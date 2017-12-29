#include "system.h"

struct Logic_Flags  Logic;

unsigned char Status_Flag1 = 0;
unsigned char Status_Flag2 = 0;

uint16_t Buzzer_counter = 0;
uint8_t  Buzzer_Toggle  = 0;
uint8_t  R_count              = 0;
uint8_t  Leds                 = 0; 
uint8_t  Power_on             = 1;
uint8_t  key_pressed          = 0;
uint8_t  Timeout_Count1       = 0;
uint16_t one_sec_counter      = 0;
uint16_t remote_counter       = 0;
uint16_t Key_Counter          = 0;
uint16_t Flashing_Counter     = 0;
uint8_t  Flash_Toggle         = 0;
uint8_t  System_Chk_Flag      = 0;
uint16_t System_Chk_counter   = 0;
uint16_t System_Chk_counter1  = 0;
uint8_t  Show_Peak            = 0;
uint8_t  Show_Clear_Peak      = 0; 
uint16_t Peak_Counter         = 0;
uint16_t Peak_Counter1        = 0;
uint16_t Peak_Counter2        = 0;
uint16_t Peak_Counter3        = 0;
uint8_t  damp_count           = 0;

uint16_t TimerA_off_count     = 0;

uint16_t relayy1_counter;
uint16_t relayy2_counter;
uint16_t relayy3_counter;
uint16_t relayy4_counter;

uint16_t relayy1;
uint16_t relayy2;
uint16_t relayy3;
uint16_t relayy4;


uint8_t start_timer1 = 0;
uint8_t start_timer2 = 0;
uint8_t start_timer3 = 0;
uint8_t start_timer4 = 0;

uint8_t Buzzer_Flag  = 0;
uint8_t Buzzer_start = 0;
uint8_t Buzzer_ack   = 0;

uint8_t Buzzer1_ack   = 0;
uint8_t Buzzer2_ack   = 0;
uint8_t Buzzer3_ack   = 0;
uint8_t Buzzer4_ack   = 0;

uint8_t Buzzer1_start = 0;
uint8_t Buzzer2_start = 0;
uint8_t Buzzer3_start = 0;
uint8_t Buzzer4_start = 0;

float64_t Set_point1_temp;   
float64_t Set_point2_temp;
float64_t Set_point3_temp;   
float64_t Set_point4_temp;

uint8_t volatile logic_off = 0;
uint16_t ack_counter = 0;
//float64_t volatile  data = 0.0;

uint8_t query_no = 0;

