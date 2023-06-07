/*
 * StepperMotor.h
 *
 * Created: 5/12/2022 1:05:06 PM
 *  Author: asus
 */ 


#ifndef STEPPERMOTOR_H_
#define STEPPERMOTOR_H_

#define  F_CPU 16000000UL
#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

void initializeStepperM();
void rotateClockwise(int n);
void rotateAntiClockwise(int n);



#endif /* STEPPERMOTOR_H_ */