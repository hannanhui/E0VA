/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      Type_Define.h                                                            */
/*   Instance     :                                                                               */
/*   Author       :      Ed                                                                       */
/*   Modify date  :      2025-04-11 11:08:33 AM                                                   */
/*   Description  :                                                                               */
/*                                                                                                */
/*                                                                                                */
/*   Compiler    :       KungFu32 IDE  [Version: V1.0.20.3]                                       */
/*   Hardware    :       ChipOn microcontroller KF32A Family [KF32A136KQT]                        */
/*   Version     :       V1.0                                                                     */
/*                                                                                                */
/*                                                                                                */
/*   All rights reserved. Distribution or duplication without previous written agreement of the   */
/*   owner prohibited.                                                                            */
/*                                                                                                */
/**************************************************************************************************/
#ifndef BASE_TYPE_H__
#define BASE_TYPE_H__


/* ***************************************************************************/
/* Include files                                                             */
/* ***************************************************************************/
#include <stdbool.h>
#include "Std_Types.h"
/*This header file already contains types such as uint_8_t/int8_t and uint6_t, so stdint.h is not required*/
/* ***************************************************************************/
/* Global pre-processor symbols/macros ('#define')                           */
/* ***************************************************************************/

#if 1

#ifndef uint8_t
	typedef uint8  				uint8_t;
#endif
#ifndef uint16_t
	typedef uint16 				uint16_t;
#endif
#ifndef uint32_t
	typedef uint32  				uint32_t;
#endif
#ifndef uint64_t
	typedef uint64  		uint64_t;
#endif

#ifndef int8_t
	typedef sint8  				int8_t;
#endif
#ifndef int16_t
	typedef sint16				int16_t;
#endif
#ifndef int32_t
	typedef sint32  				int32_t;
#endif
#ifndef int64_t
	//typedef sint64  		int64_t;
#endif
//typedef   float			         FP32;
//typedef   double 				 FP64;
#else
#include <stdint.h>

#endif
#define	uint8_t_MAX			   0xFFU
#define	uint16_t_MAX			 0xFFFFU
#define	uint32_t_MAX			 0xFFFFFFFFU

//#define BOOL        		 uint8_t
//#define bool        		 uint8_t

typedef bool BOOL;

//#define FALSE       		 (BOOL)0
//#define TRUE        		 (BOOL)1

#ifndef NULL
#define NULL				     ((void*)0)
#endif



/* 
 * SCI error code macro
 */
#ifndef SCI_SUCCESS
#define SCI_SUCCESS				(0)			//< SCI ok
#endif

#ifndef SCI_ERR
#define SCI_ERR					(-1)		//< Normal error
#endif

#ifndef SCI_ERR_BUSY
#define SCI_ERR_BUSY			(-2)		//< Communication unit busy
#endif

#ifndef SCI_ERR_ISR
#define SCI_ERR_ISR				(-3)		//< Interrupt be used by other function
#endif

#ifndef SCI_ERR_CHANNEL_INVALID
#define SCI_ERR_CHANNEL_INVALID	(-4)		//< Selected channel does not exist
#endif

#ifndef SCI_ERR_MODE_INVALID
#define SCI_ERR_MODE_INVALID	(-5)		//< Unsupported or incorrect mode
#endif

#ifndef SCI_ERR_BAUDRATE
#define SCI_ERR_BAUDRATE    	(-6)		//< Baudrate caculate error
#endif















#define T1_10MS			   10U


#define null				     (0U)
#define T1_1000MS          1000U
#define T10_0MS			   0U

#define T10_10MS			   1U
#define T10_20MS			   2U


#define T10_50MS			   5U
#define T10_60MS			   6U
#define T10_70MS			   7U
#define T10_80MS			   8U


#define T10_90MS			   9U

#define T10_100MS			   10U
#define T10_120MS			   12U
#define T10_150MS			   15U
#define T10_160MS			   16U
#define T10_200MS			   20U
#define T10_250MS			   25U

#define T10_300MS			   30U
#define T10_320MS			   32U

#define T10_400MS			   40U
#define T10_450MS			   45U

#define T10_500MS			   50U
#define T10_600MS			   60U
#define T10_900MS			 90U

#define T10_1000MS			 100U

#define T10_1200MS			 120U

#define T10_1350MS			 135U

#define T10_1500MS			 150U

#define T10_2000MS			 200U
#define T10_2100MS			 210U
#define T10_5000MS			 500U

#define T10_10000MS			 1000U
#define T10_20000MS			 2000U
#define T10_5000MS			 500U

#define T100_500MS			 5U
#define T100_1S				   10U
#define T100_2000MS			 20U

#define T300_2100MS			 7U


#define Set32Bit(Var,Place) ((Var)|=(uint32_t)((uint32_t)1<<(uint32_t)(Place)))
#define Clr32Bit(Var,Place) ((Var)&=(uint32_t)((uint32_t)((uint32_t)1<<(uint32_t)(Place))^(uint32_t)0xFFFFFFFF))
#define Val32Bit(Var,Place) ((uint32_t)(Var)&(uint32_t)((uint32_t)1<<(uint32_t)(Place)))

#define Set16Bit(Var,Place) ((Var)|=(uint16_t)((uint16_t)1<<(uint16_t)(Place)))
#define Clr16Bit(Var,Place) ((Var)&=(uint16_t)((uint16_t)((uint16_t)1<<(uint16_t)(Place))^(uint16_t)65535))
#define Val16Bit(Var,Place) ((uint16_t)(Var)&(uint16_t)((uint16_t)1<<(uint16_t)(Place)))

#define SetBit(Var,Place) ((Var)|=(uint8_t)(1<<(Place)))
#define ClrBit(Var,Place) ((Var) = (uint8_t)((Var)&((1<<(Place))^255)))
#define ValBit(Var,Place) ((Var)& (1<<(Place)))
#define ChgBit(Var,Place) ((Var)^=(1<<(Place)))

#define ClrByte(Var) 		(Var=0)

typedef enum
{
    /* Generic error codes */
    STATUS_SUCCESS                         = 0x000U,    /*!< Generic operation success status */
    STATUS_ERROR                           = 0x001U,    /*!< Generic operation failure status */
    STATUS_BUSY                            = 0x002U,    /*!< Generic operation busy status */
    STATUS_TIMEOUT                         = 0x003U,    /*!< Generic operation timeout status */
    STATUS_UNSUPPORTED                     = 0x004U,    /*!< Generic operation unsupported status */
   
} status_t;

/* ʹ��״̬��־ */
// typedef enum
// {
//     DISABLE = 0,
//     ENABLE  = 1
// } AbleStatus;


/* ***************************************************************************/
/* Global variable declarations ('extern', definition in C source)           */
/* ***************************************************************************/

/* ***************************************************************************/
/* Global function prototypes ('extern', definition in C source)             */
/* ***************************************************************************/

#endif /* __BASE_TYPE_H__ */
