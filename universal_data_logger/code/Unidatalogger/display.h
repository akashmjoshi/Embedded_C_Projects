#ifndef DISPLAY_TEST_H_
#define DISPLAY_TEST_H_

#include "msp430x26x.h"
#include "system.h"

#define LED_PORT	  	P1OUT
#define LED_SERIAL_PIN_NO 	7
#define LED_RCLK_PIN_NO 	6
#define LED_SCLK_PIN_NO 	5

#define CH_PORT	  		P1OUT
#define CH_SERIAL_PIN_NO 	4
#define CH_RCLK_PIN_NO 		3
#define CH_SCLK_PIN_NO 		2


/***************** RTC *****************/
#define SEC_REG_ADDRS       		0x00
#define MIN_REG_ADDRS       		0x01
#define HOUR_REG_ADDRS		 		0x02
#define DAY_REG_ADDRS        		0x03
#define DATE_REG_ADDRS  			0x04
#define MONTH_REG_ADDRS        		0x05
#define YEAR_REG_ADDRS  			0x06

typedef struct Name_Parameters
{
	int8_t Name1[14];
	int8_t Name2[14];
	int8_t Name3[14];
	int8_t Name4[14];
	int8_t Name5[14];
	
}NameParameters;

typedef struct Modbus_Parameters
{
	uint8_t SlaveID;
	uint8_t ReadRegister;
	uint16_t PvAddress;
	
}ModbusParameters;


typedef struct Alarm_Parameters
{
	uint16_t Alarm1_Hys;
	uint16_t Alarm2_Hys;
	int32_t Alarm1_SetPt;
	int32_t Alarm2_SetPt;
	
}AlarmParameters;

typedef struct Display_Parameters
{
	uint8_t  dp;
	uint8_t  units;
	uint16_t gas_no;
		
}DisplayParameters;

#define MAX_GAS_NO	65
#define MAX_UNIT	29
/******************** Error Codes from IntelliMaster *********************/
#define OPEN_ERROR				32767
#define OVER_ERROR		 		32766
#define UNDER_ERROR		 		32765
#define SLAVE_NOT_RESPONDING	32764
#define CHANNEL_NOT_ENABLED		32763
#define COMM_STOP_OR_MAIN_MENU	32762
#define NO_CHANNEL_ACTIVATED	32761
/************************************************************/
/******************** MACRO Definitions *********************/
/************************************************************/

/***************** use_alarm_flag *****************/

#define USE_CH1_ALARM_1_FLAG    		0x00000001
#define USE_CH1_ALARM_2_FLAG    		0x00000002
#define USE_CH2_ALARM_1_FLAG    		0x00000004
#define USE_CH2_ALARM_2_FLAG    		0x00000008
#define USE_CH3_ALARM_1_FLAG    		0x00000010
#define USE_CH3_ALARM_2_FLAG    		0x00000020
#define USE_CH4_ALARM_1_FLAG    		0x00000040
#define USE_CH4_ALARM_2_FLAG    		0x00000080
#define USE_CH5_ALARM_1_FLAG    		0x00000100
#define USE_CH5_ALARM_2_FLAG    		0x00000200
#define USE_CH6_ALARM_1_FLAG    		0x00000400
#define USE_CH6_ALARM_2_FLAG    		0x00000800
#define USE_CH7_ALARM_1_FLAG    		0x00001000
#define USE_CH7_ALARM_2_FLAG    		0x00002000
#define USE_CH8_ALARM_1_FLAG    		0x00004000
#define USE_CH8_ALARM_2_FLAG    		0x00008000
#define USE_CH9_ALARM_1_FLAG    		0x00010000
#define USE_CH9_ALARM_2_FLAG    		0x00020000
#define USE_CH10_ALARM_1_FLAG    		0x00040000
#define USE_CH10_ALARM_2_FLAG    		0x00080000
#define USE_CH11_ALARM_1_FLAG    		0x00100000
#define USE_CH11_ALARM_2_FLAG    		0x00200000
#define USE_CH12_ALARM_1_FLAG    		0x00400000
#define USE_CH12_ALARM_2_FLAG    		0x00800000
#define USE_CH13_ALARM_1_FLAG    		0x01000000
#define USE_CH13_ALARM_2_FLAG    		0x02000000
#define USE_CH14_ALARM_1_FLAG    		0x04000000
#define USE_CH14_ALARM_2_FLAG    		0x08000000
#define USE_CH15_ALARM_1_FLAG    		0x10000000
#define USE_CH15_ALARM_2_FLAG    		0x20000000
#define USE_CH16_ALARM_1_FLAG    		0x40000000
#define USE_CH16_ALARM_2_FLAG    		0x80000000

