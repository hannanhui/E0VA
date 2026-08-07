/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      Digital_Handle.h                                                         */
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
#ifndef INCLUDE_DIGITAL_HANDLE_H_
#define INCLUDE_DIGITAL_HANDLE_H_
#include "Type_Define.h"

#define SHIFT_BUFFER_SIZE 30U
#define RESISTANCE_HIGH_SIDE_OHM		56U
#define RESISTANCE_LOW_SIDE_OHM			20U

#define TOTAL_RESISTANCE_OHM		(RESISTANCE_HIGH_SIDE_OHM+RESISTANCE_LOW_SIDE_OHM)
#define CURRENT_CALCULATE_FACTOR  (AD_REF_VOL*TOTAL_RESISTANCE_OHM)
#define CURRENT_CALCULATE_DIVISOR  (AD_RES_MAX*RESISTANCE_LOW_SIDE_OHM)


#define PUMP_RESISTANCE_HIGH_SIDE_OHM		56U
#define PUMP_RESISTANCE_LOW_SIDE_OHM			20U

#define PUMP_TOTAL_RESISTANCE_OHM		(PUMP_RESISTANCE_HIGH_SIDE_OHM+PUMP_RESISTANCE_LOW_SIDE_OHM)
#define PUMP_CURRENT_CALCULATE_FACTOR  (AD_REF_VOL*TOTAL_RESISTANCE_OHM)
#define PUMP_CURRENT_CALCULATE_DIVISOR  (AD_RES_MAX*PUMP_RESISTANCE_LOW_SIDE_OHM)
#define PUMP_LOAD_RESISTANCE_OHM   1000U
#define PUMP_GAIN_CURR             1200U

#define VALVE_GAIN_CURR             1200U
#define VALVE_LOAD_RESISTANCE_OHM   1000U






#define D_VN7050AS_OVERLOAD_VSENSE  4000U

#define D_VN7050AS_OVERLOAD_VSENSE_ADVAL  ((D_VN7050AS_OVERLOAD_VSENSE*AD_RES_MAX)/AD_REF_VOL)

#define D_VN7050AS_R_SENSE_OHM		10U//1K
#define D_VN7050AS_K_VALUE			120U//1200

#define D_VN7050AS_CURRENT_CAL_FACTOR  (500*D_VN7050AS_K_VALUE)
#define D_VN7050AS_CURRENT_CAL_DIVISOR  (AD_RES_MAX*D_VN7050AS_R_SENSE_OHM)

#define POWER_OUT_SHORT_CURRENT_mA		1500U		//Pump overcurrent detection threshold, if greater than this threshold to determine the overcurrent
#define POWER_OUT_OVER_CURRENT_mA		2000U		//Pump overcurrent detection threshold, if greater than this threshold to determine the overcurrent

#define POWER_OUT1_OPEN_CURRENT_mA		50U		//// Pump open detection threshold, if less than this threshold is determined to be open
#define POWER_OUT1_SHORT_CURRENT_mA		2500U		//Pump overcurrent detection threshold, if greater than this threshold to determine the overcurrent

#define POWER_OUT1_OVER_CURRENT_mA		3000U


#define CURRENT_FILTER_MIN_NUM  5
#define CURRENT_FILTER_MAX_NUM  5



#define D_Digital_Hardware_ver_A0_ADVAL   820U
typedef enum
{
	Digital_Temperature_Index0 = 0,//Index0 Use for ntc
	Digital_Temperature_Index1,//SENSOR index offset 1,Digital_Temperature_Index1==>P_SENSOR_GENERAL_INDEX0
	Digital_Temperature_Index2,
	Digital_Temperature_Index3,
	Digital_Temperature_Index4,
	Digital_Temperature_Index5,
	Digital_Temperature_Index6,
	Digital_Temperature_Index7,
	Digital_Temperature_Index8,
	Digital_Temperature_Index9,
	Digital_Temperature_Index10,
	Digital_Temperature_Index11,
	Digital_Temperature_Index12,
	Digital_Temperature_Index13,
	Digital_Temperature_Index14,
	Digital_Temperature_Index15,
	Digital_Temperature_MaxNum
}Digital_Temperature_Index;

