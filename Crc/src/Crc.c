/**
 * @file        Crc.c
 * @brief       AUTOSAR Crc  - Crc driver source file.
 * @details     Crc driver source file, containing the C implementation of Autosar API specification
 *              and other variables and functions that are exported by the Crc driver.
 * @version     1.2.0
 *
 * @addtogroup  CRC
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

/* PRQA S 0292, 0288, 1503, 1505, 0857, 0791, 0828, 0647 EOF #
 *
 * 1.0292 -- Violates MISRA 2004 Required Rule 3.1, Source file has comments containing one of the
 * characters '$', '@' or '`'.
 *
 * 2.0288 -- Violates MISRA 2004 Required Rule 3.1, Source file has comments containing characters
 * which are not members of the basic source character set.
 *
 * 3.1503 -- Violates MISRA 2004 Required Rule 14.1, The function is defined but is not used within
 * this project.
 *
 * 4.1505 -- Violates MISRA 2004 Required Rule 8.10, The function is only referenced in the translation
 * unit where it is defined.
 *
 * 5.0857 -- Violates MISRA 2004 Required Rule 1.1, Number of macro definitions exceeds 1024 - program
 * does not conform strictly to ISO:C90.
 *
 * 6.0791 -- Violates MISRA 2004 Required Rule 5.1, Macro identifier does not differ from other macro
 * identifier(s) within the specified number of significant characters.
 *
 * 7.0828 -- Violates MISRA 2004 Required Rule 1.1, More than 8 levels of nested conditional inclusion
 * - program does not conform strictly to ISO:C90.
 *
 * 8.0647 -- Violates MISRA 2004 Required Rule 1.1, Number of enumeration constants exceeds 127 -
 * program does not conform strictly to ISO:C90.
 *
 * @page misra_violations MISRA-C:2004 violations
 */

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
#include "Crc.h"
/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION
 *====================================================================================================*/
#define CRC_VENDOR_ID_C                         0U
#define CRC_AR_RELEASE_MAJOR_VERSION_C          4U
#define CRC_AR_RELEASE_MINOR_VERSION_C          2U
#define CRC_AR_RELEASE_REVISION_VERSION_C       2U
#define CRC_SW_MAJOR_VERSION_C                  1U
#define CRC_SW_MINOR_VERSION_C                  2U
#define CRC_SW_PATCH_VERSION_C                  0U
/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Crc header file are of the same vendor */
#if(CRC_VENDOR_ID_C != CRC_VENDOR_ID )
#error "Crc.c and Crc.h have different vendor id"
#endif
/* Check if current file and Crc header file are of the same Autosar version */
#if(\
		(CRC_AR_RELEASE_MAJOR_VERSION_C != CRC_AR_RELEASE_MAJOR_VERSION) || \
		(CRC_AR_RELEASE_MINOR_VERSION_C != CRC_AR_RELEASE_MINOR_VERSION) || \
		(CRC_AR_RELEASE_REVISION_VERSION_C != CRC_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of Crc.c and Crc.h are different "
#endif
/* Check if current file and Crc header file are of the same Software version */
#if(\
		(CRC_SW_MAJOR_VERSION_C != CRC_SW_MAJOR_VERSION) || \
		(CRC_SW_MINOR_VERSION_C != CRC_SW_MINOR_VERSION) || \
		(CRC_SW_PATCH_VERSION_C != CRC_SW_PATCH_VERSION) \
	)
#error "Software Version Number of Crc.c and Crc.h are different "
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
/**
 * @req [SWS_Crc_00030] The Crc_CalculateCRC8() function of the CRC module shall
 *      implement the CRC8 routine based on the SAE-J1850 CRC8 Standard
 */
/* @brief CRC8 J1850 Standard XOR value*/
#define CRC_XOR_VALUE_8 		0xFFu
/* @brief CRC8 J1850 Standard Init value*/
#define CRC_INITIAL_VALUE_8 	0xFFu
/* @brief CRC8 J1850 Standard Generator Polynomial*/
#define CRC_POLYNOMIAL_8 		0x1Du

/**
 * @req [SWS_Crc_00042] The Crc_CalculateCRC8H2F() function of the CRC module shall
 *      implement the CRC8 routine based on the generator polynomial 0x2F
 */
/* @brief CRC8 0x2F polynomial XOR value*/
#define CRC_XOR_VALUE_8H2F 		0xFFu
/* @brief CRC8 0x2F polynomial Init value*/
#define CRC_INITIAL_VALUE_8H2F 	0xFFu
/* @brief CRC8 0x2F Generator Polynomial*/
#define CRC_POLYNOMIAL_8H2F 	0x2Fu

/**
 * @req [SWS_Crc_00002] The CRC module shall implement the CRC16 routine based on
 *      the CCITT-FALSE CRC16 Standard
 */
/* @brief CRC16 Init value*/
#define CRC_INITIAL_VALUE_16 	0xFFFFu
/* CRC16 XOR value*/
#define CRC_XOR_VALUE_16 		0x0u
/* @brief CRC16 CCITT-FALSE Standard Generator Polynomial*/
#define CRC_POLYNOMIAL_16 		0x1021u

/**
 * @req [SWS_Crc_00003] The CRC module shall implement the CRC32 routine based on
 *      the IEEE-802.3 CRC32 Ethernet Standard
 */
/* @brief CRC32 Ethernet Standard Init value*/
#define CRC_INITIAL_VALUE_32 	0xFFFFFFFFu
/* @brief CRC32 Ethernet Standard XOR value*/
#define CRC_XOR_VALUE_32 		0xFFFFFFFFu
/* @brief CRC32 Ethernet Standard Generator Polynomial*/
#define CRC_POLYNOMIAL_32 		0x04C11DB7u

/**
 * @req [SWS_Crc_00056] The CRC module shall implement the CRC32 routine using the
 *      0x1'F4'AC'FB'13 (0xF4'AC'FB'13) polynomial:
 */
/* @brief CRC32 Init value*/
#define CRC_INITIAL_VALUE_32P4 	0xFFFFFFFFu
/* @brief CRC32 XOR value*/
#define CRC_XOR_VALUE_32P4 		0xFFFFFFFFu
/* @brief CRC32 Generator Polynomial*/
#define CRC_POLYNOMIAL_32P4 	0xF4ACFB13u

/* @brief Unit test Macro */
#ifdef	AH_UNITTEST_ENABLED
#define STATIC
#else
#define STATIC static
#endif

/*====================================================================================================*
 *                                           LOCAL CONSTANTS
 *====================================================================================================*/
