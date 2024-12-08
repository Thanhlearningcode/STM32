#include "kernel.h"
void (*PeriodicTask)(void);
#define NULL (void*)0	
//Khai bao kich co Stack cho moi thread 
#define STACK_SIZE 			100 
//Khai bao so luong thread 
#define NUM_OF_THREADS		5
//Khai bao so luong periodic tasks
#define NUM_OF_PERIODIC_TASKS 10 
// ICSR Base Address
#define INTCTRL (*((volatile uint32_t *)0XE000ED04)) 
//Bit pendSV Set
#define PENDSTSET   (1<<26)
//Khai bao so lan switch task thi period task se chay
#define PERIOD 100

/* SysTick Resgister Define */
//Clock freq for SysTick
#define BUS_FREQ 			72000000 
//Cho phep bo dem sysTick Hoat Dong
#define CTRL_ENABLE 			(1<<0)
//Cho Phep Ngat Systick
#define CTRL_TICKINT 			(1<<1)
//Chon nguon cap xung clock cho Systick
#define CTRL_CLCKSRC 			(1<<2)
//Set co ngat Systick
#define CTRL_COUNTFLAG 		(1<<16)
//Gia tri Reset cho systick
#define SYSTICK_RST 			0
//Set value for SysTick (to calculate quanta time)
uint32_t MILLIS_PRESCALER;
//TCB Struct
struct tcb{
	uint32_t *stackPt;
	struct tcb* nextPt;
	uint32_t sleepTime;
};
// Define lai kieu du lieu cua TCB
typedef struct tcb tcbType;
//Khai bao TCB for each thread
tcbType tcbs[NUM_OF_THREADS];
//Define CurrentPt for deciding which thread is running.
tcbType *currentPt;
// Khai bao perioTick
uint32_t periodTick = 0;
//Khoi tao vung nho Stack
uint32_t TCB_STACK[NUM_OF_THREADS][STACK_SIZE];
//Khai bao con tro ham - ham nay k nhan gia tri vao
typedef void(*taskT)(void);
//Define kieu du lieu periodicTaskT
typedef struct{
	taskT task;
	uint32_t period;
	uint32_t timeLeft;
}periodicTaskT;
//Khai Bao so luon PeriodicTasks
static periodicTaskT PeriodicTasks[NUM_OF_PERIODIC_TASKS];
//So luong Thread cua PeriodcTasks
static uint32_t numberofPeriodicThreads = 0;
static uint16_t current_num_of_thread=0;
static uint32_t TimeMSec;
static uint32_t MaxPeriod;
uint32_t *edge_semaphore;
/*___________MAILBOX___________*/
static uint32_t MailBox_hasdata;
static uint32_t MailBox_Data;
static uint32_t MailBox_Semaph;
/*FIFO Data 	Tranfer*/
#define FIFO_SIZE  15
uint32_t PutIndex;
uint32_t GetIndex;
uint32_t Os_Fifo[FIFO_SIZE];
uint32_t currentFFSize;
uint32_t lostdata;
//Thuc hien ngat systick Khi goi ham
void osThreadYield(){
	SysTick->VAL = 0; // Reset sys cnt value to 0
	INTCTRL |= PENDSTSET;
}
/*Ex
1s -> Bus_Freq 
1000ms-> Bus_Freq
1ms -> Bus_Freq/1000
*/
void osKernelInit(void){
	//1ms
	MILLIS_PRESCALER = (BUS_FREQ/1000);	
	osPeriodicTask_Init(periodic_events_exe, 1000, 6);
}

void TIM2_IRQHandler(){
	TIM2->SR = 0;
	(*PeriodicTask)();
}

void osKernelLaunch(uint32_t quanta){
	/*Reset the SysTick*/
	SysTick->CTRL = SYSTICK_RST;
	/*Clear Systick current value register*/
	SysTick->VAL = 0;
	/*Load the quanta*/
	SysTick->LOAD = (quanta*MILLIS_PRESCALER-1);
	/*Set Systick interupt to lowest priority*/
	NVIC_SetPriority(SysTick_IRQn, 0);
	/*Enable Systick, select Internal clock*/
	SysTick->CTRL |= CTRL_CLCKSRC|CTRL_ENABLE;
	/*Enable Systick interupt*/
	SysTick->CTRL |= CTRL_TICKINT;
	//os launch scheduler
	osSchedulerLaunch();
}

