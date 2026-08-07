/**
 * @file       	Com_GwInternal.c
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

/* PRQA S 0292, 0288, 1503, 1505, 0857, 0791, 0828, 0647, 0491 EOF #
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
#define COM_GWINTERNAL_VENDOR_ID_C 							0U
#define COM_GWINTERNAL_AR_RELEASE_MAJOR_VERSION_C  			4U
#define COM_GWINTERNAL_AR_RELEASE_MINOR_VERSION_C  			2U
#define COM_GWINTERNAL_AR_RELEASE_REVISION_VERSION_C		2U
#define COM_GWINTERNAL_SW_MAJOR_VERSION_C					1U
#define COM_GWINTERNAL_SW_MINOR_VERSION_C					2U
#define COM_GWINTERNAL_SW_PATCH_VERSION_C					0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Com_Internal.h header file are of the same vendor */
#if(COM_GWINTERNAL_VENDOR_ID_C != COM_INTERNAL_VENDOR_ID )
#error "Com_GwInternal.c and Com_Internal.h have different vendor id"
#endif

#if(\
      (COM_GWINTERNAL_AR_RELEASE_MAJOR_VERSION_C != COM_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
      (COM_GWINTERNAL_AR_RELEASE_MINOR_VERSION_C != COM_INTERNAL_AR_RELEASE_MINOR_VERSION) || \
      (COM_GWINTERNAL_AR_RELEASE_REVISION_VERSION_C != COM_INTERNAL_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of Com_GwInternal.c and Com_Internal.h are different "
#endif

/* Check if current file and Com_Internal.h header file are of the same software version */
#if(\
      (COM_GWINTERNAL_SW_MAJOR_VERSION_C != COM_INTERNAL_SW_MAJOR_VERSION) || \
      (COM_GWINTERNAL_SW_MINOR_VERSION_C != COM_INTERNAL_SW_MINOR_VERSION) ||\
	  (COM_GWINTERNAL_SW_PATCH_VERSION_C != COM_INTERNAL_SW_PATCH_VERSION)\
      )
#error "Software Version Number of Com_GwInternal.c and Com_Internal.h are different "
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

STATIC FUNC(void,COM_CODE)
Com_HanldeGwSignal(
	VAR(Com_SignalType ,COM_VAR) SignalType,
	VAR(uint16 ,COM_VAR) GWSignalBufferId,
	VAR(Com_GWSignalType ,COM_VAR) DestSignalType,
	VAR(Com_SignalIdType ,COM_VAR) DestSignalId
);

STATIC FUNC(void,COM_CODE)
Com_Hanldel8_NGwSignal(
	VAR(uint16 ,COM_VAR) SignalBufferId,
	VAR(uint16 ,COM_VAR) SignalLength,
	VAR(Com_GWSignalType ,COM_VAR) DestSignalType,
	VAR(Com_SignalIdType ,COM_VAR) DestSignalId
);

#if(COM_NUMBER_OF_RXIPDU > 0)
STATIC FUNC(void,COM_CODE)
Com_HandleDynGwSignal(
	VAR(uint16 ,COM_VAR) SignalBufferId,
	VAR(uint16 ,COM_VAR) SignalLength,
	VAR(Com_GWSignalType ,COM_VAR) DestSignalType,
	VAR(Com_SignalIdType ,COM_VAR) DestSignalId
);
#endif

STATIC FUNC(void,COM_CODE)
Com_PackDestSignal(
	VAR(Com_GWSignalType ,COM_VAR) DestSignalType,
	VAR(Com_SignalIdType ,COM_VAR) DestSignalId,
	P2CONST(uint64, AUTOMATIC, COM_APPL_CONST)SignalValuePtr
);

#if(COM_TMCTXSIGNAL_NUMBER > 0u)
STATIC FUNC(boolean,COM_CODE)
Com_CalDestSignalTMC
(
	VAR(Com_SignalType ,COM_VAR) SignalType,
	P2CONST(Com_FilterType, AUTOMATIC, COM_APPL_CONST)ComFilter,
	P2CONST(uint64, AUTOMATIC, COM_APPL_CONST)NewSignalValuePtr,
	P2CONST(uint64, AUTOMATIC, COM_APPL_CONST)OldSignalValuePtr
);
#endif

STATIC FUNC(void,COM_CODE)
Com_HandleGwSignalOfPdu(
	VAR(PduIdType ,COM_VAR) PduId,
	VAR(Com_TransferPropertyType, COM_VAR) SignalProperty,
	VAR(uint16 ,COM_VAR) RptNum,
	VAR(boolean, COM_VAR) ValueChanged
);

STATIC FUNC(void,COM_CODE)
Com_HandleGwGroupSignalOfPdu(
	VAR(PduIdType ,COM_VAR) PduId,
	VAR(Com_TransferPropertyType, COM_VAR) SignalGroupProperty,
	VAR(Com_SignalIdType ,COM_VAR) GroupSignalId,
	VAR(uint16 ,COM_VAR) RptNum,
	VAR(boolean, COM_VAR) ValueChanged
);

#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
/*====================================================================================================*
 *                                           LOCAL FUNCTIONS
 *====================================================================================================*/
#define COM_START_SEC_CODE
#include "Com_MemMap.h"

/**
 * @brief			gateway signal/group signal/description signal which signal type isn't COM_UINT8_N
 * 					and COM_UINT8_DYN
 * @param[in]		SignalType: type of signal
 * @param[in]		GWSignalBufferId: The current signal is located in the entire array of signals
 * @param[in]		DestSignalType: type of signal
 * @param[in]		DestSignalId: signal identify
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 * @req [SWS_Com_00466] evaluate the transfer properties and transmission modes and perform its routing
 * 						actions in the following sequence, see also Figure 3:
						1. copy all gated signals from the source to the target I-PDUs
						2. evaluate the TMC of all gated signals
						3. evaluate the TMS for the target I-PDUs
 */
STATIC FUNC(void,COM_CODE)
Com_HanldeGwSignal(
	VAR(Com_SignalType ,COM_VAR) SignalType,
	VAR(uint16 ,COM_VAR) GWSignalBufferId,
	VAR(Com_GWSignalType ,COM_VAR) DestSignalType,
	VAR(Com_SignalIdType ,COM_VAR) DestSignalId
)
{
	boolean valueIsChanged = (boolean)FALSE;
	uint64 sourceSignalValue = 0u;
	uint64 destSignalValue = 0u;
	PduIdType pduId = 0u;
#if(((COM_LENGTH_OF_GWBOOLSIGNALBUFFER > 0u) && (COM_NUMBER_OF_BOOLSIGNAL > 0u)) || \
		((COM_LENGTH_OF_GW8BITSIGNALBUFFER > 0u) && (COM_NUMBER_OF_8BITSIGNAL > 0u)) || \
		((COM_LENGTH_OF_GW16BITSIGNALBUFFER > 0u) && (COM_NUMBER_OF_16BITSIGNAL > 0u)) || \
		((COM_LENGTH_OF_GW32BITSIGNALBUFFER > 0u) && (COM_NUMBER_OF_32BITSIGNAL > 0u)) || \
		((COM_LENGTH_OF_GW64BITSIGNALBUFFER > 0u) && (COM_NUMBER_OF_64BITSIGNAL > 0u)))
	uint16 initValueId = 0u;
#endif
#if(COM_NUMBER_OF_TXIPDU)
	uint16 pduBufferIndex;
#endif
	uint32 updateBitPosition = 0xffffffffu;
	Com_TransferPropertyType signalProperty;
	Com_TransferPropertyType signalGroupProperty;
	P2CONST(Com_FilterType, AUTOMATIC, COM_APPL_CONST)comFilter = NULL_PTR;
	uint16 rptNum = 0u;
	Com_SignalGroupIdType signalGroupId;
	if(DestSignalType == COM_SIGNAL)
	{
#if(((COM_LENGTH_OF_GWBOOLSIGNALBUFFER > 0u) && (COM_NUMBER_OF_BOOLSIGNAL > 0u)) || \
		((COM_LENGTH_OF_GW8BITSIGNALBUFFER > 0u) && (COM_NUMBER_OF_8BITSIGNAL > 0u)) || \
		((COM_LENGTH_OF_GW16BITSIGNALBUFFER > 0u) && (COM_NUMBER_OF_16BITSIGNAL > 0u)) || \
		((COM_LENGTH_OF_GW32BITSIGNALBUFFER > 0u) && (COM_NUMBER_OF_32BITSIGNAL > 0u)) || \
		((COM_LENGTH_OF_GW64BITSIGNALBUFFER > 0u) && (COM_NUMBER_OF_64BITSIGNAL > 0u)))
		initValueId = COM_CFG_TXSIGNAL(DestSignalId).ComSignalInitValueId;
#endif
		pduId = COM_CFG_TXSIGNAL(DestSignalId).ComIpduRefIndex;
		updateBitPosition = COM_CFG_TXSIGNAL(DestSignalId).ComUpdateBitPosition;
		signalProperty = COM_CFG_TXSIGNAL(DestSignalId).ComTransferProperty;
		comFilter = COM_CFG_TXSIGNAL(DestSignalId).ComFilter;
	}
	else if(DestSignalType == COM_GROUP_SIGNAL)
	{
#if(((COM_LENGTH_OF_GWBOOLSIGNALBUFFER > 0u) && (COM_NUMBER_OF_BOOLSIGNAL > 0u)) || \
		((COM_LENGTH_OF_GW8BITSIGNALBUFFER > 0u) && (COM_NUMBER_OF_8BITSIGNAL > 0u)) || \
		((COM_LENGTH_OF_GW16BITSIGNALBUFFER > 0u) && (COM_NUMBER_OF_16BITSIGNAL > 0u)) || \
		((COM_LENGTH_OF_GW32BITSIGNALBUFFER > 0u) && (COM_NUMBER_OF_32BITSIGNAL > 0u)) || \
		((COM_LENGTH_OF_GW64BITSIGNALBUFFER > 0u) && (COM_NUMBER_OF_64BITSIGNAL > 0u)))
		initValueId = COM_CFG_TXGROUPSIGNAL(DestSignalId).ComSignalInitValueId;
