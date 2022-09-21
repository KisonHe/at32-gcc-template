#include "at32f403a_407_board.h"
#include "at32f403a_407_clock.h"

#include "esp32-hal-log.h"

#ifndef NDEBUG
#include "SEGGER_RTT.h"
#include "SEGGER_SYSVIEW.h"
#endif

#include "FreeRTOS.h"
#include "task.h"

#include "Src/hardware/peripheral/lv_port_disp.h"

#include "lvgl.h"
#include "demos/lv_demos.h"

// FreeRTOS使用systick,at32带的这几个延时会搞爆FreeRTOS,需要检查并禁用
#pragma GCC poison malloc free delay_ms delay_us delay_sec

TaskHandle_t main_task_handler;
[[noreturn]] void main_task(void *pvParameters) {
    log_w("Into MainTask");

    lv_init();                      // lvgl内核初始化
    lv_port_disp_init();            // lvgl外设初始化

    while (1){
        lv_task_handler();
        vTaskDelay(pdMS_TO_TICKS(5));
    }
}

int main() {
    system_clock_config();
#ifdef BOOTLOADERVERAPP
    nvic_vector_table_set(NVIC_VECTTAB_FLASH,FLASH_APP1_ADDR-AT32_FLASH_BASE);
#endif
    nvic_priority_group_config(NVIC_PRIORITY_GROUP_4);
#ifndef NDEBUG
    SEGGER_RTT_ConfigUpBuffer(0, nullptr, nullptr, 0, SEGGER_RTT_MODE_NO_BLOCK_SKIP);
    SEGGER_RTT_ConfigDownBuffer(0, nullptr, nullptr, 0,SEGGER_RTT_MODE_NO_BLOCK_SKIP);
    SEGGER_SYSVIEW_Conf();
#endif

#ifdef BOOTLOADERVERAPP
    log_w_simp("Firmware Version:%s-bootloadered-app",GIT_VER);
#else
    log_w_simp("Firmware Version:%s", GIT_VER);
#endif

    crm_periph_clock_enable(CRM_IOMUX_PERIPH_CLOCK, TRUE);
    gpio_pin_remap_config(SWJTAG_GMUX_010, TRUE);           // 让PB3、PB4、PA15等IO正常使用

    taskENTER_CRITICAL();

    xTaskCreate((TaskFunction_t )main_task,
                (const char*    )"main task",
                (uint16_t       )1024,
                (void*          )nullptr,
                (UBaseType_t    )2,
                (TaskHandle_t*  )&main_task_handler);

    /* exit critical */
    taskEXIT_CRITICAL();

    /* start scheduler */
    vTaskStartScheduler();

    while(1) {

    }
}
