/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name        : kf32a158sf_drv_spi.h
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
#ifndef KF32A158SF_DRV_SPI_H
#define KF32A158SF_DRV_SPI_H

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
/* PRQA S 4342 EOF #KQR004342 */

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "kf_types.h"
#include "kf32a158sf_reg_spi.h"

#ifdef KF_DRV_SPI_ASSERT
#include "dev_assert.h"
#define KF_SPI_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_SPI_ASSERT(x) ((void)0U)
#endif

/******************************************************************************
 *                      Macro or Inline
 ******************************************************************************/
#define CHECK_SPI_FIFO_THRESHOLD(x) ((x) <= 0x4U)

/******************************************************************************
 *                      Type definitions
 ******************************************************************************/

/*bit mode selection*/
typedef enum
{
    SPI_BITWIDTH_8BITS,
    SPI_BITWIDTH_16BITS,
    SPI_BITWIDTH_32BITS,
    SPI_BITWIDTH_RESERVE,
} Spi_BitWidth_t;
#define CHECK_SPI_BITWIDTH(x)                                                                                          \
    (((x) == SPI_BITWIDTH_8BITS) || ((x) == SPI_BITWIDTH_16BITS) || ((x) == SPI_BITWIDTH_32BITS))

/*clock source selection*/
typedef enum
{
    SPI_CLKSRC_SCLK,
    SPI_CLKSRC_HFCLK,
    SPI_CLKSRC_RESERVE,
    SPI_CLKSRC_HF1CLK,
} Spi_ClockSrc_t;
#define CHECK_SPI_CLOCKSRC(x) (((x) == SPI_CLKSRC_SCLK) || ((x) == SPI_CLKSRC_HFCLK) || ((x) == SPI_CLKSRC_HF1CLK))

/*data direction selection*/
typedef enum
{
    SPI_BIT_ORDER_LSB_FIRST,
    SPI_BIT_ORDER_MSB_FIRST,
} Spi_BitOrder_t;
#define CHECK_SPI_BITORDER(x) (((x) == SPI_BIT_ORDER_LSB_FIRST) || ((x) == SPI_BIT_ORDER_MSB_FIRST))

/*the port connection mode selection*/
typedef enum
{
    /* SDO/SDI */
    SPI_LINE_CROSS,
    /* MOSI/MISO */
    SPI_LINE_DIRECT,
} Spi_LineMode_t;
#define CHECK_SPI_LINEMODE(x) (((x) == SPI_LINE_CROSS) || ((x) == SPI_LINE_DIRECT))

/*synchronize serial port mode selection*/
typedef enum
{
    SPI_MODE_MASTER_CLK_DIV_4,
    SPI_MODE_MASTER_CLK_DIV_16,
    SPI_MODE_MASTER_CLK_DIV_64,
    SPI_MODE_MASTER_TXTRGO_DIV_2,
    SPI_MODE_SLAVE_SCK,
    SPI_MODE_MASTER_CLK_DIV_2,
} Spi_WorkMode_t;
#define CHECK_SPI_WORKMODE(x)                                                                                          \
    (((x) == SPI_MODE_MASTER_CLK_DIV_4) || ((x) == SPI_MODE_MASTER_CLK_DIV_16) ||                                      \
     ((x) == SPI_MODE_MASTER_CLK_DIV_64) || ((x) == SPI_MODE_MASTER_TXTRGO_DIV_2) || ((x) == SPI_MODE_SLAVE_SCK) ||    \
     ((x) == SPI_MODE_MASTER_CLK_DIV_2))

/* Clock Phase */
typedef enum
{
    SPI_CPHA_1, /*!< Sample at Second Clock Edge */
    SPI_CPHA_0, /*!< Sample at First Clock Edge */
} Spi_ClockPhase_t;
#define CHECK_SPI_CLOCKPHASE(x) (((x) == SPI_CPHA_1) || ((x) == SPI_CPHA_0))

/* Polarity Level At Idle Time */
typedef enum
{
    SPI_CPOL_0, /*!< Low Level at Idle */
    SPI_CPOL_1, /*!< High Level at Idle */
} Spi_ClockPolarity_t;
#define CHECK_SPI_CLOCKPOLARITY(x) (((x) == SPI_CPOL_0) || ((x) == SPI_CPOL_1))

/* Phase and Polarity Group Mode */
typedef enum
{
    SPI_CLOCK_MODE_0, /*!< CPOL=0, CPHA=0 */
    SPI_CLOCK_MODE_1, /*!< CPOL=0, CPHA=1 */
    SPI_CLOCK_MODE_2, /*!< CPOL=1, CPHA=0 */
    SPI_CLOCK_MODE_3, /*!< CPOL=1, CPHA=1 */
} Spi_ClockMode_t;
#define CHECK_SPI_CLOCKMODE(x)                                                                                         \
    (((x) == SPI_CLOCK_MODE_0) || ((x) == SPI_CLOCK_MODE_1) || ((x) == SPI_CLOCK_MODE_2) || ((x) == SPI_CLOCK_MODE_3))

/*drive pin selection bit*/
typedef enum
{
    SPI_CS_SS0,
    SPI_CS_SS1,
    SPI_CS_SS2,
    SPI_CS_SS3,
} Spi_CsPins_t;
#define CHECK_SPI_CSPINS(x) (((x) == SPI_CS_SS0) || ((x) == SPI_CS_SS1) || ((x) == SPI_CS_SS2) || ((x) == SPI_CS_SS3))

