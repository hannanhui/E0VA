/**
 * @file        BswM_PBcfg.c
 * @brief       AUTOSAR BswM_PBcfg  - BswM_PBcfg driver source file.
 * @details     BswM_PBcfg driver source file, containing the C implementation of Autosar API specification
 *              and other variables and functions that are exported by the BswM_PBcfg driver.
 * @version     1.2.0
 *
 * @addtogroup  BswM_PBcfg
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

/*====================================================================================================*
 *                                           INCLUDE FILES                                          
 *====================================================================================================*/


/*#include "BswM_MemMap.h"*/
#if (BSWM_POSTBUILD == BSWM_VARIANT)
#include "BswM.h"
#include "Dcm.h"
#include "Dem.h"
#include "Action.h"
#include "Dcm_Internal.h"

/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION                                 
 *====================================================================================================*/

#define BSWM_PBCFG_VENDOR_ID_C                    0U
#define BSWM_PBCFG_AR_RELEASE_MAJOR_VERSION_C     4U
#define BSWM_PBCFG_AR_RELEASE_MINOR_VERSION_C     2U
#define BSWM_PBCFG_AR_RELEASE_REVISION_VERSION_C  2U
#define BSWM_PBCFG_SW_MAJOR_VERSION_C             1U
#define BSWM_PBCFG_SW_MINOR_VERSION_C             2U
#define BSWM_PBCFG_SW_PATCH_VERSION_C             0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS                                      
 *====================================================================================================*/

/* Check if current file and BswM header file are of the same vendor */
#if(BSWM_PBCFG_VENDOR_ID_C != BSWM_VENDOR_ID )
#error "BswM_PBcfg.c and BswM.h have different vendor id"
#endif
/* Check if current file and BswM header file are of the same Autosar version */
#if(\
		(BSWM_PBCFG_AR_RELEASE_MAJOR_VERSION_C != BSWM_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_PBCFG_AR_RELEASE_MINOR_VERSION_C != BSWM_AR_RELEASE_MINOR_VERSION) || \
		(BSWM_PBCFG_AR_RELEASE_REVISION_VERSION_C != BSWM_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of BswM_PBcfg.c and BswM.h are different "
#endif
/* Check if current file and BswM header file are of the same software version */
#if(\
		(BSWM_PBCFG_SW_MAJOR_VERSION_C != BSWM_SW_MAJOR_VERSION) || \
		(BSWM_PBCFG_SW_MINOR_VERSION_C != BSWM_SW_MINOR_VERSION) || \
		(BSWM_PBCFG_SW_PATCH_VERSION_C != BSWM_SW_PATCH_VERSION) \
	)
#error "Software Version Number of BswM_PBcfg.c and BswM.h are different "
#endif

/*====================================================================================================*
 *                                   EXTERNAL FUNCTION DECLARATIONS                                 
 *====================================================================================================*/

/*====================================================================================================*
 *                                           LOCAL TYPEDEFS                                         
 *====================================================================================================*/


/*====================================================================================================*
 *                                            LOCAL MACROS                                          
 *====================================================================================================*/


/*====================================================================================================*
 *                                           LOCAL CONSTANTS                                        
 *====================================================================================================*/

/*====================================================================================================*
 *                                           LOCAL VARIABLES                                        
 *====================================================================================================*/
extern CONST(BswM_ActionListType , BSWM_CONST)  BswM_ActionLists_0[BSWM_ACTION_LIST_COUNT];
extern CONST(BswM_RuleType , BSWM_CONST)  BswM_Rules_0[BSWM_RULE_COUNT];
extern CONST(BswM_LogicalExpressionType , BSWM_CONST) \
		BswM_LogicalExpressions_0[BSWM_MDOE_LOGICAL_EXPRESSION_COUNT];
extern CONST(BswM_ModeConditionType , BSWM_CONST)  BswM_ModeConditions_0[BSWM_MODE_CONDITION_COUNT];
extern CONST(BswM_ModeRequestPortType , BSWM_CONST)  \
		BswM_ModeRequestPorts_0[BSWM_MODE_REQUEST_PORT_COUNT];
extern CONST(BswM_ActionType , BSWM_CONST)  BswM_Actions_0[5];
/*====================================================================================================*
 *                                      LOCAL FUNCTION PROTOTYPES                                   
 *====================================================================================================*/

/*====================================================================================================*
 *                                           LOCAL FUNCTIONS                                        
 *====================================================================================================*/

