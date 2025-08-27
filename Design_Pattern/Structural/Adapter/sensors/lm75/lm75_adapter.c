#include "lm75_adapter.h"

// Adapter functions
static float lm75AdapterRead(void *self) { return lm75ReadRaw((Lm75 *)self); }
static const char *lm75AdapterGetName(void *self) { return lm75GetName((Lm75 *)self); }
static const char *lm75AdapterGetUnit(void *self) { return lm75GetUnit((Lm75 *)self); }
static float lm75AdapterGetMinValue(void *self) { return lm75GetMinValue((Lm75 *)self); }
static float lm75AdapterGetMaxValue(void *self) { return lm75GetMaxValue((Lm75 *)self); }
static time_t lm75AdapterGetLastReadTime(void *self) { return lm75GetLastReadTime((Lm75 *)self); }

TemperatureSensorInterface lm75CreateAdapter(Lm75 *sensor) {
    TemperatureSensorInterface adapter;
    adapter.instance = sensor;
    adapter.readTemperature = lm75AdapterRead;
    adapter.getName = lm75AdapterGetName;
    adapter.getUnit = lm75AdapterGetUnit;
    adapter.getMinValue = lm75AdapterGetMinValue;
    adapter.getMaxValue = lm75AdapterGetMaxValue;
    adapter.getLastReadTime = lm75AdapterGetLastReadTime;
    return adapter;
}