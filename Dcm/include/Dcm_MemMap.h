/**
 * @file        Dcm_MemMap.h
 * @brief       AUTOSAR Dcm_MemMap - Dcm_MemMap driver header file.
 * @details     Dcm_MemMap driver header file, containing the Autosar API specification and
 *               other variables and functions that are exported by the Dcm_MemMap driver.
 * @version     1.2.0
 *
 * @addtogroup  Dcm_MemMap
 * @{
 */
/*====================================================================================================*
 * AngHui AUTOSAR BSW.
 *
 * Copyright(C) 2023 GuoKeAngHui Inc.
 *
 * All rights reserved.
 *
 * This file is part of AngHui AUTOSAR BSW, contains proprietary information.
 * Passing on and copying of this document, and communication of its contents
 * is not permitted without prior written authorization.
 *====================================================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/* PRQA S 0841, 3116, 0883 EOF #
 *
 * 1.0841 -- Violates MISRA 2004 Required Rule 19.6, Using '#undef'.
 *
 * 2.3116 -- Violates MISRA 2004 Required Rule 3.4, nrecognized #pragma arguments '%s' This #pragma
 * directive has been ignored.
 *
 * 3.0883 -- Violates MISRA 2004 Required Rule 19.15, Include file code is not protected against
 * repeated inclusion
 *
 * @page misra_violations MISRA-C:2004 violations
 */

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/


/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/

#define DCM_MEMMAP_VENDOR_ID                      0U
#define DCM_MEMMAP_AR_RELEASE_MAJOR_VERSION       4U
#define DCM_MEMMAP_AR_RELEASE_MINOR_VERSION       2U
#define DCM_MEMMAP_AR_RELEASE_REVISION_VERSION    2U
#define DCM_MEMMAP_SW_MAJOR_VERSION               1U
#define DCM_MEMMAP_SW_MINOR_VERSION               2U
#define DCM_MEMMAP_SW_PATCH_VERSION               0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/


/*====================================================================================================*
 *                                             CONSTANTS
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                         DEFINES AND MACROS
 *====================================================================================================*/

/**
* @brief Symbol used for checking correctness of the includes
*/
#define MEMMAP_ERROR

#ifdef USING_OS_AUTOSAROS
#include "Os_memmap.h"
#endif

/*======================================================================*
*                            Dcm
*======================================================================*/

#ifdef DCM_START_SEC_VAR_NO_INIT_8
#undef DCM_START_SEC_VAR_NO_INIT_8
#define ENTERED_DCM_START_SEC_VAR_NO_INIT_8
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef DCM_STOP_SEC_VAR_NO_INIT_8
#error Dcm_MEMMAP_SECTION_NOTMATCH_ERROR
#endif
#endif
#undef MEMMAP_ERROR
#pragma GCC section bss ".Dcm_bss_8"
#endif
#ifdef DCM_STOP_SEC_VAR_NO_INIT_8
#ifdef ENTERED_DCM_START_SEC_VAR_NO_INIT_8
#undef ENTERED_DCM_START_SEC_VAR_NO_INIT_8
#else
#error Dcm_MEMMAP_SECTION_NOTMATCH_ERROR
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef DCM_STOP_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR
#pragma GCC section bss "default"
#endif


#ifdef DCM_START_SEC_VAR_NO_INIT_16
#undef DCM_START_SEC_VAR_NO_INIT_16
#define ENTERED_DCM_START_SEC_VAR_NO_INIT_16
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef DCM_STOP_SEC_VAR_NO_INIT_16
#error Dcm_MEMMAP_SECTION_NOTMATCH_ERROR
#endif
#endif
#undef MEMMAP_ERROR
#pragma GCC section bss ".Dcm_bss_16"
#endif
#ifdef DCM_STOP_SEC_VAR_NO_INIT_16
#ifdef ENTERED_DCM_START_SEC_VAR_NO_INIT_16
#undef ENTERED_DCM_START_SEC_VAR_NO_INIT_16
#else
#error Dcm_MEMMAP_SECTION_NOTMATCH_ERROR
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef DCM_STOP_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR
#pragma GCC section bss "default"
#endif


