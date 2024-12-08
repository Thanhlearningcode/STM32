/***************************************************************************
 * @file    Kernel.c
 * @brief 	Dinh nghia cac hàm va cau tru lien quan toi kernel
 * @details File nay dinh nghia cac ham cho viec dieu khien kernel
 * @version 1.0
 * @date    2024-10-07
 * @author  Nguyen Van Thanh
 * @contact https://thanhlearningcode.github.io/Myprofile/
 ***************************************************************************/
 /* Include Library */
 #include "Kernel.h"
/* Number of Thread */
	tcbTypedef tcbs[VT_NUM_THREAD];
/* Current Pointer of Thread*/
	tcbTypedef *currentPointer;
/* Memory for Stack */
uint32_t TCB_STACK[VT_NUM_THREAD][VT_STACK_SIZE];
/* Set timer for Systick Timer */
uint32_t Millis_Second;
 /**************************************************************************
 * @brief   Khoi tao stack
 * @details Ham nay khoi tao stack cho tung thread
 * @param   i Thread thu i
 **************************************************************************/
void VT_Kernel_Stack_Init(uint8_t Stack){
/* Set StackPointer to last data which push in stack */
	tcbs[Stack].=

}
 