#pragma once
#include <at32f403a_407.h>
#include <esp_err.h>

/* 屏幕分辨率 */
#define BSP_LCD_X_PIXELS (240)
#define BSP_LCD_Y_PIXELS (240)

namespace LCD{
    void lcd_init();
    void lcd_display_switch(uint8_t status);
    void lcd_draw_rect(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, const uint8_t *dat);
    void lcd_draw_rect_wait();
    /**
     *
     * @param brightness 0-255
     * @return
     */
    esp_err_t lcd_set_brightness(uint8_t brightness);
}
