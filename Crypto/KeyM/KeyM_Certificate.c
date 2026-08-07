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
 **  FILENAME    : KeyM_Certificate.c                                          **
 **                                                                            **
 **  Created on  :                                                             **
 **  Author      : qinchun.yang                                                **
 **  Vendor      :                                                             **
 **  DESCRIPTION : Implementation for certificate sub module                   **
 **                                                                            **
 **  SPECIFICATION(S) :   AUTOSAR classic Platform R21-11                      **
 **                                                                            **
 *******************************************************************************/

/******************************************************************************
**                      Revision Control History                             **
******************************************************************************/
/*  <VERSION>    <DATE>      <AUTHOR>        <REVISION LOG>
 *  V1.0.0     2022-02-15   qinchun.yang     initial version.
 *  V1.0.1     2022-02-15   qinchun.yang     Modify Certificate version check.
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "KeyM_Internal.h"
#if (STD_ON == KEYM_CERTIFICATE_MANAGER_ENABLED)
#include "StbM.h"
/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define KEYM_LONG_FORMAT_MASK           0x80u

#define KEYM_CERT_ASN1_BOOLEAN          0x01u
#define KEYM_CERT_ASN1_INTEGER          0x02u
#define KEYM_CERT_ASN1_BIT_STRING       0x03u
#define KEYM_CERT_ASN1_OCTET_STRING     0x04u
#define KEYM_CERT_ASN1_NULL             0x05u
#define KEYM_CERT_ASN1_OID              0x06u
#define KEYM_CERT_ASN1_UINT8_STRING     0x0Cu
#define KEYM_CERT_ASN1_ASCII_STRING     0x13u
#define KEYM_CERT_ASN1_UTC_TIME         0x17u
#define KEYM_CERT_ASN1_GENERALIZED_TIME 0x18u
#define KEYM_CERT_ASN1_SEQ_CONSTRU      0x30u
#define KEYM_CERT_ASN1_SET_CONSTRU      0x31u
#define KEYM_CERT_ASN1_TAG              0xA0u

#define KEYM_CHECK_RANGE(min, max, val)     \
    do                                      \
    {                                       \
        if ((val) < (min) || (val) > (max)) \
        {                                   \
            return (ret);                   \
        }                                   \
    } while (0)
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
static FUNC(Std_ReturnType, KEYM_CODE) KeyM_HandleCertcVerify(
    P2CONST(KeyM_CertPCfgType, AUTOMATIC, KEYM_CONST) certCfgPtr,
    P2CONST(KeyM_CertPCfgType, TYPEDEF, KEYM_CONST) certUpperHierRef);

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_CheckGeneralParam(
    VAR(KeyM_CertificateIdType, AUTOMATIC) CertId,
    VAR(KeyM_CertElementIdType, AUTOMATIC) CertElementId,
    P2VAR(uint8, AUTOMATIC, KEYM_APPL_DATA) CertElementData,
    P2VAR(uint32, AUTOMATIC, KEYM_APPL_DATA) CertElementDataLength,
    uint8 ApiId);

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_IsCertExist(
    KeyM_CertificateIdType certId,
    KeyM_CertEleStructType certStr,
    P2VAR(uint16, AUTOMATIC, KEYM_APPL_DATA) cfgId);

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_FindCertElement(
    KeyM_CertificateIdType certId,
    P2VAR(KeyM_CertEleType, AUTOMATIC, KEYM_APPL_DATA) certEle,
    P2VAR(uint16, AUTOMATIC, KEYM_APPL_DATA) eleIdx);

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertEleHandle(
    KeyM_CertificateIdType certId,
    P2VAR(KeyM_CertEleType, AUTOMATIC, KEYM_APPL_DATA) certEle,
    P2VAR(uint8, AUTOMATIC, KEYM_APPL_DATA) eleData,
    uint32 tag);

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertGetAsn1Tag(
    P2VAR(uint8*, AUTOMATIC, KEYM_APPL_DATA) cerS,
    P2CONST(uint8, TYPEDEF, KEYM_CONST) cerE,
    P2VAR(uint32, AUTOMATIC, KEYM_APPL_DATA) cerLenPtr,
    uint8 tag);

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertGetAsn1Len(
    P2VAR(uint8*, AUTOMATIC, KEYM_APPL_DATA) cerS,
    P2CONST(uint8, TYPEDEF, KEYM_CONST) cerE,
    P2VAR(uint32, AUTOMATIC, KEYM_APPL_DATA) cerLen);

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertGetAsn1TagInt(
    P2VAR(uint8*, AUTOMATIC, KEYM_APPL_DATA) cerS,
    P2CONST(uint8, TYPEDEF, KEYM_CONST) cerE,
    P2VAR(uint8, AUTOMATIC, KEYM_APPL_DATA) intVal,
    P2VAR(uint32, AUTOMATIC, KEYM_APPL_DATA) cerLen);

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertGetVersion(
    KeyM_CertificateIdType certId,
    P2VAR(uint8*, AUTOMATIC, KEYM_APPL_DATA) cerS,
    P2CONST(uint8, TYPEDEF, KEYM_CONST) cerE);

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertGetSerialVersion(
    KeyM_CertificateIdType certId,
    P2VAR(uint8*, AUTOMATIC, KEYM_APPL_DATA) cerS,
    P2CONST(uint8, TYPEDEF, KEYM_CONST) cerE);

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertGetSigAlgorithmId(
    KeyM_CertificateIdType certId,
    P2VAR(uint8*, AUTOMATIC, KEYM_APPL_DATA) cerS,
    P2CONST(uint8, TYPEDEF, KEYM_CONST) cerE,
    P2VAR(KeyM_Asn1DesType, AUTOMATIC, KEYM_APPL_DATA) sigPar);

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertHandleName(
    P2VAR(uint8*, AUTOMATIC, KEYM_APPL_DATA) cerS,
    P2CONST(uint8, TYPEDEF, KEYM_CONST) cerE,
    P2VAR(KeyM_Asn1DesType, TYPEDEF, KEYM_APPL_DATA) isuName,
    P2VAR(KeyM_Asn1DesType, TYPEDEF, KEYM_APPL_DATA) isuNameOid);

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertGetName(
    KeyM_CertificateIdType certId,
    P2VAR(uint8*, AUTOMATIC, KEYM_APPL_DATA) cerS,
    P2CONST(uint8, TYPEDEF, KEYM_CONST) cerE,
    KeyM_CertEleStructType eleNameType,
    KeyM_CertEleStructType eleNameOidType);

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertParseTimeEle(
    P2VAR(uint8*, AUTOMATIC, KEYM_APPL_DATA) ele,
    uint32 len,
    P2VAR(uint32, AUTOMATIC, KEYM_APPL_DATA) time);

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertCheckDate(P2VAR(KeyM_CertTimeType, AUTOMATIC, KEYM_APPL_DATA) time);

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertParseTime(
    uint32 len,
    uint32 yearLen,
    P2VAR(uint8*, AUTOMATIC, KEYM_APPL_DATA) cerS,
    P2VAR(KeyM_CertTimeType, AUTOMATIC, KEYM_APPL_DATA) time);

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertHandleGetTime(
    KeyM_CertificateIdType certId,
    P2VAR(uint8*, AUTOMATIC, KEYM_APPL_DATA) cerS,
    P2CONST(uint8, TYPEDEF, KEYM_CONST) cerE,
    P2VAR(KeyM_CertTimeType, AUTOMATIC, KEYM_APPL_DATA) time,
    KeyM_CertEleStructType eleStrut);

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertGetTime(
    KeyM_CertificateIdType certId,
    P2VAR(uint8*, AUTOMATIC, KEYM_APPL_DATA) cerS,
    P2CONST(uint8, TYPEDEF, KEYM_CONST) cerE);

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertHandleGetPubKeyAlgo(
    KeyM_CertificateIdType certId,
    P2VAR(uint8*, AUTOMATIC, KEYM_APPL_DATA) cerS,
    P2CONST(uint8, TYPEDEF, KEYM_CONST) cerE);

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertGetPubKeyInfo(
    KeyM_CertificateIdType certId,
    P2VAR(uint8*, AUTOMATIC, KEYM_APPL_DATA) cerS,
    P2CONST(uint8, TYPEDEF, KEYM_CONST) cerE);

static FUNC(void, KEYM_CODE) KeyM_CertSkipField(
    P2VAR(uint8*, AUTOMATIC, KEYM_APPL_DATA) cerS,
    P2CONST(uint8, TYPEDEF, KEYM_CONST) cerE,
    uint32 type);

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertGetExtention(
    KeyM_CertificateIdType certId,
    P2VAR(uint8*, AUTOMATIC, KEYM_APPL_DATA) cerS,
    P2CONST(uint8, TYPEDEF, KEYM_CONST) cerE);

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertGetSignature(
    KeyM_CertificateIdType certId,
    P2VAR(uint8*, AUTOMATIC, KEYM_APPL_DATA) cerS,
    P2CONST(uint8, TYPEDEF, KEYM_CONST) cerE);

static FUNC(KeyM_Asn1DesType*, KEYM_CODE)
    KeyM_GetCertEle(KeyM_CertificateIdType certId, KeyM_CertEleStructType certEleStru);

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_CmpCertEle(
    P2VAR(KeyM_Asn1DesType, TYPEDEF, KEYM_VAR) certEleBuf,
    P2VAR(KeyM_Asn1DesType, TYPEDEF, KEYM_VAR) upCertEleBuf);

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_GlobalTimeCheck(KeyM_CertificateIdType certId);

static FUNC(uint8, KEYM_CODE) KeyM_IsLeapYear(uint16 year);

static FUNC(uint32, KEYM_CODE) KeyM_ConvertTime_BeijingToUnix(P2VAR(KeyM_CertTimeType, TYPEDEF, KEYM_VAR) bjTime);
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
static KeyM_BlkWriType KeyM_BlkWriDelayRun[KEYM_NVM_BLOCK_NUM];
/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/
#define KEYM_START_SEC_VAR_CLEARED_8
#include "KeyM_MemMap.h"
static KeyM_CertificateStatusType KeyM_CertStatus[KEYM_CERT_NUM];
#define KEYM_STOP_SEC_VAR_CLEARED_8
#include "KeyM_MemMap.h"

#define KEYM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "KeyM_MemMap.h"
KeyM_CertTimeType KeyM_CertStartTime[KEYM_CERT_NUM];
KeyM_CertTimeType KeyM_CertEndTime[KEYM_CERT_NUM];

uint32 KeyM_CertVersion[KEYM_CERT_NUM];
#define KEYM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "KeyM_MemMap.h"

#define KEYM_START_SEC_VAR_INIT_8
#include "KeyM_MemMap.h"
/*Day of Common year */
static const uint8 KeyM_ComMonthDay[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
/*Day of Leap year*/
static const uint8 KeyM_LeapMonthDay[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
#define KEYM_STOP_SEC_VAR_INIT_8
#include "KeyM_MemMap.h"
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define KEYM_START_SEC_CODE
#include "KeyM_MemMap.h"
#if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON)
/*************************************************************************/
/*
 * Brief               The key server requests an operation from the key client.
 * ServiceId           0x09
 * Sync/Async          Asynchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      Service: Provides the type of service the key manager has to perform.
 *                     CertNamePtr: Points to an array that defines the name of the certificate
 *                                  to be updated
 *                     CertNameLength: Specifies the number of bytes in CertNamePtr. The value 0
 *                                indicates that no CertNamePtr is provided within this function.
 *                     RequestDataPtr: Information that comes along with the request
 *                     RequestDataLength: Length of data in the RequestData array
 *                     ResponseDataLength: Max number of bytes available in ResponseData
 * Param-Name[out]     ResponseData: Data returned by the function.
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 *                     E_OK: Operation was successfully performed. Result information are available.
 *                     E_NOT_OK: Operation not accepted due to an internal error.
 *                     KEYM_E_PARAMETER_MISMATCH: Parameter do not match with expected value.
 *                     KEYM_E_KEY_CERT_SIZE_MISMATCH: Parameter size doesn't match
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE)
KeyM_ServiceCertificate(
    VAR(KeyM_ServiceCertificateType, AUTOMATIC) Service,
    P2CONST(uint8, AUTOMATIC, KEYM_APPL_CONST) CertNamePtr,
    VAR(uint16, AUTOMATIC) CertNameLength,
    P2CONST(uint8, AUTOMATIC, KEYM_APPL_CONST) RequestData,
    VAR(uint16, AUTOMATIC) RequestDataLength,
    P2VAR(uint8, AUTOMATIC, KEYM_APPL_DATA) ResponseData,
    VAR(uint16, AUTOMATIC) ResponseDataLength)
{
    P2CONST(KeyM_CertPCfgType, AUTOMATIC, KEYM_CONST) certCfgPtr;
    P2CONST(KeyM_CertPCfgType, AUTOMATIC, KEYM_CONST) certUpperHierRef;
    uint32 jobId;
    uint16 certIdx;
    Std_ReturnType ret = E_OK;

    if (KeyM_InitStatus != TRUE)
    {
#if (KEYM_DEVERROR_DETECT == STD_ON)
        KEYM_DET_REPORT(KEYM_SERV_CERTIFICATE_ID, KEYM_E_UNINIT);
#endif
        ret = E_NOT_OK;
        goto SERV_CERT_EXIT;
    }
#if (KEYM_CRYPTO_KEYHANDLER_SERVICE_CERTIFICATE_ENABLED == STD_ON)
    ret = KeyM_KH_ServiceCertificate(
        Service,
        CertNamePtr,
        CertNameLength,
        RequestData,
        RequestDataLength,
        ResponseData,
        ResponseDataLength);
#else
    /*Searching for a configured certificate by name.*/
    for (certIdx = 0u; certIdx < KEYM_CERT_NUM; certIdx++)
    {
        certCfgPtr = &KeyM_CertPCfg[certIdx];
        if (E_OK == KeyM_strcmp(certCfgPtr->certName, CertNamePtr, CertNameLength))
        {
            break;
        }
    }
    if (certIdx == KEYM_CERT_NUM)
    {
        ret = KEYM_E_KEY_CERT_SIZE_MISMATCH;
        goto SERV_CERT_EXIT;
    }
    /*Service check.*/
    if ((Service < KEYM_SERVICE_CERT_REQUEST_CSR) || (Service > KEYM_SERVICE_CERT_UPDATE_CRL))
    {
        ret = E_NOT_OK;
        goto SERV_CERT_EXIT;
    }
    switch (Service)
    {
    case KEYM_SERVICE_CERT_REQUEST_CSR:
        if (certCfgPtr->certSigGenJobRef == NULL_PTR)
        {
            ret = E_NOT_OK;
        }
        else
        {
            jobId = *(certCfgPtr->certSigGenJobRef);
            Csm_KeyGenerate(KeyM_CryptoKeyCfg[*(certCfgPtr->certPriKeyRef)].keyId);
            ret = Csm_SignatureGenerate(
                jobId,
                CRYPTO_OPERATIONMODE_SINGLECALL,
                RequestData,
                RequestDataLength,
                ResponseData,
                (uint32*)&ResponseDataLength);
        }
        break;
    case KEYM_SERVICE_CERT_UPDATE_SIGNED_CSR:
        break;

    case KEYM_SERVICE_CERT_SET_ROOT:    /*Add a new root certificate*/
    case KEYM_SERVICE_CERT_UPDATE_ROOT: /*Update an existing root certificate*/
        if (certCfgPtr->selfSignedCert == TRUE)
        {
            /*Root certificate.*/
            ret = KeyM_HandleParseCert(certCfgPtr->certId, RequestData, RequestDataLength);
            if (ret == E_OK)
            {
                /*Self-Signed certificate.*/
                ret = KeyM_HandleCertcVerify(certCfgPtr, certCfgPtr);
            }
        }
        break;
    case KEYM_SERVICE_CERT_SET_INTERMEDIATE:    /*Add a new CA certificate*/
    case KEYM_SERVICE_CERT_UPDATE_INTERMEDIATE: /*Update an existing CA certificate*/
        /*Pre-requisite:
         * Root certificate shall have been stored before for a successful verification.*/
        if (certCfgPtr->selfSignedCert != TRUE)
        {
            certUpperHierRef = certCfgPtr;
            /*Verification shall be done from the top of the certificate hierarchy to the bottom.*/
            do
            {
                certUpperHierRef = certUpperHierRef->certUpperHierRef;
                if ((certUpperHierRef != NULL_PTR)
                    && (KeyM_CertStatus[certUpperHierRef->certId] != KEYM_CERTIFICATE_VALID))
                {
                    ret = KEYM_E_CERT_INVALID_CHAIN_OF_TRUST;
                }
            } while ((certUpperHierRef->selfSignedCert != TRUE) && (ret == E_OK));

            ret = KeyM_HandleParseCert(certCfgPtr->certId, RequestData, RequestDataLength);
            if (ret == E_OK)
            {
                /*Intermediate certificate.*/
                ret = KeyM_HandleCertcVerify(certCfgPtr, certCfgPtr->certUpperHierRef);
            }
        }
        else
        {
            ret = E_NOT_OK;
        }
        break;

    case KEYM_SERVICE_CERT_UPDATE_CRL:
        break;
    default:
        /*User specific extensions not supported temporarily*/
        ret = E_NOT_OK;
        break;
    }
#endif /*(KEYM_CRYPTO_KEYHANDLER_SERVICE_CERTIFICATE_ENABLED == STD_ON)*/

SERV_CERT_EXIT:
    return ret;
}
#endif /*(KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON)*/
/*
 * Brief               This function provides the certificate data to the key management module to
 *                     temporarily store the certificate.
 * ServiceId           0x0a
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      CertId: Holds the identifier of the certificate.
 *                     CertificateDataPtr: Pointer to a structure that provides the certificate data.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 *                     E_OK: Certificate accepted.
 *                     E_NOT_OK: Certificate could not be set.
 *                     KEYM_E_PARAMETER_MISMATCH: Parameter do not match with expected value.
 *                     KEYM_E_KEY_CERT_SIZE_MISMATCH: Parameter size doesn't match
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE)
KeyM_SetCertificate(
    VAR(KeyM_CertificateIdType, AUTOMATIC) CertId,
    P2CONST(KeyM_CertDataType, AUTOMATIC, KEYM_APPL_CONST) CertificateDataPtr)
{
    Std_ReturnType ret = E_OK;

#if (STD_ON == KEYM_DEVERROR_DETECT)
    if ((boolean)FALSE == KeyM_InitStatus)
    {
        KEYM_DET_REPORT(KEYM_START_ID, KEYM_E_UNINIT);
    }
    else if ((CertId >= KEYM_CERT_NUM) || (CertificateDataPtr == NULL_PTR))
    {
        KEYM_DET_REPORT(KEYM_START_ID, KEYM_E_PARAM_POINTER);
    }
    else
#endif /*(STD_ON == KEYM_DEVERROR_DETECT)*/
    {
        if (CertificateDataPtr->certDataLength == 0u)
        {
            /*SWS_KeyM_00141*/
            KeyM_CertStatus[CertId] = KEYM_CERTIFICATE_NOT_AVAILABLE;
            goto SET_CERT_EXIT;
        }
        else
        {
            /*Parsing is in progress*/
            KeyM_CertStatus[CertId] = KEYM_CERTIFICATE_NOT_PARSED;

            if (KeyM_CertPCfg[CertId].certStorage != KEYM_STORAGE_IN_RAM)
            {
                /*SWS_KeyM_00166*/
#if (STD_ON == KEYM_DEVERROR_DETECT)
                KEYM_DET_REPORT(KEYM_START_ID, KEYM_E_CONFIG_FAILURE);
#endif /*(STD_ON == KEYM_DEVERROR_DETECT)*/
                ret = E_NOT_OK;
            }
            else
            {
                ret = KeyM_HandleParseCert(CertId, CertificateDataPtr->certData, CertificateDataPtr->certDataLength);
            }
        }
    }
    if (ret != E_OK)
    {
        KeyM_CertStatus[CertId] = KEYM_E_CERTIFICATE_INVALID_FORMAT;
    }
SET_CERT_EXIT:
    return ret;
}

