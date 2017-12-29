#include "msp430x26x.h"
#include "adc.h"
#include "shift_data.h"
#include "lcd.h"
#include "system.h"
#include "display.h"
#define   Num_of_Results   8

unsigned char regreadads[15];
signed char thm=0; 
unsigned char regwriteads[15],chansel=0x07; 
extern unsigned int chipselect_stat;
unsigned long adc_msg,dpdata;
int j = 0, z=0;
char counts=0;

uint16_t volatile ADCresult = 0;
uint16_t scan_time=999;

uint32_t temp1 = 0;
uint32_t temp  = 0;

signed long  rtdclow[8],rtdchi[8],rtdslope[8],rtdlow[8],rtdhi[8];
signed long  f20clow[8],f20chi[8],f20slope[8],f20low[8],f20hi[8];
signed long  thmclow[8],thmchi[8],thmslope[8],thmlow[8],thmhi[8];


void switching()
{
	firstch_data=0x00ff; secondch_data=0x00ff; thirdch_data=0x00ff; fourthch_data=0x00ff;
	if(channel[0])
	{
		if(c[0]==1 || c[0]==2)
		{firstch_data |= 0x0040; secondch_data &= ~0x0040 <<1; thirdch_data &= ~0x0040;}
		if(c[0]==3)
		{firstch_data &= ~0x0040; secondch_data |= 0x0040; thirdch_data |=  0x0040;}
		if(c[0]==4)
		{firstch_data &= ~0x0040; secondch_data &= ~0x0040; thirdch_data &= ~0x0040;}
		
	}
	else
	{firstch_data &= ~0x0040; secondch_data &= ~0x0040; thirdch_data &= ~0x0040;}
/////////////////////////////////////////////////////////////////////////////////////////////////	
	if(channel[1])
	{
		if(c[1]==1 || c[1]==2)
		{firstch_data |= 0x0020; secondch_data &= ~0x0020; thirdch_data &= ~0x0020;}
		if(c[1]==3)
		{firstch_data &= ~0x0020; secondch_data |=  0x0020; thirdch_data |=  0x0020;}
		if(c[1]==4)
		{firstch_data &= ~0x0020; secondch_data &= ~0x0020; thirdch_data &= ~0x0020;}
		
	}
	else
	{firstch_data &= ~0x0020; secondch_data &= ~0x0020; thirdch_data &= ~0x0020;}
////////////////////////////////////////////////////////////////////////////////////////////////	
	if(channel[2])
	{
		if(c[2]==1 || c[2]==2)
		{firstch_data |= 0x0010; secondch_data &= ~0x0010; thirdch_data &= ~0x0010;}
		if(c[2]==3)
		{firstch_data &= ~0x0010; secondch_data |=  0x0010; thirdch_data |=  0x0010;}
		if(c[2]==4)
		{firstch_data &= ~0x0010; secondch_data &= ~0x0010; thirdch_data &= ~0x0010;}
		
	}
	else
	{firstch_data &= ~0x0010; secondch_data &= ~0x0010; thirdch_data &= ~0x0010;}

////////////////////////////////////////////////////////////////////////////////////////////////	
	if(channel[3])
	{
		if(c[3]==1 || c[3]==2)
		{firstch_data |= 0x0008; secondch_data &= ~0x0008; thirdch_data &= ~0x0008;}
		if(c[3]==3)
		{firstch_data &= ~0x0008; secondch_data |=  0x0008; thirdch_data |=  0x0008;}
		if(c[3]==4)
		{firstch_data &= ~0x0008; secondch_data &= ~0x0008; thirdch_data &= ~0x0008;}
		
	}
	else
	{firstch_data &= ~0x0008; secondch_data &= ~0x0008; thirdch_data &= ~0x0008;}

////////////////////////////////////////////////////////////////////////////////////////////////	
	if(channel[4])
	{
		if(c[4]==1 || c[4]==2)
		{firstch_data |= 0x0004; secondch_data &= ~0x0004; thirdch_data &= ~0x0004;}
		if(c[4]==3)
		{firstch_data &= ~0x0004; secondch_data |=  0x0004; thirdch_data |=  0x0004;}
		if(c[4]==4)
		{firstch_data &= ~0x0004; secondch_data &= ~0x0004; thirdch_data &= ~0x0004;}
		
	}
	else
	{firstch_data &= ~0x0004; secondch_data &= ~0x0004; thirdch_data &= ~0x0004;}
////////////////////////////////////////////////////////////////////////////////////////////////	
	if(channel[5])
	{
		if(c[5]==1 || c[5]==2)
		{firstch_data |= 0x0002; secondch_data &= ~0x0002; thirdch_data &= ~0x0002;}
		if(c[5]==3)
		{firstch_data &= ~0x0002; secondch_data |=  0x0002; thirdch_data |= 0x0002;}
		if(c[5]==4)
		{firstch_data &= ~0x0002; secondch_data &= ~0x0002; thirdch_data &= ~0x0002;}
		
	}
	else
	{firstch_data &= ~0x0002; secondch_data &= ~0x0002; thirdch_data &= ~0x0002;}
////////////////////////////////////////////////////////////////////////////////////////////////	
	if(channel[6])
	{
		if(c[6]==1 || c[6]==2)
		{firstch_data |= 0x0001; secondch_data &= ~0x0001 ; thirdch_data &= ~0x0001;}
		if(c[6]==3)
		{firstch_data &= ~0x0001; secondch_data |=  0x0001 ; thirdch_data |=  0x0001;}
		if(c[6]==4)
		{firstch_data &= ~0x0001; secondch_data &= ~0x0001; thirdch_data &= ~0x0001;}
		
	}
	else
	{firstch_data &= ~0x0001; secondch_data &= ~0x0001; thirdch_data &= ~0x0001;}

////////////////////////////////////////////////////////////////////////////////////////////////	
	if(channel[7])
	{
		if(c[7]==1 || c[7]==2)
		{firstch_data |= 0x0080 ; secondch_data &= ~0x0080; thirdch_data &= ~0x0080;}
		if(c[7]==3)
		{firstch_data &= ~0x0080; secondch_data |=  0x0080; thirdch_data |=  0x0080;}
		if(c[7]==4)
		{firstch_data &= ~0x0080; secondch_data &= ~0x0080; thirdch_data &= ~0x0080;}
		
	}
	else
	{firstch_data &= ~0x0080; secondch_data &= ~0x0080; thirdch_data &= ~0x0080;}
	
channel_sel(firstch_data, secondch_data, thirdch_data, fourthch_data,1);
led_display(firstch_data, secondch_data, thirdch_data, fourthch_data,1);	


}


void ADS1248AssertCS( int fAssert)
{
	
   if (fAssert)
   		P5OUT &= ~(ADS1248_CS); 
   		//delay_ms(5);}  		
   else
	    P5OUT |= (ADS1248_CS);
	    //delay_ms(5);}  
}

