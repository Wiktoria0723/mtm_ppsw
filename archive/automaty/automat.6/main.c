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
	enum LedState{LED_STOP,LED_RIGHT, LED_LEFT};
	enum LedState eLedState = LED_STOP;
	LedInit();
	KeyboardInit();

	while(1){
		switch(eLedState){
			case LED_RIGHT:
				if(eKeyboardRead() == BUTTON_2)
				{
					eLedState = LED_STOP;
				}else{
					LedStepRight();
					eLedState = LED_RIGHT;
				}
				break;

			case LED_LEFT:
				if(eKeyboardRead() == BUTTON_2)
				{
					eLedState = LED_STOP;
				}else{
					LedStepLeft();
					eLedState = LED_LEFT;
				}
				break;
			case LED_STOP:
				if(eKeyboardRead() == BUTTON_1){
					eLedState = LED_LEFT;
				} else if(eKeyboardRead() == BUTTON_3){
					eLedState = LED_RIGHT;
				} else {
					eLedState = LED_STOP;
				}
				break;
		}
		Delay(100);
	}
}
