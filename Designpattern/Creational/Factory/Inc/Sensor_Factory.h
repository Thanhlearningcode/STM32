#ifndef _SENSOR_FACTORY_H_
#define _SENSOR_FACTORY_H_

#include "Sensor.h"

// Enum to represent sensor types
typedef enum
{
    SENSOR_TEMPERATURE,
    SENSOR_HUMIDITY,
    SENSOR_LIGHT
} SensorType;

// Factory method to create sensors based on their type
Sensor *createSensor(SensorType type);
#endif /*_SENSOR_FACTORY_H_*/