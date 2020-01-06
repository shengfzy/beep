#include "bsp_clk.h"
#include "bsp_delay.h"
#include "bsp_led.h"
#include "bsp_beep.h"

/*
 * @description : main.c
 * @param       : 
 * @return      : 
 */
int main(int argc, char * argv[])
{
    clk_enable();
    led_init();
    beep_init();

    while(1)
    {
        led_switch(LED0, ON);
        beep_switch(ON);
        delay(500);
        led_switch(LED0, OFF);
        beep_switch(OFF);
        delay(500);
    }
    return 0;
}



