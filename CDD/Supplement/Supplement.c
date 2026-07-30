
/* Inclusion of Platform_Types.h and Compiler.h */
#include "Std_Types.h"
#include "Supplement.h"


//System_Reset()


/**
 * @brief      Reads reset reason value from SRMC module.
 *
 * @param[in]  None
 *
 * @return     uint32: Reset reason value.
 *
 */
/* SWS_Mcu_00006 */
uint32 Srmc_Drv_GetResetReasonValue(void)
{
    uint32 ResetValue;

    ResetValue = Srmc_Drv_SrmcRegWPtr->SRMC_SRS & SRMC_DRV_RESET_CAUSE_MASK;

    if ((uint32)0x00U != ResetValue)
    {
        Srmc_Drv_SrmcRegWPtr->SRMC_SSRS = ResetValue & SRMC_DRV_RESET_CAUSE_MASK;
    }
    else
    {
        /* Do nothing */
    }

    return ResetValue;
}


/**
 * @brief      Gets MCU reset reason.
 *
 * @param[in]  None
 *
 * @return     Mcu_Drvw_ResetType: Reset reason.
 *
 */
Mcu_Drvw_ResetType Mcu_Drvw_GetResetReason(void)
{
    Mcu_Drvw_ResetType ResetReason = MCU_DRVW_POWER_ON_RESET;
    uint8              Index = 0U;
    uint32             Tmp;
    uint8              ReasonNum = 0U;

    if ((uint32)SRMC_DRV_RESET_POR ==
        (Srmc_Drv_GetResetReasonValue() & (uint32)SRMC_DRV_RESET_POR))
    {
        ResetReason = MCU_DRVW_POWER_ON_RESET;
    }
    else
    {
        Tmp = Srmc_Drv_GetResetReasonValue() & (uint32)SRMC_DRV_RESET_ALL;
        for (Index = 0U; Index < 32U; ++Index)
        {
            if (0U != (Tmp & ((uint32)1U << Index)))
            {
                ResetReason = (Mcu_Drvw_ResetType)Index;
                ++ReasonNum;

                /* If there are more than two reset reasons, set reset reason with
                 * MCU_DRVW_MULTIPLE_RESET_REASON */
                if (ReasonNum >= 2U)
                {
                    ResetReason = MCU_DRVW_MULTIPLE_RESET_REASON;
                    break;
                }
            }
        }
    }

    return ResetReason;
}