typedef enum
{
	Digital_Hardware_ver_A0 = 0,//Index0 Use for ntc
	Digital_Hardware_ver_A1,
	Digital_Hardware_ver_A2,
	Digital_Hardware_ver_A3,
	Digital_Hardware_ver_A4,
	Digital_Hardware_ver_Max
}Digital_Hardware_version_Type;
/***************************************************************************************************************************************
Valve Index  map and  Sensor Index map        
----------------------------------------------------------------------------------------------------------------------------------------
_______________________________________________________________________________________________________________________________________
| o    o o    o o    o o    o o    o |    _               _     _       | o    o  o    o  o    o  o    o  o    o  o    o  o    o |    _|
| index6 index7 index8 index9 index10|   |_|             |_|   |_|      |index13 index14 index15 index16 index17 index18 index19 |   | 
|          _                         |   P6              P5    P4       |                                                        |   |_
| Bottom->|_|                        ||                                 |                                                        |     | 
|        P10      _      _      _    ||              _________________  |                                                        |     | 
|                |_|    |_|    |_|   ||                o    o o    o  | |    _      _       _                                    |     | 
|                P9     P8     P7    ||               index11 index12 | |   |_|    |_|     |_|                   ________________|     | 
|                                    ||                               | |   P3     P2      P1                    |        _            |
|               o    o o    o o    o ||                               | | o    o  o    o  o    o                 |   ____| |____       | 
|               index2 index3 index4 ||                               | |index20 index21 index22                 |  |____| |____|      | 
|                 ^^                 ||                               | |                                        |       | |           |                                      
|        _________||                 ||                               | |                                        |   ----| |----       |                                            
|       |either-or||                 ||   o    o                      | |                                        |   ----| |----       |                                                                                       
|        ---------||                 ||   index5                      | |                                        |   ----| |----       |
|                 ||                 ||                               | |                                        |   ----| |----       |
| index1 index0 index2               ||    ___                        | |                                        |   ----| |----       | 
| o    o o    o o    o               ||   |   |                       | |                                        |   ____| |____       |                                   
|_______________________  ___________||   |___|       index24 index23 | |                                        |  |____| |____|      | 
                        )     ___     |    P0          o    o o    o  | |________________________________________|       |_|           |                
                        )_____|  |____|_______________ _______________|                      __________________________________________| 
                                                      |               >ooooooo              |  
                                                      |_____________________________________|
----------------------------------------------------------------------------------------------------------------------------------------                                                      
****************************************************************************************************************************************/

typedef enum
{
	Digital_Pressure_Index0 = 0,
	Digital_Pressure_Index1,
	Digital_Pressure_Index2,
	Digital_Pressure_Index3,
	Digital_Pressure_Index4,
	Digital_Pressure_Index5,
	Digital_Pressure_Index6,
	Digital_Pressure_Index7,
	Digital_Pressure_Index8,
	Digital_Pressure_Index9,
	Digital_Pressure_Index10,
	Digital_Pressure_Index11,
	Digital_Pressure_Index12,
	Digital_Pressure_Index13,
	Digital_Pressure_Index14,
	Digital_Pressure_Index15,
	Digital_Pressure_MaxNum
}Digital_Pressure_Index;
typedef enum
{
	Digital_Hw_Version_Old = 0,
	Digital_Hw_Version_New,
	Digital_Hw_Version_Num
}Digital_Hw_Version_Type;

typedef enum
{
	Digital_Key_Index0 = 0,
	Digital_Key_Index1,
	Digital_Key_MaxNum
}Digital_Key_Index;
typedef enum
{
	Digital_Current_Index0 = 0,
	Digital_Current_Index1,
	Digital_Current_MaxNum
}Digital_Current_Index;

typedef enum
{
	Digital_Adc_Index0 = 0,
	Digital_Adc_Index1,
	Digital_Adc_Index2,
	Digital_Adc_Index3,
	Digital_Adc_Index4,
	Digital_Adc_Index5,
	Digital_Adc_Index6,
	Digital_Adc_Index7,
	Digital_Adc_Index8,
	Digital_Adc_Index9,
	Digital_Adc_Index10,
	Digital_Adc_Index11,
	Digital_Adc_Index12,
	Digital_Adc_Index13,
	Digital_Adc_Index14,
	Digital_Adc_Index15,
	
	Digital_Adc_MaxNum
}Digital_Adc_Index;

typedef enum
{
	Digital_IoRd_Index0 = 0,
	Digital_IoRd_Index1,
	Digital_IoRd_Index2,
	Digital_IoRd_Index3,
	Digital_IoRd_Index4,
	Digital_IoRd_Index5,
	Digital_IoRd_Index6,
	Digital_IoRd_Index7,
	Digital_IoRd_Index8,
	Digital_IoRd_Index9,
	Digital_IoRd_Index10,
	Digital_IoRd_Index11,
	Digital_IoRd_Index12,
	Digital_IoRd_Index13,
	Digital_IoRd_Index14,
	Digital_IoRd_Index15,
	
	Digital_IoRd_MaxNum
}Digital_IoRd_Index;