/*************************************************************************/
/*
 * Brief               This function provides the certificate data
 * ServiceId           0x0b
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      CertId: Holds the identifier of the certificate.
 * Param-Name[out]     None
 * Param-Name[in/out]  CertificateDataPtr: Pointer to a structure that provides the certificate data.
 * Return              Std_ReturnType
 *                     E_OK: Certificate accepted.
 *                     E_NOT_OK: Certificate could not be set.
 *                     KEYM_E_PARAMETER_MISMATCH: Parameter do not match with expected value.
 *                     KEYM_E_KEY_CERT_SIZE_MISMATCH: Parameter size doesn't match
 *                     KEYM_E_KEY_CERT_EMPTY: No certificate data available, the certificate slot
 *                                            is empty.
 *                     KEYM_E_KEY_CERT_READ_FAIL: Certificate cannot be provided, access denied.
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE)
KeyM_GetCertificate(
    VAR(KeyM_CertificateIdType, AUTOMATIC) CertId,
    P2VAR(KeyM_CertDataType, AUTOMATIC, KEYM_APPL_DATA) CertificateDataPtr)
{
    P2CONST(KeyM_CertPCfgType, AUTOMATIC, KEYM_CONST) certCfgPtr;
    Std_ReturnType ret = E_OK;

#if (STD_ON == KEYM_DEVERROR_DETECT)
    if ((boolean)FALSE == KeyM_InitStatus)
    {
        KEYM_DET_REPORT(KEYM_GET_CERTIFICATE_ID, KEYM_E_UNINIT);
    }
    else if ((CertId >= KEYM_CERT_NUM) || (CertificateDataPtr == NULL_PTR))
    {
        KEYM_DET_REPORT(KEYM_GET_CERTIFICATE_ID, KEYM_E_PARAM_POINTER);
    }
    else
#endif /*(STD_ON == KEYM_DEVERROR_DETECT)*/
    {
        certCfgPtr = &KeyM_CertPCfg[CertId];
        if (certCfgPtr->tbsCert->len > CertificateDataPtr->certDataLength)
        {
            ret = KEYM_E_KEY_CERT_SIZE_MISMATCH;
        }
        else if (certCfgPtr->tbsCert->len == 0u)
        {
            ret = KEYM_E_KEY_CERT_EMPTY;
        }
        else
        {
            KeyM_CopyData(
                (void*)CertificateDataPtr->certData,
                &(certCfgPtr->tbsCert->dataEle[certCfgPtr->tbsCert->tag]),
                certCfgPtr->tbsCert->len);
            CertificateDataPtr->certDataLength = certCfgPtr->tbsCert->len;
        }
    }

    return ret;
}

/*************************************************************************/
/*
 * Brief               This function provides the certificate data to the key management module to
 *                     temporarily store the certificate.
 * ServiceId           0x0c
 * Sync/Async          Asynchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      CertId: Holds the identifier of the lower certificate in the chain
 *                     CertUpperId: Holds the identifier of the upper certificate in the chain
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 *                     E_OK: Certificate verification request accepted.
 *                     E_NOT_OK: Operation not accepted due to an internal error.
 *                     KEYM_E_BUSY:Validation cannot be performed yet. KeyM is
 *                                 currently busy with other jobs.
 *                     KEYM_E_PARAMETER_MISMATCH: Certificate ID invalid.
 *                     KEYM_E_KEY_CERT_EMPTY: One of the certificate slots are empty.
 *                     KEYM_E_CERT_INVALID_CHAIN_OF_TRUST: An upper certificate is not valid.
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE)
KeyM_VerifyCertificates(
    VAR(KeyM_CertificateIdType, AUTOMATIC) CertId,
    VAR(KeyM_CertificateIdType, AUTOMATIC) CertUpperId)
{
    Std_ReturnType ret = E_OK;

    if (KeyM_InitStatus != TRUE)
    {
#if (KEYM_DEVERROR_DETECT == STD_ON)
        KEYM_DET_REPORT(KEYM_VERIFY_CERTIFICATES_ID, KEYM_E_UNINIT);
#endif
        ret = E_NOT_OK;
        goto VERIFY_CERTS_EXIT;
    }
    if ((CertId >= KEYM_CERT_NUM) || (CertUpperId >= KEYM_CERT_NUM))
    {
        ret = KEYM_E_PARAMETER_MISMATCH;
        goto VERIFY_CERTS_EXIT;
    }
    /*[SWS_KeyM_00118]:The certificate referenced by CertUpperId shall have been validated before.*/
    if (KeyM_CertStatus[CertUpperId] != KEYM_CERTIFICATE_VALID)
    {
        ret = KEYM_E_CERT_INVALID_CHAIN_OF_TRUST;
    }
    else if (KeyM_CertStatus[CertId] != KEYM_CERTIFICATE_PARSED_NOT_VALIDATED)
    {
        /*SWS_KeyM_00028*/
        ret = E_NOT_OK;
    }
    else
    {
        ret = KeyM_HandleCertcVerify(&KeyM_CertPCfg[CertId], &KeyM_CertPCfg[CertUpperId]);
    }
VERIFY_CERTS_EXIT:
    return ret;
}

