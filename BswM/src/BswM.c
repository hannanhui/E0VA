/**
 * @file        BswM.c
 * @brief       AUTOSAR BSWM  - BswM driver source file.
 * @details     BswM driver source file, containing the C implementation of Autosar API specification
 *              and other variables and functions that are exported by the BswM driver.
 * @version     1.2.0
 *
 * @addtogroup  BSWM
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

#if defined(__cplusplus)
extern "C" 
{
#endif /* defined(__cplusplus) */

/* PRQA S 0292, 0288, 1503, 1505, 0857, 0791, 0828, 0647 EOF #
 *
 * 1.0292 -- Violates MISRA 2004 Required Rule 3.1, Source file has comments containing one of the
 * characters '$', '@' or '`'.
 *
 * 2.0288 -- Violates MISRA 2004 Required Rule 3.1, Source file has comments containing characters
 * which are not members of the basic source character set.
 *
 * 3.1503 -- Violates MISRA 2004 Required Rule 14.1, The function is defined but is not used within
 * this project.
 *
 * 4.1505 -- Violates MISRA 2004 Required Rule 8.10, The function is only referenced in the translation
 * unit where it is defined.
 *
 * 5.0857 -- Violates MISRA 2004 Required Rule 1.1, Number of macro definitions exceeds 1024 - program
 * does not conform strictly to ISO:C90.
 *
 * 6.0791 -- Violates MISRA 2004 Required Rule 5.1, Macro identifier does not differ from other macro
 * identifier(s) within the specified number of significant characters.
 *
 * 7.0828 -- Violates MISRA 2004 Required Rule 1.1, More than 8 levels of nested conditional inclusion
 * - program does not conform strictly to ISO:C90.
 *
 * 8.0647 -- Violates MISRA 2004 Required Rule 1.1, Number of enumeration constants exceeds 127 -
 * program does not conform strictly to ISO:C90.
 *
 * @page misra_violations MISRA-C:2004 violations
 */

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
#include "BswM.h"
#include "BswM_Modules.h"
#include "SchM_BswM.h"
/*#include "Rte_BswM.h"*/
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
#include "Det.h"
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */

#ifdef AH_TEST_BSWM
#include "TestCode.h"
#endif
/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION
 *====================================================================================================*/

#define BSWM_VENDOR_ID_C                    0U
#define BSWM_AR_RELEASE_MAJOR_VERSION_C     4U
#define BSWM_AR_RELEASE_MINOR_VERSION_C     2U
#define BSWM_AR_RELEASE_REVISION_VERSION_C  2U
#define BSWM_SW_MAJOR_VERSION_C             1U
#define BSWM_SW_MINOR_VERSION_C             2U
#define BSWM_SW_PATCH_VERSION_C             0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/

/* Check if current file and BswM header file are of the same vendor */
#if(BSWM_VENDOR_ID_C != BSWM_VENDOR_ID )
#error "BswM.c and BswM.h have different vendor id"
#endif
/* Check if current file and BswM header file are of the same Autosar version */
#if(\
		(BSWM_AR_RELEASE_MAJOR_VERSION_C != BSWM_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_AR_RELEASE_MINOR_VERSION_C != BSWM_AR_RELEASE_MINOR_VERSION) || \
		(BSWM_AR_RELEASE_REVISION_VERSION_C != BSWM_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of BswM.c and BswM.h are different "
#endif
/* Check if current file and BswM header file are of the same software version */
#if(\
		(BSWM_SW_MAJOR_VERSION_C != BSWM_SW_MAJOR_VERSION) || \
		(BSWM_SW_MINOR_VERSION_C != BSWM_SW_MINOR_VERSION) || \
		(BSWM_SW_PATCH_VERSION_C != BSWM_SW_PATCH_VERSION) \
	)
#error "Software Version Number of BswM.c and BswM.h are different "
#endif

/* Check if current file and BswM_Modules header file are of the same vendor */
#if(BSWM_VENDOR_ID_C != BSWM_MODULES_VENDOR_ID )
#error "BswM.c and BswM_Modules.h have different vendor id"
#endif
/* Check if current file and BswM_Modules header file are of the same Autosar version */
#if(\
		(BSWM_AR_RELEASE_MAJOR_VERSION_C != BSWM_MODULES_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_AR_RELEASE_MINOR_VERSION_C != BSWM_MODULES_AR_RELEASE_MINOR_VERSION) || \
		(BSWM_AR_RELEASE_REVISION_VERSION_C != BSWM_MODULES_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of BswM.c and BswM_Modules.h are different "
#endif
/* Check if current file and BswM_Modules header file are of the same software version */
#if(\
		(BSWM_SW_MAJOR_VERSION_C != BSWM_MODULES_SW_MAJOR_VERSION) || \
		(BSWM_SW_MINOR_VERSION_C != BSWM_MODULES_SW_MINOR_VERSION) || \
		(BSWM_SW_PATCH_VERSION_C != BSWM_MODULES_SW_PATCH_VERSION) \
	)
#error "Software Version Number of BswM.c and BswM_Modules.h are different "
#endif

#ifndef DISABLE_INTERMOD_VERSION_CHECK
/* Check if current file and SchM_BswM header file are of the same Autosar version */
/* PRQA S 3332 EOF # violate MISAR_19.11:Macros are defined */
#if(\
		(BSWM_AR_RELEASE_MAJOR_VERSION_C != SCHM_BSWM_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_AR_RELEASE_MINOR_VERSION_C != SCHM_BSWM_AR_RELEASE_MINOR_VERSION) \
	)
/*#error "AutoSar Version Number of BswM.c and SchM_BswM.h are different "*/
#endif

#if (STD_ON == BSWM_DEV_ERROR_DETECT)
/* Check if current file and Det header file are of the same Autosar version */
#if(\
		(BSWM_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
	)
#error "AutoSar Version Number of BswM.c and Det.h are different "
#endif
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
#endif

/*====================================================================================================*
 *                                   EXTERNAL FUNCTION DECLARATIONS
 *====================================================================================================*/

/*====================================================================================================*
 *                                           LOCAL TYPEDEFS
 *====================================================================================================*/
/**
 * @brief  Action List Queue Struct.
 */
typedef struct
{
	/**< @brief Queue head. */
	uint16 Head;
	/**< @brief Queue tail. */
	uint16 Tail;
}BswM_QueueStructType;

/**
 * @brief  Type of request port.
 */
typedef struct
{
	/**< @brief Request port index. */
	uint32 Idx;
	/**< @brief Request port flag. */
	boolean Flag;
} BswM_RequesPortType;

/*====================================================================================================*
 *                                            LOCAL MACROS
 *====================================================================================================*/
#if defined(AH_BSWM_UNITTEST_ENABLED)

	#ifdef STATIC
		#undef STATIC
		#define STATIC
	#else
		#define STATIC
	#endif /* STATIC */

	#ifdef INLINE
		#undef INLINE
		#define INLINE
	#else
		#define STATIC_INLINE
	#endif /* INLINE */

	#ifdef STATIC_INLINE
		#undef STATIC_INLINE
		#define STATIC_INLINE
	#else
		#define STATIC_INLINE
	#endif /* STATIC_INLINE */
#else
	#ifndef STATIC
		#define STATIC static
	#endif /* STATIC */

	#ifndef INLINE
		#define INLINE inline
	#endif /* INLINE */

	#ifndef STATIC_INLINE
		#define STATIC_INLINE static inline
	#endif /* STATIC_INLINE */

#endif /* #if defined(AH_BSWM_UNITTEST_ENABLED) */

#if (STD_ON == BSWM_DEV_ERROR_DETECT)
/* PRQA S 3412 EOF # violate MISAR_19.4:Macros are defined */
#define BSWM_DET_REPORT(ApiId, ErrorId)\
	do\
	{\
		(void)Det_ReportError((uint16)(BSWM_MODULE_ID), (uint8)0, (uint8)(ApiId), (uint8)(ErrorId));\
	}while(0U)
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */

/**
 * @{
 * @brief Conditions
 */
/**
 * TRUE - Has been initialized
 * FALSE - Hasn't been initialized
 */
#define BSWM_C_ISINITED()   (BswM_IStatus == (boolean)TRUE)

/**
 * FALSE - Has been initialized
 * TRUE - Hasn't been initialized
 */
#define BSWM_C_ISUNINITED() (BswM_IStatus == (boolean)FALSE)

/**
 * TRUE - ptr is NULL_PTR
 * FALSE - ptr is not NULL_PTR
 */
/* PRQA S 3453  EOF# violate MSIAR2004_19.7: The macro definition is valid*/
#define BSWM_C_ISNULL(ptr)  ((ptr) == NULL_PTR)

#if (STD_ON == BSWM_ECUM_ENABLED)
/**
 * TRUE - state is invalid EcuM state
 * FALSE - state is valid EcuM state
 */
#define BSWM_C_ECUMSTATE_ISINVALID(state)((\
        ((state) == ECUM_STATE_STARTUP) ||\
		((state) == ECUM_STATE_RUN) ||\
		((state) == ECUM_STATE_APP_RUN) ||\
		((state) == ECUM_STATE_APP_POST_RUN) ||\
		((state) == ECUM_STATE_SHUTDOWN) ||\
		((state) == ECUM_STATE_SLEEP)) ? (boolean)FALSE : (boolean)TRUE)
#endif /* (STD_ON == BSWM_ECUM_ENABLED) */
/** @} */


/*====================================================================================================*
 *                                           LOCAL CONSTANTS
 *====================================================================================================*/


/*====================================================================================================*
 *                                           LOCAL VARIABLES
 *====================================================================================================*/
#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"/* PRQA S 5087 EOF # violate MISAR_19.1:It is correct. */

/**
 * @brief BswM configuration set pointer
 */
STATIC P2CONST(BswM_ConfigType, BSWM_VAR, BSWM_APPL_CONST) pBswM_IConfigPtr = NULL_PTR;

/**
 * @brief BswM mode request port  pointer
 */
STATIC P2CONST(BswM_ModeRequestPortType, BSWM_VAR, BSWM_APPL_CONST) \
															pBswM_IModeRequestedPorts = NULL_PTR;
/**
 * @brief BswM mode condition  pointer
 */
STATIC P2CONST(BswM_ModeConditionType, BSWM_VAR, BSWM_APPL_CONST) pBswM_IModeConditions = NULL_PTR;

/**
 * @brief BswM rules  pointer
 */
STATIC P2CONST(BswM_RuleType, BSWM_VAR, BSWM_APPL_CONST) pBswM_IRules = NULL_PTR;

#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"

#define BSWM_START_SEC_VAR_NO_INIT_BOOLEAN
#include "BswM_MemMap.h"
/**
 * @brief BswM module initialization status
 */
STATIC VAR(boolean, BSWM_VAR) BswM_IStatus = (boolean)FALSE;

/**
 * @brief  A flag of  whether the action queue is full
 */
STATIC VAR(boolean, BSWM_VAR) IActionListQueueFull = (boolean)FALSE ;

/**
 * @brief  A sign that the request pattern queue is full
 */
STATIC VAR(boolean, BSWM_VAR) IModeRequestQueueFull = (boolean)FALSE ;


STATIC VAR(boolean, BSWM_VAR) IDelayDefferRequestQueueFull  = (boolean)FALSE ;
/**
 * @brief The state of all action lists arbitrated in a single mode
 */
STATIC VAR(boolean, BSWM_VAR) BswM_IActionListStates[BSWM_ACTION_LIST_COUNT];

/**
 * @brief Storing the status of the current and previous arbitration rules
 */
STATIC VAR(boolean, BSWM_VAR) BswM_IArbitrateRuleStates[BSWM_ACTION_LIST_COUNT];

#define BSWM_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "BswM_MemMap.h"

#define BSWM_START_SEC_VAR_INIT_BOOLEAN
#include "BswM_MemMap.h"

/**
 * @brief A flag of  whether the action queue is empty or not
 */
STATIC VAR(boolean, BSWM_VAR) IActionListQueueEmpty = (boolean)TRUE;

/**
 * @brief  A flag of whether the request pattern queue is empty or not
 */
STATIC VAR(boolean, BSWM_VAR) IModeRequestQueueEmpty = (boolean)TRUE;

/**
 * @brief  A flag of whether the request pattern queue is empty or not
 */
STATIC VAR(boolean, BSWM_VAR) IDelayDefferRequestQueueEmpty = (boolean)TRUE;

#define BSWM_STOP_SEC_VAR_INIT_BOOLEAN
#include "BswM_MemMap.h"

#define BSWM_START_SEC_VAR_NO_INIT_8
#include "BswM_MemMap.h"

/**
 * @brief Locks that handle arbitration requests can only be arbitrated by one
 *        caller or master function at a time
 */
STATIC VAR(uint8, BSWM_VAR) BswM_IArbitrationLock = 0u;

/**
 * @brief Patterns for all requests
 */
STATIC VAR(BswM_ModeType, BSWM_VAR) BswM_IRequestedModes[BSWM_MODE_REQUEST_PORT_COUNT*BSWM_EXPANDED_PORT_MULTIPLE_COUNT];

/**
 * @brief Requested Modes Queue
 */
STATIC VAR(BswM_ModeType, BSWM_VAR) BswM_IRequestedModesQueue[BSWM_MODE_REQUEST_PORT_COUNT*BSWM_EXPANDED_PORT_MULTIPLE_COUNT];

STATIC VAR(BswM_ModeType, BSWM_VAR) BswM_IDelayDefferRequestedQueue[BSWM_MODE_REQUEST_PORT_COUNT*BSWM_EXPANDED_PORT_MULTIPLE_COUNT];

STATIC VAR(BswM_RequesPortType, BSWM_VAR) BswM_IDelayDefferRequestedIdx[BSWM_MODE_REQUEST_PORT_COUNT *BSWM_EXPANDED_PORT_MULTIPLE_COUNT];

STATIC VAR(BswM_RequesPortType, BSWM_VAR) BswM_DelayDefferRequested[BSWM_MODE_REQUEST_PORT_COUNT *BSWM_EXPANDED_PORT_MULTIPLE_COUNT] ;

STATIC VAR(BswM_ModeType, BSWM_VAR) BswM_DelayDefferRequestedQueue[BSWM_MODE_REQUEST_PORT_COUNT*BSWM_EXPANDED_PORT_MULTIPLE_COUNT];
#if (STD_ON == BSWM_COM_ENABLED)
/**
 * @brief Deadling Monitoring Control Vector
 */
STATIC VAR(Com_IpduGroupVector, BSWM_VAR) BswM_IComDMIpduGroupVector;

/**
 * @brief Pdu Group Switch Vector(Reinit = (boolean)TRUE)
 */
STATIC VAR(Com_IpduGroupVector, BSWM_VAR) BswM_IComPduGroupSwitchInitVector;

/**
 * @brief Pdu Group Switch Vector
 */
STATIC VAR(Com_IpduGroupVector, BSWM_VAR) BswM_IComPduGroupSwitchVector;
#endif /* (STD_ON == BSWM_COM_ENABLED) */

#define BSWM_STOP_SEC_VAR_NO_INIT_8
#include "BswM_MemMap.h"

#define BSWM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "BswM_MemMap.h"
/**
 * @brief Results of all request condition judgments
 */
STATIC VAR(BswM_ConditionStateType, BSWM_VAR) BswM_IConditionStates[BSWM_MODE_CONDITION_COUNT];

/**
 * @brief Results of all rules
 */
STATIC VAR(BswM_RuleStateType, BSWM_VAR) BswM_IRuleStates[BSWM_RULE_COUNT];

/**
 * @brief Action List
 */
STATIC P2VAR(BswM_ActionListType, AUTOMATIC, BSWM_VAR) BswM_IActionList[BSWM_ACTION_LIST_COUNT];

/**
 * @brief Requested Modes Id
 */
STATIC VAR(BswM_RequesPortType, BSWM_VAR) BswM_IRequestedModesIdx[BSWM_MODE_REQUEST_PORT_COUNT*BSWM_EXPANDED_PORT_MULTIPLE_COUNT];

/**
 * @brief Action request queue
 */
STATIC VAR(BswM_QueueStructType, BSWM_VAR) IActionListQueue = {0U, 0U} ;

/**
 * @brief Mode request queue
 */
STATIC VAR(BswM_QueueStructType, BSWM_VAR) IModeRequestQueue = {0U, 0U} ;


/**
 * @brief Delay  request queue
 */
STATIC VAR(BswM_QueueStructType, BSWM_VAR) IDelayDefferRequestQueue = {0U, 0U} ;
#define BSWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "BswM_MemMap.h"

/*====================================================================================================*
 *                                      LOCAL FUNCTION PROTOTYPES
 *====================================================================================================*/
#define BSWM_START_SEC_CODE
#include "BswM_MemMap.h"

STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_IModeRequestEnqueue(
		VAR(BswM_ModeType, AUTOMATIC) modeRequest,
		VAR(uint32, AUTOMATIC) idxcuonter
);

STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_IModeRequestDequeue(void);

STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_IDefferRequestDequeue(void);

STATIC FUNC(void, BSWM_CODE) BswM_Immediate_ProQueues(void);

STATIC FUNC(void, BSWM_CODE) BswM_Deferred_ProQueues(void);

STATIC FUNC(void, BSWM_CODE) BswM_Init_Queues(void);

STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_IActionListEnqueue
(
	P2CONST(BswM_ActionListType, AUTOMATIC, BSWM_APPL_CONST)  pActionList ,
	VAR(boolean, AUTOMATIC) triggered
);

STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_IActionListDequeue(void);

STATIC FUNC(BswM_ConditionStateType, BSWM_CODE) BswM_IArbDeferredModeCondition(
	P2CONST(BswM_ModeConditionType, AUTOMATIC, BSWM_APPL_CONST) pModeCondition
);

STATIC FUNC(BswM_ConditionStateType, BSWM_CODE) BswM_IArbitrateModeCondition(
	P2CONST(BswM_ModeConditionType, AUTOMATIC, BSWM_APPL_CONST) pModeCondition
);

STATIC  FUNC(BswM_ConditionStateType, BSWM_CODE) BswM_ILogicalOperate(
	CONST(BswM_LogicalOperatorType, AUTOMATIC) operation,
	CONST(BswM_ConditionStateType, AUTOMATIC) l,
	CONST(BswM_ConditionStateType, AUTOMATIC) r
);

STATIC FUNC(BswM_ConditionStateType, BSWM_CODE) BswM_IArbitrateLogicalExpression(
	P2CONST(BswM_LogicalExpressionType, AUTOMATIC, BSWM_APPL_CONST) pLogicalExpression
);

STATIC FUNC(boolean, BSWM_CODE) BswM_ISearchDeferredPort(
	P2CONST(BswM_LogicalExpressionType, AUTOMATIC, BSWM_APPL_CONST) pExpressionRef
);

STATIC FUNC(void, BSWM_CODE) BswM_IDeferArbitrateAllRules(void);

STATIC FUNC(void, BSWM_CODE) BswM_IArbitrateRule(
	P2CONST(BswM_RuleType, AUTOMATIC, BSWM_APPL_CONST) pRule,
	CONST(boolean, AUTOMATIC) isNested
);

STATIC FUNC(boolean, BSWM_CODE) BswM_ISearchImmediatePort(
	P2CONST(BswM_ModeRequestPortType, AUTOMATIC, BSWM_APPL_CONST) pModeRequestPort,
	P2CONST(BswM_LogicalExpressionType, AUTOMATIC, BSWM_APPL_CONST) pExpressionRef
);

STATIC FUNC(void, BSWM_CODE) BswM_IImmediateArbitrateAllRules(
	P2CONST(BswM_ModeRequestPortType, AUTOMATIC, BSWM_APPL_CONST) pModeRequestPort
);

STATIC FUNC(void, BSWM_CODE) BswM_IDelayArbitrateAllRules
(
	P2CONST(BswM_ModeRequestPortType, AUTOMATIC, BSWM_APPL_CONST) pModeRequestPort
);

STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_IGetArbitrationLock(VAR(uint32, AUTOMATIC) timeout);

STATIC FUNC(void, BSWM_CODE) BswM_IReleaseArbitrationLock(
	CONST(Std_ReturnType, AUTOMATIC) lastGetLockRet
);

STATIC FUNC(void, BSWM_CODE) BswM_IPerformActionList(
	P2CONST(BswM_ActionListType, AUTOMATIC, BSWM_APPL_CONST) pActionList,
	VAR(boolean, AUTOMATIC) isTriggered
);

STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_IPerformAction(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
);

STATIC FUNC(BswM_ConditionStateType, BSWM_CODE) BswM_IArbDeferredDeferredModeCondition(
	P2CONST(BswM_ModeConditionType, AUTOMATIC, BSWM_APPL_CONST) pModeCondition,
	CONST(uint32, AUTOMATIC) id
);

STATIC FUNC(void, BSWM_CODE) BswM_Immediate_After(void);

/**
 * @{
 * @brief declare all actions
 */
#if (STD_ON == BSWM_COMM_ENABLED)
/* PRQA S 1055 EOF # There is no need to modify the detection mechanism */
STATIC_INLINE FUNC(Std_ReturnType, BSWM_CODE) BswM_IComMAllowCom(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
);

STATIC_INLINE FUNC(Std_ReturnType, BSWM_CODE) BswM_IComMModeLimitation(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
);

STATIC_INLINE FUNC(Std_ReturnType, BSWM_CODE) BswM_IComMModeSwitch(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
);
#endif /* (STD_ON == BSWM_COMM_ENABLED) */

#if (STD_ON == BSWM_OS_ENABLED)
STATIC_INLINE FUNC(Std_ReturnType, BSWM_CODE) BswM_ICoreHaltMode(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
);
#endif /* (STD_ON == BSWM_OS_ENABLED) */

#if (STD_ON == BSWM_COM_ENABLED)
STATIC_INLINE FUNC(Std_ReturnType, BSWM_CODE) BswM_IDeadlingMonitoringControl(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
);

STATIC_INLINE FUNC(Std_ReturnType, BSWM_CODE) BswM_IPduGroupSwitch(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
);

STATIC_INLINE FUNC(Std_ReturnType, BSWM_CODE) BswM_ISwitchIPduMode(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
);

STATIC_INLINE FUNC(Std_ReturnType, BSWM_CODE) BswM_ITriggerIPduSend(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
);
#endif /* (STD_ON == BSWM_COM_ENABLED) */

#if (STD_ON == BSWM_ECUM_ENABLED)
STATIC_INLINE FUNC(Std_ReturnType, BSWM_CODE) BswM_IEcuMGoDown(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
);

STATIC_INLINE FUNC(Std_ReturnType, BSWM_CODE) BswM_IEcuMGoHalt(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
);

STATIC_INLINE FUNC(Std_ReturnType, BSWM_CODE) BswM_IEcuMGoPoll(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
);

STATIC_INLINE FUNC(Std_ReturnType, BSWM_CODE) BswM_IEcuMSelectShutdownTarget(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
);

STATIC_INLINE FUNC(Std_ReturnType, BSWM_CODE) BswM_IEcuMStateSwitch(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
);
#endif /* (STD_ON == BSWM_ECUM_ENABLED) */

#if (STD_ON == BSWM_FRSM_ENABLED)
STATIC_INLINE FUNC(Std_ReturnType, BSWM_CODE) BswM_IFrSMAllSlots(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
);
#endif /* (STD_ON == BSWM_FRSM_ENABLED) */

#if (STD_ON == BSWM_J1939DCM_ENABLED)
STATIC_INLINE FUNC(Std_ReturnType, BSWM_CODE) BswM_IJ1939DcmStateSwitch(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
);
#endif /* (STD_ON == BSWM_J1939DCM_ENABLED) */

#if (STD_ON == BSWM_J1939RM_ENABLED)
STATIC_INLINE FUNC(Std_ReturnType, BSWM_CODE) BswM_IJ1939RmStateSwitch(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
);
#endif /* (STD_ON == BSWM_J1939RM_ENABLED) */

#if (STD_ON == BSWM_LINSM_ENABLED)
STATIC_INLINE FUNC(Std_ReturnType, BSWM_CODE) BswM_ILinScheduleSwitch(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
);
#endif /* (STD_ON == BSWM_LINSM_ENABLED) */

