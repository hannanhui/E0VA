/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name        : kf32a158sf_drv_canfd.h
 *  @Date             : 2025-07-11
 *  @Version          : {{VersionDate}}
 *  @Description      : This file provides canfd driver.
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
 *  |2025-07-11  |V1.0     |AE Group     |New create
 ******************************************************************************/
#ifndef KF32A158SF_DRV_CANFD_H
#define KF32A158SF_DRV_CANFD_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      QAC Warnings
 ******************************************************************************/
/* PRQA S 3205 EOF #KQR003205 */
/* PRQA S 3219 EOF #KQR003219 */
/* PRQA S 3469 EOF #KQR003469 */
/* PRQA S 3473 EOF #KQR003473 */

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include "kf32a158sf_reg_canfd.h"

/******************************************************************************
 *                      Macro or Inline
 ******************************************************************************/
#ifdef KF_DRV_CANFD_ASSERT
#include "dev_assert.h"
#define KF_CANFD_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_CANFD_ASSERT(x) ((void)0U)
#endif

/**
 * @brief Enable Swap endian feature or not
 */
#define CAN_FEATURE_SWAP_ENABLE (true)

/**
 * @brief Mask of error interrupt
 */
#define CAN_CTRL1_RWRNMSK_MASK  ((uint32_t)0x00000400U)
#define CAN_CTRL1_TWRNMSK_MASK  ((uint32_t)0x00000800U)
#define CAN_CTRL1_ERRMSK_MASK   ((uint32_t)0x00004000U)
#define CAN_CTRL1_BOFFMSK_MASK  ((uint32_t)0x00008000U)
#define CAN_CTRL1_ERR_INTR_MASK ((uint32_t)0x0000CC00U)

/**
 * @brief Mask of CANFD interrupt flag
 */
#define CANFD_ALL_INT (0x003B0007U)

/**
 * @brief Mask of CANFD interrupt flag
 */
#define CAN_IMASK1_BUF31TO0M_MASK  (0xFFFFFFFFU)
#define CAN_IMASK2_BUF63TO32M_MASK (0xFFFFFFFFU)

/**
 * @brief
 */
#define CANFD_FORMAT_AB_IDE_SHIFT (30U)
#define CANFD_FORMAT_AB_RTR_SHIFT (31U)

#define CANFD_FORMAT_A_STD_SHIFT (19U)
#define CANFD_FORMAT_A_EXT_SHIFT (1U)
#define CANFD_FORMAT_A_EXT_MASK  (0x3FFFFFFEU)
#define CANFD_FORMAT_A_STD_MASK  (0x3FF80000U)

#define CANFD_FORMAT_B_IDE_SHIFT      (14U)
#define CANFD_FORMAT_B_RTR_SHIFT      (15U)
#define CANFD_FORMAT_B_STD_SHIFT1     (19U)
#define CANFD_FORMAT_B_EXT_SHIFT1     (16U)
#define CANFD_FORMAT_B_STD_SHIFT2     (3U)
#define CANFD_FORMAT_B_SHIFT1         (16U)
#define CANFD_FORMAT_B_EXT_SHIFT2     (0U)
#define CANFD_FORMAT_B_STD_MASK       (0x7FFU)
#define CANFD_FORMAT_B_EXT_MASK       (0x3FFFU)
#define CANFD_FORMAT_B_EXT_MASK1      (0x1FFF8000U)
#define CANFD_FORMAT_B_ID_RIGHT_SHIFT (15U)

#define CANFD_FORMAT_C_MASK            (0xFFU)
#define CANFD_FORMAT_C_SHIFT1          (24U)
#define CANFD_FORMAT_C_SHIFT2          (16U)
#define CANFD_FORMAT_C_SHIFT3          (8U)
#define CANFD_FORMAT_C_SHIFT4          (0U)
#define CANFD_FORMAT_C_EXT_MASK        (0x1FE00000U)
#define CANFD_FORMAT_C_STD_MASK        (0x7F8U)
#define CANFD_FORMAT_C_EXT_RIGHT_SHIFT (21U)
#define CANFD_FORMAT_C_STD_RIGHT_SHIFT (3U)

#define CAFND_RX_FIFO_ACCEPT_RTR_FRAME (0x1U)
#define CAFND_RX_FIFO_ACCEPT_EXT_FRAME (0x1U)

/**
 * @brief Mask of CS memory structure
 */
#define CANFD_CS_CODE_MASK    (0x0F000000U)
#define CANFD_CS_RTR_MASK     (0x00100000U)
#define CANFD_CS_IDE_MASK     (0x00200000U)
#define CANFD_CS_DLC_MASK     (0x000F0000U)
#define CANFD_CS_SRR_MASK     (0x00400000U)
#define CANFD_CS_EDL_MASK     (0x80000000U)
#define CANFD_CS_BRS_MASK     (0x40000000U)
#define CANFD_CS_DLC_SHIFT    (16U)
#define CANFD_CS_CODE_SHIFT   (24U)
#define CANFD_CS_CODE_DEFAULT (0U)
#define CANFD_ID_STD_SHIFT    (18U)

/**
 * @brief
 */
#define CANFD_NORMAL_RX_FIFO_FILTER_TABLE_OFFSET (0x18U)

/**
 * @brief Options mask
 */
/** @brief Remote Request Store enable */
#define CANFD_OPTIONS_REMOTE_STORE ((uint32_t)0x00000001U)
/** @brief Define how controller recover from bus off state */
#define CANFD_OPTIONS_BUSOFF_RECOVERY ((uint32_t)0x00000002U)
/** @brief Protocol Exception */
#define CANFD_OPTIONS_PROTOCOL_EXCEPTION ((uint32_t)0x00000004U)
/** @brief Edge Filter */
#define CANFD_OPTIONS_EDGE_FILTER ((uint32_t)0x00000008U)
/** @brief CAN FD protocol according to ISO specification (ISO 11898-1) */
#define CANFD_OPTIONS_ISO ((uint32_t)0x00000010U)
/** @brief Remote Frame Arbitration Field Comparison */
#define CANFD_OPTIONS_EACEN ((uint32_t)0x00000020U)

/**
 * @brief Enhanced Fifo Embedded RAM address offset
 */
#define CANFD_ENHANCED_RX_FIFO_RAM_OFFSET (0x2000U)

/**
 * @brief Mask of Canfd bus interrupt
 */
#define CANFD_ESR1_ERRINT_MASK    (0x2U)
#define CANFD_ESR1_BOFFINT_MASK   (0x4U)
#define CANFD_ESR1_ERRINT_FD_MASK (0x100000U)
#define CANFD_ESR1_TWRNINT_MASK   (0x20000U)
#define CANFD_ESR1_RWRNINTT_MASK  (0x10000U)

/**
 * @brief Mask of Error Correct interrupt
 */
#define CANFD_MECR_HANCEI_MSK_MASK (0x80000U)
#define CANFD_MECR_FANCEI_MSK_MASK (0x40000U)
#define CANFD_MECR_CEI_MSK_MASK    (0x10000U)
#define CANFD_MECR_CEI_ALL_MASK    (0xD0000U)

/**
 * @brief Maximum threshold values for DLC
 */
#define CANFD_MAX_DLC8  ((uint32_t)8U)
#define CANFD_MAX_DLC9  ((uint32_t)12U)
#define CANFD_MAX_DLC10 ((uint32_t)16U)
#define CANFD_MAX_DLC11 ((uint32_t)20U)
#define CANFD_MAX_DLC12 ((uint32_t)24U)
#define CANFD_MAX_DLC13 ((uint32_t)32U)
#define CANFD_MAX_DLC14 ((uint32_t)48U)
#define CANFD_MAX_DLC15 ((uint32_t)64U)
/**
 * @brief Minimum threshold values for DLC
 */
#define CANFD_MIN_DLC8  ((uint32_t)0U)
#define CANFD_MIN_DLC9  ((uint32_t)9U)
#define CANFD_MIN_DLC10 ((uint32_t)13U)
#define CANFD_MIN_DLC11 ((uint32_t)17U)
#define CANFD_MIN_DLC12 ((uint32_t)21U)
#define CANFD_MIN_DLC13 ((uint32_t)25U)
#define CANFD_MIN_DLC14 ((uint32_t)33U)
#define CANFD_MIN_DLC15 ((uint32_t)49U)
/**
 * @brief Maximum threshold values for Payload
 */
#define CANFD_PAYLOAD_8  ((uint8_t)8U)
#define CANFD_PAYLOAD_16 ((uint8_t)16U)
#define CANFD_PAYLOAD_32 ((uint8_t)32U)
#define CANFD_PAYLOAD_64 ((uint8_t)64U)
/**
 * @brief Maximum mailbox number
 */
#define CANFD_MAX_MB_PAYLOAD_8  ((uint8_t)32U)
#define CANFD_MAX_MB_PAYLOAD_16 ((uint8_t)21U)
#define CANFD_MAX_MB_PAYLOAD_32 ((uint8_t)12U)
#define CANFD_MAX_MB_PAYLOAD_64 ((uint8_t)7U)

/**
 * @defgroup  Canfd enhanced Rx FIFO status, Canfd_EnhancedRxFifoIntrMask_t
 * @{
 */
#define CANFD_ENHANCED_RX_FIFO_UNDERFLOW   (0x80000000U)
#define CANFD_ENHANCED_RX_FIFO_OVERFLOW    (0x40000000U)
#define CANFD_ENHANCED_RX_FIFO_WATER_MARK  (0x20000000U)
#define CANFD_ENHANCED_RX_FIFO_DATA_USEFUL (0x10000000U)

#define CHECK_CANFD_ENHANCED_RX_FIFO_INTR_MASK(x)                                                                      \
    (((uint32_t)(x) == (uint32_t)CANFD_ENHANCED_RX_FIFO_UNDERFLOW) ||                                                  \
     ((uint32_t)(x) == (uint32_t)CANFD_ENHANCED_RX_FIFO_OVERFLOW) ||                                                   \
     ((uint32_t)(x) == (uint32_t)CANFD_ENHANCED_RX_FIFO_WATER_MARK) ||                                                 \
     ((uint32_t)(x) == (uint32_t)CANFD_ENHANCED_RX_FIFO_DATA_USEFUL))
/** @} */

/******************************************************************************
 *                      Type definitions
 ******************************************************************************/
/* PRQA S 3630 ++ #KQR003630 */
/* PRQA S 0660 ++ #KQR000660 */

/**
 * @brief Clock source of Canfd
 */
typedef enum
{
    /** oscillator clock. */
    CANFD_CLK_SOURCE_OSC = 0U,
    /** peripheral clock. */
    CANFD_CLK_SOURCE_PERIPH = 1U,
} Canfd_ClkSource_t;
#define CHECK_CANFD_CLK_SOURCE(x)                                                                                      \
    (((uint32_t)(x) == (uint32_t)CANFD_CLK_SOURCE_OSC) || ((uint32_t)(x) == (uint32_t)CANFD_CLK_SOURCE_PERIPH))

/**
 * @brief Sample times
 */
typedef enum
{
    CANFD_SAM_ONE_TIME   = 0U,
    CANFD_SAM_THREE_TIME = 1U,
} Canfd_SampleTime_t;
#define CHECK_CANFD_SAMPLE_TIME(x)                                                                                     \
    (((uint32_t)(x) == (uint32_t)CANFD_SAM_ONE_TIME) || ((uint32_t)(x) == (uint32_t)CANFD_SAM_THREE_TIME))

/**
 * @brief Mailbox index
 */
