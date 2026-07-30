/**
 * @file        Dcm_UDS0x2A.c
 * @brief       AUTOSAR 4.2.2 - 4.2.2 driver source file.
 * @details     Dcm driver source file, containing the C implementation of Autosar API specification
 *              and other variables and functions that are exported by the Dcm driver.
 * @version     1.2.0
 *
 * @addtogroup  Dcm
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

#ifdef __cplusplus
extern "C"{
#endif

/* PRQA S 0292, 0857, 0491, 2981, 5087 EOF #
 *
 * 1.0292 -- Violates MISRA 2004 Required Rule 3.1, Source file has comments containing one of the
 * characters '$', '@' or '`'.
 *
 * 2.0857 -- Violates MISRA 2004 Required Rule 1.1, Number of macro definitions exceeds 1024 - program
 * does not conform strictly to ISO:C90.
 *
 * 3.0491 -- Violates MISRA 2004 Required Rule 17.4, Array subscripting applied to an object of pointer
 * type.
 *
 * 4.2981 -- Violates MISRA 2004 Required Rule 21.1, This initialization is redundant. The value of this
 * object is never used before being modified.
 *
 * 6.5087 -- Violates MISRA 2004 Required Rule 19.1, Use of #include directive after code fragment.
 *
 * @page misra_violations MISRA-C:2004 violations
 */

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
#include "Dcm_Internal.h"

#ifdef AH_TEST_DCM
#include "TestCode.h"
#endif /* #ifdef AH_TEST_DCM */

#if(STD_ON == DCM_UDS0x2A_ENABLE)
#if(STD_ON == DCM_UDS0x2A_INTERNAL_FNC_ENABLE)
/**
 * @req [SWS_Dcm_00254] The DSP submodule shall implement the UDS Service ReadDataByPeriodicIdentifier\
 * 		(0x2A).
 */
/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION
 *====================================================================================================*/
#define DCM_UDS0X2A_VENDOR_ID_C                            	(0x00U)
#define DCM_UDS0X2A_AR_RELEASE_MAJOR_VERSION_C             	(0x04U)
#define DCM_UDS0X2A_AR_RELEASE_MINOR_VERSION_C             	(0x02U)
#define DCM_UDS0X2A_AR_RELEASE_REVISION_VERSION_C          	(0x02U)
#define DCM_UDS0X2A_SW_MAJOR_VERSION_C                     	(0x01U)
#define DCM_UDS0X2A_SW_MINOR_VERSION_C                     	(0x02U)
#define DCM_UDS0X2A_SW_PATCH_VERSION_C                     	(0x00U)
/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Dcm_Internal header file are of the same vendor */
#if(DCM_UDS0X2A_VENDOR_ID_C != DCM_INTERNAL_VENDOR_ID )
#error "Dcm_UDS0x2A.c and Dcm_Internal.h have different vendor id"
#endif
/* Check if current file and Dcm_Internal header file are of the same Autosar version */
#if(\
		(DCM_UDS0X2A_AR_RELEASE_MAJOR_VERSION_C != DCM_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_UDS0X2A_AR_RELEASE_MINOR_VERSION_C != DCM_INTERNAL_AR_RELEASE_MINOR_VERSION) || \
		(DCM_UDS0X2A_AR_RELEASE_REVISION_VERSION_C != DCM_INTERNAL_AR_RELEASE_REVISION_VERSION) \
)
#error "AutoSar Version Number of Dcm_UDS0x2A.c and Dcm_Internal.h are different"
#endif
/* Check if current file and Dcm_Internal header file are of the same software version */
#if(\
		(DCM_UDS0X2A_SW_MAJOR_VERSION_C != DCM_INTERNAL_SW_MAJOR_VERSION) || \
		(DCM_UDS0X2A_SW_MINOR_VERSION_C != DCM_INTERNAL_SW_MINOR_VERSION) || \
		(DCM_UDS0X2A_SW_PATCH_VERSION_C != DCM_INTERNAL_SW_PATCH_VERSION) \
)
#error "Software Version Number of Dcm_UDS0x2A.c and Dcm_Internal.h are different"
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
#ifdef AH_UNITTEST_ENABLED

	#ifdef STATIC
		#undef STATIC
		#define STATIC
	#else
		#define STATIC
	#endif /* STATIC */

	#ifdef INLINE
		#undef INLINE
		#define INLINE
	#else
		#define STATIC_INLINE
	#endif /* INLINE */

	#ifdef STATIC_INLINE
		#undef STATIC_INLINE
		#define STATIC_INLINE
	#else
		#define STATIC_INLINE
	#endif /* STATIC_INLINE */
#else
	#ifndef STATIC
		#define STATIC static
	#endif /* STATIC */

	#ifndef INLINE
		#define INLINE inline
	#endif /* INLINE */

	#ifndef STATIC_INLINE
		#define STATIC_INLINE static inline
	#endif /* STATIC_INLINE */

#endif /* AH_UNITTEST_ENABLED */
/*====================================================================================================*
 *                                           LOCAL CONSTANTS
 *====================================================================================================*/

/*====================================================================================================*
 *                                           LOCAL VARIABLES
 *====================================================================================================*/
#define DCM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dcm_MemMap.h"

/**
 * @brief	Store internal status of service 0x2A during its processing.
 */
STATIC VAR(Dcm_ReadDataByPDidStatusType, DCM_VAR)Dcm_UDS0x2AStatus;

#define DCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dcm_MemMap.h"
/*====================================================================================================*
 *                                      LOCAL FUNCTION PROTOTYPES
 *====================================================================================================*/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

