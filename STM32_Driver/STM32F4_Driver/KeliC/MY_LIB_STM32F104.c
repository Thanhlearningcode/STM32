#include "My_LIB_STM32F104.h"
void GPIO_PeriClockControl(GPIO_Regdef_t *GPIOx,uint8_t Enordi){
if(Enordi ==ENABLE){ if(GPIOx==GPIOA) { GPIOA_PCLK_EN();}
else if(GPIOx==GPIOB) { GPIOB_PCLK_EN();}
else if(GPIOx==GPIOC) { GPIOC_PCLK_EN();}
else if(GPIOx==GPIOD) { GPIOD_PCLK_EN();}
else if(GPIOx==GPIOE) { GPIOE_PCLK_EN();}
else if(GPIOx==GPIOF) { GPIOF_PCLK_EN();}
else if(GPIOx==GPIOG) { GPIOG_PCLK_EN();}
else if(GPIOx==GPIOH) { GPIOH_PCLK_EN();}
else if(GPIOx==GPIOI) { GPIOI_PCLK_EN();}
else if(GPIOx==GPIOJ) { GPIOJ_PCLK_EN();}
else if(GPIOx==GPIOK) { GPIOK_PCLK_EN();}
}else{}}
void GPIO_Init(GPIO_Handle *GPIO_Handle_t){
// ENABLE THE PERIPHERAL CLOCK 
	uint8_t temp=0;
	//Configure the mode of gpio pin
if(GPIO_Handle_t->GPIO_PinConfig.GPIO_PinMode<= GPIO_MODE_ANALOG)
{temp=(GPIO_Handle_t->GPIO_PinConfig.GPIO_PinMode<<(2*GPIO_Handle_t->GPIO_PinConfig.GPIO_PinNumber));
	GPIO_Handle_t->GPIOx->MODER&=~(0x3<<(2*GPIO_Handle_t->GPIO_PinConfig.GPIO_PinNumber));
	GPIO_Handle_t->GPIOx->MODER|=temp;
}
else{ if(GPIO_Handle_t->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_FALLING) {
EXTI -> FTSR &=~(1<<GPIO_Handle_t->GPIO_PinConfig.GPIO_PinMode);
EXTI -> RTSR |=(1<<GPIO_Handle_t->GPIO_PinConfig.GPIO_PinMode);
} else if(GPIO_Handle_t->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RAISING){
	EXTI -> RTSR &=~(1<<GPIO_Handle_t->GPIO_PinConfig.GPIO_PinMode);
EXTI -> FTSR |=(1<<GPIO_Handle_t->GPIO_PinConfig.GPIO_PinMode);
}
uint8_t temp1=GPIO_Handle_t->GPIO_PinConfig.GPIO_PinMode/4;
uint8_t temp2 =GPIO_Handle_t->GPIO_PinConfig.GPIO_PinMode%4;
SYSCFG_PCLK_EN();
uint8_t code = GPIO_ADDRESS_TO_CODE(GPIO_Handle_t->GPIOx);
SYSCFG->EXTICR[temp1]=code<<(temp2*4);
EXTI->IMR|=(1<<GPIO_Handle_t->GPIO_PinConfig.GPIO_PinNumber);
}
	//speed
temp=(GPIO_Handle_t->GPIO_PinConfig.GPIO_PinMode<<(2*GPIO_Handle_t->GPIO_PinConfig.GPIO_PinNumber));
	GPIO_Handle_t->GPIOx->OSPEEDR&=~(0x3<<(2*GPIO_Handle_t->GPIO_PinConfig.GPIO_PinNumber));
	GPIO_Handle_t->GPIOx->OSPEEDR|=temp;
	//pudg
	temp=(GPIO_Handle_t->GPIO_PinConfig.GPIO_PinMode<<(2*GPIO_Handle_t->GPIO_PinConfig.GPIO_PinNumber));
	GPIO_Handle_t->GPIOx->PUPDR&=~(0x3<<(2*GPIO_Handle_t->GPIO_PinConfig.GPIO_PinNumber));
	GPIO_Handle_t->GPIOx->PUPDR|=temp;
	//
temp=(GPIO_Handle_t->GPIO_PinConfig.GPIO_PinMode<<(2*GPIO_Handle_t->GPIO_PinConfig.GPIO_PinNumber));
	GPIO_Handle_t->GPIOx->OTYPER&=~(0x1<<(2*GPIO_Handle_t->GPIO_PinConfig.GPIO_PinNumber));
	GPIO_Handle_t->GPIOx->OTYPER|=temp;
	/// Config ALT
if(GPIO_Handle_t->GPIO_PinConfig.GPIO_PinMode==GPIO_MODE_ALTFN){
uint8_t temp1,temp2;
	temp1=GPIO_Handle_t->GPIO_PinConfig.GPIO_PinMode/8;
	temp2=GPIO_Handle_t->GPIO_PinConfig.GPIO_PinMode%8;
	GPIO_Handle_t->GPIOx->AFR[temp1]&=~(0xF<<(4*temp2));}}
