#include "Sensors/Door_Sensor.h"
#include <stdio.h>


/* Initialize the DoorSensor struct */
void DoorSensor_Init(DoorSensor* sensor)
{
    Publisher_Init(&sensor->base);
    sensor->isOpen=NOT_OK;
}

/* Simulate a door event and notify subscribers */

void DoorSensor_Trigger(DoorSensor* sensor, int open)
{
    sensor->isOpen = open;
    if (open) 
    {
        sensor->base.notify_Subscribers(&sensor->base, "Door is Opened!");
    }
    else
    {
        sensor->base.notify_Subscribers(&sensor->base, "Door is closed!");
    }

}