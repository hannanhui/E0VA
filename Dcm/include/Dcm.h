/**
 * @file        Dcm.h
 * @brief       AUTOSAR 4.2.2 - 4.2.2 driver header file.
 * @details     Dcm driver header file, containing the Autosar API specification and
 *              other variables and functions that are exported by the Dcm driver.
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

#ifndef DCM_H
#define DCM_H

#ifdef __cplusplus
extern "C"{
#endif

/* PRQA S 3453 EOF #
 *
 * 1.3453 -- Violates MISRA 2004 Required Rule 19.7, A function could probably be used instead of this
 * function-like macro.
 *
 * @page misra_violations MISRA-C:2004 violations
 */

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
#include "Dcm_Types.h"
#include "Dem.h"
#if(STD_ON == DCM_DEV_ERROR_DETECT)
#include "Det.h"
#endif /* #if(STD_ON == DCM_DEV_ERROR_DETECT) */
/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/
/**
 * @req [SWS_Dcm_00052] The header file of the DCM, DCM.h, shall provide a module ID called
 * 		DCM_MODULE_ID set to the value 0x35.
 */
#define DCM_VENDOR_ID	                                 	(0x00U)
#define DCM_MODULE_ID										(0x35U)
#define DCM_AR_RELEASE_MAJOR_VERSION	                  	(0x04U)
#define DCM_AR_RELEASE_MINOR_VERSION	                  	(0x02U)
#define DCM_AR_RELEASE_REVISION_VERSION	               		(0x02U)
#define DCM_SW_MAJOR_VERSION	                          	(0x01U)
#define DCM_SW_MINOR_VERSION	                          	(0x02U)
#define DCM_SW_PATCH_VERSION	                          	(0x00U)
/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Dcm_Types header file are of the same vendor */
#if(DCM_VENDOR_ID != DCM_TYPES_VENDOR_ID )
#error "Dcm.h and Dcm_Types.h have different vendor id"
#endif
/* Check if current file and Dcm_Types header file are of the same Autosar version */
#if(\
		(DCM_AR_RELEASE_MAJOR_VERSION != DCM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_AR_RELEASE_MINOR_VERSION != DCM_TYPES_AR_RELEASE_MINOR_VERSION) || \
		(DCM_AR_RELEASE_REVISION_VERSION != DCM_TYPES_AR_RELEASE_REVISION_VERSION) \
)
#error "AutoSar Version Number of Dcm.h and Dcm_Types.h are different"
#endif
/* Check if current file and Dcm_Types header file are of the same software version */
#if(\
		(DCM_SW_MAJOR_VERSION != DCM_TYPES_SW_MAJOR_VERSION) || \
		(DCM_SW_MINOR_VERSION != DCM_TYPES_SW_MINOR_VERSION) || \
		(DCM_SW_PATCH_VERSION != DCM_TYPES_SW_PATCH_VERSION) \
)
#error "Software Version Number of Dcm.h and Dcm_Types.h are different"
#endif
#ifndef DISABLE_INTERMOD_VERSION_CHECK
/* Check if current file and Dem header file are of the same Autosar version */
#if(\
		(DCM_AR_RELEASE_MAJOR_VERSION != DEM_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_AR_RELEASE_MINOR_VERSION != DEM_AR_RELEASE_MINOR_VERSION) \
)
#error "AutoSar Version Number of Dcm.h and Dem.h are different"
#endif
#if(STD_ON == DCM_DEV_ERROR_DETECT)
/* Check if current file and Det header file are of the same Autosar version */
#if(\
		(DCM_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION) \
)
#error "AutoSar Version Number of Dcm.h and Det.h are different"
#endif
#endif
#endif
/*====================================================================================================*
 *                                             CONSTANTS
 *====================================================================================================*/

/*====================================================================================================*
 *                                         DEFINES AND MACROS
 *====================================================================================================*/
/**
 * @req [SWS_Dcm_00044] The used return values shall be the same for development and production. Only
 * 		the values given by the DCM SWS shall be used.
 *
 * @req [SWS_Dcm_00040] The following errors and exceptions shall be detectable by the DCM module
 * 		depending on its build version (development/production mode).
 */