void GPIO_Denit(GPIO_Regdef_t *GPIOx,uint8_t a){ if(a ==ENABLE){
if(GPIOx==GPIOA) { GPIOA_PCLK_EN();}
else if(GPIOx==GPIOB) { GPIOB_PCLK_DIS();}
else if(GPIOx==GPIOC) { GPIOC_PCLK_DIS();}
else if(GPIOx==GPIOD) { GPIOD_PCLK_DIS();}
else if(GPIOx==GPIOE) { GPIOE_PCLK_DIS();}
else if(GPIOx==GPIOF) { GPIOF_PCLK_DIS();}
else if(GPIOx==GPIOG) { GPIOG_PCLK_DIS();}
else if(GPIOx==GPIOH) { GPIOH_PCLK_DIS();}
else if(GPIOx==GPIOI) { GPIOI_PCLK_DIS();}
else if(GPIOx==GPIOJ) { GPIOJ_PCLK_DIS();}
else if(GPIOx==GPIOK) { GPIOK_PCLK_DIS();}
else{}}}
uint8_t GPIO_ReadInputPin(GPIO_Regdef_t *GPIOx,uint8_t PinNumber){
uint8_t value;
value= (uint8_t)(GPIOx->IDR>>PinNumber)&1U;
	return value;} 
