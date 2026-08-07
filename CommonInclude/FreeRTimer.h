/*============================================================================*/
/*  Copyright (C) 2009-2011, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file        <FreeRTimer.h>
 *  @brief       <>
 *
 *  <Compiler: CodeWarrior    MCU:XXX>
 *
 *  @author     <chen maosen>
 *  @date       <2013-03-20>
 */
/*============================================================================*/

/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>    <DATE>    <AUTHOR>    <REVISION LOG>                         */
/*  V1.0.0       2013-3-20  chenms    Initial version                         */
/*============================================================================*/
#ifndef FREERTIMER_H
#define FREERTIMER_H

/****************************** references *********************************/
#include "Os.h"

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */
#include "Std_Types.h"
#include "Platform_Types.h"

/****************************** declarations *********************************/
extern uint32 Frt_ReadOutMS(void);
extern uint32 Frt_CalculateElapsedMS(uint32 OldCurMs);
extern void Run_msCounter(void);
extern Std_ReturnType GetCounterValue(uint16 id, TickType* tick);
Std_ReturnType GetElapsedCounterValue(uint16 id, TickType* tick, TickType* elapsed);

/****************************** definitions *********************************/
#define     TICKS2MS_SystemTimer(ticks)    (ticks*1000/1000)
#define     MS2TICKS_SystemTimer(ms)       (ms*1000/1000)

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif /* FREERTIMER_H */
