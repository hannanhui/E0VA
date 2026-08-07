/**
 * @file        BswM_MemMap.h
 * @brief       AUTOSAR BswM_MemMap - BswM_MemMap driver header file.
 * @details     BswM_MemMap driver header file, containing the Autosar API specification and
 *              other variables and functions that are exported by the BswM_MemMap driver.
 * @version     1.2.0
 *
 * @addtogroup  BswM_MemMap
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

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================*
 *                                           INCLUDE FILES                                          
 *====================================================================================================*/


/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION                                 
 *====================================================================================================*/

#define BSWM_MEMMAP_VENDOR_ID                      0U
#define BSWM_MEMMAP_AR_RELEASE_MAJOR_VERSION       4U
#define BSWM_MEMMAP_AR_RELEASE_MINOR_VERSION       2U
#define BSWM_MEMMAP_AR_RELEASE_REVISION_VERSION    2U
#define BSWM_MEMMAP_SW_MAJOR_VERSION               1U
#define BSWM_MEMMAP_SW_MINOR_VERSION               2U
#define BSWM_MEMMAP_SW_PATCH_VERSION               0U

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
*                            BswM                         
*======================================================================*/

#ifdef BSWM_START_SEC_VAR_NO_INIT_8
    #undef BSWM_START_SEC_VAR_NO_INIT_8
    #define ENTERED_BSWM_START_SEC_VAR_NO_INIT_8
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef BSWM_STOP_SEC_VAR_NO_INIT_8
            #error BswM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section bss ".BswM_bss"
#endif
#ifdef BSWM_STOP_SEC_VAR_NO_INIT_8
    #ifdef ENTERED_BSWM_START_SEC_VAR_NO_INIT_8
        #undef ENTERED_BSWM_START_SEC_VAR_NO_INIT_8
    #else
        #error BswM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef BSWM_STOP_SEC_VAR_NO_INIT_8
    #undef MEMMAP_ERROR
        #pragma GCC section bss "default"
#endif


#ifdef BSWM_START_SEC_VAR_NO_INIT_16
    #undef BSWM_START_SEC_VAR_NO_INIT_16
    #define ENTERED_BSWM_START_SEC_VAR_NO_INIT_16
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef BSWM_STOP_SEC_VAR_NO_INIT_16
            #error BswM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section bss ".BswM_bss"
#endif
#ifdef BSWM_STOP_SEC_VAR_NO_INIT_16
    #ifdef ENTERED_BSWM_START_SEC_VAR_NO_INIT_16
        #undef ENTERED_BSWM_START_SEC_VAR_NO_INIT_16
    #else
        #error BswM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef BSWM_STOP_SEC_VAR_NO_INIT_16
    #undef MEMMAP_ERROR
        #pragma GCC section bss "default"
#endif


#ifdef BSWM_START_SEC_VAR_NO_INIT_32
    #undef BSWM_START_SEC_VAR_NO_INIT_32
    #define ENTERED_BSWM_START_SEC_VAR_NO_INIT_32
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef BSWM_STOP_SEC_VAR_NO_INIT_32
            #error BswM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section bss ".BswM_bss"
#endif
#ifdef BSWM_STOP_SEC_VAR_NO_INIT_32
    #ifdef ENTERED_BSWM_START_SEC_VAR_NO_INIT_32
        #undef ENTERED_BSWM_START_SEC_VAR_NO_INIT_32
    #else
        #error BswM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef BSWM_STOP_SEC_VAR_NO_INIT_32
    #undef MEMMAP_ERROR
        #pragma GCC section bss "default"
#endif


#ifdef BSWM_START_SEC_VAR_NO_INIT_BOOLEAN
    #undef BSWM_START_SEC_VAR_NO_INIT_BOOLEAN
    #define ENTERED_BSWM_START_SEC_VAR_NO_INIT_BOOLEAN
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef BSWM_STOP_SEC_VAR_NO_INIT_BOOLEAN
            #error BswM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section bss ".BswM_bss"
#endif
#ifdef BSWM_STOP_SEC_VAR_NO_INIT_BOOLEAN
    #ifdef ENTERED_BSWM_START_SEC_VAR_NO_INIT_BOOLEAN
        #undef ENTERED_BSWM_START_SEC_VAR_NO_INIT_BOOLEAN
    #else
        #error BswM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef BSWM_STOP_SEC_VAR_NO_INIT_BOOLEAN
    #undef MEMMAP_ERROR
        #pragma GCC section bss "default"
