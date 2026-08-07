/*************************************************************************************/
/**
 * @file      : Pwm_Drvw_PBcfg.c  
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

/** @addtogroup Pwm_Drvw_Configuration
 *  @brief Pwm low level driver configuration
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Pwm_Drvw.h"
#include "Mcpwm_Pwm_Drv.h"
#include "Tim_Pwm_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define PWM_DRVW_PBCFG_C_VENDOR_ID                   0x00B3U
#define PWM_DRVW_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define PWM_DRVW_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define PWM_DRVW_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define PWM_DRVW_PBCFG_C_SW_MAJOR_VERSION            2U
#define PWM_DRVW_PBCFG_C_SW_MINOR_VERSION            0U
#define PWM_DRVW_PBCFG_C_SW_PATCH_VERSION            0U

/* Check if source file and Pwm_Drvw.h header file are the same vendor */
#if (PWM_DRVW_PBCFG_C_VENDOR_ID != PWM_DRVW_H_VENDOR_ID)
    #error "Vendor IDs of Pwm_Drvw_PBcfg.c and Pwm_Drvw.h are different."
#endif

/* Check if source file and Pwm_Drvw.h header file are the same AUTOSAR version */
#if ((PWM_DRVW_PBCFG_C_AR_RELEASE_MAJOR_VERSION    != PWM_DRVW_H_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_DRVW_PBCFG_C_AR_RELEASE_MINOR_VERSION    != PWM_DRVW_H_AR_RELEASE_MINOR_VERSION) || \
     (PWM_DRVW_PBCFG_C_AR_RELEASE_REVISION_VERSION != PWM_DRVW_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar version numbers of Pwm_Drvw_PBcfg.c and Pwm_Drvw.h are different."
#endif

/* Check if source file and Pwm_Drvw.h header file are of the same software version */
#if ((PWM_DRVW_PBCFG_C_SW_MAJOR_VERSION != PWM_DRVW_H_SW_MAJOR_VERSION) || \
     (PWM_DRVW_PBCFG_C_SW_MINOR_VERSION != PWM_DRVW_H_SW_MINOR_VERSION) || \
     (PWM_DRVW_PBCFG_C_SW_PATCH_VERSION != PWM_DRVW_H_SW_PATCH_VERSION))
    #error "Software version numbers of Pwm_Drvw_PBcfg.c and Pwm_Drvw.h are different."
#endif

/* Check if source file and Mcpwm_Pwm_Drv.h header file are the same vendor */
#if (PWM_DRVW_PBCFG_C_VENDOR_ID != MCPWM_PWM_DRV_H_VENDOR_ID)
    #error "Vendor IDs of Pwm_Drvw_PBcfg.c and Mcpwm_Pwm_Drv.h are different."
#endif

/* Check if source file and Mcpwm_Pwm_Drv.h header file are the same AUTOSAR version */
#if ((PWM_DRVW_PBCFG_C_AR_RELEASE_MAJOR_VERSION    != MCPWM_PWM_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_DRVW_PBCFG_C_AR_RELEASE_MINOR_VERSION    != MCPWM_PWM_DRV_H_AR_RELEASE_MINOR_VERSION) || \
     (PWM_DRVW_PBCFG_C_AR_RELEASE_REVISION_VERSION != MCPWM_PWM_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar version numbers of Pwm_Drvw_PBcfg.c and Mcpwm_Pwm_Drv.h are different."
#endif

/* Check if source file and Mcpwm_Pwm_Drv.h header file are of the same software version */
#if ((PWM_DRVW_PBCFG_C_SW_MAJOR_VERSION != MCPWM_PWM_DRV_H_SW_MAJOR_VERSION) || \
     (PWM_DRVW_PBCFG_C_SW_MINOR_VERSION != MCPWM_PWM_DRV_H_SW_MINOR_VERSION) || \
     (PWM_DRVW_PBCFG_C_SW_PATCH_VERSION != MCPWM_PWM_DRV_H_SW_PATCH_VERSION))
    #error "Software version numbers of Pwm_Drvw_PBcfg.c and Mcpwm_Pwm_Drv.h are different."
#endif

