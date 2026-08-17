/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Adc_LCfg.c
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2026/4/7 17:54:25
 *  @Version         :V1.0
 *  @Description     :This document describes the C language document template.
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 *****************************************************************************/

/******************************************************************************
 **                      Include Files
 ******************************************************************************/
#include "Adc_LCfg.h"

/******************************************************************************
 **                      Macro Definitions
 ******************************************************************************/

/******************************************************************************
 **                      Constants
 ******************************************************************************/

/******************************************************************************
 **                      Type definitions
 ******************************************************************************/

/******************************************************************************
 **                      Variables
 ******************************************************************************/

/******************************************************************************
 **                      adc0 config
 ******************************************************************************/
extern void Adc0_Group0NotifyEvb(void);

/**
 * @brief config adc channel information
 */
static const Adc_GroupDefType Adc_Adc0Group0[11U] = {
  10U, 
  (Adc_GroupDefType)ADC_CONFIG_CHANNEL_114,
  (Adc_GroupDefType)ADC_CONFIG_CHANNEL_126,
  (Adc_GroupDefType)ADC_CONFIG_CHANNEL_127,
  (Adc_GroupDefType)ADC_CONFIG_CHANNEL_11,
  (Adc_GroupDefType)ADC_CONFIG_CHANNEL_13,
  (Adc_GroupDefType)ADC_CONFIG_CHANNEL_14,
  (Adc_GroupDefType)ADC_CONFIG_CHANNEL_15,
  (Adc_GroupDefType)ADC_CONFIG_CHANNEL_16,
  (Adc_GroupDefType)ADC_CONFIG_CHANNEL_17,
  (Adc_GroupDefType)ADC_CONFIG_CHANNEL_18
  };

/**
 * @brief group information config
 */
static const Adc_GroupCfgType Adc_Adc0GrpCfg[1U] = {
  [0U] =
    {
#if (ADC_GRP_NOTIFY_CAPABILITY == STD_ON)
    /* Notification function pointer */
    .NotifyFcnPtr = &Adc0_Group0NotifyEvb,	
#endif
    /* Assignment of channels to a channel group */
    /* First element is the number of configured channels in the group */
    /* From Second element will give the channel ID */
    .GroupDefinition = &Adc_Adc0Group0[0U],
    /* Group trigger source : SW / HW */
    .TriggerSrc = ADC_TRIGG_SRC_SW,
    /* Group conversion mode */
    .GrpConvMode = ADC_CONV_MODE_ONESHOT,
    /* Single access mode */
    .AccessMode = ADC_ACCESS_MODE_SINGLE,
    /* Number of ADC values to be acquired in streaming access mode */
    .StreamNumSample = 1U,
    /* Buffer mode type - Configure streaming buffer as "linear buffer" or "ring buffer" */
    .StreamBufferMode = ADC_STREAM_BUFFER_LINEAR,
    /* Additional sampling time configuration */
    .AdditionalSamplingTime = ADC_CONFIG_SAMSEL_32_ADCCLK,
    }
};

/**
 * @brief adc 0 Channel configuration
 */
static const Adc_ChannelCfgType Adc_Adc0ChCfg = {
  .ConChannelPtr = &(Adc_ConChCfgType){
    .ConDmaSwitch = ADC_CONFIG_CHANNEL_DMA_ENABLE,
    .DmaSource    = ADC_DMA1_CHANNEL_5,
  }};

/**
* @brief adc 0 hw config infomation
*/
static const Adc_HwCfgType Adc_Adc0HwCfg = {
  .AdcHwId	   = ADC_CONFIG_MODULE_0,
  .ClkSource   = ADC_CONFIG_HW_CLKS_HFCLK,
  .ClkPrescale = ADC_CONFIG_HW_CLKDIV_4,
  .DataAlign   = ADC_ALIGN_RIGHT,
  .RefVol 	   = ADC_CONFIG_HW_REFVOL_AVDD};

/**
 * @brief notify function
 * @retval void
 * @return void
 */
extern void Adc0_EventCallBack(Adc_HWType AdcHwId, Adc_EventType Event, Adc_GroupType Group);

/**
 * @brief AdcConfiguration
 */
const Adc_ConfigType Adc_ConfigPredefined = {
  .AdcSetCfgPtr = {
    /**
     * @brief adc 0 config
     */
    [0U] =
      &(Adc_InitConfigType){
        .HwCfgPtr      = &Adc_Adc0HwCfg,
        .ChCfgPtr      = &Adc_Adc0ChCfg,
        .GrpCfgPtr     = &Adc_Adc0GrpCfg[0U],
        .TotGrpsNum    = 1U,
        .EventCallback = &Adc0_EventCallBack,	
      }  }
};
/******************************************************************************
 **                      Function definitions
 ******************************************************************************/

