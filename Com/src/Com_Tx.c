/**
 * @file       	Com_Tx.c
 * @brief       The internal source file of the com module, mainly processing the sending process
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

/* PRQA S 0292, 0288, 1503, 1505, 0857, 0791, 0828, 0647, 0491,0316 EOF #
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
#include "PduR_Com.h"
#ifdef AH_TEST_COM
#include "TestCode.h"
#endif
/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION
 *====================================================================================================*/
#define COM_TXINTERNAL_VENDOR_ID_C 							0U
#define COM_TXINTERNAL_AR_RELEASE_MAJOR_VERSION_C  			4U
#define COM_TXINTERNAL_AR_RELEASE_MINOR_VERSION_C  			2U
#define COM_TXINTERNAL_AR_RELEASE_REVISION_VERSION_C		2U
#define COM_TXINTERNAL_SW_MAJOR_VERSION_C					1U
#define COM_TXINTERNAL_SW_MINOR_VERSION_C					2U
#define COM_TXINTERNAL_SW_PATCH_VERSION_C					0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Com_Internal.h header file are of the same vendor */
#if(COM_TXINTERNAL_VENDOR_ID_C != COM_INTERNAL_VENDOR_ID )
#error "Com_TxInternal.c and Com_Internal.h have different vendor id"
#endif

#if(\
      (COM_TXINTERNAL_AR_RELEASE_MAJOR_VERSION_C != COM_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
      (COM_TXINTERNAL_AR_RELEASE_MINOR_VERSION_C != COM_INTERNAL_AR_RELEASE_MINOR_VERSION) || \
      (COM_TXINTERNAL_AR_RELEASE_REVISION_VERSION_C != COM_INTERNAL_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of Com_TxInternal.c and Com_Internal.h are different "
#endif

/* Check if current file and Com_Internal.h header file are of the same software version */
#if(\
      (COM_TXINTERNAL_SW_MAJOR_VERSION_C != COM_INTERNAL_SW_MAJOR_VERSION) || \
      (COM_TXINTERNAL_SW_MINOR_VERSION_C != COM_INTERNAL_SW_MINOR_VERSION) ||\
	  (COM_TXINTERNAL_SW_PATCH_VERSION_C != COM_INTERNAL_SW_PATCH_VERSION)\
      )
#error "Software Version Number of Com_TxInternal.c and Com_Internal.h are different "
#endif

#ifndef DISABLE_INTERMOD_VERSION_CHECK

#if(\
      (COM_TXINTERNAL_AR_RELEASE_MAJOR_VERSION_C != PDUR_COM_AR_RELEASE_MAJOR_VERSION) || \
      (COM_TXINTERNAL_AR_RELEASE_MINOR_VERSION_C != PDUR_COM_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of Com_TxInternal.c and PduR_Com.h are different "
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

#if(COM_NUMBER_OF_TXIPDU > 0)
#if(COM_NUMBER_OF_IPDUGROUP > 0u)
STATIC FUNC(void,COM_CODE)Com_ResetTxPduBufferAndSignalBuffer(VAR(PduIdType, COM_VAR) PduId);
#endif
#endif/* COM_IPDUGROUP_NUMBER > 0u */

#if(COM_NUMBER_OF_TXSIGNALGROUP > 0u)
STATIC FUNC(void,COM_CODE)Com_PackGroupSignal(VAR(Com_SignalIdType, COM_VAR) GroupSignalId);
#endif/* COM_NUMBER_OF_TXSIGNALGROUP > 0u */



#if(COM_TMCTXSIGNAL_NUMBER > 0u)
STATIC FUNC(boolean,COM_CODE)
Com_CalSignalTMC
(
	P2CONST(void, AUTOMATIC, COM_APPL_CONST) SignalValuePtr,
	P2CONST(Com_FilterType, AUTOMATIC, COM_APPL_CONST) ComFilter,
	VAR(Com_SignalType, COM_VAR) SignalType,
	VAR(uint16, COM_VAR) SignalBufferId
);
#endif



#if(COM_NUMBER_OF_TXSIGNALGROUP > 0u)
STATIC FUNC(uint8 , COM_CODE)Com_HandleTxSignalGroup(
	Com_SignalGroupIdType SignalGroupId,
	uint16 RptNum
);
#endif

#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

/*====================================================================================================*
 *                                           LOCAL FUNCTIONS
 *====================================================================================================*/
#define COM_START_SEC_CODE
#include "Com_MemMap.h"

#if(COM_NUMBER_OF_TXIPDU > 0)
#if(COM_NUMBER_OF_IPDUGROUP > 0u)
/**
 * @brief			init the tx ipdu buffer,all signal buffer(included in the ipdu) and init the TMC
 * @param[in]		IpduId: ID of the SDU that is requested to be transmitted.
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
STATIC FUNC(void,COM_CODE)Com_ResetTxPduBufferAndSignalBuffer(VAR(PduIdType, COM_VAR) PduId)
{
	Com_SignalIdType signalId;
#if(COM_TMCTXSIGNAL_NUMBER > 0u)
	Com_SignalIdType tmcIdx;
#endif
	Com_SignalIdType signalNumber;
	Com_SignalGroupIdType signalGroupNumber;
	Com_SignalGroupIdType signalGroupId;
	Com_SignalType signalType;
	uint16 signallength = 0u;
	uint16 groupSignalNumber;
	uint16 groupSignalId;
	uint16 initValueId;
	uint16 refBufferIdx;
	uint16 pduLength;
	uint16 cnt;
	uint16 index;
	refBufferIdx = COM_CFG_TXPDU(PduId).ComTxIPduBufIndex;
	pduLength = (uint16)COM_CFG_TXPDU(PduId).ComIPduInitLength;
	for(cnt = 0u; cnt < pduLength; cnt ++)
	{
		Com_TxIPduRuntimeValue[refBufferIdx + cnt] = Com_TxIPduOriginalValue[refBufferIdx + cnt];
	}
	signalNumber = COM_CFG_TXPDU(PduId).ComIPduSignalsRefNumber;
	for(cnt = 0u; cnt < signalNumber;cnt ++)
	{
		signalId = COM_CFG_TXPDU(PduId).ComIPduSignalsRef[cnt];
		initValueId = COM_CFG_TXSIGNAL(signalId).ComSignalInitValueId;
		signalType = COM_CFG_GET_TXSIGNAL_TYPE(signalId);
		if(signalType == COM_UINT8_N)
		{
			signallength = COM_CFG_TXSIGNAL(signalId).ComSignalLength;
		}
		else if(signalType == COM_UINT8_DYN)
		{
			signallength = COM_CFG_TXSIGNAL(signalId).ComSignalDataInitValueLength;
		}
		else
		{
			
		}
		Com_InitSignalBuffer((Com_SignalType)signalType, initValueId, signallength);
		if(NULL_PTR != COM_CFG_TXSIGNAL(signalId).ComFilter)
		{
#if(COM_TMCTXSIGNAL_NUMBER > 0u)
			tmcIdx = COM_CFG_TXSIGNAL(signalId).ComFilter->ComTMCBufferId;
			TxSignalTMCRunTime[tmcIdx] = Com_TxSignalOriginalTMC[tmcIdx];
#endif
		}
	}
	signalGroupNumber = COM_CFG_TXPDU(PduId).ComIPduSignalGroupsRefNumber;
	for(cnt = 0u; cnt < signalGroupNumber; cnt ++)
	{
		signalGroupId = COM_CFG_TXPDU(PduId).ComIPduSignalGroupsRef[cnt];
		groupSignalNumber = Com_ConfigPtr->ComTxSignalGroup[signalGroupId].ComGroupSignalNumber;
		for(index = 0u; index< groupSignalNumber ;index++)
		{
			groupSignalId = Com_ConfigPtr->ComTxSignalGroup[signalGroupId].ComTxGroupSignalId[index];
			initValueId = COM_CFG_TXGROUPSIGNAL(groupSignalId).ComSignalInitValueId;
			signalType = COM_CFG_TXGROUPSIGNAL(groupSignalId).ComSignalType;
			if(signalType == COM_UINT8_N)
			{
				signallength = COM_CFG_TXGROUPSIGNAL(groupSignalId).ComSignalLength;
			}
			else if(signalType == COM_UINT8_DYN)
			{
				signallength = COM_CFG_TXGROUPSIGNAL(groupSignalId).ComSignalDataInitValueLength;
			}
			else
			{
			
			}
			Com_InitSignalBuffer(signalType, initValueId, signallength);
			if(NULL_PTR != COM_CFG_TXGROUPSIGNAL(groupSignalId).ComFilter)
			{
#if(COM_TMCTXSIGNAL_NUMBER > 0u)
				tmcIdx = COM_CFG_TXGROUPSIGNAL(groupSignalId).ComFilter->ComTMCBufferId;
				TxSignalTMCRunTime[tmcIdx] = Com_TxSignalOriginalTMC[tmcIdx];
#endif
			}
		}

	}
#if(COM_NUMBER_OF_TXIPDU > 0)
	Com_TxIPduTMS[PduId] = (boolean)TRUE;
	Com_TxIPduMode[PduId] = COM_DIRECT;
	Com_TxIPduTxConfirmation[PduId] = (boolean)FALSE;
	Com_TxIPduRepetitionPeriod[PduId] = 0u;
	Com_TxIPduRepeatNum[PduId] = 0u;
	Com_TxIPduIsTransmiting[PduId] = (boolean)FALSE;
	Com_TxIPduNeedDelay[PduId] = (boolean)FALSE;
#endif
	return;
}
#endif
#endif/* COM_IPDUGROUP_NUMBER > 0 */


#if(COM_NUMBER_OF_TXSIGNALGROUP > 0u)
/**
 * @brief			pack tx group signal(not dynamic)
 * @param[in]		GroupSignalId: Id of group signal to be sent.
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
STATIC FUNC(void,COM_CODE)
Com_PackGroupSignal(VAR(Com_SignalIdType, COM_VAR) GroupSignalId)
{
	uint8 mask;
	uint16 needCopyBits;
	PduLengthType bytePos;
	uint8 bitOffset;
	uint16 remainBits;
	Com_SignalGroupIdType signalGroupId;
	uint8 bitSize;
	uint64 oldValue;
	uint16 initValueId;
	uint16 pduBufferIndex;
	uint8 signalLength;
	uint16 index;
	uint64 signalValue = 0u;
	PduIdType refPduId;
	Com_SignalType signalType;
	Com_SignalEndiannessType signalEndianness;
	signalGroupId = COM_CFG_TXGROUPSIGNAL(GroupSignalId).ComSignalGroupRef;
	refPduId = COM_CFG_TXSIGNALGROUP(signalGroupId).ComIpduRefIndex;
	bitSize = COM_CFG_TXGROUPSIGNAL(GroupSignalId).ComBitSize;
	signalType = COM_CFG_TXGROUPSIGNAL(GroupSignalId).ComSignalType;
	pduBufferIndex = COM_CFG_TXPDU(refPduId).ComTxIPduBufIndex;
	initValueId = COM_CFG_TXGROUPSIGNAL(GroupSignalId).ComSignalInitValueId;
	bytePos = (uint32)(COM_CFG_TXGROUPSIGNAL(GroupSignalId).ComBitPosition >> 3u);
	bitOffset = (uint8)(COM_CFG_TXGROUPSIGNAL(GroupSignalId).ComBitPosition & 0x07u);
	/*
	 * @req [SWS_Com_00050] copy the shadow buffer atomically to the I-PDU buffer
	 */
	if(COM_BOOLEAN == signalType)
	{
#if(COM_NUMBER_OF_BOOLSIGNAL > 0u)
		signalValue = (uint64)(Com_BoolSignalRuntimeValue[initValueId]);
#endif
	}
	else if(COM_UINT8_N == signalType)
	{
		signalLength = COM_CFG_TXGROUPSIGNAL(GroupSignalId).ComSignalLength;
		for(index = 0u; index < signalLength; index++)
		{
#if(COM_NUMBER_OF_8BITSIGNAL > 0u)
			signalValue |= (uint64)((uint64)Com_8BitSignalRuntimeValue[initValueId + index] << (8u * index));
#endif
		}
	}
	else if(signalType == COM_UINT8 || signalType == COM_SINT8)
	{
#if(COM_NUMBER_OF_8BITSIGNAL > 0u)
		signalValue = (uint64)(Com_8BitSignalRuntimeValue[initValueId]);
#endif
	}
	else if(signalType == COM_UINT16 || signalType == COM_SINT16)
	{
#if(COM_NUMBER_OF_16BITSIGNAL > 0u)
		signalValue = (uint64)(Com_16BitSignalRuntimeValue[initValueId]);
#endif
	}
	else if(signalType == COM_UINT32 || signalType == COM_SINT32 || signalType == COM_FLOAT32)
	{
#if(COM_NUMBER_OF_32BITSIGNAL > 0u)
		signalValue = (uint64)(Com_32BitSignalRuntimeValue[initValueId]);
#endif
	}
	else if(signalType == COM_UINT64 || signalType == COM_SINT64 || signalType == COM_FLOAT64)
	{
#if(COM_NUMBER_OF_64BITSIGNAL > 0u)
		signalValue = (Com_64BitSignalRuntimeValue[initValueId]);
#endif
	}
	else
	{
		/* do nothing */
	}
	/* signal MSB byte value used for the signal value bits cover 9 bytes */
	signalEndianness = COM_CFG_TXGROUPSIGNAL(GroupSignalId).ComSignalEndianness;
	oldValue = signalValue;
	signalValue = signalValue << (bitOffset);
	if(bitSize >= (8 - bitOffset))
	{
		mask = (uint8)(~((uint8)(0xFF << bitOffset)));
		needCopyBits = 8 - bitOffset;
	}
	else
	{
		mask = (uint8)(~(((1u << bitSize) - 1u) << bitOffset));
		needCopyBits = bitSize;
	}
	Com_TxIPduRuntimeValue[pduBufferIndex + bytePos] = \
			(Com_TxIPduRuntimeValue[pduBufferIndex + bytePos] & mask) | (uint8)signalValue;
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
			Com_TxIPduRuntimeValue[pduBufferIndex + bytePos] = (uint8)signalValue;
			needCopyBits += 8u;
		}
		else
		{
			mask = (uint8)(0xFFu << remainBits);
			Com_TxIPduRuntimeValue[pduBufferIndex + bytePos] = \
				(Com_TxIPduRuntimeValue[pduBufferIndex + bytePos] & mask) | (uint8)signalValue;
			needCopyBits += remainBits;
		}
	}
	return;
}
#endif/*COM_NUMBER_OF_TXSIGNALGROUP > 0*/

