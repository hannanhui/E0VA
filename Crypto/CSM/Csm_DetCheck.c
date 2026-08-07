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
**  FILENAME    : Csm_DetCheck.c                                              **
**                                                                            **
**  Created on  :                                                             **
**  Author      : qinchun.yang                                                **
**  Vendor      :                                                             **
**  DESCRIPTION : Implementation detect-check for CSM                         **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

/******************************************************************************
**                      Revision Control History                             **
******************************************************************************/
/*  <VERSION>      <DATE>      <AUTHOR>        <REVISION LOG>
 *    V1.0.0      2019-10-18    qinchun.yang     Initial version
 *    V1.1.0      2020-06-20    yuzhe.zhang      R19-11
 *    V2.0.0      2023-02-06    jie.gu           R19_11
 */

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Csm_Internal.h"
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#if (CSM_DEV_ERROR_DETECT == STD_ON)
/*report DET error*/
#define Csm_ReportDetErr(serviceId, error) \
    (void)Det_ReportError(CSM_MODULE_ID, CSM_MODULE_INSTANCE_ID, (serviceId), (error));

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
static FUNC(Std_ReturnType, CSM_CODE) Csm_ChkInitStatus(VAR(uint8, AUTOMATIC) servId);
/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define CSM_START_SEC_CODE
#include "Csm_MemMap.h"
FUNC(boolean, CSM_CODE)
Csm_ChkInitParam(P2CONST(Csm_ConfigType, AUTOMATIC, CSM_APPL_DATA) configPtr)
{
    boolean ret = (boolean)TRUE;
    /*[SWS_Csm_00186]*/
    if (NULL_PTR != configPtr)
    {
        ret = (boolean)FALSE;
        Csm_ReportDetErr(CSM_SID_INIT, CSM_E_INIT_FAILED);
    }
    return ret;
}

/*check parameters for  Csm_GetVersionInfo()*/
FUNC(Std_ReturnType, CSM_CODE)
Csm_ChkGetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, CSM_APPL_DATA) versioninfo, VAR(uint8, AUTOMATIC) sid)
{
    Std_ReturnType ret = (boolean)E_OK;

    if (NULL_PTR == versioninfo)
    {
        ret = (boolean)E_NOT_OK;
        Csm_ReportDetErr(sid, CSM_E_PARAM_POINTER);
    }
    return ret;
}

