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
enum LedState{STATE0, STATE1, STATE2, STATE3, STATE4, STATE5};
	enum LedState eLedState = STATE0;
	LedInit();
	

	while(1){
		switch(eLedState){
			case STATE0:
				eLedState = STATE1;
				LedStepRight();
				break;
			case STATE1:
				eLedState = STATE2;
				LedStepRight();
				break;
			case STATE2:
				eLedState = STATE3;
				LedStepRight();
				break;
			case STATE3:
				eLedState = STATE4;
				LedStepLeft();
				break;
			case STATE4:
				eLedState = STATE5;
				LedStepLeft();
				break;
			case STATE5:
				eLedState = STATE0;
				LedStepLeft();
				break;
		}
		Delay(500);
	}
}
