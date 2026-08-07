/* @file        ComM_Internal.h
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

#ifndef COMM_INTERNAL_H
#define COMM_INTERNAL_H

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

#include "ComM_Cfg.h"
#include "ComM_Types.h"

#if (STD_ON == COMM_BSWM_USED)
#include "BswM_ComM.h"
#endif
/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/

#define COMM_INTERNAL_VENDOR_ID                   0U
#define COMM_INTERNAL_AR_RELEASE_MAJOR_VERSION    4u
#define COMM_INTERNAL_AR_RELEASE_MINOR_VERSION    2u
#define COMM_INTERNAL_AR_RELEASE_REVISION_VERSION 2u
#define COMM_INTERNAL_SW_MAJOR_VERSION            1u
#define COMM_INTERNAL_SW_MINOR_VERSION            2u
#define COMM_INTERNAL_SW_PATCH_VERSION            0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and ComM_Cfg.h header file are of the same vendor  */
#if(COMM_INTERNAL_VENDOR_ID != COMM_CFG_VENDOR_ID )
#error "ComM_Internal.c and ComM_Cfg.h have different vendor id"
#endif

/* Check if current file and ComM_Cfg.h header file are of the same Autosar version  */
#if(\
      (COMM_INTERNAL_AR_RELEASE_MAJOR_VERSION != COMM_CFG_AR_RELEASE_MAJOR_VERSION) || \
      (COMM_INTERNAL_AR_RELEASE_MINOR_VERSION != COMM_CFG_AR_RELEASE_MINOR_VERSION) || \
      (COMM_INTERNAL_AR_RELEASE_REVISION_VERSION != COMM_CFG_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of ComM_Internal.c and ComM_Cfg.h are different "
#endif

/* Check if current file and ComM_Cfg.h header file are of the same software version  */
#if(\
      (COMM_INTERNAL_SW_MAJOR_VERSION != COMM_CFG_SW_MAJOR_VERSION) || \
      (COMM_INTERNAL_SW_MINOR_VERSION != COMM_CFG_SW_MINOR_VERSION) ||\
	  (COMM_INTERNAL_SW_PATCH_VERSION != COMM_CFG_SW_PATCH_VERSION)\
      )
#error "Software Version Number of ComM_Internal.c and ComM_Cfg.h are different "
#endif

/* Check if current file and ComM_Types.h header file are of the same vendor  */
#if(COMM_INTERNAL_VENDOR_ID != COMM_TYPES_VENDOR_ID )
#error "ComM_Internal.c and ComM_Types.h have different vendor id"
#endif

