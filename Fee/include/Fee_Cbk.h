/**
 * @file        Fee_Cbk.h
 * @brief       AUTOSAR FEE_CBK - Fee_Cbk driver header file.
 * @details     Fee_Cbk driver header file, containing the Autosar API specification and
 *               other variables and functions that are exported by the Fee_Cbk driver.
 * @version     1.2.0
 * @addtogroup  FEE_CBK
 * @{
 */
/*=================================================================================================*
 * AngHui AUTOSAR BSW.
 *
 * Copyright(C) 2023 GuoKeAngHui Inc.
 *
 * All rights reserved.
 *
 * This file is part of AngHui AUTOSAR BSW, contains proprietary information.
 * Passing on and copying of this document, and communication of its contents
 * is not permitted without prior written authorization.
 *=================================================================================================*/

#ifndef FEE_CBK_H
#define FEE_CBK_H

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================*
 *                                           INCLUDE FILES                                          
 *====================================================================================================*/

#include "Std_Types.h"

/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION                                 
 *====================================================================================================*/

#define FEE_CBK_VENDOR_ID 						0U
#define FEE_CBK_AR_RELEASE_MAJOR_VERSION 		4U
#define FEE_CBK_AR_RELEASE_MINOR_VERSION 		2U
#define FEE_CBK_AR_RELEASE_REVISION_VERSION 	2U
#define FEE_CBK_SW_MAJOR_VERSION 				1U
#define FEE_CBK_SW_MINOR_VERSION 				2U
#define FEE_CBK_SW_PATCH_VERSION				0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS                                      
 *====================================================================================================*/

#ifndef DISABLE_INTERMOD_VERSION_CHECK

/* Check if current file and Std_Types header file are of the same Autosar version */
#if (\
		(FEE_CBK_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
		(FEE_CBK_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)\
    )
    #error "AutoSar Version Numbers of Fee_Cbk.h and Std_Types.h are different"
#endif

#endif/* DISABLE_INTERMOD_VERSION_CHECK */

/*====================================================================================================*
 *                                             CONSTANTS                                            
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                         DEFINES AND MACROS                                       
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                               ENUMS                                              
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS                                  
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS                                  
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES                                       
 *====================================================================================================*/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"

FUNC(void, FEE_CODE) Fee_JobEndNotification(void);
FUNC(void, FEE_CODE) Fee_JobErrorNotification(void);

#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* FEE_CBK_H */
/** @} */
