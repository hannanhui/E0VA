/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Fls_Im.h
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
#ifndef FLS_IM_H
#define FLS_IM_H

#ifdef __cplusplus
extern "C" {
#endif

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
/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "Fls.h"

/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/

/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/

/******************************************************************************
 **                        Export Variables
 ******************************************************************************/
/**
 * @brief Result of last flash hardware job
 *
 */
extern VAR(volatile MemIf_JobResultType, FLS_VAR) Fls_JobOperateStatus;
/**
 * @brief Pointer to current flash
 */
extern P2CONST(Fls_ConfigType, FLS_VAR, FLS_APPL_CONST) Fls_CurrentConfigPtr;
#define FLS_START_SEC_VAR_INIT_32
/******************************************************************************
 **                        Export Functions
 ******************************************************************************/
/**
 * @brief Initialize flash hardware
 *
 * @return void
 * @retval void
 */
FUNC(void, FLS_CODE) Fls_Im_Init(void);

#if (FLS_CANCEL_API == STD_ON)
/**
 * @brief cancel erase or write operate
 *
 * @return void
 * @retval void
 */
FUNC(void, FLS_CODE) Fls_Im_Cancel(void);
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
Fls_Im_SectorErase(CONST(Fls_SectorIdType, AUTOMATIC) EraseAddr);

/**
 * @brief sector write
 *
 * @param ProcessAddr process address
 * @param DataLength write length
 * @param pDataPtr write data
 *
 * @return Fls_InterReturnType
 * @retval FLS_INTER_E_OK
 * @retval FLS_INTER_E_FAILED
 * @retval FLS_INTER_E_PENDING
 */
FUNC(Fls_InterReturnType, FLS_CODE)
Fls_Im_SectorWrite(CONST(Fls_AddressType, AUTOMATIC) ProcessAddr, CONST(Fls_LengthType, AUTOMATIC) WriteLength,
                   CONSTP2CONST(uint8, AUTOMATIC, FLS_APPL_CONST) WriteData);

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
                  P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) ReadData);

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
                     CONSTP2CONST(uint8, AUTOMATIC, FLS_APPL_CONST) CompareData);
#endif

#ifdef __cplusplus
}
#endif

#endif
