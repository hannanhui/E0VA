/*************************************************************************************/
/**
 * @file      : Tim_Pwm_Drv_PBcfg.c  
 * @brief     : Pwm low level driver - Post-Build(PB) configuration file code template 
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 2.0.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2025 Zhixin Semiconductor Ltd. All rights reserved.
 *************************************************************************************/
/** @addtogroup  Pwm_Module
 *  @{
 */

/** @addtogroup Tim_Pwm_Drv_Configuration
 *  @brief Pwm low level driver configuration
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Tim_Pwm_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define TIM_PWM_DRV_PBCFG_C_VENDOR_ID                   0x00B3U
#define TIM_PWM_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define TIM_PWM_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define TIM_PWM_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define TIM_PWM_DRV_PBCFG_C_SW_MAJOR_VERSION            2U
#define TIM_PWM_DRV_PBCFG_C_SW_MINOR_VERSION            0U
#define TIM_PWM_DRV_PBCFG_C_SW_PATCH_VERSION            0U

/* Check if source file and Tim_Pwm_Drv.h header file are of the same vendor */
#if (TIM_PWM_DRV_PBCFG_C_VENDOR_ID != TIM_PWM_DRV_H_VENDOR_ID)
    #error "Vendor IDs of Tim_Pwm_Drv_PBcfg.c and Tim_Pwm_Drv.h are different."
#endif

/* Check if source file and Tim_Pwm_Drv.h header file are of the same AUTOSAR version */
#if ((TIM_PWM_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION    != TIM_PWM_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (TIM_PWM_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION    != TIM_PWM_DRV_H_AR_RELEASE_MINOR_VERSION) || \
     (TIM_PWM_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION != TIM_PWM_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Tim_Pwm_Drv_PBcfg.c and Tim_Pwm_Drv.h are different."
#endif

/* Check if source file and Tim_Pwm_Drv.h header file are of the same software version */
#if ((TIM_PWM_DRV_PBCFG_C_SW_MAJOR_VERSION != TIM_PWM_DRV_H_SW_MAJOR_VERSION) || \
     (TIM_PWM_DRV_PBCFG_C_SW_MINOR_VERSION != TIM_PWM_DRV_H_SW_MINOR_VERSION) || \
     (TIM_PWM_DRV_PBCFG_C_SW_PATCH_VERSION != TIM_PWM_DRV_H_SW_PATCH_VERSION))
    #error "Software version numbers of Tim_Pwm_Drv_PBcfg.c and Tim_Pwm_Drv.h are different."
#endif

/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"


#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

/** @} end of group Private_VariableDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

#ifndef TIM_PWM_IP_PRECOMPILE_SUPPORT
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

/**
 * @brief Defines Tim0 instance configuration.
 */
static const Tim_Pwm_Drv_ConfigType Tim_Pwm_Drv_Inst0_Cfg =
{
    .ClkSrc = TIM_PWM_DRV_CLK_SOURCE_SYSTEM, /*!< ClkSrc */ 
    .ClkDiv = TIM_PWM_DRV_CLK_DIVIDE_1, /*!< ClkDiv */
    .PwmPeriod = 65535U, /*!< PwmPeriod */
    .PwmCounterMode = TIM_PWM_DRV_COUNTING_UP, /*!< CounterMode */
    .DeadTimeDiv = TIM_PWM_DRV_CLK_DEADTIME_DIVIDE_1, /*!< DeadTimeDivider */
    .DeadTimeVal = 1U, /*!< DeadTimeValue */ 
    .InitTrigEn = (boolean)FALSE, /*!< InitTrigEn */ 
    .OverflowIrqEn = (boolean)TRUE, /*!< OverflowIrqEn */
    .OverflowCb = NULL_PTR /*!< FunctionCallback */ 
};
/**
 * @brief Defines Tim1 instance configuration.
 */
static const Tim_Pwm_Drv_ConfigType Tim_Pwm_Drv_Inst1_Cfg =
{
    .ClkSrc = TIM_PWM_DRV_CLK_SOURCE_SYSTEM, /*!< ClkSrc */ 
    .ClkDiv = TIM_PWM_DRV_CLK_DIVIDE_1, /*!< ClkDiv */
    .PwmPeriod = 65535U, /*!< PwmPeriod */
    .PwmCounterMode = TIM_PWM_DRV_COUNTING_UP, /*!< CounterMode */
    .DeadTimeDiv = TIM_PWM_DRV_CLK_DEADTIME_DIVIDE_1, /*!< DeadTimeDivider */
    .DeadTimeVal = 1U, /*!< DeadTimeValue */ 
    .InitTrigEn = (boolean)FALSE, /*!< InitTrigEn */ 
    .OverflowIrqEn = (boolean)TRUE, /*!< OverflowIrqEn */
    .OverflowCb = NULL_PTR /*!< FunctionCallback */ 
};
/**
 * @brief Defines Tim2 instance configuration.
 */
