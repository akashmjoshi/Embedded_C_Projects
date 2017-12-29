#include "system.h"


void Init_Ports(void)
{
/* Port pin definition       PORT TYPE               FUNCTION         INPUT|OUTPUT */
/* ---------------------------------------------------------------------------------------------*/
/* P1.0                  Digital                  REMOTE ACK           Input             */
/* P1.1                  Digital                  REMOTE               Input             */
/* P1.2                  Digital                  SIO-1                Output            */
/* P1.3                  Digital                  LCD Back Light       Output            */
/* P1.4                  Digital                  Realy 3              Output            */
/* P1.5                  Digital                  LED1(AL1)            Output            */
/* P1.6                  Digital                  LED2(AL2)            Output            */
/* P1.7                  Digital                  LED3(HTY)            Output            */
/* ---------------------------------------------------------------------------------------------*/

   P1SEL = 0x00;                           /* Select IO */
   P1DIR = 0xFC;                           /* Set all directions to outputs  IF 1=O/P IF 0=I/P*/ 
   P1OUT = 0x13;                           /* Set start up output statuses */
      
   
   
   
/* Port pin definition       PORT TYPE               FUNCTION         INPUT|OUTPUT */
/* ---------------------------------------------------------------------------------------------*/
/* P2.0                  Digital                  Switch 1            Input             */
/* P2.1                  Digital                  Switch 2            Input             */
/* P2.2                  Digital                  Switch 3            Input             */
/* P2.3                  Digital                  BUZZER              Output            */
/* P2.4                  Digital                  Relay  1            Output            */
/* P2.5                  Digital                  Relay  2            Output            */
/* P2.6                  Digital                  unused              Output            */
/* P2.7                  Digital                  unused              Output            */
/* ---------------------------------------------------------------------------------------------*/      
   
   P2SEL = 0x00;                     /* Select IO */
   P2DIR = 0xF8;                     /* set directions as above */
   //P2OUT = 0x00;                     /* set all outputs to off by default and pull up on input ports*/
   P2OUT = 0x30;                     /* set all outputs to off by default and pull up on input ports*/
   
   
/* Port pin definition  PORT TYPE                 FUNCTION         INPUT|OUTPUT 				*/
/* ---------------------------------------------------------------------------------------------*/
/* P3.0                  Digital                  LED4(prg)            Output 		           	*/
/* P3.1                  Digital                  LED5(cal)            Output            		*/
/* P3.2                  Digital                  LED6(key)            Output            		*/
/* P3.3                  Digital                  LED7(RX)             Output            		*/
/* P3.4                  Digital                  RS485-TXD            Output            		*/
/* P3.5                  Digital                  RS485-RXD            Input             		*/
/* P3.6                  Digital                  TXD            	   Output            		*/
/* P3.7                  Digital                  RXD            	   Input             		*/
/* ---------------------------------------------------------------------------------------------*/           
   
   P3SEL = 0xF0;           /* Select as UART and IO */
   P3DIR = 0x5F;           /* Set directions based on Pin is input or output */
   P3OUT = 0x00;           /* Set start up output status */

/* Port pin definition       PORT TYPE               FUNCTION         INPUT|OUTPUT */
/* ---------------------------------------------------------------------------------------------*/
/* P4.0                  Digital                  LCD Data 0            Output            */
/* P4.1                  Digital                  LCD Data 1            Output            */
/* P4.2                  Digital                  LCD Data 2            Output            */
/* P4.3                  Digital                  LCD Data 3            Output            */
/* P4.4                  Digital                  LCD Data 4            Output            */
/* P4.5                  Digital                  LCD Data 5            Output            */
/* P4.6                  Digital                  LCD Data 6            Output            */
/* P4.7                  Digital                  LCD Data 7            Output            */
/* ---------------------------------------------------------------------------------------------*/   
   
   P4SEL = 0x00;                           /* Select IO  */
   P4DIR = 0xFF;                           /* set all pins to outputs */
   P4OUT = 0x00;                           /* set all outputs to 0 */                     


/* Port pin definition       PORT TYPE               FUNCTION              INPUT|OUTPUT */
/* ---------------------------------------------------------------------------------------------*/
/* P5.0                  Digital                  LED8(TX)                     Output            */
/* P5.1                  Digital                  Eeprom SI(Unused)            Input               */
/* P5.2                  Digital                  Eeprom SO(Unused)            Output               */
/* P5.3                  Digital                  Eeprom SCLK(Unused)          Output               */
/* P5.4                  Digital                  Eeprom CS(Unused)            Output               */
/* P5.5                  Digital                  LCD R/W                      Output            */
/* P5.6                  Digital                  LCD EN                       Output            */
/* P5.7                  Digital                  LCD Rs                       Output            */
/* ---------------------------------------------------------------------------------------------*/   
   
   P5SEL = 0x0E;                     /* Select IO   */
   P5DIR = 0xFF;                     /* set all pins except P5.1 to outputs */
   P5OUT = 0x00;                     /* set all outputs to 0 */   

   
/* Port pin definition       PORT TYPE               FUNCTION         INPUT|OUTPUT */
/* ---------------------------------------------------------------------------------------------*/
/* P6.0                  Analogue                DEW                        Input             */
/* P6.1                  Analogue                PRESSURE                   Input             */
/* P6.2                  Analogue                TEMPERATURE                Input             */
/* P6.3                  Analogue                Unused                     Input             */                
/* P6.4                  Digital                 BUZZER                     Output            */
/* P6.5                  Digital                 SIO-2                      Output            */
/* P6.6                  Digital                 Unused                     Output            */
/* P6.7                  Digital                 Unused                     Output            */
/* ---------------------------------------------------------------------------------------------*/      
  
   P6SEL = 0x00;                           /* Select IO and Analog  */
   P6DIR = 0xFF;                           /* set all pins except P5.1 to outputs */
   P6OUT = 0x00;                           /* set all outputs to 0 */ 
   
                            /* set all outputs to 0 */ 
                                           /* set all outputs to 0 */ 
   
   
}


