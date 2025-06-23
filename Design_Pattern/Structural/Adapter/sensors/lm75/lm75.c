#include "lm75.h"
#include <time.h>

float lm75ReadRaw(Lm75 *sensor) {
    sensor->lastValue = 27.5f; // Simulated value
    sensor->lastReadTime = time(NULL);
    return sensor->lastValue;
}

const char *lm75GetName(Lm75 *sensor) { return "LM75"; }
const char *lm75GetUnit(Lm75 *sensor) { return "°C"; }
float lm75GetMinValue(Lm75 *sensor) { return -55.0f; }
float lm75GetMaxValue(Lm75 *sensor) { return 125.0f; }
time_t lm75GetLastReadTime(Lm75 *sensor) { return sensor->lastReadTime; }