#ifdef DCM_START_SEC_VAR_NO_INIT_32
#undef DCM_START_SEC_VAR_NO_INIT_32
#define ENTERED_DCM_START_SEC_VAR_NO_INIT_32
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef DCM_STOP_SEC_VAR_NO_INIT_32
#error Dcm_MEMMAP_SECTION_NOTMATCH_ERROR
#endif
#endif
#undef MEMMAP_ERROR
#pragma GCC section bss ".Dcm_bss_32"
#endif
#ifdef DCM_STOP_SEC_VAR_NO_INIT_32
#ifdef ENTERED_DCM_START_SEC_VAR_NO_INIT_32
#undef ENTERED_DCM_START_SEC_VAR_NO_INIT_32
#else
#error Dcm_MEMMAP_SECTION_NOTMATCH_ERROR
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef DCM_STOP_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR
#pragma GCC section bss "default"
#endif


#ifdef DCM_START_SEC_VAR_NO_INIT_BOOLEAN
#undef DCM_START_SEC_VAR_NO_INIT_BOOLEAN
#define ENTERED_DCM_START_SEC_VAR_NO_INIT_BOOLEAN
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef DCM_STOP_SEC_VAR_NO_INIT_BOOLEAN
#error Dcm_MEMMAP_SECTION_NOTMATCH_ERROR
#endif
#endif
#undef MEMMAP_ERROR
#pragma GCC section bss ".Dcm_bss_boolean"
#endif
#ifdef DCM_STOP_SEC_VAR_NO_INIT_BOOLEAN
#ifdef ENTERED_DCM_START_SEC_VAR_NO_INIT_BOOLEAN
#undef ENTERED_DCM_START_SEC_VAR_NO_INIT_BOOLEAN
#else
#error Dcm_MEMMAP_SECTION_NOTMATCH_ERROR
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef DCM_STOP_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR
#pragma GCC section bss "default"
#endif


#ifdef DCM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef DCM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#define ENTERED_DCM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef DCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#error Dcm_MEMMAP_SECTION_NOTMATCH_ERROR
#endif
#endif
#undef MEMMAP_ERROR
#pragma GCC section bss ".Dcm_bss"
#endif
#ifdef DCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#ifdef ENTERED_DCM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef ENTERED_DCM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#else
#error Dcm_MEMMAP_SECTION_NOTMATCH_ERROR
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef DCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#pragma GCC section bss "default"
#endif

/*======================================================================*
*                            Dcm
*======================================================================*/

#ifdef DCM_START_SEC_CODE
#undef DCM_START_SEC_CODE
#define ENTERED_DCM_START_SEC_CODE
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef DCM_STOP_SEC_CODE
#error Dcm_MEMMAP_SECTION_NOTMATCH_ERROR
#endif
#endif
#undef MEMMAP_ERROR
#pragma GCC section text ".Dcm_text"
#endif
#ifdef DCM_STOP_SEC_CODE
#ifdef ENTERED_DCM_START_SEC_CODE
#undef ENTERED_DCM_START_SEC_CODE
#else
#error Dcm_MEMMAP_SECTION_NOTMATCH_ERROR
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef DCM_STOP_SEC_CODE
#undef MEMMAP_ERROR
#pragma GCC section text "default"
#endif
/*======================================================================*
*                            Dcm
*======================================================================*/

#ifdef DCM_START_SEC_CONFIG_DATA_8
#undef DCM_START_SEC_CONFIG_DATA_8
#define ENTERED_DCM_START_SEC_CONFIG_DATA_8
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef DCM_STOP_SEC_CONFIG_DATA_8
#error Dcm_MEMMAP_SECTION_NOTMATCH_ERROR
#endif
#endif
#undef MEMMAP_ERROR
#pragma GCC section rodata ".Dcm_Cfg_data_8"
#endif
#ifdef DCM_STOP_SEC_CONFIG_DATA_8
#ifdef ENTERED_DCM_START_SEC_CONFIG_DATA_8
#undef ENTERED_DCM_START_SEC_CONFIG_DATA_8
#else
#error Dcm_MEMMAP_SECTION_NOTMATCH_ERROR
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef DCM_STOP_SEC_CONFIG_DATA_8
#undef MEMMAP_ERROR
#pragma GCC section rodata "default"
#endif