typedef enum
{
    I2S_MODE_SLAVE_TRANSMIT  = 0U,
    I2S_MODE_SLAVE_RECEIVE   = 1U,
    I2S_MODE_MASTER_TRANSMIT = 2U,
    I2S_MODE_MASTER_RECEIVE  = 3U,
} I2S_Mode_t;
#define CHECK_I2S_MODE(x)                                                                                              \
    (((x) == I2S_MODE_SLAVE_TRANSMIT) || ((x) == I2S_MODE_SLAVE_RECEIVE) || ((x) == I2S_MODE_MASTER_TRANSMIT) ||       \
     ((x) == I2S_MODE_MASTER_RECEIVE))

typedef enum
{
    I2S_PHILIPS_STANDARD_SELECTED    = 0U,
    I2S_LOW_BYTE_ALIGNMENT_SELECTED  = 1U,
    I2S_HIGH_BYTE_ALIGNMENT_SELECTED = 2U,
    I2S_PCM_STANDARD_SELECTED        = 3U,
} I2S_StandardSelection_t;
#define CHECK_I2S_STANDARD_SELECTION(x)                                                                                \
    (((x) == I2S_PHILIPS_STANDARD_SELECTED) || ((x) == I2S_LOW_BYTE_ALIGNMENT_SELECTED) ||                             \
     ((x) == I2S_HIGH_BYTE_ALIGNMENT_SELECTED) || ((x) == I2S_PCM_STANDARD_SELECTED))

typedef enum
{
    I2SCKS_FCKI2S_DIV_1 = 0x0U,
    I2SCKS_FCKI2S_DIV_4 = 0x2U,
    I2SCKS_FCKI2S_DIV_8 = 0x3U,
} I2S_ClockSource_t;
#define CHECK_I2S_CLOCKSOURCE(x)                                                                                       \
    (((x) == I2SCKS_FCKI2S_DIV_1) || ((x) == I2SCKS_FCKI2S_DIV_4) || ((x) == I2SCKS_FCKI2S_DIV_8))

/*获取中断序号*/
typedef enum
{
    SPI_INTR_GET_RNE        = 1U,           /*!< RBUF不为空中断标志 */
    SPI_INTR_GET_TNE        = 2U,           /*!< TBUF为空中断标志 */
    SPI_INTR_GET_ROVFIF     = 4U,           /*!< 接收溢出中断标志 */
    SPI_INTR_GET_TOVFIF     = 5U,           /*!< 发送溢出中断标志 */
    SPI_INTR_GET_UDRIF      = 6U,           /*!< 从机发送下溢中断标志 */
    SPI_INTR_GET_TSTOP      = 7U,           /*!< 主机停发中断标志 */
    SPI_INTR_GET_TXFIFOHTIF = 0x100U + 7U,  /*!< TXFIFO 高阈值中断标志 */
    SPI_INTR_GET_TXFIFOLTIF = 0x100U + 11U, /*!< TXFIFO 低阈值中断标志 */
    SPI_INTR_GET_RXFIFOHTIF = 0x100U + 23U, /*!< RXFIFO 高阈值中断标志 */
    SPI_INTR_GET_RXFIFOLTIF = 0x100U + 27U, /*!< RXFIFO 低阈值中断标志 */
} Spi_IntrGetIndex_t;
#define CHECK_SPI_INTRGETINDEX(x)                                                                                      \
    (((x) == SPI_INTR_GET_RNE) || ((x) == SPI_INTR_GET_TNE) || ((x) == SPI_INTR_GET_ROVFIF) ||                         \
     ((x) == SPI_INTR_GET_TOVFIF) || ((x) == SPI_INTR_GET_UDRIF) || ((x) == SPI_INTR_GET_TSTOP) ||                     \
     ((x) == SPI_INTR_GET_TXFIFOHTIF) || ((x) == SPI_INTR_GET_TXFIFOLTIF) || ((x) == SPI_INTR_GET_RXFIFOHTIF) ||       \
     ((x) == SPI_INTR_GET_RXFIFOLTIF))

/**设置中断序号*/
typedef enum
{
    SPI_INTR_SET_TSTOPIE    = 10U, /*!< 主机停发中断使能 */
    SPI_INTR_SET_UDRIE      = 11U, /*!< 从机发送下溢中断使能 */
    SPI_INTR_SET_ROVFIE     = 12U, /*!< 接收溢出中断使能 */
    SPI_INTR_SET_TOVFIE     = 13U, /*!< 发送溢出中断使能 */
    SPI_INTR_SET_RNEIE      = 14U, /*!< RBUF不为空中断使能 */
    SPI_INTR_SET_TNEIE      = 15U, /*!< TBUF为空中断使能 */
    SPI_INTR_SET_TXFIFOHTIE = 22U, /*!< TXFIFO 高阈值中断使能 */
    SPI_INTR_SET_TXFIFOLTIE = 23U, /*!< TXFIFO 低阈值中断使能 */
    SPI_INTR_SET_RXFIFOHTIE = 24U, /*!< RXFIFO 高阈值中断使能 */
    SPI_INTR_SET_RXFIFOLTIE = 25U, /*!< RXFIFO 低阈值中断使能 */
} Spi_IntrSetIndex_t;
#define CHECK_SPI_INTRSETINDEX(x)                                                                                      \
    ((((x) >= SPI_INTR_SET_TSTOPIE) && ((x) <= SPI_INTR_SET_TNEIE)) ||                                                 \
     (((x) >= SPI_INTR_SET_TXFIFOHTIE) && ((x) <= SPI_INTR_SET_RXFIFOLTIE)))

