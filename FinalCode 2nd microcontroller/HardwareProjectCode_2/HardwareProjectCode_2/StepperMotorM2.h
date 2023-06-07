/*
 * StepperMotor.h
 *
 * Created: 5/12/2022 1:05:06 PM
 *  Author: asus
 */ 


#ifndef STEPPERMOTORM2_H_
#define STEPPERMOTORM2_H_

#define  F_CPU 16000000UL
#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

void initializeStepperM2();
void rotateClockwiseM2(int n);
void rotateAntiClockwiseM2(int n);



#endif /* STEPPERMOTORM2_H_ */