/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Lin.c
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2025-08-29
 *  @Version         : V1.0.0_SF
 *  @Description     : AUTOSAR Lin - High level part of LIN driver.
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 ******************************************************************************
 *                        REVISION HISTORY
 ******************************************************************************
 *  |Date        |Version  |Author       |Description
 ******************************************************************************
 *  |2025-08-29  |V1.0     |Wang Ning    |New creat
 *****************************************************************************/

/******************************************************************************
 **                        MISRA-C Rules Violations
 ******************************************************************************/
/**
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section
 */

/******************************************************************************
 **                        QAC Warnings
 ******************************************************************************/
/**
 * @page QAC Warnings
 *
 */
/* PRQA S 3408 EOF #KQR003408 */
/* PRQA S 2814 EOF #KQR002814 */
/* PRQA S 2824 EOF #KQR002824 */
/* PRQA S 2844 EOF #KQR002844 */
/* PRQA S 2201 EOF #KQR002201 */
/* PRQA S 2919 EOF #KQR002919 */
/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "Lin.h"
#include "Lin_Im.h"

#if (LIN_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
#if (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#include "Dem.h"
#endif
/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/

/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/

/******************************************************************************
 **                        Export Variables
 ******************************************************************************/
#if (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
extern Lin_DemErrorType Lin_E_TimeOutCfg;
#endif
#if (LIN_PRECOMPILE_SUPPORT == STD_ON)
extern const Lin_ConfigType Lin_ConfigPredefined;
#endif
/******************************************************************************
 **                        Export Functions
 ******************************************************************************/

/******************************************************************************
 **                        Variable Declarations
 ******************************************************************************/
/**
 * @brief Global configuration pointer.
 * @details Pointer to the configuration structure.
 * @implements #SWS_Lin_00011
 */
#if (LIN_PRECOMPILE_SUPPORT == STD_ON)
const Lin_ConfigType *Lin_ConfigPtr = &Lin_ConfigPredefined;
#else
const Lin_ConfigType *Lin_ConfigPtr = NULL_PTR;
#endif

/**
 * @brief LIN driver status variable.
 * @details LIN driver state machine.
 */
/* PRQA S 3229 1 #KQR003229  */
static uint8 Lin_ModuleStatus = LIN_UNINIT;

/**
 * @brief Global configuration array.
 * @details Array containing channel configurations.
 */
Lin_ChannelCfgType *Lin_ChannelConfigPtr[LIN_IM_MODULES];

/**
 * @brief LIN channel state variable.
 * @details LIN channel state machine.
 */
volatile uint8 Lin_ChannelStatus[LIN_IM_MODULES];

/**
 * @brief LIN SDU buffer variable.
 * @details LIN SDU buffer to be returned.
 */
static uint8 Lin_SduBuffAddress[LIN_IM_MODULES][LIN_MAX_DATA_LENGTH];

/**
 * @brief LIN frame state variable.
 * @details LIN frame state.
 */
volatile uint8 Lin_ChannelFrameStatus[LIN_IM_MODULES];

/**
 * @brief LIN Frame header state variable.
 * @details LIN Frame header state.
 */
static uint8 Lin_ChannelHeaderStatus[LIN_IM_MODULES];

/**
 * @brief LIN Frame error status variable.
 * @details LIN Frame error status.
 */
volatile uint8 Lin_ChannelFrameErrorStatus[LIN_IM_MODULES];

/**
 * @brief LIN header command type variable.
 * @details LIN header command type.
 */
uint8 Lin_TransmitHeaderCommand[LIN_IM_MODULES];

/**
 * @brief wakeup status
 */
uint8 Lin_WakeupSupport[LIN_IM_MODULES];
/******************************************************************************
 **                      Private Function Declarations
 ******************************************************************************/
#if (LIN_DEV_ERROR_DETECT == STD_ON)
LOCAL_INLINE FUNC(void, LIN_CODE) Lin_ReportDetError(uint8 ApiId, uint8 ErrorId);
static FUNC(Std_ReturnType, LIN_CODE) Lin_ValidateGlobalConfigCall(VAR(uint8, AUTOMATIC) ServiceId);
static FUNC(Std_ReturnType, LIN_CODE)
  Lin_ValidateChannelConfigCall(VAR(uint8, AUTOMATIC) ChannelNumber, VAR(uint8, AUTOMATIC) ServiceId);
LOCAL_INLINE FUNC(Std_ReturnType, LIN_CODE)
  Lin_ValidateParamPtrInit(P2CONST(Lin_ConfigType, AUTOMATIC, LIN_APPL_CONST) ConfigPtr);
LOCAL_INLINE FUNC(Std_ReturnType, LIN_CODE)
  Lin_ValidateSendParamPtrInit(P2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_CONST) ConfigPtr);
#endif
/******************************************************************************
 **                      Function definitions
 ******************************************************************************/

#if (LIN_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief short for det error function
 *
 * @param ApiId application id
 * @param ErrorId error id
 * @return None
 * @retval None
 */
LOCAL_INLINE FUNC(void, LIN_CODE) Lin_ReportDetError(uint8 ApiId, uint8 ErrorId)
{
    (void)Det_ReportError((uint16)LIN_MODULE_ID, (uint8)LIN_INSTANCE_ID, ApiId, ErrorId);
}

