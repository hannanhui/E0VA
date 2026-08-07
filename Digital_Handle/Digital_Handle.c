/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      Digital_Handle.c                                                         */
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


static uint8_t Hardware_VerState = 0;

static uint8_t Hsd_Valve_PowerEn_ON_OffFlag = 0;
static uint8_t Hsd_Pump_PowerEn_ON_OffFlag = 0;
#define HW_CHECK_TIMER   T10_50MS
#define COMPATIBILITYHW_CHECK_TIMEOUT_TIMER   T10_200MS

static volatile uint8_t HWCheckCount =0;
static volatile uint8_t HwCompatibilityCheckCount =0U;
static volatile uint8_t HwCompatibilityCheck_Timeout =0U;


static volatile uint8_t  TempHWCurrVer = Digital_Hardware_ver_A0;

static volatile uint8_t  g_hardware_ver = Digital_Hardware_ver_A0;
unsigned char avHWVersion[D_LEN_HW_VERSION] = HW_DEF_VERSION;
POWER_IC_DIAG_FILTER_STRUCT IC_Diag_Filter[Power_Ic_Num];

uint8_t Pump_bufferArryFullFlag=0;
uint8_t Pump_VolShift_Index=0;
uint32_t Pump_VolShift_bufferBackupArry[SHIFT_BUFFER_SIZE]={0};
uint32_t Pump_VolShift_bufferArry[SHIFT_BUFFER_SIZE]={0};
uint32_t Pump_OutputPoint_Voltage=0;

// 设置硬件版本与电压的对应关系
/*
_____________________________________________
|               硬件版本电路值              |
|-------------------------------------------|
|   R98   |   R99   |   电压值   |   版本   |
|-------------------------------------------|
|   100K  |   10K   |   0.454V   |    A0    |
|-------------------------------------------|
|   100K  |   47K   |   1.598V   |    A1    |
|-------------------------------------------|
|   470K  |   470K  |   2.50V    |    A2    |
|-------------------------------------------|
|   20K   |   56K   |   3.684V   |    A3    |
|-------------------------------------------|
|   4.7K  |   56K   |   4.613V   |    A4    |
|-------------------------------------------|
*/
const Hw_Version_List HwVersion_Info[HW_VERSION_NUM] =
{
	{"A00", 	  0,	840},		    //0-1.025V
	{"A01", 	  841, 1678},		    //1.026-2.048V
	{"A02", 	  1679,	2532},		    //2.05-3.09V
	{"A03", 	  2533, 3397},		    //3.10-4.147V
	{"A04", 	  3398, 4095},		    //4.148-5V
};



/*************************************************************************************************************************
*Name		 : DigitalIf_IoRd_DataGet
*Function	 : Obtain the pin level state corresponding to opIndex
*argument	 : Digital_IoRd_Index opIndex
					Digital_IoRd_Index0, // Reserve the index of I/O
					Digital_IoRd_Index1, // Reserve the index of I/O
					Digital_IoRd_Index2, // Reserve the index of I/O
					Digital_IoRd_Index3, // Reserve the index of I/O
					Digital_IoRd_Index4, // Reserve the index of I/O
					Digital_IoRd_Index5, // Reserve the index of I/O
					Digital_IoRd_Index6, // Reserve the index of I/O
					Digital_IoRd_Index7, // Reserve the index of I/O
					Digital_IoRd_Index8, // Reserve the index of I/O
					Digital_IoRd_Index9, // Reserve the index of I/O
					Digital_IoRd_Index10, // Reserve the index of I/O
					Digital_IoRd_Index11, // Reserve the index of I/O
					Digital_IoRd_Index12, // Reserve the index of I/O
					Digital_IoRd_Index13, // Reserve the index of I/O
					Digital_IoRd_Index14, // Reserve the index of I/O
					Digital_IoRd_Index15, // Reserve the index of I/O  
*Retval 	 : uint8_t
				--The pin level state corresponding to opIndex
					0 PIN Level Low
					0 PIN Level High
*explain	 :Obtain the pin level state corresponding to opIndex
*************************************************************************************************************************/


	
uint8_t DigitalIf_IoRd_DataGet(Digital_IoRd_Index opIndex)
{
	uint8_t IoRd_Val=0;
	switch(opIndex)
	{
		case Digital_IoRd_Index0:
			IoRd_Val = 0;
		break;
		case Digital_IoRd_Index1:
			IoRd_Val = 0;
		break;
		case Digital_IoRd_Index2:
			IoRd_Val = 0;
		break;
		case Digital_IoRd_Index3:
			IoRd_Val = 0;
		break;
		case Digital_IoRd_Index4:
			IoRd_Val = 0;
		break;
		case Digital_IoRd_Index5:
			IoRd_Val = 0;
		break;
		case Digital_IoRd_Index6:
			IoRd_Val = 0;
		break;
		case Digital_IoRd_Index7:
			IoRd_Val = 0;
		break;
		case Digital_IoRd_Index8:
			IoRd_Val = 0;
		break;
		case Digital_IoRd_Index9:
			IoRd_Val = 0;
		break;
		case Digital_IoRd_Index10:
			IoRd_Val = 0;
		break;
		case Digital_IoRd_Index11:
			IoRd_Val = 0;
		break;
		case Digital_IoRd_Index12:
			IoRd_Val = 0;
		break;
		case Digital_IoRd_Index13:
			IoRd_Val = 0;
		break;
		case Digital_IoRd_Index14:
			IoRd_Val = 0;
		break;
		case Digital_IoRd_Index15:
			IoRd_Val = 0;
		break;
		default:
			break;
	}
	
	return IoRd_Val;
}


