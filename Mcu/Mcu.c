/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Mcu.c
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
/* PRQA S 2814 EOF #KQR002814 */
/* PRQA S 2824 EOF #KQR002824 */
/* PRQA S 2844 EOF #KQR002844 */
/* PRQA S 2201 EOF #KQR002201 */
/* PRQA S 2919 EOF #KQR002919 */
/* PRQA S 2934 EOF #KQR002934 */
/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "Mcu.h"
#include "Mcu_Im.h"
#if (MCU_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
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
#if (MCU_PRECOMPILE_SUPPORT == STD_ON)
extern const Mcu_ConfigType Mcu_ConfigPredefined;
#endif
/******************************************************************************
 **                        Export Functions
 ******************************************************************************/

/******************************************************************************
 **                         Variable Declarations
 ******************************************************************************/
/**
 * @brief Static Data For Store Local Config Pointer
 */
static const Mcu_ConfigType *Mcu_ConfigPtr = NULL_PTR;

/**
 * @brief Static Data for store current clock ID
 */
/* PRQA S 2895 1 #KQR002895 */
static Mcu_ClockType Mcu_CurrentClockIndex = ((Mcu_ClockType)-1);
/******************************************************************************
 **                      Private Function Declarations
 ******************************************************************************/
#if (MCU_DEV_ERROR_DETECT == STD_ON)
LOCAL_INLINE void Mcu_ReportDetError(uint8 ApiId, uint8 ErrorId);
#endif
#if (MCU_DEV_ERROR_DETECT == STD_ON)
static Std_ReturnType Mcu_ValidatePreInit(const Mcu_ConfigType *const ConfigPtr);
#endif
/******************************************************************************
 **                      Function definitions
 ******************************************************************************/
#if (MCU_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief short for det error function
 *
 * @param ApiId
 * @param ErrorId
 */
LOCAL_INLINE void Mcu_ReportDetError(uint8 ApiId, uint8 ErrorId)
{
    (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE_ID, ApiId, ErrorId);
}
#endif

#if (MCU_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief
 *
 * @param ConfigPtr
 * @return Std_ReturnType
 */
static Std_ReturnType Mcu_ValidatePreInit(const Mcu_ConfigType *const ConfigPtr)
{
    Std_ReturnType status = (Std_ReturnType)E_OK;
#if (MCU_PRECOMPILE_SUPPORT == STD_OFF)
    if (NULL_PTR == ConfigPtr)
    {
        status = (Std_ReturnType)E_NOT_OK;
        Mcu_ReportDetError(MCU_INIT_ID, MCU_E_INIT_FAILED);
    }
    else if (NULL_PTR == ConfigPtr->HwConfigPtr)
    {
        status = (Std_ReturnType)E_NOT_OK;
        Mcu_ReportDetError(MCU_INIT_ID, MCU_E_PARAM_POINTER);
    }
#else
    if (NULL_PTR != ConfigPtr)
    {
        status = (Std_ReturnType)E_NOT_OK;
        Mcu_ReportDetError(MCU_INIT_ID, MCU_E_INIT_FAILED);
    }
#endif
    else
    {
        /* Do Nothing */
    }

    if (E_OK == status)
    {
        if (NULL_PTR != Mcu_ConfigPtr)
        {
            status = (Std_ReturnType)E_NOT_OK;
            Mcu_ReportDetError(MCU_INIT_ID, MCU_E_ALREADY_INITIALIZED);
        }
        else
        {
            /* Do Nothing */
        }
    }
    else
    {
        /* Do Nothing */
    }

    return status;
}

/**
 * @brief Mcu_InitRamSection input detection
 * @param RamSection parameter
 */
