/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      Common.h                                                                 */
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
#ifndef COMPILER_COMMON_H_
#define COMPILER_COMMON_H_
#include "Type_Define.h"


//#define SPI_INTERFACE
#ifdef COMMON_C__
#define COMMON_INTERFACE
#else
#define COMMON_INTERFACE extern
#endif
//COMMON_INTERFACE void memset(unsigned char buff[],unsigned char data,uint16 length);	//PRQA S 4604

//COMMON_INTERFACE unsigned char memcpy(unsigned char to[], unsigned char from[],uint16 size);	//PRQA S 4604
COMMON_INTERFACE uint8 Hex2Bcd(uint8 hex);
COMMON_INTERFACE uint8 ByteCmpAbs(uint8 buf1 ,uint8 buf2);
COMMON_INTERFACE void SortU16FromMinToMax(uint16* buf,uint8 size);

COMMON_INTERFACE void GetArrMaxAndMinVal(int arr[], int size, int* max, int* min);


COMMON_INTERFACE uint16_t CommCrcCout(uint8_t *message, uint16_t len);


COMMON_INTERFACE void Delay_us(void);
#endif /* COMPILER_COMMON_H_ */
