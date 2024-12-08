#ifndef _LIB_STM32F4_H
#define _LIB_sTM32f4_H
#include "stdint.h"

#define __IO volatile
#define NVIC_ISER0 ((__IO uint32_t*)0xE000E100)
#define NVIC_ISER1 ((__IO uint32_t*)0xE000E104)
#define NVIC_ISER2 ((__IO uint32_t*)0xE000E108)
#define NVIC_ISER3 ((__IO uint32_t*)0xE000E10C)

#define NVIC_ICER0 ((__IO uint32_t*)0xE000E180)
#define NVIC_ICER1 ((__IO uint32_t*)0xE000E184)
#define NVIC_ICER2 ((__IO uint32_t*)0xE000E188)
#define NVIC_ICER3 ((__IO uint32_t*)0xE000E18C)
/// Priority NVIC
#define NVIC_PR_BASE_ADDR ((__IO uint32_t*)0xE000E400)

#define	 FLASH_BASEADDR 0x08000000U
#define SRAM1_BASEADDR 0x20000000U
#define SRAM2_BASEADDR 0x2001C000U
#define ROM_BASEADDR 0x1FFF0000U
#define SRAM SRAM1_BASEADDR 
// PERIPERALS 67
#define PERIPH_BASE 0x40000000U
#define APB1PERIPH_BASEADDR PERIPH_BASE 
#define APB2PERIPH_BASEADDR 0x40010000U
#define AHB1PERIPH_BASEADDR 0x40020000U
#define AHB2PERIPH_BASEADDR 0x50000000U
//GPIO
#define GPIOA_BASEADDR ( AHB1PERIPH_BASEADDR+ 0u)
#define GPIOB_BASEADDR (AHB1PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR (AHB1PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR (AHB1PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR (AHB1PERIPH_BASEADDR + 0x1000)
#define GPIOF_BASEADDR (AHB1PERIPH_BASEADDR + 0x1400)
#define GPIOG_BASEADDR (AHB1PERIPH_BASEADDR + 0x1800)
#define GPIOH_BASEADDR (AHB1PERIPH_BASEADDR + 0x1C00)
#define GPIOI_BASEADDR (AHB1PERIPH_BASEADDR + 0x2000)
#define GPIOJ_BASEADDR (AHB1PERIPH_BASEADDR + 0x2400)
#define GPIOK_BASEADDR (AHB1PERIPH_BASEADDR + 0x2800)
#define CRC_BASEADDR   (AHB1PERIPH_BASEADDR + 0x3000)
#define RCC_BASEADDR   (AHB1PERIPH_BASEADDR + 0x3800)

#define TIM2_BASEADDR  0x40000000U
#define TIM3_BASEADDR  0x40000400U
#define TIM4_BASEADDR  0x40000800U
#define TIM5_BASEADDR  0x40000C00U
#define TIM6_BASEADDR  0x40001000U
#define TIM7_BASEADDR  0x40001400U
#define TIM12_BASEADDR 0x40001800U
#define TIM13_BASEADDR 0x40001C00U
#define TIM14_BASEADDR 0x40002000U
#define RTC_BASEADDR   0x40002800U
#define WWDG_BASEADDR  0x40002C00U
#define IWDG_BASEADDR  0x40003000U
#define I2S_BASEADDR   0x40003400U
#define SPI2_BASEADDR  0x40003800U
#define SPI3_BASEADDR  0x40003C00U
#define I2S3_BASEADDR  0x40004000U
#define UART2_BASEADDR 0x40004400U
#define UART3_BASEADDR 0x40004800U
#define UART4_BASEADDR 0x40004C00U
#define UART5_BASEADDR 0x40005000U
#define I2C1_BASEADDR  0x40005400U
#define I2C2_BASEADDR  0x40005800U
#define I2C3_BASEADDR  0x40005C00U
#define CAN1_BASEADDR  0x40006400U
#define CAN2_BASEADDR  0x40006800U
#define PWR_BASEADDR   0x40007000U
#define DAC_BASEADDR   0x40007400U
#define SPI1_BASEADDR  0x40013000U
#define EXTI_BASEADDR  0x40013C00U
#define SYSCFG_BASEADDR 0x40013800U
#define UART1_BASEADDR 0x40011000U
#define UART6_BASEADDR 0x40014000U