static FUNC(Std_ReturnType, MCU_CODE) Mcu_CheckParameterRamSection(Mcu_RamSectionType RamSection)
{
    VAR(Std_ReturnType, AUTOMATIC) CheckStatus = (Std_ReturnType)E_OK;

    /* checks */
    if (RamSection >= (Mcu_ConfigPtr->NumOfRamConfigs))
    {
        CheckStatus = (Std_ReturnType)E_NOT_OK;
        (void)Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_INITRAMSECTION_ID, MCU_E_PARAM_RAMSECTION);
    }
    else
    {
        if (NULL_PTR == Mcu_ConfigPtr->RamConfigPtr)
        {
            CheckStatus = (Std_ReturnType)E_NOT_OK;
            (void)Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_INITRAMSECTION_ID, MCU_E_PARAM_CONFIG);
        }
        else if ((((*Mcu_ConfigPtr->RamConfigPtr)[RamSection]).Mcu_RamWriteSize != (uint32)1U) &&
                 (((*Mcu_ConfigPtr->RamConfigPtr)[RamSection]).Mcu_RamWriteSize != (uint32)2U) &&
                 (((*Mcu_ConfigPtr->RamConfigPtr)[RamSection]).Mcu_RamWriteSize != (uint32)4U) &&
                 (((*Mcu_ConfigPtr->RamConfigPtr)[RamSection]).Mcu_RamWriteSize != (uint32)8U))
        {
            CheckStatus = (Std_ReturnType)E_NOT_OK;
            (void)Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_INITRAMSECTION_ID, MCU_E_PARAM_CONFIG);
        }
        else
        {
            /* do nothing */
        }
    }
    return (Std_ReturnType)CheckStatus;
}
#endif

/**
 * @brief MCU driver initialization function.
 * @details This routine initializes the MCU Driver. The intention of this function is to make the configuration setting
 * for power down, clock and Ram sections visible within the MCU Driver.
 *
 * Service name: Mcu_Init
 * Syntax: void Mcu_Init (const Mcu_ConfigType* ConfigPtr)
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * @implements #SWS_Mcu_00153,#SWS_Mcu_00026,#SWS_Mcu_00116,#SWS_Mcu_00244,#SWS_Mcu_00245,#SWS_Mcu_00246,#SWS_Mcu_00247
 * @param ConfigPtr-Pointer to MCU driver configuration set.
 * @retval None
 * @return None
 */
/* PRQA S 1505 1 #KQR001505 */
FUNC(void, MCU_CODE) Mcu_Init(const Mcu_ConfigType *ConfigPtr)
{
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType status;
    status = Mcu_ValidatePreInit(ConfigPtr);
    if (status == E_OK)
    {
#endif

#if (MCU_PRECOMPILE_SUPPORT == STD_ON)
        (void)(ConfigPtr);
        Mcu_ConfigPtr = &Mcu_ConfigPredefined;
#else
    Mcu_ConfigPtr = ConfigPtr;
#endif

        /* @implements #SWS_Mcu_00026 */
        Mcu_Im_Init(Mcu_ConfigPtr->HwConfigPtr);
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    }
    else
    {
        /* clean the init pointer in case of an error */
        Mcu_ConfigPtr = NULL_PTR;
    }
#endif
}

/**
 * @brief mcu wakeup reinit
 */
/* PRQA S 3408 1 #KQR003408 */
void Mcu_Stop0WakeUpReInit(void)
{
#if (MCU_PRECOMPILE_SUPPORT == STD_ON)
    Mcu_Init(NULL_PTR);
#else
    Mcu_Init(Mcu_ConfigPtr);
#endif
    /* PRQA S 3200 1 #KQR003200 */
    Mcu_InitClock(0U);
#if (MCU_NO_PLL == STD_OFF)
    /* PRQA S 2482 1 #KQR002482 */
    while (MCU_PLL_LOCKED != Mcu_GetPllStatus())
    {
    }
    /* PRQA S 3200 1 #KQR003200 */
    Mcu_DistributePllClock();
#endif
}

/**
 * @brief This service initializes the RAM section wise.
 * @details Function initializes the ram section selected by RamSection parameter. The section base address, size and
 * value to be written are provided from the configuration structure. The function will write the value specified in the
 * configuration structure indexed by RamSection. After the write it will read back the RAM to verify that the requested
 * value was written.
 *
 * Service name: Mcu_InitRamSection
 * Syntax: Std_ReturnType Mcu_InitRamSection (Mcu_RamSectionType RamSection)
 * Service ID[hex]: 0x01
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * @implements #SWS_Mcu_00154,#SWS_Mcu_00011,#SWS_Mcu_00136
 * @param  RamSection-ram config section
 * @return Std_ReturnType
 * @retval E_OK command has been accepted
 * @retval E_NOT_OK command has not been accepted e.g. due to parameter error
 */
