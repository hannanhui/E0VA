/**************************************************************************************************/
/**
 * @file     stim_drv.c
 * @brief    STIM module driver file.
 * @version  V1.1.1
 * @date     December-2022
 * @author   Zhixin Semiconductor
 *
 * @note
 * Copyright (C) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 *
 **************************************************************************************************/

#include "stim_drv.h"

/** @addtogroup  Z20K14XM_Peripheral_Driver
 *  @{
 */

/** @defgroup STIM
 *  @brief STIM driver modules
 *  @{
 */

/** @defgroup STIM_Private_Defines
 *  @{
 */
#define STIM_SC_CLKS_MASK                   (0x00008003U)
#define STIM_SC_PSDIV_MASK                  (0x0000803CU)
#define STIM_SC_PSEN_MASK                   (0x00008040U)
#define STIM_SC_MODE_MASK                   (0x00008400U)
#define STIM_SC_RSTDIS_MASK                 (0x00008800U)
#define STIM_SC_FREE_COUNT_CONFIG_MASK      (0x00008C7FU)
#define STIM_SC_PSRC_POL_MASK               (0x00008380U)
#define STIM_SC_DMAE_MASK                   (0x00009000U)
#define STIM_SC_IE_MASK                     (0x0000A000U)
#define STIM_SC_EN_MASK                     (0x0000C000U)
#define STIM_SC_FLAG_MASK                   (0x00008000U)

#define STIM_SC_PSDIV_SHIFT                 (2U)
#define STIM_SC_PSEN_SHIFT                  (6U)
#define STIM_SC_POL_SHIFT                   (7U)
#define STIM_SC_PSRC_SHIFT                  (8U)
#define STIM_SC_MODE_SHIFT                  (10U)
#define STIM_SC_RSTDIS_SHIFT                (11U)
#define STIM_SC_DMAE_SHIFT                  (12U)
#define STIM_SC_IE_SHIFT                    (13U)
#define STIM_SC_EN_SHIFT                    (14U)
#define STIM_SC_FLAG_SHIFT                  (15U)

/** @} end of group STIM_Private_Defines */

/** @defgroup STIM_Private_Variables
 *  @{
 */
/*PRQA S 0303 ++*/
static stim_reg_t *const stimRegPtr = (stim_reg_t *) STIM_BASE_ADDR;
static stim_reg_w_t *const stimRegWPtr = (stim_reg_w_t *) STIM_BASE_ADDR;
/*PRQA S 0303 --*/

/**
 *  @brief STIM ISR callback function pointer array
 */
static isr_cb_t * stimIsrCb[STIM_NUM_ALL][STIM_INT_ALL]= 
{
    {NULL},
    {NULL},
    {NULL},
    {NULL}
};
/** @} end of group STIM_Private_Variables */

/** @defgroup STIM_Global_Variables
 *  @{
 */

/** @} end of group STIM_Global_Variables */

/** @defgroup STIM_Private_FunctionDeclaration
 *  @{
 */
/* local functions */
static void STIM_IntHandler(void);
void STIM_DriverIRQHandler(void);

/** @} end of group STIM_Private_FunctionDeclaration */

/** @defgroup STIM_Private_Function
 *  @{
 */
/**
 * @brief  STIM interrupt handle
 *
 * @return none
 *
 */
static void STIM_IntHandler(void)
{
    uint32_t i;
    uint32_t intStatus;

    for(i = 0U; i < (uint32_t)STIM_NUM_ALL; i++)
    {
        /* Read the interrupt status */
        intStatus = stimRegPtr->STIM_SCn[i].FLAG;
        /* only check enabled interrupt */
        intStatus = intStatus & stimRegPtr->STIM_SCn[i].IE;
        /* clear the interrupt */
        stimRegPtr->STIM_SCn[i].FLAG = intStatus;
        
        if(intStatus != 0U)
        {
            if(stimIsrCb[i][STIM_INT]!= NULL)
            {
                stimIsrCb[i][STIM_INT]();
            }
            /* Disable the interrupt */
            else
            {
                stimRegWPtr->STIM_SCn[i] = ((stimRegWPtr->STIM_SCn[i]) & (~STIM_SC_IE_MASK));
            }
        }
    }

    COMMON_DSB();
}

/**
 * @brief      STIM interrupt function
 *
 * @param      none
 *
 * @return     none
 *
 * @note       The specific interrupt will be disabled if the corresponding interrupt callback is 
 *             not installed and an interrupt is raised. The rationale is focusing on the processing 
 *             efficiency mostly for the case that user might enable interrupts without processing 
 *             logic, in this case the CPU might also react to the interrupt.
 *             For the low power mode, especially for the wakeup source in the way of interrupt for 
 *             STOP, user must setup the callback.
 */
