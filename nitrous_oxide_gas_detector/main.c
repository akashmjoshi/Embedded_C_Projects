#include "system.h"


/*---------------------------------------------------------------------------
                      PRODUCT BY Akash M Joshi
*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
* PRODUCT NAME        : GM-3315
* CREATED BY          : Akash M Joshi
* DATE CREATED        : 15/08/13
*---------------------------------------------------------------------------*/

void Init_Module(void);
void Clock_Init(void);

void main(void)
{	
	//delay_ms(1000);
	uint16_t i;
    uint16_t eeprom_verification  = 0;
	WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
	Init_Module();
	
	//_EINT();

     
///////////////////////////Device Memory///////////////////////////////////////////	 
	  eeprom_verification = read_2byte_memory(EEPROM_VERIFICATION_ADD);	  
	  
	  if(eeprom_verification != 6611)
      send_factory_eeprom_values();
           
      dp = read_byte_memory(DP_ADD);
      dp_update = dp;

	  message  = read_byte_memory(MESSAGE_ADD);
	  
      get_initial_eeprom_values();     
/////////////////////////////Device Memory End/////////////////////////////////////////      
    for(i=0;i<50;i++)						/* Clears the array for RS-485 */
    MainDataArray[i] = 0;
   
    UARTInit();  
    UARTInit_1();
      

    switch(Output_Type)
    {
    	case 0:
    	case 1:
               write_to_register(CONTROL_REG, (OUTPUT_EN|CURRENT_0_24mA));
               break;
        case 2:
        case 3:       
               write_to_register(CONTROL_REG, (OUTPUT_EN|VOLTAGE_0_10V));
               break;
    }

   
    message = 6;  
    
    //Timer_A_init();
    
    Send_str("                    ", 0);
	Send_str("                    ", 16);
	
	while(1)
	{
	    
		    Start_up();
		    scan_ir_keys();			
			Key_Function();		
			        
	        //if(timeout_flag1 == 1)
            //DecodeMaster();	        
	        if((!timeout_flag) && (!timeout_flag1))	        
	        DAC_Output();
	        
	        if(System_Chk_Flag != 1)
	        logic();
	        
	   		if( ( (!(logic_off) && !(Fail_show)) || ((Menu == 8) && (GF.Valid_passward)) ) && !(Power_on) )
	   		logic1();
	        		
			if((!Power_on))
			Handle_Gas_Calculation();
		     	    
			if(( (NEXT_KEY) || (SHIFT_KEY) || (INCR_KEY) || (ACK_KEY) ) && (!key_pressed) && (!Power_on))
		    {
		    	key_pressed   = 1;
		    	Backlit_damp  = 1;
		    	Timeout_Count = 1;
		    	Leds |= KEY_LED;
		    }
		    
		    if((Timeout_Count == 0) && (Timeout_Count1 != 10) && (!entry) && (message == 10))
		    {
		    	entry = 1;
		    	update_values();
		    }
		    
	          	         	                                 
	    UpdateLcd(); 
	}
}

void Init_Module(void)
{  
  Power_on = 1;
  Clock_Init(); 
  Init_Ports();
  LcdInit();
  //Timer_A_init();
  Timer_B_init();
  setup_spi_port();
  Key_Interrupt_Init();
  Init_flags();
  Logic_Flags_Reset();
  

  AL1_RELAY_OFF      
  AL2_RELAY_OFF      
  AL3_RELAY_OFF      
  AL4_RELAY_OFF      
  FAILSAFE_RELAY_OFF      
  GF.Show_Conc_Flag  = 0;
}

void Clock_Init(void)
{
    //BCSCTL1 = CALBC1_4MHZ; 
    //DCOCTL =  CALDCO_4MHZ; 
	
	BCSCTL1 = 0xC7;
	BCSCTL2 = 0x00;
	BCSCTL3 = 0x20;
}