STATIC FUNC(void, DCM_CODE)Dcm_UDS0x2AFilterDuplicateReqDid
(
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext
);

#if((0u != DCM_DSP_DID_NUM) && (0u != DCM_DSP_DID_SIGNAL_NUM))
STATIC FUNC(void, DCM_CODE)Dcm_UDS0x2ACheckReqDidExistInSchedulerTable
(
	uint8 u8ReqDid,
	boolean isDelDuplicatePDid
);

STATIC FUNC(void, DCM_CODE)Dcm_UDS0x2AInsertNewPDidToSchedulerTable
(
	void
);
#endif /* #if((0u != DCM_DSP_DID_NUM) && (0u != DCM_DSP_DID_SIGNAL_NUM)) */

#if((STD_ON == DCM_DSP_DATA_CONDITION_CHECK_READ_FNC_ENABLED) ||\
	(STD_ON == DCM_DSP_DATA_READ_DATA_LENGTH_FNC_ENABLED))
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2ACheckSingleReadCondition
(
	uint8 u8ReqDidIdx,
	Dcm_ExtendedOpStatusType opState,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);

STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2ACheckReadCondition
(
	uint8 u8ReqDidIdx,
	Dcm_ExtendedOpStatusType opState,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);
#endif /* #if((STD_ON == DCM_DSP_DATA_CONDITION_CHECK_READ_FNC_ENABLED) ||\
			  (STD_ON == DCM_DSP_DATA_READ_DATA_LENGTH_FNC_ENABLED)) */

#if((0u != DCM_DSP_DID_NUM) && (0u != DCM_DSP_DID_SIGNAL_NUM))
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2ACheckAllReqDidVaild
(
	Dcm_ExtendedOpStatusType opState,
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);
#endif /* #if((0u != DCM_DSP_DID_NUM) && (0u != DCM_DSP_DID_SIGNAL_NUM)) */

STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2AStartSendHandle
(
	uint8 u8SubId,
	Dcm_ExtendedOpStatusType opState,
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);

STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2AStopSendHandle
(
	uint8 u8ReqDidNum,
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext
);
/*====================================================================================================*
 *                                           LOCAL FUNCTIONS
 *====================================================================================================*/
/**
 * @brief			Dcm_UDS0x2AFilterDuplicateReqDid
 * @details			Filter duplicate DIDs contained in the request message.
 */
STATIC FUNC(void, DCM_CODE)Dcm_UDS0x2AFilterDuplicateReqDid
(
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext
)
{
	uint8 u8ILoop;
	uint8 u8JLoop;
	uint8 u8ValidIndex = 0u;
	boolean isDuplicate;

	for(u8ILoop = 0u; u8ILoop < Dcm_UDS0x2AStatus.ReqDidNum; u8ILoop++)
	{
		isDuplicate = (boolean)FALSE;

		for(u8JLoop = 0u; u8JLoop < u8ValidIndex; u8JLoop++)
		{
			if(pMsgContext->ReqData[u8ILoop + 2u] == pMsgContext->ReqData[u8JLoop + 2u])
			{
				isDuplicate = (boolean)TRUE;

				break;
			}
		}

		if((boolean)FALSE == isDuplicate)
		{
			pMsgContext->ReqData[u8ValidIndex + 2u] = pMsgContext->ReqData[u8ILoop + 2u];

			u8ValidIndex++;
		}
	}

	Dcm_UDS0x2AStatus.ReqDidNum = u8ValidIndex;
}

/**
 * @brief			Dcm_UDS0x2ACheckReqDidExistInSchedulerTable
 * @details			Check whether the valid requested DIDs already exist in the scheduler table.
 */
STATIC FUNC(void, DCM_CODE)Dcm_UDS0x2ACheckReqDidExistInSchedulerTable
(
	uint8 u8ReqDid,
	boolean isDelDuplicatePDid
)
{
	uint8 u8Index;

	for(u8Index = 0u; u8Index < Dcm_PeriodicTransStatus.PDidNum; u8Index++)
	{
		if(u8ReqDid == Dcm_PeriodicTransStatus.SchedulerTable[u8Index].PDid)
		{
			if((boolean)TRUE == isDelDuplicatePDid)
			{
				DspInternal_DeletePeriodicDid(u8Index);
			}

			Dcm_UDS0x2AStatus.FreeSize++;

			break;
		}
	}
}

/**
 * @brief			Dcm_UDS0x2AInsertNewPDidToSchedulerTable
 * @details			Insert valid requested DIDs in to the scheduler table.
 */