int ADS1248SPIInit(void)
{ 
  P5SEL |= ADS1248_SCLK +  ADS1248_DIN + ADS1248_DOUT_DRDY; 

  
 //UCCKPL+
    UCB1CTL0 |= UCMST+UCSYNC+UCMSB;    				/* 3-pin SPI mode, 8-bit comms, MSP430 is Master */
  	UCB1CTL1 |= UCSSEL_2;                     				/* Use SMCLK as clock source */
  	UCB1BR0 = 0x02;                           				/* Set prescaling value for bit clock /2 */
  	UCB1BR1 = 0;                              
// 	UCA0MCTL = 0;                             				/* No modulation */
  	UCB1CTL1 &= ~UCSWRST;	                     			/* **Initialize USCI state machine** */
  	
// _BIS_SR(GIE);
  
  ADS1248AssertCS(0);  
  P2OUT |= ADS1248_START; //Start High
 
 
                         
   return 0;
        
}

void ADS1248INIT()
{
	WDTCTL = WDTPW + WDTHOLD;
   ADS1248SPIInit();
   ADS1248SendResetCommand();
   ADS1248Stop();
   ADS1248ReadRegister();
}

int ADS1248CargaInicial(char chansel)
{
  switch(chansel)
  {
  	case 0:
  	chansel=CH_0;
  	break;
  	
  	case 1:
  	chansel=CH_1;
  	break;
  	
  	case 2:
  	chansel=CH_2;
  	break;
  	
  	case 3:
  	chansel=CH_3;
  	break;
  	
  	case 4:
  	chansel=CH_4;
  	break;
  	
  	case 5:
  	chansel=CH_5;
  	break;
  	
  	case 6:
  	chansel=CH_6;
  	break;
  	
  	case 7:
  	chansel=CH_7;
  	break;
  }
  int i;
  int resultado;
  
   for(i=0;i<15;i++)
   regwriteads[i] = regreadads[i];
  
   regwriteads[ADS1248_MUX0_REGISTER] = chansel;
   regwriteads[ADS1248_VBIAS_REGISTER] = 0x00;
   regwriteads[ADS1248_MUX1_REGISTER] = 0x20;
   regwriteads[ADS1248_SYS0_REGISTER] = 0x00;
  
   ADS1248WriteRegister(ADS1248_MUX0_REGISTER , 4);
   delay_ms(1);
  
   regwriteads[ADS1248_IDAC0_REGISTER] = 0x06;  // set 1mA current source
   regwriteads[ADS1248_IDAC1_REGISTER] = 0x89;  // set 1st current source as iext1 and second as iext2
   ADS1248WriteRegister(ADS1248_IDAC0_REGISTER , 2);
   delay_ms(1);
  
   ADS1248ReadRegister();
   delay_ms(1);  
   resultado = 0;
   
   for(i=0;i<7;i++)
  {
    if (regwriteads[i] != regreadads[i])
      resultado = 1;
  }
     for(i=11;i<15;i++)
  {
     if (regwriteads[i] != regreadads[i])
    resultado = 1;
  }
   
	return resultado;
  
  
}


int ADS1248WriteRegister(int StartAddress, int NumRegs)
{
  int i;
  unsigned char dummy;
  unsigned char reg[15];
  
  for (i=0;i<NumRegs;++i)
  {
    reg[i] = regwriteads[StartAddress + i];
  }
  
  
  ADS1248Stop(); 
  
  ADS1248AssertCS(1); 
  delay_ms(30);
   
//  while(!(  UC1IFG & UCB1TXIFG));
  UCB1TXBUF= ADS1248_CMD_WREG + StartAddress;
  
  while(!(  UC1IFG & UCB1RXIFG));
  dummy=UCB1RXBUF;
//  while(!(  UC1IFG & UCB1TXIFG));
  UCB1TXBUF=NumRegs - 1;
  
  while(!(  UC1IFG & UCB1RXIFG));
  dummy=UCB1RXBUF;
  for (i=0;i<NumRegs;++i)
  {
  //  while(!(  UC1IFG & UCB1TXIFG));
    UCB1TXBUF=reg[i];
    while(!(  UC1IFG & UCB1RXIFG));
    dummy=UCB1RXBUF;
  }

  //delay_ms(5);
                          
  ADS1248AssertCS(0); // CS goes high
  
  return 0;
  

}

void ADS1248ReadRegister()
{
  unsigned char dummy;
  unsigned char reg[15];
  int i;
  
    ADS1248Stop(); 
	delay_ms(5);

    ADS1248AssertCS(0); // CS goes high
 	//delay_ms(20);
    ADS1248AssertCS(1); // CS goes low
	delay_ms(30);

//  while(!(  UC1IFG & UCB1TXIFG));
  UCB1TXBUF=ADS1248_CMD_RREG;	// Command for register read
  while(!(  UC1IFG & UCB1RXIFG));
  dummy=UCB1RXBUF;
  

//  while(!(  UC1IFG & UCB1TXIFG));
  UCB1TXBUF=0x0E;		// Command for number of registers to read
  while(!(  UC1IFG & UCB1RXIFG));
  dummy=UCB1RXBUF;

  for (i=0; i<15; ++i) 
  {
    UCB1TXBUF=0xff;
    while(!(  UC1IFG & UCB1RXIFG));
    reg[i]=UCB1RXBUF;         
  }

   for(i=0;i<15;i++)
    regreadads[i] = reg[i];
  
  ADS1248AssertCS(0); // CS goes high
  
}


long ADS1248ReadData()
{
  unsigned int dummy;
  unsigned int data1, data2, data3;   
  long dato;
  
  // assert CS to start transfer
  ADS1248AssertCS(1); // CS goes low
 // delay_ms(60);

  while(P2IN & ADS1248_DRDY);
  
//  while(!(  UC1IFG & UCB1TXIFG));
  UCB1TXBUF=ADS1248_CMD_RDATA;
  while(!(  UC1IFG & UCB1RXIFG));
  dummy=UCB1RXBUF;
  delay_ms(5);
    
  UCB1TXBUF=0xff;
  while(!(  UC1IFG & UCB1RXIFG));
  data1=UCB1RXBUF; 

  UCB1TXBUF=0xff;
  while(!(  UC1IFG & UCB1RXIFG));
  data2=UCB1RXBUF; //Mid-Byte

  UCB1TXBUF=0xff;
  while(!(  UC1IFG & UCB1RXIFG));
  data3=UCB1RXBUF; //LSB
  
  dato = ((long)data1<<16)+((long)data2<<8)+((long)data3);
  
  ADS1248AssertCS(0); // CS goes high  
  
  return dato;
  
}

int ADS1248SendResetCommand(void)
{

  char dummy;
  
  // assert CS to start transfer
   ADS1248AssertCS(1); // CS goes low

   delay_ms(60);


//  while(!(UC1IFG & UCB1TXIFG));
    UCB1TXBUF= ADS1248_CMD_RESET;
    while(!(UC1IFG & UCB1RXIFG));
    dummy=UCB1RXBUF;

   // de-assert CS
   ADS1248AssertCS(0); // CS goes high
   
  delay_ms(10);
   
   return 0;
}

