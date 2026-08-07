/**
 * @file       	Com_RxInternal.c
 * @brief       Implementation for Com
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

/* PRQA S 0292, 0288, 1503, 1505, 0857, 0791, 0828, 0647, 0580, 0491 EOF #
 *
 * 1.0292 -- Violates MISRA 2004 Required Rule 3.1, Source file has comments containing one of the
 * characters '$', '@' or '`'.
 *
 * 2.0288 -- Violates MISRA 2004 Required Rule 3.1, Source file has comments containing characters
 * which are not members of the basic source character set.
 *
 * 3.1503 -- Violates MISRA 2004 Required Rule 14.1, The function is defined but is not used within
 * this project.
 *
 * 4.1503 -- Violates MISRA 2004 Required Rule 8.10, The function is only referenced in the translation
 * unit where it is defined.
 *
 * 5.0857 -- Violates MISRA 2004 Required Rule 1.1, Number of macro definitions exceeds 1024 - program
 * does not conform strictly to ISO:C90.
 *
 * 6.0791 -- Violates MISRA 2004 Required Rule 5.1, Macro identifier does not differ from other macro
 * identifier(s) within the specified number of significant characters.
 *
 * 7.0828 -- Violates MISRA 2004 Required Rule 1.1, More than 8 levels of nested conditional inclusion
 * - program does not conform strictly to ISO:C90.
 *
 * 8.0647 -- Violates MISRA 2004 Required Rule 1.1, Number of enumeration constants exceeds 127 -
 * program does not conform strictly to ISO:C90.
 *
 * @page misra_violations MISRA-C:2004 violations
 */

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
#include "Com_Internal.h"

/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION
 *====================================================================================================*/
#define COM_RXINTERNAL_VENDOR_ID_C 						0U
#define COM_RXINTERNAL_AR_RELEASE_MAJOR_VERSION_C  		4U
#define COM_RXINTERNAL_AR_RELEASE_MINOR_VERSION_C  		2U
#define COM_RXINTERNAL_AR_RELEASE_REVISION_VERSION_C	2U
#define COM_RXINTERNAL_SW_MAJOR_VERSION_C				1U
#define COM_RXINTERNAL_SW_MINOR_VERSION_C				2U
#define COM_RXINTERNAL_SW_PATCH_VERSION_C				0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Com_Internal.h header file are of the same vendor */
#if(COM_RXINTERNAL_VENDOR_ID_C != COM_INTERNAL_VENDOR_ID )
#error "Com_RxInternal.c and Com_Internal.h have different vendor id"
#endif

#if(\
      (COM_RXINTERNAL_AR_RELEASE_MAJOR_VERSION_C != COM_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
      (COM_RXINTERNAL_AR_RELEASE_MINOR_VERSION_C != COM_INTERNAL_AR_RELEASE_MINOR_VERSION) || \
      (COM_RXINTERNAL_AR_RELEASE_REVISION_VERSION_C != COM_INTERNAL_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of Com_RxInternal.c and Com_Internal.h are different "
#endif

/* Check if current file and Com_Internal.h header file are of the same software version */
#if(\
      (COM_RXINTERNAL_SW_MAJOR_VERSION_C != COM_INTERNAL_SW_MAJOR_VERSION) || \
      (COM_RXINTERNAL_SW_MINOR_VERSION_C != COM_INTERNAL_SW_MINOR_VERSION) ||\
	  (COM_RXINTERNAL_SW_PATCH_VERSION_C != COM_INTERNAL_SW_PATCH_VERSION)\
      )
#error "Software Version Number of Com_RxInternal.c and Com_Internal.h are different "
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
#ifndef AH_UNITTEST_ENABLED
#define STATIC static
#define STATIC_INLINE static inline
#else
#define STATIC
#define STATIC_INLINE
#endif /* #if defined(AH_UNITTEST_ENABLED) */

/*====================================================================================================*
 *                                           LOCAL CONSTANTS
 *====================================================================================================*/

/*====================================================================================================*
 *                                           LOCAL VARIABLES
 *====================================================================================================*/

/*====================================================================================================*
 *                                      LOCAL FUNCTION PROTOTYPES
 *====================================================================================================*/
#define COM_START_SEC_CODE
#include "Com_MemMap.h"

#if(COM_NUMBER_OF_RXIPDU > 0)
STATIC FUNC(void,COM_CODE)
Com_SignalRxIndication(
	VAR(Com_SignalIdType, COM_VAR) SignalId,
	VAR(uint16, COM_VAR) DynSignalLength,
	VAR(uint16, COM_VAR) bufferid
);
#endif

#if(COM_NUMBER_OF_RXIPDU > 0)
STATIC FUNC(void,COM_CODE)
Com_Handle8_NSignal(
	VAR(Com_SignalIdType, COM_VAR) SignalId,
	VAR(uint16, COM_VAR) SignalLength,
	VAR(uint16, COM_VAR) BufferId
);
#endif

#if(COM_NUMBER_OF_RXIPDU > 0)
STATIC FUNC(void,COM_CODE)
Com_Handle8DYNSignal(
	VAR(Com_SignalIdType, COM_VAR) SignalId,
	VAR(uint16, COM_VAR) SignalLength,
	VAR(uint16, COM_VAR) BufferId
);
#endif

#if(COM_NUMBER_OF_RXIPDU > 0)
STATIC FUNC(void,COM_CODE)
Com_HandleRxSignal(
	VAR(Com_SignalIdType, COM_VAR) SignalId
);
#endif

#if(COM_NUMBER_OF_RXIPDU > 0)
STATIC FUNC(boolean,COM_CODE)
Com_HandleSignalInvalidate(
	VAR(Com_SignalType, COM_VAR) SignalType,
	VAR(uint16, COM_VAR) InvalidValueId,
	VAR(uint64, COM_VAR) Value
);
#endif

#if(COM_NUMBER_OF_RXIPDU > 0)
STATIC FUNC(uint64,COM_CODE)
Com_UnPackRxSignal(
	VAR(Com_SignalIdType, COM_VAR) SignalId
);
#endif

#if(COM_NUMBER_OF_RXIPDU > 0)
STATIC FUNC(void,COM_CODE)
Com_UpdateGWSignalBuffer(
	VAR(uint64, COM_VAR) Value,
	VAR(uint16, COM_VAR) GWSignalBufferId,
	VAR(Com_SignalType, COM_VAR) SignalType
);
#endif

STATIC FUNC(uint64,COM_CODE)
Com_ReplaceRxSignal(
	VAR(Com_SignalType, COM_VAR) SignalType,
	VAR(uint16, COM_VAR) InitValueId
);

STATIC FUNC(boolean,COM_CODE)
Com_FilterRxSignal(
	VAR(uint64, COM_VAR) Value,
	P2CONST(Com_FilterType, AUTOMATIC, COM_APPL_CONST) ComFilter,
	VAR(Com_SignalType, COM_VAR) SignalType,
	VAR(uint16, COM_VAR) SignalBufferId
);

STATIC FUNC(void,COM_CODE)
Com_UpdateRxSignalBuff(
	VAR(uint64, COM_VAR) Value,
	VAR(Com_SignalIdType, COM_VAR) SignalId
);

#if(COM_NUMBER_OF_RXIPDU > 0)
STATIC FUNC(void,COM_CODE)
Com_SignalGroupRxIndication(
	VAR(Com_SignalGroupIdType, COM_VAR) SignalGroupId,
	VAR(uint16, COM_VAR) DynSignalLength,
	VAR(uint16, COM_VAR) bufferid
);
#endif

#if(COM_NUMBER_OF_RXIPDU > 0)
STATIC FUNC(boolean,COM_CODE)
Com_HandleSignalGroupRxIndication(
	VAR(Com_SignalType, COM_VAR) SignalType,
	VAR(Com_SignalIdType, COM_VAR) GroupSignalId,
	VAR(uint16, COM_VAR) DynSignalLength,
	VAR(uint16, COM_VAR) invalidValueId,
	VAR(uint16, COM_VAR) gwSignalBufferId,
	VAR(uint16, COM_VAR) bufferid
);
#endif

#if(COM_NUMBER_OF_RXIPDU > 0)
STATIC FUNC(uint64,COM_CODE)
Com_UnPackRxGroupSignal(
	VAR(Com_SignalIdType, COM_VAR) SignalId,
	VAR(uint16, COM_VAR) PduBufferIdx
);
#endif

#if(COM_NUMBER_OF_RXIPDU > 0)
STATIC FUNC(boolean,COM_CODE)
Com_FilterRxSignalGroup(
	VAR(Com_SignalGroupIdType, COM_VAR) SignalGroupId,
	VAR(boolean, COM_VAR) SignalGroupInvalid,
	VAR(uint16, COM_VAR) BufferId
);
#endif

#if(COM_NUMBER_OF_RXIPDU > 0)
STATIC FUNC(void,COM_CODE)
Com_UpdateRxGroupSignalBuff(
	VAR(boolean, COM_VAR) SignalGroupInvalid,
	VAR(Com_SignalIdType, COM_VAR) GroupSignalId,
	VAR(uint16, COM_VAR) bufferid,
	VAR(uint16, COM_VAR) DynSignalLength
);
#endif

#if(COM_NUMBER_OF_RXIPDU > 0)
#if(COM_NUMBER_OF_IPDUGROUP > 0u)
STATIC FUNC(void,COM_CODE)
Com_InitRxPduAndSignalBuffer(VAR(PduIdType, COM_VAR) PduId);
#endif
#endif/* COM_IPDUGROUP_NUMBER > 0u */

STATIC FUNC(void,COM_CODE)
Com_InvalidSignalReplaceAndNotification(
	VAR(Com_SignalIdType, COM_VAR) RxSignalId
);

#if(COM_NUMBER_OF_RXIPDU > 0)
STATIC FUNC(void,COM_CODE)
Com_HandleSignalInPdu(
	VAR(PduIdType, COM_VAR) PduId,
	VAR(uint16, COM_VAR) dynSignalLength,
	VAR(uint16, COM_VAR) pduBufferIdx
);
#endif

#if(COM_NUMBER_OF_RXIPDU > 0)
STATIC FUNC(void,COM_CODE)
Com_HandleSignalGroupInPdu(
	VAR(PduIdType, COM_VAR) PduId,
	VAR(uint16, COM_VAR) dynSignalLength,
	VAR(uint16, COM_VAR) pduBufferIdx
);
#endif

#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

/*====================================================================================================*
 *                                           LOCAL FUNCTIONS
 *====================================================================================================*/
#define COM_START_SEC_CODE
#include "Com_MemMap.h"

/**
 * @brief			init the rx ipdu buffer,all signal buffer(included in the ipdu,except source signal)
 * @param[in]		PduId: pdu identify
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
#if(COM_NUMBER_OF_RXIPDU > 0)
#if(COM_NUMBER_OF_IPDUGROUP > 0u)
STATIC FUNC(void,COM_CODE)
Com_InitRxPduAndSignalBuffer(
	VAR(PduIdType, COM_VAR) PduId
)
{
	uint16 cnt;
	uint16 index;
	uint16 refBufIdx;
	uint16 signalLength;
	uint16 pduLength;
	uint16 initValueId;
	uint16 groupSignalId;
	uint16 groupSignalNumber;
	Com_SignalType signalType;
	Com_SignalIdType signalNumber;
	Com_SignalIdType signalId;
	Com_SignalGroupIdType signalGroupNumber;
	Com_SignalGroupIdType signalGroupId;
	refBufIdx = COM_CFG_RXPDU(PduId).ComRxIPduBufIndex;
	pduLength = Com_RxIPduLength[PduId].RxIpduLength;
	signalNumber =  COM_CFG_RXPDU(PduId).ComIPduSignalsRefNumber;
	signalGroupNumber = COM_CFG_RXPDU(PduId).ComIPduSignalGroupsRefNumber;
	for(cnt = 0u; cnt < pduLength;cnt++)
	{
		Com_RxIPduRuntimeValue[refBufIdx + cnt] = Com_RxIPduOriginalValue[refBufIdx + cnt];
	}
	Com_RxIPduNeedGw[PduId] = (boolean)FALSE;
	Com_RxIPduIsReceiving[PduId] = (boolean)FALSE;
	Com_RxIPduRxIndication[PduId] = (boolean)FALSE;
	Com_RxIPduLength[PduId].RxIpduLength = (uint16)COM_CFG_RXPDU(PduId).ComIPduInitLength;
	for(cnt = 0u;cnt < signalNumber;cnt++)
	{
		signalId = COM_CFG_RXPDU(PduId).ComIPduSignalsRef[cnt];
		initValueId = COM_CFG_RXSIGNAL(signalId).ComSignalInitValueId;
		signalType = COM_CFG_RXSIGNAL(signalId).ComSignalType;
		if(COM_UINT8_N == signalType)
		{
			signalLength = COM_CFG_RXSIGNAL(signalId).ComSignalLength;
		}
		else if(COM_UINT8_DYN == signalType)
		{
			signalLength = COM_CFG_RXSIGNAL(signalId).ComSignalDataInitValueLength;
		}
		else
		{
			signalLength = 0u;
		}
		Com_InitSignalBuffer(signalType,initValueId,signalLength);
	}
	for(cnt = 0u;cnt < signalGroupNumber;cnt++)
	{
		signalGroupId = COM_CFG_RXPDU(PduId).ComIPduSignalGroupsRef[cnt];
		groupSignalNumber = COM_CFG_RXSIGNALGROUP(signalGroupId).ComGroupSignalNumber;
		for(index =(uint16) 0;index < groupSignalNumber;index++)
		{
			groupSignalId = COM_CFG_RXSIGNALGROUP(signalGroupId).ComRxGroupSignalId[index];
			initValueId = COM_CFG_RXGROUPSIGNAL(groupSignalId).ComSignalInitValueId;
			signalType = COM_CFG_RXGROUPSIGNAL(groupSignalId).ComSignalType;
			if(COM_UINT8_N == signalType)
			{
				signalLength = COM_CFG_RXGROUPSIGNAL(groupSignalId).ComSignalLength;
			}
			else if(COM_UINT8_DYN == signalType)
			{
				signalLength = COM_CFG_RXGROUPSIGNAL(groupSignalId).ComSignalDataInitValueLength;
			}
			else
			{
				signalLength = 0u;
			}
			Com_InitSignalBuffer(signalType,initValueId,signalLength);
		}
	}
	return;
}
#endif
#endif/* COM_IPDUGROUP_NUMBER > 0 */

#if(COM_NUMBER_OF_RXIPDU > 0)
/**
 * @brief			Processing the signal in the pdu
 * @param[in]		PduId: pdu identify
 * @param[in]		dynSignalLength: length of signal
 * @param[in]		pduBufferIdx: The current signal corresponds to the position of the pdu in
 * 					the entire pdu array
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
STATIC FUNC(void,COM_CODE)
Com_HandleSignalInPdu(
	VAR(PduIdType, COM_VAR) PduId,
	VAR(uint16, COM_VAR) dynSignalLength,
	VAR(uint16, COM_VAR) pduBufferIdx
)
{
	uint16 cnt;
	Com_SignalIdType signalNumber;
	Com_SignalIdType signalId;
	uint32 updateBitPosition;
	boolean signalIsUpdate = (boolean)FALSE;
	uint8 updateBitOffset;
#if(COM_NUMBER_OF_UPDATEBIT_GWSOURCESIGNAL > 0u)
uint16 gwUpdataStateId;
#endif/* COM_NUMBER_OF_UPDATEBIT_GWSOURCESIGNAL > 0 */

	signalNumber = COM_CFG_RXPDU(PduId).ComIPduSignalsRefNumber;
	for(cnt = 0u;cnt < signalNumber;cnt++)
	{
		signalId = COM_CFG_RXPDU(PduId).ComIPduSignalsRef[cnt];
		updateBitPosition = COM_CFG_RXSIGNAL(signalId).ComUpdateBitPosition;
		/**
		 * @req [SWS_Com_00324] the rx signal have update bit
		 */
		if(updateBitPosition == 0xffffffffu)
		{
			signalIsUpdate = (boolean)TRUE;
		}
		else
		{
			updateBitOffset = (uint8)(0x01u << ((updateBitPosition) & 0x07u));
			/* update bit is 1 */
			if(updateBitOffset == ((Com_RxIPduRuntimeValue\
					[pduBufferIdx + (uint16)(updateBitPosition/(uint32)8)]) & updateBitOffset))
			{
				#if(COM_NUMBER_OF_UPDATEBIT_GWSOURCESIGNAL > 0u)
				gwUpdataStateId = COM_CFG_RXSIGNAL(signalId).GWUpdataStateId;
				if(0xffff != gwUpdataStateId)
				{
					Com_GWSourceSignalUpdate[gwUpdataStateId] = TRUE;
				}
				#endif
				signalIsUpdate =(boolean) TRUE;
			}
		}
		if((boolean)TRUE == signalIsUpdate)
		{
			Com_SignalRxIndication(signalId,dynSignalLength,pduBufferIdx);
			signalIsUpdate = (boolean)FALSE;
		}
	}
}
#endif