static const Tim_Pwm_Drv_ConfigType Tim_Pwm_Drv_Inst2_Cfg =
{
    .ClkSrc = TIM_PWM_DRV_CLK_SOURCE_SYSTEM, /*!< ClkSrc */ 
    .ClkDiv = TIM_PWM_DRV_CLK_DIVIDE_1, /*!< ClkDiv */
    .PwmPeriod = 65535U, /*!< PwmPeriod */
    .PwmCounterMode = TIM_PWM_DRV_COUNTING_UP, /*!< CounterMode */
    .DeadTimeDiv = TIM_PWM_DRV_CLK_DEADTIME_DIVIDE_1, /*!< DeadTimeDivider */
    .DeadTimeVal = 1U, /*!< DeadTimeValue */ 
    .InitTrigEn = (boolean)FALSE, /*!< InitTrigEn */ 
    .OverflowIrqEn = (boolean)TRUE, /*!< OverflowIrqEn */
    .OverflowCb = NULL_PTR /*!< FunctionCallback */ 
};
/**
 * @brief Defines Tim3 instance configuration.
 */
static const Tim_Pwm_Drv_ConfigType Tim_Pwm_Drv_Inst3_Cfg =
{
    .ClkSrc = TIM_PWM_DRV_CLK_SOURCE_SYSTEM, /*!< ClkSrc */ 
    .ClkDiv = TIM_PWM_DRV_CLK_DIVIDE_1, /*!< ClkDiv */
    .PwmPeriod = 65535U, /*!< PwmPeriod */
    .PwmCounterMode = TIM_PWM_DRV_COUNTING_UP, /*!< CounterMode */
    .DeadTimeDiv = TIM_PWM_DRV_CLK_DEADTIME_DIVIDE_1, /*!< DeadTimeDivider */
    .DeadTimeVal = 1U, /*!< DeadTimeValue */ 
    .InitTrigEn = (boolean)FALSE, /*!< InitTrigEn */ 
    .OverflowIrqEn = (boolean)TRUE, /*!< OverflowIrqEn */
    .OverflowCb = NULL_PTR /*!< FunctionCallback */ 
};


/**
 * @brief Defines Tim0 Channel0 Configuration List.
 */
const Tim_Pwm_Drv_ChannelConfigType Tim_Pwm_Drv_I0_Ch0_Cfg =
{
    .ChannelId = 0U, /*!< channelId */
    .ChIrqEn = (boolean)TRUE, /*!< ChIrqEn */
    .ChannelCb = NULL_PTR,
    .ChannelOutputEnable = (boolean)TRUE, /*!< chOutputEn */
    .Polarity = TIM_PWM_DRV_POL_HIGH,
    .ChannelMode = TIM_PWM_DRV_MODE_EDGE_ALIGNED, /*!< ChannelMode */
    .ChannelMatchTrigEnable = (boolean)TRUE, /*!< ChannelMatchTrigEnable*/
    .DmaEn = (boolean)FALSE, /*!< dmaEnable*/
    .PairCfg = NULL_PTR /*!< PairCfg */
};
/**
 * @brief Defines Tim0 Channel1 Configuration List.
 */
const Tim_Pwm_Drv_ChannelConfigType Tim_Pwm_Drv_I0_Ch1_Cfg =
{
    .ChannelId = 1U, /*!< channelId */
    .ChIrqEn = (boolean)TRUE, /*!< ChIrqEn */
    .ChannelCb = NULL_PTR,
    .ChannelOutputEnable = (boolean)TRUE, /*!< chOutputEn */
    .Polarity = TIM_PWM_DRV_POL_HIGH,
    .ChannelMode = TIM_PWM_DRV_MODE_EDGE_ALIGNED, /*!< ChannelMode */
    .ChannelMatchTrigEnable = (boolean)TRUE, /*!< ChannelMatchTrigEnable*/
    .DmaEn = (boolean)FALSE, /*!< dmaEnable*/
    .PairCfg = NULL_PTR /*!< PairCfg */
};
/**
 * @brief Defines Tim0 Channel2 Configuration List.
 */
