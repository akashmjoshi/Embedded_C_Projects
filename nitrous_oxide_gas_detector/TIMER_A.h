#ifndef TIMER_A_H_
#define TIMER_A_H_

extern uint16_t Logic_counter;
extern uint8_t damping_counter;
extern uint8_t  toggle2;
extern uint16_t toggle2_counter;
extern uint16_t update_counter;
extern uint16_t update_counter1;
//extern uint8_t lmp_counter;

extern uint16_t Failsafe_Counter;
extern uint16_t Failsafe_Counter1;
extern uint8_t Fail_show;
extern uint8_t Power_on1;

 extern uint8_t  sec_count;
 extern uint8_t  minute_count;
 extern uint8_t  hour_count;
 
 extern uint8_t Data_captured;
  
void Timer_A_init(void);

#endif /*TIMER_A_H_*/