/*************************************************************************************************************************
*Name		 : DigitalIf_IoWt_DataSet
*Function	 : Set the pin level state corresponding to opIndex
*argument	 : Digital_IoWt_Index opIndex
					Digital_IoWt_Index0, // PB11 Pump output Ctrl En
					Digital_IoWt_Index1, // PE1 MCU Ctrl output 5V En
					Digital_IoWt_Index2, // PE0 HSD Valve Pump Power Supply En
					Digital_IoWt_Index3, // PB5 BATT+ Det Ctrl En
					Digital_IoWt_Index4, // PA12 HSD Valve Pump Power Supply Diag En
					Digital_IoWt_Index5, // Reserve the index of I/O
					Digital_IoWt_Index6, // HSD SEL0 
					Digital_IoWt_Index7, // HSD SEL1 
					Digital_IoWt_Index8, // Reserve the index of I/O
					Digital_IoWt_Index9, // HSD FAULT RESET (Based on this pin, it determines whether the HSD remains off or keeps restarting after the fault recovery.)
					Digital_IoWt_Index10, // Reserve the index of I/O
					Digital_IoWt_Index11, // Reserve the index of I/O
					Digital_IoWt_Index12, // Reserve the index of I/O
					Digital_IoWt_Index13, // Reserve the index of I/O
					Digital_IoWt_Index14, // Reserve the index of I/O
					Digital_IoWt_Index15, // Reserve the index of I/O  
			   uint8_t opStatus
			   		0 Set PIN Level Low
					1 Set PIN Level High
*Retval 	 : NONE
*explain	 :Set the pin level state corresponding to opIndex
*************************************************************************************************************************/

void DigitalIf_IoWt_DataSet(Digital_IoWt_Index opIndex,uint8_t opStatus)
{
	switch(opIndex)
	{
		case Digital_IoWt_Index0:		
			if(opStatus)
			{
				SET_HSD_PUMP_POWER_SUPPLY_EN;
				Hsd_Pump_PowerEn_ON_OffFlag = TRUE;
			}
			else
			{
				CLR_HSD_PUMP_POWER_SUPPLY_EN;
				Hsd_Pump_PowerEn_ON_OffFlag = FALSE;
			}		
		break;
		case Digital_IoWt_Index1:
			if(opStatus)
			{
				SET_MCU_CONTROL_5V_POWER_EN_EN;
			}
			else
			{
				CLR_MCU_CONTROL_5V_POWER_EN_EN;
			}
		break;
		case Digital_IoWt_Index2:
			if(opStatus)
			{
				Hsd_Valve_PowerEn_ON_OffFlag =TRUE;
				SET_HSD_VALVE_POWER_SUPPLY_EN;
			}
			else
			{
				Hsd_Valve_PowerEn_ON_OffFlag = FALSE;
				CLR_HSD_VALVE_POWER_SUPPLY_EN;
			}
		break;
		case Digital_IoWt_Index3:
			if(opStatus)
			{
				SET_BATT_VOLTAGE_DET_EN;
			}
			else
			{
				CLR_BATT_VOLTAGE_DET_EN;
			}
		break;

		case Digital_IoWt_Index4:		
			if(opStatus)
			{
				SET_HSD_VALVE_POWER_SUPPLY_DIAG_EN;
			}
			else
			{
				CLR_HSD_VALVE_POWER_SUPPLY_DIAG_EN;
			}
		break;
		case Digital_IoWt_Index5:
			if(opStatus)
			{
				//SET_VALVE_POWER_OUTPUT_EN;
			}
			else
			{
				//CLR_VALVE_POWER_OUTPUT_EN;
			}
		break;
		case Digital_IoWt_Index6:
			if(opStatus)
			{
				//SET_HSD_SEL0_EN ;
			}
			else
			{
				//CLR_HSD_SEL0_EN ;
			}
		break;
		case Digital_IoWt_Index7:
			if(opStatus)
			{
				//SET_HSD_SEL1_EN ;
			}
			else
			{
				//CLR_HSD_SEL1_EN ;
			}
		break;
		case Digital_IoWt_Index8:
			if(opStatus)
			{
				SET_HSD_PUMP_POWER_SUPPLY_DIAG_EN ;
				
			}
			else
			{
				CLR_HSD_PUMP_POWER_SUPPLY_DIAG_EN ;
				
			}
		break;
		case Digital_IoWt_Index9:
			if(opStatus)
			{
				//SET_FAULTRESET_EN ;
			}
			else
			{
				//CLR_FAULTRESET_EN ;
			}
		break;
		case Digital_IoWt_Index10:
			
		break;
		case Digital_IoWt_Index11:
			
		break;
		case Digital_IoWt_Index12:
			
		break;
		case Digital_IoWt_Index13:
			
		break;
		case Digital_IoWt_Index14:
			
		break;
		case Digital_IoWt_Index15:
			
		break;
		default:
			break;
	}
	
}


