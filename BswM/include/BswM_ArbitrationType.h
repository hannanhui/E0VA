/**
 * @file        BswM_ArbitrationType.h
 * @brief       AUTOSAR BSWM_ARBITRATIONTYPE - BswM_ArbitrationType driver header file.
 * @details     BswM_ArbitrationType driver header file, containing the Autosar API specification and
 *              other variables and functions that are exported by the BswM_ArbitrationType driver.
 * @version     1.2.0
 *
 * @addtogroup  BswM_ArbitrationType
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
#ifndef BSWM_ARBITRATIONTYPE_H
#define BSWM_ARBITRATIONTYPE_H

#if defined(__cplusplus)
extern "C" 
{
#endif /* defined(__cplusplus) */

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/

#include "BswM_ModeRequestSourceType.h"
#include "BswM_ModeControlType.h"

/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/

#define BSWM_ARBITRATIONTYPE_VENDOR_ID                    0U
#define BSWM_ARBITRATIONTYPE_AR_RELEASE_MAJOR_VERSION     4U
#define BSWM_ARBITRATIONTYPE_AR_RELEASE_MINOR_VERSION     2U
#define BSWM_ARBITRATIONTYPE_AR_RELEASE_REVISION_VERSION  2U
#define BSWM_ARBITRATIONTYPE_SW_MAJOR_VERSION             1U
#define BSWM_ARBITRATIONTYPE_SW_MINOR_VERSION             2U
#define BSWM_ARBITRATIONTYPE_SW_PATCH_VERSION             0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/

/* Check if current file and BswM_ModeRequestSourceType header file are of the same vendor */
#if(BSWM_ARBITRATIONTYPE_VENDOR_ID != BSWM_MODEREQUESTSOURCETYPE_VENDOR_ID )
#error "BswM_ArbitrationType.h and BswM_ModeRequestSourceType.h have different vendor id"
#endif
/* Check if current file and BswM_ModeRequestSourceType header file are of the same Autosar version */
#if(\
		(BSWM_ARBITRATIONTYPE_AR_RELEASE_MAJOR_VERSION != \
				                            BSWM_MODEREQUESTSOURCETYPE_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_ARBITRATIONTYPE_AR_RELEASE_MINOR_VERSION != \
				                            BSWM_MODEREQUESTSOURCETYPE_AR_RELEASE_MINOR_VERSION) || \
		(BSWM_ARBITRATIONTYPE_AR_RELEASE_REVISION_VERSION != \
				                            BSWM_MODEREQUESTSOURCETYPE_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of BswM_ArbitrationType.h and BswM_ModeRequestSourceType.h are different "
#endif
/* Check if current file and BswM_ModeRequestSourceType header file are of the same software version */
#if(\
		(BSWM_ARBITRATIONTYPE_SW_MAJOR_VERSION != BSWM_MODEREQUESTSOURCETYPE_SW_MAJOR_VERSION) || \
		(BSWM_ARBITRATIONTYPE_SW_MINOR_VERSION != BSWM_MODEREQUESTSOURCETYPE_SW_MINOR_VERSION) || \
		(BSWM_ARBITRATIONTYPE_SW_PATCH_VERSION != BSWM_MODEREQUESTSOURCETYPE_SW_PATCH_VERSION) \
	)
#error "Software Version Number of BswM_ArbitrationType.h and BswM_ModeRequestSourceType.h are different "
#endif

/* Check if current file and BswM_ModeControlType header file are of the same vendor */
#if(BSWM_ARBITRATIONTYPE_VENDOR_ID != BSWM_MODECONTROLTYPE_VENDOR_ID )
#error "BswM_ArbitrationType.h and BswM_ModeControlType.h have different vendor id"
#endif
/* Check if current file and BswM_ModeControlType header file are of the same Autosar version */
#if(\
		(BSWM_ARBITRATIONTYPE_AR_RELEASE_MAJOR_VERSION != \
				                            BSWM_MODECONTROLTYPE_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_ARBITRATIONTYPE_AR_RELEASE_MINOR_VERSION != \
				                            BSWM_MODECONTROLTYPE_AR_RELEASE_MINOR_VERSION) || \
		(BSWM_ARBITRATIONTYPE_AR_RELEASE_REVISION_VERSION != \
				                            BSWM_MODECONTROLTYPE_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of BswM_ArbitrationType.h and BswM_ModeControlType.h are different "
#endif
/* Check if current file and BswM_ModeControlType header file are of the same software version */
#if(\
		(BSWM_ARBITRATIONTYPE_SW_MAJOR_VERSION != BSWM_MODECONTROLTYPE_SW_MAJOR_VERSION) || \
		(BSWM_ARBITRATIONTYPE_SW_MINOR_VERSION != BSWM_MODECONTROLTYPE_SW_MINOR_VERSION) || \
		(BSWM_ARBITRATIONTYPE_SW_PATCH_VERSION != BSWM_MODECONTROLTYPE_SW_PATCH_VERSION) \
	)
