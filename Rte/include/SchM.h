/**
 * @file        SchM.h
 * @brief       AUTOSAR SchM - SchM driver header file.
 * @details     SchM driver header file, containing the Autosar API specification and other variables
 *              and functions that are exported by the SchM driver.
 * @version     1.0.0
 * @author      SXY
 *
 * @par         Module information
 * |        Module         |     Version     |
 * |-----------------------|-----------------|
 * |          SchM         |        /        |
 * |    AUTOSAR Version    |      4.2.2      |
 * |  Module Information   |       SchM      |
 * | Hardware Dependencies |        /        |
 *
 * @par         History
 * |    Data    | Author |   Description    |
 * |------------|--------|------------------|
 * | 2023-10-30 |  SXY   | Create this file |
 *
 * @addtogroup  RTE
 * @{
 */
/*=================================================================================================*
 * Sword AUTOSAR RTE.
 * Copyright(C) 2023 ZhongKeAngHui Inc.
 * All Rights Reserved.
 * This file is part of SWORD-ATUOSAR.
 *=================================================================================================*/
#ifndef SCHM_H
#define SCHM_H

#ifdef __cplusplus
extern "C"{
#endif

/*=================================================================================================*
 *                                           INCLUDE FILES
 *=================================================================================================*/

#include "Std_Types.h"
//#include "Rte_Cfg.h"

/*=================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION
 *=================================================================================================*/

#define SCHM_VENDOR_ID                       0U
#define SCHM_MODULE_ID                       2U
#define SCHM_AR_RELEASE_MAJOR_VERSION        4U
#define SCHM_AR_RELEASE_MINOR_VERSION        2U
#define SCHM_AR_RELEASE_REVISION_VERSION     2U
#define SCHM_SW_MAJOR_VERSION                1U
#define SCHM_SW_MINOR_VERSION                0U
#define SCHM_SW_PATCH_VERSION                0U

/*=================================================================================================*
 *                                         FILE VERSION CHECKS
 *=================================================================================================*/

/* Add code here */

/*=================================================================================================*
 *                                             CONSTANTS
 *=================================================================================================*/

/* Add code here */

/*=================================================================================================*
 *                                         DEFINES AND MACROS
 *=================================================================================================*/

/**
 * @brief API service ID for SchM_Init function
 */
#define SCHM_INIT_ID                                 ((uint8)0x00U)

/**
 * @brief API service ID for SchM_Deinit function
 */
#define SCHM_DEINIT_ID                               ((uint8)0x01U)

/**
 * @brief API service ID for SchM_GetVersionInfo function
 */
#define SCHM_GETVERSIONINFOR_ID                      ((uint8)0x02U)

/**
 * @brief   No error occurred.
 */
#define SCHM_E_OK                                    ((uint8)0U)

/**
 * @brief   A internal Basic Software Scheduler limit has been exceeded.
 */
#define SCHM_E_LIMIT                                 ((uint8)130U)

/**
 * @brief   An explicit read API call returned no data.
 */
#define SCHM_E_NO_DATA                               ((uint8)131U)

/**
 * @brief   Transmission acknowledgement received.
 */
#define SCHM_E_TRANSMIT_ACK                          ((uint8)132U)

/**
 * @brief   The error is returned by a blocking API and indicates that the schedulable entity
 *          could not enter a wait state,
 */
#define SCHM_E_IN_EXCLUSIVE_AREA           		     ((uint8)135U)

/**
 * @brief   The configured timeout exceeds before the intended result was ready.
 */
#define SCHM_E_TIMEOUT                    			 ((uint8)129U)

/**
 * @brief  input parameter is invalid
 */
#define RTE_E_DET_ILLEGAL_VARIANT_CRITERION_VALUE    ((uint8)0x02U)

/**
 * @brief  Indicates an uninitialized error ID in a development error.
 */
#define RTE_E_DET_UNINIT                             ((uint8)0x07U)

/**
 * @brief  Developing the error switch identifier.
 */
#define SCHM_DEV_ERROR_DETECT                        (RTE_DEV_ERROR_DETECT)
#define SCHM_VALIDATE_GLOBAL_CALL                    (RTE_DEV_ERROR_DETECT_UNINIT)
#define SCHM_PARAM_CHECK						     (SCHM_DEV_ERROR_DETECT)

/*=================================================================================================*
 *                                               ENUMS
 *=================================================================================================*/

/**
 * @brief Definition of the enumeration type representing the current state of the SchM module.
 */
typedef enum
{
	/**< @brief indicates the uninitialized state */
	SCHM_UINIT = 0U,
	/**< @brief indicates initialization status  */
	SCHM_INIT

}SchM_StateType;

/*=================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS
 *=================================================================================================*/
/**
 * @brief Bsw uses Alarm's configuration struct.
 */
typedef struct
{
	/**< @brief ID indicating the current alarm */
	uint16  AlarmId;
	/**< @brief Relative to the current first alarm time */
	uint32  AlarmIncrement;
	/**< @brief Indicates the cycle period of the current alarm */
	uint32  CycleTime;

}SchM_AlarmCfgType;

/**
 * @brief Bsw uses ScheduleTable's configuration struct.
 */
typedef struct
{
	/**< @brief ID indicating the current ScheduleTable */
	uint16  ScheduleTableId;
	/**< @brief Number of ticks on the counter before the schedule table processing is started */
	uint32  Offset;

}SchM_ScheduleTableCfgType;

/**
 * @brief Configuration struct of SchM.
 */
typedef struct
{
	/**< @brief The total number of Alarms used by Bsw.*/
	uint16 AlarmNum;

	/**< @brief Bsw uses Alarm collection .*/
	const SchM_AlarmCfgType*  AlarmCfg;
}SchM_ConfigType;

/*=================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS
 *=================================================================================================*/

/*=================================================================================================*
 *                                        FUNCTION PROTOTYPES
 *=================================================================================================*/

void SchM_Init(const SchM_ConfigType* ConfigPtr);
void SchM_Deinit(void);
#if (RTE_SCHM_VERSION_INFO_API == STD_ON)
void SchM_GetVersionInfo(Std_VersionInfoType* versioninfo);
#endif

#ifdef __cplusplus
}
#endif

#endif /* SCHM_H */
/** @} */