/*************************************************************************************************************************
*Name		 : DigitalIf_Adc_DataGet
*Function	 : Get the ADC value corresponding to opIndex
*argument	 : Digital_Adc_Index opIndex
					Digital_Adc_Index0, // Reserve the index of adc
					Digital_Adc_Index1, // Reserve the index of adc
					Digital_Adc_Index2, // Valve N Point Det ADC Value
					Digital_Adc_Index3, // Valve P Point Det ADC Value
					Digital_Adc_Index4, // Batt+ Det Voltage Value
					Digital_Adc_Index5, // Inside Hw Version Det ADC Value
					Digital_Adc_Index6, // Key Up Det ADC Value
					Digital_Adc_Index7, // NTC Det ADC Value
					Digital_Adc_Index8, // Reserve the index of adc
					Digital_Adc_Index9, // Key Down Det ADC Value
					Digital_Adc_Index10, // Reserve the index of adc
					Digital_Adc_Index11, // Reserve the index of adc
					Digital_Adc_Index12, // Pump N Point Det ADC Value
					Digital_Adc_Index13, // Reserve the index of adc
					Digital_Adc_Index14, // Reserve the index of adc
					Digital_Adc_Index15, // Pump P Point Det ADC Value
*Retval 	 : uint16_t
				Adc corresponding to value
*explain	 :Note that Digital_Adc_Index4 provides feedback in voltage values, 
				while the rest are ADC values with a maximum of 4095, 
				requiring the upper layer to perform the conversion itself.
*************************************************************************************************************************/

	

uint16_t DigitalIf_Adc_DataGet(Digital_Adc_Index opIndex)
{
	uint16_t Adc_Val=0;
	switch(opIndex)
	{
		case Digital_Adc_Index0:
			Adc_Val = ADC_Get_Index0_Voltage;
		break;
		case Digital_Adc_Index1:
			Adc_Val = ADC_Get_Index1_Voltage;
		break;
		case Digital_Adc_Index2:
			Adc_Val = ADC_Get_Index2_Voltage;
		break;
		case Digital_Adc_Index3:
			Adc_Val = ADC_Get_Index3_Voltage;
		break;
		case Digital_Adc_Index4:
			Adc_Val = ADC_Get_Index4_Voltage;
		break;
		case Digital_Adc_Index5:
			Adc_Val = ADC_Get_Index5_Voltage;
		break;
		case Digital_Adc_Index6:
			Adc_Val = ADC_Get_Index6_Voltage;
		break;
		case Digital_Adc_Index7:
			Adc_Val = ADC_Get_Index7_Voltage;
		break;
		case Digital_Adc_Index8:
			Adc_Val = ADC_Get_Index8_Voltage;
		break;
		case Digital_Adc_Index9:
			Adc_Val = ADC_Get_Index9_Voltage;
		break;
		case Digital_Adc_Index10:
			Adc_Val = ADC_Get_Index10_Voltage;
		break;
		case Digital_Adc_Index11:
			Adc_Val = ADC_Get_Index11_Voltage;
		break;
		case Digital_Adc_Index12:
			Adc_Val = ADC_Get_Index12_Voltage;
		break;
		case Digital_Adc_Index13:
			Adc_Val = ADC_Get_Index13_Voltage;
		break;
		case Digital_Adc_Index14:
			Adc_Val = ADC_Get_Index14_Voltage;
		break;
		case Digital_Adc_Index15:
			Adc_Val = ADC_Get_Index15_Voltage;
		break;
		default:
			break;
	}
	
	return Adc_Val;
}




#define NTC_DANGLING_VOLTAGE  4950


int16_t NTC_Get_Temperature(void)
{
	return (int16_t)Param_Calibration_AdcLookupNtcTemperature(DigitalIf_Adc_DataGet(Digital_Adc_Index7));

}
uint16_t DigitalIf_Batt_Voltage_DataGet(void)
{
	//#define BATTERY_RESISTANCE_HIGH_SIDE_OHM		56U
	//#define BATTERY_RESISTANCE_LOW_SIDE_OHM			15U
	//#define BATTERY_TOTAL_RESISTANCE_OHM		(BATTERY_RESISTANCE_HIGH_SIDE_OHM+BATTERY_RESISTANCE_LOW_SIDE_OHM)
	//((Battery *15)/(56+15)) = ((5000*ADC)/4095)
	//Battery = (14200*ADC)/2457
	// The voltage drop compensation of diode and transistor is increased to obtain the voltage of BAT on the input line
	
	#define BATTERY_CAL_FACTOR  14200U
	#define BATTERY_CAL_DIVISOR  2457U
	uint32_t Vol_Adc = DigitalIf_Adc_DataGet(Digital_Adc_Index4);
	uint32_t BattVal =((Vol_Adc*BATTERY_CAL_FACTOR)/BATTERY_CAL_DIVISOR);
	
	BattVal+= BAT_VOL_DROP_ON_DIODE_mV;		

	return BattVal;
}