/***************** logic_flag *****************/

#define CH1_LOGIC_1_FLAG    		0x00000001
#define CH1_LOGIC_2_FLAG    		0x00000002
#define CH2_LOGIC_1_FLAG    		0x00000004
#define CH2_LOGIC_2_FLAG    		0x00000008
#define CH3_LOGIC_1_FLAG    		0x00000010
#define CH3_LOGIC_2_FLAG    		0x00000020
#define CH4_LOGIC_1_FLAG    		0x00000040
#define CH4_LOGIC_2_FLAG    		0x00000080
#define CH5_LOGIC_1_FLAG    		0x00000100
#define CH5_LOGIC_2_FLAG    		0x00000200
#define CH6_LOGIC_1_FLAG    		0x00000400
#define CH6_LOGIC_2_FLAG    		0x00000800
#define CH7_LOGIC_1_FLAG    		0x00001000
#define CH7_LOGIC_2_FLAG    		0x00002000
#define CH8_LOGIC_1_FLAG    		0x00004000
#define CH8_LOGIC_2_FLAG    		0x00008000
#define CH9_LOGIC_1_FLAG    		0x00010000
#define CH9_LOGIC_2_FLAG    		0x00020000
#define CH10_LOGIC_1_FLAG    		0x00040000
#define CH10_LOGIC_2_FLAG    		0x00080000
#define CH11_LOGIC_1_FLAG    		0x00100000
#define CH11_LOGIC_2_FLAG    		0x00200000
#define CH12_LOGIC_1_FLAG    		0x00400000
#define CH12_LOGIC_2_FLAG    		0x00800000
#define CH13_LOGIC_1_FLAG    		0x01000000
#define CH13_LOGIC_2_FLAG    		0x02000000
#define CH14_LOGIC_1_FLAG    		0x04000000
#define CH14_LOGIC_2_FLAG    		0x08000000
#define CH15_LOGIC_1_FLAG    		0x10000000
#define CH15_LOGIC_2_FLAG    		0x20000000
#define CH16_LOGIC_1_FLAG    		0x40000000
#define CH16_LOGIC_2_FLAG    		0x80000000

/***************** Latch_flag *****************/

#define CH1_LATCH_1_FLAG    		0x00000001
#define CH1_LATCH_2_FLAG    		0x00000002
#define CH2_LATCH_1_FLAG    		0x00000004
#define CH2_LATCH_2_FLAG    		0x00000008
#define CH3_LATCH_1_FLAG    		0x00000010
#define CH3_LATCH_2_FLAG    		0x00000020
#define CH4_LATCH_1_FLAG    		0x00000040
#define CH4_LATCH_2_FLAG    		0x00000080
#define CH5_LATCH_1_FLAG    		0x00000100
#define CH5_LATCH_2_FLAG    		0x00000200
#define CH6_LATCH_1_FLAG    		0x00000400
#define CH6_LATCH_2_FLAG    		0x00000800
#define CH7_LATCH_1_FLAG    		0x00001000
#define CH7_LATCH_2_FLAG    		0x00002000
#define CH8_LATCH_1_FLAG    		0x00004000
#define CH8_LATCH_2_FLAG    		0x00008000
#define CH9_LATCH_1_FLAG    		0x00010000
#define CH9_LATCH_2_FLAG    		0x00020000
#define CH10_LATCH_1_FLAG    		0x00040000
#define CH10_LATCH_2_FLAG    		0x00080000
#define CH11_LATCH_1_FLAG    		0x00100000
#define CH11_LATCH_2_FLAG    		0x00200000
#define CH12_LATCH_1_FLAG    		0x00400000
#define CH12_LATCH_2_FLAG    		0x00800000
#define CH13_LATCH_1_FLAG    		0x01000000
#define CH13_LATCH_2_FLAG    		0x02000000
#define CH14_LATCH_1_FLAG    		0x04000000
#define CH14_LATCH_2_FLAG    		0x08000000
#define CH15_LATCH_1_FLAG    		0x10000000
#define CH15_LATCH_2_FLAG    		0x20000000
#define CH16_LATCH_1_FLAG    		0x40000000
#define CH16_LATCH_2_FLAG    		0x80000000

