/**
 * @file        Com_MemMap.h
 * @brief       AUTOSAR Com_MemMap - Com_MemMap driver header file.
 * @details     Com_MemMap driver header file, containing the Autosar API specification and
 *               other variables and functions that are exported by the Com_MemMap driver.
 * @version     1.2.0
 *
 * @addtogroup  Com_MemMap
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
extern "C"{
#endif

/*====================================================================================================*
 *                                           INCLUDE FILES                                          
 *====================================================================================================*/


/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION                                 
 *====================================================================================================*/

#define COM_MEMMAP_VENDOR_ID                      0U
#define COM_MEMMAP_AR_RELEASE_MAJOR_VERSION       4U
#define COM_MEMMAP_AR_RELEASE_MINOR_VERSION       2U
#define COM_MEMMAP_AR_RELEASE_REVISION_VERSION    2U
#define COM_MEMMAP_SW_MAJOR_VERSION               1U
#define COM_MEMMAP_SW_MINOR_VERSION               2U
#define COM_MEMMAP_SW_PATCH_VERSION               0U

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
*                            Com                         
*======================================================================*/

#ifdef COM_START_SEC_VAR_NO_INIT_8
    #undef COM_START_SEC_VAR_NO_INIT_8
    #define ENTERED_COM_START_SEC_VAR_NO_INIT_8
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef COM_STOP_SEC_VAR_NO_INIT_8
            #error Com_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section bss ".Com_bss"
#endif
#ifdef COM_STOP_SEC_VAR_NO_INIT_8
    #ifdef ENTERED_COM_START_SEC_VAR_NO_INIT_8
        #undef ENTERED_COM_START_SEC_VAR_NO_INIT_8
    #else
        #error Com_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef COM_STOP_SEC_VAR_NO_INIT_8
    #undef MEMMAP_ERROR
        #pragma GCC section bss "default"
#endif


#ifdef COM_START_SEC_VAR_NO_INIT_16
    #undef COM_START_SEC_VAR_NO_INIT_16
    #define ENTERED_COM_START_SEC_VAR_NO_INIT_16
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef COM_STOP_SEC_VAR_NO_INIT_16
            #error Com_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section bss ".Com_bss"
#endif
#ifdef COM_STOP_SEC_VAR_NO_INIT_16
    #ifdef ENTERED_COM_START_SEC_VAR_NO_INIT_16
        #undef ENTERED_COM_START_SEC_VAR_NO_INIT_16
    #else
        #error Com_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef COM_STOP_SEC_VAR_NO_INIT_16
    #undef MEMMAP_ERROR
        #pragma GCC section bss "default"
#endif


#ifdef COM_START_SEC_VAR_NO_INIT_32
    #undef COM_START_SEC_VAR_NO_INIT_32
    #define ENTERED_COM_START_SEC_VAR_NO_INIT_32
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef COM_STOP_SEC_VAR_NO_INIT_32
            #error Com_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section bss ".Com_bss"
#endif
#ifdef COM_STOP_SEC_VAR_NO_INIT_32
    #ifdef ENTERED_COM_START_SEC_VAR_NO_INIT_32
        #undef ENTERED_COM_START_SEC_VAR_NO_INIT_32
    #else
        #error Com_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef COM_STOP_SEC_VAR_NO_INIT_32
    #undef MEMMAP_ERROR
        #pragma GCC section bss "default"
#endif


#ifdef COM_START_SEC_VAR_NO_INIT_BOOLEAN
    #undef COM_START_SEC_VAR_NO_INIT_BOOLEAN
    #define ENTERED_COM_START_SEC_VAR_NO_INIT_BOOLEAN
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef COM_STOP_SEC_VAR_NO_INIT_BOOLEAN
            #error Com_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section bss ".Com_bss"
#endif
#ifdef COM_STOP_SEC_VAR_NO_INIT_BOOLEAN
    #ifdef ENTERED_COM_START_SEC_VAR_NO_INIT_BOOLEAN
        #undef ENTERED_COM_START_SEC_VAR_NO_INIT_BOOLEAN
    #else
        #error Com_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef COM_STOP_SEC_VAR_NO_INIT_BOOLEAN
    #undef MEMMAP_ERROR
        #pragma GCC section bss "default"
#endif


#ifdef COM_START_SEC_VAR_NO_INIT_UNSPECIFIED
    #undef COM_START_SEC_VAR_NO_INIT_UNSPECIFIED
    #define ENTERED_COM_START_SEC_VAR_NO_INIT_UNSPECIFIED
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef COM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
            #error Com_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section bss ".Com_bss"
