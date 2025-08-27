#ifndef _PUBLISHER_H_
#define _PUBLISHER_H_

#include "Subscriber.h"

#define MAX_SUBSCRIBERS 10

typedef enum
{
  NOT_OK =0,
  OK
} Status_Device;

typedef struct Publisher
{
    Subscriber* subscribers[MAX_SUBSCRIBERS];
    int subcriber_Count;

    void (*subscribe)(struct Publisher* self,Subscriber* s);
    void (*unsubscribe)(struct Publisher* self,Subscriber* s);
    void (*notify_Subscribers)(struct Publisher* self, const char* eventInfo);

} Publisher;

void Publisher_Init(Publisher* pub);

#endif /*_PUBLISHER_H_*/