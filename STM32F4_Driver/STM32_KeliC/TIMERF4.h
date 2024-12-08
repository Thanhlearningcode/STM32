#ifndef _TIMER_STM32F4_H
#define _TIMER_STM32F4_H
#include "stm32f4xx.h"
void Delay(uint16_t time);
void TiM1_init(void);
void TIM4_init(void);
uint16_t get_timer();
#endif // _TIMER_STM32F4_H