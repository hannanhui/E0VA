/**
 * @file        Com.h
 * @brief       Module header file of PduR, including version information,
 *              type definitions and all service interface declarations.
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

/* PRQA S 0292, 0288, 1503, 1505, 0857, 0791, 0828, 0647, 3453 EOF #
 *
 * 1.0292 -- Violates MISRA 2004 Required Rule 3.1, Source file has comments containing one of the*
 * characters '$', '@' or '`'.
 *
 * 2.0288 -- Violates MISRA 2004 Required Rule 3.1, Source file has comments containing characters*
 * which are not members of the basic source character set.
 *
 * 3.1503 -- Violates MISRA 2004 Required Rule 14.1, The function is defined but is not used within*
 *  this project.
 *
 * 4.1505 -- Violates MISRA 2004 Required Rule 8.10, The function is only referenced in the
 * translation* unit where it is defined.
 *
 * 5.0857 -- Violates MISRA 2004 Required Rule 1.1, Number of macro definitions exceeds 1024 -
 * program* does not conform strictly to ISO:C90.
 *
 * 6.0791 -- Violates MISRA 2004 Required Rule 5.1, Macro identifier does not differ from other macro*
 *  identifier(s) within the specified number of significant characters.
 *
 * 7.0828 -- Violates MISRA 2004 Required Rule 1.1, More than 8 levels of nested conditional
 * inclusion* - program does not conform strictly to ISO:C90.
 *
 * 8.0647 -- Violates MISRA 2004 Required Rule 1.1, Number of enumeration constants exceeds 127-program
 * does not conform strictly to ISO:C90.
 *
 * @page misra_violations MISRA-C:2004 violations
 */

#ifndef COM_H
#define COM_H

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
/* @req [SWS_Com_00796] */
#include "Com_Cfg.h"
#include "Com_Types.h"
#include "ComStack_Types.h"
#if(STD_ON == COM_DEV_ERROR_DETECT)
#include "Det.h"
#endif
/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/
#define COM_VENDOR_ID               		0U
#define COM_MODULE_ID               		50U
#define COM_AR_RELEASE_MAJOR_VERSION     	4U
#define COM_AR_RELEASE_MINOR_VERSION      	2U
#define COM_AR_RELEASE_REVISION_VERSION     2U
#define COM_SW_MAJOR_VERSION      			1U
#define COM_SW_MINOR_VERSION      			2U
#define COM_SW_PATCH_VERSION      			0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
#if(COM_VENDOR_ID != COM_CFG_VENDOR_ID )
#error "Com.h and Com_Cfg.h have different vendor id"
#endif

#if(\
      (COM_AR_RELEASE_MAJOR_VERSION != COM_CFG_AR_RELEASE_MAJOR_VERSION) || \
      (COM_AR_RELEASE_MINOR_VERSION != COM_CFG_AR_RELEASE_MINOR_VERSION) || \
      (COM_AR_RELEASE_REVISION_VERSION != COM_CFG_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of Com.h and Com_Cfg.h are different "
#endif

/* Check if current file and Com.h header file are of the same software version */
#if(\
      (COM_SW_MAJOR_VERSION != COM_CFG_SW_MAJOR_VERSION) || \
      (COM_SW_MINOR_VERSION != COM_CFG_SW_MINOR_VERSION) ||\
	  (COM_SW_PATCH_VERSION != COM_CFG_SW_PATCH_VERSION)\
      )
#error "Software Version Number of Com.h and Com_Cfg.h are different "
#endif

#if(COM_VENDOR_ID != COM_TYPES_VENDOR_ID )
#error "Com_Types.h and Com.h have different vendor id"
#endif

