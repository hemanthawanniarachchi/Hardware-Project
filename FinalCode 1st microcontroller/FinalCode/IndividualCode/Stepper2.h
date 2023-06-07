/*
 * Stepper2.h
 *
 * cutting
 */


#ifndef STEPPER2_H_
#define STEPPER2_H_
#define F_CPU 16000000UL		/* Define CPU Frequency 8MHz */
#include <avr/io.h>		/* Include AVR std. library file */
#include <util/delay.h>		/* Include delay header file */


void Stepper2_Initialize();
void Stepper2_rotatedown();
void Stepper1_rotateUp();



#endif /* STEPPER2_H_ */