#if(COM_TMCTXSIGNAL_NUMBER > 0u)
/**
 * @brief			calculate the new TMC of the signal new value
 * @param[in]		SignalValuePtr: value of signal
 * @param[in]		ComFilter: Filter mode of signal
 * @param[in]		SignalType: type of signal
 * @param[in]		SignalBufferId: The current signal is located in the same array of the same signal
 * @param[out]		/
 * @param[in/out]	/
 * @return			boolean
 * @retval			TRUE
 * 					FALSE
 */
STATIC FUNC(boolean,COM_CODE)
Com_CalSignalTMC
(
	P2CONST(void, AUTOMATIC, COM_APPL_CONST) SignalValuePtr,
	P2CONST(Com_FilterType, AUTOMATIC, COM_APPL_CONST) ComFilter,
	VAR(Com_SignalType, COM_VAR) SignalType,
	VAR(uint16, COM_VAR) SignalBufferId
)
{
	/**
	 * @req [SWS_Com_00679] If the AUTOSAR COM module evaluates no TMC of a contributing signal as true,
	 * 						then the AUTOSAR COM module shall evaluate the TMS as false
	 */
	boolean ret = (boolean)FALSE;
	Com_FilterAlgorithmType filterType;
	uint64 changedValue = 0u;
	filterType = ComFilter->ComFilterAlgorithm;
#if(COM_NUMBER_OF_ONEEVERYNFILTERSIGNAL > 0)
	    Com_SignalIdType oneEveryNId;
	    uint32 filterOffset;
	    uint32 filterPeriod;
#endif/* COM_NUMBER_OF_ONEEVERYNFILTERSIGNAL > 0 */
	if(SignalType == COM_BOOLEAN)
	{
		changedValue = (uint64)(*(const boolean*)SignalValuePtr);
	}
	else if((SignalType == COM_UINT8) || (SignalType == COM_SINT8))
	{
		changedValue = (uint64)(*(const uint8*)SignalValuePtr);
	}
	else if((SignalType == COM_UINT16) || (SignalType == COM_SINT16))
	{
		changedValue = (uint64)(*(const uint16*)SignalValuePtr);
	}
	else if((SignalType == COM_UINT32) || (SignalType == COM_SINT32) || (SignalType == COM_FLOAT32))
	{
		changedValue = (uint64)(*(const uint32*)SignalValuePtr);
	}
	else if((SignalType == COM_UINT64) || (SignalType == COM_SINT64) || (SignalType == COM_FLOAT64))
	{
		changedValue = (uint64)(*(const uint64*)SignalValuePtr);
	}
	/* @req [SWS_Com_00380] */
	else if(SignalType == COM_UINT8_N)
	{
		if(filterType == COM_ALWAYS)
		{
			/* PRQA S 2982 EOF # violate MISRA_2004_Rule_21.1:ignore warnning */
			ret = (boolean)TRUE;
		}
	}
	else
	{
		/* do nothing */
	}
	/**
	 * @req [SWS_Com_00602] use filtering mechanisms on sender side for Transmission Mode Conditions
	 */
	switch(filterType)
	{
		/* @req [SWS_COM_00813] */
		case COM_ALWAYS:
			ret = (boolean)TRUE;
			break;
		case COM_MASKED_NEW_EQUALS_X:
			if(ComFilter->ComFilterX == (changedValue & ComFilter->ComFilterMask))
			{
				ret = (boolean)TRUE;
			}
			break;
		case COM_MASKED_NEW_DIFFERS_X:
			if(ComFilter->ComFilterX != (changedValue & ComFilter->ComFilterMask))
			{
				ret = (boolean)TRUE;
			}
			break;
		case COM_MASKED_NEW_DIFFERS_MASKED_OLD:
#if(COM_NUMBER_OF_MASKNEWDIFFERMASKOLD_SIGNAL > 0u)
			Com_CalMaskedNewDiffersMaskedOldTMC(SignalType,changedValue, ComFilter,SignalBufferId ,&ret);
#endif
			break;
		case COM_NEW_IS_WITHIN:
			Com_CalWithinTMC(SignalType, changedValue, ComFilter, &ret);
			break;
		case COM_NEW_IS_OUTSIDE:
			Com_CalOutsideTMC(SignalType, changedValue, ComFilter, &ret);
			break;
			/* @req [SWS_Com_00231] */
#if(COM_NUMBER_OF_ONEEVERYNFILTERSIGNAL > 0u)
		case COM_ONE_EVERY_N:
			filterOffset = ComFilter->ComFilterOffset;
			filterPeriod = ComFilter->ComFilterPeriod;
			oneEveryNId = ComFilter->ComOneEveryNId;
			if(filterPeriod == Com_OneEveryNcnt[oneEveryNId])
			{
				Com_OneEveryNcnt[oneEveryNId] = 0u;
			}
			if(filterOffset == Com_OneEveryNcnt[oneEveryNId])
			{
				ret = TRUE;
			}
			Com_OneEveryNcnt[oneEveryNId]++;
			break;
#endif/* COM_NUMBER_OF_ONEEVERYNFILTERSIGNAL > 0 */
		default:
			break;
	}
return ret;
}
#endif



/*====================================================================================================*
 *                                          GLOBAL FUNCTIONS
 *====================================================================================================*/
/**
 * @brief			active or disable Pdu
 * @param[in]		TxPduId: Pdu identifier
 * @param[in]		initialize: It is forbidden to determine pdu activation
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
#if(COM_NUMBER_OF_TXIPDU > 0)
FUNC(void , COM_CODE)
Com_TxIpduControl(VAR(PduIdType, COM_VAR) TxPduId,VAR(boolean, COM_VAR) initialize)
{
#if(COM_NUMBER_OF_IPDUGROUP > 0u)
	Com_IpduGroupIdType refGroupNumber;
	Com_IpduGroupIdType groupIdx;
	Com_IpduGroupIdType refGroupId;
#endif
	boolean findActiveIpduGroup = (boolean)FALSE;
#if(COM_NUMBER_OF_IPDUGROUP > 0u)
	refGroupNumber = COM_CFG_TXPDU(TxPduId).ComIPduGroupsRefNumber;
	/* if the Pdu not included in any Ipdu Group,the state is always start */
	if (refGroupNumber > 0)
	{
		for(groupIdx = 0u; (groupIdx < refGroupNumber)\
    	&& ((boolean)FALSE == findActiveIpduGroup); groupIdx++)
    	{
        	refGroupId = COM_CFG_TXPDU(TxPduId).ComIPduGroupsRef[groupIdx];
        	if((boolean)TRUE == Com_IPduGroupIsActive[refGroupId])
        	{
            	findActiveIpduGroup = (boolean)TRUE;
            		if(!COM_CHECKTXPDUISENABLE(TxPduId))
            		{
            			/**
    					 * @req [SWS_Com_00787] I-PDU is started hall always initialize the following attributes
    					 * 						of this I-PDU
    					 */
            			Com_TxIPduIsActive[TxPduId] = (boolean)TRUE;
                		if((boolean)TRUE == initialize)
                		{
                			/**
                	 		* @req [SWS_Com_00222]
                			 * @req [SWS_Com_00228]
                			 */
                    		/* init the tx ipdu buffer,all signal buffer and init the TMC,TMS */
                    		Com_ResetTxPduBufferAndSignalBuffer(TxPduId);
                    		/**
                    		 * @req [SWS_Com_00223] choose Pdu transmit mode
                    		 */
                    		/* reset the Tx Time Period of I-PDUs in Periodic or MIXED transmission mode */
                    		if((boolean)TRUE == Com_TxIPduTMS[TxPduId])
    						{
                    			Com_TxIPduPeriodCnt[TxPduId] = \
    							COM_CFG_TXPDU(TxPduId).ComTxModeTrue->ComTxModeTimePeriod;
    							Com_TxIPduOffset[TxPduId] = \
    							COM_CFG_TXPDU(TxPduId).ComTxModeTrue->ComTxModeTimeOffset;
    						}
                		}
            		}
        	}
    	}
    	if((boolean)FALSE == findActiveIpduGroup)
    	{
        	if(COM_CHECKTXPDUISENABLE(TxPduId))
        	{
        		/* @req [SWS_Com_00714] */
        		Com_TxIPduIsActive[TxPduId] = (boolean)FALSE;
            	if((boolean)TRUE == Com_TxIPduIsTransmiting[TxPduId])
            	{
            		/**
            		 * @req [SWS_Com_00479] If an I-PDU is stopped by call to Com_IpduGroupControl,
            		 * 						invoke the configured ComErrorNotification
            		 */
                	Com_ErrorNotification(TxPduId);
                	#if(STD_ON == COM_CANCELLATION_SUPPORT)
                	if(TRUE == COM_CFG_TXPDU(TxPduId).ComIPduCancellationSupport)
                	{
                    	PduR_ComCancelTransmit(COM_CFG_TXPDU(TxPduId).PduRLayerId);
                	}
                	#endif
           		}
        		/**
        		 * @req [SWS_Com_00685] If an I-PDU is stopped by call to Com_IpduGroupControl,
        		 * 						invoke the configured ComErrorNotification
        		 */
            	Com_TxIPduDMTime[TxPduId] = 0u;
        	}
    	}
	}
#endif
}
#endif/*COM_IPDUGROUP_NUMBER > 0*/

