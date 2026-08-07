/**
 * @file        BswM.h
 * @brief       AUTOSAR BSWM - BswM driver header file.
 * @details     BswM driver header file, containing the Autosar API specification and
 *              other variables and functions that are exported by the BswM driver.
 * @version     1.2.0
 *
 * @addtogroup  BswM
 * @{
 */
/*====================================================================================================*
 * AngHui AUTOSAR BSW.
 *
 * Copyright(C) 2026 GuoKeAngHui Inc.
 *
 * All rights reserved.
 *
 * This file is part of AngHui AUTOSAR BSW, contains proprietary information.
 * Passing on and copying of this document, and communication of its contents
 * is not permitted without prior written authorization.
 *====================================================================================================*/
#ifndef BSWM_H
#define BSWM_H

#if defined(__cplusplus)
extern "C" 
{
#endif /* defined(__cplusplus) */

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/

#include "Std_Types.h"
#include "BswM_Cfg.h"
#include "BswM_Types.h"
#if (STD_ON == BSWM_GENERIC_REQUEST_ENABLED)
#include "BswM_Generic.h"
#endif /* (STD_ON == BSWM_GENERIC_REQUEST_ENABLED) */
/*#include "Rte_BswM_Type.h "*/

/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/

#define BSWM_MODULE_ID                    42U
#define BSWM_VENDOR_ID                    0U
#define BSWM_AR_RELEASE_MAJOR_VERSION     4U
#define BSWM_AR_RELEASE_MINOR_VERSION     2U
#define BSWM_AR_RELEASE_REVISION_VERSION  2U
#define BSWM_SW_MAJOR_VERSION             1U
#define BSWM_SW_MINOR_VERSION             2U
#define BSWM_SW_PATCH_VERSION             0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/

/* Check if current file and BswM_Cfg header file are of the same vendor */
#if(BSWM_VENDOR_ID != BSWM_CFG_VENDOR_ID )
#error "BswM.h and BswM_Cfg.h have different vendor id"
#endif
/* Check if current file and BswM_Cfg header file are of the same Autosar version */
#if(\
		(BSWM_AR_RELEASE_MAJOR_VERSION != BSWM_CFG_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_AR_RELEASE_MINOR_VERSION != BSWM_CFG_AR_RELEASE_MINOR_VERSION) || \
		(BSWM_AR_RELEASE_REVISION_VERSION != BSWM_CFG_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of BswM.h and BswM_Cfg.h are different "
#endif
/* Check if current file and BswM_Cfg header file are of the same software version */
#if(\
		(BSWM_SW_MAJOR_VERSION != BSWM_CFG_SW_MAJOR_VERSION) || \
		(BSWM_SW_MINOR_VERSION != BSWM_CFG_SW_MINOR_VERSION) || \
		(BSWM_SW_PATCH_VERSION != BSWM_CFG_SW_PATCH_VERSION) \
	)
#error "Software Version Number of BswM.h and BswM_Cfg.h are different "
#endif

/* Check if current file and BswM_Types header file are of the same vendor */
#if(BSWM_VENDOR_ID != BSWM_TYPES_VENDOR_ID )
#error "BswM.h and BswM_Types.h have different vendor id"
#endif
/* Check if current file and BswM_Types header file are of the same Autosar version */
#if(\
		(BSWM_AR_RELEASE_MAJOR_VERSION != BSWM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_AR_RELEASE_MINOR_VERSION != BSWM_TYPES_AR_RELEASE_MINOR_VERSION) || \
		(BSWM_AR_RELEASE_REVISION_VERSION != BSWM_TYPES_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of BswM.h and BswM_Types.h are different "
#endif
/* Check if current file and BswM_Types header file are of the same software version */
#if(\
		(BSWM_SW_MAJOR_VERSION != BSWM_TYPES_SW_MAJOR_VERSION) || \
		(BSWM_SW_MINOR_VERSION != BSWM_TYPES_SW_MINOR_VERSION) || \
		(BSWM_SW_PATCH_VERSION != BSWM_TYPES_SW_PATCH_VERSION) \
	)
#error "Software Version Number of BswM.h and BswM_Types.h are different "
#endif

#if (STD_ON == BSWM_GENERIC_REQUEST_ENABLED)
/* Check if current file and BswM_Generic header file are of the same vendor */
#if(BSWM_VENDOR_ID != BSWM_GENERIC_VENDOR_ID )
#error "BswM.h and BswM_Generic.h have different vendor id"
#endif
/* Check if current file and BswM_Generic header file are of the same Autosar version */
#if(\
		(BSWM_AR_RELEASE_MAJOR_VERSION != BSWM_GENERIC_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_AR_RELEASE_MINOR_VERSION != BSWM_GENERIC_AR_RELEASE_MINOR_VERSION) || \
		(BSWM_AR_RELEASE_REVISION_VERSION != BSWM_GENERIC_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of BswM.h and BswM_Generic.h are different "
#endif
/* Check if current file and BswM_Generic header file are of the same software version */
#if(\
		(BSWM_SW_MAJOR_VERSION != BSWM_GENERIC_SW_MAJOR_VERSION) || \
		(BSWM_SW_MINOR_VERSION != BSWM_GENERIC_SW_MINOR_VERSION) || \
		(BSWM_SW_PATCH_VERSION != BSWM_GENERIC_SW_PATCH_VERSION) \
	)
#error "Software Version Number of BswM.h and BswM_Generic.h are different "
#endif
#endif /* (STD_ON == BSWM_GENERIC_REQUEST_ENABLED) */

#ifndef DISABLE_INTERMOD_VERSION_CHECK
/* Check if current file and Std_Types header file are of the same Autosar version */
#if(\
		(BSWM_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
	)
#error "AutoSar Version Number of BswM.h and Std_Types.h are different "
#endif
#endif
/*====================================================================================================*
 *                                             CONSTANTS
 *====================================================================================================*/

/*====================================================================================================*
 *                                         DEFINES AND MACROS
 *====================================================================================================*/

/**
 * @{
 * @brief Api Ids
 */
#define BSWM_SID_INIT                                ((uint8) 0x00u)
#define BSWM_SID_REQUESTMODE                         ((uint8) 0x02u)
#define BSWM_SID_MAINFUNCTION                        ((uint8) 0x03u)
#define BSWM_SID_GETVERSIONINFO                      ((uint8) 0x01u)
#define BSWM_SID_DEINIT                              ((uint8) 0x04u)
#define BSWM_SID_WDGM_REQUESTEDPARTITIONRESET        ((uint8) 0x11u)
#define BSWM_SID_LINTP_REQUESTEDMODE                 ((uint8) 0x0bu)
#define BSWM_SID_BSWMPARTITIONRESTARTED              ((uint8) 0x1eu)
#define BSWM_SID_CANSM_CURRENTICOMCONFIGURATION      ((uint8) 0x1au)
#define BSWM_SID_CANSM_CURRENTSTATE                  ((uint8) 0x05u)
#define BSWM_SID_COMM_CURRENTMODE                    ((uint8) 0x0eu)
#define BSWM_SID_COMM_CURRENTPNCMODE                 ((uint8) 0x15u)
#define BSWM_SID_COMM_INITIATERESET                  ((uint8) 0x22u)
#define BSWM_SID_DCM_APPLICATIONUPDATED              ((uint8) 0x14u)
#define BSWM_SID_DCM_COMMUNICATIONMODE_CURRENTSTATE  ((uint8) 0x06u)
#define BSWM_SID_ECUM_CURRENTSTATE                   ((uint8) 0x0fu)
#define BSWM_SID_ECUM_CURRENTWAKEUP                  ((uint8) 0x10u)
#define BSWM_SID_ECUM_REQUESTEDSTATE                 ((uint8) 0x23u)
#define BSWM_SID_ETHSM_CURRENTSTATE                  ((uint8) 0x0du)
#define BSWM_SID_FRSM_CURRENTSTATE                   ((uint8) 0x0cu)
#define BSWM_SID_J1939DCMBROADCASTSTATUS             ((uint8) 0x1bu)
#define BSWM_SID_J1939NM_STATECHANGENOTIFICATION     ((uint8) 0x18u)
#define BSWM_SID_LINSM_CURRENTSCHEDULE               ((uint8) 0x0au)
#define BSWM_SID_LINSM_CURRENTSTATE                  ((uint8) 0x09u)
#define BSWM_SID_NMIF_CARWAKEUPINDICATION            ((uint8) 0x24u)
#define BSWM_SID_NVM_CURRENTBLOCKMODE                ((uint8) 0x16u)
#define BSWM_SID_NVM_CURRENTJOBMODE                  ((uint8) 0x17u)
#define BSWM_SID_SD_CLIENTSERVICECURRENTSTATE        ((uint8) 0x1fu)
#define BSWM_SID_SD_CONSUMEDEVENTGROUPCURRENTSTATE   ((uint8) 0x21u)
#define BSWM_SID_SD_EVENTHANDLERCURRENTSTATE         ((uint8) 0x20u)
/** @} */

/**
 * @{
 * @brief Development Error Ids
 */
#define BSWM_E_NO_INIT                       ((uint8) 0x01u)
#define BSWM_E_NULL_POINTER                  ((uint8) 0x02u)
#define BSWM_E_PARAM_INVALID                 ((uint8) 0x03u)
#define BSWM_E_REQ_USER_OUT_OF_RANGE         ((uint8) 0x04u)
#define BSWM_E_REQ_MODE_OUT_OF_RANGE         ((uint8) 0x05u)
#define BSWM_E_PARAM_CONFIG                  ((uint8) 0x06u)
#define BSWM_E_PARAM_POINTER                 ((uint8) 0x07u)
#define BSWM_E_INIT_FAILED                   ((uint8) 0x08u)
#define BSWM_E_HANDLE_FAILED                 ((uint8) 0x09u)
#define BSWM_E_GET_LOCK_TIMEOUT              ((uint8) 0x0Au)
#define BSWM_E_GET_MODERUQUEST_TIMEOUT       ((uint8) 0x0Bu)
/** @} */

#define BSWM_LOCK_TIMEOUT                    ((uint32) 100u)

#define BSWM_INVALID_IDX   0xFFFFFFFFU

typedef BswM_RuleStateType BswM_ConditionStateType;

/*Declaring configuration Set Objects*/
BSWM_CONFIG_PB
/*====================================================================================================*
 *                                               ENUMS
 *====================================================================================================*/

/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS
 *====================================================================================================*/



/*====================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS
 *====================================================================================================*/

/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES
 *====================================================================================================*/
#define BSWM_START_SEC_CODE
#include "BswM_MemMap.h"

FUNC(void, BSWM_CODE) BswM_Init(
	P2CONST(BswM_ConfigType, AUTOMATIC, BSWM_APPL_CONST) ConfigPtr
);

FUNC(void, BSWM_CODE) BswM_MainFunction(void);

#if (STD_ON == BSWM_VERSION_INFO_API)
FUNC(void, BSWM_CODE) BswM_GetVersionInfo(
	P2VAR(Std_VersionInfoType, AUTOMATIC, BSWM_APPL_DATA) VersionInfo
);
#endif /* STD_ON == BSWM_VERSION_INFO_API */

FUNC(void, BSWM_CODE) BswM_Deinit(
	void
);

#define BSWM_STOP_SEC_CODE
#include "BswM_MemMap.h"

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */
/** @} */

#endif /* #ifndef BSWM_H */
