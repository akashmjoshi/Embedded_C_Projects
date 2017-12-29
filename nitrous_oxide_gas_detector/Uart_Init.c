 #include "system.h"
 
unsigned char UART_RX_buf[100]    = {0};   //Receive Buffer
unsigned char UART_TX_Buffer[100] = {0};   //Transmit Buffer

unsigned char UART_rcv_count = 0; 
unsigned char chTemp;
unsigned char timeout      = 0; 
//unsigned char timeout_temp = 0; 
uint16_t timeout_temp = 0; 
unsigned char run_timer    = 0;
unsigned char volatile timeout_flag = 0;
 
 
void UARTInit(void)
{
	  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
	  P3OUT &= ~(BIT4+BIT5);
	  P3SEL |=  (BIT4+BIT5);                             // P3.4,P3.5 = USCI_A0 TXD/RXD
	  
	  P1SEL &= ~BIT2;                             // P1.2 = SIO-1 pin as GPIO
	  P1DIR |=  BIT2;                             // SIO-1 pin P1.2 as output 
	  P1OUT |=  BIT2;                             // SIO-1 pin P1.2 as 0
	 
	  UCA0CTL0 = 0x00;
	  UCA0CTL1 |= UCSSEL_1;                     // CLK = ACLK

	   switch(Parity_Count)
	  {
	  	case 0:
	  		UCA0CTL0 &= ~(0x80);
	  	break;
	  	
	  	case 1:
	  		UCA0CTL0 |= (0xC0);
	  	break;
	  	
	  	case 2:
	  		UCA0CTL0 |= (0x80);
	  		UCA0CTL0 &= ~(0x40);
	  	break;
	  	
	  	default:
	  		UCA0CTL0 &= ~(0x80);
	  	break;
	  }

	  switch(Stop_bit_Count)
	  {
	  	case 1:
	  		UCA0CTL0 &= ~(0x08);
	  	break;
	  	
	  	case 2:
	  		UCA0CTL0 |= (0x08);
	  	break;
	  	
	  	default:
	  		UCA0CTL0 &= ~(0x08);
	  	break;
	  }
	  UCA0MCTL = UCBRS1 + UCBRS0;          				  // Modulation UCBRSx = 3



// for 12 Mhz uncomment	  
	  if(Modbus_baudrate == 9600)
	  {
	  	UCA0BR0 = ((OSCILLATOR_FREQUENCY/Modbus_baudrate) - 4*256);   // Example, (12MHz/9600)-256 = 160
	  	UCA0BR1 = 0x04;
	  }
	  else if(Modbus_baudrate == 19200)
	  {
	  	UCA0BR0 = ((OSCILLATOR_FREQUENCY/Modbus_baudrate) - 2*256);   // Example, 12MHz/19200 = 208
	  	UCA0BR1 = 0x02;
	  }
	  else if(Modbus_baudrate == 38400)
	  {
	  	UCA0BR0 = ((OSCILLATOR_FREQUENCY/Modbus_baudrate) - 256);   // Example, 12MHz/19200 = 208
	  	UCA0BR1 = 0x01;
	  }
	  
	                        
	  UCA0CTL1 &= ~UCSWRST;                // **Initialize USCI state machine**
	  IE2 |= UCA0RXIE;                     // Enable USCI_A0 RX interrupt
	  
	  __bis_SR_register(GIE);       	   // Enter LPM3, interrupts enabled
}



#pragma vector=USCIAB0RX_VECTOR
__interrupt void USCI0RX_ISR(void)
{		
	if(timeout_flag)
	{
		IE2 &= ~UCA0RXIE;
		return;
	}
			
	if ( UCA0STAT & UCFE )
     {   /* FERR error condition */
     	 chTemp = UCA0RXBUF;
     	 UART_rcv_count = 0;
     	 timeout = 0;
     }
     else if ( UCA0STAT & UCOE )
     {   /* OERR error condition */
     	 chTemp = UCA0RXBUF;
     	 UART_rcv_count = 0;
     	 timeout = 0;
     }
     else
     {
       	UART_RX_buf[UART_rcv_count] = UCA0RXBUF;
    	UART_rcv_count++;
	    timeout = 0;
	    run_timer = 1;	
	    Sending_flag = 1;	    
     }
     
 // _BIS_SR(GIE);
}


//void mSetRS485_RTSHigh ()
//{
//       P1OUT |= 0x04 ;     // P1.2, SIO pin High
//}
//
//void mSetRS485_RTSLow ()
//{
//       P1OUT &= ~(0x04) ;  // P1.2, SIO pin Low
//}