/* Check if current file and ComM_Types.h header file are of the same Autosar version  */
#if(\
      (COMM_INTERNAL_AR_RELEASE_MAJOR_VERSION != COMM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
      (COMM_INTERNAL_AR_RELEASE_MINOR_VERSION != COMM_TYPES_AR_RELEASE_MINOR_VERSION) || \
      (COMM_INTERNAL_AR_RELEASE_REVISION_VERSION != COMM_TYPES_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of ComM_Internal.c and ComM_Types.h are different "
#endif

/* Check if current file and ComM_Types.h header file are of the same software version  */
#if(\
      (COMM_INTERNAL_SW_MAJOR_VERSION != COMM_TYPES_SW_MAJOR_VERSION) || \
      (COMM_INTERNAL_SW_MINOR_VERSION != COMM_TYPES_SW_MINOR_VERSION) ||\
	  (COMM_INTERNAL_SW_PATCH_VERSION != COMM_TYPES_SW_PATCH_VERSION)\
      )
#error "Software Version Number of ComM_Internal.c and ComM_Types.h are different "
#endif

#if (STD_ON == COMM_BSWM_USED)
/* Check if current file and BswM.h header file are of the same Autosar version  */
#if(\
      (COMM_INTERNAL_AR_RELEASE_MAJOR_VERSION != BSWM_COMM_AR_RELEASE_MAJOR_VERSION) || \
      (COMM_INTERNAL_AR_RELEASE_MINOR_VERSION != BSWM_COMM_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of ComM_Internal.c and BswM_ComM.h are different "
#endif
#endif/*(STD_ON == COMM_BSWM_USED)*/
/*====================================================================================================*
 *                                             CONSTANTS
 *====================================================================================================*/


/*====================================================================================================*
 *                                         DEFINES AND MACROS
 *====================================================================================================*/
#if defined(AH_UNITTEST_ENABLED)
#define STATIC
#else
#define STATIC static
#endif /* #if defined(AH_UNITTEST_ENABLED)  */

/*====================================================================================================*
 *                                               ENUMS
 *====================================================================================================*/

/**
* @brief 	Defines the functionality of the networkmanagement.Shall be harmonized with NM configuration.
* @details
*/
typedef enum
{
	COMM_ALLOWED_TO_NOCOM = (uint8)0u,  	       /**< @brief The current conditions allow the state change to NoComPending.*/
	COMM_ALLOWED_TO_FULLCOM = (uint8)1u,           /**< @brief The current conditions allow the state change to NoCom.*/
	COMM_KEEP_CURSTATE = (uint8)2u                /**< @brief The current conditions allow the state change to NetworkRequested.*/
} ComM_ConditionType;


/**
* @brief 	Defines the functionality of the networkmanagement.Shall be harmonized with NM configuration.
* @details
*/
typedef enum
{
	COMM_NM_LIGHT_TIMER ,  				/**< @brief Timer for.*/
	COMM_MIN_FULL_COM_MODE_DURATION_TIMER ,  	/**< @brief Timer for ComMTMinFullComModeDuration.*/
	COMM_NO_TIMER                       /**< @brief Timer for.*/
} ComM_TimerType;


/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS
 *====================================================================================================*/

/**
* @brief  running Mode timer for Channel .
*/
typedef struct ComM_ModeTimer
{
	/**< @brief Is the Timer start or not*/
	boolean IsStarted;
    /**< @brief RemineTime for Timer*/
    uint32 Timer;
    /**< @brief ABCTimerType for Timer*/
    ComM_TimerType TimerType;

} ComM_ModeTimerType;

/**
* @brief  running Mode timer for Channel .
*/
typedef struct ComM_EventFlags
{
	/**< @brief Is the DCMActive event happen or not*/
	boolean DcmActive;
    /**< @brief Is the EcuMWakeup event happen or not*/
	boolean EcuMWakeupInd;
    /**< @brief Is the NmStart event happen or not*/
	boolean NmStart;
	/**< @brief Is the NmReStart event happen or not*/
	boolean NmReStart;
    /**< @brief Is the NmNetworkMode event happen or not*/
	boolean NmNetworkMode;
    /**< @brief Is the NmPreSleep event happen or not*/
	boolean NmPreSleep;
	/**< @brief Is the NmBusSleep event happen or not*/
	boolean NmBusSleep;
} ComM_EventFlagsType;


/**
* @brief  running Mode timer for Channel .
*/
typedef struct ComM_BusSetRecord
{
	/**< @brief Is there a bus setting request*/
	boolean Requested;
	/**< @brief Is the bus Mode set error and need to reset*/
	boolean RetrySet;
	/**< @brief the bus which has been successfully set*/
	ComM_ModeType BusNMModeIndication;
} ComM_BusSetRecordType;


/**
* @brief 	Define a function pointer type that is used to point to state processing functions.
*/
typedef P2FUNC(void, COMM_APPL_CODE, ComM_StateHandler)
(NetworkHandleType Channel);

/**
* @brief 	Define a function pointer type that is used to point to the functions on change transmission
* 		    and reception capability  By corresponding Bus State Manager module .
*/
typedef P2FUNC(Std_ReturnType, COMM_APPL_CODE, ComM_SMReqComMode)
(NetworkHandleType Channel, ComM_ModeType ComMode);

/**
* @brief 	Define a function pointer type that is used to point to state ModeIndication functions.
*/
typedef P2FUNC(void, COMM_APPL_CODE, ComM_ModeIndication)
(NetworkHandleType Channel);

/**
* @brief 	Define a function pointer type that is used to point to a get bus mode function .
*/
typedef P2FUNC(Std_ReturnType, COMM_APPL_CODE, ComM_SMGetComMode)
(NetworkHandleType Channel, P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_DATA) ComModePtr);


/**
 * @brief 	Defines run-time structure of a user.
 */
typedef struct
{
    /* User request mode currently */
    ComM_ModeType RequestMode;

} ComM_UserRunTimeInfoType;

/**
* @brief 	Defines run-time structure of a channel.
*/
typedef struct
{
    /**< @brief Current mode of a channel */
    ComM_ModeType ComMMode;

    /**< @brief Status of a channel */
    ComM_StateType ComMState;

    /**< @brief Remain times of a channel in the current mode */
    ComM_ModeTimerType  ModeTimer;

    /**< @brief Other module flag events */
    ComM_EventFlagsType EventFlags;

    /**< @brief  bus set record */
    ComM_BusSetRecordType BusSetRecord;

    /**< @brief User counter of requests "full-communication" */
    uint8 UserReqFullNum;

    /**< @brief User counter of requests "full-communication" */
    boolean CommunicationAllowed;

    /**< @brief Conditions of the current channel satisfaction */
    ComM_ConditionType AllowedConditionType;

#if ((STD_ON == COMM_WAKEUP_INHIBITION_ENABLED) || (STD_ON == COMM_MODE_LIMITATION_ENABLED))
    boolean ComMNoWakeup;
    ComM_InhibitionStatusType InhibitionStatu;
#endif/*#if ((STD_ON == COMM_WAKEUP_INHIBITION_ENABLED) || (STD_ON == COMM_MODE_LIMITATION_ENABLED))*/

} ComM_ChannelInfoType;

/**
* @brief 	Defines run-time structure of a user.
* @details
*/
typedef struct
{
    /* User request mode currently */
    ComM_ModeType RequestMode;

#if (STD_ON == COMM_RTE_NOTIFY_USED)
    /* Old mode */
    ComM_ModeType OldMode;

    /* Channel counter of the mode(eg. full-com, silent-com, no-com). */
    uint8 ChCounter[3u];
#endif /*#if (STD_ON == COMM_RTE_NOTIFY_USED)*/

} ComM_UserInfoType;

/**
 * @brief 	Defines global run-time structure.
 */
#if ((STD_ON == COMM_WAKEUP_INHIBITION_ENABLED) || (STD_ON == COMM_MODE_LIMITATION_ENABLED))
typedef struct
{
	/**< record Limit ECU to COMM_NO_COMMUNICATION is disabled or not */
	VAR(boolean, COMM_VAR) ComM_EcuToNoCom;

	/**< record Limit channel to COMM_NO_COMMUNICATION disabled or not */
	VAR(boolean, COMM_VAR) ComMNoWakeup[COMM_NUMBER_OF_CHANNELS];

	/**< record Inhibit status Types for each channel */
	VAR(ComM_InhibitionStatusType, COMM_VAR) inhibitStatu[COMM_NUMBER_OF_CHANNELS];

	/*@req [SWS_ComM_00141]*/
	/**< Inhibit counter of requests "full-communication" */
	VAR(uint16, COMM_VAR) InhibitCounter;

	/**< Whether enable "wakeup-inhibition" and "communicate-limitiation" or not */
	VAR(ComM_InhibitionStatusType, COMM_VAR) EcuGroupClassification;

} ComM_GlobalInfoType;
#endif /*#if (COMM_WAKEUP_INHIBITION_ENABLED || COMM_MODE_LIMITATION_ENABLED)*/

/*====================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS
 *====================================================================================================*/
extern ComM_SMGetComMode ComM_SMGetComModeTable[COMM_BUS_TYPE_COUT];

extern VAR(ComM_ChannelInfoType, COMM_VAR) ComM_ChannelInfo[COMM_NUMBER_OF_CHANNELS];

extern P2CONST(ComM_ConfigType, AUTOMATIC, COMM_CONST) ComM_ConfigPtr;

extern VAR(ComM_UserInfoType, COMM_VAR) ComM_UserInfo[COMM_NUMBER_OF_USERS];

#if ((STD_ON == COMM_WAKEUP_INHIBITION_ENABLED) || (STD_ON == COMM_MODE_LIMITATION_ENABLED))
extern VAR(ComM_GlobalInfoType, COMM_VAR) ComM_GlobalInfo;
#endif /* (STD_ON == COMM_WAKEUP_INHIBITION_ENABLED) || (STD_ON == COMM_MODE_LIMITATION_ENABLED)*/

/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES
 *====================================================================================================*/
#define COMM_START_SEC_CODE
#include "ComM_MemMap.h"

FUNC(void, COMM_CODE)ComM_NoComCheck(
	CONST(NetworkHandleType, CANTP_CONST) Channel
);

FUNC(void, COMM_CODE)ComM_NoComPendingCheck(
	CONST(NetworkHandleType, CANTP_CONST) Channel
);

FUNC(void, COMM_CODE)ComM_NetworkRequestCheck(
	CONST(NetworkHandleType, CANTP_CONST) Channel
);

FUNC(void, COMM_CODE)ComM_ReadySleepCheck(
	CONST(NetworkHandleType, CANTP_CONST) Channel
);

FUNC(void, COMM_CODE)ComM_SlientCheck(
	CONST(NetworkHandleType, CANTP_CONST) Channel
);

FUNC(void, COMM_CODE)ComM_ConditionCheck(
	CONST(NetworkHandleType, CANTP_CONST) Channel
);

FUNC(void, COMM_CODE) ComM_EnterReadySleepHandler(
	CONST(NetworkHandleType, CANTP_CONST) Channel
);

FUNC(void, COMM_CODE) ComM_EnterNoComHandler(
	CONST(NetworkHandleType, CANTP_CONST) Channel
);

FUNC(void, COMM_CODE) ComM_EnterNoComPendingHandler(
	CONST(NetworkHandleType, CANTP_CONST) Channel
);

FUNC(void, COMM_CODE) ComM_EnterNetworkRequestedHandler(
	CONST(NetworkHandleType, CANTP_CONST) Channel
);

FUNC(void, COMM_CODE) ComM_EnterSilentComHandler(
	CONST(NetworkHandleType, CANTP_CONST) Channel
);

FUNC(void, COMM_CODE) ComM_ModeHandle(
    CONST(NetworkHandleType, CANTP_CONST) Channel
);

FUNC(void, COMM_CODE) ComM_TimeHandle
(
    CONST(NetworkHandleType, CANTP_CONST) Channel
);

FUNC(void, COMM_CODE) ComM_EventHandle(
    CONST(NetworkHandleType, CANTP_CONST) Channel
);

FUNC(Std_ReturnType, COMM_CODE) ComM_IntGetCurrentComMode(
    CONST(NetworkHandleType, CANTP_CONST) Channel,
    P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_DATA) ComModePtr
);

FUNC(Std_ReturnType, COMM_CODE) ComM_InterRequestComMode(
    CONST(NetworkHandleType, CANTP_CONST) Channel,
	CONST(ComM_ModeType, CANTP_CONST) ComMode
);

#define COMM_STOP_SEC_CODE
#include "ComM_MemMap.h"


#ifdef __cplusplus
}
#endif

#endif/* COMM_INTERNAL_H */
/** @} */
