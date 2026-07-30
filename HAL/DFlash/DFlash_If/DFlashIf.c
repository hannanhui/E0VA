/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      DFlashIf.c                                                               */
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
#include "..\DFlash.h"
#include "Common.h"
#include<string.h>













/**
  * @brief  Perform a mass erase or erase the specified FLASH memory pages
  * @note   To correctly run this function, the @ref HAL_FLASH_Unlock() function
  *         must be called before.
  *         Call the @ref HAL_FLASH_Lock() to disable the flash memory access 
  *         (recommended to protect the FLASH memory against possible unwanted operation)
  * @param[in]  pEraseInit pointer to an FLASH_EraseInitTypeDef structure that
  *         contains the configuration information for the erasing.
  *
  * @param[out]  PageError pointer to variable  that
  *         contains the configuration information on faulty page in case of error
  *         (0xFFFFFFFF means that all the pages have been correctly erased)
  *
  * @retval HAL_StatusTypeDef HAL Status
  */
HAL_StatusTypeDef HAL_FLASHEx_Erase(uint32_t addr)
{
	HAL_StatusTypeDef status = HAL_OK;
	uint32_t address = addr;
	if(!EraseOneSector(address))
    {
        status = HAL_ERROR;
    }
	return status;
}

HAL_StatusTypeDef HAL_FLASH_ProgramData(uint16_t size, uint32_t Address, uint8_t *buf)
{
	HAL_StatusTypeDef status = HAL_OK;
	if(!FlashIf_WriteMultiByteNoErase(Address,buf,size))
    {
        status = HAL_ERROR;
    }
	return status;

}
HAL_StatusTypeDef HAL_FLASH_ProgramHALFWORD(uint32_t Address, uint16_t Data)
{
	HAL_StatusTypeDef status = HAL_OK;
	uint8_t buf[16]={0xFF};
	buf[0] = ((Data>>8)&0xFF);
	buf[1] = ((Data)&0xFF);
	if(!FlashIf_WriteMultiByteNoErase(Address,buf,16))
    {
        status = HAL_ERROR;
    }
	return status;

}

void HAL_FLASH_Read(uint16_t size, uint32_t Address, uint8_t *buf)
{
	FlashIf_ReadMultiByte(Address,(uint8_t *)buf,size);

}

uint8_t HAL_FLASH_McuRunAreaModuleSet(uint32_t mode_num)
{

	uint8_t buf[16]={0xff};
	
	if(*(uint32_t *)UPDATE_FLAG_BASE_ADDRESS == mode_num)
    {
        return TRUE;	//The setting value is the same as the current value
    }
	else
	{
		buf[3] = ((mode_num>>24)&0xFF);
		buf[2] = ((mode_num>>16)&0xFF);
		buf[1] = ((mode_num>>8)&0xFF);
		buf[0] = ((mode_num)&0xFF);
		HAL_FLASHEx_Erase(UPDATE_FLAG_BASE_ADDRESS);	
		HAL_FLASH_ProgramData(16,UPDATE_FLAG_BASE_ADDRESS,buf);
		if(*(uint32_t *)UPDATE_FLAG_BASE_ADDRESS == mode_num)
	    {
	        return TRUE;	//Write accurately
	    }
	    else
	    {
	        return FALSE;	//Write error
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
	ReadBackRunArea = *(uint32_t *)UPDATE_FLAG_BASE_ADDRESS;
	if(ReadBackRunArea == BOOT_MODE_FLAG)
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