const Tim_Pwm_Drv_ChannelConfigType Tim_Pwm_Drv_I0_Ch2_Cfg =
{
    .ChannelId = 2U, /*!< channelId */
    .ChIrqEn = (boolean)TRUE, /*!< ChIrqEn */
    .ChannelCb = NULL_PTR,
    .ChannelOutputEnable = (boolean)TRUE, /*!< chOutputEn */
    .Polarity = TIM_PWM_DRV_POL_HIGH,
    .ChannelMode = TIM_PWM_DRV_MODE_EDGE_ALIGNED, /*!< ChannelMode */
    .ChannelMatchTrigEnable = (boolean)TRUE, /*!< ChannelMatchTrigEnable*/
    .DmaEn = (boolean)FALSE, /*!< dmaEnable*/
    .PairCfg = NULL_PTR /*!< PairCfg */
};
/**
 * @brief Defines Tim0 Channel3 Configuration List.
 */
const Tim_Pwm_Drv_ChannelConfigType Tim_Pwm_Drv_I0_Ch3_Cfg =
{
    .ChannelId = 3U, /*!< channelId */
    .ChIrqEn = (boolean)TRUE, /*!< ChIrqEn */
    .ChannelCb = NULL_PTR,
    .ChannelOutputEnable = (boolean)TRUE, /*!< chOutputEn */
    .Polarity = TIM_PWM_DRV_POL_HIGH,
    .ChannelMode = TIM_PWM_DRV_MODE_EDGE_ALIGNED, /*!< ChannelMode */
    .ChannelMatchTrigEnable = (boolean)TRUE, /*!< ChannelMatchTrigEnable*/
    .DmaEn = (boolean)FALSE, /*!< dmaEnable*/
    .PairCfg = NULL_PTR /*!< PairCfg */
};
/**
 * @brief Defines Tim0 Channel4 Configuration List.
 */
const Tim_Pwm_Drv_ChannelConfigType Tim_Pwm_Drv_I0_Ch4_Cfg =
{
    .ChannelId = 4U, /*!< channelId */
    .ChIrqEn = (boolean)TRUE, /*!< ChIrqEn */
    .ChannelCb = NULL_PTR,
    .ChannelOutputEnable = (boolean)TRUE, /*!< chOutputEn */
    .Polarity = TIM_PWM_DRV_POL_HIGH,
    .ChannelMode = TIM_PWM_DRV_MODE_EDGE_ALIGNED, /*!< ChannelMode */
    .ChannelMatchTrigEnable = (boolean)TRUE, /*!< ChannelMatchTrigEnable*/
    .DmaEn = (boolean)FALSE, /*!< dmaEnable*/
    .PairCfg = NULL_PTR /*!< PairCfg */
};
/**
 * @brief Defines Tim0 Channel5 Configuration List.
 */
const Tim_Pwm_Drv_ChannelConfigType Tim_Pwm_Drv_I0_Ch5_Cfg =
{
    .ChannelId = 5U, /*!< channelId */
    .ChIrqEn = (boolean)TRUE, /*!< ChIrqEn */
    .ChannelCb = NULL_PTR,
    .ChannelOutputEnable = (boolean)TRUE, /*!< chOutputEn */
    .Polarity = TIM_PWM_DRV_POL_HIGH,
    .ChannelMode = TIM_PWM_DRV_MODE_EDGE_ALIGNED, /*!< ChannelMode */
    .ChannelMatchTrigEnable = (boolean)TRUE, /*!< ChannelMatchTrigEnable*/
    .DmaEn = (boolean)FALSE, /*!< dmaEnable*/
    .PairCfg = NULL_PTR /*!< PairCfg */
};
/**
 * @brief Defines Tim0 Channel6 Configuration List.
 */
const Tim_Pwm_Drv_ChannelConfigType Tim_Pwm_Drv_I0_Ch6_Cfg =
{
    .ChannelId = 6U, /*!< channelId */
    .ChIrqEn = (boolean)TRUE, /*!< ChIrqEn */
    .ChannelCb = NULL_PTR,
    .ChannelOutputEnable = (boolean)TRUE, /*!< chOutputEn */
    .Polarity = TIM_PWM_DRV_POL_HIGH,
    .ChannelMode = TIM_PWM_DRV_MODE_EDGE_ALIGNED, /*!< ChannelMode */
    .ChannelMatchTrigEnable = (boolean)TRUE, /*!< ChannelMatchTrigEnable*/
    .DmaEn = (boolean)FALSE, /*!< dmaEnable*/
    .PairCfg = NULL_PTR /*!< PairCfg */
};
/**
 * @brief Defines Tim0 Channel7 Configuration List.
 */