/* Check if source file and Tim_Pwm_Drv.h header file are the same vendor */
#if (PWM_DRVW_PBCFG_C_VENDOR_ID != TIM_PWM_DRV_H_VENDOR_ID)
    #error "Vendor IDs of Pwm_Drvw_PBcfg.c and Tim_Pwm_Drv.h are different."
#endif

/* Check if source file and Tim_Pwm_Drv.h header file are the same AUTOSAR version */
#if ((PWM_DRVW_PBCFG_C_AR_RELEASE_MAJOR_VERSION    != TIM_PWM_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_DRVW_PBCFG_C_AR_RELEASE_MINOR_VERSION    != TIM_PWM_DRV_H_AR_RELEASE_MINOR_VERSION) || \
     (PWM_DRVW_PBCFG_C_AR_RELEASE_REVISION_VERSION != TIM_PWM_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar version numbers of Pwm_Drvw_PBcfg.c and Tim_Pwm_Drv.h are different."
#endif

/* Check if source file and Tim_Pwm_Drv.h header file are of the same software version */
#if ((PWM_DRVW_PBCFG_C_SW_MAJOR_VERSION != TIM_PWM_DRV_H_SW_MAJOR_VERSION) || \
     (PWM_DRVW_PBCFG_C_SW_MINOR_VERSION != TIM_PWM_DRV_H_SW_MINOR_VERSION) || \
     (PWM_DRVW_PBCFG_C_SW_PATCH_VERSION != TIM_PWM_DRV_H_SW_PATCH_VERSION))
    #error "Software version numbers of Pwm_Drvw_PBcfg.c and Tim_Pwm_Drv.h are different."
#endif

/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */

/** @} end of group Private_VariableDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

#ifndef PWM_DRVW_PRECOMPILE_SUPPORT
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

/**
 * @brief Defines Pwm All Instances Configuration List.
 */
const Pwm_Drvw_HwConfigType Pwm_Instances[PWM_DRVW_PB_CFG_INSTANCES_COUNT] =
{
    /* Tim0 */
    {
        .HwId = 0U, /*!< The Id module configured */     
        .HwType = PWM_DRVW_HW_TIM, /*!< The type of module configured */
        .McpwmHwConfig = NULL_PTR, /*!< Pointer to the Mcpwm instance configuration structure */     
        .TimHwConfig = &Tim_Pwm_Drv_User0_Cfg /*!< Pointer to the Tim configuration structure */
    },
    /* Tim1 */
    {
        .HwId = 1U, /*!< The Id module configured */     
        .HwType = PWM_DRVW_HW_TIM, /*!< The type of module configured */
        .McpwmHwConfig = NULL_PTR, /*!< Pointer to the Mcpwm instance configuration structure */     
        .TimHwConfig = &Tim_Pwm_Drv_User1_Cfg /*!< Pointer to the Tim configuration structure */
    },
    /* Tim2 */
    {
        .HwId = 2U, /*!< The Id module configured */     
        .HwType = PWM_DRVW_HW_TIM, /*!< The type of module configured */
        .McpwmHwConfig = NULL_PTR, /*!< Pointer to the Mcpwm instance configuration structure */     
        .TimHwConfig = &Tim_Pwm_Drv_User2_Cfg /*!< Pointer to the Tim configuration structure */
    },
    /* Tim3 */
    {
        .HwId = 3U, /*!< The Id module configured */     
        .HwType = PWM_DRVW_HW_TIM, /*!< The type of module configured */
        .McpwmHwConfig = NULL_PTR, /*!< Pointer to the Mcpwm instance configuration structure */     
        .TimHwConfig = &Tim_Pwm_Drv_User3_Cfg /*!< Pointer to the Tim configuration structure */
    }
};


