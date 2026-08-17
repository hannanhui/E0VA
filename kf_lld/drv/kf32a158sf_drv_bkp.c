/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name        : kf32a158sf_drv_bkp.c
 *  @Date             : 2025-07-18
 *  @Version          : {{VersionDate}}
 *  @Description      : This file provides
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 *****************************************************************************/
/******************************************************************************
 *  |Date        |Version  |Author       |Description
 *******************************************************************************
 *  |2025-07-18  |V1.0     |AE Group     |New create
 ******************************************************************************/

/******************************************************************************
 *                       QAC Warnings
 ******************************************************************************/
/* PRQA S 0288 EOF #KQR000288 */
/* PRQA S 0303,0306 EOF #KQR100303 */
/* PRQA S 1006,3006 EOF #KQR101006 */

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include "kf32a158sf_drv_bkp.h"
#include "kf32a158sf_drv_pm.h"
#include "kf32a158sf_drv_intr.h"
#include "kf32a158sf_drv_osc.h"

/******************************************************************************
 *                      Macro Definitions
 ******************************************************************************/

/******************************************************************************
 *                      Constants
 ******************************************************************************/

/******************************************************************************
 *                      Type definitions
 ******************************************************************************/

/******************************************************************************
 *                      Variables
 ******************************************************************************/
static volatile uint32_t BkpTotalEnterCounter = 0U;
static volatile uint32_t BkpPmEnterCounter    = 0U;

/******************************************************************************
 *                      Private Function definitions
 ******************************************************************************/

/******************************************************************************
 *                      Global Function definitions
 ******************************************************************************/

/**
 * @brief 备份域(BKP)寄存器开始读写
 *
 * @return void
 */
void Bkp_LL_HandleStart(void)
{
    uint32_t r = Intr_LL_EnterCritical();
    if (0U == BkpTotalEnterCounter)
    {
        Osc_LL_SetBackupWriteAndReadEnabled(true);
    }
    else
    { /*Empty*/
    }
    BkpTotalEnterCounter += 1U;
    Intr_LL_ExitCritical(r);
}

/**
 * @brief 备份域(BKP)寄存器结束读写
 *
 * @return void
 */
void Bkp_LL_HandleEnd(void)
{
    uint32_t r = Intr_LL_EnterCritical();

    if (0U != BkpTotalEnterCounter)
    {
        BkpTotalEnterCounter -= 1U;
    }
    else
    { /*Empty*/
    }

    if (0U == BkpTotalEnterCounter)
    {
        Osc_LL_SetBackupWriteAndReadEnabled(false);
    }
    else
    { /*Empty*/
    }
    Intr_LL_ExitCritical(r);
}

/**
 * @brief 备份域(BKP)PM寄存器开始读写
 *
 * @return void
 */
void Bkp_LL_PmRegisterHandleStart(void)
{
    uint32_t r = Intr_LL_EnterCritical();
    if (0U == BkpTotalEnterCounter)
    {
        Osc_LL_SetBackupWriteAndReadEnabled(true);
    }
    else
    { /*Empty*/
    }
    if (0U == BkpPmEnterCounter)
    {
        /** Enable write PMCTL and PMCAL */
        Osc_LL_SetPmControlRegisterLocked(false);
        Osc_LL_SetPmCalibrationRegisterLocked(false);
    }
    else
    { /*Empty*/
    }
    BkpTotalEnterCounter += 1U;
    BkpPmEnterCounter += 1U;
    Intr_LL_ExitCritical(r);
}

/**
 * @brief 备份域(BKP)PM寄存器结束读写
 *
 * @return void
 */
void Bkp_LL_PmRegisterHandleEnd(void)
{
    uint32_t r = Intr_LL_EnterCritical();

    if (0U != BkpTotalEnterCounter)
    {
        BkpTotalEnterCounter -= 1U;
    }
    else
    { /*Empty*/
    }
    if (0U != BkpPmEnterCounter)
    {
        BkpPmEnterCounter -= 1U;
    }
    else
    { /*Empty*/
    }

    if (0U == BkpPmEnterCounter)
    {
        /** Disable write PMCTL and PMCAL */
        Osc_LL_SetPmControlRegisterLocked(true);
        Osc_LL_SetPmCalibrationRegisterLocked(true);
    }
    else
    { /*Empty*/
    }
    if (0U == BkpTotalEnterCounter)
    {
        Osc_LL_SetBackupWriteAndReadEnabled(false);
    }
    else
    { /*Empty*/
    }
    Intr_LL_ExitCritical(r);
}

/**
 * @brief 设置BKP数据
 * @param Bkpx 指向BKPx寄存器结构的指针
 * @param Offset 偏移 0-7
 * @param Data 数据
 * @retval 无
 */
void Bkp_LL_SetBkpData(Bkp_RegisterMap_t *const Bkpx, uint32_t Offset, uint32_t Data)
{
    KF_BKP_ASSERT(CHECK_BKP_ALL_PERIPH_ADDR(Bkpx));
    KF_BKP_ASSERT(CHECK_BKP_DATAOFFSET(Offset));

    Bkp_LL_EnableDataRegisterReadWrite();

    Bkp_LL_HandleStart();
    Bkpx->BKPDATA[Offset] = Data;
    Bkp_LL_HandleEnd();
}

/**
 * @brief 获取BKP数据
 * @param Bkpx 指向BKPx寄存器结构的指针
 * @param Offset 偏移 0-7
 * @retval 无
 */
uint32_t Bkp_LL_GetBkpData(const Bkp_RegisterMap_t *const Bkpx, uint32_t Offset)
{
    KF_BKP_ASSERT(CHECK_BKP_ALL_PERIPH_ADDR(Bkpx));
    KF_BKP_ASSERT(CHECK_BKP_DATAOFFSET(Offset));

    uint32_t retVal = 0x0U;

    Bkp_LL_EnableDataRegisterReadWrite();

    Bkp_LL_HandleStart();
    retVal = Bkpx->BKPDATA[Offset];
    Bkp_LL_HandleEnd();

    return retVal;
}

/**
 * @brief 复位备份域(BKP)外设,该函数仅复位备份域寄存器组.
 * @retval 无
 */
void Bkp_LL_SetBkpResetOnOff(void)
{
    Bkp_LL_EnableDataRegisterReadWrite();

    Bkp_LL_HandleStart();
    /* 备份域寄存器组软件复位 */
    Bkp_LL_SetBkpReset(BKP_PTR, true);
    NOP();
    NOP();
    NOP();
    NOP();
    Bkp_LL_SetBkpReset(BKP_PTR, false);
    Bkp_LL_HandleEnd();
}

/**
 * @brief 使能备份域(BKP)数据寄存器读写
 *
 * @return void
 */
void Bkp_LL_EnableDataRegisterReadWrite(void)
{
    static uint32_t BkpDataEnableState = 0U;
    if (0U == BkpDataEnableState)
    {
        BkpDataEnableState = 0x55555555U;
        Bkp_LL_PmRegisterHandleStart();
        /** Exit reset mode and enable read write */
        Pm_LL_ExitBkpReset(true);
        Pm_LL_SetBackupWriteAndReadEnabled(true);
        Bkp_LL_PmRegisterHandleEnd();
    }
    else
    { /*Empty*/
    }
}

/* EOF */
