/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Fls_Im.c
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
 **                        QAC Warnings
 ******************************************************************************/
/**
 * @page QAC Warnings
 *
 */
/* PRQA S 0303 EOF #KQR000303 */
/* PRQA S 0306 EOF #KQR000306 */
/* PRQA S 0310 EOF #KQR000310 */
/* PRQA S 0404 EOF #KQR000404 */
/* PRQA S 0488 EOF #KQR000488 */
/* PRQA S 3345 EOF #KQR003345 */
/* PRQA S 3387 EOF #KQR003387 */
/* PRQA S 3415 EOF #KQR003415 */
/* PRQA S 3432 EOF #KQR003432 */
/* PRQA S 3473 EOF #KQR003473 */
/* PRQA S 4397 EOF #KQR004397 */
/* PRQA S 0312 EOF #KQR000312 */
/* PRQA S 2814 EOF #KQR002814 */
/* PRQA S 2824 EOF #KQR002824 */
/* PRQA S 2844 EOF #KQR002844 */
/* PRQA S 2201 EOF #KQR002201 */
/* PRQA S 3383 EOF #KQR003383 */
/* PRQA S 3384 EOF #KQR003384 */
/******************************************************************************
 **                      Include Files
 ******************************************************************************/
#include "Fls_Im.h"
#include "Mcal.h"
#include "kf32a158sf_drv_intr.h"
#include "kf32a158sf_drv_flash.h"
#include "__driver_Flash_API.h"
#if ((FLS_DEV_ERROR_DETECT == STD_ON) || (FLS_RUNTIME_ERROR_DETECT == STD_ON))
//#include "Det.h"
#endif
/******************************************************************************
 **                      Macro Definitions
 ******************************************************************************/
/**
 * @brief flash key
 */
#define FLS_OPERATE_KEY (0x5A5A6688U)

/**
 * @brief DFlash key
 */
#define FLS_DFLASH_KEY1 (0x77664CDEU)
#define FLS_DFLASH_KEY2 (0x82070612U)

/**
 * @brief PFlash key
 */
#define FLS_PFLASH_KEY1 (0x2895D3DEU)
#define FLS_PFLASH_KEY2 (0x81060711U)

/**
 * @brief PFlash 0~960K
 */
#define FLS_PFLASH_MAX_ADDRESS (0x000F0000U)

/**
 * @brief DFlash 2M
 */
#define FLS_DFLASH_BASE_ADDRESS (0x00200000U)

/**
 * @brief blank check value
 */
#define FLS_ERASED_VALUE (0xFFFFFFFFFFFFFFFFULL)

/**
 * @brief byte address alignment mask
 */
#define FLS_BUF_ALIGN_MASK (0x3U)

/**
 * @brief function call
 */
#define FLS_FLASH_FUNC_CALL(ptr2fcn, ptr2fcnType) ((ptr2fcnType)((uint32)(ptr2fcn)))
/******************************************************************************
 **                          Local Variables
 ******************************************************************************/
/**
 * @brief compare address
 */
static VOLATILE(Fls_DataBusWidthType, FLS_VAR, FLS_APPL_CONST) Fls_ReadAddressPtr = 0U;
/**
 * @brief compare address
 */
static VOLATILE(Fls_DataBusWidthType, FLS_VAR, FLS_APPL_CONST) Fls_CompareAddressPtr = 0U;

#if (FLS_BLANK_CHECK_API == STD_ON)
/**
 * @brief flash default value
 */
/* PRQA S 3218,0580 2 #KQR100012 */
static CONST(Fls_DataAccWidthType, FLS_CONST) Fls_ErasedFaultValue = FLS_ERASED_VALUE;
#endif
/* PRQA S 3218 2 #KQR003218 */
static uint32 kvIntState = 0U;

/**
 * @brief write buffer
 */
/* PRQA S 3218 2 # KQR003218 */
/* PRQA S 2071 1 #KQR002071 */
static uint8_t __attribute__((aligned(4))) Fls_Write4AlignedBuffer[FLASH_PAGE_SIZE];
/******************************************************************************
 **                          Local Function Definition
 ******************************************************************************/
