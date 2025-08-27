#include "stm32f10x.h"

#define TOGGLE(x) (x ^= 0x1)
uint8_t data0 = 0x0;
uint8_t data1 = 0x0;
extern void DelayMs(uint32_t _tick);
void Task1(void)
{
	while(1)
	{
		TOGGLE(data0);
		DelayMs(5000);
	}
}

void Task2(void)
{
	while(1)
	{	
		TOGGLE(data1);
		DelayMs(5000);
	}
}