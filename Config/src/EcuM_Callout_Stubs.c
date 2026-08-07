/**
 *  @file     EcuM_Callout_Stubs.c
 *  @brief    AUTOSAR EcuM  - EcuM driver source file.
 *  @details  EcuM driver source file, containing the C implementation of Autosar API specification
 *            and other variables and functions that are exported by the EcuM driver.
 *  @version  1.2.0
 *
 * @addtogroup  EcuM
 * @{
 */
/*====================================================================================================*
 * AngHui AUTOSAR BSW.
 *
 * Copyright(C) 2026 GuoKeAngHui Inc.
 *
 * All rights reserved.
 *
 * This file is part of AngHui AUTOSAR BSW, contains proprietary information.
 * Passing on and copying of this document, and communication of its contents
 * is not permitted without prior written authorization.
 *====================================================================================================*/
#if defined(__cplusplus)
extern "C"
{
#endif /* defined(__cplusplus) */

/*====================================================================================================*
 *                                           INCLUDE FILES                                          
 *====================================================================================================*/
#include "EcuM.h"

#include "BswM.h"
//#include "SchM.h"
#if (STD_ON == ECUM_INCLUDE_DET )
#include"Det.h"
#endif /* (STD_ON == ECUM_INCLUDE_DET) */
 
 

#include"Mcu.h"
 
 
/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION                                 
 *====================================================================================================*/

#define ECUM_CALLOUT_STUBS_VENDOR_ID_C                           0U
#define ECUM_CALLOUT_STUBS_SW_MAJOR_VERSION_C                    1U
#define ECUM_CALLOUT_STUBS_SW_MINOR_VERSION_C                    2U
#define ECUM_CALLOUT_STUBS_SW_PATCH_VERSION_C                    0U
#define ECUM_CALLOUT_STUBS_AR_RELEASE_MAJOR_VERSION_C            4U
#define ECUM_CALLOUT_STUBS_AR_RELEASE_MINOR_VERSION_C            2U
#define ECUM_CALLOUT_STUBS_AR_RELEASE_REVISION_VERSION_C         2U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS                                      
 *====================================================================================================*/
/* Check if current file and EcuM header file are of the same vendor */
#if(ECUM_CALLOUT_STUBS_VENDOR_ID_C != ECUM_VENDOR_ID )
#error "EcuM_Callout_Stubs.c and EcuM.h have different vendor id"
#endif
/* Check if current file and EcuM header file are of the same Autosar version */
#if(\
        (ECUM_CALLOUT_STUBS_AR_RELEASE_MAJOR_VERSION_C != ECUM_AR_RELEASE_MAJOR_VERSION) || \
        (ECUM_CALLOUT_STUBS_AR_RELEASE_MINOR_VERSION_C != ECUM_AR_RELEASE_MINOR_VERSION) || \
        (ECUM_CALLOUT_STUBS_AR_RELEASE_REVISION_VERSION_C != ECUM_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Number of EcuM_Callout_Stubs.c and EcuM.h are different "
#endif
/* Check if current file and EcuM header file are of the same software version */
#if(\
        (ECUM_CALLOUT_STUBS_SW_MAJOR_VERSION_C != ECUM_SW_MAJOR_VERSION) || \
        (ECUM_CALLOUT_STUBS_SW_MINOR_VERSION_C != ECUM_SW_MINOR_VERSION) || \
        (ECUM_CALLOUT_STUBS_SW_PATCH_VERSION_C != ECUM_SW_PATCH_VERSION) \
    )
#error "Software Version Number of EcuM_Callout_Stubs.c and EcuM.h are different "
#endif

#ifndef DISABLE_INTERMOD_VERSION_CHECK
/* Check if current file and BswM header file are of the same Autosar version */
#if(\
        (ECUM_CALLOUT_STUBS_AR_RELEASE_MAJOR_VERSION_C != BSWM_AR_RELEASE_MAJOR_VERSION) || \
        (ECUM_CALLOUT_STUBS_AR_RELEASE_MINOR_VERSION_C != BSWM_AR_RELEASE_MINOR_VERSION)  \
    )
#error "AutoSar Version Number of EcuM_Callout_Stubs.c and BswM.h are different "
#endif

