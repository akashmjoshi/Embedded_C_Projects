#include "system.h"

uint32_t range = 999999;
uint16_t passward;
uint16_t factory_passward;
uint16_t new_passward;
uint8_t  message;
uint8_t  entry = 0;
uint8_t Fault_Flash_ON;
uint8_t Fault_Flash_ON_update;



uint8_t   Use_AL= 0;
uint8_t   Set_Point = 0;
float64_t Set_point_data  = 0.0;
uint32_t  Hysterisis_data = 0;
uint8_t   AL_High_Logic   = 0;
uint8_t   AL_Latch        = 0;
uint32_t  Time_delay_data = 0;
uint8_t	  Set_point_Negative= 0;


/************SERIAL*****************************/
uint8_t  Channel_Enable_data = 1;
uint8_t  Slave_ID_data       = 0;
uint8_t  Read_Register_data  = 0;
uint16_t PV_Address_data     = 0;
uint8_t  Device_ID_data;
uint8_t  Baudrate_Count;
uint8_t  Parity_Count;
uint8_t  Stop_bit_Count;

uint8_t  Channel_Enable_update = 1;
uint8_t  Slave_ID_update       = 0;
uint8_t  Read_Register_update  = 0;
uint16_t PV_Address_update     = 0;
uint8_t  Device_ID_data_update;
uint8_t  Baudrate_Count_update;
uint8_t  Parity_Count_update;
uint8_t  Stop_bit_Count_update;
/************SERIAL*****************************/


/************DISPLAY****************************/
uint8_t   dp         = 0;
uint16_t  gas_no     = 0;
uint8_t   unit_count = 0;
uint8_t   sec_lmp;
uint8_t   minute_lmp; 
uint8_t   hour_lmp;
uint32_t  Fail_Safe_Delay_data;


uint8_t   dp_update         = 0;
uint16_t  gas_no_update     = 0;
uint8_t   unit_count_update = 0;
uint8_t   sec_lmp_update;
uint8_t   minute_lmp_update; 
uint8_t   hour_lmp_update;
uint32_t  Fail_Safe_Delay_data_update;
uint8_t   AL_Failsafe_update;
/************DISPLAY*****************************/


/************ALARM*******************************/
/**************************************************/
float64_t Set_point1_data; 
float64_t Hysterisis1_data;
uint32_t  Time_delay1_data;
uint8_t   Set_point1_Negative;  
  
uint8_t   Use_AL1_update;
float64_t Set_point1_data_update;
float64_t Hysterisis1_data_update;
uint8_t   AL1_High_Logic_update;
uint8_t   AL1_Latch_update;
uint32_t  Time_delay1_data_update; 
uint8_t	  Set_point1_Negative_update;	 
/**************************************************/
  
  
/**************************************************/  
float64_t Set_point2_data;                 
float64_t Hysterisis2_data;    
uint32_t  Time_delay2_data; 
uint8_t   Set_point2_Negative;

uint8_t   Use_AL2_update;
float64_t Set_point2_data_update;            
float64_t Hysterisis2_data_update;
uint8_t   AL2_High_Logic_update;
uint8_t   AL2_Latch_update;     
uint32_t  Time_delay2_data_update;
uint8_t	  Set_point2_Negative_update; 
/**************************************************/ 


/**************************************************/  
float64_t Set_point3_data;                 
float64_t Hysterisis3_data;    
uint32_t  Time_delay3_data; 
uint8_t   Set_point3_Negative;

uint8_t   Use_AL3_update;
float64_t Set_point3_data_update;            
float64_t Hysterisis3_data_update;
uint8_t   AL3_High_Logic_update;
uint8_t   AL3_Latch_update;     
uint32_t  Time_delay3_data_update;
uint8_t	  Set_point3_Negative_update; 
/**************************************************/ 



/**************************************************/  
float64_t Set_point4_data;                 
float64_t Hysterisis4_data;    
uint32_t  Time_delay4_data; 
uint8_t   Set_point4_Negative;

uint8_t   Use_AL4_update;
float64_t Set_point4_data_update;            
float64_t Hysterisis4_data_update;
uint8_t   AL4_High_Logic_update;
uint8_t   AL4_Latch_update;     
uint32_t  Time_delay4_data_update;
uint8_t	  Set_point4_Negative_update; 
/**************************************************/ 


/**************************************************/ 
uint8_t   Buzzer_ON;    
uint32_t  Fail_Safe_Delay_data;

uint32_t  Fail_Safe_Delay_data_update;
uint8_t   Buzzer_ON_update;  
uint8_t   AL_Failsafe_update;
/**************************************************/
/************ALARM*******************************/