/**清除中断序号*/
typedef enum
{
    SPI_INTR_CLEAR_TSTOPIC = 19U, /*!< 主机停发中断清零 */
    SPI_INTR_CLEAR_UDRIC   = 18U, /*!< 从机发送下溢中断清零 */
    SPI_INTR_CLEAR_ROVFIC  = 16U, /*!< 接收溢出中断清零 */
    SPI_INTR_CLEAR_TOVFIC  = 17U, /*!< 发送溢出中断清零 */
} Spi_IntrClearIndex_t;
#define CHECK_SPI_INTRCLEARINDEX(x) (((x) >= SPI_INTR_CLEAR_ROVFIC) && ((x) <= SPI_INTR_CLEAR_TSTOPIC))

/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/

/**
 * @brief 配置SPI波特率寄存器
 * @param Module 指向SPI寄存器结构的指针
 * @param Pres Fck/((Pres + 1) * 2)
 * @retval None
 */
KF_INLINE void Spi_LL_SetBaudRatePrescaler(Spi_RegisterMap_t *const Module, uint16_t Pres)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));

    Module->BRGR.bits.SPIBRG = Pres;
}

/**
 * @brief: 设置I2S预分频值
 * @param Module: SPI寄存器结构体指针
 * @param PreDiv: Fck/(PreDiv*2 + I2SODD)
 * @retval 无
 */
KF_INLINE void Spi_LL_SetI2SPreDivider(Spi_RegisterMap_t *const Module, uint8_t PreDiv)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));

    Module->BRGR.bits.I2SDIV = PreDiv;
}

/**
 * @brief: 设置主设备时钟输出使能
 * @param Module: SPI寄存器结构体指针
 * @param State
 *          true 使能MCK输出
 *          false 禁止MCK输出
 * @retval 无
 */
KF_INLINE void Spi_LL_SetMasterClockEnabled(Spi_RegisterMap_t *const Module, bool State)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));

    Module->BRGR.bits.MCKEN = State ? 1U : 0U;
}

/**
 * @brief: 设置I2S时钟精度微调位
 * @param Module: SPI寄存器结构体指针
 * @param State
 *          true 微调为1
 *          false 微调为0
 * @retval 无
 */
KF_INLINE void Spi_LL_SetI2SOddDivider(Spi_RegisterMap_t *const Module, bool State)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));

    Module->BRGR.bits.I2SODD = State ? 1U : 0U;
}

/**
 * @brief: 设置SPI使能位
 * @param Module: SPI寄存器结构体指针
 * @param State
 *          true 使能SPI
 *          false 禁止SPI
 * @retval 无
 */
KF_INLINE void Spi_LL_SetEnabled(Spi_RegisterMap_t *const Module, bool State)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));

    Module->CTL.bits.SPIEN = State ? 1U : 0U;
}

/**
 * @brief Set Spi Module Work Mode
 * @param Module SPI寄存器结构体指针
 * @param WorkMode Spi_WorkMode_t
 * @retval None
 */
KF_INLINE void Spi_LL_SetWorkMode(Spi_RegisterMap_t *const Module, Spi_WorkMode_t WorkMode)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
    KF_SPI_ASSERT(CHECK_SPI_WORKMODE(WorkMode));

    Module->CTL.bits.SPIMS = (uint32_t)WorkMode;
}

/**
 * @brief Get Spi Module Work Mode
 * @param Module SPI寄存器结构体指针
 * @param WorkMode Spi_WorkMode_t
 * @retval Spi_WorkMode_t
 */
KF_INLINE Spi_WorkMode_t Spi_LL_GetWorkMode(Spi_RegisterMap_t const *const Module)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));

    return (Spi_WorkMode_t)Module->CTL.bits.SPIMS;
}

/**
 * @brief Set Spi Module Clock Source
 * @param Module SPI寄存器结构体指针
 * @param ClkSrc Spi_ClockSrc_t
 * @retval None
 */
KF_INLINE void Spi_LL_SetClockSource(Spi_RegisterMap_t *const Module, Spi_ClockSrc_t ClkSrc)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
    KF_SPI_ASSERT(CHECK_SPI_CLOCKSRC(ClkSrc));

    Module->CTL.bits.SPICKS = (uint32_t)ClkSrc;
}

/**
 * @brief Set Spi Module Significant Bit
 * @param Module SPI寄存器结构体指针
 * @param Dir
 * @retval None
 */
KF_INLINE void Spi_LL_SetBitOrder(Spi_RegisterMap_t *const Module, Spi_BitOrder_t Dir)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
    KF_SPI_ASSERT(CHECK_SPI_BITORDER(Dir));

    Module->CTL.bits.SPIDS = (uint32_t)Dir;
}

/**
 * @brief Set Spi Module Data Line Mode
 * @param Module SPI寄存器结构体指针
 * @param LineMode Spi_LineMode_t
 * @retval None
 */
KF_INLINE void Spi_LL_SetDataLineMode(Spi_RegisterMap_t *const Module, Spi_LineMode_t LineMode)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
    KF_SPI_ASSERT(CHECK_SPI_LINEMODE(LineMode));

    Module->CTL.bits.SPIIOS = (uint32_t)LineMode;
}

