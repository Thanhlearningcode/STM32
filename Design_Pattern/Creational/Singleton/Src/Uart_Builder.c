#include "Uart_Builder.h"

static Uart_Builder *setBaudrate(Uart_Builder * builder, uint32_t baudrate_)
{
    if (baudrate_<UART_BAUDRATE_9600 || baudrate_>UART_BAUDRATE_115200)
    {
     //   printf("Error: Invalid baud rate. Must be between 1200 and 115200.\n");
        return builder;
    }
    builder->config.baudRate = baudrate_;

    return builder;
}

static Uart_Builder * setParity(Uart_Builder *builder, uint8_t parity_)
{
    if (parity_<UART_PARITY_NONE || parity_ >UART_PARITY_EVEN)
    {
     //   printf("Error: Invalid parity. Must be 0 (None), 1 (Odd), or 2 (Even).\n");
        return builder;
    }
    builder->config.parity = parity_;
    return builder;
}

static Uart_Builder *setStopBits(Uart_Builder *builder, uint8_t stopBits_)
{
    if (stopBits_ != UART_STOPBITS_1 && stopBits_ != UART_STOPBITS_2)
    {
   //     printf("Error: Invalid stop bits. Must be 1 or 2.\n");
        return builder;
    }

    builder->config.stopBits = stopBits_;

    return builder;
}


// Function to set the data bits
static Uart_Builder* setDataBits(Uart_Builder* builder, uint8_t dataBits_) {
    if (dataBits_ != UART_DATABITS_8 && dataBits_ != UART_DATABITS_9) {
     //   printf("Error: Invalid data bits. Must be 8 or 9.\n");
        return builder;
    }
    builder->config.dataBits = dataBits_;
    return builder;
}

// Function to build and return the UART configuration
static Uart_Config_t build(Uart_Builder * builder)
{
    return builder->config;
}


// Function to initialize the Builder
Uart_Builder UART_Builder_Init() {
    Uart_Builder builder;
    builder.config.baudRate = UART_BAUDRATE_9600;   // Default baud rate
    builder.config.parity = UART_PARITY_NONE;       // Default parity: None
    builder.config.stopBits = UART_STOPBITS_1;     // Default stop bits: 1
    builder.config.dataBits = UART_DATABITS_8;     // Default data bits: 8
    builder.setBaudrate = setBaudrate;
    builder.setParity = setParity;
    builder.setStopBits = setStopBits;
    builder.setDataBits = setDataBits;
    builder.build = build;
    return builder;
}