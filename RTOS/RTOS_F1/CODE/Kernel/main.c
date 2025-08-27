#include "kernel.h"
#include "uart.h"
volatile int i1,i2,i3,cnt1,cnt0,cnt2;;
uint32_t semaphore1, semaphore2,sporadicSemaphore=0;
#define QUANTA 1

void task0(){
		while(1){
			osCooperative_Wait(&semaphore1);
			i1++;
//			osThreadsSleep(20);
			osSemaphore_Give(&semaphore2);
			}
}

void task1(){
		while(1){
			osCooperative_Wait(&semaphore2);
			i2++;
//			osThreadsSleep(10);
			osSemaphore_Give(&semaphore1);
			}
}

void task2(){
		while(1){
			i3++;
			}
}

void periodicTask0(){
		cnt0++;
}
void periodicTask1(){
		cnt1++;
}
void sporadictask(){
	while(1){
		osCooperative_Wait(&sporadicSemaphore);
		cnt2++;
	}
}
int main() {
		osKernelInit();
		osKernelAddThread(task0,task1,task2);
		osKernelAddPeriodicThreads(periodicTask0,100);
//		osKernelAddPeriodicThreads(periodicTask1,150);
		osSemaphore_Init(&semaphore1,1);
		osSemaphore_Init(&semaphore2,0);
		osEdgeTriggerInit(&sporadicSemaphore);
		osKernelLaunch(QUANTA);
		while(1){}
}
void SysTick_Handler(){
		SCB->ICSR |= SCB_ICSR_PENDSVSET;
}