#if(COM_NUMBER_OF_RXIPDU > 0)
/**
 * @brief			Processing the signal group in the pdu
 * @param[in]		PduId: pdu identify
 * @param[in]		dynSignalLength: length of signal
 * @param[in]		pduBufferIdx: The current signal corresponds to the position of the pdu in
 * 					the entire pdu array
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
STATIC FUNC(void,COM_CODE)
Com_HandleSignalGroupInPdu(
	VAR(PduIdType, COM_VAR) PduId,
	VAR(uint16, COM_VAR) dynSignalLength,
	VAR(uint16, COM_VAR) pduBufferIdx
)
{
	uint16 cnt;
	uint8 updateBitOffset;
	uint32 updateBitPosition;
	Com_SignalGroupIdType signalGroupNumber;
	Com_SignalGroupIdType signalGroupId;
	boolean signalGroupIsUpdate = (boolean)FALSE;

#if(COM_NUMBER_OF_UPDATEBIT_GWSOURCESIGNAL > 0u)
	uint16 gwUpdataStateId;
#endif/* COM_NUMBER_OF_UPDATEBIT_GWSOURCESIGNAL > 0u */

	signalGroupNumber = COM_CFG_RXPDU(PduId).ComIPduSignalGroupsRefNumber;
	for(cnt = 0u;cnt < signalGroupNumber; cnt ++)
	{
		signalGroupId = COM_CFG_RXPDU(PduId).ComIPduSignalGroupsRef[cnt];
		updateBitPosition = Com_ConfigPtr->ComRxSignalGroup[signalGroupId].ComUpdateBitPosition;
		if(updateBitPosition == 0xffffffffu)
		{
			signalGroupIsUpdate = (boolean)TRUE;
		}
		else
		{
			updateBitOffset = (uint8)(0x01u << ((updateBitPosition) & 0x07u));
			if(updateBitOffset == ((Com_RxIPduRuntimeValue\
					[pduBufferIdx + (uint16)(updateBitPosition >> 3u)]) & updateBitOffset))
			{
				#if(COM_NUMBER_OF_UPDATEBIT_GWSOURCESIGNAL > 0u)
				gwUpdataStateId = COM_CFG_RXSIGNALGROUP(signalGroupId).GWUpdateStateId;
				if(0xffff != gwUpdataStateId)
				{
					Com_GWSourceSignalUpdate[gwUpdataStateId] = TRUE;
				}
				#endif
				signalGroupIsUpdate = (boolean)TRUE;
			}
		}
		if((boolean)TRUE == signalGroupIsUpdate)
		{
			Com_SignalGroupRxIndication(signalGroupId,dynSignalLength,pduBufferIdx);
			signalGroupIsUpdate = (boolean)FALSE;
		}
	}
}
#endif

/**
 * @brief			rx signal value replace,and notification
 * @param[in]		RxSignalId: Identification of the received I-PDU.
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
STATIC FUNC(void,COM_CODE)
Com_InvalidSignalReplaceAndNotification(
	VAR(Com_SignalIdType, COM_VAR) RxSignalId
)
{
	uint16 initValueId;
	uint16 signal8NLength;
	uint16 cnt;
	uint16 initValueLength;
	uint64 initValue;
	Com_SignalType signalType;
	initValueId = COM_CFG_RXSIGNAL(RxSignalId).ComSignalInitValueId;
	signalType = COM_CFG_GET_RXSIGNAL_TYPE(RxSignalId);
	if((signalType != COM_UINT8_N) && (signalType != COM_UINT8_DYN))
	{
		initValue = Com_ReplaceRxSignal(signalType,initValueId);
		if((boolean)TRUE == Com_FilterRxSignal(initValue,COM_CFG_RXSIGNAL(RxSignalId).ComFilter,\
				signalType,initValueId))
		{
			/* update signal value into signal runtime buffer */
			Com_UpdateRxSignalBuff(initValue,RxSignalId);
			if(NULL_PTR != COM_CFG_RXSIGNAL(RxSignalId).ComNotification)
			{
				COM_CFG_RXSIGNAL(RxSignalId).ComNotification();
			}
		}
	}
	else
	{
    	if((NULL_PTR == COM_CFG_RXSIGNAL(RxSignalId).ComFilter) ||
    			((NULL_PTR != COM_CFG_RXSIGNAL(RxSignalId).ComFilter) \
    					&& (COM_ALWAYS == COM_CFG_RXSIGNAL(RxSignalId).ComFilter->ComFilterAlgorithm)))
    	{
    		if(signalType == COM_UINT8_N)
    		{
    			signal8NLength = COM_CFG_RXSIGNAL(RxSignalId).ComSignalLength;
    			for(cnt = 0u;cnt < signal8NLength;cnt++)
    			{
#if(COM_NUMBER_OF_8BITSIGNAL > 0u)
    				Com_8BitSignalRuntimeValue[initValueId + cnt] = \
    						Com_8BitSignalOriginalValue[initValueId + cnt];
#endif
    			}
    			if(NULL_PTR != COM_CFG_RXSIGNAL(RxSignalId).ComNotification)
    			{
    				COM_CFG_RXSIGNAL(RxSignalId).ComNotification();
    			}
    		}
    		else
    		{
    			initValueLength = COM_CFG_RXSIGNAL(RxSignalId).ComSignalDataInitValueLength;
    			for(cnt = 0u;cnt < initValueLength;cnt++)
    			{
#if(COM_NUMBER_OF_8BITSIGNAL > 0u)
    				Com_8BitSignalRuntimeValue[initValueId + cnt] = \
    						Com_8BitSignalOriginalValue[initValueId + cnt];
#endif
    			}
    			if(NULL_PTR != COM_CFG_RXSIGNAL(RxSignalId).ComNotification)
    			{
    				COM_CFG_RXSIGNAL(RxSignalId).ComNotification();
    			}
    		}
    	}
	}
	return;
}

#if(COM_NUMBER_OF_RXIPDU > 0)
/**
 * @brief			unpack the rx signal and notification up layer
 * @param[in]		SignalId: signal identify
 * @param[in]		DynSignalLength: length of signal
 * @param[in]		bufferid: The current signal corresponds to the position of the pdu in the
 * 					entire pdu array
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
STATIC FUNC(void,COM_CODE)
Com_SignalRxIndication(
	VAR(Com_SignalIdType, COM_VAR) SignalId,
	VAR(uint16, COM_VAR) DynSignalLength,
	VAR(uint16, COM_VAR) bufferid
)
{
	uint16 signallength;
	uint16 gwSignalBufferId;
	uint16 cnt;
#if(COM_LENGTH_OF_GW8BITSIGNALBUFFER > 0u)
	uint32 bitPosition;
#endif
	gwSignalBufferId = COM_CFG_RXSIGNAL(SignalId).GWSignalBufferId;
#if(COM_LENGTH_OF_GW8BITSIGNALBUFFER > 0u)
	bitPosition = COM_CFG_RXSIGNAL(SignalId).ComBitPosition;
#endif
	if(COM_UINT8_N == COM_CFG_RXSIGNAL(SignalId).ComSignalType)
	{
		signallength = COM_CFG_RXSIGNAL(SignalId).ComSignalLength;
		/* the rx signal need to be gateway,then store the value to gateway buffer */
		if(0xffffu != gwSignalBufferId)
		{
			for(cnt = 0u;cnt < signallength;cnt++)
			{
#if(COM_LENGTH_OF_GW8BITSIGNALBUFFER > 0u)
				Com_GW8BitSignalBuff[gwSignalBufferId + cnt] = \
						Com_RxIPduRuntimeValue[bufferid + (uint16)(bitPosition >> 3u) + cnt];
#endif
			}
		}
		Com_Handle8_NSignal(SignalId,signallength,bufferid);
	}
	else if(COM_UINT8_DYN == COM_CFG_RXSIGNAL(SignalId).ComSignalType)
	{
		if(0xffffu != gwSignalBufferId)
		{
			for(cnt = 0u;cnt < DynSignalLength;cnt++)
			{
#if(COM_LENGTH_OF_GW8BITSIGNALBUFFER > 0u)
				Com_GW8BitSignalBuff[gwSignalBufferId + cnt] = \
						Com_RxIPduRuntimeValue[bufferid + (uint16)(bitPosition >> 3u) + cnt];
#endif
			}
		}
		Com_Handle8DYNSignal(SignalId,DynSignalLength,bufferid);
	}
	else
	{
		Com_HandleRxSignal(SignalId);
	}
	return;
}
#endif

