/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      ProprietaryLin_App.c                                                     */
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

#define VERSION_MAJOR				0	// ���汾��

#define VERSION_REQ_NONE			0	// �ް汾����
#define VERSION_REQ_BOOT_MAJOR		1	// Boot���汾����
#define VERSION_REQ_BOOT_MINOR		2	// Boot�ΰ汾����
#define VERSION_REQ_APP_MAJOR		3	// App���汾����
#define VERSION_REQ_APP_MINOR		4	// App�ΰ汾����

static uint8_t ProprietaryLin_App_Update_Req = 0U;	
uint8_t  Version_Req;						// �汾��Ϣ����
uint8_t  Version_Package_Index;			// �汾��Ϣ�ְ�
// ���õ�ǰ������ģʽ  Boot/App

const BOOT_APP_MODE Run_Mode = APP_MODE;


/*******************************************************************************
*������     ��LIN_App_Update_Init
*��������  	��LIN ������ʼ��
*��������   ����
*��������ֵ	����
*˵��		����
*******************************************************************************/
void ProprietaryLin_App_Init(void)
{
	ProprietaryLin_App_Update_Req = FALSE;
	Version_Req = VERSION_REQ_NONE;
	Version_Package_Index = 0;

	
}




void ProprietaryLin_App_VersionRespond(volatile uint8_t *i_pDataBuf)
{
	uint8_t* pVer = NULL;
	uint8_t  Ver_Index=0;
	uint8_t  Temp;
	uint8_t  i;
	BOOL   End;
	// ��ȡ�汾��Ϣ
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
		// ���Ͱ汾��Ϣ
		i_pDataBuf[0] = Run_Mode;	// App ģʽ
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
		i_pDataBuf[0] = Run_Mode;	// App ģʽ
		for (i=1; i< 8; i++)
		{
			i_pDataBuf[i] = 0;
		}
	}

}

void ProprietaryLin_DriverWriteDataInProprietaryLin(volatile uint8_t *i_pDataBuf)
{
	if (i_pDataBuf[0] == 0xFF)
	{
		// �������
		if (i_pDataBuf[1] == 0)
		{
			// ��������Bootģʽ��Ч��Bootģʽ�յ�������ʱ˵���������ݷ�����ɣ���ת��App��
		}
		// ��������
		else if (i_pDataBuf[1] == 1)
		{
			if ((i_pDataBuf[2] == 0x5A) &&
				(i_pDataBuf[3] == 0xA5) &&
				(i_pDataBuf[4] == 0x69) &&
				(i_pDataBuf[5] == 0x96) )
			{
				ProprietaryLin_App_Update_Req = TRUE;
			}
		}
		// ��ȡ��ǰģʽ�汾��Ϣ
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
		// ��ȡ����ģʽ�汾��Ϣ(AppʱΪBoot��BootʱΪApp)
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
	}
}

void ProprietaryLin_MainFun(void)
{

	// ��������
	if (ProprietaryLin_App_Update_Req)
	{
		// д��ɹ�
		if (NVM_Handle_RunAreaSet(NVM_Handle_Run_At_Boot))
		{
			// 复位，复位后自动跳转Boot
			System_ResetDelayTimeSet(T10_100MS);
			System_SwResetFlagSet(TRUE);
			//增加延时复位，保证升级标志写入
		}
		ProprietaryLin_App_Update_Req =0u;
		
	}

}	