/**
 * @brief flash operate should be enter critical
 *
 * @return void
 * @retval void
 */
static FUNC(void, FLS_CODE) Fls_Im_SetCritical(CONST(boolean, AUTOMATIC) Status)
{
    /* PRQA S 3344  1 #KQR003344*/
    if (Status)
    {
        /* Disable interrupt */
        kvIntState              = INTR_PTR->CTL0.bits.AIE;
        INTR_PTR->CTL0.bits.AIE = 0U;
    }
    else
    {
        if (kvIntState != 0U)
        {
            INTR_PTR->CTL0.bits.AIE = 1U;
        }
        else
        {
            /* Do Nothing */
        }
    }
}

#if (FLS_CANCEL_API == STD_ON)
/**
 * @brief waite flash finish
 *
 * @return Fls_InterReturnType
 * @retval FLS_INTER_E_FAILED
 * @retval FLS_INTER_E_OK
 */
static FUNC(Fls_InterReturnType, FLS_CODE) Fls_Im_WaitForOperationFinish(void)
{
    VAR(Fls_InterReturnType, AUTOMATIC) retVal = FLS_INTER_E_FAILED;
#if (FLS_TIMEOUT_ENABLED == STD_ON)
    uint32 timerCounterAbort = FLS_ABT_TIMEOUT_VALUE;
#endif

    /* wait finish */
#if (FLS_TIMEOUT_ENABLED == STD_ON)
    /* PRQA S 2486 1 #KQR002486 */
    while ((STD_ON == FLASH_RM.STATE.bits.TBIT) && (0U < timerCounterAbort))
    {
        --timerCounterAbort;
    }
#else
    while (STD_ON == FLASH_RM.STATE.bits.TBIT)
    {
    }
#endif

    if (STD_OFF == FLASH_RM.STATE.bits.TBIT)
    {
        retVal = FLS_INTER_E_OK;
    }
    else
    {
        retVal = FLS_INTER_E_FAILED;
    }

    return retVal;
}
#endif

#if ((FLS_ERASE_BLANK_CHECK == STD_ON) || (FLS_WRITE_BLANK_CHECK == STD_ON))
/**
 * @brief check erase result
 *
 * @param FlashAreaPtr check addr
 * @param DataLength check length
 * @return Fls_InterReturnType
 * @retval FLS_INTER_E_OK
 * FLS_INTER_E_FAILED
 * FLS_INTER_E_INCONSISTENT
 * FLS_INTER_E_PENDING
 */
static FUNC(Fls_InterReturnType, FLS_CODE) Fls_Im_VerifyErase(
  CONST(Fls_DataBusWidthType, FLS_APPL_CONST) FlashAreaPtr, CONST(Fls_LengthType, AUTOMATIC) DataLength)
{
    VAR(Fls_InterReturnType, AUTOMATIC) retVal            = FLS_INTER_E_OK;
    CONST(Fls_LengthType, FLS_APPL_CONST) flashAreaEndPtr = FlashAreaPtr + DataLength;

    Fls_Im_SetCritical((boolean)TRUE);
    /* PRQA S 2461 1 #KQR002461 */
    for (Fls_ReadAddressPtr = FlashAreaPtr; (Fls_ReadAddressPtr) < flashAreaEndPtr;
         Fls_ReadAddressPtr += (uint32)sizeof(Fls_DataAccWidthType))
    {
        Fls_DataAccWidthType data;
        /* PRQA S 3305 1 #KQR003305 */
        data = *(Fls_DataAccWidthType *)Fls_ReadAddressPtr;
        /* PRQA S 1254,0580 1 #KQR100014 */
        if (FLS_ERASED_VALUE != data)
        {
            break;
        }
        else
        {
            /* deliberately left blank to avoid QAC violation *
             * (Rule 2000 ) */
        }
    }

    Fls_Im_SetCritical((boolean)FALSE);

    if (Fls_ReadAddressPtr != flashAreaEndPtr)
    {
#if (FLS_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_VERIFY_ERASE_FAILED);
#endif
        retVal = FLS_INTER_E_FAILED;
    }
    else
    {
        /* deliberately left blank to avoid QAC violation *
         * (Rule 2000 ) */
    }

    return retVal;
}
#endif

