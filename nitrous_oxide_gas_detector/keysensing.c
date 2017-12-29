#include "system.h"

struct General_Flags  GF;
struct Button_Flags   Current_Button;
struct Menu_Flags     Current_Menu;

struct Serial_Flags   Current_Serial;
struct Display_Flags  Current_Display;
struct Alarm_Flags    Current_Alarm;
struct Output_Flags   Current_Output;
struct Passward_Flags Current_Passward;
struct Backlit_Flags  Current_Backlit;
struct Test_Flags     Current_Test;



uint8_t Next_Parameter  = 100;
uint8_t Incr_Parameter  = 0;
uint8_t Shift_Parameter = 0;

uint8_t  sec_complete    = 0;
uint8_t  minute_complete = 0;
uint8_t  hour_complete   = 0;

uint8_t Button         = 100;
uint8_t Menu           = 1;
uint8_t Backlit_Count  = 1;
uint8_t Backlit_Count_update = 1;
uint8_t Backlit_damp   = 1;
uint8_t Timeout_Count  = 1;
volatile uint8_t saving_value = 0;
uint8_t number_of_digits1 = 0;
uint8_t flash1 = 0;

uint16_t  passward_1   = 100;
uint32_t  Number       = 0;
uint32_t  range_temp;
uint32_t  overrange_temp;
uint32_t  Hysterisis1_data_temp  = 0;
uint32_t  Hysterisis2_data_temp  = 0;

uint8_t  Position      = 0;
uint32_t Limit;

uint32_t  upcount     = 0;
uint32_t  downcount   = 0;

uint8_t  channel = 0;

uint16_t Global_Counter  = 0;
uint16_t Global_Value    = 0;
uint8_t  start_counting  = 0;



void Key_Function(void)
{
	key_code = 0;
    scanned_key = 0;

	if(message == 10)
	{
		if(GF.Next_Button_Flag == 1)
		{		
			if(!GF.Start_Flag)
		      Next_Routine();	       
		}
		
		else if(GF.Shift_Button_Flag == 1)  
		Shift_Routine();
		
		else if(GF.Incr_Button_Flag == 1)
		Incr_Routine();
	} 			
}