STATIC FUNC(void, DCM_CODE)Dcm_UDS0x2AInsertNewPDidToSchedulerTable
(
	void
)
{
	uint8 u8Index;
	uint8 u8ReqDid;
	uint8 u8PDidNum = Dcm_PeriodicTransStatus.PDidNum;

	if(0u == u8PDidNum)
	{
		for(u8Index = 0u; u8Index < Dcm_UDS0x2AStatus.ValidPDidNum; u8Index++)
		{
			Dcm_PeriodicTransStatus.SchedulerTable[u8Index].MainConIndex = Dcm_ActiveConIdx;
			Dcm_PeriodicTransStatus.SchedulerTable[u8Index].Rate = Dcm_UDS0x2AStatus.ReqRate;
			Dcm_PeriodicTransStatus.SchedulerTable[u8Index].Timer = 0u;
			Dcm_PeriodicTransStatus.SchedulerTable[u8Index].PDid = Dcm_UDS0x2AStatus.NewPDidInfo[u8Index].PDid;
#if(STD_ON == DCM_UDS0x2C_ENABLE)
			Dcm_PeriodicTransStatus.SchedulerTable[u8Index].PDidType = Dcm_UDS0x2AStatus.NewPDidInfo[u8Index].PDidType;
			Dcm_PeriodicTransStatus.SchedulerTable[u8Index].PDDDidIndex = Dcm_UDS0x2AStatus.NewPDidInfo[u8Index].PDDDidIndex;
#endif /* #if(STD_ON == DCM_UDS0x2C_ENABLE) */
			Dcm_PeriodicTransStatus.SchedulerTable[u8Index].PDidIndex = Dcm_UDS0x2AStatus.NewPDidInfo[u8Index].PDidIndex;
			Dcm_PeriodicTransStatus.SchedulerTable[u8Index].DataLen = Dcm_UDS0x2AStatus.NewPDidInfo[u8Index].DataLen;
			Dcm_PeriodicTransStatus.SchedulerTable[u8Index].SesLevelRef = Dcm_UDS0x2AStatus.NewPDidInfo[u8Index].SesLevelRef;
			Dcm_PeriodicTransStatus.SchedulerTable[u8Index].SecLevelRef = Dcm_UDS0x2AStatus.NewPDidInfo[u8Index].SecLevelRef;
			Dcm_PeriodicTransStatus.SchedulerTable[u8Index].DidData[0] = Dcm_UDS0x2AStatus.NewPDidInfo[u8Index].PDid;

			Dcm_PeriodicTransStatus.PDidNum++;
		}
	}
	else
	{
		for(u8Index = 0u; u8Index < Dcm_UDS0x2AStatus.ValidPDidNum; u8Index++)
		{
			u8ReqDid = Dcm_UDS0x2AStatus.NewPDidInfo[u8Index].PDid;

			Dcm_UDS0x2ACheckReqDidExistInSchedulerTable(u8ReqDid, (boolean)TRUE);

			u8PDidNum = Dcm_PeriodicTransStatus.PDidNum;

			Dcm_PeriodicTransStatus.SchedulerTable[u8PDidNum].MainConIndex = Dcm_ActiveConIdx;
			Dcm_PeriodicTransStatus.SchedulerTable[u8PDidNum].Rate = Dcm_UDS0x2AStatus.ReqRate;
			Dcm_PeriodicTransStatus.SchedulerTable[u8PDidNum].Timer = 0u;
			Dcm_PeriodicTransStatus.SchedulerTable[u8PDidNum].PDid = u8ReqDid;
#if(STD_ON == DCM_UDS0x2C_ENABLE)
			Dcm_PeriodicTransStatus.SchedulerTable[u8PDidNum].PDidType = Dcm_UDS0x2AStatus.NewPDidInfo[u8Index].PDidType;
			Dcm_PeriodicTransStatus.SchedulerTable[u8PDidNum].PDDDidIndex = Dcm_UDS0x2AStatus.NewPDidInfo[u8Index].PDDDidIndex;
#endif /* #if(STD_ON == DCM_UDS0x2C_ENABLE) */
			Dcm_PeriodicTransStatus.SchedulerTable[u8PDidNum].PDidIndex = Dcm_UDS0x2AStatus.NewPDidInfo[u8Index].PDidIndex;
			Dcm_PeriodicTransStatus.SchedulerTable[u8PDidNum].DataLen = Dcm_UDS0x2AStatus.NewPDidInfo[u8Index].DataLen;
			Dcm_PeriodicTransStatus.SchedulerTable[u8PDidNum].SesLevelRef = Dcm_UDS0x2AStatus.NewPDidInfo[u8Index].SesLevelRef;
			Dcm_PeriodicTransStatus.SchedulerTable[u8PDidNum].SecLevelRef = Dcm_UDS0x2AStatus.NewPDidInfo[u8Index].SecLevelRef;
			Dcm_PeriodicTransStatus.SchedulerTable[u8PDidNum].DidData[0] = Dcm_UDS0x2AStatus.NewPDidInfo[u8Index].PDid;

			Dcm_PeriodicTransStatus.PDidNum++;
		}
	}
}

#if((STD_ON == DCM_DSP_DATA_CONDITION_CHECK_READ_FNC_ENABLED) ||\
	(STD_ON == DCM_DSP_DATA_READ_DATA_LENGTH_FNC_ENABLED))
