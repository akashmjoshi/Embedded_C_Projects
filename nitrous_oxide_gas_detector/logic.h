#ifndef LOGIC_H_
#define LOGIC_H_

extern struct Logic_Flags
{
  unsigned char AL1_Blink    :1;
  unsigned char AL2_Blink    :1;
  unsigned char AL3_Blink    :1;
  unsigned char AL4_Blink    :1;
  
  unsigned char AL1          :1;
  unsigned char AL2          :1;
  unsigned char AL3          :1;
  unsigned char AL4          :1;	
  
  unsigned char AL1_HI_Logic :1;
  unsigned char AL2_HI_Logic :1;
  unsigned char AL3_HI_Logic :1;
  unsigned char AL4_HI_Logic :1;
   
  unsigned char AL1_Latch    :1;
  unsigned char AL2_Latch    :1; 
  unsigned char AL3_Latch    :1;
  unsigned char AL4_Latch    :1; 
  
  unsigned char AL1_ACK      :1;
  unsigned char AL2_ACK      :1;
  unsigned char AL3_ACK      :1;
  unsigned char AL4_ACK      :1;

  unsigned char start_relay1  :1;
  unsigned char start_relay2  :1;
  unsigned char start_relay3  :1;
  unsigned char start_relay4  :1;
  
  unsigned char start_flashing   :1;
  unsigned char start_flashing2  :1;
  unsigned char start_flashing3  :1;
  unsigned char start_flashing4  :1;
  
  unsigned char AL_Failsafe   :1;  
  unsigned char backlit       :1;

 }Logic;


extern unsigned char Status_Flag1;
extern unsigned char Status_Flag2;
extern uint16_t Buzzer_counter;
extern uint8_t  Buzzer_Toggle;
extern uint8_t Leds;
extern uint8_t Power_on;
extern uint8_t key_pressed;
extern uint8_t Timeout_Count1;
extern uint16_t one_sec_counter;
extern uint16_t remote_counter;
extern uint16_t Key_Counter;
extern uint16_t Flashing_Counter;
extern uint8_t  Flash_Toggle;
extern uint8_t  System_Chk_Flag;
extern uint16_t System_Chk_counter;
extern uint16_t System_Chk_counter1;
extern uint8_t  Show_Peak;
extern uint8_t  Show_Clear_Peak; 
extern uint16_t Peak_Counter;
extern uint16_t Peak_Counter1;
extern uint16_t Peak_Counter2;
extern uint16_t Peak_Counter3;
extern uint8_t  damp_count;

extern uint8_t query_no;
extern uint16_t TimerA_off_count;


extern uint16_t relayy1_counter;
extern uint16_t relayy2_counter;
extern uint16_t relayy3_counter;
extern uint16_t relayy4_counter;

extern uint16_t relayy1;
extern uint16_t relayy2;
extern uint16_t relayy3;
extern uint16_t relayy4;

extern uint8_t start_timer1;
extern uint8_t start_timer2;
extern uint8_t start_timer3;
extern uint8_t start_timer4;

extern float64_t Set_point1_temp;   
extern float64_t Set_point2_temp;
extern float64_t Set_point3_temp;   
extern float64_t Set_point4_temp;

extern uint8_t Buzzer_ack;
extern uint8_t Buzzer_start;
extern uint8_t Buzzer_Flag;

extern uint8_t Buzzer1_ack;
extern uint8_t Buzzer2_ack;
extern uint8_t Buzzer3_ack;
extern uint8_t Buzzer4_ack;

extern uint8_t Buzzer1_start;
extern uint8_t Buzzer2_start;
extern uint8_t Buzzer3_start;
extern uint8_t Buzzer4_start;

extern volatile uint8_t logic_off;


void logic(void);
void logic1(void);
void Logic_Flags_Reset(void);


#endif /*LOGIC_H_*/