typedef struct{
uint32_t MODER;
uint32_t  OTYPER;
volatile uint32_t   OSPEEDR;
volatile uint32_t   PUPDR;
volatile uint32_t   IDR;
volatile uint32_t   ODR;
volatile uint32_t 	BSRR;
volatile uint32_t 	LCKR;
volatile uint32_t 	AFR[2];

}GPIO_Regdef_t;

#define GPIOA ((GPIO_Regdef_t*)GPIOA_BASEADDR)
#define GPIOB ((GPIO_Regdef_t*)GPIOB_BASEADDR)
#define GPIOC ((GPIO_Regdef_t*)GPIOC_BASEADDR)
#define GPIOD ((GPIO_Regdef_t*)GPIOD_BASEADDR)
#define GPIOE ((GPIO_Regdef_t*)GPIOE_BASEADDR)
#define GPIOF ((GPIO_Regdef_t*)GPIOF_BASEADDR)
#define GPIOG ((GPIO_Regdef_t*)GPIOG_BASEADDR)
#define GPIOH ((GPIO_Regdef_t*)GPIOH_BASEADDR)
#define GPIOI ((GPIO_Regdef_t*)GPIOI_BASEADDR)
#define GPIOJ ((GPIO_Regdef_t*)GPIOJ_BASEADDR)
#define GPIOK ((GPIO_Regdef_t*)GPIOK_BASEADDR)
#define GPIO_ADDRESS_TO_CODE(x) ( (x==GPIOA)?0: (x==GPIOB)?1: (x==GPIOC)?2: (x==GPIOD)?3: (x==GPIOE)?4: (x==GPIOF)?5: (x==GPIOG)?6: (x==GPIOH)?7: (x==GPIOI)?8: (x==GPIOJ)?9: (x==GPIOK)?10:0)
typedef struct
{
  __IO uint32_t CR;            /*!< RCC clock control register,                                  Address offset: 0x00 */
  __IO uint32_t PLLCFGR;       /*!< RCC PLL configuration register,                              Address offset: 0x04 */
  __IO uint32_t CFGR;          /*!< RCC clock configuration register,                            Address offset: 0x08 */
  __IO uint32_t CIR;           /*!< RCC clock interrupt register,                                Address offset: 0x0C */
  __IO uint32_t AHB1RSTR;      /*!< RCC AHB1 peripheral reset register,                          Address offset: 0x10 */
  __IO uint32_t AHB2RSTR;      /*!< RCC AHB2 peripheral reset register,                          Address offset: 0x14 */
  __IO uint32_t AHB3RSTR;      /*!< RCC AHB3 peripheral reset register,                          Address offset: 0x18 */
  uint32_t      RESERVED0;     /*!< Reserved, 0x1C                                                                    */
  __IO uint32_t APB1RSTR;      /*!< RCC APB1 peripheral reset register,                          Address offset: 0x20 */
  __IO uint32_t APB2RSTR;      /*!< RCC APB2 peripheral reset register,                          Address offset: 0x24 */
  uint32_t      RESERVED1[2];  /*!< Reserved, 0x28-0x2C                                                               */
  __IO uint32_t AHB1ENR;       /*!< RCC AHB1 peripheral clock register,                          Address offset: 0x30 */
  __IO uint32_t AHB2ENR;       /*!< RCC AHB2 peripheral clock register,                          Address offset: 0x34 */
  __IO uint32_t AHB3ENR;       /*!< RCC AHB3 peripheral clock register,                          Address offset: 0x38 */
  uint32_t      RESERVED2;     /*!< Reserved, 0x3C                                                                    */
  __IO uint32_t APB1ENR;       /*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x40 */
  __IO uint32_t APB2ENR;       /*!< RCC APB2 peripheral clock enable register,                   Address offset: 0x44 */
  uint32_t      RESERVED3[2];  /*!< Reserved, 0x48-0x4C                                                               */
  __IO uint32_t AHB1LPENR;     /*!< RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50 */
  __IO uint32_t AHB2LPENR;     /*!< RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54 */
  __IO uint32_t AHB3LPENR;     /*!< RCC AHB3 peripheral clock enable in low power mode register, Address offset: 0x58 */
  uint32_t      RESERVED4;     /*!< Reserved, 0x5C                                                                    */
  __IO uint32_t APB1LPENR;     /*!< RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60 */
  __IO uint32_t APB2LPENR;     /*!< RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64 */
  uint32_t      RESERVED5[2];  /*!< Reserved, 0x68-0x6C                                                               */
  __IO uint32_t BDCR;          /*!< RCC Backup domain control register,                          Address offset: 0x70 */
  __IO uint32_t CSR;           /*!< RCC clock control & status register,                         Address offset: 0x74 */
  uint32_t      RESERVED6[2];  /*!< Reserved, 0x78-0x7C                                                               */
  __IO uint32_t SSCGR;         /*!< RCC spread spectrum clock generation register,               Address offset: 0x80 */
  __IO uint32_t PLLI2SCFGR;    /*!< RCC PLLI2S configuration register,                           Address offset: 0x84 */
} Regdef_t;

