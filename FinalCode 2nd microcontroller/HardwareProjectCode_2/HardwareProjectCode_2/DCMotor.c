/*
 * DCMotor.c
 *
 * Created: 5/12/2022 11:06:18 AM
 *  Author: asus
 */ 

//Import DC motor header file
 #include "DCMotor.h"

void initializeDCM(){
	DDRC |= (1 << PC0)|(1 << PC1);
	
	DDRB |= (1 << PB3);
	TCCR0 = (1 << WGM00) | (1 << WGM01) | (1 << COM01) | (1 << CS00)|(1 << CS01);
	
}

void startDCMotor(){
	
	OCR0 = 200;
	PORTC |= 0b00000001;
	
}

void stopDCMotor()
{
	PORTC = 0b00000000;
}