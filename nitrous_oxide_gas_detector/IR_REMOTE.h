#ifndef IR_REMOTE_H_
#define IR_REMOTE_H_

extern uint8_t scanned_key;
extern uint8_t key_code;
extern uint8_t internal_count;
extern uint8_t count_delay;
extern uint8_t first_enter;
extern uint8_t first_enter2;
extern uint8_t Remote_Incr;


void Key_Interrupt_Init(void);
void scan_ir_keys(void);

#endif /*IR_REMOTE_H */