/**
 * @brief Set Spi Module Clock Polarity
 * @param Module SPI寄存器结构体指针
 * @param Cpol Spi_ClockPolarity_t
 * @retval None
 */
KF_INLINE void Spi_LL_SetClockPolarity(Spi_RegisterMap_t *const Module, Spi_ClockPolarity_t Cpol)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
    KF_SPI_ASSERT(CHECK_SPI_CLOCKPOLARITY(Cpol));

    Module->CTL.bits.SPICKP = (uint32_t)Cpol;
}

/**
 * @brief Set Spi Module Clock Polarity
 * @param Module SPI寄存器结构体指针
 * @param Sample Spi_ClockPhase_t
 * @retval None
 */
KF_INLINE void Spi_LL_SetClockPhase(Spi_RegisterMap_t *const Module, Spi_ClockPhase_t Sample)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
    KF_SPI_ASSERT(CHECK_SPI_CLOCKPHASE(Sample));

    Module->CTL.bits.SPICKE = (uint32_t)Sample;
}

/**
 * @brief 配置SPI位模式选择
 * @param Module 指向SPI寄存器结构的指针
 * @param bitWidth
 * @retval None
 */
KF_INLINE void Spi_LL_SetBitWidth(Spi_RegisterMap_t *const Module, Spi_BitWidth_t BitWidth)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
    KF_SPI_ASSERT(CHECK_SPI_BITWIDTH(BitWidth));

    Module->CTL.bits.SPIBS = (uint32_t)BitWidth;
}

/**
 * @brief 获取SPI位模式
 * @param Module 指向SPI寄存器结构的指针
 * @retval Spi_BitWidth_t
 */
KF_INLINE Spi_BitWidth_t Spi_LL_GetBitWidth(const Spi_RegisterMap_t *const Module)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));

    return (Spi_BitWidth_t)Module->CTL.bits.SPIBS;
}

/**
 * @brief Select Cs Pin
 * @param Module SPI寄存器结构体指针
 * @param Cspin Spi_CsPins_t
 * @retval NoneIE
 */
KF_INLINE void Spi_LL_SelectCsPin(Spi_RegisterMap_t *const Module, Spi_CsPins_t Cspin)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
    KF_SPI_ASSERT(CHECK_SPI_CSPINS(Cspin));

    Module->CTL.bits.SSEL = (uint32_t)Cspin;
}

/**
 * @brief: 设置I2S模式选择位
 * @param Module: SPI寄存器结构体指针
 * @param Mode: I2S模式选择位
 *          true   选择I2S 模式
 *          false   选择SPI 模式
 * @retval 无
 */
KF_INLINE void Spi_LL_SelectSPIMode(Spi_RegisterMap_t *const Module, bool Mode)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));

    Module->CTL.bits.SPIMOD = Mode ? 1U : 0U;
}

/**
 * @brief: 设置I2S空闲时MCK输出模式选择位
 * @param Module: SPI寄存器结构体指针
 * @param Mode: I2S空闲时MCK输出模式选择位
 *          true   禁止输出模式,空闲时MCK 禁止
 *          false 连续输出模式,空闲时MCK 输出
 * @retval 无
 */
KF_INLINE void Spi_LL_SelectMasterClockOutputMode(Spi_RegisterMap_t *const Module, bool Mode)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));

    Module->CTL.bits.MCKOS = Mode ? 1U : 0U;
}

/**
 * @brief: 设置I2S模式设置位
 * @param Module: SPI寄存器结构体指针
 * @param Mode: I2S模式设置 I2S_Mode_t
 * @retval 无
 */
KF_INLINE void Spi_LL_SetI2SMode(Spi_RegisterMap_t *const Module, I2S_Mode_t Mode)
{
    Module->CTL.bits.I2SMC = (uint32_t)Mode;
}

/**
 * @brief: 设置I2S标准选择位
 * @param Module: SPI寄存器结构体指针
 * @param Sel: I2S标准选择位 I2S_Standard_Selection_t
 * @retval 无
 */
KF_INLINE void Spi_LL_SelectI2SStandard(Spi_RegisterMap_t *const Module, I2S_StandardSelection_t Sel)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
    KF_SPI_ASSERT(CHECK_I2S_STANDARD_SELECTION(Sel));

    Module->CTL.bits.I2SSS = (uint32_t)Sel;
}

/**
 * @brief: 设置PCM帧同步
 * @param Module: SPI寄存器结构体指针
 * @param State
 *          true 长帧同步
 *          false 短帧同步
 * @retval 无
 */
KF_INLINE void Spi_LL_SetPcmFrameSync(Spi_RegisterMap_t *const Module, bool State)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));

    Module->CTL.bits.PCMS = State ? 1U : 0U;
}

/**
 * @brief: 设置I2S模式的时钟分频选择位
 * @param Module: SPI寄存器结构体指针
 * @param Div: I2S模式的时钟分频选择位 I2S_ClockSource_t
 * @retval 无
 */
KF_INLINE void Spi_LL_SelectI2SClockPrescaler(Spi_RegisterMap_t *const Module, I2S_ClockSource_t Div)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
    KF_SPI_ASSERT(CHECK_I2S_CLOCKSOURCE(Div));

    Module->CTL.bits.I2SCKS = (uint32_t)Div;
}

/**
 * @brief: Spi Write Data Reg
 * @param Module SPI寄存器结构体指针
 * @param Data
 * @retval None
 */