/***************** alarm_channel_exit_flag *****************/

#define EXIT_ALARM_CHANNEL_1_FLAG    		0x0001
#define EXIT_ALARM_CHANNEL_2_FLAG    		0x0002
#define EXIT_ALARM_CHANNEL_3_FLAG    		0x0004
#define EXIT_ALARM_CHANNEL_4_FLAG    		0x0008
#define EXIT_ALARM_CHANNEL_5_FLAG    		0x0010
#define EXIT_ALARM_CHANNEL_6_FLAG    		0x0020
#define EXIT_ALARM_CHANNEL_7_FLAG    		0x0040
#define EXIT_ALARM_CHANNEL_8_FLAG    		0x0080
#define EXIT_ALARM_CHANNEL_9_FLAG    		0x0100
#define EXIT_ALARM_CHANNEL_10_FLAG    		0x0200
#define EXIT_ALARM_CHANNEL_11_FLAG    		0x0400
#define EXIT_ALARM_CHANNEL_12_FLAG    		0x0800
#define EXIT_ALARM_CHANNEL_13_FLAG    		0x1000
#define EXIT_ALARM_CHANNEL_14_FLAG    		0x2000
#define EXIT_ALARM_CHANNEL_15_FLAG    		0x4000
#define EXIT_ALARM_CHANNEL_16_FLAG    		0x8000

/***************** modbus_use_channel_flag *****************/

#define USE_CHANNEL_1_FLAG    		0x0001
#define USE_CHANNEL_2_FLAG    		0x0002
#define USE_CHANNEL_3_FLAG    		0x0004
#define USE_CHANNEL_4_FLAG    		0x0008
#define USE_CHANNEL_5_FLAG    		0x0010
#define USE_CHANNEL_6_FLAG    		0x0020
#define USE_CHANNEL_7_FLAG    		0x0040
#define USE_CHANNEL_8_FLAG    		0x0080
#define USE_CHANNEL_9_FLAG    		0x0100
#define USE_CHANNEL_10_FLAG    		0x0200
#define USE_CHANNEL_11_FLAG    		0x0400
#define USE_CHANNEL_12_FLAG    		0x0800
#define USE_CHANNEL_13_FLAG    		0x1000
#define USE_CHANNEL_14_FLAG    		0x2000
#define USE_CHANNEL_15_FLAG    		0x4000
#define USE_CHANNEL_16_FLAG    		0x8000

/***************** modbus_channel_exit_flag *****************/

#define EXIT_CHANNEL_1_FLAG    			0x0001
#define EXIT_CHANNEL_2_FLAG    			0x0002
#define EXIT_CHANNEL_3_FLAG    			0x0004
#define EXIT_CHANNEL_4_FLAG    			0x0008
#define EXIT_CHANNEL_5_FLAG    			0x0010
#define EXIT_CHANNEL_6_FLAG    			0x0020
#define EXIT_CHANNEL_7_FLAG    			0x0040
#define EXIT_CHANNEL_8_FLAG    			0x0080
#define EXIT_CHANNEL_9_FLAG    			0x0100
#define EXIT_CHANNEL_10_FLAG    		0x0200
#define EXIT_CHANNEL_11_FLAG    		0x0400
#define EXIT_CHANNEL_12_FLAG    		0x0800
#define EXIT_CHANNEL_13_FLAG    		0x1000
#define EXIT_CHANNEL_14_FLAG    		0x2000
#define EXIT_CHANNEL_15_FLAG    		0x4000
#define EXIT_CHANNEL_16_FLAG    		0x8000

/***************** display_menu_exit_flag *****************/

#define DISPLAY_EXIT_CHANNEL_1_FLAG    			0x0001
#define DISPLAY_EXIT_CHANNEL_2_FLAG    			0x0002
#define DISPLAY_EXIT_CHANNEL_3_FLAG    			0x0004
#define DISPLAY_EXIT_CHANNEL_4_FLAG    			0x0008
#define DISPLAY_EXIT_CHANNEL_5_FLAG    			0x0010
#define DISPLAY_EXIT_CHANNEL_6_FLAG    			0x0020
#define DISPLAY_EXIT_CHANNEL_7_FLAG    			0x0040
#define DISPLAY_EXIT_CHANNEL_8_FLAG    			0x0080
#define DISPLAY_EXIT_CHANNEL_9_FLAG    			0x0100
#define DISPLAY_EXIT_CHANNEL_10_FLAG    		0x0200
#define DISPLAY_EXIT_CHANNEL_11_FLAG    		0x0400
#define DISPLAY_EXIT_CHANNEL_12_FLAG    		0x0800
#define DISPLAY_EXIT_CHANNEL_13_FLAG    		0x1000
#define DISPLAY_EXIT_CHANNEL_14_FLAG    		0x2000
#define DISPLAY_EXIT_CHANNEL_15_FLAG    		0x4000
#define DISPLAY_EXIT_CHANNEL_16_FLAG    		0x8000