typedef enum
{
    CANFD_MAILBOX0,
    CANFD_MAILBOX1,
    CANFD_MAILBOX2,
    CANFD_MAILBOX3,
    CANFD_MAILBOX4,
    CANFD_MAILBOX5,
    CANFD_MAILBOX6,
    CANFD_MAILBOX7,
    CANFD_MAILBOX8,
    CANFD_MAILBOX9,
    CANFD_MAILBOX10,
    CANFD_MAILBOX11,
    CANFD_MAILBOX12,
    CANFD_MAILBOX13,
    CANFD_MAILBOX14,
    CANFD_MAILBOX15,
    CANFD_MAILBOX16,
    CANFD_MAILBOX17,
    CANFD_MAILBOX18,
    CANFD_MAILBOX19,
    CANFD_MAILBOX20,
    CANFD_MAILBOX21,
    CANFD_MAILBOX22,
    CANFD_MAILBOX23,
    CANFD_MAILBOX24,
    CANFD_MAILBOX25,
    CANFD_MAILBOX26,
    CANFD_MAILBOX27,
    CANFD_MAILBOX28,
    CANFD_MAILBOX29,
    CANFD_MAILBOX30,
    CANFD_MAILBOX31,
    CANFD_MAILBOX32,
    CANFD_MAILBOX33,
    CANFD_MAILBOX34,
    CANFD_MAILBOX35,
    CANFD_MAILBOX36,
    CANFD_MAILBOX37,
    CANFD_MAILBOX38,
    CANFD_MAILBOX39,
    CANFD_MAILBOX40,
    CANFD_MAILBOX41,
    CANFD_MAILBOX42,
    CANFD_MAILBOX43,
    CANFD_MAILBOX44,
    CANFD_MAILBOX45,
    CANFD_MAILBOX46,
    CANFD_MAILBOX47,
    CANFD_MAILBOX48,
    CANFD_MAILBOX49,
    CANFD_MAILBOX50,
    CANFD_MAILBOX51,
    CANFD_MAILBOX52,
    CANFD_MAILBOX53,
    CANFD_MAILBOX54,
    CANFD_MAILBOX55,
    CANFD_MAILBOX56,
    CANFD_MAILBOX57,
    CANFD_MAILBOX58,
    CANFD_MAILBOX59,
    CANFD_MAILBOX60,
    CANFD_MAILBOX61,
    CANFD_MAILBOX62,
    CANFD_MAILBOX63,
    CANFD_MAILBOX_MAX,
} Canfd_MB_t;
#define CHECK_CANFD_MAILBOX_INDEX(x) ((uint32_t)(x) < (uint32_t)CANFD_MAILBOX_MAX)

/**
 * @brief Message ID type
 */
typedef enum
{
    /** Standard ID*/
    CANFD_MSG_ID_STD,
    /** Extended ID*/
    CANFD_MSG_ID_EXT,
} Canfd_IDType_t;
#define CHECK_CANFD_ID_TYPE(x)                                                                                         \
    (((uint32_t)(x) == (uint32_t)CANFD_MSG_ID_STD) || ((uint32_t)(x) == (uint32_t)CANFD_MSG_ID_EXT))

/**
 * @brief Send order
 */
typedef enum
{
    /** Lowest mailbox Number Send First*/
    CANFD_LOW_MAILBOX_FIRST,
    /** Highest Priority Send First*/
    CANFD_PRIORITY_FIRST
} Canfd_SendOrder_t;
#define CHECK_CANFD_SEND_ORDER(x)                                                                                      \
    (((uint32_t)(x) == (uint32_t)CANFD_LOW_MAILBOX_FIRST) || ((uint32_t)(x) == (uint32_t)CANFD_PRIORITY_FIRST))

/**
 *  @brief Canfd message buffer CODE for Rx buffers
 */
typedef enum
{
    /** MB is not active.*/
    CANFD_RX_INACTIVE = 0x00U,
    /** MB is full.*/
    CANFD_RX_FULL = 0x02U,
    /** MB is active and empty.*/
    CANFD_RX_EMPTY = 0x04U,
    /** MB is overwritten into a full buffer.*/
    CANFD_RX_OVERRUN = 0x06U,
    /** CANFD is updating the contents of the MB. The CPU must not access the MB.*/
    CANFD_RX_BUSY = 0x08U,
    /** A frame was configured to recognize a Remote Request Frame and transmit a Response Frame in return. an incoming
     * Remote Request Frame.*/
    CANFD_RX_RANSWER = 0x0AU,
    /** Not used*/
    CANFD_RX_NOTUSED = 0x0FU,
} Canfd_RxCode_t;
#define CHECK_CANFD_RX_CODE(x)                                                                                         \
    (((uint32_t)(x) == (uint32_t)CANFD_RX_INACTIVE) || ((uint32_t)(x) == (uint32_t)CANFD_RX_FULL) ||                   \
     ((uint32_t)(x) == (uint32_t)CANFD_RX_EMPTY) || ((uint32_t)(x) == (uint32_t)CANFD_RX_OVERRUN) ||                   \
     ((uint32_t)(x) == (uint32_t)CANFD_RX_BUSY) || ((uint32_t)(x) == (uint32_t)CANFD_RX_RANSWER) ||                    \
     ((uint32_t)(x) == (uint32_t)CANFD_RX_NOTUSED))

/**
 *  @brief Canfd message buffer CODE for Tx buffers
 */
typedef enum
{
    /** MB is not active.*/
    CANFD_TX_INACTIVE = 0x08U,
    /** MB is aborted.*/
    CANFD_TX_ABORT = 0x09U,
    /** MB is a TX Data Frame(MB RTR must be 0).*/
    CANFD_TX_DATA = 0x0CU,
    /** MB is a TX Remote Request Frame (MB RTR must be 1).*/
    CANFD_TX_REMOTE = 0x1CU,
    /** MB is a TX Response Request Frame from.*/
    CANFD_TX_TANSWER = 0x0EU,
    /** Not used*/
    CANFD_TX_NOTUSED = 0x0FU,
} Canfd_TxCode_t;
#define CHECK_CANFD_TX_CODE(x)                                                                                         \
    (((uint32_t)(x) == (uint32_t)CANFD_TX_INACTIVE) || ((uint32_t)(x) == (uint32_t)CANFD_TX_ABORT) ||                  \
     ((uint32_t)(x) == (uint32_t)CANFD_TX_DATA) || ((uint32_t)(x) == (uint32_t)CANFD_TX_REMOTE) ||                     \
     ((uint32_t)(x) == (uint32_t)CANFD_TX_TANSWER) || ((uint32_t)(x) == (uint32_t)CANFD_TX_NOTUSED))

/**
 *  @brief Canfd error interrupt types
 */
typedef enum
{
    /** RX warning interrupt*/
    CANFD_INTR_RX_WARNING = CAN_CTRL1_RWRNMSK_MASK,
    /** TX warning interrupt*/
    CANFD_INTR_TX_WARNING = CAN_CTRL1_TWRNMSK_MASK,
    /** Error interrupt*/
    CANFD_INTR_ERR = CAN_CTRL1_ERRMSK_MASK,
    /** Bus off interrupt*/
    CANFD_INTR_BUSOFF = CAN_CTRL1_BOFFMSK_MASK,
} Canfd_ErrorIntr_t;
#define CHECK_CANFD_ERROR_INTR(x)                                                                                      \
    (((uint32_t)(x) == (uint32_t)CANFD_INTR_RX_WARNING) || ((uint32_t)(x) == (uint32_t)CANFD_INTR_TX_WARNING) ||       \
     ((uint32_t)(x) == (uint32_t)CANFD_INTR_ERR) || ((uint32_t)(x) == (uint32_t)CANFD_INTR_BUSOFF))

/**
 * @brief Canfd Ram Region index
 */
typedef enum
{
    /** Ram Block Region0*/
    CANFD_REGION_0 = 0x0U,
    /** Ram Block Region1*/
    CANFD_REGION_1 = 0x1U,
} Canfd_Region_t;
#define CHECK_CANFD_REGION_INDEX(x) ((uint32_t)(x) <= (uint32_t)CANFD_REGION_1)

/**
 * @brief Canfd payload sizes
 */
typedef enum
{
    /** Canfd message buffer payload size in bytes*/
    CANFD_PAYLOAD_SIZE_8 = 0U,
    /** Canfd message buffer payload size in bytes*/
    CANFD_PAYLOAD_SIZE_16 = 1U,
    /** Canfd message buffer payload size in bytes*/
    CANFD_PAYLOAD_SIZE_32 = 2U,
    /** Canfd message buffer payload size in bytes*/
    CANFD_PAYLOAD_SIZE_64 = 3U,
} Canfd_PayloadSize_t;
#define CHECK_CANFD_PAYLOAD_SIZE(x) ((uint32_t)(x) <= (uint32_t)CANFD_PAYLOAD_SIZE_64)

/**
 * @brief Canfd Rx FIFO filters number
 */
typedef enum
{
    /**   8 Rx FIFO Filters. */
    CANFD_RX_FIFO_ID_FILTERS_8 = 0x0U,
    /**  16 Rx FIFO Filters. */
    CANFD_RX_FIFO_ID_FILTERS_16 = 0x1U,
    /**  24 Rx FIFO Filters. */
    CANFD_RX_FIFO_ID_FILTERS_24 = 0x2U,
    /**  32 Rx FIFO Filters. */
    CANFD_RX_FIFO_ID_FILTERS_32 = 0x3U,
    /**  40 Rx FIFO Filters. */
    CANFD_RX_FIFO_ID_FILTERS_40 = 0x4U,
    /**  48 Rx FIFO Filters. */
    CANFD_RX_FIFO_ID_FILTERS_48 = 0x5U,
    /**  56 Rx FIFO Filters. */
    CANFD_RX_FIFO_ID_FILTERS_56 = 0x6U,
    /**  64 Rx FIFO Filters. */
    CANFD_RX_FIFO_ID_FILTERS_64 = 0x7U,
    /**  72 Rx FIFO Filters. */
    CANFD_RX_FIFO_ID_FILTERS_72 = 0x8U,
    /**  80 Rx FIFO Filters. */
    CANFD_RX_FIFO_ID_FILTERS_80 = 0x9U,
    /**  88 Rx FIFO Filters. */
    CANFD_RX_FIFO_ID_FILTERS_88 = 0xAU,
    /**  96 Rx FIFO Filters. */
    CANFD_RX_FIFO_ID_FILTERS_96 = 0xBU,
    /** 104 Rx FIFO Filters. */
    CANFD_RX_FIFO_ID_FILTERS_104 = 0xCU,
    /** 112 Rx FIFO Filters. */
    CANFD_RX_FIFO_ID_FILTERS_112 = 0xDU,
    /** 120 Rx FIFO Filters. */
    CANFD_RX_FIFO_ID_FILTERS_120 = 0xEU,
    /** 128 Rx FIFO Filters. */
    CANFD_RX_FIFO_ID_FILTERS_128 = 0xFU,
} Canfd_NormalRxFifoFilterNum_t;
#define CHECK_CANFD_NORMAL_RX_FIFO_FILTER_NUM(x) ((uint32_t)(x) <= (uint32_t)CANFD_RX_FIFO_ID_FILTERS_128)

/**
 * @brief Canfd Rx FIFO Type
 */
typedef enum
{
    CANFD_NORMAL_RX_FIFO   = 0x0U,
    CANFD_ENHANCED_RX_FIFO = 0x1U,
} Canfd_RxFifoType_t;
#define CHECK_CANFD_RX_FIFO_TYPE(x) ((uint32_t)(x) <= (uint32_t)CANFD_ENHANCED_RX_FIFO)

/**
 * @brief Canfd Rx mask type
 */
typedef enum
{
    /** Rx global mask*/
    CANFD_RX_MASK_GLOBAL,
    /** Rx individual mask*/
    CANFD_RX_MASK_INDIVIDUAL,
} Canfd_RxMaskType_t;
#define CHECK_CANFD_RX_MASK_TYPE(x) ((uint32_t)(x) <= (uint32_t)CANFD_RX_MASK_INDIVIDUAL)

/**
 * @brief ID format for Rx FIFO
 */
typedef enum
{
    /** One full ID (standard and extended) per ID Filter Table element.*/
    CANFD_RX_FIFO_ID_FORMAT_A,
    /** Two full standard IDs or two partial 14-bit (standard and extended) IDs per ID Filter Table element.*/
    CANFD_RX_FIFO_ID_FORMAT_B,
    /** Four partial 8-bit Standard IDs per ID Filter Table element.*/
    CANFD_RX_FIFO_ID_FORMAT_C,
    /** All frames rejected.*/
    CANFD_RX_FIFO_ID_FORMAT_D
} Canfd_NormalRxFifoIDFormat_t;
#define CHECK_CANFD_NORMAL_RX_FIFO_ID_FORMAT(x) ((uint32_t)(x) <= (uint32_t)CANFD_RX_FIFO_ID_FORMAT_D)

/**
 * @brief Mode of Canfd
 */
typedef enum
{
    /** Normal mode or user mode  */
    CANFD_NORMAL_MODE,
    /** Listen-only mode  */
    CANFD_LISTEN_ONLY_MODE,
    /** Loop-back mode  */
    CANFD_LOOPBACK_MODE,
    /** Halt mode */
    CANFD_HALT_MODE,
    /** Module disable mode  */
    CANFD_DISABLE_MODE
} Canfd_Mode_t;
#define CHECK_CANFD_MODE(x) ((uint32_t)(x) <= (uint32_t)CANFD_DISABLE_MODE)

/**
 * @brief ISO CANFD or NON ISO CANFD
 */
typedef enum
{
    CANFD_NON_ISOMODE = 0U,
    CANFD_ISOMODE     = 1U,
} Canfd_IsoMode_t;
#define CHECK_CANFD_ISOMODE(x) ((uint32_t)(x) <= (uint32_t)CANFD_ISOMODE)