void STIM_DriverIRQHandler(void)
{
    STIM_IntHandler();
}
/** @} end of group STIM_Private_Function */

/** @defgroup STIM_Public_Functions
 *  @{
 */
/**
 * @brief      Install call back function
 *
 * @param[in]  stimNo: Select the stim number,should be STIM_0,STIM_1,STIM_2, STIM_3.
 *                     The parameter STIM_NUM_ALL should not be passed to this function.
 * @param[in]  intType: Select the interrupt, should be STIM_INT. 
 *                      The parameter STIM_INT_ALL should not be passed to this function.
 * @param[in]  cbFun: pointer to callback function.
 *
 * @return     none
 *
 */
void STIM_InstallCallBackFunc(STIM_No_t stimNo, STIM_Int_t intType,
                               isr_cb_t * cbFun)
{
    if((STIM_INT_ALL > intType) && (STIM_NUM_ALL > stimNo))
    {
        stimIsrCb[stimNo][intType] = cbFun;
    }
}

/**
 * @brief      Initialize STIM configuration
 *
 * @param[in]  stimNo: Select the stim number,should be STIM_0,STIM_1,STIM_2, STIM_3.
 *                     The parameter STIM_NUM_ALL should not be passed to this function.
 * @param[in]  stimConfigStruct: Stim configuration struct.
 *
 * @return     none
 *
 */
void STIM_Init(STIM_No_t stimNo, const STIM_Config_t* stimConfigStruct)
{
    uint32_t stimSc;
    
    if((STIM_NUM_ALL > stimNo) && (NULL != stimConfigStruct))
    {
        if(STIM_PULSE_COUNT == stimConfigStruct->workMode)
        {
            stimSc = stimRegWPtr->STIM_SCn[stimNo];
            stimSc &= (~STIM_SC_PSRC_POL_MASK);
            stimSc |= ((((uint32_t)stimConfigStruct->pinSource) << STIM_SC_PSRC_SHIFT) | 
                      (((uint32_t)stimConfigStruct->pinPolarity) << STIM_SC_POL_SHIFT));
            stimRegWPtr->STIM_SCn[stimNo] = stimSc;
        }
        stimRegPtr->STIM_CVn[stimNo].CV = 
                                (uint32_t)stimConfigStruct->compareValue;

        stimSc = stimRegWPtr->STIM_SCn[stimNo];
        stimSc &= (~STIM_SC_FREE_COUNT_CONFIG_MASK);
        stimSc |= (((uint32_t)stimConfigStruct->clockSource) | 
                   (((uint32_t)stimConfigStruct->workMode) << STIM_SC_MODE_SHIFT) | 
                   (((uint32_t)stimConfigStruct->countResetMode) << STIM_SC_RSTDIS_SHIFT) | 
                   (((uint32_t)stimConfigStruct->prescalerMode) << STIM_SC_PSEN_SHIFT) | 
                   (((uint32_t)stimConfigStruct->prescalerOrFilterValue) << STIM_SC_PSDIV_SHIFT));
        stimRegWPtr->STIM_SCn[stimNo] = stimSc;
    }
}

/**
 * @brief      Set compare value 
 *
 * @param[in]  stimNo: Select the stim number,should be STIM_0,STIM_1,STIM_2, STIM_3.
 *                     The parameter STIM_NUM_ALL should not be passed to this function.
 * @param[in]  compareValue: Stim compare value.
 *
 * @return     none
 *
 */
void STIM_SetCompareValue(STIM_No_t stimNo, uint32_t compareValue)
{
    if(STIM_NUM_ALL > stimNo)
    {
        /* Set compare value */
        stimRegWPtr->STIM_CVn[stimNo] = (uint32_t)compareValue;
    }
}

/**
 * @brief      Current Value of stim
 *
 * @param[in]  stimNo: Select the stim number,should be STIM_0,STIM_1,STIM_2, STIM_3.
 *                     The parameter STIM_NUM_ALL should not be passed to this function.
 *
 * @return      Value of stim. Because the parameter STIM_NUM_ALL is meaningless, 
 *             when it is passed to this function, 0 will be returned;
 *
 */
uint32_t STIM_GetCurrentCounterValue(STIM_No_t stimNo)
{
    uint32_t counterValue = 0U;

    if(STIM_NUM_ALL > stimNo)
    {
        /* Current Value of STIM */
        counterValue = (uint32_t)stimRegWPtr->STIM_CNTn[stimNo];
    }

    return counterValue;
}

