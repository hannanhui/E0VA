/**
 * @file        Dem_DtcStatus.h
 * @brief       AUTOSAR Dem - Dem module internal header file.
 * @details     Dem module internal header file, containing the  API specification and
 *              other variables and functions which are about dtc status processing.
 * @version     1.2.0
 *
 * @addtogroup  Dem
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

#ifndef DEM_DTCSTATUS_H
#define DEM_DTCSTATUS_H

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
#include "Dem_General.h"

/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/
#define DEM_DTCSTATUS_VENDOR_ID             					(0U)
#define DEM_DTCSTATUS_AR_RELEASE_MAJOR_VERSION      			(4U)
#define DEM_DTCSTATUS_AR_RELEASE_MINOR_VERSION      			(2U)
#define DEM_DTCSTATUS_AR_RELEASE_REVISION_VERSION      			(2U)
#define DEM_DTCSTATUS_SW_MAJOR_VERSION      					(1U)
#define DEM_DTCSTATUS_SW_MINOR_VERSION      					(2U)
#define DEM_DTCSTATUS_SW_PATCH_VERSION      					(0U)

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/

/* Check if current file and Dem_Internal.h header file are of the same vendor */
#if(DEM_DTCSTATUS_VENDOR_ID != DEM_GENERAL_VENDOR_ID )
#error "Dem_DtcStatus.h and Dem_General.h have different vendor id"
#endif /* #if(DEM_DTCSTATUS_VENDOR_ID != DEM_DTCSTATUSS_VENDOR_ID ) */

/* Check if current file and Dem_General.h header file are of the same Autosar version */
#if(\
		(DEM_DTCSTATUS_AR_RELEASE_MAJOR_VERSION != DEM_GENERAL_AR_RELEASE_MAJOR_VERSION) || \
		(DEM_DTCSTATUS_AR_RELEASE_MINOR_VERSION != DEM_GENERAL_AR_RELEASE_MINOR_VERSION) || \
		(DEM_DTCSTATUS_AR_RELEASE_REVISION_VERSION != DEM_GENERAL_AR_RELEASE_REVISION_VERSION) \
   )
#error "AutoSar Version Number of Dem_DtcStatus.h and Dem_General.h are different "
#endif /* #if(\
			(DEM_DTCSTATUS_AR_RELEASE_MAJOR_VERSION != DEM_GENERAL_AR_RELEASE_MAJOR_VERSION) || \
			(DEM_DTCSTATUS_AR_RELEASE_MINOR_VERSION != DEM_GENERAL_AR_RELEASE_MINOR_VERSION) || \
			(DEM_DTCSTATUS_AR_RELEASE_REVISION_VERSION != DEM_GENERAL_AR_RELEASE_REVISION_VERSION) \
   	   	   ) */

/* Check if current file and Dem_General.h header file are of the same Software version */
#if(\
		(DEM_DTCSTATUS_SW_MAJOR_VERSION != DEM_GENERAL_SW_MAJOR_VERSION) || \
		(DEM_DTCSTATUS_SW_MINOR_VERSION != DEM_GENERAL_SW_MINOR_VERSION) || \
		(DEM_DTCSTATUS_SW_PATCH_VERSION != DEM_GENERAL_SW_PATCH_VERSION) \
   )
#error "Software Version Number of Dem_DtcStatus.h and Dem_General.h are different "
#endif /* #if(\
				(DEM_DTCSTATUS_SW_MAJOR_VERSION != DEM_GENERAL_SW_MAJOR_VERSION) || \
				(DEM_DTCSTATUS_SW_MINOR_VERSION != DEM_GENERAL_SW_MINOR_VERSION) || \
				(DEM_DTCSTATUS_SW_PATCH_VERSION != DEM_GENERAL_SW_PATCH_VERSION) \
   	   	   	 ) */
/*====================================================================================================*
 *                                             CONSTANTS
 *====================================================================================================*/

#if(DEM_DTC_NUM > 0)
/*====================================================================================================*
 *                                         DEFINES AND MACROS
 *====================================================================================================*/