/*====================================================================================================*
 *                                          GLOBAL FUNCTIONS                                        
 *====================================================================================================*/
#define BSWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "BswM_MemMap.h"
/**
 * @{
 * @brief All request sources
 */
const BswM_GenericRequestType BswM_GenericRequest_0[1] =
{
    /* BswMGenericRequest_ShutDown */
    {
        /* BswMModeRequesterId */
        2,
        /* BswMRequestedModeMax */
        3
    }
};

/** @} */

CONST(BswM_ModeInitValueType , BSWM_CONST)  BswM_ModeInitValues_0[2] =
{
    /* BswMModeInitValue_0 */
    {
        /* BswMBswModeInitValue */
        ECUM_STATE_STARTUP,
        /* pBswMCompuScaleModeValue */
        NULL_PTR
    },
    /* BswMModeInitValue_0 */
    {
        /* BswMBswModeInitValue */
        ECUM_STATE_APP_RUN,
        /* pBswMCompuScaleModeValue */
        NULL_PTR
    }
};   

CONST(BswM_ModeRequestPortType , BSWM_CONST)  BswM_ModeRequestPorts_0[BSWM_MODE_REQUEST_PORT_COUNT] =
{
    /* BswMModeRequestPort_startup */
    {
        /* BswM_ModeRequestedPortId */
        BswMConf_BswMModeRequestPort_BswMModeRequestPort_startup,
        /* BswMRequestProcessing */
        BSWM_IMMEDIATE,
        /* pBswMModeInitValue */
        &(BswM_ModeInitValues_0[0]), 
        /* pBswMModeRequestSource */
        NULL_PTR,
        /* BswMModeRequestSourceType */
        BSWM_ECUM_INDICATION
    },
    /* BswMModeRequestPort_ShutDown */
    {
        /* BswM_ModeRequestedPortId */
        BswMConf_BswMModeRequestPort_BswMModeRequestPort_ShutDown,
        /* BswMRequestProcessing */
        BSWM_IMMEDIATE,
        /* pBswMModeInitValue */
        &(BswM_ModeInitValues_0[1]), 
        /* pBswMModeRequestSource */
        &(BswM_GenericRequest_0[0]),
        /* BswMModeRequestSourceType */
        BSWM_GENERIC_REQUEST
    }
};

CONST(BswM_BswModeType , BSWM_CONST)  BswM_BswModes_0[2] =
{
    /* BswMBswMode_0 */
    {
        /* BswMBswRequestedMode */
        ECUM_STATE_STARTUP,

        /* pBswMCompuScaleModeValue */
        NULL_PTR
    },   
    /* BswMBswMode_0 */
    {
        /* BswMBswRequestedMode */
        ECUM_STATE_APP_POST_RUN,

        /* pBswMCompuScaleModeValue */
        NULL_PTR
    }   
};

 

CONST(BswM_ConditionValueType , BSWM_CONST)  BswM_ConditionValues_0[2] =
{
    /* BswMConditionValue_0 */
    {
        /* pBswMBswMode */
        &(BswM_BswModes_0[0]), 
 
        /* pBswMModeDeclaration */
        NULL_PTR
    }, 
    /* BswMConditionValue_0 */
    {
        /* pBswMBswMode */
        &(BswM_BswModes_0[1]), 
 
        /* pBswMModeDeclaration */
        NULL_PTR
    } 
};

 

CONST(BswM_ModeConditionType , BSWM_CONST)  BswM_ModeConditions_0[BSWM_MODE_CONDITION_COUNT] =
{
    /* BswMModeCondition_startup */
    {
        /* BswMModeConditionId */
        BswMConf_BswMModeCondition_BswMModeCondition_startup,
        /* BswMConditionType */
        BSWM_EQUALS_NOT,
        /* pBswMConditionMode */
        &(BswM_ModeRequestPorts_0[BswMConf_BswMModeRequestPort_BswMModeRequestPort_startup]),
        /* pBswMConditionValue */
        &(BswM_ConditionValues_0[0]) 
    },
    /* BswMModeCondition_Shut_Down */
    {
        /* BswMModeConditionId */
        BswMConf_BswMModeCondition_BswMModeCondition_Shut_Down,
        /* BswMConditionType */
        BSWM_EQUALS,
        /* pBswMConditionMode */
        &(BswM_ModeRequestPorts_0[BswMConf_BswMModeRequestPort_BswMModeRequestPort_ShutDown]),
        /* pBswMConditionValue */
        &(BswM_ConditionValues_0[1]) 
    }
};

 
P2CONST(BswM_ModeConditionType , BSWM_CONST , RTE_APPL_CONST)  BswM_ModeConditionArguments_0[2] =
{
    /* BswMLogicalExpression_startup */
    &(BswM_ModeConditions_0[BswMConf_BswMModeCondition_BswMModeCondition_startup]),  
    /* BswMLogicalExpression_Shut_Dowm */
    &(BswM_ModeConditions_0[BswMConf_BswMModeCondition_BswMModeCondition_Shut_Down])  
};