/**
 * @brief      Enable stim
 *
 * @param[in]  stimNo: Select the stim number,should be STIM_0,STIM_1,STIM_2, STIM_3.
 *                     The parameter STIM_NUM_ALL should not be passed to this function.
 *
 * @return     none
 *
 */
void STIM_Enable(STIM_No_t stimNo)
{
    if(STIM_NUM_ALL > stimNo)
    {
        stimRegWPtr->STIM_SCn[stimNo] = (((stimRegWPtr->STIM_SCn[stimNo]) & (~STIM_SC_EN_MASK)) | 
                                         (((uint32_t)1U) << STIM_SC_EN_SHIFT));
    }
}

/**
 * @brief      Disable stim
 *
 * @param[in]  stimNo: Select the stim number,should be STIM_0,STIM_1,STIM_2, STIM_3.
 *                     The parameter STIM_NUM_ALL should not be passed to this function.
 *
 * @return     none
 *
 */
void STIM_Disable(STIM_No_t stimNo)
{
    if(STIM_NUM_ALL > stimNo)
    {
        stimRegWPtr->STIM_SCn[stimNo] = ((stimRegWPtr->STIM_SCn[stimNo]) & (~STIM_SC_EN_MASK));
    }
}

/**
 * @brief       Enable/Disable the stim interrupt
 *
 * @param[in]   stimNo: Select the stim number,should be STIM_0,STIM_1,STIM_2, STIM_3.
 *                      The parameter STIM_NUM_ALL should not be passed to this function.
 * @param[in]   newState: Enable/Disable function state.
 *             - ENABLE: enable interrupt
 *             - DISABLE: disable interrupt
 *
 * @return     none
 *
 */
void STIM_IntCmd(STIM_No_t stimNo, ControlState_t newState)
{
    if(STIM_NUM_ALL > stimNo)
    {
        /* Mask/Unmask the timer interrupt */
        stimRegWPtr->STIM_SCn[stimNo] = (((stimRegWPtr->STIM_SCn[stimNo]) & (~STIM_SC_IE_MASK)) | 
                                         (((uint32_t)newState) << STIM_SC_IE_SHIFT));
    }
}

/**
 * @brief      Enable or disable the STIM DMA function.
 *
 * @param[in]  stimNo: Select the stim number,should be STIM_0,STIM_1,STIM_2, STIM_3.
 *                     The parameter STIM_NUM_ALL should not be passed to this function.
 * @param[in]  newState: Enable/Disable function state.
 *             - ENABLE: enable DMA request
 *             - DISABLE: disable DMA request
 *
 * @return     none
 *
 */
void STIM_DmaCmd(STIM_No_t stimNo, ControlState_t newState)
{
    if(STIM_NUM_ALL > stimNo)
    {
        stimRegWPtr->STIM_SCn[stimNo] = (((stimRegWPtr->STIM_SCn[stimNo]) & (~STIM_SC_DMAE_MASK)) | 
                                         (((uint32_t)newState) << STIM_SC_DMAE_SHIFT));
    }
}

/**
 * @brief      Checks if the status flag is set when the counter matches the
 *             compare value
 *
 * @param[in]  stimNo: Select the stim number,should be STIM_0,STIM_1,STIM_2, STIM_3.
 *                     The parameter STIM_NUM_ALL should not be passed to this function.
 *
 * @return     The status flag.
 *             - SET: The status flag is set.
 *             - RESET: The status flag is not set. Because the parameter STIM_NUM_ALL 
 *                      is meaningless, when it is passed to this function, RESET will be returned.
 *
 */
FlagStatus_t STIM_GetStatus(STIM_No_t stimNo)
{
    FlagStatus_t intBitStatus = RESET;

    if(STIM_NUM_ALL > stimNo)
    {
        intBitStatus = (stimRegPtr->STIM_SCn[stimNo].FLAG != 0U) ? SET : RESET;
    }
    return intBitStatus;
}

/**
 * @brief      Clear the interrupt of stim
 *
 * @param[in]  stimNo: Select the stim number,should be STIM_0,STIM_1,STIM_2, STIM_3.
 *                     The parameter STIM_NUM_ALL should not be passed to this function.
 *
 * @return     none
 *
 */
void STIM_ClearInt(STIM_No_t stimNo)
{
    if(STIM_NUM_ALL > stimNo)
    {
        /* Write 1 to clear interrupt */
        stimRegPtr->STIM_SCn[stimNo].FLAG = 1U;
    }
}

/** @} end of group STIM_Public_Functions */

/** @} end of group STIM */

/** @} end of group Z20K14XM_Peripheral_Driver */
