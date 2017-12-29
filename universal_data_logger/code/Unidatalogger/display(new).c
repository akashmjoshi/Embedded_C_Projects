#include "msp430x26x.h"
#include "Standard_Types.h"
#include "LCD.h"
#include "math.h"
#include "system.h"
#include "display.h"

void Send_str(int8_t *lcd_temp, uint8_t i);
void channel_select();

int checksw();
int k;
int8_t str[70], bcd[7];
uint8_t OneTimeLedOn = 0;
uint8_t message=0; 
uint8_t message_cntr=0;
uint8_t mode_flags = 0;
uint8_t mode_flags_1 = 0;
uint8_t exit_flags = 0;
uint8_t exit_flags_1 = 0;
uint8_t mode_flags_1_temp = 0;
uint8_t exit_flags_factory = 0;
uint8_t indication_flags  = 0x28;
uint8_t indication_flags_2 = 0x00;
uint8_t indication_flags_3 = 0x00;
uint8_t cal_para=0;
uint8_t menu_timeout=100;
uint8_t counter = 1 ;
uint8_t pos_cntr=0;
uint8_t memory_used=0;
uint8_t NegativeFlag = 0;
uint8_t display_flag = 0;
uint8_t StartDownloadFlag = 0;
uint8_t rtcHexValue = 0;
signed char unit[8]={0,0,0,0,0,0,0,0}; 
char dispat=1;
char ambient_temp=0,ambient_flag=0;


uint16_t warm_time1 = 1;
uint16_t warm_time_set = 10;
uint16_t password=0;
uint16_t new_password=0;

uint32_t relay_flags = 0;
uint32_t StartAddrs = 0;
uint32_t StopAddrs = 0;
char channel[8]={1,1,1,1,1,1,1,1};
char alldisable=0;
char c[8];
extern char active;

extern uint8_t ConfigureParameterFlag;
extern uint8_t log_sec;
extern uint8_t log_hour;
extern uint8_t log_min ;
char DeviceId=1;						//Default Device ID
extern uint8_t SelectDownloadOption;
extern uint8_t stop_log;
extern uint8_t set_start_log_flag;
extern uint8_t backlit_select;
extern uint8_t pos_cntr1;
extern uint8_t pos_cntr2;
extern uint8_t pos_cntr3;
extern uint8_t log_interval_time;
extern uint8_t log_interval_unit;
extern uint8_t log_trigger;
extern uint8_t log_trigger_start_year;
extern uint8_t log_trigger_start_month;
extern uint8_t log_trigger_start_date;
extern uint8_t log_trigger_start_hour;
extern uint8_t log_trigger_start_min;
extern uint8_t log_trigger_stop_year;
extern uint8_t log_trigger_stop_month;
extern uint8_t log_trigger_stop_date;
extern uint8_t log_trigger_stop_hour;
extern uint8_t log_trigger_stop_min;
extern uint16_t log_key_press_delay;
extern uint8_t backlit_timer;

char relay_set[4];
char relay_logic[4];
char relay_delay[4];

uint8_t Modbus_parity=0;
uint8_t Modbus_stopbits=0;
extern uint8_t count;
signed char channel_no=0;
extern uint8_t active_channel[17];
extern uint8_t change_page_flag ;
extern uint8_t UART_TX_Buffer[20];
extern uint8_t ChannelSent;
extern uint8_t sec_ctr,min_ctr, Seconds;
extern uint8_t Slave_monitor_ID[5];
extern uint8_t exit_slave_monitor_flag;
extern uint8_t exit_slave_monitor ;
extern uint8_t exit_monitor;
extern uint8_t Slave_monitor_ID[5];
extern uint8_t use_slave_monitor_flag;
extern uint8_t use_slave_monitor;

extern uint8_t SerialYear;
extern uint8_t SerialMonth;
extern unsigned int ProcessValueId;
extern unsigned int BatchId;
extern uint16_t SerialNumber;
extern uint16_t code;
extern uint16_t auto_mode_time ;
extern uint16_t comm_fail_relay_time;
extern uint16_t modbus_use_channel_flag  ;
extern uint16_t modbus_channel_exit_flag ;
extern uint16_t display_menu_exit_flag;
extern uint16_t over_error_flags;
extern uint16_t open_error_flags;
extern uint16_t under_error_flags;
extern uint16_t temp_use_channel_flag;
extern uint16_t exit_modbus;
extern uint16_t exit_display;
extern uint16_t alarm_channel_exit_flag;
extern uint16_t Channel_Database[16][5];
extern uint16_t QueryCounter[16];
extern uint16_t scan_time;

extern uint32_t MaxLogCount;
long Modbus_baudrate=19200;			//Default baud rate
extern uint32_t use_alarm_flag;
extern uint32_t logic_flag;
extern uint32_t latch_flag;
extern uint32_t use_alarm1;
extern uint32_t use_alarm2;
extern uint32_t alarm1_low;
extern uint32_t alarm2_low ;
extern uint32_t alarm1_latch;
extern uint32_t alarm2_latch ;
extern uint32_t exit_alarm ;
extern uint32_t log_count;
extern uint32_t DownloadDataLowerLimit;
extern uint32_t DownloadDataUpperLimit;

