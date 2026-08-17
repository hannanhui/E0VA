/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      LIN_Trcv.c                                                               */
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
#include "LIN_Trcv.h"
#include "ECAL_PORT.h"
#include "Type_Define.h"
#include "Lin.h"
#include "Lin_LCfg.h"

static uint8_t Lin_TransceiverDrv_Module = LIN_TRCV_MODE_STANDBY;

void LinTrcv_Init(void)
{
    Lin_Init(&Lin_ConfigPredefined);
	Lin_TransceiverDrv_Module = LIN_TRCV_MODE_STANDBY;
}

BOOL LinTrcv_SetOpMode(LinTrcv_TrcvModeType OpMode) 
{
	BOOL Retval =FALSE;
	if(LIN_TRCV_MODE_NORMAL == OpMode)
	{
		SET_LIN_TRANSCEIVER_SLAVE_WORK_EN;

		Lin_TransceiverDrv_Module = LIN_TRCV_MODE_NORMAL;
		Retval =TRUE;
	}
	else
	{
		CLR_LIN_TRANSCEIVER_SLAVE_WORK_EN;

		Lin_TransceiverDrv_Module = LIN_TRCV_MODE_STANDBY;
		Retval =TRUE;

	}
	return Retval;
}
BOOL LinTrcv_GetOpMode(LinTrcv_TrcvModeType OpMode) 
{
	BOOL Retval =FALSE;
	if((LIN_TRCV_MODE_NORMAL == OpMode)&&(Lin_TransceiverDrv_Module == OpMode))
	{
		Retval =TRUE;
	}
	else if(((LIN_TRCV_MODE_STANDBY == OpMode))&&(Lin_TransceiverDrv_Module == OpMode))
	{
		Retval =TRUE;
	}
	else
	{
		Retval =FALSE;
	}
	return Retval;
}