void Next_Routine(void)
{
	uint8_t i = 0;
	Incr_Parameter = 0;
	Position = 0;
//	scanned_key    = 0;



	    if((passward_1  == passward)||(passward_1  == 1))
	    {
	    		GF.Valid_passward = 1;
	    	    logic_off  = 1;
	    }
	       
	    if( (Menu == 6)||(Menu == 8))// PASSWORD/TEST
	    {
	    	if(!GF.Valid_passward)
	    	{
	    		    GF.Yes_Flag = 0;
					GF.Show_Conc_Flag = 1;
					Init_flags();
					Menu_Flags_Reset();	
	    	}   	
	    }

    	
	   if((Current_Menu.Exit_Menu_Flag)&&!(Current_Button.Next_Flag))
	   {
			if(GF.Yes_Flag)
			{
				GF.Yes_Flag = 0;
				GF.Show_Conc_Flag = 1;
				Init_flags();
				Menu_Flags_Reset();				
			}
			channel = 0;
		    Menu_Flags_Reset();
			Current_Button.Next_Flag = 0;
			Next_Parameter = 0;
	    }
	
	
	  else if((Current_Serial.Exit_Flag)&&!(Current_Button.Next_Flag))
		{
			if(GF.Yes_Flag)
			{
				saving_value = 1;
				setup_spi_port();
			   
				  // write_byte_memory((Channel_Enable_ADD),Channel_Enable_data);
				   write_byte_memory((Slave_ID_ADD),Slave_ID_data);
				   write_byte_memory((Read_Register_ADD),Read_Register_data);
				   write_2byte_memory((PV_Address_ADD),PV_Address_data);
				   write_byte_memory( Device_ID_ADD, Device_ID_data);
			       write_byte_memory(Baudrate_Count_ADD,Baudrate_Count);
			       write_byte_memory(Parity_Count_ADD,Parity_Count);
			       write_byte_memory(Stop_bit_Count_ADD,Stop_bit_Count);
				   
				  // Channel_Enable_update = Channel_Enable_data;
				   Slave_ID_update       = Slave_ID_data;
				   Read_Register_update  = Read_Register_data;
				   PV_Address_update     = PV_Address_data;
				   Device_ID_data_update = Device_ID_data;
			   	   Baudrate_Count_update = Baudrate_Count;
			       Parity_Count_update   = Parity_Count;
			       Stop_bit_Count_update = Stop_bit_Count;
				   
				    if(Channel_Enable_data == 0)
				    {
				    	Logic.AL1_Blink = 0;
						Logic.AL1_ACK   = 0;
					    start_timer1    = 0;
					    Logic.start_flashing = 0;
						Buzzer1_ack     = 0;
						Buzzer1_start   = 0;
						
						Logic.AL2_Blink = 0;
						Logic.AL2_ACK   = 0;
					    start_timer2    = 0;
					    Logic.start_flashing2 = 0;
						Buzzer2_ack    = 0;
						Buzzer2_start  = 0;
						
						Logic.AL3_Blink = 0;
						Logic.AL3_ACK   = 0;
					    start_timer3    = 0;
					    Logic.start_flashing3 = 0;
						Buzzer3_ack    = 0;
						Buzzer3_start  = 0;
						
						Logic.AL3_Blink = 0;
						Logic.AL3_ACK   = 0;
					    start_timer3    = 0;
					    Logic.start_flashing3 = 0;
						Buzzer3_ack    = 0;
						Buzzer3_start  = 0;
						
                        
                        Status_Flag1 = 0;
                        Status_Flag2 = 0;  		                    		                    
		            }


			    if(Baudrate_Count == 0)
			    Modbus_baudrate = 9600;
				else if(Baudrate_Count == 1)
				Modbus_baudrate = 19200;
				else if(Baudrate_Count == 2)
			    Modbus_baudrate = 38400;
			   
	          
	            UARTInit();
	            UARTInit_1();
	            
	            logic_off = 0;
	            passward_1  = 0;
			    GF.Yes_Flag = 0;
				Menu_Flags_Reset();
				Menu = 1;
				
				saving_value = 0;
			}
			Serial_Flags_Reset();
			Incr_Para_reset();
	        Shift_Para_reset();
	        Current_Button.Next_Flag = 0;
			Next_Parameter = 0;	   
		}	
	
	
		else if((Current_Display.Exit_Flag)&&!(Current_Button.Next_Flag))
		{
		  if(GF.Yes_Flag)
	  	   {
				GF.Yes_Flag = 0;	
				logic_off   = 0;
				passward_1  = 0;				
				Menu_Flags_Reset();
				Menu = 1;				         	
	       }
	       
			Display_Flags_Reset();
			Incr_Para_reset();
	        Shift_Para_reset();
	        Current_Button.Next_Flag = 0;
			Next_Parameter = 0;	   
		}
	
		else if((Current_Alarm.Exit_Flag)&&!(Current_Button.Next_Flag))
		{
			if(GF.Yes_Flag)
			{	
				saving_value = 1;
				setup_spi_port();
				BUZZER_OFF
				logic_off   = 0;
				passward_1  = 0;
				GF.Yes_Flag = 0;
				Menu_Flags_Reset();
				Menu = 1;
				
			   
			   			   
			   write_byte_memory(AL1_ADD,Logic.AL1);
			   write_2byte_memory(Set_point1_ADD,(Set_point1_data * pow(10,dp)));
			   write_2byte_memory(Hysterisis1_ADD,(Hysterisis1_data * pow(10,dp)));
			   write_byte_memory(AL1_HI_Logic_ADD,Logic.AL1_HI_Logic);
		       write_byte_memory(AL1_Latch_ADD,Logic.AL1_Latch);
		       write_2byte_memory(Time_delay1_ADD,Time_delay1_data);
		       if(Set_point1_data == 0)
			   Set_point1_Negative = 0;
			   write_byte_memory(Set_point1_Negative_ADD,Set_point1_Negative);
			   			   
			   write_byte_memory(AL2_ADD,Logic.AL2);
			   write_2byte_memory(Set_point2_ADD,(Set_point2_data * pow(10,dp)));
			   write_2byte_memory(Hysterisis2_ADD,(Hysterisis2_data * pow(10,dp)));
			   write_byte_memory(AL2_HI_Logic_ADD,Logic.AL2_HI_Logic);
		       write_byte_memory(AL2_Latch_ADD,Logic.AL2_Latch);
		       write_2byte_memory(Time_delay2_ADD,Time_delay2_data);
		       if(Set_point2_data == 0)
			   Set_point2_Negative = 0;			      		       	
			   write_byte_memory(Set_point2_Negative_ADD,Set_point2_Negative);
			   			  		   
			   write_byte_memory(AL3_ADD,Logic.AL3);
			   write_2byte_memory(Set_point3_ADD,(Set_point3_data * pow(10,dp)));
			   write_2byte_memory(Hysterisis3_ADD,(Hysterisis3_data * pow(10,dp)));
			   write_byte_memory(AL3_HI_Logic_ADD,Logic.AL3_HI_Logic);
		       write_byte_memory(AL3_Latch_ADD,Logic.AL3_Latch);
		       write_2byte_memory(Time_delay3_ADD,Time_delay3_data);
		       if(Set_point3_data == 0)
			   Set_point3_Negative = 0;			      		       	
			   write_byte_memory(Set_point3_Negative_ADD,Set_point3_Negative);
			   			   
			   write_byte_memory(AL4_ADD,Logic.AL4);
			   write_2byte_memory(Set_point4_ADD,(Set_point4_data * pow(10,dp)));
			   write_2byte_memory(Hysterisis4_ADD,(Hysterisis4_data * pow(10,dp)));
			   write_byte_memory(AL4_HI_Logic_ADD,Logic.AL4_HI_Logic);
		       write_byte_memory(AL4_Latch_ADD,Logic.AL4_Latch);
		       write_2byte_memory(Time_delay4_ADD,Time_delay4_data);
		       if(Set_point4_data == 0)
			   Set_point4_Negative = 0;			      		       	
			   write_byte_memory(Set_point4_Negative_ADD,Set_point4_Negative);
			   
			   write_byte_memory(Buzzer_ON_ADD,Buzzer_ON);

       	          	
				Use_AL1_update  = Logic.AL1;
				Use_AL2_update  = Logic.AL2;
				Use_AL3_update  = Logic.AL3;
				Use_AL4_update  = Logic.AL4;
				
				
				if(Use_AL1_update == 0)
				{
					Logic.AL1_Blink = 0;
					Logic.AL1_ACK   = 0;
				    start_timer1    = 0;
				    Buzzer1_ack     = 0;
      			    Buzzer1_start   = 0; 
				    Logic.start_flashing = 0;
				}
				
				if(Use_AL2_update == 0)
				{
					Logic.AL2_Blink = 0;
					Logic.AL2_ACK   = 0;
				    start_timer2    = 0;
				    Buzzer2_ack     = 0;
      			    Buzzer2_start   = 0; 
				    Logic.start_flashing2 = 0;
				}
				
				if(Use_AL3_update == 0)
				{
					Logic.AL3_Blink = 0;
					Logic.AL3_ACK   = 0;
				    start_timer3    = 0;
				    Buzzer3_ack     = 0;
      			    Buzzer3_start   = 0; 
				    Logic.start_flashing3 = 0;
				}
				
				if(Use_AL4_update == 0)
				{
					Logic.AL4_Blink = 0;
					Logic.AL4_ACK   = 0;
				    start_timer4    = 0;
				    Buzzer4_ack     = 0;
      			    Buzzer4_start   = 0; 
				    Logic.start_flashing4 = 0;
				}
				
				if(Logic.AL1_Latch == 0)
				Logic.AL1_ACK   = 0;
				
				if(Logic.AL2_Latch == 0)
				Logic.AL2_ACK   = 0;
				
				if(Logic.AL3_Latch == 0)
				Logic.AL3_ACK   = 0;
				
				if(Logic.AL4_Latch == 0)
				Logic.AL4_ACK   = 0;
				
				
				if((Set_point1_data_update != Set_point1_data)||(Hysterisis1_data_update != Hysterisis1_data)||(AL1_High_Logic_update != Logic.AL1_HI_Logic)||(Set_point1_Negative_update != Set_point1_Negative))
				{
				  Buzzer1_ack     = 0;
			      Buzzer1_start   = 0; 		
				}
				if((Set_point2_data_update != Set_point2_data)||(Hysterisis2_data_update != Hysterisis2_data)||(AL2_High_Logic_update != Logic.AL2_HI_Logic)||(Set_point2_Negative_update != Set_point2_Negative))
				{
				  Buzzer2_ack     = 0;
			      Buzzer2_start   = 0; 		
				}
				if((Set_point3_data_update != Set_point3_data)||(Hysterisis3_data_update != Hysterisis3_data)||(AL3_High_Logic_update != Logic.AL3_HI_Logic)||(Set_point3_Negative_update != Set_point3_Negative))
				{
				  Buzzer3_ack     = 0;
			      Buzzer3_start   = 0; 		
				}
				if((Set_point4_data_update != Set_point4_data)||(Hysterisis4_data_update != Hysterisis4_data)||(AL4_High_Logic_update != Logic.AL4_HI_Logic)||(Set_point4_Negative_update != Set_point4_Negative))
				{
				  Buzzer4_ack     = 0;
			      Buzzer4_start   = 0; 		
				}
				
				Set_point1_data_update  = Set_point1_data;
				Hysterisis1_data_update = Hysterisis1_data; 
				AL1_High_Logic_update   = Logic.AL1_HI_Logic;
				AL1_Latch_update        = Logic.AL1_Latch;
				Time_delay1_data_update = Time_delay1_data; 
				Set_point1_Negative_update  = Set_point1_Negative;										
				
				Set_point2_data_update  = Set_point2_data;      			    
				Hysterisis2_data_update = Hysterisis2_data;				
				AL2_High_Logic_update   = Logic.AL2_HI_Logic;				
				AL2_Latch_update        = Logic.AL2_Latch;				    
			    Time_delay2_data_update = Time_delay2_data; 
			    Set_point2_Negative_update  = Set_point2_Negative;
			    
			    Set_point3_data_update  = Set_point3_data;      			    
				Hysterisis3_data_update = Hysterisis3_data;				
				AL3_High_Logic_update   = Logic.AL3_HI_Logic;				
				AL3_Latch_update        = Logic.AL3_Latch;				    
			    Time_delay3_data_update = Time_delay3_data;
			    Set_point3_Negative_update  = Set_point3_Negative;
			    
			    Set_point4_data_update  = Set_point4_data;      			    
				Hysterisis4_data_update = Hysterisis4_data;				
				AL4_High_Logic_update   = Logic.AL4_HI_Logic;				
				AL4_Latch_update        = Logic.AL4_Latch;				    
			    Time_delay4_data_update = Time_delay4_data; 
			    Set_point4_Negative_update  = Set_point4_Negative;
			    			    			    						 
			    Buzzer_ON_update = Buzzer_ON;
			    
			    write_byte_memory(AL_Failsafe_ADD,Logic.AL_Failsafe);
			    //write_2byte_memory(Failsafe_Delay_ADD, Fail_Safe_Delay_data);
			    
				AL_Failsafe_update = Logic.AL_Failsafe;
				if(AL_Failsafe_update)
				FAILSAFE_RELAY_ON
			    else
				FAILSAFE_RELAY_OFF
				
 
		     //   Fail_Safe_Delay_data_update = Fail_Safe_Delay_data;

			//UARTInit();
			saving_value = 0;	
			}
			
			Alarm_Flags_Reset();
			Incr_Para_reset();
	        Shift_Para_reset();
	       
	        Next_Parameter = 0;
			Current_Button.Next_Flag = 0;		   
		}
		
		 else if((Current_Output.Exit_Flag)&&!(Current_Button.Next_Flag))
		  {			
			if(GF.Yes_Flag)
			{
				saving_value = 1;
				setup_spi_port();
				
				    if(Output_High_data == 0.0)
				    Output_High_Negative = 0;
				    if(Output_Low_data == 0.0)
				    Output_Low_Negative = 0;
				    
				  
					if((Output_Low_Negative)&&(Output_High_Negative))
					{
						if(Output_High_data >= Output_Low_data)
					    Output_High_data = Output_Low_data - 1.0;
				    }
				    else if(!(Output_Low_Negative) && !(Output_High_Negative))
				    {
				    	if((Output_High_data == 0.0) && (Output_Low_data == 0.0))
				    	{
				    		Output_Low_data  =  0;
					    	Output_High_data =  5.0;
				    	}	
				    				    	
				    	else if(Output_High_data <= Output_Low_data)
					    Output_Low_data = Output_High_data - 1.0;
				    }
				    else if( (!(Output_Low_Negative) && (Output_High_Negative)) )
				    {
				    	Output_Low_Negative  = 0;
				    	Output_High_Negative = 0;
				    					    	
					    Output_Low_data  =  0;
					    Output_High_data =  5.0;
				    }
				    
								
				 write_2byte_memory((Output_High_ADD),(Output_High_data*pow(10,dp)));
				 write_2byte_memory((Output_Low_ADD),(Output_Low_data*pow(10,dp)));
				 write_byte_memory((Output_High_Negative_ADD),Output_High_Negative);
	             write_byte_memory((Output_Low_Negative_ADD),Output_Low_Negative);
	             write_byte_memory((Output_Type_ADD),Output_Type);
	             write_byte_memory(Scale_Type_ADD,Scale_Type);
	             write_2byte_memory((correction_factor_3_8mA_ADD),correction_factor_3_8mA);
		         write_2byte_memory((correction_factor_4mA_ADD),correction_factor_4mA);
		         write_2byte_memory((correction_factor_8mA_ADD),correction_factor_8mA);
		         write_2byte_memory((correction_factor_12mA_ADD),correction_factor_12mA);
		         write_2byte_memory((correction_factor_16mA_ADD),correction_factor_16mA);
		         write_2byte_memory((correction_factor_20mA_ADD),correction_factor_20mA);
		         write_2byte_memory((correction_factor_21mA_ADD),correction_factor_21mA);
		         
		         
			        correction_factor_3_8mA_update = correction_factor_3_8mA;
				    correction_factor_4mA_update  = correction_factor_4mA;
				    correction_factor_8mA_update  = correction_factor_8mA;
				    correction_factor_12mA_update = correction_factor_12mA;
				    correction_factor_16mA_update = correction_factor_16mA;
				    correction_factor_20mA_update = correction_factor_20mA;
				    correction_factor_21mA_update = correction_factor_21mA;			
					Output_Low_data_update = Output_Low_data;
		            Output_High_data_update = Output_High_data;
		            Output_Low_Negative_update = Output_Low_Negative;
		            Output_High_Negative_update = Output_High_Negative;
		            Output_Type_update = Output_Type;
		            Scale_Type_update  = Scale_Type;


			
         	
				logic_off = 0;
				passward_1  = 0;
				GF.Yes_Flag = 0;
				Menu_Flags_Reset();
				Menu = 1;
				saving_value = 0;
				channel = 0;
			}
			Output_Flags_Reset();
			Incr_Para_reset();
	        Shift_Para_reset();
	        Current_Button.Next_Flag = 0;
			Next_Parameter = 0;
		   
		 }
		 
		 
     	 else if((Current_Passward.Exit_Flag)&&!(Current_Button.Next_Flag))
		  {
			if(GF.Yes_Flag)
			{
				logic_off = 0;
				passward_1  = 0;
				GF.Yes_Flag = 0;
				Menu_Flags_Reset();
				Menu = 1;
			}
			
			Passward_Flags_Reset();
			Incr_Para_reset();
	        Shift_Para_reset();
	        Current_Button.Next_Flag = 0;
			Next_Parameter = 0;
			
		   
		 }
		 
		 
     else if((Current_Backlit.Exit_Flag)&&!(Current_Button.Next_Flag))
		{
			if(GF.Yes_Flag)
			{
				saving_value = 1;
				setup_spi_port();
								
			    write_byte_memory(backlit_ADD,Logic.backlit);
			    write_byte_memory(backlit_count_ADD,Backlit_Count);		
			    write_byte_memory(Fault_Flash_ON_ADD,Fault_Flash_ON);        
                			
			    Backlit_Count_update = Backlit_Count;
			    Fault_Flash_ON_update = Fault_Flash_ON;
			    
			    		
				logic_off   = 0;
				passward_1  = 0;
				GF.Yes_Flag = 0;
				Menu_Flags_Reset();
				Menu = 1;
			    saving_value = 0;
			}
			
			Backlit_Flags_Reset();
			Incr_Para_reset();
	        Shift_Para_reset();
	        Current_Button.Next_Flag = 0;
			Next_Parameter = 0;
		   
		}	
		
		
  
  	  else if((Current_Test.Exit_Flag)&&!(Current_Button.Next_Flag))
		  {
			if(GF.Yes_Flag)
			{
			    P1OUT &= ~BIT5; //LED1
	  		    P2OUT |=  BIT4; //RELAY1
	  	   
    	  	    P1OUT &= ~BIT6; //LED2
	  		    P2OUT |=  BIT5; //RELAY2
				
				logic_off   = 0;
				passward_1  = 0;
				Test_data     = 0.0;
				Test_data_Negative = 0;
				GF.Yes_Flag = 0;
				Init_flags();
				channel = 0;
			}
			Test_Flags_Reset();
			Incr_Para_reset();
	        Shift_Para_reset();
	        Current_Button.Next_Flag = 0;
			Next_Parameter = 0;
		   
		 }
		
		
   
	
	
	if(Menu == 1)
	{
		GF.Valid_passward = 0;
		logic_off = 0;
		
		if(!(Current_Button.Next_Flag))
		{
		     if(!(Current_Menu.Serial_Flag))
			  {
				Current_Menu.Serial_Flag = 1;
			    Next_Parameter = Serial_Menu;
			  }
			
			else if(!(Current_Menu.Display_Flag))
			  {		  	
			  	Current_Menu.Display_Flag  = 1;
			  	Next_Parameter = Display_Menu;
			  }
			  						
			else if(!(Current_Menu.Alarm_Flag))
			  {			  	
			  	Current_Menu.Alarm_Flag  = 1;
			  	Next_Parameter = Alarm_Menu;
			  }
			  
			else if(!(Current_Menu.Output_Flag))
			  {
				Current_Menu.Output_Flag = 1;
			    Next_Parameter =  Output_Menu;
			  }
			  
		    else if(!(Current_Menu.Passward_Flag))
			  {
				Current_Menu.Passward_Flag = 1;
			    Next_Parameter = Passward_Menu;
			  }
			  			  
		    else if(!(Current_Menu.Backlit_Flag))
			 {
				Current_Menu.Backlit_Flag = 1;
			    Next_Parameter = Backlit_Menu;
			 }			 			 
			
			else if(!(Current_Menu.Test_Flag))
			 {
				Current_Menu.Test_Flag   = 1;
			    Next_Parameter = Test_Menu;
			 }	
			 			
		    else if(!(Current_Menu.Exit_Menu_Flag))
			{
				Current_Menu.Exit_Menu_Flag  = 1;
			    Next_Parameter = Exit;
			}
						  			   
		   Current_Button.Next_Flag = 1;
		}
		
		Button = Next;	
	}
	
	
	if(Menu == 2)
	{		
		if( !(Current_Button.Next_Flag))
		{
			  
//			  if(!(Current_Serial.Channel_Enable_Flag))
//			  {		  				 	
//			  	Current_Serial.Channel_Enable_Flag   = 1;
//			  	Next_Parameter = Channel_Enable;
//			  }
			  
			  if(!(Current_Serial.Slave_ID_Flag)&&(Channel_Enable_data))
			  {
			  	Position = 0;
			  			  				 	
			  	Current_Serial.Slave_ID_Flag   = 1;
			  	Next_Parameter = Slave_ID;
			  }
			  
			  else if(!(Current_Serial.Read_Register_Flag)&&(Channel_Enable_data))
			  {		  				 	
			  	Current_Serial.Read_Register_Flag   = 1;
			  	Next_Parameter = Read_Register;
			  }
			  
			  else if(!(Current_Serial.PV_Address_Flag)&&(Channel_Enable_data))
			  {
			  	Position = 0;
			 	Number   = 0;
			 		 	
			    Number = (uint32_t)PV_Address_data;
			  			  				 	
			  	Current_Serial.PV_Address_Flag   = 1;
			  	Next_Parameter = PV_Address;
			  }
			  
			  else if(!(Current_Serial.Device_ID_Flag))
			  {
			    Position = 0;
			    
			    Current_Serial.Device_ID_Flag     = 1;
			  	Next_Parameter = Device_ID;
			  }
		
			  else if(!(Current_Serial.Baudrate_Flag))
			  {
			  	Global_Counter =(uint8_t) Baudrate_Count;
                Global_Value   = 1;
                start_counting = 1;
			  				  	
			    Current_Serial.Baudrate_Flag     = 1;
			  	Next_Parameter = Baudrate;
			  }
			  
			   else if(!(Current_Serial.Parity_Flag))
			  {
			  	Global_Counter =(uint8_t) Parity_Count;
                Global_Value   = 2;
			  				  	
			  	Current_Serial.Parity_Flag     = 1;
			  	Next_Parameter = Parity;
			  }
			  
			  else if(!(Current_Serial.Stop_Bits_Flag))
			  {
			  	Global_Values_Reset();
			  	
			    Current_Serial.Stop_Bits_Flag      = 1;
			  	Next_Parameter = Stop_Bits;
			  }
			  
			  else if(!(Current_Serial.Exit_Flag))
			  {
			  	Current_Serial.Exit_Flag      = 1;
			  	Next_Parameter = Exit;
			  }
			  Current_Button.Next_Flag      = 1;
		}
		  
		  Button = Next;  
	}
	
		
	if(Menu == 3)
	{
		  if(!(Current_Button.Next_Flag))	
	      {
			  			  			 		
			  if(!(Current_Display.Resolution_Flag))
			  {		  	
			    Global_Counter =(uint8_t)dp;
                Global_Value   = 3;
                start_counting = 1;			    
			 	
			  	Current_Display.Resolution_Flag   = 1;
			  	Next_Parameter = Resolution;
			  }
			  							  	
			 else if(!(Current_Display.Set_Gas_Flag))
			  {
			  	start_counting = 0;	
			  	
                for(i=0;i<13;i++)
				Name_List.Temp_Name[i] = Name_List.Name1[i];				
				
				Name_List.Temp_Name[13] = '\0';
  			  
			  	Current_Display.Set_Gas_Flag   = 1;
			  	Next_Parameter = Set_Gas;
			  }
			   			  		  
			 else if(!(Current_Display.Set_Unit_Flag))
			  {	
			    Global_Counter =(uint8_t) unit_count;
                Global_Value   = 28;
                start_counting = 1;	
			  		   
			  	Current_Display.Set_Unit_Flag  = 1;
			  	Next_Parameter = Set_Unit;
			  }
			  	  	 		  
			  else if(!(Current_Display.Set_sec_Flag))
		 	  {	
		 	  	Global_Counter =(uint8_t)  sec_lmp ;
                Global_Value   = 59;
                start_counting = 1;	
		 	  		 	  	
		 	  	Current_Display.Set_sec_Flag   = 1;
		 	  	Next_Parameter = Set_sec;
		 	  }
		 	  
		 	  else if(!(Current_Display.Set_minute_Flag))
		 	  {	
		 	  	Global_Counter =(uint8_t)  minute_lmp;
                Global_Value   = 59;
                start_counting = 1;	
		 	  		 	  	
		 	  	Current_Display.Set_minute_Flag = 1;
		 	  	Next_Parameter = Set_minute;
		 	  }
		 	  
		 	  else if(!(Current_Display.Set_hour_Flag))
		 	  {	
		 	  	Global_Counter =(uint8_t)  hour_lmp;
                Global_Value   = 60;
                start_counting = 1;	
                	 	  	
		 	  	Current_Display.Set_hour_Flag = 1;
		 	  	Next_Parameter = Set_hour;
		 	  }
		 	   
		 	  else if(!(Current_Display.Save_Flag))
	 		  {
	 		  	Global_Values_Reset();
	 		  	GF.Yes_Flag = 0;
	 		  	
	 		 	Current_Display.Save_Flag   = 1;
			  	Next_Parameter = Save;		 	
	 		  } 
	 		  		 	  	 		                      		
			  else if(!(Current_Display.Exit_Flag))
			  {		  	
			  	if(GF.Yes_Flag)
			  	{
			  		saving_value = 1;
			  		setup_spi_port();
			  	    UCA0CTL1 |= UCSWRST; 
			  		      	
                   address_val = NAME1_OFFSET_0_ADD;
					for(i=0;i<13;i++)
					{
						write_byte_memory(address_val,Name_List.Temp_Name[i]); 		//NAME1
						address_val = address_val+5;
					}
					address_val = 0;
					
					for(i=0;i<13;i++)
					Name_List.Name1[i] = Name_List.Temp_Name[i];				
				
				    Name_List.Name1[13] = '\0';
					    
	                write_byte_memory(SEC_ADD,sec_lmp);
				    write_byte_memory(MINUTE_ADD,minute_lmp);
				    write_byte_memory(HOUR_ADD,hour_lmp);
                    write_byte_memory((DP_ADD),dp);			  
                    write_2byte_memory((GAS_NO_ADD),gas_no);
					write_byte_memory((UNIT_ADD),unit_count);
	
               	               
	                if(unit_count > 3)
	                write_2byte_memory((GAS_NO_ADD),327);

	                
	                if(dp_update != dp)                	                    
	                {
	                	DP_change_factory_values();		      	                
	                    get_initial_eeprom_values();
	                }

	                dp_update = dp;             
	       		    gas_no_update = gas_no;
	                unit_count_update = unit_count; 	 
	                sec_lmp_update    = sec_lmp;
	                minute_lmp_update = minute_lmp;
	                hour_lmp_update   = hour_lmp;  	

	                             
	               GF.Yes_Flag = 0;
	               UARTInit();     
	               UARTInit_1();         
	  		     }
	  		     else
	  		     {
			        dp = dp_update;	
	  		     	gas_no = gas_no_update;
	                unit_count = unit_count_update; 	   	
	                
	                sec_lmp    = sec_lmp_update;
	                minute_lmp = minute_lmp_update;
	                hour_lmp   = hour_lmp_update;
	  		     }
	                
	            saving_value = 0;    
			  			  	
			    Current_Display.Exit_Flag    = 1;
			  	Next_Parameter = Exit; 
			  }
			  
			  Current_Button.Next_Flag   = 1;
	   }
	  			  
		Button = Next;
	}
	
	 else if(Menu == 4)
	{	
	
	
/****************************Set_Point = 1 START************************************/					
			 if(!(Current_Alarm.Alarm1_Flag) && !(Current_Button.Next_Flag))
			 {
			  	Set_Point = 1;
			  	
			  	Current_Alarm.Alarm1_Flag  = 1;
			  	Current_Button.Next_Flag   = 1;
			  	Next_Parameter = Alarm;
			 }
			
			 else if((Set_Point == 1) && (Logic.AL1) && (Current_Alarm.Alarm1_Flag)&&!(Current_Alarm.Set_point1_Flag)&&!(Current_Alarm.Alarm2_Flag)&&!(Current_Alarm.Exit_Flag)&&!(Current_Button.Next_Flag))
			 {				
			 	GF.Yes_Flag = 0;
			 	Position = 0;
			 	Number = 0;
			 	
			 	
			 	Negative_value = Set_point1_Negative;		 	
			    Number = (uint32_t)(Set_point1_data*pow(10,dp));
			 	
		        Current_Alarm.Set_point1_Flag = 1;
			    Current_Button.Next_Flag      = 1;
			    Next_Parameter = Set_point;
			 }  
			 
			 else if((Set_Point == 1) &&(Current_Alarm.Set_point1_Flag)&&!(Current_Alarm.Hysterisis1_Flag)&&!(Current_Button.Next_Flag))
			 {			
		        Position  = 0;	
		        Number = 0; 
		        
		        Number  = (uint32_t)(Hysterisis1_data*pow(10,dp));		        

		        
				Current_Alarm.Hysterisis1_Flag = 1;
			    Current_Button.Next_Flag       = 1;
			    
			    Next_Parameter = Hysterisis;
			 }  
			 
			 else if((Set_Point == 1) &&(Current_Alarm.Hysterisis1_Flag)&&!(Current_Alarm.Set_Logic1_Flag)&&!(Current_Button.Next_Flag))
			 {                            
				Current_Alarm.Set_Logic1_Flag = 1;				
			    Current_Button.Next_Flag      = 1;
			    Next_Parameter = Set_Logic;
			 }  
			 
			 else if((Set_Point == 1) &&(Current_Alarm.Set_Logic1_Flag)&&!(Current_Alarm.Latch1_Flag)&&!(Current_Button.Next_Flag))
			 { 
				Current_Alarm.Latch1_Flag     = 1;
			    Current_Button.Next_Flag      = 1;
			    Next_Parameter = Latch;
			 }  
			 
			 else if((Set_Point == 1) && (Current_Alarm.Latch1_Flag)&&!(Current_Alarm.Time_delay1_Flag)&&!(Current_Button.Next_Flag))
			 {		
			 	 Position = 0;
			 	
			 	 Global_Counter = Time_delay1_data;
                 Global_Value   = 999;
                 start_counting  = 1;
			 	
				Current_Alarm.Time_delay1_Flag = 1;
			    Current_Button.Next_Flag       = 1;
			    Next_Parameter = Time_delay;
			 }
/****************************Set_Point = 1 END************************************/ 
		
		
			
/****************************Set_Point = 2 START************************************/		   
		      else if((Set_Point == 1) && !(Current_Alarm.Alarm2_Flag) && !(Current_Button.Next_Flag))
				 { 
				  	start_counting  = 0; 
				  	Set_Point = 2;
			        
				  	Current_Alarm.Alarm2_Flag  = 1;
				  	Current_Button.Next_Flag   = 1;
				  	Next_Parameter = Alarm;
				 }
				
				else if((Set_Point == 2) && (Logic.AL2) &&(Current_Alarm.Alarm2_Flag)&&!(Current_Alarm.Set_point2_Flag)&&!(Current_Alarm.Exit_Flag)&&!(Current_Alarm.Fail_Safe_Flag)&&!(Current_Button.Next_Flag))
				 {			
				 	Position = 0;
				 	Number   = 0;

				 	Negative_value = Set_point2_Negative;				 	
				 	Number = (uint32_t)(Set_point2_data*pow(10,dp));
				 	
					Current_Alarm.Set_point2_Flag = 1;
				    Current_Button.Next_Flag      = 1;
				    Next_Parameter = Set_point;
				 }  
				 
				 else if((Set_Point == 2) && (Current_Alarm.Set_point2_Flag)&&!(Current_Alarm.Hysterisis2_Flag)&&!(Current_Button.Next_Flag))
				 {		   
		            Position  = 0;
		            Number   = 0;
		        
		        	Number   = (uint32_t)(Hysterisis2_data*pow(10,dp));		        
		                        				 	
					Current_Alarm.Hysterisis2_Flag = 1;
				    Current_Button.Next_Flag       = 1;
				    Next_Parameter = Hysterisis;
				 }  
				 
				 else if((Set_Point == 2) &&(Current_Alarm.Hysterisis2_Flag)&&!(Current_Alarm.Set_Logic2_Flag)&&!(Current_Button.Next_Flag))
	             {
					Current_Alarm.Set_Logic2_Flag = 1;
				    Current_Button.Next_Flag      = 1;
				    Next_Parameter = Set_Logic;
				 }  
				 
				 else if((Set_Point == 2) && (Current_Alarm.Set_Logic2_Flag)&&!(Current_Alarm.Latch2_Flag)&&!(Current_Button.Next_Flag))
				 {					 			
					Current_Alarm.Latch2_Flag     = 1;
				    Current_Button.Next_Flag      = 1;
				    Next_Parameter =Latch;
				 }  
				 
				 else if((Set_Point == 2) && (Current_Alarm.Latch2_Flag)&&!(Current_Alarm.Time_delay2_Flag)&&!(Current_Button.Next_Flag))
				 {				
				 	Position = 0;
				 	
				    Global_Counter = Time_delay2_data;
                    Global_Value   = 999;
                    start_counting  = 1;
				 	
					Current_Alarm.Time_delay2_Flag = 1;
				    Current_Button.Next_Flag       = 1;
				    Next_Parameter = Time_delay;
				 }
/****************************Set_Point = 2 END************************************/
			    
			    
/****************************Set_Point = 3 START************************************/			    
			    else if((Set_Point == 2) && !(Current_Alarm.Alarm3_Flag) && !(Current_Button.Next_Flag))
				  {
				  	start_counting  = 0; 
				  	Set_Point = 3;
				  				
				  	Current_Alarm.Alarm3_Flag  = 1;
				  	Current_Button.Next_Flag   = 1;
				  	Next_Parameter = Alarm;
				  }
				
				else if((Set_Point == 3) && (Logic.AL3) && (Current_Alarm.Alarm3_Flag)&&!(Current_Alarm.Set_point3_Flag)&&!(Current_Alarm.Exit_Flag)&&!(Current_Alarm.Fail_Safe_Flag)&&!(Current_Button.Next_Flag))
				 {			
				 	Position = 0;
				 	Number  = 0;
				 	
				 	
				 	Negative_value = Set_point3_Negative;				 	
				 	Number = (uint32_t)(Set_point3_data*pow(10,dp));
				 	
					Current_Alarm.Set_point3_Flag = 1;
				    Current_Button.Next_Flag      = 1;
				    Next_Parameter = Set_point;
				 }  
				 
				 else if((Set_Point == 3) && (Current_Alarm.Set_point3_Flag)&&!(Current_Alarm.Hysterisis3_Flag)&&!(Current_Button.Next_Flag))
				 {
			   
		            Position  = 0;
		            Number  = 0;		            
                    
		        	Number  = (uint32_t)(Hysterisis3_data*pow(10,dp));		        
                					 	
					Current_Alarm.Hysterisis3_Flag = 1;
				    Current_Button.Next_Flag       = 1;
				    Next_Parameter = Hysterisis;
				 }  
				 
				 else if((Set_Point == 3) && (Current_Alarm.Hysterisis3_Flag)&&!(Current_Alarm.Set_Logic3_Flag)&&!(Current_Button.Next_Flag))
	             {
					Current_Alarm.Set_Logic3_Flag = 1;					
				    Current_Button.Next_Flag      = 1;
				    Next_Parameter = Set_Logic;
				 }  
				 
				 else if((Set_Point == 3) && (Current_Alarm.Set_Logic3_Flag)&&!(Current_Alarm.Latch3_Flag)&&!(Current_Button.Next_Flag))
				 {						 			
					Current_Alarm.Latch3_Flag     = 1;
				    Current_Button.Next_Flag      = 1;
				    Next_Parameter = Latch;
				 }  
				 
				 else if((Set_Point == 3) && (Current_Alarm.Latch3_Flag)&&!(Current_Alarm.Time_delay3_Flag)&&!(Current_Button.Next_Flag))
				 {
				 	Position = 0;

				 	
				    Global_Counter = Time_delay3_data;
                    Global_Value   = 999;
                    start_counting  = 1;
				 	
				 	
					Current_Alarm.Time_delay3_Flag = 1;
				    Current_Button.Next_Flag       = 1;
				    Next_Parameter = Time_delay;
				 }
/****************************Set_Point = 3 END************************************/				
			    
			    
/****************************Set_Point = 4 START************************************/			    
			    else if((Set_Point == 3) && !(Current_Alarm.Alarm4_Flag) && !(Current_Button.Next_Flag))
				  { 
				  	start_counting  = 0;
				  	Set_Point = 4;
				  	
				  	Current_Alarm.Alarm4_Flag  = 1;
				  	Current_Button.Next_Flag   = 1;
				  	Next_Parameter = Alarm;
				  }
				
				else if((Set_Point == 4) && (Logic.AL4) && (Current_Alarm.Alarm4_Flag) && !(Current_Alarm.Set_point4_Flag) && !(Current_Alarm.Exit_Flag) && !(Current_Alarm.Fail_Safe_Flag) && !(Current_Button.Next_Flag))
				 {			
				 	Position    = 0;
				 	Number      = 0;
				 	
				 	
				 	Negative_value = Set_point4_Negative;				 	
				 	Number = (uint32_t)(Set_point4_data*pow(10,dp));
				 	
					Current_Alarm.Set_point4_Flag = 1;
				    Current_Button.Next_Flag      = 1;
				    Next_Parameter = Set_point;
				 }  
				 
				 else if((Set_Point == 4) &&  (Current_Alarm.Set_point4_Flag)&&!(Current_Alarm.Hysterisis4_Flag)&&!(Current_Button.Next_Flag))
				 {
			   
		            Position = 0;
		            Number   = 0;
		           		       		
		       		Number   = (uint32_t)(Hysterisis4_data*pow(10,dp));		        
                					 	
					Current_Alarm.Hysterisis4_Flag = 1;
				    Current_Button.Next_Flag       = 1;
				    Next_Parameter = Hysterisis;
				 }  
				 
				 else if((Set_Point == 4) && (Current_Alarm.Hysterisis4_Flag)&&!(Current_Alarm.Set_Logic4_Flag)&&!(Current_Button.Next_Flag))
	             {
					Global_Values_Reset();                 

				    
					Current_Alarm.Set_Logic4_Flag = 1;					
				    Current_Button.Next_Flag      = 1;
				    Next_Parameter = Set_Logic;
				 }  
				 
				 else if((Set_Point == 4) && (Current_Alarm.Set_Logic4_Flag)&&!(Current_Alarm.Latch4_Flag)&&!(Current_Button.Next_Flag))
				 {			
					Current_Alarm.Latch4_Flag     = 1;
				    Current_Button.Next_Flag      = 1;
				    Next_Parameter =Latch;
				 }  
				 
				 else if((Set_Point == 4) && (Current_Alarm.Latch4_Flag)&&!(Current_Alarm.Time_delay4_Flag)&&!(Current_Button.Next_Flag))
				 {
				
				 	GF.Yes_Flag = 0;
				 	Position    = 0;
				 	
				 	Global_Counter = Time_delay4_data;
                    Global_Value   = 999;
                    start_counting  = 1;
				 	
					Current_Alarm.Time_delay4_Flag = 1;
				    Current_Button.Next_Flag       = 1;
				    Next_Parameter = Time_delay;
				 }
/****************************Set_Point = 4 END************************************/				 

				 
				else if((Set_Point == 4)&&!(Current_Alarm.Buzzer_Flag) && !(Current_Button.Next_Flag))
			    {
			    	start_counting  = 0;
			    	Set_Point = 0;
			    	
				    Current_Alarm.Buzzer_Flag  = 1;
			        Current_Button.Next_Flag   = 1;
			        Next_Parameter = Buzzer;
			    } 		  
				 else if((Current_Alarm.Buzzer_Flag) && !(Current_Alarm.Fail_Safe_Flag)&&!(Current_Button.Next_Flag))
				 {	
					Current_Alarm.Fail_Safe_Flag   = 1;
				    Current_Button.Next_Flag       = 1;
				    Next_Parameter = Fail_Safe;
				 }
//				 else if((Current_Alarm.Fail_Safe_Flag) && !(Current_Alarm.Fail_Safe_Delay_Flag)&&!(Current_Button.Next_Flag))
//				 {
//				 	
//				 	Global_Counter_16bit = Fail_Safe_Delay_data;
//                    Global_Value_16bit   = 999;
//                    start_counting  = 1;
//				 		
//					Current_Alarm.Fail_Safe_Delay_Flag   = 1;
//				    Current_Button.Next_Flag       = 1;
//				    Next_Parameter = Fail_Safe_Delay;
//				 } 
//				 
		 
		
		 
		   else if(!(Current_Alarm.Exit_Flag)&&!(Current_Button.Next_Flag))
		   {
		   	
			Global_Values_Reset();
		   	
		   	Set_Point = 0;
		   	upcount   = 0;
            downcount = 0;		   	
		   	Current_Alarm.Exit_Flag   = 1;
		    Current_Button.Next_Flag  = 1;
		    Next_Parameter = Exit;
		   }
		 
    Button = Next;
	}
	

   if(Menu == 5)
	{
		if(!(Current_Button.Next_Flag))
		{
			 if(!(Current_Output.Output_Low_Flag))
			  {
			  	    current_output = 0;
			  	    Position = 0;
				 	Number   = 0;
				 	
				 	Negative_value = Output_Low_Negative;		  	   
				 	Number = (uint32_t)(Output_Low_data*pow(10,dp));
			  			  	 
			  		  	
			  	Current_Output.Output_Low_Flag   = 1;	 
			  	Next_Parameter = Output_Low;	  		  	
			  }
					
			
			else if(!(Current_Output.Output_High_Flag))
			  { 		  	
			  	    Position = 0;
				 	Number   = 0;
				 	
				 	Negative_value = Output_High_Negative;		  	  
				 	Number = (uint32_t)(Output_High_data*pow(10,dp));
		  	   
			  	   		        		
			  	Current_Output.Output_High_Flag    = 1;
			  	Next_Parameter = Output_High;
			  }
			  
			
			 else if(!(Current_Output.Select_Output_Type_Flag))
			 {
			 	Global_Counter =(uint8_t)Output_Type;	
			 	Global_Value   = 3;
                start_counting = 1;	
			 				 		  	    
		        Current_Output.Select_Output_Type_Flag    = 1;
			  	Next_Parameter = Select_Output_Type;		  
			 }
			 
			else if(!(Current_Output.Set_3_8mA_Flag))
			  {	
			  		  		  	
			  	Position = 0;
			  	Global_Counter =(uint16_t)  correction_factor_3_8mA;
                Global_Value   = 600;
                start_counting = 1;	
			  	
	             
	            if((Output_Type == 0)||(Output_Type == 1)) 
	            write_to_register(CONTROL_REG, (OUTPUT_EN|CURRENT_0_24mA));
	            
	            else if((Output_Type == 2)||(Output_Type == 3)) 
	            write_to_register(CONTROL_REG, (OUTPUT_EN|VOLTAGE_0_10V));
	            	    
			  	
			    Current_Output.Set_3_8mA_Flag     = 1;
			  	Next_Parameter = Set_3_8mA;
			  }
			  
			else if(!(Current_Output.Set_4mA_Flag))
			  {		  	  	
			  	Position = 0;
	            Global_Counter =(uint16_t) correction_factor_4mA;

			  	
			    Current_Output.Set_4mA_Flag    = 1;
			  	Next_Parameter = Set_4mA;
			  }
			  
			  else if( !(Current_Output.Set_8mA_Flag))
			  {
			  	Position = 0;
			  	Global_Counter =(uint16_t) correction_factor_8mA;
	
			  	
			    Current_Output.Set_8mA_Flag    = 1;
			  	Next_Parameter = Set_8mA;
			  }
			  
			  else if(!(Current_Output.Set_12mA_Flag))
			  {	
			  	Position = 0;
			  	Global_Counter =(uint16_t) correction_factor_12mA;
	
			  	
			    Current_Output.Set_12mA_Flag    = 1;
			  	Next_Parameter = Set_12mA;
			  }
			  
			  else if(!(Current_Output.Set_16mA_Flag))
			  {		  	
			  	Position = 0;
			  	Global_Counter =(uint16_t) correction_factor_16mA;
	
			  	
			    Current_Output.Set_16mA_Flag     = 1;
			  	Next_Parameter = Set_16mA;
			  }
			  
			  else if(!(Current_Output.Set_20mA_Flag))
			  {
			  	Position = 0;
			  	Global_Counter =(uint16_t) correction_factor_20mA;
	
			  	
			    Current_Output.Set_20mA_Flag    = 1;
			  	Next_Parameter = Set_20mA;
			  }
			  			  
			  else if( !(Current_Output.Set_21mA_Flag))
			  {		  	
			  	Position = 0;
			  	Global_Counter =(uint16_t) correction_factor_21mA;
		
			  	
			    Current_Output.Set_21mA_Flag    = 1;
			  	Next_Parameter = Set_21mA;
			  }
			  			 				  
		     else if( !(Current_Output.Select_scale_Flag))
			  {		  	
			  	current_output = 0;	
			  	Global_Values_Reset();	
			  		  	    
		        Current_Output.Select_scale_Flag    = 1;
			  	Next_Parameter = Select_scale;		  
			  }
					   
		     else if(!(Current_Output.Exit_Flag))
			  {
			  	Current_Output.Exit_Flag     = 1;
			  	Next_Parameter = Exit;
			  }
			  
			  Current_Button.Next_Flag     = 1;
		}
		  
		  Button = Next;
	}
	
	
	if(Menu == 6)
	{
		if(!(Current_Button.Next_Flag))
		{
		   if(!(Current_Passward.Old_Password_Flag))
			{
			    Current_Passward.Old_Password_Flag  = 1;
			  	Next_Parameter = Old_Password;			
			}
			
			else if(!(Current_Passward.Set_New_Flag))
			  {		  
			    Position = 0;
			  	Number   = 0;
			  	
			  	Current_Passward.Set_New_Flag    = 1;
			  	Next_Parameter = Set_New;
			  }
			  			
			 else if(!(Current_Passward.Sure_Flag))
			  {
			  	Current_Passward.Sure_Flag      = 1;
			  	Next_Parameter = Sure;
			  }
			  
			else if(!(Current_Passward.Exit_Flag))
			  {
			  	if(GF.Yes_Flag)
			  	{
			  		GF.Yes_Flag = 0;
			  		setup_spi_port();
				  	write_2byte_memory(PASSWARD_ADD,new_passward);
			        passward = read_2byte_memory(PASSWARD_ADD);
			  	}
			  	
			  	Current_Passward.Exit_Flag     = 1;
			  	Next_Parameter = Exit;
			  }
			  
			 Current_Button.Next_Flag       = 1;
		}
  
		  Button = Next;
	}
	
   if(Menu == 7)
	{
		if(!(Current_Button.Next_Flag))
	    {
			 if(!(Current_Backlit.Set_Backlit_Flag))
			  {		  
			  	Current_Backlit.Set_Backlit_Flag  = 1;
			  	Next_Parameter = Set_Backlit;
			  }
			  
			 else if(!(Current_Backlit.Fault_Flash_Flag))
			  {		  
			  	Current_Backlit.Fault_Flash_Flag   = 1;
			  	Next_Parameter = Fault_Flash;
			  }
				   
			 else if(!(Current_Backlit.Exit_Flag))
			  {
			  	Current_Backlit.Exit_Flag     = 1;
			  	Next_Parameter = Exit;
			  }
			  Current_Button.Next_Flag      = 1;
	    }
	  
		  Button = Next;
	}

		
	if(Menu == 8)
	{
		if (!(Current_Button.Next_Flag))
		{			
			 if(!(Current_Test.Test_Flag))
			  {
			  	Position = 0;
			  	Number   = 0;	
	

			  	Current_Test.Test_Flag        = 1;
			  	Next_Parameter = Test;
			  
			  }
			  
			else if( !(Current_Test.Exit_Flag))
			  {
			 	Current_Test.Exit_Flag         = 1;
			  	Next_Parameter = Exit;
			  }
		  
		  Current_Button.Next_Flag       = 1;
		}
		  

		  Button = Next;  
	}
		
	
	GF.Next_Button_Flag = 0;

}