/**
 * @brief			Dcm_UDS0x2ACheckSingleReadCondition
 * @details			Check whether the read conditions are met and retrieve the data length.
 *
 * @param[in]		u8ReqDidIdx:DID index.
 * @param[in]		opState:Operating state.
 *
 * @param[out]		pErrorCode:Output the error NRC.
 *
 * @return        	Result of this operation.
 * @retval			E_OK:Processing successfully.
 * @retval			E_NOT_OK:Processing not successfully.
 */
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2ACheckSingleReadCondition
(
	uint8 u8ReqDidIdx,
	Dcm_ExtendedOpStatusType opState,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_OK;

	uint8 u8Index;
	uint16 u16SignalSize;
	const Dcm_DspDataType* pSignalData = NULL_PTR;
	const Dcm_DspDidType* pDid = &Dcm_ConfigPtr->DcmDsp->DcmDspDid[u8ReqDidIdx];

	for(u8Index = Dcm_UDS0x2AStatus.ReqSignalIndex; u8Index < pDid->DcmDspDidSignalNum; u8Index++)
	{
		Dcm_UDS0x2AStatus.ReqSignalIndex = u8Index;

		pSignalData = pDid->DcmDspDidSignal[u8Index].DcmDspDidDataRef;

		u16SignalSize = (pSignalData->DcmDspDataSize / 8u);

		switch(pSignalData->DcmDspDataUsePort)
		{
		case DCM_USE_DATA_SYNCH_FNC:
		case DCM_USE_DATA_SYNCH_CLIENT_SERVER:
		case DCM_USE_DATA_ASYNCH_FNC:
		case DCM_USE_DATA_ASYNCH_FNC_ERROR:
		case DCM_USE_DATA_ASYNCH_CLIENT_SERVER:
		case DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR:
#if(STD_ON == DCM_DSP_DATA_CONDITION_CHECK_READ_FNC_ENABLED)
			/**
			 * @req [SWS_Dcm_01098] On reception of the UDS Service ReadDataByPeriodicIdentifier (0x2A),
			 * 		for every requested periodicDIDs, the Dcm module shall invoke the ConditionCheckRead
			 * 		operation (or the respective C-Function) if configured.In case of a negative result,
			 * 		the returned ErrorCode shall be used as final negative response code.
			 */
			if((boolean)TRUE == pSignalData->DcmDspDataConditionCheckReadFncUsed)
			{
				result = pSignalData->DcmDspDataConditionCheckReadFnc(opState, pErrorCode);
			}
#endif /* #if(STD_ON == DCM_DSP_DATA_CONDITION_CHECK_READ_FNC_ENABLED) */

#if(STD_ON == DCM_DSP_DATA_READ_DATA_LENGTH_FNC_ENABLED)
			/**
			 * @req [SWS_Dcm_01099] On reception of the UDS Service ReadDataByPeriodicIdentifier (0x2A),
			 * 		for every requested periodicDIDs, with a configured dynamic length the Dcm module
			 * 		shall invoke the ReadDataLength operation (or the respective C-Function) to retrieve
			 * 		the length of the periodicDID. This length is valid for each ReadData operation till
			 * 		the periodicDID is removed from the scheduler or updated via a new request. This
			 * 		length shall further be used to check against the UUDT size.
			 */
			if(((Std_ReturnType)E_OK == result) && (DCM_UINT8_DYN == pSignalData->DcmDspDataType))
			{
				result = pSignalData->DcmDspDataReadDataLengthFnc(opState, &u16SignalSize);
			}
#endif /* #if(STD_ON == DCM_DSP_DATA_READ_DATA_LENGTH_FNC_ENABLED) */
			break;
		default:
			/* Nothing to do here. */
			break;
		}

		if((Std_ReturnType)E_OK == result)
		{
			Dcm_UDS0x2AStatus.ReqDidDataLen += u16SignalSize;

#if(STD_ON == DCM_DSP_DATA_READ_DATA_LENGTH_FNC_ENABLED)
			if(DCM_UINT8_DYN == pSignalData->DcmDspDataType)
			{
				Dcm_UDS0x2AStatus.ReqDidDynDataLen = u16SignalSize;
			}
#endif /* #if(STD_ON == DCM_DSP_DATA_READ_DATA_LENGTH_FNC_ENABLED) */
		}
		else
		{
			break;
		}
	}

	return result;
}

/**
 * @brief			Dcm_UDS0x2ACheckReadCondition
 * @details			Check whether the read conditions are met and retrieve the data length.
 *
 * @param[in]		u8ReqDidIdx:DID index.
 * @param[in]		opState:Operating state.
 *
 * @param[out]		pErrorCode:Output the error NRC.
 *
 * @return        	Result of this operation.
 * @retval			E_OK:Processing successfully.
 * @retval			E_NOT_OK:Processing not successfully.
 */
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2ACheckReadCondition
(
	uint8 u8ReqDidIdx,
	Dcm_ExtendedOpStatusType opState,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_OK;

#if((STD_ON == DCM_UDS0x2C_ENABLE) && (STD_ON == DCM_UDS0x2C_SUB0x01_ENABLE))
	uint8 u8Index;
	uint8 u8ElementNum;
	uint8 u8DDDidIndex;
	Dcm_DDDIdElementStatus* pElementStatus = NULL_PTR;
	const Dcm_DspDidInfoType* pDidInfo = Dcm_ConfigPtr->DcmDsp->DcmDspDid[u8ReqDidIdx].DcmDspDidInfoRef;

	if((boolean)FALSE == pDidInfo->DcmDspDidDynamicallyDefined)
	{
		result = Dcm_UDS0x2ACheckSingleReadCondition(u8ReqDidIdx, opState, pErrorCode);
	}
	else
	{
		u8DDDidIndex = pDidInfo->DcmDspDDDIDIndex;

		Dcm_UDS0x2AStatus.ReqDDDidIndex = u8DDDidIndex;

		u8ElementNum = Dcm_DDDidStatus[u8DDDidIndex].ElementNum;

		for(u8Index = Dcm_UDS0x2AStatus.ReqElementIndex; u8Index < u8ElementNum; u8Index++)
		{
			Dcm_UDS0x2AStatus.ReqElementIndex = u8Index;

			pElementStatus = &Dcm_DDDidStatus[u8DDDidIndex].ElementStatus[u8Index];

			if((boolean)TRUE == pElementStatus->IsDidType)
			{
				result = Dcm_UDS0x2ACheckSingleReadCondition(\
							pElementStatus->Element.SrcDid.SrcDidIndex, opState, pErrorCode\
							);
			}
			else
			{
				Dcm_UDS0x2AStatus.ReqDidDataLen += (uint16)pElementStatus->Element.Memory.MemorySize;
			}

			if((Std_ReturnType)E_OK != result)
			{
				break;
			}
		}
	}
#else
	result = Dcm_UDS0x2ACheckSingleReadCondition(u8ReqDidIdx, opState, pErrorCode);
#endif /* #if((STD_ON == DCM_UDS0x2C_ENABLE) && (STD_ON == DCM_UDS0x2C_SUB0x01_ENABLE)) */

	return result;
}
#endif /* #if((STD_ON == DCM_DSP_DATA_CONDITION_CHECK_READ_FNC_ENABLED) ||\
 	 	 	  (STD_ON == DCM_DSP_DATA_READ_DATA_LENGTH_FNC_ENABLED)) */