uint32_t DigitalIf_Valve_OutputPoint_VoltageGet(uint8_t opindex)
{
	uint32_t VoutVoltage=0;
	uint32_t Cal_VoutVol=0;
	VoutVoltage = DigitalIf_Adc_DataGet(Digital_Adc_Index3);
	Cal_VoutVol = 	VoutVoltage*CURRENT_CALCULATE_FACTOR ;
	Cal_VoutVol /= CURRENT_CALCULATE_DIVISOR;
	IC_Diag_Filter[opindex].Diag_Voltage = Cal_VoutVol;
	return IC_Diag_Filter[opindex].Diag_Voltage;
}
uint32_t DigitalIf_Pump_OutputPoint_VoltageGet(void)
{
	uint32_t VoutVoltage=0;
	uint32_t Cal_VoutVol=0;
	VoutVoltage = DigitalIf_Adc_DataGet(Digital_Adc_Index12);
	Cal_VoutVol = 	VoutVoltage*PUMP_CURRENT_CALCULATE_FACTOR ;
	Cal_VoutVol /= PUMP_CURRENT_CALCULATE_DIVISOR;
	Pump_OutputPoint_Voltage = Cal_VoutVol;
	return Pump_OutputPoint_Voltage;
}


uint32_t DigitalIf_Pump_IS_CurrentGet(void)
{
	uint32_t VoutVoltage=0;
	uint32_t Cal_VoutVol=0;
	VoutVoltage = DigitalIf_Adc_DataGet(Digital_Adc_Index15);
	Cal_VoutVol = 	VoutVoltage*AD_REF_VOL/AD_RES_MAX;
	Cal_VoutVol = Cal_VoutVol *PUMP_GAIN_CURR/PUMP_LOAD_RESISTANCE_OHM;
	return Cal_VoutVol;
}

uint32_t DigitalIf_Valve_IS_CurrentGet(void)
{
	uint32_t VoutVoltage=0;
	uint32_t Cal_VoutVol=0;
	VoutVoltage = DigitalIf_Adc_DataGet(Digital_Adc_Index2);
	Cal_VoutVol = 	VoutVoltage*AD_REF_VOL/AD_RES_MAX;
	Cal_VoutVol = Cal_VoutVol *VALVE_GAIN_CURR/VALVE_LOAD_RESISTANCE_OHM;
	return Cal_VoutVol;
}




/*******************************************************************************
*Name        : DigitalIf_Temperature_DataGet
*Function    : Gets the unfiltered Temperature data of the corresponding index
*argument    : opIndex 
*			   		Digital_Temperature_Index0 = 0,//Index0 Use for ntc temperature
					Digital_Temperature_Index1,//SENSOR Temperature begin with index1
					Digital_Temperature_Index2,
					Digital_Temperature_Index3,
					Digital_Temperature_Index4,
					Digital_Temperature_Index5,
					Digital_Temperature_Index6,
					Digital_Temperature_Index7,
					Digital_Temperature_Index8,
					Digital_Temperature_Index9,
					Digital_Temperature_Index10,
				Temperature 
*			   		Temperature data store variable address
*Retval      : Temperature Data get result
*explain     : The return value is not filtered, 
				and the obtained data needs to be filtered after this function is called
*******************************************************************************/


BOOL DigitalIf_Temperature_DataGet(Digital_Temperature_Index opIndex,int16_t* Temperature)
{
	BOOL Retval =FALSE;
	int16_t TempVal =0xFF;
	if(opIndex<Digital_Temperature_MaxNum)
	{
		if(Digital_Temperature_Index0 == opIndex)
		{
			
			TempVal =NTC_Get_Temperature();
			if(0xFF == TempVal)
			{
				Retval = FALSE;
			}
			else
			{
				* Temperature =  TempVal;
				Retval = TRUE;
			}
			
		}
		else
		{
			Retval = P_Sensor_TemperatureGet((P_SENSOR_GENERAL_INDEX)(opIndex-1),Temperature);
		}
		

	}
	return Retval;
}

void POWER_IC_DIAG_Init(void)
{
	uint8_t i,j;
	for(i=0;i<Power_Ic_Num;i++)
	{

		IC_Diag_Filter[i].Diag_Current =0u;
		for(j =0;j<SHIFT_BUFFER_SIZE;j++)
		{
			IC_Diag_Filter[i].Shift_bufferArry[j] =0;
			IC_Diag_Filter[i].Shift_bufferBackupArry[j] =0;
		}
		IC_Diag_Filter[i].Shift_bufferArryFullFlag = 0;
		IC_Diag_Filter[i].Shift_Index = 0;
		for(j =0;j<SHIFT_BUFFER_SIZE;j++)
		{
			IC_Diag_Filter[i].VolShift_bufferArry[j] =0;
			IC_Diag_Filter[i].VolShift_bufferBackupArry[j] =0;
		}
		IC_Diag_Filter[i].VolShift_bufferArryFullFlag = 0;
		IC_Diag_Filter[i].VolShift_Index = 0;
	}	
	
}
static void Merge(uint32_t sourceArr[],uint32_t tempArr[], uint16_t startIndex, uint16_t midIndex, uint16_t endIndex)
{
    uint16_t i = startIndex, j = midIndex+1, k = startIndex;
	
    while(i!=midIndex+1 && j!=endIndex+1) 
	{
		if(sourceArr[i] > sourceArr[j])
		{
			tempArr[k++] = sourceArr[j++];
		}	
		else
		{
			tempArr[k++] = sourceArr[i++];
		}	
	}
    while(i != midIndex+1)
	{
		tempArr[k++] = sourceArr[i++];
	}  
    while(j != endIndex+1)
	{
		tempArr[k++] = sourceArr[j++];
	}    
    for(i=startIndex; i<=endIndex; i++)
	{
		sourceArr[i] = tempArr[i];
	}
        
}
void MergeSort(uint32_t sourceArr[], uint32_t tempArr[], uint16_t startIndex, uint16_t endIndex) 
{
    uint16_t midIndex;
    if(startIndex < endIndex) 
	{
        midIndex = startIndex + (endIndex-startIndex) / 2;//????int
        MergeSort(sourceArr, tempArr, startIndex, midIndex);
        MergeSort(sourceArr, tempArr, midIndex+1, endIndex);
        Merge(sourceArr, tempArr, startIndex, midIndex, endIndex);
    }
}