void Shift_Routine(void)
{
//	scanned_key    = 0;

    if((start_counting)&&(GF.Valid_passward))
	{
		upcount = 0;
		if(Global_Counter > 0)
		{
			downcount++;
			Global_Counter--;
		}
		else
		Global_Counter = Global_Value;
	}

    
   else if((Next_Parameter == Alarm) && (GF.Valid_passward)) 
   	{
   		Use_AL = 1;
   		        	
    	if(Set_Point == 1)
    	Logic.AL1 = Use_AL;
        else if(Set_Point == 2)
        Logic.AL2 = Use_AL;
        else if(Set_Point == 3)			    	        
        Logic.AL3 = Use_AL;	                        
        else if(Set_Point == 4)			    	       
        Logic.AL4 = Use_AL;	
   	}
   	  	
   	else if((Next_Parameter == Latch) && (GF.Valid_passward)) 
   	{
   		AL_Latch = 1;
			   	 	
    	if(Set_Point == 1)
    	Logic.AL1_Latch = AL_Latch;
        else if(Set_Point == 2)
        Logic.AL2_Latch = AL_Latch;
        else if(Set_Point == 3)			    	        
        Logic.AL3_Latch = AL_Latch;	                        
        else if(Set_Point == 4)			    	       
        Logic.AL4_Latch = AL_Latch;
   	}
   	
   	else if((Next_Parameter == Set_Logic) && (GF.Valid_passward)) 
    {
    	AL_High_Logic = 0;
	   		
    	if(Set_Point == 1)
    	Logic.AL1_HI_Logic  = AL_High_Logic;
        else if(Set_Point == 2)
        Logic.AL2_HI_Logic  = AL_High_Logic;
        else if(Set_Point == 3)			    	        
        Logic.AL3_HI_Logic  = AL_High_Logic;	                        
        else if(Set_Point == 4)			    	       
        Logic.AL4_HI_Logic  = AL_High_Logic;
    }
   	   
    else if((Next_Parameter == Buzzer)&&(GF.Valid_passward))
    Buzzer_ON = 1;
    
    
    else if((Next_Parameter == Fail_Safe)&&(GF.Valid_passward))
	Logic.AL_Failsafe = 1;
		   	
	else if((Next_Parameter == Fault_Flash)&&(GF.Valid_passward))
    Fault_Flash_ON = 1;
     

	
     
    else if((Next_Parameter == Channel_Enable) && (GF.Valid_passward)) 
    Channel_Enable_data = 0;
    
    else if((Next_Parameter == Read_Register) && (GF.Valid_passward)) 
    Read_Register_data = 0;
        
    else if((Next_Parameter == Stop_Bits)&&(GF.Valid_passward))
	Stop_bit_Count = 1;
	 
	else if((Next_Parameter == Select_scale)&&(GF.Valid_passward))
    Scale_Type = 0;

    else if((Next_Parameter == Set_Backlit)&&(GF.Valid_passward))
     {   	
	     	if(Backlit_Count <= 1)
	        Backlit_Count = 3;
	        else
	        Backlit_Count--;     
     }
    
         
    else if((Next_Parameter == Slave_ID)&&(GF.Valid_passward))
	{
		upcount   = 0;
		if(Slave_ID_data > 1)
		{
			Slave_ID_data--;
			downcount++;
		}
		else
		Slave_ID_data = 255;
	}
    
     
    else if((Next_Parameter == Device_ID)&&(GF.Valid_passward))
	{
		upcount   = 0;
		if(Device_ID_data > 1)
		{
			Device_ID_data--;
			downcount++;
		}
		else
		Device_ID_data = 255;
	 }
    
      
    else if((Next_Parameter == Exit)||(Next_Parameter == Save)||((Next_Parameter == Sure)&&(GF.Valid_passward)) )
   	 {		   	   	    
   	   	GF.No_Flag   = 0;
   	    GF.Yes_Flag  = 1;
        Shift_Parameter = YES;
        Current_Button.Shift_Flag = 1;
        Button = Shift;
     }  
     
		  	
	  else if((Incr_Parameter == Passward)||(Next_Parameter == Set_point)||(Next_Parameter == Hysterisis)||( Next_Parameter == Output_High)||(Next_Parameter == Output_Low)||(Next_Parameter == Set_New)||(Next_Parameter == Test)||(Next_Parameter == PV_Address)&&!(Current_Button.Shift_Flag))
	   {
	   	 if((Incr_Parameter == Passward)||(GF.Valid_passward))	 
	       {
	       	 GF.Toggle = 1;
		     if(Position > 4)
		     Position = 1;
		     else
		     Position++;		     
	       }
	   }
	   
	 else if((Next_Parameter == Set_Gas)&(GF.Valid_passward)&&!(Current_Button.Shift_Flag))
	   {
	       	 GF.Toggle = 1;
		     if(Position > 13)
		     Position = 1;
		     else
		     Position++;		     
	   }
	   
	GF.Shift_Button_Flag = 0; 	
}



