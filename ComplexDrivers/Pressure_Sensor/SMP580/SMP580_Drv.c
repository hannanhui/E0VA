/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      SMP580_Drv.c                                                             */
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

// The SPI clock is low when it is idle, and the first clock edge (falling edge) sends data
// Data is returned in VARIANT2 format when the ID is read. Data is returned in VARIANT2 format when the next read is read. 
// Data is returned in VARIANT1 format when the read temperature and pressure are read
// Read the ID and then read the temperature or pressure for the second time to get the correct value. 
// Read the ID and then read the temperature or pressure for the second time to get the correct value
// The specific model of the SMP580 is (Part No.: 0 273 300 389) 16 bit out of frame SPI 60... 165 kPa


uint16_t SMP580_Drv_Get_Response(SPI_ConfigList_CS_Index opCsIndex,  SPI_ConfigList_Index opSpiIndex,uint16_t Cmd)
{
	uint8_t Send[2];
	uint8_t Recv[2];
	uint16_t Ret;

	Send[0] = (Cmd >> 8) & 0xFF;
	Send[1] = (Cmd >> 0) & 0xFF;

	SpiIf_Spi_Device_Nss_Set(opCsIndex,FALSE);
	Recv[0] = SpiIf_SpiReadWrite_aByte(opSpiIndex,Send[0]);
	Recv[1] = SpiIf_SpiReadWrite_aByte(opSpiIndex,Send[1]);

	SpiIf_Spi_Device_Nss_Set(opCsIndex,TRUE);

	Ret   = Recv[0];
	Ret <<= 8;
	Ret  |= Recv[1];

	return Ret;
}


