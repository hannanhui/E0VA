/**************************************************************************************************/
/**
 * @file      : Port_Cfg.h
 * @brief     : AUTOSAR Port config file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 2.0.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2025 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef PORT_CFG_H
#define PORT_CFG_H

/** @addtogroup Port_Module
 *  @{
 */

/** @addtogroup Port_Configuration
 *  @brief Port AUTOSAR level configuration
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Port_PBcfg.h"



/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define PORT_CFG_H_VENDOR_ID                   0x00B3U
#define PORT_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define PORT_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define PORT_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define PORT_CFG_H_SW_MAJOR_VERSION            2U
#define PORT_CFG_H_SW_MINOR_VERSION            0U
#define PORT_CFG_H_SW_PATCH_VERSION            0U

/* Check if the vendor id of current file and Port_PBcfg.h are the same  */
#if (PORT_CFG_H_VENDOR_ID != PORT_PBCFG_H_VENDOR_ID)
    #error "Vendor if of Port_Cfg.h and Port_PBcfg.h are different"
#endif
/* Check if autodsar version of current file and Port_PBcfg.h are the same */
#if ((PORT_CFG_H_AR_RELEASE_MAJOR_VERSION != PORT_PBCFG_H_AR_RELEASE_MAJOR_VERSION) ||    \
     (PORT_CFG_H_AR_RELEASE_MINOR_VERSION != PORT_PBCFG_H_AR_RELEASE_MINOR_VERSION) ||    \
     (PORT_CFG_H_AR_RELEASE_REVISION_VERSION != PORT_PBCFG_H_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar version of Port_Cfg.h and Port_PBcfg.h are different"
#endif
/* Check if the software version of current file and Port_PBcfg.h are the same*/
#if ((PORT_CFG_H_SW_MAJOR_VERSION != PORT_PBCFG_H_SW_MAJOR_VERSION) ||  \
     (PORT_CFG_H_SW_MINOR_VERSION != PORT_PBCFG_H_SW_MINOR_VERSION) ||  \
     (PORT_CFG_H_SW_PATCH_VERSION != PORT_PBCFG_H_SW_PATCH_VERSION)     \
    )
    #error "Software version of Port_Cfg.h and Port_PBcfg.h are different"
#endif


    


#define PORT_PRECOMPILE_SUPPORT     (STD_ON)

#define PORT_DEV_ERROR_DETECT           PORT_DRVW_DEV_ERROR_DETECT

#define PORT_SET_PIN_DIRECTION_API      PORT_DRVW_SET_PIN_DIRECTION_API

#define PORT_SET_PIN_MODE_API           PORT_DRVW_SET_PIN_MODE_API

#define PORT_VERSION_INFO_API           (STD_ON)

#define PORT_NUMBER_OF_PARTITION              (1U)

#define PORT_TOTAL_PIN_NUMBER    ((uint16)144)

#define PORT_NUMBER_OF_CONFIG_PINS      PORT_DRVW_NUMBER_OF_CONFIG_PINS

#define PORT_MAX_PINMUX_NUMBER          PORT_DRVW_MAX_PINMUX_NUMBER


