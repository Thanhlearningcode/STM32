#include "Lcd1602.h"
#include "stm32f411xe.h"

char *p = "thanhdeptrai";

int main() {
    Lcd_Init();        
    Lcd_Put_Cur(0, 0);  // Set cursor to the first row, first column

    while (1) {
            Lcd_Put_Cur(0, 1);  // Set cursor to the second row, first column
						Lcd_Send_String(p); // Send the string to the LCD
    }
}