/**
 * @brief			Update the TMC value of the signal
 * @param[in]		SignalId: signal identifier
 * @param[in]		PduId: Pdu identifier
 * @param[in]		TxSignalDataPtr: Reference to the signal data to be transmitted.
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void , COM_CODE)
Com_UpdateTMC(
	VAR(Com_SignalIdType, COM_VAR) SignalId,
	VAR(PduIdType, COM_VAR) PduId,
	P2CONST(void, AUTOMATIC, COM_APPL_CONST) TxSignalDataPtr
)
{
#if(COM_NUMBER_OF_TXIPDU > 0)
	#if(COM_TMCTXSIGNAL_NUMBER > 0u)
	Com_SignalIdType tmcId;
	Com_SignalType signalType;
	VAR(uint16, COM_VAR) bufferId;
#endif
	boolean oldTms;
	/**
	 * @req [SWS_Com_00677]
	 * @req [SWS_Com_00602] If the AUTOSAR COM module evaluates the TMC of a contributing signal as true
	 *  					then the AUTOSAR COM module shall evaluate the TMS as true.
	 */
	if(NULL_PTR != COM_CFG_TXSIGNAL(SignalId).ComFilter)
	{
#if(COM_TMCTXSIGNAL_NUMBER > 0u)
		signalType = COM_CFG_TXSIGNAL(SignalId).ComSignalType;
		bufferId = COM_CFG_TXSIGNAL(SignalId).ComSignalInitValueId;
		/**
		 * @req [SWS_Com_00694] calculate the TMC of the signal
		 */
		tmcId = COM_CFG_TXSIGNAL(SignalId).ComFilter->ComTMCBufferId;
		TxSignalTMCRunTime[tmcId] = Com_CalSignalTMC(TxSignalDataPtr,\
				COM_CFG_TXSIGNAL(SignalId).ComFilter, signalType, bufferId);
#endif
	}
	/**
	 * @req [SWS_Com_00603]
	 * @req [SWS_Com_00678]
	 * @req [SWS_Com_00679] If the AUTOSAR COM module evaluates a filter for a signal to true, the COM
	 * 						module shall place the value of that signal into old_value
	 */
	oldTms = Com_TxIPduTMS[PduId];
	Com_TxIPduTMS[PduId] = Com_CalPduTMS(PduId);
	if(oldTms == (boolean)FALSE)
	{
		Com_TxIPduMode[PduId] = COM_CFG_TXPDU(PduId).ComTxModeFalse->ComTxModeMode;
		if((boolean)TRUE == Com_TxIPduTMS[PduId])
		{
			Com_TxIPduMode[PduId] = COM_CFG_TXPDU(PduId).ComTxModeTrue->ComTxModeMode;
			/**
			 * @req [SWS_Com_00032]
			 * @req [SWS_Com_00239] If the TMS of an I-PDU evaluates to true, then the AUTOSAR COM module
			 * shall use the ComTxModeTrue
			 */
			/* If the TMS value changes, the reset cycle count */
			if(Com_TxIPduMode[PduId] == COM_PERIODIC)
			{
				/**
				 * @req [SWS_Com_00244]
				 * @req [SWS_Com_00495]
				 * @req [SWS_Com_00238] In each of the two TMS states, the rules for combination of transfer
				 * 						properties of signals and transmission modes
				 */
				Com_TxIPduPeriodCnt[PduId] = COM_CFG_TXPDU(PduId).ComTxModeTrue->ComTxModeTimeOffset;
			}
		}
	}
	else
	{
		Com_TxIPduMode[PduId] = COM_CFG_TXPDU(PduId).ComTxModeTrue->ComTxModeMode;
		if((boolean)FALSE == Com_TxIPduTMS[PduId])
		{
			Com_TxIPduMode[PduId] = COM_CFG_TXPDU(PduId).ComTxModeFalse->ComTxModeMode;
			/**
			 * @req [SWS_Com_00799]
			 * @req [SWS_Com_00495]
			 * @req [SWS_Com_00239] If the TMS of an I-PDU evaluates to false, then the AUTOSAR COM module
			 * 						shall use the ComTxModeFalse
			 */
			if(Com_TxIPduMode[PduId] == COM_PERIODIC)
			{
				/**
				 * @req [SWS_Com_00244]
				 * @req [SWS_Com_00238] In each of the two TMS states, the rules for combination of transfer
				 *  					properties of signals and transmission modes
				 */
				Com_TxIPduPeriodCnt[PduId] = COM_CFG_TXPDU(PduId).ComTxModeFalse->ComTxModeTimeOffset;
			}
		}
	}
#endif
	return;
}

/**
 * @brief			Calculate whether the value of the signal changes
 * @param[in]		SignalId: signal identifier
 * @param[in]		SignalNewDataPtr: Reference to the signal data to be transmitted.
 * @param[out]		/
 * @param[in/out]	/
 * @return			boolean
 * @retval			TRUE
 * 					FALSE
 */
FUNC(boolean , COM_CODE)
Com_CalSignalValueIsChange(
	VAR(uint16, COM_VAR) SignalId,
	P2CONST(void, AUTOMATIC, COM_APPL_CONST) SignalNewDataPtr
)
{
	boolean ret = (boolean)FALSE;
#if(COM_NUMBER_OF_8BITSIGNAL > 0u)
	uint16 cnt;
#endif
	Com_SignalType signalType = COM_CFG_TXSIGNAL(SignalId).ComSignalType;
	uint16 initValueId = COM_CFG_TXSIGNAL(SignalId).ComSignalInitValueId;
	if(signalType == COM_BOOLEAN)
	{
#if(COM_NUMBER_OF_BOOLSIGNAL > 0u)
		if(Com_BoolSignalRuntimeValue[initValueId] != *((const boolean*)(SignalNewDataPtr)))
		{
			Com_BoolSignalRuntimeValue[initValueId] = *((const boolean*)(SignalNewDataPtr));
		}
		ret = (boolean)TRUE;
#endif
	}
	else if((signalType == COM_UINT8) || (signalType == COM_SINT8))
	{
#if(COM_NUMBER_OF_8BITSIGNAL > 0u)
		if(Com_8BitSignalRuntimeValue[initValueId] != *((const uint8*)(SignalNewDataPtr)))
		{
			Com_8BitSignalRuntimeValue[initValueId] = *((const uint8*)(SignalNewDataPtr));
			ret =(boolean) TRUE;
		}
#endif
	}
	else if((signalType == COM_UINT16) || (signalType == COM_SINT16))
	{
#if(COM_NUMBER_OF_16BITSIGNAL > 0u)
		if(Com_16BitSignalRuntimeValue[initValueId] != *((const uint16*)(SignalNewDataPtr)))
		{
			Com_16BitSignalRuntimeValue[initValueId] = *((const uint16*)(SignalNewDataPtr));
			ret =(boolean) TRUE;
		}
#endif
	}
	else if(signalType == COM_UINT8_N)
	{
#if(COM_NUMBER_OF_8BITSIGNAL > 0u)
		for(cnt =(uint16)0;cnt < COM_CFG_TXSIGNAL(SignalId).ComSignalLength; cnt ++)
		{
			/* PRQA S 0492 EOF # violate MISRA_2004_Rule_17.4:ignore warnning */
			if(Com_8BitSignalRuntimeValue[initValueId + cnt] != ((const uint8*)SignalNewDataPtr)[cnt])
			{
				Com_8BitSignalRuntimeValue[initValueId + cnt] = ((const uint8*)SignalNewDataPtr)[cnt];
				ret = (boolean)TRUE;
			}
		}
#endif
	}
	else if((signalType == COM_UINT32) || (signalType == COM_SINT32) || (signalType == COM_FLOAT32))
	{
#if(COM_NUMBER_OF_32BITSIGNAL > 0u)
		if(Com_32BitSignalRuntimeValue[initValueId] != *((const uint32*)(SignalNewDataPtr)))
		{
			Com_32BitSignalRuntimeValue[initValueId] = *((const uint32*)(SignalNewDataPtr));
			ret =(boolean) TRUE;
		}
#endif
	}
	else if((signalType == COM_UINT64) || (signalType == COM_SINT64) || (signalType == COM_FLOAT64))
	{
#if(COM_NUMBER_OF_64BITSIGNAL > 0u)
		if(Com_64BitSignalRuntimeValue[initValueId] != *((const uint64*)(SignalNewDataPtr)))
		{
			Com_64BitSignalRuntimeValue[initValueId] = *((const uint64*)(SignalNewDataPtr));
			ret = (boolean)TRUE;
		}
#endif
	}
	else
	{
		/* do nothing */
	}
	return ret;
}

/**
 * @brief			Calculate whether the value of the group signal changes
 * @param[in]		GroupSignalId: group signal identifier
 * @param[in]		SignalNewDataPtr: Reference to the signal data to be transmitted.
 * @param[out]		/
 * @param[in/out]	/
 * @return			boolean
 * @retval			TRUE
 * 					FALSE
 */
FUNC(boolean , COM_CODE)Com_CalGroupSignalValueIsChange
(
	VAR(uint16, COM_VAR) GroupSignalId,
	P2CONST(void, AUTOMATIC, COM_APPL_CONST) SignalNewDataPtr
)
{
	boolean ret = (boolean)FALSE;
#if(COM_NUMBER_OF_8BITSIGNAL > 0u)
	uint16 cnt;
#endif
	Com_SignalType signalType = COM_CFG_TXGROUPSIGNAL(GroupSignalId).ComSignalType;
	uint16 initValueId = COM_CFG_TXGROUPSIGNAL(GroupSignalId).ComSignalInitValueId;
	if(signalType == COM_BOOLEAN)
	{
#if(COM_NUMBER_OF_BOOLSIGNAL > 0u)
		if(Com_BoolSignalRuntimeValue[initValueId] != *((const boolean*)(SignalNewDataPtr)))
		{
			Com_BoolSignalRuntimeValue[initValueId] = *((const boolean*)(SignalNewDataPtr));
		}
		ret = (boolean)TRUE;
#endif
	}
	else if((signalType == COM_UINT8) || (signalType == COM_SINT8))
	{
#if(COM_NUMBER_OF_8BITSIGNAL > 0u)
		if(Com_8BitSignalRuntimeValue[initValueId] != *((const uint8*)(SignalNewDataPtr)))
		{
			Com_8BitSignalRuntimeValue[initValueId] = *((const uint8*)(SignalNewDataPtr));
			ret =(boolean) TRUE;
		}
#endif
	}
	else if((signalType == COM_UINT16) || (signalType == COM_SINT16))
	{
#if(COM_NUMBER_OF_16BITSIGNAL > 0u)
		if(Com_16BitSignalRuntimeValue[initValueId] != *((const uint16*)(SignalNewDataPtr)))
		{
			Com_16BitSignalRuntimeValue[initValueId] = *((const uint16*)(SignalNewDataPtr));
			ret =(boolean) TRUE;
		}
#endif
	}
	else if(signalType == COM_UINT8_N)
	{
#if(COM_NUMBER_OF_8BITSIGNAL > 0u)
		for(cnt =(uint16)0;cnt < COM_CFG_TXGROUPSIGNAL(GroupSignalId).ComSignalLength; cnt ++)
		{
			if(Com_8BitSignalRuntimeValue[initValueId + cnt] != ((const uint8*)SignalNewDataPtr)[cnt])
			{
				Com_8BitSignalRuntimeValue[initValueId + cnt] = ((const uint8*)SignalNewDataPtr)[cnt];
				ret = (boolean)TRUE;
			}
		}
#endif
	}
	else if((signalType == COM_UINT32) || (signalType == COM_SINT32) || (signalType == COM_FLOAT32))
	{
#if(COM_NUMBER_OF_32BITSIGNAL > 0u)
		if(Com_32BitSignalRuntimeValue[initValueId] != *((const uint32*)(SignalNewDataPtr)))
		{
			Com_32BitSignalRuntimeValue[initValueId] = *((const uint32*)(SignalNewDataPtr));
			ret =(boolean) TRUE;
		}
#endif
	}
	else if((signalType == COM_UINT64) || (signalType == COM_SINT64) || (signalType == COM_FLOAT64))
	{
#if(COM_NUMBER_OF_64BITSIGNAL > 0u)
		if(Com_64BitSignalRuntimeValue[initValueId] != *((const uint64*)(SignalNewDataPtr)))
		{
			Com_64BitSignalRuntimeValue[initValueId] = *((const uint64*)(SignalNewDataPtr));
			ret = (boolean)TRUE;
		}
#endif
	}
	else
	{
		/* do nothing */
	}
	return ret;
}