#endif
#ifdef COM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    #ifdef ENTERED_COM_START_SEC_VAR_NO_INIT_UNSPECIFIED
        #undef ENTERED_COM_START_SEC_VAR_NO_INIT_UNSPECIFIED
    #else
        #error Com_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef COM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR
        #pragma GCC section bss "default"
#endif

/*======================================================================*
*                            Com                         
*======================================================================*/

#ifdef COM_START_SEC_CODE
    #undef COM_START_SEC_CODE
    #define ENTERED_COM_START_SEC_CODE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef COM_STOP_SEC_CODE
            #error Com_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section text ".Com_text"
#endif
#ifdef COM_STOP_SEC_CODE
    #ifdef ENTERED_COM_START_SEC_CODE
        #undef ENTERED_COM_START_SEC_CODE
    #else
        #error Com_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef COM_STOP_SEC_CODE
    #undef MEMMAP_ERROR
    #pragma GCC section text "default" 
#endif
/*======================================================================*
*                            Com                         
*======================================================================*/

#ifdef COM_START_SEC_CONFIG_DATA_8
    #undef COM_START_SEC_CONFIG_DATA_8
    #define ENTERED_COM_START_SEC_CONFIG_DATA_8
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef COM_STOP_SEC_CONFIG_DATA_8
            #error Com_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section rodata ".Com_Cfg_data"
#endif
#ifdef COM_STOP_SEC_CONFIG_DATA_8
    #ifdef ENTERED_COM_START_SEC_CONFIG_DATA_8
        #undef ENTERED_COM_START_SEC_CONFIG_DATA_8
    #else
        #error Com_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef COM_STOP_SEC_CONFIG_DATA_8
    #undef MEMMAP_ERROR
        #pragma GCC section rodata "default"
#endif


#ifdef COM_START_SEC_CONFIG_DATA_16
    #undef COM_START_SEC_CONFIG_DATA_16
    #define ENTERED_COM_START_SEC_CONFIG_DATA_16
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef COM_STOP_SEC_CONFIG_DATA_16
            #error Com_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section rodata ".Com_Cfg_data"
#endif
#ifdef COM_STOP_SEC_CONFIG_DATA_16
    #ifdef ENTERED_COM_START_SEC_CONFIG_DATA_16
        #undef ENTERED_COM_START_SEC_CONFIG_DATA_16
    #else
        #error Com_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef COM_STOP_SEC_CONFIG_DATA_16
    #undef MEMMAP_ERROR
        #pragma GCC section rodata "default"
#endif


#ifdef COM_START_SEC_CONFIG_DATA_32
    #undef COM_START_SEC_CONFIG_DATA_32
    #define ENTERED_COM_START_SEC_CONFIG_DATA_32
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef COM_STOP_SEC_CONFIG_DATA_32
            #error Com_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section rodata ".Com_Cfg_data"
#endif
#ifdef COM_STOP_SEC_CONFIG_DATA_32
    #ifdef ENTERED_COM_START_SEC_CONFIG_DATA_32
        #undef ENTERED_COM_START_SEC_CONFIG_DATA_32
    #else
        #error Com_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef COM_STOP_SEC_CONFIG_DATA_32
    #undef MEMMAP_ERROR
        #pragma GCC section rodata "default"
#endif


#ifdef COM_START_SEC_CONFIG_DATA_BOOLEAN
    #undef COM_START_SEC_CONFIG_DATA_BOOLEAN
    #define ENTERED_COM_START_SEC_CONFIG_DATA_BOOLEAN
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef COM_STOP_SEC_CONFIG_DATA_BOOLEAN
            #error Com_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section rodata ".Com_Cfg_data"
#endif
#ifdef COM_STOP_SEC_CONFIG_DATA_BOOLEAN
    #ifdef ENTERED_COM_START_SEC_CONFIG_DATA_BOOLEAN
        #undef ENTERED_COM_START_SEC_CONFIG_DATA_BOOLEAN
    #else
        #error Com_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef COM_STOP_SEC_CONFIG_DATA_BOOLEAN
    #undef MEMMAP_ERROR
        #pragma GCC section rodata "default"
#endif


#ifdef COM_START_SEC_CONFIG_DATA_UNSPECIFIED
    #undef COM_START_SEC_CONFIG_DATA_UNSPECIFIED
    #define ENTERED_COM_START_SEC_CONFIG_DATA_UNSPECIFIED
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
            #error Com_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section rodata ".Com_Cfg_data"
