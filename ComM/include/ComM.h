/**
 * @file        ComM.h
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

#ifndef COMM_H
#define COMM_H

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

#include "ComM_BusSM.h"
#include "ComM_Cfg.h"
#include "ComM_Types.h"

#include "ComM_EcuMBswM.h"

#if (STD_ON == COMM_COM_USED)
#include "Com.h"
#endif

#if (STD_ON == COMM_ECUM_USED)
#include "EcuM.h"
#endif

#if (STD_ON == COMM_DCM_USED)
#include "ComM_Dcm.h"
#include "Dcm_Cbk.h"
#endif /*#if (STD_ON == COMM_DCM_USED)*/

#if (STD_ON == COMM_COM_USED)
#include "ComM_Com.h"
#endif

#if (STD_ON == COMM_NM_USED)
#include "ComM_Nm.h"
#include "Nm.h"
#endif /*#if (STD_ON == COMM_NM_USED)*/

/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/

#define COMM_VENDOR_ID                    0U
#define COMM_MODULE_ID                    12U
#define COMM_AR_RELEASE_MAJOR_VERSION     4U
#define COMM_AR_RELEASE_MINOR_VERSION     2U
#define COMM_AR_RELEASE_REVISION_VERSION  2U
#define COMM_SW_MAJOR_VERSION             1U
#define COMM_SW_MINOR_VERSION             2U
#define COMM_SW_PATCH_VERSION             0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and ComM_Cfg.h header file are of the same vendor  */
#if(COMM_VENDOR_ID != COMM_CFG_VENDOR_ID )
#error "ComM.h and ComM_Cfg.h have different vendor id"
#endif

/* Check if current file and ComM.h header file are of the same Autosar version  */
#if(\
      (COMM_AR_RELEASE_MAJOR_VERSION != COMM_CFG_AR_RELEASE_MAJOR_VERSION) || \
      (COMM_AR_RELEASE_MINOR_VERSION != COMM_CFG_AR_RELEASE_MINOR_VERSION) || \
      (COMM_AR_RELEASE_REVISION_VERSION != COMM_CFG_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of ComM.h and ComM_Cfg.h are different "
#endif

/* Check if current file and ComM.h header file are of the same software version  */
#if(\
      (COMM_SW_MAJOR_VERSION != COMM_CFG_SW_MAJOR_VERSION) || \
      (COMM_SW_MINOR_VERSION != COMM_CFG_SW_MINOR_VERSION) ||\
	  (COMM_SW_PATCH_VERSION != COMM_CFG_SW_PATCH_VERSION)\
      )
#error "Software Version Number of ComM.h and ComM_Cfg.h are different "
#endif

/* Check if current file and ComM_Types.h header file are of the same vendor  */
#if(COMM_VENDOR_ID != COMM_TYPES_VENDOR_ID )
#error "ComM.h and ComM_Types.h have different vendor id"
#endif

