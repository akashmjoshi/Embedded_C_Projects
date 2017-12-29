#include "system.h"

unsigned int  MainDataArray[MAX_DATA_ARRAY];
unsigned char save_data    = 0;
unsigned char Status_Flag  = 0;
unsigned char Sending_flag = 0;
unsigned int  start_msg,length_msg, data_length,write_address;
unsigned int  write_data;

 MAP_DESC_TYP Input_Register[MAX_IP_REG] = {
//	Address			Data		  offset	
	{ 1		,		 0,			  	0},
	{ 2		,		 0,				1},
	{ 3		,		 0,				2},
	{ 4		,		 0,				3},
	{ 5		,		 0,				4},
	{ 6		,		 0,				5},
	{ 7		,		 0,				6},
	{ 8		,		 0,				7},
	{ 9		,		 0,				8},
	{ 10	,		 0,				9},
	{ 11	,		 0,				10},
	{ 12	,		 0,				11},
	{ 13	,		 0,				12},
	{ 14	,		 0,				13},
	{ 15	,		 0,				14},
	{ 16	,		 0,				15},
	{ 17	,		 0,				16},
	{ 18	,		 0,				17},
	{ 19	,		 0,				18},
	{ 20	,		 0,				19},
	{ 21	,		 0,				20},
	{ 22	,		 0,				21},
	{ 23	,		 0,				22},
	{ 24	,		 0,				23},
	{ 25	,		 0,				24},
	{ 26	,		 0,				25},
	{ 27	,		 0,				26},
	{ 28	,		 0,				27},
	{ 29	,		 0,				28},
	{ 30	,		 0,				29},
	{ 31	,		 0,				30},
	{ 32	,		 0,				31},
	{ 33	,		 0,				32},
	{ 34	,		 0,				33},
	{ 35	,		 0,				34},
	{ 36	,		 0,				35},
	{ 37	,		 0,				36},
	{ 38	,		 0,				37},
	{ 39	,		 0,				38},
	{ 40	,		 0,				39},
	{ 41	,		 0,				40},
	{ 42	,		 0,				41},
	{ 43	,		 0,				42},
	{ 44	,		 0,				43},
	{ 45	,		 0,				44},
	{ 46	,		 0,				45},
	{ 47	,		 0,				46},
	{ 48	,		 0,				47},
	{ 49	,		 0,				48},
	{ 50	,		 0,				49},
};


