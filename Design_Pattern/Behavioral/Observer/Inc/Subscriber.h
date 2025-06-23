#ifndef _SUBSCRIBER_H_
#define _SUBSCRIBER_H_

typedef struct Publisher Publisher;

/* Subscriber interface */

typedef struct Subscriber
{
    void (*update)(struct Subscriber* self, Publisher *context, const char* evenInfo);
    void *data;
} Subscriber;


#endif /* _SUBSCRIBER_H_ */