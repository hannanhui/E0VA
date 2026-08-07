/**
 * @file        BswM_ModeControlType.h
 * @brief       AUTOSAR BSWM_MODECONTROLTYPE - BswM_ModeControlType driver header file.
 * @details     BswM_ModeControlType driver header file, containing the Autosar API specification and
 *              other variables and functions that are exported by the BswM_ModeControlType driver.
 * @version     1.2.0
 *
 * @addtogroup  BSWM_MODECONTROLTYPE
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
#ifndef BSWM_MODECONTROLTYPE_H
#define BSWM_MODECONTROLTYPE_H

#if defined(__cplusplus)
extern "C" 
{
#endif /* defined(__cplusplus) */

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/

#include "BswM_AvailableActionsType.h"
#if (BSWM_DEM_ENABLED == STD_ON)
#include "Dem.h"
#endif

/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/

#define BSWM_MODECONTROLTYPE_VENDOR_ID                    0U
#define BSWM_MODECONTROLTYPE_AR_RELEASE_MAJOR_VERSION     4U
#define BSWM_MODECONTROLTYPE_AR_RELEASE_MINOR_VERSION     2U
#define BSWM_MODECONTROLTYPE_AR_RELEASE_REVISION_VERSION  2U
#define BSWM_MODECONTROLTYPE_SW_MAJOR_VERSION             1U
#define BSWM_MODECONTROLTYPE_SW_MINOR_VERSION             2U
#define BSWM_MODECONTROLTYPE_SW_PATCH_VERSION             0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/

/* Check if current file and BswM_AvailableActionsType header file are of the same vendor */
#if(BSWM_MODECONTROLTYPE_VENDOR_ID != BSWM_AVAILABLEACTIONSTYPE_VENDOR_ID )
#error "BswM_ModeControlType.h and BswM_AvailableActionsType.h have different vendor id"
#endif
/* Check if current file and BswM_AvailableActionsType header file are of the same Autosar version */
#if(\
		(BSWM_MODECONTROLTYPE_AR_RELEASE_MAJOR_VERSION != \
				                            BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_MODECONTROLTYPE_AR_RELEASE_MINOR_VERSION != \
				                            BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_MINOR_VERSION) || \
		(BSWM_MODECONTROLTYPE_AR_RELEASE_REVISION_VERSION != \
				                            BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of BswM_ModeControlType.h and BswM_AvailableActionsType.h are different "
#endif
/* Check if current file and BswM_AvailableActionsType header file are of the same software version */
#if(\
		(BSWM_MODECONTROLTYPE_SW_MAJOR_VERSION != BSWM_AVAILABLEACTIONSTYPE_SW_MAJOR_VERSION) || \
		(BSWM_MODECONTROLTYPE_SW_MINOR_VERSION != BSWM_AVAILABLEACTIONSTYPE_SW_MINOR_VERSION) || \
		(BSWM_MODECONTROLTYPE_SW_PATCH_VERSION != BSWM_AVAILABLEACTIONSTYPE_SW_PATCH_VERSION) \
	)
#error "Software Version Number of BswM_ModeControlType.h and BswM_AvailableActionsType.h are different "
#endif

#ifndef DISABLE_INTERMOD_VERSION_CHECK
#if (BSWM_DEM_ENABLED == STD_ON)
/* Check if current file and Dem header file are of the same Autosar version */
#if(\
		(BSWM_MODECONTROLTYPE_AR_RELEASE_MAJOR_VERSION != DEM_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_MODECONTROLTYPE_AR_RELEASE_MINOR_VERSION != DEM_AR_RELEASE_MINOR_VERSION) \
	)
#error "AutoSar Version Number of BswM_ModeControlType.h and Dem.h are different "
#endif
#endif/* #if (BSWM_DEM_ENABLED == STD_ON) */
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

/**
 * @brief This parameter controls if the corresponding action list shall be executed every time
 * 		  the rule is evaluated or only when the result of the evaluation changes. This parameter
 * 		  does not have an effect when this action list is executed within another action list.
 */
typedef enum
{
	/**< @brief Action list shall be executed every time the rule is evaluated. */
	BSWM_CONDITION,
	/**< @brief Action list shall be executed every time the result of the evaluation changes.*/
	BSWM_TRIGGER
} BswM_ActionListExecutionType;

/**
 * @brief The action item can either be an atomic action or a reference to another
 * 		  action list or rule.
 */
typedef enum
{
	/**< @brief  BswM Action*/
	BSWM_ACTION,
	/**< @brief  BswM Action list*/
	BSWM_ACTION_LIST,
	/**< @brief  BswM rule*/
	BSWM_RULE
} BswM_ActionListItemTypeType;

/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS
 *====================================================================================================*/

/**
 * @brief This container defines an item in an action list.
 * @req   ECUC_BswM_00823
 */
