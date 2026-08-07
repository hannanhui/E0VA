/**
 * @file        BswM_Sd.h
 * @brief       AUTOSAR BSWM_SD - BswM_Sd driver header file.
 * @details     BswM_Sd driver header file, containing the Autosar API specification and
 *              other variables and functions that are exported by the BswM_Sd driver.
 * @version     1.2.0
 *
 * @addtogroup  BSWM_SD
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
#ifndef BSWM_SD_H
#define BSWM_SD_H

#if defined(__cplusplus)
extern "C" 
{
#endif /* defined(__cplusplus) */

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/

#include "BswM_Cfg.h"

#if (STD_ON == BSWM_SD_ENABLED)
#include "Sd.h"
#endif /* (STD_ON == BSWM_SD_ENABLED) */

/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/

#define BSWM_SD_VENDOR_ID                    0U
#define BSWM_SD_AR_RELEASE_MAJOR_VERSION     4U
#define BSWM_SD_AR_RELEASE_MINOR_VERSION     2U
#define BSWM_SD_AR_RELEASE_REVISION_VERSION  2U
#define BSWM_SD_SW_MAJOR_VERSION             1U
#define BSWM_SD_SW_MINOR_VERSION             2U
#define BSWM_SD_SW_PATCH_VERSION             0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/

/* Check if current file and BswM_Cfg header file are of the same vendor */
#if(BSWM_SD_VENDOR_ID != BSWM_CFG_VENDOR_ID )
#error "BswM_Sd.h and BswM_Cfg.h have different vendor id"
#endif
/* Check if current file and BswM_Cfg header file are of the same Autosar version */
#if(\
		(BSWM_SD_AR_RELEASE_MAJOR_VERSION != BSWM_CFG_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_SD_AR_RELEASE_MINOR_VERSION != BSWM_CFG_AR_RELEASE_MINOR_VERSION) || \
		(BSWM_SD_AR_RELEASE_REVISION_VERSION != BSWM_CFG_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of BswM_Sd.h and BswM_Cfg.h are different "
#endif
/* Check if current file and BswM_Cfg header file are of the same software version */
#if(\
		(BSWM_SD_SW_MAJOR_VERSION != BSWM_CFG_SW_MAJOR_VERSION) || \
		(BSWM_SD_SW_MINOR_VERSION != BSWM_CFG_SW_MINOR_VERSION) || \
		(BSWM_SD_SW_PATCH_VERSION != BSWM_CFG_SW_PATCH_VERSION) \
	)
#error "Software Version Number of BswM_Sd.h and BswM_Cfg.h are different "
#endif

#ifndef DISABLE_INTERMOD_VERSION_CHECK
#if (STD_ON == BSWM_SD_ENABLED)
/* Check if current file and Sd header file are of the same Autosar version */
#if(\
		(BSWM_SD_AR_RELEASE_MAJOR_VERSION != SD_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_SD_AR_RELEASE_MINOR_VERSION != SD_AR_RELEASE_MINOR_VERSION) \
	)
/*#error "AutoSar Version Number of BswM_Sd.h and Sd.h are different "*/
#endif
#endif /* (STD_ON == BSWM_SD_ENABLED) */
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

#if (STD_ON == BSWM_SD_ENABLED)
FUNC(void, BSWM_CODE) BswM_Sd_ClientServiceCurrentState(
	VAR(uint16, AUTOMATIC) SdClientServiceHandleId,
	VAR(Sd_ClientServiceCurrentStateType, AUTOMATIC) CurrentClientState
);

FUNC(void, BSWM_CODE) BswM_Sd_ConsumedEventGroupCurrentState(
	VAR(uint16, AUTOMATIC) SdConsumedEventGroupHandleId,
	VAR(Sd_ConsumedEventGroupCurrentStateType, AUTOMATIC) ConsumedEventGroupState
);

FUNC(void, BSWM_CODE) BswM_Sd_EventHandlerCurrentState(
	VAR(uint16, AUTOMATIC) SdEventHandlerHandleId,
	VAR(Sd_EventHandlerCurrentStateType, AUTOMATIC) EventHandlerStatus
);
#endif /* (STD_ON == BSWM_SD_ENABLED) */

#define BSWM_STOP_SEC_CODE
#include "BswM_MemMap.h"

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */
/** @} */

#endif /* #ifndef BSWM_SD_H*/
