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
**  FILENAME    : Crypto_internal.c                                           **
**                                                                            **
**  Created on  :                                                             **
**  Author      : yuzhe.zhang                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : Implementation for Crypto                                   **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

/******************************************************************************
**                      Revision Control History                             **
******************************************************************************/
/*  <VERSION>    <DATE>    <AUTHOR>        <REVISION LOG>
 *  V1.0        20200701  yuzhe.zhang      Initial version
 */
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Crypto_internal.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/*report DET error*/
#define Crypto_ReportDetErr(serviceId, error) \
    Det_ReportError(CRYPTO_MODULE_ID, CRYPTO_MODULE_INSTANCE_ID, (serviceId), (error));

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
#define CRYPTO_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Crypto_MemMap.h"
extern VAR(Crypto_KeyCfgType, AUTOMATIC) Crypto_Key[CRYPTO_MAXKEY_CONFIGURED];
#define CRYPTO_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Crypto_MemMap.h"
#define CRYPTO_START_SEC_VAR_CLEARED_8
#include "Crypto_MemMap.h"
extern VAR(Crypto_KeyStateType, CRY_VAR) CryptoKeyStatus[CRYPTO_MAXKEY_CONFIGURED];
#define CRYPTO_STOP_SEC_VAR_CLEARED_8
#include "Crypto_MemMap.h"

#endif
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
#if (CRYPTO_MAXKEY_CONFIGURED > 0)
/*Find Key Element index*/

FUNC(Std_ReturnType, CRY_CODE)
Crypto_KeyElementIndexFind(
    VAR(uint32, AUTOMATIC) cryptokeyId,
    VAR(uint32, AUTOMATIC) keyElementId,
    P2VAR(uint32, AUTOMATIC, CRY_APPL_DATA) getkeyElementId)
{
    uint32 i;
    Std_ReturnType ret = E_NOT_OK;
#if (CRYPTO_DEV_ERROR_DETECT == STD_ON)
    /*@req SWS_Crypto_00076*/
    if (cryptokeyId >= CRYPTO_MAXKEY_CONFIGURED)
    {
        Crypto_ReportDetErr(CRYPTO_SID_KEYELEMENTSET, CRYPTO_E_PARAM_HANDLE);
    }
    else
#endif /* CRYPTO_DEV_ERROR_DETECT == STD_ON */
    {
        /*Find Key space */
        for (i = 0; i < Crypto_Key[cryptokeyId].CryptoKeyTypeRef->KeyElementNum; i++)
        {
            if (Crypto_Key[cryptokeyId].CryptoKeyTypeRef->CryptoKeyElementRef[i].CryptoKeyElementId == keyElementId)
            {
                *getkeyElementId = i;
                ret = E_OK;
                break;
            }
        }
#if (CRYPTO_DEV_ERROR_DETECT == STD_ON)
        /*@req SWS_Crypto_00076*/
        if (E_OK != ret)
        {
            Crypto_ReportDetErr(CRYPTO_SID_KEYELEMENTSET, CRYPTO_E_PARAM_HANDLE);
        }
#endif /* CRYPTO_DEV_ERROR_DETECT == STD_ON */
    }
    return ret;
}

FUNC(Std_ReturnType, CRY_CODE)
Get_Key(
    VAR(uint32, AUTOMATIC) cryptoKeyId,
    P2VAR(uint8, AUTOMATIC, CRY_APPL_DATA) key,
    VAR(uint8, AUTOMATIC) keyelementid)
{
    Std_ReturnType ret = E_NOT_OK;
    uint16 i;
    uint32 KeyElementIndex;
    ret = Crypto_KeyElementIndexFind(cryptoKeyId, keyelementid, &KeyElementIndex);
    if (E_OK == ret)
    {
        if ((CryptoKeyStatus[cryptoKeyId] == CRYPTO_KEYSTATE_VALID))
        {
            for (i = 0;
                 i
                 < Crypto_Key[cryptoKeyId].CryptoKeyTypeRef->CryptoKeyElementRef[KeyElementIndex].CryptoKeyElementSize;
                 i++)
            {
                key[i] = Crypto_Key[cryptoKeyId]
                             .CryptoKeyTypeRef->CryptoKeyElementRef[KeyElementIndex]
                             .CryptoKeyElementInitValue[i];
            }
        }
        else
        {
            ret = CRYPTO_E_KEY_READ_FAIL;
        }
    }
    return ret;
}

FUNC(Std_ReturnType, CRY_CODE)
Crypto_KeyElementSetInternal(
    uint32 cryptokeyId,
    uint32 keyElementId,
    P2CONST(uint8, AUTOMATIC, CSM_APPL_DATA) keyPtr,
    uint32 keyLength)
{
    Std_ReturnType Status = E_NOT_OK;
    uint32 KeyElementIndex;
    uint16 Index;

    Status = Crypto_KeyElementIndexFind(cryptokeyId, keyElementId, &KeyElementIndex);

    if (E_OK == Status)
    {
        Status = E_NOT_OK;
        if (keyLength
            <= Crypto_Key[cryptokeyId].CryptoKeyTypeRef->CryptoKeyElementRef[KeyElementIndex].CryptoKeyElementSize)
        {
            for (Index = 0; Index < keyLength; Index++)
            {
                Crypto_Key[cryptokeyId]
                    .CryptoKeyTypeRef->CryptoKeyElementRef[KeyElementIndex]
                    .CryptoKeyElementInitValue[Index] = keyPtr[Index];
            }
            *(Crypto_Key[cryptokeyId].CryptoKeyTypeRef->CryptoKeyElementRef[KeyElementIndex].CryptoKeyElementLength) =
                keyLength;
            Status = E_OK;
        }
    }
    return Status;
}
#endif

FUNC(void, CRY_CODE) Crypto_memset(void* buf, uint32 len)
{
    uint8* tmpsrc = (uint8*)buf;

    if ((len > 0) && (buf != NULL_PTR))
    {
        while (len--)
        {
            *tmpsrc++ = (uint8)0;
        }
    }
}

FUNC(void, CRY_CODE) Crypto_memsetVal(void* buf, uint8 val, uint32 len)
{
    uint8* tmpsrc = (uint8*)buf;

    if ((len > 0) && (buf != NULL_PTR))
    {
        while (len--)
        {
            *tmpsrc++ = val;
        }
    }
}

FUNC(void, CRY_CODE) Crypto_memcpy(void* buf, const void* buf1, uint32 len)
{
    uint32 i;
    if ((len > 0) && (buf != NULL_PTR) && (buf1 != NULL_PTR))
    {
        const char* psrc = (const char*)buf1;
        char* pdest = (char*)buf;
        for (i = 0; i < len; i++)
        {
            pdest[i] = psrc[i];
        }
    }
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"
