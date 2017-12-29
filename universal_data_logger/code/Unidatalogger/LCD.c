#include "LCD.h"
#include "stdio.h"

char its1[4]={0,0,0,0};
char its2[4]={0,0,0,0};
char its[8]={0,0,0,0,0,0,0,0};
char buffer[16]="   Ambetronics  ";
char programmar[16]="  Akash Joshi   ";
char open[]="Sensor OPEN  ";
char shot[]="Sensor SHORT ";



void LcdInit(void)
{
   WDTCTL = WDTPW + WDTHOLD;     
   P4SEL = 0X00;
  // P5SEL = 0x00;
   
   LCD_PORT_DIR_OUT;
   EN_RS_RW_PORT_DIR_OUT;
   P4OUT=0X00;
   P5OUT=0X00;
      
   delay_ms(15);
   LcdSendCmd_8bit(0x30);
   delay_ms(5);
   LcdSendCmd_8bit(0x30);
   delay_ms(160);
   LcdSendCmd_8bit(0x30);
   delay_ms(160);   
   LcdSendCmd_8bit(0x02);
   delay_ms(12);
   LcdSendCmd_8bit(DataBit8_Line2_SmallFont);
   LcdSendCmd_8bit(LCD_Display_Off_Cursor_On);
   LcdSendCmd_8bit(LCD_Display_On_Cursor_Off);
   LcdSendCmd_8bit(Shift_LCD_Cursor_Right);
   LcdSendCmd_8bit(Begin_From_LCD_Line2);
   
   LcdClr(); 
         
}

void LcdSendCmd_8bit(unsigned char cmd)
{ 
   uint8_t i = 0;  
   RS_CMD;
   RW_WRITE;
   P4OUT=cmd;   
//   delay_ms(1);
   for(i = 50; i>0; i--);  
   EN_SET;
//   delay_ms(1);
   for(i = 50; i>0; i--);  
   EN_CLR;
   
}

void LcdPutCh_8bit(unsigned char ch)
{
   uint8_t i = 0;   
   RS_DATA;
   RW_WRITE;
   P4OUT=ch;   
//   delay_ms(1);
   for(i = 50; i>0; i--);  
   EN_SET;
   for(i = 50; i>0; i--); 
//   delay_ms(1); 
   EN_CLR;   
}

void LcdPutS(unsigned char * s)
{
   while(*s)
      LcdPutCh_8bit(*s++);
   
   return;
}

void LcdSendCmd_4bit(unsigned char cmd)
{  
   unsigned int upper,lower;
   
   upper=cmd & 0xf0;
   lower=cmd << 4;
   
   LcdSendCmd_8bit(upper);
   LcdSendCmd_8bit(lower);   
      
   return;

}


void LcdPutCh_4bit(unsigned char ch)
{
   unsigned int upper,lower;
   
   upper=ch & 0xf0;
   lower=ch << 4;
   
   LcdPutCh_8bit(upper);
   LcdPutCh_8bit(lower);
      
   return;
}


void delay_ms(unsigned int delay)
{
        uint16_t i,j;
        for(i=delay; i>0; i--)
        {
                for(j=125; j>0; j--);
        }
//    while (delay--)
//    {
//        __delay_cycles(1024);  //PUT_CPU_CLOCK_SPEED_IN_HZ_DIVIDED_BY_1000_HERE
//    }
}



void UpdateLcd(void)
{
  unsigned char i;  
  
  LcdSendCmd_8bit(Begin_From_LCD_Line1);     //send first 8 characters of lcd buffer to 1st line 
  for(i = 0;i < 16; i++)
  {
    LcdPutCh_8bit(str[i]);
  }   
   
  LcdSendCmd_8bit(Begin_From_LCD_Line2);     //send second 16 characters of lcd buffer to 2nd line 
  for(i = 16;i < 32; i++)
  {
    LcdPutCh_8bit(str[i]);
  }  
  
  LcdSendCmd_8bit(Begin_From_LCD_Line3);     //send second 16 characters of lcd buffer to 3rd line 
  for(i = 32;i < 48; i++)
  {
    LcdPutCh_8bit(str[i]);
  }  
  
  LcdSendCmd_8bit(Begin_From_LCD_Line4);     //send second 16 characters of lcd buffer to 4th line 
  for(i = 48;i < 64; i++)
  {
    LcdPutCh_8bit(str[i]);
  }     
}



