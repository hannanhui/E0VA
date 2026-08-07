/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      Param_Calibration.h                                                      */
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
#ifndef INCLUDE_PARAM_CALIBRATION_H_
#define INCLUDE_PARAM_CALIBRATION_H_
#include "model_Cfg_feature.h"


typedef enum
{
	Param_PressureUseNone = 0,
	Param_PressureUseSMP58X,
	Param_PressureUseNSPAD1
}Param_PressureUseCfg;



/*************************************************************************************************************************/
								
/*  ######################################################################################################################
	#################################################External call API####################################################	
**  ######################################################################################################################*/




/*************************************************************************************************************************
*Name		 : Param_Calibration_SensorUseCfgTypeSet
*Function	 :Set Sensor use type
*argument	 : uint8_t opCfgType
					Param_PressureUseNone = 0,
					Param_PressureUseSMP58X,
					Param_PressureUseNSPAD1
*Retval 	 : NONE
*explain	 :Set Sensor use type
*************************************************************************************************************************/
extern void Param_Calibration_SensorUseCfgTypeSet(uint8_t opCfgType);
/*************************************************************************************************************************
*Name		 : Param_Calibration_SensorUseCfgTypeSet
*Function	 :Set Sensor use type
*argument	 : NONE
*Retval 	 : uint8_t opCfgType
					Param_PressureUseNone = 0,
					Param_PressureUseSMP58X,
					Param_PressureUseNSPAD1
*explain	 :Set Sensor use type
*************************************************************************************************************************/

extern uint8_t Param_Calibration_SensorUseCfgTypeGet(void);




/*************************************************************************************************************************
*Name		 : Param_Calibration_AdcLookupNtcTemperature
*Function	 : Enter the ADC value and look up the corresponding temperature value in the table.
*argument	 : uint16_t opAdcVal
				The ADC value of the corresponding NTC channel
*Retval 	 : uint8_t Temperature:
				The returned temperature value ranges from 10 to 150 degrees Celsius. 
				If 0xFF is returned, it represents an invalid value.
*explain	 : Enter the ADC value and look up the corresponding temperature value in the table.
**************************************************************************************************************************/

/*************************************************************************************************************************/
extern uint8_t  Param_Calibration_AdcLookupNtcTemperature(uint16_t opAdcVal);


#endif /* INCLUDE_PARAM_CALIBRATION_H_ */