/* stop collecting data */
void ADS1248Stop(void)
{
      unsigned char dummy;
      
      // Reset SPI
      ADS1248AssertCS(0); // CS goes high
      delay_ms(10);
      ADS1248AssertCS(1); // CS goes low
      delay_ms(60);
      
      // Command to stop taking continous readings
       while(P2IN & ADS1248_DRDY);
      
  //    while(!( UC1IFG & UCB1TXIFG));
              UCB1TXBUF=ADS1248_CMD_SDATAC;
      while(!( UC1IFG & UCB1RXIFG));
              dummy=UCB1RXBUF;
      delay_ms(10);
 
      ADS1248AssertCS(0); // CS goes high
      
}
void crRTD(int i,int cr)
{
	signed char count=0,sign=1;
	signed int u,t,h,th;
	
   		
   		if(cr==0)
   		{
   			Send_str("CALIBRATION MODE", 0);
   			Send_str(" RTD LOW LEVEL  ", 16);
   			Send_str("  APPLY -200 °C ", 32);
   			Send_str("                ", 48);
   			while(checksw()!=1)
   			{
   				rtdclow[i]=ADS1248ReadData();
	   			rtdclow[i] = - 8.9313e-24*rtdclow[i]*rtdclow[i]*rtdclow[i]*rtdclow[i] + 7.7592e-17*rtdclow[i]*rtdclow[i]*rtdclow[i] - 7.9312e-11*rtdclow[i]*rtdclow[i] + 0.0027924*rtdclow[i] - 2532.1;
	   			if(rtdclow[i]>=0)
   				display_val_with_dp(53,rtdclow[i],1,0);
   				else
   				display_negative_with_dp(54,rtdclow[i],1,0);
   				UpdateLcd();
   			}
   			
   			
   			Send_str("CALIBRATION MODE", 0);
   			Send_str(" RTD HIGH LEVEL ", 16);
   			Send_str("  APPLY 400 °C  ", 32);
   			while(checksw()!=1)
   			{
   				rtdchi[i]=ADS1248ReadData();
	   			rtdchi[i] = - 8.9313e-24*rtdchi[i]*rtdchi[i]*rtdchi[i]*rtdchi[i] + 7.7592e-17*rtdchi[i]*rtdchi[i]*rtdchi[i] - 7.9312e-11*rtdchi[i]*rtdchi[i] + 0.0027924*rtdchi[i] - 2532.1;
	   			if(rtdchi[i]>=0)
   				display_val_with_dp(53,rtdchi[i],1,0);
   				else
   				display_negative_with_dp(54,rtdchi[i],1,0);
   				UpdateLcd();
   			}
   			
   			
   			
   		}
   		
   		if(cr==1)
   		{
   			Send_str("  RANGE SETTING ", 0);
   			Send_str(" RTD  LOW RANGE ", 16);
   			Send_str("USE INC/SHFT KEY", 32);
   			Send_str("                ", 48);
   			rtdlow[i]=0;
   			
   			while(checksw()!=1)
   			{
   				if(checksw()==1)
   				break;
   				
   				display(rtdlow[i],54,0,4);
   				UpdateLcd();
   				
   				if(checksw()==3)
   				{
	   				if(count==0)
	   				u++;
	   				else if(count==1)
	   				t++;
	   				else if(count==2)
	   				h++;
	   				else if(count==3)
	   				th++;
	   				else if(count==4 && sign==1)
	   				{
	   					Send_str("-",53);
	   					UpdateLcd();
	   					sign=0;
	   				}
	   				else if(count==4 && sign==0)
	   				{
	   					Send_str("+",53);
	   					UpdateLcd();
	   					sign=1;
	   				}
	   				else if(count==5)
   					count=0;
   				}
   				
   				else if(checksw()==2)
   				count++;
   				
   				rtdlow[i]=((th%10)*1000+(h%10)*100+(t%10)*10+(u%10));
   				
   				
   				if(count<=3)
   				Send_str("_", 57-count);
   				UpdateLcd();
   				if(checksw()==1)
   				break;
   				
   				
   			}
   			
   			
   			Send_str("  RANGE SETTING ", 0);
   			Send_str(" RTD HIGH RANGE ", 16);
   			Send_str("USE INC/SHFT KEY", 32);
   			Send_str("                ", 48);
   			rtdhi[i]=0;
   			
   			while(checksw()!=1)
   			{
   				if(checksw()==1)
   				break;
   				
   				display(rtdhi[i],54,0,4);
   				UpdateLcd();
   				
   				if(checksw()==3)
   				{
	   				if(count==0)
	   				u++;
	   				else if(count==1)
	   				t++;
	   				else if(count==2)
	   				h++;
	   				else if(count==3)
	   				th++;
	   				else if(count==4 && sign==1)
	   				{
	   					Send_str("-",53);
	   					UpdateLcd();
	   					sign=0;
	   				}
	   				else if(count==4 && sign==0)
	   				{
	   					Send_str("+",53);
	   					UpdateLcd();
	   					sign=1;
	   				}
	   				else if(count==5)
   					count=0;
   				}
   				
   				else if(checksw()==2)
   				count++;
   				
   				rtdhi[i]=((th%10)*1000+(h%10)*100+(t%10)*10+(u%10));
   				
   				
   				if(count<=3)
   				Send_str("_", 57-count);
   				UpdateLcd();
   				if(checksw()==1)
   				break;
   				
   				
   			}
   		}
   		   		
	
   	
   	Send_str("                ", 48);
   	UpdateLcd();
	
}