KF_INLINE void Spi_LL_WriteData(Spi_RegisterMap_t *const Module, uint32_t Data)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));

    Module->BUFR = Data;
}

/**
 * @brief: Spi Read Data Reg
 *
 * @param Module SPI寄存器结构体指针
 * @param Data
 * @retval None
 */
KF_INLINE uint32_t Spi_LL_ReadData(const Spi_RegisterMap_t *const Module)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));

    return Module->BUFR;
}

/**
 * @brief: Spi Get Data Reg Pointer
 *
 * @param Module SPI寄存器结构体指针
 * @retval uint32_t* SPI Buffer 指针
 */
KF_INLINE uint32_t const volatile *Spi_LL_GetBufferPtr(Spi_RegisterMap_t const *const Module)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));

    return (uint32_t const volatile *)&Module->BUFR;
}

/**
 * @brief: 获取SPI忙标志
 * @param Module: 指向Spi_RegisterMap_t内存结构的指针
 * @retval true      SPI忙
 * @retval false      SPI空闲
 */
KF_INLINE bool Spi_LL_GetSpiBusyFlag(const Spi_RegisterMap_t *const Module)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));

    return Module->STR.bits.SPIBUSY != 0U;
}

/**
 * @brief: 获取接收BUF未空标志
 * @param Module: 指向Spi_RegisterMap_t内存结构的指针
 * @retval true      接收BUF不为空
 * @retval false      接收BUF为空
 */
KF_INLINE bool Spi_LL_IsRxBufferFull(const Spi_RegisterMap_t *const Module)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));

    return (Module->STR.bits.RNE != 0U);
}

/**
 * @brief: SPI 发送状态
 *      发送BUF未空,启动发送时该位为0,写SPIx_BUFR后该位为1
 * @param Module
 * @retval      true   发送BUF为空
 *              false   发送BUF不为空
 */
KF_INLINE bool Spi_LL_IsTxBufferEmpty(const Spi_RegisterMap_t *const Module)
{
    return (Module->STR.bits.TNE == 0U);
}

/**
 * @brief 设置Spi中断使能
 * @param Module 指向SPI寄存器结构的指针
 * @param IntIndex 设置中断序号, Spi_IntrSetIndex_t
 * @param State 使能状态
 * @retval None
 */
KF_INLINE void Spi_LL_SetIntrEnabled(Spi_RegisterMap_t *const Module, Spi_IntrSetIndex_t IntIndex, bool State)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
    KF_SPI_ASSERT(CHECK_SPI_INTRSETINDEX(IntIndex));

    /* PRQA S 3473 1 #KQR003473 */
    REG_BITS_WRITE(Module->STR.reg, (1UL << (uint32_t)IntIndex), ((State ? 1UL : 0UL) << (uint32_t)IntIndex));
}

/**
 * @brief 获取Spi中断使能状态
 * @param Module 指向SPI寄存器结构的指针
 * @param IntIndex Spi_IntrSetIndex_t
 * @retval true/false
 */
KF_INLINE bool Spi_LL_GetIntrEnabledState(const Spi_RegisterMap_t *const Module, Spi_IntrSetIndex_t IntIndex)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
    KF_SPI_ASSERT(CHECK_SPI_INTRSETINDEX(IntIndex));

    /* PRQA S 3469 1 #KQR003469 */
    return (REG_BITS_READ(Module->STR.reg, (0x1UL << (uint32_t)IntIndex), (uint32_t)IntIndex) != 0U);
}

/**
 * @brief 清零SPi中断
 * @param Module 指向SPI寄存器结构的指针
 * @param IntIndex 清除中断序号, 可见 Spi_IntrClearIndex_t
 * @retval None
 */
KF_INLINE void Spi_LL_ClearIntrFlag(Spi_RegisterMap_t *const Module, Spi_IntrClearIndex_t IntIndex)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
    KF_SPI_ASSERT(CHECK_SPI_INTRCLEARINDEX(IntIndex));

    /* PRQA S 3473 ++ #KQR003473 */
    REG_BITS_WRITE(Module->STR.reg, (1UL << (uint32_t)IntIndex), (0x1UL << (uint32_t)IntIndex));
    NOP();
    NOP();
    NOP();
    NOP();
    REG_BITS_WRITE(Module->STR.reg, (1UL << (uint32_t)IntIndex), (0x0UL << (uint32_t)IntIndex));
    /* PRQA S 3473 -- #KQR003473 */
}

/**
 * @brief Get Spi Module Flag Status
 * @param Module 指向SPI寄存器结构的指针
 * @param flag
 * @retval true/false
 */
KF_INLINE bool Spi_LL_GetIntrFlag(const Spi_RegisterMap_t *const Module, Spi_IntrGetIndex_t IntIndex)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
    KF_SPI_ASSERT(CHECK_SPI_INTRGETINDEX(IntIndex));
    bool     state = false;
    uint32_t fifoIntIndex;
    if ((uint32_t)IntIndex < 0x100U)
    {
        /* PRQA S 3469 1 #KQR003469 */
        state = REG_BITS_READ(Module->STR.reg, (0x1UL << (uint32_t)IntIndex), (uint32_t)IntIndex) != 0U;
    }
    else
    {
        fifoIntIndex = (uint32_t)IntIndex - 0x100U;
        /* PRQA S 3469 1 #KQR003469 */
        state = REG_BITS_READ(Module->FIFOCTL.reg, (0x1UL << (uint32_t)fifoIntIndex), (uint32_t)fifoIntIndex) != 0U;
    }

    return state;
}

