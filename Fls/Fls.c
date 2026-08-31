/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Fls.c
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
/* PRQA S 0488 EOF #KQR000488 */
/* PRQA S 0791 EOF #KQR000791 */
/* PRQA S 3387 EOF #KQR003387 */
/* PRQA S 3432 EOF #KQR003432 */
/* PRQA S 3408 EOF #KQR003408 */
/* PRQA S 2814 EOF #KQR002814 */
/* PRQA S 2824 EOF #KQR002824 */
/* PRQA S 2844 EOF #KQR002844 */
/* PRQA S 2201 EOF #KQR002201 */
/* PRQA S 2919 EOF #KQR002919 */
/* PRQA S 2934 EOF #KQR002934 */
/* PRQA S 3383 EOF #KQR003383 */
/******************************************************************************
 **                        QAC Warnings
 ******************************************************************************/
/**
 * @page QAC Warnings
 *
 */

/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "Fls.h"
#include "SchM_Fls.h"
#include "Fls_Im.h"
#if ((FLS_DEV_ERROR_DETECT == STD_ON) || (FLS_RUNTIME_ERROR_DETECT == STD_ON))
#include "Det.h"
#endif
/******************************************************************************
 **                        File Version Check
 ******************************************************************************/
/**
 * @brief can module autosar version,c file ver
 *
 * Internal micro-dependent versioning. Check of AUTOSAR & Vendor specification version.
 */
#define FLS_SW_MAJOR_VERSION_C (1U)
#define FLS_SW_MINOR_VERSION_C (0U)
#define FLS_SW_PATCH_VERSION_C (0U)

/**
 * @brief Check if current file and CAN configuration header file are of the same software version
 */
#if ((FLS_SW_MAJOR_VERSION_C != FLS_SW_MAJOR_VERSION) || (FLS_SW_MINOR_VERSION_C != FLS_SW_MINOR_VERSION) ||           \
     (FLS_SW_PATCH_VERSION_C != FLS_SW_PATCH_VERSION))
#error "Software Version Numbers of Fls and Fls.h are different"
#endif
/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/
/**
 * @brief fill pattern used to clear write and erase access code in RAM
 */
#if (FLS_AC_LOAD_ON_JOB_START == STD_ON)
#define FLS_AC_UNLOAD_PATTERN 0xFFFFFFFFU
#endif

/**
 * @brief Calculate total flash size in bytes
 */
#if (FLS_DEV_ERROR_DETECT == STD_ON)
#define FLS_TOTAL_SIZE (Fls_CurrentConfigPtr->FlashTotalSize)
#endif
/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/

/******************************************************************************
 **                        Export Variables
 ******************************************************************************/

/******************************************************************************
 **                        Export Functions
 ******************************************************************************/
#if (FLS_AC_LOAD_ON_JOB_START == STD_ON)
/* Start Position and Size of erase access code in flash */
extern CONST(uint32, FLS_CONST) Fls_ACEraseRomStart[];
extern CONST(uint32, FLS_CONST) Fls_ACEraseSize[];
/* Start Position and Size of write access code in flash */
extern CONST(uint32, FLS_CONST) Fls_ACWriteRomStart[];
extern CONST(uint32, FLS_CONST) Fls_ACWriteSize[];
#endif

#if (FLS_PRECOMPILE_SUPPORT == STD_ON)
extern CONST(Fls_ConfigType, FLS_CONST) Fls_ConfigPredefined;
#endif
/******************************************************************************
 **                        Global Variables
 ******************************************************************************/
/**
 * @brief Result of last flash hardware job
 */
VAR(volatile MemIf_JobResultType, FLS_VAR) Fls_JobOperateStatus = MEMIF_JOB_OK;

/**
 * @brief Pointer to current flash
 */
P2CONST(Fls_ConfigType, FLS_VAR, FLS_APPL_CONST) Fls_CurrentConfigPtr = NULL_PTR;

/**
 * @brief const variable for define minimum operable size
 *
 * @note Place in .inrodata so it is copied to RAM with .indata Flash API.
 *       __FLASH_Erase__ (vendor RAM code) does LD #__Flash_Min_Size__ then
 *       LD.W; keeping the object in the RAM init image avoids a stale/wrong
 *       flash absolute after startup copy.
 */
/* PRQA S 0499,0602,1502 1 #KQR100011 */
__attribute__((section(".inrodata"), used))
const uint32 __Flash_Min_Size__ = (uint32)FLS_MIN_OPERABLE_ADDRESS;
/******************************************************************************
 **                      Constant Declarations
 ******************************************************************************/

/******************************************************************************
**                     Variable Declarations
******************************************************************************/
/**
 * @brief Logical address of data block currently processed by Fls_MainFunction
 */
static VAR(Fls_AddressType, FLS_VAR) Fls_JobOperateAddrStart = 0U;
/**
 * @brief Last logical address to be processed by a job
 */
static VAR(Fls_AddressType, FLS_VAR) Fls_JobOperateAddrEnd = 0U;
/**
 * @brief Type of currently executed job (erase, write, read, or compare)
 */
static VAR(Fls_JobOperateType, FLS_VAR) Fls_JobOperate = FLS_JOB_ERASE;
/**
 * @brief Maximum number of bytes to read or compare in one cycle of Fls_MainFunction
 */
static VAR(Fls_LengthType, FLS_VAR) Fls_MaxRead = 0U;
/**
 * @brief Maximum number of bytes to write in one cycle of Fls_MainFunction
 */
static VAR(Fls_LengthType, FLS_VAR) Fls_MaxWrite = 0U;
/**
 * @brief Result of Module State
 * @implements Fls_JobResult_Object #SWS_Fls_00184
 */
static VAR(MemIf_StatusType, FLS_VAR) Fls_ModuleState = MEMIF_UNINIT;
/**
 * @brief Result of last flash module job
 * @implements Fls_JobResult_Object
 */
static VAR(MemIf_JobResultType, FLS_VAR) Fls_JobResult = MEMIF_JOB_OK;
/**
 * @brief Pointer to current position in source data buffer
 * @details Used by both write and compare jobs
 */
static P2CONST(uint8, FLS_VAR, FLS_APPL_CONST) Fls_JobDataSrcPtr = NULL_PTR;
/**
 * @brief Pointer to current position in target data buffer
 * @details Used only by read job
 */
static P2VAR(uint8, FLS_VAR, FLS_APPL_DATA) Fls_JobDataDestPtr = NULL_PTR;
/**
 * @brief Indicates that new job has been accepted
 * @details Used by all types of job
 */
static VAR(boolean, FLS_VAR) Fls_JobStartStatus = FALSE;
/******************************************************************************
 **                      Function definitions
 ******************************************************************************/
#if (FLS_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief check write address whether aligned
 * @param TargetAddress write target end address
 * @return boolean
 * @retval FALSE
 * @retval TRUE
 */
