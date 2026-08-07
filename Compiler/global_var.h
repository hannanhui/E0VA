/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      global_var.h                                                             */
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

#ifndef GLOBAL_VARIABLE_H
#define GLOBAL_VARIABLE_H
#include "Type_Define.h"
#ifndef GLOBALS_MAIN
#define extern_var extern
#else
#define extern_var
#endif
extern_var uint16_t Reset_Flag;
//The bit definition is the same as RCM_SRS register

#define RESET_SOURCE_RST_BROWN_OUT       			 0
#define RESET_SOURCE_RST_SOFTWARE           1
#define RESET_SOURCE_RST_EXT_RESET_PIN            2
#define RESET_SOURCE_RST_POWER_ON                     3
#define RESET_SOURCE_RST_WATCH_DOG                       4




#define F_BROWN_OUT_RESET_Set  				SetBit(Reset_Flag, RESET_SOURCE_RST_BROWN_OUT)
#define F_BROWN_OUT_RESET_Clr  				ClrBit(Reset_Flag, RESET_SOURCE_RST_BROWN_OUT)
#define F_BROWN_OUT_RESET_Val  				ValBit(Reset_Flag, RESET_SOURCE_RST_BROWN_OUT)

#define F_SOFTWARE_RESET_Set      		SetBit(Reset_Flag, RESET_SOURCE_RST_SOFTWARE)
#define F_SOFTWARE_RESET_Clr      		ClrBit(Reset_Flag, RESET_SOURCE_RST_SOFTWARE)
#define F_SOFTWARE_RESET_Val      		ValBit(Reset_Flag, RESET_SOURCE_RST_SOFTWARE)

#define F_EXT_RESET_PIN_RESET_Set     		SetBit(Reset_Flag, RESET_SOURCE_RST_EXT_RESET_PIN)
#define F_EXT_RESET_PIN_RESET_Clr     		ClrBit(Reset_Flag, RESET_SOURCE_RST_EXT_RESET_PIN)
#define F_EXT_RESET_PIN_RESET_Val     		ValBit(Reset_Flag, RESET_SOURCE_RST_EXT_RESET_PIN)

#define F_POWER_ON_RESET_Set        				SetBit(Reset_Flag, RESET_SOURCE_RST_POWER_ON)
#define F_POWER_ON_RESET_Clr        				ClrBit(Reset_Flag, RESET_SOURCE_RST_POWER_ON)
#define F_POWER_ON_RESET_Val        				ValBit(Reset_Flag, RESET_SOURCE_RST_POWER_ON)

#define F_WATCH_DOG_RESET_Set     					SetBit(Reset_Flag, RESET_SOURCE_RST_WATCH_DOG)
#define F_WATCH_DOG_RESET_Clr     					ClrBit(Reset_Flag, RESET_SOURCE_RST_WATCH_DOG)
#define F_WATCH_DOG_RESET_Val     					ValBit(Reset_Flag, RESET_SOURCE_RST_WATCH_DOG)



#define F_RESET_SOURCE_DATA_Clr						ClrByte(Reset_Flag)



#endif