FUNC(Std_ReturnType, MCU_CODE) Mcu_InitRamSection(Mcu_RamSectionType RamSection)
{
    const Mcu_RamConfigType *ramConfig;
    /* Result of the operation. */
    VAR(Std_ReturnType, AUTOMATIC) RamStatus;

#if (MCU_DEV_ERROR_DETECT == STD_ON)
    /* @implements #SWS_Mcu_00136 */
    if (NULL_PTR == Mcu_ConfigPtr)
    {
        Mcu_ReportDetError(MCU_INITRAMSECTION_ID, MCU_E_UNINIT);
        RamStatus = E_NOT_OK;
    }
    else if (E_NOT_OK == Mcu_CheckParameterRamSection(RamSection))
    {
        RamStatus = E_NOT_OK;
    }
    else
    {
#endif
        /* PRQA S 0488 1 #KQR000488 */
        ramConfig = *(Mcu_ConfigPtr->RamConfigPtr) + RamSection;
        /* @implements #SWS_Mcu_00011 */
        RamStatus = Mcu_Im_InitRam(ramConfig);
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    }
#endif
    return (Std_ReturnType)RamStatus;
}

#if (MCU_INIT_CLOCK == STD_ON)
/**
 * @brief This service initializes the PLL and other MCU specific clock options
 * @details This function initializes the PLL and MCU specific clock options. The clock setting is provided from the
 * configuration structure.
 *
 * Service name: Mcu_InitClock
 * Syntax: Std_ReturnType Mcu_InitClock(Mcu_ClockType ClockSetting)
 * Service ID[hex]: 0x02
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * @implements #SWS_Mcu_00155,#SWS_Mcu_00137,#SWS_Mcu_00138,#SWS_Mcu_00139,#SWS_Mcu_00210
 * @param ClockSetting-Clock setting
 * @return Std_ReturnType
 * @retval E_OK Command has been accepted
 * @retval E_NOT_OK Command has not been accepted
 */
/* PRQA S 1505 1 #KQR001505 */
FUNC(Std_ReturnType, MCU_CODE) Mcu_InitClock(VAR(Mcu_ClockType, AUTOMATIC) ClockSetting)
{
    Std_ReturnType status;

    const Mcu_ClockConfigType *clockConfig;
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    /*SWS_Mcu_00139 */
    if (NULL_PTR == Mcu_ConfigPtr)
    {
        Mcu_ReportDetError(MCU_INITCLOCK_ID, MCU_E_UNINIT);
    }
    else if (NULL_PTR == Mcu_ConfigPtr->ClockConfigPtr)
    {
        Mcu_ReportDetError(MCU_INITCLOCK_ID, MCU_E_PARAM_POINTER);
    }
    else if (ClockSetting >= Mcu_ConfigPtr->NumOfClkConfigs)
    {
        Mcu_ReportDetError(MCU_INITCLOCK_ID, MCU_E_PARAM_CLOCK);
    }
    else
    {
#endif
        /* BugFix: #224 Issue. Incorrect dereference on ClockConfigPtr Array Pointer */
        /* PRQA S 0488 1 #KQR000488 */
        clockConfig = *(Mcu_ConfigPtr->ClockConfigPtr) + ClockSetting;
        /* @implements #SWS_Mcu_00137 */
        Mcu_Im_InitClock(clockConfig);

        /* Internal voltage configuration */
        Mcu_Im_InternalRefVolConfig();

        Mcu_CurrentClockIndex = ClockSetting;

        status = (Std_ReturnType)E_OK;
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    }
#endif
    return (Std_ReturnType)status;
}
#endif

