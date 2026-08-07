/**************************************************************************************************/
/**
 * @file     flash_drv.h
 * @brief    FLASH driver module header file.
 * @version  V1.1.1
 * @date     December-2022
 * @author   Zhixin Semiconductor
 *
 * @note
 * Copyright (C) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 * 
 **************************************************************************************************/

#ifndef MFLASH_DRV_H
#define MFLASH_DRV_H

#include "common_drv.h"

/** @addtogroup  Z20K14XM_Peripheral_Driver
 *  @{
 */

/** @addtogroup  FLASH
 *  @{
 */

/** @defgroup FLASH_Public_Types 
 *  @{
 */

/**
 *  @brief FLASH status mask definition
 */
#define FLASH_STATUS_FAIL_MASK           0x00000001U /*!< command fail */
#define FLASH_STATUS_CMDABT_MASK         0x00000004U /*!< Command Abort */
#define FLASH_STATUS_ACCERR_MASK         0x00000020U /*!< Access Error */
#define FLASH_STATUS_PREABT_MASK         0x00000040U /*!< Write Sequence Abort */
#define FLASH_STATUS_CCIF_MASK           0x00000080U /*!< Command Complete */
#define FLASH_STATUS_CMDWRF_MASK         0x00000800U /*!< Flash command registers written */
#define FLASH_STATUS_DFDIF_MASK          0x00010000U /*!< Multi-bit ECC fault */
#define FLASH_STATUS_SFDIF_MASK          0x00020000U /*!< Single-bit ECC fault */
#define FLASH_STATUS_DBG_ERSALL_DIS_MASK 0x40000000U /*!< debug erase all request disable */
#define FLASH_STATUS_FSEC_MASK           0x80000000U /*!< Flash secure state */

/**
 *  @brief FLASH interrupt type definition
 */
 
 
 
#define FLASH_CODE_BASE_ADDR           ((uint32_t)0x00000000)            /*!< program/Code flash base address */
#define FLASH_CODE_END_ADDR            ((uint32_t)0x0007FFFF)            /*!< program/Code flash end address */
#define FLASH_DATA_BASE_ADDR           ((uint32_t)0x01000000)            /*!< Data flash base address */
#define FLASH_DATA_END_ADDR            ((uint32_t)0x0101FFFF)            /*!< Data flash end address */
#define FLASH_IFR_BASE_ADDR            ((uint32_t)0x02000000)            /*!< flash IFR base address */
#define FLASH_IFR_END_ADDR             ((uint32_t)0x02007FFF)            /*!< flash IFR end address */
#define SRAMU_BASE_ADDR                ((uint32_t)0x20000000)            /*!< SRAMU base address */
#define SRAMU_END_ADDR                 ((uint32_t)0x2000FFFF)            /*!< SRAMU end address */ 
#define PERIPHERAL_BASE_ADDR           ((uint32_t)0x40000000)            /*!< Peripheral area base address */
#define AIPS0_BASE_ADDR                ((uint32_t)0x40000000)            /*!< AIPS0 base address */
#define FLASH_DFLASH_SIZE              ((uint32_t)0x00020000)            /*!< Data flash size */
#define PRI_PERI_BUS_BASE_ADDR         ((uint32_t)0xE0000000)            /*!< private Peripheral base address */
 
 
 
 #define FLASH_TIMEOUT_ABORT_WAIT_CNT        300U
 #define FLASH_TIMEOUT_WAIT_CNT_ERASE_ALL    30000000U 
 #define FLASH_TIMEOUT_WAIT_CNT              300000U
typedef enum
{
    FLASH_INT_CCIF = 0U,    /*!< command complete */
    FLASH_INT_DFDIF,        /*!< Multi-bit ECC fault */
    FLASH_INT_SFDIF,        /*!< single-bit ECC fault */
    FLASH_INT_ALL           /*!< all interrupt */
}FLASH_Int_t;

/**
 *  @brief FLASH user actions when execute a command type definition
 */
typedef enum
{
    FLASH_CMD_ACT_WAIT = 0U,    /*!< wait until a command is completed */
    FLASH_CMD_ACT_INT           /*!< enable interrupt and use interrupt to inform
                                     when the command is completed */ 
}FLASH_CmdAct_t;


/**
 *  @brief FLASH abort command result type definition
 */
typedef enum
{
    FLASH_ABORT_OK = 0U,      /*!< abort flash command succeeded */
    FLASH_ABORT_FINISHED,     /*!< abort failed, but flash command has been finished  */
    FLASH_ABORT_TIMEOUT,      /*!< abort flash command timeout */ 
}FLASH_AbortResult_t;

/** 
 *   @brief Call back function pointer data type
 *   If using callback in the application, any code reachable from this function
 *   must not be placed in a Flash block targeted for a program/erase operation.
 *   Functions can be placed in RAM section.
 */
typedef void (* flash_cb_t)(void);

/**
 * @brief Flash command Configuration Structure
 */
typedef struct
{
    FLASH_CmdAct_t act;   /*!< define the actions when the command is executing
                               - FLASH_CMD_ACT_WAIT: wait until a command is completed
                               - FLASH_CMD_ACT_INT: enable interrupt and use interrupt to inform
                                     when the command is completed */   
    flash_cb_t callBack;   /*!< Call back function to service the time critical 
                                events. Any code reachable from this function
                                must not be placed in a Flash block targeted for
                                a program/erase operation. if "act" parameter is 
                                set to FLASH_CMD_ACT_WAIT, this callBack is called
                                when waiting for the completion of command. If
                                FLASH_CMD_ACT_INT is selected, this parameter can
                                be ignored a interrupt call back function can be
                                installed through FLASH_InstallCallBackFunc() */
} FLASH_CmdConfig_t;

