#ifndef _SMOKE_SENSOR_H_
#define _SMOKE_SENSOR_H_

#include "Publisher.h"

typedef struct SmokeSensor
{
    Publisher base;
    int smoke_Detected;

} SmokeSensor;

void SmokeSensor_Init(SmokeSensor* sensor);
void SmokeSensor_Trigger(SmokeSensor* sensor, int detected);


#endif /*__SMOKE_SENSOR_H_*/