/* Check if current file and SchM header file are of the same Autosar version */
#if(\
        (ECUM_CALLOUT_STUBS_AR_RELEASE_MAJOR_VERSION_C != SCHM_AR_RELEASE_MAJOR_VERSION) || \
        (ECUM_CALLOUT_STUBS_AR_RELEASE_MINOR_VERSION_C != SCHM_AR_RELEASE_MINOR_VERSION)  \
    )
#error "AutoSar Version Number of EcuM_Callout_Stubs.c and SchM.h are different "
#endif

#endif /* #ifndef DISABLE_INTERMOD_VERSION_CHECK */
/*====================================================================================================*
 *                                   EXTERNAL FUNCTION DECLARATIONS                                 
 *====================================================================================================*/

/*====================================================================================================*
 *                                           LOCAL TYPEDEFS                                         
 *====================================================================================================*/

/*====================================================================================================*
 *                                            LOCAL MACROS                                          
 *====================================================================================================*/

/*====================================================================================================*
 *                                           LOCAL CONSTANTS                                        
 *====================================================================================================*/

/*====================================================================================================*
 *                                           LOCAL VARIABLES                                        
 *====================================================================================================*/

/*====================================================================================================*
 *                                      LOCAL FUNCTION PROTOTYPES                                   
 *====================================================================================================*/

/*====================================================================================================*
 *                                           LOCAL FUNCTIONS                                        
 *====================================================================================================*/

/*====================================================================================================*
 *                                          GLOBAL FUNCTIONS                                        
 *====================================================================================================*/
#define ECUM_START_SEC_CODE
#include "EcuM_MemMap.h"
/**
 * @brief         Error hook callout prototype.
 * @details       The ECU State Manager will call the error hook if the error codes
 *                "ECUM_E_RAM_CHECK_FAILED" or "ECUM_E_CONFIGURATION_DATA_INCONSISTENT" occur.
 *                In this situation it is not possible to continue processing and the ECU
 *                must be stopped. The integrator may choose the modality how the ECU is
 *                stopped, i.e. reset, halt, restart, safe state etc.
 * @req           SWS_EcuM_02904
 */
FUNC(void, ECUM_CODE) EcuM_ErrorHook
(
    CONST(uint16, AUTOMATIC) reason
)
{
    (void)reason;
    /* Won't return */
    while(1)
    {}
}
#if(STD_ON == ECUM_SET_PROGRAMMABLE_INTERRUPTS)
/**
 * @brief         shall set the interrupts.
 * @details       If the configuration parameter EcuMSetProgrammableInterrupts is set to true, this
 *				  callout EcuM_AL_SetProgrammableInterrupts is executed and shall set the
 *                interrupts on ECUs with programmable interrupts.
 * @req           SWS_EcuM_04085
 */
FUNC(void, ECUM_CODE) EcuM_AL_SetProgrammableInterrupts
(
    void
)
{

}
#endif /* STD_ON == ECUM_SET_PROGRAMMABLE_INTERRUPTS */

#if(STD_ON == ECUM_DRIVER_INIT_LIST_ZERO)
/**
 * @brief         Driver initilization step zero prototype.
 * @details       This callout shall provide driver initialization and other hardware-related startup
 *                activities for loading the post-build configuration data. Beware: Here only pre-
 *                compile and link-time configurable modules may be used.
 * @req           SWS_EcuM_02905
*/
FUNC(void, ECUM_CODE) EcuM_AL_DriverInitZero
(
    void
)
{
#if (STD_ON == ECUM_INCLUDE_DET)
    Det_Init(&Det_Config);
#endif /* (STD_ON == ECUM_INCLUDE_DET) */

 
 
 
}
#endif /* STD_ON == ECUM_DRIVER_INIT_LIST_ZERO */

/**
* @brief         Used to determine which post-build configuration shall be used in the remainder of
*                the startup process.
* @details       This callout should evaluate some condition, like port pin or NVRAM value, to
*                determine which post-build configuration shall be used in the remainder of the
*                startup process. It shall load this configuration data into a piece of memory that is
*                accessible by all BSW modules and shall return a pointer to the EcuM post-build
*                configuration as a base for all BSW module post-build configrations.
* @req           SWS_EcuM_02906
*/
FUNC(const EcuM_ConfigType*, ECUM_CODE) EcuM_DeterminePbConfiguration
(
    void
)
{
    /* Custom Code(Modifiable) */
    const EcuM_ConfigType* ret = &EcuM_Config;

    return ret;
}

