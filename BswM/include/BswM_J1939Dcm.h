/**
 * @file        BswM_J1939Dcm.h
 * @brief       AUTOSAR BSWM_J1939DCM - BswM_J1939Dcm driver header file.
 * @details     BswM_J1939Dcm driver header file, containing the Autosar API specification and
 *              other variables and functions that are exported by the BswM_J1939Dcm driver.
 * @version     1.2.0
 *
 * @addtogroup  BSWM_J1939DCM
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

#ifndef BSWM_J1939DCM_H
#define BSWM_J1939DCM_H

#if defined(__cplusplus)
extern "C" 
{
#endif /* defined(__cplusplus) */

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/

#include "BswM_Cfg.h"

#if (STD_ON == BSWM_J1939DCM_ENABLED)
#include "J1939Dcm.h"
#endif /* (STD_ON == BSWM_J1939DCM_ENABLED) */

/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/

#define BSWM_J1939DCM_VENDOR_ID                    0U
#define BSWM_J1939DCM_AR_RELEASE_MAJOR_VERSION     4U
#define BSWM_J1939DCM_AR_RELEASE_MINOR_VERSION     2U
#define BSWM_J1939DCM_AR_RELEASE_REVISION_VERSION  2U
#define BSWM_J1939DCM_SW_MAJOR_VERSION             1U
#define BSWM_J1939DCM_SW_MINOR_VERSION             2U
#define BSWM_J1939DCM_SW_PATCH_VERSION             0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/

/* Check if current file and BswM_Cfg header file are of the same vendor */
#if(BSWM_J1939DCM_VENDOR_ID != BSWM_CFG_VENDOR_ID )
#error "BswM_J1939Dcm.h and BswM_Cfg.h have different vendor id"
#endif
/* Check if current file and BswM_Cfg header file are of the same Autosar version */
#if(\
		(BSWM_J1939DCM_AR_RELEASE_MAJOR_VERSION != BSWM_CFG_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_J1939DCM_AR_RELEASE_MINOR_VERSION != BSWM_CFG_AR_RELEASE_MINOR_VERSION) || \
		(BSWM_J1939DCM_AR_RELEASE_REVISION_VERSION != BSWM_CFG_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of BswM_J1939Dcm.h and BswM_Cfg.h are different "
#endif
/* Check if current file and BswM_Cfg header file are of the same software version */
#if(\
		(BSWM_J1939DCM_SW_MAJOR_VERSION != BSWM_CFG_SW_MAJOR_VERSION) || \
		(BSWM_J1939DCM_SW_MINOR_VERSION != BSWM_CFG_SW_MINOR_VERSION) || \
		(BSWM_J1939DCM_SW_PATCH_VERSION != BSWM_CFG_SW_PATCH_VERSION) \
	)
#error "Software Version Number of BswM_J1939Dcm.h and BswM_Cfg.h are different "
#endif

#ifndef DISABLE_INTERMOD_VERSION_CHECK
#if (STD_ON == BSWM_J1939DCM_ENABLED)
/* Check if current file and J1939Dcm header file are of the same Autosar version */
#if(\
		(BSWM_J1939DCM_AR_RELEASE_MAJOR_VERSION != J1939DCM_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_J1939DCM_AR_RELEASE_MINOR_VERSION != J1939DCM_AR_RELEASE_MINOR_VERSION) \
	)
/*#error "AutoSar Version Number of BswM_J1939Dcm.h and J1939Dcm.h are different "*/
#endif
#endif /* (STD_ON == BSWM_J1939DCM_ENABLED) */
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

#if (STD_ON == BSWM_J1939DCM_ENABLED)
FUNC(void, BSWM_CODE) BswM_J1939DcmBroadcastStatus(
	VAR(uint16, AUTOMATIC) NetworkMask
);
#endif /* (STD_ON == BSWM_J1939DCM_ENABLED) */

#define BSWM_STOP_SEC_CODE
#include "BswM_MemMap.h"

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */
/** @} */

#endif /* #ifndef BSWM_J1939DCM_H */
