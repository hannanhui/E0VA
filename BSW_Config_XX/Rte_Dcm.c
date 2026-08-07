/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_Dcm.c>
 *  @brief      <>
 *  
 *  <MCU:Z20K144M>
 *  
 *  @author     <>
 *  @date       <2025-02-07 16:03:35>
 */
/*============================================================================*/

#include "Rte_Dcm.h"
#include "NvM.h"
#include "NmHistoryState.h"
#include "Common.h"
#include "Mcu.h"
#include "Dcm.h"

//#include "Power.h"
#include "Rte_Type.h"
//#include "Pneumatic.h"
#include "Type_Define.h"
/*==========================Function Enable Macros============================*/
/* comment MACRO below to disable the service 22 to readout public key checksum */
#define READOUT_PUBLICKEY_CHECKSUM
/* comment MACRO below to disable the RDID 0206 fixed to pass check programming 
 * precondition
 */

#define READOUT_SECURITY_CONSTANT

#define TEST_PHASE_TO_PASS_PROGRAM_CHECK
#define TEST_DTC

#if defined(TEST_DTC)
#include "Dem.h"
#endif

extern void Dcm_MemoryCopy(
    P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) Source,
    P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Dest,
    uint16 Length);

#ifdef READOUT_PUBLICKEY_CHECKSUM

typedef struct
{
    uint8 Checksum[32];
    uint32 PublicKeyWrittenFlag;
}PublicKeyChecksumInfoType;
#define PUBLIC_KEY_CHECK_SUM_INFO_BASE         0x0101C104U
#define PUBLIC_KEY_CHECK_SUM_INFO_LEN          36
#define PUBLIC_KEY_CHECK_SUM_INFO_WRITTEN_FLAG 0x4a4b4850U

#endif /* READOUT_PUBLICKEY_CHECKSUM */

#ifdef READOUT_SECURITY_CONSTANT

typedef struct
{
    uint8 SecurityConstant[5];
    uint8 SecurityConstantWrittenFlagArr[4];
}SecurityConstantInfoType;
#define SECURITY_CONSTANT_BASE                  0x0101E000U
#define SECURITY_CONSTANT_LEN                   9
#define SECURITY_CONSTANT_FLAG_LEN              4
uint8 SecurityConstantFlagArr[4] = {0xAA,0xd1,0x4b,0x55};

#endif /* READOUT_SECURITY_CONSTANT */

#define DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
Std_ReturnType  Dcm_DcmDslCallbackDCMRequestService_0_StartProtocol = E_OK;
Std_ReturnType  Dcm_DcmDslCallbackDCMRequestService_0_StopProtocol = E_OK;
#define DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
/***************************Security Part****************************************/

/***************************Did Part****************************************/