#if((STD_ON == CRC8_ALGORITHM) && (CRC_TABLE == CRC_8_MODE))
CONST(uint8, CRC_CONST)
Crc_8Table[256] =
{
    0x00u, 0x1du, 0x3au, 0x27u, 0x74u, 0x69u, 0x4eu, 0x53u,
    0xe8u, 0xf5u, 0xd2u, 0xcfu, 0x9cu, 0x81u, 0xa6u, 0xbbu,
    0xcdu, 0xd0u, 0xf7u, 0xeau, 0xb9u, 0xa4u, 0x83u, 0x9eu,
    0x25u, 0x38u, 0x1fu, 0x02u, 0x51u, 0x4cu, 0x6bu, 0x76u,
    0x87u, 0x9au, 0xbdu, 0xa0u, 0xf3u, 0xeeu, 0xc9u, 0xd4u,
    0x6fu, 0x72u, 0x55u, 0x48u, 0x1bu, 0x06u, 0x21u, 0x3cu,
    0x4au, 0x57u, 0x70u, 0x6du, 0x3eu, 0x23u, 0x04u, 0x19u,
    0xa2u, 0xbfu, 0x98u, 0x85u, 0xd6u, 0xcbu, 0xecu, 0xf1u,
    0x13u, 0x0eu, 0x29u, 0x34u, 0x67u, 0x7au, 0x5du, 0x40u,
    0xfbu, 0xe6u, 0xc1u, 0xdcu, 0x8fu, 0x92u, 0xb5u, 0xa8u,
    0xdeu, 0xc3u, 0xe4u, 0xf9u, 0xaau, 0xb7u, 0x90u, 0x8du,
    0x36u, 0x2bu, 0x0cu, 0x11u, 0x42u, 0x5fu, 0x78u, 0x65u,
    0x94u, 0x89u, 0xaeu, 0xb3u, 0xe0u, 0xfdu, 0xdau, 0xc7u,
    0x7cu, 0x61u, 0x46u, 0x5bu, 0x08u, 0x15u, 0x32u, 0x2fu,
    0x59u, 0x44u, 0x63u, 0x7eu, 0x2du, 0x30u, 0x17u, 0x0au,
    0xb1u, 0xacu, 0x8bu, 0x96u, 0xc5u, 0xd8u, 0xffu, 0xe2u,
    0x26u, 0x3bu, 0x1cu, 0x01u, 0x52u, 0x4fu, 0x68u, 0x75u,
    0xceu, 0xd3u, 0xf4u, 0xe9u, 0xbau, 0xa7u, 0x80u, 0x9du,
    0xebu, 0xf6u, 0xd1u, 0xccu, 0x9fu, 0x82u, 0xa5u, 0xb8u,
    0x03u, 0x1eu, 0x39u, 0x24u, 0x77u, 0x6au, 0x4du, 0x50u,
    0xa1u, 0xbcu, 0x9bu, 0x86u, 0xd5u, 0xc8u, 0xefu, 0xf2u,
    0x49u, 0x54u, 0x73u, 0x6eu, 0x3du, 0x20u, 0x07u, 0x1au,
    0x6cu, 0x71u, 0x56u, 0x4bu, 0x18u, 0x05u, 0x22u, 0x3fu,
    0x84u, 0x99u, 0xbeu, 0xa3u, 0xf0u, 0xedu, 0xcau, 0xd7u,
    0x35u, 0x28u, 0x0fu, 0x12u, 0x41u, 0x5cu, 0x7bu, 0x66u,
    0xddu, 0xc0u, 0xe7u, 0xfau, 0xa9u, 0xb4u, 0x93u, 0x8eu,
    0xf8u, 0xe5u, 0xc2u, 0xdfu, 0x8cu, 0x91u, 0xb6u, 0xabu,
    0x10u, 0x0du, 0x2au, 0x37u, 0x64u, 0x79u, 0x5eu, 0x43u,
    0xb2u, 0xafu, 0x88u, 0x95u, 0xc6u, 0xdbu, 0xfcu, 0xe1u,
    0x5au, 0x47u, 0x60u, 0x7du, 0x2eu, 0x33u, 0x14u, 0x09u,
    0x7fu, 0x62u, 0x45u, 0x58u, 0x0bu, 0x16u, 0x31u, 0x2cu,
    0x97u, 0x8au, 0xadu, 0xb0u, 0xe3u, 0xfeu, 0xd9u, 0xc4u
};
#endif

#if((STD_ON == CRC8H2F_ALGORITHM) && (CRC_TABLE == CRC_8H2F_MODE))
CONST(uint8, CRC_CONST)
Crc_8H2FTable[256] =
{
	0x0u,   0x2fu,  0x5eu,  0x71u,  0xbcu,  0x93u,  0xe2u,  0xcdu,
	0x57u,  0x78u,  0x9u,   0x26u,  0xebu,  0xc4u,  0xb5u,  0x9au,
	0xaeu,  0x81u,  0xf0u,  0xdfu,  0x12u,  0x3du,  0x4cu,  0x63u,
	0xf9u,  0xd6u,  0xa7u,  0x88u,  0x45u,  0x6au,  0x1bu,  0x34u,
	0x73u,  0x5cu,  0x2du,  0x2u,   0xcfu,  0xe0u,  0x91u,  0xbeu,
	0x24u,  0xbu,   0x7au,  0x55u,  0x98u,  0xb7u,  0xc6u,  0xe9u,
	0xddu,  0xf2u,  0x83u,  0xacu,  0x61u,  0x4eu,  0x3fu,  0x10u,
	0x8au,  0xa5u,  0xd4u,  0xfbu,  0x36u,  0x19u,  0x68u,  0x47u,
	0xe6u,  0xc9u,  0xb8u,  0x97u,  0x5au,  0x75u,  0x4u,   0x2bu,
	0xb1u,  0x9eu,  0xefu,  0xc0u,  0xdu,   0x22u,  0x53u,  0x7cu,
	0x48u,  0x67u,  0x16u,  0x39u,  0xf4u,  0xdbu,  0xaau,  0x85u,
	0x1fu,  0x30u,  0x41u,  0x6eu,  0xa3u,  0x8cu,  0xfdu,  0xd2u,
	0x95u,  0xbau,  0xcbu,  0xe4u,  0x29u,  0x6u,   0x77u,  0x58u,
	0xc2u,  0xedu,  0x9cu,  0xb3u,  0x7eu,  0x51u,  0x20u,  0xfu,
	0x3bu,  0x14u,  0x65u,  0x4au,  0x87u,  0xa8u,  0xd9u,  0xf6u,
	0x6cu,  0x43u,  0x32u,  0x1du,  0xd0u,  0xffu,  0x8eu,  0xa1u,
	0xe3u,  0xccu,  0xbdu,  0x92u,  0x5fu,  0x70u,  0x1u,   0x2eu,
	0xb4u,  0x9bu,  0xeau,  0xc5u,  0x8u,   0x27u,  0x56u,  0x79u,
	0x4du,  0x62u,  0x13u,  0x3cu,  0xf1u,  0xdeu,  0xafu,  0x80u,
	0x1au,  0x35u,  0x44u,  0x6bu,  0xa6u,  0x89u,  0xf8u,  0xd7u,
	0x90u,  0xbfu,  0xceu,  0xe1u,  0x2cu,  0x3u,   0x72u,  0x5du,
	0xc7u,  0xe8u,  0x99u,  0xb6u,  0x7bu,  0x54u,  0x25u,  0xau,
	0x3eu,  0x11u,  0x60u,  0x4fu,  0x82u,  0xadu,  0xdcu,  0xf3u,
	0x69u,  0x46u,  0x37u,  0x18u,  0xd5u,  0xfau,  0x8bu,  0xa4u,
	0x5u,   0x2au,  0x5bu,  0x74u,  0xb9u,  0x96u,  0xe7u,  0xc8u,
	0x52u,  0x7du,  0xcu,   0x23u,  0xeeu,  0xc1u,  0xb0u,  0x9fu,
	0xabu,  0x84u,  0xf5u,  0xdau,  0x17u,  0x38u,  0x49u,  0x66u,
	0xfcu,  0xd3u,  0xa2u,  0x8du,  0x40u,  0x6fu,  0x1eu,  0x31u,
	0x76u,  0x59u,  0x28u,  0x7u,   0xcau,  0xe5u,  0x94u,  0xbbu,
	0x21u,  0xeu,   0x7fu,  0x50u,  0x9du,  0xb2u,  0xc3u,  0xecu,
	0xd8u,  0xf7u,  0x86u,  0xa9u,  0x64u,  0x4bu,  0x3au,  0x15u,
	0x8fu,  0xa0u,  0xd1u,  0xfeu,  0x33u,  0x1cu,  0x6du,  0x42u
};
#endif

