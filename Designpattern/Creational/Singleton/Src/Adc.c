#include "Adc.h"
#include "stm32f4xx.h"   

void ADC_Init(void) {
    // Enable clock GPIOA và ADC1
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;

    // Configure PA1 (ADC Channel 1) là analog mode
    GPIOA->MODER |= (3U << (1 * 2));  // MODER1 = 11

    // ADC Common config
    ADC->CCR &= ~(3U << 16);           // Prescaler: PCLK2 / 2

    // ADC1 config
    ADC1->CR1 = 0;
    ADC1->CR2 = ADC_CR2_ADON;          // Enable ADC1

    // Sample time cho channel 1 (PA1)
    ADC1->SMPR2 |= (7U << 3);          // 480 cycles
}

uint16_t ADC_ReadChannel(uint8_t channel) {
    
    ADC1->SQR3 = channel;

    // Start conversation
    ADC1->CR2 |= ADC_CR2_SWSTART;

    // Wait for conversation
    while (!(ADC1->SR & ADC_SR_EOC));

    // return data
    return ADC1->DR;
}