/*---------------------------------------------------------------------------
* Function name       : void DecodeSlave(void)
*     returns         : -
*     arg1            : -
*     arg2            : -
* Created by          : N.Singh
* Date created        : 11/10/10
* Description         : This function used to decode the query received from
* 						the Modbus master in the RS485 MODBUS network 
*---------------------------------------------------------------------------*/
void DecodeMaster(void)
{
	unsigned int  temp_code1,temp_code2,temp_code3;
    unsigned int  check,s;
    WDTCTL = WDTPW + WDTHOLD;  
    
	{
	     Leds |=  COM_LED;
	     for(s=1000;s>0;s--);
	     Leds &= ~COM_LED;
		
		
		 UC1IE &= ~UCA1RXIE;
		 UART1_rcv_count = 0;

	    
		check = modrtuChecksum ( UART1_RX_buf, 6 );
		
		temp_code1 = UART1_RX_buf[6] ;
   		temp_code2 = (unsigned int) (temp_code1 << 8);
   		temp_code1 = UART1_RX_buf[7] ;
   		temp_code3 = (unsigned int)(temp_code2|temp_code1);
   		
   		if ( check == (unsigned int) ( temp_code3 ) )
   		{
   		   if (UART1_RX_buf[0] == Device_ID_data)
   			{   				   				
   				switch (UART1_RX_buf[1])
		        {
		        	case MODBUS_READ_INPUT_REGISTERS :
		        	case MODBUS_READ_HOLDING_REGISTERS:
		        	
			          	start_msg = (int)UART1_RX_buf[2];    //message start
			         	start_msg <<= 8;
			         	start_msg += (int)UART1_RX_buf[3];
			      
			          	length_msg = (int)UART1_RX_buf[4];   //message length
			         	length_msg <<= 8;
			         	length_msg += (int)UART1_RX_buf[5];
			         
			           	temp_code1 = start_msg + length_msg;
			           
			           	if (temp_code1 <= MAX_IP_REG)  //total number of registers which can be read
			           	{
			           		
			           		send_data(&Input_Register[0]);
			           		
			           	}
			           	else
			            {
			            	 modbusReturnException ( 0x02 );  
			            	 Sending_flag = 0;
			            }         
			         break; 
			         
			         
			       case MODBUS_WRITE_HOLDING_REGISTERS :
			            write_address = (int)UART1_RX_buf[2];    //message start
			         	write_address <<= 8;
			         	write_address += (int)UART1_RX_buf[3];
			      
			          	write_data = (int)UART1_RX_buf[4];   //message length
			         	write_data <<= 8;
			         	write_data += (int)UART1_RX_buf[5];
			         	
			         	if (write_address <= MAX_HL_REG)  //total number of registers which can be write
			         	{
			         		send_echo();
			         		MainDataArray[((&Input_Register[write_address])->offset)] = write_data;
			         		setup_spi_port();
			         		
			         		switch(write_address)
			         		{
			         		
				         		case 2:	
				         		    if(write_data >= (65536-(9999)))
	     						    { 
	     							  Set_point1_data = ((float32_t)(65536-write_data));
	     							  Set_point1_Negative = 1;
	     						    }
	     						    else if(write_data <= 9999)
	     						    { 
	     							  Set_point1_data = (float32_t)write_data;
	     							  Set_point1_Negative = 0;
	     						    }
	     						    
	     						    write_2byte_memory(Set_point1_ADD,Set_point1_data);       
	 				            	write_byte_memory(Set_point1_Negative_ADD,Set_point1_Negative);
	 				            	Set_point1_data = Set_point1_data/pow(10,dp);
					                 
		                        
		                        	Set_point1_data_update  = Set_point1_data;
		                        	Set_point1_Negative_update = Set_point1_Negative;
		                        	break;
				         		       
				         			                            
			                    case 4: 
			                        if(write_data >= (65536-(9999)))
	     						    { 
	     							  Set_point2_data = ((float32_t)(65536-write_data));
	     							  Set_point2_Negative = 1;
	     						    }
	     						    else if(write_data <= 9999)
	     						    { 
	     							  Set_point2_data = (float32_t)write_data;
	     							  Set_point2_Negative = 0;
	     						    }
	     						    
	     						    write_2byte_memory(Set_point2_ADD,Set_point2_data);       
	 				            	write_byte_memory(Set_point2_Negative_ADD,Set_point2_Negative);
	 				            	Set_point2_data = Set_point2_data/pow(10,dp);
					                 
		                        
		                        	Set_point2_data_update  = Set_point2_data;
		                        	Set_point2_Negative_update = Set_point2_Negative;
		                        	break;		                           
			                    
			                    
			                    case 6:
			                        if(write_data >= (65536-(9999)))
	     						    { 
	     							  Set_point3_data = ((float32_t)(65536-write_data));
	     							  Set_point3_Negative = 1;
	     						    }
	     						    else if(write_data <= 9999)
	     						    { 
	     							  Set_point3_data = (float32_t)write_data;
	     							  Set_point3_Negative = 0;
	     						    }
	     						    
	     						    write_2byte_memory((Set_point3_ADD),Set_point3_data);       
	 				            	write_byte_memory((Set_point3_Negative_ADD),Set_point3_Negative);
	 				            	Set_point3_data = Set_point3_data/pow(10,dp);
					                 
		                        
		                        	Set_point3_data_update  = Set_point3_data;
		                        	Set_point3_Negative_update = Set_point3_Negative;
		                        	break;		                            
			                    
			                    
			                    case 8:
			                        if(write_data >= (65536-(9999)))
	     						    { 
	     							  Set_point4_data = ((float32_t)(65536-write_data));
	     							  Set_point4_Negative = 1;
	     						    }
	     						    else if(write_data <= 9999)
	     						    { 
	     							  Set_point4_data = (float32_t)write_data;
	     							  Set_point4_Negative = 0;
	     						    }
	     						    
	     						    write_2byte_memory(Set_point4_ADD,Set_point4_data);       
	 				            	write_byte_memory((Set_point4_Negative_ADD),Set_point4_Negative);
	 				            	Set_point4_data = Set_point4_data/pow(10,dp);
					                 
		                        
		                        	Set_point4_data_update  = Set_point4_data;
		                        	Set_point4_Negative_update = Set_point4_Negative;
		                        	break;
			                        
	        
							  case 9:     //Buzzer ack
							    
							    if(write_data == 1)
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
						        }					        
							   break; 
						        
								    
							   case 10:  //AL1_ACK
							        if((write_data == 1)&&(Logic.AL1_Blink)&&(Logic.AL1_Latch))    	
								    Logic.AL1_ACK = 1;
						  
								    break;    
								    
							   case 11:  //AL2_ACK
							        if((write_data == 1)&&(Logic.AL2_Blink)&&(Logic.AL2_Latch))    	
								    Logic.AL2_ACK = 1;
						  
								    break;    
								    
							   case 12:  //AL3_ACK	
							        if((write_data == 1)&&(Logic.AL3_Blink)&&(Logic.AL3_Latch))    	
								    Logic.AL3_ACK = 1;
							    	    
								    break;    
								    								    
							   case 13:  //AL4_ACK
							        if((write_data == 1)&&(Logic.AL4_Blink)&&(Logic.AL4_Latch))    	
								    Logic.AL4_ACK = 1;
						    
								    break;    
				         			
			         		}			         		
			         		
			         	}
			         	else
			         	{
			            	 modbusReturnException ( 0x02 );
			            	 Sending_flag = 0;
			         	}           
			         	break;   
			         
			         
			      default:
			         	{
			         		modbusReturnException ( 0x01 );
			         		Sending_flag = 0;
			         	} 	   
			         
	           }
   			}
   		}
   		
   		
   		timeout_flag1 = 0;
   		UC1IE |= UCA1RXIE;
	}
		   
}



