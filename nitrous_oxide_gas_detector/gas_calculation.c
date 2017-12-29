#include "system.h"


uint8_t open_error  = 0;
uint8_t under_error = 0;
uint8_t over_error  = 0;
uint8_t undefined_error = 0;
uint8_t comfail_error  = 0;

float64_t process_value  = 0.0;
uint8_t Process_Negative = 0;

float64_t Peak_Gas_Concentration = 0;
uint8_t Peak_Negative= 0;


float64_t Input4_20mA  = 0.0;
uint16_t  Input4_20    = 0.0;
float64_t process_range  = 9999.0;
uint8_t Start_Failsafe_Timer = 0;



void Handle_Gas_Calculation()
{	
	  	if(message == 10)
	    {
/**********************************FAULT CONDITIONS********************************************************************************/		    
		    if( (ComFail)&&(Channel_Enable_data) )
		    {
		       //if(Power_on1)
		        {
		        	Power_on1 = 0;
		        	Fail_show = 1;
		        }
//		    	if(!Fail_show)
//		        Start_Failsafe_Timer = 1;
		        comfail_error = 1;
		    	open_error  = 0;
		    	over_error  = 0;
		    	under_error = 0;
		    	undefined_error = 0;		    	
		    }
		    else if(data_received == 32767)    
		    {
		    	//if(Power_on1)
		        {
		        	Power_on1 = 0;
		        	Fail_show = 1;
		        }
//		    	if(!Fail_show)
//		        Start_Failsafe_Timer = 1;
		        comfail_error = 0;
		    	open_error  = 1;
		    	over_error  = 0;
		    	under_error = 0;
		    	undefined_error = 0;
		    }
		    else if(data_received == 32768)
		    {
//		    	if(Power_on1)
		        {
		        	Power_on1 = 0;
		        	Fail_show = 1;
		        }
//		    	if(!Fail_show)
//		    	Start_Failsafe_Timer = 1;
		    	
		    	comfail_error = 0;
		    	under_error = 1;
		    	over_error  = 0;
		    	open_error  = 0;
		    	undefined_error = 0;
		    }
		    else if(data_received == 32766)
		    {
//		     	if(Power_on1)
		        {
		        	Power_on1 = 0;
		        	Fail_show = 1;
		        }
//		    	if(!Fail_show)
//		    	Start_Failsafe_Timer = 1;
		    	
		    	comfail_error = 0;
		    	over_error  = 1;
		    	under_error = 0;
		    	open_error  = 0;
		    	undefined_error = 0;
		    }
		    else if(data_received == 32769) //UNDEFINED ERROR
		    {
//		    	if(Power_on1)
		        {
		        	Power_on1 = 0;
		        	Fail_show = 1;
		        }
//		    	if(!Fail_show)
//		    	Start_Failsafe_Timer = 1;
		    	
		    	comfail_error = 0;
		    	under_error = 0;
		    	over_error  = 0;
		    	open_error  = 0;
		    	undefined_error = 1;
		    }
		    else 
		    {
		    //	Start_Failsafe_Timer = 0;
		    	Power_on1 = 0;
		    	Fail_show = 0;
		    	
		    	comfail_error = 0;
		    	over_error  = 0;
		    	under_error = 0;
		    	open_error  = 0;
		    	undefined_error = 0;
		    }
   
		    		  		    			    
	    }	    	   
/*********************************FAULT CONDITIONS********************************************************************************/	    
	         
}
     






