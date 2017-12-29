#ifndef KEYSENSING_H_
#define KEYSENSING_H_



/***************START BUTTON MENU***************/
#define Next             1
#define Shift            2
#define Incr             3
/***************END BUTTON MENU***************/



/***************START SHIFT BUTTON MENU*******/
#define YES              1
#define Low              2
#define On               3
#define Even             4
#define One              5
/***************END SHIFT BUTTON MENU**********/



/***************INCR BUTTON MENU***************/
#define Passward         1
#define NO               2
#define High             3
#define Off              4
#define Odd              5
#define Two              6
/***************END INCR BUTTON MENU***********/



/***************MENU MENU**********************/
#define Serial_Menu      1
#define Display_Menu     2
#define Alarm_Menu       3      
#define Output_Menu      4
#define Passward_Menu    5
#define Backlit_Menu     6
#define Test_Menu        7
#define Exit             8
/***************END NEXT BUTTON MENU**********/


/***************START SERIAL******************/
#define Channel_Enable   9
#define Slave_ID         10
#define Read_Register    11
#define PV_Address       12
#define Device_ID        13
#define Baudrate         14
#define Parity           15
#define Stop_Bits        16
/***************END SERIAL********************/


/***************Display***********************/
#define Resolution       17
#define Set_Gas          18
#define Set_Unit         19
#define Set_sec          20
#define Set_minute       21
#define Set_hour         22
#define Save             23
/***************Display END********************/


/***************ALARM**************************/
#define Alarm            24
#define Set_point        25
#define Hysterisis       26
#define Set_Logic        27
#define Latch            28
#define Time_delay       29
#define Buzzer           30

#define Fail_Safe        31
#define Fail_Safe_Delay  32
/***************END ALARM MENU***************/



/***************START OUTPUT*****************/
#define Output_Low          33
#define Output_High         34
#define Select_Output_Type  35
#define Select_scale        36

#define Set_3_8mA        	37
#define Set_4mA          	38
#define Set_8mA		     	39
#define Set_12mA	     	40
#define Set_16mA		 	41
#define Set_20mA	     	42
#define Set_21mA		 	43
/***************3.8mA-21mA MENU ends*********/



/***************START PASSWARD***************/
#define Old_Password     44
#define Set_New          45
#define Sure             46
/***************END PASSWARD*****************/


/***************START BACKLIT***************/
#define Set_Backlit      47
#define Fault_Flash      48
/***************END BACKLIT*****************/


/***************START TEST******************/
#define Test             49
/***************END TEST********************/



extern struct General_Flags
{  
  	 unsigned char Next_Button_Flag         : 1;
	 unsigned char Shift_Button_Flag        : 1;
	 unsigned char Incr_Button_Flag         : 1;	 
	
	 unsigned char Show_Conc_Flag           : 1;
	 unsigned char Sec_3_Flag               : 1;	 
	 unsigned char Start_Flag               : 1;
	 unsigned char Warm_Up_Flag             : 1;	 	 
	 unsigned char Yes_Flag                 : 1;
	 unsigned char No_Flag                  : 1;	
	 unsigned char Blink_Flag               : 1;
	 unsigned char Valid_passward           : 1;	 
	 unsigned char Toggle                   : 1;
  
}GF;



extern struct Button_Flags
{
	unsigned char Next_Flag         :1;
	unsigned char Shift_Flag        :1;
	unsigned char Incr_Flag         :1;
}Current_Button;

extern struct Menu_Flags
{
	unsigned char Serial_Flag       :1;	
	unsigned char Display_Flag      :1;	
	unsigned char Alarm_Flag        :1;
	unsigned char Output_Flag       :1;
	unsigned char Passward_Flag     :1;
	unsigned char Backlit_Flag      :1;
	unsigned char Test_Flag         :1;
	unsigned char Exit_Menu_Flag    :1;
}Current_Menu;


extern struct Serial_Flags
{
	unsigned char Channel_Enable_Flag  :1;
	unsigned char Slave_ID_Flag      :1;
	unsigned char Read_Register_Flag :1;
	unsigned char PV_Address_Flag    :1;
	unsigned char Device_ID_Flag     :1;
	unsigned char Baudrate_Flag      :1;
	unsigned char Parity_Flag        :1;
	unsigned char Stop_Bits_Flag     :1;
	unsigned char Exit_Flag          :1;
}Current_serial;


extern struct Display_Flags
{
	unsigned char Resolution_Flag  :1;
	unsigned char Set_Gas_Flag     :1;
	unsigned char Set_Unit_Flag    :1;
	unsigned char Set_hour_Flag    :1;
	unsigned char Set_sec_Flag     :1;
	unsigned char Set_minute_Flag  :1;
	unsigned char Save_Flag        :1;
	unsigned char Exit_Flag        :1;
}Current_Display;