#define RCC ((Regdef_t*)RCC_BASEADDR )
typedef struct
{
  __IO uint32_t IMR;    /*!< EXTI Interrupt mask register,            Address offset: 0x00 */
  __IO uint32_t EMR;    /*!< EXTI Event mask register,                Address offset: 0x04 */
  __IO uint32_t RTSR;   /*!< EXTI Rising trigger selection register,  Address offset: 0x08 */
  __IO uint32_t FTSR;   /*!< EXTI Falling trigger selection register, Address offset: 0x0C */
  __IO uint32_t SWIER;  /*!< EXTI Software interrupt event register,  Address offset: 0x10 */
  __IO uint32_t PR;     /*!< EXTI Pending register,                   Address offset: 0x14 */
} EXTI_Regdef_t;
#define EXTI ((EXTI_Regdef_t*)EXTI_BASEADDR )

typedef struct
{
  __IO uint32_t CR1;        /*!< SPI control register 1 (not used in I2S mode),      Address offset: 0x00 */
  __IO uint32_t CR2;        /*!< SPI control register 2,                             Address offset: 0x04 */
  __IO uint32_t SR;         /*!< SPI status register,                                Address offset: 0x08 */
  __IO uint32_t DR;         /*!< SPI data register,                                  Address offset: 0x0C */
  __IO uint32_t CRCPR;      /*!< SPI CRC polynomial register (not used in I2S mode), Address offset: 0x10 */
  __IO uint32_t RXCRCR;     /*!< SPI RX CRC register (not used in I2S mode),         Address offset: 0x14 */
  __IO uint32_t TXCRCR;     /*!< SPI TX CRC register (not used in I2S mode),         Address offset: 0x18 */
  __IO uint32_t I2SCFGR;    /*!< SPI_I2S configuration register,                     Address offset: 0x1C */
  __IO uint32_t I2SPR;      /*!< SPI_I2S prescaler register,                         Address offset: 0x20 */
} SPI_Regdef_t;
#define SPI2_BASEADDR 0x40003800U
#define SPI1 ((SPI_Regdef_t*)SPI1_BASEADDR)
#define SPI2 ((SPI_Regdef_t*)SPI2_BASEADDR)
#define SPI3 ((SPI_Regdef_t*)SPI3_BASEADDR)

typedef struct
{
  __IO uint32_t MEMRMP;       /*!< SYSCFG memory remap register,                      Address offset: 0x00      */
  __IO uint32_t PMC;          /*!< SYSCFG peripheral mode configuration register,     Address offset: 0x04      */
  __IO uint32_t EXTICR[4];    /*!< SYSCFG external interrupt configuration registers, Address offset: 0x08-0x14 */
  uint32_t      RESERVED[2];  /*!< Reserved, 0x18-0x1C                                                          */
  __IO uint32_t CMPCR;        /*!< SYSCFG Compensation cell control register,         Address offset: 0x20      */
} SYSCFG_Regdef_t;
#define SYSCFG ((SYSCFG_Regdef_t*)SYSCFG_BASEADDR)


