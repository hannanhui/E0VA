/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      ADC_DESC.h                                                               */
/*   Instance     :                                                                               */
/*   Author       :      Ed                                                                       */
/*   Modify date  :      2025-04-11 11:08:33 AM                                                   */
/*   Description  :                                                                               */
/*                                                                                                */
/*                                                                                                */
/*   Compiler    :       KungFu32 IDE  [Version: V1.0.20.3]                                       */
/*   Hardware    :       ChipOn microcontroller KF32A Family [KF32A136KQT]                        */
/*   Version     :       V1.0                                                                     */
/*                                                                                                */
/*                                                                                                */
/*   All rights reserved. Distribution or duplication without previous written agreement of the   */
/*   owner prohibited.                                                                            */
/*                                                                                                */
/**************************************************************************************************/


#ifndef __ADC_DESC_H__
#define __ADC_DESC_H__

#define ADC_VAL_INVALID        0xFFFF



#define  ADC_INSIDE_CHANNEL_2 		(AdcConf_AdcChannel_ADC1_CH11_VAVLE_HSD_AD-0x1000+ADC_CFG_GROUP_0_CHANNEL_NUM)

#define  ADC_INSIDE_CHANNEL_3 		(AdcConf_AdcChannel_ADC1_CH10_VAVLE_V_AD-0x1000+ADC_CFG_GROUP_0_CHANNEL_NUM)

#define  ADC_INSIDE_CHANNEL_4 		AdcConf_AdcChannel_ADC0_CH0_POWER_DTC_AD

#define  ADC_INSIDE_CHANNEL_5 		(AdcConf_AdcChannel_ADC1_CH3_HW_VER-0x1000+ADC_CFG_GROUP_0_CHANNEL_NUM)

#define  ADC_INSIDE_CHANNEL_6 		(AdcConf_AdcChannel_ADC1_CH13_KEY1_AD-0x1000+ADC_CFG_GROUP_0_CHANNEL_NUM)

#define  ADC_INSIDE_CHANNEL_7 		(AdcConf_AdcChannel_ADC1_CH6_NTC_AD-0x1000+ADC_CFG_GROUP_0_CHANNEL_NUM)

#define  ADC_INSIDE_CHANNEL_8 		(AdcConf_AdcChannel_ADC1_CH4_KEY3_AD-0x1000+ADC_CFG_GROUP_0_CHANNEL_NUM)

#define  ADC_INSIDE_CHANNEL_9 		(AdcConf_AdcChannel_ADC1_CH5_KEY2_AD-0x1000+ADC_CFG_GROUP_0_CHANNEL_NUM)
#define  ADC_INSIDE_CHANNEL_10        (AdcConf_AdcChannel_ADC1_CH12_250KPA_OUT-0x1000+ADC_CFG_GROUP_0_CHANNEL_NUM)


#define  ADC_INSIDE_CHANNEL_12 		AdcConf_AdcChannel_ADC0_CH2_PUMP_V_AD

#define  ADC_INSIDE_CHANNEL_15 		AdcConf_AdcChannel_ADC0_CH3_PUMP_HSD_AD

#define ADC_SAMP_NUM           5u //Old every ch 12time samp, all ch one samp 200ms, change to 5 all ch samp 125ms;
#if (ADC_SAMP_NUM < 3u)
  #error "ADC_SAMP_NUM can not less than 3 ! "
#endif

#define ADC_GROUP_CH_NUM       ADC_CFG_GROUP_0_CHANNEL_NUM+ADC_CFG_GROUP_1_CHANNEL_NUM+ADC_CFG_GROUP_2_CHANNEL_NUM

typedef struct
{
    //const ADC_P_Channel_t Ch;
    uint8_t DataValidSt;
    uint16_t Val;
}AdcResult_t;

typedef enum
{
    AdcWorkSt_PwrOn,
    AdcWorkSt_Init,
    AdcWorkSt_Idle,
    AdcWorkSt_SampStart,
    AdcWorkSt_Sampling,
    AdcWorkSt_SamplFinsh,
    AdcWorkSt_Err,
    
}AdcWorkSt_t;

#endif /* __ADC_DESC_H__ */



