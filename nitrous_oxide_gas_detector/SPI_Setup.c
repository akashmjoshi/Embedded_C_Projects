#include "system.h"

ubool_t eeprom_action_complete;

uint8_t eeprom_data_size;
uint8_t *eeprom_data_pointer;
uint8_t *eeprom_receive_pointer;
uint8_t data_to_eeprom_buffer[MAX_EEPROM_STRING_SIZE];
uint8_t data_from_eeprom_buffer[MAX_EEPROM_STRING_SIZE];


void setup_spi_port(void)
{                
     P5DIR |= 0x1F;                                        /* Set all pins to outputs */
     P5SEL |= 0x0E;                                        /* P5.2 = Slave Out Master In, P5.1 = Slave in Master Out */
                                                           /* P5.3 = UCB1CLK */ 
     UCB1CTL0 |= UCMST+UCSYNC+UCCKPL+UCMSB;                /* 3-pin SPI mode, 8-bit comms, MSP430 is Master */
     UCB1CTL1 |= UCSSEL_2;                                 /* Use SMCLK as clock source */
     UCB1BR0 = 0x02;                                       /* Set prescaling value for bit clock /2 */
     UCB1BR1 = 0;                              
     UCA0MCTL = 0;                                         /* No modulation */
     UCB1CTL1 &= UCSWRST_OFF;                              /* **Initialize USCI state machine** */
     UC1IE |= UCB1TXIE;                                    /* Enable USCI_A0 RX interrupt */

     P5OUT &= 0xEF;                                        /* Now with SPI signals initialized, */
     P5OUT |= 0x10;                                        /* reset slave */
     P5OUT &= 0xEF;

     /*discard_for_MISRA =*/ _BIS_SR(GIE);                 /* enable interrupts */
}

/*---------------------------------------------------------------------------
* Function name       : interrupt void USCIB1TX_ISR (void)
*     returns         : -
*     arg1            : -
*     arg2            : -
* Created by          : N.Singh & Bala. J
* Date created        : 11/10/10
* Description         : This is the interrupt routine to communicate with
* 						EEPROM.
*---------------------------------------------------------------------------*/
#pragma vector=USCIAB1TX_VECTOR
interrupt void USCIB1TX_ISR (void)
{
   volatile uint8_t i;
   volatile uint8_t eeprom_loop_counter;
   __disable_interrupt();                           /* disable all interrupts so that this routine is not disturbed*/                                        
   while ((UC1IFG & UCB1TXIFG) == 0x00)
   {
      /* Wait until USART1 TX buffer is ready*/
   }   
    P5OUT |= 0x10;                                 	/* reset slave */
    P5OUT &= 0xEF;
   	eeprom_data_pointer = &data_to_eeprom_buffer[0];		/* point to the start of the data to be sent */
   	eeprom_receive_pointer = &data_from_eeprom_buffer[0];	/* point to the start of the data to be received */
   	eeprom_loop_counter = 0;                        /* initialise the loop counter */   
   	while (eeprom_loop_counter <= eeprom_data_size)         /* perform loop until all data is sent */
   	{ 
      UCB1TXBUF = *eeprom_data_pointer;                   	/* Send next value */      
      while ((UC1IFG & UCB1RXIFG) == 0x00)      
      {
      }                                       		/* wait until receive buffer is ready */         
        *eeprom_receive_pointer = UCB1RXBUF;        /* put the received data into the receive array */
        eeprom_data_pointer++;                      /* increment pointers */
        eeprom_receive_pointer++;
        eeprom_loop_counter++;       
        for(i=100;i>0;i--)                          /* Add time between transmissions */       
      {
      }
   	}
    P5OUT |= 0x10;                                  /* set the Chip Select pin high- not communicating with slave */
    for(i=100;i>0;i--)                              /* Add another time so that nothing else can be sent imminently*/
    {
    }    
    UC1IE &= UCB1TXIE_OFF;                          /* disable this interrupt */
    eeprom_action_complete = TRUE;                  /* set flag to show data has been sent and received */
    /*discard_for_MISRA =*/ _BIS_SR(GIE);           /* enable all interrupts now that routine is complete */
    /*discard_for_MISRA =*/ _BIC_SR_IRQ(CPUOFF);
}


