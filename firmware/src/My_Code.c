#include "My_Code.h"

uint8_t SendArray[2] = {0xAA, 0x0F};
uint8_t ReadArray[2];
uint8_t PayloadToSendArray[5] = {'A', 'B', 'C', 'D', 'E'}; //{0xAA, 0x00, 0x01, 0x02, 0x03};
uint8_t ToggleState = 0;
static uint8_t TempRegToRead = 0;
static uint8_t TempRegToWrite = 0;
uint8_t TempStatus = 0;

void MyTaskFunction()
{
  uint8_t tempLogicHolder = 0;
  uint8_t ReadByte = 0;
              //void PLIB_PORTS_Set(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_DATA_TYPE value, PORTS_DATA_MASK mask)
            //PLIB_PORTS_PinGet(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_BIT_POS bitPos);
            //PLIB_PORTS_Read(PORTS_MODULE_ID index, PORTS_CHANNEL channel)
            //if(0x80 & PLIB_PORTS_Read(PORTS_ID_0, PORT_CHANNEL_A))
  
            if(GET_SW1)
            {
                SS_HI;
                Init_NRF24L();
                D2_ON;
                while(GET_SW1)
                {
                    
                }
                //PLIB_PORTS_Set(PORTS_ID_0, PORT_CHANNEL_A, 0x01, 0x01);
                //PLIB_PORTS_Set(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_DATA_TYPE value, PORTS_DATA_MASK mask)
            }
            else
            {
                //unsigned char Read_Register(unsigned char RegisterNumber, unsigned char * RecieveArray, unsigned char NumOfBytesToRead)
                
                //SS_TOGGLE;
                //D2_OFF;

                //PLIB_PORTS_Clear(PORTS_ID_0, PORT_CHANNEL_A, 0x01);
            }
            
            if(GET_SW3)
            {
                //D6_TOGGLE
                Read_Register(0, ReadArray, 1);
                Read_Register(1, ReadArray, 1);
                Read_Register(2, ReadArray, 1);
                Read_Register(3, ReadArray, 1);
                Read_Register(4, ReadArray, 1);
                //TempStatus = Read_Status();
                TempStatus = 6;
                //DRV_USART0_WriteByte(TempStatus);
                //Read_Register(unsigned char RegisterNumber, unsigned char * RecieveArray, unsigned char NumOfBytesToRead)
                D3_ON;
                while(GET_SW3)
                {
                }
            }
            else
            {
                //D3_OFF;
            }
            
            if(GET_SW4)
            {
                D4_ON;
                //D8_ON;
                //PLIB_USART_TransmitterByteSend(USART_ID_1, 0xAA);
                //DRV_USART0_WriteByte(const uint8_t byte)
                //unsigned char SendNewPayload(unsigned char * PayloadArrayToSend, unsigned char NumberOfBytesToSend)
                //DRV_SPI0_BufferAddWriteRead(SendArray, ReadArray, 2);
                SS_HI;
                DRV_USART0_WriteByte(0xAA);
                Clear_NRF_Int_Flags();
                //DRV_USART0_ReceiverBufferIsEmpty(void)
                //DRV_USART0_ReadByte(void)
#if 0
                while(DRV_USART0_ReceiverBufferIsEmpty())
                {
                    
                }
                
                D7_ON;
                ReadByte = DRV_USART0_ReadByte();
                D6_ON;
#endif
                if(0xAA == ReadByte)
                {
                    D5_ON;
                }
                else
                {
                    
                }
                
                while(GET_SW4)
                {
                }
                //D8_ON;
            }
            else
            {
                D4_OFF;
            }
            
            if(GET_SW5)
            {
                D5_ON;
                SendNewPayload(PayloadToSendArray, 5);
                CE_ON;
                //Delay_ms(1);
                //CE_OFF;
                while(GET_SW5)
                {

                }
                CE_OFF;
            }
            else
            {
                ToggleState = 0;
                //D5_OFF;
            }
  
            //if(GET_EXT_INT3)
            //{
            //    D2_ON;
            //}
            //else
            //{
            //    D3_ON;
            //}
          
#if 0
            if(PLIB_PORTS_PinGet(PORTS_ID_0, PORT_CHANNEL_A, 0x80))
            {
                PLIB_PORTS_Clear(PORTS_ID_0, PORT_CHANNEL_A, 0x01);
            }
            else
            {
                PLIB_PORTS_Set(PORTS_ID_0, PORT_CHANNEL_A, 0x01, 0x01);
            }
#endif
            
            //PLIB_PORTS_Clear(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_DATA_MASK clearMask)
            //PLIB_PORTS_Clear(PORTS_ID_0, PORT_CHANNEL_A, 0x01);
            
            
}

//GetSetInterruptFlag(uint8_t FlagNumber, uint8_t SetNotGet, uint8_t ValueToSet)
void MySDelay(unsigned int Delay)
{
    GetSetInterruptFlag(1, 1, 0);

    while(Delay > GetSetInterruptFlag(1, 0, 0))
    {
    }
    
}