/**
 * @brief Validate the call of a function impacting the configuration of the entire driver.
 *
 * @param ServiceId Id of the service calling this function
 * @return Std_ReturnType
 * @retval E_OK
 * @retval E_NOT_OK
 */
static FUNC(Std_ReturnType, LIN_CODE) Lin_ValidateGlobalConfigCall(VAR(uint8, AUTOMATIC) ServiceId)
{
    /* Variable to store the value returned by the function */
    Std_ReturnType retVal = (Std_ReturnType)E_OK;

    if (LIN_UNINIT == Lin_ModuleStatus)
    {
        if (LIN_INIT_ID != ServiceId)
        {
            Lin_ReportDetError(ServiceId, LIN_E_UNINIT);
            retVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /*Intentionally Empty*/
        }
    }
    else
    {
        /* @implements #SWS_Lin_00105 */
        if (LIN_INIT_ID == ServiceId)
        {
            Lin_ReportDetError(ServiceId, LIN_E_STATE_TRANSITION);
            retVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /*Intentionally Empty*/
        }
    }
    return retVal;
}

/**
 * @brief Validate the call of a function impacting the configuration of one of the driver's
 *
 * @param ChannelNumber Id of the channel the caller tries to update
 * @param ServiceId Id of the service calling this function
 * @return Std_ReturnType
 * @retval E_OK
 * @retval E_NOT_OK
 */
static FUNC(Std_ReturnType, LIN_CODE)
  Lin_ValidateChannelConfigCall(VAR(uint8, AUTOMATIC) ChannelNumber, VAR(uint8, AUTOMATIC) ServiceId)
{
    /* Variable to store the value returned by the function */
    Std_ReturnType retVal = (Std_ReturnType)E_OK;

    /* Check that the channel is in valid range */
    if (ChannelNumber >= Lin_ConfigPtr->ChannelNum)
    {
        Lin_ReportDetError(ServiceId, LIN_E_INVALID_CHANNEL);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        /*Intentionally Empty*/
    }
    return retVal;
}

/**
 * @brief Check Config for not being a null pointer
 *
 * @param ConfigPtr Pointer to the configuration the driver is to be init with
 * @return Std_ReturnType
 * @retval E_OK
 * @retval E_NOT_OK
 */
LOCAL_INLINE FUNC(Std_ReturnType, LIN_CODE)
  Lin_ValidateParamPtrInit(P2CONST(Lin_ConfigType, AUTOMATIC, LIN_APPL_CONST) ConfigPtr)
{
    /* Variable to store the value returned by the function */
    Std_ReturnType retVal = (Std_ReturnType)E_OK;
#if (LIN_PRECOMPILE_SUPPORT != STD_ON)
    /* Check if the config pointer received as param is NULL */
    if (NULL_PTR == ConfigPtr)
    {
        Lin_ReportDetError(LIN_INIT_ID, LIN_E_PARAM_POINTER);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        /*Intentionally Empty*/
    }
#else
    {
        /* Check if the config pointer received as param is NULL */
        if (NULL_PTR != ConfigPtr)
        {
            Lin_ReportDetError(LIN_INIT_ID, LIN_E_PARAM_POINTER);
            retVal = (Std_ReturnType)E_NOT_OK;
        }
    }
#endif
    return retVal;
}

/**
 * @brief Check if the config pointer received as param
 *
 * @param ConfigPtr Pointer to the configuration the driver is to be init with
 * @return Std_ReturnType
 * @retval E_OK
 * @retval E_NOT_OK
 */
LOCAL_INLINE FUNC(Std_ReturnType, LIN_CODE)
  Lin_ValidateSendParamPtrInit(P2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_CONST) ConfigPtr)
{
    /* Variable to store the value returned by the function */
    Std_ReturnType retVal = (Std_ReturnType)E_OK;

    /* Check if the config pointer received as param is NULL */
    if (NULL_PTR == ConfigPtr)
    {
        Lin_ReportDetError(LIN_SENDFRAME_ID, LIN_E_PARAM_POINTER);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        /*Intentionally Empty*/
    }
    return retVal;
}
#endif

/**
 * @brief Initializes the LIN module.
 * @details
 * Service name: Lin_Init
 * Syntax: void Lin_Init (const Lin_ConfigType* Config)
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * @implements #SWS_Lin_00006,#SWS_Lin_00084,#SWS_Lin_00150,#SWS_Lin_00190,#SWS_Lin_00106,
 * #SWS_Lin_00099,#SWS_Lin_00105,#SWS_Lin_00097
 * @param Config Pointer to LIN driver configuration set.
 * @retval None
 * @return None
 */