static FUNC(boolean, FLS_CODE) Fls_CheckAddrPageAligned(CONST(Fls_AddressType, AUTOMATIC) TargetAddress)
{
    VAR(boolean, AUTOMATIC) retVal;

    if ((TargetAddress <= (Fls_AddressType)FLS_TOTAL_SIZE) && (0U == (TargetAddress % (FLASH_PAGE_SIZE))))
    {
        retVal = (boolean)TRUE;
    }
    else
    {
        retVal = (boolean)FALSE;
    }

    return (retVal);
}

/**
 * @brief check erase end address whether aligned
 * @param TargetAddress erase start address
 * @return boolean
 * @retval TRUE
 * @retval FALSE
 */
static FUNC(boolean, FLS_CODE) Fls_CheckAddrSectorAligned(CONST(Fls_AddressType, AUTOMATIC) TargetAddress)
{
    VAR(boolean, AUTOMATIC) retVal;

    if ((TargetAddress <= FLS_TOTAL_SIZE) && ((TargetAddress % FLASH_SECTOR_SIZE) == 0U))
    {
        retVal = (boolean)TRUE;
    }
    else
    {
        retVal = (boolean)FALSE;
    }

    return retVal;
}

#endif

#if (FLS_AC_LOAD_ON_JOB_START == STD_ON)
/**
 * @brief load access function
 * @param OperateType operate type
 * @return None
 * @retval None
 */
static FUNC(void, FLS_CODE) Fls_LoadAccessCode(CONST(Fls_JobOperateType, AUTOMATIC) OperateType)
{
    P2CONST(uint32, AUTOMATIC, FLS_APPL_CONST) romPtr    = NULL_PTR;
    P2CONST(uint32, AUTOMATIC, FLS_APPL_CONST) romEndPtr = NULL_PTR;
    P2VAR(uint32, AUTOMATIC, FLS_APPL_DATA) ramPtr       = NULL_PTR;

    switch (OperateType)
    {
    case FLS_JOB_ERASE:
        romPtr    = Fls_ACEraseRomStart;
        romEndPtr = romPtr + (uint32)(Fls_ACEraseSize);
        ramPtr    = (uint32 *)(Fls_CurrentConfigPtr->EraseProcessPtr);
        break;

    case FLS_JOB_WRITE:
        romPtr    = Fls_ACWriteRomStart;
        romEndPtr = romPtr + (uint32)(Fls_ACWriteSize);
        ramPtr    = (uint32 *)(Fls_CurrentConfigPtr->WritePageProcessPtr);
        break;
    default:
        /* PRQA S 2016 1 #KQR002016  */
        break;
    }

    for (; (uint32)romPtr < (uint32)romEndPtr; romPtr++)
    {
        *ramPtr = *romPtr;
        ramPtr++;
    }
}

/**
 * @brief unload access function
 * @param OperateType operate type
 * @return None
 * @retval None
 */
static FUNC(void, FLS_CODE) Fls_UnloadAccessCode(CONST(Fls_JobOperateType, AUTOMATIC) OperateType)
{
    P2VAR(uint32, AUTOMATIC, FLS_APPL_DATA) ramPtr    = NULL_PTR;
    P2VAR(uint32, AUTOMATIC, FLS_APPL_DATA) ramEndPtr = NULL_PTR;

    switch (OperateType)
    {
    case FLS_JOB_ERASE:
        ramPtr    = (uint32 *)(Fls_CurrentConfigPtr->EraseProcessPtr);
        ramEndPtr = ramPtr + (uint32)(Fls_ACEraseSize);
        break;
    case FLS_JOB_WRITE:
        ramPtr    = (uint32 *)(Fls_CurrentConfigPtr->WritePageProcessPtr);
        ramEndPtr = ramPtr + (uint32)(Fls_ACWriteSize);
        break;
    default:
        /* PRQA S 2016 1 #KQR002016  */
        break;
    }

    for (; (uint32)ramPtr < (uint32)ramEndPtr; ramPtr++)
    {
        *ramPtr = FLS_AC_UNLOAD_PATTERN;
    }
}
#endif

/**
 * @brief flash job erase
 *
 * @return void
 * @retval void
 */
