/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : MemIf_Types.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2025-08-29
 *  @Version         : V1.0.0_SF
 *  @Description     : This document describes the C language document template.
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 ******************************************************************************
 *                        REVISION HISTORY
 ******************************************************************************
 *  |Date        |Version  |Author       |Description
 ******************************************************************************
 *  |2025-08-29  |V1.0     |Wang Ning    |New creat
 *****************************************************************************/
#ifndef MEMIF_TYPES_H
#define MEMIF_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      Include Files                                          *
 ******************************************************************************/
#include "Std_Types.h"

/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/

/**
 * @brief A memory hardware abstraction module's state is denoted in this type.
 * Mainly used in MemIf_GetStatus and related APIs of memory hardware
 * abstraction modules.
 *
 */
typedef enum
{
    MEMIF_UNINIT = 0,
    MEMIF_IDLE,
    MEMIF_BUSY,
    MEMIF_BUSY_INTERNAL
} MemIf_StatusType;

/**
 * @brief A requested job can have one these values after it has been
 * processed. Use in MemIf_GetJobResult and related memory
 * hardware abstraction module APIs.
 */
typedef enum
{
    MEMIF_JOB_OK = 0,
    MEMIF_JOB_FAILED,
    MEMIF_JOB_PENDING,
    MEMIF_JOB_CANCELED,
    MEMIF_BLOCK_INCONSISTENT,
    MEMIF_BLOCK_INVALID
} MemIf_JobResultType;

/**
 * @brief Specifies the processing speed of requested jobs. The exact
 * processing duration in the different modes depends on
 * configuration of the underlying memory hardware abstraction
 * modules.
 */
typedef enum
{
    MEMIF_MODE_SLOW = 0,
    MEMIF_MODE_FAST
} MemIf_ModeType;

/* data pointer for API */
#if 0
typedef P2VAR(uint8, AUTOMATIC, MEMIF_APPL_DATA) MemIf_DataPtr_pu8;
typedef P2CONST(uint8, AUTOMATIC, MEMIF_APPL_DATA) MemIf_ConstDataPtr_pu8;
#endif

/******************************************************************************
 **                        Export Variables
 ******************************************************************************/

/******************************************************************************
 **                        Export Functions
 ******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif
/* EOF */