CONST(BswM_LogicalExpressionType , BSWM_CONST)  BswM_LogicalExpressions_0[BSWM_MDOE_LOGICAL_EXPRESSION_COUNT] =
{
    
    /* BswMLogicalExpression_startup */
    {
        /* BswMLogicalOperator */
        BSWM_NOOP,
        /* pBswMLogicExpressionArgumentRef */
        NULL_PTR,
        /* BswMLogicExpressionArgumentCount */
        0,
        /* pBswMModeConditionArgumentRef */
        &(BswM_ModeConditionArguments_0[0]), 
        /* BswMModeConditionArgumentCount */
        1
    },
    
    /* BswMLogicalExpression_Shut_Dowm */
    {
        /* BswMLogicalOperator */
        BSWM_NOOP,
        /* pBswMLogicExpressionArgumentRef */
        NULL_PTR,
        /* BswMLogicExpressionArgumentCount */
        0,
        /* pBswMModeConditionArgumentRef */
        &(BswM_ModeConditionArguments_0[1]), 
        /* BswMModeConditionArgumentCount */
        1
    }
};
 

CONST(BswM_RuleType , BSWM_CONST)  BswM_Rules_0[BSWM_RULE_COUNT] =
{
    /* BswMRule_startup_zero */
    {
        /* BswMRuleId */
        BswMConf_BswMRule_BswMRule_startup_zero,
        /* BswMNestedExecutionOnly */
        FALSE,
        /* BswMRuleInitState */
        BSWM_TRUE,
        /* pBswMRuleExpressionRef */
        &(BswM_LogicalExpressions_0[BswMConf_BswMLogicalExpression_BswMLogicalExpression_startup]),
        /* pBswMRuleFalseActionList */
        NULL_PTR ,
        /* pBswMRuleTrueActionList */
        &(BswM_ActionLists_0[BswMConf_BswMActionList_BswMActionList_All_Init_zero])
    }
};

 
 





void BswM_UserCalloutFunction_0(void)
{
    //NvM_ReadAll_Action();
}
void BswM_UserCalloutFunction_1(void)
{
    Memory_All_Init();
}
void BswM_UserCalloutFunction_2(void)
{
    Communication_All_Init();
}
void BswM_UserCalloutFunction_3(void)
{
    Dcm_Init(&Dcm_Config);
}
void BswM_UserCalloutFunction_4(void)
{
   // Callout_Action();
}

CONST(BswM_UserCalloutType , BSWM_CONST) BswM_UserCallout_0[5] =
{
    {
       /* BswMUserCalloutFunction */
       BswM_UserCalloutFunction_0
    },
    {
       /* BswMUserCalloutFunction */
       BswM_UserCalloutFunction_1
    },
    {
       /* BswMUserCalloutFunction */
       BswM_UserCalloutFunction_2
    },
    {
       /* BswMUserCalloutFunction */
       BswM_UserCalloutFunction_3
    },
    {
       /* BswMUserCalloutFunction */
       BswM_UserCalloutFunction_4
    }
};

CONST(BswM_ActionType , BSWM_CONST)  BswM_Actions_0[5] =
{
    /* BswMAction_NvM_ReadAll */
    {
        /* pBswMAvailableActions */
        &(BswM_UserCallout_0[0]), 
        /* BswMAvailableActionsType */
        BSWM_USER_CALLOUT
    },
    /* BswMAction_Memory_All_Init */
    {
        /* pBswMAvailableActions */
        &(BswM_UserCallout_0[1]), 
        /* BswMAvailableActionsType */
        BSWM_USER_CALLOUT
    },
    /* BswMAction_Communication_All_Init */
    {
        /* pBswMAvailableActions */
        &(BswM_UserCallout_0[2]), 
        /* BswMAvailableActionsType */
        BSWM_USER_CALLOUT
    },
    /* BswMAction_Dcm */
    {
        /* pBswMAvailableActions */
        &(BswM_UserCallout_0[3]), 
        /* BswMAvailableActionsType */
        BSWM_USER_CALLOUT
    },
    /* BswMAction_Action */
    {
        /* pBswMAvailableActions */
        &(BswM_UserCallout_0[4]), 
        /* BswMAvailableActionsType */
        BSWM_USER_CALLOUT
    }
};