FUNC(void, LIN_CODE) Lin_Init(const Lin_ConfigType *Config)
{
    uint8 channelLoop;
    uint8 length;

#if (LIN_PRECOMPILE_SUPPORT == STD_ON)
    (void)Config;
#else
    /* @implements #SWS_Lin_00150 */
    /* Save configuration pointer in global variable */
    Lin_ConfigPtr = Config;
#endif

#if (LIN_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType callIsValid;
    callIsValid = Lin_ValidateGlobalConfigCall(LIN_INIT_ID);
    if ((Std_ReturnType)E_OK == callIsValid)
    {
        /* @implements SWS_Lin_00099 */
        callIsValid = Lin_ValidateParamPtrInit(Config);
    }
    else
    {
        /*Intentionally Empty*/
    }
    if ((Std_ReturnType)E_OK == callIsValid)
#endif
    {
        for (channelLoop = (uint8)0U; channelLoop < Lin_ConfigPtr->ChannelNum; channelLoop++)
        {
            Lin_ChannelConfigPtr[channelLoop] = &(Lin_ConfigPtr->ChannelPtr[channelLoop]);

            for (length = (uint8)0U; length < LIN_MAX_DATA_LENGTH; length++)
            {
                Lin_SduBuffAddress[channelLoop][length] = (uint8)0U;
            }
            /* @implements #SWS_Lin_00084,#SWS_Lin_00008,#SWS_Lin_00190 */
            Lin_Im_UsartInitChannel(Lin_ChannelConfigPtr[channelLoop]);
#if (LIN_START_UP_SLEEP_STATE == STD_ON)
            /* Set LIN channel state machine to LIN_CH_SLEEP_STATE */
            Lin_ChannelStatus[channelLoop] = LIN_CH_SLEEP_STATE;
            /* Set LIN channel frame operation status to LIN_CH_NOT_READY_STATE */
            Lin_ChannelFrameStatus[channelLoop] = LIN_CH_NOT_READY_STATE;
#else
            /* Set LIN channel state machine to LIN_CH_OPERATIONAL */
            Lin_ChannelStatus[channelLoop] = LIN_CH_OPERATIONAL;
            /* Set LIN channel frame operation status to LIN_CH_READY_STATE */
            Lin_ChannelFrameStatus[channelLoop] = LIN_CH_READY_STATE;
#endif
            /* Header status flag */
            Lin_ChannelHeaderStatus[channelLoop] = (uint8)FALSE;
            /* Reset header command type */
            Lin_TransmitHeaderCommand[channelLoop] = LIN_TX_NO_COMMAND;
            /* Reset error status global flag */
            Lin_ChannelFrameErrorStatus[channelLoop] = LIN_NO_ERROR;

            Lin_WakeupSupport[channelLoop] = Lin_ChannelConfigPtr[channelLoop]->ChannelWakeupSupport;
        }
        Lin_ModuleStatus = LIN_INIT;
    }
#if (LIN_DEV_ERROR_DETECT == STD_ON)
    else
    {
        /*Intentionally Empty*/
    }
#endif
}

/**
 * @brief Deinitialize the LIN module.
 * @details
 * Service name: Lin_DeInit
 * Syntax: void Lin_DeInit (void)
 * Service ID[hex]: 0x50
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * @implements None
 * @param None
 * @retval None
 * @return None
 */
FUNC(void, LIN_CODE) Lin_DeInit(void)
{
    uint8 channelLoop;
    uint8 length;

#if (LIN_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType callIsValid;
    callIsValid = Lin_ValidateGlobalConfigCall(LIN_DEINIT_ID);

    if ((Std_ReturnType)E_OK == callIsValid)
#endif
    {
        for (channelLoop = (uint8)0U; channelLoop < Lin_ConfigPtr->ChannelNum; channelLoop++)
        {
            Lin_ChannelConfigPtr[channelLoop] = &(Lin_ConfigPtr->ChannelPtr[channelLoop]);

            for (length = (uint8)0U; length < LIN_MAX_DATA_LENGTH; length++)
            {
                Lin_SduBuffAddress[channelLoop][length] = (uint8)0U;
            }
            /* @implements #SWS_Lin_00084,#SWS_Lin_00008,#SWS_Lin_00190 */
            Lin_Im_UsartDeInitChannel(Lin_ChannelConfigPtr[channelLoop]);
            /* Set LIN channel state machine to LIN_CH_SLEEP_STATE */
            Lin_ChannelStatus[channelLoop] = LIN_CH_SLEEP_STATE;
            /* Set LIN channel frame operation status to LIN_CH_NOT_READY_STATE */
            Lin_ChannelFrameStatus[channelLoop] = LIN_CH_NOT_READY_STATE;
            /* Header status flag */
            Lin_ChannelHeaderStatus[channelLoop] = (uint8)FALSE;
            /* Reset header command type */
            Lin_TransmitHeaderCommand[channelLoop] = LIN_TX_NO_COMMAND;
            /* Reset error status global flag */
            Lin_ChannelFrameErrorStatus[channelLoop] = LIN_NO_ERROR;
            Lin_Im_DeinitDataClear(Lin_ChannelConfigPtr[channelLoop]);

            Lin_WakeupSupport[channelLoop]    = FALSE;
            Lin_ChannelConfigPtr[channelLoop] = NULL_PTR;
        }
        Lin_ModuleStatus = LIN_UNINIT;
    }
#if (LIN_DEV_ERROR_DETECT == STD_ON)
    else
    {
        /*Intentionally Empty*/
    }
#endif
}
/**
 * @brief This function checks if a wakeup has occurred on the addressed LIN channel.
 * @details
 * Service name: Lin_CheckWakeup
 * Syntax: Std_ReturnType Lin_CheckWakeup (uint8 Channel)
 * Service ID[hex]: 0x0a
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * @implements #SWS_Lin_00160,#SWS_Lin_00098,#SWS_Lin_00251,#SWS_Lin_00107
 * @param Channel LIN channel to be addressed
 * @return Std_ReturnType
 * @retval E_OK API call has been accepted
 * @retval E_NOT_OK API call has not been accepted
 */
