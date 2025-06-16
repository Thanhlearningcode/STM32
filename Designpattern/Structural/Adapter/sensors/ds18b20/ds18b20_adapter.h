#ifndef DS18B20_ADAPTER_H
#define DS18B20_ADAPTER_H

#include "temperature_sensor_interface.h"
#include "ds18b20.h"

// Create adapter for DS18B20
TemperatureSensorInterface ds18b20CreateAdapter(Ds18b20 *sensor);

#endif // DS18B20_ADAPTER_H