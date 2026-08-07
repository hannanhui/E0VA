/**
 * @file        LinIf_Cbk.h
 * @brief       AUTOSAR LINIF - LinIf_Cbk driver header file.
 * @details     LinIf_Cbk header file, containing the Autosar API specification and
 *              other variables and functions that are exported by the LinIf driver.
 * @addtogroup  LINIF
 * @{
 */
/*=================================================================================================*
 * AngHui AUTOSAR BSW.
 *
 * Copyright(C) 2023 GuoKeAngHui Inc.
 *
 * All rights reserved.
 *
 * This file is part of AngHui AUTOSAR BSW, contains proprietary information.
 * Passing on and copying of this document, and communication of its contents
 * is not permitted without prior written authorization.
 *=================================================================================================*/

#ifndef LINIF_CBK_H
#define LINIF_CBK_H

#ifdef __cplusplus
extern "C"{
#endif

/*=================================================================================================*
 *                                           INCLUDE FILES
 *=================================================================================================*/

#include "ComStack_Types.h"
#include "Lin_GeneralTypes.h"
#include "LinIf_Cfg.h"
#include "EcuM.h"

/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/

#define LINIF_CBK_VENDOR_ID                       0U
#define LINIF_CBK_AR_RELEASE_MAJOR_VERSION        4U
#define LINIF_CBK_AR_RELEASE_MINOR_VERSION        2U
#define LINIF_CBK_AR_RELEASE_REVISION_VERSION     2U
#define LINIF_CBK_SW_MAJOR_VERSION                1U
#define LINIF_CBK_SW_MINOR_VERSION                0U
#define LINIF_CBK_SW_PATCH_VERSION                0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/

#ifndef  DISABLE_INTERMOD_VERSION_CHECK
/* Check if current file and ComStack_Types header file are of the same Autosar version */
#if(\
	(LINIF_CBK_AR_RELEASE_MAJOR_VERSION != COMTYPE_AR_RELEASE_MAJOR_VERSION) || \
	(LINIF_CBK_AR_RELEASE_MINOR_VERSION != COMTYPE_AR_RELEASE_MINOR_VERSION) \
	)
#error "AutoSar Version Number of LinIf_Cbk.h and ComStack_Types.h are different "
#endif

/* Check if current file and Lin_GeneralTypes header file are of the same Autosar version */
#if(\
	(LINIF_CBK_AR_RELEASE_MAJOR_VERSION != LIN_GENERALTYPES_AR_RELEASE_MAJOR_VERSION) || \
	(LINIF_CBK_AR_RELEASE_MINOR_VERSION != LIN_GENERALTYPES_AR_RELEASE_MINOR_VERSION) \
	)
#error "AutoSar Version Number of LinIf_Cbk.h and Lin_GeneralTypes.h are different "
#endif
#endif /* DISABLE_INTERMOD_VERSION_CHECK */

/*====================================================================================================*
 *                                             CONSTANTS
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                         DEFINES AND MACROS
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                               ENUMS
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES
 *====================================================================================================*/
FUNC(void,LINIF_CODE)LinIf_WakeupConfirmation
(
    VAR(EcuM_WakeupSourceType,AUTOMATIC) WakeupSource
);

#if (LINIF_USED_SLAVE_NODE == STD_ON)
FUNC(Std_ReturnType,LINIF_CODE)LinIf_HeaderIndication
(
    VAR(NetworkHandleType,AUTOMATIC) Channel,
	P2VAR(Lin_PduType, AUTOMATIC,LINIF_APPL_DATA) PduPtr
);

FUNC(void,LINIF_CODE)LinIf_RxIndication
(
    VAR(NetworkHandleType,AUTOMATIC) Channel,
	P2VAR(uint8, AUTOMATIC,LINIF_APPL_DATA) Lin_SduPtr
);

FUNC(void,LINIF_CODE)LinIf_TxConfirmation
(
    VAR(NetworkHandleType,AUTOMATIC) Channel
);

FUNC(void,LINIF_CODE)LinIf_LinErrorIndication
(
    VAR(NetworkHandleType,AUTOMATIC) Channel,
	VAR(Lin_SlaveErrorType,AUTOMATIC) ErrorStatus
);
#endif /* LINIF_USED_SLAVE_NODE == STD_ON */

#ifdef __cplusplus
}
#endif

#endif /* LINIF_CBK_H */
/** @} */
