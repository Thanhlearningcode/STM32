#include "stm32f4xx.h"


int main(){
RCC->AHB1ENR |= ( 1U << 0 );
RCC->APB1ENR |= ( 1U << 17 );
GPIOA->MODER &=~ ( 0xF << 0 );
GPIOA->MODER |=( 1U << 1 );
GPIOA->MODER |= ( 1U << 3 );
GPIOA->AFR[0]|=( 7U << 0);
GPIOA->AFR[0]|=( 7U << 4);
while(1){

}
return 0;
}