extern AlarmParameters	 Alarm_Channels[16];
extern ModbusParameters  Modbus_Channels[16];
extern DisplayParameters Display_Channels[16];
extern NameParameters Name_List;
/*---------------------------------------------------------------------------
* Function name       : void Display(void)
*     returns         : -
*     arg1            : -
*     arg2            : -
* Created by          : Nitin Singh
* Date created        : 20/01/11
* Description         : This function checks the menu and parameters and calls
*                       functions to update strings and numbers.
*---------------------------------------------------------------------------*/
void Display(int menu)
{
	
    int i=0;
    begin:
	switch (menu)
	{
		case 1:
		{
			   
				Send_str("                ", 0);
				Send_str("                ", 16);
				Send_str("                ", 32);
				Send_str("                ", 48);
			    	  
		  		Send_str("  Ambetronics  ", 0);       		 
		    	Send_str("   Engineers   ", 16);
		    	Send_str("    Pvt Ltd    ", 32);				 
		    	Send_str(" Mumbai , India", 48);
		    	
		    	UpdateLcd();
		    	delay_ms(2000);
		    			
				Send_str("     UDL-800    ", 0);
		    	Send_str("  UniDataLogger ", 16);
		    	Send_str("     8 CHNL     ", 32);
		    	Send_str("  VERSION V1.0  ", 48);   
		    	
		    	UpdateLcd();
		    	delay_ms(1000);
		    	
		    	for(i=5; i>=0; i--)
		    	{
		    		
		    		delay_ms(900);
			    	Send_str("PLEASE WAIT TILL", 0);
			    	Send_str("  WARM UP TIME  ", 16);
			    	Send_str("    00:00:05    ", 32);
			    	Send_str("    00:00:      ", 48);
			    	display(i,58,0,2);
			    	UpdateLcd();
			    	
		    	}
		    	break;
		}	    	
		
////////////////////////////////////////////////////////////////////////

		case 2:
		{
			char flag=0,count=0,rtc_date=0,rtc_month=0,rtc_year=0,rtc_hour=0,rtc_min=0,rtc_sec=0;
 			
			Send_str("    MAIN MENU   ", 0);
			Send_str("   RTC SETTING  ", 16);
			Send_str("    PARAMETER   ", 32);
			Send_str("  PRESS INC KEY ", 48);
			UpdateLcd();
			delay_ms(500);
			
			while(checksw()!=3)
			{
				if(checksw()==1)
				{
					menu++;
					goto begin;
				}
					
			}
			
			while(checksw()!=1)
			{
				read_RTC();
				Send_str("TIME:     :  :  ", 0);
				Send_str("                ", 16);
				Send_str("DATE:     /  /  ", 32);
				Send_str("                ", 48);
				display(Seconds,14,0,2);
				display(Minutes,11,0,2);
				display(Hours,8,0,2);
				display(Date,40,0,2);
				display(Month,43,0,2);
				display(Year,46,0,2);
				UpdateLcd();
			}
			
			
			
			
			rtc:
			Send_str(" RTC PARAMETER  ", 0);
			Send_str("                ", 16);
			Send_str("   TO CONTINUE  ", 32);
			Send_str("PRSS SET/NXT KEY", 48);
			UpdateLcd();
			
			while(checksw()!=1);
			
			Send_str("DATE/ MNTH/ YEAR", 16);
			Send_str("USE INC & SHIFT ", 32);
			Send_str("                ", 48);
			while(checksw()!=1)
			{
				if(checksw()==1)
   				break;
   				
   				if(checksw()==3 && count==0)
   				{rtc_date++; if(rtc_date==32) rtc_date=0;}
   				else if(checksw()==3 && count==1)
   				{rtc_month++; if(rtc_month==13) rtc_month=1;}
   				else if(checksw()==3 && count==2)
   				{rtc_year++; if(rtc_year==100) rtc_year=0;}
   				else if(checksw()==2)
   				count++;
   				
   				
   				display(rtc_date,52,1,2);
   				Send_str("/",54);
   				display(rtc_month,55,1,2);
   				Send_str("/",57);
   				display(rtc_year,58,1,2);
   				
   				UpdateLcd(); 
   				
   				if(count==3)
   				count=0; 				
 				
			}
			
			count=0;
			Send_str("HOUR :MINS :SEC ", 16);
			Send_str("USE INC & SHIFT ", 32);
			Send_str("                ", 48);
			
			while(checksw()!=1)
			{
				if(checksw()==1)
   				break;
   				
   				if(checksw()==3 && count==0)
   				{rtc_sec++; if(rtc_sec==60) rtc_sec=0;}
   				else if(checksw()==3 && count==1)
   				{rtc_min++; if(rtc_min==60) rtc_min=0;}
   				else if(checksw()==3 && count==2)
   				{rtc_hour++; if(rtc_hour==24) rtc_hour=0;}
   				else if(checksw()==2)
   				count++;
   				
   				
   				display(rtc_hour,52,0,2);
   				Send_str(":",54);
   				display(rtc_min,55,0,2);
   				Send_str(":",57);
   				display(rtc_sec,58,0,2);
   				
   				UpdateLcd(); 
   				
   				if(count==3)
   				count=0; 				
 				
			}
			
				Send_str("  RTC PARAMETER ", 0);
				Send_str("   UPDATE RTC   ", 16);
				Send_str("       NO       ", 32);
				Send_str("USE INC & SHIFT ", 48);
				UpdateLcd();
				
				flag=0;
				
			while(checksw()!=1)
			{	
				if(checksw()==3)
				{Send_str("       YES      ", 32); flag=1; UpdateLcd();}
				
				if(checksw()==2)
				{Send_str("       NO       ", 32); flag=0; UpdateLcd();}
				
			}
			
			if(flag)
			{
				TI_USCI_I2C_transmitinit(0x68,12); // initialize USCI
				while ( TI_USCI_I2C_notready() ); // wait for bus to be free
				rtcHexValue = DecimalToHex(rtc_sec);
				write_RTC(SEC_REG_ADDRS, (rtcHexValue & 0x7F));
				rtcHexValue = DecimalToHex(rtc_min);
				write_RTC(MIN_REG_ADDRS, (rtcHexValue & 0x7F));
				rtcHexValue = DecimalToHex(rtc_hour);
				write_RTC(HOUR_REG_ADDRS, (rtcHexValue & 0x3F));
				rtcHexValue = DecimalToHex(rtc_date);
				write_RTC(DATE_REG_ADDRS, (rtcHexValue & 0x3F));
				rtcHexValue = DecimalToHex(rtc_month);
				write_RTC(MONTH_REG_ADDRS,(rtcHexValue & 0x1F));
				rtcHexValue = DecimalToHex(rtc_year);
				write_RTC(YEAR_REG_ADDRS, rtcHexValue);
				
			}
			
			Send_str("   RTC SETTING  ", 0);
			Send_str("    EXIT MENU   ", 16);
			Send_str("       NO       ", 32);
			Send_str("USE INC & SHIFT ", 48);
			UpdateLcd();
			exit_flags=1;
			
			while(checksw()!=1)
			{
				if(checksw()==3)
				{
					Send_str("       YES      ", 32);
					UpdateLcd();
					exit_flags=0;
				}
				else if(checksw()==2)
				{
					Send_str("       NO       ", 32);
					UpdateLcd();
					exit_flags=1;
				}
			}
			
			if(exit_flags)
			goto rtc;
			else
			goto begin;
			
		}	
	    	
////////////////////////////////////////////////////////////////////////

		case 3:
		{
		    	
			Send_str("    MAIN MENU   ", 0);
			Send_str("ENABL/DISBL MODE", 16);
			Send_str("    PARAMETER   ", 32);
			Send_str("  PRESS INC KEY ", 48);
			UpdateLcd();
			
			while(checksw()!=3)
			{
				if(checksw()==1)
				{
					menu++;
					goto begin;
				}
				
			}
			
			edm:
			Send_str("ENABL/DISBL MODE", 0);
			Send_str("                ", 16);
			Send_str("   TO CONTINUE  ", 32);
			Send_str("PRSS SET/NXT KEY", 48);
			UpdateLcd();
			while(checksw()!=1);
			
			Send_str("ENABLE ALL CHNLS", 0);
			Send_str("                ", 16);
			Send_str("PRSS SET/NXT KEY", 32);
			Send_str(" OR PRSS INC KEY", 48);
			UpdateLcd();
			
			while(checksw()!=1 || checksw()!=3)
			{
				if(checksw()==1)
				{
					channel[0]=1;
					channel[1]=1;
					channel[2]=1;
					channel[3]=1;
					channel[4]=1;
					channel[5]=1;
					channel[6]=1;
					channel[7]=1;
					
					goto edx;
				}
				else if(checksw()==3)
				break;
			}
			
			for(k=0; k<=7; k++)
			{
					Send_str("ENABL/DISBL MODE", 0);
					Send_str("  CHANNEL :     ", 16);
					Send_str("     ENABLE     ", 32);
					Send_str("USE INC & SHIFT ", 48);
					display(k+1,29,0,1);
					UpdateLcd();
					channel[k]=1;
					
					while(checksw()!=1)
					{
						if(checksw()== 2)
						{
							Send_str("     DISABLE    ", 32);
							UpdateLcd();						
							channel[k]=0;
							alldisable++;
						}
						
						if(checksw()== 3)
						{
							Send_str("     ENABLE    ", 32);
							UpdateLcd();						
							channel[k]=1;
						}
						
						if(checksw()== 1)
						goto c1o;
						
					}
					c1o:
					delay_ms(100);
			}
			
			if(alldisable==8)
			{
				channel[0]=1;
				alldisable=0;
			}
			
			edx:
			Send_str("ENABL/DISBL MODE", 0);
			Send_str("    EXIT MENU   ", 16);
			Send_str("       NO      ", 32);
			Send_str("USE INC & SHIFT ", 48);
			UpdateLcd();
			exit_flags=1;
			
			while(checksw()!=1)
			{
				if(checksw()==3)
				{
					Send_str("       YES      ", 32);
					UpdateLcd();
					exit_flags=0;
				}
				else if(checksw()==2)
				{
					Send_str("       NO       ", 32);
					UpdateLcd();
					exit_flags=1;
				}
			}
			
			if(exit_flags)
			goto edm;
			else
			goto begin;	
				
		}
////////////////////////////////////////////////////////////////////////
		
		case 4:
		{
	
		    	Send_str("    MAIN MENU   ", 0);
				Send_str("   INPUT TYPE   ", 16);
				Send_str("    PARAMETER   ", 32);
				Send_str("  PRESS INC KEY ", 48);
				UpdateLcd();	
				while(checksw()!= 3)
				{
					if(checksw()==1)
					{
						menu++;
						goto begin;
					}
					
				}
				
				ip:
				Send_str("INPUT PARAMETER ", 0);
				Send_str("                ", 16);
				Send_str("  TO CONTINUE   ", 32);
				Send_str("PRSS SET/NXT KEY", 48);
				UpdateLcd();	
				while(checksw()!= 1);
				delay_ms(20);
				
				channel_no=0;
				Send_str("INPUT PARAMETER ", 0);
				channel_select();
				i=channel_no;
					
				
				{
					if (channel[i]==1)
					{
						
						c1a:
						Send_str(" CHANNEL    SET ", 0);
						Send_str("   INPUT TYPE   ", 16);
						Send_str("   4 TO 20 mA   ", 32);
						Send_str("  PRESS INC KEY ", 48);
						display(i+1,10,0,1);
						UpdateLcd();
						delay_ms(100);
						c[i]=1;								// 4to20 selcted
										
						while(checksw()!=1)
						{
							if(checksw()== 1)
							goto c1s;
							//delay_ms(10);
							if(checksw()== 3)
							{
								Send_str("   0 TO 1 VOLT  ", 32);
								UpdateLcd();
								c[i]=2;
								while(checksw()!=1)
								{
									if(checksw()== 1)
									goto c1s;
									//delay_ms(10);
									if(checksw()== 3)
									{
										Send_str("  RTD : PT 100  ", 32);
										UpdateLcd();
										c[i]=3;
										while(checksw()!=1)
										{
											if(checksw()== 1)
											goto c1s;
											//delay_ms(10);
											if(checksw()== 3)
											{
												Send_str("  THERMOCOUPLE  ", 32);
												UpdateLcd();
												c[i]=4;
												while(checksw()!=1)
												{
													if(checksw()== 1)
													goto c1s;
													//delay_ms(10);
													else if(checksw()== 3)
													goto c1a;
												}
												goto c1s;
											}
										}
										goto c1s;
									}
								}
								goto c1s;
							}
						}
						goto c1s;
					}
					else 
					goto c1s;
				c1s:
				}
			switching();
			
			
			Send_str("ALL CHANNELS ARE", 0);
			Send_str("   CONFIGURED   ", 16);
			Send_str("                ", 32);
			Send_str("                ", 48);
			UpdateLcd();				
			delay_ms(1000);
			
			Send_str("   INPUT TYPE   ", 0);
			Send_str("    EXIT MENU   ", 16);
			Send_str("       NO       ", 32);
			Send_str("USE INC & SHIFT ", 48);
			UpdateLcd();
			exit_flags=1;
			
			while(checksw()!=1)
			{
				if(checksw()==3)
				{
					Send_str("       YES      ", 32);
					UpdateLcd();
					exit_flags=0;
				}
				else if(checksw()==2)
				{
					Send_str("       NO       ", 32);
					UpdateLcd();
					exit_flags=1;
				}
			}
			
			if(exit_flags)
			goto ip;
			else
			goto begin;	
		}
		
////////////////////////////////////////////////////////////////////////
		case 5:
		{
			Send_str("    MAIN MENU   ", 0);
			Send_str("DISPLAY SETTINGS", 16);
			Send_str("    PARAMETER   ", 32);
			Send_str("  PRESS INC KEY ", 48);
			UpdateLcd();	
			while(checksw()!= 3)
			{
				if(checksw()==1)
				{
					menu++;
					goto begin;
				}
				
			}
			
			ds:
			Send_str("DISPLAY SETTINGS", 0);
			Send_str("                ", 16);
			Send_str("  TO CONTINUE   ", 32);
			Send_str("PRSS SET/NXT KEY", 48);
			UpdateLcd();	
			while(checksw()!= 1);
			
			dispat=1;
			Send_str("DISPLAY SETTINGS", 0);
			Send_str("SET DISPLAY TYPE", 16);
			Send_str("      : CHANNEL ", 32);
			Send_str("USE INC & SHIFT ", 48);
			display(dispat,36,0,1);
			UpdateLcd();	
			
			
			while(checksw()!= 1)
			{
				if(checksw()==3)
				{
					dispat+=dispat;
					
					if(dispat>4)
					dispat=1;
					
					display(dispat,36,0,1);
					UpdateLcd();
					
				}
			}
			
			
			Send_str("DISPLAY SETTINGS", 0);
			Send_str("    EXIT MENU   ", 16);
			Send_str("       NO       ", 32);
			Send_str("USE INC & SHIFT ", 48);
			UpdateLcd();
			exit_flags=1;
			
			while(checksw()!=1)
			{
				if(checksw()==3)
				{
					Send_str("       YES      ", 32);
					UpdateLcd();
					exit_flags=0;
				}
				else if(checksw()==2)
				{
					Send_str("       NO       ", 32);
					UpdateLcd();
					exit_flags=1;
				}
			}
			
			if(exit_flags)
			goto ds;
			else
			goto begin;
			
		}

////////////////////////////////////////////////////////////////////////
		
		case 6:
		{
			i=active;
			Send_str("    MAIN MENU   ", 0);
			Send_str("  UNIT SETTINGS ", 16);
			Send_str("    PARAMETER   ", 32);
			Send_str("  PRESS INC KEY ", 48);
			UpdateLcd();	
			while(checksw()!= 3)
			{
				if(checksw()==1)
				{
					menu++;
					goto begin;
				}
				
			}
			
			us:
			Send_str("  UNIT SETTINGS ", 0);
			Send_str("                ", 16);
			Send_str("  TO CONTINUE   ", 32);
			Send_str("PRSS SET/NXT KEY", 48);
			UpdateLcd();	
			while(checksw()!= 1);
			
			channel_no=0;
			Send_str("  UNIT SETTINGS ", 0);
			channel_select();
			i=channel_no;
		
			Send_str("  UNIT SETTINGS ", 0);
			Send_str("CHANNEL NO:     ", 16);
			Send_str("                ", 32);
			Send_str("USE INC & SHIFT ", 48);
			display(i+1,28,0,1);
			
			Send_str("%LEL",37);
			unit[i]=0;
			
			UpdateLcd();
			
			while(checksw()!=1)
			{
				if(checksw()==3)
				{
					unit[i]++;
					Display_units(unit[i],37);
					UpdateLcd();
					if(unit[i]>29)
					unit[i]=0;
				}
				else if(checksw()==2)
				{
					unit[i]--;
					Display_units(unit[i],37);
					UpdateLcd();
					if(unit[i]<0)
					unit[i]=29;
				}
				
			}
			
			
			Send_str("  UNIT SETTINGS ", 0);
			Send_str("    EXIT MENU   ", 16);
			Send_str("       NO       ", 32);
			Send_str("USE INC & SHIFT ", 48);
			UpdateLcd();
			exit_flags=1;
			
			while(checksw()!=1)
			{
				if(checksw()==3)
				{
					Send_str("       YES      ", 32);
					UpdateLcd();
					exit_flags=0;
				}
				else if(checksw()==2)
				{
					Send_str("       NO       ", 32);
					UpdateLcd();
					exit_flags=1;
				}
			}
			
			if(exit_flags)
			goto us;
			else
			goto begin;
			
			
			
		}

////////////////////////////////////////////////////////////////////////

		case 7:
		{
			Send_str("    MAIN MENU   ", 0);
			Send_str("  RANGE SETTING ", 16);
			Send_str("    PARAMETER   ", 32);
			Send_str("  PRESS INC KEY ", 48);
			UpdateLcd();	
			while(checksw()!= 3)
			{
				if(checksw()==1)
				{
					menu++;
					goto begin;
				}
				
			}	
			
			ran:
			Send_str(" RANGE SETTING  ", 0);
			Send_str("                ", 16);
			Send_str("  TO CONTINUE   ", 32);
			Send_str("PRSS SET/NXT KEY", 48);
			UpdateLcd();	
			while(checksw()!= 1);
			
			channel_no=0;
			Send_str(" RANGE SETTING  ", 0);
			channel_select();
			
			Send_str(" RANGE SETTING  ", 0);
			Send_str(" CHANNEL NO:    ", 16);
			Send_str("                ", 32);
			Send_str("  PRESS INC KEY ", 48);
			display(channel_no+1,29,0,1);
			UpdateLcd();
			while(checksw()!= 3);
			
			switch(c[channel_no])
			{
				case 1 || 2:
				{
					cr420(channel_no,1);
					break;
				}
				case 3:
				{
					crRTD(channel_no,1);
					break;
				}
				case 4:
				{
					crthermo(channel_no,1);
					break;
				}
			}
			
			Send_str("  RANGE SETTING ", 0);
			Send_str("    EXIT MENU   ", 16);
			Send_str("       NO       ", 32);
			Send_str("USE INC & SHIFT ", 48);
			UpdateLcd();
			exit_flags=1;
			
			while(checksw()!=1)
			{
				if(checksw()==3)
				{
					Send_str("       YES      ", 32);
					UpdateLcd();
					exit_flags=0;
				}
				else if(checksw()==2)
				{
					Send_str("       NO       ", 32);
					UpdateLcd();
					exit_flags=1;
				}
			}
			
			if(exit_flags)
			goto ran;
			else
			goto begin;
		}		
////////////////////////////////////////////////////////////////////////

		case 8:
		{
			Send_str("    MAIN MENU   ", 0);
			Send_str("   CALIBRATION  ", 16);
			Send_str("    PARAMETER   ", 32);
			Send_str("  PRESS INC KEY ", 48);
			UpdateLcd();	
			while(checksw()!= 3)
			{
				if(checksw()==1)
				{
					menu++;
					goto begin;
				}
				
			}	
			
			cal:
			Send_str("CALIBRATION PARA", 0);
			Send_str("                ", 16);
			Send_str("  TO CONTINUE   ", 32);
			Send_str("PRSS SET/NXT KEY", 48);
			UpdateLcd();	
			while(checksw()!= 1);
			
			channel_no=0;
			Send_str("CALIBRATION PARA", 0);
			channel_select();	
				
			Send_str("SET CALIBRATION ", 0);
			Send_str("CHANNEL NO:     ", 16);
			Send_str("                ", 32);
			Send_str("  PRESS INC KEY ", 48);
			display(channel_no+1,28,0,1);
			UpdateLcd();
			while(checksw()!= 3);
			
			ADS1248CargaInicial(channel_no);
			
			switch(c[channel_no])
			{
				case 1 || 2:
				{
					cr420(channel_no,0);
					break;
				}
				case 3:
				{
					crRTD(channel_no,0);
					break;
				}
				case 4:
				{
					crthermo(channel_no,0);
					break;
				}
			}
			
			Send_str("CALIBRATION PARA", 0);
			Send_str("    EXIT MENU   ", 16);
			Send_str("       NO       ", 32);
			Send_str("USE INC & SHIFT ", 48);
			UpdateLcd();
			exit_flags=1;
			
			while(checksw()!=1)
			{
				if(checksw()==3)
				{
					Send_str("       YES      ", 32);
					UpdateLcd();
					exit_flags=0;
				}
				else if(checksw()==2)
				{
					Send_str("       NO       ", 32);
					UpdateLcd();
					exit_flags=1;
				}
			}
			
			if(exit_flags)
			goto cal;
			else
			goto begin;
			
		}


////////////////////////////////////////////////////////////////////////
		case 9:
		{
			char count=0,u=0,t=0,h=0;
			Send_str("    MAIN MENU   ", 0);
			Send_str("  SCAN INTERVAL ", 16);
			Send_str("    PARAMETER   ", 32);
			Send_str("  PRESS INC KEY ", 48);
			UpdateLcd();	
			while(checksw()!= 3)
			{
				if(checksw()==1)
				{
					menu++;
					goto begin;
				}
				
			}	
			
			scan:
			Send_str("  SCAN INTERVAL ", 0);
			Send_str("                ", 16);
			Send_str("  TO CONTINUE   ", 32);
			Send_str("PRSS SET/NXT KEY", 48);
			UpdateLcd();	
			while(checksw()!= 1);
			
			Send_str("SCAN INTRVAL SET", 0);
			Send_str("    SCAN TIME   ", 16);
			Send_str("USE INC & SHIFT ", 32);
			Send_str("      SECONDS   ", 48);
			display(scan_time,50,0,3);	
			UpdateLcd();
			
			while(checksw()!= 1)
			{
				if(checksw()== 3 && count==0)
				u++;
				else if(checksw()== 3 && count==1)
				t++;
				else if(checksw()== 3 && count==2)
				h++;
				else if(checksw()== 2 )
				count++;
				
				if(count==3)
				count=0;
				
				scan_time=(u%10)+(t%10)*10+(h%10)*100;
				display(scan_time,50,0,3);
				scan_time*=6;	
				UpdateLcd();
				
			}
			
			Send_str("  SCAN INTERVAL ", 0);
			Send_str("    EXIT MENU   ", 16);
			Send_str("       NO       ", 32);
			Send_str("USE INC & SHIFT ", 48);
			UpdateLcd();
			exit_flags=1;
			
			while(checksw()!=1)
			{
				if(checksw()==3)
				{
					Send_str("       YES      ", 32);
					UpdateLcd();
					exit_flags=0;
				}
				else if(checksw()==2)
				{
					Send_str("       NO       ", 32);
					UpdateLcd();
					exit_flags=1;
				}
			}
			
			if(exit_flags)
			goto scan;
			else
			goto begin;
		
			
				
		}
////////////////////////////////////////////////////////////////////////

		case 10:
		{
			char count=0,u=0,t=0,h=0;
			Send_str("    MAIN MENU   ", 0);
			Send_str("  AMBIENT MODE  ", 16);
			Send_str("    PARAMETER   ", 32);
			Send_str("  PRESS INC KEY ", 48);
			UpdateLcd();	
			while(checksw()!= 3)
			{
				if(checksw()==1)
				{
					menu++;
					goto begin;
				}
				
			}
			
			amb:
			Send_str("  AMBIENT MODE  ", 0);
			Send_str("                ", 16);
			Send_str("  TO CONTINUE   ", 32);
			Send_str("PRSS SET/NXT KEY", 48);
			UpdateLcd();	
			while(checksw()!= 1);
			
			Send_str("  AMBIENT MODE  ", 0);
			Send_str("SET AMBIENT TEMP", 16);
			Send_str("         deg C  ", 32);
			Send_str("USE INC & SHIFT ", 48);
			display(ambient_temp,35,0,3);
			UpdateLcd();
			
			while(checksw()!= 1)
			{
				if(checksw()== 3 && count==0)
				u++;
				else if(checksw()== 3 && count==1)
				t++;
				else if(checksw()== 3 && count==2)
				h++;
				else if(checksw()== 2 )
				count++;
				
				if(count==3)
				count=0;

				ambient_temp=(u%10)+(t%10)*10+(h%10)*100;
				display(ambient_temp,36,0,3);
				UpdateLcd();
			}	
			
			Send_str("AMBIENT MODE SET", 0);
			Send_str("      UPDATE    ", 16);
			Send_str("       NO       ", 32);
			Send_str("USE INC & SHIFT ", 48);
			UpdateLcd();
			
			ambient_flag =0;
			
			while(checksw()!=1)
			{	
				if(checksw()==3)
				{Send_str("       YES      ", 32); ambient_flag=1; UpdateLcd();}
				
				if(checksw()==2)
				{Send_str("       NO       ", 32); ambient_flag=0; UpdateLcd();}
				
			}
			
			Send_str("  AMBIENT MODE  ", 0);
			Send_str("    EXIT MENU   ", 16);
			Send_str("       NO       ", 32);
			Send_str("USE INC & SHIFT ", 48);
			UpdateLcd();
			exit_flags=1;
			
			while(checksw()!=1)
			{
				if(checksw()==3)
				{
					Send_str("       YES      ", 32);
					UpdateLcd();
					exit_flags=0;
				}
				else if(checksw()==2)
				{
					Send_str("       NO       ", 32);
					UpdateLcd();
					exit_flags=1;
				}
			}
			
			if(exit_flags)
			goto amb;
			else
			goto begin;
			
			
		}	
////////////////////////////////////////////////////////////////////////

		case 11:
		{
			char count=0,u=0,t=0,h=0;
			Send_str("    MAIN MENU   ", 0);
			Send_str(" MODBUS SETTING ", 16);
			Send_str("    PARAMETER   ", 32);
			Send_str("  PRESS INC KEY ", 48);
			UpdateLcd();	
			while(checksw()!= 3)
			{
				if(checksw()==1)
				{
					menu++;
					goto begin;
				}
				
			}
			
			mod:
			Send_str(" MODBUS SETTING ", 0);
			Send_str("                ", 16);
			Send_str("  TO CONTINUE   ", 32);
			Send_str("PRSS SET/NXT KEY", 48);
			UpdateLcd();	
			while(checksw()!= 1);
			
			Send_str("MODBUS PARAMETER", 0);
			Send_str("   STATION ID   ", 16);
			Send_str("                ", 32);
			Send_str("USE INC & SHIFT ", 48);
			display(DeviceId,38,0,3);
			UpdateLcd();
			
			while(checksw()!= 1)
			{
				if(checksw()== 3 && count==0)
				u++;
				else if(checksw()== 3 && count==1)
				t++;
				else if(checksw()== 3 && count==2)
				{
					h++;
					if(h>2)
					h=0;
				}
				else if(checksw()== 2 )
				count++;
				
				if(count==3)
				count=0;

				DeviceId=(u%10)+(t%10)*10+(h%10)*100;
				display(DeviceId,38,0,3);
				UpdateLcd();
			}
			
						
			Send_str("MODBUS PARAMETER", 0);
			Send_str(" BAUD RATE : BPS", 16);
			Send_str("                ", 32);
			Send_str("USE INC & SHIFT ", 48);
			display(Modbus_baudrate,37,0,6);
			UpdateLcd();
			
			
			while(checksw()!= 1)
			{
				if(checksw()==3)
				Modbus_baudrate+=9600;
				else if(checksw()==2)
				Modbus_baudrate-=9600;
				
				if(Modbus_baudrate>115200 || Modbus_baudrate<9600)
				Modbus_baudrate=9600;
				
				display(Modbus_baudrate,37,0,6);
				UpdateLcd();
			}
			
			Send_str("MODBUS PARAMETER", 0);
			Send_str("   SET PARITY   ", 16);
			Send_str("      NONE      ", 32);
			Send_str("USE INC & SHIFT ", 48);
			UpdateLcd();
			Modbus_parity=0;
			count=0;
			
			while(checksw()!= 1)
			{
				if(checksw()==3)
				{
					count++;
					if(count==2)
					{
						Modbus_parity=2;
						Send_str("      EVEN      ", 32);
						UpdateLcd();
					}
					else if(count==1)
					{
						Modbus_parity=1;
						Send_str("      ODD       ", 32);
						UpdateLcd();
					}
					if(count==3 || count==0)
					{
						count=0;
						Modbus_parity=0;
						Send_str("      NONE      ", 32);
						UpdateLcd();
					}
				}
					
				if(checksw()==2)
				{
					count--;
					if(count==2)
					{
						Modbus_parity=2;
						Send_str("      EVEN      ", 32);
						UpdateLcd();
					}
					else if(count==1)
					{
						Modbus_parity=1;
						Send_str("      ODD       ", 32);
						UpdateLcd();
					}
					if(count<=0)
					{
						count=0;
						Modbus_parity=0;
						Send_str("      NONE      ", 32);
						UpdateLcd();
					}
					
				}
			}
			
			Send_str("MODBUS PARAMETER", 0);
			Send_str("  SET STOPBITS  ", 16);
			Send_str("       ONE      ", 32);
			Send_str("USE INC & SHIFT ", 48);
			UpdateLcd();
			Modbus_stopbits=1;
			
			while(checksw()!= 1)
			{
				if(checksw()==2)
				{
					Modbus_stopbits=2;
					Send_str("      TWO     ", 32);
					UpdateLcd();
					
				}
					
				if(checksw()==3)
				{
					Modbus_stopbits=1;
					Send_str("      ONE       ", 32);
					UpdateLcd();
					
				}
			}
			
			Send_str(" MODBUS SETTING ", 0);
			Send_str("    EXIT MENU   ", 16);
			Send_str("       NO       ", 32);
			Send_str("USE INC & SHIFT ", 48);
			UpdateLcd();
			exit_flags=1;
			
			while(checksw()!=1)
			{
				if(checksw()==3)
				{
					Send_str("       YES      ", 32);
					UpdateLcd();
					exit_flags=0;
				}
				else if(checksw()==2)
				{
					Send_str("       NO       ", 32);
					UpdateLcd();
					exit_flags=1;
				}
			}
			
			if(exit_flags)
			goto mod;
			else
			goto begin;
		}
		
		
////////////////////////////////////////////////////////////////////////

		case 12:
		{
			Send_str("    MAIN MENU   ", 0);
			Send_str("   RELAY LOGIC  ", 16);
			Send_str("    PARAMETER   ", 32);
			Send_str("  PRESS INC KEY ", 48);
			UpdateLcd();	
			while(checksw()!= 3)
			{
				if(checksw()==1)
				{
					menu++;
					goto begin;
				}
				
			}
			
			relay:
			Send_str("   RELAY LOGIC  ", 0);
			Send_str("                ", 16);
			Send_str("  TO CONTINUE   ", 32);
			Send_str("PRSS SET/NXT KEY", 48);
			UpdateLcd();	
			while(checksw()!= 1);
			
			
			for(i=0;i<=3 ;i++)
			{
				Send_str("ASSIGN RELAY:   ", 0);
				display(i+1,14,0,1);
				Send_str("   TO CHANNEL   ", 16);				
				Send_str("                ", 32);
				Send_str("USE INC & SHIFT ", 48);
				channel_no=0;
				display(channel_no+1,40,0,1);	
				UpdateLcd();
				
				
				while(checksw()!=1)
				{
					if(checksw()==3)
					{
						channel_no++;
						if(channel_no>7)
						channel_no=0;
						
						display(channel_no+1,40,0,1);
						
						
					}
					
					if(checksw()==2)
					{
						channel_no--;
						if(channel_no<0)
						channel_no=7;
						
						display(channel_no+1,40,0,1);
						
						
					}
				UpdateLcd();
				
				}
				
				relay_set[i]=channel_no;
				
			}
			
			for(i=0;i<=3 ;i++)
			{
				Send_str("   LOGIC LEVEL  ", 0);
				Send_str("   RELAY :      ", 16);
				display(i+1,28,1,1);
				Send_str("   LOGIC HIGH   ", 32);
				Send_str(" USE INC & SHIFT", 48);
				UpdateLcd();
				relay_logic[i]=1;
				
				while(checksw()!=1)
				{
					if(checksw()==3)
					{
						Send_str("   LOGIC LOW    ", 32);
						relay_logic[i]=0;	
						UpdateLcd();
					}
					else if(checksw()==2)
					{
						Send_str("   LOGIC HIGH   ", 32);
						relay_logic[i]=1;	
						UpdateLcd();
					}
				}
				
				
			}
			
			
			Send_str("   RELAY LOGIC  ", 0);
			Send_str("    EXIT MENU   ", 16);
			Send_str("       NO       ", 32);
			Send_str("USE INC & SHIFT ", 48);
			UpdateLcd();
			exit_flags=1;
			
			while(checksw()!=1)
			{
				if(checksw()==3)
				{
					Send_str("       YES      ", 32);
					UpdateLcd();
					exit_flags=0;
				}
				else if(checksw()==2)
				{
					Send_str("       NO       ", 32);
					UpdateLcd();
					exit_flags=1;
				}
			}
			
			if(exit_flags)
			goto relay;
			else
			goto begin;
			
		}

////////////////////////////////////////////////////////////////////////
		
		case 13:
		{
			Send_str("    MAIN MENU   ", 0);
			Send_str("   LOG SETTING  ", 16);
			Send_str("    PARAMETER   ", 32);
			Send_str("  PRESS INC KEY ", 48);
			UpdateLcd();	
			while(checksw()!= 3)
			{
				if(checksw()==1)
				{
					menu++;
					goto begin;
				}
				
			}
			
			log:
			Send_str("   LOG SETTING  ", 0);
			Send_str("                ", 16);
			Send_str("  TO CONTINUE   ", 32);
			Send_str("PRSS SET/NXT KEY", 48);
			UpdateLcd();	
			while(checksw()!= 1);
			
			Send_str("   LOG SETTING  ", 0);
			Send_str("    EXIT MENU   ", 16);
			Send_str("       NO       ", 32);
			Send_str("USE INC & SHIFT ", 48);
			UpdateLcd();
			exit_flags=1;
			
			while(checksw()!=1)
			{
				if(checksw()==3)
				{
					Send_str("       YES      ", 32);
					UpdateLcd();
					exit_flags=0;
				}
				else if(checksw()==2)
				{
					Send_str("       NO       ", 32);
					UpdateLcd();
					exit_flags=1;
				}
			}
			
			if(exit_flags)
			goto log;
			else
			goto begin;
			
			
			
				
		}
////////////////////////////////////////////////////////////////////////
		
////////////////////////////////////////////////////////////////////////		
	}
	Send_str("                ", 0);
	Send_str("                ", 16);
	Send_str("                ", 32);
	Send_str("                ", 48);
	UpdateLcd();
}