#if (STD_ON == BSWM_NM_ENABLED)
STATIC_INLINE FUNC(Std_ReturnType, BSWM_CODE) BswM_INMControl(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
);
#endif /* (STD_ON == BSWM_NM_ENABLED) */

#if (STD_ON == BSWM_PDUR_ENABLED)
STATIC_INLINE FUNC(Std_ReturnType, BSWM_CODE) BswM_IPduRouterControl(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
);
#endif /* (STD_NO == BSWM_PDUR_ENABLED) */

#if (STD_ON == BSWM_SCHM_ENABLED)
STATIC_INLINE FUNC(Std_ReturnType, BSWM_CODE) BswM_IRteModeRequest(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
);

STATIC_INLINE FUNC(Std_ReturnType, BSWM_CODE) BswM_IRteSwitch(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
);
#endif /* (STD_ON == BSWM_SCHM_ENABLED) */

#if (STD_ON == BSWM_SCHM_ENABLED)
STATIC_INLINE FUNC(Std_ReturnType, BSWM_CODE) BswM_ISchMSwitch(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
);
#endif /* (STD_ON == BSWM_SCHM_ENABLED) */

#if (STD_ON == BSWM_SD_ENABLED)
STATIC_INLINE FUNC(Std_ReturnType, BSWM_CODE) BswM_ISdClientServiceModeRequest(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
);

STATIC_INLINE FUNC(Std_ReturnType, BSWM_CODE) BswM_ISdConsumedEventGroupModeRequest(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
);

STATIC_INLINE FUNC(Std_ReturnType, BSWM_CODE) BswM_ISdServerServiceModeRequest(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
);
#endif /* (STD_ON == BSWM_SD_ENABLED) */

#if (STD_ON == BSWM_GENERIC_REQUEST_ENABLED)
STATIC_INLINE FUNC(Std_ReturnType, BSWM_CODE) BswM_IUserCallout(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
);
#endif /* (STD_ON == BSWM_GENERIC_REQUEST_ENABLED) */
/** @} */

#define BSWM_STOP_SEC_CODE
#include "BswM_MemMap.h"

/*====================================================================================================*
 *                                           LOCAL FUNCTIONS
 *====================================================================================================*/
#define BSWM_START_SEC_CODE
#include "BswM_MemMap.h"

/**
 * @brief          Handles the list of actions in the queue
 * @param[in]      None
 * @param[out]     None
 * @param[in/out]  None
 * @return         void
 **/
STATIC FUNC(void, BSWM_CODE) BswM_Immediate_ProQueues(void)
{
	/* PRQA S 0781 EOF# violate MISRA_2004_Rule_5.6:Here local variables are used as traversal conditions */
	uint32 idx ;
	while(IActionListQueueEmpty != (boolean)TRUE)
	{
		BswM_IPerformActionList((BswM_IActionList[IActionListQueue.Head]), \
												BswM_IArbitrateRuleStates[IActionListQueue.Head]);
		BswM_IActionList[IActionListQueue.Head] = NULL_PTR;
		BswM_IArbitrateRuleStates[IActionListQueue.Head] = (boolean) FALSE;
		(void)BswM_IActionListDequeue();
	}
	/* clear state of action list */
	for(idx = 0U; idx < BSWM_ACTION_LIST_COUNT; idx++)
	{
		BswM_IActionListStates[idx] = (boolean)FALSE;
	}
}


/**
 * @brief     	   Handles the list of actions in the queue
 * @param[in]      None
 * @param[out]     None
 * @param[in/out]  None
 * @return         void
 **/
STATIC FUNC(void, BSWM_CODE) BswM_Deferred_ProQueues(void)
{
	uint32 idx ;
	while(IActionListQueueEmpty != (boolean)TRUE)
	{
		BswM_IPerformActionList((BswM_IActionList[IActionListQueue.Head]), \
												BswM_IArbitrateRuleStates[IActionListQueue.Head]);
		BswM_IActionList[IActionListQueue.Head] = NULL_PTR;
		BswM_IArbitrateRuleStates[IActionListQueue.Head] = (boolean) FALSE;
		(void)BswM_IActionListDequeue();
	}

	/* clear state of action list */
	for(idx = 0U; idx < BSWM_ACTION_LIST_COUNT; idx++)
	{
		BswM_IActionListStates[idx] = (boolean)FALSE;
	}
}


/**
 * @brief          put queue in it's initialized state
 * @param[in]      None
 * @param[out]     None
 * @param[in/out]  None
 * @return         void
 **/
STATIC FUNC(void, BSWM_CODE)  BswM_Init_Queues(void)
{
	uint32 idx;

    IActionListQueue.Head = (uint16)0 ;
    IActionListQueue.Tail = (uint16)0 ;

    IActionListQueueEmpty = (boolean)TRUE ;
    IActionListQueueFull = (boolean)FALSE ;

    IModeRequestQueue.Head = (uint16)0 ;
    IModeRequestQueue.Tail = (uint16)0 ;

    IDelayDefferRequestQueue.Head = (uint16)0 ;
    IDelayDefferRequestQueue.Tail = (uint16)0 ;

    IModeRequestQueueEmpty = (boolean)TRUE ;
    IModeRequestQueueFull = (boolean)FALSE ;

    IDelayDefferRequestQueueEmpty = (boolean)TRUE ;
    IDelayDefferRequestQueueFull = (boolean)FALSE ;

	/* initialize BswM_IActionListStates */
	for(idx = 0U; idx < BSWM_ACTION_LIST_COUNT; idx++)
	{
		BswM_IActionListStates[idx] = (boolean)FALSE;
	}

	/* initialize BswM_IRequestedModesQueue */
	for(idx = 0U; idx < ((uint32)(BSWM_MODE_REQUEST_PORT_COUNT*BSWM_EXPANDED_PORT_MULTIPLE_COUNT)); idx++)
	{
		BswM_IRequestedModesQueue[idx] = BSWM_INVALID_MODE;
		BswM_IRequestedModesIdx[idx].Idx = BSWM_INVALID_IDX;
		BswM_IRequestedModesIdx[idx].Flag = (boolean) FALSE;

		BswM_IDelayDefferRequestedQueue[idx] = BSWM_INVALID_MODE;
		BswM_IDelayDefferRequestedIdx[idx].Idx = BSWM_INVALID_IDX;
		BswM_IDelayDefferRequestedIdx[idx].Flag = (boolean) FALSE;
	}
}

/**
 * @brief          Add ActionList to the queue to be executed later
 * @param[in]      pActionList: action list
 * @param[in]      triggered: Is it triggered
 * @param[out]     None
 * @param[in/out]  None
 * @return         Std_ReturnType
 * @retval         E_OK: Add action list successfully
 * @retval 	       E_NOT_OK:Failed to add action list
 */
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_IActionListEnqueue
(
	P2CONST(BswM_ActionListType, AUTOMATIC, BSWM_APPL_CONST)  pActionList ,
	VAR(boolean, AUTOMATIC) triggered
)
{
	Std_ReturnType ret ;

	if(IActionListQueueFull == (boolean)TRUE)
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	else
	{
		/* PRQA S 0311  EOF# violate MSIAR2004_11.5: It's reasonable here. */
		BswM_IActionList[IActionListQueue.Tail] = (BswM_ActionListType*)pActionList;
		BswM_IArbitrateRuleStates[IActionListQueue.Tail] = triggered;
		/*if queue is empty, so insert your job directly*/
		if(IActionListQueueEmpty == (boolean)TRUE)
		{
			IActionListQueueEmpty = (boolean)FALSE ;
		}

		IActionListQueue.Tail++ ;

		/*When Tail reaches queue end*/
		if(IActionListQueue.Tail == BSWM_ACTION_LIST_COUNT)
		{
			IActionListQueue.Tail = (uint16)0 ;
		}

		/*When Tail reaches Head while enqueing, the queue is full*/
		if(IActionListQueue.Tail == IActionListQueue.Head)
		{
			IActionListQueueFull = (boolean)TRUE ;
		}
		ret = (Std_ReturnType)E_OK;
	}
    return ret;
}

/**
 * @brief          Remove a ActionList from the queue
 * @param[in]      None
 * @param[out]     None
 * @param[in/out]  None
 * @return         Std_ReturnType
 * @retval         E_OK: Remove action list successfully
 * @retval 		   E_NOT_OK:Failed to remove action list
 */
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_IActionListDequeue(void)
{
	Std_ReturnType ret ;
    /*Standard queue is empty , so return error*/
    if(IActionListQueueEmpty == (boolean)TRUE)
    {
    	ret = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        if(IActionListQueueFull == (boolean)TRUE)
        {
        	IActionListQueueFull = (boolean)FALSE;
        }

        IActionListQueue.Head++ ;

		if(IActionListQueue.Head == BSWM_ACTION_LIST_COUNT)
		{
			IActionListQueue.Head = (uint16)0 ;
		}

		if(IActionListQueue.Head == IActionListQueue.Tail)
		{
			IActionListQueueEmpty = (boolean)TRUE ;
		}

        ret = (Std_ReturnType)E_OK;
    }
    return ret;
}

/**
 * @brief     Add Mode Request to the queue to be executed later
 * @param[in] modeRequest:pattern requests to be added
 * @param[in] idxcuonter:counter
 * @return    Std_ReturnType
 * @retval    E_OK:    Add successfully
 * @retval    E_NOT_OK:Add failure
 */
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_IModeRequestEnqueue(
	VAR(BswM_ModeType, AUTOMATIC) modeRequest,
	VAR(uint32, AUTOMATIC) idxcuonter
)
{
	Std_ReturnType ret ;

	if(IModeRequestQueueFull == (boolean)TRUE)
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	else
	{
		/* PRQA S 0491  EOF# violate MSIAR2004_17.4: It's correct. */
		if(pBswM_IModeRequestedPorts[idxcuonter].BswMRequestProcessing == BSWM_IMMEDIATE)
		{
			BswM_IRequestedModesQueue[IModeRequestQueue.Tail] = modeRequest;
			BswM_IRequestedModesIdx[IModeRequestQueue.Tail].Idx = idxcuonter;
			BswM_IRequestedModesIdx[IModeRequestQueue.Tail].Flag = (boolean)TRUE;
			/* if queue is empty, so insert your job directly*/
			if(IModeRequestQueueEmpty == (boolean)TRUE)
			{
				IModeRequestQueueEmpty = (boolean)FALSE ;
			}

			IModeRequestQueue.Tail++ ;

			/*When Tail reaches queue end*/
			if(IModeRequestQueue.Tail == ((uint16)(BSWM_MODE_REQUEST_PORT_COUNT*BSWM_EXPANDED_PORT_MULTIPLE_COUNT)))
			{
				IModeRequestQueue.Tail = (uint16)0 ;
			}

			/*When Tail reaches Head while enqueing, the queue is full*/
			if(IModeRequestQueue.Tail == IModeRequestQueue.Head)
			{
				IModeRequestQueueFull = (boolean)TRUE ;
			}
		}
		else if(pBswM_IModeRequestedPorts[idxcuonter].BswMRequestProcessing == BSWM_DEFERRED)
		{
			BswM_IDelayDefferRequestedQueue[IDelayDefferRequestQueue.Tail] = modeRequest;
			BswM_IDelayDefferRequestedIdx[IDelayDefferRequestQueue.Tail].Idx = idxcuonter;
			/* if queue is empty, so insert your job directly*/
			if(IDelayDefferRequestQueueEmpty == (boolean)TRUE)
			{
				IDelayDefferRequestQueueEmpty = (boolean)FALSE ;
			}

			IDelayDefferRequestQueue.Tail++ ;

			/*When Tail reaches queue end*/
			if(IDelayDefferRequestQueue.Tail == ((uint16)(BSWM_MODE_REQUEST_PORT_COUNT*BSWM_EXPANDED_PORT_MULTIPLE_COUNT)))
			{
				IDelayDefferRequestQueue.Tail = (uint16)0 ;
			}

			/*When Tail reaches Head while enqueing, the queue is full*/
			if(IDelayDefferRequestQueue.Tail == IDelayDefferRequestQueue.Head)
			{
				IDelayDefferRequestQueueFull = (boolean)TRUE ;
			}
		}else{/*do nothing*/}

		ret = (Std_ReturnType)E_OK;
	}
    return ret;
}

/**
 * @brief     Remove a Mode Request from the queue
 * @param[in] None
 * @return    Std_ReturnType
 * @retval    E_OK:    Deleted successfully
 * @retval    E_NOT_OK:Failed to delete
 */
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_IModeRequestDequeue(void)
{
	Std_ReturnType ret ;
    /*Standard queue is empty and standard queue is empty, so return error*/
    if(IModeRequestQueueEmpty == (boolean)TRUE)
    {
    	ret = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        if(IModeRequestQueueFull == (boolean)TRUE)
        {
        	IModeRequestQueueFull = (boolean)FALSE;
        }

        IModeRequestQueue.Head++ ;

		if(IModeRequestQueue.Head == ((uint16)(BSWM_MODE_REQUEST_PORT_COUNT*BSWM_EXPANDED_PORT_MULTIPLE_COUNT)))
		{
			IModeRequestQueue.Head = (uint16)0 ;
		}

		if(IModeRequestQueue.Head == IModeRequestQueue.Tail)
		{
			IModeRequestQueueEmpty = (boolean)TRUE ;
		}

        ret = (Std_ReturnType)E_OK;
    }
    return ret;
}


/**
 * @brief     Remove a  Deffer Request from the queue
 * @param[in] None
 * @return    Std_ReturnType
 * @retval    E_OK:    Deleted successfully
 * @retval    E_NOT_OK:Failed to delete
 */
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_IDefferRequestDequeue(void)
{
	Std_ReturnType ret ;
    /*Standard queue is empty and standard queue is empty, so return error*/
    if(IDelayDefferRequestQueueEmpty == (boolean)TRUE)
    {
    	ret = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        if(IDelayDefferRequestQueueFull == (boolean)TRUE)
        {
        	IDelayDefferRequestQueueFull = (boolean)FALSE;
        }

        IDelayDefferRequestQueue.Head++ ;

		if(IDelayDefferRequestQueue.Head == ((uint16)(BSWM_MODE_REQUEST_PORT_COUNT *BSWM_EXPANDED_PORT_MULTIPLE_COUNT)))
		{
			IDelayDefferRequestQueue.Head = (uint16)0 ;
		}

		if(IDelayDefferRequestQueue.Head == IDelayDefferRequestQueue.Tail)
		{
			IDelayDefferRequestQueueEmpty = (boolean)TRUE ;
		}

        ret = (Std_ReturnType)E_OK;
    }
    return ret;
}

/**
 * @brief     Conditions of the arbitration model
 * @param[in] pModeCondition: Mode Condition pointer
 * @return    BswM_ConditionStateType
 * @retval    enum BswM_RuleStateType:
 * 				   BSWM_TRUE:The evaluation result is always treated as changed at the first
 * 				             evaluation of the rule after initialization
 *                 BSWM_UNDEFINED:The evaluation result is always treated as changed at the first
 *                                evaluation of the rule after initialization
 *                 BSWM_FALSE:The evaluation result is treated as changed if the rule is evaluated
 *                            to true.
 */
STATIC FUNC(BswM_ConditionStateType, BSWM_CODE) BswM_IArbitrateModeCondition(
	P2CONST(BswM_ModeConditionType, AUTOMATIC, BSWM_APPL_CONST) pModeCondition
)
{
	BswM_ConditionStateType ret = BSWM_UNDEFINED;
	uint32 portId = pModeCondition->pBswMConditionMode->BswM_ModeRequestedPortId;
	const BswM_ConditionValueType* pConditionValue;
	const BswM_BswModeType* pBswMode;
	boolean isEqual;
	/**
	 * @req [SWS_BswM_00064] If the container BswMModeInitValue does not exist [or the ModeRequest
	 *      does not already have an initial value, the] BswM shall treat the corresponding mode
	 *      condition as undefined and not use it for mode arbitration until the corresponding mode
	 *      arbitration request has been updated for the first time.
	 */
	if(BswM_IRequestedModes[portId] != BSWM_INVALID_MODE)
	{
		/*Defines the conditional match value*/
		if(pModeCondition->pBswMConditionValue != NULL_PTR)
		{
			pConditionValue = pModeCondition->pBswMConditionValue;
			if(pConditionValue->pBswMBswMode != NULL_PTR)
			{
				pBswMode = pConditionValue->pBswMBswMode;
				/*Is the desired value equal to the true value*/
				isEqual = (boolean)(pBswMode->BswMBswRequestedMode == (BswM_IRequestedModes[portId]));
				/*conditional judgment*/
				if(((pModeCondition->BswMConditionType == BSWM_EQUALS) && (isEqual == (boolean)FALSE))
			 || ((pModeCondition->BswMConditionType == BSWM_EQUALS_NOT) && (isEqual == (boolean)TRUE)))
				{
					ret = BSWM_FALSE;
				}
				else
				{
					ret = BSWM_TRUE;
				}
			} else { /* do nothing */ }
		} else { /* do nothing */ }

		if(ret == BSWM_UNDEFINED)
		{
			ret = (pModeCondition->BswMConditionType == BSWM_EQUALS) ? BSWM_FALSE : BSWM_TRUE;
		}
	} else { /* return BSWM_UNDEFINED */}
	return ret;
}

/**
 * @brief     Conditions of the arbitration model
 * @param[in] pModeCondition: Mode Condition pointer
 * @return    BswM_ConditionStateType
 * @retval    enum BswM_RuleStateType:
 * 				   BSWM_TRUE:The evaluation result is always treated as changed at the first
 * 				             evaluation of the rule after initialization
 *                 BSWM_UNDEFINED:The evaluation result is always treated as changed at the first
 *                                evaluation of the rule after initialization
 *                 BSWM_FALSE:The evaluation result is treated as changed if the rule is evaluated
 *                            to true.
 */
STATIC FUNC(BswM_ConditionStateType, BSWM_CODE) BswM_IArbDeferredModeCondition(
	P2CONST(BswM_ModeConditionType, AUTOMATIC, BSWM_APPL_CONST) pModeCondition
)
{
	BswM_ConditionStateType ret = BSWM_UNDEFINED;
	uint32 portId = pModeCondition->pBswMConditionMode->BswM_ModeRequestedPortId;
	const BswM_ConditionValueType* pConditionValue;
	const BswM_BswModeType* pBswMode;
	boolean isEqual;
	uint32 idx;
	boolean findflag = (boolean)FALSE;
	if(portId == BswM_IRequestedModesIdx[IModeRequestQueue.Head].Idx)
	{
		BswM_IRequestedModes[portId] = BswM_IRequestedModesQueue[IModeRequestQueue.Head];
		for(idx = (uint32)(pModeCondition->BswMModeConditionId + (uint32)1); idx < BSWM_MODE_CONDITION_COUNT; idx++)
		{
			/* PRQA S 0492  EOF# violate MSIAR2004_17.4: Ignore this warning */
			if(pModeCondition[idx].pBswMConditionMode->BswM_ModeRequestedPortId == BswM_IRequestedModesIdx[IModeRequestQueue.Head].Idx)
			{
				findflag = (boolean)TRUE;
				break;
			}
		}
		if(findflag == (boolean)FALSE)
		{
			BswM_IRequestedModesQueue[IModeRequestQueue.Head] = BSWM_INVALID_MODE;
			BswM_IRequestedModesIdx[IModeRequestQueue.Head].Idx = BSWM_INVALID_IDX;
			BswM_IRequestedModesIdx[IModeRequestQueue.Head].Flag = (boolean)FALSE;
			(void)BswM_IModeRequestDequeue();
		}

	}

	if(BswM_IRequestedModes[portId] != BSWM_INVALID_MODE)
	{
		/* Defines the conditional match value */
		if(pModeCondition->pBswMConditionValue != NULL_PTR)
		{
			pConditionValue = pModeCondition->pBswMConditionValue;
			if(pConditionValue->pBswMBswMode != NULL_PTR)
			{
				pBswMode = pConditionValue->pBswMBswMode;

				isEqual = (boolean)(pBswMode->BswMBswRequestedMode == (BswM_IRequestedModes[portId]));

				/*conditional judgment*/
				if(((pModeCondition->BswMConditionType == BSWM_EQUALS) && (isEqual == (boolean)FALSE))
				|| ((pModeCondition->BswMConditionType == BSWM_EQUALS_NOT) && (isEqual == (boolean)TRUE)))
				{
					ret = BSWM_FALSE;
				}
				else
				{
					ret = BSWM_TRUE;
				}
			} else { /* do nothing */ }
		} else { /* do nothing */ }
		if(ret == BSWM_UNDEFINED)
		{
			ret = (pModeCondition->BswMConditionType == BSWM_EQUALS) ? BSWM_FALSE : BSWM_TRUE;
		}
	} else { /* return BSWM_UNDEFINED */}
	return ret;
}

/**
 * @brief     Execute logical expression operations.
 * @param[in] operation: operator(computing).
 * @param[in] l: evaluation result
 * @param[in] r:evaluation result
 * @return    BswM_ConditionStateType
 * @retval    evaluation result
 */
STATIC_INLINE  FUNC(BswM_ConditionStateType, BSWM_CODE) BswM_ILogicalOperate(
	CONST(BswM_LogicalOperatorType, AUTOMATIC) operation,
	CONST(BswM_ConditionStateType, AUTOMATIC) l,
	CONST(BswM_ConditionStateType, AUTOMATIC) r
)
{
	BswM_ConditionStateType ret = BSWM_UNDEFINED;
	if((l == BSWM_UNDEFINED) && (r == BSWM_UNDEFINED))
	{
		ret = BSWM_UNDEFINED;
	}
	else if((l == BSWM_INVALID) ||(r == BSWM_INVALID))
	{
		ret = BSWM_INVALID;
	}
	else if(l == BSWM_UNDEFINED)
	{
		ret = r;
	}
	else if(r == BSWM_UNDEFINED)
	{
		ret = l;
	}
	else /*Both I and r are defined*/
	{
		switch(operation)
		{
		case BSWM_AND:
		/* PRQA S 4528  EOF# violate MSIAR2004_13.2: logical necessity */
		/* PRQA S 4115  EOF# violate MSIAR2004_12.6: logical necessity */
			ret = (BswM_RuleStateType)(l && r);
			break;
		case BSWM_NAND:
			ret = ((l == BSWM_FALSE) && (r == BSWM_FALSE)) ? (BSWM_TRUE):((l == r) ? BSWM_FALSE : BSWM_TRUE);
			break;
		case BSWM_OR:
			ret = (BswM_RuleStateType)(l || r);
			break;
		case BSWM_XOR:
			ret =  ((l!=r)?BSWM_TRUE:BSWM_FALSE);
			break;
		default: /* The condition is always not met*/
			break;
		}
	}
	return ret;
}

/**
 * @brief     Query Immediate Port.
 * @param[in] pModeRequestPort: Pointer to the requesting port .
 * @param[in] pExpressionRef: Pointer to the requesting expression .
 * @return    boolean
 * @retval    TRUE :Query Immediate Port Success
 * @retval    FALSE:Query Immediate Port Failure
 */
STATIC FUNC(boolean, BSWM_CODE) BswM_ISearchImmediatePort(
	P2CONST(BswM_ModeRequestPortType, AUTOMATIC, BSWM_APPL_CONST) pModeRequestPort,
	P2CONST(BswM_LogicalExpressionType, AUTOMATIC, BSWM_APPL_CONST) pExpressionRef
)
{
	boolean ret = (boolean)FALSE;
	uint32 idx ;
	if((pExpressionRef != NULL_PTR) && (pModeRequestPort != NULL_PTR))
	{
		if(pExpressionRef->pBswMLogicExpressionArgumentRef != NULL_PTR)
		{
			/*Iterate over subsequent logical expressions*/
			for(idx = 0U; idx < pExpressionRef->BswMLogicExpressionArgumentCount; idx++)
			{
				/* PRQA S 3670  EOF# violate MSIAR2004_16.2: The requires a recursive call to. */
				if(BswM_ISearchImmediatePort(pModeRequestPort, \
						pExpressionRef->pBswMLogicExpressionArgumentRef[idx]) == (boolean)TRUE)
				{
					ret = (boolean)TRUE;
					break;
				}
			}
		} else {/* do nothing */}

		if((ret == (boolean)FALSE) && (pExpressionRef->pBswMModeConditionArgumentRef != NULL_PTR))
		{
			/* Iterate over all pattern conditions*/
			for(idx = 0U; idx < pExpressionRef->BswMModeConditionArgumentCount; idx++)
			{
				/* Compare the pattern request port for the desired condition with the actual
				 * pattern request port*/
				if(pExpressionRef->pBswMModeConditionArgumentRef[idx]->pBswMConditionMode == \
						                                                            pModeRequestPort)
				{
					ret = (boolean)TRUE;
					break;
				}
			}
		} else {/* do nothing */}
	} else {/* do nothing */}
	return ret;
}

