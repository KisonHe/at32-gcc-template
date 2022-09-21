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
#include "Src/gui/font/src/stringtable.h"

// FreeRTOS使用systick,at32带的这几个延时会搞爆FreeRTOS,需要检查并禁用
#pragma GCC poison malloc free delay_ms delay_us delay_sec

void emerg_stop_msg_box(){
    // Style variables should be static, global or dynamically allocated.
    // In other words they can not be local variables in functions which are destroyed when the function exists.
    static lv_style_t btn_style;
    lv_obj_t * emerg_stop_msg_box = nullptr;
    lv_style_init(&btn_style);
    lv_style_set_bg_color(&btn_style,lv_palette_main(LV_PALETTE_AMBER));
    //// If parent is NULL the message box will be modal. Safe even if pressing on boot (not created on screen)
    // 使用 kh_fonttool_get_text 获得字符串
    // 使用 kh_fonttool_get_font 获得字体
    emerg_stop_msg_box = lv_msgbox_create(nullptr, strings::kh_fonttool_get_text(strings::WarnText), strings::kh_fonttool_get_text(strings::EmerStopText), nullptr, true);
    lv_obj_set_style_text_font(lv_msgbox_get_title(emerg_stop_msg_box),strings::kh_fonttool_get_font(strings::WarnText),0);
    lv_obj_set_style_text_font(lv_msgbox_get_text(emerg_stop_msg_box),strings::kh_fonttool_get_font(strings::EmerStopText),0);

//    lv_obj_set_style_text_color(lv_msgbox_get_title(emerg_stop_msg_box),lv_color_hex(0xFF5959),0);
//    lv_obj_set_style_text_color(lv_msgbox_get_text(emerg_stop_msg_box),lv_color_hex(0xFF5959),0);

    lv_obj_add_style(lv_msgbox_get_close_btn(emerg_stop_msg_box), &btn_style, 0);

//    lv_obj_add_flag(lv_msgbox_get_close_btn(mbox1), LV_OBJ_FLAG_HIDDEN);
    lv_obj_center(emerg_stop_msg_box);
}

TaskHandle_t main_task_handler;

lv_obj_t * ui_Screen1;
lv_obj_t * ui_ModeLabel;

[[noreturn]] void main_task(void *pvParameters) {
    log_w("Into MainTask");

    lv_init();                      // lvgl内核初始化
    lv_port_disp_init();            // lvgl外设初始化

    strings::kh_load_all_font();                        // 字体辅助器加载字体
//    strings::kh_fonttool_set_lang(strings::Chinese);    // 设置语言
    strings::kh_fonttool_set_lang(strings::English);    // 设置语言
//    strings::kh_fonttool_set_lang(strings::Japanese);    // 设置语言

    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);

    ui_Screen1 = lv_obj_create(nullptr);


    ui_ModeLabel = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_ModeLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ModeLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ModeLabel, 0);
    lv_obj_set_y(ui_ModeLabel, 48);
    lv_obj_set_align(ui_ModeLabel, LV_ALIGN_CENTER);

    // 使用 kh_fonttool_get_text 获得字符串
    lv_label_set_text(ui_ModeLabel,strings::kh_fonttool_get_text(strings::EmergIcon));
    // 使用 kh_fonttool_get_font 获得字体
    lv_obj_set_style_text_font(ui_ModeLabel,strings::kh_fonttool_get_font(strings::EmergIcon),0);
    lv_obj_set_style_text_color(ui_ModeLabel,lv_palette_main(LV_PALETTE_RED),0);

    lv_disp_load_scr(ui_Screen1);

    emerg_stop_msg_box();

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
