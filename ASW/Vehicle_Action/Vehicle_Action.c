/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      Vehicle_Action.c                                                         */
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

#include "include.h"

uint8_t Boot_Major_Version[VERSION_INFO_MAX_SIZE];	// Boot主版本信息
uint8_t App_Major_Version[VERSION_INFO_MAX_SIZE];	// App主版本信息

uint8_t Boot_Minor_Version[VERSION_INFO_MAX_SIZE];	// Boot底层库版本信息
uint8_t App_Minor_Version[VERSION_INFO_MAX_SIZE];	// App底层库信息
ASM_POS      MX11_ASM_Pos;    

void Vehicle_Action_Bus_NADJduge(void)
{
	MX11_ASM_Pos = ASM_POS_FL;//DigitalIf_Device_Mounting_PositionGet();
	#if UPGRADE_MODE == UPGRADE_MODE_FOR_UDS_LIN
	if(ASM_POS_FL == MX11_ASM_Pos)
	{
		LINTP_DEVICE_NAD_Set(ASM_POS_FL_NAD);
		
	}
	else if(ASM_POS_FR  == MX11_ASM_Pos)
	{

		LINTP_DEVICE_NAD_Set(ASM_POS_FR_NAD);
		
	}
	else if(ASM_POS_RL  == MX11_ASM_Pos)
	{
		LINTP_DEVICE_NAD_Set(ASM_POS_RL_NAD);
	}
	else if(ASM_POS_RR  == MX11_ASM_Pos)
	{
		LINTP_DEVICE_NAD_Set(ASM_POS_RR_NAD);
	}
	#endif
}

void Vehicle_Action_Init(void)
{
	UDS_Tp_Init();
#if UPGRADE_MODE == UPGRADE_MODE_FOR_PROPRIETARY_LIN
	ProprietaryLin_Tp_Init();
#endif
	System_CAL_Version(BOOT_MAJOR_VERSION, Boot_Major_Version);
	System_CAL_Version(APP_MAJOR_VERSION, App_Major_Version);
	System_CAL_Version(BOOT_MINOR_VERSION, Boot_Minor_Version);
	System_CAL_Version(APP_MINOR_VERSION, App_Minor_Version);
	Vehicle_Action_Bus_NADJduge();
	#if UPGRADE_MODE == UPGRADE_MODE_FOR_PROPRIETARY_LIN
	
	ProprietaryLin_App_Init();
	#endif
	l_lld_Id_Stbl_use_index_Set_LI0(LI0_Schedule_Index0,TRUE);
#if (UPGRADE_MODE == UPGRADE_MODE_FOR_UDS_LIN)
	l_lld_Id_Respone_Set_LI0(LI0_Schedule_Index0,LI0_TBL0_DiagMasterReq,TRUE);
	l_lld_Id_Respone_Set_LI0(LI0_Schedule_Index0,LI0_TBL0_DiagSlaveResp,TRUE);
	l_lld_Id_Respone_Set_LI0(LI0_Schedule_Index0,LI0_TBL0_PrietaryMasterReq,FALSE);
	l_lld_Id_Respone_Set_LI0(LI0_Schedule_Index0,LI0_TBL0_PrietarySlaveResp,FALSE);
	g_lin_Diag_Tx_data_Len =0u;
	LINTP_DEVICE_NAD_Set(ASM_POS_FL_NAD);
	#else
	l_lld_Id_Respone_Set_LI0(LI0_Schedule_Index0,LI0_TBL0_DiagMasterReq,FALSE);
	l_lld_Id_Respone_Set_LI0(LI0_Schedule_Index0,LI0_TBL0_DiagSlaveResp,FALSE);
	l_lld_Id_Respone_Set_LI0(LI0_Schedule_Index0,LI0_TBL0_PrietaryMasterReq,TRUE);
	l_lld_Id_Respone_Set_LI0(LI0_Schedule_Index0,LI0_TBL0_PrietarySlaveResp,TRUE);
	g_lin_Diag_Tx_data_Len =0u;
	#endif
}
void Vehicle_Action_1mS(void)
{
	#if UPGRADE_MODE == UPGRADE_MODE_FOR_UDS_LIN
	UDS_SystemTickCtl();
	UDS_MainFun();
	#endif
	#if UPGRADE_MODE == UPGRADE_MODE_FOR_PROPRIETARY_LIN
	ProprietaryLin_MainFun();
	#endif
}
void Vehicle_Action_10mS(void)
{
	Vehicle_Action_Bus_NADJduge();
}



