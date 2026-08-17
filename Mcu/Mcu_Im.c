/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Mcu_Im.c
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
/* PRQA S 0303 EOF #KQR000303 */
/* PRQA S 3473 EOF #KQR003473 */
/* PRQA S 4397 EOF #KQR004397 */
/* PRQA S 1484 EOF #KQR001484 */
/* PRQA S 4342 EOF #KQR004342 */
/* PRQA S 4322 EOF #KQR004322 */
/* PRQA S 3006 EOF #KQR003006 */
/* PRQA S 3415 EOF #KQR003415 */
/* PRQA S 1006 EOF #KQR101006 */
/* PRQA S 2814 EOF #KQR002814 */
/* PRQA S 2824 EOF #KQR002824 */
/* PRQA S 2834 EOF #KQR002834 */
/* PRQA S 2844 EOF #KQR002844 */
/* PRQA S 2201 EOF #KQR002201 */
/* PRQA S 4899 EOF #KQR004899 */
/* PRQA S 3383 EOF #KQR003383 */
/* PRQA S 3384 EOF #KQR003384 */
/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "Mcu_Im.h"
#include "kf32a158sf_drv_pclk.h"
#include "kf32a158sf_drv_pm.h"
#include "kf32a158sf_drv_osc.h"
#include "kf32a158sf_drv_rst.h"
#include "kf32a158sf_drv_ecc.h"
#include "kf32a158sf_drv_sysctl.h"
#include "kf32a158sf_drv_flash.h"
#include "kf32a158sf_drv_bkp.h"
#include "kf32a158sf_drv_gpio.h"
#include "kf32a158sf_drv_intr.h"
#include "kf32a158sf_drv_cache.h"
#include "kf32a158sf_drv_gptimer.h"
#include "Reload_Kernel.h"
#include "kf32a158sf_drv_wdt.h"

/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/
#ifdef MCU_INTERNAL_TRACE_LOGGER
#include "kflog.h"
KF_REG_LOG(MCU_HW, KF_LOG_OPT_LINE);
#endif

/**
 * @brief PM_STA0 register reset flag
 * bit30 : Watchdog reset status flag bit
 * bit29 : RTC alarm wake-up flag bit
 * bit28 : External wake up pin wake up event flag bit
 * bit26 : BOR reset status flag bit
 * bit25 : Software reset status flag bit
 * bit24 : Power-on reset flag bit
 * bit23 : External reset pin reset flag bit
 */
#define PM_STA0_RESET_REASON_MASK32 ((uint32)0x77800000U)

/**
 * @brief Wait time for enable external oscillator, in us.
 */
#define EXTERNAL_CLOCK_STARTUP_TIMEOUT ((uint16_t)8000U)

/**
 * The Max number of wake up pin.
 */
#define MCU_MAX_WAKEUP_PIN_NUM (12U)

/**
 * @brief Timeout for enable internal oscillator, in us.
 */
#define INTERNAL_CLOCK_STARTUP_TIMEOUT ((uint16_t)500U)
/**
 * @brief Default bit value of PM_CAL4 register
 */
#define PM_CAL4_DEFAULT_SET_MASK (0x8D00000U)
/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/

/**
 * @brief mcu sleep reduce clock source
 */
typedef enum
{
    MCU_SLEEP_CLK_INTHF,
    MCU_SLEEP_CLK_INTLF,
} Mcu_SleepClockType;

/**
 * @brief wakeup config
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
} Mcu_ModeCfgType;

/**
 * @brief timer config
 */
typedef struct
{
    uint32  ClockSrc;
    uint32  PreScaler;
    uint32  Period;
    uint32  CountMode;
    uint32  Mode;
    boolean UpdateEnableSta;
    uint32  StartStatus;
} Mcu_GTimerStructType;
/******************************************************************************
 **                      Constant Declarations
 ******************************************************************************/
/**
 * @brief mcu wakeup port ptr
 */
/* PRQA S 2203 ++ #KQR002203 */
/* PRQA S 3218 3 #KQR003218 */
static Gpio_RegisterMap_t *const Mcu_Wkp_Port[MCU_MAX_WAKEUP_PIN_NUM] = {
  GPIOC_PTR, GPIOC_PTR, GPIOD_PTR, GPIOG_PTR, GPIOG_PTR, GPIOA_PTR,
  NULL_PTR,  GPIOB_PTR, NULL_PTR,  GPIOD_PTR, GPIOG_PTR, GPIOH_PTR};

/**
 * @brief mcu wakeup pin index
 */
/* PRQA S 3218 3 #KQR003218 */
static const Gpio_PinIndex_t Mcu_Wkp_Pin[MCU_MAX_WAKEUP_PIN_NUM] = {
  GPIO_PIN_INDEX_6, GPIO_PIN_INDEX_0, GPIO_PIN_INDEX_4, GPIO_PIN_INDEX_12, GPIO_PIN_INDEX_13, GPIO_PIN_INDEX_9,
  GPIO_PIN_INDEX_0, GPIO_PIN_INDEX_4, GPIO_PIN_INDEX_0, GPIO_PIN_INDEX_13, GPIO_PIN_INDEX_9,  GPIO_PIN_INDEX_9};
/* PRQA S 2203 -- #KQR002203 */
/******************************************************************************
 **                     Variable Declarations
 ******************************************************************************/

/**
 * @brief Mcu raw reset value
 */
static uint32 Mcu_RawResetValue = 0U;

/**
 * @brief Record config MCU mode or not.
 */
static boolean Mcu_ModeConfiguredStatus = FALSE;

/**
 * @brief Record wake up pin configurations.
 */
static Mcu_WakeupPinConfig Mcu_WakeUpPinCfgRecorder[MCU_MAX_WAKEUP_PIN_NUM] = {0};

/**
 * @brief Record wake up configurations.
 */
static Mcu_WakeupConfig Mcu_WakeUpCfgRecorder = {
  .WakeupPinConfig = Mcu_WakeUpPinCfgRecorder,
};

/**
 * @brief Record MCU mode configuration.
 */
static Mcu_ModeCfgType Mcu_ModeCfgRecorder = {
  .Mcu_WkupConfig = &Mcu_WakeUpCfgRecorder,
};
/******************************************************************************
 **                        Export Variables
 ******************************************************************************/

/******************************************************************************
 **                        Export Functions
 ******************************************************************************/
/* PRQA S 3684 4 #KQR003684 */
/* PRQA S 1510 1 #KQR100022 */
extern uint32 __Stop0_Wakeup_Vector[];
/* PRQA S 1752 1 #KQR001752 */
extern uint32 _start[];
extern void   Mcu_Stop0WakeUpReInit(void);
/******************************************************************************
 **                      Private Function Declarations
 ******************************************************************************/
/* PRQA S 2071 1 #KQR002071 */
__attribute__((noinline, section(".indata"), optimize("-Os"))) static void Mcu_Im_NopDelay(uint32 DelayCount);

static void       Mcu_Im_InitSMControl(const Mcu_SystemConfigType *const SMConfig);
LOCAL_INLINE void Mcu_Im_EnablePeriphClock(const Peripheral_ClockEnableType *const PClockConfig);
static void       Mcu_Im_InitPMControl(const Mcu_PowerConfigType *const PMConfig);
static void       Mcu_Im_DetectVddVoltage(void);
/* PRQA S 2071 1 #KQR002071 */
__attribute__((section(".indata"))) static uint32 Mcu_Im_GotoStop0(void);
static void   Mcu_Im_GPtim_BaseInit(GeneralTimer_RegisterMap_t *GTimerX, Mcu_GTimerStructType const *pGtimerInitStruct);
static uint32 Mcu_Im_ReduceSclkFrequency(Mcu_SleepClockType TargetClock);
static void   Mcu_Im_PmcInit(void);
static FUNC(boolean, MCU_CODE) Mcu_Im_GotoMode(Mcu_SleepConfigType McuMode);
static boolean Mcu_Im_GetWakeupPinState(Mcu_WkupIndexType WakeupPin);
/******************************************************************************
 **                      Function definitions
 ******************************************************************************/

/**
 * @brief Delay function.
 *
 * @param DelayCount Delay time (in us) multiplied by frequency of SCLK.
 *  For example:
 *      Now, SCLK is 16MHz and you want to delay 10us, so you should input 16*10 = 160.
 * @attention The delay time is not accurate at low frequencies.
 * @retval void
 */