static FUNC(MemIf_JobResultType, FLS_CODE) Fls_JobEraseProcess(void)
{
    VAR(MemIf_JobResultType, AUTOMATIC) retVal = MEMIF_JOB_PENDING;
    /* process result */
    VAR(Fls_InterReturnType, AUTOMATIC) eraseResult;

    if (Fls_JobOperateAddrStart >= Fls_JobOperateAddrEnd)
    {
        /* PRQA S 2982 1 #KQR002982 */
        retVal = MEMIF_JOB_OK;
    }
    else
    {
        /* erase sector */
        eraseResult = Fls_Im_SectorErase(Fls_JobOperateAddrStart);
        Fls_JobOperateAddrStart += FLASH_SECTOR_SIZE;

        if (FLS_INTER_E_FAILED == eraseResult)
        {
            retVal = MEMIF_JOB_FAILED;
#if (FLS_RUNTIME_ERROR_DETECT == STD_ON)
            /* @implements #SWS_Fls_00104 */
            (void)Det_ReportRuntimeError(
              (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_ERASE_FAILED);
#endif
        }
        else if ((FLS_INTER_E_OK == eraseResult) && (Fls_JobOperateAddrStart >= Fls_JobOperateAddrEnd))
        {
            retVal = MEMIF_JOB_OK;
        }
        else
        {
            /* retVal remains MEMIF_JOB_PENDING */
        }
    }

    return (retVal);
}

/**
 * @brief calculate process end address
 * @param MaxLength process data length
 * @return Fls_AddressType
 * @retval address
 */
static FUNC(Fls_AddressType, FLS_CODE) Fls_CalcDataProcessAddrEnd(CONST(Fls_LengthType, AUTOMATIC) MaxLength)
{
    VAR(Fls_AddressType, AUTOMATIC) processAddrEnd = Fls_JobOperateAddrEnd;

    if (processAddrEnd >= (Fls_JobOperateAddrStart + MaxLength))
    {
        processAddrEnd = (Fls_JobOperateAddrStart + MaxLength);
    }
    else
    {
        /* deliberately left blank to avoid QAC violation *
         * (Rule 2000 ) */
    }

    return (processAddrEnd);
}

/**
 * @brief job read data process
 * @param ProcessAddr process address
 * @param ReadLength read length
 * @return Fls_InterReturnType
 * @retval FLS_INTER_E_OK
 * @retval FLS_INTER_E_FAILED
 * @retval FLS_INTER_E_PENDING
 */
static FUNC(Fls_InterReturnType, FLS_CODE)
  Fls_JobReadProcess(CONST(Fls_AddressType, AUTOMATIC) ProcessAddr, CONST(Fls_AddressType, AUTOMATIC) ReadLength)
{
    VAR(Fls_InterReturnType, AUTOMATIC) retVal;

    /* sector read */
    retVal = Fls_Im_SectorRead(ProcessAddr, ReadLength, Fls_JobDataDestPtr);

    /* Do physical sector read */
    if (FLS_INTER_E_FAILED == retVal)
    {
#if (FLS_RUNTIME_ERROR_DETECT == STD_ON)
        (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_READ_FAILED);
#endif
    }
    else
    {
        /* deliberately left blank to avoid QAC violation *
         * (Rule 2000 ) */
    }
    return (retVal);
}

/**
 * @brief process write operate
 * @param ProcessAddr process address
 * @param WriteLength write length
 * @return Fls_InterReturnType
 * @retval FLS_INTER_E_OK
 * @retval FLS_INTER_E_FAILED
 * @retval FLS_INTER_E_PENDING
 */
static FUNC(Fls_InterReturnType, FLS_CODE)
  Fls_JobProcessWrite(CONST(Fls_AddressType, AUTOMATIC) ProcessAddr, CONST(Fls_AddressType, AUTOMATIC) WriteLength)
{
    VAR(Fls_InterReturnType, AUTOMATIC) retVal;

    /* sector write */
    retVal = Fls_Im_SectorWrite(ProcessAddr, WriteLength, Fls_JobDataSrcPtr);

    if (FLS_INTER_E_FAILED == retVal)
    {
#if (FLS_RUNTIME_ERROR_DETECT == STD_ON)
        (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_WRITE_FAILED);
#endif
    }
    else
    {
        /* deliberately left blank to avoid QAC violation *
         * (Rule 2000 ) */
    }
    return (retVal);
}

#if (FLS_COMPARE_API == STD_ON)
/**
 * @brief job compare data process
 * @param ProcessAddr process address
 * @param CompareLength compare data length
 * @return Fls_InterReturnType
 * @retval FLS_INTER_E_OK
 * @retval FLS_INTER_E_FAILED
 * @retval FLS_INTER_E_INCONSISTENT
 * @retval FLS_INTER_E_PENDING
 */
static FUNC(Fls_InterReturnType, FLS_CODE)
  Fls_JobCompareProcess(CONST(Fls_AddressType, AUTOMATIC) ProcessAddr, VAR(Fls_AddressType, AUTOMATIC) CompareLength)
{
    VAR(Fls_InterReturnType, AUTOMATIC) retVal;

    /* sector data compare */
    retVal = Fls_Im_SectorCompare(ProcessAddr, CompareLength, Fls_JobDataSrcPtr);

    if (FLS_INTER_E_FAILED == retVal)
    {
#if (FLS_RUNTIME_ERROR_DETECT == STD_ON)
        (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_COMPARE_FAILED);
#endif
    }
    else
    {
        /* deliberately left blank to avoid QAC violation *
         * (Rule 2000 ) */
    }
    return (retVal);
}
#endif

#if (FLS_BLANK_CHECK_API == STD_ON)
/**
 * @brief check job blank data
 * @param ProcessAddr process address
 * @param Length check data length
 * @return Fls_InterReturnType
 * @retval FLS_INTER_E_OK
 * @retval FLS_INTER_E_FAILED
 * @retval FLS_INTER_E_INCONSISTENT
 * @retval FLS_INTER_E_PENDING
 */
static FUNC(Fls_InterReturnType, FLS_CODE)
  Fls_JobBlankCheckProcess(CONST(Fls_AddressType, AUTOMATIC) ProcessAddr, VAR(Fls_AddressType, AUTOMATIC) Length)
{
    VAR(Fls_InterReturnType, AUTOMATIC) retVal;

    /* sector data compare */
    retVal = Fls_Im_SectorCompare(ProcessAddr, Length, NULL_PTR);

    if (FLS_INTER_E_FAILED == retVal)
    {
#if (FLS_RUNTIME_ERROR_DETECT == STD_ON)
        (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_BLANK_CHECK_ID, FLS_E_COMPARE_FAILED);
#endif
    }
    else
    {
        /* deliberately left blank to avoid QAC violation *
         * (Rule 2000 ) */
    }

    return (retVal);
}
#endif

/**
 * @brief job read,write,compare process
 * @param OperateType operate type
 * @param MaxLength data length
 * @return MemIf_JobResultType
 * @retval MEMIF_JOB_PENDING
 * @retval MEMIF_JOB_OK
 * @retval MEMIF_JOB_FAILED
 * @retval MEMIF_BLOCK_INCONSISTENT
 */
static FUNC(MemIf_JobResultType, FLS_CODE)
  Fls_JobDataProcess(CONST(Fls_JobOperateType, AUTOMATIC) OperateType, CONST(Fls_LengthType, AUTOMATIC) MaxLength)
{
    VAR(MemIf_JobResultType, AUTOMATIC) retVal = MEMIF_JOB_PENDING;

    /* No more data to write */
    if (Fls_JobOperateAddrStart >= Fls_JobOperateAddrEnd)
    {
        retVal = MEMIF_JOB_OK;
    }
    else
    {
        VAR(Fls_AddressType, AUTOMATIC) dataProcessAddrEnd;
        VAR(Fls_InterReturnType, AUTOMATIC) processRstVal = FLS_INTER_E_FAILED;

        /* calculate process end address */
        dataProcessAddrEnd = Fls_CalcDataProcessAddrEnd(MaxLength);

        do
        {
            VAR(Fls_AddressType, AUTOMATIC) jobProcessLength;

            /* calculate sector offset */
            jobProcessLength = (dataProcessAddrEnd - Fls_JobOperateAddrStart);

            switch (OperateType)
            {
            case FLS_JOB_WRITE:
                processRstVal = Fls_JobProcessWrite(Fls_JobOperateAddrStart, jobProcessLength);
                Fls_JobDataSrcPtr += jobProcessLength;
                break;

            case FLS_JOB_READ:
                processRstVal = Fls_JobReadProcess(Fls_JobOperateAddrStart, jobProcessLength);
                Fls_JobDataDestPtr += jobProcessLength;
                break;

#if (FLS_COMPARE_API == STD_ON)
            case FLS_JOB_COMPARE:
                processRstVal = Fls_JobCompareProcess(Fls_JobOperateAddrStart, jobProcessLength);
                Fls_JobDataSrcPtr += jobProcessLength;
                break;
#endif

#if (FLS_BLANK_CHECK_API == STD_ON)
            case FLS_JOB_BLANK_CHECK:
                processRstVal = Fls_JobBlankCheckProcess(Fls_JobOperateAddrStart, jobProcessLength);
                break;
#endif
                /* PRQA S 2016 1 #KQR002016  */
            default:
                break;
            }

            Fls_JobOperateAddrStart += jobProcessLength;
        } while ((Fls_JobOperateAddrStart < dataProcessAddrEnd) && (FLS_INTER_E_OK == processRstVal));

        if (FLS_INTER_E_FAILED == processRstVal)
        {
            retVal = MEMIF_JOB_FAILED;
        }
        else if (FLS_INTER_E_INCONSISTENT == processRstVal)
        {
            retVal = MEMIF_BLOCK_INCONSISTENT;
        }
        else if ((Fls_JobOperateAddrStart >= Fls_JobOperateAddrEnd) && (FLS_INTER_E_OK == processRstVal))
        {
            retVal = MEMIF_JOB_OK;
        }
        else
        {
            /* deliberately left blank to avoid QAC violation *
             * (Rule 2000 ) */
        }
    }

    return (retVal);
}

/**
 * @brief Initializes the Flash Driver.
 * @details
 * Service name: Fls_Init
 * Syntax: void Fls_Init (const Fls_ConfigType* ConfigPtr)
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * @implements #SWS_Fls_00014,#SWS_Fls_00191,#SWS_Fls_00086,#SWS_Fls_00015,#SWS_Fls_00323,
 * #SWS_Fls_00324,#SWS_Fls_00268,#SWS_Fls_00048
 * TODO:#SWS_Fls_00048 maybe implement by software
 * @param ConfigPtr Pointer to flash driver configuration set.
 * @retval void
 * @return void
 */
FUNC(void, FLS_CODE) Fls_Init(P2CONST(Fls_ConfigType, FLS_VAR, FLS_APPL_CONST) ConfigPtr)
{
#if (FLS_DEV_ERROR_DETECT == STD_ON)
#if (FLS_PRECOMPILE_SUPPORT == STD_ON)
    if (NULL_PTR != ConfigPtr)
#else
    if (NULL_PTR == ConfigPtr)
#endif
    {
        /* @implements #SWS_Fls_00015 */
        (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_INIT_ID, FLS_E_PARAM_CONFIG);
    }
    else if (MEMIF_UNINIT != Fls_ModuleState)
    {
        /* @implements #SWS_Fls_00268 */
        (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_INIT_ID, FLS_E_ALREADY_INITIALIZED);
    }
    else
    {
#endif
        /* @implements #SWS_Fls_00191 */
#if (FLS_PRECOMPILE_SUPPORT == STD_ON)
        Fls_CurrentConfigPtr = &Fls_ConfigPredefined;
        (void)ConfigPtr;
#else
    Fls_CurrentConfigPtr = ConfigPtr;
#endif

        /* @implements #SWS_Fls_00086 */
        /* Set the max number of bytes to read/write */
        if (MEMIF_MODE_SLOW == Fls_CurrentConfigPtr->DefaultMode)
        {
            Fls_MaxRead  = Fls_CurrentConfigPtr->ReadNormalSize;
            Fls_MaxWrite = Fls_CurrentConfigPtr->WriteNormalSize;
        }
        else
        {
            Fls_MaxRead  = Fls_CurrentConfigPtr->ReadFastSize;
            Fls_MaxWrite = Fls_CurrentConfigPtr->WriteFastSize;
        }

        /* @implements #SWS_Fls_00014 */
        Fls_Im_Init();
        if (MEMIF_JOB_FAILED == Fls_JobOperateStatus)
        {
            Fls_JobResult        = MEMIF_JOB_FAILED;
            Fls_CurrentConfigPtr = NULL_PTR;
        }
        else
        {
            /* @implements #SWS_Fls_00323 */
            Fls_ModuleState = MEMIF_IDLE;
            /* @implements #SWS_Fls_00324 */
            Fls_JobResult = MEMIF_JOB_OK;
        }
#if (FLS_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}

/**
 * @brief Erases flash sector(s).
 * @details
 * Service name: Fls_Erase
 * Syntax: Std_ReturnType Fls_Erase (Fls_AddressType TargetAddress,Fls_LengthType Length)
 * Service ID[hex]: 0x01
 * Sync/Async: Asynchronous
 * Reentrancy: Non Reentrant
 * @implements #SWS_Fls_00218,#SWS_Fls_00327,#SWS_Fls_00328,#SWS_Fls_00329,#SWS_Fls_00330,
 * #SWS_Fls_00220,#SWS_Fls_00221,#SWS_Fls_00020,#SWS_Fls_00021,#SWS_Fls_00065,#SWS_Fls_00023
 * @todo #SWS_Fls_00145
 * @param TargetAddress Target address in flash memory. This address offset will be added to the flash memory base
 * address. Min.: 0 Max.: FLS_SIZE - 1
 * @param Length Number of bytes to erase Min.: 1 Max.: FLS_SIZE - Target Address
 * @return Std_ReturnType
 * @retval E_OK: erase command has been accepted
 * @retval E_NOT_OK: erase command has not been accepted
 */
FUNC(Std_ReturnType, FLS_CODE)
Fls_Erase(VAR(Fls_AddressType, AUTOMATIC) TargetAddress, VAR(Fls_LengthType, AUTOMATIC) Length)
{
    /* @implements #SWS_Fls_00218 */
    VAR(Std_ReturnType, AUTOMATIC) retVal;

#if (FLS_DEV_ERROR_DETECT == STD_ON)
    if (MEMIF_UNINIT == Fls_ModuleState)
    {
        /* @implements #SWS_Fls_00065 */
        (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_ERASE_ID, FLS_E_UNINIT);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    else if ((boolean)FALSE == (Fls_CheckAddrSectorAligned((Fls_AddressType)TargetAddress)))
    {
        /* @implements #SWS_Fls_00020 */
        (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_ERASE_ID, FLS_E_PARAM_ADDRESS);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    else if ((0U == Length) ||
             ((boolean)FALSE == (Fls_CheckAddrSectorAligned((Fls_AddressType)TargetAddress + Length))))
    {
        /* @implements #SWS_Fls_00021 */
        (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_ERASE_ID, FLS_E_PARAM_LENGTH);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    else
#endif
    {
        SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_00();
        if (MEMIF_JOB_PENDING == Fls_JobResult)
        {
            /* @implements #SWS_Fls_00023 */
#if (FLS_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_ERASE_ID, FLS_E_BUSY);
#endif
            retVal = (Std_ReturnType)E_NOT_OK;
            SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_00();
        }
        else
        {
            /* @implements #SWS_Fls_00327,#SWS_Fls_00221 */
            Fls_JobOperateAddrStart = TargetAddress;
            Fls_JobOperateAddrEnd   = (TargetAddress + Length);

            Fls_JobOperate     = FLS_JOB_ERASE;
            Fls_JobStartStatus = TRUE;
            /* Execute the erase job */
            /* @implements #SWS_Fls_00329 */
            Fls_JobResult = MEMIF_JOB_PENDING;
            /* @implements #SWS_Fls_00328 */
            Fls_ModuleState = MEMIF_BUSY;
            /* @implements #SWS_Fls_00330 */
            retVal = (Std_ReturnType)E_OK;
            SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_00();
        }
    }

    return (retVal);
}

/**
 * @brief Writes one or more complete flash pages
 * @details
 * Service name: Fls_Write
 * Syntax: Std_ReturnType Fls_Write (Fls_AddressType TargetAddress,const uint8* SourceAddressPtr,Fls_LengthType Length)
 * Service ID[hex]: 0x02
 * Sync/Async: Asynchronous
 * Reentrancy: Non Reentrant
 * @implements #SWS_Fls_00223,#SWS_Fls_00331,#SWS_Fls_00332,#SWS_Fls_00333,#SWS_Fls_00334,
 * #SWS_Fls_00225,#SWS_Fls_00226,#SWS_Fls_00026,#SWS_Fls_00027,#SWS_Fls_00066,#SWS_Fls_00030,#SWS_Fls_00157
 * @todo #SWS_Fls_00146
 * @param TargetAddress Target address in flash memory. This address offset will be added
 * to the flash memory base address. Min.: 0 Max.: FLS_SIZE - 1
 * @param SourceAddressPtr Pointer to source data buffer
 * @param Length Number of bytes to write Min.: 1 Max.: FLS_SIZE - TargetAddress
 * @return Std_ReturnType
 * @retval E_NOT_OK:write command has not been accepted
 * @retval E_OK:write command has been accepted
 */
FUNC(Std_ReturnType, FLS_CODE)
Fls_Write(VAR(Fls_AddressType, AUTOMATIC) TargetAddress, P2CONST(uint8, FLS_VAR, FLS_APPL_CONST) SourceAddressPtr,
          VAR(Fls_LengthType, AUTOMATIC) Length)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal;

#if (FLS_DEV_ERROR_DETECT == STD_ON)
    if (MEMIF_UNINIT == Fls_ModuleState)
    {
        /* @implements #SWS_Fls_00066 */
        (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_WRITE_ID, FLS_E_UNINIT);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    else if ((boolean)FALSE == (Fls_CheckAddrPageAligned((Fls_AddressType)TargetAddress)))
    {
        /* @implements #SWS_Fls_00026 */
        (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_WRITE_ID, FLS_E_PARAM_ADDRESS);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    else if ((0U == Length) || ((boolean)FALSE == (Fls_CheckAddrPageAligned(TargetAddress + Length))))
    {
        /* @implements #SWS_Fls_00027 */
        (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_WRITE_ID, FLS_E_PARAM_LENGTH);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    else if (NULL_PTR == SourceAddressPtr)
    {
        /* @implements #SWS_Fls_00157 */
        (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_WRITE_ID, FLS_E_PARAM_DATA);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    else
#endif
    {
        SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_00();
        if (MEMIF_JOB_PENDING == Fls_JobResult)
        {
            /* @implements #SWS_Fls_00030 */
#if (FLS_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_WRITE_ID, FLS_E_BUSY);
#endif
            retVal = (Std_ReturnType)E_NOT_OK;
            SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_00();
        }
        else
        {
            /* @implements #SWS_Fls_00226,#SWS_Fls_00331 */
            Fls_JobOperateAddrStart = TargetAddress;
            Fls_JobOperateAddrEnd   = (TargetAddress + Length);

            Fls_JobDataSrcPtr  = SourceAddressPtr;
            Fls_JobOperate     = FLS_JOB_WRITE;
            Fls_JobStartStatus = TRUE;

            /* @implements #SWS_Fls_00333 */
            Fls_JobResult = MEMIF_JOB_PENDING;
            /* @implements #SWS_Fls_00332 */
            Fls_ModuleState = MEMIF_BUSY;
            /* @implements #SWS_Fls_00334 */
            retVal = (Std_ReturnType)E_OK;
            SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_00();
        }
    }

    return (retVal);
}

/* @implements #SWS_Fls_00183 */
#if (FLS_CANCEL_API == STD_ON)
/**
 * @brief Cancels an ongoing job
 * @details
 * Service name: Fls_Cancel
 * Syntax: void Fls_Cancel (void)
 * Service ID[hex]: 0x03
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * @implements #SWS_Fls_00229,#SWS_Fls_00230,#SWS_Fls_00335,#SWS_Fls_00336,#SWS_Fls_00033,
 * #SWS_Fls_00147,#SWS_Fls_00183,#SWS_Fls_00356
 * @param None
 * @retval None
 * @return None
 */
FUNC(void, FLS_CODE) Fls_Cancel(void)
{
#if (FLS_DEV_ERROR_DETECT == STD_ON)
    if (MEMIF_UNINIT == Fls_ModuleState)
    {
        /* @implements #SWS_Fls_00356 */
        (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_CANCEL_ID, FLS_E_UNINIT);
    }
    else
    {
#endif
        /* @implements #SWS_Fls_00336 */
        Fls_ModuleState = MEMIF_IDLE;
        /* @implements #SWS_Fls_00033 */
        if (MEMIF_JOB_PENDING == Fls_JobResult)
        {
            Fls_JobResult = MEMIF_JOB_CANCELED;

            if (MEMIF_JOB_PENDING == Fls_JobOperateStatus)
            {
                /* @implements #SWS_Fls_00229,#SWS_Fls_00230 */
                Fls_Im_Cancel();
            }
            else
            {
                /* @implements #SWS_Fls_00335 */
                Fls_JobOperateStatus = MEMIF_JOB_CANCELED;
            }
#if (FLS_AC_LOAD_ON_JOB_START == STD_ON)
            if ((FLS_JOB_ERASE == Fls_JobOperate) || (FLS_JOB_WRITE == Fls_JobOperate))
            {
                Fls_UnloadAccessCode(Fls_JobOperate);
            }
            else
            {
                /* deliberately left blank to avoid QAC violation *
                 * (Rule 2000 ) */
            }
#endif
            if (MEMIF_JOB_CANCELED == Fls_JobOperateStatus)
            {
                /* set status to canceled */
                Fls_JobResult = MEMIF_JOB_CANCELED;
            }
            else
            {
                /* deliberately left blank to avoid QAC violation *
                 * (Rule 2000 ) */
            }

            if (NULL_PTR != Fls_CurrentConfigPtr->JobErrorNotificationPtr)
            {
                /* @implements #SWS_Fls_00147 */
                Fls_CurrentConfigPtr->JobErrorNotificationPtr();
            }
            else
            {
                /* deliberately left blank to avoid QAC violation *
                 * (Rule 2000 ) */
            }
        }
        else
        {
            /* deliberately left blank to avoid QAC violation *
             * (Rule 2000 ) */
        }
#if (FLS_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}
#endif

/* @implements #SWS_Fls_00184 */
#if (FLS_GET_STATUS_API == STD_ON)
/**
 * @brief Returns the result of the last job.
 * @details
 * Service name: Fls_GetStatus
 * Syntax: MemIf_StatusType Fls_GetStatus (void)
 * Service ID[hex]: 0x04
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * @implements #SWS_Fls_00034,#SWS_Fls_00184
 * @param None
 * @return MemIf_StatusType
 * @retval MEMIF_UNINIT
 * @retval MEMIF_IDLE
 * @retval MEMIF_BUSY
 */
FUNC(MemIf_StatusType, FLS_CODE) Fls_GetStatus(void)
{
    /* @implements #SWS_Fls_00034 */
    return Fls_ModuleState;
}
#endif

/* @implements #SWS_Fls_00185 */
#if (FLS_GET_JOB_RESULT_API == STD_ON)
/**
 * @brief Returns the result of the last job.
 * @details
 * Service name: Fls_GetJobResult
 * Syntax: MemIf_JobResultType Fls_GetJobResult (void)
 * Service ID[hex]: 0x05
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * @implements #SWS_Fls_00035,#SWS_Fls_00036,#SWS_Fls_00185,#SWS_Fls_00358
 * @param None
 * @return MemIf_JobResultType
 * @retval MEMIF_JOB_OK
 * @retval MEMIF_JOB_FAILED
 * @retval MEMIF_JOB_PENDING
 * @retval MEMIF_JOB_CANCELED
 * @retval MEMIF_BLOCK_INVALID
 * @retval MEMIF_BLOCK_INCONSISTENT
 */
FUNC(MemIf_JobResultType, FLS_CODE) Fls_GetJobResult(void)
{
    /* @implements #SWS_Fls_00035 */
    VAR(MemIf_JobResultType, AUTOMATIC) retVal;

#if (FLS_DEV_ERROR_DETECT == STD_ON)
    if (MEMIF_UNINIT == Fls_ModuleState)
    {
        /* @implements #SWS_Fls_00358 */
        (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_GETJOBRESULT_ID, FLS_E_UNINIT);
        retVal = MEMIF_JOB_FAILED;
    }
    else
#endif
    {
        /* @implements #SWS_Fls_00036 */
        retVal = Fls_JobResult;
    }
    return retVal;
}
#endif

/**
 * @brief Compares the contents of an area of flash memory with that of an application data buffer.
 * @details
 * Service name: Fls_Read
 * Syntax: Std_ReturnType Fls_Read (Fls_AddressType SourceAddress,uint8* TargetAddressPtr,Fls_LengthType Length)
 * Service ID[hex]: 0x07
 * Sync/Async: Asynchronous
 * Reentrancy: Non Reentrant
 * @implements #SWS_Fls_00236,#SWS_Fls_00338,#SWS_Fls_00339,#SWS_Fls_00340,#SWS_Fls_00238,
 * #SWS_Fls_00239,#SWS_Fls_00097,#SWS_Fls_00098,#SWS_Fls_00099,#SWS_Fls_00100,#SWS_Fls_00158,
 * #SWS_Fls_00240
 * @param SourceAddress Source address in flash memory. This address offset will be added to the flash memory base
 * address. Min.: 0 Max.: FLS_SIZE - 1
 * @param TargetAddressPtr Pointer to target data buffer
 * @param Length Number of bytes to read Min.: 1 Max.: FLS_SIZE - Source Address
 * @return Std_ReturnType
 * @retval E_OK: read command has been accepted
 * @retval E_NOT_OK: read command has not been accepted
 */
FUNC(Std_ReturnType, FLS_CODE)
Fls_Read(VAR(Fls_AddressType, AUTOMATIC) SourceAddress, P2VAR(uint8, FLS_VAR, FLS_APPL_DATA) TargetAddressPtr,
         VAR(Fls_LengthType, AUTOMATIC) Length)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal;

#if (FLS_DEV_ERROR_DETECT == STD_ON)
    if (MEMIF_UNINIT == Fls_ModuleState)
    {
        /* @implements #SWS_Fls_0009,#SWS_Fls_00240 */
        (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_READ_ID, FLS_E_UNINIT);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    else if (SourceAddress >= FLS_TOTAL_SIZE)
    {
        /* @implements #SWS_Fls_00097 */
        (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_READ_ID, FLS_E_PARAM_ADDRESS);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    else if ((0U == Length) || ((SourceAddress + Length) > FLS_TOTAL_SIZE))
    {
        /* @implements #SWS_Fls_00098 */
        (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_READ_ID, FLS_E_PARAM_LENGTH);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    else if (NULL_PTR == TargetAddressPtr)
    {
        /* @implements #SWS_Fls_00158 */
        (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_READ_ID, FLS_E_PARAM_DATA);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    else
#endif
    {
        SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_00();
        if (MEMIF_JOB_PENDING == Fls_JobResult)
        {
            /* @implements #SWS_Fls_00100 */
#if (FLS_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_READ_ID, FLS_E_BUSY);
#endif
            retVal = (Std_ReturnType)E_NOT_OK;
            SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_00();
        }
        else
        {
            /* @implements #SWS_Fls_00100,#SWS_Fls_00239 */
            Fls_JobOperateAddrStart = SourceAddress;
            Fls_JobOperateAddrEnd   = (SourceAddress + Length);
            Fls_JobDataDestPtr      = (P2VAR(uint8, FLS_VAR, FLS_APPL_DATA))TargetAddressPtr;
            Fls_JobOperate          = FLS_JOB_READ;
            Fls_JobStartStatus      = TRUE;
            /* @implements #SWS_Fls_00339 */
            Fls_JobResult = MEMIF_JOB_PENDING;
            /* @implements #SWS_Fls_00338 */
            Fls_ModuleState = MEMIF_BUSY;
            /* @implements #SWS_Fls_00340 */
            retVal = (Std_ReturnType)E_OK;
            SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_00();
        }
    }

    return (retVal);
}

/* @implements #SWS_Fls_00186 */
#if (FLS_COMPARE_API == STD_ON)
/**
 * @brief Compares the contents of an area of flash memory with that of an application data buffer.
 * @details
 * Service name: Fls_Compare
 * Syntax: Std_ReturnType Fls_Compare (Fls_AddressType SourceAddress,const uint8* TargetAddressPtr,Fls_LengthType
 * Length)
 * Service ID[hex]: 0x08
 * Sync/Async: Asynchronous
 * Reentrancy: Non Reentrant
 * @implements #SWS_Fls_00241,#SWS_Fls_00341,#SWS_Fls_00342,#SWS_Fls_00343,#SWS_Fls_00344,
 * #SWS_Fls_00243,#SWS_Fls_00244,#SWS_Fls_00150,#SWS_Fls_00151,#SWS_Fls_00152,#SWS_Fls_00153,
 * #SWS_Fls_00273,#SWS_Fls_00186
 * @param SourceAddress Source address in flash memory. This address offset will be added to the flash memory base
 * address. Min.: 0 Max.: FLS_SIZE - 1 MEMIF_MODE_FAST: Fast read access / SPI burst access.
 * @param TargetAddressPtr Pointer to target data buffer
 * @param Length Number of bytes to compare Min.: 1 Max.: FLS_SIZE - Source Address
 * @return Std_ReturnType
 * @retval E_OK: compare command has been accepted
 * @retval E_NOT_OK: compare command has not been accepted
 */
FUNC(Std_ReturnType, FLS_CODE)
Fls_Compare(VAR(Fls_AddressType, AUTOMATIC) SourceAddress, P2CONST(uint8, FLS_VAR, FLS_APPL_CONST) TargetAddressPtr,
            VAR(Fls_LengthType, AUTOMATIC) Length)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal;

#if (FLS_DEV_ERROR_DETECT == STD_ON)
    if (MEMIF_UNINIT == Fls_ModuleState)
    {
        /* @implements #SWS_Fls_00152 */
        (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_COMPARE_ID, FLS_E_UNINIT);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    else if (SourceAddress >= FLS_TOTAL_SIZE)
    {
        /* @implements #SWS_Fls_00150 */
        (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_COMPARE_ID, FLS_E_PARAM_ADDRESS);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    else if ((0U == Length) || ((SourceAddress + Length) > FLS_TOTAL_SIZE))
    {
        /* @implements #SWS_Fls_00151 */
        (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_COMPARE_ID, FLS_E_PARAM_LENGTH);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    else if (NULL_PTR == TargetAddressPtr)
    {
        /* @implements #SWS_Fls_00273 */
        (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_COMPARE_ID, FLS_E_PARAM_DATA);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    else
#endif
    {
        SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_00();
        if (MEMIF_JOB_PENDING == Fls_JobResult)
        {
            /* @implements #SWS_Fls_00153 */
#if (FLS_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_COMPARE_ID, FLS_E_BUSY);
#endif
            retVal = (Std_ReturnType)E_NOT_OK;
            SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_00();
        }
        else
        {
            /* @implements #SWS_Fls_00341,#SWS_Fls_00244 */
            Fls_JobOperateAddrStart = SourceAddress;
            Fls_JobOperateAddrEnd   = (SourceAddress + Length);
            Fls_JobDataSrcPtr       = TargetAddressPtr;
            Fls_JobOperate          = FLS_JOB_COMPARE;
            Fls_JobStartStatus      = TRUE;
            /* Execute the read job */
            /* @implements #SWS_Fls_00343 */
            Fls_JobResult = MEMIF_JOB_PENDING;
            /* @implements #SWS_Fls_00342 */
            Fls_ModuleState = MEMIF_BUSY;
            /* @implements #SWS_Fls_00344 */
            retVal = (Std_ReturnType)E_OK;
            SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_00();
        }
    }

    return (retVal);
}
#endif

/* @implements #SWS_Fls_00187 */
#if (FLS_SET_MODE_API == STD_ON)
/**
 * @brief Sets the flash driver  operation mode
 * @details
 * Service name: Fls_SetMode
 * Syntax: void Fls_SetMode (MemIf_ModeType Mode)
 * Service ID[hex]: 0x09
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * @implements #SWS_Fls_00155,#SWS_Fls_00156,#SWS_Fls_00187
 * @param Mode MEMIF_MODE_SLOW: Slow read access / normal SPI access.
 * MEMIF_MODE_FAST: Fast read access / SPI burst access.
 * @return None
 * @retval None
 */
FUNC(void, FLS_CODE) Fls_SetMode(VAR(MemIf_ModeType, AUTOMATIC) Mode)
{
#if (FLS_DEV_ERROR_DETECT == STD_ON)
    if (MEMIF_UNINIT == Fls_ModuleState)
    {
        (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SETMODE_ID, FLS_E_UNINIT);
    }
    else if (MEMIF_JOB_PENDING == Fls_JobResult)
    {
        /* @implements #SWS_Fls_00156 */
        (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SETMODE_ID, FLS_E_BUSY);
    }
    else
    {
#endif
        /* @implements #SWS_Fls_00155 */
        switch (Mode)
        {
        case MEMIF_MODE_FAST:
            Fls_MaxRead  = Fls_CurrentConfigPtr->ReadFastSize;
            Fls_MaxWrite = Fls_CurrentConfigPtr->WriteFastSize;
            break;

        case MEMIF_MODE_SLOW:
            Fls_MaxRead  = Fls_CurrentConfigPtr->ReadNormalSize;
            Fls_MaxWrite = Fls_CurrentConfigPtr->WriteNormalSize;
            break;
            /* PRQA S 2016 1 #KQR002016  */
        default:
            break;
        }
#if (FLS_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}
#endif

#if (FLS_VERSION_INFO_API == STD_ON)
/**
 * @brief Returns the version information of this module
 * @details
 * Service name: Fls_GetVersionInfo
 * Syntax: void Fls_GetVersionInfo (Std_VersionInfoType* VersioninfoPtr)
 * Service ID[hex]: 0x10
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * @implements #SWS_Fls_00363
 * @param VersionInfoPtr Pointer to where to store the version information of this module
 * @return None
 * @retval None
 */
FUNC(void, FLS_CODE) Fls_GetVersionInfo(P2VAR(Std_VersionInfoType, FLS_VAR, FLS_APPL_DATA) VersionInfoPtr)
{
#if (FLS_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == VersionInfoPtr)
    {
        /* @implements #SWS_Fls_00363 */
        (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_GETVERSIONINFO_ID, FLS_E_PARAM_POINTER);
    }
    else
    {
#endif
        VersionInfoPtr->vendorID         = (uint16)FLS_VENDOR_ID;
        VersionInfoPtr->moduleID         = (uint16)FLS_MODULE_ID;
        VersionInfoPtr->sw_major_version = (uint8)FLS_SW_MAJOR_VERSION;
        VersionInfoPtr->sw_minor_version = (uint8)FLS_SW_MINOR_VERSION;
        VersionInfoPtr->sw_patch_version = (uint8)FLS_SW_PATCH_VERSION;
#if (FLS_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}
#endif

#if (FLS_BLANK_CHECK_API == STD_ON)
/**
 * @brief The function Fls_BlankCheck shall verify, whether a given memory area has been erased but not (yet)
 * programmed. The function shall limit the maximum number of checked flash cells per main function cycle to the
 * configured value FlsMaxReadNormalMode or FlsMaxReadFastMode respectively.
 * @details
 * Service name: Fls_BlankCheck
 * Syntax: Std_ReturnType Fls_BlankCheck (Fls_AddressType TargetAddress,Fls_LengthType Length)
 * Service ID[hex]: 0x0a
 * Sync/Async: Asynchronous
 * Reentrancy: Non Reentrant
 * @implements #SWS_Fls_00373,#SWS_Fls_00374,#SWS_Fls_00375,#SWS_Fls_00039,#SWS_Fls_00377,
 * #SWS_Fls_00378,#SWS_Fls_00379,#SWS_Fls_00380,#SWS_Fls_00381,#SWS_Fls_00382,#SWS_Fls_00383,
 * #SWS_Fls_00055,#SWS_Fls_00056,#SWS_Fls_00345,#SWS_Fls_00346,#SWS_Fls_00232,#SWS_Fls_00233,
 * @param TargetAddress Address in flash memory from which the blank check should be started. Min.: 0 Max.: FLS_SIZE - 1
 * @param Length Number of bytes to be checked for erase pattern. Min.: 1 Max.:FLS_SIZE - TargetAddress
 * @return Std_ReturnType
 * @retval E_OK: request for blank checking has been accepted by the module
 * @retval E_NOT_OK: request for blank checking has not been accepted by the module
 */
FUNC(Std_ReturnType, FLS_CODE)
Fls_BlankCheck(VAR(Fls_AddressType, AUTOMATIC) TargetAddress, VAR(Fls_LengthType, AUTOMATIC) Length)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal;

#if (FLS_DEV_ERROR_DETECT == STD_ON)
    if (MEMIF_UNINIT == Fls_ModuleState)
    {
        /* @implements #SWS_Fls_00382 */
        (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_BLANK_CHECK_ID, FLS_E_UNINIT);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    else if (TargetAddress >= FLS_TOTAL_SIZE)
    {
        /* @implements #SWS_Fls_00380 */
        (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_BLANK_CHECK_ID, FLS_E_PARAM_ADDRESS);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    else if ((0U == Length) || ((TargetAddress + Length) > FLS_TOTAL_SIZE))
    {
        /* @implements #SWS_Fls_00381 */
        (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_BLANK_CHECK_ID, FLS_E_PARAM_LENGTH);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    else
#endif
    {
        SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_00();
        if (MEMIF_JOB_PENDING == Fls_JobResult)
        {
            /* @implements #SWS_Fls_00383 */
#if (FLS_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_BLANK_CHECK_ID, FLS_E_BUSY);
#endif
            retVal = (Std_ReturnType)E_NOT_OK;
            SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_00();
        }
        else
        {
            /* @implements #SWS_Fls_00373,#SWS_Fls_00374,#SWS_Fls_00379 */
            Fls_JobOperateAddrStart = TargetAddress;
            Fls_JobOperateAddrEnd   = (TargetAddress + Length);
            Fls_JobOperate          = FLS_JOB_BLANK_CHECK;
            Fls_JobStartStatus      = TRUE;
            /* Execute the read job */
            /* @implements #SWS_Fls_00376 */
            Fls_JobResult = MEMIF_JOB_PENDING;
            /* @implements #SWS_Fls_00375 */
            Fls_ModuleState = MEMIF_BUSY;
            /* @implements #SWS_Fls_00377 */
            retVal = (Std_ReturnType)E_OK;
            SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_00();
        }
    }

    return (retVal);
}
#endif

/**
 * @brief Performs the processing of jobs.
 * @details
 * Service name: Fls_MainFunction
 * Syntax: void Fls_MainFunction(void)
 * Service ID[hex]: 0x06
 * @implements #SWS_Fls_00255,#SWS_Fls_00037,#SWS_Fls_00038,#SWS_Fls_00039,#SWS_Fls_00040,
 * #SWS_Fls_00104,#SWS_Fls_00105,#SWS_Fls_00106,#SWS_Fls_00154,#SWS_Fls_00200,#SWS_Fls_00022,
 * #SWS_Fls_00055,#SWS_Fls_00056,#SWS_Fls_00345,#SWS_Fls_00346,#SWS_Fls_00232,#SWS_Fls_00233,
 * #SWS_Fls_00234,#SWS_Fls_00235,#SWS_Fls_00272,#SWS_Fls_00359,#SWS_Fls_00360,,#SWS_Fls_00362,
 * #SWS_Fls_00117,SWS_Fls_00196
 * @param None
 * @retval None
 * @return None
 */
FUNC(void, FLS_CODE) Fls_MainFunction(void)
{
    /* @implements #SWS_Fls_00037,#SWS_Fls_00038,#SWS_Fls_00235 */
#if (FLS_DEV_ERROR_DETECT == STD_ON)
    if (MEMIF_UNINIT == Fls_ModuleState)
    {
        /* @implements #SWS_Fls_00117 */
        (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_UNINIT);
    }
    else
    {
#endif
        if (MEMIF_JOB_PENDING == Fls_JobResult)
        {
            VAR(MemIf_JobResultType, AUTOMATIC) processRst = MEMIF_BLOCK_INVALID;

            if (TRUE == Fls_JobStartStatus)
            {
                Fls_JobStartStatus = FALSE;
                /* set job status */
                Fls_JobOperateStatus = MEMIF_JOB_OK;

#if (FLS_AC_LOAD_ON_JOB_START == STD_ON)
                /* Load position independent access code */
                if ((FLS_JOB_ERASE == Fls_JobOperate) || (FLS_JOB_WRITE == Fls_JobOperate))
                {
                    Fls_LoadAccessCode(Fls_JobOperate);
                }
                else
                {
                    /* deliberately left blank to avoid QAC violation *
                     * (Rule 2000 ) */
                }
#endif
            }
            else
            {
                /* deliberately left blank to avoid QAC violation *
                 * (Rule 2000 ) */
            }

            if (MEMIF_JOB_OK == Fls_JobOperateStatus)
            {
                /* PRQA S 2032 1 #KQR002032  */
                switch (Fls_JobOperate)
                {
                case FLS_JOB_ERASE:
                    /* @implements #SWS_Fls_00220 */
                    processRst = Fls_JobEraseProcess();
                    break;
                case FLS_JOB_WRITE:
                    /* @implements #SWS_Fls_00040 */
                    processRst = Fls_JobDataProcess(Fls_JobOperate, Fls_MaxWrite);
                    break;
#if (FLS_BLANK_CHECK_API == STD_ON)
                case FLS_JOB_BLANK_CHECK:
                    /* @implements #SWS_Fls_00378 */
#endif
                case FLS_JOB_READ:
                    /* @implements #SWS_Fls_00238 */
#if (FLS_COMPARE_API == STD_ON)
                case FLS_JOB_COMPARE:
                    /* @implements #SWS_Fls_00243 */
#endif
                    /* @implements #SWS_Fls_00040 */
                    processRst = Fls_JobDataProcess(Fls_JobOperate, Fls_MaxRead);
                    break;
                    /* PRQA S 2016 1 #KQR002016  */
                default:
                    break;
                }
            }
            else
            {
                /* deliberately left blank to avoid QAC violation *
                 * (Rule 2000 ) */
            }

#if (FLS_AC_LOAD_ON_JOB_START == STD_ON)
            if ((MEMIF_JOB_PENDING != processRst) &&
                ((FLS_JOB_ERASE == Fls_JobOperate) || (FLS_JOB_WRITE == Fls_JobOperate)))
            {
                Fls_UnloadAccessCode(Fls_JobOperate);
            }
#endif

            Fls_JobResult = processRst;
            if (MEMIF_JOB_OK == processRst)
            {
                Fls_ModuleState = MEMIF_IDLE;
                if (NULL_PTR != Fls_CurrentConfigPtr->JobEndNotificationPtr)
                {
                    Fls_CurrentConfigPtr->JobEndNotificationPtr();
                }
                else
                {
                    /* deliberately left blank to avoid QAC violation *
                     * (Rule 2000 ) */
                }
            }
            else if ((MEMIF_JOB_FAILED == processRst) || (MEMIF_BLOCK_INCONSISTENT == processRst))
            {
                if (NULL_PTR != Fls_CurrentConfigPtr->JobErrorNotificationPtr)
                {
                    Fls_CurrentConfigPtr->JobErrorNotificationPtr();
                }
                else
                {
                    /* deliberately left blank to avoid QAC violation *
                     * (Rule 2000 ) */
                }
            }
            else
            {
                /* deliberately left blank to avoid QAC violation *
                 * (Rule 2000 ) */
            }
        }
        else
        {
            /* deliberately left blank to avoid QAC violation *
             * (Rule 2000 ) */
        }

#if (FLS_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}