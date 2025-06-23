/**********************************************************
 * @file Dio.h
 * @brief Digital Input/Output (DIO) Driver Header File
 * @details This file contains definitions of data types and 
 *          declarations of API functions for the DIO Driver according to the AUTOSAR standard.
 *          This driver is designed to control the GPIO of the STM32F103.
 * @version 1.0
 * @date 2024-11-7
 * @author Nguyen Van Thanh
 **********************************************************/

#ifndef DIO_H
#define DIO_H

#include "Std_Types.h" /* Includes AUTOSAR standard data types */
#include "stm32f10x_gpio.h"  /* Standard STM32F103 library */
#include "Dio_Cfg.h"
/**********************************************************
 * Definitions of PortId values for GPIO pins
 **********************************************************/

#define DIO_PORT_A   0  /* Mapping for GPIOA */
#define DIO_PORT_B   1  /* Mapping for GPIOB */
#define DIO_PORT_C   2  /* Mapping for GPIOC */
#define DIO_PORT_D   3  /* Mapping for GPIOD */

/**********************************************************
 * Macro to identify the GPIO port and pin based on ChannelId
 **********************************************************/

/* Macro to identify the GPIO port based on ChannelId */
#define DIO_GET_PORT(ChannelId) \
    (((ChannelId) < 16) ? GPIOA : \
    ((ChannelId) < 32) ? GPIOB : \
    ((ChannelId) < 48) ? GPIOC : \
    ((ChannelId) < 64) ? GPIOD : NULL)

/* Macro to identify the GPIO pin based on ChannelId */
#define DIO_GET_PIN(ChannelId) \
    (1 << ((ChannelId) % 16))  /* Calculate corresponding GPIO pin */

/**********************************************************
 * Macro to define ChannelId for each GPIO pin
 * @param[in] GPIOx: GPIO port (GPIOA, GPIOB, GPIOC, GPIOD)
 * @param[in] Pin: Pin number from 0 to 15
 **********************************************************/
#define DIO_CHANNEL(GPIOx, Pin)   (((GPIOx) << 4) + (Pin))

/* Channel for all pins on GPIOA */
#define DIO_CHANNEL_A0   DIO_CHANNEL(GPIOA, 0)   /* GPIOA Pin 0  */
#define DIO_CHANNEL_A1   DIO_CHANNEL(GPIOA, 1)   /* GPIOA Pin 1  */
#define DIO_CHANNEL_A2   DIO_CHANNEL(GPIOA, 2)   /* GPIOA Pin 2  */
#define DIO_CHANNEL_A3   DIO_CHANNEL(GPIOA, 3)   /* GPIOA Pin 3  */
#define DIO_CHANNEL_A4   DIO_CHANNEL(GPIOA, 4)   /* GPIOA Pin 4  */
#define DIO_CHANNEL_A5   DIO_CHANNEL(GPIOA, 5)   /* GPIOA Pin 5  */
#define DIO_CHANNEL_A6   DIO_CHANNEL(GPIOA, 6)   /* GPIOA Pin 6  */
#define DIO_CHANNEL_A7   DIO_CHANNEL(GPIOA, 7)   /* GPIOA Pin 7  */
#define DIO_CHANNEL_A8   DIO_CHANNEL(GPIOA, 8)   /* GPIOA Pin 8  */
#define DIO_CHANNEL_A9   DIO_CHANNEL(GPIOA, 9)   /* GPIOA Pin 9  */
#define DIO_CHANNEL_A10  DIO_CHANNEL(GPIOA, 10)  /* GPIOA Pin 10 */
#define DIO_CHANNEL_A11  DIO_CHANNEL(GPIOA, 11)  /* GPIOA Pin 11 */
#define DIO_CHANNEL_A12  DIO_CHANNEL(GPIOA, 12)  /* GPIOA Pin 12 */
#define DIO_CHANNEL_A13  DIO_CHANNEL(GPIOA, 13)  /* GPIOA Pin 13 */
#define DIO_CHANNEL_A14  DIO_CHANNEL(GPIOA, 14)  /* GPIOA Pin 14 */
#define DIO_CHANNEL_A15  DIO_CHANNEL(GPIOA, 15)  /* GPIOA Pin 15 */

