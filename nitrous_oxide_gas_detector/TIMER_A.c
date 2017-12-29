 #include "system.h"

 uint16_t Logic_counter1    = 0; 
 uint16_t Logic_counter     = 0;
 uint8_t  damping_counter   = 0;
 uint8_t  toggle2 = 0;
 uint16_t toggle2_counter    = 0;
 uint16_t update_counter     = 0;
 uint16_t update_counter1    = 0;

 
 uint16_t lmp_counter       = 0;
 uint16_t Failsafe_Counter  = 0;
 uint16_t Failsafe_Counter1 = 0;
 uint8_t Fail_show = 0;
 uint8_t Power_on1 = 0;
 
 uint8_t  sec_count    = 0;
 uint8_t  minute_count = 0;
 uint8_t  hour_count   = 0;
 
uint8_t Data_captured       = 0;


 
 void Timer_A_init(void)
 {
//      TACCTL0 = CCIE;
//      TACCR0 = 0x64;    //200 micro  
//    //     TACCR0 = 0x7D;     //250 micro
//
//      //  TACCR0 = 0x96;     //300 micro
//     // TACCR0 = 0xFA;    //500 micro
//     //TACCR0 = 0x113;    //550 micro
//     //TACCR0 = 0x177;    //750 micro
//     //  TACCR0 = 0x1F6;      //1 ms
//     TACTL  = 0x01D0;


  //TACCTL0 = CCIE;                      /* Timer interrupt enabled*/
  TACTL = 0x0110u;                     /* TASSEL_1 + MC_1 + TACLR;Timer source is ACLK, Timer in upmode (counts up to TBCL0), clear TAR*/
  TACCR0 = 2000;  // 200us for 12 MHZ
  

   
    _BIS_SR(GIE); 
 } 


