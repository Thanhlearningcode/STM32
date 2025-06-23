#include "SensorManager_Singleton.h"
#include "Adc.h"
#include "Uart_Driver.h"
#include <stdlib.h>
#include <stddef.h> 

static SensorManager *instanceSensor = NULL;
SensorManager* SensorManager_GetInstance(void) 
{
    if (instanceSensor == NULL) 
    {
        instanceSensor = (SensorManager*)calloc(1, sizeof(SensorManager));
        if (instanceSensor != NULL) 
        {
            instanceSensor->SensorCout= 1;
            for (int i = 0; i < 10; ++i)
            {
                instanceSensor->AdcValues[i] = 0;
            }
            ADC_Init();
        }
    }
    return instanceSensor;
}

void SensorManager_CollectData(SensorManager* sm) 
{
    if (sm != NULL) 
    {
        for (int i = 0; i < sm->SensorCout; ++i) 
        {
            sm->AdcValues[i] = ADC_ReadChannel(i + 1);
        }

        UART2_Printf("Collecting data from %d sensors...\r\n", sm->SensorCout);
        for (int i = 0; i < sm->SensorCout; ++i)
        {
            UART2_Printf("Sensor[%d] ADC value: %u\r\n", i, sm->AdcValues[i]);
        }
    }
}

void SensorManager_UploadToDatabase(SensorManager* sm)
{
    if (sm != NULL) 
    {
        UART2_SendString("Uploading sensor data to database...\r\n");
    }
}
