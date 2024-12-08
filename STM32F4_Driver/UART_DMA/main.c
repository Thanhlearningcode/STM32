#include "stm32f411xe.h"
#include "UART_DMA.h"
void UART_Init()
{
    /* set alternate function for PA2 & PA3 in alternate */
    __HAL_RCC_GPIOA_CLK_ENABLE();

    uint32_t* GPIOA_MODER = (uint32_t*)0x40020000;
    *GPIOA_MODER &= ~(0b1111 << 4);
    *GPIOA_MODER |= (0b10 << 4) | (0b10 << 6);

    uint32_t* GPIOA_AFRL = (uint32_t*)0x40020020;
    *GPIOA_AFRL &= ~(0xff << 8);
    *GPIOA_AFRL |= (7 << 8) | (7 << 12);

    __HAL_RCC_USART2_CLK_ENABLE();
    /* set baudrate 9600 */
    uint32_t* BRR = (uint32_t*)0x40004408;
    // 104.1667
    *BRR = (104 << 4) | (3);

 uint32_t* CR1 = (uint32_t*)0x4000440c;
*CR1 |= (1 << 13) | (1 << 2) | (1 << 3); // | (1 << 5);

uint32_t* CR3 = (uint32_t*)0x40004414;
*CR3 |= (1 << 6); // enable DMA for RX

uint32_t* ISER1 = (uint32_t*)0xe000e104;
*ISER1 |= (1 << (38 - 32));

DMA_Init();
}
void DMA_Init()
{
    uint32_t* SSPAR = (uint32_t*)0x40026090;
    *SSPAR = 0x40004404;

    uint32_t* SSMOAR = (uint32_t*)0x40026094;
    *SSMOAR = (uint32_t)rx_buf;

    uint32_t* SSNDTR = (uint32_t*)0x4002608c;
    *SSNDTR = sizeof(rx_buf);

    uint32_t* SSCR = (uint32_t*)0x40026088;
    *SSCR &= ~(0b111 << 25);
    *SSCR |= (4 << 25) | (1 << 10) | 1;
}

int main(void) {


    
    Uart_DMAStream5_Init_Receiver(9600); 

  
    while (1) {
    

 
           }
				 }
   
     
       
