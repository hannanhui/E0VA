/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Port.c
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2025-08-29
 *  @Version         : V1.0.0_SF
 *  @Description     : This document describes the C language document template.
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 ******************************************************************************
 *                        REVISION HISTORY
 ******************************************************************************
 *  |Date        |Version  |Author        |Description
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
/* PRQA S 0303 EOF #KQR000303 */
/* PRQA S 1290 EOF #KQR001290 */
/* PRQA S 2032 EOF #KQR002032 */
/* PRQA S 0488 EOF #KQR000488 */
/* PRQA S 2814 EOF #KQR002814 */
/* PRQA S 2824 EOF #KQR002824 */
/* PRQA S 2844 EOF #KQR002844 */
/* PRQA S 2201 EOF #KQR002201 */
/* PRQA S 2919 EOF #KQR002919 */
/* PRQA S 3383 EOF #KQR003383 */
/******************************************************************************
 **                        Include Files
 ******************************************************************************/
/**
 * @brief port.c shall include Port.h, Port_MemMap.h,Det.h,SchM_Port.h
 * @implements #SWS_Port_00131
 */
#include "Port.h"
#include "Port_Im.h"
/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/
/* AutoSar stander macro definitions */
#if (PORT_DEV_ERROR_DETECT == STD_ON)
#define PORT_INITIALIZES_OK     (0x01U)
#define PORT_INITIALIZES_NOT_OK (0x00U)
#endif
/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/

/******************************************************************************
 **                        Export Variables
 ******************************************************************************/
#if (PORT_PRECOMPILE_SUPPORT == STD_ON)
extern const Port_ConfigType Port_ConfigPredefined;
#endif
/******************************************************************************
 **                        Export Functions
 ******************************************************************************/

/******************************************************************************
 **                      Constant Declarations
 ******************************************************************************/
static const Port_ConfigType *Port_ConfigPtr = NULL_PTR;
/******************************************************************************
**                     Variable Declarations
******************************************************************************/
#if (PORT_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief short for det error function
 *
 * @param ApiId
 * @param ErrorId
 */
LOCAL_INLINE void Port_ReportDetError(uint8 ApiId, uint8 ErrorId)
{
    (void)Det_ReportError((uint16)PORT_MODULE_ID, (uint8)PORT_INSTANCE_ID, ApiId, ErrorId);
}
#endif

/**
 * @brief Get Port Index
 *
 * @param Pin
 * @retval Port_PinType
 */
LOCAL_INLINE Port_PinType Port_GetPortIndex(Port_PinType Pin)
{
    return (Port_PinType)((Pin & (Port_PinType)0xF0U) >> 4U);
}

/**
 * @brief Get Pin Index
 *
 * @param Pin
 * @retval Port_PinType
 */
LOCAL_INLINE Port_PinType Port_GetPinIndex(Port_PinType Pin)
{
    return (Port_PinType)((Pin & (Port_PinType)0x0FU));
}

/**
 * @brief get set AFunction
 *
 * @param Mode
 * @retval Port_PinModeType
 */
LOCAL_INLINE Port_PinModeType Port_GetAltFcn(Port_PinModeType Mode)
{
    return (Port_PinModeType)((Mode & (Port_PinModeType)0xFFFF0000U) >> 16U);
}

/**
 * @brief get set mode
 *
 * @param Mode
 * @retval Port_PinModeType
 */
LOCAL_INLINE Port_PinModeType Port_GetMode(Port_PinModeType Mode)
{
    return (Port_PinModeType)((Mode & (Port_PinModeType)0xFFFFU));
}
/******************************************************************************
 **                      Private Function Declarations
 ******************************************************************************/

/**
 * @brief check port or pin valid
 *
 * @param Port port number
 * @param Pin pin number
 * @retval Std_ReturnType
 * @return E_OK-check ok
 * E_NOT_OK-check error
 */
static Std_ReturnType Port_ValidateInitParam(Port_PinType Port, uint32 Pin)
{
    Std_ReturnType retErr;
    /* PRQA S 1840 2 #KQR001840 */
    if ((Port > (PORT_TOTAL_NUMBER - 1)) || (Pin > (PORT_PIN_TOTAL_NUMBER - 1)))
    {
        /* ConfigPtr is NULL_PTR, report DET error for variant PB */
#if (PORT_DEV_ERROR_DETECT == STD_ON)
        Port_ReportDetError(PORT_INIT_SID, PORT_E_INIT_FAILED);
#endif
        retErr = E_NOT_OK;
    }
    else
    {
        retErr = E_OK;
    }

    return retErr;
}
/******************************************************************************
 **                      Function Implementation
 ******************************************************************************/