void cr420(int i,int cr)
{
	signed char count=0,sign=1;
	signed int u=0,t=0,h=0,th=0,tth=0;
		
   		
   		if(cr==0)
   		{
   			Send_str("CALIBRATION MODE", 0);
   			Send_str(" 4-20 LOW LEVEL ", 16);
   			Send_str("   APPLY 4 mA   ", 32);
   			Send_str("                ", 48);
   			
   			while(checksw()!=1)
   			{
   				f20clow[i]=0.01004*ADS1248ReadData()+30.859;
   				
   				display_val_with_dp(54,f20clow[i],3,0);
   				UpdateLcd();
   				
   			}
   			
   			
   			Send_str("CALIBRATION MODE", 0);
   			Send_str("4-20 HIGH LEVEL ", 16);
   			Send_str("   APPLY 20mA   ", 32);
   			while(checksw()!=1)
   			{
   				f20chi[i]=0.01004*ADS1248ReadData()+30.859;
   				
   				display_val_with_dp(54,f20chi[i],3,0);
   				UpdateLcd();
   				
   			}
   			
   			
   			
   			
   		}
   		
   		if(cr==1)
   		{
   			Send_str("  RANGE SETTING ", 0);
   			Send_str(" 4-20 LOW RANGE ", 16);
   			Send_str("USE INC/SHFT KEY", 32);
   			Send_str("                ", 48);
   			//f20low[i]=0;
   			
   			while(checksw()!=1)
   			{
   				if(checksw()==1)
   				break;
   				
   				display(f20low[i],54,0,5);
   				UpdateLcd();
   				if(checksw()==1)
   				break;
   				if(count<=5)
   				Send_str("_", 58-count);
   				UpdateLcd();
   				
   				
   				if(checksw()==3 && count==0)
   				u++;
   				else if(checksw()==3 && count==1)
   				t++;
   				else if(checksw()==3 && count==2)
   				h++;
   				else if(checksw()==3 && count==3)
   				th++;
   				else if(checksw()==3 && count==4)
   				tth++;
   				else if(checksw()==3 && count==5 && sign==1)
   				{
   					Send_str("-",53);
   					UpdateLcd();
   					sign=0;
   				}
   				else if(checksw()==3 && count==5 && sign==0)
   				{
   					Send_str("+",53);
   					UpdateLcd();
   					sign=1;
   				}
   				else if(checksw()==2)
   				count++;
   				else if(count==6)
   				count=0;
   				
   				f20low[i]=(tth%10)*10000+(th%10)*1000+(h%10)*100+(t%10)*10+(u%10);
   				if(checksw()==1)
   				break;
   				
   				
   			}
   			
   			
   			Send_str("  RANGE SETTING ", 0);
   			Send_str(" 4-20 HIGH RANGE", 16);
   			Send_str("USE INC/SHFT KEY", 32);
   			Send_str("                ", 48);
   			//f20hi[i]=0;
   			
   			while(checksw()!=1)
   			{
   				if(checksw()==1)
   				break;
   				
   				display(f20hi[i],54,0,5);
   				UpdateLcd();
   				if(checksw()==1)
   				break;
   				if(count<=5)
   				Send_str("_", 58-count);
   				UpdateLcd();
   				
   				
   				if(checksw()==3 && count==0)
   				u++;
   				else if(checksw()==3 && count==1)
   				t++;
   				else if(checksw()==3 && count==2)
   				h++;
   				else if(checksw()==3 && count==3)
   				th++;
   				else if(checksw()==3 && count==4)
   				tth++;
   				else if(checksw()==3 && count==5 && sign==1)
   				{
   					Send_str("-",53);
   					UpdateLcd();
   					sign=0;
   				}
   				else if(checksw()==3 && count==5 && sign==0)
   				{
   					Send_str("+",53);
   					UpdateLcd();
   					sign=1;
   				}
   				else if(checksw()==2)
   				count++;
   				else if(count==6)
   				count=0;
   				f20hi[i]=(tth%10)*10000+(th%10)*1000+(h%10)*100+(t%10)*10+(u%10);
   				if(checksw()==1)
   				break;
   				
   				
   			}
   		}
   		   		
	
	Send_str("                ", 48);
   	UpdateLcd();
	
}

void crthermo(int i,int cr)
{
	signed char count=0,sign=1;
	signed int u=0,t=0,h=0,th=0,tth=0;
	
   		
   		if(cr==0)
   		{
   			Send_str("CALIBRATION MODE", 0);
   			Send_str("THRMO LOW LEVEL ", 16);
   			Send_str(" APPLY 10 degC  ", 32);
   			Send_str("                ", 48);
   			
   			while(checksw()!=1)
   			{
   				thmclow[i]=0.01081*ADS1248ReadData() - 1.952;
   				
   				display_val_with_dp(54,thmclow[i],2,0);
   				UpdateLcd();
   				
   			}
   			
   			
   			Send_str("CALIBRATION MODE", 0);
   			Send_str("THRMO HIGH LEVEL", 16);
   			Send_str(" APPLY MAX degC ", 32);
   			while(checksw()!=1)
   			{
   				thmchi[i]=0.01081*ADS1248ReadData() - 1.952;
   				
   				display_val_with_dp(54,thmchi[i],2,0);
   				UpdateLcd();
   				
   			}
   			
   			
   			
   			
   		}
   		
   		if(cr==1)
   		{
   			Send_str("  RANGE SETTING ", 0);
   			Send_str("    LOW RANGE   ", 16);
   			Send_str("USE INC/SHFT KEY", 32);
   			Send_str("                ", 48);
   			//thmlow[i]=0;
   			
   			while(checksw()!=1)
   			{
   				if(checksw()==1)
   				break;
   				
   				display(thmlow[i],54,0,5);
   				UpdateLcd();
   				if(checksw()==1)
   				break;
   				if(count<=5)
   				Send_str("_", 58-count);
   				UpdateLcd();
   				
   				
   				if(checksw()==3 && count==0)
   				u++;
   				else if(checksw()==3 && count==1)
   				t++;
   				else if(checksw()==3 && count==2)
   				h++;
   				else if(checksw()==3 && count==3)
   				th++;
   				else if(checksw()==3 && count==4)
   				tth++;
   				else if(checksw()==3 && count==5 && sign==1)
   				{
   					Send_str("-",53);
   					UpdateLcd();
   					sign=0;
   				}
   				else if(checksw()==3 && count==5 && sign==0)
   				{
   					Send_str("+",53);
   					UpdateLcd();
   					sign=1;
   				}
   				else if(checksw()==2)
   				count++;
   				else if(count==6)
   				count=0;
   				
   				thmlow[i]=(tth%10)*10000+(th%10)*1000+(h%10)*100+(t%10)*10+(u%10);
   				if(checksw()==1)
   				break;
   				
   				
   			}
   			
   			
   			Send_str("  RANGE SETTING ", 0);
   			Send_str("   HIGH RANGE   ", 16);
   			Send_str("USE INC/SHFT KEY", 32);
   			Send_str("                ", 48);
   			//thmhi[i]=0;
   			
   			while(checksw()!=1)
   			{
   				if(checksw()==1)
   				break;
   				
   				display(thmhi[i],54,0,5);
   				UpdateLcd();
   				if(checksw()==1)
   				break;
   				if(count<=5)
   				Send_str("_", 58-count);
   				UpdateLcd();
   				
   				
   				if(checksw()==3 && count==0)
   				u++;
   				else if(checksw()==3 && count==1)
   				t++;
   				else if(checksw()==3 && count==2)
   				h++;
   				else if(checksw()==3 && count==3)
   				th++;
   				else if(checksw()==3 && count==4)
   				tth++;
   				else if(checksw()==3 && count==5 && sign==1)
   				{
   					Send_str("-",53);
   					UpdateLcd();
   					sign=0;
   				}
   				else if(checksw()==3 && count==5 && sign==0)
   				{
   					Send_str("+",53);
   					UpdateLcd();
   					sign=1;
   				}
   				else if(checksw()==2)
   				count++;
   				else if(count==6)
   				count=0;
   				thmhi[i]=(tth%10)*10000+(th%10)*1000+(h%10)*100+(t%10)*10+(u%10);
   				if(checksw()==1)
   				break;
   				
   				
   			}
   		}
   		   		
	
	Send_str("                ", 48);
   	UpdateLcd();
	
}