#if(COM_NUMBER_OF_RXIPDU > 0)
/**
 * @brief			unpack the rx signal and notification up layer
 * @param[in]		SignalGroupId: signal group identify
 * @param[in]		DynSignalLength: length of signal
 * @param[in]		bufferid: The current signal corresponds to the position of the pdu in the
 * 					entire pdu array
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
STATIC FUNC(void,COM_CODE)
Com_SignalGroupRxIndication(
	VAR(Com_SignalGroupIdType, COM_VAR) SignalGroupId,
	VAR(uint16, COM_VAR) DynSignalLength,
	VAR(uint16, COM_VAR) bufferid
)
{
#if(COM_NUMBER_OF_RXIPDU > 0)
	PduIdType pduId;
	Com_SignalIdType groupSignalNumber;
	Com_SignalIdType counter;
	uint16 cnt;
	uint16 signalLength;
	uint16 signalGroupIsInvalid = (boolean)FALSE;
	uint16 invalidValueId;
	uint16 initValueId;
	boolean needFilter = (boolean)TRUE;
	Com_SignalIdType groupSignalId;
	uint16 gwSignalBufferId;
	Com_SignalType signalType;
	groupSignalNumber = COM_CFG_RXSIGNALGROUP(SignalGroupId).ComGroupSignalNumber;
	pduId = COM_CFG_RXSIGNALGROUP(SignalGroupId).ComIpduRefIndex;
	for(cnt = 0u; cnt < groupSignalNumber; cnt ++)
	{
		groupSignalId = COM_CFG_RXSIGNALGROUP(SignalGroupId).ComRxGroupSignalId[cnt];
		invalidValueId = COM_CFG_RXGROUPSIGNAL(groupSignalId).ComSignalDataInvalidValueId;
		gwSignalBufferId = COM_CFG_RXGROUPSIGNAL(groupSignalId).GWSignalBufferId;
		signalType = COM_CFG_RXGROUPSIGNAL(groupSignalId).ComSignalType;
		signalGroupIsInvalid = Com_HandleSignalGroupRxIndication(signalType, groupSignalId,\
				DynSignalLength, invalidValueId, gwSignalBufferId, bufferid);
		if((boolean)TRUE == signalGroupIsInvalid)
		{
			/**
			 * @req [SWS_Com_00682] ComDataInvalidAction is replace ,replace the signal's value by its
			 * 						configured ComSignalInitValue
			 * @req [SWS_Com_00718] ComDataInvalidAction is NOTIFY ,replace the signal's value by its
			 * 						configured ComSignalInitValue
			 */
			needFilter =(boolean) FALSE;
			if(COM_INVALID_ACTION_NOTIFY == COM_CFG_RXSIGNALGROUP(SignalGroupId).ComDataInvalidAction)
			{
				if(NULL_PTR != COM_CFG_RXSIGNALGROUP(SignalGroupId).ComInvalidNotification)
				{
					COM_CFG_RXSIGNALGROUP(SignalGroupId).ComInvalidNotification();
				}
			}
			else
			{
				initValueId = COM_CFG_RXGROUPSIGNAL(groupSignalId).ComSignalInitValueId;
				if(signalType == COM_UINT8_N)
				{
					signalLength = COM_CFG_RXGROUPSIGNAL(groupSignalId).ComSignalLength;
				}
				else if(signalType == COM_UINT8_DYN)
				{
					signalLength = COM_CFG_RXGROUPSIGNAL(groupSignalId).ComSignalDataInitValueLength;
					Com_RxIPduLength[pduId].RxIpduLength = \
							COM_CFG_RXPDU(pduId).IPduNoDynSignalLength + signalLength;
				}
				else
				{
					signalLength = 0u;
				}
				Com_InitSignalBuffer(signalType,initValueId,signalLength);
			}
		}
	}
	if((boolean)TRUE == needFilter)
	{
		/**
		 * @req [SWS_Com_00836] If filters out a signal to false,discard that signal
		 */
		if((boolean)TRUE == Com_FilterRxSignalGroup((Com_SignalGroupIdType)SignalGroupId,\
				(boolean)signalGroupIsInvalid,(uint16)bufferid))
		{
			for(counter = 0u;counter < groupSignalNumber;counter++)
			{
				groupSignalId = COM_CFG_RXSIGNALGROUP(SignalGroupId).ComRxGroupSignalId[counter];
				Com_UpdateRxGroupSignalBuff((boolean)signalGroupIsInvalid,(Com_SignalIdType)groupSignalId,\
						(uint16)bufferid,(uint16)DynSignalLength);
			}
			/* if this group signal has normal rx notification function configured,
			   invoke this function. */
			if(NULL_PTR != Com_ConfigPtr->ComRxSignalGroup[SignalGroupId].ComNotification)
			{
				Com_ConfigPtr->ComRxSignalGroup[SignalGroupId].ComNotification();
			}
		}

	}
#endif
}
#endif

#if(COM_NUMBER_OF_RXIPDU > 0)
/**
 * @brief			Processing of signal group reception
 * @param[in]		SignalType: type of group signal
 * @param[in]		GroupSignalId: group signal identify
 * @param[in]		DynSignalLength: length of signal
 * @param[in]		invalidValueId: The invalid value of the signal corresponds to the position
 * 					in the array
 * @param[in]		gwSignalBufferId: The location of the gateway signal in the same array
 * @param[in]		bufferid: The current signal corresponds to the position of the pdu in the
 * 					entire pdu array
 * @param[out]		/
 * @param[in/out]	/
 * @return			boolean
 * @retval			TRUE
 * 					FALSE
 */
STATIC FUNC(boolean,COM_CODE)
Com_HandleSignalGroupRxIndication(
	VAR(Com_SignalType, COM_VAR) SignalType,
	VAR(Com_SignalIdType, COM_VAR) GroupSignalId,
	VAR(uint16, COM_VAR) DynSignalLength,
	VAR(uint16, COM_VAR) invalidValueId,
	VAR(uint16, COM_VAR) gwSignalBufferId,
	VAR(uint16, COM_VAR) bufferid
)
{
	boolean signalGroupIsInvalid = (boolean)FALSE;
	uint16 signal8NLength;
#if(COM_NUMBER_OF_NVALID_8BITSIGNAL > 0u || \
		COM_LENGTH_OF_GW8BITSIGNALBUFFER > 0u)
	uint32 bitPosition;
#endif
	uint16 cnt;
	uint64 unPackValue;
#if(COM_NUMBER_OF_NVALID_8BITSIGNAL > 0u || \
		COM_LENGTH_OF_GW8BITSIGNALBUFFER > 0u)
	bitPosition = COM_CFG_RXGROUPSIGNAL(GroupSignalId).ComBitPosition;
#endif
	if(COM_UINT8_N == SignalType)
	{
		signal8NLength = COM_CFG_RXGROUPSIGNAL(GroupSignalId).ComSignalLength;
		if(0xffffu != invalidValueId)
		{
			for(cnt = 0u;cnt < signal8NLength;cnt++)
			{
#if(COM_NUMBER_OF_NVALID_8BITSIGNAL > 0u)
				if(Com_8BitSignalInvalidValue[invalidValueId + cnt] == \
						Com_RxIPduRuntimeValue[bufferid + (uint16)(bitPosition >> 3u) + cnt])
				{
					signalGroupIsInvalid = (boolean)TRUE;
				}
#endif
			}
		}
		/* the group signal need gateway,store group signal value in gateway buffer */
		if(0xffffu != gwSignalBufferId)
		{
			for(cnt = 0u;cnt < signal8NLength;cnt++)
			{
#if(COM_LENGTH_OF_GW8BITSIGNALBUFFER > 0u)
				Com_GW8BitSignalBuff[gwSignalBufferId + cnt] = \
						Com_RxIPduRuntimeValue[bufferid + (uint16)(bitPosition >> 3u) + cnt];
#endif
			}
		}
	}
	else if(COM_UINT8_DYN == SignalType)
	{
		if(0xffffu != invalidValueId)
		{
			if(DynSignalLength != COM_CFG_RXGROUPSIGNAL(GroupSignalId).ComSignalDataInvalidValueLength)
			{
				signalGroupIsInvalid = (boolean)FALSE;
			}
			else
			{
				for(cnt = 0u;cnt < DynSignalLength;cnt++)
				{
#if(COM_NUMBER_OF_NVALID_8BITSIGNAL > 0u)
					if(Com_8BitSignalInvalidValue[invalidValueId + cnt] == \
							Com_RxIPduRuntimeValue[bufferid + (uint16)(bitPosition >> 3u) + cnt])
					{
						signalGroupIsInvalid = (boolean)TRUE;
					}
#endif
				}
			}
		}
		if((uint16)0xffff != gwSignalBufferId)
		{
			for(cnt = 0u;cnt < DynSignalLength;cnt++)
			{
#if(COM_LENGTH_OF_GW8BITSIGNALBUFFER > 0u)
				Com_GW8BitSignalBuff[gwSignalBufferId + cnt] = \
						Com_RxIPduRuntimeValue[bufferid + (uint16)(bitPosition >> 3u) + cnt];
#endif
			}
		}
	}
	else
	{
		unPackValue = Com_UnPackRxGroupSignal(GroupSignalId,bufferid);
		Com_UpdateGWSignalBuffer(unPackValue,gwSignalBufferId,\
				COM_CFG_RXGROUPSIGNAL(GroupSignalId).ComSignalType);
		/* PRQA S 2991, 2995 EOF #violate MISAR2004_13.7:ingore this warnning */
		if((0xffffu != invalidValueId) && ((boolean)FALSE == signalGroupIsInvalid))
		{
			signalGroupIsInvalid = Com_HandleSignalInvalidate\
					(COM_CFG_RXGROUPSIGNAL(GroupSignalId).ComSignalType,invalidValueId,unPackValue);
		}
	}
	return signalGroupIsInvalid;
}
#endif

#if(COM_NUMBER_OF_RXIPDU > 0)
/**
 * @brief			unpack the rx signal(signal type is COM_UINT8_N) and notification up layer
 * @param[in]		SignalId: signal identify
 * @param[in]		SignalLength: length of signal
 * @param[in]		BufferId: The current signal corresponds to the position of the pdu in the
 * 					entire pdu array
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
STATIC FUNC(void,COM_CODE)
Com_Handle8_NSignal(
	VAR(Com_SignalIdType, COM_VAR) SignalId,
	VAR(uint16, COM_VAR) SignalLength,
	VAR(uint16, COM_VAR) BufferId
)
{
	boolean needFilter = (boolean)TRUE;
	uint16 invalidValueId;
#if(COM_NUMBER_OF_8BITSIGNAL > 0u)
	uint32 bitPosition;
	uint16 initValueId;
#endif
	uint16 cnt;
	uint16 index;
#if(COM_NUMBER_OF_8BITSIGNAL > 0u)
	initValueId = COM_CFG_RXSIGNAL(SignalId).ComSignalInitValueId;
	bitPosition = COM_CFG_RXSIGNAL(SignalId).ComBitPosition;
#endif
	invalidValueId = COM_CFG_RXSIGNAL(SignalId).ComSignalDataInvalidValueId;
	if((uint16)0xffff != invalidValueId)
	{
		for(cnt = 0u; cnt < SignalLength; cnt++)
		{
#if(COM_NUMBER_OF_NVALID_8BITSIGNAL > 0u)
			if(Com_RxIPduRuntimeValue[BufferId + (uint16)(bitPosition >> 3u) + cnt] == \
					Com_8BitSignalInvalidValue[invalidValueId + cnt])
			{
				/**
				 * @req [SWS_Com_00680] ComDataInvalidAction is NOTIFY for this signal, replace the
				 * 						signal's value by its configured ComSignalInitValue
				 */
				if(COM_INVALID_ACTION_NOTIFY == COM_CFG_RXSIGNAL(SignalId).ComDataInvalidAction)
				{
					if(NULL_PTR != COM_CFG_RXSIGNAL(SignalId).ComInvalidNotification)
					{
						COM_CFG_RXSIGNAL(SignalId).ComInvalidNotification();
					}
				}
				else
				{
					if((NULL_PTR == COM_CFG_RXSIGNAL(SignalId).ComFilter) ||
							((NULL_PTR != COM_CFG_RXSIGNAL(SignalId).ComFilter)\
							&&(COM_ALWAYS == COM_CFG_RXSIGNAL(SignalId).ComFilter->ComFilterAlgorithm)))
					{
						for(index = 0u;index < SignalLength;index++)
						{
							Com_8BitSignalRuntimeValue[initValueId + index] = \
									Com_8BitSignalOriginalValue[initValueId + index];
						}
						if(NULL_PTR != COM_CFG_RXSIGNAL(SignalId).ComNotification)
						{
							COM_CFG_RXSIGNAL(SignalId).ComNotification();
						}
					}
				}
				needFilter =(boolean) FALSE;
			}
#endif
		}
	}
	if((boolean)TRUE == needFilter)
	{
		if((NULL_PTR == COM_CFG_RXSIGNAL(SignalId).ComFilter) ||
				((NULL_PTR != COM_CFG_RXSIGNAL(SignalId).ComFilter)\
						&&(COM_ALWAYS == COM_CFG_RXSIGNAL(SignalId).ComFilter->ComFilterAlgorithm)))
		{
			for(index = 0u;index < SignalLength;index++)
			{
#if(COM_NUMBER_OF_8BITSIGNAL > 0u)
				Com_8BitSignalRuntimeValue[initValueId + index] = \
						Com_RxIPduRuntimeValue[BufferId + (uint16)(bitPosition >> 3u) + index];
#endif
			}
			if(NULL_PTR != COM_CFG_RXSIGNAL(SignalId).ComNotification)
			{
				COM_CFG_RXSIGNAL(SignalId).ComNotification();
			}
		}
	}
	return;
}
#endif