#if((0u != DCM_DSP_DID_NUM) && (0u != DCM_DSP_DID_SIGNAL_NUM))
/**
 * @brief			Dcm_UDS0x2ACheckAllReqDidVaild
 * @details			Check whether all requested DIDs are valid.
 *
 * @param[in]		opState:Operating state.
 * @param[in]		pMsgContext:Message-related information for one diagnostic protocol identifier.
 *
 * @param[out]		pErrorCode:Output the error NRC.
 *
 * @return        	Result of this operation.
 * @retval			E_OK:Processing successfully.
 * @retval			E_NOT_OK:Processing not successfully.
 */
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2ACheckAllReqDidVaild
(
	Dcm_ExtendedOpStatusType opState,
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_OK;

	uint8 u8Index;
	uint8 u8ReqDid;
	uint8 u8PDidNum;
	uint8 u8ReqDidNum = Dcm_UDS0x2AStatus.ReqDidNum;
	uint8 u8ReqDidIdx = Dcm_UDS0x2AStatus.PendDidIndex;
	boolean flag = (boolean)FALSE;

	for(u8Index = Dcm_UDS0x2AStatus.ReqDidIndex; u8Index < u8ReqDidNum; u8Index++)
	{
		Dcm_UDS0x2AStatus.ReqDidIndex = u8Index;

		u8ReqDid = pMsgContext->ReqData[u8Index + 2u];

		/**
		 * @req [SWS_Dcm_00721] On reception of the UDS Service ReadDataByPeriodicIdentifier (0x2A), for
		 * 		every requested periodicDIDs, the Dcm module shall check if the periodicDID can be read
		 * 		in the current session (see configuration parameter DcmDspDidReadSessionRef). If none
		 * 		of the periodicDID can be read in the current session, the Dcm module shall send a NRC
		 * 		0x31 (RequestOutOfRange).
		 *
		 * @req [SWS_Dcm_00722] On reception of the UDS Service ReadDataByPeriodicIdentifier (0x2A), for
		 * 		every requested periodicDIDs, the Dcm module shall check if the periodicDID can be read
		 * 		in the current security level (see configuration parameter
		 * 		DcmDspDidReadSecurityLevelRef). If not, the Dcm module shall send NRC 0x33 (Security
		 * 		access denied).
		 */
		if((boolean)FALSE == Dcm_UDS0x2AStatus.PendState)
		{
			result = DspInternal_CheckDidValid(\
						(0xF200u | (uint16)u8ReqDid), DCM_PERMISSION_CHECK_USER_READ_DID,\
						&u8ReqDidIdx, &Dcm_UDS0x2AStatus.ReqDidSesLevelRef,\
						&Dcm_UDS0x2AStatus.ReqDidSecLevelRef, pErrorCode\
						);
#if(STD_ON == DCM_UDS0x2C_ENABLE)
			/**
			 * @req [SWS_Dcm_01097] On reception of the UDS Service ReadDataByPeriodicIdentifier (0x2A),
			 * 		if verification has been successfully done ([SWS_Dcm_00721], [SWS_Dcm_00722] and
			 * 		[SWS_Dcm_00820]), and if the request contains one or more dynamically defined
			 * 		DID(s), the Dcm module shall do the session, security and mode dependencies checks
			 * 		for all source data in case the configuration parameter DcmDspDDDIDcheckPerSourceDID
			 * 		is set to TRUE.
			 */
			if((Std_ReturnType)E_OK == result)
			{
				result = DspInternal_CheckDDDidReadValid(\
							u8ReqDidIdx, &Dcm_UDS0x2AStatus.ReqDidType, pErrorCode\
							);
			}
#endif /* #if(STD_ON == DCM_UDS0x2C_ENABLE) */
		}

#if((STD_ON == DCM_DSP_DATA_CONDITION_CHECK_READ_FNC_ENABLED) ||\
	(STD_ON == DCM_DSP_DATA_READ_DATA_LENGTH_FNC_ENABLED))
		if((Std_ReturnType)E_OK == result)
		{
			result = Dcm_UDS0x2ACheckReadCondition(u8ReqDidIdx, opState, pErrorCode);
		}
#endif /* #if((STD_ON == DCM_DSP_DATA_CONDITION_CHECK_READ_FNC_ENABLED) ||\
 	 	 	  (STD_ON == DCM_DSP_DATA_READ_DATA_LENGTH_FNC_ENABLED)) */

		if((Std_ReturnType)E_OK == result)
		{
			if(0u != Dcm_PeriodicTransStatus.PDidNum)
			{
				Dcm_UDS0x2ACheckReqDidExistInSchedulerTable(u8ReqDid, (boolean)FALSE);
			}

			u8PDidNum = Dcm_UDS0x2AStatus.ValidPDidNum;

			if(Dcm_UDS0x2AStatus.FreeSize >= (u8PDidNum + 1u))
			{
				if(7u >= Dcm_UDS0x2AStatus.ReqDidDataLen)
				{
					Dcm_UDS0x2AStatus.NewPDidInfo[u8PDidNum].PDid = u8ReqDid;
					Dcm_UDS0x2AStatus.NewPDidInfo[u8PDidNum].PDidIndex = u8ReqDidIdx;
#if(STD_ON == DCM_UDS0x2C_ENABLE)
					Dcm_UDS0x2AStatus.NewPDidInfo[u8PDidNum].PDidType = Dcm_UDS0x2AStatus.ReqDidType;
					Dcm_UDS0x2AStatus.NewPDidInfo[u8PDidNum].PDDDidIndex = Dcm_UDS0x2AStatus.ReqDDDidIndex;
#endif /* #if(STD_ON == DCM_UDS0x2C_ENABLE) */
					Dcm_UDS0x2AStatus.NewPDidInfo[u8PDidNum].DataLen = Dcm_UDS0x2AStatus.ReqDidDataLen;
					Dcm_UDS0x2AStatus.NewPDidInfo[u8PDidNum].SesLevelRef = Dcm_UDS0x2AStatus.ReqDidSesLevelRef;
					Dcm_UDS0x2AStatus.NewPDidInfo[u8PDidNum].SecLevelRef = Dcm_UDS0x2AStatus.ReqDidSecLevelRef;

					Dcm_UDS0x2AStatus.ValidPDidNum++;

					Dcm_UDS0x2AStatus.ReqDidDataLen = 0u;
					Dcm_UDS0x2AStatus.ReqSignalIndex = 0u;
#if(STD_ON == DCM_UDS0x2C_ENABLE)
					Dcm_UDS0x2AStatus.ReqDidType = 1u;
					Dcm_UDS0x2AStatus.ReqElementIndex = 0u;
#endif /* #if(STD_ON == DCM_UDS0x2C_ENABLE) */
					Dcm_UDS0x2AStatus.PendState = (boolean)FALSE;
				}
				else
				{
					*pErrorCode = DCM_E_RESPONSETOOLONG;

					result = (Std_ReturnType)E_NOT_OK;

					flag = (boolean)TRUE;
				}
			}
			else
			{
				*pErrorCode = DCM_E_REQUESTOUTOFRANGE;

				result = (Std_ReturnType)E_NOT_OK;

				flag = (boolean)TRUE;
			}
		}
		else
		{
			if((Std_ReturnType)DCM_E_PENDING == result)
			{
				Dcm_OpState = DCM_PENDING;
				*pErrorCode = DCM_E_RESPONSE_PENDING;

				flag = (boolean)TRUE;

				Dcm_UDS0x2AStatus.PendState = (boolean)TRUE;
				Dcm_UDS0x2AStatus.PendDidIndex = u8ReqDidIdx;

				result = (Std_ReturnType)E_NOT_OK;
			}
			else
			{
				if((DCM_E_SECURITYACCESSDENIED == *pErrorCode) ||\
					(DCM_E_CONDITIONSNOTCORRECT == *pErrorCode))
				{
					Dcm_PeriodicTransStatus.PDidNum = 0u;

					flag = (boolean)TRUE;
				}
			}
		}

		if((boolean)TRUE == flag)
		{
			break;
		}
	}

	/**
	 * @req [SWS_Dcm_01095]  On reception of the UDS Service ReadDataByPeriodicIdentifier (0x2A), for
	 * 		every requested periodicDIDs, the Dcm module shall check if the periodicDID is supported
	 * 		(see configuration parameter DcmDspDid). If none of the periodicDIDs are supported, the Dcm
	 * 		module shall send NRC 0x31 (Request out of range).
	 */
	if(u8Index == u8ReqDidNum)
	{
		if(0u != Dcm_UDS0x2AStatus.ValidPDidNum)
		{
			Dcm_UDS0x2AInsertNewPDidToSchedulerTable();

			result = (Std_ReturnType)E_OK;
		}
		else
		{
			*pErrorCode = DCM_E_REQUESTOUTOFRANGE;
		}
	}

	return result;
}
#endif /* #if((0u != DCM_DSP_DID_NUM) && (0u != DCM_DSP_DID_SIGNAL_NUM))) */

