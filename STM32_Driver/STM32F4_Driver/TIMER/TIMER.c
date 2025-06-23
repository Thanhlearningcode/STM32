#include "stm32f411xe.h"
void GPIOA_Init(void);
void GPIOA_Status(uint8_t status);
void Timer_Init(void);
void Delay_ms(uint16_t time);
int main(){ GPIOA_Init();
	Timer_Init();
while(1){
	
GPIOA_Status(1);
Delay_ms(700);
GPIOA_Status(0);
	}
}
void GPIOA_Init(void){
RCC->AHB1ENR|=(1U<<0); // CLOCK GPIOA EN
GPIOA->MODER|=(1U<<0); // General purpose output mode
GPIOA->OTYPER&=~(1U<<0); // PUSH-PULL
//GPIOA->ODR&=~(1U<<0); // SET PIN LOW
}
void GPIOA_Status(uint8_t status){
if(1==status){
GPIOA->ODR|=1<<0;}
else {
GPIOA->ODR&=~(1U<<0); 
}}
void Timer_Init(void){
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
TIM1->CR1 =1; // ENABLE TIM1
}	
void Delay_ms(uint16_t time){
	TIM1->EGR=0;
while(time>0){
while( (TIM1->SR&0x1)==1){
time--;
	TIM1->SR&=~0x1;
}}}