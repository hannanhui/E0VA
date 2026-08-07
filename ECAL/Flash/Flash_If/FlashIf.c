/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      FlashIf.c                                                                */
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
#include "model_Cfg_feature.h"
#include "..\Flash_Cfg\Flash_Cfg.h"
#include "FlashIf.h"
#include "Fls.h" 
uint8_t HAL_FLASH_McuRunAreaModuleSet(uint32_t mode_num)
{

	uint8_t buf[16]={0xff};
	uint8_t Index=0;
	uint8_t CompareResult=TRUE;
	uint8_t read_buff[16]={0xff};
	buf[3] = ((mode_num>>24)&0xFF);
	buf[2] = ((mode_num>>16)&0xFF);
	buf[1] = ((mode_num>>8)&0xFF);
	buf[0] = ((mode_num)&0xFF);
  if( E_OK != Fls_Read(UPDATE_FLAG_BASE_ADDRESS, read_buff, 16))
	{
			return FALSE;
	}
	while(MEMIF_IDLE != Fls_GetStatus())
	{
			Fls_MainFunction();
	}
	if(Fls_GetJobResult() != MEMIF_JOB_OK)
	{
			return FALSE;
	}
	for(Index=0;Index<4;Index++)
	{
			if(buf[Index] != read_buff[Index])
			{
				  CompareResult =FALSE;
			}
	}
	if(CompareResult == TRUE)
	{
			return TRUE;	//The setting value is the same as the current value
	}
	else
	{
		
		/* erase operation */
		if(Fls_Erase(UPDATE_FLAG_BASE_ADDRESS, 0x2000) != E_OK)
		{
				return FALSE;
		}
		while(MEMIF_IDLE != Fls_GetStatus())
		{
				Fls_MainFunction();
		}
		if(Fls_GetJobResult() != MEMIF_JOB_OK)
		{
				return FALSE;
		}
			 /* write operation */
    if(Fls_Write(UPDATE_FLAG_BASE_ADDRESS, buf, 4) != E_OK)
    {
        return FALSE;
    }
    while(MEMIF_IDLE != Fls_GetStatus())
    {
        Fls_MainFunction();
    }
    if(Fls_GetJobResult() != MEMIF_JOB_OK)
    {
        return FALSE;
    }
		CompareResult=TRUE;
		if( E_OK != Fls_Read(UPDATE_FLAG_BASE_ADDRESS, read_buff, 16))
		{
				return FALSE;
		}
		while(MEMIF_IDLE != Fls_GetStatus())
		{
				Fls_MainFunction();
		}
		if(Fls_GetJobResult() != MEMIF_JOB_OK)
		{
				return FALSE;
		}
		for(Index=0;Index<4;Index++)
		{
				if(buf[Index] != read_buff[Index])
				{
						CompareResult =FALSE;
				}
		}
		if(CompareResult == TRUE)
		{
				return TRUE;	//The setting value is the same as the current value
		}
		else
		{
				return FALSE;
		}		
	}
}
uint8_t DFlashIf_McuRunAreaModuleSet(Mcu_Run_AreaDef opMode)
{
	uint8_t RetVal=0u;
	if(Mcu_Run_Area_Boot == opMode)
	{
		RetVal = HAL_FLASH_McuRunAreaModuleSet(BOOT_MODE_FLAG);
	}
	else if(Mcu_Run_Area_App == opMode)
	{
		RetVal = HAL_FLASH_McuRunAreaModuleSet(APP_MODE_FLAG);
	}
	else
	{
		RetVal=0u;
	}
    return RetVal;
}

Mcu_Run_AreaDef DFlashIf_McuRunAreaModuleGet(void)
{
	uint32_t ReadBackRunArea=0u;
	Mcu_Run_AreaDef RetVal=Mcu_Run_Area_Boot;
	uint8_t buf[16]={0xff};
	uint8_t Index=0;
	uint8_t CompareResult=TRUE;
	uint8_t read_buff[16]={0xff};
	buf[3] = ((BOOT_MODE_FLAG>>24)&0xFF);
	buf[2] = ((BOOT_MODE_FLAG>>16)&0xFF);
	buf[1] = ((BOOT_MODE_FLAG>>8)&0xFF);
	buf[0] = ((BOOT_MODE_FLAG)&0xFF);
  if( E_OK != Fls_Read(UPDATE_FLAG_BASE_ADDRESS, read_buff, 16))
	{
			return FALSE;
	}
	while(MEMIF_IDLE != Fls_GetStatus())
	{
			Fls_MainFunction();
	}
	if(Fls_GetJobResult() != MEMIF_JOB_OK)
	{
			return FALSE;
	}
	for(Index=0;Index<4;Index++)
	{
			if(buf[Index] != read_buff[Index])
			{
				  CompareResult =FALSE;
			}
	}
	if(CompareResult == TRUE)
	{
			RetVal =  Mcu_Run_Area_Boot;
	}
	else
	{
		//Set default run area is App
		if(DFlashIf_McuRunAreaModuleSet(Mcu_Run_Area_App))
		{
			RetVal =  Mcu_Run_Area_App;
		}
	}
	return RetVal;
}

