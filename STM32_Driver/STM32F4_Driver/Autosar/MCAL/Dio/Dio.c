/**********************************************************
 * @file Dio.c
 * @brief Digital Input/Output (DIO) Driver Source File
 * @details This file contains the implementation of the DIO Driver APIs 
 *          according to the AUTOSAR standard for STM32F103. This driver 
 *          provides functionality to read and write the logic levels of 
 *          GPIO pins and GPIO ports in the STM32F103 microcontroller.
 * 
 * @version 1.0
 * @date 2024-11-7
 * @author Nguyen Van Thanh
 **********************************************************/

/* ===============================
 *           Includes
 * =============================== */
#include "Dio.h"

/* ===============================
 *           Function Definitions
 * =============================== */

/**********************************************************
 * @brief Reads the logic state of a DIO channel
 * @details
 * This function reads the logic state of a GPIO pin (DIO Channel) 
 * on the STM32F103 microcontroller. It determines the GPIO port and pin 
 * based on the ChannelId and returns the logic level (HIGH or LOW) 
 * of the corresponding GPIO pin.
 *
 * @param[in] ChannelId
 *            The ID of the DIO channel to read (identified by the DIO_CHANNEL macro)
 *
 * @return Dio_LevelType
 *         The logic state of the channel:
 *         - STD_HIGH: If the pin has a high logic level (Vcc)
 *         - STD_LOW: If the pin has a low logic level (GND)
 **********************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId) {
    GPIO_TypeDef* GPIO_Port;    /* Pointer to the structure defining the GPIO port */
    uint16_t GPIO_Pin;          /* Corresponding GPIO pin number */

    /* Step 1: Determine the GPIO port using the DIO_GET_PORT macro */
    GPIO_Port = DIO_GET_PORT(ChannelId);
    
    /* Check if the GPIO port is valid */
    if (GPIO_Port == NULL) {
        return STD_LOW;  /* Return STD_LOW if the port is not valid */
    }

    /* Step 2: Determine the GPIO pin using the DIO_GET_PIN macro */
    GPIO_Pin = DIO_GET_PIN(ChannelId);

    /* Step 3: Read the logic state of the corresponding GPIO pin */
    if (GPIO_ReadInputDataBit(GPIO_Port, GPIO_Pin) == Bit_SET) {
        return STD_HIGH;  /* Return STD_HIGH if the pin has a high logic level */
    } else {
        return STD_LOW;   /* Return STD_LOW if the pin has a low logic level */
    }
}


/**********************************************************
 * @brief Writes the logic state to a DIO channel
 * @details
 * This function writes the logic state (HIGH or LOW) to a GPIO pin 
 * (DIO Channel) on the STM32F103 microcontroller. It determines the 
 * GPIO port and pin based on the ChannelId and then writes the specified 
 * logic level to the pin.
 *
 * @param[in] ChannelId
 *            The ID of the DIO channel to write to (identified by the DIO_CHANNEL macro)
 * 
 * @param[in] Level
 *            The logic state to write to the DIO channel (STD_HIGH or STD_LOW)
 **********************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level) {
    GPIO_TypeDef* GPIO_Port;    /* Pointer to the structure defining the GPIO port */
    uint16_t GPIO_Pin;          /* Corresponding GPIO pin number */

    /* Step 1: Determine the GPIO port using the DIO_GET_PORT macro */
    GPIO_Port = DIO_GET_PORT(ChannelId);
    
    /* Check if the GPIO port is valid */
    if (GPIO_Port == NULL) {
        return;  /* If the port is not valid, exit the function */
    }

    /* Step 2: Determine the GPIO pin using the DIO_GET_PIN macro */
    GPIO_Pin = DIO_GET_PIN(ChannelId);

    /* Step 3: Write the logic state to the corresponding GPIO pin */
    if (Level == STD_HIGH) {
        GPIO_SetBits(GPIO_Port, GPIO_Pin);  /* Set the GPIO pin to HIGH */
    } else {
        GPIO_ResetBits(GPIO_Port, GPIO_Pin);  /* Set the GPIO pin to LOW */
    }
}


/**********************************************************
 * @brief Reads the logic state of an entire DIO port
 * @details
 * This function reads the logic state of all the GPIO pins in a GPIO port 
 * on the STM32F103 microcontroller. The GPIO port is identified by the PortId, 
 * and the entire state of the port is returned as a 16-bit value.
 *
 * @param[in] PortId
 *            The ID of the DIO port to read (DIO_PORT_A, DIO_PORT_B, ...)
 *
 * @return Dio_PortLevelType
 *         The logic state of the entire DIO port (including multiple GPIO pins)
 **********************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId) {
    /* Step 1: Use the DIO_GET_PORT macro to determine the GPIO port */
    GPIO_TypeDef* GPIO_Port = DIO_GET_PORT(PortId);

    /* Check if the GPIO port is valid */
    if (GPIO_Port == NULL) {
        return 0;  /* Return 0 if the PortId is not valid */
    }

    /* Step 2: Read and return the state of the entire GPIO port */
    return (Dio_PortLevelType)GPIO_ReadInputData(GPIO_Port);
}


