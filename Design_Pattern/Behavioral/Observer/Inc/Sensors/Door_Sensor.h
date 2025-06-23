#ifndef _DOOR_SENSOR_H_
#define _DOOR_SENSOR_H_

#include "Publisher.h"


typedef struct DoorSensor
{
    Publisher base;
    int isOpen;
} DoorSensor;

void DoorSensor_Init(DoorSensor* sensor);
void DoorSensor_Trigger(DoorSensor* sensor, int open);
#endif /*_DOOR_SENSOR_H_*/