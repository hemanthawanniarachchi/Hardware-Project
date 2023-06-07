/*
 * Stepper C File
 */ 

//Import Header File
#include "Stepper.h"


//Initialize PORTA lower pins as output
void Stepper_Initialize()
{
	DDRA = 0xF0;	
}



// Rotate Stepper Motor clockwise with Half step sequence 
void Stepper_Rotate()
{
	int period;
	period = 100;	// Set period in between two steps 
	

	PORTA = 0x10;
	_delay_ms(period);
	PORTA = 0x40;
	_delay_ms(period);
	PORTA = 0xC0;
	_delay_ms(period);
	PORTA = 0x80;
	_delay_ms(period);
	PORTA = 0x30;
	_delay_ms(period);
	PORTA = 0x90;
	_delay_ms(period);
	
	
	
}