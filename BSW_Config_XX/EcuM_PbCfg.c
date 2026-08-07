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
**  FILENAME    : EcuM_PbCfg.c                                                **
**                                                                            **
**  Created on  : 2025/02/07 16:03:34                                         **
**  Author      :                                                             **
**  Vendor      :                                                             **
**  DESCRIPTION :  Configuration constant variables for pre-compile           **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19_11                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "EcuM.h"
#include "Dem.h"
#include "CanSM.h"
#include "CanNm.h"
#include "CanTp.h"
#include "Nm.h"
#include "PduR.h"
#include "Com.h"
#include "ComM.h"

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
#define ECUM_START_SEC_PBCFG_GLOBALROOT
#include "EcuM_MemMap.h"
CONST(EcuM_GenBSWPbCfgType, ECUM_VAR_NO_INIT) EcuM_GenMcalConfig =
{
    NULL_PTR, /*bswmPbCfg*/
    (void *)&CanSM_Config,
    (void *)&CanNm_Config,
    (void *)&CanTp_Config,
    (void *)&Nm_Config,
    (void *)&PduR_PBConfigData,
    (void *)&Com_PBConfigData,
    (void *)&ComM_Config,
};
CONST(EcuM_ConfigType, ECUM_VAR_NO_INIT) EcuM_Config =
{
    0,    /*EcuMConfigConsistencyHash*/
    0,    /*EcuMDefaultAppMode*/
    ECUM_SHUTDOWN_TARGET_OFF,
    0,
    &EcuM_GenMcalConfig
};
#define ECUM_STOP_SEC_PBCFG_GLOBALROOT
#include "EcuM_MemMap.h"

/*******************************************************************************
**                            General Notes                                   **
*******************************************************************************/