void Incr_Routine(void) 
{
     
     if((flash1 == (number_of_digits1+1)) && ((Next_Parameter == Set_point)||(Next_Parameter == Output_High)||(Next_Parameter == Output_Low)||(Next_Parameter == Test)))
     {
     	if(Negative_value)
     	Negative_value = 0;
     	    	
     	else if(!Negative_value)
     	Negative_value = 1;     	
     	
     	if(Next_Parameter == Set_point)
     	{
        	if(Set_Point == 1)
        	Set_point1_Negative = Negative_value;
	        else if(Set_Point == 2)
	        Set_point2_Negative = Negative_value;
	        else if(Set_Point == 3)			    	        
	        Set_point3_Negative = Negative_value;	                        
	        else if(Set_Point == 4)			    	       
	        Set_point4_Negative = Negative_value;
	   	}
     	
     	if(Next_Parameter == Output_High)
     	Output_High_Negative = Negative_value;
     	
     	if(Next_Parameter == Output_Low)
     	Output_Low_Negative = Negative_value; 
     	
     	if(Next_Parameter == Test)
     	Test_data_Negative = Negative_value;     	   		     	
     }
     
    else if((start_counting)&&(GF.Valid_passward))
	{
		downcount = 0;
		if(Global_Counter< Global_Value)
		{
		  upcount++;
		  Global_Counter++;
		}
		else
		Global_Counter = 0;
	}
	
	else if((Next_Parameter == Alarm) && (GF.Valid_passward)) 
   	{
   		Use_AL = 0;
   		        	
    	if(Set_Point == 1)
    	Logic.AL1 = Use_AL;
        else if(Set_Point == 2)
        Logic.AL2 = Use_AL;
        else if(Set_Point == 3)			    	        
        Logic.AL3 = Use_AL;	                        
        else if(Set_Point == 4)			    	       
        Logic.AL4 = Use_AL;	
   	}
   	  	
   	else if((Next_Parameter == Latch) && (GF.Valid_passward)) 
   	{
   		AL_Latch = 0;
			   	 	
    	if(Set_Point == 1)
    	Logic.AL1_Latch = AL_Latch;
        else if(Set_Point == 2)
        Logic.AL2_Latch = AL_Latch;
        else if(Set_Point == 3)			    	        
        Logic.AL3_Latch = AL_Latch;	                        
        else if(Set_Point == 4)			    	       
        Logic.AL4_Latch = AL_Latch;
   	}
   	
   	else if((Next_Parameter == Set_Logic) && (GF.Valid_passward)) 
    {
    	AL_High_Logic = 1;
	   		
    	if(Set_Point == 1)
    	Logic.AL1_HI_Logic  = AL_High_Logic;
        else if(Set_Point == 2)
        Logic.AL2_HI_Logic  = AL_High_Logic;
        else if(Set_Point == 3)			    	        
        Logic.AL3_HI_Logic  = AL_High_Logic;	                        
        else if(Set_Point == 4)			    	       
        Logic.AL4_HI_Logic  = AL_High_Logic;
    }

	else if((Next_Parameter == Buzzer) && (GF.Valid_passward)) 
    Buzzer_ON = 0;
      
    else if((Next_Parameter == Fail_Safe) && (GF.Valid_passward)) 
	Logic.AL_Failsafe = 0;
	
    else if((Next_Parameter == Fault_Flash) && (GF.Valid_passward)) 
	Fault_Flash_ON = 0;

    else if((Next_Parameter == Channel_Enable) && (GF.Valid_passward)) 
    Channel_Enable_data = 1;
    
    else if((Next_Parameter == Read_Register) && (GF.Valid_passward)) 
    Read_Register_data = 1;
       
    else if((Next_Parameter == Stop_Bits)&&(GF.Valid_passward))
	Stop_bit_Count = 2;

    else if((Next_Parameter == Select_scale)&&(GF.Valid_passward))
    Scale_Type = 1;
    
    else if((Next_Parameter == Slave_ID)&&(GF.Valid_passward))
	{
		downcount = 0;
		if(Slave_ID_data < 255)
		{
			upcount = 0;
			Slave_ID_data++;
		}
		else
		Slave_ID_data = 1;
	}
    	
    else if((Next_Parameter == Device_ID)&&(GF.Valid_passward))
	{
		downcount = 0;
		if(Device_ID_data < 255)
		{
			upcount = 0;
			Device_ID_data++;
		}
		else
		Device_ID_data = 1;
	}
         
	   	
    else if( (Next_Parameter == Exit)||(Next_Parameter == Save)||((Next_Parameter == Sure)&&(GF.Valid_passward)) )
 	{	     		
		Current_Button.Incr_Flag = 1;
   	    GF.Yes_Flag    = 0;
   	    GF.No_Flag     = 1;
        Incr_Parameter = NO;
        Button = Incr;
	}
	   
	
    else if((Menu<=1)&&(Next_Parameter == Serial_Menu)&&!(Current_Button.Incr_Flag))
    { 	
    	GF.Valid_passward = 0;
    	Position = 0;
    	Number = 0;
    	
    	Incr_Parameter = Passward;
	    Menu = 2;
	    Button = Incr;
	    Current_Button.Incr_Flag = 1;
    }
	
	
     else if((Menu<=2)&&(Next_Parameter == Display_Menu)&&!(Current_Button.Incr_Flag))
	  {
	  	GF.Valid_passward = 0;
	  	Position = 0;
	  	Number   = 0;
	  
	  	Incr_Parameter = Passward;
	    Menu = 3;
	    Current_Button.Incr_Flag = 1;
	    Button = Incr;
	  }
	
		
	else if((Menu<=3)&&(Next_Parameter == Alarm_Menu)&&!(Current_Button.Incr_Flag))
	  {  
	  	GF.Valid_passward = 0;
	  	Position = 0;
	  	Number   = 0;
	  
	  	Incr_Parameter = Passward;
	    Menu = 4;
	    Current_Button.Incr_Flag = 1;
	    Button = Incr;
	  }
	

      
    else if((Menu<=4)&&(Next_Parameter == Output_Menu)&&!(Current_Button.Incr_Flag))
     {
    	GF.Valid_passward = 0;
    	Position = 0;
    	Number   = 0;
    	
    	Incr_Parameter = Passward;
	    Menu = 5;
	    Button = Incr;
	    Current_Button.Incr_Flag = 1;
     }
      
      
    else if((Menu<=5)&&(Next_Parameter == Passward_Menu)&&!(Current_Button.Incr_Flag))
    {
    	GF.Valid_passward = 0;
    	Position = 0;
    	Number = 0;
    	
    	Incr_Parameter = Passward;
	    Menu = 6;
	    Button = Incr;
	    Current_Button.Incr_Flag = 1;
    }

    
    else if((Menu<=6)&&(Next_Parameter == Backlit_Menu)&&!(Current_Button.Incr_Flag))
    {
    	GF.Valid_passward = 0;
    	Position = 0;
    	Number = 0;
    	
    	Incr_Parameter = Passward;
	    Menu = 7;
	    Button = Incr;
	    Current_Button.Incr_Flag = 1;
    }
    

    else if((Menu<=7)&&(Next_Parameter == Test_Menu)&&!(Current_Button.Incr_Flag))
    { 	
    	GF.Valid_passward = 0;
    	Position = 0;
    	Number = 0;
    	
    	Incr_Parameter = Passward;
	    Menu = 8;
	    Button = Incr;
	    Current_Button.Incr_Flag = 1;
    }
    
    
  
    
    else if(!(set_polarity) && ((Incr_Parameter == Passward)||(Next_Parameter == Set_point)||(Next_Parameter == Hysterisis)||( Next_Parameter == Output_High)||(Next_Parameter == Output_Low)||(Next_Parameter == Set_New)||(Next_Parameter == PV_Address)||(Next_Parameter == Test)))
	 {
	 	 GF.Blink_Flag = 0;
	 
	 	
		 if((Incr_Parameter == Passward)||(GF.Valid_passward))	 
		 {
		 	  GF.Toggle = 0;
		 	  
		      break_digits(Number); 			  
			     switch(Position)
			     {
				    case 1:
				       bcd[0]++;  
				       if (bcd[0] > 9)
				       bcd[0] = 0;
				       break;
				    
				    case 2:
				      bcd[1]++;  
				      if (bcd[1] > 9)
				      bcd[1] = 0;
				      break;
				    
				    case 3:
				      bcd[2]++;  
				      if (bcd[2] > 9)
				      bcd[2] = 0;
				      break;
				    
				    case 4:
				      bcd[3]++;  
				      if (bcd[3] > 9)
				      bcd[3] = 0;
				      break;
				    
				    case 5:
				      bcd[4]++;  
				      if (bcd[4] > 9)
				      bcd[4] = 0;
				      break;
			     }
			  
			     Number = make_digits(); 
	        }
	  }
	  
	  else if((Next_Parameter == Set_Gas)&&(GF.Valid_passward))
	   {
	   	       Name_List.Temp_Name[Position-1]++;

/************************************************************************/	   	
	       		if(Name_List.Temp_Name[Position-1] < 32)
					Name_List.Temp_Name[Position-1] = 32;
		     	
		     	if((Name_List.Temp_Name[Position-1] > 57)&& (Name_List.Temp_Name[Position-1] < 65))
	     			Name_List.Temp_Name[Position-1] = 65;				
					
		     	if(Name_List.Temp_Name[Position-1] > 90)
	     			Name_List.Temp_Name[Position-1] = 32;
	     			
	     		if(Name_List.Temp_Name[Position-1] == 33)
	     			Name_List.Temp_Name[Position-1] = 48;			     				     				     			
/************************************************************************/
 	   	     
	   }
	    

	GF.Incr_Button_Flag = 0;
	
}


