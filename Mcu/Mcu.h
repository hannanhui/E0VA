/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Mcu.h
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
#ifndef MCU_H
#define MCU_H

#ifdef __cplusplus
extern "C" {
#endif

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
/* PRQA S 3205 EOF #KQR003205 */
/* PRQA S 3630 EOF #KQR003630 */
/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "Std_Types.h"
#include "Mcu_Cfg.h"
#include "Mcu_Types.h"

/******************************************************************************
 **                        File Version Check
 ******************************************************************************/
#define MCU_VENDOR_ID   (0xCCU)
#define MCU_MODULE_ID   (101U)
#define MCU_INSTANCE_ID (0U)

#define MCU_SW_MAJOR_VERSION (1U)
#define MCU_SW_MINOR_VERSION (0U)
#define MCU_SW_PATCH_VERSION (1U)
/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/
/**
 * @brief API service ID for Mcu_Init function.
 * @details Parameters used when raising an error or exception.
 *
 * @implements
 */
#define MCU_INIT_ID ((uint8)0x00U)

/**
 * @brief API service ID for Mcu_InitRamSection function.
 * @details Parameters used when raising an error or exception.
 *
 * @implements
 */
#define MCU_INITRAMSECTION_ID ((uint8)0x01U)

/**
 * @brief API service ID for Mcu_InitClock function.
 * @details Parameters used when raising an error or exception.
 *
 * @implements
 */
#define MCU_INITCLOCK_ID ((uint8)0x02U)

/**
 * @brief API service ID for Mcu_DistributePllClock function.
 * @details Parameters used when raising an error or exception.
 *
 * @implements
 */
#define MCU_DISTRIBUTEPLLCLOCK_ID ((uint8)0x03U)

/**
 * @brief API service ID for Mcu_GetPllStatus function.
 * @details Parameters used when raising an error or exception.
 *
 * @implements
 */
#define MCU_GETPLLSTATUS_ID ((uint8)0x04U)

/**
 * @brief API service ID for Mcu_GetResetReason function.
 * @details Parameters used when raising an error or exception.
 *
 * @implements
 */
#define MCU_GETRESETREASON_ID ((uint8)0x05U)

/**
 * @brief API service ID for Mcu_GetResetRawValue function.
 * @details Parameters used when raising an error or exception.
 *
 * @implements
 */
#define MCU_GETRESETRAWVALUE_ID ((uint8)0x06U)

/**
 * @brief API service ID for Mcu_PerformReset function.
 * @details Parameters used when raising an error or exception.
 *
 * @implements
 */
#define MCU_PERFORMRESET_ID ((uint8)0x07U)

/**
 * @brief API service ID for Mcu_SetMode function.
 * @details Parameters used when raising an error or exception.
 *
 * @implements
 */
#define MCU_SETMODE_ID ((uint8)0x08U)

/**
 * @brief API service ID for Mcu_GetVersionInfo function.
 * @details Parameters used when raising an error or exception.
 *
 * @implements
 */
#define MCU_GETVERSIONINFO_ID ((uint8)0x09U)

/**
 * @brief API service ID for Mcu_GetRamState function.
 * @details Parameters used when raising an error or exception.
 *
 * @implements
 */
#define MCU_GETRAMSTATE_ID ((uint8)0x0AU)

/**
 * @brief Default error values are of type uint8.
 * The following errors and exceptions shall be detectable by
 * the MCU module depending on its build version (default/production mode).
 */
#define MCU_E_PARAM_CONFIG        ((uint8)0x0AU)
#define MCU_E_PARAM_CLOCK         ((uint8)0x0BU)
#define MCU_E_PARAM_MODE          ((uint8)0x0CU)
#define MCU_E_PARAM_RAMSECTION    ((uint8)0x0DU)
#define MCU_E_PLL_NOT_LOCKED      ((uint8)0x0EU)
#define MCU_E_UNINIT              ((uint8)0x0FU)
#define MCU_E_PARAM_POINTER       ((uint8)0x10U)
#define MCU_E_INIT_FAILED         ((uint8)0x11U)
#define MCU_E_ALREADY_INITIALIZED ((uint8)0x13U)
/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/
#if (MCU_INIT_CLOCK == STD_ON)
/**
 * @brief Defines the identification (ID) for clock setting
 * configured via the configuration structure.
 * @details The type shall be uint8, uint16 or uint32, depending on uC
 * platform.
 *
 * @implements #SWS_Mcu_00251,#SWS_Mcu_00232,#SWS_Mcu_00233
 */
typedef uint32 Mcu_ClockType;
#endif

/**
 * @brief The Mcu_ModeType specifies the identification (ID) for a
 * MCU mode, configured via configuration structure.
 * @details The type shall be uint8, uint16 or uint32.
 *
 * @implements #SWS_Mcu_00254,#SWS_Mcu_00237,#SWS_Mcu_00238
 */
typedef uint32 Mcu_ModeType;

/**
 * @brief The Mcu_RamSectionType specifies the identification (ID)
 * for a RAM section, configured via the configuration structure. The type shall
 * be uint8, uint16 or uint32, based on best performance.
 *
 * @implements #SWS_Mcu_00255,#SWS_Mcu_00239,#SWS_Mcu_00240
 */
typedef uint32 Mcu_RamSectionType;

/**
 * @brief The type Mcu_RawResetType specifies the reset reason in raw
 * register format, read from a reset status register.
 * @details The type shall be uint8, uint16 or uint32 based on best
 * performance.
 *
 * @implements #SWS_Mcu_00253,#SWS_Mcu_00235,#SWS_Mcu_00236
 *
 */
typedef uint32 Mcu_RawResetType;

#if (MCU_INIT_CLOCK == STD_ON)
/**
 * @brief Mcu_ClockNotificationType
 * @details Clock failure notification. Enable/disable clock failure interrupt generated by the MCU.
 */
typedef enum
{
    /** @brief Disable clock notification. */
    MCU_CLK_NOTIF_DISABLE = 0x5AU,
    /** @brief Enable clock notification.  */
    MCU_CLK_NOTIF_ENABLE = 0xA5U
} Mcu_ClockNotificationType;
#endif

/**
 * @brief The type Mcu_ResetType, represents the different reset that
 * a specified MCU can have.
 * @details The MCU module shall provide at least the values
 * MCU_POWER_ON_RESET and MCU_RESET_UNDEFINED for the enumeration Mcu_ResetType.
 *
 * @implements #SWS_Mcu_00252,#SWS_Mcu_00234,#SWS_Mcu_00134
 */
typedef enum
{
    /** @brief Watchdog reset. */
    MCU_WATCHDOG_RESET,
    /** @brief RTC alarm reset. */
    MCU_RTC_ALARM_RESET,
    /** @brief WakeUp pin reset. */
    MCU_WKPPIN_RESET,
    /** @brief Low-Voltage Detect Reset or High-Voltage Detect Reset. */
    MCU_BOR_RESET,
    /** @brief Software reset. */
    MCU_SW_RESET,
    /** @brief POR reset. */
    MCU_POWER_ON_RESET,
    /** @brief NRST reset. */
    MCU_NRST_RESET,
    /** @brief More than one reset events are logged except"Power on event" */
    MCU_MULTIPLE_RESET_REASON,
    /** @brief No reset reason found */
    MCU_NO_RESET_REASON,
    /** @brief Undefined reset source. */
    MCU_RESET_UNDEFINED
} Mcu_ResetType;

/**
 * @brief Type of the return value of the function Mcu_GetPllStatus.
 * @details The type of Mcu_PllStatusType is an enumeration with the
 * following values: MCU_PLL_LOCKED, MCU_PLL_UNLOCKED, MCU_PLL_STATUS_UNDEFINED.
 *
 * @implements #SWS_Mcu_00250,#SWS_Mcu_00231
 */
typedef enum
{
    /** @brief PLL is unlocked. */
    MCU_PLL_UNLOCKED,
    /** @brief PLL is locked. */
    MCU_PLL_LOCKED,
    /** @brief PLL Status is unknown. */
    MCU_PLL_STATUS_UNDEFINED
} Mcu_PllStatusType;

/**
 * @brief Definition of a RAM section within the configuration
 * structure. The definitions for each RAM section within the structure
 * Mcu_ConfigType shall contain:
 *                   - RAM section base address
 *                   - Section size
 *                   - Data pre-setting to be initialized
 */
typedef struct
{
    /** @brief The ID for Ram Sector configuration. */
    Mcu_RamSectionType Mcu_RamSectorId;
    /** @brief RAM section base address. */
    uint64 *Mcu_RamBaseAddress;
    /** @brief RAM section size. */
    uint32 Mcu_RamSize;
    /** @brief RAM default value for initialization. */
    uint64 Mcu_RamDefaultValue;
    /** @brief RAM section write size. */
    uint32 Mcu_RamWriteSize;
} Mcu_RamConfigType;

#if (MCU_GET_RAM_STATE_API == STD_ON)
/**
 * @brief Ram State of the micro controller.
 * @details This is the Ram State data type returned by the function
 * Mcu_GetRamState() of the Mcu module.
 *
 * @implements #SWS_Mcu_00256
 */
typedef enum
{
    /** @brief RAM content is not valid or unknown (default). */
    MCU_RAMSTATE_INVALID,
    /** @brief RAM content is valid. */
    MCU_RAMSTATE_VALID
} Mcu_RamStateType;
#endif

/**
 * @brief Initialization data for the MCU driver.
 * @details A pointer to such a structure is provided to the MCU
 * initialization routines for configuration.
 *
 * @implements #SWS_Mcu_00249
 */
typedef struct
{
#if (MCU_INIT_CLOCK == STD_ON)
    /** @brief Clock source failure notification enable configuration. */
    Mcu_ClockNotificationType ClkSrcFailureNotification;
#endif
    /** @brief number of RAM sections. */
    uint8 NumOfRamConfigs;
#if (MCU_INIT_CLOCK == STD_ON)
    /** @brief number of MCU clock configurations. */
    uint8 NumOfClkConfigs;
#endif
    /** @brief ram data configuration. */
    /* PRQA S 1037 EOF #KQR001037 */
    const Mcu_RamConfigType (*RamConfigPtr)[MCU_MAX_RAMCONFIGS];
#if (MCU_INIT_CLOCK == STD_ON)
    /** @brief clock information configuration. */
    const Mcu_ClockConfigType (*ClockConfigPtr)[MCU_MAX_CLOCKCONFIGS];
#endif
    /** @brief data generic configuration. */
    const Mcu_HwConfigType *HwConfigPtr;
} Mcu_ConfigType;

/******************************************************************************
 **                        Export Variables
 ******************************************************************************/

/******************************************************************************
 **                        Export Functions
 ******************************************************************************/
/******************************************************************************
 * Function Name   : Mcu_Init
 *
 * Service ID   : 0x00
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Non Reentrant
 *
 * Parameters(in)   : ConfigPtr
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : None
 *
 * Description   :This service initializes the MCU driver.
 *
 ******************************************************************************/
FUNC(void, MCU_CODE) Mcu_Init(const Mcu_ConfigType *ConfigPtr);

/******************************************************************************
 * Function Name   : Mcu_InitRamSection
 *
 * Service ID   : 0x01
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Non Reentrant
 *
 * Parameters(in)   : RamSection
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : Std_ReturnType: E_OK: command has been accepted
 *                                  E_NOT_OK: command has not been accepted e.g.
 *due to parameter error
 *
 * Description   : This service initializes the RAM section wise.
 *
 ******************************************************************************/
FUNC(Std_ReturnType, MCU_CODE) Mcu_InitRamSection(Mcu_RamSectionType RamSection);

/******************************************************************************
 * Function Name   : Mcu_InitClock
 *
 * Service ID   : 0x02
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Non Reentrant
 *
 * Parameters(in)   : ClockSetting
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : Std_ReturnType: E_OK: command has been accepted
 *                                  E_NOT_OK: Command has not been accepted
 *
 * Description   : This service initializes the PLL and other MCU specific clock
 *options.
 *
 ******************************************************************************/
#if (MCU_INIT_CLOCK == STD_ON)
FUNC(Std_ReturnType, MCU_CODE) Mcu_InitClock(Mcu_ClockType ClockSetting);
#endif

/******************************************************************************
 * Function Name   : Mcu_DistributePllClock
 *
 * Service ID   : 0x03
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Non Reentrant
 *
 * Parameters(in)   : None
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : Std_ReturnType: E_OK: command has been accepted
 *                                  E_NOT_OK: Command has not been accepted
 *
 * Description   : This service activates the PLL clock to the MCU clock
 *distribution.
 *
 ******************************************************************************/
#if (MCU_INIT_CLOCK == STD_ON)
#if (MCU_NO_PLL == STD_OFF)
FUNC(Std_ReturnType, MCU_CODE) Mcu_DistributePllClock(void);
#endif
#endif

/******************************************************************************
 * Function Name   : Mcu_GetPllStatus
 *
 * Service ID   : 0x04
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Reentrant
 *
 * Parameters(in)   : None
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : Mcu_PllStatusType: PLL Status
 *
 * Description   : This service provides the lock status of the PLL.
 *
 ******************************************************************************/
FUNC(Mcu_PllStatusType, MCU_CODE) Mcu_GetPllStatus(void);

/******************************************************************************
 * Function Name   : Mcu_GetResetReason
 *
 * Service ID   : 0x05
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Reentrant
 *
 * Parameters(in)   : None
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : Mcu_ResetType
 *
 * Description   : The service reads the reset type from the hardware, if supported.
 *
 ******************************************************************************/
FUNC(Mcu_ResetType, MCU_CODE) Mcu_GetResetReason(void);

/******************************************************************************
 * Function Name   : Mcu_GetResetRawValue
 *
 * Service ID   : 0x06
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Reentrant
 *
 * Parameters(in)   : None
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : Mcu_RawResetType
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
 *
 * Description   : The service reads the reset type from the hardware register, if supported
 *
 ******************************************************************************/
FUNC(Mcu_RawResetType, MCU_CODE) Mcu_GetResetRawValue(void);

/******************************************************************************
 * Function Name   : Mcu_PerformReset
 *
 * Service ID   : 0x07
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Non Reentrant
 *
 * Parameters(in)   : None
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : None
 *
 * Description   : The service performs a micro-controller reset.
 *
 ******************************************************************************/
#if MCU_PERFORM_RESET_API == STD_ON
FUNC(void, MCU_CODE) Mcu_PerformReset(void);
#endif

/******************************************************************************
 * Function Name   : Mcu_SetMode
 *
 * Service ID   : 0x08
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Non Reentrant
 *
 * Parameters(in)   : McuMode
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : None
 *
 * Description   : This service activates the MCU power modes.
 *
 ******************************************************************************/
FUNC(void, MCU_CODE) Mcu_SetMode(Mcu_ModeType McuMode);

/******************************************************************************
 * Function Name   : Mcu_GetVersionInfo
 *
 * Service ID   : 0x09
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Reentrant
 *
 * Parameters(in)   : McuMode
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : versioninfo
 *
 * Return value   : None
 *
 * Description   : This service returns the version information of this module.
 *
 ******************************************************************************/
#if (MCU_VERSION_INFO_API == STD_ON)
FUNC(void, MCU_CODE) Mcu_GetVersionInfo(Std_VersionInfoType *versioninfo);
#endif

/******************************************************************************
 * Function Name   : Mcu_GetRamState
 *
 * Service ID   : 0x0a
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Reentrant
 *
 * Parameters(in)   : None
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : Mcu_RamStateType
 *
 * Description   : This service provides the actual status of the micro-controller Ram.
 *
 ******************************************************************************/
#if (MCU_GET_RAM_STATE_API == STD_ON)
FUNC(Mcu_RamStateType, MCU_CODE) Mcu_GetRamState(void);
#endif

/******************************************************************************
 * Function Name   : Mcu_LatchIO
 *
 * Service ID   :
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Non Reentrant
 *
 * Parameters(in)   : EnableState
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : None
 *
 * Description   : Set io latch state
 *
 ******************************************************************************/
#if (MCU_IO_LATCH_STATE_IN_STANDBY == STD_ON)
FUNC(void, MCU_CODE) Mcu_LatchIO(VAR(boolean, AUTOMATIC) Enabled);
#endif

/******************************************************************************
 * Function Name   : Mcu_AttachConfig
 *
 * Service ID   :
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Non Reentrant
 *
 * Parameters(in)   : ConfigPtr
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : None
 *
 * Description   : Attach configuration to MCU driver without hardware initialization
 *
 ******************************************************************************/
FUNC(void, MCU_CODE) Mcu_AttachConfig(const Mcu_ConfigType *ConfigPtr);


FUNC(void, MCU_CODE) Mcu_SetBGMR(void);
FUNC(void, MCU_CODE) Mcu_Delay(uint32 DelayTime);
#ifdef __cplusplus
}
#endif

#endif
/* EOF */