CONST(BswM_ActionListItemType , BSWM_CONST)  BswM_ActionListItems_0[5] =
{
    {
        /* BswMActionListItemIndex */
        0, 
        /* BswMAbortOnFail */
        FALSE,
        /* pBswMActionListItemRef */
        &(BswM_Actions_0[BswMConf_BswMAction_BswMAction_Memory_All_Init]),
        /* BswM_ActionListItemType */
        BSWM_ACTION,
        /* BswMReportFailToDemRef */
        #if (BSWM_DEM_ENABLED == STD_ON)
        0
        #endif
    },
    {
        /* BswMActionListItemIndex */
        1, 
        /* BswMAbortOnFail */
        FALSE,
        /* pBswMActionListItemRef */
        &(BswM_Actions_0[BswMConf_BswMAction_BswMAction_Communication_All_Init]),
        /* BswM_ActionListItemType */
        BSWM_ACTION,
        /* BswMReportFailToDemRef */
        #if (BSWM_DEM_ENABLED == STD_ON)
        0
        #endif
    },
    {
        /* BswMActionListItemIndex */
        2, 
        /* BswMAbortOnFail */
        FALSE,
        /* pBswMActionListItemRef */
        &(BswM_Actions_0[BswMConf_BswMAction_BswMAction_Dcm]),
        /* BswM_ActionListItemType */
        BSWM_ACTION,
        /* BswMReportFailToDemRef */
        #if (BSWM_DEM_ENABLED == STD_ON)
        0
        #endif
    },
    {
        /* BswMActionListItemIndex */
        3, 
        /* BswMAbortOnFail */
        FALSE,
        /* pBswMActionListItemRef */
        &(BswM_Actions_0[BswMConf_BswMAction_BswMAction_Action]),
        /* BswM_ActionListItemType */
        BSWM_ACTION,
        /* BswMReportFailToDemRef */
        #if (BSWM_DEM_ENABLED == STD_ON)
        0
        #endif
    },
    {
        /* BswMActionListItemIndex */
        4, 
        /* BswMAbortOnFail */
        FALSE,
        /* pBswMActionListItemRef */
        &(BswM_Actions_0[BswMConf_BswMAction_BswMAction_NvM_ReadAll]),
        /* BswM_ActionListItemType */
        BSWM_ACTION,
        /* BswMReportFailToDemRef */
        #if (BSWM_DEM_ENABLED == STD_ON)
        0
        #endif
    }
};


CONST(BswM_ActionListType , BSWM_CONST)  BswM_ActionLists_0[BSWM_ACTION_LIST_COUNT] =
{
    /* BswMActionList_All_Init_zero */
    {
        /* BswMActionListIdx */
        0,
        /* BswMActionListExecution */
        BSWM_CONDITION,
        /* pBswMActionListItem */
        &(BswM_ActionListItems_0[0]), 
        /* BswMActionListItemCount */
        5
    }
};
 

CONST(BswM_ConfigType , BSWM_CONST)  BswM_Config =
{
    /* pBswMPartitionRef */
    NULL_PTR,
    /* BswMArbitration */
    {
        /* pBswMLogicalExpression */
        BswM_LogicalExpressions_0,
        /* pBswMModeCondition */
        BswM_ModeConditions_0,
        /* pBswMModeRequestPort */
        BswM_ModeRequestPorts_0,
        /* pBswMRule */
        BswM_Rules_0
    },
    /* pBswMDataTypeMappingSets */
    NULL_PTR,
    /* BswMModeControl */
    {
        /* pBswMAction */
        BswM_Actions_0,
        /* pBswMActionList */
        BswM_ActionLists_0,
        /* pBswMRteModeRequestPort */
        NULL_PTR,
        /* pBswMSwitchPort */
        NULL_PTR
    }
};

#define BSWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "BswM_MemMap.h"

#endif /* (BSWM_POSTBUILD == BSWM_VARIANT) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */
/** @} */