/************OUTPUT******************************/
float64_t Output_Low_data = 0;
float64_t Output_High_data= 0;
uint8_t Output_High_Negative= 0;
uint8_t Output_Low_Negative = 0;
uint8_t Output_Type= 0;
uint8_t  Scale_Type;
uint16_t correction_factor_3_7mA= 0;
uint16_t correction_factor_3_8mA= 0;
uint16_t correction_factor_4mA  = 0;
uint16_t correction_factor_8mA  = 0;
uint16_t correction_factor_12mA = 0;
uint16_t correction_factor_16mA = 0;
uint16_t correction_factor_20mA = 0;
uint16_t correction_factor_21mA = 0;
uint16_t correction_factor_23mA = 0;


float64_t Output_Low_data_update = 0;
float64_t Output_High_data_update= 0;
uint8_t Output_High_Negative_update= 0;
uint8_t Output_Low_Negative_update = 0;
uint8_t Output_Type_update= 0;
uint8_t  Scale_Type_update;
uint16_t correction_factor_3_8mA_update= 0;
uint16_t correction_factor_4mA_update  = 0;
uint16_t correction_factor_8mA_update  = 0;
uint16_t correction_factor_12mA_update = 0;
uint16_t correction_factor_16mA_update = 0;
uint16_t correction_factor_20mA_update = 0;
uint16_t correction_factor_21mA_update = 0;
/************OUTPUT******************************/

uint16_t address_val = 0;



/*---------------------------------------------------------------------------
* Function name       : uint16_t get_2_byte_value_from_eeprom(uint16_t high_address)
*     returns         : uint16_t value_from_eeprom
*     arg1            : uint16_t high_address
*     arg2            : 
* Created by          : N.Singh & Bala. J
* Date created        : 11/10/10
* Description         : reads 2 bytes from the eeprom and returns the actual
*                       value. 
*---------------------------------------------------------------------------*/
uint16_t read_2byte_memory(uint16_t high_address)
{
   uint16_t temp;
   uint16_t value_from_eeprom = 0x0000u;   
            

   value_from_eeprom = read_byte_memory(high_address);
   value_from_eeprom = value_from_eeprom << 8;
   temp = read_byte_memory(high_address + 1);   /* see eeprom.h for detailed table of eeprom contents */
   value_from_eeprom |= temp;                              /* assumes the low address is the next address, adds it on */
   
   return value_from_eeprom;
}


/*---------------------------------------------------------------------------
* Function name       : void send_2_byte_value_to_eeprom(uint16_t value_to_send, uint16_t high_address)
*     returns         : -
*     arg1            : uint16_t value_to_send
*     arg2            : uint16_t high_address
* Created by          : N.Singh & Bala. J
* Date created        : 11/10/10
* Description         : Organises sending of a 2 byte value to an address
* 						in the eeprom. 
*---------------------------------------------------------------------------*/




void write_2byte_memory(uint16_t high_address, uint16_t value_to_send)
//void send_2_byte_value_to_eeprom(uint16_t value_to_send, uint16_t high_address)
{
   static uint8_t local_msb_byte;   
   static uint8_t local_lsb_byte;
         
   local_msb_byte = (uint8_t) ((value_to_send >> 8) & 0x00FFu);      
   local_lsb_byte = (uint8_t) (value_to_send & 0x00FFu);
   if (high_address == 0x0000u)
   {
      high_address = 0x0000;
   }
   
   write_byte_memory( high_address, local_msb_byte);
   write_byte_memory((high_address + 1), local_lsb_byte);
   
}


/*---------------------------------------------------------------------------
* Function name       : void wait_for_eeprom(void)
*     returns         : -
*     arg1            : -
*     arg2            : -
* Created by          : N.Singh & Bala. J
* Date created        : 11/10/10
* Description         : Wait for the transmit interrupt to complete transmission.
*---------------------------------------------------------------------------*/
void wait_for_eeprom(void)
{
   eeprom_action_complete = FALSE;                              /* initialise flag to false */
   UC1IE |= UCB1TXIE;                                       	/* enable the B1 SPI port interrupt*/
   while (eeprom_action_complete == FALSE)                      /* when the interrupt has not yet completed */
   {
      /* wait for the isr to execute */
   }
   eeprom_action_complete = FALSE;                              /* reset the flag to false */
}

/*---------------------------------------------------------------------------
* Function name       : void eeprom_write_enable(void)
*     returns         : -
*     arg1            : -
*     arg2            : -
* Created by          : N.Singh & Bala. J
* Date created        : 11/10/10
* Description         : This function transmits a write enable request to the
* 						eeprom. This should be done before writing data to the eeprom. 
*---------------------------------------------------------------------------*/
void eeprom_write_enable(void)
{
   data_to_eeprom_buffer[0] = EEPROM_WRITE_ENABLE;           	/* send a write enable request */
   eeprom_data_size = 1;                                    	/* only 1 byte is being sent to the eeprom */
   wait_for_eeprom();                                        	/* wait until this is completed before doing anything else*/   
}

