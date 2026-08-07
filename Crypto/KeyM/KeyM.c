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
**  FILENAME    : KeyM.c                                                      **
**                                                                            **
**  Created on  :                                                             **
**  Author      : qinchun.yang                                                **
**  Vendor      :                                                             **
**  DESCRIPTION : Implement KeyM general functions                            **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R21-11                      **
**                                                                            **
*******************************************************************************/

/******************************************************************************
**                      Revision Control History                             **
******************************************************************************/
/*  <VERSION>    <DATE>      <AUTHOR>        <REVISION LOG>
 *  V1.0.0     2022-02-15   qinchun.yang     initial version.
 *  V1.0.1     2023-03-21   qinchun.yang     CPD-3718,CPD-3719,CPD-3720,CPD-3721,CPD-3724,CPD-3725
 *                                           CPD-3726,CPD-3727,CPD-3728,CPD-3730,CPD-3769.
 *  V1.0.2     2023-03-21   qinchun.yang     Modify initialization processing persistent storage certificate logic.
 *  V1.0.3     2023-03-24   qinchun.yang     Versions that have undergone functional testing.
 */
/*=======[V E R S I O N  I N F O R M A T I O N]===============================*/
#define KEYM_C_AR_MAJOR_VERSION 4u
#define KEYM_C_AR_MINOR_VERSION 7u
#define KEYM_C_AR_PATCH_VERSION 0u
#define KEYM_C_SW_MAJOR_VERSION 1u
#define KEYM_C_SW_MINOR_VERSION 0u
#define KEYM_C_SW_PATCH_VERSION 3u
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "KeyM_Internal.h"
/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/
#if (KEYM_C_AR_MAJOR_VERSION != KEYM_AR_MAJOR_VERSION)
#error "KeyM.c : Mismatch in Specification Major Version"
#endif
#if (KEYM_C_AR_MINOR_VERSION != KEYM_AR_MINOR_VERSION)
#error "KeyM.c : Mismatch in Specification Major Version"
#endif
#if (KEYM_C_AR_PATCH_VERSION != KEYM_AR_PATCH_VERSION)
#error "KeyM.c : Mismatch in Specification Major Version"
#endif
#if (KEYM_C_SW_MAJOR_VERSION != KEYM_SW_MAJOR_VERSION)
#error "KeyM.c : Mismatch in Specification Major Version"
#endif
#if (KEYM_C_SW_MINOR_VERSION != KEYM_SW_MINOR_VERSION)
#error "KeyM.c : Mismatch in Specification Major Version"
#endif
#if (KEYM_C_SW_PATCH_VERSION != KEYM_SW_PATCH_VERSION)
#error "KeyM.c : Mismatch in Specification Major Version"
#endif

/*******************************************************************************
**                      Private Macro Definitions                             **
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
#define KEYM_START_SEC_VAR_CLEARED_BOOLEAN
#include "KeyM_MemMap.h"
VAR(boolean, KEYM_VAR) KeyM_InitStatus;
#define KEYM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "KeyM_MemMap.h"
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define KEYM_START_SEC_CODE
#include "KeyM_MemMap.h"
/*************************************************************************/
/*
 * Brief               This function initializes the key management module.
 * ServiceId           0x01
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      ConfigPtr: Pointer to the configuration set in VARIANT-POST-BUILD.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/*************************************************************************/
FUNC(void, KEYM_CODE)
KeyM_Init(P2CONST(KeyM_ConfigType, AUTOMATIC, KEYM_APPL_DATA) ConfigPtr)
{
#if (STD_ON == KEYM_CERTIFICATE_MANAGER_ENABLED)
    P2CONST(KeyM_CertPCfgType, AUTOMATIC, KEYM_CONST) certCfgPtr;
    uint16 certId;
#endif /*(STD_ON == KEYM_CERTIFICATE_MANAGER_ENABLED)*/

    if (ConfigPtr != NULL_PTR)
    {
#if (KEYM_DEVERROR_DETECT == STD_ON)
        KEYM_DET_REPORT(KEYM_INIT_ID, KEYM_E_INIT_FAILED);
#endif
    }
    else
    {
#if (STD_ON == KEYM_CERTIFICATE_MANAGER_ENABLED)
        /*SWS_KeyM_00167*/
        for (certId = 0u; certId < KEYM_CERT_NUM; certId++)
        {
            certCfgPtr = &KeyM_CertPCfg[certId];
            KeyM_CertSetStatus(certId, KEYM_CERTIFICATE_NOT_AVAILABLE);
            if (certCfgPtr->certStorage == KEYM_STORAGE_IN_CSM)
            {
                if ((certCfgPtr->selfSignedCert != TRUE) && (certCfgPtr->certKeyTarRef != NULL_PTR))
                {
                    KeyM_HandleCsmKeyStorage(*(certCfgPtr->certKeyTarRef), certId, FALSE);
                    KeyM_CertSetStatus(certId, KEYM_CERTIFICATE_PARSED_NOT_VALIDATED);
                }
            }
#if (KEYM_NVM_BLOCK_NUM > 0u)
            else if (certCfgPtr->certStorage == KEYM_STORAGE_IN_NVM)
            {
                NvM_ReadBlock(
                    KeyM_NvmBlockPCfg[(*KeyM_CertPCfg[certId].certNvmBlkRef)].blkId,
                    KeyM_CertPCfg[certId].tbsCert->dataEle);
                KeyM_CertSetStatus(certId, KEYM_CERTIFICATE_NOT_PARSED);
            }
#endif /*(KEYM_NVM_BLOCK_NUM > 0)*/
            else
            {
                /*Do nothing.*/
            }
        }
#endif /*(STD_ON == KEYM_CERTIFICATE_MANAGER_ENABLED)*/
        KeyM_InitStatus = TRUE;
    }
}

