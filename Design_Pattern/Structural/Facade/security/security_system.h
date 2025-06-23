#ifndef SECURITY_SYSTEM_H
#define SECURITY_SYSTEM_H

typedef struct {
    void (*activateAlarm)(void);
    void (*deactivateAlarm)(void);
    void (*monitorSensors)(void);
} SecuritySystem;

SecuritySystem* createSecuritySystem();

#endif // SECURITY_SYSTEM_H