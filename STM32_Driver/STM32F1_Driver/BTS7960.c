#include <BTS7960.h>
#include "stm32f1xx_hal.h"

/**************************************************************************************************
 *  GLOBAL FUNCTION DEFINITIONS
 *************************************************************************************************/

/**
 * \brief Initialize the robot's hardware configuration.
 * \details Configures RCC and GPIOA for TIM2 to set up PWM for controlling motors.
 */
void startRobot(void) {
    // Enable RCC for GPIOA and TIM2
    RCC->APB1ENR |= (1U << 2);  // Enable GPIOA
    RCC->APB1ENR |= (1U << 0);  // Enable TIM2

    // Configure GPIOA pins for Alternate function output Push-pull with max speed 50MHz
    GPIOA->CRH &= ~(0xF << 0);       
    GPIOA->CRH |= (0xB << 0);        // PA0
    GPIOA->CRH &= ~(0xF << 4);       
    GPIOA->CRH |= (0xB << 4);        // PA1
    GPIOA->CRH &= ~(0xF << 8);       
    GPIOA->CRH |= (0xB << 8);        // PA2
    GPIOA->CRH &= ~(0xF << 12);      
    GPIOA->CRH |= (0xB << 12);       // PA3

    // Configure PWM for TIM2 with 72MHz frequency
    TIM2->CNT = 0;                   
    TIM2->PSC = 71;                   // Prescaler for 1MHz timer frequency
    TIM2->ARR = 0xFFFF - 1;           // Set auto-reload value
    TIM2->CR1 &= ~(1U << 7);          // Disable auto-reload preload
    TIM2->CR1 &= ~(1U << 4);          // Set up-counter mode

    // Set default PWM values
    TIM2->CCR1 = 0;
    TIM2->CCR2 = 0;
    TIM2->CCR3 = 0;
    TIM2->CCR4 = 0;

    // Configure output modes for PWM
    TIM2->CCMR1 |= (6U << 4) | (6U << 12);   // PWM mode 1 for CC1 and CC2
    TIM2->CCMR2 |= (6U << 4) | (6U << 12);   // PWM mode 1 for CC3 and CC4

    TIM2->CR1 |= (1U << 0);           // Enable TIM2
}

/**
 * \brief Move the robot forward.
 * \param[in] pwm1 PWM value for the left motor.
 * \param[in] pwm2 PWM value for the right motor.
 */
void turnfowardRobot(uint32_t pwm1, uint32_t pwm2) {
    if (pwm1 > 66535) pwm1 = 66535;
    if (pwm2 > 66535) pwm2 = 66535;

    TIM2->CCR1 = pwm1;  // Motor left forward
    TIM2->CCR2 = 0;
    TIM2->CCR3 = pwm2;  // Motor right forward
    TIM2->CCR4 = 0;
}

/**
 * \brief Move the robot backward.
 * \param[in] pwm1 PWM value for the left motor.
 * \param[in] pwm2 PWM value for the right motor.
 */
void turnbackwardRobot(uint32_t pwm1, uint32_t pwm2) {
    if (pwm1 > 66535) pwm1 = 66535;
    if (pwm2 > 66535) pwm2 = 66535;

    TIM2->CCR1 = 0;
    TIM2->CCR2 = pwm1;  // Motor left backward
    TIM2->CCR3 = 0;
    TIM2->CCR4 = pwm2;  // Motor right backward
}

/**
 * \brief Turn the robot to the right.
 * \param[in] pwm1 PWM value for the left motor.
 * \param[in] pwm2 PWM value for the right motor.
 */
void turnrightRobot(uint32_t pwm1, uint32_t pwm2) {
    if (pwm1 > 66535) pwm1 = 66535;
    if (pwm2 > 66535) pwm2 = 66535;

    TIM2->CCR1 = 0;
    TIM2->CCR2 = pwm1;  // Left motor backward
    TIM2->CCR3 = pwm2;  // Right motor forward
    TIM2->CCR4 = 0;
}

/**
 * \brief Turn the robot to the left.
 * \param[in] pwm1 PWM value for the left motor.
 * \param[in] pwm2 PWM value for the right motor.
 */
void turnleftRobot(uint32_t pwm1, uint32_t pwm2) {
    if (pwm1 > 66535) pwm1 = 66535;
    if (pwm2 > 66535) pwm2 = 66535;

    TIM2->CCR1 = pwm1;  // Left motor forward
    TIM2->CCR2 = 0;
    TIM2->CCR3 = 0;
    TIM2->CCR4 = pwm2;  // Right motor backward
}

/**
 * \brief Stop the robot's movement.
 */
void stopRobot(uint32_t pwm1, uint32_t pwm2) {
    TIM2->CCR1 = 0;
    TIM2->CCR2 = 0;
    TIM2->CCR3 = 0;
    TIM2->CCR4 = 0;
}

/**
 * \brief Control robot based on selected mode.
 * \param[in] controlRobot Function pointer to control robot mode.
 * \param[in] pwm1 PWM value for the left motor.
 * \param[in] pwm2 PWM value for the right motor.
 *
 * Modes:
 *   Mode 0 -> Stop
 *   Mode 1 -> Forward
 *   Mode 2 -> Backward
 *   Mode 3 -> Left
 *   Mode 4 -> Right
 */
void modeRobot(void (*controlRobot)(uint32_t, uint32_t), uint32_t pwm1, uint32_t pwm2) {
    controlRobot(pwm1, pwm2);
}

/**************************************************************************************************
 *  GLOBAL VARIABLE DEFINITIONS
 *************************************************************************************************/
void (*controlRobot[])(uint32_t, uint32_t) = {
    stopRobot, turnfowardRobot, turnbackwardRobot, turnleftRobot, turnrightRobot
};

/**************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *************************************************************************************************/