#if (PORT_SET_PIN_MODE_API == STD_ON)
/**
 * @brief Sets the port pin mode
 * @details
 * Syntax: void Port_SetPinMode(Port_PinType Pin,Port_PinModeType Mode)
 * Service ID[hex]: 0x04
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * @implements #SWS_Port_00145,#SWS_Port_00125,#SWS_Port_00128,#SWS_Port_00223
 * @param Pin Port Pin ID number(high 4bit represent port num,low 4bit represent pin num)
 * @param Mode New Port Pin mode to be set on port pin.(high 8bit represent remap function,low 8bit represent remap
 * mode)
 * @retval void
 * @return void
 */
FUNC(void, PORT_CODE) Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode)
{
    Port_PinType portIndex;
    Port_PinType pinIndex;

    uint16 portAltFcn;
    uint16 portMode;

    uint8 loop = 0U;

    boolean isFind = FALSE;
    uint8   configNum;

    const Port_PinConfigType *configPtr;

    portIndex = Port_GetPortIndex(Pin);
    pinIndex  = Port_GetPinIndex(Pin);

    portAltFcn = (uint16)Port_GetAltFcn(Mode);
    portMode   = (uint16)Port_GetMode(Mode);

#if (PORT_DEV_ERROR_DETECT == STD_ON)
    /**
     * @brief check the function parameters
     * @implements #SWS_Port_00125
     */
    if (NULL_PTR == Port_ConfigPtr)
    {
        Port_ReportDetError(PORT_SETPINMODE_SID, PORT_E_UNINIT);
    }
    else if ((portIndex > (PORT_TOTAL_NUMBER - 1U)) || (pinIndex > (PORT_PIN_TOTAL_NUMBER - 1U)))
    {
        /* pin ID out of range */
        Port_ReportDetError(PORT_SETPINMODE_SID, PORT_E_PARAM_PIN);
    }
    else if ((portMode > MODE_AN) || (portAltFcn > GPIO_PAGE3_REMAP_AF14))
    {
        /* pin Mode out of range */
        /* BugFix: #293. Issue report type error */
        Port_ReportDetError(PORT_SETPINMODE_SID, PORT_E_PARAM_INVALID_MODE);
    }
    else
#endif
    {
        configNum = Port_ConfigPtr->NumConfig;
        configPtr = Port_ConfigPtr->PortPinConfigPtr;
        /* Find specific pin config */
        do
        {
            if ((portIndex == configPtr[loop].PortBase) && (pinIndex == configPtr[loop].PinIndex))
            {
                isFind = TRUE;
                break;
            }
            else
            {
                /* Avoid QAC 2000 Warning */
            }
            loop++;
        } while (loop < configNum);

        if (isFind == TRUE)
        {
            /* check pin availability */
            if (Port_Im_isPortPinMasked(portIndex, pinIndex) == PORT_PIN_MASKED)
            {
#if (PORT_DEV_ERROR_DETECT == STD_ON)
                /* pin not available */
                Port_ReportDetError(PORT_SETPINMODE_SID, PORT_E_PARAM_PIN);
#endif
            }
#if (PORT_DEV_ERROR_DETECT == STD_ON)
            /* @implements #SWS_Port_00223 */
            else if (configPtr[loop].IsPinsModeChangeable == MODE_NOT_CHANGEABLE)
            {
                /* pin mode not changeable in config data */
                Port_ReportDetError(PORT_SETPINMODE_SID, PORT_E_MODE_UNCHANGEABLE);
            }
#endif
            else
            {
                Port_Im_SetPinMode(portIndex, pinIndex, portAltFcn, portMode);
            }
        }
        else
        {
#if (PORT_DEV_ERROR_DETECT == STD_ON)
            Port_ReportDetError(PORT_SETPINMODE_SID, PORT_E_PARAM_INVALID_RANGE);
#endif
        }
    }
}
#endif

#if (STD_ON == PORT_VERSION_INFO_API)
/**
 * @brief Returns the version information of this module
 * @details
 * Syntax: void Port_GetVersionInfo(Std_VersionInfoType* Versioninfo)
 * Service ID[hex]: 0x03
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * @implements #SWS_Port_00143,#SWS_Port_00225
 * @param Versioninfo Pointer to where to store the version information of this module
 * @retval void
 * @return void
 */