/* PRQA S 0750 ++ #KQR000750 */

/**
 * @brief
 *
 */
typedef union
{
    __IO uint32_t CS_CODE;
    struct
    {
        __IO uint32_t TIMESTAMP :16;
        __IO uint32_t DLC       :4;
        __IO uint32_t RTR       :1;
        __IO uint32_t IDE       :1;
        __IO uint32_t SRR       :1;
        __I uint32_t  RESERVED0 :1;
        __IO uint32_t CODE      :4;
        __I uint32_t  RESERVED1 :1;
        __IO uint32_t ESI       :1;
        __IO uint32_t BRS       :1;
        __IO uint32_t EDL       :1;
    };
} Canfd_Cs_t;

/**
 * @brief
 */
typedef union
{
    struct
    {
        __I uint32_t  RESERVED0 :18;
        __IO uint32_t ID        :11;
        __IO uint32_t PRIO      :3;
    } SFF;
    struct
    {
        __IO uint32_t ID   :29;
        __IO uint32_t PRIO :3;
    } EFF;
    __IO uint32_t reg;
} Canfd_ID_t;
/* PRQA S 0750 -- #KQR000750 */

/**
 * @brief Structure of Canfd Rx FIFO ID filter
 */
typedef struct
{
    /** Remote frame*/
    bool IsRemoteFrame;
    /** Extended frame*/
    bool IsExtendedFrame;
    /** Rx FIFO ID filter element*/
    uint32_t ID;
} Canfd_Filter_t;

/**
 * @brief Structure of Canfd bitrate
 */
typedef struct
{
    /** Propagation segment*/
    uint32_t PropSeg;
    /** Phase segment 1*/
    uint32_t TSeg1;
    /** Phase segment 2*/
    uint32_t TSeg2;
    /** Clock pre-scaler division factor*/
    uint32_t PreScaler;
    /** Resync jump width*/
    uint32_t Sjw;
    /** Sample time*/
    Canfd_SampleTime_t SampleTime;
} Canfd_ArbiTimeSegment_t;

/**
 * @brief Structure of Canfd bitrate
 */
typedef struct
{
    /** Propagation segment*/
    uint32_t PropSeg;
    /** Phase segment 1*/
    uint32_t HtSeg1;
    /** Phase segment 2*/
    uint32_t HtSeg2;
    /** Clock pre-scaler division factor*/
    uint32_t BrsPrescale;
    /** Resync jump width*/
    uint32_t Sjw;
} Canfd_DataTimeSegment_t;

/**
 * @brief Structure of Canfd baudrate
 */
typedef struct
{
    Canfd_ArbiTimeSegment_t *ArbiBaudrateConfig;
    Canfd_DataTimeSegment_t *DataBaudrateConfig;
} Canfd_Baudrate_t;

/* PRQA S 0750 ++ #KQR000750 */
/**
 * @brief Information needed for configing normal Rx fifo filters.
 */
typedef union
{
    struct
    {
        __I uint32_t  RESERVED0 :1;
        __IO uint32_t ID        :29;
        __IO uint32_t IDE       :1;
        __IO uint32_t RTR       :1;
    } FORMAT_A;
    struct
    {
        __IO uint32_t ID1  :14;
        __IO uint32_t IDE1 :1;
        __IO uint32_t RTR1 :1;
        __IO uint32_t ID0  :14;
        __IO uint32_t IDE0 :1;
        __IO uint32_t RTR0 :1;
    } FORMAT_B;
    struct
    {
        __IO uint32_t ID3 :8;
        __IO uint32_t ID2 :8;
        __IO uint32_t ID1 :8;
        __IO uint32_t ID0 :8;
    } FORMAT_C;
    __IO uint32_t reg;
} Canfd_NormalRxFifoFilter_t;

typedef struct
{
    /** Pointer to filter array. The length of array is 8 + (2*FilterNum) */
    Canfd_NormalRxFifoFilter_t *FilterPtr;
    /** Number of filter */
    Canfd_NormalRxFifoFilterNum_t FilterNum;
    /** Format of filter elements */
    Canfd_NormalRxFifoIDFormat_t IDFormat;
    /** Global filter ID type */
    Canfd_IDType_t GlobalIDType;
    /** Global filter mask */
    uint32_t GlobalMask;
} Canfd_NormalRxFifo_t;

/**
 * @brief Information needed for configing enhance Rx fifo filters which id is standard id.
 */
typedef union
{
    struct
    {
        __IO uint32_t IDMASK    :11;
        __IO uint32_t RTRMASK   :1;
        __I uint32_t  RESERVED1 :4;
        __IO uint32_t ID        :11;
        __IO uint32_t RTR       :1;
        __I uint32_t  RESERVED0 :2;
        __IO uint32_t FSCH      :2;
    } MASK_FILTER;
    struct
    {
        __IO uint32_t ID1       :11;
        __IO uint32_t RTRMASK   :1;
        __I uint32_t  RESERVED1 :4;
        __IO uint32_t ID2       :11;
        __IO uint32_t RTR       :1;
        __I uint32_t  RESERVED0 :2;
        __IO uint32_t FSCH      :2;
    } RANGE_FILTER;
    __IO uint32_t reg;
} Canfd_EnhancedRxFifoStandardIDFilter_t;
/**
 * @brief Information needed for configing enhance Rx fifo filters which id is extened id.
 */
typedef union
{
    struct
    {
        struct
        {
            __IO uint32_t ID   :29;
            __IO uint32_t RTR  :1;
            __IO uint32_t FSCH :2;
        };
        struct
        {
            __IO uint32_t IDMASK    :29;
            __IO uint32_t RTRTRMASK :1;
            __I uint32_t  RESERVED0 :2;
        };
    } MASK_FILTER;
    struct
    {
        struct
        {
            __IO uint32_t ID2  :29;
            __IO uint32_t RTR2 :1;
            __IO uint32_t FSCH :2;
        };
        struct
        {
            __IO uint32_t ID1       :29;
            __IO uint32_t RTR1      :1;
            __IO uint32_t RESERVED0 :2;
        };
    } RANGE_FILTER;
    __IO uint32_t reg[2];
} Canfd_EnhancedRxFifoExtendedIDFilter_t;
/* PRQA S 0750 -- #KQR000750 */

/**
 * @brief Structure of Canfd enhanced Rx fifo filter
 */
typedef struct
{
    Canfd_EnhancedRxFifoStandardIDFilter_t *StandardIDFilter;
    Canfd_EnhancedRxFifoExtendedIDFilter_t *ExtendedIDFilter;
} Canfd_EnhancedRxFifoFilter_t;

/**
 * @brief Canfd Enhanced Rx fifo structure
 */
typedef struct
{
    Canfd_EnhancedRxFifoFilter_t *FilterPtr;
    uint32_t                      StandardIDFilterNumber;
    uint32_t                      ExtendedIDFilterNumber;
    uint32_t                      WaterMark;
} Canfd_EnhancedRxFifo_t;

/**
 * @brief Structure of Canfd message info
 */
typedef struct
{
    /** Type of message ID (standard or extended)*/
    Canfd_IDType_t IDType;
    /** message ID */
    uint32_t MsgID;
    /** Length of Data in Bytes*/
    uint8_t DataLength;
    /** Enable or disable FD*/
    bool IsCanfd;
    /** Set a value for padding. It will be used when the data length code (DLC) specifies a bigger payload size than
     * dataLength to fill the MB */
    uint8_t FdPadding;
    /** Enable bit rate switch inside a CAN FD format frame*/
    bool BrsEnable;
    /** Specifies if the frame is standard or remote */
    bool IsRemote;
} Canfd_MsgInfo_t;
/**
 * @brief Canfd data info from user
 */
typedef struct
{
    Canfd_MsgInfo_t Info;
    /** Data bytes of the canfd message*/
    uint8_t *Data;
} Canfd_Msg_t;
/* PRQA S 3630 -- #KQR003630 */
/* PRQA S 0660 -- #KQR000660 */

/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/

/**
 * @brief Set FD enable state
 *
 * @param Module Pointer to Canfd
 * @param Status Enable or disable
 * @return void
 */
KF_INLINE void Canfd_LL_SetFdEnabled(Canfd_RegisterMap_t *Module, bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->CTL0.bits.FDEN, Status ? 1U : 0U);
}

/**
 * @brief Get FD enable state
 *
 * @param Module Pointer to Canfd
 * @return bool
 */
KF_INLINE bool Canfd_LL_GetFdEnabledState(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    return (REG_READ(Module->CTL0.bits.FDEN) != 0U) ? true : false;
}

/**
 * @brief Set Canfd soft reset
 *
 * @param Module Pointer to Canfd
 * @param Status (true: reset, false: not reset)
 * @return void
 */
KF_INLINE void Canfd_LL_SetSoftReset(Canfd_RegisterMap_t *Module, bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->CTL0.bits.SOFTRST, Status ? 1U : 0U);
}

/**
 * @brief Get Canfd soft reset state
 *
 * @param Module Pointer to Canfd
 * @return bool
 * @retval true : reset
 * @retval false : not reset
 */
KF_INLINE bool Canfd_LL_GetSoftResetState(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    return (REG_READ(Module->CTL0.bits.SOFTRST) != 0U) ? true : false;
}

/**
 * @brief Get Canfd ready state
 *
 * @attention Return is NOT SAME to KF32A13X user manual.
 *
 * @param Module Pointer to Canfd
 * @return bool
 * @retval true : ready
 * @retval false : not ready
 */
KF_INLINE bool Canfd_LL_GetReadyState(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    return (REG_READ(Module->CTL0.bits.NOTRDY) == 0U) ? true : false;
}

/**
 * @brief Set halt mode enable
 *
 * @param Module Pointer to Canfd
 * @param Status (true: enable, false: disable)
 * @return void
 */
KF_INLINE void Canfd_LL_SetHaltEnabled(Canfd_RegisterMap_t *Module, bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->CTL0.bits.SETUPEN, Status ? 1U : 0U);
}

/**
 * @brief Get halt mode enable state
 *
 * @param Module Pointer to Canfd
 * @return bool
 * @retval true : enable
 * @retval false : disable
 */
KF_INLINE bool Canfd_LL_GetHaltEnabledState(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    return (REG_READ(Module->CTL0.bits.SETUPEN) != 0U) ? true : false;
}

/**
 * @brief Get halt mode ack state
 *
 * @param Module Pointer to Canfd
 * @return bool
 * @retval true : in halt mode
 * @retval false : not in halt mode
 */
KF_INLINE bool Canfd_LL_GetHaltAck(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    return (REG_READ(Module->CTL0.bits.HALTACK) != 0U) ? true : false;
}

/**
 * @brief Get disable mode ack state
 *
 * @param Module Pointer to Canfd
 * @return bool
 * @retval true : in disable mode
 * @retval false : not in disable mode
 */
KF_INLINE bool Canfd_LL_GetDisableModeAck(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    return (REG_READ(Module->CTL0.bits.DMACK) != 0U) ? true : false;
}

/**
 * @brief Set halt mode enable
 *
 * @param Module Pointer to Canfd
 * @param Status (true: enable, false: disable)
 * @return void
 */
KF_INLINE void Canfd_LL_SetHaltRequestEnabled(Canfd_RegisterMap_t *Module, bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->CTL0.bits.HALT, Status ? 1U : 0U);
}

/**
 * @brief Set Canfd module enable
 *
 * @param Module Pointer to Canfd
 * @param Status (true: enable, false: disable)
 * @return void
 */
KF_INLINE void Canfd_LL_SetEnabled(Canfd_RegisterMap_t *Module, bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->CTL0.bits.DISEN, Status ? 0U : 1U);
}

/**
 * @brief Get Canfd module enable state
 *
 * @param Module Pointer to Canfd
 * @return bool
 * @retval true : enable
 * @retval false : disable
 */
KF_INLINE bool Canfd_LL_GetEnabledState(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    return ((REG_READ(Module->CTL0.bits.DISEN) != 0U) ? false : true);
}

/**
 * @brief Set Supervisor mode
 *
 * @param Module Pointer to Canfd
 * @param Status (true: in Supervisor mode, false: in User mode)
 * @return void
 */
KF_INLINE void Canfd_LL_SetSuperVisorMode(Canfd_RegisterMap_t *Module, bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->CTL0.bits.SUPV, Status ? 1U : 0U);
}

/**
 * @brief Set Warning interrupt enable
 *
 * @param Module Pointer to Canfd
 * @param Status (true: enable, false: disable)
 * @return void
 */
