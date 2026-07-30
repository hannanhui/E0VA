/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      Common.h                                                                 */
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
#ifndef COMPILER_COMMON_H_
#define COMPILER_COMMON_H_
#include "Type_Define.h"


//#define SPI_INTERFACE
#ifdef COMMON_C__
#define COMMON_INTERFACE
#else
#define COMMON_INTERFACE extern
#endif
extern void check_failed(uint8_t *File, uint32_t Line);
//#define System_Check_Failed() Check_Failed(__FILE__, __LINE__)
//#define CHECK_RESTRICTION(expr) ((expr) ? (void)0 : check_failed((uint8_t *)__FILE__, __LINE__))

COMMON_INTERFACE uint16_t CommCrcCout(uint8_t *message, uint16_t len);

COMMON_INTERFACE uint8_t CommCrcCal_crc8(uint8_t* pData, uint16_t Len, uint8_t Init_Val);

COMMON_INTERFACE void Delay_us(void);
#endif /* COMPILER_COMMON_H_ */
