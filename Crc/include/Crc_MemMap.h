/**
 * @file        Crc_MemMap.h
 * @brief       AUTOSAR Crc_MemMap - Crc_MemMap driver header file.
 * @details     Crc_MemMap driver header file, containing the Autosar API specification and
 *               other variables and functions that are exported by the Crc_MemMap driver.
 * @version     1.2.0
 *
 * @addtogroup  Crc_MemMap
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

#define CRC_MEMMAP_VENDOR_ID                      0U
#define CRC_MEMMAP_AR_RELEASE_MAJOR_VERSION       4U
#define CRC_MEMMAP_AR_RELEASE_MINOR_VERSION       2U
#define CRC_MEMMAP_AR_RELEASE_REVISION_VERSION    2U
#define CRC_MEMMAP_SW_MAJOR_VERSION               1U
#define CRC_MEMMAP_SW_MINOR_VERSION               2U
#define CRC_MEMMAP_SW_PATCH_VERSION               0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS                                      
 *====================================================================================================*/


/*====================================================================================================*
 *                                             CONSTANTS                                            
 *====================================================================================================*/

/* Add code here */
#if 0
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
*                            Crc                         
*======================================================================*/

#ifdef CRC_START_SEC_VAR_NO_INIT_8
    #undef CRC_START_SEC_VAR_NO_INIT_8
    #define ENTERED_CRC_START_SEC_VAR_NO_INIT_8
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CRC_STOP_SEC_VAR_NO_INIT_8
            #error Crc_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section bss ".Crc_bss"
#endif
#ifdef CRC_STOP_SEC_VAR_NO_INIT_8
    #ifdef ENTERED_CRC_START_SEC_VAR_NO_INIT_8
        #undef ENTERED_CRC_START_SEC_VAR_NO_INIT_8
    #else
        #error Crc_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CRC_STOP_SEC_VAR_NO_INIT_8
    #undef MEMMAP_ERROR
        #pragma GCC section bss "default"
#endif


#ifdef CRC_START_SEC_VAR_NO_INIT_16
    #undef CRC_START_SEC_VAR_NO_INIT_16
    #define ENTERED_CRC_START_SEC_VAR_NO_INIT_16
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CRC_STOP_SEC_VAR_NO_INIT_16
            #error Crc_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section bss ".Crc_bss"
#endif
#ifdef CRC_STOP_SEC_VAR_NO_INIT_16
    #ifdef ENTERED_CRC_START_SEC_VAR_NO_INIT_16
        #undef ENTERED_CRC_START_SEC_VAR_NO_INIT_16
    #else
        #error Crc_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CRC_STOP_SEC_VAR_NO_INIT_16
    #undef MEMMAP_ERROR
        #pragma GCC section bss "default"
#endif


#ifdef CRC_START_SEC_VAR_NO_INIT_32
    #undef CRC_START_SEC_VAR_NO_INIT_32
    #define ENTERED_CRC_START_SEC_VAR_NO_INIT_32
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CRC_STOP_SEC_VAR_NO_INIT_32
            #error Crc_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section bss ".Crc_bss"
#endif
#ifdef CRC_STOP_SEC_VAR_NO_INIT_32
    #ifdef ENTERED_CRC_START_SEC_VAR_NO_INIT_32
        #undef ENTERED_CRC_START_SEC_VAR_NO_INIT_32
    #else
        #error Crc_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CRC_STOP_SEC_VAR_NO_INIT_32
    #undef MEMMAP_ERROR
        #pragma GCC section bss "default"
#endif


#ifdef CRC_START_SEC_VAR_NO_INIT_BOOLEAN
    #undef CRC_START_SEC_VAR_NO_INIT_BOOLEAN
    #define ENTERED_CRC_START_SEC_VAR_NO_INIT_BOOLEAN
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CRC_STOP_SEC_VAR_NO_INIT_BOOLEAN
            #error Crc_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section bss ".Crc_bss"
#endif
#ifdef CRC_STOP_SEC_VAR_NO_INIT_BOOLEAN
    #ifdef ENTERED_CRC_START_SEC_VAR_NO_INIT_BOOLEAN
        #undef ENTERED_CRC_START_SEC_VAR_NO_INIT_BOOLEAN
    #else
        #error Crc_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CRC_STOP_SEC_VAR_NO_INIT_BOOLEAN
    #undef MEMMAP_ERROR
        #pragma GCC section bss "default"
#endif


#ifdef CRC_START_SEC_VAR_NO_INIT_UNSPECIFIED
    #undef CRC_START_SEC_VAR_NO_INIT_UNSPECIFIED
    #define ENTERED_CRC_START_SEC_VAR_NO_INIT_UNSPECIFIED
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CRC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
            #error Crc_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section bss ".Crc_bss"
