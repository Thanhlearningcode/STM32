#ifndef _TEMPSENSOR_H_
#define _TEMPSENSOR_H_

#include "Sensor_Factory.h"
void TempSensor_Init(void);

float TempSensor_Read(void);

Sensor createTemperatureSensor();
#endif /*_TEMPSENSOR_H_*/


