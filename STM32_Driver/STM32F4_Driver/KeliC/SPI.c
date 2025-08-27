#include "My_LIB_STM32F104.h"
void SP2_GPIOInits(void){
	GPIO_Handle SP;
	SP.GPIOx=GPIOB;
	SP.GPIO_PinConfig.GPIO_PinMode=GPIO_MODE_ALTFN;
	SP.GPIO_PinConfig.GPIO_PinAltFunMode=5;
	SP.GPIO_PinConfig.GPIO_PinOPType=GPIO_OP_TYPE_PP;
	SP.GPIO_PinConfig.GPIO_PinPuDdcontrol=GPIO_NO_PUPD;
	SP.GPIO_PinConfig.GPIO_PinSpeed=GPIO_SPEED_HIGH;
// SCLK
	SP.GPIO_PinConfig.GPIO_PinNumber=GPIO_PIN_13;
	GPIO_Init(&SP);
	//MOSI
	SP.GPIO_PinConfig.GPIO_PinNumber=GPIO_PIN_15;
	GPIO_Init(&SP);
	// NSS
	SP.GPIO_PinConfig.GPIO_PinNumber=GPIO_PIN_12;
	GPIO_Init(&SP);
}	
void SPI2_Init(void){
SPI_Handle_t SPI2handle;
	SPI2handle.SPI_Config.SPI_BusConfig;
	SPI2handle.SPI_Config.SPI_DeviceMode=SPI_DEVICE_MODE_MASTER;
	SPI2handle.SPI_Config.SPI_SclkSpeed=SPI_SLCK_SPEED_DIV2;// 8MHZ
	SPI2handle.SPI_Config.SPI_DFF=SPI_DFF_8Bits;
	SPI2handle.SPI_Config.SPI_CPOL=SPI_CPOL_HIGH;
	SPI2handle.SPI_Config.SPI_CPOL=SPI_CPHA_LOW;
	SPI2handle.SPI_Config.SPI_SSM=SPI_SSM_EN;
	SPI_Init(&SPI2handle);
}
	
	
int main (){

}