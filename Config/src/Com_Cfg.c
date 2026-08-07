/**
 * @file       	Com.c
 * @brief       Source file of Com module, implementing all services of Com.
 * @version     1.2.0
 * @addtogroup  Com
 * @{
 */

/*====================================================================================================*
 * AngHui AUTOSAR BSW.
 *
 * Copyright(C) 2023 GuoKeAngHui Inc.
 *
 * All rights reserved.
 *
 * This file is part of AngHui AUTOSAR BSW, contains proprietary information.
 * Passing on and copying of this document, and communication of its contents
 * is not permitted without prior written authorization.
 *====================================================================================================*/

 /*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
#include "Com_Cfg.h"
#include "ComStack_Types.h"
#include "Com_Types.h"
#include "PduR_Cfg.h"

/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION                                 
 *====================================================================================================*/
#define COM_CFG_VENDOR_ID_C               		    0U
#define COM_CFG_AR_RELEASE_MAJOR_VERSION_C     	    4U
#define COM_CFG_AR_RELEASE_MINOR_VERSION_C      	2U
#define COM_CFG_AR_RELEASE_REVISION_VERSION_C       2U
#define COM_CFG_SW_MAJOR_VERSION_C      			1U
#define COM_CFG_SW_MINOR_VERSION_C      			2U
#define COM_CFG_SW_PATCH_VERSION_C      			0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS                                      
 *====================================================================================================*/
#if(COM_CFG_VENDOR_ID_C != COM_CFG_VENDOR_ID)
#error "Com.h and Com_Cfg.h have different vendor id"
#endif

#if(\
      (COM_CFG_AR_RELEASE_MAJOR_VERSION_C != COM_CFG_AR_RELEASE_MAJOR_VERSION) || \
      (COM_CFG_AR_RELEASE_MINOR_VERSION_C != COM_CFG_AR_RELEASE_MINOR_VERSION) || \
      (COM_CFG_AR_RELEASE_REVISION_VERSION_C != COM_CFG_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of Com.h and Com_Cfg.h are different "
#endif

/* Check if current file and Com.h header file are of the same software version */
#if(\
      (COM_CFG_SW_MAJOR_VERSION_C != COM_CFG_SW_MAJOR_VERSION) || \
      (COM_CFG_SW_MINOR_VERSION_C != COM_CFG_SW_MINOR_VERSION) ||\
	  (COM_CFG_SW_PATCH_VERSION_C != COM_CFG_SW_PATCH_VERSION)\
      )
#error "Software Version Number of Com.h and Com_Cfg.h are different "
#endif

