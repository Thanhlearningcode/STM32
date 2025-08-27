#include "ds18b20.h"
#include <time.h>

float ds18b20ReadRaw(Ds18b20 *sensor) {
    sensor->lastValue = 24.2f; // Simulated value
    sensor->lastReadTime = time(NULL);
    return sensor->lastValue;
}
const char *ds18b20GetName(Ds18b20 *sensor) { return "DS18B20"; }
const char *ds18b20GetUnit(Ds18b20 *sensor) { return "°C"; }
float ds18b20GetMinValue(Ds18b20 *sensor) { return -55.0f; }
float ds18b20GetMaxValue(Ds18b20 *sensor) { return 125.0f; }
time_t ds18b20GetLastReadTime(Ds18b20 *sensor) { return sensor->lastReadTime; }