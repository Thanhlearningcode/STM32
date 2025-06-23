#ifndef LIGHTING_SYSTEM_H
#define LIGHTING_SYSTEM_H

typedef struct {
    void (*turnOn)(void);
    void (*turnOff)(void);
    void (*setBrightness)(int level);
} LightingSystem;

LightingSystem* createLightingSystem();

#endif // LIGHTING_SYSTEM_H