const Tim_Pwm_Drv_ChannelConfigType Tim_Pwm_Drv_I0_Ch7_Cfg =
{
    .ChannelId = 7U, /*!< channelId */
    .ChIrqEn = (boolean)TRUE, /*!< ChIrqEn */
    .ChannelCb = NULL_PTR,
    .ChannelOutputEnable = (boolean)TRUE, /*!< chOutputEn */
    .Polarity = TIM_PWM_DRV_POL_HIGH,
    .ChannelMode = TIM_PWM_DRV_MODE_EDGE_ALIGNED, /*!< ChannelMode */
    .ChannelMatchTrigEnable = (boolean)TRUE, /*!< ChannelMatchTrigEnable*/
    .DmaEn = (boolean)FALSE, /*!< dmaEnable*/
    .PairCfg = NULL_PTR /*!< PairCfg */
};
/**
 * @brief Defines Tim1 Channel0 Configuration List.
 */
const Tim_Pwm_Drv_ChannelConfigType Tim_Pwm_Drv_I1_Ch0_Cfg =
{
    .ChannelId = 0U, /*!< channelId */
    .ChIrqEn = (boolean)TRUE, /*!< ChIrqEn */
    .ChannelCb = NULL_PTR,
    .ChannelOutputEnable = (boolean)TRUE, /*!< chOutputEn */
    .Polarity = TIM_PWM_DRV_POL_HIGH,
    .ChannelMode = TIM_PWM_DRV_MODE_EDGE_ALIGNED, /*!< ChannelMode */
    .ChannelMatchTrigEnable = (boolean)TRUE, /*!< ChannelMatchTrigEnable*/
    .DmaEn = (boolean)FALSE, /*!< dmaEnable*/
    .PairCfg = NULL_PTR /*!< PairCfg */
};
/**
 * @brief Defines Tim1 Channel1 Configuration List.
 */
const Tim_Pwm_Drv_ChannelConfigType Tim_Pwm_Drv_I1_Ch1_Cfg =
{
    .ChannelId = 1U, /*!< channelId */
    .ChIrqEn = (boolean)TRUE, /*!< ChIrqEn */
    .ChannelCb = NULL_PTR,
    .ChannelOutputEnable = (boolean)TRUE, /*!< chOutputEn */
    .Polarity = TIM_PWM_DRV_POL_HIGH,
    .ChannelMode = TIM_PWM_DRV_MODE_EDGE_ALIGNED, /*!< ChannelMode */
    .ChannelMatchTrigEnable = (boolean)TRUE, /*!< ChannelMatchTrigEnable*/
    .DmaEn = (boolean)FALSE, /*!< dmaEnable*/
    .PairCfg = NULL_PTR /*!< PairCfg */
};
/**
 * @brief Defines Tim1 Channel2 Configuration List.
 */
const Tim_Pwm_Drv_ChannelConfigType Tim_Pwm_Drv_I1_Ch2_Cfg =
{
    .ChannelId = 2U, /*!< channelId */
    .ChIrqEn = (boolean)TRUE, /*!< ChIrqEn */
    .ChannelCb = NULL_PTR,
    .ChannelOutputEnable = (boolean)TRUE, /*!< chOutputEn */
    .Polarity = TIM_PWM_DRV_POL_HIGH,
    .ChannelMode = TIM_PWM_DRV_MODE_EDGE_ALIGNED, /*!< ChannelMode */
    .ChannelMatchTrigEnable = (boolean)TRUE, /*!< ChannelMatchTrigEnable*/
    .DmaEn = (boolean)FALSE, /*!< dmaEnable*/
    .PairCfg = NULL_PTR /*!< PairCfg */
};
/**
 * @brief Defines Tim1 Channel5 Configuration List.
 */