#if((STD_ON == CRC16_ALGORITHM) && (CRC_TABLE == CRC_16_MODE))
CONST(uint16, CRC_CONST)
Crc_16Table[256] =
{
    0x0000u, 0x1021u, 0x2042u, 0x3063u, 0x4084u, 0x50a5u, 0x60c6u, 0x70e7u,
    0x8108u, 0x9129u, 0xa14au, 0xb16bu, 0xc18cu, 0xd1adu, 0xe1ceu, 0xf1efu,
    0x1231u, 0x0210u, 0x3273u, 0x2252u, 0x52b5u, 0x4294u, 0x72f7u, 0x62d6u,
    0x9339u, 0x8318u, 0xb37bu, 0xa35au, 0xd3bdu, 0xc39cu, 0xf3ffu, 0xe3deu,
    0x2462u, 0x3443u, 0x0420u, 0x1401u, 0x64e6u, 0x74c7u, 0x44a4u, 0x5485u,
    0xa56au, 0xb54bu, 0x8528u, 0x9509u, 0xe5eeu, 0xf5cfu, 0xc5acu, 0xd58du,
    0x3653u, 0x2672u, 0x1611u, 0x0630u, 0x76d7u, 0x66f6u, 0x5695u, 0x46b4u,
    0xb75bu, 0xa77au, 0x9719u, 0x8738u, 0xf7dfu, 0xe7feu, 0xd79du, 0xc7bcu,
    0x48c4u, 0x58e5u, 0x6886u, 0x78a7u, 0x0840u, 0x1861u, 0x2802u, 0x3823u,
    0xc9ccu, 0xd9edu, 0xe98eu, 0xf9afu, 0x8948u, 0x9969u, 0xa90au, 0xb92bu,
    0x5af5u, 0x4ad4u, 0x7ab7u, 0x6a96u, 0x1a71u, 0x0a50u, 0x3a33u, 0x2a12u,
    0xdbfdu, 0xcbdcu, 0xfbbfu, 0xeb9eu, 0x9b79u, 0x8b58u, 0xbb3bu, 0xab1au,
    0x6ca6u, 0x7c87u, 0x4ce4u, 0x5cc5u, 0x2c22u, 0x3c03u, 0x0c60u, 0x1c41u,
    0xedaeu, 0xfd8fu, 0xcdecu, 0xddcdu, 0xad2au, 0xbd0bu, 0x8d68u, 0x9d49u,
    0x7e97u, 0x6eb6u, 0x5ed5u, 0x4ef4u, 0x3e13u, 0x2e32u, 0x1e51u, 0x0e70u,
    0xff9fu, 0xefbeu, 0xdfddu, 0xcffcu, 0xbf1bu, 0xaf3au, 0x9f59u, 0x8f78u,
    0x9188u, 0x81a9u, 0xb1cau, 0xa1ebu, 0xd10cu, 0xc12du, 0xf14eu, 0xe16fu,
    0x1080u, 0x00a1u, 0x30c2u, 0x20e3u, 0x5004u, 0x4025u, 0x7046u, 0x6067u,
    0x83b9u, 0x9398u, 0xa3fbu, 0xb3dau, 0xc33du, 0xd31cu, 0xe37fu, 0xf35eu,
    0x02b1u, 0x1290u, 0x22f3u, 0x32d2u, 0x4235u, 0x5214u, 0x6277u, 0x7256u,
    0xb5eau, 0xa5cbu, 0x95a8u, 0x8589u, 0xf56eu, 0xe54fu, 0xd52cu, 0xc50du,
    0x34e2u, 0x24c3u, 0x14a0u, 0x0481u, 0x7466u, 0x6447u, 0x5424u, 0x4405u,
    0xa7dbu, 0xb7fau, 0x8799u, 0x97b8u, 0xe75fu, 0xf77eu, 0xc71du, 0xd73cu,
    0x26d3u, 0x36f2u, 0x0691u, 0x16b0u, 0x6657u, 0x7676u, 0x4615u, 0x5634u,
    0xd94cu, 0xc96du, 0xf90eu, 0xe92fu, 0x99c8u, 0x89e9u, 0xb98au, 0xa9abu,
    0x5844u, 0x4865u, 0x7806u, 0x6827u, 0x18c0u, 0x08e1u, 0x3882u, 0x28a3u,
    0xcb7du, 0xdb5cu, 0xeb3fu, 0xfb1eu, 0x8bf9u, 0x9bd8u, 0xabbbu, 0xbb9au,
    0x4a75u, 0x5a54u, 0x6a37u, 0x7a16u, 0x0af1u, 0x1ad0u, 0x2ab3u, 0x3a92u,
    0xfd2eu, 0xed0fu, 0xdd6cu, 0xcd4du, 0xbdaau, 0xad8bu, 0x9de8u, 0x8dc9u,
    0x7c26u, 0x6c07u, 0x5c64u, 0x4c45u, 0x3ca2u, 0x2c83u, 0x1ce0u, 0x0cc1u,
    0xef1fu, 0xff3eu, 0xcf5du, 0xdf7cu, 0xaf9bu, 0xbfbau, 0x8fd9u, 0x9ff8u,
    0x6e17u, 0x7e36u, 0x4e55u, 0x5e74u, 0x2e93u, 0x3eb2u, 0x0ed1u, 0x1ef0u
};
#endif
#if((STD_ON == CRC32_ALGORITHM) && (CRC_TABLE == CRC_32_MODE))
CONST(uint32, CRC_CONST)
Crc_32Table[256] =
{
    0x00000000uL, 0x77073096uL, 0xee0e612cuL, 0x990951bauL, 0x076dc419uL, 0x706af48fuL, 0xe963a535uL,
	0x9e6495a3uL, 0x0edb8832uL, 0x79dcb8a4uL, 0xe0d5e91euL, 0x97d2d988uL, 0x09b64c2buL, 0x7eb17cbduL,
	0xe7b82d07uL, 0x90bf1d91uL, 0x1db71064uL, 0x6ab020f2uL, 0xf3b97148uL, 0x84be41deuL, 0x1adad47duL,
	0x6ddde4ebuL, 0xf4d4b551uL, 0x83d385c7uL, 0x136c9856uL, 0x646ba8c0uL, 0xfd62f97auL, 0x8a65c9ecuL,
	0x14015c4fuL, 0x63066cd9uL, 0xfa0f3d63uL, 0x8d080df5uL, 0x3b6e20c8uL, 0x4c69105euL, 0xd56041e4uL,
	0xa2677172uL, 0x3c03e4d1uL, 0x4b04d447uL, 0xd20d85fduL, 0xa50ab56buL, 0x35b5a8fauL, 0x42b2986cuL,
	0xdbbbc9d6uL, 0xacbcf940uL, 0x32d86ce3uL, 0x45df5c75uL, 0xdcd60dcfuL, 0xabd13d59uL, 0x26d930acuL,
	0x51de003auL, 0xc8d75180uL, 0xbfd06116uL, 0x21b4f4b5uL, 0x56b3c423uL, 0xcfba9599uL, 0xb8bda50fuL,
    0x2802b89euL, 0x5f058808uL, 0xc60cd9b2uL, 0xb10be924uL, 0x2f6f7c87uL, 0x58684c11uL, 0xc1611dabuL,
	0xb6662d3duL, 0x76dc4190uL, 0x01db7106uL, 0x98d220bcuL, 0xefd5102auL, 0x71b18589uL, 0x06b6b51fuL,
	0x9fbfe4a5uL, 0xe8b8d433uL, 0x7807c9a2uL, 0x0f00f934uL, 0x9609a88euL, 0xe10e9818uL, 0x7f6a0dbbuL,
	0x086d3d2duL, 0x91646c97uL, 0xe6635c01uL, 0x6b6b51f4uL, 0x1c6c6162uL, 0x856530d8uL, 0xf262004euL,
	0x6c0695eduL, 0x1b01a57buL, 0x8208f4c1uL, 0xf50fc457uL, 0x65b0d9c6uL, 0x12b7e950uL, 0x8bbeb8eauL,
	0xfcb9887cuL, 0x62dd1ddfuL, 0x15da2d49uL, 0x8cd37cf3uL, 0xfbd44c65uL, 0x4db26158uL, 0x3ab551ceuL,
	0xa3bc0074uL, 0xd4bb30e2uL, 0x4adfa541uL, 0x3dd895d7uL, 0xa4d1c46duL, 0xd3d6f4fbuL, 0x4369e96auL,
	0x346ed9fcuL, 0xad678846uL, 0xda60b8d0uL, 0x44042d73uL, 0x33031de5uL, 0xaa0a4c5fuL, 0xdd0d7cc9uL,
    0x5005713cuL, 0x270241aauL, 0xbe0b1010uL, 0xc90c2086uL, 0x5768b525uL, 0x206f85b3uL, 0xb966d409uL,
	0xce61e49fuL, 0x5edef90euL, 0x29d9c998uL, 0xb0d09822uL, 0xc7d7a8b4uL, 0x59b33d17uL, 0x2eb40d81uL,
	0xb7bd5c3buL, 0xc0ba6caduL, 0xedb88320uL, 0x9abfb3b6uL, 0x03b6e20cuL, 0x74b1d29auL, 0xead54739uL,
	0x9dd277afuL, 0x04db2615uL, 0x73dc1683uL, 0xe3630b12uL, 0x94643b84uL, 0x0d6d6a3euL, 0x7a6a5aa8uL,
	0xe40ecf0buL, 0x9309ff9duL, 0x0a00ae27uL, 0x7d079eb1uL, 0xf00f9344uL, 0x8708a3d2uL, 0x1e01f268uL,
	0x6906c2feuL, 0xf762575duL, 0x806567cbuL, 0x196c3671uL, 0x6e6b06e7uL, 0xfed41b76uL, 0x89d32be0uL,
	0x10da7a5auL, 0x67dd4accuL, 0xf9b9df6fuL, 0x8ebeeff9uL, 0x17b7be43uL, 0x60b08ed5uL, 0xd6d6a3e8uL,
	0xa1d1937euL, 0x38d8c2c4uL, 0x4fdff252uL, 0xd1bb67f1uL, 0xa6bc5767uL, 0x3fb506dduL, 0x48b2364buL,
    0xd80d2bdauL, 0xaf0a1b4cuL, 0x36034af6uL, 0x41047a60uL, 0xdf60efc3uL, 0xa867df55uL, 0x316e8eefuL,
	0x4669be79uL, 0xcb61b38cuL, 0xbc66831auL, 0x256fd2a0uL, 0x5268e236uL, 0xcc0c7795uL, 0xbb0b4703uL,
	0x220216b9uL, 0x5505262fuL, 0xc5ba3bbeuL, 0xb2bd0b28uL, 0x2bb45a92uL, 0x5cb36a04uL, 0xc2d7ffa7uL,
	0xb5d0cf31uL, 0x2cd99e8buL, 0x5bdeae1duL, 0x9b64c2b0uL, 0xec63f226uL, 0x756aa39cuL, 0x026d930auL,
	0x9c0906a9uL, 0xeb0e363fuL, 0x72076785uL, 0x05005713uL, 0x95bf4a82uL, 0xe2b87a14uL, 0x7bb12baeuL,
	0x0cb61b38uL, 0x92d28e9buL, 0xe5d5be0duL, 0x7cdcefb7uL, 0x0bdbdf21uL, 0x86d3d2d4uL, 0xf1d4e242uL,
	0x68ddb3f8uL, 0x1fda836euL, 0x81be16cduL, 0xf6b9265buL, 0x6fb077e1uL, 0x18b74777uL, 0x88085ae6uL,
	0xff0f6a70uL, 0x66063bcauL, 0x11010b5cuL, 0x8f659effuL, 0xf862ae69uL, 0x616bffd3uL, 0x166ccf45uL,
    0xa00ae278uL, 0xd70dd2eeuL, 0x4e048354uL, 0x3903b3c2uL, 0xa7672661uL, 0xd06016f7uL, 0x4969474duL,
	0x3e6e77dbuL, 0xaed16a4auL, 0xd9d65adcuL, 0x40df0b66uL, 0x37d83bf0uL, 0xa9bcae53uL, 0xdebb9ec5uL,
	0x47b2cf7fuL, 0x30b5ffe9uL, 0xbdbdf21cuL, 0xcabac28auL, 0x53b39330uL, 0x24b4a3a6uL, 0xbad03605uL,
	0xcdd70693uL, 0x54de5729uL, 0x23d967bfuL, 0xb3667a2euL, 0xc4614ab8uL, 0x5d681b02uL, 0x2a6f2b94uL,
	0xb40bbe37uL, 0xc30c8ea1uL, 0x5a05df1buL, 0x2d02ef8duL
};
#endif