//#define  DataLength_DcmDspData_220AH 1
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
//uint8 Buffer_DcmDspData_220AH[ DataLength_DcmDspData_220AH ] = {0x00} ;
//uint8 Buffer_DcmDspData_220AH_Default[ DataLength_DcmDspData_220AH ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_D03AH 32
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_D03AH[ DataLength_DcmDspData_D03AH ] = {0x00} ;
uint8 Buffer_DcmDspData_D03AH_Default[ DataLength_DcmDspData_D03AH ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_D0B5H 3
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_D0B5H[ DataLength_DcmDspData_D0B5H ] = {0x00} ;
uint8 Buffer_DcmDspData_D0B5H_Default[ DataLength_DcmDspData_D0B5H ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_D109H 1
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_D109H[ DataLength_DcmDspData_D109H ] = {0x00} ;
uint8 Buffer_DcmDspData_D109H_Default[ DataLength_DcmDspData_D109H ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_D110H 2
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_D110H[ DataLength_DcmDspData_D110H ] = {0x00} ;
uint8 Buffer_DcmDspData_D110H_Default[ DataLength_DcmDspData_D110H ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
//#define  DataLength_DcmDspData_D134H 1
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
//uint8 Buffer_DcmDspData_D134H[ DataLength_DcmDspData_D134H ] = {0x00} ;
//uint8 Buffer_DcmDspData_D134H_Default[ DataLength_DcmDspData_D134H ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_D214H 50
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_D214H[ DataLength_DcmDspData_D214H ] = {0x00} ;
uint8 Buffer_DcmDspData_D214H_Default[ DataLength_DcmDspData_D214H ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_D291H 34
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
//uint8 Buffer_DcmDspData_D291H[ DataLength_DcmDspData_D291H ] = {0x20} ;
uint8 Buffer_DcmDspData_D291H_Default[ DataLength_DcmDspData_D291H ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_D907H 500
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
//uint8 Buffer_DcmDspData_D907H[ DataLength_DcmDspData_D907H ] = {0x20} ;
uint8 Buffer_DcmDspData_D907H_Default[ DataLength_DcmDspData_D907H ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_457EH 1
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
//uint8 Buffer_DcmDspData_457EH[ DataLength_DcmDspData_457EH ] = {0x20} ;
uint8 Buffer_DcmDspData_457EH_Default[ DataLength_DcmDspData_457EH ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_DD00H 4
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_DD00H[ DataLength_DcmDspData_DD00H ] = {0x00} ;
uint8 Buffer_DcmDspData_DD00H_Default[ DataLength_DcmDspData_DD00H ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_DD01H 3
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_DD01H[ DataLength_DcmDspData_DD01H ] = {0x00} ;
uint8 Buffer_DcmDspData_DD01H_Default[ DataLength_DcmDspData_DD01H ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_DD02H 1
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_DD02H[ DataLength_DcmDspData_DD02H ] = {0x00} ;
uint8 Buffer_DcmDspData_DD02H_Default[ DataLength_DcmDspData_DD02H ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
//#define  DataLength_DcmDspData_DD0AH 1
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
//uint8 Buffer_DcmDspData_DD0AH[ DataLength_DcmDspData_DD0AH ] = {0x00} ;
//uint8 Buffer_DcmDspData_DD0AH_Default[ DataLength_DcmDspData_DD0AH ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_DD0CH 1
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_DD0CH[ DataLength_DcmDspData_DD0CH ] = {0x00} ;
uint8 Buffer_DcmDspData_DD0CH_Default[ DataLength_DcmDspData_DD0CH ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_F120H 7
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_F120H[ DataLength_DcmDspData_F120H ] = {0x00} ;
uint8 Buffer_DcmDspData_F120H_Default[ DataLength_DcmDspData_F120H ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_F121H 7
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_F121H[ DataLength_DcmDspData_F121H ] = {0x00} ;
uint8 Buffer_DcmDspData_F121H_Default[ DataLength_DcmDspData_F121H ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_F125H 7
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_F125H[ DataLength_DcmDspData_F125H ] = {0x00} ;
uint8 Buffer_DcmDspData_F125H_Default[ DataLength_DcmDspData_F125H ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_F126H 51
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_F126H[ DataLength_DcmDspData_F126H ] = {0x00} ;
uint8 Buffer_DcmDspData_F126H_Default[ DataLength_DcmDspData_F126H ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_F12AH 7
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_F12AH[ DataLength_DcmDspData_F12AH ] = {0x00} ;
uint8 Buffer_DcmDspData_F12AH_Default[ DataLength_DcmDspData_F12AH ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_F12BH 7
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_F12BH[ DataLength_DcmDspData_F12BH ] = {0x00} ;
uint8 Buffer_DcmDspData_F12BH_Default[ DataLength_DcmDspData_F12BH ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_F12EH 15
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_F12EH[ DataLength_DcmDspData_F12EH ] = {0x00} ;
uint8 Buffer_DcmDspData_F12EH_Default[ DataLength_DcmDspData_F12EH ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_F186H 1
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_F186H[ DataLength_DcmDspData_F186H ] = {0x00} ;
uint8 Buffer_DcmDspData_F186H_Default[ DataLength_DcmDspData_F186H ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_F18AH 6
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_F18AH[ DataLength_DcmDspData_F18AH ] = {0x00} ;
uint8 Buffer_DcmDspData_F18AH_Default[ DataLength_DcmDspData_F18AH ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_F18CH 4
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_F18CH[ DataLength_DcmDspData_F18CH ] = {0x00};
uint8 Buffer_DcmDspData_F18CH_Default[ DataLength_DcmDspData_F18CH ] = {0x0};
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_F1A0H 8
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_F1A0H[ DataLength_DcmDspData_F1A0H ] = {0x66, 0x08, 0x25, 0x10, 0x42, 0x20, 0x20, 'A'};
uint8 Buffer_DcmDspData_F1A0H_Default[ DataLength_DcmDspData_F1A0H ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_F1A1H 8
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_F1A1H[ DataLength_DcmDspData_F1A1H ] = {0x66, 0x08, 0x17 ,0x59, 0x82, 0x20, 0x20, 'A'};
uint8 Buffer_DcmDspData_F1A1H_Default[ DataLength_DcmDspData_F1A1H ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_F1A5H 8
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_F1A5H[ DataLength_DcmDspData_F1A5H ] = {0x66, 0x08, 0x17, 0x62, 0x21, 0x20, 0x20, 'B'};
uint8 Buffer_DcmDspData_F1A5H_Default[ DataLength_DcmDspData_F1A5H ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_F1AAH 8
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_F1AAH[ DataLength_DcmDspData_F1AAH ] = {0x66, 0x08, 0x37, 0x17, 0x21, 0x20, 0x20, 'A'};
uint8 Buffer_DcmDspData_F1AAH_Default[ DataLength_DcmDspData_F1AAH ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_F1ABH 8
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_F1ABH[ DataLength_DcmDspData_F1ABH ] = {0x66, 0x08, 0x37, 0x16, 0x63, 0x20, 0x20, 'A'};
uint8 Buffer_DcmDspData_F1ABH_Default[ DataLength_DcmDspData_F1ABH ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_F1AEH 9
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_F1AEH[ DataLength_DcmDspData_F1AEH ] = {0x01, 0x66, 0x08, 0x37, 0x17, 0x23, 0x20, 0x20, 'B'};
uint8 Buffer_DcmDspData_F1AEH_Default[ DataLength_DcmDspData_F1AEH ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_F1F8H 32
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_F1F8H[ DataLength_DcmDspData_F1F8H ] = {0x00} ;
uint8 Buffer_DcmDspData_F1F8H_Default[ DataLength_DcmDspData_F1F8H ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_F1FAH 38
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_F1FAH[ DataLength_DcmDspData_F1FAH ] = {0x00} ;
uint8 Buffer_DcmDspData_F1FAH_Default[ DataLength_DcmDspData_F1FAH ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_F1FBH 8
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_F1FBH[ DataLength_DcmDspData_F1FBH ] = {0x00} ;
uint8 Buffer_DcmDspData_F1FBH_Default[ DataLength_DcmDspData_F1FBH ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
//#define  DataLength_DcmDspData_F1FEH 8
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_F1FEH[ DataLength_DcmDspData_F1FEH ] = {0x00};
uint8 Buffer_DcmDspData_F1FEH_Default[ DataLength_DcmDspData_F1FEH ] = {0x0};
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_F1FFH 8
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_F1FFH[ DataLength_DcmDspData_F1FFH ] = {0x00} ;
uint8 Buffer_DcmDspData_F1FFH_Default[ DataLength_DcmDspData_F1FFH ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_F1A0H_DidName 2
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_F1A0H_DidName[ DataLength_DcmDspData_F1A0H_DidName ] = {0xF1, 0xA0} ;
uint8 Buffer_DcmDspData_F1A0H_DidName_Default[ DataLength_DcmDspData_F1A0H_DidName ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_F1AAH_DidName 2
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_F1AAH_DidName[ DataLength_DcmDspData_F1AAH_DidName ] = {0xf1, 0xaa} ;
uint8 Buffer_DcmDspData_F1AAH_DidName_Default[ DataLength_DcmDspData_F1AAH_DidName ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_F1ABH_DidName 2
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_F1ABH_DidName[ DataLength_DcmDspData_F1ABH_DidName ] = {0xf1, 0xab} ;
uint8 Buffer_DcmDspData_F1ABH_DidName_Default[ DataLength_DcmDspData_F1ABH_DidName ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_F18CH_DidName 2
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_F18CH_DidName[ DataLength_DcmDspData_F18CH_DidName ] = {0xf1, 0x8c} ;
uint8 Buffer_DcmDspData_F18CH_DidName_Default[ DataLength_DcmDspData_F18CH_DidName ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_F1AEH_DidName 2
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_F1AEH_DidName[ DataLength_DcmDspData_F1AEH_DidName ] = {0xf1, 0xae} ;
uint8 Buffer_DcmDspData_F1AEH_DidName_Default[ DataLength_DcmDspData_F1AEH_DidName ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_F120H_DidName 2
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_F120H_DidName[ DataLength_DcmDspData_F120H_DidName ] = {0xf1, 0x20} ;
uint8 Buffer_DcmDspData_F120H_DidName_Default[ DataLength_DcmDspData_F120H_DidName ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_F12AH_DidName 2
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_F12AH_DidName[ DataLength_DcmDspData_F12AH_DidName ] = {0xf1, 0x2a} ;
uint8 Buffer_DcmDspData_F12AH_DidName_Default[ DataLength_DcmDspData_F12AH_DidName ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_F12BH_DidName 2
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_F12BH_DidName[ DataLength_DcmDspData_F12BH_DidName ] = {0xf1, 0x2b} ;
uint8 Buffer_DcmDspData_F12BH_DidName_Default[ DataLength_DcmDspData_F12BH_DidName ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_F12EH_DidName 2
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_F12EH_DidName[ DataLength_DcmDspData_F12EH_DidName ] = {0xf1,0x2e} ;
uint8 Buffer_DcmDspData_F12EH_DidName_Default[ DataLength_DcmDspData_F12EH_DidName ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataConditionCheck_220AH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode )
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataConditionCheck_D03AH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode )
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataConditionCheck_D0B5H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode )
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataConditionCheck_D109H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode )
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataConditionCheck_D110H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode )
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataConditionCheck_D134H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode )
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataConditionCheck_D214H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode )
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataConditionCheck_D291H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode )
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataConditionCheck_D907H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode )
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataConditionCheck_457EH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode )
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataConditionCheck_DD00H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode )
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataConditionCheck_DD01H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode )
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataConditionCheck_DD02H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode )
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataConditionCheck_DD0AH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode )
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataConditionCheck_DD0CH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode )
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataConditionCheck_F120H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode )
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataConditionCheck_F121H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode )
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataConditionCheck_F125H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode )
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataConditionCheck_F126H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode )
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataConditionCheck_F12AH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode )
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataConditionCheck_F12BH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode )
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataConditionCheck_F12EH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode )
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataConditionCheck_F186H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode )
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataConditionCheck_F18AH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode )
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataConditionCheck_F18CH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode )
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataConditionCheck_F1A0H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode )
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataConditionCheck_F1A1H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode )
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataConditionCheck_F1A5H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode )
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataConditionCheck_F1AAH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode )
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataConditionCheck_F1ABH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode )
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataConditionCheck_F1AEH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode )
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataConditionCheck_F1F8H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode )
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataConditionCheck_F1FAH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode )
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataConditionCheck_F1FBH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode )
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataConditionCheck_F1FEH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode )
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataConditionCheck_F1FFH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode )
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataRead_220AH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    /*float temp;
    //uint8  index;
    //for(index = 0;index < DataLength_DcmDspData_220AH;index++)
    //{
    temp = Power_AdGet()*5000/4096*BAT_RES_UP/BAT_RES_DOWN/100U + 4U;
    Data[0U] = (uint8)temp;//Buffer_DcmDspData_220AH[index];
    //}*/
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataRead_D03AH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
#if (defined(READOUT_PUBLICKEY_CHECKSUM) && defined(OEM_SPECIFI_GEELY_2P0))
    uint8 iloop;
    PublicKeyChecksumInfoType checksumInfo = {0};
    Std_ReturnType ret = E_NOT_OK;
    Dcm_MemoryCopy(((uint8*)PUBLIC_KEY_CHECK_SUM_INFO_BASE),
                    ((uint8*)&checksumInfo.Checksum),PUBLIC_KEY_CHECK_SUM_INFO_LEN);
    if(checksumInfo.PublicKeyWrittenFlag == PUBLIC_KEY_CHECK_SUM_INFO_WRITTEN_FLAG)
    {
        /* if condition satisfied readout checksum info */
        if(NULL_PTR != Data)
        {
            for ( iloop = 0; iloop < DataLength_DcmDspData_D03AH; iloop++)
            {
                Data[iloop] = checksumInfo.Checksum[iloop];
            }
            ret = E_OK;
        }     
    }
    if((ret != E_OK) && (ErrorCode != NULL_PTR))
    {
        *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
    }
    return ret;
#else
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_D03AH;index++)
    {
        Data[index] = Buffer_DcmDspData_D03AH[index];
    }
    return E_OK;
#endif
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataRead_D0B5H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_D0B5H;index++)
    {
        Data[index] = Buffer_DcmDspData_D0B5H[index];
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataRead_D109H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_D109H;index++)
    {
        Data[index] = Buffer_DcmDspData_D109H[index];
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataRead_D110H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_D110H;index++)
    {
        Data[index] = Buffer_DcmDspData_D110H[index];
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataRead_D134H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
//    Com_BodyCAN_ISTrigVehModMngtGlbSafe1_0_Record  VehModMngtGlbSafe1;
//    Rte_Read_Com_BodyCAN_ISTrigVehModMngtGlbSafe1_0_DataElement(&VehModMngtGlbSafe1); //0XF0

    //uint8  index;
    //for(index = 0;index < DataLength_DcmDspData_D134H;index++)
    //{
//        Data[0U] = VehModMngtGlbSafe1.BodyCAN_ISTrisVehModMngtGlbSafe1CarModSts1_0; //Buffer_DcmDspData_D134H[index];
    //}
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataRead_D214H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
#ifdef ASENSING_GEELY_FX11_CUSTOM
    /* only when DID 0xD124 is configed then enable the function*/
    Std_ReturnType ret = E_NOT_OK;
    /* read the network management history */ 
    if(NmHistoryState_BaseDidReadBuf(Data) == E_OK)
    {
        ret = E_OK;
    }
    else
    {
        if(ErrorCode != NULL_PTR)
        {
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            ret = E_NOT_OK;
        }
    }
    return ret;
#else
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_D214H;index++)
    {
        Data[index] = Buffer_DcmDspData_D214H[index];
    }
    return E_OK;
#endif
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataRead_D291H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    /*float fTemp;
    unsigned short int u16Temp;
    
    fTemp = (PressAdMin_CaliVal+584.57)/9.743*10;
    u16Temp = (unsigned short int)fTemp;
    Data[0U] = (u16Temp>>8)&0xFF;
    Data[1U] = u16Temp&0xFF;
    
    u16Temp = NSPAS3_GetPressure();
    Data[2U] = (u16Temp>>8)&0xFF;
    Data[3U] = u16Temp&0xFF;
    
    fTemp = (SMP58X_GetValue(BACK_SIDE_L)+584.57)/9.743*10;
    u16Temp = (unsigned short int)fTemp;
    Data[4U] = (u16Temp>>8)&0xFF;
    Data[5U] = u16Temp&0xFF;
    
    fTemp = (SMP58X_GetValue(BACK_SIDE_R)+584.57)/9.743*10;
    u16Temp = (unsigned short int)fTemp;
    Data[6U] = (u16Temp>>8)&0xFF;
    Data[7U] = u16Temp&0xFF;
    
    fTemp = (SMP58X_GetValue(Cushion_L)+584.57)/9.743*10;
    u16Temp = (unsigned short int)fTemp;
    Data[8U] = (u16Temp>>8)&0xFF;
    Data[9U] = u16Temp&0xFF;
    
    fTemp = (SMP58X_GetValue(Cushion_R)+584.57)/9.743*10;
    u16Temp = (unsigned short int)fTemp;
    Data[10U] = (u16Temp>>8)&0xFF;
    Data[11U] = u16Temp&0xFF;
    
    fTemp = 0; //Up lumbar
    u16Temp = (unsigned short int)fTemp;
    Data[12U] = (u16Temp>>8)&0xFF;
    Data[13U] = u16Temp&0xFF;
    
    fTemp = 0; //Middle lumbar
    u16Temp = (unsigned short int)fTemp;
    Data[14U] = (u16Temp>>8)&0xFF;
    Data[15U] = u16Temp&0xFF;
    
    fTemp = 0; //Low lumbar
    u16Temp = (unsigned short int)fTemp;
    Data[16U] = (u16Temp>>8)&0xFF;
    Data[17U] = u16Temp&0xFF;
    
    fTemp = (SMP58X_GetValue(BACK_SIDE_Surface_L)+584.57)/9.743*10;
    u16Temp = (unsigned short int)fTemp;
    Data[18U] = (u16Temp>>8)&0xFF;
    Data[19U] = u16Temp&0xFF;
    
    fTemp = (SMP58X_GetValue(BACK_SIDE_Surface_R)+584.57)/9.743*10;
    u16Temp = (unsigned short int)fTemp;
    Data[20U] = (u16Temp>>8)&0xFF;
    Data[21U] = u16Temp&0xFF;
    
    fTemp = (SMP58X_GetValue(Cushion_Surface_L)+584.57)/9.743*10;
    u16Temp = (unsigned short int)fTemp;
    Data[22U] = (u16Temp>>8)&0xFF;
    Data[23U] = u16Temp&0xFF;
    
    fTemp = (SMP58X_GetValue(Cushion_Surface_R)+584.57)/9.743*10;
    u16Temp = (unsigned short int)fTemp;
    Data[24U] = (u16Temp>>8)&0xFF;
    Data[25U] = u16Temp&0xFF;
    
    fTemp = 0; //Reserve Surface Pressure 5
    u16Temp = (unsigned short int)fTemp;
    Data[26U] = (u16Temp>>8)&0xFF;
    Data[27U] = u16Temp&0xFF;
    
    fTemp = 0; //Reserve Surface Pressure 6
    u16Temp = (unsigned short int)fTemp;
    Data[28U] = (u16Temp>>8)&0xFF;
    Data[29U] = u16Temp&0xFF;
    
    fTemp = 0; //Reserve Surface Pressure 7
    u16Temp = (unsigned short int)fTemp;
    Data[30U] = (u16Temp>>8)&0xFF;
    Data[31U] = u16Temp&0xFF;
    
    fTemp = 0; //Reserve Surface Pressure 8
    u16Temp = (unsigned short int)fTemp;
    Data[32U] = (u16Temp>>8)&0xFF;
    Data[33U] = u16Temp&0xFF;
    */
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
//#include "Valve.h"
//#include "Power.h"
Std_ReturnType  Rte_DataRead_D907H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
   /* static PMirror PrePM;
    unsigned int u32Temp;
    unsigned short int u16Temp;
    short int s16Temp;
    float fTemp;
    Valve_Param_t Valve_Param_Temp;
    
    Data[0] = LumbarDir;
    Data[1] = SmartSt;
    Data[2] = GasholderWorkSt;
    Data[3] = GasholderIsFull;
    Data[4] = (PM.PortMirror >>56)&0xFF;
    Data[5] = (PM.PortMirror >>48)&0xFF;
    Data[6] = (PM.PortMirror >>40)&0xFF;
    Data[7] = (PM.PortMirror >>32)&0xFF;
    Data[8] = (PM.PortMirror >>24)&0xFF;
    Data[9] = (PM.PortMirror >>16)&0xFF;
    Data[10] = (PM.PortMirror >>8)&0xFF;
    Data[11] = (PM.PortMirror >>0)&0xFF;

    Data[12] = BagPress[Cushion_L];
    Data[13] = BagPress[Cushion_R];
    Data[14] = BagPress[BACK_SIDE_L];
    Data[15] = BagPress[BACK_SIDE_R];
    Data[16] = BagPress[Cushion_Surface_R];
    Data[17] = BagPress[Cushion_Surface_R];
    Data[18] = BagPress[BACK_SIDE_Surface_L];
    Data[19] = BagPress[BACK_SIDE_Surface_R];
    
    u16Temp = NSPAS3_GetPressure();
    Data[20] = (unsigned char)u16Temp;
    
    Data[21] = InflatAct[Cushion_Surface_L];
    Data[22] = InflatAct[Cushion_Surface_R];
    Data[23] = InflatAct[BACK_SIDE_Surface_L];
    Data[24] = InflatAct[BACK_SIDE_Surface_R];
    Data[25] = InflatAct[BACK_SIDE_L];
    Data[26] = InflatAct[BACK_SIDE_R];
    Data[27] = InflatAct[Cushion_L];
    Data[28] = InflatAct[Cushion_R];

    s16Temp = NTC_GetTemperature();
    Data[29] = (s16Temp>>8)&0xFF;
    Data[30] = s16Temp&0xFF;
    
    fTemp = (PressAdMin_CaliVal+584.57)/9.743*10;
    u16Temp = (unsigned short int)fTemp;
    Data[31U] = (u16Temp>>8)&0xFF;
    Data[32U] = u16Temp&0xFF;
    
    Data[33U] = Power_GetBatSt();
    u32Temp = Power_AdGet();
    Data[34U] = (u32Temp>>24)&0xFF;
    Data[35U] = (u32Temp>>16)&0xFF;
    Data[36U] = (u32Temp>>8)&0xFF;
    Data[37U] = (u32Temp>>0)&0xFF;
    
    //16 * Valve Param1-24
    u16Temp = 38;
    for(u32Temp=0;u32Temp<24;u32Temp++)
    {
        Valve_Param_Temp = Valve_GetParam(u32Temp);
        Data[u16Temp] = Valve_Param_Temp.St;
        Data[u16Temp+1] = (Valve_Param_Temp.V_CurrSet>>8)&0xFF;
        Data[u16Temp+2] = Valve_Param_Temp.V_CurrSet&0xFF;
        Data[u16Temp+3] = (Valve_Param_Temp.V0>>8)&0xFF;
        Data[u16Temp+4] = Valve_Param_Temp.V0&0xFF;
        Data[u16Temp+5] = (Valve_Param_Temp.V1>>8)&0xFF;
        Data[u16Temp+6] = Valve_Param_Temp.V1&0xFF;
        Data[u16Temp+7] = (Valve_Param_Temp.V2>>8)&0xFF;
        Data[u16Temp+8] = Valve_Param_Temp.V2&0xFF;
        Data[u16Temp+9] = (Valve_Param_Temp.V3>>8)&0xFF;
        Data[u16Temp+10] = Valve_Param_Temp.V3&0xFF;
        Data[u16Temp+11] = (Valve_Param_Temp.T>>8)&0xFF;
        Data[u16Temp+12] = Valve_Param_Temp.T&0xFF;
        Data[u16Temp+13] = (Valve_Param_Temp.Cnt>>8)&0xFF;
        Data[u16Temp+14] = Valve_Param_Temp.Cnt&0xFF;
        Data[u16Temp+15] = Valve_Param_Temp.Temp;
        u16Temp += 16;
    }
    
    //Reserved
    //Data[423] = RunMode;
    //Data[423] = Test_PumpOnPos_;
    //Data[423] = Test_PumpOffPos_;
    
#if 0
      Buffer_DcmDspData_F126H[37] = cnt;
      if(cnt< 3)
      {
          PM.UC.AS = 0;
          cnt++;
      }
      else
      {
          Buffer_DcmDspData_F126H[35] = val/100;
          Buffer_DcmDspData_F126H[36] = 00;
          Data[35] = Buffer_DcmDspData_F126H[35];
          Data[36] = Buffer_DcmDspData_F126H[36];
          Test_AS_Key(val);
          val += 500;
          if(val > 10000)
          val = 6500;
      }
#endif
*/
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataRead_457EH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    //Data[0U] = PM.UC.PUMP;
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataRead_DD00H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_DD00H;index++)
    {
        Data[index] = Buffer_DcmDspData_DD00H[index];
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataRead_DD01H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_DD01H;index++)
    {
        Data[index] = Buffer_DcmDspData_DD01H[index];
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataRead_DD02H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_DD02H;index++)
    {
        Data[index] = Buffer_DcmDspData_DD02H[index];
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataRead_DD0AH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
//    Com_BodyCAN_ISTrigVehModMngtGlbSafe1_0_Record  VehModMngtGlbSafe1;
//    Rte_Read_Com_BodyCAN_ISTrigVehModMngtGlbSafe1_0_DataElement(&VehModMngtGlbSafe1); //0XF0
    
//    Data[0U] = VehModMngtGlbSafe1.BodyCAN_ISTrisVehModMngtGlbSafe1UsgModSts_0; //Buffer_DcmDspData_DD0AH[index];
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataRead_DD0CH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_DD0CH;index++)
    {
        Data[index] = Buffer_DcmDspData_DD0CH[index];
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataRead_F120H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F120H;index++)
    {
        Data[index] = Buffer_DcmDspData_F120H[index];
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataRead_F121H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F121H;index++)
    {
        Data[index] = Buffer_DcmDspData_F121H[index];
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataRead_F125H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F125H;index++)
    {
        Data[index] = Buffer_DcmDspData_F125H[index];
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataRead_F126H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F126H;index++)
    {
        Data[index] = Buffer_DcmDspData_F126H[index];
    }
    
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataRead_F12AH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F12AH;index++)
    {
        Data[index] = Buffer_DcmDspData_F12AH[index];
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataRead_F12BH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F12BH;index++)
    {
        Data[index] = Buffer_DcmDspData_F12BH[index];
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataRead_F12EH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F12EH;index++)
    {
        Data[index] = Buffer_DcmDspData_F12EH[index];
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataRead_F186H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
#if (defined(OEM_SPECIFI_GEELY_2P0) && DataLength_DcmDspData_F186H >= 1)
    /* only when 0xf186 config */
    Dcm_SesCtrlType activeSesionNum;
    uint8  result = Dcm_GetSesCtrlType(&activeSesionNum);
    if (E_OK == result)
    {
        if (NULL_PTR != Data)
        {           
            Data[0] = (uint8)activeSesionNum;
        }
        return E_OK;
    }
    else
    {
        /*if failed to get active session Responese NRC22*/
        if(NULL_PTR != ErrorCode)
        {
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
        }
        return E_NOT_OK;   
    }
#else
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F186H;index++)
    {
        Data[index] = Buffer_DcmDspData_F186H[index];
    }
    return E_OK;
