/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      DFlashIf.h                                                               */
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
#ifndef _DATA_FLASH_IF_H_
#define _DATA_FLASH_IF_H_


#include "model_Cfg_feature.h"

/** 
  * @brief  HAL Status structures definition  
  */  
typedef enum 
{
	HAL_OK       = 0x00U,
	HAL_ERROR    = 0x01U,
	HAL_BUSY     = 0x02U,
	HAL_TIMEOUT  = 0x03U
} HAL_StatusTypeDef;



typedef enum 
{
	Mcu_Run_Area_Boot        = 0x00U,
	Mcu_Run_Area_App    	= 0x01U
} Mcu_Run_AreaDef;




extern uint8_t DFlashIf_McuRunAreaModuleSet(Mcu_Run_AreaDef opMode);

extern Mcu_Run_AreaDef DFlashIf_McuRunAreaModuleGet(void);

#endif /* _DATA_FLASH_IF_H_ */
