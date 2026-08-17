/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Fls_LCfg.c
 *  @Syntax             : GNU99
 *  @Author             : ChipON AE/FAE Group
 *  @Date            : 2021-12-23
 *  @Version         : {{VersionDate}}
 *  @Description     : This document describes the C language document template.
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 *****************************************************************************/

/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "Fls_LCfg.h"
#include "__driver_Flash_API.h"

/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/

/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/

/******************************************************************************
 **                        Export Variables
 ******************************************************************************/

/******************************************************************************
 **                        Export Functions
 ******************************************************************************/

/******************************************************************************
 **                      Constant Declarations
 ******************************************************************************/
/**
 * @brief flash config information
 *
 * @details Page Size 16Byte;Sector Size 2048Byte
 */
CONST(Fls_ConfigType, FLS_CONST)
Fls_ConfigPredefined = {
  /** @brief pointer to erase function */
  .EraseProcessPtr = (Fls_ErasePtrType)&__FLASH_Erase__,
  /** @brief pointer to write page function */
  .WritePageProcessPtr = (Fls_WritePtrType)&__FLASH_Program_NBytes__,
  /** @brief pointer to write sector function */
  .WriteSectorProcessPtr = (Fls_WritePtrType)&__FLASH_Program__,
  /** @brief function pointer for JobEndNotification */
  .JobEndNotificationPtr = NULL_PTR,
  /** @brief function pointer for JobErrorNotification */
  .JobErrorNotificationPtr = NULL_PTR,
  /** @brief function pointer for StartFlashAccessNotification */
  .StartFlashAccessNotificationPtr = NULL_PTR,
  /** @brief function pointer for FinishedFlashAccessNotification */
  .FinishedFlashAccessNotificationPtr = NULL_PTR,
  /** @brief function pointer for feed dog */
  .FeedDogProcessPtr = NULL_PTR,
  /** @brief default fls device mode */
  .DefaultMode = MEMIF_MODE_SLOW,
  /** @brief fast read size */
  .ReadFastSize = FLASH_TOTAL_SIZE,
  /** @brief fast write size */
  .WriteFastSize = FLASH_FAST_WRITE_MAX_SIZE,
  /** @brief normal read size */
  .ReadNormalSize = FLASH_SECTOR_SIZE,
  /** @brief normal read size */
  .WriteNormalSize = FLASH_PAGE_SIZE,
  /** @brief physical start address */
  .PhysicalStartAddr = FLASH_BASE_ADDR,
  /** @brief flash total size */
  .FlashTotalSize = FLASH_TOTAL_SIZE,
};

/******************************************************************************
**                     Variable Declarations
******************************************************************************/
