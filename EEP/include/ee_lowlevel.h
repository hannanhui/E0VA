/***************************************************************************//**
 * @file     ee_lowlevel.h
 * @brief    EEPROM emulation low level header file.
 * @version  V1.3
 * @date     May-2021
 * @author   Zhixin Semiconductor
 *
 * @note
 * Copyright (C) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 * 
 ******************************************************************************/
#ifndef EE_LOWLEVEL_H
#define EE_LOWLEVEL_H


uint32_t EE_FlashReadHalfWord(uint32_t addr, uint16_t * halfWord);
uint32_t EE_FlashReadWord(uint32_t addr, uint32_t * word);
uint32_t EE_FlashRead(uint32_t addr, uint8_t * buffer, uint32_t size,void (*CallBack)(void));
uint32_t EE_FlashReadByWord(uint32_t addr, uint32_t *buffer, uint32_t size,
                            void (*CallBack)(void));

uint32_t EE_FlashBlankCheck(uint32_t addr, uint32_t size, 
                            FlagStatus_t *blankFlag, void (*CallBack)(void));
uint32_t EE_DataCheck(uint32_t addr, const uint8_t *buf, uint32_t len,
                      FlagStatus_t *flag, void (*CallBack)(void));

uint32_t EE_FlashWriteWithPadding(uint32_t srcAddr, uint32_t len, 
                                  uint32_t srcInFlash, uint32_t addr, 
                                  void (*CallBack)(void));

uint32_t EE_SectorErase(uint32_t addr, uint32_t size, void (*CallBack)(void));
FlagStatus_t EE_SramCheckByWord(uint32_t *buf, uint32_t size, uint32_t value);
#endif