/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Rtc.h
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
#ifndef RTC_H
#define RTC_H

#ifdef __cplusplus
extern "C" {
#endif

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

/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "Rtc_Types.h"
#include "Rtc_Cfg.h"
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
 * Function Name   : Rtc_Init
 *
 * Service ID   :
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Non Reentrant
 *
 * Parameters(in)   : ConfigPtr Pointer to RTC configure.
 * InitTimeStatus
 * true : Initialize time
 * false: Do not initialize time
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : Rtc_StatusType
 *
 * Description   : Initializes the Rtc hardware units and driver
 *
 ******************************************************************************/
FUNC(Rtc_StatusType, RTC_CODE)
Rtc_Init(P2CONST(Rtc_ConfigType, AUTOMATIC, RTC_APPL_CONST) ConfigPtr, VAR(boolean, RTC_VAR) InitTimeStatus);

/******************************************************************************
 * Function Name   : Rtc_DeInit
 *
 * Service ID   :
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Non Reentrant
 *
 * Parameters(in)   : None
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : None
 *
 * Description   : De-initialize RTC
 *
 ******************************************************************************/
FUNC(void, RTC_CODE) Rtc_DeInit(VAR(void, RTC_VAR));

/******************************************************************************
 * Function Name   : Rtc_SetDateTime
 *
 * Service ID   :
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Non Reentrant
 *
 * Parameters(in)   : DateTimePtr Pointer to RTC time.
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : Std_ReturnType
 *
 * Description   : Set RTC time
 *
 ******************************************************************************/
FUNC(Std_ReturnType, RTC_CODE) Rtc_SetDateTime(P2CONST(Rtc_DateTimeType, RTC_VAR, RTC_APPL_CONST) DateTimePtr);

/******************************************************************************
 * Function Name   : Rtc_GetDateTime
 *
 * Service ID   :
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Non Reentrant
 *
 * Parameters(in)   : TimePtr Pointer to where store the time
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : None
 *
 * Description   : Get RTC time.
 *
 ******************************************************************************/
/* PRQA S 3432 1 #KQR003432 */
FUNC(void, RTC_CODE) Rtc_GetDateTime(P2VAR(Rtc_DateTimeType, AUTOMATIC, OCU_APPL_DATA) TimePtr);

/******************************************************************************
 * Function Name   : Rtc_GetDateTime
 *
 * Service ID   :
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Non Reentrant
 *
 * Parameters(in)   : AlarmIndex Index of alarm.
 * AlarmTimePtr Pointer to structure of alarm.
 * AlarmRepeatType alarm type
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : Std_ReturnType
 *
 * Description   : Config alarm. Repeat every day.
 *
 ******************************************************************************/
FUNC(Std_ReturnType, RTC_CODE)
Rtc_SetAlarm(VAR(Rtc_IndexType, RTC_VAR) AlarmIndex, VAR(Rtc_AlarmRepeatType, RTC_VAR) AlarmRepeatType,
             P2CONST(Rtc_TimeType, RTC_VAR, RTC_APPL_CONST) AlarmTimePtr);

/******************************************************************************
 * Function Name   : Rtc_EnableAlarm
 *
 * Service ID   :
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Non Reentrant
 *
 * Parameters(in)   : AlarmIndex Index of alarm.
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : Std_ReturnType
 *
 * Description   : Enable alarm.
 *
 ******************************************************************************/
FUNC(Std_ReturnType, RTC_CODE) Rtc_EnableAlarm(VAR(Rtc_IndexType, RTC_VAR) AlarmIndex);

/******************************************************************************
 * Function Name   : Rtc_EnableAlarm
 *
 * Service ID   :
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Non Reentrant
 *
 * Parameters(in)   : AlarmIndex Index of alarm.
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : Std_ReturnType
 *
 * Description   : Disable alarm.
 *
 ******************************************************************************/
FUNC(Std_ReturnType, RTC_CODE) Rtc_DisableAlarm(VAR(Rtc_IndexType, RTC_VAR) AlarmIndex);
#ifdef __cplusplus
}
#endif

#endif
/* EOF */
