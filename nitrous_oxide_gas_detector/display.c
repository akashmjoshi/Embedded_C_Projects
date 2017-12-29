#include "system.h"

struct NameParameters Name_List;

unsigned long Modbus_baudrate;

uint16_t toggle_counter  = 0;


uint8_t set_polarity = 0;
uint8_t Negative_value = 0;
uint8_t Show_Peak1  = 0;
uint8_t Failsafe_ON = 0;
float64_t default_correction_factor;



void Start_up(void)
{	
	//uint8_t i = 0;
	delay_ms(100);	
	Send_str("                    ", 0);
	Send_str("                    ", 16);
	switch(message)
	{
	
		case 6:
				Send_str("  AMBETRONICS   ", 0);       				/* Displaying version */ 
		    	Send_str("ENGINERS PVT LTD", 16);	
		    	break;
		
		case 5:
				Send_str(" VERSION 150813 ", 0);      				/* Displaying Device Name */
		    	Send_str("    GM-3315     ", 16);		
		    	break;
		    			    	 					
	    case 4:
	            Send_str("    ALARM-1     ", 0);
	            Send_str((Logic.AL1)?" ON ":"OFF ", 16);
				Send_str((!Logic.AL1_HI_Logic)?"LOW ":"HIGH", 20);			     
     	        Negative_value = Set_point1_Negative;
			    display_with_dp_adv1((uint32_t)(Set_point1_data*pow(10,dp)),26, Position,4,dp);			
		        break;        			
         
    	case 3:
	            Send_str("    ALARM-2     ", 0);
	            Send_str((Logic.AL2)?" ON ":"OFF ", 16);
				Send_str((!Logic.AL2_HI_Logic)?"LOW ":"HIGH", 20);			     
     	        Negative_value = Set_point2_Negative;
			    display_with_dp_adv1((uint32_t)(Set_point2_data*pow(10,dp)),26, Position,4,dp);
				break;
				
		case 2:
	            Send_str("    ALARM-3     ", 0);
	            Send_str((Logic.AL3)?" ON ":"OFF ", 16);
				Send_str((!Logic.AL3_HI_Logic)?"LOW ":"HIGH", 20);			     
     	        Negative_value = Set_point3_Negative;
			    display_with_dp_adv1((uint32_t)(Set_point3_data*pow(10,dp)),26, Position,4,dp);
			
		        break;        			
         
    	case 1:
	            Send_str("    ALARM-4     ", 0);
	            Send_str((Logic.AL4)?" ON ":"OFF ", 16);
				Send_str((!Logic.AL4_HI_Logic)?"LOW ":"HIGH", 20);			     
     	        Negative_value = Set_point4_Negative;
			    display_with_dp_adv1((uint32_t)(Set_point4_data*pow(10,dp)),26, Position,4,dp);

				break;		 		
	   
		case 0:
		        GF.Warm_Up_Flag = 1;
		        		        
		        if(GF.Toggle)
		    	Send_str("  WARM-UP TIME  ", 0);
		    	else
		    	{
		    		display(hour_lmp, 3, 0, 2);
		            Send_str(":", 5);
		            display(minute_lmp, 6, 0, 2);
		            Send_str(":", 8);
		            display(sec_lmp, 9, 0, 2);  
		    	}
		        
		
	    		display(hour_count, 19, 0, 2);
	            Send_str(":", 21);
	            display(minute_count, 22, 0, 2);
	            Send_str(":", 24);
	            display(sec_count, 25, 0, 2);		    		
				break;
	    
	    default:
	    
	   if((!GF.Sec_3_Flag)||(GF.Show_Conc_Flag)||(first_enter2 == 1))  
	    {	    		    	
		    	
		      if((first_enter == 1)||(first_enter2 == 1))
	          {
	          		Send_str(" ENTERING MAIN  ", 0);
				    Send_str("      MENU      ", 16);
	          }
	            
	          else if(Show_Clear_Peak)           
	          {
	          	   if(Peak_Counter3 > 0)
			        {
			        	Send_str("  ALARM STATUS  ", 0);          	    
			        	Send_str("AL1:OFF  AL2:OFF", 16); 
			        	if( (Logic.AL1_Blink) && !(Logic.AL1_ACK) )
			            Send_str("ON ", 20);		            		            
			            	            
			            if( (Logic.AL2_Blink) && !(Logic.AL2_ACK) )
			            Send_str("ON ", 29);
			        }
			        if(Peak_Counter3 > 2000)
			        {
			        	Send_str("  ALARM STATUS  ", 0);
			        	Send_str("AL3:OFF  AL4:OFF", 16);     
			        	if( (Logic.AL3_Blink) && !(Logic.AL3_ACK) )
			            Send_str("ON ", 20);
			            	            
			            if( (Logic.AL4_Blink) && !(Logic.AL4_ACK) )
			            Send_str("ON ", 29);
			        }
	          	   if(Peak_Counter3 > 4000)
	          	    {
	          	        Send_str("                ", 0);	
         	            Send_str("                ", 16);          	    	
		          		Send_str("MASTER ID:", 0);
			            display((uint32_t)Slave_ID_data,10,0,3);
			            Send_str("DEVICE ID:", 16);
			            display((uint32_t)Device_ID_data,26,0,3);
	          	    }
	          }
	
	        
	         else if(System_Chk_Flag)
	         {
	         	Send_str(" SYSTEM CHECK!! ", 0);	
	            Send_str(" WAIT FOR 5 SEC ", 16);
	         }
		     
		     else
		     {	     	
	     	   if(Fail_show)
		        {
		        	  Send_str("                ",0);
		        	  Send_str("                ",16);
		        	  Display_Name(Name_List.Name1,17,0);		         	
				   	  if(comfail_error)
				   	  {
				   	  	Send_str("                ",16);
				   	  	Send_str(" COM FAIL WITH ", 0);
				   	  	Send_str(" MASTER ID",16);
				   	  	display((uint32_t)Slave_ID_data,27,0,3);
				   	  }
				   	  else if(over_error)
					  Send_str("  OVER RANGE!!  ", 0);	
				      else if(open_error)
				      Send_str("  SENSOR OPEN!! ", 0);
				      else if(under_error)
				      Send_str("  UNDER RANGE!! ", 0);	
				      else if(undefined_error)		   
				      Send_str("UNDEFINED RANGE!",0);
		        }
		        else
		     	{	
			     		Negative_value = Process_Negative;			  	  				  	   			          	         
			            display_with_dp_adv1((uint32_t)data_received,3,Position,4,dp);
			            Display_units(9);
			            Display_Name(Name_List.Name1,17,0);			     	 
		     	}	     	
		     }		      	         
	    }
	    else
	    {  
	      switch(Button)
	           {
	           		           	
		      case Next:
		             
		            switch(Next_Parameter)
		            {
		               case Display_Menu:
		            	    Send_str("  SELECT MENU  ", 0);
				    	    Send_str("DISPLAY SETTING", 16);
			            	Current_Button.Next_Flag = 0;
			            	break;		            	
		            			            				            	
			            case Resolution:
			                dp =(uint8_t)Global_Counter;
                            Send_str(" SET RESOLUTION ", 0);				    	    
				    	    if(dp == 0)
				    	    Send_str("     0000      ", 16);
				    	    else if(dp == 1)
				    	    Send_str("     000.0     ", 16);
				    	    else if(dp == 2)
				    	    Send_str("     00.00     ", 16);
				    	    else if(dp == 3)
				    	    Send_str("     0.000     ", 16);
			            	Current_Button.Next_Flag = 0;
			            	break;	
			            				         
			            case Set_Gas: 	              
		            	    //Send_str("  SELECT GAS   ", 0);
		            	    Send_str(" SELECT ENTITY  ", 0);
		            	    Display_Name(Name_List.Temp_Name,17,Position);		            	   
		            	    Current_Button.Next_Flag = 0;
		            	    break;       	
			     			     
			            case Set_Unit: 
			                unit_count =(uint8_t)  Global_Counter;			                			               
		            	    Send_str(" SET ENGG. UNIT ", 0);
							Display_units(21);			    
			            	Current_Button.Next_Flag = 0;
			            	break;


			            case Set_sec:
			                 sec_lmp =(uint8_t)  Global_Counter;
			            	 Send_str(" WARM-UP SECONDS ", 0);
			            	 display((uint32_t)sec_lmp,22,  Position,2);
			            	 Send_str("SECS ", 25);
			    	         Current_Button.Next_Flag = 0;
			            	 break;	 
			            	 
			             case Set_minute:
			                 minute_lmp =(uint8_t)  Global_Counter;
			            	 Send_str(" WARM-UP MINUTES ", 0);
			            	 display((uint32_t)minute_lmp,22,  Position,2);
			            	 Send_str("MINS ", 25);
			    	         Current_Button.Next_Flag = 0;
			            	 break;
			            	 
			             case Set_hour:
			                 hour_lmp =(uint8_t)  Global_Counter;
			            	 Send_str(" WARM-UP HOURS   ", 0);
			            	 display((uint32_t)hour_lmp,22,  Position,2);
			            	 Send_str("HRS ", 25);
			    	         Current_Button.Next_Flag = 0;
			            	 break; 		            	     					
			            			            			            	    		            			            	
		            	case Save:		            	   
		            	    Send_str(" SAVE SETTINGS? ", 0); 
		            	    Send_str("      NO        ", 16);
		            	    Current_Button.Next_Flag = 0;
		            	    break;   
		            	    
		              		            	    
		            	case Alarm_Menu: 
			            	Send_str("  SELECT MENU  ", 0);
				    	    Send_str(" ALARM SETTING  ", 16);
			            	Current_Button.Next_Flag = 0;
			            	break;
		            	
		            	case Alarm:
		            	    if(Set_Point == 1)
		            	    {
		            	    	Use_AL = Logic.AL1;
			            	    Send_str("   USE ALARM1   ", 0);
		            	    }
			    	        else if(Set_Point == 2)
			    	        {
			    	        	Use_AL = Logic.AL2;
			    	            Send_str("   USE ALARM2   ", 0);
			    	        }
			    	        else if(Set_Point == 3)
			    	        {
			    	        	Use_AL = Logic.AL3;
			    	            Send_str("   USE ALARM3   ", 0);
			    	        }
			    	        else if(Set_Point == 4)
			    	        {
			    	        	Use_AL = Logic.AL4;			    	       
			    	            Send_str("   USE ALARM4   ", 0);
			    	        }
			    	        
				    	    Send_str((Use_AL)?"      YES      " : "      NO        ", 16);
			            	Current_Button.Next_Flag = 0;
			                break;
			                
			                
		                
		                case Set_point:
		                
		                    Number = inc_digit(Number,(9999*pow(10,dp)));
		                    	                
		                    if(Set_Point == 1)
							{
								Send_str("ALARM1 SET POINT", 0);
								Negative_value = Set_point1_Negative;
			            	    Set_point1_data = (float64_t)(Number /(pow(10,dp)));
							}
			    	        else if(Set_Point == 2)
							{
								Send_str("ALARM2 SET POINT", 0);
								Negative_value = Set_point2_Negative;
			    	            Set_point2_data = (float64_t)(Number /(pow(10,dp)));
							}
			    	        else if(Set_Point == 3)
							{
								Send_str("ALARM3 SET POINT", 0);
								Negative_value = Set_point3_Negative;
			    	            Set_point3_data = (float64_t)(Number /(pow(10,dp)));
							}
			    	        else if(Set_Point == 4)
							{
								Send_str("ALARM4 SET POINT", 0);
								Negative_value = Set_point4_Negative;
			    	            Set_point4_data = (float64_t)(Number /(pow(10,dp)));
							}
		                     
		                    display_with_dp_adv1((uint32_t)(Number),21,Position,4,dp);
					   	   
					   	    //display_with_dp_adv1((uint32_t)Number,10,Position,4);
					   	   // display_with_dp_adv1((uint32_t)(Set_point1_data * pow(10,dp)),21,Position,4,dp);					  				    	       
				    	    Current_Button.Next_Flag=0;
			                break;
		            	
		            	case Hysterisis:
		            	   
			            	 Number = inc_digit(Number,(9999*pow(10,dp)));
			            	
			            	 if(Set_Point == 1)
						    {
						    	Send_str("ALARM1 HYSTERSIS", 0);                                
                                Hysterisis1_data  = (float64_t)(Number /(pow(10,dp)));
						    }	
			    	        else if(Set_Point == 2)
			    	        {
			    	        	Send_str("ALARM2 HYSTERSIS", 0);			    	            
			    	            Hysterisis2_data  = (float64_t)(Number /(pow(10,dp)));
			    	        }
			    	        else if(Set_Point == 3)
			    	        {
			    	        	Send_str("ALARM3 HYSTERSIS", 0);	                            
	                            Hysterisis3_data  = (float64_t)(Number /(pow(10,dp)));
			    	        }
			    	        else if(Set_Point == 4)			
			    	        {
			    	        	Send_str("ALARM4 HYSTERSIS", 0);    	        	                            
	                            Hysterisis4_data  = (float64_t)(Number /(pow(10,dp)));
			    	        }
			            	
					
			            	display_with_dp_adv((uint32_t)Number,21,Position,4);
			            		    	    					   	   
			            	Current_Button.Next_Flag = 0;
			                break;
			                
		                case Set_Logic:
		                     if(Set_Point == 1)
		                    {
		                    	AL_High_Logic  = Logic.AL1_HI_Logic;
			            	    Send_str("  ALARM1 LOGIC   ", 0);
		                    }
			    	        else if(Set_Point == 2)
			    	        {
			    	        	AL_High_Logic  = Logic.AL2_HI_Logic;
			    	            Send_str("  ALARM2 LOGIC   ", 0);
			    	        }
			    	        else if(Set_Point == 3)			    
			    	        {
			    	        	AL_High_Logic  = Logic.AL3_HI_Logic;	        
			    	            Send_str("  ALARM3 LOGIC   ", 0);
			    	        }	                        
			    	        else if(Set_Point == 4)			    
			    	        {
			    	        	AL_High_Logic  = Logic.AL4_HI_Logic;	       
			    	            Send_str("  ALARM4 LOGIC   ", 0);
			    	        }			    	        
			    	                     
			            	Send_str( (!AL_High_Logic)?"      LOW        ":"      HIGH       ", 16);
			            	 Current_Button.Next_Flag = 0;
			                 break;
		                
		                case Latch:
		                   if(Set_Point == 1)
		                    {
		                    	AL_Latch = Logic.AL1_Latch;
			            	    Send_str("ALARM1 LATCHING ", 0);
		                    }
			    	        else if(Set_Point == 2)
			    	        {
			    	        	AL_Latch = Logic.AL2_Latch;
			    	            Send_str("ALARM2 LATCHING ", 0);
			    	        }
			    	        else if(Set_Point == 3)		
			    	        {
			    	        	AL_Latch = Logic.AL3_Latch;	    	        
			    	            Send_str("ALARM3 LATCHING ", 0);
			    	        }	                        
			    	        else if(Set_Point == 4)		
			    	        {
			    	        	AL_Latch = Logic.AL4_Latch;	    	       
			    	            Send_str("ALARM4 LATCHING ", 0);
			    	        }			            	
			            	Send_str((AL_Latch)?"      YES      ":"      NO       ", 16);
			            	Current_Button.Next_Flag = 0;
			                break;
		                
		                case Time_delay:
		                    if(Set_Point == 1)
			            	{
			            		Send_str("  ALARM1 DELAY   ", 0);
			    	            Time_delay1_data = Global_Counter;			                 
			            	}
			    	        else if(Set_Point == 2)
			    	        {
			    	        	Send_str("  ALARM2 DELAY   ", 0);
			    	            Time_delay2_data = Global_Counter;
			    	        }
			    	        else if(Set_Point == 3)			    	        
			    	        {
			    	        	Send_str("  ALARM3 DELAY   ", 0);	
			    	            Time_delay3_data = Global_Counter;
			    	        }                        
			    	        else if(Set_Point == 4)			    	       
			    	        {
			    	        	Send_str("  ALARM4 DELAY   ", 0);
			    	            Time_delay4_data = Global_Counter;
			    	        }			            	
			    	        Send_str("SEC", 25);
					        
					   	    display((uint32_t)Global_Counter,21,  Position,3);
			            	Current_Button.Next_Flag = 0;
			                break;
			            
			             case Buzzer:
			            	Send_str(" BUZZER SETTING ", 0);
			            	Send_str((Buzzer_ON)?"      ON        ":"      OFF     ", 16);


			            	Current_Button.Next_Flag = 0;
			            	break;
			                		                		                		                
		                
		                case Fail_Safe:
			            	Send_str("FAIL SAFE RELAY ", 0);
			            	Send_str((Logic.AL_Failsafe)?"  NORMALLY-ON   ":"  NORMALLY-OFF  ", 16);
			            	Current_Button.Next_Flag = 0;
			                break;			             		            	
		      
//		            	case Fail_Safe_Delay:
//		            	    Fail_Safe_Delay_data =(uint32_t) Global_Counter;
//		            	    Send_str("FAIL SAFE DELAY ", 0);
//			            	Send_str("SEC", 25);
//			            	display((uint32_t)Fail_Safe_Delay_data,21,  Position,3);
//		            	    Current_Button.Next_Flag = 0;
//			                break;
		            			           
		            	
		            	case Output_Menu:
			            	Send_str("  SELECT MENU   ", 0);
				    	    Send_str(" OUTPUT SETTING ", 16);
			            	Current_Button.Next_Flag=0;
			            	break;
		            	
		            	case Output_Low:
		            	    Send_str(" SET OUTPUT LOW ", 0);
			            	Number = inc_digit(Number,(9999*pow(10,dp)));
			            	Negative_value = Output_Low_Negative;
			            	Output_Low_data = (float64_t)(Number /(pow(10,dp)));
			            					 
					   	    display_with_dp_adv1((uint32_t)Number,21, Position,4,dp);					            				            			   	    
			                Current_Button.Next_Flag = 0;
			            	break;
		            	
		            	
		            	case Output_High:
		            	    Send_str("SET OUTPUT HIGH ", 0);
                            Negative_value = Output_High_Negative;	                        
	                        Number = inc_digit(Number,(9999*pow(10,dp)));
	                        Output_High_data = (float64_t)(Number /(pow(10,dp)));
	                       	                        	                                              
	                        display_with_dp_adv1((uint32_t)Number,21, Position,4,dp);					   	    
					   	    Current_Button.Next_Flag=0;
			            	break;
		            	
		            	case Select_Output_Type:
		            	    Output_Type =(uint8_t) Global_Counter;
		            	    Send_str(" SELECT OUTPUT  ", 0);
			                if(Output_Type == 0)
			                Send_str("  0-20mA OUTPUT ", 16);
			                else if(Output_Type == 1)
			                Send_str("  4-20mA OUTPUT ", 16);
			                else if(Output_Type == 2)
			                Send_str("  0-5V OUTPUT   ", 16);
			                else if(Output_Type == 3)
			                Send_str("  0-10V OUTPUT  ", 16);
			                					            
			            	Current_Button.Next_Flag=0;
			            	break;
			            	
			            case Select_scale:
			                Send_str("  SELECT SCALE  ", 0);
			                Send_str((Scale_Type)?"    UP-SCALE   ":"   DOWN-SCALE  ", 16);					            
			            	Current_Button.Next_Flag = 0;
			            	break;	
		            			            			            			            	

		            	case Set_3_8mA:
		            	   
		            	    if(Output_Type == 0) //0-20mA
				            {
				            	Send_str(" SET 0mA O/P  ", 0);
				            	//current_output = 0;
				            	correction_factor_3_8mA = 300;
				            }
				            else if(Output_Type == 1)//4-20mA
				            {
				            	Send_str(" SET 3.8mA O/P  ", 0);
				            	current_output = 3.8;
				            }
				            else if(Output_Type == 2)//0-5V
				            {
				            	Send_str(" SET 0V O/P  ", 0);
				            	//current_output = 0;
				            	correction_factor_3_8mA = 300;
				            }
				            else if(Output_Type == 3)//0-10V
				            {
				            	Send_str(" SET 0V O/P  ", 0);
				            	//current_output = 0;
				            	correction_factor_3_8mA = 300;
				            }
				            correction_factor_3_8mA =(uint16_t) Global_Counter;
				    	    display((uint32_t)correction_factor_3_8mA,22,  Position,3);
				    	    Current_Button.Next_Flag = 0;
				            break;   
		            	
		            	case Set_4mA:
			            	if(Output_Type == 0) //0-20mA
				            {
				            	Send_str(" SET 4.0mA O/P  ", 0);
				            	current_output = 4.0;
				            }
				            else if(Output_Type == 1)//4-20mA
				            {
				            	Send_str(" SET 4.0mA O/P  ", 0);
				            	current_output = 4.0;
				            }
				            else if(Output_Type == 2)//0-5V
				            {
				            	Send_str(" SET 1.0V O/P  ", 0);
				            	current_output = 1.0;
				            }
				            else if(Output_Type == 3)//0-10V
				            {
				            	Send_str(" SET 2.0V O/P  ", 0);
				            	current_output = 2.0;
				            }
				            correction_factor_4mA =(uint16_t) Global_Counter;
				    	    display((uint32_t)correction_factor_4mA,22,  Position,3);
			            	Current_Button.Next_Flag=0;
			            	break;
		            	
		            	case Set_8mA:
			            	if(Output_Type == 0) //0-20mA
				            {
				            	Send_str(" SET 8.0mA O/P  ", 0);
				            	current_output = 8.0;
				            }
				            else if(Output_Type == 1)//4-20mA
				            {
				            	Send_str(" SET 8.0mA O/P  ", 0);
				            	current_output = 8.0;
				            }
				            else if(Output_Type == 2)//0-5V
				            {
				            	Send_str(" SET 2.0V O/P  ", 0);
				            	current_output = 2.0;
				            }
				            else if(Output_Type == 3)//0-10V
				            {
				            	Send_str(" SET 4.0V O/P  ", 0);
				            	current_output = 4.0;
				            }
				            correction_factor_8mA =(uint16_t) Global_Counter;
				    	    display((uint32_t)correction_factor_8mA,22,  Position,3);
			            	Current_Button.Next_Flag=0;
			            	break;
		            	
		            	
		            	case Set_12mA:
			            	if(Output_Type == 0) //0-20mA
				            {
				            	Send_str(" SET 12.0mA O/P  ", 0);
				            	current_output = 12.0;
				            }
				            else if(Output_Type == 1)//4-20mA
				            {
				            	Send_str(" SET 12.0mA O/P  ", 0);
				            	current_output = 12.0;
				            }
				            else if(Output_Type == 2)//0-5V
				            {
				            	Send_str(" SET 3.0V O/P  ", 0);
				            	current_output = 3.0;
				            }
				            else if(Output_Type == 3)//0-10V
				            {
				            	Send_str(" SET 6.0V O/P  ", 0);
				            	current_output = 6.0;
				            }
				            correction_factor_12mA =(uint16_t) Global_Counter;
				    	    display((uint32_t)correction_factor_12mA ,22,  Position,3);
			            	Current_Button.Next_Flag=0;
			            	break;
		            	
		            	case Set_16mA:
			            	if(Output_Type == 0) //0-20mA
				            {
				            	Send_str(" SET 16.0mA O/P  ", 0);
				            	current_output = 16.0;
				            }
				            else if(Output_Type == 1)//4-20mA
				            {
				            	Send_str(" SET 16.0mA O/P  ", 0);
				            	current_output = 16.0;
				            }
				            else if(Output_Type == 2)//0-5V
				            {
				            	Send_str(" SET 4.0V O/P  ", 0);
				            	current_output = 4.0;
				            }
				            else if(Output_Type == 3)//0-10V
				            {
				            	Send_str(" SET 8.0V O/P  ", 0);
				            	current_output = 8.0;
				            }
				            correction_factor_16mA =(uint16_t) Global_Counter;
				    	    display((uint32_t)correction_factor_16mA,22,  Position,3);
			            	Current_Button.Next_Flag=0;
			            	break;
		            	
		            	
		            	case Set_20mA:
			            	if(Output_Type == 0) //0-20mA
				            {
				            	Send_str(" SET 20.0mA O/P  ", 0);
				            	current_output = 20.0;
				            }
				            else if(Output_Type == 1)//4-20mA
				            {
				            	Send_str(" SET 20.0mA O/P  ", 0);
				            	current_output = 20.0;
				            }
				            else if(Output_Type == 2)//0-5V
				            {
				            	Send_str(" SET 5.0V O/P  ", 0);
				            	current_output = 5.0;
				            }
				            else if(Output_Type == 3)//0-10V
				            {
				            	Send_str(" SET 10.0V O/P  ", 0);
				            	current_output = 10.0;
				            }
				            correction_factor_20mA =(uint16_t) Global_Counter;
				    	    display((uint32_t)correction_factor_20mA,22,  Position,3);
			            	Current_Button.Next_Flag=0;
			            	break;
		            	
		            	
		            	case Set_21mA:
			            	if(Output_Type == 0) //0-20mA
				            {
				            	Send_str(" SET 21.0mA O/P  ", 0);
				            	current_output = 21.0;
				            }
				            else if(Output_Type == 1)//4-20mA
				            {
				            	Send_str(" SET 21.0mA O/P  ", 0);
				            	current_output = 21.0;
				            }
				            else if(Output_Type == 2)//0-5V
				            {
				            	Send_str(" SET 6.0V O/P  ", 0);
				            	current_output = 6.0;
				            }
				            else if(Output_Type== 3)//0-10V
				            {
				            	Send_str(" SET 11.0V O/P  ", 0);
				            	current_output = 11.0;
				            }
				            correction_factor_21mA =(uint16_t) Global_Counter;
				    	    display((uint32_t)correction_factor_21mA,22,  Position,3);
			            	Current_Button.Next_Flag=0;
			            	break;
		            			            				            			             	
		              	case Passward_Menu:
			            	Send_str("  SELECT MENU  ", 0);
				    	    Send_str("PASSWORD SETTING", 16);
			            	Current_Button.Next_Flag=0;
			            	break;
			            	
			            case Old_Password:
				    	    Send_str("  OLD PASSWORD  ", 0);
				   	   		display((uint32_t)passward, 21, 0, 4); 				    	    
		                    Current_Button.Next_Flag=0;
			            	break;	
			            	
		            	
		            	case Set_New:
		                    Send_str("SET NEW PASSWORD", 0);
		                    Number = inc_digit1(Number,1000);
			    	        new_passward = Number;
			    	        display((uint32_t)new_passward,21,  Position,4);
			    	        
			            	Current_Button.Next_Flag=0;
			            	break;
		            	
		            	case Sure:
		            	    Send_str(" ARE YOU SURE? ", 0);
			            	
				    	    Send_str("      NO        ", 16);
			            	Current_Button.Next_Flag=0;
			            	break;
			            	
			            	case Backlit_Menu:
			            	Send_str("  SELECT MENU  ", 0);
				    	    Send_str("BACKLIT SETTING ", 16);
			            	Current_Button.Next_Flag=0;
			            	break;
		            	
		            	case Set_Backlit:
			            	Send_str(" SELECT BACKLIT ", 0);
			            
			            	if(Backlit_Count == 1)
			                {
			            	  Logic.backlit = 1;
			            	  Send_str("  CONTINOUS ON  ",16);
			                }
			            	else if(Backlit_Count == 2)
			            	{
			            		Logic.backlit = 0;
			            		Send_str("  CONTINOUS OFF  ",16);
			            	}
			            	else if(Backlit_Count == 3)
			            	{
			            		Logic.backlit = 1;
			            		Send_str("AUTOMATIC ON/OFF",16);
			            	}	   				    	   
			            	Current_Button.Next_Flag = 0;
			            	break;
			            	
			            
			            case  Fault_Flash:
				            Send_str(" FAULT FLASHING ", 0);
				            
				            if(Fault_Flash_ON)
				            Send_str("      ON       ", 16);
				            else
				            Send_str("      OFF      ", 16);
				            
			            	Current_Button.Next_Flag=0;
			            	break;	
			            	
		            
		            	case Serial_Menu:
			            	Send_str("  SELECT MENU   ", 0);
				    	    Send_str(" RS-485 MODBUS  ", 16);
			            	Current_Button.Next_Flag=0;
			            	break;
			            	
			            case Channel_Enable:
			            	Send_str("  SET CHANNEL  ", 0);
			            	Send_str(Channel_Enable_data?"    ENABLE    ":"    DISABLE   ", 16);
			            	Current_Button.Next_Flag = 0;
			            	break;	
			            	
			            case Slave_ID:
			            	Send_str(" SET MASTER ID ", 0);
			            	
			            	display((uint32_t)Slave_ID_data,22,  Position,3);
			            	
			            	Current_Button.Next_Flag=0;
			            	break;
			            	
			            case Read_Register:
			            	Send_str("SET READ REGISTR",0);
			            	Send_str(Read_Register_data?"HOLDING REGISTER":" INPUT REGISTER", 16);
			            	Current_Button.Next_Flag=0;
			            	break;
			           
			           case PV_Address:
			                Number = inc_digit1(Number,9999);
			    	        PV_Address_data = Number;			           
			            	Send_str("SET PV REGISTER  ", 0);
			            	display((uint32_t)PV_Address_data,22,  Position,4);			            	
			            	Current_Button.Next_Flag = 0;
			            	break; 				
			            				            			            
		            	case Device_ID:
		            	    Send_str(" SET DEVICE ID  ", 0);
			    	        display((uint32_t)Device_ID_data,22,  Position,3);
			            	Current_Button.Next_Flag=0;
			            	break;
		            	
		            	case Baudrate:
			            	Send_str("BAUDRATE IN BPS ", 0);
				            
				    	    Baudrate_Count =(uint8_t) Global_Counter;
				    	    if(Baudrate_Count == 0)
				    	    Send_str("     9600       ", 16);				    	    
				    	    else if(Baudrate_Count == 1)
				    	    Send_str("     19200       ", 16);				    	    
				    	    else if(Baudrate_Count == 2)
				    	    Send_str("     38400      ", 16);

				    	    Current_Button.Next_Flag=0;
			            	break;
		            	
		            	case Parity:
			            	Send_str("   SET PARITY   ", 0);
			            	Parity_Count =(uint8_t) Global_Counter;			            	
			            	if(Parity_Count == 0)
				    	    Send_str("      NONE      ", 16);				    	    
				    	    else if(Parity_Count == 1)
				    	    Send_str("      EVEN      ", 16);				    	    
				    	    else if(Parity_Count == 2)
				    	    Send_str("      ODD       ", 16);
			         
			            	Current_Button.Next_Flag=0;
			            	break;
			            	
		            	case Stop_Bits:
			            	Send_str(" SET STOPBITS ", 0);
			            	if(Stop_bit_Count == 1)
				    	    Send_str("      ONE       ", 16);				    	   
				    	    else if(Stop_bit_Count == 2)
				    	    Send_str("      TWO       ", 16);
			            	Current_Button.Next_Flag=0;
			            	break;			            			            	
		            	    		            				         
		            	case Test_Menu:
			            	Send_str("  SELECT MENU   ", 0);
				    	    Send_str("   TEST MODE    ", 16);
			            	Current_Button.Next_Flag=0;
			            	break;
		            	
		            	case Test:			            	
				    	    Number = inc_digit(Number,(9999*pow(10,dp)));
					   	    Negative_value = Test_data_Negative; 
					   	    Test_data  = (float64_t)(Number /pow(10,dp));
					   	    				   	    
	                        display_with_dp_adv1((uint32_t)Number,3, Position,4,dp);									   	   				    	    			    	   
                            Display_units(9);
                            
				    	    Send_str("  IN TEST MODE  ", 16);
				    	    
			            	Current_Button.Next_Flag = 0;
			            	break;
			            	
		            	case Exit:
		            	    Send_str("   EXIT MENU    ", 0);		            	  
		            	    Send_str("      NO        ", 16);
		            	
		            	    Current_Button.Next_Flag=0;
		                    break;
		      
		            }
		            break;
		        
		  case Shift:
		        switch(Shift_Parameter)
		            {
			          case YES:
				          if((Next_Parameter == Exit))
		            	  Send_str("   EXIT MENU   ", 0);
		            	 		            	  		            	  
		            	  else if(Next_Parameter == Sure)		            
		            	  Send_str(" ARE YOU SURE? ", 0);
		            	  
		            	  else if(Next_Parameter == Save)
		            	   Send_str(" SAVE SETTINGS? ", 0);
		            	
		            	  
					      Send_str("      YES      ", 16);
				          Current_Button.Shift_Flag=0;
				      break;  
			         
				   }
		         break;
		       
		        
		  case Incr:
		       switch(Incr_Parameter)
	            {
	            	case Passward: 
		            	Send_str(" ENTER PASSWORD", 0);
			    	    
			    	    Number = inc_digit(Number,(9999*pow(10,dp)));
			    	    passward_1 = Number;
			    	    display((uint32_t)passward_1,21,  Position,4);
			    	    Current_Button.Incr_Flag = 0;
	            	break;
	            	
	            	case NO:
		            	  if(Next_Parameter == Exit)
		            	  Send_str("   EXIT MENU   ", 0);
		            	 		            		            	  		            	  
		            	  else if(Next_Parameter == Sure)		            
		            	  Send_str(" ARE YOU SURE? ", 0);
		            	         		            	  		            	  
		            	  else if(Next_Parameter == Save)
		            	   Send_str(" SAVE SETTINGS? ", 0); 
		            			       		    
				          Send_str("      NO        ", 16);
			            Current_Button.Incr_Flag = 0;
			            break;		       
	            }
	            break;

	         }
	    }
	}
	
}











