/**
 * @file        Com_Type.h
 * @brief       Module header file of Com, including version information,
 *              The type and structure of the pdur module are defined
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

/* PRQA S 0292, 0288, 1503, 1505, 0857, 0791, 0828, 0647 EOF #
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

#ifndef  COM_TYPES_H
#define  COM_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
#include "ComStack_Types.h"
#include "Com_Cfg.h"

/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/
#define COM_TYPES_VENDOR_ID               			0U
#define COM_TYPES_AR_RELEASE_MAJOR_VERSION			4U
#define COM_TYPES_AR_RELEASE_MINOR_VERSION			2U
#define COM_TYPES_AR_RELEASE_REVISION_VERSION		2U
#define COM_TYPES_SW_MAJOR_VERSION      			1U
#define COM_TYPES_SW_MINOR_VERSION      			2U
#define COM_TYPES_SW_PATCH_VERSION      			0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
#ifndef DISABLE_INTERMOD_VERSION_CHECK

#if(\
      (COM_TYPES_AR_RELEASE_MAJOR_VERSION != COMTYPE_AR_RELEASE_MAJOR_VERSION) || \
      (COM_TYPES_AR_RELEASE_MINOR_VERSION != COMTYPE_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of Com_Types.h and ComStack_Types.h are different "
#endif

#endif
/*====================================================================================================*
 *                                             CONSTANTS
 *====================================================================================================*/

/*====================================================================================================*
 *                                         DEFINES AND MACROS
 *====================================================================================================*/

/*====================================================================================================*
 *                                               ENUMS
 *====================================================================================================*/
/* @req[SWS_Com_00819] the state of com module ,range com_init/com_uninit */
typedef enum
{
	COM_UNINIT = 0u,
	COM_INIT
}Com_StatusType;

/* Defines the endianness of the signal's network representation */

typedef enum
{
	COM_BIG_ENDIAN = 0u,
	COM_LITTLE_ENDIAN,
	COM_OPAQUE
}Com_SignalEndiannessType;

/**
 * @req [SWS_Com_00675]
 * @req [SWS_Com_00007]
 * @req [SWS_Com_00674]
 * @req [SWS_Com_00829]
 * @req [SWS_Com_00753]
 */
typedef enum
{
	COM_BOOLEAN = 0u,
	COM_UINT8,
	COM_UINT8_N,
	COM_UINT8_DYN,
	COM_SINT8,
	COM_UINT16,
	COM_SINT16,
	COM_UINT32,
	COM_SINT32,
	COM_FLOAT32,
	COM_UINT64,
	COM_SINT64,
	COM_FLOAT64
}Com_SignalType;

/* define the property of the signal which can trigger the transmission of the corresponding I-PDU */
typedef enum
{
	COM_PENDING = 0,
	COM_TRIGGERED,
	COM_TRIGGERED_ON_CHANGE,
	COM_TRIGGERED_WITHOUT_REPETITION,
	COM_TRIGGERED_ON_CHANGE_WITHOUT_REPETITION
}Com_TransferPropertyType;

/**
 * @req [SWS_Com_00602] The AUTOSAR COM module only provides the following ComFilterAlgorithms
 */
typedef enum
{
	COM_ALWAYS = 0u,
	COM_NEVER,
	COM_ONE_EVERY_N,
	COM_NEW_IS_OUTSIDE,
	COM_NEW_IS_WITHIN,
	COM_MASKED_NEW_DIFFERS_X,
	COM_MASKED_NEW_EQUALS_X,
	COM_MASKED_NEW_DIFFERS_MASKED_OLD
}Com_FilterAlgorithmType;

/*define the mode of the trans PDU*/
typedef enum
{
	COM_DIRECT = 0u,
	COM_MIXED,
	COM_PERIODIC,
	COM_NONE
}Com_TxModeModeType;

typedef enum
{
	COM_CONFIRMATION = 0u,
	COM_TRANSMIT,
	COM_TRIGGERTRANSMIT
}Com_TxIPduClearUpdateBitType;