void ADC_Setup(void)
{
  WDTCTL = WDTPW+WDTHOLD;                   // Stop watchdog timer
  P6SEL &= 0xFE;                             // Enable A/D channel inputs
  ADC12CTL0 = ADC12ON+MSC+SHT0_8;           // Turn on ADC12, extend sampling time
                                            // to avoid overflow of results
  ADC12CTL1  = SHP+CONSEQ_3; 
  ADC12MCTL0 = INCH_0;                      // ref+=AVcc, channel = A0
  ADC12MCTL1 = INCH_1;                      // ref+=AVcc, channel = A1
  ADC12MCTL2 = INCH_2;                      // ref+=AVcc, channel = A2
  ADC12MCTL3 = INCH_3+EOS;                  // ref+=AVcc, channel = A3, end seq.
 
  ADC12IE = 0x08;                           // Enable ADC12IFG.3
  ADC12CTL0 |= ENC;                         // Enable conversions
  
  ADC12CTL0 |= ADC12SC;                     // Start convn - software trigger
  _BIS_SR(GIE);                 
}

#pragma vector=ADC12_VECTOR
__interrupt void ADC12ISR (void)
{
    ADCresult=0;
    
    for(j=0;j<=199;j++)
    ADCresult+=0.081*ADC12MEM0 - 50;
    
    ADCresult=ADCresult/200;   	
  
    //display_val_with_dp(53,ADCresult,0,0);
   	//UpdateLcd();
   	ADC12IE = 0x00;
    
}

void rtdcurrsel(int i)
{
	switch(i)
	{
		case 0:
		{
			P6OUT &=  ~0x02;
			P6OUT &=  ~0x04;
			P6OUT &=  ~0x08;
			break;
		}
		
		case 1:
		{
			P6OUT |=  0x02;
			P6OUT &=  ~0x04;
			P6OUT &=  ~0x08;
			break;
		}
		
		case 2:
		{
			P6OUT &=  ~0x02;
			P6OUT |=  0x04;
			P6OUT &=  ~0x08;
			break;
		}
		
		case 3:
		{
			P6OUT |=  0x02;
			P6OUT |=  0x04;
			P6OUT &=  ~0x08;
			break;
		}
		
		case 4:
		{
			P6OUT &=  ~0x02;
			P6OUT &=  ~0x04;
			P6OUT |=  0x08;
			break;
		}
		
		case 5:
		{
			P6OUT |=  0x02;
			P6OUT &=  ~0x04;
			P6OUT |=  0x08;
			break;
		}
		
		case 6:
		{
			P6OUT &=  ~0x02;
			P6OUT |=  0x04;
			P6OUT |=  0x08;
			break;
		}
		
		
		case 7:
		{
			P6OUT |=  0x02;
			P6OUT |=  0x04;
			P6OUT |=  0x08;
			break;
		}
	}
}