#ifndef DISABLE_INTERMOD_VERSION_CHECK
#if(\
      (COM_CFG_AR_RELEASE_MAJOR_VERSION_C != COMTYPE_AR_RELEASE_MAJOR_VERSION) || \
      (COM_CFG_AR_RELEASE_MINOR_VERSION_C != COMTYPE_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of Com.h and ComStack_Types.h are different "
#endif

#if(\
      (COM_CFG_AR_RELEASE_MAJOR_VERSION_C != COM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
      (COM_CFG_AR_RELEASE_MINOR_VERSION_C != COM_TYPES_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of Com.h and Com_Types.h are different "
#endif

#if(\
      (COM_CFG_AR_RELEASE_MAJOR_VERSION_C != PDUR_CFG_AR_RELEASE_MAJOR_VERSION) || \
      (COM_CFG_AR_RELEASE_MINOR_VERSION_C != PDUR_CFG_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of Com.h and PduR_Cfg.h are different "
#endif


#endif
/*====================================================================================================*
 *                                   EXTERNAL FUNCTION DECLARATIONS                                 
 *====================================================================================================*/

/*====================================================================================================*
 *                                           LOCAL TYPEDEFS                                         
 *====================================================================================================*/

/*====================================================================================================*
 *                                            LOCAL MACROS                                          
 *====================================================================================================*/

/*====================================================================================================*
 *                                           LOCAL CONSTANTS                                        
 *====================================================================================================*/

/*====================================================================================================*
 *                                           LOCAL VARIABLES                                        
 *====================================================================================================*/
#define COM_START_SEC_CONFIG_DATA_8
#include "Com_MemMap.h"
VAR(uint8, COM_VAR) Com_TxIPduRuntimeValue[COM_LENGTH_OF_TXIPDUBUFFER];

CONST(uint8,COM_CONST_PBCFG) Com_TxIPduOriginalValue[COM_LENGTH_OF_TXIPDUBUFFER] = {
0x0,0x0,0x8,0xC0,0x0,0x0,0xC0,0xC0
};
#define COM_STOP_SEC_CONFIG_DATA_8
#include "Com_MemMap.h"

#define COM_START_SEC_CONFIG_DATA_8
#include "Com_MemMap.h"
VAR(uint8, COM_VAR) Com_RxIPduRuntimeValue[COM_LENGTH_OF_RXIPDUBUFFER];

CONST(uint8,COM_CONST_PBCFG) Com_RxIPduOriginalValue[COM_LENGTH_OF_RXIPDUBUFFER]= {
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0
};
#define COM_STOP_SEC_CONFIG_DATA_8
#include "Com_MemMap.h"

#define COM_START_SEC_CONFIG_DATA_8
#include "Com_MemMap.h"
CONST(boolean,COM_CONST_PBCFG) Com_BoolSignalOriginalValue[COM_NUMBER_OF_BOOLSIGNAL] = {
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0
};

VAR(boolean, COM_VAR) Com_BoolSignalRuntimeValue[COM_NUMBER_OF_BOOLSIGNAL];
#define COM_STOP_SEC_CONFIG_DATA_8
#include "Com_MemMap.h"

#define COM_START_SEC_CONFIG_DATA_8
#include "Com_MemMap.h"
CONST(uint8,COM_CONST_PBCFG) Com_8BitSignalOriginalValue[COM_NUMBER_OF_8BITSIGNAL] = {
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00
};

VAR(uint8, COM_VAR) Com_8BitSignalRuntimeValue[COM_NUMBER_OF_8BITSIGNAL];
#define COM_STOP_SEC_CONFIG_DATA_8
#include "Com_MemMap.h"


#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"
VAR(Com_RxIPduLengthRunTimeType, COM_VAR) Com_RxIPduLength[COM_NUMBER_OF_RXIPDU];

VAR(Com_RxIPduDataRunTimeType, COM_VAR) Com_RxIPduData[COM_NUMBER_OF_RXIPDU];
#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"
VAR(Com_TxIPduDataRunTimeType, COM_VAR) Com_TxIPduData[COM_NUMBER_OF_TXIPDU];
#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"




CONST(Com_SignalGroupIdType, COM_CONST) ComRxIPduSignalsRef_0[5] = {0,1,2,3,4};
CONST(Com_SignalGroupIdType, COM_CONST) ComRxIPduSignalsRef_1[2] = {5,6};

CONST(Com_SignalGroupIdType, COM_CONST) ComTxIPduSignalsRef_0[21] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
CONST(Com_RxIpduType, COM_CONST) Com_RxIPdu[COM_NUMBER_OF_RXIPDU]=
{
    {   
        NULL_PTR,     /*ComIPduCallout*/
        ComConf_ComIPdu_LinPdu_PduRToCom_ZCU_SMM_1_Rx,   /*ComIpduHandleID*/
        COM_IMMEDIATE,   /*ComIpduSignalprocess*/
        COM_NORMAL,    /*ComIpduType*/
        0,        /*ComIpduGroupRefNum*/
        NULL_PTR,       /*ComIpduGroupRef*/
        0,                              /*ComIpduSignalGroupRefNum*/
        NULL_PTR,                       /*ComIpduSignalGroupRef*/
        5,                             /*ComIPduSignalsRefNum*/
        &ComRxIPduSignalsRef_0[0],      /*ComIPduSignalsRef*/
        0,                             /*MetaDataLength*/
        8,                             /*IPduNoDynSignalLength*/
        0,                             /*IPduMaxDynSignalLength*/
        0,                    /*ComRxIPduBufIndex*/
        NULL_PTR,       /*ComIPduCounter*/
        FALSE,       /*IPduGW*/
        8   /*ComIPduInitLength*/
    },
    {   
        NULL_PTR,     /*ComIPduCallout*/
        ComConf_ComIPdu_LinPdu_PduRToCom_ZCU_SMM_2_Rx,   /*ComIpduHandleID*/
        COM_IMMEDIATE,   /*ComIpduSignalprocess*/
        COM_NORMAL,    /*ComIpduType*/
        0,        /*ComIpduGroupRefNum*/
        NULL_PTR,       /*ComIpduGroupRef*/
        0,                              /*ComIpduSignalGroupRefNum*/
        NULL_PTR,                       /*ComIpduSignalGroupRef*/
        2,                             /*ComIPduSignalsRefNum*/
        &ComRxIPduSignalsRef_1[0],      /*ComIPduSignalsRef*/
        0,                             /*MetaDataLength*/
        8,                             /*IPduNoDynSignalLength*/
        0,                             /*IPduMaxDynSignalLength*/
        8,                    /*ComRxIPduBufIndex*/
        NULL_PTR,       /*ComIPduCounter*/
        FALSE,       /*IPduGW*/
        8   /*ComIPduInitLength*/
    },
};

CONST(Com_TxModeType, COM_CONST) ComTxModeTrue[1]=
{
    {
        COM_DIRECT,/*ComTxModeMode*/
        0,/*ComTxModeNumberOfRepetitions*/
        0,/*ComTxModeRepetitionPeriod*/
        0,/*ComTxModeTimeOffset*/
        0,/*ComTxModeTimePeriod*/
    },
};

CONST(Com_TxModeType, COM_CONST) ComTxModeFalse[1]=
{
    {
        COM_DIRECT,/*ComTxModeMode*/
        0,/*ComTxModeNumberOfRepetitions*/
        0,/*ComTxModeRepetitionPeriod*/
        0,/*ComTxModeTimeOffset*/
        0,/*ComTxModeTimePeriod*/
    },
};

CONST(Com_TxIpduType, COM_CONST) Com_TxIPdu[COM_NUMBER_OF_TXIPDU]=
{
    {
        NULL_PTR,     /*ComIPduCallout*/
        ComConf_ComIPdu_LinPdu_ComToPduR_DSMM_1_Tx,    /*ComIPduHandleId*/
        COM_IMMEDIATE,            /*ComIPduSignalProcessing*/
        NULL_PTR,     /*ComIPduCallout*/
        COM_NORMAL,                        /*ComIPduType*/
        0,              /*ComIpduGroupRefNum*/
        NULL_PTR, 		/*ComIPduGroupsRef*/
        0,                              /*ComIpduSignalGroupRefNum*/
        NULL_PTR,                       /*ComIpduSignalGroupRef*/
        21,                             /*ComIPduSignalsRefNum*/
        &ComTxIPduSignalsRef_0[0],      /*ComIPduSignalsRef*/
        PduRConf_PduRSrcPdu_LinPdu_ComToPduR_DSMM_1_Tx,  /*PduRLayerId*/
        0,                             /*MetaDataLength*/
        8,            /*IPduNoDynSignalLength*/
        0,           /*IPduMaxDynSignalLength*/
        0,                             /*ComTxIPduBufIndex*/
        NULL_PTR,          /*ComIPduCounter*/
        0,                  /*ComMinimumDelayTime*/
        COM_CONFIRMATION,              /*ComTxIPduClearUpdateBit*/
        &ComTxModeTrue[0],             /*ComTxModeTrue*/
        &ComTxModeFalse[0],	            /*ComTxModeFalse*/
        0,                             /*ComTxIpduDM*/
        8   /*ComIPduInitLength*/
    }
};

CONST(Com_TxSignalType, COM_CONST) Com_TxSignal[COM_NUMBER_OF_TXSIGNAL]=
{
    {
        0,        /*ComBitPosition*/
        8,        /*ComBitSize*/
        NULL_PTR,    /*ComErrorNotification*/
        ComConf_ComSignal_SoftwareVersion_Tx,        /*ComSignalId*/
        FALSE,       /*ComInitialValueOnly*/
        NULL_PTR,        /*ComNotification*/
        0xffff,     /*ComSignalDataInvalidValueId*/
        COM_LITTLE_ENDIAN,        /*ComSignalEndianness*/
        0,        /*ComSignalInitValueId*/
        0,        /*ComSignalLength*/
        COM_UINT8,   /*ComSignalType*/
        0,                                      /*ComTimeout*/
        0,        /*ComIpduRefIndex*/
        NULL_PTR,                    /*ComTimeoutNotification*/
        COM_TRIGGERED,        /*ComTransferProperty*/
        0xffffffff,        /*ComUpdateBitPosition*/
        NULL_PTR,        /*ComFilter*/
        0,         /*ComSignalDataInvalidValueLength*/
        0,         /*ComSignalDataInitValueLength*/
    },
    {
        8,        /*ComBitPosition*/
        8,        /*ComBitSize*/
        NULL_PTR,    /*ComErrorNotification*/
        ComConf_ComSignal_HardwareVersion_Tx,        /*ComSignalId*/
        FALSE,       /*ComInitialValueOnly*/
        NULL_PTR,        /*ComNotification*/
        0xffff,     /*ComSignalDataInvalidValueId*/
        COM_LITTLE_ENDIAN,        /*ComSignalEndianness*/
        1,        /*ComSignalInitValueId*/
        0,        /*ComSignalLength*/
        COM_UINT8,   /*ComSignalType*/
        0,                                      /*ComTimeout*/
        0,        /*ComIpduRefIndex*/
        NULL_PTR,                    /*ComTimeoutNotification*/
        COM_TRIGGERED,        /*ComTransferProperty*/
        0xffffffff,        /*ComUpdateBitPosition*/
        NULL_PTR,        /*ComFilter*/
        0,         /*ComSignalDataInvalidValueLength*/
        0,         /*ComSignalDataInitValueLength*/
    },
    {
        16,        /*ComBitPosition*/
        3,        /*ComBitSize*/
        NULL_PTR,    /*ComErrorNotification*/
        ComConf_ComSignal_DriveSeatMsgStr_Lvlsts_Tx,        /*ComSignalId*/
        FALSE,       /*ComInitialValueOnly*/
        NULL_PTR,        /*ComNotification*/
        0xffff,     /*ComSignalDataInvalidValueId*/
        COM_LITTLE_ENDIAN,        /*ComSignalEndianness*/
        2,        /*ComSignalInitValueId*/
        0,        /*ComSignalLength*/
        COM_UINT8,   /*ComSignalType*/
        0,                                      /*ComTimeout*/
        0,        /*ComIpduRefIndex*/
        NULL_PTR,                    /*ComTimeoutNotification*/
        COM_TRIGGERED,        /*ComTransferProperty*/
        0xffffffff,        /*ComUpdateBitPosition*/
        NULL_PTR,        /*ComFilter*/
        0,         /*ComSignalDataInvalidValueLength*/
        0,         /*ComSignalDataInitValueLength*/
    },
    {
        20,        /*ComBitPosition*/
        4,        /*ComBitSize*/
        NULL_PTR,    /*ComErrorNotification*/
        ComConf_ComSignal_DriverSeatMsg_ModeSts_Tx,        /*ComSignalId*/
        FALSE,       /*ComInitialValueOnly*/
        NULL_PTR,        /*ComNotification*/
        0xffff,     /*ComSignalDataInvalidValueId*/
        COM_LITTLE_ENDIAN,        /*ComSignalEndianness*/
        3,        /*ComSignalInitValueId*/
        0,        /*ComSignalLength*/
        COM_UINT8,   /*ComSignalType*/
        0,                                      /*ComTimeout*/
        0,        /*ComIpduRefIndex*/
        NULL_PTR,                    /*ComTimeoutNotification*/
        COM_TRIGGERED,        /*ComTransferProperty*/
        0xffffffff,        /*ComUpdateBitPosition*/
        NULL_PTR,        /*ComFilter*/
        0,         /*ComSignalDataInvalidValueLength*/
        0,         /*ComSignalDataInitValueLength*/
    },
    {
        24,        /*ComBitPosition*/
        1,        /*ComBitSize*/
        NULL_PTR,    /*ComErrorNotification*/
        ComConf_ComSignal_DSMM_Rsp_Error_Tx,        /*ComSignalId*/
        FALSE,       /*ComInitialValueOnly*/
        NULL_PTR,        /*ComNotification*/
        0xffff,     /*ComSignalDataInvalidValueId*/
        COM_LITTLE_ENDIAN,        /*ComSignalEndianness*/
        0,     /*ComSignalInitValueId*/
        0,        /*ComSignalLength*/
        COM_BOOLEAN,   /*ComSignalType*/
        0,                                      /*ComTimeout*/
        0,        /*ComIpduRefIndex*/
        NULL_PTR,                    /*ComTimeoutNotification*/
        COM_TRIGGERED,        /*ComTransferProperty*/
        0xffffffff,        /*ComUpdateBitPosition*/
        NULL_PTR,        /*ComFilter*/
        0,         /*ComSignalDataInvalidValueLength*/
        0,         /*ComSignalDataInitValueLength*/
    },
    {
        25,        /*ComBitPosition*/
        2,        /*ComBitSize*/
        NULL_PTR,    /*ComErrorNotification*/
        ComConf_ComSignal_DrvLumSpprtSwtFct_Tx,        /*ComSignalId*/
        FALSE,       /*ComInitialValueOnly*/
        NULL_PTR,        /*ComNotification*/
        0xffff,     /*ComSignalDataInvalidValueId*/
        COM_LITTLE_ENDIAN,        /*ComSignalEndianness*/
        4,        /*ComSignalInitValueId*/
        0,        /*ComSignalLength*/
        COM_UINT8,   /*ComSignalType*/
        0,                                      /*ComTimeout*/
        0,        /*ComIpduRefIndex*/
        NULL_PTR,                    /*ComTimeoutNotification*/
        COM_TRIGGERED,        /*ComTransferProperty*/
        0xffffffff,        /*ComUpdateBitPosition*/
        NULL_PTR,        /*ComFilter*/
        0,         /*ComSignalDataInvalidValueLength*/
        0,         /*ComSignalDataInitValueLength*/
    },
    {
        27,        /*ComBitPosition*/
        3,        /*ComBitSize*/
        NULL_PTR,    /*ComErrorNotification*/
        ComConf_ComSignal_DrvSeatLeSideBolsterFltSt_Tx,        /*ComSignalId*/
        FALSE,       /*ComInitialValueOnly*/
        NULL_PTR,        /*ComNotification*/
        0xffff,     /*ComSignalDataInvalidValueId*/
        COM_LITTLE_ENDIAN,        /*ComSignalEndianness*/
        5,        /*ComSignalInitValueId*/
        0,        /*ComSignalLength*/
        COM_UINT8,   /*ComSignalType*/
        0,                                      /*ComTimeout*/
        0,        /*ComIpduRefIndex*/
        NULL_PTR,                    /*ComTimeoutNotification*/
        COM_TRIGGERED,        /*ComTransferProperty*/
        0xffffffff,        /*ComUpdateBitPosition*/
        NULL_PTR,        /*ComFilter*/
        0,         /*ComSignalDataInvalidValueLength*/
        0,         /*ComSignalDataInitValueLength*/
    },
    {
        32,        /*ComBitPosition*/
        3,        /*ComBitSize*/
        NULL_PTR,    /*ComErrorNotification*/
        ComConf_ComSignal_DrvSeatRiSideBolsterFltSt_Tx,        /*ComSignalId*/
        FALSE,       /*ComInitialValueOnly*/
        NULL_PTR,        /*ComNotification*/
        0xffff,     /*ComSignalDataInvalidValueId*/
        COM_LITTLE_ENDIAN,        /*ComSignalEndianness*/
        6,        /*ComSignalInitValueId*/
        0,        /*ComSignalLength*/
        COM_UINT8,   /*ComSignalType*/
        0,                                      /*ComTimeout*/
        0,        /*ComIpduRefIndex*/
        NULL_PTR,                    /*ComTimeoutNotification*/
        COM_TRIGGERED,        /*ComTransferProperty*/
        0xffffffff,        /*ComUpdateBitPosition*/
        NULL_PTR,        /*ComFilter*/
        0,         /*ComSignalDataInvalidValueLength*/
        0,         /*ComSignalDataInitValueLength*/
    },
    {
        35,        /*ComBitPosition*/
        1,        /*ComBitSize*/
        NULL_PTR,    /*ComErrorNotification*/
        ComConf_ComSignal_DrvSeatLeSideBolsterNTCOverT_Tx,        /*ComSignalId*/
        FALSE,       /*ComInitialValueOnly*/
        NULL_PTR,        /*ComNotification*/
        0xffff,     /*ComSignalDataInvalidValueId*/
        COM_LITTLE_ENDIAN,        /*ComSignalEndianness*/
        1,     /*ComSignalInitValueId*/
        0,        /*ComSignalLength*/
        COM_BOOLEAN,   /*ComSignalType*/
        0,                                      /*ComTimeout*/
        0,        /*ComIpduRefIndex*/
        NULL_PTR,                    /*ComTimeoutNotification*/
        COM_TRIGGERED,        /*ComTransferProperty*/
        0xffffffff,        /*ComUpdateBitPosition*/
        NULL_PTR,        /*ComFilter*/
        0,         /*ComSignalDataInvalidValueLength*/
        0,         /*ComSignalDataInitValueLength*/
    },
    {
        36,        /*ComBitPosition*/
        1,        /*ComBitSize*/
        NULL_PTR,    /*ComErrorNotification*/
        ComConf_ComSignal_DrvSeatRiSideBolsterNTCOverT_Tx,        /*ComSignalId*/
        FALSE,       /*ComInitialValueOnly*/
        NULL_PTR,        /*ComNotification*/
        0xffff,     /*ComSignalDataInvalidValueId*/
        COM_LITTLE_ENDIAN,        /*ComSignalEndianness*/
        2,     /*ComSignalInitValueId*/
        0,        /*ComSignalLength*/
        COM_BOOLEAN,   /*ComSignalType*/
        0,                                      /*ComTimeout*/
        0,        /*ComIpduRefIndex*/
        NULL_PTR,                    /*ComTimeoutNotification*/
        COM_TRIGGERED,        /*ComTransferProperty*/
        0xffffffff,        /*ComUpdateBitPosition*/
        NULL_PTR,        /*ComFilter*/
        0,         /*ComSignalDataInvalidValueLength*/
        0,         /*ComSignalDataInitValueLength*/
    },
    {
        37,        /*ComBitPosition*/
        1,        /*ComBitSize*/
        NULL_PTR,    /*ComErrorNotification*/
        ComConf_ComSignal_DrvSeatMainAirwayPSnsrFlt_Tx,        /*ComSignalId*/
        FALSE,       /*ComInitialValueOnly*/
        NULL_PTR,        /*ComNotification*/
        0xffff,     /*ComSignalDataInvalidValueId*/
        COM_LITTLE_ENDIAN,        /*ComSignalEndianness*/
        3,     /*ComSignalInitValueId*/
        0,        /*ComSignalLength*/
        COM_BOOLEAN,   /*ComSignalType*/
        0,                                      /*ComTimeout*/
        0,        /*ComIpduRefIndex*/
        NULL_PTR,                    /*ComTimeoutNotification*/
        COM_TRIGGERED,        /*ComTransferProperty*/
        0xffffffff,        /*ComUpdateBitPosition*/
        NULL_PTR,        /*ComFilter*/
        0,         /*ComSignalDataInvalidValueLength*/
        0,         /*ComSignalDataInitValueLength*/
    },
    {
        38,        /*ComBitPosition*/
        1,        /*ComBitSize*/
        NULL_PTR,    /*ComErrorNotification*/
        ComConf_ComSignal_DrvSeatLeSideBolsterPSnsrFlt_Tx,        /*ComSignalId*/
        FALSE,       /*ComInitialValueOnly*/
        NULL_PTR,        /*ComNotification*/
        0xffff,     /*ComSignalDataInvalidValueId*/
        COM_LITTLE_ENDIAN,        /*ComSignalEndianness*/
        4,     /*ComSignalInitValueId*/
        0,        /*ComSignalLength*/
        COM_BOOLEAN,   /*ComSignalType*/
        0,                                      /*ComTimeout*/
        0,        /*ComIpduRefIndex*/
        NULL_PTR,                    /*ComTimeoutNotification*/
        COM_TRIGGERED,        /*ComTransferProperty*/
        0xffffffff,        /*ComUpdateBitPosition*/
        NULL_PTR,        /*ComFilter*/
        0,         /*ComSignalDataInvalidValueLength*/
        0,         /*ComSignalDataInitValueLength*/
    },
    {
        39,        /*ComBitPosition*/
        1,        /*ComBitSize*/
        NULL_PTR,    /*ComErrorNotification*/
        ComConf_ComSignal_DrvSeatRiSideBolsterPSnsrFlt_Tx,        /*ComSignalId*/
        FALSE,       /*ComInitialValueOnly*/
        NULL_PTR,        /*ComNotification*/
        0xffff,     /*ComSignalDataInvalidValueId*/
        COM_LITTLE_ENDIAN,        /*ComSignalEndianness*/
        5,     /*ComSignalInitValueId*/
        0,        /*ComSignalLength*/
        COM_BOOLEAN,   /*ComSignalType*/
        0,                                      /*ComTimeout*/
        0,        /*ComIpduRefIndex*/
        NULL_PTR,                    /*ComTimeoutNotification*/
        COM_TRIGGERED,        /*ComTransferProperty*/
        0xffffffff,        /*ComUpdateBitPosition*/
        NULL_PTR,        /*ComFilter*/
        0,         /*ComSignalDataInvalidValueLength*/
        0,         /*ComSignalDataInitValueLength*/
    },
    {
        40,        /*ComBitPosition*/
        8,        /*ComBitSize*/
        NULL_PTR,    /*ComErrorNotification*/
        ComConf_ComSignal_AirPotPressure_Tx,        /*ComSignalId*/
        FALSE,       /*ComInitialValueOnly*/
        NULL_PTR,        /*ComNotification*/
        0xffff,     /*ComSignalDataInvalidValueId*/
        COM_LITTLE_ENDIAN,        /*ComSignalEndianness*/
        7,        /*ComSignalInitValueId*/
        0,        /*ComSignalLength*/
        COM_UINT8,   /*ComSignalType*/
        0,                                      /*ComTimeout*/
        0,        /*ComIpduRefIndex*/
        NULL_PTR,                    /*ComTimeoutNotification*/
        COM_TRIGGERED,        /*ComTransferProperty*/
        0xffffffff,        /*ComUpdateBitPosition*/
        NULL_PTR,        /*ComFilter*/
        0,         /*ComSignalDataInvalidValueLength*/
        0,         /*ComSignalDataInitValueLength*/
    },
    {
        48,        /*ComBitPosition*/
        1,        /*ComBitSize*/
        NULL_PTR,    /*ComErrorNotification*/
        ComConf_ComSignal_AirPotPressureSnsFlt_Tx,        /*ComSignalId*/
        FALSE,       /*ComInitialValueOnly*/
        NULL_PTR,        /*ComNotification*/
        0xffff,     /*ComSignalDataInvalidValueId*/
        COM_LITTLE_ENDIAN,        /*ComSignalEndianness*/
        6,     /*ComSignalInitValueId*/
        0,        /*ComSignalLength*/
        COM_BOOLEAN,   /*ComSignalType*/
        0,                                      /*ComTimeout*/
        0,        /*ComIpduRefIndex*/
        NULL_PTR,                    /*ComTimeoutNotification*/
        COM_TRIGGERED,        /*ComTransferProperty*/
        0xffffffff,        /*ComUpdateBitPosition*/
        NULL_PTR,        /*ComFilter*/
        0,         /*ComSignalDataInvalidValueLength*/
        0,         /*ComSignalDataInitValueLength*/
    },
    {
        49,        /*ComBitPosition*/
        2,        /*ComBitSize*/
        NULL_PTR,    /*ComErrorNotification*/
        ComConf_ComSignal_VoltageState_Tx,        /*ComSignalId*/
        FALSE,       /*ComInitialValueOnly*/
        NULL_PTR,        /*ComNotification*/
        0xffff,     /*ComSignalDataInvalidValueId*/
        COM_LITTLE_ENDIAN,        /*ComSignalEndianness*/
        8,        /*ComSignalInitValueId*/
        0,        /*ComSignalLength*/
        COM_UINT8,   /*ComSignalType*/
        0,                                      /*ComTimeout*/
        0,        /*ComIpduRefIndex*/
        NULL_PTR,                    /*ComTimeoutNotification*/
        COM_TRIGGERED,        /*ComTransferProperty*/
        0xffffffff,        /*ComUpdateBitPosition*/
        NULL_PTR,        /*ComFilter*/
        0,         /*ComSignalDataInvalidValueLength*/
        0,         /*ComSignalDataInitValueLength*/
    },
    {
        51,        /*ComBitPosition*/
        1,        /*ComBitSize*/
        NULL_PTR,    /*ComErrorNotification*/
        ComConf_ComSignal_PumFlt_Tx,        /*ComSignalId*/
        FALSE,       /*ComInitialValueOnly*/
        NULL_PTR,        /*ComNotification*/
        0xffff,     /*ComSignalDataInvalidValueId*/
        COM_LITTLE_ENDIAN,        /*ComSignalEndianness*/
        7,     /*ComSignalInitValueId*/
        0,        /*ComSignalLength*/
        COM_BOOLEAN,   /*ComSignalType*/
        0,                                      /*ComTimeout*/
        0,        /*ComIpduRefIndex*/
        NULL_PTR,                    /*ComTimeoutNotification*/
        COM_TRIGGERED,        /*ComTransferProperty*/
        0xffffffff,        /*ComUpdateBitPosition*/
        NULL_PTR,        /*ComFilter*/
        0,         /*ComSignalDataInvalidValueLength*/
        0,         /*ComSignalDataInitValueLength*/
    },
    {
        52,        /*ComBitPosition*/
        1,        /*ComBitSize*/
        NULL_PTR,    /*ComErrorNotification*/
        ComConf_ComSignal_ValveFlt_Tx,        /*ComSignalId*/
        FALSE,       /*ComInitialValueOnly*/
        NULL_PTR,        /*ComNotification*/
        0xffff,     /*ComSignalDataInvalidValueId*/
        COM_LITTLE_ENDIAN,        /*ComSignalEndianness*/
        8,     /*ComSignalInitValueId*/
        0,        /*ComSignalLength*/
        COM_BOOLEAN,   /*ComSignalType*/
        0,                                      /*ComTimeout*/
        0,        /*ComIpduRefIndex*/
        NULL_PTR,                    /*ComTimeoutNotification*/
        COM_TRIGGERED,        /*ComTransferProperty*/
        0xffffffff,        /*ComUpdateBitPosition*/
        NULL_PTR,        /*ComFilter*/
        0,         /*ComSignalDataInvalidValueLength*/
        0,         /*ComSignalDataInitValueLength*/
    },
    {
        53,        /*ComBitPosition*/
        1,        /*ComBitSize*/
        NULL_PTR,    /*ComErrorNotification*/
        ComConf_ComSignal_EnvPressureSnsFlt_Tx,        /*ComSignalId*/
        FALSE,       /*ComInitialValueOnly*/
        NULL_PTR,        /*ComNotification*/
        0xffff,     /*ComSignalDataInvalidValueId*/
        COM_LITTLE_ENDIAN,        /*ComSignalEndianness*/
        9,     /*ComSignalInitValueId*/
        0,        /*ComSignalLength*/
        COM_BOOLEAN,   /*ComSignalType*/
        0,                                      /*ComTimeout*/
        0,        /*ComIpduRefIndex*/
        NULL_PTR,                    /*ComTimeoutNotification*/
        COM_TRIGGERED,        /*ComTransferProperty*/
        0xffffffff,        /*ComUpdateBitPosition*/
        NULL_PTR,        /*ComFilter*/
        0,         /*ComSignalDataInvalidValueLength*/
        0,         /*ComSignalDataInitValueLength*/
    },
    {
        56,        /*ComBitPosition*/
        3,        /*ComBitSize*/
        NULL_PTR,    /*ComErrorNotification*/
        ComConf_ComSignal_DrvSeatLeSidBolsterInflatuinSts_Tx,        /*ComSignalId*/
        FALSE,       /*ComInitialValueOnly*/
        NULL_PTR,        /*ComNotification*/
        0xffff,     /*ComSignalDataInvalidValueId*/
        COM_LITTLE_ENDIAN,        /*ComSignalEndianness*/
        9,        /*ComSignalInitValueId*/
        0,        /*ComSignalLength*/
        COM_UINT8,   /*ComSignalType*/
        0,                                      /*ComTimeout*/
        0,        /*ComIpduRefIndex*/
        NULL_PTR,                    /*ComTimeoutNotification*/
        COM_TRIGGERED,        /*ComTransferProperty*/
        0xffffffff,        /*ComUpdateBitPosition*/
        NULL_PTR,        /*ComFilter*/
        0,         /*ComSignalDataInvalidValueLength*/
        0,         /*ComSignalDataInitValueLength*/
    },
    {
        59,        /*ComBitPosition*/
        3,        /*ComBitSize*/
        NULL_PTR,    /*ComErrorNotification*/
        ComConf_ComSignal_DrvSeatRiSideBolsterInflationSts_Tx,        /*ComSignalId*/
        FALSE,       /*ComInitialValueOnly*/
        NULL_PTR,        /*ComNotification*/
        0xffff,     /*ComSignalDataInvalidValueId*/
        COM_LITTLE_ENDIAN,        /*ComSignalEndianness*/
        10,        /*ComSignalInitValueId*/
        0,        /*ComSignalLength*/
        COM_UINT8,   /*ComSignalType*/
        0,                                      /*ComTimeout*/
        0,        /*ComIpduRefIndex*/
        NULL_PTR,                    /*ComTimeoutNotification*/
        COM_TRIGGERED,        /*ComTransferProperty*/
        0xffffffff,        /*ComUpdateBitPosition*/
        NULL_PTR,        /*ComFilter*/
        0,         /*ComSignalDataInvalidValueLength*/
        0,         /*ComSignalDataInitValueLength*/
    }
};

CONST(Com_RxSignalType, COM_CONST) Com_RxSignal[COM_NUMBER_OF_RXSIGNAL]=
{
    {
        24,    /*ComBitPosition*/
        3,    /*ComBitSize*/
        0,      /*ComFirstTimeout*/
        0,      /*ComTimeout*/
        0xff,    /*ComTimeCntIndex*/
        0,     /*ComIpduRefIndex*/
        ComConf_ComSignal_FuelVehPowerMode_Rx,    /*ComSignalId*/
        COM_INVALID_ACTION_NOTIFY,    /*ComDataInvalidAction*/
        NULL_PTR,
        NULL_PTR,
        COM_TIMEOUT_ACTION_NONE,    /*ComRxDataTimeoutAction*/
        0xffff,     /*ComSignalDataInvalidValueId*/
        COM_LITTLE_ENDIAN,    /*ComSignalEndianness*/
        11,        /*ComSignalInitValueId*/
        0,    /*ComSignalLength*/
        COM_UINT8,    /*ComSignalType*/
        NULL_PTR,       /*ComTimeoutNotification.*/
        0xffffffff,        /*ComUpdateBitPosition*/
        NULL_PTR,        /*ComFilter*/
        0,         /*ComSignalDataInvalidValueLength*/
        0,         /*ComSignalDataInitValueLength*/
        0xffff,    /*GWUpdateStateId*/
        0xffff,		/*GWSignalBufferId*/
    },
    {
        8,    /*ComBitPosition*/
        3,    /*ComBitSize*/
        0,      /*ComFirstTimeout*/
        0,      /*ComTimeout*/
        0xff,    /*ComTimeCntIndex*/
        0,     /*ComIpduRefIndex*/
        ComConf_ComSignal_DriverSeatMsgStr_Lvlcmd_Rx,    /*ComSignalId*/
        COM_INVALID_ACTION_NOTIFY,    /*ComDataInvalidAction*/
        NULL_PTR,
        NULL_PTR,
        COM_TIMEOUT_ACTION_NONE,    /*ComRxDataTimeoutAction*/
        0xffff,     /*ComSignalDataInvalidValueId*/
        COM_LITTLE_ENDIAN,    /*ComSignalEndianness*/
        12,        /*ComSignalInitValueId*/
        0,    /*ComSignalLength*/
        COM_UINT8,    /*ComSignalType*/
        NULL_PTR,       /*ComTimeoutNotification.*/
        0xffffffff,        /*ComUpdateBitPosition*/
        NULL_PTR,        /*ComFilter*/
        0,         /*ComSignalDataInvalidValueLength*/
        0,         /*ComSignalDataInitValueLength*/
        0xffff,    /*GWUpdateStateId*/
        0xffff,		/*GWSignalBufferId*/
    },
    {
        28,    /*ComBitPosition*/
        4,    /*ComBitSize*/
        0,      /*ComFirstTimeout*/
        0,      /*ComTimeout*/
        0xff,    /*ComTimeCntIndex*/
        0,     /*ComIpduRefIndex*/
        ComConf_ComSignal_DriveSeatMsg_ModeCmd_Rx,    /*ComSignalId*/
        COM_INVALID_ACTION_NOTIFY,    /*ComDataInvalidAction*/
        NULL_PTR,
        NULL_PTR,
        COM_TIMEOUT_ACTION_NONE,    /*ComRxDataTimeoutAction*/
        0xffff,     /*ComSignalDataInvalidValueId*/
        COM_LITTLE_ENDIAN,    /*ComSignalEndianness*/
        13,        /*ComSignalInitValueId*/
        0,    /*ComSignalLength*/
        COM_UINT8,    /*ComSignalType*/
        NULL_PTR,       /*ComTimeoutNotification.*/
        0xffffffff,        /*ComUpdateBitPosition*/
        NULL_PTR,        /*ComFilter*/
        0,         /*ComSignalDataInvalidValueLength*/
        0,         /*ComSignalDataInitValueLength*/
        0xffff,    /*GWUpdateStateId*/
        0xffff,		/*GWSignalBufferId*/
    },
    {
        32,    /*ComBitPosition*/
        2,    /*ComBitSize*/
        0,      /*ComFirstTimeout*/
        0,      /*ComTimeout*/
        0xff,    /*ComTimeCntIndex*/
        0,     /*ComIpduRefIndex*/
        ComConf_ComSignal_PowerMode_Rx,    /*ComSignalId*/
        COM_INVALID_ACTION_NOTIFY,    /*ComDataInvalidAction*/
        NULL_PTR,
        NULL_PTR,
        COM_TIMEOUT_ACTION_NONE,    /*ComRxDataTimeoutAction*/
        0xffff,     /*ComSignalDataInvalidValueId*/
        COM_LITTLE_ENDIAN,    /*ComSignalEndianness*/
        14,        /*ComSignalInitValueId*/
        0,    /*ComSignalLength*/
        COM_UINT8,    /*ComSignalType*/
        NULL_PTR,       /*ComTimeoutNotification.*/
        0xffffffff,        /*ComUpdateBitPosition*/
        NULL_PTR,        /*ComFilter*/
        0,         /*ComSignalDataInvalidValueLength*/
        0,         /*ComSignalDataInitValueLength*/
        0xffff,    /*GWUpdateStateId*/
        0xffff,		/*GWSignalBufferId*/
    },
    {
        44,    /*ComBitPosition*/
        3,    /*ComBitSize*/
        0,      /*ComFirstTimeout*/
        0,      /*ComTimeout*/
        0xff,    /*ComTimeCntIndex*/
        0,     /*ComIpduRefIndex*/
        ComConf_ComSignal_APC_Level_Limit_Rx,    /*ComSignalId*/
        COM_INVALID_ACTION_NOTIFY,    /*ComDataInvalidAction*/
        NULL_PTR,
        NULL_PTR,
        COM_TIMEOUT_ACTION_NONE,    /*ComRxDataTimeoutAction*/
        0xffff,     /*ComSignalDataInvalidValueId*/
        COM_LITTLE_ENDIAN,    /*ComSignalEndianness*/
        15,        /*ComSignalInitValueId*/
        0,    /*ComSignalLength*/
        COM_UINT8,    /*ComSignalType*/
        NULL_PTR,       /*ComTimeoutNotification.*/
        0xffffffff,        /*ComUpdateBitPosition*/
        NULL_PTR,        /*ComFilter*/
        0,         /*ComSignalDataInvalidValueLength*/
        0,         /*ComSignalDataInitValueLength*/
        0xffff,    /*GWUpdateStateId*/
        0xffff,		/*GWSignalBufferId*/
    },
    {
        16,    /*ComBitPosition*/
        3,    /*ComBitSize*/
        0,      /*ComFirstTimeout*/
        0,      /*ComTimeout*/
        0xff,    /*ComTimeCntIndex*/
        1,     /*ComIpduRefIndex*/
        ComConf_ComSignal_DrvSeatLeSideBolsterInflationReq_Rx,    /*ComSignalId*/
        COM_INVALID_ACTION_NOTIFY,    /*ComDataInvalidAction*/
        NULL_PTR,
        NULL_PTR,
        COM_TIMEOUT_ACTION_NONE,    /*ComRxDataTimeoutAction*/
        0xffff,     /*ComSignalDataInvalidValueId*/
        COM_LITTLE_ENDIAN,    /*ComSignalEndianness*/
        16,        /*ComSignalInitValueId*/
        0,    /*ComSignalLength*/
        COM_UINT8,    /*ComSignalType*/
        NULL_PTR,       /*ComTimeoutNotification.*/
        0xffffffff,        /*ComUpdateBitPosition*/
        NULL_PTR,        /*ComFilter*/
        0,         /*ComSignalDataInvalidValueLength*/
        0,         /*ComSignalDataInitValueLength*/
        0xffff,    /*GWUpdateStateId*/
        0xffff,		/*GWSignalBufferId*/
    },
    {
        19,    /*ComBitPosition*/
        3,    /*ComBitSize*/
        0,      /*ComFirstTimeout*/
        0,      /*ComTimeout*/
        0xff,    /*ComTimeCntIndex*/
        1,     /*ComIpduRefIndex*/
        ComConf_ComSignal_DrvSeatRisSideBolsterInflationReq_Rx,    /*ComSignalId*/
        COM_INVALID_ACTION_NOTIFY,    /*ComDataInvalidAction*/
        NULL_PTR,
        NULL_PTR,
        COM_TIMEOUT_ACTION_NONE,    /*ComRxDataTimeoutAction*/
        0xffff,     /*ComSignalDataInvalidValueId*/
        COM_LITTLE_ENDIAN,    /*ComSignalEndianness*/
        17,        /*ComSignalInitValueId*/
        0,    /*ComSignalLength*/
        COM_UINT8,    /*ComSignalType*/
        NULL_PTR,       /*ComTimeoutNotification.*/
        0xffffffff,        /*ComUpdateBitPosition*/
        NULL_PTR,        /*ComFilter*/
        0,         /*ComSignalDataInvalidValueLength*/
        0,         /*ComSignalDataInitValueLength*/
        0xffff,    /*GWUpdateStateId*/
        0xffff,		/*GWSignalBufferId*/
    }
};

CONST(Com_ConfigType, COM_CONST_PBCFG) Com_Config =
{
    &Com_RxIPdu[0],             /*ComRxIPdu,*/
    &Com_TxIPdu[0],             /*ComTxIPdu*/
    &Com_RxSignal[0],           /*ComRxSignal*/
    &Com_TxSignal[0],           /*ComTxSignal*/
    NULL_PTR,                   /*ComRxSignalGroup*/
    NULL_PTR,                   /*ComTxSignalGroup*/
    NULL_PTR,                   /*ComRxGroupSignal*/
    NULL_PTR,                   /*ComTxGroupSignal*/
    NULL_PTR,                   /*ComGwMapping*/
};
#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

/*====================================================================================================*
 *                                      LOCAL FUNCTION PROTOTYPES                                   
 *====================================================================================================*/


/*====================================================================================================*
 *                                           LOCAL FUNCTIONS                                        
 *====================================================================================================*/


/*====================================================================================================*
 *                                          GLOBAL FUNCTIONS                                        
 *====================================================================================================*/

#ifdef __cplusplus
}
#endif
/** @} */
