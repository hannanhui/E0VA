/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      SMP580.h                                                                 */
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
/*
 * SMP580.h
 *
 *  Created on: 2022-8-8
 *      Author: Administrator
 */

#ifndef __SMP580_H__
#define __SMP580_H__
#include "model_Cfg_feature.h"


#if PRESSURE_USE_TYPE == PRESSURE_USE_TYPE_SMP581
#define D_P_SENSOR_SMP580_INDEX0_USED         1
#define D_P_SENSOR_SMP580_INDEX1_USED         1					
#define D_P_SENSOR_SMP580_INDEX2_USED         1					
#define D_P_SENSOR_SMP580_INDEX3_USED         1					
#define D_P_SENSOR_SMP580_INDEX4_USED         1					
#define D_P_SENSOR_SMP580_INDEX5_USED         1					
#define D_P_SENSOR_SMP580_INDEX6_USED         1					
#define D_P_SENSOR_SMP580_INDEX7_USED         1	
#define D_P_SENSOR_SMP580_INDEX8_USED         1					
#define D_P_SENSOR_SMP580_INDEX9_USED         1	


#else
#define D_P_SENSOR_SMP580_INDEX0_USED         0
#define D_P_SENSOR_SMP580_INDEX1_USED         0					
#define D_P_SENSOR_SMP580_INDEX2_USED         0					
#define D_P_SENSOR_SMP580_INDEX3_USED         0					
#define D_P_SENSOR_SMP580_INDEX4_USED         0					
#define D_P_SENSOR_SMP580_INDEX5_USED         0					
#define D_P_SENSOR_SMP580_INDEX6_USED         0					
#define D_P_SENSOR_SMP580_INDEX7_USED         0	
#define D_P_SENSOR_SMP580_INDEX8_USED         0					
#define D_P_SENSOR_SMP580_INDEX9_USED         0	


#endif


typedef enum
{
	P_SENSOR_SMP580_INDEX0= 0,
	P_SENSOR_SMP580_INDEX1,
	P_SENSOR_SMP580_INDEX2,
	P_SENSOR_SMP580_INDEX3,
	P_SENSOR_SMP580_INDEX4,
	P_SENSOR_SMP580_INDEX5,
	P_SENSOR_SMP580_INDEX6,
	P_SENSOR_SMP580_INDEX7,
	P_SENSOR_SMP580_INDEX8,
	P_SENSOR_SMP580_INDEX9,
	P_SENSOR_SMP580_MAX_NUM
}P_SENSOR_SMP580_INDEX;

#include "SMP580_Drv.h"
#include "SMP580_App.h"
#endif /* __SMP580_H__ */
