

#include "NRF24L01_DRIVER.h"
#include "My_Code.h"


void Clear_NRF_Int_Flags(void)
{
    unsigned char SendArray[2] = {0, 0};
    unsigned char TempStatus = 0;
    
    TempStatus = Read_Status();
    TempStatus = TempStatus & 0xF0;
    SendArray[0] = TempStatus;
    ModWriteRegister(0x20 + 7, SendArray[0]);
}

void Init_NRF24L(void)
{
	  //CE_OFF;
	  //Delay_ms(100);
	  //Write_Register(unsigned char RegisterNumber, unsigned char * SendArray, unsigned char * RecievedArray, unsigned char NumOfBytesToRead)
	  unsigned char SendArray[2] = {0, 0};
	  unsigned char ReadArray[2];
	  //SendArray[0] = 0x52; //0b01010010 
      SendArray[0] = 0x5E;
      //SendArray[0] = 0x00; //0b01110010 // dissable all interupts.
      //DRV_SPI0_BufferAddWriteRead(TempSendArray, TempReadArray, NumOfBytesToRead + 1);
      //ModWriteRegister(unsigned char ByteOne, unsigned char ByteTwo)
      ModWriteRegister(0x20 + 0, SendArray[0]);
      ModWriteRegister(0, SendArray[0]);

	  //Write_Register(0, SendArray, ReadArray, 1); // power up rf mod.
      //DRV_SPI0_BufferAddWriteRead(SendArray, ReadArray, 2);
      
	  //SendArray[0] = 0x00;
      SendArray[0] = 0x01;
      ModWriteRegister(0x20 + 1, SendArray[0]);
	  //Write_Register(1, SendArray, ReadArray, 1); // disable auto ack.
      ModWriteRegister(1, SendArray[0]);
      
      
	  SendArray[0] = 0x01;
      ModWriteRegister(0x20 + 2, SendArray[0]);
      ModWriteRegister(2, SendArray[0]);
	  //Write_Register(2, SendArray, ReadArray, 1); // enable data pipe 0.

	  SendArray[0] = 0x03;
      ModWriteRegister(0x20 + 3, SendArray[0]);
      ModWriteRegister(3, SendArray[0]);

	  //Write_Register(3, SendArray, ReadArray, 1); // use 5 bytes address field width.

      SendArray[0] = 0xFF;
      ModWriteRegister(0x20 + 0x04, SendArray[0]);
      ModWriteRegister(0x04, SendArray[0]);
      
      SendArray[0] = 83;
      ModWriteRegister(0x20 + 0x05, SendArray[0]);
      ModWriteRegister(0x05, SendArray[0]);      
      
	  SendArray[0] = 0x05;
      ModWriteRegister(0x20 + 0x11, SendArray[0]);
      ModWriteRegister(0x11, SendArray[0]);

	  //Write_Register(0x11, SendArray, ReadArray, 1); // data payload widths for pipe0 5 bytes.
      
      
}

void ModWriteRegister(unsigned char ByteOne, unsigned char ByteTwo)
{
    unsigned char OUT = ByteOne;
    unsigned char IN;
    SS_LOW;
   DRV_SPI0_BufferAddWriteRead(&OUT, &IN, 1); 
   OUT = ByteTwo;
   DRV_SPI0_BufferAddWriteRead(&OUT, &IN, 1); 
   SS_HI; 
}

unsigned char Read_Register(unsigned char RegisterNumber, unsigned char * RecieveArray, unsigned char NumOfBytesToRead)
{

	unsigned char ReturnFlag = 0;
	unsigned char TempSendArray[50];
	unsigned char TempReadArray[50];
	unsigned char Counter = 0;
	TempSendArray[0] = RegisterNumber | R_REGISTER;

    SS_LOW;
    DRV_SPI0_BufferAddWriteRead(TempSendArray, TempReadArray, NumOfBytesToRead + 1);
    SS_HI;
	//DSPI_DRV_MasterTransferBlocking(FSL_DSPICOM1, NULL, TempSendArray, TempReadArray, NumOfBytesToRead + 1, 10000);
	ReturnFlag = TempReadArray[0];

	while(NumOfBytesToRead > Counter)
	{
		RecieveArray[Counter] = TempReadArray[Counter + 1];
		Counter++;
	}

	return (ReturnFlag);
}

