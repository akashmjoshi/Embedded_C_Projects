#include "system.h"

#pragma vector=USCIAB1RX_VECTOR

__interrupt void USCI1RX_ISR(void)

{

  while (!(IFG2&UCA1TXIFG));                // USCI_A0 TX buffer ready?

  UCA1TXBUF = UCA1RXBUF;                    // TX -> RXed character

}


void Uart_Init()
{
	  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
	  if (CALBC1_1MHZ==0xFF)                                        // If calibration constant erased
	  {                                                                                        
	    while(1);                               // do not load, trap CPU!!        
	  }
	  DCOCTL = 0;                               // Select lowest DCOx and MODx settings
	  BCSCTL1 = CALBC1_1MHZ;                    // Set DCO
	  DCOCTL = CALDCO_1MHZ;
	  P3SEL = 0xf0;                             // P3.4,5 = USCI_A0 TXD/RXD
	  UCA1CTL1 |= UCSSEL_2;                     // SMCLK
	  UCA1BR0 = 6;                              // 1MHz 9600
	  UCA1BR1 = 0;                              // 1MHz 9600
	  UCA1MCTL = UCBRF3 + UCOS16;               // Modln UCBRSx=1, over sampling
	  UCA1CTL1 &= ~UCSWRST;                     // **Initialize USCI state machine**
	  IE2 |= UCA1RXIE;                          // Enable USCI_A0 RX interrupt
}

void tab()
{
	delay_ms(1);
 	while (!(IFG2&UCA1TXIFG));                // USCI_A0 TX buffer ready?
 	UCA1TXBUF = 0x09;
}

void nextline()
{
	delay_ms(1);
	while (!(IFG2&UCA1TXIFG));                // USCI_A0 TX buffer ready?
 	UCA1TXBUF = 0x0A;
 	delay_ms(1);
 	while (!(IFG2&UCA1TXIFG));                // USCI_A0 TX buffer ready?
 	UCA1TXBUF = 0x0D;
}

void Uart_TX()
{
	while (!(IFG2&UCA1TXIFG));                // USCI_A0 TX buffer ready?
 	UCA1TXBUF = 0x46;
 	tab();
 	delay_ms(1);
 	while (!(IFG2&UCA1TXIFG));                // USCI_A0 TX buffer ready?
 	UCA1TXBUF = 0x48;
 	nextline();
 	delay_ms(1);
 	
}


