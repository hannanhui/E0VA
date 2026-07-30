/**
 * @file        BM.h
 * @brief       AUTOSAR BM - BM driver header file.
 * @details     BM driver header file, containing the Autosar API specification and
 *               other variables and functions that are exported by the BM driver.
 * @version     1.0.0
 *
 * @addtogroup  BM
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

#ifndef BM_H
#define BM_H

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/

#include "FBL.h"
#include "BM_Cfg.h"
#include "Z20K144M.h"
#include "int_drv.h"
extern void INT_All_Enable (uint8_t NewState);

/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/

/**
* @brief Parameters that shall be published within the BM driver header file and also in the
*        module's description file
*/
#define BM_VENDOR_ID                    xx
#define BM_MODULE_ID                    xx
#define BM_AR_RELEASE_MAJOR_VERSION     xx
#define BM_AR_RELEASE_MINOR_VERSION     xx
#define BM_AR_RELEASE_REVISION_VERSION  xx
#define BM_SW_MAJOR_VERSION             xx
#define BM_SW_MINOR_VERSION             xx
#define BM_SW_PATCH_VERSION             xx

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                             CONSTANTS
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                         DEFINES AND MACROS
 *====================================================================================================*/

/** type for  U32 Data. */
typedef uint32 BM_U32DataType;

/** type for  U32 Time. */
typedef uint32 BM_U32TimeType;

/** type for Flash read Length */
typedef uint32 BM_LengthType;

/** type for Flash Check Parameter */
typedef uint8 BM_CheckParameterType;

/** type for Block Index */
typedef uint8 BM_BlockIndexType;

/** type for Gpt Flag */
typedef boolean BM_GptFlagType;

/** type for DATA Buffer */
typedef uint8 BM_DtatBufferType;

/** type for EEPROM Data */
typedef uint8 BM_EepromDataType;

/** type for DCM Session Data */
typedef uint8 BM_DcmSesDataType;

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
extern uint8 APP_Jump;
/**
 * @brief  The active security level of this module.
 */
extern VAR(Dcm_SecLevelType,DCM_VAR)Dcm_ActiveSec;

/**
 * @brief  The active session status of this module.
 */
extern VAR(Dcm_SecLevelType,DCM_VAR)Dcm_ActiveSes;

/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES
 *====================================================================================================*/

FUNC(void,AUTOMATIC) BM_InitEcu(void);

FUNC(void,AUTOMATIC) BM_DeInit(void);

FUNC(void,AUTOMATIC) BM_CheckEcuDownload(void);

FUNC(void,AUTOMATIC) BM_EnterApp(void);

#ifdef __cplusplus
}
#endif

#endif /* BM_H */
/** @} */