/**
 * @brief Flash ECC state Structure
 */
typedef struct
{
    FlagStatus_t eccFlag;   /*!< It reflects if an single/multi bit ECC error is
                                 detected
                               - RESET: no ECC error
                               - SET: ECC error is detected */
    FlagStatus_t overrun;   /*!< It reflects if single/multi bit ECC error is 
                                 overrun
                               - RESET: no overrun
                               - SET: ECC error is overrun */
    uint32_t addr;          /*!< If an ECC error is detected, it indicates the
                                 address where ECC error happens */

} FLASH_EccState_t;

/** @} end of group FLASH_Public_Types */

/** @defgroup FLASH_Public_Constants
 *  @{
 */

/** @} end of group FLASH_Public_Constants */

/** @defgroup FLASH_Public_Macro
 *  @{
 */

/** @} end of group FLASH_Public_Macro */

/** @defgroup FLASH_Public_FunctionDeclaration
 *  @brief FLASH functions declaration
 *  @{
 */

/**
 * @brief      configure a range of Flash to not generate bus error when 
 *             multi-bit ECC error happens.
 *
 * @param[in]  startAddr: The start address of flash to ignore bus error. It 
 *                        should be 16-byte aligned, the lowest 4 bits of 
 *                        starAddr shall always be 0. The range should be within
 *                        Flash memory.
 * @param[in]  endAddr: The end address of flash to ignore bus error. It 
 *                        should be 16-byte aligned, the lowest 4 bits of 
 *                        starAddr shall always be 0. The range should be within
 *                        Flash memory.
 *
 * @return     none
 *
 */
 
 
 
 struct scm_reg {
    /* 0x00*/
    struct {
           uint32_t RSVD_3_0                : 4;  /* [3:0]          ro         */
           uint32_t CLKOUTSEL               : 2;  /* [5:4]          r/w        */
           uint32_t RSVD_7_6                : 2;  /* [7:6]          ro         */
           uint32_t CLKOUTDIV               : 3;  /* [10:8]         r/w        */
           uint32_t CLKOUTEN                : 1;  /* [11]           r/w        */
           uint32_t RSVD_31_12              :20;  /* [31:12]        ro         */
    } SCM_CHIPCTL;

    /* 0x04*/
    struct {
           uint32_t SWTRIG0                 : 1;  /* [0]            r/w        */
           uint32_t SWTRIG1                 : 1;  /* [1]            r/w        */
           uint32_t SWTRIG2                 : 1;  /* [2]            r/w        */
           uint32_t SWTRIG3                 : 1;  /* [3]            r/w        */
           uint32_t SRAML_READ_BUFF_EN      : 1;  /* [4]            r/w        */
           uint32_t SRAMU_READ_BUFF_EN      : 1;  /* [5]            r/w        */
           uint32_t XBAR_ROUND_ROBIN        : 1;  /* [6]            r/w        */
           uint32_t RSVD_10_7               : 4;  /* [10:7]         ro         */
           uint32_t CCACHE_CLR              : 1;  /* [11]           r/w        */
           uint32_t CCACHE_PARITY_MISS_EN   : 1;  /* [12]           r/w        */
           uint32_t CCACHE_PARITY_FAULT_EN  : 1;  /* [13]           r/w        */
           uint32_t CACHE_DIS               : 1;  /* [14]           r/w        */
           uint32_t RSVD_15                 : 1;  /* [15]           ro         */
           uint32_t CCACHE_BE_INT_EN        : 1;  /* [16]           r/w        */
           uint32_t RSVD_23_17              : 7;  /* [23:17]        ro         */
           uint32_t FPU_INEXACT_INT_EN      : 1;  /* [24]           r/w        */
           uint32_t FPU_OVERFLOW_INT_EN     : 1;  /* [25]           r/w        */
           uint32_t FPU_UNDERFLOW_INT_EN    : 1;  /* [26]           r/w        */
           uint32_t FPU_INVALIDOP_INT_EN    : 1;  /* [27]           r/w        */
           uint32_t FPU_DIVZERO_INT_EN      : 1;  /* [28]           r/w        */
           uint32_t FPU_DENORMALIN_INT_EN   : 1;  /* [29]           r/w        */
           uint32_t RSVD_31_30              : 2;  /* [31:30]        ro         */
    } SCM_MISCCTL1;

    uint8_t zResverd0x08[32];   /*pad 0x08 - 027*/

    /* 0x28*/
    struct {
           uint32_t RSVD_7_0                : 8;  /* [7:0]          ro         */
           uint32_t MCPWM0_TCLK_SEL         : 2;  /* [9:8]          r/w        */
           uint32_t MCPWM1_TCLK_SEL         : 2;  /* [11:10]        r/w        */
           uint32_t TIM0_TCLK_SEL           : 2;  /* [13:12]        r/w        */
           uint32_t TIM1_TCLK_SEL           : 2;  /* [15:14]        r/w        */
           uint32_t TIM2_TCLK_SEL           : 2;  /* [17:16]        r/w        */
           uint32_t TIM3_TCLK_SEL           : 2;  /* [19:18]        r/w        */
           uint32_t RSVD_23_20              : 4;  /* [23:20]        ro         */
           uint32_t ADC0_CH8_SEL            : 1;  /* [24]           r/w        */
           uint32_t ADC0_CH9_SEL            : 1;  /* [25]           r/w        */
           uint32_t ADC1_CH14_SEL           : 1;  /* [26]           r/w        */
           uint32_t ADC1_CH15_SEL           : 1;  /* [27]           r/w        */
           uint32_t RSVD_31_28              : 4;  /* [31:28]        ro         */
    } SCM_MISCCTL2;

    uint8_t zResverd0x02C[20];   /*pad 0x02C - 03F*/

    /* 0x40*/
    struct {
           uint32_t RSVD_15_0               :16;  /* [15:0]         ro         */
           uint32_t CACHE_BE_FLAG           : 1;  /* [16]           w1c        */
           uint32_t CACHE_BE_SUPV           : 1;  /* [17]           ro         */
           uint32_t CACHE_BE_HSIZE          : 2;  /* [19:18]        ro         */
           uint32_t CACHE_BE_HMAST          : 4;  /* [23:20]        ro         */
           uint32_t FPU_INEXACT_FLAG        : 1;  /* [24]           r/w        */
           uint32_t FPU_OVERFLOW_FLAG       : 1;  /* [25]           r/w        */
           uint32_t FPU_UNDERFLOW_FLAG      : 1;  /* [26]           r/w        */
           uint32_t FPU_INVALIDOP_FLAG      : 1;  /* [27]           r/w        */
           uint32_t FPU_DIVZERO_FLAG        : 1;  /* [28]           r/w        */
           uint32_t FPU_DENORMALIN_FLAG     : 1;  /* [29]           r/w        */
           uint32_t RSVD_31_30              : 2;  /* [31:30]        ro         */
    } SCM_MISCSTAT1;

    /* 0x44*/
    struct {
           uint32_t CACHE_BE_ADDR           :32;  /* [31:0]         ro         */
    } SCM_MISCDATA1;

    /* 0x48*/
    struct {
           uint32_t CACHE_BE_DATA           :32;  /* [31:0]         ro         */
    } SCM_MISCDATA2;

    uint8_t zResverd0x04C[180];   /*pad 0x04C - 0FF*/

    /* 0x100*/
    struct {
           uint32_t CCACHE_DIS_IFR          : 1;  /* [0]            ro         */
           uint32_t FPU_DIS                 : 1;  /* [1]            r/w        */
           uint32_t RSVD_31_2               :30;  /* [31:2]         ro         */
    } SCM_CHIPOPT;

    /* 0x104*/
    struct {
           uint32_t RSVD_23_0               :24;  /* [23:0]         ro         */
           uint32_t PFSIZE                  : 4;  /* [27:24]        ro         */
           uint32_t DFSIZE                  : 4;  /* [31:28]        ro         */
    } SCM_FLSCFG;

    /* 0x108*/
    struct {
           uint32_t CACHESIZE               : 4;  /* [3:0]          ro         */
           uint32_t RSVD_27_4               :24;  /* [27:4]         ro         */
           uint32_t RAMSIZE                 : 4;  /* [31:28]        ro         */
    } SCM_RAMCFG;

    uint8_t zResverd0x010C[16];   /*pad 0x010C - 011B*/

    /* 0x11C*/
    struct {
           uint32_t MEMSIZE_ID              : 4;  /* [3:0]          ro         */
           uint32_t SERIES_ID               : 3;  /* [6:4]          ro         */
           uint32_t SUBFAMILY_ID            : 5;  /* [11:7]         ro         */
           uint32_t FAMILY_ID               : 4;  /* [15:12]        ro         */
           uint32_t REV_ID                  : 4;  /* [19:16]        ro         */
           uint32_t FEATURE_ID              : 7;  /* [26:20]        ro         */
           uint32_t PACKAGE_ID              : 5;  /* [31:27]        ro         */
    } SCM_DEVID;

    /* 0x120*/
    struct {
           uint32_t UID_31_0                :32;  /* [31:0]         ro         */
    } SCM_UNIQUE0;

    /* 0x124*/
    struct {
           uint32_t UID_63_32               :32;  /* [31:0]         ro         */
    } SCM_UNIQUE1;

    /* 0x128*/
    struct {
           uint32_t UID_95_64               :32;  /* [31:0]         ro         */
    } SCM_UNIQUE2;

    /* 0x12C*/
    struct {
           uint32_t UID_127_96              :32;  /* [31:0]         ro         */
    } SCM_UNIQUE3;

};    /*scm_reg*/