#if (MCU_INIT_CLOCK == STD_ON)
#if (MCU_NO_PLL == STD_OFF)
/**
 * @brief This function activates the PLL clock to the MCU clock distribution.
 * @details Function completes the PLL configuration and then activates the PLL clock to MCU. If the MCU_NO_PLL is TRUE
 * the Mcu_DistributePllClock has to be disabled. The function will not distribute the PLL clock if the driver state
 * does not allow it, or the PLL is not stable.
 *
 * Service name: Mcu_DistributePllClock
 * Syntax: Std_ReturnType Mcu_DistributePllClock (void)
 * Service ID[hex]: 0x03
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * @implements #SWS_Mcu_00156,#SWS_Mcu_00140,#SWS_Mcu_00141,#SWS_Mcu_00056,#SWS_Mcu_00142,#SWS_Mcu_00205
 * @param ConfigPtr-Pointer to MCU driver configuration set.
 * @return Std_ReturnType
 * @retval E_OK Command has been accepted.
 * @retval E_NOT_OK Command has not been accepted.
 */
/* PRQA S 1505 1 #KQR001505 */
FUNC(Std_ReturnType, MCU_CODE) Mcu_DistributePllClock(VAR(void, AUTOMATIC))
{
    Std_ReturnType status = (Std_ReturnType)E_NOT_OK;
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Mcu_ConfigPtr)
    {
        Mcu_ReportDetError(MCU_DISTRIBUTEPLLCLOCK_ID, MCU_E_UNINIT);
    }
    else if (NULL_PTR == Mcu_ConfigPtr->ClockConfigPtr)
    {
        Mcu_ReportDetError(MCU_DISTRIBUTEPLLCLOCK_ID, MCU_E_PARAM_POINTER);
    }
    else if (Mcu_CurrentClockIndex >= MCU_MAX_CLOCKCONFIGS)
    {
        Mcu_ReportDetError(MCU_DISTRIBUTEPLLCLOCK_ID, MCU_E_PARAM_CLOCK);
    }
    else
    {
#endif
        /* PRQA S 0488 1 #KQR000488 */
        const Mcu_ClockConfigType *clockConfig = *(Mcu_ConfigPtr->ClockConfigPtr) + Mcu_CurrentClockIndex;
        /* Check if the PLL is locked. */
        /* @implements #SWS_Mcu_00142 */
        if (MCU_PLL_LOCKED == Mcu_Im_GetPllStatus())
        {
            Mcu_Im_DistributePllClock(clockConfig);
            status = (Std_ReturnType)E_OK;
        }
        else
        {
            /* @implements #SWS_Mcu_00122 */
#if (MCU_DEV_ERROR_DETECT == STD_ON)
            (void)Mcu_ReportDetError(MCU_DISTRIBUTEPLLCLOCK_ID, MCU_E_PLL_NOT_LOCKED);
#endif
        }
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    }
#endif
    return (Std_ReturnType)status;
}
#endif
#endif

/**
 * @brief This function returns the lock status of the PLL.
 * @details The user takes care that the PLL is locked by executing Mcu_GetPllStatus. If the MCU_NO_PLL is TRUE the
 * MCU_GetPllStatus has to return MCU_PLL_STATUS_UNDEFINED. It will also return MCU_PLL_STATUS_UNDEFINED if the driver
 * state was invalid
 *
 * Service name: Mcu_GetPllStatus
 * Syntax: Mcu_PllStatusType Mcu_GetPllStatus (void)
 * Service ID[hex]: 0x04
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * @implements #SWS_Mcu_00157,#SWS_Mcu_00008,#SWS_Mcu_00132,#SWS_Mcu_00206
 * @param None
 * @return Provides the lock status of the PLL.
 * @retval MCU_PLL_STATUS_UNDEFINED    PLL Status is unknown.
 * @retval MCU_PLL_LOCKED              PLL is locked.
 * @retval MCU_PLL_UNLOCKED            PLL is unlocked.
 */
