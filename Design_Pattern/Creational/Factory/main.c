#include <stdio.h>
#include <stdlib.h>
//#include "sensor-factory/sensor-factory.h"
#include "Sensor_Factory.h"
int main() {
   // Create a temperature sensor
    Sensor* tempSensor = createSensor(SENSOR_TEMPERATURE);
    // if (tempSensor != NULL) {
    //     tempSensor->init();
    //     printf("Temperature: %.2f°C\n", tempSensor->readData());
    //     free(tempSensor);
    // }


    return 0;
}