#ifndef LM75_H
#define LM75_H

#include <time.h>

typedef struct {
    int i2c_address;
    float lastValue;
    time_t lastReadTime;
} Lm75;

float lm75ReadRaw(Lm75 *sensor);
const char *lm75GetName(Lm75 *sensor);
const char *lm75GetUnit(Lm75 *sensor);
float lm75GetMinValue(Lm75 *sensor);
float lm75GetMaxValue(Lm75 *sensor);
time_t lm75GetLastReadTime(Lm75 *sensor);

#endif // LM75_H
