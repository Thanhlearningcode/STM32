#include "Sensors/Smoke_Sensor.h"
#include <stdio.h>


void SmokeSensor_Init(SmokeSensor* sensor)
{
    Publisher_Init(&sensor->base);
    sensor->smoke_Detected = NOT_OK;
}

/* Mô phỏng phát hiện khói và gửi thông báo */
void SmokeSensor_Detect(SmokeSensor* sensor, int detected)
{
    sensor->smoke_Detected = detected;
    if (detected)
    {
        sensor->base.notify_Subscribers(&sensor->base, "Smoke is Detected");
    }
    else
    {
        sensor->base.notify_Subscribers(&sensor->base, "No smoking");
    }
}
