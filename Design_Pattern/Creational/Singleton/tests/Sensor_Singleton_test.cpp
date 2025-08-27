#include "gtest/gtest.h"
extern "C" {
    #include "../Inc/SensorManager_Singleton.h"
}
extern "C" {
    #include "../Inc/Uart_Builder.h"
}

TEST(SensorManagerSingletonTest, ReturnsSameInstance) {
    SensorManager* sm1 = SensorManager_GetInstance();
    SensorManager* sm2 = SensorManager_GetInstance();
    
    if (sm1 == nullptr || sm2 == nullptr) 
    {
      
        GTEST_FAIL() << "One or both SensorManager instances are nullptr. "
                        "Check if stm32f4xx.h is missing or mocks not set correctly.";
    } else 
    {
        ASSERT_EQ(sm1, sm2) << "SensorManager_GetInstance() should return the same instance pointer.";
    }
}

TEST(SensorManagerSingletonTest, CollectDataUpdatesSameInstance) 
{
    SensorManager* sm = SensorManager_GetInstance();
    ASSERT_NE(sm, nullptr) << "SensorManager instance is nullptr, check if stm32f4xx.h is missing.";

    sm->SensorCout = 2;
    SensorManager_CollectData(sm);

    // Kiểm tra dữ liệu từ sensor
    EXPECT_EQ(sm->AdcValues[0], 0);
    EXPECT_EQ(sm->AdcValues[1], 100);
}
