/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      ProprietaryLin_Tp.c                                                      */
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

#if UPGRADE_MODE == UPGRADE_MODE_FOR_PROPRIETARY_LIN

static void Proprietary_Tx_Data_assignment(void)
{
	//#if UPGRADE_MODE == UPGRADE_MODE_FOR_PROPRIETARY_LIN
	if(TP_VERSION_REQ_NONE == ProprietaryLin_App_VersionReqFlagGet())
	{
		ProprietaryLin_App_Update_Request(g_lin_Proprietary_Tx_data_buffer);
	}
	else
	{
		ProprietaryLin_App_VersionRespond(g_lin_Proprietary_Tx_data_buffer);
	}
	//#endif
}
static void Proprietary_Tx_Complete(void)
{
	
}
static void Proprietary_Rx_Complete(void)
{
	//#if UPGRADE_MODE == UPGRADE_MODE_FOR_PROPRIETARY_LIN
	ProprietaryLin_DriverWriteDataInProprietaryLin(g_lin_Proprietary_Rx_data_buffer);
	//#endif
}



void ProprietaryLin_Tp_Init(void)
{
	l_ifc_tl_InstallCallback_Proprietary_Tx_Data_assignment_LI0(Proprietary_Tx_Data_assignment);
	l_ifc_tl_InstallCallback_Proprietary_Tx_Complete_LI0(Proprietary_Tx_Complete);  	
	l_ifc_tl_InstallCallback_Proprietary_Rx_Complete_LI0(Proprietary_Rx_Complete);  
}

#endif