/**
 * @brief     Arbitration Logic Expressions  .
 * @param[in] pLogicalExpression: list of logical expressions .
 * @return    BswM_ConditionStateType
 * @retval    enum BswM_RuleStateType:
 * 				   BSWM_TRUE:The evaluation result is always treated as changed at the first
 * 				             evaluation of the rule after initialization
 *                 BSWM_UNDEFINED:The evaluation result is always treated as changed at the first
 *                                evaluation of the rule after initialization
 *                 BSWM_FALSE:The evaluation result is treated as changed if the rule is evaluated
 *                            to true.
 */
STATIC FUNC(BswM_ConditionStateType, BSWM_CODE) BswM_IArbitrateLogicalExpression(
	P2CONST(BswM_LogicalExpressionType, AUTOMATIC, BSWM_APPL_CONST) pLogicalExpression
)
{
	BswM_ConditionStateType ret = BSWM_UNDEFINED;
	BswM_ConditionStateType tmp;
	uint8 idx, condition_idx;
	if(pLogicalExpression->BswMLogicalOperator == BSWM_NOOP)
	{
		if(pLogicalExpression->pBswMLogicExpressionArgumentRef != NULL_PTR)
		{
			ret = BswM_IArbitrateLogicalExpression(pLogicalExpression->pBswMLogicExpressionArgumentRef[0]);
		}
		else
		{
			ret = BswM_IConditionStates[\
					pLogicalExpression->pBswMModeConditionArgumentRef[0]->BswMModeConditionId];
		}
	}
	else
	{
		/*Iterate through all subsequest logical conditions*/
		for(idx = 0U; idx < pLogicalExpression->BswMLogicExpressionArgumentCount; idx++)
		{
			tmp = BswM_IArbitrateLogicalExpression(pLogicalExpression->\
					                                 pBswMLogicExpressionArgumentRef[idx]);
			/*The conditions of BSWM_UNDEFINED will not participate in the logic judgment*/
			if((tmp != BSWM_UNDEFINED)&&(tmp != BSWM_INVALID))
			{
				ret = BswM_ILogicalOperate(pLogicalExpression->BswMLogicalOperator, ret, tmp);
			}
			else
			{
				ret = BSWM_INVALID;
			}
		}

		/*Iterate through all subsequest pattern conditions*/
		for(idx = 0U; idx < pLogicalExpression->BswMModeConditionArgumentCount; idx++)
		{
			condition_idx = pLogicalExpression->pBswMModeConditionArgumentRef[idx]->BswMModeConditionId;
			/*The conditions of BSWM_UNDEFINED will not participate in the logic judgment*/
			if(BswM_IConditionStates[condition_idx] != BSWM_UNDEFINED)
			{
				ret = BswM_ILogicalOperate(pLogicalExpression->BswMLogicalOperator, ret,\
						BswM_IConditionStates[condition_idx]);
			}
			else
			{
				ret = BSWM_INVALID;
			}
		}
	}
	return ret;
}

/**
 * @brief Query Delay Port
 * @param[in] pExpressionRef:logical expression
 * @return    boolean
 * @retval    TRUE:It's a delayed port
 * @retval    FALSE : Not a delayed port
 */
STATIC FUNC(boolean, BSWM_CODE) BswM_ISearchDeferredPort(
	P2CONST(BswM_LogicalExpressionType, AUTOMATIC, BSWM_APPL_CONST) pExpressionRef
)
{
	boolean ret = (boolean)FALSE;
	uint32 idx ;
	if(pExpressionRef != NULL_PTR)
	{
		if(pExpressionRef->pBswMLogicExpressionArgumentRef != NULL_PTR)
		{
			/*Iterate over subsequent logical expressions (recursive calls)*/
			for(idx = 0U; idx < pExpressionRef->BswMLogicExpressionArgumentCount; idx++)
			{
				/*deep priority search*/
				if(BswM_ISearchDeferredPort(pExpressionRef->pBswMLogicExpressionArgumentRef[idx]) == \
						                                                                 (boolean)TRUE)
				{
					ret = (boolean)TRUE;
					break;
				}
			}
		} else {/* do nothing */}

		if((ret == (boolean)FALSE) && (pExpressionRef->pBswMModeConditionArgumentRef != NULL_PTR))
		{
			/*Iterate over subsequent pattern conditions*/
			for(idx = 0U; idx < pExpressionRef->BswMModeConditionArgumentCount; idx++)
			{
				/*The rule exists for the port of BSWM_DEFERRED */
				if(pExpressionRef->pBswMModeConditionArgumentRef[idx]->\
						pBswMConditionMode->BswMRequestProcessing == BSWM_DEFERRED)
				{
					ret = (boolean)TRUE;
					break;
				}
			}
		} else {/* do nothing */}
	} else {/* do nothing */}
	return ret;
}


/**
 * @brief     Deferral of all rules of arbitration.
 * @param[in] None
 * @return    None
 * @retval    None
 */
STATIC FUNC(void, BSWM_CODE) BswM_IDeferArbitrateAllRules(void)
{
	uint32 idx;
	/* loop all rules */
	for(idx = 0U; idx < BSWM_RULE_COUNT; idx++)
	{
		/**
		 * @req [SWS_BswM_00075] The BswM_MainFunction shall perform evaluation of all rules that uses
		 *      at least one mode request with configuration parameter BswMRequestProcessing set to
		 *      BSWM_DEFERRED as input.
		 * @req [SWS_BswM_00060] All rules that use at least one deferred mode condition shall be
		 *      evaluated during every execution of the main function of BswM.
		 * @req [SWS_BswM_00016] The BswM shall perform mode control by means of action lists that
		 *      are executed as a result of rule evaluation in the mode arbitration.
		 */
		/* Queries whether delayed ports are configured*/
		if((boolean)TRUE == BswM_ISearchDeferredPort(pBswM_IRules[idx].pBswMRuleExpressionRef))
		{
			/*Arbitration Rules*/
			BswM_IArbitrateRule(&(pBswM_IConfigPtr->BswMArbitration.pBswMRule[idx]), (boolean)FALSE);
		}
	}
}

/**
 * @brief     Arbitration Rules  .
 * @param[in] pRule: regular linked list .
 * @param[in] isNested: Is it nested .
 * @return    None
 * @retval    None
 */
STATIC FUNC(void, BSWM_CODE) BswM_IArbitrateRule(
	P2CONST(BswM_RuleType, AUTOMATIC, BSWM_APPL_CONST) pRule,
	CONST(boolean, AUTOMATIC) isNested
)
{
	BswM_RuleStateType curRuleState;
	BswM_RuleStateType lastRuleState ;
	boolean isTriggered ;

	/**
	 * @req [ECUC_BswM_00935] This parameter defines for its related Rule if the Rule is an
	 *      Independent rule or a Subordinate rule;
     *      false: an Independent rule, i.e. to be evaluated each time applicable (both as
     *      standalone Rule driven by its own BswMModeRequestSource and when referenced by
     *      another Rule).
     *      true: a Subordinated rule, to be evaluated ONLY as a result of being referenced
     *      in one or more Action Lists.
     *      if TRUE,it can only be executed in the ActionList.
	 */
	if((pRule->BswMNestedExecutionOnly == (boolean)FALSE)
	||((pRule->BswMNestedExecutionOnly == (boolean)TRUE) && (isNested == (boolean)TRUE)))
	{
		curRuleState = BswM_IArbitrateLogicalExpression(pRule->pBswMRuleExpressionRef);
		lastRuleState = BswM_IRuleStates[pRule->BswMRuleId];
		BswM_IRuleStates[pRule->BswMRuleId] = curRuleState;
		isTriggered = (lastRuleState == curRuleState) ? (boolean)FALSE : (boolean)TRUE;

		/**
		 * @req [SWS_BswM_00015] For each rule of the mode arbitration, BswM shall be able to execute
		 *      different action lists based on if the rule evaluates to True or False.
		 */
		switch(BswM_IRuleStates[pRule->BswMRuleId])
		{
		case BSWM_FALSE:
			/**
			 * @req [SWS_BswM_00223] If an action list is triggered by multiple rules during mode
			 *      arbitration, the action list shall be executed only once.
			 */
			if((pRule->pBswMRuleFalseActionList != NULL_PTR) &&
			   (BswM_IActionListStates[pRule->pBswMRuleFalseActionList->BswMActionListIdx] == \
					                                                              (boolean)FALSE))
			{
				/* Make an action that has already been performed */
				BswM_IActionListStates[pRule->pBswMRuleFalseActionList->BswMActionListIdx] = (boolean)TRUE;
				(void)BswM_IActionListEnqueue(pRule->pBswMRuleFalseActionList , isTriggered);
			} else {/* do nothing */}
			break;
		case BSWM_TRUE:
			/**
			 * @req [SWS_BswM_00223] If an action list is triggered by multiple rules during mode
			 *      arbitration, the action list shall be executed only once.
			 */
			if((pRule->pBswMRuleTrueActionList != NULL_PTR) &&
			   (BswM_IActionListStates[pRule->pBswMRuleTrueActionList->BswMActionListIdx] == (boolean)FALSE))
			{
				/* Make an action that has already been performed*/
				BswM_IActionListStates[pRule->pBswMRuleTrueActionList->BswMActionListIdx] = (boolean)TRUE;
				(void)BswM_IActionListEnqueue(pRule->pBswMRuleTrueActionList , isTriggered);
			} else {/* do nothing */}
			break;
		default:
			/* do nothing */
			break;
		}
	} else {/* do nothing */}
}

/**
 * @brief     Immediate arbitration of all rules
 * @param[in] pModeRequestPort: mode request port pointer
 * @return    None
 * @retval    None
 */
STATIC FUNC(void, BSWM_CODE) BswM_IImmediateArbitrateAllRules(
	P2CONST(BswM_ModeRequestPortType, AUTOMATIC, BSWM_APPL_CONST) pModeRequestPort
)
{
	uint32 idx , condition_idx ;
	/* Update all associated conditions */
	for(condition_idx = 0U; condition_idx < BSWM_MODE_CONDITION_COUNT; condition_idx++)
	{
		if(pBswM_IModeConditions[condition_idx].pBswMConditionMode == pModeRequestPort)
		{
			BswM_IConditionStates[condition_idx] = \
					BswM_IArbitrateModeCondition(&(pBswM_IModeConditions[condition_idx]));
		} else {/* do nothing */}
	}
	/* loop all rules */
	for(idx = 0U; idx < BSWM_RULE_COUNT; idx++)
	{
		/*Arbitration rules only if this immediate request port exists*/

		if((boolean)TRUE == BswM_ISearchImmediatePort(pModeRequestPort, \
				                                          pBswM_IRules[idx].pBswMRuleExpressionRef))
		{
			/**
			 * @req [SWS_BswM_00016] The BswM shall perform mode control by means of action lists that are
			 *      executed as a result of rule evaluation in the mode arbitration.
			 */
			BswM_IArbitrateRule(&(pBswM_IConfigPtr->BswMArbitration.pBswMRule[idx]), (boolean)FALSE);
		} else {/* do nothing */}
	}
}

/**
 * @brief     Deferral of all rules of arbitration.
 * @param[in] pModeRequestPort:mode request port pointer
 * @return    None
 * @retval    None
 */
STATIC FUNC(void, BSWM_CODE) BswM_IDelayArbitrateAllRules
(
	P2CONST(BswM_ModeRequestPortType, AUTOMATIC, BSWM_APPL_CONST) pModeRequestPort
)
{
	uint32 idx;
	/* loop all rules */
	for(idx = 0U; idx < BSWM_RULE_COUNT; idx++)
	{
		/**
		 * @req [SWS_BswM_00075] The BswM_MainFunction shall perform evaluation of all rules that uses
		 *      at least one mode request with configuration parameter BswMRequestProcessing set to
		 *      BSWM_DEFERRED as input.
		 * @req [SWS_BswM_00060] All rules that use at least one deferred mode condition shall be
		 *      evaluated during every execution of the main function of BswM.
		 * @req [SWS_BswM_00016] The BswM shall perform mode control by means of action lists that
		 *      are executed as a result of rule evaluation in the mode arbitration.
		 */
		/* Queries whether delayed ports are configured*/
		if((boolean)TRUE == BswM_ISearchImmediatePort(pModeRequestPort,\
														  pBswM_IRules[idx].pBswMRuleExpressionRef))
		{
			/*Arbitration Rules*/
			BswM_IArbitrateRule(&(pBswM_IConfigPtr->BswMArbitration.pBswMRule[idx]), (boolean)FALSE);
		}
	}
}

/**
 * @brief     Implementation of individual acts.
 * @param[in] pAction: action  list
 * @return    Std_ReturnType
 * @retval    E_OK:    The return value of performing the relevent action
 * @retval    E_NOT_OK:The return value of performing the relevent action
 */
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_IPerformAction(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
)
{
	Std_ReturnType ret;
	/**
	 * @req [SWS_BswM_00039] The BswM shall be able to call any function in the AUTOSAR BSW even
	 *      though it is not among the standardized actions defined in BswMAvailableActions.
	 */
	switch(pAction->BswMAvailableActionsType)
	{
#if (STD_ON == BSWM_COMM_ENABLED)
	case BSWM_COMM_ALLOW_COM:
		ret = BswM_IComMAllowCom(pAction);
		break;
	case BSWM_COMM_MODE_LIMITATION:
		ret = BswM_IComMModeLimitation(pAction);
		break;
	case BSWM_COMM_MODE_SWITCH:
		ret = BswM_IComMModeSwitch(pAction);
		break;
#endif /* (STD_ON == BSWM_COMM_ENABLED) */
#if (STD_ON == BSWM_OS_ENABLED)
	case BSWM_CORE_HALT_MODE:
		ret = BswM_ICoreHaltMode(pAction);
		break;
#endif /* (STD_ON == BSWM_OS_ENABLED) */
#if (STD_ON == BSWM_COM_ENABLED)
	case BSWM_DEADLINE_MONITORING_CONTROL:
		ret = BswM_IDeadlingMonitoringControl(pAction);
		break;
	case BSWM_PDU_GROUP_SWITCH:
		ret = BswM_IPduGroupSwitch(pAction);
		break;
	case BSWM_SWITCH_IPDU_MODE:
		ret = BswM_ISwitchIPduMode(pAction);
		break;
	case BSWM_TRIGGER_IPDU_SEND:
		ret = BswM_ITriggerIPduSend(pAction);
		break;
#endif /* (STD_ON == BSWM_COM_ENABLED) */
#if (STD_ON == BSWM_ECUM_ENABLED)
	case BSWM_ECUM_GODOWN:
		ret = BswM_IEcuMGoDown(pAction);
		break;
	case BSWM_ECUM_GOHALT:
		ret = BswM_IEcuMGoHalt(pAction);
		break;
	case BSWM_ECUM_GOPOLL:
		ret = BswM_IEcuMGoPoll(pAction);
		break;
	case BSWM_ECUM_SELECT_SHUTDOWN_TARGET:
		ret = BswM_IEcuMSelectShutdownTarget(pAction);
		break;
	case BSWM_ECUM_STATE_SWITCH:
		ret = BswM_IEcuMStateSwitch(pAction);
		break;
#endif /* (STD_ON == BSWM_ECUM_ENABLED) */
#if (STD_ON == BSWM_FRSM_ENABLED)
	case BSWM_FRSM_ALL_SLOTS:
		ret = BswM_IFrSMAllSlots(pAction);
		break;
#endif /* (STD_ON == BSWM_FRSM_ENABLED) */
#if (STD_ON == BSWM_J1939DCM_ENABLED)
	case BSWM_J1939DCM_STATE_SWITCH:
		ret = BswM_IJ1939DcmStateSwitch(pAction);
		break;
#endif /* (STD_ON == BSWM_J1939DCM_ENABLED) */
#if (STD_ON == BSWM_J1939RM_ENABLED)
	case BSWM_J1939RM_STATE_SWITCH:
		ret = BswM_IJ1939RmStateSwitch(pAction);
		break;
#endif /* (STD_ON == BSWM_J1939RM_ENABLED) */
#if (STD_ON == BSWM_LINSM_ENABLED)
	case BSWM_LIN_SCHEDULE_SWITCH:
		ret = BswM_ILinScheduleSwitch(pAction);
		break;
#endif /* (STD_ON == BSWM_LINSM_ENABLED) */
#if (STD_ON == BSWM_NM_ENABLED)
	case BSWM_NM_CONTROL:
		ret = BswM_INMControl(pAction);
		break;
#endif /* (STD_ON == BSWM_NM_ENABLED) */
#if (STD_ON == BSWM_PDUR_ENABLED)
	case BSWM_PDU_ROUTER_CONTROL:
		ret = BswM_IPduRouterControl(pAction);
		break;
#endif /* (STD_ON == BSWM_PDUR_ENABLED) */
#if (STD_ON == BSWM_SCHM_ENABLED)
	case BSWM_RTE_MODE_REQUEST:
		ret = BswM_IRteModeRequest(pAction);
		break;
	case BSWM_RTE_SWITCH:
		ret = BswM_IRteSwitch(pAction);
		break;
#endif /* (STD_ON == BSWM_SCHM_ENABLED) */
#if (STD_ON == BSWM_SCHM_ENABLED)
	case BSWM_SCHM_SWITCH:
		ret = BswM_ISchMSwitch(pAction);
		break;
#endif /* (STD_ON == BSWM_SCHM_ENABLED) */
#if (STD_ON == BSWM_SD_ENABLED)
	case BSWM_SD_CLIENT_SERVICE_MODE_REQUEST:
		ret = BswM_ISdClientServiceModeRequest(pAction);
		break;
	case BSWM_SD_CONSUMED_EVENT_GROUP_MODE_REQUEST:
		ret = BswM_ISdConsumedEventGroupModeRequest(pAction);
		break;
	case BSWM_SD_SERVER_SERVICE_MODE_REQUEST:
		ret = BswM_ISdServerServiceModeRequest(pAction);
		break;
#endif /* (STD_ON == BSWM_SD_ENABLED) */
#if (STD_ON == BSWM_GENERIC_REQUEST_ENABLED)
	case BSWM_USER_CALLOUT:
		/**
		 * @req [SWS_BswM_00040] The BswM shall be able to call user defined functions.
		 * @req [SWS_BswM_00054] The parameters of the user defined functions, and their values,
		 *      shall be defined at ECU configuration time
		 */
		ret = BswM_IUserCallout(pAction);
		break;
#endif /* (STD_ON == BSWM_GENERIC_REQUEST_ENABLED) */
	default:
		ret = (Std_ReturnType)E_NOT_OK; /*terminate actionlist*/
		break;
	}
	return ret;
}

/**
 * @brief     Conditions of the arbitration model
 * @param[in] pModeCondition: Mode Condition pointer
 * @return    BswM_ConditionStateType
 * @retval    enum BswM_RuleStateType:
 * 				   BSWM_TRUE:The evaluation result is always treated as changed at the first
 * 				             evaluation of the rule after initialization
 *                 BSWM_UNDEFINED:The evaluation result is always treated as changed at the first
 *                                evaluation of the rule after initialization
 *                 BSWM_FALSE:The evaluation result is treated as changed if the rule is evaluated
 *                            to true.
 */
STATIC FUNC(BswM_ConditionStateType, BSWM_CODE) BswM_IArbDeferredDeferredModeCondition(
	P2CONST(BswM_ModeConditionType, AUTOMATIC, BSWM_APPL_CONST) pModeCondition,
	CONST(uint32, AUTOMATIC) id
)
{
	BswM_ConditionStateType ret = BSWM_UNDEFINED;
	const BswM_ModeRequestPortType * BswM_ModeRequestPort;
	const BswM_ConditionValueType* pConditionValue;
	const BswM_BswModeType* pBswMode;
	boolean isEqual;
	uint32 portId;
	BswM_ModeRequestPort = pModeCondition->pBswMConditionMode;
	portId = BswM_ModeRequestPort->BswM_ModeRequestedPortId;
	if(portId == BswM_DelayDefferRequested[id].Idx)
	{
		BswM_IRequestedModes[portId] = BswM_DelayDefferRequestedQueue[id];
	}

	if(BswM_IRequestedModes[portId] != BSWM_INVALID_MODE)
	{
		/* Defines the conditional match value */
		if(pModeCondition->pBswMConditionValue != NULL_PTR)
		{
			pConditionValue = pModeCondition->pBswMConditionValue;
			if(pConditionValue->pBswMBswMode != NULL_PTR)
			{
				pBswMode = pConditionValue->pBswMBswMode;

				isEqual = (boolean)(pBswMode->BswMBswRequestedMode == (BswM_IRequestedModes[portId]));

				/*conditional judgment*/
				if(((pModeCondition->BswMConditionType == BSWM_EQUALS) && (isEqual == (boolean)FALSE))
				|| ((pModeCondition->BswMConditionType == BSWM_EQUALS_NOT) && (isEqual == (boolean)TRUE)))
				{
					ret = BSWM_FALSE;
				}
				else
				{
					ret = BSWM_TRUE;
				}
			} else { /* do nothing */ }
		} else { /* do nothing */ }
		if(ret == BSWM_UNDEFINED)
		{
			ret = (pModeCondition->BswMConditionType == BSWM_EQUALS) ? BSWM_FALSE : BSWM_TRUE;
		}
	} else { /* return BSWM_UNDEFINED */}
	return ret;
}

/**
 * @brief     List of implementation activities.
 * @param[in] pActionList: Action list
 * @return    isTriggered: Is it triggered
 * @retval    None
 * @retval    None
 */
