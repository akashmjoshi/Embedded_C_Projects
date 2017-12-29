#ifndef EEPROM_SPI_H_
#define EEPROM_SPI_H_

#define CHANNEL   2


//////////////////FACTORY VALUES ADDRESS/////////////////////////
#define EEPROM_VERIFICATION_ADD      0
#define MESSAGE_ADD                  2
#define PASSWARD_ADD                 4
#define FACTORY_PASSWARD_ADD         6
#define Scale_Type_ADD               8

#define Channel_Enable_ADD           12    
#define Slave_ID_ADD                 14
#define Read_Register_ADD            16
#define PV_Address_ADD               18
#define Device_ID_ADD                20
#define Baudrate_Count_ADD           22
#define Parity_Count_ADD             24
#define Stop_bit_Count_ADD           26


#define Page_Mode_ADD                28
#define Page_Time_ADD                30
#define DP_ADD                       32
#define GAS_NO_ADD                   34
#define UNIT_ADD                     36        
#define SEC_ADD                      38
#define MINUTE_ADD                   40
#define HOUR_ADD                     42


#define AL1_ADD                      44
#define AL2_ADD                      46
#define AL3_ADD                      48
#define AL4_ADD                      50
#define Set_point1_ADD               52  
#define Set_point2_ADD               54
#define Set_point3_ADD               56  
#define Set_point4_ADD               58
#define Hysterisis1_ADD              60
#define Hysterisis2_ADD              62
#define Hysterisis3_ADD              64
#define Hysterisis4_ADD              66
#define AL1_HI_Logic_ADD             68
#define AL2_HI_Logic_ADD             70
#define AL3_HI_Logic_ADD             72
#define AL4_HI_Logic_ADD             74
#define AL1_Latch_ADD                76
#define AL2_Latch_ADD                78
#define AL3_Latch_ADD                80
#define AL4_Latch_ADD                82
#define Time_delay1_ADD              84
#define Time_delay2_ADD              86
#define Time_delay3_ADD              88
#define Time_delay4_ADD              90
#define Buzzer_ON_ADD                92
#define AL_Failsafe_ADD              94
#define Failsafe_Delay_ADD           96 
#define Set_point1_Negative_ADD      98
#define Set_point2_Negative_ADD      100
#define Set_point3_Negative_ADD      102
#define Set_point4_Negative_ADD      104


#define Output_Low_ADD               106
#define Output_High_ADD              108
#define Output_High_Negative_ADD     110
#define Output_Low_Negative_ADD      112
#define Output_Type_ADD              114
#define correction_factor_3_7mA_ADD  116
#define correction_factor_3_8mA_ADD  118
#define correction_factor_4mA_ADD    120
#define correction_factor_8mA_ADD    122
#define correction_factor_12mA_ADD   124
#define correction_factor_16mA_ADD   126
#define correction_factor_20mA_ADD   128
#define correction_factor_21mA_ADD   130
#define correction_factor_23mA_ADD   132


#define backlit_ADD                  134
#define backlit_count_ADD            136
#define Fault_Flash_ON_ADD           138


#define NAME1_OFFSET_0_ADD						 260
#define NAME2_OFFSET_0_ADD						 261
#define NAME3_OFFSET_0_ADD						 262
#define NAME4_OFFSET_0_ADD						 263
#define NAME5_OFFSET_0_ADD						 264

#define NAME1_OFFSET_1_ADD						 265
#define NAME2_OFFSET_1_ADD						 266
#define NAME3_OFFSET_1_ADD						 267
#define NAME4_OFFSET_1_ADD						 268
#define NAME5_OFFSET_1_ADD						 269

#define NAME1_OFFSET_2_ADD						 270
#define NAME2_OFFSET_2_ADD						 271
#define NAME3_OFFSET_2_ADD						 272
#define NAME4_OFFSET_2_ADD						 273
#define NAME5_OFFSET_2_ADD						 274

#define NAME1_OFFSET_3_ADD						 275
#define NAME2_OFFSET_3_ADD						 276
#define NAME3_OFFSET_3_ADD						 277
#define NAME4_OFFSET_3_ADD						 278
#define NAME5_OFFSET_3_ADD						 279

#define NAME1_OFFSET_4_ADD						 280
#define NAME2_OFFSET_4_ADD						 281
#define NAME3_OFFSET_4_ADD						 282
#define NAME4_OFFSET_4_ADD						 283
#define NAME5_OFFSET_4_ADD						 284

