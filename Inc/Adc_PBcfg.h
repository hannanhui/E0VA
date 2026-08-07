/**************************************************************************************************/
/**
 * @file      : Adc_PBcfg.h
 * @brief     : Adc AUTOSAR level - Post-Build(PB) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 2.0.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2025 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef ADC_PBCFG_H
#define ADC_PBCFG_H

/** @addtogroup Adc_Module
 *  @{
 */

/** @addtogroup Adc_Configuration
 *  @brief Adc AUTOSAR level configuration
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define ADC_PBCFG_H_VENDOR_ID                   0x00B3U
#define ADC_PBCFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define ADC_PBCFG_H_AR_RELEASE_MINOR_VERSION    6U
#define ADC_PBCFG_H_AR_RELEASE_REVISION_VERSION 0U
#define ADC_PBCFG_H_SW_MAJOR_VERSION            2U
#define ADC_PBCFG_H_SW_MINOR_VERSION            0U
#define ADC_PBCFG_H_SW_PATCH_VERSION            0U

/**
 * @brief Defines ADC configuration
 */

/**
 * @brief Total number of groups across all ConfigSet.
 *
 */
#define ADC_CFG_GROUP_NUM    (3U)

/**
* @brief Number of channels configured for each group.
*
*/
#define ADC_CFG_GROUP_0_CHANNEL_NUM    (3U)
#define ADC_CFG_GROUP_1_CHANNEL_NUM    (6U)
#define ADC_CFG_GROUP_2_CHANNEL_NUM    (2U)

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

/**
 * @brief Defines declaration of ADC notification functions.
 */
#define ADC_FUNC_DECL_PB \
    extern void Cbk_Adc0Group0_Notification(void);  \
    extern void Cbk_Adc1Group0_Notification(void);  \
    extern void Cbk_Adc1Group1_Notification(void);  \

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Adc_Configuration */

/** @} end of group Adc_Module */

#endif /* ADC_PBCFG_H */