void logic()
{
	//static uint8_t query_no = 0;
	WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
	
	 
	 if(TimerA_off_count > 1000)
	 {
	 	 TimerA_off_count = 0;
	 	 TACCTL0 ^= CCIE;
	 }
		
	 if(Logic_counter > 400)
     {
  	   Logic_counter = 0;
  	   toggle2 ^= 1;  		  
     } 
     
     if(toggle_counter > 700)
	 { 	
	    toggle_counter = 0;
		GF.Toggle ^= 1;
	 }
	 
	 if(remote_counter > 500)
	 {
		remote_counter  = 0;
		Data_captured   = 0;
		
		key_code        = 0;
		scanned_key     = 0;
		count_delay     = 0;
		internal_count  = 0;
		
		P1IFG &= ~BIT1;
		P1IE  |= BIT1;
	 }
	 
	 if(Key_Counter > 200)
	 {
	    Key_Counter = 0;
	    key_pressed = 0;
	    Leds &= ~KEY_LED; 
	 }


/**************UART0************************************/	 
   
   if(timeout_temp > 200) 
  	{ 
  		timeout_temp = 0; 
  	    send_request(); 		  		
  	} 
   
   
   if(timeout > 50)
  	{
  		timeout_flag = 1;
  		
  		ReceivedByteCount = UART_rcv_count;
  		DecodeSlave();  		
  		ReceivedByteCount = UART_rcv_count;
  		
  		timeout = 0;
  		UART_rcv_count = 0;
  		run_timer = 0;
  	}
  	
  	
/**************UART0************************************/


  	
///**************UART0**********************************/   
    if(timeout1 > 100)
  	{
  		timeout_flag1 = 1;  	
  		DecodeMaster();	
  		
  		timeout1 = 0;
  		UART1_rcv_count = 0;
  		run_timer1 = 0;
  	}
///**************UART1************************************/
    
	
     if(Flashing_Counter > 1500)
     {
     	Flashing_Counter = 0;
     	Flash_Toggle ^= 1;
     	
     	if(Flash_Toggle)
	 	BACKLIT_ON
	 	else
	 	BACKLIT_OFF          	
     }
   
    
    
     
    if(!System_Chk_Flag)
    {
    	if(Buzzer_Toggle)
		BUZZER_ON
		else
		BUZZER_OFF
    } 
     
     if(update_counter > 1000)
	 {
	    update_counter = 0;
	    Timeout_Count1++;
	    entry = 0;
	 }		
    
    
  /****************************skipping warm-up******************************************/	  
	  if ( (NEXT_KEY) && (message == 0) )
	  {
	  		sec_complete = 1;
	  		minute_complete = 1;
	  		hour_complete = 1;
	  	
	  		UARTInit();				        
	        Power_on     = 0;
	        Power_on1    = 1;
	        sec_complete = 0;
		    GF.Warm_Up_Flag   = 0;
		    GF.Show_Conc_Flag = 1;
		   	message = 10;
		    Button  = 100;	  		  
	  }
/****************************skipping warm-up******************************************/
     
     
    if(one_sec_counter > 1000)
	{
		  one_sec_counter = 0;
		
		 // TACCTL0 ^= CCIE;
		
		  R_count++;		 
		  if(R_count > 180)
		  {
		  	R_count = 0;
		  	
		  	if(!(INCR_KEY))
		  	ack_counter = 0;
		  	if(!(ACK_KEY))
		  	System_Chk_counter = 0;
		  	
		  	internal_count = 0;
            count_delay    = 0;
            scanned_key    = 0;
 	        key_code       = 0;
		  }
		
		
	   if( ((!GF.Sec_3_Flag)||(GF.Show_Conc_Flag)) && (INCR_KEY) )
	    ack_counter++;
		
		if(!(sec_complete) && (GF.Warm_Up_Flag))
		sec_count++;		
		
		if(hour_complete && minute_complete)
		{
			if(sec_count >= sec_lmp)
			sec_complete = 1;				
		}
		
		if((sec_count >= 59) && !(minute_complete))
		{
			sec_count = 0;
			minute_count++;
			
			if(hour_complete)
			{
				if(minute_count >= minute_lmp)
				minute_complete = 1;				
			}
			
			if( (minute_count >= 59) && !(hour_complete))
			{
				minute_count = 0;
				hour_count++;
				
				if(hour_count >= hour_lmp)
				hour_complete = 1;
			}
		}
		
		   		
        if((Backlit_Count == 3) && (Backlit_damp) && (GF.Show_Conc_Flag) && (message == 10))
		Backlit_damp++;
		
		if(Backlit_damp >= 10)
		Backlit_damp = 0;
		
	    if((!GF.Sec_3_Flag)||(GF.Show_Conc_Flag))
	    Timeout_Count = 0;
	    else
	    Timeout_Count++;
		
//		if((Menu == 10) && (Timeout_Count >= 225))
//		{
//			P3OUT &= ~BIT1;
//			Timeout_Count = 0;
//			Init_flags();			
//		}
		
	   if((Timeout_Count >=45) && (Timeout_Count) && !(GF.Show_Conc_Flag))
		{
			Timeout_Count   = 0;
			Timeout_Count1  = 0;
			Init_flags();
		}
			
	    if((message>0)&&(GF.Warm_Up_Flag != 1)&&(message != 10))
	    message--;		    
		  
	    else if((sec_complete)&& (message != 10)) 
		{
			Timer_A_init();
						
			Show_Peak1 = 0;
			Power_on   = 0;
			logic_off  = 0;
		    GF.Warm_Up_Flag   = 0;
		    GF.Show_Conc_Flag = 1;
		   	message = 10;
		    Button  = 100;
	    }
	   	   
	} 
     
            	
//	 if(Peak_Counter > 3000)
//     {
//	   	 Leds &= ~KEY_LED;	   	 
//	   	 Peak_Counter = 0;
//	   	 Show_Peak    = 1;   	 
//     }	   	 	   	
//   	 else if(Peak_Counter1 > 5000)
//   	 {
//   	 	Peak_Counter1 = 0;
//   	    Show_Peak     = 0;  	       	 	
//   	 }
		
	
	 if(Peak_Counter2 > 200)
     {
	   	 Leds &= ~KEY_LED;	   	 	   	 
	   	 Peak_Counter2      = 0;
	   	 Show_Clear_Peak    = 1;
     }	   	 	   	
   	else if(Peak_Counter3 > 6000)
   	 {
   	 	Show_Clear_Peak = 0;   	 	
   		Peak_Counter3   = 0;
   	 }
			
	
      if( ( ((!GF.Sec_3_Flag)||(GF.Show_Conc_Flag))||((Menu == 8) && (GF.Valid_passward)) ) && ((ack_counter > 10)||(ACK_KEY)||(Remote_Incr)) )      
      {
	      	ack_counter = 0;
	      	
	      	
	      	if((Logic.AL1_Blink)&&(Logic.AL1_Latch))
	    	Logic.AL1_ACK      = 1;
	
			if((Logic.AL2_Blink)&&(Logic.AL2_Latch))
			Logic.AL2_ACK      = 1;
		    
		    if((Logic.AL3_Blink)&&(Logic.AL3_Latch))
			Logic.AL3_ACK      = 1;
	
		    if((Logic.AL4_Blink)&&(Logic.AL4_Latch))
			Logic.AL4_ACK      = 1;
			 
			 
		    Remote_Incr = 0;

      }
     
     
     if( ( ((!GF.Sec_3_Flag)||(GF.Show_Conc_Flag))||((Menu == 8) && (GF.Valid_passward)) ) && ((INCR_KEY)||(ACK_KEY)||(Remote_Incr)) ) 	
     {
	     	if(Buzzer_ON) 
	      	{
	      		if(Buzzer1_start)
	      		{
	      			Buzzer1_ack   = 1;
	      			Buzzer1_start = 0;      			
	      		}
	      		if(Buzzer2_start)
	      		{
	      			Buzzer2_ack   = 1;
	      			Buzzer2_start = 0;      			
	      		}
	      		if(Buzzer3_start)
	      		{
	      			Buzzer3_ack   = 1;
	      			Buzzer3_start = 0;      			
	      		}
	      		if(Buzzer4_start)
	      		{
	      			Buzzer4_ack   = 1;
	      			Buzzer4_start = 0;      			
	      		} 
	      		
	      		Buzzer_ack = 1;
	      	}
	      			    
		    Remote_Incr = 0;
      } 	
	
/************************AL1/AL2 LED, RELAY1/RELAY2**********************************************/	
	if( ( (!(logic_off) && !(Fail_show)) || ((Menu == 8) && (GF.Valid_passward)) ) && !(Power_on))
  	   {
	  	   if(Logic.AL1)    //AL1
			   {
				      if( (Logic.AL1_Blink) && !(Logic.AL1_ACK) )
				       {				          
					       	Status_Flag1 |= (RL1_STATUS + LED1_STATUS);
					       	AL1_RELAY_ON
					       	
					       	if(toggle2)						   
						    Leds |= AL1_LED;
						    else
						    Leds &= ~AL1_LED;
				       }
					   else if( (Logic.AL1_Blink) && (Logic.AL1_ACK) )
					   {
						   Leds  |= AL1_LED;
						   AL1_RELAY_OFF
						   
						   Status_Flag1 |= (LED1_STATUS);
						   Status_Flag1 &= ~(RL1_STATUS);
					   }
					   else
					   {
					   	   Leds  &= ~AL1_LED;
					   	   AL1_RELAY_OFF
				           Status_Flag1 &= ~(RL1_STATUS + LED1_STATUS);
					   }
					   
			   }
		  else
		       {
		  	       Leds  &= ~AL1_LED;
		  	       AL1_RELAY_OFF
				   Status_Flag1 &= ~(RL1_STATUS + LED1_STATUS);
			   }
			   
				
				
			
           if(Logic.AL2)           //AL2
			   {			     
			         if( (Logic.AL2_Blink) && !(Logic.AL2_ACK))
					  {					  						  					  					  						  						  						  	
					  	Status_Flag1 |= (RL2_STATUS + LED2_STATUS);
					  	AL2_RELAY_ON
					  	
					  	if(toggle2)					 	
					 	Leds  |= AL2_LED;					 						       
					 	else
					 	Leds  &= ~AL2_LED;
					  }
					  else if( (Logic.AL2_Blink) && (Logic.AL2_ACK) )
					  {					  	
					 	Leds |= AL2_LED;
					 	AL2_RELAY_OFF
					    
					    Status_Flag1 |= (LED2_STATUS);
					    Status_Flag1 &= ~(RL2_STATUS);
					  }
					  else
					  {
					  	Leds &= ~AL2_LED;
					  	AL2_RELAY_OFF
		  		        Status_Flag1 &= ~(RL2_STATUS + LED2_STATUS);
					  }					  
			   }
		   else
			   {			   	    
			    	Leds &= ~AL2_LED;
			    	AL2_RELAY_OFF
	  		        Status_Flag1 &= ~(RL2_STATUS + LED2_STATUS);
			   }
			   
		  if(Logic.AL3)           //AL3
			   {
			   	     		     
			         if( (Logic.AL3_Blink) && !(Logic.AL3_ACK))
					  {	
					  	Status_Flag2 |= (RL1_STATUS + LED1_STATUS);
					  	AL3_RELAY_ON
					  					  						  					  					  						  						  						  	
					  	if(toggle2)					
					 	Leds  |= AL3_LED;					 	
					 	else
					 	Leds  &= ~AL3_LED;
					  }
					  else if( (Logic.AL3_Blink) && (Logic.AL3_ACK))
					  {					  	
					 	Leds |= AL3_LED;
					 	AL3_RELAY_OFF
					 	
					    Status_Flag2 |= (LED1_STATUS);
						Status_Flag2 &= ~(RL1_STATUS);
					  }
					  else
					  {
					  	Leds &= ~AL3_LED;
					  	AL3_RELAY_OFF
					  	Status_Flag2 &= ~(RL1_STATUS + LED1_STATUS);		  		       
					  }					  
			   }
		   else
			   {			   	    
			    	Leds &= ~AL3_LED;
			    	AL3_RELAY_OFF
			    	Status_Flag2 &= ~(RL1_STATUS + LED1_STATUS);
			   } 
			   
		  if(Logic.AL4)           //AL4
			   {	
			   	     		     
			         if( (Logic.AL4_Blink)&& !(Logic.AL4_ACK) )
					  {
					  	Status_Flag2 |= (RL2_STATUS + LED2_STATUS);					  						  					  					  						  						  						  	
					  	if(toggle2)
					 	{
					 		Leds  |= AL4_LED;
					 		AL4_RELAY_ON				        
					 	}
					 	else
					 	Leds  &= ~AL4_LED;
					  }
					  else if( (Logic.AL4_Blink)&& (Logic.AL4_ACK) )
					  {					  	
					 	Leds |= AL4_LED;
					 	AL4_RELAY_OFF
					 	
					    Status_Flag2 |= (LED2_STATUS);
						Status_Flag2 &= ~(RL2_STATUS);
					 	
					  }
					  else
					  {
					  	Leds &= ~AL4_LED;
					  	AL4_RELAY_OFF
					    Status_Flag2 &= ~(RL2_STATUS + LED2_STATUS);		  		       
					  }					  
			   }
		   else
			   {			   	    
			    	Leds &= ~AL4_LED;
			    	AL4_RELAY_OFF
			    	Status_Flag2 &= ~(RL2_STATUS + LED2_STATUS);
			   } 	   
			   
			   
			   
			   
  	   }
  	   else
  	   {
  	      Leds &= ~(AL1_LED + AL2_LED + AL3_LED + AL4_LED);
  	      AL1_RELAY_OFF
  	      AL2_RELAY_OFF
  	      AL3_RELAY_OFF
  	      AL4_RELAY_OFF
  	   }
/************************AL1/AL2 LED, RELAY1/RELAY2**********************************************/  	   
  	   
 /************************HEALTHY LED**********************************************/  	 
	   if( (Fail_show) && !(GF.Valid_passward) )       //HTY
	   {
	   		if(toggle2)
	   		Leds |= HTY_LED;
	   		else
	   		Leds &= ~HTY_LED;	   		
	   }   	   
  	   else if( (logic_off) || (Power_on))      //HTY
       Leds &= ~HTY_LED;	   		    
	   else
	   Leds |= HTY_LED;
/************************HEALTHY LED**********************************************/	   


/************************PROGRAM LED**********************************************/	        
	   if( (GF.Valid_passward) && (toggle2) && (message == 10) )     //(PRG)
	   Leds |= PRG_LED;
	   else
	   Leds &= ~PRG_LED;
/************************PROGRAM LED**********************************************/	  


/************************FAILSAFE RELAY*******************************************/
      if( ((GF.Valid_passward) && (message == 10) && !((!GF.Sec_3_Flag)||(GF.Show_Conc_Flag))) || (Power_on)) 
        {
		     	FAILSAFE_RELAY_OFF
		     	Failsafe_ON = 0;   	
        }
       else
	    {
	    	if(Fail_show)
	        {
	        	     Status_Flag1 = 0;
	        	     Status_Flag2 = 0;
	        	
	        	     Leds &= ~(AL1_LED + AL2_LED + AL3_LED + AL4_LED);
					 AL1_RELAY_OFF        
					 AL2_RELAY_OFF        
					 AL3_RELAY_OFF        
					 AL4_RELAY_OFF        
			        			        
			         if(Logic.AL_Failsafe)
				     {
				     	FAILSAFE_RELAY_OFF
				     	Failsafe_ON = 0;
				     }
				     else
				     {
				     	FAILSAFE_RELAY_ON
				     	Failsafe_ON = 1;
				     }
	        }
	        else
	        {
	        	 if(Logic.AL_Failsafe)
			     {
			     	FAILSAFE_RELAY_ON
			     	Failsafe_ON = 1;
			     }
			     else
			     {
			     	FAILSAFE_RELAY_OFF
			     	Failsafe_ON = 0;
			     }   
	        }
	    }
/************************FAILSAFE RELAY**********************************************/	    
      if(relayy1_counter > 1000)
	  {
	   	   relayy1_counter = 0;
	   	   relayy1++;
	   	   	
		   if((relayy1 > Time_delay1_data))
		   {
		    relayy1 = 0;
		    Logic.start_flashing = 1;
		   }
	  }

      if(relayy2_counter > 1000)   //1sec
   	  {
	   	   relayy2_counter = 0;
	   	   relayy2++;
		   
		   if(relayy2 > Time_delay2_data)
		   {
		    relayy2 = 0;
		    Logic.start_flashing2 = 1;
	       }
   	  }
   	  
   	  if(relayy3_counter > 1000)   //1sec
   	  {
	   	   relayy3_counter = 0;
	   	   relayy3++;
		   
		   if(relayy3 > Time_delay3_data)
		   {
		    relayy3 = 0;
		    Logic.start_flashing3 = 1;
	       }
   	  }
   	  
   	  if(relayy4_counter > 1000)   //1sec
   	  {
	   	   relayy4_counter = 0;
	   	   relayy4++;
		   
		   if(relayy4 > Time_delay4_data)
		   {
		    relayy4 = 0;
		    Logic.start_flashing4 = 1;
	       }
   	  }
   	  
//      if(Failsafe_Counter > 1000)
//	  {
//		  	Failsafe_Counter = 0;
//		  	Failsafe_Counter1++;
//		  	
//		  	if(Failsafe_Counter1 > Fail_Safe_Delay_data)
//		  	{
//		  		Start_Failsafe_Timer = 0;
//		  		Failsafe_Counter1    = 0;
//		  		Fail_show = 1; 		
//		  	}
//	  }  	  
  

}