/*define the IpduSignalProcessing*/
typedef enum
{
	COM_DEFERRED = 0u,
	COM_IMMEDIATE
}Com_IPduSignalProcessingType;

/* define the typedef of I-PDU */
typedef enum
{
	COM_NORMAL = 0u,
	COM_TP
}Com_IPduType;

typedef enum
{
	COM_INVALID_ACTION_NOTIFY = 0u,
	COM_INVALID_ACTION_REPLACE
}Com_DataInvalidActionType;

typedef enum
{
	COM_TIMEOUT_ACTION_NONE = 0u,
	COM_TIMEOUT_ACTION_REPLACE
}Com_RxDataTimeoutActionType;

typedef enum
{
	COM_SIGNAL = 0u,
	COM_SIGNAL_GROUP,
	COM_GROUP_SIGNAL,
    COM_DESCRIPTION
}Com_GWSignalType;

/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS
 *====================================================================================================*/
/* @req [SWS_Com_00820] AUTOSAR COM signal object identifier, Range 0-SingalIdMax */
typedef uint16 Com_SignalIdType;

/* @req [SWS_Com_00821] AUTOSAR COM signal group object identifier, Range 0-SingalGroupIdMax */
typedef uint16 Com_SignalGroupIdType;

/* @req [SWS_Com_00822] AUTOSAR COM IPdu group object identifier, Range 0-PduGroupIdMax */
typedef uint16 Com_IpduGroupIdType;

/* @req [SWS_Com_00823] */
#if(COM_NUMBER_OF_IPDUGROUP > 0u)
typedef uint8 Com_IpduGroupVector[(((uint16)COM_NUMBER_OF_IPDUGROUP - 1u)/8u)+1u];
#else
typedef uint8 Com_IpduGroupVector[1];
#endif

/* @req [SWS_Com_00824] */
typedef uint8 Com_ServiceIdType;

typedef struct
{
	const Com_GWSignalType ComGwDestSignalType;
	const Com_SignalIdType ComGwDestSignalId;
}Com_GwDestType;

typedef struct
{
	const Com_GWSignalType ComGwSourceSignalType;
	const Com_SignalIdType ComGwSourceSignalId;
	const Com_SignalIdType ComGwDestNumber;
	P2CONST(Com_GwDestType, AUTOMATIC, COM_APPL_CONST) ComGwDest;
}Com_GwMappingType;

typedef struct
{
	const uint32 ComBitPosition;
	const uint8 ComBitSize;
	const Com_SignalEndiannessType ComSignalEndianness;
	const uint16 ComSignalLength;
	const Com_SignalType ComSignalType;
	const uint32 ComUpdateBitPosition;
	const uint16 ComGwIpduRef;
	const uint16 GWSignalBufferId;
	const uint16 GWUpadateStateId;
}Com_GwSourceSignalType;

typedef struct
{
	/* choose the filteralgorithm of the signal */
	const Com_FilterAlgorithmType ComFilterAlgorithm;
	const uint64 ComFilterMask;
	const uint64 ComFilterX;
	const uint64 ComFilterMax;
	const uint64 ComFilterMin;
	const uint32 ComFilterOffset;
	const uint32 ComFilterPeriod;
	const Com_SignalIdType ComOneEveryNId;
	const Com_SignalIdType ComMaskNewDifferMaskOldId;
	const Com_SignalIdType ComTMCBufferId;
}Com_FilterType;

typedef struct
{
	const uint32 ComBitPosition;
	const uint8 ComBitSize;
	const Com_SignalType ComSignalType;
	const uint16 ComSignalLength;
	const Com_SignalEndiannessType ComSignalEndianness;
	const Com_TransferPropertyType ComTransferProperty;
	const uint32 ComUpdateBitPosition;
	const uint16 ComGwIpduRef;
	P2CONST(Com_FilterType, AUTOMATIC, CANIF_APPL_CONST) ComFilter;
	const uint16 ComSignalInitValueId;
	const uint16 ComSignalDataInitValueLength;
}Com_GwDestSignalType;

