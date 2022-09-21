/**
 * @file gpio.cpp
 * @author kisonhe (kisonhepenpal@gmail.com)
 * @brief todo 并未实现全部功能，目前为了配合SoftSP实现的最基本的版本
 * @version 0.1
 * @date 2022-09-01
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "gpio.h"

#pragma GCC poison malloc free delay_ms delay_us delay_sec
namespace hardware {
    void GPIO::pinMode(GPIO_FUNCTIONS mode) {
        gpio_init_type gpio_initstructure;
        if (GPIOx == GPIOA){
            crm_periph_clock_enable(CRM_GPIOA_PERIPH_CLOCK, TRUE);
        } else if (GPIOx == GPIOB){
            crm_periph_clock_enable(CRM_GPIOB_PERIPH_CLOCK, TRUE);
        } else if (GPIOx == GPIOC){
            crm_periph_clock_enable(CRM_GPIOC_PERIPH_CLOCK, TRUE);
        } else if (GPIOx == GPIOD){
            crm_periph_clock_enable(CRM_GPIOD_PERIPH_CLOCK, TRUE);
        } else if (GPIOx == GPIOE){
            crm_periph_clock_enable(CRM_GPIOE_PERIPH_CLOCK, TRUE);
        } else {
            while (1); //halt
        }
        gpio_default_para_init(&gpio_initstructure);
        switch (mode) {
            case GPIO_FUNCTIONS::INPUT:
            case GPIO_FUNCTIONS::INPUT_PULLDOWN:
                gpio_initstructure.gpio_mode = (GPIO_MODE_INPUT);
                gpio_initstructure.gpio_pull = GPIO_PULL_DOWN;
                break;
            case GPIO_FUNCTIONS::OUTPUT:
                gpio_initstructure.gpio_mode = (GPIO_MODE_OUTPUT);
                gpio_initstructure.gpio_pull = GPIO_PULL_NONE;
                gpio_initstructure.gpio_out_type       = GPIO_OUTPUT_PUSH_PULL;
                gpio_initstructure.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;
                break;
            case GPIO_FUNCTIONS::INPUT_PULLUP:
                gpio_initstructure.gpio_mode = (GPIO_MODE_INPUT);
                gpio_initstructure.gpio_pull = GPIO_PULL_UP;
                break;
        }
        /* spi1 sck pin */
        gpio_initstructure.gpio_pins           = GPIO_Pin;
        gpio_init(GPIOx, &gpio_initstructure);
    }

    void GPIO::digitalWrite(GPIO_LEVEL val) {
        gpio_bits_write(GPIOx, GPIO_Pin, static_cast<confirm_state>(val));
    }

    int8_t GPIO::digitalRead() {
        return gpio_input_data_bit_read(GPIOx, GPIO_Pin);
    }

    void GPIO::SetLow() {
        digitalWrite(GPIO_LEVEL::LOW);
    }

    void GPIO::SetHigh() {
        digitalWrite(GPIO_LEVEL::HIGH);
    }

    GPIO::GPIO(gpio_type *port, uint16_t pin) : GPIOx(port), GPIO_Pin(pin) {}

    void GPIO::Toggle() {
        GPIOx->odt ^= GPIO_Pin;
    }
}