#if(STD_ON == ECUM_DRIVER_INIT_LIST_ONE)
/**
 * @brief         Driver initilization step one prototype.
 * @details       This callout shall provide driver initialization and other hardware-related startup
 *                activities in case of a power on reset.
 * @req           SWS_EcuM_02907
 */
FUNC(void, ECUM_CODE) EcuM_AL_DriverInitOne
(
    P2CONST(EcuM_ConfigType, AUTOMATIC, ECUM_APPL_CODE) ConfigPtr
)
{

//    /* MCU Driver */
//    Mcu_Init(&Mcu_Config);
//    /* @todo Not support selection of clock configuration for MCU. */
//    Mcu_InitClock(0);
//    #if (STD_OFF == MCU_NO_PLL)
//    /* waiting for pll lock */
//    while(MCU_PLL_UNLOCKED == Mcu_GetPllStatus()) {}
//    /* distribute pll clock */
//    Mcu_DistributePllClock();
//    #endif /* (STD_OFF == MCU_NO_PLL) */


 
 
    
}
#endif /* STD_ON == ECUM_DRIVER_INIT_LIST_ONE */

#if(STD_ON == ECUM_RESET_LOOP_DETECTION)
/**
 * @brief         loop detection.
 * @details       If the configuration parameter EcuMResetLoopDetection is set to true,
 *                this callout EcuM_LoopDetection is called on every startup.
 * @req           SWS_EcuM_04137
 */
FUNC(boolean, ECUM_CODE) EcuM_LoopDetection
(
    void
)
{
    boolean ret = TRUE;
    return ret;
}
#endif /* STD_ON == ECUM_RESET_LOOP_DETECTION */

/**
 * @brief         Notification propotype on entry into the GO OFF I state.
 * @details       This call allows the system designer to notify that the GO OFF I state is about to
 *                be entered.
 * @req           SWS_EcuM_02916
 */
FUNC(void, ECUM_CODE) EcuM_OnGoOffOne
(
    void
)
{

}

/**
 * @brief         Notification propotype on entry into the GO OFF II state.
 * @details       This call allows the system designer to notify that the GO OFF II state is about to
 *                be entered.
 * @req           SWS_EcuM_02917
 */
FUNC(void, ECUM_CODE) EcuM_OnGoOffTwo
(
    void
)
{

}

/**
 * @brief         Prototype process for shutting off the power supply.
 * @details       This callout shall take the code for shutting off the power supply of the ECU. If the
 *                ECU cannot unpower itself, a reset may be an adequate reaction.
 * @req           SWS_EcuM_02920
 */
FUNC(void, ECUM_CODE) EcuM_AL_SwitchOff
(
    void
)
{

}

/**
 * @brief         This callout shall take the code for resetting the ECU.
 * @req           SWS_EcuM_04065
 */
FUNC(void, ECUM_CODE) EcuM_AL_Reset
(
    CONST(EcuM_ResetType, AUTOMATIC) reset
)
{

}

/**
 * @brief         Used to enable wakeup sources.
 * @details       The ECU Manager Module calls EcuM_EnableWakeupSource to allow the system
 *                designer to notify wakeup sources defined in the wakeupSource bitfield that
 *                SLEEP will be entered and to adjust their source accordingly.
 * @req           SWS_EcuM_02918
 */
FUNC(void, ECUM_CODE) EcuM_EnableWakeupSources
(
    CONST(EcuM_WakeupSourceType, AUTOMATIC) wakeupSource
)
{

}

/**
* @req           SWS_EcuM_02919
* @see           EcuM_CheckRamHash
*/
FUNC(void, ECUM_CODE) EcuM_GenerateRamHash
(
    void
)
{

}

/**
* @brief         This callout is invoked periodically in all reduced clock sleep modes.
* @details       It is explicitely allowed to poll wakeup sources from this callout and to call wakeup
*                notification functions to indicate the end of the sleep state to the ECU State
*                Manager.
* @req           SWS_EcuM_02928
*/

