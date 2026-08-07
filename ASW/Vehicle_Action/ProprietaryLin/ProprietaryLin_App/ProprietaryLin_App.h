/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      ProprietaryLin_App.h                                                     */
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
#ifndef INCLUDE_PROPRIETARYLIN_APP_H_
#define INCLUDE_PROPRIETARYLIN_APP_H_

typedef enum
{
	BOOT_MODE = 0,			// Bootģʽ
	APP_MODE  = 1,			// Appģʽ

}BOOT_APP_MODE;

extern void ProprietaryLin_App_VersionRespond(volatile uint8_t *i_pDataBuf);
extern void ProprietaryLin_App_Init(void);
extern void ProprietaryLin_DriverWriteDataInProprietaryLin(volatile uint8_t *i_pDataBuf);
extern void ProprietaryLin_MainFun(void);


#endif /* INCLUDE_PROPRIETARYLIN_APP_H_ */
