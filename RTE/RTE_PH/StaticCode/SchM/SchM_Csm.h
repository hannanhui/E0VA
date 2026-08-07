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
**  FILENAME    : SchM_Csm.h                                                  **
**                                                                            **
**  Created on  :                                                             **
**  Author      : yuzhe.zhang                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : implementation header for Csm                               **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
/******************************************************************************
**                      Revision Control History                             **
******************************************************************************/
/*  <VERSION>    <DATE>      <AUTHOR>        <REVISION LOG>
 *  V1.0.0      20200717    yuzhe.zhang      Initial version
 */
#ifndef SCHM_CSM_H
#define SCHM_CSM_H

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
#define CSM_START_SEC_CODE
#include "Csm_MemMap.h"

/**
 * API to be called cyclically to process the requested jobs. The Csm_MainFunction
 * shall check the queues for jobs to pass to the underlying CRYIF.
 * Service ID: 0x01
 * Parameters(IN): NA
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: NA
 */
FUNC(void, CSM_CODE) Csm_MainFunction(void);

#define CSM_STOP_SEC_CODE
#include "Csm_MemMap.h"
#endif
