/**
 * @file        BswM_FrSM.h
 * @brief       AUTOSAR BSWM_FRSM - BswM_FrSM driver header file.
 * @details     BswM_FrSM driver header file, containing the Autosar API specification and
 *              other variables and functions that are exported by the BswM_FrSM driver.
 * @version     1.2.0
 *
 * @addtogroup  BSWM_FRSM
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

#ifndef BSWM_FRSM_H
#define BSWM_FRSM_H

#if defined(__cplusplus)
extern "C" 
{
#endif /* defined(__cplusplus) */

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
#include "BswM_Cfg.h"

#if (STD_ON == BSWM_FRSM_ENABLED)
#include "FrSM.h"
#endif /* (STD_ON == BSWM_FRSM_ENABLED) */

/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/

#define BSWM_FRSM_VENDOR_ID                    0U
#define BSWM_FRSM_AR_RELEASE_MAJOR_VERSION     4U
#define BSWM_FRSM_AR_RELEASE_MINOR_VERSION     2U
#define BSWM_FRSM_AR_RELEASE_REVISION_VERSION  2U
#define BSWM_FRSM_SW_MAJOR_VERSION             1U
#define BSWM_FRSM_SW_MINOR_VERSION             2U
#define BSWM_FRSM_SW_PATCH_VERSION             0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/

/* Check if current file and BswM_Cfg header file are of the same vendor */
#if(BSWM_FRSM_VENDOR_ID != BSWM_CFG_VENDOR_ID )
#error "BswM_FrSM.h and BswM_Cfg.h have different vendor id"
#endif
/* Check if current file and BswM_Cfg header file are of the same Autosar version */
#if(\
		(BSWM_FRSM_AR_RELEASE_MAJOR_VERSION != BSWM_CFG_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_FRSM_AR_RELEASE_MINOR_VERSION != BSWM_CFG_AR_RELEASE_MINOR_VERSION) || \
		(BSWM_FRSM_AR_RELEASE_REVISION_VERSION != BSWM_CFG_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of BswM_FrSM.h and BswM_Cfg.h are different "
#endif
/* Check if current file and BswM_Cfg header file are of the same software version */
#if(\
		(BSWM_FRSM_SW_MAJOR_VERSION != BSWM_CFG_SW_MAJOR_VERSION) || \
		(BSWM_FRSM_SW_MINOR_VERSION != BSWM_CFG_SW_MINOR_VERSION) || \
		(BSWM_FRSM_SW_PATCH_VERSION != BSWM_CFG_SW_PATCH_VERSION) \
	)
#error "Software Version Number of BswM_FrSM.h and BswM_Cfg.h are different "
#endif

#ifndef DISABLE_INTERMOD_VERSION_CHECK
#if (STD_ON == BSWM_FRSM_ENABLED)
/* Check if current file and FrSM header file are of the same Autosar version */
#if(\
		(BSWM_FRSM_AR_RELEASE_MAJOR_VERSION != FRSM_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_FRSM_AR_RELEASE_MINOR_VERSION != FRSM_AR_RELEASE_MINOR_VERSION) \
	)
/*#error "AutoSar Version Number of BswM_FrSM.h and FrSM.h are different "*/
#endif
#endif /* (STD_ON == BSWM_FRSM_ENABLED) */
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

#if (STD_ON == BSWM_FRSM_ENABLED)
FUNC(void, BSWM_CODE) BswM_FrSM_CurrentState(
	VAR(NetworkHandleType, AUTOMATIC) Network,
	VAR(FrSM_BswM_StateType, AUTOMATIC) CurrentState
);
#endif /* (STD_ON == BSWM_FRSM_ENABLED) */

#define BSWM_STOP_SEC_CODE
#include "BswM_MemMap.h"

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */
/** @} */

#endif /* #ifndef BSWM_FRSM_H */