/*---------------------------------------------------------------------------
* Function name       : void display(int value, unsigned char pos, unsigned char flash)
*     returns         : -
*     arg1            : float value1, number which has to be displayed
*     arg2            : unsigned char pos, starting position to display
*     arg3            : unsigned char flash, position of cursor
* Created by          : Ch. Shravan Kumar
* Date created        : 02/10/10
* Description         : This function diaplays a number on LCD
*---------------------------------------------------------------------------*/

void display(uint32_t value, uint8_t pos, uint8_t flash,uint8_t number_of_digits)
{
      uint8_t digit;
	    
	    if(number_of_digits == 6)
   		{
	         digit=((value/100000));           			//calculating thousands place digit
	         
	         if((flash == 6))
		      {
		      	 if(GF.Toggle)
		         str[pos++] = '_';
		         else
		         str[pos++] = digit+0x30;
		      }
		      else
		      str[pos++] = digit+0x30;
	         	
	         number_of_digits--;
   		}
   		if(number_of_digits == 5)
   		{
	         digit=((value%100000)/10000);            			//calculating thousands place digit
	      
	    	 if((flash == 5))
		      {
		    	if(GF.Toggle)
		        str[pos++] = '_';
		        else
		        str[pos++] = digit+0x30;
		      }
		     else  
		     str[pos++] = digit+0x30;
		      
	        number_of_digits--;
   		}
         if(number_of_digits == 4)
         { 
	         digit=((value%100000)%10000)/1000;         			//calculating hundred place digit
	         
	         if((flash == 4))
		     {
		         if(GF.Toggle)
		         str[pos++] = '_';
		         else
		         str[pos++] = digit+0x30;
		     }
		     else
		      str[pos++] = digit+0x30;
		      
		      number_of_digits--;
         }
         
         
         if(number_of_digits == 3)
         { 
	         digit=(((value%100000)%10000)%1000)/100;    			//calculating tens place digit
	       
	         if((flash == 3))
		     {
		         if(GF.Toggle)
		         str[pos++] = '_';
		         else
		         str[pos++] = digit+0x30;
		     }
		     else
		      str[pos++] = digit+0x30;
	     
	          number_of_digits--;
         }
         
        
        if(number_of_digits == 2)
         { 
	         digit=((((value%100000)%10000)%1000)%100)/10;    			//calculating ones place digit
	        
	        if((flash == 2))
		     {
		         if(GF.Toggle)
		         str[pos++] = '_';
		         else
		         str[pos++] = digit+0x30;
		     }
		     else
		     str[pos++] = digit+0x30;
		     
		     number_of_digits--;
         }
         
        
         if(number_of_digits == 1)
         { 
	         digit=((((value%100000)%10000)%1000)%100)%10;    			//calculating ones place digit
	       
	         if(flash == 1)
		     {
		         if(GF.Toggle)
		         str[pos++] = '_';
		         else
		         str[pos++] = digit+0x30;
		     }
		     else 
		     str[pos++] = digit+0x30;
	       
	         number_of_digits--;
         }
}