#endif
#ifdef CRC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    #ifdef ENTERED_CRC_START_SEC_VAR_NO_INIT_UNSPECIFIED
        #undef ENTERED_CRC_START_SEC_VAR_NO_INIT_UNSPECIFIED
    #else
        #error Crc_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CRC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR
        #pragma GCC section bss "default"
#endif

/*======================================================================*
*                            Crc                         
*======================================================================*/

#ifdef CRC_START_SEC_CODE
    #undef CRC_START_SEC_CODE
    #define ENTERED_CRC_START_SEC_CODE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CRC_STOP_SEC_CODE
            #error Crc_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section text ".Crc_text"
#endif
#ifdef CRC_STOP_SEC_CODE
    #ifdef ENTERED_CRC_START_SEC_CODE
        #undef ENTERED_CRC_START_SEC_CODE
    #else
        #error Crc_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CRC_STOP_SEC_CODE
    #undef MEMMAP_ERROR
    #pragma GCC section text "default" 
#endif
/*======================================================================*
*                            Crc                         
*======================================================================*/

#ifdef CRC_START_SEC_CONFIG_DATA_8
    #undef CRC_START_SEC_CONFIG_DATA_8
    #define ENTERED_CRC_START_SEC_CONFIG_DATA_8
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CRC_STOP_SEC_CONFIG_DATA_8
            #error Crc_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section rodata ".Crc_Cfg_data"
#endif
#ifdef CRC_STOP_SEC_CONFIG_DATA_8
    #ifdef ENTERED_CRC_START_SEC_CONFIG_DATA_8
        #undef ENTERED_CRC_START_SEC_CONFIG_DATA_8
    #else
        #error Crc_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CRC_STOP_SEC_CONFIG_DATA_8
    #undef MEMMAP_ERROR
        #pragma GCC section rodata "default"
#endif


#ifdef CRC_START_SEC_CONFIG_DATA_16
    #undef CRC_START_SEC_CONFIG_DATA_16
    #define ENTERED_CRC_START_SEC_CONFIG_DATA_16
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CRC_STOP_SEC_CONFIG_DATA_16
            #error Crc_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section rodata ".Crc_Cfg_data"
#endif
#ifdef CRC_STOP_SEC_CONFIG_DATA_16
    #ifdef ENTERED_CRC_START_SEC_CONFIG_DATA_16
        #undef ENTERED_CRC_START_SEC_CONFIG_DATA_16
    #else
        #error Crc_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CRC_STOP_SEC_CONFIG_DATA_16
    #undef MEMMAP_ERROR
        #pragma GCC section rodata "default"
#endif


#ifdef CRC_START_SEC_CONFIG_DATA_32
    #undef CRC_START_SEC_CONFIG_DATA_32
    #define ENTERED_CRC_START_SEC_CONFIG_DATA_32
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CRC_STOP_SEC_CONFIG_DATA_32
            #error Crc_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section rodata ".Crc_Cfg_data"
#endif
#ifdef CRC_STOP_SEC_CONFIG_DATA_32
    #ifdef ENTERED_CRC_START_SEC_CONFIG_DATA_32
        #undef ENTERED_CRC_START_SEC_CONFIG_DATA_32
    #else
        #error Crc_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CRC_STOP_SEC_CONFIG_DATA_32
    #undef MEMMAP_ERROR
        #pragma GCC section rodata "default"
#endif


#ifdef CRC_START_SEC_CONFIG_DATA_BOOLEAN
    #undef CRC_START_SEC_CONFIG_DATA_BOOLEAN
    #define ENTERED_CRC_START_SEC_CONFIG_DATA_BOOLEAN
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CRC_STOP_SEC_CONFIG_DATA_BOOLEAN
            #error Crc_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section rodata ".Crc_Cfg_data"
#endif
#ifdef CRC_STOP_SEC_CONFIG_DATA_BOOLEAN
    #ifdef ENTERED_CRC_START_SEC_CONFIG_DATA_BOOLEAN
        #undef ENTERED_CRC_START_SEC_CONFIG_DATA_BOOLEAN
    #else
        #error Crc_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CRC_STOP_SEC_CONFIG_DATA_BOOLEAN
    #undef MEMMAP_ERROR
        #pragma GCC section rodata "default"
#endif


#ifdef CRC_START_SEC_CONFIG_DATA_UNSPECIFIED
    #undef CRC_START_SEC_CONFIG_DATA_UNSPECIFIED
    #define ENTERED_CRC_START_SEC_CONFIG_DATA_UNSPECIFIED
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CRC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
            #error Crc_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section rodata ".Crc_Cfg_data"
