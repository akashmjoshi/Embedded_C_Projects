/*--------------------------------------------------------------------------

* PROJECT:              IR Sensor                                           
*                                                                           
* MODULE TITLE:         LCD   
*                                                                           
* MODULE FILENAME:      LCD.c                                    
*
* MODULE TESTING REF:   
*
* TOOLS DESCRIPTION:
*                       Texas Instruments Code Composer Essentials Version 3.2.2.1.4
*                       Texas Instruments MSP430 USB-Debug-Interface MSP-FET430UIF
*                       
*                                                                            
* MODULE DESCRIPTION:                                                       
* This module configure the LCD.                           
*                                                                           
* ISSUE:   DATE:     AUTHOR:   REASON:                                      
* ------  --------   -------   -------                                      
* v1      19.03.10   N.Singh   Initial                                                                                                              
*                                                                           
*-------------------------------------------------------------------------*/

#include "system.h"

int i=0;
char sw=0,active;
float tmp;
signed int ret,time;
long value[8]={0,0,0,0,0,0,0,0};
unsigned char array[5] = { 0x1, 0x2, 0x3, 0x4, 0x5 };


uint8_t Time_Format;
uint8_t Time_Stamp;
uint8_t Seconds;
uint8_t Minutes;
uint8_t Hours;
uint8_t Day;
uint8_t Date;
uint8_t Month;
uint16_t Year;

void Clock_Init(void)
{
	BCSCTL1 = 0xC7;
	BCSCTL2 = 0x00;
	BCSCTL3 = 0x20;
}

// Echo back RXed character, confirm TX buffer is ready first


void main()
{
	
	WDTCTL = WDTPW + WDTHOLD; // Disable Watchdog
	_EINT(); // enable interrupts
	Clock_Init();
	LcdInit();
	Init_Ports();
	ADS1248INIT();
	Uart_Init();
	switching();
	
	Display(1);
	
	active=0;
    while(1)
    {
			ADS1248CargaInicial(active);
			//while(checksw()!=3)
			{
				
				//read_RTC();
				adc_reading(active);
				delay_ms(900);
				if(checksw()==1)
				Display(2);
				
			}
			//Uart_TX();
			
			active++;
			if(active==8)
				active=0;
		
		
    } 
	
}