/**
 * @brief			Dcm_UDS0x2AStartSendHandle
 * @details			UDS service 0x2A Start-Sending sub-function processing interface.
 *
 * @param[in]		u8SubId:Sub-function identifier.
 * @param[in]		opState:Operating state.
 * @param[in]		pMsgContext:Message-related information for one diagnostic protocol identifier.
 *
 * @param[out]		pErrorCode:Output the error NRC.
 *
 * @return        	Result of this operation.
 * @retval			E_OK:Processing successfully.
 * @retval			E_NOT_OK:Processing not successfully.
 */
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2AStartSendHandle
(
	uint8 u8SubId,
	Dcm_ExtendedOpStatusType opState,
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	uint8 u8Rate = 0u;

	/**
	 * @req [SWS_Dcm_01094] On reception of the UDS Service ReadDataByPeriodicIdentifier (0x2A), the Dcm
	 * 		module shall check if the transmissionMode is supported, otherwise the Dcm module shall send
	 * 		a NRC 0x31(Request out of range).
	 */
	if((0x01u == u8SubId) && (0u != DCM_DSP_PERIODIC_TRANSMISSION_SLOW_RATE))
	{
		u8Rate = DCM_DSP_PERIODIC_TRANSMISSION_SLOW_RATE;
	}
	else if((0x02u == u8SubId) && (0u != DCM_DSP_PERIODIC_TRANSMISSION_MEDIUM_RATE))
	{
		u8Rate = DCM_DSP_PERIODIC_TRANSMISSION_MEDIUM_RATE;
	}
	else if((0x03u == u8SubId) && (0u != DCM_DSP_PERIODIC_TRANSMISSION_FAST_RATE))
	{
		u8Rate = DCM_DSP_PERIODIC_TRANSMISSION_FAST_RATE;
	}
	else
	{
		*pErrorCode = DCM_E_REQUESTOUTOFRANGE;
	}

	if((0u != u8Rate) && (DCM_DSP_MAX_PERIODIC_DID_SCHEDULER != Dcm_PeriodicTransStatus.PDidNum))
	{
		Dcm_UDS0x2AStatus.ReqRate = u8Rate;

		if(1u < Dcm_UDS0x2AStatus.ReqDidNum)
		{
			Dcm_UDS0x2AFilterDuplicateReqDid(pMsgContext);
		}

#if((0u != DCM_DSP_DID_NUM) && (0u != DCM_DSP_DID_SIGNAL_NUM))
		/**
		 * @req [SWS_Dcm_01100]  On reception of the UDS Service ReadDataByPeriodicIdentifier (0x2A)
		 * 		with transmissionMode different than stopSending, the Dcm shall do the verification for
		 * 		session, security and mode rule.
		 */
		result = Dcm_UDS0x2ACheckAllReqDidVaild(opState, pMsgContext, pErrorCode);
#else
		*pErrorCode = DCM_E_REQUESTOUTOFRANGE;
#endif /* #if((0u != DCM_DSP_DID_NUM) && (0u != DCM_DSP_DID_SIGNAL_NUM)) */
	}
	else
	{
		*pErrorCode = DCM_E_REQUESTOUTOFRANGE;
	}

	return result;
}

