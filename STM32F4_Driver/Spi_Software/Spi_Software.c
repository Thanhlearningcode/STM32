#include "Spi_Software.h"
/* PE11  SPI_NSS
   PE12  SPI_SCK
   PE13  SPI_MISO
	 PE14	 SPI_MOSI
*/
void Delay(uint32_t time){
while(time--){}}
void Clock(void){
GPIOE->ODR|=(1U<<12);
Delay(4);
GPIOE->ODR&=~(1U<<12);
Delay(4);
}
void Spi_Transmit_Init(void){
RCC->AHB1ENR|=(1U<<4);
// Gpio Config SPI_NSS_Pin|SPI_SCK_Pin| SPI_MISO_Pin| SPI_MOSI_Pin Mode out_pp
GPIOE->MODER&=~(0xFFU<<2);
GPIOE->MODER|=(1U<<22)|(1U<<24)|(1U<<28);
GPIOE->OTYPER&=~(0xFU<<11); 
GPIOE->OTYPER|=(1U<<3); // MISO 
GPIOE->OSPEEDR|=(1U<<22)|(1U<<24)|(1U<<26)|(1U<<28);
// Spi_Config
GPIOE->ODR&=~(1U<<12);
GPIOE->ODR|=(1U<<11);	
GPIOE->ODR&=~(3U<<13);
}
void Spi_Receive_Init(void){
RCC->AHB1ENR|=(1U<<4);
//  Gpio Config SPI_NSS_Pin|SPI_SCK_Pin| SPI_MISO_Pin| SPI_MOSI_Pin Mode out_pp
GPIOE->MODER&=~(0xFFU<<22);
GPIOE->MODER|=(1U<<26);
GPIOE->OTYPER&=~(1U<<13); // PP
GPIOE->OSPEEDR|=(1U<<22)|(1U<<24)|(1U<<26)|(1U<<28);
}
void Spi_Master_Transmit(uint8_t Data){
uint8_t u8Mask=0x80; // 0b10000000
uint8_t tempData;
	GPIOE->ODR&=~(1U<<11);// CS to low
	Delay(1);
for(int i=0;i<8;i++){
	tempData=Data&u8Mask;
if(tempData){
	GPIOE->ODR|=(1U<<14); // MOSI to 1
	Delay(1);
}else{
	GPIOE->ODR&=~(1U<<14); // MOSI to 0
Delay(1);
}
	Data=Data<<1;
	Clock();
}	
	GPIOE->ODR|=(1U<<14);
	Delay(1);
}
//  Gpio Config SPI_NSS_Pin|SPI_S	CK_Pin| SPI_MISO_Pin| SPI_MOSI_Pin Mode out_pp
uint8_t Spi_Slave_Receive(void){
uint8_t u8Mask=0x80;
uint8_t dataReceive=0x00; 
uint8_t temp=0x00;
uint8_t i=0;
while( (GPIOE->IDR&(1<<11)));
while( !(GPIOE->IDR&(1<<12)));
for( int i=0;i<8;i++){
if( (GPIOE->IDR&(1<<12))){
while( (GPIOE->IDR&(1<<12)));
temp= (GPIOE->IDR&(1<<14));
dataReceive=dataReceive<<1;
dataReceive=dataReceive|temp;
}
while( !(GPIOE->IDR&(1<<12)));
}
return dataReceive;
}
