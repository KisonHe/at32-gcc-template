/**
  **************************************************************************
  * @file     at32f403a_407_int.c
  * @version  v2.0.7
  * @date     2022-02-11
  * @brief    main interrupt service routines.
  **************************************************************************
  *                       Copyright notice & Disclaimer
  *
  * The software Board Support Package (BSP) that is made available to
  * download from Artery official website is the copyrighted work of Artery.
  * Artery authorizes customers to use, copy, and distribute the BSP
  * software and its related documentation for the purpose of design and
  * development in conjunction with Artery microcontrollers. Use of the
  * software is governed by this copyright notice and the following disclaimer.
  *
  * THIS SOFTWARE IS PROVIDED ON "AS IS" BASIS WITHOUT WARRANTIES,
  * GUARANTEES OR REPRESENTATIONS OF ANY KIND. ARTERY EXPRESSLY DISCLAIMS,
  * TO THE FULLEST EXTENT PERMITTED BY LAW, ALL EXPRESS, IMPLIED OR
  * STATUTORY OR OTHER WARRANTIES, GUARANTEES OR REPRESENTATIONS,
  * INCLUDING BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY,
  * FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.
  *
  **************************************************************************
  */

/* includes ------------------------------------------------------------------*/
#include "at32f403a_407_int.h"
//#include "FreeRTOS.h"
//#include "task.h"
//#include "queue.h"
//#include "semphr.h"
#include "at32f403a_407_board.h"
//#include "../../User/Src/hardware/onchip/led.h"
/** @addtogroup UTILITIES_examples
  * @{
  */

/** @addtogroup FreeRTOS_demo
  * @{
  */

/**
  * @brief  this function handles nmi exception.
  * @param  none
  * @retval none
  */
extern "C" void NMI_Handler(void)
{
}

/**
  * @brief  this function handles hard fault exception.
  * @param  none
  * @retval none
  */
extern "C" void HardFault_Handler(void)
{
    /* go to infinite loop when hard fault exception occurs */
    while(1)
    {
//        LED_Toggle(hardware::led_num::RED);
        delay_ms(200);
    }
}

/**
  * @brief  this function handles memory manage exception.
  * @param  none
  * @retval none
  */
extern "C" void MemManage_Handler(void)
{
    /* go to infinite loop when memory manage exception occurs */
    while(1)
    {
//        LED_Toggle(hardware::led_num::RED);
        delay_ms(200);
    }
}

/**
  * @brief  this function handles bus fault exception.
  * @param  none
  * @retval none
  */
extern "C" void BusFault_Handler(void)
{
    /* go to infinite loop when bus fault exception occurs */
    while(1)
    {
//        LED_Toggle(hardware::led_num::RED);
        delay_ms(200);
    }
}

/**
  * @brief  this function handles usage fault exception.
  * @param  none
  * @retval none
  */
extern "C" void UsageFault_Handler(void)
{
    /* go to infinite loop when usage fault exception occurs */
    while(1)
    {
//        LED_Toggle(hardware::led_num::RED);
        delay_ms(200);
    }
}

/**
  * @brief  this function handles svcall exception.
  * @param  none
  * @retval none
  */
//void SVC_Handler(void)
//{
//}

/**
  * @brief  this function handles debug monitor exception.
  * @param  none
  * @retval none
  */
extern "C" void DebugMon_Handler(void)
{
}

/**
  * @brief  this function handles pendsv_handler exception.
  * @param  none
  * @retval none
  */
//void PendSV_Handler(void)
//{
//}

/**
  * @brief  this function handles systick handler.
  * @param  none
  * @retval none
  */
//void SysTick_Handler(void)
//{
//}

/**
  * @brief  this function handles emac handler.
  * @param  none
  * @retval none
  */
//void EMAC_IRQHandler(void)
//{
//}
/**
  * @}
  */

/**
  * @}
  */

/**
  * @brief  This function handles the spi1 interrupt request.
  * @param  None
  * @retval None
  */
extern "C" void SPI1_IRQHandler(void)
{
}

/**
  * @brief  This function handles the spi2 interrupt request.
  * @param  None
  * @retval None
  */
extern "C" void SPI2_I2S2EXT_IRQHandler(void)
{
}
//#ifdef EMBEDDED
//extern uint32_t k_tick;
//extern "C" void TMR1_OVF_TMR10_IRQHandler(void)
//{
//    if(tmr_flag_get(TMR1, TMR_OVF_FLAG) == SET)
//    {
//        /* 增加应用程序 */
////        at32_led_toggle(LED3);
//        k_tick++;
//        tmr_flag_clear(TMR1, TMR_OVF_FLAG);
//    }
//}
//#endif