void POWER_IC_Cal_Periodic_10ms(Power_Ic_Index_Def opindex,uint8_t DiagEnSts,uint8_t PowerEnSts,uint32_t VisVoltage,uint32_t VoutVoltage,uint32_t VsVoltage,uint8_t DrvType)
{
	uint32_t Vol_across_Res =0;
	uint32_t Curr_across_Res =0;
	uint8_t i=0;
//	uint8_t j=0;
	uint32_t CumulativeSum=0;
//	uint32_t CalTemp =0;
	uint32_t Cal_VoutVol=0;
	//uint32_t Avg_VoutVol=0;
	uint32_t VolCumulativeSum=0;
//	uint32_t VolCalTemp =0;
	uint32_t TempData[30];
	//Use a 0.5 ohm resistor in series with the load, 
	//the current of the series circuit is equal, 
	//and the current at both ends of the 0.5 ohm resistor is equal to the load current
	#if 0
	Cal_VoutVol = 	VoutVoltage*CURRENT_CALCULATE_FACTOR ;
	Cal_VoutVol /= CURRENT_CALCULATE_DIVISOR;
	if(0u == IC_Diag_Filter[opindex].VolShift_bufferArryFullFlag)
	{
		if(IC_Diag_Filter[opindex].VolShift_Index<SHIFT_BUFFER_SIZE)
		{
			IC_Diag_Filter[opindex].VolShift_bufferArry[IC_Diag_Filter[opindex].VolShift_Index] = Cal_VoutVol;
			IC_Diag_Filter[opindex].VolShift_Index ++;
			if(IC_Diag_Filter[opindex].VolShift_Index == SHIFT_BUFFER_SIZE)
			{
				IC_Diag_Filter[opindex].VolShift_Index =0u;
				IC_Diag_Filter[opindex].VolShift_bufferArryFullFlag =1u;
				for(i=0;i<SHIFT_BUFFER_SIZE;i++)
				{
					IC_Diag_Filter[opindex].VolShift_bufferBackupArry[i] = IC_Diag_Filter[opindex].VolShift_bufferArry[i];
				}
				MergeSort(IC_Diag_Filter[opindex].VolShift_bufferBackupArry,TempData,0,29);
				for (i = CURRENT_FILTER_MIN_NUM; i < (SHIFT_BUFFER_SIZE-CURRENT_FILTER_MAX_NUM); i++)
				{
					VolCumulativeSum += IC_Diag_Filter[opindex].VolShift_bufferBackupArry[i];     
				}
				IC_Diag_Filter[opindex].Diag_Voltage = VolCumulativeSum/(SHIFT_BUFFER_SIZE-(CURRENT_FILTER_MIN_NUM+CURRENT_FILTER_MAX_NUM)); 	
			}
		}
		
	}
	else
	{
		IC_Diag_Filter[opindex].VolShift_bufferArry[IC_Diag_Filter[opindex].VolShift_Index] = Cal_VoutVol;
		IC_Diag_Filter[opindex].VolShift_Index ++;
		if(IC_Diag_Filter[opindex].VolShift_Index == SHIFT_BUFFER_SIZE)
		{
			IC_Diag_Filter[opindex].VolShift_Index =0u;
		}
		for(i=0;i<SHIFT_BUFFER_SIZE;i++)
		{
			IC_Diag_Filter[opindex].VolShift_bufferBackupArry[i] = IC_Diag_Filter[opindex].VolShift_bufferArry[i];
		}
		MergeSort(IC_Diag_Filter[opindex].VolShift_bufferBackupArry,TempData,0,29);
		/*for (i = 0; i < SHIFT_BUFFER_SIZE - 1; i++)
			for (j = 0; j < SHIFT_BUFFER_SIZE - 1 - i; j++)
				if (IC_Diag_Filter[opindex].VolShift_bufferBackupArry[j] > IC_Diag_Filter[opindex].VolShift_bufferBackupArry[j + 1]) {
					VolCalTemp = IC_Diag_Filter[opindex].VolShift_bufferBackupArry[j];
					IC_Diag_Filter[opindex].VolShift_bufferBackupArry[j] = IC_Diag_Filter[opindex].VolShift_bufferBackupArry[j + 1];
					IC_Diag_Filter[opindex].VolShift_bufferBackupArry[j + 1] = VolCalTemp;
				}*/
		for (i = CURRENT_FILTER_MIN_NUM; i < (SHIFT_BUFFER_SIZE-CURRENT_FILTER_MAX_NUM); i++)
		{
			VolCumulativeSum += IC_Diag_Filter[opindex].VolShift_bufferBackupArry[i];     
		}
		IC_Diag_Filter[opindex].Diag_Voltage = VolCumulativeSum/(SHIFT_BUFFER_SIZE-(CURRENT_FILTER_MIN_NUM+CURRENT_FILTER_MAX_NUM));  
							
	}
	#endif
	if(TRUE == DiagEnSts) 
	{
		if(PowerEnSts)
		{


			Vol_across_Res = ((uint32_t)VisVoltage*D_VN7050AS_CURRENT_CAL_FACTOR);
			Curr_across_Res  = Vol_across_Res/D_VN7050AS_CURRENT_CAL_DIVISOR;

			
			if(0u == IC_Diag_Filter[opindex].Shift_bufferArryFullFlag)
			{
				if(IC_Diag_Filter[opindex].Shift_Index<SHIFT_BUFFER_SIZE)
				{
					IC_Diag_Filter[opindex].Shift_bufferArry[IC_Diag_Filter[opindex].Shift_Index] = Curr_across_Res;
					IC_Diag_Filter[opindex].Shift_Index ++;
					if(IC_Diag_Filter[opindex].Shift_Index == SHIFT_BUFFER_SIZE)
					{
						IC_Diag_Filter[opindex].Shift_Index =0u;
						IC_Diag_Filter[opindex].Shift_bufferArryFullFlag =1u;
						for(i=0;i<SHIFT_BUFFER_SIZE;i++)
						{
							IC_Diag_Filter[opindex].Shift_bufferBackupArry[i] = IC_Diag_Filter[opindex].Shift_bufferArry[i];
						}
						MergeSort(IC_Diag_Filter[opindex].Shift_bufferBackupArry,TempData,0,29);
						/*for (i = 0; i < SHIFT_BUFFER_SIZE - 1; i++)
							for (j = 0; j < SHIFT_BUFFER_SIZE - 1 - i; j++)
								if (IC_Diag_Filter[opindex].Shift_bufferBackupArry[j] > IC_Diag_Filter[opindex].Shift_bufferBackupArry[j + 1]) {
									CalTemp = IC_Diag_Filter[opindex].Shift_bufferBackupArry[j];
									IC_Diag_Filter[opindex].Shift_bufferBackupArry[j] = IC_Diag_Filter[opindex].Shift_bufferBackupArry[j + 1];
									IC_Diag_Filter[opindex].Shift_bufferBackupArry[j + 1] = CalTemp;
								}*/
						for (i = CURRENT_FILTER_MIN_NUM; i < (SHIFT_BUFFER_SIZE-CURRENT_FILTER_MAX_NUM); i++)
						{
							CumulativeSum += IC_Diag_Filter[opindex].Shift_bufferBackupArry[i];     
						}
						IC_Diag_Filter[opindex].Diag_Current = CumulativeSum/(SHIFT_BUFFER_SIZE-(CURRENT_FILTER_MIN_NUM+CURRENT_FILTER_MAX_NUM)); 	
					}
				}
				
			}
			else
			{
				IC_Diag_Filter[opindex].Shift_bufferArry[IC_Diag_Filter[opindex].Shift_Index] = Curr_across_Res;
				IC_Diag_Filter[opindex].Shift_Index ++;
				if(IC_Diag_Filter[opindex].Shift_Index == SHIFT_BUFFER_SIZE)
				{
					IC_Diag_Filter[opindex].Shift_Index =0u;
				}
				for(i=0;i<SHIFT_BUFFER_SIZE;i++)
				{
					IC_Diag_Filter[opindex].Shift_bufferBackupArry[i] = IC_Diag_Filter[opindex].Shift_bufferArry[i];
				}
				MergeSort(IC_Diag_Filter[opindex].Shift_bufferBackupArry,TempData,0,29);
				/*for (i = 0; i < SHIFT_BUFFER_SIZE - 1; i++)
					for (j = 0; j < SHIFT_BUFFER_SIZE - 1 - i; j++)
						if (IC_Diag_Filter[opindex].Shift_bufferBackupArry[j] > IC_Diag_Filter[opindex].Shift_bufferBackupArry[j + 1]) {
							CalTemp = IC_Diag_Filter[opindex].Shift_bufferBackupArry[j];
							IC_Diag_Filter[opindex].Shift_bufferBackupArry[j] = IC_Diag_Filter[opindex].Shift_bufferBackupArry[j + 1];
							IC_Diag_Filter[opindex].Shift_bufferBackupArry[j + 1] = CalTemp;
						}*/
				for (i = CURRENT_FILTER_MIN_NUM; i < (SHIFT_BUFFER_SIZE-CURRENT_FILTER_MAX_NUM); i++)
				{
					CumulativeSum += IC_Diag_Filter[opindex].Shift_bufferBackupArry[i];     
				}
				IC_Diag_Filter[opindex].Diag_Current = CumulativeSum/(SHIFT_BUFFER_SIZE-(CURRENT_FILTER_MIN_NUM+CURRENT_FILTER_MAX_NUM));  
			}
			if(IC_Diag_Filter[opindex].Shift_bufferArryFullFlag &&IC_Diag_Filter[opindex].VolShift_bufferArryFullFlag)
			{
				
				
			}
		}
		else
		{
			IC_Diag_Filter[opindex].Diag_Current = 0u;

			//IC_Diag_Filter[opindex].Diag_Current = 0u;
			if(IC_Diag_Filter[opindex].VolShift_bufferArryFullFlag)
			{
				
			}

		}
			
	}
	else
	{

		IC_Diag_Filter[opindex].Diag_Current =0u;
	}

}
uint32_t POWER_IC_Diag_Current_Get(Power_Ic_Index_Def opindex)
{
#if 0
	uint32_t Vol_across_Res =0;
		uint32_t Curr_across_Res =0;
		uint32_t VisVoltage =0;
		if(Power_Ic_Index0 == opindex)
		{
			DigitalIf_IoWt_DataSet(Digital_IoWt_Index6,FALSE);
			DigitalIf_IoWt_DataSet(Digital_IoWt_Index7,FALSE);
		}
		else
		{
			DigitalIf_IoWt_DataSet(Digital_IoWt_Index6,TRUE);
			DigitalIf_IoWt_DataSet(Digital_IoWt_Index7,FALSE);
		}
		VisVoltage =DigitalIf_Adc_DataGet(Digital_Adc_Index2);
		Vol_across_Res = ((uint32_t)VisVoltage*D_VN7050AS_CURRENT_CAL_FACTOR);
		Curr_across_Res  = Vol_across_Res/D_VN7050AS_CURRENT_CAL_DIVISOR;

	if(opindex<Power_Ic_Num)
	{

		IC_Diag_Filter[opindex].Diag_Current = Curr_across_Res;
		return IC_Diag_Filter[opindex].Diag_Current;
	}
	else
	{
		return 0;
	}
	#else
	if(opindex<Power_Ic_Num)
	{

		return IC_Diag_Filter[opindex].Diag_Current;
	}
	else
	{
		return 0;
	}
	#endif
}

