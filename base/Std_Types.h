/*******************************************************************************
**                  Shanghai ChipON Micro-Electronic Co.,Ltd **
********************************************************************************
*  @File Name       : Std_Types.h
*  @Syntax          : GNU99
*  @Author          : ChipON AE/FAE Group
*  @Date            : 2025-08-29
*  @Version         : V1.0.0_SF
*  @Description     : This document describes the C language document template.
********************************************************************************
*  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
*  All rights reserved.
*
*  This software is copyright protected and proprietary to
*  Shanghai ChipON Micro-Electronic Co.,Ltd.
********************************************************************************
*                        REVISION HISTORY
********************************************************************************
*  |Date        |Version  |Author       |Description
********************************************************************************
*  |2025-08-29  |V1.0     |Zhai Yu     |Initial Version
*******************************************************************************/
#ifndef STD_TYPES_H
#define STD_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"
/*******************************************************************************
 *                                        CONSTANTS
 *******************************************************************************/
/**
 * @brief Physical state 5V or 3.3V
 * @implements DBASE12006
 */
#define STD_HIGH 0x01U

/**
 * @brief Physical state 0V.
 * @implements  DBASE12007
 */
#define STD_LOW 0x00U

/**
 * @brief Logical state active.
 * @implements DBASE12008
 */
#define STD_ACTIVE 0x01U

/**
 * @brief Logical state idle.
 * @implements DBASE12009
 */
#define STD_IDLE 0x00U

/**
 * @brief ON State.
 * @implements DBASE12010
 */
#ifndef STD_ON
#define STD_ON 0x01U
#endif

/**
 * @brief OFF state.
 * @implements DBASE12011
 */
#ifndef STD_OFF
#define STD_OFF 0x00U
#endif

/**
 * @brief Return code for failure/error.
 * @implements DBASE12005
 */
#define E_NOT_OK 0x01U

/********************************************************************************
 *                                        DEFINES AND MACROS
 ********************************************************************************/

/**
 * @brief Because E_OK is already defined within OSEK, the symbol E_OK has to be
 * shared. To avoid name clashes and redefinition problems, the symbols have to
 * be defined in the following way (approved within implementation).
 */
#ifndef STATUSTYPEDEFINED
#define STATUSTYPEDEFINED

#define E_OK 0x00U                /** @brief Success return code  */
typedef unsigned char StatusType; /** @brief This type is defined for OSEK
                                     compliance.  */
#endif

/**
 * @brief This type can be used as standard API return type which is shared
 * between the RTE and the BSW modules.
 * @implements DBASE12002
 */
typedef uint8 Std_ReturnType;

/**
 * @brief This type shall be used to request the version of a BSW module
 * using the "ModuleName"_GetVersionInfo() function.
 * @implements DBASE12003
 */
typedef struct
{
    uint16 vendorID;         /**< @brief vendor ID */
    uint16 moduleID;         /**< @brief BSW module ID */
    uint8  sw_major_version; /**< @brief BSW module software major version */
    uint8  sw_minor_version; /**< @brief BSW module software minor version */
    uint8  sw_patch_version; /**< @brief BSW module software patch version */
} Std_VersionInfoType;

#ifdef __cplusplus
}
#endif

#endif
