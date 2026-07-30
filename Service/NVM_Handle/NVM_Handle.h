/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      NVM_Handle.h                                                             */
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
#ifndef INCLUDE_NVM_HANDLE_H_
#define INCLUDE_NVM_HANDLE_H_



typedef enum 
{
	NVM_Handle_Run_At_Boot        = 0x00U,
	NVM_Handle_Run_At_App    	= 0x01U
} NVM_Handle_Run_AreaDef;


typedef enum 
{
	NVM_Handle_CodeFlashData        = 0x00U,
	NVM_Handle_CodeFlashChecksum
} NVM_Handle_WriteReadType;
typedef enum
{
	NVM_Handle_CodeFlash_Erase_PageWrite        = 0x00U,
	NVM_Handle_CodeFlash_NErase_8BytesWrite
} NVM_Handle_CodeFlashWriteType;
extern uint8_t NVM_Handle_DataWriteOperate(NVM_Handle_WriteReadType opType,NVM_Handle_CodeFlashWriteType opWriteType,uint32_t addr,uint8_t * buff,uint32_t len);
extern uint8_t NVM_Handle_DataReadOperate(NVM_Handle_WriteReadType opType,uint32_t addr,uint8_t * buff,uint32_t len);
extern uint8_t NVM_Handle_DataEraseOperate(NVM_Handle_WriteReadType opType,uint32_t addr);
extern uint8_t NVM_Handle_RunAreaSet(NVM_Handle_Run_AreaDef opMode);
extern NVM_Handle_Run_AreaDef NVM_Handle_RunAreaGet(void);

#endif /* INCLUDE_NVM_HANDLE_H_ */