FUNC(Std_ReturnType, LIN_CODE) Lin_CheckWakeup(uint8 Channel)
{
    Std_ReturnType callIsValid = (Std_ReturnType)E_OK;

#if (LIN_DEV_ERROR_DETECT == STD_ON)
    /* @implements #SWS_Lin_00107 */
    callIsValid = Lin_ValidateGlobalConfigCall(LIN_CHECKWAKEUP_ID);
    if ((Std_ReturnType)E_OK == callIsValid)
    {
        /* @implements #SWS_Lin_00251 */
        callIsValid = Lin_ValidateChannelConfigCall(Channel, LIN_CHECKWAKEUP_ID);
    }
    else
    {
        /*Intentionally Empty*/
    }
    if ((Std_ReturnType)E_OK == callIsValid)
#endif
    {
        /*  LIN_CH_SLEEP_STATE state */
        if (LIN_CH_SLEEP_STATE == Lin_ChannelStatus[Channel])
        {
            /* Lin channel is in LIN_CH_SLEEP_STATE state */
            if ((uint8)STD_ON == Lin_ChannelConfigPtr[Channel]->ChannelWakeupSupport)
            {
                /* Check if Lin channel has detected a wake-up */
                if ((uint8)TRUE == Lin_Im_UsartCheckWakeup(Channel))
                {
                    /* Indicates a valid timer wakeup event to ECU State Manager */
                    /* @implements SWS_Lin_00098 */
                    EcuM_SetWakeupEvent(Lin_ChannelConfigPtr[Channel]->ChannelEcuMWakeupSource);
                    /* Report the wakeup source after the successful wakeup to LinInterface */
#if 0
                     LinIf_WakeupConfirmation(Lin_ChannelConfigPtr[Channel]->ChannelEcuMWakeupSource);
#endif
                }
                else
                {
                    /* do nothing */
                }
            }
            else
            {
                /* do nothing */
            }
        }
        else
        {
            /* Do Nothing */
        }
    }
#if (LIN_DEV_ERROR_DETECT == STD_ON)
    else
    {
        /*Intentionally Empty*/
    }
#endif

    return callIsValid;
}

#if (LIN_VERSION_INFO_API == STD_ON)
/**
 * @brief Returns the version information of this module
 * @details
 * Service name: Lin_GetVersionInfo
 * Syntax: void Lin_GetVersionInfo (Std_VersionInfoType* versioninfo)
 * Service ID[hex]: 0x01
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * @implements #SWS_Lin_00161,#SWS_Lin_00001,#SWS_Lin_00248
 * @param VersionInfo Pointer to where is stored the version information of this module.
 * @return None
 * @retval None
 */
FUNC(void, LIN_CODE) Lin_GetVersionInfo(Std_VersionInfoType *VersionInfo)
{
    /* @implements #SWS_Lin_00248 */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == VersionInfo)
    {
        Lin_ReportDetError((uint8)LIN_GETVERSIONINFO_ID, (uint8)LIN_E_PARAM_POINTER);
    }
    else
#endif
    {
        /* @implements SWS_Lin_00001 */
        (VersionInfo)->vendorID         = (uint16)LIN_VENDOR_ID;
        (VersionInfo)->moduleID         = (uint8)LIN_MODULE_ID;
        (VersionInfo)->sw_major_version = (uint8)LIN_SW_MAJOR_VERSION;
        (VersionInfo)->sw_minor_version = (uint8)LIN_SW_MINOR_VERSION;
        (VersionInfo)->sw_patch_version = (uint8)LIN_SW_PATCH_VERSION;
    }
}
#endif

/**
 * @brief Sends a LIN header and a LIN response, if necessary. The direction of the frame response (master response,
 * slave response, slave-to-slave communication) is provided by the PduInfoPtr.Only used for LIN master nodes.
 * @details
 * Service name: Lin_SendFrame
 * Syntax: Std_ReturnType Lin_SendFrame (uint8 Channel,const Lin_PduType* PduInfoPtr)
 * Service ID[hex]: 0x04
 * Sync/Async: Asynchronous
 * Reentrancy: Non Reentrant
 * @implements #SWS_Lin_00191,#SWS_Lin_00192,#SWS_Lin_00193,#SWS_Lin_00194,#SWS_Lin_00239,#SWS_Lin_00240,
 * #SWS_Lin_00195,#SWS_Lin_00197,#SWS_Lin_00198,#SWS_Lin_00199,#SWS_Lin_00287
 * @param Channel LIN channel to be addressed
 * @param PduInfoPtr Pointer to PDU containing the PID, checksum model, response type, Dl and SDU data pointer
 * @return Std_ReturnType
 * @retval E_OK Send command has been accepted.
 * @retval E_NOT_OK API Send command has not been accepted,development or production error occurred.
 */