/*---------------------------------------------------------------------------
* Function name       : void eeprom_write_disable(void)
*     returns         : -
*     arg1            : -
*     arg2            : -
* Created by          : N.Singh & Bala. J
* Date created        : 11/10/10
* Description         : This function transmits a write disable request to the
* 						eeprom. This should be done after writing data to the eeprom. 
*---------------------------------------------------------------------------*/
void eeprom_write_disable(void)
{
   data_to_eeprom_buffer[0] = EEPROM_WRITE_DISABLE;         /* send a write disable request*/
   eeprom_data_size = 1;                                    /* only 1 byte is being sent to the eeprom */
   wait_for_eeprom();                                       /* wait until this is completed before doing anything else*/
}

/*---------------------------------------------------------------------------
* Function name       : void write_byte_to_eeprom(uint16_t eeprom_address, uint8_t data_to_write_to_eeprom)
*     returns         : -
*     arg1            : uint16_t eeprom_address
*     arg2            : uint8_t data_to_write_to_eeprom
* Created by          : N.Singh & Bala. J
* Date created        : 11/10/10
* Description         : This function writes a byte 'data_to_write_to_eeprom'
* 						to the eeprom at memory address 'eeprom_address'.
*---------------------------------------------------------------------------*/





void write_byte_memory(uint16_t eeprom_address, uint8_t data_to_write_to_eeprom)
//void write_byte_to_eeprom(uint8_t data_to_write_to_eeprom, uint16_t eeprom_address)
{
   uint8_t eeprom_address_high;
   uint8_t eeprom_address_low;
   
   eeprom_address_high = (uint8_t) ((eeprom_address >> 8) & 0x00FFu);  /* record the msb */
   eeprom_address_low  = (uint8_t) (eeprom_address  & 0x00FFu);        /* record the lsb */
   eeprom_write_enable();                                   /* enable eeprom write */
   data_to_eeprom_buffer[0] = EEPROM_WRITE_CMD;             /* send command to eeprom for writing data */
   data_to_eeprom_buffer[1] = eeprom_address_high;          /* send the first byte of the address to write to */
   data_to_eeprom_buffer[2] = eeprom_address_low;           /* send the second byte of the address to write to */
   data_to_eeprom_buffer[3] = data_to_write_to_eeprom;      /* send the data byte */
   eeprom_data_size = 3;                                    /* 3 bytes in total to be sent to the eeprom */
   wait_for_eeprom();                                       /* wait for the data to be sent to the eeprom */
   eeprom_write_disable();                                  /* disable writing data to eeprom memory */
}

/*---------------------------------------------------------------------------
* Function name       : uint8_t read_byte_from_eeprom(uint16_t eeprom_read_address)
*     returns         : uint8_t read_value
*     arg1            : uint16_t eeprom_read_address
*     arg2            : -
* Created by          : N.Singh &  Bala. J
* Date created        : 11/10/10
* Description         : This function returns a single byte read from the
* 						eeprom at address 'eeprom_read_address'
*---------------------------------------------------------------------------*/


uint8_t read_byte_memory(uint16_t eeprom_read_address)
//uint8_t read_byte_from_eeprom(uint16_t eeprom_read_address)
{
   uint8_t eeprom_read_address_low;                  	/* need to convert the 16 bit address into two seperate bytes */      
   uint8_t eeprom_read_address_high;                  	/* now get the most significant byte */
   eeprom_read_address_high = (uint8_t) ((eeprom_read_address >> 8) & 0x00FFu);    	/* record the msb */
   eeprom_read_address_low  = (uint8_t) (eeprom_read_address  & 0x00FFu);       	/* record the lsb */
   data_from_eeprom_buffer[3]='b';   
   data_to_eeprom_buffer[0] = EEPROM_READ_CMD;        	/* send command to eeprom for reading data */
   data_to_eeprom_buffer[1] = eeprom_read_address_high; /* send the first byte of the address to read from */
   data_to_eeprom_buffer[2] = eeprom_read_address_low;  /* send the second byte of the address to read from */
   eeprom_data_size = 3;                                /* 3 bytes in total to be sent to the eeprom */
   wait_for_eeprom();
   return (data_from_eeprom_buffer[3]);                 /* return the received value from the eeprom */
} 



