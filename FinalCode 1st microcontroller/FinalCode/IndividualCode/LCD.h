/*
 * 
 *
 * LCD-header file
 *  
 */ 


#ifndef LCD_H_
#define LCD_H_

#define F_CPU 16000000UL
#include<avr/io.h>
#include<util/delay.h>

#define LCD PORTB
#define EN 7
#define RW 6
#define RS 5

void lcdcmd(unsigned char cmd);
void lcddata(unsigned char data);
void lcd_init();
void lcd_print(char *str);





#endif /* LCD_H_ */