/*check parameters for  Csm_Servicexxx()*/
FUNC(Std_ReturnType, CSM_CODE)
Csm_ChkServiceParam(VAR(uint32, AUTOMATIC) jobId, VAR(uint8, AUTOMATIC) sid)
{
    Std_ReturnType ret;

    ret = Csm_ChkInitStatus(sid);
    if ((boolean)E_OK == ret)
    {
        if (jobId > CSM_JOB_NUM)
        {
            ret = (boolean)E_NOT_OK;
            Csm_ReportDetErr(sid, CSM_E_PARAM_HANDLE);
        }
        switch (sid)
        {
        case CSM_SID_HASH:
            if (Csm_JobCfg[jobId].jobPrimitiveInfo->primitiveInfo->service != CRYPTO_HASH)
            {
                ret = (boolean)E_NOT_OK;
                Csm_ReportDetErr(sid, CSM_E_SERVICE_TYPE);
            }
            break;
        case CSM_SID_MAC_GEN:
            if (Csm_JobCfg[jobId].jobPrimitiveInfo->primitiveInfo->service != CRYPTO_MACGENERATE)
            {
                ret = (boolean)E_NOT_OK;
                Csm_ReportDetErr(sid, CSM_E_SERVICE_TYPE);
            }
            break;
        case CSM_SID_MAC_VERIFY:
            if (Csm_JobCfg[jobId].jobPrimitiveInfo->primitiveInfo->service != CRYPTO_MACVERIFY)
            {
                ret = (boolean)E_NOT_OK;
                Csm_ReportDetErr(sid, CSM_E_SERVICE_TYPE);
            }
            break;
        case CSM_SID_ENCRYPT:
            if (Csm_JobCfg[jobId].jobPrimitiveInfo->primitiveInfo->service != CRYPTO_ENCRYPT)
            {
                ret = (boolean)E_NOT_OK;
                Csm_ReportDetErr(sid, CSM_E_SERVICE_TYPE);
            }
            break;
        case CSM_SID_DECRYPT:
            if (Csm_JobCfg[jobId].jobPrimitiveInfo->primitiveInfo->service != CRYPTO_DECRYPT)
            {
                ret = (boolean)E_NOT_OK;
                Csm_ReportDetErr(sid, CSM_E_SERVICE_TYPE);
            }
            break;
        case CSM_SID_AEADENCRYPT:
            if (Csm_JobCfg[jobId].jobPrimitiveInfo->primitiveInfo->service != CRYPTO_AEADENCRYPT)
            {
                ret = (boolean)E_NOT_OK;
                Csm_ReportDetErr(sid, CSM_E_SERVICE_TYPE);
            }
            break;
        case CSM_SID_AEADDECRYPT:
            if (Csm_JobCfg[jobId].jobPrimitiveInfo->primitiveInfo->service != CRYPTO_AEADDECRYPT)
            {
                ret = (boolean)E_NOT_OK;
                Csm_ReportDetErr(sid, CSM_E_SERVICE_TYPE);
            }
            break;
        case CSM_SID_SIG_GEN:
            if (Csm_JobCfg[jobId].jobPrimitiveInfo->primitiveInfo->service != CRYPTO_SIGNATUREGENERATE)
            {
                ret = (boolean)E_NOT_OK;
                Csm_ReportDetErr(sid, CSM_E_SERVICE_TYPE);
            }
            break;
        case CSM_SID_SIG_VERIFY:
            if (Csm_JobCfg[jobId].jobPrimitiveInfo->primitiveInfo->service != CRYPTO_SIGNATUREVERIFY)
            {
                ret = (boolean)E_NOT_OK;
                Csm_ReportDetErr(sid, CSM_E_SERVICE_TYPE);
            }
            break;
        case CSM_SID_RANDOM_GEN:
            if (Csm_JobCfg[jobId].jobPrimitiveInfo->primitiveInfo->service != CRYPTO_RANDOMGENERATE)
            {
                ret = (boolean)E_NOT_OK;
                Csm_ReportDetErr(sid, CSM_E_SERVICE_TYPE);
            }
            break;
        default:
            if (Csm_JobCfg[jobId].jobPrimitiveInfo->primitiveInfo->service != CRYPTO_SIGNATUREVERIFY)
            {
                ret = (boolean)E_NOT_OK;
                Csm_ReportDetErr(sid, CSM_E_SERVICE_TYPE);
            }
            break;
        }
    }
    return ret;
}

/*check parameters for  Csm_KeyElementSet()*/
FUNC(Std_ReturnType, CSM_CODE)
Csm_ChkKeyEleSetParam(
    VAR(uint32, AUTOMATIC) keyId,
    P2CONST(uint8, AUTOMATIC, CSM_APPL_DATA) keyPtr,
    VAR(uint32, AUTOMATIC) keyLength,
    VAR(uint8, AUTOMATIC) sid)
{
    Std_ReturnType ret;

    ret = Csm_ChkInitStatus(sid);
    if ((boolean)E_OK == ret)
    {
        if (keyId > CSM_KEY_NUM)
        {
            ret = (boolean)E_NOT_OK;
            Csm_ReportDetErr(sid, CSM_E_PARAM_HANDLE);
        }
        else if (NULL_PTR == keyPtr)
        {
            ret = (boolean)E_NOT_OK;
            Csm_ReportDetErr(sid, CSM_E_PARAM_POINTER);
        }
        else if (0u == keyLength)
        {
            ret = (boolean)E_NOT_OK;
            Csm_ReportDetErr(sid, CSM_E_PARAM_HANDLE);
        }
        else
        {
            /*Do nothing*/
        }
    }
    return ret;
}

