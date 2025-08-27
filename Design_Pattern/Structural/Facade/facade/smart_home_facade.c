#include <stdio.h>
#include <stdlib.h>
#include "smart_home_facade.h"

// Function to create a SmartHomeFacade instance
SmartHomeFacade* createSmartHomeFacade() {
    SmartHomeFacade* facade = (SmartHomeFacade*)malloc(sizeof(SmartHomeFacade));
    facade->lighting = createLightingSystem();
    facade->security = createSecuritySystem();
    facade->hvac = createHvacSystem();
    return facade;
}

// Function to activate the morning routine
void activateMorningRoutine(SmartHomeFacade* facade) {
    facade->lighting->turnOn();                  // Turn on the lights
    facade->lighting->setBrightness(100);        // Set brightness to 100%
    facade->hvac->setTemperature(22);            // Set temperature to 22°C
    facade->hvac->setMode("Cooling");            // Set HVAC mode to Cooling
    facade->security->deactivateAlarm();         // Deactivate the alarm
    printf("Morning routine activated.\n");
}

// Function to activate away mode
void activateAwayMode(SmartHomeFacade* facade) {
    facade->lighting->turnOff();                 // Turn off the lights
    facade->security->activateAlarm();           // Activate the alarm
    facade->hvac->setTemperature(26);            // Set temperature to 26°C
    facade->hvac->setMode("Eco");                // Set HVAC mode to Eco
    printf("Away mode activated.\n");
}

// Function to set the movie night scene
void setMovieNightScene(SmartHomeFacade* facade) {
    facade->lighting->setBrightness(30);         // Set brightness to 30%
    facade->hvac->setTemperature(21);            // Set temperature to 21°C
    facade->security->deactivateAlarm();         // Deactivate the alarm
    printf("Movie night scene set.\n");
}