/*************************************************************************/
/*
 * Brief               This function verifies a certificate that was previously provided with
 *                     KeyM_SetCertificate() against already stored and provided certificates
 *                     stored with other certificate IDs.
 * ServiceId           0x0d
 * Sync/Async          Asynchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      CertId: Holds the identifier of certificate
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 *                     E_OK: Certificate verification request accepted.
 *                     E_NOT_OK: Operation not accepted due to an internal error
 *                     KEYM_E_BUSY:Validation cannot be performed yet. KeyM is
 *                                 currently busy with other jobs.
 *                     KEYM_E_PARAMETER_MISMATCH: Certificate ID invalid.
 *                     KEYM_E_KEY_CERT_EMPTY: One of the certificate slots are empty.
 *                     KEYM_E_CERT_INVALID_CHAIN_OF_TRUST: An upper certificate is not valid.
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE)
KeyM_VerifyCertificate(VAR(KeyM_CertificateIdType, AUTOMATIC) CertId)
{
    P2CONST(KeyM_CertPCfgType, AUTOMATIC, KEYM_CONST) certCfgPtr;
    P2CONST(KeyM_CertPCfgType, TYPEDEF, KEYM_CONST) certUpperHierRef;
    Std_ReturnType ret = E_OK;

    if (KeyM_InitStatus != TRUE)
    {
#if (KEYM_DEVERROR_DETECT == STD_ON)
        KEYM_DET_REPORT(KEYM_VERIFY_CERTIFICATE_ID, KEYM_E_UNINIT);
#endif
        ret = E_NOT_OK;
        goto VERIFY_CERT_EXIT;
    }
    if (CertId >= KEYM_CERT_NUM)
    {
        ret = KEYM_E_PARAMETER_MISMATCH;
    }
    else
    {
        certCfgPtr = &KeyM_CertPCfg[CertId];

        /*SWS_KeyM_00028: A verification of a certificate shall only be started if the certificate is
         * in the status KEYM_CERTIFICATE_PARSED_NOT_VALIDATED*/
        if (KeyM_CertStatus[CertId] != KEYM_CERTIFICATE_PARSED_NOT_VALIDATED)
        {
            ret = E_NOT_OK;
        }
        else
        {
            certUpperHierRef = certCfgPtr;
            /*Verification shall be done from the top of the certificate hierarchy to the bottom.*/
            do
            {
                certUpperHierRef = certUpperHierRef->certUpperHierRef;
                if ((certUpperHierRef != NULL_PTR)
                    && (KeyM_CertStatus[certUpperHierRef->certId] != KEYM_CERTIFICATE_VALID))
                {
                    ret = KEYM_E_CERT_INVALID_CHAIN_OF_TRUST;
                    goto VERIFY_CERT_EXIT;
                }
            } while (certUpperHierRef->selfSignedCert != TRUE);

            certUpperHierRef = certCfgPtr->certUpperHierRef;
            ret = KeyM_HandleCertcVerify(certCfgPtr, certUpperHierRef);
        }
    }
VERIFY_CERT_EXIT:
    return ret;
}

/*************************************************************************/
/*
 * Brief               This function performs a certificate verification against a list of
 *                     certificates.
 * ServiceId           0x0e
 * Sync/Async          Asynchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      CertId: Holds the identifier of the last certificate in the chain.
 *                     certChainData: This is a pointer to an array of certificates sorted
 *                                    according to the order in the PKI.
 *                     NumberOfCertificates: Defines the number of certificates stored in
 *                                           the CertChainData array.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 *                     E_OK: Certificate verification request accepted.
 *                     E_NOT_OK: Operation not accepted due to an internal error
 *                     KEYM_E_BUSY:Validation cannot be performed yet. KeyM is
 *                                 currently busy with other jobs.
 *                     KEYM_E_PARAMETER_MISMATCH: Certificate ID invalid.
 *                     KEYM_E_KEY_CERT_EMPTY: One of the certificate slots are empty.
 *                     KEYM_E_CERT_INVALID_CHAIN_OF_TRUST: An upper certificate is not valid.
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE)
KeyM_VerifyCertificateChain(
    VAR(KeyM_CertificateIdType, AUTOMATIC) CertId,
    CONST(KeyM_CertDataType, AUTOMATIC) certChainData[],
    VAR(uint8, AUTOMATIC) NumberOfCertificates)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 certCnt;

    if (KeyM_InitStatus != TRUE)
    {
#if (KEYM_DEVERROR_DETECT == STD_ON)
        KEYM_DET_REPORT(KEYM_VERIFY_CERTIFICATE_CHAIN_ID, KEYM_E_UNINIT);
#endif
        ret = E_NOT_OK;
        goto VERIFY_CERTCHAIN_EXIT;
    }
    /*TODO*/
    for (certCnt = 0u; certCnt < NumberOfCertificates; certCnt++)
    {
        const KeyM_CertDataType* currentCertData = &(certChainData[certCnt]);
        const KeyM_CertDataType* nextCertData = &(certChainData[certCnt + 1u]);
        (void)currentCertData;
        (void)nextCertData;
    }
VERIFY_CERTCHAIN_EXIT:
    return ret;
}

/*************************************************************************/
/*
 * Brief               Provides the content of a specific certificate element.
 * ServiceId           0x0f
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      CertId: Holds the identifier of the last certificate in the chain.
 *                     CertElementId: Specifies the ElementId where the data shall be read from.
 *                     NumberOfCertificates: Defines the number of certificates stored in
 *                                           the CertChainData array.
 * Param-Name[out]     CertElementData: Pointer to a data buffer allocated by the caller of this function.
 * Param-Name[in/out]  CertElementDataLength:
 *                       In: Pointer to a value that contains the maximum data length of the
 *                           CertElementData buffer.
 *                       Out: The data length will be overwritten with the actual length of data
 *                            placed to the buffer if the function returns E_OK. Otherwise, the
 *                            it will be overwritten with the value zero.
 * Return              Std_ReturnType
 *                     E_OK: Certificate verification request accepted.
 *                     E_NOT_OK: Operation not accepted due to an internal error
 *                     KEYM_E_BUSY:Validation cannot be performed yet. KeyM is
 *                                 currently busy with other jobs.
 *                     KEYM_E_PARAMETER_MISMATCH: Certificate ID invalid.
 *                     KEYM_E_KEY_CERT_EMPTY: One of the certificate slots are empty.
 *                     KEYM_E_CERT_INVALID_CHAIN_OF_TRUST: An upper certificate is not valid.
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE)
KeyM_CertElementGet(
    VAR(KeyM_CertificateIdType, AUTOMATIC) CertId,
    VAR(KeyM_CertElementIdType, AUTOMATIC) CertElementId,
    P2VAR(uint8, AUTOMATIC, KEYM_APPL_DATA) CertElementData,
    P2VAR(uint32, AUTOMATIC, KEYM_APPL_DATA) CertElementDataLength)
{
    Std_ReturnType ret;

    ret =
        KeyM_CheckGeneralParam(CertId, CertElementId, CertElementData, CertElementDataLength, KEYM_CERT_ELEMENT_GET_ID);
    if (ret == (Std_ReturnType)E_OK)
    {
        KeyM_CopyData(
            CertElementData,
            KeyM_CertPCfg[CertId].certEleRef[CertElementId].certEleBuf->dataEle,
            KeyM_CertPCfg[CertId].certEleRef[CertElementId].certEleBuf->len);
        *CertElementDataLength = KeyM_CertPCfg[CertId].certEleRef[CertElementId].certEleBuf->len;
    }

    return ret;
}

/*************************************************************************/
/*
 * Brief               This function provides the element data of a certificate.
 * ServiceId           0x1b
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      CertId: Identifier of the certificate.
 *                     CertElementId:Specifies the ElementId where the data shall be read from.
 *                     Index:Specifies the index to the element that shall be read (0..N).
 * Param-Name[out]     CertElementDataPtr: Pointer to a data buffer allocated by the caller of this function
 * Param-Name[in/out]  CertElementDataLengthPtr
 *                     In: Pointer to a value that contains the maximum data length of
 *                          the CertElementData buffer.
 *                     Out:Pointer to a data buffer allocated by the caller of this function
 * Return              Std_ReturnType
 *                     E_OK
 *                     E_NOT_OK
 *                     KEYM_E_PARAMETER_MISMATCH
 *                     KEYM_E_KEY_CERT_SIZE_MISMATCH
 *                     KEYM_E_KEY_CERT_EMPTY
 *                     KEYM_E_CERT_INVALID
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE)
KeyM_CertificateElementGetByIndex(
    VAR(KeyM_CertificateIdType, AUTOMATIC) CertId,
    VAR(KeyM_CertElementIdType, AUTOMATIC) CertElementId,
    VAR(uint32, AUTOMATIC) Index,
    P2VAR(uint8, AUTOMATIC, KEYM_APPL_DATA) CertElementDataPtr,
    P2VAR(uint32, AUTOMATIC, KEYM_APPL_DATA) CertElementDataLengthPtr)
{
    P2CONST(KeyM_CertEleType, AUTOMATIC, KEYM_CONST) certElePCfgPtr;
    P2VAR(KeyM_Asn1DesType, AUTOMATIC, KEYM_VAR) certEleBufPtr;
    uint32 idx;
    Std_ReturnType ret;

    ret = KeyM_CheckGeneralParam(
        CertId,
        CertElementId,
        CertElementDataPtr,
        CertElementDataLengthPtr,
        KEYM_CERT_ELEMENT_GET_BY_INDEX);
    if (ret == (Std_ReturnType)E_OK)
    {
        /*Index from 0..N*/
        Index++;
        certElePCfgPtr = &KeyM_CertPCfg[CertId].certEleRef[CertElementId];
        for (idx = 0; idx < Index; idx++)
        {
            if (idx == 0u)
            {
                certEleBufPtr = certElePCfgPtr->certEleBuf;
            }
            else if (certEleBufPtr->next != NULL_PTR)
            {
                certEleBufPtr = certEleBufPtr->next;
            }
            else
            {
                ret = E_NOT_OK;
                break;
            }
        }
        if (idx == Index)
        {
            KeyM_CopyData(CertElementDataPtr, certEleBufPtr->dataEle, certEleBufPtr->len);
            *CertElementDataLengthPtr = certEleBufPtr->len;
        }
    }

    return ret;
}

/*************************************************************************/
/*
 * Brief               This function provides the total number of data
 *                     elements that are available for the specified certificate element.
 * ServiceId           0x1c
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      CertId: Identifier of the certificate.
 *                     CertElementId:Specifies the certificate element.
 * Param-Name[out]     CountPtr: Pointer to the buffer where the number of available data elements
 *                     for this certificate element shall be copied to.
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 *                     E_OK
 *                     E_NOT_OK
 *                     KEYM_E_PARAMETER_MISMATCH
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE)
KeyM_CertificateElementGetCount(
    VAR(KeyM_CertificateIdType, AUTOMATIC) CertId,
    VAR(KeyM_CertElementIdType, AUTOMATIC) CertElementId,
    P2VAR(uint16, AUTOMATIC, KEYM_APPL_DATA) CountPtr)
{
    P2VAR(KeyM_Asn1DesType, AUTOMATIC, KEYM_VAR) certEleBufPtr;
    uint16 cnt = 0;
    Std_ReturnType ret = E_OK;

    if ((CertId >= KEYM_CERT_NUM) || (CertElementId > KeyM_CertPCfg[CertId].numOfCertEle))
    {
        ret = KEYM_E_PARAMETER_MISMATCH;
    }
    else
    {
        certEleBufPtr = KeyM_CertPCfg[CertId].certEleRef[CertElementId].certEleBuf;
        while (certEleBufPtr->next != NULL_PTR)
        {
            cnt++;
            certEleBufPtr = certEleBufPtr->next;
        }
        *CountPtr = cnt;
    }
    return ret;
}

/*************************************************************************/
/*
 * Brief               This function is used to initialize the interative extraction of a
 *                     certificate data element.
 * ServiceId           0x10
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      CertId: Holds the identifier of the last certificate in the chain.
 *                     CertElementId: Specifies the CertElementId where the data shall be read from.
 * Param-Name[out]     CertElementData: Pointer to a data buffer allocated by the caller of this function.
 * Param-Name[in/out]  CertElementIterator: Pointer to a structure that is allocated and
 *                                          maintained by the caller.
 *                     CertElementDataLength:
 *                       In: Pointer to a value that contains the maximum data length of the
 *                           CertElementData buffer.
 *                       Out: The data length will be overwritten with the actual length of data
 *                            placed to the buffer if the function returns E_OK. Otherwise, the
 *                            it will be overwritten with the value zero.
 * Return              Std_ReturnType
 *                     E_OK:  Element found and data provided in the buffer.
 *                     E_NOT_OK: Element data not found.
 *                     KEYM_E_BUSY:Validation cannot be performed yet. KeyM is
 *                                 currently busy with other jobs.
 *                     KEYM_E_PARAMETER_MISMATCH: Certificate ID invalid.
 *                     KEYM_E_KEY_CERT_SIZE_MISMATCH: Provided buffer for the certificate
 *                                                    element too small.
 *                     KEYM_E_KEY_CERT_EMPTY: No certificate data available, the certificate
 *                                            is empty
 *                     KEYM_E_CERT_INVALID: Certificate is not valid or not verified successfull
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE)
KeyM_CertElementGetFirst(
    VAR(KeyM_CertificateIdType, AUTOMATIC) CertId,
    VAR(KeyM_CertElementIdType, AUTOMATIC) CertElementId,
    P2VAR(KeyM_CertElementIteratorType, AUTOMATIC, KEYM_APPL_DATA) CertElementIterator,
    P2VAR(uint8, AUTOMATIC, KEYM_APPL_DATA) CertElementData,
    P2VAR(uint32, AUTOMATIC, KEYM_APPL_DATA) CertElementDataLength)
{
    Std_ReturnType ret;

    ret = KeyM_CheckGeneralParam(
        CertId,
        CertElementId,
        CertElementData,
        CertElementDataLength,
        KEYM_CERT_ELEMENT_GET_FIRST_ID);
    if (ret == (Std_ReturnType)E_OK)
    {
        /*Initialize CertElementIterator*/
        CertElementIterator->certId = CertId;
        CertElementIterator->certEleId = CertElementId;
        CertElementIterator->eleItrator = KeyM_CertPCfg[CertId].certEleRef[CertElementId].certEleBuf;

        KeyM_CopyData(
            CertElementData,
            KeyM_CertPCfg[CertId].certEleRef[CertElementId].certEleBuf->dataEle,
            KeyM_CertPCfg[CertId].certEleRef[CertElementId].certEleBuf->len);
        *CertElementDataLength = KeyM_CertPCfg[CertId].certEleRef[CertElementId].certEleBuf->len;
        CertElementIterator->eleItrator = CertElementIterator->eleItrator->next;
    }
    return ret;
}

