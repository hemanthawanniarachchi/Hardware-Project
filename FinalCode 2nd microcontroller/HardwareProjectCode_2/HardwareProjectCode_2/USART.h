/*
 * USART.h

 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>
#include <stdlib.h>



void USART_Init( unsigned int ubrr);
void USART_Transmit( unsigned char data );
void USART_TxString(char *ptr_string);
void USART_TxStringln(char *ptr_string);
void USART_TxNumber(int32_t number,uint8_t dtype);
uint8_t USART_ReciveWait(char*wait,int16_t timeout ,uint8_t deleteWait);

char num[]="";
//#define rxshiftNum 50
char rchar=0;

void USART_Init( unsigned int ubrr)
{	ubrr=F_CPU/16/ubrr-1;
	/*Set baud rate */
	UBRRH = (unsigned char)(ubrr>>8);
	UBRRL = (unsigned char)ubrr;
	/*Enable receiver and transmitter */
	UCSRB = (1<<RXEN)|(1<<TXEN)|(1<<RXCIE);
	/* Set frame format: 8data, 1stop bit */
	UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
	sei();
}

void USART_Transmit( unsigned char data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) );
	
	/* Put data into buffer, sends the data */
	UDR = data;
}

void USART_TxString(char *ptr_string)
{
	while(*ptr_string)
	USART_Transmit(*ptr_string++);// Loop through the string and transmit char by char
}
void USART_TxStringln(char *ptr_string)
{
	while(*ptr_string){
		USART_Transmit(*ptr_string++);// Loop through the string and transmit char by char
	}
	USART_Transmit(13);
	USART_Transmit(10);
}

void USART_TxNumber(int32_t number,uint8_t dtype){
	
	itoa(number,num,dtype);
	USART_TxString(num);
	
}



ISR(USART_RXC_vect){
	
	rchar=UDR;
	
	
}


