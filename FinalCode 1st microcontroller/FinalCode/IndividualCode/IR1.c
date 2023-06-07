/*
 * IR1.c
 *
 * 
 */ 
#include "IR1.h"
void IR1_Initialize(){
	PORTD &= ~(1<<2);
}

int IR1_checking(){
	int n1;
	
	if((PIND & 0x04) != 0)    // read PIND.2
		{
			n1=1;
		}
	else{
			n1=0;
	}
return n1;
}