#if (FLS_WRITE_VERIFICATION_ENABLED == STD_ON)
/**
 * @brief check write whether success
 *
 * @param FlashAreaPtr flash address
 * @param UserBufferPtr buffer address
 * @param DataLength check length
 *
 * @return Fls_InterReturnType
 * @retval FLS_INTER_E_OK
 * @retval FLS_INTER_E_FAILED
 */
static FUNC(Fls_InterReturnType, FLS_CODE)
  Fls_Im_VerifyWrite(CONST(Fls_DataBusWidthType, CONSTANT) FlashAreaPtr,
                     CONST(Fls_DataBusWidthType, CONSTANT) UserBufferPtr, CONST(Fls_LengthType, CONSTANT) DataLength)
{
    VAR(Fls_InterReturnType, AUTOMATIC) retVal = FLS_INTER_E_OK;
    /* check end address */
    VOLATILE(Fls_DataBusWidthType, AUTOMATIC, FLS_APPL_CONST) flashAreaEndPtr = FlashAreaPtr + DataLength;
    /* PRQA S 3205 2 #KQR003205 */
    Fls_DataAccWidthType readData;
    Fls_DataAccWidthType compareData;
    /* check address */
    Fls_CompareAddressPtr = UserBufferPtr;

    /* PRQA S 2461 1 #KQR002461 */
    for (Fls_ReadAddressPtr = FlashAreaPtr; Fls_ReadAddressPtr < flashAreaEndPtr;
         Fls_ReadAddressPtr += (uint32)sizeof(Fls_DataAccWidthType))
    {
        /* PRQA S 3305 1 #KQR003305  */
        readData = *((Fls_DataAccWidthType *)Fls_ReadAddressPtr);

        if (0U != ((uint32)Fls_CompareAddressPtr % 8U))
        {
            compareData = (((Fls_DataAccWidthType)(*(uint8 *)(Fls_CompareAddressPtr + 7U))) << 56U);
            compareData |= (((Fls_DataAccWidthType)(*(uint8 *)(Fls_CompareAddressPtr + 6U))) << 48U);
            compareData |= (((Fls_DataAccWidthType)(*(uint8 *)(Fls_CompareAddressPtr + 5U))) << 40U);
            compareData |= (((Fls_DataAccWidthType)(*(uint8 *)(Fls_CompareAddressPtr + 4U))) << 32U);
            compareData |= (((Fls_DataAccWidthType)(*(uint8 *)(Fls_CompareAddressPtr + 3U))) << 24U);
            compareData |= (((Fls_DataAccWidthType)(*(uint8 *)(Fls_CompareAddressPtr + 2U))) << 16U);
            compareData |= (((Fls_DataAccWidthType)(*(uint8 *)(Fls_CompareAddressPtr + 1U))) << 8U);
            compareData |= *(uint8 *)Fls_CompareAddressPtr;
        }
        else
        {
            /* PRQA S 3305 1 #KQR003305 */
            compareData = *((Fls_DataAccWidthType *)Fls_CompareAddressPtr);
        }

        if (readData != compareData)
        {
            /* data check error */
            break;
        }
        else
        {
            /* deliberately left blank to avoid QAC violation *
             * (Rule 2000 ) */
        }

        Fls_CompareAddressPtr += (uint32)sizeof(Fls_DataAccWidthType);
    }

    if (Fls_ReadAddressPtr != flashAreaEndPtr)
    {
#if (FLS_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_VERIFY_WRITE_FAILED);
#endif
        retVal = FLS_INTER_E_FAILED;
    }
    else
    {
        /* deliberately left blank to avoid QAC violation *
         * (Rule 2000 ) */
    }

    return retVal;
}
#endif

/**
 * @brief check flash whether idle status
 *
 * @return Fls_InterReturnType
 * @retval FLS_INTER_E_OK
 * @retval FLS_INTER_E_FAILED
 */