KF_INLINE void Canfd_LL_SetWarningIntrEnabled(Canfd_RegisterMap_t *Module, bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->CTL0.bits.WRNEN, Status ? 1U : 0U);
}

/**
 * @brief Set max mailbox number
 *
 * @param Module Pointer to Canfd
 * @param MaxMailboxNumber Max mailbox number(0 ~ 127)
 * @return void
 */
KF_INLINE void Canfd_LL_SetMaxMailboxCount(Canfd_RegisterMap_t *Module, uint32_t MaxMailboxNumber)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    KF_CANFD_ASSERT(MaxMailboxNumber <= 127U);

    REG_WRITE(Module->CTL0.bits.MAXMB, MaxMailboxNumber);
}

/**
 * @brief Get max mailbox number
 *
 * @param Module Pointer to Canfd
 * @return uint32_t (0 ~ 127)
 */
KF_INLINE uint32_t Canfd_LL_GetMaxMailboxCount(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    return ((uint32_t)REG_READ(Module->CTL0.bits.MAXMB));
}

/**
 * @brief Set self reception enable
 *
 * @attention NOT SAME to KF32A13X user manual.
 *
 * @param Module Pointer to Canfd
 * @param Status true: enable, false: disable
 * @return void
 */
KF_INLINE void Canfd_LL_SetSelfReceptionEnabled(Canfd_RegisterMap_t *Module, bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->CTL0.bits.SRXDIS, Status ? 0U : 1U);
}

/**
 * @brief Get last mailbox index that is occupied by Rx FIFO
 *
 * @param FilterNumber Filter number
 * @return uint32_t
 */
KF_INLINE uint32_t Canfd_LL_GetRxFifoOccupiedLastMailbox(uint32_t FilterNumber)
{
    return (5U + (((FilterNumber + 1U) << 3U) >> 2U));
}

/**
 * @brief Set normal Rx FIFO enable
 *
 * @param Module Pointer to Canfd
 * @param Status (true: enable, false: disable)
 * @return void
 */
KF_INLINE void Canfd_LL_SetNormalRxFifoEnabled(Canfd_RegisterMap_t *Module, bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->CTL0.bits.NRFEN, Status ? 1U : 0U);
}

/**
 * @brief Get normal Rx FIFO enable state
 *
 * @param Module Pointer to Canfd
 * @return bool
 * @retval true : enable
 * @retval false : disable
 */
KF_INLINE bool Canfd_LL_GetNormalRxFifoEnabledState(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    return (REG_READ(Module->CTL0.bits.NRFEN) != 0U) ? true : false;
}

/**
 * @brief Set Rx mask type, global or individual
 *
 * @param Module Pointer to Canfd
 * @param Type Mask type
 * @return void
 */
KF_INLINE void Canfd_LL_SetRxMaskType(Canfd_RegisterMap_t *Module, Canfd_RxMaskType_t Type)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    KF_CANFD_ASSERT(CHECK_CANFD_RX_MASK_TYPE(Type));

    REG_WRITE(Module->CTL0.bits.IRMQ, (uint32_t)Type);
}

/**
 * @brief Set ID format of normal Rx FIFO
 *
 * @param Module Pointer to Canfd
 * @param Mode ID format
 * @return void
 */
KF_INLINE void Canfd_LL_SetNormalRxFifoIDFormat(Canfd_RegisterMap_t *Module, Canfd_NormalRxFifoIDFormat_t Mode)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    KF_CANFD_ASSERT(CHECK_CANFD_NORMAL_RX_FIFO_ID_FORMAT(Mode));

    REG_WRITE(Module->CTL0.bits.NRFIDFM, (uint32_t)Mode);
}

/**
 * @brief Get ID format of normal Rx FIFO
 *
 * @param Module Pointer to Canfd
 * @return Canfd_NormalRxFifoIDFormat_t
 */
KF_INLINE Canfd_NormalRxFifoIDFormat_t Canfd_LL_GetRxFifoIDFormat(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    /* PRQA S 4342 1 #KQR004342 */
    return ((Canfd_NormalRxFifoIDFormat_t)REG_READ(Module->CTL0.bits.NRFIDFM));
}

/**
 * @brief Get Sleep mode Enable state
 *
 * @param Module Pointer to Canfd
 * @return bool
 * @retval true : enable
 * @retval false : disable
 */
KF_INLINE bool Canfd_LL_GetSleepModeEnabledState(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    /* PRQA S 4342 1 #KQR004342 */
    return (REG_READ(Module->CTL0.bits.DOZE) != 0U) ? true : false;
}

/**
 * @brief Set Sleep mode Enable state
 *
 * @param Module Pointer to Canfd
 * @param Status (true: enable, false: disable)
 * @return void
 */
KF_INLINE void Canfd_LL_SetSleepModeEnabled(Canfd_RegisterMap_t *Module, bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->CTL0.bits.DOZE, Status ? 1U : 0U);
}

/**
 * @brief Set listen only mode
 *
 * @param Module Pointer to Canfd
 * @param Status (true: enable listen only mode, false: disable listen only mode)
 * @return void
 */
KF_INLINE void Canfd_LL_SetListenOnlyMode(Canfd_RegisterMap_t *Module, bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->CTL1.bits.LOM, Status ? 1U : 0U);
}

/**
 * @brief Set loop back mode
 *
 * @param Module Pointer to Canfd
 * @param Status (true: enable loop back mode, false: disable loop back mode)
 * @return void
 */
KF_INLINE void Canfd_LL_SetLoopBackMode(Canfd_RegisterMap_t *Module, bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->CTL1.bits.LPB, Status ? 1U : 0U);
}

/**
 * @brief Set order of sending
 *
 * @param Module Pointer to Canfd
 * @param Order Order
 * @return void
 */
KF_INLINE void Canfd_LL_SetSendOrder(Canfd_RegisterMap_t *Module, Canfd_SendOrder_t Order)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    KF_CANFD_ASSERT(CHECK_CANFD_SEND_ORDER(Order));

    REG_WRITE(Module->CTL1.bits.LBUF, (uint32_t)Order);
}

/**
 * @brief Set error interrupt mask
 *
 * @param Module Pointer to Canfd
 * @param IntrMask Mask of interrupt, @ref Canfd_ErrorIntr_t
 * @return void
 */
KF_INLINE void Canfd_LL_SetErrorIntrMask(Canfd_RegisterMap_t *Module, uint32_t IntrMask)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    REG_BIT_SET(Module->CTL1.reg, IntrMask);
}

/**
 * @brief Clear error interrupt mask
 *
 * @param Module Pointer to Canfd
 * @param IntrMask Mask of interrupt, @ref Canfd_ErrorIntr_t
 * @return void
 */
KF_INLINE void Canfd_LL_ClearErrorIntrMask(Canfd_RegisterMap_t *Module, uint32_t IntrMask)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    REG_BIT_CLR(Module->CTL1.reg, IntrMask);
}

/**
 * @brief Get error interrupt mask
 *
 * @param Module Pointer to Canfd
 * @return uint32_t
 */
KF_INLINE uint32_t Canfd_LL_GetErrorIntrMask(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    return (REG_READ(Module->CTL1.reg) & CAN_CTRL1_ERR_INTR_MASK);
}

/**
 * @brief Select clock source of Canfd
 *
 * @param Module Pointer to Canfd
 * @param ClkSource Clock source of Canfd
 * @return void
 */
KF_INLINE void Canfd_LL_SelectClock(Canfd_RegisterMap_t *Module, Canfd_ClkSource_t ClkSource)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    KF_CANFD_ASSERT(CHECK_CANFD_CLK_SOURCE(ClkSource));

    REG_WRITE(Module->CTL1.bits.CLKSRC, (uint32_t)ClkSource);
}

/**
 * @brief Set hardware busoff recovery enabled
 *
 * @param Module Pointer to Canfd
 * @param Status true: enable bus off recovery, false: disable bus off recovery
 * @return void
 */
KF_INLINE void Canfd_LL_SetHardwareBusoffRecoveryEnabled(Canfd_RegisterMap_t *Module, bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->CTL1.bits.BOFFREC, Status ? 0U : 1U);
}

/**
 * @brief Set sample time
 *
 * @param Module Pointer to Canfd
 * @param SampleTime Sample time
 * @return void
 */
KF_INLINE void Canfd_LL_SetSampleTime(Canfd_RegisterMap_t *Module, Canfd_SampleTime_t SampleTime)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    KF_CANFD_ASSERT(CHECK_CANFD_SAMPLE_TIME(SampleTime));

    REG_WRITE(Module->CTL1.bits.SMP, (uint32_t)SampleTime);
}

/**
 * @brief Get sample time
 *
 * @param Module Pointer to Canfd
 * @return uint32_t
 */
KF_INLINE uint32_t Canfd_LL_GetSampleTime(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    return REG_READ(Module->CTL1.bits.SMP);
}

/**
 * @brief Set Propagation Segment
 *
 * @param Module Pointer to Canfd
 * @param Value Propagation segment time, 0 ~ 7
 * @return void
 */
KF_INLINE void Canfd_LL_SetPropSeg(Canfd_RegisterMap_t *Module, uint32_t Value)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    KF_CANFD_ASSERT(Value <= 7U);

    REG_WRITE(Module->CTL1.bits.PROPSEG, Value);
}

/**
 * @brief Get Propagation Segment
 *
 * @param Module Pointer to Canfd
 * @return uint32_t
 */
KF_INLINE uint32_t Canfd_LL_GetPropSeg(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    return (REG_READ(Module->CTL1.bits.PROPSEG));
}

/**
 * @brief Set Phase Segment 1
 *
 * @param Module Pointer to Canfd
 * @param Value Phase Segment 1 time, 0 ~ 7
 * @return void
 */
KF_INLINE void Canfd_LL_SetPhaseSeg1(Canfd_RegisterMap_t *Module, uint32_t Value)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    KF_CANFD_ASSERT(Value <= 7U);

    REG_WRITE(Module->CTL1.bits.PSEG1, Value);
}

/**
 * @brief Get Phase Segment 1
 *
 * @param Module Pointer to Canfd
 * @return uint32_t
 */
KF_INLINE uint32_t Canfd_LL_GetPhaseSeg1(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    return (REG_READ(Module->CTL1.bits.PSEG1));
}

/**
 * @brief Set Phase Segment 2
 *
 * @param Module Pointer to Canfd
 * @param Value Phase Segment 2 time, 0 ~ 7
 * @return void
 */
KF_INLINE void Canfd_LL_SetPhaseSeg2(Canfd_RegisterMap_t *Module, uint32_t Value)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    KF_CANFD_ASSERT(Value <= 7U);

    REG_WRITE(Module->CTL1.bits.PSEG2, Value);
}

/**
 * @brief Get Phase Segment 2
 *
 * @param Module Pointer to Canfd
 * @return uint32_t
 */
KF_INLINE uint32_t Canfd_LL_GetPhaseSeg2(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    return (REG_READ(Module->CTL1.bits.PSEG2));
}

/**
 * @brief Set Prescaler Division Factor
 *
 * @param Module Pointer to Canfd
 * @param Value Prescaler Division Factor, 0 ~ 255
 * @return void
 */
KF_INLINE void Canfd_LL_SetPrescalerDivision(Canfd_RegisterMap_t *Module, uint32_t Value)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    KF_CANFD_ASSERT(Value <= 0xFFU);

    REG_WRITE(Module->CTL1.bits.PRESDIV, Value);
}

/**
 * @brief Get Prescaler Division Factor
 *
 * @param Module Pointer to Canfd
 * @return uint32_t
 */
KF_INLINE uint32_t Canfd_LL_GetPrescalerDivision(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    return (REG_READ(Module->CTL1.bits.PRESDIV));
}

/**
 * @brief Set Resync Jump Width
 *
 * @param Module Pointer to Canfd
 * @param Value Resync Jump Width, 0 ~ 3
 * @return void
 */
KF_INLINE void Canfd_LL_SetResyncJumpWidth(Canfd_RegisterMap_t *Module, uint32_t Value)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    KF_CANFD_ASSERT(Value <= 3U);

    REG_WRITE(Module->CTL1.bits.RJW, Value);
}

/**
 * @brief Get Resync Jump Width
 *
 * @param Module Pointer to Canfd
 * @return uint32_t
 */
KF_INLINE uint32_t Canfd_LL_GetResyncJumpWidth(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    return (REG_READ(Module->CTL1.bits.RJW));
}

/**
 * @brief Unlock the mailbox by reading the free running timer
 *
 * @param Module Pointer to Canfd
 * @return void
 */
KF_INLINE void Canfd_LL_UnlockRxMailbox(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    /* Unlock the mailbox by reading the free running timer */
    (void)Module->TIMER.reg;
}

