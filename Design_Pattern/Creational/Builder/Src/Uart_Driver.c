#include "Uart_Driver.h"

void UART1_Config(Uart_Config_t config)
{
      // 1. Clock enable cho GPIOA và USART1
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;   // PA9: TX, PA10: RX
    RCC->APB2ENR |= RCC_APB2ENR_USART1EN;

    // 2. Cấu hình Alternate Function cho PA9, PA10
    GPIOA->MODER  &=~(0xF << (9*2)); // Clear mode bits
    GPIOA->MODER  |= (0xA << (9*2)); // Set Af 
    GPIOA->AFR[1] &= ~((0xF << (1 * 4)) | (0xF << (2 * 4))); // Clear AFR
    GPIOA->AFR[1] |=  (0x7 << (1 * 4)) | (0x7 << (2 * 4));   // AF
    //3. Baudrate
    uint32_t uartdiv = 16000000 / config.baudRate; // Giả sử APB2 = 16MHz
    USART1->BRR = uartdiv;

    // 4. Cấu hình parity & data bits
    USART1->CR1 = 0;
    if (config.parity == 1) 
    {
        USART1->CR1 |= USART_CR1_PCE | USART_CR1_PS; // Odd
    } else if (config.parity == 2) 
    {
        USART1->CR1 |= USART_CR1_PCE; // Even
    }

    if (config.dataBits == 9 || (config.parity && config.dataBits == 8)) 
    {
        USART1->CR1 |= USART_CR1_M;
    }

    // 5. Stop bits
        USART1->CR2 &= ~USART_CR2_STOP;

    if (config.stopBits == 2) 
    {
        USART1->CR2 |= (0x2 << USART_CR2_STOP_Pos);
    }

    // 6. Enable TX, RX, USART
    USART1->CR1 |= USART_CR1_TE | USART_CR1_RE | USART_CR1_UE;
}

// Hàm gửi 1 ký tự
void UART1_SendChar(char c)
{
    while (!(USART1->SR & USART_SR_TXE)); // Chờ TX trống
    USART1->DR = c;
}

// Hàm gửi chuỗi
void UART1_SendString(const char *str)
{
    while (*str)
    {
        UART1_SendChar(*str++);
    }
}

// Hàm nhận ký tự (blocking)
char UART1_ReceiveChar(void)
{
    while (!(USART1->SR & USART_SR_RXNE)); // Chờ dữ liệu sẵn sàng
    return USART1->DR;
}

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