/*-------------------------------------------------------------------------------
* Function name       : void display_with_dp(unsigned char pos, float value1, unsigned char dp, unsigned char flash)
*     returns         : -
*     arg1            : unsigned char pos, starting position to display
*     arg2            : float value1, number which has to be displayed
*     arg3            : unsigned char dp, number of digits after decimal point
*     arg4            : unsigned char flash, position of cursor
* Created by          : Ch. Shravan Kumar
* Date created        : 02/10/10
* Description         : This function diaplays the float number on LCD
*---------------------------------------------------------------------------*/

void display_with_dp(uint8_t pos, float64_t value1, uint8_t dp, uint8_t flash)
{
	uint16_t digit;
	uint32_t value;
	
	value = (uint32_t)(value1 * 100);
	   
   digit=((value/10000));           					//calculating ten-thousands place digit
   if((flash == 5) &&(GF.Blink_Flag))
        str[pos++] = '_';
   else
   		str[pos++]=digit+0x30;
   
   digit=(value%10000)/1000;         					//calculating thousands place digit
   if((flash == 4)&&(GF.Blink_Flag))
        str[pos++] = '_';
   else
   		str[pos++]=digit+0x30;
   
   digit=((value%10000)%1000)/100;    					//calculating hundred place digit
   if((flash == 3)&&(GF.Blink_Flag))
        str[pos++] = '_';
   else
   		str[pos++]=digit+0x30;
   
   if( dp != NO_DP && dp <= TWO_DP)
   {
     str[pos++]= '.';    
     
       if(dp == TWO_DP || dp == ONE_DP)
       {
	     digit=(((value%10000)%1000)%100)/10;    		//calculating hundred place digit
	     if((flash == 2)&&(GF.Blink_Flag) )
        	str[pos++] = '_';
   		 else
   		 	str[pos++]=digit+0x30;
     
     	 if(dp == TWO_DP)
   		 {
	        digit=(((value%10000)%1000)%100)%10;    	//calculating tens place digit
	        if((flash == 1)&&(GF.Blink_Flag))
        		str[pos++] = '_';
   			else
   				str[pos++]=digit+0x30;
         }
       }
     }
   
}