typedef enum
{
	Digital_IoWt_Index0 = 0,
	Digital_IoWt_Index1,
	Digital_IoWt_Index2,
	Digital_IoWt_Index3,
	Digital_IoWt_Index4,
	Digital_IoWt_Index5,
	Digital_IoWt_Index6,
	Digital_IoWt_Index7,
	Digital_IoWt_Index8,
	Digital_IoWt_Index9,
	Digital_IoWt_Index10,
	Digital_IoWt_Index11,
	Digital_IoWt_Index12,
	Digital_IoWt_Index13,
	Digital_IoWt_Index14,
	Digital_IoWt_Index15,
	
	Digital_IoWt_MaxNum
}Digital_IoWt_Index;
typedef enum
{
	Power_Ic_Index0 = 0,
	Power_Ic_Index1,	
	Power_Ic_Num
}Power_Ic_Index_Def;

typedef struct
{
	uint32_t Diag_Current; //MA
	uint32_t Diag_Voltage; //MA
	uint8_t Shift_bufferArryFullFlag;
	uint8_t Shift_Index;
	uint32_t Shift_bufferArry[SHIFT_BUFFER_SIZE];
	uint32_t Shift_bufferBackupArry[SHIFT_BUFFER_SIZE];
	uint8_t VolShift_bufferArryFullFlag;
	uint8_t VolShift_Index;
	uint32_t VolShift_bufferArry[SHIFT_BUFFER_SIZE]; 
	uint32_t VolShift_bufferBackupArry[SHIFT_BUFFER_SIZE]; 
}POWER_IC_DIAG_FILTER_STRUCT;

#define D_LEN_HW_VERSION		4
#define HW_VERSION_NUM  Digital_Hardware_ver_Max

typedef struct
{
	char *	Version;
	uint16_t Voltage_Floor_mV;
	uint16_t Voltage_Upper_mV;

}Hw_Version_List;

typedef struct
{
	uint16_t Voltage_Floor_mV;
	uint16_t Voltage_Upper_mV;

}Hw_Compatibility_Version_List;



extern void DigitalIf_Init(void);

/*************************************************************************************************************************/
								
/*  ######################################################################################################################
	#################################################External call API####################################################	
**  ######################################################################################################################*/

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

extern uint8_t DigitalIf_IoRd_DataGet(Digital_IoRd_Index opIndex);
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
					Digital_IoWt_Index6, // Reserve the index of I/O
					Digital_IoWt_Index7, // Reserve the index of I/O
					Digital_IoWt_Index8, // Reserve the index of I/O
					Digital_IoWt_Index9, // Reserve the index of I/O
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

extern void DigitalIf_IoWt_DataSet(Digital_IoWt_Index opIndex,uint8_t opStatus);
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

extern uint16_t DigitalIf_Adc_DataGet(Digital_Adc_Index opIndex);

/*************************************************************************************************************************
*Name		 : DigitalIf_Diag_Current_DataGet
*Function	 : Get Current
*argument	 : Digital_Current_Index opIndex:
				Digital_Current_Index0,   //The HSD Current --valve
				Digital_Current_Index1,   //The HSD Current --Pump
*Retval 	 : uint32_t -->current:
				The driving current of the current power supply IC, in mA
*explain	 : Returns the drive current of the corresponding power IC according to the input index
*************************************************************************************************************************/
	
extern uint32_t DigitalIf_Diag_Current_DataGet(Digital_Current_Index opIndex);

/*************************************************************************************************************************
*Name		 : DigitalIf_Temperature_DataGet
*Function	 : Get Temperature Data
*argument	 : Digital_Temperature_Index opIndex
					Digital_Temperature_Index0, // Temperature-value index of NTC resistance on the board
					Digital_Temperature_Index1, // Index of the temperature value of the pressure sensor(SMP581)
					Digital_Temperature_Index2, // specifies the index of the temperature value of the pressure sensor
					Digital_Temperature_Index3, // Reserve the index of pressure sensor temperature value
					Digital_Temperature_Index4, // Reserve the index of pressure sensor temperature values
					Digital_Temperature_Index5, // Reserve the index of pressure sensor temperature values
					Digital_Temperature_Index6, // Reserve the index of pressure sensor temperature values
					Digital_Temperature_Index7, // Reserve an index of the temperature value of the pressure sensor
					Digital_Temperature_Index8, // Reserve the index of pressure sensor temperature values
					Digital_Temperature_Index9, // Reserve the index of pressure sensor temperature values
					Digital_Temperature_Index10, // Reserve the index of pressure sensor temperature values
			   int16_t* Temperature
					The obtained temperature value is stored in the address
*Retval 	 : BOOL 
				--The current temperature obtains the result
*explain	 : According to the input index, the corresponding temperature value is read out and written to the set address.
				If the reading fails, 
				the current temperature value is unavailableThe obtained temperature unit is �� C
*************************************************************************************************************************/

