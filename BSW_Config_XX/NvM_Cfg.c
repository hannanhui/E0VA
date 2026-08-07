
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
**  FILENAME    : NvM_Cfg.c                                                   **
**                                                                            **
**  Created on  : 2025/02/07 16:03:34                                 **
**  Author      : <>                                                          **
**  Vendor      :                                                             **
**  DESCRIPTION : Post-build configuration parameter of NvM                   **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/ 
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "NvM_Types.h"
#include "NvM_Cfg.h"

#include "Rte_Dem.h"
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
#define NVM_CFG_C_AR_MAJOR_VERSION 4U
#define NVM_CFG_C_AR_MINOR_VERSION 5U
#define NVM_CFG_C_AR_PATCH_VERSION 0U
#define NVM_CFG_C_SW_MAJOR_VERSION 2U
#define NVM_CFG_C_SW_MINOR_VERSION 0U
#define NVM_CFG_C_SW_PATCH_VERSION 0U

/********************************************************
 ****Container for NvmMultiBlockCallback
 ********************************************************/
#define NVM_START_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"
CONST(NvM_MultiBlockCallbackType, NVM_CONST) NvmMultiBlockCallback = Rte_NvMNotifyJobFinished_MultiBlock;
#define NVM_STOP_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"

#define NVM_START_SEC_VAR_CLEARED_8
#include "NvM_MemMap.h"
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer1[2];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer2[1];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer3[1];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer4[2];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer5[4000];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer6[300];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer7[50];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer8[420];
#define NVM_STOP_SEC_VAR_CLEARED_8
#include "NvM_MemMap.h"

/********************************************************
 ****Container for a management structure to configure the
composition of a given NVRAM Block Management Type.
 ********************************************************/
#define NVM_START_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"
CONST(NvM_BlockDescriptorType, NVM_CONST) NvM_BlockDescriptor[NVM_BLOCK_NUM_ALL] =
{
    /*NvMBlock_ConfigID*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_REDUNDANT,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x3c,
       /*
        * Bit 0:NvmWriteBlockOnce
        * Bit 1:NvmBlockWriteProt
        * Bit 2:NvmCalcRamBlockCrc
        * Bit 3:NvmResistantToChangedSw
        * Bit 4:NvmSelectBlockForReadall
        * Bit 5:NvmSelectBlockForWriteall
        * Bit 6:NvMStaticBlockIDCheck
        * Bit 7:NvMWriteVerification
        * Bit 8:NvMBlockUseAutoValidation
        * Bit 9:NvMBlockUseCRCCompMechanism
        * Bit 10:NvMBlockUseSetRamBlockStatus
        * Bit 11:NvMBlockUseSyncMechanism
        * Bit 12:NvMBswMBlockStatusInformation
        */
        NVM_CRC16,    /*NvmBlockCRCType*/
        1,    /*NvmNvBlockBaseNumber*/
        2,    /*NvmNvBlockLength*/
        2,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer1),    /*NvmRamBlockDataAddress*/
        NULL_PTR,   /*NvmRomBlockDataAddress*/
        NULL_PTR,   /*NvmInitBlockCallback*/
        NULL_PTR,   /*NvmSingleBlockCallback*/
        NULL_PTR,   /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,   /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock1_DID*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        2,    /*NvmNvBlockBaseNumber*/
        1,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer2),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock2_FAC*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        3,    /*NvmNvBlockBaseNumber*/
        1,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer3),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock3_Timer*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        4,    /*NvmNvBlockBaseNumber*/
        2,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer4),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock4_DTC_4000*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        5,    /*NvmNvBlockBaseNumber*/
        4000,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer5),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock5_DTC_300*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        6,    /*NvmNvBlockBaseNumber*/
        300,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer6),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock6_NM_50*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        7,    /*NvmNvBlockBaseNumber*/
        50,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer7),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_UserData0_420*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        8,    /*NvmNvBlockBaseNumber*/
        420,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer8),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
};
#define NVM_STOP_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"

#if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
#define NVM_START_SEC_VAR_POWER_ON_INIT_16
#include "NvM_MemMap.h"
VAR(uint16, NVM_VAR_POWER_ON_INIT) NvM_PriorityTable[2][NVM_TABLE_SIZE_PRIORITY] =
{

    {
        0x0000U,0x0000U
    },
    {
        0x0000U,0x0000U
    }
};
#define NVM_STOP_SEC_VAR_POWER_ON_INIT_16
#include "NvM_MemMap.h"
#endif
/*******************************************************************************
**                           End Of File                                      **
*******************************************************************************/

