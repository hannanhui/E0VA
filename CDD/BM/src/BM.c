/**
 * @file        BM.c
 * @brief       AUTOSAR BM  - BM driver source file.
 * @details     BM driver source file, containing the C implementation of Autosar API specification
 *              and other variables and functions that are exported by the BM driver.
 * @version     1.0.0
 *
 * @addtogroup  BM
 * @{
 */
/*====================================================================================================*
 * AngHui AUTOSAR BSW.
 *
 * Copyright(C) 2025 GuoKeAngHui Inc.
 *
 * All rights reserved.
 *
 * This file is part of AngHui AUTOSAR BSW, contains proprietary information.
 * Passing on and copying of this document, and communication of its contents
 * is not permitted without prior written authorization.
 *====================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/

#include "SecM.h"
#include "BM.h"
#include "Supplement.h"
#include "common_drv.h"
#include "eep_emulation.h"
#include <string.h>

//#include "Dcm_Cfg.h"

#if(STD_ON==BM_USE_USPR_REGISTER)
//#include "compiler_api.h"
#endif

/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION
 *====================================================================================================*/

/**
* @brief Parameters that shall be published within the BM driver header file and also in the
*        module's description file
*/
#define BM_VENDOR_ID_C                    xx
#define BM_AR_RELEASE_MAJOR_VERSION_C     xx
#define BM_AR_RELEASE_MINOR_VERSION_C     xx
#define BM_AR_RELEASE_REVISION_VERSION_C  xx
#define BM_SW_MAJOR_VERSION_C             xx
#define BM_SW_MINOR_VERSION_C             xx
#define BM_SW_PATCH_VERSION_C             xx

#define STATIC static

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                   EXTERNAL FUNCTION DECLARATIONS
 *====================================================================================================*/



/*====================================================================================================*
 *                                           LOCAL TYPEDEFS
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                            LOCAL MACROS
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                           LOCAL CONSTANTS
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                           LOCAL VARIABLES
 *====================================================================================================*/

STATIC VAR(boolean,AUTOMATIC) BM_BootJumpAPP = (boolean)FALSE;

/*====================================================================================================*
 *                                      LOCAL FUNCTION PROTOTYPES
 *====================================================================================================*/

STATIC FUNC(boolean,AUTOMATIC) BM_GetAppValFlag(void);
STATIC FUNC(void,AUTOMATIC) BM_RAMDeInit(void);
uint32 appValFlagData = 0;
uint8 Read_Actual_Lengh;


/*====================================================================================================*
 *                                           LOCAL FUNCTIONS
 *====================================================================================================*/

/**
 * @brief              Check the flag bit for boot mode
 * @param[in]      	   None
 * @param[out]     	   None
 * @return             boolean
 */

extern uint32 g_boot_flag;
STATIC FUNC(boolean,AUTOMATIC) BM_GetAppValFlag(void)
{
	/*PXC*/

	VAR(boolean,AUTOMATIC) appValFlag = FALSE;

	appValFlagData = 0U;
	/* Read only — do NOT EE_DeleteRecord on every boot. Delete writes an
	 * invalidation marker and fills DFlash until sector swap hangs. Flag
	 * is cleared once in BM_CheckEcuDownload when upgrade is consumed. */
	(void)EE_ReadRecord(&eeConf,EE_BLOCK_FINGER_AppValFlag,4,(uint8 *)&appValFlagData,&Read_Actual_Lengh,NULL);//读升级标志位

	if(appValFlagData == 0x95279527)//判断升级标志位
	{
		appValFlag = TRUE;//升级
	}
	else
	{
		//nothing
	}
	return appValFlag;

}

/**
 * @brief              Clear the data in the ram area
 * @param[in]      	   None
 * @param[out]     	   None
 * @return             None
 */
