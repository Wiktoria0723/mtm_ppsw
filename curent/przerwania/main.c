#include "timer_interupt.h"
#include "led.h"
#include "keyboard.h"

#define MULTIPIER 10000

void Automat(){
	enum StateOfDirection {STAY, MOVE_RIGHT, MOVE_LEFT};
	enum StateOfDirection eStateOfDirection = STAY;
	KeyboardInit();
	LedInit();
	switch(eStateOfDirection){
			case STAY:
				if(eKeyboardRead() == BUTTON_1){
					eStateOfDirection = MOVE_LEFT;
				}
				else if(eKeyboardRead() == BUTTON_3){
					eStateOfDirection = MOVE_RIGHT;
				}
				break;		
			case MOVE_RIGHT:
				 if(eKeyboardRead() == BUTTON_2){
						eStateOfDirection = STAY;
					}
				 else{
						LedStepRight();  
					}
					break;
					
		  case MOVE_LEFT:
					if(eKeyboardRead() == BUTTON_2){
						eStateOfDirection = STAY;
					}
					else {
						LedStepLeft();
					}
					break;
				}				
			}			


int main (){
	
	unsigned int iMainLoopCtr;
	Timer0Interrupts_Init(MULTIPIER*25,&Automat); //tak aby byly 4 przerwania na sekunde
	LedInit();
	KeyboardInit();

	while(1){
	 	iMainLoopCtr++;
	}
}
