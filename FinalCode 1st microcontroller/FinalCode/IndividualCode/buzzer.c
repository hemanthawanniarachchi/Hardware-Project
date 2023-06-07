/*
 * Buzzer.c
 *
 * 
 *  
 */ 

#include "buzzer.h"

void BUZZER()
{
	DDRC |= 1<<3;           
	
	for(int i=0;i<3;i++)
	{
		
		PORTC =0x08;
		_delay_ms(5);
		break;
		//PORTC &= ~(1<<3);
		//_delay_ms(1000);
	}
	PORTC&=~(1<<3);
    
}