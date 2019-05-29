#include <lpc21xx.h>
#include "keyboard.h"

#define S0_bm (1<<4)
#define S1_bm (1<<6)
#define S2_bm (1<<5)
#define S3_bm (1<<7)

enum KeyboardState eKeyboardRead(void){
	
	if((IO0PIN&S0_bm) == 0){ 
		return BUTTON_1;
	}
	if((IO0PIN&S1_bm) == 0){
		return BUTTON_2;
	}
	if((IO0PIN&S2_bm) == 0){
		return BUTTON_3;
	}
	if((IO0PIN&S3_bm) == 0){
		return BUTTON_4;
	}
	
		return RELEASED;
}

void KeyboardInit(){
	IO0DIR = IO0DIR & ~ ( S0_bm | S1_bm | S2_bm | S3_bm);
}