STATIC FUNC(void, BSWM_CODE) BswM_IPerformActionList(
	P2CONST(BswM_ActionListType, AUTOMATIC, BSWM_APPL_CONST) pActionList,
	VAR(boolean, AUTOMATIC) isTriggered
)
{
	BswM_ActionListExecutionType exec = pActionList->BswMActionListExecution;
	const BswM_ActionListItemType* pActionListItem;
	uint8 idx ;
	/**
	 * @req [SWS_BswM_00011] If a True action list is configured for triggered execution,
	 *      the BswM shall only execute it when the evaluation of the corresponding rule changes
	 *      from False to True.
	 * @req [SWS_BswM_00023] If a False action list is configured for triggered execution the BswM
	 *      shall only execute it when the evaluation of the corresponding rule changes from True
	 *      to False.
	 * @req [SWS_BswM_00115] If a False action list is configured for triggered execution the BswM
	 *      shall only execute it when the evaluation of the corresponding rule changes from True
	 *      to False.
	 * @req [SWS_BswM_00116] If a False action list is configured for conditional execution, the BswM
	 *      shall execute it every time the corresponding rule is evaluated to False.
	 */
	/* PRQA S 4558  EOF# violate MSIAR2004_13.2:  Ignore the type here for now */
	if((exec == BSWM_CONDITION) || ((exec == BSWM_TRIGGER) && isTriggered))
	{
		/**
		 * @req [SWS_BswM_00017] An action list comprises a set of actions that BswM shall execute in
		 *      an ordered manner.
		 */
		/*loop all action items*/
		for(idx = 0U; idx < pActionList->BswMActionListItemCount; idx++)
		{
			pActionListItem = &(pActionList->pBswMActionListItem[idx]);
			if(pActionListItem->BswM_ActionListItemsType == BSWM_ACTION)
			{
				/**
				 * @req [SWS_BswM_00055] The BswM shall abort the execution of an action list if an
				 *      action returns E_NOT_OK and the corresponding BswMAbortOnFail configuration
				 *      parameter is set to 鈥渢rue鈥�.
				 * @req [SWS_BswM_00121] The BswM shall report a DEM event if an action returns
				 *      E_NOT_OK and the corresponding BswMReportFailToDemRef configuration parameter
				 *      is set
				 */
				/* PRQA S 0317 EOF # violate MSIAR2004_11.4: The pionter is valid. */
				if((Std_ReturnType)E_NOT_OK == \
						             BswM_IPerformAction(pActionListItem->pBswMActionListItemRef))
				{
					/* 0 --- Invalid DemId */
				#if (BSWM_DEM_ENABLED == STD_ON)
					if(pActionListItem->BswMReportFailToDemRef != 0U)
					{
						/* Notification of Dem failure */
						Dem_ReportErrorStatus(pActionListItem->BswMReportFailToDemRef , \
								                               (Dem_EventStatusType)DEM_EVENT_STATUS_FAILED);
					} else {/* do nothing */}
				#endif/* #if (BSWM_DEM_ENABLED == STD_ON) */
					if((boolean)TRUE == pActionListItem->BswMAbortOnFail)
					{
						break; /* Termination of the queue when an action fails to occur */
					} else {/* do nothing */}
				}
				else
				{
					/* 0 --- Invalid DemId */
				#if (BSWM_DEM_ENABLED == STD_ON)
					if(pActionListItem->BswMReportFailToDemRef != 0U)
					{
						/* Notification of Dem failure */
						Dem_ReportErrorStatus(pActionListItem->BswMReportFailToDemRef , \
								                               (Dem_EventStatusType)DEM_EVENT_STATUS_PASSED);
					} else {/* do nothing */}
				#endif/* #if (BSWM_DEM_ENABLED == STD_ON) */
				}
			}
			else if(pActionListItem->BswM_ActionListItemsType == BSWM_ACTION_LIST)
			{
				/**
				 * @req [SWS_BswM_00018] An action list may contain links to other action lists that
				 *      BswM shall include in the execution.
				 * @req [SWS_BswM_00037] If cascaded action lists are used (i.e. using references to
				 *      other rules or action lists) the action list structure may contain up to
				 *      seven (7) hierarchic levels.Note: The purpose of this limit is to make testing
				 *      of BswM implementations and generator tools possible. The limit must be checked
				 *      by the generator tool.
				 */
				BswM_IPerformActionList(pActionListItem->pBswMActionListItemRef, isTriggered);
			}
			else if(pActionListItem->BswM_ActionListItemsType == BSWM_RULE)
			{
				/**
				 * @req [SWS_BswM_00019] An action list may also include links to mode arbitration
				 *      rules that BswM shall evaluate within the scope of the execution of the current
				 *      action list.
				 * @req [SWS_BswM_00067] If a rule is included in an action list as specified in
				 *      [SWS_BswM_00019, any action list execution resulting from that evaluation
				 *      shall be executed by BswM before it continues to execute the original action
				 *      list.
				 * @req [SWS_BswM_00062] Action lists associated with rules evaluated in the context of
				 *      the mode arbitration request shall be executed by BswM immediately when triggered
				 *      by the mode arbitration, and not be deferred to the main function execution.
				 *      Rationale: This allows very short latencies on mode requests when necessary.
				 */
				BswM_IArbitrateRule(pActionListItem->pBswMActionListItemRef, (boolean)TRUE);
			} else {/* do nothing */}
		}
	} else {/* do nothing */}
}

/**
 * @brief     Implementing  Spin Locks for Pattern Arbitration.
 * @param[in] timeout
 * @return    Std_ReturnType
 * @retval    E_OK:   Locked
 * @retval    E_NOT_OK:Failed to losk
 */
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_IGetArbitrationLock(VAR(uint32, AUTOMATIC) timeout)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
	do
	{
		/* waiting for timeout or lock free */
		if(BswM_IArbitrationLock == 0U)
		{
			/* try to get lock */
			SchM_Enter_BswM_EXCLUSIVE_AREA_00();
			BswM_IArbitrationLock = (uint8)1;
			ret = (Std_ReturnType)E_OK;
			SchM_Exit_BswM_EXCLUSIVE_AREA_00();
		}
		timeout--;
	} while(((ret == (Std_ReturnType)E_NOT_OK) && (timeout > (uint32)0U)));
	return ret;
}

/**
 * @brief     Spin Locks for release mode Arbitration.
 * @param[in] lastGetLockRet:last acquired lock
 * @return    None
 * @retval    None
 */
STATIC_INLINE  FUNC(void, BSWM_CODE) BswM_IReleaseArbitrationLock(
	CONST(Std_ReturnType, AUTOMATIC) lastGetLockRet
)
{
	if(lastGetLockRet == (Std_ReturnType)E_OK)
	{
		BswM_IArbitrationLock = 0U;
	} else {/* do nothing */}
}

/**
 * @{
 * @brief     All actions
 * @param[in] pAction: action
 * @return    Std_ReturnType
 * @retval    E_OK:Successful execution of the action
 * @retval    E_NOT_OK:Unsuccessful action execution
 */
