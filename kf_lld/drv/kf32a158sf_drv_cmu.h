/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name        : kf32a158sf_drv_cmu.h
 *  @Date             : 2025-07-08
 *  @Version          : {{VersionDate}}
 *  @Description      : This file provides CMU driver.
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
#ifndef KF32A158SF_DRV_CMU_H
#define KF32A158SF_DRV_CMU_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      QAC Warnings
 ******************************************************************************/
/* PRQA S 0288 EOF #KQR000288 */
/* PRQA S 3205 EOF #KQR003205 */
/* PRQA S 3219 EOF #KQR003219 */
/* PRQA S 0303,0306 EOF #KQR100303 */

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include "kf32a158sf_reg_cmu.h"

/******************************************************************************
 *                      Macro or Inline
 ******************************************************************************/
#ifdef KF_DRV_CMU_ASSERT
#include "dev_assert.h"
#define KF_CMU_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_CMU_ASSERT(x) ((void)0U)
#endif

/******************************************************************************
 *                      Type definitions
 ******************************************************************************/
/** @brief enum of CMU channel number */
typedef enum
{
    CMU_CHANNEL_1      = 0U,
    CMU_CHANNEL_2      = 1U,
    CMU_CHANNEL_3      = 2U,
    CMU_CHANNEL_4      = 3U,
    CMU_CHANNEL_INTHF  = 0U,
    CMU_CHANNEL_EXTHF  = 1U,
    CMU_CHANNEL_PLL    = 2U,
    CMU_CHANNEL_HSIVAF = 3U,
} Cmu_Channel_t;
#define CHECK_CMU_CHANNEL(CHN) ((uint32_t)(CHN) <= (uint32_t)CMU_CHANNEL_4)

/** @brief enum of CMU threshold type */
typedef enum
{
    CMU_THRESHOLD_HIGH = 0U,
    CMU_THRESHOLD_LOW,
} Cmu_Threshold_t;
#define CHECK_CMU_THRESHOLD_TYPE(THR) ((CMU_THRESHOLD_LOW == (THR)) || (CMU_THRESHOLD_HIGH == (THR)))

/** @brief Check threshold */
#define CHECK_CMU_THRESHOLD(THR) ((THR) <= 0xffffffU)

/** @brief CMU清除中断序号*/
typedef enum
{
    CMU_INTR_CLEAR_INDEX_FHHIC1   = 4U,
    CMU_INTR_CLEAR_INDEX_FLLIC1   = 5U,
    CMU_INTR_CLEAR_INDEX_FHHIC2   = 6U,
    CMU_INTR_CLEAR_INDEX_FLLIC2   = 7U,
    CMU_INTR_CLEAR_INDEX_FHHIC3   = 8U,
    CMU_INTR_CLEAR_INDEX_FLLIC3   = 9U,
    CMU_INTR_CLEAR_INDEX_FHHIC4   = 10U,
    CMU_INTR_CLEAR_INDEX_FLLIC4   = 11U,
    CMU_INTR_CLEAR_INDEX_CH1REFIC = 12U,
    CMU_INTR_CLEAR_INDEX_CH2REFIC = 13U,
    CMU_INTR_CLEAR_INDEX_CH3REFIC = 14U,
    CMU_INTR_CLEAR_INDEX_CH4REFIC = 15U,
} Cmu_IntrClearIndex_t;
#define CHECK_CMU_INTRCLEARINDEX(x) (((x) >= CMU_INTR_CLEAR_INDEX_FHHIC1) && ((x) <= CMU_INTR_CLEAR_INDEX_CH4REFIC))

/** @brief CMU设置中断序号*/
typedef enum
{
    CMU_INTR_SET_INDEX_FHHIE1   = 8U,
    CMU_INTR_SET_INDEX_FLLIE1   = 9U,
    CMU_INTR_SET_INDEX_FHHIE2   = 10U,
    CMU_INTR_SET_INDEX_FLLIE2   = 11U,
    CMU_INTR_SET_INDEX_FHHIE3   = 12U,
    CMU_INTR_SET_INDEX_FLLIE3   = 13U,
    CMU_INTR_SET_INDEX_FHHIE4   = 14U,
    CMU_INTR_SET_INDEX_FLLIE4   = 15U,
    CMU_INTR_SET_INDEX_CH1REFIE = 16U,
    CMU_INTR_SET_INDEX_CH2REFIE = 17U,
    CMU_INTR_SET_INDEX_CH3REFIE = 18U,
    CMU_INTR_SET_INDEX_CH4REFIE = 19U,
} Cmu_IntrSetIndex_t;
#define CHECK_CMU_INTRSETINDEX(x) (((x) >= CMU_INTR_SET_INDEX_FHHIE1) && ((x) <= CMU_INTR_SET_INDEX_CH4REFIE))

