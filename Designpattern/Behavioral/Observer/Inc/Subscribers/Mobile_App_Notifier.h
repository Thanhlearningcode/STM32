#ifndef _MOBILE_APP_NOTIFIER_H_
#define _MOBILE_APP_NOTIFIER_H_

#include "Subscriber.h" 

typedef struct 
{
    Subscriber base;
} MobileApp_Notifier;

void MobileApp_Notifier_Init(MobileApp_Notifier* notifier);

#endif /*  _MOBILE_APP_NOTIFIER_H_ */