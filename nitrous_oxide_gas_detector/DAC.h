#ifndef DAC_H_
#define DAC_H_


#define CLOCK_SEL					P5SEL
#define CLOCK_DIR					P5DIR
#define CLOCK_OUT					P5OUT
#define CLOCK_PIN					0x08

#define DATA_SEL					P5SEL
#define DATA_DIR					P5DIR
#define DATA_OUT					P5OUT
#define DATA_PIN					0x02
                                 
#define LATCH1_SEL					P3SEL
#define LATCH1_DIR					P3DIR
#define LATCH1_OUT	 				P3OUT                                  
#define LATCH1_PIN	 				0x08                                  
                        
#define LATCH2_SEL					P5SEL
#define LATCH2_DIR					P5DIR
#define LATCH2_OUT	 				P5OUT                                  
#define LATCH2_PIN	 				0x01  

#define LATCH1						0x00
#define LATCH2						0x01
#define LATCH3						0x02

#define NOP_REG						0x00
#define DATA_REG					0x01
#define READBACK_REG				0x02
#define CONTROL_REG					0x55
#define RESET_REG					0x56

#define READ_FROM_STATUS_REG		0x0000
#define READ_FROM_DATA_REG			0x0001
#define READ_FROM_CONTROL_REG		0x0002

#define CLR							0x8000
#define OVER_RNG					0x4000
#define RES_SET						0x2000
#define OUTPUT_EN					0x1000
#define	DAISY_EN					0x0008

#define VOLTAGE_0_5V 				0x0000
#define VOLTAGE_0_10V 				0x0001
#define VOLTAGE_5_5V 				0x0002
#define VOLTAGE_10_10V 				0x0003
#define CURRENT_4_20mA 				0x0005
#define CURRENT_0_20mA 				0x0006
#define CURRENT_0_24mA 				0x0007


#define WARMUP_CURRENT_OUTPUT			3.8
#define OPEN_CURRENT_OUTPUT				3.7
#define HIGH_CURRENT_OUTPUT				21.0

#define NORMAL_WORKING_MODE  ( (!logic_off) && (!Power_on) )

//extern float64_t current_output;
//extern float64_t voltage_output;

extern float32_t current_output;
extern float32_t voltage_output;
extern uint16_t  N_HI;
extern float64_t Test_data;
extern uint8_t Test_data_Negative;

void DAC_Output(void);
//void DAC_Output1(void);
void write_to_register(uint8_t address, uint16_t value);

#endif /*DAC_H_*/
