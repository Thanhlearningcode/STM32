#include "temperature_sensor_interface.h"

// Unified temperature reading function
float temperatureSensorRead(TemperatureSensorInterface *sensor) {
    if (sensor && sensor->readTemperature) {
        return sensor->readTemperature(sensor->instance);
    }
    return -1000.0f; // Error value
}