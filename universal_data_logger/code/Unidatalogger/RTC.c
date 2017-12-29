#include "system.h"

uint8_t data_write[5] = {0x00, 0x00, 0x00, 0x00};
uint8_t data_read[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};


void write_RTC(uint8_t address, uint8_t data)
{
	TI_USCI_I2C_transmitinit(0x68,0x12);  	// init transmitting with USCI 
	while (TI_USCI_I2C_notready());         // wait for bus to be free
	data_write[0] = address;
	data_write[1] = data;
	TI_USCI_I2C_transmit(2,data_write);     // start transmitting
    while (TI_USCI_I2C_notready());         // wait for bus to be free
}

void read_RTC()
{
	uint8_t temp1 = 0, temp2 = 0;
	uint8_t array[1] = {0x00};
	
	TI_USCI_I2C_transmitinit(0x68,0x12);  	  // init transmitting with 
    while ( TI_USCI_I2C_notready() );         // wait for bus to be free
    TI_USCI_I2C_transmit(1,array);       	  // start transmitting
    while ( TI_USCI_I2C_notready() );         // wait for bus to be free
  
    TI_USCI_I2C_receiveinit(0x68,0x12);   	  // init receiving with USCI 
    while ( TI_USCI_I2C_notready() );         // wait for bus to be free
    TI_USCI_I2C_receive(7,data_read);
    while ( TI_USCI_I2C_notready() );         // wait for bus to be free
  
    temp1 = data_read[0] & 0x0F;
	temp2 = data_read[0] & 0xF0;
	temp2 = temp2 >> 4;
	Seconds = (temp2 *10) + temp1;  
	
	temp1 = data_read[1] & 0x0F;
	temp2 = data_read[1] & 0xF0;
	temp2 = temp2 >> 4;
	Minutes = (temp2 *10) + temp1;  
	
	temp1 = data_read[2] & 0x0F;
	temp2 = data_read[2] & 0x30;
	temp2 = temp2 >> 4;
	Hours = (temp2 * 10) + temp1;  
	
	Time_Format = data_read[2] & 0x40;
	
	Time_Stamp = data_read[2] & 0x20;
	
	Day = data_read[3] & 0x07;
	
	temp1 = data_read[4] & 0x0F;
	temp2 = data_read[4] & 0x30;
	temp2 = temp2 >> 4;
	Date = (temp2 *10) + temp1; 
	
	temp1 = data_read[5] & 0x0F;
	temp2 = data_read[5] & 0x10;
	temp2 = temp2 >> 4;
	Month = (temp2 *10) + temp1; 
	
	temp1 = data_read[6] & 0x0F;
	temp2 = data_read[6] & 0xF0;
	temp2 = temp2 >> 4;
	Year = (temp2 * 10) + temp1;  
	//Year = 2000 + Year;
} 

void displayRTC()
{
    
	display(Hours,8,0,2);
	display(Minutes,11,0,2);
	display(Seconds,14,0,2);
	Send_str(":", 10);
	Send_str(":", 13);
	
	
	display(Date,0,0,2);
	display(Month,3,0,2);
	display(Year,6,0,2);
	Send_str("/", 2);
	Send_str("/", 5);
	
	UpdateLcd();
	
} 

unsigned char DecimalToHex(unsigned char decValue)
{
	uint8_t temp1 = 0;
	uint8_t temp2 = 0;
	uint8_t hexValue = 0;
	
	temp1 = decValue/10;
	temp2 = decValue%10;
	
	hexValue = ((temp1 << 4) | temp2);
	
	return hexValue;
}