#if((STD_ON == CRC32P4_ALGORITHM) && (CRC_TABLE == CRC_32P4_MODE))
CONST(uint32, CRC_CONST)
Crc_32p4Table[256] =
{
	0x00000000uL,  0x30850ff5uL,  0x610a1feauL,  0x518f101fuL,  0xc2143fd4uL,  0xf2913021uL,
	0xa31e203euL,  0x939b2fcbuL,  0x159615f7uL,  0x25131a02uL,  0x749c0a1duL,  0x441905e8uL,
	0xd7822a23uL,  0xe70725d6uL,  0xb68835c9uL,  0x860d3a3cuL,  0x2b2c2beeuL,  0x1ba9241buL,
	0x4a263404uL,  0x7aa33bf1uL,  0xe938143auL,  0xd9bd1bcfuL,  0x88320bd0uL,  0xb8b70425uL,
	0x3eba3e19uL,  0x0e3f31ecuL,  0x5fb021f3uL,  0x6f352e06uL,  0xfcae01cduL,  0xcc2b0e38uL,
	0x9da41e27uL,  0xad2111d2uL,  0x565857dcuL,  0x66dd5829uL,  0x37524836uL,  0x07d747c3uL,
	0x944c6808uL,  0xa4c967fduL,  0xf54677e2uL,  0xc5c37817uL,  0x43ce422buL,  0x734b4ddeuL,
	0x22c45dc1uL,  0x12415234uL,  0x81da7dffuL,  0xb15f720auL,  0xe0d06215uL,  0xd0556de0uL,
	0x7d747c32uL,  0x4df173c7uL,  0x1c7e63d8uL,  0x2cfb6c2duL,  0xbf6043e6uL,  0x8fe54c13uL,
	0xde6a5c0cuL,  0xeeef53f9uL,  0x68e269c5uL,  0x58676630uL,  0x09e8762fuL,  0x396d79dauL,
	0xaaf65611uL,  0x9a7359e4uL,  0xcbfc49fbuL,  0xfb79460euL,  0xacb0afb8uL,  0x9c35a04duL,
	0xcdbab052uL,  0xfd3fbfa7uL,  0x6ea4906cuL,  0x5e219f99uL,  0x0fae8f86uL,  0x3f2b8073uL,
	0xb926ba4fuL,  0x89a3b5bauL,  0xd82ca5a5uL,  0xe8a9aa50uL,  0x7b32859buL,  0x4bb78a6euL,
	0x1a389a71uL,  0x2abd9584uL,  0x879c8456uL,  0xb7198ba3uL,  0xe6969bbcuL,  0xd6139449uL,
	0x4588bb82uL,  0x750db477uL,  0x2482a468uL,  0x1407ab9duL,  0x920a91a1uL,  0xa28f9e54uL,
	0xf3008e4buL,  0xc38581beuL,  0x501eae75uL,  0x609ba180uL,  0x3114b19fuL,  0x0191be6auL,
	0xfae8f864uL,  0xca6df791uL,  0x9be2e78euL,  0xab67e87buL,  0x38fcc7b0uL,  0x0879c845uL,
	0x59f6d85auL,  0x6973d7afuL,  0xef7eed93uL,  0xdffbe266uL,  0x8e74f279uL,  0xbef1fd8cuL,
	0x2d6ad247uL,  0x1defddb2uL,  0x4c60cdaduL,  0x7ce5c258uL,  0xd1c4d38auL,  0xe141dc7fuL,
	0xb0cecc60uL,  0x804bc395uL,  0x13d0ec5euL,  0x2355e3abuL,  0x72daf3b4uL,  0x425ffc41uL,
	0xc452c67duL,  0xf4d7c988uL,  0xa558d997uL,  0x95ddd662uL,  0x0646f9a9uL,  0x36c3f65cuL,
	0x674ce643uL,  0x57c9e9b6uL,  0xc8df352fuL,  0xf85a3adauL,  0xa9d52ac5uL,  0x99502530uL,
	0x0acb0afbuL,  0x3a4e050euL,  0x6bc11511uL,  0x5b441ae4uL,  0xdd4920d8uL,  0xedcc2f2duL,
	0xbc433f32uL,  0x8cc630c7uL,  0x1f5d1f0cuL,  0x2fd810f9uL,  0x7e5700e6uL,  0x4ed20f13uL,
	0xe3f31ec1uL,  0xd3761134uL,  0x82f9012buL,  0xb27c0edeuL,  0x21e72115uL,  0x11622ee0uL,
	0x40ed3effuL,  0x7068310auL,  0xf6650b36uL,  0xc6e004c3uL,  0x976f14dcuL,  0xa7ea1b29uL,
	0x347134e2uL,  0x04f43b17uL,  0x557b2b08uL,  0x65fe24fduL,  0x9e8762f3uL,  0xae026d06uL,
	0xff8d7d19uL,  0xcf0872ecuL,  0x5c935d27uL,  0x6c1652d2uL,  0x3d9942cduL,  0x0d1c4d38uL,
	0x8b117704uL,  0xbb9478f1uL,  0xea1b68eeuL,  0xda9e671buL,  0x490548d0uL,  0x79804725uL,
	0x280f573auL,  0x188a58cfuL,  0xb5ab491duL,  0x852e46e8uL,  0xd4a156f7uL,  0xe4245902uL,
	0x77bf76c9uL,  0x473a793cuL,  0x16b56923uL,  0x263066d6uL,  0xa03d5ceauL,  0x90b8531fuL,
	0xc1374300uL,  0xf1b24cf5uL,  0x6229633euL,  0x52ac6ccbuL,  0x03237cd4uL,  0x33a67321uL,
	0x646f9a97uL,  0x54ea9562uL,  0x0565857duL,  0x35e08a88uL,  0xa67ba543uL,  0x96feaab6uL,
	0xc771baa9uL,  0xf7f4b55cuL,  0x71f98f60uL,  0x417c8095uL,  0x10f3908auL,  0x20769f7fuL,
	0xb3edb0b4uL,  0x8368bf41uL,  0xd2e7af5euL,  0xe262a0abuL,  0x4f43b179uL,  0x7fc6be8cuL,
	0x2e49ae93uL,  0x1ecca166uL,  0x8d578eaduL,  0xbdd28158uL,  0xec5d9147uL,  0xdcd89eb2uL,
	0x5ad5a48euL,  0x6a50ab7buL,  0x3bdfbb64uL,  0x0b5ab491uL,  0x98c19b5auL,  0xa84494afuL,
	0xf9cb84b0uL,  0xc94e8b45uL,  0x3237cd4buL,  0x02b2c2beuL,  0x533dd2a1uL,  0x63b8dd54uL,
	0xf023f29fuL,  0xc0a6fd6auL,  0x9129ed75uL,  0xa1ace280uL,  0x27a1d8bcuL,  0x1724d749uL,
	0x46abc756uL,  0x762ec8a3uL,  0xe5b5e768uL,  0xd530e89duL,  0x84bff882uL,  0xb43af777uL,
	0x191be6a5uL,  0x299ee950uL,  0x7811f94fuL,  0x4894f6bauL,  0xdb0fd971uL,  0xeb8ad684uL,
	0xba05c69buL,  0x8a80c96euL,  0x0c8df352uL,  0x3c08fca7uL,  0x6d87ecb8uL,  0x5d02e34duL,
	0xce99cc86uL,  0xfe1cc373uL,  0xaf93d36cuL,  0x9f16dc99uL
};
#endif
/*====================================================================================================*
 *                                           LOCAL VARIABLES
 *====================================================================================================*/

