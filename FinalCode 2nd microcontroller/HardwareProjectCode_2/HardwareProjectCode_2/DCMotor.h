/*
 * DCMotor.h
 *
 * Created: 5/12/2022 11:32:10 AM
 *  Author: asus
 */ 


#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void initializeDCM();
void startDCMotor();
void stopDCMotor();


#endif /* DCMOTOR_H_ */