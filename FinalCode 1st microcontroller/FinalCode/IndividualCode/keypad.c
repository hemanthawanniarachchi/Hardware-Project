/*
 * 
 *
 * KeyPad- C File
 *  
 */

#include "keypad.h"

unsigned char keypad()
{
	PORTA=0b11111110;
	if((PINA &(1<<PINA4))==0)
	{
		_delay_ms(3);
		return '7';
	}
	else if((PINA & (1<<PINA5))==0)
	{
		_delay_ms(3);
		return '8';
	}
	else if((PINA & (1<<PINA6))==0)
	{
		_delay_ms(3);
		return '9';
	}
	else if((PINA & (1<<PINA7))==0)
	{
		_delay_ms(3);
		return '/';
	}
	
	PORTA=0b11111101;
	if((PINA &(1<<PINA4))==0)
	{
		_delay_ms(3);
		return '4';
	}
	else if((PINA & (1<<PINA5))==0)
	{
		_delay_ms(3);
		return '5';
	}
	else if((PINA & (1<<PINA6))==0)
	{
		_delay_ms(3);
		return '6';
	}
	else if((PINA & (1<<PINA7))==0)
	{
		_delay_ms(3);
		return '*';
	}
	
	PORTA=0b11111011;
	if((PINA &(1<<PINA4))==0)
	{
		_delay_ms(3);
		return '1';
	}
	else if((PINA & (1<<PINA5))==0)
	{
		_delay_ms(3);
		return '2';
	}
	else if((PINA & (1<<PINA6))==0)
	{
		_delay_ms(3);
		return '3';
	}
	else if((PINA & (1<<PINA7))==0)
	{
		_delay_ms(3);
		return '-';
	}
	
	PORTA=0b11110111;
	if((PINA &(1<<PINA4))==0)
	{
		_delay_ms(3);
		return 'C';

	}
	else if((PINA & (1<<PINA5))==0)
	{
		_delay_ms(3);
		return '0';
	}
	else if((PINA & (1<<PINA6))==0)
	{
		_delay_ms(3);
		return '=';
	
	}
	else if((PINA & (1<<PINA7))==0)
	{
		_delay_ms(3);
		return '+';
	}
}