#endif
#ifdef COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #ifdef ENTERED_COM_START_SEC_CONFIG_DATA_UNSPECIFIED
        #undef ENTERED_COM_START_SEC_CONFIG_DATA_UNSPECIFIED
    #else
        #error Com_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR
        #pragma GCC section rodata "default"
#endif

/*======================================================================*
*                            Com                         
*======================================================================*/

#ifdef COM_START_SEC_CONST
    #undef COM_START_SEC_CONST
    #define ENTERED_COM_START_SEC_CONST
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef COM_STOP_SEC_CONST
            #error Com_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section rodata ".Com_rodata"
#endif
#ifdef COM_STOP_SEC_CONST
    #ifdef ENTERED_COM_START_SEC_CONST
        #undef ENTERED_COM_START_SEC_CONST
    #else
        #error Com_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef COM_STOP_SEC_CONST
    #undef MEMMAP_ERROR
    #pragma GCC section rodata "default" 
#endif
/*======================================================================*
*                            Com                         
*======================================================================*/

#ifdef COM_START_SEC_VAR_INIT_8
    #undef COM_START_SEC_VAR_INIT_8
    #define ENTERED_COM_START_SEC_VAR_INIT_8
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef COM_STOP_SEC_VAR_INIT_8
            #error Com_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section data ".Com_data"
#endif
#ifdef COM_STOP_SEC_VAR_INIT_8
    #ifdef ENTERED_COM_START_SEC_VAR_INIT_8
        #undef ENTERED_COM_START_SEC_VAR_INIT_8
    #else
        #error Com_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef COM_STOP_SEC_VAR_INIT_8
    #undef MEMMAP_ERROR
        #pragma GCC section data "default"
#endif


#ifdef COM_START_SEC_VAR_INIT_16
    #undef COM_START_SEC_VAR_INIT_16
    #define ENTERED_COM_START_SEC_VAR_INIT_16
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef COM_STOP_SEC_VAR_INIT_16
            #error Com_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section data ".Com_data"
#endif
#ifdef COM_STOP_SEC_VAR_INIT_16
    #ifdef ENTERED_COM_START_SEC_VAR_INIT_16
        #undef ENTERED_COM_START_SEC_VAR_INIT_16
    #else
        #error Com_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef COM_STOP_SEC_VAR_INIT_16
    #undef MEMMAP_ERROR
        #pragma GCC section data "default"
#endif


#ifdef COM_START_SEC_VAR_INIT_32
    #undef COM_START_SEC_VAR_INIT_32
    #define ENTERED_COM_START_SEC_VAR_INIT_32
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef COM_STOP_SEC_VAR_INIT_32
            #error Com_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section data ".Com_data"
#endif
#ifdef COM_STOP_SEC_VAR_INIT_32
    #ifdef ENTERED_COM_START_SEC_VAR_INIT_32
        #undef ENTERED_COM_START_SEC_VAR_INIT_32
    #else
        #error Com_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef COM_STOP_SEC_VAR_INIT_32
    #undef MEMMAP_ERROR
        #pragma GCC section data "default"
#endif


#ifdef COM_START_SEC_VAR_INIT_BOOLEAN
    #undef COM_START_SEC_VAR_INIT_BOOLEAN
    #define ENTERED_COM_START_SEC_VAR_INIT_BOOLEAN
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef COM_STOP_SEC_VAR_INIT_BOOLEAN
            #error Com_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section data ".Com_data"
#endif
#ifdef COM_STOP_SEC_VAR_INIT_BOOLEAN
    #ifdef ENTERED_COM_START_SEC_VAR_INIT_BOOLEAN
        #undef ENTERED_COM_START_SEC_VAR_INIT_BOOLEAN
    #else
        #error Com_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef COM_STOP_SEC_VAR_INIT_BOOLEAN
    #undef MEMMAP_ERROR
        #pragma GCC section data "default"
#endif


#ifdef COM_START_SEC_VAR_INIT_UNSPECIFIED
    #undef COM_START_SEC_VAR_INIT_UNSPECIFIED
    #define ENTERED_COM_START_SEC_VAR_INIT_UNSPECIFIED
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef COM_STOP_SEC_VAR_INIT_UNSPECIFIED
            #error Com_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEMMAP_ERROR
        #pragma GCC section data ".Com_data"
#endif
#ifdef COM_STOP_SEC_VAR_INIT_UNSPECIFIED
    #ifdef ENTERED_COM_START_SEC_VAR_INIT_UNSPECIFIED
        #undef ENTERED_COM_START_SEC_VAR_INIT_UNSPECIFIED
    #else
        #error Com_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef COM_STOP_SEC_VAR_INIT_UNSPECIFIED
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