void display_with_dp_adv(uint32_t value,uint8_t pos, uint8_t flash,uint8_t number_of_digits)
{
	    uint8_t digit;
	    
	    if(number_of_digits == 6)
   		{
	         digit=((value/100000));           			//calculating thousands place digit
	         
	         if((flash == 6))
		      {
		      	 if(GF.Toggle)
		         str[pos++] = '_';
		         else
		         str[pos++] = digit+0x30;
		      }
		      else
		      str[pos++] = digit+0x30;
	         	
	         number_of_digits--;
   		}
   		if(number_of_digits == 5)
   		{
	         digit=((value%100000)/10000);            			//calculating thousands place digit
	      
	    	 if((flash == 5))
		      {
		    	if(GF.Toggle)
		        str[pos++] = '_';
		        else
		        str[pos++] = digit+0x30;
		      }
		     else  
		     str[pos++] = digit+0x30;
		      
	        number_of_digits--;
   		}
         if(number_of_digits == 4)
         { 
	         digit=((value%100000)%10000)/1000;         			//calculating hundred place digit
	         
	         if((flash == 4))
		     {
		         if(GF.Toggle)
		         str[pos++] = '_';
		         else
		         str[pos++] = digit+0x30;
		     }
		     else
		      str[pos++] = digit+0x30;
		      
		      number_of_digits--;
         }
         
         
         if(dp == 3)
         str[pos++] = '.';
         
         if(number_of_digits == 3)
         { 
	         digit=(((value%100000)%10000)%1000)/100;    			//calculating tens place digit
	       
	         if((flash == 3))
		     {
		         if(GF.Toggle)
		         str[pos++] = '_';
		         else
		         str[pos++] = digit+0x30;
		     }
		     else
		      str[pos++] = digit+0x30;
	     
	          number_of_digits--;
         }
         
         if(dp == 2)
         str[pos++] = '.';
         
         if(number_of_digits == 2)
         { 
	         digit=((((value%100000)%10000)%1000)%100)/10;    			//calculating ones place digit
	        
	        if((flash == 2))
		     {
		         if(GF.Toggle)
		         str[pos++] = '_';
		         else
		         str[pos++] = digit+0x30;
		     }
		     else
		     str[pos++] = digit+0x30;
		     
		     number_of_digits--;
         }
         
         if(dp == 1)
         str[pos++] = '.';
         
         if(number_of_digits == 1)
         { 
	         digit=((((value%100000)%10000)%1000)%100)%10;    			//calculating ones place digit
	       
	         if(flash == 1)
		     {
		         if(GF.Toggle)
		         str[pos++] = '_';
		         else
		         str[pos++] = digit+0x30;
		     }
		     else 
		     str[pos++] = digit+0x30;
	       
	         number_of_digits--;
         }
}


