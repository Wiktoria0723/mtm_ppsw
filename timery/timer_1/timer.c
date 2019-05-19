#include <LPC21XX.H>
#include "timer.h"

#define TCR_EN 0x1
#define TCR_RST 0x2

void InitTimer0(void){
	T0TCR |= TCR_EN;
}



void WaitOnTimer0(unsigned int uiTime){
	T0TCR |= TCR_RST;
	T0TCR &= ~TCR_RST;
	T0PR = 0xE;
	while( ((unsigned int)T0TC) < uiTime){};
}