const Tim_Pwm_Drv_ChannelConfigType Tim_Pwm_Drv_I1_Ch5_Cfg =
{
    .ChannelId = 5U, /*!< channelId */
    .ChIrqEn = (boolean)TRUE, /*!< ChIrqEn */
    .ChannelCb = NULL_PTR,
    .ChannelOutputEnable = (boolean)TRUE, /*!< chOutputEn */
    .Polarity = TIM_PWM_DRV_POL_HIGH,
    .ChannelMode = TIM_PWM_DRV_MODE_EDGE_ALIGNED, /*!< ChannelMode */
    .ChannelMatchTrigEnable = (boolean)TRUE, /*!< ChannelMatchTrigEnable*/
    .DmaEn = (boolean)FALSE, /*!< dmaEnable*/
    .PairCfg = NULL_PTR /*!< PairCfg */
};
/**
 * @brief Defines Tim1 Channel6 Configuration List.
 */
const Tim_Pwm_Drv_ChannelConfigType Tim_Pwm_Drv_I1_Ch6_Cfg =
{
    .ChannelId = 6U, /*!< channelId */
    .ChIrqEn = (boolean)TRUE, /*!< ChIrqEn */
    .ChannelCb = NULL_PTR,
    .ChannelOutputEnable = (boolean)TRUE, /*!< chOutputEn */
    .Polarity = TIM_PWM_DRV_POL_HIGH,
    .ChannelMode = TIM_PWM_DRV_MODE_EDGE_ALIGNED, /*!< ChannelMode */
    .ChannelMatchTrigEnable = (boolean)TRUE, /*!< ChannelMatchTrigEnable*/
    .DmaEn = (boolean)FALSE, /*!< dmaEnable*/
    .PairCfg = NULL_PTR /*!< PairCfg */
};
/**
 * @brief Defines Tim2 Channel2 Configuration List.
 */
const Tim_Pwm_Drv_ChannelConfigType Tim_Pwm_Drv_I2_Ch2_Cfg =
{
    .ChannelId = 2U, /*!< channelId */
    .ChIrqEn = (boolean)TRUE, /*!< ChIrqEn */
    .ChannelCb = NULL_PTR,
    .ChannelOutputEnable = (boolean)TRUE, /*!< chOutputEn */
    .Polarity = TIM_PWM_DRV_POL_HIGH,
    .ChannelMode = TIM_PWM_DRV_MODE_EDGE_ALIGNED, /*!< ChannelMode */
    .ChannelMatchTrigEnable = (boolean)TRUE, /*!< ChannelMatchTrigEnable*/
    .DmaEn = (boolean)FALSE, /*!< dmaEnable*/
    .PairCfg = NULL_PTR /*!< PairCfg */
};
/**
 * @brief Defines Tim2 Channel3 Configuration List.
 */
const Tim_Pwm_Drv_ChannelConfigType Tim_Pwm_Drv_I2_Ch3_Cfg =
{
    .ChannelId = 3U, /*!< channelId */
    .ChIrqEn = (boolean)TRUE, /*!< ChIrqEn */
    .ChannelCb = NULL_PTR,
    .ChannelOutputEnable = (boolean)TRUE, /*!< chOutputEn */
    .Polarity = TIM_PWM_DRV_POL_HIGH,
    .ChannelMode = TIM_PWM_DRV_MODE_EDGE_ALIGNED, /*!< ChannelMode */
    .ChannelMatchTrigEnable = (boolean)TRUE, /*!< ChannelMatchTrigEnable*/
    .DmaEn = (boolean)FALSE, /*!< dmaEnable*/
    .PairCfg = NULL_PTR /*!< PairCfg */
};
/**
 * @brief Defines Tim2 Channel4 Configuration List.
 */
const Tim_Pwm_Drv_ChannelConfigType Tim_Pwm_Drv_I2_Ch4_Cfg =
{
    .ChannelId = 4U, /*!< channelId */
    .ChIrqEn = (boolean)TRUE, /*!< ChIrqEn */
    .ChannelCb = NULL_PTR,
    .ChannelOutputEnable = (boolean)TRUE, /*!< chOutputEn */
    .Polarity = TIM_PWM_DRV_POL_HIGH,
    .ChannelMode = TIM_PWM_DRV_MODE_EDGE_ALIGNED, /*!< ChannelMode */
    .ChannelMatchTrigEnable = (boolean)TRUE, /*!< ChannelMatchTrigEnable*/
    .DmaEn = (boolean)FALSE, /*!< dmaEnable*/
    .PairCfg = NULL_PTR /*!< PairCfg */
};
/**
 * @brief Defines Tim2 Channel6 Configuration List.
 */