/* Channel for all pins on GPIOB */
#define DIO_CHANNEL_B0   DIO_CHANNEL(GPIOB, 0)   /* GPIOB Pin 0  */
#define DIO_CHANNEL_B1   DIO_CHANNEL(GPIOB, 1)   /* GPIOB Pin 1  */
#define DIO_CHANNEL_B2   DIO_CHANNEL(GPIOB, 2)   /* GPIOB Pin 2  */
#define DIO_CHANNEL_B3   DIO_CHANNEL(GPIOB, 3)   /* GPIOB Pin 3  */
#define DIO_CHANNEL_B4   DIO_CHANNEL(GPIOB, 4)   /* GPIOB Pin 4  */
#define DIO_CHANNEL_B5   DIO_CHANNEL(GPIOB, 5)   /* GPIOB Pin 5  */
#define DIO_CHANNEL_B6   DIO_CHANNEL(GPIOB, 6)   /* GPIOB Pin 6  */
#define DIO_CHANNEL_B7   DIO_CHANNEL(GPIOB, 7)   /* GPIOB Pin 7  */
#define DIO_CHANNEL_B8   DIO_CHANNEL(GPIOB, 8)   /* GPIOB Pin 8  */
#define DIO_CHANNEL_B9   DIO_CHANNEL(GPIOB, 9)   /* GPIOB Pin 9  */
#define DIO_CHANNEL_B10  DIO_CHANNEL(GPIOB, 10)  /* GPIOB Pin 10 */
#define DIO_CHANNEL_B11  DIO_CHANNEL(GPIOB, 11)  /* GPIOB Pin 11 */
#define DIO_CHANNEL_B12  DIO_CHANNEL(GPIOB, 12)  /* GPIOB Pin 12 */
#define DIO_CHANNEL_B13  DIO_CHANNEL(GPIOB, 13)  /* GPIOB Pin 13 */
#define DIO_CHANNEL_B14  DIO_CHANNEL(GPIOB, 14)  /* GPIOB Pin 14 */
#define DIO_CHANNEL_B15  DIO_CHANNEL(GPIOB, 15)  /* GPIOB Pin 15 */

/* Channel for all pins on GPIOC */
#define DIO_CHANNEL_C0   DIO_CHANNEL(GPIOC, 0)   /* GPIOC Pin 0  */
#define DIO_CHANNEL_C1   DIO_CHANNEL(GPIOC, 1)   /* GPIOC Pin 1  */
#define DIO_CHANNEL_C2   DIO_CHANNEL(GPIOC, 2)   /* GPIOC Pin 2  */
#define DIO_CHANNEL_C3   DIO_CHANNEL(GPIOC, 3)   /* GPIOC Pin 3  */
#define DIO_CHANNEL_C4   DIO_CHANNEL(GPIOC, 4)   /* GPIOC Pin 4  */
#define DIO_CHANNEL_C5   DIO_CHANNEL(GPIOC, 5)   /* GPIOC Pin 5  */
#define DIO_CHANNEL_C6   DIO_CHANNEL(GPIOC, 6)   /* GPIOC Pin 6  */
#define DIO_CHANNEL_C7   DIO_CHANNEL(GPIOC, 7)   /* GPIOC Pin 7  */
#define DIO_CHANNEL_C8   DIO_CHANNEL(GPIOC, 8)   /* GPIOC Pin 8  */
#define DIO_CHANNEL_C9   DIO_CHANNEL(GPIOC, 9)   /* GPIOC Pin 9  */
#define DIO_CHANNEL_C10  DIO_CHANNEL(GPIOC, 10)  /* GPIOC Pin 10 */
#define DIO_CHANNEL_C11  DIO_CHANNEL(GPIOC, 11)  /* GPIOC Pin 11 */
#define DIO_CHANNEL_C12  DIO_CHANNEL(GPIOC, 12)  /* GPIOC Pin 12 */
#define DIO_CHANNEL_C13  DIO_CHANNEL(GPIOC, 13)  /* GPIOC Pin 13 */
#define DIO_CHANNEL_C14  DIO_CHANNEL(GPIOC, 14)  /* GPIOC Pin 14 */
#define DIO_CHANNEL_C15  DIO_CHANNEL(GPIOC, 15)  /* GPIOC Pin 15 */