/* PRQA S 3206 2 #KQR003206 */
/* PRQA S 2071 1 #KQR002071 */
__attribute__((noinline, section(".indata"), optimize("-Os"))) static void Mcu_Im_NopDelay(uint32 DelayCount)
{
    asm volatile("MOV R0, %0" ::"r"(DelayCount));
    asm volatile("LSR R0, #3");
    asm volatile("SUB R0, R0, #1");
    asm volatile("NOP");
    asm volatile("NOP");
    asm volatile("NOP");
    asm volatile("CMP R0, #0");
    /* PRQA S 0286 1 #KQR000286 */
    asm volatile("JNZ $-5");
}

/**
 * @brief Flash ECC & SRAM ECC initial function
 *
 * @param void
 * @retval void
 */
static void Mcu_Im_RamEccInitial(void)
{
    /* Reset RAM ECC */
    Pclk_LL_SetCtl4Clock(PCLK_IDX_ECC4CLKEN, true);
    Rst_LL_SetCtl4State(RST_IDX_ECC4RST, true);
    Rst_LL_SetCtl4State(RST_IDX_ECC4RST, false);

    /* Enable RAM ECC */
    Pm_LL_SetRamEccEnabled(true);
}

/**
 * @brief Flash ECC & SRAM ECC initial function
 *
 * @param void
 * @retval void
 */
static void Mcu_Im_FlashEccInitial(void)
{
    /* Reset Flash ECC */
    Pclk_LL_SetCtl4Clock(PCLK_IDX_ECC0CLKEN, true);
    Rst_LL_SetCtl4State(RST_IDX_ECC0RST, true);
    Rst_LL_SetCtl4State(RST_IDX_ECC0RST, false);
    Pclk_LL_SetCtl4Clock(PCLK_IDX_ECC1CLKEN, true);
    Rst_LL_SetCtl4State(RST_IDX_ECC1RST, true);
    Rst_LL_SetCtl4State(RST_IDX_ECC1RST, false);

    /* Enable Flash ECC */
    Flash_LL_EnableECCCheck();
}

/**
 * @brief enable or disable cache
 * @param
 */
static void Mcu_Im_CacheEnable(bool Enable)
{
    if ((true == Flash_LL_GetLinearPrefetchState()) && (0U != Flash_LL_GetAccessCycle()) && Enable)
    {
        if ((false == Cache_LL_IsEnabled()))
        {
            Cache_LL_ExitReset();
            Cache_LL_EnableECC();
            Cache_LL_Enable();
        }
    }
    else
    {
        Cache_LL_Disable();
        Cache_LL_DisableECC();
        Cache_LL_Reset();
    }
}

/**
 * @brief
 *
 * @param SMConfig
 * @retval void
 */
static void Mcu_Im_InitSMControl(const Mcu_SystemConfigType *const SMConfig)
{
    if (STD_ON == SMConfig->EnableCache)
    {
        Mcu_Im_CacheEnable(true);
    }
    else
    {
        Mcu_Im_CacheEnable(false);
    }

    if (STD_ON == SMConfig->EnableRamEcc)
    {
        Mcu_Im_RamEccInitial();
    }
    else
    {
        /* Do Nothing */
    }

    if (STD_ON == SMConfig->EnableRamEccIntr)
    {
        Ecc_LL_SetIntrEnabled(ECC4_PTR, ECC_INTR_SET_MEM2BITERRIE, true);
    }
    else
    {
        /* Do Nothing */
    }

    if (STD_ON == SMConfig->EnableFlashEccIntr)
    {
        Mcu_Im_FlashEccInitial();
        /*Enable ECC0~EEC4 interrupt*/
        Ecc_LL_SetIntrEnabled(ECC0_PTR, ECC_INTR_SET_MEM2BITERRIE, true);
        Ecc_LL_SetIntrEnabled(ECC1_PTR, ECC_INTR_SET_MEM2BITERRIE, true);
        Ecc_LL_SetIntrEnabled(ECC4_PTR, ECC_INTR_SET_MEM2BITERRIE, true);
    }
    else
    {
        /* Do Nothing */
    }
}

/**
 * @brief
 *
 * @param PClockConfig
 * @retval void
 */
LOCAL_INLINE void Mcu_Im_EnablePeriphClock(const Peripheral_ClockEnableType *const PClockConfig)
{
    /* TODO Further improvement based on LLD is needed here. */
    /* PRQA S 0303 4 #KQR000303 */
    PCLK_RM.CTL0.reg = PClockConfig->PclkCtrlGroup_0;
    PCLK_RM.CTL1.reg = PClockConfig->PclkCtrlGroup_1;
    PCLK_RM.CTL2.reg = PClockConfig->PclkCtrlGroup_2;
    PCLK_RM.CTL3.reg = PClockConfig->PclkCtrlGroup_3;
    PCLK_RM.CTL4.reg = PClockConfig->PclkCtrlGroup_4;
}

/**
 * @brief
 *
 * @param PMConfig
 * @retval void
 */
/* PRQA S 3206 1 #KQR003206 */
static void Mcu_Im_InitPMControl(const Mcu_PowerConfigType *const PMConfig)
{
    MCU_DEV_ASSERT(PMConfig != NULL_PTR);

#if (MCU_ENABLE_SAFETY_STARTUP == STD_ON)
    /* I-WDT use Low-Freq Internal Osc */
    Pm_LL_SetInternalLowFrequencyEnabled(true);
    /* Use I-WDT as Clock Monitor */
    Pm_LL_ExitIwdgReset(true);
    Iwdt_LL_SelectClkSource(IWDT_PTR, false);
    Iwdt_LL_SetClkPrescaler(IWDT_PTR, IWDT_DIVISION_32);
    /* Internal frequency is 32K. preScaler to 32. so we get 1K freq. default time out is set to 500ms. this time is
     * long enough so no need to feed dog */
    Iwdt_LL_SetOverflowValue(IWDT_PTR, 500U);

    Iwdt_LL_SetEnabled(IWDT_PTR, true);
#endif
}

/**
 * @brief Waiting for VDD higher than 2.9V, and enable BOR.
 *
 * @param void
 * @retval void
 */
