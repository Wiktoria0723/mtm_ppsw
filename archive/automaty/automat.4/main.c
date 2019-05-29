# include "keyboard.h"
# include "led.h"


void Delay(int DelayTime){
	int TimeScale=12000; 
	int i;
	int Iterations=TimeScale*DelayTime; 
	for(i=0;i<Iterations;i++){
	}
}

int main(){
	enum LedState{LED_STOP,LED_RIGHT};
	enum LedState eLedState = LED_STOP;
	char cCounter=0;
	LedInit();
	KeyboardInit();

	while(1){
		switch(eLedState){
			case LED_RIGHT:
				if(cCounter > 0 ){
					cCounter--;
					LedStepRight();
					eLedState = LED_RIGHT;
				} else {
					eLedState = LED_STOP;
				}
				break;
			case LED_STOP:
				if(eKeyboardRead() == BUTTON_1){
					cCounter = 3;
					eLedState = LED_RIGHT;
				} else {
					eLedState = LED_STOP;
				}
				break;
		}
		Delay(100);
	}
}
