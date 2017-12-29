#include "system.h"


uint16_t ms_1000_counter1   = 0;
uint16_t ms_1000_counter2   = 0;
//uint16_t ms_100_counter1    = 0;
//uint16_t ms_100_counter2    = 0;


//uint16_t Buzzer1_counter = 0;
//uint16_t Buzzer2_counter = 0;
//uint8_t  Buzzer1_Toggle  = 0;
//uint8_t  Buzzer2_Toggle  = 0;


//uint8_t  Leds                 = 0; 
//uint8_t  Power_on             = 1;
//uint8_t  key_pressed          = 0;
//uint8_t  Timeout_Count1       = 0;
//uint16_t one_sec_counter      = 0;
//uint16_t remote_counter       = 0;
//uint16_t Key_Counter          = 0;
//uint16_t Flashing_Counter     = 0;
//uint8_t  Flash_Toggle         = 0;
//uint8_t  System_Chk_Flag      = 0;
//uint16_t System_Chk_counter   = 0;
//uint16_t System_Chk_counter1  = 0;
//uint8_t  Show_Peak            = 0;
//uint8_t  Show_Clear_Peak      = 0; 
//uint16_t Peak_Counter         = 0;
//uint16_t Peak_Counter1        = 0;
//uint16_t Peak_Counter2        = 0;
//uint16_t Peak_Counter3        = 0;


void Timer_B_init(void)
{
//  TBCCTL0 = CCIE;                       /* Timer interrupt enabled*/
//  TBCCR0 = 0x1F3;					    /* compare the clock frequency with the number of counts giving an interrupt every milisecond*/                                
//  TBCTL = 0x01D0;                     	/* TBSSEL_1 + MC_1 + TBCLR;Timer source is ACLK, Timer in upmode (counts up to TBCL0), clear TBR*/

  TBCCTL0 = CCIE;                           /* Timer interrupt enabled*/
  TBCTL = 0x0110u;                     /* TBSSEL_1 + MC_1 + TBCLR;Timer source is ACLK, Timer in upmode (counts up to TBCL0), clear TBR*/
 // TBCCR0 = 65000;  //5ms for 12 MHZ  
  TBCCR0 = 13800;  //1ms for 12 MHZ

  _BIS_SR(GIE);                         /* Ensure all interrupts are enabled. Discard returned value */
}