/*====================================================================================================*
 *                                      LOCAL FUNCTION PROTOTYPES
 *====================================================================================================*/
#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
#if((CRC_RUNTIME == CRC_32_MODE) || (CRC_RUNTIME == CRC_32P4_MODE))
STATIC FUNC(uint8, CRC_CODE) Crc_GetReflection_uint8(VAR(uint8,AUTOMATIC) data);
STATIC FUNC(uint32, CRC_CODE) Crc_GetReflection_uint32(VAR(uint32,AUTOMATIC) data);
#endif
/*====================================================================================================*
 *                                           LOCAL FUNCTIONS
 *====================================================================================================*/
#if((CRC_RUNTIME == CRC_32_MODE) || (CRC_RUNTIME == CRC_32P4_MODE))
/**
 * @brief        get the reflection of uint8 type data
 * @details      get the reflection of uint8 type data
 * @param[in]	 input: input data of char
 * @return       uint8
 */
STATIC FUNC(uint8, CRC_CODE) Crc_GetReflection_uint8(VAR(uint8,AUTOMATIC) data)
{
	uint8 count, reflection = 0u;
	for(count = 0u; count < 0x08u; count++)
	{
		if((data & (uint8)0x01) != 0u )
		{
			reflection |= (uint8)(1u << (7u - count));
		}
		data >>=1u;
	}
	return reflection;
}