#if(COM_NUMBER_OF_RXIPDU > 0)
/**
 * @brief			unpack the rx signal(signal type is COM_UINT8_DYN) and notification up layer
 * @param[in]		SignalId: signal identify
 * @param[in]		SignalLength: length of signal
 * @param[in]		BufferId: The current signal corresponds to the position of the pdu in the
 * 					entire pdu array
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
STATIC FUNC(void,COM_CODE)
Com_Handle8DYNSignal(
	VAR(Com_SignalIdType, COM_VAR) SignalId,
	VAR(uint16, COM_VAR) SignalLength,
	VAR(uint16, COM_VAR) BufferId
)
{
	boolean needFilter = (boolean)TRUE;
	uint16 invalidValueId;
	uint16 cnt;
	uint16 index;
#if(COM_NUMBER_OF_8BITSIGNAL > 0u)
	uint16 initValueId;
	uint32 bitPosition;
#endif
#if(COM_NUMBER_OF_NVALID_8BITSIGNAL > 0u)
	uint16 InitValueLength;
	uint16 rxIpduLength;
#endif
#if(COM_NUMBER_OF_8BITSIGNAL > 0u)
	initValueId = COM_CFG_RXSIGNAL(SignalId).ComSignalInitValueId;
	bitPosition = COM_CFG_RXSIGNAL(SignalId).ComBitPosition;
#if(COM_NUMBER_OF_NVALID_8BITSIGNAL > 0u)
	InitValueLength = COM_CFG_RXSIGNAL(SignalId).ComSignalDataInitValueLength;
#endif
#endif
	invalidValueId = COM_CFG_RXSIGNAL(SignalId).ComSignalDataInvalidValueId;
    if(0xffffu != invalidValueId)
    {
    	if(SignalLength == COM_CFG_RXSIGNAL(SignalId).ComSignalDataInvalidValueLength)
    	{
    		for(cnt = 0u;cnt < SignalLength; cnt++)
    		{
#if(COM_NUMBER_OF_NVALID_8BITSIGNAL > 0u)
    			if((Com_RxIPduRuntimeValue[BufferId + ((uint16)bitPosition >> 3u) + cnt]) == \
    					(Com_8BitSignalInvalidValue[invalidValueId + cnt]))
    			{
    	    		/**
    	    		 * @req [SWS_Com_00680] ComDataInvalidAction is NOTIFY for this signal, replace the
    	    		 * 						signal's value by its configured ComSignalInitValue
    	    		 */
    	            if(COM_INVALID_ACTION_NOTIFY == \
    	            		Com_ConfigPtr->ComRxSignal[SignalId].ComDataInvalidAction)
    	            {
    	            	if(NULL_PTR != COM_CFG_RXSIGNAL(SignalId).ComInvalidNotification)
    	            	{
    	            		COM_CFG_RXSIGNAL(SignalId).ComInvalidNotification();
    	            	}
    	            }
    	            else
    	            {
    	            	if((NULL_PTR == COM_CFG_RXSIGNAL(SignalId).ComFilter) ||
    	            			((NULL_PTR != COM_CFG_RXSIGNAL(SignalId).ComFilter)\
							&&(COM_ALWAYS == COM_CFG_RXSIGNAL(SignalId).ComFilter->ComFilterAlgorithm)))
    	            	{
    	                	for(index = 0u;index < InitValueLength;index++)
    	                	{
    	                		Com_8BitSignalRuntimeValue[initValueId + index] = \
    	                				Com_8BitSignalOriginalValue[initValueId + index];
    	                	}
    	                	/* change the rx Ipdu length to Init rx Ipdu length */
    	                	rxIpduLength = Com_RxIPduLength\
    	                			[COM_CFG_RXSIGNAL(SignalId).ComIpduRefIndex].RxIpduLength;
    	                	rxIpduLength = (rxIpduLength - SignalLength) + InitValueLength;
    	                	Com_RxIPduLength[COM_CFG_RXSIGNAL(SignalId).ComIpduRefIndex].\
								RxIpduLength = rxIpduLength;
    	                    if(NULL_PTR != COM_CFG_RXSIGNAL(SignalId).ComNotification)
    	                    {
    	                    	COM_CFG_RXSIGNAL(SignalId).ComNotification();
    	                    }
    	            	}
    	            }
    	            needFilter =(boolean) FALSE;
    			}
#endif
    		}
    	}
    }
    if((boolean)TRUE == needFilter)
    {
    	if((NULL_PTR == COM_CFG_RXSIGNAL(SignalId).ComFilter) ||
    			((NULL_PTR != COM_CFG_RXSIGNAL(SignalId).ComFilter)\
    					&&(COM_ALWAYS == COM_CFG_RXSIGNAL(SignalId).ComFilter->ComFilterAlgorithm)))
    	{
			for(index = 0u;index < SignalLength;index++)
			{
#if(COM_NUMBER_OF_8BITSIGNAL > 0u)
				Com_8BitSignalRuntimeValue[initValueId + index] = \
						Com_RxIPduRuntimeValue[BufferId + (uint16)(bitPosition >> 3u) + index];
#endif
			}
            if(NULL_PTR != COM_CFG_RXSIGNAL(SignalId).ComNotification)
            {
            	COM_CFG_RXSIGNAL(SignalId).ComNotification();
            }
    	}
    }
	return;
}
#endif

#if(COM_NUMBER_OF_RXIPDU > 0u)
/**
 * @brief			unpack the rx signal and notification up layer
 * @param[in]		SignalId: signal identify
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
STATIC FUNC(void,COM_CODE)  /*Unpack signals, and processing of signals*/
Com_HandleRxSignal(
	VAR(Com_SignalIdType, COM_VAR) SignalId
)
{
	boolean needFilter = (boolean)TRUE;
	uint64 UnPackValue;
	uint16 invalidValueId;
	uint16 initValueId;
	uint16 gwSignalBufferId;
	Com_SignalType SignalType;
	boolean signalIsValid;
	invalidValueId = COM_CFG_RXSIGNAL(SignalId).ComSignalDataInvalidValueId;
	gwSignalBufferId = COM_CFG_RXSIGNAL(SignalId).GWSignalBufferId;
	SignalType = COM_CFG_RXSIGNAL(SignalId).ComSignalType;
	initValueId = COM_CFG_RXSIGNAL(SignalId).ComSignalInitValueId;
	UnPackValue = Com_UnPackRxSignal(SignalId);
	Com_UpdateGWSignalBuffer(UnPackValue,gwSignalBufferId,SignalType);
	/* If the signal is configured with valid values */
	if(0xffffu != invalidValueId)
	{
		if((boolean)TRUE == Com_HandleSignalInvalidate(SignalType,invalidValueId,UnPackValue))
		{
			/**
			 * @req [SWS_Com_00680]
			 * @req [SWS_Com_00681]
			 * @req [SWS_Com_00682]
			 * @req [SWS_Com_00683]
			 * @req [SWS_Com_00717]
			 * @req [SWS_Com_00718] ComDataInvalidAction is replace ,replace the signal's value by its
			 * 						configured ComSignalInitValue
			 */
			if(COM_INVALID_ACTION_NOTIFY == COM_CFG_RXSIGNAL(SignalId).ComDataInvalidAction)
			{
				if(NULL_PTR != COM_CFG_RXSIGNAL(SignalId).ComInvalidNotification)
				{
					COM_CFG_RXSIGNAL(SignalId).ComInvalidNotification();
				}
				needFilter = (boolean)FALSE;
			}
			else
			{
				/* replace signal runtime buffer, with init value. */
				UnPackValue = Com_ReplaceRxSignal(SignalType,initValueId);
			}
		}
	}
	if((boolean)TRUE == needFilter)
	{
		signalIsValid = Com_FilterRxSignal(UnPackValue,COM_CFG_RXSIGNAL(SignalId).ComFilter,\
				SignalType,initValueId);
		 /* @req [SWS_Com_00273]
		  * @req [SWS_Com_00302]
		  * @req [SWS_Com_00303]
		  */
		if((boolean)TRUE == signalIsValid)
		{
			Com_UpdateRxSignalBuff(UnPackValue, SignalId);
			/* @req [SWS_Com_00300] If ComIPduSignalProcessing is configured to IMMEDIATE,
			 * 						invoke the configured ComNotifications
			 */
			if(NULL_PTR != COM_CFG_RXSIGNAL(SignalId).ComNotification)
			{
				COM_CFG_RXSIGNAL(SignalId).ComNotification();
			}
		}
	}
	return;
}
#endif

#if(COM_NUMBER_OF_RXIPDU > 0u)
/**
 * @brief			unpack the rx signal(signal type isn't COM_UINT8_N or COM_UINT8_DYN)
 * @param[in]		SignalId: signal identify
 * @param[out]		/
 * @param[in/out]	/
 * @return			uint64
 * @retval			/
 */
STATIC FUNC(uint64,COM_CODE)
Com_UnPackRxSignal(
	VAR(Com_SignalIdType, COM_VAR) SignalId
)
{
	PduLengthType bytePos;
	uint16 remainBits;
	uint16 needCopyBits;
	uint8 bitOffset;
	Com_SignalType signalType;
	Com_SignalEndiannessType signalEndianness;
	uint8 bitSize;
	PduIdType pduId;
	uint16 pduBufferIdx;
	uint32 bitPosition;
	uint64 unPackValue = 0xFFFFFFFFFFFFFFFFu;
	pduId = COM_CFG_RXSIGNAL(SignalId).ComIpduRefIndex;
	signalType = COM_CFG_RXSIGNAL(SignalId).ComSignalType;
	pduBufferIdx = COM_CFG_RXPDU(pduId).ComRxIPduBufIndex;
	signalEndianness = COM_CFG_RXSIGNAL(SignalId).ComSignalEndianness;
	bitPosition = COM_CFG_RXSIGNAL(SignalId).ComBitPosition;
	bitSize = COM_CFG_RXSIGNAL(SignalId).ComBitSize;
	bytePos = (PduLengthType)(bitPosition >> 3u);
	bitOffset = (uint8)(bitPosition & 0x07u);
	if(bitSize > 0u)
	{
		unPackValue = (uint64)((uint64)Com_RxIPduRuntimeValue[pduBufferIdx + bytePos] >> bitOffset);
		if(bitSize > (8u - bitOffset))
		{
			needCopyBits = (uint16)(8u - (uint16)bitOffset);
		}
		else
		{
			unPackValue = unPackValue & (uint8)(~(uint8)(0xFFu << bitSize));
			needCopyBits = bitSize;
		}
		while(needCopyBits < bitSize)
		{
			remainBits = bitSize - needCopyBits;
			if(signalEndianness != COM_BIG_ENDIAN)
			{
				bytePos++;
			}
			else
			{
				bytePos--;
			}
			if(remainBits >= 8u)
			{
				unPackValue |= (((uint64)(Com_RxIPduRuntimeValue[pduBufferIdx + bytePos])) << needCopyBits);
				needCopyBits += 8u;
			}
			else
			{
				unPackValue |= ((uint64)((uint64)(Com_RxIPduRuntimeValue[pduBufferIdx + bytePos]) \
						& ((uint8)(0xFFu >> (8u - remainBits)))) << needCopyBits);
				needCopyBits += remainBits;
			}

		}
		if((signalType == COM_SINT8) || (signalType == COM_SINT16) \
				|| (signalType == COM_SINT32) || (signalType == COM_SINT64))
		{
			unPackValue |= (((uint64)(0xFFFFFFFFFFFFFFFFu)) << (bitSize - 1u));
		}
	}
	return unPackValue;
}
#endif

#if(COM_NUMBER_OF_RXIPDU > 0u)
/**
 * @brief			unpack the rx group signal(signal type isn't COM_UINT8_N or COM_UINT8_DYN)
 * @param[in]		SignalId: signal identify
 * @param[in]		bufferid: The current signal corresponds to the position of the pdu in the
 * 					entire pdu array
 * @param[out]		/
 * @param[in/out]	/
 * @return			uint64
 * @retval			/
 */
STATIC FUNC(uint64,COM_CODE)
Com_UnPackRxGroupSignal(
	VAR(Com_SignalIdType, COM_VAR) SignalId,
	VAR(uint16, COM_VAR) PduBufferIdx
)
{
	PduLengthType bytePos;
	uint16 remainBits;
	uint16 needCopyBits;
	uint8 bitOffset;
	uint64 unPackValue;
	uint32 bitPosition;
	Com_SignalType signalType;
	Com_SignalEndiannessType signalEndianness;
	uint8 bitSize;
	bitPosition = COM_CFG_RXGROUPSIGNAL(SignalId).ComBitPosition;
	signalType = COM_CFG_RXGROUPSIGNAL(SignalId).ComSignalType;
	signalEndianness = COM_CFG_RXGROUPSIGNAL(SignalId).ComSignalEndianness;
	bitSize = COM_CFG_RXGROUPSIGNAL(SignalId).ComBitSize;
	bytePos = (PduLengthType)(bitPosition >> 3u);
	bitOffset = (uint8)(bitPosition & 0x07u);
	unPackValue = (uint64)((uint64)Com_RxIPduRuntimeValue[PduBufferIdx + bytePos] >> bitOffset);
	if(bitSize > (8u - bitOffset))
	{
		needCopyBits = (uint16)(8u - (uint16)bitOffset);
	}
	else
	{
		unPackValue = unPackValue & (uint8)(~(uint8)(0xFFu << bitSize));
		needCopyBits = bitSize;
	}
	while(needCopyBits < bitSize)
	{
		remainBits = bitSize - needCopyBits;
		if(signalEndianness != COM_BIG_ENDIAN)
		{
			bytePos++;
		}
		else
		{
			bytePos--;
		}
		if(remainBits >= 8u)
		{
			unPackValue |= (((uint64)(Com_RxIPduRuntimeValue[PduBufferIdx + bytePos])) << needCopyBits);
			needCopyBits += 8u;
		}
		else
		{
			unPackValue |= ((uint64)((uint64)(Com_RxIPduRuntimeValue[PduBufferIdx + bytePos]) \
					& ((uint8)(0xFFu >> (8u - remainBits)))) << needCopyBits);
			needCopyBits += remainBits;
		}
	}
	if((signalType == COM_SINT8) || (signalType == COM_SINT16) \
			|| (signalType == COM_SINT32) || (signalType == COM_SINT64))
	{
		unPackValue |= (((uint64)(0xFFFFFFFFFFFFFFFFu)) << (bitSize - 1u));
	}
	return unPackValue;
}
#endif