/**
 * @brief Read free running timer
 *
 * @param Module Pointer to Canfd
 * @return uint32_t
 */
KF_INLINE uint32_t Canfd_LL_ReadTimer(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    return REG_READ(Module->TIMER.bits.TIMER);
}

/**
 * @brief Write free running timer
 *
 * @param Module Pointer to Canfd
 * @param Value Timer count, 0 ~ 0xFFFF
 * @return void
 */
KF_INLINE void Canfd_LL_WriteTimer(Canfd_RegisterMap_t *Module, uint32_t Value)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    KF_CANFD_ASSERT(Value <= 0xFFFFU);

    REG_WRITE(Module->TIMER.bits.TIMER, Value);
}

/**
 * @brief Set Rx Mailbox Global Mask
 *
 * @param Module Pointer to Canfd
 * @param Mask Global mask
 * @return void
 */
KF_INLINE void Canfd_LL_SetRxMailboxGlobalMask(Canfd_RegisterMap_t *Module, uint32_t Mask)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->RXMGMASK.reg, Mask);
}

/**
 * @brief Set Rx Mailbox Global Standard Mask
 *
 * @param Module Pointer to Canfd
 * @param StdMask Standard mask
 * @return void
 */
KF_INLINE void Canfd_LL_SetRxMailboxGlobalStandardMask(Canfd_RegisterMap_t *Module, uint32_t StdMask)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->RXMGMASK.reg, 0U);
    REG_WRITE(Module->RXMGMASK.SFF.MASK, StdMask);
}

/**
 * @brief Set Rx Mailbox Global Extended Mask
 *
 * @param Module Pointer to Canfd
 * @param ExtMask Extended mask
 * @return void
 */
KF_INLINE void Canfd_LL_SetRxMailboxGlobalExtendedMask(Canfd_RegisterMap_t *Module, uint32_t ExtMask)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->RXMGMASK.reg, 0U);
    REG_WRITE(Module->RXMGMASK.EFF.MASK, ExtMask);
}

/**
 * @brief Get Tx Error Counter
 *
 * @param Module Pointer to Canfd
 * @return uint32_t
 */
KF_INLINE uint32_t Canfd_LL_GetTxErrorCounter(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    return (REG_READ(Module->ECR.bits.TXERRCNT));
}

/**
 * @brief Set Tx Error Counter
 *
 * @param Module Pointer to Canfd
 * @param Value 0 ~ 0xFF
 * @return void
 */
KF_INLINE void Canfd_LL_SetTxErrorCounter(Canfd_RegisterMap_t *Module, uint8_t Value)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->ECR.bits.TXERRCNT, (uint32_t)Value);
}

/**
 * @brief Get Rx Error Counter
 *
 * @param Module Pointer to Canfd
 * @return uint32_t
 */
KF_INLINE uint32_t Canfd_LL_GetRxErrorCounter(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    return (REG_READ(Module->ECR.bits.RXERRCNT));
}

/**
 * @brief Set Rx Error Counter
 *
 * @param Module Pointer to Canfd
 * @param Value 0 ~ 0xFF
 * @return void
 */
KF_INLINE void Canfd_LL_SetRxErrorCounter(Canfd_RegisterMap_t *Module, uint8_t Value)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->ECR.bits.RXERRCNT, (uint32_t)Value);
}

/**
 * @brief Get Fd Tx Error Counter
 *
 * @param Module Pointer to Canfd
 * @return uint32_t
 */
KF_INLINE uint32_t Canfd_LL_GetFdTxErrorCounter(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    return (REG_READ(Module->ECR.bits.TXERRCNT_FD));
}

/**
 * @brief Set Fd Tx Error Counter
 *
 * @param Module Pointer to Canfd
 * @param Value 0 ~ 0xFF
 * @return void
 */
KF_INLINE void Canfd_LL_SetFdTxErrorCounter(Canfd_RegisterMap_t *Module, uint8_t Value)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->ECR.bits.TXERRCNT_FD, (uint32_t)Value);
}

/**
 * @brief Get Fd Rx Error Counter
 *
 * @param Module Pointer to Canfd
 * @return uint32_t
 */
KF_INLINE uint32_t Canfd_LL_GetFdRxErrorCounter(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    return (REG_READ(Module->ECR.bits.RXERRCNT_FD));
}

/**
 * @brief Set Fd Rx Error Counter
 *
 * @param Module Pointer to Canfd
 * @param Value 0 ~ 0xFF
 * @return void
 */
KF_INLINE void Canfd_LL_SetFdRxErrorCounter(Canfd_RegisterMap_t *Module, uint8_t Value)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->ECR.bits.RXERRCNT_FD, (uint32_t)Value);
}

/**
 * @brief Get Error State
 *
 * @param Module Pointer to Canfd
 * @return uint32_t
 */
KF_INLINE uint32_t Canfd_LL_GetErrorState(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    return REG_READ(Module->ESR1.reg);
}

/**
 * @brief Clear Error Sate
 * @attention Write 1 to clear flag ,write 0 has no effect
 *
 * @param Module Pointer to Canfd
 * @param Mask Mask for clear state
 * @return void
 */
KF_INLINE void Canfd_LL_ClearErrorState(Canfd_RegisterMap_t *Module, uint32_t Mask)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->ESR1.reg, Mask);
}

/**
 * @brief Get wake up flag
 *
 * @param Module Pointer to Canfd
 * @return bool
 * @retval true wake up flag is set
 * @retval false wake up flag is clear
 */
KF_INLINE bool Canfd_LL_GetWakeUpFlag(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    return (REG_READ(Module->ESR1.bits.WAKINT) != 0U) ? true : false;
}

/**
 * @brief Clear wake up flag
 *
 * @param Module Pointer to Canfd
 * @return void
 */
KF_INLINE void Canfd_LL_ClearWakeUpFlag(Canfd_RegisterMap_t *Module)
{
    /* Write 1 to clear flag ,write 0 has no effect */
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->ESR1.reg, 1U);
}

/**
 * @brief Set interrupt mask register 1
 *
 * @param Module Pointer to Canfd
 * @param Mask Mask
 * @return void
 */
KF_INLINE void Canfd_LL_SetIntr1Mask(Canfd_RegisterMap_t *Module, uint32_t Mask)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->IMASK1.reg, Mask);
}

/**
 * @brief Get interrupt mask register 1
 *
 * @param Module Pointer to Canfd
 * @return uint32_t
 */
KF_INLINE uint32_t Canfd_LL_GetIntr1Mask(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    return (REG_READ(Module->IMASK1.reg));
}

/**
 * @brief Clear interrupt flag register 1
 * @attention Write 1 to clear flag ,write 0 has no effect
 *
 * @param Module Pointer to Canfd
 * @param Flag Flag mask to be cleared
 * @return void
 */
KF_INLINE void Canfd_LL_ClearIntr1Flag(Canfd_RegisterMap_t *Module, uint32_t Flag)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->IFLAG1.reg, Flag);
}

/**
 * @brief Get interrupt flag register 1
 *
 * @param Module Pointer to Canfd
 * @return uint32_t
 */
KF_INLINE uint32_t Canfd_LL_GetIntr1Flag(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    return (REG_READ(Module->IFLAG1.reg));
}

/**
 * @brief Set interrupt mask register 2
 *
 * @param Module Pointer to Canfd
 * @param Mask Mask
 * @return void
 */
KF_INLINE void Canfd_LL_SetIntr2Mask(Canfd_RegisterMap_t *Module, uint32_t Mask)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->IMASK2.reg, Mask);
}

/**
 * @brief Get interrupt mask register 2
 *
 * @param Module Pointer to Canfd
 * @return uint32_t
 */
KF_INLINE uint32_t Canfd_LL_GetIntr2Mask(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    return (REG_READ(Module->IMASK2.reg));
}

/**
 * @brief Clear interrupt flag register 2
 * @attention Write 1 to clear flag ,write 0 has no effect
 *
 * @param Module Pointer to Canfd
 * @param Flag Flag mask to be cleared
 * @return void
 */
KF_INLINE void Canfd_LL_ClearIntr2Flag(Canfd_RegisterMap_t *Module, uint32_t Flag)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->IFLAG2.reg, Flag);
}

/**
 * @brief Get interrupt flag register 2
 *
 * @param Module Pointer to Canfd
 * @return uint32_t
 */
KF_INLINE uint32_t Canfd_LL_GetIntr2Flag(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    return (REG_READ(Module->IFLAG2.reg));
}

/**
 * @brief Clear interrupt flag of mailbox
 *
 * @param Module Pointer to Canfd
 * @param MailboxIndex Index of mailbox
 * @return void
 */
KF_INLINE void Canfd_LL_ClearMailboxIntrFlag(Canfd_RegisterMap_t *Module, Canfd_MB_t MailboxIndex)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    KF_CANFD_ASSERT(CHECK_CANFD_MAILBOX_INDEX(MailboxIndex));

    uint32_t flag = (1UL << ((uint32_t)MailboxIndex % 32U));
    /* Clear the corresponding message buffer interrupt flag*/
    if ((uint32_t)MailboxIndex < 32U)
    {
        REG_WRITE(Module->IFLAG1.reg, flag);
    }
    else if ((uint32_t)MailboxIndex < 64U)
    {
        REG_WRITE(Module->IFLAG2.reg, flag);
    }
    else
    { /*Empty*/
    }
}

/**
 * @brief Set interrupt mask of mailbox
 *
 * @param Module Pointer to Canfd Module
 * @param MailboxIndex Index of mailbox
 * @param Status true: enable interrupt, false: disable interrupt
 * @return kf_status_t
 * @retval STATUS_OK Success
 * @retval STATUS_ERROR Invalid mailbox index
 */
KF_INLINE void Canfd_LL_SetMailboxIntrMask(Canfd_RegisterMap_t *Module, Canfd_MB_t MailboxIndex, bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    KF_CANFD_ASSERT(CHECK_CANFD_MAILBOX_INDEX(MailboxIndex));

    uint32_t intrMask = 0U;

    intrMask = 1UL << ((uint32_t)MailboxIndex % 32U);
    /* Enable the corresponding message buffer Interrupt */
    if ((uint32_t)MailboxIndex < 32U)
    {
        if (Status)
        {
            REG_BIT_SET(Module->IMASK1.reg, intrMask);
        }
        else
        {
            REG_BIT_CLR(Module->IMASK1.reg, intrMask);
        }
    }
    else if ((uint32_t)MailboxIndex < 64U)
    {
        if (Status)
        {
            REG_BIT_SET(Module->IMASK2.reg, intrMask);
        }
        else
        {
            REG_BIT_CLR(Module->IMASK2.reg, intrMask);
        }
    }
    else
    { /*Empty*/
    }
}

/**
 * @brief Get interrupt flag of mailbox
 *
 * @param Module Pointer to Canfd
 * @param MailboxIndex Index of mailbox
 * @return bool
 * @retval true interrupt flag is set
 * @retval false interrupt flag is clear
 */
KF_INLINE bool Canfd_LL_GetMailboxIntrFlag(const Canfd_RegisterMap_t *Module, Canfd_MB_t MailboxIndex)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    KF_CANFD_ASSERT(CHECK_CANFD_MAILBOX_INDEX(MailboxIndex));

    uint32_t flag = (1UL << ((uint32_t)MailboxIndex % 32U));
    bool     ret  = false;

    /* Clear the corresponding message buffer interrupt flag*/
    if ((uint32_t)MailboxIndex < 32U)
    {
        ret = ((REG_READ(Module->IFLAG1.reg) & flag) != 0U) ? true : false;
    }
    else if ((uint32_t)MailboxIndex < 64U)
    {
        ret = ((REG_READ(Module->IFLAG2.reg) & flag) != 0U) ? true : false;
    }
    else
    { /*Empty*/
    }

    return ret;
}

/**
 * @brief Get mailbox interrupt state
 *
 * @param Module Pointer to Canfd
 * @param MailboxIndex Index of mailbox
 * @return bool
 * @retval true: Interrupt is enabled, and flag is set
 * @retval false: Interrupt is disabled, or flag is not set
 */
KF_INLINE bool Canfd_LL_GetMailboxIntrState(const Canfd_RegisterMap_t *Module, Canfd_MB_t MailboxIndex)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    KF_CANFD_ASSERT(CHECK_CANFD_MAILBOX_INDEX(MailboxIndex));

    uint32_t flag          = (1UL << ((uint32_t)MailboxIndex % 32U));
    uint32_t intrStateMask = 0U;
    bool     ret           = false;

    /* Clear the corresponding message buffer interrupt flag*/
    if ((uint32_t)MailboxIndex < 32U)
    {
        /* PRQA S 0404 1 #KQR000404 */
        intrStateMask = Module->IMASK1.reg & Module->IFLAG1.reg;
        ret           = ((intrStateMask & flag) != 0U) ? true : false;
    }
    else if ((uint32_t)MailboxIndex < 64U)
    {
        /* PRQA S 0404 1 #KQR000404 */
        intrStateMask = Module->IMASK2.reg & Module->IFLAG2.reg;
        ret           = ((intrStateMask & flag) != 0U) ? true : false;
    }
    else
    { /*Empty*/
    }

    return ret;
}

