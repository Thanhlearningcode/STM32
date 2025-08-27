#include "Sensor_Factory.h"
#include "TempSensor.h"
#include <stdlib.h>
// Factory method to create a sensor based on the provided type
Sensor *createSensor(SensorType type)
{
    Sensor *sensor = (Sensor *)malloc(sizeof(Sensor));
    if (sensor == NULL)
    {
        return NULL; // Memory allocation failed
    }

    switch (type)
    {
      case SENSOR_TEMPERATURE:
       *sensor = createTemperatureSensor();
            break;
        case SENSOR_HUMIDITY:
    //        *sensor = createHumiditySensor();
            break;
        case SENSOR_LIGHT:
    //        *sensor = createLightSensor();
            break;
        default:
            free(sensor);
            return NULL; // Invalid sensor type
    }

    return sensor;
}