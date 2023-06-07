/*
 * StepperMotor.c
 *
 * Created: 5/12/2022 1:03:54 PM
 *  Author: asus
 */ 
#include "StepperMotor.h"

void rotateClockwise(int n)
{
	int period =500;
	for (int i = 0; i < n ; i++)  //clockwise
	{
		PORTD =0x09;
		_delay_ms(period);
		PORTD =0x08;
		_delay_ms(period);
		PORTD =0x0C;
		_delay_ms(period);
		PORTD =0x04;
		_delay_ms(period);
		PORTD =0x06;
		_delay_ms(period);
		PORTD =0x02;
		_delay_ms(period);
		PORTD =0x03;
		_delay_ms(period);
		PORTD =0x01;
		_delay_ms(period);
		PORTD =0x09;
	}
	
	
}

void rotateAntiClockwise(int n)
{
	int period =500;
	for (int i = 0; i < n ; i++)  //clockwise
	{
		PORTD =0x09;
		_delay_ms(period);
		PORTD =0x01;
		_delay_ms(period);
		PORTD =0x03;
		_delay_ms(period);
		PORTD =0x02;
		_delay_ms(period);
		PORTD =0x06;
		_delay_ms(period);
		PORTD =0x04;
		_delay_ms(period);
		PORTD =0x0C;
		_delay_ms(period);
		PORTD =0x08;
		_delay_ms(period);
		PORTD =0x09;
	}
	
	
}

void initializeStepperM()
{
	DDRD = 0x0F;
}