#define DEM_DTCSTATUSBIT_ISENABLE  	 	DEM_U8STATUS_ISENABLE
#define DEM_DTCSUPPRESS_CHECK  	 		DEM_U8BIT_ISENABLE
#define DEM_DTCSUPPRESS_ENABLE  	 	DEM_U8BIT_ENABLE
#define DEM_DTCSUPPRESS_DISABLE  		DEM_U8BIT_DISABLE

#if(DEM_GROUP_OF_DTC_NUM > 0)
#define DEM_GROUPDTCSETTING_CHECK  	 	DEM_U8BIT_ISENABLE
#define DEM_GROUPDTCSETTING_ENABLE  	DEM_U8BIT_ENABLE
#define DEM_GROUPDTCSETTING_DISABLE  	DEM_U8BIT_DISABLE
#endif /* #if(DEM_GROUP_OF_DTC_NUM > 0) */
/*====================================================================================================*
 *                                               ENUMS
 *====================================================================================================*/

/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS
 *====================================================================================================*/

/*====================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS
 *====================================================================================================*/
#if(DEM_GROUP_OF_DTC_NUM > 0)
/**
 * @brief Record dtc group status which used for Dem_DcmDisableDTCSetting and Dem_DcmEnableDTCSetting.
 */
extern VAR(uint8,DEM_VAR)Dem_DtcGroupSettingStatus[DEM_GROUP_OF_DTC_NUM_BYTE];
#endif /* #if(DEM_GROUP_OF_DTC_NUM > 0) */

/**
 * @brief Indicate relate dtc is suppressed or not
 */
extern VAR(uint8,DEM_VAR)Dem_DtcSuppress[DEM_DTC_NUM_BYTE];

/**
 * @brief Record uds status bits of relate dtc
 */
extern VAR(Dem_UdsStatusByteType,DEM_VAR)Dem_DtcUdsStatus[DEM_DTC_NUM];
/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES
 *====================================================================================================*/
DEM_STATIC_INLINE boolean Dem_ISEnable_DtcStatusBits
(
	uint16 u16DtcRef,
	Dem_UdsStatusByteType status
)
{
	return ((DEM_DTCSTATUSBIT_ISENABLE(Dem_DtcUdsStatus[u16DtcRef],status) != 0) ? \
			(boolean)TRUE : (boolean)FALSE);
}

DEM_STATIC_INLINE boolean Dem_ISEnable_DTCSuppress
(
	uint16 u16DtcRef
)
{
	return ((DEM_DTCSUPPRESS_CHECK(Dem_DtcSuppress,u16DtcRef) != 0) ? \
			(boolean)TRUE : (boolean)FALSE);
}

DEM_STATIC_INLINE void Dem_Enable_DTCSuppress
(
	uint16 u16DtcRef
)
{
	DEM_DTCSUPPRESS_ENABLE(Dem_DtcSuppress,u16DtcRef);
}

DEM_STATIC_INLINE void Dem_Disable_DTCSuppress
(
	uint16 u16DtcRef
)
{
	DEM_DTCSUPPRESS_DISABLE(Dem_DtcSuppress,u16DtcRef);
}


#if(DEM_GROUP_OF_DTC_NUM > 0)
DEM_STATIC_INLINE boolean Dem_ISEnable_GroupDTC
(
	uint16 u16DtcRef
)
{
	return ((DEM_GROUPDTCSETTING_CHECK(Dem_DtcGroupSettingStatus,u16DtcRef) != 0) ? \
			(boolean)TRUE : (boolean)FALSE);
}

DEM_STATIC_INLINE void Dem_Enable_GroupDTC
(
	uint16 u16DtcRef
)
{
	DEM_GROUPDTCSETTING_ENABLE(Dem_DtcGroupSettingStatus,u16DtcRef);
}

DEM_STATIC_INLINE void Dem_Disable_GroupDTC
(
	uint16 u16DtcRef
)
{
	DEM_GROUPDTCSETTING_DISABLE(Dem_DtcGroupSettingStatus,u16DtcRef);
}
#endif /* #if(DEM_GROUP_OF_DTC_NUM > 0) */

#endif /* #if(DEM_DTC_NUM > 0) */

#ifdef __cplusplus
}
#endif

#endif /* DEM_DTCSTATUS_H */
/** @} */