#endif
		signalGroupId = COM_CFG_TXGROUPSIGNAL(DestSignalId).ComSignalGroupRef;
		pduId = COM_CFG_TXSIGNALGROUP(signalGroupId).ComIpduRefIndex;
		updateBitPosition = COM_CFG_TXSIGNALGROUP(signalGroupId).ComUpdateBitPosition;
		signalGroupProperty = Com_ConfigPtr->ComTxSignalGroup[DestSignalId].ComTransferProperty;
		comFilter = COM_CFG_TXGROUPSIGNAL(DestSignalId).ComFilter;
	}
	else
	{
		/* do nothing */
	}
	if(SignalType == COM_BOOLEAN)
	{
#if((COM_LENGTH_OF_GWBOOLSIGNALBUFFER > 0u) && (COM_NUMBER_OF_BOOLSIGNAL > 0u))
		sourceSignalValue = (uint64)Com_GWBoolSignalBuff[GWSignalBufferId];
		destSignalValue = (uint64)Com_BoolSignalRuntimeValue[initValueId];
		Com_BoolSignalRuntimeValue[initValueId] = Com_GWBoolSignalBuff[GWSignalBufferId];
#endif
	}
	else if((SignalType == COM_UINT8) || (SignalType == COM_SINT8))
	{
#if((COM_LENGTH_OF_GW8BITSIGNALBUFFER > 0u) && (COM_NUMBER_OF_8BITSIGNAL > 0u))
		sourceSignalValue = (uint64)Com_GW8BitSignalBuff[GWSignalBufferId];
		destSignalValue = (uint64)Com_8BitSignalRuntimeValue[initValueId];
		Com_8BitSignalRuntimeValue[initValueId] = Com_GW8BitSignalBuff[GWSignalBufferId];
#endif
	}
	else if((SignalType == COM_UINT16) || (SignalType == COM_SINT16))
	{
#if((COM_LENGTH_OF_GW16BITSIGNALBUFFER > 0u) && (COM_NUMBER_OF_16BITSIGNAL > 0u))
		sourceSignalValue = (uint64)Com_GW16BitSignalBuff[GWSignalBufferId];
		destSignalValue = (uint64)Com_16BitSignalRuntimeValue[initValueId];
		Com_16BitSignalRuntimeValue[initValueId] = Com_GW16BitSignalBuff[GWSignalBufferId];
#endif
	}
	else if((SignalType == COM_UINT32) || (SignalType == COM_SINT32) || (SignalType == COM_FLOAT32))
	{
#if((COM_LENGTH_OF_GW32BITSIGNALBUFFER > 0u) && (COM_NUMBER_OF_32BITSIGNAL > 0u))
		sourceSignalValue = (uint64)Com_GW32BitSignalBuff[GWSignalBufferId];
		destSignalValue = (uint64)Com_32BitSignalRuntimeValue[initValueId];
		Com_32BitSignalRuntimeValue[initValueId] = Com_GW32BitSignalBuff[GWSignalBufferId];
#endif
	}
	else if((SignalType == COM_UINT64) || (SignalType == COM_SINT64) || (SignalType == COM_FLOAT64))
	{
#if((COM_LENGTH_OF_GW64BITSIGNALBUFFER > 0u) && (COM_NUMBER_OF_64BITSIGNAL > 0u))
		sourceSignalValue = Com_GW64BitSignalBuff[GWSignalBufferId];
		destSignalValue = Com_64BitSignalRuntimeValue[initValueId];
		Com_64BitSignalRuntimeValue[initValueId] = Com_GW64BitSignalBuff[GWSignalBufferId];
#endif
	}
	else
	{
		/* do nothing */
	}
	if(sourceSignalValue != destSignalValue)
	{
		valueIsChanged = (boolean)TRUE;
		Com_PackDestSignal(DestSignalType,DestSignalId,&sourceSignalValue);
	}
    if(updateBitPosition != 0xffffffffu)
    {
#if(COM_NUMBER_OF_TXIPDU)
    	pduBufferIndex = Com_ConfigPtr->ComTxIPdu[pduId].ComTxIPduBufIndex;
    	Com_TxIPduRuntimeValue[pduBufferIndex + (uint16)(updateBitPosition >> 3u)] |= \
    			(uint8)(0x01u << (((uint8)updateBitPosition) & 0x07u));
#endif
    }
	if(NULL_PTR != comFilter)
	{
#if(COM_TMCTXSIGNAL_NUMBER > 0u)
		TxSignalTMCRunTime[comFilter->ComTMCBufferId] = \
				Com_CalDestSignalTMC(SignalType,comFilter,&sourceSignalValue,&destSignalValue);
#endif
	}
	Com_HandleTxIpduTMS(pduId,&rptNum);
	if(DestSignalType == COM_SIGNAL)
	{
		Com_HandleGwSignalOfPdu(pduId,signalProperty,rptNum,valueIsChanged);
#if(COM_NUMBER_OF_TXIPDU > 0)
    	if((uint16)0 != COM_CFG_TXSIGNAL(DestSignalId).ComTimeout)
    	{
    		if(((uint16)0 == Com_TxIPduDMTime[pduId]) \
    				|| ((uint16)1 < Com_TxIPduRepeatNum[pduId]))
    		{
    			Com_TxIPduDMTime[pduId] = Com_ConfigPtr->ComTxIPdu[pduId].ComTxIpduDM;
    		}
    	}
#endif
	}
	else if(DestSignalType == COM_GROUP_SIGNAL)
	{
		Com_HandleGwGroupSignalOfPdu(pduId,signalGroupProperty,DestSignalId,rptNum,valueIsChanged);
#if(COM_NUMBER_OF_TXIPDU > 0)
    	if((uint16)0 != COM_CFG_TXSIGNALGROUP(signalGroupId).ComTimeout)
    	{
    		if(((uint16)0 == Com_TxIPduDMTime[pduId]) \
    				|| ((uint16)1 < Com_TxIPduRepeatNum[pduId]))
    		{
    			Com_TxIPduDMTime[pduId] = Com_ConfigPtr->ComTxIPdu[pduId].ComTxIpduDM;
    		}
    	}
#endif
	}
	else
	{
		/* do nothing */
	}
	return;
}


