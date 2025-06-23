#include <stdio.h>
#include <stdlib.h>
#include "security_system.h"

static void activateAlarm() {
    printf("Alarm activated.\n");
}

static void deactivateAlarm() {
    printf("Alarm deactivated.\n");
}

static void monitorSensors() {
    printf("Monitoring sensors...\n");
}

SecuritySystem* createSecuritySystem() {
    SecuritySystem* system = (SecuritySystem*)malloc(sizeof(SecuritySystem));
    system->activateAlarm = activateAlarm;      // Assign activateAlarm function
    system->deactivateAlarm = deactivateAlarm;  // Assign deactivateAlarm function
    system->monitorSensors = monitorSensors;    // Assign monitorSensors function
    return system;
}