uint32_t DigitalIf_Diag_Current_DataGet(Digital_Current_Index opIndex)
{
	return POWER_IC_Diag_Current_Get((Power_Ic_Index_Def)opIndex);

}


/*******************************************************************************
*Name        : DigitalIf_Pressure_DataGet
*Function    : Gets the unfiltered Pressure data of the corresponding index
*argument    : opIndex 
*			   		Digital_Pressure_Index0,
*					Digital_Pressure_Index1,
*					Digital_Pressure_Index2,
*					Digital_Pressure_Index3,
*					Digital_Pressure_Index4,
*					Digital_Pressure_Index5,
*					Digital_Pressure_Index6,
*					Digital_Pressure_Index7,
*					Digital_Pressure_Index8,
*					Digital_Pressure_Index9,
*					Digital_Pressure_Index10,
*					Digital_Pressure_Index11,
*					Digital_Pressure_Index12,
*					Digital_Pressure_Index13,
*					Digital_Pressure_Index14,
*					Digital_Pressure_Index15,
				Pressure 
*			   		Pressure data store variable address
*Retval      : Pressure Data get result
*explain     : The return value is not filtered, 
				and the obtained data needs to be filtered after this function is called
*******************************************************************************/

BOOL DigitalIf_Pressure_DataGet(Digital_Pressure_Index opIndex,uint32_t* Pressure)
{
	BOOL Retval =FALSE;
	if(opIndex<Digital_Pressure_MaxNum)
	{
		Retval = P_Sensor_PressureGet((P_SENSOR_GENERAL_INDEX)opIndex,Pressure);

	}
	return Retval;

}


