/***************************************************************************
 * @file    kernel.h
 * @brief   Khai báo các hàm va cau truc lien quan toi kernel
 * @details File này cung cap giao dien cho viec dieu khien kernel
 * @version 1.0
 * @date    2024-10-07
 * @author  Nguyen Van Thanh
 * @contact https://github.com/Thanhlearningcode
 ***************************************************************************/
#ifndef _Kernel_H_
#define _Kernel_H_

#include "stm32f411xe.h"
 /* Number of Task */
#define VT_NUM_THREAD 	3
 /* Size of Stack for Thread */
#define VT_STACK_SIZE  100
 /* Configure CLOCK */
#define VT_CLOCK 			72000000
 
typedef struct {
	uint32_t *stackPointer;
	struct tcb*nextPointer;
}tcbTypedef;

uint8_t VT_Kernel_Thread(void (*Task0)(void),void (*Task1)(void), void (*Task2)(void) );
void VT_Kernel_Stack_Init(uint8_t Stack);
void VT_Scheduler_Launch(void);
void VT_Kernel_Init(void);
void VT_Kernel_Launch(uint32_t Quanta);
void Systick_Handler(void); 
#endif /* _Kernel_H_ */
 