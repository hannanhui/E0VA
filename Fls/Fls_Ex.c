/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Fls_Ex.c
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2025-08-29
 *  @Version         : V1.0.0_SF
 *  @Description     : This document describes the C language document template.
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 ******************************************************************************
 *                        REVISION HISTORY
 ******************************************************************************
 *  |Date        |Version  |Author       |Description
 ******************************************************************************
 *  |2025-08-29  |V1.0     |Wang Ning    |New creat
 *****************************************************************************/

/******************************************************************************
 **                        MISRA-C Rules Violations
 ******************************************************************************/
/**
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section
 */

/******************************************************************************
 **                        QAC Warnings
 ******************************************************************************/
/**
 * @page QAC Warnings
 *
 */
/* PRQA S 3473 EOF #KQR003473 */
/* PRQA S 0303 EOF #KQR000303 */
/* PRQA S 0310 EOF #KQR000310 */
/* PRQA S 0312 EOF #KQR000312 */
/* PRQA S 4397 EOF #KQR004397 */
/* PRQA S 3200 EOF #KQR003200 */
/* PRQA S 1881 EOF #KQR001881 */
/* PRQA S 0306 EOF #KQR000306 */
/* PRQA S 2814 EOF #KQR002814 */
/* PRQA S 2824 EOF #KQR002824 */
/* PRQA S 2844 EOF #KQR002844 */
/* PRQA S 2201 EOF #KQR002201 */
/* PRQA S 3383 EOF #KQR003383 */
/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "Fls_Ex.h"
#include "__driver_Flash_API.h"
#include "kf32a158sf_drv_intr.h"
#include "kf32a158sf_drv_flash.h"
/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/
#ifndef FLS_FEATURE_AB_SWAP_ENABLE
#define FLS_FEATURE_AB_SWAP_ENABLE (STD_OFF)
#endif

/**
 * @brief flash key
 */
#define FLS_OPERATE_KEY (0x5A5A6688U)

#if (FLS_DFLASH_FUNCTION_ENABLE == STD_ON)
/**
 * @brief DFlash key
 */
#define FLS_DFLASH_KEY1 (0x77664CDEU)
#define FLS_DFLASH_KEY2 (0x82070612U)
#endif

#if (FLS_PFLASH_FUNCTION_ENABLE == STD_ON)
/**
 * @brief PFlash key
 *
 * @note Only can operate on PFlash B (512KB ~ 992KB).
 */
#if (FLS_FEATURE_AB_SWAP_ENABLE == STD_ON)
#define FLS_PFLASH_KEY1 (0x29133476U)
#define FLS_PFLASH_KEY2 (0x1793526BU)
#else
#define FLS_PFLASH_KEY1 (0x2895D3DEU)
#define FLS_PFLASH_KEY2 (0x81060711U)
#endif
#endif

/**
 * @brief fast mode fls Fls_MainFunction once write max size
 *
 * @note can not changed
 */
#define FLASH_EX_WRITE_MAX_SIZE (0x200U)

/**
 * @brief page size
 *
 * @note can not changed
 */
#define FLASH_EX_PAGE_SIZE (8U)

/**
 * @brief fast erase sector size
 *
 * @note can not changed
 */
#define FLASH_EX_ERASE_SIZE (0x400U)

/**
 * @brief flash max 2M+32K
 */
#define FLASH_MAX_ADDR (0x208000U)

/**
 * @brief DFlash base
 */
#define FLASH_EX_D_FLASH_BASE_ADDR (0x200000U)

/**
 * @brief Maximum PFlash address
 */
#if (FLS_FEATURE_AB_SWAP_ENABLE == STD_ON)
#define FLS_EX_P_FLASH_MAX_ADDRESS (992U << 10U)
#else
#define FLS_EX_P_FLASH_MAX_ADDRESS (960U << 10U)
#endif

/**
 * @brief write address and write length mask
 */
#define FLASH_ADDR_AND_WRITE_LENGTH_MASK (0x07U)

/**
 * @brief byte address alignment mask
 */
#define FLASH_BUF_ALIGN_MASK (0x3U)

/**
 * @brief sector write address should be 1K alignment
 */
#define FLASH_SECTOR_WRITE_MASK (0x1FFU)

/**
 * @brief sector erase size mask
 */
