/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name        : kf32a158sf_drv_bkp.h
 *  @Date             : 2025-07-08
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
 *  |2025-07-08  |V1.0     |AE Group     |New create
 ******************************************************************************/
#ifndef KF32A158SF_DRV_BKP_H
#define KF32A158SF_DRV_BKP_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      QAC Warnings
 ******************************************************************************/
/* PRQA S 0288 EOF #KQR000288 */
/* PRQA S 1006,3006 EOF #KQR101006 */
/* PRQA S 3205 EOF #KQR003205 */
/* PRQA S 3219 EOF #KQR003219 */

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "kf_types.h"
#include "kf32a158sf_reg_pm.h"
#include "kf32a158sf_reg_osc.h"
#include "kf32a158sf_reg_bkp.h"

#ifdef KF_DRV_BKP_ASSERT
#include "dev_assert.h"
#define KF_BKP_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_BKP_ASSERT(x) ((void)0U)
#endif

/******************************************************************************
 *                      Macro or Inline
 ******************************************************************************/
#define CHECK_BKP_DATAOFFSET(x) ((x) < 8U)

/******************************************************************************
 *                      Type definitions
 ******************************************************************************/

/** TAMP信号采样时钟 */
typedef enum
{
    BKP_TAMP_SAMPLE_CLK_SCLK  = 0x0U,
    BKP_TAMP_SAMPLE_CLK_INTLF = 0x1U,
} Bkp_TampSampleClk_t;
#define CHECK_BKP_TAMPSAMPLECLK(x) (((x) == BKP_TAMP_SAMPLE_CLK_SCLK) || ((x) == BKP_TAMP_SAMPLE_CLK_INTLF))

/** RTC 时钟源选择 */
typedef enum
{
    BKP_RTC_CLK_SRC_NONE = 0x0U,
    BKP_RTC_CLK_SRC_EXTLF,
    BKP_RTC_CLK_SRC_INTLF,
    BKP_RTC_CLK_SRC_EXTHF_DIVIDED,
} Bkp_RtcClkSrc_t;
#define CHECK_BKP_RTCCLKSRC(x)                                                                                         \
    (((x) == BKP_RTC_CLK_SRC_NONE) || ((x) == BKP_RTC_CLK_SRC_EXTLF) || ((x) == BKP_RTC_CLK_SRC_INTLF) ||              \
     ((x) == BKP_RTC_CLK_SRC_EXTHF_DIVIDED))

/** RTC EXTHF时钟源分频 */
typedef enum
{
    BKP_RTC_EXTHF_SCALER_128 = 0x0U,
    BKP_RTC_EXTHF_SCALER_32,
    BKP_RTC_EXTHF_SCALER_8,
    BKP_RTC_EXTHF_SCALER_2,
} Bkp_RtcExthfScaler_t;
#define CHECK_BKP_RTCEXTHFSCALER(x)                                                                                    \
    (((x) == BKP_RTC_EXTHF_SCALER_128) || ((x) == BKP_RTC_EXTHF_SCALER_32) || ((x) == BKP_RTC_EXTHF_SCALER_8) ||       \
     ((x) == BKP_RTC_EXTHF_SCALER_2))

/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/

/**
 * @brief  设置RTC时钟源选择位
 * @param Bkpx 指向Bkp寄存器结构的指针
 * @param RtcClkSel: 参考枚举 Bkp_RtcClkSrc_t
 * @retval 无
 */
KF_INLINE void Bkp_LL_SetRtcClkSel(Bkp_RegisterMap_t *const Bkpx, Bkp_RtcClkSrc_t RtcClkSel)
{
    KF_BKP_ASSERT(CHECK_BKP_ALL_PERIPH_ADDR(Bkpx));
    KF_BKP_ASSERT(CHECK_BKP_RTCCLKSRC(RtcClkSel));

    Bkpx->CTL.bits.RTCCLKS = (uint32_t)RtcClkSel;
}

/**
 * @brief  设置RTC_EXTHF时钟源分频选择
 * @param Bkpx 指向Bkp寄存器结构的指针
 * @param Rtcclktp: 参考 枚举Bkp_RtcExthfScaler_t
 * @retval 无
 */
KF_INLINE void Bkp_LL_SetRtcExthfScaler(Bkp_RegisterMap_t *const Bkpx, Bkp_RtcExthfScaler_t Rtcclktp)
{
    KF_BKP_ASSERT(CHECK_BKP_ALL_PERIPH_ADDR(Bkpx));
    KF_BKP_ASSERT(CHECK_BKP_RTCEXTHFSCALER(Rtcclktp));

    Bkpx->CTL.bits.RTCCLKTP = (uint32_t)Rtcclktp;
}

/**
 * @brief  设置备份域寄存器组软件复位
 * @param Bkpx 指向Bkp寄存器结构的指针
 * @param State:
 *          true 备份域寄存器组复位
 *          false 无作用
 * @retval 无
 */
KF_INLINE void Bkp_LL_SetBkpReset(Bkp_RegisterMap_t *const Bkpx, bool State)
{
    KF_BKP_ASSERT(CHECK_BKP_ALL_PERIPH_ADDR(Bkpx));

    Bkpx->CTL.bits.BKPRST = State ? 1U : 0U;
}

/**
 * @brief 备份域(BKP)寄存器开始读写
 *
 * @retval void
 */
void Bkp_LL_HandleStart(void);

/**
 * @brief 备份域(BKP)寄存器结束读写
 *
 * @retval void
 */
void Bkp_LL_HandleEnd(void);

/**
 * @brief 备份域(BKP)PM寄存器开始读写
 *
 * @return void
 */
void Bkp_LL_PmRegisterHandleStart(void);

/**
 * @brief 备份域(BKP)PM寄存器结束读写
 *
 * @return void
 */
void Bkp_LL_PmRegisterHandleEnd(void);

/**
 * @brief 设置BKP数据
 * @param Bkpx 指向BKPx寄存器结构的指针
 * @param Offset 偏移 0-7
 * @param Data 数据
 * @retval 无
 */
void Bkp_LL_SetBkpData(Bkp_RegisterMap_t *const Bkpx, uint32_t Offset, uint32_t Data);

/**
 * @brief 获取BKP数据
 * @param Bkpx 指向BKPx寄存器结构的指针
 * @param Offset 偏移 0-7
 * @retval 无
 */
uint32_t Bkp_LL_GetBkpData(const Bkp_RegisterMap_t *const Bkpx, uint32_t Offset);

/**
 * @brief 使能备份域(BKP)数据寄存器读写
 *
 * @return void
 */
void Bkp_LL_EnableDataRegisterReadWrite(void);

/**
 * @brief 复位备份域(BKP)外设,该函数仅复位备份域寄存器组
 * @retval 无
 */
void Bkp_LL_SetBkpResetOnOff(void);

#ifdef __cplusplus
}
#endif /*End of __cplusplus*/
#endif /*End of KF32A158SF_DRV_BKP_H*/
/* EOF */
