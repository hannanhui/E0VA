/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2020)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : SchM_StbM.h                                                 **
**                                                                            **
**  Created on  :                                                             **
**  Author      : yuzhe.zhang                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : implementation header for StbM                              **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
/******************************************************************************
**                      Revision Control History                             **
******************************************************************************/
#ifndef SCHM_STBM_H
#define SCHM_STBM_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
#define STBM_START_SEC_CODE
#include "StbM_MemMap.h"

/**
 * This function will be called cyclically by a task body provided by the BSW Schedule.
   It will invoke the triggered customers and synchronize the referenced OS Schedule Tables.
 * Service ID: 0x04
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters(IN): NA
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value:    NA
 */
FUNC(void, STBM_CODE) StbM_MainFunction(void);

#define STBM_STOP_SEC_CODE
#include "StbM_MemMap.h"

#define SchM_Enter_StbM()
#define SchM_Exit_StbM()

#endif
