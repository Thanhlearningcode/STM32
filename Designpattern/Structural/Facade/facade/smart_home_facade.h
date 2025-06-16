#ifndef SMART_HOME_FACADE_H
#define SMART_HOME_FACADE_H

#include "../lighting/lighting_system.h"
#include "../security/security_system.h"
#include "../hvac/hvac_system.h"

typedef struct {
    LightingSystem* lighting;  // Pointer to the lighting system
    SecuritySystem* security;  // Pointer to the security system
    HvacSystem* hvac;          // Pointer to the HVAC system
} SmartHomeFacade;

SmartHomeFacade* createSmartHomeFacade();
void activateMorningRoutine(SmartHomeFacade* facade);
void activateAwayMode(SmartHomeFacade* facade);
void setMovieNightScene(SmartHomeFacade* facade);

#endif // SMART_HOME_FACADE_H