#include "system.h"


float32_t current_output;
float32_t voltage_output;

float64_t Test_data   = 0.0;
uint8_t	Test_data_Negative = 0;
 uint16_t  dac_counts = 0;
 uint16_t  N_HI = 0;
 float64_t dac_concentration    = 0.0;
 volatile float64_t Output_low  = 0.0;
 volatile float64_t Output_high = 0.0;

void write_to_register(uint8_t address, uint16_t value)
{
	volatile uint8_t i = 0;
	
	CLOCK_SEL &= ~CLOCK_PIN;
	CLOCK_DIR |= CLOCK_PIN;
	CLOCK_OUT &= ~CLOCK_PIN;
	
	DATA_SEL &= ~DATA_PIN;
	DATA_DIR |= DATA_PIN;
	DATA_OUT &= ~DATA_PIN;
	
	
		LATCH1_SEL &= ~LATCH1_PIN;
		LATCH1_DIR |= LATCH1_PIN;
		LATCH1_OUT &= ~LATCH1_PIN;


//		LATCH2_SEL &= ~LATCH2_PIN;
//		LATCH2_DIR |= LATCH2_PIN;
//		LATCH2_OUT &= ~LATCH2_PIN;


	
	
	for(i=0; i<8; i++)
	{
		CLOCK_OUT &= ~CLOCK_PIN;		//P5OUT &= ~0x08;
		if(address &(0x80>>i))			/*if(temp & 0x80)*/
		{
			DATA_OUT |= DATA_PIN;		//P5OUT |= 0x02;	//			address_temp |= (0x01 << i);
		}	
		else
		{
			DATA_OUT &= ~DATA_PIN;		//P5OUT &= ~0x02;	//			address_temp &= ~(0x01 << i);	
		}
		
		CLOCK_OUT |= CLOCK_PIN;			//P5OUT |= 0x08;
	} 
	
	for(i=0; i<16; i++)
	{
		CLOCK_OUT &= ~CLOCK_PIN;		//P5OUT &= ~0x08;	//		temp = (0x80)&(value << i);
		if(value &(0x8000>>i))			/*if(temp & 0x80)*/
		{
			DATA_OUT |= DATA_PIN;		//P5OUT |= 0x02;	//			value_temp |= (0x01 << i);
		}	
		else
		{
			DATA_OUT &= ~DATA_PIN;		//P5OUT &= ~0x02;	//			value_temp &= ~(0x01 << i);	
		}
		CLOCK_OUT |= CLOCK_PIN;			//P5OUT |= 0x08;
	}

    
     LATCH1_OUT |= LATCH1_PIN;		//P3OUT |= 0x40;
	 for(i=3; i>0; i--);
	 LATCH1_OUT &= ~LATCH1_PIN;		//P3OUT &= ~0x40;
    
//	switch(latch)
//	{
//		case LATCH1:	
//			LATCH1_OUT |= LATCH1_PIN;		//P3OUT |= 0x40;
//			for(i=3; i>0; i--);
//			LATCH1_OUT &= ~LATCH1_PIN;		//P3OUT &= ~0x40;
//			break;
//		
//		case LATCH2:				
//		    LATCH2_DIR &= ~LATCH2_PIN;
//		    for(i=3; i>0; i--);
//		    LATCH2_OUT |= LATCH2_PIN;						
//			break;
//			
//	 }		

}

