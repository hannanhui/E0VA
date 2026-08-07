/**
 *  @file     EcuM_LCfg.c
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

/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION                                 
 *====================================================================================================*/

#define ECUM_LCFG_VENDOR_ID_C                           0U
#define ECUM_LCFG_SW_MAJOR_VERSION_C                    1U
#define ECUM_LCFG_SW_MINOR_VERSION_C                    2U
#define ECUM_LCFG_SW_PATCH_VERSION_C                    0U
#define ECUM_LCFG_AR_RELEASE_MAJOR_VERSION_C            4U
#define ECUM_LCFG_AR_RELEASE_MINOR_VERSION_C            2U
#define ECUM_LCFG_AR_RELEASE_REVISION_VERSION_C         2U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS                                      
 *====================================================================================================*/

/* Check if current file and EcuM header file are of the same vendor */
#if(ECUM_LCFG_VENDOR_ID_C != ECUM_VENDOR_ID )
#error "EcuM_Lcfg.c and EcuM.h have different vendor id"
#endif
/* Check if current file and EcuM header file are of the same Autosar version */
#if(\
        (ECUM_LCFG_AR_RELEASE_MAJOR_VERSION_C != ECUM_AR_RELEASE_MAJOR_VERSION) || \
        (ECUM_LCFG_AR_RELEASE_MINOR_VERSION_C != ECUM_AR_RELEASE_MINOR_VERSION) || \
        (ECUM_LCFG_AR_RELEASE_REVISION_VERSION_C != ECUM_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Number of EcuM_Lcfg.c and EcuM.h are different "
#endif
/* Check if current file and EcuM header file are of the same software version */
#if(\
        (ECUM_LCFG_SW_MAJOR_VERSION_C != ECUM_SW_MAJOR_VERSION) || \
        (ECUM_LCFG_SW_MINOR_VERSION_C != ECUM_SW_MINOR_VERSION) || \
        (ECUM_LCFG_SW_PATCH_VERSION_C != ECUM_SW_PATCH_VERSION) \
    )
#error "Software Version Number of EcuM_Lcfg.c and EcuM.h are different "
#endif

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


#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */
/** @} */

