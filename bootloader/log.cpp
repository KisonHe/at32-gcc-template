//
// Created by kisonhe on 22-8-14.
//
//#include "printf.h"
#include <cstdio>
#include <cstdlib>
#include "esp32-hal-log.h"

#include "FreeRTOS.h"
#include "task.h"

int log_printf(const char *format, ...)
{
//    return 0;
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
        temp = (char*)malloc(len+1);
        if(temp == nullptr) {
            return 0;
        }
    }
    vsnprintf(temp, len+1, format, arg);
//    printf("%s", temp);
// 用户自行完成的打印函数

    va_end(arg);
    if(len >= sizeof(loc_buf)){
        free(temp);
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
//    return xTaskGetTickCount()*1000;
    return 0;
}