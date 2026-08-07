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
**  FILENAME    : Crypto_Alg.c                                                       **
**                                                                            **
**  Created on  :                                                             **
**  Author      : yuhao.ge                                                **
**  Vendor      :                                                             **
**  DESCRIPTION : Implementation for Crypto                                   **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.4.0                       **
**                                                                            **
*******************************************************************************/
#ifndef CRYPTO_ALG_H
#define CRYPTO_ALG_H
/******************************************************************************
**                      Revision Control History                             **
******************************************************************************/
/*  <VERSION>    <DATE>    <AUTHOR>        <REVISION LOG>
 *  V1.0     20200701    yuhao.ge    Initial version
 */

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "Det.h"
#include "Crypto.h"
#include "Crypto_Types.h"
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

#define CRYPTO_KEY_VALID (0x01U)
/** @brief  Indicate that key is not valid */
#define CRYPTO_KEY_NOT_VALID (0x00U)

#define CRYPTO_JOB_NOT_VALID (0xffffU)

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/
#if (CRYPTO_MAXKEY_CONFIGURED > 0)
/*Enumeration of the current Key state*/
typedef enum
{
    CRYPTO_KEYSTATE_INVALID = 0x00u, /*Job is in the state "Valid".*/
    CRYPTO_KEYSTATE_VALID = 0x01u    /*Job is in the state "Invalid".*/
} Crypto_KeyStateType;
#endif /* CRYPTO_MAXKEY_CONFIGURED > 0 */
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRY_CODE)
Crypto_KeyElementIndexFind(
    VAR(uint32, AUTOMATIC) cryptokeyId,
    VAR(uint32, AUTOMATIC) keyElementId,
    P2VAR(uint32, AUTOMATIC, CRY_APPL_DATA) getkeyElementId);
FUNC(uint32, CRY_CODE) Crypto_KeyIndexFind(VAR(uint32, AUTOMATIC) cryptokeyId);
FUNC(Std_ReturnType, CRY_CODE)
Get_Key(
    VAR(uint32, AUTOMATIC) cryptoKeyId,
    P2VAR(uint8, AUTOMATIC, CRY_APPL_DATA) key,
    VAR(uint8, AUTOMATIC) keyelementid);
FUNC(void, CRY_CODE) Crypto_memcpy(void* buf, const void* buf1, uint32 len);
FUNC(void, CRY_CODE) Crypto_memset(void* buf, uint32 len);
FUNC(void, CRY_CODE) Crypto_memsetVal(void* buf, uint8 val, uint32 len);
FUNC(Std_ReturnType, CRY_CODE)
Crypto_KeyElementSetInternal(
    uint32 cryptokeyId,
    uint32 keyElementId,
    P2CONST(uint8, AUTOMATIC, CSM_APPL_DATA) keyPtr,
    uint32 keyLength);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"
#endif