typedef struct
{
	P2FUNC(void,COM_APPL_CODE,ComIPduCounterErrorNotification)
	(PduIdType ComPduId,uint8 ExpectedCounter,uint8 ReceivedCounter);
	uint8 ComIpduCounterSize;
	uint32 ComIpduCounterStartPosition;
	uint8 ComIpduCounterThreshold;
	uint8 ComIpduMaxCounter;
}Com_IPduCounterType;

typedef struct
{
	const Com_TxModeModeType ComTxModeMode;
	const uint8 ComTxModeNumberOfRepetitions;
	const uint16 ComTxModeRepetitionPeriod;
	const uint16 ComTxModeTimeOffset;
	const uint16 ComTxModeTimePeriod;
}Com_TxModeType;

typedef struct
{
	P2FUNC(boolean,COM_APPL_CODE,ComIPduCallout)
	(PduIdType PduId,P2CONST(PduInfoType, AUTOMATIC, COM_APPL_CONST) PduInfoPtr);
	#if(STD_ON == COM_CANCELLATION_SUPPORT)
	const boolean ComIPduCancellationSupport;
	#endif
	const uint16 ComIPduHandleId;
	const Com_IPduSignalProcessingType ComIPduSignalProcessing;
	const Com_IPduType ComIPduType;
	const Com_IpduGroupIdType ComIPduGroupsRefNumber;
	P2CONST(Com_IpduGroupIdType, AUTOMATIC, COM_APPL_CONST) ComIPduGroupsRef;
	const Com_SignalGroupIdType ComIPduSignalGroupsRefNumber;
	P2CONST(Com_SignalGroupIdType, AUTOMATIC, COM_APPL_CONST) ComIPduSignalGroupsRef;
	const Com_SignalIdType ComIPduSignalsRefNumber;
	P2CONST(Com_SignalIdType, AUTOMATIC, COM_APPL_CONST) ComIPduSignalsRef;
	const uint8 MetaDataLength;
	const uint16 IPduNoDynSignalLength;
	const uint16 IPduMaxDynSignalLength;
	const uint16 ComRxIPduBufIndex;
	/** < @brief If the parameter is set, the parameter is tested */
	P2CONST(Com_IPduCounterType, AUTOMATIC, COM_APPL_CONST) ComIPduCounter;
	const boolean IPduGW;
	const PduLengthType ComIPduInitLength;
}Com_RxIpduType;

typedef struct
{
	P2FUNC(boolean,COM_APPL_CODE,ComIPduCallout)
	(PduIdType PduId,P2VAR(PduInfoType, AUTOMATIC, COM_APPL_CONST) PduInfoPtr);
	#if(STD_ON == COM_CANCELLATION_SUPPORT)
	const boolean ComIPduCancellationSupport;
	#endif
	const uint16 ComIPduHandleId;
	const Com_IPduSignalProcessingType ComIPduSignalProcessing;
	P2FUNC(boolean,COM_APPL_CODE,ComIPduTriggerTransmitCallout)
	(PduIdType PduId,P2VAR(PduInfoType, AUTOMATIC, COM_APPL_CONST) PduInfoPtr);
	const Com_IPduType ComIPduType;
	const Com_IpduGroupIdType ComIPduGroupsRefNumber;
	P2CONST(Com_IpduGroupIdType, AUTOMATIC, COM_APPL_CONST) ComIPduGroupsRef;
	const Com_SignalGroupIdType ComIPduSignalGroupsRefNumber;
	P2CONST(Com_SignalGroupIdType, AUTOMATIC, COM_APPL_CONST) ComIPduSignalGroupsRef;
	const Com_SignalIdType ComIPduSignalsRefNumber;
	P2CONST(Com_SignalIdType, AUTOMATIC, COM_APPL_CONST) ComIPduSignalsRef;
	const uint16 PduRLayerId;
	const uint8 MetaDataLength;
	const uint16 IPduNoDynSignalLength;
	const uint16 IPduMaxDynSignalLength;
	const uint16 ComTxIPduBufIndex;
	P2CONST(Com_IPduCounterType, AUTOMATIC, COM_APPL_CONST) ComIPduCounter;
	const uint16 ComMinimumDelayTime;
	const Com_TxIPduClearUpdateBitType  ComTxIPduClearUpdateBit;
	P2CONST(Com_TxModeType, AUTOMATIC, COM_APPL_CONST) ComTxModeTrue;
	P2CONST(Com_TxModeType, AUTOMATIC, com_APPL_CONST) ComTxModeFalse;
	const uint16 ComTxIpduDM;
	const PduLengthType ComIPduInitLength;
}Com_TxIpduType;

