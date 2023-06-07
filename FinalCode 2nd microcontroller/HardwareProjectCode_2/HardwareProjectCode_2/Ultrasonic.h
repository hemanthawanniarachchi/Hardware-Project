/*
 * Ultrasonic.h
 *
 * Created: 5/12/2022 9:06:50 PM
 *  Author: asus
 */ 


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define  Trigger_pin	PA0	/* Trigger pin */
double ultrasonic();


#endif /* ULTRASONIC_H_ */