/* *****************************************************************************
* Function name: SMP580_Drv_Check_Variant_Parity
* Function Function: Verify the data obtained from the SMP580
* Function argument: Value - The obtained data
* Function return value: true - The test succeeded
* Function return value: false - The test failed
* Note: None

*******************************************************************************/
BOOL SMP580_Drv_Check_Variant_Parity(uint16_t Value)
{
	uint8_t i;
	uint8_t Cnt;
	BOOL Parity_Calc;
	BOOL Parity_Recv = (Value & 0x0001);

	Cnt = 0;
	for(i=1; i<16; i++)
	{
		if (Value & ((uint16_t)1 << i))
		{
			Cnt++;
		}
	}

	if (Cnt % 2 == 0)
	{
		Parity_Calc = 1;
	}
	else
	{
		Parity_Calc = 0;
	}

	if (Parity_Calc == Parity_Recv)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/* *****************************************************************************
* Function name: SMP580_Drv_Get_Id
* Function Function: Obtain ID data of the SMP580
* Function parameter: SMP580 ID value
* Function return: none
* Note: None
*******************************************************************************/
uint16_t SMP580_Drv_Get_Id(SPI_ConfigList_CS_Index opCsIndex,  SPI_ConfigList_Index opSpiIndex)
{
	SMP580_16BIT_CMD SMP580_Cmd;

	SMP580_Cmd.Bit.Request = REQUEST_IDENTIFICATION;
	SMP580_Cmd.Bit.Status_Clear = STATUS_CLEAR_ACTION;
	SMP580_Cmd.Bit.CmdData = COMMAND_DATA;

	//Write it once to make the command take effect
	SMP580_Drv_Get_Response(opCsIndex,opSpiIndex,SMP580_Cmd.Value);
	return SMP580_Drv_Get_Response(opCsIndex,opSpiIndex,SMP580_Cmd.Value);
}

/* *****************************************************************************
* Function name: SMP580_Drv_Get_Pressure
* Function Function: Obtain the pressure data of the SMP580
* Function argument: Pressure - Returned pressure data
* Function return value: true - Obtaining data successfully
* Function return value: false - Failed to get data
* Note: None
*******************************************************************************/
BOOL SMP580_Drv_Get_Pressure(SPI_ConfigList_CS_Index opCsIndex,  SPI_ConfigList_Index opSpiIndex, uint16_t* Pressure)
{
	SMP580_16BIT_CMD SMP580_Cmd;
	SMP580_16BIT_VARIANT1 SMP580_Value;

	SMP580_Cmd.Bit.Request = REQUEST_PRESSURE;
	SMP580_Cmd.Bit.Status_Clear = STATUS_CLEAR_ACTION;
	SMP580_Cmd.Bit.CmdData = COMMAND_DATA;

	SMP580_Drv_Get_Response(opCsIndex,opSpiIndex,SMP580_Cmd.Value);
	SMP580_Value.Value = SMP580_Drv_Get_Response(opCsIndex,opSpiIndex,SMP580_Cmd.Value);
	if (SMP580_Value.Bit.Diagnostic == NO_ERR)
	{
		if (SMP580_Drv_Check_Variant_Parity(SMP580_Value.Value))
		{
			*Pressure = SMP580_Value.Bit.RespData;
			return TRUE;
		}
	}
	return FALSE;
}

/* *****************************************************************************
* Function name: SMP580_Drv_Calculate_Pressure
* Function function: Calculate pressure
* Function parameter: Value-SMP580 pressure data returned
* Function return value: Pressure value unit: Pa 60KPa-165KPa
* Note: None
*******************************************************************************/
uint32_t SMP580_Drv_Calculate_Pressure(uint16_t Value)
{

	#define PRESSURE_MIN_VAL     60000 				// Minimum pressure: unit pa
	#define PRESSURE_MAX_VAL     165000 			// Maximum pressure: unit pa
	#define PRESSURE_CAL_PARAM   584570			// Pressure sensor parameter values
	#define PRESSURE_DIV_PARAM   9743 			// Pressure sensor parameter values
	#define PRESSURE_ENLARGEMENT_FACTOR   1000 			
	if (Value > SMP580_RESOLUTION_MAX)
	{
		Value = SMP580_RESOLUTION_MAX;
	}
	
	uint32_t Temp = (uint32_t)Value*1000 + PRESSURE_CAL_PARAM;
	Temp *= PRESSURE_ENLARGEMENT_FACTOR;
	Temp /= PRESSURE_DIV_PARAM;
	if(Temp<PRESSURE_MIN_VAL)
	{
		Temp = PRESSURE_MIN_VAL;
	}
	else if(Temp>PRESSURE_MAX_VAL)
	{
		Temp = PRESSURE_MAX_VAL;
	}
	return (uint32_t)Temp;

}

/* *****************************************************************************
* Function name: 	SMP580_Drv_Get_Temperature
* Function Function: Obtain the temperature data of the SMP580
* Function argument: Temperature - The returned temperature data
* Function return value: true - Obtaining data successfully
* Function return value: false - Failed to get data
* Note: None
*******************************************************************************/
BOOL SMP580_Drv_Get_Temperature(SPI_ConfigList_CS_Index opCsIndex,  SPI_ConfigList_Index opSpiIndex, uint16_t* Temperature)
{
	SMP580_16BIT_CMD SMP580_Cmd;
	SMP580_16BIT_VARIANT1 SMP580_Value;

	SMP580_Cmd.Bit.Request = REQUEST_TEMPERATURE;
	SMP580_Cmd.Bit.Status_Clear = STATUS_CLEAR_ACTION;
	SMP580_Cmd.Bit.CmdData = COMMAND_DATA;

	SMP580_Drv_Get_Response(opCsIndex,opSpiIndex,SMP580_Cmd.Value);
	SMP580_Value.Value = SMP580_Drv_Get_Response(opCsIndex,opSpiIndex,SMP580_Cmd.Value);

	if (SMP580_Value.Bit.Diagnostic == NO_ERR)
	{
		if (SMP580_Drv_Check_Variant_Parity(SMP580_Value.Value))
		{
			*Temperature = SMP580_Value.Bit.RespData;
			return TRUE;
		}
	}
	return FALSE;
}


/* *****************************************************************************
* Function name: SMP580_Drv_Calculate_Temperature
* Function Function: Calculate temperature
* Function parameter: value-temperature data returned by SMP580
* Function return value: Temperature value Unit: 1¡ãC -40¡ãC - 125¡ãC
* Note: None
*******************************************************************************/
int16_t SMP580_Drv_Calculate_Temperature(uint16_t Value)
{

	#define TEMP_MIN_VAL     -40 // Minimum pressure: unit Kpa
	#define TEMP_MAX_VAL     125 // Maximum pressure: unit Kpa
	#define TEMP_CAL_PARAM   2480 // Pressure sensor parameter values
	#define TEMP_DIV_PARAM   62 // Pressure sensor parameter values
	#define TEMP_ENLARGEMENT_FACTOR   10
	if (Value > SMP580_RESOLUTION_MAX)
	{
		Value = SMP580_RESOLUTION_MAX;
	}
	int32_t Temp = Value*TEMP_ENLARGEMENT_FACTOR;
	Temp -= TEMP_CAL_PARAM;
	Temp /= TEMP_DIV_PARAM;
	if(Temp<TEMP_MIN_VAL)
	{
		Temp = TEMP_MIN_VAL;
	}
	else if(Temp>TEMP_MAX_VAL)
	{
		Temp = TEMP_MAX_VAL;
	}

	return (int16_t)Temp;
}