/**
 * @brief Set Fd Error Interrupt Enabled
 *
 * @param Module Pointer to Canfd
 * @param Status true: enable false: disable
 * @return void
 */
KF_INLINE void Canfd_LL_SetFdErrorIntrEnabled(Canfd_RegisterMap_t *Module, bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->CTL2.bits.ERRMSK_FD, Status ? 1U : 0U);
}

/**
 * @brief Get Fd Error Interrupt Enabled
 *
 * @param Module Pointer to Canfd
 * @param Status true: enable false: disable
 * @return bool
 */
KF_INLINE bool Canfd_LL_GetFdErrorIntrEnabledState(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    return (Module->CTL2.bits.ERRMSK_FD != 0U);
}

/**
 * @brief Set Write Access To Memory In Halt Mode
 *
 * @param Module Pointer to Canfd
 * @param Status true: enable, false: disable
 * @return void
 */
KF_INLINE void Canfd_LL_SetWriteAccessToMemoryInHalt(Canfd_RegisterMap_t *Module, bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->CTL2.bits.WRMFRZ, Status ? 1U : 0U);
}

/**
 * @brief Set ISOCANFD mode
 *
 * @param Module Pointer to Canfd
 * @param Status true: ISO CANFD ,false: non-ISO CANFD
 * @return void
 */
KF_INLINE void Canfd_LL_SetIsoMode(Canfd_RegisterMap_t *Module, bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->CTL2.bits.ISOCANFDEN, Status ? 1U : 0U);
}

/**
 * @brief Set Remote Frame Filter Enabled
 *
 * @param Module Pointer to Canfd
 * @param Status true: enable, false: disable
 * @return void
 */
KF_INLINE void Canfd_LL_SetRemoteFrameFilterEnabled(Canfd_RegisterMap_t *Module, bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->CTL2.bits.EACEN, Status ? 1U : 0U);
}

/**
 * @brief Set Enhanced Bit time segments Enabled
 *
 * @param Module Pointer to Canfd
 * @param Status true: enable, false: disable
 * @return KF_INLINE
 */
KF_INLINE void Canfd_LL_SetEnhancedBitTimeEnabled(Canfd_RegisterMap_t *Module, bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->CTL2.bits.BTE, Status ? 1U : 0U);
}

/**
 * @brief Get enhanced bit time enabled state
 *
 * @param Module Pointer to Canfd
 * @return bool
 */
KF_INLINE bool Canfd_LL_GetEnhancedBitTimeEnabledState(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    return (REG_READ(Module->CTL2.bits.BTE) == 1U);
}

/**
 * @brief Set Protocol Exception Enabled
 *
 * @param Module Pointer to Canfd
 * @param Status true: enable, false: disable
 * @return void
 */
KF_INLINE void Canfd_LL_SetProtocolExceptionEnabled(Canfd_RegisterMap_t *Module, bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->CTL2.bits.PREXCEN, Status ? 1U : 0U);
}

/**
 * @brief Set Remote Request Store Enabled
 *
 * @param Module Pointer to Canfd
 * @param Status true: Remote Request Frame is stored, false: Remote Response Frame is generated
 * @return void
 */
KF_INLINE void Canfd_LL_SetRemoteRequestStoreEnabled(Canfd_RegisterMap_t *Module, bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->CTL2.bits.RRS, Status ? 1U : 0U);
}

/**
 * @brief Set Edge Filter Enabled
 *
 * @param Module Pointer to Canfd
 * @param Status true: enable, false: disable
 * @return void
 */
KF_INLINE void Canfd_LL_SetEdgeFilterEnabled(Canfd_RegisterMap_t *Module, bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->CTL2.bits.EDFLTDIS, Status ? 0U : 1U);
}

/**
 * @brief Set filter number of normal Rx FIFO
 *
 * @param Module Pointer to Canfd
 * @param FilterNumber Number of filter
 * @return void
 */
KF_INLINE void Canfd_LL_SetNormalFifoFilterNum(Canfd_RegisterMap_t *Module, Canfd_NormalRxFifoFilterNum_t FilterNumber)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    KF_CANFD_ASSERT(CHECK_CANFD_NORMAL_RX_FIFO_FILTER_NUM(FilterNumber));

    REG_WRITE(Module->CTL2.bits.NRFFN, (uint32_t)FilterNumber);
}

/**
 * @brief Get filter number of normal Rx
 *
 * @param Module Pointer to Canfd
 * @return Canfd_NormalRxFifoFilterNum_t
 */
KF_INLINE Canfd_NormalRxFifoFilterNum_t Canfd_LL_GetNormalFifoFilterNumber(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    /* PRQA S 4342 1 #KQR004342 */
    return ((Canfd_NormalRxFifoFilterNum_t)REG_READ(Module->CTL2.bits.NRFFN));
}

/**
 * @brief Set Error Correct Configuration register write Enable
 *
 * @param Module Pointer to Canfd
 * @param Status true: enable, false: disable
 * @return void
 */
KF_INLINE void Canfd_LL_SetErrorCorrectConfigurationEnable(Canfd_RegisterMap_t *Module, bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    if (Status)
    {
        REG_WRITE(Module->CTL2.bits.ECRWRE, 1U);
        REG_WRITE(Module->MECR.bits.ECRWRDIS, 0U);
    }
    else
    {
        REG_WRITE(Module->MECR.bits.ECRWRDIS, 1U);
        REG_WRITE(Module->CTL2.bits.ECRWRE, 0U);
    }
}

/**
 * @brief Set Normal Rx FIFO Global Mask
 *
 * @param Module Pointer to Canfd
 * @param Mask Mask
 * @return void
 */
KF_INLINE void Canfd_LL_SetNormalRxFifoFilterGlobalMask(Canfd_RegisterMap_t *Module, uint32_t Mask)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->NRFGM, Mask);
}

/**
 * @brief Get Normal Rx FIFO Global Mask
 *
 * @param Module Pointer to Canfd
 * @return uint32_t
 */
KF_INLINE uint32_t Canfd_LL_GetNormalRxFifoFilterGlobalMask(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    return (REG_READ(Module->NRFGM));
}

/**
 * @brief Set Extended Propagation Segment
 *
 * @param Module Pointer to Canfd
 * @param Value Propagation Segment, 0 ~ 0x3F
 * @return void
 */
KF_INLINE void Canfd_LL_SetExtendedPropSeg(Canfd_RegisterMap_t *Module, uint32_t Value)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    KF_CANFD_ASSERT(Value <= 0x3FU);

    REG_WRITE(Module->CBT.bits.EPROPSEG, Value);
}

/**
 * @brief Set Extend Bit Time Enabled
 *
 * @param Module Pointer to Canfd
 * @param Status true: enable, false: disable
 * @return void
 */
KF_INLINE void Canfd_LL_SetExtendedBitTimeEnabled(Canfd_RegisterMap_t *Module, bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->CBT.bits.BTF, Status ? 1U : 0U);
}

/**
 * @brief Set Extended Phase Segment 1
 *
 * @param Module Pointer to Canfd
 * @param Value Phase Segment 1, 0 ~ 0x1F
 * @return void
 */
KF_INLINE void Canfd_LL_SetExtendedPhaseSeg1(Canfd_RegisterMap_t *Module, uint32_t Value)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    KF_CANFD_ASSERT(Value <= 0x1FU);

    REG_WRITE(Module->CBT.bits.EPSEG1, Value);
}

/**
 * @brief Set Extended Phase Segment 2
 *
 * @param Module Pointer to Canfd
 * @param Value Phase Segment 2, 0 ~ 0x1F
 * @return void
 */
KF_INLINE void Canfd_LL_SetExtendedPhaseSeg2(Canfd_RegisterMap_t *Module, uint32_t Value)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    KF_CANFD_ASSERT(Value <= 0x1FU);

    REG_WRITE(Module->CBT.bits.EPSEG2, Value);
}

/**
 * @brief Set Extended Prescaler Division
 *
 * @param Module Pointer to Canfd
 * @param Value Prescaler Division Factor, 0 ~ 0x3FF
 * @return void
 */
KF_INLINE void Canfd_LL_SetExtendedPrescalerDivision(Canfd_RegisterMap_t *Module, uint32_t Value)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    KF_CANFD_ASSERT(Value <= 0x3FFU);

    REG_WRITE(Module->CBT.bits.EPRESDIV, Value);
}

/**
 * @brief Set Extended Resync Jump Width
 *
 * @param Module Pointer to Canfd
 * @param Value Resync Jump Width, 0 ~ 0x1F
 * @return void
 */
KF_INLINE void Canfd_LL_SetExtendedResyncJumpWidth(Canfd_RegisterMap_t *Module, uint32_t Value)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    KF_CANFD_ASSERT(Value <= 0x1FU);

    REG_WRITE(Module->CBT.bits.ERJW, Value);
}

/**
 * @brief Set Rx Mailbox Individual Mask
 *
 * @param Module Pointer to Canfd
 * @param MBIndex Index of mailbox
 * @param Mask Mask
 * @return void
 */
KF_INLINE void Canfd_LL_SetRxMailboxIndividualMask(Canfd_RegisterMap_t *Module, Canfd_MB_t MBIndex, uint32_t Mask)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    KF_CANFD_ASSERT(CHECK_CANFD_MAILBOX_INDEX(MBIndex));

    REG_WRITE(Module->RXIMR[MBIndex].reg, Mask);
}

/**
 * @brief Set Rx Mailbox Individual Standard Mask
 *
 * @param Module Pointer to Canfd
 * @param MBIndex Index of mailbox
 * @param StdMask Standard Mask
 * @return void
 */
KF_INLINE void
Canfd_LL_SetRxMailboxIndividualStandardMask(Canfd_RegisterMap_t *Module, Canfd_MB_t MBIndex, uint32_t StdMask)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    KF_CANFD_ASSERT(CHECK_CANFD_MAILBOX_INDEX(MBIndex));

    uint32_t mask = ((StdMask & 0x7FFU) << 18U) | (3UL << 30U);

    REG_WRITE(Module->RXIMR[MBIndex].reg, mask);
}

/**
 * @brief Set Rx Mailbox Individual Extended Mask
 *
 * @param Module Pointer to Canfd
 * @param MBIndex Index of mailbox
 * @param ExtMask Standard Mask
 * @return void
 */
KF_INLINE void
Canfd_LL_SetRxMailboxIndividualExtendedMask(Canfd_RegisterMap_t *Module, Canfd_MB_t MBIndex, uint32_t ExtMask)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    KF_CANFD_ASSERT(CHECK_CANFD_MAILBOX_INDEX(MBIndex));

    uint32_t mask = (ExtMask & 0x1FFFFFFFU) | (3UL << 30U);

    REG_WRITE(Module->RXIMR[MBIndex].reg, mask);
}

/**
 * @brief Set Error Correct Enable
 *
 * @attention NOT SAME to KF32A13X user manual.
 *
 * @param Module Pointer to Canfd
 * @param Status true: enable error correct, false: disable error correct
 * @return void
 */
KF_INLINE void Canfd_LL_SetErrorCorrectEnable(Canfd_RegisterMap_t *Module, bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->MECR.bits.ECCDIS, Status ? 0U : 1U);
}

/**
 * @brief Set error report enable
 *
 * @attention NOT SAME to KF32A13X user manual.
 *
 * @param Module Pointer to Canfd
 * @param Status true: enable error report, false: disable error report
 * @return void
 */
KF_INLINE void Canfd_LL_SetErrorReportEnable(Canfd_RegisterMap_t *Module, bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->MECR.bits.RERRDIS, Status ? 0U : 1U);
}

/**
 * @brief Enter Halt If Error can't be Corrected
 *
 * @param Module Pointer to Canfd
 * @param Status true: enter halt, false: keep normal mode
 * @return void
 */
KF_INLINE void Canfd_LL_EnterHaltIfErrorNonCorrect(Canfd_RegisterMap_t *Module, bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->MECR.bits.NCEFAFRZ, Status ? 1U : 0U);
}

