/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a158sf_reg_canfd.h
 *  @Date            : 2025-07-03
 *  @Version         : {{VersionDate}}
 *  @Description     : This document describes the register definition of Canfd
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 ******************************************************************************/
/*****************************************************************************
 *                              REVISION HISTORY
 ******************************************************************************
 *  |Date        |Version       |Author          |Description
 ******************************************************************************
 *  |2025-07-03  |v1.0          |AE Group        |New create
 *****************************************************************************/
#ifndef KF32A158SF_REG_CANFD_H
#define KF32A158SF_REG_CANFD_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 **                     QAC Warnings
 ******************************************************************************/
/* PRQA S 0750 EOF #KQR000750 */

/******************************************************************************
 **                     Include Files
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "kf_types.h"

/******************************************************************************
 *                      Macro
 ******************************************************************************/

/******************************************************************************
 **                     Typedef  Definitions
 ******************************************************************************/

#define CANFD_RAM_N_COUNT (256U)
#define CANFD_MAX_MB_NUM  (64U)
#define CANFD_ERFFEL_NUM  (6U)

#define CANFD_SMB_OFFSET                           (0xF28U)
#define CANFD_SMB_LENGTH_IN_WORD                   (0x36U)
#define CAN_SMB_OFFSET                             (0xAB0U)
#define CAN_SMB_LENGTH_IN_WORD                     (0xCU)
#define CAN_ENHANCED_RX_FIFO_OFFSET                (0x2000U)
#define CAN_ENHANCED_RX_FIFO_LENGTH_IN_WORD        (0x78U)
#define CAN_ENHANCED_RX_FIFO_FILTER_OFFSET         (0x3000U)
#define CAN_ENHANCED_RX_FIFO_FILTER_LENGTH_IN_WORD (0x6U)
typedef volatile struct
{
    /* Offset:0x0  CAN_CTL0 */
    union
    {
        struct
        {
            __IO uint32_t MAXMB    :7;
            __I           uint32_t :1;
            __IO uint32_t NRFIDFM  :2;
            __I           uint32_t :1;
            __IO uint32_t FDEN     :1;
            __IO uint32_t ATXEN    :1;
            __IO uint32_t LPRIOEN  :1;
            __IO uint32_t PNET_EN  :1;
            __IO uint32_t DMA      :1;
            __IO uint32_t IRMQ     :1;
            __IO uint32_t SRXDIS   :1;
            __IO uint32_t DOZE     :1;
            __IO uint32_t WAKSRC   :1;
            __I uint32_t  DMACK    :1;
            __IO uint32_t WRNEN    :1;
            __IO uint32_t SLFWAK   :1;
            __IO uint32_t SUPV     :1;
            __I uint32_t  HALTACK  :1;
            __IO uint32_t SOFTRST  :1;
            __IO uint32_t WAKMSK   :1;
            __I uint32_t  NOTRDY   :1;
            __IO uint32_t HALT     :1;
            __IO uint32_t NRFEN    :1;
            __IO uint32_t SETUPEN  :1;
            __IO uint32_t DISEN    :1;
        } bits;
        __IO uint32_t reg;
    } CTL0;
    /* Offset:0x4  CAN_CTL1 */
    union
    {
        struct
        {
            __IO uint32_t PROPSEG  :3;
            __IO uint32_t LOM      :1;
            __IO uint32_t LBUF     :1;
            __IO uint32_t TSYN     :1;
            __IO uint32_t BOFFREC  :1;
            __IO uint32_t SMP      :1;
            __I           uint32_t :2;
            __IO uint32_t RWRNMSK  :1;
            __IO uint32_t TWRNMSK  :1;
            __IO uint32_t LPB      :1;
            __IO uint32_t CLKSRC   :1;
            __IO uint32_t ERRMSK   :1;
            __IO uint32_t BOFFMSK  :1;
            __IO uint32_t PSEG2    :3;
            __IO uint32_t PSEG1    :3;
            __IO uint32_t RJW      :2;
            __IO uint32_t PRESDIV  :8;
        } bits;
        __IO uint32_t reg;
    } CTL1;
    /* Offset:0x8  CAN_TIMER */
    union
    {
        struct
        {
            __IO uint32_t TIMER    :16;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } TIMER;
    __I uint32_t RESERVED_0xc[1];
    /* Offset:0x10  CAN_RXMGMASK */
    union
    {
        struct
        {
            __I uint32_t  RESERVED0 :18;
            __IO uint32_t MASK      :11;
            __I uint32_t  RESERVED1 :3;
        } SFF;
        struct
        {
            __IO uint32_t MASK      :29;
            __I uint32_t  RESERVED0 :3;
        } EFF;
        __IO uint32_t reg;
    } RXMGMASK;
    /* Offset:0x14 */
    __I uint32_t RESERVED_0x14[2];
    /* Offset:0x1c  CAN_ECR */
    union
    {
        struct
        {
            __IO uint32_t TXERRCNT    :8;
            __IO uint32_t RXERRCNT    :8;
            __IO uint32_t TXERRCNT_FD :8;
            __IO uint32_t RXERRCNT_FD :8;
        } bits;
        __IO uint32_t reg;
    } ECR;
    /* Offset:0x20  CAN_ESR1 */
    union
    {
        struct
        {
            __IO uint32_t WAKINT      :1;
            __IO uint32_t ERRINT      :1;
            __IO uint32_t BOFFINT     :1;
            __I uint32_t  RXSTA       :1;
            __I uint32_t  FLTCONF     :2;
            __I uint32_t  TXSTA       :1;
            __I uint32_t  IDLE        :1;
            __I uint32_t  RXWRN       :1;
            __I uint32_t  TXWRN       :1;
            __I uint32_t  STFERR      :1;
            __I uint32_t  FRMERR      :1;
            __I uint32_t  CRCERR      :1;
            __I uint32_t  ACKERR      :1;
            __I uint32_t  BIT0ERR     :1;
            __I uint32_t  BIT1ERR     :1;
            __I uint32_t  RWRNINT     :1;
            __I uint32_t  TWRNINT     :1;
            __I uint32_t  SYNCH       :1;
            __I uint32_t  BOFFDONEINT :1;
            __I uint32_t  ERRINT_FD   :1;
            __I uint32_t  ERROVER     :1;
            __I           uint32_t    :4;
            __I uint32_t  STFERR_FD   :1;
            __I uint32_t  FRMERR_FD   :1;
            __I uint32_t  CRCERR_FD   :1;
            __I           uint32_t    :1;
            __I uint32_t  BIT0ERR_FD  :1;
            __I uint32_t  BIT1ERR_FD  :1;
        } bits;
        __IO uint32_t reg;
    } ESR1;
    /* Offset:0x24  CAN_IMASK2 */
    union
    {
        struct
        {
            __IO uint32_t BUF63TO32M :32;
        } bits;
        __IO uint32_t reg;
    } IMASK2;
    /* Offset:0x28  CAN_IMASK1 */
    union
    {
        struct
        {
            __IO uint32_t BUF31TO0M :32;
        } bits;
        __IO uint32_t reg;
    } IMASK1;
    /* Offset:0x2c  CAN_IFLAG2 */
    union
    {
        struct
        {
            __I uint32_t BUF63TO32I :32;
        } bits;
        __IO uint32_t reg;
    } IFLAG2;
    /* Offset:0x30  CAN_IFLAG1 */
    union
    {
        struct
        {
            __I uint32_t BUF0I     :1;
            __I uint32_t BUF4TO1I  :4;
            __I uint32_t BUF5I     :1;
            __I uint32_t BUF6I     :1;
            __I uint32_t BUF7I     :1;
            __I uint32_t BUF31TO8I :24;
        } bits;
        __IO uint32_t reg;
    } IFLAG1;
    /* Offset:0x34  CAN_CTL2 */
    union
    {
        struct
        {
            __I           uint32_t    :6;
            __IO uint32_t TSTAMPCAP   :2;
            __IO uint32_t MBTSBASE    :2;
            __I           uint32_t    :1;
            __IO uint32_t EDFLTDIS    :1;
            __IO uint32_t ISOCANFDEN  :1;
            __IO uint32_t BTE         :1;
            __IO uint32_t PREXCEN     :1;
            __IO uint32_t TIMER_SRC   :1;
            __IO uint32_t EACEN       :1;
            __IO uint32_t RRS         :1;
            __IO uint32_t MRP         :1;
            __IO uint32_t TASD        :5;
            __IO uint32_t NRFFN       :4;
            __IO uint32_t WRMFRZ      :1;
            __IO uint32_t ECRWRE      :1;
            __IO uint32_t BOFFDONEMSK :1;
            __IO uint32_t ERRMSK_FD   :1;
        } bits;
        __IO uint32_t reg;
    } CTL2;
    /* Offset:0x38  CAN_ESR2 */
    union
    {
        struct
        {
            __I           uint32_t :13;
            __I uint32_t  IMB      :1;
            __I uint32_t  VPS      :1;
            __IO uint32_t TWAMSK   :1;
            __I uint32_t  LPTM     :7;
            __I           uint32_t :8;
            __I uint32_t  TWAINT   :1;
        } bits;
        __IO uint32_t reg;
    } ESR2;
    __I uint32_t RESERVED_0x3c[2];
    /* Offset:0x44  CAN_CRCR */
    union
    {
        struct
        {
            __I uint32_t TXCRC    :15;
            __I          uint32_t :1;
            __I uint32_t MBCRC    :7;
            __I          uint32_t :9;
        } bits;
        __IO uint32_t reg;
    } CRCR;
    /* Offset:0x48  CAN_NRFGM */
    __IO uint32_t NRFGM;
    /* Offset:0x4c  CAN_NRFFIR */
    union
    {
        struct
        {
            __I uint32_t IDFIR    :9;
            __I          uint32_t :23;
        } bits;
        __IO uint32_t reg;
    } NRFFIR;
    /* Offset:0x50  CAN_CBT */
    union
    {
        struct
        {
            __IO uint32_t EPSEG2   :5;
            __IO uint32_t EPSEG1   :5;
            __IO uint32_t EPROPSEG :6;
            __IO uint32_t ERJW     :5;
            __IO uint32_t EPRESDIV :10;
            __IO uint32_t BTF      :1;
        } bits;
        __IO uint32_t reg;
    } CBT;
    uint32_t RESERVED_0x40004080[11];
    /** Offset:0x80 Embedded RAM */
    __IO uint32_t RAMn[CANFD_RAM_N_COUNT];
    /** Offset:0x480 */
    __I uint32_t RESERVED_0x480[256];
    /* Offset:0x880  RXIMR */
    union
    {
        struct
        {
            __I uint32_t  RESERVED0 :18;
            __IO uint32_t MASK      :11;
            __I uint32_t  RESERVED1 :3;
        } SFF;
        struct
        {
            __IO uint32_t MASK      :29;
            __I uint32_t  RESERVED0 :3;
        } EFF;
        __IO uint32_t reg;
    } RXIMR[CANFD_MAX_MB_NUM];
    __I uint32_t RESERVED_0x980[88];
    /* Offset:0xae0  CAN_MECR */
    union
    {
        struct
        {
            __I           uint32_t   :7;
            __IO uint32_t NCEFAFRZ   :1;
            __IO uint32_t ECCDIS     :1;
            __IO uint32_t RERRDIS    :1;
            __I           uint32_t   :3;
            __IO uint32_t EXTERRIE   :1;
            __IO uint32_t FAERRIE    :1;
            __IO uint32_t HAERRIE    :1;
            __IO uint32_t CEI_MSK    :1;
            __I           uint32_t   :1;
            __IO uint32_t FANCEI_MSK :1;
            __IO uint32_t HANCEI_MSK :1;
            __I           uint32_t   :11;
            __IO uint32_t ECRWRDIS   :1;
        } bits;
        __IO uint32_t reg;
    } MECR;
    /* Offset:0xae4  CAN_ERRIAR */
    union
    {
        struct
        {
            __I uint32_t  INJADDR_L :2;
            __IO uint32_t INJADDR_H :12;
            __I           uint32_t  :18;
        } bits;
        __IO uint32_t reg;
    } ERRIAR;
    /* Offset:0xae8  CAN_ERRIDPR */
    __IO uint32_t ERRIDPR;
    /* Offset:0xaec  CAN_ERRIPPR */
    union
    {
        struct
        {
            __IO uint32_t PFLIP0   :5;
            __I           uint32_t :3;
            __IO uint32_t PFLIP1   :5;
            __I           uint32_t :3;
            __IO uint32_t PFLIP2   :5;
            __I           uint32_t :3;
            __IO uint32_t PFLIP3   :5;
            __I           uint32_t :3;
        } bits;
        __IO uint32_t reg;
    } ERRIPPR;
    /* Offset:0xaf0  CAN_RERRAR */
    union
    {
        struct
        {
            __I uint32_t ERRADDR  :14;
            __I          uint32_t :2;
            __I uint32_t SAID     :3;
            __I          uint32_t :5;
            __I uint32_t NCE      :1;
            __I          uint32_t :7;
        } bits;
        __IO uint32_t reg;
    } RERRAR;
    /* Offset:0xaf4  CAN_RERRDR */
    __I uint32_t RERRDR;
    /* Offset:0xaf8  CAN_RERRSYNR */
    union
    {
        struct
        {
            __I uint32_t SYND0    :5;
            __I          uint32_t :2;
            __I uint32_t BE0      :1;
            __I uint32_t SYND1    :5;
            __I          uint32_t :2;
            __I uint32_t BE1      :1;
            __I uint32_t SYND2    :5;
            __I          uint32_t :2;
            __I uint32_t BE2      :1;
            __I uint32_t SYND3    :5;
            __I          uint32_t :2;
            __I uint32_t BE3      :1;
        } bits;
        __IO uint32_t reg;
    } RERRSYNR;
    /* Offset:0xafc  CAN_ERRSR */
    union
    {
        struct
        {
            __I uint32_t CEIOF    :1;
            __I          uint32_t :1;
            __I uint32_t FANCEIOF :1;
            __I uint32_t HANCEIOF :1;
            __I          uint32_t :12;
            __I uint32_t CEIF     :1;
            __I          uint32_t :1;
            __I uint32_t FANCEIF  :1;
            __I uint32_t HANCEIF  :1;
            __I          uint32_t :12;
        } bits;
        __IO uint32_t reg;
    } ERRSR;
    __I uint32_t RESERVED_0x40004BF0[60];
    /* Offset:0xbf0  CAN_EPRS */
    union
    {
        struct
        {
            __IO uint32_t ENPRESDIV :10;
            __I           uint32_t  :6;
            __IO uint32_t EDPRESDIV :10;
            __I           uint32_t  :6;
        } bits;
        __IO uint32_t reg;
    } EPRS;
    /* Offset:0xbf4 */
    __I uint32_t RESERVED_0xbf4[1];
    /* Offset:0xbf8 */
    __I uint32_t RESERVED_0xbf8[1];
    /* Offset:0xbfc  CAN_ETDC */
    union
    {
        struct
        {
            __I uint32_t  ETDCVAL  :8;
            __I           uint32_t :7;
            __I uint32_t  ETDCFAIL :1;
            __IO uint32_t ETDCOFF  :7;
            __I           uint32_t :7;
            __IO uint32_t TDMDIS   :1;
            __IO uint32_t ETDCEN   :1;
        } bits;
        __IO uint32_t reg;
    } ETDC;
    /* Offset:0xc00  CAN_FDCTL */
    union
    {
        struct
        {
            __I uint32_t  TDCVAL   :6;
            __I           uint32_t :2;
            __IO uint32_t TDCOFF   :5;
            __I           uint32_t :1;
            __IO uint32_t TDCFAIL  :1;
            __IO uint32_t TDCEN    :1;
            __IO uint32_t MBDSR0   :2;
            __I           uint32_t :1;
            __IO uint32_t MBDSR1   :2;
            __I           uint32_t :1;
            __IO          uint32_t :2;
            __I           uint32_t :1;
            __IO          uint32_t :2;
            __I           uint32_t :4;
            __IO uint32_t FDRATE   :1;
        } bits;
        __IO uint32_t reg;
    } FDCTL;
    /* Offset:0xc04  CAN_FDCBT */
    union
    {
        struct
        {
            __IO uint32_t FPSEG2   :3;
            __I           uint32_t :2;
            __IO uint32_t FPSEG1   :3;
            __I           uint32_t :2;
            __IO uint32_t FPROPSEG :5;
            __I           uint32_t :1;
            __IO uint32_t FRJW     :3;
            __I           uint32_t :1;
            __IO uint32_t FPRESDIV :10;
            __I           uint32_t :2;
        } bits;
        __IO uint32_t reg;
    } FDCBT;
    /* Offset:0xc08  CAN_FDCRC */
    union
    {
        struct
        {
            __I uint32_t FD_TXCRC :21;
            __I          uint32_t :3;
            __I uint32_t FD_MBCRC :7;
            __I          uint32_t :1;
        } bits;
        __IO uint32_t reg;
    } FDCRC;
    /* Offset:0xc0c  CAN_ERFCR */
    union
    {
        struct
        {
            __IO uint32_t ERFWM    :5;
            __I           uint32_t :3;
            __IO uint32_t NFE      :6;
            __I           uint32_t :2;
            __IO uint32_t NEXIF    :7;
            __I           uint32_t :3;
            __IO          uint32_t :5;
            __IO uint32_t ERFEN    :1;
        } bits;
        __IO uint32_t reg;
    } ERFCR;
    /* Offset:0xc10  CAN_ERFIER */
    union
    {
        struct
        {
            __I           uint32_t :28;
            __IO uint32_t ERFDAIE  :1;
            __IO uint32_t ERFWMIIE :1;
            __IO uint32_t ERFOVFIE :1;
            __IO uint32_t ERFUFWIE :1;
        } bits;
        __IO uint32_t reg;
    } ERFIER;
    /* Offset:0xc14  CAN_ERFSR */
    union
    {
        struct
        {
            __I uint32_t  ERFEL    :6;
            __I           uint32_t :10;
            __I uint32_t  ERFF     :1;
            __I uint32_t  ERFE     :1;
            __I           uint32_t :9;
            __O uint32_t  ERFCLR   :1;
            __IO uint32_t ERFDA    :1;
            __IO uint32_t ERFWMI   :1;
            __IO uint32_t ERFOVF   :1;
            __IO uint32_t ERFUFW   :1;
        } bits;
        __IO uint32_t reg;
    } ERFSR;
    __I uint32_t RESERVED_0xc18[6];
    /* Offset:0xc30  HR_TIME_STAMP */
    __IO uint32_t HR_TIME_STAMP[64];
    __I uint32_t  RESERVED_0xd30[2228];
    /* Offset:0x3000  ERFFEL */
    __IO uint32_t ERFFEL[CANFD_ERFFEL_NUM];
    __I uint32_t  RESERVED_0x3018[954];
    /* Offset:0x3f00  CAN_CTL3 */
    union
    {
        struct
        {
            __IO uint32_t CLK_SEL           :2;
            __IO uint32_t CLK_DIV           :3;
            __IO uint32_t READ_ENDIAN_SWAP  :1;
            __IO uint32_t WRITE_ENDIAN_SWAP :1;
            __IO uint32_t CAN_IO_EN         :1;
            __IO uint32_t CAN_TX_EN         :1;
            __I           uint32_t          :23;
        } bits;
        __IO uint32_t reg;
    } CTL3;
    /* Offset:0x3f04  CAN_TESTPIN */
    union
    {
        struct
        {
            __IO uint32_t TESTPIN1    :3;
            __IO uint32_t TESTPIN2    :3;
            __IO uint32_t TESTPIN3    :3;
            __IO uint32_t TESTPIN4    :3;
            __IO uint32_t TESTPIN5    :3;
            __IO uint32_t TESTPIN6    :3;
            __IO uint32_t TESTPIN7    :3;
            __IO uint32_t TESTPIN8    :3;
            __IO uint32_t TESTPIN1_EN :1;
            __IO uint32_t TESTPIN2_EN :1;
            __IO uint32_t TESTPIN3_EN :1;
            __IO uint32_t TESTPIN4_EN :1;
            __IO uint32_t TESTPIN5_EN :1;
            __IO uint32_t TESTPIN6_EN :1;
            __IO uint32_t TESTPIN7_EN :1;
            __IO uint32_t TESTPIN8_EN :1;
        } bits;
        __IO uint32_t reg;
    } TESTPIN;
    /* Offset:0x3f08  CAN_TESTEN */
    union
    {
        struct
        {
            __IO uint32_t TESTEN0  :1;
            __IO uint32_t TESTEN1  :1;
            __I           uint32_t :30;
        } bits;
        __IO uint32_t reg;
    } TESTEN;
} Canfd_RegisterMap_t;

/**
 * @brief Address of Canfd register
 */
#define CANFD6_ADDR ((uint32_t)0x40010000U)
#define CANFD7_ADDR ((uint32_t)0x40018000U)
#define CANFD8_ADDR ((uint32_t)0x40020000U)
#define CANFD9_ADDR ((uint32_t)0x40028000U)

/**
 * @brief Pointer to Canfd register
 */
#define CANFD6_PTR ((Canfd_RegisterMap_t *)CANFD6_ADDR)
#define CANFD7_PTR ((Canfd_RegisterMap_t *)CANFD7_ADDR)
#define CANFD8_PTR ((Canfd_RegisterMap_t *)CANFD8_ADDR)
#define CANFD9_PTR ((Canfd_RegisterMap_t *)CANFD9_ADDR)

/**
 * @brief Register map of Canfd
 */
#define CANFD6_RM (*(CANFD6_PTR))
#define CANFD7_RM (*(CANFD7_PTR))
#define CANFD8_RM (*(CANFD8_PTR))
#define CANFD9_RM (*(CANFD9_PTR))

/**
 * @brief Module check assertion
 */
#define CHECK_CANFD_ALL_PERIPH_ADDR(Module)                                                                            \
    (((uint32_t)(Module) == (uint32_t)(CANFD6_PTR)) || ((uint32_t)(Module) == (uint32_t)(CANFD7_PTR)) ||               \
     ((uint32_t)(Module) == (uint32_t)(CANFD8_PTR)) || ((uint32_t)(Module) == (uint32_t)(CANFD9_PTR)))

/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/
#ifdef LLD_TEST_INJECTION
#include "kf32_reg_test.h"
#endif
#ifdef __cplusplus
}
#endif /*End of __cplusplus*/
#endif /*End of KF32A158SF_REG_CANFD_H*/
/* EOF */
