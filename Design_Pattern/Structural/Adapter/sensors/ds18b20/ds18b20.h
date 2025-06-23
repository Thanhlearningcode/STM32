#ifndef DS18B20_H
#define DS18B20_H

#include <time.h>

typedef struct {
    int pin;
    float lastValue;
    time_t lastReadTime;
} Ds18b20;

float ds18b20ReadRaw(Ds18b20 *sensor);
const char *ds18b20GetName(Ds18b20 *sensor);
const char *ds18b20GetUnit(Ds18b20 *sensor);
float ds18b20GetMinValue(Ds18b20 *sensor);
float ds18b20GetMaxValue(Ds18b20 *sensor);
time_t ds18b20GetLastReadTime(Ds18b20 *sensor);

#endif // DS18B20_H