/**********************************************************
 * @file main.c
 * @brief Main Application File for Testing the DIO Driver
 * @details This file contains the main application that 
 *          continuously reads the button state and controls 
 *          the LED based on the button press, utilizing the 
 *          Digital Input/Output (DIO) driver.
 * 
 * @version 1.0
 * @date 2024-11-7
 * @author Nguyen Van Thanh
 **********************************************************/

#include "Dio.h" 


int main(int argc, char* argv[])
{
    /* Define the DIO channels for LED and Button */
    Dio_ChannelType ledChannel = DIO_CHANNEL_LED;       /**< LED channel */
    Dio_ChannelType buttonChannel = DIO_CHANNEL_BUTTON;  /**< Button channel */

   
    while (1) 
    {
        /* Read the current state of the button */
        Dio_LevelType buttonState = Dio_ReadChannel(buttonChannel);

        /* Check if the button is pressed (button state is HIGH) */
        if (buttonState == STD_HIGH) 
        {
            /* Turn ON the LED if the button is pressed */
            Dio_WriteChannel(ledChannel, STD_HIGH);
        } 
        else 
        {
            /* Turn OFF the LED if the button is not pressed */
            Dio_WriteChannel(ledChannel, STD_LOW);
        }
    }

   
								return 0;
}
