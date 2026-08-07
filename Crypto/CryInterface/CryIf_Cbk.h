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
**  FILENAME    : CryIf_Cbk.h                                                 **
**                                                                            **
**  Created on  :                                                             **
**  Author      : yuzhe.zhang                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : implementation call-back header for CryIf                   **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
#ifndef CRYIF_CBK_H
#define CRYIF_CBK_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "CryIf.h"
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
#define CRYIF_START_SEC_CBK_NOTIFICATION_CODE
#include "CryIf_MemMap.h"
/**
 * Notifies the CRYIF about the completion of the request with the result of the cryptographic operation.
 * Service ID: 0x70
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters(IN):
 *     @job, Points to the completed job's information structure. It contains a callbackID
 * to identify which job is finished.
 *     @result, Contains the result of the cryptographic operation
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: NA
 */
FUNC(void, CSM_CBK_NOTIFICATION_CODE)
CryIf_CallbackNotification(
    P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_DATA) job,
    VAR(Crypto_ResultType, CSM_APPL_DATA) result);
#define CRYIF_STOP_SEC_CBK_NOTIFICATION_CODE
#include "CryIf_MemMap.h"

#endif /* CryIf_CBK_H */
