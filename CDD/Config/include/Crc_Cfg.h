/**
* @file        Crc_Cfg.h
* @brief       Precompile configuration file for Crc module.
*
* @par         Module information
* |          Module          |          Version             |
* |--------------------------|------------------------------|
* |            Crc           |             /                |
* |       AUTOSAR Version    |           4.2.2              |
* |      Model Information   |            Crc               |
* |   Hardware Dependencies  |            Crc               |
*
* @addtogroup Crc
* @{
*/
/*=================================================================================================*
* Sword AUTOSAR MCAL.
* Copyright(C) 2023 ZhongKeAngHui Inc.
* All Rights Reserved.
* This file is part of SWORD-ATUOSAR.
*=================================================================================================*/

#ifndef CRC_CFG_H_
#define CRC_CFG_H_

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/


/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
                                        DEFINES AND MACROS
==================================================================================================*/
/* calculation method of Crc mode */
#define CRC_HARDWARE  0
#define CRC_RUNTIME   1
#define CRC_TABLE     2

/* CRC8 (SAE J1850) algorithm calculation switch */
#define CRC8_ALGORITHM             STD_OFF

/* CRC8 (2Fh polynomial) algorithm calculation switch */
#define CRC8H2F_ALGORITHM          STD_OFF

/* CRC16 (CCITT) algorithm calculation switch */
#define CRC16_ALGORITHM            STD_OFF

/* CRC32 (Ethernet) algorithm calculation switch */
#define CRC32_ALGORITHM            STD_ON

/* CRC32 (0xF4ACFB13 polynomial) algorithm calculation switch */
#define CRC32P4_ALGORITHM          STD_OFF

/* Switch to select one of the available CRC 8-bit (SAE J1850) calculation methods*/
#define CRC_8_MODE                 CRC_TABLE

/* Switch to select one of the available CRC 8-bit (2Fh polynomial) calculation methods*/
#define CRC_8H2F_MODE              CRC_TABLE

/* Switch to select one of the available CRC 16-bit (CCITT) calculation methods*/
#define CRC_16_MODE                CRC_TABLE

/* Switch to select one of the available CRC 32-bit (IEEE-802.3 CRC32 Ethernet Standard) calculation methods*/
#define CRC_32_MODE                CRC_TABLE

/* Switch to select one of the available CRC 32-bit E2E Profile 4 calculation methods*/
#define CRC_32P4_MODE              CRC_TABLE
/*==================================================================================================
                                    STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                     GLOBAL CONSTANT DECLARATIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif



