/*
 * HardwareProjectCode_2.c
 * Author : Group48
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <math.h>

//import header files
#include "DCMotor.h"
#include "Uart.h"
#include "Ultrasonic.h"
#include "StepperMotorM1.h"
#include "StepperMotorM2.h"
#include "StepperMotorM3.h"
#include "Stepper.h"
#include "USART.h"

int y2,y3,d;     //y2- strip height  ,y3-strip length  ,d-diameter of the wire ,k- selection variable
int M;
int k=0;

int main(void)

{       
      InitializationUart();  	 
	  M = getData();
	  USART_Init(9600);
	  Stepper_Initialize();

     if (rchar==65)
     {
	     
	     Stepper_Rotate();
	     
     }
     else if(rchar==66)
     {
	     
	     Stepper_Initialize();
     }
     
 


	 if(M==0)
	  {
         DDRB  |= (1 << PINB1);
		
		d=0;                        
		
		
		if(k==0){
			y2 = getData();
			k=1;
			_delay_ms(500);
		}
		
		if(k==1){
			y3 = getData();	
			k=0;
		}
		 
		 //Declare ultrasonic selection pins as output
		 DDRC  |= (1 << PINC6)|(1 << PINC7);
		 
		//initialize ultrasonic
		DDRA = 0x01;	
		_delay_ms(100);
		

		    d=(int)ultrasonic(); 
					_delay_ms(500);      
			d=(int)(ultrasonic());
			_delay_ms(500);
			
			initializeStepperM3();		      // d-diameter of the wire 
			rotateAntiClockwiseM3(d*0.5*2);       //pitch of the screw gauge=0.5cm
			                                  /*Pitch of the screw gauge is defined as the distance moved by the spindle per revolution which is measured by
											   moving the head scale over the pitch scale in order to complete one full rotation.*/
			_delay_ms(100);
			
			
			//USE ULTRASONIC(R)
			PORTC |= (1 << PINB6);
			PORTC |= (1 << PINB7);
			        // PORTC |= 11000000;	
					  _delay_ms(300);		
			double h2=(ultrasonic());
		           	_delay_ms(300);		
						
			double h3=20;
			
			initializeStepperM2();

			while(ultrasonic()<(h2+ h3-(d-y2)) )     
			{
		    rotateAntiClockwiseM2(1);
			}
			_delay_ms(100);
			
			//initialize dcM
		   initializeDCM();
	        _delay_ms(100);
		    
			startDCMotor();
			 _delay_ms(1000);
			 
			//stepper code
		   initializeStepperM1();
		   rotateClockwiseM1(20);
		   rotateClockwiseM1(y3*2);  
		   //**//
		 	_delay_ms(500);
			stopDCMotor();
		   _delay_ms(200);
		   initializeStepperM2();
			
			//USE ULTRASONIC(R)
			PORTC |= (1 << PINB6);
			PORTC |= (1 << PINB7);
				 
	
		   while(ultrasonic()> h2 ) {     
			 rotateClockwiseM2(1);
		   }
		 
		   _delay_ms(100);
		   rotateClockwiseM3(d*0.5*2); //'ANTHARALAYA=0.5cm'



	  }




}

