/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      NSPAD1.h                                                                 */
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


#ifndef __NSPAD1_H__
#define __NSPAD1_H__

#include "model_Cfg_feature.h"

#if PRESSURE_USE_TYPE == PRESSURE_USE_TYPE_NSPAD1

#define D_P_SENSOR_NSPAD1_INDEX0_USED         1
#define D_P_SENSOR_NSPAD1_INDEX1_USED         1
#define D_P_SENSOR_NSPAD1_INDEX2_USED         1
#define D_P_SENSOR_NSPAD1_INDEX3_USED         1
#define D_P_SENSOR_NSPAD1_INDEX4_USED         1
#define D_P_SENSOR_NSPAD1_INDEX5_USED         1
#define D_P_SENSOR_NSPAD1_INDEX6_USED         1
#define D_P_SENSOR_NSPAD1_INDEX7_USED         1
#define D_P_SENSOR_NSPAD1_INDEX8_USED         1
#define D_P_SENSOR_NSPAD1_INDEX9_USED         1


#else
#define D_P_SENSOR_NSPAD1_INDEX0_USED         0
#define D_P_SENSOR_NSPAD1_INDEX1_USED         0
#define D_P_SENSOR_NSPAD1_INDEX2_USED         0
#define D_P_SENSOR_NSPAD1_INDEX3_USED         0
#define D_P_SENSOR_NSPAD1_INDEX4_USED         0
#define D_P_SENSOR_NSPAD1_INDEX5_USED         0
#define D_P_SENSOR_NSPAD1_INDEX6_USED         0
#define D_P_SENSOR_NSPAD1_INDEX7_USED         0
#define D_P_SENSOR_NSPAD1_INDEX8_USED         0
#define D_P_SENSOR_NSPAD1_INDEX9_USED         0


#endif


typedef enum
{
	P_SENSOR_NSPAD1_INDEX0= 0,
	P_SENSOR_NSPAD1_INDEX1,
	P_SENSOR_NSPAD1_INDEX2,
	P_SENSOR_NSPAD1_INDEX3,
	P_SENSOR_NSPAD1_INDEX4,
	P_SENSOR_NSPAD1_INDEX5,
	P_SENSOR_NSPAD1_INDEX6,
	P_SENSOR_NSPAD1_INDEX7,
	P_SENSOR_NSPAD1_INDEX8,
	P_SENSOR_NSPAD1_INDEX9,
	P_SENSOR_NSPAD1_MAX_NUM
}P_SENSOR_NSPAD1_INDEX;

#include "NSPAD1_Drv.h"
#include "NSPAD1_App.h"
#endif /* __SMP580_H__ */