uint16_t GPIO_ReadInputPort(GPIO_Regdef_t *GPIOx){
uint16_t value;
value =(uint16_t)(GPIOx->IDR);
}
void GPIO_Write_OutPutPin(GPIO_Regdef_t *GPIOx, uint8_t PinNumber,uint8_t value){
if(value==GPIO_PIN_SET){ GPIOx->ODR|=(1<<PinNumber);  } else{
	GPIOx->ODR&=~(1<<PinNumber); 
}}
void GPIO_Write_OutPutPort(GPIO_Regdef_t *GPIOx,uint8_t value){
if(value==GPIO_PIN_SET){ GPIOx->ODR |=0xFFFFFFFF;  }
else {GPIOx->ODR &=~0xFFFFFFFF;}
}
void GPIO_Toggle_OutPutPin(GPIO_Regdef_t *GPIOx, uint8_t PinNumber){
GPIOx->ODR  ^=(1<<PinNumber);
}
void GPIO_IRQInterupt_Config(uint8_t IRQNumber,uint8_t EnorDi){
if(EnorDi==ENABLE){
if(IRQNumber <=31){
*NVIC_ISER0 |=(1<<IRQNumber);
}
else if(IRQNumber>31&&IRQNumber<64){
*NVIC_ISER1 |=(1<<(IRQNumber%32)); // 32 to 63
}
else if(IRQNumber>64&&IRQNumber<96){
*NVIC_ISER2 |=(1<<(IRQNumber%64));
} 
}else{
if(IRQNumber <=31){
*NVIC_ICER0 |=(1<<IRQNumber);
}
else if(IRQNumber>31&&IRQNumber<64){
*NVIC_ICER1 |=(1<<(IRQNumber%32)); // 32 to 63
}
else if(IRQNumber>64&&IRQNumber<96){
*NVIC_ICER2 |=(1<<(IRQNumber%64));
} 
}
}
void GPIO_IRQPriority_Config(uint8_t IRQNumber,uint32_t IRQPriority){
uint8_t IPR=IRQNumber/4;
uint8_t IRQ=IRQNumber%4;
*(NVIC_PR_BASE_ADDR+IPR) |= (IRQPriority<< (8*IRQ+4));
}
void GPIO_IRQHandling(uint8_t PinNumber){
if(EXTI->PR&(1<<PinNumber)){
EXTI->PR|=(1<<PinNumber);
}
}
/////////////////SPI
void SPI_PeriClockControl(SPI_Regdef_t *SPIx,uint8_t EnorDi){
if(EnorDi==ENABLE){ if(SPIx==1){SPI1_PCLK_EN();}
else if(SPIx==2){  SPI2_PCLK_EN();                    }
else if(SPIx==3){  SPI3_PCLK_EN();                    }
else if(SPIx==4){  SPI4_PCLK_EN();                    }
}
else {}
}
void SPI_Init(SPI_Handle_t *SPI_Handle){SPI_PeriClockControl(SPI_Handle->SPIx, ENABLE);
uint32_t tempreg=0;
	// Config device
	tempreg |=SPI_Handle->SPI_Config.SPI_DeviceMode<<SPI_CR1_MSTR; 
	if(SPI_Handle->SPI_Config.SPI_BusConfig==SPI_BUS_CONFIG_FD){
tempreg&=~(1<<SPI_CR1_BIDIOE);	 // bidi mode be cleared
	}
else if(SPI_Handle->SPI_Config.SPI_BusConfig==SPI_BUS_CONFIG_HD){
tempreg |=(1<<SPI_CR1_BIDIMODE);// bidi mode be set
}	
else if(SPI_Handle->SPI_Config.SPI_BusConfig==SPI_BUS_CONFIG_SIMPLEX_RXONLY){
tempreg&=~(1<<SPI_CR1_BIDIOE);
	tempreg |=(1<<SPI_CR1_RXONLY);
}
///3 Configure the clock speed
tempreg |=SPI_Handle->SPI_Config.SPI_SclkSpeed<<SPI_CR1_BR;
// Configure the DFF
tempreg |=SPI_Handle->SPI_Config.SPI_DFF<<SPI_CR1_DFF;
// CPOL,CPHA
tempreg |=SPI_Handle->SPI_Config.SPI_CPOL<<SPI_CR1_CPOL;
tempreg |=SPI_Handle->SPI_Config.SPI_CPHA<<SPI_CR1_CPHA;
tempreg |=SPI_Handle->SPI_Config.SPI_SSM<<SPI_CR1_SSM;
SPI_Handle->SPIx->CR1=tempreg;
}
uint8_t SPI_GetFlagStatus(SPI_Regdef_t *SPIx, uint32_t FlagName){
if(SPIx->SR &FlagName){
return FlagName;
}
return FlagName;
}
void SPI_SendData(SPI_Regdef_t *SPIx, uint8_t *pTxBuffer, uint32_t Len){
while(Len >0){
while(SPI_GetFlagStatus(SPIx,(1<<SPI_SR_TXE))==FLAG_PIN_RESET); // wait until TXE is set
if( (  SPIx->CR1&(1<<SPI_CR1_DFF))){
SPIx->DR=*((uint16_t*)pTxBuffer);
	Len--;
	Len--;
	(uint16_t*)pTxBuffer++;}
else{
	SPIx->DR=*pTxBuffer;
	Len--;
	pTxBuffer++;
}
}
}
void SPI_PeripheralControl(SPI_Regdef_t *SPIx, uint8_t EnorDi){
if(EnorDi==1){
SPIx->CR1|=(1<<SPI_CR1_SPE);}
else{ SPIx->CR1&=~(1<<SPI_CR1_SPE);  }
}
void SPI_SSIConfig(SPI_Regdef_t *SPIx, uint8_t EnorDi){
if(EnorDi ==1){ SPIx->CR1|=(1<<SPI_CR1_SSI);  }
	else{ SPIx->CR1 &=~(1<<SPI_CR1_SSI);   }
}