/////***************** use_slave_monitor_flag *****************/
////#define USE_SLAVE_MONITOR_1_FLAG    	0x01
////#define USE_SLAVE_MONITOR_2_FLAG    	0x02
////
/////***************** exit_slave_monitor_flag *****************/
////#define EXIT_SLAVE_MONITOR_1_FLAG    	0x01
////#define EXIT_SLAVE_MONITOR_2_FLAG    	0x02

/***************** indication_flags_2 *****************/
#define CONFIRM_MEM_CLEAR_FLAG  0x01
#define LOG_MODE_FLAG  			0x02
#define SET_NEW_RTC_FLAG		0x04
#define FAIL_SAFE_RELAY_FLAG	0x08
#define START_STOP_COMM			0x10
#define SET_RESET	  			0x20
#define USE_COMM_FAIL_FLAG 		0x40
#define SET_NEW_PASSWORD    	0x80

/*************** Indication Flags ***************/
#define DISPLAY_AUTO_MODE			0x01
#define TOGGLE       				0x02
#define BLINK		     	 	    0x04
#define START_DOWNLOADING_FLAG		0X08
#define FACTORY_MODE    		    0x10
#define SHOW_MODE      			    0x20 
#define FACTORY_LED      		    0x40
#define KEY_DEBOUNCE			    0x80

/***************** indication_flags_3 *****************/
#define STOP_LOGGING_FLAG		  0x01

/***************** Mode Flags *****************/
#define MODBUS_SETTING_MODE			0x01
#define DISPLAY_SETTING_MODE        0x02
#define PASSWORD_MODE       		0x04
#define BACKLIT_MODE        		0x08
#define ALARM_MODE		    		0x10
#define RS485_MODE        			0x20
#define SLAVE_MONITOR_MODE     		0x40
#define START_STOP_COMM_MODE		0x80

/***************** Mode Flags_1 *****************/
#define RTC_MODE		    		0x01
#define LOG_SET_MODE        		0x02
#define MEMORY_MENU_MODE       		0x04
#define DOWNLOADING_MENU_MODE       0x08
#define MEMORY_CLEAR_FLAG     		0x10
#define EXIT_SLAVE_MONITOR_FLAG		0x20
#define USE_REPEATER_FLAG			0x40
#define DEVICE_CONFIG_OPTION_FLAG	0x80

/***************** Exit Flags *****************/
#define EXIT_MENU					0x01
#define EXIT_MODBUS_MENU_FLAG		0x02
#define EXIT_DISPLAY_MENU_FLAG      0x04
#define EXIT_PASSWORD       		0x08
#define EXIT_BACKLIT        		0x10
#define EXIT_START_STOP_COMM   		0x20
#define EXIT_ALARM	        		0x40
#define EXIT_FACTORY           		0x80
/***************** exit_flags_1*****************/
#define EXIT_LOG_SET_FLAG				0x01
#define EXIT_RTC_MENU        			0x02
#define EXIT_MEMORY_MENU				0x04
#define EXIT_LIST_MENU_FLAG				0x08
#define KEY_SENSED						0x10
#define KEY_SENSED_3_SECS				0x20
#define KEY_PRESS_3_SECS				0x40
#define EXIT_DOWNLOADING_MENU			0x80
/**************** Decimal Point ****************/
#define NO_DP        		   0
#define ONE_DP       		   1
#define TWO_DP      		   2
#define THREE_DP     		   3
#define FOUR_DP     		   4


#define FACTORY_PASSWORD      	1357
#define DONT_DISPLAY            16
#define MAGNET_DELAY            250
#define KEY_DELAY            	40
#define MAGNET_3_SECS_DELAY		5000
#define KEY_3_SECS_DELAY		3000

