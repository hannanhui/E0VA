/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      ProprietaryLin_App.c                                                     */
/*   Instance     :                                                                               */
/*   Author       :      Ed                                                                       */
/*   Modify date  :      2025-12-22 14:00:05 PM                                                   */
/*   Description  :                                                                               */
/*                                                                                                */
/*                                                                                                */
/*   Compiler    :       KungFu32 IDE  [Version: V1.0.20.3]                                       */
/*   Hardware    :       ChipOn microcontroller KF32A Family [KF32A156MQV]                        */
/*   Version     :       V1.0                                                                     */
/*                                                                                                */
/*                                                                                                */
/*   All rights reserved. Distribution or duplication without previous written agreement of the   */
/*   owner prohibited.                                                                            */
/*                                                                                                */
/**************************************************************************************************/
#include "include.h"
#if UPGRADE_MODE == UPGRADE_MODE_FOR_PROPRIETARY_LIN


static uint8_t ProprietaryLin_Force_Jump_App = 0U;	


uint8_t  Version_Req;						// 版本信息请求
uint8_t  Version_Package_Index;			// 版本信息分包
// 设置当前的运行模式  Boot/App

uint32_t Image_CheckSum;
uint8_t  Image_Crc8;

const BOOT_APP_MODE Run_Mode = BOOT_MODE;



uint8_t	ProprietaryLin_App_Buf[1024];				// 接收数据缓存
uint8_t	ProprietaryLin_App_Buf_CrcData[5];				// 接收数据缓存
uint16_t	ProprietaryLin_App_Package;  				// 当前请求的包号
uint8_t	ProprietaryLin_App_FlashEraseFlag=0;    				// 当前请求的包内偏移

uint8_t	ProprietaryLin_App_Index;    				// 当前请求的包内偏移
BOOL    ProprietaryLin_App_Pk_Complete;				// 当前请求1KByte数据完成

BOOL    ProprietaryLin_App_Force_Jump_App;			// 强制跳转到App
BOOL    ProprietaryLin_App_Finish;					// 当前所有请求完成
uint8_t	ProprietaryLin_App_ResetFlag=0u;    				// 复位标志


uint32_t  ProprietaryLin_App_Rx_Image_CheckSum;		// 接收到的升级数据累加和
uint8_t   ProprietaryLin_App_Rx_Image_Crc8;			// 接收到的升级数据校验和

/*******************************************************************************
*函数名     ：ProprietaryLin_App_Init
*函数功能  	：LIN 升级初始化
*函数参数   ：无
*函数返回值	：无
*说明		：无
*******************************************************************************/
void ProprietaryLin_App_Init(void)
{
	ProprietaryLin_Force_Jump_App = FALSE;
	Version_Req = VERSION_REQ_NONE;
	Version_Package_Index = 0;
	ProprietaryLin_App_Package     = 0;
	ProprietaryLin_App_Index       = 0;
	ProprietaryLin_App_FlashEraseFlag=0;
	ProprietaryLin_App_Pk_Complete = FALSE;
	ProprietaryLin_App_Finish      = FALSE;
	// 计算的校验信息
	Image_CheckSum = 0;	
	Image_Crc8 = 0;		
	
}

uint8_t ProprietaryLin_App_VersionReqFlagGet(void)
{
	return Version_Req;
}
void ProprietaryLin_App_Update_Request(volatile uint8_t *i_pDataBuf)
{
	i_pDataBuf[0] = Run_Mode;					// Boot 模式
	i_pDataBuf[1] = 0;							// 升级请求
	i_pDataBuf[2] = ProprietaryLin_App_Pk_Complete;	// 是否空闲
	i_pDataBuf[3] = ProprietaryLin_App_Package >> 8;// Package
	i_pDataBuf[4] = ProprietaryLin_App_Package >> 0;
	i_pDataBuf[5] = ProprietaryLin_App_Index;		// Index
	i_pDataBuf[6] = 0;
	i_pDataBuf[7] = 0;
}


