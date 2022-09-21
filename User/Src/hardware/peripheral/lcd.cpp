#include "lcd.h"
#include "../onchip/gpio.h"
#include <pindef.h>
#include "gc9a01_cmd.h"
#include <FreeRTOS.h>
#include <task.h>

#define GC9A01_MADCTL_BGR	(0x08)
#define GC9A01_MADCTL_MV	(0x20)
#define GC9A01_MADCTL_MX	(0x40)
#define GC9A01_MADCTL_MY	(0x80)

static volatile uint8_t dma_trans_done_flag = 1;

extern "C" void DMA1_Channel3_IRQHandler(void)
{
    if(dma_flag_get(DMA1_FDT3_FLAG) != RESET)
    {
        dma_trans_done_flag = 1;
        dma_reset(DMA1_CHANNEL3); //复位DMA通道
    }
}
static hardware::GPIO
        GPIO_LCDCS(LCD_CS_GPIO_Port, LCD_CS_Pin),
        GPIO_LCDRST(LCD_RES_GPIO_Port, LCD_RES_Pin),
        GPIO_LCDDC(LCD_DC_GPIO_Port, LCD_DC_Pin);

namespace LCD{
    static void lcd_blk_bus_init(){
        crm_clocks_freq_type crm_clocks_freq_struct;
        tmr_output_config_type tmr_output_struct;

        crm_clocks_freq_get(&crm_clocks_freq_struct);

        gpio_init_type  gpio_init_struct;
        crm_periph_clock_enable(CRM_GPIOA_PERIPH_CLOCK, TRUE);
        gpio_default_para_init(&gpio_init_struct);
        gpio_init_struct.gpio_pins = GPIO_PINS_1;
        gpio_init_struct.gpio_mode = GPIO_MODE_MUX;
        gpio_init_struct.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
        gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
        gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;
        gpio_init(GPIOA, &gpio_init_struct);

        crm_periph_clock_enable(CRM_TMR5_PERIPH_CLOCK, TRUE);

        tmr_output_default_para_init(&tmr_output_struct);
        tmr_output_struct.oc_mode = TMR_OUTPUT_CONTROL_PWM_MODE_B;
        tmr_output_struct.oc_output_state = TRUE;
        tmr_output_struct.oc_polarity = TMR_OUTPUT_ACTIVE_LOW;
        tmr_output_struct.oc_idle_state = TRUE;
        tmr_output_struct.occ_output_state = TRUE;
        tmr_output_struct.occ_polarity = TMR_OUTPUT_ACTIVE_HIGH;
        tmr_output_struct.occ_idle_state = FALSE;

        tmr_cnt_dir_set(TMR5, TMR_COUNT_UP);
        tmr_output_channel_config(TMR5, TMR_SELECT_CHANNEL_2, &tmr_output_struct);
    }
    static void lcd_bus_init()
    {
        GPIO_LCDCS.pinMode(GPIO_FUNCTIONS::OUTPUT);
        GPIO_LCDRST.pinMode(GPIO_FUNCTIONS::OUTPUT);
        GPIO_LCDDC.pinMode(GPIO_FUNCTIONS::OUTPUT);

        /* GPIO外设 */
        crm_periph_clock_enable(CRM_GPIOA_PERIPH_CLOCK, TRUE); //使能GPIOA外设时钟
        gpio_init_type gpio_initstructure;
        gpio_default_para_init(&gpio_initstructure);

        gpio_initstructure.gpio_out_type       = GPIO_OUTPUT_PUSH_PULL;
        gpio_initstructure.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;
        gpio_initstructure.gpio_mode           = GPIO_MODE_MUX;
        gpio_initstructure.gpio_pull           = GPIO_PULL_DOWN;
        gpio_initstructure.gpio_pins           = GPIO_PINS_5 | GPIO_PINS_7; //PA5=SPI1_CLK  PA7=SPI1_MOSI
        gpio_init(GPIOA, &gpio_initstructure);

        /* SPI外设 */
        crm_periph_clock_enable(CRM_SPI1_PERIPH_CLOCK, TRUE); //使能SPI外设时钟

        spi_init_type spi_init_struct;
        spi_default_para_init(&spi_init_struct);

        spi_init_struct.transmission_mode = SPI_TRANSMIT_HALF_DUPLEX_TX; //仅发送
        spi_init_struct.master_slave_mode = SPI_MODE_MASTER;
        spi_init_struct.mclk_freq_division = SPI_MCLK_DIV_2; //120/2=60Mhz
        spi_init_struct.first_bit_transmission = SPI_FIRST_BIT_MSB;
        spi_init_struct.frame_bit_num = SPI_FRAME_8BIT;
        spi_init_struct.clock_polarity = SPI_CLOCK_POLARITY_LOW;
        spi_init_struct.clock_phase = SPI_CLOCK_PHASE_1EDGE;        //CPHA=0
        spi_init_struct.cs_mode_selection = SPI_CS_SOFTWARE_MODE;
        spi_init(SPI1, &spi_init_struct);

        spi_i2s_dma_transmitter_enable(SPI1, TRUE); //使能SPI发送DMA请求

        spi_enable(SPI1, TRUE);

        /* DMA外设 */
        crm_periph_clock_enable(CRM_DMA1_PERIPH_CLOCK, TRUE);

        nvic_irq_enable(DMA1_Channel3_IRQn, 1, 0); //使能DMA中断请求
    }