#pragma vector=TIMERB0_VECTOR
interrupt void Timer_B (void)
{
       one_sec_counter++;
	   Logic_counter++;       
       toggle_counter++;
       TimerA_off_count++;
	
	   if(Data_captured)
	   {
	   	 TACCTL0 &= ~CCIE; 
	   	 internal_count = 30;	   		   	
	   	 remote_counter++;
	   }
			
	   if(key_pressed)
	   Key_Counter++;
	
	
//if(message == 10)
{		
///************UART0*******************/
	   if(run_timer)
	   timeout++;
	   
	   timeout_temp++; 
///************UART0*******************/

/************UART1*******************/
	   if(run_timer1)
	   timeout1++; 
/************UART1*******************/
}	   
	  	
	  	  
/*****************************BACKLIT FLASHING*************************************************/     
     if( (Fault_Flash_ON) && !(Power_on) && !(logic_off) &&  ( (Logic.AL1_Blink||Logic.AL1_ACK) || (Logic.AL2_Blink||Logic.AL2_ACK) || (Logic.AL3_Blink||Logic.AL3_ACK) || (Logic.AL4_Blink||Logic.AL4_ACK) || (Fail_show) ) && !(System_Chk_Flag) )
     Flashing_Counter++;
     else
     {
       if((Logic.backlit) && (Backlit_damp) )             // LCD Backlit
       BACKLIT_ON
       else
       BACKLIT_OFF
     }
/*****************************BACKLIT FLASHING END********************************************************/      
       	
         	
/****************************Data updating************************************************/
     if((Timeout_Count == 0)&&(Timeout_Count1 != 10) && (message == 10))
     update_counter++;  
/****************************Data Updating*************************************************/		  
		 
		 

/********************************Key logic**************************************************/	 
 if ( (NEXT_KEY)&&(message == 10) && !(GF.Start_Flag))   //SET/NEXT KEY
 {	
 	upcount   = 0;
    downcount = 0;
 		
 	ms_1000_counter1++;
 	Timeout_Count = 1;
 }
      
 else if ( (SHIFT_KEY)&&(message == 10) && (GF.Sec_3_Flag))  //SHIFT KEY
 {
 	ms_1000_counter1++;
 	Timeout_Count = 1;
 }
	
 else if ( (INCR_KEY)&&(message == 10) && (GF.Sec_3_Flag))   //INCR KEY
 {
 	ms_1000_counter1++;
 	Timeout_Count = 1;
 }
	 
	 

 if(((ms_1000_counter1 == 250)||(upcount > 50)||(downcount > 50))&&(message == 10)&& (GF.Sec_3_Flag))  //Normal key operation//
   {
	    ms_1000_counter1 = 0;
		         
	    if(NEXT_KEY)
	    GF.Next_Button_Flag = 1;
		       
	    else if(SHIFT_KEY)
        GF.Shift_Button_Flag = 1;
		         	
	    else if(INCR_KEY)
        GF.Incr_Button_Flag = 1;		         
   }
		      
          
 else if( (NEXT_KEY) && (ms_1000_counter1 > 2000) && (message == 10))  //Entering for the first time
    {   	    	
    	ms_1000_counter1    = 0;   	
    	GF.Sec_3_Flag       = 1;
    	GF.Start_Flag       = 1;    	
    	GF.Show_Conc_Flag   = 0;

    	Button = Next;
    	Menu = 1;
    	Next_Parameter = 1;
    	
    	Current_Display.Resolution_Flag = 0;
    	Current_Menu.Alarm_Flag         = 0;
    }
    
else if((GF.Start_Flag)&&(message == 10))           //Entering for the first time
    {  
    	Leds |= KEY_LED;	 		 	  
	    
	    if(ms_1000_counter2 == 2000)
	    {
	       Leds &= ~KEY_LED;
	       
	  	   ms_1000_counter2  = 0;
	  	   Timeout_Count1    = 0;
	       first_enter2      = 0;
	       GF.Start_Flag     = 0;
	       GF.Next_Button_Flag = 1;
	    }
	    else
	    {
	       first_enter2 = 1;
	       ms_1000_counter2++;
	    }
     }
	 
/****************************Key logic*******************************************/	  



/****************************IR START-UP*********************************/ 
  else if(first_enter == 1)
     {
     	   ms_1000_counter2++;
 	  
	      if(ms_1000_counter2 > 2000)
	      {
	      	  Leds &= ~KEY_LED;
	      	  
	      	  ms_1000_counter2  = 0;
	      	  first_enter       = 0;
	      	  Timeout_Count1    = 0;
	      	  GF.Show_Conc_Flag = 0;  
			  GF.Sec_3_Flag     = 1;
			  
			  key_code = 0;
			  scanned_key = 0;
			  			   
			  Button = Next;
			  Menu = 1;
		      Next_Parameter = 1;
		      Current_Display.Resolution_Flag = 0;
		      Current_Menu.Alarm_Flag       = 0;	      	 
	      }
     } 

/****************************IR START-UP*********************************/


/*****************************BUZZER*********************************************************/  
//if(!System_Chk_Flag)
 // {
       if( (Buzzer_ON) && !(Buzzer_ack) && ((Buzzer1_start)||(Buzzer2_start)||(Buzzer3_start)||(Buzzer4_start)) && ((!(logic_off) && !(Fail_show)) || ((Menu == 8) && (GF.Valid_passward)) ) )
       {
       		Buzzer_counter++;
       		if(Buzzer_counter > 700) 
			{
				Buzzer_counter = 0;
				Buzzer_Toggle ^= 1;
			}
       }   	   		 		   		    		  		    		  		    		
       else
       {
       	  Buzzer_Toggle = 0;
          BUZZER_OFF
       } 		
//  }
/*****************************BUZZER*********************************************************/



///****************************System Check*********************************/	
if((ACK_KEY) && ((!GF.Sec_3_Flag)||(GF.Show_Conc_Flag)))
    System_Chk_counter++;


if((System_Chk_counter >= 15000)||(System_Chk_Flag))
{
	System_Chk_counter = 0;
	System_Chk_Flag    = 1;
	System_Chk_counter1++;
	
	if(System_Chk_counter1 >= 5000)
	{
		System_Chk_counter1 = 0;
		System_Chk_Flag     = 0;
		
		Leds &= ~(AL1_LED + AL2_LED + AL3_LED + AL4_LED + HTY_LED+ PRG_LED + KEY_LED + COM_LED);
	    AL1_RELAY_OFF
	    AL2_RELAY_OFF
	    AL3_RELAY_OFF
	    AL4_RELAY_OFF
	    FAILSAFE_RELAY_OFF
	    BUZZER_OFF
	}
	else
	{
		Leds |= (AL1_LED + AL2_LED + AL3_LED + AL4_LED + HTY_LED+ PRG_LED + KEY_LED + COM_LED);
	    AL1_RELAY_ON
	    AL2_RELAY_ON
	    AL3_RELAY_ON
	    AL4_RELAY_ON
	    FAILSAFE_RELAY_ON
	    BUZZER_ON
	}
}
/****************************System Check***************************************/




/******************************Peak Value***************************************/   
//   if( ((!GF.Sec_3_Flag)||(GF.Show_Conc_Flag)) && (SHIFT_KEY))
//   Peak_Counter++;  
//   if(Show_Peak)
//   Peak_Counter1++;
  
   if(((!GF.Sec_3_Flag)||(GF.Show_Conc_Flag)) && (INCR_KEY))
   Peak_Counter2++;
   if(Show_Clear_Peak)
   Peak_Counter3++;   
/****************************Peak Value*********************************************/ 



/************************Relay-1****************************************************/  
  if((start_timer1  == 1) && !(Logic.start_flashing))
   {
	   	if(Time_delay1_data == 0)
	   	Logic.start_flashing = 1;
	   	else
	   	relayy1_counter++;
   }
/************************Relay-1****************************************************/    


/************************RELAY-2****************************************************/ 	   
    if((start_timer2  == 1) && !(Logic.start_flashing2))
    {
	   	if(Time_delay2_data == 0)
	   	Logic.start_flashing2 = 1;
   		else
	   	relayy2_counter++;
     }
/************************RELAY-2****************************************************/


/************************RELAY-3****************************************************/ 	   
    if((start_timer3  == 1) && !(Logic.start_flashing3))
    {
	   	if(Time_delay3_data == 0)
	   	Logic.start_flashing3 = 1;
   		else
	   	relayy3_counter++;
     }
/************************RELAY-3****************************************************/


/************************RELAY-4****************************************************/ 	   
    if((start_timer4  == 1) && !(Logic.start_flashing4))
    {
	   	if(Time_delay4_data == 0)
	   	Logic.start_flashing4 = 1;
   		else
	   	relayy4_counter++;
     }
/************************RELAY-4****************************************************/

/************************FAILSAFE RELAY*********************************************/
	 if(Start_Failsafe_Timer == 1)
	 Failsafe_Counter++;  
/************************FAILSAFE RELAY***********************************************/ 
 
 
    led_display(Leds);


/*****************************ADC logic******************************************************/
   //     ADC12CTL0 |= ADC12SC;
/*****************************ADC logic******************************************************/

 
 /************************AL1/AL2 LED, RELAY1/RELAY2*******************************************/      
//_BIS_SR(GIE); 
	
	
}