/*check parameters for  Csm_KeySetValid()*/
FUNC(Std_ReturnType, CSM_CODE)
Csm_ChkKeySetValid(VAR(uint32, AUTOMATIC) keyId, VAR(uint8, AUTOMATIC) sid)
{
    Std_ReturnType ret;

    ret = Csm_ChkInitStatus(sid);
    if ((boolean)E_OK == ret)
    {
        if (keyId > CSM_KEY_NUM)
        {
            ret = (boolean)E_NOT_OK;
            Csm_ReportDetErr(sid, CSM_E_PARAM_HANDLE);
        }
    }
    return ret;
}

/*check parameters for  Csm_KeyElementGet()*/
FUNC(Std_ReturnType, CSM_CODE)
Csm_ChkKeyEleGet(
    VAR(uint32, AUTOMATIC) keyId,
    P2VAR(uint8, AUTOMATIC, CSM_APPL_DATA) keyPtr,
    P2VAR(uint32, AUTOMATIC, CSM_APPL_DATA) keyLengthPtr,
    VAR(uint8, AUTOMATIC) sid)
{
    Std_ReturnType ret;

    ret = Csm_ChkInitStatus(sid);
    if ((boolean)E_OK == ret)
    {
        if (keyId > CSM_KEY_NUM)
        {
            ret = (boolean)E_NOT_OK;
            Csm_ReportDetErr(sid, CSM_E_PARAM_HANDLE);
        }
        else if ((NULL_PTR == keyPtr) || (NULL_PTR == keyLengthPtr))
        {
            ret = (boolean)E_NOT_OK;
            Csm_ReportDetErr(sid, CSM_E_PARAM_POINTER);
        }
        else if (0u == *keyLengthPtr)
        {
            ret = (boolean)E_NOT_OK;
            Csm_ReportDetErr(sid, CSM_E_PARAM_HANDLE);
        }
        else
        {
            /*Do nothing*/
        }
    }
    return ret;
}

/*check parameters for  Csm_KeyElementCopy()*/
FUNC(Std_ReturnType, CSM_CODE)
Csm_ChkKeyEleCopy(
    CONST(uint32, CSM_APPL_DATA) keyId,
    CONST(uint32, CSM_APPL_DATA) targetKeyId,
    VAR(uint8, AUTOMATIC) sid)
{
    Std_ReturnType ret;

    ret = Csm_ChkInitStatus(sid);
    if ((boolean)E_OK == ret)
    {
        if ((keyId > CSM_KEY_NUM) || (targetKeyId > CSM_KEY_NUM))
        {
            ret = (boolean)E_NOT_OK;
            Csm_ReportDetErr(sid, CSM_E_PARAM_HANDLE);
        }
    }
    return ret;
}

/*check parameters for  Csm_KeyCopy()*/
FUNC(Std_ReturnType, CSM_CODE)
Csm_ChkKeyCopy(CONST(uint32, CSM_APPL_DATA) keyId, CONST(uint32, CSM_APPL_DATA) targetKeyId, VAR(uint8, AUTOMATIC) sid)
{
    Std_ReturnType ret;

    ret = Csm_ChkInitStatus(sid);
    if ((boolean)E_OK == ret)
    {
        if ((keyId > CSM_KEY_NUM) || (targetKeyId > CSM_KEY_NUM))
        {
            ret = (boolean)E_NOT_OK;
            Csm_ReportDetErr(sid, CSM_E_PARAM_HANDLE);
        }
    }
    return ret;
}