struct scm_reg_w {
    /* 0x00*/
    uint32_t SCM_CHIPCTL;
    /* 0x04*/
    uint32_t SCM_MISCCTL1;
    uint8_t zResverd0x08[32];   /*pad 0x08 - 027*/

    /* 0x28*/
    uint32_t SCM_MISCCTL2;
    uint8_t zResverd0x02C[20];   /*pad 0x02C - 03F*/

    /* 0x40*/
    uint32_t SCM_MISCSTAT1;
    /* 0x44*/
    uint32_t SCM_MISCDATA1;
    /* 0x48*/
    uint32_t SCM_MISCDATA2;
    uint8_t zResverd0x04C[180];   /*pad 0x04C - 0FF*/

    /* 0x100*/
    uint32_t SCM_CHIPOPT;
    /* 0x104*/
    uint32_t SCM_FLSCFG;
    /* 0x108*/
    uint32_t SCM_RAMCFG;
    uint8_t zResverd0x010C[16];   /*pad 0x010C - 011B*/

    /* 0x11C*/
    uint32_t SCM_DEVID;
    /* 0x120*/
    uint32_t SCM_UNIQUE0;
    /* 0x124*/
    uint32_t SCM_UNIQUE1;
    /* 0x128*/
    uint32_t SCM_UNIQUE2;
    /* 0x12C*/
    uint32_t SCM_UNIQUE3;
};    /*scm_reg*/


 struct flash_reg_w {
    /* 0x0*/
    uint32_t FLASH_FSTAT;
    /* 0x4*/
    uint32_t FLASH_FCNFG;
    /* 0x8*/
    uint32_t FLASH_FCTRL;
    uint8_t zResverd0x0C[4];   /*pad 0x0C - 0F*/

    /* 0x10*/
    uint32_t FLASH_FCMD;
    /* 0x14*/
    uint8_t zResverd0x14[4];
    /* 0x18*/
    uint32_t FLASH_FADDR;
    /* 0x1C*/
    uint32_t FLASH_FADDR_END;
    /* 0x20*/
    uint32_t FLASH_FDATA0;
    /* 0x24*/
    uint32_t FLASH_FDATA1;
    /* 0x28*/
    uint32_t FLASH_FDATA2;
    /* 0x2C*/
    uint32_t FLASH_FDATA3;
    /* 0x30*/
    uint32_t FLASH_BED_ADDR_STRT;
    /* 0x34*/
    uint32_t FLASH_BED_ADDR_END;
    /* 0x38*/
    uint32_t FLASH_ECC_IN_ADDR;
    /* 0x3C*/
    uint32_t FLASH_ECC_IN_CTRL;
    /* 0x40*/
    uint32_t FLASH_MBE_STATE;
    /* 0x44*/
    uint32_t FLASH_SBE_STATE;
};
 
 
 struct flash_reg {
    /* 0x0*/
    struct {
           uint32_t FAIL                    : 1;  /* [0]            ro         */
           uint32_t RSVD_1                  : 1;  /* [1]            ro         */
           uint32_t CMDABT                  : 1;  /* [2]            r/w1c      */
           uint32_t RSVD_4_3                : 2;  /* [4:3]          ro         */
           uint32_t ACCERR                  : 1;  /* [5]            r/w1c      */
           uint32_t PREABT                  : 1;  /* [6]            r/w1c      */
           uint32_t CCIF                    : 1;  /* [7]            r/w1c      */
           uint32_t RSVD_10_8               : 3;  /* [10:8]         ro         */
           uint32_t CMDWRF                  : 1;  /* [11]           ro         */
           uint32_t RSVD_15_12              : 4;  /* [15:12]        ro         */
           uint32_t DFDIF                   : 1;  /* [16]           r/w1c      */
           uint32_t SFDIF                   : 1;  /* [17]           r/w1c      */
           uint32_t RSVD_29_18              :12;  /* [29:18]        ro         */
           uint32_t DBG_ERSALL_DIS          : 1;  /* [30]           ro         */
           uint32_t FSEC                    : 1;  /* [31]           ro         */
    } FLASH_FSTAT;

    /* 0x4*/
    struct {
           uint32_t BK_QUERY                : 1;  /* [0]            r/w        */
           uint32_t RSVD_6_1                : 6;  /* [6:1]          ro         */
           uint32_t CCIE                    : 1;  /* [7]            r/w        */
           uint32_t DBG_ERS_FLG             : 1;  /* [8]            ro         */
           uint32_t RSVD_15_9               : 7;  /* [15:9]         ro         */
           uint32_t DFDIE                   : 1;  /* [16]           r/w        */
           uint32_t SFDIE                   : 1;  /* [17]           r/w        */
           uint32_t RSVD_31_18              :14;  /* [31:18]        ro         */
    } FLASH_FCNFG;

    /* 0x8*/
    struct {
           uint32_t RWSC                    : 4;  /* [3:0]          r/w        */
           uint32_t RSVD_15_4               : 12;  /* [15:4]        ro         */
           uint32_t FECCF                   : 1;  /* [16]           r/w        */
           uint32_t RSVD_23_17              : 7;  /* [23:17]        ro         */
           uint32_t ABTREQ                  : 1;  /* [24]           r/w        */
           uint32_t RSVD_31_25              : 7;  /* [31:25]        ro         */
    } FLASH_FCTRL;

    uint8_t zResverd0x0C[4];   /*pad 0x0C - 0F*/

    /* 0x10*/
    struct {
           uint32_t CMDCODE                 : 8;  /* [7:0]          r/w        */
           uint32_t RSVD_31_8               :24;  /* [31:8]         ro         */
    } FLASH_FCMD;

    /* 0x14*/
    uint8_t zResverd0x14[4];  

    /* 0x18*/
    struct {
           uint32_t CMDADDR                 :32;  /* [31:0]         r/w        */
    } FLASH_FADDR;

    /* 0x1C*/
    struct {
           uint32_t CMDADDRE                :32;  /* [31:0]         r/w        */
    } FLASH_FADDR_END;

    /* 0x20*/
    struct {
           uint32_t CMDDATA0                :32;  /* [31:0]         r/w        */
    } FLASH_FDATA0;

    /* 0x24*/
    struct {
           uint32_t CMDDATA1                :32;  /* [31:0]         r/w        */
    } FLASH_FDATA1;

    /* 0x28*/
    struct {
           uint32_t CMDDATA2                :32;  /* [31:0]         r/w        */
    } FLASH_FDATA2;

    /* 0x2C*/
    struct {
           uint32_t CMDDATA3                :32;  /* [31:0]         r/w        */
    } FLASH_FDATA3;

    /* 0x30*/
    struct {
           uint32_t RSVD_3_0                : 4;  /* [3:0]          ro         */
           uint32_t BED_ADDR_STRT           :28;  /* [31:4]         r/w        */
    } FLASH_BED_ADDR_STRT;

    /* 0x34*/
    struct {
           uint32_t RSVD_3_0                : 4;  /* [3:0]          ro         */
           uint32_t BED_ADDR_END            :28;  /* [31:4]         r/w        */
    } FLASH_BED_ADDR_END;

    /* 0x38*/
    struct {
           uint32_t RSVD_3_0                : 4;  /* [3:0]          ro         */
           uint32_t ECC_IN_ADDR             :28;  /* [31:4]         r/w        */
    } FLASH_ECC_IN_ADDR;

    /* 0x3C*/
    struct {
           uint32_t ECC_9BIT                : 9;  /* [8:0]          r/w        */
           uint32_t ECC_IN_EN               : 1;  /* [9]            r/w        */
           uint32_t RSVD_30_10              :21;  /* [30:10]        ro         */
           uint32_t LOCK                    : 1;  /* [31]           r/w        */
    } FLASH_ECC_IN_CTRL;

    /* 0x40*/
    struct {
           uint32_t MBE_FLAG                : 1;  /* [0]            w1c        */
           uint32_t MBE_OVERRUN             : 1;  /* [1]            ro         */
           uint32_t RSVD_3_2                : 2;  /* [3:2]          ro         */
           uint32_t MBE_ADDR                :28;  /* [31:4]         ro         */
    } FLASH_MBE_STATE;

    /* 0x44*/
    struct {
           uint32_t SBE_FLAG                : 1;  /* [0]            w1c        */
           uint32_t SBE_OVERRUN             : 1;  /* [1]            ro         */
           uint32_t RSVD_3_2                : 2;  /* [3:2]          ro         */
           uint32_t SBE_ADDR                :28;  /* [31:4]         ro         */
    } FLASH_SBE_STATE;

};    /*flash_reg*/
 
 
void FLASH_IgnoreBusErrorConfig(uint32_t startAddr, uint32_t endAddr);

