/**
 * @file       	Com_Internal.c
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
#define COM_INTERNAL_VENDOR_ID_C 						0U
#define COM_INTERNAL_AR_RELEASE_MAJOR_VERSION_C  		4U
#define COM_INTERNAL_AR_RELEASE_MINOR_VERSION_C  		2U
#define COM_INTERNAL_AR_RELEASE_REVISION_VERSION_C		2U
#define COM_INTERNAL_SW_MAJOR_VERSION_C					1U
#define COM_INTERNAL_SW_MINOR_VERSION_C					2U
#define COM_INTERNAL_SW_PATCH_VERSION_C					0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Com_Internal.h header file are of the same vendor */
#if(COM_INTERNAL_VENDOR_ID_C != COM_INTERNAL_VENDOR_ID )
#error "Com_Internal.c and Com_Internal.h have different vendor id"
#endif

#if(\
      (COM_INTERNAL_AR_RELEASE_MAJOR_VERSION_C != COM_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
      (COM_INTERNAL_AR_RELEASE_MINOR_VERSION_C != COM_INTERNAL_AR_RELEASE_MINOR_VERSION) || \
      (COM_INTERNAL_AR_RELEASE_REVISION_VERSION_C != COM_INTERNAL_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of Com_GwInternal.c and Com_Internal.h are different "
#endif

/* Check if current file and Com_Internal.h header file are of the same software version */
#if(\
      (COM_INTERNAL_SW_MAJOR_VERSION_C != COM_INTERNAL_SW_MAJOR_VERSION) || \
      (COM_INTERNAL_SW_MINOR_VERSION_C != COM_INTERNAL_SW_MINOR_VERSION) ||\
	  (COM_INTERNAL_SW_PATCH_VERSION_C != COM_INTERNAL_SW_PATCH_VERSION)\
      )
#error "Software Version Number of Com_GwInternal.c and Com_Internal.h are different "
#endif

/*====================================================================================================*
 *                                   EXTERNAL FUNCTION DECLARATIONS
 *====================================================================================================*/


/*=================================================================================================*
 *                                           Private Function Declarations
 *=================================================================================================*/

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
#define COM_START_SEC_CODE
#include "Com_MemMap.h"

#if(COM_NUMBER_OF_RXIPDU > 0)
#if(COM_NUMBER_OF_ONEEVERYNFILTERSIGNAL > 0u)
STATIC FUNC(void,COM_CODE)
Com_ResetSignalWithOneEveryNFilter(VAR(PduIdType, COM_VAR) IpduId);
#endif/* COM_NUMBER_OF_ONEEVERYNFILTERSIGNAL > 0u */
#endif

#if(COM_NUMBER_OF_TXIPDU > 0u)
#if(COM_NUMBER_OF_ONEEVERYNFILTERSIGNAL > 0u)
STATIC FUNC(void,COM_CODE)Com_ResetTxOccurrenceOfPduFilter(VAR(PduIdType, COM_VAR) IpduId);
#endif/* COM_NUMBER_OF_ONEEVERYNFILTERSIGNAL > 0u */
#endif

#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
/*====================================================================================================*
 *                                           LOCAL VARIABLES
 *====================================================================================================*/

/*====================================================================================================*
 *                                           LOCAL FUNCTIONS
 *====================================================================================================*/

/*====================================================================================================*
 *                                          GLOBAL FUNCTIONS
 *====================================================================================================*/
#define COM_START_SEC_CODE
#include "Com_MemMap.h"

/**
 * @brief			init rx signal/group signal buffer
 * @param[in]		SignalType: type of signal
 * @param[in]		SignalInitValueId: The starting position of the signal valid value
 * @param[in]		SignalLength: length of signal
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void , COM_CODE)
Com_InitSignalBuffer(
	VAR(Com_SignalType, COM_VAR) SignalType,
	VAR(uint16, COM_VAR) SignalInitValueId,
	VAR(uint16, COM_VAR) SignalLength
)
{
#if(COM_NUMBER_OF_8BITSIGNAL > 0u)
	uint16 cnt;
#endif
	switch(SignalType)
	{

#if(COM_NUMBER_OF_BOOLSIGNAL > 0u)
		case COM_BOOLEAN:
			Com_BoolSignalRuntimeValue[SignalInitValueId] = Com_BoolSignalOriginalValue[SignalInitValueId];
			break;
#endif
#if(COM_NUMBER_OF_8BITSIGNAL > 0u)
		case COM_UINT8:
		case COM_SINT8:
			Com_8BitSignalRuntimeValue[SignalInitValueId] = Com_8BitSignalOriginalValue[SignalInitValueId];
			break;
		case COM_UINT8_N:
		case COM_UINT8_DYN:
			for(cnt = (uint16)0u;cnt < (uint16)SignalLength; cnt++)
			{
				Com_8BitSignalRuntimeValue[SignalInitValueId + cnt] = \
						Com_8BitSignalOriginalValue[SignalInitValueId + cnt];
			}
			break;
#endif
#if(COM_NUMBER_OF_16BITSIGNAL > 0u)
		case COM_UINT16:
		case COM_SINT16:
			Com_16BitSignalRuntimeValue[SignalInitValueId] = Com_16BitSignalOriginalValue[SignalInitValueId];
			break;
#endif
#if(COM_NUMBER_OF_32BITSIGNAL > 0u)
		case COM_UINT32:
		case COM_SINT32:
		case COM_FLOAT32:
			Com_32BitSignalRuntimeValue[SignalInitValueId] = Com_32BitSignalOriginalValue[SignalInitValueId];
			break;
#endif
#if(COM_NUMBER_OF_64BITSIGNAL > 0u)
		case COM_UINT64:
		case COM_SINT64:
		case COM_FLOAT64:
			Com_64BitSignalRuntimeValue[SignalInitValueId] = Com_64BitSignalOriginalValue[SignalInitValueId];
			break;
#endif
		default:
			break;
	}
	return;
}


/**
 * @brief			base the signal endianness,get the high byte number of the (group)signal
 * @param[in]		SignalEndianness: Signal storage mode
 * @param[in]		IpduBufferIndex: The corresponding pdu in the entire pdu array
 * @param[out]		/
 * @param[in/out]	/
 * @return			uint16
 * @retval			/
 */
FUNC(uint16 , COM_CODE)
Com_GetNextPduBufferIndex(
	VAR(Com_SignalEndiannessType, COM_VAR) SignalEndianness,
	VAR(Com_SignalType, COM_VAR) IpduBufferIndex
)
{
	uint16 retIpduBufferIndex = (uint16)IpduBufferIndex;

	if(COM_BIG_ENDIAN == SignalEndianness)
	{
		retIpduBufferIndex--;
	}
	else
	{
		retIpduBufferIndex++;
	}
	return retIpduBufferIndex;
}



/**
 * @brief			update the expected counter
 * @param[in]		IsTxPdu: Is it the sending type of pdu
 * @param[in]		PduId: pdu identify
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void , COM_CODE)
Com_GetNextCounterValue(VAR(boolean, COM_VAR) IsTxPdu,VAR(PduIdType, COM_VAR) PduId)
{
	uint8 maxCounterValue;
	uint8 currentCounterValue;
#if(COM_NUMBER_OF_TXIPDU > 0)
	if((boolean)TRUE == IsTxPdu)
	{
		maxCounterValue = COM_CFG_TXPDU(PduId).ComIPduCounter->ComIpduMaxCounter;
		currentCounterValue = Com_TxIPduData[PduId].TxIpduCounter;
		if(maxCounterValue == currentCounterValue)
		{
			Com_TxIPduData[PduId].TxIpduCounter = 0u;
		}
		else
		{
			Com_TxIPduData[PduId].TxIpduCounter++ ;
		}
	}
	else
#endif
	{
#if(COM_NUMBER_OF_RXIPDU > 0)
		maxCounterValue = COM_CFG_RXPDU(PduId).ComIPduCounter->ComIpduMaxCounter;
		currentCounterValue = Com_RxIPduData[PduId].RxIpduCounter;
		if(maxCounterValue == currentCounterValue)
		{
			Com_RxIPduData[PduId].RxIpduCounter = 0u;
		}
		else
		{
			Com_RxIPduData[PduId].RxIpduCounter++;
		}
#endif
	}
	return;
}

/**
 * @brief			calculate the tx ipdu TMS(signal/Group signal/Dest signal)
 * @param[in]		PduId: pdu identify
 * @param[out]		/
 * @param[in/out]	/
 * @return			boolean
 * @retval			TRUE
 * 					FALSE
 */
FUNC(boolean , COM_CODE)
Com_CalPduTMS(VAR(PduIdType, COM_VAR) PduId)
{
	/* @req [SWS_Com_00677] */
	boolean ret = (boolean)TRUE;
	uint16 cnt;
	uint16 counter;
	Com_SignalIdType signalNumber;
	Com_SignalIdType signalId;
	Com_SignalGroupIdType signalGroupNumber;
	Com_SignalGroupIdType signalGroupId;
	Com_SignalIdType groupSignalNumber;
	Com_SignalIdType groupSignalId;
	if(NULL_PTR != COM_CFG_TXPDU(PduId).ComTxModeFalse)
	{
		ret =(boolean) FALSE;
		/* PRQA S 2995 EOF #violate MISAR2004_13.7:ingore this warnning */
		signalNumber = COM_CFG_TXPDU(PduId).ComIPduSignalsRefNumber;
		for(cnt = 0u; ((cnt < signalNumber) && ((boolean)FALSE == ret)); cnt++)
		{
			signalId = COM_CFG_TXPDU(PduId).ComIPduSignalsRef[cnt];
			if(NULL_PTR != COM_CFG_TXSIGNAL(signalId).ComFilter)
			{
#if(COM_TMCTXSIGNAL_NUMBER > 0u)
				if((boolean)TRUE == TxSignalTMCRunTime\
						[COM_CFG_TXSIGNAL(signalId).ComFilter->ComTMCBufferId])
				{
					ret =(boolean) TRUE;
				}
#endif
			}
		}
		if((boolean)FALSE == ret)
		{
			signalGroupNumber = COM_CFG_TXPDU(PduId).ComIPduSignalGroupsRefNumber;
			for(cnt = 0u;(cnt < signalGroupNumber) && ((boolean)FALSE == ret); cnt++)
			{
				signalGroupId = COM_CFG_TXPDU(PduId).ComIPduSignalGroupsRef[cnt];
				groupSignalNumber = COM_CFG_TXSIGNALGROUP(signalGroupId).ComGroupSignalNumber;
				for(counter = 0u;(counter < groupSignalNumber)&&((boolean)FALSE == ret);counter++)
				{
					groupSignalId = COM_CFG_TXSIGNALGROUP(signalGroupId).ComTxGroupSignalId[counter];
					if(NULL_PTR != COM_CFG_TXGROUPSIGNAL(groupSignalId).ComFilter)
					{
#if(COM_TMCTXSIGNAL_NUMBER > 0u)
						if((boolean)TRUE == TxSignalTMCRunTime\
								[COM_CFG_TXGROUPSIGNAL(groupSignalId).ComFilter->ComTMCBufferId])
						{
							ret =(boolean) TRUE;
						}
#endif
					}
				}
			}
		}
	}
	return ret;
}

/**
 * @brief			when FilterAlgorithm is NEW_IS_WITHIN,calculate the signal's TMC
 * @param[in]		SignalType: type of signal
 * @param[in]		SignalValue: The signal value that needs to be sent
 * @param[in]		ComFilter: Filter method of signal
 * @param[in]		TMC
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void , COM_CODE)
Com_CalWithinTMC
(
	VAR(Com_SignalType, COM_VAR) SignalType,
	VAR(uint64, COM_VAR) SignalValue,
	P2CONST(Com_FilterType, AUTOMATIC, COM_APPL_CONST) ComFilter,
	P2VAR(boolean, AUTOMATIC, COM_VAR) TMC
)
{
	if((SignalType == COM_UINT8) || (SignalType == COM_UINT16) \
			|| (SignalType == COM_UINT32) || (SignalType == COM_UINT64))
	{
		if(((SignalValue) >= (ComFilter->ComFilterMin)) \
				&& ((SignalValue) <= (ComFilter->ComFilterMax)))
		{
			*TMC =(boolean) TRUE;
		}
	}
	else if(SignalType == COM_SINT8)
	{
		if(((sint8)(SignalValue) >= (sint8)(ComFilter->ComFilterMin)) \
				&& ((sint8)(SignalValue) <= (sint8)(ComFilter->ComFilterMax)))
		{
			*TMC = (boolean)TRUE;
		}
	}
	else if(SignalType == COM_SINT16)
	{
		if(((sint16)(SignalValue) >=(sint16) (ComFilter->ComFilterMin)) \
				&& ((sint16)(SignalValue) <= (sint16)(ComFilter->ComFilterMax)))
		{
			*TMC =(boolean) TRUE;
		}
	}
	else if(SignalType == COM_SINT32)
	{
		if(((sint32)(SignalValue) >= (sint32)(ComFilter->ComFilterMin)) \
				&& ((sint32)(SignalValue) <= (sint32)(ComFilter->ComFilterMax)))
		{
			*TMC =(boolean) TRUE;
		}
	}
	else if(SignalType == COM_SINT64)
	{
		if(((sint64)(SignalValue) >= (sint64)(ComFilter->ComFilterMin)) \
				&& ((sint64)(SignalValue) <= (sint64)(ComFilter->ComFilterMax)))
		{
			*TMC = (boolean)TRUE;
		}
	}
	else
	{
		/* do nothing */
	}
	return;
}

