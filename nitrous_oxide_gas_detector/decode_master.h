#ifndef DECODE_MASTER_H_
#define DECODE_MASTER_H_

typedef struct
{
   unsigned int  address ;
   unsigned int  data;
   unsigned char offset;
   
} MAP_DESC_TYP ;


#define MAX_DATA_ARRAY  50
#define MAX_IP_REG		50
#define MAX_HL_REG		50

#define RS485_RTSHigh_1   P6OUT |=  BIT5;
#define RS485_RTSLow_1    P6OUT &= ~BIT5;



extern unsigned int MainDataArray[MAX_DATA_ARRAY];
extern unsigned char save_data;
extern unsigned char Status_Flag;
extern unsigned char Sending_flag;


void DecodeMaster(void);
void send_data(MAP_DESC_TYP * ptr);
void send_echo(void);
void modbusSendUARTPacket1( unsigned char length);
void modbusReturnException ( unsigned char exception );






#endif /*DECODE_MASTER_H_*/