/*check parameters for  Csm_KeyElementCopyPartial()*/
FUNC(Std_ReturnType, CSM_CODE)
Csm_ChkKeyEleCopyPart(VAR(uint32, AUTOMATIC) keyId, VAR(uint32, AUTOMATIC) targetKeyId, VAR(uint8, AUTOMATIC) sid)
{
    Std_ReturnType ret;

    ret = Csm_ChkInitStatus(sid);
    if ((boolean)E_OK == ret)
    {
        if ((keyId > CSM_KEY_NUM) || (targetKeyId > CSM_KEY_NUM))
        {
            ret = (boolean)E_NOT_OK;
            Csm_ReportDetErr(sid, CSM_E_PARAM_HANDLE);
        }
    }
    return ret;
}

/*check parameters for  Csm_RandomSeed()*/
FUNC(Std_ReturnType, CSM_CODE)
Csm_ChkRandomSeed(
    VAR(uint32, AUTOMATIC) keyId,
    P2CONST(uint8, AUTOMATIC, CSM_APPL_DATA) seedPtr,
    uint32 seedLength,
    VAR(uint8, AUTOMATIC) sid)
{
    Std_ReturnType ret;

    ret = Csm_ChkInitStatus(sid);
    if ((boolean)E_OK == ret)
    {
        if (keyId > CSM_KEY_NUM)
        {
            ret = (boolean)E_NOT_OK;
            Csm_ReportDetErr(sid, CSM_E_PARAM_HANDLE);
        }
        else if (NULL_PTR == seedPtr)
        {
            ret = (boolean)E_NOT_OK;
            Csm_ReportDetErr(sid, CSM_E_PARAM_POINTER);
        }
        else if (0u == seedLength)
        {
            ret = (boolean)E_NOT_OK;
            Csm_ReportDetErr(sid, CSM_E_PARAM_HANDLE);
        }
        else
        {
            /*Do nothing*/
        }
    }
    return ret;
}

/*check parameters for  Csm_KeyGenerate()*/
FUNC(Std_ReturnType, CSM_CODE)
Csm_ChkKeyGenerate(VAR(uint32, AUTOMATIC) keyId, VAR(uint8, AUTOMATIC) sid)
{
    Std_ReturnType ret;

    ret = Csm_ChkInitStatus(sid);
    if ((boolean)E_OK == ret)
    {
        if (keyId > CSM_KEY_NUM)
        {
            ret = (boolean)E_NOT_OK;
            Csm_ReportDetErr(sid, CSM_E_PARAM_HANDLE);
        }
    }
    return ret;
}

/*check parameters for  Csm_KeyDerive()*/
FUNC(Std_ReturnType, CSM_CODE)
Csm_ChkKeyDerive(VAR(uint32, AUTOMATIC) keyId, VAR(uint32, AUTOMATIC) targetKeyId, VAR(uint8, AUTOMATIC) sid)
{
    Std_ReturnType ret;

    ret = Csm_ChkInitStatus(sid);
    if ((boolean)E_OK == ret)
    {
        if ((keyId > CSM_KEY_NUM) || (targetKeyId > CSM_KEY_NUM))
        {
            ret = (boolean)E_NOT_OK;
            Csm_ReportDetErr(sid, CSM_E_PARAM_HANDLE);
        }
    }
    return ret;
}

/*check parameters for  Csm_KeyExchangeCalcPubVal()*/
FUNC(Std_ReturnType, CSM_CODE)
Csm_ChkExCalcPubVal(
    VAR(uint32, AUTOMATIC) keyId,
    P2VAR(uint8, AUTOMATIC, CSM_APPL_DATA) publicValuePtr,
    P2VAR(uint32, AUTOMATIC, CSM_APPL_DATA) publicValueLengthPtr,
    VAR(uint8, AUTOMATIC) sid)
{
    Std_ReturnType ret;

    ret = Csm_ChkInitStatus(sid);
    if ((boolean)E_OK == ret)
    {
        if (keyId > CSM_KEY_NUM)
        {
            ret = (boolean)E_NOT_OK;
            Csm_ReportDetErr(sid, CSM_E_PARAM_HANDLE);
        }
        else if ((NULL_PTR == publicValuePtr) || (NULL_PTR == publicValueLengthPtr))
        {
            ret = (boolean)E_NOT_OK;
            Csm_ReportDetErr(sid, CSM_E_PARAM_POINTER);
        }
        else
        {
            /*Do nothing*/
        }
    }
    return ret;
}

