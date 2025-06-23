cmake_minimum_required(VERSION 3.10)
project(UartBuilderTest LANGUAGES C CXX)
project(UartBuilderTest C)

enable_testing()

# Add GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

# Add test executable
add_executable(uart_builder_test Uart_Builder_test.cpp ../Src/Uart_Builder.c)

# Include headers
target_include_directories(uart_builder_test PRIVATE ../Inc)

# Link with gtest
target_link_libraries(uart_builder_test gtest gtest_main)

# Add test
add_test(NAME UartBuilderTest COMMAND uart_builder_test)
