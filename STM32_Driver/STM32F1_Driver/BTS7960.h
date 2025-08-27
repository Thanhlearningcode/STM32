#ifndef BTS_LIB_H_
#define BTS_LIB_H_

/**************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Author: Nguyen Van Thanh
 *  Date: 2024-11-01
 *  This software is provided for educational purposes only.
 *  \endverbatim
 *************************************************************************************************/

/**************************************************************************************************
 *  INCLUDES
 *************************************************************************************************/
#include "stm32f1xx_hal.h"

/**************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *************************************************************************************************/
/**
 * \brief Enumeration for controlling the car's movement.
 */
typedef enum {
    Stop = 0U,   /**< Stop the car. */
    Forward,     /**< Move the car forward. */
    Backward,    /**< Move the car backward. */
    Left,        /**< Turn the car to the left. */
    Right        /**< Turn the car to the right. */
} ControlCar;

/**
 * \brief Initialize and start the robot.
 * \details This function prepares the robot and starts it in an initial ready state.
 */
void startRobot(void);

/**
 * \brief Move the robot forward.
 * \param[in] pwm1 PWM value for the left motor.
 * \param[in] pwm2 PWM value for the right motor.
 * \details Makes the robot move straight forward based on the PWM values.
 */
void turnfowardRobot(uint32_t pwm1, uint32_t pwm2);

/**
 * \brief Move the robot backward.
 * \param[in] pwm1 PWM value for the left motor.
 * \param[in] pwm2 PWM value for the right motor.
 * \details Reverses the robot based on the PWM values.
 */
void turnbackwardRobot(uint32_t pwm1, uint32_t pwm2);

/**
 * \brief Turn the robot to the right.
 * \param[in] pwm1 PWM value for the left motor.
 * \param[in] pwm2 PWM value for the right motor.
 * \details Rotates the robot to the right by adjusting motor PWM values.
 */
void turnrightRobot(uint32_t pwm1, uint32_t pwm2);

/**
 * \brief Turn the robot to the left.
 * \param[in] pwm1 PWM value for the left motor.
 * \param[in] pwm2 PWM value for the right motor.
 * \details Rotates the robot to the left by adjusting motor PWM values.
 */
void turnleftRobot(uint32_t pwm1, uint32_t pwm2);

/**
 * \brief Stop the robot.
 * \param[in] pwm1 PWM value for the left motor (typically set to zero).
 * \param[in] pwm2 PWM value for the right motor (typically set to zero).
 * \details Halts the robot's movement by setting PWM values to zero.
 */
void stopRobot(uint32_t pwm1, uint32_t pwm2);

#endif /* BTS_LIB_H_ */
