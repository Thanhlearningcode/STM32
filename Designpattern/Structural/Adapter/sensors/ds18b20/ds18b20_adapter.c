#include "ds18b20_adapter.h"

// Adapter functions
static float ds18b20AdapterRead(void *self) { return ds18b20ReadRaw((Ds18b20 *)self); }
static const char *ds18b20AdapterGetName(void *self) { return ds18b20GetName((Ds18b20 *)self); }
static const char *ds18b20AdapterGetUnit(void *self) { return ds18b20GetUnit((Ds18b20 *)self); }
static float ds18b20AdapterGetMinValue(void *self) { return ds18b20GetMinValue((Ds18b20 *)self); }
static float ds18b20AdapterGetMaxValue(void *self) { return ds18b20GetMaxValue((Ds18b20 *)self); }
static time_t ds18b20AdapterGetLastReadTime(void *self) { return ds18b20GetLastReadTime((Ds18b20 *)self); }

TemperatureSensorInterface ds18b20CreateAdapter(Ds18b20 *sensor) {
    TemperatureSensorInterface adapter;
    adapter.instance = sensor;
    adapter.readTemperature = ds18b20AdapterRead;
    adapter.getName = ds18b20AdapterGetName;
    adapter.getUnit = ds18b20AdapterGetUnit;
    adapter.getMinValue = ds18b20AdapterGetMinValue;
    adapter.getMaxValue = ds18b20AdapterGetMaxValue;
    adapter.getLastReadTime = ds18b20AdapterGetLastReadTime;
    return adapter;
}