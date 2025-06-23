#ifndef SENSOR_MANAGER_SINGLETON_H
#define SENSOR_MANAGER_SINGLETON_H

#define MAX_SENSORS 10

typedef struct {
    int SensorCout;
    unsigned int AdcValues[MAX_SENSORS];
} SensorManager;

SensorManager* SensorManager_GetInstance(void);

void SensorManager_CollectData(SensorManager* sm);

void SensorManager_UploadToDatabase(SensorManager* sm);

#endif // SENSOR_MANAGER_SINGLETON_H