static FUNC(Fls_InterReturnType, FLS_CODE) Fls_Im_CheckCtrlIdle(void)
{
    VAR(Fls_InterReturnType, AUTOMATIC) retVal;

    /* check flash status */
    if (STD_IDLE == FLASH_RM.STATE.bits.TBIT)
    {
        retVal = FLS_INTER_E_OK;
    }
    else
    {
        retVal = FLS_INTER_E_FAILED;
    }

    return retVal;
}

/**
 * @brief flash operate feed dog
 */
static FUNC(void, FLS_CODE) Fls_Im_FeedDogProcess(void)
{
    /* feed dog */
    /* PRQA S 3344  1 #KQR003344*/
    if (Fls_CurrentConfigPtr->FeedDogProcessPtr)
    {
        Fls_CurrentConfigPtr->FeedDogProcessPtr();
    }
    else
    {
        /* deliberately left blank to avoid QAC violation *
         * (Rule 2000 ) */
    }
}
/******************************************************************************
 *                          Global Function Definition                         *
 ******************************************************************************/

/**
 * @brief Initialize flash hardware
 *
 * @return void
 * @retval void
 */
FUNC(void, FLS_CODE) Fls_Im_Init(void)
{
    Fls_JobOperateStatus = MEMIF_JOB_OK;

    if (TRUE == FLASH_RM.STATE.bits.TBIT)
    {
        /* If there is any pending operation in the memory controller */
#if (FLS_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportTransientFault((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_INIT_ID, FLS_E_ERASE_FAILED);
#endif
        Fls_JobOperateStatus = MEMIF_JOB_FAILED;
    }
    else
    {
        /* deliberately left blank to avoid QAC violation *
         * (Rule 2000 ) */
    }
}

#if (FLS_CANCEL_API == STD_ON)
/**
 * @brief cancel erase or write operate
 *
 * @return void
 * @retval void
 */
FUNC(void, FLS_CODE) Fls_Im_Cancel(void)
{
    /* wait for operate finish */
    if (FLS_INTER_E_OK == Fls_Im_WaitForOperationFinish())
    {
        /* set status canceled */
        Fls_JobOperateStatus = MEMIF_JOB_CANCELED;
    }
    else
    {
        /* deliberately left blank to avoid QAC violation *
         * (Rule 2000 ) */
    }
}
#endif

/**
 * @brief flash erase,erase one sector
 *
 * @param EraseAddr erase address
 *
 * @return Fls_InterReturnType
 * @retval FLS_INTER_E_FAILED
 * @retval FLS_INTER_E_OK
 */
