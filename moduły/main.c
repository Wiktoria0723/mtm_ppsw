
#include "led.h"
#include "keyboard.h"




void Delay(int DelayTime){
	int TimeScale=12000; 
	int i;
	int Iterations=TimeScale*DelayTime; 
	for(i=0;i<Iterations;i++){
	}
}




int main(void){
	LedInit();
	KeyboardInit();
	Delay(100);
	while(1){
		switch (eKeyboardRead()){
		case BUTTON_1:
			LedStepRight();
			break;
		case BUTTON_2:
			LedStepLeft();
			break;
		default:
			break;
		}
	}
}
