/**
 * Generated File, Do not modify
 * 
 */
#include "stringtable.h"
#include <stdint.h>
#include "esp32-hal-log.h"

LV_FONT_DECLARE(font_ui_20);
const fonttype* font_ui_20_ptr = &font_ui_20;
LV_FONT_DECLARE(font_ui_16);
const fonttype* font_ui_16_ptr = &font_ui_16;
LV_FONT_DECLARE(font_ui_big);
const fonttype* font_ui_big_ptr = &font_ui_big;
LV_FONT_DECLARE(font_icon);
const fonttype* font_icon_ptr = &font_icon;
namespace strings
{
    Language_t CurrentLanguage = English; //When generating, set default to first lang

    static kh_textdata_t MainData[EndOfLanguages][EndOfTexts] = {

        { 
            {"", font_ui_20_ptr},
            {"", font_ui_big_ptr},
            {"", font_icon_ptr},
            {"", font_icon_ptr},
            {"", font_icon_ptr},
            {"", font_icon_ptr},
            {"", font_icon_ptr},
            {"Km", font_ui_20_ptr},
            {"Warning!", font_ui_16_ptr},
            {"Emergency Stop Button Pressed", font_ui_16_ptr},
        },
        { 
            {"", font_ui_20_ptr},
            {"", font_ui_big_ptr},
            {"", font_icon_ptr},
            {"", font_icon_ptr},
            {"", font_icon_ptr},
            {"", font_icon_ptr},
            {"", font_icon_ptr},
            {"Km", font_ui_20_ptr},
            {"警告!", font_ui_20_ptr},
            {"急停开关被按下", font_ui_20_ptr},
        },
        { 
            {"", font_ui_20_ptr},
            {"", font_ui_big_ptr},
            {"", font_icon_ptr},
            {"", font_icon_ptr},
            {"", font_icon_ptr},
            {"", font_icon_ptr},
            {"", font_icon_ptr},
            {"Km", font_ui_20_ptr},
            {"警告!", font_ui_20_ptr},
            {"非常停止ボタンが押されました", font_ui_16_ptr},
        },
    };
    
    static const char* FontNames[] = {  //help to load font from file system 
        "font_ui_20",
        "font_ui_16",
        "font_ui_big",
        "font_icon",
    };

    const char * kh_fonttool_get_text(ID id){
        if (id >= EndOfTexts)
            return nullptr;
        return MainData[CurrentLanguage][id].text;
    }

    const fonttype * kh_fonttool_get_font(ID id){
        if (id >= EndOfTexts)
            return nullptr;
        return (MainData[CurrentLanguage][id].fontptr);
    }

    int kh_fonttool_set_lang(Language_t lang){
        if (lang >= EndOfLanguages)
            return -1;
        CurrentLanguage = lang; 
        return 0; 
    }

    void kh_load_all_font(){
        return; // for lvgl format fonts are already loaded
    }
  
}