/* PRQA S 1505 1 #KQR001505 */
FUNC(Mcu_PllStatusType, MCU_CODE) Mcu_GetPllStatus(VAR(void, AUTOMATIC))
{
    /* @implements #SWS_Mcu_00206 */
#if (MCU_NO_PLL == STD_ON)
    Mcu_PllStatusType status = MCU_PLL_STATUS_UNDEFINED;
#else
    Mcu_PllStatusType status;
#endif

#if (MCU_DEV_ERROR_DETECT == STD_ON)
    /* @implements #SWS_Mcu_00132 */
    if (NULL_PTR == Mcu_ConfigPtr)
    {
        (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_GETPLLSTATUS_ID, MCU_E_UNINIT);
        status = MCU_PLL_STATUS_UNDEFINED;
    }
    else
    {
#endif

#if (MCU_NO_PLL == STD_OFF)
        /* @implements #SWS_Mcu_00008 */
        status = Mcu_Im_GetPllStatus();
#endif

#if (MCU_DEV_ERROR_DETECT == STD_ON)
    }
#endif
    /* @implements #SWS_Mcu_00230 */
    return (Mcu_PllStatusType)status;
}

/**
 * @brief The service reads the reset type from the hardware, if supported.
 * @details This routine returns the Reset reason that is read from the hardware.
 *
 * Service name: Mcu_GetResetReason
 * Syntax: Mcu_ResetType Mcu_GetResetReason (void)
 * Service ID[hex]: 0x05
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * @implements #SWS_Mcu_00158,#SWS_Mcu_00005,#SWS_Mcu_00133
 * @param None
 * @return Mcu_ResetType
 * @retval MCU_WATCHDOG_RESET Watchdog reset.
 * @retval MCU_RTC_ALARM_RESET RTC alarm reset.
 * @retval MCU_WKPPIN_RESET WakeUp pin reset.
 * @retval MCU_BOR_RESET Low-Voltage Detect Reset or High-Voltage Detect Reset.
 * @retval MCU_SW_RESET Software reset.
 * @retval MCU_POWER_ON_RESET Power-on reset.
 * @retval MCU_NRST_RESET NRST reset.
 * @retval MCU_MULTIPLE_RESET_REASON More than one reset events are logged except"Power on event"
 * @retval MCU_NO_RESET_REASON No reset reason found
 * @retval MCU_RESET_UNDEFINED Undefined reset source
 */
FUNC(Mcu_ResetType, MCU_CODE) Mcu_GetResetReason(VAR(void, AUTOMATIC))
{
    Mcu_ResetType resetReason;

#if (MCU_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Mcu_ConfigPtr)
    {
        /* @implements #SWS_Mcu_00133 */
        (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_GETRESETREASON_ID, MCU_E_UNINIT);
        resetReason = MCU_RESET_UNDEFINED;
    }
    else
    {
#endif
        /* @implements #SWS_Mcu_00005 */
        resetReason = (Mcu_ResetType)Mcu_Im_GetResetReason();
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    }
#endif
    return (Mcu_ResetType)resetReason;
}

/**
 * @brief The service reads the reset type from the hardware register, if supported
 * @details This routine returns the Raw Reset value that is read from the hardware.
 *
 * Service name: Mcu_GetResetRawValue
 * Syntax: Mcu_RawResetType Mcu_GetResetRawValue (void)
 * Service ID[hex]: 0x06
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * @implements #SWS_Mcu_00159,#SWS_Mcu_00135,#SWS_Mcu_00006
 * @param None
 * @return Mcu_RawResetType
 * @retval Code of the Raw reset value
 * bit30: Reset caused by the watchdog timer
 * bit29: Reset caused by the RTC
 * bit28: Reset caused by the wake up pin
 * bit26: Reset caused by the brown out reset
 * bit25: Reset caused by the software reset
 * bit24: Reset caused by the power on reset
 * bit23: Reset caused by the external reset pin
 *
 * bit11: wake up by WKUP 12
 * bit10: wake up by WKUP 11
 * bit9: wake up by WKUP 10
 * bit8: wake up by WKUP 9
 * bit7: wake up by WKUP 8
 * bit6: wake up by WKUP 7
 * bit5: wake up by WKUP 6
 * bit4: wake up by WKUP 5
 * bit3: wake up by WKUP 4
 * bit2: wake up by WKUP 3
 * bit1: wake up by WKUP 2
 * bit0: wake up by WKUP 1
 */