/**
 * @brief        get the reflection of uint32 type data
 * @details      get the reflection of uint32 type data
 * @param[in]	 input: input data of uint32
 * @return       uint32
 */
STATIC FUNC(uint32, CRC_CODE) Crc_GetReflection_uint32(VAR(uint32,AUTOMATIC) data)
{
	uint32 count, reflection = 0u;
	for(count = 0u; count < 0x20u; count++)
	{
		if((data & (uint32)0x01) != 0u )
		{						
			reflection |= (uint32)((uint32)1u << (uint32)(0x1fu - count));
		}
		data >>=1u;
	}
	return reflection;
}
#endif /* (CRC_RUNTIME == CRC_32_MODE) || (CRC_RUNTIME == CRC_32P4_MODE) */

/*====================================================================================================*
 *                                          GLOBAL FUNCTIONS
 *====================================================================================================*/

#if(STD_ON == CRC8_ALGORITHM)
/**
 * @sid				   0x01
 * @brief              This service makes a CRC8 calculation on Crc_Length
 *                     data bytes, with SAE J1850 parameters
 * @details			   This service makes a CRC8 calculation on Crc_Length
 *                     data bytes, with SAE J1850 parameters
 * @param[in]      	   Crc_DataPtr:		Pointer to start address of data block to be calculated.
 *                     Crc_Length:		Length of data block to be calculated in bytes.
 *                     Crc_StartValue8:	Start value when the algorithm starts.
 *                     Crc_IsFirstCall:
 *                     		TRUE: First call in a sequence or individual CRC calculation;
 *                     		start from initial value, ignore Crc_StartValue8.
 *                     		FALSE:Subsequent call in a call sequence; Crc_StartValue8 is
 *                     		interpreted to be the return value of the previous function call.
 * @param[out]     	   None
 * @return             uint8
 * @retval         	   uint8
 */
FUNC(uint8, CRC_CODE) Crc_CalculateCRC8
(
	P2CONST(uint8, AUTOMATIC, CRC_APPL_DATA) Crc_DataPtr,
	VAR(uint32,AUTOMATIC) Crc_Length,
	VAR(uint8,AUTOMATIC) Crc_StartValue8,
	VAR(boolean,AUTOMATIC) Crc_IsFirstCall
)
{
	uint8 crc, subscript, count;
	if((boolean)TRUE == Crc_IsFirstCall)
	{
		crc = CRC_INITIAL_VALUE_8;
	}
	else
	{
		/**
		 * @req [SWS_Crc_00032] The function Crc_CalculateCRC8 shall perform a CRC8 calculation on
		 *      Crc_Length data bytes, pointed to by Crc_DataPtr, with the starting value of
		 *      Crc_StartValue8
		 */
		crc = Crc_StartValue8;
		crc ^= CRC_XOR_VALUE_8;
	}

#if(CRC_RUNTIME == CRC_8_MODE)
	/* it is runtime method to calculate */
	for (subscript = 0u; subscript < Crc_Length; subscript++)
	{
		/* current CRC8 XOR data in */
		/* PRQA S 0492 EOF # violate MISRA_2004_Rule_17.4:Logical need here */
		crc ^= Crc_DataPtr[subscript];

		for (count = 0u; count < 0x8u; count++)
		{
			/*check if MSB is 1*/
			if ((crc & 0x80u) > 0x0u)
			{
				/* PRQA S 2911 EOF # violate MISRA_2004_Rule_21.1:Logical need here */
				crc <<= 0x1u;	
				crc ^= CRC_POLYNOMIAL_8;
			}
			else
			{
				crc <<= 0x1u;
			}
		}
    }
	/* check if it is table method to calculate */
#elif(CRC_TABLE == CRC_8_MODE)
	for (subscript = 0u; subscript < Crc_Length; subscript++)
	{
		count = crc ^ (uint8)Crc_DataPtr[subscript];
		crc = (uint8)Crc_8Table[count];
	}
	/* check if it is hardware method to calculate */
#elif(CRC_HARDWARE == CRC_8_MODE)

#endif /* CRC_RUNTIME == CRC_8_MODE */
	crc ^= CRC_XOR_VALUE_8;
	return crc;
}
#endif/* STD_ON == CRC8_ALGORITHM */

#if(STD_ON == CRC8H2F_ALGORITHM)
/**
 * @sid				   0x05
 * @brief              This service makes a CRC8 calculation with the
 *                     Polynomial 0x2F on Crc_Length
 * @details			   This service makes a CRC8 calculation with the
 *                     Polynomial 0x2F on Crc_Length
 * @param[in]      	   Crc_DataPtr:		Pointer to start address of data block to be calculated.
 *                     Crc_Length:		Length of data block to be calculated in bytes.
 *                     Crc_StartValue8H2F:	Start value when the algorithm starts.
 *                     Crc_IsFirstCall:
 *                     		TRUE: First call in a sequence or individual CRC calculation;
 *                     		start from initial value, ignore Crc_StartValue8H2F..
 *                     		FALSE:Subsequent call in a call sequence; Crc_StartValue8H2F is
 *                     		interpreted to be the return value of the previous function call.
 * @param[out]     	   None
 * @return             uint8
 * @retval         	   uint8
 */
