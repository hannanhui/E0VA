/**************************************************************************************************/
/**
 * @file      : Rtc_Drv_PBcfg.c 
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
extern "C"
{
#endif

#include "Rtc_Drv.h"
#include "Gpt_Irq.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define RTC_DRV_PBCFG_C_VENDOR_ID                   0x00B3U
#define RTC_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define RTC_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define RTC_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define RTC_DRV_PBCFG_C_SW_MAJOR_VERSION            2U
#define RTC_DRV_PBCFG_C_SW_MINOR_VERSION            0U
#define RTC_DRV_PBCFG_C_SW_PATCH_VERSION            0U

/* Check if current file and Rtc_Drv header file are of the same vendor */
#if (RTC_DRV_PBCFG_C_VENDOR_ID != RTC_DRV_H_VENDOR_ID)
    #error "Vendor ID of Rtc_Drv_PBcfg.c and Rtc_Drv.h are different"
#endif
/* Check if current file and Rtc_Drv header file are of the same Autosar version */
#if ((RTC_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION != RTC_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (RTC_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION != RTC_DRV_H_AR_RELEASE_MINOR_VERSION) || \
     (RTC_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION != RTC_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Rtc_Drv_PBcfg.c and Rtc_Drv.h are different"
#endif
/* Check if current file and Rtc_Drv header file are of the same Software version */
#if ((RTC_DRV_PBCFG_C_SW_MAJOR_VERSION != RTC_DRV_H_SW_MAJOR_VERSION) || \
     (RTC_DRV_PBCFG_C_SW_MINOR_VERSION != RTC_DRV_H_SW_MINOR_VERSION) || \
     (RTC_DRV_PBCFG_C_SW_PATCH_VERSION != RTC_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Rtc_Drv_PBcfg.c and Rtc_Drv.h are different"
#endif

/* Check if current file and Gpt_Irq header file are of the same vendor */
#if (RTC_DRV_PBCFG_C_VENDOR_ID != GPT_IRQ_H_VENDOR_ID)
    #error "Vendor ID of Rtc_Drv_PBcfg.c and Gpt_Irq.h are different"
#endif
/* Check if current file and Gpt_Irq header file are of the same Autosar version */
#if ((RTC_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION != GPT_IRQ_H_AR_RELEASE_MAJOR_VERSION) || \
     (RTC_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION != GPT_IRQ_H_AR_RELEASE_MINOR_VERSION) || \
     (RTC_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION != GPT_IRQ_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Rtc_Drv_PBcfg.c and Gpt_Irq.h are different"
#endif
/* Check if current file and Gpt_Irq header file are of the same Software version */
#if ((RTC_DRV_PBCFG_C_SW_MAJOR_VERSION != GPT_IRQ_H_SW_MAJOR_VERSION) || \
     (RTC_DRV_PBCFG_C_SW_MINOR_VERSION != GPT_IRQ_H_SW_MINOR_VERSION) || \
     (RTC_DRV_PBCFG_C_SW_PATCH_VERSION != GPT_IRQ_H_SW_PATCH_VERSION))
    #error "Software Version of Rtc_Drv_PBcfg.c and Gpt_Irq.h are different"
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

const Rtc_Drv_ConfigType Rtc_Drv_InitConfig = 
{
    RTC_DRV_CLK_LPO32K, /*!< Rtc clock source */
    RTC_DRV_SECONDS, /*!< RTC clock output type */
    RTC_DRV_INT_ALARM, /*!< RTC interrupt mode type */
#if (defined (RTC_DRV_ENABLE_COMPENSATION_SUPPORT) && (RTC_DRV_ENABLE_COMPENSATION_SUPPORT == STD_ON))
    (uint8)0U, /*!< Rtc Compensation Interval */
    RTC_DRV_COMP_UP, /*!< Rtc Compensation Direction */
    (uint8)0U, /*!< Rtc Compensation Value */
#endif
    &Gpt_TimeMatchCallback, /*!< Rtc interrupt callback */
    (uint8)0U /*!< Pointer to callback parameters */
};


#define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"
/** @} end of group Global_VariableDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Rtc_Drv_Configuration */

/** @} end of group Rtc_Module */
