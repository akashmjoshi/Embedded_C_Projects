#ifndef TIMER_B_H_
#define TIMER_B_H_


#define NEXT_KEY   !(P2IN & 0x01)
#define SHIFT_KEY  !(P2IN & 0x02)
#define INCR_KEY   !(P2IN & 0x04)
#define ACK_KEY    !(P1IN & 0x01)

#define RL1_STATUS  0x08
#define LED1_STATUS 0x04
#define RL2_STATUS  0x02
#define LED2_STATUS 0x01
//#define HTY_STATUS  0x01


#define AL1_LED  0x40
#define AL2_LED  0x20
#define AL3_LED  0x10
#define AL4_LED  0x08
#define HTY_LED  0x04
#define PRG_LED  0x02
#define KEY_LED  0x01
#define COM_LED  0x80


#define AL1_RELAY_ON          P2OUT &= ~0x10;
#define AL2_RELAY_ON          P2OUT &= ~0x20;
#define AL3_RELAY_ON          P1OUT &= ~0x10;
#define AL4_RELAY_ON          P6OUT &= ~0x40;
#define FAILSAFE_RELAY_ON     P6OUT &= ~0x80;

#define AL1_RELAY_OFF         P2OUT |= 0x10;
#define AL2_RELAY_OFF         P2OUT |= 0x20; 
#define AL3_RELAY_OFF         P1OUT |= 0x10;
#define AL4_RELAY_OFF         P6OUT |= 0x40;
#define FAILSAFE_RELAY_OFF    P6OUT |= 0x80;


//#define RELAY1   0x10
//#define RELAY2   0x20
//#define FAILSAFE_RELAY  0x10


#define LED_PORT	  			P1OUT
#define LED_SCLK_PIN_NO 			5
#define LED_RCLK_PIN_NO 			6
#define LED_SERIAL_PIN_NO 			7


void Timer_B_init(void);
void led_display(unsigned int led_glow);

#endif /*TIMER_B_H_*/
