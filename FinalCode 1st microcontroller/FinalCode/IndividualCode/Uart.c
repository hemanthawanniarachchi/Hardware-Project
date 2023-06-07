/*
 * Uart.c
 *
 * Created: 5/13/2022 8:11:47 AM
 *  Author: asus
 */

#include "Uart.h" 

void InitializationUart()
{
	int UBRR_value=25; //25 gives u 0.2% error (less than 3%)
	UBRRH =(unsigned char)(UBRR_value >> 8);
	UBRRL =(unsigned char)UBRR_value;
	UCSRB =(1 << RXEN) | (1 << TXEN);
	UCSRC |= (1 << USBS ) | (3 << UCSZ0) ;
}

void sentData(int x)
{
	while(!(UCSRA & (1 << UDRE)) );
	UDR = x;
}

int getData()
{
	while(!(UCSRA & (1 << RXC)) );
	int x =UDR ;
	return x;
}