void Init_flags(void)
{
	Next_Parameter  = 1;
    Shift_Parameter = 0;
    Incr_Parameter  = 0;

    Menu      = 2;
    Button    = 0;
    logic_off = 0;

	
	Button_Flags_Reset();
	Incr_Para_reset();
	Shift_Para_reset();
	Global_Values_Reset();
	General_Flags_Reset();
	
	
	Menu_Flags_Reset();
	Serial_Flags_Reset();
	Display_Flags_Reset();
	Alarm_Flags_Reset();
	Output_Flags_Reset();
	Passward_Flags_Reset();
	Backlit_Flags_Reset();	
	Test_Flags_Reset();
	
}

void Global_Values_Reset(void)
{
	Global_Counter  = 0;
    Global_Value    = 0;
    start_counting  = 0;
}

void Button_Flags_Reset(void)
{
      Current_Button.Next_Flag     = 0;
      Current_Button.Shift_Flag    = 0;
      Current_Button.Incr_Flag     = 0;
}

void General_Flags_Reset(void)
{	
	 GF.Next_Button_Flag        = 0;
	 GF.Shift_Button_Flag       = 0;
	 GF.Incr_Button_Flag        = 0;	 
	
	 GF.Show_Conc_Flag          = 1;
	 GF.Sec_3_Flag              = 0;	 
	 GF.Start_Flag              = 0;
	 GF.Warm_Up_Flag            = 0;	 	 
	 GF.Yes_Flag                = 0;
	 GF.No_Flag                 = 0;	
	 GF.Blink_Flag              = 0;
	 GF.Valid_passward          = 0;	 
	 GF.Toggle                  = 1;
}


