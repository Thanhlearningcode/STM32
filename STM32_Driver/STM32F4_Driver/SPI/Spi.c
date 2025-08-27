/*
 * Author: Nguyen Van Thanh
 * Description: SPI initialization and communication using STM32F411
 * PA4  -> NSS (Output)
 * PA5  -> SCK (Alternate Function)
 * PA6  -> MISO (Alternate Function)
 * PA7  -> MOSI (Alternate Function)
 */

#include "stm32f411xe.h"
#include "w5500.h"
#include "socket.h"
#include "wizchip_conf.h"

// Function to initialize SPI
void SPI_Init(void) {
    // Enable clock for GPIOA and SPI1
    RCC->AHB1ENR |= (1 << 0);   // Enable GPIOA clock
    RCC->APB2ENR |= (1 << 12);  // Enable SPI1 clock
    
    // Configure GPIO pins
    GPIOA->MODER &= ~(0xFF << 8);  // Clear bits for PA4-PA7
    GPIOA->MODER |= (1U << 8);     // PA4 as output (NSS)
    GPIOA->MODER |= (2U << 10);    // PA5 as AF (SCK)
    GPIOA->MODER |= (2U << 12);    // PA6 as AF (MISO)
    GPIOA->MODER |= (2U << 14);    // PA7 as AF (MOSI)
    
    // Set Alternate Function AF5 (SPI1) for PA5, PA6, PA7
    GPIOA->AFR[0] |= (0x5 << 20);  // PA5 AF5 (SCK)
    GPIOA->AFR[0] |= (0x5 << 24);  // PA6 AF5 (MISO)
    GPIOA->AFR[0] |= (0x5 << 28);  // PA7 AF5 (MOSI)
    
    // Configure SPI
    SPI1->CR1 |= (1 << 3);   // Set baud rate (fPCLK/4)
    SPI1->CR1 &= ~(1 << 7);  // MSB first
    SPI1->CR1 |= (1 << 8);   // Internal slave select
    SPI1->CR1 |= (1 << 9);   // Software slave management
    SPI1->CR1 |= (1 << 10);  // Full duplex (Transmit and receive)
    SPI1->CR1 &= ~(1 << 11); // 8-bit data frame format
    SPI1->CR1 |= (3U << 0);  // Set CPOL and CPHA
    SPI1->CR1 |= (1 << 2);   // Master configuration
    SPI1->CR1 |= (1 << 6);   // Enable SPI
}

// Function to transmit data via SPI
void SPI_Transmit(uint8_t *data, int size) {
    int i = 0;
    while (size > i) {
        // Wait until TX buffer is empty
        while (((SPI1->SR >> 1) & 0x1) != 1) {}
        SPI1->DR = data[i];
        i++;
    }

    // Clear error flags (if any)
    int temp = SPI1->SR;
    temp = SPI1->DR;
}

// Function to receive data via SPI
void SPI_Receive(uint8_t *data, int size) {
    while (size) {
        // Send dummy data
        SPI1->DR = 0;
        // Wait until RX buffer is not empty
        while (((SPI1->SR) & 0x1) != 1) {}
        *data++ = SPI1->DR;
        size--;
    }
}

// Function to enable select (CS)
void EN_CS(void) {
    GPIOA->ODR &= ~(1U << 4);  // Pull NSS low
}

// Function to disable chip select (CS)
void DIS_CS(void) {
    GPIOA->ODR |= (1U << 4);   // Pull NSS high
}
void W5500_Init(void);
void W5500_ConfigureNetwork(void);

// Function to initialize W5500
void W5500_Init(void) {
    uint8_t resetCmd = 0x00;  // Gi? s? l?nh reset là 0x00
    EN_CS();
    SPI_Transmit(&resetCmd, 1);  // G?i l?nh reset d?n W5500
    DIS_CS();
    
    // Configure W5500 (e.g., setup IP, gateway, subnet mask)
    W5500_ConfigureNetwork();
}

// Function to configure network settings for W5500
void W5500_ConfigureNetwork(void) {
    uint8_t ip[4] = {192, 168, 1, 100};
    uint8_t subnet[4] = {255, 255, 255, 0};
    uint8_t gateway[4] = {192, 168, 1, 1};
    
    // Write to W5500 registers to set IP, subnet, gateway
    EN_CS();
    SPI_Transmit(ip, sizeof(ip));  // Ví d? l?nh d? thi?t l?p IP
    DIS_CS();
    
    EN_CS();
    SPI_Transmit(subnet, sizeof(subnet));  // Ví d? l?nh d? thi?t l?p subnet mask
    DIS_CS();
    
    EN_CS();
    SPI_Transmit(gateway, sizeof(gateway));  // Ví d? l?nh d? thi?t l?p gateway
    DIS_CS();
}

int main() {

    SPI_Init();
    W5500_Init();

    while (1) {
      
    }
}
