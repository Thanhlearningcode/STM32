#include "Adc.h"
#include "stm32f4xx.h"

static uint8_t adc_channel;

void Adc_Init(Adc_Config_t config) 
{
    adc_channel = config.channel;

    RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;

    if (adc_channel <= 7)
    {
      GPIOA->MODER |= (3U << (adc_channel * 2));
    }
    else if (adc_channel >= 10 && adc_channel <= 15)
    {
      GPIOC->MODER |= (3U << ((adc_channel - 10) * 2));
    }

    ADC1->CR2 = 0;
    ADC1->SQR3 = adc_channel;

    if (adc_channel <= 9)
    {
       ADC1->SMPR2 |= (config.sampleTime << (3 * adc_channel)); 
    }
        
    else
    {
      ADC1->SMPR1 |= (config.sampleTime << (3 * (adc_channel - 10)));

    }
       
    ADC1->CR2 |= ADC_CR2_ADON;
}

uint16_t Adc_Read(void) 
{
    ADC1->CR2 |= ADC_CR2_SWSTART;
    while (!(ADC1->SR & ADC_SR_EOC));
    return ADC1->DR;
}

float Adc_ReadVoltage(float vref)
{
    return ((float)Adc_Read() * vref) / 4095.0f;
}