#if(COM_NUMBER_OF_RXIPDU > 0)
/**
 * @brief			update the gateway signal value buffer of the rx signal
 * @param[in]		Value: value of signal
 * @param[in]		GWSignalBufferId: The current signal is located in the entire array of signals
 * @param[in]		SignalType: type of signal
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
STATIC FUNC(void,COM_CODE)
Com_UpdateGWSignalBuffer(
	VAR(uint64, COM_VAR) Value,
	VAR(uint16, COM_VAR) GWSignalBufferId,
	VAR(Com_SignalType, COM_VAR) SignalType
)
{
	/*the rx signal need gateway,store signal value in gateway buffer*/
    if(0xffffu != GWSignalBufferId)
    {
        switch(SignalType)
        {
            case COM_BOOLEAN:
#if(COM_LENGTH_OF_GWBOOLSIGNALBUFFER > 0u)
            	Com_GWBoolSignalBuff[GWSignalBufferId] = (boolean)Value;
#endif
    			break;
            case COM_UINT8:
            case COM_SINT8:
#if(COM_LENGTH_OF_GW8BITSIGNALBUFFER > 0u)
            	Com_GW8BitSignalBuff[GWSignalBufferId] = (uint8)Value;
#endif
    			break;
            case COM_UINT16:
            case COM_SINT16:
#if(COM_LENGTH_OF_GW16BITSIGNALBUFFER > 0u)
            	Com_GW16BitSignalBuff[GWSignalBufferId] = (uint16)Value;
#endif
    			break;
            case COM_UINT32:
            case COM_SINT32:
            case COM_FLOAT32:
#if(COM_LENGTH_OF_GW32BITSIGNALBUFFER > 0u)
            	Com_GW32BitSignalBuff[GWSignalBufferId] = (uint32)Value;
#endif
    			break;
            case COM_UINT64:
            case COM_SINT64:
            case COM_FLOAT64:
#if(COM_LENGTH_OF_GW64BITSIGNALBUFFER > 0u)
            	Com_GW64BitSignalBuff[GWSignalBufferId] = Value;
#endif
    			break;
            default:
            	break;
        }
    }
	return;
}
#endif

#if(COM_NUMBER_OF_RXIPDU > 0)
/**
 * @brief			judge the rx (group) signal value is invalid value or not
 * @param[in]		SignalType: type of signal
 * @param[in]		InvalidValueId: The null value of the signal is in the array
 * @param[in]		Value: value of signal
 * @param[out]		/
 * @param[in/out]	/
 * @return			boolean
 * @retval			TRUE
 * 					FALSE
 */
STATIC FUNC(boolean,COM_CODE)
Com_HandleSignalInvalidate(
	VAR(Com_SignalType, COM_VAR) SignalType,
	VAR(uint16, COM_VAR) InvalidValueId,
	VAR(uint64, COM_VAR) Value
)
{
	boolean ret = (boolean)FALSE;
	switch(SignalType)
	{
		case COM_BOOLEAN:
#if(COM_NUMBER_OF_NVALID_BOOLSIGNAL > 0u)
			if(((boolean)Value) == Com_BoolSignalInvalidValue[InvalidValueId])
			{
				ret =(boolean) TRUE;
			}
#endif
			break;
		case COM_UINT8:
		case COM_SINT8:
#if(COM_NUMBER_OF_NVALID_8BITSIGNAL > 0u)
			if(((uint8)Value) == Com_8BitSignalInvalidValue[InvalidValueId])
			{
				ret =(boolean) TRUE;
			}
#endif
			break;
		case COM_UINT16:
		case COM_SINT16:
#if(COM_NUMBER_OF_NVALID_16BITSIGNAL > 0u)
			if(((uint16)Value) == Com_16BitSignalInvalidValue[InvalidValueId])
			{
				ret = (boolean)TRUE;
			}
#endif
			break;
		case COM_UINT32:
		case COM_SINT32:
		case COM_FLOAT32:
#if(COM_NUMBER_OF_NVALID_32BITSIGNAL > 0u)
			if(((uint32)Value) == Com_32BitSignalInvalidValue[InvalidValueId])
			{
				ret =(boolean) TRUE;
			}
#endif
			break;
		case COM_UINT64:
		case COM_SINT64:
		case COM_FLOAT64:
#if(COM_NUMBER_OF_NVALID_64BITSIGNAL > 0u)
			if(Value == Com_64BitSignalInvalidValue[InvalidValueId])
			{
				ret =(boolean) TRUE;
			}
#endif
			break;
		default:
			break;
	}
	return ret;
}
#endif

/**
 * @brief			get the rx (group) signal's init value
 * @param[in]		SignalType: type of the signal.
 * @param[in]		InitValueId: The current signal is at the beginning of the same type of signal
 * @param[out]		/
 * @param[in/out]	/
 * @return			uint64
 * @retval			/
 */
STATIC FUNC(uint64,COM_CODE)
Com_ReplaceRxSignal(
	VAR(Com_SignalType, COM_VAR) SignalType,
	VAR(uint16, COM_VAR) InitValueId
)
{
	uint64 UnPackValue = 0xffffffffu;
	if(SignalType == COM_BOOLEAN)
	{
#if(COM_NUMBER_OF_BOOLSIGNAL > 0u)
		UnPackValue = (uint64)Com_BoolSignalOriginalValue[InitValueId];
#endif
	}
	else if((SignalType == COM_UINT8) || (SignalType == COM_SINT8))
	{
#if(COM_NUMBER_OF_8BITSIGNAL > 0u)
		UnPackValue = (uint64)Com_8BitSignalOriginalValue[InitValueId];
#endif
	}
	else if((SignalType == COM_UINT16) || (SignalType == COM_SINT16))
	{
#if(COM_NUMBER_OF_16BITSIGNAL > 0u)
		UnPackValue = (uint64)Com_16BitSignalOriginalValue[InitValueId];
#endif
	}
	else if((SignalType == COM_UINT32) || (SignalType == COM_SINT32) || (SignalType == COM_FLOAT32))
	{
#if(COM_NUMBER_OF_32BITSIGNAL > 0u)
		UnPackValue = (uint64)Com_32BitSignalOriginalValue[InitValueId];
#endif
	}
	else if((SignalType == COM_UINT64) || (SignalType == COM_SINT64) || (SignalType == COM_FLOAT64))
	{
#if(COM_NUMBER_OF_64BITSIGNAL > 0u)
		UnPackValue = (uint64)Com_64BitSignalOriginalValue[InitValueId];
#endif
	}
	else
	{
		/* do nothing */
	}
	return UnPackValue;
}

/**
 * @brief			calculate the rx signal value is filter out or not
 * @param[in]		Value: The signal value of the solution package
 * @param[in]		ComFilter: Filter condition of signal
 * @param[in]		SignalType: type of signal
 * @param[in]		SignalBufferId: The signal is at the beginning of the similar type of signal
 * @param[out]		/
 * @param[in/out]	/
 * @return			booelan
 * @retval			TRUE/FALSE
 *
 * @req [SWS_Com_00695]
 */
STATIC FUNC(boolean,COM_CODE)
Com_FilterRxSignal(
	VAR(uint64, COM_VAR) Value,
	P2CONST(Com_FilterType, AUTOMATIC, COM_APPL_CONST) ComFilter,
	VAR(Com_SignalType, COM_VAR) SignalType,
	VAR(uint16, COM_VAR) SignalBufferId
)
{
	boolean ret = (boolean)TRUE;
	Com_FilterAlgorithmType filterType;
	#if(COM_NUMBER_OF_ONEEVERYNFILTERSIGNAL > 0u)
	Com_SignalIdType oneEveryNId;
	uint32 filterOffset;
	uint32 filterPeriod;
	#endif/* COM_NUMBER_OF_ONEEVERYNFILTERSIGNAL > 0 */
	#if(COM_NUMBER_OF_MASKNEWDIFFERMASKOLD_SIGNAL > 0u)
	Com_SignalIdType maskNewDifferMaskOldId;
	#endif/* COM_NUMBER_OF_MASKNEWDIFFERMASKOLD_SIGNAL > 0 */
	if(NULL_PTR != ComFilter)
	{
		ret =(boolean) FALSE;
		filterType = ComFilter->ComFilterAlgorithm;
		if(filterType == COM_ALWAYS)
		{
			ret = (boolean)TRUE;
		}
		else if(filterType == COM_NEVER)
		{
			ret = (boolean)FALSE;
		}
		else if(filterType == COM_MASKED_NEW_DIFFERS_X)
		{
			if((Value & ComFilter->ComFilterMask) != ComFilter->ComFilterX)
			{
				ret = (boolean)TRUE;
			}
		}
		else if(filterType == COM_MASKED_NEW_EQUALS_X)
		{
			if((Value & ComFilter->ComFilterMask) == ComFilter->ComFilterX)
			{
				ret = (boolean)TRUE;
			}
		}
		/**
		 * @req [SWS_Com_00439] bool signal not support WITHIN and OUTSIDE
		 */
		else if(filterType == COM_NEW_IS_OUTSIDE)
		{
			if((SignalType == COM_UINT8) || (SignalType == COM_UINT16) \
					|| (SignalType == COM_UINT32) || (SignalType == COM_UINT64))
			{
				if(((Value) > (ComFilter->ComFilterMax)) || ((Value) < (ComFilter->ComFilterMin)))
				{
					ret = (boolean)TRUE;
				}
			}
			else if((SignalType == COM_SINT8) || (SignalType == COM_SINT16) \
					|| (SignalType == COM_SINT32) || (SignalType == COM_SINT64))
			{
				if((((sint64)(Value)) > ((sint64)(ComFilter->ComFilterMax))) \
						|| (((sint64)(Value)) < ((sint64)(ComFilter->ComFilterMin))))
				{
					ret =(boolean) TRUE;
				}
			}
			else
			{
				/* do nothing */
			}
		}
		else if(filterType == COM_NEW_IS_WITHIN)
		{
			if((SignalType == COM_UINT8) || (SignalType == COM_UINT16) \
					|| (SignalType == COM_UINT32) || (SignalType == COM_UINT64))
			{
				if(((Value) <= (ComFilter->ComFilterMax)) && ((Value) >= (ComFilter->ComFilterMin)))
				{
					ret =(boolean) TRUE;
				}
			}
			else if((SignalType == COM_SINT8) || (SignalType == COM_SINT16) \
					|| (SignalType == COM_SINT32) || (SignalType == COM_SINT64))
			{
				if((((sint64)(Value)) <= ((sint64)(ComFilter->ComFilterMax))) \
						&& (((sint64)(Value)) >= ((sint64)(ComFilter->ComFilterMin))))
				{
					ret =(boolean) TRUE;
				}
			}
			else
			{
				/* do nothing */
			}
		}
#if(COM_NUMBER_OF_ONEEVERYNFILTERSIGNAL > 0u)
		else if(filterType == COM_ONE_EVERY_N)
		{
			filterOffset = ComFilter->ComFilterOffset;
			filterPeriod = ComFilter->ComFilterPeriod;
			oneEveryNId = ComFilter->ComOneEveryNId;
			/* @req [SWS_Com_00231] */
			if(filterPeriod == Com_OneEveryNcnt[oneEveryNId])
			{
				Com_OneEveryNcnt[oneEveryNId] = 0u;
			}
			/* @req [SWS_Com_00231] */
			if(filterOffset == Com_OneEveryNcnt[oneEveryNId])
			{
				ret = TRUE;
			}
			Com_OneEveryNcnt[oneEveryNId]++;
		}
#endif
#if(COM_NUMBER_OF_MASKNEWDIFFERMASKOLD_SIGNAL > 0u)
		else if(filterType == COM_MASKED_NEW_DIFFERS_MASKED_OLD)
		{
			/* @req [SWS_Com_00793] */
			maskNewDifferMaskOldId = ComFilter->ComMaskNewDifferMaskOldId;
			if(TRUE == Com_MaskNewDifferMaskOldTimeOut[maskNewDifferMaskOldId])
			{
				ret = TRUE;
				Com_MaskNewDifferMaskOldTimeOut[maskNewDifferMaskOldId] = FALSE;
			}
			else
			{
				Com_CalMaskedNewDiffersMaskedOldTMC(SignalType,Value,ComFilter,SignalBufferId,&ret);
			}
		}
#endif
		else
		{
			/* do nothing */
		}
	}
	return ret;
}

#if(COM_NUMBER_OF_RXIPDU > 0)
/**
 * @brief			judge the rx signal group value is filter out or not
 * @param[in]		SignalGroupId: Signal group identifier
 * @param[in]		SignalGroupInvalid: Whether the signal group is effective
 * @param[in]		BufferId: Whether the signal group is effective
 * @param[out]		/
 * @param[in/out]	/
 * @return			booelan
 * @retval			TRUE/FALSE
 */
STATIC FUNC(boolean,COM_CODE)
Com_FilterRxSignalGroup(
	VAR(Com_SignalGroupIdType, COM_VAR) SignalGroupId,
	VAR(boolean, COM_VAR) SignalGroupInvalid,
	VAR(uint16, COM_VAR) BufferId
)
{
	boolean ret = (boolean)TRUE;
	Com_SignalIdType GroupSignalNumber;
	Com_SignalIdType cnt=(Com_SignalIdType)0;
	Com_SignalIdType GroupSignalId;
	Com_SignalType GroupSignalType;
	uint16 GroupSignalInitValueId;
	uint64 unpackValue;
	GroupSignalNumber = COM_CFG_RXSIGNALGROUP(SignalGroupId).ComGroupSignalNumber;
	GroupSignalId = COM_CFG_RXSIGNALGROUP(SignalGroupId).ComRxGroupSignalId[cnt];
	GroupSignalType = COM_CFG_RXGROUPSIGNAL(GroupSignalId).ComSignalType;
	GroupSignalInitValueId = COM_CFG_RXGROUPSIGNAL(GroupSignalId).ComSignalInitValueId;
	if((boolean)TRUE == SignalGroupInvalid)
	{
		for(cnt = 0u; cnt < GroupSignalNumber; cnt++)
		{
			if((COM_UINT8_N == GroupSignalType) || (COM_UINT8_DYN == GroupSignalType))
			{
				if((NULL_PTR != COM_CFG_RXGROUPSIGNAL(GroupSignalId).ComFilter) && \
					(COM_NEVER == COM_CFG_RXGROUPSIGNAL(GroupSignalId).ComFilter->ComFilterAlgorithm))
				{
					ret =(boolean) FALSE;
				}
			}
			else /* If the signalgroup value is valid, replace it with the initial value */
			{
				unpackValue = Com_ReplaceRxSignal(GroupSignalType, GroupSignalInitValueId);
				ret = Com_FilterRxSignal(unpackValue, COM_CFG_RXGROUPSIGNAL(GroupSignalId).ComFilter, \
						GroupSignalType, BufferId);
			}
		}
	}
	else
	{
		for(cnt = 0u; (cnt < GroupSignalNumber) && ((boolean)TRUE == ret); cnt ++)
		{
			if((COM_UINT8_N == GroupSignalType) || (COM_UINT8_DYN == GroupSignalType))
			{
				if((NULL_PTR != COM_CFG_RXGROUPSIGNAL(GroupSignalId).ComFilter) && \
					(COM_NEVER == COM_CFG_RXGROUPSIGNAL(GroupSignalId).ComFilter->ComFilterAlgorithm))
				{
					ret =(boolean) FALSE;
				}
			}
			else
			{
				unpackValue = Com_UnPackRxGroupSignal(GroupSignalId, BufferId);
				ret = Com_FilterRxSignal(unpackValue, COM_CFG_RXGROUPSIGNAL(GroupSignalId).ComFilter, \
						GroupSignalType, BufferId);
			}
		}
	}
	return ret;
}
#endif