int checksw()
{
	if((P2IN & 0X01)==0)					//Check for SW1B pressed 
	{delay_ms(100); 
	if((P2IN & 0X01)==0);		
	return 1;}
	else if((P2IN & 0X02)==0)					//Check for SW1B pressed 
	{delay_ms(100); 
	if((P2IN & 0X02)==0);		
	return 2;}
	else if((P2IN & 0X04)==0)					//Check for SW1B pressed 
	{delay_ms(100); 
	if((P2IN & 0X04)==0);		
	return 3;}
}

//////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
void Display_units(uint16_t unit_no,uint8_t pos)
{
/* Displays gas specified by units starting from pos */
	switch (unit_no)
  	{
    	case 0:
      			Send_str("%LEL",pos);
      			break;  
    
    	case 1:
      			Send_str("%V/V", pos);
      			break;      
    
    	case 2:
    			Send_str("mg/m3", pos);
       			break;
        
       	case 3:
       			Send_str(" PPM", pos);
      			break;
      			
       	case 4:
       			Send_str(" PPB", pos);
      			break;				
       
       	case 5:
      			Send_str("  C  ",pos);
	      		str[pos+1] = 0xdf;
       			break;		
       
        case 6:
      			Send_str("  F   ",pos);
	      		str[pos+1] = 0xdf;
       			break;
		
		case 7:
      			Send_str(" %RH ",pos);
	      		break;	
       			
       	case 8:
      			Send_str("mmWC ",pos);
	      		break;
	    
	    case 9:
      			Send_str("mmHg ",pos);
	      		break;
	      		
	    case 10:
      			Send_str("Pa  ",pos);
	      		break;
	    
	    case 11:
      			Send_str("kPa ",pos);
	      		break;
	    
	    case 12:
      			Send_str("hPa ",pos);
	      		break;
	    
	    case 13:
      			Send_str("atm ",pos);
	      		break;
	    
	    case 14:
      			Send_str("bar ",pos);
	      		break;
	    
	    case 15:
      			Send_str("Torr ",pos);
	      		break;
	    
	    case 16:
      			Send_str("dyne ",pos);
	      		break;
	      		
	    case 17:
      			Send_str("lbf  ",pos);
	      		break;
	    
	    case 18:
      			Send_str("kPa ",pos);
	      		break;
	    
	    case 19:
      			Send_str("N   ",pos);
	      		break;
	    
	    case 20:
      			Send_str("kN ",pos);
	      		break;
	    
	    case 21:
      			Send_str("MN ",pos);
	      		break;
	    
	    case 22:
      			Send_str("cal ",pos);
	      		break;
	    
	    case 23:
      			Send_str("kcal ",pos);
	      		break;
	    
	    case 24:
      			Send_str("Joule",pos);
	      		break;
	    
	    case 25:
      			Send_str("kJoul",pos);
	      		break;
	      		
	    case 26:
      			Send_str("MJoul",pos);
	      		break;
	    
	    case 27:
      			Send_str("N-mtr",pos);
	      		break;
	    
	    case 28:
      			Send_str("Ergs",pos);
	      		break;
	    
	    case 29:
      			Send_str("kWh ",pos);
	      		break;
	    
	      					
  	}           
}

