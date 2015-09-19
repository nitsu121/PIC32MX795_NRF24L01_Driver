/* 
 * File:   My_Code.h
 * Author: Justin.Flor
 *
 * Created on September 5, 2015, 11:24 AM
 */

#ifndef MY_CODE_H
#define	MY_CODE_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "app.h"    
//#include "system_definitions.h"
#include "NRF24L01_DRIVER.h"
#include "system_interrupt.h"
    
    
#define GET_SW1 (!(0x80 & PLIB_PORTS_Read(PORTS_ID_0, PORT_CHANNEL_A)))
#define GET_SW3 (!(0x80 & PLIB_PORTS_Read(PORTS_ID_0, PORT_CHANNEL_D)))
#define GET_SW4 (!(0x0100 & PLIB_PORTS_Read(PORTS_ID_0, PORT_CHANNEL_D)))
#define GET_SW5 (!(0b0010000000000000 & PLIB_PORTS_Read(PORTS_ID_0, PORT_CHANNEL_D)))
    
#define GET_EXT_INT3 (0b0100000010000000 & PLIB_PORTS_Read(PORTS_ID_0, PORT_CHANNEL_A))

#define D2_ON PLIB_PORTS_Set(PORTS_ID_0, PORT_CHANNEL_A, 0x01, 0x01)
#define D2_OFF PLIB_PORTS_Clear(PORTS_ID_0, PORT_CHANNEL_A, 0x01)     
    
#define D3_ON PLIB_PORTS_Set(PORTS_ID_0, PORT_CHANNEL_A, 0x02, 0x02)
#define D3_OFF PLIB_PORTS_Clear(PORTS_ID_0, PORT_CHANNEL_A, 0x02)  

#define D4_ON PLIB_PORTS_Set(PORTS_ID_0, PORT_CHANNEL_A, 0b0000001000000000, 0b0000001000000000)
#define D4_OFF PLIB_PORTS_Clear(PORTS_ID_0, PORT_CHANNEL_A, 0b0000001000000000)     
    
#define D5_ON PLIB_PORTS_Set(PORTS_ID_0, PORT_CHANNEL_A, 0b0000010000000000, 0b0000010000000000)
#define D5_OFF PLIB_PORTS_Clear(PORTS_ID_0, PORT_CHANNEL_A, 0b0000010000000000)  
    
#define D6_ON PLIB_PORTS_Set(PORTS_ID_0, PORT_CHANNEL_A, 0b00010000, 0b00010000)
#define D6_OFF PLIB_PORTS_Clear(PORTS_ID_0, PORT_CHANNEL_A, 0b00010000)     
#define D6_TOGGLE PLIB_PORTS_Toggle(PORTS_ID_0, PORT_CHANNEL_A,  0b00010000);   
    
#define D7_ON PLIB_PORTS_Set(PORTS_ID_0, PORT_CHANNEL_A, 0b00100000, 0b00100000)
#define D7_OFF PLIB_PORTS_Clear(PORTS_ID_0, PORT_CHANNEL_A, 0b00100000)  
#define D7_TOGGLE PLIB_PORTS_Toggle(PORTS_ID_0, PORT_CHANNEL_A,  0b00100000);
    
#define D8_ON PLIB_PORTS_Set(PORTS_ID_0, PORT_CHANNEL_A, 0b001000000, 0b001000000)
#define D8_OFF PLIB_PORTS_Clear(PORTS_ID_0, PORT_CHANNEL_A, 0b001000000) 
#define D8_TOGGLE PLIB_PORTS_Toggle(PORTS_ID_0, PORT_CHANNEL_A,  0b001000000);
    
    
uint8_t GetSetInterruptFlag(uint8_t FlagNumber, uint8_t SetNotGet, uint8_t ValueToSet);    
    
    
void MyTaskFunction(void);
void MySDelay(unsigned int Delay);

#ifdef	__cplusplus
}
#endif

#endif	/* MY_CODE_H */

