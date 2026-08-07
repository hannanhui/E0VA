/**
 * @file        Crc.h
 * @brief       AUTOSAR Crc - Crc driver header file.
 * @details     Crc driver header file, containing the Autosar API specification and
 *              other variables and functions that are exported by the Crc driver.
 * @version     1.2.0
 *
 * @addtogroup  CRC
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
#ifndef CRC_H_
#define CRC_H_
#ifdef __cplusplus
extern "C"{
#endif
/*====================================================================================================*
 *                                         INCLUDE FILES
 *====================================================================================================*/
#include "Crc_Cfg.h"
#include "Std_Types.h"
/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/
#define CRC_MODULE_ID                     201U
#define CRC_VENDOR_ID                     0U
#define CRC_AR_RELEASE_MAJOR_VERSION      4U
#define CRC_AR_RELEASE_MINOR_VERSION      2U
#define CRC_AR_RELEASE_REVISION_VERSION   2U
#define CRC_SW_MAJOR_VERSION              1U
#define CRC_SW_MINOR_VERSION              2U
#define CRC_SW_PATCH_VERSION              0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/

/* Check if current file and Crc_Cfg header file are of the same vendor */
#if(CRC_VENDOR_ID != CRC_CFG_VENDOR_ID )
#error "Crc.h and Crc_Cfg.h have different vendor id"
#endif
/* Check if current file and Crc_Cfg header file are of the same Autosar version */
#if(\
		(CRC_AR_RELEASE_MAJOR_VERSION != CRC_CFG_AR_RELEASE_MAJOR_VERSION) || \
		(CRC_AR_RELEASE_MINOR_VERSION != CRC_CFG_AR_RELEASE_MINOR_VERSION) || \
		(CRC_AR_RELEASE_REVISION_VERSION != CRC_CFG_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of Crc.h and Crc_Cfg.h are different "
#endif
/* Check if current file and Crc_Cfg header file are of the same software version */
#if(\
		(CRC_SW_MAJOR_VERSION != CRC_CFG_SW_MAJOR_VERSION) || \
		(CRC_SW_MINOR_VERSION != CRC_CFG_SW_MINOR_VERSION) || \
		(CRC_SW_PATCH_VERSION != CRC_CFG_SW_PATCH_VERSION) \
	)
#error "Software Version Number of Crc.h and Crc_Cfg.h are different "
#endif

#ifndef DISABLE_INTERMOD_VERSION_CHECK
/* Check if current file and Std_Types header file are of the same Autosar version */
#if(\
		(CRC_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
		(CRC_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)  \
	)
#error "AutoSar Version Number of Crc.h and Std_Types.h are different "
#endif
#endif /* #ifndef DISABLE_INTERMOD_VERSION_CHECK */
/*====================================================================================================*
 *                                             CONSTANTS
 *====================================================================================================*/

/*====================================================================================================*
 *                                         DEFINES AND MACROS
 *====================================================================================================*/
/**
 * @req [SWS_Crc_00017] If source code for caller and callee of the function Crc_GetVersionInfo is
 *      available, the CRC module should realize this function as a macro, defined in the modules
 *      header file
 */
/* PRQA S 3412 EOF# violate MISRA_2004_Rule_19.4: Simple replacement of macro function parameters*/
#define CRC_GETVERSIONINFO(Versioninfo)  do{Crc_GetVersionInfo(Versioninfo);}while(0);
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
#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
#if(STD_ON == CRC8_ALGORITHM)
extern FUNC(uint8, CRC_CODE) Crc_CalculateCRC8
(
	P2CONST(uint8, AUTOMATIC, CRC_APPL_DATA) Crc_DataPtr,
	VAR(uint32,AUTOMATIC) Crc_Length,
	VAR(uint8,AUTOMATIC) Crc_StartValue8,
	VAR(boolean,AUTOMATIC) Crc_IsFirstCall
);
#endif/* STD_ON == CRC8_ALGORITHM */

#if(STD_ON == CRC8H2F_ALGORITHM)
extern FUNC(uint8, CRC_CODE) Crc_CalculateCRC8H2F
(
	P2CONST(uint8, AUTOMATIC, CRC_APPL_DATA) Crc_DataPtr,
	VAR(uint32,AUTOMATIC) Crc_Length,
	VAR(uint8,AUTOMATIC)  Crc_StartValue8H2F,
	VAR(boolean,AUTOMATIC) Crc_IsFirstCall
);
#endif/* STD_ON == CRC8H2F_ALGORITHM */

#if(STD_ON == CRC16_ALGORITHM)
extern FUNC(uint16, CRC_CODE) Crc_CalculateCRC16
(
	P2CONST(uint8, AUTOMATIC, CRC_APPL_DATA) Crc_DataPtr,
	VAR(uint32,AUTOMATIC) Crc_Length,
	VAR(uint16,AUTOMATIC) Crc_StartValue16,
	VAR(boolean,AUTOMATIC) Crc_IsFirstCall
);
#endif/* STD_ON == CRC16_ALGORITHM */

#if(STD_ON == CRC32_ALGORITHM)
extern FUNC(uint32, CRC_CODE) Crc_CalculateCRC32
(
	P2CONST(uint8, AUTOMATIC, CRC_APPL_DATA) Crc_DataPtr,
	VAR(uint32,AUTOMATIC) Crc_Length,
	VAR(uint32,AUTOMATIC) Crc_StartValue32,
	VAR(boolean,AUTOMATIC) Crc_IsFirstCall
);
#endif/* STD_ON == CRC32_ALGORITHM */

#if(STD_ON == CRC32P4_ALGORITHM)
extern FUNC(uint32, CRC_CODE) Crc_CalculateCRC32P4
(
	P2CONST(uint8, AUTOMATIC, CRC_APPL_DATA) Crc_DataPtr,
	VAR(uint32,AUTOMATIC) Crc_Length,
	VAR(uint32,AUTOMATIC) Crc_StartValue32,
	VAR(boolean,AUTOMATIC) Crc_IsFirstCall
);
#endif/* STD_ON == CRC32P4_ALGORITHM */
FUNC(void, CRC_CODE) Crc_GetVersionInfo( P2VAR(Std_VersionInfoType, CRC_CODE, AUTOMATIC) Versioninfo );
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* !defined CRC_H */
/** @} */
