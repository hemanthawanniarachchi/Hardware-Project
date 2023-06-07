/*
 * servo.c
 *
 * 
 *  
 */ 

#include "servo.h"

void servoangle(uint8_t pin){
	
	if (pin)
	{
		for(uint8_t j=0;j<100;j++){
			PORTC|=(1<<2);
			for(uint8_t i=0;i<9;i++){
				_delay_us(100);
			}
			PORTC&=~(1<<2);
			
			
			
			for(uint8_t i=0;i<9;i++){
				_delay_us(100);
			}
		}
	}
	else
	{
		
		for(uint8_t j=0;j<100;j++){
			
			PORTC|=(1<<2);
			for(uint8_t i=0;i<28;i++){
				_delay_us(50);
			}
			PORTC&=~(1<<2);
			
			
			
			for(uint8_t i=0;i<28;i++){
				_delay_us(50);
			}
		}
	}
	
	
	
	
	
}