/**
 * @brief			when FilterAlgorithm is NEW_IS_OUTSIDE,calculate the signal's TMC
 * @param[in]		SignalType: type of signal
 * @param[in]		SignalValue: The signal value that needs to be sent
 * @param[in]		ComFilter: Filter method of signal
 * @param[in]		TMC
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void , COM_CODE)
Com_CalOutsideTMC
(
	VAR(Com_SignalType, COM_VAR) SignalType,
	VAR(uint64, COM_VAR) SignalValue,
	P2CONST(Com_FilterType, AUTOMATIC, COM_APPL_CONST) ComFilter,
	P2VAR(boolean, AUTOMATIC, COM_VAR) TMC
)
{
	if((SignalType == COM_UINT8) || (SignalType == COM_UINT16) \
			|| (SignalType == COM_UINT32) || (SignalType == COM_UINT64))
	{
		if(((SignalValue) < (ComFilter->ComFilterMin)) \
				|| ((SignalValue) > (ComFilter->ComFilterMax)))
		{
			*TMC =(boolean) TRUE;
		}
	}
	else if(SignalType == COM_SINT8)
	{
		if(((sint8)(SignalValue) < (sint8)(ComFilter->ComFilterMin)) \
				|| ((sint8)(SignalValue) >(sint8) (ComFilter->ComFilterMax)))
		{
			*TMC = (boolean)TRUE;
		}
	}
	else if(SignalType == COM_SINT16)
	{
		if(((sint16)(SignalValue) <(sint16) (ComFilter->ComFilterMin)) \
				|| ((sint16)(SignalValue) > (sint16)(ComFilter->ComFilterMax)))
		{
			*TMC = (boolean)TRUE;
		}
	}
	else if(SignalType == COM_SINT32)
	{
		if(((sint32)(SignalValue) <(sint32) (ComFilter->ComFilterMin)) \
				|| ((sint32)(SignalValue) > (sint32)(ComFilter->ComFilterMax)))
		{
			*TMC =(boolean) TRUE;
		}
	}
	else if(SignalType == COM_SINT64)
	{
		if(((sint64)(SignalValue) <(sint64) (ComFilter->ComFilterMin)) \
				|| ((sint64)(SignalValue) >(sint64) (ComFilter->ComFilterMax)))
		{
			*TMC = (boolean)TRUE;
		}
	}
	else
	{
		/* do nothing */	
	}
	return;
}

