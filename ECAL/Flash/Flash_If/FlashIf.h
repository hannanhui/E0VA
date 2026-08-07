/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      FlashIf.h                                                                */
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
#ifndef _FLASH_IF_H_
#define _FLASH_IF_H_

typedef enum 
{
	Mcu_Run_Area_Boot        = 0x00U,
	Mcu_Run_Area_App    	= 0x01U
} Mcu_Run_AreaDef;


extern uint8_t DFlashIf_McuRunAreaModuleSet(Mcu_Run_AreaDef opMode);

extern Mcu_Run_AreaDef DFlashIf_McuRunAreaModuleGet(void);

#endif /* _FLASH_IF_H_ */
