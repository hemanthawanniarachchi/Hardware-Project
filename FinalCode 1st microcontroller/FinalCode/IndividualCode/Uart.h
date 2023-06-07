/*
 * Uart.h
 *
 * Created: 5/13/2022 8:14:15 AM
 *  Author: asus
 */ 


#ifndef UART_H_
#define UART_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
void InitializationUart();
void sentData(int x);
int getData();

#endif /* UART_H_ */