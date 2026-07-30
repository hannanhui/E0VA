/*

 *
 *  Created on:支持文件
 *      Author: wu
 */

#ifndef SUPPLEMENT_SUPPLEMENT_H_
#define SUPPLEMENT_SUPPLEMENT_H_

struct Reg_Srmc_W
{
    /* 0x00*/
    uint32 zResverd0x00;
    /* 0x04*/
    uint32 SRMC_PARAM;
    /* 0x08*/
    uint32 SRMC_SRS;
    /* 0x0C*/
    uint32 SRMC_CTRL;
    uint8  zResverd0x010[8]; /*pad 0x010 - 017*/

    /* 0x18*/
    uint32 SRMC_SSRS;
    /* 0x1C*/
    uint32 SRMC_SRIE;
    /* 0x20*/
    uint32 SRMC_PMPORT;
    /* 0x24*/
    uint32 SRMC_PMCTRL;
    /* 0x28*/
    uint32 SRMC_PMSTAT;
    /* 0x2C*/
    uint32 SRMC_DSMWUPC1;
    /* 0x30*/
    uint32 SRMC_DSMWUPC2;
    /* 0x34*/
    uint32 SRMC_DSMWUPS;
}; /*srmc*/
typedef volatile struct Reg_Srmc_W  Reg_Srmc_WType;
/**
 * @brief Type of reset reason.
 */
typedef enum
{
    MCU_DRVW_WAKEUP_RESET = 0U,   /*!< Reset caused by a standby wakeup */
    MCU_DRVW_LVD_RESET = 1U,      /*!< Low Voltage detected Reset */
    MCU_DRVW_LOC_RESET = 2U,      /*!< Loss of External Clock Reset */
    MCU_DRVW_WATCHDOG_RESET = 5U, /*!< Internal WatchDog Timer Reset */
    MCU_DRVW_PIN_RESET = 6U,      /*!< the External RESET Pin Reset */
    MCU_DRVW_POWER_ON_RESET = 7U, /*!< Power On Reset */
    MCU_DRVW_LOCKUP_RESET = 9U,   /*!< ARM Core Indication of a LOCKUP event Reset */
    MCU_DRVW_SW_RESET = 10U,      /*!< Software Reset */
    MCU_DRVW_MDM_AP_RESET =
        11U, /*!< Host Debugger System Setting in the MDM-AP Control Register Reset */
    MCU_DRVW_SERU_COLD_RESET = 12U, /*!< SERU Cold Reset Request Reset */
    MCU_DRVW_SERU_SYS_RESET = 13U,  /*!< SERU System Reset Request Reset */
    MCU_DRVW_SERU_SACKERR = 15U,    /*!< Fail to ACK Attempt to Enter Stop Mode Reset */
    MCU_DRVW_MULTIPLE_RESET_REASON =
        0x55U, /**< More than one reset events are logged except "Power on event" */
    MCU_DRVW_RESET_UNDEFINED = 0xFFU /*!< Reset is undefined */
} Mcu_Drvw_ResetType;


/* SRMC RESET by Power-on Detection Logic */
#define SRMC_DRV_RESET_POR 0x00000080U

#define SRMC_DRV_RESET_ALL  0x0000BEE7U


/* SRMC Reset Cause Mask define */
#define SRMC_DRV_RESET_CAUSE_MASK ((uint32)0x0000BEE7U)

#define PERIPHERAL_BASE_ADDR ((uint32)0x40000000U) /*!< Peripheral area base address */
#define SRMC_BASE_ADDR    (PERIPHERAL_BASE_ADDR + 0x7E000UL) /*!< SRMC base address */
static Reg_Srmc_WType *const  Srmc_Drv_SrmcRegWPtr = (Reg_Srmc_WType *)SRMC_BASE_ADDR;

uint32 Srmc_Drv_GetResetReasonValue(void);
Mcu_Drvw_ResetType Mcu_Drvw_GetResetReason(void);
#endif /* TIMER_TIMER_H_ */
