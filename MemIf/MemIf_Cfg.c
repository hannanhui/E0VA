/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2022)                                               **
**                                                                            **
** All rights reserved.                                                       **
 **                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : MemIf_Cfg.c                                                 **
**                                                                            **
**  Created on  : 2025/02/07 16:03:34                                         **
**  Author      :                                                             **
**  Vendor      : isoft                                                       **
**  DESCRIPTION : MemIf pre compile globle macro define                       **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "MemIf_Cfg.h"
//#include "Fee.h"

/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/

#define MEMIF_START_SEC_CONST_UNSPECIFIED
#include "MemIf_MemMap.h"
CONST(MemIf_MemHwAApi_Type, MEMIF_CONST) MemIf_MemHwaApis_at[MEMIF_NUMBER_OF_DEVICES] =
{

    {
        /* Device SetMode Operation API */
        0,
        /* Device Read operation API */
        0,
        /* Device Write operation API */
        0,
        /* Device Erase Immediate operation API */
        0,
        /* Device Invalidate operation API */
        0,
        /* Device Cancel operation API */
        0,
        /* Device GetStatus operation API */
        0,
        /* Device GetJobResult operation API */
        0
    },
};

#define MEMIF_STOP_SEC_CONST_UNSPECIFIED
#include "MemIf_MemMap.h"