#ifdef DCM_START_SEC_CONFIG_DATA_16
#undef DCM_START_SEC_CONFIG_DATA_16
#define ENTERED_DCM_START_SEC_CONFIG_DATA_16
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef DCM_STOP_SEC_CONFIG_DATA_16
#error Dcm_MEMMAP_SECTION_NOTMATCH_ERROR
#endif
#endif
#undef MEMMAP_ERROR
#pragma GCC section rodata ".Dcm_Cfg_data_16"
#endif
#ifdef DCM_STOP_SEC_CONFIG_DATA_16
#ifdef ENTERED_DCM_START_SEC_CONFIG_DATA_16
#undef ENTERED_DCM_START_SEC_CONFIG_DATA_16
#else
#error Dcm_MEMMAP_SECTION_NOTMATCH_ERROR
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef DCM_STOP_SEC_CONFIG_DATA_16
#undef MEMMAP_ERROR
#pragma GCC section rodata "default"
#endif


#ifdef DCM_START_SEC_CONFIG_DATA_32
#undef DCM_START_SEC_CONFIG_DATA_32
#define ENTERED_DCM_START_SEC_CONFIG_DATA_32
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef DCM_STOP_SEC_CONFIG_DATA_32
#error Dcm_MEMMAP_SECTION_NOTMATCH_ERROR
#endif
#endif
#undef MEMMAP_ERROR
#pragma GCC section rodata ".Dcm_Cfg_data_32"
#endif
#ifdef DCM_STOP_SEC_CONFIG_DATA_32
#ifdef ENTERED_DCM_START_SEC_CONFIG_DATA_32
#undef ENTERED_DCM_START_SEC_CONFIG_DATA_32
#else
#error Dcm_MEMMAP_SECTION_NOTMATCH_ERROR
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef DCM_STOP_SEC_CONFIG_DATA_32
#undef MEMMAP_ERROR
#pragma GCC section rodata "default"
#endif


#ifdef DCM_START_SEC_CONFIG_DATA_BOOLEAN
#undef DCM_START_SEC_CONFIG_DATA_BOOLEAN
#define ENTERED_DCM_START_SEC_CONFIG_DATA_BOOLEAN
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef DCM_STOP_SEC_CONFIG_DATA_BOOLEAN
#error Dcm_MEMMAP_SECTION_NOTMATCH_ERROR
#endif
#endif
#undef MEMMAP_ERROR
#pragma GCC section rodata ".Dcm_Cfg_data_boolean"
#endif
#ifdef DCM_STOP_SEC_CONFIG_DATA_BOOLEAN
#ifdef ENTERED_DCM_START_SEC_CONFIG_DATA_BOOLEAN
#undef ENTERED_DCM_START_SEC_CONFIG_DATA_BOOLEAN
#else
#error Dcm_MEMMAP_SECTION_NOTMATCH_ERROR
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef DCM_STOP_SEC_CONFIG_DATA_BOOLEAN
#undef MEMMAP_ERROR
#pragma GCC section rodata "default"
#endif


#ifdef DCM_START_SEC_CONFIG_DATA_UNSPECIFIED
#undef DCM_START_SEC_CONFIG_DATA_UNSPECIFIED
#define ENTERED_DCM_START_SEC_CONFIG_DATA_UNSPECIFIED
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef DCM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#error Dcm_MEMMAP_SECTION_NOTMATCH_ERROR
#endif
#endif
#undef MEMMAP_ERROR
#pragma GCC section rodata ".Dcm_Cfg_data"
#endif
#ifdef DCM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#ifdef ENTERED_DCM_START_SEC_CONFIG_DATA_UNSPECIFIED
#undef ENTERED_DCM_START_SEC_CONFIG_DATA_UNSPECIFIED
#else
#error Dcm_MEMMAP_SECTION_NOTMATCH_ERROR
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef DCM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#undef MEMMAP_ERROR
#pragma GCC section rodata "default"
#endif

/*======================================================================*
*                            Dcm
*======================================================================*/

#ifdef DCM_START_SEC_CONST_8
#undef DCM_START_SEC_CONST_8
#define ENTERED_DCM_START_SEC_CONST_8
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef DCM_STOP_SEC_CONST_8
#error Dcm_MEMMAP_SECTION_NOTMATCH_ERROR
#endif
#endif
#undef MEMMAP_ERROR
#pragma GCC section rodata ".Dcm_rodata_8"
#endif
#ifdef DCM_STOP_SEC_CONST_8
#ifdef ENTERED_DCM_START_SEC_CONST_8
#undef ENTERED_DCM_START_SEC_CONST_8
#else
#error Dcm_MEMMAP_SECTION_NOTMATCH_ERROR
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef DCM_STOP_SEC_CONST_8
#undef MEMMAP_ERROR
#pragma GCC section rodata "default"
#endif


