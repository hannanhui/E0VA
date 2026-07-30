/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      NVM_Handle.c                                                             */
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




uint8_t NVM_Handle_DataWriteOperate(NVM_Handle_WriteReadType opType,NVM_Handle_CodeFlashWriteType opWriteType,uint32_t addr,uint8_t * buff,uint32_t len)
{
	uint8_t RetVal = FALSE;
	if(NVM_Handle_CodeFlashData == opType)
	{
		if(NVM_Handle_CodeFlash_Erase_PageWrite == opWriteType)
		{
			RetVal = FlashIf_WritePageByte(addr,buff,len);
		}
		else if(NVM_Handle_CodeFlash_NErase_8BytesWrite == opWriteType)
		{
			RetVal = FlashIf_WriteMultiByteNoErase(addr,buff,len);

		}
	}

	return RetVal;
}
uint8_t NVM_Handle_DataReadOperate(NVM_Handle_WriteReadType opType,uint32_t addr,uint8_t * buff,uint32_t len)
{
	uint8_t RetVal = FALSE;
	uint32_t FlashChecksum=0;
	uint8_t i;
	uint8_t TmpBuf[4];
	if(NVM_Handle_CodeFlashData == opType)
	{
		if(len<4)
		{
			RetVal = FlashIf_ReadMultiByte(addr,TmpBuf,len);
			for(i=0;i<len;i++)
			{
				 buff[i] = TmpBuf[i];
			}
		}
		else
		{
			RetVal = FlashIf_ReadMultiByte(addr,buff,len);
		}
	}
	if(NVM_Handle_CodeFlashChecksum == opType)
	{
		FlashChecksum = FlashIf_CalCheckSum(addr,len);
		buff[0] = (FlashChecksum&0xFF);
		buff[1] = ((FlashChecksum>>8)&0xFF);
		buff[2] = ((FlashChecksum>>16)&0xFF);
		buff[3] = ((FlashChecksum>>24)&0xFF);
		RetVal = TRUE;
	}
	
	return RetVal;
}
uint8_t NVM_Handle_DataEraseOperate(NVM_Handle_WriteReadType opType,uint32_t addr)
{
	uint8_t RetVal = FALSE;
	if(NVM_Handle_CodeFlashData == opType)
	{
		RetVal = FlashIf_Erase_AppRunArea(addr);
	}
	return RetVal;
}


uint8_t NVM_Handle_RunAreaSet(NVM_Handle_Run_AreaDef opMode)
{
	return DFlashIf_McuRunAreaModuleSet((Mcu_Run_AreaDef)opMode);
}
NVM_Handle_Run_AreaDef NVM_Handle_RunAreaGet(void)
{
	return (NVM_Handle_Run_AreaDef)DFlashIf_McuRunAreaModuleGet();
}