void Menu_Flags_Reset(void)
{	
	  Current_Menu.Serial_Flag       = 0;
	  Current_Menu.Display_Flag      = 0;
      Current_Menu.Alarm_Flag        = 0;
      Current_Menu.Output_Flag       = 0;
      Current_Menu.Passward_Flag     = 0;
      Current_Menu.Backlit_Flag      = 0;
      Current_Menu.Test_Flag         = 0;
      Current_Menu.Exit_Menu_Flag    = 0;
}


void Serial_Flags_Reset(void)
{
	  Current_Serial.Channel_Enable_Flag  = 0;  
	  Current_Serial.Slave_ID_Flag        = 0;  
	  Current_Serial.Read_Register_Flag   = 0;
	  Current_Serial.PV_Address_Flag      = 0;  
	  Current_Serial.Device_ID_Flag       = 0;
      Current_Serial.Baudrate_Flag        = 0;
      Current_Serial.Parity_Flag          = 0;
      Current_Serial.Stop_Bits_Flag       = 0;
      Current_Serial.Exit_Flag            = 0;
}

void Display_Flags_Reset(void)
{
      Current_Display.Resolution_Flag  = 0;
      Current_Display.Set_Gas_Flag     = 0;
      Current_Display.Set_Unit_Flag    = 0;  
      Current_Display.Set_sec_Flag     = 0;
	  Current_Display.Set_minute_Flag  = 0;
	  Current_Display.Set_hour_Flag    = 0;
	  Current_Display.Save_Flag        = 0;   	     
      Current_Display.Exit_Flag        = 0;
}