/**
 * @brief Set Error correct interrupt enabled state
 *
 * @param Module Pointer to Canfd
 * @param Mask Mask, values can be:
 * CANFD_MECR_HANCEI_MSK_MASK
 * CANFD_MECR_FANCEI_MSK_MASK
 * CANFD_MECR_CEI_MSK_MASK
 * CANFD_MECR_CEI_ALL_MASK
 * @param Status true: enable, false: disable
 * @return void
 */
KF_INLINE void Canfd_LL_SetErrorCorrectIntrEnabled(Canfd_RegisterMap_t *Module, uint32_t Mask, bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    if (Status)
    {
        REG_BIT_SET(Module->MECR.reg, (Mask & CANFD_MECR_CEI_ALL_MASK));
    }
    else
    {
        REG_BIT_CLR(Module->MECR.reg, (Mask & CANFD_MECR_CEI_ALL_MASK));
    }
}

/**
 * @brief Set Payload Size
 *
 * @param Module Pointer to Canfd
 * @param Region Region index
 * @param Payload Payload Size
 * @return void
 */
KF_INLINE void Canfd_LL_SetPayloadSize(Canfd_RegisterMap_t *Module, Canfd_Region_t Region, Canfd_PayloadSize_t Payload)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    KF_CANFD_ASSERT(CHECK_CANFD_REGION_INDEX(Region));
    KF_CANFD_ASSERT(CHECK_CANFD_PAYLOAD_SIZE(Payload));

    uint32_t pos = 16U + ((uint32_t)Region * 3U);
    REG_BITS_WRITE(Module->FDCTL.reg, (0x3UL << pos), ((uint32_t)Payload << pos));
}

/**
 * @brief Get payload size of region
 *
 * @param Module Pointer to Canfd
 * @param Region Region index
 * @return Canfd_PayloadSize_t
 */
KF_INLINE Canfd_PayloadSize_t Canfd_LL_GetPayloadSize(const Canfd_RegisterMap_t *Module, Canfd_Region_t Region)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    KF_CANFD_ASSERT(CHECK_CANFD_REGION_INDEX(Region));

    uint32_t pos    = 16U + ((uint32_t)Region * 3U);
    uint32_t retVal = REG_BITS_READ(Module->FDCTL.reg, ((uint32_t)0x3U << pos), pos);

    /* PRQA S 4342 1 #KQR004342 */
    return (Canfd_PayloadSize_t)retVal;
}

/**
 * @brief Set FD Rate Switch
 *
 * @param Module Pointer to Canfd
 * @param Status true: enable, false: disable
 * @return void
 */
KF_INLINE void Canfd_LL_SetFdRateSwitch(Canfd_RegisterMap_t *Module, bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->FDCTL.bits.FDRATE, Status ? 1U : 0U);
}

/**
 * @brief Get TDC Value
 *
 * @param Module Pointer to Canfd
 * @return uint32_t: 0 ~ 0x3F
 */
KF_INLINE uint32_t Canfd_LL_GetTdcValue(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    return (REG_READ(Module->FDCTL.bits.TDCVAL));
}

/**
 * @brief Get TDC Fail State
 *
 * @param Module Pointer to Canfd
 * @return bool
 * @retval true: TDC not in range
 * @retval false: TDC in range
 */
KF_INLINE bool Canfd_LL_GetTdcFailState(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    return (REG_READ(Module->FDCTL.bits.TDCFAIL) == 1U);
}

/**
 * @brief Clear TDC Fail State
 *
 * @param Module Pointer to Canfd
 * @return void
 */
KF_INLINE void Canfd_LL_ClearTdcFailState(Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->FDCTL.bits.TDCFAIL, 1U);
}

/**
 * @brief Set TDC Status
 *
 * @param Module Pointer to Canfd
 * @param Status true: enable, false: disable
 * @return void
 */
KF_INLINE void Canfd_LL_SetTdcEnabled(Canfd_RegisterMap_t *Module, bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->FDCTL.bits.TDCEN, Status ? 1U : 0U);
}

/**
 * @brief Set TDC Offset Value
 *
 * @param Module Pointer to Canfd
 * @param Offset TDC offset, 0 ~ 0x1F
 * @return void
 */
KF_INLINE void Canfd_LL_SetTdcOffsetValue(Canfd_RegisterMap_t *Module, uint32_t Offset)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    KF_CANFD_ASSERT(Offset <= 0x1FU);

    REG_WRITE(Module->FDCTL.bits.TDCOFF, Offset);
}

/**
 * @brief Set FD Propagation Segment
 *
 * @param Module Pointer to Canfd
 * @param Value FD Propagation Segment, 0 ~ 0x1F
 * @return void
 */
KF_INLINE void Canfd_LL_SetFdPropSeg(Canfd_RegisterMap_t *Module, uint32_t Value)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    KF_CANFD_ASSERT(Value <= 0x1FU);

    REG_WRITE(Module->FDCBT.bits.FPROPSEG, Value);
}

/**
 * @brief Get FD Propagation Segment
 *
 * @param Module Pointer to Canfd
 * @return uint32_t
 */
KF_INLINE uint32_t Canfd_LL_GetFdPropSeg(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    return (REG_READ(Module->FDCBT.bits.FPROPSEG));
}

/**
 * @brief Set FD Phase Segment 1
 *
 * @param Module Pointer to Canfd
 * @param Value FD Phase Segment 1, 0 ~ 0x7
 * @return void
 */
KF_INLINE void Canfd_LL_SetFdPhaseSeg1(Canfd_RegisterMap_t *Module, uint32_t Value)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    KF_CANFD_ASSERT(Value <= 0x7U);

    REG_WRITE(Module->FDCBT.bits.FPSEG1, Value);
}

/**
 * @brief Get FD Phase Segment 1
 *
 * @param Module Pointer to Canfd
 * @return uint32_t
 */
KF_INLINE uint32_t Canfd_LL_GetFdPhaseSeg1(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    return (REG_READ(Module->FDCBT.bits.FPSEG1));
}

/**
 * @brief Set FD Phase Segment 2
 *
 * @param Module Pointer to Canfd
 * @param Value FD Phase Segment 2, 0 ~ 0x7
 * @return void
 */
KF_INLINE void Canfd_LL_SetFdPhaseSeg2(Canfd_RegisterMap_t *Module, uint32_t Value)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    KF_CANFD_ASSERT(Value <= 0x7U);

    REG_WRITE(Module->FDCBT.bits.FPSEG2, Value);
}

/**
 * @brief Get FD Phase Segment 2
 *
 * @param Module Pointer to Canfd
 * @return uint32_t
 */
KF_INLINE uint32_t Canfd_LL_GetFdPhaseSeg2(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    return (REG_READ(Module->FDCBT.bits.FPSEG2));
}

/**
 * @brief Set FD Prescaler Division
 *
 * @param Module Pointer to Canfd
 * @param Value FD Prescaler Division, 0 ~ 0x3FF
 * @return void
 */
KF_INLINE void Canfd_LL_SetFdPrescalerDivision(Canfd_RegisterMap_t *Module, uint32_t Value)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    KF_CANFD_ASSERT(Value <= 0x3FFU);

    REG_WRITE(Module->FDCBT.bits.FPRESDIV, Value);
}

/**
 * @brief Get FD Prescaler Division
 *
 * @param Module Pointer to Canfd
 * @return uint32_t
 */
KF_INLINE uint32_t Canfd_LL_GetFdPrescalerDivision(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    return (REG_READ(Module->FDCBT.bits.FPRESDIV));
}

/**
 * @brief Set FD Resync Jump Width
 *
 * @param Module Pointer to Canfd
 * @param Value FD Resync Jump Width, 0 ~ 0x7
 * @return void
 */
KF_INLINE void Canfd_LL_SetFdResyncJumpWidth(Canfd_RegisterMap_t *Module, uint32_t Value)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    KF_CANFD_ASSERT(Value <= 0x7U);

    REG_WRITE(Module->FDCBT.bits.FRJW, Value);
}

/**
 * @brief Get FD Resync Jump Width
 *
 * @param Module Pointer to Canfd
 * @return uint32_t
 */
KF_INLINE uint32_t Canfd_LL_GetFdResyncJumpWidth(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    return (REG_READ(Module->FDCBT.bits.FRJW));
}

/**
 * @brief Set Enhanced Rx Fifo Enabled
 *
 * @param Module Pointer to Canfd
 * @param Status true: enable, false: disable
 * @return void
 */
KF_INLINE void Canfd_LL_SetEnhancedRxFifoEnabled(Canfd_RegisterMap_t *Module, bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    /* only use in halt mode */
    REG_WRITE(Module->ERFCR.bits.ERFEN, Status ? 1U : 0U);
}

/**
 * @brief Get Enhanced Rx Fifo Enabled State
 *
 * @param Module Pointer to Canfd
 * @return bool
 */
KF_INLINE bool Canfd_LL_GetEnhancedRxFifoEnabledState(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    return (REG_READ(Module->ERFCR.bits.ERFEN) == 1U);
}

/**
 * @brief Set Enhanced Rx Fifo Filter Number
 *
 * @param Module Pointer to Canfd
 * @param Number Number of Filter, 0 ~ 0x3F
 * @return void
 */
KF_INLINE void Canfd_LL_SetEnhancedRxFifoFilterNumber(Canfd_RegisterMap_t *Module, uint32_t Number)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    KF_CANFD_ASSERT(Number <= 0x3FU);

    REG_WRITE(Module->ERFCR.bits.NFE, Number);
}

/**
 * @brief Get Enhanced Rx Fifo Filter Number
 *
 * @param Module Pointer to Canfd
 * @return uint8_t
 */
KF_INLINE uint32_t Canfd_LL_GetEnhancedRxFifoFilterNumber(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    return (REG_READ(Module->ERFCR.bits.NFE));
}

/**
 * @brief Set Enhanced Rx Fifo Extended Filter Number
 *
 * @param Module Pointer to Canfd
 * @param Number Number of Filter, 0 ~ 0x7F
 * @return void
 */
KF_INLINE void Canfd_LL_SetEnhancedRxFifoExtendedFilterNumber(Canfd_RegisterMap_t *Module, uint32_t Number)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    KF_CANFD_ASSERT(Number <= 0x7FU);

    REG_WRITE(Module->ERFCR.bits.NEXIF, Number);
}

/**
 * @brief Get Enhanced Rx Fifo Extended Filter Number
 *
 * @param Module Pointer to Canfd
 * @return uint32_t
 */
KF_INLINE uint32_t Canfd_LL_GetEnhancedRxFifoExtendedFilterNumber(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    return (REG_READ(Module->ERFCR.bits.NEXIF));
}

/**
 * @brief Set Enhanced Rx Fifo Water Mark
 *
 * @param Module Pointer to Canfd
 * @param WaterMark Number of Water Mark, 0 ~ 0x1F
 * @return bool
 */
KF_INLINE void Canfd_LL_SetEnhancedRxFifoWaterMark(Canfd_RegisterMap_t *Module, uint32_t WaterMark)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    KF_CANFD_ASSERT(WaterMark <= 0x1FU);

    REG_WRITE(Module->ERFCR.bits.ERFWM, WaterMark);
}

/**
 * @brief Set Enhanced Rx Fifo Interrupt Enabled
 *
 * @param Module Pointer to Canfd
 * @param RxFifoIntrMask Mask of Interrupt, see @ref Canfd_EnhancedRxFifoIntrMask_t
 * @param Status true: enable, false: disable
 * @return void
 */
KF_INLINE void Canfd_LL_SetEnhancedRxFifoIntrEnabled(Canfd_RegisterMap_t *Module, uint32_t RxFifoIntrMask, bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    if (Status)
    {
        REG_BIT_SET(Module->ERFIER.reg, RxFifoIntrMask);
    }
    else
    {
        REG_BIT_CLR(Module->ERFIER.reg, RxFifoIntrMask);
    }
}

/**
 * @brief Clear Enhanced Rx Fifo
 *
 * @param Module Pointer to Canfd
 * @return void
 */
KF_INLINE void Canfd_LL_ClearEnhancedRxFifo(Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    /* only use in halt mode */
    REG_WRITE(Module->ERFSR.reg, 0x8000000U);
}

/**
 * @brief Clear Enhanced Rx Fifo State
 *
 * @param Module Pointer to Canfd
 * @return void
 */
KF_INLINE void Canfd_LL_ClearEnhancedRxFifoState(Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    /** Write 1 to clear */
    /* clear Enhanced RxFiFo underFlow indication */
    /* clear Enhanced RxFiFo overflow indication */
    /* clear Enhanced RxFiFo watermark indication */
    /* clear Enhanced RxFiFo data available indication */
    REG_WRITE(Module->ERFSR.reg,
              (uint32_t)CANFD_ENHANCED_RX_FIFO_UNDERFLOW | (uint32_t)CANFD_ENHANCED_RX_FIFO_OVERFLOW |
                  (uint32_t)CANFD_ENHANCED_RX_FIFO_WATER_MARK | (uint32_t)CANFD_ENHANCED_RX_FIFO_DATA_USEFUL);
}