/**
 * @brief			update the rx signal value buffer
 * @param[in]		Value: The signal value of the solution package
 * @param[in]		SignalId: Signal identifier
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
STATIC FUNC(void,COM_CODE)
Com_UpdateRxSignalBuff(
	VAR(uint64, COM_VAR) Value,
	VAR(Com_SignalIdType, COM_VAR) SignalId
)
{
    uint16 initValueId;
    Com_SignalType SignalType;
    initValueId = COM_CFG_RXSIGNAL(SignalId).ComSignalInitValueId;
    SignalType = COM_CFG_RXSIGNAL(SignalId).ComSignalType;
    switch(SignalType)
    {
        case COM_BOOLEAN:
#if(COM_NUMBER_OF_BOOLSIGNAL > 0u)
        	Com_BoolSignalRuntimeValue[initValueId] = (boolean)Value;
#endif
			break;
        case COM_UINT8:
        case COM_SINT8:
#if(COM_NUMBER_OF_8BITSIGNAL > 0u)
        	Com_8BitSignalRuntimeValue[initValueId] = (uint8)Value;
#endif
			break;
        case COM_UINT16:
        case COM_SINT16:
#if(COM_NUMBER_OF_16BITSIGNAL > 0u)
        	Com_16BitSignalRuntimeValue[initValueId] = (uint16)Value;
#endif
			break;
        case COM_UINT32:
        case COM_SINT32:
        case COM_FLOAT32:
#if(COM_NUMBER_OF_32BITSIGNAL > 0u)
        	Com_32BitSignalRuntimeValue[initValueId] = (uint32)Value;
#endif
			break;
        case COM_UINT64:
        case COM_SINT64:
        case COM_FLOAT64:
#if(COM_NUMBER_OF_64BITSIGNAL > 0u)
        	Com_64BitSignalRuntimeValue[initValueId] = (uint64)Value;
#endif
			break;
        default:
        	break;
    }
	return;
}

#if(COM_NUMBER_OF_RXIPDU > 0)
/**
 * @brief			update the rx group signal value buffer
 * @param[in]		SignalGroupInvalid: Is the signal group an effective signal group
 * @param[in]		GroupSignalId: group signal identify
 * @param[in]		bufferid: The current signal corresponds to the position of the
 * 					pdu in the entire pdu array
 * @param[in]		DynSignalLength: length of signal
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
STATIC FUNC(void,COM_CODE)
Com_UpdateRxGroupSignalBuff(
	VAR(boolean, COM_VAR) SignalGroupInvalid,
	VAR(Com_SignalIdType, COM_VAR) GroupSignalId,
	VAR(uint16, COM_VAR) bufferid,
	VAR(uint16, COM_VAR) DynSignalLength
)
{
	uint16 InitValueId;

#if(COM_NUMBER_OF_8BITSIGNAL > 0u)
	uint16 PduLength;
	Com_SignalGroupIdType SignalGroupId;
	PduIdType PduId;
	uint16 cnt;
	uint16 SignalInitValueLength;
	uint16 Signal8_NLength;
	uint32 bitPosition;
#endif
	uint64 value;
	Com_SignalType SignalType;
	InitValueId = COM_CFG_RXGROUPSIGNAL(GroupSignalId).ComSignalInitValueId;
	SignalType = COM_CFG_RXGROUPSIGNAL(GroupSignalId).ComSignalType;
#if(COM_NUMBER_OF_8BITSIGNAL > 0u)
	Signal8_NLength = COM_CFG_RXGROUPSIGNAL(GroupSignalId).ComSignalLength;
	SignalInitValueLength = COM_CFG_RXGROUPSIGNAL(GroupSignalId).ComSignalDataInitValueLength;
#endif
	if((boolean)TRUE == SignalGroupInvalid)
	{
		switch(SignalType)
		{
			case COM_BOOLEAN:
#if(COM_NUMBER_OF_BOOLSIGNAL > 0u)
				Com_BoolSignalRuntimeValue[InitValueId] = Com_BoolSignalOriginalValue[InitValueId];
#endif
				break;
			case COM_UINT8:
			case COM_SINT8:
#if(COM_NUMBER_OF_8BITSIGNAL > 0u)
				Com_8BitSignalRuntimeValue[InitValueId] = Com_8BitSignalOriginalValue[InitValueId];
#endif
				break;
			case COM_UINT8_N:
#if(COM_NUMBER_OF_8BITSIGNAL > 0u)
				for(cnt = 0u;cnt < Signal8_NLength; cnt ++)
				{
					Com_8BitSignalRuntimeValue[InitValueId + cnt] = \
							Com_8BitSignalOriginalValue[InitValueId + cnt];
				}
#endif
				break;
			case COM_UINT8_DYN:
#if(COM_NUMBER_OF_8BITSIGNAL > 0u)
				for(cnt = 0u;cnt < SignalInitValueLength; cnt ++)
				{
					Com_8BitSignalRuntimeValue[InitValueId + cnt] = \
							Com_8BitSignalOriginalValue[InitValueId + cnt];
				}
				/*Initialize the length of the pdu*/
				SignalGroupId = COM_CFG_RXGROUPSIGNAL(GroupSignalId).ComSignalGroupRef;
				PduId = Com_ConfigPtr->ComRxSignalGroup[SignalGroupId].ComIpduRefIndex;
				PduLength = Com_ConfigPtr->ComRxIPdu[PduId].IPduNoDynSignalLength;
				Com_RxIPduLength[PduId].RxIpduLength = PduLength + SignalInitValueLength;
#endif
				break;
			case COM_UINT16:
			case COM_SINT16:
#if(COM_NUMBER_OF_16BITSIGNAL > 0u)
				Com_16BitSignalRuntimeValue[InitValueId] = Com_16BitSignalOriginalValue[InitValueId];
#endif
				break;
			case COM_UINT32:
			case COM_SINT32:
			case COM_FLOAT32:
#if(COM_NUMBER_OF_32BITSIGNAL > 0u)
				Com_32BitSignalRuntimeValue[InitValueId] = Com_32BitSignalOriginalValue[InitValueId];
#endif
				break;
			case COM_UINT64:
			case COM_SINT64:
			case COM_FLOAT64:
#if(COM_NUMBER_OF_64BITSIGNAL > 0u)
				Com_64BitSignalRuntimeValue[InitValueId] = Com_64BitSignalOriginalValue[InitValueId];
#endif
				break;
			default:
				break;
		}
	}
	else
	{
#if(COM_NUMBER_OF_8BITSIGNAL > 0u)
		bitPosition = COM_CFG_RXGROUPSIGNAL(GroupSignalId).ComBitPosition;
#endif
		value = Com_UnPackRxGroupSignal(GroupSignalId, bufferid);
		switch(SignalType)
		{
			case COM_BOOLEAN:
#if(COM_NUMBER_OF_BOOLSIGNAL > 0u)
				Com_BoolSignalRuntimeValue[InitValueId] = (boolean)value ;
#endif
				break;
			case COM_UINT8:
			case COM_SINT8:
#if(COM_NUMBER_OF_8BITSIGNAL > 0u)
				Com_8BitSignalRuntimeValue[InitValueId] = (uint8)value;
#endif
				break;
			case COM_UINT8_N:
#if(COM_NUMBER_OF_8BITSIGNAL > 0u)
				for(cnt =(uint16) 0;cnt < Signal8_NLength; cnt ++)
				{
					Com_8BitSignalRuntimeValue[InitValueId + cnt] = \
							Com_RxIPduRuntimeValue[bufferid + (uint16)(bitPosition/(uint32)8u) + cnt];
				}
#endif
				break;
			case COM_UINT8_DYN:
#if(COM_NUMBER_OF_8BITSIGNAL > 0u)
				for(cnt =(uint16) 0;cnt < SignalInitValueLength; cnt ++)
				{
					Com_8BitSignalRuntimeValue[InitValueId + cnt] = \
							Com_RxIPduRuntimeValue[bufferid + (uint16)(bitPosition/(uint32)8u) + cnt];
				}
#endif
				break;
			case COM_UINT16:
			case COM_SINT16:
#if(COM_NUMBER_OF_16BITSIGNAL > 0u)
				Com_16BitSignalRuntimeValue[InitValueId] = (uint16)value;
#endif
				break;
			case COM_UINT32:
			case COM_SINT32:
			case COM_FLOAT32:
#if(COM_NUMBER_OF_32BITSIGNAL > 0u)
				Com_32BitSignalRuntimeValue[InitValueId] = (uint32)value;
#endif
				break;
			case COM_UINT64:
			case COM_SINT64:
			case COM_FLOAT64:
#if(COM_NUMBER_OF_64BITSIGNAL > 0u)
				Com_64BitSignalRuntimeValue[InitValueId] = value;
#endif
				break;
			default:
				break;
		}
	}
}
#endif

/*====================================================================================================*
 *                                          GLOBAL FUNCTIONS
 *====================================================================================================*/
/**
 * @brief			This service starts Rx I-PDU.
 * @param[in]		RxPduId: Pdu identifier
 *                  initialize: flag to request initialization of the I-PDUs which are newly started
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
#if(COM_NUMBER_OF_RXIPDU > 0u)
FUNC(void , COM_CODE)
Com_RxIpduControl(
	VAR(PduIdType, COM_VAR) RxPduId,
	VAR(boolean, COM_VAR) initialize
)
{
#if(COM_NUMBER_OF_IPDUGROUP > 0u)
	Com_IpduGroupIdType refGroupNum;
	Com_IpduGroupIdType groupIdx;
	Com_IpduGroupIdType ipduGroupId;
	boolean findActiveIpduGroup =(boolean) FALSE;
	refGroupNum = COM_CFG_RXPDU(RxPduId).ComIPduGroupsRefNumber;
#endif
	/* if the Pdu not included in any Ipdu Group,the state is COM_ALWAYS start */
#if(COM_NUMBER_OF_IPDUGROUP > 0u)
	if(refGroupNum != 0u)
	{
	    for(groupIdx = 0u; (groupIdx < refGroupNum)\
	    	&&((boolean)FALSE == findActiveIpduGroup); groupIdx++)
	    {
	    	ipduGroupId = COM_CFG_RXPDU(RxPduId).ComIPduGroupsRef[groupIdx];
	    	if((boolean)TRUE == Com_IPduGroupIsActive[ipduGroupId])
	    	{
	    		findActiveIpduGroup = (boolean)TRUE;
		        if(!COM_CHECKRXPDUISENABLE(RxPduId))
		        {
		        	Com_RxIPduIsActive[RxPduId] = (boolean)TRUE;
		        	if((boolean)TRUE == initialize)
		        	{
		        		/**
		        		 * @req [SWS_Com_00222] init the rx ipdu and signal buffer(except source signal)
		        		 * @req [SWS_Com_00228]
		        		 */
		        		Com_InitRxPduAndSignalBuffer(RxPduId);
		        	}
		        }
	    	}
	    }
	    if((boolean)FALSE == findActiveIpduGroup)
	    {
	    	if(COM_CHECKRXPDUISENABLE(RxPduId))
	    	{
	    		/* @req [SWS_Com_00714] */
	    		Com_RxIPduIsActive[RxPduId] = (boolean)FALSE;
#if(COM_NUMBER_OF_TIMEOUT_SIGNAL > 0)
	    		Com_ClearRxPduDeadlineMonitorTime(RxPduId);
#endif/* COM_NUMBER_OF_RXSIGNAL+COM_NUMBER_OF_RXSIGNALGROUP > 0u */
	    	}
	    }
	}
#endif
	return;
}
#endif/* COM_IPDUGROUP_NUMBER > 0 */


