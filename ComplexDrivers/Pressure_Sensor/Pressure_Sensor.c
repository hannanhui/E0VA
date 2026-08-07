/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      Pressure_Sensor.c                                                        */
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



#include "Pressure_Sensor.h"


uint16_t PSensor_Init_Delay = 0;
uint8_t PSensor_Init_Status = 0;
uint8_t PSensor_InitComplete_Flag = 0;

P_Sensor_Index_Type_str_t P_Sensor_Index_ReferenceList[P_SENSOR_GENERAL_MAX_NUM] ={

	{
		.Sensor_Dev_Index = P_SENSOR_GENERAL_INDEX0,
		.Sensor_Dev_Type = P_SENSOR_GENERAL_TYPE_NSPAS3,
	},
	#if PRESSURE_USE_TYPE == PRESSURE_USE_TYPE_SMP581
	{
		.Sensor_Dev_Index = P_SENSOR_SMP580_INDEX0,
		.Sensor_Dev_Type = P_SENSOR_GENERAL_TYPE_SMP580,
	},
	{
		.Sensor_Dev_Index = P_SENSOR_SMP580_INDEX1,
		.Sensor_Dev_Type = P_SENSOR_GENERAL_TYPE_SMP580, 
	},
	{
		.Sensor_Dev_Index = P_SENSOR_SMP580_INDEX2,
		.Sensor_Dev_Type = P_SENSOR_GENERAL_TYPE_SMP580, 
	},
	{
		.Sensor_Dev_Index = P_SENSOR_SMP580_INDEX3,
		.Sensor_Dev_Type = P_SENSOR_GENERAL_TYPE_SMP580, 
	},
	{
		.Sensor_Dev_Index = P_SENSOR_SMP580_INDEX4,
		.Sensor_Dev_Type = P_SENSOR_GENERAL_TYPE_SMP580,
	},
	{
		.Sensor_Dev_Index = P_SENSOR_SMP580_INDEX5,
		.Sensor_Dev_Type = P_SENSOR_GENERAL_TYPE_SMP580,
	},
	{
		.Sensor_Dev_Index = P_SENSOR_SMP580_INDEX6,
		.Sensor_Dev_Type = P_SENSOR_GENERAL_TYPE_SMP580,
	},
	{
		.Sensor_Dev_Index = P_SENSOR_SMP580_INDEX7,
		.Sensor_Dev_Type = P_SENSOR_GENERAL_TYPE_SMP580,
	},
	{
		.Sensor_Dev_Index = P_SENSOR_SMP580_INDEX8,
		.Sensor_Dev_Type = P_SENSOR_GENERAL_TYPE_SMP580, 
	},
	{
		.Sensor_Dev_Index = P_SENSOR_SMP580_INDEX9,
		.Sensor_Dev_Type = P_SENSOR_GENERAL_TYPE_SMP580, 
	},
	#else
	{
		.Sensor_Dev_Index = P_SENSOR_NSPAD1_INDEX0,
		.Sensor_Dev_Type = P_SENSOR_GENERAL_TYPE_NSPAD1,
	},
	{
		.Sensor_Dev_Index = P_SENSOR_NSPAD1_INDEX1,
		.Sensor_Dev_Type = P_SENSOR_GENERAL_TYPE_NSPAD1, 
	},
	{
		.Sensor_Dev_Index = P_SENSOR_NSPAD1_INDEX2,
		.Sensor_Dev_Type = P_SENSOR_GENERAL_TYPE_NSPAD1, 
	},
	{
		.Sensor_Dev_Index = P_SENSOR_NSPAD1_INDEX3,
		.Sensor_Dev_Type = P_SENSOR_GENERAL_TYPE_NSPAD1, 
	},
	{
		.Sensor_Dev_Index = P_SENSOR_NSPAD1_INDEX4,
		.Sensor_Dev_Type = P_SENSOR_GENERAL_TYPE_NSPAD1,
	},
	{
		.Sensor_Dev_Index = P_SENSOR_NSPAD1_INDEX5,
		.Sensor_Dev_Type = P_SENSOR_GENERAL_TYPE_NSPAD1,
	},
	{
		.Sensor_Dev_Index = P_SENSOR_NSPAD1_INDEX6,
		.Sensor_Dev_Type = P_SENSOR_GENERAL_TYPE_NSPAD1,
	},
	{
		.Sensor_Dev_Index = P_SENSOR_NSPAD1_INDEX7,
		.Sensor_Dev_Type = P_SENSOR_GENERAL_TYPE_NSPAD1,
	},
	{
		.Sensor_Dev_Index = P_SENSOR_NSPAD1_INDEX8,
		.Sensor_Dev_Type = P_SENSOR_GENERAL_TYPE_NSPAD1, 
	},
	{
		.Sensor_Dev_Index = P_SENSOR_NSPAD1_INDEX9,
		.Sensor_Dev_Type = P_SENSOR_GENERAL_TYPE_NSPAD1, 
	},
	#endif
	{
		.Sensor_Dev_Index = P_SENSOR_GENERAL_INVALID_INDEX,
		.Sensor_Dev_Type = P_SENSOR_GENERAL_TYPE_SMP580,
	},
	{
		.Sensor_Dev_Index = P_SENSOR_GENERAL_INVALID_INDEX,
		.Sensor_Dev_Type = P_SENSOR_GENERAL_TYPE_SMP580,
	},
	{
		.Sensor_Dev_Index = P_SENSOR_GENERAL_INVALID_INDEX,
		.Sensor_Dev_Type = P_SENSOR_GENERAL_TYPE_SMP580,
	},
	{
		.Sensor_Dev_Index = P_SENSOR_GENERAL_INVALID_INDEX,
		.Sensor_Dev_Type = P_SENSOR_GENERAL_TYPE_SMP580,
	},
	{
		.Sensor_Dev_Index = P_SENSOR_GENERAL_INVALID_INDEX,
		.Sensor_Dev_Type = P_SENSOR_GENERAL_TYPE_SMP580,
	},


};



