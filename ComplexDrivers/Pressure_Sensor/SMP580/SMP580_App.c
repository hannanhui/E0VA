/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      SMP580_App.c                                                             */
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


P_Sensor_Smp580_str_t Smp580_attribute_array[P_SENSOR_SMP580_MAX_NUM] ={

	{
		.m_Smp580xEn = D_P_SENSOR_SMP580_INDEX0_USED,
		.Smp580xInitFlag = FALSE,
		.Drv_Spi_Baudrate = SPI_COMM_BAUDRETE,
		.Drv_Spi_Index = SPI_ConfigList_SPI1,
		.Spi_Cs_Index = SPI_ConfigList_CS0,
		.SMP580_Id.Value =0,
		.SMP580_Pressure =0,			 
		.SMP580_Temperature =0,	
	},
	{
		.m_Smp580xEn = D_P_SENSOR_SMP580_INDEX1_USED,
		.Smp580xInitFlag = FALSE,
		.Drv_Spi_Baudrate = SPI_COMM_BAUDRETE,
		.Drv_Spi_Index = SPI_ConfigList_SPI1,
		.Spi_Cs_Index = SPI_ConfigList_CS1,
		.SMP580_Id.Value =0,
		.SMP580_Pressure =0,			 
		.SMP580_Temperature =0,	
	},
	{
		.m_Smp580xEn = D_P_SENSOR_SMP580_INDEX2_USED,
		.Smp580xInitFlag = FALSE,
		.Drv_Spi_Baudrate = SPI_COMM_BAUDRETE,
		.Drv_Spi_Index = SPI_ConfigList_SPI1,
		.Spi_Cs_Index = SPI_ConfigList_CS2,
		.SMP580_Id.Value =0,
		.SMP580_Pressure =0,			 
		.SMP580_Temperature =0,	
	},
	{
		.m_Smp580xEn = D_P_SENSOR_SMP580_INDEX3_USED,
		.Smp580xInitFlag = FALSE,
		.Drv_Spi_Baudrate = SPI_COMM_BAUDRETE,
		.Drv_Spi_Index = SPI_ConfigList_SPI1,
		.Spi_Cs_Index = SPI_ConfigList_CS3,
		.SMP580_Id.Value =0,
		.SMP580_Pressure =0,			 
		.SMP580_Temperature =0,	
	},
	{
		.m_Smp580xEn = D_P_SENSOR_SMP580_INDEX4_USED,
		.Smp580xInitFlag = FALSE,
		.Drv_Spi_Baudrate = SPI_COMM_BAUDRETE,
		.Drv_Spi_Index = SPI_ConfigList_SPI1,
		.Spi_Cs_Index = SPI_ConfigList_CS4,
		.SMP580_Id.Value =0,
		.SMP580_Pressure =0,			 
		.SMP580_Temperature =0,	
	},
	{
		.m_Smp580xEn = D_P_SENSOR_SMP580_INDEX5_USED,
		.Smp580xInitFlag = FALSE,
		.Drv_Spi_Baudrate = SPI_COMM_BAUDRETE,
		.Drv_Spi_Index = SPI_ConfigList_SPI1,
		.Spi_Cs_Index = SPI_ConfigList_CS5,
		.SMP580_Id.Value =0,
		.SMP580_Pressure =0,			 
		.SMP580_Temperature =0,	
	},
	{
		.m_Smp580xEn = D_P_SENSOR_SMP580_INDEX6_USED,
		.Smp580xInitFlag = FALSE,
		.Drv_Spi_Baudrate = SPI_COMM_BAUDRETE,
		.Drv_Spi_Index = SPI_ConfigList_SPI1,
		.Spi_Cs_Index = SPI_ConfigList_CS6,
		.SMP580_Id.Value =0,
		.SMP580_Pressure =0,			 
		.SMP580_Temperature =0,	
	},
	{
		.m_Smp580xEn = D_P_SENSOR_SMP580_INDEX7_USED,
		.Smp580xInitFlag = FALSE,
		.Drv_Spi_Baudrate = SPI_COMM_BAUDRETE,
		.Drv_Spi_Index = SPI_ConfigList_SPI1,
		.Spi_Cs_Index = SPI_ConfigList_CS7,
		.SMP580_Id.Value =0,
		.SMP580_Pressure =0,			 
		.SMP580_Temperature =0,	
	},
	{
		.m_Smp580xEn = D_P_SENSOR_SMP580_INDEX8_USED,
		.Smp580xInitFlag = FALSE,
		.Drv_Spi_Baudrate = SPI_COMM_BAUDRETE,
		.Drv_Spi_Index = SPI_ConfigList_SPI1,
		.Spi_Cs_Index = SPI_ConfigList_CS8,
		.SMP580_Id.Value =0,
		.SMP580_Pressure =0,			 
		.SMP580_Temperature =0,	
	},
	{
		.m_Smp580xEn = D_P_SENSOR_SMP580_INDEX9_USED,
		.Smp580xInitFlag = FALSE,
		.Drv_Spi_Baudrate = SPI_COMM_BAUDRETE,
		.Drv_Spi_Index = SPI_ConfigList_SPI1,
		.Spi_Cs_Index = SPI_ConfigList_CS9,
		.SMP580_Id.Value =0,
		.SMP580_Pressure =0,			 
		.SMP580_Temperature =0,	
	},
};


