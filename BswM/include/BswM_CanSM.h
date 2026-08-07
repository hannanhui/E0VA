/**
 * @file        BswM_CanSM.h
 * @brief       AUTOSAR BSWM_CANSM - BswM_CanSM driver header file.
 * @details     BswM_CanSM driver header file, containing the Autosar API specification and
 *              other variables and functions that are exported by the BswM_CanSM driver.
 * @version     1.2.0
 *
 * @addtogroup  BSWM_CANSM
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

#ifndef BSWM_CANSM_H
#define BSWM_CANSM_H

#if defined(__cplusplus)
extern "C" 
{
#endif /* defined(__cplusplus) */
/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/

#include "BswM_Cfg.h"

#if ((STD_ON == BSWM_CANSM_ICOM_ENABLED) || (STD_ON == BSWM_CANSM_ENABLED))
#include "CanSM_BswM.h"
#endif /* ((STD_ON == BSWM_CANSM_ICOM_ENABLED) || (STD_ON == BSWM_CANSM_ENABLED)) */

/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/

#define BSWM_CANSM_VENDOR_ID                    0U
#define BSWM_CANSM_AR_RELEASE_MAJOR_VERSION     4U
#define BSWM_CANSM_AR_RELEASE_MINOR_VERSION     2U
#define BSWM_CANSM_AR_RELEASE_REVISION_VERSION  2U
#define BSWM_CANSM_SW_MAJOR_VERSION             1U
#define BSWM_CANSM_SW_MINOR_VERSION             2U
#define BSWM_CANSM_SW_PATCH_VERSION             0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/

/* Check if current file and BswM_Cfg header file are of the same vendor */
#if(BSWM_CANSM_VENDOR_ID != BSWM_CFG_VENDOR_ID )
#error "BswM_CanSM.h and BswM_Cfg.h have different vendor id"
#endif
/* Check if current file and BswM_Cfg header file are of the same Autosar version */
#if(\
		(BSWM_CANSM_AR_RELEASE_MAJOR_VERSION != BSWM_CFG_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_CANSM_AR_RELEASE_MINOR_VERSION != BSWM_CFG_AR_RELEASE_MINOR_VERSION) || \
		(BSWM_CANSM_AR_RELEASE_REVISION_VERSION != BSWM_CFG_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of BswM_CanSM.h and BswM_Cfg.h are different "
#endif
/* Check if current file and BswM_Cfg header file are of the same software version */
#if(\
		(BSWM_CANSM_SW_MAJOR_VERSION != BSWM_CFG_SW_MAJOR_VERSION) || \
		(BSWM_CANSM_SW_MINOR_VERSION != BSWM_CFG_SW_MINOR_VERSION) || \
		(BSWM_CANSM_SW_PATCH_VERSION != BSWM_CFG_SW_PATCH_VERSION) \
	)
#error "Software Version Number of BswM_CanSM.h and BswM_Cfg.h are different "
#endif

#ifndef DISABLE_INTERMOD_VERSION_CHECK
#if ((STD_ON == BSWM_CANSM_ICOM_ENABLED) || (STD_ON == BSWM_CANSM_ENABLED))
/* Check if current file and CanSM header file are of the same Autosar version */
#if(\
		(BSWM_CANSM_AR_RELEASE_MAJOR_VERSION != CANSM_BSWM_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_CANSM_AR_RELEASE_MINOR_VERSION != CANSM_BSWM_AR_RELEASE_MINOR_VERSION) \
	)
/*#error "AutoSar Version Number of BswM_CanSM.h and CanSM.h are different "*/
#endif
#endif /* ((STD_ON == BSWM_CANSM_ICOM_ENABLED) || (STD_ON == BSWM_CANSM_ENABLED)) */
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

#if (STD_ON == BSWM_CANSM_ICOM_ENABLED)
FUNC(void, BSWM_CODE) BswM_CanSM_CurrentIcomConfiguration(
	VAR(NetworkHandleType, AUTOMATIC) Network,
	VAR(IcomConfigIdType, AUTOMATIC) ActiveConfiguration,
	VAR(IcomSwitch_ErrorType, AUTOMATIC) Error
);
#endif /* (STD_ON == BSWM_CANSM_ICOM_ENABLED) */

#if (STD_ON == BSWM_CANSM_ENABLED)
FUNC(void, BSWM_CODE) BswM_CanSM_CurrentState(
	VAR(NetworkHandleType, AUTOMATIC) Network,
	VAR(CanSM_BswMCurrentStateType, AUTOMATIC) CurrentState
);
#endif /* (STD_ON == BSWM_CANSM_ENABLED) */

#define BSWM_STOP_SEC_CODE
#include "BswM_MemMap.h"

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */
/** @} */

#endif /* !defined BSWM_CANSM_H */