#define NAME1_OFFSET_5_ADD						 285
#define NAME2_OFFSET_5_ADD						 286
#define NAME3_OFFSET_5_ADD						 287
#define NAME4_OFFSET_5_ADD						 288
#define NAME5_OFFSET_5_ADD						 289

#define NAME1_OFFSET_6_ADD						 290
#define NAME2_OFFSET_6_ADD						 291
#define NAME3_OFFSET_6_ADD						 292
#define NAME4_OFFSET_6_ADD						 293
#define NAME5_OFFSET_6_ADD						 294

#define NAME1_OFFSET_7_ADD						 295
#define NAME2_OFFSET_7_ADD						 296
#define NAME3_OFFSET_7_ADD						 297
#define NAME4_OFFSET_7_ADD						 298
#define NAME5_OFFSET_7_ADD						 299

#define NAME1_OFFSET_8_ADD						 300
#define NAME2_OFFSET_8_ADD						 301
#define NAME3_OFFSET_8_ADD						 302
#define NAME4_OFFSET_8_ADD						 303
#define NAME5_OFFSET_8_ADD						 304

#define NAME1_OFFSET_9_ADD						 305
#define NAME2_OFFSET_9_ADD						 306
#define NAME3_OFFSET_9_ADD						 307
#define NAME4_OFFSET_9_ADD						 308
#define NAME5_OFFSET_9_ADD						 309

#define NAME1_OFFSET_10_ADD						 310
#define NAME2_OFFSET_10_ADD						 311
#define NAME3_OFFSET_10_ADD						 312
#define NAME4_OFFSET_10_ADD						 313
#define NAME5_OFFSET_10_ADD						 314

#define NAME1_OFFSET_11_ADD						 315
#define NAME2_OFFSET_11_ADD						 316
#define NAME3_OFFSET_11_ADD						 317
#define NAME4_OFFSET_11_ADD						 318
#define NAME5_OFFSET_11_ADD						 319

#define NAME1_OFFSET_12_ADD						 320
#define NAME2_OFFSET_12_ADD						 321
#define NAME3_OFFSET_12_ADD						 322
#define NAME4_OFFSET_12_ADD						 323
#define NAME5_OFFSET_12_ADD						 324
#define N_HI_ADD                                 550


extern uint32_t range;
extern uint16_t passward;
extern uint16_t factory_passward;
extern uint16_t new_passward;
extern uint8_t  message;
extern uint8_t  entry;
extern uint8_t  Fault_Flash_ON;
extern uint8_t  Fault_Flash_ON_update;


extern uint8_t   Use_AL;
extern uint8_t   Set_Point;
extern float64_t Set_point_data;
extern uint32_t  Hysterisis_data;
extern uint8_t   AL_High_Logic;
extern uint8_t   AL_Latch;
extern uint32_t  Time_delay_data;
extern uint8_t	 Set_point_Negative;

/************SERIAL*****************************/
extern uint8_t  Channel_Enable_data;
extern uint8_t  Slave_ID_data;
extern uint8_t  Read_Register_data;
extern uint16_t PV_Address_data;
extern uint8_t  Device_ID_data;
extern uint8_t  Baudrate_Count;
extern uint8_t  Parity_Count;
extern uint8_t  Stop_bit_Count;

extern uint8_t  Channel_Enable_update;
extern uint8_t  Slave_ID_update;
extern uint8_t  Read_Register_update;
extern uint16_t PV_Address_update;
extern uint8_t  Device_ID_data_update;
extern uint8_t  Baudrate_Count_update;
extern uint8_t  Parity_Count_update;
extern uint8_t  Stop_bit_Count_update;
/************SERIAL*****************************/


/************DISPLAY****************************/
extern uint8_t   dp;
extern uint16_t  gas_no;
extern uint8_t   unit_count;
extern uint8_t   sec_lmp;
extern uint8_t   minute_lmp; 
extern uint8_t   hour_lmp;
extern uint32_t  Fail_Safe_Delay_data;


extern uint8_t   dp_update;
extern uint16_t  gas_no_update;
extern uint8_t   unit_count_update;
extern uint8_t   sec_lmp_update;
extern uint8_t   minute_lmp_update; 
extern uint8_t   hour_lmp_update;
extern uint32_t  Fail_Safe_Delay_data_update;
extern uint8_t   AL_Failsafe_update;
/************DISPLAY*****************************/