uint8_t DigitalIf_Platform_HwVerStateGet(uint8_t* HwVer)
{
	BOOL Retval =FALSE;
	if(HWCheckCount <= HW_CHECK_TIMER) 
	{
		if(HwCompatibilityCheck_Timeout < COMPATIBILITYHW_CHECK_TIMEOUT_TIMER)
		{
			Retval =FALSE;
			* HwVer = Digital_Hardware_ver_A0;
		}
		else
		{
			Retval =TRUE;
			* HwVer = Digital_Hardware_ver_A0;
		}
	}
	else
	{
		Retval =TRUE;
		* HwVer = g_hardware_ver;
	}
	return Retval;
}



void DigitalIf_Init(void)
{

}


void DigitalIf_DeInit(void)
{

}








void DigitalIf_Platform_HwVer_Det_10Ms(void)
{
	//BOOL Retval =FALSE;
	uint16_t Hw_ADval;
	uint8_t ListIndex;
	uint8_t index;
	if(HwCompatibilityCheck_Timeout < COMPATIBILITYHW_CHECK_TIMEOUT_TIMER)
	{
		
		if(HWCheckCount > HW_CHECK_TIMER) 
			return;
		HwCompatibilityCheck_Timeout++;
		Hw_ADval = DigitalIf_Adc_DataGet(Digital_Adc_Index5);
		for(ListIndex=0; ListIndex<HW_VERSION_NUM; ListIndex++)
		{
			if ((HwVersion_Info[ListIndex].Voltage_Floor_mV <= Hw_ADval) && (Hw_ADval <= HwVersion_Info[ListIndex].Voltage_Upper_mV))
			{
				index = ListIndex;
				break;
			}
		}

		if(TempHWCurrVer != index) 
		{
			HWCheckCount = 0;
			TempHWCurrVer = index;
		}
		else
		{
			HWCheckCount++;
			if(HWCheckCount > HW_CHECK_TIMER)
			{
				//memcpy(&avHWVersion[0U],HwVersion_Info[ListIndex].Version , 4);
				HWCheckCount = HW_CHECK_TIMER+1;
				g_hardware_ver = TempHWCurrVer;
			}
		}
	}
}