#if(\
      (COM_AR_RELEASE_MAJOR_VERSION != COM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
      (COM_AR_RELEASE_MINOR_VERSION != COM_TYPES_AR_RELEASE_MINOR_VERSION) || \
      (COM_AR_RELEASE_REVISION_VERSION != COM_TYPES_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of Com_Types.h and Com.h are different "
#endif

/* Check if current file and Com.h header file are of the same software version */
#if(\
      (COM_SW_MAJOR_VERSION != COM_TYPES_SW_MAJOR_VERSION) || \
      (COM_SW_MINOR_VERSION != COM_TYPES_SW_MINOR_VERSION) ||\
	  (COM_SW_PATCH_VERSION != COM_TYPES_SW_PATCH_VERSION)\
      )
#error "Software Version Number of Com_Types.h and Com.h are different "
#endif

#ifndef DISABLE_INTERMOD_VERSION_CHECK

#if(\
      (COM_AR_RELEASE_MAJOR_VERSION != COMTYPE_AR_RELEASE_MAJOR_VERSION) || \
      (COM_AR_RELEASE_MINOR_VERSION != COMTYPE_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of ComStack_Types.h and Com.h are different "
#endif

#endif
/*====================================================================================================*
 *                                             CONSTANTS
 *====================================================================================================*/

/*====================================================================================================*
 *                                         DEFINES AND MACROS
 *====================================================================================================*/

#define COM_SERVICE_NOT_AVAILABLE              ((uint8)0x80U)
#define COM_BUSY                               ((uint8)0x81U)
#define COM_INSTANCE_ID                        ((uint8)0x00U)
/* PRQA S 0828 EOF # violate MISRA_2004_Rule_1.1:The program has no more than eight layers*/
#if(STD_ON == COM_DEV_ERROR_DETECT)
/* Service ID */
/* @req [SWS_Com_00442] */
/**
 * @brief service ID of function: Com_Init
 */
#define COM_SID_INIT                            ((uint8)0x01U)
/**
 * @brief service ID of function: Com_DeInit
 */
#define COM_SID_DEINIT                          ((uint8)0x02U)
/**
 * @brief service ID of function: Com_IpduGroupControl
 */
#define COM_SID_IPDUGROUPCONTROL                ((uint8)0x03U)
/**
 * @brief service ID of function: Com_ReceptionDMControl
 */
#define COM_SID_RECEPTIONDMCONTROL              ((uint8)0x06U)
/**
 * @brief service ID of function: Com_GetStatus
 */
#define COM_SID_GETSTATUS                       ((uint8)0x07U)
/**
 * @brief service ID of function: Com_GetVersionInfo
 */
#define COM_SID_GETVERSIONINFO                  ((uint8)0x09U)
/**
 * @brief service ID of function: Com_ClearIpduGroupVector
 */
#define COM_SID_CLEARIPDUGROUPVECTOR            ((uint8)0x1CU)
/**
 * @brief service ID of function: Com_SetIpduGroup
 */
#define COM_SID_SETIPDUGROUP                    ((uint8)0x1DU)
/**
 * @brief service ID of function: Com_SendSignal
 */
#define COM_SID_SENDSIGNAL                      ((uint8)0x0AU)
/**
 * @brief service ID of function: Com_SendDynSignal
 */
#define COM_SID_SENDDYNSIGNAL                   ((uint8)0x21U)
/**
 * @brief service ID of function: Com_ReceiveSignal
 */
#define COM_SID_RECEIVESIGNAL                   ((uint8)0x0BU)
/**
 * @brief service ID of function: Com_ReceiveDynSignal
 */
#define COM_SID_RECEIVEDYNSIGNAL                ((uint8)0x22U)
/**
 * @brief service ID of function: Com_UpdateShadowSignal
 */
#define COM_SID_UPDATESHADOWSIGNAL              ((uint8)0x0CU)
/**
 * @brief service ID of function: Com_SendSignalGroup
 */
#define COM_SID_SENDSIGNALGROUP                 ((uint8)0x0DU)
/**
 * @brief service ID of function: Com_ReceiveSignalGroup
 */
#define COM_SID_RECEIVESIGNALGROUP              ((uint8)0x0EU)
/**
 * @brief service ID of function: Com_ReceiveShadowSignal
 */
#define COM_SID_RECEIVESHADOWSIGNAL             ((uint8)0x0FU)
/**
 * @brief service ID of function: Com_SendSignalGroupArray
 */
#define COM_SID_SENDSIGNALGROUPARRAY            ((uint8)0x23U)
/**
 * @brief service ID of function: Com_ReceiveSignalGroupArray
 */
#define COM_SID_RECEIVESIGNALGROUPARRAY         ((uint8)0x24U)
/**
 * @brief service ID of function: Com_InvalidSignal
 */
#define COM_SID_INVALIDATESIGNAL                ((uint8)0x10U)
/**
 * @brief service ID of function: Com_InvalidShadowSignal
 */
#define COM_SID_INVALIDATESHADOWSIGNAL          ((uint8)0x16U)
/**
 * @brief service ID of function: Com_InvalidSignalGroup
 */
#define COM_SID_INVALIDATESIGNALGROUP           ((uint8)0x1BU)
/**
 * @brief service ID of function: Com_TriggerIPDUSend
 */
#define COM_SID_TRIGGERIPDUSEND                 ((uint8)0x17U)
/**
 * @brief service ID of function: Com_TriggerIPDUSendWithMetaData
 */
#define COM_SID_TRIGGERIPDUSENDWITHMETADATA     ((uint8)0x28U)
/**
 * @brief service ID of function: Com_SwitchIpduMode
 */
#define COM_SID_SWITCHIPDUTXMODE                ((uint8)0x27U)
/**
 * @brief service ID of function: Com_TriggerTransmit
 */
#define COM_SID_TRIGGERTRANSMIT                 ((uint8)0x41U)
/**
 * @brief service ID of function: Com_RxIndication
 */
#define COM_SID_RXINDICATION                    ((uint8)0x42U)
/**
 * @brief service ID of function: Com_TpRxIndication
 */
#define COM_SID_TPRXINDICATION                  ((uint8)0x45U)
/**
 * @brief service ID of function: Com_TxConfirmation
 */
#define COM_SID_TXCONFIRMATION                  ((uint8)0x40U)
/**
 * @brief service ID of function: Com_TpTxConfirmation
 */
#define COM_SID_TPTXCONFIRMATION                ((uint8)0x48U)
/**
 * @brief service ID of function: Com_StartOfReception
 */
#define COM_SID_STARTOFRECEPTION                ((uint8)0x46U)
/**
 * @brief service ID of function: Com_CopyRxData
 */
#define COM_SID_COPYRXDATA                      ((uint8)0x44U)
/**
 * @brief service ID of function: Com_CopyTxData
 */
#define COM_SID_COPYTXDATA                      ((uint8)0x43U)
/**
 * @brief service ID of function: Com_MainfunctionRx
 */
#define COM_SID_MAINFUNCTIONRX                  ((uint8)0x18U)
/**
 * @brief service ID of function: Com_MainfunctionTx
 */
#define COM_SID_MAINFUNCTIONTX                  ((uint8)0x19U)
/**
 * @brief service ID of function: Com_MainfunctionRouteSignals
 */
#define COM_SID_MAINFUNCTIONROUTESIGNALS        ((uint8)0x1AU)
/* Error detection */
/* @req [SWS_Com_00803] */
#define COM_E_PARAM                            ((uint8)0x01U)
/* @req [SWS_Com_00804] */
#define COM_E_UNINIT                           ((uint8)0x02U)
/* @req [SWS_Com_00805] */
#define COM_E_PARAM_POINTER                    ((uint8)0x03U)
/* @req [SWS_Com_00837] */
#define COM_E_INIT_FAILED                      ((uint8)0x04U)
/* @req [SWS_Com_00864] */
#define COM_E_SKIPPED_TRANSMISSION             ((uint8)0x05U)


#define COM_DET_ERROR_REPORT(ApiId,ErrorId)     (\
                         (void)Det_ReportError(\
                                COM_MODULE_ID,\
                                COM_INSTANCE_ID,\
                                            (ApiId),\
                                            (ErrorId)))
#else
#define COM_DET_REPORT(ApiId,ErrorId)
#endif/* STD_ON == COM_DEV_ERROR_DETECT */

#define COM_CFG_GET_TXSIGNAL_TYPE(SignalId) Com_ConfigPtr->ComTxSignal[SignalId].ComSignalType
#define COM_CFG_GET_RXSIGNAL_TYPE(SignalId) Com_ConfigPtr->ComRxSignal[SignalId].ComSignalType
#define COM_CFG_GET_TXPDU_TYPE(PduId) Com_ConfigPtr->ComTxIPdu[PduId].ComIPduType
#define COM_CFG_GET_RXPDU_TYPE(PduId) Com_ConfigPtr->ComRxIPdu[PduId].ComIPduType

#define COM_CFG_TXSIGNAL(SignalId) Com_ConfigPtr->ComTxSignal[SignalId]
#define COM_CFG_RXSIGNAL(SignalId) Com_ConfigPtr->ComRxSignal[SignalId]
#define COM_CFG_TXPDU(PduId) Com_ConfigPtr->ComTxIPdu[PduId]
#define COM_CFG_RXPDU(PduId) Com_ConfigPtr->ComRxIPdu[PduId]
#define COM_CFG_TXGROUPSIGNAL(GroupSignalId) Com_ConfigPtr->ComTxGroupSignal[GroupSignalId]
#define COM_CFG_RXGROUPSIGNAL(GroupSignalId) Com_ConfigPtr->ComRxGroupSignal[GroupSignalId]
#define COM_CFG_TXSIGNALGROUP(SignalGroupId) Com_ConfigPtr->ComTxSignalGroup[SignalGroupId]
#define COM_CFG_RXSIGNALGROUP(SignalGroupId) Com_ConfigPtr->ComRxSignalGroup[SignalGroupId]
#define COM_CHECKTXPDUISENABLE(PduId) ((boolean)TRUE == Com_TxIPduIsActive[PduId])
#define COM_CHECKRXPDUISENABLE(PduId) ((boolean)TRUE == Com_RxIPduIsActive[PduId])

/*====================================================================================================*
 *                                               ENUMS
 *====================================================================================================*/

/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS
 *====================================================================================================*/

/*====================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS
 *====================================================================================================*/
COM_CONF_PB
extern const Com_ConfigType* Com_ConfigPtr;

#if(COM_NUMBER_OF_RXIPDU > 0)
/*RxPdu*/
extern VAR(boolean, COM_VAR) Com_RxIPduIsActive[COM_NUMBER_OF_RXIPDU];
extern VAR(boolean, COM_VAR) Com_RxIPduIsReceiving[COM_NUMBER_OF_RXIPDU];
extern VAR(boolean, COM_VAR) Com_RxIPduDMEnable[COM_NUMBER_OF_RXIPDU];
extern VAR(boolean, COM_VAR) Com_RxIPduNeedGw[COM_NUMBER_OF_RXIPDU];
extern VAR(boolean, COM_VAR) Com_RxIPduRxIndication[COM_NUMBER_OF_RXIPDU];
extern VAR(uint16, COM_VAR) Com_RxIPduOffset[COM_NUMBER_OF_RXIPDU];
#endif

#if(COM_NUMBER_OF_TXIPDU > 0)
/*TxPdu*/
extern VAR(boolean, COM_VAR) Com_TxIPduIsActive[COM_NUMBER_OF_TXIPDU];
extern VAR(boolean, COM_VAR) Com_TxIPduIsTransmiting[COM_NUMBER_OF_TXIPDU];
extern VAR(boolean, COM_VAR) Com_TxIPduTMS[COM_NUMBER_OF_TXIPDU];
extern VAR(boolean, COM_VAR) Com_TxIPduNeedDelay[COM_NUMBER_OF_TXIPDU];
extern VAR(boolean, COM_VAR) Com_TxIPduTxConfirmation[COM_NUMBER_OF_TXIPDU];
extern VAR(uint16, COM_VAR) Com_TxIPduMDT[COM_NUMBER_OF_TXIPDU];
extern VAR(uint16, COM_VAR) Com_TxIPduDMTime[COM_NUMBER_OF_TXIPDU];
extern VAR(uint16, COM_VAR) Com_TxIPduRepeatNum[COM_NUMBER_OF_TXIPDU];
extern VAR(uint16, COM_VAR) Com_TxIPduRepetitionPeriod[COM_NUMBER_OF_TXIPDU];
extern VAR(uint16, COM_VAR) Com_TxIPduPeriodCnt[COM_NUMBER_OF_TXIPDU];
extern VAR(uint16, COM_VAR) Com_TxIPduOffset[COM_NUMBER_OF_TXIPDU];
extern VAR(Com_TxModeModeType, COM_VAR) Com_TxIPduMode[COM_NUMBER_OF_TXIPDU];
#endif

#if(COM_NUMBER_OF_RXIPDU > 0u)
extern VAR(Com_RxIPduLengthRunTimeType, COM_VAR) Com_RxIPduLength[COM_NUMBER_OF_RXIPDU];
extern VAR(Com_RxIPduDataRunTimeType, COM_VAR) Com_RxIPduData[COM_NUMBER_OF_RXIPDU];
#endif/*COM_NUMBER_OF_RXIPDU > 0*/

#if(COM_NUMBER_OF_TXIPDU > 0u)
extern VAR(Com_TxIPduDataRunTimeType, COM_VAR) Com_TxIPduData[COM_NUMBER_OF_TXIPDU];
#endif/* COM_NUMBER_OF_TXIPDU > 0u */

#if(COM_LENGTH_OF_RXIPDUBUFFER > 0u)
extern uint8 Com_RxIPduRuntimeValue[COM_LENGTH_OF_RXIPDUBUFFER];
extern CONST(uint8,COM_CONST_PBCFG) Com_RxIPduOriginalValue[COM_LENGTH_OF_RXIPDUBUFFER];
#endif/* COM_LENGTH_OF_RXIPDUBUFFER > 0u */

#if(COM_LENGTH_OF_TXIPDUBUFFER > 0u)
extern uint8 Com_TxIPduRuntimeValue[COM_LENGTH_OF_TXIPDUBUFFER];
extern CONST(uint8,COM_CONST_PBCFG) Com_TxIPduOriginalValue[COM_LENGTH_OF_TXIPDUBUFFER];
#endif/* COM_LENGTH_OF_TXIPDUBUFFER > 0u */

#if(COM_NUMBER_OF_BOOLSIGNAL > 0u)
extern boolean Com_BoolSignalRuntimeValue[COM_NUMBER_OF_BOOLSIGNAL];
extern CONST(boolean,COM_CONST_PBCFG) Com_BoolSignalOriginalValue[COM_NUMBER_OF_BOOLSIGNAL];
#endif/* COM_NUMBER_OF_BOOLSIGNAL > 0u */

#if(COM_NUMBER_OF_8BITSIGNAL > 0u)
extern uint8 Com_8BitSignalRuntimeValue[COM_NUMBER_OF_8BITSIGNAL];
extern CONST(uint8,COM_CONST_PBCFG) Com_8BitSignalOriginalValue[COM_NUMBER_OF_8BITSIGNAL];
#endif/* COM_NUMBER_OF_8BITSIGNAL > 0u */

#if(COM_NUMBER_OF_16BITSIGNAL > 0u)
extern uint16 Com_16BitSignalRuntimeValue[COM_NUMBER_OF_16BITSIGNAL];
extern CONST(uint16,COM_CONST_PBCFG) Com_16BitSignalOriginalValue[COM_NUMBER_OF_16BITSIGNAL];
#endif/* COM_NUMBER_OF_16BITSIGNAL > 0u */

#if(COM_NUMBER_OF_32BITSIGNAL > 0u)
extern uint32 Com_32BitSignalRuntimeValue[COM_NUMBER_OF_32BITSIGNAL];
extern CONST(uint32,COM_CONST_PBCFG) Com_32BitSignalOriginalValue[COM_NUMBER_OF_32BITSIGNAL];
#endif/* COM_NUMBER_OF_32BITSIGNAL > 0u */

#if(COM_NUMBER_OF_64BITSIGNAL > 0u)
extern uint64 Com_64BitSignalRuntimeValue[COM_NUMBER_OF_64BITSIGNAL];
extern CONST(uint64,COM_CONST_PBCFG) Com_64BitSignalOriginalValue[COM_NUMBER_OF_64BITSIGNAL];
#endif/* COM_NUMBER_OF_64BITSIGNAL > 0u */

#if(COM_NUMBER_OF_RXGROUPBOOLSIGNAL > 0u)
extern boolean Com_RxGroupBoolSignalShadowBuff[COM_NUMBER_OF_RXGROUPBOOLSIGNAL];
#endif/* COM_NUMBER_OF_RXGROUPBOOLSIGNAL > 0u */

#if(COM_NUMBER_OF_RXGROUP8BITSIGNAL > 0u)
extern uint8 Com_RxGroup8BitSignalShadowBuff[COM_NUMBER_OF_RXGROUP8BITSIGNAL];
#endif/* COM_NUMBER_OF_RXGROUP8BITSIGNAL > 0u */

#if(COM_NUMBER_OF_RXGROUP16BITSIGNAL > 0u)
extern uint16 Com_RxGroup16BitSignalShadowBuff[COM_NUMBER_OF_RXGROUP16BITSIGNAL];
#endif/* COM_NUMBER_OF_RXGROUP16BITSIGNAL > 0u */

#if(COM_NUMBER_OF_RXGROUP32BITSIGNAL > 0u)
extern uint32 Com_RxGroup32BitSignalShadowBuff[COM_NUMBER_OF_RXGROUP32BITSIGNAL];
#endif/* COM_NUMBER_OF_RXGROUP32BITSIGNAL > 0u */

#if(COM_NUMBER_OF_RXGROUP64BITSIGNAL > 0u)
extern uint64  Com_RxGroup64BitSignalShadowBuff[COM_NUMBER_OF_RXGROUP64BITSIGNAL];
#endif/* COM_NUMBER_OF_RXGROUP64BITSIGNAL > 0u */

#if(COM_LENGTH_OF_GWBOOLSIGNALBUFFER > 0u)
extern boolean Com_GWBoolSignalBuff[COM_LENGTH_OF_GWBOOLSIGNALBUFFER];
#endif/* COM_LENGTH_OF_GWBOOLSIGNALBUFFER > 0u */

#if(COM_LENGTH_OF_GW8BITSIGNALBUFFER > 0u)
extern uint8 Com_GW8BitSignalBuff[COM_LENGTH_OF_GW8BITSIGNALBUFFER];
#endif/* COM_LENGTH_OF_GW8BITSIGNALBUFFER > 0u */

#if(COM_LENGTH_OF_GW16BITSIGNALBUFFER > 0u)
extern uint16 Com_GW16BitSignalBuff[COM_LENGTH_OF_GW16BITSIGNALBUFFER];
#endif/* COM_LENGTH_OF_GW16BITSIGNALBUFFER > 0u */

#if(COM_LENGTH_OF_GW32BITSIGNALBUFFER > 0u)
extern uint32 Com_GW32BitSignalBuff[COM_LENGTH_OF_GW32BITSIGNALBUFFER];
#endif/* COM_LENGTH_OF_GW32BITSIGNALBUFFER > 0u */

#if(COM_LENGTH_OF_GW64BITSIGNALBUFFER > 0u)
extern uint64 Com_GW64BitSignalBuff[COM_LENGTH_OF_GW64BITSIGNALBUFFER];
#endif/* COM_LENGTH_OF_GW64BITSIGNALBUFFER > 0u */

#if(COM_TMCTXSIGNAL_NUMBER > 0u)
extern VAR(boolean, COM_VAR) TxSignalTMCRunTime[COM_TMCTXSIGNAL_NUMBER];
extern CONST(boolean, COM_CONST_PBCFG) Com_TxSignalOriginalTMC[COM_TMCTXSIGNAL_NUMBER];
#endif/* COM_TMCTXSIGNAL_NUMBER > 0u */

#if(COM_TMCTXGROUPSIGNAL_NUMBER > 0u)
extern boolean TxGroupSignalTMCBuffer[COM_TMCTXGROUPSIGNAL_NUMBER];
#endif/* COM_TMCTXGROUPSIGNAL_NUMBER > 0u */

#if(COM_NUMBER_OF_NVALID_BOOLSIGNAL > 0u)
extern CONST(boolean, COM_CONST_PBCFG) Com_BoolSignalInvalidValue[COM_NUMBER_OF_NVALID_BOOLSIGNAL];
#endif/* COM_NUMBER_OF_NVALID_BOOLSIGNAL > 0u */

#if(COM_NUMBER_OF_NVALID_8BITSIGNAL > 0u)
extern CONST(uint8, COM_CONST_PBCFG) Com_8BitSignalInvalidValue[COM_NUMBER_OF_NVALID_8BITSIGNAL];
#endif/* COM_NUMBER_OF_NVALID_8BITSIGNAL > 0u */

/*PRQA S 3332 EOF # violate MISAR_2004_Rule_19.11:Ignore this warning*/
#if(COM_NUMBER_OF_NVALID_16BITSIGNAL > 0u)
extern CONST(uint16, COM_CONST_PBCFG) Com_16BitSignalInvalidValue[COM_NUMBER_OF_NVALID_16BITSIGNAL];
#endif/* COM_NUMBER_OF_NVALID_16BITSIGNAL > 0u */

#if(COM_NUMBER_OF_NVALID_32BITSIGNAL > 0u)
extern CONST(uint32, COM_CONST_PBCFG) Com_32BitSignalInvalidValue[COM_NUMBER_OF_NVALID_32BITSIGNAL];
#endif/* COM_NUMBER_OF_NVALID_32BITSIGNAL > 0u */

#if(COM_NUMBER_OF_NVALID_64BITSIGNAL > 0u)
extern CONST(uint64, COM_CONST_PBCFG) Com_64BitSignalInvalidValue[COM_NUMBER_OF_NVALID_64BITSIGNAL];
#endif/* COM_NUMBER_OF_NVALID_64BITSIGNAL > 0u */

#if(COM_NUMBER_OF_IPDUGROUP > 0u)
extern boolean Com_IPduGroupIsActive[COM_NUMBER_OF_IPDUGROUP];
extern boolean Com_IPduGroupDMIsActive[COM_NUMBER_OF_IPDUGROUP];
#endif/* COM_NUMBER_OF_IPDUGROUP > 0u */

#if(COM_NUMBER_OF_TXSIGNALGROUP > 0u)
extern VAR(Com_TxSignalGroupRunTimeStateType, COM_VAR) Com_TxSignalGroupState[COM_NUMBER_OF_TXSIGNALGROUP];
#endif/* COM_NUMBER_OF_TXSIGNALGROUP > 0u */

#if(COM_NUMBER_OF_TIMEOUT_SIGNAL > 0u)
extern uint16 Com_TimeOut[COM_NUMBER_OF_TIMEOUT_SIGNAL];
#endif/* COM_NUMBER_OF_TIMEOUT_SIGNAL > 0u */

#if(COM_NUMBER_OF_UPDATEBIT_GWSOURCESIGNAL > 0u)
extern boolean Com_GWSourceSignalUpdate[COM_NUMBER_OF_UPDATEBIT_GWSOURCESIGNAL];
#endif/* COM_NUMBER_OF_UPDATEBIT_GWSOURCESIGNAL > 0u */

#if(COM_NUMBER_OF_ONEEVERYNFILTERSIGNAL > 0u)
extern uint32 Com_OneEveryNcnt[COM_NUMBER_OF_ONEEVERYNFILTERSIGNAL];
#endif/* COM_NUMBER_OF_ONEEVERYNFILTERSIGNAL > 0u */

#if(COM_NUMBER_OF_MASKNEWDIFFERMASKOLD_SIGNAL > 0u)
extern boolean Com_MaskNewDifferMaskOldTimeOut[COM_NUMBER_OF_MASKNEWDIFFERMASKOLD_SIGNAL];
#endif/* COM_NUMBER_OF_MASKNEWDIFFERMASKOLD_SIGNAL > 0u */

/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES
 *====================================================================================================*/
#define COM_START_SEC_CODE
#include "Com_MemMap.h"

FUNC(void , COM_CODE)
Com_Init(P2CONST(Com_ConfigType, AUTOMATIC, COM_CONST_PBCFG) config);

FUNC(void , COM_CODE)
Com_DeInit(void);

FUNC(void , COM_CODE)
Com_IpduGroupControl(Com_IpduGroupVector const ipduGroupVector,boolean initialize);

FUNC(void , COM_CODE)
Com_ReceptionDMControl(Com_IpduGroupVector const ipduGroupVector);

FUNC(Com_StatusType , COM_CODE)
Com_GetStatus(void);

FUNC(void , COM_CODE)
Com_GetVersionInfo(Std_VersionInfoType* versioninfo);

FUNC(void , COM_CODE)
Com_ClearIpduGroupVector(Com_IpduGroupVector ipduGroupVector);

FUNC(void , COM_CODE)
Com_SetIpduGroup(Com_IpduGroupVector ipduGroupVector,Com_IpduGroupIdType ipduGroupId,boolean bitval);

FUNC(uint8 , COM_CODE)
Com_SendSignal(Com_SignalIdType SignalId,P2CONST(void, AUTOMATIC, COM_APPL_CONST) SignalDataPtr);

FUNC(uint8 , COM_CODE)
Com_SendDynSignal(
	Com_SignalIdType SignalId,
	P2CONST(void, AUTOMATIC, COM_APPL_CONST) SignalDataPtr,uint16 Length
);

FUNC(uint8 , COM_CODE)
Com_ReceiveSignal(Com_SignalIdType SignalId,P2VAR(void, AUTOMATIC, COM_APPL_CONST) SignalDataPtr);

FUNC(uint8 , COM_CODE)
Com_ReceiveDynSignal(
	Com_SignalIdType SignalId,
	P2VAR(void, AUTOMATIC, COM_APPL_CONST) SignalDataPtr,
	P2CONST(uint16, AUTOMATIC, COM_APPL_CONST) Length
);

FUNC(uint8 , COM_CODE)
Com_SendSignalGroup(Com_SignalGroupIdType SignalGroupId);

FUNC(uint8 , COM_CODE)
Com_ReceiveSignalGroup(Com_SignalGroupIdType SignalGroupId);

FUNC(uint8 , COM_CODE)
Com_InvalidateSignal(Com_SignalIdType SignalId);

FUNC(uint8 , COM_CODE)
Com_InvalidateSignalGroup(Com_SignalGroupIdType SignalGroupId);

FUNC(Std_ReturnType , COM_CODE)
Com_TriggerIPDUSend(PduIdType PduId);

FUNC(Std_ReturnType , COM_CODE)
Com_TriggerIPDUSendWithMetaData(PduIdType PduId,P2VAR(uint8, AUTOMATIC, COM_APPL_CONST) MetaData);

FUNC(void , COM_CODE)
Com_SwitchIpduTxMode(PduIdType PduId,boolean Mode);

FUNC(void , COM_CODE)
Com_MainFunctionRx(void);

FUNC(void , COM_CODE)
Com_MainFunctionTx(void);

FUNC(void , COM_CODE)
Com_MainFunctionRouteSignals(void);

#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif

/** @} */