/* Check if current file and ComM_Types.h header file are of the same Autosar version  */
#if(\
      (COMM_AR_RELEASE_MAJOR_VERSION != COMM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
      (COMM_AR_RELEASE_MINOR_VERSION != COMM_TYPES_AR_RELEASE_MINOR_VERSION) || \
      (COMM_AR_RELEASE_REVISION_VERSION != COMM_TYPES_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of ComM.h and ComM_Types.h are different "
#endif

/* Check if current file and ComM_Types.h header file are of the same software version  */
#if(\
      (COMM_SW_MAJOR_VERSION != COMM_TYPES_SW_MAJOR_VERSION) || \
      (COMM_SW_MINOR_VERSION != COMM_TYPES_SW_MINOR_VERSION) ||\
	  (COMM_SW_PATCH_VERSION != COMM_TYPES_SW_PATCH_VERSION)\
      )
#error "Software Version Number of ComM.h and ComM_Types.h are different "
#endif


/* Check if current file and ComM_BusSM.h header file are of the same vendor  */
#if(COMM_VENDOR_ID != COMM_BUSSM_VENDOR_ID )
#error "ComM.h and ComM_BusSM.h have different vendor id"
#endif

/* Check if current file and ComM_BusSM.h header file are of the same Autosar version  */
#if(\
      (COMM_AR_RELEASE_MAJOR_VERSION != COMM_BUSSM_AR_RELEASE_MAJOR_VERSION) || \
      (COMM_AR_RELEASE_MINOR_VERSION != COMM_BUSSM_AR_RELEASE_MINOR_VERSION) || \
      (COMM_AR_RELEASE_REVISION_VERSION != COMM_BUSSM_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of ComM.h and ComM_BusSM.h are different "
#endif

/* Check if current file and ComM_BusSM.h header file are of the same software version  */
#if(\
      (COMM_SW_MAJOR_VERSION != COMM_BUSSM_SW_MAJOR_VERSION) || \
      (COMM_SW_MINOR_VERSION != COMM_BUSSM_SW_MINOR_VERSION) ||\
	  (COMM_SW_PATCH_VERSION != COMM_BUSSM_SW_PATCH_VERSION)\
      )
#error "Software Version Number of ComM.h and ComM_BusSM.h are different "
#endif


#if (STD_ON == COMM_ECUM_USED)
/* Check if current file and ComM_EcuMBswM.h header file are of the same vendor  */
#if(COMM_VENDOR_ID != COMM_ECUMBSWM_VENDOR_ID )
#error "ComM.c and ComM_EcuMBswM.h have different vendor id"
#endif
/* Check if current file and ComM_EcuMBswM.h header file are of the same Autosar version  */
#if(\
      (COMM_AR_RELEASE_MAJOR_VERSION != COMM_ECUMBSWM_AR_RELEASE_MAJOR_VERSION) || \
      (COMM_AR_RELEASE_MINOR_VERSION != COMM_ECUMBSWM_AR_RELEASE_MINOR_VERSION) || \
      (COMM_AR_RELEASE_REVISION_VERSION != COMM_ECUMBSWM_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of ComM.h and ComM_EcuMBswM.h are different "
#endif

/* Check if current file and ComM_EcuMBswM.h header file are of the same software version  */
#if(\
      (COMM_SW_MAJOR_VERSION != COMM_ECUMBSWM_SW_MAJOR_VERSION) || \
      (COMM_SW_MINOR_VERSION != COMM_ECUMBSWM_SW_MINOR_VERSION) ||\
	  (COMM_SW_PATCH_VERSION != COMM_ECUMBSWM_SW_PATCH_VERSION)\
      )
#error "Software Version Number of ComM.h and ComM_EcuMBswM.h are different "
#endif
#endif/*(STD_ON == COMM_ECUM_USED)*/


#if (STD_ON == COMM_DCM_USED)
/* Check if current file and ComM_Dcm.h header file are of the same vendor  */
#if(COMM_VENDOR_ID != COMM_DCM_VENDOR_ID )
#error "ComM.h and ComM_Dcm.h have different vendor id"
#endif
/* Check if current file and ComM_Dcm.h header file are of the same Autosar version  */
#if(\
      (COMM_AR_RELEASE_MAJOR_VERSION != COMM_DCM_AR_RELEASE_MAJOR_VERSION) || \
      (COMM_AR_RELEASE_MINOR_VERSION != COMM_DCM_AR_RELEASE_MINOR_VERSION) || \
      (COMM_AR_RELEASE_REVISION_VERSION != COMM_DCM_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of ComM.h and ComM_Dcm.h are different "
#endif

/* Check if current file and ComM_Dcm.h header file are of the same software version  */
#if(\
      (COMM_SW_MAJOR_VERSION != COMM_DCM_SW_MAJOR_VERSION) || \
      (COMM_SW_MINOR_VERSION != COMM_DCM_SW_MINOR_VERSION) ||\
	  (COMM_SW_PATCH_VERSION != COMM_DCM_SW_PATCH_VERSION)\
      )
#error "Software Version Number of ComM.h and ComM_Dcm.h are different "
#endif
#endif

#if (STD_ON == COMM_COM_USED)
/* Check if current file and ComM_Com.h header file are of the same vendor  */
#if(COMM_VENDOR_ID != COMM_COM_VENDOR_ID )
#error "ComM.h and ComM_Com.h have different vendor id"
#endif

/* Check if current file and ComM_Com.h header file are of the same Autosar version  */
#if(\
      (COMM_AR_RELEASE_MAJOR_VERSION != COMM_COM_AR_RELEASE_MAJOR_VERSION) || \
      (COMM_AR_RELEASE_MINOR_VERSION != COMM_COM_AR_RELEASE_MINOR_VERSION) || \
      (COMM_AR_RELEASE_REVISION_VERSION != COMM_COM_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of ComM.h and ComM_Com.h are different "
#endif

/* Check if current file and ComM_Com.h header file are of the same software version  */
#if(\
      (COMM_SW_MAJOR_VERSION != COMM_COM_SW_MAJOR_VERSION) || \
      (COMM_SW_MINOR_VERSION != COMM_COM_SW_MINOR_VERSION) ||\
	  (COMM_SW_PATCH_VERSION != COMM_COM_SW_PATCH_VERSION)\
      )
#error "Software Version Number of ComM.h and ComM_Com.h are different "
#endif
#endif/*(STD_ON == COMM_COM_USED)*/


#if (STD_ON == COMM_NM_USED)
/* Check if current file and ComM_Nm.h header file are of the same vendor  */
#if(COMM_VENDOR_ID != COMM_NM_VENDOR_ID )
#error "ComM.h and ComM_Nm.h have different vendor id"
#endif
/* Check if current file and ComM_Nm.h header file are of the same Autosar version  */
#if(\
      (COMM_AR_RELEASE_MAJOR_VERSION != COMM_NM_AR_RELEASE_MAJOR_VERSION) || \
      (COMM_AR_RELEASE_MINOR_VERSION != COMM_NM_AR_RELEASE_MINOR_VERSION) || \
      (COMM_AR_RELEASE_REVISION_VERSION != COMM_NM_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of ComM.h and ComM_Nm.h are different "
#endif

/* Check if current file and ComM_Nm.h header file are of the same software version  */
#if(\
      (COMM_SW_MAJOR_VERSION != COMM_NM_SW_MAJOR_VERSION) || \
      (COMM_SW_MINOR_VERSION != COMM_NM_SW_MINOR_VERSION) ||\
	  (COMM_SW_PATCH_VERSION != COMM_NM_SW_PATCH_VERSION)\
      )
#error "Software Version Number of ComM.h and ComM_Nm.h are different "
#endif
#endif

#ifndef DISABLE_INTERMOD_VERSION_CHECK

#if (STD_ON == COMM_NM_USED)
/* Check if current file and Nm.h header file are of the same Autosar version  */
#if(\
      (COMM_AR_RELEASE_MAJOR_VERSION != NM_AR_RELEASE_MAJOR_VERSION) || \
      (COMM_AR_RELEASE_MINOR_VERSION != NM_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of ComM.h and Nm.h are different "
#endif
#endif

#if (STD_ON == COMM_COM_USED)
/* Check if current file and Com.h header file are of the same Autosar version  */
#if(\
      (COMM_AR_RELEASE_MAJOR_VERSION != COM_AR_RELEASE_MAJOR_VERSION) || \
      (COMM_AR_RELEASE_MINOR_VERSION != COM_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of ComM.h and Com.h are different "
#endif
#endif

#if (STD_ON == COMM_ECUM_USED)
/* Check if current file and EcuM.h header file are of the same Autosar version  */
#if(\
      (COMM_AR_RELEASE_MAJOR_VERSION != ECUM_AR_RELEASE_MAJOR_VERSION) || \
      (COMM_AR_RELEASE_MINOR_VERSION != ECUM_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of ComM.h and EcuM.h are different "
#endif
#endif/*#if (STD_ON == COMM_ECUM_USED)*/

/* Check if current file and ComStack_Types.h header file are of the same Autosar version  */
#if(\
      (COMM_AR_RELEASE_MAJOR_VERSION != COMTYPE_AR_RELEASE_MAJOR_VERSION) || \
      (COMM_AR_RELEASE_MINOR_VERSION != COMTYPE_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of ComM.h and ComStack_Types.h are different "
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
COMM_CONF_PB

/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES
 *====================================================================================================*/
#define COMM_START_SEC_CODE
#include "ComM_MemMap.h"

FUNC(void, COMM_CODE)
ComM_Init(
	P2CONST(ComM_ConfigType, AUTOMATIC, COMM_APPL_DATA) ConfigPtr
);

FUNC(void, COMM_CODE)
ComM_DeInit(
	void
);

FUNC(void, COMM_CODE)
ComM_GetVersionInfo(
    P2VAR(Std_VersionInfoType, AUTOMATIC, COMM_APPL_DATA) Versioninfo
);

FUNC(Std_ReturnType, COMM_CODE)
ComM_GetStatus(
    P2VAR(ComM_InitStatusType, AUTOMATIC, COMM_APPL_DATA) Status
);

FUNC(Std_ReturnType, COMM_CODE)
ComM_GetState(
    CONST(NetworkHandleType, CANTP_CONST) Channel,
    P2VAR(ComM_StateType, AUTOMATIC, COMM_APPL_DATA) State
);

FUNC(Std_ReturnType, COMM_CODE)
ComM_GetInhibitionStatus(
	CONST(NetworkHandleType, CANTP_CONST) Channel,
    P2VAR(ComM_InhibitionStatusType, AUTOMATIC, COMM_APPL_DATA) Status
);

FUNC(Std_ReturnType, COMM_CODE)
ComM_RequestComMode(
    CONST(ComM_UserHandleType, CANTP_CONST) User,
	CONST(ComM_ModeType, CANTP_CONST) ComMode
);

FUNC(void, COMM_CODE)
ComM_MainFunction(
	CONST(NetworkHandleType, CANTP_CONST) Channel
);

#if (STD_ON == COMM_PNC_SUPPORT)
FUNC(void, COMM_COM_CODE)
ComM_COMCbk(
    uint16 signalId
);
#endif/*#if (STD_ON == COMM_PNC_SUPPORT)*/

#if ((STD_ON == COMM_WAKEUP_INHIBITION_ENABLED) || (STD_ON == COMM_MODE_LIMITATION_ENABLED))
FUNC(Std_ReturnType, COMM_CODE)
ComM_SetECUGroupClassification(
	CONST(ComM_InhibitionStatusType, CANTP_CONST) Status
);
#endif /*#if ((STD_ON==COMM_WAKEUP_INHIBITION_ENABLED) || (STD_ON==COMM_MODE_LIMITATION_ENABLED)) */

#if (STD_ON == COMM_WAKEUP_INHIBITION_ENABLED)
FUNC(Std_ReturnType, COMM_CODE)
ComM_PreventWakeUp(
    CONST(NetworkHandleType, CANTP_CONST) Channel,
	CONST(boolean, CANTP_CONST) Status
);
#endif /*#if (STD_ON == COMM_WAKEUP_INHIBITION_ENABLED)*/

#if ((STD_ON == COMM_RESET_AFTER_FORCING_NO_COMM) && (STD_ON == COMM_MODE_LIMITATION_ENABLED))
FUNC(Std_ReturnType, COMM_CODE)
ComM_LimitChannelToNoComMode(
    CONST(NetworkHandleType, CANTP_CONST) Channel,
	CONST(boolean, CANTP_CONST) Status
);

FUNC(Std_ReturnType, COMM_CODE)
ComM_LimitECUToNoComMode(
	CONST(boolean, CANTP_CONST) Status
);
#endif /* ((STD_ON==COMM_RESET_AFTER_FORCING_NO_COMM) && (STD_ON==COMM_MODE_LIMITATION_ENABLED))*/

#if (STD_ON == COMM_MODE_LIMITATION_ENABLED)
#if defined (COMM_GLOBAL_NVM_BLOCK_DESCRIPTOR)
FUNC(Std_ReturnType, COMM_CODE)
ComM_ReadInhibitCounter(
    P2VAR(uint16, AUTOMATIC, COMM_APPL_DATA) CounterValue
);

FUNC(Std_ReturnType, COMM_CODE)
ComM_ResetInhibitCounter(
    void
);
#endif /*#if defined (COMM_GLOBAL_NVM_BLOCK_DESCRIPTOR)*/
#endif /*#if (STD_ON == COMM_MODE_LIMITATION_ENABLED)*/

FUNC(Std_ReturnType, COMM_CODE)
ComM_GetCurrentComMode(
    CONST(ComM_UserHandleType, CANTP_CONST) User,
    P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_DATA) ComMode
);

FUNC(void, COMM_ECUMBSWM_CODE)
ComM_CommunicationAllowed(
    CONST(NetworkHandleType, CANTP_CONST) Channel,
	CONST(boolean, CANTP_CONST) Allowed
);

FUNC(Std_ReturnType, COMM_CODE)
ComM_GetMaxComMode(
    CONST(ComM_UserHandleType, CANTP_CONST) User,
    P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_DATA) ComMode
);

FUNC(Std_ReturnType, COMM_CODE)
ComM_GetRequestedComMode(
	CONST(ComM_UserHandleType, CANTP_CONST) User,
    P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_DATA) ComMode
);

#define COMM_STOP_SEC_CODE
#include "ComM_MemMap.h"
#ifdef __cplusplus
}
#endif

#endif/* COMM_H */
/** @} */
