/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Mcu_Types.h
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
#ifndef MCU_TYPES_H
#define MCU_TYPES_H

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
/*PRQA S 0635 EOF #KQR000635 */
/*PRQA S 3630 EOF #KQR003630 */
/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "Mcu_Cfg.h"
/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/

/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/

/**
 * @brief
 * @details
 *
 */
typedef struct
{
    /* PCLK_CTL0 configuration */
    uint32 PclkCtrlGroup_0;
    /* PCLK_CTL1 configuration */
    uint32 PclkCtrlGroup_1;
    /* PCLK_CTL2 configuration */
    uint32 PclkCtrlGroup_2;
    /* PCLK_CTL3 configuration */
    uint32 PclkCtrlGroup_3;
    /* PCLK_CTL4 configuration */
    uint32 PclkCtrlGroup_4;
} Peripheral_ClockEnableType;

typedef enum
{
    LFCLK_INPUT_INTLF,
    LFCLK_INPUT_EXTLF
} LFclk_SourceType;

typedef enum
{
    HFCLK_SOURCE_INTHF = 0U,
    HFCLK_SOURCE_EXTHF = 2U,
    HFCLK_SOURCE_PLL   = 4U,
} HFclk_SourceType;

typedef enum
{
    /** @brief Internal High-Freq as PLL Source   */
    PLL_SOURCE_INTHF,
    /** @brief External High-Freq as PLL Source   */
    PLL_SOURCE_EXTHF,
} Pll_SourceType;

typedef enum
{
    SCLK_SOURCE_INTHF,
    SCLK_SOURCE_INTLF,
    SCLK_SOURCE_EXTHF,
    SCLK_SOURCE_EXTLF,
    SCLK_SOURCE_PLL,
} Sclk_SourceType;

typedef enum
{
    SCLK_DIVISION_1,
    SCLK_DIVISION_2,
    SCLK_DIVISION_4,
    SCLK_DIVISION_8,
    SCLK_DIVISION_16,
    SCLK_DIVISION_32,
    SCLK_DIVISION_64,
    SCLK_DIVISION_128,
} Sclk_DivisionFactorType;

typedef struct
{
    /** @brief Enable Oscillator */
    boolean Enabled;
    /** @brief Generate Interrupt Call */
    boolean AllowIntr;
    /** @brief Delay Time when Oscillator enabled */
    uint32 Delay;
} Osc_FreqConfigType;

/**
 * @brief Inner high-freq Oscillator Config
 *
 */
typedef Osc_FreqConfigType Osc_InnerHFConfigType;
/**
 * @brief Inner low-freq Oscillator Config
 *
 */
typedef Osc_FreqConfigType Osc_InnerLFConfigType;
/**
 * @brief Outer high-freq Oscillator Config
 *
 */
typedef Osc_FreqConfigType Osc_OuterHFConfigType;
/**
 * @brief Outer low-freq Oscillator Config
 *
 */
typedef Osc_FreqConfigType Osc_OuterLFConfigType;

typedef struct
{
    uint32 OD :2;
    uint32 N  :4;
    uint32 M  :14;
} Pll_CtrlParamType;

typedef struct
{
    Pll_SourceType    ClockSource;
    uint8             Delay;
    boolean           IsClockDivBy2;
    Pll_CtrlParamType Control;
} Pll_ConfigType;

typedef struct
{
    /** @brief  */
    Sclk_SourceType ClockSource;
    /** @brief  */
    Sclk_DivisionFactorType Division;
} Sclk_ConfigType;

/**
 * @brief High- Speed Peripheral Clock Configuration
 *
 */
typedef struct
{
    boolean          Enabled;
    HFclk_SourceType ClockSource;
    uint8            Division;
} HSPclk_ConfigType;

/**
 * @brief Low- Speed Peripheral Clock Configuration
 *
 */
typedef struct
{
    boolean          Enabled;
    LFclk_SourceType ClockSource;
    uint8            Division;
} LSPclk_ConfigType;

/**
 * @brief MCU sleep type
 */
typedef enum
{
    MCU_SLEEP_NORMAL,
    MCU_SLEEP_STANDBY,
    MCU_SLEEP_STOP0
} Mcu_SleepConfigType;

/**
 * @brief MCU wake up edge
 */
typedef enum
{
    MCU_WAKEUP_EDGE_RISE,
    MCU_WAKEUP_EDGE_FALL,
} Mcu_WakeupEdgeType;

/**
 *@brief mcu wakeup source
 */
typedef enum
{
    MCU_WKUP1 = 0U,
    MCU_WKUP2 = 1U,
    MCU_WKUP3 = 2U,
    MCU_WKUP4 = 3U,
    MCU_WKUP5 = 4U,
    MCU_WKUP6 = 5U,
    MCU_WKUP7 = 6U,
    MCU_WKUP8 = 7U,
    MCU_WKUP9 = 8U,
    MCU_WKUP10 = 9U,
    MCU_WKUP11 = 10U,
    MCU_WKUP12 = 11U,
    MCU_WKUP_MAX
} Mcu_WkupIndexType;