/*************************************************************************/
/*
 * Brief               This function resets the key management module to
 *                     the uninitialized state.
 * ServiceId           0x02
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/*************************************************************************/
FUNC(void, KEYM_CODE)
KeyM_Deinit(void)
{
    KeyM_InitStatus = FALSE;
}

/*************************************************************************/
/*
 * Brief               This function provides the version of this module.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     VersionInfo: Pointer to the version information of this module.
 * Param-Name[in/out]  None
 * Return              None
 */
/*************************************************************************/
FUNC(void, KEYM_CODE)
KeyM_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, KEYM_APPL_DATA) VersionInfo)
{
#if (KEYM_DEVERROR_DETECT == STD_ON)
    if (NULL_PTR == VersionInfo)
    {
        KEYM_DET_REPORT(KEYM_GETVERSIONINFO_ID, KEYM_E_PARAM_POINTER);
    }
    else
#endif /*(ECUM_DEV_ERROR_DETECT == STD_ON)*/
    {
        VersionInfo->moduleID = KEYM_MODULE_ID;
        VersionInfo->vendorID = KEYM_H_VENDOR_ID;
        VersionInfo->instanceID = KEYM_INSTANCE_ID;
        VersionInfo->sw_major_version = KEYM_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = KEYM_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = KEYM_SW_PATCH_VERSION;
    }
}

/*************************************************************************/
/*
 * Brief               Function is called periodically according the specified time interval.
 * ServiceId           0x19
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None.
 * Param-Name[in/out]  None
 * Return              None
 */
/*************************************************************************/
FUNC(void, KEYM_CODE)
KeyM_MainFunction(void)
{
#if (STD_ON == KEYM_CERTIFICATE_MANAGER_ENABLED)
    KeyM_CertStoreNvmHandle();
#endif /*(STD_ON == KEYM_CERTIFICATE_MANAGER_ENABLED)*/
}
/*************************************************************************/
/*
 * Brief               Function is called from a pre-emptive operating system
 *                     when no other task operation is needed
 * ServiceId           0x1a
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None.
 * Param-Name[in/out]  None
 * Return              None
 */
/*************************************************************************/
FUNC(void, KEYM_CODE)
KeyM_MainBackgroundFunction(void)
{
#if (STD_ON == KEYM_CERTIFICATE_MANAGER_ENABLED)
    P2CONST(KeyM_CertPCfgType, AUTOMATIC, KEYM_CONST) certCfgPtr;
    uint16 certId;
    KeyM_CertificateStatusType certStatu;
#endif /*(STD_ON == KEYM_CERTIFICATE_MANAGER_ENABLED)*/

#if (STD_ON == KEYM_CERTIFICATE_MANAGER_ENABLED)
    for (certId = 0u; certId < KEYM_CERT_NUM; certId++)
    {
        certCfgPtr = &KeyM_CertPCfg[certId];
        (void)KeyM_CertGetStatus(certId, &certStatu);
        if ((certCfgPtr->certStorage == KEYM_STORAGE_IN_NVM) && (certStatu == KEYM_CERTIFICATE_NOT_PARSED))
        {
            KeyM_HandleParseCert(certId, certCfgPtr->tbsCert->dataEle, certCfgPtr->tbsCert->len);
        }
    }
#endif /*(STD_ON == KEYM_CERTIFICATE_MANAGER_ENABLED)*/
}

FUNC(void, KEYM_CODE)
KeyM_CopyData(P2VAR(void, AUTOMATIC, KEYM_APPL_DATA) dest, P2CONST(void, AUTOMATIC, KEYM_CONST) src, uint32 size)
{
    uint32 idx;
    P2VAR(uint8, AUTOMATIC, KEYM_APPL_DATA) destPtr = (uint8*)dest;
    P2VAR(uint8, AUTOMATIC, KEYM_APPL_DATA) srcPtr = (uint8*)src;

    if (dest == src)
    {
        return;
    }
    if ((src != NULL_PTR) && (dest != NULL_PTR) && (size != 0u))
    {
        for (idx = 0; idx < size; idx++)
        {
            destPtr[idx] = srcPtr[idx];
        }
    }
}

FUNC(Std_ReturnType, KEYM_CODE)
KeyM_strcmp(P2CONST(uint8, AUTOMATIC, KEYM_CONST) str1, P2CONST(uint8, AUTOMATIC, KEYM_CONST) str2, uint16 size)
{
    uint16 len;
    Std_ReturnType ret = E_OK;

    for (len = 0u; len < size; len++)
    {
        if (str1[len] != str2[len])
        {
            break;
        }
    }
    if (len != size)
    {
        ret = E_NOT_OK;
    }
    return ret;
}
#define KEYM_STOP_SEC_CODE
#include "KeyM_MemMap.h"
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