/** @brief CMU获取中断序号*/
typedef enum
{
    CMU_INTR_GET_INDEX_FHHIF1   = 0U,
    CMU_INTR_GET_INDEX_FLLIF1   = 1U,
    CMU_INTR_GET_INDEX_FHHIF2   = 2U,
    CMU_INTR_GET_INDEX_FLLIF2   = 3U,
    CMU_INTR_GET_INDEX_FHHIF3   = 4U,
    CMU_INTR_GET_INDEX_FLLIF3   = 5U,
    CMU_INTR_GET_INDEX_FHHIF4   = 6U,
    CMU_INTR_GET_INDEX_FLLIF4   = 7U,
    CMU_INTR_GET_INDEX_CH1REFIF = 20U,
    CMU_INTR_GET_INDEX_CH2REFIF = 21U,
    CMU_INTR_GET_INDEX_CH3REFIF = 22U,
    CMU_INTR_GET_INDEX_CH4REFIF = 23U,
} Cmu_IntrGetIndex_t;
#define CHECK_CMU_INTRGETINDEX(x) (((x) >= CMU_INTR_GET_INDEX_FHHIF1) && ((x) <= CMU_INTR_GET_INDEX_CH4REFIF))

/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/

/**
 * @brief  设置 CMU 通道使能状态
 *
 * @param Channel: CMU通道
 *        CMU_CHANNEL_1 ~ CMU_CHANNEL_4
 * @param EnableStatus: 使能状态
 *        true -- 使能
 *        false -- 失能
 * @return void
 */
KF_INLINE void Cmu_LL_SetChannelEnabled(Cmu_Channel_t Channel, bool EnableStatus)
{
    KF_CMU_ASSERT(CHECK_CMU_CHANNEL(Channel));
    uint32_t tmpStatus = EnableStatus ? 1U : 0U;

    /* PRQA S 3473 1 #KQR103473 */
    REG_BITS_WRITE(CMU_PTR->CTL.reg, (0x1UL << (uint32_t)Channel), tmpStatus << (uint32_t)Channel);
}

/**
 * @brief 清除CMU中断标志
 *
 * @param IntIndex 清除中断序号, 可见 Cmu_IntrClearIndex_t
 * @return void
 */
KF_INLINE void Cmu_LL_ClearIntrFlag(Cmu_IntrClearIndex_t IntIndex)
{
    KF_CMU_ASSERT(CHECK_CMU_INTRCLEARINDEX(IntIndex));

    /* PRQA S 3473 1 #KQR103473 */
    REG_BIT_SET(CMU_PTR->CTL.reg, 0x1UL << (uint32_t)IntIndex);
}

/**
 * @brief 中断使能设置
 *
 * @param IntIndex 设置中断序号, 可见 Cmu_IntrSetIndex_t
 * @param EnableStatus 中断使能状态
 * @return void
 */
KF_INLINE void Cmu_LL_SetIntrEnabled(Cmu_IntrSetIndex_t IntIndex, bool EnableStatus)
{
    KF_CMU_ASSERT(CHECK_CMU_INTRSETINDEX(IntIndex));
    uint32_t tmpStatus = EnableStatus ? 1U : 0U;

    /* PRQA S 3473 1 #KQR103473 */
    REG_BITS_WRITE(CMU_PTR->INT.reg, 0x1UL << (uint32_t)IntIndex, tmpStatus << (uint32_t)IntIndex);
}

/**
 * @brief  获取CMU中断状态
 *
 * @param Channel: CMU通道
 *        CMU_CHANNEL_1 ~ CMU_CHANNEL_4
 * @param ThrType: CMU阈值类型
 *        CMU_THRESHOLD_HIGH or CMU_THRESHOLD_LOW
 * @return bool: 中断状态
 * @retval true -- 发生中断
 * @retval false -- 无中断发生
 */