FUNC(Fls_InterReturnType, FLS_CODE)
Fls_Im_SectorErase(CONST(Fls_SectorIdType, AUTOMATIC) EraseAddr)
{
    VAR(Fls_InterReturnType, AUTOMATIC) retVal = FLS_INTER_E_OK;
    VAR(uint32, AUTOMATIC) kvRetVal            = 0U;
    volatile Flash_Key_t DFlashKey             = {FLS_OPERATE_KEY, FLS_DFLASH_KEY1, FLS_DFLASH_KEY2, FLS_OPERATE_KEY};

    VOLATILE(Fls_DataBusWidthType, FLS_VAR, FLS_APPL_CONST)
    eraseAddress = (Fls_DataBusWidthType)(Fls_CurrentConfigPtr->PhysicalStartAddr + EraseAddr);

#if (FLS_TIMEOUT_ENABLED == STD_ON)
    /* Initialize timeout counters */
    VAR(uint32, FLS_VAR) timeoutCounter = FLS_SYNC_ERASE_TIMEOUT_VALUE;
#endif

    /* verify that ERASE SECTOR command may be started */
    if (FLS_INTER_E_OK != Fls_Im_CheckCtrlIdle())
    {
        retVal = FLS_INTER_E_FAILED;
    }
    else
    {
        /* start erase */
        if (NULL_PTR != Fls_CurrentConfigPtr->StartFlashAccessNotificationPtr)
        {
            Fls_CurrentConfigPtr->StartFlashAccessNotificationPtr();
        }
        else
        {
            /* deliberately left blank to avoid QAC violation *
             * (Rule 2000 ) */
        }

        /* Enter critical zone */
        Fls_Im_SetCritical((boolean)TRUE);
        /* feed dog */
        Fls_Im_FeedDogProcess();

        /* PRQA S 0305,0311 2 #KQR100020 */
        kvRetVal = FLS_FLASH_FUNC_CALL(Fls_CurrentConfigPtr->EraseProcessPtr, Fls_ErasePtrType)(
          (uint32 *)&DFlashKey, eraseAddress);
        /* check flash operate result */
        if (kvRetVal != CMD_SUCCESS)
        {
            retVal = FLS_INTER_E_FAILED;
        }
        else
        {
            /* Do Nothing */
        }

        /* feed dog */
        Fls_Im_FeedDogProcess();
        /* exit critical zone */
        Fls_Im_SetCritical((boolean)FALSE);
        if (NULL_PTR != Fls_CurrentConfigPtr->FinishedFlashAccessNotificationPtr)
        {
            Fls_CurrentConfigPtr->FinishedFlashAccessNotificationPtr();
        }
        else
        {
            /* deliberately left blank to avoid QAC violation *
             * (Rule 2000 ) */
        }

        /* verify that erase operation was successful */
#if (FLS_TIMEOUT_ENABLED == STD_ON)
        while ((TRUE == FLASH_RM.STATE.bits.TBIT) && (0U < timeoutCounter))
        {
            --timeoutCounter;
        }

        if (0U != timeoutCounter)
#endif
        {
            /* erase operation succeed */
#if (FLS_ERASE_BLANK_CHECK == STD_ON)
            if (FLS_INTER_E_OK != Fls_Im_VerifyErase(eraseAddress, FLASH_SECTOR_SIZE))
            {
                retVal = FLS_INTER_E_FAILED;
            }
            else
            {
                retVal = FLS_INTER_E_OK;
            }
#endif
        }
#if (FLS_TIMEOUT_ENABLED == STD_ON)
        else
        {
            retVal = FLS_INTER_E_FAILED;
        }
#endif
    }

    return retVal;
}

/**
 * @brief sector write
 *
 * @param ProcessAddr process address
 * @param WriteLength write length
 * @param WriteData write data
 *
 * @return Fls_InterReturnType
 * @retval FLS_INTER_E_OK
 * @retval FLS_INTER_E_FAILED
 * @retval FLS_INTER_E_PENDING
 */
