//
// Created by kisonhe on 22-8-31.
//
typedef void (*otafun)();
#include <cstdint>
#ifdef __cplusplus
extern "C" {
#endif
#include "cmsis_gcc.h"
#ifdef __cplusplus
}
#endif

//#include "sdkconfig.h"
//#include "esp32-hal-log.h"
#include <at32f403a_407_clock.h>
#include "flash.h"
otafun jump_to_app;

/**
  * @brief  app load.
  * @param  app_addr
  *         app code starting address
  * @retval none
  */
void app_load(uint32_t app_addr)
{
    /* check app starting address whether 0x08xxxxxx */
    if(((*(uint32_t*)(app_addr + 4)) & 0xFF000000) != 0x08000000)
        return;
    /* check the address of stack */
    if(((*(uint32_t*)app_addr) - 0x20000000) < (SRAM_SIZE * 1024))
    {
        /* disable periph clock */
        crm_periph_clock_enable(CRM_TMR3_PERIPH_CLOCK, FALSE);
        crm_periph_clock_enable(CRM_USART1_PERIPH_CLOCK, FALSE);
        crm_periph_clock_enable(CRM_GPIOA_PERIPH_CLOCK, FALSE);

        /* disable nvic irq and clear pending */
        nvic_irq_disable(USART1_IRQn);
        nvic_irq_disable(TMR3_GLOBAL_IRQn);
        __NVIC_ClearPendingIRQ(USART1_IRQn);
        __NVIC_ClearPendingIRQ(TMR3_GLOBAL_IRQn);

        jump_to_app = (otafun)*(uint32_t*)(app_addr + 4);        /* code second word is reset address */
        __set_MSP(*(uint32_t*)app_addr);                        /* init app stack pointer(code first word is stack address) */
        jump_to_app();                                          /* jump to user app */
    }
}

int main(void)
{
    system_clock_config();
    /* config nvic priority group */
    nvic_priority_group_config(NVIC_PRIORITY_GROUP_4);

    delay_init();
//    /* check ota_upgrade_flag flag */
//    if(flash_upgrade_flag_read() == RESET)
//    {
        app_load(0x08020000);
//    }

    /* init tmr used for show code running state(led cycle toggle) */
//    tmr_init();

    while(1)
    {
        /* upgrade handle */
//        ota_upgrade_app_handle();
    }
}