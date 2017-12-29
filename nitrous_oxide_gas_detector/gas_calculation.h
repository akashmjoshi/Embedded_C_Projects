#ifndef GAS_CALCULATION_H_
#define GAS_CALCULATION_H_

extern uint8_t open_error;
extern uint8_t under_error;
extern uint8_t over_error;
extern uint8_t undefined_error;
extern uint8_t comfail_error;


extern float64_t process_value;
extern uint8_t Process_Negative;

extern float64_t Input4_20mA;
extern uint16_t Input4_20;
extern uint8_t Start_Failsafe_Timer;
extern float64_t process_range;

void Handle_Gas_Calculation(void);



#endif /*GAS_CALCULATION_H_*/
