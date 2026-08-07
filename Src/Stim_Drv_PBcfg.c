/**************************************************************************************************/
/**
 * @file      : Stim_Drv_PBcfg.c  
 * @brief     : Gpt low level driver - Post-Build(PB) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 2.0.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2025 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Gpt_Module
 *  @{
 */

/** @addtogroup Gpt_Drv_Configuration
 *  @brief Gpt low level driver configuration
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Stim_Drv.h"
#include "Gpt_Irq.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define STIM_DRV_PBCFG_C_VENDOR_ID                   0x00B3U
#define STIM_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define STIM_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define STIM_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define STIM_DRV_PBCFG_C_SW_MAJOR_VERSION            2U
#define STIM_DRV_PBCFG_C_SW_MINOR_VERSION            0U
#define STIM_DRV_PBCFG_C_SW_PATCH_VERSION            0U

/* Check if current file and Stim_Drv header file are of the same vendor */
#if (STIM_DRV_PBCFG_C_VENDOR_ID != STIM_DRV_H_VENDOR_ID)
    #error "Stim_Drv_PBcfg.c and Stim_Drv.h have different vendor ids"
#endif
/* Check if current file and Stim_Drv header file are of the same vendor */
#if ((STIM_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION != STIM_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (STIM_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION != STIM_DRV_H_AR_RELEASE_MINOR_VERSION) ||  \
     (STIM_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION != STIM_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Stim_Drv_PBcfg.c and Stim_Drv.h are different"
#endif
/* Check if current file and Stim_Drv header file are of the same Software version */
#if ((STIM_DRV_PBCFG_C_SW_MAJOR_VERSION != STIM_DRV_H_SW_MAJOR_VERSION) || \
     (STIM_DRV_PBCFG_C_SW_MINOR_VERSION != STIM_DRV_H_SW_MINOR_VERSION) || \
     (STIM_DRV_PBCFG_C_SW_PATCH_VERSION != STIM_DRV_H_SW_PATCH_VERSION))
    #error "Software Version Numbers of Stim_Drv_PBcfg.c and Stim_Drv.h are different"
#endif

/* Check if current file and Gpt_Irq header file are of the same vendor */
#if (STIM_DRV_PBCFG_C_VENDOR_ID != GPT_IRQ_H_VENDOR_ID)
    #error "Stim_Drv_PBcfg.c and Gpt_Irq.h have different vendor ids"
#endif
/* Check if current file and Gpt_Irq header file are of the same vendor */
#if ((STIM_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION != GPT_IRQ_H_AR_RELEASE_MAJOR_VERSION) || \
     (STIM_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION != GPT_IRQ_H_AR_RELEASE_MINOR_VERSION) ||  \
     (STIM_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION != GPT_IRQ_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Stim_Drv_PBcfg.c and Gpt_Irq.h are different"
#endif
/* Check if current file and Gpt_Irq header file are of the same Software version */
#if ((STIM_DRV_PBCFG_C_SW_MAJOR_VERSION != GPT_IRQ_H_SW_MAJOR_VERSION) || \
     (STIM_DRV_PBCFG_C_SW_MINOR_VERSION != GPT_IRQ_H_SW_MINOR_VERSION) || \
     (STIM_DRV_PBCFG_C_SW_PATCH_VERSION != GPT_IRQ_H_SW_PATCH_VERSION))
    #error "Software Version Numbers of Stim_Drv_PBcfg.c and Gpt_Irq.h are different"
#endif
/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
#define GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"

const Stim_Drv_ChannelConfigType Stim_Drv_ChannelConfig[4U] = 
{
    /*!< GptStimChannels_FUNCTION */
    {
        0U, /*!< stim channel number */
        (boolean)TRUE, /*!< PrescalerEnable */
    #if( STIM_DRV_SET_DUAL_CLOCK_MODE == STD_ON)
        (Stim_Drv_PrescalerType)2U, /*!< The clock alternate prescaler value */ 
    #endif
        (Stim_Drv_PrescalerType)0U, /*!< Clock prescaler value */ 
        STIM_DRV_FUNCTION_CLOCK,
        &Gpt_TimeMatchCallback, /*!< Stim Interrupt Callback */
        (uint8)3U /*!< Stim callback parameters */
}
    ,
    /*!< GptStimChannels_BUS */
    {
        1U, /*!< stim channel number */
        (boolean)TRUE, /*!< PrescalerEnable */
    #if( STIM_DRV_SET_DUAL_CLOCK_MODE == STD_ON)
        (Stim_Drv_PrescalerType)1U, /*!< The clock alternate prescaler value */ 
    #endif
        (Stim_Drv_PrescalerType)0U, /*!< Clock prescaler value */ 
        STIM_DRV_BUS_CLOCK,
        &Gpt_TimeMatchCallback, /*!< Stim Interrupt Callback */
        (uint8)2U /*!< Stim callback parameters */
}
    ,
    /*!< GptStimChannels_OSC40M */
    {
        2U, /*!< stim channel number */
        (boolean)(FALSE), /*!< PrescalerEnable */
    #if( STIM_DRV_SET_DUAL_CLOCK_MODE == STD_ON)
        (Stim_Drv_PrescalerType)1U, /*!< The clock alternate prescaler value */ 
    #endif
        (Stim_Drv_PrescalerType)0U, /*!< Clock prescaler value */ 
        STIM_DRV_OSC40M,
        &Gpt_TimeMatchCallback, /*!< Stim Interrupt Callback */
        (uint8)4U /*!< Stim callback parameters */
}
    ,
    /*!< GptStimChannels_LPO32K */
    {
        3U, /*!< stim channel number */
        (boolean)(FALSE), /*!< PrescalerEnable */
    #if( STIM_DRV_SET_DUAL_CLOCK_MODE == STD_ON)
        (Stim_Drv_PrescalerType)5U, /*!< The clock alternate prescaler value */ 
    #endif
        (Stim_Drv_PrescalerType)0U, /*!< Clock prescaler value */ 
        STIM_DRV_LPO32K,
        &Gpt_TimeMatchCallback, /*!< Stim Interrupt Callback */
        (uint8)1U /*!< Stim callback parameters */
}
};



#define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"

/** @} end of group Global_VariableDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Stim_Drv_Configuration */

/** @} end of group Stim_Module */