typedef struct
{
	/**< @brief This parameter defines the index of the action in the action list. It is used
	 *         define in which order the actions shall be performed. (1)
	 */
	CONST(uint8, BSWM_CONFIG_DATA) BswMActionListItemIndex;
	/**< @brief This parameter defines if the execution of the action list shall be aborted if
	 *         this specific action returns E_NOT_OK. (1)
	 */
	CONST(boolean, BSWM_CONFIG_DATA) BswMAbortOnFail;
	/**< @brief The action item can either be an atomic action or a reference to another
	 *         action list or rule. (1)
	 */
	P2CONST(void, BSWM_CONFIG_DATA, BSWM_APPL_CONST) pBswMActionListItemRef;
	/**< @brief The action item can either be an atomic action or a reference to another
	 * 			action list or rule.
	 */
	CONST(BswM_ActionListItemTypeType, BSWM_CONFIG_DATA) BswM_ActionListItemsType;
	/**< @brief If the reference is given, the DEM event shall be reported failed if this
	 *         specific action returns E_NOT_OK; it shall be reported passed if this
	 *         specific action returns E_OK. (0..1)
	 *         0 - Invalid Dem Event ID
	 */
#if (BSWM_DEM_ENABLED == STD_ON)
	CONST(Dem_EventIdType, BSWM_CONFIG_DATA) BswMReportFailToDemRef;
#endif
} BswM_ActionListItemType;

/**
 * @brief Each instance of this container defines an action list that is invoked based
 *         on the BswM Rules. An action list contains a list of numbered action items
 *         to be processed. An action list can also include other action lists.
 * @req    ECUC_BswM_00809
 */
typedef struct
{
	/**< @brief Identification of the action list*/
	CONST(uint8, BSWM_CONFIG_DATA) BswMActionListIdx;
	/**< @brief  This parameter controls if the corresponding action list shall be executed every
	 *         time the rule is evaluated or only when the result of the evaluation changes. (1)
	 */
	CONST(BswM_ActionListExecutionType, BSWM_CONFIG_DATA) BswMActionListExecution;
	/**< @brief This container defines an item in an action list. (1..*)*/
	P2CONST(BswM_ActionListItemType, BSWM_CONFIG_DATA, BSWM_APPL_CONST) pBswMActionListItem;
	/**< @brief Number of action list*/
	CONST(uint8, BSWM_CONFIG_DATA) BswMActionListItemCount;
} BswM_ActionListType;

/**
 * @brief  Each container of this type defines an action. These actions can be part of
 *         one or several action lists.
 * @req    ECUC_BswM_00810
 */
typedef struct
{
	/**< @brief Choice container including the available actions to be used in
     *          the action lists. (1) */
	P2CONST(void, BSWM_CONFIG_DATA, BSWM_APPL_CONST) pBswMAvailableActions;
	/**< @brief BswM Available Actions Type */
	CONST(BswM_AvailableActionsTypeType, BSWM_CONFIG_DATA) BswMAvailableActionsType;
} BswM_ActionType;

/**
 * @brief This container includes all configuration sub-containers and parameters
 *         related to the mode control functionality of the BswM.
 * @req    ECUC_BswM_00802
 */
typedef struct
{
	/**< @brief Each container of this type defines an action. These actions
	 *          can be part of one or several action lists. (0..*) */
	P2CONST(BswM_ActionType, BSWM_CONFIG_DATA, BSWM_APPL_CONST) pBswMAction;

	/**< @brief Each instance of this container defines an action list that is
	 *          invoked based on the BswM Rules. (0..*) */
	P2CONST(BswM_ActionListType, BSWM_CONFIG_DATA, BSWM_APPL_CONST) pBswMActionList;

	/**< @brief This container defines a mode request port which the BswM
	 *          may utilize to send a mode request to a SW-C which is acting as a mode-manager.
	 *          If this container is referenced by a BswMRteModeRequest, the BswM
	 *          shall create a corresponding PPort in its service description. (0..*)
	 *  @todo  not yet realized */
	P2CONST(BswM_RteModeRequestPortType, BSWM_CONFIG_DATA, BSWM_APPL_CONST) pBswMRteModeRequestPort;
	/**< @brief This container includes a reference to mode switch interface
	 * 	        which the BswM must instantiate for the creation of a
	 *          PPortPrototype in its SWCD. (0..*)
	 *  @todo  not yet realized */
	P2CONST(BswM_SwitchPortType, BSWM_CONFIG_DATA, BSWM_APPL_CONST) pBswMSwitchPort;
} BswM_ModeControlType;

/*====================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS
 *====================================================================================================*/

/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES
 *====================================================================================================*/

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */
/** @} */

#endif /* #ifndef BSWM_MODECONTROLTYPE_H */
