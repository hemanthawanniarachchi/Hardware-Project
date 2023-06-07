/*
 * servo.h
 *
 * 
 *  
 */ 


#ifndef SERVO_H_
#define SERVO_H_
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


void servoangle(uint8_t pin);




#endif /* SERVO_H_ */