/**
 * @brief DMA写SPI FIFO寄存器使能
 *
 * @param Module Module 指向SPI寄存器结构的指针
 * @param State 使能状态
 *                  true      使能
 *                  false      不使能
 * @retval void
 */
KF_INLINE void Spi_LL_SetTxFifoDmaEnabled(Spi_RegisterMap_t *const Module, bool State)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));

    Module->STR.bits.STXFIFODE = State ? 1U : 0U;
}

/**
 * @brief DMA读SPI FIFO寄存器使能
 *
 * @param Module Module 指向SPI寄存器结构的指针
 * @param State 使能状态
 *                  true      使能
 *                  false      不使能
 * @retval void
 */
KF_INLINE void Spi_LL_SetRxFifoDmaEnabled(Spi_RegisterMap_t *const Module, bool State)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));

    Module->STR.bits.SRXFIFODE = State ? 1U : 0U;
}

/**
 * @brief DMA写SPI数据寄存器使能
 *
 * @param Module Module 指向SPI寄存器结构的指针
 * @param State 使能状态
 *                  true      使能
 *                  false      不使能
 * @retval void
 */
KF_INLINE void Spi_LL_SetDmaWriteEnabled(Spi_RegisterMap_t *const Module, bool State)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));

    Module->STR.bits.STXDE = State ? 1U : 0U;
}

/**
 * @brief DMA读SPI数据寄存器使能
 *
 * @param Module Module 指向SPI寄存器结构的指针
 * @param State 使能状态
 *                  true      使能
 *                  false      不使能
 * @retval void
 */
KF_INLINE void Spi_LL_SetDmaReadEnabled(Spi_RegisterMap_t *const Module, bool State)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));

    Module->STR.bits.SRCDE = State ? 1U : 0U;
}

/**
 * @brief Enable Spi Module
 * @param Module
 * @retval None
 */
KF_INLINE void Spi_LL_Enable(Spi_RegisterMap_t *const Module)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));

    /* Select SPI */
    Spi_LL_SelectSPIMode(Module, false);
    /* SPI Enable */
    Spi_LL_SetEnabled(Module, true);
}

/**
 * @brief Disable Spi Module
 * @param Module
 * @retval None
 */
KF_INLINE void Spi_LL_Disable(Spi_RegisterMap_t *const Module)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));

    Spi_LL_SetEnabled(Module, false);
}

/**
 * @brief Set Spi Module Clock Mode
 * @param Module
 * @param clkMode
 * @retval None
 */
KF_INLINE void Spi_LL_SetClockMode(Spi_RegisterMap_t *const Module, Spi_ClockMode_t ClkMode)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
    KF_SPI_ASSERT(CHECK_SPI_CLOCKMODE(ClkMode));

    switch (ClkMode)
    {
    case SPI_CLOCK_MODE_0: {
        Spi_LL_SetClockPolarity(Module, SPI_CPOL_0);
        Spi_LL_SetClockPhase(Module, SPI_CPHA_0);
    }
    break;
    case SPI_CLOCK_MODE_1: {
        Spi_LL_SetClockPolarity(Module, SPI_CPOL_0);
        Spi_LL_SetClockPhase(Module, SPI_CPHA_1);
    }
    break;
    case SPI_CLOCK_MODE_2: {
        Spi_LL_SetClockPolarity(Module, SPI_CPOL_1);
        Spi_LL_SetClockPhase(Module, SPI_CPHA_0);
    }
    break;
    case SPI_CLOCK_MODE_3: {
        Spi_LL_SetClockPolarity(Module, SPI_CPOL_1);
        Spi_LL_SetClockPhase(Module, SPI_CPHA_1);
    }
    break;

    default:
        KF_SPI_ASSERT(false);
        break;
    }
}

/**
 * @brief 配置SPI 延时周期寄存器
 *
 * @param Module: 指向Spi_RegisterMap_t内存结构的指针
 * @param DelayPeriod: SPI 延时周期
 * @retval None
 */
KF_INLINE void Spi_LL_SetDelayPeriod(Spi_RegisterMap_t *const Module, uint16_t DelayPeriod)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));

    Module->PPX.bits.SPIPPX = DelayPeriod;
}

/**
 * @brief 配置片选信号延时功能使能状态
 *
 * @param Module: 指向Spi_RegisterMap_t内存结构的指针
 * @param State: true -- 使能片选信号延时功能, false -- 关闭片选信号延时功能
 * @retval None
 */
KF_INLINE void Spi_LL_SetChipSelectSignalDelayEnable(Spi_RegisterMap_t *const Module, bool State)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));

    Module->PPX.bits.TESTEN_CSDELAY = (State ? 1UL : 0UL);
}

/**
 * @brief 写SPI TXFIFO寄存器
 *
 * @param Module 指向SPI寄存器结构的指针
 * @param Data 写入的数据
 * @retval void
 */
KF_INLINE void Spi_LL_WriteTxFifo(Spi_RegisterMap_t *const Module, uint32_t Data)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));

    Module->TXFIFO = Data;
}

/**
 * @brief: Spi Get Txfifo Reg Pointer
 *
 * @param Module SPI寄存器结构体指针
 * @retval uint32_t* SPI Txfifo 指针
 */