/**********************************************************
 * @brief Writes the logic state to an entire DIO port
 * @details
 * This function writes a 16-bit logic state value to all the GPIO pins in a 
 * GPIO port on the STM32F103 microcontroller. The GPIO port is identified 
 * by the PortId, and the logic state to write is passed in as the Level parameter.
 *
 * @param[in] PortId
 *            The ID of the DIO port to write to (DIO_PORT_A, DIO_PORT_B, ...)
 *
 * @param[in] Level
 *            The logic state value to write to the entire GPIO port
 **********************************************************/
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level) {
    /* Use the DIO_GET_PORT macro to determine the GPIO port */
    GPIO_TypeDef* GPIO_Port = DIO_GET_PORT(PortId);

    /* Check if the GPIO port is valid */
    if (GPIO_Port == NULL) {
        return;  /* If the port is not valid, exit the function */
    }

    /* Write the logic state to the entire GPIO port */
    GPIO_Write(GPIO_Port, Level);
}


/**********************************************************
 * @brief Reads the logic state of a DIO channel group
 * @details
 * This function reads the logic state of a group of GPIO pins 
 * (DIO Channel Group) on a GPIO port, identified through the GroupIdPtr structure. 
 * The result is shifted and returned based on the group’s mask and offset.
 *
 * @param[in] GroupIdPtr
 *            Pointer to the DIO group structure (contains port, mask, and offset information)
 *
 * @return Dio_PortLevelType
 *         The logic state of the DIO channel group
 **********************************************************/
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* GroupIdPtr) {
    /* Use the DIO_GET_PORT macro to determine the GPIO port */
    GPIO_TypeDef* GPIO_Port = DIO_GET_PORT(GroupIdPtr->port);

    /* Check if the GPIO port is valid */
    if (GPIO_Port == NULL) {
        return 0;  /* Return 0 if the port is not valid */
    }

    /* Read the logic state of the entire GPIO port */
    uint16_t portData = GPIO_ReadInputData(GPIO_Port);

    /* Apply the mask and offset to extract the value of the channel group */
    return (Dio_PortLevelType)((portData & GroupIdPtr->mask) >> GroupIdPtr->offset);
}


/**********************************************************
 * @brief Writes the logic state to a DIO channel group
 * @details
 * This function writes a logic state value to a group of GPIO pins 
 * (DIO Channel Group) on a GPIO port, identified through the GroupIdPtr structure. 
 * The value is written to the group of pins specified by the mask and offset.
 *
 * @param[in] GroupIdPtr
 *            Pointer to the DIO group structure (contains port, mask, and offset information)
 *
 * @param[in] Level
 *            The logic state value to write to the DIO channel group
 **********************************************************/
void Dio_WriteChannelGroup(const Dio_ChannelGroupType* GroupIdPtr, Dio_PortLevelType Level) {
    /* Use the DIO_GET_PORT macro to determine the GPIO port */
    GPIO_TypeDef* GPIO_Port = DIO_GET_PORT(GroupIdPtr->port);

    /* Check if the GPIO port is valid */
    if (GPIO_Port == NULL) {
        return;  /* If the port is not valid, exit the function */
    }

    /* Read data from the GPIO port */
    uint16_t portData = GPIO_ReadInputData(GPIO_Port);

    /* Clear the bits in the group, then write the new value to the group */
    portData &= ~(GroupIdPtr->mask);  /* Clear the bits corresponding to the mask */
    portData |= ((Level << GroupIdPtr->offset) & GroupIdPtr->mask);  /* Write the new value to the group */
    
    /* Write the modified data back to the GPIO port */
    GPIO_Write(GPIO_Port, portData);
}


/**********************************************************
 * @brief Retrieves the version information of the DIO Driver
 * @details This function returns the version information of the DIO driver.
 * 
 * @param[out] VersionInfo
 *            Pointer to the Std_VersionInfoType structure to receive the version information
 **********************************************************/
void Dio_GetVersionInfo(Std_VersionInfoType* VersionInfo) {
    /* Assign version information */
    VersionInfo->vendorID = 0x1234;  /* Example Vendor ID */
    VersionInfo->moduleID = 0x5678;  /* Example DIO Module ID */
    VersionInfo->sw_major_version = 1;
    VersionInfo->sw_minor_version = 0;
    VersionInfo->sw_patch_version = 0;
}

/**********************************************************
 * @brief Toggles the logic state of a DIO channel
 * @details This function toggles the logic state of a GPIO pin (HIGH to LOW or vice versa).
 * 
 * @param[in] ChannelId
 *            The ID of the DIO channel to toggle
 * 
 * @return Dio_LevelType
 *         The new logic state of the channel after toggling
 **********************************************************/
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId) {
    Dio_LevelType currentLevel = Dio_ReadChannel(ChannelId);

    /* Toggle the logic state of the channel */
    if (currentLevel == STD_HIGH) {
        Dio_WriteChannel(ChannelId, STD_LOW);
        return STD_LOW;
    } else {
        Dio_WriteChannel(ChannelId, STD_HIGH);
        return STD_HIGH;
    }
}