/*********************** MENU **********************/
#define NORMAL_MODE             	0
#define MAIN_MENU					1
#define ENTER_PASSWORD				2
#define MODBUS_MENU					3
#define CHANNEL_MODBUS_MENU			4
#define DISPLAY_SETTING_MENU		5
#define CHANNEL_DISPLAY_MENU		6
#define ALARM_MENU					7
#define CHANNEL_ALARM_MENU			8
#define START_STOP_COMMUNICATION	9
#define PASSWORD_MENU				10
#define BACKLIT_MENU				11
#define FACTORY_MENU				12
#define REMOTE_TEST_MENU			13
#define RTC_MENU					14
#define LOG_SET_MENU				15
#define MEMORY_MENU					16
#define CUSTOMIZED_LIST_MENU		17
#define DOWNLOADING_MENU			18
#define SLAVE_MONITOR_MENU			19
////#define CHANNEL_SLAVE_MONITOR_MENU	20
/*********************************************************/
/***************** CALCUATION PARAMETERS *****************/
/*********************************************************/


/************* MAIN_MENU *****************/

#define MODBUS_PARAMETER					0
#define DISPLAY_SETTING_PARAMETER			1
#define ALARM_MENU_PARAMETER				2
#define RTC_MENU_PARAMETER					3
#define LOG_SET_MENU_PARAMETER				4
#define MEMORY_MENU_PARAMETER				5
#define DOWNLOADING_PARAMETER				6
#define PASSWORD_PARAMETER					7
#define BACKLIT_PARAMETER					8
#define SLAVE_MONITOR_PARAMETER				9
#define START_STOP_COMMUNICATION_PARAMETER	10
#define MAIN_MENU_EXIT_PARAMETER			11

/************* RTC_MENU *****************/
#define RTC_PARAMETER_1				0
#define SET_RTC_PARAMETER_1			1
#define SET_RTC_PARAMETER_2			2
#define CONFIRM_RTC_PARAMETER		3
#define EXIT_RTC_MENU_PARAMETER		4

/************* LOG_SET_MENU *****************/
#define LOG_SET_MENU_PARAMETER_1				0
#define LOG_INTERVAL_PARAMETER					1
#define LOG_MODE_PARAMETER		    			2
#define LOG_TRIGGER_PARAMETER		    		3
#define SET_LOG_TRIGGER_START_YEAR_PARAMETER	4
#define SET_LOG_TRIGGER_START_HOUR_PARAMETER	5
#define SET_LOG_TRIGGER_STOP_YEAR_PARAMETER		6
#define SET_LOG_TRIGGER_STOP_HOUR_PARAMETER		7
#define KEY_PRESS_START_DELAY_PARAMETER			8
#define STOP_LOGGING_PARAMETER					9
#define EXIT_LOG_SET_MENU_PARAMETER				10

/************* MEMORY_MENU *****************/
#define MEMORY_MENU_PARAMETER_1				0
#define MEMORY_USED_PARAMETER				1
#define MEMORY_CLEAR_PARAMETER				2
#define MEMORY_CLEAR_CONFIRM_PARAMETER		3
#define EXIT_MEMORY_MENU_PARAMETER			4

/************* DOWNLOADING_MENU *****************/
#define DOWNLOADING_PARAMETER_1				0
#define DEVICE_ID_PARAMETER					1
#define SELECT_OPTION_PARAMETER				2
#define DEVICE_CONFIGURATION_PARAMETER		3
#define SELECT_DOWNLOADING_PARAMETER		4
#define BATCH_LOWER_LIMIT_PARAMETER			5
#define BATCH_UPPER_LIMIT_PARAMETER			6
#define START_DOWNLOADING_PARAMETER			7
#define DOWNLOADING_STARTED_PARAMETER		8
#define DOWNLOADING_COMPLETED_PARAMETER		9
#define NO_DATA_PARAMETER					10
#define DOWNLOADING_EXIT_PARAMETER			11

//#define DOWNLOADING_PARAMETER_1				0
//#define DEVICE_ID_PARAMETER					1
//#define SELECT_DOWNLOADING_PARAMETER		2
//#define BATCH_LOWER_LIMIT_PARAMETER			3
//#define BATCH_UPPER_LIMIT_PARAMETER			4
//#define START_DOWNLOADING_PARAMETER			5
//#define DOWNLOADING_STARTED_PARAMETER		6
//#define DOWNLOADING_COMPLETED_PARAMETER		7
//#define NO_DATA_PARAMETER					8
//#define DOWNLOADING_EXIT_PARAMETER			9