void Alarm_Flags_Reset(void)
{
     
      Current_Alarm.Alarm1_Flag        =0;
      Current_Alarm.Alarm2_Flag        =0;
      Current_Alarm.Alarm3_Flag        =0;
      Current_Alarm.Alarm4_Flag        =0;
      
      Current_Alarm.Set_point1_Flag    =0;
      Current_Alarm.Set_point2_Flag    =0;
      Current_Alarm.Set_point3_Flag    =0;
      Current_Alarm.Set_point4_Flag    =0;
      
      Current_Alarm.Hysterisis1_Flag   =0;
      Current_Alarm.Hysterisis2_Flag   =0;
      Current_Alarm.Hysterisis3_Flag   =0;
      Current_Alarm.Hysterisis4_Flag   =0;
      
      Current_Alarm.Set_Logic1_Flag    =0;
      Current_Alarm.Set_Logic2_Flag    =0;
      Current_Alarm.Set_Logic3_Flag    =0;
      Current_Alarm.Set_Logic4_Flag    =0;
      
      Current_Alarm.Latch1_Flag        =0;
      Current_Alarm.Latch2_Flag        =0;
      Current_Alarm.Latch3_Flag        =0;
      Current_Alarm.Latch4_Flag        =0;
      
      Current_Alarm.Time_delay1_Flag   =0;
      Current_Alarm.Time_delay2_Flag   =0;
      Current_Alarm.Time_delay3_Flag   =0;
      Current_Alarm.Time_delay4_Flag   =0;
                   
      Current_Alarm.Buzzer_Flag       =0;           
      Current_Alarm.Fail_Safe_Flag    =0; 
      Current_Alarm.Fail_Safe_Delay_Flag = 0;
      Current_Alarm.Exit_Flag          =0;
}