/**
 * @brief			calculate the TMS,store new Tx mode,get rptNum value for DIRECT/MIXED tx mode,
 * 					if TMS changed will reset periodic mode counter
 * @param[in]		TxPduId: Pdu identifier
 * @param[in]		RptNum: repeat number
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void , COM_CODE)
Com_HandleTxIpduTMS(VAR(PduIdType, COM_VAR) TxPduId,P2VAR(uint16, AUTOMATIC, COM_VAR) RptNum)
{
#if(COM_NUMBER_OF_TXIPDU > 0)
	boolean oldTms;
	/**
	 * @req [SWS_Com_00848] calculate the TMS of the Ipdu,need to query every signal/group signal/dest
	 * 						signal,until find one TRUE TMC
	 */
	oldTms = Com_TxIPduTMS[TxPduId];

	Com_TxIPduTMS[TxPduId] = Com_CalPduTMS(TxPduId);
	if(oldTms == (boolean)FALSE)
	{
		Com_TxIPduMode[TxPduId] = COM_CFG_TXPDU(TxPduId).ComTxModeFalse->ComTxModeMode;
		*RptNum  = COM_CFG_TXPDU(TxPduId).ComTxModeFalse->ComTxModeNumberOfRepetitions;
		if((boolean)TRUE == Com_TxIPduTMS[TxPduId])
		{
			Com_TxIPduMode[TxPduId] = COM_CFG_TXPDU(TxPduId).ComTxModeTrue->ComTxModeMode;
			*RptNum = COM_CFG_TXPDU(TxPduId).ComTxModeTrue->ComTxModeNumberOfRepetitions;
			if(Com_TxIPduMode[TxPduId] == COM_PERIODIC)
			{
				Com_TxIPduPeriodCnt[TxPduId] = \
						COM_CFG_TXPDU(TxPduId).ComTxModeTrue->ComTxModeTimeOffset;
			}
		}
	}
	else
	{
		Com_TxIPduMode[TxPduId] = COM_CFG_TXPDU(TxPduId).ComTxModeTrue->ComTxModeMode;
		*RptNum = COM_CFG_TXPDU(TxPduId).ComTxModeTrue->ComTxModeNumberOfRepetitions;
		if((boolean)FALSE == Com_TxIPduTMS[TxPduId])
		{
			Com_TxIPduMode[TxPduId] = COM_CFG_TXPDU(TxPduId).ComTxModeFalse->ComTxModeMode;
			*RptNum  = COM_CFG_TXPDU(TxPduId).ComTxModeFalse->ComTxModeNumberOfRepetitions;
			if(Com_TxIPduMode[TxPduId] == COM_PERIODIC)
			{
				Com_TxIPduPeriodCnt[TxPduId] = \
						COM_CFG_TXPDU(TxPduId).ComTxModeFalse->ComTxModeTimeOffset;
			}
		}
	}
