#include <stdio.h>
#include "temperature_sensor_interface.h"
#include "ds18b20_adapter.h"
#include "lm75_adapter.h"

int main(void) {
    Ds18b20 ds18b20;
    Lm75 lm75;

    TemperatureSensorInterface *ds18b20_iface = ds18b20_get_interface(&ds18b20_sensor);
    TemperatureSensorInterface *lm75_iface = lm75_get_interface(&lm75_sensor);

    // Test DS18B20
    printf("DS18B20:\n");
    printf("  Name: %s\n", ds18b20_iface->get_name(ds18b20_iface->sensor));
    printf("  Unit: %s\n", ds18b20_iface->get_unit(ds18b20_iface->sensor));
    printf("  Min: %.2f\n", ds18b20_iface->get_min_value(ds18b20_iface->sensor));
    printf("  Max: %.2f\n", ds18b20_iface->get_max_value(ds18b20_iface->sensor));
    printf("\n");

    // Test LM75
    printf("LM75:\n");
    printf("  Name: %s\n", lm75_iface->get_name(lm75_iface->sensor));
    printf("  Unit: %s\n", lm75_iface->get_unit(lm75_iface->sensor));
    printf("  Min: %.2f\n", lm75_iface->get_min_value(lm75_iface->sensor));
    printf("  Max: %.2f\n", lm75_iface->get_max_value(lm75_iface->sensor));

    return 0;
}
