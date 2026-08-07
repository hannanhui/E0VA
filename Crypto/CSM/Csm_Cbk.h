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
**  FILENAME    : Csm_Cbk.H                                                   **
**                                                                            **
**  Created on  :                                                             **
**  Author      : qinchun.yang                                                **
**  Vendor      :                                                             **
**  DESCRIPTION : implementation call-back header for CSM                     **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
/******************************************************************************
**                      Revision Control History                             **
******************************************************************************/
/*  <VERSION>      <DATE>        <AUTHOR>        <REVISION LOG>
 *    V1.0.0      2019-10-18    qinchun.yang     Initial version
 *    V1.1.0      2020-07-16    yuzhe.zhang      R19-11
 *    V2.0.0      2023-02-06    jie.gu           R19_11
 */
#ifndef CSM_CBK_H
#define CSM_CBK_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Csm.h"
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
#define CSM_START_SEC_CBK_NOTIFICATION_CODE
#include "Csm_MemMap.h"
/**
 * Notifies the CSM that a job has finished. This function is used by the
 * underlying layer (CRYIF).
 * Variation: {ecuc(Csm/CsmJob/CsmJobUsePort == false)} &&
 * {ecuc(Csm/CsmJobs/CsmJob.CsmJobPrimitiveRef- >CsmPrimitives/{Primitive}Config/
 * {Primitive}Processing == CRYPTO_PROCESSING_ASYNC)}
 * Service ID: 0x70
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters(IN):
 *     @job, Holds a pointer to the job, which has finished.
 *     @result, Contains the result of the cryptographic operation
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: NA
 */
FUNC(void, CSM_CBK_NOTIFICATION_CODE)
Csm_CallbackNotification(
    P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_DATA) job,
    VAR(Crypto_ResultType, CSM_APPL_DATA) result);
#define CSM_STOP_SEC_CBK_NOTIFICATION_CODE
#include "Csm_MemMap.h"
#endif /* CSM_CBK_H */