/**
 * @brief      Verify all flash and IFR space are in the erased state
 *
 * @param[in]  config: config the action when the command is executing
 *
 * @note       if config->callBack is not NULL, it has to point to a function 
 *             that is not in flash memory
 *             Due to the lack of correction for ECC errors, this interface's result
 *             may be different from the verification after erase sector operation.
 *
 * @return     
 *             - SUCC -- successful
 *             - ERR --  some error
 *             - BUSY -- flash is executing last command. It can not execute this  
 *                       new command now.  
 *
 */
ResultStatus_t FLASH_VerifyAll(const FLASH_CmdConfig_t *config);


/**
 * @brief      Verify that a flash block is erased
 *
 * @param[in]  addr: block start address, the range should be within Pflash or Dflash memory
 * @param[in]  config: config the action when the command is executing
 *
 * @note       if config->callBack is not NULL, it has to point to a function 
 *             that is not in the flash memory that flash commands is executing
 *             in.
 *             Due to the lack of correction for ECC errors, this interface's result
 *             may be different from the verification after erase sector operation.
 *
 * @return     - SUCC -- successful
 *             - ERR --  some error
 *             - BUSY -- flash is executing last command. It can not execute this  
 *                       new command now.  
 *
 */   
ResultStatus_t FLASH_VerifyBlock(uint32_t addr,
                                 const FLASH_CmdConfig_t *config);

