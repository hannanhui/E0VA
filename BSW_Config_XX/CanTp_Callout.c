/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <CanTp_Callout.c>
 *  @brief      <>
 *  
 *  <MCU:Z20K144M>
 *  
 *  @author     <>
 *  @date       <2025-02-07 16:03:35>
 */
/*============================================================================*/

/*=======[I N C L U D E S]====================================================*/
#include "CanTp_Internal.h"
#if (CANTP_TM == STD_ON)
#include "Tm.h"
#endif /* CANTP_TM == STD_ON */

#include "FreeRTimer.h"

/*=============Module Callout Function Implementation====================*/
#define CANTP_START_SEC_CODE
#include "CanTp_MemMap.h"
/* Showing TM solution as an example */
/* if not having TM, need to implement other methods for timing functionality */
FUNC(void, CANTP_CODE)
    CanTp_ResetTime(
        P2VAR(uint32, AUTOMATIC, CANTP_APPL_DATA) TimerPtr)
{
#if (CANTP_TM == STD_ON)
    Tm_PredefTimer100us32bitType Timer;

    Timer.ui32RefTime = 0;
    (void)Tm_ResetTimer100us32bit(&Timer);
    *TimerPtr = Timer.ui32RefTime / (uint32)10;
#endif
    
    *TimerPtr = Frt_ReadOutMS();
    
}

/* Showing TM solution as an example */
/* if not having TM, need to implement other methods for timing functionality */
FUNC(void, CANTP_CODE)
    CanTp_GetTimeSpan(
        uint32 TimerPtr,
        P2VAR(uint32, AUTOMATIC, CANTP_APPL_DATA) TimeSpanPtr)
{
#if (CANTP_TM == STD_ON)
    Tm_PredefTimer100us32bitType Timer;

    Timer.ui32RefTime = TimerPtr * (uint32)10;
    (void)Tm_GetTimeSpan100us32bit(&Timer, TimeSpanPtr);
    *TimeSpanPtr = (*TimeSpanPtr) / (uint32)10;
#endif
    
    *TimeSpanPtr = Frt_CalculateElapsedMS(TimerPtr);
}
#define CANTP_STOP_SEC_CODE
#include "CanTp_MemMap.h"