void send_factory_eeprom_values(void)
{
	uint8_t i = 0;
	saving_value = 1;
	setup_spi_port();
		
	write_2byte_memory(EEPROM_VERIFICATION_ADD,6611);
	write_2byte_memory(FACTORY_PASSWARD_ADD,1357);	
	write_2byte_memory(PASSWARD_ADD,1);
	
	
	write_byte_memory((Channel_Enable_ADD),0);
	write_byte_memory((Slave_ID_ADD),1);
	write_byte_memory((Read_Register_ADD),0);
	write_2byte_memory((PV_Address_ADD),0);
	write_byte_memory(Device_ID_ADD,1);	
	write_byte_memory(Baudrate_Count_ADD,0);	
	write_byte_memory(Parity_Count_ADD,0);	
	write_byte_memory(Stop_bit_Count_ADD,1);
	
	write_byte_memory((DP_ADD),0);
	write_2byte_memory((GAS_NO_ADD),0);
	write_byte_memory((UNIT_ADD),0);
	write_byte_memory(SEC_ADD,5);
	write_byte_memory(MINUTE_ADD,0);
	write_byte_memory(HOUR_ADD,0);
	write_2byte_memory(N_HI_ADD,0);

     
	write_byte_memory(backlit_ADD,1);
    write_byte_memory(backlit_count_ADD,1); 
	write_byte_memory(Fault_Flash_ON_ADD,0);	
    
    address_val = NAME1_OFFSET_0_ADD;
	for(i=0;i<13;i++)
	{
		write_byte_memory(address_val,65); 		//NAME1
		write_byte_memory(address_val+1,66);	//NAME2
		write_byte_memory(address_val+2,67);	//NAME3
		write_byte_memory(address_val+3,68);	//NAME4
		write_byte_memory(address_val+4,69);	//NAME5
		
		address_val = address_val+5;
	}
	address_val = 0;
   

	    	    	
	write_byte_memory(AL1_ADD,0);
	write_byte_memory(AL2_ADD,0);
	write_byte_memory(AL3_ADD,0);
	write_byte_memory(AL4_ADD,0);
    write_2byte_memory(Set_point1_ADD,5);
    write_2byte_memory(Set_point2_ADD,5);
    write_2byte_memory(Set_point3_ADD,5);
    write_2byte_memory(Set_point4_ADD,5);
    write_2byte_memory(Hysterisis1_ADD,0);
    write_2byte_memory(Hysterisis2_ADD,0);
    write_2byte_memory(Hysterisis3_ADD,0);
    write_2byte_memory(Hysterisis4_ADD,0);
    write_2byte_memory(Time_delay1_ADD,0);
	write_2byte_memory(Time_delay2_ADD,0);
	write_2byte_memory(Time_delay3_ADD,0);
	write_2byte_memory(Time_delay4_ADD,0);
	write_byte_memory(AL1_HI_Logic_ADD,0);
	write_byte_memory(AL2_HI_Logic_ADD,0);
	write_byte_memory(AL3_HI_Logic_ADD,0);
	write_byte_memory(AL4_HI_Logic_ADD,0);
	write_byte_memory(AL1_Latch_ADD,0);
	write_byte_memory(AL2_Latch_ADD,0);
	write_byte_memory(AL3_Latch_ADD,0);
	write_byte_memory(AL4_Latch_ADD,0);
	write_byte_memory(Buzzer_ON_ADD,0);
    write_byte_memory(Set_point1_Negative_ADD,0);
    write_byte_memory(Set_point2_Negative_ADD,0);
    write_byte_memory(Set_point3_Negative_ADD,0);
    write_byte_memory(Set_point4_Negative_ADD,0);	



	write_byte_memory(AL_Failsafe_ADD,0);
	write_2byte_memory(Failsafe_Delay_ADD,0);
	    		
		
	    write_2byte_memory((Output_Low_ADD),0);
	    write_2byte_memory((Output_High_ADD),5);		
	    write_byte_memory((Output_High_Negative_ADD),0);
	    write_byte_memory((Output_Low_Negative_ADD),0);
	    write_byte_memory((Output_Type_ADD),0);
	
	    	   
		write_2byte_memory((correction_factor_3_8mA_ADD),300);
		write_2byte_memory((correction_factor_4mA_ADD),300);
		write_2byte_memory((correction_factor_8mA_ADD),300);
		write_2byte_memory((correction_factor_12mA_ADD),300);
		write_2byte_memory((correction_factor_16mA_ADD),300);
		write_2byte_memory((correction_factor_20mA_ADD),300);
		write_2byte_memory((correction_factor_21mA_ADD),300);			
				

	saving_value = 0;
	
}


