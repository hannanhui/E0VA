/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      SystemModeIf.h                                                           */
/*   Instance     :                                                                               */
/*   Author       :      Ed                                                                       */
/*   Modify date  :      2025-12-22 14:00:05 PM                                                   */
/*   Description  :                                                                               */
/*                                                                                                */
/*                                                                                                */
/*   Compiler    :       KungFu32 IDE  [Version: V1.0.20.3]                                       */
/*   Hardware    :       ChipOn microcontroller KF32A Family [KF32A156MQV]                        */
/*   Version     :       V1.0                                                                     */
/*                                                                                                */
/*                                                                                                */
/*   All rights reserved. Distribution or duplication without previous written agreement of the   */
/*   owner prohibited.                                                                            */
/*                                                                                                */
/**************************************************************************************************/
#ifndef SYSTEM_MODE_IF_H_
#define SYSTEM_MODE_IF_H_

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

#if EXTERN_WAKEUP_KEY_EN
extern void intp10_interrupt(void);
#endif
#if EXTERN_WAKEUP_LIN_EN
extern void intp0_interrupt(void);
#endif
#if EXTERN_WAKEUP_IGN_EN
extern void intp3_interrupt(void);
#endif


#define System_Reset()	COMMON_SystemReset()
extern void SystemMode__Entry_Standby(void);
extern void SystemMode_PMC_Error_Irq_Handler(void);
extern void SystemMode_Wakeup_Init(void);
extern void SystemMode_CheckResetSrc(void);
extern void SystemMode_WakeupIntp_Init(void);
extern void SystemMode_WakeupPinDisable_Config(void);


#endif /* SYSTEM_MODE_IF_H_ */
