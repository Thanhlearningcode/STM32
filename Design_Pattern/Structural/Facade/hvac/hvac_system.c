#include <stdio.h>
#include <stdlib.h>
#include "hvac_system.h"

static void setTemperature(int temperature) {
    printf("Temperature set to %d°C.\n", temperature);
}

static void setMode(const char* mode) {
    printf("HVAC mode set to %s.\n", mode);
}

// Function to create an HvacSystem instance
HvacSystem* createHvacSystem() {
    HvacSystem* system = (HvacSystem*)malloc(sizeof(HvacSystem));
    system->setTemperature = setTemperature; // Assign setTemperature function
    system->setMode = setMode;               // Assign setMode function
    return system;
}