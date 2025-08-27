#include "Uart_Driver.h"
#include <stdarg.h>
#include <stdio.h>

void UART2_Config(Uart_Config_t config)
{
    // 1. Enable clock cho GPIOA & USART2
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;

    // 2. PA2 (TX), PA3 (RX) → Alternate function AF7
    GPIOA->MODER &= ~((3 << (2 * 2)) | (3 << (3 * 2)));  // Clear bits
    GPIOA->MODER |=  (2 << (2 * 2)) | (2 << (3 * 2));    // Set to AF

    GPIOA->AFR[0] &= ~((0xF << (2 * 4)) | (0xF << (3 * 4))); // Clear AF
    GPIOA->AFR[0] |=  (7 << (2 * 4)) | (7 << (3 * 4));       // AF7

    // 3. Baudrate
    uint32_t uartdiv = (16000000 + config.baudRate / 2) / config.baudRate;
    USART2->BRR = uartdiv;

    // 4. Parity & data bits
    USART2->CR1 = 0;
    if (config.parity == 1) {
        USART2->CR1 |= USART_CR1_PCE | USART_CR1_PS; // Odd
    } else if (config.parity == 2) {
        USART2->CR1 |= USART_CR1_PCE; // Even
    }

    if ((config.dataBits == 9) || (config.parity != 0 && config.dataBits == 8)) {
        USART2->CR1 |= USART_CR1_M;
    }

    // 5. Stop bits
    USART2->CR2 &= ~USART_CR2_STOP;
    if (config.stopBits == 2) {
        USART2->CR2 |= (2 << USART_CR2_STOP_Pos);
    }

    // 6. Enable TX, RX, USART
    USART2->CR1 |= USART_CR1_TE | USART_CR1_RE | USART_CR1_UE;
}

void UART2_SendChar(char c)
{
    while (!(USART2->SR & USART_SR_TXE));
    USART2->DR = c;
}

void UART2_SendString(const char *s)
{
    while (*s) {
        UART2_SendChar(*s++);
    }
}

char UART2_ReceiveChar(void)
{
    while (!(USART2->SR & USART_SR_RXNE));
    return USART2->DR;
}

void UART2_Printf(const char* format, ...) {
    char buffer[128];
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);
    UART2_SendString(buffer);
}
