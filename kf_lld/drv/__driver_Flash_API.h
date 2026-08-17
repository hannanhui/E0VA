/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name        : __driver_Flash_API.h
 *  @Syntax           : GNU99
 *  @Author           : ChipON AE/FAE Group
 *  @Date             : 24-06-29
 *  @Version          : V2.0
 *  @Description      :
 *****************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 ******************************************************************************
 *                              REVISION HISTORY
 ******************************************************************************
 *  |Date         |Version  |Author          |Description
 ******************************************************************************
 *  |2023-6-29    |V1.0     |Li Yuansheng    |New API of flash for A02
 *****************************************************************************/

#ifndef DRIVER_FLASH_OP_API_HEAD_H_
#define DRIVER_FLASH_OP_API_HEAD_H_
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ user config 1

#include <stdint.h>

/**
 * @brief Structure of flash key
 *
 */
/* PRQA S 3205 ++ #KQR003205 */
typedef struct
{
    /** @brief Soft KEY 1 */
    uint32_t SoftKey1;
    /** @brief Flash KEY 1 */
    uint32_t FlashKey1;
    /** @brief Flash KEY 2 */
    uint32_t FlashKey2;
    /** @brief Soft KEY 2 */
    uint32_t SoftKey2;
} Flash_Key_t;
/* PRQA S 3205 -- #KQR003205 */

/**
 * @brief Return value of flash command
 */
#define CMD_SUCCESS 0x00U
#define CMD_ERROR   0xAAU
#define PARAM_ERROR 0x0CU

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/* PRQA S 1753 ++ #KQR001753 */
uint32_t __FLASH_Erase__(volatile const uint32_t *const KeyPtr, volatile uint32_t WriteAddr);
uint32_t __FLASH_Program__(volatile const uint32_t *const KeyPtr, uint32_t WriteAddr, const uint32_t *const WriteData);
uint32_t
__FLASH_Program_NBytes__(volatile const uint32_t *const KeyPtr, uint32_t WriteAddr, const uint32_t *const WriteData);
/* PRQA S 1753 -- #KQR001753 */

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ user config 1
#endif /* DRIVER_FLASH_OP_API_HEAD_H_ */
