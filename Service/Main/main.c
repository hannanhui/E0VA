/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      main.c                                                                   */
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

#define GLOBALS_MAIN

/******************************************************************************
**                              Include Files
******************************************************************************/
#include "include.h"
#include "Dcm.h"
#include "LinIf.h"
#include "BM.h"
#include "FBL.h"
#include "lin_driver.h"
#include "Dcm_Internal.h"
#include "aes128.h"
#include "trng.h"
#include "eep_emulation.h"
volatile const static  uint8_t SwVer[VERSION_INFO_MAX_SIZE] __attribute__((section(".ARM.__at_0x00000400"),used)) ={MCU_CUSTOMER_MAIN_VERSION};
volatile const static  uint8_t CfgSwVer[VERSION_INFO_MAX_SIZE] __attribute__((section(".ARM.__at_0x00000430"),used)) ={MCU_CONFIG_MAIN_VERSION};
//volatile uint32 g_boot_flag __attribute__((at(0x20007990)));
__attribute__((section(".Boot_Flag_Section"),no_init)) volatile uint32 g_boot_flag ;
extern volatile uint8 Dcm_Send_1002;

uint8 APP_Jump;
/**
 *  @brief : Reports the name of the source file and the source line number
 *           where the assert_param error has occurred.
 *  @param[in]  file pointer to the source file name
 *  @param[in]  line assert_param error line source number
 *  @param[out] None
 *  @retval :None
 */
void check_failed(uint8_t *File, uint32_t Line)
{
    /* User can add his own implementation to report the file name and line number,
        ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

    /* Infinite loop */
    while (1)
    {
        ;
    }
};


NVM_Handle_Run_AreaDef  run_Area = NVM_Handle_Run_At_Boot;

lin_user_config_t lin_InitConfig = {
    .baudRate = 19200U,
    .nodeFunction = (bool)SLAVE,
    .autobaudEnable = false,
    .classicPID = NULL,
    .numOfClassicPID = 0U,
};

uint8 linRxBuf[8] = {};
uint8 linTxBuf[8] = {};
	
lin_state_t linState = {
	.txBuff = linTxBuf,
	.rxBuff = linRxBuf
};


/*******************************************************************************
**                                 main Functions
*******************************************************************************/

volatile uint32 time=0;
int main()
{
	System_Init();
	FLASH_Init();

	/* Belt-and-suspenders: ensure FLS-driver RAM has valid ECC before any
	 * UDS 0x36 write/CRC. Startup also clears 0x20007B00..0x20007F03. */
	{
		volatile uint32 *p = (volatile uint32 *)0x20007B00u;
		uint32 i;
		for (i = 0u; i < (0x400u / 4u); i++)
		{
			p[i] = 0u;
		}
		g_boot_flag = 0u;
	}

	EE_Init(&eeConf, ENABLE, &CallBack);

	BM_InitEcu();
	BM_CheckEcuDownload();

	WatchDogIf_Free();
	WatchDogIf_Disable();
	PORTIF_LIN_HE_DRV_SLP_EN_INIT();
	LinIf_Init(&LinIf_Config);
	LinTp_Init(&LinTp_Config);
	Dcm_Init(&Dcm_Config);
	LinIf_Wakeup(0);
	
	Trng_Init();
	LIN_DRV_Init(0,&lin_InitConfig,&linState);
	LIN_DRV_InstallCallback(0,LIN_DRV_NotifyLinIf);

	if(APP_Jump == 0x01) /* reply 50 02 after APP->Boot jump (TX done in LIN PID callback) */
	{
		Dcm_Send_1002 = 0;
		while(Dcm_Send_1002 != 1)
		{
			time++;
		}
		/* 50 02 already transmitted on first SRF(0x3D) in LIN_DRV_NotifyLinIf */
		Dcm_NewActiveSession = DCM_PROGRAMMING_SESSION;
		Dcm_NewActiveSessionIdx = 1;
		Dcm_ProtocolStartState = 1;
		DslInternal_SetSesCtrlType(Dcm_NewActiveSession);
	}
	
	while(1)
	{
		SystemTickIf_MainWhileCallHandler();
	}
}