/*----------------------------------------------------------------------------------
* Function name       : void send_data(MAP_DESC_TYP * ptr)
*     returns         : -
*     arg1            : Pointer to the Database register
*     arg2            : -
* Created by          : N.Singh
* Date created        : 11/10/10
* Description         : This function used to form the response of the query 
* 						received from the Modbus master in the RS485 MODBUS network 
*-----------------------------------------------------------------------------------*/
void send_data(MAP_DESC_TYP * ptr)
{		  
	  unsigned char tempc,i,j;
	  unsigned int tempi;

	 
	 if( Power_on && (Channel_Enable_data == 0) )   //Disable channel
     MainDataArray[0] = 0;
     else if(comfail_error)
     MainDataArray[0] = (uint16_t)32770;    //Comfail channel
     else if(undefined_error)
     MainDataArray[0] = (uint16_t)32769;    //undef error 
     else if(under_error)
     MainDataArray[0] = (uint16_t)32768;    //under error
     else if(over_error)
     MainDataArray[0] = (uint16_t)32766;    //over error
     else if(open_error)
     MainDataArray[0] = (uint16_t)32767;    //open error
     else
     MainDataArray[0] =(Process_Negative)? (unsigned int)(65536 - (uint16_t)(process_value * pow(10,dp))):(unsigned int)(process_value * pow(10,dp));  //gas conc.       	
     
    
	 MainDataArray[1] = (Logic.AL1)?1:0;             //Use AL1	
	 MainDataArray[2] = (Set_point1_Negative)?(unsigned int)(65536 - (Set_point1_data * pow(10,dp))):(unsigned int)(Set_point1_data * pow(10,dp));  //set pt1	   	
	 
	 MainDataArray[3] = (Logic.AL2)? 1:0;	//Use AL1 
     MainDataArray[4] = (Set_point2_Negative)?(unsigned int)(65536 - (Set_point2_data * pow(10,dp))):(unsigned int)(Set_point2_data * pow(10,dp));  //set pt2
	 
	 MainDataArray[5] =(Logic.AL3)?1:0;  //Use AL3		  
	 MainDataArray[6] =(Set_point3_Negative)?(unsigned int)(65536 - (Set_point3_data * pow(10,dp))):(unsigned int)(Set_point3_data *pow(10,dp));  //set pt3
	 
	 MainDataArray[7] =(Logic.AL4)?1:0;  //Use AL4	  
	 MainDataArray[8] =(Set_point4_Negative)?(unsigned int)(65536 - (Set_point4_data * pow(10,dp))):(unsigned int)(Set_point4_data *pow(10,dp));  //set pt4
	 
	 MainDataArray[9]  = (unsigned int)Buzzer_ack;
	 	 
	 MainDataArray[10] = (Logic.AL1_ACK)? 1:0;	 
	 MainDataArray[11] = (Logic.AL2_ACK)? 1:0;
	 MainDataArray[12] = (Logic.AL3_ACK)? 1:0;	 
	 MainDataArray[13] = (Logic.AL4_ACK)? 1:0;
    
     MainDataArray[14] =  (Output_Low_Negative) ?(unsigned int)(65536 - (Output_Low_data  * pow(10,dp))):(unsigned int)(Output_Low_data *pow(10,dp));  //Lo Range	   	
     MainDataArray[15] =  (Output_High_Negative)?(unsigned int)(65536 - (Output_High_data * pow(10,dp))):(unsigned int)(Output_High_data *pow(10,dp));  //Hi Range		 
	 MainDataArray[16] = (unsigned int)Output_Type;         //output type
	
	
	 MainDataArray[17] = (unsigned int)dp;                  //dp	 
	 MainDataArray[18] = (unsigned int)unit_count;          //unit
	 MainDataArray[19] = (unsigned int)Backlit_Count;       //Backlit	 
	 MainDataArray[20] = (unsigned int)Fault_Flash_ON;      //Fault Flashing
	 MainDataArray[21] = (unsigned int)Status_Flag1;        //status flag1	
	 MainDataArray[22] = (unsigned int)Status_Flag2;        //status flag2 
	 MainDataArray[23] = (unsigned int)Failsafe_ON;         //failsafe relay
	  

	 UART1_TX_Buf[0] = Device_ID_data;
	 UART1_TX_Buf[1] = UART1_RX_buf[1];
	  
	  tempc = (char)length_msg;    
	  UART1_TX_Buf[2] = tempc << 1;  
	
	  tempc = (char)start_msg;   
	  tempc += (char)length_msg;   
	
	  j = 2;  
	  for (i = (char)start_msg; i < tempc; i++)   
	  {     
	    j++;  
	    UART1_TX_Buf[j] = (MainDataArray[((ptr + i)->offset)]) >> 8;      //upper 8 bits
	    j++;
	    UART1_TX_Buf[j] = (MainDataArray[((ptr + i)->offset)]);  //lower 8 bits
	  }  
	 
	  tempi = modrtuChecksum ( UART1_TX_Buf, j+1);  
	  UART1_TX_Buf[j + 1] = tempi >> 8;             //msb of crc
	  UART1_TX_Buf[j + 2] = (unsigned char)tempi;   //lsb of crc
	 
	
	  data_length = j + 2;
	  
	  //TACCTL0 &= ~CCIE;
	  _DINT();
	  modbusSendUARTPacket1 (data_length);
	  _EINT();
	  //TACCTL0 |= CCIE;   
	  
	  Sending_flag = 0;
	
}