void ProprietaryLin_App_VersionRespond(volatile uint8_t *i_pDataBuf)
{
	uint8_t* pVer = NULL;
	uint8_t  Ver_Index=0;
	uint8_t  Temp;
	uint8_t  i;
	BOOL   End;
	// 获取版本信息
	 if (Version_Req == VERSION_REQ_BOOT_MAJOR)
	{
		pVer = Boot_Major_Version;
		Ver_Index = 1;
	}
	else if (Version_Req == VERSION_REQ_BOOT_MINOR)
	{
		pVer = Boot_Minor_Version;
		Ver_Index = 1;
	}
	else if (Version_Req == VERSION_REQ_APP_MAJOR)
	{
		pVer = App_Major_Version;
		Ver_Index = 1;
	}
	else if (Version_Req == VERSION_REQ_APP_MINOR)
	{
		pVer = App_Minor_Version;
		Ver_Index = 1;
	}	
	if(Ver_Index != 0)
	{
		// 发送版本信息
		i_pDataBuf[0] = Run_Mode;	// App 模式
		i_pDataBuf[1] = Ver_Index + Version_Package_Index;

		End = FALSE;

		for (i=0; i< 6; i++)
		{
			if (End == FALSE)
			{
				Temp = pVer[6*Version_Package_Index+i];
				End = !Temp;
			}
			else
			{
				Temp = 0;
			}
			i_pDataBuf[2+i] = Temp;
		}
		Version_Package_Index++;
	}
	else
	{
		i_pDataBuf[0] = Run_Mode;	// App 模式
		for (i=1; i< 8; i++)
		{
			i_pDataBuf[i] = 0;
		}
	}

}

