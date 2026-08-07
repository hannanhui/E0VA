/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      ProprietaryLin_Tp.c                                                      */
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

#include "include.h"


static void Proprietary_Tx_Data_assignment(void)
{
	ProprietaryLin_App_VersionRespond(g_lin_Proprietary_Tx_data_buffer);

}
static void Proprietary_Tx_Complete(void)
{
	
}
static void Proprietary_Rx_Complete(void)
{
	ProprietaryLin_DriverWriteDataInProprietaryLin(g_lin_Proprietary_Rx_data_buffer);

}



void ProprietaryLin_Tp_Init(void)
{
	l_ifc_tl_InstallCallback_Proprietary_Tx_Data_assignment_LI0(Proprietary_Tx_Data_assignment);
	l_ifc_tl_InstallCallback_Proprietary_Tx_Complete_LI0(Proprietary_Tx_Complete);  	
	l_ifc_tl_InstallCallback_Proprietary_Rx_Complete_LI0(Proprietary_Rx_Complete);  
}





