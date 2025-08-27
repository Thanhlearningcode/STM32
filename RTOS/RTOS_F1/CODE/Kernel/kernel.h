

#include "stm32f10x.h"                  // Device header
uint8_t osKernelAddThread(void (*task0)(void),void (*task1)(void), void (*task2)(void));
void osKernelStackInit(int i);
void osSchedulerLaunch();
void osKernelInit(void);
void osKernelLaunch(uint32_t quanta);
void SysTick_Handler();
void osThreadYield();
void osSemaphore_Init(uint32_t *semaphore, uint32_t val);
void osSemaphore_Give(uint32_t *semaphore);
void osSpinLock_Wait(uint32_t *semaphore);
void osCooperative_Wait(uint32_t *semaphore);
void osSchedulerRoundRobin();
void periodicTask0();
void periodicTask1();
uint8_t osKernelAddPeriodicThreads(void(*task)(void), uint32_t period);
void osSchedulerPeriodicRoundRobin();
void periodic_events_exe();
void osPeriodicTask_Init(void(*task)(void), uint32_t freq, uint8_t priority);
void TIM2_IRQHandler();
void osThreadsSleep(uint32_t sleeptime);
uint8_t osKernelAdd1Thread(void (*task)(void));
void EdgeTrigger_Init(void);
void osEdgeTriggerInit(uint32_t *semaphore);
void MailBox_Init(void);
void osMailBoxSend(uint32_t data);
uint32_t osMailBoxReceive(void);
void FIFO_Init(void);
uint8_t osFIFOPut(uint32_t data);
uint32_t osFIFOGet(void);