#if (STD_ON == BSWM_COMM_ENABLED)
STATIC_INLINE  FUNC(Std_ReturnType, BSWM_CODE) BswM_IComMAllowCom(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
)
{
	Std_ReturnType ret = (Std_ReturnType)E_OK;
	const BswM_ComMAllowComType* action = (pAction->pBswMAvailableActions);
	if(action != NULL_PTR)
	{
		ComM_CommunicationAllowed(action->BswMComMAllowChannelRef, action->BswMComAllowed);
	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	return ret;
}

STATIC_INLINE  FUNC(Std_ReturnType, BSWM_CODE) BswM_IComMModeLimitation(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
)
{
	Std_ReturnType ret;
	const BswM_ComMModeLimitationType* action = (pAction->pBswMAvailableActions);
	if(action != NULL_PTR)
	{
	#if ((STD_ON == COMM_RESET_AFTER_FORCING_NO_COMM) && (STD_ON == COMM_MODE_LIMITATION_ENABLED))
		ret = ComM_LimitChannelToNoComMode(action->BswMComMLimitChannelRef, action->BswMComMLimitMode);
	#endif /* ((STD_ON == COMM_RESET_AFTER_FORCING_NO_COMM) && (STD_ON == COMM_MODE_LIMITATION_ENABLED)) */
	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	return ret;
}

STATIC_INLINE  FUNC(Std_ReturnType, BSWM_CODE) BswM_IComMModeSwitch(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
)
{
	Std_ReturnType ret;
	const BswM_ComMModeSwitchType* action = (pAction->pBswMAvailableActions);
	if(action != NULL_PTR)
	{
		ret = ComM_RequestComMode(action->BswMComMUserRef, action->BswMComMRequestedMode);
	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	return ret;
}
#endif /* (STD_ON == BSWM_COMM_ENABLED) */

#if (STD_ON == BSWM_OS_ENABLED)
STATIC_INLINE  FUNC(Std_ReturnType, BSWM_CODE) BswM_ICoreHaltMode(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
)
{
	Std_ReturnType ret = (Std_ReturnType)E_OK;
	/* @todo not yet realized */
	return ret;
}
#endif /* (STD_ON == BSWM_OS_ENABLED) */

#if (STD_ON == BSWM_COM_ENABLED)
STATIC_INLINE  FUNC(Std_ReturnType, BSWM_CODE) BswM_IDeadlingMonitoringControl(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
)
{
	Std_ReturnType ret = (Std_ReturnType)E_OK;
	const BswM_DeadlineMonitoringControlType* action = (pAction->pBswMAvailableActions);
	uint16 idx;
	for(idx = 0U; idx < action->BswMDiabledCount; idx++)
	{
		Com_SetIpduGroup(BswM_IComDMIpduGroupVector, action->pBswMDisabledDMPduGroupRef[idx], \
				                                                                   (boolean)FALSE);
	}
	for(idx = 0U; idx < action->BswMEnabledCount; idx++)
	{
		Com_SetIpduGroup(BswM_IComDMIpduGroupVector, action->pBswMEnabledDMPduGroupRef[idx], \
				                                                                 (boolean)TRUE);
	}
	/**
	 * @req [SWS_BswM_00225] If any BswMDeadlineMonitoringControl action(s) have been performed,
	 *      the BswM shall execute the Com_ReceptionDMControl command at the end of its processing
	 *      of the BswM main function or an immediate request processing.
	 */
	Com_ReceptionDMControl(BswM_IComDMIpduGroupVector);
	return ret;
}

STATIC_INLINE  FUNC(Std_ReturnType, BSWM_CODE) BswM_IPduGroupSwitch(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
)
{
	Std_ReturnType ret = (Std_ReturnType)E_OK;
	uint16 idx;
	static boolean firstCall = (boolean)TRUE;
	const BswM_PduGroupSwitchType* action = (pAction->pBswMAvailableActions);
	/**
	 * @req [SWS_BswM_00234] The BswM shall utilize two different internal IpduGroupVectors for
	 *      BswMPduGroupSwitch actions. One vector shall accumulate only the BswMPduGroupSwitches
	 *      which have BswMPduGroupSwitchReinit set to true, and the other vector shall accumulate
	 *      all of BswMPduGroupSwitches (including those with BswMPduGroupSwitchReinit set to true).
	 *      For the first call of Com_IpduGroupControl, the vector for BswMPduGroupSwitchReinit == true
	 *      shall be used. For the second call of Com_IpduGroupControl, the other vector shall be used.
	 *      After the second call of Com_IpduGroupControl, the vector for BswMPduGroupSwitchReinit ==
	 *      true shall be overwritten with the value of the other vector.
	 */
	if(action->BswMPduGroupSwitchReinit == (boolean)TRUE)
	{
		for(idx = 0U; idx < action->BswMDiabledCount; idx++)
		{
			Com_SetIpduGroup(BswM_IComPduGroupSwitchInitVector, \
					action->pBswMDisabledPduGroupRef[idx], (boolean)FALSE);
			Com_SetIpduGroup(BswM_IComPduGroupSwitchVector, \
					action->pBswMDisabledPduGroupRef[idx], (boolean)FALSE);
		}
		for(idx = 0U; idx < action->BswMEnabledCount; idx++)
		{
			Com_SetIpduGroup(BswM_IComPduGroupSwitchInitVector, \
					action->pBswMEnabledPduGroupRef[idx], (boolean)TRUE);
			Com_SetIpduGroup(BswM_IComPduGroupSwitchVector, \
					action->pBswMEnabledPduGroupRef[idx], (boolean)TRUE);
		}
	}
	else
	{
		for(idx = 0U; idx < action->BswMDiabledCount; idx++)
		{
			Com_SetIpduGroup(BswM_IComPduGroupSwitchVector, \
					action->pBswMDisabledPduGroupRef[idx], (boolean)FALSE);
		}
		for(idx = 0U; idx < action->BswMEnabledCount; idx++)
		{
			Com_SetIpduGroup(BswM_IComPduGroupSwitchVector, \
					action->pBswMEnabledPduGroupRef[idx], (boolean)TRUE);
		}

	}
	if((firstCall == (boolean)TRUE) && (action->BswMPduGroupSwitchReinit == (boolean)TRUE))
	{
		firstCall = (boolean)FALSE;
		/**
		 * @req [SWS_BswM_00129] If any BswMPduGroupSwitch action(s) have been performed, the BswM
		 *      shall execute the Com_IpduGroupControl commands at the end of its processing of the
		 *      BswM main function or an immediate request processing.
		 */
		Com_IpduGroupControl(BswM_IComPduGroupSwitchInitVector, (boolean)TRUE);
	}
	else
	{
		/** @req SWS_BswM_00129 */
		Com_IpduGroupControl(BswM_IComPduGroupSwitchVector, (boolean)FALSE);
		for(idx = 0U; idx < sizeof(BswM_IComPduGroupSwitchVector); idx++)/* PRQA S 2877 # violate MISAR_21.1:It is correct*/
		{
			BswM_IComPduGroupSwitchInitVector[idx] =  BswM_IComPduGroupSwitchVector[idx];
		}
	}
	return ret;
}

STATIC_INLINE  FUNC(Std_ReturnType, BSWM_CODE) BswM_ISwitchIPduMode(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
)
{
	Std_ReturnType ret = (Std_ReturnType)E_OK;
	const BswM_SwitchIPduModeType* action = (pAction->pBswMAvailableActions);
	if(action != NULL_PTR)
	{
		Com_SwitchIpduTxMode(action->BswMSwitchIPduModeRef, action->BswMSwitchIPduModeValue);
	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	return ret;
}

STATIC_INLINE  FUNC(Std_ReturnType, BSWM_CODE) BswM_ITriggerIPduSend(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
)
{
	Std_ReturnType ret = (Std_ReturnType)E_OK;
	const BswM_TriggerIPduSendType* action = (pAction->pBswMAvailableActions);
	uint16 idx;
	for(idx = 0U; idx < action->BswMTriggeredIPduCount; idx++)
	{
		ret |= Com_TriggerIPDUSend(action->pBswMTriggeredIPduRef[idx]);
	}
	return ret;
}
#endif /* (STD_ON == BSWM_COM_ENABLED) */

#if (STD_ON == BSWM_ECUM_ENABLED)
STATIC_INLINE  FUNC(Std_ReturnType, BSWM_CODE) BswM_IEcuMGoDown(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
)
{
	Std_ReturnType ret;
	const BswM_EcuMGoDownType* action = (pAction->pBswMAvailableActions);
	if(action != NULL_PTR)
	{
		ret = EcuM_GoDown(action->BswMEcuMUserIdRef);
	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	return ret;
}

STATIC_INLINE  FUNC(Std_ReturnType, BSWM_CODE) BswM_IEcuMGoHalt(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
)
{
	Std_ReturnType ret;
	ret = EcuM_GoHalt();
	return ret;
}

STATIC_INLINE  FUNC(Std_ReturnType, BSWM_CODE) BswM_IEcuMGoPoll(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
)
{
	Std_ReturnType ret;
	ret = EcuM_GoPoll();
	return ret;
}

STATIC_INLINE  FUNC(Std_ReturnType, BSWM_CODE) BswM_IEcuMSelectShutdownTarget(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
)
{
	Std_ReturnType ret;
	const BswM_EcuMSelectShutdownTargetType* action = (pAction->pBswMAvailableActions);
	if(ECUM_SHUTDOWN_TARGET_SLEEP == action->BswMEcuMShutdownTarget)
	{
		ret = (Std_ReturnType)EcuM_SelectShutdownTarget(ECUM_SHUTDOWN_TARGET_SLEEP, \
				                                                      action->BswMEcuMSleepModeRef);
	}
	else if(ECUM_SHUTDOWN_TARGET_RESET == action->BswMEcuMShutdownTarget)
	{
		ret = (Std_ReturnType)EcuM_SelectShutdownTarget(ECUM_SHUTDOWN_TARGET_RESET, \
				                                                       action->BswMEcuMResetModeRef);
	}
	else /* ECUM_STATE_OFF */
	{
		ret = (Std_ReturnType)EcuM_SelectShutdownTarget(ECUM_SHUTDOWN_TARGET_OFF, \
				                                                           (EcuM_ShutdownModeType)0);
	}
	return ret;
}

STATIC_INLINE  FUNC(Std_ReturnType, BSWM_CODE) BswM_IEcuMStateSwitch(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
)
{
	Std_ReturnType ret = (Std_ReturnType)E_OK;
	const BswM_EcuMStateSwitchType* action = (pAction->pBswMAvailableActions);
	if(action != NULL_PTR)
	{
		EcuM_SetState(action->BswMEcuMState);
	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	return ret;
}
#endif /* (STD_ON == BSWM_ECUM_ENABLED) */

#if (STD_ON == BSWM_FRSM_ENABLED)
STATIC_INLINE  FUNC(Std_ReturnType, BSWM_CODE) BswM_IFrSMAllSlots(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
)
{
	Std_ReturnType ret;
	const BswM_FrSMAllSlotsType* action = (pAction->pBswMAvailableActions);
	if(action != NULL_PTR)
	{
		ret = FrSM_AllSlots(action->BswMFrSMAllSlotsNetworkHandleRef);
	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	return ret;
}
#endif /* (STD_ON == BSWM_FRSM_ENABLED) */

#if (STD_ON == BSWM_J1939DCM_ENABLED)
STATIC_INLINE  FUNC(Std_ReturnType, BSWM_CODE) BswM_IJ1939DcmStateSwitch(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
)
{
	Std_ReturnType ret;
	const BswM_J1939DcmStateSwitchType* action = (pAction->pBswMAvailableActions);
	if(action != NULL_PTR)
	{
		ret = J1939Dcm_SetState(action->BswMJ1939DcmChannelRef, \
				action->BswMJ1939DcmNodeRef, \
				action->BswMJ1939DcmRequestedState);
	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	return ret;
}
#endif /* (STD_ON == BSWM_J1939DCM_ENABLED) */

#if (STD_ON == BSWM_J1939RM_ENABLED)
STATIC_INLINE  FUNC(Std_ReturnType, BSWM_CODE) BswM_IJ1939RmStateSwitch(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
)
{
	Std_ReturnType ret ;
	const BswM_J1939RmStateSwitchType* action = \
			(const BswM_J1939RmStateSwitchType*)(pAction->pBswMAvailableActions);
	ret = J1939Rm_SetState(action->BswMJ1939RmChannelRef, \
			action->BswMJ1939RmNodeRef, \
			action->BswMJ1939RmRequestedState);
	return ret;
}
#endif /* (STD_ON == BSWM_J1939RM_ENABLED) */

#if (STD_ON == BSWM_LINSM_ENABLED)
STATIC_INLINE  FUNC(Std_ReturnType, BSWM_CODE) BswM_ILinScheduleSwitch(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
)
{
	Std_ReturnType ret;
	const BswM_LinScheduleSwitchType* action = (pAction->pBswMAvailableActions);
	if(action != NULL_PTR)
	{
		ret = LinSM_ScheduleRequest(action->BswMLinScheduleNetworkHandle, action->BswMLinScheduleRef);
	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	return ret;
}
#endif /* (STD_ON == BSWM_LINSM_ENABLED) */

#if (STD_ON == BSWM_NM_ENABLED)
STATIC_INLINE  FUNC(Std_ReturnType, BSWM_CODE) BswM_INMControl(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
)
{
	Std_ReturnType ret = (Std_ReturnType)E_OK;
	const BswM_NMControlType* action = (pAction->pBswMAvailableActions);
	if(BSWM_NM_DISABLE == action->BswMNMAction)
	{
		ret = Nm_DisableCommunication(action->BswMComMNetworkHandleRef);
	}
	else if(BSWM_NM_ENABLE == action->BswMNMAction)
	{
		ret = Nm_EnableCommunication(action->BswMComMNetworkHandleRef);
	} else {/* do nothing */}
	return ret;
}
#endif /* (STD_ON == BSWM_NM_ENABLED) */

#if (STD_ON == BSWM_PDUR_ENABLED)
STATIC_INLINE  FUNC(Std_ReturnType, BSWM_CODE) BswM_IPduRouterControl(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
)
{
	Std_ReturnType ret = (Std_ReturnType)E_OK;
	uint16 idx = 0U;
	const BswM_PduRouterControlType* action = \
			(const BswM_PduRouterControlType*)(pAction->pBswMAvailableActions);
	if(BSWM_PDUR_ENABLE == action->BswMPduRouterAction)
	{
		for(idx = 0U; idx < action->BswMPduRoutingPathGroupCount; idx++)
		{
			PduR_EnableRouting(action->pBswMPduRoutingPathGroupRef[idx]);
		}
	}
	else if(BSWM_PDUR_DISABLE == action->BswMPduRouterAction)
	{
		for(idx = 0U; idx < action->BswMPduRoutingPathGroupCount; idx++)
		{
			PduR_DisableRouting(action->pBswMPduRoutingPathGroupRef[idx], \
					action->BswMPduRouterDisableInitBuffer);
		}
	} else {/* do nothing */}
	return ret;
}
#endif /* (STD_ON == BSWM_PDUR_ENABLED) */

#if (STD_ON == BSWM_SCHM_ENABLED)
STATIC_INLINE  FUNC(Std_ReturnType, BSWM_CODE) BswM_IRteModeRequest(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
)
{
	Std_ReturnType ret = (Std_ReturnType)E_OK;
	/** @todo not yet realized */
	return ret;
}

STATIC_INLINE  FUNC(Std_ReturnType, BSWM_CODE) BswM_IRteSwitch(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
)
{
	Std_ReturnType ret = (Std_ReturnType)E_OK;
	/** @todo not yet realized */
	return ret;
}
#endif /* (STD_ON == BSWM_SCHM_ENABLED) */

#if (STD_ON == BSWM_SCHM_ENABLED)
STATIC_INLINE  FUNC(Std_ReturnType, BSWM_CODE) BswM_ISchMSwitch(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
)
{
	Std_ReturnType ret = (Std_ReturnType)E_OK;
	/** @todo not yet realized */
	return ret;
}
#endif /* (STD_ON == BSWM_SCHM_ENABLED) */

#if (STD_ON == BSWM_SD_ENABLED)
STATIC_INLINE  FUNC(Std_ReturnType, BSWM_CODE) BswM_ISdClientServiceModeRequest(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
)
{
	Std_ReturnType ret;
	const BswM_SdClientServiceModeRequestType* action = (pAction->pBswMAvailableActions);
	if(action != NULL_PTR)
	{
		ret = Sd_ClientServiceSetState(action->BswMSdClientMethodsRef, action->BswMSdClientServiceState);
	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	return ret;
}

STATIC_INLINE  FUNC(Std_ReturnType, BSWM_CODE) BswM_ISdConsumedEventGroupModeRequest(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
)
{
	Std_ReturnType ret;
	const BswM_SdConsumedEventGroupModeRequestType* action = (pAction->pBswMAvailableActions);
	if(action != NULL_PTR)
	{
		ret = Sd_ConsumedEventGroupSetState(action->BswMSdConsumedEventGroupRef, \
					action->BswMSdConsumedEventGroupState);
	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	return ret;
}

STATIC_INLINE  FUNC(Std_ReturnType, BSWM_CODE) BswM_ISdServerServiceModeRequest(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
)
{
	Std_ReturnType ret;
	const BswM_SdServerServiceModeRequestType* action = (pAction->pBswMAvailableActions);
	if(action != NULL_PTR)
	{
		ret = Sd_ServerServiceSetState(action->BswMSdServerMethodsRef, \
				action->BswMSdServerServiceState);
	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	return ret;
}
#endif /* (STD_ON == BSWM_SD_ENABLED) */

#if (STD_ON == BSWM_GENERIC_REQUEST_ENABLED)
STATIC_INLINE  FUNC(Std_ReturnType, BSWM_CODE) BswM_IUserCallout(
	P2CONST(BswM_ActionType, AUTOMATIC, BSWM_APPL_CONST) pAction
)
{
	Std_ReturnType ret = (Std_ReturnType)E_OK;
	const BswM_UserCalloutType* action = (pAction->pBswMAvailableActions);
	if(NULL_PTR != action)
	{
		action->BswMUserCalloutFunction();
	} else { /* do nothing */ }
	return ret;
}
#endif /* (STD_ON == BSWM_GENERIC_REQUEST_ENABLED) */
/** @} */

/*====================================================================================================*
 *                                          GLOBAL FUNCTIONS
 *====================================================================================================*/

/**
 * @sid       0x00
 * @brief     Initializes the BSW Mode Manager.
 * @param[in] ConfigPtr: Pointer to post-build configuration data
 * @return    None
 * @retval    None
 */
FUNC(void, BSWM_CODE) BswM_Init(
	P2CONST(BswM_ConfigType, AUTOMATIC, BSWM_APPL_CONST) ConfigPtr
)
{
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	if(BSWM_C_ISINITED())
	{
		BSWM_DET_REPORT(BSWM_SID_INIT, BSWM_E_NO_INIT);
	}
	else if(BSWM_C_ISNULL(ConfigPtr))
	{
		BSWM_DET_REPORT(BSWM_SID_INIT, BSWM_E_NULL_POINTER);
	}
	else
	{
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
		const BswM_ModeRequestPortType* pRequestedPort;
		const BswM_RuleType* pRule;
		/* initializtion started */
		uint32 idx ;
		uint32 PortIdidx;
		/* initialize BswM_IRequestedModes */
		pRequestedPort = ConfigPtr->BswMArbitration.pBswMModeRequestPort;
		for(idx = 0U; idx < BSWM_MODE_REQUEST_PORT_COUNT; idx++)
		{
			/**
			 * @req [SWS_BswM_00064] If the container BswMModeInitValue does not exist [or the
			 *      ModeRequest does not already have an initial value, the] BswM shall treat
			 *      the corresponding mode condition as undefined and not use it for mode arbitration
			 *      until the corresponding mode arbitration request has been updated for the first
			 *      time.
			 * @req [SWS_BswM_00203] In case BswMModeInitValue is defined the BswM shall initialize
			 *      the corresponding BswMModeRequestSource with either the BswMBswModeInitValue or
			 *      the BswMCompuScaleModeValue while the BswM is initialized. The BswM shall reject
			 *      configurations which contain both a BswMBswModeInitValue and a
			 *      BswMCompuScaleModeValue for a single BswMModeInitValue. This initialization value
			 *      shall be used for the arbitration rule until the corresponding mode arbitration
			 *      request has been updated e.g. each call of BswM_RequestMode shall update the
			 *      GenericRequest mode.
			 */
			if(NULL_PTR != pRequestedPort[idx].pBswMModeInitValue)
			{
				BswM_IRequestedModes[idx] = pRequestedPort[idx].pBswMModeInitValue->\
																			BswMBswModeInitValue;
			}
			else
			{
				BswM_IRequestedModes[idx] = BSWM_INVALID_MODE; /* equals undefined */
			}
		}
		for(idx = BSWM_MODE_REQUEST_PORT_COUNT; idx < ((uint32)(BSWM_MODE_REQUEST_PORT_COUNT*BSWM_EXPANDED_PORT_MULTIPLE_COUNT)); idx++)
		{
			BswM_IRequestedModes[idx] = BSWM_INVALID_MODE;
		}

		/* initialize BswM_IRuleStates */
		pRule = ConfigPtr->BswMArbitration.pBswMRule;
		for(idx = 0U; idx < BSWM_RULE_COUNT; idx++)
		{
			BswM_IRuleStates[idx] = pRule[idx].BswMRuleInitState;
		}

	    /* Initialize Queues */
		BswM_Init_Queues();
		/* initialization completed */
		pBswM_IConfigPtr = ConfigPtr;
		pBswM_IModeRequestedPorts = pBswM_IConfigPtr->BswMArbitration.pBswMModeRequestPort;
		pBswM_IModeConditions = pBswM_IConfigPtr->BswMArbitration.pBswMModeCondition;
		pBswM_IRules = pBswM_IConfigPtr->BswMArbitration.pBswMRule;
		/* Initialization Condition State */
		for(idx = 0U; idx < BSWM_MODE_CONDITION_COUNT; idx++)
		{
			for(PortIdidx = 0U; PortIdidx < BSWM_MODE_REQUEST_PORT_COUNT; PortIdidx++)
			{
				if(pBswM_IModeConditions[idx].pBswMConditionMode->BswM_ModeRequestedPortId == \
						                         pRequestedPort[PortIdidx].BswM_ModeRequestedPortId)
				{
					if(NULL_PTR != pRequestedPort[PortIdidx].pBswMModeInitValue)
					{
						if(((pBswM_IModeConditions[idx].pBswMConditionValue->pBswMBswMode->\
							BswMBswRequestedMode == pRequestedPort[PortIdidx].pBswMModeInitValue->\
							BswMBswModeInitValue) && (pBswM_IModeConditions[idx].BswMConditionType \
							== BSWM_EQUALS)) || ((pBswM_IModeConditions[idx].pBswMConditionValue->\
							pBswMBswMode->BswMBswRequestedMode != pRequestedPort[PortIdidx].\
							pBswMModeInitValue->BswMBswModeInitValue) && \
							(pBswM_IModeConditions[idx].BswMConditionType == BSWM_EQUALS_NOT)))
						{
							BswM_IConditionStates[idx] = BSWM_TRUE;
						}
						else
						{
							BswM_IConditionStates[idx] = BSWM_FALSE;
						}
					}
					else
					{
						BswM_IConditionStates[idx] = BSWM_UNDEFINED;
					}
					break;
				}else{/* do nothing */}
			}
		}
		/**
		 * @req [SWS_BswM_00224] BswM shall keep internal variables as an accumulative storage
		 * 		of the results of BswMDeadlineMonitoringControl actions. These internal variables
		 * 		shall be initialized to all-zeros when the BswM is initialized. These internal
		 * 		variables shall be used as the parameters when calling the Com_ReceptionDMControl()
		 * 		function.
		 */
#if (STD_ON == BSWM_COM_ENABLED)
		Com_ClearIpduGroupVector(BswM_IComDMIpduGroupVector);
		/**
		 * @req [SWS_BswM_00128] BswM shall keep internal variables as an accumulative storage of the
		 *      results of BswMPduGroupSwitch actions. These internal variables shall be initialized
		 *      to allzeros when the BswM is initialized. These internal variables shall be used as
		 *      the parameters when calling the Com_IpduGroupControl() function.
		 */
		Com_ClearIpduGroupVector(BswM_IComPduGroupSwitchInitVector);
		Com_ClearIpduGroupVector(BswM_IComPduGroupSwitchVector);
#endif
		BswM_IStatus = (boolean)TRUE;
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	}
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
}


STATIC FUNC(void, BSWM_CODE) BswM_Immediate_After(void)
{
	uint32 idx;
	uint32 number;
	boolean stillflag = (boolean)FALSE;
	VAR(BswM_RequesPortType, BSWM_VAR) BswM_IDelayRequestedModesIdx;
	while(BswM_IRequestedModesIdx[IModeRequestQueue.Head].Flag == (boolean)TRUE)
	{
		BswM_IDelayRequestedModesIdx.Idx = BswM_IRequestedModesIdx[IModeRequestQueue.Head].Idx;
		BswM_IDelayRequestedModesIdx.Flag = BswM_IRequestedModesIdx[IModeRequestQueue.Head].Flag;
		for(idx = 0U; idx < BSWM_MODE_CONDITION_COUNT; idx++)
		{
			uint32 id = pBswM_IModeConditions[idx].pBswMConditionMode->BswM_ModeRequestedPortId;

			if(((pBswM_IModeConditions[idx].pBswMConditionMode->BswMRequestProcessing == \
								  BSWM_IMMEDIATE ) && (BswM_IDelayRequestedModesIdx.Flag == \
								 (boolean) TRUE ) && (BswM_IDelayRequestedModesIdx.Idx == \
																					 id )))
			{
				/**
				 * @req [SWS_BswM_00068] BswM shall delay mode arbitration requests received during
				 *      the processing of its main function until it is finished.
				 */
				SchM_Enter_BswM_EXCLUSIVE_AREA_25();
				/* Arbitrate mode condition.*/
				BswM_IConditionStates[idx] = BswM_IArbDeferredModeCondition(\
															 &(pBswM_IModeConditions[idx]));
				for(number = idx + (uint32)1; number < BSWM_MODE_CONDITION_COUNT; number++)
				{
					if(pBswM_IModeConditions[number].pBswMConditionMode->BswM_ModeRequestedPortId == BswM_IDelayRequestedModesIdx.Idx)
					{
						stillflag = (boolean)TRUE;
						break;
					}
				}
				if(stillflag == (boolean)FALSE)
				{
					/* mode arbitration */
					BswM_IDelayArbitrateAllRules(&(pBswM_IModeRequestedPorts[id]));
				}
				SchM_Exit_BswM_EXCLUSIVE_AREA_25();
			}
			stillflag = (boolean)FALSE;
		}
		BswM_Deferred_ProQueues();
	}
}

/**
 * @sid       0x03
 * @brief     Main function of the BswM
 * @param[in] None
 * @return    None
 * @retval    None
 */
FUNC(void, BSWM_CODE) BswM_MainFunction(void)
{
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	/**
	 * @req [SWS_BswM_00076] If the BswMDevErrorDetect switch is enabled, the routine shall check
	 *      if the BSW Mode Manager is initialized. If the BswM-mainfunction is uninitialized called
	 *      from the BSW Scheduler, then it shall return immediately without performing any action and
	 *      without reporting an error
	 */
	if(BSWM_C_ISUNINITED())
	{
		/* @violate [SWS_BswM_00076] Can't tell if it's the SchM scheduling main function ,
		 *           so it always throw an error
		 */
		BSWM_DET_REPORT(BSWM_SID_MAINFUNCTION, BSWM_E_NO_INIT);
	}
	else
	{
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
		uint32 idx;
		uint32 number;
		uint8 DefferCondition = (uint8)0;
		uint32 clearidx;
		boolean findflag = (boolean)FALSE;
		uint32 receiveid;
		uint32 deleateid;
		uint32 i = (uint32)0;
		/* PRQA S 3415  EOF# violate MSIAR2004_12.4: The logical expression is correct. */
		if((BswM_IDelayDefferRequestedIdx[IDelayDefferRequestQueue.Head].Idx != BSWM_INVALID_IDX) && ((Std_ReturnType)E_OK == BswM_IGetArbitrationLock(BSWM_LOCK_TIMEOUT)))
		{
			for(receiveid = (uint32)0;receiveid < ((uint32)(BSWM_MODE_REQUEST_PORT_COUNT *BSWM_EXPANDED_PORT_MULTIPLE_COUNT)); receiveid++)
			{
				BswM_DelayDefferRequested[receiveid].Flag = (boolean)FALSE;
				BswM_DelayDefferRequested[receiveid].Idx = BSWM_INVALID_IDX;
				BswM_DelayDefferRequestedQueue[receiveid] = BSWM_INVALID_MODE;
			}
			for(receiveid = IDelayDefferRequestQueue.Head; receiveid < ((uint32)(BSWM_MODE_REQUEST_PORT_COUNT *BSWM_EXPANDED_PORT_MULTIPLE_COUNT)); receiveid++)
			{
				BswM_DelayDefferRequested[i] = BswM_IDelayDefferRequestedIdx[receiveid];
				BswM_DelayDefferRequestedQueue[i] = BswM_IDelayDefferRequestedQueue[receiveid];
				i++;
			}
			deleateid = (uint32)IDelayDefferRequestQueue.Tail - (uint32)IDelayDefferRequestQueue.Head;
			for(clearidx = (uint32)0; clearidx < deleateid; clearidx++)
			{
				BswM_IDelayDefferRequestedQueue[clearidx] = BSWM_INVALID_MODE;
				BswM_IDelayDefferRequestedIdx[clearidx].Idx = BSWM_INVALID_IDX;
				BswM_IDelayDefferRequestedIdx[clearidx].Flag = (boolean)FALSE;
				(void)BswM_IDefferRequestDequeue();
			}
			i = (uint32)0;
			while((BswM_DelayDefferRequested[i].Idx != BSWM_INVALID_IDX)&&(i < (uint32)(BSWM_MODE_REQUEST_PORT_COUNT * (uint32)BSWM_EXPANDED_PORT_MULTIPLE_COUNT)))
			{
				for(idx = 0U; idx < BSWM_MODE_CONDITION_COUNT; idx++)
				{
					const BswM_ModeRequestPortType * BswM_ModeRequestPort;
					BswM_ModeRequestPort = pBswM_IModeConditions[idx].pBswMConditionMode;
					if(BswM_ModeRequestPort->BswM_ModeRequestedPortId == BswM_DelayDefferRequested[i].Idx)
					{
						if(BswM_ModeRequestPort->BswMRequestProcessing == BSWM_DEFERRED)
						{
							/**
							 * @req [SWS_BswM_00068] BswM shall delay mode arbitration requests received during
							 *      the processing of its main function until it is finished.
							 */
							SchM_Enter_BswM_EXCLUSIVE_AREA_25();
							/* Arbitrate mode condition.*/
							BswM_IConditionStates[idx] = BswM_IArbDeferredDeferredModeCondition(\
																			   &(pBswM_IModeConditions[idx]),i);
							for(number = (uint32)(pBswM_IModeConditions[idx].BswMModeConditionId + (uint32)1); number < (uint32)BSWM_MODE_CONDITION_COUNT; number++)
							{
								const BswM_ModeRequestPortType * ModeRequestPort;
								ModeRequestPort = pBswM_IModeConditions[number].pBswMConditionMode;
								if(ModeRequestPort->BswM_ModeRequestedPortId == BswM_DelayDefferRequested[i].Idx)
								{/* PRQA S 0715  # violate MSIAR2004_1.1: Ignore this warning. */
									findflag = (boolean)TRUE;
									break;
								}
							}
							if(findflag != (boolean)TRUE)
							{
								BswM_DelayDefferRequested[i].Idx = BSWM_INVALID_IDX;
								BswM_DelayDefferRequestedQueue[i] = BSWM_INVALID_MODE;
								i++;
								BswM_IDeferArbitrateAllRules();
							}
							SchM_Exit_BswM_EXCLUSIVE_AREA_25();
						}
						if(findflag != (boolean)TRUE)
						{
							BswM_Deferred_ProQueues();
							break;
						}
					}
					findflag = (boolean)FALSE;
				}
		}
			BswM_Immediate_After();
			BswM_IReleaseArbitrationLock((uint8)E_OK);
		}
		else if((Std_ReturnType)E_OK == BswM_IGetArbitrationLock(BSWM_LOCK_TIMEOUT))
		{
			for(idx = 0U; idx < BSWM_MODE_CONDITION_COUNT; idx++)
			{
				if(pBswM_IModeConditions[idx].pBswMConditionMode->BswMRequestProcessing == BSWM_DEFERRED)
				{
					/**
					 * @req [SWS_BswM_00068] BswM shall delay mode arbitration requests received during
					 *      the processing of its main function until it is finished.
					 */
					SchM_Enter_BswM_EXCLUSIVE_AREA_25();
					DefferCondition = (uint8)1;
					SchM_Exit_BswM_EXCLUSIVE_AREA_25();
					break;
				}else{/*do nothing*/}
			}
			if(DefferCondition == (uint8)1)
			{
				BswM_IDeferArbitrateAllRules();
				BswM_Deferred_ProQueues();
				DefferCondition = (uint8)0;/* PRQA S 2983 # violate MSIAR2004_21.1: It's correct. */
			}
			BswM_Immediate_After();
			BswM_IReleaseArbitrationLock((Std_ReturnType)E_OK);
		}else{/*do nothing*/}
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	}
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
}

#if (STD_ON == BSWM_GENERIC_REQUEST_ENABLED)
/**
 * @sid       0x02
 * @brief     Generic function call to request modes. This function shall only be used by other
 * 			  BSW modules that does not have a specific mode request interface.
 * @param[in] requesting_user: The user that requests the mode
 * @param[in] requested_mode : The requested mode.
 * @return    None
 * @retval    None
 */
FUNC(void, BSWM_CODE) BswM_RequestMode(
	CONST(BswM_UserType, AUTOMATIC) requesting_user,
	CONST(BswM_ModeType, AUTOMATIC) requested_mode
)
{
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	/**
	 * @req [SWS_BswM_00077] If the BswMDevErrorDetect switch is enabled, the routine shall check
	 *      if the BSW Mode Manager is initialized. In case of an error, the BswM shall ignore the
	 *      mode request and report the error to the Default Error Tracer with the error code
	 *      BSWM_E_NO_INIT.
	 */
	if(BSWM_C_ISUNINITED())
	{
		BSWM_DET_REPORT(BSWM_SID_REQUESTMODE, BSWM_E_NO_INIT);
	}
	else
	{
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
		uint32 idx;
		const BswM_GenericRequestType* requestSource;
		for(idx = 0U; idx < BSWM_MODE_REQUEST_PORT_COUNT; idx++)
		{
			if(pBswM_IModeRequestedPorts[idx].BswMModeRequestSourceType == BSWM_GENERIC_REQUEST)
			{
				requestSource = (pBswM_IModeRequestedPorts[idx].pBswMModeRequestSource);
				/* find mode request port*/
				if(requestSource->BswMModeRequesterId == requesting_user)
				{
				#if (STD_ON == BSWM_DEV_ERROR_DETECT)
					/**
					 * @req [SWS_BswM_00089] If the BswMDevErrorDetect switch is enabled, the
					 *      parameter requested_mode shall be checked for being in the allowed range.
					 *      In case of an error, the BswM shall ignore the mode request and report the
					 *      error to the Default Error Tracer with the value
					 *      BSWM_E_REQ_MODE_OUT_OF_RANGE.
					 */
					if(requestSource->BswMRequestedModeMax < requested_mode)
					{
						BSWM_DET_REPORT(BSWM_SID_REQUESTMODE, BSWM_E_REQ_MODE_OUT_OF_RANGE);
					}
					else
				#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */

					if((pBswM_IModeRequestedPorts[idx].BswMRequestProcessing == \
							                   (BswM_RequestProcessingType)BSWM_IMMEDIATE) && \
								((Std_ReturnType)E_OK == BswM_IGetArbitrationLock(BSWM_LOCK_TIMEOUT)))
					{
						SchM_Enter_BswM_EXCLUSIVE_AREA_01();
						BswM_IRequestedModes[idx] = (BswM_ModeType)requested_mode;
						/* mode arbitration */
						BswM_IImmediateArbitrateAllRules(&(pBswM_IModeRequestedPorts[idx]));
						SchM_Exit_BswM_EXCLUSIVE_AREA_01();
						BswM_Immediate_ProQueues();
						BswM_Immediate_After();
						BswM_IReleaseArbitrationLock((uint8)E_OK);
					}
					else /* deferred to main function*/
					{
						(void)BswM_IModeRequestEnqueue((BswM_ModeType)requested_mode , idx);
					}
					/* Unique ports in the system */
					break;
				} else {/* do nothing */}
			} else {/* do nothing */}
		}
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
		/**
		 * @req [SWS_BswM_00090] If the BswMDevErrorDetect switch is enabled, the parameter
		 *      requesting_user shall be checked for being in the allowed range. In case of
		 *      an error, the BswM shall ignore the mode request and report the error to the
		 *      Default Error Tracer with the value BSWM_E_REQ_USER_OUT_OF_RANGE.
		 */
		if(requesting_user >= BSWM_MODE_REQUEST_PORT_COUNT)
		{
			BSWM_DET_REPORT(BSWM_SID_REQUESTMODE, BSWM_E_REQ_USER_OUT_OF_RANGE);
		} else {/* do nothing */}
	}
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
}
#endif /* (STD_ON == BSWM_GENERIC_REQUEST_ENABLED) */

#if (STD_ON == BSWM_VERSION_INFO_API)
/**
 * @sid        0x01
 * @brief      Returns the version information of this module.
 * @param[in]  None
 * @param[out] VersionInfo: Pointer to where to store the version information of the module.
 * @return     None
 * @retval     None
 */
FUNC(void, BSWM_CODE) BswM_GetVersionInfo(
	P2VAR(Std_VersionInfoType, AUTOMATIC, BSWM_APPL_DATA) VersionInfo
)
{
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	if(VersionInfo == NULL_PTR)
	{
		BSWM_DET_REPORT(BSWM_SID_GETVERSIONINFO, BSWM_E_NULL_POINTER);
	}
	else
	{
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
		VersionInfo->moduleID = BSWM_MODULE_ID;
		VersionInfo->vendorID = BSWM_VENDOR_ID;
		VersionInfo->sw_major_version = BSWM_SW_MAJOR_VERSION;
		VersionInfo->sw_minor_version = BSWM_SW_MINOR_VERSION;
		VersionInfo->sw_patch_version = BSWM_SW_PATCH_VERSION;
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	}
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
}
#endif /* STD_ON == BSWM_VERSION_INFO_API */

/**
 * @sid        0x04
 * @brief      Deinitializes the BSW Mode Manager.
 * @param[in]  None
 * @return     None
 * @retval     None
 */
FUNC(void, BSWM_CODE) BswM_Deinit(
	void
)
{
	/**
	 * @req [SWS_BswM_00120] After a call of BswM_Deinit no mode processing shall be performed by
	 *      BswM even if any mode requests are made or the BswM main function is called.
	 */
	BswM_IStatus = (boolean)FALSE;
	BswM_IArbitrationLock = 0u;
}

#if (STD_ON == BSWM_WDGM_ENABLED)
/**
 * @sid       0x11
 * @brief     Function called by WdgM to request a partition reset.
 * @param[in] Application: The identifier of an OS-Application
 * @return    None
 * @retval    None
 */
FUNC(void, BSWM_CODE) BswM_WdgM_RequestPartitionReset(
	VAR(ApplicationType, AUTOMATIC) Application
)
{
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	/**
	 * @req [SWS_BswM_00134] If the BswMDevErrorDetect switch is enabled, the routine shall check
	 *      if the BSW Mode Manager is initialized. In case of an error, the BswM shall ignore the
	 *      mode request and report the error to the Default Error Tracer with the error code
	 *      BSWM_E_NO_INIT.
	 */
	if(BSWM_C_ISUNINITED())
	{
		BSWM_DET_REPORT(BSWM_SID_WDGM_REQUESTEDPARTITIONRESET, BSWM_E_NO_INIT);
	}
	else
	{
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
		/**
		 * @todo Finds the corresponding port according to Application and performs mode
		 *       arbitration ,but since partitioning is not implemented ,this function is
		 *       not implemented for now
		 */
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	}
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
}
#endif

#if (STD_ON == BSWM_LINTP_ENABLED)
/**
 * @sid       0x0b
 * @brief     Function called by LinTP to request a mode for the corresponding LIN channel.
 * 		      The LinTp_Mode correlates to the LIN schedule table that should be used.
 * @param[in] Network:             The LIN channel that the LinTp mode request relates to.
 * @param[in] LinTpRequestedMode:  The requested LIN TP mode.
 * @return    None
 * @retval    None
 */
FUNC(void, BSWM_CODE) BswM_LinTp_RequestMode(
	VAR(NetworkHandleType, AUTOMATIC) Network,
	VAR(LinTp_Mode, AUTOMATIC) LinTpRequestedMode
)
{
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	/**
	 * @req [SWS_BswM_00112] If the BswMDevErrorDetect switch is enabled, the routine shall check
	 *      if the BSW Mode Manager is initialized. In case of an error, the BswM shall ignore the
	 *      mode request and report the error to the Default Error Tracer with the error code
	 *      BSWM_E_NO_INIT.
	 */
	if(BSWM_C_ISUNINITED())
	{
		BSWM_DET_REPORT(BSWM_SID_LINTP_REQUESTEDMODE, BSWM_E_NO_INIT);
	}
	/**
	 * @req [SWS_BswM_00113] If the BswMDevErrorDetect switch is enabled, the parameter
	 *      LinTpRequestedMode shall be checked for being in the allowed range. In case of
	 *      an error the BswM shall ignore the mode request and report the error, to the Default
	 *      Error Tracer with the value BSWM_E_REQ_MODE_OUT_OF_RANGE.
	 */
	else if(LinTpRequestedMode > LINTP_DIAG_RESPONSE)
	{
		BSWM_DET_REPORT(BSWM_SID_LINTP_REQUESTEDMODE, BSWM_E_REQ_MODE_OUT_OF_RANGE);
	}
	else
	{
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
		uint32 idx;
		const BswM_LinTpModeRequestType* requestSource;
		/*Iterate over all requested ports*/
		for(idx = 0U; idx < BSWM_MODE_REQUEST_PORT_COUNT; idx++)
		{
			/*Determines if the type of of schema request source is a request for the specified module*/
			if(pBswM_IModeRequestedPorts[idx].BswMModeRequestSourceType == BSWM_LINTP_MODE_REQUEST)
			{
				/*Store the schema request source in the set struct pointer variable*/
				requestSource = (pBswM_IModeRequestedPorts[idx].pBswMModeRequestSource);
				/* Finding the port */
				/* Determination by request entry and configuration */
				if(requestSource->BswMLinTpChannelRef == Network)
				{
					/*Determine if the arbitration request port is an immediate arbition port*/
					if((pBswM_IModeRequestedPorts[idx].BswMRequestProcessing == \
							                         (BswM_RequestProcessingType)BSWM_IMMEDIATE) && \
                                 		((Std_ReturnType)E_OK == BswM_IGetArbitrationLock(BSWM_LOCK_TIMEOUT)))
					{
						SchM_Enter_BswM_EXCLUSIVE_AREA_02();
						BswM_IRequestedModes[idx] = (BswM_ModeType)LinTpRequestedMode;
						/* mode arbitration */
						BswM_IImmediateArbitrateAllRules(&(pBswM_IModeRequestedPorts[idx]));
						SchM_Exit_BswM_EXCLUSIVE_AREA_02();
						BswM_Immediate_ProQueues();
						BswM_Immediate_After();
						BswM_IReleaseArbitrationLock((uint8)E_OK);
					}
					else
					{
						(void)BswM_IModeRequestEnqueue((BswM_ModeType)LinTpRequestedMode , idx);
					}
					/* Unique ports in the system */
					break;
				} else {/* do nothing */}
			} else {/* do nothing */}
		}
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	}
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
}
#endif /* (STD_ON == BSWM_LINTP_ENABLED) */

#if (STD_ON == BSWM_SCHM_ENABLED)
/**
 * @sid       0x01
 * @brief     Function called by Restart Task if the partition containing the BswM has been restarted.
 * @param[in] None
 * @return    None
 * @retval    None
 */
FUNC(void, BSWM_CODE) BswM_BswMPartitionRestarted(
	void
)
{
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	if(BSWM_C_ISUNINITED())
	{
		BSWM_DET_REPORT(BSWM_SID_BSWMPARTITIONRESTARTED, BSWM_E_NO_INIT);
	}
	else
	{
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
		uint32 idx;
		for(idx = 0U; idx < BSWM_MODE_REQUEST_PORT_COUNT; idx++)
		{
			/**
			 * @req [SWS_BswM_00035] The BswM shall perform mode arbitration based on incoming
			 *      mode indications.
			 */
			if(pBswM_IModeRequestedPorts[idx].BswMModeRequestSourceType == BSWM_PARTITION_RESTARTED)
			{
				/* Finding the port */
				if((pBswM_IModeRequestedPorts[idx].BswMRequestProcessing == BSWM_IMMEDIATE) && \
						          ((Std_ReturnType)E_OK == BswM_IGetArbitrationLock(BSWM_LOCK_TIMEOUT)))
				{
					SchM_Enter_BswM_EXCLUSIVE_AREA_03();
					/* @todo Set the mode to 1 when the interface is called and change it subsequently */
					BswM_IRequestedModes[idx] = (BswM_ModeType) TRUE;
					/* mode arbitration */
					BswM_IImmediateArbitrateAllRules(&(pBswM_IModeRequestedPorts[idx]));
					SchM_Exit_BswM_EXCLUSIVE_AREA_03();
					BswM_Immediate_ProQueues();
					BswM_Immediate_After();
					BswM_IReleaseArbitrationLock((uint8)E_OK);
				}
				else
				{
					(void)BswM_IModeRequestEnqueue((BswM_ModeType)TRUE , idx);
				}
				/* Unique ports in the system */
				break;
			} else {/* do nothing */}
		}
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	}
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
}
#endif /* (STD_ON == BSWM_SCHM_ENABLED) */

#if (STD_ON == BSWM_CANSM_ICOM_ENABLED)
/**
 * @sid   0x1a
 * @brief Function to inform BswM about the switch of Icom Configuration.
 * @param[in] Network: The CAN channel the requested state corresponds to.
 * @param[in] ActiveConfiguration: The configuration Id of the Icom configuration.
 * @param[in] Error :   ICOM_SWITCH_E_OK: No Error
 *                      ICOM_SWITCH_E_FAILED: Switch to requested Configuration failed. Severe Error.
 * @return None
 * @retval None
 */
FUNC(void, BSWM_CODE) BswM_CanSM_CurrentIcomConfiguration(
	VAR(NetworkHandleType, AUTOMATIC) Network,
	VAR(IcomConfigIdType, AUTOMATIC) ActiveConfiguration,
	VAR(IcomSwitch_ErrorType, AUTOMATIC) Error
)
{
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	if(BSWM_C_ISUNINITED())
	{
		BSWM_DET_REPORT(BSWM_SID_CANSM_CURRENTICOMCONFIGURATION, BSWM_E_NO_INIT);
	}
	else
	{
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
		uint32 idx;
		const BswM_CanSMIcomIndicationType* requestSource;
		for(idx = 0U; idx < BSWM_MODE_REQUEST_PORT_COUNT; idx++)
		{
			if(pBswM_IModeRequestedPorts[idx].BswMModeRequestSourceType == BSWM_CANSM_ICOM_INDICATION)
			{
				requestSource = (pBswM_IModeRequestedPorts[idx].pBswMModeRequestSource);
				/**
				 * @req [SWS_BswM_00166] The interface BswM_CanSM_CurrentIcomConfiguration shall be
				 *      used by the CanSM to inform the BswM about the activation of a new ICOM
				 *      configuration for a given channel. The BswM shall match the Network and Error
				 *      parameters to a configured BswMCanSMIcomIndication and utilize the
				 *      ActiveConfiguration parameter as the value that gets evaluated in the
				 *      arbitration rules.
				 */
				if((requestSource->BswMCanSMChannelRef == Network)
				&& (requestSource->BswMCanSMIcomIndicationSwitchError == (boolean) Error))
				{
					if((pBswM_IModeRequestedPorts[idx].BswMRequestProcessing == BSWM_IMMEDIATE) && \
                                 ((Std_ReturnType)E_OK == BswM_IGetArbitrationLock(BSWM_LOCK_TIMEOUT)))
					{
						SchM_Enter_BswM_EXCLUSIVE_AREA_04();
						BswM_IRequestedModes[idx] = (BswM_ModeType) ActiveConfiguration;
						/* mode arbitration */
						BswM_IImmediateArbitrateAllRules(&(pBswM_IModeRequestedPorts[idx]));
						SchM_Exit_BswM_EXCLUSIVE_AREA_04();
						BswM_Immediate_ProQueues();
						BswM_Immediate_After();
						BswM_IReleaseArbitrationLock((uint8)E_OK);
					}
					else
					{
						(void)BswM_IModeRequestEnqueue((BswM_ModeType)ActiveConfiguration , idx);
					}
					/* Unique ports in the system */
					break;
				} else {/* do nothing */}
			} else {/* do nothing */}
		}
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	}
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
}
#endif /* (STD_ON == BSWM_CANSM_ICOM_ENABLED) */

#if (STD_ON == BSWM_CANSM_ENABLED)
/**
 * @sid       0x05
 * @brief     Function called by CanSM to indicate its current state.
 * @param[in] Network: The CAN channel that the indicated state corresponds to.
 * @param[in] CurrentState: The current state of the CAN channel.
 * @return    None
 * @retval    None
 */
FUNC(void, BSWM_CODE) BswM_CanSM_CurrentState(
	VAR(NetworkHandleType, AUTOMATIC) Network,
	VAR(CanSM_BswMCurrentStateType, AUTOMATIC) CurrentState
)
{
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	/**
	 * @req [SWS_BswM_00080] If the BswMDevErrorDetect switch is enabled, the routine shall check
	 *      if the BSW Mode Manager is initialized. In case of an error, the BswM shall ignore the
	 *      state indication and report the error to the Default Error Tracer with the error code
	 *      BSWM_E_NO_INIT.
	 */
	if(BSWM_C_ISUNINITED())
	{
		BSWM_DET_REPORT(BSWM_SID_CANSM_CURRENTSTATE, BSWM_E_NO_INIT);
	}
	/**
	 * @req [SWS_BswM_0095] If the BswMDevErrorDetect switch is enabled, the parameter CurrentState
	 *      shall be checked for being in the allowed range. In case of an error, the BswM shall
	 *      ignore the state indication and report the error to the Default Error Tracer with the
	 *      value BSWM_E_REQ_MODE_OUT_OF_RANGE.
	 */
	else if(CurrentState > CANSM_BSWM_CHANGE_BAUDRATE)
	{
		BSWM_DET_REPORT(BSWM_SID_CANSM_CURRENTSTATE, BSWM_E_REQ_MODE_OUT_OF_RANGE);
	}
	else
	{
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
		uint32 idx;
		const BswM_CanSMIndicationType* requestSource;
		for(idx = 0U; idx < BSWM_MODE_REQUEST_PORT_COUNT; idx++)
		{
			if(pBswM_IModeRequestedPorts[idx].BswMModeRequestSourceType == BSWM_CANSM_INDICATION)
			{
				requestSource = (pBswM_IModeRequestedPorts[idx].pBswMModeRequestSource);
				if(requestSource->BswMCanSMChannelRef == Network)
				{
					if((pBswM_IModeRequestedPorts[idx].BswMRequestProcessing == BSWM_IMMEDIATE) && \
                                 ((Std_ReturnType)E_OK == BswM_IGetArbitrationLock(BSWM_LOCK_TIMEOUT)))
					{
						SchM_Enter_BswM_EXCLUSIVE_AREA_05();
						BswM_IRequestedModes[idx] = (BswM_ModeType) CurrentState;
						/* mode arbitration */
						BswM_IImmediateArbitrateAllRules(&(pBswM_IModeRequestedPorts[idx]));
						SchM_Exit_BswM_EXCLUSIVE_AREA_05();
						BswM_Immediate_ProQueues();
						BswM_Immediate_After();
						BswM_IReleaseArbitrationLock((uint8)E_OK);
					}
					else
					{
						(void)BswM_IModeRequestEnqueue((BswM_ModeType)CurrentState , idx);
					}
					/* Unique ports in the system */
					break;
				} else {/* do nothing */}
			} else {/* do nothing */}
		}
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	}
#endif
}
#endif /* (STD_ON == BSWM_CANSM_ENABLED) */

#if (BSWM_COMM_ENABLED == STD_ON)
/**
 * @sid       0x0e
 * @brief     Function called by ComM to indicate the current communication mode of a ComM channel.
 * @param[in] Network:The ComM communication channel that the indicated state corresponds to.
 * @param[in] RequestedMode: The current state of the ComM communication channel.
 * @return    None
 * @retval    None
 */
FUNC(void, BSWM_CODE) BswM_ComM_CurrentMode(
	VAR(NetworkHandleType, AUTOMATIC) Network,
	VAR(ComM_ModeType, AUTOMATIC) RequestedMode
)
{
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	/**
	 * @req [SWS_BswM_00078] If the BswMDevErrorDetect switch is enabled, the routine shall check
	 *      if the BSW Mode Manager is initialized. In case of an error, the BswM shall ignore the
	 *      mode request and report the error to the Default Error Tracer with the error code
	 *      BSWM_E_NO_INIT.
	 */
	if(BSWM_C_ISUNINITED())
	{
		BSWM_DET_REPORT(BSWM_SID_COMM_CURRENTMODE, BSWM_E_NO_INIT);
	}
	/**
	 * @req [SWS_BswM_00091] If the BswMDevErrorDetect switch is enabled, the parameter RequestedMode
	 *      shall be checked for being in the allowed range. In case of an error, the BswM shall
	 *      ignore the mode request and report the error to the Default Error Tracer with the value
	 *      BSWM_E_REQ_MODE_OUT_OF_RANGE.
	 */
	else if(RequestedMode > COMM_FULL_COMMUNICATION)
	{
		BSWM_DET_REPORT(BSWM_SID_COMM_CURRENTMODE, BSWM_E_REQ_MODE_OUT_OF_RANGE);
	}
	else
	{
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
		uint32 idx;
		const BswM_ComMIndicationType* requestSource;
		for(idx = 0U; idx < BSWM_MODE_REQUEST_PORT_COUNT; idx++)
		{
			if(pBswM_IModeRequestedPorts[idx].BswMModeRequestSourceType == BSWM_COMM_INDICATION)
			{
				requestSource = (pBswM_IModeRequestedPorts[idx].pBswMModeRequestSource);
				if(requestSource->BswMComMChannelRef == Network)
				{
					if((pBswM_IModeRequestedPorts[idx].BswMRequestProcessing == BSWM_IMMEDIATE) && \
                                 ((Std_ReturnType)E_OK == BswM_IGetArbitrationLock(BSWM_LOCK_TIMEOUT)))
					{
						SchM_Enter_BswM_EXCLUSIVE_AREA_06();
						BswM_IRequestedModes[idx] = (BswM_ModeType) RequestedMode;
						/* mode arbitration */
						BswM_IImmediateArbitrateAllRules(&(pBswM_IModeRequestedPorts[idx]));
						SchM_Exit_BswM_EXCLUSIVE_AREA_06();
						BswM_Immediate_ProQueues();
						BswM_Immediate_After();
						BswM_IReleaseArbitrationLock((uint8)E_OK);
					}
					else
					{
						(void)BswM_IModeRequestEnqueue((BswM_ModeType)RequestedMode , idx);
					}
					/* Unique ports in the system */
					break;
				} else {/* do nothing */}
			} else {/* do nothing */}
		}
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	}
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
}
#endif /* (BSWM_COMM_ENABLED == STD_ON) */

#if (BSWM_COMM_ENABLED == STD_ON)
/**
 * @sid       0x15
 * @brief     Function called by ComM to indicate the current mode of the PNC.
 * @param[in] PNC: The handle of the PNC for which the current state is reported.
 * @param[in] CurrentPncMode: The current mode of the PNC.
 * @return    None
 * @retval    None
 */
FUNC(void, BSWM_CODE) BswM_ComM_CurrentPNCMode(
	VAR(PNCHandleType, AUTOMATIC) PNC,
	VAR(ComM_PncModeType, AUTOMATIC) CurrentPncMode
)
{
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	/**
	 * @req [SWS_BswM_00149] If the BswMDevErrorDetect switch is enabled, the routine shall check if
	 *      the BSW Mode Manager is initialized. In case of an error, the BswM shall ignore the mode
	 *      request and report the error to the Default Error Tracer with the error code BSWM_E_NO_INIT.
	 */
	if(BSWM_C_ISUNINITED())
	{
		BSWM_DET_REPORT(BSWM_SID_COMM_CURRENTPNCMODE, BSWM_E_NO_INIT);
	}
	/**
	 * @req [SWS_BswM_00150] If the BswMDevErrorDetect switch is enabled, the parameter CurrentPncMode
	 *      shall be checked for being in the allowed range. In case of an error, the BswM shall ignore
	 *      the mode request and report the error to the Default Error Tracer with the value
	 *      BSWM_E_REQ_MODE_OUT_OF_RANGE.
	 */
	else if(CurrentPncMode > (ComM_PncModeType)COMM_PNC_NO_COMMUNICATION)
	{
		BSWM_DET_REPORT(BSWM_SID_COMM_CURRENTPNCMODE, BSWM_E_REQ_MODE_OUT_OF_RANGE);
	}
	else
	{
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
		uint32 idx;
		const BswM_ComMPncRequestType* requestSource;
		for(idx = 0U; idx < BSWM_MODE_REQUEST_PORT_COUNT; idx++)
		{
			if(pBswM_IModeRequestedPorts[idx].BswMModeRequestSourceType == BSWM_COMM_PNC_REQUEST)
			{
				requestSource = (pBswM_IModeRequestedPorts[idx].pBswMModeRequestSource);
				if(requestSource->BswMComMPncRef == (ComM_PncModeType)PNC)
				{
					if((pBswM_IModeRequestedPorts[idx].BswMRequestProcessing == BSWM_IMMEDIATE) && \
							  ((Std_ReturnType)E_OK == BswM_IGetArbitrationLock(BSWM_LOCK_TIMEOUT)))
					{
						SchM_Enter_BswM_EXCLUSIVE_AREA_07();
						BswM_IRequestedModes[idx] = (BswM_ModeType) CurrentPncMode;
						/* mode arbitration */
						BswM_IImmediateArbitrateAllRules(&(pBswM_IModeRequestedPorts[idx]));
						SchM_Exit_BswM_EXCLUSIVE_AREA_07();
						BswM_Immediate_ProQueues();
						BswM_Immediate_After();
						BswM_IReleaseArbitrationLock((uint8)E_OK);
					}
					else
					{
						(void)BswM_IModeRequestEnqueue((BswM_ModeType)CurrentPncMode , idx);
					}
					/* Unique ports in the system */
					break;
				} else {/* do nothing */}
			} else {/* do nothing */}
		}
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	}
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
}
#endif /* (BSWM_COMM_ENABLED == STD_ON) */

#if (BSWM_COMM_ENABLED == STD_ON)
/**
 * @sid       0x22
 * @brief     Function called by ComM to signal a shutdown.
 * @param[in] None
 * @return    None
 * @retval    None
 */
FUNC(void, BSWM_CODE) BswM_ComM_InitiateReset(
	void
)
{
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	if(BSWM_C_ISUNINITED())
	{
		BSWM_DET_REPORT(BSWM_SID_COMM_INITIATERESET, BSWM_E_NO_INIT);
	}
	else
	{
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
		uint32 idx;
		for(idx = 0U; idx < BSWM_MODE_REQUEST_PORT_COUNT; idx++)
		{
			if(pBswM_IModeRequestedPorts[idx].BswMModeRequestSourceType == BSWM_COMM_INITIATE_RESET)
			{
				if((pBswM_IModeRequestedPorts[idx].BswMRequestProcessing == \
						                     (BswM_RequestProcessingType)BSWM_IMMEDIATE) && \
                               ((Std_ReturnType)E_OK == BswM_IGetArbitrationLock(BSWM_LOCK_TIMEOUT)))
				{
					SchM_Enter_BswM_EXCLUSIVE_AREA_07();
					/* @todo Set the mode to 1 when the interface is called and change it subsequently  */
					BswM_IRequestedModes[idx] = (BswM_ModeType) TRUE;
					/* mode arbitration */
					BswM_IImmediateArbitrateAllRules(&(pBswM_IModeRequestedPorts[idx]));
					SchM_Exit_BswM_EXCLUSIVE_AREA_07();
					BswM_Immediate_ProQueues();
					BswM_Immediate_After();
					BswM_IReleaseArbitrationLock((uint8)E_OK);
				}
				else
				{
					(void)BswM_IModeRequestEnqueue((BswM_ModeType)TRUE , idx);
				}
				/* Unique ports in the system */
				break;
			} else {/* do nothing */}
		}
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	}
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
}
#endif /* (BSWM_COMM_ENABLED == STD_ON) */

#if (STD_ON == BSWM_DCM_ENABLED)
/**
 * @sid       0x14
 * @brief     This function is called by the DCM in order to report an updated application.
 * @param[in] None
 * @return    None
 * @retval    None
 */
FUNC(void, BSWM_CODE) BswM_Dcm_ApplicationUpdated(
	void
)
{
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	/**
	 * @req [SWS_BswM_00159] If the BswMDevErrorDetect switch is enabled, the routine shall check if
	 *      the BSW Mode Manager is initialized. In case of an error, the BswM shall ignore the mode
	 *      request and report the error to the Default Error Tracer with the error code BSWM_E_NO_INIT.
	 */
	if(BSWM_C_ISUNINITED())
	{
		BSWM_DET_REPORT(BSWM_SID_DCM_APPLICATIONUPDATED, BSWM_E_NO_INIT);
	}
	else
	{
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
		uint32 idx;
		for(idx = 0U; idx < BSWM_MODE_REQUEST_PORT_COUNT; idx++)
		{
			if( pBswM_IModeRequestedPorts[idx].BswMModeRequestSourceType == \
					                                          BSWM_DCM_APPLICATION_UPDATED_INDICATION )
			{
				if((pBswM_IModeRequestedPorts[idx].BswMRequestProcessing == \
						                             (BswM_RequestProcessingType)BSWM_IMMEDIATE) && \
                                 ((Std_ReturnType)E_OK == BswM_IGetArbitrationLock(BSWM_LOCK_TIMEOUT)))
				{
					SchM_Enter_BswM_EXCLUSIVE_AREA_08();
					/* @todo Set the mode to 1 when the interface is called and change it subsequently  */
					BswM_IRequestedModes[idx] = (BswM_ModeType) TRUE;
					/* mode arbitration */
					BswM_IImmediateArbitrateAllRules(&(pBswM_IModeRequestedPorts[idx]));
					SchM_Exit_BswM_EXCLUSIVE_AREA_08();
					BswM_Immediate_ProQueues();
					BswM_Immediate_After();
					BswM_IReleaseArbitrationLock((uint8)E_OK);
				}
				else
				{
					(void)BswM_IModeRequestEnqueue((BswM_ModeType)TRUE , idx);
				}
				/* Unique ports in the system */
				break;
			} else {/* do nothing */}
		}
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	}
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
}
#endif /* (STD_ON == BSWM_DCM_ENABLED) */

#if (STD_ON == BSWM_DCM_ENABLED)
/**
 * @sid       0x06
 * @brief     Function called by DCM to inform the BswM about the current state of the communication mode.
 * @param[in] Network: The communication channel that the diagnostic mode corresponds to.
 * @param[in] RequestedMode: The requested diagnostic communication mode.
 * @return    None
 * @retval    None
 */
#if(STD_ON == DCM_UDS0x28_ENABLE)
FUNC(void, BSWM_CODE) BswM_Dcm_CommunicationMode_CurrentState(
	VAR(NetworkHandleType, AUTOMATIC) Network,
	VAR(Dcm_CommunicationModeType, AUTOMATIC) RequestedMode
)
{
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	/**
	 * @req [SWS_BswM_00079] If the BswMDevErrorDetect switch is enabled, the routine shall check if
	 *      the BSW Mode Manager is initialized. In case of an error, the BswM shall ignore the mode
	 *      request and report the error to the Default Error Tracer with the error code BSWM_E_NO_INIT.
	 */
	if(BSWM_C_ISUNINITED())
	{
		BSWM_DET_REPORT(BSWM_SID_DCM_COMMUNICATIONMODE_CURRENTSTATE, BSWM_E_NO_INIT);
	}
	/**
	 * @req [SWS_BswM_00093] If the BswMDevErrorDetect switch is enabled, the parameter RequestedMode
	 *      shall be checked for being in the allowed range. In case of an error, the BswM shall ignore
	 *      the mode request and report the error to the Default Error Tracer with the value
	 *      BSWM_E_REQ_MODE_OUT_OF_RANGE.
	 */
	else if(RequestedMode > (uint8)DCM_DISABLE_RX_TX_NORM_NM)
	{
		BSWM_DET_REPORT(BSWM_SID_DCM_COMMUNICATIONMODE_CURRENTSTATE, BSWM_E_REQ_MODE_OUT_OF_RANGE);
	}
	else
	{
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
		uint32 idx;
		const BswM_DcmComModeRequestType* requestSource;
		for(idx = 0U; idx < BSWM_MODE_REQUEST_PORT_COUNT; idx++)
		{
			if(pBswM_IModeRequestedPorts[idx].BswMModeRequestSourceType == BSWM_DCM_COM_MODE_REQUEST)
			{
				requestSource = (pBswM_IModeRequestedPorts[idx].pBswMModeRequestSource);
				if(requestSource->BswMDcmComMChannelRef == Network)
				{
					if((pBswM_IModeRequestedPorts[idx].BswMRequestProcessing == \
							                               (BswM_RequestProcessingType)BSWM_IMMEDIATE) && \
                                 ((Std_ReturnType)E_OK == BswM_IGetArbitrationLock(BSWM_LOCK_TIMEOUT)))
					{
						SchM_Enter_BswM_EXCLUSIVE_AREA_09();
						BswM_IRequestedModes[idx] = (BswM_ModeType) RequestedMode;
						/* mode arbitration */
						BswM_IImmediateArbitrateAllRules(&(pBswM_IModeRequestedPorts[idx]));
						SchM_Exit_BswM_EXCLUSIVE_AREA_09();
						BswM_Immediate_ProQueues();
						BswM_IReleaseArbitrationLock((uint8)E_OK);
					}
					else
					{
						(void)BswM_IModeRequestEnqueue((BswM_ModeType)RequestedMode , idx);
					}
					/* Unique ports in the system */
					break;
				} else {/* do nothing */}
			} else {/* do nothing */}
		}
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	}
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
}
#endif/* (STD_ON == DCM_UDS0x28_ENABLE) */
#endif /* (STD_ON == BSWM_DCM_ENABLED) */

#if (STD_ON == BSWM_ECUM_ENABLED)
/**
 * @sid       0x0f
 * @brief     Function called by EcuM to indicate the current ECU Operation Mode.
 * @param[in] CurrentState: The requested ECU Operation Mode
 * @return    None
 * @retval    None
 */
FUNC(void, BSWM_CODE) BswM_EcuM_CurrentState(
	VAR(EcuM_StateType, AUTOMATIC) CurrentState
)
{
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	/**
	 * @req [SWS_BswM_00084] If the BswMDevErrorDetect switch is enabled, the routine shall check if
	 *      the BSW Mode Manager is initialized. In case of an error, the BswM shall ignore the mode
	 *      request and report the error to the Default Error Tracer with the error code BSWM_E_NO_INIT.
	 */
	if(BSWM_C_ISUNINITED())
	{
		BSWM_DET_REPORT(BSWM_SID_ECUM_CURRENTSTATE, BSWM_E_NO_INIT);
	}
	/**
	 * @req [SWS_BswM_00103] If the BswMDevErrorDetect switch is enabled, the parameter CurrentState
	 *      shall be checked for being in the allowed range. In case of an error, the BswM shall ignore
	 *      the mode request and report the error to the Default Error Tracer with the value
	 *      BSWM_E_REQ_MODE_OUT_OF_RANGE.
	 */
	else if(BSWM_C_ECUMSTATE_ISINVALID(CurrentState))/* PRQA S 3344  # violate MSIAR2004_13.2: Ignore the type conversion here for now. */
	{
		BSWM_DET_REPORT(BSWM_SID_ECUM_CURRENTSTATE, BSWM_E_REQ_MODE_OUT_OF_RANGE);
	}
	else
	{
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
		uint32 idx;
		for(idx = 0U; idx < BSWM_MODE_REQUEST_PORT_COUNT; idx++)
		{
			if(pBswM_IModeRequestedPorts[idx].BswMModeRequestSourceType == BSWM_ECUM_INDICATION)
			{
				if((pBswM_IModeRequestedPorts[idx].BswMRequestProcessing == \
						                         (BswM_RequestProcessingType)BSWM_IMMEDIATE) && \
                                  ((Std_ReturnType)E_OK == BswM_IGetArbitrationLock(BSWM_LOCK_TIMEOUT)))
				{
					SchM_Enter_BswM_EXCLUSIVE_AREA_10();
					BswM_IRequestedModes[idx] = (BswM_ModeType) CurrentState;
					/* mode arbitration */
					BswM_IImmediateArbitrateAllRules(&(pBswM_IModeRequestedPorts[idx]));
					SchM_Exit_BswM_EXCLUSIVE_AREA_10();
					BswM_Immediate_ProQueues();
					BswM_Immediate_After();
					BswM_IReleaseArbitrationLock((uint8)E_OK);
				}
				else
				{
					(void)BswM_IModeRequestEnqueue((BswM_ModeType)CurrentState , idx);
				}
				/* Unique ports in the system */
				break;
			} else { /* do nothing */ }
		}
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	}
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
}
#endif /* (STD_ON == BSWM_ECUM_ENABLED) */

#if (STD_ON == BSWM_ECUM_ENABLED)
/**
 * @sid       0x10
 * @brief     Function called by EcuM to indicate the current state of a wakeup source
 * @param[in] source: Wakeup source(s) that changed state
 * @param[in] state: The new state of the wakeup source(s)
 * @return    None
 * @retval    None
 */
FUNC(void, BSWM_CODE) BswM_EcuM_CurrentWakeup(
	VAR(EcuM_WakeupSourceType, AUTOMATIC) source,
	VAR(EcuM_WakeupStatusType, AUTOMATIC) state
)
{
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	/**
	 * @req [SWS_BswM_00132] If the BswMDevErrorDetect switch is enabled, the routine shall check if
	 *      the BSW Mode Manager is initialized. In case of an error, the BswM shall ignore the mode
	 *      request and report the error to the Default Error Tracer with the error code BSWM_E_NO_INIT.
	 */
	if(BSWM_C_ISUNINITED())
	{
		BSWM_DET_REPORT(BSWM_SID_ECUM_CURRENTWAKEUP, BSWM_E_NO_INIT);
	}
	/**
	 * @req [SWS_BswM_00133] If the BswMDevErrorDetect switch is enabled, the parameter state and the
	 *      parameter source shall be checked for being in the allowed range. In case of an error,
	 *      the BswM shall ignore the mode request and report the error to the Default Error Tracer
	 *      with the value BSWM_E_REQ_MODE_OUT_OF_RANGE.
	 */
	else if((state > ECUM_WKSTATUS_ENABLED)
	     || ((state > ECUM_WKSTATUS_EXPIRED) && (state < ECUM_WKSTATUS_ENABLED)))
	{
		BSWM_DET_REPORT(BSWM_SID_ECUM_CURRENTWAKEUP, BSWM_E_REQ_MODE_OUT_OF_RANGE);
	}
	else
	{
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
		uint32 idx;
		const BswM_EcuMWakeupSourceType* requestSource;
		for(idx = 0U; idx < BSWM_MODE_REQUEST_PORT_COUNT; idx++)
		{
			/**
			 * @req [SWS_BswM_00009] The BswM shall perform mode arbitration based on incoming mode requests.
			 */
			if(pBswM_IModeRequestedPorts[idx].BswMModeRequestSourceType == BSWM_ECUM_WAKEUP_SOURCE)
			{
				requestSource = (pBswM_IModeRequestedPorts[idx].pBswMModeRequestSource);
				if((requestSource->BswMEcuMWakeupSrcRef & source) != 0U)
				{
					if((pBswM_IModeRequestedPorts[idx].BswMRequestProcessing == \
							                     (BswM_RequestProcessingType)BSWM_IMMEDIATE) && \
                                 ((Std_ReturnType)E_OK == BswM_IGetArbitrationLock(BSWM_LOCK_TIMEOUT)))
					{
						/**
						 * @req [SWS_BswM_00059] Only the mode arbitration rules that use a specific
						 *      immediate mode condition shall be evaluated by the BswM within the
						 *      context of that specific mode request/indication.
						 */
						SchM_Enter_BswM_EXCLUSIVE_AREA_11();
						BswM_IRequestedModes[idx] = (BswM_ModeType) state;
						/* mode arbitration */
						BswM_IImmediateArbitrateAllRules(&(pBswM_IModeRequestedPorts[idx]));
						SchM_Exit_BswM_EXCLUSIVE_AREA_11();
						BswM_Immediate_ProQueues();
						BswM_Immediate_After();
						BswM_IReleaseArbitrationLock((uint8)E_OK);
					}
					else
					{
						(void)BswM_IModeRequestEnqueue((BswM_ModeType)state , idx);
					}
				} else {/* do nothing */}
			} else {/* do nothing */}
		}
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	}
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
}
#endif /* (STD_ON == BSWM_ECUM_ENABLED) */

#if (STD_ON == BSWM_ECUM_ENABLED)
/**
 * @sid       0x23
 * @brief     Function called by EcuM to notify about current Status of the Run Request Protocol.
 * @param[in] State:The requested state by EcuMFlex.
 * @param[in] CurrentStatus: Result of the Run Request Protocol.
 * @return    None
 * @retval    None
 */
FUNC(void, BSWM_CODE) BswM_EcuM_RequestedState(
	VAR(EcuM_StateType, AUTOMATIC) State,
	VAR(EcuM_RunStatusType, AUTOMATIC) CurrentStatus
)
{
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	/**
	 * @req [SWS_BswM_00227] If the BswMDevErrorDetect switch is enabled, the routine shall check if
	 *      the BSW Mode Manager is initialized. In case of an error, the BswM shall ignore the mode
	 *      request and report the error to the Default Error Tracer with the error code BSWM_E_NO_INIT.
	 */
	if(BSWM_C_ISUNINITED())
	{
		BSWM_DET_REPORT(BSWM_SID_ECUM_REQUESTEDSTATE, BSWM_E_NO_INIT);
	}
	/**
	 * @req [SWS_BswM_00228] If the BswMDevErrorDetect switch is enabled, the parameter State shall
	 *      be checked for being in the allowed range. In case of an error, the BswM shall ignore the
	 *      mode request and report the error to the Default Error Tracer with the value
	 *      BSWM_E_REQ_MODE_OUT_OF_RANGE.
	 * @req [SWS_BswM_00229] If the BswMDevErrorDetect switch is enabled, the parameter CurrentStatus
	 *      shall be checked for being in the allowed range. In case of an error, the BswM shall
	 *      ignore the mode request and report the error to the Default Error Tracer with the value
	 *      BSWM_E_REQ_MODE_OUT_OF_RANGE.
	 */
	else if(BSWM_C_ECUMSTATE_ISINVALID(State) || (CurrentStatus > ECUM_RUNSTATUS_RELEASED))
	{
		BSWM_DET_REPORT(BSWM_SID_ECUM_REQUESTEDSTATE, BSWM_E_REQ_MODE_OUT_OF_RANGE);
	}
	else
	{
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
		uint32 idx;
		const BswM_EcuMRUNRequestIndicationType* requestSource;
		for(idx = 0U; idx < BSWM_MODE_REQUEST_PORT_COUNT; idx++)
		{
			if(pBswM_IModeRequestedPorts[idx].BswMModeRequestSourceType == BSWM_ECUM_RUN_REQUEST_INDICATION)
			{
				requestSource = (pBswM_IModeRequestedPorts[idx].pBswMModeRequestSource);
				if(requestSource->BswMEcuMRUNRequestProtocolPort == \
						(BswM_EcuMRUNRequestProtocolPortType) State)
				{
					if((pBswM_IModeRequestedPorts[idx].BswMRequestProcessing == \
							                     (BswM_RequestProcessingType)BSWM_IMMEDIATE) && \
                                 ((Std_ReturnType)E_OK == BswM_IGetArbitrationLock(BSWM_LOCK_TIMEOUT)))
					{
						SchM_Enter_BswM_EXCLUSIVE_AREA_12();
						BswM_IRequestedModes[idx] = (BswM_ModeType) CurrentStatus;
						/* mode arbitration */
						BswM_IImmediateArbitrateAllRules(&(pBswM_IModeRequestedPorts[idx]));
						SchM_Exit_BswM_EXCLUSIVE_AREA_12();
						BswM_Immediate_ProQueues();
						BswM_Immediate_After();
						BswM_IReleaseArbitrationLock((uint8)E_OK);
					}
					else
					{
						(void)BswM_IModeRequestEnqueue((BswM_ModeType)CurrentStatus , idx);
					}
					/* Unique ports in the system */
					break;
				} else {/* do nothing */}
			} else {/* do nothing */}
		}
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	}
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
}
#endif /* (STD_ON == BSWM_ECUM_ENABLED) */

#if (STD_ON == BSWM_ETHSM_ENABLED)
/**
 * @sid       0x0d
 * @brief     Function called by EthSM to indicate its current state.
 * @param[in] Network: The Ethernet channel that the indicated state corresponds to.
 * @param[in] CurrentState:The current state of the Ethernet channel.
 * @return    None
 * @retval    None
 */
FUNC(void, BSWM_CODE) BswM_EthSM_CurrentState(
	VAR(NetworkHandleType, AUTOMATIC) Network,
	VAR(EthSM_NetworkModeStateType, AUTOMATIC) CurrentState
)
{
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	/**
	 * @req [SWS_BswM_00081] If the BswMDevErrorDetect switch is enabled, the routine shall check if
	 *      the BSW Mode Manager is initialized. In case of an error, the BswM shall ignore the state
	 *      indication and report the error to the Default Error Tracer with the error code
	 *      BSWM_E_NO_INIT.
	 */
	if(BSWM_C_ISUNINITED())
	{
		BSWM_DET_REPORT(BSWM_SID_ETHSM_CURRENTSTATE, BSWM_E_NO_INIT);
	}
	/**
	 * @req [SWS_BswM_00097] If the BswMDevErrorDetect switch is enabled, the parameter CurrentState
	 *      shall be checked for being in the allowed range. In case of an error, the BswM shall ignore
	 *      the state indication and report the error to the Default Error Tracer with the value
	 *      BSWM_E_REQ_MODE_OUT_OF_RANGE.
	 */
	else if(CurrentState > ETHSM_STATE_WAIT_OFFLINE)
	{
		BSWM_DET_REPORT(BSWM_SID_ETHSM_CURRENTSTATE, BSWM_E_REQ_MODE_OUT_OF_RANGE);
	}
	else
	{
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
		uint32 idx;
		const BswM_EthSMIndicationType* requestSource;
		for(idx = 0U; idx < BSWM_MODE_REQUEST_PORT_COUNT; idx++)
		{
			if(pBswM_IModeRequestedPorts[idx].BswMModeRequestSourceType == BSWM_ETHSM_INDICATION)
			{
				requestSource = (pBswM_IModeRequestedPorts[idx].pBswMModeRequestSource);
				if(requestSource->BswMEthSMChannelRef == Network)
				{
					if((pBswM_IModeRequestedPorts[idx].BswMRequestProcessing == BSWM_IMMEDIATE)  && \
                                              ((uint8)E_OK == BswM_IGetArbitrationLock(BSWM_LOCK_TIMEOUT)))
					{
						SchM_Enter_BswM_EXCLUSIVE_AREA_13();
						BswM_IRequestedModes[idx] = (BswM_ModeType) CurrentState;
						/* mode arbitration */
						BswM_IImmediateArbitrateAllRules(&(pBswM_IModeRequestedPorts[idx]));
						SchM_Exit_BswM_EXCLUSIVE_AREA_13();
						BswM_Immediate_ProQueues();
						BswM_Immediate_After();
						BswM_IReleaseArbitrationLock((uint8)E_OK);
					}
					else
					{
						(void)BswM_IModeRequestEnqueue((BswM_ModeType)CurrentState , idx);
					}
					/* Unique ports in the system */
					break;
				} else {/* do nothing */}
			} else {/* do nothing */}
		}
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	}
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
}
#endif /* (STD_ON == BSWM_ETHSM_ENABLED) */

#if (STD_ON == BSWM_FRSM_ENABLED)
/**
 * @sid       0x0c
 * @brief     Function called by FrSM to indicate its current state.
 * @param[in] Network: The FlexRay cluster that the indicated state corresponds to.
 * @param[in] CurrentState: The corrent state of the FlexRay cluster.
 * @return    None
 * @retval    None
 */
FUNC(void, BSWM_CODE) BswM_FrSM_CurrentState(
	VAR(NetworkHandleType, AUTOMATIC) Network,
	VAR(FrSM_BswM_StateType, AUTOMATIC) CurrentState
)
{
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	/**
	 * @req [SWS_BswM_00082] If the BswMDevErrorDetect switch is enabled, the routine shall check if
	 *      the BSW Mode Manager is initialized. In case of an error, the BswM shall ignore the state
	 *      indication and report the error to the Default Error Tracer with the error code
	 *      BSWM_E_NO_INIT.
	 */
	if(BSWM_C_ISUNINITED())
	{
		BSWM_DET_REPORT(BSWM_SID_FRSM_CURRENTSTATE, BSWM_E_NO_INIT);
	}
	/**
	 * @req [SWS_BswM_00099] If the BswMDevErrorDetect switch is enabled, the parameter CurrentState
	 *      shall be checked for being in the allowed range. In case of an error, the BswM shall
	 *      ignore the state indication and report the error to the Default Error Tracer with the
	 *      value BSWM_E_REQ_MODE_OUT_OF_RANGE.
	 */
	else if(CurrentState > FRSM_LOW_NUMBER_OF_COLDSTARTERS_ECU_PASSIVE)
	{
		BSWM_DET_REPORT(BSWM_SID_FRSM_CURRENTSTATE, BSWM_E_REQ_MODE_OUT_OF_RANGE);
	}
	else
	{
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
		uint32 idx;
		const BswM_FrSMIndicationType* requestSource;
		for(idx = 0U; idx < BSWM_MODE_REQUEST_PORT_COUNT; idx++)
		{
			if(pBswM_IModeRequestedPorts[idx].BswMModeRequestSourceType == BSWM_FRSM_INDICATION)
			{
				requestSource = (pBswM_IModeRequestedPorts[idx].pBswMModeRequestSource);
				if(requestSource->BswMFrSMChannelRef == Network)
				{
					if((pBswM_IModeRequestedPorts[idx].BswMRequestProcessing == BSWM_IMMEDIATE) && \
							                     ((uint8)E_OK == BswM_IGetArbitrationLock(BSWM_LOCK_TIMEOUT)))
					{
						SchM_Enter_BswM_EXCLUSIVE_AREA_14();

						BswM_IRequestedModes[idx] = (BswM_ModeType) CurrentState;
						/* mode arbitration */
						BswM_IImmediateArbitrateAllRules(&(pBswM_IModeRequestedPorts[idx]));
						SchM_Exit_BswM_EXCLUSIVE_AREA_14();
						BswM_Immediate_ProQueues();
						BswM_Immediate_After();
						BswM_IReleaseArbitrationLock((uint8)E_OK);
					}
					else
					{
						(void)BswM_IModeRequestEnqueue((BswM_ModeType)CurrentState , idx);
					}
					/* Unique ports in the system */
					break;
				} else {/* do nothing */}
			} else {/* do nothing */}
		}
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	}
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
}
#endif /* (STD_ON == BSWM_FRSM_ENABLED) */

#if (STD_ON == BSWM_J1939DCM_ENABLED)
/**
 * @sid 0x1b
 * @brief This API tells the BswM the desired communication status of the available networks.
 *        The status will typically be activated via COM I-PDU group switches.
 * @param[in] NetworkMask: Mask containing one bit for each available network.
 *            1: Network enabled
 *            0: Network disabled
 * @return    None
 * @retval    None
 */
FUNC(void, BSWM_CODE) BswM_J1939DcmBroadcastStatus(
	VAR(uint16, AUTOMATIC) NetworkMask
)
{
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	if(BSWM_C_ISUNINITED())
	{
		BSWM_DET_REPORT(BSWM_SID_J1939DCMBROADCASTSTATUS, BSWM_E_NO_INIT);
	}
	else
	{
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
		uint32 idx;
		BswM_ModeType requested;
		const BswM_J1939DcmBroadcastStatusType* requestSource;
		for(idx = 0U; idx < BSWM_MODE_REQUEST_PORT_COUNT; idx++)
		{
			if(pBswM_IModeRequestedPorts[idx].BswMModeRequestSourceType == BSWM_J1939DCM_BROADCAST_STATUS)
			{
				requestSource = (pBswM_IModeRequestedPorts[idx].pBswMModeRequestSource);
				/* communications enable */
				/* PRQA S 4397 EOF # violate MISRA_2004_Rule_10.5:Complex expressions should be limited */
				/* PRQA S 1891 EOF # violate MISRA_2004_Rule_10.1:There is no implicit type modification */
				if((NetworkMask & (0x0001u << requestSource->pBswMJ1939DcmChannelRef)) != 0U)
				{
					requested = (BswM_ModeType)TRUE;
				}
				/* communications prohibition */
				else
				{
					requested = (BswM_ModeType)FALSE;
				}
				/* model arbitration  */
				if((pBswM_IModeRequestedPorts[idx].BswMRequestProcessing == BSWM_IMMEDIATE) && \
						                       ((uint8)E_OK == BswM_IGetArbitrationLock(BSWM_LOCK_TIMEOUT)))
				{
					SchM_Enter_BswM_EXCLUSIVE_AREA_15();
					/* @todo Set the mode to 1 when the interface is called and change it subsequently  */
					BswM_IRequestedModes[idx] = (BswM_ModeType) requested;
					/* mode arbitration */
					BswM_IImmediateArbitrateAllRules(&(pBswM_IModeRequestedPorts[idx]));
					SchM_Exit_BswM_EXCLUSIVE_AREA_15();
					BswM_Immediate_ProQueues();
					BswM_Immediate_After();
					BswM_IReleaseArbitrationLock((uint8)E_OK);
				}
				else
				{
					(void)BswM_IModeRequestEnqueue((BswM_ModeType)requested , idx);
				}
			} else {/* do nothing */}
		}
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	}
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
}
#endif /* (STD_ON == BSWM_J1939DCM_ENABLED) */

#if (STD_ON == BSWM_J1939NM_ENABLED)
/**
 * @sid       0x18
 * @brief     Notification of current J1939Nm state after state changes.
 * @param[in] Network: Identification of the J1939 channel
 * @param[in] Node:    Identification of the J1939 node
 * @param[in] NmState: Current (new) state of the J1939 node
 * @return    None
 * @retval    None
 */
FUNC(void, BSWM_CODE) BswM_J1939Nm_StateChangeNotification(
	VAR(NetworkHandleType, AUTOMATIC) Network,
	VAR(uint8, AUTOMATIC) Node,
	VAR(Nm_StateType, AUTOMATIC) NmState
)
{
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	if(BSWM_C_ISUNINITED())
	{
		BSWM_DET_REPORT(BSWM_SID_J1939NM_STATECHANGENOTIFICATION, BSWM_E_NO_INIT);
	}
	else if(NmState > NM_STATE_OFFLINE)
	{
		BSWM_DET_REPORT(BSWM_SID_J1939NM_STATECHANGENOTIFICATION, BSWM_E_REQ_MODE_OUT_OF_RANGE);
	}
	else
	{
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
		uint32 idx;
		const BswM_J1939NmIndicationType* requestSource;
		for(idx = 0U; idx < BSWM_MODE_REQUEST_PORT_COUNT; idx++)
		{
			if(pBswM_IModeRequestedPorts[idx].BswMModeRequestSourceType == BSWM_J1939NM_INDICATION)
			{
				requestSource = (pBswM_IModeRequestedPorts[idx].pBswMModeRequestSource);
				if((requestSource->BswMJ1939NmChannelRef == Network)
				&& (requestSource->BswMJ1939NmNodeRef == Node))
				{
					if((pBswM_IModeRequestedPorts[idx].BswMRequestProcessing == BSWM_IMMEDIATE) && \
							                ((uint8)E_OK == BswM_IGetArbitrationLock(BSWM_LOCK_TIMEOUT)))
					{
						SchM_Enter_BswM_EXCLUSIVE_AREA_16();

						BswM_IRequestedModes[idx] = (BswM_ModeType) NmState;
						/* mode arbitration */
						BswM_IImmediateArbitrateAllRules(&(pBswM_IModeRequestedPorts[idx]));
						SchM_Exit_BswM_EXCLUSIVE_AREA_16();
						BswM_Immediate_ProQueues();
						BswM_Immediate_After();
						BswM_IReleaseArbitrationLock((uint8)E_OK);
					}
					else
					{
						(void)BswM_IModeRequestEnqueue((BswM_ModeType)NmState , idx);
					}
					/* Unique ports in the system */
					break;
				} else {/* do nothing */}
			} else {/* do nothing */}
		}
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	}
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
}
#endif /* (STD_ON == BSWM_J1939NM_ENABLED) */

#if (STD_ON == BSWM_LINSM_ENABLED)
/**
 * @sid       0x0a
 * @brief     Function called by LinSM to indicate the currently active schedule table for a
 *            specific LIN channel.
 * @param[in] Network: The LIN channel that the schedule table switch have occurred on.
 * @param[in] CurrentSchedule: The currently active schedule table of the LIN channel.
 * @return    None
 * @retval    None
 */
FUNC(void, BSWM_CODE) BswM_LinSM_CurrentSchedule(
	VAR(NetworkHandleType, AUTOMATIC) Network,
	VAR(LinIf_SchHandleType, AUTOMATIC) CurrentSchedule
)
{
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	if(BSWM_C_ISUNINITED())
	{
		BSWM_DET_REPORT(BSWM_SID_LINSM_CURRENTSCHEDULE, BSWM_E_NO_INIT);
	}
	else
	{
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
		uint32 idx;
		const BswM_LinScheduleIndicationType* requestSource;
		for(idx = 0U; idx < BSWM_MODE_REQUEST_PORT_COUNT; idx++)
		{
			if(pBswM_IModeRequestedPorts[idx].BswMModeRequestSourceType == BSWM_LIN_SCHEDULE_INDICATION)
			{
				requestSource = (pBswM_IModeRequestedPorts[idx].pBswMModeRequestSource);
				if(requestSource->BswMLinSMChannelRef == Network)
				{
					if((pBswM_IModeRequestedPorts[idx].BswMRequestProcessing == \
							                            (BswM_RequestProcessingType)BSWM_IMMEDIATE) && \
                                 ((Std_ReturnType)E_OK == BswM_IGetArbitrationLock(BSWM_LOCK_TIMEOUT)))
					{
						SchM_Enter_BswM_EXCLUSIVE_AREA_17();

						BswM_IRequestedModes[idx] = (BswM_ModeType) CurrentSchedule;
						/* mode arbitration */
						BswM_IImmediateArbitrateAllRules(&(pBswM_IModeRequestedPorts[idx]));
						SchM_Exit_BswM_EXCLUSIVE_AREA_17();
						BswM_Immediate_ProQueues();
						BswM_Immediate_After();
						BswM_IReleaseArbitrationLock((uint8)E_OK);
					}
					else
					{
						(void)BswM_IModeRequestEnqueue((BswM_ModeType)CurrentSchedule , idx);
					}
					/* Unique ports in the system */
					break;
				} else {/* do nothing */}
			} else {/* do nothing */}
		}
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	}
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
}
#endif /* (STD_ON == BSWM_LINSM_ENABLED) */

#if (STD_ON == BSWM_LINSM_ENABLED)
/**
 * @sid       0x09
 * @brief     Function called by LinSM to indicate its current state.
 * @param[in] Network: The LIN channel that the indicated state corresponds to.
 * @param[in] CurrentState: The current state of the LIN channel.
 * @return    None
 * @retval    None
 */
FUNC(void, BSWM_CODE) BswM_LinSM_CurrentState(
	VAR(NetworkHandleType, AUTOMATIC) Network,
	VAR(LinSM_ModeType, AUTOMATIC) CurrentState
)
{
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	/**
	 * @req [SWS_BswM_00083] If the BswMDevErrorDetect switch is enabled, the routine shall check
	 *      if the BSW Mode Manager is initialized. In case of an error, the BswM shall ignore the
	 *      state indication and report the error to the Default Error Tracer with the error code
	 *      BSWM_E_NO_INIT.
	 */
	if(BSWM_C_ISUNINITED())
	{
		BSWM_DET_REPORT(BSWM_SID_LINSM_CURRENTSTATE, BSWM_E_NO_INIT);
	}
	else if(CurrentState > LINSM_NO_COM)
	{
		BSWM_DET_REPORT(BSWM_SID_LINSM_CURRENTSTATE, BSWM_E_REQ_MODE_OUT_OF_RANGE);
	}
	else
	{
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
		uint32 idx;
		const BswM_LinSMIndicationType* requestSource;
		for(idx = 0U; idx < BSWM_MODE_REQUEST_PORT_COUNT; idx++)
		{
			if(pBswM_IModeRequestedPorts[idx].BswMModeRequestSourceType == BSWM_LINSM_INDICATION)
			{
				requestSource = (pBswM_IModeRequestedPorts[idx].pBswMModeRequestSource);
				if(requestSource->BswMLinSMChannelRef == Network)
				{
					if((pBswM_IModeRequestedPorts[idx].BswMRequestProcessing == \
							                         (BswM_RequestProcessingType)BSWM_IMMEDIATE) && \
                                 ((Std_ReturnType)E_OK == BswM_IGetArbitrationLock(BSWM_LOCK_TIMEOUT)))
					{
						SchM_Enter_BswM_EXCLUSIVE_AREA_18();

						BswM_IRequestedModes[idx] = (BswM_ModeType) CurrentState;
						/* mode arbitration */
						BswM_IImmediateArbitrateAllRules(&(pBswM_IModeRequestedPorts[idx]));
						SchM_Exit_BswM_EXCLUSIVE_AREA_18();
						BswM_Immediate_ProQueues();
						BswM_Immediate_After();
						BswM_IReleaseArbitrationLock((uint8)E_OK);
					}
					else
					{
						(void)BswM_IModeRequestEnqueue((BswM_ModeType)CurrentState , idx);
					}
					/* Unique ports in the system */
					break;
				}  else {/* do nothing */}
			} else {/* do nothing */}
		}
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	}
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
}
#endif /* (STD_ON == BSWM_LINSM_ENABLED) */

#if (STD_ON == BSWM_NM_ENABLED)
/**
 * @sid       0x24
 * @brief     Function called by NmIf to indicate a CarWakeup.
 * @param[in] Network:Identification of the Nm-Channel
 * @return    None
 * @retval    None
 */
FUNC(void, BSWM_CODE) BswM_NmIf_CarWakeUpIndication(
	VAR(NetworkHandleType, AUTOMATIC) Network
)
{
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	if(BSWM_C_ISUNINITED())
	{
		BSWM_DET_REPORT(BSWM_SID_NMIF_CARWAKEUPINDICATION, BSWM_E_NO_INIT);
	}
	else
	{
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
		uint32 idx;
		const BswM_NmIfCarWakeUpIndicationType* requestSource;
		for(idx = 0U; idx < BSWM_MODE_REQUEST_PORT_COUNT; idx++)
		{
			if(pBswM_IModeRequestedPorts[idx].BswMModeRequestSourceType == BSWM_NMIF_CAR_WAKEUP_INDICATION)
			{
				requestSource = (pBswM_IModeRequestedPorts[idx].pBswMModeRequestSource);
				if(requestSource->BswMNmChannelRef == Network)
				{
					if((pBswM_IModeRequestedPorts[idx].BswMRequestProcessing == \
							                                (BswM_RequestProcessingType)BSWM_IMMEDIATE)  && \
                                ((Std_ReturnType)E_OK == BswM_IGetArbitrationLock(BSWM_LOCK_TIMEOUT)))
					{
						SchM_Enter_BswM_EXCLUSIVE_AREA_19();
						/* @todo Set the mode to 1 when the interface is called and change it subsequently*/
						BswM_IRequestedModes[idx] = (BswM_ModeType) TRUE;
						/* mode arbitration */
						BswM_IImmediateArbitrateAllRules(&(pBswM_IModeRequestedPorts[idx]));
						SchM_Exit_BswM_EXCLUSIVE_AREA_19();
						BswM_Immediate_ProQueues();
						BswM_Immediate_After();
						BswM_IReleaseArbitrationLock((uint8)E_OK);
					}
					else
					{
						(void)BswM_IModeRequestEnqueue((BswM_ModeType)TRUE , idx);
					}
					/* Unique ports in the system */
					break;
				} else {/* do nothing */}
			} else {/* do nothing */}
		}
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	}
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
}
#endif /* (STD_ON == BSWM_NM_ENABLED) */

#if (STD_ON == BSWM_NVM_ENABLED)
/**
 * @sid       0x16
 * @brief     Function called by NvM to indicate the current block mode of an NvM block.
 *            To use this function integration code will be needed.
 * @param[in] Block: The Block that the new NvM Mode corresponds to.
 * @param[in] CurrentBlockMode:The current block mode of the NvM block.
 * @return    None
 * @retval    None
 */
FUNC(void, BSWM_CODE) BswM_NvM_CurrentBlockMode(
	VAR(NvM_BlockIdType, AUTOMATIC) Block,
	VAR(NvM_RequestResultType, AUTOMATIC) CurrentBlockMode
)
{
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	/**
	 * @req [SWS_BswM_00109] If the BswMDevErrorDetect switch is enabled, the routine shall check
	 *      if the BSW Mode Manager is initialized. In case of an error, the BswM shall ignore the
	 *      block mode indication and report the error to the Default Error Tracer with the error
	 *      code BSWM_E_NO_INIT.
	 */
	if(BSWM_C_ISUNINITED())
	{
		BSWM_DET_REPORT(BSWM_SID_NVM_CURRENTBLOCKMODE, BSWM_E_NO_INIT);
	}
	/**
	 * @req [SWS_BswM_00110] If the BswMDevErrorDetect switch is enabled, the parameter
	 *      CurrentBlockMode shall be checked for being in the allowed range. In case of an error,
	 *      the BswM shall ignore the block mode indication and report the error to the Default Error
	 *      Tracer with the value BSWM_E_REQ_MODE_OUT_OF_RANGE.
	 */
	else if(CurrentBlockMode > NVM_REQ_RESTORED_FROM_ROM)
	{
		BSWM_DET_REPORT(BSWM_SID_NVM_CURRENTBLOCKMODE, BSWM_E_REQ_MODE_OUT_OF_RANGE);
	}
	else
	{
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
		uint32 idx;
		const BswM_NvMRequestType* requestSource;
		for(idx = 0U; idx < BSWM_MODE_REQUEST_PORT_COUNT; idx++)
		{
			if(pBswM_IModeRequestedPorts[idx].BswMModeRequestSourceType == BSWM_NVM_REQUEST)
			{
				requestSource = (pBswM_IModeRequestedPorts[idx].pBswMModeRequestSource);
				if(requestSource->BswMNvMBlockRef == Block)
				{
					if((pBswM_IModeRequestedPorts[idx].BswMRequestProcessing == \
							              (BswM_RequestProcessingType)BSWM_IMMEDIATE) && \
							    ((Std_ReturnType)E_OK == BswM_IGetArbitrationLock(BSWM_LOCK_TIMEOUT)))
					{
						SchM_Enter_BswM_EXCLUSIVE_AREA_20();

						BswM_IRequestedModes[idx] = (BswM_ModeType) CurrentBlockMode;
						/* mode arbitration */
						BswM_IImmediateArbitrateAllRules(&(pBswM_IModeRequestedPorts[idx]));
						SchM_Exit_BswM_EXCLUSIVE_AREA_20();
						BswM_Immediate_ProQueues();
						BswM_Immediate_After();
						BswM_IReleaseArbitrationLock((uint8)E_OK);
					}
					else
					{
						(void)BswM_IModeRequestEnqueue((BswM_ModeType)CurrentBlockMode , idx);
					}
					/* Unique ports in the system */
					break;
				} else {/* do nothing */}
			} else {/* do nothing */}
		}
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	}
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
}
#endif /* (STD_ON == BSWM_NVM_ENABLED) */

#if (STD_ON == BSWM_NVM_ENABLED)
/**
 * @sid       0x17
 * @brief     Function called by NvM to inform the BswM about the current state of a multi block job.
 * @param[in] ServiceId: Indicates whether the callback refers to multi block services NvM_ReadAll
 *                       or NvM_WriteAll.
 * @param[in] CurrentJobMode: Current state of the multi block job indicated by parameter ServiceId.
 * @return    None
 * @retval    None
 */
FUNC(void, BSWM_CODE) BswM_NvM_CurrentJobMode(
	VAR(uint8, AUTOMATIC) ServiceId,
	VAR(NvM_RequestResultType, AUTOMATIC) CurrentJobMode
)
{
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	/**
	 * @req [SWS_BswM_00153] If the BswMDevErrorDetect switch is enabled, the routine shall check
	 *      if the BSW Mode Manager is initialized. In case of an error, the BswM shall ignore the
	 *      job  mode indication and report the error to the Default Error Tracer with the error
	 *      code BSWM_E_NO_INIT.
	 */
	if(BSWM_C_ISUNINITED())
	{
		BSWM_DET_REPORT(BSWM_SID_NVM_CURRENTJOBMODE, BSWM_E_NO_INIT);
	}
	else if(CurrentJobMode > NVM_REQ_RESTORED_FROM_ROM)
	{
		BSWM_DET_REPORT(BSWM_SID_NVM_CURRENTJOBMODE, BSWM_E_REQ_MODE_OUT_OF_RANGE);
	}
	else
	{
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
		uint32 idx;
		const BswM_NvMJobModeIndicationType* requestSource;
		for(idx = 0U; idx < BSWM_MODE_REQUEST_PORT_COUNT; idx++)
		{
			if(pBswM_IModeRequestedPorts[idx].BswMModeRequestSourceType == BSWM_NVM_JOB_MODE_INDICATION)
			{
				requestSource = (pBswM_IModeRequestedPorts[idx].pBswMModeRequestSource);
				if(requestSource->BswMNvmService == (BswM_NvmServiceType)ServiceId)
				{
					if((pBswM_IModeRequestedPorts[idx].BswMRequestProcessing == \
							                          (BswM_RequestProcessingType)BSWM_IMMEDIATE) \
							&& ((Std_ReturnType)E_OK == BswM_IGetArbitrationLock(BSWM_LOCK_TIMEOUT)))
					{
						SchM_Enter_BswM_EXCLUSIVE_AREA_21();

						BswM_IRequestedModes[idx] = (BswM_ModeType) CurrentJobMode;
						/* mode arbitration */
						BswM_IImmediateArbitrateAllRules(&(pBswM_IModeRequestedPorts[idx]));
						SchM_Exit_BswM_EXCLUSIVE_AREA_21();
						BswM_Immediate_ProQueues();
						BswM_Immediate_After();
						BswM_IReleaseArbitrationLock((uint8)E_OK);
					}
					else
					{
						(void)BswM_IModeRequestEnqueue((BswM_ModeType)CurrentJobMode , idx);
					}
					/* Unique ports in the system */
					break;
				} else {/* do nothing */}
			} else {/* do nothing */}
		}
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	}
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
}
#endif /* (STD_ON == BSWM_NVM_ENABLED) */

#if (STD_ON == BSWM_SD_ENABLED)
/**
 * @sid       0x1f
 * @brief     Function called by Service Discovery to indicate current state of the
 *            Client Service (available/down).
 * @param[in] SdClientServiceHandleId: HandleId to identify the ClientService
 * @param[in] CurrentClientState: Current state of the ClientService
 * @return    None
 * @retval    None
 */
FUNC(void, BSWM_CODE) BswM_Sd_ClientServiceCurrentState(
	VAR(uint16, AUTOMATIC) SdClientServiceHandleId,
	VAR(Sd_ClientServiceCurrentStateType, AUTOMATIC) CurrentClientState
)
{
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	/**
	 * @req [SWS_BswM_00205] If the BswMDevErrorDetect switch is enabled, the routine shall check if
	 *      the BSW Mode Manager is initialized. In case of an error, the BswM shall ignore the mode
	 *      request and report the error to the Default Error Tracer with the error code BSWM_E_NO_INIT.
	 */
	if(BSWM_C_ISUNINITED())
	{
		BSWM_DET_REPORT(BSWM_SID_SD_CLIENTSERVICECURRENTSTATE, BSWM_E_NO_INIT);
	}
	/**
	 * @req [SWS_BswM_00206] If the BswMDevErrorDetect switch is enabled, the parameter
	 *      CurrentClientState shall be checked for being in the allowed range. In case
	 *      of an error the BswM shall ignore the mode request and report the error, to
	 *      the Default Error Tracer with the value BSWM_E_REQ_MODE_OUT_OF_RANGE.
	 */
	else if(CurrentClientState > SD_CLIENT_SERVICE_AVAILABLE)
	{
		BSWM_DET_REPORT(BSWM_SID_SD_CLIENTSERVICECURRENTSTATE, BSWM_E_REQ_MODE_OUT_OF_RANGE);
	}
	else
	{
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
		uint32 idx;
		const BswM_SdClientServiceCurrentStateType* requestSource;
		for(idx = 0U; idx < BSWM_MODE_REQUEST_PORT_COUNT; idx++)
		{
			if( pBswM_IModeRequestedPorts[idx].BswMModeRequestSourceType == \
					                             BSWM_SD_CLIENT_SERVICE_CURRENT_STATE )
			{
				requestSource = (pBswM_IModeRequestedPorts[idx].pBswMModeRequestSource);
				if(requestSource->BswMSdClientMethodsRef == SdClientServiceHandleId)
				{
					if((pBswM_IModeRequestedPorts[idx].BswMRequestProcessing == \
							                     (BswM_RequestProcessingType)BSWM_IMMEDIATE)  && \
                                ((Std_ReturnType)E_OK == BswM_IGetArbitrationLock(BSWM_LOCK_TIMEOUT)))
					{
						SchM_Enter_BswM_EXCLUSIVE_AREA_22();
						/* @todo Set the mode to 1 when the interface is called and change it subsequently */
						BswM_IRequestedModes[idx] = (BswM_ModeType) CurrentClientState;
						/* mode arbitration */
						BswM_IImmediateArbitrateAllRules(&(pBswM_IModeRequestedPorts[idx]));
						SchM_Exit_BswM_EXCLUSIVE_AREA_22();
						BswM_Immediate_ProQueues();
						BswM_Immediate_After();
						BswM_IReleaseArbitrationLock((uint8)E_OK);
					}
					else
					{
						(void)BswM_IModeRequestEnqueue((BswM_ModeType)CurrentClientState , idx);
					}
					/* Unique ports in the system */
					break;
				} else {/* do nothing */}
			} else {/* do nothing */}
		}
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	}
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
}
#endif /* (STD_ON == BSWM_SD_ENABLED) */

#if (STD_ON == BSWM_SD_ENABLED)
/**
 * @sid       0x21
 * @brief     Function called by Service Discovery to indicate current status of the
 *            Consumed Eventgroup (available/down).
 * @param[in] SdConsumedEventGroupHandleId: HandleId to identify the Consumed Eventgroup
 * @param[in] ConsumedEventGroupState:Status of the Consumed Eventgroup
 * @return    None
 * @retval    None
 */
FUNC(void, BSWM_CODE) BswM_Sd_ConsumedEventGroupCurrentState(
	VAR(uint16, AUTOMATIC) SdConsumedEventGroupHandleId,
	VAR(Sd_ConsumedEventGroupCurrentStateType, AUTOMATIC) ConsumedEventGroupState
)
{
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	/**
	 * @req [SWS_BswM_00208] If the BswMDevErrorDetect switch is enabled, the routine shall
	 *      check if the BSW Mode Manager is initialized. In case of an error, the BswM shall
	 *      ignore the mode request and report the error to the Default Error Tracer with the
	 *      error code BSWM_E_NO_INIT.
	 */
	if(BSWM_C_ISUNINITED())
	{
		BSWM_DET_REPORT(BSWM_SID_SD_CONSUMEDEVENTGROUPCURRENTSTATE, BSWM_E_NO_INIT);
	}
	/**
	 * @req [SWS_BswM_00209] If the BswMDevErrorDetect switch is enabled, the parameter
	 *      ConsumedEventGroupState shall be checked for being in the allowed range. In case of
	 *      an error the BswM shall ignore the mode request and report the error, to the Default
	 *      Error Tracer with the value BSWM_E_REQ_MODE_OUT_OF_RANGE.
	 */
	else if(ConsumedEventGroupState > SD_CONSUMED_EVENTGROUP_AVAILABLE)
	{
		BSWM_DET_REPORT(BSWM_SID_SD_CONSUMEDEVENTGROUPCURRENTSTATE, BSWM_E_REQ_MODE_OUT_OF_RANGE);
	}
	else
	{
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
		uint32 idx;
		const BswM_SdConsumedEventGroupCurrentStateType* requestSource;
		for(idx = 0U; idx < BSWM_MODE_REQUEST_PORT_COUNT; idx++)
		{
			if(pBswM_IModeRequestedPorts[idx].BswMModeRequestSourceType == \
					                                 BSWM_SD_CONSUMED_EVENT_GROUP_CURRENT_STATE)
			{
				requestSource = (pBswM_IModeRequestedPorts[idx].pBswMModeRequestSource);
				if(requestSource->BswMSdConsumedEventGroupRef == SdConsumedEventGroupHandleId)
				{
					if((pBswM_IModeRequestedPorts[idx].BswMRequestProcessing == BSWM_IMMEDIATE) && \
							                    ((uint8)E_OK == BswM_IGetArbitrationLock(BSWM_LOCK_TIMEOUT)))
					{
						SchM_Enter_BswM_EXCLUSIVE_AREA_23();
						/* @todo Set the mode to 1 when the interface is called and change it subsequently */
						BswM_IRequestedModes[idx] = (BswM_ModeType) ConsumedEventGroupState;
						/* mode arbitration */
						BswM_IImmediateArbitrateAllRules(&(pBswM_IModeRequestedPorts[idx]));
						SchM_Exit_BswM_EXCLUSIVE_AREA_23();
						BswM_Immediate_ProQueues();
						BswM_Immediate_After();
						BswM_IReleaseArbitrationLock((uint8)E_OK);
					}
					else
					{
						(void)BswM_IModeRequestEnqueue((BswM_ModeType)ConsumedEventGroupState , idx);
					}
					/* Unique ports in the system */
					break;
				} else {/* do nothing */}
			} else {/* do nothing */}
		}
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	}
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
}
#endif /* (STD_ON == BSWM_SD_ENABLED) */

#if (STD_ON == BSWM_SD_ENABLED)
/**
 * @sid       0x20
 * @brief     Function called by Service Discovery to indicate current status of theEventHandler (requested/released).
 * @param[in] SdEventHandlerHandleId: HandleId to identify the EventHandler
 * @param[in] EventHandlerStatus: Status of the EventHandler
 * @return    None
 * @retval    None
 */
FUNC(void, BSWM_CODE) BswM_Sd_EventHandlerCurrentState(
	VAR(uint16, AUTOMATIC) SdEventHandlerHandleId,
	VAR(Sd_EventHandlerCurrentStateType, AUTOMATIC) EventHandlerStatus
)
{
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	/**
	 * @req [SWS_BswM_00211] If the BswMDevErrorDetect switch is enabled, the routine
	 *      shall check if the BSW Mode Manager is initialized. In case of an error, the
	 *      BswM shall ignore the mode request and report the error to the Default Error Tracer
	 *      with the error code BSWM_E_NO_INIT.
	 */
	if(BSWM_C_ISUNINITED())
	{
		BSWM_DET_REPORT(BSWM_SID_SD_EVENTHANDLERCURRENTSTATE, BSWM_E_NO_INIT);
	}
	/**
	 * @req [SWS_BswM_00212] If the BswMDevErrorDetect switch is enabled, the parameter
	 *      EventHandlerStatus shall be checked for being in the allowed range. In case of an error
	 *      the BswM shall ignore the mode request and report the error, to the Default Error Tracer
	 *      with the value BSWM_E_REQ_MODE_OUT_OF_RANGE.
	 */
	else if(EventHandlerStatus > SD_EVENT_HANDLER_REQUESTED)
	{
		BSWM_DET_REPORT(BSWM_SID_SD_EVENTHANDLERCURRENTSTATE, BSWM_E_REQ_MODE_OUT_OF_RANGE);
	}
	else
	{
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
		uint32 idx;
		const BswM_SdEventHandlerCurrentStateType* requestSource;
		for(idx = 0U; idx < BSWM_MODE_REQUEST_PORT_COUNT; idx++)
		{
			if(pBswM_IModeRequestedPorts[idx].BswMModeRequestSourceType == \
					                                         BSWM_SD_EVENT_HANDLER_CURRENT_STATE )
			{
				requestSource = (pBswM_IModeRequestedPorts[idx].pBswMModeRequestSource);
				if(requestSource->BswMSdEventHandlerRef == SdEventHandlerHandleId)
				{
					if((pBswM_IModeRequestedPorts[idx].BswMRequestProcessing == BSWM_IMMEDIATE) \
							             && ((uint8)E_OK == BswM_IGetArbitrationLock(BSWM_LOCK_TIMEOUT)))
					{
						SchM_Enter_BswM_EXCLUSIVE_AREA_24();

						BswM_IRequestedModes[idx] = (BswM_ModeType) EventHandlerStatus;
						/* mode arbitration */
						BswM_IImmediateArbitrateAllRules(&(pBswM_IModeRequestedPorts[idx]));
						SchM_Exit_BswM_EXCLUSIVE_AREA_24();
						BswM_Immediate_ProQueues();
						BswM_Immediate_After();
						BswM_IReleaseArbitrationLock((uint8)E_OK);
					}
					else
					{
						(void)BswM_IModeRequestEnqueue((BswM_ModeType)EventHandlerStatus , idx);
					}
					/* Unique ports in the system */
					break;
				} else {/* do nothing */}
			} else {/* do nothing */}
		}
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
	}
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */
}
#endif /* (STD_ON == BSWM_SD_ENABLED) */
/** @} */

#define BSWM_STOP_SEC_CODE
#include "BswM_MemMap.h"

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */
/** @} */
