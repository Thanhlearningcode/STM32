/***************************************************************************
 * @file    kernel.h
 * @brief   Khai b�o c�c h�m va cau truc lien quan toi kernel
 * @details File n�y cung cap giao dien cho viec dieu khien kernel
 * @version 1.0
 * @date    2024-10-07
 * @author  PHAN DANG DANH
 * @website https://hala.edu.vn/
 ***************************************************************************/
#ifndef KERNEL_H
#define KERNEL_H
#include "stm32f4xx.h"                  // Device header
//khai bao so luong thread
#define NUM_OF_THREAD 3
//khai bao kick thuoc stack cho moi thread
#define STACK_SIZE 100
//khai bao xung clock
#define BUS_FREQ 			72000000
//Init some value for SysTick Reg
#define CTRL_ENABLE 		(1<<0)
#define CTRL_TICKINT 		(1<<1)
#define CTRL_CLCKSRC 		(1<<2)
#define CTRL_COUNTFLAG 		(1<<16)
#define SYSTICK_RST 		0
//Define struct tcb 
typedef struct{
	uint32_t* stackPt;
	struct tcb* nextPt;
}tcbType;

uint8_t osKernelAddThread(void (*task0)(void),void (*task1)(void), void (*task2)(void));
void osKernelStackInit(int i);
void osSchedulerLaunch();
void osKernelInit(void);
void osKernelLaunch(uint32_t quanta);
void SysTick_Handler();
#endif // KERNEL_H
