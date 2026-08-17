/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name        : kf32a158sf_drv_cache.h
 *  @Date             : 2025-07-07
 *  @Version          : {{VersionDate}}
 *  @Description      : This file provides cache driver.
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
 *  |2025-07-07  |V1.0     |AE Group     |New create
 ******************************************************************************/
#ifndef KF32A158SF_DRV_CACHE_H
#define KF32A158SF_DRV_CACHE_H

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
/* PRQA S 1006,3006 EOF #KQR101006 */

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include "kf32a158sf_reg_cache.h"
#include "kf32a158sf_drv_flash.h"

/******************************************************************************
 *                      Macro or Inline
 ******************************************************************************/
#ifdef KF_DRV_CACHE_ASSERT
#include "dev_assert.h"
#define KF_CACHE_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_CACHE_ASSERT(x) ((void)0U)
#endif

/******************************************************************************
 *                      Type definitions
 ******************************************************************************/
/**
 * @brief Cache bus test mode
 */
typedef enum
{
    CACHE_BUS_TEST_WRITE = 0U,
    CACHE_BUS_TEST_READ  = 1U
} Cache_BusTestMode_t;

#define CHECK_CACHE_BUSTESTMODE(Mode) ((uint32_t)(Mode) <= (uint32_t)CACHE_BUS_TEST_READ)

/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/

/**
 * @brief Enable the cache.
 * @note The cache can only be enabled when prefetch is enabled and the flash
 * access cycle is not 0.
 * @return void
 */
KF_INLINE void Cache_LL_Enable(void)
{
    KF_CACHE_ASSERT(Flash_LL_GetLinearPrefetchState() == true);
    KF_CACHE_ASSERT(FLASH_PTR->CFG.bits.TCFG != 0U);
    CACHE_PTR->CTL.bits.CACHEEN = 1U;
}

/**
 * @brief Disable the cache.
 * @return void
 */
KF_INLINE void Cache_LL_Disable(void)
{
    CACHE_PTR->CTL.bits.CACHEEN = 0U;
}

/**
 * @brief Get the cache enable state.
 * @return bool
 * @retval true The cache is enabled.
 * @retval false The cache is disabled.
 */
KF_INLINE bool Cache_LL_IsEnabled(void)
{
    return (CACHE_PTR->CTL.bits.CACHEEN == 1U);
}

/**
 * @brief Reset the cache.
 * @note This function should only be called when the cache is disabled.
 * @return void
 */
KF_INLINE void Cache_LL_Reset(void)
{
    KF_CACHE_ASSERT(Cache_LL_IsEnabled() == false);
    CACHE_PTR->CTL.bits.CACHERST = 1U;
}

/**
 * @brief Exit the cache reset.
 * @note This function should only be called when the cache reset is complete.
 * @return void
 */
KF_INLINE void Cache_LL_ExitReset(void)
{
    CACHE_PTR->CTL.bits.CACHERST = 0U;
}

/**
 * @brief Enable instruction cache write 2 lines.
 * @return void
 */
KF_INLINE void Cache_LL_EnableWrite2Lines(void)
{
    CACHE_PTR->CTL.bits.ICWR2LEN = 1U;
}

/**
 * @brief Disable instruction cache write 2 lines.
 * @return void
 */
KF_INLINE void Cache_LL_DisableWrite2Lines(void)
{
    CACHE_PTR->CTL.bits.ICWR2LEN = 0U;
}

/**
 * @brief Enable instruction cache read 2 lines.
 * @return void
 */
KF_INLINE void Cache_LL_EnableRead2Lines(void)
{
    CACHE_PTR->CTL.bits.ICRD2LEN = 1U;
}

/**
 * @brief Disable instruction cache read 2 lines.
 * @return void
 */
KF_INLINE void Cache_LL_DisableRead2Lines(void)
{
    CACHE_PTR->CTL.bits.ICRD2LEN = 0U;
}

/**
 * @brief Enable ECC check for cache.
 * @return void
 */
KF_INLINE void Cache_LL_EnableECC(void)
{
    CACHE_PTR->CTL.bits.CECCEN = 1U;
}

/**
 * @brief Disable ECC check for cache.
 * @return void
 */
KF_INLINE void Cache_LL_DisableECC(void)
{
    CACHE_PTR->CTL.bits.CECCEN = 0U;
}

/**
 * @brief Enable bus test mode.
 * @return void
 */
KF_INLINE void Cache_LL_EnableBusTest(void)
{
    CACHE_PTR->CTL.bits.BUSTEN = 1U;
}

/**
 * @brief Disable bus test mode.
 * @return void
 */
KF_INLINE void Cache_LL_DisableBusTest(void)
{
    CACHE_PTR->CTL.bits.BUSTEN = 0U;
}

/**
 * @brief Start the bus test.
 * @return void
 */
KF_INLINE void Cache_LL_StartBusTest(void)
{
    CACHE_PTR->CTL.bits.BUSTSTART = 1U;
}

/**
 * @brief Set the bus test mode.
 * @param Mode The bus test mode.
 * @return void
 */
KF_INLINE void Cache_LL_SetBusTestMode(Cache_BusTestMode_t Mode)
{
    KF_CACHE_ASSERT(CHECK_CACHE_BUSTESTMODE(Mode));
    CACHE_PTR->CTL.bits.BUSTMODE = (uint32_t)Mode;
}

/**
 * @brief Set the bus test data 0.
 * @param Data The data to be set.
 * @return void
 */
KF_INLINE void Cache_LL_SetBusTestData0(bool Data)
{
    CACHE_PTR->CTL.bits.BUSTD0 = Data ? 1U : 0U;
}

/**
 * @brief Set the bus test data 1.
 * @param Data The data to be set.
 * @return void
 */
KF_INLINE void Cache_LL_SetBusTestData1(bool Data)
{
    CACHE_PTR->CTL.bits.BUSTD1 = Data ? 1U : 0U;
}

/**
 * @brief Get the bus read error flag.
 * @return bool
 * @retval true A read error has occurred.
 * @retval false No read error.
 */
KF_INLINE bool Cache_LL_GetBusReadErrorFlag(void)
{
    return (CACHE_PTR->CTL.bits.BUSRERR == 1U);
}

/**
 * @brief Get the bus write error flag.
 * @return bool
 * @retval true A write error has occurred.
 * @retval false No write error.
 */
KF_INLINE bool Cache_LL_GetBusWriteErrorFlag(void)
{
    return (CACHE_PTR->CTL.bits.BUSWERR == 1U);
}

#ifdef __cplusplus
}
#endif /*End of __cplusplus*/
#endif /*End of KF32A158SF_DRV_CACHE_H*/
       /* EOF */
