#ifndef _Can_H_
#define _Can_H_

#include "stm32f10x_can.h"
#include "stm32f10x.h"

void Can_Config();
uint32_t CAN_ReceiveData();
void CAN_Transmitdata(uint8_t *data, uint8_t len, uint32_t id);

#endif // _Can_H_