/**
 * @brief			set Tx dynamic signal to signalbuffer,return the buffer value is changed or not
 * @param[in]		PduId: Pdu identify
 * @param[in]		InitValueId: The current signal is in the position of the same type of signal array
 * @param[in]		SignalNewDataPtr: Reference to the signal data to be transmitted.
 * @param[in]		Length: length of signal
 * @param[out]		/
 * @param[in/out]	/
 * @return			boolean
 * @retval			TRUE
 * 					FALSE
 */
FUNC(boolean , COM_CODE)
Com_CalDynChange(
	VAR(PduIdType, COM_VAR) PduId,
	VAR(uint16, COM_VAR) InitValueId,
	P2CONST(void, AUTOMATIC, COM_APPL_CONST) SignalNewDataPtr,
	VAR(uint16, COM_VAR) Length
)
{
	boolean rtn = (boolean)FALSE;
	uint16 cnt;
#if(COM_NUMBER_OF_TXIPDU > 0)
	uint16 oldSignalLength;
#endif
	/* Copy Uint8N signal value one byte by one */
	for(cnt = 0u; cnt < Length; cnt++)
	{
#if(COM_NUMBER_OF_8BITSIGNAL > 0u)
		if(((const uint8*)SignalNewDataPtr)[cnt] != Com_8BitSignalRuntimeValue[InitValueId + cnt])
		{
			Com_8BitSignalRuntimeValue[InitValueId + cnt] = ((const uint8*)SignalNewDataPtr)[cnt];
			rtn = (boolean)TRUE;
		}
#endif
	}
	if((boolean)FALSE == rtn)
	{
#if(COM_NUMBER_OF_TXIPDU > 0)
		oldSignalLength = COM_CFG_TXPDU(PduId).ComIPduInitLength - \
				COM_CFG_TXPDU(PduId).IPduNoDynSignalLength;
		if(oldSignalLength != Length)
		{
			rtn =(boolean) TRUE;
		}
#endif
	}
	return rtn;
}

/**
 * @brief			pack the Tx signal into ipdu Tx buffer
 * @param[in]		SignalId: signal identify
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void , COM_CODE)
Com_PackSignal(VAR(Com_SignalIdType, COM_VAR) SignalId)
{
#if(COM_NUMBER_OF_TXIPDU)
	uint8 mask;
	uint16 needCopyBits;
	PduLengthType bytePos;
	uint8 bitSize;
	uint8 bitOffset;
	uint16 remainBits;
	uint16 initValueId;
	uint16 pduBufferIndex;
#if(COM_NUMBER_OF_8BITSIGNAL > 0u)
	uint16 signalLength;
	uint16 index;
#endif
	uint64 signalValue= 0u;
	uint64 oldValue;
	PduIdType refPduId;
	Com_SignalType signalType;
	Com_SignalEndiannessType signalEndianness;
	refPduId = COM_CFG_TXSIGNAL(SignalId).ComIpduRefIndex;
	bitSize = COM_CFG_TXSIGNAL(SignalId).ComBitSize;
	signalType = COM_CFG_TXSIGNAL(SignalId).ComSignalType;
	pduBufferIndex = COM_CFG_TXPDU(refPduId).ComTxIPduBufIndex;
	initValueId = COM_CFG_TXSIGNAL(SignalId).ComSignalInitValueId;
	bytePos = (uint32)(COM_CFG_TXSIGNAL(SignalId).ComBitPosition >> 3u);
	bitOffset = (uint8)(COM_CFG_TXSIGNAL(SignalId).ComBitPosition & 0x07u);
	if(COM_BOOLEAN == signalType)
	{
#if(COM_NUMBER_OF_BOOLSIGNAL > 0u)
		signalValue = (uint64)(Com_BoolSignalRuntimeValue[initValueId]);
#endif
	}
	else if(COM_UINT8_N == signalType)
	{
#if(COM_NUMBER_OF_8BITSIGNAL > 0u)
		signalLength = COM_CFG_TXSIGNAL(SignalId).ComSignalLength;
		for(index= 0u; index < signalLength; index++)
		{
			signalValue |= (uint64)((uint64)Com_8BitSignalRuntimeValue[initValueId + index] \
					<< (8u * index));
		}
#endif
	}
	else if((signalType == COM_UINT8) || (signalType == COM_SINT8))
	{
#if(COM_NUMBER_OF_8BITSIGNAL > 0u)
		signalValue = (uint64)(Com_8BitSignalRuntimeValue[initValueId]);
#endif
	}
	else if((signalType == COM_UINT16) || (signalType == COM_SINT16))
	{
#if(COM_NUMBER_OF_16BITSIGNAL > 0u)
		signalValue = (uint64)(Com_16BitSignalRuntimeValue[initValueId]);
#endif
	}
	else if((signalType == COM_UINT32) || (signalType == COM_SINT32) || (signalType == COM_FLOAT32))
	{
#if(COM_NUMBER_OF_32BITSIGNAL > 0u)
		signalValue = (uint64)(Com_32BitSignalRuntimeValue[initValueId]);
#endif
	}
	else if((signalType == COM_UINT64) || (signalType == COM_SINT64) || (signalType == COM_FLOAT64))
	{
#if(COM_NUMBER_OF_64BITSIGNAL > 0u)
		signalValue = Com_64BitSignalRuntimeValue[initValueId];
#endif
	}
	else
	{
		/* do nothing */
	}
	signalEndianness = COM_CFG_TXSIGNAL(SignalId).ComSignalEndianness;
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
			/*  S 4397 # violate MISRA_2004_Rule_21.1:ignore warnning */
			mask = (uint8)(~(uint8)(((uint8)((uint8)1u << bitSize) - 1u) << bitOffset));
			needCopyBits = bitSize;
		}

		Com_TxIPduRuntimeValue[pduBufferIndex + bytePos] = \
				(Com_TxIPduRuntimeValue[pduBufferIndex + bytePos] & mask) | ((uint8)signalValue);
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
				Com_TxIPduRuntimeValue[pduBufferIndex + bytePos] = (uint8)signalValue;
				needCopyBits += 8u;
			}
			else
			{
				mask = (uint8)(0xFFu << remainBits);
				Com_TxIPduRuntimeValue[pduBufferIndex + bytePos] = \
					(Com_TxIPduRuntimeValue[pduBufferIndex + bytePos] & mask) | (uint8)signalValue;
				needCopyBits += remainBits;
			}
		}
	}
#endif
	return;
}

/**
 * @brief			pack the Tx signal group into ipdu Tx buffer
 * @param[in]		SignalGroupId: signal group identify
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
#if(COM_NUMBER_OF_TXSIGNALGROUP > 0u)
FUNC(void,COM_CODE)
Com_PackSignalGroup(Com_SignalGroupIdType SignalGroupId)
{
    Com_SignalIdType groupSignalNumber;
    Com_SignalIdType cnt;
    Com_SignalIdType groupSignalId;
#if(COM_TMCTXGROUPSIGNAL_NUMBER > 0u)
    Com_SignalIdType groupSignalTMCId;
#endif
    uint16 length;
    PduIdType txPduId;
    uint32 bitPosition;
    uint16 initValueId;
    groupSignalNumber = COM_CFG_TXSIGNALGROUP(SignalGroupId).ComGroupSignalNumber;
    for(cnt = 0u;cnt < groupSignalNumber;cnt++)
    {
        groupSignalId = COM_CFG_TXSIGNALGROUP(SignalGroupId).ComTxGroupSignalId[cnt];
        if(NULL_PTR != COM_CFG_TXGROUPSIGNAL(groupSignalId).ComFilter)
        {
#if(COM_TMCTXGROUPSIGNAL_NUMBER > 0u)
        	groupSignalTMCId = COM_CFG_TXGROUPSIGNAL(groupSignalId).ComFilter->ComTMCBufferId;
            TxSignalTMCRunTime[groupSignalTMCId] = TxGroupSignalTMCBuffer[groupSignalTMCId];
#endif
        }
        if(COM_UINT8_DYN == COM_CFG_TXGROUPSIGNAL(groupSignalId).ComSignalType)
        {
            txPduId = COM_CFG_TXSIGNALGROUP(SignalGroupId).ComIpduRefIndex;
            bitPosition = COM_CFG_TXGROUPSIGNAL(groupSignalId).ComBitPosition;
            initValueId = COM_CFG_TXGROUPSIGNAL(groupSignalId).ComSignalInitValueId;
            length = Com_TxSignalGroupState[SignalGroupId].DynamicSignalLength;
            Com_PackDynSignal(txPduId,bitPosition,initValueId,length);
        }
        else
        {
            Com_PackGroupSignal(groupSignalId);
        }
    }
    return;
}
#endif

/**
 * @brief			send Tx signal handle
 * @param[in]		SignalId: signal identify
 * @param[in]		ValueChanged: Does the value of the signal change
 * @param[out]		/
 * @param[in/out]	/
 * @return			uint8
 * @retval			/
 */
FUNC(uint8 , COM_CODE)
Com_HandleTxSignal(VAR(Com_SignalIdType, COM_VAR) SignalId, VAR(boolean, COM_VAR) ValueChanged)
{
	uint8 retValue;
	#if(COM_NUMBER_OF_TXIPDU > 0)
	uint16 pduBufferIdx;
	uint16 pduLength;
	PduInfoType pduInfo;
	boolean ret = (boolean)TRUE;
	uint16 rptNum;
	boolean dmNeedStart = (boolean)FALSE;
	boolean signalNeedMonitor;
	PduIdType pduId = COM_CFG_TXSIGNAL(SignalId).ComIpduRefIndex;
	/* @req [SWS_Com_00333]
	 * @req [SWS_Com_00481] If the configuration parameter ComTimeout for a signal or signal group is
	 * 						omitted or configured to 0, the AUTOSAR COM module shall not monitor this
	 * 						signal or signal group
	 */
	if(COM_CFG_TXSIGNAL(SignalId).ComTimeout != 0u)
	{
		signalNeedMonitor =(boolean) TRUE;
	}
	else
	{
		signalNeedMonitor =(boolean) FALSE;
	}

	/* the signal config timeout,the DM timer isn't start by other signals,
	 * the Tx mode is not NONE.then start the DM timer here */
	if((0u == Com_TxIPduDMTime[pduId]) && ((boolean)TRUE == signalNeedMonitor) \
			&& (COM_NONE != Com_TxIPduMode[pduId]))
	{
		Com_TxIPduDMTime[pduId] = COM_CFG_TXPDU(pduId).ComTxIpduDM;
		dmNeedStart = (boolean)TRUE;
	}
	/**
	 * @req [SWS_Com_00221] invoke the pdu callout notification if the pdu have config */
	if(NULL_PTR != COM_CFG_TXPDU(pduId).ComIPduCallout)
	{
		pduBufferIdx = COM_CFG_TXPDU(pduId).ComTxIPduBufIndex;
		pduLength = COM_CFG_TXPDU(pduId).ComIPduInitLength;
		pduInfo.SduDataPtr = &Com_TxIPduRuntimeValue[pduBufferIdx];
		pduInfo.SduLength = (PduLengthType)pduLength + \
				(PduLengthType)COM_CFG_TXPDU(pduId).MetaDataLength;
		ret = COM_CFG_TXPDU(pduId).ComIPduCallout(pduId, &pduInfo);
	}
	if((boolean)TRUE == ret)
	{
		/**
		 * @req [SWS_Com_00330]
		 * @req [SWS_Com_00495]
		 * @req [SWS_Com_00582] When a call to Com_SendSignal or Com_SendSignalGroup results into a
		 * 						change of the transmission mode of a started I-PDU to the transmission
		 * 						mode PERIODIC or MIXED, then the AUTOSAR COM module shall start the new
		 * 						transmission cycle with a call to PduR_ComTransmit within the next main
		 * 						function at the latest.
		 */
		if((COM_DIRECT == Com_TxIPduMode[pduId]) || (COM_MIXED == Com_TxIPduMode[pduId]))
		{
			if((boolean)TRUE == Com_TxIPduTMS[pduId])
			{
				rptNum = COM_CFG_TXPDU(pduId).ComTxModeTrue->ComTxModeNumberOfRepetitions;
			}
			else
			{
				rptNum = COM_CFG_TXPDU(pduId).ComTxModeFalse->ComTxModeNumberOfRepetitions;
			}
			/**
			 * @req [SWS_Com_00279] If a new send request is received,cancel the outstanding
			 * 						transmission repetitions and start processing the new request within
			 * 						the next main function at the latest
			 */
			Com_HandleTxSignalProperty(pduId,COM_CFG_TXSIGNAL(SignalId).ComTransferProperty,\
					ValueChanged,dmNeedStart,signalNeedMonitor,rptNum);
		}
		else
		{
			Com_TxIPduRepetitionPeriod[pduId] = 0u;
			Com_TxIPduRepeatNum[pduId] = 0u;
		}
		retValue = (uint8)E_OK;
	}
	else
	{
		retValue = COM_SERVICE_NOT_AVAILABLE;
	}
#else
	retValue = (uint8)E_NOT_OK;
#endif
	return retValue;
}