//Init Stack for Thread I
void osKernelStackInit(int i){
	//set StackPt
	tcbs[i].stackPt = &TCB_STACK[i][STACK_SIZE-16];
	/*Set bit24 (T-Bit) in PSR to 1 to operate it*/
	/*Thumb Mode*/
	TCB_STACK[i][STACK_SIZE-1] = 1<<24;	/*PSR*/
	/*Skip the PC*/
	//
	/*Dumming Stack Content*/
	TCB_STACK[i][STACK_SIZE-3] 	= 0xAAAAAAAA;/*R14 (LR)*/
	TCB_STACK[i][STACK_SIZE-4] 	= 0xAAAAAAAA;/*R12*/
	TCB_STACK[i][STACK_SIZE-5] 	= 0xAAAAAAAA;/*R3*/
	TCB_STACK[i][STACK_SIZE-6] 	= 0xAAAAAAAA;/*R2*/
	TCB_STACK[i][STACK_SIZE-7] 	= 0xAAAAAAAA;/*R1*/
	TCB_STACK[i][STACK_SIZE-8] 	= 0xAAAAAAAA;/*R0*/
	
	TCB_STACK[i][STACK_SIZE-9] 	= 0xAAAAAAAA;/*R11*/
	TCB_STACK[i][STACK_SIZE-10] = 0xAAAAAAAA;/*R10*/
	TCB_STACK[i][STACK_SIZE-11] = 0xAAAAAAAA;/*R9*/
	TCB_STACK[i][STACK_SIZE-12] = 0xAAAAAAAA;/*R8*/
	TCB_STACK[i][STACK_SIZE-13] = 0xAAAAAAAA;/*R7*/
	TCB_STACK[i][STACK_SIZE-14] = 0xAAAAAAAA;/*R6*/
	TCB_STACK[i][STACK_SIZE-15] = 0xAAAAAAAA;/*R5*/
	TCB_STACK[i][STACK_SIZE-16] = 0xAAAAAAAA;/*R4*/
}

uint8_t osKernelAddThread(void (*task0)(void),void (*task1)(void), void (*task2)(void)){
	/*Disable global Interupt*/
	__disable_irq();
	tcbs[0].nextPt = &tcbs[1];
	tcbs[1].nextPt = &tcbs[2];
	tcbs[2].nextPt = &tcbs[0];
	
	osKernelStackInit(0);
	TCB_STACK[0][STACK_SIZE-2] = (uint32_t)(task0);
	
	osKernelStackInit(1);
	TCB_STACK[1][STACK_SIZE-2] = (uint32_t)(task1);

	osKernelStackInit(2);
	TCB_STACK[2][STACK_SIZE-2] = (uint32_t)(task2);
	
	//inside add thread
	for(int i=0; i< NUM_OF_THREADS; i++){
	tcbs[i].sleepTime = 0;
	}

	currentPt = &tcbs[0];
	
	__enable_irq();
	
	return 1;
}
uint8_t osKernelAdd1Thread(void (*task)(void)){
	/*Disable global Interupt*/
	__disable_irq();
	
	osKernelStackInit(current_num_of_thread);
	TCB_STACK[current_num_of_thread][STACK_SIZE-2] = (uint32_t)(task);
	
	if(!current_num_of_thread){
		tcbs[current_num_of_thread].nextPt = &tcbs[current_num_of_thread];
	} else {
		tcbs[current_num_of_thread-1].nextPt = &tcbs[current_num_of_thread];
		tcbs[current_num_of_thread].nextPt = &tcbs[0];
	}
	
	tcbs[current_num_of_thread].sleepTime = 0;
	currentPt = &tcbs[0];
	current_num_of_thread++;
	__enable_irq();
}

uint8_t osKernelAddPeriodicThreads(void(*task)(void), uint32_t period){
	if(numberofPeriodicThreads == NUM_OF_PERIODIC_TASKS || period == 0){
		return 0;
	}
	PeriodicTasks[numberofPeriodicThreads].task = task;
	PeriodicTasks[numberofPeriodicThreads].period = period;
	PeriodicTasks[numberofPeriodicThreads].timeLeft = period-1;
	
	numberofPeriodicThreads++;
	return 1;
}

void osSchedulerRoundRobin(){
	periodTick++;
	if((periodTick%100) == 1){
		(*periodicTask0)();
	}
	if((periodTick%200) == 1){
		(*periodicTask1)();
	}
	currentPt = currentPt->nextPt;
	while(currentPt->sleepTime>0){
		currentPt = currentPt->nextPt;
	}
}

void osSemaphore_Init(uint32_t *semaphore, uint32_t val){
	*semaphore = val;
}
//return the semaphore access right
void osSemaphore_Give(uint32_t *semaphore){
	__disable_irq();//disable interrup
	*semaphore +=1;
	__enable_irq();//enable interrup
}
//check until the semaphore is ready
void osSpinLock_Wait(uint32_t *semaphore){
	__disable_irq();
	
	while(*semaphore <= 0){
		__enable_irq();
		__disable_irq();
	}
	*semaphore -=1;
	
	__enable_irq();
}
//check if the semaphore is ready, if not -> switch to another Thread
void osCooperative_Wait(uint32_t *semaphore){
	__disable_irq();
	
	while(*semaphore <= 0){
		__enable_irq();
		osThreadYield();
		__disable_irq();
	}
	*semaphore -=1;
	
	__enable_irq();
}

