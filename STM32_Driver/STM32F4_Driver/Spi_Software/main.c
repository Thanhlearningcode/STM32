#include "Spi_Software.h"
uint8_t DataTrans[] = {1,3,9,10,15,19,90};//Data
int main(){
void Spi_Transmit_Init(void);
	while(1)
		{	
			for(int i=0; i<7; i++){
			Spi_Master_Transmit(DataTrans[i]);
			Delay(200);
			}
		}

}
