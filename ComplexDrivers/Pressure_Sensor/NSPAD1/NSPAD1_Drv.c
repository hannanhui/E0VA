/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      NSPAD1_Drv.c                                                             */
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



void NSPAD1_Drv_SendCmd(SPI_ConfigList_CS_Index opCsIndex,  SPI_ConfigList_Index opSpiIndex,uint16_t Cmd)
{
	uint8_t Send[3];
	uint8_t Recv[2];

	Send[0] = 0x00;
	Send[1] = 0x00;
	Send[1] +=((Cmd >> 8) & 0xFF);
	Send[2] = (Cmd >> 0) & 0xFF;
	SpiIf_Spi_Device_Nss_Set(opCsIndex,FALSE);
	SpiIf_SpiReadWrite_aByte(opSpiIndex,Send[0]);
	SpiIf_SpiReadWrite_aByte(opSpiIndex,Send[1]);
	SpiIf_SpiReadWrite_aByte(opSpiIndex,Send[2]);
	SpiIf_Spi_Device_Nss_Set(opCsIndex,TRUE);
}
uint8_t NSPAD1_Drv_RecvOneByte(SPI_ConfigList_CS_Index opCsIndex,  SPI_ConfigList_Index opSpiIndex,uint16_t Cmd)
{
	uint8_t Send[3];
	uint8_t Recv[2];
	uint8_t Ret=0U;
	Send[0] = 0x80;
	Send[1] = 0x00;
	Send[1] +=((Cmd >> 8) & 0xFF);
	Send[2] = (Cmd >> 0) & 0xFF;
	SpiIf_Spi_Device_Nss_Set(opCsIndex,FALSE);
	SpiIf_SpiReadWrite_aByte(opSpiIndex,Send[0]);
	SpiIf_SpiReadWrite_aByte(opSpiIndex,Send[1]);
	Recv[0] = SpiIf_SpiReadWrite_aByte(opSpiIndex,Send[2]);
	SpiIf_Spi_Device_Nss_Set(opCsIndex,TRUE);
	Ret = Recv[0];
	return Ret;
}
uint32_t NSPAD1_Drv_RecvThreeByte(SPI_ConfigList_CS_Index opCsIndex,  SPI_ConfigList_Index opSpiIndex,uint16_t Cmd)
{
	uint8_t Send[5];
	uint8_t Recv[3];
	uint32_t Ret=0U;

	Send[0] = 0x80;
		Send[1] = 0x06;
		//Send[1] +=((Cmd >> 8) & 0xFF);
		Send[2] = 0;//(Cmd >> 0) & 0xFF;
		SpiIf_Spi_Device_Nss_Set(opCsIndex,FALSE);
		SpiIf_SpiReadWrite_aByte(opSpiIndex,Send[0]);
		SpiIf_SpiReadWrite_aByte(opSpiIndex,Send[1]);
		Recv[0] = SpiIf_SpiReadWrite_aByte(opSpiIndex,Send[2]);
		SpiIf_Spi_Device_Nss_Set(opCsIndex,TRUE);
		Send[0] = 0x80;
		Send[1] = 0x07;
		//Send[1] +=((Cmd >> 8) & 0xFF);
		Send[2] = (Cmd >> 0) & 0xFF;
		SpiIf_Spi_Device_Nss_Set(opCsIndex,FALSE);
		SpiIf_SpiReadWrite_aByte(opSpiIndex,Send[0]);
		SpiIf_SpiReadWrite_aByte(opSpiIndex,Send[1]);
		Recv[1] = SpiIf_SpiReadWrite_aByte(opSpiIndex,Send[2]);
		SpiIf_Spi_Device_Nss_Set(opCsIndex,TRUE);
		Send[0] = 0x80;
		Send[1] = 0x08;
		//Send[1] +=((Cmd >> 8) & 0xFF);
		Send[2] = 0;//(Cmd >> 0) & 0xFF;
		SpiIf_Spi_Device_Nss_Set(opCsIndex,FALSE);
		SpiIf_SpiReadWrite_aByte(opSpiIndex,Send[0]);
		SpiIf_SpiReadWrite_aByte(opSpiIndex,Send[1]);
		Recv[2] = SpiIf_SpiReadWrite_aByte(opSpiIndex,Send[2]);
		SpiIf_Spi_Device_Nss_Set(opCsIndex,TRUE);

	Ret = (((uint32_t)Recv[0]<<16)|((uint32_t)Recv[1]<<8)|((uint32_t)Recv[2]));
	return Ret;
}

