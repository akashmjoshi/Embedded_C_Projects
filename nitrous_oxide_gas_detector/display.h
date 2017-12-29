#ifndef DISPLAY_H_
#define DISPLAY_H_

#define NO_DP             0
#define ONE_DP       	  1
#define TWO_DP      	  2
#define THREE_DP     	  3
#define FOUR_DP     	  4

extern struct NameParameters
{
	int8_t Name1[14];
	int8_t Name2[14];
	int8_t Name3[14];
	int8_t Name4[14];
	int8_t Name5[14];
	int8_t Temp_Name[14];
	
}Name_List;


extern unsigned long Modbus_baudrate;
extern uint16_t toggle_counter;


extern uint8_t set_polarity;
extern uint8_t Negative_value;
extern uint8_t Show_Peak1;
extern uint8_t Failsafe_ON;

void Start_up(void);
void display(uint32_t value, uint8_t pos, uint8_t flash,uint8_t number_of_digits);
void display_with_dp(uint8_t pos, float64_t value1, uint8_t dp, uint8_t flash);
void display_with_dp_adv(uint32_t value,uint8_t pos, uint8_t flash,uint8_t number_of_digits);
void display_with_dp_adv1(uint32_t value,uint8_t pos, uint8_t flash,uint8_t number_of_digits,uint8_t dp);


void Start_up1(void);

uint32_t inc_digit(uint32_t num,uint32_t lim);
uint32_t inc_digit1(uint32_t num,uint32_t lim);

void break_digits (uint32_t value);
uint32_t make_digits(void);
void Display_units(unsigned char pos);
void Display_Name(int8_t *lcd_temp, uint8_t i,uint8_t pos);
#endif /*DISPLAY_H_*/


