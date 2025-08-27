#ifndef _Spi_Software_H_
#define _Spi_Software_H_
#include "stm32f411xe.h"
void Delay(uint32_t time);
void Spi_Transmit_Init(void);
void Spi_Receive_Init(void);
void Spi_Master_Transmit(uint8_t Data);
uint8_t Spi_Slave_Receive(void);
#endif // _Spi_Software_H_