#endif
	return;
}

#if(COM_NUMBER_OF_RXIPDU > 0)
#if(COM_NUMBER_OF_ONEEVERYNFILTERSIGNAL > 0u)
/**
 * @brief			reset OCCURRENCE of filter with ComFilterAlgorithm ONE_EVERY_N
 * @param[in]		PduId: pdu identify
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
STATIC FUNC(void,COM_CODE)
Com_ResetSignalWithOneEveryNFilter(VAR(PduIdType, COM_VAR) PduId)
{
	uint16 cnt;
	Com_SignalIdType SignalNumber;
	Com_SignalGroupIdType SignalGroupNumber;
	Com_SignalGroupIdType SignalGroupId;
	Com_SignalIdType SignalId;
	Com_SignalIdType oneEveryNId;
	uint16 counter;
	uint16 GroupSignalNumber;
	uint16 GroupSignalId;
	/*reset signal/group signal of rx pdu which ComFilterAlgorithm is ONE_EVERY_N*/
	SignalNumber =  COM_CFG_RXPDU(PduId).ComIPduSignalsRefNumber;
	for(cnt = 0u;cnt < SignalNumber;cnt++)
	{
		SignalId = COM_CFG_RXPDU(PduId).ComIPduSignalsRef[cnt];
		if(NULL_PTR != Com_ConfigPtr->ComRxSignal[SignalId].ComFilter)
		{
			oneEveryNId = Com_ConfigPtr->ComRxSignal[SignalId].ComFilter->ComOneEveryNId;
			if(0xffff != oneEveryNId)
			{
				Com_OneEveryNcnt[oneEveryNId] = 0u;
			}
		}
	}
	SignalGroupNumber = COM_CFG_RXPDU(PduId).ComIPduSignalGroupsRefNumber;
	for(cnt = 0u;cnt < SignalGroupNumber;cnt++)
	{
		SignalGroupId = COM_CFG_RXPDU(PduId).ComIPduSignalGroupsRef[cnt];
		GroupSignalNumber = Com_ConfigPtr->ComRxSignalGroup[SignalGroupId].ComGroupSignalNumber;
		for(counter = 0;counter < GroupSignalNumber;counter++)
		{
			GroupSignalId = Com_ConfigPtr->ComRxSignalGroup[SignalGroupId].ComRxGroupSignalId[counter];
			if(NULL_PTR != Com_ConfigPtr->ComRxGroupSignal[GroupSignalId].ComFilter)
			{
				oneEveryNId = Com_ConfigPtr->ComRxGroupSignal[GroupSignalId].ComFilter->ComOneEveryNId;
				if(0xffff != oneEveryNId)
				{
					Com_OneEveryNcnt[oneEveryNId] = 0u;
				}
			}
		}
	}
	return;
}
#endif/* COM_NUMBER_OF_ONEEVERYNFILTERSIGNAL > 0 */
#endif