/**
 * @brief CLear Enhanced Rx Fifo Interrupt Flag
 *
 * @param Module Pointer to Canfd
 * @param Mask Mask of Interrupt, see @ref Canfd_EnhancedRxFifoIntrMask_t
 * @return void
 */
KF_INLINE void Canfd_LL_ClearEnhancedRxFifoIntrFlag(Canfd_RegisterMap_t *Module, uint32_t Mask)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->ERFSR.reg, Mask);
}

/**
 * @brief Get Enhanced Rx Fifo Interrupt Flag
 *
 * @param Module Pointer to Canfd
 * @param Mask Mask of Interrupt, see @ref Canfd_EnhancedRxFifoIntrMask_t
 * @return bool
 * @retval true: interrupt flag is set
 * @retval false: interrupt flag is not set
 */
KF_INLINE bool Canfd_LL_GetEnhancedRxFifoIntrFlag(const Canfd_RegisterMap_t *Module, uint32_t Mask)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    KF_CANFD_ASSERT(CHECK_CANFD_ENHANCED_RX_FIFO_INTR_MASK(Mask));

    return REG_BIT_BOOLED(Module->ERFSR.reg, Mask);
}

/**
 * @brief Get enhanced Rx FIFO interrupt state
 *
 * @param Module Pointer to Canfd
 * @param Mask Mask of enhanced Rx FIFO interrupt, @ref Canfd_EnhancedRxFifoIntrMask_t
 * @return bool
 * @retval true: Interrupt is enabled, and flag is set
 * @retval false: Interrupt is disabled, or flag is not set
 */
KF_INLINE bool Canfd_LL_GetEnhancedRxFifoIntrState(const Canfd_RegisterMap_t *Module, uint32_t Mask)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    KF_CANFD_ASSERT(CHECK_CANFD_ENHANCED_RX_FIFO_INTR_MASK(Mask));

    /* PRQA S 0404 1 #KQR000404 */
    uint32_t intrMask = (Module->ERFSR.reg & Module->ERFIER.reg) & 0xF0000000U;

    return ((intrMask & Mask) != 0U);
}

/**
 * @brief Check Enhanced Rx Fifo Empty or not
 *
 * @param Module Pointer to Canfd
 * @return bool
 */
KF_INLINE bool Canfd_LL_IsEnhancedRxFifoEmpty(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    return (REG_READ(Module->ERFSR.bits.ERFE) != 0U) ? true : false;
}

/**
 * @brief Check Enhanced Rx Fifo Full or not
 *
 * @param Module Pointer to Canfd
 * @return bool
 */
KF_INLINE bool Canfd_LL_IsEnhancedRxFifoFull(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    return (REG_READ(Module->ERFSR.bits.ERFF) != 0U) ? true : false;
}

/**
 * @brief Get Enhanced Rx Fifo Message Number
 *
 * @param Module Pointer to Canfd
 * @return uint32_t, 0 ~ 0x7
 */
KF_INLINE uint32_t Canfd_LL_GetEnhancedRxFifoMessageNumber(const Canfd_RegisterMap_t *Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    return REG_READ(Module->ERFSR.bits.ERFEL);
}

/**
 * @brief Set Enhanced Rx Fifo Filter Element
 *
 * @param Module Pointer to Canfd
 * @param ElementIndex Element Index, 0 ~ 5
 * @param FilterElement Filter Element
 * @return void
 */
KF_INLINE void
Canfd_LL_SetEnhancedRxFifoFilterElement(Canfd_RegisterMap_t *Module, uint32_t ElementIndex, uint32_t FilterElement)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    KF_CANFD_ASSERT(ElementIndex <= 5U);

    Module->ERFFEL[ElementIndex] = FilterElement;
}

/**
 * @brief Set Clock Source of CANFD
 *
 * @param Module Pointer to Canfd
 * @param ClockSource Clock Source, 0 ~ 3
 * @return void
 */
KF_INLINE void Canfd_LL_SetClockSource(Canfd_RegisterMap_t *Module, uint32_t ClockSource)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    KF_CANFD_ASSERT(ClockSource <= 3U);

    Module->CTL3.bits.CLK_SEL = ClockSource;
}

/**
 * @brief Set Clock Division
 *
 * @param Module Pointer to Canfd
 * @param Division Division, 0 ~ 4
 * @return void
 */
KF_INLINE void Canfd_LL_SetClockDivision(Canfd_RegisterMap_t *Module, uint32_t Division)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    KF_CANFD_ASSERT(Division <= 4U);

    Module->CTL3.bits.CLK_DIV = Division;
}

/**
 * @brief Set Read Endian Swap
 *
 * @param Module Pointer to Canfd
 * @param State Swap State
 *        true: swap
 *        false: not swap
 * @return void
 */
KF_INLINE void Canfd_LL_SetReadEndianSwapEnabled(Canfd_RegisterMap_t *Module, bool State)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    Module->CTL3.bits.READ_ENDIAN_SWAP = (true == State) ? 1U : 0U;
}

/**
 * @brief Set Write Endian Swap
 *
 * @param Module Pointer to Canfd
 * @param State Swap State
 *        true: swap
 *        false: not swap
 * @return void
 */
KF_INLINE void Canfd_LL_SetWriteEndianSwapEnabled(Canfd_RegisterMap_t *Module, bool State)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    Module->CTL3.bits.WRITE_ENDIAN_SWAP = (true == State) ? 1U : 0U;
}

/**
 * @brief Set Internal IO Enabled
 *
 * @param Module Pointer to Canfd
 * @param State Enable or disable internal IO
 *         true: enable
 *         false: disable
 * @return void
 */
KF_INLINE void Canfd_LL_SetInternalIOEnabled(Canfd_RegisterMap_t *Module, bool State)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    Module->CTL3.bits.CAN_IO_EN = (true == State) ? 1U : 0U;
}

/**
 * @brief Set Internal Tx Enabled
 *
 * @param Module Pointer to Canfd
 * @param State Enable or disable internal Tx
 *         true: enable
 *         false: disable
 * @return void
 */
KF_INLINE void Canfd_LL_SetInternalTxEnabled(Canfd_RegisterMap_t *Module, bool State)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));

    Module->CTL3.bits.CAN_TX_EN = (true == State) ? 1U : 0U;
}

/**
 * @brief Set Tx arbitration start delay
 *
 * @param Module Pointer to Canfd
 * @param Delay Delay time
 * @return void
 */
KF_INLINE void Canfd_LL_SetTxArbitrationStartDelay(Canfd_RegisterMap_t *Module, uint32_t Delay)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    KF_CANFD_ASSERT(Delay <= 0x1FU);

    Module->CTL2.bits.TASD = Delay;
}

uint32_t Canfd_LL_GetMailboxNumber(uint32_t PayloadSize);
uint32_t Canfd_LL_GetDataLength(uint32_t Dlc);
uint32_t Canfd_LL_ComputeDlcValue(uint32_t dataLength);
void     Canfd_LL_SwapBytesInWord(void *DesPtr, const void *SouPtr);
uint32_t Canfd_LL_GetPayloadMemSize(const Canfd_RegisterMap_t *Module, Canfd_Region_t Region);
uint32_t Canfd_LL_EnterHaltMode(Canfd_RegisterMap_t *Module);
void     Canfd_LL_ExitHaltMode(Canfd_RegisterMap_t *Module, uint32_t State);
void     Canfd_LL_Disable(Canfd_RegisterMap_t *Module);
void     Canfd_LL_Enable(Canfd_RegisterMap_t *Module);
void     Canfd_LL_SetTimeSegments(Canfd_RegisterMap_t *Module, const Canfd_ArbiTimeSegment_t *const TimeSegPtr);
void     Canfd_LL_SetExtendedTimeSegments(Canfd_RegisterMap_t *Module, const Canfd_ArbiTimeSegment_t *const TimeSegPtr);
void     Canfd_LL_SetFdTimeSegments(Canfd_RegisterMap_t *Module, const Canfd_DataTimeSegment_t *const TimeSegPtr);
void     Canfd_LL_GetTimeSegments(const Canfd_RegisterMap_t *Module, Canfd_ArbiTimeSegment_t *TimeSegPtr);
void     Canfd_LL_GetFdTimeSegments(const Canfd_RegisterMap_t *Module, Canfd_DataTimeSegment_t *TimeSegPtr);
uint32_t Canfd_LL_GetFirstIndividualMailbox(const Canfd_RegisterMap_t *Module);
void     Canfd_LL_ClearErrIntrStatusFlag(Canfd_RegisterMap_t *Module);
void     Canfd_LL_SetTdcOffset(Canfd_RegisterMap_t *Module, bool Status, uint32_t Offset);
void     Canfd_LL_SetEnhancedTdcOffset(Canfd_RegisterMap_t *Module, bool Status, uint32_t Offset);
void     Canfd_LL_Init(Canfd_RegisterMap_t *Module);
void     Canfd_LL_SetNormalRxFifoGlobalMask(Canfd_RegisterMap_t *Module, Canfd_IDType_t IDType, uint32_t Mask);
void     Canfd_LL_SetRxIndividualMask(
        Canfd_RegisterMap_t *Module, Canfd_MB_t MailboxIndex, Canfd_IDType_t IDType, uint32_t Mask);
kf_status_t Canfd_LL_ConfigNormalRxFifo(Canfd_RegisterMap_t *Module, const Canfd_NormalRxFifo_t *NormalRxFifoPtr);
void Canfd_LL_SetEnhancedRxFifoFilter(Canfd_RegisterMap_t *Module, const Canfd_EnhancedRxFifoFilter_t *FilterPtr);
kf_status_t Canfd_LL_ConfigEnhancedRxFifo(Canfd_RegisterMap_t *Module, const Canfd_EnhancedRxFifo_t *EnhancedRxFifoPtr);
volatile uint32_t *Canfd_LL_GetMailboxAddress(Canfd_RegisterMap_t *Module, Canfd_MB_t MailboxIndex);
kf_status_t        Canfd_LL_SetMaxMailboxNumber(Canfd_RegisterMap_t *Module, uint32_t MaxMailboxNumber);
void               Canfd_LL_SetOperationMode(Canfd_RegisterMap_t *Module, Canfd_Mode_t Mode);
void               Canfd_LL_SetErrorIntrEnabled(Canfd_RegisterMap_t *Module, Canfd_ErrorIntr_t ErrType, bool Status);
void               Canfd_LL_AbortTxMailbox(Canfd_RegisterMap_t *Module, Canfd_MB_t MailboxIndex);
kf_status_t        Canfd_LL_SetTxMailbox(
           Canfd_RegisterMap_t *Module, Canfd_MB_t MailboxIndex, Canfd_TxCode_t Code, const Canfd_Msg_t *MsgPtr);
kf_status_t Canfd_LL_SetRxMailbox(
    Canfd_RegisterMap_t *Module, Canfd_MB_t MailboxIndex, Canfd_RxCode_t Code, const Canfd_MsgInfo_t *MsgInfoPtr);
void     Canfd_LL_ReadRxFifo(const Canfd_RegisterMap_t *Module, Canfd_Msg_t *MsgPtr);
uint32_t Canfd_LL_GetRxFifoMask(Canfd_IDType_t IDType, Canfd_NormalRxFifoIDFormat_t FormatType, uint32_t Mask);
void     Canfd_LL_SetNormalRxFifoFilter(
        Canfd_RegisterMap_t *Module, Canfd_NormalRxFifoIDFormat_t IDFormat, const Canfd_Filter_t *IDFilterTablePtr);
kf_status_t Canfd_LL_GetMailboxData(Canfd_RegisterMap_t *Module, Canfd_MB_t MBIndex, Canfd_Msg_t *MsgPtr);
void        Canfd_LL_LockRxMailBox(Canfd_RegisterMap_t *Module, Canfd_MB_t MBIndex);
void        Canfd_LL_ResetRxMailbox(Canfd_RegisterMap_t *Module, Canfd_MB_t MBIndex);
void        Canfd_LL_DisableMemErrorDetection(Canfd_RegisterMap_t *Module);
void        Canfd_LL_ConfigControllerByOptions(Canfd_RegisterMap_t *Module, uint32_t Options);
void        Canfd_LL_ReadEnhancedRxFifo(const Canfd_RegisterMap_t *Module, Canfd_Msg_t *MsgPtr);

#ifdef __cplusplus
}
#endif /*End of __cplusplus*/
#endif /*End of KF32A158SF_DRV_CANFD_H*/
/* EOF */
