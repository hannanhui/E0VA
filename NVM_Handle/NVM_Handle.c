/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      NVM_Handle.c                                                             */
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




uint8_t NVM_Handle_DataWriteOperate(NVM_Handle_WriteReadType opType,uint32_t addr,uint8_t * buff,uint32_t len)
{
	uint8_t RetVal = FALSE;

	return RetVal;
}
uint8_t NVM_Handle_DataReadOperate(NVM_Handle_WriteReadType opType,uint32_t addr,uint8_t * buff,uint32_t len)
{
	uint8_t RetVal = FALSE;
	return RetVal;
}
uint8_t NVM_Handle_DataEraseOperate(NVM_Handle_WriteReadType opType,uint32_t addr)
{
	uint8_t RetVal = FALSE;

	return RetVal;
}


uint16_t NVM_Handle_ModuleInit(void)
{
	uint8_t EeInitStatus=FALSE;
	
	return EeInitStatus;
}
uint8_t NVM_Handle_RunAreaSet(NVM_Handle_Run_AreaDef opMode)
{
	return DFlashIf_McuRunAreaModuleSet((Mcu_Run_AreaDef)opMode);

}
NVM_Handle_Run_AreaDef NVM_Handle_RunAreaGet(void)
{
	return (NVM_Handle_Run_AreaDef)DFlashIf_McuRunAreaModuleGet();
}