KF_INLINE uint32_t const volatile *Spi_LL_GetTxFifoPtr(Spi_RegisterMap_t const *const Module)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));

    return (uint32_t const volatile *)&Module->TXFIFO;
}

/**
 * @brief 读SPI RXFIFO寄存器
 *
 * @param Module 指向SPI寄存器结构的指针
 * @retval uint32_t 读取的数据
 */
KF_INLINE uint32_t Spi_LL_ReadRxFifo(const Spi_RegisterMap_t *const Module)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));

    return Module->RXFIFO;
}

/**
 * @brief: Spi Get Rxfifo Reg Pointer
 *
 * @param Module SPI寄存器结构体指针
 * @retval uint32_t* SPI Rxfifo 指针
 */
KF_INLINE uint32_t const volatile *Spi_LL_GetRxFifoPtr(Spi_RegisterMap_t const *const Module)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));

    return (uint32_t const volatile *)&Module->RXFIFO;
}

/**
 * @brief 设置TXFIFO使能
 *
 * @param Module 指向SPI寄存器结构的指针
 * @param State 使能状态
 *                  true      使能
 *                  false      不使能
 * @retval void
 */
KF_INLINE void Spi_LL_SetTxFifoEnabled(Spi_RegisterMap_t *const Module, bool State)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));

    Module->FIFOCTL.bits.TXFIFOEN = (State ? 1U : 0U);
}

/**
 * @brief 获取TXFIFO满标志
 *
 * @param Module 指向SPI寄存器结构的指针
 * @retval bool
 *                  true      TXFIFO已满
 *                  false     TXFIFO未满
 */
KF_INLINE bool Spi_LL_IsTxFifoFull(const Spi_RegisterMap_t *const Module)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));

    return Module->FIFOCTL.bits.TXFIFOFULL != 0U;
}

/**
 * @brief 获取TXFIFO空标志
 *
 * @param Module 指向SPI寄存器结构的指针
 * @retval bool
 *                  true      TXFIFO为空
 *                  false     TXFIFO不为空
 */
KF_INLINE bool Spi_LL_IsTxFifoEmpty(const Spi_RegisterMap_t *const Module)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));

    return Module->FIFOCTL.bits.TXFIFOEMPTY != 0U;
}

/**
 * @brief 设置TXFIFO高阈值
 *
 * @param Module 指向SPI寄存器结构的指针
 * @param Threshold 阈值 (0-7)
 * @retval void
 */
KF_INLINE void Spi_LL_SetTxFifoHighThreshold(Spi_RegisterMap_t *const Module, uint8_t Threshold)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
    KF_SPI_ASSERT(CHECK_SPI_FIFO_THRESHOLD(Threshold));

    Module->FIFOCTL.bits.TXFIFOHT = Threshold;
}

/**
 * @brief 获取TXFIFO高阈值中断标志
 *
 * @param Module 指向SPI寄存器结构的指针
 * @retval bool
 *                  true      触发高阈值中断
 *                  false     未触发高阈值中断
 */
KF_INLINE bool Spi_LL_GetTxFifoHighThresholdFlag(const Spi_RegisterMap_t *const Module)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));

    return Module->FIFOCTL.bits.TXFIFOHTIF != 0U;
}

/**
 * @brief 设置TXFIFO低阈值
 *
 * @param Module 指向SPI寄存器结构的指针
 * @param Threshold 阈值 (0-7)
 * @retval void
 */
KF_INLINE void Spi_LL_SetTxFifoLowThreshold(Spi_RegisterMap_t *const Module, uint8_t Threshold)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
    KF_SPI_ASSERT(CHECK_SPI_FIFO_THRESHOLD(Threshold));

    Module->FIFOCTL.bits.TXFIFOLT = Threshold;
}

/**
 * @brief 获取TXFIFO低阈值中断标志
 *
 * @param Module 指向SPI寄存器结构的指针
 * @retval bool
 *                  true      触发低阈值中断
 *                  false     未触发低阈值中断
 */
KF_INLINE bool Spi_LL_GetTxFifoLowThresholdFlag(const Spi_RegisterMap_t *const Module)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));

    return Module->FIFOCTL.bits.TXFIFOLTIF != 0U;
}

/**
 * @brief 获取TXFIFO中的数据个数
 *
 * @param Module 指向SPI寄存器结构的指针
 * @retval uint8_t TXFIFO中的数据个数
 */
KF_INLINE uint8_t Spi_LL_GetTxFifoCount(const Spi_RegisterMap_t *const Module)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));

    return (uint8_t)Module->FIFOCTL.bits.TXFIFOCNT;
}

/**
 * @brief 设置RXFIFO使能
 *
 * @param Module 指向SPI寄存器结构的指针
 * @param State 使能状态
 *                  true      使能
 *                  false      不使能
 * @retval void
 */
KF_INLINE void Spi_LL_SetRxFifoEnabled(Spi_RegisterMap_t *const Module, bool State)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));

    Module->FIFOCTL.bits.RXFIFOEN = (State ? 1U : 0U);
}

/**
 * @brief 获取RXFIFO满标志
 *
 * @param Module 指向SPI寄存器结构的指针
 * @retval bool
 *                  true      RXFIFO已满
 *                  false     RXFIFO未满
 */
KF_INLINE bool Spi_LL_IsRxFifoFull(const Spi_RegisterMap_t *const Module)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));

    return Module->FIFOCTL.bits.RXFIFOFULL != 0U;
}

