/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      ProprietaryLin_Tp.h                                                      */
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
#ifndef INCLUDE_PROPRIETARYLIN_TP_H_
#define INCLUDE_PROPRIETARYLIN_TP_H_

#if UPGRADE_MODE == UPGRADE_MODE_FOR_PROPRIETARY_LIN
#define TP_VERSION_REQ_NONE			0	

extern void ProprietaryLin_Tp_Init(void);
#endif
#endif /* INCLUDE_PROPRIETARYLIN_TP_H_ */