#error "Software Version Number of BswM_ArbitrationType.h and BswM_ModeControlType.h are different "
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
 * @brief This enum type specifies the logical operator to be used in the logical expression.
 */
typedef enum
{
	/**< @brief Logical expression "with" */
	BSWM_AND,
	/**< @brief Logical expression "not and"  */
	BSWM_NAND,
	/**< @brief Logical expression "or" */
	BSWM_OR,
	/**< @brief Logical expression "different or" */
	BSWM_XOR,
	/**< @brief no opearion */
	BSWM_NOOP
} BswM_LogicalOperatorType;

/**
 * @brief This enum type specifices what kind of comparison that is made for
 *        the evaluation of the mode condition.
 */
typedef enum
{
	/**< @brief Equal mode condition */
	BSWM_EQUALS,
	/**< @brief mode condition are not equal */
	BSWM_EQUALS_NOT
} BswM_ConditionTypeType;

/**
 * @brief This parameter defines if the processing of the mode arbitration shall be done
 *        immediately when a mode request is received or if it shall be deferred to the
 *        processing of the main function of BswM.
 */
typedef enum
{
	/**< @brief mmediate implementation  */
	BSWM_DEFERRED,
	/**< @brief Defer to main function*/
	BSWM_IMMEDIATE
} BswM_RequestProcessingType;

/**
 * @brief Define reset/initialization behavior of BswM.
 */
typedef enum
{
	/**< @brief The evaluation result is treated as changed if the rule is evaluated to true.*/
	BSWM_FALSE,
	/**< @brief The evaluation result is always treated as changed
     *          at the first evaluation of the rule after initialization*/
	BSWM_TRUE,
	/**< @brief The evaluation result is always treated as changed
     *          at the first evaluation of the rule after initialization.*/
	BSWM_UNDEFINED,
	BSWM_INVALID
} BswM_RuleStateType;

/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS
 *====================================================================================================*/

/**
 * @brief  This container contains parameters used to define a mode value.
 * @req    ECUC_BswM_01039
 * @todo   not yet realized
 */
typedef struct
{
	/**< @brief The value of this parameter shall match the VT member of a CompuConst
	 *          defined within the referenced CompuMethod (BswMCompuMethodRef).  */
	CONST(uint8, BSWM_CONFIG_DATA) BswMCompuConstText;
	/**< @brief This is a foreign reference to the CompuMethod used for mode requests.
	 * 			The CompuMethod category shall be TEXTTABLE.  */
	P2CONST(void, BSWM_CONFIG_DATA, RTE_APPL_CONST) pBswMCompuMethodRef;
} BswM_CompuScaleModeValueType;

/**
 * @brief  This container defines the initial mode value that is used by BswM for the
 *         corresponding mode request after initialization.
 * @note   BswMBswModeInitValue 鍜� pBswMCompuScaleModeValue can only define one
 * @req     ECUC_BswM_00928
 */
typedef struct
{
	/**< @brief This parameter defines the initial mode value that is used by BswM for the
	 * 			corresponding mode request after initialization. (0..1)*/
	CONST(BswM_ModeType, BSWM_CONFIG_DATA) BswMBswModeInitValue;

	/**< @brief This container contains parameters used to define a mode value. (0..1)
	 *   @todo not yet realized*/
	P2CONST(BswM_CompuScaleModeValueType, BSWM_CONFIG_DATA, BSWM_APPL_CONST) pBswMCompuScaleModeValue;
} BswM_ModeInitValueType;

/**
 * @brief  When the mode corresponds to a mode request or mode indication
 *         interface the mode is defined by a mode declaration.
 * @req    ECUC_BswM_00868
 * @todo   not yet realized
 */