FUNC(Std_ReturnType, LIN_CODE) Lin_SendFrame(uint8 Channel, const Lin_PduType *PduInfoPtr)
{
    Std_ReturnType tempReturn;

#if (LIN_DEV_ERROR_DETECT == STD_ON)
    /* Check whether the LIN driver is in LIN_INIT state */
    /* @implements #SWS_Lin_00195 */
    tempReturn = Lin_ValidateGlobalConfigCall(LIN_SENDFRAME_ID);
    if ((Std_ReturnType)E_OK == tempReturn)
    {
        /* @implements #SWS_Lin_00197 */
        tempReturn = Lin_ValidateChannelConfigCall(Channel, LIN_SENDFRAME_ID);
        if ((Std_ReturnType)E_OK == tempReturn)
        {
            /* @implements #SWS_Lin_00198 */
            tempReturn = Lin_ValidateSendParamPtrInit(PduInfoPtr);
        }
    }
    else
    {
        /*Intentionally Empty*/
    }
    if ((Std_ReturnType)E_OK == tempReturn)
#endif
    {
        /* @implements #SWS_Lin_00194,#SWS_Lin_00199 */
        if (LIN_CH_SLEEP_STATE == Lin_ChannelStatus[Channel])
        {
            tempReturn = (uint8)E_NOT_OK;
#if (LIN_DEV_ERROR_DETECT == STD_ON)
            /* Report error to development error tracer */
            Lin_ReportDetError((uint8)LIN_SENDFRAME_ID, (uint8)LIN_E_STATE_TRANSITION);
#endif
        }
        else
        {
            /* Lin Master Device will send the header first */
            /* @implements SWS_Lin_00192 */
            if ((uint8)E_NOT_OK == Lin_Im_UsartSendHeader(Channel, PduInfoPtr))
            {
/* Report Production error */
#if (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                if (STD_ON == Lin_E_TimeOutCfg.state)
                {
                    (void)Dem_SetEventStatus((Dem_EventIdType)Lin_E_TimeOutCfg.id, DEM_EVENT_STATUS_FAILED);
                }
                else
                {
#if (LIN_DEV_ERROR_DETECT == STD_ON)
                    /* Report error to development error tracer */
                    Lin_ReportDetError((uint8)LIN_SENDFRAME_ID, (uint8)LIN_E_TIMEOUT);
#endif
                }
#else
#if (LIN_DEV_ERROR_DETECT == STD_ON)
                /* Report error to development error tracer */
                Lin_ReportDetError((uint8)LIN_SENDFRAME_ID, (uint8)LIN_E_TIMEOUT);
#endif
#endif
                tempReturn = (uint8)E_NOT_OK;
            }
            else
            {
                /* Report Production no error */
#if (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                if (STD_ON == Lin_E_TimeOutCfg.state)
                {
                    (void)Dem_SetEventStatus((Dem_EventIdType)Lin_E_TimeOutCfg.id, DEM_EVENT_STATUS_PASSED);
                }
#endif
                /* Set header status to TRUE if master wants to send the response frame */
                if (LIN_MASTER_RESPONSE == PduInfoPtr->Drc)
                {
                    Lin_ChannelHeaderStatus[Channel] = (uint8)TRUE;
                }
                else
                {
                    /* do nothing */
                }

                /* Lin_SendHeader() function should be called first */
                if ((uint8)FALSE != Lin_ChannelHeaderStatus[Channel])
                {
                    Lin_ChannelHeaderStatus[Channel] = (uint8)FALSE;
                    Lin_Im_UsartSendResponse(Channel, PduInfoPtr);
                    tempReturn = (uint8)E_OK;
                }
                else
                {
                    tempReturn = (uint8)E_OK;
                }
            }
        }
    }
#if (LIN_DEV_ERROR_DETECT == STD_ON)
    else
    {
        /*Intentionally Empty*/
    }
#endif
    return tempReturn;
}

/**
 * @brief The service instructs the driver to transmit a go-to-sleep-command on the addressed LIN channel.Only used for
 * LIN master nodes.
 * @details
 * Service name: Lin_GoToSleep
 * Syntax: Std_ReturnType Lin_GoToSleep (uint8 Channel)
 * Service ID[hex]: 0x06
 * Sync/Async: Asynchronous
 * Reentrancy: Non Reentrant
 * @implements #SWS_Lin_00166,#SWS_Lin_00089,#SWS_Lin_00266,#SWS_Lin_00220,#SWS_Lin_00221,#SWS_Lin_00255,
 * #SWS_Lin_00074,#SWS_Lin_00129,#SWS_Lin_00131,#SWS_Lin_00288
 * @param Channel LIN channel to be addressed
 * @return Std_ReturnType
 * @retval E_OK Sleep command has been accepted
 * @retval E_NOT_OK Sleep command has not been accepted,development or production error occurred
 */