/*************************************************************************/
/*
 * Brief               This function provides further data from a certificate element.
 * ServiceId           0x11
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      No
 * Param-Name[out]     CertElementData: Pointer to a data buffer allocated by the caller of this function.
 * Param-Name[in/out]  CertElementIterator: Pointer to a structure that is allocated and
 *                                          maintained by the caller.
 *                     CertElementDataLength:
 *                       In: Pointer to a value that contains the maximum data length of the
 *                           CertElementData buffer.
 *                       Out: The data length will be overwritten with the actual length of data
 *                            placed to the buffer if the function returns E_OK. Otherwise, the
 *                            it will be overwritten with the value zero.
 * Return              Std_ReturnType
 *                     E_OK:  Element found and data provided in the buffer.
 *                     E_NOT_OK: Element data not found.
 *                     KEYM_E_PARAMETER_MISMATCH: Certificate ID invalid.
 *                     KEYM_E_KEY_CERT_SIZE_MISMATCH: Provided buffer for the certificate
 *                                                    element too small.
 *                     KEYM_E_KEY_CERT_EMPTY: No certificate data available, the certificate
 *                                            is empty
 *                     KEYM_E_CERT_INVALID: Certificate is not valid or not verified successfull
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE)
KeyM_CertElementGetNext(
    P2VAR(KeyM_CertElementIteratorType, AUTOMATIC, KEYM_APPL_DATA) CertElementIterator,
    P2VAR(uint8, AUTOMATIC, KEYM_APPL_DATA) CertElementData,
    P2VAR(uint32, AUTOMATIC, KEYM_APPL_DATA) CertElementDataLength)
{
    P2CONST(KeyM_CertEleType, AUTOMATIC, KEYM_CONST) certElePCfgPtr;
    Std_ReturnType ret = E_NOT_OK;

    if (CertElementIterator != NULL_PTR)
    {
        ret = KeyM_CheckGeneralParam(
            CertElementIterator->certId,
            CertElementIterator->certEleId,
            CertElementData,
            CertElementDataLength,
            KEYM_CERT_ELEMENT_GET_NEXT_ID);
        if (ret == (Std_ReturnType)E_OK)
        {
            certElePCfgPtr = &KeyM_CertPCfg[CertElementIterator->certId].certEleRef[CertElementIterator->certEleId];
            /*SWS_KeyM_00148*/
            if (certElePCfgPtr->certEleHasIteration == (boolean)FALSE)
            {
                ret = KEYM_E_CERT_INVALID;
                goto KEYM_GET_ELENEXT_EXIT;
            }
            KeyM_CopyData(
                CertElementData,
                CertElementIterator->eleItrator->dataEle,
                CertElementIterator->eleItrator->len);
            *CertElementDataLength = CertElementIterator->eleItrator->len;

            CertElementIterator->eleItrator = CertElementIterator->eleItrator->next;
        }
    }
KEYM_GET_ELENEXT_EXIT:
    return ret;
}

/*************************************************************************/
/*
 * Brief               This function provides the status of a certificate.
 * ServiceId           0x12
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      CertId: Holds the identifier of the last certificate in the chain.
 * Param-Name[out]     Status: Provides the status of the certificate.
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 *                     E_OK
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE)
KeyM_CertGetStatus(
    VAR(KeyM_CertificateIdType, AUTOMATIC) CertId,
    P2VAR(KeyM_CertificateStatusType, AUTOMATIC, KEYM_APPL_DATA) Status)
{
    Std_ReturnType ret = E_OK;

    if (CertId >= KEYM_CERT_NUM)
    {
        ret = KEYM_E_PARAMETER_MISMATCH;
    }
    else
    {
        *Status = KeyM_CertStatus[CertId];
    }

    return ret;
}

FUNC(Std_ReturnType, KEYM_CODE)
KeyM_CertSetStatus(VAR(KeyM_CertificateIdType, AUTOMATIC) CertId, KeyM_CertificateStatusType Status)
{
    Std_ReturnType ret = E_OK;

    if (CertId >= KEYM_CERT_NUM)
    {
        ret = KEYM_E_PARAMETER_MISMATCH;
    }
    else
    {
        KeyM_CertStatus[CertId] = Status;
    }

    return ret;
}

FUNC(void, KEYM_CODE)
KeyM_CertStoreNvmHandle(void)
{
    uint16 nvmBlkIdx;

    for (nvmBlkIdx = 0u; nvmBlkIdx < KEYM_NVM_BLOCK_NUM; nvmBlkIdx++)
    {
        if (KeyM_BlkWriDelayRun[nvmBlkIdx].timeStart == TRUE)
        {
            KeyM_BlkWriDelayRun[nvmBlkIdx].delayTime--;
            if (KeyM_BlkWriDelayRun[nvmBlkIdx].delayTime == 0u)
            {
                NvM_WriteBlock(KeyM_NvmBlockPCfg[nvmBlkIdx].blkId, KeyM_BlkWriDelayRun[nvmBlkIdx].nvmCertEle->dataEle);
                KeyM_BlkWriDelayRun[nvmBlkIdx].timeStart = FALSE;
                KeyM_BlkWriDelayRun[nvmBlkIdx].nvmCertEle = NULL_PTR;
            }
        }
    }
}

FUNC(Std_ReturnType, KEYM_CODE)
KeyM_HandleParseCert(
    KeyM_CertificateIdType CertId,
    P2CONST(uint8, AUTOMATIC, KEYM_APPL_CONST) certDataPtr,
    uint32 certDataLength)
{
    P2CONST(KeyM_CertPCfgType, AUTOMATIC, KEYM_CONST) certCfgPtr;
    P2VAR(uint8, TYPEDEF, KEYM_VAR) certStartPtr;
    P2VAR(uint8, TYPEDEF, KEYM_VAR) tbsPtr;
    P2VAR(uint8, TYPEDEF, KEYM_VAR) certendPtr;
    P2VAR(uint8, TYPEDEF, KEYM_VAR) certTotalendPtr;
    uint32 certEleLen;
    KeyM_Asn1DesType sifParam;
    Std_ReturnType ret = E_OK;

    certCfgPtr = &KeyM_CertPCfg[CertId];
    certStartPtr = (uint8*)certDataPtr;
    certEleLen = certDataLength;
    certendPtr = certStartPtr + certEleLen;
    /*
     * Certificate  ::=  SEQUENCE  {
     *      tbsCertificate       TBSCertificate,
     *      signatureAlgorithm   AlgorithmIdentifier,
     *      signatureValue       BIT STRING  }
     */
    ret = KeyM_CertGetAsn1Tag(&certStartPtr, certendPtr, &certEleLen, KEYM_CERT_ASN1_SEQ_CONSTRU);
    if (ret != E_OK)
    {
        goto PARSE_CERT_EXIT;
    }
    certendPtr = certStartPtr + certEleLen;
    certTotalendPtr = certendPtr;
    /*
     * TBSCertificate  ::=  SEQUENCE  {
     */
    tbsPtr = certStartPtr;
    ret = KeyM_CertGetAsn1Tag(&certStartPtr, certendPtr, &certEleLen, KEYM_CERT_ASN1_SEQ_CONSTRU);
    if (ret != E_OK)
    {
        goto PARSE_CERT_EXIT;
    }
    certendPtr = certStartPtr + certEleLen;
    /*Save tbs-Certificate*/
    if (certendPtr - tbsPtr > certCfgPtr->certMaxLen)
    {
        ret = E_NOT_OK;
        goto PARSE_CERT_EXIT;
    }
    certCfgPtr->tbsCert->len = certendPtr - tbsPtr;
    /*Use tag record TBS position.*/
    certCfgPtr->tbsCert->tag = tbsPtr - (uint8*)certDataPtr;

    if (*certStartPtr == KEYM_CERT_ASN1_TAG)
    {
        /*
         * Version  ::=  INTEGER  {v1(0), v2(1), v3(2)}
         */
        ret = KeyM_CertGetVersion(CertId, &certStartPtr, certendPtr);
        if (ret != E_OK)
        {
            goto PARSE_CERT_EXIT;
        }
    }
    else if (*certStartPtr != KEYM_CERT_ASN1_INTEGER)
    {
        goto PARSE_CERT_EXIT;
    }
    /*CertificateSerialNumber  ::=  INTEGER*/
    ret = KeyM_CertGetSerialVersion(CertId, &certStartPtr, certendPtr);
    if (ret != E_OK)
    {
        goto PARSE_CERT_EXIT;
    }
    /*Signature AlgorithmIdentifier*/
    ret = KeyM_CertGetSigAlgorithmId(CertId, &certStartPtr, certendPtr, &sifParam);
    if (ret != E_OK)
    {
        goto PARSE_CERT_EXIT;
    }
    /*
     * Issuer Name
     */
    ret = KeyM_CertGetAsn1Tag(&certStartPtr, certendPtr, &certEleLen, KEYM_CERT_ASN1_SEQ_CONSTRU);
    if (ret != E_OK)
    {
        goto PARSE_CERT_EXIT;
    }
    ret = KeyM_CertGetName(
        CertId,
        &certStartPtr,
        certStartPtr + certEleLen,
        CERTIFICATE_ISSUER_NAME,
        CERTIFICATE_ISSUER_UNIQUE_IDENTIFIER);
    if (ret != E_OK)
    {
        goto PARSE_CERT_EXIT;
    }
    /*
     * Validity ::= SEQUENCE {
     *      notBefore      Time,
     *      notAfter       Time }
     *
     */
    ret = KeyM_CertGetTime(CertId, &certStartPtr, certendPtr);
    if (ret != E_OK)
    {
        goto PARSE_CERT_EXIT;
    }
    /*
     * subject Name
     * */
    ret = KeyM_CertGetAsn1Tag(&certStartPtr, certendPtr, &certEleLen, KEYM_CERT_ASN1_SEQ_CONSTRU);
    if (ret != E_OK)
    {
        goto PARSE_CERT_EXIT;
    }
    ret = KeyM_CertGetName(
        CertId,
        &certStartPtr,
        certStartPtr + certEleLen,
        CERTIFICATE_SUBJECT_NAME,
        CERTIFICATE_SUBJECT_UNIQUE_IDENTIFIER);
    if (ret != E_OK)
    {
        goto PARSE_CERT_EXIT;
    }
    /*
     *  SubjectPublicKeyInfo  ::=  SEQUENCE  {
     *       algorithm            AlgorithmIdentifier,
     *       subjectPublicKey     BIT STRING }
     */
    ret = KeyM_CertGetPubKeyInfo(CertId, &certStartPtr, certendPtr);
    if (ret != E_OK)
    {
        goto PARSE_CERT_EXIT;
    }
    /*
     *  issuerUniqueID  [1]  IMPLICIT UniqueIdentifier OPTIONAL,
     *                       -- If present, version shall be v2 or v3
     *  subjectUniqueID [2]  IMPLICIT UniqueIdentifier OPTIONAL,
     *                       -- If present, version shall be v2 or v3
     */
    if ((KeyM_CertVersion[CertId] == KEYM_CONST_1) || (KeyM_CertVersion[CertId] == KEYM_CONST_2))
    {
        /*Skip issuerUniqueID & subjectUniqueID*/
        KeyM_CertSkipField(&certStartPtr, certendPtr, 0xa1);
        KeyM_CertSkipField(&certStartPtr, certendPtr, 0xa1);
    }
    /*  extensions      [3]  EXPLICIT Extensions OPTIONAL
     *                       -- If present, version shall be v3
     * */
    if (KeyM_CertVersion[CertId] == KEYM_CONST_2)
    {
        ret = KeyM_CertGetExtention(CertId, &certStartPtr, certendPtr);
        if (ret != E_OK)
        {
            goto PARSE_CERT_EXIT;
        }
    }
    /*Check if validation completes TBS field*/
    if (certStartPtr != certendPtr)
    {
        ret = KEYM_E_KEY_CERT_INVALID;
    }
    else
    {
        /*1.Skip signatureAlgorithm AlgorithmIdentifie.
         * This field MUST contain the same algorithm identifier as the signature field in the sequence
         * tbsCertificater*/
        certendPtr = certTotalendPtr;
        KeyM_CertSkipField(&certStartPtr, certendPtr, KEYM_CERT_ASN1_SEQ_CONSTRU);
        /*Store signature*/
        ret = KeyM_CertGetSignature(CertId, &certStartPtr, certendPtr);
        if ((ret != E_OK) || (certStartPtr != certendPtr))
        {
            ret = KEYM_E_KEY_CERT_INVALID;
        }
        else
        {
            /*Parsing operation has been completed without failure*/
            KeyM_CertStatus[CertId] = KEYM_CERTIFICATE_PARSED_NOT_VALIDATED;
            KeyM_CopyData(certCfgPtr->tbsCert->dataEle, certDataPtr, certDataLength);
        }
    }
