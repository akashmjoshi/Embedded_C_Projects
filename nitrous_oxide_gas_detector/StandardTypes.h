/*
* PROJECT:              IR Sensor                                             
*                                                                           
* MODULE TITLE:         Standard Types       
*                                                                           
* MODULE FILENAME:      StandardTypes.h                                     
*
* MODULE TESTING REF:   
*
* TOOLS DESCRIPTION:
*                       Texas Instruments Code Composer Essentials Version 3.2.2.1.4
*                       Texas Instruments MSP430 USB-Debug-Interface MSP-FET430UIF
*                       
*                                                                            
* MODULE DESCRIPTION:                                                       
* Define Standard Types Definitions and Macros                              
*                                                                           
* ISSUE:   DATE:     AUTHOR:   REASON:                                      
* ------   --------  -------   -------                                      
* v1      18.03.10   N.Singh  -Initial                                                                                                    
*                                                                           
*-------------------------------------------------------------------------*/

#ifndef __STANDARDTYPES_H
#define __STANDARDTYPES_H    
  
/* Definitions and Macros */
#ifndef TRUE
#define TRUE 0x01
#endif
  
#ifndef FALSE
#define FALSE 0x00
#endif   
  
#ifndef ON
#define ON 1u
#endif
  
#ifndef OFF   
#define OFF 0u
#endif

#ifndef LOW
#define LOW 0u
#endif

#ifndef HIGH
#define HIGH 1u
#endif

/* 2 bytes manipulation */
#define _LOBYTE(x) ((uint8_t) 0xffu & ((uint8_t) x))
#define _HIBYTE(x) ((uint8_t)((x) >> 8))
#define SWAP(x)    ((uint16_t)((x) >> 8) | (((x) & 0xff) << 8))

/* Bit manipulation on a single byte */
/* Example:  error_flags_1 = _SETBIT_5(error_flags_1);  will set bit 5 of the variable specified */
#define _SETBIT_0(x) ((uint8_t) 0x01 | (x)) 
#define _SETBIT_1(x) ((uint8_t) 0x02 | (x)) 
#define _SETBIT_2(x) ((uint8_t) 0x04 | (x)) 
#define _SETBIT_3(x) ((uint8_t) 0x08 | (x)) 
#define _SETBIT_4(x) ((uint8_t) 0x10 | (x)) 
#define _SETBIT_5(x) ((uint8_t) 0x20 | (x)) 
#define _SETBIT_6(x) ((uint8_t) 0x40 | (x)) 
#define _SETBIT_7(x) ((uint8_t) 0x80 | (x)) 

#define _CLEARBIT_0(x) ((uint8_t) 0xFE & (x)) 
#define _CLEARBIT_1(x) ((uint8_t) 0xFD & (x)) 
#define _CLEARBIT_2(x) ((uint8_t) 0xFB & (x)) 
#define _CLEARBIT_3(x) ((uint8_t) 0xF7 & (x)) 
#define _CLEARBIT_4(x) ((uint8_t) 0xEF & (x)) 
#define _CLEARBIT_5(x) ((uint8_t) 0xDF & (x)) 
#define _CLEARBIT_6(x) ((uint8_t) 0xBF & (x)) 
#define _CLEARBIT_7(x) ((uint8_t) 0x7F & (x)) 

/* Global Variables */
     
/* Standard Type Definitions */
  typedef unsigned char ubool_t;
  typedef char int8_t;
  typedef unsigned char uint8_t;
  typedef int int16_t;
  typedef unsigned int uint16_t;
 /* typedef short long int24_t;            commented out for MiCS eval kit */      
 /* typedef unsigned short long uint24_t;   commented out for MiCS eval kit */
  typedef long int32_t;
  typedef unsigned long uint32_t;
  typedef float float32_t;
  typedef double float64_t;
  
  
   #define KEY_LED_ON     P2OUT |=  BIT7;    //KEY
  
  #define BACKLIT_ON     P1OUT |= 0x08;
  #define BACKLIT_OFF    P1OUT &= ~0x08;

  #define BUZZER_ON      P6OUT |= BIT4;
  #define BUZZER_OFF     P6OUT &= ~BIT4;
  
  //#define BUZZER2_ON      P2OUT |= BIT3;
  //#define BUZZER2_OFF     P2OUT &= ~BIT3;  
  


#endif