/*check parameters for  Csm_KeyExchangeCalcSecret()*/
FUNC(Std_ReturnType, CSM_CODE)
Csm_ChkExCalcSecVal(
    VAR(uint32, AUTOMATIC) keyId,
    P2CONST(uint8, AUTOMATIC, CSM_APPL_DATA) partnerPublicValuePtr,
    VAR(uint32, AUTOMATIC) partnerPublicValueLength,
    VAR(uint8, AUTOMATIC) sid)
{
    Std_ReturnType ret;

    ret = Csm_ChkInitStatus(sid);
    if ((boolean)E_OK == ret)
    {
        if ((keyId > CSM_KEY_NUM) || (0u == partnerPublicValueLength))
        {
            ret = (boolean)E_NOT_OK;
            Csm_ReportDetErr(sid, CSM_E_PARAM_HANDLE);
        }
        else if (NULL_PTR == partnerPublicValuePtr)
        {
            ret = (boolean)E_NOT_OK;
            Csm_ReportDetErr(sid, CSM_E_PARAM_POINTER);
        }
        else
        {
            /*Do nothing*/
        }
    }
    return ret;
}

/*check parameters for  Csm_JobKeySetValid()*/
FUNC(Std_ReturnType, CSM_CODE)
Csm_ChkJobKeySetValid(VAR(uint32, AUTOMATIC) jobId, VAR(uint32, AUTOMATIC) keyId, VAR(uint8, AUTOMATIC) sid)
{
    Std_ReturnType ret;

    ret = Csm_ChkInitStatus(sid);
    if ((boolean)E_OK == ret)
    {
        if ((keyId > CSM_KEY_NUM) || (jobId > CSM_JOB_NUM))
        {
            ret = (boolean)E_NOT_OK;
            Csm_ReportDetErr(sid, CSM_E_PARAM_HANDLE);
        }
        if (Csm_JobCfg[jobId].jobPrimitiveInfo->primitiveInfo->service != CRYPTO_KEYSETVALID)
        {
            ret = (boolean)E_NOT_OK;
            Csm_ReportDetErr(sid, CSM_E_SERVICE_TYPE);
        }
    }
    return ret;
}

/*check parameters for Csm_JobRandomSeed()*/
FUNC(Std_ReturnType, CSM_CODE)
Csm_ChkJobRandomSeed(
    VAR(uint32, AUTOMATIC) jobId,
    VAR(uint32, AUTOMATIC) keyId,
    P2CONST(uint8, AUTOMATIC, CSM_APPL_DATA) seedPtr,
    VAR(uint32, AUTOMATIC) seedLength,
    VAR(uint8, AUTOMATIC) sid)
{
    Std_ReturnType ret;

    ret = Csm_ChkInitStatus(sid);
    if ((boolean)E_OK == ret)
    {
        if (jobId > CSM_JOB_NUM)
        {
            ret = (boolean)E_NOT_OK;
            Csm_ReportDetErr(sid, CSM_E_PARAM_HANDLE);
        }
        if (Csm_JobCfg[jobId].jobPrimitiveInfo->primitiveInfo->service != CRYPTO_RANDOMSEED)
        {
            ret = (boolean)E_NOT_OK;
            Csm_ReportDetErr(sid, CSM_E_SERVICE_TYPE);
        }
        if ((boolean)E_OK == ret)
        {
            ret = Csm_ChkRandomSeed(keyId, seedPtr, seedLength, sid);
        }
    }
    return ret;
}