/**
 * @brief      Verify that a flash sector is erased
 *
 * @param[in]  addr: sector start address, the range should be within Pflash or Dflash memory
 * @param[in]  config: config the action when the command is executing
 *
 * @note       if config->callBack is not NULL, it has to point to a function 
 *             that is not in the flash memory that flash commands is executing
 *             in.
 *             Due to the lack of correction for ECC errors, this interface's result
 *             may be different from the verification after erase sector operation.
 *
 * @return     - SUCC -- successful
 *             - ERR -- some error
 *             - BUSY -- flash is executing last command. It can not execute this  
 *                       new command now. 
 *
 */   
ResultStatus_t FLASH_VerifySector(uint32_t addr,
                                  const FLASH_CmdConfig_t *config);
     
/**
 * @brief      Verify that a flash page is erased
 *
 * @param[in]  addr: page start address, the range should be within Pflash or Dflash memory
 * @param[in]  config: config the action when the command is executing
 *
 * @note       if config->callBack is not NULL, it has to point to a function 
 *             that is not in the flash memory that flash commands is executing
 *             in.
 *             Due to the lack of correction for ECC errors, this interface's result
 *             may be different from the verification after erase sector operation.
 *
 * @return     - SUCC -- successful
 *             - ERR -- some error
 *             - BUSY -- flash is executing last command. It can not execute this  
 *                       new command now.  
 *
 */   
ResultStatus_t FLASH_VerifyPage(uint32_t addr,
                                const FLASH_CmdConfig_t *config);
     
/**
 * @brief      Verify that a flash phrase is erased
 *
 * @param[in]  addr: phrase start address, the range should be within Pflash or Dflash memory
 * @param[in]  config: config the action when the command is executing
 *
 * @note       1.if config->callBack is not NULL, it has to point to a function 
 *             that is not in the flash memory that flash commands is executing
 *             in.
 *             2.Due to the lack of correction for ECC errors, this interface's result
 *             may be different from the verification after erase sector operation.
 *             3.This interface does not support flash address from 0x00100000 
 *             to 0x001FFFFF(upper 1MB area in program flash). If the input parameter 
 *             (addr) is passed with a invalid address, the return value shall be ERR.
 *
 * @return     - SUCC -- successful
 *             - ERR -- some error
 *             - BUSY -- flash is executing last command. It can not execute this  
 *                       new command now.  
 *
 */   
ResultStatus_t FLASH_VerifyPhrase(uint32_t addr,
                                  const FLASH_CmdConfig_t *config);

