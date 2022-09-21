/**
 * @file rtc.h
 * @author kisonhe (kisonhepenpal@gmail.com)
 * @brief   AT32有 42 个 16 位电池供电数据寄存器
 *          本库中，41写入固定的数据，42CRC校验1-41用于验证数据是否有效
 *          用户可用寄存器 BPR_DATA1 - BPR_DATA40
 * @version 0.1
 * @date 2022-09-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include <esp_err.h>

namespace rtc{
    const int16_t VAILD_FALG=0x1234;
    /**
     * 初始化RTC
     * @param timeout In ms
     * @return ESP_OK if success. Other if fail
     */
    esp_err_t rtc_init(uint32_t timeout);

    bool rtc_is_bat_reg_valid();

    void rtc_update_crc();

    esp_err_t rtc_write_data(uint16_t data, uint8_t pos);
    uint16_t rtc_read_data(uint8_t pos);
}