#endif


#ifdef BSWM_START_SEC_VAR_NO_INIT_UNSPECIFIED
    #undef BSWM_START_SEC_VAR_NO_INIT_UNSPECIFIED
    #define ENTERED_BSWM_START_SEC_VAR_NO_INIT_UNSPECIFIED
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef BSWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
            #error BswM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section bss ".BswM_bss"
#endif
#ifdef BSWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    #ifdef ENTERED_BSWM_START_SEC_VAR_NO_INIT_UNSPECIFIED
        #undef ENTERED_BSWM_START_SEC_VAR_NO_INIT_UNSPECIFIED
    #else
        #error BswM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef BSWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR
        #pragma GCC section bss "default"
#endif

/*======================================================================*
*                            BswM                         
*======================================================================*/

#ifdef BSWM_START_SEC_CODE
    #undef BSWM_START_SEC_CODE
    #define ENTERED_BSWM_START_SEC_CODE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef BSWM_STOP_SEC_CODE
            #error BswM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section text ".BswM_text"
#endif
#ifdef BSWM_STOP_SEC_CODE
    #ifdef ENTERED_BSWM_START_SEC_CODE
        #undef ENTERED_BSWM_START_SEC_CODE
    #else
        #error BswM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef BSWM_STOP_SEC_CODE
    #undef MEMMAP_ERROR
    #pragma GCC section text "default" 
#endif
/*======================================================================*
*                            BswM                         
*======================================================================*/

#ifdef BSWM_START_SEC_CONFIG_DATA_8
    #undef BSWM_START_SEC_CONFIG_DATA_8
    #define ENTERED_BSWM_START_SEC_CONFIG_DATA_8
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef BSWM_STOP_SEC_CONFIG_DATA_8
            #error BswM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section rodata ".BswM_Cfg_data"
#endif
#ifdef BSWM_STOP_SEC_CONFIG_DATA_8
    #ifdef ENTERED_BSWM_START_SEC_CONFIG_DATA_8
        #undef ENTERED_BSWM_START_SEC_CONFIG_DATA_8
    #else
        #error BswM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef BSWM_STOP_SEC_CONFIG_DATA_8
    #undef MEMMAP_ERROR
        #pragma GCC section rodata "default"
#endif


#ifdef BSWM_START_SEC_CONFIG_DATA_16
    #undef BSWM_START_SEC_CONFIG_DATA_16
    #define ENTERED_BSWM_START_SEC_CONFIG_DATA_16
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef BSWM_STOP_SEC_CONFIG_DATA_16
            #error BswM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section rodata ".BswM_Cfg_data"
#endif
#ifdef BSWM_STOP_SEC_CONFIG_DATA_16
    #ifdef ENTERED_BSWM_START_SEC_CONFIG_DATA_16
        #undef ENTERED_BSWM_START_SEC_CONFIG_DATA_16
    #else
        #error BswM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef BSWM_STOP_SEC_CONFIG_DATA_16
    #undef MEMMAP_ERROR
        #pragma GCC section rodata "default"
#endif


#ifdef BSWM_START_SEC_CONFIG_DATA_32
    #undef BSWM_START_SEC_CONFIG_DATA_32
    #define ENTERED_BSWM_START_SEC_CONFIG_DATA_32
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef BSWM_STOP_SEC_CONFIG_DATA_32
            #error BswM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section rodata ".BswM_Cfg_data"
#endif
#ifdef BSWM_STOP_SEC_CONFIG_DATA_32
    #ifdef ENTERED_BSWM_START_SEC_CONFIG_DATA_32
        #undef ENTERED_BSWM_START_SEC_CONFIG_DATA_32
    #else
        #error BswM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef BSWM_STOP_SEC_CONFIG_DATA_32
    #undef MEMMAP_ERROR
        #pragma GCC section rodata "default"
#endif


#ifdef BSWM_START_SEC_CONFIG_DATA_BOOLEAN
    #undef BSWM_START_SEC_CONFIG_DATA_BOOLEAN
    #define ENTERED_BSWM_START_SEC_CONFIG_DATA_BOOLEAN
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef BSWM_STOP_SEC_CONFIG_DATA_BOOLEAN
            #error BswM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section rodata ".BswM_Cfg_data"
