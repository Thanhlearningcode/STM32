#include "Uart_Driver.h"
#include "Uart_Builder.h"
#include "SensorManager_Singleton.h"
#include "Adc.h"


int main(void)
{   
    Uart_Builder builder = UART_Builder_Init();
    Uart_Config_t config = builder
        .setBaudrate(&builder, UART_BAUDRATE_115200)
        ->setParity(&builder, UART_PARITY_NONE)
        ->setStopBits(&builder, UART_STOPBITS_1)
        ->setDataBits(&builder, UART_DATABITS_8)
        ->build(&builder);

    UART2_Config(config);
    UART2_SendString("Hello,My name is Thanh!\r\n");



    SensorManager* sm = SensorManager_GetInstance();

    while(1) 
    {
        UART2_SendString("Hello,My name is Thanh!\r\n");
        SensorManager_CollectData(sm);
        SensorManager_UploadToDatabase(sm);
        // Delay đơn giản
        for(volatile int i=0; i<1000000; i++);
    }
}