void dispattern(int i)
{
	switch(dispat)
	{
		case 1:
		{
			Send_str("CH :   ", 0);
			display(i+1,5,0,1);
	    	Send_str("AL1 :           ", 32);
	    	Send_str("AL2 :           ", 48);
	    	
			switch(c[i])
			{
				case 1||2:
				{
					Send_str("4 20 mA", 8);
					if (value[i]>21000 && value[i]<23000)
			   		Send_str("     OVER       ", 16);
			   		else if (value[i]>=3000 && value[i]<3500)
			   		Send_str("     UNDER      ", 16);
			   		else if(value[i]>=23000 || value[i]<3000)
			   		Send_str("     OPEN      ", 16);
			   		else
			   		{
			   			Send_str("                ", 16);
				   		if(value[i]>=0)
				   		display(value[i],22,0,5);
				   		else
				   		display_negative_with_dp(22,value[i],0,0);
				   	}
				   	break;
				}
				
				case 3:
				{
					Send_str("RTD TYP", 8);
					if(value[i]>=10000)
			   		Send_str("     OPEN       ", 16);
			   		else if(value[i]<-2000)
			   		Send_str("     UNDER      ", 16);
			   		else if(value[i]>8500 && value[i]<10000)
			   		Send_str("      OVER      ", 16);
			   		else
			   		{
			   			Send_str("                ", 16);   		
			   			if(value[i]>=0)
			   			display_val_with_dp(22,value[i],1,0);
			   			else
			   			display_negative_with_dp(22,value[i],1,0);
			   		}
			   		break;
				}
				
				case 4:
				{
					switch(thm)
					{
						case 0:
						{
							Send_str("E TYPE ", 8);
							if(value[i]>=14000)
					   		Send_str("     OPEN       ", 16);
					   		else if(value[i]>11000 && value[i]<14000)
					   		Send_str("      OVER      ", 16);
					   		else
							display_val_with_dp(22,value[i],1,0);
							break;
						}
						case 1:
						{
							Send_str("J TYPE ", 8);	
							if(value[i]>=850)
					   		Send_str("     OPEN       ", 16);
					   		else if(value[i]>800 && value[i]<850)
					   		Send_str("      OVER      ", 16);
					   		else
							display_val_with_dp(22,value[i],0,0);
							break;
						}
						case 2:
						{
							Send_str("K TYPE ", 8);
							if(value[i]>=15000)
					   		Send_str("     OPEN       ", 16);
					   		else if(value[i]>13000 && value[i]<15000)
					   		Send_str("      OVER      ", 16);
					   		else
							display_val_with_dp(22,value[i],1,0);
							break;
						}
						case 3:
						{
							Send_str("R TYPE ", 8);
							if(value[i]>=1550)
					   		Send_str("     OPEN       ", 16);
					   		else if(value[i]>1470 && value[i]<1550)
					   		Send_str("      OVER      ", 16);
					   		else
							display_val_with_dp(22,value[i],0,0);
							break;
						}
						case 4:
						{
							Send_str("S TYPE ", 8);
							if(value[i]>=1550)
					   		Send_str("     OPEN       ", 16);
					   		else if(value[i]>1470 && value[i]<1550)
					   		Send_str("      OVER      ", 16);
					   		else
							display_val_with_dp(22,value[i],0,0);
							break;
						}
					}
					break;
				}
			}
			
			UpdateLcd();
			break;
		}
		
		case 2:
		{
			Send_str("CH :   ", 0);
			display(i,5,0,1);
			Send_str("CH :   ", 32);
			display(i+1,37,0,1);
			
			switch(c[i-1])
			{
				case 1||2:
				{
					Send_str("4 20 mA", 8);
					if (value[i-1]>21000 && value[i-1]<23000)
			   		Send_str("     OVER       ", 16);
			   		else if (value[i-1]>=3000 && value[i-1]<3500)
			   		Send_str("     UNDER      ", 16);
			   		else if(value[i-1]>=23000 || value[i-1]<3000)
			   		Send_str("     OPEN      ", 16);
			   		else
			   		{
			   			Send_str("                ", 16);
				   		if(value[i-1]>=0)
				   		display(value[i-1],22,0,5);
				   		else
				   		display_negative_with_dp(22,value[i-1],0,0);
				   	}
				   	break;
				}
				
				case 3:
				{
					Send_str("RTD TYP", 8);
					if(value[i-1]>=10000)
			   		Send_str("     OPEN       ", 16);
			   		else if(value[i-1]<-2000)
			   		Send_str("     UNDER      ", 16);
			   		else if(value[i-1]>8500 && value[i-1]<10000)
			   		Send_str("      OVER      ", 16);
			   		else
			   		{
			   			Send_str("                ", 16);   		
			   			if(value[i-1]>=0)
			   			display_val_with_dp(22,value[i-1],1,0);
			   			else
			   			display_negative_with_dp(22,value[i-1],1,0);
			   		}
			   		break;
				}
				
				case 4:
				{
					switch(thm)
					{
						case 0:
						{
							Send_str("E TYPE ", 8);
							if(value[i-1]>=14000)
					   		Send_str("     OPEN       ", 16);
					   		else if(value[i-1]>11000 && value[i-1]<14000)
					   		Send_str("      OVER      ", 16);
					   		else
					   		{
					   			Send_str("                ", 48);
								display_val_with_dp(22,value[i-1],1,0);
					   		}
							break;
						}
						case 1:
						{
							Send_str("J TYPE ", 8);	
							if(value[i-1]>=850)
					   		Send_str("     OPEN       ", 16);
					   		else if(value[i-1]>800 && value[i-1]<850)
					   		Send_str("      OVER      ", 16);
					   		else
							display_val_with_dp(22,value[i-1],0,0);
							break;
						}
						case 2:
						{
							Send_str("K TYPE ", 8);
							if(value[i-1]>=15000)
					   		Send_str("     OPEN       ", 16);
					   		else if(value[i-1]>13000 && value[i-1]<15000)
					   		Send_str("      OVER      ", 16);
					   		else
							display_val_with_dp(22,value[i-1],1,0);
							break;
						}
						case 3:
						{
							Send_str("R TYPE ", 8);
							if(value[i-1]>=1550)
					   		Send_str("     OPEN       ", 16);
					   		else if(value[i-1]>1470 && value[i-1]<1550)
					   		Send_str("      OVER      ", 16);
					   		else
							display_val_with_dp(22,value[i-1],0,0);
							break;
						}
						case 4:
						{
							Send_str("S TYPE ", 8);
							if(value[i-1]>=1550)
					   		Send_str("     OPEN       ", 16);
					   		else if(value[i-1]>1470 && value[i-1]<1550)
					   		Send_str("      OVER      ", 16);
					   		else
							display_val_with_dp(22,value[i-1],0,0);
							break;
						}
					}
					break;
				}
			}
			
			
			switch(c[i])
			{
				case 1||2:
				{
					Send_str("4 20 mA", 40);
					if (value[i]>21000 && value[i]<23000)
			   		Send_str("     OVER       ", 48);
			   		else if (value[i]>=3000 && value[i]<3500)
			   		Send_str("     UNDER      ", 48);
			   		else if(value[i]>=23000 || value[i]<3000)
			   		Send_str("     OPEN      ", 48);
			   		else
			   		{
			   			Send_str("                ", 48);
				   		if(value[i]>=0)
				   		display(value[i],54,0,5);
				   		else
				   		display_negative_with_dp(54,value[i],0,0);
				   	}
				   	break;
				}
				
				case 3:
				{
					Send_str("RTD TYP", 40);
					if(value[i]>=10000)
			   		Send_str("     OPEN       ", 48);
			   		else if(value[i]<-2000)
			   		Send_str("     UNDER      ", 48);
			   		else if(value[i]>8500 && value[i]<10000)
			   		Send_str("      OVER      ", 48);
			   		else
			   		{
			   			Send_str("                ", 48);   		
			   			if(value[i]>=0)
			   			display_val_with_dp(54,value[i],1,0);
			   			else
			   			display_negative_with_dp(54,value[i],1,0);
			   		}
			   		break;
				}
				
				case 4:
				{
					switch(thm)
					{
						case 0:
						{
							Send_str("E TYPE ", 40);
							if(value[i]>=14000)
					   		Send_str("     OPEN       ", 48);
					   		else if(value[i]>11000 && value[i]<14000)
					   		Send_str("      OVER      ", 48);
					   		else
							display_val_with_dp(54,value[i],1,0);
							break;
						}
						case 1:
						{
							Send_str("J TYPE ", 40);	
							if(value[i]>=850)
					   		Send_str("     OPEN       ", 48);
					   		else if(value[i]>800 && value[i]<850)
					   		Send_str("      OVER      ", 48);
					   		else
							display_val_with_dp(54,value[i],0,0);
							break;
						}
						case 2:
						{
							Send_str("K TYPE ", 40);
							if(value[i]>=15000)
					   		Send_str("     OPEN       ", 48);
					   		else if(value[i]>13000 && value[i]<15000)
					   		Send_str("      OVER      ", 48);
					   		else
							display_val_with_dp(54,value[i],1,0);
							break;
						}
						case 3:
						{
							Send_str("R TYPE ", 40);
							if(value[i]>=1550)
					   		Send_str("     OPEN       ", 48);
					   		else if(value[i]>1470 && value[i]<1550)
					   		Send_str("      OVER      ", 48);
					   		else
							display_val_with_dp(54,value[i],0,0);
							break;
						}
						case 4:
						{
							Send_str("S TYPE ", 40);
							if(value[i]>=1550)
					   		Send_str("     OPEN       ", 48);
					   		else if(value[i]>1470 && value[i]<1550)
					   		Send_str("      OVER      ", 48);
					   		else
							display_val_with_dp(54,value[i],0,0);
							break;
						}
					}
					break;
				}
			}
			
			
			UpdateLcd();
			break;
		}
		
		case 4:
		{
			Send_str("CH :   ", 0);
			display(i-2,5,0,1);
			Send_str("CH :   ", 16);
			display(i-1,21,0,1);
			Send_str("CH :   ", 32);
			display(i,37,0,1);
			Send_str("CH :   ", 48);
			display(i+1,53,0,1);
			
			switch(c[i-3])
			{
				case 1||2:
				{
					
					if (value[i-3]>21000 && value[i-3]<23000)
			   		Send_str("   OVER  ", 7);
			   		else if (value[i-3]>=3000 && value[i-3]<3500)
			   		Send_str("   UNDER ", 7);
			   		else if(value[i-3]>=23000 || value[i-3]<3000)
			   		Send_str("   OPEN  ", 7);
			   		else
			   		{
			   			
				   		if(value[i-3]>=0)
				   		display(value[i-3],7,0,5);
				   		else
				   		display_negative_with_dp(7,value[i-3],0,0);
				   	}
				   	break;
				}
				
				case 3:
				{
					
					if(value[i-3]>=10000)
			   		Send_str("   OPEN  ", 7);
			   		else if(value[i-3]<-2000)
			   		Send_str("  UNDER  ", 7);
			   		else if(value[i-3]>8500 && value[i-3]<10000)
			   		Send_str("   OVER  ", 7);
			   		else
			   		{
			   			  		
			   			if(value[i-3]>=0)
			   			display_val_with_dp(7,value[i-3],1,0);
			   			else
			   			display_negative_with_dp(7,value[i-3],1,0);
			   		}
			   		break;
				}
				
				case 4:
				{
					switch(thm)
					{
						case 0:
						{
							
							if(value[i-3]>=14000)
					   		Send_str("   OPEN  ", 7);
					   		else if(value[i-3]>11000 && value[i-3]<14000)
					   		Send_str("   OVER  ", 7);
					   		else
							display_val_with_dp(7,value[i-3],1,0);
							break;
						}
						case 1:
						{
								
							if(value[i-3]>=850)
					   		Send_str("   OPEN  ", 7);
					   		else if(value[i-3]>800 && value[i-3]<850)
					   		Send_str("   OVER  ", 7);
					   		else
							display_val_with_dp(7,value[i-3],0,0);
							break;
						}
						case 2:
						{
							
							if(value[i-3]>=15000)
					   		Send_str("   OPEN  ", 7);
					   		else if(value[i-3]>13000 && value[i-3]<15000)
					   		Send_str("   OVER  ", 7);
					   		else
							display_val_with_dp(7,value[i-3],1,0);
							break;
						}
						case 3:
						{
							
							if(value[i-3]>=1550)
					   		Send_str("   OPEN  ", 7);
					   		else if(value[i-3]>1470 && value[i-3]<1550)
					   		Send_str("   OVER  ", 7);
					   		else
							display_val_with_dp(7,value[i-3],0,0);
							break;
						}
						case 4:
						{
							
							if(value[i-3]>=1550)
					   		Send_str("   OPEN  ", 7);
					   		else if(value[i-3]>1470 && value[i-3]<1550)
					   		Send_str("   OVER  ", 7);
					   		else
							display_val_with_dp(7,value[i-3],0,0);
							break;
						}
					}
					break;
				}
			}
////////////			
			switch(c[i-2])
			{
				case 1||2:
				{
					
					if (value[i-2]>21000 && value[i-2]<23000)
			   		Send_str("   OVER  ", 23);
			   		else if (value[i-2]>=3000 && value[i-2]<3500)
			   		Send_str("   UNDER ", 23);
			   		else if(value[i-2]>=23000 || value[i-2]<3000)
			   		Send_str("   OPEN  ", 23);
			   		else
			   		{
			   			
				   		if(value[i-2]>=0)
				   		display(value[i-2],23,0,5);
				   		else
				   		display_negative_with_dp(23,value[i-2],0,0);
				   	}
				   	break;
				}
				
				case 3:
				{
					
					if(value[i-2]>=10000)
			   		Send_str("   OPEN  ", 23);
			   		else if(value[i-2]<-2000)
			   		Send_str("  UNDER  ", 23);
			   		else if(value[i-2]>8500 && value[i-2]<10000)
			   		Send_str("   OVER  ", 23);
			   		else
			   		{
			   			  		
			   			if(value[i-2]>=0)
			   			display_val_with_dp(23,value[i-2],1,0);
			   			else
			   			display_negative_with_dp(23,value[i-2],1,0);
			   		}
			   		break;
				}
				
				case 4:
				{
					switch(thm)
					{
						case 0:
						{
							
							if(value[i-2]>=14000)
					   		Send_str("   OPEN  ", 23);
					   		else if(value[i-2]>11000 && value[i-2]<14000)
					   		Send_str("   OVER  ", 23);
					   		else
							display_val_with_dp(23,value[i-2],1,0);
							break;
						}
						case 1:
						{
								
							if(value[i-2]>=850)
					   		Send_str("   OPEN  ", 23);
					   		else if(value[i-2]>800 && value[i-2]<850)
					   		Send_str("   OVER  ", 23);
					   		else
							display_val_with_dp(23,value[i-2],0,0);
							break;
						}
						case 2:
						{
							
							if(value[i-2]>=15000)
					   		Send_str("   OPEN  ", 23);
					   		else if(value[i-2]>13000 && value[i-2]<15000)
					   		Send_str("   OVER  ", 23);
					   		else
							display_val_with_dp(23,value[i-2],1,0);
							break;
						}
						case 3:
						{
							
							if(value[i-2]>=1550)
					   		Send_str("   OPEN  ", 23);
					   		else if(value[i-2]>1470 && value[i-2]<1550)
					   		Send_str("   OVER  ", 23);
					   		else
							display_val_with_dp(23,value[i-2],0,0);
							break;
						}
						case 4:
						{
							
							if(value[i-2]>=1550)
					   		Send_str("   OPEN  ", 23);
					   		else if(value[i-2]>1470 && value[i-2]<1550)
					   		Send_str("   OVER  ", 23);
					   		else
							display_val_with_dp(23,value[i-2],0,0);
							break;
						}
					}
					break;
				}
			}
///////////////

			switch(c[i-1])
			{
				case 1||2:
				{
					
					if (value[i-1]>21000 && value[i-1]<23000)
			   		Send_str("   OVER  ", 39);
			   		else if (value[i-1]>=3000 && value[i-1]<3500)
			   		Send_str("   UNDER ", 39);
			   		else if(value[i-3]>=23000 || value[i-1]<3000)
			   		Send_str("   OPEN  ", 39);
			   		else
			   		{
			   			
				   		if(value[i-1]>=0)
				   		display(value[i-1],39,0,5);
				   		else
				   		display_negative_with_dp(39,value[i-1],0,0);
				   	}
				   	break;
				}
				
				case 3:
				{
					
					if(value[i-1]>=10000)
			   		Send_str("   OPEN  ", 39);
			   		else if(value[i-1]<-2000)
			   		Send_str("  UNDER  ", 39);
			   		else if(value[i-1]>8500 && value[i-1]<10000)
			   		Send_str("   OVER  ", 39);
			   		else
			   		{
			   			  		
			   			if(value[i-1]>=0)
			   			display_val_with_dp(39,value[i-1],1,0);
			   			else
			   			display_negative_with_dp(39,value[i-1],1,0);
			   		}
			   		break;
				}
				
				case 4:
				{
					switch(thm)
					{
						case 0:
						{
							
							if(value[i-1]>=14000)
					   		Send_str("   OPEN  ", 39);
					   		else if(value[i-1]>11000 && value[i-1]<14000)
					   		Send_str("   OVER  ", 39);
					   		else
							display_val_with_dp(39,value[i-1],1,0);
							break;
						}
						case 1:
						{
								
							if(value[i-1]>=850)
					   		Send_str("   OPEN  ", 39);
					   		else if(value[i-1]>800 && value[i-1]<850)
					   		Send_str("   OVER  ", 39);
					   		else
							display_val_with_dp(39,value[i-1],0,0);
							break;
						}
						case 2:
						{
							
							if(value[i-1]>=15000)
					   		Send_str("   OPEN  ", 39);
					   		else if(value[i-1]>13000 && value[i-1]<15000)
					   		Send_str("   OVER  ", 39);
					   		else
							display_val_with_dp(39,value[i-1],1,0);
							break;
						}
						case 3:
						{
							
							if(value[i-1]>=1550)
					   		Send_str("   OPEN  ", 39);
					   		else if(value[i-1]>1470 && value[i-1]<1550)
					   		Send_str("   OVER  ", 39);
					   		else
							display_val_with_dp(39,value[i-1],0,0);
							break;
						}
						case 4:
						{
							
							if(value[i-1]>=1550)
					   		Send_str("   OPEN  ", 39);
					   		else if(value[i-1]>1470 && value[i-1]<1550)
					   		Send_str("   OVER  ", 39);
					   		else
							display_val_with_dp(39,value[i-1],0,0);
							break;
						}
					}
					break;
				}
			}
///////////

			switch(c[i])
			{
				case 1||2:
				{
					
					if (value[i]>21000 && value[i]<23000)
			   		Send_str("   OVER  ", 7);
			   		else if (value[i]>=3000 && value[i]<3500)
			   		Send_str("   UNDER ", 7);
			   		else if(value[i]>=23000 || value[i]<3000)
			   		Send_str("   OPEN  ", 7);
			   		else
			   		{
			   			
				   		if(value[i]>=0)
				   		display(value[i],7,0,5);
				   		else
				   		display_negative_with_dp(7,value[i],0,0);
				   	}
				   	break;
				}
				
				case 3:
				{
					
					if(value[i]>=10000)
			   		Send_str("   OPEN  ", 7);
			   		else if(value[i]<-2000)
			   		Send_str("  UNDER  ", 7);
			   		else if(value[i]>8500 && value[i]<10000)
			   		Send_str("   OVER  ", 7);
			   		else
			   		{
			   			   		
			   			if(value[i]>=0)
			   			display_val_with_dp(7,value[i],1,0);
			   			else
			   			display_negative_with_dp(7,value[i],1,0);
			   		}
			   		break;
				}
				
				case 4:
				{
					switch(thm)
					{
						case 0:
						{
							
							if(value[i]>=14000)
					   		Send_str("   OPEN  ", 7);
					   		else if(value[i]>11000 && value[i]<14000)
					   		Send_str("   OVER  ", 7);
					   		else
							display_val_with_dp(7,value[i],1,0);
							break;
						}
						case 1:
						{
								
							if(value[i]>=850)
					   		Send_str("   OPEN  ", 7);
					   		else if(value[i]>800 && value[i]<850)
					   		Send_str("   OVER  ", 7);
					   		else
							display_val_with_dp(7,value[i],0,0);
							break;
						}
						case 2:
						{
							
							if(value[i]>=15000)
					   		Send_str("   OPEN  ", 7);
					   		else if(value[i]>13000 && value[i]<15000)
					   		Send_str("   OVER  ", 7);
					   		else
							display_val_with_dp(7,value[i],1,0);
							break;
						}
						case 3:
						{
							
							if(value[i]>=1550)
					   		Send_str("   OPEN  ", 7);
					   		else if(value[i]>1470 && value[i]<1550)
					   		Send_str("   OVER  ", 7);
					   		else
							display_val_with_dp(7,value[i],0,0);
							break;
						}
						case 4:
						{
							
							if(value[i]>=1550)
					   		Send_str("   OPEN  ", 7);
					   		else if(value[i]>1470 && value[i]<1550)
					   		Send_str("   OVER  ", 7);
					   		else
							display_val_with_dp(7,value[i],0,0);
							break;
						}
					}
					break;
				}
			}
			
			UpdateLcd();
			break;
		}
	}
}