const Tim_Pwm_Drv_ChannelConfigType Tim_Pwm_Drv_I2_Ch6_Cfg =
{
    .ChannelId = 6U, /*!< channelId */
    .ChIrqEn = (boolean)TRUE, /*!< ChIrqEn */
    .ChannelCb = NULL_PTR,
    .ChannelOutputEnable = (boolean)TRUE, /*!< chOutputEn */
    .Polarity = TIM_PWM_DRV_POL_HIGH,
    .ChannelMode = TIM_PWM_DRV_MODE_EDGE_ALIGNED, /*!< ChannelMode */
    .ChannelMatchTrigEnable = (boolean)TRUE, /*!< ChannelMatchTrigEnable*/
    .DmaEn = (boolean)FALSE, /*!< dmaEnable*/
    .PairCfg = NULL_PTR /*!< PairCfg */
};
/**
 * @brief Defines Tim2 Channel7 Configuration List.
 */
const Tim_Pwm_Drv_ChannelConfigType Tim_Pwm_Drv_I2_Ch7_Cfg =
{
    .ChannelId = 7U, /*!< channelId */
    .ChIrqEn = (boolean)TRUE, /*!< ChIrqEn */
    .ChannelCb = NULL_PTR,
    .ChannelOutputEnable = (boolean)TRUE, /*!< chOutputEn */
    .Polarity = TIM_PWM_DRV_POL_HIGH,
    .ChannelMode = TIM_PWM_DRV_MODE_EDGE_ALIGNED, /*!< ChannelMode */
    .ChannelMatchTrigEnable = (boolean)TRUE, /*!< ChannelMatchTrigEnable*/
    .DmaEn = (boolean)FALSE, /*!< dmaEnable*/
    .PairCfg = NULL_PTR /*!< PairCfg */
};
/**
 * @brief Defines Tim3 Channel0 Configuration List.
 */
const Tim_Pwm_Drv_ChannelConfigType Tim_Pwm_Drv_I3_Ch0_Cfg =
{
    .ChannelId = 0U, /*!< channelId */
    .ChIrqEn = (boolean)TRUE, /*!< ChIrqEn */
    .ChannelCb = NULL_PTR,
    .ChannelOutputEnable = (boolean)TRUE, /*!< chOutputEn */
    .Polarity = TIM_PWM_DRV_POL_HIGH,
    .ChannelMode = TIM_PWM_DRV_MODE_EDGE_ALIGNED, /*!< ChannelMode */
    .ChannelMatchTrigEnable = (boolean)TRUE, /*!< ChannelMatchTrigEnable*/
    .DmaEn = (boolean)FALSE, /*!< dmaEnable*/
    .PairCfg = NULL_PTR /*!< PairCfg */
};
/**
 * @brief Defines Tim3 Channel1 Configuration List.
 */
const Tim_Pwm_Drv_ChannelConfigType Tim_Pwm_Drv_I3_Ch1_Cfg =
{
    .ChannelId = 1U, /*!< channelId */
    .ChIrqEn = (boolean)TRUE, /*!< ChIrqEn */
    .ChannelCb = NULL_PTR,
    .ChannelOutputEnable = (boolean)TRUE, /*!< chOutputEn */
    .Polarity = TIM_PWM_DRV_POL_HIGH,
    .ChannelMode = TIM_PWM_DRV_MODE_EDGE_ALIGNED, /*!< ChannelMode */
    .ChannelMatchTrigEnable = (boolean)TRUE, /*!< ChannelMatchTrigEnable*/
    .DmaEn = (boolean)FALSE, /*!< dmaEnable*/
    .PairCfg = NULL_PTR /*!< PairCfg */
};
/**
 * @brief Defines Tim3 Channel2 Configuration List.
 */
const Tim_Pwm_Drv_ChannelConfigType Tim_Pwm_Drv_I3_Ch2_Cfg =
{
    .ChannelId = 2U, /*!< channelId */
    .ChIrqEn = (boolean)TRUE, /*!< ChIrqEn */
    .ChannelCb = NULL_PTR,
    .ChannelOutputEnable = (boolean)TRUE, /*!< chOutputEn */
    .Polarity = TIM_PWM_DRV_POL_HIGH,
    .ChannelMode = TIM_PWM_DRV_MODE_EDGE_ALIGNED, /*!< ChannelMode */
    .ChannelMatchTrigEnable = (boolean)TRUE, /*!< ChannelMatchTrigEnable*/
    .DmaEn = (boolean)FALSE, /*!< dmaEnable*/
    .PairCfg = NULL_PTR /*!< PairCfg */
};
/**
 * @brief Defines Tim3 Channel4 Configuration List.
 */