/*---------------------------------------------------------------------------
* Function name       : void Send_str(char *lcd_temp, unsigned char i)
*     returns         : -
*     arg1            : unsigned char *lcd_temp, string which has to be displayed
*     arg2            : unsigned char i, starting position to display
* Created by          : Nitin Singh
* Date created        : 20/01/11
* Description         : This function updates the string character by character
*---------------------------------------------------------------------------*/
void Send_str(int8_t *lcd_temp, uint8_t i)
{
	while(*lcd_temp != 0)
		str[i++] = *lcd_temp++;                           /* storing the string to be diplayed on buffer string */
}

/*---------------------------------------------------------------------------
* Function name       : void Display_Name(char *lcd_temp, unsigned char i)
*     returns         : -
*     arg1            : unsigned char *lcd_temp, string which has to be displayed
*     arg2            : unsigned char i, starting position to display
* Created by          : Nitin Singh
* Date created        : 20/01/11
* Description         : This function updates the string character by character
*---------------------------------------------------------------------------*/
void Display_Name(int8_t *lcd_temp, uint8_t i)
{
	uint8_t temp = i;
	
	while(*lcd_temp != 0)
	{
		if((i-temp+1) == pos_cntr)
		{
			if(( indication_flags & TOGGLE))
			{
	        	 str[i++] = '_';
	        	 *lcd_temp++;
			}
	        else
	        	str[i++] = *lcd_temp++;                           /* storing the string to be diplayed on buffer string */
		}
		else
			str[i++] = *lcd_temp++;                           /* storing the string to be diplayed on buffer string */
	}
}