static void Mcu_Im_DetectVddVoltage(void)
{
    volatile uint32 pvdStaCount = 0U;
    volatile uint32 delayCount  = 0U;

    /*Enable PVD, set PVD voltage detect point to PVD0(2.95V)*/
    Pm_LL_SelectVoltageDetection(PM_VOLTAGE_DETECTION_POINT_0);
    Pm_LL_SetVoltageDetectionEnabled(true);
    /* PRQA S 2740 1 #KQR002740 */
    while (1)
    {
        /* Delay 10us */
        Mcu_Im_NopDelay(160U);
        /* PRQA S 3387 1 #KQR003387 */
        delayCount++;
        /* PRQA S 2109 1 #KQR002109 */
        if (true != Pm_LL_GetPvdState())
        {
            /* PRQA S 3387 1 #KQR003387 */
            pvdStaCount++;
            if (pvdStaCount >= PVD_DETECT_VDD_TIMES)
            {
                break;
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

        /* Timeout, go to callback function */
        if ((10U * delayCount) >= WAIT_VDD_TIME)
        {
            System_LL_SetSystemReset(SYSTEM_PTR, true);
        }
        else
        {
            /* Do Nothing */
        }
    }

    /*Disable PVD*/
    Pm_LL_SetVoltageDetectionEnabled(false);

#if (MCU_FEATURE_BOR_ENABLE == STD_ON)
    /*Enable BOR, set BOR voltage to BOR4(2.799V)*/
    Pm_LL_SelectBorVoltage((Pm_BorVoltage_t)MCU_BOR_LEVEL);
    Pm_LL_SetBorEnabled(true);
#else
    Pm_LL_SetBorEnabled(false);
#endif
}

/**
 * @brief Go to stop0 mode(in RAM)
 *
 * @param void
 * @retval void
 */
/* PRQA S 2071 1 #KQR002071 */
__attribute__((section(".indata"))) static uint32 Mcu_Im_GotoStop0(void)
{
    uint32 errReturn = 0U;

#if (MCU_FEATURE_KEEP_FLASH_IN_STOP0_ENABLE == STD_ON)
    /*Enable keep flash in stop0 mode*/
    PM_PTR->CAL0.bits.STOP0_FLASH_EN = 1U;
#endif

    asm volatile("DSI");
    asm volatile("NOP");
    /* Change vector to __Stop0_Wakeup_Vector */
    /* PRQA S 0306,0324 1 #KQR000306 */
    SYSTEM_PTR->VECTOFF.reg = (uint32_t)&__Stop0_Wakeup_Vector;
    /* Enable interrupt, it is necessary */
    asm volatile("ENI");
    asm volatile("NOP");
    /* Clear all of interrupt flags */
    INTR_PTR->EIF3.reg = 0U;
    INTR_PTR->EIF2.reg = 0U;
    INTR_PTR->EIF1.reg = 0U;
    INTR_PTR->EIF0.reg = 0U;

    /* Clear wake up interrupt flags */
    PM_PTR->STAC.reg |= 0xF87F0000U;
    asm volatile("NOP");
    asm volatile("NOP");
    asm volatile("NOP");
    asm volatile("NOP");
    PM_PTR->STAC.reg &= ~0xF87F0000U;

    /* Enable WKUP Interrupt */
    INTR_PTR->EIE2.bits.WKPIE = 1U;
    asm volatile("SLEEP");
    asm volatile("NOP");
    /*Disable interrupt*/
    asm volatile("DSI");
    asm volatile("NOP");

    /* Close wake up INTR */
    INTR_PTR->EIE2.bits.WKPIE = 0U;
    /* Feed dog*/
    IWDT_PTR->FD.bits.IWDTFD = 0x55AA55AAU;

    /* Change SCLK to INTHF */
    OSC_PTR->CTL0.bits.SCKS = 0U;
#if (MCU_FEATURE_KEEP_FLASH_IN_STOP0_ENABLE == STD_OFF)
    OSC_PTR->CTL0.bits.SCKDIV = 1U;
    (void)Mcu_Im_NopDelay(80U); /* delay 10us(RAM function) */

    errReturn = (uint32_t)__Reload_Kernel_Trim();
#endif
    OSC_PTR->CTL0.bits.SCKDIV = 0U;
    /* delay 10us(RAM function) */
    (void)Mcu_Im_NopDelay(160U);

#if (MCU_FEATURE_KEEP_FLASH_IN_STOP0_ENABLE == STD_ON)
    /*Enable keep flash in stop0 mode*/
    PM_PTR->CAL0.bits.STOP0_FLASH_EN = 0U;
#endif

    /* Reset Vector to default */
    /* PRQA S 0306,0324 1 #KQR000306 */
    SYSTEM_PTR->VECTOFF.reg = (uint32_t)&_start;
    /* Enable Interrupt */
    asm volatile("ENI");
    asm volatile("NOP");

    return errReturn;
}

/**
 * @brief set timer
 *
 * @param GTimerX
 * @param pGtimerInitStruct
 * @retval void
 */
static void Mcu_Im_GPtim_BaseInit(GeneralTimer_RegisterMap_t *GTimerX, Mcu_GTimerStructType const *pGtimerInitStruct)
{
    /* reset clock */
    Pclk_LL_SetTimerEnabled(PCLK_T0, true);
    Rst_LL_SetTimerEnabled(RST_T0, false);
    Rst_LL_SetTimerEnabled(RST_T0, true);

    /* Basic configuration of T0 */
    /* PRQA S 4340 1 #KQR004340 */
    GPTimer_LL_SetUpdateEnabled(GTimerX, (bool)pGtimerInitStruct->UpdateEnableSta);
    GPTimer_LL_SetClkSrc(GTimerX, (Timer_ClockSource_t)pGtimerInitStruct->ClockSrc);
    GPTimer_LL_SetPrescaler(GTimerX, pGtimerInitStruct->PreScaler);
    GPTimer_LL_SetPeriod(GTimerX, pGtimerInitStruct->Period);
    GPTimer_LL_SetCounter(GTimerX, 0U);
    GPTimer_LL_SetCounterManner(GTimerX, (Timer_CountingManner_t)pGtimerInitStruct->CountMode);
    GPTimer_LL_SetWorkingMode(GTimerX, (Timer_Mode_t)pGtimerInitStruct->Mode);
    GPTimer_LL_SetUpdateImmediately(GTimerX);
    /* PRQA S 4340 1 #KQR004340 */
    GPTimer_LL_SetEnabled(GTimerX, (bool)pGtimerInitStruct->StartStatus);
    return;
}

/**
 * @brief Reduce frequency of SCLK.
 *
 * @param TargetClock
 * @retval uint32
 *  0 -- success
 *  other -- failed
 */
static uint32 Mcu_Im_ReduceSclkFrequency(Mcu_SleepClockType TargetClock)
{
    volatile uint32 WaitTime;
    kf_status_t     Ret = STATUS_OK;

    /* Enable INTHF */
    if (!(Osc_LL_GetIntrFlag(OSC_INTR_GET_IHFIF)))
    {
        WaitTime = INTERNAL_CLOCK_STARTUP_TIMEOUT / 10U;
        Osc_LL_SetInthfSoftwareEnabled(true);
        (void)Mcu_Im_NopDelay(MCU_CFG_SYSCLK_FREQ * INTERNAL_CLOCK_STARTUP_TIMEOUT);

        while ((!(Osc_LL_GetIntrFlag(OSC_INTR_GET_IHFIF))) && (0U != WaitTime))
        {
            (void)Mcu_Im_NopDelay(MCU_CFG_SYSCLK_FREQ * 10u);
            /* PRQA S  3387 1 #KQR003387 */
            WaitTime--;
        }
        if (0U == WaitTime)
        {
            Ret = STATUS_ERROR;
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

    /* Enable INTLF */
    if ((!(Osc_LL_GetIntrFlag(OSC_INTR_GET_ILFIF))) && (STATUS_OK == Ret))
    {
        WaitTime = INTERNAL_CLOCK_STARTUP_TIMEOUT / 10U;
        Osc_LL_SetIntlfSoftwareEnabled(true);
        (void)Mcu_Im_NopDelay(MCU_CFG_SYSCLK_FREQ * INTERNAL_CLOCK_STARTUP_TIMEOUT);
        /* PRQA S 3415 1 #KQR003415 */
        while ((!(Osc_LL_GetIntrFlag(OSC_INTR_GET_ILFIF))) && (0U != WaitTime))
        {
            (void)Mcu_Im_NopDelay(MCU_CFG_SYSCLK_FREQ * 10u);
            /* PRQA S 3387 1 #KQR003387 */
            WaitTime--;
        }
        if (0U == WaitTime)
        {
            Ret = STATUS_ERROR;
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

    if (STATUS_OK == Ret)
    {
        /* Swap SCLK to PLL DIVISION 2 */
        Osc_LL_SetSclkDivision(OSC_SCLK_DIVISION_2);
        (void)Mcu_Im_NopDelay((MCU_CFG_SYSCLK_FREQ >> 1U) * 10U);
        /* Swap SCLK to PLL DIVISION 4 */
        Osc_LL_SetSclkDivision(OSC_SCLK_DIVISION_4);
        (void)Mcu_Im_NopDelay((MCU_CFG_SYSCLK_FREQ >> 2U) * 10U);
        /* Swap SCLK to INTHF DIVISION 4 */
        Osc_LL_SelectSclkClockSource(OSC_SCLK_SOURCE_INTHF);
        (void)Mcu_Im_NopDelay(40U);

        if (MCU_SLEEP_CLK_INTLF == TargetClock)
        {
            Osc_LL_SelectSclkClockSource(OSC_SCLK_SOURCE_INTLF);
            Osc_LL_SetSclkDivision(OSC_SCLK_DIVISION_1);
        }
        else if (MCU_SLEEP_CLK_INTHF == TargetClock)
        {
            Osc_LL_SetSclkDivision(OSC_SCLK_DIVISION_1);
            (void)Mcu_Im_NopDelay(160U);
        }
        else
        {
            /* Do Nothing */
        }

        /* Disable Clock */
        Osc_LL_SetPll0SoftwareEnabled(false);
        Osc_LL_SetPll1SoftwareEnabled(false);
        Osc_LL_SetHfclkEnabled(false);
        Osc_LL_SetLfclkEnabled(false);
        if (MCU_SLEEP_CLK_INTLF == TargetClock)
        {
            Osc_LL_SetInthfSoftwareEnabled(false);
        }
        else
        {
            /* Do Nothing */
        }
        Osc_LL_SetExthfSoftwareEnabled(false);
    }
    else
    {
        /* Do Nothing */
    }

    return (uint32)Ret;
}

/**
 * @brief PMC initialise
 *
 * @param void
 * @return void
 */
static void Mcu_Im_PmcInit(void)
{
    Intr_LL_SetExtiMaskValue(INTR_EXTI_INDEX_21, true);
    Intr_LL_SetExtiRiseEdgeEnabled(INTR_EXTI_INDEX_21, true);
    Intr_LL_SetExtiFallEdgeEnabled(INTR_EXTI_INDEX_21, false);
    Intr_LL_SetExtiHiLevelEnabled(INTR_EXTI_INDEX_21, false);
    Intr_LL_ClearExtiFlag(INTR_EXTI_INDEX_21);

    Pm_LL_ClearPmcIntrFlag();
    Pm_LL_SetPmcErrorIntrEnabled(false);

    Intr_LL_ClearInterruptFlag(EINT31TO20_IRQn);
    Intr_LL_SetInterruptEnabled(EINT31TO20_IRQn, false);
}

/**
 * @brief Set external wakeup pin enabled
 *
 * @param WakeupPin Wakeup pin number
 * @param EnableState Enable state
 */
static void Pm_SetExternalWakeupPinEnabled(uint32_t WakeupPin, bool EnableState)
{
    /** Wakeup pin 1~5 */
    if (WakeupPin <= (uint32_t)PM_PIN_WKP5)
    {
        Pm_LL_SetExternalWakeupPinEnabled((Pm_WakeUp_t)WakeupPin, EnableState);
    }
    /** Wakeup pin 6~12 */
    else if (WakeupPin <= (uint32_t)PM_PIN_WKP12)
    {
        Pm_LL_SetExternalWakeup6To12PinEnabled((Pm_WakeUp6To12_t)WakeupPin, EnableState);
    }
    else
    {
        /*Empty*/
    }
}

/**
 * @brief Set external wakeup pin edge
 *
 * @param WakeupPin Wakeup pin number
 * @param WakeupEdge Wakeup edge
 */
static void Pm_SetExternalWakeupEdge(uint32_t WakeupPin, Pm_TrigEdge_t WakeupEdge)
{
    /** Wakeup pin 1~5 */
    if (WakeupPin <= (uint32_t)PM_PIN_WKP5)
    {
        Pm_LL_SetExternalWakeupEdge((Pm_WakeUp_t)WakeupPin, WakeupEdge);
    }
    /** Wakeup pin 6~12 */
    else if (WakeupPin <= (uint32_t)PM_PIN_WKP12)
    {
        Pm_LL_SetExternalWakeup6To12Edge((Pm_WakeUp6To12_t)WakeupPin, WakeupEdge);
    }
    else
    {
        /*Empty*/
    }
}

/**
 * @brief Clear wakeup pin state
 *
 * @param WakeupPin Wakeup pin number
 */
static void Pm_ClearWakeupPinState(uint32_t WakeupPin)
{
    /** Wakeup pin 1~5 */
    if (WakeupPin <= (uint32_t)PM_PIN_WKP5)
    {
        Pm_LL_ClearWakeupPinState((Pm_WakeUp_t)WakeupPin);
    }
    /** Wakeup pin 6~12 */
    else if (WakeupPin <= (uint32_t)PM_PIN_WKP12)
    {
        Pm_LL_ClearWakeup6To12PinState((Pm_WakeUp6To12_t)WakeupPin);
    }
    else
    {
        /*Empty*/
    }
}

/**
 * @brief MCU is transferred to the previous configuration mode.
 *
 * @param McuMode MCU mode ready to go.
 * @retval boolean
 *  TRUE -- success
 *  FALSE --
 *  1 -- Didn't config mode
 *  2 -- Failed to swap SCLK
 *  3 -- Failed to trim flash
 */
static FUNC(boolean, MCU_CODE) Mcu_Im_GotoMode(Mcu_SleepConfigType McuMode)
{
    boolean retVal = FALSE;

    const Mcu_WakeupPinConfig *ptrWakeupConfig = NULL_PTR;

    Bkp_LL_PmRegisterHandleStart();
    if (MCU_SLEEP_NORMAL == McuMode)
    {
        retVal = TRUE;

        /* Clear all of interrupt flags */
        (void)Intr_LL_ClearAllInterruptFlag();

        /* Go to sleep */
        asm volatile("NOP");
        asm volatile("SLEEP");
        asm volatile("NOP");
    }
    /* PRQA S 3344 1 #KQR003344 */
    else if (Mcu_ModeConfiguredStatus)
    {
        Mcu_Im_PmcInit();
        /* PRQA S 3344 1 #KQR003344 */
        if (Mcu_ModeCfgRecorder.Mcu_PinWkupEnableSta)
        {
            for (uint8_t i = 0U; i < Mcu_ModeCfgRecorder.Mcu_WkupConfig->WakeupNumber; i++)
            {
                ptrWakeupConfig = &Mcu_ModeCfgRecorder.Mcu_WkupConfig->WakeupPinConfig[i];
                /* PRQA S 3344 1 #KQR003344 */
                if (ptrWakeupConfig->WakeupFixLvEnable)
                {
                    if (MCU_WAKEUP_EDGE_FALL == ptrWakeupConfig->WakeupEdge)
                    {
                        /* Enable WKUP pin pull down */
                        Gpio_LL_WritePullDownState(
                          Mcu_Wkp_Port[ptrWakeupConfig->WakeupIndex],
                          (Gpio_PinIndex_t)Mcu_Wkp_Pin[ptrWakeupConfig->WakeupIndex], true);
                    }
                    else
                    {
                        /* Enable WKUP pin pull up */
                        Gpio_LL_WritePullUpState(
                          Mcu_Wkp_Port[ptrWakeupConfig->WakeupIndex],
                          (Gpio_PinIndex_t)Mcu_Wkp_Pin[ptrWakeupConfig->WakeupIndex], true);
                    }
                }
                else
                {
                    /* Do Nothing */
                }

                Pm_SetExternalWakeupPinEnabled((uint32_t)ptrWakeupConfig->WakeupIndex, true);
                /* Set WKUP edge trigger. */
                Pm_SetExternalWakeupEdge(
                  (uint32_t)ptrWakeupConfig->WakeupIndex, (Pm_TrigEdge_t)ptrWakeupConfig->WakeupEdge);
                /* Clear WKUP flag. */
                Pm_ClearWakeupPinState((uint32_t)ptrWakeupConfig->WakeupIndex);
            }

            Pm_LL_ClearAllWakeupPinState();
            Intr_LL_ClearInterruptFlag(WKP_IRQn);
            Intr_LL_SetInterruptEnabled(WKP_IRQn, false);
        }
        else
        {
            /* Do Nothing */
        }
        /* PRQA S 3344 1 #KQR003344 */
        if (Mcu_ModeCfgRecorder.Mcu_T0WkupEnableSta)
        {
            Mcu_GTimerStructType LpTimerInit = {
              .ClockSrc        = (uint32_t)TIM_INTLF_T0,
              .CountMode       = (uint32_t)TIM_MANNER_UP_FLAG,
              .Mode            = (uint32_t)TIMING_MODE,
              .PreScaler       = 31U,
              .Period          = Mcu_ModeCfgRecorder.Mcu_T0WkupTime,
              .UpdateEnableSta = TRUE,
              .StartStatus     = 0U,
            };
            PM_PTR->CTL2.bits.T0LPEN    = 0U;
            PM_PTR->CTL2.bits.T0LPEN    = 1U;
            PM_PTR->CTL2.bits.T0CLKLPEN = 1U;

            Mcu_Im_GPtim_BaseInit(T0_PTR, &LpTimerInit);
            /* Config interrupt of timer */
            GPTimer_LL_SetOverFlowIntrEnabled(T0_PTR, true);
            Intr_LL_ClearInterruptFlag(T0_IRQn);
            Intr_LL_SetInterruptEnabled(T0_IRQn, true);
        }
        else
        {
            /* Do Nothing */
        }

        if (MCU_SLEEP_STANDBY == McuMode)
        {
            /** Set PMCWKPTESTSEL */
            Pm_LL_SetSoftwareWakeupEnabled(true);

#if (MCU_KEEP_LPRAM_STATE_IN_STANDBY)
            /* Keep LPRAM in standby */
            Pm_LL_SetLpramWorkMode(1U);
#endif
#if (MCU_INNER_LOW_FREQ_IN_LOW_POWER_MODE == STD_ON)
            Pm_LL_SetInternalLowFrequencyEnabled(true);
#endif
#if (MCU_OUTER_LOW_FREQ_IN_LOW_POWER_MODE == STD_ON)
            Pm_LL_SetExternalLowFrequencyEnabled(true);
#endif
#if (MCU_INNER_HIGH_FREQ_IN_LOW_POWER_MODE == STD_ON)
            Pm_LL_SetInternalHighFrequencyEnabled(true);
#endif
            /* Set standby sleep mode */
            Pm_LL_SelectLowPowerMode(PM_LOW_POWER_STANDBY);

            /* Disable the BKP area read and write */
            Bkp_LL_PmRegisterHandleEnd();

            /* Clear all of interrupt flags */
            (void)Intr_LL_ClearAllInterruptFlag();

            /* Disable interrupt*/
            asm volatile("DSI");
            /* Go to sleep */
            asm volatile("NOP");
            asm volatile("SLEEP");
            asm volatile("NOP");
        }
        else if ((MCU_SLEEP_STOP0 == McuMode))
        {
#if (MCU_FEATURE_FSCM_ENABLE == STD_ON)
            Osc_LL_SetFscmEnabled(false);
#endif

            Pm_LL_SetPmcErrorIntrEnabled(true);
            Intr_LL_SetInterruptEnabled(EINT31TO20_IRQn, true);

            /* PRQA S 3344 1 #KQR003344 */
            if (Mcu_ModeCfgRecorder.Mcu_T0WkupEnableSta)
            {
                GPTimer_LL_SetEnabled(T0_PTR, true);
            }
            else
            {
                /* Do Nothing */
            }
            /* Set stop0 sleep mode */
            Pm_LL_SelectLowPowerMode(PM_LOW_POWER_STOP_0);

            /** Set TEST_STOP0 */
            Osc_LL_SetStop0ClearClockStableFlagEnabled(true);
            Osc_LL_SetInthfStartDelay(OSC_INTHF_START_DELAY_16384);

            Pm_LL_SetInternalLowFrequencyEnabled(true);
            Iwdt_LL_FeedDog(IWDT_PTR);

            /** @note: Need modify the delay time of `Mcu_GotoStop0` the same time. */
            if (0U != Mcu_Im_ReduceSclkFrequency(MCU_SLEEP_CLK_INTLF))
            {
                retVal = FALSE;
            }
            else
            {
#if (MCU_FEATURE_KEEP_FLASH_IN_STOP0_ENABLE == STD_ON)
                /** Enable keep flash in stop0 */
                Pm_LL_SetStop0FlashDelayEnabled(true);
#endif
                if (0U != Mcu_Im_GotoStop0())
                {
                    retVal = FALSE;
                }
                else
                {
                    /* Success path */
                    retVal = TRUE;
                }
            }
            /* PRQA S 3344 1 #KQR003344 */
            if (Mcu_ModeCfgRecorder.Mcu_T0WkupEnableSta)
            {
                GPTimer_LL_SetEnabled(T0_PTR, false);
            }
            else
            {
                /* Do Nothing */
            }

            /* Re-initial MCU */
            Mcu_Stop0WakeUpReInit();
        }
        else
        {
            /* Do Nothing */
        }
    }
    else
    {
        retVal = FALSE;
    }

    Bkp_LL_PmRegisterHandleEnd();

    return retVal;
}

#if (MCU_IO_LATCH_STATE_IN_STANDBY == STD_ON)
/**
 * @brief set io latch state
 */
void Mcu_Im_LatchIO(boolean Enabled)
{
    Bkp_LL_PmRegisterHandleStart();
    /*Set IO latch*/
    /* PRQA S 4340 1 #KQR004340 */
    Pm_LL_SetIoLatchEnabled((bool)Enabled);
    Bkp_LL_PmRegisterHandleEnd();
}
#endif

/**
 * @brief mcu sleep config mode information
 *
 * @param McuMode
 * @retval void
 *
 */
FUNC(boolean, MCU_CODE) Mcu_Im_SetMode(const Mcu_PowerConfigType *PowerModeConfig)
{
    if (PowerModeConfig->Mcu_SleepType != MCU_SLEEP_NORMAL)
    {
        /* Recode MCU config status and configuration */
        Mcu_ModeConfiguredStatus = TRUE;

        Mcu_ModeCfgRecorder.Mcu_PinWkupEnableSta         = PowerModeConfig->Mcu_PinWkupEnableSta;
        Mcu_ModeCfgRecorder.Mcu_WkupConfig->WakeupNumber = PowerModeConfig->Mcu_WkupConfig->WakeupNumber;

        for (uint8_t i = 0U; i < PowerModeConfig->Mcu_WkupConfig->WakeupNumber; i++)
        {
            Mcu_ModeCfgRecorder.Mcu_WkupConfig->WakeupPinConfig[i].WakeupEdge =
              PowerModeConfig->Mcu_WkupConfig->WakeupPinConfig[i].WakeupEdge;

            Mcu_ModeCfgRecorder.Mcu_WkupConfig->WakeupPinConfig[i].WakeupFixLvEnable =
              PowerModeConfig->Mcu_WkupConfig->WakeupPinConfig[i].WakeupFixLvEnable;

            Mcu_ModeCfgRecorder.Mcu_WkupConfig->WakeupPinConfig[i].WakeupIndex =
              PowerModeConfig->Mcu_WkupConfig->WakeupPinConfig[i].WakeupIndex;
        }

        Mcu_ModeCfgRecorder.Mcu_T0WkupEnableSta = PowerModeConfig->Mcu_T0WkupEnableSta;
        Mcu_ModeCfgRecorder.Mcu_T0WkupTime =
          ((PowerModeConfig->Mcu_T0WkupTime > 5U) ? PowerModeConfig->Mcu_T0WkupTime : 5U);
    }
    else
    {
        /* do nothing */
    }

    return Mcu_Im_GotoMode(PowerModeConfig->Mcu_SleepType);
}

#if (MCU_INIT_CLOCK == STD_ON)
#if (MCU_NO_PLL == STD_OFF)
/**
 * @brief
 * @param
 * @param
 */
static void Mcu_Im_PllDivisionProcess(Sclk_DivisionFactorType SclkDiv, Sclk_SourceType SclkSource)
{
    switch (SclkDiv)
    {
    case SCLK_DIVISION_1:
    case SCLK_DIVISION_2:
    case SCLK_DIVISION_4:
    case SCLK_DIVISION_8:
    case SCLK_DIVISION_16:
    case SCLK_DIVISION_32: {
        /* Enable SCLK */
        /* PRQA S 4394 1 #KQR004394 */
        Osc_LL_SetSclkDivision((Osc_SclkDivision_t)((uint8)SclkDiv + 2U));
        Mcu_Im_NopDelay((uint32)(MCU_CFG_CLK_FREQ * 10U) >> 2U);
        Osc_LL_SelectSclkClockSource((Osc_SclkSrc_t)SclkSource);
        Mcu_Im_NopDelay((uint32)(MCU_CFG_SYSCLK_FREQ * 10U) >> 2U);
        /*Set SCLK division to 2*/
        /* PRQA S 4394 1 #KQR004394 */
        Osc_LL_SetSclkDivision((Osc_SclkDivision_t)((uint8)SclkDiv + 1U));
        Mcu_Im_NopDelay((uint32)(MCU_CFG_SYSCLK_FREQ * 10U) >> 1U);
        /*Set SCLK division to 1*/
        Osc_LL_SetSclkDivision((Osc_SclkDivision_t)SclkDiv);
        Mcu_Im_NopDelay((uint32)(MCU_CFG_SYSCLK_FREQ * 10U));
        break;
    }
    case SCLK_DIVISION_64: {
        /* Enable SCLK */
        Osc_LL_SetSclkDivision((Osc_SclkDivision_t)SCLK_DIVISION_128);
        Mcu_Im_NopDelay((uint32)(MCU_CFG_CLK_FREQ * 10U) >> 2U);
        Osc_LL_SelectSclkClockSource((Osc_SclkSrc_t)SclkSource);
        Mcu_Im_NopDelay((uint32)(MCU_CFG_SYSCLK_FREQ * 10U) >> 2U);
        /*Set SCLK division to 2*/
        Osc_LL_SetSclkDivision((Osc_SclkDivision_t)SCLK_DIVISION_64);
        Mcu_Im_NopDelay((uint32)(MCU_CFG_SYSCLK_FREQ * 10U) >> 1U);
        break;
    }
    case SCLK_DIVISION_128: {
        /* Enable SCLK */
        Osc_LL_SetSclkDivision((Osc_SclkDivision_t)SCLK_DIVISION_128);
        Mcu_Im_NopDelay((uint32)(MCU_CFG_CLK_FREQ * 10U) >> 2U);
        Osc_LL_SelectSclkClockSource((Osc_SclkSrc_t)SclkSource);
        Mcu_Im_NopDelay((uint32)(MCU_CFG_SYSCLK_FREQ * 10U) >> 2U);
        break;
    }
    /* PRQA S 2016 1 #KQR002016 */
    default:
        break;
    }
}

/**
 * @brief This function activates the main PLL as the system clock source.
 * @details This function sets the PLL as the system clock and also enables monitoring.
 *  This will set SCLK Source to Pll
 *
 * @return void
 *
 */
FUNC(void, MCU_CODE) Mcu_Im_DistributePllClock(const Mcu_ClockConfigType *const ClockConfigPtr)
{
    volatile uint32 intrState;
    volatile uint32 PM_CAL0_TMP, PM_CAL0_HLVL;

    /* Config the BKP area is enable, BKP register and data can be write and read */
    Bkp_LL_PmRegisterHandleStart();

    Flash_LL_SetFlashConfig(MCU_FLASH_CFG_PREDEF_VALUE);

    /**
     * Select PLL as SCLK
     */
    intrState   = Intr_LL_EnterCritical();
    PM_CAL0_TMP = Pm_LL_GetBGTRIMMRLDOValue();

    PM_CAL0_HLVL = PM_CAL0_TMP + 3U;
    /* Judge the value in Pm_LL_SetBGTRIMMRLDOValue */
    Pm_LL_SetBGTRIMMRLDOValue((uint8_t)PM_CAL0_HLVL);
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");

    /* @implements #SWS_Mcu_00140,#SWS_Mcu_00141 */
    Mcu_Im_PllDivisionProcess(ClockConfigPtr->SclkConfig.Division, ClockConfigPtr->SclkConfig.ClockSource);

    Pm_LL_SetBGTRIMMRLDOValue((uint8_t)PM_CAL0_TMP);
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");

    Intr_LL_ExitCritical(intrState);

    /* Enable High-Freq Peripheral Clk */
    if ((ClockConfigPtr->HSPclkConfig.Enabled == (boolean)TRUE))
    {
        if (ClockConfigPtr->HSPclkConfig.ClockSource == HFCLK_SOURCE_PLL)
        {
            Osc_LL_SetHfclkDivision((Osc_HfclkDivision_t)ClockConfigPtr->HSPclkConfig.Division);
            Osc_LL_SelectHfclkClockSource((Osc_HfclkSrc_t)ClockConfigPtr->HSPclkConfig.ClockSource);
            Osc_LL_SetHfclkEnabled(true);
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

    Bkp_LL_PmRegisterHandleEnd();

#if (MCU_ENABLE_SAFETY_STARTUP == STD_ON)
    /* To Disable IWDT We need BKP Operation */
    Bkp_LL_PmRegisterHandleStart();
    Iwdt_LL_SetEnabled(IWDT_PTR, false);
    Pm_LL_ExitIwdgReset(false);
    Bkp_LL_PmRegisterHandleEnd();
#endif

#if (MCU_CLOCK_OUTPUT_FUNCTION == STD_ON)
    /* Mcu Clock Output Function */
    Osc_LL_SelectClkOutClockSource((Osc_ClkOutSrc_t)MCU_CLOCK_OUTPUT_SOURCE);
    Osc_LL_SetClkOutDivision((Osc_ClkOutDivision_t)MCU_CLOCK_OUTPUT_DIVISION);

    Osc_LL_SetClkOutEnabled(true);
#endif
}
#endif
#endif

FUNC(Mcu_PllStatusType, MCU_CODE) Mcu_Im_GetPllStatus(void)
{
    /* Pll status variable. */
    Mcu_PllStatusType status;
    if (Osc_LL_GetIntrFlag(OSC_INTR_GET_PLL0IF))
    {
        /* PLL LOCKED */
        status = MCU_PLL_LOCKED;
    }
    else
    {
        /* PLL UNLOCKED */
        status = MCU_PLL_UNLOCKED;
    }
    return status;
}

static uint32 Mcu_Im_WakeUpPinCheck(void)
{
    uint32 i;
    uint32 wakeUpPin = 0U;

    for (i = 0U; i < (uint32)MCU_WKUP_MAX; i++)
    {
        /* PRQA S 4342 1 #An expression of 'essentially unsigned' type is being cast to enum type */
        if (Mcu_Im_GetWakeupPinState((Mcu_WkupIndexType)i) == TRUE)
        {
            /* PRQA S 2986 1 #KQR002986 */
            wakeUpPin |= (uint32)((uint32)1U << i);

            break;
        }
        else
        {
            /* Do Nothing */
        }
    }

    return wakeUpPin;
}

FUNC(Mcu_ResetType, MCU_CODE) Mcu_Im_GetResetReason(void)
{
    /* Code for the Reset event returned by this function. */
    Mcu_ResetType resetReason = MCU_NO_RESET_REASON;
    /* Temporary variable for PM_STA0 register value. */
    uint32 index;
    uint32 dynamicMask;
    uint32 position   = 0x00U;
    uint32 numOfFlags = 0x00U;
    uint32 regValue;

    /* Config the BKP area is enable, BKP register and data can be write and read */
    Bkp_LL_HandleStart();
    /* Check reset reasons from PM_STA0 Register. */
    regValue = PM_RM.STA0.reg & PM_STA0_RESET_REASON_MASK32;
    /* clear WKPPINF */
    regValue = regValue & (~(uint32)0x10000000U);
    /* check WKPPINF:28bit */
    if (Mcu_Im_WakeUpPinCheck() != 0U)
    {
        regValue = (regValue | (uint32)0x10000000U);
    }
    else
    {
        /* do nothing */
    }

    if (regValue != 0U)
    {
        Mcu_RawResetValue = regValue;
    }
    else
    {
        regValue = Mcu_RawResetValue;
    }
    /* Clear the flags if any flag is set */
    Pm_LL_ClearRstAndWakeupFlag();
    Pm_LL_ClearBkpPorResetFlag();
    Pm_LL_ClearPowerOnResetFlag();
    /* disable BKP area */
    Bkp_LL_HandleEnd();

    if (0x00U != regValue)
    {
        for (index = 0x00U; index < 0x20U; index++)
        {
            dynamicMask = ((uint32)0x80000000U >> index);
            if ((uint32)0x00U != (dynamicMask & PM_STA0_RESET_REASON_MASK32))
            {
                if ((uint32)0x00U != (dynamicMask & regValue))
                {
                    resetReason = (Mcu_ResetType)position;
                    numOfFlags++;
                    /* MCU_MULTIPLE_RESET_REASON returned if more than one reset reason in this case use function
                     * Mcu_GetRawValue to determine. */
                    if (numOfFlags >= (uint32)2U)
                    {
                        resetReason = MCU_MULTIPLE_RESET_REASON;
                        break;
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
                position++;
            }
            else
            {
                /* Do Nothing */
            }
        }
    }
    else
    {
        /* Do Nothing*/
    }

    return resetReason;
}

/**
 * @brief get wake up pin status
 *
 * @param WakeupPin pin index
 */
static boolean Mcu_Im_GetWakeupPinState(Mcu_WkupIndexType WakeupPin)
{
    boolean RetState = FALSE;

    if (WakeupPin <= MCU_WKUP5)
    {
        /* PRQA S 4304 1 #KQR004304 */
        RetState = (boolean)Pm_LL_GetWakeupPinState((Pm_WakeUp_t)WakeupPin);
    }
    else if (WakeupPin <= MCU_WKUP12)
    {
        /* PRQA S 4304 1 #KQR004304 */
        RetState = (boolean)Pm_LL_GetWakeup6To12PinState((Pm_WakeUp6To12_t)WakeupPin);
    }
    else
    {
        /* Do Nothing */
    }

    return RetState;
}

/**
 * @brief
 *
 * @retval Mcu_RawResetType
 */
Mcu_RawResetType Mcu_Im_GetResetRawValue(void)
{
    uint32 regValue;
    uint32 wakeUpPin = 0U;
    uint32 i;

    /* Config the BKP area is enable, BKP register and data can be write and read */
    Bkp_LL_HandleStart();
    regValue = PM_RM.STA0.reg & PM_STA0_RESET_REASON_MASK32;
    /* clear WKPPINF */
    regValue = regValue & (~(uint32)0x10000000U);
    /* check WKPPINF:28bit */
    if (Mcu_Im_WakeUpPinCheck() != 0U)
    {
        regValue = (regValue | (uint32)0x10000000U);
    }
    else
    {
        /* do nothing */
    }

    if (regValue != 0U)
    {
        Mcu_RawResetValue = regValue;
    }
    else
    {
        regValue = Mcu_RawResetValue;
    }
    /* Clear the flags if any flag is set */
    Pm_LL_ClearRstAndWakeupFlag();
    Pm_LL_ClearBkpPorResetFlag();
    Pm_LL_ClearPowerOnResetFlag();

    if ((regValue & ((uint32)0x10000000U)) > 0U)
    {
        for (i = 0U; i < (uint32)MCU_WKUP_MAX; i++)
        {
            if (Mcu_Im_GetWakeupPinState((Mcu_WkupIndexType)i) == TRUE)
            {
                wakeUpPin |= (uint32)((uint32)1U << i);
            }
            else
            {
                /* Do Nothing */
            }
        }
    }
    else
    {
        /* do nothing */
    }

    /* disable BKP area */
    Bkp_LL_HandleEnd();

    return (Mcu_RawResetType)(regValue | wakeUpPin);
}

/**
 * @brief Perform Mcu Reset
 *
 */
/*PRQA S 2885 1 #KQR002885 */
void Mcu_Im_Reset(void)
{
    /* PRQA S 2870 1 #KQR002870 */
    RESET();
}

/**
 * @brief
 *
 * @param ClockConfigPtr
 * @retval void
 *
 */
FUNC(void, MCU_CODE) Mcu_Im_InitClock(const Mcu_ClockConfigType *const ClockConfigPtr)
{
    /* Enable INTLF */
    if (ClockConfigPtr->InnerLFConfig.Enabled == (boolean)TRUE)
    {
        Osc_LL_ClearIntrFlag(OSC_INTR_CLEAR_ILFIF);
        Osc_LL_SetIntlfStartDelay((Osc_IntlfStartDelay_t)(ClockConfigPtr->InnerLFConfig.Delay));
        Osc_LL_SetIntlfSoftwareEnabled(true);
        (void)Mcu_Im_NopDelay(MCU_CFG_CLK_FREQ * INTERNAL_CLOCK_STARTUP_TIMEOUT);

        /* PRQA S 2482 1 #KQR002482 */
        while (!(Osc_LL_GetIntrFlag(OSC_INTR_GET_ILFIF)))
        {
        }
    }
    else
    {
        Osc_LL_SetIntlfSoftwareEnabled(false);
    }
    Osc_LL_SetInthfStartDelay((Osc_InthfStartDelay_t)ClockConfigPtr->InnerHFConfig.Delay);
    /* Enable INTHF used for system clock */
    Osc_LL_SetInthfSoftwareEnabled(true);

    Flash_LL_SetFlashConfig(0xC7U);

    /*Delay and wait for INTHF to be ready*/
    (void)Mcu_Im_NopDelay(MCU_CFG_CLK_FREQ * INTERNAL_CLOCK_STARTUP_TIMEOUT);

    /* PRQA S 2482 1 #KQR002482 */
    while (!(Osc_LL_GetIntrFlag(OSC_INTR_GET_IHFIF)))
    {
        ;
    }

    /* Set the INTHF as the SCLK DIV<1:1> */
    Osc_LL_SetSclkDivision(OSC_SCLK_DIVISION_1);
    Osc_LL_SelectSclkClockSource(OSC_SCLK_SOURCE_INTHF);

    /* Enable EXTLF */
    if (ClockConfigPtr->OuterLFConfig.Enabled == (boolean)TRUE)
    {
        Osc_LL_ClearIntrFlag(OSC_INTR_CLEAR_ELFIF);
        Osc_LL_SetExtlfStartDelay((Osc_ExtStartDelay_t)ClockConfigPtr->OuterLFConfig.Delay);
        Osc_LL_SetExtlfSoftwareEnabled(true);

        /* PRQA S 2482 1 #KQR002482 */
        while (!(Osc_LL_GetIntrFlag(OSC_INTR_GET_ELFIF)))
        {
        }
    }
    else
    {
        Osc_LL_SetExtlfSoftwareEnabled(false);
    }

    /* Enable EXTHF */
    if (ClockConfigPtr->OuterHFConfig.Enabled == (boolean)TRUE)
    {
        /* Disable HSE to avoid core crash in case that crystal oscillator short circuit */
        Osc_LL_SetHseOutputHysteresisEnabled(false);

        /**
         * Disable PLL0 lock detection
         */
        Osc_LL_SetPll0LockDetectEnabled(false);

        Gpio_LL_WriteModeDirectionState(GPIOH_PTR, GPIO_PIN_INDEX_11, GPIO_PIN_MODE_IN);
        /* Set GMBOOST to 0B1000 */
        Osc_LL_SelectExthfDriverWeightsAdjust(OSC_EXTHF_DRIVE_WEIGHTS_16_4);
        /* EXTHF internal parallel 470K resistor enable */
        Osc_LL_SetXthr470kEnabled(true);
        Osc_LL_SetExthfStartDelay((Osc_ExtStartDelay_t)ClockConfigPtr->OuterHFConfig.Delay);
        Osc_LL_ClearIntrFlag(OSC_INTR_CLEAR_EHFIF);
        /* Must be wait till EXTHF is ready and if Time out is reached exit */
        Osc_LL_SetExthfSoftwareEnabled(true);

        /* Delay and wait for EXTHF to be ready */
        (void)Mcu_Im_NopDelay(MCU_CFG_CLK_FREQ * EXTERNAL_CLOCK_STARTUP_TIMEOUT);

        /* PRQA S 2482 1 #KQR002482 */
        while (!(Osc_LL_GetIntrFlag(OSC_INTR_GET_EHFIF)))
        {
            ;
        }
    }
    else
    {
        Osc_LL_SetExthfSoftwareEnabled(false);
    }

#if (MCU_FEATURE_FSCM_ENABLE == STD_ON)
    /* Configure the FSCM function to monitor the system clock. */
    Osc_LL_SelectFscmClockSource(OSC_FSCM_SOURCE_EXTHF);
    Osc_LL_SetFscmGap(OSC_FSCM_GAP_INTLF64);
    Osc_LL_SetFscmEnabled(true);
#endif

#if (MCU_NO_PLL == STD_OFF)
    Osc_LL_ClearIntrFlag(OSC_INTR_CLEAR_PLL0IF);

    /* pll source config */
    if (PLL_SOURCE_INTHF == ClockConfigPtr->PllConfig.ClockSource)
    {
        Osc_LL_SelectPll0ClockSource(OSC_PLL_INPUT_INTHF);
    }
    else
    {
        Osc_LL_SelectPll0ClockSource(OSC_PLL_INPUT_EXTHF);
    }
#endif

    if (ClockConfigPtr->OuterHFConfig.Enabled == (boolean)TRUE)
    {
        Osc_LL_SelectSclkClockSource(OSC_SCLK_SOURCE_EXTHF);
    }
    else
    {
        /* Do Nothing */
    }

    /* disable INTHF */
    if (ClockConfigPtr->InnerHFConfig.Enabled == (boolean)FALSE)
    {
        Osc_LL_SetInthfSoftwareEnabled(false);
    }
    else
    {
        /* Do Nothing */
    }

#if (MCU_NO_PLL == STD_OFF)
    /* PRQA S 4340  1 #KQR004340*/
    Osc_LL_SetPll0Division((bool)ClockConfigPtr->PllConfig.IsClockDivBy2);

    Osc_LL_SetPll0StartDelay((Osc_PllStartDelay_t)ClockConfigPtr->PllConfig.Delay);

    Osc_LL_SetPll0MultipleValue(
      ClockConfigPtr->PllConfig.Control.M, ClockConfigPtr->PllConfig.Control.N, ClockConfigPtr->PllConfig.Control.OD);
    /* Enable PLL  */
    Osc_LL_SetPll0SoftwareEnabled(true);
    Osc_LL_SetPll0Reset();
#endif
    /*Delay and wait for PLL to be ready*/
    Mcu_Im_NopDelay(MCU_CFG_CLK_FREQ * 1000U);

    /* Enable High-Freq Peripheral Clk */
    if ((ClockConfigPtr->HSPclkConfig.Enabled == (boolean)TRUE))
    {
        /* Pll is distribute to HSPclk in Mcu_DistributePllClock */
        if (ClockConfigPtr->HSPclkConfig.ClockSource != HFCLK_SOURCE_PLL)
        {
            /* First, Use Default Value */
            Osc_LL_SelectHfclkClockSource((Osc_HfclkSrc_t)ClockConfigPtr->HSPclkConfig.ClockSource);
            Osc_LL_SetHfclkDivision((Osc_HfclkDivision_t)ClockConfigPtr->HSPclkConfig.Division);
            Osc_LL_SetHfclkEnabled(true);
        }
        else
        {
            /* Use Default Value. Leave it to Mcu_DistributePllClock */
        }
    }
    else
    {
        Osc_LL_SetHfclkEnabled(false);
    }

    /* Enable Low-Freq Peripheral Clk */
    if (ClockConfigPtr->LSPclkConfig.Enabled == (boolean)TRUE)
    {
        Osc_LL_SelectLfclkClockSource((Osc_LfclkSrc_t)ClockConfigPtr->LSPclkConfig.ClockSource);
        Osc_LL_SetLfclkDivision((Osc_LfclkDivision_t)ClockConfigPtr->LSPclkConfig.Division);
        Osc_LL_SetLfclkEnabled(true);
    }
    else
    {
        Osc_LL_SetLfclkEnabled(false);
    }

#if (MCU_INNER_LOW_FREQ_IN_LOW_POWER_MODE == true)
    Pm_LL_SetInternalLowFrequencyEnabled(true);
#endif

#if (MCU_OUTER_LOW_FREQ_IN_LOW_POWER_MODE == true)
    Pm_LL_SetExternalLowFrequencyEnabled(true);
#endif

    if (ClockConfigPtr->SclkConfig.ClockSource != SCLK_SOURCE_PLL)
    {
        Osc_LL_SetSclkDivision((Osc_SclkDivision_t)ClockConfigPtr->SclkConfig.Division);
        Osc_LL_SelectSclkClockSource((Osc_SclkSrc_t)ClockConfigPtr->SclkConfig.ClockSource);

#if (MCU_CLOCK_OUTPUT_FUNCTION == STD_ON)
#if (MCU_NO_PLL == STD_ON)
        /* Mcu Clock Output Function */
        Osc_LL_SelectClkOutClockSource((Osc_ClkOutSrc_t)MCU_CLOCK_OUTPUT_SOURCE);
        Osc_LL_SetClkOutDivision((Osc_ClkOutDivision_t)MCU_CLOCK_OUTPUT_DIVISION);

        Osc_LL_SetClkOutEnabled(true);
#endif
#endif
    }
    else
    {
        /* Do Nothing */
    }

    /* Peripheral clock enable */
    Mcu_Im_EnablePeriphClock(&ClockConfigPtr->PclkEnConfig);

#if (MCU_NO_PLL == STD_ON)
#if (MCU_ENABLE_SAFETY_STARTUP == STD_ON)
    Bkp_LL_PmRegisterHandleStart();
    Iwdt_LL_SetEnabled(IWDT_PTR, false);
    Pm_LL_ExitIwdgReset(false);
    Bkp_LL_PmRegisterHandleEnd();
#endif
    Flash_LL_SetFlashConfig(MCU_FLASH_CFG_PREDEF_VALUE);
#endif

    /* @implements #SWS_Mcu_00138 */
    /* return without waiting until the PLL is locked */
}

/**
 * @brief
 *
 * @param RamConfig
 * @retval void
 *
 */
FUNC(Std_ReturnType, MCU_CODE) Mcu_Im_InitRam(const Mcu_RamConfigType *RamConfig)
{
    VAR(Std_ReturnType, AUTOMATIC) RamStatus = (Std_ReturnType)E_OK;
    uint32 RamCounter;
    uint32 RamCounterLimit;

    RamCounterLimit = ((RamConfig->Mcu_RamSize) / (RamConfig->Mcu_RamWriteSize));
    /* PRQA S 2474 2 #KQR002474 */
    for (RamCounter = 0U; ((RamCounter < RamCounterLimit) && ((Std_ReturnType)E_OK == RamStatus)); ++RamCounter)
    {
        /* PRQA S 2032 1 #KQR002032 */
        switch (RamConfig->Mcu_RamWriteSize)
        {
        case 1U:
            ((uint8(*))(RamConfig->Mcu_RamBaseAddress))[RamCounter] = (uint8)RamConfig->Mcu_RamDefaultValue;
            break;

        case 2U:
            /* PRQA S 0310 1 #KQR000310 */
            ((uint16(*))(RamConfig->Mcu_RamBaseAddress))[RamCounter] = (uint16)RamConfig->Mcu_RamDefaultValue;
            break;

        case 4U:
            /* PRQA S 0310 1 #KQR000310 */
            ((uint32(*))(RamConfig->Mcu_RamBaseAddress))[RamCounter] = (uint32)RamConfig->Mcu_RamDefaultValue;
            break;

        case 8U:
            ((uint64(*))(RamConfig->Mcu_RamBaseAddress))[RamCounter] = (uint64)RamConfig->Mcu_RamDefaultValue;
            break;

        default:
            RamStatus = (Std_ReturnType)E_NOT_OK;
            break;
        }
    }

    return RamStatus;
}

/**
 * @brief
 *
 * @param Mcu_HwConfigPtr
 * @return void
 *
 */
FUNC(void, MCU_CODE) Mcu_Im_Init(const Mcu_HwConfigType *const Mcu_HwConfigPtr)
{
    /* Config the BKP area is enable, BKP register and data can be write and read */
    Bkp_LL_PmRegisterHandleStart();

    /* CAN MB Reception Rule Calibration */
    PM_PTR->CAL0.reg = PM_PTR->CAL0.reg & (~(1u << 21u));

    /* @implements #SWS_Mcu_00247 */
    Mcu_Im_DetectVddVoltage();
    Mcu_Im_InitSMControl(Mcu_HwConfigPtr->SMConfig);
    Mcu_Im_InitPMControl(Mcu_HwConfigPtr->PMConfig);

    /* disable BKP area */
    Bkp_LL_PmRegisterHandleEnd();
}

/**
 * @brief Internal reference voltage configuration
 * @retval void
 * @return void
 */
FUNC(void, MCU_CODE) Mcu_Im_InternalRefVolConfig(void)
{
    /* PRQA S 2742 1 #KQR002742 */
    if (MCU_REF_VOLTAGE_NOT_USE != MCU_CFG_INTERNAL_REF_VOLTAGE)
    {
        /* PRQA S 2880 1 #KQR002880 */
        Bkp_LL_PmRegisterHandleStart();

        if (!Pm_LL_GetFvrCaplessEnabledState())
        {
            switch (MCU_CFG_INTERNAL_REF_VOLTAGE)
            {
            case MCU_REF_VOLTAGE_4V: {
                Pm_LL_SelectFvr2Voltage(PM_FVR_VOLTAGE_4V);
                break;
            }
            case MCU_REF_VOLTAGE_3V: {
                Pm_LL_SelectFvr2Voltage(PM_FVR_VOLTAGE_3V);
                break;
            }
            case MCU_REF_VOLTAGE_2V: {
                Pm_LL_SelectFvr2Voltage(PM_FVR_VOLTAGE_2V);
                break;
            }
            case MCU_REF_VOLTAGE_1P5V: {
                Pm_LL_SelectFvr2Voltage(PM_FVR_VOLTAGE_1P5V);
                break;
            }
            default: {
                Pm_LL_SelectFvr2Voltage(PM_FVR_VOLTAGE_1P5V);
                break;
            }
            }

            Pm_LL_SetFvrCaplessMode(true);
            Pm_LL_SetFvrCaplessEnabled(true);
        }
        else
        {
            /* do nothing */
        }

        Bkp_LL_PmRegisterHandleEnd();
    }
    else
    {
        /* do nothing */
    }
}

/**
 * @brief Perform Mcu Im SetBGMR
 *
 */
FUNC(void, MCU_CODE) Mcu_Im_SetBGMR(void)
{
    volatile uint32 intrState;
    volatile uint32 PM_CAL0_TMP, PM_CAL0_HLVL;

    /* Config the BKP area is enable, BKP register and data can be write and read */
    Bkp_LL_PmRegisterHandleStart();

    /**
     * read MR
     */
    intrState = Intr_LL_EnterCritical();
    PM_CAL0_TMP = Pm_LL_GetBGTRIMMRLDOValue();

    PM_CAL0_HLVL = PM_CAL0_TMP + 10U;
    if (PM_CAL0_HLVL > 0x1F)
        PM_CAL0_HLVL = 0x1F;

    /* Judge the value in Pm_LL_SetBGTRIMMRLDOValue */
    Pm_LL_SetBGTRIMMRLDOValue((uint8_t)PM_CAL0_HLVL);
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");

    /* enable psensor power*/
    GPIOA_PTR->POR.bits.PXPOR8 = 1;

    for (volatile uint32_t i = 0; i < 500u; i++)
    {
        asm("NOP");
        asm("NOP");
        asm("NOP");
        asm("NOP");
    }

    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");

    Pm_LL_SetBGTRIMMRLDOValue((uint8_t)PM_CAL0_TMP);

    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");

    Intr_LL_ExitCritical(intrState);
    Bkp_LL_PmRegisterHandleEnd();
}


/**
 * @brief Delay function.
 * @attention The Max delay time is 0xFFFFFFFFU / SCLK, in us.
 *  120MHz -- 35,791,394us (35.79s)
 *  72MHz -- 59,652,323us (59.65s)
 *  48MHz -- 89,478,485us (89.47s)
 * @attention The delay time is not accurate at short delay time, especially when it's less than 10 us.
 *
 * @param DelayTime Delay time in us.
 * @return void
 */
#define  MCU_SYSCLK_FREQ   120UL
FUNC(void, MCU_CODE) Mcu_Im_Delay(uint32 DelayTime)
{
    MCU_DEV_ASSERT(DelayTime != 0U);

    if (DelayTime > (0xFFFFFFFFU / MCU_SYSCLK_FREQ))
    {
        (void)Mcu_Im_NopDelay(MCU_SYSCLK_FREQ * (0xFFFFFFFFU / MCU_SYSCLK_FREQ));
    }
    else
    {
        (void)Mcu_Im_NopDelay(MCU_SYSCLK_FREQ * DelayTime);
    }
}
/* EOF */
