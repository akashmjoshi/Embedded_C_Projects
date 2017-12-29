#ifndef SEND_REQUEST_H_
#define SEND_REQUEST_H_

extern uint16_t PV_address;

void send_request(void);


void modbusSendUARTPacket ( unsigned char length);
unsigned int modrtuChecksum ( unsigned char *chkbuf, unsigned char len );

#endif /*SEND_REQUEST_H_*/