#define FLASH_SECTOR_ERASE_MASK (0x3FFU)
/******************************************************************************
 **                          Local Variables
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
#if ((FLS_FEATURE_AB_SWAP_ENABLE != STD_ON) || (FLS_DFLASH_FUNCTION_ENABLE == STD_ON))
/**
 * @brief flash operate should be enter critical
 *
 * @return void
 * @retval void
 */
static FUNC(void, FLS_CODE) Fls_Ex_SetCritical(CONST(boolean, AUTOMATIC) Status)
{
    static uint32 kvInt_State = 0U;

    /* PRQA S 3344 1 # KQR003344 */
    if (Status)
    {
        /* Disable interrupt */
        kvInt_State             = INTR_PTR->CTL0.bits.AIE;
        INTR_PTR->CTL0.bits.AIE = 0U;
    }
    else
    {
        if (kvInt_State != 0U)
        {
            INTR_PTR->CTL0.bits.AIE = 1U;
        }
        else
        {
            /* Do Nothing */
        }
    }
}
#endif

/**
 * @brief flash extended Reads from flash memory
 *
 * @note
 * 1.Operation less than 2M
 * 2.TargetAddressPtr not NULL_PTR
 *
 * @param SourceAddress Source address in flash memory.flash absolute address
 * @param TargetAddressPtr Pointer to target data buffer
 * @param Length Number of bytes to read
 * @return Std_ReturnType
 * @retval E_NOT_OK
 * @retval E_OK
 */
