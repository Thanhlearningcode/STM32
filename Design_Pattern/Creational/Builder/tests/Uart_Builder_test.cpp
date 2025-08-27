#include <gtest/gtest.h>

extern "C" {
    #include "../Inc/Uart_Builder.h"
}

TEST(UartBuilderTest, DefaultConfigTest) {
    Uart_Builder builder = UART_Builder_Init();
    Uart_Config_t config = builder.build(&builder);
    EXPECT_EQ(config.baudRate, 9600);
    EXPECT_EQ(config.parity, 0);
    EXPECT_EQ(config.stopBits, 1);
    EXPECT_EQ(config.dataBits, 8);
}

TEST(UartBuilderTest, CustomValidConfig) {
    Uart_Builder builder = UART_Builder_Init();
    builder.setBaudrate(&builder, 115200);
    builder.setParity(&builder, 2);
    builder.setStopBits(&builder, 2);
    builder.setDataBits(&builder, 9);

    Uart_Config_t config = builder.build(&builder);
    EXPECT_EQ(config.baudRate, 115200);
    EXPECT_EQ(config.parity, 2);
    EXPECT_EQ(config.stopBits, 2);
    EXPECT_EQ(config.dataBits, 9);
}

TEST(UartBuilderTest, InvalidBaudrateIgnored) {
    Uart_Builder builder = UART_Builder_Init();
    builder.setBaudrate(&builder, 100);  // invalid
    Uart_Config_t config = builder.build(&builder);
    EXPECT_EQ(config.baudRate, 9600);  // giữ nguyên mặc định
}

TEST(UartBuilderTest, InvalidStopBitsIgnored) {
    Uart_Builder builder = UART_Builder_Init();
    builder.setStopBits(&builder, 3);  // invalid
    Uart_Config_t config = builder.build(&builder);
    EXPECT_EQ(config.stopBits, 1);  // giữ nguyên mặc định
}
