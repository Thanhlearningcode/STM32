#ifndef ADC_H
#define ADC_H

#include <stdint.h>
#include "Adc_Builder.h"

void     Adc_Init(Adc_Config_t config);
uint16_t Adc_Read(void);
float    Adc_ReadVoltage(float vref);

#endif
