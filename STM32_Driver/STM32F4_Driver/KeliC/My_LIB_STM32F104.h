#include "LIB.h"
typedef struct{
uint8_t GPIO_PinNumber;
uint8_t GPIO_PinMode;
uint8_t GPIO_PinSpeed;
uint8_t GPIO_PinPuDdcontrol;
uint8_t GPIO_PinOPType;
uint8_t GPIO_PinAltFunMode;
}GPIO_PinConig_t;
typedef struct{
GPIO_Regdef_t *GPIOx;
	GPIO_PinConig_t GPIO_PinConfig;
}GPIO_Handle;
#define ENABLE 1
#define DISABLE 0
#define SET ENABLE
#define RESET DISABLE
#define GPIO_PIN_SET SET
#define GPIO_PIN_RESET RESET
#define FLAG_PIN_SET SET
#define FLAG_PIN_RESET RESET
#define GPIO_PIN_0 0
#define GPIO_PIN_1 1
#define GPIO_PIN_3 3
#define GPIO_PIN_2 2
#define GPIO_PIN_4 4
#define GPIO_PIN_5 5
#define GPIO_PIN_6 6
#define GPIO_PIN_7 7
#define GPIO_PIN_8 8
#define GPIO_PIN_9 9
#define GPIO_PIN_10 10
#define GPIO_PIN_11 11
#define GPIO_PIN_12 12
#define GPIO_PIN_13 13
#define GPIO_PIN_14 14
#define GPIO_PIN_15 15
#define GPIO_MODE_IN 0
#define GPIO_MODE_OUT 1
#define GPIO_MODE_ALTFN 2
#define GPIO_MODE_ANALOG 3
#define GPIO_MODE_IN 0
#define GPIO_MODE_IT_FALLING 4
#define GPIO_MODE_IT_RAISING 5
#define GPIO_MODE_IT_FaR 6
#define GPIO_OP_TYPE_PP 0
#define GPIO_OP_TYPE_OD  // Open-Drain

#define GPIO_SPEED_LOW 0
#define GPIO_SPEED_MEDIUM 1
#define GPIO_SPEED_HIGH 2
#define GPIO_SPEED_SuperHIGH 3
#define GPIO_NO_PUPD 0
#define GPIO_PIN_PU 1
#define GPIO_PIN_PD 2

#define GPIOA_PIN_RESET do { (RCC->AHB1ENR|=(1<<0)); (RCC->AHB1ENR&=~(1<<0));} while(0)
#define GPIOB_PIN_RESET do { (RCC->AHB1ENR|=(1<<1)); (RCC->AHB1ENR&=~(1<<1));} while(0)
#define GPIOC_PIN_RESET do { (RCC->AHB1ENR|=(1<<2)); (RCC->AHB1ENR&=~(1<<2));} while(0)
#define GPIOD_PIN_RESET do { (RCC->AHB1ENR|=(1<<3)); (RCC->AHB1ENR&=~(1<<3));} while(0)
#define GPIOE_PIN_RESET do { (RCC->AHB1ENR|=(1<<4)); (RCC->AHB1ENR&=~(1<<4));} while(0)
#define GPIOF_PIN_RESET do { (RCC->AHB1ENR|=(1<<5)); (RCC->AHB1ENR&=~(1<<5));} while(0)
#define GPIOG_PIN_RESET do { (RCC->AHB1ENR|=(1<<6)); (RCC->AHB1ENR&=~(1<<6));} while(0)
#define GPIOH_PIN_RESET do { (RCC->AHB1ENR|=(1<<7)); (RCC->AHB1ENR&=~(1<<7));} while(0)
#define GPIOI_PIN_RESET do { (RCC->AHB1ENR|=(1<<8)); (RCC->AHB1ENR&=~(1<<8));} while(0)
#define GPIOJ_PIN_RESET do { (RCC->AHB1ENR|=(1<<9)); (RCC->AHB1ENR&=~(1<<9));} while(0)
#define GPIOK_PIN_RESET do { (RCC->AHB1ENR|=(1<<10)); (RCC->AHB1ENR&=~(1<<10));} while(0)
#define IRQ_NO_EXTI0 6
#define IRQ_NO_EXTI1 7
#define IRQ_NO_EXTI2 8
#define IRQ_NO_EXTI3 9
#define IRQ_NO_EXTI4 10
#define IRQ_NO_EXTI9_5 23
#define IRQ_NO_EXTI15_10 40
void GPIO_PeriClockControl(GPIO_Regdef_t *GPIOx,uint8_t Enordi);
void GPIO_Init(GPIO_Handle *GPIO_Handle_t);
void GPIO_Denit(GPIO_Regdef_t *GPIOx,uint8_t a);
uint8_t GPIO_ReadInputPin(GPIO_Regdef_t *GPIOx,uint8_t PinNumber);
uint16_t GPIO_ReadInputPort(GPIO_Regdef_t *GPIOx);
void GPIO_Write_OutPutPin(GPIO_Regdef_t *GPIOx, uint8_t PinNumber,uint8_t value);
void GPIO_Write_OutPutPort(GPIO_Regdef_t *GPIOx,uint8_t value);
void GPIO_Toggle_OutPutPin(GPIO_Regdef_t *GPIOx, uint8_t PinNumber);