FUNC(Mcu_RawResetType, MCU_CODE) Mcu_GetResetRawValue(VAR(void, AUTOMATIC))
{
    Mcu_RawResetType rawResetValue;
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    /* @implements #SWS_Mcu_00135 */
    if (NULL_PTR == Mcu_ConfigPtr)
    {
        (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_GETRESETRAWVALUE_ID, MCU_E_UNINIT);
        rawResetValue = 0x12345678U;
    }
    else
    {
#endif
        /* @implements #SWS_Mcu_00006 */
        rawResetValue = (Mcu_RawResetType)Mcu_Im_GetResetRawValue();
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    }
#endif
    return rawResetValue;
}

#if (MCU_PERFORM_RESET_API == STD_ON)
/**
 * @brief The service performs a micro-controller reset.
 * @details This function performs a micro-controller reset by using the hardware feature of the micro-controller. In
 * case the function returns, the user must reset the platform using an alternate reset mechanism
 *
 * Service name: Mcu_PerformReset
 * Syntax: void Mcu_PerformReset (void)
 * Service ID[hex]: 0x07
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * @implements #SWS_Mcu_00160,#SWS_Mcu_00143,#SWS_Mcu_00144,SWS_Mcu_00145,SWS_Mcu_00146
 * @param None
 * @return void
 * @retval void
 */
