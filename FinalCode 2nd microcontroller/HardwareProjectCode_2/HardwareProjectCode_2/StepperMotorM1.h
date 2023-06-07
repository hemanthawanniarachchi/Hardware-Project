/*
 * StepperMotor.h
 *
 * Created: 5/12/2022 1:05:06 PM
 *  Author: asus
 */ 


#ifndef STEPPERMOTORM1_H_
#define STEPPERMOTORM1_H_

#define  F_CPU 16000000UL
#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

void initializeStepperM1();
void rotateClockwiseM1(int n);
void rotateAntiClockwiseM1(int n);



#endif /* STEPPERMOTORM1_H_ */