void logic1(void)
{
	volatile float64_t data;

	
	if( (Menu == 8) && (GF.Valid_passward))
    data = (Test_data_Negative)?( Test_data * (-1)):Test_data;
	else
	data =(Process_Negative)?(process_value * (-1)):process_value;
	
	
	Set_point1_temp =(Set_point1_Negative)?( Set_point1_data * (-1)):Set_point1_data;
	Set_point2_temp =(Set_point2_Negative)? (Set_point2_data * (-1)):Set_point2_data;
	Set_point3_temp =(Set_point3_Negative)?( Set_point3_data * (-1)):Set_point3_data;
	Set_point4_temp =(Set_point4_Negative)? (Set_point4_data * (-1)):Set_point4_data;
				
	
	
	if(Logic.AL1)
	{		
			if(Logic.AL1_HI_Logic)
			{			
				if((data >= (Set_point1_temp + Hysterisis1_data)) && !(Logic.AL1_ACK))
				 {				 	
				 	start_timer1  = 1;
				 	
				 	if(Logic.start_flashing)
				 	{
				 		if(!Buzzer1_ack)
				 		{
				 			Buzzer1_start = 1;
				 		    Buzzer_ack    = 0;
				 		}
				 		
				 		Logic.AL1_Blink = 1;
				 		AL1_RELAY_ON
				 		start_timer1    = 0;
				 	}
				 }
				
				else if(data < Set_point1_temp)
			    {
			    	if(((Logic.AL1_Latch)&&(Logic.AL1_ACK)) || !(Logic.AL1_Latch))
			    	{
			    		if(Buzzer1_ack)
				 		{
				 			Buzzer1_start = 0;
				 		    Buzzer1_ack   = 0;
				 		}
				 		
			    		
			    		start_timer1  = 0;
				    	Logic.start_flashing = 0;			    	
					    Logic.AL1_Blink      = 0;
		                Logic.AL1_ACK        = 0;
		                AL1_RELAY_OFF			    		
			    	}
			    }
				 
			}
			else
			{				
				if( ( data <= (Set_point1_temp - Hysterisis1_data) ) && !(Logic.AL1_ACK) )
				{
			        start_timer1  = 1;
				 	
				 	if(Logic.start_flashing)
				 	{
				 		if(!Buzzer1_ack)
				 		{
				 			Buzzer1_start = 1;
				 	        Buzzer_ack    = 0;
				 		}
				 		
				 		
				 		start_timer1    = 0;
				 		Logic.AL1_Blink = 1;
				 		AL1_RELAY_ON
				 	}
				}
			    else if(data > Set_point1_temp)
			    {
				    if(((Logic.AL1_Latch)&&(Logic.AL1_ACK)) || !(Logic.AL1_Latch))
			    	{
			    	    if(Buzzer1_ack)
				 		{
				 			Buzzer1_start = 0;
				 		    Buzzer1_ack   = 0;
				 		}
			    		
			    		start_timer1         = 0;
				    	Logic.start_flashing = 0;			    	
					    Logic.AL1_Blink      = 0;
		                Logic.AL1_ACK        = 0;
		                AL1_RELAY_OFF			    		
			    	}
			    }
		    }
			
	}
	
	if(Logic.AL2)
	{		
			if(Logic.AL2_HI_Logic)
			{
			
				if((data >= (Set_point2_temp + Hysterisis2_data))&&!(Logic.AL2_ACK))
				 {				 	
				 	start_timer2  = 1;
				 	
				 	if(Logic.start_flashing2)
				 	{
				 		if(!Buzzer2_ack)
				 		{
				 			Buzzer2_start = 1;
				 	        Buzzer_ack = 0;
				 		}
				 		
				 		Logic.AL2_Blink = 1;
				 		AL2_RELAY_ON
				 	    start_timer2    = 0;
				 	}
				 }
				
				 else if(data < Set_point2_temp)
			    {
			       if(((Logic.AL2_Latch)&&(Logic.AL2_ACK)) || !(Logic.AL2_Latch))
			    	{
			    	    if(Buzzer2_ack)
				 		{
				 			Buzzer2_start = 0;
				 			Buzzer2_ack = 0;
				 		}
				    	start_timer2  = 0;
				    	Logic.start_flashing2 = 0;			    	
					    Logic.AL2_Blink    = 0;
		                Logic.AL2_ACK      = 0;
		                AL2_RELAY_OFF
			    	}
			    }
				 
			}
			else
			{			
				if((data <= (Set_point2_temp - Hysterisis2_data))&&!(Logic.AL2_ACK))
				{
				    start_timer2  = 1;
				 	
				 	if(Logic.start_flashing2)
				 	{
				 		if(!Buzzer2_ack)
				 		{
				 			Buzzer2_start = 1;
				 	        Buzzer_ack = 0;
				 		}				 			
				 		
				 		Logic.AL2_Blink = 1;
				 		AL2_RELAY_ON
				 	    start_timer2    = 0;
				 	}
				}
			    else if(data > Set_point2_temp)
			    {
				    if(((Logic.AL2_Latch)&&(Logic.AL2_ACK)) || !(Logic.AL2_Latch))
			    	{
			    	    if(Buzzer2_ack)
				 		{
				 			Buzzer2_start = 0;
				 			Buzzer2_ack = 0;
				 		}
				    	start_timer2  = 0;
				    	Logic.start_flashing2 = 0;			    	
					    Logic.AL2_Blink    = 0;
		                Logic.AL2_ACK      = 0;
		                AL2_RELAY_OFF
			    	}
			    }
		    }
						
	}
	
		
	
	if(Logic.AL3)
	{		
			if(Logic.AL3_HI_Logic)
			{
			
				if((data >= (Set_point3_temp + Hysterisis3_data))&&!(Logic.AL3_ACK))
				 {
				 	start_timer3  = 1;
				 	
				 	if(Logic.start_flashing3)
				 	{
				 		if(!Buzzer3_ack)
				 		{
				 			Buzzer3_start = 1;
				 	        Buzzer_ack = 0;
				 		}				 			
				 		
				 		Logic.AL3_Blink = 1;
				 		AL3_RELAY_ON
				 	    start_timer3    = 0;
				 	}
				 }
				
				 else if(data < Set_point3_temp)
			    {
			       if(((Logic.AL3_Latch)&&(Logic.AL3_ACK)) || !(Logic.AL3_Latch))
			    	{
			    		if(Buzzer3_ack)
			    		{
			    			Buzzer3_start = 0;
			    			Buzzer3_ack = 0;
			    		}
				    	start_timer3  = 0;
				    	Logic.start_flashing3 = 0;			    	
					    Logic.AL3_Blink    = 0;
		                Logic.AL3_ACK      = 0;
		                AL3_RELAY_OFF
			    	}
			    }				 
			}
			else
			{			
				if((data <= (Set_point3_temp - Hysterisis3_data))&&!(Logic.AL3_ACK))
				{
				    start_timer3  = 1;
				 	
				 	if(Logic.start_flashing3)
				 	{
				 		if(!Buzzer3_ack)
				 		{
				 			Buzzer3_start = 1;
				 	        Buzzer_ack = 0;
				 		}				 			
				 		
				 		Logic.AL3_Blink = 1;
				 		AL3_RELAY_ON
				 	    start_timer3    = 0;
				 	}
				}
			    else if(data > Set_point3_temp)
			    {
				    if(((Logic.AL3_Latch)&&(Logic.AL3_ACK)) || !(Logic.AL3_Latch))
			    	{
			    		if(Buzzer3_ack)
			    		{
			    			Buzzer3_start = 0;
			    			Buzzer3_ack = 0;
			    		}
			    		
				    	start_timer3  = 0;
				    	Logic.start_flashing3 = 0;			    	
					    Logic.AL3_Blink    = 0;
		                Logic.AL3_ACK      = 0;
		                AL3_RELAY_OFF
			    	}
			    }
		    }
						
	}
	
	
	
	if(Logic.AL4)
	{		
			if(Logic.AL4_HI_Logic)
			{
			
				if((data >= (Set_point4_temp + Hysterisis4_data))&&!(Logic.AL4_ACK))
				 {
				 	start_timer4  = 1;
				 	
				 	if(Logic.start_flashing4)
				 	{
				 		if(!Buzzer4_ack)
				 		{
				 			Buzzer4_start = 1;
				 	        Buzzer_ack = 0;
				 		}					 			
				 		
				 		Logic.AL4_Blink = 1;
				 		AL4_RELAY_ON
				 	    start_timer4    = 0;
				 	}
				 }
				
				 else if(data < Set_point4_temp)
			    {
			       if(((Logic.AL4_Latch)&&(Logic.AL4_ACK)) || !(Logic.AL4_Latch))
			    	{
			    		if(Buzzer4_ack)
			    		{
			    			Buzzer4_start = 0;
			    			Buzzer4_ack   = 0;
			    		}
			    		
				    	start_timer4  = 0;
				    	Logic.start_flashing4 = 0;			    	
					    Logic.AL4_Blink    = 0;
		                Logic.AL4_ACK      = 0;
		                AL4_RELAY_OFF
			    	}
			    }				 
			}
			else
			{			
				if((data <= (Set_point4_temp - Hysterisis4_data))&&!(Logic.AL4_ACK))
				{
				    start_timer4  = 1;
				 	
				 	if(Logic.start_flashing4)
				 	{
				 		if(!Buzzer4_ack)
				 		{
				 			Buzzer4_start = 1;
				 		    Buzzer_ack = 0;
				 		}	
				 		
				 		Logic.AL4_Blink = 1;
				 		AL4_RELAY_ON
				 	    start_timer4    = 0;
				 	}
				}
			    else if(data > Set_point4_temp)
			    {
				    if(((Logic.AL4_Latch)&&(Logic.AL4_ACK)) || !(Logic.AL4_Latch))
			    	{
			    		if(Buzzer4_ack)
			    		{
			    			Buzzer4_start = 0;
			    			Buzzer4_ack = 0;
			    		}
			    		
				    	start_timer4  = 0;
				    	Logic.start_flashing4 = 0;			    	
					    Logic.AL4_Blink    = 0;
		                Logic.AL4_ACK      = 0;
		                AL4_RELAY_OFF
			    	}
			    }
		    }
						
	}
	
	
	

}


void Logic_Flags_Reset(void)
{
    Logic.AL1_Blink       = 0;
    Logic.AL2_Blink       = 0;
    Logic.AL3_Blink       = 0;
    Logic.AL4_Blink       = 0;

    Logic.AL1_ACK         = 0;
    Logic.AL2_ACK         = 0;
    Logic.AL3_ACK         = 0;
    Logic.AL4_ACK         = 0;
    
    Logic.start_relay1    = 0;
    Logic.start_relay2    = 0;
    Logic.start_relay3    = 0;
    Logic.start_relay4    = 0;
    
    Logic.start_flashing  = 0;
    Logic.start_flashing2 = 0;
    Logic.start_flashing3 = 0;
    Logic.start_flashing4 = 0;
}

