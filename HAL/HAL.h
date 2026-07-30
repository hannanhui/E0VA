/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      HAL.h                                                                    */
/*   Instance     :                                                                               */
/*   Author       :      Ed                                                                       */
/*   Modify date  :      2025-12-22 14:00:05 PM                                                   */
/*   Description  :                                                                               */
/*                                                                                                */
/*                                                                                                */
/*   Compiler    :       KungFu32 IDE  [Version: V1.0.20.3]                                       */
/*   Hardware    :       ChipOn microcontroller KF32A Family [KF32A156MQV]                        */
/*   Version     :       V1.0                                                                     */
/*                                                                                                */
/*                                                                                                */
/*   All rights reserved. Distribution or duplication without previous written agreement of the   */
/*   owner prohibited.                                                                            */
/*                                                                                                */
/**************************************************************************************************/
#ifndef __INCLUDE_HAL_H__
#define __INCLUDE_HAL_H__



#include "Clock\Clock.h"
#include "DFlash\DFlash.h"
#include "Interrupt\Interrupt.h"
#include "Flash\CFlash.h"
//#include "LIN\HAL_LIN.h"
#include "Port\PORT.h"

#include "SystemMode\SystemMode.h"
#include "SystemTick\SystemTick.h"

#include "WatchDog\WatchDog.h"

#include "LIN\lin_driver.h"
#include "Uart\lpuart_hw_access.h"
#include "Uart\lin_lpuart_driver.h"


#endif /*__INCLUDE_HAL_H__*/
