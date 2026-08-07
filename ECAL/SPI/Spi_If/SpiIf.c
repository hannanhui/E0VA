/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      SpiIf.c                                                                  */
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

#include "Ecal_SPI.h"


volatile static uint8_t  g_csi01_Send_Recv_Flag=0;           /* csi01 send data count */


void SPI_IF_Init(void)
{

	Spi_Init(NULL_PTR);

}


void SPI_IF_DeInit(void)
{
   
}





uint8_t Spi_Drv_ReadWrite_aByte(SPI_ConfigList_Index SpiIndex,uint8_t Send)
{
		uint8_t ReadData=0;
		uint8_t SpiWriteBuff[1u] = {0x00};
		uint8_t SpiReadBuff[1u] = {0x00};
		uint8_t Spi_Commumication_Timeout=0;
		if(SPI_ConfigList_SPI1 == SpiIndex)
		{
			SpiWriteBuff[0] = Send;
			Spi_SetupEB(SpiConf_SpiChannel_MasterC_SPI1, SpiWriteBuff, SpiReadBuff, 1u);
			Spi_SyncTransmit(SpiConf_SpiSequence_MasterS_SPI1);
			ReadData = SpiReadBuff[0];
		}
	  return ReadData;
}

uint8_t SpiIf_SpiReadWrite_aByte(SPI_ConfigList_Index SpiIndex,uint8_t Send)
{
	  uint8_t ReadData=0;
	  #if (STD_ON == MCU_SPI_USE_DEFINE)    
		if(SpiIndex<SPI_ConfigList_Num)
		{
			
			switch(SpiIndex)
			{
				case SPI_ConfigList_SPI0:
					//SET_SPI0_CS_EN;
					ReadData=Spi_Drv_ReadWrite_aByte(SpiIndex,Send);
				    //CLR_SPI0_CS_EN;
					break;
				case SPI_ConfigList_SPI1:
					//SET_SPI1_CS_EN;
					ReadData=Spi_Drv_ReadWrite_aByte(SpiIndex,Send);
				    //CLR_SPI1_CS_EN;
					break;
				case SPI_ConfigList_SPI2:
					//SET_SPI2_CS_EN;
					ReadData=Spi_Drv_ReadWrite_aByte(SpiIndex,Send);
				    //CLR_SPI2_CS_EN;
					break;
				case SPI_ConfigList_SPI3:
					//SET_SPI3_CS_EN;
					ReadData=Spi_Drv_ReadWrite_aByte(SpiIndex,Send);
				    //CLR_SPI3_CS_EN;
					break;

				default:
					ReadData=0U;
					break;
			}
			
		}
		else
		{
			  ReadData =0u;
		}
		
	#endif
		return ReadData;
}



void SpiIf_Spi_Device_Nss_Set(SPI_ConfigList_CS_Index opIndex,uint8_t SetVal)
{
	switch(opIndex)
	{
		case SPI_ConfigList_CS0:
			if(SetVal)
			{
				SET_SPI1_CS0_EN;
			}
			else
			{
				CLR_SPI1_CS0_EN;
			}
			break;
		case SPI_ConfigList_CS1:
			if(SetVal)
			{
				SET_SPI1_CS1_EN;
			}
			else
			{
				CLR_SPI1_CS1_EN;
			}
			break;
		case SPI_ConfigList_CS2:
			if(SetVal)
			{
				SET_SPI1_CS2_EN;
			}
			else
			{
				CLR_SPI1_CS2_EN;
			}
			break;
		case SPI_ConfigList_CS3:
			if(SetVal)
			{
				SET_SPI1_CS3_EN;
			}
			else
			{
				CLR_SPI1_CS3_EN;
			}
			break;
		case SPI_ConfigList_CS4:
			if(SetVal)
			{
				SET_SPI1_CS4_EN;
			}
			else
			{
				CLR_SPI1_CS4_EN;
			}
			break;
		case SPI_ConfigList_CS5:
			if(SetVal)
			{
				SET_SPI1_CS5_EN;
			}
			else
			{
				CLR_SPI1_CS5_EN;
			}
			break;
		case SPI_ConfigList_CS6:
			if(SetVal)
			{
				SET_SPI1_CS6_EN;
			}
			else
			{
				CLR_SPI1_CS6_EN;
			}
			break;
		case SPI_ConfigList_CS7:
			if(SetVal)
			{
				SET_SPI1_CS7_EN;
			}
			else
			{
				CLR_SPI1_CS7_EN;
			}
			break;
		case SPI_ConfigList_CS8:
			if(SetVal)
			{
				SET_SPI1_CS8_EN;
			}
			else
			{
				CLR_SPI1_CS8_EN;
			}
			break;
		case SPI_ConfigList_CS9:
			if(SetVal)
			{
				SET_SPI1_CS9_EN;
			}
			else
			{
				CLR_SPI1_CS9_EN;
			}
			break;
		default:
			break;
				
	}
}
/**
* @brief Job Start Notification for Job 'MasterJ_SPI1'
*/
void Cbk_Spi1_Master_JobStartNotification(void)
{

}

/**
* @brief Job End Notification for Job 'MasterJ_SPI1'
*/
void Cbk_Spi1_Master_JobEndNotification(void)
{

}

/**
* @brief Sequence End Notification for Sequence 'MasterS_SPI1'
*/
void Cbk_Spi1_Master_SeqEndNotification(void)
{

}