/*----------------------------------------------------------------------------------
* Function name       : void send_echo(void)
*     returns         : -
*     arg1            : -
*     arg2            : -
* Created by          : N.Singh
* Date created        : 11/10/10
* Description         : This function used to send the response frame when write operation 
* 						is performed. 
*-----------------------------------------------------------------------------------*/
void send_echo(void)
{
   unsigned char i;
   unsigned int temp;
  
   for(i=0; i<6; i++)
   UART1_TX_Buf[i] = UART1_RX_buf[i];
  	
  temp = modrtuChecksum ( UART1_TX_Buf, 6 );
  UART1_TX_Buf[6] = temp >> 8;    		 //msb of crc
  UART1_TX_Buf[7] = (unsigned char)temp;   //lsb of crc  
        
  modbusSendUARTPacket1(7); 
}

/*----------------------------------------------------------------------------------
* Function name       : void modbusSendUARTPacket ( unsigned char length)
*     returns         : -
*     arg1            : Length of the response packet
*     arg2            : -
* Created by          : N.Singh
* Date created        : 11/10/10
* Description         : This function used to send the data on TX pin. 
*-----------------------------------------------------------------------------------*/
void modbusSendUARTPacket1( unsigned char length)
{
	uint16_t s;
    unsigned char i; 
	  
	  RS485_RTSHigh_1	   //P6.5 high
	  	   
	  for ( i=0; i <= length; i++ )
	  {
	  		UCA1TXBUF = UART1_TX_Buf[i];
	  		while (( UCA1STAT & UCBUSY ));
	  }
	  
	  RS485_RTSLow_1    //P6.5 Low
	  
	  Leds |= COM_LED;
	  for(s=1000;s>0;s--);
	  Leds &= ~COM_LED;
	  
}


/*----------------------------------------------------------------------------------
* Function name       : void modbusReturnException ( unsigned char exception )
*     returns         : -
*     arg1            : Exception value
*     arg2            : -
* Created by          : N.Singh
* Date created        : 11/10/10
* Description         : This function used to send the exception to the modbus master. 
*-----------------------------------------------------------------------------------*/
void modbusReturnException ( unsigned char exception )
{
	   unsigned int check;    
	   
	   UART1_TX_Buf[0]  = Device_ID_data;
	   UART1_TX_Buf[1] |= 0x80 ;      //function code for exception
	   UART1_TX_Buf[2]  = exception;
	   
	   check = modrtuChecksum ( UART1_TX_Buf, 3 );
	   
	   UART1_TX_Buf[3] = check >> 8;    //msb of crc
	   UART1_TX_Buf[4] = (char)check;   //lsb of crc
	
	   
	   modbusSendUARTPacket1(4);
}


