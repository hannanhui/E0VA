/* @file        ComM_EcuMBswM.h
 * @brief       AUTOSAR ComM - ComM driver header file.
 * @version     1.2.0
 * @addtogroup  ComM
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
#ifndef COMM_ECUMBSWM_H
#define COMM_ECUMBSWM_H

#ifdef __cplusplus
extern "C"{
#endif

/* PRQA S 0292, 0288, 1503, 1505, 0857, 0791, 0828, 0647 EOF #
*
* 1.0292 -- Violates MISRA 2004 Required Rule 3.1, Source file has comments containing one of the* characters '$', '@' or '`'.
*
* 2.0288 -- Violates MISRA 2004 Required Rule 3.1, Source file has comments containing characters* which are not members of the basic source character set.
*
* 3.1503 -- Violates MISRA 2004 Required Rule 14.1, The function is defined but is not used within* this project.
*
* 4.1505 -- Violates MISRA 2004 Required Rule 8.10, The function is only referenced in the translation* unit where it is defined.
*
* 5.0857 -- Violates MISRA 2004 Required Rule 1.1, Number of macro definitions exceeds 1024 - program* does not conform strictly to ISO:C90.
*
* 6.0791 -- Violates MISRA 2004 Required Rule 5.1, Macro identifier does not differ from other macro* identifier(s) within the specified number of significant characters.
*
* 7.0828 -- Violates MISRA 2004 Required Rule 1.1, More than 8 levels of nested conditional inclusion* - program does not conform strictly to ISO:C90.
*
* 8.0647 -- Violates MISRA 2004 Required Rule 1.1, Number of enumeration constants exceeds 127-program
* does not conform strictly to ISO:C90.
*
* @page misra_violations MISRA-C:2004 violations
*/
/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
#include "ComStack_Types.h"
#include "ComM_Cfg.h"

/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/
#define COMM_ECUMBSWM_VENDOR_ID                   0U
#define COMM_ECUMBSWM_AR_RELEASE_MAJOR_VERSION    4u
#define COMM_ECUMBSWM_AR_RELEASE_MINOR_VERSION    2u
#define COMM_ECUMBSWM_AR_RELEASE_REVISION_VERSION 2u
#define COMM_ECUMBSWM_SW_MAJOR_VERSION            1u
#define COMM_ECUMBSWM_SW_MINOR_VERSION            2u
#define COMM_ECUMBSWM_SW_PATCH_VERSION            0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and ComM_Cfg.h header file are of the same vendor  */
#if(COMM_ECUMBSWM_VENDOR_ID != COMM_CFG_VENDOR_ID )
#error "ComM_EcuMBswM.h and ComM_Cfg.h have different vendor id"
#endif

/* Check if current file and ComM_Cfg.h header file are of the same Autosar version  */
#if(\
      (COMM_ECUMBSWM_AR_RELEASE_MAJOR_VERSION != COMM_CFG_AR_RELEASE_MAJOR_VERSION) || \
      (COMM_ECUMBSWM_AR_RELEASE_MINOR_VERSION != COMM_CFG_AR_RELEASE_MINOR_VERSION) || \
      (COMM_ECUMBSWM_AR_RELEASE_REVISION_VERSION != COMM_CFG_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of ComM_EcuMBswM.h and ComM_Cfg.h are different "
#endif

/* Check if current file and ComM_Cfg.h header file are of the same software version  */
#if(\
      (COMM_ECUMBSWM_SW_MAJOR_VERSION != COMM_CFG_SW_MAJOR_VERSION) || \
      (COMM_ECUMBSWM_SW_MINOR_VERSION != COMM_CFG_SW_MINOR_VERSION) ||\
	  (COMM_ECUMBSWM_SW_PATCH_VERSION != COMM_CFG_SW_PATCH_VERSION)\
      )
#error "Software Version Number of ComM_EcuMBswM.h and ComM_Cfg.h are different "
#endif

#ifndef DISABLE_INTERMOD_VERSION_CHECK
/* Check if current file and ComStack_Types.h header file are of the same Autosar version  */
#if(\
      (COMM_ECUMBSWM_AR_RELEASE_MAJOR_VERSION != COMTYPE_AR_RELEASE_MAJOR_VERSION) || \
      (COMM_ECUMBSWM_AR_RELEASE_MINOR_VERSION != COMTYPE_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of ComM_EcuMBswM.h and ComStack_Types.h are different "
#endif
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
#define COMM_START_SEC_CODE
#include "ComM_MemMap.h"

#if (STD_ON == COMM_ECUM_USED)
FUNC(void, COMM_ECUM_CODE)
ComM_EcuM_WakeUpIndication(
    CONST(NetworkHandleType, CANTP_CONST) Channel
);
#endif /*#if (STD_ON == COMM_ECUM_USED)*/

#define COMM_STOP_SEC_CODE
#include "ComM_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif/* COMM_ECUMBSWM_H */
/** @} */
