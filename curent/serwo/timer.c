#include <LPC21xx.H>
#include "timer.h"

#define TIMER_ENABLE (1<<0)
#define TIMER_RESET (1<<1)
#define MR0_RESET (1<<1)
#define MR0_INTERRUPT (1<<0)

void InitTimer0(void)
{
	T0TCR = (T0TCR | TIMER_ENABLE); // aktywacja timeru 0
}

void WaitOnTimer0(unsigned int uiTime)
{
	T0TCR = (T0TCR | TIMER_RESET);//wlaczenie resetowania  timer0
	T0TCR = (T0TCR & ~TIMER_RESET);//wylaczenie resetowania
	while(T0TC<(15*uiTime))//czeka az zegar dojdzie do przekazanej wartosci
	{}
}

void InitTimer0Match0(unsigned int iDelayTime)
{
	T0MR0 = (iDelayTime*15);//czas który ma osiagnac timer
	T0MCR = (MR0_RESET | MR0_INTERRUPT | T0MCR);// wlaczenie resetu, przerwania 
	T0TCR = T0TCR | TIMER_RESET; //wlaczenie resetu zegara
	T0TCR = T0TCR & ~TIMER_RESET; //wylaczenie resetu zegara
	T0TCR = T0TCR | TIMER_ENABLE; // aktywacja timeru 0
}

void WaitOnTimer0Match0(){
	while((T0IR & MR0_INTERRUPT) == 0){} //czekanie az Timer0 osiagnie odp wartosc
	T0IR |= MR0_INTERRUPT;	 // wyzerowanie flagi przerwania
}
