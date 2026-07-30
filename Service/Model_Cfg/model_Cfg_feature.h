/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      model_Cfg_feature.h                                                      */
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

#ifndef MODEL_CFG_FEATURE_H_
#define MODEL_CFG_FEATURE_H_


/* ********************************************************************
                 MCU model definition area
***********************************************************************/
#define STR_MCU_TYPE "KF32A136"


/* ********************************************************************
                 Project definition area
***********************************************************************/
/*Project definition*/

#define CFG_MVP13           1

#define CFG_MODEL           CFG_MVP13

#if CFG_MODEL == CFG_MVP13
#include "model_Cfg_MGP13.h"

#else
#error "!!! model_Cfg error !!!"
#endif

/* ********************************************************************
                 Default definition area for all definitions
***********************************************************************/





#ifndef WATCHDOG_FUNC_EN
#define WATCHDOG_FUNC_EN   			1
#endif

#ifndef DEBUG_APPLICATION_ENABLE
#define DEBUG_APPLICATION_ENABLE 			0
#endif

#ifndef LIN_BUS_CTRL_RUN_MODE_EN
#define LIN_BUS_CTRL_RUN_MODE_EN   		1
#endif

#ifndef POWER_MODE_LIN_BUS_DET_EN
#define POWER_MODE_LIN_BUS_DET_EN 		0
#endif



#ifndef PUMP_IS_BLDC_MOTOR
#define PUMP_IS_BLDC_MOTOR 		0
#endif


#ifndef POWER_MODE_IGN_LINE_DET_EN
#define POWER_MODE_IGN_LINE_DET_EN 		0
#endif






/* *******************************************************************/

#endif  //MODEL_CFG_FEATURE_H_
