#ifndef UART_INIT_H_
#define UART_INIT_H_

//#define OSCILLATOR_FREQUENCY 4000000 
#define OSCILLATOR_FREQUENCY  12000000

extern unsigned char UART_RX_buf[100];      //Receive Buffer
extern unsigned char UART_TX_Buffer[100];   //Transmit Buffer


extern unsigned char UART_rcv_count; 
extern unsigned char timeout; 
//extern unsigned char timeout_temp;
extern uint16_t timeout_temp;
extern unsigned char run_timer;
extern unsigned char volatile timeout_flag;
 

//void mSetRS485_RTSHigh();
//void mSetRS485_RTSLow ();
void UARTInit(void);


#endif /*UART_INIT_H_*/
