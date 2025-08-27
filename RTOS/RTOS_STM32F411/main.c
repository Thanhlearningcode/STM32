#include "kernel.h"                  // Device header
volatile int i0,i1,i2;
#define QUANTA 1
void task0(){
		while(1){
				i0++;
	}
}
void task1(){
		while(1){
				i1++;
	}
}
void task2(){
		while(1){
				i2++;
	}
}

int main(){
	osKernelInit();
	osKernelAddThread(task0,task1,task2);
	osKernelLaunch(QUANTA);
	while(1){
	
	}
}