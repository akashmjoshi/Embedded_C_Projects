#include "system.h"

uint16_t PV_address = 0;


void send_request(void)
{
	unsigned int tempi,s;
		
		if(Channel_Enable_data == 0)
		return;
	
				        
        UART_TX_Buffer[0] = Slave_ID_data;	
		UART_TX_Buffer[1] = Read_Register_data? 0x03:0x04;		//function code of holding reg
		
		UART_TX_Buffer[2] =(uint8_t) ((PV_Address_data>>8) & 0x00FF);  	    //address high
		UART_TX_Buffer[3] =(uint8_t) (PV_Address_data & 0x00FF);	        //address low

		UART_TX_Buffer[4] = 0x00;		//length High
		UART_TX_Buffer[5] = 0x01;		//length low
		
		
		tempi = modrtuChecksum ( UART_TX_Buffer, 6 );
	    UART_TX_Buffer[6] = tempi >> 8;    			//msb of crc	0x84;//
	    UART_TX_Buffer[7] = (unsigned char)tempi;   //lsb of crc	0x0a;//
	    
	    
	    modbusSendUARTPacket(7);
	    
        PV_address = PV_Address_data;
        
        
        
		if(ComFail_Count < 30)
		ComFail_Count++;
		
		if(ComFail_Count > 20)
		ComFail = 1;
		else
		ComFail = 0;

	    
	        
	    
	    Leds |=  COM_LED;
	    for(s=1000;s>0;s--);
	    Leds &= ~COM_LED;
	    
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
void modbusSendUARTPacket ( unsigned char length)
{
	  unsigned char i; 

	  RS485_RTSHigh   // P1.2, SIO pin High
	   // Put data in TX_BUFFER
	  for ( i=0; i <= length; i++ )
	  {
	  		UCA0TXBUF = UART_TX_Buffer[i];
	  		while (( UCA0STAT & UCBUSY ));
	  }
     
	 RS485_RTSLow // P1.2, SIO pin Low
}


/*----------------------------------------------------------------------------------
* Function name       : unsigned int modrtuChecksum ( unsigned char *chkbuf, unsigned char len )
*     returns         : Returns the calculated checksum
*     arg1            : Pointer to the array whose checksum needs to be calculated
*     arg2            : Length of the array upto which checksum needs to be calculated
* Created by          : N.Singh
* Date created        : 11/10/10
* Description         : This function used to calculate the checksum. 
*-----------------------------------------------------------------------------------*/
unsigned int modrtuChecksum ( unsigned char *chkbuf, unsigned char len )
{
	   unsigned char    uchCRCHi = 0xff ;
	   unsigned char    uchCRCLo = 0xff ;
	   unsigned int  	uIndex ;
	   unsigned int  	temp_code ;
	
	   while ( len )
		  {
		      uIndex = (unsigned int) ( uchCRCHi ^ *chkbuf++ ) ;	
		      uchCRCHi = (unsigned char) ( uchCRCLo ^ auchCRCHi_exp[uIndex] ) ;
		      uchCRCLo = auchCRCLo_exp[uIndex] ;
		      len-- ;
		  }
	   temp_code = (unsigned int) uchCRCHi ;
	   temp_code = (unsigned int) (temp_code << 8) ;
	   return(unsigned int) (  temp_code | uchCRCLo ) ;
}
