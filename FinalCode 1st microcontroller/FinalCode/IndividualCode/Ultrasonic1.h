/*
 * Ultrasonic1.h
 *
 * Created: 5/25/2022 12:28:03 AM
 *  Author: Asus
 */ 


#ifndef ULTRASONIC1_H_
#define ULTRASONIC1_H_
     
#include <avr/io.h>             // This header file includes the appropriate Input/output definitions for the device
#include <util/delay.h>         // to use delay function we need to include this library
#include <stdlib.h>             // we'll be using itoa() function to convert integer to character array that resides in this library


#define US_PORT PORTC           // we have connected the Ultrasonic sensor on port C. to use the ultrasonic we need two pins of the ultrasonic to be connected on port C
#define	US_PIN	PINC            // we need to initialize the pin resistor when we want to take input.
#define US_DDR 	DDRC            // we need data-direction-resistor (DDR) to set the direction of data flow. input or output. we will define it later, now we're just naming it.

#define US_TRIG_POS	PC0         // the trigger pin of ultrasonic sound sensor is connected to port C pin 0
#define US_ECHO_POS	PC1         // the echo pin of the ultrasonic sound sensor is connected to port C pin 1

#define US_ERROR		-1      // we're defining two more variables two know if the ultrasonic sensor is working or not
#define	US_NO_OBSTACLE	-2

#define US_ERROR		-1      
#define	US_NO_OBSTACLE	-2


void HCSR04Init();
void HCSR04Trigger();
uint16_t GetPulseWidth();
int calculate();




#endif /* ULTRASONIC1_H_ */