FUNC(Std_ReturnType, LIN_CODE) Lin_GoToSleep(uint8 Channel)
{
    Std_ReturnType tempReturn;

#if (LIN_DEV_ERROR_DETECT == STD_ON)
    /* Check whether the LIN driver is in LIN_INIT state */
    /* @implements #SWS_Lin_00129 */
    tempReturn = Lin_ValidateGlobalConfigCall(LIN_GOTOSLEEP_ID);
    if ((Std_ReturnType)E_OK == tempReturn)
    {
        /* @implements #SWS_Lin_00131 */
        tempReturn = Lin_ValidateChannelConfigCall(Channel, LIN_GOTOSLEEP_ID);
    }
    else
    {
        /*Intentionally Empty*/
    }
    if ((Std_ReturnType)E_OK == tempReturn)
#endif
    {
        /* Check whether the LIN channel is in LIN_CH_SLEEP_STATE state */
        if (LIN_CH_SLEEP_STATE == Lin_ChannelStatus[Channel])
        {
            tempReturn = (uint8)E_OK;
        }
        else
        {
            /* @implements #SWS_Lin_00089 */
            if ((uint8)E_NOT_OK == Lin_Im_UsartGoToSleep(Channel))
            {
/* Report Production error */
#if (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                if (STD_ON == Lin_E_TimeOutCfg.state)
                {
                    (void)Dem_SetEventStatus((Dem_EventIdType)Lin_E_TimeOutCfg.id, DEM_EVENT_STATUS_FAILED);
                }
                else
                {
#if (LIN_DEV_ERROR_DETECT == STD_ON)
                    /* Report error to development error tracer */
                    Lin_ReportDetError((uint8)LIN_GOTOSLEEP_ID, (uint8)LIN_E_TIMEOUT);
#endif
                }
#else
#if (LIN_DEV_ERROR_DETECT == STD_ON)
                /* Report error to development error tracer */
                Lin_ReportDetError((uint8)LIN_GOTOSLEEP_ID, (uint8)LIN_E_TIMEOUT);
#endif
#endif
                tempReturn = (uint8)E_NOT_OK;
            }
            else
            {
/* Report Production error */
#if (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                if (STD_ON == Lin_E_TimeOutCfg.state)
                {
                    (void)Dem_SetEventStatus((Dem_EventIdType)Lin_E_TimeOutCfg.id, DEM_EVENT_STATUS_PASSED);
                }
#endif
                tempReturn = (uint8)E_OK;
            }
            /* Set Channel state to LIN_CH_SLEEP_PENDING state */
            /* @implements #SWS_Lin_00226 */
            Lin_ChannelStatus[Channel] = LIN_CH_SLEEP_PENDING;
        }
    }
#if (LIN_DEV_ERROR_DETECT == STD_ON)
    else
    {
        /*Intentionally Empty*/
    }
#endif

    return tempReturn;
}

/**
 * @brief Sets the channel state to LIN_CH_SLEEP, enables the wake-up detection and optionally sets the LIN hardware
 * unit to reduced power operation mode (if supported by HW).
 * @details
 * Service name: Lin_GoToSleepInternal
 * Syntax: Std_ReturnType Lin_GoToSleepInternal (uint8 Channel)
 * Service ID[hex]: 0x09
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * @implements #SWS_Lin_00167,#SWS_Lin_00095,#SWS_Lin_00222,#SWS_Lin_00223,#SWS_Lin_00133,#SWS_Lin_00135
 * @param Channel LIN channel to be addressed
 * @return Std_ReturnType
 * @retval E_OK Command has been accepted
 * @retval E_NOT_OK Command has not been accepted,development or production error occurred
 */
FUNC(Std_ReturnType, LIN_CODE) Lin_GoToSleepInternal(uint8 Channel)
{
    Std_ReturnType tempReturn;

#if (LIN_DEV_ERROR_DETECT == STD_ON)
    /* Check whether the LIN driver is in LIN_INIT state */
    /* @implements #SWS_Lin_00133 */
    tempReturn = Lin_ValidateGlobalConfigCall(LIN_GOTOSLEEPINTERNAL_ID);
    if ((Std_ReturnType)E_OK == tempReturn)
    {
        /* @implements #SWS_Lin_00135 */
        tempReturn = Lin_ValidateChannelConfigCall(Channel, LIN_GOTOSLEEPINTERNAL_ID);
    }
    else
    {
        /*Intentionally Empty*/
    }
    if ((Std_ReturnType)E_OK == tempReturn)
#endif
    {
        /* Check whether the LIN channel is in LIN_CH_SLEEP_STATE state */
        if (LIN_CH_SLEEP_STATE == Lin_ChannelStatus[Channel])
        {
            tempReturn = (uint8)E_OK;
        }
        else
        {
            /* TODO:SWS_Lin_00222  */
            if ((uint8)E_NOT_OK == Lin_Im_UsartGoToSleepInternal(Channel))
            {
/* Report Production error */
#if (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                if (STD_ON == Lin_E_TimeOutCfg.state)
                {
                    (void)Dem_SetEventStatus((Dem_EventIdType)Lin_E_TimeOutCfg.id, DEM_EVENT_STATUS_FAILED);
                }
                else
                {
#if (LIN_DEV_ERROR_DETECT == STD_ON)
                    /* Report error to development error tracer */
                    Lin_ReportDetError((uint8)LIN_GOTOSLEEPINTERNAL_ID, (uint8)LIN_E_TIMEOUT);
#endif
                }
#else
#if (LIN_DEV_ERROR_DETECT == STD_ON)
                /* Report error to development error tracer */
                Lin_ReportDetError((uint8)LIN_GOTOSLEEPINTERNAL_ID, (uint8)LIN_E_TIMEOUT);
#endif
#endif
                tempReturn = (uint8)E_NOT_OK;
            }
            else
            {
/* Report Production Error */
#if (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                if (STD_ON == Lin_E_TimeOutCfg.state)
                {
                    (void)Dem_SetEventStatus((Dem_EventIdType)Lin_E_TimeOutCfg.id, DEM_EVENT_STATUS_PASSED);
                }
#endif
                /* @implements #SWS_Lin_00095 */
                Lin_ChannelStatus[Channel] = LIN_CH_SLEEP_STATE;
                /* Update LIN channel frame operation status to LIN_CH_NOT_READY_STATE */
                Lin_ChannelFrameStatus[Channel] = LIN_CH_NOT_READY_STATE;
                tempReturn                      = (uint8)E_OK;
            }
        }
    }
#if (LIN_DEV_ERROR_DETECT == STD_ON)
    else
    {
        /*Intentionally Empty*/
    }
#endif

    return tempReturn;
}

