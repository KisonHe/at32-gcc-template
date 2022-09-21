#ifndef __LV_PORT_DISP_H
#define __LV_PORT_DISP_H

#include "lvgl.h"
#ifdef __cplusplus
extern "C" {
#endif
/* lvgl缓冲区大小，单位为像素数 */
#define LVGL_BUFF_SIZE (BSP_LCD_X_PIXELS*BSP_LCD_Y_PIXELS/32) // 1/6屏幕分辨率

void lv_port_disp_init(void);
#ifdef __cplusplus
}
#endif
#endif
