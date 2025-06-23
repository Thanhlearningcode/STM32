#include "Sensors/Door_Sensor.h"
#include "Sensors/Smoke_Sensor.h"
#include "Subscribers/Mobile_App_Notifier.h"
#include "Subscribers/Alarm_System_Controller.h"

#include <stdio.h>

int main (int argc, char const *argv[]) 
{
// Initialize sensors (publishers)
    DoorSensor doorSensor;
    DoorSensor_Init(&doorSensor);

    SmokeSensor smokeSensor;
    SmokeSensor_Init(&smokeSensor);

    // Initialize subscribers
    MobileApp_Notifier mobileApp;
    MobileApp_Notifier_Init(&mobileApp);

    Alarm_System_Controller alarmSystem;
    Alarm_System_Control_Init(&alarmSystem);

    // Register subscribers to door sensor (publisher)
    doorSensor.base.subscribe(&doorSensor.base, (Subscriber*)&mobileApp);
    doorSensor.base.subscribe(&doorSensor.base, (Subscriber*)&alarmSystem);

    // Register subscribers to smoke sensor (publisher)
    smokeSensor.base.subscribe(&smokeSensor.base, (Subscriber*)&mobileApp);
    smokeSensor.base.subscribe(&smokeSensor.base, (Subscriber*)&alarmSystem);

    // Simulate events
    printf("== Simulate Door Open Event ==\n");
    DoorSensor_Trigger(&doorSensor, 1);

    return 0;
}
