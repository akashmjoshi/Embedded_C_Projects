#include "system.h"

uint8_t scanned_key    = 0;
uint8_t key_code       = 0;
uint8_t internal_count = 0;
uint8_t count_delay    = 0;
uint8_t first_enter    = 0;
uint8_t first_enter2   = 0;
uint8_t Remote_Incr    = 0;


void Key_Interrupt_Init(void)
{ 
	P1IES |= BIT1;
	P1IE  |= BIT1;
}


void scan_ir_keys(void)
{
	switch(scanned_key)
	{
		case 32:				
		case 33:  //SHIFT KEY
        case 34:
                Leds =  KEY_LED;
	    	    Backlit_damp  = 1;
	    	    Timeout_Count = 1;
                key_pressed   = 1;

		         GF.Shift_Button_Flag = 1;
			    break;
		
		case 48:		
		case 49:   //INCR KEY
                Leds =  KEY_LED;
                Backlit_damp   = 1;
                key_pressed    = 1;
		        Timeout_Count  = 1;
		        Remote_Incr = 1;
		        
                GF.Incr_Button_Flag = 1;

				break;
		
		case 8:		
		case 9:      //NEXT KEY

                Leds =  KEY_LED;
                Backlit_damp  = 1;
                key_pressed    = 1;
		        Timeout_Count  = 1;
		        
		        if((!GF.Sec_3_Flag)||(GF.Show_Conc_Flag))
			    {
			 	   first_enter       = 1; 
			       GF.Start_Flag     = 0;
			    } 			    
				else if((GF.Show_Conc_Flag == 0) && (first_enter == 0))
                GF.Next_Button_Flag = 1;   

				break;												
	}	
	
}


#pragma vector = PORT1_VECTOR
interrupt void PORT1_ISR(void)
{
	if(P1IE & 0x02)
	P1IE &= ~0x02;
	
	TimerA_off_count = 0;
	TACCTL0 |= CCIE;
	
	if(internal_count != 30)
	{
	 internal_count = 0;
     count_delay    = 0;
     scanned_key    = 0;
 	 key_code       = 0;
	}
    _BIS_SR(GIE);          
}





//void Key_Interrupt_Init(void)
//{
//	WDTCTL = WDTPW + WDTHOLD;  
//	P1IES |= BIT1;
//	P1IE  |= BIT1;
//	_BIS_SR(GIE);
//}
//
//void scan_ir_keys(void)
//{
//	internal_count = 0;
//	WDTCTL = WDTPW + WDTHOLD;   
//  
//	switch(scanned_key)
//	{
//		case 0:
//		        scanned_key    = 0;
//				key_code       = 0;
//				break;
//		
//				
//		case 16:  //SHIFT KEY
//			    P3OUT |= BIT2;   //key led
//		        key_pressed    = 1;
//		        Timeout_Count  = 1;
//		        key_code       = 0;
//				scanned_key    = 0;
//				Shift_Routine();
//				break;
//				
//		case 24:   //INCR KEY
//			    P3OUT |= BIT2;   //key led
//		        key_pressed    = 1;
//		        Timeout_Count  = 1;
//		        key_code       = 0;
//				scanned_key    = 0;
//				
//			    if((!GF.Sec_3_Flag)||(GF.Show_Conc_Flag))
//		        {
//			    	 if((Logic.AL1_Blink)&&(Logic.AL1_Latch))
//			    	 {
//			    		Logic.AL1_ACK      = 1;
//					    Logic.AL1_Blink    = 0;
//			    	 }		
//					 else if((Logic.AL2_Blink)&&(Logic.AL2_Latch))
//					 {
//						Logic.AL2_ACK      = 1;
//						Logic.AL2_Blink    = 0;
//				     }
//		        } 
//								
//				Incr_Routine();	
//				break;
//				
//		case 4:      //NEXT KEY
//			    P3OUT |= BIT2;   //key led
//		        key_pressed    = 1;
//		        Timeout_Count  = 1;
//		        key_code       = 0;
//				scanned_key    = 0;
//		        
//			    //if(GF.Show_Conc_Flag)
//			    if((!GF.Sec_3_Flag)||(GF.Show_Conc_Flag))
//			    {
//			 	   first_enter       = 1; 
//			       GF.Start_Flag     = 0;
//			    } 			    
//				else if((GF.Show_Conc_Flag == 0)&&(first_enter == 0))
//				{
//					key_code    = 0;
//					scanned_key = 0;
//					Next_Routine();
//				}
//				break;
//				
//		default:
//		        scanned_key    = 0;
//				key_code       = 0;							
//				
//	}	
//	
//}
//
//
//#pragma vector = PORT1_VECTOR
//interrupt void PORT1_ISR(void)
//{	 
//     internal_count = 0;
//     count_delay    = 0;
//     scanned_key    = 0;
// 	 key_code       = 0;
//    _BIS_SR(GIE);
//     P1IFG &= ~BIT1;
//     P1IE  &= ~BIT1;
//}


