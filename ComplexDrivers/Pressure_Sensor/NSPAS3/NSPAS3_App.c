/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      NSPAD1_App.c                                                             */
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

#include "include.h"

void NSPAS3_App_Init(void)
{
	
}
void NSPAS3_App_DeInit(void)
{

}
BOOL NSPAS3_App_PressureGet(uint32_t* Pressure)
{
	//uint  pa
	//VOUT = AD * 5000 / 4096
	//VOUT = (A * P + B) * VDDHV
	//VDDHV = 5v
	//P = (AD / 4096 - B)/A   ==>Kpa
	//P = (1000*AD-4096000*B)/(4096*A)  ==>Pa
	//A = 0.003696F
	//B = 0.006087F
	//P = (1000000*AD -24932352)/15139  ==>Pa

	#define A            15139U
    #define B            24932352U
	#define AMP_FACTOR   1000000U
    uint32_t Vout_AD_VAl =ADC_Get_Index10_Voltage;
	uint32_t Vout_Amp_AD = 0;
    uint32_t CalPressure =101325;
	uint8_t RetVal =FALSE;
    if( Vout_AD_VAl != ADC_VAL_INVALID )
   	{
		Vout_Amp_AD = Vout_AD_VAl*AMP_FACTOR;
		CalPressure =((Vout_Amp_AD- B)/A);
		RetVal =TRUE;
	}
	*Pressure = CalPressure;	
    
    return RetVal;
}