FUNC(Fls_InterReturnType, FLS_CODE)
Fls_Im_SectorWrite(CONST(Fls_AddressType, AUTOMATIC) ProcessAddr, CONST(Fls_LengthType, AUTOMATIC) WriteLength,
                   CONSTP2CONST(uint8, AUTOMATIC, FLS_APPL_CONST) WriteData)
{
    VAR(Fls_InterReturnType, AUTOMATIC) retVal = FLS_INTER_E_OK;
    VAR(uint32, AUTOMATIC) CycleRemainToWrite  = WriteLength;
    VAR(Fls_DataBusWidthType, AUTOMATIC) writeAddressPtr;
    VAR(Fls_DataBusWidthType, AUTOMATIC) pageWriteData;
    VAR(Fls_DataBusWidthType, AUTOMATIC) pageWriteAddr;
    VAR(uint32, AUTOMATIC) kvRetVal = 0U;
    volatile Flash_Key_t DFlashKey  = {FLS_OPERATE_KEY, FLS_DFLASH_KEY1, FLS_DFLASH_KEY2, FLS_OPERATE_KEY};

    writeAddressPtr = (Fls_DataBusWidthType)(Fls_CurrentConfigPtr->PhysicalStartAddr + ProcessAddr);

#if (FLS_WRITE_BLANK_CHECK == STD_ON)
    /* check the memory location for being erased before attempting to write it */
    if (FLS_INTER_E_OK != Fls_Im_VerifyErase(writeAddressPtr, WriteLength))
    {
        /* verify erase failed */
        retVal = FLS_INTER_E_FAILED;
    }
    else
    {
#endif

        /* start write data */
        if (NULL_PTR != Fls_CurrentConfigPtr->StartFlashAccessNotificationPtr)
        {
            Fls_CurrentConfigPtr->StartFlashAccessNotificationPtr();
        }
        else
        {
            /* deliberately left blank to avoid QAC violation *
             * (Rule 2000 ) */
        }

        /* call flash access code routine */
        /* Enter critical zone */
        Fls_Im_SetCritical((boolean)TRUE);

        if (((uint32_t)WriteData & FLS_BUF_ALIGN_MASK) > 0U)
        {
            VAR(uint8, AUTOMATIC) loop;

            pageWriteData = (Fls_DataBusWidthType)WriteData;
            pageWriteAddr = (Fls_DataBusWidthType)writeAddressPtr;
            while (CycleRemainToWrite != 0U)
            {
                for (loop = 0U; loop < FLASH_PAGE_SIZE; loop++)
                {
                    Fls_Write4AlignedBuffer[loop] = *((uint8 *)pageWriteData + loop);
                }

                /* PRQA S 0305,0311,3305 2 #KQR100007 */
                kvRetVal = FLS_FLASH_FUNC_CALL(Fls_CurrentConfigPtr->WritePageProcessPtr, Fls_WritePtrType)(
                  (uint32 *)&DFlashKey, pageWriteAddr, (Fls_InterFuncType *)Fls_Write4AlignedBuffer);

                pageWriteData += FLASH_PAGE_SIZE;
                pageWriteAddr += FLASH_PAGE_SIZE;
                CycleRemainToWrite -= FLASH_PAGE_SIZE;
                /* feed dog */
                Fls_Im_FeedDogProcess();
                /* check flash operate result */
                if (kvRetVal != CMD_SUCCESS)
                {
                    retVal = FLS_INTER_E_FAILED;
                    break;
                }
                else
                {
                    /* Do Nothing */
                }
            }
        }
        else
        {
            if ((0U != (CycleRemainToWrite % FLASH_FAST_WRITE_MAX_SIZE)) || ((writeAddressPtr & 0x3FFU) != 0U))
            {
                pageWriteData = (Fls_DataBusWidthType)WriteData;
                pageWriteAddr = (Fls_DataBusWidthType)writeAddressPtr;

                while (CycleRemainToWrite != 0U)
                {

                    /* PRQA S 0305,0311,3305 2 #KQR100007 */
                    kvRetVal = FLS_FLASH_FUNC_CALL(Fls_CurrentConfigPtr->WritePageProcessPtr, Fls_WritePtrType)(
                      (uint32 *)&DFlashKey, pageWriteAddr, (Fls_InterFuncType *)pageWriteData);

                    pageWriteData += FLASH_PAGE_SIZE;
                    pageWriteAddr += FLASH_PAGE_SIZE;
                    CycleRemainToWrite -= FLASH_PAGE_SIZE;
                    /* feed dog */
                    Fls_Im_FeedDogProcess();
                    /* check flash operate result */
                    if (kvRetVal != CMD_SUCCESS)
                    {
                        retVal = FLS_INTER_E_FAILED;
                        break;
                    }
                    else
                    {
                        /* Do Nothing */
                    }
                }
            }
            else
            {
                /* feed dog */
                Fls_Im_FeedDogProcess();

                /* PRQA S 0305,0311,3305 2 #KQR100007 */
                kvRetVal = FLS_FLASH_FUNC_CALL(Fls_CurrentConfigPtr->WriteSectorProcessPtr, Fls_WritePtrType)(
                  (uint32 *)&DFlashKey, writeAddressPtr, (Fls_InterFuncType *)((Fls_DataBusWidthType)WriteData));
                /* check flash operate result */
                if (kvRetVal != CMD_SUCCESS)
                {
                    retVal = FLS_INTER_E_FAILED;
                }
                else
                {
                    /* Do Nothing */
                }
                /* feed dog */
                Fls_Im_FeedDogProcess();
            }
        }

        /* exit critical zone */
        Fls_Im_SetCritical((boolean)FALSE);
        /* end flash access section: implementation depends on integrator */
        if (NULL_PTR != Fls_CurrentConfigPtr->FinishedFlashAccessNotificationPtr)
        {
            Fls_CurrentConfigPtr->FinishedFlashAccessNotificationPtr();
        }
        else
        {
            /* deliberately left blank to avoid QAC violation *
             * (Rule 2000 ) */
        }

        /* verify that program operation was successful */
        /* program operation succeed */
#if (FLS_WRITE_VERIFICATION_ENABLED == STD_ON)
        if (FLS_INTER_E_OK != Fls_Im_VerifyWrite(writeAddressPtr, (Fls_DataBusWidthType)WriteData, WriteLength))
        {
            retVal = FLS_INTER_E_FAILED;
        }
        else
        {
            retVal = FLS_INTER_E_OK;
        }
#endif
#if (FLS_WRITE_BLANK_CHECK == STD_ON)
    }
#endif

    return retVal;
}