/**
 * @brief			Dcm_UDS0x2AStopSendHandle
 * @details			UDS service 0x2A Stop-Sending sub-function processing interface.
 *
 * @param[in]		u8ReqDidNum:Requested PDid number.
 * @param[in]		pMsgContext:Message-related information for one diagnostic protocol identifier.
 *
 *
 * @return        	Result of this operation.
 * @retval			E_OK:Processing successfully.
 * @retval			E_NOT_OK:Processing not successfully.
 */
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2AStopSendHandle
(
	uint8 u8ReqDidNum,
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext
)
{
	Std_ReturnType result = (Std_ReturnType)E_OK;

	uint8 u8ReqIndex;
	uint8 u8ScheIndex = 0u;
	uint8 u8ReqDid;
	Dcm_SessionDataType sesLevelRef;

	/**
	 * @req [SWS_Dcm_01426] On reception of the UDS Service ReadDataByPeriodicIdentifier (0x2A) with
	 * 		transmissionMode = stopSending, the Dcm shall skip the verification for security and mode
	 * 		rule.
	 *
	 * @req [SWS_Dcm_01113] On a static periodic DID stop event, the Dcm shall no longer call the
	 * 		"ReadData" function of this DIDs data (i.e. periodic DID is removed from scheduler).
	 *
	 * @req [SWS_Dcm_01114] On a dynamically defined periodic DID stop event, the Dcm shall no longer
	 * 		call any source data "ReadMemory" or "ReadData" function of the periodic DDDID (i.e.
	 * 		periodic DDDID is removed from scheduler).
	 *
	 * @req [SWS_Dcm_01117] On a periodic DID stop event, all its data in a Dcm queue (waiting to be
	 * 		transmitted) is cleared.
	 *
	 * @req [SWs_Dcm_01118] On a periodic DID stop event, Dcm will NOT try to cancel any data
	 * 		transmission already initiated by the call of PduR_DcmTransmit.
	 */

	/**
	 * @req [SWS_Dcm_01427] On reception of the UDS Service ReadDataByPeriodicIdentifier (0x2A) with
	 * 		transmissionMode = stopSending and no periodicDataIdentifier in the request, the Dcm shall
	 * 		stop all scheduled periodicDataIdentifier transmissions.
	 */
	if(0u == u8ReqDidNum)
	{
		Dcm_PeriodicTransStatus.PDidNum = 0u;
	}
	else
	{
		/**
		 * @req [SWS_Dcm_01428] On reception of the UDS Service ReadDataByPeriodicIdentifier (0x2A)
		 * 		with transmissionMode = stopSending and at least one periodicDataIdentifier is in the
		 * 		request, the Dcm shall stop the scheduled periodic data transmissions for all requested
		 * 		and in the current session supported periodicDataIdentifiers.
		 */
		for(u8ReqIndex = 0u; u8ReqIndex < u8ReqDidNum; u8ReqIndex++)
		{
			u8ReqDid = pMsgContext->ReqData[u8ReqIndex + 2u];

			while(u8ScheIndex < Dcm_PeriodicTransStatus.PDidNum)
			{
				sesLevelRef = Dcm_PeriodicTransStatus.SchedulerTable[u8ScheIndex].SesLevelRef;

				if((u8ReqDid == Dcm_PeriodicTransStatus.SchedulerTable[u8ScheIndex].PDid) &&\
					(DCM_CHECK_BIT_SET(sesLevelRef, Dcm_ActiveSessionIdx, uint8)))
				{
					DspInternal_DeletePeriodicDid(u8ScheIndex);

					break;
				}
				else
				{
					u8ScheIndex++;
				}
			}
		}
	}

	return result;
}
/*====================================================================================================*
 *                                          GLOBAL FUNCTIONS
 *====================================================================================================*/
