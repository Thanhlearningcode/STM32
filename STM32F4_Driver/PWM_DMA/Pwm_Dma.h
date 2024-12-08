#ifndef _Pwm_Dma_h_
#define _Pwm_Dma_h_
#include "PLATFORM_TYPES.h"
#include "stm32f411xe.h"
void Pwm_Dma_Init(void);
void Pwm_Duty(uint16 Duty1,uint16 Duty2);
#endif // _Pwm_Dma_h_