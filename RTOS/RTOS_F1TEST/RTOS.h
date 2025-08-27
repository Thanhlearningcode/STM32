#ifndef __RTOS_H__
#define __RTOS_H__

#include "stm32f10x.h"
//< Define basic parameter stack
#define NUM_TASKS          0x3
#define IDE_ID             0x0
#define TASK1_ID           0x1
#define TASK2_ID           0x2
#define BASE_ADDRESS_STACK 0x20000000U
#define TOP_STACK          (BASE_ADDRESS_STACK + 1024*8)
#define STACK_SIZE         1024 //2Kb
#define IDE_STACK           TOP_STACK
#define FIRST_STACK        (TOP_STACK - STACK_SIZE) //< 0x20002000
#define SECOND_STACK       (TOP_STACK - 2*STACK_SIZE) //< 0x20001800
#define MSP_STACK          (TOP_STACK - 4*STACK_SIZE) //< 0x20001000
#define NULL               ((void*)0)

typedef enum eTaskState
{
	emIde     = 0,
	emRunning = 1,
}TaskState_t;

typedef enum ePriIRQs
{
	emSystick = 11,
	emPendSV  = 10,
}ePriIRQs_t;

typedef enum eRequestPendSV
{
	emInValid = 0,
	emValid,
}RequestPendSV_t;

typedef void (*TaskTypedef)(void);
typedef struct
{
	uint32_t    PSP_Stack;
	TaskState_t State;
	TaskTypedef Task;
	uint32_t    Delay_Tick;
	uint32_t    Cur_Tick;
}ThreadTypedef_t;

void InitializeThreads(void);
void SystemTickSetup(const uint32_t _time_slot);
void StoreCurrentStack(const uint32_t _cur_stack);
void ContextSwitch(void);
uint32_t GetNextTask(void);
void DelayMs(uint32_t _tick);
__WEAK void ConfigPriIRQ(void);

#endif //__RTOS_H__