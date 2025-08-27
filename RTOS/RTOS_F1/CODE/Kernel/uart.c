#include "uart.h"
#include "stdio.h"

//struct __FILE{int dummy;};
//FILE __sdtout;

//int fputc(int ch, FILE *f){
//	Uart_send(ch);
//	return ch;
//}

void Uart_Init(){
	//Enable clock for GPIOA and Usart1
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN|RCC_APB2ENR_USART1EN;
	//PIN 9 as AF_PP
	//mode 11
	GPIOA->CRH 	|= (GPIO_CRH_MODE9_0);
	GPIOA->CRH 	|= (GPIO_CRH_MODE9_1);
	//CNF = 10
	GPIOA->CRH 	&= ~(GPIO_CRH_CNF9_0);
	GPIOA->CRH 	|= (GPIO_CRH_CNF9_1);
	//PIN 10 as AF_PP
	//mode 00
	GPIOA->CRH  &= ~(GPIO_CRH_MODE10_0);
	GPIOA->CRH  &= ~(GPIO_CRH_MODE10_1);
	//CNF = 01
	GPIOA->CRH  |= (GPIO_CRH_CNF10_0);
	GPIOA->CRH 	&= ~(GPIO_CRH_CNF10_1);
	
	//Config Usart1
	USART1->BRR |= 0x1D4<<4;
	USART1->BRR |= 0xC;
	USART1->CR1 |= 1<<13|1<<5|1<<3|1<<2;
}

void Uart_Send(int c){
	USART1->DR = c;
	while(!(USART1->SR & 1<<6));
	USART1->SR &= ~(1<<6);
}