/*check parameters for  Csm_JobKeyGenerate()*/
FUNC(Std_ReturnType, CSM_CODE)
Csm_ChkJobKeyGenerate(VAR(uint32, AUTOMATIC) jobId, VAR(uint32, AUTOMATIC) keyId, VAR(uint8, AUTOMATIC) sid)
{
    Std_ReturnType ret;

    ret = Csm_ChkInitStatus(sid);
    if ((boolean)E_OK == ret)
    {
        if ((keyId > CSM_KEY_NUM) || (jobId > CSM_JOB_NUM))
        {
            ret = (boolean)E_NOT_OK;
            Csm_ReportDetErr(sid, CSM_E_PARAM_HANDLE);
        }
        if (Csm_JobCfg[jobId].jobPrimitiveInfo->primitiveInfo->service != CRYPTO_KEYGENERATE)
        {
            ret = (boolean)E_NOT_OK;
            Csm_ReportDetErr(sid, CSM_E_SERVICE_TYPE);
        }
    }
    return ret;
}

/*check parameters for  Csm_JobKeyDerive()*/
FUNC(Std_ReturnType, CSM_CODE)
Csm_ChkJobKeyDerive(
    VAR(uint32, AUTOMATIC) jobId,
    VAR(uint32, AUTOMATIC) keyId,
    VAR(uint32, AUTOMATIC) targetKeyId,
    VAR(uint8, AUTOMATIC) sid)
{
    Std_ReturnType ret;

    ret = Csm_ChkInitStatus(sid);
    if ((boolean)E_OK == ret)
    {
        if ((keyId > CSM_KEY_NUM) || (targetKeyId > CSM_KEY_NUM) || (jobId > CSM_JOB_NUM))
        {
            ret = (boolean)E_NOT_OK;
            Csm_ReportDetErr(sid, CSM_E_PARAM_HANDLE);
        }
        if (Csm_JobCfg[jobId].jobPrimitiveInfo->primitiveInfo->service != CRYPTO_KEYDERIVE)
        {
            ret = (boolean)E_NOT_OK;
            Csm_ReportDetErr(sid, CSM_E_SERVICE_TYPE);
        }
    }
    return ret;
}

/*check parameters for  Csm_JobKeyExchangeCalcPubVal()*/
FUNC(Std_ReturnType, CSM_CODE)
Csm_ChkJobExCalcPubVal(
    VAR(uint32, AUTOMATIC) jobId,
    VAR(uint32, AUTOMATIC) keyId,
    P2VAR(uint8, AUTOMATIC, CSM_APPL_DATA) publicValuePtr,
    P2VAR(uint32, AUTOMATIC, CSM_APPL_DATA) publicValueLengthPtr,
    VAR(uint8, AUTOMATIC) sid)
{
    Std_ReturnType ret = E_OK;
    if ((boolean)E_OK == ret)
    {
        if (jobId > CSM_JOB_NUM)
        {
            ret = (boolean)E_NOT_OK;
            Csm_ReportDetErr(sid, CSM_E_PARAM_HANDLE);
        }
        if (Csm_JobCfg[jobId].jobPrimitiveInfo->primitiveInfo->service != CRYPTO_KEYEXCHANGECALCPUBVAL)
        {
            ret = (boolean)E_NOT_OK;
            Csm_ReportDetErr(sid, CSM_E_SERVICE_TYPE);
        }
        if ((boolean)E_OK == ret)
        {
            ret = Csm_ChkExCalcPubVal(keyId, publicValuePtr, publicValueLengthPtr, sid);
        }
    }
    return ret;
}

