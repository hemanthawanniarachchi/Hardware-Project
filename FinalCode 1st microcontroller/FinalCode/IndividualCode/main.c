
#define F_CPU 16000000UL
#include<avr/io.h>
#include<util/delay.h>

#include "Uart.h"
#include "IR1.h"
#include "IR2.h"
#include "LCD.h"
#include "Servo.h"
#include "keypad.h" 
#include "buzzer.h"
#include "Stepper1.h"
#include "Stepper2.h"
#include "Ultrasonic1.h"
#include "USART.h"


unsigned char x; //mode display strip(x=0) or cut(x=1)
unsigned char x1;//strip-->x1=stripheight,  cut--->x1=length
unsigned char x2;//cut--->x2=no of pieces , strip-->x2=strip length
int y2=0; //cut--->length of a piece  , strip-->stripheight        
int y=0; //strip or cut        
int y3=0; //pieces  , y3=strip length
        


int main(void)
{  
	    
	    DDRA=0x0F;
		DDRC|=(1<<2);//servo pin as output
		USART_Init(9600);
		
	    lcd_init();
         

	    lcd_print("....STARTING....");
	    _delay_ms(100);
	
	    lcdcmd(0x01);
	    lcdcmd(0x0E);
	    _delay_ms(100);
		


	    lcd_print("Strip:0/Cut:1");
	    lcdcmd(0xC0);
		
	    do
	    {
		    PORTA=0xF0;
		    if(PINA!=0xF0)
		    {
			    x=keypad();     
				
				if(x!='=')
				{
					y=x-'0';
					lcddata(x);
				}
		    }
	    }while(x!='=');
		
		lcdcmd(0x01);
		lcd_print("---Processing---");
		_delay_ms(300);
		
		//cutting mode
			
		if(y==1)   // select MODE
		{
			IR1_Initialize();
			if(IR1_checking()== 0)
			{
				lcd_print("....NO WIRE....");
				BUZZER();
				lcdcmd(0x01);
				lcdcmd(0x0E);
				_delay_ms(100);
				lcdcmd(0x08);
			}
			
		    //Initialization Uart
			InitializationUart();
			
			//send data
			sentData(1);  //1- cutting mode
			
	
			
            IR2_Initialize();
            if(IR2_checking()== 1)
			{

				label1:
				lcdcmd(0x01);
				lcd_print("Enter Length:");
				_delay_ms(100);
				lcdcmd(0xC0);
				_delay_ms(100);
				
				do
				{
					PORTA=0xF0;
					if(PINA!=0xF0)
					{
						x1=keypad();   
						if(x1=='/' || x1=='+'  ||x1=='*' ||x1=='C' ||x1=='-')
						{
							lcdcmd(0x01);
							lcdcmd(0x0E);
							_delay_ms(100);
							BUZZER();
							lcd_print("Invalid Input!");
							_delay_ms(100);
							goto label1;
						}

						else if(x1!='=')
						{
							y2=(y2*10)+(x1-'0');
							lcddata(x1);
						}
					}
				}while(x1!='=');
				
			
				
				if(y2<50)
				{   
					label2:
					lcdcmd(0x01);
					lcdcmd(0x0E);
					_delay_ms(100);
					lcd_print("No. of pieces:");
					_delay_ms(100);
					lcdcmd(0xC0);
					
					do
					{
						PORTA=0xF0;
						if(PINA!=0xF0)
						{
							x2=keypad();     
							if(x2=='/' || x2=='+'  ||x2=='*' || x2=='C' ||x2=='-')
							{
								lcdcmd(0x01);
								lcdcmd(0x0E);
								_delay_ms(100);
								BUZZER();
								lcd_print("Invalid Input!");
								_delay_ms(100);
								goto label2;
							}
							else if(x2!='=')
							{
								y3=(y3*10)+(x2-'0');       
								lcddata(x2);
							}
						}
					}while(x2!='=');
					
					lcdcmd(0x01);
					lcd_print("---Processing---");
					_delay_ms(300);
					lcdcmd(0x01);
					lcd_print("--Data Accepted--");
					_delay_ms(300);
					
					
					Stepper1_Initialize();
					Stepper2_Initialize();
					HCSR04Init();

					for (int j=0;j<y3;j++)
					{

                        for (int i=0; i<y2*10;i++)
                        {
						    Stepper1_rotate(); //measuring
						}

                        _delay_ms(100);

                        while(calculate()<10)
						{
                            Stepper2_rotatedown();      //blade down
	                    }
                        _delay_ms(100);

                        while (calculate()>3)
						{
	                        Stepper1_rotateUp();                       //blade up
	                    }
                        _delay_ms(300);

               
			       }
                        
                     
				} 
				
				else if(y2>=50)
           	    {
           	   	    //rotate steppermotor1 according to length;   
				    for (int i=0; i<y2*10;i++)
                    {
				        Stepper1_rotate();//measuring
					}
                    

						while(1){
							if (PIND&(1<<4))// check ir pin
							{
								servoangle(0);
								USART_TxString("A");  //send data
								
								
							}
							else
							{
								servoangle(1);USART_TxString("B");
							}
							
						}
					
					
           	
					_delay_ms(100);

                    while(calculate()<10)
					{
                         Stepper2_rotatedown();      //blade down
	                }
                    _delay_ms(100);
						   
						  

                    while (calculate()>3)
					{
	                     Stepper1_rotateUp();           //blade up
	                }
                    _delay_ms(300);

           	   }
		    }

			else  //(IR1==0)
       	    {  
				   lcdcmd(0x01);
				   lcd_print("-----ERROR-----");
				   BUZZER();
				   lcdcmd(0x08);        
       		      
            }

		}
			
	    //stripping mode
		else if (y==0)
		{   
			//Initialization Uart
			InitializationUart();
			
			//send data
			sentData(0);  // 0 -stripping mode
			
			label3:
			lcdcmd(0x01);
			lcd_print("Strip height:");
			_delay_ms(100);
			lcdcmd(0xC0);
				
			do
			{
				PORTA=0xF0;
				if(PINA!=0xF0)
				{
					x1=keypad();    
					if(x1=='/' || x1=='+'  ||x1=='*' || x1=='C' ||x1=='-')
					{
						lcdcmd(0x01);
						lcdcmd(0x0E);
						_delay_ms(100);
						BUZZER();
						lcd_print("Invalid Input!");
						_delay_ms(100);
						goto label3;
					}  
					else if(x1!='=')
					{
						y2=(y2*10)+(x1-'0');        
						lcddata(x1);
					}
	
				}
			}while(x1!='=');
				
				
			label5:	
			lcdcmd(0x01);
			lcdcmd(0x0E);
			_delay_ms(100);
			lcd_print("Strip length:");
			_delay_ms(100);
			lcdcmd(0xC0);
				
			do
			{
				PORTA=0xF0;
				if(PINA!=0xF0)
				{
					x2=keypad();     
					if(x2=='/' || x2=='+' ||x2=='*' || x2=='C'||x2=='-')
					{
						lcdcmd(0x01);
						lcdcmd(0x0E);
						_delay_ms(100);
						BUZZER();
						lcd_print("Invalid Input!");
						_delay_ms(100);
						goto label5;
					}
					else if(x2!='=')
					{
						y3=(y3*10)+(x2-'0');        
						lcddata(x2);
					}
				}
			}while(x2!='=');
					
			lcdcmd(0x01);
			lcd_print("---Processing---");
			_delay_ms(300);
			lcdcmd(0x01);
			lcd_print("-Data Accepted-");
			_delay_ms(300);
          
           //Initialization Uart
			InitializationUart();
				
			//send data
			sentData(y2);
				
			_delay_ms(500);
				
			//send data
			sentData(y3);  


		}
			
		//invalid mode
		else
		{
			lcdcmd(0x01);
			lcd_print("-Can't Accept-");
			BUZZER();
			_delay_ms(100);
	        lcdcmd(0x08);
		}
	
	return 0;
}


		
	

