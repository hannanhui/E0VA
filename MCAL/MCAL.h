/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      MCAL.h                                                                   */
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
#ifndef __INCLUDE_MCAL_H__
#define __INCLUDE_MCAL_H__
/* ???????? */
#define USE_CHECK_ASSERT 0
#if USE_CHECK_ASSERT
#define CHECK_RESTRICTION(expr) ((expr) ? (void)0 : check_failed((uint8_t *)__FILE__, __LINE__))
/*  ?????? ------------------------------------------------------- */
void check_failed(uint8_t *file, uint32_t line);
#else
#define CHECK_RESTRICTION(expr) ((void)0)
#endif /* USE_CHECK_ASSERT */
#if (defined(DEV_Z20K118M)) || (defined(DEV_Z20K116M)) || (defined(DEV_Z20K114M))
#include "Z20K11xM_drv.h"
#include "Z20K11xM_clock.h"
#include "Z20K11xM_sysctrl.h"
#include "Z20K11xM_wdog.h"
#include "Z20K11xM_gpio.h"
#include "Z20K11xM_uart.h"
#include "Z20K11xM_flash.h"
#include "Z20K11xM_crc.h"
#include "Z20K11xM_regfile.h"
#else
#include "Type_Define.h"


#include "regfile_drv.h"
#include "int_drv.h"
#include "common_drv.h"
#include "clock_drv.h"
#include "sysctrl_drv.h"
#include "gpio_drv.h"
#include "wdog_drv.h"
#include "crc_drv.h"
#include "flash_drv.h"
#include "stim_drv.h"
#include "pmu_drv.h"


#include "uart_drv.h"



#endif

#endif /*__INCLUDE_MCAL_H__*/