    static void sendCommand(uint8_t commandByte, const void *dataBytes = nullptr, int numDataBytes = 0, int dataRepeat = 1) {
        GPIO_LCDCS.SetLow();
        GPIO_LCDDC.SetLow();

        spi_frame_bit_num_set(SPI1, SPI_FRAME_8BIT);

        spi_i2s_data_transmit(SPI1, commandByte);
        while(spi_i2s_flag_get(SPI1, SPI_I2S_BF_FLAG) == SET); //等待传输完成
        GPIO_LCDDC.SetHigh();
        for (int r = 0; r < dataRepeat; r++) {
            spi_frame_bit_num_set(SPI1, SPI_FRAME_8BIT);
            uint8_t * ptr = (uint8_t *) dataBytes;
            for(uint8_t i = 0; i < numDataBytes; i ++) {
                spi_i2s_data_transmit(SPI1, ptr[i]);
                while(spi_i2s_flag_get(SPI1, SPI_I2S_BF_FLAG) == SET); //等待传输完成
            }
        }
        GPIO_LCDCS.SetHigh();
    }

    static void sendSequence(const uint8_t *addr) {
        uint8_t cmd, numArgs;

        while ((cmd = *addr++) != 0) {              // For each command...
            numArgs = *addr++;                      // Number of args to follow
            sendCommand(cmd, addr, numArgs);
            addr += numArgs;
        }
    }

    static void lcd_send_color(const uint8_t *data, uint32_t len)
    {
        spi_frame_bit_num_set(SPI1, SPI_FRAME_16BIT);

        dma_init_type dma_init_struct;

        dma_init_struct.buffer_size = len;
        dma_init_struct.direction = DMA_DIR_MEMORY_TO_PERIPHERAL;
        dma_init_struct.memory_base_addr = (uint32_t)data;
        dma_init_struct.memory_data_width = DMA_MEMORY_DATA_WIDTH_HALFWORD;
        dma_init_struct.memory_inc_enable = TRUE;
        dma_init_struct.peripheral_base_addr = (uint32_t)&(SPI1->dt);
        dma_init_struct.peripheral_data_width = DMA_PERIPHERAL_DATA_WIDTH_HALFWORD;
        dma_init_struct.peripheral_inc_enable = FALSE;
        dma_init_struct.priority = DMA_PRIORITY_MEDIUM;
        dma_init_struct.loop_mode_enable = FALSE;

        dma_init(DMA1_CHANNEL3, &dma_init_struct);

        dma_interrupt_enable(DMA1_CHANNEL3, DMA_FDT_INT, TRUE); //开启DMA传输完成中断

        gpio_bits_reset(GPIOA, GPIO_PINS_4); //CS=0
        dma_channel_enable(DMA1_CHANNEL3, TRUE); //启动传输
    }