/**
 * @brief      Generate MISR signature for flash pages
 *
 * @param[in]  startAddr: page start address, the range should be within Pflash or Dflash memory
 * @param[in]  endAddr: Ending phrase address. It must be the last phrase in a page.
 *                      The range should be within Pflash or Dflash memory.
 * @param[in]  seed: the pointer that points to the 4-word seed
 * @param[in]  signature: the pointer that points the memory that the 128-bit 
 *                        signature result that will be stored through this function.
 *                        it is only valid when config->act == FLASH_CMD_ACT_WAIT.
 *                       If config->act == FLASH_CMD_ACT_INT, the result is not stored
 * @param[in]  config: config the action when the command is executing. If
 *                     FLASH_CMD_ACT_WAIT is selected, the result is stored in
 *                     signature[4]. If FLASH_CMD_ACT_INT is selected, the result
 *                     is not stored. user can get the result in the interrupt
 *                     call back function
 *
 * @note       1.if config->callBack is not NULL, it has to point to a function 
 *             that is not in the flash memory that flash commands is executing
 *             in.
 *             2.This interface does not support flash address from 0x00100000 
 *             to 0x001FFFFF(upper 1MB area in program flash). If the input parameter 
 *             (startAddr/endAddr) is passed with a invalid address, the return value shall be ERR.
 *
 * @return     - SUCC -- successful
 *             - ERR -- some error
 *             - BUSY -- flash is executing last command. It can not execute this  
 *                       new command now. 
 *
 */   
ResultStatus_t FLASH_PagesMircSignature(uint32_t startAddr, uint32_t endAddr,
                                        uint32_t seed[4], uint32_t signature[4],
                                        const FLASH_CmdConfig_t *config);
 
/**
 * @brief      Verify that a flash IFR sector is erased
 *
 * @param[in]  addr: IFR sector start address, the range should be within Flash IFR memory
 * @param[in]  config: config the action when the command is executing
 *
 * @note       if config->callBack is not NULL, it has to point to a function 
 *             that is not in the flash memory that flash commands is executing
 *             in.
 *             Due to the lack of correction for ECC errors, this interface's result
 *             may be different from the verification after erase sector operation.
 *
 * @return     - SUCC -- successful
 *             - ERR -- some error
 *             - BUSY -- flash is executing last command. It can not execute this  
 *                       new command now. 
 *
 */   
ResultStatus_t FLASH_VerifyIfrSector(uint32_t addr,
                                     const FLASH_CmdConfig_t *config);
     
/**
 * @brief      Verify that a flash IFR page is erased
 *
 * @param[in]  addr: IFR page start address, the range should be within Flash IFR memory
 * @param[in]  config: config the action when the command is executing
 *
 * @note       if config->callBack is not NULL, it has to point to a function 
 *             that is not in the flash memory that flash commands is executing
 *             in.
 *             Due to the lack of correction for ECC errors, this interface's result
 *             may be different from the verification after erase sector operation.
 *
 * @return     - SUCC -- successful
 *             - ERR -- some error 
 *             - BUSY -- flash is executing last command. It can not execute this  
 *                       new command now. 
 *
 */   
ResultStatus_t FLASH_VerifyIfrPage(uint32_t addr,
                                   const FLASH_CmdConfig_t *config);
     
/**
 * @brief      Verify that a flash IFR phrase is erased
 *
 * @param[in]  addr: IFR phrase start address, the range should be within Flash IFR memory
 * @param[in]  config: config the action when the command is executing
 *
 * @note       if config->callBack is not NULL, it has to point to a function 
 *             that is not in the flash memory that flash commands is executing
 *             in.
 *             Due to the lack of correction for ECC errors, this interface's result
 *             may be different from the verification after erase sector operation.
 *
 * @return     - SUCC -- successful
 *             - ERR -- some error 
 *             - BUSY -- flash is executing last command. It can not execute this  
 *                       new command now. 
 *
 */   
ResultStatus_t FLASH_VerifyIfrPhrase(uint32_t addr,
                                     const FLASH_CmdConfig_t *config);

/**
 * @brief      Generate MISR signature for flash IFR pages
 *
 * @param[in]  startAddr: page start address, the range should be within Flash IFR memory
 * @param[in]  endAddr: Ending phrase address. It must be the last phrase in a page.
 *                      The range should be within Flash IFR memory.
 * @param[in]  seed: the pointer that points to the 4-word seed
 * @param[in]  signature: the pointer that points the memory that the 128-bit 
 *                        signature result that will be stored through this function.
 *                        it is only valid when config->act == FLASH_CMD_ACT_WAIT.
 *                       If config->act == FLASH_CMD_ACT_INT, the result is not stored
 * @param[in]  config: config the action when the command is executing. If
 *                     FLASH_CMD_ACT_WAIT is selected, the result is stored in
 *                     signature[4]. If FLASH_CMD_ACT_INT is selected, the result
 *                     is not selected. user can get the result in the interrupt
 *                     call back function
 *
 * @note       if config->callBack is not NULL, it has to point to a function 
 *             that is not in the flash memory that flash commands is executing
 *             in.
 *
 * @return     - SUCC -- successful
 *             - ERR -- some error
 *             - BUSY -- flash is executing last command. It can not execute this  
 *                       new command now.  
 *
 */   
ResultStatus_t FLASH_IfrPagesMircSignature(uint32_t startAddr, uint32_t endAddr,
                                        uint32_t seed[4], uint32_t signature[4],
                                        const FLASH_CmdConfig_t *config);

/**
 * @brief      program a Dflash phrase
 *
 * @param[in]  flashAddr: phrase start address to be programmed
 *                        The range should be within Dflash memory.
 * @param[in]  dataP: points to data to be programmed into flash
 * @param[in]  config: config the action when the command is executing
 *
 * @note       if config->callBack is not NULL, it has to point to a function 
 *             that is not in the flash memory that flash commands is executing
 *             in.
 *
 * @return     - SUCC -- successful.
 *             - ERR -- invalid input address, or command execution error or timeout.
 *             - BUSY -- flash is executing last command. It can not execute this  
 *                       new command now. 
 *
 */
ResultStatus_t FLASH_ProgramDflashPhrase(uint32_t flashAddr, const uint8_t *dataP, 
                                         const FLASH_CmdConfig_t *config);
