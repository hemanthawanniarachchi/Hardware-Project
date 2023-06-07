/*
 * StepperMotor.c
 *
 * Created: 5/12/2022 1:03:54 PM
 *  Author: asus
 */ 
#include "StepperMotorM1.h"

void rotateClockwiseM1(int n)
{
	int period =25;
	for (int i = 0; i < n ; i++)  //clockwise
	{
		PORTD =0x24;
		_delay_ms(period);
		PORTD =0x20;
		_delay_ms(period);
		PORTD =0x30;
		_delay_ms(period);
		PORTD =0x10;
		_delay_ms(period);
		PORTD =0x18;
		_delay_ms(period);
		PORTD =0x08;
		_delay_ms(period);
		PORTD =0x0C;
		_delay_ms(period);
		PORTD =0x04;
		_delay_ms(period);
		PORTD =0x24;
	}
	
	
}


void initializeStepperM1()
{
	DDRD |= 00111100;
}