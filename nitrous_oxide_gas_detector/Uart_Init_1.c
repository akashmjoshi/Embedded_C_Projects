#include "system.h"

unsigned char UART1_RX_buf[100] = {0};   //Receive Buffer
unsigned char UART1_TX_Buf[100] = {0};   //Transmit Buffer
unsigned char UART1_rcv_count = 0;
unsigned char chTemp1;
 
unsigned char timeout1; 
unsigned char run_timer1;
unsigned char volatile timeout_flag1;


unsigned char StartCommCounterFlag;
uint16_t StartCommCounter;


void UARTInit_1(void)
{
	  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
	  P3OUT &= ~(BIT6+BIT7);
	  P3SEL |=  (BIT6+BIT7);                             // P3.4,P3.5 = USCI_A0 TXD/RXD
	 	  
	  P6SEL &= ~BIT5;                             // P6.5 = SIO-2 pin as GPIO
	  P6DIR |=  BIT5;                             // SIO-2 pin P6.5 as output 
	  P6OUT &= ~BIT5;                             // SIO-2 pin P6.5 as 0	  

//	  UCA1BR0 = 226; // 9600 for 12Mhz
//	  UCA1BR1 = 0x04;
//	  UCA1BR0 = 104; // 115200 for 12Mhz
//	  UCA1BR1 = 0x00;
	  
	  UCA1CTL0 = 0x00;
	  UCA1CTL1 |= UCSSEL_1;                     // CLK = ACLK
	  
      switch(Parity_Count)
	  {
	  	case 0:
	  		UCA1CTL0 &= ~(0x80);
	  	break;
	  	
	  	case 1:
	  		UCA1CTL0 |= (0xC0);
	  	break;
	  	
	  	case 2:
	  		UCA1CTL0 |= (0x80);
	  		UCA1CTL0 &= ~(0x40);
	  	break;
	  	
	  	default:
	  		UCA1CTL0 &= ~(0x80);
	  	break;
	  }

	  switch(Stop_bit_Count)
	  {
	  	case 1:
	  		UCA1CTL0 &= ~(0x08);
	  	break;
	  	
	  	case 2:
	  		UCA1CTL0 |= (0x08);
	  	break;
	  	
	  	default:
	  		UCA1CTL0 &= ~(0x08);
	  	break;
	  }	  

	  UCA1MCTL = UCBRS1 + UCBRS0;          		// Modulation UCBRSx = 3	  


     if(Modbus_baudrate == 9600)
	  {
	  	UCA1BR0 = ((OSCILLATOR_FREQUENCY/Modbus_baudrate) - 4*256);   // Example, (12MHz/9600)-256 = 160
	  	UCA1BR1 = 0x04;
	  }
	  else if(Modbus_baudrate == 19200)
	  {
	  	UCA1BR0 = ((OSCILLATOR_FREQUENCY/Modbus_baudrate) - 2*256);   // Example, 12MHz/19200 = 208
	  	UCA1BR1 = 0x02;
	  }
	  else if(Modbus_baudrate == 38400)
	  {
	  	UCA1BR0 = ((OSCILLATOR_FREQUENCY/Modbus_baudrate) - 256);   // Example, 12MHz/19200 = 208
	  	UCA1BR1 = 0x01;
	  }



	  UCA1CTL1 &= ~UCSWRST;                     // **Initialize USCI state machine**
	  UC1IE |= UCA1RXIE; 
	    
	  
	  __bis_SR_register(GIE);       	   // Enter LPM3, interrupts enabled
}






#pragma vector=USCIAB1RX_VECTOR
__interrupt void USCI1RX_ISR(void)
{			
	 if(timeout_flag1)
	 {
	 	return;	 
	 }	 
	 if ( UCA1STAT & UCFE )
     {   /* FERR error condition */
     	 chTemp1 = UCA1RXBUF;
     	 timeout1 = 0;
     	 UART1_rcv_count = 0;
     }
     else if ( UCA1STAT & UCOE )
     {   /* OERR error condition */
     	 chTemp1 = UCA1RXBUF;
     	 timeout1 = 0;
     	 UART1_rcv_count = 0;
     }
     else
     {
     	UART1_RX_buf[UART1_rcv_count++] = UCA1RXBUF;
     	timeout1   = 0;
		run_timer1 = 1;
     }
}