/************* SLAVE_MONITOR_MENU *****************/

#define SLAVE_MONITOR_MENU_PARA			    0
#define SLAVE_MONITOR_1_PARAMETER			1
////#define SLAVE_MONITOR_2_PARAMETER			2
#define EXIT_SLAVE_MONITOR_PARAMETER		2

/////************* CHANNEL_SLAVE_MONITOR_MENU *****************/
////
////#define USE_SLAVE_MONITOR_PARAMETER				0
////#define SET_SLAVE_ID_PARAMETER		    		1
////#define EXIT_CHANNEL_SLAVE_MONITOR_PARAMETER	2

/************* COMMUNICATION_MENU *****************/
#define COMM_PARAMETER_1 					0
#define START_STOP_PARAMETER				1
#define EXIT_START_STOP_MENU				2

/************* MODBUS_MENU *****************/

#define MODBUS_PARAMETER_1				0
#define CH1_MODBUS_PARAMETER			1
#define CH2_MODBUS_PARAMETER			2
#define CH3_MODBUS_PARAMETER			3
#define CH4_MODBUS_PARAMETER			4
#define CH5_MODBUS_PARAMETER			5
#define CH6_MODBUS_PARAMETER			6
#define CH7_MODBUS_PARAMETER			7
#define CH8_MODBUS_PARAMETER			8
#define CH9_MODBUS_PARAMETER			9
#define CH10_MODBUS_PARAMETER			10
#define CH11_MODBUS_PARAMETER			11
#define CH12_MODBUS_PARAMETER			12
#define CH13_MODBUS_PARAMETER			13
#define CH14_MODBUS_PARAMETER			14
#define CH15_MODBUS_PARAMETER			15
#define CH16_MODBUS_PARAMETER			16
#define BAUD_RATE_PARAMETER				17
#define PARITY_PARAMETER				18
#define STOPBITS_PARAMETER				19
#define MODBUS_EXIT_PARAMETER			20

/************* CHANNEL_MODBUS_MENU *****************/
#define ENABLE_CHANNEL					0
#define SET_CHANNEL_PARAMETER_1			1
#define CHANNEL_EXIT					2


/************* DISPLAY_SETTING_MENU *****************/

#define DISPLAY_PARAMETER_1					0
#define PAGE_CHANGING_PARAMETER				1
#define AUTO_PAGE_CHANGING_TIME_PARAMETER	2
#define CUSTOMIZED_NAME_LIST_PARAMETER		3
#define CH1_DISPLAY_PARAMETER				4
#define CH2_DISPLAY_PARAMETER				5
#define CH3_DISPLAY_PARAMETER				6
#define CH4_DISPLAY_PARAMETER				7
#define CH5_DISPLAY_PARAMETER				8
#define CH6_DISPLAY_PARAMETER				9
#define CH7_DISPLAY_PARAMETER				10
#define CH8_DISPLAY_PARAMETER				11
#define CH9_DISPLAY_PARAMETER				12
#define CH10_DISPLAY_PARAMETER				13
#define CH11_DISPLAY_PARAMETER				14
#define CH12_DISPLAY_PARAMETER				15
#define CH13_DISPLAY_PARAMETER				16
#define CH14_DISPLAY_PARAMETER				17
#define CH15_DISPLAY_PARAMETER				18
#define CH16_DISPLAY_PARAMETER				19
#define DISPLAY_EXIT_PARAMETER				20

/************* CHANNEL_DISPLAY_MENU *****************/


#define CHANNEL_PARAMETER_1				0
#define CHANNEL_PARAMETER_2				1
#define CHANNEL_PARAMETER_3				2
#define CHANNEL_PARAMETER_EXIT			3

/************* CUSTOMIZED_LIST_MENU *****************/

#define NAME_1_PARAMETER				0
#define NAME_2_PARAMETER				1
#define NAME_3_PARAMETER				2
#define NAME_4_PARAMETER				3
#define NAME_5_PARAMETER				4
#define NAME_EXIT_PARAMETER				5

/************* ALARM_MENU *****************/

