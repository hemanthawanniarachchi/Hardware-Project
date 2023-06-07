/*
 * Stepper1.h
 * measuring

 */ 


#ifndef STEPPER1_H_
#define STEPPER1_H_

#define F_CPU 16000000UL		/* Define CPU Frequency 16MHz */
#include <avr/io.h>		/* Include AVR std. library file */
#include <util/delay.h>		/* Include delay header file */

void Stepper1_Initialize();
void Stepper1_rotate();

#endif /* STEPPER1_H_ */