void GPIO_IRQInterupt_Config(uint8_t IRQNumber,uint8_t EnorDi);
void GPIO_IRQPriority_Config(uint8_t IRQNumber,uint32_t IRQPriority);
void GPIO_IRQHandling(uint8_t PinNumber);
///////////////////////////////SPI
typedef struct{
uint8_t SPI_DeviceMode;
uint8_t SPI_BusConfig;
uint8_t SPI_SclkSpeed;
uint8_t SPI_DFF;
uint8_t SPI_CPOL;
uint8_t SPI_CPHA;
uint8_t SPI_SSM;
}SPI_Config_t;
typedef struct {
    SPI_Regdef_t *SPIx;
    SPI_Config_t SPI_Config;
} SPI_Handle_t;

#define SPI_DEVICE_MODE_MASTER 1
#define SPI_DEVICE_MODE_SLAVE 0
#define SPI_BUS_CONFIG_FD 1
#define SPI_BUS_CONFIG_HD 2
#define SPI_BUS_CONFIG_SIMPLEX_RXONLY 3
#define SPI_SLCK_SPEED_DIV2 0
#define SPI_SLCK_SPEED_DIV4 1
#define SPI_SLCK_SPEED_DIV8 2
#define SPI_SLCK_SPEED_DIV16 3
#define SPI_SLCK_SPEED_DIV32 4
#define SPI_SLCK_SPEED_DIV64 5
#define SPI_SLCK_SPEED_DIV128 6
#define SPI_SLCK_SPEED_DIV256 7

#define SPI_DFF_8Bits 0
#define SPI_DFF_16Bits 1
#define SPI_CPOL_HIGH 1
#define SPI_CPOL_LOW 0
#define SPI_CPHA_HIGH 1
#define SPI_CPHA_LOW 0
#define SPI_SSM_EN 1
#define SPI_SSM_DIS 0
void SPI_PeriClockControl(SPI_Regdef_t *SPIx, uint8_t EnorDi);
void SPI_Init(SPI_Handle_t *SPI_Handle);
void SPI_DeInit(SPI_Regdef_t *SPIx);
void SPI_SendData(SPI_Regdef_t *SPIx, uint8_t *pTxBuffer, uint32_t Len);
void SPI_ReceiveData(SPI_Regdef_t *SPIx, uint8_t *pRxBuffer, uint32_t Len);
uint8_t SPI_SendDataIT(SPI_Handle_t *pSPIHandle, uint8_t *pTxBuffer, uint32_t Len);
uint8_t SPI_ReceiveDataIT(SPI_Handle_t *pSPIHandle, uint8_t *pRxBuffer, uint32_t Len);
void SPI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);
void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);
void SPI_IRQHandling(SPI_Handle_t *pHandle);
void SPI_PeripheralControl(SPI_Regdef_t *SPIx, uint8_t EnorDi);
void SPI_SSIConfig(SPI_Regdef_t *SPIx, uint8_t EnorDi);
void SPI_SSOEConfig(SPI_Regdef_t *SPIx, uint8_t EnorDi);
uint8_t SPI_GetFlagStatus(SPI_Regdef_t *SPIx, uint32_t FlagName);
void SPI_ClearOVRFlag(SPI_Regdef_t *SPIx);
void SPI_CloseTransmission(SPI_Handle_t *pSPIHandle);
void SPI_CloseReception(SPI_Handle_t *pSPIHandle);
uint8_t I2C_DeviceMode(I2C_Regdef_t *I2cx);