#include "Subscribers/Alarm_System_Controller.h"
#include "stdio.h"

/* Update method for AlarmSystemController */
void Alarm_System_Update(Subscriber* self, Publisher* context, const char* eventInfo)
{
    (void)self;
    (void)context;
   printf("[AlarmSystem] Alarm: %s\n", eventInfo);
}

void Alarm_System_Controller_Init(Alarm_System_Controller* controller)
{
    controller->base.update = Alarm_System_Update;
    controller->base.data   = NULL;
}