void Output_Flags_Reset(void)
{
      Current_Output.Output_Low_Flag      = 0;
      Current_Output.Output_High_Flag     = 0;
      
      Current_Output.Select_Output_Type_Flag =0;
      Current_Output.Set_3_8mA_Flag     =0;
	  Current_Output.Set_4mA_Flag       =0;
      Current_Output.Set_8mA_Flag		=0;
      Current_Output.Set_12mA_Flag	    =0;
      Current_Output.Set_16mA_Flag      =0;
      Current_Output.Set_20mA_Flag	    =0;
      Current_Output.Set_21mA_Flag		=0; 
      
      Current_Output.Select_scale_Flag   =0;      
      Current_Output.Exit_Flag           =0;
}	


void Passward_Flags_Reset(void)
{
	  Current_Passward.Old_Password_Flag =0;
      Current_Passward.Set_New_Flag      =0;
      Current_Passward.Sure_Flag         =0;
      Current_Passward.Exit_Flag         =0;
}

void Backlit_Flags_Reset(void)
{
	  Current_Backlit.Set_Backlit_Flag   =0;
	  Current_Backlit.Fault_Flash_Flag   =0;
      Current_Backlit.Exit_Flag          =0;
}


void Test_Flags_Reset(void)
{
	Current_Test.Test_Flag         =0;
	Current_Test.Exit_Flag         =0;
}


void Incr_Para_reset(void)
{
	Incr_Parameter = 0;
	GF.Yes_Flag    = 0;
	GF.No_Flag     = 0;
}

void Shift_Para_reset(void)
{
Shift_Parameter = 0;
}