/*---------------------------------------------------------------------------
* Function name       : void display(uint32_t value, uint8_t pos, uint8_t flash,uint8_t number_of_digits)
*     returns         : -
*     arg1            : uint32_t value, number which has to be displayed
*     arg2            : uint8_t pos, starting position to display
*     arg3            : uint8_t flash, for flasging the digit (1 = flashing ON & 0 = flashing OFF)
*     arg4            : uint8_t number_of_digits, number of digits to be displayed
* Created by          : Nitin Singh
* Date created        : 20/01/11
*---------------------------------------------------------------------------*/
void display(uint32_t value, uint8_t pos, uint8_t flash,uint8_t number_of_digits)
{
      uint8_t digit;
   		if(number_of_digits == 6)
   		{
	         digit=((value/100000));           			//calculating thousands place digit
	         if((flash == 6) && ( indication_flags & TOGGLE))
	         	str[pos++] = '_';
	         else
	         	str[pos++]=digit+0x30;
	         number_of_digits--;
   		}
   		if(number_of_digits == 5)
   		{
	         digit=((value%100000)/10000);           			//calculating thousands place digit
	         if((flash == 5) && ( indication_flags & TOGGLE))
	         	str[pos++] = '_';
	         else
	         	str[pos++]=digit+0x30;
	         number_of_digits--;
   		}
         if(number_of_digits == 4)
         { 
	         digit=((value%100000)%10000)/1000;         			//calculating hundred place digit
	         if((flash == 4) && ( indication_flags & TOGGLE))
	         	str[pos++] = '_';
	         else
	         	str[pos++]=digit+0x30;
	         number_of_digits--;
         }
         if(number_of_digits == 3)
         { 
	         digit=(((value%100000)%10000)%1000)/100;    			//calculating tens place digit
	         if((flash == 3) && ( indication_flags & TOGGLE))
	         	str[pos++] = '_';
	         else
	         	str[pos++]=digit+0x30;
	         number_of_digits--;
         }
         if(number_of_digits == 2)
         { 
	         digit=((((value%100000)%10000)%1000)%100)/10;    			//calculating ones place digit
	         if((flash == 2) && ( indication_flags & TOGGLE))
	         	str[pos++] = '_';
	         else
	         	str[pos++]=digit+0x30;
	         number_of_digits--;
         }
         if(number_of_digits == 1)
         { 
	         digit=((((value%100000)%10000)%1000)%100)%10;    			//calculating ones place digit
	         if((flash == 1) && ( indication_flags & TOGGLE))
	         	str[pos++] = '_';
	         else
	         	str[pos++]=digit+0x30;
	         number_of_digits--;
         }
}