/**
 * @brief Generates a wake up pulse and sets the channel state to LIN_CH_OPERATIONAL.
 * @details
 * Service name: Lin_Wakeup
 * Syntax: Std_ReturnType Lin_Wakeup (uint8 Channel)
 * Service ID[hex]: 0x07
 * Sync/Async: Asynchronous
 * Reentrancy: Non Reentrant
 * @implements #SWS_Lin_00169,#SWS_Lin_00137,#SWS_Lin_00139,#SWS_Lin_00140
 * @param Channel LIN channel to be addressed
 * @return Std_ReturnType
 * @retval E_OK Wake-up request has been accepted
 * @retval E_NOT_OK Wake-up request has not been accepted,development or production error occurred
 */
FUNC(Std_ReturnType, LIN_CODE) Lin_Wakeup(uint8 Channel)
{
    Std_ReturnType tempReturn;

#if (LIN_DEV_ERROR_DETECT == STD_ON)
    /* Check whether the LIN driver is in LIN_INIT state */
    /* @implements #SWS_Lin_00137 */
    tempReturn = Lin_ValidateGlobalConfigCall(LIN_WAKEUP_ID);
    if ((Std_ReturnType)E_OK == tempReturn)
    {
        /* Invalid channel */
        /* @implements #SWS_Lin_00139 */
        tempReturn = Lin_ValidateChannelConfigCall(Channel, LIN_WAKEUP_ID);
    }
    else
    {
        /*Intentionally Empty*/
    }
    if ((Std_ReturnType)E_OK == tempReturn)
#endif
    {
        /* Check whether the LIN channel is in LIN_CH_SLEEP_STATE state */
        /* @implements SWS_Lin_00140 */
        if (LIN_CH_SLEEP_STATE != Lin_ChannelStatus[Channel])
        {
            /* LIN channel is not in sleep mode */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
            /* Report error to development error tracer */
            Lin_ReportDetError((uint8)LIN_WAKEUP_ID, (uint8)LIN_E_STATE_TRANSITION);
#endif
            tempReturn = (uint8)E_NOT_OK;
        }
        else
        {
            /* Call LLD function */
            Lin_Im_UsartWakeUp(Channel);
            /* Update LIN channel status to LIN_CH_OPERATIONAL */
            Lin_ChannelStatus[Channel] = LIN_CH_OPERATIONAL;
            /* Update LIN channel frame operation status to
             * LIN_CH_READY_STATE */
            Lin_ChannelFrameStatus[Channel] = LIN_CH_READY_STATE;
            /* Reset Frame Error status to LIN_NO_ERROR */
            Lin_ChannelFrameErrorStatus[Channel] = LIN_NO_ERROR;
            tempReturn                           = (uint8)E_OK;
        }
    }
#if (LIN_DEV_ERROR_DETECT == STD_ON)
    else
    {
        /*Intentionally Empty*/
    }
#endif

    return tempReturn;
}

/**
 * @brief Sets the channel state to LIN_CH_OPERATIONAL without generating a wake up pulse.
 * @details
 * Service name: Lin_WakeupInternal
 * Syntax: Std_ReturnType Lin_WakeupInternal (uint8 Channel)
 * Service ID[hex]: 0x0b
 * Sync/Async: Asynchronous
 * Reentrancy: Non Reentrant
 * @implements #SWS_Lin_00256,#SWS_Lin_00257,#SWS_Lin_00258,#SWS_Lin_00259,#SWS_Lin_00260
 * @param Channel LIN channel to be addressed
 * @return Std_ReturnType
 * @retval E_OK Wake-up request has been accepted
 * @retval E_NOT_OK Wake-up request has not been accepted, development or production error occurred
 */
FUNC(Std_ReturnType, LIN_CODE) Lin_WakeupInternal(uint8 Channel)
{
    Std_ReturnType tempReturn;

#if (LIN_DEV_ERROR_DETECT == STD_ON)
    /* Check whether the LIN driver is in LIN_INIT state */
    /* @implements SWS_Lin_00258 */
    tempReturn = Lin_ValidateGlobalConfigCall(LIN_WAKEUPINTERNAL_ID);
    if ((Std_ReturnType)E_OK == tempReturn)
    {
        /* Invalid channel */
        /* @implements SWS_Lin_00259 */
        tempReturn = Lin_ValidateChannelConfigCall(Channel, LIN_WAKEUPINTERNAL_ID);
    }
    else
    {
        /*Intentionally Empty*/
    }
    if ((Std_ReturnType)E_OK == tempReturn)
#endif
    {
        /* Check whether the LIN channel is in LIN_CH_SLEEP_STATE state */
        /* @implements SWS_Lin_00260 */
        if (LIN_CH_SLEEP_STATE != Lin_ChannelStatus[Channel])
        {
            /* LIN channel is not in sleep mode */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
            /* Report error to development error tracer */
            Lin_ReportDetError((uint8)LIN_WAKEUPINTERNAL_ID, (uint8)LIN_E_STATE_TRANSITION);
#endif
            tempReturn = (uint8)E_NOT_OK;
        }
        else
        {
            /* @implements #SWS_Lin_00257 */
            Lin_Im_UsartWakeUpInternal(Channel);
            /* Update LIN channel status to LIN_CH_OPERATIONAL */
            Lin_ChannelStatus[Channel] = LIN_CH_OPERATIONAL;
            /* Update LIN channel frame operation status to LIN_CH_READY_STATE */
            Lin_ChannelFrameStatus[Channel] = LIN_CH_READY_STATE;
            /* Reset Frame Error status to LIN_NO_ERROR */
            Lin_ChannelFrameErrorStatus[Channel] = LIN_NO_ERROR;
            tempReturn                           = (uint8)E_OK;
        }
    }
#if (LIN_DEV_ERROR_DETECT == STD_ON)
    else
    {
        /*Intentionally Empty*/
    }
#endif

    return tempReturn;
}

