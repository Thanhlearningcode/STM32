#include "TIMERF4.h"
void Delay(uint16_t time){
	TIM1->CNT=0;
while(time>0){
while( (TIM1->SR&0x1)==1){
time--;
	TIM1->SR&=~0x1;
}
}
}
void TiM1_init(void){

RCC->APB2ENR|=(1U<<0);
	TIM1->CNT=0;
	TIM1->PSC=15;
	TIM1->ARR=999;
	TIM1->CR1|=(1U<<7);
	TIM1->CR1&=~(1U<<4);
	TIM1->CR1&=~(1U<<2);
		TIM1->CR1&=~(1U<<1);
	TIM1->EGR|=(1U<<0);
	TIM1->CR1|=(1U<<0);
}
uint16_t get_timer(){
return TIM1->CNT;
}
void Configure_PMW( void){
		/// PIND12 chanel 1
RCC->AHB1ENR|=(1U<<3);
RCC->APB1ENR|=(1U<<2);
	GPIOD->MODER&=~(3U<<24);
	GPIOD->MODER|=(2U<<24);
GPIOD->AFR[1]|=(2<<16);
		TIM4 ->ARR =999; // 1ms 
	TIM4 -> PSC = 15;
TIM4->CCR1 = 30;

	TIM4->CCMR1 &=~(0x3<<0);
	TIM4->CCMR1|=(6U<<4);
	TIM4->CCER |= 1;
	TIM4->CR1 |=  (1<<0);
}

void tim4_init(void)
{
	
	/* tim base */
	RCC->APB1ENR |= (1 << 2);
	TIM4->CR1 = (1 << 7) | (1 << 1);
	TIM4->PSC = 84 - 1;
	TIM4->ARR = 10 - 1;
	TIM4->CR1 &= ~(1 << 1);
	TIM4->EGR = 1;
	TIM4->CR1 |= (1 << 0);
	
	/* capture */
	TIM4->CCMR1 |= (1 << 0);
	TIM4->CCER |= (1 << 3) | (1 << 1) | (1 << 0);
	
	/* PB6 */
	RCC->AHB1ENR |= (1 << 1);
	GPIOB->MODER &= ~(3 << 12);
	GPIOB->MODER |= (1 << 13);
	GPIOB->OSPEEDR |= (3 << 12);
	GPIOB->AFR[0] &= ~(15 << 24);
	GPIOB->AFR[0] |= (2 << 24);
	TIM4->DIER |= (1 << 9);}