void DP_change_factory_values(void)
{

	saving_value = 1;
	setup_spi_port();
	
	write_byte_memory(AL1_ADD,0);
	write_byte_memory(AL2_ADD,0);
	write_byte_memory(AL3_ADD,0);
	write_byte_memory(AL4_ADD,0);	
	write_2byte_memory(Set_point1_ADD,0);
    write_2byte_memory(Set_point2_ADD,0);
    write_2byte_memory(Set_point3_ADD,0);
    write_2byte_memory(Set_point4_ADD,0);
    write_2byte_memory(Hysterisis1_ADD,0);
    write_2byte_memory(Hysterisis2_ADD,0);
    write_2byte_memory(Hysterisis3_ADD,0);
    write_2byte_memory(Hysterisis4_ADD,0);
    write_byte_memory(AL1_HI_Logic_ADD,0);
	write_byte_memory(AL2_HI_Logic_ADD,0);
    write_byte_memory(AL3_HI_Logic_ADD,0);
	write_byte_memory(AL4_HI_Logic_ADD,0);
	write_byte_memory(AL1_Latch_ADD,0);
	write_byte_memory(AL2_Latch_ADD,0);
	write_byte_memory(AL3_Latch_ADD,0);
	write_byte_memory(AL4_Latch_ADD,0);
	write_2byte_memory(Time_delay1_ADD,0);
	write_2byte_memory(Time_delay2_ADD,0);
	write_2byte_memory(Time_delay3_ADD,0);
	write_2byte_memory(Time_delay4_ADD,0);
    write_byte_memory(Set_point1_Negative_ADD,0);
    write_byte_memory(Set_point2_Negative_ADD,0);
    write_byte_memory(Set_point3_Negative_ADD,0);
    write_byte_memory(Set_point4_Negative_ADD,0);
	write_byte_memory(Buzzer_ON_ADD,0);
		
		    
    write_2byte_memory((Output_Low_ADD),0);
    write_2byte_memory((Output_High_ADD),(5*pow(10,dp)));
    write_byte_memory((Output_High_Negative_ADD),0);
    write_byte_memory((Output_Low_Negative_ADD),0);
				
	channel = 0;
	saving_value = 0;  		
}