/**
 * @brief sector read
 *
 * @param ProcessAddr process address
 * @param ReadLength read length
 * @param ReadData save read data
 * @return Fls_InterReturnType
 * @retval FLS_INTER_E_OK
 */
FUNC(Fls_InterReturnType, FLS_CODE)
Fls_Im_SectorRead(CONST(Fls_AddressType, AUTOMATIC) ProcessAddr, VAR(Fls_LengthType, AUTOMATIC) ReadLength,
                  P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) ReadData)
{
    /* Physical flash address to read */
    Fls_ReadAddressPtr = (Fls_DataBusWidthType)(Fls_CurrentConfigPtr->PhysicalStartAddr + ProcessAddr);

    while ((8U <= ReadLength) && ((0U != ((uint32)ReadData % 8U)) || (0U != ((uint32)Fls_ReadAddressPtr % 8U))))
    {
        /* read flash address */
        *ReadData = *(uint8 *)Fls_ReadAddressPtr;
        /* PRQA S 1338 1 #KQR001338 */
        ReadData++;
        Fls_ReadAddressPtr++;
        /* PRQA S 1338 1 #KQR001338 */
        ReadLength -= 1U;
    }

    /* 64bits read */
    while (8U <= ReadLength)
    {
        /* PRQA S 3305 3 #KQR003305 */
        *(uint64 *)(ReadData) = *(Fls_DataAccWidthType *)Fls_ReadAddressPtr;
        /* PRQA S 1338 1 #KQR001338 */
        ReadData += (uint32)sizeof(Fls_DataAccWidthType);
        Fls_ReadAddressPtr += (uint32)sizeof(Fls_DataAccWidthType);
        /* PRQA S 1338 1 #KQR001338 */
        ReadLength -= 8U;
    }

    /* 8bits read */
    while (0U < ReadLength)
    {
        /* read flash address */
        *ReadData = *(uint8 *)Fls_ReadAddressPtr;
        /* PRQA S 1338 1 #KQR001338 */
        ReadData++;
        Fls_ReadAddressPtr++;
        /* PRQA S 1338 1 #KQR001338 */
        ReadLength -= 1U;
    }

    return FLS_INTER_E_OK;
}

#if ((FLS_COMPARE_API == STD_ON) || (FLS_BLANK_CHECK_API == STD_ON))
/**
 * @brief compare sector data
 *
 * @param ProcessAddr process address
 * @param CompareLength compare data length
 * @param CompareData compare data
 *
 * @return Fls_InterReturnType
 * @retval FLS_INTER_E_OK
 * @retval FLS_INTER_E_INCONSISTENT
 */