FUNC(void, PORT_CODE) Port_GetVersionInfo(Std_VersionInfoType *Versioninfo)
{
    /** @implements #SWS_Port_00225 */
#if (STD_ON == PORT_DEV_ERROR_DETECT)
    if (NULL_PTR == Versioninfo)
    {
        Port_ReportDetError(PORT_GETVERSIONINFO_SID, PORT_E_PARAM_POINTER);
    }
    else
#endif
    {
        (Versioninfo)->vendorID         = (uint16)PORT_VENDOR_ID;
        (Versioninfo)->moduleID         = (uint16)PORT_MODULE_ID;
        (Versioninfo)->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
        (Versioninfo)->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
        (Versioninfo)->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
    }
}
#endif

/**
 * @brief Refreshes port direction
 * @details
 * void Port_RefreshPortDirection(void)
 * Service ID[hex]: 0x02
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * @implements #SWS_Port_00142,#SWS_Port_00060,#SWS_Port_00061
 * @retval void
 * @return void
 */
FUNC(void, PORT_CODE) Port_RefreshPortDirection(void)
{
    uint32 loop;
    uint32 configNum;

    Port_PinType portBase;
    Port_PinType pinIndex;

    const Port_PinConfigType *pinConfig;

#if (PORT_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Port_ConfigPtr)
    {
        Port_ReportDetError(PORT_REFRESHPORTDIR_SID, PORT_E_UNINIT);
    }
    else
#endif
    {
        configNum = Port_ConfigPtr->NumConfig;

        /** @implements #SWS_Port_00060 */
        for (loop = 0U; loop < configNum; ++loop)
        {
            pinConfig = Port_ConfigPtr->PortPinConfigPtr + loop;
            portBase  = pinConfig->PortBase;
            pinIndex  = pinConfig->PinIndex;

            /** @implements #SWS_Port_00061 */
            /* BugFix: #260. Issue wrong conditional */
            /* BugFix: #261. Issue remove PORT_SET_PIN_DIRECTION_API used to control IsDirChangeable  */
            /* PRQA S 3415 3 #KQR003415 */
            if ((Port_Im_isPortPinMasked(portBase, pinIndex) == PORT_PIN_NOT_MASKED) &&
                (pinConfig->IsDirChangeable == DIR_NOT_CHANGEABLE) &&
                (Port_Im_GetMode((uint32)pinConfig->PinsControl) <= MODE_GPIO_OUT))
            {
                Port_Im_RefreshPinDirection(portBase, pinIndex, pinConfig->PinsControl);
            }
            else
            {
                /* Avoid QAC 2000 Warning */
            }
        }
    }
}

#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
/**
 * @brief Sets the port pin direction
 * @details
 * Syntax: void Port_SetPinDirection(Port_PinType Pin,Port_PinDirectionType
 * Direction)
 * Service ID[hex]: 0x01
 * Sync/Async: Synchronous
 * Reentrancy:Reentrant
 * @implements #SWS_Port_00141,#SWS_Port_00063,#SWS_Port_00054,#SWS_Port_00086
 * @param Pin Port Pin ID number(high 4bit represent port num,low 4bit represent pin num)
 * @param Direction Port Pin Direction
 * @retval void
 * @return void
 */