void ProprietaryLin_DriverWriteDataInProprietaryLin(volatile uint8_t *i_pDataBuf)
{
	uint8_t i;
	uint8_t* pData = (uint8_t*)ProprietaryLin_App_Buf;
	if (i_pDataBuf[0] == 0xFF)
	{
		// 升级完成
		if (i_pDataBuf[1] == 0)
		{
			// 接收的校验信息
			ProprietaryLin_App_Rx_Image_CheckSum   = i_pDataBuf[2];
			ProprietaryLin_App_Rx_Image_CheckSum <<= 8;
			ProprietaryLin_App_Rx_Image_CheckSum  |= i_pDataBuf[3];
			ProprietaryLin_App_Rx_Image_CheckSum <<= 8;
			ProprietaryLin_App_Rx_Image_CheckSum  |= i_pDataBuf[4];
			ProprietaryLin_App_Rx_Image_CheckSum <<= 8;
			ProprietaryLin_App_Rx_Image_CheckSum  |= i_pDataBuf[5];

			ProprietaryLin_App_Rx_Image_Crc8       = i_pDataBuf[6];

			ProprietaryLin_App_Finish = TRUE;
		}
		// 升级请求
		else if (i_pDataBuf[1] == 1)
		{
			Version_Req = VERSION_REQ_NONE;
		}
		// 获取当前模式版本信息
		else if (i_pDataBuf[1] == 2)
		{
			if ((i_pDataBuf[2] == 0x5A) &&
				(i_pDataBuf[3] == 0xA5) &&
				(i_pDataBuf[4] == 0x69) &&
				(i_pDataBuf[5] == 0x96) )
			{
				Version_Package_Index = 0;
				if (APP_MODE == Run_Mode)
				{
					if (i_pDataBuf[6] == VERSION_MAJOR)
					{
						Version_Req = VERSION_REQ_APP_MAJOR;
					}
					else 
					{
						Version_Req = VERSION_REQ_APP_MINOR;
					}
				}
				else
				{					
					if (i_pDataBuf[6] == VERSION_MAJOR)
					{
						Version_Req = VERSION_REQ_BOOT_MAJOR;
					}
					else 
					{
						Version_Req = VERSION_REQ_BOOT_MINOR;
					}						
				}
			}
		}
		// 获取其它模式版本信息(App时为Boot；Boot时为App)
		else if (i_pDataBuf[1] == 3)
		{
			if ((i_pDataBuf[2] == 0x5A) &&
				(i_pDataBuf[3] == 0xA5) &&
				(i_pDataBuf[4] == 0x69) &&
				(i_pDataBuf[5] == 0x96) )
			{
				Version_Package_Index = 0;

				if (APP_MODE == Run_Mode)
				{
					if (i_pDataBuf[6] == VERSION_MAJOR)
					{
						Version_Req = VERSION_REQ_BOOT_MAJOR;
					}
					else 
					{
						Version_Req = VERSION_REQ_BOOT_MINOR;
					}	
				}
				else
				{
					if (i_pDataBuf[6] == VERSION_MAJOR)
					{
						Version_Req = VERSION_REQ_APP_MAJOR;
					}
					else 
					{
						Version_Req = VERSION_REQ_APP_MINOR;
					}
				}
			}
		}
		// 强制跳转到App模式
		else if (i_pDataBuf[1] == 4)
		{
			// 此命令在Boot模式有效，Boot模式收到此命令时说明升级数据发送完成，跳转到App。
			if ((i_pDataBuf[2] == 0x5A) &&
				(i_pDataBuf[3] == 0xA5) &&
				(i_pDataBuf[4] == 0x69) &&
				(i_pDataBuf[5] == 0x96) )
			{
				ProprietaryLin_Force_Jump_App = TRUE;
			}
		}
	}
	else if (i_pDataBuf[0] <= 146)
	{


		if (i_pDataBuf[0] == 146)
		{
			for(i=0; i<2; i++)
			{
				pData[7*i_pDataBuf[0]+i] = i_pDataBuf[1+i];
			}
			for(i=0; i<5; i++)
			{
				ProprietaryLin_App_Buf_CrcData[i] = i_pDataBuf[3+i];
			}
			ProprietaryLin_App_Pk_Complete = 1;
		}
		else
		{
			for(i=0; i<7; i++)
			{
				pData[7*i_pDataBuf[0]+i] = i_pDataBuf[1+i];
			}

		}
	}
}
uint8_t  Crc8[5];
uint8_t  CrcBuf4_Tmp=0;
void ProprietaryLin_MainFun(void)
{

	//uint16_t Package;
	uint16_t Index;

	uint8_t* pData = (uint8_t*)ProprietaryLin_App_Buf;
	// 升级请求
	if (ProprietaryLin_Force_Jump_App)
	{
		// 写入成功
		if (NVM_Handle_RunAreaSet(NVM_Handle_Run_At_App))
		{
			// 复位，复位后自动跳转Boot
			System_SwResetFlagSet(TRUE);
			//增加延时复位，保证升级标志写入
		}
		return;
		
	}
	// 升级完成
	if (ProprietaryLin_App_Finish)
	{
		
		if ((ProprietaryLin_App_Rx_Image_CheckSum == Image_CheckSum) && (ProprietaryLin_App_Rx_Image_Crc8 == Image_Crc8))
		{
			// 写入成功
			if (NVM_Handle_RunAreaSet(NVM_Handle_Run_At_App))
			{
				System_SwResetFlagSet(TRUE);
			}
		}
		else
		{
			ProprietaryLin_App_Package = 0;
			ProprietaryLin_App_Index = 0;
			ProprietaryLin_App_FlashEraseFlag =0;
			ProprietaryLin_App_Finish  = false;
			ProprietaryLin_App_Force_Jump_App = false;
			ProprietaryLin_App_Pk_Complete = false;
			// 计算的校验信息
			Image_CheckSum = 0;	
			Image_Crc8 = 0;	
		}
	}


	// 接收1包数据完成
	if (ProprietaryLin_App_Pk_Complete)//等待上位机获取接收完成标志
	{
		Crc8[0] = CommCrcCal_crc8(&pData[0],   256, 0);
		Crc8[1] = CommCrcCal_crc8(&pData[256], 256, 0);
		Crc8[2] = CommCrcCal_crc8(&pData[512], 256, 0);
		Crc8[3] = CommCrcCal_crc8(&pData[768], 256, 0);
		CrcBuf4_Tmp = CommCrcCal_crc8(&pData[0],   1024,0);
		Crc8[4] = CommCrcCal_crc8(&ProprietaryLin_App_Buf_CrcData[0],   4,CrcBuf4_Tmp);
		if ((Crc8[0] == ProprietaryLin_App_Buf_CrcData[0]) &&
			(Crc8[1] == ProprietaryLin_App_Buf_CrcData[1]) &&
			(Crc8[2] == ProprietaryLin_App_Buf_CrcData[2]) &&
			(Crc8[3] == ProprietaryLin_App_Buf_CrcData[3]) &&
			(Crc8[4] == ProprietaryLin_App_Buf_CrcData[4]) )
		{
			// 校验通过，写入数据
			
			if(0u == ProprietaryLin_App_FlashEraseFlag)
			{
				// 计算的校验信息
				Image_CheckSum = 0;	// 580661
				Image_Crc8 = 0;		// 91
				if((NVM_Handle_DataEraseOperate(NVM_Handle_CodeFlashData,ApplicationAddress)==TRUE)&&(NVM_Handle_RunAreaSet(NVM_Handle_Run_At_Boot)==TRUE))
				{
					ProprietaryLin_App_FlashEraseFlag = TRUE;
				}
				else
				{
					ProprietaryLin_App_FlashEraseFlag = FALSE;
				}
				//ProprietaryLin_App_FlashEraseFlag =1u;
			}
			if (NVM_Handle_DataWriteOperate(NVM_Handle_CodeFlashData,NVM_Handle_CodeFlash_Erase_PageWrite,(ApplicationAddress + ProprietaryLin_App_Package*UPDATE_PACKAGE_SIZE_BYTE),&ProprietaryLin_App_Buf[0], UPDATE_PACKAGE_SIZE_BYTE)==TRUE)
			{
				//if (NVM_Handle_DataWriteOperate(NVM_Handle_CodeFlashData,(ApplicationAddress + ProprietaryLin_App_Package*UPDATE_PACKAGE_SIZE_BYTE+FLASH_ONE_SECTOR_SIZE),&ProprietaryLin_App_Buf[FLASH_ONE_SECTOR_SIZE], FLASH_ONE_SECTOR_SIZE)==TRUE)
				{
					
					INT_All_Enable(DISABLE);//??????

					WatchDogIf_Free();
					if(NVM_Handle_DataReadOperate(NVM_Handle_CodeFlashData,(ApplicationAddress + (ProprietaryLin_App_Package * UPDATE_PACKAGE_SIZE_BYTE)),ProprietaryLin_App_Buf, UPDATE_PACKAGE_SIZE_BYTE)==TRUE)      
					{
						for(Index=0; Index<UPDATE_PACKAGE_SIZE_BYTE; Index++)
						{
							Image_CheckSum += (ProprietaryLin_App_Buf[Index]) & 0xFF;
						}
					}
		            Image_Crc8 = CommCrcCal_crc8((uint8_t*)ProprietaryLin_App_Buf, UPDATE_PACKAGE_SIZE_BYTE, Image_Crc8);
					INT_All_Enable(ENABLE);//??????
					ProprietaryLin_App_Package++;
					ProprietaryLin_App_Index = 0;
					ProprietaryLin_App_Pk_Complete = false;
				}
			}


		}
		else
		{
			// 校验错误，重新请求数据
			ProprietaryLin_App_Index = 0;
			ProprietaryLin_App_Pk_Complete = false;
		}
	}
}
#endif
