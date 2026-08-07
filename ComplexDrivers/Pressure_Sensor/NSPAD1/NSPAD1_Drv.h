/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      NSPAD1_Drv.h                                                             */
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

#ifndef __NSPAD1_DRV_H__
#define __NSPAD1_DRV_H__


#include "NSPAD1.h"
#include "Ecal_SPI.h"

#define NSPAD1_RESOLUTION_MAX		0x7FFFFF



#define REQUEST_INIT  0x00			//Enable SDO Output
#define DATA_INIT  0x81
#define REQUEST_START_CONVERSION  0x30
#define DATA_START_CONVERSION  0x0A
#define REQUEST_READ_CONVERSION_END_STATUS  0xFF
#define DATA_READ_CONVERSION_END_STATUS  0x30

#define REQUEST_READ_PRESSURE  0x08
#define DATA__READ_PRESSURE  0xFF
#define COMMAND_CONVERSION_SUCCESS 0x02 					// The data segment for sending a command must be 0

#define REQUEST_RESET  0x00
#define DATA_RESET  0x24

typedef union
{
	uint16_t Value;

	struct
	{
		uint16_t   CmdData		: 8;	// bit13-15
		uint16_t   CmdAddr 		: 8;	// bit0-11
		

	}Bit;

}NSPAD1_16BIT_CMD;



typedef union
{
	uint16_t Value;

	struct
	{
		uint16_t   CheckSun 		: 1;	// bit0		bit1-bit15 Odd check The value is 1 when the number of 1s is even (including 0). The value is 0 when the number of 1s is odd
		uint16_t   RespData		: 10;	// bit1-10
		uint16_t   Diagnostic		: 5;	// bit11-15

	}Bit;

}NSPAD1_16BIT_VARIANT1;

extern void NSPAD1_Drv_Start_Conversion_Pressure(SPI_ConfigList_CS_Index opCsIndex,  SPI_ConfigList_Index opSpiIndex);
extern BOOL NSPAD1_Drv_Read_Pressure_Conversion_Status(SPI_ConfigList_CS_Index opCsIndex,  SPI_ConfigList_Index opSpiIndex);
extern void NSPAD1_Drv_Start_Reset(SPI_ConfigList_CS_Index opCsIndex,  SPI_ConfigList_Index opSpiIndex);
extern BOOL NSPAD1_Drv_Read_6C_Status(SPI_ConfigList_CS_Index opCsIndex,  SPI_ConfigList_Index opSpiIndex);
extern BOOL NSPAD1_Drv_Get_Pressure(SPI_ConfigList_CS_Index opCsIndex,  SPI_ConfigList_Index opSpiIndex, uint32_t* Pressure);
extern uint32_t NSPAD1_Drv_Calculate_Pressure(uint32_t Value);
extern uint16_t NSPAD1_Drv_Enable_IC_SDO_Output(SPI_ConfigList_CS_Index opCsIndex,  SPI_ConfigList_Index opSpiIndex);
extern void NSPAD1_Drv_Enable_IC_VOUT_Output(SPI_ConfigList_CS_Index opCsIndex,  SPI_ConfigList_Index opSpiIndex);
#endif /* __SMP580_DRV_H__ */