/**
 * @brief      program a flash phrase
 *
 * @param[in]  flashAddr: phrase start address to be programmed
 *                        The range should be within Flash memory.
 * @param[in]  dataP: points to data to be programmed into flash
 * @param[in]  config: config the action when the command is executing
 *
 * @note       if config->callBack is not NULL, it has to point to a function 
 *             that is not in the flash memory that flash commands is executing
 *             in.
 *
 * @return     - SUCC -- successful
 *             - ERR -- some error 
 *             - BUSY -- flash is executing last command. It can not execute this  
 *                       new command now. 
 *
 */
ResultStatus_t FLASH_ProgramPhrase(uint32_t flashAddr, const uint8_t *dataP, 
                                   const FLASH_CmdConfig_t *config);
     
/**
 * @brief      program flash memory
 *
 * @param[in] flashAddr: start address of flash memory, the range should be within Flash memory.
 *                   It is the start address of a phrase. 
 *                   This address should be aligned to 4 words(16 bytes).
 * @param[in] len: length in byte to be programmed, should not exceed the 
 *                  range of the Flash memory when it is added to flashAddr.
 *                 This length should be aligned to 4 words(16 bytes).
 * @param[in] dataP: points to the source buffer from which data is taken 
 *                     for program operation.
 * @param[in]  callBack: the callBack function when waiting for command executing
 *
 * @note       if callBack is not NULL, it has to point to a function 
 *             that is not in the flash memory that flash commands is executing
 *             in.
 *
 * @return     - SUCC -- successful
 *             - ERR -- some error
 *             - BUSY -- flash is executing last command. It can not execute this  
 *                       new command now.  
 *
 */   
ResultStatus_t FLASH_Program(uint32_t flashAddr, uint32_t len, const uint8_t *dataP,
                             flash_cb_t callBack);


/**
 * @brief      Erase all flash and IFR space
 *
 * @param[in]  config: config the action when the command is executing
 *
 * @note       if config->callBack is not NULL, it has to point to a function 
 *             that is not in the flash memory 
 *
 * @return     - SUCC -- successful
 *             - ERR -- some error
 *             - BUSY -- flash is executing last command. It can not execute this  
 *                       new command now. 
 *
 */
ResultStatus_t FLASH_EraseAll(const FLASH_CmdConfig_t *config);

/**
 * @brief      Erase a Dflash sector
 *
 * @param[in]  addr: DFlash sector start address. It shall be aligned to 8K bytes.
 *                   The range should be within Dflash memory.
 * @param[in]  config: config the action when the command is executing
 *
 * @note       if config->callBack is not NULL, it has to point to a function 
 *             that is not in the flash memory that flash commands is executing
 *             in.
 *
 * @return     - SUCC -- successful.
 *             - ERR -- invalid input address, or command execution error or timeout.
 *             - BUSY -- flash is executing last command. It can not execute this  
 *                       new command now.  
 *
 */
ResultStatus_t FLASH_EraseDflashSector(uint32_t addr, const FLASH_CmdConfig_t *config);

/**
 * @brief      Erase a flash sector
 *
 * @param[in]  addr: sector start address, the range should be within Flash memory.
 * @param[in]  config: config the action when the command is executing
 *
 * @note       if config->callBack is not NULL, it has to point to a function 
 *             that is not in the flash memory that flash commands is executing
 *             in.
 *
 * @return     - SUCC -- successful
 *             - ERR -- some error
 *             - BUSY -- flash is executing last command. It can not execute this  
 *                       new command now.  
 *
 */
ResultStatus_t FLASH_EraseSector(uint32_t addr, const FLASH_CmdConfig_t *config);

/**
 * @brief      Flash enters security mode. In this mode, debug Port is prevented
 *             to read any AHB-AP memory-map addresses
 *
 * @param[in]  debugEraseAllEn: Enable/Disable debug erase-all.
 *                             - ENABLE: debug erase all request is allowed to 
 *                                       erase flash
 *                             - DISABLE: debug erase all request cannot erase flash
 * @param[in]  key: 96-bit backdoor key data stored in Flash0 IFR
 * @param[in]  config: config the action when the command is executing
 *
 * @note       if config->callBack is not NULL, it has to point to a function 
 *             that is not in the flash memory that flash commands is executing
 *             in.
 *
 * @return     - SUCC -- successful
 *             - ERR -- some error
 *             - BUSY -- flash is executing last command. It can not execute this  
 *                       new command now.  
 *
 */
ResultStatus_t FLASH_EnterSecurityMode(ControlState_t debugEraseAllEn, uint8_t key[12],
                                       const FLASH_CmdConfig_t *config);

/**
 * @brief      Set wait state. If the system clock frequency is higher than
 *             flash clock, some wait-states are required to be added to wait
 *             for flash data ready.
 *
 * @param[in]  cycle: number of additional wait-state is added. 
 *                    Its range is 0-15.
 *
 * @return    none
 *
 */ 
void FLASH_SetWaitState(uint8_t cycle);

/**
 * @brief      Get FLASHC status
 *
 * @param[in]  statMask: the status to be get
 *             - FLASH_STATUS_FAIL_MASK: Command Fail
 *             - FLASH_STATUS_CMDABT_MASK: Command Abort
 *             - FLASH_STATUS_ACCERR_MASK: Access Error
 *             - FLASH_STATUS_PREABT_MASK: Write Sequence Abort
 *             - FLASH_STATUS_CCIF_MASK: Command Complete
 *             - FLASH_STATUS_CMDWRF_MASK: Flash command registers written
 *             - FLASH_STATUS_DFDIF_MASK: Multi-bit ECC fault
 *             - FLASH_STATUS_SFDIF_MASK: Single-bit ECC fault
 *             - FLASH_STATUS_DBG_ERSALL_DIS_MASK: Debug Erase All Request Disable
 *             - FLASH_STATUS_FSEC_MASK: Flash secure state
 * @return    the status
 *
 */ 