typedef struct
{
	const uint32 ComBitPosition;
	const uint8 ComBitSize;
	const uint16 ComFirstTimeout;
	const uint16 ComTimeout;
	const uint16 ComTimeCntIndex;
	const PduIdType ComIpduRefIndex;
	const Com_SignalIdType ComSignalId;
	const Com_DataInvalidActionType ComDataInvalidAction;
	P2FUNC(void,COM_APPL_CODE,ComInvalidNotification)(void);
	P2FUNC(void,COM_APPL_CODE,ComNotification)(void);
	const Com_RxDataTimeoutActionType ComRxDataTimeoutAction;
	const uint16 ComSignalDataInvalidValueId;
	const Com_SignalEndiannessType ComSignalEndianness;
	const uint16 ComSignalInitValueId;
	const uint16 ComSignalLength;
	const Com_SignalType ComSignalType;
	P2FUNC(void,COM_APPL_CODE,ComTimeoutNotification)(void);
	const uint32 ComUpdateBitPosition;
	P2CONST(Com_FilterType, AUTOMATIC, COM_APPL_CONST) ComFilter;
	const uint16 ComSignalDataInvalidValueLength;
	const uint16 ComSignalDataInitValueLength;
	const uint16 GWUpdataStateId;
	const uint16 GWSignalBufferId;
}Com_RxSignalType;

typedef struct
{
	const uint32 ComBitPosition;
	const uint8 ComBitSize;
	P2FUNC(void,COM_APPL_CODE,ComErrorNotification)(void);
	const Com_SignalIdType ComSignalId;
	const boolean ComInitialValueOnly;
	P2FUNC(void,COM_APPL_CODE,ComNotification)(void);
	const uint16 ComSignalDataInvalidValueId;
	const Com_SignalEndiannessType ComSignalEndianness;
	const uint16 ComSignalInitValueId;
	const uint16 ComSignalLength;
	const Com_SignalType ComSignalType;
	const uint16 ComTimeout;
	const PduIdType ComIpduRefIndex;
	P2FUNC(void,COM_APPL_CODE,ComTimeoutNotification)(void);
	const Com_TransferPropertyType ComTransferProperty;
	const uint32 ComUpdateBitPosition;
	P2CONST(Com_FilterType, AUTOMATIC, COM_APPL_CONST) ComFilter;
    const uint16 ComSignalDataInvalidValueLength;
    const uint16 ComSignalDataInitValueLength;
}Com_TxSignalType;

typedef struct
{
	const Com_DataInvalidActionType ComDataInvalidAction;
	const uint16 ComFirstTimeout;
	const uint16 ComTimeout;
	const Com_SignalGroupIdType ComSignalGroupId;
	P2FUNC(void,COM_APPL_CODE,ComInvalidNotification)(void);
	P2FUNC(void,COM_APPL_CODE,ComNotification)(void);
	const Com_RxDataTimeoutActionType ComRxDataTimeoutAction;
	P2FUNC(void,COM_APPL_CODE,ComTimeoutNotification)(void);
	const uint32 ComUpdateBitPosition;
	const Com_SignalIdType ComGroupSignalNumber;
	P2CONST(Com_SignalIdType, AUTOMATIC, COM_APPL_CONST) ComRxGroupSignalId;
	const PduIdType ComIpduRefIndex;
	const uint16 ComTimeoutCntIndex;
	const uint16 GWUpdateStateId;
}Com_RxSignalGroupType;