void get_initial_eeprom_values(void)
{
	uint8_t i = 0;
	saving_value = 1;
	setup_spi_port();
		
		
    passward = read_2byte_memory(PASSWARD_ADD);
    factory_passward = read_2byte_memory(FACTORY_PASSWARD_ADD);
	
	


/*****************Output****************************************/
		Output_Low_data = (float64_t)(read_2byte_memory(Output_Low_ADD)/pow(10,dp));
		Output_High_data =(float64_t)(read_2byte_memory(Output_High_ADD)/pow(10,dp));	
		Output_High_Negative = read_byte_memory(Output_High_Negative_ADD);
	    Output_Low_Negative = read_byte_memory(Output_Low_Negative_ADD);
	    Output_Type = read_byte_memory(Output_Type_ADD);
	    Scale_Type = read_byte_memory(Scale_Type_ADD);
	    
	    correction_factor_3_7mA = read_2byte_memory(correction_factor_3_7mA_ADD);
		correction_factor_3_8mA = read_2byte_memory(correction_factor_3_8mA_ADD);
		correction_factor_4mA  = read_2byte_memory(correction_factor_4mA_ADD);
		correction_factor_8mA  = read_2byte_memory(correction_factor_8mA_ADD);
		correction_factor_12mA = read_2byte_memory(correction_factor_12mA_ADD);
		correction_factor_16mA = read_2byte_memory(correction_factor_16mA_ADD);
		correction_factor_20mA = read_2byte_memory(correction_factor_20mA_ADD);
		correction_factor_21mA = read_2byte_memory(correction_factor_21mA_ADD);
		correction_factor_23mA = read_2byte_memory(correction_factor_23mA_ADD);
	   
	   
	   
	    Output_Low_data_update = Output_Low_data;
	    Output_High_data_update = Output_High_data;
	    Output_Low_Negative_update = Output_Low_Negative;
	    Output_High_Negative_update = Output_High_Negative;
	    Output_Type_update = Output_Type;
	    Scale_Type_update = Scale_Type;
	    
	    correction_factor_3_8mA_update = correction_factor_3_8mA;
	    correction_factor_4mA_update  = correction_factor_4mA;
	    correction_factor_8mA_update  = correction_factor_8mA;
	    correction_factor_12mA_update = correction_factor_12mA;
	    correction_factor_16mA_update = correction_factor_16mA;
	    correction_factor_20mA_update = correction_factor_20mA;
	    correction_factor_21mA_update = correction_factor_21mA;
	    
/*****************Output****************************************/
	
	
/*****************Display****************************************/	
    unit_count = read_byte_memory(UNIT_ADD);	
	gas_no = read_2byte_memory(GAS_NO_ADD);    
    sec_lmp    = read_byte_memory(SEC_ADD);
	minute_lmp = read_byte_memory(MINUTE_ADD);
	hour_lmp   = read_byte_memory(HOUR_ADD);
    if(hour_lmp == 0)
    {
    	hour_complete = 1;
    	if(minute_lmp == 0)
    	minute_complete = 1;
    } 
      
    gas_no_update     = gas_no;
	unit_count_update = unit_count;    
    sec_lmp_update    = sec_lmp;
    minute_lmp_update = minute_lmp;
    hour_lmp_update   = hour_lmp;
    
    
    
    address_val = NAME1_OFFSET_0_ADD;
	for(i=0;i<13;i++)
	{
		Name_List.Name1[i] = read_byte_memory(address_val);
		Name_List.Name2[i] = read_byte_memory(address_val+1);
		Name_List.Name3[i] = read_byte_memory(address_val+2);
		Name_List.Name4[i] = read_byte_memory(address_val+3);
		Name_List.Name5[i] = read_byte_memory(address_val+4);
		
		address_val = address_val+5;
	}
	address_val = 0;
	Name_List.Name1[13] = '\0';
	Name_List.Name2[13] = '\0';
	Name_List.Name3[13] = '\0';
	Name_List.Name4[13] = '\0';
	Name_List.Name5[13] = '\0';

/*****************Display****************************************/
	
	
/*****************backlit****************************************/	
	Backlit_Count = read_byte_memory(backlit_count_ADD);
    Fault_Flash_ON = read_byte_memory(Fault_Flash_ON_ADD);
	
	Fault_Flash_ON_update = Fault_Flash_ON;
    Backlit_Count_update = Backlit_Count;
    
    if((Backlit_Count == 1)||(Backlit_Count == 3))
    Logic.backlit = 1;
    else if(Backlit_Count == 2)
	Logic.backlit = 0;
/*****************backlit****************************************/

	
/*****************serial****************************************/	
    //Channel_Enable_data = read_byte_memory(Channel_Enable_ADD);
	Slave_ID_data       = read_byte_memory(Slave_ID_ADD);
	Read_Register_data  = read_byte_memory(Read_Register_ADD);
	PV_Address_data     = read_2byte_memory(PV_Address_ADD);
	Device_ID_data = read_byte_memory(Device_ID_ADD);
    Baudrate_Count = read_byte_memory(Baudrate_Count_ADD);
	Parity_Count = read_byte_memory(Parity_Count_ADD);
	Stop_bit_Count = read_byte_memory(Stop_bit_Count_ADD);
	
	
	//Channel_Enable_update = Channel_Enable_data;
	Slave_ID_update       = Slave_ID_data;
	Read_Register_update  = Read_Register_data;
	PV_Address_update     = PV_Address_data;
	Device_ID_data_update = Device_ID_data;
    Baudrate_Count_update = Baudrate_Count;
    Parity_Count_update   = Parity_Count;
    Stop_bit_Count_update = Stop_bit_Count;
	
	
	if(Baudrate_Count == 0)
    Modbus_baudrate = 9600;
	else if(Baudrate_Count == 1)
	Modbus_baudrate = 19200;
	else if(Baudrate_Count == 2)
    Modbus_baudrate = 38400;
/*****************serial****************************************/ 



/*****************alarm****************************************/							
    Logic.AL1 = read_byte_memory(AL1_ADD);
	Logic.AL2 = read_byte_memory(AL2_ADD); 
	Logic.AL3 = read_byte_memory(AL3_ADD);
	Logic.AL4 = read_byte_memory(AL4_ADD);   
	Set_point1_data =(float64_t) (read_2byte_memory(Set_point1_ADD)/pow(10,dp));
    Set_point2_data =(float64_t) (read_2byte_memory(Set_point2_ADD)/pow(10,dp));
    Set_point3_data =(float64_t) (read_2byte_memory(Set_point3_ADD)/pow(10,dp));
    Set_point4_data =(float64_t) (read_2byte_memory(Set_point4_ADD)/pow(10,dp));
    Hysterisis1_data =(float64_t) (read_2byte_memory(Hysterisis1_ADD)/pow(10,dp));
    Hysterisis2_data =(float64_t) (read_2byte_memory(Hysterisis2_ADD)/pow(10,dp));
    Hysterisis3_data =(float64_t) (read_2byte_memory(Hysterisis3_ADD)/pow(10,dp));
    Hysterisis4_data =(float64_t) (read_2byte_memory(Hysterisis4_ADD)/pow(10,dp));	
	Logic.AL1_HI_Logic  = read_byte_memory(AL1_HI_Logic_ADD);
    Logic.AL2_HI_Logic  = read_byte_memory(AL2_HI_Logic_ADD);
    Logic.AL3_HI_Logic  = read_byte_memory(AL3_HI_Logic_ADD);
    Logic.AL4_HI_Logic  = read_byte_memory(AL4_HI_Logic_ADD);
	Logic.AL1_Latch     = read_byte_memory(AL1_Latch_ADD);
	Logic.AL2_Latch     = read_byte_memory(AL2_Latch_ADD);
	Logic.AL3_Latch     = read_byte_memory(AL3_Latch_ADD);
	Logic.AL4_Latch     = read_byte_memory(AL4_Latch_ADD);    	
	Time_delay1_data    = read_2byte_memory(Time_delay1_ADD);
	Time_delay2_data    = read_2byte_memory(Time_delay2_ADD);
	Time_delay3_data    = read_2byte_memory(Time_delay3_ADD);
	Time_delay4_data    = read_2byte_memory(Time_delay4_ADD);
	Set_point1_Negative  = read_byte_memory(Set_point1_Negative_ADD);
    Set_point2_Negative  = read_byte_memory(Set_point2_Negative_ADD);
    Set_point3_Negative  = read_byte_memory(Set_point3_Negative_ADD);
    Set_point4_Negative  = read_byte_memory(Set_point4_Negative_ADD);
    Buzzer_ON           = read_byte_memory(Buzzer_ON_ADD);		


	Use_AL1_update = Logic.AL1;
	Use_AL2_update = Logic.AL2;
	Use_AL3_update = Logic.AL3;
	Use_AL4_update = Logic.AL4;
	
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
	
	Set_point1_data_update  = Set_point1_data;
	Set_point2_data_update  = Set_point2_data; 
	Set_point3_data_update  = Set_point3_data;
	Set_point4_data_update  = Set_point4_data; 
	     
	Hysterisis1_data_update = Hysterisis1_data;     
	Hysterisis2_data_update = Hysterisis2_data;
	Hysterisis3_data_update = Hysterisis3_data;     
	Hysterisis4_data_update = Hysterisis4_data;
	
	AL1_High_Logic_update   = Logic.AL1_HI_Logic;
	AL2_High_Logic_update   = Logic.AL2_HI_Logic;
	AL3_High_Logic_update   = Logic.AL3_HI_Logic;
	AL4_High_Logic_update   = Logic.AL4_HI_Logic;
	
	AL1_Latch_update        = Logic.AL1_Latch;
	AL2_Latch_update        = Logic.AL2_Latch;
	AL3_Latch_update        = Logic.AL3_Latch;
	AL4_Latch_update        = Logic.AL4_Latch;
	
	Time_delay1_data_update = Time_delay1_data;     
    Time_delay2_data_update = Time_delay2_data;
    Time_delay3_data_update = Time_delay3_data;     
    Time_delay4_data_update = Time_delay4_data;
     
    Set_point1_Negative_update = Set_point1_Negative;		 
    Set_point2_Negative_update = Set_point2_Negative;  
    Set_point3_Negative_update = Set_point3_Negative;		 
    Set_point4_Negative_update = Set_point4_Negative; 
     

	
    Buzzer_ON_update = Buzzer_ON;
    
    Logic.AL_Failsafe   = read_byte_memory(AL_Failsafe_ADD);
	AL_Failsafe_update  = Logic.AL_Failsafe;
    if(AL_Failsafe_update)
	FAILSAFE_RELAY_ON    //ON
    else
	FAILSAFE_RELAY_OFF   //OFF
/*****************alarm****************************************/
        	     	     
    N_HI = read_2byte_memory(N_HI_ADD);    	     	     
    N_HI++;
    if(N_HI > 150)
    while(1);
    write_2byte_memory(N_HI_ADD,N_HI);
  
    
    saving_value = 0;

}