#define ALARM_PARAMETER_1				0
#define CH1_ALARM_PARAMETER				1
#define CH2_ALARM_PARAMETER				2
#define CH3_ALARM_PARAMETER				3
#define CH4_ALARM_PARAMETER				4
#define CH5_ALARM_PARAMETER				5
#define CH6_ALARM_PARAMETER				6
#define CH7_ALARM_PARAMETER				7
#define CH8_ALARM_PARAMETER				8
#define CH9_ALARM_PARAMETER				9
#define CH10_ALARM_PARAMETER			10
#define CH11_ALARM_PARAMETER			11
#define CH12_ALARM_PARAMETER			12
#define CH13_ALARM_PARAMETER			13
#define CH14_ALARM_PARAMETER			14
#define CH15_ALARM_PARAMETER			15
#define CH16_ALARM_PARAMETER			16
#define USE_COMM_FAIL_RELAY				17
#define COMM_FAIL_RELAY_TIME			18
#define FAILSAFE_RELAY_PARAMETER		19
#define ALARM_MENU_EXIT_PARAMETER		20

/************* CHANNEL_ALARM_MENU *****************/

#define USE_ALARM1_PARAMETER				0
#define SET_ALARM1_PARAMETER				1
#define SET_HYSTERESIS1_PARAMETER			2
#define SEL_ALARM1_LOGIC_PARAMETER			3
#define SEL_ALARM1_LATCH_PARAMETER			4
#define USE_ALARM2_PARAMETER				5
#define SET_ALARM2_PARAMETER				6
#define SET_HYSTERESIS2_PARAMETER			7
#define SEL_ALARM2_LOGIC_PARAMETER			8
#define SEL_ALARM2_LATCH_PARAMETER			9
#define ALARM_EXIT_PARAMETER				10


#define DEFAULT_PARAMETER                   0

/************* PASSWORD_MENU *****************/
#define PASSWORD_PARAMETER_1				0
#define SET_PASSWORD_PARAMETER              1
#define CONFIRM_PASSWORD_PARAMETER			2
#define PASSWORD_EXIT_PARAMETER				3
/************* BACKLIT_MENU *****************/
#define BACKLIT_PARAMETER_1					0
#define BACKLIT_ON_OFF_PARAMETER            1
#define BACKLIT_EXIT_PARAMETER				2

/************* FACTORY_MENU *****************/
#define FACTORY_PARAMETER_1					0
#define SET_WARMUP_PARAMETER				1
#define MAX_LOG_COUNT_PARAMETER				2
#define SERIAL_YEAR_PARAMETER				3
#define SERIAL_MONTH_PARAMETER				4
#define SERIAL_NUMBER_PARAMETER				5
#define FACTORY_EXIT_PARAMETER				6


	 
/************************************************************/
/****************** Function Definitions ********************/
/************************************************************/

/**************** KeyScanning.c ****************/
void key_scanning(void);
void factory_setting(void);
void user_setting(void);
void next_key(void);
void enter_key(void);
void shift_key(void);
float64_t inc_digit_with_dp(float64_t num, uint8_t pos, float64_t lim);
void break_digits_with_dp (uint32_t value);
uint32_t make_digits_with_dp(void);
unsigned long inc_digit(unsigned long num, unsigned char pos,uint32_t lim);
void break_digits (uint32_t);
uint32_t make_digits(void);
void inc_key(void);
int32_t inc_neg_digit(int16_t num, uint8_t pos);
int checksw();


/****************** Display.c ******************/
void Display(int menu);
void Display_units(uint16_t unit_no,uint8_t pos);
void Display_gas(uint16_t gas_no,uint8_t pos);
void display_with_dp(uint8_t pos, float64_t value1, uint8_t dp, uint8_t flash);
void display_val_with_dp(uint8_t pos, uint32_t value, uint8_t dp, uint8_t flash);
void display_with_three_dp(uint8_t pos, float64_t value1, uint8_t dp);
void display_concentration1(uint8_t pos, float64_t value1, uint8_t dp, uint8_t flash);
void display(uint32_t value, uint8_t pos, uint8_t flash,uint8_t number_of_digits);
void display_name(uint8_t *string, uint8_t pos, uint8_t flash,uint8_t number_of_char);
void Send_str(int8_t *lcd_temp, uint8_t i);
void Display_Name(int8_t *lcd_temp, uint8_t i);
void display_negative_with_dp(uint8_t pos, float32_t num1, uint8_t dp_v, uint8_t flash);
void led_display(unsigned int first16LEDs,unsigned int second16LEDs,unsigned int third16LEDs,unsigned int fourth16LEDs, unsigned char set);


#endif /*Display_TEST_H_*/
