/**
 * @file        BswM_Types.h
 * @brief       AUTOSAR BSWM_TYPES - BswM_Types driver header file.
 * @details     BswM_TypesBswM_Types driver header file, containing the Autosar API specification and
 *              other variables and functions that are exported by the BswM_Types driver.
 * @version     1.2.0
 *
 * @addtogroup  BSWM_TYPES
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
#ifndef BSWM_TYPES_H
#define BSWM_TYPES_H

#if defined(__cplusplus)
extern "C" 
{
#endif /* defined(__cplusplus) */

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/

#include "BswM_ArbitrationType.h"
#include "BswM_ModeControlType.h"
#include "BswM_ModeRequestSourceType.h"

/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/

#define BSWM_TYPES_VENDOR_ID                    0U
#define BSWM_TYPES_AR_RELEASE_MAJOR_VERSION     4U
#define BSWM_TYPES_AR_RELEASE_MINOR_VERSION     2U
#define BSWM_TYPES_AR_RELEASE_REVISION_VERSION  2U
#define BSWM_TYPES_SW_MAJOR_VERSION             1U
#define BSWM_TYPES_SW_MINOR_VERSION             2U
#define BSWM_TYPES_SW_PATCH_VERSION             0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/

/* Check if current file and BswM_ArbitrationType header file are of the same vendor */
#if(BSWM_TYPES_VENDOR_ID != BSWM_ARBITRATIONTYPE_VENDOR_ID )
#error "BswM_Types.h and BswM_ArbitrationType.h have different vendor id"
#endif
/* Check if current file and BswM_ArbitrationType header file are of the same Autosar version */
#if(\
		(BSWM_TYPES_AR_RELEASE_MAJOR_VERSION != BSWM_ARBITRATIONTYPE_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_TYPES_AR_RELEASE_MINOR_VERSION != BSWM_ARBITRATIONTYPE_AR_RELEASE_MINOR_VERSION) || \
		(BSWM_TYPES_AR_RELEASE_REVISION_VERSION != BSWM_ARBITRATIONTYPE_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of BswM_Types.h and BswM_ArbitrationType.h are different "
#endif
/* Check if current file and BswM_ArbitrationType header file are of the same software version */
#if(\
		(BSWM_TYPES_SW_MAJOR_VERSION != BSWM_ARBITRATIONTYPE_SW_MAJOR_VERSION) || \
		(BSWM_TYPES_SW_MINOR_VERSION != BSWM_ARBITRATIONTYPE_SW_MINOR_VERSION) || \
		(BSWM_TYPES_SW_PATCH_VERSION != BSWM_ARBITRATIONTYPE_SW_PATCH_VERSION) \
	)
#error "Software Version Number of BswM_Types.h and BswM_ArbitrationType.h are different "
#endif

/* Check if current file and BswM_ModeControlType header file are of the same vendor */
#if(BSWM_TYPES_VENDOR_ID != BSWM_MODECONTROLTYPE_VENDOR_ID )
#error "BswM_Types.h and BswM_ModeControlType.h have different vendor id"
#endif
/* Check if current file and BswM_ModeControlType header file are of the same Autosar version */
#if(\
		(BSWM_TYPES_AR_RELEASE_MAJOR_VERSION != BSWM_MODECONTROLTYPE_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_TYPES_AR_RELEASE_MINOR_VERSION != BSWM_MODECONTROLTYPE_AR_RELEASE_MINOR_VERSION) || \
		(BSWM_TYPES_AR_RELEASE_REVISION_VERSION != BSWM_MODECONTROLTYPE_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of BswM_Types.h and BswM_ModeControlType.h are different "
#endif
/* Check if current file and BswM_ModeControlType header file are of the same software version */
#if(\
		(BSWM_TYPES_SW_MAJOR_VERSION != BSWM_MODECONTROLTYPE_SW_MAJOR_VERSION) || \
		(BSWM_TYPES_SW_MINOR_VERSION != BSWM_MODECONTROLTYPE_SW_MINOR_VERSION) || \
		(BSWM_TYPES_SW_PATCH_VERSION != BSWM_MODECONTROLTYPE_SW_PATCH_VERSION) \
	)
#error "Software Version Number of BswM_Types.h and BswM_ModeControlType.h are different "
#endif

/* Check if current file and BswM_ModeRequestSourceType header file are of the same vendor */
#if(BSWM_TYPES_VENDOR_ID != BSWM_MODEREQUESTSOURCETYPE_VENDOR_ID )
#error "BswM_Types.h and BswM_ModeRequestSourceType.h have different vendor id"
#endif
/* Check if current file and BswM_ModeRequestSourceType header file are of the same Autosar version */
#if(\
		(BSWM_TYPES_AR_RELEASE_MAJOR_VERSION != BSWM_MODEREQUESTSOURCETYPE_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_TYPES_AR_RELEASE_MINOR_VERSION != BSWM_MODEREQUESTSOURCETYPE_AR_RELEASE_MINOR_VERSION) || \
		(BSWM_TYPES_AR_RELEASE_REVISION_VERSION != BSWM_MODEREQUESTSOURCETYPE_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of BswM_Types.h and BswM_ModeRequestSourceType.h are different "
#endif
/* Check if current file and BswM_ModeRequestSourceType header file are of the same software version */
#if(\
		(BSWM_TYPES_SW_MAJOR_VERSION != BSWM_MODEREQUESTSOURCETYPE_SW_MAJOR_VERSION) || \
		(BSWM_TYPES_SW_MINOR_VERSION != BSWM_MODEREQUESTSOURCETYPE_SW_MINOR_VERSION) || \
		(BSWM_TYPES_SW_PATCH_VERSION != BSWM_MODEREQUESTSOURCETYPE_SW_PATCH_VERSION) \
	)
#error "Software Version Number of BswM_Types.h and BswM_ModeRequestSourceType.h are different "
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

/**
 * @brief  Collection of references to DataTypeMappingSet.
 * @req    ECUC_BswM_00936
 */
typedef struct
{
	/**< @brief Reference to DataTypeMappingSet.
	 *   @todo  Not realized for the time being */
	P2CONST(void, BSWM_CONST, RTE_APPL_CONST) pBswMDataTypeMappingSetRef;
} BswM_DataTypeMappingSetsType;

/**
 * @brief  This container contains the configuration parameters and sub containers of
 *         the AUTOSAR BswM module. This container exists once per partition. (1..*)
 * @req    ECUC_BswM_00895
 */
typedef struct
{
	/**< @brief This references the partition the BswM shall run inside.
	 *          Not realized for the time being*/
	P2CONST(void, BSWM_CONST, ECUC_APPL_CONST) pBswMPartitionRef;
	/**< @brief This container includes all configuration sub-containers and
	 *          parameters related to the mode arbitration functionality of the BswM. (1)
	 */
	CONST(BswM_ArbitrationType, BSWM_CONST) BswMArbitration;
	/**< @brief Collection of references to DataTypeMappingSet. (0..1)*/
	P2CONST(BswM_DataTypeMappingSetsType, BSWM_CONST, BSWM_APPL_CONST) pBswMDataTypeMappingSets;
    /**< @brief This container includes all configuration sub-containers and
	 *         parameters related to the mode control functionality of the BswM. (1)
	 */
	CONST(BswM_ModeControlType, BSWM_CONST) BswMModeControl;
} BswM_ConfigType;

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

#endif /* #ifndef BSWM_TYPES_H*/
