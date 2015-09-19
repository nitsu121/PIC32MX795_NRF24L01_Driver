/* 
 * File:   NRF24L01_DRIVER.h
 * Author: Justin.Flor
 *
 * Created on September 5, 2015, 3:09 PM
 */

#ifndef NRF24L01_DRIVER_H
#define	NRF24L01_DRIVER_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "app.h"    
    
//NRF COMMANDS
#define R_REGISTER 0
#define W_REGISTER 0b00100000

#define R_RX_PAYLOAD 0b01100001
#define W_TX_PAYLOAD 0b10100000
#define FLUSH_TX 0b11100001
#define FLUSH_RX 0b11100010
#define REUSE_TX_PL 0b11100011
#define NOP 0b11111111
//NRF REGISTERS
#define CONFIG 0
#define EN_AA 1
#define EN_RXADDR 2
#define SETUP_AW 3
#define SETUP_RETR 4
#define RF_CH 5
#define RF_SETUP 6
#define STATUS 7
#define OBSERVE_TX 8
#define CD 9
#define RX_ADDR_P0 0x0A
#define RX_ADDR_P1 0x0B
#define RX_ADDR_P2 0x0C
#define RX_ADDR_P3 0x0D
#define RX_ADDR_P4 0x0E
#define RX_ADDR_P5 0x0F
#define TX_ADDR 0x10
#define RX_PW_P0 0x11
#define RX_PW_P1 0x12
#define RX_PW_P2 0x13
#define RX_PW_P3 0x14
#define RX_PW_P4 0x15
#define RX_PW_P5 0x16
#define FIFO_STATUS 0x17

#define SS_LOW PLIB_PORTS_Clear(PORTS_ID_0, PORT_CHANNEL_F, 0b0001000000000000);
#define SS_HI PLIB_PORTS_Set(PORTS_ID_0, PORT_CHANNEL_F, 0b0001000000000000, 0b0001000000000000) 
#define SS_TOGGLE PLIB_PORTS_Toggle(PORTS_ID_0, PORT_CHANNEL_F,  0b0001000000000000);

    
//#define D2_ON PLIB_PORTS_Set(PORTS_ID_0, PORT_CHANNEL_A, 0x01, 0x01)
    //#define D2_ON PLIB_PORTS_Set(PORTS_ID_0, PORT_CHANNEL_G, 0x80, 0x80)
    //PLIB_PORTS_Clear(PORTS_ID_0, PORT_CHANNEL_G, 0x80);
#define CE_OFF PLIB_PORTS_Clear(PORTS_ID_0, PORT_CHANNEL_A, 0b1000000000000000)
#define CE_ON PLIB_PORTS_Set(PORTS_ID_0, PORT_CHANNEL_A, 0b1000000000000000, 0b1000000000000000)

void Init_NRF24L(void);
unsigned char Read_Register(unsigned char RegisterNumber, unsigned char * RecieveArray, unsigned char NumOfBytesToRead);
unsigned char Write_Register(unsigned char RegisterNumber, unsigned char * SendArray, unsigned char * RecievedArray, unsigned char NumOfBytesToRead);
unsigned char Send_Last_Payload(unsigned char NumberOfTimesToSend);
unsigned char Read_Status(void);
unsigned char Flush_Tx(void);
unsigned char Flush_RX(void);
unsigned char SendNewPayload(unsigned char * PayloadArrayToSend, unsigned char NumberOfBytesToSend);
void ModWriteRegister(unsigned char ByteOne, unsigned char ByteTwo);
void Clear_NRF_Int_Flags(void);
#ifdef	__cplusplus
}
#endif

#endif	/* NRF24L01_DRIVER_H */

