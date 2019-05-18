#include <LPC21xx.H>


#define LED0_bm (1<<16)
#define LED1_bm (1<<17)
#define LED2_bm (1<<18)
#define LED3_bm (1<<19)

#define S0_bm (1<<4)
#define S1_bm (1<<6)
#define S2_bm (1<<5)
#define S3_bm (1<<7)

void Delay(int DelayTime){
	int TimeScale=12000; 
	int i;
	int Iterations=TimeScale*DelayTime; 
	for(i=0;i<Iterations;i++){
	}
}

// ustawia piny podpiete od LED0 do LED4 na wyjscia
void LedInit(void){
	IO1DIR = IO1DIR | (LED0_bm | LED1_bm | LED2_bm | LED3_bm) ;
	IO1CLR = LED1_bm | LED2_bm | LED3_bm;
	IO1SET =LED0_bm;
}


// zapala jedna diode od led0 do led3 gaszac pozostale
void LedOn(unsigned char ucLedIndeks){
	IO1CLR = LED0_bm | LED1_bm | LED2_bm | LED3_bm;
	switch(ucLedIndeks){
		case 0:
			IO1SET=LED0_bm;
				break;
		case 1:
			IO1SET=LED1_bm;
				break;
		case 2:
			IO1SET=LED2_bm;
				break;
		case 3:
			IO1SET=LED3_bm;
				break;
	}
}

enum KeyboardState {RELEASED, BUTTON_1, BUTTON_2, BUTTON_3, BUTTON_4};


// odczytuje stan przyciskow od S1 do S4
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

// funkja ustawia piny podpiete od S1 do S4 na wejscia
void KeyboardInit(){
	IO0DIR = IO0DIR & ~ ( S0_bm | S1_bm | S2_bm | S3_bm);
}

enum Direction {LEFT, RIGHT};

// przesówa punkt swietlny zgodine z podanym argumentem
void LedStep(enum Direction eDir){
	
	static unsigned int uiDiodeNumber=0;
	if(eDir == LEFT){
		uiDiodeNumber++;
	}
	else{
		uiDiodeNumber--;
	}
	LedOn(uiDiodeNumber%4);
}
	
void LedStepLeft(){
	LedStep(LEFT);
}

void LedStepRight(){
	LedStep(RIGHT);
}

int main()

{
	LedInit();
	KeyboardInit();
	
	while(1){
		switch (eKeyboardRead()){
		case BUTTON_1:
			LedStepRight();
			break;
		case BUTTON_2:
			LedStepLeft();
			break;
		default:
			break;
		}
	}
}