#if(COM_NUMBER_OF_TIMEOUT_SIGNAL > 0u)
/**
 * @brief			Reset timeout
 * @param[in]		IpduId: Pdu identifier
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void , COM_CODE)
Com_ResetRxPduDeadlineMonitorTime(
	VAR(PduIdType, COM_VAR) IpduId
)
{
	Com_SignalIdType cnt;
	uint16 TimeIndex;
    #if(COM_NUMBER_OF_RXSIGNAL > 0u)
	Com_SignalIdType SignalRefNumber;
	Com_SignalIdType SignalId;
    #endif/* COM_NUMBER_OF_RXSIGNAL > 0u */
    #if(COM_NUMBER_OF_RXSIGNALGROUP > 0u)
	Com_SignalGroupIdType ipduSignalGroupNumber;
	Com_SignalGroupIdType SignalGroupId;
    #endif/* COM_NUMBER_OF_RXSIGNALGROUP > 0u */
    #if(COM_NUMBER_OF_RXSIGNAL > 0u)
	SignalRefNumber = Com_ConfigPtr->ComRxIPdu[IpduId].ComIPduSignalsRefNumber;
	for(cnt = 0u;cnt < SignalRefNumber;cnt++)
	{
		SignalId = Com_ConfigPtr->ComRxIPdu[IpduId].ComIPduSignalsRef[cnt];
		TimeIndex = Com_ConfigPtr->ComRxSignal[SignalId].ComTimeCntIndex;
		Com_TimeOut[TimeIndex] = Com_ConfigPtr->ComRxSignal[SignalId].ComFirstTimeout;
	}
    #endif/* (COM_NUMBER_OF_RXSIGNAL > 0u) */
    #if(COM_NUMBER_OF_RXSIGNALGROUP > 0u)
	ipduSignalGroupNumber = Com_ConfigPtr->ComRxIPdu[IpduId].ComIPduSignalGroupsRefNumber;
	for(cnt = 0u;cnt < ipduSignalGroupNumber;cnt++)
	{
		SignalGroupId = Com_ConfigPtr->ComRxIPdu[IpduId].ComIPduSignalGroupsRef[cnt];
		TimeIndex = Com_ConfigPtr->ComRxSignalGroup[SignalGroupId].ComTimeoutCntIndex;
		if(TimeIndex != 0xffu)
		{
			Com_TimeOut[TimeIndex] = Com_ConfigPtr->ComRxSignalGroup[SignalGroupId].ComFirstTimeout;
		}
	}
    #endif/*COM_NUMBER_OF_RXSIGNALGROUP > 0*/
	return;
}
#endif/* COM_NUMBER_OF_TIMEOUT_SIGNAL */

#if(COM_NUMBER_OF_TIMEOUT_SIGNAL > 0)
/**
 * @brief			Disable timeout
 * @param[in]		IpduId: Pdu identifier
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void , COM_CODE)
Com_ClearRxPduDeadlineMonitorTime(
	VAR(PduIdType, COM_VAR) PduId
)
{
	uint16 timeCntIndex;
	Com_SignalIdType cnt;
    #if(COM_NUMBER_OF_RXSIGNAL > 0)
	Com_SignalIdType SignalRefNumber;
	Com_SignalIdType SignalId;
    #endif
    #if(COM_NUMBER_OF_RXSIGNALGROUP > 0)
	Com_SignalGroupIdType SignalGroupNumber;
	Com_SignalGroupIdType SignalGroupId;
    #endif
    #if(COM_NUMBER_OF_RXSIGNAL > 0)
	SignalRefNumber = Com_ConfigPtr->ComRxIPdu[PduId].ComIPduSignalsRefNumber;
	for(cnt = 0u;cnt < SignalRefNumber;cnt++)
	{
		SignalId = Com_ConfigPtr->ComRxIPdu[PduId].ComIPduSignalsRef[cnt];
		timeCntIndex = Com_ConfigPtr->ComRxSignal[SignalId].ComTimeCntIndex;
		Com_TimeOut[timeCntIndex] =(uint16) 0;
	}
    #endif
    #if(COM_NUMBER_OF_RXSIGNALGROUP > 0)
	SignalGroupNumber = Com_ConfigPtr->ComRxIPdu[PduId].ComIPduSignalGroupsRefNumber;
	for(cnt = 0u;cnt < SignalGroupNumber;cnt++)
	{
		SignalGroupId = Com_ConfigPtr->ComRxIPdu[PduId].ComIPduSignalGroupsRef[cnt];
		timeCntIndex = Com_ConfigPtr->ComRxSignalGroup[SignalGroupId].ComTimeoutCntIndex;
		Com_TimeOut[timeCntIndex] = 0;
	}
    #endif
	return;
}
#endif/*COM_NUMBER_OF_RXSIGNALGROUP + COM_NUMBER_OF_RXSIGNAL > 0*/

#if(COM_NUMBER_OF_TIMEOUT_SIGNAL > 0)
/**
 * @brief			reset receive MD timer for all signals/signal groups(which is update) of one rx pdu
 * @param[in]		IpduId: Pdu identifier
 * 					PduInfo:Contains a pointer to a buffer to where the SDU data shall be copied
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void,COM_CODE)
Com_ResetDMTime(
	VAR(PduIdType, COM_VAR) PduId,
	P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfo
)
{
	uint16 cnt;
	uint16 index;
	uint32 updateBitPosition;
	uint8 updateBitOffset;
	#if(COM_NUMBER_OF_RXSIGNAL > 0u)
	Com_SignalIdType signalNumber;
	Com_SignalIdType signalId;
	#endif
	#if(COM_NUMBER_OF_RXSIGNALGROUP > 0u)
	Com_SignalGroupIdType signalGroupNumber;
	Com_SignalGroupIdType signalGroupId;
	#endif
#if(COM_NUMBER_OF_RXSIGNAL > 0u)
	signalNumber = COM_CFG_RXPDU(PduId).ComIPduSignalsRefNumber;
	for(cnt = 0u;cnt < signalNumber; cnt++)
	{
		signalId = COM_CFG_RXPDU(PduId).ComIPduSignalsRef[cnt];
		updateBitPosition = COM_CFG_RXSIGNAL(signalId).ComUpdateBitPosition;
		index = COM_CFG_RXSIGNAL(signalId).ComTimeCntIndex;
		if(updateBitPosition != 0xffffffffU)
		{
			updateBitOffset = (uint8)(0x01u << ((updateBitPosition) & 0x07u));
			/* update bit is 1 */
			if(updateBitOffset == ((PduInfo->SduDataPtr[updateBitPosition >> 3u]) & updateBitOffset))
			{
				Com_TimeOut[index] = COM_CFG_RXSIGNAL(signalId).ComTimeout;
			}
		}
		/* the rx signal not have update bit */
		else
		{
			Com_TimeOut[index] = COM_CFG_RXSIGNAL(signalId).ComTimeout;
		}
	}
#endif/* COM_NUMBER_OF_RXSIGNAL > 0 */
#if(COM_NUMBER_OF_RXSIGNALGROUP > 0u)
	signalGroupNumber = COM_CFG_RXPDU(PduId).ComIPduSignalGroupsRefNumber;
	for(cnt = 0u;cnt < signalGroupNumber;cnt++)
	{
		signalGroupId = COM_CFG_RXPDU(PduId).ComIPduSignalGroupsRef[cnt];
		index = COM_CFG_RXSIGNALGROUP(signalGroupId).ComTimeoutCntIndex;
		updateBitPosition = COM_CFG_RXSIGNALGROUP(signalGroupId).ComUpdateBitPosition;
		if(updateBitPosition != 0xffffffffu)
		{
			updateBitOffset = (uint8)(0x01u << ((updateBitPosition) & 0x07u));
			if(updateBitOffset == ((PduInfo->SduDataPtr[updateBitPosition >> 3u]) & updateBitOffset))
			{
				Com_TimeOut[index] = COM_CFG_RXSIGNALGROUP(signalGroupId).ComTimeout;
			}
		}
		else
		{
			Com_TimeOut[index] = COM_CFG_RXSIGNALGROUP(signalGroupId).ComTimeout;
		}
	}
    #endif/* COM_NUMBER_OF_RXSIGNALGROUP > 0 */
}
#endif/* COM_NUMBER_OF_RXSIGNAL+COM_NUMBER_OF_RXSIGNALGROUP > 0 */

#if(COM_NUMBER_OF_RXIPDU > 0)
/**
 * @brief			judge the receive pdu's counter is valid or not
 * @param[in]		IpduId: Pdu identifier
 * 					CurrentCounterValue: received counter
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(boolean,COM_CODE)
Com_CalCounterIsValid(
	VAR(PduIdType, COM_VAR) PduId,
	VAR(uint8, COM_VAR) CurrentCounterValue
)
{
	boolean counterIsValid = (boolean)FALSE;
	uint8 counterThresholdValue;
	uint8 expectedCounterValue;
	/* accept any incoming I-PDU, regardless of the value of the I-PDU counter */
	if(Com_RxIPduData[PduId].RxAnyCounterPdu != (boolean)TRUE)
	{
		/* @req [SWS_Com_00590] */
		expectedCounterValue = Com_RxIPduData[PduId].RxIpduCounter;
		counterThresholdValue = COM_CFG_RXPDU(PduId).ComIPduCounter->ComIpduCounterThreshold;
		if((CurrentCounterValue >= expectedCounterValue) \
				&& (CurrentCounterValue <= (expectedCounterValue + counterThresholdValue)) )
		{
			counterIsValid = (boolean)TRUE;
			Com_RxIPduData[PduId].RxIpduCounter = CurrentCounterValue;
			Com_GetNextCounterValue((boolean)FALSE,PduId);
		}
		if(counterIsValid == (boolean)FALSE)
		{
			/* @req [SWS_Com_00727] */
			if(COM_CFG_RXPDU(PduId).ComIPduCounter->ComIPduCounterErrorNotification != NULL_PTR)
			{
				COM_CFG_RXPDU(PduId).ComIPduCounter->ComIPduCounterErrorNotification\
									(PduId,expectedCounterValue,CurrentCounterValue);
			}
		}
	}
	else
	{
		counterIsValid = (boolean)TRUE;
		Com_RxIPduData[PduId].RxIpduCounter = CurrentCounterValue;
		Com_RxIPduData[PduId].RxAnyCounterPdu = (boolean)FALSE;
		Com_GetNextCounterValue((boolean)FALSE, PduId);
	}
	return counterIsValid;
}
#endif

#if(COM_NUMBER_OF_RXIPDU > 0)
/**
 * @brief			unpack the rx pdu data and invoke notification
 * @param[in]		PduId: Pdu identifier
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void,COM_CODE)
Com_HandlePdu(
    VAR(PduIdType, COM_VAR) PduId
)
{
	uint16 dynSignalTotalLength = 0;
	uint16 dynSignalLength = 0;
	uint16 dynGroupSignalLength = 0;
    uint16 pduBufferIdx;
    uint32 cnt = 0;
    Com_SignalIdType signalId;
    pduBufferIdx = COM_CFG_RXPDU(PduId).ComRxIPduBufIndex;
    dynSignalTotalLength = Com_RxIPduLength[PduId].RxIpduLength - COM_CFG_RXPDU(PduId).IPduNoDynSignalLength;
    for(cnt = 0; cnt < COM_CFG_RXPDU(PduId).ComIPduSignalsRefNumber; cnt++)
    {
        signalId = COM_CFG_RXPDU(PduId).ComIPduSignalsRef[cnt];
        if(COM_CFG_RXSIGNAL(signalId).ComSignalType == COM_UINT8_DYN)
        {
            dynSignalLength += COM_CFG_RXSIGNAL(signalId).ComSignalLength;
        }
    }
    dynGroupSignalLength = dynSignalTotalLength - dynSignalLength;
    Com_HandleSignalInPdu(PduId,dynSignalLength,pduBufferIdx);
    Com_HandleSignalGroupInPdu(PduId,dynGroupSignalLength,pduBufferIdx);
    return;
}
#endif

#if(COM_NUMBER_OF_RXIPDU > 0)
/**
 * @brief			Processing of pdu from the bottom
 * @param[in]		allowReceive: Whether to accept
 * @param[in]		RxPduId: Pdu identify
 * @param[in]		PduInfoPtr: A pointer variable carrying data and length
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void,COM_CODE)
Com_HandleReceivePdu(
	VAR(boolean, COM_VAR) allowReceive,
	VAR(PduIdType, COM_VAR) RxPduId
)
{
	/*If pdu is configured with the callout parameter*/
	if((boolean)TRUE == allowReceive)
	{
		/**
		 * @req [SWS_Com_00300] ComIPduSignalProcessing is IMMEDIATE, invoke the ComNotificationsfor the
		 * 						included signals and signal groups within the Com_RxIndication, or
		 * 						Com_TpRxIndication function respectively
		 */
		if(COM_IMMEDIATE == COM_CFG_RXPDU(RxPduId).ComIPduSignalProcessing)
		{
			Com_HandlePdu(RxPduId);
			/* If need a gateway */
			if((boolean)TRUE == COM_CFG_RXPDU(RxPduId).IPduGW)
			{
				Com_RxIPduNeedGw[RxPduId] =(boolean) TRUE;
			}
			else
			{
				Com_RxIPduNeedGw[RxPduId] =(boolean) FALSE;
			}
			Com_RxIPduRxIndication[RxPduId] = (boolean)FALSE;
		}
		/**
		 * @req [SWS_Com_00301] If ComIPduSignalProcessing for an I-PDU is configured to DEFFERRED,
		 * 						first copy the I-PDU's data within the Com_RxIndication function
		 */
		else
		{
			Com_RxIPduRxIndication[RxPduId] = (boolean)TRUE;
		}
	}
}
#endif

#if(COM_NUMBER_OF_RXIPDU > 0u)
/**
 * @brief			unpack the receive pdu's counter
 * @param[in]		PduId: Pdu identifier
 * @param[out]		/
 * @param[in/out]	/
 * @return			uint8
 * @retval			/
 */
FUNC(uint8,COM_CODE)
Com_UnPackCounter(
	VAR(PduIdType, COM_VAR) PduId
)
{
	uint8 counterValue;
	uint16 bufferid;
	uint32 bitPosition;
	uint8 bitSize;
	bufferid = Com_ConfigPtr->ComRxIPdu[PduId].ComRxIPduBufIndex;
	bitPosition = Com_ConfigPtr->ComRxIPdu[PduId].ComIPduCounter->ComIpduCounterStartPosition;
	bitSize = Com_ConfigPtr->ComRxIPdu[PduId].ComIPduCounter->ComIpduCounterSize;
	counterValue = Com_RxIPduRuntimeValue[bufferid + (uint16)(bitPosition/(uint32)8)];
	counterValue = counterValue << ((uint8)8 - (((uint8)bitPosition & 0x07u) + bitSize));
	counterValue = counterValue >> ((uint8)8 - bitSize);
	return counterValue;
}
#endif

