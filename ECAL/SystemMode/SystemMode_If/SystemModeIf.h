/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      SystemModeIf.h                                                           */
/*   Instance     :                                                                               */
/*   Author       :      Ed                                                                       */
/*   Modify date  :      2025-04-11 11:08:33 AM                                                   */
/*   Description  :                                                                               */
/*                                                                                                */
/*                                                                                                */
/*   Compiler    :       KungFu32 IDE  [Version: V1.0.20.3]                                       */
/*   Hardware    :       ChipOn microcontroller KF32A Family [KF32A136KQT]                        */
/*   Version     :       V1.0                                                                     */
/*                                                                                                */
/*                                                                                                */
/*   All rights reserved. Distribution or duplication without previous written agreement of the   */
/*   owner prohibited.                                                                            */
/*                                                                                                */
/**************************************************************************************************/
#ifndef SYSTEM_MODE_IF_H_
#define SYSTEM_MODE_IF_H_

#include "Device_Regs.h"
#if (defined(DEV_Z20K148M))
    #include "Z20K148M.h"
#elif (defined(DEV_Z20K146M))
    #include "Z20K146M.h"
#elif (defined(DEV_Z20K144M))
    #include "Z20K144M.h"
#else
    #error "No valid CPU defined!"
#endif


/* Mcu IRQn handler reentrant flag type */
struct Mcu_IrqFlagType_Bf
{
    uint32 DMA         : 1;  /* [0]          r/w        */
    uint32 FLASH       : 1;  /* [1]          r/w        */
    uint32 PMU         : 1;  /* [2]          r/w        */
    uint32 EWDT        : 1;  /* [3]          r/w        */
    uint32 SRMC        : 1;  /* [4]          r/w        */
    uint32 I2C         : 1;  /* [5]          r/w        */
    uint32 SPI         : 1;  /* [6]          r/w        */
    uint32 UART        : 1;  /* [7]          r/w        */
    uint32 CAN         : 1;  /* [8]          r/w        */
    uint32 TIM         : 1;  /* [9]          r/w        */
    uint32 TDG         : 1;  /* [10]         r/w        */
    uint32 I2S         : 1;  /* [11]         r/w        */
    uint32 PORT        : 1;  /* [12]         r/w        */
    uint32 STIM        : 1;  /* [13]         r/w        */
    uint32 RTC         : 1;  /* [14]         r/w        */
    uint32 AES         : 1;  /* [15]         r/w        */
    uint32 TRNG        : 1;  /* [16]         r/w        */
    uint32 CMU         : 1;  /* [17]         r/w        */
    uint32 SERU        : 1;  /* [18]         r/w        */
    uint32 SCC         : 1;  /* [19]         r/w        */
    uint32 MCPWM       : 1;  /* [20]         r/w        */
    uint32 ADC         : 1;  /* [21]         r/w        */
    uint32 CMP         : 1;  /* [22]         r/w        */
    uint32 FPU         : 1;  /* [23]         r/w        */
    uint32 CACHE       : 1;  /* [24]         r/w        */
    uint32 RSVD_31_25  : 7;  /* [31:25]      ro         */
};

/**
 * @brief Defines MCU standby interrupt handler type.
 */
typedef volatile struct Mcu_IrqFlagType_Bf Mcu_IrqFlagType;
typedef enum
{
    PORT_ISF_INT_RISING_EDGE = 9U,         /*!< PORT isf interrupt rising  */
    PORT_ISF_INT_FALLING_EDGE = 10U,       /*!< PORT isf interrupt falling */
    PORT_ISF_INT_BOTH_EDGE = 11U,          /*!< PORT isf interrupt both    */
} PORT_IntConfig_t;
typedef void (*Interrupt_Drv_StandbyIrqHandlerType)(void);

/* =========================================================================================================================== */
/* ================                                            RST                                            ================ */
/* =========================================================================================================================== */

/* =========================================================  RESF  ========================================================== */
#define RST_RESF_WDTRF_Pos                (30UL)                     /*!< RST RESF: WDTRF (Bit 30)                               */
#define RST_RESF_WDTRF_Msk                (0x40000000UL)                  /*!< RST RESF: WDTRF (Bitfield-Mask: 0x01)                 */

#define RST_RESF_BOR_Pos                (26UL)                     /*!< RST RESF: LVIRF (Bit 26)                               */
#define RST_RESF_BOR_Msk                (0x04000000UL)                   /*!< RST RESF: LVIRF (Bitfield-Mask: 0x01)                 */

#define RST_RESF_SW_Pos                (25UL)                     /*!< RST RESF: IAWRF (Bit 25)                               */
#define RST_RESF_SW_Msk                (0x02000000UL)                   /*!< RST RESF: IAWRF (Bitfield-Mask: 0x01)                 */

#define RST_RESF_POR_Pos                (24UL)                     /*!< RST RESF: RPERF (Bit 24) */
#define RST_RESF_POR_Msk                (0x01000000UL)                   /*!< RST RESF: RPERF (Bitfield-Mask: 0x01)                 */

#define RST_RESF_NRST_Pos                (23UL)                     /*!< RST RESF: CLMRF (Bit 23) */
#define RST_RESF_NRST_Msk                (0x00800000UL)                   /*!< RST RESF: CLMRF (Bitfield-Mask: 0x01)                 */


typedef enum
{
    RST_BROWN_OUT      			= 1U,               /*当 VDD/VDDA 低于 VBORL值，系统进入复位状态。     */
    RST_SOFTWARE           = 2U,       		/*!< Illegal access memory reset */
    RST_EXT_RESET_PIN            = 3U,               /*!< ram parity check reset */
    RST_WATCH_DOG         				= 4U,               /*!< Watch dog reset */
    RST_POWER_ON					= 5U,               /*!< 当 VDD/VDDA低于 VPDR 值，系统进入复位状态。 */
    RST_SRC_NAME_MAX
} RST_Source_names_t;




#define System_Reset()	Mcu_PerformReset()
extern void SystemMode__Entry_Standby(void);
extern void SystemMode_PMC_Error_Irq_Handler(void);
extern void SystemMode_Wakeup_Init(void);
extern void SystemMode_CheckResetSrc(void);
extern void SystemMode_WakeupIntp_Init(void);
extern void SystemMode_WakeupPinDisable_Config(void);
extern void SystemMode_Interrupt_Init(void);


#endif /* SYSTEM_MODE_IF_H_ */
