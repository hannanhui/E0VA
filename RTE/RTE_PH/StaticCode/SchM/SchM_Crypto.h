/*******************************************************************************
**                                                                            **
** Copyright(C) iSOFT  (2020)                                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : SchM_Crypto.h                                               **
**                                                                            **
**  Created on  :                                                             **
**  Author      : yuhao.ge                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : Implementation for Crypto                                   **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.4.0                       **
**                                                                            **
*******************************************************************************/

/******************************************************************************
**                      Revision Control History                             **
******************************************************************************/
/*  <VERSION>    <DATE>    <AUTHOR>        <REVISION LOG>
 *  V1.0        20200701    yuhao.ge        Initial version*/
#ifndef SCHM_CRYPTO_H
#define SCHM_CRYPTO_H

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
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
/**
 * API to be called cyclically to process the requested jobs. The Csm_MainFunction
 * shall check the queues for jobs to pass to the underlying CRYIF.
 * Service ID: 0x01
 * Parameters(IN): NA
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: NA
 */

FUNC(void, CRY_CODE) Crypto_MainFunction(void);

#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#endif