void display_with_dp_adv1(uint32_t value , uint8_t pos , uint8_t flash , uint8_t number_of_digits,uint8_t dp)
{
	    uint8_t digit;
	    
	    number_of_digits1 = number_of_digits;
	    flash1 = flash;
	    
	    
     	if(flash == (number_of_digits+1))
	      {
	      	set_polarity = 1;
	      	if(GF.Toggle)
	      	{
	      	   if(Negative_value)
	           str[pos-1] = '-';
	           else 
	           str[pos-1] = '+';
	        }
	      }
	     else
	      {
	     	 set_polarity = 0;
	         if(Negative_value)
             str[pos-1] = '-';
             else 
             str[pos-1] = ' ';
	      }
	     
	  	  	 
         if(number_of_digits == 4)
         { 
	         digit=(value%10000)/1000;         			//calculating hundred place digit
	         
	         if(flash == 4)
		     {
		         if(GF.Toggle)
		         str[pos++] = '_';
		         else
		         str[pos++] = digit+0x30;
		     }
		     else
		      str[pos++] = digit+0x30;
		      
		      number_of_digits--;
         }
         
         
         if(dp == 3)
         str[pos++] = '.';
         
         if(number_of_digits == 3)
         { 
	         digit=((value%10000)%1000)/100;    			//calculating tens place digit
	       
	         if(flash == 3)
		     {
		         if(GF.Toggle)
		         str[pos++] = '_';
		         else
		         str[pos++] = digit+0x30;
		     }
		     else
		      str[pos++] = digit+0x30;
	     
	          number_of_digits--;
         }
         
         if(dp == 2)
         str[pos++] = '.';
         
         if(number_of_digits == 2)
         { 
	         digit=(((value%10000)%1000)%100)/10;    			//calculating ones place digit
	        
	        if(flash == 2)
		     {
		         if(GF.Toggle)
		         str[pos++] = '_';
		         else
		         str[pos++] = digit+0x30;
		     }
		     else
		     str[pos++] = digit+0x30;
		     
		     number_of_digits--;
         }
         
         if(dp == 1)
         str[pos++] = '.';
         
         if(number_of_digits == 1)
         { 
	         digit=(((value%10000)%1000)%100)%10;    			//calculating ones place digit
	       
	         if(flash == 1)
		     {
		         if(GF.Toggle)
		         str[pos++] = '_';
		         else
		         str[pos++] = digit+0x30;
		     }
		     else 
		     str[pos++] = digit+0x30;
	       
	         number_of_digits--;
         }
}