/*---------------------------------------------------------------------------
* Function name       : void display_name(uint8_t *string, uint8_t pos, uint8_t flash,uint8_t number_of_char)
*     returns         : -
*     arg1            : uint8_t *string, sting which has to be displayed
*     arg2            : uint8_t pos, starting position to display
*     arg3            : uint8_t flash, for flashing the character (1 = flashing ON & 0 = flashing OFF)
*     arg4            : uint8_t number_of_char, number of character to be displayed
* Created by          : Nitin Singh
* Date created        : 20/01/11
*---------------------------------------------------------------------------*/

//void display_name(uint8_t *string, uint8_t pos, uint8_t flash,uint8_t number_of_char)
//{
//      	
//      	if(number_of_char == 16)
//   		{
//	         if((flash == 16) && ( indication_flags & BLINK))
//	         	str[pos++] = '_';
//	         else
//	         	str[pos++] = *(string+15);
//	         number_of_char--;
//   		}
//      	if(number_of_char == 15)
//   		{
//	         if((flash == 15) && ( indication_flags & BLINK))
//	         	str[pos++] = '_';
//	         else
//	         	str[pos++] = *(string+14);
//	         number_of_char--;
//   		}
//   		if(number_of_char == 14)
//   		{
//	         
//	         if((flash == 14) && ( indication_flags & BLINK))
//	         	str[pos++] = '_';
//	         else
//	         	str[pos++]=*(string+13);
//	         number_of_char--;
//   		}
//         if(number_of_char == 13)
//         { 
//	         
//	         if((flash == 13) && ( indication_flags & BLINK))
//	         	str[pos++] = '_';
//	         else
//	         	str[pos++]=*(string+12);
//	         number_of_char--;
//         }
//      	if(number_of_char == 12)
//   		{
//	         if((flash == 12) && ( indication_flags & BLINK))
//	         	str[pos++] = '_';
//	         else
//	         	str[pos++] = *(string+11);
//	         number_of_char--;
//   		}
//   		if(number_of_char == 11)
//   		{
//	         
//	         if((flash == 11) && ( indication_flags & BLINK))
//	         	str[pos++] = '_';
//	         else
//	         	str[pos++]=*(string+10);
//	         number_of_char--;
//   		}
//         if(number_of_char == 10)
//         { 
//	         
//	         if((flash == 10) && ( indication_flags & BLINK))
//	         	str[pos++] = '_';
//	         else
//	         	str[pos++]=*(string+9);
//	         number_of_char--;
//         }
//         if(number_of_char == 9)
//         { 
//	         
//	         if((flash == 9) && ( indication_flags & BLINK))
//	         	str[pos++] = '_';
//	         else
//	         	str[pos++]=*(string+8);
//	         number_of_char--;
//         }
//         if(number_of_char == 8)
//         { 
//	         
//	         if((flash == 8) && ( indication_flags & BLINK))
//	         	str[pos++] = '_';
//	         else
//	         	str[pos++]=*(string+7);
//	         number_of_char--;
//         }
//         if(number_of_char == 7)
//         { 
//	         
//	         if((flash == 7) && ( indication_flags & BLINK))
//	         	str[pos++] = '_';
//	         else
//	         	str[pos++]=*(string+6);
//	         number_of_char--;
//         }
//   		if(number_of_char == 6)
//   		{
//	         if((flash == 6) && ( indication_flags & BLINK))
//	         	str[pos++] = '_';
//	         else
//	         	str[pos++] = *(string+5);
//	         number_of_char--;
//   		}
//   		if(number_of_char == 5)
//   		{
//	         
//	         if((flash == 5) && ( indication_flags & BLINK))
//	         	str[pos++] = '_';
//	         else
//	         	str[pos++]=*(string+4);
//	         number_of_char--;
//   		}
//         if(number_of_char == 4)
//         { 
//	         
//	         if((flash == 4) && ( indication_flags & BLINK))
//	         	str[pos++] = '_';
//	         else
//	         	str[pos++]=*(string+3);
//	         number_of_char--;
//         }
//         if(number_of_char == 3)
//         { 
//	         
//	         if((flash == 3) && ( indication_flags & BLINK))
//	         	str[pos++] = '_';
//	         else
//	         	str[pos++]=*(string+2);
//	         number_of_char--;
//         }
//         if(number_of_char == 2)
//         { 
//	         
//	         if((flash == 2) && ( indication_flags & BLINK))
//	         	str[pos++] = '_';
//	         else
//	         	str[pos++]=*(string+1);
//	         number_of_char--;
//         }
//         if(number_of_char == 1)
//         { 
//	         
//	         if((flash == 1) && ( indication_flags & BLINK))
//	         	str[pos++] = '_';
//	         else
//	         	str[pos++]=*(string+0);
//	         number_of_char--;
//         }
//}