/**
 * @brief			send Tx signal handle
 * @param[in]		PduId: Pdu identify
 * @param[in]		SignalProperty: Sending properties of a signal
 * @param[in]		ValueChanged: Does the value of the signal change
 * @param[in]		DmStart: Whether to open the death limit monitoring
 * @param[in]		SignalDM: The signal corresponds to the death limit monitoring
 * @param[in]		RptNum: The number of times you need to repeat
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void , COM_CODE)
Com_HandleTxSignalProperty
(
	VAR(PduIdType, COM_VAR) PduId,
	VAR(Com_TransferPropertyType, COM_VAR) SignalProperty,
	VAR(boolean, COM_VAR) ValueChanged,
	VAR(boolean, COM_VAR) DmStart,
	VAR(boolean, COM_VAR) SignalDM,
	VAR(uint16, COM_VAR) RptNum
)
{
#if(COM_NUMBER_OF_TXIPDU > 0)
	/**
	 * @req [SWS_Com_00630] If the updated signal,has the ComTransferProperty PENDING, then the function
	 * 						Com_SendDynSignal shall not perform a transmission of the I-PDU associated
	 * 						with the signal.
	 */
	if(SignalProperty == COM_TRIGGERED)
	{
		Com_TxIPduRepeatNum[PduId] = RptNum;
		Com_TxIPduRepetitionPeriod[PduId] = 0u;
		if((RptNum > 1u) && ((boolean)FALSE == DmStart) && ((boolean)TRUE == SignalDM))
		{
			Com_TxIPduDMTime[PduId] = COM_CFG_TXPDU(PduId).ComTxIpduDM;
		}
	}
	else if(SignalProperty == COM_TRIGGERED_ON_CHANGE)
	{
		/**
		 * @req [SWS_Com_00734] ComTxModeMode is DIRECT or MIXED, initiate ComTxModeNumberOfRepetitions
		 * 						plus one transmissions of the assigned I-PDU if the new sent signal
		 * 						differs to the locally stored (last sent or init) in length or value
		 */
		if((boolean)TRUE == ValueChanged)
		{
			Com_TxIPduRepeatNum[PduId] = RptNum;
			Com_TxIPduRepetitionPeriod[PduId] = 0u;
			if((RptNum > 1u) && ((boolean)FALSE == DmStart) && ((boolean)TRUE == SignalDM))
			{
				Com_TxIPduDMTime[PduId] = COM_CFG_TXPDU(PduId).ComTxIpduDM;
			}
		}
	}
	/**
	 * @req [SWS_Com_00768] ComTxModeMode is DIRECT or MIXED,  one transmission of the assigned I-PDU
	 * 						if the new sent signal differs to the locally stored (last sent or init)
	 * 						in length or value
	 */
	else if(SignalProperty == COM_TRIGGERED_ON_CHANGE_WITHOUT_REPETITION)
	{
		if((boolean)TRUE == ValueChanged)
		{
			Com_TxIPduRepeatNum[PduId] = 1u;
			Com_TxIPduRepetitionPeriod[PduId] = 0u;
		}
	}
	/**
	 * @req [SWS_Com_00767] ComTxModeMode is DIRECT or MIXED, initiate ComTxModeNumberOfRepetitions
	 * 						plus one transmissions of the assigned I-PDU
	 */
	else if(SignalProperty == COM_TRIGGERED_WITHOUT_REPETITION)
	{
		Com_TxIPduRepeatNum[PduId] = 1u;
		Com_TxIPduRepetitionPeriod[PduId] = 0u;
	}
	else
	{
		/* do nothing */
	}
#endif
}

/**
 * @brief			Pack the dynamic signal into the pdu buffer
 * @param[in]		PduId: Pdu identify
 * @param[in]		BitPosition: The signal is the starting position in pdu
 * @param[in]		InitValueId: The current signal is located in the same array of the same signal
 * @param[in]		SignalLength: length of signal
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void , COM_CODE)
Com_PackDynSignal(
	VAR(PduIdType, COM_VAR) PduId,
	VAR(uint32, COM_VAR) BitPosition,
	VAR(uint16, COM_VAR) InitValueId,
	VAR(uint16, COM_VAR) SignalLength
)
{
#if(COM_NUMBER_OF_TXIPDU > 0u)
	#if(COM_NUMBER_OF_8BITSIGNAL > 0u)
	uint16 ipduBufferIndex;
	uint16 cnt;
	ipduBufferIndex = COM_CFG_TXPDU(PduId).ComTxIPduBufIndex;
	for(cnt = 0u; cnt < SignalLength; cnt++)
	{
		Com_TxIPduRuntimeValue[ipduBufferIndex + (BitPosition >> 3u) + cnt] = \
		Com_8BitSignalRuntimeValue[(InitValueId + SignalLength) - (1u + cnt)];
	}
#endif
#endif
	return;
}



/**
 * @brief			It is called in case the transmission is not possible because the corresponding
 * 					I-PDU group is stopped
 * @param[in]		PduId: Pdu identify
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void,COM_CODE)
Com_ErrorNotification(VAR(PduIdType, COM_VAR) PduId)
{
	uint16 cnt;
	Com_SignalIdType signalNumber;
	Com_SignalIdType signalId;
	Com_SignalGroupIdType signalGroupNumber;
	Com_SignalGroupIdType signalGroupId;
	signalNumber = Com_ConfigPtr->ComTxIPdu[PduId].ComIPduSignalsRefNumber;
	for(cnt = (uint16)0; cnt < signalNumber ; cnt ++)
	{
		signalId = COM_CFG_TXPDU(PduId).ComIPduSignalsRef[cnt];
		/*If the signal is configured for error notification*/
		if(NULL_PTR != COM_CFG_TXSIGNAL(signalId).ComErrorNotification)
		{
			COM_CFG_TXSIGNAL(signalId).ComErrorNotification();
		}
	}
	signalGroupNumber = COM_CFG_TXPDU(PduId).ComIPduSignalGroupsRefNumber;
	for(cnt = (uint16)0; cnt < signalGroupNumber; cnt ++)
	{
		signalGroupId = COM_CFG_TXPDU(PduId).ComIPduSignalGroupsRef[cnt];
		if(NULL_PTR != COM_CFG_TXSIGNALGROUP(signalGroupId).ComErrorNotification)
		{
			COM_CFG_TXSIGNALGROUP(signalGroupId).ComErrorNotification();
		}
	}
}


/**
 * @brief			Pack the counter value in the pdu buffer
 * @param[in]		PduId: Pdu identify
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void,COM_CODE)
Com_CalCounterValue(VAR(PduIdType, COM_VAR) PduId)
{
#if(COM_NUMBER_OF_TXIPDU > 0)
	uint8 counter;
	uint16 pduBufIdx;
	uint32 bitPosition;
	uint8 bitSize;
	counter = Com_TxIPduData[PduId].TxIpduCounter;
	pduBufIdx = COM_CFG_TXPDU(PduId).ComTxIPduBufIndex;
	bitPosition = COM_CFG_TXPDU(PduId).ComIPduCounter->ComIpduCounterStartPosition;
	bitSize = COM_CFG_TXPDU(PduId).ComIPduCounter->ComIpduCounterSize;
	counter = counter << ((uint8)bitPosition & 0x07u);
	/* Clear corresponding bits in IPdu */
	Com_TxIPduRuntimeValue[pduBufIdx + (uint16)(bitPosition >> 3u)] \
		&= (0xFFu >> (8u - ((uint8)bitPosition & 0x07u))) \
			| (uint8)(0xFFu << (((uint8)bitPosition & 0x07u) + bitSize));
	/* write corresponding bits to IPdu buffer */
	Com_TxIPduRuntimeValue[pduBufIdx + (uint16)(bitPosition >> 3u)] \
		|= (0xFFu >> (8u - (((uint8)bitPosition & 0x07u) + bitSize))) & (counter);
#endif
	return;
}


/**
 * @brief			clear all signal group/signal/dest description signal update bit of the Tx Pdu
 * @param[in]		TxIpduId: Pdu identify
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void,COM_CODE)
Com_ClearUpdates(VAR(PduIdType, COM_VAR) TxIpduId)
{
#if(COM_NUMBER_OF_TXIPDU)
	uint16 cnt;
    Com_SignalGroupIdType signalGroupNumber;
    Com_SignalIdType signalNumber;
    uint16 pduBufIdx;
    uint32 updateBitPosition;
    uint16 refSignalGroupId ;
    uint16 refSignalId ;
    signalNumber = COM_CFG_TXPDU(TxIpduId).ComIPduSignalsRefNumber;
    signalGroupNumber = COM_CFG_TXPDU(TxIpduId).ComIPduSignalGroupsRefNumber;
    pduBufIdx = COM_CFG_TXPDU(TxIpduId).ComTxIPduBufIndex;
    for(cnt = 0u;cnt < signalNumber;cnt++)
    {
    	refSignalId = COM_CFG_TXPDU(TxIpduId).ComIPduSignalsRef[cnt];
    	updateBitPosition = COM_CFG_TXSIGNAL(refSignalId).ComUpdateBitPosition;
        if(updateBitPosition != 0xffffffffU)
        {
            Com_TxIPduRuntimeValue[pduBufIdx + (updateBitPosition >> 3u)] \
				&= (uint8)(~(uint8)(0x01u << ((updateBitPosition) & 0x07u)));
        }
    }
    for(cnt = 0u;cnt < signalGroupNumber;cnt++)
    {
    	refSignalGroupId = COM_CFG_TXPDU(TxIpduId).ComIPduSignalGroupsRef[cnt];
    	updateBitPosition = COM_CFG_TXSIGNALGROUP(refSignalGroupId).ComUpdateBitPosition;
        if(updateBitPosition != 0xffffffffU)
        {
            Com_TxIPduRuntimeValue[pduBufIdx + (updateBitPosition >> 3u)] \
				&=(uint8)(~(uint8)(0x01u << ((updateBitPosition) & 0x07u)));
        }
    }
#endif
    return;
}


/**
 * @brief			Tx notification for all signals/signal groups of the Tx Pdu
 * @param[in]		pduId: Pdu identify
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void,COM_CODE)
Com_Confirmation(VAR(PduIdType, COM_VAR) PduId)
{
	Com_SignalIdType signalNumber;
	Com_SignalGroupIdType siganlGroupNumber;
	uint16 cnt;
	Com_SignalIdType signalId;
	Com_SignalGroupIdType signalGroupId;
	signalNumber = COM_CFG_TXPDU(PduId).ComIPduSignalsRefNumber;
	for(cnt = 0u;cnt < signalNumber;cnt++)
	{
		signalId = COM_CFG_TXPDU(PduId).ComIPduSignalsRef[cnt];
		if(NULL_PTR != COM_CFG_TXSIGNAL(signalId).ComNotification)
		{
			COM_CFG_TXSIGNAL(signalId).ComNotification();
		}
	}
	siganlGroupNumber = COM_CFG_TXPDU(PduId).ComIPduSignalGroupsRefNumber;
	for(cnt = 0u;cnt < siganlGroupNumber;cnt++)
	{
		signalGroupId = COM_CFG_TXPDU(PduId).ComIPduSignalGroupsRef[cnt];
		if(NULL_PTR != COM_CFG_TXSIGNALGROUP(signalGroupId).ComNotification)
		{
			COM_CFG_TXSIGNALGROUP(signalGroupId).ComNotification();
		}
	}
	return;
}


/**
 * @brief			tx pdu DM timeout notification
 * @param[in]		pduId: Pdu identify
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void,COM_CODE)
Com_TimeOutNotification(VAR(PduIdType, COM_VAR) PduId)
{
	Com_SignalIdType signalNumber;
	Com_SignalGroupIdType siganlGroupNumber;
	uint16 cnt;
	Com_SignalIdType signalId;
	Com_SignalGroupIdType signalGroupId;
	signalNumber = COM_CFG_TXPDU(PduId).ComIPduSignalsRefNumber;
	for(cnt = 0u;cnt < signalNumber;cnt++)
	{
		signalId = COM_CFG_TXPDU(PduId).ComIPduSignalsRef[cnt];
		if(NULL_PTR != COM_CFG_TXSIGNAL(signalId).ComTimeoutNotification)
		{
			COM_CFG_TXSIGNAL(signalId).ComTimeoutNotification();
		}
	}
	siganlGroupNumber = COM_CFG_TXPDU(PduId).ComIPduSignalGroupsRefNumber;
	for(cnt = 0u;cnt < siganlGroupNumber;cnt++)
	{
		signalGroupId = COM_CFG_TXPDU(PduId).ComIPduSignalGroupsRef[cnt];
		if(NULL_PTR != COM_CFG_TXSIGNALGROUP(signalGroupId).ComTimeoutNotification)
		{
			COM_CFG_TXSIGNALGROUP(signalGroupId).ComTimeoutNotification();
		}
	}
	return;
}

/**
 * @brief			Processing of pdu with direct sending properties
 * @param[in]		pduId: Pdu identify
 * @param[in]		txMDT: Does the current pdu send delay
 * @param[out]		/
 * @param[in/out]	/
 * @return			boolean
 * @retval			TRUE
 * 					FALSE
 */