#define DCM_E_INTERFACE_RETURN_VALUE 							((uint8)0x02)
#define DCM_E_INTERFACE_BUFFER_OVERFLOW 						((uint8)0x03)
#define DCM_E_UNINIT 											((uint8)0x05)
#define DCM_E_PARAM 											((uint8)0x06)
#define DCM_E_PARAM_POINTER 									((uint8)0x07)
#define DCM_E_INIT_FAILED 										((uint8)0x08)
#define DCM_E_SET_PROG_CONDITIONS_FAIL 							((uint8)0x09)

#define DCM_E_INVALID_VALUE 									((uint8)0x01)
#define DCM_E_INTERFACE_TIMEOUT 								((uint8)0x0A)

#define DCM_E_FORCE_RCRRP_IN_SILENT_COMM						((uint8)0x0B)

/**
 * @brief	The API identifier definitions.
 */
#define DCM_SID_INIT                            				((uint8)0x01)
#define DCM_SID_GETVERSIONINFO                  				((uint8)0x24)
#define DCM_SID_DEMTRIGGERONDTCSTATUS							((uint8)0x2B)
#define DCM_SID_GETVIN                          				((uint8)0x07)
#define DCM_SID_SETDEAUTHENTICATEDROLE							((uint8)0x79)
#define DCM_SID_GETSECURITYLEVEL                				((uint8)0x0D)
#define DCM_SID_GETSESCTRLTYPE                  				((uint8)0x06)
#define DCM_SID_GETACTIVEPROTOCOL               				((uint8)0x0F)
#define DCM_SID_RESETTODEFAULTSESSION							((uint8)0x2A)
#define DCM_SID_TRIGGERONEVENT									((uint8)0x2D)
#define DCM_SID_SETACTIVEDIAGNOSTIC             				((uint8)0x56)
#define DCM_SID_STARTOFRECEPTION                				((uint8)0x46)
#define DCM_SID_COPYRXDATA                      				((uint8)0x44)
#define DCM_SID_TPRXINDICATION                  				((uint8)0x45)
#define DCM_SID_COPYTXDATA                      				((uint8)0x43)
#define DCM_SID_TPTXCONFIRMATION                				((uint8)0x48)
#define DCM_SID_TXCONFIRMATION                  				((uint8)0x40)
#define DCM_SID_COMMNOCOMMODEENTERED            				((uint8)0x21)
#define DCM_SID_COMMSILENTCOMMODEENTERED        				((uint8)0x22)
#define DCM_SID_COMMFULLCOMMODEENTERED          				((uint8)0x23)
#define DCM_SID_CSMASYNCJOBFINISHED								((uint8)0xFF)
#define DCM_SID_KEYMASYNCCERTIFICATEVERIFYFINISHED				((uint8)0xFF)
#define DCM_SID_READMEMORY										((uint8)0x26)
#define DCM_SID_WRITEMEMORY										((uint8)0x27)
#define DCM_SID_SETPROGCONDITIONS								((uint8)0x61)
#define DCM_SID_GETPROGCONDITIONS								((uint8)0x62)
#define DCM_SID_PROCESSREQUESTADDFILE							((uint8)0x72)
#define DCM_SID_PROCESSREQUESTDELETEFILE						((uint8)0x73)
#define DCM_SID_PROCESSREQUESTREPLACEFILE						((uint8)0x74)
#define DCM_SID_PROCESSREQUESTREADFILE							((uint8)0x75)
#define DCM_SID_PROCESSREQUESTREADDIR							((uint8)0x76)
#define DCM_SID_WRITEFILE										((uint8)0x77)
#define DCM_SID_READFILEORDIR									((uint8)0x78)
#define DCM_SID_MAINFUNCTION									((uint8)0x25)

/**
 * @brief	Macro function to DET error report.
 */
#if(STD_ON == DCM_DEV_ERROR_DETECT)
#define DCM_DET_ERROR_REPORT(ApiId,ErrorId)	\
	do{ \
		(void)Det_ReportError(DCM_MODULE_ID,DCM_VENDOR_ID,ApiId,ErrorId); \
	}while(0)
#else
#define DCM_DET_ERROR_REPORT(ApiId,ErrorId)	do{ }while(0)
#endif /* #if(STD_ON == DCM_DEV_ERROR_DETECT) */

/**
 * @brief	Macro function to set a specific bit of variable to 1.
 */