PARSE_CERT_EXIT:
    if (ret != E_OK)
    {
        KeyM_CertSetStatus(CertId, KEYM_E_CERTIFICATE_INVALID_FORMAT);
    }
    return ret;
}

/*keySet = TRUE:Storrage KeyElement.
 * keySet = FALSE:Get KeyElement.
 * */
FUNC(void, KEYM_CODE)
KeyM_HandleCsmKeyStorage(uint32 keyId, uint16 certId, boolean keySet)
{
    P2CONST(KeyM_CertPCfgType, AUTOMATIC, KEYM_CONST) certCfgPtr;
    P2CONST(KeyM_CertEleType, AUTOMATIC, KEYM_CONST) certEleRef;
    uint32 keyElementId;
    uint16 certEle;

    certCfgPtr = &KeyM_CertPCfg[certId];
    for (certEle = 0u; certEle < certCfgPtr->numOfCertEle; certEle++)
    {
        certEleRef = &certCfgPtr->certEleRef[certEle];
        switch (certEleRef->certEleStruct)
        {
        case CERTIFICATE_VERSION_NUMBER:
            keyElementId = CRYPTO_KE_CERTIFICATE_VERSION;
            break;
        case CERTIFICATE_SERIAL_NUMBER:
            keyElementId = CRYPTO_KE_CERTIFICATE_SERIALNUMBER;
            break;
        case CERTIFICATE_SIGNATURE_ALGORITHM:
            keyElementId = CRYPTO_KE_CERTIFICATE_SIGNATURE_ALGORITHM;
            break;
        case CERTIFICATE_ISSUER_NAME:
            keyElementId = CRYPTO_KE_CERTIFICATE_ISSUER;
            break;
        case CERTIFICATE_VALIDITY_PERIOD_NOT_BEFORE:
            keyElementId = CRYPTO_KE_CERTIFICATE_VALIDITY_NOT_BEFORE;
            break;
        case CERTIFICATE_VALIDITY_PERIOD_NOT_AFTER:
            keyElementId = CRYPTO_KE_CERTIFICATE_VALIDITY_NOT_AFTER;
            break;
        case CERTIFICATE_SUBJECT_NAME:
            keyElementId = CRYPTO_KE_CERTIFICATE_SUBJECT;
            break;
        case CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_SUBJECT_PUBLIC_KEY:
            keyElementId = CRYPTO_KE_CERTIFICATE_SUBJECT_PUBLIC_KEY;
            break;
        case CERTIFICATE_SIGNATURE:
            keyElementId = CRYPTO_KE_CERTIFICATE_SIGNATURE;
            break;
        case CERTIFICATE_EXTENSION:
            keyElementId = CRYPTO_KE_CERTIFICATE_EXTENSIONS;
            break;
        default:
            keyElementId = KEYM_INVALID_U32;
            break;
        }
        if (keyElementId != KEYM_INVALID_U32)
        {
            if (keySet == TRUE)
            {
                (void)Csm_KeyElementSet(
                    keyId,
                    keyElementId,
                    certEleRef->certEleBuf->dataEle,
                    certEleRef->certEleBuf->len);
            }
            else
            {
                (void)Csm_KeyElementGet(
                    keyId,
                    keyElementId,
                    certEleRef->certEleBuf->dataEle,
                    &certEleRef->certEleBuf->len);
            }
        }
    }
}
#define KEYM_STOP_SEC_CODE
#include "KeyM_MemMap.h"
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
static FUNC(Std_ReturnType, KEYM_CODE) KeyM_CheckGeneralParam(
    VAR(KeyM_CertificateIdType, AUTOMATIC) CertId,
    VAR(KeyM_CertElementIdType, AUTOMATIC) CertElementId,
    P2VAR(uint8, AUTOMATIC, KEYM_APPL_DATA) CertElementData,
    P2VAR(uint32, AUTOMATIC, KEYM_APPL_DATA) CertElementDataLength,
    uint8 ApiId)
{
    Std_ReturnType ret = E_OK;

    if ((boolean)FALSE == KeyM_InitStatus)
    {
#if (STD_ON == KEYM_DEVERROR_DETECT)
        KEYM_DET_REPORT(ApiId, KEYM_E_UNINIT);
#endif /*(STD_ON == KEYM_DEVERROR_DETECT)*/
        ret = E_NOT_OK;
    }
    else if ((CertElementData == NULL_PTR) || (CertElementDataLength == NULL_PTR))
    {
#if (STD_ON == KEYM_DEVERROR_DETECT)
        KEYM_DET_REPORT(ApiId, KEYM_E_PARAM_POINTER);
#endif /*(STD_ON == KEYM_DEVERROR_DETECT)*/
        ret = E_NOT_OK;
    }
    else
    {
        if ((CertId >= KEYM_CERT_NUM) || (CertElementId > KeyM_CertPCfg[CertId].numOfCertEle))
        {
            ret = KEYM_E_PARAMETER_MISMATCH;
        }
        else if (*CertElementDataLength < KeyM_CertPCfg[CertId].certEleRef[CertElementId].certEleMaxLen)
        {
            ret = KEYM_E_KEY_CERT_SIZE_MISMATCH;
        }
        else if (KeyM_CertStatus[CertId] != KEYM_CERTIFICATE_VALID)
        {
            ret = KEYM_E_KEY_CERT_INVALID;
        }
        else if (KeyM_CertPCfg[CertId].certEleRef[CertElementId].certEleBuf->len == 0U)
        {
            ret = KEYM_E_KEY_CERT_EMPTY;
        }
    }
    return ret;
}

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_IsCertExist(
    KeyM_CertificateIdType certId,
    KeyM_CertEleStructType certStr,
    P2VAR(uint16, AUTOMATIC, KEYM_APPL_DATA) cfgId)
{
    P2CONST(KeyM_CertEleType, AUTOMATIC, KEYM_CONST) certEleCfgPtr;
    uint16 idx;
    Std_ReturnType ret = E_NOT_OK;

    for (idx = 0; idx < KeyM_CertPCfg[certId].numOfCertEle; idx++)
    {
        certEleCfgPtr = &KeyM_CertPCfg[certId].certEleRef[idx];
        if (certEleCfgPtr->certEleStruct == certStr)
        {
            ret = E_OK;
            if (cfgId != NULL_PTR)
            {
                *cfgId = idx;
            }
            break;
        }
    }
    return ret;
}

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_FindCertElement(
    KeyM_CertificateIdType certId,
    P2VAR(KeyM_CertEleType, AUTOMATIC, KEYM_APPL_DATA) certEle,
    P2VAR(uint16, AUTOMATIC, KEYM_APPL_DATA) eleIdx)
{
    P2CONST(KeyM_CertEleType, AUTOMATIC, KEYM_CONST) certEleCfgPtr;
    uint16 idx;
    uint16 len;
    Std_ReturnType ret = E_NOT_OK;
    boolean oidCheck = FALSE;

    for (idx = 0; idx < KeyM_CertPCfg[certId].numOfCertEle; idx++)
    {
        certEleCfgPtr = &KeyM_CertPCfg[certId].certEleRef[idx];
        if ((certEleCfgPtr->certEleMaxLen < certEle->certEleMaxLen)
            || (certEleCfgPtr->certEleStruct != certEle->certEleStruct))
        {
            continue;
        }
        else
        {
            /*Check KeyMCertificateElementObjectType*/
            if ((certEleCfgPtr->certEleObjType != NULL_PTR) && (certEle->certEleObjType != NULL_PTR))
            {
                if (((*certEleCfgPtr->certEleObjType) & (*certEle->certEleObjType)) == 0u)
                {
                    continue;
                }
            }
            /*Check KeyMCertificateElementObjectId*/
            if ((certEleCfgPtr->certEleObjId != NULL_PTR) && (certEleCfgPtr->certEleObjIdLen != 0u)
                && (certEle->certEleObjId != NULL_PTR))
            {
                for (len = 0u; len < certEleCfgPtr->certEleObjIdLen; len++)
                {
                    if (certEleCfgPtr->certEleObjId[len] != certEle->certEleObjId[len])
                    {
                        break;
                    }
                }
                if (len == certEleCfgPtr->certEleObjIdLen)
                {
                    oidCheck = TRUE;
                }
            }
            else
            {
                /*No need to check*/
                oidCheck = TRUE;
            }

            if (oidCheck == TRUE)
            {
                *eleIdx = idx;
                ret = E_OK;
                break;
            }
        }
    }
    return ret;
}

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertEleHandle(
    KeyM_CertificateIdType certId,
    P2VAR(KeyM_CertEleType, AUTOMATIC, KEYM_APPL_DATA) certEle,
    P2VAR(uint8, AUTOMATIC, KEYM_APPL_DATA) eleData,
    uint32 tag)
{
    uint16 eleCfgIndex;
    uint16 eleIdx;
    Std_ReturnType ret;

    ret = KeyM_FindCertElement(certId, certEle, &eleCfgIndex);
    if (ret == (Std_ReturnType)E_OK)
    {
        for (eleIdx = 0u; eleIdx < certEle->certEleMaxLen; eleIdx++)
        {
            KeyM_CertPCfg[certId].certEleRef[eleCfgIndex].certEleBuf->dataEle[eleIdx] = eleData[eleIdx];
        }
        KeyM_CertPCfg[certId].certEleRef[eleCfgIndex].certEleBuf->tag = tag;
        KeyM_CertPCfg[certId].certEleRef[eleCfgIndex].certEleBuf->len = certEle->certEleMaxLen;
    }
    return ret;
}

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertGetAsn1Tag(
    P2VAR(uint8*, AUTOMATIC, KEYM_APPL_DATA) cerS,
    P2CONST(uint8, TYPEDEF, KEYM_CONST) cerE,
    P2VAR(uint32, AUTOMATIC, KEYM_APPL_DATA) cerLenPtr,
    uint8 tag)
{
    Std_ReturnType ret = E_OK;

    if (((cerE - *cerS) < KEYM_CONST_1) || (**cerS != tag))
    {
        ret = E_NOT_OK;
    }
    else
    {
        (*cerS)++;
        ret = KeyM_CertGetAsn1Len(cerS, cerE, cerLenPtr);
    }

    return ret;
}

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertGetAsn1Len(
    P2VAR(uint8*, AUTOMATIC, KEYM_APPL_DATA) cerS,
    P2CONST(uint8, TYPEDEF, KEYM_CONST) cerE,
    P2VAR(uint32, AUTOMATIC, KEYM_APPL_DATA) cerLen)
{
    Std_ReturnType ret = E_OK;

    if ((**cerS & KEYM_LONG_FORMAT_MASK) == 0u)
    {
        *cerLen = *(*cerS)++;
    }
    else /*length > 127*/
    {
        switch (**cerS & (KEYM_LONG_FORMAT_MASK - KEYM_CONST_1))
        {
        case KEYM_CONST_1:
            if ((cerE - *cerS) < KEYM_CONST_2)
            {
                ret = E_NOT_OK;
                goto ASNLEN_EXIT;
            }
            *cerLen = (*cerS)[1];
            (*cerS) += 2;
            break;
        case KEYM_CONST_2:
            if ((cerE - *cerS) < KEYM_CONST_3)
            {
                ret = E_NOT_OK;
                goto ASNLEN_EXIT;
            }
            *cerLen = ((uint32)(*cerS)[1u] << 8u) | (*cerS)[2u];
            (*cerS) += 3u;
            break;
        case KEYM_CONST_3:
            if ((cerE - *cerS) < KEYM_CONST_4)
            {
                ret = E_NOT_OK;
                goto ASNLEN_EXIT;
            }
            *cerLen = ((uint32)(*cerS)[1u] << 16u) | ((uint32)(*cerS)[2u] << 8u) | (*cerS)[3u];
            (*cerS) += 4u;
            break;
        case KEYM_CONST_4:
            if ((cerE - *cerS) < KEYM_CONST_5)
            {
                ret = E_NOT_OK;
                goto ASNLEN_EXIT;
            }
            *cerLen =
                ((uint32)(*cerS)[1u] << 24u) | ((uint32)(*cerS)[2u] << 16u) | ((uint32)(*cerS)[3u] << 8u) | (*cerS)[4u];
            (*cerS) += 5u;
            break;
        default:
            ret = E_NOT_OK;
            break;
        }
    }
    if (*cerLen > (uint32)(cerE - *cerS))
    {
        ret = E_NOT_OK;
    }
ASNLEN_EXIT:
    return ret;
}

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertGetAsn1TagInt(
    P2VAR(uint8*, AUTOMATIC, KEYM_APPL_DATA) cerS,
    P2CONST(uint8, TYPEDEF, KEYM_CONST) cerE,
    P2VAR(uint8, AUTOMATIC, KEYM_APPL_DATA) intVal,
    P2VAR(uint32, AUTOMATIC, KEYM_APPL_DATA) cerLen)
{
    uint32 len;
    Std_ReturnType ret;

    *intVal = 0u;
    ret = KeyM_CertGetAsn1Tag(cerS, cerE, &len, KEYM_CERT_ASN1_INTEGER);
    if ((ret == (Std_ReturnType)E_OK) && (len > 0u) && (len <= 4u) && ((**cerS & KEYM_LONG_FORMAT_MASK) == 0u))
    {
        *cerLen = len;
        /*Skip leading zeros.*/
        while ((len > 0u) && (**cerS == 0u))
        {
            ++(*cerS);
            --len;
        }
        while (len-- > 0)
        {
            *intVal = (*intVal << 8u) | **cerS;
            (*cerS)++;
        }
    }
    else
    {
        ret = E_NOT_OK;
    }
    return ret;
}

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertGetVersion(
    KeyM_CertificateIdType certId,
    P2VAR(uint8*, AUTOMATIC, KEYM_APPL_DATA) cerS,
    P2CONST(uint8, TYPEDEF, KEYM_CONST) cerE)
{
    uint32 cerLen;
    uint16 eleIdx;
    Std_ReturnType ret;
    uint8 ver;

    ret = KeyM_CertGetAsn1Tag(cerS, cerE, &cerLen, KEYM_CERT_ASN1_TAG);
    if (ret == (Std_ReturnType)E_OK)
    {
        cerE = *cerS + cerLen;
        ret = KeyM_CertGetAsn1TagInt(cerS, cerE, &ver, &cerLen);
        if ((ret != E_OK) || (*cerS != cerE))
        {
            ret = E_NOT_OK;
        }
        else
        {
            ret = KeyM_IsCertExist(certId, CERTIFICATE_VERSION_NUMBER, &eleIdx);
            if (E_OK == ret)
            {
                KeyM_CertVersion[certId] = ver;
                KeyM_CertPCfg[certId].certEleRef[eleIdx].certEleBuf->dataEle[0] = ver;
            }
        }
    }
    return ret;
}

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertGetSerialVersion(
    KeyM_CertificateIdType certId,
    P2VAR(uint8*, AUTOMATIC, KEYM_APPL_DATA) cerS,
    P2CONST(uint8, TYPEDEF, KEYM_CONST) cerE)
{
    uint32 tag;
    uint32 cerLen;
    KeyM_CertEleType certEle;
    uint8 objType = KEYM_CERT_ASN1_INTEGER;
    Std_ReturnType ret = E_OK;

    if (((cerE - *cerS) < KEYM_CONST_1) || (**cerS != KEYM_CERT_ASN1_INTEGER))
    {
        ret = E_NOT_OK;
    }
    else
    {
        tag = *(*cerS)++;
        ret = KeyM_CertGetAsn1Len(cerS, cerE, &cerLen);
        if (ret == (Std_ReturnType)E_OK)
        {
            certEle.certEleMaxLen = cerLen;
            certEle.certEleObjType = &objType;
            certEle.certEleStruct = CERTIFICATE_SERIAL_NUMBER;
            ret = KeyM_CertEleHandle(certId, &certEle, *cerS, tag);
            if (ret == (Std_ReturnType)E_OK)
            {
                *cerS += cerLen;
            }
        }
    }
    return ret;
}

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertGetSigAlgorithmId(
    KeyM_CertificateIdType certId,
    P2VAR(uint8*, AUTOMATIC, KEYM_APPL_DATA) cerS,
    P2CONST(uint8, TYPEDEF, KEYM_CONST) cerE,
    P2VAR(KeyM_Asn1DesType, AUTOMATIC, KEYM_APPL_DATA) sigPar)
{
    uint32 tag;
    uint32 cerLen;
    KeyM_CertEleType certEle;
    uint8 objType = KEYM_CERT_ASN1_OID;
    Std_ReturnType ret;

    ret = KeyM_CertGetAsn1Tag(cerS, cerE, &cerLen, KEYM_CERT_ASN1_SEQ_CONSTRU);
    if ((ret == (Std_ReturnType)E_OK) || ((cerE - *cerS) < KEYM_CONST_1))
    {
        tag = **cerS;
        cerE = *cerS + cerLen;
        ret = KeyM_CertGetAsn1Tag(cerS, cerE, &cerLen, KEYM_CERT_ASN1_OID);
        if (ret != E_OK)
        {
            goto SIGALGO_EXIT;
        }
        certEle.certEleMaxLen = cerLen;
        certEle.certEleObjType = &objType;
        certEle.certEleStruct = CERTIFICATE_SIGNATURE_ALGORITHM_ID;
        ret = KeyM_CertEleHandle(certId, &certEle, *cerS, tag);
        if (ret != E_OK)
        {
            goto SIGALGO_EXIT;
        }
        *cerS += cerLen;

        if (*cerS != cerE)
        {
            sigPar->tag = **cerS;
            (*cerS)++;
            ret = KeyM_CertGetAsn1Len(cerS, cerE, &sigPar->len);
            if (ret != E_OK)
            {
                goto SIGALGO_EXIT;
            }
            sigPar->dataEle = *cerS;
            *cerS += sigPar->len;
            if (*cerS != cerE)
            {
                ret = E_NOT_OK;
            }
        }
    }
SIGALGO_EXIT:
    return ret;
}

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertHandleName(
    P2VAR(uint8*, AUTOMATIC, KEYM_APPL_DATA) cerS,
    P2CONST(uint8, TYPEDEF, KEYM_CONST) cerE,
    P2VAR(KeyM_Asn1DesType, TYPEDEF, KEYM_APPL_DATA) isuName,
    P2VAR(KeyM_Asn1DesType, TYPEDEF, KEYM_APPL_DATA) isuNameOid)
{
    uint32 len;
    Std_ReturnType ret;

    ret = KeyM_CertGetAsn1Tag(cerS, cerE, &len, KEYM_CERT_ASN1_SEQ_CONSTRU);
    if (ret != E_OK)
    {
        goto HADLE_ISSUER;
    }
    cerE = *cerS + len;
    if ((cerE - *cerS) < KEYM_CONST_1)
    {
        ret = E_NOT_OK;
        goto HADLE_ISSUER;
    }
    isuNameOid->tag = **cerS;
    ret = KeyM_CertGetAsn1Tag(cerS, cerE, &isuNameOid->len, KEYM_CERT_ASN1_OID);
    if (ret != E_OK)
    {
        goto HADLE_ISSUER;
    }
    KeyM_CopyData(isuNameOid->dataEle, *cerS, isuNameOid->len);
    *cerS += isuNameOid->len;

    if (((cerE - *cerS) < KEYM_CONST_1)
        || ((**cerS != KEYM_CERT_ASN1_BIT_STRING) && (**cerS != KEYM_CERT_ASN1_OCTET_STRING)
            && (**cerS != KEYM_CERT_ASN1_UINT8_STRING) && (**cerS != KEYM_CERT_ASN1_ASCII_STRING)))
    {
        ret = E_NOT_OK;
        goto HADLE_ISSUER;
    }
    isuName->tag = **cerS;
    (*cerS)++;
    ret = KeyM_CertGetAsn1Len(cerS, cerE, &isuName->len);
    if (ret != E_OK)
    {
        goto HADLE_ISSUER;
    }
    KeyM_CopyData(isuName->dataEle, *cerS, isuName->len);
    *cerS += isuName->len;
    if (*cerS != cerE)
    {
        ret = E_NOT_OK;
        goto HADLE_ISSUER;
    }
HADLE_ISSUER:
    return ret;
}

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertGetName(
    KeyM_CertificateIdType certId,
    P2VAR(uint8*, AUTOMATIC, KEYM_APPL_DATA) cerS,
    P2CONST(uint8, TYPEDEF, KEYM_CONST) cerE,
    KeyM_CertEleStructType eleNameType,
    KeyM_CertEleStructType eleNameOidType)
{
    P2CONST(uint8, TYPEDEF, KEYM_CONST) cerEndSet;
    uint16 nameCfgId;
    P2VAR(KeyM_Asn1DesType, TYPEDEF, KEYM_VAR) nameEleBuf;
    uint16 nameOidCfgId;
    P2VAR(KeyM_Asn1DesType, TYPEDEF, KEYM_VAR) nameOidEleBuf;
    uint32 setLen;
    Std_ReturnType ret;

    ret = KeyM_IsCertExist(certId, eleNameType, &nameCfgId);
    if (ret != E_OK)
    {
        goto ISSUER_NAME;
    }
    nameEleBuf = KeyM_CertPCfg[certId].certEleRef[nameCfgId].certEleBuf;

    ret = KeyM_IsCertExist(certId, eleNameOidType, &nameOidCfgId);
    if (ret != E_OK)
    {
        goto ISSUER_NAME;
    }
    nameOidEleBuf = KeyM_CertPCfg[certId].certEleRef[nameOidCfgId].certEleBuf;

    for (;;)
    {
        /*Traverse all SET.*/
        ret = KeyM_CertGetAsn1Tag(cerS, cerE, &setLen, KEYM_CERT_ASN1_SET_CONSTRU);
        if (ret != E_OK)
        {
            goto ISSUER_NAME;
        }
        cerEndSet = *cerS + setLen;
        for (;;)
        {
            if ((nameEleBuf == NULL_PTR) || (nameOidEleBuf == NULL_PTR))
            {
                ret = E_NOT_OK;
                goto ISSUER_NAME;
            }
            /*Handle a SET instance.*/
            ret = KeyM_CertHandleName(cerS, cerEndSet, nameEleBuf, nameOidEleBuf);
            if (ret != E_OK)
            {
                goto ISSUER_NAME;
            }
            if (*cerS == cerEndSet)
            {
                break;
            }
        }
        if (*cerS == cerE)
        {
            break;
        }
        nameEleBuf = nameEleBuf->next;
        nameOidEleBuf = nameOidEleBuf->next;
    }
ISSUER_NAME:
    return ret;
}

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertParseTimeEle(
    P2VAR(uint8*, AUTOMATIC, KEYM_APPL_DATA) ele,
    uint32 len,
    P2VAR(uint32, AUTOMATIC, KEYM_APPL_DATA) time)
{
    uint32 eleLen = len;
    Std_ReturnType ret = E_OK;

    for (; eleLen > 0u; --eleLen)
    {
        /*'0' <--> 0x30*/
        /*'9' <--> 0x39*/
        if ((**ele < 0x30) || (**ele > 0x39))
        {
            ret = KEYM_E_KEY_CERT_INVALID;
            break;
        }
        else
        {
            /*ASCII convert*/
            *time *= 10u;
            *time += (*(*ele)++ - 0x30);
        }
    }
    return ret;
}

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertCheckDate(P2VAR(KeyM_CertTimeType, AUTOMATIC, KEYM_APPL_DATA) time)
{
    uint32 mon;
    Std_ReturnType ret = E_NOT_OK;

    KEYM_CHECK_RANGE(0, 9999, time->certYear);
    KEYM_CHECK_RANGE(0, 23, time->certHour);
    KEYM_CHECK_RANGE(0, 59, time->certMin);
    KEYM_CHECK_RANGE(0, 59, time->certSec);

    /*Calculate how many days in this month*/
    switch (time->certMon)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        mon = 31u;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        mon = 30u;
        break;
    case 2:
        if ((!(time->certYear % 4) && time->certYear % 100) || !(time->certYear % 400))
            mon = 29;
        else
            mon = 28;
        break;
    default:
        return ret;
    }
    KEYM_CHECK_RANGE(0, mon, time->certMon);
    return E_OK;
}

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertParseTime(
    uint32 len,
    uint32 yearLen,
    P2VAR(uint8*, AUTOMATIC, KEYM_APPL_DATA) cerS,
    P2VAR(KeyM_CertTimeType, AUTOMATIC, KEYM_APPL_DATA) time)
{
    Std_ReturnType ret = E_NOT_OK;
    /*Minimum length is 10 or 12 depending on yearLen*/
    if (len >= yearLen + 8u)
    {
        len -= yearLen + 8u;
        /*Parse year, month, day, hour, minute*/
        ret = KeyM_CertParseTimeEle(cerS, yearLen, &time->certYear);
        if (ret != E_OK)
        {
            goto PARSE_TIME;
        }
        if (KEYM_CONST_2 == yearLen)
        {
            if (time->certYear < 50u)
            {
                time->certYear += 100;
            }
            time->certYear += 1900;
        }
        ret = KeyM_CertParseTimeEle(cerS, 2u, &time->certMon);
        if (ret != E_OK)
        {
            goto PARSE_TIME;
        }
        ret = KeyM_CertParseTimeEle(cerS, 2u, &time->certDay);
        if (ret != E_OK)
        {
            goto PARSE_TIME;
        }
        ret = KeyM_CertParseTimeEle(cerS, 2u, &time->certHour);
        if (ret != E_OK)
        {
            goto PARSE_TIME;
        }
        ret = KeyM_CertParseTimeEle(cerS, 2u, &time->certMin);
        if (ret != E_OK)
        {
            goto PARSE_TIME;
        }
        /*Parse seconds if present*/
        if (len >= 2u)
        {
            ret = KeyM_CertParseTimeEle(cerS, 2u, &time->certSec);
            if (ret != E_OK)
            {
                goto PARSE_TIME;
            }
            len -= 2u;
        }
        else
        {
            ret = KEYM_E_KEY_CERT_INVALID;
        }
        /*Parse trailing 'Z' if present
         * Zulu Time
         * */
        if (KEYM_CONST_1 == len && 'Z' == **cerS)
        {
            (*cerS)++;
            len--;
        }
        if (len != 0u)
        {
            ret = E_NOT_OK;
        }
        /*Finnal:Check if date is valid*/
        ret = KeyM_CertCheckDate(time);
    }
PARSE_TIME:
    return ret;
}

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertHandleGetTime(
    KeyM_CertificateIdType certId,
    P2VAR(uint8*, AUTOMATIC, KEYM_APPL_DATA) cerS,
    P2CONST(uint8, TYPEDEF, KEYM_CONST) cerE,
    P2VAR(KeyM_CertTimeType, AUTOMATIC, KEYM_APPL_DATA) time,
    KeyM_CertEleStructType eleStrut)
{
    uint32 yearLen;
    uint32 len;
    KeyM_CertEleType certEle;
    Std_ReturnType ret = E_NOT_OK;
    uint8 timeTag;

    if ((cerE - *cerS) >= KEYM_CONST_1)
    {
        timeTag = **cerS;
        if (timeTag == KEYM_CERT_ASN1_UTC_TIME)
        {
            yearLen = 2u;
        }
        else if (timeTag == KEYM_CERT_ASN1_GENERALIZED_TIME)
        {
            yearLen = 4u;
        }
        else
        {
            ret = KEYM_E_KEY_CERT_INVALID;
            goto HANDLE_TIME;
        }
        (*cerS)++;
        ret = KeyM_CertGetAsn1Len(cerS, cerE, &len);
        if (ret != E_OK)
        {
            goto HANDLE_TIME;
        }
        certEle.certEleMaxLen = len;
        certEle.certEleObjType = &timeTag;
        certEle.certEleStruct = eleStrut;
        ret = KeyM_CertEleHandle(certId, &certEle, *cerS, timeTag);
        if (ret != E_OK)
        {
            goto HANDLE_TIME;
        }
        ret = KeyM_CertParseTime(len, yearLen, cerS, time);
    }
HANDLE_TIME:
    return ret;
}

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertGetTime(
    KeyM_CertificateIdType certId,
    P2VAR(uint8*, AUTOMATIC, KEYM_APPL_DATA) cerS,
    P2CONST(uint8, TYPEDEF, KEYM_CONST) cerE)
{
    uint32 len;
    Std_ReturnType ret;

    ret = KeyM_CertGetAsn1Tag(cerS, cerE, &len, KEYM_CERT_ASN1_SEQ_CONSTRU);
    if (ret != E_OK)
    {
        goto GET_TIME_EXIT;
    }
    cerE = *cerS + len;
    /*Validity Not Before Time*/
    ret =
        KeyM_CertHandleGetTime(certId, cerS, cerE, &KeyM_CertStartTime[certId], CERTIFICATE_VALIDITY_PERIOD_NOT_BEFORE);
    if (ret != E_OK)
    {
        goto GET_TIME_EXIT;
    }
    /*Validity Not After Time*/
    ret = KeyM_CertHandleGetTime(certId, cerS, cerE, &KeyM_CertEndTime[certId], CERTIFICATE_VALIDITY_PERIOD_NOT_AFTER);
    if (ret != E_OK)
    {
        goto GET_TIME_EXIT;
    }
    if (*cerS != cerE)
    {
        ret = E_NOT_OK;
    }
GET_TIME_EXIT:
    return ret;
}

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertHandleGetPubKeyAlgo(
    KeyM_CertificateIdType certId,
    P2VAR(uint8*, AUTOMATIC, KEYM_APPL_DATA) cerS,
    P2CONST(uint8, TYPEDEF, KEYM_CONST) cerE)
{
    P2CONST(uint8, TYPEDEF, KEYM_CONST) cerEndPtr;
    P2VAR(KeyM_Asn1DesType, TYPEDEF, KEYM_VAR) pubAlgoPtr;
    uint32 len;
    uint16 pubAlgoCfgIdx;
    Std_ReturnType ret;

    ret = KeyM_IsCertExist(certId, CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_PUBLIC_KEY_ALGORITHM, &pubAlgoCfgIdx);
    if (ret != E_OK)
    {
        goto HANDLE_GET_PUB_KEY_EXIT;
    }
    pubAlgoPtr = KeyM_CertPCfg[certId].certEleRef[pubAlgoCfgIdx].certEleBuf;

    ret = KeyM_CertGetAsn1Tag(cerS, cerE, &len, KEYM_CERT_ASN1_SEQ_CONSTRU);
    if (ret != E_OK)
    {
        goto HANDLE_GET_PUB_KEY_EXIT;
    }
    cerEndPtr = *cerS + len;

    pubAlgoPtr->tag = **cerS;
    ret = KeyM_CertGetAsn1Tag(cerS, cerEndPtr, &pubAlgoPtr->len, KEYM_CERT_ASN1_OID);
    if (ret != E_OK)
    {
        goto HANDLE_GET_PUB_KEY_EXIT;
    }
    KeyM_CopyData(pubAlgoPtr->dataEle, *cerS, pubAlgoPtr->len);
    if (pubAlgoPtr->next == NULL_PTR)
    {
        *cerS += (cerEndPtr - *cerS);
        goto HANDLE_GET_PUB_KEY_EXIT;
    }

    /*Optional parameters*/
    *cerS += pubAlgoPtr->len;
    pubAlgoPtr = pubAlgoPtr->next;

    pubAlgoPtr->tag = **cerS;
    if (pubAlgoPtr->tag == KEYM_CERT_ASN1_OID)
    {
        ret = KeyM_CertGetAsn1Tag(cerS, cerEndPtr, &pubAlgoPtr->len, KEYM_CERT_ASN1_OID);
        if (ret != E_OK)
        {
            goto HANDLE_GET_PUB_KEY_EXIT;
        }
        KeyM_CopyData(pubAlgoPtr->dataEle, *cerS, pubAlgoPtr->len);
        *cerS += pubAlgoPtr->len;
    }
    else /*KEYM_CERT_ASN1_NULL*/
    {
        pubAlgoPtr->len = 0;
        (*cerS) += 2u;
    }

    if (*cerS != cerEndPtr)
    {
        ret = E_NOT_OK;
    }
HANDLE_GET_PUB_KEY_EXIT:
    return ret;
}

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertGetPubKeyInfo(
    KeyM_CertificateIdType certId,
    P2VAR(uint8*, AUTOMATIC, KEYM_APPL_DATA) cerS,
    P2CONST(uint8, TYPEDEF, KEYM_CONST) cerE)
{
    uint32 len;
    uint32 tag;
    KeyM_CertEleType certEle;
    uint8 objType = KEYM_CERT_ASN1_BIT_STRING;
    Std_ReturnType ret;

    ret = KeyM_CertGetAsn1Tag(cerS, cerE, &len, KEYM_CERT_ASN1_SEQ_CONSTRU);
    if (ret != E_OK)
    {
        goto GET_PUB_KEY_EXIT;
    }
    cerE = *cerS + len;
    ret = KeyM_CertHandleGetPubKeyAlgo(certId, cerS, cerE);
    if (ret != E_OK)
    {
        goto GET_PUB_KEY_EXIT;
    }
    /*Public key info.*/
    tag = **cerS;
    ret = KeyM_CertGetAsn1Tag(cerS, cerE, &len, KEYM_CERT_ASN1_BIT_STRING);
    if (ret != E_OK)
    {
        goto GET_PUB_KEY_EXIT;
    }
    certEle.certEleMaxLen = len;
    certEle.certEleObjType = &objType;
    certEle.certEleStruct = CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_SUBJECT_PUBLIC_KEY;
    ret = KeyM_CertEleHandle(certId, &certEle, *cerS, tag);
    if (ret != E_OK)
    {
        goto GET_PUB_KEY_EXIT;
    }
    *cerS += len;
    if (*cerS != cerE)
    {
        ret = E_NOT_OK;
    }
GET_PUB_KEY_EXIT:
    return ret;
}