FUNC(uint8, CRC_CODE) Crc_CalculateCRC8H2F
(
	P2CONST(uint8, AUTOMATIC, CRC_APPL_DATA) Crc_DataPtr,
	VAR(uint32,AUTOMATIC) Crc_Length,
	VAR(uint8,AUTOMATIC)  Crc_StartValue8H2F,
	VAR(boolean,AUTOMATIC) Crc_IsFirstCall
)
{
	uint8 crc, subscript, count;
	if((boolean)TRUE == Crc_IsFirstCall)
	{
		crc = CRC_INITIAL_VALUE_8H2F;
	}
	else
	{
		/**
		 * @req [SWS_Crc_00044] The function Crc_CalculateCRC8H2F shall perform a CRC8
         *      calculation with the polynomial 0x2F on Crc_Length data bytes, pointed to by
         *      Crc_DataPtr, with the starting value of Crc_StartValue8H2F.
		 * @req [SWS_Crc_00041] The CRC function (with parameter Crc_IsFirstCall = FALSE)
         *      shall do the following operations:
         *      1. As 'Initial value' of the CRC computation, uses the parameter Crc_StartValueX
         *         (where X is 8, 8H2F, 16, 32 or P4) that should be the CRC result of the last
         *         call. The result is then XORed with 'XOR value' and reflected if 'Result data
         *         reflected' of the polynomial is TRUE:
         *         Crc = Crc_StartValueX ^ PolynomialXorVal
         *         Crc = reflectCrc size (Crc) (in the case 'Result data reflected' is TRUE)
         *       Steps 2 to 6 are identical to [SWS_Crc_00014] .
		 */
		crc = Crc_StartValue8H2F;
		crc ^= CRC_XOR_VALUE_8H2F;
	}

#if(CRC_RUNTIME == CRC_8H2F_MODE)
	/* it is runtime method to calculate */
	for (subscript = 0u; subscript < Crc_Length; subscript++)
	{
		/* current CRC8 XOR data in */
		crc ^= Crc_DataPtr[subscript];

		for (count = 0u; count < 0x8u; count++)
		{
			/*check if MSB is 1*/
			if ((crc & 0x80u) > 0x0u)
			{
				crc <<= 0x1u;
				crc ^= CRC_POLYNOMIAL_8H2F;
			}
			else
			{
				crc <<= 0x1u;
			}
		}
    }
	/* check if it is table method to calculate */
#elif(CRC_TABLE == CRC_8H2F_MODE)
    for (subscript = 0u; subscript < Crc_Length; subscript++)
    {
    	count = crc ^ (uint8)Crc_DataPtr[subscript];
    	crc = (uint8)Crc_8H2FTable[count];
    }
	/* check if it is hardware method to calculate */
#elif(CRC_HARDWARE == CRC_8H2F_MODE)

#endif /* CRC_RUNTIME == CRC_8H2F_MODE */
	crc ^= CRC_XOR_VALUE_8H2F;
	return crc;
}
#endif/* STD_ON == CRC8H2F_ALGORITHM */

#if(STD_ON == CRC16_ALGORITHM)
/**
 * @sid				   0x02
 * @brief              This service makes a CRC16 calculation on Crc_Length data bytes.
 * @details			   This service makes a CRC16 calculation on Crc_Length data bytes.
 * @param[in]      	   Crc_DataPtr:		Pointer to start address of data block to be calculated.
 *                     Crc_Length:		Length of data block to be calculated in bytes.
 *                     Crc_StartValue16:	Start value when the algorithm starts.
 *                     Crc_IsFirstCall:
 *                     		TRUE: First call in a sequence or individual CRC calculation;
 *                     		start from initial value, ignore Crc_StartValue16.
 *                     		FALSE:Subsequent call in a call sequence; Crc_StartValue16 is
 *                     		interpreted to be the return value of the previous function call.
 * @param[out]     	   None
 * @return             uint16
 * @retval         	   crc
 */
FUNC(uint16, CRC_CODE) Crc_CalculateCRC16
(
	P2CONST(uint8, AUTOMATIC, CRC_APPL_DATA) Crc_DataPtr,
	VAR(uint32,AUTOMATIC) Crc_Length,
	VAR(uint16,AUTOMATIC) Crc_StartValue16,
	VAR(boolean,AUTOMATIC) Crc_IsFirstCall
)
{
	uint16 crc, subscript, count;
	if((boolean)TRUE == Crc_IsFirstCall)
	{
		crc = CRC_INITIAL_VALUE_16;
	}
	else
	{
		crc = Crc_StartValue16;
	}

#if(CRC_RUNTIME == CRC_16_MODE)
	/* it is runtime method to calculate */
	for (subscript = 0u; subscript < Crc_Length; subscript++)
	{
		/* current CRC8 XOR data in */
		crc ^= (uint16)((uint16)Crc_DataPtr[subscript] << 8u);

		for (count = 0u; count < 0x8u; count++)
		{
			/*check if MSB is 1*/
			if ((crc & 0x8000u) > 0x0u)
			{
				crc <<= 0x1u;
				crc ^= CRC_POLYNOMIAL_16;
			}
			else
			{
				crc <<= 0x1u;
			}
		}
    }
	/* check if it is table method to calculate */
#elif(CRC_TABLE == CRC_16_MODE)
	for (subscript = 0u; subscript < Crc_Length; subscript++)
	{
		count = (((crc >> 8u) ^ ((uint16)Crc_DataPtr[subscript]))) & 0xFFu;
		crc = Crc_16Table[count] ^ (crc << 8u);
	}
/* check if it is hardware method to calculate */
#elif(CRC_HARDWARE == CRC_16_MODE)

#endif /* CRC_RUNTIME == CRC_16_MODE */
	return crc;
}
#endif/* STD_ON == CRC16_ALGORITHM */

#if(STD_ON == CRC32_ALGORITHM)
/**
 * @sid				   0x03
 * @brief              This service makes a CRC32 calculation on Crc_Length data bytes.
 * @details			   This service makes a CRC32 calculation on Crc_Length data bytes.
 * @param[in]      	   Crc_DataPtr:		Pointer to start address of data block to be calculated.
 *                     Crc_Length:		Length of data block to be calculated in bytes.
 *                     Crc_StartValue32:	Start value when the algorithm starts.
 *                     Crc_IsFirstCall:
 *                     		TRUE: First call in a sequence or individual CRC calculation;
 *                     		start from initial value, ignore Crc_StartValue32.
 *                     		FALSE:Subsequent call in a call sequence; Crc_StartValue32 is
 *                     		interpreted to be the return value of the previous function call.
 * @param[out]     	   None
 * @return             uint32
 * @retval         	   crc
 */