KF_INLINE bool Cmu_LL_GetIntrFlag(Cmu_IntrGetIndex_t IntIndex)
{
    KF_CMU_ASSERT(CHECK_CMU_INTRGETINDEX(IntIndex));

    /* PRQA S 3469 1 #KQR003469 */
    return (0U != REG_BITS_READ(CMU_PTR->INT.reg, 0x1UL << (uint32_t)IntIndex, (uint32_t)IntIndex));
}

/**
 * @brief  设置参考时钟运行周期
 *
 * @param Channel: CMU通道
 *        CMU_CHANNEL_1 ~ CMU_CHANNEL_4
 * @param RefCount: 参考时钟运行周期数
 *        0x0 ~ 0xffff
 * @return void
 */
KF_INLINE void Cmu_LL_SetReferenceCount(Cmu_Channel_t Channel, uint16_t RefCount)
{
    KF_CMU_ASSERT(CHECK_CMU_CHANNEL(Channel));

    switch (Channel)
    {
    case CMU_CHANNEL_1:
        CMU_PTR->REFCNT1.reg = (uint32_t)RefCount;
        break;
    case CMU_CHANNEL_2:
        CMU_PTR->REFCNT2.reg = (uint32_t)RefCount;
        break;
    case CMU_CHANNEL_3:
        CMU_PTR->REFCNT3.reg = (uint32_t)RefCount;
        break;
    case CMU_CHANNEL_4:
        CMU_PTR->REFCNT4.reg = (uint32_t)RefCount;
        break;

    default:
        (void)0U;
        break;
    }
}

/**
 * @brief  设置CMU监测周期计数值上限
 *
 * @param Channel: CMU通道
 *        CMU_CHANNEL_1 ~ CMU_CHANNEL_4
 * @param HighThreshold: 监测周期计数上限值
 *        0x0 ~ 0xffffff
 * @return void
 */
KF_INLINE void Cmu_LL_SetHighThreshold(Cmu_Channel_t Channel, uint32_t HighThreshold)
{
    KF_CMU_ASSERT(CHECK_CMU_CHANNEL(Channel));
    KF_CMU_ASSERT(CHECK_CMU_THRESHOLD(HighThreshold));

    switch (Channel)
    {
    case CMU_CHANNEL_1:
        CMU_PTR->HTC1.reg = (uint32_t)HighThreshold;
        break;
    case CMU_CHANNEL_2:
        CMU_PTR->HTC2.reg = (uint32_t)HighThreshold;
        break;
    case CMU_CHANNEL_3:
        CMU_PTR->HTC3.reg = (uint32_t)HighThreshold;
        break;
    case CMU_CHANNEL_4:
        CMU_PTR->HTC4.reg = (uint32_t)HighThreshold;
        break;

    default:
        (void)0U;
        break;
    }
}

/**
 * @brief  设置CMU监测周期计数值下限
 *
 * @param Channel: CMU通道
 *        CMU_CHANNEL_1 ~ CMU_CHANNEL_4
 * @param HighThreshold: 监测周期计数下限值
 *        0x0 ~ 0xffffff
 * @return void
 */
KF_INLINE void Cmu_LL_SetLowThreshold(Cmu_Channel_t Channel, uint32_t LowThreshold)
{
    KF_CMU_ASSERT(CHECK_CMU_CHANNEL(Channel));
    KF_CMU_ASSERT(CHECK_CMU_THRESHOLD(LowThreshold));

    switch (Channel)
    {
    case CMU_CHANNEL_1:
        CMU_PTR->LTC1.reg = (uint32_t)LowThreshold;
        break;
    case CMU_CHANNEL_2:
        CMU_PTR->LTC2.reg = (uint32_t)LowThreshold;
        break;
    case CMU_CHANNEL_3:
        CMU_PTR->LTC3.reg = (uint32_t)LowThreshold;
        break;
    case CMU_CHANNEL_4:
        CMU_PTR->LTC4.reg = (uint32_t)LowThreshold;
        break;

    default:
        (void)0U;
        break;
    }
}

#ifdef __cplusplus
}
#endif /*End of __cplusplus*/
#endif /*End of KF32A158SF_DRV_CMU_H*/
/* EOF */