extern struct Alarm_Flags
{
	unsigned char Alarm1_Flag        :1;
	unsigned char Set_point1_Flag    :1;
	unsigned char Hysterisis1_Flag   :1;
	unsigned char Set_Logic1_Flag    :1;
	unsigned char Latch1_Flag        :1;
	unsigned char Time_delay1_Flag   :1;
	
	unsigned char Alarm2_Flag        :1;
	unsigned char Set_point2_Flag    :1;
	unsigned char Hysterisis2_Flag   :1;
	unsigned char Set_Logic2_Flag    :1;
	unsigned char Latch2_Flag        :1;
	unsigned char Time_delay2_Flag   :1;
	
	unsigned char Alarm3_Flag        :1;
	unsigned char Set_point3_Flag    :1;
	unsigned char Hysterisis3_Flag   :1;
	unsigned char Set_Logic3_Flag    :1;
	unsigned char Latch3_Flag        :1;
	unsigned char Time_delay3_Flag   :1;
	
	unsigned char Alarm4_Flag        :1;
	unsigned char Set_point4_Flag    :1;
	unsigned char Hysterisis4_Flag   :1;
	unsigned char Set_Logic4_Flag    :1;
	unsigned char Latch4_Flag        :1;
	unsigned char Time_delay4_Flag   :1;

    unsigned char Buzzer_Flag        :1;
	unsigned char Fail_Safe_Flag     :1;
	unsigned char Fail_Safe_Delay_Flag   :1;	
	unsigned char Exit_Flag          :1;
	
}Current_Alarm;



extern struct Output_Flags
{	
	unsigned char Output_Low_Flag     :1;
	unsigned char Output_High_Flag    :1;
	unsigned char Select_Output_Type_Flag :1;
	
	unsigned char Set_3_8mA_Flag      :1;
	unsigned char Set_4mA_Flag        :1;
	unsigned char Set_8mA_Flag		  :1;	
	unsigned char Set_12mA_Flag	      :1;
	unsigned char Set_16mA_Flag       :1;
	unsigned char Set_20mA_Flag	      :1;
	unsigned char Set_21mA_Flag		  :1;
	
	unsigned char Select_scale_Flag   :1;	
	unsigned char Exit_Flag           :1;
}Current_Output;



extern struct Passward_Flags
{
	unsigned char Old_Password_Flag :1;		
	unsigned char Set_New_Flag      :1;
	unsigned char Sure_Flag         :1;
	unsigned char Exit_Flag         :1;
}Current_Passward;


extern struct Backlit_Flags
{
	unsigned char Set_Backlit_Flag   :1;
	unsigned char Fault_Flash_Flag   :1;
	unsigned char Exit_Flag          :1;
}Current_Backlit;


extern struct Test_Flags
{
	unsigned char Test_Flag           :1;
	unsigned char Exit_Flag           :1;
}Current_Test;


extern uint8_t Next_Parameter  ;
extern uint8_t Incr_Parameter  ;
extern uint8_t Shift_Parameter ;

extern uint8_t  sec_complete;
extern uint8_t  minute_complete;
extern uint8_t  hour_complete;

extern uint8_t Button;
extern uint8_t Menu;
extern uint8_t Baudrate_Count;
extern uint8_t Parity_Count;
extern uint8_t Backlit_Count;
extern uint8_t Backlit_Count_update;
extern uint8_t Backlit_damp;
extern uint8_t Timeout_Count;
extern volatile uint8_t saving_value;
extern uint8_t unit_count1;
extern uint8_t First_calibration;
extern uint8_t number_of_digits1;
extern uint8_t flash1;



extern uint16_t  passward_1;
extern uint8_t   Position;
extern uint32_t  Limit;
extern uint32_t  Hysterisis1_data_temp;
extern uint32_t  Hysterisis2_data_temp;
extern uint8_t   dp_count_temp;
extern uint32_t  Number;



extern uint32_t  upcount;
extern uint32_t  downcount;

extern uint8_t channel;
extern uint16_t Global_Counter;



void Init_flags(void);
void Key_Function(void);
void Next_Routine(void);
void Shift_Routine(void);
void Incr_Routine(void);

void General_Flags_Reset(void);
void Button_Flags_Reset(void);
void Menu_Flags_Reset(void);
void Global_Values_Reset(void);

void Serial_Flags_Reset(void);
void Display_Flags_Reset(void);
void Alarm_Flags_Reset(void);
void Offset_Flags_Reset(void);
void Output_Flags_Reset(void);
void Passward_Flags_Reset(void);
void Backlit_Flags_Reset(void);
void Test_Flags_Reset(void);

void Incr_Para_reset(void);
void Shift_Para_reset(void);


#endif /*KEYSENSING_H_*/
