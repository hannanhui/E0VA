/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      SMP580_Drv.h                                                             */
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

#ifndef __SMP580_DRV_H__
#define __SMP580_DRV_H__


#include "SMP580.h"
#include "Ecal_SPI.h"

#define SMP580_RESOLUTION_MAX		1023

#define REQUEST_PRESSURE 1			 	// Obtain the pressure data
#define REQUEST_TEMPERATURE 2 			// Obtain the temperature data
#define REQUEST_IDENTIFICATION 4 		// Obtain ID data
#define REQUEST_POWER_DOWN 5 			// Enter the power off mode
#define STATUS_CLEAR_NOACTION 1 		// Do not clear the error flag
#define STATUS_CLEAR_ACTION 0 			// Clear the error flag
#define COMMAND_DATA 0 					// The data segment for sending a command must be 0



typedef union
{
	uint16_t Value;

	struct
	{
		uint16_t   CmdData 		: 12;	// bit0-11
		uint16_t   Status_Clear	: 1;	// bit12
		uint16_t   Request		: 3;	// bit13-15

	}Bit;

}SMP580_16BIT_CMD;


// 按优先级排列
typedef enum
{
	SENSOR_MEMORY_ERROR = 0x10,
	ACQUISITION_CHAIN_FAILURE = 0x08,
	PRESSURE_SENSING_ELEMENT_FAILURE = 0x04,
	ADC_UPPER_LIMIT = 0x02,
	ADC_LOWER_LIMIT	= 0x01,
	NO_ERR = 0x0A,

}DIAGNOSTIC;

typedef union
{
	uint16_t Value;

	struct
	{
		uint16_t   CheckSun 		: 1;	// bit0		bit1-bit15 Odd check The value is 1 when the number of 1s is even (including 0). The value is 0 when the number of 1s is odd
		uint16_t   RespData		: 10;	// bit1-10
		uint16_t   Diagnostic		: 5;	// bit11-15

	}Bit;

}SMP580_16BIT_VARIANT1;

typedef union
{
	uint16_t Value;

	struct
	{
		uint16_t   ASIC_ID			: 8;	// bit0-7
		uint16_t   Metal_Version 		: 3;	// bit8-10
		uint16_t   Silicon_Version	: 3;	// bit11-13
		uint16_t   Supplier_ID		: 2;	// bit14-15

	}Bit;

}SMP580_16BIT_VARIANT2;

extern uint16_t SMP580_Drv_Get_Id(SPI_ConfigList_CS_Index opCsIndex,  SPI_ConfigList_Index opSpiIndex);
extern BOOL SMP580_Drv_Get_Pressure(SPI_ConfigList_CS_Index opCsIndex,  SPI_ConfigList_Index opSpiIndex, uint16_t* Pressure);
extern BOOL SMP580_Drv_Get_Temperature(SPI_ConfigList_CS_Index opCsIndex,  SPI_ConfigList_Index opSpiIndex, uint16_t* Temperature);
extern int16_t SMP580_Drv_Calculate_Temperature(uint16_t Value);
extern uint32_t SMP580_Drv_Calculate_Pressure(uint16_t Value);

#endif /* __SMP580_DRV_H__ */
