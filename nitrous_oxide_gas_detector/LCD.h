/*--------------------------------------------------------------------------
* 
* PROJECT:              IR Sensor                                           
*                                                                           
* MODULE TITLE:         LCD Header File    
*                                                                           
* MODULE FILENAME:      LCD.h                                   
*
* MODULE TESTING REF:   
*
* TOOLS DESCRIPTION:
*                       Texas Instruments Code Composer Essentials Version 3.2.2.1.4
*                       Texas Instruments MSP430 USB-Debug-Interface MSP-FET430UIF
*                       
*                                                                            
* MODULE DESCRIPTION:                                                       
* Contains standard types and definitions for LCD.        
*                                                                           
* ISSUE:   DATE:     AUTHOR:   REASON:                                      
* ------   --------  -------   -------                                                            
* v1      19.03.10  N.Singh   Initial                                                                           
*                                                                           
*-------------------------------------------------------------------------*/

#ifndef LCD_H_
#define LCD_H_

extern uint8_t str[35],bcd[7];

void LcdPutS(unsigned char *s) ;
void LcdInit(void);
void LcdSendCmd_4bit(unsigned char cmd);
void LcdSendCmd_8bit(unsigned char cmd);
void LcdPutCh_4bit(unsigned char ch);
void LcdPutCh_8bit(unsigned char ch);
void delay_ms(unsigned int value);
void UpdateLcd(void);
void Send_str(const int8_t *lcd_temp, uint8_t i);

/*************************************************************/
/*****************LCD Output Lines Definition*****************/
/*************************************************************/

#define LCD_PORT_DIR_OUT         P4DIR=0XFF;
#define EN_RS_RW_PORT_DIR_OUT    P5DIR=0XE0;    //P5.7=RS ,P5.6=EN ,P5.5=RW

//#define RW_READ            P5OUT |= 0X20;
//#define RW_WRITE           P5OUT &= 0XDF;
//#define EN_SET             P5OUT |= 0X40;
//#define EN_CLR             P5OUT &= 0XBF;
//#define RS_DATA            P5OUT |= 0X80;
//#define RS_CMD             P5OUT &= 0X7F;


#define RW_READ            P5OUT |= 0x20;
#define RW_WRITE           P5OUT &= 0xC0;
#define EN_SET             P5OUT |= 0x40;
#define EN_CLR             P5OUT &= 0xA0;
#define RS_DATA            P5OUT |= 0x80;
#define RS_CMD             P5OUT &= 0x60;



/*************************************************************/
/*****************LCD Initialization Commands*****************/
/*************************************************************/
#define LcdClr() LcdSendCmd_8bit(Clear_LCD_Display);delay_ms(2)

#define Clear_LCD_Display              0x01
#define Return_LCD_Cursor_Home         0x02
#define Shift_LCD_Cursor_Left          0x04
#define Shift_LCD_Cursor_Right         0x06
#define Shift_LCD_Display_Right        0x05
#define Shift_LCD_Display_Left         0x07
#define LCD_Display_Off_Cursor_Off     0x08
#define LCD_Display_Off_Cursor_On      0x0A
#define LCD_Display_On_Cursor_Off      0x0C
#define LCD_Display_On_Cursor_On       0x0E
#define LCD_Display_On_Cursor_Blinking 0x0F
#define Move_LCD_Cursor_Left           0x10
#define Move_LCD_Cursor_Right          0x14
#define Move_LCD_Display_Left          0x18
#define Move_LCD_Display_Right         0x1C
#define Begin_From_LCD_Line1           0x80
#define Begin_From_LCD_Line2           0xC0
/*************************************************************/
/*****************LCD Display Selection Commands**************/
/*************************************************************/
#define DataBit4_Line1_SmallFont 0x20
#define DataBit4_Line1_BigFont   0x24
#define DataBit4_Line2_SmallFont 0x28
#define DataBit4_Line2_BigFont   0x2C
#define DataBit8_Line1_SmallFont 0x30
#define DataBit8_Line1_BigFont   0x34
#define DataBit8_Line2_SmallFont 0x38
#define DataBit8_Line2_BigFont   0x3C


#endif /*LCD_H_*/
