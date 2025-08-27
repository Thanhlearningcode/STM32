#include "RTOS.h"

//< Index of task
static uint8_t id_current_task = 1;
//< Define timeslot
static uint32_t time_slot_cfg = 1; //Ms
//< Define threads
static ThreadTypedef_t mThreadControl[NUM_TASKS] = {{0,emIde,NULL}, {0,emIde,NULL}, {0,emIde,NULL}};
//< Define detail tasks
extern void Task1(void);
extern void Task2(void);
static void TaskIde(void)
{
	while(1)
	{
		
	}
}
//< Initialize threads
void InitializeThreads(void)
{
	//< Init ide task
	(mThreadControl + IDE_ID)->PSP_Stack   = IDE_STACK;
	(mThreadControl + IDE_ID)->State       = emIde;
	(mThreadControl + IDE_ID)->Task        = (TaskTypedef)&TaskIde;
	//< Init task 1
	(mThreadControl + TASK1_ID)->PSP_Stack = FIRST_STACK;
	(mThreadControl + TASK1_ID)->State     = emIde;
	(mThreadControl + TASK1_ID)->Task      = (TaskTypedef)&Task1;
	//< Init task 2
	(mThreadControl + TASK2_ID)->PSP_Stack = SECOND_STACK;
	(mThreadControl + TASK2_ID)->State     = emIde;
	(mThreadControl + TASK2_ID)->Task      = (TaskTypedef)&Task2;
	//< Init stack buffer for each task
	uint32_t* cur_stack_ptr = NULL;
	for(uint8_t id = 0; id < NUM_TASKS; id++)
	{
		cur_stack_ptr = (uint32_t*)(mThreadControl + id)->PSP_Stack;
		// xPSR register
		*cur_stack_ptr = 0x01000000U;
		cur_stack_ptr--;
		// PC register
		*cur_stack_ptr = (uint32_t)(mThreadControl + id)->Task;
		cur_stack_ptr--;
		// LR
		*cur_stack_ptr = 0xFFFFFFFDU; // Use PSP stack and thread mode
		cur_stack_ptr--;
		// Initialize remain registers
		for(uint8_t i = 0; i <= 12; i++)
		{
			*cur_stack_ptr  = 0U;
			cur_stack_ptr--;
		}
		cur_stack_ptr++;
		(mThreadControl + id)->PSP_Stack = (uint32_t)cur_stack_ptr;
	}
}

void SystemTickSetup(const uint32_t _time_slot)
{
	// config a tick = 1ms
	if(!_time_slot) return;
	time_slot_cfg  = _time_slot;
	SysTick->CTRL &= ~(1<<16);
	SysTick->CTRL |= (1<<2);
	SysTick->CTRL |= (1<<1);
	SysTick->LOAD  = 72000 - 1;
	SysTick->VAL   = 0;
	SysTick->CTRL |= (1<<0);	
}

static void TriggerPendSV(RequestPendSV_t state)
{
	static uint8_t request[2] = {27,28};
	SCB->ICSR |= (1<<request[(uint8_t)state]);
}

void SysTick_Handler(void)
{
	//<Update tick
	for(uint8_t i = 0; i < NUM_TASKS; i++)
	{
		if((mThreadControl + i)->Delay_Tick != 0)
		{
			(mThreadControl + i)->Cur_Tick++;
		}
	}
	//<Update state
	for(uint8_t i = 1; i < NUM_TASKS; i++)
	{
		if(i == id_current_task) continue;
		if(((mThreadControl + i)->Delay_Tick != 0) && \
			 ((mThreadControl + i)->Cur_Tick == (mThreadControl + i)->Delay_Tick))
		{
			(mThreadControl + i)->State      = emIde;
			(mThreadControl + i)->Delay_Tick = 0;
			(mThreadControl + i)->Cur_Tick   = 0;
		}
	}
	TriggerPendSV(emValid);
}

void StoreCurrentStack(const uint32_t _cur_stack)
{
	(mThreadControl + id_current_task)->PSP_Stack = _cur_stack;
}

void ContextSwitch(void)
{
	uint8_t pre_id = id_current_task;
	for(uint8_t i = id_current_task + 1;i<NUM_TASKS; i++)
	{
		if(emIde == (mThreadControl + i)->State)
		{
			id_current_task = i;
			break;
		}
	}
	if(pre_id == id_current_task)
	{
		for(int i = 1; i < id_current_task; i++)
		{
			if(emIde == (mThreadControl + i)->State)
			{
				id_current_task = i;
				break;
			}
		}
	}
	if(pre_id == id_current_task)
	{
		id_current_task = 0;//ide task
	}
}

uint32_t GetNextTask(void)
{
	return (mThreadControl + id_current_task)->PSP_Stack;
}

void DelayMs(uint32_t _tick)
{
	(mThreadControl + id_current_task)->Delay_Tick = _tick;
	(mThreadControl + id_current_task)->State      = emRunning;
	(mThreadControl + id_current_task)->Cur_Tick   = 0;
	 TriggerPendSV(emValid);
}

void ConfigPriIRQ(void)
{
	SCB->AIRCR = 0x05FA0300;
	SCB->SHP[emPendSV]  = 0xF0;
	SCB->SHP[emSystick] = 0x00;
}