FUNC(void, PORT_CODE) Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction)
{
    Port_PinType portIndex;
    Port_PinType pinIndex;

    uint8 loop = 0U;

    boolean isFind = FALSE;
    uint8   configNum;

    Port_PinDirectionType pinMode;

    const Port_PinConfigType *configPtr;

    portIndex = Port_GetPortIndex(Pin);
    pinIndex  = Port_GetPinIndex(Pin);

    /** @implements #SWS_Port_00063 */
#if (PORT_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Port_ConfigPtr)
    {
        Port_ReportDetError(PORT_SETPINDIRECTION_SID, PORT_E_UNINIT);
    }
    else
#endif
    {
#if (PORT_DEV_ERROR_DETECT == STD_ON)
        /* check paramater "Port_PinType Pin" : Pin Index */
        /** @implements #SWS_Port_00077 */
        if ((portIndex > (PORT_TOTAL_NUMBER - 1U)) || (pinIndex > (PORT_PIN_TOTAL_NUMBER - 1U)))
        {
            /* pin ID not out of range */
            Port_ReportDetError(PORT_SETPINDIRECTION_SID, PORT_E_PARAM_PIN);
        }
        else
#endif
        {
            configNum = Port_ConfigPtr->NumConfig;
            configPtr = Port_ConfigPtr->PortPinConfigPtr;
            /* TODO Optimize below look up loop */
            /* Find specific pin config */
            do
            {
                if ((portIndex == configPtr[loop].PortBase) && (pinIndex == configPtr[loop].PinIndex))
                {
                    isFind = TRUE;
                    break;
                }
                else
                {
                    /* Avoid QAC 2000 Warning */
                }
                loop++;
            } while (loop < configNum);

            if (isFind == TRUE)
            {
                pinMode = Port_Im_GetModeDirectionStatus(portIndex, pinIndex);

                /* check pin availability */
                if (Port_Im_isPortPinMasked(portIndex, pinIndex) == PORT_PIN_MASKED)
                {
                    /* pin not available */
#if (PORT_DEV_ERROR_DETECT == STD_ON)
                    Port_ReportDetError(PORT_SETPINDIRECTION_SID, PORT_E_PARAM_PIN);
#endif
                }
                /* Pin not direction changeable in config data */
#if (PORT_DEV_ERROR_DETECT == STD_ON)
                /* @implements #SWS_Port_00086 */
                else if (configPtr[loop].IsDirChangeable == DIR_NOT_CHANGEABLE)
                {
                    Port_ReportDetError(PORT_SETPINDIRECTION_SID, PORT_E_DIRECTION_UNCHANGEABLE);
                }
#endif
                else if ((pinMode != PORT_PIN_IN) && (pinMode != PORT_PIN_OUT))
                {
                    /* start - To be checked : uncertain */
                    /* only GPIO mode can support direction change */
#if (PORT_DEV_ERROR_DETECT == STD_ON)
                    Port_ReportDetError(PORT_SETPINDIRECTION_SID, PORT_E_DIRECTION_UNCHANGEABLE);
#endif
                    /* End - To be checked : uncertain */
                }
                else
                {
                    Port_Im_SetPinDirection(portIndex, pinIndex, Direction);
                }
            }
            else
            {
#if (PORT_DEV_ERROR_DETECT == STD_ON)
                Port_ReportDetError(PORT_SETPINDIRECTION_SID, PORT_E_PARAM_INVALID_RANGE);
#endif
            }
        }
    }
}
#endif

/**
 * @brief Initializes the Port Driver module
 * @details
 * Syntax : void Port_Init(const Port_ConfigType* ConfigPtr)
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * @implements
 * #SWS_Port_00140,#SWS_Port_00041,#SWS_Port_00078,#SWS_Port_00213,#SWS_Port_00042,#SWS_Port_00043,#SWS_Port_00071,
 * #SWS_Port_00002,#SWS_Port_00003,#SWS_Port_00055,#SWS_Port_00121
 * @param ConfigPtr Pointer to configuration set
 * @retval void
 * @return void
 */
FUNC(void, PORT_CODE) Port_Init(const Port_ConfigType *ConfigPtr)
{
    uint8                     loop;
    const Port_PinConfigType *configPtr;

    /* @implements #SWS_Port_00121 */
#if (PORT_DEV_ERROR_DETECT == STD_ON)
    uint8 status = E_OK;

#if (PORT_PRECOMPILE_SUPPORT == STD_ON)
    if (NULL_PTR != ConfigPtr)
#else
    if (NULL_PTR == ConfigPtr)
#endif
    {
        Port_ReportDetError(PORT_INIT_SID, PORT_E_INIT_FAILED);
        status = E_NOT_OK;
    }
    else
    {
        /* Do Nothing */
    }

    if (status == E_OK)
#endif
    {
#if (PORT_PRECOMPILE_SUPPORT == STD_OFF)
        /* Store ConfigPtr to use any other APIs */
        Port_ConfigPtr = ConfigPtr;
#else
        (void)(ConfigPtr);
        Port_ConfigPtr = &Port_ConfigPredefined;
#endif

        /**
         * @brief reset hardware uint
         * @implements #SWS_Port_00055,#SWS_Port_00003
         */
        Port_Im_Reset();

        /* pin init */
        /* @implements #SWS_Port_00041 */
        for (loop = 0U; loop < Port_ConfigPtr->NumConfig; loop++)
        {
            configPtr = Port_ConfigPtr->PortPinConfigPtr + loop;

            if (Port_ValidateInitParam(configPtr->PortBase, configPtr->PinIndex) == E_OK)
            {
                /* ensure the port pin not masked */
                if (Port_Im_isPortPinMasked(configPtr->PortBase, configPtr->PinIndex) == PORT_PIN_NOT_MASKED)
                {
                    /* @implements #SWS_Port_00042,#SWS_Port_00003 */
                    Port_Im_PinInit(configPtr->PortBase, configPtr->PinIndex, configPtr->PinsControl);
                }
                else
                {
                    /* Do-Nothing*/
                }
            }
            else
            {
                /* Configuration error */
                break;
            }
        }
    }
}
