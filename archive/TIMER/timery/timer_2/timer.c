#include <LPC21XX.H>
#include "timer.h"

#define TCR_EN 		(1<<0)
#define TCR_RST 	(1<<1)
#define MR0_INT 	(1<<0)
#define MR0_RST 	(1<<1)
#define MR0_STOP 	(1<<3)
#define MR0_INT_FLAG (1<<0)

void InitTimer0(void){
	T0TCR |= TCR_EN;
}

void WaitOnTimer0(unsigned int uiTime){
	T0TCR |= TCR_RST;
	T0TCR &= ~TCR_RST;
	T0PR = 0xE;
	while( T0TC < uiTime){};
}

void IInitTimer0Match0(unsigned int iDelayTime){
	T0MR0 = iDelayTime;
	T0MCR |= MR0_RST;
	T0MCR |= MR0_INT;
	
	T0PR = 0xE; 
	
	T0TCR |= TCR_RST;
	T0TCR &= ~TCR_RST;
	T0TCR |= TCR_EN;
}

void WaitOnTimer0Match0(void){
	while ((T0IR & MR0_INT_FLAG) == 0 ){}
	T0IR = MR0_INT_FLAG;
}