FUNC(boolean,COM_CODE)
Com_TxDirect(VAR(PduIdType, COM_VAR) PduId, VAR(boolean, COM_VAR) txMDT)
{
	boolean ret = (boolean)FALSE;
#if(COM_NUMBER_OF_TXIPDU > 0)
	/*@req [SWS_Com_00305]*/
	if(Com_TxIPduRepetitionPeriod[PduId] > 0u)
	{
		Com_TxIPduRepetitionPeriod[PduId]--;
	}
	if((0u == Com_TxIPduRepetitionPeriod[PduId]) && (Com_TxIPduRepeatNum[PduId] > 0U) \
			&& ((boolean)TRUE != Com_TxIPduIsTransmiting[PduId]))
	{
		/* delay transmit of the MDT */
		if((boolean)TRUE == txMDT)
		{
			Com_TxIPduNeedDelay[PduId] =(boolean) TRUE;
		}
		else
		{
			ret = (boolean)TRUE;
		}
		/* reset transmit period */
		if((boolean)TRUE == Com_TxIPduTMS[PduId])
		{
			Com_TxIPduRepetitionPeriod[PduId] = \
					COM_CFG_TXPDU(PduId).ComTxModeTrue->ComTxModeRepetitionPeriod;
		}
		else
		{
			Com_TxIPduRepetitionPeriod[PduId] = \
					COM_CFG_TXPDU(PduId).ComTxModeFalse->ComTxModeRepetitionPeriod;
		}
	}
	if((boolean)FALSE == txMDT)
	{
		if((boolean)TRUE == Com_TxIPduNeedDelay[PduId])
		{
			ret = (boolean)TRUE;
		}
	}
#endif
	return ret;
}

/**
 * @brief			Processing of pdu with Periodic sending properties
 * @param[in]		pduId: Pdu identify
 * @param[in]		txMDT: Does the current pdu send delay
 * @param[out]		/
 * @param[in/out]	/
 * @return			boolean
 * @retval			TRUE
 * 					FALSE
 */
FUNC(boolean,COM_CODE)
Com_TxPeriodic(VAR(PduIdType, COM_VAR) PduId, VAR(boolean, COM_VAR) txMDT)
{
	boolean ret = (boolean)FALSE;
#if(COM_NUMBER_OF_TXIPDU > 0)
	if(Com_TxIPduPeriodCnt[PduId] > 0u)
	{
		Com_TxIPduPeriodCnt[PduId]--;
	}
	if(0u == Com_TxIPduPeriodCnt[PduId])
	{
		/* delay transmit of the MDT */
		if((boolean)TRUE == txMDT)
		{
			Com_TxIPduNeedDelay[PduId] = (boolean)TRUE;
		}
		else
		{
			ret = (boolean)TRUE;
		}
		if((boolean)TRUE == Com_TxIPduTMS[PduId])
		{
			Com_TxIPduPeriodCnt[PduId] = COM_CFG_TXPDU(PduId).ComTxModeTrue->ComTxModeTimePeriod;
		}
		else
		{
			Com_TxIPduPeriodCnt[PduId] = COM_CFG_TXPDU(PduId).ComTxModeFalse->ComTxModeTimePeriod;
		}
	}
	if((boolean)FALSE == txMDT)
	{
		if((boolean)TRUE == Com_TxIPduNeedDelay[PduId])
		{
			ret = (boolean)TRUE;
		}
	}
	if((boolean)TRUE == ret)
	{
		/*reset the dm counter*/
		Com_TxIPduDMTime[PduId] = COM_CFG_TXPDU(PduId).ComTxIpduDM;
	}
#endif
	return ret;
}


/**
 * @brief			Processing of pdu with Mix sending properties
 * @param[in]		pduId: Pdu identify
 * @param[in]		txMDT: Does the current pdu send delay
 * @param[out]		/
 * @param[in/out]	/
 * @return			boolean
 * @retval			TRUE
 * 					FALSE
 */
FUNC(boolean,COM_CODE)
Com_TxMix(VAR(PduIdType, COM_VAR) PduId, VAR(boolean, COM_VAR) txMDT)
{
	/**
	 * @req [SWS_Com_00494] If within the transmission mode MIXED an N-Times transmission request
	 * 						overlaps with the cyclic part of the mixed transmission the cyclic
	 * 						transmission shall be counted as the corresponding transmission of the
	 * 						N-Times transmission request
	 */
	/* Direct mode */
	boolean ret;
#if(COM_NUMBER_OF_TXIPDU > 0)
	/* PRQA S 2982 EOF # violate MISRA_2004_Rule_21.1:ignore warnning */
	ret = Com_TxDirect(PduId,txMDT);
	ret = Com_TxPeriodic(PduId,txMDT);
#else
	ret = (boolean)FALSE;
#endif
	return ret;
}


/**
 * @brief			send Tx group signal
 * @param[in]		TxGroupSignalId: Signal identifier
 * @param[in]		SignalDataPtr: Reference to the signal data to be transmitted
 * @param[out]		/
 * @param[in/out]	/
 * @return			uint8
 * @retval			/
 */
#if(COM_NUMBER_OF_TXSIGNALGROUP > 0u)
FUNC(uint8 , COM_CODE)
Com_HandleTxGroupSignal(
	VAR(Com_SignalIdType, COM_VAR) TxGroupSignalId,
	P2CONST(void, AUTOMATIC, COM_APPL_CONST) SignalDataPtr
)
{
    uint8 ret;
    Com_SignalGroupIdType signalGroupId;
#if(COM_TMCTXGROUPSIGNAL_NUMBER > 0u)
    Com_SignalIdType txSignalTMCId;
    uint16 initValueId;
#endif
    boolean valueIsChanged = (boolean)FALSE;
    Com_SignalType groupSignalType;
    PduIdType refPduId;
    signalGroupId = COM_CFG_TXGROUPSIGNAL(TxGroupSignalId).ComSignalGroupRef;
    groupSignalType = COM_CFG_TXGROUPSIGNAL(TxGroupSignalId).ComSignalType;
    refPduId = COM_CFG_TXSIGNALGROUP(signalGroupId).ComIpduRefIndex;
    if((COM_UINT8_DYN == groupSignalType) && \
    		(COM_CFG_TXSIGNALGROUP(signalGroupId).ComInitialValueOnly == (boolean)TRUE))
    {
    	ret = COM_SERVICE_NOT_AVAILABLE;
    }
    else
    {
		if(NULL_PTR != COM_CFG_TXGROUPSIGNAL(TxGroupSignalId).ComFilter)
		{
#if(COM_TMCTXGROUPSIGNAL_NUMBER > 0u)
			initValueId = COM_CFG_TXGROUPSIGNAL(TxGroupSignalId).ComSignalInitValueId;
			txSignalTMCId = COM_CFG_TXGROUPSIGNAL(TxGroupSignalId).ComFilter->ComTMCBufferId;
			TxGroupSignalTMCBuffer[txSignalTMCId] = Com_CalSignalTMC(SignalDataPtr,\
					COM_CFG_TXGROUPSIGNAL(TxGroupSignalId).ComFilter,groupSignalType,initValueId);
#endif
		}
		/* update tx signal buffer and check if the sending signal value changed */
		valueIsChanged = Com_CalGroupSignalValueIsChange(TxGroupSignalId,SignalDataPtr);
		switch(COM_CFG_TXSIGNALGROUP(signalGroupId).ComTransferProperty)
		{
			/**
			 * @req [SWS_Com_00741] signal group with ComTransferProperty TRIGGERED, immediately
			 * 						(within the next main function at the latest) initiate
			 * 						ComTxModeNumberOfRepetitions plus one transmissions of the
			 * 						assigned I-PDU
			 */
			case COM_TRIGGERED:
				Com_TxSignalGroupState[signalGroupId].TransmitRequest = (boolean)TRUE;
				Com_TxSignalGroupState[signalGroupId].NoRepetition = (boolean)FALSE;
				break;
			/**
			 * @req [SWS_Com_00743]
			 * @req [SWS_Com_00742] signal group with ComTransferProperty TRIGGERED, immediately
			 * 						(within the next main function at the latest) initiate
			 * 						ComTxModeNumberOfRepetitions plus one transmissions of the
			 * 						assigned I-PDU  if at least one new sent group signal differs
									to the locally stored (last sent or init) in length or value
			 */
			case COM_TRIGGERED_ON_CHANGE:
				if(((boolean)TRUE == valueIsChanged) && \
			(COM_TRIGGERED_ON_CHANGE == COM_CFG_TXGROUPSIGNAL(TxGroupSignalId).ComTransferProperty))
				{
					Com_TxSignalGroupState[signalGroupId].TransmitRequest = (boolean)TRUE;
					Com_TxSignalGroupState[signalGroupId].NoRepetition = (boolean)FALSE;
				}
				break;
			/**
			 * @req [SWS_Com_00770] ComTransferProperty TRIGGERED_ON_CHANGE_WITHOUT_REPETITION,
			 * 						immediately (within the next main function at the latest) initiate
			 * 						ComTxModeNumberOfRepetitions plus one transmissions of the
			 * 						assigned I-PDU
			 */
			case COM_TRIGGERED_ON_CHANGE_WITHOUT_REPETITION:
				if((boolean)TRUE == valueIsChanged)
				{
					Com_TxSignalGroupState[signalGroupId].TransmitRequest = (boolean)TRUE;
					Com_TxSignalGroupState[signalGroupId].NoRepetition = (boolean)TRUE;
				}
				break;
			/**
			 * @req [SWS_Com_00769] signal group with ComTransferProperty TRIGGERED_WITHOUT_REPETITION,
			 * 						immediately (within the next main function at the latest) initiate
			 * 						ComTxModeNumberOfRepetitions plus one transmissions of the
			 * 						assigned I-PDU
			 */
			case COM_TRIGGERED_WITHOUT_REPETITION:
				Com_TxSignalGroupState[signalGroupId].TransmitRequest = (boolean)TRUE;
				Com_TxSignalGroupState[signalGroupId].NoRepetition = (boolean)TRUE;
				break;
			default:
				break;
		}
	    if(COM_CHECKTXPDUISENABLE(refPduId))
	    {
	    	ret = E_OK;
	    }
	    else
	    {
	    	ret = COM_SERVICE_NOT_AVAILABLE;
	    }
    }
    return ret;
}
#endif/* COM_NUMBER_OF_TXSIGNALGROUP > 0u */