typedef struct
{
	/**< @brief This is a foreign reference to the Mode Declaration used for the mode
	 * 			requests corresponding to this condition.
	 *   @todo  not yet realized*/
	CONST(uint8, BSWM_CONFIG_DATA) BswMModeValueRef;
} BswM_ModeDeclarationType;

/**
 * @brief  This container defines the value and type of a mode in the BSW.
 * @req    ECUC_BswM_00869
 */
typedef struct
{
	/**< @brief This parameter contains the symbolic name (as a string) of a certain
	 * 			mode/state that can be requested/indicated by the BSW modules. (0..1)*/
	CONST(BswM_ModeType, BSWM_CONFIG_DATA) BswMBswRequestedMode;

	/**< @brief This container contains parameters used to define a mode value. (0..1)*/
	P2CONST(BswM_CompuScaleModeValueType, BSWM_CONFIG_DATA, BSWM_APPL_CONST) pBswMCompuScaleModeValue;
} BswM_BswModeType;

/**
 * @brief  This container holds the parameters and references necessary to identify
 *         the mode type and the value that the mode request is compared to.
 * @req    ECUC_BswM_00816
 */
typedef struct
{
	/**< @brief This container defines the value and type of a mode in the BSW. (0..1)*/
	P2CONST(BswM_BswModeType, BSWM_CONFIG_DATA, BSWM_APPL_CONST) pBswMBswMode;

	/**< @brief When the mode corresponds to a mode request or mode indication interface
	 * 			the mode is defined by a mode declaration. (0..1)
	 *   @todo  not yet realized*/
	P2CONST(BswM_ModeDeclarationType, BSWM_CONFIG_DATA, BSWM_APPL_CONST) pBswMModeDeclaration;
} BswM_ConditionValueType;

/**
 * @brief  Each instance of this container defines a mode request interface that is
 *         used to requests or indicate modes from/to the BswM.
 * @req    ECUC_BswM_00805
 */
typedef struct
{
	/**< @brief Id of the requesting port*/
	CONST(uint32, BSWM_CONFIG_DATA) BswM_ModeRequestedPortId;
	/**< @brief This parameter defines if the processing of the mode arbitration shall be done
	 *          immediately when a mode request is received or if it shall be deferred to the
	 *          processing of the main function of BswM. (1)
	 */
	CONST(BswM_RequestProcessingType, BSWM_CONFIG_DATA) BswMRequestProcessing;

	/**< @brief This container defines the initial mode value that is used by
	 *    	  	BswM for the corresponding mode request (0..1).
     */
	P2CONST(BswM_ModeInitValueType, BSWM_CONFIG_DATA, BSWM_APPL_CONST) pBswMModeInitValue;

	/**< @brief This choice container specifies the source of the mode request
     *          or state/mode indication. (1)
     */
	P2CONST(void, BSWM_CONFIG_DATA, BSWM_APPL_CONST) pBswMModeRequestSource;

	/**< @brief This is the type of pBswMModeRequestSource. (1)*/
	CONST(BswM_ModeRequestSourceTypeType, BSWM_CONFIG_DATA) BswMModeRequestSourceType;
} BswM_ModeRequestPortType;

/**
 * @brief  This container describes the BswM mode conditions that can be used
 *         either by itself to form a rule or as a part of a logical expression.
 * @req    ECUC_BswM_00807
 */
typedef struct
{
	/**< @brief Id of the mode condition*/
	CONST(uint8, BSWM_CONFIG_DATA) BswMModeConditionId;
	/**< @brief This parameter specifies what kind of comparison that is made for
     *          the evaluation of the mode condition. (1)*/
	CONST(BswM_ConditionTypeType, BSWM_CONFIG_DATA) BswMConditionType;

	/**< @brief This parameter references the mode request port that is used for the condition. (1)*/
	P2CONST(BswM_ModeRequestPortType, BSWM_CONFIG_DATA, BSWM_APPL_CONST) pBswMConditionMode;

	/**< @brief This container holds the parameters and references necessary
	 *          to identify the mode type and the value that the mode request is compared to. (0..1)*/
	P2CONST(BswM_ConditionValueType, BSWM_CONFIG_DATA, BSWM_APPL_CONST) pBswMConditionValue;
} BswM_ModeConditionType;

