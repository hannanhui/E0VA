/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      Param_Calibration.c                                                      */
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
static uint8_t PressureUseCfg =0U;
/*The finer the sampling point, the closer it is to the actual curve, the smaller the error */

#define D_NTC_CORRESPOND_LIST_NUM       141

const uint16_t  g_10K_PULLUP_NTC_TempCorresponding_ADCValList[D_NTC_CORRESPOND_LIST_NUM]={
	2630 ,2592 ,2553 ,2514 ,2475 ,2437 ,2397 ,2359 ,2319 ,2280,
	2241 ,2202 ,2163 ,2124 ,2085 ,2047 ,2009 ,1971 ,1933 ,1895,
	1858 ,1821 ,1785 ,1749 ,1713 ,1677 ,1642 ,1608 ,1574 ,1540,
	1507 ,1474 ,1442 ,1410 ,1379 ,1348 ,1318 ,1288 ,1259 ,1230,
	1202 ,1175 ,1147 ,1121 ,1095 ,1069 ,1044 ,1020 ,996 ,972,
	949 ,927 ,905 ,883 ,862 ,841 ,821 ,802 ,782 ,764 ,
	745 ,728 ,710 ,693 ,677 ,660 ,644 ,629 ,614 ,599 ,
	585 ,571 ,557 ,544 ,531 ,518 ,506 ,494 ,482 ,471 ,
	460 ,449 ,439 ,428 ,418 ,409 ,399 ,390 ,381 ,372 ,
	363 ,355 ,347 ,339 ,331 ,324 ,316 ,309 ,302 ,295 ,
	289 ,282 ,276 ,270 ,264 ,258 ,252 ,247 ,241 ,236 ,
	231 ,226 ,221 ,216 ,212 ,207 ,203 ,199 ,194 ,190 ,
	186 ,182 ,178 ,175 ,171 ,168 ,164, 161 ,157 ,154 ,
	151 ,148 ,145 ,142 ,140 ,136 ,134 ,131 ,129 ,126 ,124 ,

};
const uint16_t g_1K_PULLUP_NTC_TempCorresponding_ADCValList[D_NTC_CORRESPOND_LIST_NUM]={
	3879, 3870, 3861, 3852, 3843, 3834, 3824, 3814, 3803, 3793,
	3782, 3771, 3759, 3747, 3735, 3722, 3709, 3696, 3683, 3669,
	3655, 3640, 3625, 3610, 3595, 3579, 3563, 3546, 3529, 3512,
	3495, 3477, 3458, 3440, 3421, 3402, 3382, 3362, 3342, 3321,
	3301, 3279, 3258, 3236, 3214, 3192, 3169, 3146, 3123, 3099,
	3076, 3052, 3027, 3003, 2978, 2953, 2928, 2903, 2877, 2852,
	2826, 2800, 2774, 2747, 2721, 2694, 2667, 2641, 2613, 2587,
	2560, 2533, 2505, 2478, 2451, 2424, 2397, 2370, 2342, 2316,
	2288, 2261, 2234, 2207, 2180, 2154, 2127, 2100, 2074, 2048,
	2021, 1996, 1969, 1944, 1917, 1893, 1867, 1842, 1817, 1793,
	1768, 1744, 1719, 1696, 1671, 1648, 1625, 1602, 1579, 1556,
	1534, 1511, 1490, 1468, 1446, 1425, 1404, 1384, 1363, 1342,
	1324, 1303, 1284, 1265, 1245, 1227, 1209, 1190, 1172, 1155,
	1138, 1118, 1103, 1086, 1070, 1052, 1036, 1020, 1006, 990, 976,
};

void Param_Calibration_SensorUseCfgTypeSet(uint8_t opCfgType)
{
	PressureUseCfg = opCfgType;
}
uint8_t Param_Calibration_SensorUseCfgTypeGet(void)
{
	return PressureUseCfg;
}



/*==================================================================
* Function : AdcLookupNtcTemperature
* Description :According to the corresponding Adc interval, 
*              map the corresponding Ntc Temperature
* Input Para  
* Output Para  
* Return Value: 
==================================================================*/
uint8_t  Param_Calibration_AdcLookupNtcTemperature(uint16_t opAdcVal)
{
	uint8_t u8ReturnValue=0u;
	
    uint8_t  u8Index=0u;


	if(opAdcVal != 0u)
	{

		for(u8Index =0;u8Index<D_NTC_CORRESPOND_LIST_NUM;u8Index++)
		{

			if(opAdcVal >= g_10K_PULLUP_NTC_TempCorresponding_ADCValList[u8Index])
			{
				u8ReturnValue = 10 + u8Index;
				break;
			}


		}
		if(u8ReturnValue ==0u)
		{
			u8ReturnValue =150U;
		}
	}
	else
	{
		u8ReturnValue =0xFF;
	}


	return (u8ReturnValue);


}