/**
 * @brief			gateway signal/group signal/description signal which signal type is COM_UINT8_N
 * @param[in]		SignalBufferId: The current signal is located in the entire array of signals
 * @param[in]		SignalLength: length of signal
 * @param[in]		DestSignalType: type of signal
 * @param[in]		DestSignalId: signal identify
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
STATIC FUNC(void,COM_CODE)
Com_Hanldel8_NGwSignal(
	VAR(uint16 ,COM_VAR) SignalBufferId,
	VAR(uint16 ,COM_VAR) SignalLength,
	VAR(Com_GWSignalType ,COM_VAR) DestSignalType,
	VAR(Com_SignalIdType ,COM_VAR) DestSignalId
)
{
	boolean valueIsChanged = (boolean)FALSE;
	uint16 cnt;
	PduIdType pduId;
#if(COM_LENGTH_OF_GW8BITSIGNALBUFFER > 0u)
	uint16 pduBufferId;
	uint32 bitPosition;
#endif
	uint32 updateBitPosition;
#if(COM_NUMBER_OF_TXIPDU)
	uint16 pduBufferIndex;
#endif
	Com_TransferPropertyType signalProperty;
	Com_TransferPropertyType signalGroupProperty;
	uint16 rptNum;
	Com_SignalGroupIdType signalGroupId;
	switch(DestSignalType)
	{
		case COM_SIGNAL:
			pduId = Com_ConfigPtr->ComTxSignal[DestSignalId].ComIpduRefIndex;
#if(COM_LENGTH_OF_GW8BITSIGNALBUFFER > 0u)
			bitPosition = Com_ConfigPtr->ComTxSignal[DestSignalId].ComBitPosition;
			pduBufferId = Com_ConfigPtr->ComTxIPdu[pduId].ComTxIPduBufIndex;
#endif
			updateBitPosition = Com_ConfigPtr->ComTxSignal[DestSignalId].ComUpdateBitPosition;
			for(cnt =(uint16) 0 ;cnt < SignalLength; cnt ++)
			{
#if(COM_LENGTH_OF_GW8BITSIGNALBUFFER > 0u)
				if((Com_TxIPduRuntimeValue[pduBufferId + (uint16)(bitPosition  >> 3u) + cnt ]) \
						!= (Com_GW8BitSignalBuff[SignalBufferId + cnt]))
				{
					valueIsChanged =(boolean) TRUE;
					Com_TxIPduRuntimeValue[pduBufferId + (uint16)(bitPosition  >> 3u) + cnt ]  =\
							Com_GW8BitSignalBuff[SignalBufferId + cnt];
				}
#endif
			}
		    if(0xffffffffu != updateBitPosition)
		    {
#if(COM_NUMBER_OF_TXIPDU)
		    	pduBufferIndex = Com_ConfigPtr->ComTxIPdu[pduId].ComTxIPduBufIndex;
		    	Com_TxIPduRuntimeValue[pduBufferIndex + (uint16)(updateBitPosition >> 3u)] |= \
		    			(uint8)(0x01u << (((uint8)updateBitPosition) & 0x07u));
#endif
		    }
			Com_HandleTxIpduTMS(pduId,&rptNum);
			signalProperty = Com_ConfigPtr->ComTxSignal[DestSignalId].ComTransferProperty;
			Com_HandleGwSignalOfPdu(pduId,signalProperty,rptNum,valueIsChanged);
#if(COM_NUMBER_OF_TXIPDU > 0)
	    	if(Com_ConfigPtr->ComTxSignal[DestSignalId].ComTimeout != 0u)
	    	{
	    		if((0u == Com_TxIPduDMTime[pduId]) \
	    				|| (1u < Com_TxIPduRepeatNum[pduId]))
	    		{
	    			Com_TxIPduDMTime[pduId] = Com_ConfigPtr->ComTxIPdu[pduId].ComTxIpduDM;
	    		}
	    	}
#endif
			break;
		case COM_GROUP_SIGNAL:
			signalGroupId = Com_ConfigPtr->ComTxGroupSignal[DestSignalId].ComSignalGroupRef;
			pduId = Com_ConfigPtr->ComTxSignalGroup[signalGroupId].ComIpduRefIndex;
#if(COM_LENGTH_OF_GW8BITSIGNALBUFFER > 0u)
			bitPosition = Com_ConfigPtr->ComTxGroupSignal[DestSignalId].ComBitPosition;
			pduBufferId = Com_ConfigPtr->ComTxIPdu[pduId].ComTxIPduBufIndex;
#endif
			updateBitPosition = Com_ConfigPtr->ComTxSignalGroup[signalGroupId].ComUpdateBitPosition;

			for(cnt = (uint16)0 ;cnt < SignalLength; cnt ++)
			{
#if(COM_LENGTH_OF_GW8BITSIGNALBUFFER > 0u)
				if((Com_TxIPduRuntimeValue[pduBufferId + (uint16)(bitPosition  >> 3u) + cnt ]) \
						!= (Com_GW8BitSignalBuff[SignalBufferId + cnt]))
				{
					valueIsChanged =(boolean)  TRUE;
					Com_TxIPduRuntimeValue[pduBufferId + (uint16)(bitPosition  >> 3u) + cnt ] =\
							Com_GW8BitSignalBuff[SignalBufferId + cnt];
				}
#endif
			}
		    if(0xffffffffu != updateBitPosition)
		    {
#if(COM_NUMBER_OF_TXIPDU)
		    	pduBufferIndex = Com_ConfigPtr->ComTxIPdu[pduId].ComTxIPduBufIndex;
		    	Com_TxIPduRuntimeValue[pduBufferIndex + (uint16)(updateBitPosition >> 3u)] |= \
		    			(uint8)(0x01u << (((uint8)updateBitPosition) & 0x07u));
#endif
		    }
			Com_HandleTxIpduTMS(pduId,&rptNum);
			signalGroupProperty = Com_ConfigPtr->ComTxSignalGroup[signalGroupId].ComTransferProperty;
			Com_HandleGwGroupSignalOfPdu(pduId,signalGroupProperty,DestSignalId,rptNum,valueIsChanged);
#if(COM_NUMBER_OF_TXIPDU > 0)
			if(Com_ConfigPtr->ComTxSignalGroup[DestSignalId].ComTimeout != 0u)
			{
				if(((uint16)0 == Com_TxIPduDMTime[pduId]) \
						|| (1u < Com_TxIPduRepeatNum[pduId]))
				{
					Com_TxIPduDMTime[pduId] = Com_ConfigPtr->ComTxIPdu[pduId].ComTxIpduDM;
				}
			}
#endif
			break;
		default:
			break;
	}
}

#if(COM_NUMBER_OF_RXIPDU > 0)
/**
 * @brief			gateway signal/group signal/description signal which signal type is COM_UINT8_DYN
 * @param[in]		SignalBufferId: The current signal is located in the entire array of signals
 * @param[in]		SignalLength: length of signal
 * @param[in]		DestSignalType: type of signal
 * @param[in]		DestSignalId: signal identify
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
STATIC FUNC(void,COM_CODE)
Com_HandleDynGwSignal(
	VAR(uint16 ,COM_VAR) SignalBufferId,
	VAR(uint16 ,COM_VAR) SignalLength,
	VAR(Com_GWSignalType ,COM_VAR) DestSignalType,
	VAR(Com_SignalIdType ,COM_VAR) DestSignalId
)
{
#if(COM_NUMBER_OF_TXIPDU > 0)
	boolean valueIsChanged = (boolean)FALSE;
	uint16 cnt;
	uint16 pduId;
#if(COM_LENGTH_OF_GW8BITSIGNALBUFFER > 0u)
	uint16 pduBufferId;
	uint32 bitPosition;
#endif
	uint32 updateBitPosition;
	uint16 pduBufferIndex;
	Com_TransferPropertyType signalProperty;
	Com_TransferPropertyType signalGroupProperty;
	uint16 rptNum;
	Com_SignalGroupIdType signalGroupId;
#endif
	switch(DestSignalType)
	{
	    case COM_SIGNAL:
#if(COM_NUMBER_OF_TXIPDU > 0)
	    	pduId = Com_ConfigPtr->ComTxSignal[DestSignalId].ComIpduRefIndex;
#if(COM_LENGTH_OF_GW8BITSIGNALBUFFER > 0u)
	    	bitPosition = Com_ConfigPtr->ComTxSignal[DestSignalId].ComBitPosition;
	    	pduBufferId = Com_ConfigPtr->ComTxIPdu[pduId].ComTxIPduBufIndex;
#endif
	    	updateBitPosition = Com_ConfigPtr->ComTxSignal[DestSignalId].ComUpdateBitPosition;
	    	for(cnt =(uint16) 0;cnt < SignalLength;cnt++)
	    	{
#if(COM_LENGTH_OF_GW8BITSIGNALBUFFER > 0u)
	    		if((Com_TxIPduRuntimeValue[pduBufferId + (uint16)(bitPosition >> 3u) + cnt] ) \
						!= (Com_GW8BitSignalBuff[SignalBufferId + cnt]))
				{
					valueIsChanged = (boolean)TRUE;
					Com_TxIPduRuntimeValue[pduBufferId + (uint16)(bitPosition >> 3u) + cnt] \
					= Com_GW8BitSignalBuff[SignalBufferId + cnt];
				}
#endif
	    	}
		    if(0xffffffffu != updateBitPosition)
		    {
		    	pduBufferIndex = Com_ConfigPtr->ComTxIPdu[pduId].ComTxIPduBufIndex;
		    	Com_TxIPduRuntimeValue[pduBufferIndex + (uint16)(updateBitPosition >> 3u)] |= \
		    			(uint8)(0x01u << (((uint8)updateBitPosition) & 0x07u));
		    }
	    	Com_HandleTxIpduTMS(pduId,&rptNum);
	    	signalProperty = Com_ConfigPtr->ComTxSignal[DestSignalId].ComTransferProperty;
	    	Com_HandleGwSignalOfPdu(pduId,signalProperty,rptNum,valueIsChanged);
	    	if((uint16)0 != Com_ConfigPtr->ComTxSignal[DestSignalId].ComTimeout)
	    	{
	    		if(((uint16)0 == Com_TxIPduDMTime[pduId]) \
	    				|| (1u < Com_TxIPduRepeatNum[pduId]))
	    		{
	    			Com_TxIPduDMTime[pduId] = Com_ConfigPtr->ComTxIPdu[pduId].ComTxIpduDM;
	    		}
	    	}
#endif
	    	break;
	    case COM_GROUP_SIGNAL:
#if(COM_NUMBER_OF_TXIPDU > 0)
	    	signalGroupId = Com_ConfigPtr->ComTxGroupSignal[DestSignalId].ComSignalGroupRef;
	    	pduId = Com_ConfigPtr->ComTxSignalGroup[signalGroupId].ComIpduRefIndex;
#if(COM_LENGTH_OF_GW8BITSIGNALBUFFER > 0u)
	    	bitPosition = Com_ConfigPtr->ComTxGroupSignal[DestSignalId].ComBitPosition;
	    	pduBufferId = Com_ConfigPtr->ComTxIPdu[pduId].ComTxIPduBufIndex;
#endif
	    	updateBitPosition = Com_ConfigPtr->ComTxSignalGroup[signalGroupId].ComUpdateBitPosition;
	    	for(cnt =(uint16) 0;cnt < SignalLength;cnt++)
	    	{
#if(COM_LENGTH_OF_GW8BITSIGNALBUFFER > 0u)
	    		if((Com_TxIPduRuntimeValue[pduBufferId + (uint16)(bitPosition >> 3u) + cnt] ) \
						!= (Com_GW8BitSignalBuff[SignalBufferId + cnt]))
				{
					valueIsChanged = (boolean)TRUE;
					Com_TxIPduRuntimeValue[pduBufferId + (uint16)(bitPosition >> 3u) + cnt] \
					= Com_GW8BitSignalBuff[SignalBufferId + cnt];
				}
#endif
	    	}
		    if(0xffffffffu != updateBitPosition)
		    {
		    	pduBufferIndex = Com_ConfigPtr->ComTxIPdu[pduId].ComTxIPduBufIndex;
		    	Com_TxIPduRuntimeValue[pduBufferIndex + (uint16)(updateBitPosition >> 3u)] |= \
		    			(uint8)(0x01u << (((uint8)updateBitPosition) & 0x07u));
		    }
	    	Com_HandleTxIpduTMS(pduId,&rptNum);
	    	signalGroupProperty = Com_ConfigPtr->ComTxSignalGroup[signalGroupId].ComTransferProperty;
	    	Com_HandleGwGroupSignalOfPdu(pduId,signalGroupProperty,DestSignalId,rptNum,valueIsChanged);
	    	if((uint16)0 != Com_ConfigPtr->ComTxSignalGroup[signalGroupId].ComTimeout)
	    	{
	    		if(((uint16)0 == Com_TxIPduDMTime[pduId]) \
	    				|| (1u < Com_TxIPduRepeatNum[pduId]))
	    		{
	    			Com_TxIPduDMTime[pduId] = Com_ConfigPtr->ComTxIPdu[pduId].ComTxIpduDM;
	    		}
	    	}
#endif
	    	break;
	    default:
	    	break;
	}
    return;
}
#endif


/**
 * @brief			gateway dest signal is packed to dest tx pdu buffer
 * @param[in]		DestSignalType: type of signal
 * @param[in]		DestSignalId: signal identify
 * @param[in]		SignalValuePtr: value of signal
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
STATIC FUNC(void,COM_CODE)
Com_PackDestSignal(
	VAR(Com_GWSignalType ,COM_VAR) DestSignalType,
	VAR(Com_SignalIdType ,COM_VAR) DestSignalId,
	P2CONST(uint64, AUTOMATIC, COM_APPL_CONST)SignalValuePtr
)
{
#if(COM_NUMBER_OF_TXIPDU)
	uint8 mask;
	uint16 needCopyBits;
	PduLengthType bytePos;
	uint8 bitOffset;
	uint16 remainBits;
	uint64 oldValue;
	PduIdType pduId = 0u;
    uint32 bitPosition = 0u;
    uint16 refBufIdx;
	Com_SignalGroupIdType signalGroupId;
    Com_SignalEndiannessType signalEndianness;
    uint64 signalValue;
    uint8 bitSize = 0u;
    signalValue = *SignalValuePtr;
    switch(DestSignalType)
    {
		case COM_SIGNAL:
			pduId = Com_ConfigPtr->ComTxSignal[DestSignalId].ComIpduRefIndex;
			bitPosition = Com_ConfigPtr->ComTxSignal[DestSignalId].ComBitPosition;
			signalEndianness = Com_ConfigPtr->ComTxSignal[DestSignalId].ComSignalEndianness;
			bitSize = Com_ConfigPtr->ComTxSignal[DestSignalId].ComBitSize;
			break;
		case COM_GROUP_SIGNAL:
			signalGroupId = Com_ConfigPtr->ComTxGroupSignal[DestSignalId].ComSignalGroupRef;
			pduId = Com_ConfigPtr->ComTxSignalGroup[signalGroupId].ComIpduRefIndex;
			bitPosition = Com_ConfigPtr->ComTxGroupSignal[DestSignalId].ComBitPosition;
			signalEndianness = Com_ConfigPtr->ComTxGroupSignal[DestSignalId].ComSignalEndianness;
			bitSize = Com_ConfigPtr->ComTxGroupSignal[DestSignalId].ComBitSize;
			break;
		default:
			break;
    }
	bytePos = (uint32)(bitPosition >> 3u);
	bitOffset = (uint8)(bitPosition & 0x07u);
	refBufIdx = Com_ConfigPtr->ComTxIPdu[pduId].ComTxIPduBufIndex;
	oldValue = signalValue;
	signalValue = signalValue << (bitOffset);
	if(bitSize > 0u)
	{
		if(bitSize >= (8u - bitOffset))
		{
			mask = (uint8)(~((uint8)(0xFFu << bitOffset)));
			needCopyBits = 8u - (uint16)bitOffset;
		}
		else
		{
			mask = (uint8)(~(uint8)((uint8)((uint8)(1u << bitSize) - 1u) << bitOffset));
			needCopyBits = bitSize;
		}

		Com_TxIPduRuntimeValue[refBufIdx + bytePos] = \
				(Com_TxIPduRuntimeValue[refBufIdx + bytePos] & mask) | (uint8)signalValue;
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
			signalValue = oldValue >> needCopyBits;
			if(remainBits >= 8u)
			{
				Com_TxIPduRuntimeValue[refBufIdx + bytePos] = (uint8)signalValue;
				needCopyBits += 8u;
			}
			else
			{
				mask = (uint8)(0xFFu << remainBits);
				Com_TxIPduRuntimeValue[refBufIdx + bytePos] = \
					(Com_TxIPduRuntimeValue[refBufIdx + bytePos] & mask) | (uint8)signalValue;
				needCopyBits += remainBits;
			}
		}
	}
#endif
	return;
}

#if(COM_TMCTXSIGNAL_NUMBER > 0u)
/**
 * @brief			calculate dest signal/group signal/description signal TMC
 * @param[in]		SignalType: type of signal
 * @param[in]		ComFilter: Filter mode of signal
 * @param[in]		NewSignalValuePtr: New signal value
 * @param[in]		OldSignalValuePtr: Old signal value
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
STATIC FUNC(boolean,COM_CODE)
Com_CalDestSignalTMC
(
	VAR(Com_SignalType ,COM_VAR) SignalType,
	P2CONST(Com_FilterType, AUTOMATIC, COM_APPL_CONST)ComFilter,
	P2CONST(uint64, AUTOMATIC, COM_APPL_CONST)NewSignalValuePtr,
	P2CONST(uint64, AUTOMATIC, COM_APPL_CONST)OldSignalValuePtr
)
{
	boolean ret = (boolean)FALSE;
	Com_FilterAlgorithmType filterType;
	uint64 signalNewValue;
	uint64 signalOldValue;
    #if(COM_NUMBER_OF_ONEEVERYNFILTERSIGNAL > 0u)
	Com_SignalIdType oneEveryNId;
	uint32 filterOffset;
	uint32 filterPeriod;
    #endif
	signalNewValue = *NewSignalValuePtr;
	signalOldValue = *OldSignalValuePtr;
	filterType = ComFilter->ComFilterAlgorithm;
	if(filterType == COM_ALWAYS)
	{
		ret = (boolean)TRUE;
	}
	else if(filterType == COM_MASKED_NEW_EQUALS_X)
	{
		if(((signalNewValue) & (ComFilter->ComFilterMask)) == (ComFilter->ComFilterX))
		{
			ret = (boolean)TRUE;
		}
	}
	else if(filterType == COM_MASKED_NEW_DIFFERS_X)
	{
		if(((signalNewValue) & (ComFilter->ComFilterMask)) != (ComFilter->ComFilterX))
		{
			ret =(boolean) TRUE;
		}
	}
	else if(filterType == COM_NEW_IS_WITHIN)
	{
		Com_CalWithinTMC(SignalType,signalNewValue,ComFilter,&ret);
	}
	else if(filterType == COM_NEW_IS_OUTSIDE)
	{
		Com_CalOutsideTMC(SignalType,signalNewValue,ComFilter,&ret);
	}
#if(COM_NUMBER_OF_ONEEVERYNFILTERSIGNAL > 0)
	else if(filterType == COM_ONE_EVERY_N)
	{
		filterOffset = ComFilter->ComFilterOffset;
		filterPeriod = ComFilter->ComFilterPeriod;
		oneEveryNId = ComFilter->ComOneEveryNId;
		if(filterPeriod == Com_OneEveryNcnt[oneEveryNId])
		{
			Com_OneEveryNcnt[oneEveryNId] = 0;
		}
		if(filterOffset == Com_OneEveryNcnt[oneEveryNId])
		{
			ret = TRUE;
		}
		Com_OneEveryNcnt[oneEveryNId]++;
	}
#endif
	else if(filterType == COM_MASKED_NEW_DIFFERS_MASKED_OLD)
	{
        if(((signalNewValue) & (ComFilter->ComFilterMask))
            != ((signalOldValue) & (ComFilter->ComFilterMask)))
        {
        	ret =(boolean) TRUE;
        }
	}
	else
	{
		/* do nothing */
	}
	return ret;
}
#endif