/**
 * @brief			Dcm_UDS0x2A
 * @details			Internal processing interface for Service 0x2A.
 *
 * @param[in]		OpStatus:Operating state.
 * @param[in]		pMsgContext:Message-related information for one diagnostic protocol identifier.
 * 					The pointers in pMsgContext shall point behind the SID.
 *
 * @param[out]		ErrorCode:If the operation <Module>_<DiagnosticService> returns value  E_NOT_OK,
 * 					the DCM module shall send a negative response  with NRC code equal to the parameter
 * 					ErrorCode parameter value.
 *
 * @return        	Result of this operation.
 * @retval			E_OK:Request was successful.
 * @retval			E_NOT_OK:Request was not successful.
 */
FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2A
(
	Dcm_OpStatusType OpStatus,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	uint8 u8AddrType;
	uint8 u8ReqDidNum;
	uint8 u8SubId = pMsgContext->ReqData[1];
	const Dcm_DsdServiceType* pService = NULL_PTR;

	if(DCM_PENDING != OpStatus)
	{
		/**
		 * @req [SWS_Dcm_01093] On reception of the UDS Service ReadDataByPeriodicIdentifier (0x2A), the
		 * 		Dcm module shall check the request minimum length. If length of the request is wrong,
		 * 		the Dcm module shall send a NRC 0x13 (Incorrect message length or invalid format).
		 */
		if(2u > pMsgContext->ReqDataLen)
		{
			*ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
		}
		else
		{
			u8ReqDidNum = (uint8)(pMsgContext->ReqDataLen - 2u);
			/**
			 * @req [SWS_Dcm_00843] On reception of the UDS Service ReadDataByPeriodicIdentifier (0x2A),
			 * 		the Dcm module shall check if the periodicDataIdentifiers requested in a single
			 * 		request do not exceed the configured DcmDspMaxPeriodicDidToRead (maximum length
			 * 		check). Otherwise (in case the number of elements is exceeded) the Dcm module shall
			 * 		send a NRC 0x13 (Incorrect message length or invalid format).
			 */
			if((DCM_DSP_MAX_PERIODIC_DID_TO_READ < u8ReqDidNum) ||\
				((2u == pMsgContext->ReqDataLen) && (0x04u != u8SubId)))
			{
				*ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
			}
			else
			{
				u8AddrType = (pMsgContext->MsgAddInfo & 0x01u);

				pService = DCM_GET_SERVICE_PTR(Dcm_ConnectionStatus[Dcm_ActiveConIdx].ServiceIdx);

				if((Std_ReturnType)E_OK == DspInternal_SubServiceCheck(u8AddrType, u8SubId, pService, ErrorCode))
				{
					Dcm_UDS0x2AStatus.ReqRate = 0u;
					Dcm_UDS0x2AStatus.ReqDidIndex = 0u;
					Dcm_UDS0x2AStatus.ValidPDidNum = 0u;
					Dcm_UDS0x2AStatus.PendDidIndex = 0u;
					Dcm_UDS0x2AStatus.ReqDidDataLen = 0u;
					Dcm_UDS0x2AStatus.ReqSignalIndex = 0u;
#if(STD_ON == DCM_UDS0x2C_ENABLE)
					Dcm_UDS0x2AStatus.ReqDidType = 1u;
					Dcm_UDS0x2AStatus.ReqDDDidIndex = 0u;
					Dcm_UDS0x2AStatus.ReqElementIndex = 0u;
#endif /* #if(STD_ON == DCM_UDS0x2C_ENABLE) */
#if(STD_ON == DCM_DSP_DATA_READ_DATA_LENGTH_FNC_ENABLED)
					Dcm_UDS0x2AStatus.ReqDidDynDataLen = 0u;
#endif /* #if(STD_ON == DCM_DSP_DATA_READ_DATA_LENGTH_FNC_ENABLED) */
					Dcm_UDS0x2AStatus.ReqDidSesLevelRef = 0u;
					Dcm_UDS0x2AStatus.ReqDidSecLevelRef = 0u;
					Dcm_UDS0x2AStatus.ReqDidNum = u8ReqDidNum;
					Dcm_UDS0x2AStatus.FreeSize = (DCM_DSP_MAX_PERIODIC_DID_SCHEDULER - Dcm_PeriodicTransStatus.PDidNum);
					Dcm_UDS0x2AStatus.PendState = (boolean)FALSE;

					if(0x04u == u8SubId)
					{
						result = Dcm_UDS0x2AStopSendHandle(u8ReqDidNum, pMsgContext);
					}
					else
					{
						result = Dcm_UDS0x2AStartSendHandle(u8SubId, OpStatus, pMsgContext, ErrorCode);
					}
				}
			}
		}
	}
	else
	{
		result = Dcm_UDS0x2ACheckAllReqDidVaild(OpStatus, pMsgContext, ErrorCode);
	}

	if((Std_ReturnType)E_OK == result)
	{
		/* The minimum length of the buffer is 8 bytes, no need to check the response length. */

		pMsgContext->ResData[0] = 0x6Au;

		pMsgContext->ResDataLen = 1u;
	}

	return result;
}

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#endif /* #if(STD_ON == DCM_UDS0x2A_INTERNAL_FNC_ENABLE) */
#endif /* #if(STD_ON == DCM_UDS0x2A_ENABLE) */

#ifdef __cplusplus
}
#endif
/** @} */