/* *****************************************************************************
*函数名      	：SMP580_Drv_Init
*函数功能  	：SMP580 初始化
*函数参数    	：无
*函数返回值	：无
*说明		：无
*******************************************************************************/
void SMP580_App_Init(void)
{
	uint8_t index=0;
	int8_t  SpiInitStatus = SCI_SUCCESS;
	
	for(index=0;index<P_SENSOR_SMP580_MAX_NUM;index++)
	{
		if(Smp580_attribute_array[index].m_Smp580xEn)
		{
			//SpiInitStatus = SPI_IF_Init(Smp580_attribute_array[index].Drv_Spi_Index,Smp580_attribute_array[index].Drv_Spi_Baudrate);

			Smp580_attribute_array[index].Smp580xInitFlag = TRUE;
			SpiIf_Spi_Device_Nss_Set(Smp580_attribute_array[index].Spi_Cs_Index,TRUE);
			if(TRUE == Smp580_attribute_array[index].Smp580xInitFlag)
			{
				Smp580_attribute_array[index].SMP580_Id.Value = SMP580_Drv_Get_Id(Smp580_attribute_array[index].Spi_Cs_Index,Smp580_attribute_array[index].Drv_Spi_Index);
			}
		}
		
	}
	
	
}
void SMP580_App_DeInit(void)
{
	uint8_t index=0;
	for(index=0;index<P_SENSOR_SMP580_MAX_NUM;index++)
	{
		if(Smp580_attribute_array[index].m_Smp580xEn)
		{
			//SPI_IF_DeInit(Smp580_attribute_array[index].Drv_Spi_Index);

			SpiIf_Spi_Device_Nss_Set(Smp580_attribute_array[index].Spi_Cs_Index,FALSE);
			Smp580_attribute_array[index].Smp580xInitFlag = FALSE;

		}

	}
	
}

BOOL SMP580_App_PressureGet(P_SENSOR_SMP580_INDEX opIndex,uint32_t* Pressure)
{
	BOOL RetVal = FALSE;
	uint16_t TmpPressureVal;
	if(opIndex < P_SENSOR_SMP580_MAX_NUM)
	{
		if((Smp580_attribute_array[opIndex].m_Smp580xEn)&&(TRUE == Smp580_attribute_array[opIndex].Smp580xInitFlag))
		{
			if (SMP580_Drv_Get_Pressure(Smp580_attribute_array[opIndex].Spi_Cs_Index,Smp580_attribute_array[opIndex].Drv_Spi_Index,&TmpPressureVal))
			{
				*Pressure = SMP580_Drv_Calculate_Pressure(TmpPressureVal);
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
BOOL SMP580_App_TemperatureGet(P_SENSOR_SMP580_INDEX opIndex,int16_t* Temperature)
{
	BOOL RetVal = FALSE;
	uint16_t TmpTemperatureVal;
	if(opIndex < P_SENSOR_SMP580_MAX_NUM)
	{
		if((Smp580_attribute_array[opIndex].m_Smp580xEn)&&(TRUE == Smp580_attribute_array[opIndex].Smp580xInitFlag))
		{
			if (SMP580_Drv_Get_Temperature(Smp580_attribute_array[opIndex].Spi_Cs_Index,Smp580_attribute_array[opIndex].Drv_Spi_Index,&TmpTemperatureVal))
			{
				*Temperature = SMP580_Drv_Calculate_Temperature(TmpTemperatureVal);
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
void SMP580_App_RunStatus_Manage(void)
{

}
