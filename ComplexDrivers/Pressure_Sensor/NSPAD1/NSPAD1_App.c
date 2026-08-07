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

//uint32_t Nspad1_NowPressure=0;

P_Sensor_Nspad1_str_t Nspad1_attribute_array[P_SENSOR_NSPAD1_MAX_NUM] ={

	{
		.m_Nspad1xEn = D_P_SENSOR_NSPAD1_INDEX0_USED,
		.Nspad1xInitFlag = FALSE,
		.Drv_Spi_Baudrate = SPI_COMM_BAUDRETE,
		.Drv_Spi_Index = SPI_ConfigList_SPI1,
		.Spi_Cs_Index = SPI_ConfigList_CS0,
		.NSPAD1_Pressure =0,
		.Nspad1_ReadStatus=0,
	},
	{
		.m_Nspad1xEn = D_P_SENSOR_NSPAD1_INDEX1_USED,
		.Nspad1xInitFlag = FALSE,
		.Drv_Spi_Baudrate = SPI_COMM_BAUDRETE,
		.Drv_Spi_Index = SPI_ConfigList_SPI1,
		.Spi_Cs_Index = SPI_ConfigList_CS1,
		.NSPAD1_Pressure =0,
		.Nspad1_ReadStatus=0,
	},
	{
		.m_Nspad1xEn = D_P_SENSOR_NSPAD1_INDEX2_USED,
		.Nspad1xInitFlag = FALSE,
		.Drv_Spi_Baudrate = SPI_COMM_BAUDRETE,
		.Drv_Spi_Index = SPI_ConfigList_SPI1,
		.Spi_Cs_Index = SPI_ConfigList_CS2,
		.NSPAD1_Pressure =0,
		.Nspad1_ReadStatus=0,
	},
	{
		.m_Nspad1xEn = D_P_SENSOR_NSPAD1_INDEX3_USED,
		.Nspad1xInitFlag = FALSE,
		.Drv_Spi_Baudrate = SPI_COMM_BAUDRETE,
		.Drv_Spi_Index = SPI_ConfigList_SPI1,
		.Spi_Cs_Index = SPI_ConfigList_CS3,
		.NSPAD1_Pressure =0,
		.Nspad1_ReadStatus=0,
	},
	{
		.m_Nspad1xEn = D_P_SENSOR_NSPAD1_INDEX4_USED,
		.Nspad1xInitFlag = FALSE,
		.Drv_Spi_Baudrate = SPI_COMM_BAUDRETE,
		.Drv_Spi_Index = SPI_ConfigList_SPI1,
		.Spi_Cs_Index = SPI_ConfigList_CS4,
		.NSPAD1_Pressure =0,
		.Nspad1_ReadStatus=0,
	},
	{
		.m_Nspad1xEn = D_P_SENSOR_NSPAD1_INDEX5_USED,
		.Nspad1xInitFlag = FALSE,
		.Drv_Spi_Baudrate = SPI_COMM_BAUDRETE,
		.Drv_Spi_Index = SPI_ConfigList_SPI1,
		.Spi_Cs_Index = SPI_ConfigList_CS5,
		.NSPAD1_Pressure =0,
		.Nspad1_ReadStatus=0,
	},
	{
		.m_Nspad1xEn = D_P_SENSOR_NSPAD1_INDEX6_USED,
		.Nspad1xInitFlag = FALSE,
		.Drv_Spi_Baudrate = SPI_COMM_BAUDRETE,
		.Drv_Spi_Index = SPI_ConfigList_SPI1,
		.Spi_Cs_Index = SPI_ConfigList_CS6,
		.NSPAD1_Pressure =0,
		.Nspad1_ReadStatus=0,
	},
	{
		.m_Nspad1xEn = D_P_SENSOR_NSPAD1_INDEX7_USED,
		.Nspad1xInitFlag = FALSE,
		.Drv_Spi_Baudrate = SPI_COMM_BAUDRETE,
		.Drv_Spi_Index = SPI_ConfigList_SPI1,
		.Spi_Cs_Index = SPI_ConfigList_CS7,
		.NSPAD1_Pressure =0,
		.Nspad1_ReadStatus=0,
	},
	{
		.m_Nspad1xEn = D_P_SENSOR_NSPAD1_INDEX8_USED,
		.Nspad1xInitFlag = FALSE,
		.Drv_Spi_Baudrate = SPI_COMM_BAUDRETE,
		.Drv_Spi_Index = SPI_ConfigList_SPI1,
		.Spi_Cs_Index = SPI_ConfigList_CS8,
		.NSPAD1_Pressure =0,
		.Nspad1_ReadStatus=0,
	},
	{
		.m_Nspad1xEn = D_P_SENSOR_NSPAD1_INDEX9_USED,
		.Nspad1xInitFlag = FALSE,
		.Drv_Spi_Baudrate = SPI_COMM_BAUDRETE,
		.Drv_Spi_Index = SPI_ConfigList_SPI1,
		.Spi_Cs_Index = SPI_ConfigList_CS9,
		.NSPAD1_Pressure =0,
		.Nspad1_ReadStatus=0,
	},
};