/*---------------------------------------------------------------------------
* Function name       : void TA0_ISR(void)
*     returns         : -
*     arg1            : -
*     arg2            : -
* Created by          : N.Singh
* Date created        : 18/03/10
* Description         : This interrupt occurs time_delay_ms after the
* lamp pulse interrupt occurs. This is in order to read the ADC at the peak
* and trough exactly
* 
*---------------------------------------------------------------------------*/
#pragma vector = TIMERA0_VECTOR
interrupt void TA0_ISR(void)
{
		
   if((internal_count == 30)||(Data_captured))     
	{
		scanned_key = 0;
		scanned_key = key_code;
		Data_captured = 1;
		P1IE &= ~BIT1;
	}
	else
	{		
		if(internal_count == 0)       //A
		{
			if(!(P1IN & 0x02))
				count_delay++;
			else
			{
				if(count_delay > 30)
				{
					internal_count = 1;
					count_delay = 0;
				}
				else
					internal_count = 0;
			}
		}
		else if(internal_count == 1)   //B
		{
			if((P1IN & 0x02))
				internal_count = 1;
			else
				internal_count =2;	
		}
		else if(internal_count == 2)    //C
		{
			if(!(P1IN & 0x02))
				internal_count = 2;
			else
				internal_count = 3;	
		}
		else if(internal_count == 3)    //D
		{
			if((P1IN & 0x02))
				internal_count = 3;
			else
				internal_count = 4;	
		}
		else if(internal_count == 4)   //E
		{
			if(!(P1IN & 0x02))
				internal_count = 4;
			else
				internal_count =5;	
		}
		else if(internal_count == 5)    //F
		{
			if((P1IN & 0x02))
				internal_count = 5;
			else
				internal_count = 6;	
		}
		else if(internal_count == 6)    //G
		{
			if(!(P1IN & 0x02))
				internal_count = 6;
			else
				internal_count =7;	
		}
		else if(internal_count == 7)    //H
		{
			if((P1IN & 0x02))
				internal_count = 7;
			else
				internal_count =8;	
		}
		else if(internal_count == 8)    //I
		{
			if(!(P1IN & 0x02))
				internal_count = 8;
			else
				internal_count = 9;	
		}
		else if(internal_count == 9)    //J
		{
			if((P1IN & 0x02))
				internal_count = 9;
			else
				internal_count = 10;	
		}
		else if(internal_count == 10)    //K
		{
			if(!(P1IN & 0x02))
				internal_count = 10;
			else
				internal_count = 11;	
		}
		else if(internal_count == 11)    //L
		{
			if((P1IN & 0x02))
				internal_count = 11;
			else
				internal_count = 12;	
		}
		else if(internal_count == 12)    //M
		{
			if(!(P1IN & 0x02))
				internal_count = 12;
			else
				internal_count = 13;	
		}
		else if(internal_count == 13)    //N
		{
			if((P1IN & 0x02))
				internal_count = 13;
			else
				internal_count = 14;	
		}
		else if(internal_count == 14)    //O
		{
			if(!(P1IN & 0x02))
				internal_count = 14;
			else
				internal_count = 15;	
		}
		else if(internal_count == 15)    //P
		{
			if((P1IN & 0x02))
				internal_count = 15;
			else
				internal_count = 16;	
		}
		else if(internal_count == 16)    //Q
		{
			if(!(P1IN & 0x02))
				internal_count = 16;
			else
				internal_count = 17;	
		}
		else if(internal_count == 17)    //R
		{
			if((P1IN & 0x02))
				internal_count = 17;
			else
				internal_count = 18;	
		}
		else if(internal_count == 18)   //S
		{
			if(!(P1IN & 0x02))
				internal_count = 18;
			else
				internal_count = 19;	
		}
		else if(internal_count == 19)   //T
		{
			if((P1IN & 0x02))
				count_delay++;
			else
			{
				if(count_delay >3)
					key_code |= 0x20;
				else
					key_code &=~0x20;
				internal_count =20;	
				count_delay = 0;
			}
		}
		else if(internal_count == 20)   //U
		{
			if(!(P1IN & 0x02))
				internal_count = 20;
			else
				internal_count = 21;	
		}
		else if(internal_count == 21)   //V
		{
			if((P1IN & 0x02))
				count_delay++;
			else
			{
				if(count_delay >3)
					key_code |= 0x10;
				else
					key_code &=~0x10;
				internal_count =22;	
				count_delay = 0;
			}	
		}
		else if(internal_count == 22)   //W
		{
			if(!(P1IN & 0x02))
				internal_count = 22;
			else
				internal_count = 23;	
		}
		else if(internal_count == 23)   //X
		{
			if((P1IN & 0x02))
				count_delay++;
			else
			{
				if(count_delay >3)
					key_code |= 0x08;
				else
					key_code &=~0x8;
				internal_count =24;	
				count_delay = 0;
			}	
		}
		else if(internal_count == 24)   //Y
		{
			if(!(P1IN & 0x02))
				internal_count = 24;
			else
				internal_count =25;	
		}			
		else if(internal_count == 25)   //Z
		{
			if((P1IN & 0x02))
				count_delay++;
			else
			{
				if(count_delay >3)
					key_code |= 0x04;
				else
					key_code &=~0x04;
				internal_count =26;	
				count_delay = 0;
			}
		}
		else if(internal_count == 26)   //A1
		{
			if(!(P1IN & 0x02))
				internal_count = 26;
			else
				internal_count = 27;	
		}
		else if(internal_count == 27)   //A2
		{
			if((P1IN & 0x02))
				count_delay++;
			else
			{
				if(count_delay >3)
					key_code |= 0x02;
				else
					key_code &=~0x02;
				internal_count =28;	
				count_delay = 0;
			}	
		}
		else if(internal_count == 28)   //A3
		{
			if(!(P1IN & 0x02))
				internal_count = 28;
			else
				internal_count = 29;	
		}
		else if(internal_count == 29)   //A4
		{
			if((P1IN & 0x02))
				count_delay++;
			else
			{
				if(count_delay >3)
					key_code |= 0x01;
				else
					key_code &=~0x01;
					
				internal_count = 30;
				count_delay = 0;
			}
		}
	}
	
	
		
	//scanned_key = key_code;	
	
	    	
 _BIS_SR(GIE);   
}

