#ifndef HCSR04_H
#define HCSR04_H

#include "stm32f411xe.h"

/* Time in microseconds to centimeters conversion */
#define HCSR04_NUMBER ((float)0.0171821)
#define HCSR04_TIMEOUT 1000000

typedef struct {
    float Distance;
    GPIO_TypeDef* ECHO_GPIOx;
    uint16_t ECHO_GPIO_Pin;
    GPIO_TypeDef* TRIGGER_GPIOx;
    uint16_t TRIGGER_GPIO_Pin;
} HCSR04_t;

uint8_t HCSR04_Init(HCSR04_t* HCSR04, GPIO_TypeDef* ECHO_GPIOx, uint16_t ECHO_GPIO_Pin, GPIO_TypeDef* TRIGGER_GPIOx, uint16_t TRIGGER_GPIO_Pin);
float HCSR04_Read(HCSR04_t* HCSR04);

#endif
