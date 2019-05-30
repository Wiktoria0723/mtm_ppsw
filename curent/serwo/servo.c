#include <LPC21xx.H>
#include "led.h"
#include "timer_interupt.h"
#include "servo.h"

#define DETECTOR_bm (1 << 10)

enum ServoState {IDLE, CALLIB, IN_PROGRESS};
enum DetectorState {ACTIVE, INACTIVE};

struct Servo {
	
	enum ServoState eState;
	unsigned int uiCurrentPosition;
	unsigned int uiDesiredPosition;
};

struct Servo sServo;

void DetectorInit (void) {
	
	IO0DIR = IO0DIR & ~DETECTOR_bm;
}

enum DetectorState eReadDetector (void) {
	
	if( 0 == (IO0PIN & DETECTOR_bm) ){
		return ACTIVE;
	}
	else {
		return INACTIVE;
	}
}

void Automat (void) {
	
	switch( sServo.eState ) {
		case IDLE:
			if( sServo.uiCurrentPosition != sServo.uiDesiredPosition ) {
				sServo.eState = IN_PROGRESS;
			} 
			break;
		case CALLIB:
			if( 0 == eReadDetector() ) {
				sServo.eState = IDLE;
				sServo.uiCurrentPosition = 0;
				sServo.uiDesiredPosition = 0;
			} else {
				LedStepLeft();
			}
			break;
		case IN_PROGRESS:
			if( sServo.uiCurrentPosition < sServo.uiDesiredPosition ) {
				LedStepRight();
				sServo.uiCurrentPosition++;
			} 
			else if ( sServo.uiCurrentPosition > sServo.uiDesiredPosition ) {
				LedStepLeft();
				sServo.uiCurrentPosition--;
			}
			else {
				sServo.eState = IDLE;
			}
			break;
		default: {}
	}
}

void ServoCalib (void) {
	
	while(sServo.eState != IDLE) {}
	sServo.eState = CALLIB;
}

void ServoGoTo (unsigned int uiPosition) {
	
	while(sServo.eState != IDLE) {}
	sServo.uiDesiredPosition = uiPosition;
	sServo.eState = IN_PROGRESS;
}

void ServoInit (unsigned int uiServoFrequency) {
	
	ServoCalib();
	LedInit();
	Timer0Interrupts_Init( (1000000 / uiServoFrequency), &Automat );
}