static FUNC(void, KEYM_CODE) KeyM_CertSkipField(
    P2VAR(uint8*, AUTOMATIC, KEYM_APPL_DATA) cerS,
    P2CONST(uint8, TYPEDEF, KEYM_CONST) cerE,
    uint32 type)
{
    uint32 len;
    Std_ReturnType ret;

    if (**cerS == type)
    {
        ret = KeyM_CertGetAsn1Tag(cerS, cerE, &len, type);
        if (ret == (Std_ReturnType)E_OK)
        {
            *cerS += len;
        }
    }
}

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertGetExtention(
    KeyM_CertificateIdType certId,
    P2VAR(uint8*, AUTOMATIC, KEYM_APPL_DATA) cerS,
    P2CONST(uint8, TYPEDEF, KEYM_CONST) cerE)
{
    uint32 len;
    uint32 tag;
    KeyM_CertEleType certEle;
    uint8 objType = KEYM_CERT_ASN1_TAG | 3u;
    Std_ReturnType ret;

    if (**cerS == 0xa3u)
    {
        tag = 0xa3u;
        ret = KeyM_CertGetAsn1Tag(cerS, cerE, &len, 0xa3u);
        if (ret == (Std_ReturnType)E_OK)
        {
            certEle.certEleMaxLen = len;
            certEle.certEleObjType = &objType;
            certEle.certEleStruct = CERTIFICATE_EXTENSION;
            (void)KeyM_CertEleHandle(certId, &certEle, *cerS, tag);
            *cerS += len;
        }
    }
    return ret;
}

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertGetSignature(
    KeyM_CertificateIdType certId,
    P2VAR(uint8*, AUTOMATIC, KEYM_APPL_DATA) cerS,
    P2CONST(uint8, TYPEDEF, KEYM_CONST) cerE)
{
    uint32 len;
    uint32 tag;
    KeyM_CertEleType certEle;
    uint8 objType = KEYM_CERT_ASN1_BIT_STRING;
    Std_ReturnType ret;

    tag = **cerS;
    ret = KeyM_CertGetAsn1Tag(cerS, cerE, &len, KEYM_CERT_ASN1_BIT_STRING);
    if (ret != E_OK)
    {
        goto GET_SIGNATURE;
    }
    certEle.certEleMaxLen = len;
    certEle.certEleObjType = &objType;
    certEle.certEleStruct = CERTIFICATE_SIGNATURE;
    ret = KeyM_CertEleHandle(certId, &certEle, *cerS, tag);
    if (ret != E_OK)
    {
        goto GET_SIGNATURE;
    }
    *cerS += len;
GET_SIGNATURE:
    return ret;
}

