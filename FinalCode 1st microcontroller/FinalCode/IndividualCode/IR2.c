/*
 * IR2.c
 *
 * 
 */ 

#include "IR2.h"
void IR2_Initialize(){
	
		PORTD &= ~(1<<3);
	
}
int IR2_checking(){
	int n2;
	
	if((PIND & 0x08) != 0)    // read PIND.3
	{
		n2=1;
	}
	else{
		n2=0;
	}
	return n2;
}
