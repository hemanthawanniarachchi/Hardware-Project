/*
 * Stepper1.c
 * Measuring
 * 
 */ 
#include "Stepper1.h"

void Stepper1_Initialize(){
	
	DDRC |=0xF0;		/* Make PORTC higher pins as output */
	
}

void Stepper1_rotate(){
	int period=1;
	PORTC = 0x90;
	_delay_ms(period);
	PORTC = 0xC0;
	_delay_ms(period);
	PORTC = 0x60;
	_delay_ms(period);
	PORTC = 0x30;
	_delay_ms(period);
}