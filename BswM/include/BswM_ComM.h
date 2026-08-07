/**
 * @file        BswM_ComM.h
 * @brief       AUTOSAR BSWM_COMM - BswM_ComM driver header file.
 * @details     BswM_ComM driver header file, containing the Autosar API specification and
 *              other variables and functions that are exported by the BswM_ComM driver.
 * @version     1.2.0
 *
 * @addtogroup  BSWM_COMM
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

#ifndef BSWM_COMM_H
#define BSWM_COMM_H

#if defined(__cplusplus)
extern "C" 
{
#endif /* defined(__cplusplus) */

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
#include "BswM_Cfg.h"

#if (BSWM_COMM_ENABLED == STD_ON)
#include "ComM.h"
#endif /* (BSWM_COMM_ENABLED == STD_ON) */

/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/

#define BSWM_COMM_VENDOR_ID                    0U
#define BSWM_COMM_AR_RELEASE_MAJOR_VERSION     4U
#define BSWM_COMM_AR_RELEASE_MINOR_VERSION     2U
#define BSWM_COMM_AR_RELEASE_REVISION_VERSION  2U
#define BSWM_COMM_SW_MAJOR_VERSION             1U
#define BSWM_COMM_SW_MINOR_VERSION             2U
#define BSWM_COMM_SW_PATCH_VERSION             0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/

/* Check if current file and BswM_Cfg header file are of the same vendor */
#if(BSWM_COMM_VENDOR_ID != BSWM_CFG_VENDOR_ID )
#error "BswM_ComM.h and BswM_Cfg.h have different vendor id"
#endif
/* Check if current file and BswM_Cfg header file are of the same Autosar version */
#if(\
		(BSWM_COMM_AR_RELEASE_MAJOR_VERSION != BSWM_CFG_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_COMM_AR_RELEASE_MINOR_VERSION != BSWM_CFG_AR_RELEASE_MINOR_VERSION) || \
		(BSWM_COMM_AR_RELEASE_REVISION_VERSION != BSWM_CFG_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of BswM_ComM.h and BswM_Cfg.h are different "
#endif
/* Check if current file and BswM_Cfg header file are of the same software version */
#if(\
		(BSWM_COMM_SW_MAJOR_VERSION != BSWM_CFG_SW_MAJOR_VERSION) || \
		(BSWM_COMM_SW_MINOR_VERSION != BSWM_CFG_SW_MINOR_VERSION) || \
		(BSWM_COMM_SW_PATCH_VERSION != BSWM_CFG_SW_PATCH_VERSION) \
	)
#error "Software Version Number of BswM_ComM.h and BswM_Cfg.h are different "
#endif

#ifndef DISABLE_INTERMOD_VERSION_CHECK
#if (BSWM_COMM_ENABLED == STD_ON)
/* Check if current file and ComM header file are of the same Autosar version */
#if(\
		(BSWM_COMM_AR_RELEASE_MAJOR_VERSION != COMM_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_COMM_AR_RELEASE_MINOR_VERSION != COMM_AR_RELEASE_MINOR_VERSION) \
	)
/*#error "AutoSar Version Number of BswM_ComM.h and ComM.h are different "*/
#endif
#endif /* (BSWM_COMM_ENABLED == STD_ON) */
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

#if (BSWM_COMM_ENABLED == STD_ON)
FUNC(void, BSWM_CODE) BswM_ComM_CurrentMode(
	VAR(NetworkHandleType, AUTOMATIC) Network,
	VAR(ComM_ModeType, AUTOMATIC) RequestedMode
);

FUNC(void, BSWM_CODE) BswM_ComM_CurrentPNCMode(
	VAR(PNCHandleType, AUTOMATIC) PNC,
	VAR(ComM_PncModeType, AUTOMATIC) CurrentPncMode
);

FUNC(void, BSWM_CODE) BswM_ComM_InitiateReset(
	void
);
#endif /* (BSWM_COMM_ENABLED == STD_ON) */

#define BSWM_STOP_SEC_CODE
#include "BswM_MemMap.h"

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */
/** @} */

#endif /* #ifndef BSWM_COMM_H */
