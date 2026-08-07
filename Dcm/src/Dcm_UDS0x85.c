/**
 * @file        Dcm_UDS0x85.c
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
 * 5.5087 -- Violates MISRA 2004 Required Rule 19.1, Use of #include directive after code fragment.
 *
 * @page misra_violations MISRA-C:2004 violations
 */

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
#include "Dcm_Internal.h"
#include "Dem_Dcm.h"
#ifdef AH_TEST_DCM
#include "TestCode.h"
#endif /* #ifdef AH_TEST_DCM */
#include "Rte_Dem.h"

#if(STD_ON == DCM_UDS0x85_ENABLE)
#if(STD_ON == DCM_UDS0x85_INTERNAL_FNC_ENABLE)
/**
 * @req [SWS_Dcm_00249] The Dcm module shall implement UDS Service ControlDTCSetting (0x85) to enable
 * 						or disable the storage of DTCs in the ECUs error memory.
 */
/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION
 *====================================================================================================*/
#define DCM_UDS0X85_VENDOR_ID_C                            	(0x00U)
#define DCM_UDS0X85_AR_RELEASE_MAJOR_VERSION_C             	(0x04U)
#define DCM_UDS0X85_AR_RELEASE_MINOR_VERSION_C             	(0x02U)
#define DCM_UDS0X85_AR_RELEASE_REVISION_VERSION_C          	(0x02U)
#define DCM_UDS0X85_SW_MAJOR_VERSION_C                     	(0x01U)
#define DCM_UDS0X85_SW_MINOR_VERSION_C                     	(0x02U)
#define DCM_UDS0X85_SW_PATCH_VERSION_C                     	(0x00U)
/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Dcm_Internal header file are of the same vendor */
#if(DCM_UDS0X85_VENDOR_ID_C != DCM_INTERNAL_VENDOR_ID )
#error "Dcm_UDS0x85.c and Dcm_Internal.h have different vendor id"
#endif
/* Check if current file and Dcm_Internal header file are of the same Autosar version */
#if(\
		(DCM_UDS0X85_AR_RELEASE_MAJOR_VERSION_C != DCM_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_UDS0X85_AR_RELEASE_MINOR_VERSION_C != DCM_INTERNAL_AR_RELEASE_MINOR_VERSION) || \
		(DCM_UDS0X85_AR_RELEASE_REVISION_VERSION_C != DCM_INTERNAL_AR_RELEASE_REVISION_VERSION) \
)
#error "AutoSar Version Number of Dcm_UDS0x85.c and Dcm_Internal.h are different"
#endif
/* Check if current file and Dcm_Internal header file are of the same software version */
#if(\
		(DCM_UDS0X85_SW_MAJOR_VERSION_C != DCM_INTERNAL_SW_MAJOR_VERSION) || \
		(DCM_UDS0X85_SW_MINOR_VERSION_C != DCM_INTERNAL_SW_MINOR_VERSION) || \
		(DCM_UDS0X85_SW_PATCH_VERSION_C != DCM_INTERNAL_SW_PATCH_VERSION) \
)
#error "Software Version Number of Dcm_UDS0x85.c and Dcm_Internal.h are different"
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
#define DCM_START_SEC_VAR_NO_INIT_BOOLEAN
#include "Dcm_MemMap.h"

/**
 * @brief 	Whether DTC has been disabled before.
 */
VAR(boolean, DCM_VAR)Dcm_DisableDTCState = (boolean)FALSE;

#define DCM_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "Dcm_MemMap.h"
/*====================================================================================================*
 *                                      LOCAL FUNCTION PROTOTYPES
 *====================================================================================================*/

/*====================================================================================================*
 *                                           LOCAL FUNCTIONS
 *====================================================================================================*/

/*====================================================================================================*
 *                                          GLOBAL FUNCTIONS
 *====================================================================================================*/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