#endif
#ifdef BSWM_STOP_SEC_CONFIG_DATA_BOOLEAN
    #ifdef ENTERED_BSWM_START_SEC_CONFIG_DATA_BOOLEAN
        #undef ENTERED_BSWM_START_SEC_CONFIG_DATA_BOOLEAN
    #else
        #error BswM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef BSWM_STOP_SEC_CONFIG_DATA_BOOLEAN
    #undef MEMMAP_ERROR
        #pragma GCC section rodata "default"
#endif


#ifdef BSWM_START_SEC_CONFIG_DATA_UNSPECIFIED
    #undef BSWM_START_SEC_CONFIG_DATA_UNSPECIFIED
    #define ENTERED_BSWM_START_SEC_CONFIG_DATA_UNSPECIFIED
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef BSWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
            #error BswM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section rodata ".BswM_Cfg_data"
#endif
#ifdef BSWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #ifdef ENTERED_BSWM_START_SEC_CONFIG_DATA_UNSPECIFIED
        #undef ENTERED_BSWM_START_SEC_CONFIG_DATA_UNSPECIFIED
    #else
        #error BswM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef BSWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR
        #pragma GCC section rodata "default"
#endif

/*======================================================================*
*                            BswM                         
*======================================================================*/

#ifdef BSWM_START_SEC_CONST_8
    #undef BSWM_START_SEC_CONST_8
    #define ENTERED_BSWM_START_SEC_CONST_8
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef BSWM_STOP_SEC_CONST_8
            #error BswM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section rodata ".BswM_rodata"
#endif
#ifdef BSWM_STOP_SEC_CONST_8
    #ifdef ENTERED_BSWM_START_SEC_CONST_8
        #undef ENTERED_BSWM_START_SEC_CONST_8
    #else
        #error BswM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef BSWM_STOP_SEC_CONST_8
    #undef MEMMAP_ERROR
        #pragma GCC section rodata "default"
#endif


#ifdef BSWM_START_SEC_CONST_16
    #undef BSWM_START_SEC_CONST_16
    #define ENTERED_BSWM_START_SEC_CONST_16
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef BSWM_STOP_SEC_CONST_16
            #error BswM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section rodata ".BswM_rodata"
#endif
#ifdef BSWM_STOP_SEC_CONST_16
    #ifdef ENTERED_BSWM_START_SEC_CONST_16
        #undef ENTERED_BSWM_START_SEC_CONST_16
    #else
        #error BswM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef BSWM_STOP_SEC_CONST_16
    #undef MEMMAP_ERROR
        #pragma GCC section rodata "default"
#endif


#ifdef BSWM_START_SEC_CONST_32
    #undef BSWM_START_SEC_CONST_32
    #define ENTERED_BSWM_START_SEC_CONST_32
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef BSWM_STOP_SEC_CONST_32
            #error BswM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section rodata ".BswM_rodata"
#endif
#ifdef BSWM_STOP_SEC_CONST_32
    #ifdef ENTERED_BSWM_START_SEC_CONST_32
        #undef ENTERED_BSWM_START_SEC_CONST_32
    #else
        #error BswM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef BSWM_STOP_SEC_CONST_32
    #undef MEMMAP_ERROR
        #pragma GCC section rodata "default"
#endif


#ifdef BSWM_START_SEC_CONST_BOOLEAN
    #undef BSWM_START_SEC_CONST_BOOLEAN
    #define ENTERED_BSWM_START_SEC_CONST_BOOLEAN
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef BSWM_STOP_SEC_CONST_BOOLEAN
            #error BswM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section rodata ".BswM_rodata"
#endif
#ifdef BSWM_STOP_SEC_CONST_BOOLEAN
    #ifdef ENTERED_BSWM_START_SEC_CONST_BOOLEAN
        #undef ENTERED_BSWM_START_SEC_CONST_BOOLEAN
    #else
        #error BswM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef BSWM_STOP_SEC_CONST_BOOLEAN
    #undef MEMMAP_ERROR
        #pragma GCC section rodata "default"
#endif


#ifdef BSWM_START_SEC_CONST_UNSPECIFIED
    #undef BSWM_START_SEC_CONST_UNSPECIFIED
    #define ENTERED_BSWM_START_SEC_CONST_UNSPECIFIED
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef BSWM_STOP_SEC_CONST_UNSPECIFIED
            #error BswM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section rodata ".BswM_rodata"