#ifdef DCM_START_SEC_CONST_16
#undef DCM_START_SEC_CONST_16
#define ENTERED_DCM_START_SEC_CONST_16
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef DCM_STOP_SEC_CONST_16
#error Dcm_MEMMAP_SECTION_NOTMATCH_ERROR
#endif
#endif
#undef MEMMAP_ERROR
#pragma GCC section rodata ".Dcm_rodata_16"
#endif
#ifdef DCM_STOP_SEC_CONST_16
#ifdef ENTERED_DCM_START_SEC_CONST_16
#undef ENTERED_DCM_START_SEC_CONST_16
#else
#error Dcm_MEMMAP_SECTION_NOTMATCH_ERROR
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef DCM_STOP_SEC_CONST_16
#undef MEMMAP_ERROR
#pragma GCC section rodata "default"
#endif


#ifdef DCM_START_SEC_CONST_32
#undef DCM_START_SEC_CONST_32
#define ENTERED_DCM_START_SEC_CONST_32
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef DCM_STOP_SEC_CONST_32
#error Dcm_MEMMAP_SECTION_NOTMATCH_ERROR
#endif
#endif
#undef MEMMAP_ERROR
#pragma GCC section rodata ".Dcm_rodata_32"
#endif
#ifdef DCM_STOP_SEC_CONST_32
#ifdef ENTERED_DCM_START_SEC_CONST_32
#undef ENTERED_DCM_START_SEC_CONST_32
#else
#error Dcm_MEMMAP_SECTION_NOTMATCH_ERROR
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef DCM_STOP_SEC_CONST_32
#undef MEMMAP_ERROR
#pragma GCC section rodata "default"
#endif


#ifdef DCM_START_SEC_CONST_BOOLEAN
#undef DCM_START_SEC_CONST_BOOLEAN
#define ENTERED_DCM_START_SEC_CONST_BOOLEAN
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef DCM_STOP_SEC_CONST_BOOLEAN
#error Dcm_MEMMAP_SECTION_NOTMATCH_ERROR
#endif
#endif
#undef MEMMAP_ERROR
#pragma GCC section rodata ".Dcm_rodata_boolean"
#endif
#ifdef DCM_STOP_SEC_CONST_BOOLEAN
#ifdef ENTERED_DCM_START_SEC_CONST_BOOLEAN
#undef ENTERED_DCM_START_SEC_CONST_BOOLEAN
#else
#error Dcm_MEMMAP_SECTION_NOTMATCH_ERROR
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef DCM_STOP_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR
#pragma GCC section rodata "default"
#endif


#ifdef DCM_START_SEC_CONST_UNSPECIFIED
#undef DCM_START_SEC_CONST_UNSPECIFIED
#define ENTERED_DCM_START_SEC_CONST_UNSPECIFIED
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef DCM_STOP_SEC_CONST_UNSPECIFIED
#error Dcm_MEMMAP_SECTION_NOTMATCH_ERROR
#endif
#endif
#undef MEMMAP_ERROR
#pragma GCC section rodata ".Dcm_rodata"
#endif
#ifdef DCM_STOP_SEC_CONST_UNSPECIFIED
#ifdef ENTERED_DCM_START_SEC_CONST_UNSPECIFIED
#undef ENTERED_DCM_START_SEC_CONST_UNSPECIFIED
#else
#error Dcm_MEMMAP_SECTION_NOTMATCH_ERROR
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef DCM_STOP_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR
#pragma GCC section rodata "default"
#endif

/*======================================================================*
*                            Dcm
*======================================================================*/

#ifdef DCM_START_SEC_VAR_INIT_8
#undef DCM_START_SEC_VAR_INIT_8
#define ENTERED_DCM_START_SEC_VAR_INIT_8
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef DCM_STOP_SEC_VAR_INIT_8
#error Dcm_MEMMAP_SECTION_NOTMATCH_ERROR
#endif
#endif
#undef MEMMAP_ERROR
#pragma GCC section data ".Dcm_data_8"
#endif
#ifdef DCM_STOP_SEC_VAR_INIT_8
#ifdef ENTERED_DCM_START_SEC_VAR_INIT_8
#undef ENTERED_DCM_START_SEC_VAR_INIT_8
#else
#error Dcm_MEMMAP_SECTION_NOTMATCH_ERROR
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef DCM_STOP_SEC_VAR_INIT_8
#undef MEMMAP_ERROR
#pragma GCC section data "default"
#endif