/**
 * @brief Gets the status of the LIN driver.Only used for LIN master nodes.
 * @details
 * Service name: Lin_GetStatus
 * Syntax: Lin_StatusType Lin_GetStatus (uint8 Channel,const uint8** Lin_SduPtr)
 * Service ID[hex]: 0x08
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * @implements
 * #SWS_Lin_00168,#SWS_Lin_00091,#SWS_Lin_00200,#SWS_Lin_00092,#SWS_Lin_00238,#SWS_Lin_00141,#SWS_Lin_00143,,#SWS_Lin_00144,#SWS_Lin_00289
 * @param Channel LIN channel to be checked
 * @param Lin_SduPtr Pointer to pointer to a shadow buffer or memory mapped LIN Hardware receive buffer where the
 * current SDU is stored.
 * @return Lin_StatusType
 * @retval LIN_NOT_OK Development or production error occurred
 * @retval LIN_TX_OK Successful transmission
 * @retval LIN_TX_BUSY Ongoing transmission(Header or Response)
 * @retval LIN_TX_HEADER_ERROR Erroneous header transmission such as:
 *                             - Mismatch between sent and read back data
 *                             - Identifier parity error or Physical bus error
 * @retval LIN_TX_ERROR Erroneous response transmission such as:
 *                      - Mismatch between sent and read back data
 *                      - Physical bus error
 * @retval LIN_RX_OK Reception of correct response
 * @retval LIN_RX_BUSY Ongoing reception: at least one response byte has been received, but the checksum byte has not
 * been received
 * @retval LIN_RX_ERROR Erroneous response reception such as:
 *                      - Framing error
 *                      - Overrun error
 *                      - Checksum error or Short response
 * @retval LIN_RX_NO_RESPONSE No response byte has been received so far
 * @retval LIN_OPERATIONAL Normal operation; the related LIN channel is woken up from the LIN_CH_SLEEP and no data has
 * been sent.
 * @retval LIN_CH_SLEEP Sleep state operation; in this state wake-up detection from slave nodes is enabled.
 */
FUNC(Lin_StatusType, LIN_CODE) Lin_GetStatus(uint8 Channel, uint8 **Lin_SduPtr)
{
    Lin_StatusType tempReturn;

#if (LIN_DEV_ERROR_DETECT == STD_ON)
    /* Check whether the LIN driver is in LIN_INIT state */
    /* @implements SWS_Lin_00141 */
    /* PRQA S 4342 6 #KQR004342 */
    tempReturn = (Lin_StatusType)Lin_ValidateGlobalConfigCall(LIN_GETSTATUS_ID);
    if ((Std_ReturnType)E_OK == (uint8)tempReturn)
    {
        /* Invalid channel */
        /* @implements SWS_Lin_00143 */
        tempReturn = (Lin_StatusType)Lin_ValidateChannelConfigCall(Channel, LIN_GETSTATUS_ID);
    }
    else
    {
        /*Intentionally Empty*/
    }
    if ((Std_ReturnType)E_OK == (uint8)tempReturn)
#endif
    {
        /* Check PduInfoPtr for not being a null pointer */
        /* @implements SWS_Lin_00144 */
        if (NULL_PTR == Lin_SduPtr)
        {
            /* Invalid pointer */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
            /* Report error to development error tracer */
            Lin_ReportDetError((uint8)LIN_GETSTATUS_ID, (uint8)LIN_E_PARAM_POINTER);
#endif
            tempReturn = LIN_NOT_OK;
        }
        else
        {
            /* LIN channel state */
            /* @implements #SWS_Lin_00200*/
            /* PRQA S 2032 1 #KQR002032 */
            switch (Lin_ChannelStatus[Channel])
            {
            case LIN_CH_SLEEP_STATE: {
                tempReturn = LIN_CH_SLEEP;
            }
            break;
            case LIN_CH_SLEEP_PENDING: { /* @implements #SWS_Lin_00255 */
                Lin_ChannelStatus[Channel] = LIN_CH_SLEEP_STATE;
                *Lin_SduPtr                = Lin_SduBuffAddress[Channel];
                tempReturn                 = LIN_CH_SLEEP;
            }
            break;
            case LIN_CH_OPERATIONAL: {
                /* LIN Channel frame state */
                /* Initialize the pointer to return with */
                /* the address of the data receive buffer */
                *Lin_SduPtr = Lin_SduBuffAddress[Channel];
                /* @implements #SWS_Lin_00193,#SWS_Lin_00092,#SWS_Lin_00238 */
                tempReturn = Lin_Im_UsartHardwareGetStatus(Channel, Lin_SduBuffAddress[Channel]);
            }
            break;
            default:
                tempReturn = LIN_NOT_OK;
                break;
            }
        }
    }
#if (LIN_DEV_ERROR_DETECT == STD_ON)
    else
    {
        tempReturn = LIN_NOT_OK;
    }
#endif

    /* @implements SWS_Lin_00091 */
    return tempReturn;
}

/* EOF */
