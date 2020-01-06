#ifndef __BSP_BEEP_H
#define __BSP_BEEP_H

#include "imx6ull.h"

void beep_init(void);
void beep_switch(int status);

#endif // !__BSP_BEEP_H