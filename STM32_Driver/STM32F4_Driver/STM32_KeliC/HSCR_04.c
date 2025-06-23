#include "HSCR_04.h""

/* Delay function using SysTick */
static void DelayMicroseconds(uint32_t us) {
    us *= (SystemCoreClock / 1000000) / 8;
    while (us--);
}

uint8_t HCSR04_Init(HCSR04_t* HCSR04, GPIO_TypeDef* ECHO_GPIOx, uint16_t ECHO_GPIO_Pin, GPIO_TypeDef* TRIGGER_GPIOx, uint16_t TRIGGER_GPIO_Pin) {
    /* Save GPIO settings */
    HCSR04->ECHO_GPIOx = ECHO_GPIOx;
    HCSR04->ECHO_GPIO_Pin = ECHO_GPIO_Pin;
    HCSR04->TRIGGER_GPIOx = TRIGGER_GPIOx;
    HCSR04->TRIGGER_GPIO_Pin = TRIGGER_GPIO_Pin;

    /* Enable GPIO clocks */
    if (ECHO_GPIOx == GPIOA || TRIGGER_GPIOx == GPIOA) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    if (ECHO_GPIOx == GPIOB || TRIGGER_GPIOx == GPIOB) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
    if (ECHO_GPIOx == GPIOC || TRIGGER_GPIOx == GPIOC) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;

    /* Set TRIGGER pin as output */
    TRIGGER_GPIOx->MODER &= ~(3U << (TRIGGER_GPIO_Pin * 2));  /* Clear mode bits */
    TRIGGER_GPIOx->MODER |= (1U << (TRIGGER_GPIO_Pin * 2));   /* Set mode to output */
    TRIGGER_GPIOx->OSPEEDR |= (2U << (TRIGGER_GPIO_Pin * 2)); /* Medium speed */
    TRIGGER_GPIOx->OTYPER &= ~(1U << TRIGGER_GPIO_Pin);       /* Output type push-pull */
    TRIGGER_GPIOx->PUPDR &= ~(3U << (TRIGGER_GPIO_Pin * 2));  /* No pull-up/pull-down */

    /* Set ECHO pin as input */
    ECHO_GPIOx->MODER &= ~(3U << (ECHO_GPIO_Pin * 2));        /* Set mode to input */
    ECHO_GPIOx->PUPDR &= ~(3U << (ECHO_GPIO_Pin * 2));        /* No pull-up/pull-down */

    /* Set Trigger pin to low */
    TRIGGER_GPIOx->BSRR |= (1U << (TRIGGER_GPIO_Pin + 16));

    /* Check if sensor works */
    if (HCSR04_Read(HCSR04) >= 0) {
        return 1;
    }

    return 0;
}

float HCSR04_Read(HCSR04_t* HCSR04) {
    uint32_t time = 0, timeout = HCSR04_TIMEOUT;

    /* Trigger low */
    HCSR04->TRIGGER_GPIOx->BSRR |= (1U << (HCSR04->TRIGGER_GPIO_Pin + 16));
    DelayMicroseconds(2);

    /* Trigger high for 10us */
    HCSR04->TRIGGER_GPIOx->BSRR |= (1U << HCSR04->TRIGGER_GPIO_Pin);
    DelayMicroseconds(10);
    HCSR04->TRIGGER_GPIOx->BSRR |= (1U << (HCSR04->TRIGGER_GPIO_Pin + 16));

    /* Wait for ECHO pin to go high */
    while (!(HCSR04->ECHO_GPIOx->IDR & (1U << HCSR04->ECHO_GPIO_Pin))) {
        if (timeout-- == 0) return -1;
    }

    /* Measure the time ECHO pin is high */
    while (HCSR04->ECHO_GPIOx->IDR & (1U << HCSR04->ECHO_GPIO_Pin)) {
        time++;
        DelayMicroseconds(1);
    }

    /* Convert time to distance in cm */
    HCSR04->Distance = (float)time * HCSR04_NUMBER;

    return HCSR04->Distance;
}
