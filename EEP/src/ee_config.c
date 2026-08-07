/***************************************************************************//**
 * @file     ee_config.c
 * @brief    EEPROM emulation config source file.
 * @version  V1.2
 * @date     May-2025
 * @author   Zhixin Semiconductor
 *
 * @note
 * Copyright (C) 2021 Zhixin Semiconductor Ltd. All rights reserved.
 * 
 ******************************************************************************/
#include "ee_config.h"
#include "eep_emulation.h"

/* cache configuration */
static uint32_t cacheTable[EE_CACHE_RECORD_NUM];
static EE_cache_t cacheConf =
{
    cacheTable,               /* cache start address */
    EE_CACHE_RECORD_NUM       /* cache size */
};

/* sector 0 configuration */
static const EE_SectorConfig_t sectorConf0 =
{
    EE_SECTOR_0_ADDR,          /* the start address */
    EE_SECTOR_SIZE,            /* the size */
};

/* sector 1 configuration */
static const EE_SectorConfig_t sectorConf1 =
{
    EE_SECTOR_1_ADDR,          /* the start address */
    EE_SECTOR_SIZE,            /* the size */
};

/* sector configuration array */
static const EE_SectorConfig_t* sectorConfig[EE_SECTOR_NUM] =
{
    &sectorConf0,
    &sectorConf1, 
};

/* EEPROM configuration */
EE_Config_t eeConf =
{
    .sectorNum = EE_SECTOR_NUM,  /* the number of sectors being used emulation */
    .sectors = sectorConfig,     /* the configuration of sectors */
    .cacheEn = ENABLE,           /* enable cache */
    .cTable = &cacheConf,        /* the cache config */
    .busyFlag = RESET,
    .maxRecordId = EE_MAX_RECORD_ID,         /* the max record ID */
};

void CallBack(void)
{
    
}

void ErrorTrap(void)
{
//    while(true)
//    {
        CallBack();
//    }
}