/**
 * @brief			gateway pdu(which include gateway signal) handle
 * @param[in]		PduId: pdu identify
 * @param[in]		SignalProperty: Attribute of signal
 * @param[in]		RptNum: Repeated times
 * @param[in]		ValueChanged: Does the value of the signal change
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
STATIC FUNC(void,COM_CODE)
Com_HandleGwSignalOfPdu(
	VAR(PduIdType ,COM_VAR) PduId,
	VAR(Com_TransferPropertyType, COM_VAR) SignalProperty,
	VAR(uint16 ,COM_VAR) RptNum,
	VAR(boolean, COM_VAR) ValueChanged
)
{
#if(COM_NUMBER_OF_TXIPDU > 0)
	if((COM_DIRECT == Com_TxIPduMode[PduId]) || (COM_MIXED == Com_TxIPduMode[PduId]))
	{
		if(SignalProperty == COM_TRIGGERED)
		{
			Com_TxIPduRepeatNum[PduId] = RptNum;
			Com_TxIPduRepetitionPeriod[PduId] = 0u;
		}
		else if((SignalProperty == COM_TRIGGERED_ON_CHANGE) && (ValueChanged == (boolean)TRUE))
		{
			Com_TxIPduRepeatNum[PduId] = RptNum;
			Com_TxIPduRepetitionPeriod[PduId] = 0u;
		}
		else if((SignalProperty == COM_TRIGGERED_ON_CHANGE_WITHOUT_REPETITION) \
				&& (ValueChanged == (boolean)TRUE))
		{
			Com_TxIPduRepeatNum[PduId] = 1u;
			Com_TxIPduRepetitionPeriod[PduId] = 0u;
		}
		else if(SignalProperty == COM_TRIGGERED_WITHOUT_REPETITION)
		{
			Com_TxIPduRepeatNum[PduId] = 1u;
			Com_TxIPduRepetitionPeriod[PduId] = 0u;
		}
		else
		{

		}
	}
	else
	{
		Com_TxIPduRepeatNum[PduId] = 0u;
		Com_TxIPduRepetitionPeriod[PduId] = 0u;
	}
#endif
	return;
}

/**
 * @brief			gateway pdu(which include gateway group signal) handle
 * @param[in]		PduId: pdu identify
 * @param[in]		SignalProperty: Attribute of signal
 * @param[in]		GroupSignalId: group signal identify
 * @param[in]		RptNum: Repeated times
 * @param[in]		ValueChanged: Does the value of the signal change
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
STATIC FUNC(void,COM_CODE)
Com_HandleGwGroupSignalOfPdu(
	VAR(PduIdType ,COM_VAR)PduId,
	VAR(Com_TransferPropertyType ,COM_VAR) SignalGroupProperty,
	VAR(Com_SignalIdType ,COM_VAR) GroupSignalId,
	VAR(uint16 ,COM_VAR) RptNum,
	VAR(boolean, COM_VAR) ValueChanged
)
{
#if(COM_NUMBER_OF_TXIPDU > 0)
	Com_TransferPropertyType signalProperty;
	if((COM_DIRECT == Com_TxIPduMode[PduId]) || (COM_MIXED == Com_TxIPduMode[PduId]))
	{
		if(SignalGroupProperty == COM_TRIGGERED)
		{
			Com_TxIPduRepeatNum[PduId] = RptNum;
			Com_TxIPduRepetitionPeriod[PduId]= 0u;
		}
		else if(SignalGroupProperty == COM_TRIGGERED_ON_CHANGE)
		{
				signalProperty = Com_ConfigPtr->ComTxGroupSignal[GroupSignalId].ComTransferProperty;
				if(((boolean)TRUE == ValueChanged) && (COM_TRIGGERED_ON_CHANGE == signalProperty))
				{
					Com_TxIPduRepeatNum[PduId] = RptNum;
					Com_TxIPduRepetitionPeriod[PduId] = 0u;
				}
		}
		else if(SignalGroupProperty == COM_TRIGGERED_ON_CHANGE_WITHOUT_REPETITION)
		{
			Com_TxIPduRepeatNum[PduId] = 1u;
			Com_TxIPduRepetitionPeriod[PduId] = 0u;
		}
		else if(SignalGroupProperty == COM_TRIGGERED_WITHOUT_REPETITION)
		{
			Com_TxIPduRepeatNum[PduId] = 1u;
			Com_TxIPduRepetitionPeriod[PduId] = 0u;
		}
		else
		{

		}
	}
	else
	{
		Com_TxIPduRepeatNum[PduId] = 0u;
		Com_TxIPduRepetitionPeriod[PduId] = 0u;
	}
#endif
	return;
}

/*====================================================================================================*
 *                                          GLOBAL FUNCTIONS
 *====================================================================================================*/