/**
 * @brief			init Rx Pdu buffer
 * @param[in]		/
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void, COM_CODE)
Com_InitRxPduBuffer(void)
{
#if(COM_NUMBER_OF_RXIPDU > 0)
	uint16 cnt;
	/**
	 * @req [SWS_Com_00217] Initializes the rxipdu runtime array
	 */
	for(cnt = 0u;cnt <(uint16) COM_NUMBER_OF_RXIPDU; cnt++)
	{
		Com_RxIPduIsActive[cnt] = (COM_CFG_RXPDU(cnt).ComIPduGroupsRefNumber == 0u)? (boolean)TRUE : (boolean)FALSE;
		Com_RxIPduIsReceiving[cnt] = (boolean)FALSE;
		Com_RxIPduDMEnable[cnt] = (boolean)FALSE;
		Com_RxIPduRxIndication[cnt] = (boolean)FALSE;
		Com_RxIPduNeedGw[cnt] = (boolean)FALSE;
		Com_RxIPduOffset[cnt] = 0u;
		Com_RxIPduLength[cnt].RxIpduLength = (uint16)COM_CFG_RXPDU(cnt).ComIPduInitLength;
		Com_RxIPduData[cnt].RxIpduCounter = 0u;
		Com_RxIPduData[cnt].RxAnyCounterPdu = (boolean)FALSE;
    	/**
    	 * @req [SWS_Com_00733]
    	 * @req [SWS_Com_00772] start the deadline monitoring for these signals independently of
    	 * 						the value of the initialize parameter
    	 */
#if(COM_NUMBER_OF_TIMEOUT_SIGNAL > 0)
    	Com_ResetRxPduDeadlineMonitorTime(cnt);
#endif/* COM_NUMBER_OF_RXSIGNAL+COM_NUMBER_OF_RXSIGNALGROUP > 0u */
#if(COM_NUMBER_OF_ONEEVERYNFILTERSIGNAL > 0u)
		Com_ResetSignalWithOneEveryNFilter(cnt);
#endif/* COM_NUMBER_OF_ONEEVERYNFILTERSIGNAL > 0 */
		/**
		 * @req [SWS_Com_00587] For all I-PDUs with ComIPduDirection configured to RECEIVE
		 * 						that have a configured ComIPduCounter, shall accept any
		 * 						incoming I-PDU
		 */
		if(NULL_PTR != COM_CFG_RXPDU(cnt).ComIPduCounter)
		{
			/**
			 * @req [SWS_Com_00587] accept for I-PDUs with ComIPduDirection configured to
			 * 						RECEIVED any next incoming I-PDU counter
			 */
			Com_RxIPduData[cnt].RxAnyCounterPdu = (boolean)TRUE;
		}
	}
#endif
}

