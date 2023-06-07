/*
 * 
 *
 * LCD- C File
 *  
 */ 

#include "LCD.h"



void lcdcmd(unsigned char cmd)
{
	PORTD&=~(1<<RS);
	PORTD&=~(1<<RW);
	LCD=cmd & 0xF0;
	PORTD|=(1<<EN);
	_delay_ms(100);
	PORTD&=~(1<<EN);
	LCD=cmd<<4;
	PORTD|=(1<<EN);
	_delay_ms(100);
	PORTD&=~(1<<EN);
}
void lcddata(unsigned char data)
{
	PORTD|=(1<<RS);
	PORTD&=~(1<<RW);
	LCD=data & 0xF0;
	PORTD|=(1<<EN);
	_delay_ms(100);
	PORTD&=~(1<<EN);
	LCD=data << 4;
	PORTD|=(1<<EN);
	_delay_ms(100);
	PORTD&=~(1<<EN);
}
void lcd_init()
{
	DDRB=0xFF;
	DDRD=0xFF;
	PORTD&=~(1<<EN);
	lcdcmd(0x33);
	lcdcmd(0x32);
	lcdcmd(0x28);
	lcdcmd(0x0E);
	lcdcmd(0x01);
	_delay_ms(100);
}
void lcd_print(char *str)
{
	unsigned char i=0;
	while(str[i]!=0)
	{
		lcddata(str[i]);
		i++;
	}
}