#endif
#ifdef BSWM_STOP_SEC_CONST_UNSPECIFIED
    #ifdef ENTERED_BSWM_START_SEC_CONST_UNSPECIFIED
        #undef ENTERED_BSWM_START_SEC_CONST_UNSPECIFIED
    #else
        #error BswM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef BSWM_STOP_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR
        #pragma GCC section rodata "default"
#endif

/*======================================================================*
*                            BswM                         
*======================================================================*/

#ifdef BSWM_START_SEC_VAR_INIT_8
    #undef BSWM_START_SEC_VAR_INIT_8
    #define ENTERED_BSWM_START_SEC_VAR_INIT_8
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef BSWM_STOP_SEC_VAR_INIT_8
            #error BswM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section data ".BswM_data"
#endif
#ifdef BSWM_STOP_SEC_VAR_INIT_8
    #ifdef ENTERED_BSWM_START_SEC_VAR_INIT_8
        #undef ENTERED_BSWM_START_SEC_VAR_INIT_8
    #else
        #error BswM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef BSWM_STOP_SEC_VAR_INIT_8
    #undef MEMMAP_ERROR
        #pragma GCC section data "default"
#endif


#ifdef BSWM_START_SEC_VAR_INIT_16
    #undef BSWM_START_SEC_VAR_INIT_16
    #define ENTERED_BSWM_START_SEC_VAR_INIT_16
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef BSWM_STOP_SEC_VAR_INIT_16
            #error BswM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section data ".BswM_data"
#endif
#ifdef BSWM_STOP_SEC_VAR_INIT_16
    #ifdef ENTERED_BSWM_START_SEC_VAR_INIT_16
        #undef ENTERED_BSWM_START_SEC_VAR_INIT_16
    #else
        #error BswM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef BSWM_STOP_SEC_VAR_INIT_16
    #undef MEMMAP_ERROR
        #pragma GCC section data "default"
#endif


#ifdef BSWM_START_SEC_VAR_INIT_32
    #undef BSWM_START_SEC_VAR_INIT_32
    #define ENTERED_BSWM_START_SEC_VAR_INIT_32
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef BSWM_STOP_SEC_VAR_INIT_32
            #error BswM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section data ".BswM_data"
#endif
#ifdef BSWM_STOP_SEC_VAR_INIT_32
    #ifdef ENTERED_BSWM_START_SEC_VAR_INIT_32
        #undef ENTERED_BSWM_START_SEC_VAR_INIT_32
    #else
        #error BswM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef BSWM_STOP_SEC_VAR_INIT_32
    #undef MEMMAP_ERROR
        #pragma GCC section data "default"
#endif


#ifdef BSWM_START_SEC_VAR_INIT_BOOLEAN
    #undef BSWM_START_SEC_VAR_INIT_BOOLEAN
    #define ENTERED_BSWM_START_SEC_VAR_INIT_BOOLEAN
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef BSWM_STOP_SEC_VAR_INIT_BOOLEAN
            #error BswM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section data ".BswM_data"
#endif
#ifdef BSWM_STOP_SEC_VAR_INIT_BOOLEAN
    #ifdef ENTERED_BSWM_START_SEC_VAR_INIT_BOOLEAN
        #undef ENTERED_BSWM_START_SEC_VAR_INIT_BOOLEAN
    #else
        #error BswM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef BSWM_STOP_SEC_VAR_INIT_BOOLEAN
    #undef MEMMAP_ERROR
        #pragma GCC section data "default"
#endif


#ifdef BSWM_START_SEC_VAR_INIT_UNSPECIFIED
    #undef BSWM_START_SEC_VAR_INIT_UNSPECIFIED
    #define ENTERED_BSWM_START_SEC_VAR_INIT_UNSPECIFIED
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef BSWM_STOP_SEC_VAR_INIT_UNSPECIFIED
            #error BswM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section data ".BswM_data"
#endif
#ifdef BSWM_STOP_SEC_VAR_INIT_UNSPECIFIED
    #ifdef ENTERED_BSWM_START_SEC_VAR_INIT_UNSPECIFIED
        #undef ENTERED_BSWM_START_SEC_VAR_INIT_UNSPECIFIED
    #else
        #error BswM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef BSWM_STOP_SEC_VAR_INIT_UNSPECIFIED
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