#if(COM_NUMBER_OF_TXIPDU > 0u)
/**
 * @brief			reset OCCURRENCE of filter with ComFilterAlgorithm ONE_EVERY_N
 * @param[in]		IpduId: Pdu identify
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
#if(COM_NUMBER_OF_ONEEVERYNFILTERSIGNAL > 0u)
STATIC FUNC(void,COM_CODE)
Com_ResetTxOccurrenceOfPduFilter(VAR(PduIdType, COM_VAR) IpduId)
{
    uint16 cnt;
    Com_SignalIdType signalNumber;
    Com_SignalGroupIdType signalGroupNumber;
    Com_SignalGroupIdType signalGroupId;
    Com_SignalIdType signalId;
    Com_SignalIdType oneEveryNId;
    uint16 counter;
    uint16 groupSignalNumber;
    uint16 groupSignalId;
    /* reset signal/group signal/dest description signal of tx pdu which ComFilterAlgorithm
     * is ONE_EVERY_N */
    signalNumber =  COM_CFG_TXPDU(IpduId).ComIPduSignalsRefNumber;
    for(cnt = 0u;cnt < signalNumber;cnt++)
    {
        signalId = COM_CFG_TXPDU(IpduId).ComIPduSignalsRef[cnt];
        if(NULL_PTR != COM_CFG_TXSIGNAL(signalId).ComFilter)
        {
            oneEveryNId = COM_CFG_TXSIGNAL(signalId).ComFilter->ComOneEveryNId;
            if(0xffff != oneEveryNId)
            {
                Com_OneEveryNcnt[oneEveryNId] = 0;
            }
        }
    }
    signalGroupNumber = COM_CFG_TXPDU(IpduId).ComIPduSignalGroupsRefNumber;
    for(cnt = 0u;cnt < signalGroupNumber;cnt++)
    {
        signalGroupId = COM_CFG_TXPDU(IpduId).ComIPduSignalGroupsRef[cnt];
        groupSignalNumber = COM_CFG_TXSIGNALGROUP(signalGroupId).ComGroupSignalNumber;
        for(counter = 0;counter < groupSignalNumber;counter++)
        {
            groupSignalId = COM_CFG_TXSIGNALGROUP(signalGroupId).ComTxGroupSignalId[counter];
            if(NULL_PTR != COM_CFG_TXGROUPSIGNAL(groupSignalId).ComFilter)
            {
                oneEveryNId = COM_CFG_TXGROUPSIGNAL(groupSignalId).ComFilter->ComOneEveryNId;
                if(0xffff != oneEveryNId)
                {
                    Com_OneEveryNcnt[oneEveryNId] = 0;
                }
            }
        }
    }
    return;
}
#endif/* COM_NUMBER_OF_ONEEVERYNFILTERSIGNAL > 0*/
#endif

/**
 * @brief			init Tx Pdu buffer
 * @param[in]		/
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void, COM_CODE)
Com_InitTxPduBuffer(void)
{
#if(COM_NUMBER_OF_TXIPDU > 0)
	uint16 cnt;
   	/**
	 * @req [SWS_Com_00217] Initializes the txipdu runtime array
	 */
	for(cnt = 0u;cnt < (uint16)COM_NUMBER_OF_TXIPDU; cnt++)
	{
		Com_TxIPduIsActive[cnt] = (COM_CFG_TXPDU(cnt).ComIPduGroupsRefNumber == 0u)? (boolean)TRUE : (boolean)FALSE;
		Com_TxIPduIsTransmiting[cnt] = (boolean)FALSE;
		Com_TxIPduTMS[cnt] = (boolean)TRUE;
		Com_TxIPduDMTime[cnt] = 0u;
		Com_TxIPduMDT[cnt] = 0u;
		Com_TxIPduTxConfirmation[cnt] = (boolean)FALSE;
		Com_TxIPduNeedDelay[cnt] = (boolean)FALSE;
		Com_TxIPduPeriodCnt[cnt] = 0u;
		Com_TxIPduRepeatNum[cnt] = 0u;
		Com_TxIPduRepetitionPeriod[cnt] = 0u;
		Com_TxIPduOffset[cnt] = 0u;
		Com_TxIPduData[cnt].TxIpduCounter = 0u;
		Com_TxIPduMode[cnt] = COM_DIRECT;
        if((NULL_PTR == COM_CFG_TXPDU(cnt).ComTxModeFalse) \
        		&& (COM_NONE == COM_CFG_TXPDU(cnt).ComTxModeTrue->ComTxModeMode))
        {
        	/**
        	 * @req [SWS_Com_00733]
        	 * @req [SWS_Com_00696] If an I-PDU is started and contains signals that have deadline
        	 * 						monitoring configured, start the deadline monitoring
        	 */
            Com_TxIPduDMTime[cnt] = COM_CFG_TXPDU(cnt).ComTxIpduDM;
        }
        else
        {
            Com_TxIPduDMTime[cnt] = 0u;
        }
        Com_ClearUpdates(cnt);
#if(COM_NUMBER_OF_ONEEVERYNFILTERSIGNAL > 0u)
        Com_ResetTxOccurrenceOfPduFilter(cnt);
#endif/* COM_NUMBER_OF_ONEEVERYNFILTERSIGNAL > 0u */
        if(NULL_PTR != COM_CFG_TXPDU(cnt).ComIPduCounter)
        {
            /**
             * @req [SWS_Com_00687] set the I-PDU counter to 0 for I-PDUs with ComIPduDirection
             * 						configured to SEND
             */
            Com_TxIPduData[cnt].TxIpduCounter = 0u;
        }
	}
