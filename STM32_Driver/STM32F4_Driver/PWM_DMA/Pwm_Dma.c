#include "Pwm_Dma.h"
#define LOOKUP_TABLE_LEN		200

uint32_t ch1_duty_cycl_lookup[LOOKUP_TABLE_LEN]=
{
	0,50 ,100 ,151 ,201 ,250 ,300 ,349 ,398 ,446 ,494 ,542 ,589 ,635 ,681
	,726 ,771 ,814 ,857 ,899 ,940 ,981 ,1020 ,1058 ,1095 ,1131 ,1166 ,1200 ,1233 ,1264
	,1294 ,1323 ,1351 ,1377 ,1402 ,1426 ,1448 ,1468 ,1488 ,1505 ,1522 ,1536 ,1550 ,1561
	,1572 ,1580 ,1587 ,1593 ,1597 ,1599 ,1600 ,1599 ,1597 ,1593 ,1587 ,1580 ,1572 ,1561
	,1550 ,1536 ,1522 ,1505 ,1488 ,1468 ,1448 ,1426 ,1402 ,1377 ,1351 ,1323 ,1294 ,1264
	,1233 ,1200 ,1166 ,1131 ,1095 ,1058 ,1020 ,981 ,940 ,899 ,857 ,814 ,771 ,726 ,681 ,635
	,589 ,542 ,494 ,446 ,398 ,349 ,300 ,250 ,201 ,151 ,100 ,50,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0
	,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0
	,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0

};

uint32_t ch2_duty_cycl_lookup[LOOKUP_TABLE_LEN]=
{
	 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0
	,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0
	,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0
	,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,50 ,100 ,151 ,201 ,250 ,300 ,349 ,398 ,446 ,494
	,542 ,589 ,635 ,681 ,726 ,771 ,814 ,857 ,899 ,940 ,981 ,1020 ,1058 ,1095 ,1131 ,1166 ,1200 ,1233
	,1264 ,1294 ,1323 ,1351 ,1377 ,1402 ,1426 ,1448 ,1468 ,1488 ,1505 ,1522 ,1536 ,1550 ,1561 ,1572 ,1580
	,1587 ,1593 ,1597 ,1599 ,1600 ,1599 ,1597 ,1593 ,1587 ,1580 ,1572 ,1561 ,1550 ,1536 ,1522 ,1505 ,1488
	,1468 ,1448 ,1426 ,1402 ,1377 ,1351 ,1323 ,1294 ,1264 ,1233 ,1200 ,1166 ,1131 ,1095 ,1058 ,1020 ,981

};
void Pwm_Dma_Init(void){
	/*Set PA0 and PA1 mode to alternate function mode*/
	/*PA8*/
	GPIOA->MODER &= ~(1U<<16);
	GPIOA->MODER |= (1U<<17);

	/*PA9*/
	GPIOA->MODER &= ~(1U<<18);
	GPIOA->MODER |= (1U<<19);
	/*Set alternate function type to TIM1 (AF01)*/
	GPIOA->AFR[1]&=~(0xFFU<<16);
	GPIOA->AFR[1]|=(1U<<16);
	GPIOA->AFR[1]|=(1U<<20);
		RCC->APB2ENR |=(1U<<0); // Clock Tim en
		RCC->AHB1ENR |=(1U<<0); // Clock Gpioa en
		TIM1->CNT=0; 					 
		TIM1->PSC=15;
		TIM1->ARR=999;
		TIM1->DIER|=(1U<<8)|(1U<<9)|(1U<<10); 
		TIM1->CCR1=0;
		TIM1->CCR2=0;
	/*Set PA9 (ch2) and PA8 (ch1) to 110 : PWM mode 1*/
		TIM1->CCMR1|=(6U<<4); 
		TIM1->CCMR1|=(6U<<12); 
		/*Enable ch1 and ch2*/
		TIM1->CCER|=(1U<<0)|(1U<<4);
	/*****Configure DMA Parameters***/
	/*Enable clock access DMA*/
	RCC->AHB1ENR |=(1U<<22); 
		/*Disable DMA stream*/
	DMA2_Stream6->CR = 0;
	/*Wait till DMA Stream is disabled*/
	while((DMA1_Stream5->CR & (1U<<0))){}
		/*Select DMA channel : CH0*/
		DMA2_Stream6->CR&=~(7U<<25);
			/*Enable circular mode*/
		DMA2_Stream6->CR|=(1U<<8);
		/*Enable Mem Addr increment*/
				DMA2_Stream6->CR|=(1U<<10);
		/*Set Mem size :  32bit*/
		DMA2_Stream6->CR &=~(1U<<13);
   	DMA2_Stream6->CR |=(1U<<14);
		/*Set Periph size :  32bit*/
		DMA2_Stream6->CR &=~(1U<<11);
		DMA2_Stream6->CR |=(1U<<12);
		/*Set Transfer direction : Mem to Periph */
		DMA2_Stream6->CR |=(1U<<6);
		DMA2_Stream6->CR &=~(1U<<7);
			/*Set number of transfer*/
		DMA1_Stream5->NDTR = (uint16_t)LOOKUP_TABLE_LEN;

		/*Set peripheral address*/
		DMA1_Stream5->PAR =  (uint32_t)(&TIM2->CCR1);
		/*Set memory address*/
		DMA1_Stream5->M0AR = (uint32_t)(&ch1_duty_cycl_lookup);

		/*Enable the DMA Stream*/
		DMA1_Stream5->CR |= (1U<<0);
//		/*******Stream 6******/
//	/*Disable DMA stream*/
//	DMA2_Stream6->CR = 0;

//	/*Wait till DMA Stream is disabled*/
//	while((DMA1_Stream6->CR & DMA_SCR_EN)){}

//	/*Select DMA channel : CH3*/
//	DMA1_Stream6->CR |=(1U<<25);
//	DMA1_Stream6->CR |=(1U<<26);
//	DMA1_Stream6->CR &=~(1U<<27);

//	/*Enable circular mode*/
//	DMA1_Stream6->CR |= SC_CIRC;

//	/*Enable Mem Addr increment*/
//	DMA1_Stream6->CR |=DMA_SCR_MINC;

//	/*Set Mem size :  32bit*/
//	DMA1_Stream6->CR &=~(1U<<13);
//	DMA1_Stream6->CR |=(1U<<14);

//	/*Set Periph size :  32bit*/
//	DMA1_Stream6->CR &=~(1U<<11);
//	DMA1_Stream6->CR |=(1U<<12);

//	/*Set Transfer direction : Mem to Periph */
//	DMA1_Stream6->CR |=(1U<<6);
//	DMA1_Stream6->CR &=~(1U<<7);

//	/*Set number of transfer*/
//	DMA1_Stream6->NDTR = (uint16_t)LOOKUP_TABLE_LEN;

//	/*Set peripheral address*/
//	DMA1_Stream6->PAR =  (uint32_t)(&TIM2->CCR2);
//	/*Set memory address*/
//	DMA1_Stream6->M0AR = (uint32_t)(&ch2_duty_cycl_lookup);

//	/*Enable the DMA Stream*/
//	DMA1_Stream6->CR |= DMA_SCR_EN;

//	/*Enable timer*/
//	TIM2->CR1 |=CR1_CEN;

}