typedef struct
{
	P2FUNC(void,COM_APPL_CODE,ComErrorNotification)(void);
	const Com_SignalGroupIdType ComSignalGroupId;
	const boolean ComInitialValueOnly;
	P2FUNC(void,COM_APPL_CODE,ComNotification)(void);
	const uint16 ComTimeout;
	P2FUNC(void,COM_APPL_CODE,ComTimeoutNotification)(void);
	const Com_TransferPropertyType ComTransferProperty;
	const uint32 ComUpdateBitPosition;
	const Com_SignalIdType ComGroupSignalNumber;
	P2CONST(Com_SignalIdType, AUTOMATIC, COM_APPL_CONST) ComTxGroupSignalId;
	const PduIdType ComIpduRefIndex;
}Com_TxSignalGroupType;

typedef struct
{
	const uint32 ComBitPosition;
	const uint8 ComBitSize;
	const Com_SignalIdType ComGroupSignalId;
	const uint16 ComSignalDataInvalidValueId;
    const Com_SignalEndiannessType ComSignalEndianness;
    const uint16 ComSignalInitValueId;
    const uint16 ComSignalLength;
    const Com_SignalType ComSignalType;
    P2CONST(Com_FilterType, AUTOMATIC, COM_APPL_CONST) ComFilter;
    const Com_SignalGroupIdType ComSignalGroupRef;
    const uint16 ComSignalDataInvalidValueLength;
    const uint16 ComSignalDataInitValueLength;
    const uint16 GWSignalBufferId;
}Com_RxGroupSignalType;

typedef struct
{
	const uint32 ComBitPosition;
	const uint8 ComBitSize;
	const Com_SignalIdType ComGroupSignalId;
	const uint16 ComSignalDataInvalidValueId;
    const Com_SignalEndiannessType ComSignalEndianness;
    const uint16 ComSignalInitValueId;
    const uint16 ComSignalLength;
    const Com_SignalType ComSignalType;
    P2CONST(Com_FilterType, AUTOMATIC, COM_APPL_CONST) ComFilter;
    const Com_TransferPropertyType ComTransferProperty;
    const Com_SignalGroupIdType ComSignalGroupRef;
    const uint16 ComSignalDataInvalidValueLength;
    const uint16 ComSignalDataInitValueLength;
}Com_TxGroupSignalType;

typedef struct
{
	uint16 RxIpduLength;
	uint16 GWDynSignalLength;
}Com_RxIPduLengthRunTimeType;

typedef struct
{
	boolean RxAnyCounterPdu;
	uint8 RxIpduCounter;
}Com_RxIPduDataRunTimeType;

typedef struct
{
	uint16 TxIpduLength;
	uint8 TxIpduCounter;
}Com_TxIPduDataRunTimeType;

typedef struct
{
	boolean TransmitRequest;
	boolean NoRepetition;
	uint16 DynamicSignalLength;
}Com_TxSignalGroupRunTimeStateType;


typedef struct
{
	P2CONST(Com_RxIpduType, AUTOMATIC, COM_APPL_CONST) ComRxIPdu;
	P2CONST(Com_TxIpduType, AUTOMATIC, COM_APPL_CONST) ComTxIPdu;
	P2CONST(Com_RxSignalType, AUTOMATIC, COM_APPL_CONST) ComRxSignal;
	P2CONST(Com_TxSignalType, AUTOMATIC, COM_APPL_CONST) ComTxSignal;
	P2CONST(Com_RxSignalGroupType, AUTOMATIC, COM_APPL_CONST) ComRxSignalGroup;
	P2CONST(Com_TxSignalGroupType, AUTOMATIC, COM_APPL_CONST) ComTxSignalGroup;
	P2CONST(Com_RxGroupSignalType, AUTOMATIC, COM_APPL_CONST) ComRxGroupSignal;
	P2CONST(Com_TxGroupSignalType, AUTOMATIC, COM_APPL_CONST) ComTxGroupSignal;
	P2CONST(Com_GwMappingType, AUTOMATIC, COM_APPL_CONST) ComGwMapping;
}Com_ConfigType;

/*====================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS
 *====================================================================================================*/

/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES
 *====================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif

/** @} */