void Display_Name(int8_t *lcd_temp, uint8_t i,uint8_t pos)
{
	uint8_t temp = i;
	
	while(*lcd_temp != 0)
	{
		if((i-temp+1) == pos)
		{
			if(GF.Toggle)
			{
	        	 str[i++] = '_';
	        	 *lcd_temp++;
			}
	        else
	        	str[i++] = *lcd_temp++;                           /* storing the string to be diplayed on buffer string */
		}
		else
			str[i++] = *lcd_temp++;                           /* storing the string to be diplayed on buffer string */
	}
}


/*-------------------------------------------------------------------------------------
* Function name       : unsigned int inc_digit_with_dp(unsigned int , unsigned char , unsigned int)
*     returns         : An unsigned integer 
*     arg1            : unsigned int num, Number to be incremented
*     arg2            : unsigned char pos, position of the cursor
*     arg3            : unsigned int lim, highest limit upto which number to be
*                       incremented.
* Created by          : Ch. Shravan Kumar
* Date created        : 02/10/10
* Description         : This function increments the passed integer value based on 
*                       passed cursor position and returns it to called function
*--------------------------------------------------------------------------------------*/
uint32_t inc_digit(uint32_t num,uint32_t lim)
{
	if (num > 999999)
    	num = 0;  
  
	return num;  
}  


