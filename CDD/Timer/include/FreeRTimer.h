/*============================================================================*/
/*  Copyright (C) 2009-2011,   SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is  property. Duplication
 *  or disclosure without  written authorization is prohibited.
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
#include "Std_Types.h"
/*#include "Os_counter_api.h"*/

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

#define     TICKS2MS_SystemTimer(ticks)    (ticks*1000/1000)
#define     MS2TICKS_SystemTimer(ms)       (ms*1000/1000)


/****************************** declarations *********************************/
uint32 Frt_ReadOutMS(void);
uint32 Frt_CalculateElapsedMS(uint32 OldCurMs);
/****************************** definitions *********************************/

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif /* FREERTIMER_H */