/*-----------------------------------------------------------------------------------------------------------
* Function name       : void display_val_with_dp(uint8_t pos, uint32_t value, uint8_t dp, uint8_t flash)
*     returns         : -
*     
*     arg1            : uint8_t pos, starting position to display
* 	  arg2            : uint32_t value, number which has to be displayed
*     arg3            : uint8_t dp, decimal point value
* 	  arg4            : uint8_t flash, for flasging the digit (1 = flashing ON & 0 = flashing OFF)
*     
* Created by          : Nitin Singh
* Date created        : 20/01/11
*-----------------------------------------------------------------------------------------------------------*/
void display_val_with_dp(uint8_t pos, uint32_t value, uint8_t dp, uint8_t flash)
{
	uint8_t digit6,digit5,digit4,digit3,digit2,digit1;
	
	
//	digit5 = value/10000;
//	digit4 = (value%10000)/1000;
//	digit3 = ((value%10000)%1000)/100;
//	digit2 = (((value%10000)%1000)%100)/10;
//	digit1 = (((value%10000)%1000)%100)%10;
	
	digit6 = value/100000;
	digit5 = (value%100000)/10000;
	digit4 = ((value%100000)%10000)/1000;
	digit3 = (((value%100000)%10000)%1000)/100;
	digit2 = ((((value%100000)%10000)%1000)%100)/10;
	digit1 = ((((value%100000)%10000)%1000)%100)%10;
	
	if(dp == 3)
	{
		if((flash == 6) && ( indication_flags & BLINK))
	         str[pos++] = '_';
	    else
	         str[pos++] = digit6+0x30;
	         
		if((flash == 5) && ( indication_flags & BLINK))
	         str[pos++] = '_';
	    else
	         str[pos++] = digit5+0x30;
	         
		if((flash == 4) && ( indication_flags & BLINK))
	         str[pos++] = '_';
	    else
	         str[pos++] = digit4+0x30;
	    
	    str[pos++] = '.';
	    
		if((flash == 3) && ( indication_flags & BLINK))
	         str[pos++] = '_';
	    else
	         str[pos++] = digit3+0x30;
	         
		if((flash == 2) && ( indication_flags & BLINK))
	         str[pos++] = '_';
	    else
	         str[pos++] = digit2+0x30;
		
		if((flash == 1) && ( indication_flags & BLINK))
	         str[pos++] = '_';
	    else
	         str[pos++] = digit1+0x30;
	}
	else if(dp == 2)
	{
		if((flash == 5) && ( indication_flags & BLINK))
	         str[pos++] = '_';
	    else
	         str[pos++] = digit5+0x30;
	         
		if((flash == 4) && ( indication_flags & BLINK))
	         str[pos++] = '_';
	    else
	         str[pos++] = digit4+0x30;
	         
		if((flash == 3) && ( indication_flags & BLINK))
	         str[pos++] = '_';
	    else
	         str[pos++] = digit3+0x30;
	         
		str[pos++] = '.';
	         
		if((flash == 2) && ( indication_flags & BLINK))
	         str[pos++] = '_';
	    else
	         str[pos++] = digit2+0x30;
		
		if((flash == 1) && ( indication_flags & BLINK))
	         str[pos++] = '_';
	    else
	         str[pos++] = digit1+0x30;
	}
	else if(dp == 1)
	{
		if((flash == 5) && ( indication_flags & BLINK))
	         str[pos++] = '_';
	    else
	         str[pos++] = digit5+0x30;
		if((flash == 4) && ( indication_flags & BLINK))
	         str[pos++] = '_';
	    else
	         str[pos++] = digit4+0x30;
		if((flash == 3) && ( indication_flags & BLINK))
	         str[pos++] = '_';
	    else
	         str[pos++] = digit3+0x30;
		if((flash == 2) && ( indication_flags & BLINK))
	         str[pos++] = '_';
	    else
	         str[pos++] = digit2+0x30;
		str[pos++] = '.';
		if((flash == 1) && ( indication_flags & BLINK))
	         str[pos++] = '_';
	    else
	         str[pos++] = digit1+0x30;
	}
	else if(dp == 0)
	{
		if((flash == 5) && ( indication_flags & BLINK))
	         str[pos++] = '_';
	    else
	         str[pos++] = digit5+0x30;
		if((flash == 4) && ( indication_flags & BLINK))
	         str[pos++] = '_';
	    else
	         str[pos++] = digit4+0x30;
		if((flash == 3) && ( indication_flags & BLINK))
	         str[pos++] = '_';
	    else
	         str[pos++] = digit3+0x30;
		if((flash == 2) && ( indication_flags & BLINK))
	         str[pos++] = '_';
	    else
	         str[pos++] = digit2+0x30;
		if((flash == 1) && ( indication_flags & BLINK))
	         str[pos++] = '_';
	    else
	         str[pos++] = digit1+0x30;
	}
}
/*---------------------------------------------------------------------------
* Function name       : void display_negative_with_dp(uint8_t pos, float32_t num1, uint8_t dp_v, uint8_t flash)
*     returns         : -
*     arg1            : uint8_t *string, sting which has to be displayed
*     arg2            : uint8_t pos, starting position to display
*     arg3            : uint8_t flash, for flashing the character (1 = flashing ON & 0 = flashing OFF)
*     arg4            : uint8_t number_of_char, number of character to be displayed
* Created by          : Nitin Singh
* Date created        : 20/01/11
*---------------------------------------------------------------------------*/