typedef struct
{
  __IO uint32_t CR1;        /*!< I2C Control register 1,     Address offset: 0x00 */
  __IO uint32_t CR2;        /*!< I2C Control register 2,     Address offset: 0x04 */
  __IO uint32_t OAR1;       /*!< I2C Own address register 1, Address offset: 0x08 */
  __IO uint32_t OAR2;       /*!< I2C Own address register 2, Address offset: 0x0C */
  __IO uint32_t DR;         /*!< I2C Data register,          Address offset: 0x10 */
  __IO uint32_t SR1;        /*!< I2C Status register 1,      Address offset: 0x14 */
  __IO uint32_t SR2;        /*!< I2C Status register 2,      Address offset: 0x18 */
  __IO uint32_t CCR;        /*!< I2C Clock control register, Address offset: 0x1C */
  __IO uint32_t TRISE;      /*!< I2C TRISE register,         Address offset: 0x20 */
} I2C_Regdef_t;
#define I2C1 ((Regdef_t*) I2C_BASEADDR)
///////// GPIO
#define GPIOA_PCLK_EN() (RCC->AHB1ENR|=(1<<0))
#define GPIOB_PCLK_EN() (RCC->AHB1ENR|=(1<<1))
#define GPIOC_PCLK_EN() (RCC->AHB1ENR|=(1<<2))
#define GPIOD_PCLK_EN() (RCC->AHB1ENR|=(1<<3))
#define GPIOE_PCLK_EN() (RCC->AHB1ENR|=(1<<4))
#define GPIOF_PCLK_EN() (RCC->AHB1ENR|=(1<<5))
#define GPIOG_PCLK_EN() (RCC->AHB1ENR|=(1<<6))
#define GPIOH_PCLK_EN() (RCC->AHB1ENR|=(1<<7))
#define GPIOI_PCLK_EN() (RCC->AHB1ENR|=(1<<8))
#define GPIOJ_PCLK_EN() (RCC->AHB1ENR|=(1<<9))
#define GPIOK_PCLK_EN() (RCC->AHB1ENR|=(1<<10))
/////////// SPI
#define SPI1_PCLK_EN() (RCC->APB2ENR|=(1<<12))
#define SPI4_PCLK_EN() (RCC->APB1ENR|=(1<<13))
#define SPI2_PCLK_EN() (RCC->APB1ENR|=(1<<14))
#define SPI3_PCLK_EN() (RCC->APB1ENR|=(1<<15))
///////// I2C
#define I2C1_PCLK_EN() (RCC->APB1ENR|=(1<<21))
#define I2C2_PCLK_EN() (RCC->APB1ENR|=(1<<22))
#define I2C3_PCLK_EN() (RCC->APB1ENR|=(1<<23))
/////////UART
#define UART1_PCLK_EN() (RCC->APB2ENR|=(1<<4))
#define UART2_PCLK_EN() (RCC->APB1ENR|=(1<<17))
#define UART3_PCLK_EN() (RCC->APB1ENR|=(1<<18))
#define UART4_PCLK_EN() (RCC->APB1ENR|=(1<<19))
#define UART5_PCLK_EN() (RCC->APB1ENR|=(1<<20))
#define UART6_PCLK_EN() (RCC->APB1ENR|=(1<<5))
///
#define SYSCFG_PCLK_EN() (RCC->APB2ENR|=(1<<14))

// Macros to disable UART peripheral clocks
#define UART1_PCLK_DIS() (RCC->APB2ENR &= ~(1 << 4))
#define UART2_PCLK_DIS() (RCC->APB1ENR &= ~(1 << 17))
#define UART3_PCLK_DIS() (RCC->APB1ENR &= ~(1 << 18))
#define UART4_PCLK_DIS() (RCC->APB1ENR &= ~(1 << 19))
#define UART5_PCLK_DIS() (RCC->APB1ENR &= ~(1 << 20))
#define UART6_PCLK_DIS() (RCC->APB2ENR &= ~(1 << 5))