const Tim_Pwm_Drv_ChannelConfigType Tim_Pwm_Drv_I3_Ch4_Cfg =
{
    .ChannelId = 4U, /*!< channelId */
    .ChIrqEn = (boolean)TRUE, /*!< ChIrqEn */
    .ChannelCb = NULL_PTR,
    .ChannelOutputEnable = (boolean)TRUE, /*!< chOutputEn */
    .Polarity = TIM_PWM_DRV_POL_HIGH,
    .ChannelMode = TIM_PWM_DRV_MODE_EDGE_ALIGNED, /*!< ChannelMode */
    .ChannelMatchTrigEnable = (boolean)TRUE, /*!< ChannelMatchTrigEnable*/
    .DmaEn = (boolean)FALSE, /*!< dmaEnable*/
    .PairCfg = NULL_PTR /*!< PairCfg */
};
/**
 * @brief Defines Tim3 Channel5 Configuration List.
 */
const Tim_Pwm_Drv_ChannelConfigType Tim_Pwm_Drv_I3_Ch5_Cfg =
{
    .ChannelId = 5U, /*!< channelId */
    .ChIrqEn = (boolean)TRUE, /*!< ChIrqEn */
    .ChannelCb = NULL_PTR,
    .ChannelOutputEnable = (boolean)TRUE, /*!< chOutputEn */
    .Polarity = TIM_PWM_DRV_POL_HIGH,
    .ChannelMode = TIM_PWM_DRV_MODE_EDGE_ALIGNED, /*!< ChannelMode */
    .ChannelMatchTrigEnable = (boolean)TRUE, /*!< ChannelMatchTrigEnable*/
    .DmaEn = (boolean)FALSE, /*!< dmaEnable*/
    .PairCfg = NULL_PTR /*!< PairCfg */
};
/**
 * @brief Defines Tim3 Channel6 Configuration List.
 */
const Tim_Pwm_Drv_ChannelConfigType Tim_Pwm_Drv_I3_Ch6_Cfg =
{
    .ChannelId = 6U, /*!< channelId */
    .ChIrqEn = (boolean)TRUE, /*!< ChIrqEn */
    .ChannelCb = NULL_PTR,
    .ChannelOutputEnable = (boolean)TRUE, /*!< chOutputEn */
    .Polarity = TIM_PWM_DRV_POL_HIGH,
    .ChannelMode = TIM_PWM_DRV_MODE_EDGE_ALIGNED, /*!< ChannelMode */
    .ChannelMatchTrigEnable = (boolean)TRUE, /*!< ChannelMatchTrigEnable*/
    .DmaEn = (boolean)FALSE, /*!< dmaEnable*/
    .PairCfg = NULL_PTR /*!< PairCfg */
};
/**
 * @brief Defines Tim3 Channel7 Configuration List.
 */
const Tim_Pwm_Drv_ChannelConfigType Tim_Pwm_Drv_I3_Ch7_Cfg =
{
    .ChannelId = 7U, /*!< channelId */
    .ChIrqEn = (boolean)TRUE, /*!< ChIrqEn */
    .ChannelCb = NULL_PTR,
    .ChannelOutputEnable = (boolean)TRUE, /*!< chOutputEn */
    .Polarity = TIM_PWM_DRV_POL_HIGH,
    .ChannelMode = TIM_PWM_DRV_MODE_EDGE_ALIGNED, /*!< ChannelMode */
    .ChannelMatchTrigEnable = (boolean)TRUE, /*!< ChannelMatchTrigEnable*/
    .DmaEn = (boolean)FALSE, /*!< dmaEnable*/
    .PairCfg = NULL_PTR /*!< PairCfg */
};

/**
 * @brief Defines Tim0 All Channels Configuration List.
 */
static const Tim_Pwm_Drv_ChannelConfigType * const Tim_Pwm_Drv_I0_ChArrayPtr[8U] =
{
    &Tim_Pwm_Drv_I0_Ch0_Cfg,
    &Tim_Pwm_Drv_I0_Ch1_Cfg,
    &Tim_Pwm_Drv_I0_Ch2_Cfg,
    &Tim_Pwm_Drv_I0_Ch3_Cfg,
    &Tim_Pwm_Drv_I0_Ch4_Cfg,
    &Tim_Pwm_Drv_I0_Ch5_Cfg,
    &Tim_Pwm_Drv_I0_Ch6_Cfg,
    &Tim_Pwm_Drv_I0_Ch7_Cfg
};
/**
 * @brief Defines Tim1 All Channels Configuration List.
 */
