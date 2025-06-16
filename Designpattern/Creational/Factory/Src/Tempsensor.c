#include "TempSensor.h"
#include "Adc.h"
#include "Adc_Builder.h"

void TempSensor_Init(void)
{
    Adc_Builder builder = Adc_Builder_Init();
    Adc_Config_t config = builder
        .setChannel(&builder, ADC_CHANNEL_5)
        ->setSampleTime(&builder, ADC_SAMPLE_480CYCLES)
        ->build(&builder);

    Adc_Init(config);
}

float TempSensor_Read(void)
{
    float voltage = Adc_ReadVoltage(3.3f);
    return (voltage - 0.5f) * 100.0f; // LM35
}

Sensor createTemperatureSensor()
{
    Sensor TempSensor;
    TempSensor.init = TempSensor_Init;
    TempSensor.readData = TempSensor_Read;
    return TempSensor;
}
