#ifndef DECODE_SLAVE_H_
#define DECODE_SLAVE_H_


extern const unsigned char auchCRCHi_exp[];
extern const unsigned char auchCRCLo_exp[];

#define MODBUS_READ_HOLDING_REGISTERS     0x03
#define MODBUS_READ_INPUT_REGISTERS       0x04
#define MODBUS_WRITE_HOLDING_REGISTERS    0x06

#define RS485_RTSHigh   P1OUT |= 0x04;
#define RS485_RTSLow    P1OUT &= ~(0x04);


extern unsigned int  data_received;
extern uint8_t ReceivedByteCount;
extern uint8_t ComFail;
extern uint8_t ComFail_Count;
extern uint8_t Com_data_recv;
extern uint8_t Query_sent;



void DecodeSlave(void);






#endif /*DECODE_SLAVE_H_*/