unsigned char Write_Register(unsigned char RegisterNumber, unsigned char * SendArray, unsigned char * RecievedArray, unsigned char NumOfBytesToRead)
{
	unsigned char ReturnFlag = 0;
	unsigned char TempSendArray[50];
	unsigned char TempReadArray[50];
	unsigned char Counter = 0;
	TempSendArray[0] = RegisterNumber | W_REGISTER;

	while(NumOfBytesToRead > Counter)
	{
		TempSendArray[Counter + 1] = SendArray[Counter];
		Counter++;
	}
    SS_LOW;
    DRV_SPI0_BufferAddWriteRead(TempSendArray, TempReadArray, NumOfBytesToRead + 1);
    SS_HI;
	//DSPI_DRV_MasterTransferBlocking(FSL_DSPICOM1, NULL, TempSendArray, TempReadArray, NumOfBytesToRead + 1, 10000);
	ReturnFlag = TempReadArray[0];

	Counter = 0;

	while(NumOfBytesToRead > Counter)
	{
		RecievedArray[Counter] = TempReadArray[Counter + 1];
		Counter++;
	}

	return (ReturnFlag);
}

unsigned char Send_Last_Payload(unsigned char NumberOfTimesToSend)
{
	unsigned char ReturnFlag = 0;

	return (ReturnFlag);
}

unsigned char Read_Status()
{
	unsigned char ReturnFlag = 0;
	unsigned char ReadArray[2] = {0, 0};

	Read_Register(0x07, ReadArray, 1);
	ReturnFlag = ReadArray[0];
	return (ReturnFlag);
}

unsigned char SendNewPayload(unsigned char * PayloadArrayToSend, unsigned char NumberOfBytesToSend)
{
	unsigned char ReturnFlag = 0;
	unsigned char TempSendArray[50];
	unsigned char TempReadArray[50];
	unsigned char Counter = 0;

	Flush_Tx();

	TempSendArray[0] = W_TX_PAYLOAD;

	while(NumberOfBytesToSend > Counter)
	{
		TempSendArray[Counter + 1] = PayloadArrayToSend[Counter];
		Counter++;
	}

    SS_LOW;
    DRV_SPI0_BufferAddWriteRead(TempSendArray, TempReadArray, NumberOfBytesToSend + 1);
    SS_HI;
	//DSPI_DRV_MasterTransferBlocking(FSL_DSPICOM1, NULL, TempSendArray, TempReadArray, NumberOfBytesToSend + 1, 10000);
	ReturnFlag = TempReadArray[0];

	//CE_ON;
	//Delay_ms(1);
	//CE_OFF;

	//ReturnFlag = Read_Status();

	//while(0 == ReturnFlag & 0b00100000)
	//{
	//	ReturnFlag = Read_Status();
	//}

	return (ReturnFlag);
}

unsigned char Flush_Tx()
{
	unsigned char ReturnFlag = 0;
	unsigned char ReadArray[2] = {0, 0};
	unsigned char SendArray[2] = {FLUSH_TX, 0};
    SS_LOW;
    DRV_SPI0_BufferAddWriteRead(SendArray, ReadArray, 1);
    SS_HI;
	//DSPI_DRV_MasterTransferBlocking(FSL_DSPICOM1, NULL, SendArray, ReadArray, 1, 10000);
	ReturnFlag = ReadArray[0];
	return (ReturnFlag);
}

unsigned char Flush_RX()
{
	unsigned char ReturnFlag = 0;
	unsigned char ReadArray[2] = {0, 0};
	unsigned char SendArray[2] = {FLUSH_RX, 0};
    SS_LOW;
    DRV_SPI0_BufferAddWriteRead(SendArray, ReadArray, 1);
    SS_HI;
	//DSPI_DRV_MasterTransferBlocking(FSL_DSPICOM1, NULL, SendArray, ReadArray, 1, 10000);
	ReturnFlag = ReadArray[0];
	return (ReturnFlag);
}




