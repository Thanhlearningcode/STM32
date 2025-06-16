#include "Gpio.h"
#include "Uart_Driver.h"
#include "Uart_Builder.h"
#include <stdio.h>

void delay(volatile uint32_t count) {
    while(count--) {
        __NOP();
    }
}

 extern void UART1_Config(Uart_Config_t config);  

int main(void) 
{
    GPIOA_Pin5_Output_Init();
    Uart_Builder builder = UART_Builder_Init();
   

    Uart_Config_t config = builder
        .setBaudrate(&builder, UART_BAUDRATE_115200)
        ->setParity(&builder, UART_PARITY_NONE)
        ->setStopBits(&builder, UART_STOPBITS_1)
        ->setDataBits(&builder, UART_DATABITS_8)
        ->build(&builder);

    UART2_Config(config);
  //  UART1_SendString("UART Ready1111!\r\n");
         // Print the configured UART parameters
    while(1) 
    {
     UART2_SendString("Hello,My name is Thanh!\r\n");
    // char c = UART2_ReceiveChar();  // Nhận ký tự từ terminal
    //  UART2_SendChar(c);             // Phản hồi lại
     //   GPIOA_Pin5_Toggle();
        delay(3000000);
    }
}
