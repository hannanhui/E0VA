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
**  FILENAME    : Csm_Cbk.c                                                   **
**                                                                            **
**  Created on  :                                                             **
**  Author      : qinchun.yang                                                **
**  Vendor      :                                                             **
**  DESCRIPTION : Implementation callback function for CSM                    **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

/******************************************************************************
**                      Revision Control History                             **
******************************************************************************/
/*  <VERSION>     <DATE>        <AUTHOR>         <REVISION LOG>
 *    V1.0.0     2019-10-18      qinchun.yang    Initial version
 *    V1.1.0     2020-06-20      yuzhe.zhang     R19-11
 *    V2.0.0     2023-02-06      jie.gu          R19_11
 */

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Csm_Cbk.h"
#include "Csm_Internal.h"
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
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
    VAR(Crypto_ResultType, CSM_APPL_DATA) result)
{
    P2CONST(Csm_JobsCfgType, AUTOMATIC, AUTOMATIC) jobCfgPtr;
    uint32 cbkId;
    Crypto_OperationModeType mode;
#if (CSM_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType ret;

    ret = Csm_ChkCbkNotify(job, CSM_SID_CBK_NOTIFY);
    if ((boolean)E_OK == ret)
#endif /*(CSM_DEV_ERROR_DETECT == STD_ON)*/
    {
        jobCfgPtr = &(Csm_JobCfg[job->jobId]);
        cbkId = jobCfgPtr->jobPrimitiveInfo->callbackId;
        mode = job->jobPrimitiveInputOutput.mode;
        if ((boolean)TRUE == Csm_JobPostponeFlag[job->jobId])
        {
#if (CSM_CBKFUNCS_NUM > 0u)
            /*[SWS_Csm_01087]*/
            if (NULL_PTR != Csm_CbkCfg[cbkId].cbkFnc)
            {
                Csm_CbkCfg[cbkId].cbkFnc(job, CRYPTO_E_JOB_CANCELED);
            }
#else
            CSM_AVOID_WARNING(result);
            CSM_AVOID_WARNING(cbkId);
#endif /*(CSM_CBKFUNCS_NUM > 0u)*/
            Csm_JobPostponeFlag[job->jobId] = FALSE;
        }
        else
        {
            if (0u != (mode & CRYPTO_OPERATIONMODE_FINISH)) /*PRQA S 4522,1823*/
            {
#if (CSM_CBKFUNCS_NUM > 0u)
                /*[SWS_Csm_01044]*/
                if (NULL_PTR != Csm_CbkCfg[cbkId].cbkFnc)
                {
                    Csm_CbkCfg[cbkId].cbkFnc(job, result);
                }
#endif /*(CSM_CBKFUNCS_NUM > 0u)*/
                Csm_JobStates[job->jobId] = CRYPTO_JOBSTATE_IDLE;

                /*[SWS_Csm_91017]*/
                /*TODO*/
            }
        }
    }
}
#define CSM_STOP_SEC_CBK_NOTIFICATION_CODE
#include "Csm_MemMap.h"
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
