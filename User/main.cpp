/*
@ 	AT32_F403_hub V7.0 release / 2021-12-23
@
@	IAP start address			 	0x08000000
@	version ID address	 			0x0801E000
@	App start address				0x08020000
@	Flag of update mode				0x0801E800
@	device ID address				0x0801F000
*/

#include "at32f403a_407_board.h"
#include "at32f403a_407_clock.h"
#include "at32f403a_407_crm.h"
#include "at32f403a_407_misc.h"

int main() {
    system_clock_config();

    nvic_priority_group_config(NVIC_PRIORITY_GROUP_4);

    crm_periph_clock_enable(CRM_IOMUX_PERIPH_CLOCK, TRUE);
    gpio_pin_remap_config(SWJTAG_GMUX_010, TRUE);           // 禁用JTag仅启用SWD, 让PB3、PB4、PA15等IO正常使用


    while(1) {

    }
}
