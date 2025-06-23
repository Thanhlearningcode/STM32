#include <stdio.h>
#include <stdlib.h>
#include "lighting_system.h"

static void turnOn() {
    printf("Lights turned on.\n");
}

static void turnOff() {
    printf("Lights turned off.\n");
}

static void setBrightness(int level) {
    printf("Brightness set to %d%%.\n", level);
}

// Function to create a LightingSystem instance
LightingSystem* createLightingSystem() {
    LightingSystem* system = (LightingSystem*)malloc(sizeof(LightingSystem));
    system->turnOn = turnOn;                // Assign turnOn function
    system->turnOff = turnOff;              // Assign turnOff function
    system->setBrightness = setBrightness;  // Assign setBrightness function
    return system;
}
