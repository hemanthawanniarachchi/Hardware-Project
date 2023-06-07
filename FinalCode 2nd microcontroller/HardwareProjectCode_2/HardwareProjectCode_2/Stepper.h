/*
 * Stepper Header File
 */ 


#ifndef STEPPER_H_
#define STEPPER_H_
#define F_CPU 16000000UL		// Define CPU Frequency 16MHz 
#include <avr/io.h>		// Include AVR std. library file 
#include <util/delay.h>		// Include delay header file 

void Stepper_Initialize();
void Stepper_Rotate();

#endif /* STEPPER_H_ */