void adc_reading(int i)
{
	
	signed long data;
	counts++;
	if(i==6)
    {
	    P2SEL &= 0xEF;                     /* Select IO */
	    P2OUT &= 0xef; // Channel 7
  	}
  	else if(i==7)
  	{
  		P2SEL &= 0xEF;                     /* Select IO */
	    P2OUT |= 0x10;	// Channel 8
  	}
	
	
	if(channel[i]==1)
	   {
		   //Send_str("CHANNEL    DATA ", 16);
		   // display(i+1,24,0,2);	
		   
		   	switch(c[i])	
		   	{
			   	case 1 || 2:
			   	{
			   		data=0.01004*ADS1248ReadData()+30.859;
			   		value[i]=(data-f20clow[i])*(f20hi[i]-f20low[i])/(f20chi[i]-f20clow[i])+f20low[i];
			   		
			   		break;			   		  		
			   	}
			   	
			    
			   
			    case 3:
			   	{
			   		rtdcurrsel(i);
			   		data=ADS1248ReadData();
			   		// for -200 to 850
			   		//data= - 1.9334e-30*data*data*data*data*data + 2.2805e-23*data*data*data*data - 8.2574e-17*data*data*data + 2.6786e-10*data*data + 0.0024589*data - 2417.5;
			   		// for -200 to 400
			   		//data= - 1.4249e-29*data*data*data*data*data + 1.065e-22*data*data*data*data - 2.8855e-16*data*data*data + 4.8793e-10*data*data + 0.0023643*data - 2406.6;
			   		// for 0 to 400
			   		data = - 8.9313e-24*data*data*data*data + 7.7592e-17*data*data*data - 7.9312e-11*data*data + 0.0027924*data - 2532.1;
			   		value[i]=(data-rtdclow[i])*4000/(rtdchi[i]-rtdclow[i])-0000;
			   		 
			   		//value[i]=ADS1248ReadData();
			   		//UpdateLcdstr();  		
			   	   	break;	
			   	}
			   	
			   	
			   	case 4:
			   	{
					
			   		thermo:
			   		data=0.01081*ADS1248ReadData() - 1.952;
			   		
			   		if(ambient_flag)
			   		ADCresult=ambient_temp-10;
			   		else 
			   		ADC_Setup();
			   		
			   		
			   		switch (thm)
			   		{   		
						case 0:
				   		{
				   			value[i]=(data-thmclow[i])*9900/(thmchi[i]-thmclow[i])+100+ADCresult*10;
							
				   			if(checksw()==2)
			   				{thm++; goto thermo; }
			   				else 
			   				break;
				   			//UpdateLcdstr();
				   		}
				   		
				   		case 1:
				   		{
				   			value[i]=(data-thmclow[i])*750/(thmchi[i]-thmclow[i])+10+ADCresult;
							
				   			if(checksw()==2)
			   				{thm++; goto thermo; }
			   				else 
			   				break;
				   		}
				   		
				   		case 2:
				   		{
				   			value[i]=(data-thmclow[i])*12600/(thmchi[i]-thmclow[i])+100+ADCresult*10;
							
				   			if(checksw()==2)
			   				{thm++; goto thermo; }
			   				else 
			   				break;
				   		}
				   		
				   		case 3:
				   		{
				   			value[i]=(data-thmclow[i])*1440/(thmchi[i]-thmclow[i])+10+ADCresult;
							
				   			if(checksw()==2)
			   				{thm++; goto thermo; }
			   				else 
			   				break;
				   		}
				   		
				   		case 4:
				   		{
				   			value[i]=(data-thmclow[i])*1440/(thmchi[i]-thmclow[i])+10+ADCresult;
							
				   			if(checksw()==2)
			   				{thm=0; goto thermo; }
			   				else 
			   				break;
				   		}
				   	}
			   	}
			}
			
			
				counts=0;
				switch(dispat)
				{
					case 1:
					{
						dispattern(i);
							
						break;
					}
					
					case 2: 
					{
						if(i==1 || i==3 || i==5 || i==7)
						dispattern(i);
						
						break;
					}
					
					case 4: 
					{
						if(i==3 || i==7)
						dispattern(i);
						
						break;
					}
					
					
				}
				
			
		   	
	   		//if(checksw()==1)
			//Display(2);
	   }
}
 




