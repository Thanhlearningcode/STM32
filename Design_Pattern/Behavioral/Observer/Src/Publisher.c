#include "Publisher.h"
#include <string.h>

/* Subscribe a subscriber to the publisher */
void Publisher_Subscribe(Publisher *self,Subscriber* s ) 
{
    if ((self->subcriber_Count) < MAX_SUBSCRIBERS)
    {
        self->subscribers[self->subcriber_Count++] = s;
    }
}

/* unSubscribe a subscriber to the publisher */
void Publisher_UnSubscribe(Publisher *self,Subscriber* s )
{
    for (int i = 0; i < self->subcriber_Count; i++)
    {
        if (self->subscribers[i] == s) 
        {
            for (int j = i; j < self->subcriber_Count -1; ++i)
            {
                self->subscribers[j] = self->subscribers[j+1];
            }
            self->subcriber_Count--;
            break;
        }
    }
}

/* Notify all subscribers about an event */
void Publisher_Notify(Publisher *self, const char* eventInfo) 
{
    for (int i=0; i < self->subcriber_Count; i++)
    {
        if (self->subscribers[i]&& self->subscribers[i]->update)
        {
            self->subscribers[i]->update(self->subscribers[i], self, eventInfo);

        }
    }
}

/* Initialize the publisher struct */ 
void Publisher_Init(Publisher* pub) {
    memset(pub, 0, sizeof(Publisher));
    pub->subscribe = Publisher_Subscribe;
    pub->unsubscribe = Publisher_UnSubscribe;
    pub->notify_Subscribers = Publisher_Notify;
}