FUNC(Fls_InterReturnType, FLS_CODE)
Fls_Im_SectorCompare(CONST(Fls_AddressType, AUTOMATIC) ProcessAddr, VAR(Fls_LengthType, AUTOMATIC) CompareLength,
                     CONSTP2CONST(uint8, AUTOMATIC, FLS_APPL_CONST) CompareData)
{
    VAR(uint8, AUTOMATIC) fls8ReadValue;
    VAR(uint64, AUTOMATIC) fls64ReadValue;
    VAR(uint8, AUTOMATIC) fls8CompareValue;
    VAR(uint64, AUTOMATIC) fls64CompareValue;
    Fls_InterReturnType retVal = FLS_INTER_E_OK;

    /* read flash address */
    Fls_ReadAddressPtr = (Fls_DataBusWidthType)(Fls_CurrentConfigPtr->PhysicalStartAddr + ProcessAddr);
#if (FLS_BLANK_CHECK_API == STD_ON)
    if (NULL_PTR == CompareData)
    {
        /* PRQA S 0311 1 #KQR000311 */
        Fls_CompareAddressPtr = (Fls_DataBusWidthType)&Fls_ErasedFaultValue;
    }
    else
#endif
    {
        /* compare address */
        Fls_CompareAddressPtr = (Fls_DataBusWidthType)CompareData;
    }

    while ((8U <= CompareLength) &&
           ((0U != ((uint32)Fls_CompareAddressPtr % 8U)) || (0U != ((uint32)Fls_ReadAddressPtr % 8U))))
    {
        /* read flash address */
        fls8ReadValue = *(uint8 *)Fls_ReadAddressPtr;
        Fls_ReadAddressPtr += (uint32)sizeof(uint8);

        /* read compare */
        fls8CompareValue = *(uint8 *)Fls_CompareAddressPtr;

        /* PRQA S 1338 1 #KQR001338 */
        CompareLength -= 1U;

        if (fls8ReadValue != fls8CompareValue)
        {
            retVal = FLS_INTER_E_INCONSISTENT;
            break;
        }
        else
        {
#if (FLS_BLANK_CHECK_API == STD_ON)
            if (NULL_PTR == CompareData)
            {
                /* BLANK_CHECK API */
            }
            else
#endif
            {
                Fls_CompareAddressPtr += (uint32)sizeof(uint8);
            }
        }
    }

    if (retVal == FLS_INTER_E_OK)
    {
        while (8U <= CompareLength)
        {
            /* read flash location */
            fls64ReadValue = *(Fls_DataAccWidthType *)Fls_ReadAddressPtr;
            Fls_ReadAddressPtr += (uint32)sizeof(Fls_DataAccWidthType);

            /* read compare */
            fls64CompareValue = *(Fls_DataAccWidthType *)Fls_CompareAddressPtr;

            /* PRQA S 1338 1 #KQR001338 */
            CompareLength -= 8U;

            if (fls64ReadValue != fls64CompareValue)
            {
                retVal = FLS_INTER_E_INCONSISTENT;
                break;
            }
            else
            {
#if (FLS_BLANK_CHECK_API == STD_ON)
                if (NULL_PTR == CompareData)
                {
                    /* BLANK_CHECK API */
                }
                else
#endif
                {
                    Fls_CompareAddressPtr += (uint32)sizeof(Fls_DataAccWidthType);
                }
            }
        }

        if (retVal == FLS_INTER_E_OK)
        {
            while (0U < CompareLength)
            {
                /* read flash address */
                fls8ReadValue = *(uint8 *)Fls_ReadAddressPtr;
                Fls_ReadAddressPtr += (uint32)sizeof(uint8);

                /* read compare */
                fls8CompareValue = *(uint8 *)Fls_CompareAddressPtr;

                /* PRQA S 1338 1 #KQR001338 */
                CompareLength -= 1U;

                if (fls8ReadValue != fls8CompareValue)
                {
                    retVal = FLS_INTER_E_INCONSISTENT;
                    break;
                }
                else
                {
#if (FLS_BLANK_CHECK_API == STD_ON)
                    if (NULL_PTR == CompareData)
                    {
                        /* BLANK_CHECK API */
                    }
                    else
#endif
                    {
                        Fls_CompareAddressPtr += (uint32)sizeof(uint8);
                    }
                }
            }
        }
    }

    return retVal;
}
#endif