/**
 * @brief			gateway signal/group signal/signal group/description signal
 * @param[in]		PduId: pdu identify
 * @param[in]		SignalProperty: Attribute of signal
 * @param[in]		GroupSignalId: group signal identify
 * @param[in]		RptNum: Repeated times
 * @param[in]		ValueChanged: Does the value of the signal change
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void,COM_CODE)
Com_GwSignal(
	VAR(Com_SignalIdType ,COM_VAR) GwMappingId,
	VAR(Com_GWSignalType ,COM_VAR) GwSourceSignalType,
	VAR(Com_SignalIdType ,COM_VAR) GwSourceSignalId
)
{
	Com_SignalIdType destMappingNumber;
	Com_SignalIdType cnt = 0u;
	Com_SignalType signalType;
	uint16 signalBufferId;
	Com_GWSignalType destSignalType;
	Com_SignalIdType destSignalId;
	uint16 signalLength;
	Com_SignalGroupIdType signalGroupId;
	Com_SignalIdType groupSignalNumber;
	Com_SignalIdType index;
	Com_SignalIdType sourceSignalId;
	destMappingNumber = Com_ConfigPtr->ComGwMapping[GwMappingId].ComGwDestNumber;
	switch(GwSourceSignalType)
	{
		case COM_SIGNAL:
			signalType = COM_CFG_RXSIGNAL(GwSourceSignalId).ComSignalType;
			signalBufferId = COM_CFG_RXSIGNAL(GwSourceSignalId).GWSignalBufferId;
			for(cnt = 0u;cnt < destMappingNumber; cnt ++)
			{
				destSignalType = Com_ConfigPtr->ComGwMapping[GwMappingId].ComGwDest[cnt].\
						ComGwDestSignalType;
				destSignalId = Com_ConfigPtr->ComGwMapping[GwMappingId].ComGwDest[cnt].\
						ComGwDestSignalId;
				switch(signalType)
				{
					case COM_UINT8_N:
						signalLength = COM_CFG_RXSIGNAL(GwSourceSignalId).ComSignalLength;
						Com_Hanldel8_NGwSignal(signalBufferId,signalLength,destSignalType,\
								destSignalId);
						break;
					case COM_UINT8_DYN:
#if(COM_NUMBER_OF_RXIPDU > 0)
						signalLength = COM_CFG_RXSIGNAL(GwSourceSignalId).ComSignalLength;
						Com_HandleDynGwSignal(signalBufferId,signalLength,destSignalType,\
								destSignalId);
#endif
						break;
					default:
						Com_HanldeGwSignal(signalType, signalBufferId, destSignalType, \
								destSignalId);
						break;
				}
			}
			break;
		case COM_GROUP_SIGNAL:
			signalType = Com_ConfigPtr->ComRxGroupSignal[GwSourceSignalId].ComSignalType;
			signalBufferId = Com_ConfigPtr->ComRxGroupSignal[GwSourceSignalId].GWSignalBufferId;
			for(cnt = 0u;cnt < destMappingNumber; cnt ++)
			{
				destSignalType = Com_ConfigPtr->ComGwMapping[GwMappingId].ComGwDest[cnt].\
						ComGwDestSignalType;
				destSignalId = Com_ConfigPtr->ComGwMapping[GwMappingId].ComGwDest[cnt].\
						ComGwDestSignalId;
				switch(signalType)
				{
					case COM_UINT8_N:
						signalLength = Com_ConfigPtr->ComRxGroupSignal[GwSourceSignalId].\
						ComSignalLength;
						Com_Hanldel8_NGwSignal(signalBufferId,signalLength,destSignalType,\
								destSignalId);
						break;
					case COM_UINT8_DYN:
#if(COM_NUMBER_OF_RXIPDU > 0)
						signalGroupId = Com_ConfigPtr->ComRxGroupSignal[GwSourceSignalId].\
						ComSignalGroupRef;
						signalLength = Com_ConfigPtr->ComRxGroupSignal[GwSourceSignalId].\
								ComSignalLength;
						Com_HandleDynGwSignal(signalBufferId,signalLength,destSignalType,\
								destSignalId);
#endif
						break;
					default:
						Com_HanldeGwSignal(signalType, signalBufferId, destSignalType, \
								destSignalId);
						break;
				}
			}
			break;
        case COM_SIGNAL_GROUP:
        	groupSignalNumber = COM_CFG_RXSIGNALGROUP(GwSourceSignalId).ComGroupSignalNumber;
        	for(index = 0u;index < groupSignalNumber; index++)
        	{
        		sourceSignalId = COM_CFG_RXSIGNALGROUP(GwSourceSignalId).ComRxGroupSignalId[cnt];
        		signalType = COM_CFG_RXGROUPSIGNAL(sourceSignalId).ComSignalType;
        		signalBufferId = COM_CFG_RXGROUPSIGNAL(sourceSignalId).GWSignalBufferId;
            	for(cnt = 0u;cnt < destMappingNumber; cnt++)
            	{
            		signalGroupId = Com_ConfigPtr->ComGwMapping[GwMappingId].ComGwDest[cnt].\
            				ComGwDestSignalId;
            		destSignalId = Com_ConfigPtr->ComTxSignalGroup[signalGroupId].\
            				ComTxGroupSignalId[cnt];
            		switch(signalType)
            		{
        			    case COM_UINT8_N:
        			    	signalLength = COM_CFG_RXGROUPSIGNAL(sourceSignalId).ComSignalLength;
        			    	Com_Hanldel8_NGwSignal(signalBufferId,signalLength,COM_GROUP_SIGNAL,\
        			    			destSignalId);
        				    break;
        			    case COM_UINT8_DYN:
#if(COM_NUMBER_OF_RXIPDU > 0)
        			    	signalLength = COM_CFG_RXGROUPSIGNAL(sourceSignalId).ComSignalLength;
        			    	Com_HandleDynGwSignal(signalBufferId,signalLength,COM_GROUP_SIGNAL,\
        			    			destSignalId);
#endif
        				    break;
        			    default:
        			    	Com_HanldeGwSignal(signalType,signalBufferId,COM_GROUP_SIGNAL,\
        			    			destSignalId);
        				    break;
            		}
            	}
        	}
			break;
		default:
			break;
	}
}

#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