FlagStatus_t FLASH_GetStatus(uint32_t statMask);

/**
 * @brief      Inject ECC error into FLASH 
 *
 * @param[in]  addr: the address at which Ecc will be injected. It should be 
 *                   16-byte aligned. The range should be within Flash memory.
 * @param[in]  eccBits: It indicates which bits in 9-bit Ecc part will be 
 *                      injected error. Only bit 0-9 in eccBits is
 *                      valid. If one bit is 0, no error is injected into this
 *                      bit; if one bit is 1, this bit will be inverted on 
 *                      reading.
 * @param[in]  dataBits: It indicates which bits in 128-bit data part will be
 *                       injected error. If one bit is 0, no error is injected 
 *                       into this bit; if one bit is 1, this bit will be 
 *                       inverted on reading. It points to an array with 
 *                       4 elements, each element is 32-bit.
 *                       dataBits[0] : data bit 0 - data bit31
 *                       dataBits[1] : data bit 32 - data bit63
 *                       dataBits[2] : data bit 64 - data bit95
 *                       dataBits[3] : data bit 96 - data bit127 
 *
 * @return    none
 *
 */ 
void FLASH_InjectEcc(uint32_t addr, uint32_t eccBits, uint32_t dataBits[4]);
     
/**
 * @brief      Disable ECC error injection into FLASH 
 *
 * @param[in]  none
 *
 * @return    none
 *
 */ 
void FLASH_DisableEccInjection(void);

/**
 * @brief      Get FLASH single-bit ECC error state
 *
 * @param[out]  stat: it points to a struct where the Ecc state will be stored
 *
 * @return    none
 *
 */ 
void FLASH_GetSingleBitEccState(FLASH_EccState_t *state);
     
/**
 * @brief      Get FLASH multi-bit ECC error state
 *
 * @param[out]  stat: it points to a struct where the Ecc state will be stored
 *
 * @return    none
 *
 */ 
void FLASH_GetMultiBitEccState(FLASH_EccState_t *state);

/**
 * @brief      Clear FLASH single-bit ECC error state
 *
 * @param[in]  none
 *
 * @return    none
 *
 */ 
void FLASH_ClearSingleBitEccState(void);

/**
 * @brief      Clear FLASH multi-bit ECC error state
 *
 * @param[in]  none
 *
 * @return    none
 *
 */ 
void FLASH_ClearMultiBitEccState(void);

/**
 * @brief      Query if the key entered is correct. If it is correct, exit 
 *             secure mode
 *
 * @param[in]  key: it points to the 96-bit key to be entered.
 *
 * @return     none
 *
 */
void FLASH_QueryKey(uint8_t key[12]);

/**
 * @brief      Request to abort a command write sequence
 *
 * @param[in]  none
 *
 * @note       none
 *
 * @return - FLASH_ABORT_OK        -- abort flash command succeeded
 *         - FLASH_ABORT_FINISHED  -- abort failed, but flash command has been finished
 *         - FLASH_ABORT_TIMEOUT   -- abort flash command timeout
 *
 */
FLASH_AbortResult_t FLASH_AbortCommand(void);

/**
 * @brief      Mask/Unmask interrupt
 *
 * @param[in]  intType: select interrupt type
 *             - FLASH_INT_CCIF: command complete
 *             - FLASH_INT_DFDIF: Multi-bit ECC fault
 *             - FLASH_INT_SFDIF: single-bit ECC fault
 *             - FLASH_INT_ALL: all interrupt
 * @param[in]  intMask: MASK/UNMASK
 *
 * @return    none
 *
 */
void FLASH_IntMask(FLASH_Int_t intType, IntMask_t intMask);

/**
 * @brief      Clear interrupt
 *
 * @param[in]  intType: select interrupt type
 *             - FLASH_INT_CCIF: command complete
 *             - FLASH_INT_DFDIF: Multi-bit ECC fault
 *             - FLASH_INT_SFDIF: single-bit ECC fault
 *             - FLASH_INT_ALL: all interrupt
 *
 * @return    none
 *
 */ 
void FLASH_IntClear(FLASH_Int_t intType);

/**
 * @brief      Install FLASH callback function
 *
 * @param[in]  intType: select interrupt type
 *             - FLASH_INT_CCIF: command complete
 *             - FLASH_INT_DFDIF: Multi-bit ECC fault
 *             - FLASH_INT_SFDIF: single-bit ECC fault
 * @param[in]  cbFun: indicate callback function
 *
 * @return    none
 *
 */ 
void FLASH_InstallCallBackFunc(FLASH_Int_t intType, isr_cb_t * const cbFun);

/**
 * @brief      flash init
 *
 * @param[in]  none
 *
 * @return     - SUCC -- Initialization succeeded.
 *             - ERR  -- Initialization failed.
 *
 */ 
ResultStatus_t FLASH_Init(void);

/** @} end of group FLASH_Public_FunctionDeclaration */

/** @} end of group FLASH  */

/** @} end of group Z20K14XM_Peripheral_Driver */

typedef volatile struct flash_reg flash_reg_t;
typedef volatile struct flash_reg_w flash_reg_w_t;


typedef volatile struct scm_reg scm_reg_t;
typedef volatile struct scm_reg_w scm_reg_w_t;


uint8_t Flash_EraseNSectors(uint32_t addr,uint32_t sectors)  ;
uint8_t Flash_Write(uint32_t flashAddr, uint32_t len, const uint8_t *dataP);


ResultStatus_t Eep_ProgramPhrase(uint32 flashAddr, const uint8_t *dataP, 
                                   const FLASH_CmdConfig_t *config);




#endif /* FLASH_DRV_H */