void Digital_Pump_Output_Point_VoltageDet(void)
{
	uint8_t i=0;
	uint32_t VoutVoltage=0;
	uint32_t Cal_VoutVol=0;
	uint32_t VolCumulativeSum=0;
	uint32_t TempData[30];
	VoutVoltage = DigitalIf_Adc_DataGet(Digital_Adc_Index12);
	Cal_VoutVol = 	VoutVoltage*PUMP_CURRENT_CALCULATE_FACTOR ;
	Cal_VoutVol /= PUMP_CURRENT_CALCULATE_DIVISOR;
	if(0u == Pump_bufferArryFullFlag)
	{
		if(Pump_VolShift_Index<SHIFT_BUFFER_SIZE)
		{
			Pump_VolShift_bufferArry[Pump_VolShift_Index] = Cal_VoutVol;
			Pump_VolShift_Index ++;
			if(Pump_VolShift_Index == SHIFT_BUFFER_SIZE)
			{
				Pump_VolShift_Index =0u;
				Pump_bufferArryFullFlag =1u;
				for(i=0;i<SHIFT_BUFFER_SIZE;i++)
				{
					Pump_VolShift_bufferBackupArry[i] = Pump_VolShift_bufferArry[i];
				}
				MergeSort(Pump_VolShift_bufferBackupArry,TempData,0,29);
				for (i = CURRENT_FILTER_MIN_NUM; i < (SHIFT_BUFFER_SIZE-CURRENT_FILTER_MAX_NUM); i++)
				{
					VolCumulativeSum += Pump_VolShift_bufferBackupArry[i];     
				}
				Pump_OutputPoint_Voltage = VolCumulativeSum/(SHIFT_BUFFER_SIZE-(CURRENT_FILTER_MIN_NUM+CURRENT_FILTER_MAX_NUM)); 	
			}
		}
		
	}
	else
	{
		Pump_VolShift_bufferArry[Pump_VolShift_Index] = Cal_VoutVol;
			Pump_VolShift_Index ++;
		if(Pump_VolShift_Index == SHIFT_BUFFER_SIZE)
		{
			Pump_VolShift_Index =0u;
		}
		for(i=0;i<SHIFT_BUFFER_SIZE;i++)
		{
			Pump_VolShift_bufferBackupArry[i] = Pump_VolShift_bufferArry[i];
		}
		MergeSort(Pump_VolShift_bufferBackupArry,TempData,0,29);
		for (i = CURRENT_FILTER_MIN_NUM; i < (SHIFT_BUFFER_SIZE-CURRENT_FILTER_MAX_NUM); i++)
		{
			VolCumulativeSum += Pump_VolShift_bufferBackupArry[i];     
		}
		Pump_OutputPoint_Voltage = VolCumulativeSum/(SHIFT_BUFFER_SIZE-(CURRENT_FILTER_MIN_NUM+CURRENT_FILTER_MAX_NUM)); 
							
	}
}
void Digital_Handle_10msCall(void)
{
	
	DigitalIf_Platform_HwVer_Det_10Ms();

	POWER_IC_Cal_Periodic_10ms(Power_Ic_Index0,TRUE,Hsd_Valve_PowerEn_ON_OffFlag,DigitalIf_Adc_DataGet(Digital_Adc_Index2),DigitalIf_Adc_DataGet(Digital_Adc_Index3),DigitalIf_Adc_DataGet(Digital_Adc_Index4),0);
	POWER_IC_Cal_Periodic_10ms(Power_Ic_Index1,TRUE,Hsd_Pump_PowerEn_ON_OffFlag,DigitalIf_Adc_DataGet(Digital_Adc_Index15),DigitalIf_Adc_DataGet(Digital_Adc_Index12),DigitalIf_Adc_DataGet(Digital_Adc_Index4),0);
	//Digital_Pump_Output_Point_VoltageDet();

}
void Digital_Handle_1msCall(void)
{
	static uint8_t Change_Index=0;
	uint32_t Vol_across_Res =0;
	uint32_t Curr_across_Res =0;
	uint32_t VisVoltage =0;
	static uint8_t Change_Index1=0;
	
	if(Change_Index ==0)
	{
		VisVoltage =DigitalIf_Adc_DataGet(Digital_Adc_Index2);
		Vol_across_Res = ((uint32_t)VisVoltage*D_VN7050AS_CURRENT_CAL_FACTOR);
		Curr_across_Res  = Vol_across_Res/D_VN7050AS_CURRENT_CAL_DIVISOR;
		IC_Diag_Filter[Power_Ic_Index0].Diag_Current = Curr_across_Res;

		Change_Index=1;
	}
	else if (Change_Index ==1)
	{
		DigitalIf_IoWt_DataSet(Digital_IoWt_Index6,TRUE);
		DigitalIf_IoWt_DataSet(Digital_IoWt_Index7,FALSE);

		Change_Index=2;
	}
	else if (Change_Index ==2)
	{

		VisVoltage =DigitalIf_Adc_DataGet(Digital_Adc_Index2);
		Vol_across_Res = ((uint32_t)VisVoltage*D_VN7050AS_CURRENT_CAL_FACTOR);
		Curr_across_Res  = Vol_across_Res/D_VN7050AS_CURRENT_CAL_DIVISOR;
		IC_Diag_Filter[Power_Ic_Index1].Diag_Current = Curr_across_Res;
		Change_Index=3;
	}
	else if (Change_Index ==3)
		{

			DigitalIf_IoWt_DataSet(Digital_IoWt_Index6,FALSE);
			DigitalIf_IoWt_DataSet(Digital_IoWt_Index7,FALSE);
			Change_Index=0;
		}
}









