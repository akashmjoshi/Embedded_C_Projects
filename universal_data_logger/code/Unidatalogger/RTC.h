#ifndef RTC_H_
#define RTC_H_



#define SUNDAY		0x01
#define MONDAY		0x02
#define TUESDAY		0x03
#define WEDNESDAY	0x04
#define THURSDAY	0x05
#define FRIDAY		0x06
#define SATURDAY	0x07

#define JANUARY		0x01
#define FEBRUARY	0x02
#define MARCH		0x03
#define APRIL		0x04
#define MAY			0x05
#define JUNE		0x06
#define JULY		0x07
#define AUGUST		0x08
#define SEPTEMBER	0x09
#define OCTOBER		0x0A
#define NOVEMBER	0x0B
#define DECEMBER	0x0C

#define AM_STAMP	0x00
#define PM_STAMP	0x20

#define HOUR_24_FORMAT		0x00
#define HOUR_12_FORMAT		0x40

#define SEC_REG_ADDRS       		0x00
#define MIN_REG_ADDRS       		0x01
#define HOUR_REG_ADDRS		 		0x02
#define DAY_REG_ADDRS        		0x03
#define DATE_REG_ADDRS  			0x04
#define MONTH_REG_ADDRS        		0x05
#define YEAR_REG_ADDRS  			0x06

unsigned char DecimalToHex(unsigned char decValue);
//void Send_str(int8_t *lcd_temp, uint8_t i);
//void display(uint32_t value, uint8_t pos, uint8_t flash,uint8_t number_of_digits);

//void set_dew(void);
void Clock_Init(void);
void init_ports(void);

void write_RTC(uint8_t address, uint8_t data);
void read_RTC();
void displayRTC();

extern uint8_t Time_Format ;
extern uint8_t Time_Stamp ;
extern uint8_t Seconds ;
extern uint8_t Minutes ;
extern uint8_t Hours ;
extern uint8_t Day ;
extern uint8_t Date;
extern uint8_t Month;
extern uint16_t Year;

#endif /*DISPLAY_H_*/
