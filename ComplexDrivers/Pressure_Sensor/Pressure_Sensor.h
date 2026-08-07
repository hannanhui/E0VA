/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      Pressure_Sensor.h                                                        */
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
#ifndef __INCLUDE_PRESSURE_SENSOR_H__
#define __INCLUDE_PRESSURE_SENSOR_H__


#include "SMP580.h"
#include "NSPAD1.h"
#include "NSPAS3.h"

typedef enum
{
	P_SENSOR_GENERAL_INDEX0 = 0,
	P_SENSOR_GENERAL_INDEX1,
	P_SENSOR_GENERAL_INDEX2,
	P_SENSOR_GENERAL_INDEX3,
	P_SENSOR_GENERAL_INDEX4,
	P_SENSOR_GENERAL_INDEX5,
	P_SENSOR_GENERAL_INDEX6,
	P_SENSOR_GENERAL_INDEX7,
	P_SENSOR_GENERAL_INDEX8,
	P_SENSOR_GENERAL_INDEX9,
	P_SENSOR_GENERAL_INDEX10,
	P_SENSOR_GENERAL_INDEX11,
	P_SENSOR_GENERAL_INDEX12,
	P_SENSOR_GENERAL_INDEX13,
	P_SENSOR_GENERAL_INDEX14,
	P_SENSOR_GENERAL_INDEX15,
	P_SENSOR_GENERAL_MAX_NUM,
	P_SENSOR_GENERAL_INVALID_INDEX = 0xFF
}P_SENSOR_GENERAL_INDEX;
typedef enum
{
	P_SENSOR_GENERAL_TYPE_SMP580 = 0,
	P_SENSOR_GENERAL_TYPE_NSPAD1,
	P_SENSOR_GENERAL_TYPE_NSPAS3,
	P_SENSOR_GENERAL_TYPE_LPMSCA05  //Reserved
	
}P_SENSOR_GENERAL_TYPE;


typedef enum
{
	P_SENSOR_INIT_WAIT_POWER_STABILIZE = 0,
	P_SENSOR_INIT_REGISTER1_SET,
	P_SENSOR_INIT_REGISTER2_SET,
	P_SENSOR_INIT_COMPLETE 
	
}P_SENSOR_INIT_STATUS;


typedef struct {
	uint8_t 				Sensor_Dev_Index; 	
	uint8_t 				Sensor_Dev_Type; 		 
} P_Sensor_Index_Type_str_t;


extern void P_Sensor_Scheduler_Periodic_10mS(void);
extern BOOL P_Sensor_PressureGet(P_SENSOR_GENERAL_INDEX opIndex,uint32_t* Pressure);
extern BOOL P_Sensor_TemperatureGet(P_SENSOR_GENERAL_INDEX opIndex,int16_t* Temperature);
extern void P_Sensor_Init(void);
extern void P_Sensor_DeInit(void);

#endif /*__INCLUDE_PRESSURE_SENSOR_H__*/
