/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      ProprietaryLin_App.h                                                     */
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
#ifndef INCLUDE_PROPRIETARYLIN_APP_H_
#define INCLUDE_PROPRIETARYLIN_APP_H_
#if UPGRADE_MODE == UPGRADE_MODE_FOR_PROPRIETARY_LIN
#include "Type_Define.h"
#define VERSION_MAJOR				0	// 主版本号

#define VERSION_REQ_NONE			0	// 无版本请求
#define VERSION_REQ_BOOT_MAJOR		1	// Boot主版本请求
#define VERSION_REQ_BOOT_MINOR		2	// Boot次版本请求
#define VERSION_REQ_APP_MAJOR		3	// App主版本请求
#define VERSION_REQ_APP_MINOR		4	// App次版本请求
#define UPDATE_PACKAGE_SIZE_BYTE		1024

typedef enum
{
	BOOT_MODE = 0,			// Boot模式
	APP_MODE  = 1,			// App模式

}BOOT_APP_MODE;
//#if UPGRADE_MODE == UPGRADE_MODE_FOR_PROPRIETARY_LIN

extern void ProprietaryLin_App_VersionRespond(volatile uint8_t *i_pDataBuf);
extern void ProprietaryLin_App_Init(void);
extern void ProprietaryLin_DriverWriteDataInProprietaryLin(volatile uint8_t *i_pDataBuf);
extern void ProprietaryLin_MainFun(void);
extern uint8_t ProprietaryLin_App_VersionReqFlagGet(void);
extern void ProprietaryLin_App_Update_Request(volatile uint8_t *i_pDataBuf);
#endif

#endif /* INCLUDE_PROPRIETARYLIN_APP_H_ */