static FUNC(KeyM_Asn1DesType*, KEYM_CODE)
    KeyM_GetCertEle(KeyM_CertificateIdType certId, KeyM_CertEleStructType certEleStru)
{
    P2CONST(KeyM_CertPCfgType, AUTOMATIC, KEYM_CONST) certCfgPtr;
    P2VAR(KeyM_Asn1DesType, TYPEDEF, KEYM_VAR) certEleBuf;
    uint16 eleIdx;

    certCfgPtr = &KeyM_CertPCfg[certId];
    for (eleIdx = 0u; eleIdx < certCfgPtr->numOfCertEle; eleIdx++)
    {
        if (certEleStru == certCfgPtr->certEleRef[eleIdx].certEleStruct)
        {
            certEleBuf = certCfgPtr->certEleRef[eleIdx].certEleBuf;
            break;
        }
        else
        {
            continue;
        }
    }
    if (eleIdx == certCfgPtr->numOfCertEle)
    {
        certEleBuf = NULL_PTR;
    }
    return certEleBuf;
}

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_CmpCertEle(
    P2VAR(KeyM_Asn1DesType, TYPEDEF, KEYM_VAR) certEleBuf,
    P2VAR(KeyM_Asn1DesType, TYPEDEF, KEYM_VAR) upCertEleBuf)
{
    P2VAR(KeyM_Asn1DesType, TYPEDEF, KEYM_VAR) certEle = certEleBuf;
    P2VAR(KeyM_Asn1DesType, TYPEDEF, KEYM_VAR) upEle = upCertEleBuf;
    Std_ReturnType ret = E_NOT_OK;

    while ((certEle != NULL_PTR) && (upEle != NULL_PTR))
    {
        if (certEle->len != upEle->len)
        {
            goto KeyM_CmpCertEle_Exit;
        }
        else if (E_NOT_OK == KeyM_strcmp(certEle->dataEle, upEle->dataEle, certEle->len))
        {
            goto KeyM_CmpCertEle_Exit;
        }
        certEle = certEle->next;
        upEle = upEle->next;
    }
    if ((certEle == NULL_PTR) && (upEle == NULL_PTR))
    {
        ret = E_OK;
    }
KeyM_CmpCertEle_Exit:
    return ret;
}

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_GlobalTimeCheck(KeyM_CertificateIdType certId)
{
    uint64 ts_s;
    uint32 notBefore_s;
    uint32 notAfter_s;
    StbM_TimeStampType stbM_TimeStamp;
    StbM_UserDataType stbM_UserData;
    Std_ReturnType ret = E_NOT_OK;

    if (certId < KEYM_CERT_NUM)
    {
        ret = StbM_GetCurrentTime(KeyM_CertPCfg[certId].certStbMTime, &stbM_TimeStamp, &stbM_UserData);
        if (ret == E_OK)
        {
            /*secondsHi:16 bit MSB of the 48 bits Seconds part of the time*/
            /*seconds:32 bit LSB of the 48 bits Seconds part of the time*/
            /*Convert the current time to seconds*/
            ts_s = (stbM_TimeStamp.secondsHi << KEYM_CONST_4 | stbM_TimeStamp.seconds);

            /*Validity Not Before Time*/
            notBefore_s = KeyM_ConvertTime_BeijingToUnix(&KeyM_CertStartTime[certId]);

            /*Validity Not After Time*/
            notAfter_s = KeyM_ConvertTime_BeijingToUnix(&KeyM_CertEndTime[certId]);
            if ((ts_s < notBefore_s) || (ts_s > notAfter_s))
            {
                ret = E_NOT_OK;
            }
        }
    }
    return ret;
}

