/*
 * StepperMotor.c
 *
 * Created: 5/12/2022 1:03:54 PM
 *  Author: asus
 */ 
#include "StepperMotorM2.h"

void rotateClockwiseM2(int n)
{
	int period =50;
	for (int i = 0; i < n ; i++)  //clockwise
	{
		PORTB =0x90;
		_delay_ms(period);
		PORTB =0x80;
		_delay_ms(period);
		PORTB =0xC0;
		_delay_ms(period);
		PORTB =0x40;
		_delay_ms(period);
		PORTB =0x60;
		_delay_ms(period);
		PORTB =0x20;
		_delay_ms(period);
		PORTB =0x30;
		_delay_ms(period);
		PORTB =0x10;
		_delay_ms(period);
		PORTB =0x90;
	}
	
	
}

void rotateAntiClockwiseM2(int n)
{
	int period =50;
	for (int i = 0; i < n ; i++)  //clockwise
	{
		PORTB =0x90;
		_delay_ms(period);
		PORTB =0x10;
		_delay_ms(period);
		PORTB =0x30;
		_delay_ms(period);
		PORTB =0x20;
		_delay_ms(period);
		PORTB =0x60;
		_delay_ms(period);
		PORTB =0x40;
		_delay_ms(period);
		PORTB =0xC0;
		_delay_ms(period);
		PORTB =0x80;
		_delay_ms(period);
		PORTB =0x90;
	}
	
	
}

void initializeStepperM2()
{
	DDRB |= 11110000;
}