Std_ReturnType Fls_Ex_Read(const uint32 SourceAddress, uint8 *TargetAddressPtr, const uint32 Length)
{
    Std_ReturnType retVal = (Std_ReturnType)E_OK;

    if (((SourceAddress + Length) > FLASH_MAX_ADDR) ||
        (((SourceAddress + Length) > FLS_EX_P_FLASH_MAX_ADDRESS) &&
         ((SourceAddress + Length) < FLASH_EX_D_FLASH_BASE_ADDR)) ||
        (((SourceAddress) > FLS_EX_P_FLASH_MAX_ADDRESS) && ((SourceAddress) < FLASH_EX_D_FLASH_BASE_ADDR)))
    {
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    else if (TargetAddressPtr == NULL_PTR)
    {
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        uint32 loop;
        for (loop = 0U; loop < Length; loop++)
        {
            TargetAddressPtr[loop] = *(uint8_t *)(SourceAddress + loop);
        }
    }

    return retVal;
}

#if (FLS_PFLASH_FUNCTION_ENABLE == STD_ON)
/**
 * @brief PFlash extended Writes one or more complete flash pages.
 *
 * @note
 * 1.TargetAddress write address 8 Align
 * 2.Length write length 8 Align
 * 3.Operation less than 960K
 *
 * @param TargetAddress Target address in flash memory.flash absolute address
 * @param SourceAddressPtr Pointer to source data buffer
 * @param Length Number of bytes to write
 * @return Std_ReturnType
 * @retval E_NOT_OK
 * @retval E_OK
 */
Std_ReturnType Fls_Ex_PFlashWrite(const uint32 TargetAddress, const uint8 *SourceAddressPtr, const uint32 Length)
{
    Std_ReturnType retVal = (Std_ReturnType)E_OK;

    if (((TargetAddress + Length) > FLS_EX_P_FLASH_MAX_ADDRESS) ||
        (0U != (TargetAddress & FLASH_ADDR_AND_WRITE_LENGTH_MASK)))
    {
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    else if (((Length & FLASH_ADDR_AND_WRITE_LENGTH_MASK) > 0U) || (0U == Length))
    {
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    else if (SourceAddressPtr == NULL_PTR)
    {
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        uint8  loop;
        uint32 cycleRemainToWrite = Length;
        uint32 pageWriteData      = (uint32)SourceAddressPtr;
        uint32 pageWriteAddr      = (uint32)TargetAddress;
        uint32 kvRetVal           = 0U;
        uint8_t __attribute__((aligned(4))) Fls_ExPFlashWrite4AlignedBuffer[FLASH_EX_PAGE_SIZE];
        /* PFlash Key Information */
        volatile Flash_Key_t PFlash_Key = {FLS_OPERATE_KEY, FLS_PFLASH_KEY1, FLS_PFLASH_KEY2, FLS_OPERATE_KEY};
#if (FLS_FEATURE_AB_SWAP_ENABLE != STD_ON)
        /* Enter critical zone */
        Fls_Ex_SetCritical((boolean)TRUE);
#endif
        if (((uint32)SourceAddressPtr & FLASH_BUF_ALIGN_MASK) > 0U)
        {
            while (cycleRemainToWrite != 0U)
            {
                for (loop = 0U; loop < FLASH_EX_PAGE_SIZE; loop++)
                {
                    /* PRQA S 0488 1 #KQR000488  */
                    Fls_ExPFlashWrite4AlignedBuffer[loop] = *((uint8 *)pageWriteData + loop);
                }

                /* PRQA S 3305 3   #KQR003305 */
                kvRetVal = __FLASH_Program_NBytes__(
                  (const uint32_t *const)&PFlash_Key, pageWriteAddr,
                  (const uint32_t *const)Fls_ExPFlashWrite4AlignedBuffer);

                if (kvRetVal != CMD_SUCCESS)
                {
                    retVal = E_NOT_OK;
                    break;
                }
                else
                {
                    /* Do Nothing */
                }

                pageWriteData += FLASH_EX_PAGE_SIZE;
                pageWriteAddr += FLASH_EX_PAGE_SIZE;
                cycleRemainToWrite -= FLASH_EX_PAGE_SIZE;
            }
        }
        else
        {
            if ((0U != (cycleRemainToWrite % FLASH_EX_WRITE_MAX_SIZE)) ||
                ((TargetAddress & FLASH_SECTOR_WRITE_MASK) != 0U))
            {
                while (cycleRemainToWrite != 0U)
                {
                    /* PRQA S 1842 1 # KQR001842 */

                    kvRetVal = __FLASH_Program_NBytes__(
                      (const uint32_t *const)&PFlash_Key, pageWriteAddr, (const uint32_t *const)pageWriteData);

                    if (kvRetVal != CMD_SUCCESS)
                    {
                        retVal = E_NOT_OK;
                        break;
                    }
                    else
                    {
                        /* Do Nothing */
                    }

                    pageWriteData += FLASH_EX_PAGE_SIZE;
                    pageWriteAddr += FLASH_EX_PAGE_SIZE;
                    cycleRemainToWrite -= FLASH_EX_PAGE_SIZE;
                }
            }
            else
            {
                while (cycleRemainToWrite != 0U)
                {
                    /* PRQA S 1842 1 # KQR001842 */

                    kvRetVal = __FLASH_Program__(
                      (const uint32_t *const)&PFlash_Key, pageWriteAddr, (const uint32_t *const)pageWriteData);

                    if (kvRetVal != CMD_SUCCESS)
                    {
                        retVal = E_NOT_OK;
                        break;
                    }
                    else
                    {
                        /* Do Nothing */
                    }

                    pageWriteData += FLASH_EX_WRITE_MAX_SIZE;
                    pageWriteAddr += FLASH_EX_WRITE_MAX_SIZE;
                    cycleRemainToWrite -= FLASH_EX_WRITE_MAX_SIZE;
                }
            }
        }
#if (FLS_FEATURE_AB_SWAP_ENABLE != STD_ON)
        /* exit critical zone */
        Fls_Ex_SetCritical((boolean)FALSE);
#endif
    }

    return retVal;
}

/**
 * @brief PFlash extended Erases flash sector(s).
 *
 * @note
 * 1.TargetAddress write address 1024 Align
 * 2.Length write length 1024 Align
 * 3.Operation less than 960K
 *
 * @param TargetAddress Target address in flash memory.flash absolute address
 * @param Length Number of bytes to erase
 * @return Std_ReturnType
 * @retval E_NOT_OK
 * @retval E_OK
 */
Std_ReturnType Fls_Ex_PFlashErase(const uint32 TargetAddress, const uint32 Length)
{
    Std_ReturnType retVal = (Std_ReturnType)E_OK;

    if (((TargetAddress + Length) > FLS_EX_P_FLASH_MAX_ADDRESS) || (0U != (TargetAddress & FLASH_SECTOR_ERASE_MASK)))
    {
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    else if ((0U != (Length & FLASH_SECTOR_ERASE_MASK)) || (0U == Length))
    {
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        uint32 eraseAddress       = (uint32)TargetAddress;
        uint32 cycleRemainToErase = Length;
        uint32 kvRetVal           = 0U;
        /* PFlash Key Information */
        volatile Flash_Key_t PFlash_Key = {FLS_OPERATE_KEY, FLS_PFLASH_KEY1, FLS_PFLASH_KEY2, FLS_OPERATE_KEY};
#if (FLS_FEATURE_AB_SWAP_ENABLE != STD_ON)
        /* Enter critical zone */
        Fls_Ex_SetCritical((boolean)TRUE);
#endif
        while (cycleRemainToErase != 0U)
        {
            kvRetVal = __FLASH_Erase__((const uint32_t *const)&PFlash_Key, eraseAddress);

            if (kvRetVal != CMD_SUCCESS)
            {
                retVal = E_NOT_OK;
                break;
            }
            else
            {
                /* Do Nothing */
            }

            eraseAddress += FLASH_EX_ERASE_SIZE;
            cycleRemainToErase -= FLASH_EX_ERASE_SIZE;
        }
#if (FLS_FEATURE_AB_SWAP_ENABLE != STD_ON)
        /* exit critical zone */
        Fls_Ex_SetCritical((boolean)FALSE);
#endif
    }

    return retVal;
}
#endif

#if (FLS_DFLASH_FUNCTION_ENABLE == STD_ON)
/**
 * @brief DFlash extended Writes one or more complete flash pages.
 *
 * @note
 * 1.TargetAddress write address 8 Align
 * 2.Length write length 8 Align
 * 3.Operation 2M-2M+32K
 *
 * @param TargetAddress Target address in flash memory.flash absolute address
 * @param SourceAddressPtr Pointer to source data buffer
 * @param Length Number of bytes to write
 * @return Std_ReturnType
 * @retval E_NOT_OK
 * @retval E_OK
 */
Std_ReturnType Fls_Ex_DFlashWrite(const uint32 TargetAddress, const uint8 *SourceAddressPtr, const uint32 Length)
{
    Std_ReturnType retVal = (Std_ReturnType)E_OK;

    if (((TargetAddress + Length) > FLASH_MAX_ADDR) || (TargetAddress < FLASH_EX_D_FLASH_BASE_ADDR) ||
        (0U != (TargetAddress & FLASH_ADDR_AND_WRITE_LENGTH_MASK)))
    {
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    else if (((Length & FLASH_ADDR_AND_WRITE_LENGTH_MASK) > 0U) || (0U == Length))
    {
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    else if (SourceAddressPtr == NULL_PTR)
    {
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        uint8  loop;
        uint32 cycleRemainToWrite = Length;
        uint32 pageWriteData      = (uint32)SourceAddressPtr;
        uint32 pageWriteAddr      = (uint32)TargetAddress;
        uint32 kvRetVal           = 0U;
        uint8_t __attribute__((aligned(4))) Fls_ExDFlashWrite4AlignedBuffer[FLASH_EX_PAGE_SIZE];
        /* DFlash Key Information */
        volatile Flash_Key_t DFlash_Key = {FLS_OPERATE_KEY, FLS_DFLASH_KEY1, FLS_DFLASH_KEY2, FLS_OPERATE_KEY};

        /* Enter critical zone */
        Fls_Ex_SetCritical((boolean)TRUE);
        if (((uint32)SourceAddressPtr & FLASH_BUF_ALIGN_MASK) > 0U)
        {
            while (cycleRemainToWrite != 0U)
            {
                for (loop = 0U; loop < FLASH_EX_PAGE_SIZE; loop++)
                {
                    /* PRQA S 0488 1 #KQR000488  */
                    Fls_ExDFlashWrite4AlignedBuffer[loop] = *((uint8 *)pageWriteData + loop);
                }

                kvRetVal = __FLASH_Program_NBytes__(
                  (const uint32_t *const)&DFlash_Key, pageWriteAddr,
                  (const uint32_t *const)Fls_ExDFlashWrite4AlignedBuffer);

                if (kvRetVal != CMD_SUCCESS)
                {
                    retVal = E_NOT_OK;
                    break;
                }
                else
                {
                    /* Do Nothing */
                }
                pageWriteData += FLASH_EX_PAGE_SIZE;
                pageWriteAddr += FLASH_EX_PAGE_SIZE;
                cycleRemainToWrite -= FLASH_EX_PAGE_SIZE;
            }
        }
        else
        {
            if ((0U != (cycleRemainToWrite % FLASH_EX_WRITE_MAX_SIZE)) ||
                ((TargetAddress & FLASH_SECTOR_WRITE_MASK) != 0U))
            {

                while (cycleRemainToWrite != 0U)
                {
                    kvRetVal = __FLASH_Program_NBytes__(
                      (const uint32_t *const)&DFlash_Key, pageWriteAddr, (const uint32_t *const)pageWriteData);

                    if (kvRetVal != CMD_SUCCESS)
                    {
                        retVal = E_NOT_OK;
                        break;
                    }
                    else
                    {
                        /* Do Nothing */
                    }
                    pageWriteData += FLASH_EX_PAGE_SIZE;
                    pageWriteAddr += FLASH_EX_PAGE_SIZE;
                    cycleRemainToWrite -= FLASH_EX_PAGE_SIZE;
                }
            }
            else
            {
                while (cycleRemainToWrite != 0U)
                {
                    kvRetVal = __FLASH_Program__(
                      (const uint32_t *const)&DFlash_Key, pageWriteAddr, (const uint32_t *const)pageWriteData);

                    if (kvRetVal != CMD_SUCCESS)
                    {
                        retVal = E_NOT_OK;
                        break;
                    }
                    else
                    {
                        /* Do Nothing */
                    }

                    pageWriteData += FLASH_EX_WRITE_MAX_SIZE;
                    pageWriteAddr += FLASH_EX_WRITE_MAX_SIZE;
                    cycleRemainToWrite -= FLASH_EX_WRITE_MAX_SIZE;
                }
            }
        }
        /* exit critical zone */
        Fls_Ex_SetCritical((boolean)FALSE);
    }

    return retVal;
}

/**
 * @brief DFlash extended Erases flash sector(s).
 *
 * @note
 * 1.TargetAddress write address 1024 Align
 * 2.Length write length 1024 Align
 * 3.Operation 2M-2M+32K
 *
 * @param TargetAddress Target address in flash memory.flash absolute address
 * @param Length Number of bytes to erase
 * @return Std_ReturnType
 * @retval E_NOT_OK
 * @retval E_OK
 */
Std_ReturnType Fls_Ex_DFlashErase(const uint32 TargetAddress, const uint32 Length)
{
    Std_ReturnType retVal = (Std_ReturnType)E_OK;

    if (((TargetAddress + Length) > FLASH_MAX_ADDR) || (TargetAddress < FLASH_EX_D_FLASH_BASE_ADDR) ||
        (0U != (TargetAddress & FLASH_SECTOR_ERASE_MASK)))
    {
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    else if ((0U != (Length & FLASH_SECTOR_ERASE_MASK)) || (0U == Length))
    {
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        uint32 eraseAddress       = (uint32)TargetAddress;
        uint32 cycleRemainToErase = Length;
        uint32 kvRetVal           = 0U;
        /* DFlash Key Information */
        volatile Flash_Key_t DFlash_Key = {FLS_OPERATE_KEY, FLS_DFLASH_KEY1, FLS_DFLASH_KEY2, FLS_OPERATE_KEY};
        /* Enter critical zone */
        Fls_Ex_SetCritical((boolean)TRUE);
        while (cycleRemainToErase != 0U)
        {
            kvRetVal = __FLASH_Erase__((const uint32_t *const)&DFlash_Key, eraseAddress);

            if (kvRetVal != CMD_SUCCESS)
            {
                retVal = E_NOT_OK;
                break;
            }
            else
            {
                /* Do Nothing */
            }

            eraseAddress += FLASH_EX_ERASE_SIZE;
            cycleRemainToErase -= FLASH_EX_ERASE_SIZE;
        }
        /* exit critical zone */
        Fls_Ex_SetCritical((boolean)FALSE);
    }

    return retVal;
}
#endif

/**
 * @brief: Initialize A/B partition swap function
 *
 */
void Fls_Ex_Init(void)
{
#if (FLS_FEATURE_AB_SWAP_ENABLE == STD_ON)
    Flash_LL_UnlockRedundantReg();
    Flash_LL_EnableReadWhileWrite();
    Flash_LL_LockRedundantReg();
#endif
}

/* EOF */