#endif /* OEM_SPECIFI_GEELY_2P0 */
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataRead_F18AH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F18AH;index++)
    {
        Data[index] = Buffer_DcmDspData_F18AH[index];
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
#include "Z20K144M.h"
Std_ReturnType  Rte_DataRead_F18CH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    Reg_Scm_WType *const scmRegWPtr = (Reg_Scm_WType *) SCM_BASE_ADDR; /*!< SCM Word Register */
    uint32_t UID0 = scmRegWPtr->SCM_UNIQUE0;
    uint32_t UID1 = scmRegWPtr->SCM_UNIQUE1;
    uint32_t UID2 = scmRegWPtr->SCM_UNIQUE2;
    uint32_t UID3 = scmRegWPtr->SCM_UNIQUE3;
    
    Buffer_DcmDspData_F18CH[0] =Hex2Bcd((UID0>>0U)&0xF);
    Buffer_DcmDspData_F18CH[1] =Hex2Bcd((UID0>>16U)&0xF);
    Buffer_DcmDspData_F18CH[2] =Hex2Bcd((UID1>>0U)&0xF);
    Buffer_DcmDspData_F18CH[3] =Hex2Bcd((UID1>>16U)&0xF);
    
    for(index = 0;index < DataLength_DcmDspData_F18CH;index++)
    {
        Data[index] = Buffer_DcmDspData_F18CH[index];
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataRead_F1A0H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F1A0H;index++)
    {
        Data[index] = Buffer_DcmDspData_F1A0H[index];
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataRead_F1A1H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F1A1H;index++)
    {
        Data[index] = Buffer_DcmDspData_F1A1H[index];
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataRead_F1A5H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F1A5H;index++)
    {
        Data[index] = Buffer_DcmDspData_F1A5H[index];
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataRead_F1AAH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F1AAH;index++)
    {
        Data[index] = Buffer_DcmDspData_F1AAH[index];
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataRead_F1ABH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F1ABH;index++)
    {
        Data[index] = Buffer_DcmDspData_F1ABH[index];
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataRead_F1AEH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F1AEH;index++)
    {
        Data[index] = Buffer_DcmDspData_F1AEH[index];
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataRead_F1F8H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F1F8H;index++)
    {
        Data[index] = Buffer_DcmDspData_F1F8H[index];
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataRead_F1FAH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F1FAH;index++)
    {
        Data[index] = Buffer_DcmDspData_F1FAH[index];
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataRead_F1FBH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F1FBH;index++)
    {
        Data[index] = Buffer_DcmDspData_F1FBH[index];
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataRead_F1FEH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F1FEH;index++)
    {
        Data[index] = Buffer_DcmDspData_F1FEH[index];
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataRead_F1FFH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F1FFH;index++)
    {
        Data[index] = Buffer_DcmDspData_F1FFH[index];
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataRead_F1A0H_Name( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F1A0H_DidName;index++)
    {
        Data[index] = Buffer_DcmDspData_F1A0H_DidName[index];
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataRead_F1AAH_Name( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F1AAH_DidName;index++)
    {
        Data[index] = Buffer_DcmDspData_F1AAH_DidName[index];
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataRead_F1ABH_Name( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F1ABH_DidName;index++)
    {
        Data[index] = Buffer_DcmDspData_F1ABH_DidName[index];
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataRead_F18CH_Name( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F18CH_DidName;index++)
    {
        Data[index] = Buffer_DcmDspData_F18CH_DidName[index];
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataRead_F1AEH_Name( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F1AEH_DidName;index++)
    {
        Data[index] = Buffer_DcmDspData_F1AEH_DidName[index];
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataRead_F120H_Name( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F120H_DidName;index++)
    {
        Data[index] = Buffer_DcmDspData_F120H_DidName[index];
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataRead_F12AH_Name( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F12AH_DidName;index++)
    {
        Data[index] = Buffer_DcmDspData_F12AH_DidName[index];
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataRead_F12BH_Name( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F12BH_DidName;index++)
    {
        Data[index] = Buffer_DcmDspData_F12BH_DidName[index];
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_DataRead_F12EH_Name( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F12EH_DidName;index++)
    {
        Data[index] = Buffer_DcmDspData_F12EH_DidName[index];
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/***************************Routine Part****************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_RoutineRequest_202AH(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_RoutineRequest_203DH(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_RoutineRequest_F010H(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_RoutineRequest_F011H(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_RoutineRequest_F012H(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_RoutineRequest_F013H(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_RoutineRequest_F014H(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_RoutineRequest_F015H(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_RoutineStart_0206H(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
#ifdef TEST_PHASE_TO_PASS_PROGRAM_CHECK
    OutBuffer[0] = 0x10;
    OutBuffer[1] = 0x1;
#endif /* TEST_PHASE_TO_PASS_PROGRAM_CHECK */
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_RoutineStart_202AH(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_RoutineStart_203DH(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_RoutineStart_F010H(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_RoutineStart_F011H(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_RoutineStart_F012H(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_RoutineStart_F013H(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_RoutineStart_F014H(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_RoutineStart_F015H(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_RoutineStop_202AH(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_RoutineStop_203DH(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_RoutineStop_F010H(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_RoutineStop_F011H(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_RoutineStop_F012H(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_RoutineStop_F013H(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_RoutineStop_F014H(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_RoutineStop_F015H(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/**************function for ClearDTC**************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType Rte_ClearDTCCheck(uint32 GoDTC,Dcm_NegativeResponseCodeType* ErrorCode)
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*******function for Protocol Start and stop***********/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  DcmDslCallbackDCMRequestService_0_StartProtocol(Dcm_ProtocolType  ProtocolID)
{
    return(Dcm_DcmDslCallbackDCMRequestService_0_StartProtocol);
}
Std_ReturnType  DcmDslCallbackDCMRequestService_0_StopProtocol(Dcm_ProtocolType  ProtocolID)
{
    return(Dcm_DcmDslCallbackDCMRequestService_0_StopProtocol);
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
/*PreConditon Check*/
//Std_ReturnType  Dcm_Rte_PreConditonCheck = E_OK;
Std_ReturnType RTE_PreConditonCheck(    uint8 SID, uint8 Subfunction)
{
//    Com_BodyCAN_ISTrigVehSpdLgt_0_Record  VehSpdLgt;
//    Com_BodyCAN_ISTrigVehModMngtGlbSafe1_0_Record  VehModMngtGlbSafe1;
    Std_ReturnType  Dcm_Rte_PreConditonCheck = E_OK;
    
    if( (SID == 0x10)&&((Subfunction&0x0F) == 0x2) ) //10 02/82
    {
//        Rte_Read_Com_BodyCAN_ISTrigVehSpdLgt_0_DataElement(&VehSpdLgt);
//        Rte_Read_Com_BodyCAN_ISTrigVehModMngtGlbSafe1_0_DataElement(&VehModMngtGlbSafe1);
//        if( (VehSpdLgt.BodyCAN_ISTrisVehSpd_kmh > 3) || (VehModMngtGlbSafe1.BodyCAN_ISTrisVehModMngtGlbSafe1UsgModSts_0 == 13 ) ) //VehicleSpd > 3km/h or UsageMode = Driving
        {
//            Dcm_Rte_PreConditonCheck = E_NOT_OK;
        }
    }
    
    return Dcm_Rte_PreConditonCheck;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType SchM_PerformReset(Rte_ModeType_DcmEcuReset Reset)
{
    if (Reset == RTE_MODE_DcmEcuReset_EXECUTE)
    {
        //Mcu_PerformReset();
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

Std_ReturnType Rte_IsPublicKeyWritten()
{
    PublicKeyChecksumInfoType checksumInfo = {0};
    Dcm_MemoryCopy(((uint8*)PUBLIC_KEY_CHECK_SUM_INFO_BASE),
                    ((uint8*)&checksumInfo.Checksum),PUBLIC_KEY_CHECK_SUM_INFO_LEN);
    if(checksumInfo.PublicKeyWrittenFlag == PUBLIC_KEY_CHECK_SUM_INFO_WRITTEN_FLAG)
    {
        return E_OK;
    }
    return E_NOT_OK;
}

Std_ReturnType Rte_IsSecurityConstantWritten()
{
    SecurityConstantInfoType securityConstantInfo = {0};
    uint16 index = 0;
    Dcm_MemoryCopy(((uint8*)SECURITY_CONSTANT_BASE),
                    ((uint8*)&securityConstantInfo.SecurityConstant),SECURITY_CONSTANT_LEN);
    for (index = 0; index < SECURITY_CONSTANT_FLAG_LEN; ++index)
    {
        if(securityConstantInfo.SecurityConstantWrittenFlagArr[index] != 
        SecurityConstantFlagArr[index])
        {
            return E_NOT_OK;
        }
    }
    
    return E_OK;
}

