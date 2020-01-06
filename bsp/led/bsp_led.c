#include "bsp_led.h"

/*
 * @description : LED初始化函数
 * @param       : 
 * @return      : 
 */
void led_init(void)
{
    IOMUXC_SetPinMux(IOMUXC_GPIO1_IO03_GPIO1_IO03, 0);    
    IOMUXC_SetPinConfig(IOMUXC_GPIO1_IO03_GPIO1_IO03, 0X10B0);
    GPIO1->GDIR |= (1<<3);
    GPIO1->DR &= ~(1<<3);
}

/*
 * @description : LED控制函数
 * @param       : 
 *                led：要控制的LED编号
 *                status： 0,关闭led 1, 打开led
 * @return      : 
 */
void led_switch(int led, int status)
{
    switch(led)
    {
        case LED0:
            if(ON == status)
                GPIO1->DR &= ~(1<<3);
            else if(OFF == status)
                GPIO1->DR |= (1<<3);
            break;
    }
}

