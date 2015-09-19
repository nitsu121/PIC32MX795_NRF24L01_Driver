
#include "MY_PORT_INIT.h"



void Init_My_Ports()
{
  //
  //PLIB_PORTS_AnPinsModeSelect(PORTS_ID_0, SYS_PORT_AD1PCFG, PORTS_PIN_MODE_DIGITAL);
//PLIB_PORTS_CnPinsPullUpEnable(PORTS_ID_0, SYS_PORT_CNPUE);
//PLIB_PORTS_CnPinsEnable(PORTS_ID_0, SYS_PORT_CNEN);
//PLIB_PORTS_ChangeNoticeEnable(PORTS_ID_0);
  
    /* PORT A Initialization */
    //PLIB_PORTS_OpenDrainDisable(PORTS_ID_0, PORT_CHANNEL_A, 0xFFFF);
    //PLIB_PORTS_Toggle( PORTS_ID_0, PORT_CHANNEL_A,  SYS_PORT_A_LAT);
    PLIB_PORTS_DirectionOutputSet(PORTS_ID_0, PORT_CHANNEL_A,  0b0000011001110011);
    PLIB_PORTS_DirectionInputSet(PORTS_ID_0, PORT_CHANNEL_A,  0b0100000010000000);
    
#if 0
    /* PORT B Initialization */
    //PLIB_PORTS_OpenDrainEnable(PORTS_ID_0, PORT_CHANNEL_A, SYS_PORT_A_ODC);
    PLIB_PORTS_Toggle( PORTS_ID_0, PORT_CHANNEL_A,  SYS_PORT_A_LAT);
    PLIB_PORTS_DirectionOutputSet( PORTS_ID_0, PORT_CHANNEL_A,  SYS_PORT_A_TRIS ^ 0xFFFF);
    
    /* PORT C Initialization */
    //PLIB_PORTS_OpenDrainEnable(PORTS_ID_0, PORT_CHANNEL_A, SYS_PORT_A_ODC);
    PLIB_PORTS_Toggle( PORTS_ID_0, PORT_CHANNEL_A,  SYS_PORT_A_LAT);
    PLIB_PORTS_DirectionOutputSet( PORTS_ID_0, PORT_CHANNEL_A,  SYS_PORT_A_TRIS ^ 0xFFFF);
#endif
    
    
    //PLIB_PORTS_DirectionOutputSet(PORTS_ID_0, PORT_CHANNEL_B,  0x10);
    
        /* PORT D Initialization */
    //PLIB_PORTS_OpenDrainEnable(PORTS_ID_0, PORT_CHANNEL_A, SYS_PORT_A_ODC);
    //PLIB_PORTS_Toggle( PORTS_ID_0, PORT_CHANNEL_D,  SYS_PORT_A_LAT);
    PLIB_PORTS_DirectionInputSet( PORTS_ID_0, PORT_CHANNEL_D,  0x80 | 0x100 | 0b0010000000000000);
    
    
#if 0
        /* PORT E Initialization */
    PLIB_PORTS_OpenDrainEnable(PORTS_ID_0, PORT_CHANNEL_A, SYS_PORT_A_ODC);
    PLIB_PORTS_Toggle( PORTS_ID_0, PORT_CHANNEL_A,  SYS_PORT_A_LAT);
    PLIB_PORTS_DirectionOutputSet( PORTS_ID_0, PORT_CHANNEL_A,  SYS_PORT_A_TRIS ^ 0xFFFF);
    
    /* PORT F Initialization */
    //PLIB_PORTS_OpenDrainEnable(PORTS_ID_0, PORT_CHANNEL_F, SYS_PORT_F_ODC);
    PLIB_PORTS_Toggle( PORTS_ID_0, PORT_CHANNEL_F,  SYS_PORT_F_LAT);
    PLIB_PORTS_DirectionOutputSet( PORTS_ID_0, PORT_CHANNEL_F,  SYS_PORT_F_TRIS ^ 0xFFFF);
    
        /* PORT G Initialization */
    //PLIB_PORTS_OpenDrainEnable(PORTS_ID_0, PORT_CHANNEL_A, SYS_PORT_A_ODC);
    PLIB_PORTS_Toggle( PORTS_ID_0, PORT_CHANNEL_A,  SYS_PORT_A_LAT);
    PLIB_PORTS_DirectionOutputSet( PORTS_ID_0, PORT_CHANNEL_A,  SYS_PORT_A_TRIS ^ 0xFFFF);
#endif
    
    D2_OFF;
    D3_OFF;
    D4_OFF;
    D5_OFF;
    D6_OFF;
    D7_OFF;
    D8_OFF;
}