#ifdef DCM_START_SEC_VAR_INIT_16
#undef DCM_START_SEC_VAR_INIT_16
#define ENTERED_DCM_START_SEC_VAR_INIT_16
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef DCM_STOP_SEC_VAR_INIT_16
#error Dcm_MEMMAP_SECTION_NOTMATCH_ERROR
#endif
#endif
#undef MEMMAP_ERROR
#pragma GCC section data ".Dcm_data_16"
#endif
#ifdef DCM_STOP_SEC_VAR_INIT_16
#ifdef ENTERED_DCM_START_SEC_VAR_INIT_16
#undef ENTERED_DCM_START_SEC_VAR_INIT_16
#else
#error Dcm_MEMMAP_SECTION_NOTMATCH_ERROR
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef DCM_STOP_SEC_VAR_INIT_16
#undef MEMMAP_ERROR
#pragma GCC section data "default"
#endif


#ifdef DCM_START_SEC_VAR_INIT_32
#undef DCM_START_SEC_VAR_INIT_32
#define ENTERED_DCM_START_SEC_VAR_INIT_32
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef DCM_STOP_SEC_VAR_INIT_32
#error Dcm_MEMMAP_SECTION_NOTMATCH_ERROR
#endif
#endif
#undef MEMMAP_ERROR
#pragma GCC section data ".Dcm_data_32"
#endif
#ifdef DCM_STOP_SEC_VAR_INIT_32
#ifdef ENTERED_DCM_START_SEC_VAR_INIT_32
#undef ENTERED_DCM_START_SEC_VAR_INIT_32
#else
#error Dcm_MEMMAP_SECTION_NOTMATCH_ERROR
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef DCM_STOP_SEC_VAR_INIT_32
#undef MEMMAP_ERROR
#pragma GCC section data "default"
#endif


#ifdef DCM_START_SEC_VAR_INIT_BOOLEAN
#undef DCM_START_SEC_VAR_INIT_BOOLEAN
#define ENTERED_DCM_START_SEC_VAR_INIT_BOOLEAN
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef DCM_STOP_SEC_VAR_INIT_BOOLEAN
#error Dcm_MEMMAP_SECTION_NOTMATCH_ERROR
#endif
#endif
#undef MEMMAP_ERROR
#pragma GCC section data ".Dcm_data_boolean"
#endif
#ifdef DCM_STOP_SEC_VAR_INIT_BOOLEAN
#ifdef ENTERED_DCM_START_SEC_VAR_INIT_BOOLEAN
#undef ENTERED_DCM_START_SEC_VAR_INIT_BOOLEAN
#else
#error Dcm_MEMMAP_SECTION_NOTMATCH_ERROR
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef DCM_STOP_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR
#pragma GCC section data "default"
#endif


#ifdef DCM_START_SEC_VAR_INIT_UNSPECIFIED
#undef DCM_START_SEC_VAR_INIT_UNSPECIFIED
#define ENTERED_DCM_START_SEC_VAR_INIT_UNSPECIFIED
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef DCM_STOP_SEC_VAR_INIT_UNSPECIFIED
#error Dcm_MEMMAP_SECTION_NOTMATCH_ERROR
#endif
#endif
#undef MEMMAP_ERROR
#pragma GCC section data ".Dcm_data"
#endif
#ifdef DCM_STOP_SEC_VAR_INIT_UNSPECIFIED
#ifdef ENTERED_DCM_START_SEC_VAR_INIT_UNSPECIFIED
#undef ENTERED_DCM_START_SEC_VAR_INIT_UNSPECIFIED
#else
#error Dcm_MEMMAP_SECTION_NOTMATCH_ERROR
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef DCM_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#pragma GCC section data "default"
#endif


#ifdef MEMMAP_ERROR
#error "MemMap.h, no valid memory mapping symbol defined."
#endif

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

/* Add code here */

#ifdef __cplusplus
}
#endif