extern BOOL DigitalIf_Temperature_DataGet(Digital_Temperature_Index opIndex,int16_t* Temperature);

/*************************************************************************************************************************
*Name		 : DigitalIf_Pressure_DataGet
*Function	 : Get Pressure Data
*argument	 : Digital_Pressure_Index opIndex
					Digital_Pressure_Index0, // Index of the pressure value obtained by the pressure sensor
					Digital_Pressure_Index1, // Reserve the pressure index of the pressure sensor
					Digital_Pressure_Index2, // Reserve the pressure sensor pressure value index
					Digital_Pressure_Index3, // Reserve pressure sensor pressure value index
					Digital_Pressure_Index4, // Reserve the pressure sensor pressure index
					Digital_Pressure_Index5, // Reserve the pressure sensor pressure index
					Digital_Pressure_Index6, // Reserve the pressure sensor pressure index
					Digital_Pressure_Index7, // Reserve the pressure sensor pressure index
					Digital_Pressure_Index8, // Reserve the pressure sensor pressure index
					Digital_Pressure_Index9, // Reserve the pressure sensor pressure index
					Digital_Pressure_Index10, // Reserve the pressure sensor pressure index
					Digital_Pressure_Index11, // Reserve the pressure sensor pressure index
					Digital_Pressure_Index12, // Reserve the pressure sensor pressure index
					Digital_Pressure_Index13, // Reserve the pressure sensor pressure index
					Digital_Pressure_Index14, // Reserve the pressure sensor pressure index
					Digital_Pressure_Index15, // Reserve the pressure sensor pressure index
			   uint32_t* Pressure
					Get the address where the pressure value is stored
*Retval 	 : BOOL 
				--The current Pressure obtains the result
*explain	 : According to the input index, the corresponding pressure value is read out and written to the set address.
				If the reading fails,
				the current obtained pressure value is not availableObtained pressure unit :Pa
*************************************************************************************************************************/

extern BOOL DigitalIf_Pressure_DataGet(Digital_Pressure_Index opIndex,uint32_t* Pressure);



/*************************************************************************************************************************
*Name		 : DigitalIf_Batt_Voltage_DataGet
*Function	 : Get Batt+ Voltage 
*argument	 : NONE

*Retval 	 : uint16_t
				Batt+ Voltage  uint:mV

*explain	 : Returns the Batt+ Voltage Value
*************************************************************************************************************************/

extern uint16_t DigitalIf_Batt_Voltage_DataGet(void);

extern uint32_t DigitalIf_Valve_OutputPoint_VoltageGet(uint8_t opindex);
extern uint32_t DigitalIf_Pump_OutputPoint_VoltageGet(void);
extern uint32_t DigitalIf_Pump_IS_CurrentGet(void);
extern uint32_t DigitalIf_Valve_IS_CurrentGet(void);


/*************************************************************************************************************************
*Name		 : DigitalIf_Platform_HwVer_Det_10Ms
*Function	 : Identifying and detecting hardware PCBA versions
*argument	 : NONE
*Retval 	 : NONE
*explain	 : NONE
*************************************************************************************************************************/

extern void DigitalIf_Platform_HwVer_Det_10Ms(void);

/*************************************************************************************************************************
*Name		 : DigitalIf_Platform_HwVerStateGet
*Function	 : Obtain the current hardware PCBA version for functional adaptation across different versions
*argument	 : uint8_t*:
				Pass in the pointer corresponding to the saved version variable.
*Retval 	 : uint8_t:
				Success or failure in obtaining the version
				0 Failure
				1 Success
*explain	 : Obtain the current hardware PCBA version for functional adaptation across different versions
*************************************************************************************************************************/

extern uint8_t DigitalIf_Platform_HwVerStateGet(uint8_t* HwVer);





/************************************************************************************************************************/

extern void Digital_Handle_10msCall(void);

extern void Digital_Handle_1msCall(void);


#endif /* INCLUDE_DIGITAL_HANDLE_H_ */