/* *****************************************************************************
* Function name: SMP580_Drv_Get_Id
* Function Function: Obtain ID data of the SMP580
* Function parameter: SMP580 ID value
* Function return: none
* Note: None
*******************************************************************************/
uint16_t NSPAD1_Drv_Enable_IC_SDO_Output(SPI_ConfigList_CS_Index opCsIndex,  SPI_ConfigList_Index opSpiIndex)
{
	NSPAD1_16BIT_CMD NSPAD1_Cmd;
	NSPAD1_Cmd.Bit.CmdAddr = REQUEST_INIT;
	NSPAD1_Cmd.Bit.CmdData = DATA_INIT;
	NSPAD1_Drv_SendCmd(opCsIndex,opSpiIndex,NSPAD1_Cmd.Value);

	return 0U;
}
void NSPAD1_Drv_Enable_IC_VOUT_Output(SPI_ConfigList_CS_Index opCsIndex,  SPI_ConfigList_Index opSpiIndex)
{
	NSPAD1_16BIT_CMD NSPAD1_Cmd;
	NSPAD1_Cmd.Bit.CmdAddr = 0xA5;
	NSPAD1_Cmd.Bit.CmdData = 0x80;
	NSPAD1_Drv_SendCmd(opCsIndex,opSpiIndex,NSPAD1_Cmd.Value);
	NSPAD1_Cmd.Bit.CmdAddr = 0xA5;
	NSPAD1_Cmd.Bit.CmdData = DATA__READ_PRESSURE;
	NSPAD1_Drv_RecvOneByte(opCsIndex,opSpiIndex,NSPAD1_Cmd.Value);
}
/* *****************************************************************************
* Function name: NSPAD1_Drv_Start_Conversion_Pressure
* Function Function: Obtain the pressure data of the SMP580
* Function argument: Pressure - Returned pressure data
* Function return value: true - Obtaining data successfully
* Function return value: false - Failed to get data
* Note: None
*******************************************************************************/
void NSPAD1_Drv_Start_Conversion_Pressure(SPI_ConfigList_CS_Index opCsIndex,  SPI_ConfigList_Index opSpiIndex)
{
	NSPAD1_16BIT_CMD NSPAD1_Cmd;
	NSPAD1_Cmd.Bit.CmdAddr = REQUEST_START_CONVERSION;
	NSPAD1_Cmd.Bit.CmdData = DATA_START_CONVERSION;
	NSPAD1_Drv_SendCmd(opCsIndex,opSpiIndex,NSPAD1_Cmd.Value);
}

void NSPAD1_Drv_Start_Reset(SPI_ConfigList_CS_Index opCsIndex,  SPI_ConfigList_Index opSpiIndex)
{
	NSPAD1_16BIT_CMD NSPAD1_Cmd;
	NSPAD1_Cmd.Bit.CmdAddr = REQUEST_RESET;
	NSPAD1_Cmd.Bit.CmdData = DATA_RESET;
	NSPAD1_Drv_SendCmd(opCsIndex,opSpiIndex,NSPAD1_Cmd.Value);
}

BOOL NSPAD1_Drv_Read_Pressure_Conversion_Status(SPI_ConfigList_CS_Index opCsIndex,  SPI_ConfigList_Index opSpiIndex)
{
	NSPAD1_16BIT_CMD NSPAD1_Cmd;
	BOOL Ret=FALSE;
	NSPAD1_Cmd.Bit.CmdAddr = DATA_READ_CONVERSION_END_STATUS;
	NSPAD1_Cmd.Bit.CmdData = REQUEST_READ_CONVERSION_END_STATUS;
	if(COMMAND_CONVERSION_SUCCESS == NSPAD1_Drv_RecvOneByte(opCsIndex,opSpiIndex,NSPAD1_Cmd.Value))
	{
		Ret =TRUE;
	}
	else
	{
		Ret=FALSE;

	}
	return Ret;
}
BOOL NSPAD1_Drv_Read_6C_Status(SPI_ConfigList_CS_Index opCsIndex,  SPI_ConfigList_Index opSpiIndex)
{
	NSPAD1_16BIT_CMD NSPAD1_Cmd;
	BOOL Ret=FALSE;
	NSPAD1_Cmd.Bit.CmdAddr = 0x6C;
	NSPAD1_Cmd.Bit.CmdData = DATA__READ_PRESSURE;
	NSPAD1_Drv_RecvOneByte(opCsIndex,opSpiIndex,NSPAD1_Cmd.Value);
	return Ret;
}
/* *****************************************************************************
* Function name: SMP580_Drv_Get_Pressure
* Function Function: Obtain the pressure data of the SMP580
* Function argument: Pressure - Returned pressure data
* Function return value: true - Obtaining data successfully
* Function return value: false - Failed to get data
* Note: None
*******************************************************************************/
BOOL NSPAD1_Drv_Get_Pressure(SPI_ConfigList_CS_Index opCsIndex,  SPI_ConfigList_Index opSpiIndex, uint32_t* Pressure)
{
	NSPAD1_16BIT_CMD NSPAD1_Cmd;
	uint32_t Value=0;
	BOOL Ret=FALSE;
	NSPAD1_Cmd.Bit.CmdAddr = REQUEST_READ_PRESSURE;
	NSPAD1_Cmd.Bit.CmdData = DATA__READ_PRESSURE;
	Value =NSPAD1_Drv_RecvThreeByte(opCsIndex,opSpiIndex,NSPAD1_Cmd.Value);
	if ((Value > NSPAD1_RESOLUTION_MAX)||(0u == Value))
	{
		Ret =FALSE;
	}
	else
	{
		Ret=TRUE;
		* Pressure =Value;

	}
	return Ret;
}

/* *****************************************************************************
* Function name: NSPAD1_Drv_Calculate_Pressure
* Function function: Calculate pressure
* Function parameter: Value-NSPAD1 pressure data returned
* Function return value: Pressure value unit: Pa 60KPa-165KPa
* Note: None
*******************************************************************************/
uint32_t NSPAD1_Drv_Calculate_Pressure(uint32_t Value)
{

	#define PRESSURE_MIN_VAL     60000 				// Minimum pressure: unit pa
	#define PRESSURE_MAX_VAL     165000 			// Maximum pressure: unit pa
	#define PRESSURE_CAL_PARAM   46875			// Pressure sensor parameter values
	#define PRESSURE_DIV_PARAM   31250 			// Pressure sensor parameter values
	#define PRESSURE_ENLARGEMENT_FACTOR   489
	#define PARAM_INSIDE_MAX_VALUE			0x733333
	uint32_t Temp = 0u;
	if(Value>PARAM_INSIDE_MAX_VALUE)
	{
		Temp = PARAM_INSIDE_MAX_VALUE;
	}
	else
	{
		Temp = Value;
	}
	Temp *= PRESSURE_ENLARGEMENT_FACTOR;
	Temp /= PRESSURE_DIV_PARAM;
	Temp +=PRESSURE_CAL_PARAM;
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