static FUNC(uint8, KEYM_CODE) KeyM_IsLeapYear(uint16 year)
{
    uint8 ret = 0u;

    if (year % 4u == 0)
    {
        if ((year % 100u == 0u) && (year % 400u != 0u))
        {
            /*Common year*/
            ret = 0u;
        }
        else
        {
            /*Leap year*/
            ret = 1u;
        }
    }
    return ret;
}

static FUNC(uint32, KEYM_CODE) KeyM_ConvertTime_BeijingToUnix(P2VAR(KeyM_CertTimeType, TYPEDEF, KEYM_VAR) bjTime)
{
    uint32 dayNum = 0u;
    uint32 secNum = 0u;
    uint16 unixStartYear = 1970;
    uint16 mon = 0u;

    /*1.Calculate the number of days in all years*/
    while (unixStartYear < bjTime->certYear)
    {

        if (KeyM_IsLeapYear(unixStartYear) != 0u)
        {
            dayNum += 366;
        }
        else
        {
            dayNum += 365;
        }
        unixStartYear++;
    }
    /*2.Calculate the number of days in all months.*/
    while (mon < bjTime->certMon - 1u)
    {
        if (KeyM_IsLeapYear(bjTime->certYear) != 0u)
        {
            dayNum += KeyM_LeapMonthDay[mon];
        }
        else
        {
            dayNum += KeyM_ComMonthDay[mon];
        }
        mon++;
    }

    /*3.Add day*/
    /*No need to plus one-day on the 1st of each month*/
    dayNum += bjTime->certDay - 1u;

    /*4.Hour Minute Second*/
    secNum = dayNum * 24 * 60 * 60;

    secNum += bjTime->certHour * 60 * 60; /*Hour*/

    secNum += bjTime->certMin * 60; /*Minute*/

    secNum += bjTime->certSec; /*Second*/

    /*5.Time zone adjustment*/
    secNum -= 8 * 60 * 60; /*8:Beijing Time zone.*/
    return secNum;
}

static FUNC(Std_ReturnType, KEYM_CODE) KeyM_HandleCertcVerify(
    P2CONST(KeyM_CertPCfgType, AUTOMATIC, KEYM_CONST) certCfgPtr,
    P2CONST(KeyM_CertPCfgType, TYPEDEF, KEYM_CONST) certUpperHierRef)
{
    P2VAR(KeyM_Asn1DesType, TYPEDEF, KEYM_VAR) certEleBuf = NULL_PTR;
    P2VAR(KeyM_Asn1DesType, TYPEDEF, KEYM_VAR) upCertEleBuf = NULL_PTR;
    P2VAR(KeyM_Asn1DesType, TYPEDEF, KEYM_VAR) sigBuf = NULL_PTR;
    P2VAR(KeyM_Asn1DesType, TYPEDEF, KEYM_VAR) pbKeyBuf = NULL_PTR;
    uint32 sigVerJob;
    uint32 tarKey = KEYM_INVALID_U32;
    uint16 CertId = certCfgPtr->certId;
    uint16 nvmRefBloId;
    Crypto_VerifyResultType verifyRes = CRYPTO_E_VER_NOT_OK;
    Std_ReturnType ret = E_OK;

    /*1.Subject check*/
    if (certCfgPtr->selfSignedCert == TRUE)
    {
        /*self-signed : SUBJECT = ISSUER*/
        certEleBuf = KeyM_GetCertEle(CertId, CERTIFICATE_SUBJECT_NAME);
        upCertEleBuf = KeyM_GetCertEle(CertId, CERTIFICATE_ISSUER_NAME);
    }
    else
    {
        certEleBuf = KeyM_GetCertEle(CertId, CERTIFICATE_ISSUER_NAME);
        upCertEleBuf = KeyM_GetCertEle(certUpperHierRef->certId, CERTIFICATE_SUBJECT_NAME);
    }
    if ((certEleBuf == NULL_PTR) || (upCertEleBuf == NULL_PTR))
    {
        ret = KEYM_E_CERT_INVALID_CHAIN_OF_TRUST;
        goto CERT_VERIFY_EXIT;
    }
    ret = KeyM_CmpCertEle(certEleBuf, upCertEleBuf);
    if (ret != E_OK)
    {
        goto CERT_VERIFY_EXIT;
    }

    /*2.Time stamp check*/
    ret = KeyM_GlobalTimeCheck(CertId);
    if (ret != E_OK)
    {
        KeyM_CertStatus[CertId] = KEYM_E_CERTIFICATE_VALIDITY_PERIOD_FAIL;
        goto CERT_VERIFY_EXIT;
    }

    /*3.Certificate elements check*/
    if (certCfgPtr->certRuleArbiFunc != NULL_PTR)
    {
        /*SWS_KeyM_00035&SWS_KeyM_00135*/
        /*The contents of certificate elements shall be checked through by a check of all
         * KeyMCertCertificateElementRuleRef.*/
        if ((boolean)FALSE == certCfgPtr->certRuleArbiFunc())
        {
            ret = E_NOT_OK;
            KeyM_CertStatus[CertId] = KEYM_E_CERTIFICATE_INVALID_CONTENT;
            goto CERT_VERIFY_EXIT;
        }
    }
    /*4.Signature check*/
    /*Get public Key*/
    pbKeyBuf = KeyM_GetCertEle(CertId, CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_SUBJECT_PUBLIC_KEY);
    if (pbKeyBuf == NULL_PTR)
    {
        ret = E_NOT_OK;
        goto CERT_VERIFY_EXIT;
    }

    /*Get signature.*/
    sigBuf = KeyM_GetCertEle(CertId, CERTIFICATE_SIGNATURE);
    if (sigBuf == NULL_PTR)
    {
        ret = E_NOT_OK;
        goto CERT_VERIFY_EXIT;
    }

    sigVerJob = certUpperHierRef->certSigVeriJob;
    if (certCfgPtr->selfSignedCert == TRUE)
    {
        /*For self-signed certificates, first the public key of this certificate needs to be set*/
        (void)Csm_KeyElementSet(certCfgPtr->certSigVeriKey, CRYPTO_KE_SIGNATURE_KEY, pbKeyBuf->dataEle, pbKeyBuf->len);
        (void)Csm_KeySetValid(certCfgPtr->certSigVeriKey);
        sigVerJob = certCfgPtr->certSigVeriJob;
    }

    /*Use CA's public Key.*/
    /*SWS_KeyM_00032*/
    ret = Csm_SignatureVerify(
        sigVerJob,
        CRYPTO_OPERATIONMODE_SINGLECALL,
        certCfgPtr->tbsCert->dataEle,
        certCfgPtr->tbsCert->len,
        sigBuf->dataEle,
        sigBuf->len,
        &verifyRes);
    if (ret != E_OK)
    {
        KeyM_CertStatus[CertId] = KEYM_E_CERTIFICATE_SIGNATURE_FAIL;
        goto CERT_VERIFY_EXIT;
    }

    /*Validation succeeded,the public key of the certificate shall be set and validated.*/
    if (certCfgPtr->certStorage == KEYM_STORAGE_IN_NVM)
    {
        nvmRefBloId = *certCfgPtr->certNvmBlkRef;
        if (nvmRefBloId < KEYM_NVM_BLOCK_NUM)
        {
            if (KeyM_NvmBlockPCfg[nvmRefBloId].blkWriDelay == 0u)
            {
                /*Public-Key is Written immediately*/
                NvM_WriteBlock(KeyM_NvmBlockPCfg[nvmRefBloId].blkId, certCfgPtr->tbsCert->dataEle);
            }
            else
            {
                KeyM_BlkWriDelayRun[nvmRefBloId].timeStart = TRUE;
                KeyM_BlkWriDelayRun[nvmRefBloId].delayTime = KeyM_NvmBlockPCfg[nvmRefBloId].blkWriDelay;
                /*Record certificate start address.*/
                KeyM_BlkWriDelayRun[nvmRefBloId].nvmCertEle = certCfgPtr->tbsCert;
            }
        }
    }
    else if (certCfgPtr->certStorage == KEYM_STORAGE_IN_CSM)
    {
        if (certCfgPtr->certKeyTarRef != NULL_PTR)
        {
            tarKey = *(certCfgPtr->certKeyTarRef);
            KeyM_HandleCsmKeyStorage(tarKey, CertId, TRUE);
            (void)Csm_KeySetValid(tarKey);
        }
    }
    else /*KEYM_STORAGE_IN_RAM*/
    {
        /*Do nothing.*/
    }

    if (ret == E_OK)
    {
        KeyM_CertStatus[CertId] = KEYM_CERTIFICATE_VALID;
        if (certCfgPtr->certVeriCbkFunc != NULL_PTR)
        {
            (void)certCfgPtr->certVeriCbkFunc(CertId, KeyM_CertStatus[CertId]);
        }
    }
CERT_VERIFY_EXIT:
    return ret;
}
#endif /*(STD_ON == KEYM_CERTIFICATE_MANAGER_ENABLED)*/
