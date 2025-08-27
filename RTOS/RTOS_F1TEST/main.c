#include "RTOS.h"

extern void ConfigurationStackPointer(uint32_t psp_stack, uint32_t msp_stack);
extern void Task1(void);
int main(void)
{
	InitializeThreads();
	ConfigurationStackPointer(FIRST_STACK,MSP_STACK);
	SystemTickSetup(1);
	ConfigPriIRQ();
	Task1();
}