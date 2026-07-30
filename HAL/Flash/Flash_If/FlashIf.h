/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      FlashIf.h                                                                */
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
#ifndef _FLASH_IF_H_
#define _FLASH_IF_H_

extern uint8_t FlashIf_Erase_AppRunArea(uint32_t addr);

extern uint8_t FlashIf_WritePageByte(uint32_t addr,uint8_t * buff,uint32_t len);

extern uint32_t FlashIf_CalCheckSum(uint32_t addr ,uint32_t len );
extern uint8_t FlashIf_ReadMultiByte(uint32_t addr,uint8_t * buff,uint32_t len);
extern uint32_t FlashIf_WriteMultiByteNoErase(uint32_t addr,uint8_t * buff,uint32_t len);
extern uint8_t FlashIf_ReadMultiByte(uint32_t addr,uint8_t * buff,uint32_t len);
extern uint8_t EraseOneSector(uint32_t addr);
extern ResultStatus_t FlashInit(void);

#endif /* _FLASH_IF_H_ */
