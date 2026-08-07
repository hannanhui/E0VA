/***************************************************************************//**
 * @file     ee_config.h
 * @brief    EEPROM emulation config header file.
 * @version  V1.2
 * @date     May-2025
 * @author   Zhixin Semiconductor
 *
 * @note
 * Copyright (C) 2025 Zhixin Semiconductor Ltd. All rights reserved..
 * 
 ******************************************************************************/
#ifndef EE_CONFIG_H
#define EE_CONFIG_H

#define Z20K11X_SDK     1U
#define Z20K14X_SDK     2U

#define Z20K1XX_SDK       Z20K14X_SDK

#define EE_BASE_ADDR      0x01000000      

#define EE_SECTOR_NUM           2U
#define EE_SECTOR_SIZE          EE_FL_SECTOR_SIZE 
#define EE_SECTOR_0_ADDR        (EE_BASE_ADDR)
#define EE_SECTOR_1_ADDR        (EE_SECTOR_0_ADDR + EE_SECTOR_SIZE)

#define EE_MAX_RECORD_ID          0x20U
#define EE_CACHE_RECORD_NUM       (EE_MAX_RECORD_ID + 1U)

//需要的信息
#define EE_BLOCK_Finger_F184          0
#define EE_BLOCK_FINGER_AppValFlag    1
#define EE_UpdataTriedCounter         2
#define EE_DependecyCheckSeccessCounter   3



extern void CallBack(void);
extern void ErrorTrap(void);

#endif