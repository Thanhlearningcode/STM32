cmake_minimum_required(VERSION 3.10)

project(SensorSingletonTest LANGUAGES C CXX)

enable_testing()

# Lấy GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

# Tạo executable test
add_executable(Sensor_Singleton_test
    Sensor_Singleton_test.cpp
    ../Src/SensorManager_Singleton.c
)

# Thêm thư mục include
target_include_directories(Sensor_Singleton_test PRIVATE ../Inc)


# Link thư viện GoogleTest và pthread
target_link_libraries(Sensor_Singleton_test gtest gtest_main pthread)

# Thêm test, tên test và tên executable phải trùng
add_test(NAME Sensor_Singleton_test COMMAND Sensor_Singleton_test)