void update_values(void)
{	
	Position = 0;
	channel  = 0;
	saving_value = 1;
	//setup_spi_port();
	logic_off = 0;
	GF.Valid_passward = 0;
    Global_Values_Reset();
    


/***************Serial*****************************************************/    
   // Channel_Enable_data = Channel_Enable_update;
	Slave_ID_data       = Slave_ID_update;
	Read_Register_data  = Read_Register_update;
	PV_Address_data     = PV_Address_update;
    
    Device_ID_data = Device_ID_data_update;
    Baudrate_Count = Baudrate_Count_update;
    Parity_Count   = Parity_Count_update; 
    Stop_bit_Count = Stop_bit_Count_update;
/***************Serial*****************************************************/

    
/***************Backlit*****************************************************/    
    Backlit_Count = Backlit_Count_update;
    if((Backlit_Count == 1)||(Backlit_Count == 3))
    Logic.backlit = 1;
    else if(Backlit_Count == 2)
    Logic.backlit = 0;
    Fault_Flash_ON = Fault_Flash_ON_update;
/***************Backlit*****************************************************/


/***************Display*****************************************************/     
   	 dp = dp_update;
	 gas_no = gas_no_update;
	 unit_count = unit_count_update;
   
     sec_lmp    = sec_lmp_update;
     minute_lmp = minute_lmp_update; 
     hour_lmp   = hour_lmp_update;
/***************Display*****************************************************/ 
  

/***************Alarm*****************************************************/        
    Logic.AL1 = Use_AL1_update;
	Logic.AL2 = Use_AL2_update;
	Logic.AL3 = Use_AL3_update;
	Logic.AL4 = Use_AL4_update;
			
	if(Use_AL1_update == 0)
    {
		Logic.AL1_Blink = 0;
		Logic.AL1_ACK   = 0;
	    start_timer1    = 0;
	    Logic.start_flashing = 0;
    }
	
	if(Use_AL2_update == 0)
    {
		Logic.AL2_Blink = 0;
		Logic.AL2_ACK   = 0;
	    start_timer2    = 0;
	    Logic.start_flashing2 = 0;
    }
    
    if(Use_AL3_update == 0)
    {
		Logic.AL3_Blink = 0;
		Logic.AL3_ACK   = 0;
	    start_timer3    = 0;
	    Logic.start_flashing3 = 0;
    }
    
    if(Use_AL4_update == 0)
    {
		Logic.AL4_Blink = 0;
		Logic.AL4_ACK   = 0;
	    start_timer4    = 0;
	    Logic.start_flashing4 = 0;
    }
	
	Set_point1_data  = Set_point1_data_update;
	Set_point2_data  = Set_point2_data_update; 
	Set_point3_data  = Set_point3_data_update;
	Set_point4_data  = Set_point4_data_update;      
	Hysterisis1_data = Hysterisis1_data_update;     
	Hysterisis2_data = Hysterisis2_data_update;
	Hysterisis3_data = Hysterisis3_data_update;     
	Hysterisis4_data = Hysterisis4_data_update;
	Logic.AL1_HI_Logic = AL1_High_Logic_update;
	Logic.AL2_HI_Logic = AL2_High_Logic_update;
	Logic.AL3_HI_Logic = AL3_High_Logic_update;
	Logic.AL4_HI_Logic = AL4_High_Logic_update;
	Logic.AL1_Latch = AL1_Latch_update;
	Logic.AL2_Latch = AL2_Latch_update;
	Logic.AL3_Latch = AL3_Latch_update;
	Logic.AL4_Latch = AL4_Latch_update;
	Time_delay1_data  = Time_delay1_data_update;     
    Time_delay2_data  = Time_delay2_data_update;
    Time_delay3_data  = Time_delay3_data_update;     
    Time_delay4_data  = Time_delay4_data_update;
     
    Buzzer_ON = Buzzer_ON_update;
	Logic.AL_Failsafe = AL_Failsafe_update;
	Set_point1_Negative = Set_point1_Negative_update;		 
    Set_point2_Negative = Set_point2_Negative_update; 
    Set_point3_Negative = Set_point3_Negative_update;		 
    Set_point4_Negative = Set_point4_Negative_update; 
    Fail_Safe_Delay_data = Fail_Safe_Delay_data_update;
/***************Alarm*****************************************************/


/***************Output*****************************************************/	    
	    Output_Low_data  = Output_Low_data_update;
	    Output_High_data = Output_High_data_update;
	    Output_Low_Negative = Output_Low_Negative_update;
	    Output_High_Negative = Output_High_Negative_update;
	    Scale_Type = Scale_Type_update;
	    
	    Output_Type = Output_Type_update;
	    if((Output_Type == 0)||(Output_Type == 1)) 
	    write_to_register(CONTROL_REG, (OUTPUT_EN|CURRENT_0_24mA));
	            
	    else if((Output_Type == 2)||(Output_Type == 3)) 
	    write_to_register(CONTROL_REG, (OUTPUT_EN|VOLTAGE_0_10V));
	    
	    correction_factor_3_8mA = correction_factor_3_8mA_update;
	    correction_factor_4mA	 = correction_factor_4mA_update;
		correction_factor_8mA	 = correction_factor_8mA_update;
		correction_factor_12mA	 = correction_factor_12mA_update;
		correction_factor_16mA	 = correction_factor_16mA_update;
		correction_factor_20mA	 = correction_factor_20mA_update;
		correction_factor_21mA  = correction_factor_21mA_update;
/***************Output*****************************************************/
        

    Test_data      = 0.0;
	Test_data_Negative = 0; 

    Timeout_Count1  = 10;			    
}
