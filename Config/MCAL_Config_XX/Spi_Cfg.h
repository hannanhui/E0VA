/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Spi_Cfg.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2026/3/10 13:22:24
 *  @Version         : V1.0
 *  @Description     : AUTOSAR Spi - High level header of SPI driver.
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 *****************************************************************************/

#ifndef SPI_CFG_H
#define SPI_CFG_H

/* The LEVEL 0 Simple Synchronous SPI Handler Driver functionalities are
 * selected.*/
#define SPI_LEVEL_0 (0x00U)

/* The LEVEL 1 Basic Asynchronous SPI Handler Driver functionalities are
 * selected.*/
#define SPI_LEVEL_1 (0x01U)

/* The LEVEL 2 Enhanced SPI Handler Driver functionalities are selected. */
#define SPI_LEVEL_2 (0x02U)

/*
 * Selects the SPI Driver level of scalable functionality between
 * SPI_LEVEL_0, SPI_LEVEL_1 or SPI_LEVEL_2
 */
#define SPI_LEVEL_DELIVERED (SPI_LEVEL_2)

/* Only Internal Buffers are allowed in Handler Driver.*/
#define SPI_USAGE0 (0x00U)

/* Only External Buffers are allowed in Handler Driver.*/
#define SPI_USAGE1 (0x01U)

/* Both Buffer types are allowed in Handler Driver. */
#define SPI_USAGE2 (0x02U)

/**
 * @brief Selects the SPI Handler Driver Channel Buffers usage allowed and
 * delivered.
 * @details Selects the SPI Handler Driver Channel Buffers usage allowed and
 * delivered. (see chapter 7.2.1)
 * @implements SPI_CHANNEL_BUFFERS_ALLOWED_define
 */
#define SPI_CHANNEL_BUFFERS_ALLOWED (SPI_USAGE2)

/* Switches the Spi_GetVersionInfo ON or OFF */
#define SPI_VERSION_INFO_API (STD_OFF)

/* Switches the Spi_Cancel function ON or OFF */
#define SPI_CANCEL_API (STD_ON)

/* Switches the Spi_GetHwUnitStatus function ON or OFF */
#define SPI_HW_STATUS_API (STD_ON)

/* SPI Slave Mode Supported */
#define SPI_SLAVE_SUPPORT (STD_OFF)

/* SPI Fifo Used */
#define SPI_FIFO_USED (STD_OFF)

/* SPI Transfer Timeout Value */
#define SPI_TRANS_MAX_TIMEOUT ((uint32)0xFFFFFU)

/* SPI Use DMA, Default Working Mode */
#define SPI_DMA_USED (STD_ON)

/**
 * @brief Max Spi Module Unit
 * For kf32a1x8 there are SPI0,SPI1,SPI2
 * @warning DO NOT MODIFY
 */
#define SPI_MAX_HWUNIT (3U)

#define SPI_MAX_SEQUENCE (1U)
#define SPI_MAX_JOB      (1U)
#define SPI_MAX_CHANNEL  (1U)

/**
 * @brief Switches the Production Error Detection and Notification ON.
 */
#define SPI_DISABLE_DEM_REPORT_ERROR_STATUS (STD_ON)

/**
 * @brief Switches the Development Error Detection ON or OFF
 *
 */
#define SPI_DEV_ERROR_DETECT (STD_OFF)

/**
 * @brief  the Interruptable Sequences handling functionality ON or OFF
 * Only used for with Level 1 or 2
 */
#define SPI_INTERRUPTABLE_SEQ_ALLOWED (STD_OFF)

/**
 * @brief Defines the periodic time of the function Spi_MainFunction_Handling
 * The unit time is defined in seconds
 * Parameter is used by upper layer modules not by this driver
 *
 */
#define SPI_MAIN_FUNCTION_PERIOD (0.1F) /* In Seconds */

/**
 * @brief Only in Level 0 Specifies whether the concurrent Spi_SyncTransmit()
 * calls for different sequences is accepted or not Sequences must use different
 * buses
 *
 */
#define SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT (STD_OFF)

/* (2bytes*x) Reserve 256 Bytes for Internal Buffers */
#define SPI_IB_MAX_LENGTH (10U)

#define SPI_PRECOMPILE_SUPPORT (STD_OFF)

/**
 * @brief SPI Channel ID, used as parameter in SPI API functions.
 */
#define SpiConf_SpiChannelId_0 (0U)
/**
 * @brief SPI Job ID, used as parameter in SPI API functions.
 */
#define SpiConf_SpiJobId_0 (0U)
/**
 * @brief SPI Job ID, used as parameter in SPI API functions.
 */
#define SpiConf_SpiSequenceId_0 (0U)

#endif
/* EOF */