/**
 * @brief			Dcm_UDS0x85
 * @details			Internal processing interface for Service 0x85.
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
FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x85
(
	Dcm_OpStatusType OpStatus,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	uint8 u8Ret;
	uint8 u8SubId;
	uint8 u8AddrType;
	uint32 u32DTC = DEM_DTC_GROUP_ALL_DTCS;
	const Dcm_DsdServiceType* pService = NULL_PTR;
	const Dcm_DspControlDTCSettingType* pControlDTC = NULL_PTR;

	if(2u > pMsgContext->ReqDataLen)
	{
		*ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
	}
	else
	{
		u8SubId = pMsgContext->ReqData[1];

		u8AddrType = (pMsgContext->MsgAddInfo & 0x01u);

		pService = DCM_GET_SERVICE_PTR(Dcm_ConnectionStatus[Dcm_ActiveConIdx].ServiceIdx);

		if((Std_ReturnType)E_OK == DspInternal_SubServiceCheck(u8AddrType, u8SubId, pService, ErrorCode))
		{
			pControlDTC = Dcm_ConfigPtr->DcmDsp->DcmDspControlDTCSetting;

			/**
			 * @req [SWS_Dcm_00829] In case the configuration parameter
			 * 		DcmSupportDTCSettingControlOptionRecord is set to true and the length of the
			 * 		optional parameter DTCSettingControlOptionRecord in the request is different from
			 * 		3 bytes, the Dcm shall return NRC 0x13 (Incorrect message length or invalid format)
			 * 		to the tester.
			 *
			 * @req [SWS_Dcm_00852] In case the configuration parameter
			 * 		DcmSupportDTCSettingControlOptionRecord is set to false the DCM shall return NRC
			 * 		0x13 (Incorrect message length or invalid format) if any data is present after the
			 * 		subFunction.
			 */
			if((((boolean)FALSE == pControlDTC->DcmSupportDTCSettingControlOptionRecord) &&\
				(2u != pMsgContext->ReqDataLen)) ||\
				(((boolean)TRUE == pControlDTC->DcmSupportDTCSettingControlOptionRecord) &&\
				(5u != pMsgContext->ReqDataLen)))
			{

				*ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
			}
			else
			{
				if((boolean)TRUE == pControlDTC->DcmSupportDTCSettingControlOptionRecord)
				{
					u32DTC = ((uint32)pMsgContext->ReqData[2] << 16u);
					u32DTC |= ((uint32)pMsgContext->ReqData[3] << 8u);
					u32DTC |= (uint32)pMsgContext->ReqData[4];
				}

				/**
				 * @req [SWS_Dcm_00304] On reception of the UDS Service 0x85 with DTCSettingType =
				 * 		on the optional parameter DTCSettingControlOptionRecord is NOT present in the
				 * 		request message, the DCM module shall call Dem_DcmEnableDTCSetting(DTCGroup,
				 * 		DTCKind)with DTCGroup = DEM_DTC_GROUP_ALL_DTCS and DTCKind =
				 * 		DEM_DTC_KIND_ALL_DTCS.
				 *
				 * @req [SWS_Dcm_01063] On reception of the UDS Service 0x85 with DTCSettingType =
				 * 		on and the optional parameter DTCSettingControlOptionRecord is present in the
				 * 		request message, the DCM module shall call Dem_DcmEnableDTCSetting(DTCGroup,
				 * 		DTCKind)with DTCGroup = DTCSettingControlOptionRecord of the request message
				 * 		and DTCKind = DEM_DTC_KIND_ALL_DTCS.
				 */
				if(0x01u == u8SubId)
				{
					u8Ret = Dem_DcmEnableDTCSetting(u32DTC, DEM_DTC_KIND_ALL_DTCS);
				}
				/**
				 * @req [SWS_Dcm_01064] On reception of the UDS Service 0x85 with DTCSettingType =
				 * 		off and the optional parameter DTCSettingControlOptionRecord is NOT present
				 * 		in the request message, the DCM module shall call Dem_DcmDisableDTCSetting(
				 * 		DTCGroup, DTCKind)with DTCGroup = DEM_DTC_GROUP_ALL_DTCS and DTCKind =
				 * 		DEM_DTC_KIND_ALL_DTCS.
				 *
				 * @req [SWS_Dcm_00406] On reception of the UDS Service 0x85 with DTCSettingType =
				 * 		off and the optional parameter DTCSettingControlOptionRecord is present in the
				 * 		request message, the DCM module shall call Dem_DcmDisableDTCSetting(DTCGroup,
				 * 		DTCKind)with DTCGroup = DTCSettingControlOptionRecord of the request message
				 * 		and DTCKind = DEM_DTC_KIND_ALL_DTCS.
				 */
				else
				{
					u8Ret = Dem_DcmDisableDTCSetting(u32DTC, DEM_DTC_KIND_ALL_DTCS);
				}

				/**
				 * @req [SWS_Dcm_00783] In case of Dem_DcmEnableDTCSetting returns
				 * 		DEM_CONTROL_DTC_SETTING_OK (see [SWS_Dcm_00304]), the DCM shall invoke a mode
				 * 		switch of the ModeDeclarationGroupPrototype DcmControlDTCSetting by calling
				 * 		SchM_Switch_<bsnp>_DcmControlDTCSetting
				 * 		(RTE_MODE_DcmControlDTCSetting_ENABLEDTCSETTING).
				 *
				 * @req [SWS_Dcm_00784] In case of Dem_DcmDisableDTCSetting returns
				 * 		DEM_CONTROL_DTC_SETTING_OK (see [SWS_Dcm_00406] ), the DCM shall invoke a mode
				 * 		switch of the ModeDeclarationGroupPrototype DcmControlDTCSetting by calling
				 * 		SchM_Switch_<bsnp>_DcmControlDTCSetting
				 * 		(RTE_MODE_DcmControlDTCSetting_DISABLEDTCSETTING).
				 */
				if((uint8)DEM_CONTROL_DTC_SETTING_OK == u8Ret)
				{
					/* The minimum length of the buffer is 8 bytes, no need to check the response length. */

					if(0x01u == u8SubId)
					{
						SchM_Switch_DcmControlDTCSetting(RTE_MODE_DcmControlDTCSetting_ENABLEDTCSETTING);
					}
					else
					{
						SchM_Switch_DcmControlDTCSetting(RTE_MODE_DcmControlDTCSetting_DISABLEDTCSETTING);

						Dcm_DisableDTCState = (boolean)TRUE;
					}

					pMsgContext->ResData[0] = 0xC5u;
					pMsgContext->ResData[1] = u8SubId;

					pMsgContext->ResDataLen = 2u;

					result = (Std_ReturnType)E_OK;
				}
				/**
				 * @req [SWS_Dcm_00830] In case of Dem_DcmDisableDTCSetting or Dem_DcmEnableDTCSetting
				 * 		returns DEM_CONTROL_DTC_WRONG_DTCGROUP (wrong groupOfDTC), the Dcm shall return
				 * 		NRC 0x31 (RequestOutOfRange).
				 */
				else
				{
					*ErrorCode = DCM_E_REQUESTOUTOFRANGE;
				}
			}
		}
	}

	return result;
}

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#endif /* #if(STD_ON == DCM_UDS0x85_INTERNAL_FNC_ENABLE) */
#endif /* #if(STD_ON == DCM_UDS0x85_ENABLE) */

#ifdef __cplusplus
}
#endif
/** @} */