#endif
}


/**
 * @brief			init signal buffer
 * @param[in]		/
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void, COM_CODE)
Com_InitSignalRunTimeBuffer(void)
{
	uint16 cnt;
/**
 * @req [SWS_Com_00484]
 * @req [SWS_Com_00603]
 * @req [SWS_Com_00604]
 * @req [SWS_Com_00098] Initializes the value of the signal buffer
 */
#if(COM_NUMBER_OF_BOOLSIGNAL > 0u)
	for(cnt = 0u; cnt < (uint16)COM_NUMBER_OF_BOOLSIGNAL; cnt++)
	{
		Com_BoolSignalRuntimeValue[cnt] = Com_BoolSignalOriginalValue[cnt];
	}
#endif

#if(COM_NUMBER_OF_8BITSIGNAL > 0u)
	for(cnt = 0u; cnt < (uint16)COM_NUMBER_OF_8BITSIGNAL; cnt++)
	{
        Com_8BitSignalRuntimeValue[cnt] = Com_8BitSignalOriginalValue[cnt];
	}
#endif/* COM_NUMBER_OF_8BITSIGNAL > 0u */

#if(COM_NUMBER_OF_16BITSIGNAL > 0u)
	for(cnt = 0u; cnt < (uint16)COM_NUMBER_OF_16BITSIGNAL; cnt++)
	{
		Com_16BitSignalRuntimeValue[cnt] = Com_16BitSignalOriginalValue[cnt];
	}
#endif

#if(COM_NUMBER_OF_32BITSIGNAL > 0u)
	for(cnt = 0u; cnt < (uint16)COM_NUMBER_OF_32BITSIGNAL; cnt++)
	{
		Com_32BitSignalRuntimeValue[cnt] = Com_32BitSignalOriginalValue[cnt];
	}
#endif

#if(COM_NUMBER_OF_64BITSIGNAL > 0u)
	for(cnt = 0u; cnt < (uint16)COM_NUMBER_OF_64BITSIGNAL; cnt++)
	{
		Com_64BitSignalRuntimeValue[cnt] = Com_64BitSignalOriginalValue[cnt];
	}
#endif

/* the signal is filtered in one every n way */
#if(COM_NUMBER_OF_ONEEVERYNFILTERSIGNAL > 0u)
	for(cnt = 0u; cnt < COM_NUMBER_OF_ONEEVERYNFILTERSIGNAL; cnt++)
	{
		Com_OneEveryNcnt[cnt] = 0u;
	}
#endif

/* the signal is filtered in mask new differend mask old */
#if(COM_NUMBER_OF_MASKNEWDIFFERMASKOLD_SIGNAL > 0u)
	for(cnt = 0u;cnt < COM_NUMBER_OF_MASKNEWDIFFERMASKOLD_SIGNAL;cnt++)
	{
		Com_MaskNewDifferMaskOldTimeOut[cnt] = FALSE;
	}
#endif
}

/**
 * @brief			init Group signal buffer
 * @param[in]		/
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void, COM_CODE)
Com_InitGroupSignalRunTimeBuffer(void)
{
#if((COM_NUMBER_OF_RXGROUPBOOLSIGNAL > 0u) || \
		(COM_NUMBER_OF_RXGROUP8BITSIGNAL > 0u)|| \
		(COM_NUMBER_OF_RXGROUP16BITSIGNAL > 0u) || \
		(COM_NUMBER_OF_RXGROUP32BITSIGNAL > 0u) || \
		(COM_NUMBER_OF_RXGROUP64BITSIGNAL > 0u) || \
		(COM_NUMBER_OF_TXSIGNALGROUP > 0u))
	uint16 cnt;
#endif
/**
 * @req [SWS_Com_00484]
 * @req [SWS_Com_00603]
 * @req [SWS_Com_00604]
 * @req [SWS_Com_00098] Initializes the value of the signal buffer
 */
#if(COM_NUMBER_OF_RXGROUPBOOLSIGNAL > 0u)
	for(cnt = 0u; cnt < COM_NUMBER_OF_RXGROUPBOOLSIGNAL; cnt++)
	{
		Com_RxGroupBoolSignalShadowBuff[cnt] = Com_BoolSignalOriginalValue[cnt];
	}
#endif

#if(COM_NUMBER_OF_RXGROUP8BITSIGNAL > 0u)
	for(cnt = 0u; cnt < (uint16)COM_NUMBER_OF_RXGROUP8BITSIGNAL; cnt++)
	{
		Com_RxGroup8BitSignalShadowBuff[cnt] = Com_8BitSignalOriginalValue[cnt];
	}