void osSchedulerPeriodicRoundRobin(){
	if(TimeMSec<MaxPeriod) TimeMSec++;
	else
		TimeMSec=1;
	for(int i=0; i<NUM_OF_PERIODIC_TASKS; i++){
		if(TimeMSec%PeriodicTasks[i].period ==0 && PeriodicTasks[i].task != NULL){
			PeriodicTasks[i].task();
		}
	}
	currentPt = currentPt->nextPt;
	while(currentPt->sleepTime>0){
		currentPt = currentPt->nextPt;
	}
}

void periodic_events_exe(){
	int i;
	for(i = 0; i<numberofPeriodicThreads; i++){
		if(PeriodicTasks[i].timeLeft == 0 ){
			PeriodicTasks[i].task();
			PeriodicTasks[i].timeLeft =  PeriodicTasks[i].period-1;
		}
		else PeriodicTasks[i].timeLeft --;
	}
	//Check each Thread if sleepTime > 0
	for(i=0; i<NUM_OF_THREADS; i++){
		if(tcbs[i].sleepTime >0){
			tcbs[i].sleepTime--;
		}
	}
}
//Set Sleep Time for Thread
void osThreadsSleep(uint32_t sleeptime){
	__disable_irq();
	currentPt->sleepTime = sleeptime;
	__enable_irq();
	osThreadYield();
}

void osPeriodicTask_Init(void(*task)(void), uint32_t freq, uint8_t priority){
	__disable_irq();
	PeriodicTask = task;
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	TIM2->PSC = 72-1;
	TIM2->ARR = 1000000/freq -1;
	TIM2->CR1 = 1;
	TIM2->DIER |= 1;
	NVIC_SetPriority(TIM2_IRQn , priority);
	NVIC_EnableIRQ(TIM2_IRQn);
}
// Cau hinh EXTI cho PA0
void EdgeTrigger_Init(void){
	__disable_irq();
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN| RCC_APB2ENR_AFIOEN; //Kich hoat xung clock cap cho GPIOA
											
	GPIOA->CRL &= ~GPIO_CRL_MODE0_0; 	//MODE = 00: Intput mode.
	GPIOA->CRL &= ~GPIO_CRL_MODE0_1; 
	GPIOA->CRL |= GPIO_CRL_CNF0_1;	 //CNF = 10: Input with pull-up / pull-down
	GPIOA->CRL &= ~GPIO_CRL_CNF0_0;	       
	GPIOA->ODR |= GPIO_ODR_ODR0; //Set ODR0, PA0 now working as input pull up.
	
	AFIO->EXTICR[0] &=~(0x0F<<0);
	EXTI->IMR |= (1<<0);
	EXTI->RTSR &=~ (1<<0);
	EXTI->FTSR |= (1<<0);
	//Set Do uu tien chi sau Systick
	NVIC_SetPriority(EXTI0_IRQn, 1);
	NVIC_EnableIRQ(EXTI0_IRQn);
}

void osEdgeTriggerInit(uint32_t *semaphore){
	edge_semaphore = semaphore;
	EdgeTrigger_Init();
}
void EXTI0_IRQHandler(void){
	osSemaphore_Give(edge_semaphore);
	EXTI->PR |= 1<<0;
}
void MailBox_Init(void){
	MailBox_hasdata = 0;
	MailBox_Data = 0;
	osSemaphore_Init(&MailBox_Semaph, 0);
}
void osMailBoxSend(uint32_t data){
	__disable_irq();
	if(MailBox_hasdata){
		__enable_irq();
		return;
	}
	MailBox_Data = data;
	MailBox_hasdata = 1;
	__enable_irq();
	osSemaphore_Give(&MailBox_Semaph);
	
}
uint32_t osMailBoxReceive(void){
	osCooperative_Wait(&MailBox_Semaph);
	uint32_t data;
	__disable_irq();
	data = MailBox_Data;
	MailBox_hasdata = 0;
	
	__enable_irq();
	return data;
}
void FIFO_Init(void){
	PutIndex = 0;
	GetIndex = 0;
	osSemaphore_Init(&currentFFSize, 0);
	lostdata = 0;
}
uint8_t osFIFOPut(uint32_t data){
	if(currentFFSize == FIFO_SIZE){
		lostdata++;
		return -1;
	}
	Os_Fifo[PutIndex] = data;
	PutIndex = (PutIndex+1)%FIFO_SIZE;
	osSemaphore_Give(&currentFFSize);
	
	return 1;
}
uint32_t osFIFOGet(void){
	uint32_t data;
	osCooperative_Wait(&currentFFSize);
	__disable_irq();
	data = Os_Fifo[GetIndex];
	GetIndex = (GetIndex+1)%FIFO_SIZE;
	__enable_irq();
	return data;
}
