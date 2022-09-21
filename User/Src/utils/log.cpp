//
// Created by kisonhe on 22-8-14.
//
#include "printf.h"
#include <cstdlib>
#include "esp32-hal-log.h"
#ifndef NDEBUG
#include "SEGGER_RTT.h"
#endif

#include "FreeRTOS.h"
#include "task.h"

#pragma GCC poison malloc free delay_ms delay_us delay_sec
int log_printf(const char *format, ...)
{
    static char loc_buf[64];
    char * temp = loc_buf;
    unsigned int len;
    va_list arg;
    va_list copy;
    va_start(arg, format);
    va_copy(copy, arg);
    len = vsnprintf(nullptr, 0, format, arg);
    va_end(copy);
    if(len >= sizeof(loc_buf)){
        temp = (char*)pvPortMalloc(len+1);
        if(temp == nullptr) {
            return 0;
        }
    }
    vsnprintf(temp, len+1, format, arg);
//    printf("%s", temp);
#ifndef NDEBUG
    SEGGER_RTT_printf(0, "%s", temp);
//    hardware::uart1_instance.transmit(reinterpret_cast<uint8_t *>(temp), len + 1);
#else
// 用户自行根据需要实现自己的打印
//    hardware::uart1_instance.transmit(reinterpret_cast<uint8_t *>(temp), len + 1);
#endif

    va_end(arg);
    if(len >= sizeof(loc_buf)){
        vPortFree(temp);
    }
    return len;
}


const char * pathToFileName(const char * path)
{
    size_t i = 0;
    size_t pos = 0;
    char * p = (char *)path;
    while(*p){
        i++;
        if(*p == '/' || *p == '\\'){
            pos = i;
        }
        p++;
    }
    return path+pos;
}

int64_t esp_timer_get_time(){
    return xTaskGetTickCount()*1000;
}