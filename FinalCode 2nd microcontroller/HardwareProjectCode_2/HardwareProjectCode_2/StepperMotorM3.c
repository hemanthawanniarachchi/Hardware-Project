/*
 * StepperMotor.c
 * Created: 5/12/2022 1:03:54 PM
 */ 


#include "StepperMotorM3.h"

void rotateClockwiseM3(int n)
{
	int period =25;
	for (int i = 0; i < n ; i++)  //clockwise
	{
		PORTC =0x24;
		_delay_ms(period);
		PORTC =0x20;
		_delay_ms(period);
		PORTC =0x30;
		_delay_ms(period);
		PORTC =0x10;
		_delay_ms(period);
		PORTC =0x18;
		_delay_ms(period);
		PORTC =0x08;
		_delay_ms(period);
		PORTC =0x0C;
		_delay_ms(period);
		PORTC =0x04;
		_delay_ms(period);
		PORTC =0x24;
	}
	
	
}


void rotateAntiClockwiseM3(int n)
{
	int period =25;
	for (int i = 0; i < n ; i++)  //clockwise
	{
		PORTC =0x24;
		_delay_ms(period);
		PORTC =0x04;
		_delay_ms(period);
		PORTC =0x0C;
		_delay_ms(period);
		PORTC =0x08;
		_delay_ms(period);
		PORTC =0x18;
		_delay_ms(period);
		PORTC =0x10;
		_delay_ms(period);
		PORTC =0x30;
		_delay_ms(period);
		PORTC =0x20;
		_delay_ms(period);
		PORTC =0x24;
	}
	
	
}




	
void initializeStepperM3()
{
	DDRC |= 00111100;
}