static const Tim_Pwm_Drv_ChannelConfigType * const Tim_Pwm_Drv_I1_ChArrayPtr[5U] =
{
    &Tim_Pwm_Drv_I1_Ch0_Cfg,
    &Tim_Pwm_Drv_I1_Ch1_Cfg,
    &Tim_Pwm_Drv_I1_Ch2_Cfg,
    &Tim_Pwm_Drv_I1_Ch5_Cfg,
    &Tim_Pwm_Drv_I1_Ch6_Cfg
};
/**
 * @brief Defines Tim2 All Channels Configuration List.
 */
static const Tim_Pwm_Drv_ChannelConfigType * const Tim_Pwm_Drv_I2_ChArrayPtr[5U] =
{
    &Tim_Pwm_Drv_I2_Ch2_Cfg,
    &Tim_Pwm_Drv_I2_Ch3_Cfg,
    &Tim_Pwm_Drv_I2_Ch4_Cfg,
    &Tim_Pwm_Drv_I2_Ch6_Cfg,
    &Tim_Pwm_Drv_I2_Ch7_Cfg
};
/**
 * @brief Defines Tim3 All Channels Configuration List.
 */
static const Tim_Pwm_Drv_ChannelConfigType * const Tim_Pwm_Drv_I3_ChArrayPtr[7U] =
{
    &Tim_Pwm_Drv_I3_Ch0_Cfg,
    &Tim_Pwm_Drv_I3_Ch1_Cfg,
    &Tim_Pwm_Drv_I3_Ch2_Cfg,
    &Tim_Pwm_Drv_I3_Ch4_Cfg,
    &Tim_Pwm_Drv_I3_Ch5_Cfg,
    &Tim_Pwm_Drv_I3_Ch6_Cfg,
    &Tim_Pwm_Drv_I3_Ch7_Cfg
};

/**
 * @brief Defines Tim0 User Configuration.
 */
const Tim_Pwm_Drv_UserCfgType Tim_Pwm_Drv_User0_Cfg =
{
    .InstanceCfg = &Tim_Pwm_Drv_Inst0_Cfg, /*!< InstanceCfg */
    .ConfiguredChArray = Tim_Pwm_Drv_I0_ChArrayPtr, /*!< ConfiguredChArray */
    .NoOfConfiguredCh = 8U /*!< NoOfConfiguredCh */
};
/**
 * @brief Defines Tim1 User Configuration.
 */
const Tim_Pwm_Drv_UserCfgType Tim_Pwm_Drv_User1_Cfg =
{
    .InstanceCfg = &Tim_Pwm_Drv_Inst1_Cfg, /*!< InstanceCfg */
    .ConfiguredChArray = Tim_Pwm_Drv_I1_ChArrayPtr, /*!< ConfiguredChArray */
    .NoOfConfiguredCh = 5U /*!< NoOfConfiguredCh */
};
/**
 * @brief Defines Tim2 User Configuration.
 */
const Tim_Pwm_Drv_UserCfgType Tim_Pwm_Drv_User2_Cfg =
{
    .InstanceCfg = &Tim_Pwm_Drv_Inst2_Cfg, /*!< InstanceCfg */
    .ConfiguredChArray = Tim_Pwm_Drv_I2_ChArrayPtr, /*!< ConfiguredChArray */
    .NoOfConfiguredCh = 5U /*!< NoOfConfiguredCh */
};
/**
 * @brief Defines Tim3 User Configuration.
 */
const Tim_Pwm_Drv_UserCfgType Tim_Pwm_Drv_User3_Cfg =
{
    .InstanceCfg = &Tim_Pwm_Drv_Inst3_Cfg, /*!< InstanceCfg */
    .ConfiguredChArray = Tim_Pwm_Drv_I3_ChArrayPtr, /*!< ConfiguredChArray */
    .NoOfConfiguredCh = 7U /*!< NoOfConfiguredCh */
};


#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

#endif  /*TIM_PWM_DRV_PRECOMPILE_SUPPORT */

/** @} end of group Global_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */

/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Tim_Pwm_Drv_Configuration */

/** @} end of group Pwm_Module */
