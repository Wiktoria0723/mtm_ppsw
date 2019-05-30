#include <LPC21xx.H>
#include "keyboard.h"
#include "servo.h"


/**********************************************/
int main () {
	
	KeyboardInit();
	ServoInit(50);
	ServoGoTo(24);
	ServoCalib();
	ServoGoTo(12);
	

	while(1){
	 	switch( eKeyboardRead() ) {
			case BUTTON_1:
				ServoCalib();
				break;
			case BUTTON_2:
				ServoGoTo(12);
				break;
			case BUTTON_3:
				ServoGoTo(24);
				break;
			case BUTTON_4:
				ServoGoTo(36);
				break;
			case RELEASED: {}
			default: {}
		}
	}
}