FUNC(void, ECUM_CODE) EcuM_SleepActivity
(
    void
)
{
    /* Update the internal clock */
    /*	EcuM_SetClock();*/

}

/**
 * @brief          Start the CheckWakeupTimer for the corresponding WakeupSource.
 * @param[in]      WakeupSource: For this wakeup source the corresponding CheckWakeupTimer
 *                 shall be started.
 */
FUNC(void, ECUM_CODE) EcuM_StartCheckWakeup
(
    CONST(EcuM_WakeupSourceType, AUTOMATIC) WakeupSource
)
{

}

/**
 * @brief         This callout is called by the EcuM to poll a wakeup source.
 * @details       This callout is called by the EcuM to poll a wakeup source. It shall also be called
 *                by the ISR of a wakeup source to set up the PLL and check other wakeup sources
 *                that may be connected to the same interrupt.
 * @req           SWS_EcuM_02929
 */
FUNC(void, ECUM_CODE) EcuM_CheckWakeup
(
    CONST(EcuM_WakeupSourceType, AUTOMATIC) wakeupSource
)
{

}

/**
 * @brief          The API cancels the CheckWakeupTimer for the WakeupSource.
 * @param[in]      WakeupSource: For this wakeup source the corresponding
 *                 CheckWakeupTimer shall be canceled.
 */
FUNC(void, ECUM_CODE) EcuM_EndCheckWakeup
(
    CONST(EcuM_WakeupSourceType, AUTOMATIC) WakeupSource
)
{

}

/**
 * @brief         This callout is intended to provide a RAM integrity test.
 * 				  If the check fails, return E_NOT_OK, otherwise return E_OK.
 * @req           SWS_EcuM_02921
 */
FUNC(uint8, ECUM_CODE) EcuM_CheckRamHash
(
    void
)
{
    uint8 ret = E_OK;
    return ret;
}

/**
 * @brief         Used to disable wakeup sources.
 * @details       The ECU Manager Module calls EcuM_DisableWakeupSources to set the wakeup
 *                source(s) defined in the wakeupSource bitfield so that they are not able to wake
 *                the ECU up.
 * @req           SWS_EcuM_02922
 */
FUNC(void, ECUM_CODE) EcuM_DisableWakeupSources
(
    CONST(EcuM_WakeupSourceType, AUTOMATIC) wakeupSource
)
{

}

/**
 * @brief         Prototype for initilization in the wakeup case.
 * @details       This callout shall provide driver initialization and other hardware-related startup
 *                activities in the wakeup case.
 * @req           SWS_EcuM_02923
 */
FUNC(void, ECUM_CODE) EcuM_AL_DriverRestart
(
    P2CONST(EcuM_ConfigType, AUTOMATIC, ECUM_APPL_DATA) pConfigPtr
)
{
    
 
}

/**
 * @brief         Used to start wakeup sources.
 * @details       The callout shall start the given wakeup source(s) so that they are ready to
 *                perform wakeup validation.
 * @req           SWS_EcuM_02924
 */
FUNC(void, ECUM_CODE) EcuM_StartWakeupSources
(
    CONST(EcuM_WakeupSourceType, AUTOMATIC) wakeupSource
)
{

}

/**
 * @brief         Used to validate wakeup sources.
 * @details       This callout is called by the EcuM to validate a wakeup source. If a valid wakeup
 *                has been detected, it shall be reported to EcuM via EcuM_ValidateWakeupEvent().
 * @req           SWS_EcuM_02925
 */
FUNC(void, ECUM_CODE) EcuM_CheckValidation
(
    CONST(EcuM_WakeupSourceType, AUTOMATIC) wakeupSource
)
{
/* Call the module validation function: <Module>_CheckValidation() */

}

/**
 * @brief         Used to stop wakeup sources.
 * @details       The callout shall stop the given wakeup source(s) after unsuccessful wakeup
 *                validation.
 * @req           SWS_EcuM_02926
 */
FUNC(void, ECUM_CODE) EcuM_StopWakeupSources
(
    CONST(EcuM_WakeupSourceType, AUTOMATIC) wakeupSource
)
{

}

#define ECUM_STOP_SEC_CODE
#include "EcuM_MemMap.h"

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */
/** @} */

