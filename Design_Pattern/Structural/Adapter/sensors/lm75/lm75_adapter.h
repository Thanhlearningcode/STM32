#ifndef LM75_ADAPTER_H
#define LM75_ADAPTER_H

#include "temperature_sensor_interface.h"
#include "lm75.h"

// Create adapter for LM75
TemperatureSensorInterface lm75CreateAdapter(Lm75 *sensor);

#endif // LM75_ADAPTER_H