void DAC_Output()
{       
	     //WDTCTL = WDTPW + WDTHOLD;  
	    
	     Output_low  = (Output_Low_Negative  == 1)?(Output_Low_data * (-1)):Output_Low_data;
	     Output_high = (Output_High_Negative == 1)?(Output_High_data * (-1)):Output_High_data;

	     
	 
	     if( (Menu == 5) && (GF.Valid_passward) )   //OUTPUT MENU
	     {	    	
		   switch(Output_Type)
	       {
		    	case 0:
		    	case 1: dac_counts = (uint16_t)(2730.625 * current_output); 
				        break;
				case 2:
		        case 3: 
		                dac_counts = (uint16_t)(6550.0 * current_output);
				        //dac_counts = (uint16_t)(3900.0 * current_output);
		                break;
	       }
			
			if(Next_Parameter == Set_3_8mA)
			dac_counts -= (3000 - (10 * correction_factor_3_8mA));
		   
			else if(Next_Parameter == Set_4mA)
			dac_counts -=(3000 - (10 * correction_factor_4mA));
			
			else if(Next_Parameter == Set_8mA)
			dac_counts -= (3000 - (10 * correction_factor_8mA));
			
			else if(Next_Parameter == Set_12mA)
			dac_counts -= (3000 - (10 * correction_factor_12mA));
			
			else if(Next_Parameter == Set_16mA)
			dac_counts -= (3000 - (10 * correction_factor_16mA));
			
			else if(Next_Parameter == Set_20mA)
			dac_counts -= (3000 - (10 * correction_factor_20mA));
			
			else if(Next_Parameter == Set_21mA)
			dac_counts -= (3000 - (10 * correction_factor_21mA));				  
	     }				
	     
 	
 	    else if(!(logic_off) && (Fail_show))  //FAULT CONDITION
		 {
			    if(Scale_Type)
			    {
			    	switch(Output_Type)
					 {
				       case 0:
				       case 1: current_output = 21.0;
				   	           dac_counts = (uint16_t)(2730.625 * current_output);				   	  				   	           
				   	           break;
				   	           
				   	   case 2: current_output = 5.5;
				   	           dac_counts = (uint16_t)(6550.0 * current_output);
				   	           //dac_counts = (uint16_t)(3900.0 * current_output);				   	           				   	           
				   	           break;
				   	           
				   	   case 3: current_output = 10.5;
				   	           dac_counts = (uint16_t)(6550.0 * current_output);
				   	           //dac_counts = (uint16_t)(3900.0 * current_output);				   	           
				   	           break; 	
					  }
					  dac_counts -= (3000-(10*correction_factor_21mA));
			    }
			    else
			    {
				    switch(Output_Type)
				    {
				       case 0:
				       case 1:
				       case 2:
				       case 3:
				              current_output = 0;
				              dac_counts = 0;
				              break;				   	 
				    }
			    }		    		       	 
	     }
	   
	   
	   else if(( (NORMAL_WORKING_MODE) && (!Fail_show)) || ((Menu == 8)&&(GF.Valid_passward) && (Current_Test.Test_Flag)))
	    {
	    	if( (NORMAL_WORKING_MODE) && (!Fail_show))
		    dac_concentration = (Process_Negative==1)? (process_value * (-1)):process_value;
		    
		    else if((Menu == 8)&&(GF.Valid_passward))
		    dac_concentration = (Test_data_Negative==1) ? (Test_data * (-1)): Test_data;

		     		   
	        if(Channel_Enable_data == 0)
	        {
	        	switch(Output_Type)
			    {
	        	   case 0:
			       case 1:
			       case 2:		    	
				   case 3:
				          current_output = 0;  
		                  break; 	  				         
			    }
	        	
	        }	        
	        else if(dac_concentration < Output_low)
		    {
		       switch(Output_Type)
			   {
			   	   case 0:
			       case 2:
			       case 3:		    	
		                  current_output = 0;  
		                  break; 	  
				   case 1:
			              current_output = 4.0;
			              break;
			   }   	  			 	 
	        }
			else if(dac_concentration > Output_high)
		    {
		       switch(Output_Type)
		       {
		       	   case 0: 
                   case 1: current_output = 20.0;
		       	           break;
		       	   case 2: current_output = 5.0;
		       	           break;
		       	   case 3: current_output = 10.0;
		       	           break;                		       	           		       	
		       }		 	 
	        }
			else
			{
			   switch(Output_Type)
		       {
				   case 0: current_output = (20.0 * (dac_concentration - Output_low))/(Output_high - Output_low);
				           break;
				           
                   case 1: current_output = ((16.0 * dac_concentration) + ((4.0 * Output_high) - (20.0 * Output_low)))/(Output_high - Output_low);
		       	           break;
		       	           
		       	   case 2: current_output = (5.0 * (dac_concentration - Output_low))/(Output_high - Output_low);
		       	           break;
		       	           
		       	   case 3: current_output = (10.0 * (dac_concentration - Output_low))/(Output_high - Output_low);
		       	           break;
		       }  		       
			}
		    
		    
		    switch(Output_Type)
            {
            	case 0: //0-20mA
					dac_counts = (uint16_t)(2730.625 * current_output);
					                                                                           /* Set DAC voltages back to depending on Channel a active voltage*/
					if(current_output >= 0.0 && current_output < 3.0)
					dac_counts -= (3000 - (10 * correction_factor_3_8mA));      /* Set DAC voltages back to depending on Channel a active voltage*/
					else if(current_output >= 3.0 && current_output < 6.0)
					dac_counts -=(3000 - (10 * correction_factor_4mA));         /* Set DAC voltages back to depending on Channel a active voltage*/
					else if(current_output >= 6.0 && current_output < 10.0)
					dac_counts -=(3000 - (10 * correction_factor_8mA));         /* Set DAC voltages back to depending on Channel a active voltage*/
					else if(current_output >= 10.0 && current_output < 14.0)
					dac_counts -=(3000 - (10 * correction_factor_12mA));        /* Set DAC voltages back to depending on Channel a active voltage*/
					else if(current_output >= 14.0 && current_output < 18.0)
					dac_counts -=(3000 - (10 * correction_factor_16mA));        /* Set DAC voltages back to depending on Channel a active voltage*/
					else if(current_output >= 18.0 && current_output < 21.0)
					dac_counts -=(3000 - (10 * correction_factor_20mA));        /* Set DAC voltages back to depending on Channel a active voltage*/
					else if(current_output >= 21.0)
					dac_counts -=(3000 - (10 * correction_factor_21mA));       /* Set DAC voltages back to depending on Channel a active voltage*/
					break;

			case 1: //4-20mA

				dac_counts = (uint16_t)(2730.625 * current_output);
				if(current_output < 3.78)                       
				dac_counts = 0;
				else if(current_output >= 3.78 && current_output < 3.9)
				dac_counts -= (3000-(10 * correction_factor_3_8mA));       /* Set DAC voltages back to depending on Channel a active voltage*/
				else if(current_output >= 3.9 && current_output < 6.0)
				dac_counts -= (3000-(10 * correction_factor_4mA));         /* Set DAC voltages back to depending on Channel a active voltage*/
				else if(current_output >= 6.0 && current_output < 10.0)
				dac_counts -= (3000-(10 * correction_factor_8mA));         /* Set DAC voltages back to depending on Channel a active voltage*/
				else if(current_output >= 10.0 && current_output < 14.0)
				dac_counts -= (3000-(10 * correction_factor_12mA));        /* Set DAC voltages back to depending on Channel a active voltage*/
				else if(current_output >= 14.0 && current_output < 18.0)
				dac_counts -= (3000-(10 * correction_factor_16mA));        /* Set DAC voltages back to depending on Channel a active voltage*/
				else if(current_output >= 18.0 && current_output < 21.0)
				dac_counts -= (3000-(10 * correction_factor_20mA));        /* Set DAC voltages back to depending on Channel a active voltage*/
				else if(current_output >= 21.0)
				dac_counts -= (3000-(10 * correction_factor_21mA));        /* Set DAC voltages back to depending on Channel a active voltage*/
				break;

			case 2: //0-5V

				//dac_counts = (uint16_t)(3900.0 * current_output);
				dac_counts = (uint16_t)(6550.0 * current_output);
				if(current_output <= 0.25)
				dac_counts = 0;        /* Set DAC voltages back to depending on Channel a active voltage*/
				else if(current_output >= 0.25 && current_output < 0.75)
				dac_counts -= (3000-(10*correction_factor_3_8mA));       /* Set DAC voltages back to depending on Channel a active voltage*/
				else if(current_output >= 0.75 && current_output < 1.5)
				dac_counts -= (3000-(10*correction_factor_4mA));         /* Set DAC voltages back to depending on Channel a active voltage*/
				else if(current_output >= 1.5 && current_output < 2.5)
				dac_counts -= (3000-(10*correction_factor_8mA));         /* Set DAC voltages back to depending on Channel a active voltage*/
				else if(current_output >= 2.5 && current_output < 3.5)
				dac_counts -= (3000-(10*correction_factor_12mA));        /* Set DAC voltages back to depending on Channel a active voltage*/
				else if(current_output >= 3.5 && current_output < 4.5)
				dac_counts -= (3000-(10*correction_factor_16mA));        /* Set DAC voltages back to depending on Channel a active voltage*/
				else if(current_output >= 4.5 && current_output < 5.5)
				dac_counts -= (3000-(10*correction_factor_20mA));        /* Set DAC voltages back to depending on Channel a active voltage*/
				else if(current_output >= 5.5)
				dac_counts -= (3000-(10*correction_factor_21mA));        /* Set DAC voltages back to depending on Channel a active voltage*/
				break;

			case 3: //0-10V
				
				//dac_counts = (uint16_t)(3900.0 * current_output);
				dac_counts = (uint16_t)(6550.0 * current_output);
				if(current_output <= 0.5) 
				dac_counts = 0;                                          /* Set DAC voltages back to depending on Channel a active voltage*/
				else if(current_output >= 0.5 && current_output < 1.0)
				dac_counts -=  (3000-(10*correction_factor_3_8mA));       /* Set DAC voltages back to depending on Channel a active voltage*/
				else if(current_output >= 1.0 && current_output < 3.0)
				dac_counts -=  (3000-(10*correction_factor_4mA));         /* Set DAC voltages back to depending on Channel a active voltage*/
				else if(current_output >= 3.0 && current_output < 5.0)
				dac_counts -=  (3000-(10*correction_factor_8mA));         /* Set DAC voltages back to depending on Channel a active voltage*/
				else if(current_output >= 5.0 && current_output < 7.0)
				dac_counts -=  (3000-(10*correction_factor_12mA));        /* Set DAC voltages back to depending on Channel a active voltage*/
				else if(current_output >= 7.0 && current_output < 9.0)
				dac_counts -=  (3000-(10*correction_factor_16mA));        /* Set DAC voltages back to depending on Channel a active voltage*/
				else if(current_output >= 9.0 && current_output < 10.5)
				dac_counts -=  (3000-(10*correction_factor_20mA));        /* Set DAC voltages back to depending on Channel a active voltage*/
				else if(current_output >= 10.5)
				dac_counts -=  (3000-(10*correction_factor_21mA));        /* Set DAC voltages back to depending on Channel a active voltage*/
                break;
	      }
        
	    }
	    
	   else if((logic_off)||(Power_on))
       {  	    	
			current_output = 0;
			dac_counts     = 0;	
       }   
	   
	   if(System_Chk_Flag)   //SYSTEM CHECK
	    {
	    	switch(Output_Type)
			{
			   	   
			   	   case 0: current_output = 10.0;
			   	           dac_counts = (uint16_t)(2730.625 * current_output);
			   	           dac_counts -= (3000-(10 * correction_factor_12mA)); 
			   	           break;
			   	   case 1: current_output = 12.0;
			   	           dac_counts = (uint16_t)(2730.625 * current_output);
			   	           dac_counts -= (3000-(10 * correction_factor_12mA)); 
			   	           break;
			   	   case 2: current_output = 2.5;
			   	           dac_counts = (uint16_t)(6550.0 * current_output);
			   	           //dac_counts = (uint16_t)(3900.0 * current_output);
			   	           dac_counts -= (3000-(10*correction_factor_8mA));
			   	           break;
			   	   case 3: current_output = 5.0;
			   	           dac_counts = (uint16_t)(6550.0 * current_output);
			   	           //dac_counts = (uint16_t)(3900.0 * current_output);
			   	           dac_counts -=  (3000-(10*correction_factor_8mA));
			   	           break;                    			   	           
			 }  	
	     }
	   
	         
    
	write_to_register(DATA_REG,dac_counts);
}

