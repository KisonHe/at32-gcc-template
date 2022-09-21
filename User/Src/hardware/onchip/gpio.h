#pragma once
#include <cstdint>
#include <at32f403a_407_gpio.h>

enum class GPIO_LEVEL:uint8_t {
    LOW = 0x0,
    HIGH = 0x1
};

enum class GPIO_FUNCTIONS:uint8_t {
    INPUT = 0x01,
    OUTPUT = 0x02,
//    PULLUP = 0x04,
    INPUT_PULLUP = 0x05,
//    PULLDOWN = 0x08,
    INPUT_PULLDOWN = 0x09,
//    OPEN_DRAIN = 0x10,
//    OUTPUT_OPEN_DRAIN = 0x12,
//    SPECIAL = 0xF0,
//    FUNCTION_1 = 0x00,
//    FUNCTION_2 = 0x20,
//    FUNCTION_3 = 0x40,
//    FUNCTION_4 = 0x60,
//    FUNCTION_5 = 0x80,
//    FUNCTION_6 = 0xA0,
//    ANALOG = 0xC0
};

//https://docs.microsoft.com/en-us/cpp/preprocessor/token-pasting-operator-hash-hash?view=msvc-170


/**
 * @brief   Structure for describing gpio
 */

namespace hardware {
    class GPIO {
    private:
        gpio_type *GPIOx;
        uint16_t GPIO_Pin;
    public:
        GPIO(gpio_type *port, uint16_t pin);

        void pinMode(GPIO_FUNCTIONS mode);

        void digitalWrite(GPIO_LEVEL val);

        int8_t digitalRead();

        void SetLow();

        void SetHigh();

        void Toggle();
    };

};