/**
 * @brief Wake up pin configuration
 */
typedef struct
{
    Mcu_WkupIndexType  WakeupIndex;
    Mcu_WakeupEdgeType WakeupEdge;
    /** @brief Fix level of wake up pin or not before go to mode
     *  true -- Fix level of wake up pin before go to mode
     *  false -- Don't fix level of wake up pin before go to mode
     *
     * @attention If set WakeupFixLvEnable to true,
     *  function will pull up or down wake up pin according to wake up edge before go to mode.
     *  EXAMPLE:
     *  WakeupEdge -- HLI_MCU_WAKEUP_EDGE_FALL
     *  WakeupFixLvEnable -- true
     *  function will pull down wake up pin before go to mode.
     *
     *  WakeupFixLvEnable -- false
     *  function will not pull up or pull down wake up pin before go to mode.
     */
    boolean WakeupFixLvEnable;
} Mcu_WakeupPinConfig;

/**
 * @brief Wake up configuration
 */
typedef struct
{
    /**
     * @brief Number of wake up pin
     */
    uint32 WakeupNumber;
    /**
     * @brief Pointer to wake up pin configuration
     */
    Mcu_WakeupPinConfig *WakeupPinConfig;
} Mcu_WakeupConfig;

/**
 * @brief
 * @details
 *
 */
typedef struct
{
    /**
     * @brief EN state of WKUP pin wake up MCU
     */
    boolean Mcu_PinWkupEnableSta;
    /**
     * @brief WKUP pin index
     */
    Mcu_WakeupConfig *Mcu_WkupConfig;
    /**
     * @brief EN state of T0
     */
    boolean Mcu_T0WkupEnableSta;
    /**
     * @brief Time of T0, in ms
     */
    uint32 Mcu_T0WkupTime;

    /**
     * @brief normal\standby\stop0
     */
    Mcu_SleepConfigType Mcu_SleepType;
} Mcu_PowerConfigType;

/**
 * @brief Mcu System Parameter (Cache, Ecc) Configuration
 * @details
 *
 */
typedef struct
{
    /** @brief Enable Cache */
    uint32 EnableCache :1;
    /** @brief Enable Ram Ecc Functionality */
    uint32 EnableRamEcc :1;
    /** @brief Enable Cache ECC Interrupt */
    uint32 EnableCacheEccIntr :1;
    /** @brief Enable RAM ECC Interrupt */
    uint32 EnableRamEccIntr :1;
    /** @brief Enable Flash ECC Interrupt */
    uint32 EnableFlashEccIntr :1;
} Mcu_SystemConfigType;

/**
 * @brief Mcu driver configuration structure.
 * @details Configuration for Power Management and System Management.
 *
 */
typedef struct
{
    /** @brief Configuration for PMC (Power Management Control) hardware IP. */
    const Mcu_PowerConfigType *PMConfig;
    /** @brief Configuration for SMC (System Management Control) hardware IP. */
    const Mcu_SystemConfigType *SMConfig;
} Mcu_HwConfigType;

#if (MCU_INIT_CLOCK == STD_ON)

/**
 * @brief Definition of a Clock configuration.
 * @details This configuration is transmitted as parameter to
 * Mcu_Im_InitClock() API. Used by "Mcu_ConfigType" structure.
 *
 */
typedef struct
{
    /** @brief  Internal Low-Freq Clock Config */
    const Osc_InnerLFConfigType InnerLFConfig;
    /** @brief  Internal High-Freq Clock Config */
    const Osc_InnerHFConfigType InnerHFConfig;
    /** @brief  External Low-Freq Clock Config */
    const Osc_OuterLFConfigType OuterLFConfig;
    /** @brief  External High-Freq Clock Config */
    const Osc_OuterHFConfigType OuterHFConfig;
    /** @brief  System Clock Config */
    const Sclk_ConfigType SclkConfig;
#if (MCU_NO_PLL == STD_OFF)
    /** @brief  PLL Clock Config */
    const Pll_ConfigType PllConfig;
#endif
    /** @brief Peripheral High-Freq  Clock */
    const HSPclk_ConfigType HSPclkConfig;
    /** @brief Peripheral Low-Freq  Clock */
    const LSPclk_ConfigType LSPclkConfig;
    /** @brief Module Clock Configs */
    const Peripheral_ClockEnableType PclkEnConfig;
} Mcu_ClockConfigType;
#endif
/******************************************************************************
 **                        Export Variables
 ******************************************************************************/

/******************************************************************************
 **                        Export Functions
 ******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif
/* EOF */
