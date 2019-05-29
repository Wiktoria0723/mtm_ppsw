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
	enum LedState{LED_LEFT,LED_RIGHT};
	enum LedState eLedState = LED_LEFT;
	char cCounter=0;
	LedInit();
	

	while(1){
		cCounter++;
		switch(eLedState){
			case LED_LEFT:
				if(cCounter == 4){
					cCounter = 0;
					eLedState = LED_RIGHT;	
				}
				else {
					LedStepLeft();
					eLedState = LED_LEFT;	
				}
				break;
			case LED_RIGHT:
				if(cCounter == 4){
					cCounter = 0;
					eLedState = LED_LEFT;
				}
				else {
					LedStepRight();
					eLedState = LED_RIGHT;
				}
				break;
		}
		//Delay(500);
	}
}