/* *****************************************************************************
*函数名      	：NSPAD1_Drv_Init
*函数功能  	：NSPAD1 初始化
*函数参数    	：无
*函数返回值	：无
*说明		：无
*******************************************************************************/
void NSPAD1_App_Init(void)
{
	uint8_t index=0;
	int8_t  SpiInitStatus = SCI_SUCCESS;
	
	for(index=0;index<P_SENSOR_NSPAD1_MAX_NUM;index++)
	{
		if(Nspad1_attribute_array[index].m_Nspad1xEn)
		{

			Nspad1_attribute_array[index].Nspad1xInitFlag = TRUE;
			SpiIf_Spi_Device_Nss_Set(Nspad1_attribute_array[index].Spi_Cs_Index,TRUE);//TRUE

		}
		
	}
	
	
}

void NSPAD1_App_Register_Init(void)
{
	uint8_t index=0;
	for(index=0;index<P_SENSOR_NSPAD1_MAX_NUM;index++)
	{
		if(Nspad1_attribute_array[index].m_Nspad1xEn)
		{
			if(TRUE == Nspad1_attribute_array[index].Nspad1xInitFlag)
			{
				NSPAD1_Drv_Enable_IC_SDO_Output(Nspad1_attribute_array[index].Spi_Cs_Index,Nspad1_attribute_array[index].Drv_Spi_Index);
			}
		}
	}

}
void NSPAD1_App_Register2_Init(void)
{
	uint8_t index=0;
	for(index=0;index<P_SENSOR_NSPAD1_MAX_NUM;index++)
	{
		if(Nspad1_attribute_array[index].m_Nspad1xEn)
		{
			if(TRUE == Nspad1_attribute_array[index].Nspad1xInitFlag)
			{
				NSPAD1_Drv_Enable_IC_VOUT_Output(Nspad1_attribute_array[index].Spi_Cs_Index,Nspad1_attribute_array[index].Drv_Spi_Index);
			}
		}
	}

}


void NSPAD1_App_DeInit(void)
{
	uint8_t index=0;
	for(index=0;index<P_SENSOR_NSPAD1_MAX_NUM;index++)
	{
		if(Nspad1_attribute_array[index].m_Nspad1xEn)
		{
			SPI_IF_DeInit();

			SpiIf_Spi_Device_Nss_Set(Nspad1_attribute_array[index].Spi_Cs_Index,FALSE);
			Nspad1_attribute_array[index].Nspad1xInitFlag = FALSE;
		}

	}
	
}

BOOL NSPAD1_App_PressureGet(P_SENSOR_NSPAD1_INDEX opIndex,uint32_t* Pressure)
{
	BOOL RetVal = FALSE;
	uint32_t TmpPressureVal;
	if(opIndex < P_SENSOR_NSPAD1_MAX_NUM)
	{
		if((Nspad1_attribute_array[opIndex].m_Nspad1xEn)&&(TRUE == Nspad1_attribute_array[opIndex].Nspad1xInitFlag))
		{
			if(NSPAD1_Drv_Get_Pressure(Nspad1_attribute_array[opIndex].Spi_Cs_Index,Nspad1_attribute_array[opIndex].Drv_Spi_Index,&TmpPressureVal))
			{

				*Pressure = NSPAD1_Drv_Calculate_Pressure(TmpPressureVal);
				RetVal = TRUE;
			}
			else
			{
				RetVal = FALSE;
			}

		}
		else
		{
			RetVal = FALSE;
		}
	}
	return RetVal;
}

