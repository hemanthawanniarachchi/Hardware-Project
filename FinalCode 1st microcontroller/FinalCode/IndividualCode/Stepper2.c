/*
 * Stepper2.c
 * Cutting
 * 
 */ 

#include "Stepper2.h"

void Stepper2_Initialize(){

	DDRB|= 0x0F;		/* Make PORTD lower pins as output */
	
	
}
void Stepper2_rotatedown(){
	    int period=100;
		/*move blade down*/
		for(int i=0;i<1;i++)
		{
			PORTB = 0x09;
			_delay_ms(period);
			PORTD = 0x0C;
			_delay_ms(period);
			PORTD = 0x06;
			_delay_ms(period);
			PORTD = 0x03;
			_delay_ms(period);
		}
		
}
 void Stepper1_rotateUp(){
	        int period=100;
			/* move blade down*/
			for(int i=0;i<1;i++)
			{
				PORTD = 0x09;
				_delay_ms(period);
				PORTD = 0x03;
				_delay_ms(period);
				PORTD = 0x06;
				_delay_ms(period);
				PORTD = 0x0C;
				_delay_ms(period);
			}
			
}