/**
 * @brief 获取RXFIFO空标志
 *
 * @param Module 指向SPI寄存器结构的指针
 * @retval bool
 *                  true      RXFIFO为空
 *                  false     RXFIFO不为空
 */
KF_INLINE bool Spi_LL_IsRxFifoEmpty(const Spi_RegisterMap_t *const Module)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));

    return Module->FIFOCTL.bits.RXFIFOEMPTY != 0U;
}

/**
 * @brief 设置RXFIFO高阈值
 *
 * @param Module 指向SPI寄存器结构的指针
 * @param Threshold 阈值 (0-7)
 * @retval void
 */
KF_INLINE void Spi_LL_SetRxFifoHighThreshold(Spi_RegisterMap_t *const Module, uint8_t Threshold)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
    KF_SPI_ASSERT(CHECK_SPI_FIFO_THRESHOLD(Threshold));

    Module->FIFOCTL.bits.RXFIFOHT = Threshold;
}

/**
 * @brief 获取RXFIFO高阈值中断标志
 *
 * @param Module 指向SPI寄存器结构的指针
 * @retval bool
 *                  true      触发高阈值中断
 *                  false     未触发高阈值中断
 */
KF_INLINE bool Spi_LL_GetRxFifoHighThresholdFlag(const Spi_RegisterMap_t *const Module)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));

    return Module->FIFOCTL.bits.RXFIFOHTIF != 0U;
}

/**
 * @brief 设置RXFIFO低阈值
 *
 * @param Module 指向SPI寄存器结构的指针
 * @param Threshold 阈值 (0-7)
 * @retval void
 */
KF_INLINE void Spi_LL_SetRxFifoLowThreshold(Spi_RegisterMap_t *const Module, uint8_t Threshold)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
    KF_SPI_ASSERT(CHECK_SPI_FIFO_THRESHOLD(Threshold));

    Module->FIFOCTL.bits.RXFIFOLT = Threshold;
}

/**
 * @brief 获取RXFIFO低阈值中断标志
 *
 * @param Module 指向SPI寄存器结构的指针
 * @retval bool
 *                  true      触发低阈值中断
 *                  false     未触发低阈值中断
 */
KF_INLINE bool Spi_LL_GetRxFifoLowThresholdFlag(const Spi_RegisterMap_t *const Module)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));

    return Module->FIFOCTL.bits.RXFIFOLTIF != 0U;
}

/**
 * @brief 获取RXFIFO中的数据个数
 *
 * @param Module 指向SPI寄存器结构的指针
 * @retval uint8_t RXFIFO中的数据个数
 */
KF_INLINE uint8_t Spi_LL_GetRxFifoCount(const Spi_RegisterMap_t *const Module)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));

    return (uint8_t)Module->FIFOCTL.bits.RXFIFOCNT;
}

/**
 * @brief 获取SPI中断发生状态
 * @param Module 指向SPI寄存器结构的指针
 * @param IntIndex Spi_IntrSetIndex_t
 * @retval bool 中断发生状态
 *         true    发生了中断，且已使能
 *         false    未发生中断，或未使能
 */
KF_INLINE bool Spi_LL_GetIntrState(const Spi_RegisterMap_t *const Module, Spi_IntrGetIndex_t IntIndex)
{
    KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
    KF_SPI_ASSERT(CHECK_SPI_INTRGETINDEX(IntIndex));
    uint32_t mask  = 0;
    bool     flag  = Spi_LL_GetIntrFlag(Module, IntIndex);
    bool     state = false;
    switch (IntIndex)
    {
    case SPI_INTR_GET_RNE:
        state = (Module->STR.bits.RNEIE != 0U) ? true : false;
        break;
    case SPI_INTR_GET_TNE:
        state = (Module->STR.bits.TNEIE != 0U) ? true : false;
        break;
    case SPI_INTR_GET_ROVFIF:
    case SPI_INTR_GET_TOVFIF:
        mask = (uint32_t)IntIndex + (uint32_t)SPI_INTR_SET_ROVFIE - (uint32_t)SPI_INTR_GET_ROVFIF;
        /* PRQA S 3469 1 #KQR003469 */
        state = (REG_BITS_READ(Module->STR.reg, (0x1UL << mask), mask) != 0U) ? true : false;
        break;
    case SPI_INTR_GET_UDRIF:
        state = (Module->STR.bits.UDRIE != 0U) ? true : false;
        break;
    case SPI_INTR_GET_TSTOP:
        state = (Module->STR.bits.TSTOPIE != 0U) ? true : false;
        break;
    case SPI_INTR_GET_TXFIFOHTIF:
        state = (Module->STR.bits.TXFIFOHTIE != 0U) ? true : false;
        break;
    case SPI_INTR_GET_TXFIFOLTIF:
        state = (Module->STR.bits.TXFIFOLTIE != 0U) ? true : false;
        break;
    case SPI_INTR_GET_RXFIFOHTIF:
        state = (Module->STR.bits.RXFIFOHTIE != 0U) ? true : false;
        break;
    case SPI_INTR_GET_RXFIFOLTIF:
        state = (Module->STR.bits.RXFIFOLTIE != 0U) ? true : false;
        break;

    default:
        /* Intentionally Empty */
        break;
    }
    return flag && state;
}

#ifdef __cplusplus
}
#endif /*End of __cplusplus*/
#endif /*End of KF32A158SF_DRV_SPI_H*/
/* EOF */
