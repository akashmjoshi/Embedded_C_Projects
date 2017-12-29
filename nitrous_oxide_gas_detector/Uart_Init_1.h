#ifndef UART_INIT_1_H_
#define UART_INIT_1_H_

extern unsigned char UART1_RX_buf[100];   //Receive Buffer
extern unsigned char UART1_TX_Buf[100];   //Transmit Buffer
extern unsigned char UART1_rcv_count;
extern unsigned char chTemp1;
 
extern unsigned char timeout1; 
extern unsigned char run_timer1;
extern unsigned char volatile timeout_flag1;


extern unsigned char StartCommCounterFlag;
extern uint16_t StartCommCounter;


void UARTInit_1(void);


#endif /*UART_INIT_1_H_*/