/**
 * @brief  This container describes the logical expressions that can be used for the
 *         mode arbitration.
 * @req    ECUC_BswM_00808
 */
typedef struct _BswM_LogicalExpressionType
{
	/**< @brief This parameter specifies the logical operator to be used in the logical expression.
	 *          If the expression only consists of a single condition this parameter shall not be
	 *          used.*/
	CONST(BswM_LogicalOperatorType, BSWM_CONFIG_DATA) BswMLogicalOperator;
	/**< @brief This is a reference to a sub-expression. (1..*)*/
	P2CONST(struct _BswM_LogicalExpressionType*, BSWM_CONFIG_DATA, BSWM_APPL_CONST) pBswMLogicExpressionArgumentRef;
	/**< @brief  Number of logical expressions */
	CONST(uint8, BSWM_CONFIG_DATA) BswMLogicExpressionArgumentCount;
	/**< @brief This is a  reference  to a mode condition . (1..*)*/
	P2CONST(BswM_ModeConditionType*, BSWM_CONFIG_DATA, BSWM_APPL_CONST) pBswMModeConditionArgumentRef;
	/**< @brief  Number of mode condition */
	CONST(uint8, BSWM_CONFIG_DATA) BswMModeConditionArgumentCount;
} BswM_LogicalExpressionType;

/**
 * @brief Each instance of this container describes a BswM arbitration rule.
 */
typedef struct
{
	/**< @brief Rule Id*/
	CONST(uint32, BSWM_CONFIG_DATA) BswMRuleId;
	/**< @brief This parameter defines for its related Rule if the Rule is an Independent
	 *          rule or a Subordinate rule; (1)
	 *   @range False - an Independent rule, i.e. to be evaluated each time applicable (both
	 *                 as standalone Rule.
	 *          True  - a Subordinated rule, to be evaluated ONLY as a result of being
	 *                 referenced in one or more Action Lists.
	 */
	CONST(boolean, BSWM_CONFIG_DATA) BswMNestedExecutionOnly;

	/**< @brief This parameter is a part of the reset/initialization behavior of BswM. (1)*/
	CONST(BswM_RuleStateType, BSWM_CONFIG_DATA) BswMRuleInitState;

	/**< @brief This is a reference to the logical expression that is evaluated for each rule. (1)*/
	P2CONST(BswM_LogicalExpressionType, BSWM_CONFIG_DATA, BSWM_APPL_CONST) pBswMRuleExpressionRef;

	/**< @brief This is a reference to the action list that shall be executed when the rule is
	 	 	 	evaluated to False. (0..1)*/
	P2CONST(BswM_ActionListType, BSWM_CONFIG_DATA, BSWM_APPL_CONST) pBswMRuleFalseActionList;

	/**< @brief This is a reference to the action list that shall be executed when the rule is
	            evaluated to True. (0..1)*/
	P2CONST(BswM_ActionListType, BSWM_CONFIG_DATA, BSWM_APPL_CONST) pBswMRuleTrueActionList;
} BswM_RuleType;

/**
 * @brief  This container includes all configuration sub-containers and parameters
 *         related to the mode arbitration functionality of the BswM.
 * @req    ECUC_BswM_00801
 */
typedef struct
{
	/**< @brief This container describes the logical expressions that can be used
	            for the mode arbitration. (0..*)*/
	P2CONST(BswM_LogicalExpressionType, BSWM_CONFIG_DATA, BSWM_APPL_CONST) pBswMLogicalExpression;
	/**< @brief This container describes the BswM mode conditions that can
	            be used either by itself to form a rule or as a part of a logical expression.(0..*)*/
	P2CONST(BswM_ModeConditionType, BSWM_CONFIG_DATA, BSWM_APPL_CONST) pBswMModeCondition;
	/**< @brief Each instance of this container defines a mode request
	 *          interface that is used to requests or indicate modes from/to the BswM.(0..*)*/
	P2CONST(BswM_ModeRequestPortType, BSWM_CONFIG_DATA, BSWM_APPL_CONST) pBswMModeRequestPort;
	/**< @brief Each instance of this container describes a BswM arbitration rule.(0..*)*/
	P2CONST(BswM_RuleType, BSWM_CONFIG_DATA, BSWM_APPL_CONST) pBswMRule;
} BswM_ArbitrationType;

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

#endif /* #ifndef BSWM_ARBITRATIONTYPE_H */