STATIC FUNC(void,AUTOMATIC) BM_RAMDeInit(void)
{
	VAR(FBL_LengthType,AUTOMATIC) u32Length;
	volatile uint32 *pWord;

	/* Word clear — required for Z20K SRAM ECC at FLASH_DRIVE_ADDRESS. */
	pWord = (volatile uint32 *)FLASH_DRIVE_ADDRESS;
	u32Length = (uint32)FLASH_DRIVE_LENGTH / 4u;

	while (u32Length > 0u)
	{
		*pWord = 0u;
		pWord++;
		u32Length--;
	}
}


/*====================================================================================================*
 *                                          GLOBAL FUNCTIONS
 *====================================================================================================*/

/**
 * @brief              ECU initialize.
 * @details			   This routine shall be called by the boot code contained in the flash loader to initialize common hardware.
 * @param[in]      	   None
 * @param[out]     	   None
 * @return             None
 */

FUNC(void,AUTOMATIC) BM_InitEcu(void)
{

    FBL_Init();
    /*Wdg_Swt_Init();*/
}

/**
 * @brief              ECU DeInit.
 * @details			   This routine shall be called by the flashloader to reset the ECU upon request from the external programming device.
 * @param[in]      	   None
 * @param[out]     	   None
 * @return             None
 */
FUNC(void,AUTOMATIC) BM_DeInit(void)
{
	volatile uint16 i;
	for (i = 0; i < 10000; i++)
	{
		
	}
	BM_RAMDeInit();
	COMMON_SystemReset();

}

/**
 * @brief              ECU check download.
 * @details			   Check if there is a programming sign, when there is no programming sign,
 * check the validity of the programming information in the eeprom and the effectiveness of the app,
 *  when the app works, enter the app, otherwise it will be downloaded
 * @param[in]      	   None
 * @param[out]     	   None
 * @return             None
 */
uint8 FlashReadByte(uint32 globalAddr)
{
    uint8 readData = 0;

    readData = *(uint8*)globalAddr;

    return readData;
}
void FlashReadMemory(uint8* DataBuf,uint32 Addr, uint32 Length)
{
    while(Length > 0)
    {
        *DataBuf = FlashReadByte(Addr);
        Addr++;
        DataBuf++;
        Length--;
    }
}


FUNC(void,AUTOMATIC) BM_CheckEcuDownload(void)
{
	uint8 AppValFlag;

	AppValFlag = BM_GetAppValFlag();

	if(AppValFlag == (uint8)FALSE)
	{
		memcpy((BM_EepromDataType*)&FBL_AppProgramInfo, (uint8*)FBL_EEPROM_INFO_ADDRESS,
			    (BM_U32DataType)sizeof(FBL_AppProgramInfoType));

		if(FBL_AppProgramInfo.FBL_AppStatus.AppValid == (uint8)TRUE)
		{
				BM_BootJumpAPP = (uint8)TRUE;
				BM_EnterApp();
		}
	
	}
	else //升级
	{
		APP_Jump = 0x01;
		appValFlagData = 0;
		EE_WriteRecord(&eeConf,EE_BLOCK_FINGER_AppValFlag,4,(const uint8 *)&appValFlagData,0,NULL);//清除升级标志位
	}

}

void IAP_SetVectorTable(uint32_t VectTab)
{
	 INT_SetVector(0,VectTab);
}
/**
 * @brief              ECU Enter App.
 * @details			   Enter the app application from boot, and then initialize the drive module
 * @param[in]      	   None
 * @param[out]     	   None
 * @return             None
 */
FUNC(void,AUTOMATIC) BM_EnterApp(void)
{
		if(BM_BootJumpAPP == (boolean)TRUE)
		{
			INT_All_Enable(FALSE);                     				
			INT_DisableIRQ(STIM_IRQn);
			INT_DisableIRQ(WDOG_IRQn);
			IAP_SetVectorTable(FBL_BM_SOFTWARE_ADDR);
			(*(void (*)(void))(*(uint32*)(FBL_BM_SOFTWARE_ADDR + 0x4uL)))();
			INT_All_Enable(TRUE);
		}
}


#ifdef __cplusplus
}
#endif
/** @} */
