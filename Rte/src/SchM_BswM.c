/** 
 *  @file     SchM_BswM.c
 *  @brief    {@todo add brief here}
 *  @details  {@todo add details here}
 *  @version  1.0.1
 *
 *  @par information
 *  |          Module          |            Version           |
 *  |--------------------------|------------------------------|
 *  |           MCU            |            S32K148           |
 *  |     AUTOSAR Version      |             4.2.2            |
 *  |      Model Information   |   {@todo add model information here}     |
 *  |   Hardware Dependencies  |   {@todo add hardware information here}  |
 *
 *  @addtogroup {@todo add model information here}
 *  @{
 */
/****************************************************************************************************
 *  Sword AUTOSAR MCAL                                                                              *
 *  Copyright(C) 2022 ZhongKeAngHui Inc                                                             *
 *  All Rights Reserved.                                                                            *
 *                                                                                                  *
 *  This file is part of SWORD-AUTOSAR.                                                             *
 ****************************************************************************************************/
#if defined(__cplusplus)
extern "C" 
{
#endif /* defined(__cplusplus) */

/****************************************************************************************************/
/*                                          INCLUDE FILES                                           */
/****************************************************************************************************/

#include "SchM_BswM.h"
#include "McalLib.h"

/****************************************************************************************************/
/*                                  SOURCE FILE VERSION INFORMATION                                 */
/****************************************************************************************************/

/****************************************************************************************************/
/*                                        FILE VERSION CHECKS                                       */
/****************************************************************************************************/

/****************************************************************************************************/
/*                                   EXTERNAL FUNCTION DECLARATIONS                                 */
/****************************************************************************************************/

/****************************************************************************************************/
/*                                  EXTERNAL CONSTANTS DECLARATIONS                                 */
/****************************************************************************************************/

/****************************************************************************************************/
/*                                  EXTERNAL VARIABLES DECLARATIONS                                 */
/****************************************************************************************************/

/****************************************************************************************************/
/*                                          GLOBAL CONSTANTS                                        */
/****************************************************************************************************/

/****************************************************************************************************/
/*                                          GLOBAL VARIABLES                                        */
/****************************************************************************************************/

/****************************************************************************************************/
/*                                          LOCAL TYPEDEFS                                          */
/****************************************************************************************************/

/****************************************************************************************************/
/*                                           LOCAL MACROS                                           */
/****************************************************************************************************/

#define ISR_ON(msr)    (uint32)(((uint32)(msr) & (uint32)(ISR_STATE_MASK)) == (uint32)0)
#define ISR_STATE_MASK ((uint32)0x00000001UL)   /**< @brief PRIMASK bit 0 */

/****************************************************************************************************/
/*                                          LOCAL CONSTANTS                                         */
/****************************************************************************************************/

/****************************************************************************************************/
/*                                          LOCAL VARIABLES                                         */
/****************************************************************************************************/

static uint32 msr_00;
static uint32 msr_01;
static uint32 msr_02;
static uint32 msr_03;
static uint32 msr_04;
static uint32 msr_05;
static uint32 msr_06;
static uint32 msr_07;
static uint32 msr_08;
static uint32 msr_09;
static uint32 msr_10;
static uint32 msr_11;
static uint32 msr_12;
static uint32 msr_13;
static uint32 msr_14;
static uint32 msr_15;
static uint32 msr_16;
static uint32 msr_17;
static uint32 msr_18;
static uint32 msr_19;
static uint32 msr_20;
static uint32 msr_21;
static uint32 msr_22;
static uint32 msr_23;
static uint32 msr_24;
static uint32 msr_25;
static uint32 msr_26;
static uint32 msr_27;
static uint32 msr_28;
static uint32 msr_29;
static uint32 msr_30;
static volatile uint32 reentry_guard_00 = 0;
static volatile uint32 reentry_guard_01 = 0;
static volatile uint32 reentry_guard_02 = 0;
static volatile uint32 reentry_guard_03 = 0;
static volatile uint32 reentry_guard_04 = 0;
static volatile uint32 reentry_guard_05 = 0;
static volatile uint32 reentry_guard_06 = 0;
static volatile uint32 reentry_guard_07 = 0;
static volatile uint32 reentry_guard_08 = 0;
static volatile uint32 reentry_guard_09 = 0;
static volatile uint32 reentry_guard_10 = 0;
static volatile uint32 reentry_guard_11 = 0;
static volatile uint32 reentry_guard_12 = 0;
static volatile uint32 reentry_guard_13 = 0;
static volatile uint32 reentry_guard_14 = 0;
static volatile uint32 reentry_guard_15 = 0;
static volatile uint32 reentry_guard_16 = 0;
static volatile uint32 reentry_guard_17 = 0;
static volatile uint32 reentry_guard_18 = 0;
static volatile uint32 reentry_guard_19 = 0;
static volatile uint32 reentry_guard_20 = 0;
static volatile uint32 reentry_guard_21 = 0;
static volatile uint32 reentry_guard_22 = 0;
static volatile uint32 reentry_guard_23 = 0;
static volatile uint32 reentry_guard_24 = 0;
static volatile uint32 reentry_guard_25 = 0;
static volatile uint32 reentry_guard_26 = 0;
static volatile uint32 reentry_guard_27 = 0;
static volatile uint32 reentry_guard_28 = 0;
static volatile uint32 reentry_guard_29 = 0;
static volatile uint32 reentry_guard_30 = 0;

/****************************************************************************************************/
/*                                      LOCAL FUNCTION PROTOTYPES                                   */
/****************************************************************************************************/

FUNC(uint32, RTE_CODE) BswM_schm_read_msr(void);

/****************************************************************************************************/
/*                                          GLOBAL FUNCTIONS                                        */
/****************************************************************************************************/

void SchM_Enter_BswM_EXCLUSIVE_AREA_00(void)
{
    if(0UL == reentry_guard_00)
    {
       msr_00 = BswM_schm_read_msr();
       if (ISR_ON(msr_00))
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
         ASM_KEYWORD(" nop ");
#endif
      }
    }
    reentry_guard_00++;
}
void SchM_Enter_BswM_EXCLUSIVE_AREA_01(void)
{
    if(0UL == reentry_guard_01)
    {
       msr_01 = BswM_schm_read_msr();
       if (ISR_ON(msr_01))
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
         ASM_KEYWORD(" nop ");
#endif
      }
    }
    reentry_guard_01++;
}
void SchM_Enter_BswM_EXCLUSIVE_AREA_02(void)
{
    if(0UL == reentry_guard_02)
    {
       msr_02 = BswM_schm_read_msr();
       if (ISR_ON(msr_02))
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
         ASM_KEYWORD(" nop ");
#endif
      }
    }
    reentry_guard_02++;
}
void SchM_Enter_BswM_EXCLUSIVE_AREA_03(void)
{
    if(0UL == reentry_guard_03)
    {
       msr_03 = BswM_schm_read_msr();
       if (ISR_ON(msr_03))
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
         ASM_KEYWORD(" nop ");
#endif
      }
    }
    reentry_guard_03++;
}
void SchM_Enter_BswM_EXCLUSIVE_AREA_04(void)
{
    if(0UL == reentry_guard_04)
    {
       msr_04 = BswM_schm_read_msr();
       if (ISR_ON(msr_04))
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
         ASM_KEYWORD(" nop ");
#endif
      }
    }
    reentry_guard_04++;
}
void SchM_Enter_BswM_EXCLUSIVE_AREA_05(void)
{
    if(0UL == reentry_guard_05)
    {
       msr_05 = BswM_schm_read_msr();
       if (ISR_ON(msr_05))
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
         ASM_KEYWORD(" nop ");
#endif
      }
    }
    reentry_guard_05++;
}
void SchM_Enter_BswM_EXCLUSIVE_AREA_06(void)
{
    if(0UL == reentry_guard_06)
    {
       msr_06 = BswM_schm_read_msr();
       if (ISR_ON(msr_06))
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
         ASM_KEYWORD(" nop ");
#endif
      }
    }
    reentry_guard_06++;
}
void SchM_Enter_BswM_EXCLUSIVE_AREA_07(void)
{
    if(0UL == reentry_guard_07)
    {
       msr_07 = BswM_schm_read_msr();
       if (ISR_ON(msr_07))
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
         ASM_KEYWORD(" nop ");
#endif
      }
    }
    reentry_guard_07++;
}
void SchM_Enter_BswM_EXCLUSIVE_AREA_08(void)
{
    if(0UL == reentry_guard_08)
    {
       msr_08 = BswM_schm_read_msr();
       if (ISR_ON(msr_08))
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
         ASM_KEYWORD(" nop ");
#endif
      }
    }
    reentry_guard_08++;
}
void SchM_Enter_BswM_EXCLUSIVE_AREA_09(void)
{
    if(0UL == reentry_guard_09)
    {
       msr_09 = BswM_schm_read_msr();
       if (ISR_ON(msr_09))
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
         ASM_KEYWORD(" nop ");
#endif
      }
    }
    reentry_guard_09++;
}
void SchM_Enter_BswM_EXCLUSIVE_AREA_10(void)
{
    if(0UL == reentry_guard_10)
    {
       msr_10 = BswM_schm_read_msr();
       if (ISR_ON(msr_10))
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
         ASM_KEYWORD(" nop ");
#endif
      }
    }
    reentry_guard_10++;
}
void SchM_Enter_BswM_EXCLUSIVE_AREA_11(void)
{
    if(0UL == reentry_guard_11)
    {
       msr_11 = BswM_schm_read_msr();
       if (ISR_ON(msr_11))
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
         ASM_KEYWORD(" nop ");
#endif
      }
    }
    reentry_guard_11++;
}
void SchM_Enter_BswM_EXCLUSIVE_AREA_12(void)
{
    if(0UL == reentry_guard_12)
    {
       msr_12 = BswM_schm_read_msr();
       if (ISR_ON(msr_12))
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
         ASM_KEYWORD(" nop ");
#endif
      }
    }
    reentry_guard_12++;
}
void SchM_Enter_BswM_EXCLUSIVE_AREA_13(void)
{
    if(0UL == reentry_guard_13)
    {
       msr_13 = BswM_schm_read_msr();
       if (ISR_ON(msr_13))
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
         ASM_KEYWORD(" nop ");
#endif
      }
    }
    reentry_guard_13++;
}
void SchM_Enter_BswM_EXCLUSIVE_AREA_14(void)
{
    if(0UL == reentry_guard_14)
    {
       msr_14 = BswM_schm_read_msr();
       if (ISR_ON(msr_14))
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
         ASM_KEYWORD(" nop ");
#endif
      }
    }
    reentry_guard_14++;
}
void SchM_Enter_BswM_EXCLUSIVE_AREA_15(void)
{
    if(0UL == reentry_guard_15)
    {
       msr_15 = BswM_schm_read_msr();
       if (ISR_ON(msr_15))
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
         ASM_KEYWORD(" nop ");
#endif
      }
    }
    reentry_guard_15++;
}
void SchM_Enter_BswM_EXCLUSIVE_AREA_16(void)
{
    if(0UL == reentry_guard_16)
    {
       msr_16 = BswM_schm_read_msr();
       if (ISR_ON(msr_16))
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
         ASM_KEYWORD(" nop ");
#endif
      }
    }
    reentry_guard_16++;
}
void SchM_Enter_BswM_EXCLUSIVE_AREA_17(void)
{
    if(0UL == reentry_guard_17)
    {
       msr_17 = BswM_schm_read_msr();
       if (ISR_ON(msr_17))
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
         ASM_KEYWORD(" nop ");
#endif
      }
    }
    reentry_guard_17++;
}
void SchM_Enter_BswM_EXCLUSIVE_AREA_18(void)
{
    if(0UL == reentry_guard_18)
    {
       msr_18 = BswM_schm_read_msr();
       if (ISR_ON(msr_18))
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
         ASM_KEYWORD(" nop ");
#endif
      }
    }
    reentry_guard_18++;
}
void SchM_Enter_BswM_EXCLUSIVE_AREA_19(void)
{
    if(0UL == reentry_guard_19)
    {
       msr_19 = BswM_schm_read_msr();
       if (ISR_ON(msr_19))
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
         ASM_KEYWORD(" nop ");
#endif
      }
    }
    reentry_guard_19++;
}
void SchM_Enter_BswM_EXCLUSIVE_AREA_20(void)
{
    if(0UL == reentry_guard_20)
    {
       msr_20 = BswM_schm_read_msr();
       if (ISR_ON(msr_20))
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
         ASM_KEYWORD(" nop ");
#endif
      }
    }
    reentry_guard_20++;
}
void SchM_Enter_BswM_EXCLUSIVE_AREA_21(void)
{
    if(0UL == reentry_guard_21)
    {
       msr_21 = BswM_schm_read_msr();
       if (ISR_ON(msr_21))
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
         ASM_KEYWORD(" nop ");
#endif
      }
    }
    reentry_guard_21++;
}
void SchM_Enter_BswM_EXCLUSIVE_AREA_22(void)
{
    if(0UL == reentry_guard_22)
    {
       msr_22 = BswM_schm_read_msr();
       if (ISR_ON(msr_22))
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
         ASM_KEYWORD(" nop ");
#endif
      }
    }
    reentry_guard_22++;
}
void SchM_Enter_BswM_EXCLUSIVE_AREA_23(void)
{
    if(0UL == reentry_guard_23)
    {
       msr_23 = BswM_schm_read_msr();
       if (ISR_ON(msr_23))
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
         ASM_KEYWORD(" nop ");
#endif
      }
    }
    reentry_guard_23++;
}
void SchM_Enter_BswM_EXCLUSIVE_AREA_24(void)
{
    if(0UL == reentry_guard_24)
    {
       msr_24 = BswM_schm_read_msr();
       if (ISR_ON(msr_24))
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
         ASM_KEYWORD(" nop ");
#endif
      }
    }
    reentry_guard_24++;
}
void SchM_Enter_BswM_EXCLUSIVE_AREA_25(void)
{
    if(0UL == reentry_guard_25)
    {
       msr_25 = BswM_schm_read_msr();
       if (ISR_ON(msr_25))
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
         ASM_KEYWORD(" nop ");
#endif
      }
    }
    reentry_guard_25++;
}
void SchM_Enter_BswM_EXCLUSIVE_AREA_26(void)
{
    if(0UL == reentry_guard_26)
    {
       msr_26 = BswM_schm_read_msr();
       if (ISR_ON(msr_26))
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
         ASM_KEYWORD(" nop ");
#endif
      }
    }
    reentry_guard_26++;
}
void SchM_Enter_BswM_EXCLUSIVE_AREA_27(void)
{
    if(0UL == reentry_guard_27)
    {
       msr_27 = BswM_schm_read_msr();
       if (ISR_ON(msr_27))
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
         ASM_KEYWORD(" nop ");
#endif
      }
    }
    reentry_guard_27++;
}
void SchM_Enter_BswM_EXCLUSIVE_AREA_28(void)
{
    if(0UL == reentry_guard_28)
    {
       msr_28 = BswM_schm_read_msr();
       if (ISR_ON(msr_28))
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
         ASM_KEYWORD(" nop ");
#endif
      }
    }
    reentry_guard_28++;
}
void SchM_Enter_BswM_EXCLUSIVE_AREA_29(void)
{
    if(0UL == reentry_guard_29)
    {
       msr_29 = BswM_schm_read_msr();
       if (ISR_ON(msr_29))
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
         ASM_KEYWORD(" nop ");
#endif
      }
    }
    reentry_guard_29++;
}
void SchM_Enter_BswM_EXCLUSIVE_AREA_30(void)
{
    if(0UL == reentry_guard_30)
    {
       msr_30 = BswM_schm_read_msr();
       if (ISR_ON(msr_30))
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
         ASM_KEYWORD(" nop ");
#endif
      }
    }
    reentry_guard_30++;
}


