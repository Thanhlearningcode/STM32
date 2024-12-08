#include "stm32f411xe.h"

#include "TIMERF4.h"
#include "HSCR_04.h"
int main() {
    // Kh?i t?o c�c module c?n thi?t
    TiM1_init();
  
    // C?u h�nh PWM (gi? d?nh r?ng b?n d� d?nh nghia d�ng)
    Configure_PMW();  

    uint32_t pulse_length;
    float distance;
    HCSR04_Init();
	   TIM4->CCR1 = 1000;
    while(1) {
  
        Delay(5);

       if (distance > 100) {
            TIM4->CCR1 = 1000;}
        else {
          TIM4->CCR1 = 0; // �i?u ch?nh gi� tr? PWM n?u c?n
      }

        Delay(5);
    }
}