uint32_t inc_digit1(uint32_t num,uint32_t lim)
{
	if (num > lim)
    	num = 0;  
  
	return num;  
}  

/*-------------------------------------------------------------------------------------
* Function name       : void break_digits (unsigned int value)
*     returns         : -
*     arg1            : unsigned int value, value to be divided
* Created by          : Ch. Shravan Kumar
* Date created        : 02/10/10
* Description         : This function breaks the passed number into characters and 
*                       updates it to a string.
*--------------------------------------------------------------------------------------*/
void break_digits (uint32_t value)
{
	     int digit;
		 digit=value/100000;               //calculating thousands place digit
         bcd[5]=digit; 
         digit=(value%100000)/10000;               //calculating thousands place digit
         bcd[4]=digit;
         digit=((value%100000)%10000)/1000;         //calculating hundreds place digit
         bcd[3]=digit;
         digit=(((value%100000)%10000)%1000)/100;    //calculating tens place digit
         bcd[2]=digit;
         digit=((((value%100000)%10000)%1000)%100)/10;    //calculating ones place digit
         bcd[1]=digit;
         digit=((((value%100000)%10000)%1000)%100)%10;    //calculating ones place digit
         bcd[0]=digit;
}    
/*-------------------------------------------------------------------------------------
* Function name       : unsigned int make_digits(void)
*     returns         : unsigned integer number
*     arg1            : -
* Created by          : Ch. Shravan Kumar
* Date created        : 02/10/10
* Description         : This function transforms the indvidual characters of the string to
*                       a number and returns it to called function.
*--------------------------------------------------------------------------------------*/
uint32_t make_digits(void)
{
	uint32_t num1;
  
  	num1 = (uint32_t)bcd[0];                     /* Unit digit */
  	num1 += 10 * (uint32_t)bcd[1];               /* Add 10's digitmultipled by 10 with unit digit */ 
  	num1 += 100 * (uint32_t)bcd[2];              /* Add 100's digitmultipled by 100 with previous number */
  	num1 += 1000 * (uint32_t)bcd[3];             /* Add 1000's digitmultipled by 1000 with unit previous number */
 	num1 += 10000 * (uint32_t)bcd[4];            /* Add 10000's digitmultipled by 10000 with unit previous number */
 	num1 += 100000 * (uint32_t)bcd[5];           /* Add 10000's digitmultipled by 10000 with unit previous number */
 
  	return num1;                            /* Return the number */ 
} 

