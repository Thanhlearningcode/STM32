#include "Subscribers/Mobile_App_Notifier.h"
#include <stdio.h>

/* Update method for MobileAppNotifier */
void MobileApp_Update(Subscriber *self,Publisher* context, const char* eventInfor) 
{
    (void)self; (void)context;
    printf("[MobileApp] Alert: %s\n",eventInfor);
}

/* Initialize MobileAppNotifier*/
void MobileApp_Notifier_Init(MobileApp_Notifier* notifier) 
{
    notifier->base.update =   MobileApp_Update;
    notifier->base.data   =   NULL; 
}