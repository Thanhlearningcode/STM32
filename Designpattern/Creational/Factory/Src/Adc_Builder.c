#include "Adc_Builder.h"

static Adc_Builder* setChannel(Adc_Builder* builder, uint8_t channel) 
{
    builder->config.channel = channel;
    return builder;
}

static Adc_Builder* setSampleTime(Adc_Builder* builder, uint8_t sampleTime) 
{
    builder->config.sampleTime = sampleTime;
    return builder;
}

static Adc_Config_t build(Adc_Builder* builder) 
{
    return builder->config;
}

Adc_Builder Adc_Builder_Init(void)
{
    Adc_Builder builder;
    builder.config.channel = ADC_CHANNEL_0;
    builder.config.sampleTime = ADC_SAMPLE_480CYCLES;

    builder.setChannel = setChannel;
    builder.setSampleTime = setSampleTime;
    builder.build = build;

    return builder;
}