/*check parameters for  Csm_JobKeyExchangeCalcSecret()*/
FUNC(Std_ReturnType, CSM_CODE)
Csm_ChkJobExCalcSec(
    VAR(uint32, AUTOMATIC) jobId,
    VAR(uint32, AUTOMATIC) keyId,
    P2CONST(uint8, AUTOMATIC, CSM_APPL_DATA) partnerPublicValuePtr,
    VAR(uint32, AUTOMATIC) partnerPublicValueLength,
    VAR(uint8, AUTOMATIC) sid)
{
    Std_ReturnType ret;

    ret = Csm_ChkInitStatus(sid);
    if ((boolean)E_OK == ret)
    {
        if (jobId > CSM_JOB_NUM)
        {
            ret = (boolean)E_NOT_OK;
            Csm_ReportDetErr(sid, CSM_E_PARAM_HANDLE);
        }
        if (Csm_JobCfg[jobId].jobPrimitiveInfo->primitiveInfo->service != CRYPTO_KEYEXCHANGECALCSECRET)
        {
            ret = (boolean)E_NOT_OK;
            Csm_ReportDetErr(sid, CSM_E_SERVICE_TYPE);
        }
        if ((boolean)E_OK == ret)
        {
            ret = Csm_ChkExCalcSecVal(keyId, partnerPublicValuePtr, partnerPublicValueLength, sid);
        }
    }
    return ret;
}

/*check parameters for  Csm_CancelJob()*/
FUNC(Std_ReturnType, CSM_CODE)
Csm_ChkCancelJob(VAR(uint32, AUTOMATIC) jobId, VAR(uint8, AUTOMATIC) sid)
{
    P2CONST(Csm_JobsCfgType, AUTOMATIC, AUTOMATIC) jobCfgPtr;
    Std_ReturnType ret;

    ret = Csm_ChkInitStatus(sid);
    if ((boolean)E_OK == ret)
    {
        if (jobId > CSM_JOB_NUM)
        {
            ret = (boolean)E_NOT_OK;
            Csm_ReportDetErr(sid, CSM_E_PARAM_HANDLE);
        }
        else
        {
            jobCfgPtr = &(Csm_JobCfg[jobId]);
            /*[SWS_Csm_01086]*/
            if (CRYPTO_PROCESSING_SYNC == jobCfgPtr->jobPrimitiveInfo->processingType)
            {
                ret = (boolean)E_NOT_OK;
                Csm_ReportDetErr(sid, CSM_E_PROCESSING_MODE);
            }
        }
    }
    return ret;
}

/*check parameters for  Csm_CallbackNotification()*/
FUNC(Std_ReturnType, CSM_CODE)
Csm_ChkCbkNotify(P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_DATA) job, VAR(uint8, AUTOMATIC) sid)
{
    Std_ReturnType ret;

    ret = Csm_ChkInitStatus(sid);
    if ((boolean)E_OK == ret)
    {
        if (job->jobId > CSM_JOB_NUM)
        {
            ret = (boolean)E_NOT_OK;
            Csm_ReportDetErr(sid, CSM_E_PARAM_HANDLE);
        }
        else if ((NULL_PTR == job->jobInfo) || (NULL_PTR == job->jobPrimitiveInfo))
        {
            ret = (boolean)E_NOT_OK;
            Csm_ReportDetErr(sid, CSM_E_PARAM_POINTER);
        }
        else
        {
            /*Do nothing*/
        }
    }
    return ret;
}
#define CSM_STOP_SEC_CODE
#include "Csm_MemMap.h"
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
#define CSM_START_SEC_CODE
#include "Csm_MemMap.h"
static FUNC(Std_ReturnType, CSM_CODE) Csm_ChkInitStatus(VAR(uint8, AUTOMATIC) servId)
{
    Std_ReturnType ret = (boolean)E_OK;

    if ((boolean)FALSE == Csm_InitStatus)
    {
        ret = (boolean)E_NOT_OK;
        Csm_ReportDetErr(servId, CSM_E_UNINIT);
    }
    return ret;
}
#define CSM_STOP_SEC_CODE
#include "Csm_MemMap.h"

#endif /* CSM_DEV_ERROR_DETECT == STD_ON */