#endif/* COM_NUMBER_OF_8BITSIGNAL > 0u */

#if(COM_NUMBER_OF_RXGROUP16BITSIGNAL > 0u)
	for(cnt = 0u; cnt < COM_NUMBER_OF_RXGROUP16BITSIGNAL; cnt++)
	{
		Com_RxGroup16BitSignalShadowBuff[cnt] = Com_16BitSignalOriginalValue[cnt];
	}
#endif

#if(COM_NUMBER_OF_RXGROUP32BITSIGNAL > 0u)
	for(cnt = 0u; cnt < COM_NUMBER_OF_RXGROUP32BITSIGNAL; cnt++)
	{
		Com_RxGroup32BitSignalShadowBuff[cnt] = Com_32BitSignalOriginalValue[cnt];
	}
#endif

#if(COM_NUMBER_OF_RXGROUP64BITSIGNAL > 0u)
	for(cnt = 0u; cnt < COM_NUMBER_OF_RXGROUP64BITSIGNAL; cnt++)
	{
		Com_RxGroup64BitSignalShadowBuff[cnt] = Com_64BitSignalOriginalValue[cnt];
	}
#endif

/* set the status of all signal group to no need to send */
#if(COM_NUMBER_OF_TXSIGNALGROUP > 0u)
	for(cnt = 0u;cnt < COM_NUMBER_OF_TXSIGNALGROUP; cnt++)
	{
		Com_TxSignalGroupState[cnt].TransmitRequest = FALSE;
	}
#endif
}

#if(COM_NUMBER_OF_MASKNEWDIFFERMASKOLD_SIGNAL > 0u)
/**
 * @brief			when FilterAlgorithm is MASKED_NEW_DIFFERS_MASKED_OLD,calculate the signal's TMC
 * @param[in]		SignalType: type of signal
 * @param[in]		SignalValue: value of signal
 * @param[in]		ComFilter: Filter mode of signal
 * @param[in]		SignalBufferId: The current signal is located in the same array of the same signa
 * @param[in]		TMC: the TMC Value of signal
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void,COM_CODE)
Com_CalMaskedNewDiffersMaskedOldTMC
(
	VAR(Com_SignalType, COM_VAR) SignalType,
	VAR(uint64, COM_VAR) SignalValue,
	P2CONST(Com_FilterType, AUTOMATIC, COM_APPL_CONST) ComFilter,
	VAR(uint16, COM_VAR) SignalBufferId,
	P2VAR(boolean, AUTOMATIC, COM_VAR) TMC
)
{
	if(SignalType == COM_BOOLEAN)
	{
#if(COM_NUMBER_OF_BOOLSIGNAL > 0u)
		if((((boolean)(SignalValue)) & ((boolean)(ComFilter->ComFilterMask))) != \
				(Com_BoolSignalRuntimeValue[SignalBufferId] & ((boolean)(ComFilter->ComFilterMask))))
		{
			*TMC = (boolean)TRUE;
		}
#endif
	}
	else if((SignalType == COM_UINT8) || (SignalType == COM_SINT8))
	{
#if(COM_NUMBER_OF_8BITSIGNAL > 0u)
		if((((uint8)(SignalValue)) & ((uint8)(ComFilter->ComFilterMask))) != \
				(Com_8BitSignalRuntimeValue[SignalBufferId] & ((uint8)(ComFilter->ComFilterMask))))
		{
			*TMC = (boolean)TRUE;
		}
#endif
	}
	else if((SignalType == COM_UINT16) || (SignalType == COM_SINT16))
	{
#if(COM_NUMBER_OF_16BITSIGNAL > 0u)
		if((((uint16)(SignalValue)) & ((uint16)(ComFilter->ComFilterMask))) != \
				(Com_16BitSignalRuntimeValue[SignalBufferId] & ((uint16)(ComFilter->ComFilterMask))))
		{
			*TMC = (boolean)TRUE;
		}
#endif
	}
	else if((SignalType == COM_UINT32) || (SignalType == COM_SINT32))
	{
#if(COM_NUMBER_OF_32BITSIGNAL > 0u)
		if((((uint32)(SignalValue)) & ((uint32)(ComFilter->ComFilterMask))) != \
				(Com_32BitSignalRuntimeValue[SignalBufferId] & ((uint32)(ComFilter->ComFilterMask))))
		{
			*TMC = (boolean)TRUE;
		}
#endif
	}
	else if((SignalType == COM_UINT64) || (SignalType == COM_SINT64))
	{
#if(COM_NUMBER_OF_64BITSIGNAL > 0u)
		if((((uint64)(SignalValue)) & ((uint64)(ComFilter->ComFilterMask))) != \
				(Com_64BitSignalRuntimeValue[SignalBufferId] & ((uint64)(ComFilter->ComFilterMask))))
		{
			*TMC = (boolean)TRUE;
		}
#endif
	}
	else
	{
		/* do nothing */
	}
	return;
}
#endif

#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

