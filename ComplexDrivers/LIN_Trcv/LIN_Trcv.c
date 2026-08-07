/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      LIN_Trcv.c                                                               */
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



#include "Lin.h"
#include "Ecal_PORT.h"
#include "LIN_Trcv.h"
static uint8_t Lin_Transceiver0Drv_Module = LIN_TRCV_MODE_STANDBY;
static uint8_t Lin_Transceiver1Drv_Module = LIN_TRCV_MODE_STANDBY;

BOOL LinTrcv_SetOpMode(LinTrcv_TrcvIndex OpIndex,LinTrcv_TrcvModeType OpMode) 
{
	BOOL Retval =FALSE;
	if(LIN_TRCV_INDEX0 == OpIndex)
	{
		#if (MCU_LIN_MASTER_USE_DEFINE == STD_ON)
		if(LIN_TRCV_MODE_NORMAL == OpMode)
		{
			SET_LIN_TRANSCEIVER_MASTER_WORK_EN;
			Lin_Transceiver0Drv_Module = LIN_TRCV_MODE_NORMAL;
			Retval =TRUE;
		}
		else
		{
			CLR_LIN_TRANSCEIVER_MASTER_WORK_EN;
			Lin_Transceiver0Drv_Module = LIN_TRCV_MODE_STANDBY;
			Retval =TRUE;
		}
		#endif
	}
	else
	{
		#if (MCU_LIN_SLAVE_USE_DEFINE == STD_ON)
		if(LIN_TRCV_MODE_NORMAL == OpMode)
		{
			SET_LIN_TRANSCEIVER_SLAVE_WORK_EN;
			Lin_Transceiver1Drv_Module = LIN_TRCV_MODE_NORMAL;
			Retval =TRUE;
		}
		else
		{
			CLR_LIN_TRANSCEIVER_SLAVE_WORK_EN;
			Lin_Transceiver1Drv_Module = LIN_TRCV_MODE_STANDBY;
			Retval =TRUE;
		}
		#endif
	}
	return Retval;
}
BOOL LinTrcv_GetOpMode(LinTrcv_TrcvIndex OpIndex,LinTrcv_TrcvModeType OpMode) 
{
	BOOL Retval =FALSE;
	if(LIN_TRCV_INDEX0 == OpIndex)
	{
		#if (MCU_LIN_MASTER_USE_DEFINE == STD_ON)
			if((LIN_TRCV_MODE_NORMAL == OpMode)&&(Lin_Transceiver0Drv_Module == OpMode))
			{
				Retval =TRUE;
			}
			else if((LIN_TRCV_MODE_STANDBY == OpMode)&&(Lin_Transceiver0Drv_Module == OpMode))
			{
				Retval =TRUE;
			}
			else
			{
				Retval =FALSE;
			}
		#endif
	}
	else
	{
		#if (MCU_LIN_SLAVE_USE_DEFINE == STD_ON)
			if((LIN_TRCV_MODE_NORMAL == OpMode)&&(Lin_Transceiver1Drv_Module == OpMode))
			{
				Retval =TRUE;
			}
			else if((LIN_TRCV_MODE_STANDBY == OpMode)&&(Lin_Transceiver1Drv_Module == OpMode))
			{
				Retval =TRUE;
			}
			else
			{
				Retval =FALSE;
			}
		#endif
	}
	return Retval;
}
void LinTrcv_Init(void)
{
	Lin_Init(&Lin_Config);
	Lin_WakeupInternal(LinConf_LinChannel_LinChannel_0_Slave);
	#if (MCU_LIN_MASTER_USE_DEFINE == STD_ON)
	LinTrcv_SetOpMode(LIN_TRCV_INDEX0,LIN_TRCV_MODE_NORMAL);
	Lin_WakeupInternal(LinConf_LinChannel_LinChannel_1_Master);
	#endif

	#if (MCU_LIN_SLAVE_USE_DEFINE == STD_ON)
	LinTrcv_SetOpMode(LIN_TRCV_INDEX1,LIN_TRCV_MODE_NORMAL);
	#endif
}