void led_display(unsigned int led_glow)
{
   static uint8_t led_merge = 0x00;
   
   led_merge = ~led_glow;
   
   if(led_merge & 0x01)
      LED_PORT |= (0x01 << LED_SERIAL_PIN_NO);
   else
      LED_PORT &= ~(0x01 << LED_SERIAL_PIN_NO);
   
   LED_PORT &= ~(0x01 << LED_SCLK_PIN_NO);
   LED_PORT |= (0x01 << LED_SCLK_PIN_NO);
   
   
   if(led_merge & 0x02)
      LED_PORT |= (0x01 << LED_SERIAL_PIN_NO);
   else
      LED_PORT &= ~(0x01 << LED_SERIAL_PIN_NO);
   
   LED_PORT &= ~(0x01 << LED_SCLK_PIN_NO);
   LED_PORT |= (0x01 << LED_SCLK_PIN_NO);
   
   
   if(led_merge & 0x04)
      LED_PORT |= (0x01 << LED_SERIAL_PIN_NO);
   else
      LED_PORT &= ~(0x01 << LED_SERIAL_PIN_NO);
   
   LED_PORT &= ~(0x01 << LED_SCLK_PIN_NO);
   LED_PORT |= (0x01 << LED_SCLK_PIN_NO);
   
   
   if(led_merge & 0x08)
      LED_PORT |= (0x01 << LED_SERIAL_PIN_NO);
   else
      LED_PORT &= ~(0x01 << LED_SERIAL_PIN_NO);
   
   LED_PORT &= ~(0x01 << LED_SCLK_PIN_NO);
   LED_PORT |= (0x01 << LED_SCLK_PIN_NO);
   
   
   if(led_merge & 0x10)
      LED_PORT |= (0x01 << LED_SERIAL_PIN_NO);
   else
      LED_PORT &= ~(0x01 << LED_SERIAL_PIN_NO);
   
   LED_PORT &= ~(0x01 << LED_SCLK_PIN_NO);
   LED_PORT |= (0x01 << LED_SCLK_PIN_NO);
   
   
   if(led_merge & 0x20)
      LED_PORT |= (0x01 << LED_SERIAL_PIN_NO);
   else
      LED_PORT &= ~(0x01 << LED_SERIAL_PIN_NO);
   
   LED_PORT &= ~(0x01 << LED_SCLK_PIN_NO);
   LED_PORT |= (0x01 << LED_SCLK_PIN_NO);
   
   
   if(led_merge & 0x40)
     LED_PORT |= (0x01 << LED_SERIAL_PIN_NO);
   else
      LED_PORT &= ~(0x01 << LED_SERIAL_PIN_NO);
   
   LED_PORT &= ~(0x01 << LED_SCLK_PIN_NO);
   LED_PORT |= (0x01 << LED_SCLK_PIN_NO);
   
   if(led_merge & 0x80)
      LED_PORT |= (0x01 << LED_SERIAL_PIN_NO);
   else
      LED_PORT &= ~(0x01 << LED_SERIAL_PIN_NO);
   
   LED_PORT &= ~(0x01 << LED_SCLK_PIN_NO);
   LED_PORT |= (0x01 << LED_SCLK_PIN_NO);
      
   LED_PORT &= ~(0x01 << LED_RCLK_PIN_NO);
   LED_PORT |= (0x01 << LED_RCLK_PIN_NO);
    
}

