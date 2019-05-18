# include "keyboard.h"
# include "led.h"


void Delay(int DelayTime){
	int TimeScale=12000; 
	int i;
	int Iterations=TimeScale*DelayTime; 
	for(i=0;i<Iterations;i++){
	}
}

int main(void)
{
	
enum LedState{LED_LEFT,LED_RIGHT};
enum LedState eLedState = LED_LEFT;
LedInit();	
	
while(1){
switch(eLedState){
case LED_LEFT:

eLedState = LED_RIGHT;
LedStepRight();
break;
case LED_RIGHT:

eLedState = LED_LEFT;
LedStepLeft();
break;

}
Delay(500);
}
}
