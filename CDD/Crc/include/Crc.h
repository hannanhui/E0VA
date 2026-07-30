/** @file Crc.h
 *  @brief AUTOSAR CRC
 *  @details realize AUTOSAR CRC all external interface
 *  @version 1.0.0
 *
 *  @par Module Information
 *  |          Module          |            Version           |
 *  |--------------------------|------------------------------|
 *  |         Compiler         |               /      		  |
 *  |           CRC            |         	   /              |
 *  |     AUTOSAR Version      |             4.2.2            |
 *  |      Model Information   |              CRC             |
 *  |   Hardware Dependencies  |               /              |
 *
 *  @par amendment
 *  |    Date    |    Author   |         Description          |
 *  |------------|-------------|----------------------------- |
 *  | 2023-10-27 |      WP     |        Create this file      |
 *
 *  @addtogroup CRC
 *  @{
 */
/*==================================================================================================*
 *  Sword AUTOSAR MCAL                                                                   			*
 *  Copyright(C) 2022 ZhongKeAngHui Inc                                                  			*
 *  All Rights Reserved.                                                                 			*
 *  This file is part of SWORD-AUTOSAR.                                                  			*
*===================================================================================================*/
#ifndef CRC_H_
#define CRC_H_
#ifdef __cplusplus
extern "C"{
#endif
/*==================================================================================================*
 *                                         INCLUDE FILES
 * 1) system and project includes
 * 2) needed interfaces from external units
 * 3) internal and external interfaces from this unit
 *==================================================================================================*/
#include "Crc_Cfg.h"
#include "Std_Types.h"
//#include "Compiler.h"

/*================================================================================================*
 *                             SOURCE FILE VERSION INFORMATION
 *================================================================================================*/
#define CRC_MODULE_ID                     201
#define CRC_VENDOR_ID                     62
#define CRC_AR_RELEASE_MAJOR_VERSION      4
#define CRC_AR_RELEASE_MINOR_VERSION      2
#define CRC_AR_RELEASE_REVISION_VERSION   2
#define CRC_SW_MAJOR_VERSION              1
#define CRC_SW_MINOR_VERSION              0
#define CRC_SW_PATCH_VERSION              0

/*================================================================================================*
 *                                    FILE VERSION CHECKS
 *================================================================================================*/
/*Add code here*/
/*================================================================================================*
 *                                         CONSTANTS
 *================================================================================================*/
/*Add code here*/
/*================================================================================================*
 *                                         DEFINES AND MACROS
 *================================================================================================*/
/*Add code here*/
/*================================================================================================*
 *                                             ENUMS
 *================================================================================================*/
/*Add code here*/
/*================================================================================================*
 *                                STRUCTURES AND OTHER TYPEDEFS
 *================================================================================================*/
/*Add code here*/
/*==================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS
 *==================================================================================================*/
/* Add code here */
/*==================================================================================================*
 *                                       FUNCTION PROTOTYPES
 *==================================================================================================*/
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
/* req<SWS_Crc_00043>*/
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
//FUNC(void, CRC_CODE) Crc_GetVersionInfo( P2VAR(Std_VersionInfoType, CRC_CODE, AUTOMATIC) Versioninfo );
#endif/* CRC_H_ */

#ifdef __cplusplus
}
#endif
/** @} */
