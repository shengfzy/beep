#include "bsp_beep.h"

/*
 * @description : 初始化蜂鸣器
 * @param       : 
 * @return      : 
 */

void beep_init(void)
{
    IOMUXC_SetPinMux(IOMUXC_SNVS_SNVS_TAMPER1_GPIO5_IO01, 0);
    IOMUXC_SetPinConfig(IOMUXC_SNVS_SNVS_TAMPER1_GPIO5_IO01, 0x10b0);
    GPIO5->GDIR |= (1<<1);
    GPIO5->DR   |= (1<<1);
}

/*
 * @description : 蜂鸣器控制函数
 * @param       : 0,关闭蜂鸣器，1,打开蜂鸣器
 * @return      : 
 */

void beep_switch(int status)
{
    if(ON == status)
        GPIO5->DR &= ~(1<<1);
    else if(OFF == status)
        GPIO5->DR |= (1<<1);
}