/**
 * @brief			send dynamic Tx group signal
 * @param[in]		TxGroupSignalId: Signal identifier
 * @param[in]		SignalDataPtr: Reference to the signal data to be transmitted
 * @param[in]		DynLength: length of signal
 * @param[out]		/
 * @param[in/out]	/
 * @return			uint8
 * @retval			/
 */
#if(COM_NUMBER_OF_TXSIGNALGROUP > 0u)
FUNC(uint8 , COM_CODE)
Com_HandleTxDynGroupSignal(
	VAR(Com_SignalIdType, COM_VAR) TxGroupSignalId,
	P2CONST(void, AUTOMATIC, COM_APPL_CONST) SignalDataPtr,
	VAR(uint16, COM_VAR) DynLength
)
{
    uint8 ret;
    Com_SignalGroupIdType signalGroupId;
    PduIdType refPduId;
    boolean valueIsChanged;
    uint16 initValueId;
    signalGroupId = COM_CFG_TXGROUPSIGNAL(TxGroupSignalId).ComSignalGroupRef;
    if((COM_UINT8_DYN == COM_CFG_TXGROUPSIGNAL(TxGroupSignalId).ComSignalType) \
    		&& (COM_CFG_TXSIGNALGROUP(signalGroupId).ComInitialValueOnly != (boolean)TRUE))
    {
    	if(DynLength > COM_CFG_TXGROUPSIGNAL(TxGroupSignalId).ComSignalLength)
    	{
    		#if(STD_ON == COM_DEV_ERROR_DETECT)
    		COM_DET_ERROR_REPORT(COM_SID_SENDDYNSIGNAL, COM_E_PARAM);
    		#endif
    		ret = E_NOT_OK;
    	}
    	else
    	{
    		refPduId = COM_CFG_TXSIGNALGROUP(signalGroupId).ComIpduRefIndex;
    		initValueId = COM_CFG_TXGROUPSIGNAL(TxGroupSignalId).ComSignalInitValueId;
    		valueIsChanged = Com_CalDynChange(refPduId,initValueId,SignalDataPtr,DynLength);
    		Com_TxSignalGroupState[signalGroupId].DynamicSignalLength = DynLength;
    		switch(COM_CFG_TXSIGNALGROUP(signalGroupId).ComTransferProperty)
    		{
    			case COM_TRIGGERED:
    				Com_TxSignalGroupState[signalGroupId].TransmitRequest = (boolean)TRUE;
    				Com_TxSignalGroupState[signalGroupId].NoRepetition = (boolean)FALSE;
    				break;
    			case COM_TRIGGERED_ON_CHANGE:
					if(((boolean)TRUE == valueIsChanged) && (COM_TRIGGERED_ON_CHANGE == \
							COM_CFG_TXGROUPSIGNAL(TxGroupSignalId).ComTransferProperty))
					{
						Com_TxSignalGroupState[signalGroupId].TransmitRequest = (boolean)TRUE;
						Com_TxSignalGroupState[signalGroupId].NoRepetition = (boolean)FALSE;
					}
    				break;
    			case COM_TRIGGERED_ON_CHANGE_WITHOUT_REPETITION:
    				if((boolean)TRUE == valueIsChanged)
    				{
    					Com_TxSignalGroupState[signalGroupId].TransmitRequest = (boolean)TRUE;
    					Com_TxSignalGroupState[signalGroupId].NoRepetition = (boolean)TRUE;
    				}
    				break;
    			case COM_TRIGGERED_WITHOUT_REPETITION:
    				Com_TxSignalGroupState[signalGroupId].TransmitRequest = (boolean)TRUE;
    				Com_TxSignalGroupState[signalGroupId].NoRepetition = (boolean)TRUE;
    				break;
    			default:
    				break;
    		}
    		ret = E_OK;
    	}
    }
    else
    {
    	ret = COM_SERVICE_NOT_AVAILABLE;
    }
	return ret;
}
#endif/* COM_NUMBER_OF_TXSIGNALGROUP > 0u */

/**
 * @brief			send Tx group signal
 * @param[in]		TxGroupSignalId: Signal identifier
 * @param[in]		SignalDataPtr: Reference to the signal data to be transmitted
 * @param[out]		/
 * @param[in/out]	/
 * @return			uint8
 * @retval			/
 */
FUNC(void , COM_CODE)
Com_SendPdu(VAR(PduIdType, COM_VAR) PduId)
{
#if(COM_NUMBER_OF_TXIPDU > 0)
	Std_ReturnType result;
	uint8 metaDataLength;
	uint8 counterValue = 0u;
	uint16 bufIndex;
	uint16 pduLength;
	PduIdType refPduRPduId;
	PduInfoType pduinfo;
	bufIndex = COM_CFG_TXPDU(PduId).ComTxIPduBufIndex;
	pduLength = COM_CFG_TXPDU(PduId).ComIPduInitLength;
	metaDataLength = COM_CFG_TXPDU(PduId).MetaDataLength;
	/**
	 * @req [SWS_Com_00759] Determine whether the sent pdu is normal or tp type
	 */
	if(COM_NORMAL == COM_CFG_GET_TXPDU_TYPE(PduId))
	{
		pduinfo.SduDataPtr = &Com_TxIPduRuntimeValue[bufIndex];
		pduinfo.SduLength = (PduLengthType)pduLength + (PduLengthType)metaDataLength;
	}
	/**
	 * @req [SWS_Com_00760] Tp type of pdu
	 */
	else
	{
		if(metaDataLength != 0u)
		{
			pduinfo.SduDataPtr = &Com_TxIPduRuntimeValue[bufIndex + pduLength];
		}
		else
		{
			pduinfo.SduDataPtr = NULL_PTR;
		}
		pduinfo.SduLength = pduLength;
	}
	/* If pdu sets the counter, it will check the validity of the counter */
	if(NULL_PTR != COM_CFG_TXPDU(PduId).ComIPduCounter)
	{
		Com_CalCounterValue(PduId);
		/**
		 * @req [SWS_Com_00688] increase the I-PDU counter of an I-PDU by one before the I-PDU is sent
		 *  					out by PduR_ComTransmit
		 */
		counterValue = Com_TxIPduData[PduId].TxIpduCounter;
		Com_GetNextCounterValue((boolean)TRUE, PduId);
	}
	refPduRPduId = Com_ConfigPtr->ComTxIPdu[PduId].PduRLayerId;
	/**
	 * @req [SWS_Com_00478]
	 * @req [SWS_Com_00138] send out I-PDUs by a calling the PduR_ComTransmit function
	 */
	result = (Std_ReturnType)PduR_ComTransmit(refPduRPduId, &pduinfo);
	Com_HandleTransmitResult(PduId,result,counterValue);
#endif
}

/**
 * @brief			Processing pass judgment signals
 * @param[in]		SignalId: Signal identifier
 * @param[in]		PduId: Pdu identifier
 * @param[in]		SignalDataPtr: Reference to the signal data to be transmitted
 * @param[out]		/
 * @param[in/out]	/
 * @return			Std_ReturnType
 * @retval			E_OK
 * 					E_NOT_OK
 * 					COM_SERVICE_NOT_AVAILABLE
 */
FUNC(Std_ReturnType , COM_CODE)
Com_HandlePassSignal(
	VAR(Com_SignalIdType, COM_VAR) SignalId,
	VAR(PduIdType, COM_VAR) PduId,
	P2CONST(void, AUTOMATIC, COM_APPL_CONST) SignalDataPtr
)
{
	Std_ReturnType ret;
#if(COM_NUMBER_OF_TXIPDU > 0)
	uint16 pduBufferIdx;
	boolean valueIsChanged = (boolean)FALSE;
#endif
	uint32 updateBitPosition;
	updateBitPosition = COM_CFG_TXSIGNAL(SignalId).ComUpdateBitPosition;
	if(updateBitPosition != 0xffffffffu)
	{
#if(COM_NUMBER_OF_TXIPDU)
		pduBufferIdx = COM_CFG_TXPDU(PduId).ComTxIPduBufIndex;
		/**
		 * @req [SWS_Com_00061]
		 * @req [SWS_Com_00067] set the update-bit of this signal
		 */
		Com_TxIPduRuntimeValue[pduBufferIdx + (uint16)(updateBitPosition >> 3u)] |= \
				(uint8)(0x01u << (updateBitPosition & 0x07u));
#endif
	}
	Com_UpdateTMC((Com_SignalIdType)SignalId, (PduIdType)PduId, SignalDataPtr);
	if((boolean)TRUE == Com_CalSignalValueIsChange(SignalId,SignalDataPtr))
	{
		/**
		 * @req [SWS_Com_00055] The AUTOSAR COM module shall handle the update-bit only internally and
		 * 						not as part of the signal or signal group.
		 */

		/**
		 * @req [SWS_Com_00624] Com_SendSignal shall update the signal object identified by SignalId
		 *  					with the signal referenced by the SignalDataPtr parameter.
		 */
		Com_PackSignal(SignalId);
		/**
		 * @req [SWS_Com_00245] re-calculate the TMS for an I-PDU, after a contained signal was
		 * 						updated by a call to Com_SendSignal or Com_SendSignalGroup
		 */
#if(COM_NUMBER_OF_TXIPDU > 0)
		valueIsChanged = (boolean)TRUE;
#endif
	}
#if(COM_NUMBER_OF_TXIPDU > 0)
	if(COM_CHECKTXPDUISENABLE(PduId))
	{
		ret = Com_HandleTxSignal(SignalId, valueIsChanged);
	}
	else
	{
		if(COM_CFG_TXSIGNAL(SignalId).ComErrorNotification != NULL_PTR)
		{
			COM_CFG_TXSIGNAL(SignalId).ComErrorNotification();
		}
		ret = COM_SERVICE_NOT_AVAILABLE;
	}
#else
	ret = (Std_ReturnType)E_NOT_OK;
#endif
	return ret;
}

/**
 * @brief			Processing pass judgment dymic signals
 * @param[in]		SignalId: Signal identifier
 * @param[in]		PduId: Pdu identifier
 * @param[in]		SignalDataPtr: Reference to the signal data to be transmitted
 * @param[in]		Length: length of signal
 * @param[out]		/
 * @param[in/out]	/
 * @return			Std_ReturnType
 * @retval			E_OK
 * 					E_NOT_OK
 * 					COM_SERVICE_NOT_AVAILABLE
 */