/**
 * @brief			execute all configured ComDataInvalidActions for all signals and signal groups
 * @param[in]		RxIpduId: Pdu identifier
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void,COM_CODE)
Com_HandleInvalidPdu(
	VAR(PduIdType, COM_VAR) RxIpduId
)
{
	Com_SignalIdType signalNumber;
	Com_SignalGroupIdType siganlGroupNumber;
	Com_SignalIdType cnt;
#if(COM_NUMBER_OF_RXIPDU > 0)
	Com_SignalIdType counter;
    uint16 rxDynSignalLength;
    uint16 ipduBufferId;
	Com_SignalIdType groupSignalNumber;
	Com_SignalIdType groupSignalId;
	Com_SignalGroupIdType rxSignalGroupId;
#endif
    Com_SignalIdType rxSignalId;
	uint16 invalidValueId;
	signalNumber = COM_CFG_RXPDU(RxIpduId).ComIPduSignalsRefNumber;
	for(cnt = 0u;cnt < signalNumber;cnt++)
	{
		rxSignalId = COM_CFG_RXPDU(RxIpduId).ComIPduSignalsRef[cnt];
		invalidValueId = COM_CFG_RXSIGNAL(rxSignalId).ComSignalDataInvalidValueId;
	    if((uint16)0xffff != invalidValueId)
	    {
			if(COM_INVALID_ACTION_NOTIFY == COM_CFG_RXSIGNAL(rxSignalId).ComDataInvalidAction)
			{
				if(NULL_PTR != COM_CFG_RXSIGNAL(rxSignalId).ComInvalidNotification)
				{
					COM_CFG_RXSIGNAL(rxSignalId).ComInvalidNotification();
				}
			}
			else
			{
				Com_InvalidSignalReplaceAndNotification(rxSignalId);
			}
	    }
	}
	siganlGroupNumber = COM_CFG_RXPDU(RxIpduId).ComIPduSignalGroupsRefNumber;
	for(cnt = 0u;cnt < siganlGroupNumber;cnt++)
	{
#if(COM_NUMBER_OF_RXIPDU > 0)
		rxSignalGroupId = COM_CFG_RXPDU(RxIpduId).ComIPduSignalGroupsRef[cnt];
		groupSignalNumber = COM_CFG_RXSIGNALGROUP(rxSignalGroupId).ComGroupSignalNumber;
		if(COM_INVALID_ACTION_NOTIFY == COM_CFG_RXSIGNALGROUP(rxSignalGroupId).ComDataInvalidAction)
		{
			if(NULL_PTR != COM_CFG_RXSIGNALGROUP(rxSignalGroupId).ComInvalidNotification)
			{
				COM_CFG_RXSIGNALGROUP(rxSignalGroupId).ComInvalidNotification();
			}
		}
		else
		{
			ipduBufferId = COM_CFG_RXPDU(RxIpduId).ComRxIPduBufIndex;
			if((boolean)TRUE == Com_FilterRxSignalGroup(rxSignalGroupId,(boolean)TRUE,ipduBufferId))
			{
				/* update all group signal init value into group signal runtime buffer */
				for(counter = 0u;counter < groupSignalNumber;counter++)
				{
					rxDynSignalLength = Com_RxIPduLength[RxIpduId].RxIpduLength - \
							COM_CFG_RXPDU(RxIpduId).IPduNoDynSignalLength;
					groupSignalId = COM_CFG_RXSIGNALGROUP(rxSignalGroupId).ComRxGroupSignalId[counter];
					Com_UpdateRxGroupSignalBuff((boolean)TRUE,groupSignalId,\
							ipduBufferId,rxDynSignalLength);
				}
				if(NULL_PTR != COM_CFG_RXSIGNALGROUP(rxSignalGroupId).ComNotification)
				{
					COM_CFG_RXSIGNALGROUP(rxSignalGroupId).ComNotification();
				}
			}
		}
#endif
	}
	return;
}


/**
 * @brief			The main function of the receiving group signal
 * @param[in]		PduId: Pdu identifier
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
#if((COM_NUMBER_OF_RXSIGNALGROUP > 0u) && (COM_NUMBER_OF_TIMEOUT_SIGNAL > 0u))
FUNC(void , COM_CODE)
Com_RxGroupSignalMainFunction(
	VAR(PduIdType, COM_VAR) pduId
)
{
	uint16 idx;
	uint16 cnt;
	Com_SignalType signalType;
	uint16 signalLength;
	uint16 initValueId;
	Com_SignalGroupIdType refSignalGroupNum;
	Com_SignalGroupIdType signalGroupId;
	Com_SignalIdType groupSignalNum;
	Com_SignalIdType groupSignalId;
    refSignalGroupNum = COM_CFG_RXPDU(pduId).ComIPduSignalGroupsRefNumber;
	for(cnt = 0u;cnt < refSignalGroupNum; cnt ++)
	{
		/* Get the id of the signal group and the timeout index */
		signalGroupId = COM_CFG_RXPDU(pduId).ComIPduSignalGroupsRef[cnt];
		idx = COM_CFG_RXSIGNALGROUP(signalGroupId).ComTimeoutCntIndex;
		if((idx != 0xffu) && (Com_TimeOut[idx] > 0u))
		{
			if(--Com_TimeOut[idx] == 0u)
			{
				/* @req [SWS_Com_00513] */
				if(COM_TIMEOUT_ACTION_REPLACE == COM_CFG_RXSIGNALGROUP(signalGroupId).\
						ComRxDataTimeoutAction)
				{
					groupSignalNum = COM_CFG_RXPDU(pduId).ComIPduSignalGroupsRefNumber;
					for(cnt = 0;cnt < groupSignalNum; cnt ++)
					{
						groupSignalId = COM_CFG_RXPDU(pduId).ComIPduSignalGroupsRef[cnt];
						initValueId = COM_CFG_RXGROUPSIGNAL(groupSignalId).ComSignalInitValueId;
						signalType = COM_CFG_RXGROUPSIGNAL(groupSignalId).ComSignalType;
						if(signalType == COM_UINT8_N)
						{
							signalLength = Com_ConfigPtr->ComRxGroupSignal[groupSignalId].\
									ComSignalLength;
						}
						else if(signalType == COM_UINT8_DYN)
						{
							signalLength = Com_ConfigPtr->ComRxGroupSignal[groupSignalId].\
									ComSignalDataInitValueLength;
							Com_RxIPduLength[pduId].RxIpduLength = signalLength + \
									COM_CFG_RXPDU(pduId).IPduNoDynSignalLength;
						}
						else
						{
							signalLength = 0u;
						}
						Com_InitSignalBuffer(signalType, initValueId, signalLength);
					}
				}
				if(NULL_PTR != COM_CFG_RXSIGNALGROUP(signalGroupId).ComTimeoutNotification)
				{
					COM_CFG_RXSIGNALGROUP(signalGroupId).ComTimeoutNotification();
				}

			}
		}
	}
}
#endif /* #if(COM_NUMBER_OF_RXSIGNALGROUP > 0u) */

#if(COM_NUMBER_OF_RXIPDU > 0)
/**
 * @brief			Handle the received pdu counter
 * @param[in]		RxPduId: Pdu identifier
 * 					allowReceive: Is it allowed to receive this pdu
 * 					PduInfoPtr: Contains the length (SduLength) of the received I-PDU and a pointer to
 *                  a buffer (SduDataPtr) containing the I-PDU.
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void, COM_CODE)
Com_HandleRxPduCounter(
	VAR(PduIdType, COM_VAR) RxPduId,
	boolean* allowReceive,
	P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
)
{

    uint8 counterValue;
    uint8 bitSize;
    PduLengthType cnt;
    PduIdType pduBufferIdx;
    uint32 bitPosition;
    pduBufferIdx = COM_CFG_RXPDU(RxPduId).ComRxIPduBufIndex;
	if(NULL_PTR == COM_CFG_RXPDU(RxPduId).ComIPduCounter)
	{
		*allowReceive = (boolean)TRUE;
		/*Copy the received pdu data to the buffer*/
		for(cnt= 0u; cnt < PduInfoPtr->SduLength; cnt++)
		{
			Com_RxIPduRuntimeValue[pduBufferIdx + cnt] = PduInfoPtr->SduDataPtr[cnt];
		}
		Com_RxIPduLength[RxPduId].RxIpduLength = \
				(uint16)PduInfoPtr->SduLength - COM_CFG_RXPDU(RxPduId).MetaDataLength;
	}
	else
	{
		bitPosition = COM_CFG_RXPDU(RxPduId).ComIPduCounter->ComIpduCounterStartPosition;
		bitSize = COM_CFG_RXPDU(RxPduId).ComIPduCounter->ComIpduCounterSize;
		/**
		 * @req [SWS_Com_00588] At reception of an I-PDU containing an I-PDU counter, set the
		 * 						next expected value to the value following the received value
		 * 						with respect to counter wrap-around
		 */
		counterValue = PduInfoPtr->SduDataPtr[(uint16)(bitPosition  >> 3u)];
		counterValue = counterValue << (8u - (((uint8)bitPosition & 0x07u) + bitSize));
		counterValue = counterValue >> (8u - bitSize);
		*allowReceive = (boolean)Com_CalCounterIsValid(RxPduId, counterValue);
		if((boolean)TRUE == *allowReceive)
		{
			for(cnt=(PduLengthType)0; cnt < PduInfoPtr->SduLength; cnt++)
			{
				Com_RxIPduRuntimeValue[pduBufferIdx + cnt] = PduInfoPtr->SduDataPtr[cnt];
			}
			Com_RxIPduLength[RxPduId].RxIpduLength = \
					(uint16)PduInfoPtr->SduLength - COM_CFG_RXPDU(RxPduId).MetaDataLength;
		}
	}
}
#endif

#if((COM_NUMBER_OF_RXSIGNAL > 0u) && (COM_NUMBER_OF_TIMEOUT_SIGNAL > 0u))
/**
 * @brief			Processing received pdu deadline monitoring time
 * @param[in]		RxPduId: Pdu identifier
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void, COM_CODE)
Com_HandleReceiveDm(
	VAR(PduIdType, COM_VAR) RxPduId
)
{
	uint16 idx;
	uint16 cnt;
	uint16 signalNum;
	uint16 initValueId;
	uint16 signalLength;
    Com_SignalIdType signalId;
    Com_SignalType signalType;
#if(COM_NUMBER_OF_MASKNEWDIFFERMASKOLD_SIGNAL > 0u)
    Com_SignalIdType maskNewDifferMaskOldId;
#endif/* COM_NUMBER_OF_MASKNEWDIFFERMASKOLD_SIGNAL > 0u */
    signalNum = COM_CFG_RXPDU(RxPduId).ComIPduSignalsRefNumber;
	for(cnt = 0u; cnt < signalNum;cnt ++)
	{
		signalId = COM_CFG_RXPDU(RxPduId).ComIPduSignalsRef[cnt];
		idx = COM_CFG_RXSIGNAL(signalId).ComTimeCntIndex;
		if(Com_TimeOut[idx] > 0u)
		{
			Com_TimeOut[idx]--;
			if(0u == Com_TimeOut[idx])
			{
#if(COM_NUMBER_OF_MASKNEWDIFFERMASKOLD_SIGNAL > 0u)
				if((NULL_PTR != COM_CFG_RXSIGNAL(signalId).ComFilter)
				   && (COM_MASKED_NEW_DIFFERS_MASKED_OLD == \
						   COM_CFG_RXSIGNAL(signalId).ComFilter->ComFilterAlgorithm))
				{
					maskNewDifferMaskOldId = \
						COM_CFG_RXSIGNAL(signalId).ComFilter->ComMaskNewDifferMaskOldId;
					Com_MaskNewDifferMaskOldTimeOut[maskNewDifferMaskOldId] = \
							(boolean)TRUE;
				}
#endif/* (COM_NUMBER_OF_MASKNEWDIFFERMASKOLD_SIGNAL > 0) */
				/**
				 * @req [SWS_Com_00470]
				 * @req [SWS_Com_00500]
				 * @req [SWS_Com_00513] ComRxDataTimeoutAction set to REPLACE , replace
				 * 						the signal's value by its ComSignalInitValue
				 */
				if(COM_TIMEOUT_ACTION_REPLACE == COM_CFG_RXSIGNAL(signalId).\
						ComRxDataTimeoutAction)
				{
					initValueId = COM_CFG_RXSIGNAL(signalId).ComSignalInitValueId;
					signalType = COM_CFG_RXSIGNAL(signalId).ComSignalType;
					if(signalType == COM_UINT8_N)
					{
						signalLength = COM_CFG_RXSIGNAL(signalId).ComSignalLength;
					}
					else if(signalType == COM_UINT8_DYN)
					{
#if(COM_NUMBER_OF_RXIPDU > 0)
						signalLength = COM_CFG_RXSIGNAL(signalId).\
								ComSignalDataInvalidValueLength;
						Com_RxIPduLength[RxPduId].RxIpduLength = signalLength + \
								COM_CFG_RXPDU(RxPduId).IPduNoDynSignalLength;
#endif
					}
					else
					{
						signalLength = 0u;
					}
					Com_InitSignalBuffer(signalType, initValueId, signalLength);
				}
				if(NULL_PTR != COM_CFG_RXSIGNAL(signalId).ComTimeoutNotification)
				{
					COM_CFG_RXSIGNAL(signalId).ComTimeoutNotification();
				}
			}
		}
	}
}
#endif

#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

