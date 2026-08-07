/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      AdcIf.h                                                                  */
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
#ifndef ADC_IF_H_
#define ADC_IF_H_


#include "ADC_DESC.h"



extern void ADCIf_Init(void);
extern void ADCIf_DeInit(void);
extern void ADCIf_Irq_Handler(void);
extern BOOL ADCIf_Periodic_10mS_Call_Func(void);
extern BOOL ADCIf_Periodic_1mS_Call_Func(void);

extern uint16_t ADCIf_Get_Normal_CalculateVoltage(uint8_t Ch);


#endif /* ADC_ADC_H_ */