/************ALARM*******************************/
/**************************************************/
extern float64_t Set_point1_data;  
extern float64_t Hysterisis1_data; 
extern uint32_t  Time_delay1_data; 
extern uint8_t   Set_point1_Negative;

extern uint8_t   Use_AL1_update;
extern float64_t Set_point1_data_update;
extern float64_t Hysterisis1_data_update; 
extern uint8_t   AL1_High_Logic_update;
extern uint8_t   AL1_Latch_update;
extern uint32_t  Time_delay1_data_update;
extern uint8_t   Set_point1_Negative_update;
/**************************************************/


/**************************************************/ 
extern float64_t Set_point2_data;            
extern float64_t Hysterisis2_data; 
extern uint32_t  Time_delay2_data;  
extern uint8_t   Set_point2_Negative;

extern uint8_t   Use_AL2_update;
extern float64_t Set_point2_data_update;           
extern float64_t Hysterisis2_data_update;
extern uint8_t   AL2_High_Logic_update;
extern uint8_t   AL2_Latch_update;     
extern uint32_t  Time_delay2_data_update;
extern uint8_t   Set_point2_Negative_update; 
/**************************************************/



/**************************************************/ 
extern float64_t Set_point3_data;            
extern float64_t Hysterisis3_data; 
extern uint32_t  Time_delay3_data;  
extern uint8_t   Set_point3_Negative;

extern uint8_t   Use_AL3_update;
extern float64_t Set_point3_data_update;           
extern float64_t Hysterisis3_data_update;
extern uint8_t   AL3_High_Logic_update;
extern uint8_t   AL3_Latch_update;     
extern uint32_t  Time_delay3_data_update;
extern uint8_t   Set_point3_Negative_update; 
/**************************************************/


/**************************************************/ 
extern float64_t Set_point4_data;            
extern float64_t Hysterisis4_data; 
extern uint32_t  Time_delay4_data;  
extern uint8_t   Set_point4_Negative;

extern uint8_t   Use_AL4_update;
extern float64_t Set_point4_data_update;           
extern float64_t Hysterisis4_data_update;
extern uint8_t   AL4_High_Logic_update;
extern uint8_t   AL4_Latch_update;     
extern uint32_t  Time_delay4_data_update;
extern uint8_t   Set_point4_Negative_update; 
/**************************************************/


/**************************************************/
extern uint8_t   Buzzer_ON;    
extern uint32_t  Fail_Safe_Delay_data;
extern uint32_t  Fail_Safe_Delay_data_update;

extern uint8_t   Buzzer_ON_update;   
extern uint8_t   AL_Failsafe_update;
/**************************************************/
/************ALARM*******************************/


/************OUTPUT******************************/
extern float64_t Output_Low_data ;
extern float64_t Output_High_data;
extern uint8_t Output_High_Negative;
extern uint8_t Output_Low_Negative ;
extern uint8_t Output_Type;
extern uint8_t  Scale_Type;
extern uint16_t correction_factor_3_7mA;
extern uint16_t correction_factor_3_8mA;
extern uint16_t correction_factor_4mA ;
extern uint16_t correction_factor_8mA ;
extern uint16_t correction_factor_12mA;
extern uint16_t correction_factor_16mA;
extern uint16_t correction_factor_20mA;
extern uint16_t correction_factor_21mA;
extern uint16_t correction_factor_23mA;


extern float64_t Output_Low_data_update ;
extern float64_t Output_High_data_update;
extern uint8_t Output_High_Negative_update;
extern uint8_t Output_Low_Negative_update;
extern uint8_t Output_Type_update;
extern uint8_t  Scale_Type_update;
extern uint16_t correction_factor_3_8mA_update;
extern uint16_t correction_factor_4mA_update ;
extern uint16_t correction_factor_8mA_update ;
extern uint16_t correction_factor_12mA_update;
extern uint16_t correction_factor_16mA_update;
extern uint16_t correction_factor_20mA_update;
extern uint16_t correction_factor_21mA_update;
/************OUTPUT******************************/

extern uint16_t address_val;



void wait_for_eeprom(void);
void eeprom_write_enable(void);
void eeprom_write_disable(void);

void write_byte_memory(uint16_t address, uint8_t data);
void write_2byte_memory(uint16_t address, uint16_t data);
uint8_t read_byte_memory(uint16_t address);
uint16_t read_2byte_memory(uint16_t address);

void send_factory_eeprom_values(void);
void DP_change_factory_values(void);
void get_initial_eeprom_values(void);
void update_values(void);


#endif /*EEPROM_SPI_H_*/