#define DCM_BIT_SET(Var,Bit,Type) \
	do{ \
		(Var) |= (Type)((Type)1 << (Bit));\
	}while(0)

/**
 * @brief	Macro function to clear a specific bit of variable to 0.
 */
#define DCM_BIT_CLEAR(Var,Bit,Type) \
	do{ \
		(Var) &= (Type)(~(Type)((Type)1 << (Bit)));\
	}while(0)

/**
 * @brief	Macro function to check whether a specific bit of a variable is set to 1.
 */
#define DCM_CHECK_BIT_SET(Var,Bit,Type)	(((Var) & (Type)((Type)1 << (Bit))) != 0u)

/**
 * @brief	Macro function to copy data of a specified length from the source address to the
 * 			destination address.
 */
#define DCM_MEMORY_COPY(Src,Dest,Size) \
	do{\
		const uint8* pSrc = (uint8*)(Src);\
		uint8* pDest = (uint8*)(Dest);\
		uint32 u32Size = (uint32)(Size);\
		while((uint32)0 < u32Size)\
		{\
			*pDest = *pSrc;\
			pSrc++;\
			pDest++;\
			u32Size--;\
		}\
	}while(0)

/**
 * @brief	Clear the internal buffer.
 */
#define DCM_BUFFER_CLEAR(Src,Size) \
	do{ \
		uint8* pSrc = (uint8*)(Src);\
		uint32 u32Size = (uint32)(Size);\
		while((uint32)0 < u32Size)\
		{ \
			*pSrc = (uint8)0;\
			pSrc++;\
			u32Size--;\
		}\
	}while(0)
/*====================================================================================================*
 *                                               ENUMS
 *====================================================================================================*/

/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS
 *====================================================================================================*/

/*====================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS
 *====================================================================================================*/
extern CONST(Dcm_ConfigType, DCM_CONST)Dcm_Config;
/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES
 *====================================================================================================*/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

/**
 * @req [SWS_Dcm_01065] The file Dcm.h shall provide all type definitions and APIs used by other BSW
 * 		modules for direct calls as described in chapter 8.3 Function definitions.
 */

FUNC(void, DCM_CODE)Dcm_Init
(
	P2CONST(Dcm_ConfigType, AUTOMATIC, DCM_CONST)ConfigPtr
);

#if(STD_ON == DCM_VERSION_INFO_API)
FUNC(void, DCM_CODE)Dcm_GetVersionInfo
(
	P2VAR(Std_VersionInfoType, AUTOMATIC, DCM_VAR)VersionInfo
);
#endif /* #if(STD_ON == DCM_VERSION_INFO_API) */

FUNC(Std_ReturnType, DCM_CODE)Dcm_GetVin
(
	P2VAR(uint8, AUTOMATIC, DCM_VAR)Data
);

FUNC(Std_ReturnType, DCM_CODE)Dcm_GetSecurityLevel
(
	P2VAR(Dcm_SecLevelType, AUTOMATIC, DCM_VAR)SecLevel
);

FUNC(Std_ReturnType, DCM_CODE)Dcm_GetSesCtrlType
(
	P2VAR(Dcm_SesCtrlType, AUTOMATIC, DCM_VAR)SesType
);

FUNC(Std_ReturnType, DCM_CODE)Dcm_GetActiveProtocol
(
	P2VAR(Dcm_ProtocolType, AUTOMATIC, DCM_VAR)ActiveProtocolType,
	P2VAR(uint16, AUTOMATIC, DCM_VAR)ConnectionId,
	P2VAR(uint16, AUTOMATIC, DCM_VAR)TesterSourceAddress
);

FUNC(Std_ReturnType, DCM_CODE)Dcm_ResetToDefaultSession
(
	void
);

FUNC(Std_ReturnType, DCM_CODE)Dcm_TriggerOnEvent
(
	uint8 RoeEventId
);

FUNC(Std_ReturnType, DCM_CODE)Dcm_SetActiveDiagnostic
(
	boolean Active
);

FUNC(void, DCM_CODE)Dcm_MainFunction
(
	void
);

FUNC(Std_ReturnType, DCM_CODE)Dcm_DemTriggerOnDTCStatus
(
	uint32 DTC,
	Dem_UdsStatusByteType DTCStatusOld,
	Dem_UdsStatusByteType DTCStatusNew
);

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* DCM_H */
/** @} */