FUNC(uint32, CRC_CODE) Crc_CalculateCRC32
(
	P2CONST(uint8, AUTOMATIC, CRC_APPL_DATA) Crc_DataPtr,
	VAR(uint32,AUTOMATIC) Crc_Length,
	VAR(uint32,AUTOMATIC) Crc_StartValue32,
	VAR(boolean,AUTOMATIC) Crc_IsFirstCall
)
{
	uint32 crc, subscript, count;
	if((boolean)TRUE == Crc_IsFirstCall)
	{
		crc = CRC_INITIAL_VALUE_32;
	}
	else
	{
		crc = Crc_StartValue32;
		crc ^= CRC_XOR_VALUE_32;
#if(CRC_RUNTIME == CRC_32_MODE)
		crc = Crc_GetReflection_uint32(crc);
#endif
	}

#if(CRC_RUNTIME == CRC_32_MODE)
	/* it is runtime method to calculate */
	for (subscript = 0u; subscript < Crc_Length; subscript++)
	{
		/* current CRC32 high byte XOR data in(LSB first),left move 24 bit */
		crc ^= ((uint32)Crc_GetReflection_uint8(Crc_DataPtr[subscript]) << 0x18u);

		for (count = 0u; count < 0x8u; count++)
		{
			/*check if MSB is 1*/
			if ((crc & 0x80000000u) > 0x0u)
			{
				crc <<= 0x1u;
				crc ^= CRC_POLYNOMIAL_32;
			}
			else
			{
				crc <<= 0x1u;
			}
		}
    }
	/* check if it is table method to calculate */
#elif(CRC_TABLE == CRC_32_MODE)
    for (subscript = 0u; subscript < Crc_Length; subscript++)
    {
    	count = (crc ^ (uint32)Crc_DataPtr[subscript]) & 0xFFu;
    	crc = Crc_32Table[count] ^ (crc >> 8u);
    }
	/* check if it is hardware method to calculate */
#elif(CRC_HARDWARE == CRC_32_MODE)

#endif /* (CRC_RUNTIME == CRC_32_MODE) */
	crc ^= CRC_XOR_VALUE_32;
#if(CRC_RUNTIME == CRC_32_MODE)
	/**
	 * @req [SWS_Crc_00014] If the attribute 'Result data reflected' of the polynomial is TRUE, then reflect
     *      the CRC (over 8, 16 or 32 bits, depending on the CRC size)
	 */
	crc = Crc_GetReflection_uint32(crc);
#endif /* (CRC_RUNTIME == CRC_32_MODE) */
	return crc;
}
#endif/* STD_ON == CRC_32_ALGORITHM */

#if(STD_ON == CRC32P4_ALGORITHM)
/**
 * @sid				   0x06
 * @brief              This service makes a CRC32 calculation on Crc_Length data bytes, using the
 * 					   polynomial 0xF4ACFB13. This CRC routine is used by E2E Profile 4.
 * @details			   This service makes a CRC32 calculation on Crc_Length data bytes, using the
 * 					   polynomial 0xF4ACFB13. This CRC routine is used by E2E Profile 4.
 * @param[in]      	   Crc_DataPtr:		Pointer to start address of data block to be calculated.
 *                     Crc_Length:		Length of data block to be calculated in bytes.
 *                     Crc_StartValue32:	Start value when the algorithm starts.
 *                     Crc_IsFirstCall:
 *                     		TRUE: First call in a sequence or individual CRC calculation;
 *                     		start from initial value, ignore Crc_StartValue32.
 *                     		FALSE:Subsequent call in a call sequence; Crc_StartValue32 is
 *                     		interpreted to be the return value of the previous function call.
 * @param[out]     	   None
 * @return             uint32
 * @retval         	   crc
 */
FUNC(uint32, CRC_CODE)  Crc_CalculateCRC32P4
(
	P2CONST(uint8, AUTOMATIC, CRC_APPL_DATA) Crc_DataPtr,
	VAR(uint32,AUTOMATIC) Crc_Length,
	VAR(uint32,AUTOMATIC) Crc_StartValue32,
	VAR(boolean,AUTOMATIC) Crc_IsFirstCall
)
{
	uint32 crc, subscript, count;
	if((boolean)TRUE == Crc_IsFirstCall)
	{
		crc = CRC_INITIAL_VALUE_32P4;
	}
	else
	{
		crc = Crc_StartValue32;
		crc ^= CRC_XOR_VALUE_32P4;
#if(CRC_RUNTIME == CRC_32P4_MODE)
		crc = Crc_GetReflection_uint32(crc);
#endif
	}

#if(CRC_RUNTIME == CRC_32P4_MODE)
	/* it is runtime method to calculate */
	for (subscript = 0u; subscript < Crc_Length; subscript++)
	{
		/* current CRC32 high byte XOR data in(LSB first),left move 24 bit */
		crc ^= ((uint32)Crc_GetReflection_uint8(Crc_DataPtr[subscript]) << 0x18u);
		for (count = 0u; count < 0x8u; count++)
		{
			/*check if MSB is 1*/
			if ((crc & 0x80000000u) > 0x0u)
			{
				crc <<= 0x1u;
				crc ^= CRC_POLYNOMIAL_32P4;
			}
			else
			{
				crc <<= 0x1u;
			}
		}
    }
	/* check if it is table method to calculate */
#elif(CRC_TABLE == CRC_32P4_MODE)
    for (subscript = 0u; subscript < Crc_Length; subscript++)
    {
    	count = (crc ^ (uint32)Crc_DataPtr[subscript]) & 0xFFu;
    	crc = Crc_32p4Table[count] ^ (crc >> 8u);
    }
	/* check if it is hardware method to calculate */
#elif(CRC_HARDWARE == CRC_32P4_MODE)

#endif /* (CRC_RUNTIME == CRC_32P4_MODE) */
	crc ^= CRC_XOR_VALUE_32P4;
#if(CRC_RUNTIME == CRC_32P4_MODE)
	crc = Crc_GetReflection_uint32(crc);
#endif /* (CRC_RUNTIME == CRC_32P4_MODE) */
	return crc;
}
#endif/* STD_ON == CRC32P4_ALGORITHM */

/**
 * @sid			0x04
 * @brief       Service to get the version information of this module.
 * @details     Version information includes:
 *              - Module Id
 *              - Vendor Id
 *              - Vendor specific version numbers .
 * @param[out]  Versioninfo  Pointer to where to store the version information of this module.
 * @return		None
 */
FUNC(void, CRC_CODE) Crc_GetVersionInfo( P2VAR(Std_VersionInfoType, CRC_CODE, AUTOMATIC) Versioninfo )
{
	/**
	 * @req [SWS_Crc_00011] The function Crc_GetVersionInfo shall return the version information of the
	 *       CRC module. The version information includes:
     *       - Module Id
     *       - Vendor Id
     *       - Vendor specific version numbers
	 */
	Versioninfo -> moduleID = (uint16)CRC_MODULE_ID;
	Versioninfo -> vendorID = (uint16)CRC_VENDOR_ID;
	Versioninfo -> sw_major_version = (uint8)CRC_SW_MAJOR_VERSION;
	Versioninfo -> sw_minor_version = (uint8)CRC_SW_MINOR_VERSION;
	Versioninfo -> sw_patch_version = (uint8)CRC_SW_PATCH_VERSION;

}
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
