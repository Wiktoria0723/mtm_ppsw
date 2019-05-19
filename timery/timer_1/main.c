#include <lpc21xx.h>

#include "led.h"
#include "keyboard.h"
#include "timer.h"


int main(){
	InitTimer0();
	LedInit();
	
	
	while(1){
		LedStepLeft();
		WaitOnTimer0(500000);
	}
}
