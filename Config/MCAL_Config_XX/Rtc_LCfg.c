/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Rtc_LCfg.c
 *  @Syntax             : GNU99
 *  @Author             : ChipON AE/FAE Group
 *  @Date            : 2021-12-23
 *  @Version         : {{VersionDate}}
 *  @Description     : This document describes the C language document template.
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 *****************************************************************************/

/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "Rtc_LCfg.h"

/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/

/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/

/******************************************************************************
 **                        Export Variables
 ******************************************************************************/

/******************************************************************************
 **                        Export Functions
 ******************************************************************************/

/******************************************************************************
 **                        Variables
 ******************************************************************************/

void Rtc_AlarmCallBack(void);

/** @brief RTC日期，BCD格式 */
static const Rtc_DateType Rtc_DateConfig = {
  .Year  = 0x24U,
  .Month = 0x10U,
  .Day   = 0x21U,
};

/** @brief RTC时间，BCD格式 */
static const Rtc_TimeType Rtc_TimeConfig = {
  .Week   = 0x01U,
  .Hour   = 0x11U,
  .Minute = 0x58U,
  .Second = 0x33U,
};

/** @brief RTC初始化结构体 */
const Rtc_ConfigType Rtc_ConfigPredefined = {
  .Clock          = RTC_INTLF,
  .DateConfig     = &Rtc_DateConfig,
  .TimeConfig     = &Rtc_TimeConfig,
  .AlarmACallback = Rtc_AlarmCallBack,
  .AlarmBCallback = NULL_PTR,
};
/******************************************************************************
 **                      Function definitions
 ******************************************************************************/

/**
 * @brief call back of alarm interrupt
 *
 * @param AlarmIndex
 */
void Rtc_AlarmCallBack(void)
{
    /* User done */
}
/* EOF */
