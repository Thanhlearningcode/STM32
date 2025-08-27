#ifndef ADC_BUILDER_H
#define ADC_BUILDER_H

#include <stdint.h>

typedef enum 
{
    ADC_CHANNEL_0  = 0,
    ADC_CHANNEL_1  = 1,
    ADC_CHANNEL_2  = 2,
    ADC_CHANNEL_3  = 3,
    ADC_CHANNEL_4  = 4,
    ADC_CHANNEL_5  = 5,
    ADC_CHANNEL_6  = 6,
    ADC_CHANNEL_7  = 7,
    ADC_CHANNEL_8  = 8,
    ADC_CHANNEL_9  = 9,
    ADC_CHANNEL_10 = 10,
    ADC_CHANNEL_11 = 11,
    ADC_CHANNEL_12 = 12,
    ADC_CHANNEL_13 = 13,
    ADC_CHANNEL_14 = 14,
    ADC_CHANNEL_15 = 15
} ADC_Channel_t;

typedef enum
{
    ADC_SAMPLE_3CYCLES   = 0,
    ADC_SAMPLE_15CYCLES  = 1,
    ADC_SAMPLE_28CYCLES  = 2,
    ADC_SAMPLE_56CYCLES  = 3,
    ADC_SAMPLE_84CYCLES  = 4,
    ADC_SAMPLE_112CYCLES = 5,
    ADC_SAMPLE_144CYCLES = 6,
    ADC_SAMPLE_480CYCLES = 7
} ADC_SampleTime_t;

typedef struct {
    uint8_t channel;
    uint8_t sampleTime;
} Adc_Config_t;

typedef struct Adc_Builder 
{
    Adc_Config_t config;

    struct Adc_Builder* (*setChannel)   (struct Adc_Builder*, uint8_t);
    struct Adc_Builder* (*setSampleTime)(struct Adc_Builder*, uint8_t);

    Adc_Config_t (*build)(struct Adc_Builder*);
} Adc_Builder;

Adc_Builder Adc_Builder_Init(void);

#endif
