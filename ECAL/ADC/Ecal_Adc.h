/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      Adc_H.h                                                                  */
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
#ifndef __ADC_CFG_H__
#define __ADC_CFG_H__

#include "model_Cfg_feature.h"
#include "Type_Define.h"
#include "Adc.h"
#include "CDD_Dma.h"
#include "ADC_DESC.h"
#include "AdcIf.h"



//Gets the ADC_Get_Index0_Voltage value after sampling average
//IGN

#define ADC_Get_Index0_Voltage  		 0U//ADCIf_Get_Normal_CalculateVoltage(ADC_INSIDE_CHANNEL_0)

//Gets the ADC_Get_Index1_Voltage value after sampling average
//
#define ADC_Get_Index1_Voltage  		 0U//ADCIf_Get_Normal_CalculateVoltage(ADC_INSIDE_CHANNEL_1)

//Gets the ADC_Get_Index2_Voltage value after sampling average
//Valve Current Det

#define ADC_Get_Index2_Voltage  		 	 ADCIf_Get_Normal_CalculateVoltage(ADC_INSIDE_CHANNEL_2)

//Gets the ADC_Get_Index3_Voltage value after sampling average
//Valve  Output Voltage Det

#define ADC_Get_Index3_Voltage  		 	 ADCIf_Get_Normal_CalculateVoltage(ADC_INSIDE_CHANNEL_3)

//Gets the ADC_Get_Index4_Voltage value after sampling average
//Batt Det

#define ADC_Get_Index4_Voltage  		 	 ADCIf_Get_Normal_CalculateVoltage(ADC_INSIDE_CHANNEL_4)

//Gets the ADC_Get_Index5_Voltage value after sampling average
//Version Det

#define ADC_Get_Index5_Voltage  		 	 ADCIf_Get_Normal_CalculateVoltage(ADC_INSIDE_CHANNEL_5)

//Gets the ADC_Get_Index6_Voltage value after sampling average
//Key1 ADC Det
#define ADC_Get_Index6_Voltage  		 	 ADCIf_Get_Normal_CalculateVoltage(ADC_INSIDE_CHANNEL_6)


//Gets the ADC_Get_Index7_Voltage value after sampling average
// NTC

#define ADC_Get_Index7_Voltage  		 	 ADCIf_Get_Normal_CalculateVoltage(ADC_INSIDE_CHANNEL_7)

//Gets the ADC_Get_Index8_Voltage value after sampling average
//Key3_AD

#define ADC_Get_Index8_Voltage  		 	 ADCIf_Get_Normal_CalculateVoltage(ADC_INSIDE_CHANNEL_8)

//Gets the ADC_Get_Index9_Voltage value after sampling average
//Key2_AD

#define ADC_Get_Index9_Voltage  		 	 ADCIf_Get_Normal_CalculateVoltage(ADC_INSIDE_CHANNEL_9)

//Gets the ADC_Get_Index10_Voltage value after sampling average

//NSPAS3 Pressure sensor Vout
#define ADC_Get_Index10_Voltage  		 	 ADCIf_Get_Normal_CalculateVoltage(ADC_INSIDE_CHANNEL_10)

//Gets the ADC_Get_Index11_Voltage value after sampling average
#define ADC_Get_Index11_Voltage  		 	 0U//ADCIf_Get_Normal_CalculateVoltage(ADC_INSIDE_CHANNEL_11)

//Gets the ADC_Get_Index12_Voltage value after sampling average
//Pump Voltage

#define ADC_Get_Index12_Voltage  		 	 ADCIf_Get_Normal_CalculateVoltage(ADC_INSIDE_CHANNEL_12)


//Gets the ADC_Get_Index13_Voltage value after sampling average
#define ADC_Get_Index13_Voltage  		 	 0U//ADCIf_Get_Normal_CalculateVoltage(ADC_INSIDE_CHANNEL_13)

//Gets the ADC_Get_Index14_Voltage value after sampling average
#define ADC_Get_Index14_Voltage  		 	 0U//ADCIf_Get_Normal_CalculateVoltage(ADC_INSIDE_CHANNEL_14)

//Gets the ADC_Get_Index15_Voltage value after sampling average
//pump current

#define ADC_Get_Index15_Voltage  		 	 ADCIf_Get_Normal_CalculateVoltage(ADC_INSIDE_CHANNEL_15)








#define ADC_AtOnce_Get_Valve_Diag_Voltage  	 //ADCIf_AtOnce_Get_NowVoltages(ADC_CHANNEL_BAT)


#define ADC_AtOnce_Get_Valve_Output_Voltage  	 //ADCIf_AtOnce_Get_NowVoltages(ADC_CHANNEL_VALVE_VOL)




#endif /* __ADC_CFG_H__ */