/**
 * @brief   This function is called to allow FEE to exit the specific critical region.
 * @details This is a local function stub only. It will resume interrupts if no other
 *          critical area is still executing.
 *
 * @param[in]     void     No input parameters
 * @return        void     This function does not return anything
 *
 * @pre  None
 * @post None
 *
 */
void SchM_Exit_BswM_EXCLUSIVE_AREA_00(void)
{
    reentry_guard_00--;
    if ((ISR_ON(msr_00))&&(0UL == reentry_guard_00))
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
      ASM_KEYWORD(" nop ");
#endif
    }
}
void SchM_Exit_BswM_EXCLUSIVE_AREA_01(void)
{
    reentry_guard_01--;
    if ((ISR_ON(msr_01))&&(0UL == reentry_guard_01))
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
      ASM_KEYWORD(" nop ");
#endif
    }
}
void SchM_Exit_BswM_EXCLUSIVE_AREA_02(void)
{
    reentry_guard_02--;
    if ((ISR_ON(msr_02))&&(0UL == reentry_guard_02))
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
      ASM_KEYWORD(" nop ");
#endif
    }
}
void SchM_Exit_BswM_EXCLUSIVE_AREA_03(void)
{
    reentry_guard_03--;
    if ((ISR_ON(msr_03))&&(0UL == reentry_guard_03))
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
      ASM_KEYWORD(" nop ");
#endif
    }
}
void SchM_Exit_BswM_EXCLUSIVE_AREA_04(void)
{
    reentry_guard_04--;
    if ((ISR_ON(msr_04))&&(0UL == reentry_guard_04))
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
      ASM_KEYWORD(" nop ");
#endif
    }
}
void SchM_Exit_BswM_EXCLUSIVE_AREA_05(void)
{
    reentry_guard_05--;
    if ((ISR_ON(msr_05))&&(0UL == reentry_guard_05))
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
      ASM_KEYWORD(" nop ");
#endif
    }
}
void SchM_Exit_BswM_EXCLUSIVE_AREA_06(void)
{
    reentry_guard_06--;
    if ((ISR_ON(msr_06))&&(0UL == reentry_guard_06))
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
      ASM_KEYWORD(" nop ");
#endif
    }
}
void SchM_Exit_BswM_EXCLUSIVE_AREA_07(void)
{
    reentry_guard_07--;
    if ((ISR_ON(msr_07))&&(0UL == reentry_guard_07))
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
      ASM_KEYWORD(" nop ");
#endif
    }
}
void SchM_Exit_BswM_EXCLUSIVE_AREA_08(void)
{
    reentry_guard_08--;
    if ((ISR_ON(msr_08))&&(0UL == reentry_guard_08))
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
      ASM_KEYWORD(" nop ");
#endif
    }
}
void SchM_Exit_BswM_EXCLUSIVE_AREA_09(void)
{
    reentry_guard_09--;
    if ((ISR_ON(msr_09))&&(0UL == reentry_guard_09))
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
      ASM_KEYWORD(" nop ");
#endif
    }
}
void SchM_Exit_BswM_EXCLUSIVE_AREA_10(void)
{
    reentry_guard_10--;
    if ((ISR_ON(msr_10))&&(0UL == reentry_guard_10))
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
      ASM_KEYWORD(" nop ");
#endif
    }
}
void SchM_Exit_BswM_EXCLUSIVE_AREA_11(void)
{
    reentry_guard_11--;
    if ((ISR_ON(msr_11))&&(0UL == reentry_guard_11))
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
      ASM_KEYWORD(" nop ");
#endif
    }
}
void SchM_Exit_BswM_EXCLUSIVE_AREA_12(void)
{
    reentry_guard_12--;
    if ((ISR_ON(msr_12))&&(0UL == reentry_guard_12))
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
      ASM_KEYWORD(" nop ");
#endif
    }
}
void SchM_Exit_BswM_EXCLUSIVE_AREA_13(void)
{
    reentry_guard_13--;
    if ((ISR_ON(msr_13))&&(0UL == reentry_guard_13))
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
      ASM_KEYWORD(" nop ");
#endif
    }
}
void SchM_Exit_BswM_EXCLUSIVE_AREA_14(void)
{
    reentry_guard_14--;
    if ((ISR_ON(msr_14))&&(0UL == reentry_guard_14))
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
      ASM_KEYWORD(" nop ");
#endif
    }
}
void SchM_Exit_BswM_EXCLUSIVE_AREA_15(void)
{
    reentry_guard_15--;
    if ((ISR_ON(msr_15))&&(0UL == reentry_guard_15))
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
      ASM_KEYWORD(" nop ");
#endif
    }
}
void SchM_Exit_BswM_EXCLUSIVE_AREA_16(void)
{
    reentry_guard_16--;
    if ((ISR_ON(msr_16))&&(0UL == reentry_guard_16))
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
      ASM_KEYWORD(" nop ");
#endif
    }
}
void SchM_Exit_BswM_EXCLUSIVE_AREA_17(void)
{
    reentry_guard_17--;
    if ((ISR_ON(msr_17))&&(0UL == reentry_guard_17))
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
      ASM_KEYWORD(" nop ");
#endif
    }
}
void SchM_Exit_BswM_EXCLUSIVE_AREA_18(void)
{
    reentry_guard_18--;
    if ((ISR_ON(msr_18))&&(0UL == reentry_guard_18))
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
      ASM_KEYWORD(" nop ");
#endif
    }
}
void SchM_Exit_BswM_EXCLUSIVE_AREA_19(void)
{
    reentry_guard_19--;
    if ((ISR_ON(msr_19))&&(0UL == reentry_guard_19))
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
      ASM_KEYWORD(" nop ");
#endif
    }
}
void SchM_Exit_BswM_EXCLUSIVE_AREA_20(void)
{
    reentry_guard_20--;
    if ((ISR_ON(msr_20))&&(0UL == reentry_guard_20))
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
      ASM_KEYWORD(" nop ");
#endif
    }
}
void SchM_Exit_BswM_EXCLUSIVE_AREA_21(void)
{
    reentry_guard_21--;
    if ((ISR_ON(msr_21))&&(0UL == reentry_guard_21))
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
      ASM_KEYWORD(" nop ");
#endif
    }
}
void SchM_Exit_BswM_EXCLUSIVE_AREA_22(void)
{
    reentry_guard_22--;
    if ((ISR_ON(msr_22))&&(0UL == reentry_guard_22))
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
      ASM_KEYWORD(" nop ");
#endif
    }
}
void SchM_Exit_BswM_EXCLUSIVE_AREA_23(void)
{
    reentry_guard_23--;
    if ((ISR_ON(msr_23))&&(0UL == reentry_guard_23))
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
      ASM_KEYWORD(" nop ");
#endif
    }
}
void SchM_Exit_BswM_EXCLUSIVE_AREA_24(void)
{
    reentry_guard_24--;
    if ((ISR_ON(msr_24))&&(0UL == reentry_guard_24))
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
      ASM_KEYWORD(" nop ");
#endif
    }
}
void SchM_Exit_BswM_EXCLUSIVE_AREA_25(void)
{
    reentry_guard_25--;
    if ((ISR_ON(msr_25))&&(0UL == reentry_guard_25))
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
      ASM_KEYWORD(" nop ");
#endif
    }
}
void SchM_Exit_BswM_EXCLUSIVE_AREA_26(void)
{
    reentry_guard_26--;
    if ((ISR_ON(msr_26))&&(0UL == reentry_guard_26))
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
      ASM_KEYWORD(" nop ");
#endif
    }
}
void SchM_Exit_BswM_EXCLUSIVE_AREA_27(void)
{
    reentry_guard_27--;
    if ((ISR_ON(msr_27))&&(0UL == reentry_guard_27))
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
      ASM_KEYWORD(" nop ");
#endif
    }
}
void SchM_Exit_BswM_EXCLUSIVE_AREA_28(void)
{
    reentry_guard_28--;
    if ((ISR_ON(msr_28))&&(0UL == reentry_guard_28))
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
      ASM_KEYWORD(" nop ");
#endif
    }
}
void SchM_Exit_BswM_EXCLUSIVE_AREA_29(void)
{
    reentry_guard_29--;
    if ((ISR_ON(msr_29))&&(0UL == reentry_guard_29))
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
      ASM_KEYWORD(" nop ");
#endif
    }
}
void SchM_Exit_BswM_EXCLUSIVE_AREA_30(void)
{
    reentry_guard_30--;
    if ((ISR_ON(msr_30))&&(0UL == reentry_guard_30))
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_CCFC2007PT_
      ASM_KEYWORD(" nop ");
#endif
    }
}


/****************************************************************************************************/
/*                                         CALLBACK FUNCTIONS                                       */
/****************************************************************************************************/

/****************************************************************************************************/
/*                                           LOCAL FUNCTIONS                                        */
/****************************************************************************************************/

/**
 * @brief        This function returns the MSR register value (32 bits).
 * @return       The MSR register value (32 bits).
 */
FUNC(uint32, RTE_CODE) BswM_schm_read_msr(void)
{
    register uint32 reg_tmp;
    __asm volatile( " mrs %0, primask " : "=r" (reg_tmp) );
    return (uint32)reg_tmp;
}

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */
/** @} */