void display_negative_with_dp(uint8_t pos, float32_t num1, uint8_t dp_v, uint8_t flash)
{
	uint8_t digit = 0;
	uint16_t num = 0;
	if(dp_v == 0)
	{
		pos++;
	}
	pos--;
	if(num1<(-0.51))
	{
		num = (uint16_t)(((-1)*num1)+0.5);
		if((flash == 5) && ( indication_flags & TOGGLE))
		        str[pos++] = '_';
		else
		   	str[pos++] = '-';
	}
	else
	{
		num = (uint16_t)(num1+0.5);
		if((flash == 5) && ( indication_flags & TOGGLE))
		        str[pos++] = '_';
		else
	   		str[pos++] = '+';
	}
	digit=((num/1000));
	if((flash == 4) && ( indication_flags & TOGGLE))
        	str[pos++] = '_';
    	else
   		str[pos++]=digit+0x30; 
   	if(dp_v == 3)
   		str[pos++] = '.';
   	digit=(num%1000)/100;
   	if((flash == 3) && ( indication_flags & TOGGLE))
        str[pos++] = '_';
    else
   		str[pos++]=digit+0x30; 
   	if(dp_v == 2)
   		str[pos++] = '.';
   	digit=((num%1000)%100)/10;
   	if((flash == 2) && ( indication_flags & TOGGLE))
        str[pos++] = '_';
    else
   		str[pos++]=digit+0x30; 
   	if(dp_v == 1)
   		str[pos++] = '.';
   	digit=((num%1000)%100)%10;
   	if((flash == 1) && ( indication_flags & TOGGLE))
        str[pos++] = '_';
    else
   		str[pos++]=digit+0x30; 
}
void led_display(unsigned int first16LEDs,unsigned int second16LEDs,unsigned int third16LEDs,unsigned int fourth16LEDs, unsigned char set)
{
   static unsigned int led_merge1 = 0x0000;
   static unsigned int led_merge2 = 0x0000;
   static unsigned int led_merge3 = 0x0000;
   static unsigned int led_merge4 = 0x0000;
   
   unsigned char i = 0;
   
   
   if(set == 1)
   {
      led_merge1 |= fourth16LEDs;
      led_merge2 |= third16LEDs;
      led_merge3 |= second16LEDs;
      led_merge4 |= first16LEDs;
   }
   else
   {
      led_merge1 &= ~fourth16LEDs;
      led_merge2 &= ~third16LEDs;
      led_merge3 &= ~second16LEDs;
      led_merge4 &= ~first16LEDs;
   }
   /*
   //for(i=0;i<8;i++)
   {
     LED_PORT |= (0x01 << LED_SERIAL_PIN_NO);
     LED_PORT &= ~(0x01 << LED_SCLK_PIN_NO);
	 LED_PORT |= (0x01 << LED_SCLK_PIN_NO);
   }
   
   for(i=0;i<8;i++)
   {
	   if(led_merge1 & (0x0001 << i))
	      LED_PORT |= (0x01 << LED_SERIAL_PIN_NO);
	   else
	      LED_PORT &= ~(0x01 << LED_SERIAL_PIN_NO);
	   if(i!=7)
	   {
	   LED_PORT &= ~(0x01 << LED_SCLK_PIN_NO);
	   LED_PORT |= (0x01 << LED_SCLK_PIN_NO);
	   }
   }
   
   for(i=0;i<8;i++)
   {
	   if(led_merge2 & (0x0001 << i))
	      LED_PORT |= (0x01 << LED_SERIAL_PIN_NO);
	   else
	      LED_PORT &= ~(0x01 << LED_SERIAL_PIN_NO);
	   
	   if(i!=7)
	   {
	   LED_PORT &= ~(0x01 << LED_SCLK_PIN_NO);
	   LED_PORT |= (0x01 << LED_SCLK_PIN_NO);
	   }
   }

      
   for(i=0;i<8;i++)
   {
	   if(led_merge3 & (0x0001 << i))
	      LED_PORT |= (0x01 << LED_SERIAL_PIN_NO);
	   else
	      LED_PORT &= ~(0x01 << LED_SERIAL_PIN_NO);
	   
	   if(i!=7)
	   {
	   LED_PORT &= ~(0x01 << LED_SCLK_PIN_NO);
	   LED_PORT |= (0x01 << LED_SCLK_PIN_NO);
	   }
   }
   */
   for(i=0;i<8;i++)
   {
	   if(led_merge4 & (0x0001 << i))
	      LED_PORT |= (0x01 << LED_SERIAL_PIN_NO);
	   else
	      LED_PORT &= ~(0x01 << LED_SERIAL_PIN_NO);
	   
	   
	   LED_PORT &= ~(0x01 << LED_SCLK_PIN_NO);
	   delay_ms(10);
	   LED_PORT |= (0x01 << LED_SCLK_PIN_NO);
	   
	   delay_ms(10);
   }
		   
   LED_PORT &= ~(0x01 << LED_RCLK_PIN_NO);
   delay_ms(10);
   LED_PORT |= (0x01 << LED_RCLK_PIN_NO);

    
}

void channel_select()
{
	Send_str(" SELECT CHANNEL ", 16);
	Send_str("                ", 32);
	Send_str(" USE INC & SHIFT", 48);
	display(channel_no+1,40,0,1);
		
	while(checksw()!=1)
	{
		if(checksw()==3)
		{
			channel_no++;
			if(channel_no>7)
			channel_no=0;
			
			display(channel_no+1,40,0,1);
			
			
		}
		
		if(checksw()==2)
		{
			channel_no--;
			if(channel_no<0)
			channel_no=7;
			
			display(channel_no+1,40,0,1);
			
			
		}
	UpdateLcd();
	
	}
	
}