BOOL P_Sensor_PressureGet(P_SENSOR_GENERAL_INDEX opIndex,uint32_t* Pressure)
{
	BOOL RetVal = FALSE;
	if(opIndex <P_SENSOR_GENERAL_MAX_NUM)
	{
		if(P_SENSOR_GENERAL_INVALID_INDEX != P_Sensor_Index_ReferenceList[opIndex].Sensor_Dev_Index)
		{
			if(P_SENSOR_GENERAL_TYPE_SMP580 == P_Sensor_Index_ReferenceList[opIndex].Sensor_Dev_Type)
			{
				if(P_SENSOR_INIT_COMPLETE == PSensor_Init_Status)
				{
					RetVal = SMP580_App_PressureGet((P_SENSOR_SMP580_INDEX)P_Sensor_Index_ReferenceList[opIndex].Sensor_Dev_Index,Pressure);
				}
			}
			else if(P_SENSOR_GENERAL_TYPE_NSPAD1 == P_Sensor_Index_ReferenceList[opIndex].Sensor_Dev_Type)
			{
				if(P_SENSOR_INIT_COMPLETE == PSensor_Init_Status)
				{
					RetVal = NSPAD1_App_PressureGet((P_SENSOR_NSPAD1_INDEX)P_Sensor_Index_ReferenceList[opIndex].Sensor_Dev_Index,Pressure);
				}
			}
			else if(P_SENSOR_GENERAL_TYPE_NSPAS3 == P_Sensor_Index_ReferenceList[opIndex].Sensor_Dev_Type)
			{
				RetVal = NSPAS3_App_PressureGet(Pressure);
			}
			else if(P_SENSOR_GENERAL_TYPE_LPMSCA05 == P_Sensor_Index_ReferenceList[opIndex].Sensor_Dev_Type)
			{

			}
			else
			{

			}
		}
	}
	return RetVal;
}
BOOL P_Sensor_TemperatureGet(P_SENSOR_GENERAL_INDEX opIndex,int16_t* Temperature)
{
	BOOL RetVal = FALSE;
	if(opIndex <P_SENSOR_GENERAL_MAX_NUM)
	{
		if(P_SENSOR_GENERAL_INVALID_INDEX != P_Sensor_Index_ReferenceList[opIndex].Sensor_Dev_Index)
		{
			if(P_SENSOR_GENERAL_TYPE_SMP580 == P_Sensor_Index_ReferenceList[opIndex].Sensor_Dev_Type)
			{
				if(PSensor_Init_Status == P_SENSOR_INIT_COMPLETE)
				{
					RetVal = SMP580_App_TemperatureGet((P_SENSOR_SMP580_INDEX)P_Sensor_Index_ReferenceList[opIndex].Sensor_Dev_Index,Temperature);
				}
			}
			else if(P_SENSOR_GENERAL_TYPE_LPMSCA05 == P_Sensor_Index_ReferenceList[opIndex].Sensor_Dev_Type)
			{

			}
			else
			{

			}
		}
	}
	return RetVal;
}










void P_Sensor_Init(void)
{
	//SMP580_App_Init();
	//NSPAD1_App_Init();
	//LPMSCA05_App_Init();
}
void P_Sensor_DeInit(void)
{
	SMP580_App_DeInit();
	NSPAD1_App_DeInit();
}

void P_Sensor_Scheduler_Periodic_10mS(void)
{
	switch(PSensor_Init_Status)
	{
		case P_SENSOR_INIT_WAIT_POWER_STABILIZE:
			#if PRESSURE_USE_TYPE == PRESSURE_USE_TYPE_SMP581
				Spi_Init(NULL_PTR);
				SMP580_App_Init();
				PSensor_Init_Status = P_SENSOR_INIT_COMPLETE;
			#elif PRESSURE_USE_TYPE == PRESSURE_USE_TYPE_NSPAD1
				PSensor_Init_Delay++;
				if(PSensor_Init_Delay>T10_200MS)//T10_200MS T10_50MS
				{
					PSensor_Init_Status =P_SENSOR_INIT_REGISTER1_SET;
					PSensor_Init_Delay =0;
					Spi_Init(NULL_PTR);
					NSPAD1_App_Init();
					
				}
			#else

			#endif
			break;
		case P_SENSOR_INIT_REGISTER1_SET:
			#if PRESSURE_USE_TYPE == PRESSURE_USE_TYPE_NSPAD1
				PSensor_Init_Delay++;
				if(PSensor_Init_Delay>T10_100MS)
				{
					PSensor_Init_Status =P_SENSOR_INIT_REGISTER2_SET;
					PSensor_Init_Delay =0;
					NSPAD1_App_Register_Init();
				}
			#endif
			break;
		case P_SENSOR_INIT_REGISTER2_SET:
			#if PRESSURE_USE_TYPE == PRESSURE_USE_TYPE_NSPAD1
				PSensor_Init_Delay++;
				if(PSensor_Init_Delay>T10_10MS)
				{
					PSensor_Init_Status =P_SENSOR_INIT_COMPLETE;
					PSensor_Init_Delay =0;
					NSPAD1_App_Register2_Init();
				}
			#endif
			break;
		case P_SENSOR_INIT_COMPLETE: 
			break;
	}

}
