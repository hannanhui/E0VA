/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2022)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : NvM_Cfg.h                                                   **
**                                                                            **
**  Created on  : 2025/02/07 16:03:34                                 **
**  Author      : <>                                                          **
**  Vendor      :                                                             **
**  DESCRIPTION : Pre-compile configuration parameter of NvM                  **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
#ifndef NVM_CFG_H
#define NVM_CFG_H
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
#define NVM_CFG_H_AR_MAJOR_VERSION 4U
#define NVM_CFG_H_AR_MINOR_VERSION 5U
#define NVM_CFG_H_AR_PATCH_VERSION 0U
#define NVM_CFG_H_SW_MAJOR_VERSION 2U
#define NVM_CFG_H_SW_MINOR_VERSION 0U
#define NVM_CFG_H_SW_PATCH_VERSION 0U

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define NVM_API_CONFIG_CLASS                            NVM_API_CONFIG_CLASS_3
#define NVM_BSWM_MULTIBLOCK_JOBSTATUS_INFORMATION        STD_OFF
#define NVM_BSWM_SINGLEBLOCK_JOBSTATUS_INFORMATION      STD_OFF
#define NVM_COMPILED_CONFIG_ID                          (0x1u)
#define NVM_CRC_NUM_OF_BYTES                              (0x80u)
#define NVM_DATASET_SELECTION_BITS                      (0x8u)
#define NVM_DEV_ERROR_DETECT                            STD_ON
#define NVM_DRV_MODE_SWITCH                                 STD_OFF
#define NVM_DYNAMIC_CONFIGURATION                         STD_ON
#define NVM_JOB_PRIORITIZATION                            STD_OFF
#define NVM_POLLING_MODE                                STD_OFF
#define NVM_REPEAT_MIRROR_OPERATIONS                      (0x3u)
#define NVM_SET_RAM_BLOCK_STATUS_API                    STD_OFF
#define NVM_SIZE_IMMEDIATE_JOB_QUEUE                    (0x0u)
#define NVM_SIZE_STANDARD_JOB_QUEUE                        (0xau)
#define NVM_VERSION_INFO_API                            STD_OFF
#define NVM_INCLUDE_CRC                                 STD_ON
#define NVM_CRC_TYPE_8                                  STD_OFF
#define NVM_CRC_TYPE_16                                 STD_ON
#define NVM_CRC_TYPE_32                                 STD_OFF
#define NVM_DEM_PRODUCTION_ERROR_DETECT                    STD_OFF

/*The following definitions used to index NVM block for SW */
#define NvMBlock1_DID               2U
#define NvMBlock2_FAC               3U
#define NvMBlock3_Timer               4U
#define NvMBlock4_DTC_4000               5U
#define NvMBlock5_DTC_300               6U
#define NvMBlock6_NM_50               7U
#define NvMBlock_UserData0_420               8U

/*The total number of user configured*/
#define NVM_BLOCK_NUM_ALL                                 8
#define NVM_REDUNDANT_ALL                                  1

#define NVM_MAX_LENGTH_CONFIGED_RAM_MIRROR                0U

#define NVM_MAX_LENGTH_NV_BLOCK                            4000U
#define NVM_MAX_LENGTH_REDUNDANT_BLOCK                    2U

#if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON == NVM_JOB_PRIORITIZATION))
/*The total number of different priority*/
#define NVM_TOTAL_NUM_DIFF_PRI                             NVM_TABLE_SIZE_PRIORITY
#endif

#if (STD_ON==NVM_JOB_PRIORITIZATION)
/* The priority table size*/
#define NVM_TABLE_SIZE_PRIORITY                          2U
#endif

extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer1[2];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer2[1];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer3[1];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer4[2];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer5[4000];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer6[300];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer7[50];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer8[420];

#define NVM_READ_O_WRITE_USERDATA        NvMBlockRamBuffer8

#endif /* End of NVM_CFG_H*/
/*******************************************************************************
**                           End Of File                                      **
*******************************************************************************/

