//
// Created by kisonhe on 22-9-19.
//
#include <at32f403a_407_crm.h>
#include "rtc.h"
namespace rtc{
    static uint16_t rtc_calulate_crc(){
        crc_data_reset();
        return (uint16_t)(crc_block_calculate((uint32_t *)(*(__IO uint16_t *)(BPR_BASE + BPR_DATA1)), 10));
    }
    esp_err_t rtc_init(uint32_t timeout) {
        crm_periph_clock_enable(CRM_CRC_PERIPH_CLOCK, TRUE);
        crm_periph_clock_enable(CRM_PWC_PERIPH_CLOCK, TRUE);
        crm_periph_clock_enable(CRM_BPR_PERIPH_CLOCK, TRUE);
        pwc_battery_powered_domain_access(TRUE);
        crc_data_reset();
        if (!rtc_is_bat_reg_valid()){
            bpr_reset();
            crm_clock_source_enable(CRM_CLOCK_SOURCE_HEXT, TRUE);
            /* 等待 HEXT 时钟稳定 */ // todo port to timeout
            while(crm_flag_get(CRM_HEXT_STABLE_FLAG) == RESET);
            /* 选择 RTC 时钟源 */
            crm_rtc_clock_select(CRM_RTC_CLOCK_HEXT_DIV);
            crm_rtc_clock_enable(TRUE);
            /* 等待 RTC 寄存器同步 */ // todo port to timeout
            rtc_wait_update_finish();
            /* 等待上一次寄存器配置同步完成 */ // todo port to timeout
            rtc_wait_config_finish();
            /* 配置 RTC 分频器 */
            rtc_divider_set(32767);
            /* 等待上一次寄存器配置同步完成 */
            rtc_wait_config_finish();
            bpr_data_write(BPR_DATA41, VAILD_FALG);
            rtc_update_crc();
        }
        return 0;
    }

    bool rtc_is_bat_reg_valid() {
        if (bpr_data_read(BPR_DATA41) != VAILD_FALG)
            return false;
        if (bpr_data_read(BPR_DATA42) != rtc_calulate_crc()){
            return false;
        } else {
            return true;
        }
    }

    esp_err_t rtc_write_data(uint16_t data, uint8_t pos) {
        if (pos > 40 || pos == 0){
            return ESP_FAIL;
        }
        bpr_data_write(static_cast<bpr_data_type>(4*pos),data);
        rtc_update_crc();
        return ESP_OK;
    }

    void rtc_update_crc() {
        bpr_data_write(BPR_DATA42, rtc_calulate_crc());
    }

    uint16_t rtc_read_data(uint8_t pos) {
        if (pos > 40 || pos == 0){
            return 0;
        }
        return bpr_data_read(static_cast<bpr_data_type>(4*pos));
    }
}
