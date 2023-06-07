/*
 * StepperMotor.h
 *
 * Created: 5/12/2022 1:05:06 PM
 *  Author: asus
 */ 


#ifndef STEPPERMOTORM3_H_
#define STEPPERMOTORM3_H_

#define  F_CPU 16000000UL
#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

void initializeStepperM3();
void rotateClockwiseM3(int n);
void rotateAntiClockwiseM3(int n);

#endif /* STEPPERMOTORM3_H_ */