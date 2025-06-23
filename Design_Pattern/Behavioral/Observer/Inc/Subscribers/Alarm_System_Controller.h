#ifndef _ALARM_SYSTEM_CONTROLLER_H_
#define _ALARM_SYSTEM_CONTROLLER_H_

#include "Subscriber.h" 

typedef struct 
{
    Subscriber base;
} Alarm_System_Controller ;


void Alarm_System_Control_Init(Alarm_System_Controller* alarm); 
#endif /* _ALARM_SYSTEM_CONTROLLER_H_ */