void Display_units(unsigned char pos)
{
/* Displays gas specified by units starting from pos */
	switch (unit_count)
  	{
    	case 0:
      			Send_str("%V/V",pos);
    	break;  
    
    	case 1:
      			Send_str("%LEL",pos);
    	break;      
    
    	case 2:
    			Send_str("PPM", pos);
      	break;
        
        case 3:
      			Send_str("PPB", pos);
      	break;
      	
      	case 4:
      			Send_str("mgm3", pos);
      	break;
      	
		case 5:
      			str[pos] = 0xDF;
      			Send_str("C", pos+1);
      	break;
      	
  		case 6:
      			str[pos] = 0xDF;
      			Send_str("F", pos+1);
      	break;
      	
      	case 7:
      			Send_str("Pa", pos);
      	break;
      	
      	case 8:
      			Send_str("kPa", pos);
      	break;
      	
      	case 9:
      			Send_str("hPa", pos);
      	break;
      	
      	case 10:
      			Send_str("atm", pos);
      	break;
      	
      	case 11:
      			Send_str("bar", pos);
      	break;
      	
      	case 12:
      			Send_str("mmHg", pos);
      	break;
      	
      	case 13:
      			Send_str("mmWC", pos);
      	break;
      	
      	case 14:
      			Send_str("Torr", pos);
      	break;
      	
      	case 15:
      			Send_str("dyne", pos);
      	break;
      	
      	case 16:
      			Send_str("lbf", pos);
      	break;
      	
      	case 17:
      			Send_str("Newton", pos);
      	break;
      	
      	case 18:
      			Send_str("kN", pos);
      	break;
      	
      	case 19:
      			Send_str("MN", pos);
      	break;
      	
      	case 20:
      			Send_str("Calorie", pos);
      	break;
      	
      	case 21:
      			Send_str("kcal", pos);
      	break;
      	
      	case 22:
      			Send_str("Joule", pos);
      	break;
      	
      	case 23:
      			Send_str("kJ", pos);
      	break;
      	
      	case 24:
      			Send_str("MJ", pos);
      	break;
      	
      	case 25:
      			Send_str("Nm", pos);
      	break;
      	
      	case 26:
      			Send_str("Ergs", pos);
      	break;
      	
      	case 27:
      			Send_str("kWh", pos);
      	break;
      	
      	case 28:
      			Send_str("%rH", pos);
      	break;
  	}
      	        
}    
			             		  




			             	                    


