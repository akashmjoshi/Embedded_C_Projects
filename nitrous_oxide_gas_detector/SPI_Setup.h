#ifndef SPI_SETUP_H_
#define SPI_SETUP_H_

#define OFIFG_OFF					0xFD
#define UCSWRST_OFF					0xFE
#define UCB1TXIE_OFF				0xF7
#define EEPROM_NOPROT 				0x00
#define EEPROM_READ_CMD 			0x03
#define EEPROM_WRITE_CMD 			0x02
#define EEPROM_WRITE_ENABLE  		0x06
#define EEPROM_WRITE_DISABLE		0x04
#define MAX_EEPROM_STRING_SIZE		6u
#define EEPROM_WRITE_STATUS_REG 	0x01


extern ubool_t eeprom_action_complete;
extern uint8_t eeprom_data_size;
extern uint8_t *eeprom_data_pointer;
extern uint8_t *eeprom_receive_pointer;
extern uint8_t data_to_eeprom_buffer[MAX_EEPROM_STRING_SIZE];
extern uint8_t data_from_eeprom_buffer[MAX_EEPROM_STRING_SIZE];

void setup_spi_port(void);


#endif /*SPI_SETUP_H_*/