const Pwm_Drvw_ChannelConfigType Pwm_Drvw_Ch0_Config =
{
    .ChnHwId = (Pwm_Drvw_ModuleType)TIM_PWM_DRV_I2_CH7_CFG, /*!< Hardware Channel Instance ID */             
    .ChnHwType = PWM_DRVW_HW_TIM, /*!< Hardware Channel Type */
    .ChannelDutyCycle = 0U, /*!< The duty cycle of this channel */
    .McpwmChConfig = NULL_PTR, /*!< Mcpwm Channel Configuration Pointer */
    .TimChConfig = &Tim_Pwm_Drv_I2_Ch7_Cfg /*!< Tim Channel Configuration Pointer */  
};
const Pwm_Drvw_ChannelConfigType Pwm_Drvw_Ch1_Config =
{
    .ChnHwId = (Pwm_Drvw_ModuleType)TIM_PWM_DRV_I2_CH6_CFG, /*!< Hardware Channel Instance ID */             
    .ChnHwType = PWM_DRVW_HW_TIM, /*!< Hardware Channel Type */
    .ChannelDutyCycle = 0U, /*!< The duty cycle of this channel */
    .McpwmChConfig = NULL_PTR, /*!< Mcpwm Channel Configuration Pointer */
    .TimChConfig = &Tim_Pwm_Drv_I2_Ch6_Cfg /*!< Tim Channel Configuration Pointer */  
};
const Pwm_Drvw_ChannelConfigType Pwm_Drvw_Ch2_Config =
{
    .ChnHwId = (Pwm_Drvw_ModuleType)TIM_PWM_DRV_I0_CH3_CFG, /*!< Hardware Channel Instance ID */             
    .ChnHwType = PWM_DRVW_HW_TIM, /*!< Hardware Channel Type */
    .ChannelDutyCycle = 0U, /*!< The duty cycle of this channel */
    .McpwmChConfig = NULL_PTR, /*!< Mcpwm Channel Configuration Pointer */
    .TimChConfig = &Tim_Pwm_Drv_I0_Ch3_Cfg /*!< Tim Channel Configuration Pointer */  
};
const Pwm_Drvw_ChannelConfigType Pwm_Drvw_Ch3_Config =
{
    .ChnHwId = (Pwm_Drvw_ModuleType)TIM_PWM_DRV_I0_CH2_CFG, /*!< Hardware Channel Instance ID */             
    .ChnHwType = PWM_DRVW_HW_TIM, /*!< Hardware Channel Type */
    .ChannelDutyCycle = 0U, /*!< The duty cycle of this channel */
    .McpwmChConfig = NULL_PTR, /*!< Mcpwm Channel Configuration Pointer */
    .TimChConfig = &Tim_Pwm_Drv_I0_Ch2_Cfg /*!< Tim Channel Configuration Pointer */  
};
const Pwm_Drvw_ChannelConfigType Pwm_Drvw_Ch4_Config =
{
    .ChnHwId = (Pwm_Drvw_ModuleType)TIM_PWM_DRV_I2_CH4_CFG, /*!< Hardware Channel Instance ID */             
    .ChnHwType = PWM_DRVW_HW_TIM, /*!< Hardware Channel Type */
    .ChannelDutyCycle = 0U, /*!< The duty cycle of this channel */
    .McpwmChConfig = NULL_PTR, /*!< Mcpwm Channel Configuration Pointer */
    .TimChConfig = &Tim_Pwm_Drv_I2_Ch4_Cfg /*!< Tim Channel Configuration Pointer */  
};
const Pwm_Drvw_ChannelConfigType Pwm_Drvw_Ch5_Config =
{
    .ChnHwId = (Pwm_Drvw_ModuleType)TIM_PWM_DRV_I0_CH1_CFG, /*!< Hardware Channel Instance ID */             
    .ChnHwType = PWM_DRVW_HW_TIM, /*!< Hardware Channel Type */
    .ChannelDutyCycle = 0U, /*!< The duty cycle of this channel */
    .McpwmChConfig = NULL_PTR, /*!< Mcpwm Channel Configuration Pointer */
    .TimChConfig = &Tim_Pwm_Drv_I0_Ch1_Cfg /*!< Tim Channel Configuration Pointer */  
};
const Pwm_Drvw_ChannelConfigType Pwm_Drvw_Ch6_Config =
{
    .ChnHwId = (Pwm_Drvw_ModuleType)TIM_PWM_DRV_I0_CH0_CFG, /*!< Hardware Channel Instance ID */             
    .ChnHwType = PWM_DRVW_HW_TIM, /*!< Hardware Channel Type */
    .ChannelDutyCycle = 0U, /*!< The duty cycle of this channel */
    .McpwmChConfig = NULL_PTR, /*!< Mcpwm Channel Configuration Pointer */
    .TimChConfig = &Tim_Pwm_Drv_I0_Ch0_Cfg /*!< Tim Channel Configuration Pointer */  
};
const Pwm_Drvw_ChannelConfigType Pwm_Drvw_Ch7_Config =
{
    .ChnHwId = (Pwm_Drvw_ModuleType)TIM_PWM_DRV_I0_CH7_CFG, /*!< Hardware Channel Instance ID */             
    .ChnHwType = PWM_DRVW_HW_TIM, /*!< Hardware Channel Type */
    .ChannelDutyCycle = 0U, /*!< The duty cycle of this channel */
    .McpwmChConfig = NULL_PTR, /*!< Mcpwm Channel Configuration Pointer */
    .TimChConfig = &Tim_Pwm_Drv_I0_Ch7_Cfg /*!< Tim Channel Configuration Pointer */  
};
const Pwm_Drvw_ChannelConfigType Pwm_Drvw_Ch8_Config =
{
    .ChnHwId = (Pwm_Drvw_ModuleType)TIM_PWM_DRV_I0_CH6_CFG, /*!< Hardware Channel Instance ID */             
    .ChnHwType = PWM_DRVW_HW_TIM, /*!< Hardware Channel Type */
    .ChannelDutyCycle = 0U, /*!< The duty cycle of this channel */
    .McpwmChConfig = NULL_PTR, /*!< Mcpwm Channel Configuration Pointer */
    .TimChConfig = &Tim_Pwm_Drv_I0_Ch6_Cfg /*!< Tim Channel Configuration Pointer */  
};
const Pwm_Drvw_ChannelConfigType Pwm_Drvw_Ch9_Config =
{
    .ChnHwId = (Pwm_Drvw_ModuleType)TIM_PWM_DRV_I0_CH5_CFG, /*!< Hardware Channel Instance ID */             
    .ChnHwType = PWM_DRVW_HW_TIM, /*!< Hardware Channel Type */
    .ChannelDutyCycle = 0U, /*!< The duty cycle of this channel */
    .McpwmChConfig = NULL_PTR, /*!< Mcpwm Channel Configuration Pointer */
    .TimChConfig = &Tim_Pwm_Drv_I0_Ch5_Cfg /*!< Tim Channel Configuration Pointer */  
};
const Pwm_Drvw_ChannelConfigType Pwm_Drvw_Ch10_Config =
{
    .ChnHwId = (Pwm_Drvw_ModuleType)TIM_PWM_DRV_I0_CH4_CFG, /*!< Hardware Channel Instance ID */             
    .ChnHwType = PWM_DRVW_HW_TIM, /*!< Hardware Channel Type */
    .ChannelDutyCycle = 0U, /*!< The duty cycle of this channel */
    .McpwmChConfig = NULL_PTR, /*!< Mcpwm Channel Configuration Pointer */
    .TimChConfig = &Tim_Pwm_Drv_I0_Ch4_Cfg /*!< Tim Channel Configuration Pointer */  
};
const Pwm_Drvw_ChannelConfigType Pwm_Drvw_Ch11_Config =
{
    .ChnHwId = (Pwm_Drvw_ModuleType)TIM_PWM_DRV_I2_CH3_CFG, /*!< Hardware Channel Instance ID */             
    .ChnHwType = PWM_DRVW_HW_TIM, /*!< Hardware Channel Type */
    .ChannelDutyCycle = 0U, /*!< The duty cycle of this channel */
    .McpwmChConfig = NULL_PTR, /*!< Mcpwm Channel Configuration Pointer */
    .TimChConfig = &Tim_Pwm_Drv_I2_Ch3_Cfg /*!< Tim Channel Configuration Pointer */  
};
const Pwm_Drvw_ChannelConfigType Pwm_Drvw_Ch12_Config =
{
    .ChnHwId = (Pwm_Drvw_ModuleType)TIM_PWM_DRV_I2_CH2_CFG, /*!< Hardware Channel Instance ID */             
    .ChnHwType = PWM_DRVW_HW_TIM, /*!< Hardware Channel Type */
    .ChannelDutyCycle = 0U, /*!< The duty cycle of this channel */
    .McpwmChConfig = NULL_PTR, /*!< Mcpwm Channel Configuration Pointer */
    .TimChConfig = &Tim_Pwm_Drv_I2_Ch2_Cfg /*!< Tim Channel Configuration Pointer */  
};
const Pwm_Drvw_ChannelConfigType Pwm_Drvw_Ch13_Config =
{
    .ChnHwId = (Pwm_Drvw_ModuleType)TIM_PWM_DRV_I1_CH2_CFG, /*!< Hardware Channel Instance ID */             
    .ChnHwType = PWM_DRVW_HW_TIM, /*!< Hardware Channel Type */
    .ChannelDutyCycle = 0U, /*!< The duty cycle of this channel */
    .McpwmChConfig = NULL_PTR, /*!< Mcpwm Channel Configuration Pointer */
    .TimChConfig = &Tim_Pwm_Drv_I1_Ch2_Cfg /*!< Tim Channel Configuration Pointer */  
};
const Pwm_Drvw_ChannelConfigType Pwm_Drvw_Ch14_Config =
{
    .ChnHwId = (Pwm_Drvw_ModuleType)TIM_PWM_DRV_I1_CH1_CFG, /*!< Hardware Channel Instance ID */             
    .ChnHwType = PWM_DRVW_HW_TIM, /*!< Hardware Channel Type */
    .ChannelDutyCycle = 0U, /*!< The duty cycle of this channel */
    .McpwmChConfig = NULL_PTR, /*!< Mcpwm Channel Configuration Pointer */
    .TimChConfig = &Tim_Pwm_Drv_I1_Ch1_Cfg /*!< Tim Channel Configuration Pointer */  
};
const Pwm_Drvw_ChannelConfigType Pwm_Drvw_Ch15_Config =
{
    .ChnHwId = (Pwm_Drvw_ModuleType)TIM_PWM_DRV_I1_CH0_CFG, /*!< Hardware Channel Instance ID */             
    .ChnHwType = PWM_DRVW_HW_TIM, /*!< Hardware Channel Type */
    .ChannelDutyCycle = 0U, /*!< The duty cycle of this channel */
    .McpwmChConfig = NULL_PTR, /*!< Mcpwm Channel Configuration Pointer */
    .TimChConfig = &Tim_Pwm_Drv_I1_Ch0_Cfg /*!< Tim Channel Configuration Pointer */  
};
const Pwm_Drvw_ChannelConfigType Pwm_Drvw_Ch16_Config =
{
    .ChnHwId = (Pwm_Drvw_ModuleType)TIM_PWM_DRV_I3_CH7_CFG, /*!< Hardware Channel Instance ID */             
    .ChnHwType = PWM_DRVW_HW_TIM, /*!< Hardware Channel Type */
    .ChannelDutyCycle = 0U, /*!< The duty cycle of this channel */
    .McpwmChConfig = NULL_PTR, /*!< Mcpwm Channel Configuration Pointer */
    .TimChConfig = &Tim_Pwm_Drv_I3_Ch7_Cfg /*!< Tim Channel Configuration Pointer */  
};
const Pwm_Drvw_ChannelConfigType Pwm_Drvw_Ch17_Config =
{
    .ChnHwId = (Pwm_Drvw_ModuleType)TIM_PWM_DRV_I3_CH6_CFG, /*!< Hardware Channel Instance ID */             
    .ChnHwType = PWM_DRVW_HW_TIM, /*!< Hardware Channel Type */
    .ChannelDutyCycle = 0U, /*!< The duty cycle of this channel */
    .McpwmChConfig = NULL_PTR, /*!< Mcpwm Channel Configuration Pointer */
    .TimChConfig = &Tim_Pwm_Drv_I3_Ch6_Cfg /*!< Tim Channel Configuration Pointer */  
};
const Pwm_Drvw_ChannelConfigType Pwm_Drvw_Ch18_Config =
{
    .ChnHwId = (Pwm_Drvw_ModuleType)TIM_PWM_DRV_I3_CH5_CFG, /*!< Hardware Channel Instance ID */             
    .ChnHwType = PWM_DRVW_HW_TIM, /*!< Hardware Channel Type */
    .ChannelDutyCycle = 0U, /*!< The duty cycle of this channel */
    .McpwmChConfig = NULL_PTR, /*!< Mcpwm Channel Configuration Pointer */
    .TimChConfig = &Tim_Pwm_Drv_I3_Ch5_Cfg /*!< Tim Channel Configuration Pointer */  
};
const Pwm_Drvw_ChannelConfigType Pwm_Drvw_Ch19_Config =
{
    .ChnHwId = (Pwm_Drvw_ModuleType)TIM_PWM_DRV_I3_CH4_CFG, /*!< Hardware Channel Instance ID */             
    .ChnHwType = PWM_DRVW_HW_TIM, /*!< Hardware Channel Type */
    .ChannelDutyCycle = 0U, /*!< The duty cycle of this channel */
    .McpwmChConfig = NULL_PTR, /*!< Mcpwm Channel Configuration Pointer */
    .TimChConfig = &Tim_Pwm_Drv_I3_Ch4_Cfg /*!< Tim Channel Configuration Pointer */  
};
const Pwm_Drvw_ChannelConfigType Pwm_Drvw_Ch20_Config =
{
    .ChnHwId = (Pwm_Drvw_ModuleType)TIM_PWM_DRV_I3_CH2_CFG, /*!< Hardware Channel Instance ID */             
    .ChnHwType = PWM_DRVW_HW_TIM, /*!< Hardware Channel Type */
    .ChannelDutyCycle = 0U, /*!< The duty cycle of this channel */
    .McpwmChConfig = NULL_PTR, /*!< Mcpwm Channel Configuration Pointer */
    .TimChConfig = &Tim_Pwm_Drv_I3_Ch2_Cfg /*!< Tim Channel Configuration Pointer */  
};
const Pwm_Drvw_ChannelConfigType Pwm_Drvw_Ch21_Config =
{
    .ChnHwId = (Pwm_Drvw_ModuleType)TIM_PWM_DRV_I3_CH1_CFG, /*!< Hardware Channel Instance ID */             
    .ChnHwType = PWM_DRVW_HW_TIM, /*!< Hardware Channel Type */
    .ChannelDutyCycle = 0U, /*!< The duty cycle of this channel */
    .McpwmChConfig = NULL_PTR, /*!< Mcpwm Channel Configuration Pointer */
    .TimChConfig = &Tim_Pwm_Drv_I3_Ch1_Cfg /*!< Tim Channel Configuration Pointer */  
};
const Pwm_Drvw_ChannelConfigType Pwm_Drvw_Ch22_Config =
{
    .ChnHwId = (Pwm_Drvw_ModuleType)TIM_PWM_DRV_I3_CH0_CFG, /*!< Hardware Channel Instance ID */             
    .ChnHwType = PWM_DRVW_HW_TIM, /*!< Hardware Channel Type */
    .ChannelDutyCycle = 0U, /*!< The duty cycle of this channel */
    .McpwmChConfig = NULL_PTR, /*!< Mcpwm Channel Configuration Pointer */
    .TimChConfig = &Tim_Pwm_Drv_I3_Ch0_Cfg /*!< Tim Channel Configuration Pointer */  
};
const Pwm_Drvw_ChannelConfigType Pwm_Drvw_Ch23_Config =
{
    .ChnHwId = (Pwm_Drvw_ModuleType)TIM_PWM_DRV_I1_CH6_CFG, /*!< Hardware Channel Instance ID */             
    .ChnHwType = PWM_DRVW_HW_TIM, /*!< Hardware Channel Type */
    .ChannelDutyCycle = 0U, /*!< The duty cycle of this channel */
    .McpwmChConfig = NULL_PTR, /*!< Mcpwm Channel Configuration Pointer */
    .TimChConfig = &Tim_Pwm_Drv_I1_Ch6_Cfg /*!< Tim Channel Configuration Pointer */  
};
const Pwm_Drvw_ChannelConfigType Pwm_Drvw_Ch24_Config =
{
    .ChnHwId = (Pwm_Drvw_ModuleType)TIM_PWM_DRV_I1_CH5_CFG, /*!< Hardware Channel Instance ID */             
    .ChnHwType = PWM_DRVW_HW_TIM, /*!< Hardware Channel Type */
    .ChannelDutyCycle = 0U, /*!< The duty cycle of this channel */
    .McpwmChConfig = NULL_PTR, /*!< Mcpwm Channel Configuration Pointer */
    .TimChConfig = &Tim_Pwm_Drv_I1_Ch5_Cfg /*!< Tim Channel Configuration Pointer */  
};

#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

#endif  /*PWM_DRVW_PRECOMPILE_SUPPORT */

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

/** @} end of group Pwm_Drvw_Configuration */

/** @} end of group Pwm_Module */