#define PortConf_PortPin_PTB1_CAN0_TX  0
#define PortConf_PortPin_PTB0_CAN0_RX  1
#define PortConf_PortPin_PTA17_CAN0_ERR  2
#define PortConf_PortPin_PTB17_CAN0_EN  3
#define PortConf_PortPin_PTB13_CAN0_STB  4
#define PortConf_PortPin_PTE12_SPI1_CS7  5
#define PortConf_PortPin_PTD17_SPI1_CS8  6
#define PortConf_PortPin_PTD14_SPI1_CS9  7
#define PortConf_PortPin_PTD13_SPI1_CS10  8
#define PortConf_PortPin_PTC3_SPI1_CS6  9
#define PortConf_PortPin_PTC2_SPI1_CS5  10
#define PortConf_PortPin_PTD6_SPI1_CS4  11
#define PortConf_PortPin_PTC1_SPI1_CS1  12
#define PortConf_PortPin_PTC0_SPI1_CS2  13
#define PortConf_PortPin_PTD9_SPI1_CS3  14
#define PortConf_PortPin_PTB16_SPI1_MOSI  15
#define PortConf_PortPin_PTB15_SPI1_MISO  16
#define PortConf_PortPin_PTB14_SPI1_SCK  17
#define PortConf_PortPin_PTC9_LIN1_M_TXD  18
#define PortConf_PortPin_PTC8_LIN1_M_RXD  19
#define PortConf_PortPin_PTE7_LIN1_M_CS  20
#define PortConf_PortPin_PTD2_LIN0_S_CS  21
#define PortConf_PortPin_PTA3_LIN0_S_TXD  22
#define PortConf_PortPin_PTA2_LIN0_S_RXD  23
#define PortConf_PortPin_PTE13_CAN_LIN_WAKE  24
#define PortConf_PortPin_PTE1_IGN_WAKE  25
#define PortConf_PortPin_PTA9_KEY_WAKE  26
#define PortConf_PortPin_PTA7_ADC0_CH3_PUMP_HSD_AD  27
#define PortConf_PortPin_PTA6_ADC0_CH2_PUMP_V_AD  28
#define PortConf_PortPin_PTD4_ADC1_CH6_NTC_AD  29
#define PortConf_PortPin_PTD3_ADC1_CH3_HW_VER  30
#define PortConf_PortPin_PTA0_ADC0_CH0_POWER_DTC_AD  31
#define PortConf_PortPin_PTC7_ADC1_CH5_KEY2_AD  32
#define PortConf_PortPin_PTC6_ADC1_CH4_KEY3_AD  33
#define PortConf_PortPin_PTA16_ADC1_CH13_KEY1_AD  34
#define PortConf_PortPin_PTA15_ADC1_CH12_250KPA_OUT  35
#define PortConf_PortPin_PTE6_ADC1_CH11_VAVLE_HSD_AD  36
#define PortConf_PortPin_PTE2_ADC1_CH10_VAVLE_V_AD  37
#define PortConf_PortPin_PTE16_TIM2_CH7  38
#define PortConf_PortPin_PTE15_TIM2_CH6  39
#define PortConf_PortPin_PTD1_TIM0_CH3  40
#define PortConf_PortPin_PTD0_TIM0_CH2  41
#define PortConf_PortPin_PTE11_TIM2_CH4  42
#define PortConf_PortPin_PTD16_TIM0_CH1  43
#define PortConf_PortPin_PTD15_TIM0_CH0  44
#define PortConf_PortPin_PTE9_TIM0_CH7  45
#define PortConf_PortPin_PTE8_TIM0_CH6  46
#define PortConf_PortPin_PTB5_TIM0_CH5  47
#define PortConf_PortPin_PTB4_TIM0_CH4  48
#define PortConf_PortPin_PTD5_TIM2_CH3  49
#define PortConf_PortPin_PTD12_TIM2_CH2  50
#define PortConf_PortPin_PTC14_TIM1_CH2  51
#define PortConf_PortPin_PTB3_TIM1_CH1  52
#define PortConf_PortPin_PTB2_TIM1_CH0  53
#define PortConf_PortPin_PTC13_TIM3_CH7  54
#define PortConf_PortPin_PTC12_TIM3_CH6  55
#define PortConf_PortPin_PTC11_TIM3_CH5  56
#define PortConf_PortPin_PTC10_TIM3_CH4  57
#define PortConf_PortPin_PTB10_TIM3_CH2  58
#define PortConf_PortPin_PTB9_TIM3_CH1  59
#define PortConf_PortPin_PTB8_TIM3_CH0  60
#define PortConf_PortPin_PTA12_TIM1_CH6  61
#define PortConf_PortPin_PTA11_TIM1_CH5  62
#define PortConf_PortPin_PTE14_VALVE_HSD_SEN  63
#define PortConf_PortPin_PTE3_HSD_IN  64
#define PortConf_PortPin_PTD8_SPWR_EN  65
#define PortConf_PortPin_PTC17_PUMP_HSD_SEN  66
#define PortConf_PortPin_PTC16_PUMP_HSD_IN  67
#define PortConf_PortPin_PTA1_VOLTAGE_DTC_EN  68


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

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Port_Configuration */

/** @} end of group Port_Module */

#endif /* PORT_CFG_H */

/* End of File */