    static void lcd_reg_init_gc9a01()
    {
        GPIO_LCDRST.SetLow();
        vTaskDelay(100);
        GPIO_LCDRST.SetHigh();
        vTaskDelay(500);
        sendSequence(GC9A01_Init);

        vTaskDelay(120);
        sendCommand(0x29);
        vTaskDelay(20);
        uint8_t addr_mode;
        int rotation = 0;
        switch (rotation) {
            default:
                addr_mode = 0;
                break;
            case 90:
                addr_mode = GC9A01_MADCTL_MV | GC9A01_MADCTL_MX;
                break;
            case 180:
                addr_mode = GC9A01_MADCTL_MY | GC9A01_MADCTL_MX;
                break;
            case 270:
                addr_mode = GC9A01_MADCTL_MV | GC9A01_MADCTL_MY;
                break;
        }
        addr_mode |= GC9A01_MADCTL_BGR;
        sendCommand(0x36,&addr_mode,1);
        vTaskDelay(20);

    }

    void lcd_draw_rect(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, const uint8_t *pix_data)
    {
        uint8_t tx_data[4];

        /* 设置Column地址 */
        tx_data[0] = x0>>8; //起始地址高8位
        tx_data[1] = x0&0xFF; //起始地址高8位
        tx_data[2] = x1>>8; //结束地址高8位
        tx_data[3] = x1&0xFF; //结束地址高8位
        sendCommand(0x2A,tx_data,4);

        /* 设置Page地址 */
        tx_data[0] = y0>>8;
        tx_data[1] = y0&0xFF;
        tx_data[2] = y1>>8;
        tx_data[3] = y1&0xFF;
        sendCommand(0x2B,tx_data,4);

        /* 写入图像数据 */
        sendCommand(0x2C);
        lcd_send_color(pix_data, (x1-x0+1)*(y1-y0+1));
    }

    void lcd_draw_rect_wait()
    {
        while(dma_trans_done_flag == 0); //等待传输完毕
        dma_trans_done_flag = 0;

        while(spi_i2s_flag_get(SPI1, SPI_I2S_BF_FLAG) == SET); //DMA传输完成中断产生时，SPI的最后一个字节仍在传输中，不能提前释放CS
        gpio_bits_set(GPIOA, GPIO_PINS_4); //CS=1
    }

    void lcd_display_switch(uint8_t status)
    {
        if(status) {
            sendCommand(0x29); //开显示
        } else {
            sendCommand(0x28); //关显示
        }
    }

    void lcd_init()
    {
        lcd_blk_bus_init();
        lcd_set_brightness(0);
        lcd_bus_init();
        lcd_reg_init_gc9a01();
        vTaskDelay(10);
        lcd_set_brightness(255);
    }

    esp_err_t lcd_set_brightness(uint8_t brightness) {
        crm_clocks_freq_type crm_clocks_freq_struct;
        crm_clocks_freq_get(&crm_clocks_freq_struct);
        uint16_t timer_period = (crm_clocks_freq_struct.sclk_freq / (10000) ) - 1;
        uint16_t channel_pulse = (uint16_t)(((uint32_t) brightness * (timer_period - 1)) / 255);

        tmr_base_init(TMR5, timer_period, 9);       //div = 9+1,分频10倍
        tmr_channel_value_set(TMR5, TMR_SELECT_CHANNEL_2, channel_pulse);
        tmr_output_enable(TMR5, TRUE);
        tmr_counter_enable(TMR5, TRUE);
        return 0;
    }
}