/* Channel for all pins on GPIOD */
#define DIO_CHANNEL_D0   DIO_CHANNEL(GPIOD, 0)   /* GPIOD Pin 0  */
#define DIO_CHANNEL_D1   DIO_CHANNEL(GPIOD, 1)   /* GPIOD Pin 1  */
#define DIO_CHANNEL_D2   DIO_CHANNEL(GPIOD, 2)   /* GPIOD Pin 2  */
#define DIO_CHANNEL_D3   DIO_CHANNEL(GPIOD, 3)   /* GPIOD Pin 3  */
#define DIO_CHANNEL_D4   DIO_CHANNEL(GPIOD, 4)   /* GPIOD Pin 4  */
#define DIO_CHANNEL_D5   DIO_CHANNEL(GPIOD, 5)   /* GPIOD Pin 5  */
#define DIO_CHANNEL_D6   DIO_CHANNEL(GPIOD, 6)   /* GPIOD Pin 6  */
#define DIO_CHANNEL_D7   DIO_CHANNEL(GPIOD, 7)   /* GPIOD Pin 7  */
#define DIO_CHANNEL_D8   DIO_CHANNEL(GPIOD, 8)   /* GPIOD Pin 8  */
#define DIO_CHANNEL_D9   DIO_CHANNEL(GPIOD, 9)   /* GPIOD Pin 9  */
#define DIO_CHANNEL_D10  DIO_CHANNEL(GPIOD, 10)  /* GPIOD Pin 10 */
#define DIO_CHANNEL_D11  DIO_CHANNEL(GPIOD, 11)  /* GPIOD Pin 11 */
#define DIO_CHANNEL_D12  DIO_CHANNEL(GPIOD, 12)  /* GPIOD Pin 12 */
#define DIO_CHANNEL_D13  DIO_CHANNEL(GPIOD, 13)  /* GPIOD Pin 13 */
#define DIO_CHANNEL_D14  DIO_CHANNEL(GPIOD, 14)  /* GPIOD Pin 14 */
#define DIO_CHANNEL_D15  DIO_CHANNEL(GPIOD, 15)  /* GPIOD Pin 15 */

/* ===============================
 *  Definition of DIO Driver Data Types
 * =============================== */
/**********************************************************
 * @typedef Dio_ChannelType
 * @brief Data type for a DIO channel
 * @details This type defines a specific GPIO pin.
 **********************************************************/
typedef uint8 Dio_ChannelType;

/**********************************************************
 * @typedef Dio_PortType
 * @brief Data type for a DIO port
 * @details This type defines a specific GPIO port.
 **********************************************************/
typedef uint16 Dio_PortType;

/**********************************************************
 * @typedef Dio_LevelType
 * @brief Data type for the logic level of a DIO channel
 * @details The logic levels can be HIGH (1) or LOW (0).
 **********************************************************/
typedef uint8 Dio_LevelType;

/**********************************************************
 * @typedef Dio_PortLevelType
 * @brief Data type for the logic level of a DIO port
 * @details A port can have multiple channels, so its logic level 
 *          may represent a combination of several channels' logic levels.
 **********************************************************/
typedef uint16 Dio_PortLevelType;

/**********************************************************
 * @struct Dio_ChannelGroupType
 * @brief Structure to define a group of DIO channels
 * @details Used to manipulate a group of channels together.
 **********************************************************/
typedef struct {
    Dio_PortType port;        /**< The port of the DIO group */
    uint8 offset;             /**< The offset of the first bit in the group */
    uint8 mask;               /**< The bitmask for the channels in the group */
} Dio_ChannelGroupType;

/* ===============================
 *  Declaration of DIO Driver API Functions
 * =============================== */
/**********************************************************
 * @brief Reads the state of a DIO channel
 * @param[in] ChannelId The ID of the DIO channel to read
 * @return The logic level of the channel (STD_HIGH or STD_LOW)
 **********************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

/**********************************************************
 * @brief Writes a logic level to a DIO channel
 * @param[in] ChannelId The ID of the DIO channel to write to
 * @param[in] Level The logic level to write to the channel (STD_HIGH or STD_LOW)
 **********************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);

/**********************************************************
 * @brief Reads the state of a DIO port
 * @param[in] PortId The ID of the DIO port to read
 * @return The logic level of the entire port (including multiple channels)
 **********************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);

/**********************************************************
 * @brief Writes a logic level to a DIO port
 * @param[in] PortId The ID of the DIO port to write to
 * @param[in] Level The logic level to write to the entire port (all channels)
 **********************************************************/
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);

/**********************************************************
 * @brief Reads the logic level of a group of DIO channels
 * @param[in] GroupIdPtr A pointer to the group configuration
 * @return The logic level of the group of channels
 **********************************************************/
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* GroupIdPtr);

/**********************************************************
 * @brief Writes a logic level to a group of DIO channels
 * @param[in] GroupIdPtr A pointer to the group configuration
 * @param[in] Level The logic level to write to the group of channels
 **********************************************************/
void Dio_WriteChannelGroup(const Dio_ChannelGroupType* GroupIdPtr, Dio_PortLevelType Level);

/**********************************************************
 * @brief Retrieves the version information of the DIO Driver
 * @param[out] VersionInfo A pointer to the Std_VersionInfoType structure to receive version information
 **********************************************************/
void Dio_GetVersionInfo(Std_VersionInfoType* VersionInfo);

/**********************************************************
 * @brief Toggles the logic level of a DIO channel
 * @param[in] ChannelId The ID of the DIO channel to toggle
 * @return The new logic level of the channel after the toggle
 **********************************************************/
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);

#endif /* DIO_H */
