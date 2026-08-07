/***************************************************************************//**
 * @file     ee_middlelevel.h
 * @brief    EEPROM emulation middle level header file.
 * @version  V1.3
 * @date     May-2021
 * @author   Zhixin Semiconductor
 *
 * @note
 * Copyright (C) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 * 
 ******************************************************************************/
#ifndef EE_MIDDLELEVEL_H
#define EE_MIDDLELEVEL_H

#include "eep_emulation.h"

#define EE_CACHE_ITEM_SIZE     4U

#define EE_RECORD_ADDR_DELETED   0xFFFFFFFEU
#define EE_RECORD_ADDR_EMPTY     0xFFFFFFFFU


#define EE_ERASED_WORD         0xFFFFFFFFU

#define EE_VALID_PATTERN_SIZE_IN_BYTE        EE_FL_PHRASE_SIZE
#define EE_INVALID_PATTERN_SIZE_IN_BYTE      EE_FL_PHRASE_SIZE

#define EE_VALID_PATTERN_SIZE_IN_WORD       (EE_VALID_PATTERN_SIZE_IN_BYTE >> 2U)
#define EE_INVALID_PATTERN_SIZE_IN_WORD     (EE_INVALID_PATTERN_SIZE_IN_BYTE >> 2U)

extern const uint32_t validPattern[EE_VALID_PATTERN_SIZE_IN_WORD];
extern const uint32_t invalidPattern[EE_INVALID_PATTERN_SIZE_IN_WORD];

void HalfwordToBytes(uint16_t src, uint8_t *dest);
void WordToBytes(uint32_t src, uint8_t *dest);
void EE_UpdateCacheTable(EE_cache_t* cTable, uint16_t recordID, 
                                   uint32_t newValue);
uint32_t EE_SearchInCache(EE_cache_t* cTable, uint16_t recordID, 
                          uint32_t* recAddr);
uint32_t EE_ReadRecordAtAddr(uint32_t recordAddr, uint16_t dataSize, 
                             uint8_t *buf, uint16_t *readSize, 
                             void (*CallBack)(void));
uint32_t EE_SearchInSectors(EE_Config_t* eeConfig, uint16_t recordID, 
                            uint32_t* recordAddr, void (*CallBack) (void));
uint32_t EE_ValidateRecord(uint32_t recordAddr, void (*CallBack)(void));
uint32_t EE_InvalidateRecord(uint32_t recordAddr, void (*CallBack)(void));
uint32_t EE_WriteRecordInSector(EE_SectorInfo_t *secInfo, uint16_t recordID, 
                                uint16_t size, const uint8_t *src, uint32_t srcInFlash,
                                void (*CallBack)(void));
uint16_t EE_AlignToPhraseSize(uint16_t size);
uint32_t EE_ReadSectorHeader(uint32_t addr, EE_SectorHeader_t * head, 
                             void (*CallBack)(void));
uint32_t EE_ReadRecordHeader(uint32_t addr, EE_RecordHeader_t * head,
                             void (*CallBack)(void));
uint32_t EE_ValidateSector(const EE_SectorConfig_t *pSector, 
                           void (*CallBack)(void));
uint32_t EE_InvalidateSector(const EE_SectorConfig_t *pSector, 
                             void (*CallBack)(void));
uint32_t EE_EmptySector(const EE_SectorConfig_t* pSector, void (*CallBack)(void));
uint32_t EE_FormatSector(const EE_SectorConfig_t* pSector, uint32_t id, 
                         void (*CallBack) (void));
uint32_t EE_ScanSector(EE_Config_t* eeConfig, ControlState_t swapEn, 
                       void (*CallBack)(void));

uint32_t EE_CheckSectorSpaceForRecord(EE_SectorInfo_t* secInfo, 
                                      uint16_t dataSize);
uint32_t EE_SectorSwap(EE_Config_t* eeConfig, void (*CallBack)(void));


#endif