// Macros to disable GPIO peripheral clocks
#define GPIOA_PCLK_DIS() (RCC->AHB1ENR &= ~(1 << 0))
#define GPIOB_PCLK_DIS() (RCC->AHB1ENR &= ~(1 << 1))
#define GPIOC_PCLK_DIS() (RCC->AHB1ENR &= ~(1 << 2))
#define GPIOD_PCLK_DIS() (RCC->AHB1ENR &= ~(1 << 3))
#define GPIOE_PCLK_DIS() (RCC->AHB1ENR &= ~(1 << 4))
#define GPIOF_PCLK_DIS() (RCC->AHB1ENR &= ~(1 << 5))
#define GPIOG_PCLK_DIS() (RCC->AHB1ENR &= ~(1 << 6))
#define GPIOH_PCLK_DIS() (RCC->AHB1ENR &= ~(1 << 7))
#define GPIOI_PCLK_DIS() (RCC->AHB1ENR &= ~(1 << 8))
#define GPIOJ_PCLK_DIS() (RCC->AHB1ENR &= ~(1 << 9))
#define GPIOK_PCLK_DIS() (RCC->AHB1ENR &= ~(1 << 10))
// Macros to disable SPI peripheral clocks
#define SPI1_PCLK_DIS() (RCC->APB2ENR &= ~(1 << 12))
#define SPI2_PCLK_DIS() (RCC->APB1ENR &= ~(1 << 14))
#define SPI3_PCLK_DIS() (RCC->APB1ENR &= ~(1 << 15))
#define SPI4_PCLK_DIS() (RCC->APB2ENR &= ~(1 << 13))

// Macros to disable UART peripheral clocks
#define UART1_PCLK_DIS() (RCC->APB2ENR &= ~(1 << 4))
#define UART2_PCLK_DIS() (RCC->APB1ENR &= ~(1 << 17))
#define UART3_PCLK_DIS() (RCC->APB1ENR &= ~(1 << 18))
#define UART4_PCLK_DIS() (RCC->APB1ENR &= ~(1 << 19))
#define UART5_PCLK_DIS() (RCC->APB1ENR &= ~(1 << 20))
#define UART6_PCLK_DIS() (RCC->APB2ENR &= ~(1 << 5))
// Macros to disable I2C peripheral clocks
#define I2C1_PCLK_DIS() (RCC->APB1ENR &= ~(1 << 21))
#define I2C2_PCLK_DIS() (RCC->APB1ENR &= ~(1 << 22))
#define I2C3_PCLK_DIS() (RCC->APB1ENR &= ~(1 << 23))
#define SYSCFG_PCLK_DIS() (RCC->APB2ENR&=~(1<<14))
///SPI1
#define SPI_CR1_CPHA 0
#define SPI_CR1_CPOL 1
#define SPI_CR1_MSTR 2  
#define SPI_CR1_BR   3
#define SPI_CR1_SPE 6
#define SPI_CR1_LSBFIRST 7
#define SPI_CR1_SSI  8
#define SPI_CR1_SSM 9
#define SPI_CR1_RXONLY 10
#define SPI_CR1_DFF 11 
#define SPI_CR1_CRCNEXT 12
#define SPI_CR1_CRCEN 13
#define SPI_CR1_BIDIOE 14
#define SPI_CR1_BIDIMODE 15
//SPI2
#define SPI_CR2_RXDMAEN 0
#define SPI_CR2_TXDMAEN 1
#define SPI_CR2_SSOE 2
#define SPI_CR2_FRF 4
#define SPI_CR2_ERRIE 5
#define SPI_CR2_RXNEIE 6
#define SPI_CR2_TXEIE 7
//SPI SR
#define SPI_SR_RXNE 0
#define SPI_SR_TXE  1
#define SPI_SR_CHSIDE  2 
#define SPI_SR_UDR 3
#define SPI_SR_CRCERR 4 
#define SPI_SR_MODF 5
#define SPI_SR_OVR 6
#define SPI_SR_BSY  7
#define SPI_SR_FRE 8
#endif