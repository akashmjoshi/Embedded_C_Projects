#include "display.h"
#include "shift_data.h"
#include "system.h"



 unsigned int first_led,secnd_led,thrd_led,forth_led,relay_data;
 signed int firstch_data, secondch_data, thirdch_data, fourthch_data;
 unsigned int chipselect_stat;




void relay(unsigned int relay_data)
{
	char i;
	relay_data= ~relay_data;
	
	 for(i=0;i<4;i++)
   {
	   if(relay_data & (0x0001 << i))
	      LED_PORT |= (0x01 << LED_SERIAL_PIN_NO);
	   else
	      LED_PORT &= ~(0x01 << LED_SERIAL_PIN_NO);
	   
	   LED_PORT &= ~(0x01 << LED_SCLK_PIN_NO);
	   LED_PORT |= (0x01 << LED_SCLK_PIN_NO);
   }
led_display(first_led,secnd_led,thrd_led,forth_led, 1);
   
   
}

void channel_sel(unsigned int firstdata,unsigned int seconddata,unsigned int thirddata,unsigned int fourthdata, unsigned int set)
{
   static unsigned int data_merge1 = 0x0000;
   static unsigned int data_merge2 = 0x0000;
   static unsigned int data_merge3 = 0x0000;
   static unsigned int data_merge4 = 0x0000;
   
   unsigned char i = 0;
   
   

   if(set == 1)
   {
      data_merge1 |= fourthdata;
      data_merge2 |= thirddata;
      data_merge3 |= seconddata;
      data_merge4 |= firstdata;
   }
   else
   {
      data_merge1 &= ~fourthdata;
      data_merge2 &= ~thirddata;
      data_merge3 &= ~seconddata;
      data_merge4 &= ~firstdata;
   }
   
     
   for(i=0;i<8;i++)
   {
           if(data_merge4 & (0x0001 << i))
              CH_PORT |= 0x10;
           else
              CH_PORT &= 0xEF;
           
           
           CH_PORT &= ~0x04;
           delay_ms(1);
           CH_PORT |= 0x04;
           
           
   }
                   
   CH_PORT &= ~0x08;
   delay_ms(1);
   CH_PORT |= 0x08;
   
}