FUNC(Std_ReturnType , COM_CODE)
Com_HandlePassDynSignal(
	VAR(Com_SignalIdType, COM_VAR) SignalId,
	VAR(PduIdType, COM_VAR) PduId,
	P2CONST(void, AUTOMATIC, COM_APPL_CONST) SignalDataPtr,
	VAR(uint16, COM_VAR) Length
)
{
	Std_ReturnType ret;
	uint16 initValueId;
	uint16 signalLength;
#if(COM_NUMBER_OF_TXIPDU > 0)
	boolean valueIsChanged = (boolean)FALSE;
	uint16 pduBufferIdx;
#endif
	uint32 updateBitPosition;
	uint32 bitPosition;
	signalLength = COM_CFG_TXSIGNAL(SignalId).ComSignalLength;
	initValueId = Com_ConfigPtr->ComTxSignal[SignalId].ComSignalInitValueId;
	updateBitPosition = COM_CFG_TXSIGNAL(SignalId).ComUpdateBitPosition;
	/**
	 * @req [SWS_Com_00055] handle the update-bit only internally and not as part of the
	 * 						signal or signal group.
	 */
	if(updateBitPosition != 0xffffffffu)
	{
#if(COM_NUMBER_OF_TXIPDU)
		pduBufferIdx = COM_CFG_TXPDU(PduId).ComTxIPduBufIndex;
		/**
		 * @req [SWS_Com_00061]
		 * @req [SWS_Com_00067] set the update-bit of this signal
		 */
		Com_TxIPduRuntimeValue[pduBufferIdx + (uint16)(updateBitPosition >> 3u)] |= \
				(uint8)(0x01u << (updateBitPosition & 0x07u));
#endif
	}
	Com_UpdateTMC((Com_SignalIdType)SignalId, (PduIdType)PduId, SignalDataPtr);
	if((boolean)TRUE == Com_CalDynChange(PduId, initValueId, SignalDataPtr, signalLength))
	{
#if(COM_NUMBER_OF_TXIPDU > 0)
		valueIsChanged = (boolean)TRUE;
#endif
		bitPosition = COM_CFG_TXSIGNAL(SignalId).ComBitPosition;
		/* pack dynamic signals into the pdu buffer */
		Com_PackDynSignal(PduId, bitPosition, initValueId, signalLength);
	}
#if(COM_NUMBER_OF_TXIPDU > 0)
	if(COM_CHECKTXPDUISENABLE(PduId))
	{
		ret = Com_HandleTxSignal(SignalId, valueIsChanged);
	}
	else
	{
		if(COM_CFG_TXSIGNAL(SignalId).ComErrorNotification != NULL_PTR)
		{
			COM_CFG_TXSIGNAL(SignalId).ComErrorNotification();
		}
		ret = COM_SERVICE_NOT_AVAILABLE;
	}
#else
	ret = (Std_ReturnType)E_NOT_OK;
#endif
	return ret;
}

#if(COM_NUMBER_OF_TXSIGNALGROUP > 0u)
/**
 * @brief			Processing pass judgment signal groups
 * @param[in]		SignalGroupId: Signal Group identifier
 * @param[in]		PduId: Pdu identifier
 * @param[out]		/
 * @param[in/out]	/
 * @return			Std_ReturnType
 * @retval			E_OK
 * 					E_NOT_OK
 * 					COM_SERVICE_NOT_AVAILABLE
 */
FUNC(Std_ReturnType , COM_CODE)
Com_HandlePassSignalGroup(Com_SignalGroupIdType SignalGroupId, VAR(PduIdType, COM_VAR) PduId)
{
	uint16 rptNum;
	Std_ReturnType ret = E_OK;
	uint16 pduBufferIdx = 0u;
	uint32 updateBitPosition;
	updateBitPosition = COM_CFG_TXSIGNALGROUP(SignalGroupId).ComUpdateBitPosition;
	/**
	 * @req [SWS_Com_00055] The AUTOSAR COM module shall handle the update-bit only internally and
	 * 						not as part of the signal or signal group.
	 */
	if(updateBitPosition != 0xffffffffu)
	{
		pduBufferIdx = COM_CFG_TXPDU(PduId).ComTxIPduBufIndex;
		/**
		 * @req [SWS_Com_00801]
		 * @req [SWS_Com_00061]
		 * @req [SWS_Com_00067] set the update-bit of this signal
		 */
		Com_TxIPduRuntimeValue[pduBufferIdx + (uint16)(updateBitPosition >> 3u)] |= \
				(uint8)(0x01u << (updateBitPosition & 0x07u));
	}

	Com_PackSignalGroup(SignalGroupId);
	Com_HandleTxIpduTMS(PduId, &rptNum);
	if(COM_CHECKTXPDUISENABLE(PduId))
	{
		ret = Com_HandleTxSignalGroup(SignalGroupId,rptNum);
	}
	else
	{
		if(COM_CFG_TXSIGNALGROUP(SignalGroupId).ComErrorNotification != NULL_PTR)
		{
			COM_CFG_TXSIGNALGROUP(SignalGroupId).ComErrorNotification();
		}
		ret = COM_SERVICE_NOT_AVAILABLE;
	}
	return ret;
}
#endif

#if(COM_NUMBER_OF_TXSIGNALGROUP > 0u)
/**
 * @brief			send Tx signal group handle
 * @param[in]		SignalGroupId: Signal Group identifier
 * @param[out]		/
 * @param[in/out]	/
 * @return			Std_ReturnType
 * @retval			E_OK
 * 					E_NOT_OK
 * 					COM_SERVICE_NOT_AVAILABLE
 */
STATIC FUNC(uint8 , COM_CODE)
Com_HandleTxSignalGroup(Com_SignalGroupIdType SignalGroupId,uint16 RptNum)
{
	uint16 pduBufferIdx;
	PduInfoType pduInfo;
	PduLengthType pduLength;
	boolean ret = (boolean)TRUE;
	boolean DmStart = (boolean)FALSE;
	PduIdType pduId = COM_CFG_TXSIGNALGROUP(SignalGroupId).ComIpduRefIndex;
	boolean retCallOut = (boolean)TRUE;
    /* the signal group configuration timeout,the DM timer isn't start by other
     * signals/signal groups,Tx Mode isn't NONE */
    if((0u != COM_CFG_TXSIGNALGROUP(SignalGroupId).ComTimeout) && (COM_NONE != Com_TxIPduMode[pduId])
       && (0u == Com_TxIPduDMTime[pduId]))
    {
    	Com_TxIPduDMTime[pduId] = COM_CFG_TXPDU(pduId).ComTxIpduDM;
    	DmStart = TRUE;
    }
    if(NULL_PTR != COM_CFG_TXPDU(pduId).ComIPduCallout)
    {
    	pduBufferIdx = COM_CFG_TXPDU(pduId).ComTxIPduBufIndex;
    	pduLength = COM_CFG_TXPDU(pduId).ComIPduInitLength;
        pduInfo.SduDataPtr = &Com_TxIPduRuntimeValue[pduBufferIdx];
        pduInfo.SduLength = pduLength + (uint16)COM_CFG_TXPDU(pduId).MetaDataLength;
        retCallOut = COM_CFG_TXPDU(pduId).ComIPduCallout(pduId, &pduInfo);
    }
    if(TRUE == retCallOut)
    {
        if((COM_DIRECT == Com_TxIPduMode[pduId]) || (COM_MIXED == Com_TxIPduMode[pduId]))
        {
            if((boolean)TRUE == Com_TxSignalGroupState[SignalGroupId].TransmitRequest)
            {
                Com_TxIPduRepetitionPeriod[pduId] = 0u;
                if((boolean)TRUE == Com_TxSignalGroupState[SignalGroupId].NoRepetition)
                {
                    Com_TxIPduRepeatNum[pduId] = 1u;
                }
                else
                {
                	Com_TxIPduRepeatNum[pduId] = RptNum;
                    if((1u < RptNum) && (FALSE == DmStart) && \
                    		(0u != COM_CFG_TXSIGNALGROUP(SignalGroupId).ComTimeout))
                    {
                        Com_TxIPduDMTime[pduId] = COM_CFG_TXPDU(pduId).ComTxIpduDM;
                    }
                }
            }
        }
        else
        {
            Com_TxIPduRepetitionPeriod[pduId] = 0u;
            Com_TxIPduRepeatNum[pduId] = 0u;
        }
        ret = E_OK;
    }
    else
    {
        ret = COM_SERVICE_NOT_AVAILABLE;
    }
    return ret;
}
#endif

#if(COM_NUMBER_OF_TXIPDU)
/**
 * @brief			Handle the result of transmit Pdu
 * @param[in]		SignalId: signal identify
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void , COM_CODE)
Com_HandleTransmitResult(
	VAR(PduIdType, COM_VAR) PduId,
	VAR(Std_ReturnType, COM_VAR)Result,
	VAR(uint8, COM_VAR)CounterValue
)
{
	if(Result == (Std_ReturnType)E_OK)
	{
		Com_TxIPduIsTransmiting[PduId] = (boolean)TRUE;
#if(STD_ON == COM_ENABLE_MDT_FOR_CYCLIC_TRANSMISSION)
		Com_TxIPduMDT[PduId] = COM_CFG_TXPDU(PduId).ComMinimumDelayTime;
#endif/* STD_ON == COM_ENABLE_MDT_FOR_CYCLIC_TRANSMISSION */
		/**
		 * @req [SWS_Com_00062] clear all update-bits of all contained signals and signal groups after
		 *  					this I-PDU was sent out via PduR_ComTransmit
		 */
		if(COM_TRANSMIT == COM_CFG_TXPDU(PduId).ComTxIPduClearUpdateBit)
		{
			Com_ClearUpdates(PduId);
		}
		Com_TxIPduOffset[PduId] = 0u;
		if((boolean)TRUE == Com_TxIPduNeedDelay[PduId])
		{
			Com_TxIPduNeedDelay[PduId] = (boolean)FALSE;

		}
		/**
		 * @req [SWS_Com_00828] If ComMinimumDelayTime of an I-PDU is configured greater than 0 and
		 * 						ComRetryFailedTransmitRequests is set to TRUE, shall load and start
		 * 						the minimum delay time counter upon transmission via PduR_ComTransmit
		 * 						only in case PduR_ComTransmit returns E_OK
		 */
	}
	else
	{
		if(NULL_PTR != COM_CFG_TXPDU(PduId).ComIPduCounter)
		{
			Com_TxIPduData[PduId].TxIpduCounter = CounterValue;
		}
		/**
		 * @req [SWS_Com_00775] If ComRetryFailedTransmitRequests is set to True and a transmission
		 * 						deadline monitoring timeout occurs for an I-PDU, shall expire any
		 * 						pending transmission request for this I-PDU
		 */
#if(STD_ON == COM_RETRY_FAILED_TRANSMIT_REQUESTS)
		Com_TxIPduNeedDelay[PduId] = TRUE;
#endif/*STD_ON == COM_RETRY_FAILED_TRANSMIT_REQUESTS*/
	}
}
#endif

#if(COM_NUMBER_OF_TXIPDU)
/**
 * @brief			Handle the result of transmit Pdu
 * @param[in]		SignalId: signal identify
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void , COM_CODE)
Com_CheckPduIsDelay(
	VAR(PduIdType, COM_VAR) PduId,
	P2VAR(Std_ReturnType, COM_AUTOMATIC, COM_VAR)NeedDelay
)
{
#if(COM_ENABLE_MDT_FOR_CYCLIC_TRANSMISSION == STD_ON)
	/**
	 * @req [SWS_Com_00471] No minimum delay time monitoring shall take place, if
	 * 						ComMinimumDelayTime is omitted or configured to 0
	 */
	if(Com_TxIPduMDT[PduId] > 0u)
	{
		Com_TxIPduMDT[PduId]--;
		if(Com_TxIPduMDT[PduId] != 0u)
		{
			*NeedDelay = (boolean)TRUE;
		}
	}
#endif
	if(Com_TxIPduDMTime[PduId] > 0u)
	{
		Com_TxIPduDMTime[PduId]--;
		if(Com_TxIPduDMTime[PduId] == 0u)
		{
			/**
			 * @req [SWS_Com_00304] When DM CNT is reduced to 0, it indicates that the timeout is
			 * 						overdue, and the timeout notification is required
			 */
			/**
			 * @req [SWS_Com_00392] a transmission deadline monitoring timeout occurs
			 * 						before the N-Times transmission is complete
			 */
			Com_TimeOutNotification(PduId);
			Com_TxIPduRepeatNum[PduId] = 0u;
			Com_TxIPduRepetitionPeriod[PduId] = 0u;
			Com_TxIPduIsTransmiting[PduId] = (boolean)FALSE;
	/**
	 * @req [SWS_Com_00708] In case the transmission deadline monitoring timer expires for
	 * 						an I-PDU with ComIPduCancellationSupport configured to TRUE,
	 * 						the AUTOSAR COM module shall invoke PduR_ComCancelTransmit
	 */
	#if(STD_ON == COM_CANCELLATION_SUPPORT)
			if(TRUE == COM_CFG_TXPDU(PduId).ComIPduCancellationSupport)
			{
				PduR_ComCancelTransmit(COM_CFG_TXPDU(PduId).PduRLayerId);
			}
	#endif/*STD_ON == COM_CANCELLATION_SUPPORT*/
		}
	}
}
#endif

#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"