FUNC(void, MCU_CODE) Mcu_PerformReset(VAR(void, AUTOMATIC))
{
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    /* @implements #SWS_Mcu_00145 */
    if (NULL_PTR == Mcu_ConfigPtr)
    {
        Mcu_ReportDetError(MCU_PERFORMRESET_ID, MCU_E_UNINIT);
    }
    else
    {
#endif
        /* @implements #SWS_Mcu_00143,#SWS_Mcu_00144 */
        Mcu_Im_Reset();
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}
#endif

/**
 * @brief This function sets the MCU power mode.
 * @details This function activates MCU power mode from config structure selected by McuMode parameter. If the driver
 * state is invalid or McuMode is not in range the function will skip changing the mcu mode.
 *
 * Service name: Mcu_SetMode
 * Syntax: void Mcu_SetMode (Mcu_ModeType McuMode)
 * Service ID[hex]: 0x08
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * @implements #SWS_Mcu_00161,#SWS_Mcu_00147,#SWS_Mcu_00148
 * @param  McuMode-Set different MCU power modes configured in the configuration set
 * @return void
 * @retval void
 */
FUNC(void, MCU_CODE) Mcu_SetMode(VAR(Mcu_ModeType, AUTOMATIC) McuMode)
{
    const Mcu_PowerConfigType *powerModeConfig;

#if (MCU_DEV_ERROR_DETECT == STD_ON)
    /* @implements #SWS_Mcu_00148 */
    if (NULL_PTR == Mcu_ConfigPtr)
    {
        Mcu_ReportDetError(MCU_SETMODE_ID, MCU_E_UNINIT);
    }
    else if ((McuMode >= MCU_MAX_SUPPORTED_MODE) || (NULL_PTR == Mcu_ConfigPtr->HwConfigPtr) ||
             (NULL_PTR == Mcu_ConfigPtr->HwConfigPtr->PMConfig))
    {
        /* BugFix: #238. Parameter Validation */
        Mcu_ReportDetError(MCU_SETMODE_ID, MCU_E_PARAM_MODE);
    }
    else
    {
#endif
        /* @implements #SWS_Mcu_00147 */
        powerModeConfig = &Mcu_ConfigPtr->HwConfigPtr->PMConfig[McuMode];
        /* PRQA S 1863 1 #KQR001863 */
        if (Mcu_Im_SetMode(powerModeConfig) == 0)
        {
#if (MCU_DEV_ERROR_DETECT == STD_ON)
            Mcu_ReportDetError(MCU_SETMODE_ID, MCU_E_PARAM_MODE);
#endif
        }
        else
        {
            /* Do Nothing */
        }
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}

#if (MCU_VERSION_INFO_API == STD_ON)
/**
 * @brief This service returns the version information of this module.
 * @details This function returns the vendor id, module id, major, minor and patch version.
 *
 * Service name: Mcu_GetVersionInfo
 * Syntax: void Mcu_GetVersionInfo (Std_VersionInfoType* versioninfo)
 * Service ID[hex]: 0x09
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * @implements #SWS_Mcu_00162
 * @param versioninfo Pointer to where to store the version information of this module.
 * @return None
 * @retval None
 */
FUNC(void, MCU_CODE) Mcu_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == versioninfo)
    {
        Mcu_ReportDetError(MCU_GETVERSIONINFO_ID, MCU_E_PARAM_POINTER);
    }
    else
    {
#endif
        (versioninfo)->vendorID         = (uint16)MCU_VENDOR_ID;
        (versioninfo)->moduleID         = (uint16)MCU_MODULE_ID;
        (versioninfo)->sw_major_version = (uint8)MCU_SW_MAJOR_VERSION;
        (versioninfo)->sw_minor_version = (uint8)MCU_SW_MINOR_VERSION;
        (versioninfo)->sw_patch_version = (uint8)MCU_SW_PATCH_VERSION;

#if (MCU_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}
#endif

#if (MCU_GET_RAM_STATE_API == STD_ON)
/**
 * @brief This service provides the actual status of the micro-controller Ram.
 * @details This function returns if the Ram Status is valid after a reset. The report is get from STCU as a result of
 * MBIST (Memory Built-In Self Tests).
 *
 * Service name: Mcu_GetRamState
 * Syntax: Mcu_RamStateType Mcu_GetRamState (void)
 * Service ID[hex]: 0x0a
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * @implements #SWS_Mcu_00207,#SWS_Mcu_00208,#SWS_Mcu_00209
 * @param None
 * @return Mcu_RamStateType
 * @retval MCU_RAMSTATE_INVALID Ram state is not valid or unknown (default), or the driver state does not allow this
 * call.
 * @retval MCU_RAMSTATE_VALID Ram state is valid.
 */
FUNC(Mcu_RamStateType, MCU_CODE) Mcu_GetRamState(void)
{
    /* Return value of this function. */
    VAR(Mcu_RamStateType, AUTOMATIC) ramState = MCU_RAMSTATE_INVALID;

#if (MCU_DEV_ERROR_DETECT == STD_ON)
    /* @implements #SWS_Mcu_00208 */
    if (NULL_PTR == Mcu_ConfigPtr)
    {
        Mcu_ReportDetError(MCU_GETRAMSTATE_ID, MCU_E_UNINIT);
    }
    else
    {
#endif
        /* Not Supported */
        ramState = MCU_RAMSTATE_INVALID;
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    }
#endif
    return (Mcu_RamStateType)ramState;
}
#endif

#if (MCU_IO_LATCH_STATE_IN_STANDBY == STD_ON)
/**
 * @brief Set io latch state
 * @details
 *
 * Service name: Mcu_LatchIO
 * Syntax: void Mcu_LatchIO (boolean Enabled)
 * Service ID[hex]:
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * @implements
 * @param Enabled TRUE or FALSE
 * @return None
 * @retval None
 */
FUNC(void, MCU_CODE) Mcu_LatchIO(VAR(boolean, AUTOMATIC) Enabled)
{
    /*Set IO latch*/
    Mcu_Im_LatchIO(Enabled);
}
#endif

/**
 * @brief Attach configuration to MCU driver without hardware initialization
 * @details
 *
 * Service name: Mcu_AttachConfig
 * Syntax: void Mcu_AttachConfig(const Mcu_ConfigType *ConfigPtr)
 * Service ID[hex]:
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * @implements
 * @param ConfigPtr Pointer to MCU driver configuration set
 * @return None
 */
void Mcu_AttachConfig(const Mcu_ConfigType *ConfigPtr)
{
    Mcu_ConfigPtr = ConfigPtr;
}

/**
 * @brief Perform Mcu SetBGMR
 *
 */
FUNC(void, MCU_CODE) Mcu_SetBGMR(void)
{
    Mcu_Im_SetBGMR();
}

FUNC(void, MCU_CODE) Mcu_Delay(uint32 DelayTime)
{
    Mcu_Im_Delay(DelayTime);
}
/* EOF */
