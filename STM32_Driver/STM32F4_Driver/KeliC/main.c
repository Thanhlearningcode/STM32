#include "My_LIB_STM32F104.h"

/////////GPIO
////////void delay(uint32_t k){
//for(uint32_t i;i<k;i++);
//}
//uint32_t a;
//int main(){
	//GPIO_Handle led11;
	//led11.GPIOx=GPIOC;
	//led11.GPIO_PinConfig.GPIO_PinNumber=GPIO_PIN_13;
	//led11.GPIO_PinConfig.GPIO_PinMode=GPIO_MODE_OUT;
	//led11.GPIO_PinConfig.GPIO_PinSpeed=GPIO_SPEED_HIGH;
	//led11.GPIO_PinConfig.GPIO_PinOPType=GPIO_OP_TYPE_PP;
	//led11.GPIO_PinConfig.GPIO_PinPuDdcontrol=GPIO_NO_PUPD;
	//GPIO_Init(&led11);
	
	//GPIO_Handle bt;
	//bt.GPIOx=GPIOA;
	//bt.GPIO_PinConfig.GPIO_PinNumber=GPIO_PIN_1;
	//bt.GPIO_PinConfig.GPIO_PinMode=GPIO_MODE_IN;
	//bt.GPIO_PinConfig.GPIO_PinSpeed=GPIO_SPEED_HIGH;
	//bt.GPIO_PinConfig.GPIO_PinPuDdcontrol=GPIO_PIN_PU;
	//GPIO_Init(&bt);
	//GPIO_IRQInterupt_Config(IRQ_NO_EXTI1,ENABLE);
	//GPIO_IRQPriority_Config(IRQ_NO_EXTI1,3);
	//while(1){
	//GPIO_Toggle_OutPutPin(GPIOC,13);

	//}
//return 0;}
//void EXTI1_IRQHandler (){
//	a++;
//	delay(1000);
 //GPIO_IRQHandling(GPIO_PIN_1);
	//GPIO_Toggle_OutPutPin(GPIOC,1);
	
//////////////////////////SPI

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
// HOW TO SEND // 

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
SP2_GPIOInits();
SPI2_Init();
SPI_SSIConfig(SPI2,ENABLE);
SPI_PeripheralControl(SPI2,1);

}