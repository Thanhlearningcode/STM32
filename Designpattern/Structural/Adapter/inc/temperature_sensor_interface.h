#ifndef TEMPERATURE_SENSOR_INTERFACE_H
#define TEMPERATURE_SENSOR_INTERFACE_H

#include <stdint.h>
#include <time.h>

// Standardized temperature sensor interface
typedef struct {
    void *instance;
    float (*readTemperature)(void *self);
    const char *(*getName)(void *self);
    const char *(*getUnit)(void *self);
    float (*getMinValue)(void *self);
    float (*getMaxValue)(void *self);
    time_t (*getLastReadTime)(void *self);
} TemperatureSensorInterface;

// Unified function to read temperature (updates lastReadTime)
float temperatureSensorRead(TemperatureSensorInterface *sensor);

#endif // TEMPERATURE_SENSOR_INTERFACE_H