#endif
#ifdef CRC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #ifdef ENTERED_CRC_START_SEC_CONFIG_DATA_UNSPECIFIED
        #undef ENTERED_CRC_START_SEC_CONFIG_DATA_UNSPECIFIED
    #else
        #error Crc_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CRC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR
        #pragma GCC section rodata "default"
#endif

/*======================================================================*
*                            Crc                         
*======================================================================*/

#ifdef CRC_START_SEC_CONST
    #undef CRC_START_SEC_CONST
    #define ENTERED_CRC_START_SEC_CONST
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CRC_STOP_SEC_CONST
            #error Crc_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section rodata ".Crc_rodata"
#endif
#ifdef CRC_STOP_SEC_CONST
    #ifdef ENTERED_CRC_START_SEC_CONST
        #undef ENTERED_CRC_START_SEC_CONST
    #else
        #error Crc_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CRC_STOP_SEC_CONST
    #undef MEMMAP_ERROR
    #pragma GCC section rodata "default" 
#endif
/*======================================================================*
*                            Crc                         
*======================================================================*/

#ifdef CRC_START_SEC_VAR_INIT_8
    #undef CRC_START_SEC_VAR_INIT_8
    #define ENTERED_CRC_START_SEC_VAR_INIT_8
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CRC_STOP_SEC_VAR_INIT_8
            #error Crc_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section data ".Crc_data"
#endif
#ifdef CRC_STOP_SEC_VAR_INIT_8
    #ifdef ENTERED_CRC_START_SEC_VAR_INIT_8
        #undef ENTERED_CRC_START_SEC_VAR_INIT_8
    #else
        #error Crc_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CRC_STOP_SEC_VAR_INIT_8
    #undef MEMMAP_ERROR
        #pragma GCC section data "default"
#endif


#ifdef CRC_START_SEC_VAR_INIT_16
    #undef CRC_START_SEC_VAR_INIT_16
    #define ENTERED_CRC_START_SEC_VAR_INIT_16
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CRC_STOP_SEC_VAR_INIT_16
            #error Crc_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section data ".Crc_data"
#endif
#ifdef CRC_STOP_SEC_VAR_INIT_16
    #ifdef ENTERED_CRC_START_SEC_VAR_INIT_16
        #undef ENTERED_CRC_START_SEC_VAR_INIT_16
    #else
        #error Crc_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CRC_STOP_SEC_VAR_INIT_16
    #undef MEMMAP_ERROR
        #pragma GCC section data "default"
#endif


#ifdef CRC_START_SEC_VAR_INIT_32
    #undef CRC_START_SEC_VAR_INIT_32
    #define ENTERED_CRC_START_SEC_VAR_INIT_32
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CRC_STOP_SEC_VAR_INIT_32
            #error Crc_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section data ".Crc_data"
#endif
#ifdef CRC_STOP_SEC_VAR_INIT_32
    #ifdef ENTERED_CRC_START_SEC_VAR_INIT_32
        #undef ENTERED_CRC_START_SEC_VAR_INIT_32
    #else
        #error Crc_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CRC_STOP_SEC_VAR_INIT_32
    #undef MEMMAP_ERROR
        #pragma GCC section data "default"
#endif


#ifdef CRC_START_SEC_VAR_INIT_BOOLEAN
    #undef CRC_START_SEC_VAR_INIT_BOOLEAN
    #define ENTERED_CRC_START_SEC_VAR_INIT_BOOLEAN
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CRC_STOP_SEC_VAR_INIT_BOOLEAN
            #error Crc_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section data ".Crc_data"
#endif
#ifdef CRC_STOP_SEC_VAR_INIT_BOOLEAN
    #ifdef ENTERED_CRC_START_SEC_VAR_INIT_BOOLEAN
        #undef ENTERED_CRC_START_SEC_VAR_INIT_BOOLEAN
    #else
        #error Crc_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CRC_STOP_SEC_VAR_INIT_BOOLEAN
    #undef MEMMAP_ERROR
        #pragma GCC section data "default"
#endif


#ifdef CRC_START_SEC_VAR_INIT_UNSPECIFIED
    #undef CRC_START_SEC_VAR_INIT_UNSPECIFIED
    #define ENTERED_CRC_START_SEC_VAR_INIT_UNSPECIFIED
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CRC_STOP_SEC_VAR_INIT_UNSPECIFIED
            #error Crc_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section data ".Crc_data"
#endif
#ifdef CRC_STOP_SEC_VAR_INIT_UNSPECIFIED
    #ifdef ENTERED_CRC_START_SEC_VAR_INIT_UNSPECIFIED
        #undef ENTERED_CRC_START_SEC_VAR_INIT_UNSPECIFIED
    #else
        #error Crc_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CRC_STOP_SEC_VAR_INIT_UNSPECIFIED
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
#endif
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


