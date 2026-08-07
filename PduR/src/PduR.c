/**
 * @file        PduR.c 
 * @brief       Source file of PduR module, implementing all services of PduR.
 * @version     1.2.0
 * @addtogroup  PduR
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

/* PRQA S 0292, 0288, 1503, 1505, 0857, 0791, 0828, 0647, 2844, 2992 EOF #
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
 * 4.1503 -- Violates MISRA 2004 Required Rule 8.10, The function is only referenced in the translation 
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

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
#include "PduR.h"
/**
 * @req [SWS_PduR_00287] If PduRZeroCostOperation is set to (boolean)true and all routing paths are of
 * 						 configuration class Pre-Compile modules directly above or below the PDU Router
 * 						 may directly call each other without using PduR module functions.
 */
#if(STD_OFF == PDUR_ZERO_COST_OPERATION)
/**
 * @req [SWS_PduR_00802] The PduR implementation shall include Det.h if PduRDevErrorDetect is enabled.
 */
#if(STD_ON == PDUR_DEV_ERROR_DETECT)
#include "Det.h"
#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */

#if(STD_ON == PDUR_CANIF_SUPPORT)
#include "PduR_CanIf.h"
#endif/* STD_ON == PDUR_CANIF_SUPPORT */

#if(STD_ON == PDUR_CANTP_SUPPORT)
#include "PduR_CanTp.h"
#endif/* STD_ON == PDUR_CANTP_SUPPORT */

#if(STD_ON == PDUR_J1939TP_SUPPORT)
#include "PduR_J1939Tp.h"
#endif/* STD_ON == PDUR_J1939TP_SUPPORT */

#if(STD_ON == PDUR_COM_SUPPORT)
#include "PduR_Com.h"
#endif/* STD_ON == PDUR_COM_SUPPORT */

#if(STD_ON == PDUR_DCM_SUPPORT)
#include "PduR_Dcm.h"
#endif/* STD_ON == PDUR_DCM_SUPPORT */

#if(STD_ON == PDUR_J1939DCM_SUPPORT)
#include "PduR_J1939Dcm.h"
#endif/* STD_ON == PDUR_J1939DCM_SUPPORT */

#if(STD_ON == PDUR_IPDUM_SUPPORT)
#include "PduR_IpduM.h"
#endif/* STD_ON == PDUR_IPDUM_SUPPORT */

#if(STD_ON == PDUR_J1939RM_SUPPORT)
#include "PduR_J1939Rm.h"
#endif/* STD_ON == PDUR_J1939RM_SUPPORT */

#if(STD_ON == PDUR_LDCOM_SUPPORT)
#include "PduR_LdCom.h"
#endif/* STD_ON == PDUR_LDCOM_SUPPORT */

#if(STD_ON == PDUR_SECOC_SUPPORT)
#include "PduR_SecOC.h"
#endif/* STD_ON == PDUR_SECOC_SUPPORT */

#if(STD_ON == PDUR_DBG_SUPPORT)
#include "PduR_Dbg.h"
#endif/* STD_ON == PDUR_DBG_SUPPORT */

#if(STD_ON == PDUR_CANNM_SUPPORT)
#include "PduR_CanNm.h"
#endif/* STD_ON == PDUR_CANNM_SUPPORT */

#if(STD_ON == PDUR_LINIF_SUPPORT)
#include "PduR_LinIf.h"
#endif/* STD_ON == PDUR_LINIF_SUPPORT */

#if(STD_ON == PDUR_LINTP_SUPPORT)
#include "PduR_LinTp.h"
#endif/* STD_ON == PDUR_LINTP_SUPPORT */

#if(STD_ON == PDUR_FRIF_SUPPORT)
#include "PduR_FrIf.h"
#endif/* STD_ON == PDUR_FRIF_SUPPORT */

#if(STD_ON == PDUR_FRNM_SUPPORT)
#include "PduR_FrNm.h"
#endif

#if(STD_ON == PDUR_SOAD_SUPPORT)
#include "PduR_SoAd.h"
#endif/* STD_ON == PDUR_SOAD_SUPPORT */
#ifdef AH_TEST_PDUR
#include "TestCode.h"
#endif

/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION
 *====================================================================================================*/
#define PDUR_VENDOR_ID_C 					0U
#define PDUR_AR_RELEASE_MAJOR_VERSION_C  	4U
#define PDUR_AR_RELEASE_MINOR_VERSION_C  	2U
#define PDUR_AR_RELEASE_REVISION_VERSION_C	2U
#define PDUR_SW_MAJOR_VERSION_C				1U
#define PDUR_SW_MINOR_VERSION_C				2U
#define PDUR_SW_PATCH_VERSION_C				0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
#ifndef DISABLE_INTERMOD_VERSION_CHECK

#if(STD_ON == PDUR_DEV_ERROR_DETECT)
/* Check if current file and Det.h header file are of the same Autosar version */
#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION)\
      )
#error "AutoSar Version Number of Det.h and Det.h are different "
#endif
#endif

#endif

#if(STD_ON == PDUR_CANIF_SUPPORT)
/* Check if current file and PduR_CanIf.h header file are of the same vendor */
#if(PDUR_VENDOR_ID_C != PDUR_CANIF_VENDOR_ID )
#error "PduR.c and PduR_CanIf.h have different vendor id"
#endif

#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION_C != PDUR_CANIF_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION_C != PDUR_CANIF_AR_RELEASE_MINOR_VERSION) || \
      (PDUR_AR_RELEASE_REVISION_VERSION_C != PDUR_CANIF_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of PduR.c and PduR_CanIf.h are different "
#endif

/* Check if current file and PduR_CanIf.h header file are of the same software version */
#if(\
      (PDUR_SW_MAJOR_VERSION_C != PDUR_CANIF_SW_MAJOR_VERSION) || \
      (PDUR_SW_MINOR_VERSION_C != PDUR_CANIF_SW_MINOR_VERSION) ||\
	  (PDUR_SW_PATCH_VERSION_C != PDUR_CANIF_SW_PATCH_VERSION)\
      )
#error "Software Version Number of PduR.c and PduR_CanIf.h are different "
#endif
#endif

#if(STD_ON == PDUR_CANTP_SUPPORT)
/* Check if current file and PduR_CanTp.h header file are of the same vendor */
#if(PDUR_VENDOR_ID_C != PDUR_CANTP_VENDOR_ID )
#error "PduR.c and PduR_CanTp.h have different vendor id"
#endif

#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION_C != PDUR_CANTP_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION_C != PDUR_CANTP_AR_RELEASE_MINOR_VERSION) || \
      (PDUR_AR_RELEASE_REVISION_VERSION_C != PDUR_CANTP_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of PduR.c and PduR_CanTp.h are different "
#endif

/* Check if current file and PduR_CanTp.h header file are of the same software version */
#if(\
      (PDUR_SW_MAJOR_VERSION_C != PDUR_CANTP_SW_MAJOR_VERSION) || \
      (PDUR_SW_MINOR_VERSION_C != PDUR_CANTP_SW_MINOR_VERSION) ||\
	  (PDUR_SW_PATCH_VERSION_C != PDUR_CANTP_SW_PATCH_VERSION)\
      )
#error "Software Version Number of PduR.c and PduR_CanTp.h are different "
#endif
#endif

#if(STD_ON == PDUR_J1939TP_SUPPORT)
/* Check if current file and PduR_J1939Tp.h header file are of the same vendor */
#if(PDUR_VENDOR_ID_C != PDUR_J1939TP_VENDOR_ID )
#error "PduR.c and PduR_CanTp.h have different vendor id"
#endif

#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION_C != PDUR_J1939TP_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION_C != PDUR_J1939TP_AR_RELEASE_MINOR_VERSION) || \
      (PDUR_AR_RELEASE_REVISION_VERSION_C != PDUR_J1939TP_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of PduR.c and PduR_J1939Tp.h are different "
#endif

/* Check if current file and PduR_J1939Tp.h header file are of the same software version */
#if(\
      (PDUR_SW_MAJOR_VERSION_C != PDUR_J1939TP_SW_MAJOR_VERSION) || \
      (PDUR_SW_MINOR_VERSION_C != PDUR_J1939TP_SW_MINOR_VERSION) ||\
	  (PDUR_SW_PATCH_VERSION_C != PDUR_J1939TP_SW_PATCH_VERSION)\
      )
#error "Software Version Number of PduR.c and PduR_J1939Tp.h are different "
#endif
#endif

#if(STD_ON == PDUR_COM_SUPPORT)
/* Check if current file and PduR_Com.h header file are of the same vendor */
#if(PDUR_VENDOR_ID_C != PDUR_COM_VENDOR_ID )
#error "PduR.c and PduR_Com.h have different vendor id"
#endif

#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION_C != PDUR_COM_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION_C != PDUR_COM_AR_RELEASE_MINOR_VERSION) || \
      (PDUR_AR_RELEASE_REVISION_VERSION_C != PDUR_COM_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of PduR.c and PduR_Com.h are different "
#endif

/* Check if current file and PduR_Com.h header file are of the same software version */
#if(\
      (PDUR_SW_MAJOR_VERSION_C != PDUR_COM_SW_MAJOR_VERSION) || \
      (PDUR_SW_MINOR_VERSION_C != PDUR_COM_SW_MINOR_VERSION) ||\
	  (PDUR_SW_PATCH_VERSION_C != PDUR_COM_SW_PATCH_VERSION)\
      )
#error "Software Version Number of PduR.c and PduR_Com.h are different "
#endif
#endif

#if(STD_ON == PDUR_DCM_SUPPORT)
/* Check if current file and PduR_Dcm.h header file are of the same vendor */
#if(PDUR_VENDOR_ID_C != PDUR_DCM_VENDOR_ID )
#error "PduR.c and PduR_Com.h have different vendor id"
#endif

#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION_C != PDUR_DCM_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION_C != PDUR_DCM_AR_RELEASE_MINOR_VERSION) || \
      (PDUR_AR_RELEASE_REVISION_VERSION_C != PDUR_DCM_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of PduR.c and PduR_Dcm.h are different "
#endif

/* Check if current file and PduR_Dcm.h header file are of the same software version */
#if(\
      (PDUR_SW_MAJOR_VERSION_C != PDUR_DCM_SW_MAJOR_VERSION) || \
      (PDUR_SW_MINOR_VERSION_C != PDUR_DCM_SW_MINOR_VERSION) ||\
	  (PDUR_SW_PATCH_VERSION_C != PDUR_DCM_SW_PATCH_VERSION)\
      )
#error "Software Version Number of PduR.c and PduR_Dcm.h are different "
#endif
#endif

#if(STD_ON == PDUR_J1939DCM_SUPPORT)
/* Check if current file and PduR_J1939Dcm.h header file are of the same vendor */
#if(PDUR_VENDOR_ID_C != PDUR_J1939DCM_VENDOR_ID )
#error "PduR.c and PduR_J1939Dcm.h have different vendor id"
#endif

#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION_C != PDUR_J1939DCM_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION_C != PDUR_J1939DCM_AR_RELEASE_MINOR_VERSION) || \
      (PDUR_AR_RELEASE_REVISION_VERSION_C != PDUR_J1939DCM_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of PduR.c and PduR_J1939Dcm.h are different "
#endif

/* Check if current file and PduR_J1939Dcm.h header file are of the same software version */
#if(\
      (PDUR_SW_MAJOR_VERSION_C != PDUR_J1939DCM_SW_MAJOR_VERSION) || \
      (PDUR_SW_MINOR_VERSION_C != PDUR_J1939DCM_SW_MINOR_VERSION) ||\
	  (PDUR_SW_PATCH_VERSION_C != PDUR_J1939DCM_SW_PATCH_VERSION)\
      )
#error "Software Version Number of PduR.c and PduR_J1939Dcm.h are different "
#endif
#endif

#if(STD_ON == PDUR_LDCOM_SUPPORT)
/* Check if current file and PduR_LdCom.h header file are of the same vendor */
#if(PDUR_VENDOR_ID_C != PDUR_LDCOM_VENDOR_ID )
#error "PduR.c and PduR_LdCom.h have different vendor id"
#endif

#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION_C != PDUR_LDCOM_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION_C != PDUR_LDCOM_AR_RELEASE_MINOR_VERSION) || \
      (PDUR_AR_RELEASE_REVISION_VERSION_C != PDUR_LDCOM_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of PduR.c and PduR_LdCom.h are different "
#endif

/* Check if current file and PduR_LdCom.h header file are of the same software version */
#if(\
      (PDUR_SW_MAJOR_VERSION_C != PDUR_LDCOM_SW_MAJOR_VERSION) || \
      (PDUR_SW_MINOR_VERSION_C != PDUR_LDCOM_SW_MINOR_VERSION) ||\
	  (PDUR_SW_PATCH_VERSION_C != PDUR_LDCOM_SW_PATCH_VERSION)\
      )
#error "Software Version Number of PduR.c and PduR_LdCom.h are different "
#endif
#endif

#if(STD_ON == PDUR_IPDUM_SUPPORT)
/* Check if current file and PduR_IpduM.h header file are of the same vendor */
#if(PDUR_VENDOR_ID_C != PDUR_IPDUM_VENDOR_ID )
#error "PduR.c and PduR_IpduM.h have different vendor id"
#endif

#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION_C != PDUR_IPDUM_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION_C != PDUR_IPDUM_AR_RELEASE_MINOR_VERSION) || \
      (PDUR_AR_RELEASE_REVISION_VERSION_C != PDUR_IPDUM_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of PduR.c and PduR_IpduM.h are different "
#endif

/* Check if current file and PduR_IpduM.h header file are of the same software version */
#if(\
      (PDUR_SW_MAJOR_VERSION_C != PDUR_IPDUM_SW_MAJOR_VERSION) || \
      (PDUR_SW_MINOR_VERSION_C != PDUR_IPDUM_SW_MINOR_VERSION) ||\
	  (PDUR_SW_PATCH_VERSION_C != PDUR_IPDUM_SW_PATCH_VERSION)\
      )
#error "Software Version Number of PduR.c and PduR_IpduM.h are different "
#endif
#endif

#if(STD_ON == PDUR_J1939RM_SUPPORT)
/* Check if current file and PduR_IpduM.h header file are of the same vendor */
#if(PDUR_VENDOR_ID_C != PDUR_J1939RM_VENDOR_ID )
#error "PduR.c and PduR_J1939Rm.h have different vendor id"
#endif

#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION_C != PDUR_J1939RM_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION_C != PDUR_J1939RM_AR_RELEASE_MINOR_VERSION) || \
      (PDUR_AR_RELEASE_REVISION_VERSION_C != PDUR_J1939RM_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of PduR.c and PduR_J1939Rm.h are different "
#endif

/* Check if current file and PduR_J1939Rm.h header file are of the same software version */
#if(\
      (PDUR_SW_MAJOR_VERSION_C != PDUR_J1939RM_SW_MAJOR_VERSION) || \
      (PDUR_SW_MINOR_VERSION_C != PDUR_J1939RM_SW_MINOR_VERSION) ||\
	  (PDUR_SW_PATCH_VERSION_C != PDUR_J1939RM_SW_PATCH_VERSION)\
      )
#error "Software Version Number of PduR.c and PduR_J1939Rm.h are different "
#endif
#endif

#if(STD_ON == PDUR_SECOC_SUPPORT)
/* Check if current file and PduR_SecOC.h header file are of the same vendor */
#if(PDUR_VENDOR_ID_C != PDUR_SECOC_VENDOR_ID )
#error "PduR.c and PduR_SecOC.h have different vendor id"
#endif

#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION_C != PDUR_SECOC_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION_C != PDUR_SECOC_AR_RELEASE_MINOR_VERSION) || \
      (PDUR_AR_RELEASE_REVISION_VERSION_C != PDUR_SECOC_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of PduR.c and PduR_SecOC.h are different "
#endif

/* Check if current file and PduR_SecOC.h header file are of the same software version */
#if(\
      (PDUR_SW_MAJOR_VERSION_C != PDUR_SECOC_SW_MAJOR_VERSION) || \
      (PDUR_SW_MINOR_VERSION_C != PDUR_SECOC_SW_MINOR_VERSION) ||\
	  (PDUR_SW_PATCH_VERSION_C != PDUR_SECOC_SW_PATCH_VERSION)\
      )
#error "Software Version Number of PduR.c and PduR_SecOC.h are different "
#endif
#endif

#if(STD_ON == PDUR_DBG_SUPPORT)
/* Check if current file and PduR_Dbg.h header file are of the same vendor */
#if(PDUR_VENDOR_ID_C != PDUR_DBG_VENDOR_ID )
#error "PduR.c and PduR_Dbg.h have different vendor id"
#endif

#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION_C != PDUR_DBG_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION_C != PDUR_DBG_AR_RELEASE_MINOR_VERSION) || \
      (PDUR_AR_RELEASE_REVISION_VERSION_C != PDUR_DBG_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of PduR.c and PduR_Dbg.h are different "
#endif

/* Check if current file and PduR_Dbg.h header file are of the same software version */
#if(\
      (PDUR_SW_MAJOR_VERSION_C != PDUR_DBG_SW_MAJOR_VERSION) || \
      (PDUR_SW_MINOR_VERSION_C != PDUR_DBG_SW_MINOR_VERSION) ||\
	  (PDUR_SW_PATCH_VERSION_C != PDUR_DBG_SW_PATCH_VERSION)\
      )
#error "Software Version Number of PduR.c and PduR_Dbg.h are different "
#endif
#endif

#if(STD_ON == PDUR_CANNM_SUPPORT)
/* Check if current file and PduR_CanNm.h header file are of the same vendor */
#if(PDUR_VENDOR_ID_C != PDUR_CANNM_VENDOR_ID )
#error "PduR.c and PduR_CanNm.h have different vendor id"
#endif

#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION_C != PDUR_CANNM_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION_C != PDUR_CANNM_AR_RELEASE_MINOR_VERSION) || \
      (PDUR_AR_RELEASE_REVISION_VERSION_C != PDUR_CANNM_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of PduR.c and PduR_CanNm.h are different "
#endif

/* Check if current file and PduR_CanNm.h header file are of the same software version */
#if(\
      (PDUR_SW_MAJOR_VERSION_C != PDUR_CANNM_SW_MAJOR_VERSION) || \
      (PDUR_SW_MINOR_VERSION_C != PDUR_CANNM_SW_MINOR_VERSION) ||\
	  (PDUR_SW_PATCH_VERSION_C != PDUR_CANNM_SW_PATCH_VERSION)\
      )
#error "Software Version Number of PduR.c and PduR_CanNm.h are different "
#endif
#endif

#if(STD_ON == PDUR_LINIF_SUPPORT)
/* Check if current file and PduR_LinIf header file are of the same vendor */
#if(PDUR_VENDOR_ID_C != PDUR_LINIF_VENDOR_ID )
#error "PduR.c and PduR_LinIf.h have different vendor id"
#endif

#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION_C != PDUR_LINIF_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION_C != PDUR_LINIF_AR_RELEASE_MINOR_VERSION) || \
      (PDUR_AR_RELEASE_REVISION_VERSION_C != PDUR_LINIF_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of PduR.c and PduR_LinIf.h are different "
#endif

/* Check if current file and PduR_LinIf.h header file are of the same software version */
#if(\
      (PDUR_SW_MAJOR_VERSION_C != PDUR_LINIF_SW_MAJOR_VERSION) || \
      (PDUR_SW_MINOR_VERSION_C != PDUR_LINIF_SW_MINOR_VERSION) ||\
	  (PDUR_SW_PATCH_VERSION_C != PDUR_LINIF_SW_PATCH_VERSION)\
      )
#error "Software Version Number of PduR.c and PduR_LinIf.h are different "
#endif
#endif

#if(STD_ON == PDUR_LINTP_SUPPORT)
/* Check if current file and PduR_LinTp.h header file are of the same vendor */
#if(PDUR_VENDOR_ID_C != PDUR_LINTP_VENDOR_ID )
#error "PduR.c and PduR_LinTp.h have different vendor id"
#endif

#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION_C != PDUR_LINTP_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION_C != PDUR_LINTP_AR_RELEASE_MINOR_VERSION) || \
      (PDUR_AR_RELEASE_REVISION_VERSION_C != PDUR_LINTP_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of PduR.c and PduR_LinTp.h are different "
#endif

/* Check if current file and PduR_LinTp.h header file are of the same software version */
#if(\
      (PDUR_SW_MAJOR_VERSION_C != PDUR_LINTP_SW_MAJOR_VERSION) || \
      (PDUR_SW_MINOR_VERSION_C != PDUR_LINTP_SW_MINOR_VERSION) ||\
	  (PDUR_SW_PATCH_VERSION_C != PDUR_LINTP_SW_PATCH_VERSION)\
      )
#error "Software Version Number of PduR.c and PduR_LinTp.h are different "
#endif
#endif

#if(STD_ON == PDUR_FRIF_SUPPORT)
/* Check if current file and PduR_FrIf.h header file are of the same vendor */
#if(PDUR_VENDOR_ID_C != PDUR_FRIF_VENDOR_ID )
#error "PduR.c and PduR_FrIf.h have different vendor id"
#endif

#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION_C != PDUR_FRIF_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION_C != PDUR_FRIF_AR_RELEASE_MINOR_VERSION) || \
      (PDUR_AR_RELEASE_REVISION_VERSION_C != PDUR_FRIF_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of PduR.c and PduR_FrIf.h are different "
#endif

/* Check if current file and PduR_FrIf.h header file are of the same software version */
#if(\
      (PDUR_SW_MAJOR_VERSION_C != PDUR_FRIF_SW_MAJOR_VERSION) || \
      (PDUR_SW_MINOR_VERSION_C != PDUR_FRIF_SW_MINOR_VERSION) ||\
	  (PDUR_SW_PATCH_VERSION_C != PDUR_FRIF_SW_PATCH_VERSION)\
      )
#error "Software Version Number of PduR.c and PduR_FrIf.h are different "
#endif
#endif

#if(STD_ON == PDUR_FRNM_SUPPORT)
/* Check if current file and PduR_FrNm.h header file are of the same vendor */
#if(PDUR_VENDOR_ID_C != PDUR_FRNM_VENDOR_ID )
#error "PduR.c and PduR_FrNm.h have different vendor id"
#endif

#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION_C != PDUR_FRNM_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION_C != PDUR_FRNM_AR_RELEASE_MINOR_VERSION) || \
      (PDUR_AR_RELEASE_REVISION_VERSION_C != PDUR_FRNM_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of PduR.c and PduR_FrNm.h are different "
#endif

/* Check if current file and PduR_FrNm.h header file are of the same software version */
#if(\
      (PDUR_SW_MAJOR_VERSION_C != PDUR_FRNM_SW_MAJOR_VERSION) || \
      (PDUR_SW_MINOR_VERSION_C != PDUR_FRNM_SW_MINOR_VERSION) ||\
	  (PDUR_SW_PATCH_VERSION_C != PDUR_FRNM_SW_PATCH_VERSION)\
      )
#error "Software Version Number of PduR.c and PduR_FrNm.h are different "
#endif
#endif

#if(STD_ON == PDUR_SOAD_SUPPORT)
/* Check if current file and PduR_SoAd.h header file are of the same vendor */
#if(PDUR_VENDOR_ID_C != PDUR_SOAD_VENDOR_ID )
#error "PduR.c and PduR_SoAd.h have different vendor id"
#endif

#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION_C != PDUR_SOAD_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION_C != PDUR_SOAD_AR_RELEASE_MINOR_VERSION) || \
      (PDUR_AR_RELEASE_REVISION_VERSION_C != PDUR_SOAD_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of PduR.c and PduR_SoAd.h are different "
#endif

/* Check if current file and PduR_SoAd.h header file are of the same software version */
#if(\
      (PDUR_SW_MAJOR_VERSION_C != PDUR_SOAD_SW_MAJOR_VERSION) || \
      (PDUR_SW_MINOR_VERSION_C != PDUR_SOAD_SW_MINOR_VERSION) ||\
	  (PDUR_SW_PATCH_VERSION_C != PDUR_SOAD_SW_PATCH_VERSION)\
      )
#error "Software Version Number of PduR.c and PduR_SoAd.h are different "
#endif
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
#ifndef AH_UNITTEST_ENABLED
#define STATIC static
#define STATIC_INLINE static inline
#else
#define STATIC
#define STATIC_INLINE
#endif /* #if defined(AH_UNITTEST_ENABLED) */

/*====================================================================================================*
 *                                           LOCAL CONSTANTS
 *====================================================================================================*/

/*====================================================================================================*
 *                                           LOCAL VARIABLES
 *====================================================================================================*/
/**
 * @req [SWS_PduR_00325] The PDU Router module shall consist of two states,PDUR_UNINIT and
 * 						 PDUR_ONLINE, as defined in PduR_StateType
 */

/* PRQA S 3218 EOF #violate MISAR2004_8.7: ignore this warnning*/

/**
 * @brief PduR init status, at first define it as PDUR_UNINIT
 */
#define PDUR_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "PduR_MemMap.h"
STATIC VAR(PduR_StateType, PDUR_VAR) PduR_Status = PDUR_UNINIT;

/**
 * @brief If gateway:dest pdu(PduRDestPduDataProvision) is configuration PDUR_DIRECT
 */
#if(PDUR_GATEWAY_DIRECT_BUFFER_PDU_SUM > 0u)
STATIC VAR(PduR_DestStateType,PDUR_VAR) PduR_DestPduState[PDUR_GATEWAY_DIRECT_BUFFER_PDU_SUM];
#else
STATIC P2VAR(PduR_DestStateType, AUTOMATIC, PDUR_APPL_DATA) PduR_DestPduState = NULL_PTR;
#endif/* PDUR_GATEWAY_DIRECT_BUFFER_PDU_SUM > 0u */

/**
 * @brief PduR PB Configuration Run Time point parameter
 */
STATIC P2CONST(PduR_PBConfigType, PDUR_CONST, PDUR_CONST_PBCFG) PduR_ConfigData = NULL_PTR;

#define PDUR_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "PduR_MemMap.h"

/**
 * @brief all route dest pdus is enable or disable
 */
#define PDUR_START_SEC_VAR_NO_INIT_BOOLEAN
#include "PduR_MemMap.h"
#if(PDUR_SRC_PDU_SUM > 0u)
STATIC VAR(boolean, PDUR_VAR) PathIsEnabled[PDUR_SRC_PDU_SUM];
#else
STATIC P2VAR(boolean, AUTOMATIC, PDUR_APPL_DATA) PathIsEnabled = NULL_PTR;
#endif/* PDUR_DEST_PDU_SUM > 0u */
#define PDUR_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "PduR_MemMap.h"

/**
 * @brief up module Tx 1:n(include If and Tp)
 */
#define PDUR_START_SEC_VAR_NO_INIT_BOOLEAN
#include "PduR_MemMap.h"
#if(PDUR_SRC_UP_MULTICAST_TX_IF_SUM + PDUR_SRC_UP_MULTICAST_TX_TP_SUM > 0u)
STATIC VAR(boolean, PDUR_VAR)
PduR_UpTxConfirmation[PDUR_SRC_UP_MULTICAST_TX_IF_SUM + PDUR_SRC_UP_MULTICAST_TX_TP_SUM];
#else
STATIC P2VAR(boolean, AUTOMATIC,PDUR_APPL_DATA) PduR_UpTxConfirmation = NULL_PTR;
#endif/* PDUR_SRC_UP_MULTICAST_TX_IF_SUM + PDUR_SRC_UP_MULTICAST_TX_TP_SUM > 0u */
#define PDUR_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "PduR_MemMap.h"

/**
 * @brief up module Tx 1:n (only Tp)
 */
#define PDUR_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "PduR_MemMap.h"
#if(PDUR_SRC_UP_MULTICAST_TX_TP_SUM > 0u)

STATIC VAR(PduR_UpTxTpMulPduRunTimeType,PDUR_VAR) PduR_UpTxTpMulRoute[PDUR_SRC_UP_MULTICAST_TX_TP_SUM];
#else
STATIC P2VAR(PduR_UpTxTpMulPduRunTimeType, AUTOMATIC,PDUR_APPL_DATA) PduR_UpTxTpMulRoute = NULL_PTR;
#endif/* PDUR_SRC_UP_MULTICAST_TX_TP_SUM > 0u */
#define PDUR_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "PduR_MemMap.h"

#if(PDUR_TP_SUPPORT == STD_ON)
#define PDUR_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "PduR_MemMap.h"
/**
 * @brief gateway Tp routing path:all dest pdu(SF/MF,route to Tp or Up)
 */
#if(PDUR_DEST_GATEWAY_TP_PDU_SUM > 0u)

STATIC VAR(PduR_GateWayDestTpRunTimeType, PDUR_VAR) PduR_GateWayDestTpSate[PDUR_DEST_GATEWAY_TP_PDU_SUM];
#else
STATIC P2VAR(PduR_GateWayDestTpRunTimeType, AUTOMATIC, PDUR_APPL_DATA)
PduR_GateWayDestTpSate = NULL_PTR;
#endif/* PDUR_DEST_GATEWAY_TP_PDU_SUM > 0u */
#define PDUR_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "PduR_MemMap.h"
#endif /* #if(PDUR_TP_SUPPORT == STD_ON) */

/*====================================================================================================*
 *                                      LOCAL FUNCTION PROTOTYPES
 *====================================================================================================*/
#define PDUR_START_SEC_CODE
#include "PduR_MemMap.h"

#if(STD_ON == PDUR_UPMODE_SUPPORT)
STATIC FUNC(Std_ReturnType, PDUR_CODE)
PduR_UpperModeTransmit(
	VAR(PduIdType, PDUR_VAR) id,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info
);
#endif/* STD_ON == PDUR_UPMODE_SUPPORT */

#if(STD_ON == PDUR_UPMODE_CANCEL_TRANSMIT)
STATIC FUNC(Std_ReturnType, PDUR_CODE)
PduR_UpperModeCancelTransmit(
	VAR(PduIdType, PDUR_VAR) SrcPduId
);
#endif/* STD_ON == PDUR_UPMODE_CANCEL_TRANSMIT */

#if(STD_ON == PDUR_UPMODE_CHANGE_PARAMETER)
STATIC FUNC(Std_ReturnType, PDUR_CODE)
PduR_UpperModeChangeParameter(
	VAR(PduIdType, PDUR_VAR) id,
	VAR(TPParameterType, PDUR_VAR) parameter,
	VAR(uint16, PDUR_VAR) value
);
#endif/* STD_ON == PDUR_UPMODE_CHANGE_PARAMETER */

#if(STD_ON == PDUR_UPMODE_CANCEL_RECEIVE)
STATIC FUNC(Std_ReturnType, PDUR_CODE)
PduR_UpperModeCancelReceive(
	VAR(PduIdType, PDUR_VAR) id
);
#endif/* STD_ON == PDUR_UPMODE_CANCEL_RECEIVE */

#if(STD_ON == PDUR_LOWER_SUPPORT)
STATIC FUNC(void, PDUR_CODE)
PduR_LowerModeRxIndication(
	VAR(PduIdType, PDUR_VAR) RxPduId,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
);
#endif/* STD_ON == PDUR_LOWER_SUPPORT */

#if(STD_ON == PDUR_TX_CONFIRMATION)
STATIC FUNC(void, PDUR_CODE)
PduR_LowerModeTxConfirmation(
	VAR(PduIdType,PDUR_VAR) TxPduId
);
#endif /* STD_ON == PDUR_TX_CONFIRMATION */

#if(STD_ON == PDUR_TRIGGER_TRANSMIT)
STATIC FUNC(Std_ReturnType, PDUR_CODE)
PduR_LowerModeTriggerTransmit(
	VAR(PduIdType, PDUR_VAR) TxPduId,
	P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
);
#endif/* STD_ON == PDUR_TRIGGER_TRANSMIT */

#if(STD_ON == PDUR_TP_SUPPORT)
STATIC FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_LoTpStartOfReception(
	VAR(PduIdType, PDUR_VAR) srcPduId,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	VAR(PduLengthType, PDUR_VAR) TpSduLength,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
);

STATIC FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_LoTpCopyRxData(
	VAR(PduIdType, PDUR_VAR) srcPduId,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
);

STATIC FUNC(void, PDUR_CODE)
PduR_LoTpRxIndication(
	VAR(PduIdType, PDUR_VAR) srcPduId,
	VAR(Std_ReturnType, PDUR_VAR) ret
);

STATIC FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_LoTpCopyTxData(
	VAR(PduIdType,PDUR_VAR) TxPduId,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
);

STATIC FUNC(void, PDUR_CODE)
PduR_LoTpTxConfirmation(
	VAR(PduIdType, PDUR_VAR) id,
	VAR(Std_ReturnType, PDUR_VAR) ret
);

#endif/* STD_ON == PDUR_TP_SUPPORT */

STATIC FUNC(void, PDUR_CODE)
PduR_Memcpy(
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) dest,
    P2CONST(uint8, AUTOMATIC, AUTOMATIC) source,
	VAR(uint16, PDUR_VAR) length
);

#if((STD_ON == PDUR_CANIF_SUPPORT) || (STD_ON == PDUR_LINIF_SUPPORT))

/*Rx If pdu gateway to other If Pdus*/
STATIC FUNC(void, PDUR_CODE)
PduR_GateWayIfPdu(
	VAR(uint8, PDUR_VAR) DestModule,
	VAR(PduIdType, PDUR_VAR) RxPduId,
	VAR(PduIdType, PDUR_VAR) DestPduId,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) InfoPtr
);

#if(STD_ON == PDUR_CANIF_SUPPORT)
STATIC FUNC(void, PDUR_CODE)
PduR_GatewayCanIfPduHandle(
	VAR(PduIdType, PDUR_VAR) RxPduId,
	VAR(PduIdType, PDUR_VAR) PduId,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) InfoPtr,
	VAR(uint8, PDUR_VAR) DestModule
);
#endif

#if(STD_ON == PDUR_LINIF_SUPPORT)
STATIC FUNC(void, PDUR_CODE)
PduR_GatewayLinIfPduHandle(
	VAR(PduIdType, PDUR_VAR) RxPduId,
	VAR(PduIdType, PDUR_VAR) PduId,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) InfoPtr,
	VAR(uint8, PDUR_VAR) DestModule
);
#endif

/* store the If Rx Pdu data to buffer */
STATIC FUNC(void, PDUR_CODE)
PduR_EnQueueBuffer(
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)PduInfo,
	VAR(uint16, PDUR_VAR) bufId,
	VAR(uint8, PDUR_VAR) DestModule
);

/* clear the buffer(the buffer data have transmit,Whether or not it succeeds) */
STATIC FUNC(void, PDUR_CODE)
PduR_ClearQueueBuffer(
	VAR(uint16, PDUR_VAR) bufId
);
#endif/* (STD_ON == PDUR_CANIF_SUPPORT) || (STD_ON == PDUR_LINIF_SUPPORT) */

#if(STD_ON == PDUR_TP_SUPPORT)
/* if the tp buffer which have been copyed all data by all dest Tp Pdus,need clear the tp buffer */
STATIC FUNC(boolean, PDUR_CODE)
PduR_ClearGateWayOnTheFlyTpBuffer(
	VAR(PduIdType, PDUR_VAR) SrcPdu,
	VAR(uint8, PDUR_VAR)  CopyTpBufferNumber
);

/* copy the rx pdu data to the tp buffer */
STATIC FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_CopyRxDataToTpBuffer(
	VAR(uint8, PDUR_VAR) TpBufferId,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) Info,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) BufferSizePtr
);

/* find one unused tp buffer.if no unused tp buffer,return 0xffu */
STATIC FUNC(uint8, PDUR_CODE)
PduR_NextValidTpBuffer(
	void
);

/* gateway MF pdu to Tp mode by LoTp_Transmit */
STATIC FUNC(boolean, PDUR_CODE)
PduR_GateWayMFToTp(
	VAR(uint16, PDUR_VAR) PduRSrcPduId,
	VAR(uint16, PDUR_VAR) PduRDestPduId
);

/*gateway SF pdu to Tp mode by LoTp_Transmit*/
STATIC FUNC(Std_ReturnType, PDUR_CODE)
PduR_GateWaySFToTp(
	VAR(uint16, PDUR_VAR) PduRSrcPduId,
	VAR(uint16, PDUR_VAR) PduRDestPduId
);

/* SF Tp pdu 1:n(n>1) route:route the pdu to one up mode */
STATIC FUNC(void, PDUR_CODE)
PduR_RouteSFtoUp(
	VAR(uint8, PDUR_VAR) DestModule,
	VAR(uint16, PDUR_VAR) PduRSrcPduId,
	VAR(uint16, PDUR_VAR) PduRDestPduId
);

/* MF Tp pdu 1:n(n>1) route:route the pdu to one up mode */
STATIC FUNC(void, PDUR_CODE)
PduR_RouteMFtoUp(
	VAR(uint8, PDUR_VAR) DestModule,
	VAR(uint16, PDUR_VAR) PduRSrcPduId,
	VAR(uint16, PDUR_VAR) PduRDestPduId
);

/* find one valid tp buffer.if not find,return 0xffu */
STATIC FUNC(uint8, PDUR_CODE)
PduR_FindValidTpBuffer(
	VAR(uint16, PDUR_VAR) PduRSrcPduId,
	VAR(uint16, PDUR_VAR) PduLength
);

/* find the rx tp pdu active store tp buffer */
STATIC FUNC(uint8, PDUR_CODE)
PduR_FindTpBuffer(
	VAR(uint16, PDUR_VAR) PduRSrcPduId
);


/* Rx Tp Pdu gateway to only one Tp Module Pdu handle,when start of reception */
STATIC FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_StartOfReceptionToOneTpHandle(
	VAR(PduIdType, PDUR_VAR) SrcPduId,
	VAR(PduIdType, PDUR_VAR) DestPduId,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	VAR(PduLengthType, PDUR_VAR) Length,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
);

/* 1:n Rx Tp Pdu GateWay(more than one Tp Module,zero or one Up Module),when start of reception */
STATIC FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_StartOfReceptionToMoreModuleHandle(
	VAR(PduIdType, PDUR_VAR) SrcPduId,
	VAR(uint8, PDUR_VAR) DestPduNum,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	VAR(PduLengthType, PDUR_VAR) Length,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
);

/* Rx Tp Pdu gateway to only one Tp Module Pdu handle,when copy Rx Data */
STATIC FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_CopyRxDataToOneTpHandle(
	VAR(PduIdType, PDUR_VAR) SrcPduId,
	VAR(PduIdType, PDUR_VAR) DestPduId,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA)BufferSizePtr
);

/* 1:n Rx Tp Pdu GateWay(more than one Tp Module,zero or one Up Module),when copy Rx Data */
STATIC FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_CopyRxDataToMultitudeBswHandle(
	VAR(PduIdType, PDUR_VAR) SrcPduId,
	VAR(uint8, PDUR_VAR) destPduNum,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA)BufferSizePtr
);

/* Rx Tp Pdu gateway to only one Tp Module Pdu handle,when Rx Indication */
STATIC FUNC(void, PDUR_CODE)
PduR_RxIndicationToTpHandle(
	VAR(PduIdType, PDUR_VAR) SrcPduId,
	VAR(PduIdType, PDUR_VAR) DestPduId
);

/* 1:n Rx Tp Pdu GateWay(more than one Tp Module,zero or one Up Module),when Rx Indication */
STATIC FUNC(void, PDUR_CODE)
PduR_RxIndicationToMultitudeBswHandle(
	VAR(PduIdType, PDUR_VAR) SrcPduId,
	VAR(uint8, PDUR_VAR) DestPduSum
);

/* one Tp Pdu route to one Tp Pdu,the dest pdu copy tx data handle */
STATIC FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_FromTpCopyTxDataHandle(
	VAR(PduIdType, PDUR_VAR) SrcPduId,
	VAR(PduIdType, PDUR_VAR) ActualPduId,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	P2CONST(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
);

STATIC FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_HandleOneModuleOnFlyGateway(
	VAR(uint16, PDUR_VAR) tpRunTimeIndex,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	VAR(uint8, PDUR_VAR) tpBufferId,
	P2CONST(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
);

STATIC FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_HandleOneModuleNotOnFlyGateway(
	VAR(uint16, PDUR_VAR) tpRunTimeIndex,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	VAR(uint8, PDUR_VAR) tpBufferId,
	P2CONST(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
);

STATIC FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_HandleMultiModuleOnFlyGateway(
	VAR(PduIdType, PDUR_VAR) SrcPduId,
	VAR(uint16, PDUR_VAR) tpRunTimeIndex,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	VAR(uint8, PDUR_VAR) tpBufferId,
	P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
);

STATIC FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_HandleMultiModuleNotOnFlyGateway(
	VAR(uint16, PDUR_VAR) tpRunTimeIndex,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	VAR(uint8, PDUR_VAR) tpBufferId,
	P2CONST(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
);


/* one Tp Pdu route to more module Pdus,one dest Tp Pdu copy tx data handle */
STATIC FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_FromTpCopyTxDataToMultitudeBswHandle(
	VAR(PduIdType, PDUR_VAR) SrcPduId,
	VAR(PduIdType, PDUR_VAR) ActualPduId,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
);

/* one up module Tx Tp Pdu to one or more dest Tp Pdu,one Tp Pdu call the TpTxConfirmation Handle */
STATIC FUNC(void, PDUR_CODE)
PduR_UpTpTxConfirmationHandle(
	VAR(uint8, PDUR_VAR) srcModuleType,
	VAR(PduIdType, PDUR_VAR) SrcPduId,
	VAR(uint8, PDUR_VAR) DestPduNum,
	VAR(Std_ReturnType, PDUR_VAR) Ret
);

/* one up module Tx tp pdu(SF) to more Tp Module Pdus,the Lo Tp copy tx data */
STATIC FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_UpMulticastTpCopyData(
	VAR(uint8, PDUR_VAR) SrcModuleType,
	VAR(PduIdType, PDUR_VAR) SrcPduId,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
);

/* clear buffer and gateway state for gateway tp pdu */
STATIC FUNC(void, PDUR_CODE)
PduR_ClearGateWayTpBufferAndState(
	VAR(uint16, PDUR_VAR) PduRSrcPduId
);

/* 1:n(n>1)Tp route,at least one dest pdu is still need transmit,return (boolean)TRUE */
STATIC FUNC(boolean, PDUR_CODE)
PduR_AtLeastOneDestIsNotTxConfirm(
	VAR(uint16, PDUR_VAR) PduRSrcPduId
);

#endif/* STD_ON == PDUR_TP_SUPPORT */

#define PDUR_STOP_SEC_CODE
#include "PduR_MemMap.h"

/*====================================================================================================*
 *                                           LOCAL FUNCTIONS
 *====================================================================================================*/
#define PDUR_START_SEC_CODE
#include "PduR_MemMap.h"
/**
 * @brief			transmit pdu
 * @param[in]		id : Source Pdu Id
 * @param[in]		info : Length and pointer to the buffer of the I-PDU.
 * @param[out]		/
 * @param[in/out]	/
 * @return			Std_ReturnType
 * @retval			E_OK
 * 					E_NOT_OK
 */
#if(STD_ON == PDUR_UPMODE_SUPPORT)
STATIC FUNC(Std_ReturnType, PDUR_CODE)
PduR_UpperModeTransmit(
	VAR(PduIdType, PDUR_VAR) id,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
	Std_ReturnType retValue ;
	Std_ReturnType tpRet = (Std_ReturnType)E_NOT_OK;
	Std_ReturnType ifRet = (Std_ReturnType)E_NOT_OK;
	PduIdType destPduId;
	uint8 destPduNumber;
	uint8 destModuleType;
	uint8 index;
	/* PRQA S 0491 EOF #violate MISAR2004_17.4 ingore this warnning*/
	destPduNumber = PduR_ConfigData->PduRRoutingTableRef[id].DestPduNumber;
	/**
	 * @req [SWS_PduR_00256] The PDU Router module shall not retry transmission if the destination
	 * 						 communication interface module returns (Std_ReturnType)E_NOT_OK after
	 * 						 calling <DstLo>_Transmit.
	 */
	for(index = (uint8)0; index < destPduNumber;index++)
	{
		/**
		 * @req [SWS_PduR_00646] The PDU Router shall immediately disable the routing path groups.
		 * 						 Disabling of routing path groups inhibits forwarding of the following
		 * 						  APIs and return (Std_ReturnType)E_NOT_OK
		 */
		if((boolean)TRUE == PathIsEnabled[id])
		{
			/**
			 * @req [SWS_PduR_00633] If there are more than one lower layer destination modules
			 * 						 in a transmission request (1:n, n>1), all of these modules
			 * 						 must either be communication interface modules or transport
			 * 						 protocol modules. Not a mix of them
			 */
			/**
			 * @req [SWS_PduR_00766] The PDU Router module shall convert the I-PDU ID to the
			 * 						 destination module(s) for both transmission path and
			 * 						 confirmation/indication path.
			 */
			destModuleType = PduR_ConfigData->PduRRoutingTableRef[id].PduRDestPduIdRef[index].\
					DestModuleType;
			destPduId = PduR_ConfigData->PduRRoutingTableRef[id].PduRDestPduIdRef[index].DestPduId;
			if(PduR_ConfigData->PduRRoutingTableRef[id].RouteIsTp == (boolean)FALSE)
			{
				if(PduRLo_Transmit[destModuleType] != NULL_PTR)
				{
					retValue = PduRLo_Transmit[destModuleType](destPduId,info);
					if(retValue == (Std_ReturnType)E_OK)
					{
						if(destPduNumber == (uint8)1)
						{
							ret = (Std_ReturnType)E_OK;
						}
						else
						{
							ifRet = (Std_ReturnType)E_OK;
						}
					}
				}
				/**
				 * @req [SWS_PduR_00218] If the provided I-PDU ID represents a group of PDUs
				 * 						(multicast transmit request) and at least one of the forwarded
				 * 						transmit requests returns successfully, the function PduR_<Up>
				 * 						Transmit shall return (Std_ReturnType)E_OK.
				 */
			}
			else
			{
				if((uint8)1== destPduNumber)
				{
					/**
					 * @req [SWS_PduR_00161] The PDU Router module shall identify routing path uniquely
					 * 						 by the combination of source module I-PDU ID (located in
					 * 						 the PDU Router configuration) and destination I-PDU IDs
					 * 						 (located in the called destination module configurations).
					 */
					destPduId = PduR_ConfigData->PduRRoutingTableRef[id].PduRDestPduIdRef[0].DestPduId;
					if(PduRLo_Transmit[destModuleType] != NULL_PTR)
					{
						/**
						 * @req [SWS_PduR_00626] If singlecast (1:1) the return value of the <Lo>_
						 * 						 Transmit call shall be forwarded to the source
						 * 						 upper layer module
						 */
						ret = PduRLo_Transmit[destModuleType](destPduId,info);
					}
				}

				else
				{
					/**
					 * @req [SWS_PduR_00803] When one destination fails (Transmit returns E_NOT_OK),
					 * 						 the other destinations shall continue.
					 */
					/**
					 * @req [SWS_PduR_00806] When one destination fails (Transmit returns E_NOT_OK),
					 * 						 the other destinations shall continue.
					 */
					PduR_UpTxTpMulRoute[PduR_ConfigData->PduRSrcPduRef[id].TxTpMulticastIndex].\
					ActiveDestNumber = (uint8)0;
					PduR_UpTxTpMulRoute[PduR_ConfigData->PduRSrcPduRef[id].TxTpMulticastIndex].\
					DestCopyDataTimer = (uint8)0;
					if(PduRLo_Transmit[destModuleType] != NULL_PTR)
					{
						/**
						 * @req [SWS_PduR_00625] When source upper layer module calls PduR_<Up>Transmit
						 * 						 the PDU Router shall call <Lo>_Transmit for each
						 * 						 destination communication interface module
						 */
						/**
						 * @req [SWS_PduR_00745] If the I-PDU is transmitted by an upper layer module
						 * 						 the PDU Router module shall not check the length of
						 * 						 the I-PDU
						 */
						retValue = PduRLo_Transmit[destModuleType](destPduId,info);
						if(retValue == (Std_ReturnType)E_OK)
						{
							tpRet = (Std_ReturnType)E_OK;
							PduR_UpTxTpMulRoute[PduR_ConfigData->PduRSrcPduRef[id].TxTpMulticastIndex].\
							ActiveDestNumber += (uint8)1;
						}
					}
				}
			}
		}
		else
		{
			ret = (Std_ReturnType)E_NOT_OK;
		}

	}
	/**
	 * @req [SWS_PduR_00218] If the provided I-PDU ID represents a group of PDUs (multicast transmit
	 * 						 request) and at least one of the forwarded transmit requests returns
	 * 						 successfully, the function PduR_<Up>Transmit shall return E_OK.
	 */
	if(destPduNumber > (uint8)1)
	{
		if((Std_ReturnType)E_OK == ifRet)
		{
			if((boolean)TRUE == PduR_ConfigData->PduRSrcPduRef[id].PduRSrcPduUpTxConf)
			{
				/* route 1:n,used to handle just the first dest TxConfirm will call up TxConfirm */
				PduR_UpTxConfirmation[PduR_ConfigData->PduRSrcPduRef[id].UpTxconfirmStateIndex] = \
						(boolean)FALSE;
			}
			ret = (Std_ReturnType)E_OK;
		}
		else if((Std_ReturnType)E_OK == tpRet)
		{
			/* define to up TxConfirmation with (Std_ReturnType)E_OK or (Std_ReturnType)E_NOT_OK */
			PduR_UpTxConfirmation[PduR_ConfigData->PduRSrcPduRef[id].UpTxconfirmStateIndex] = \
					(boolean)FALSE;
			ret = (Std_ReturnType)E_OK;
		}
		else
		{
		}
	}
	return ret;
}
#endif/* STD_ON == PDUR_UPMODE_SUPPORT */

/**
 * @brief			cancel transmit pdu
 * @param[in]		SrcPduId : Source Pdu Id
 * @param[out]		/
 * @param[in/out]	/
 * @return			Std_ReturnType
 * @retval			E_OK
 * 					E_NOT_OK
 */
#if(STD_ON == PDUR_UPMODE_CANCEL_TRANSMIT)
STATIC FUNC(Std_ReturnType, PDUR_CODE)
PduR_UpperModeCancelTransmit(
	VAR(PduIdType, PDUR_VAR) SrcPduId
)
{
	Std_ReturnType ret;
	boolean retOk = (boolean)TRUE;
	PduIdType destPduId;
	uint8 destPduNum;
	uint8 index;
	uint8 destModuleType,moduleIndex;
	const PduRBswModuleType* module = NULL_PTR;
	destPduNum = PduR_ConfigData->PduRRoutingTableRef[SrcPduId].DestPduNumber;
	for(index = 0u;(index < destPduNum) && ((boolean)TRUE == retOk); index++)
	{
		destPduId = PduR_ConfigData->PduRRoutingTableRef[SrcPduId].PduRDestPduIdRef[index].DestPduId;
		destModuleType = PduR_ConfigData->PduRRoutingTableRef[SrcPduId].PduRDestPduIdRef[index].\
				DestModuleType;
		for(moduleIndex = 0u; moduleIndex < (uint8)PDUR_BSW_MODULE_SUM; moduleIndex++)
		{
			if(PduR_BswModuleConfigData[moduleIndex].PduRBswModuleRef == destModuleType)
			{
				module = &PduR_BswModuleConfigData[moduleIndex];
				break;
			}
		}
		/**
		 * @req [SWS_PduR_00710] If the routing path for the requested I-PDU is disabled, then PduR_<Up>
		 * 						 CancelTransmit shall return (Std_ReturnType)E_NOT_OK directly without
		 * 						 any further action
		 */
		if(((boolean)TRUE == PathIsEnabled[SrcPduId]) && \
		   ((module != NULL_PTR) && (module->PduRCancelTransmit == (boolean)TRUE)))
		{
			/**
			 * @req [SWS_PduR_00722] [SWS_PduR_00625] [SWS_PduR_00721]The PDU Router module shall
			 * 						 call the <LoTp>_CancelTransmit for the destination module of
			 * 						 the I-PDU
			 */
			if(PduRUp_CancelTransmit[destModuleType] != NULL_PTR)
			{
				/**
				 * @req [SWS_PduR_00700] [SWS_PduR_00745] The PDU Router module shall return same
				 * 						 return value to the calling upper layer module
				 */
				if((Std_ReturnType)E_NOT_OK == PduRUp_CancelTransmit[destModuleType](destPduId))
				{
					retOk = (boolean)FALSE;
				}
			}
		}
		else
		{
			retOk = (boolean)FALSE;
		}

	}
	/**
	 * @req [SWS_PduR_00701] (Std_ReturnType)E_OK shall be returned to the calling upper layer if all
	 * 						 destination modules return (Std_ReturnType)E_OK, otherwise E_NOT_OK
	 * 						 shall be returned
	 */
	if((boolean)TRUE == retOk)
	{
		ret = (Std_ReturnType)E_OK;
	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	return ret;
}
#endif/* STD_ON == PDUR_UPMODE_CANCEL_TRANSMIT */

/**
 * @brief			Change Pdu Parameter
 * @param[in]		id : Source Pdu Id
 * @param[in]		parameter : need to change parameter
 * @param[in]		value
 * @param[out]		/
 * @param[in/out]	/
 * @return			Std_ReturnType
 * @retval			E_OK
 * 					E_NOT_OK
 */
#if(STD_ON == PDUR_UPMODE_CHANGE_PARAMETER)
STATIC FUNC(Std_ReturnType, PDUR_CODE)
PduR_UpperModeChangeParameter(
	VAR(PduIdType, PDUR_VAR) id,
	VAR(TPParameterType, PDUR_VAR) parameter,
	VAR(uint16, PDUR_VAR) value
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
	PduIdType srcPduId;
	PduIdType actualPduId;
	uint8 destPduNum;
	uint8 index;
	uint8 destModuleType = 0u;
	const PduRBswModuleType* module = NULL_PTR;
	uint8 cnt;
	/**
	 * @req [SWS_PduR_00747] The I-PDU id provided in the call is Rx I-PDU ID and therefore the PDU
	 * 						 Router module shall be able to identify this I-PDU correctly
	 */
	srcPduId = PduR_ConfigData->PduRDestPduRef[id].PduRSrcPduRef;
	actualPduId = PduR_ConfigData->PduRDestPduRef[id].ActualPduId;
	destPduNum = PduR_ConfigData->PduRRoutingTableRef[srcPduId].DestPduNumber;
	for(index = 0u; index < destPduNum; index++)
	{
		if(PduR_ConfigData->PduRRoutingTableRef[srcPduId].PduRDestPduIdRef[index].DestPduId == \
				actualPduId)
		{
			destModuleType = PduR_ConfigData->PduRRoutingTableRef[srcPduId].PduRDestPduIdRef[index].\
					DestModuleType;
			break;
		}
	}
	for(cnt = 0u;cnt < (uint8)PDUR_BSW_MODULE_SUM; cnt++)
	{
		if(PduR_BswModuleConfigData[cnt].PduRBswModuleRef == destModuleType)
		{
			module = &PduR_BswModuleConfigData[cnt];
		}
	}
	if(((boolean)TRUE == PathIsEnabled[srcPduId]) && \
		((NULL_PTR != module) && (module->PduRChangeParameterApi == (boolean)TRUE)))
	{
		/**
		 * @req [SWS_PduR_00733] When the PduR_<Up>ChangeParameter is called the PDU Router module
		 * 						 shall call the <LoTp>_ChangeParameter for the destination transport
		 * 						 protocol module of the I-PDU
		 */
		if((destModuleType == PDUR_CANTP) || (destModuleType == PDUR_LINTP) || \
				(destModuleType == PDUR_J1939TP))
		{
			if(PduRUp_ChangeParameter[destModuleType] != NULL_PTR)
			{
				if((Std_ReturnType)E_OK == PduRUp_ChangeParameter[destModuleType]\
						(actualPduId,parameter,value))
				{
					ret = (Std_ReturnType)E_OK;
				}
			}
		}
	}
	return ret;
}
#endif/* STD_ON == PDUR_UPMODE_CHANGE_PARAMETER */

/**
 * @brief			Cancel Receive Pdu
 * @param[in]		id : Pdu Id
 * @param[out]		/
 * @param[in/out]	/
 * @return			Std_ReturnType
 * @retval			E_OK
 * 					E_NOT_OK
 */
#if(STD_ON == PDUR_UPMODE_CANCEL_RECEIVE)
STATIC FUNC(Std_ReturnType, PDUR_CODE)
PduR_UpperModeCancelReceive(
	VAR(PduIdType, PDUR_VAR) id
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
	PduIdType srcPduId;
	uint8 destModuleType = 0u;
	uint8 actualPduId;
	uint8 destPduNum,index;
	uint8 cnt;
	PduIdType destPduId = 0xffffu;
	const PduRBswModuleType* module = NULL_PTR;
	actualPduId = (uint8)PduR_ConfigData->PduRDestPduRef[id].ActualPduId;
	/**
	 * @req [SWS_PduR_00736] The I-PDU id provided in the call is Rx I-PDU ID and therefore the PDU
	 * 						 Router module shall be able to identify this I-PDU correctly
	 */
	srcPduId = PduR_ConfigData->PduRDestPduRef[id].PduRSrcPduRef;
	destPduNum = PduR_ConfigData->PduRRoutingTableRef[srcPduId].DestPduNumber;
	for(index = 0u; index < destPduNum; index++)
	{
		if(PduR_ConfigData->PduRRoutingTableRef[srcPduId].PduRDestPduIdRef[index].DestPduId == \
				actualPduId)
		{
			destModuleType = PduR_ConfigData->PduRRoutingTableRef[srcPduId].PduRDestPduIdRef[index].\
					DestModuleType;
			destPduId = PduR_ConfigData->PduRRoutingTableRef[srcPduId].PduRDestPduIdRef[index].\
					DestPduId;
			break;
		}
	}
	for(cnt = 0u; cnt < (uint8)PDUR_BSW_MODULE_SUM; cnt++)
	{
		if(PduR_BswModuleConfigData[cnt].PduRBswModuleRef == destModuleType)
		{
			module = &PduR_BswModuleConfigData[cnt];
			break;
		}
	}
	if(((boolean)TRUE == PathIsEnabled[srcPduId]) && \
		((NULL_PTR != module) && (module->PduRCancelReceive == (boolean)TRUE)))
	{
		/**
		 * @req [SWS_PduR_00727] When the PduR_<Up>CancelReceive is called the PDU Router module shall
		 * 						 call the <LoTp>_CancelReceive for the destination transport protocol
		 * 						 module of the I-PDU
		 */
		if(PduRUp_CancelReceive[destModuleType] != NULL_PTR)
		{
			/**
			 * @req [SWS_PduR_00732] The return value of the <LoTp>_CancelReceive shall be forwarded
			 * 						 to the upper layer module
			 */
			ret = PduRUp_CancelReceive[destModuleType](destPduId);
		}
	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	return ret;
}
#endif/* STD_ON == PDUR_UPMODE_CANCEL_RECEIVE */

/**
 * @brief			Handle RxIndication
 * @param[in]		RxPduId : Pdu Id
 * @param[in]		PduInfoPtr: Contains the length (SduLength) of the received I-PDU and a pointer
 * 					to a buffer (SduDataPtr) containing the I-PDU.
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
#if(STD_ON == PDUR_LOWER_SUPPORT)
STATIC FUNC(void, PDUR_CODE)
PduR_LowerModeRxIndication(
	VAR(PduIdType, PDUR_VAR) RxPduId,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
)
{
	uint8 destPduNumber;
	uint8 cnt;
	PduIdType destPduId;
	uint8 destModuleType;
	destPduNumber = PduR_ConfigData->PduRRoutingTableRef[RxPduId].DestPduNumber;
	/**
	 * @req [SWS_PduR_00164] The PDU Router module shall provide 1:n routing for an IPDU received from
	 * 						 a communication interface module and routed to one or more upper layer \
	 * 						 module(s)
	 */
	for (cnt = (uint8)0; cnt < (uint8)destPduNumber; cnt++)
	{
		destModuleType = PduR_ConfigData->PduRRoutingTableRef[RxPduId].PduRDestPduIdRef[cnt].\
				DestModuleType;
		destPduId = PduR_ConfigData->PduRRoutingTableRef[RxPduId].PduRDestPduIdRef[cnt].DestPduId;
		if((boolean)TRUE == PathIsEnabled[RxPduId])
		{
			if((destModuleType != PDUR_CANIF) && (destModuleType != PDUR_LINIF))
			{
				if(PduRUp_RxIndication[destModuleType] != NULL_PTR)
				{
					/**
					 * @req [SWS_PduR_00744] If the I-PDU is received by a local module the PDU Router
					 * 						 shall not check the length of the I-PDU, just forward the
					 * 						 indication to the upper layer module
					 */
					PduRUp_RxIndication[destModuleType](destPduId,PduInfoPtr);
				}
			}
			else
			{
#if((STD_ON == PDUR_CANIF_SUPPORT) || (STD_ON == PDUR_LINIF_SUPPORT))
				PduR_GateWayIfPdu(destModuleType,RxPduId, destPduId, PduInfoPtr);
#endif
			}
		}
	}
	return;
}
#endif/* STD_ON == PDUR_LOWER_SUPPORT */

/**
 * @brief			Handle TxConfirmation
 * @param[in]		RxPduId : Pdu Id
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
#if(STD_ON == PDUR_TX_CONFIRMATION)
STATIC FUNC(void, PDUR_CODE)
PduR_LowerModeTxConfirmation(
	VAR(PduIdType,PDUR_VAR) TxPduId
)
{
	PduIdType srcUpPduId;
#if(STD_ON == PDUR_CANIF_SUPPORT || STD_ON == PDUR_LINIF_SUPPORT)
	PduInfoType pduInfo;
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
#endif
	uint16 bufferId = 0xffu;
	PduIdType srcPduId;
	uint8 srcPduModType;
	uint8 destPduNum;
	uint16 actualId;
	uint8 index;
	PduR_DestPduDataProvisionType destPduDataProvision;
	PduIdType pduRGatewayDirectTxStateId;
	srcPduId = PduR_ConfigData->PduRDestPduRef[TxPduId].PduRSrcPduRef;
	srcPduModType = PduR_ConfigData->PduRSrcPduRef[srcPduId].SrcModuleType;
	if(PathIsEnabled[srcPduId] == (boolean)TRUE)
	{
		if(((srcPduModType != PDUR_CANIF) && (srcPduModType != PDUR_LINIF)))
		{
			if((boolean)TRUE == PduR_ConfigData->PduRSrcPduRef[srcPduId].PduRSrcPduUpTxConf)
			{
				srcUpPduId = PduR_ConfigData->PduRSrcPduRef[srcPduId].PduRSrcModulePduId;
				/* route 1:1 Pdu from up module to lo If module */
				if((uint16)0xffff == PduR_ConfigData->PduRSrcPduRef[srcPduId].UpTxconfirmStateIndex)
				{
					/**
					 * @req [SWS_PduR_00589] In case of a multicast (1:n, n>1), communication interface
					 * 						 transmission, the PDU Router shall call the transmit
					 * 						 confirmation API of the upper layer module as soon as the
					 * 						 first transmit confirmation from a communication interface
					 * 						 module which supports transmit confirmation has been received
					 */
					if(PduRUp_TxConfirmation[srcPduModType] != NULL_PTR)
					{
						PduRUp_TxConfirmation[srcPduModType](srcUpPduId);
					}

				}
			/* route 1:n Pdu from up module to lo If module,only the first Lo TxConfirm call Up TxConfirm */
				else
				{
					if((boolean)FALSE == PduR_UpTxConfirmation[PduR_ConfigData->PduRSrcPduRef[srcPduId].\
															   UpTxconfirmStateIndex])
					{
						/**
						 * @req [SWS_PduR_00589] In case of a multicast (1:n, n>1), communication interface
						 * 						 transmission, the PDU Router shall call the transmit
						 * 						 confirmation API of the upper layer module as soon as the
						 * 						 first transmit confirmation from a communication interface
						 * 						 module which supports transmit confirmation has been
						 * 						 received
						 */
						if(PduRUp_TxConfirmation[srcPduModType] != NULL_PTR)
						{
							PduRUp_TxConfirmation[srcPduModType](srcUpPduId);
							PduR_UpTxConfirmation[PduR_ConfigData->PduRSrcPduRef[srcPduId].\
												  UpTxconfirmStateIndex] = (boolean)TRUE;
						}
					}
				}
			}
		}
		else
		{
			actualId = PduR_ConfigData->PduRDestPduRef[TxPduId].ActualPduId;
			destPduNum = PduR_ConfigData->PduRRoutingTableRef[srcPduId].DestPduNumber;
			for(index = 0u; index < destPduNum; index++)
			{
				if(PduR_ConfigData->PduRRoutingTableRef[srcPduId].PduRDestPduIdRef[index].DestPduId == \
						actualId)
				{
					bufferId = PduR_ConfigData->PduRRoutingTableRef[srcPduId].PduRDestPduIdRef[index].\
							PduRDestTxBufferRef;
					destPduDataProvision = PduR_ConfigData->PduRRoutingTableRef[srcPduId].\
							PduRDestPduIdRef[index].PduRDestPduDataProvision;
					pduRGatewayDirectTxStateId = PduR_ConfigData->PduRRoutingTableRef[srcPduId].\
							PduRDestPduIdRef[index].PduRGatewayDirectTxStateIndex;
					break;
				}
			}
			/* the pdu config buffer and it's PDUR_DIRECT mode */
			/**
			 * @req [SWS_PduR_00640] If the destination communication interface module confirms the
			 * 						 transmission of the I-PDU using PduR_<DstLo>TxConfirmation and
			 * 						 destination is not a direct data provision Pdu with FIFO buffer
			 * 						 the PDU Router module shall not do anything
			 */
			if(((uint16)0xff != bufferId) && (PDUR_DIRECT == destPduDataProvision) && 0xffff !=pduRGatewayDirectTxStateId)
			{
				/**
				 * @req [SWS_PduR_00303] When <DstLo>_Transmit is called the <DstLo> module copies the
				 * 						 data and the PDU Router does not buffer the transmitted I-PDU
				 * 						 any longer.
				 */
				PduR_DestPduState[pduRGatewayDirectTxStateId] = PDUR_IDLE;
				if((boolean)TRUE == PduR_TxBuffer[bufferId].PduRTxBufferRef->used)
				{
#if(STD_ON == PDUR_CANIF_SUPPORT || STD_ON == PDUR_LINIF_SUPPORT)
					pduInfo.SduDataPtr = PduR_TxBuffer[bufferId].PduRTxBufferRef[0].TxBufferData;
					pduInfo.SduLength = PduR_TxBuffer[bufferId].PduRTxBufferRef[0].SduLength;
					if(PduRLo_Transmit[srcPduModType] != NULL_PTR)
					{
						ret = PduRLo_Transmit[srcPduModType](actualId, &pduInfo);
					}
					if((Std_ReturnType)E_OK == ret)
					{
						PduR_DestPduState[pduRGatewayDirectTxStateId] = PDUR_BUSY;
					}
					else
#endif
					{
						/**
						 * @req [SWS_PDUR_00807] When <DstLo>_Transmit() returns E_NOT_OK for a routing
						 * 						 path using a FIFO, the PDU Router shall report
						 * 						 PDUR_E_PDU_INSTANCES_LOST to the DET module
						 */
						/* transmit not ok(FIFO),report det error */
						if(PduR_TxBuffer[bufferId].PduRTxBufferDepth >(uint16) 1)
						{
							#if(STD_ON == PDUR_DEV_ERROR_DETECT)
							PDUR_DET_ERROR_REPORT(PDUR_SID_CANIFTXCONFIRMATION, \
									PDUR_E_PDU_INSTANCES_LOST);
							#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
						}
					}
#if(STD_ON == PDUR_CANIF_SUPPORT || STD_ON == PDUR_LINIF_SUPPORT)
					PduR_ClearQueueBuffer(bufferId);
#endif
				}
			}
		}
	}
	else
	{
		/* do nothing */
	}
}
#endif /*STD_ON == PDUR_TX_CONFIRMATION*/

/**
 * @brief			Handle Trigger Transmit Request
 * @param[in]		TxPduId : Pdu Id
 * @param[in]		PduInfoPtr: Contains the length (SduLength) of the I-PDU and a pointer
 * 					to a buffer (SduDataPtr) containing the I-PDU.
 * @param[out]		/
 * @param[in/out]	Std_ReturnType
 * @return			E_OK
 * @retval			E_NOT_OK
 */
#if(STD_ON == PDUR_TRIGGER_TRANSMIT)
STATIC FUNC(Std_ReturnType, PDUR_CODE)
PduR_LowerModeTriggerTransmit(
	VAR(PduIdType, PDUR_VAR) TxPduId,
	P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
    PduIdType srcPduId;
    PduIdType upPduId;
    uint8 srcModuleType;
    uint16 bufferId = 0u;
#if(STD_ON == PDUR_CANIF_SUPPORT || STD_ON == PDUR_LINIF_SUPPORT)
    PduInfoType pduInfo;
#endif
    uint8 destPduNum;
    uint8 actualId;
    uint8 index;
    uint8 moduleIndex;
    const PduRBswModuleType* modulePtr = NULL_PTR;
    srcPduId = PduR_ConfigData->PduRDestPduRef[TxPduId].PduRSrcPduRef;
	srcModuleType = PduR_ConfigData->PduRSrcPduRef[srcPduId].SrcModuleType;
    if((boolean)TRUE == PathIsEnabled[srcPduId])
    {
    	for(moduleIndex = 0u;moduleIndex < (uint8)PDUR_BSW_MODULE_SUM; moduleIndex++)
    	{
    		if(PduR_BswModuleConfigData[moduleIndex].PduRBswModuleRef == srcModuleType)
    		{
    			modulePtr = &PduR_BswModuleConfigData[moduleIndex];
    			break;
    		}
    	}
    	if((srcModuleType != PDUR_CANIF) && (srcModuleType != PDUR_LINIF))
    	{
    		if((NULL_PTR != modulePtr) && ((boolean)TRUE == modulePtr->PduRTriggertransmit))
    		{
    			upPduId = PduR_ConfigData->PduRSrcPduRef[srcPduId].PduRSrcModulePduId;
    			/**
    			 * @req [SWS_PduR_00661] The PDU Router module shall copy the return value from the
    			 * 						 <Up>_TriggerTransmit to the lower layer module
    			 */
    			if(PduRUp_TriggerTransmit[srcModuleType] != NULL_PTR)
    			{
    				ret = PduRUp_TriggerTransmit[srcModuleType](upPduId,PduInfoPtr);
    			}
    		}
    	}
    	else
    	{
			destPduNum = PduR_ConfigData->PduRRoutingTableRef[srcPduId].DestPduNumber;
			actualId = (uint8)PduR_ConfigData->PduRDestPduRef[TxPduId].ActualPduId;
			for(index = 0u;index < destPduNum; index++)
			{
				if(PduR_ConfigData->PduRRoutingTableRef[srcPduId].PduRDestPduIdRef[index].DestPduId == \
						actualId)
				{
					bufferId = PduR_ConfigData->PduRRoutingTableRef[srcPduId].PduRDestPduIdRef[index].\
							PduRDestTxBufferRef;
				}
			}
			if(PduInfoPtr->SduLength >= PduR_TxBuffer[bufferId].PduRTxBufferRef[0].SduLength)
			{
				PduInfoPtr->SduLength = PduR_TxBuffer[bufferId].PduRTxBufferRef[0].SduLength;
				PduR_Memcpy(
							PduInfoPtr->SduDataPtr,
							PduR_TxBuffer[bufferId].PduRTxBufferRef[0].TxBufferData,
							(uint16)PduInfoPtr->SduLength);
				if(PduR_TxBuffer[bufferId].PduRTxBufferDepth >(uint16) 1)
				{
#if(STD_ON == PDUR_CANIF_SUPPORT || STD_ON == PDUR_LINIF_SUPPORT)
					PduR_ClearQueueBuffer(bufferId);
					if((boolean)TRUE == PduR_TxBuffer[bufferId].PduRTxBufferRef[0].used)
					{
						pduInfo.SduDataPtr = NULL_PTR;
						pduInfo.SduLength = (PduLengthType)0;
						if(PduRLo_Transmit[srcModuleType] != NULL_PTR)
						{
							(void)PduRLo_Transmit[srcModuleType]((PduIdType)actualId, &pduInfo);
						}
					}
#endif
				}
				ret = (Std_ReturnType)E_OK;
			}
    	}
    }
    return ret;
}
#endif/* STD_ON == PDUR_TRIGGER_TRANSMIT */

/**
 * @brief			Handle Start of reception
 * @param[in]		srcPduId : Pdu Id
 * @param[in]		PduInfoPtr: Contains the length (SduLength) of the I-PDU and a pointer
 * 					to a buffer (SduDataPtr) containing the I-PDU.
 * @param[in]		TpSduLength
 * @param[in]		bufferSizePtr : The size of the upper available space that needs to be confirmed
 * @param[out]		/
 * @param[in/out]	/
 * @return			BufReq_ReturnType
 * @retval			BUFREQ_OK
    				BUFREQ_E_NOT_OK
    				BUFREQ_E_BUSY
          	  	  	BUFREQ_E_OVFL
 * @req [SWS_PduR_00549] When a source transport protocol module indicates the start of a reception
 * 						 of a PDU that has only upper layer destinations using PduR_<LoTp>Start
 * 						 OfReception, the PDU Router module shall forward the request to the
 * 						 destination upper layer module by calling <Up>_StartOfReception
 */
#if(STD_ON == PDUR_TP_SUPPORT)
STATIC FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_LoTpStartOfReception(
	VAR(PduIdType, PDUR_VAR) srcPduId,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	VAR(PduLengthType, PDUR_VAR) TpSduLength,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
	BufReq_ReturnType bufQeqRet = BUFREQ_E_NOT_OK;
	uint8 destPduNum;
	PduIdType pduRDestPduId;
	uint8 destModuleType;
	destPduNum = PduR_ConfigData->PduRRoutingTableRef[srcPduId].DestPduNumber;
	/*one dest pdu*/
	if(1u == destPduNum)
	{
		destModuleType = PduR_ConfigData->PduRRoutingTableRef[srcPduId].PduRDestPduIdRef[0].\
				DestModuleType;
		pduRDestPduId = PduR_ConfigData->PduRRoutingTableRef[srcPduId].PduRDestPduIdRef[0].DestPduId;
		/**
		 * @req [SWS_PduR_00789] In case of gatewaying, when a successful RxIndication is received by
		 * 						 PduR from the lower layer, the module shall initiate a reception
		 * 						 session for a configured upper layer destination: StartOfReception,
		 * 						<UpTp>_CopyRxData, and <UpTp>_RxIndication will be called in this order
		 */
		if((boolean)TRUE == PathIsEnabled[srcPduId])
		{
			if((destModuleType != PDUR_CANTP) && (destModuleType != PDUR_LINTP) && \
					(destModuleType != PDUR_J1939TP))
			{
				if(PduRUp_TpStartOfReception[destModuleType] != NULL_PTR)
				{
					bufQeqRet = (BufReq_ReturnType)PduRUp_TpStartOfReception[destModuleType]\
							(pduRDestPduId,info,TpSduLength,bufferSizePtr);
				}
			}
			else
			{
				/**
				 * @req [SWS_PduR_00623] The PDU Router shall forward the return value of the <Up>_
				 * 						 StartOfReception to the source transport protoco
				 */
				bufQeqRet = PduR_StartOfReceptionToOneTpHandle\
						(srcPduId,pduRDestPduId,info,TpSduLength,bufferSizePtr);
			}
		}
		/**
		 *  @req [SWS_PDUR_00805] Disabling of routing path groups in case of gatewaying shall
		 *  					  disable the following APIs and APIs with BufReq_ReturnType
		 * 						  shall return BUFREQ_E_NOT_OK
		 */
		else
		{
			bufQeqRet = BUFREQ_E_NOT_OK;
		}
	}
	/* Receive Tp pdu and route the pdu to more than one module */
	else
	{
		if((boolean)TRUE == PathIsEnabled[srcPduId])
		{
			bufQeqRet = PduR_StartOfReceptionToMoreModuleHandle\
					(srcPduId, destPduNum, info, TpSduLength, bufferSizePtr);
		}
		else
		{
			bufQeqRet = BUFREQ_E_NOT_OK;
		}
	}
	return bufQeqRet;
}

/**
 * @req [SWS_PduR_00428] When a source transport protocol module requests the PDU Router module to
 * 						 copy the received data using PduR_<LoTp>CopyRxData, the PDU Router module
 * 						 shall forward the request to the destination upper layer module by calling
 * 						 <Up>_CopyRxData
 */
/**
 * @brief			Handle Copy Rx Data
 * @param[in]		srcPduId : Pdu Id
 * @param[in]		info : Contains the length (SduLength) of the I-PDU and a pointer
 * 					to a buffer (SduDataPtr) containing the I-PDU.
 * @param[in]		bufferSizePtr : The size of the upper available space that needs to be confirmed
 * @param[out]		/
 * @param[in/out]	/
 * @return			BufReq_ReturnType
 * @retval			BUFREQ_OK
    				BUFREQ_E_NOT_OK
    				BUFREQ_E_BUSY
          	  	  	BUFREQ_E_OVFL
 */
STATIC FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_LoTpCopyRxData(
	VAR(PduIdType, PDUR_VAR) srcPduId,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
	BufReq_ReturnType ret = BUFREQ_E_NOT_OK;
	uint8 destPduNum;
	PduIdType destPduId;
	uint8 destModuleType;
	destPduNum = PduR_ConfigData->PduRRoutingTableRef[srcPduId].DestPduNumber;
	/* one dest pdu */
	if(1u == destPduNum)
	{
		destPduId = PduR_ConfigData->PduRRoutingTableRef[srcPduId].PduRDestPduIdRef[0].DestPduId;
		destModuleType = PduR_ConfigData->PduRRoutingTableRef[srcPduId].PduRDestPduIdRef[0].\
				DestModuleType;
		if((boolean)TRUE == PathIsEnabled[srcPduId])
		{
			if((destModuleType != PDUR_CANTP) && (destModuleType != PDUR_LINTP) \
					&& (destModuleType != PDUR_J1939TP))
			{
				if(PduRUp_TpCopyRxData[destModuleType] != NULL_PTR)
				{
					ret = (BufReq_ReturnType)PduRUp_TpCopyRxData[destModuleType]\
							(destPduId,info,bufferSizePtr);
				}
			}
			else
			{
				ret = PduR_CopyRxDataToOneTpHandle(srcPduId, destPduId, info, bufferSizePtr);
			}
		}
		else
		{
			ret = BUFREQ_E_NOT_OK;
		}
	}
	/* more than one dest pdu */
	else
	{
		ret = PduR_CopyRxDataToMultitudeBswHandle(srcPduId, destPduNum, info, bufferSizePtr);
	}
	return ret;
}

/**
 * @brief			Handle Tp RxIndication
 * @param[in]		srcPduId : Pdu Id
 * @param[in]		ret : result
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 * @req [SWS_PduR_00429] When a source transport protocol module calls PduR_<LoTp>RxIndication
 * 						 indicating reception of the complete I-PDU, the PDU Router module shall
 * 						 forward the indication to the destination upper layer module by calling
 * 						 <Up>_TpRxIndication
 */
STATIC FUNC(void, PDUR_CODE)
PduR_LoTpRxIndication(
	VAR(PduIdType, PDUR_VAR) srcPduId,
	VAR(Std_ReturnType, PDUR_VAR) ret
)
{
	uint8 destPduNum;

	PduIdType destPduId;
	uint8 destModuleType;
	destPduNum = PduR_ConfigData->PduRRoutingTableRef[srcPduId].DestPduNumber;
	/* rx tp pdu to only one dest pdu */
	/**
	 * @req [SWS_PduR_00673] The PDU Router module shall provide 1:1 routing for an IPDU received
	 * 						 from a source transport protocol module and routed to one destination
	 * 						 upper module
	 */
	if(1u == destPduNum)
	{
		destPduId = PduR_ConfigData->PduRRoutingTableRef[srcPduId].PduRDestPduIdRef[0].DestPduId;
		destModuleType = PduR_ConfigData->PduRRoutingTableRef[srcPduId].PduRDestPduIdRef[0].\
				DestModuleType;
		if((destModuleType != PDUR_CANTP) && (destModuleType != PDUR_LINTP) \
				&& (destModuleType != PDUR_J1939TP))
		{
			if(PduRUp_TpRxIndication[destModuleType] != NULL_PTR)
			{
				if((boolean)TRUE == PathIsEnabled[srcPduId])
				{
					/**
					 * @req [SWS_PduR_00207] If the source transport protocol module reports an error
					 * 						 using PduR_<LoTp>RxIndication, the PDU Router module shall
					 * 						 not perform any error handling other than forwarding the
					 * 						 indication to the upper layer module
					 */
					PduRUp_TpRxIndication[destModuleType](destPduId,ret);
				}
				else
				{
					/**
					 * @req [SWS_PduR_00207] If the source transport protocol module reports an error
					 * 						 using PduR_<LoTp>RxIndication, the PDU Router module
					 * 						 shall not perform any error handling other than forwarding
					 * 						 the indication to the upper layer module
					 */
					PduRUp_TpRxIndication[destModuleType](destPduId,(Std_ReturnType)E_NOT_OK);
				}
			}
		}
		else
		{
			if(((Std_ReturnType)E_OK == ret) && ((boolean)TRUE == PathIsEnabled[srcPduId]))
			{
				PduR_RxIndicationToTpHandle(srcPduId,destPduId);
			}
			else
			{
				/**
				 * @req [SWS_PduR_00689] If the result value is not E_OK in the PduR_<SrcLoTp>
				 * 						 RxIndication, the PDU Router shall immediately stop further
				 * 						 processing of the I-PDU.
				 */
				PduR_ClearGateWayTpBufferAndState(srcPduId);
			}
		}
	}
	/* rx tp pdu to more than one dest pdu */
	else
	{
		if((Std_ReturnType)E_OK == ret)
		{
			PduR_RxIndicationToMultitudeBswHandle(srcPduId, destPduNum);
		}
		else
		{
			/**
			 * @req [SWS_PduR_00689] If the result value is not E_OK in the PduR_<SrcLoTp>RxIndication,
			 * 						 the PDU Router shall immediately stop further processing of the
			 * 						 I-PDU.
			 */
			PduR_ClearGateWayTpBufferAndState(srcPduId);
		}
	}
	return;
}


/**
 * @req [SWS_PduR_00740] If the transport protocol module calls PduR_<LoTp>CopyTxData or PduR_<LoTp>
 * 						 CopyRxData with length zero (PduInfoType.SduLength = 0) the PDU Router module
 * 						 shall return the size of the current available buffer or the current available
 * 						 data respectively.
 */
/**
 * @brief			Handle Copy Tx Data
 * @param[in]		TxPduId : Pdu Id
 * @param[in]		info : Contains the length (SduLength) of the I-PDU and a pointer
 * 					to a buffer (SduDataPtr) containing the I-PDU.
 * @param[in]		retry : The pointer structure of the retry operation
 * @param[in]		availableDataPtr : The size of the upper available space that needs to be confirmed
 * @param[out]		/
 * @param[in/out]	/
 * @return			BufReq_ReturnType
 * @retval			BUFREQ_OK
    				BUFREQ_E_NOT_OK
    				BUFREQ_E_BUSY
          	  	  	BUFREQ_E_OVFL
 */
STATIC FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_LoTpCopyTxData(
	VAR(PduIdType,PDUR_VAR) TxPduId,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
)
{
	BufReq_ReturnType ret = BUFREQ_E_NOT_OK;
	PduIdType srcTxPduId;
	uint8 srcModuleType;
	PduIdType upTxPduId;
	uint8 destPduNum;
	uint8 actualPduId;
	srcTxPduId = PduR_ConfigData->PduRDestPduRef[TxPduId].PduRSrcPduRef;
	srcModuleType = PduR_ConfigData->PduRSrcPduRef[srcTxPduId].SrcModuleType;
	destPduNum = PduR_ConfigData->PduRRoutingTableRef[srcTxPduId].DestPduNumber;
	upTxPduId = PduR_ConfigData->PduRSrcPduRef[srcTxPduId].PduRSrcModulePduId;
	actualPduId = (uint8)PduR_ConfigData->PduRDestPduRef[TxPduId].ActualPduId;
	/* one dest pdu route */
	if(1u == destPduNum)
	{
		if((boolean)TRUE == PathIsEnabled[srcTxPduId])
		{
			if((srcModuleType != PDUR_CANTP) && (srcModuleType != PDUR_LINTP) \
					&& (srcModuleType != PDUR_J1939TP))
			{
				if(PduRUp_TpCopyTxData[srcModuleType] != NULL_PTR)
				{
					/**
					 * @req [SWS_PduR_00676] The return value from the <Up>_CopyTxData shall be
					 * 						 forwarded to the calling destination lower layer
					 * 						 transport protocol module.
					 */
					ret = (BufReq_ReturnType)PduRUp_TpCopyTxData[srcModuleType]\
							(upTxPduId,info,retry,availableDataPtr);
				}
			}
			else
			{
				ret = PduR_FromTpCopyTxDataHandle\
						(srcTxPduId,(PduIdType)actualPduId,info,retry,availableDataPtr);
			}
		}
		else
		{
			ret = BUFREQ_E_NOT_OK;
		}
	}
	/* more than one dest pdu route */
	else
	{
		if((srcModuleType == PDUR_COM) || (srcModuleType == PDUR_LDCOM) \
				|| (srcModuleType == PDUR_SECOC) || (srcModuleType == PDUR_DCM) \
				|| (srcModuleType == PDUR_J1939DCM))
		{
			ret = PduR_UpMulticastTpCopyData(srcModuleType,srcTxPduId,info,availableDataPtr);
		}
		else
		{
			ret = PduR_FromTpCopyTxDataToMultitudeBswHandle\
					(srcTxPduId,(PduIdType)actualPduId,info,retry,availableDataPtr);
		}
	}
	return ret;
}

/**
 * @req [SWS_PduR_00812] After all transport protocols have received their data the PDU Router module
 * 						 may confirm the data to the upper layer module
 */
/**
 * @brief			Handle Tp Confirmation
 * @param[in]		id : Pdu Id
 * @param[in]		ret : result
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
STATIC FUNC(void, PDUR_CODE)
PduR_LoTpTxConfirmation(
	VAR(PduIdType, PDUR_VAR) id,
	VAR(Std_ReturnType, PDUR_VAR) ret
)
{
	PduIdType srcPdu;
	uint8 destPduNum;
	uint8 srcModuleType;
	uint8 actualId, index;
	PduIdType tpRunTimeIndex = 0u;
	srcPdu = PduR_ConfigData->PduRDestPduRef[id].PduRSrcPduRef;
	srcModuleType = PduR_ConfigData->PduRSrcPduRef[srcPdu].SrcModuleType;
	destPduNum = PduR_ConfigData->PduRRoutingTableRef[srcPdu].DestPduNumber;
	switch(srcModuleType)
	{
		#if(STD_ON == PDUR_COM_SUPPORT)
		case PDUR_COM:
		#endif/* STD_ON == PDUR_COM_SUPPORT */
		#if(STD_ON == PDUR_LDCOM_SUPPORT)
		case PDUR_LDCOM:
		#endif/* STD_ON == PDUR_LDCOM_SUPPORT */
		#if(STD_ON == PDUR_SECOC_SUPPORT)
		case PDUR_SECOC:
		#endif/* STD_ON == PDUR_SECOC_SUPPORT */
		#if(STD_ON == PDUR_DCM_SUPPORT)
		case PDUR_DCM:
		#endif/* STD_ON == PDUR_DCM_SUPPORT */
		#if(STD_ON == PDUR_J1939DCM_SUPPORT)
		case PDUR_J1939DCM:
		#endif/* STD_ON == PDUR_J1939DCM_SUPPORT */
			PduR_UpTpTxConfirmationHandle(srcModuleType,srcPdu,destPduNum,ret);
			break;
		/* Tp layer:Gateway pdu */
		default:
			actualId = (uint8)PduR_ConfigData->PduRDestPduRef[id].ActualPduId;
			for(index = 0u; index < destPduNum; index++)
			{
				if(PduR_ConfigData->PduRRoutingTableRef[srcPdu].PduRDestPduIdRef[index].DestPduId == \
						actualId)
				{
					tpRunTimeIndex = PduR_ConfigData->PduRRoutingTableRef[srcPdu].PduRDestPduIdRef\
							[index].GateWayTpRunTimeIndex;
				}
			}
			PduR_GateWayDestTpSate[tpRunTimeIndex].TpTxConfirmation = (boolean)TRUE;
			/**
			 * @req [SWS_PduR_00637] When the PDU Router module receives the PduR_TxConfirmation,
			 * 						 the PDU Router shall free the I-PDU buffer for this destination
			 */
			if((boolean)FALSE == PduR_AtLeastOneDestIsNotTxConfirm(srcPdu))
			{
				PduR_ClearGateWayTpBufferAndState(srcPdu);
			}
			break;
	}
	return;
}
#endif/* STD_ON == PDUR_TP_SUPPORT */

/*====================================================================================================*
 *                                          GLOBAL FUNCTIONS
 *====================================================================================================*/
/**
 * @sid 			0xf0
 * @brief			Initializes the PDU Router
 * @param[in]		ConfigPtr: Pointer to Post build configuration data.
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 *
 * @req [SWS_PduR_00334]
 */
FUNC(void, PDUR_CODE)
PduR_Init(
	P2CONST(PduR_PBConfigType, AUTOMATIC, PDUR_APPL_DATA) ConfigPtr
)
{
	uint16 cnt;
	uint16 destNumber;
	uint16 index;
	PduIdType destPduId;
	uint16 loop;
	uint16 loop1;
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_UNINIT != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_INIT, PDUR_E_INVALID_REQUEST);
	}
	else if(NULL_PTR == ConfigPtr)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_INIT, PDUR_E_INIT_FAILED);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		/**
		 * @req [SWS_PduR_00709] After initialization all I-PDU routing groups shall be enabled
		 * 						 according enable at start configuration parameter
		 */
		PduR_ConfigData = ConfigPtr;
		/**
		 * @req [SWS_PduR_00330] The PDU Router module shall perform no routing when it is in the
		 * 						 uninitialized state
		 */
		for(cnt = (uint16)0u; cnt < (uint16)PDUR_SRC_PDU_SUM; cnt++)
		{
			PathIsEnabled[cnt] = (boolean)TRUE;
		}

#if((PDUR_SRC_UP_MULTICAST_TX_IF_SUM + PDUR_SRC_UP_MULTICAST_TX_TP_SUM) > 0)
		for(cnt = 0u;cnt < (uint16)(PDUR_SRC_UP_MULTICAST_TX_IF_SUM + PDUR_SRC_UP_MULTICAST_TX_TP_SUM);\
		cnt++)
		{
			PduR_UpTxConfirmation[cnt] = (boolean)FALSE;
		}
#endif/* (PDUR_SRC_UP_MULTICAST_TX_IF_SUM + PDUR_SRC_UP_MULTICAST_TX_TP_SUM) > 0 */

		/* PRQA S 2996 EOF # violate MISRA_2004_Rule_13.7:ignore this warnning */
		/* PRQA S 2994 EOF # violate MISRA_2004_Rule_13.7:ignore this warnning */
		for (cnt = 0u; cnt < (uint16)PDUR_ROUTING_PATH_GROUP_SUM; cnt++)
		{
			/* PRQA S 2880 EOF # violate MISRA_2004_Rule_14.1:ignore this warnning */
			if ((boolean)FALSE == PduR_ConfigData->PduRRoutingPathGroupRef[cnt].PduRIsEnabledAtInit)
			{
				destNumber = PduR_ConfigData->PduRRoutingPathGroupRef[cnt].PduRDestPduRefNumber;
				for(index = 0u;index < destNumber; index++)
				{
					destPduId = PduR_ConfigData->PduRRoutingPathGroupRef[cnt].PduRDestPduRef[index];
					for(loop = 0u;loop < (uint16)PDUR_SRC_PDU_SUM;loop++)
					{
						for(loop1 = 0u;loop1 < PduR_ConfigData->PduRRoutingTableRef[loop].DestPduNumber;\
							loop1++)
						{
							if(destPduId == PduR_ConfigData->PduRRoutingTableRef[loop].\
									PduRDestPduIdRef[loop1].DestPduId)
							{
								PathIsEnabled[loop] = (boolean)FALSE;
								break;
							}
						}
					}
				}
			}
		}

		/**
		 * @req [SWS_PduR_00645] The PDU Router module shall release all buffers in PduR_Init function
		 */
		#if (PDUR_GATEWAY_DIRECT_BUFFER_PDU_SUM > 0u)
		/* if source pdu gateway to other if dest pdus which configed PDUR_DIRECT */
		for(index = 0u;index < (uint16)PDUR_GATEWAY_DIRECT_BUFFER_PDU_SUM;index++)
		{
			PduR_DestPduState[index] = PDUR_IDLE;
		}
		#endif/* PDUR_GATEWAY_DIRECT_BUFFER_PDU_SUM > 0 */
		#if(PDUR_SRC_UP_MULTICAST_TX_TP_SUM > 0u)
		/* up module 1:n(n>1) tp transmit */
		for(index = 0u;index < (uint16)PDUR_SRC_UP_MULTICAST_TX_TP_SUM;index++)
		{
			PduR_UpTxTpMulRoute[index].ActiveDestNumber = 0u;
			PduR_UpTxTpMulRoute[index].DestCopyDataTimer = 0u;
		}
		#endif/* PDUR_SRC_UP_MULTICAST_TX_TP_SUM > 0u */
		#if(PDUR_DEST_GATEWAY_TP_PDU_SUM > 0u)
		/* gateway tp routing path,Run Time State of all dest pdu(include up pdu and tp pdu) */
		for(cnt = 0u;cnt < PDUR_DEST_GATEWAY_TP_PDU_SUM;cnt++)
		{
			PduR_GateWayDestTpSate[cnt].ActiveTpBufferId = 0xffu;
			PduR_GateWayDestTpSate[cnt].CopyCompleteTpBufferNumber = 0u;
			PduR_GateWayDestTpSate[cnt].IsGateWayOnTheFly = (boolean)FALSE;
			PduR_GateWayDestTpSate[cnt].TpTxConfirmation = (boolean)TRUE;
			PduR_GateWayDestTpSate[cnt].TxBufferOffset = 0u;
		}
		#endif/* PDUR_DEST_GATEWAY_TP_PDU_SUM > 0 */
		/**
		 * @req [SWS_PduR_00326] [SWS_PduR_00328]
		 * 						The PDU Router module shall change to the state PDUR_ONLINE when the
		 * 						PDU Router has successfully been initialized via the function PduR_Init
		 */
		PduR_Status = PDUR_ONLINE;
	}
	return;
}

/**
 * @req [SWS_PduR_00338]
 */
/**
 * @sid 			0x07
 * @brief			Returns the version of the AUTOSAR PduR module.
 * @param[in]		A pointer to get the version information
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void, PDUR_CODE)
PduR_GetVersionInfo(
	P2VAR(Std_VersionInfoType, AUTOMATIC,PDUR_APPL_DATA) versionInfo
)
{
#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(NULL_PTR == versionInfo)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_GETVERSIONINFO, PDUR_E_PARAM_POINTER);
	}
	else
#endif
	{
		versionInfo->moduleID = PDUR_MODULE_ID;
		versionInfo->sw_major_version = PDUR_SW_MAJOR_VERSION;
		versionInfo->sw_minor_version = PDUR_SW_MINOR_VERSION;
		versionInfo->sw_patch_version = PDUR_SW_PATCH_VERSION;
		versionInfo->vendorID = PDUR_VENDOR_ID;
	}
	return;
}

/**
 * @req [SWS_PduR_00341]
 */
/**
 * @sid 				0xf2
 * @brief				Returns the unique identifier of the post-build time configuration of the PDU
 * 						Router
 * @param[in]			/
 * @param[out]			/
 * @param[in/out]		/
 * @return				identifier
 * @retval				Identifier of the post-build time configuration
 */
FUNC(PduR_PBConfigIdType, PDUR_CODE)
PduR_GetConfigurationId(void)
{
	uint16 cfgId;
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	cfgId = 0xffffu;
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_GETCONFIGURATIONID, PDUR_E_INVALID_REQUEST);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		/**
		 * @req [SWS_PduR_00280] The function PduR_GetConfigurationId shall return the unique identifier
		 * 						 of the post-build time configuration of the PDU Router module.
		 */
		cfgId = 0u;
	}
	return cfgId;
}

/**
 * @req [SWS_PduR_00615]
 */
/**
 * @sid 			0xf3
 * @brief			Enables a routing path table
 * @param[in]		id: Identification of the routing path group.Routing path groups are defined in
 * 					the PDU router configuration
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void, PDUR_CODE)
PduR_EnableRouting(
	VAR(PduR_RoutingPathGroupIdType, PDUR_VAR) id
)
{
	uint16 destPduId;
	uint16 destPduNum;
	uint16 index;
	uint8 cnt;
	uint8 cnt1;
	uint16 srcDestPduNum;
	PduIdType actualId;
	PduIdType srcPduId;
	/*@req [SWS_PduR_00648] If the routing path group id does not exist and the PduRDevErrorDetect
	 * 						is enabled, the PDU Router module shall report
	 * 						PDUR_E_ROUTING_PATH_GROUP_ID_INVALID*/
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_ENABLEROUTING, PDUR_E_INVALID_REQUEST);
	}
	/**
	 * @req [SWS_PduR_00647][SWS_PduR_00648] If the routing path group id does not exist, then the
	 * 						PDU Router module shall return with no action.
	 */
	
	else if (((0u < (uint16)PDUR_ROUTING_PATH_GROUP_SUM) && (id >= (uint16)PDUR_ROUTING_PATH_GROUP_SUM)))
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_ENABLEROUTING, PDUR_E_ROUTING_PATH_GROUP_ID_INVALID);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		
		destPduNum = PduR_ConfigData->PduRRoutingPathGroupRef[id].PduRDestPduRefNumber;
		for (index = (uint16)0; index < destPduNum; index++)
		{
			/**
			 * @req [SWS_PduR_00715] Enabling of I-PDU routing path groups shall be immediate
			 */
			destPduId = PduR_ConfigData->PduRRoutingPathGroupRef[id].PduRDestPduRef[index];
			actualId = PduR_ConfigData->PduRDestPduRef[destPduId].ActualPduId;
			srcPduId = PduR_ConfigData->PduRDestPduRef[destPduId].PduRSrcPduRef;
			for(cnt = 0u; cnt < (uint8)PDUR_SRC_PDU_SUM; cnt++)
			{
				if(PduR_ConfigData->PduRRoutingTableRef[cnt].PduRSrcPduId == srcPduId)
				{
					srcDestPduNum = PduR_ConfigData->PduRRoutingTableRef[cnt].DestPduNumber;
					for(cnt1 = 0u; cnt1 < srcDestPduNum; cnt1++)
					{
						if(PduR_ConfigData->PduRRoutingTableRef[cnt].PduRDestPduIdRef[cnt1].DestPduId == \
								actualId)
						{
							PathIsEnabled[cnt] = (boolean)TRUE;
						}
					}
				}
			}
		}
	}
	return;
}

/**
 * @req [SWS_PduR_00617]
 */
/**
 * @sid 			0xf4
 * @brief			Disables a routing path table
 * @param[in]		id: Identification of the routing path group.Routing path groups are defined in
 * 					the PDU router configuration
 * @param[in]		initialize ((boolean)true,(boolean)false)
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void, PDUR_CODE)
PduR_DisableRouting(
	VAR(PduR_RoutingPathGroupIdType, PDUR_VAR) id,
	VAR(boolean, PDUR_VAR) initialize
)
{
	uint16 destPduNum;
	uint16 index;
	uint16 txBufferId;
	uint8 txBufferDepth;
	uint8 cnt;
	PduIdType destPduId;
	PduIdType srcPduId;
	/**
	 * @req [SWS_PduR_00649] If the routing path table id does not exist and the PduRDevErrorDetect
	 * 						 is enabled, the PDU Router module shall report
	 * 						 PDUR_E_ROUTING_PATH_GROUP_ID_INVALID
	 */
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_DISABLEROUTING, PDUR_E_INVALID_REQUEST);
	}
	/**
	 * @req [SWS_PduR_00716][SWS_PduR_00649] If the routing path group id does not exist, then the
	 * 						PDU Router module shall return with no action
	 */
	else if ((0u < (uint16)PDUR_ROUTING_PATH_GROUP_SUM) && (id >= (uint16)PDUR_ROUTING_PATH_GROUP_SUM))

	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_DISABLEROUTING, PDUR_E_ROUTING_PATH_GROUP_ID_INVALID);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		destPduNum = PduR_ConfigData->PduRRoutingPathGroupRef[id].PduRDestPduRefNumber;
		for (index =(uint16)0; index < destPduNum; index++)
		{
			destPduId = PduR_ConfigData->PduRRoutingPathGroupRef[id].PduRDestPduRef[index];
			/**
			 * @req [SWS_PduR_00810] When a routing path associated with a single buffer
			 * 						 (PduRTxBufferDepth == 1) is stopped, the according buffer shall be
			 * 						 set to the default value if PduR_DisableRouting is called with
			 * 						 initialize set to (boolean)true, otherwise the current value shall
			 * 						 be retained.
			 */
			srcPduId = PduR_ConfigData->PduRDestPduRef[destPduId].PduRSrcPduRef;
			if ((boolean)TRUE == PathIsEnabled[srcPduId])
			{
				destPduNum = PduR_ConfigData->PduRRoutingTableRef[srcPduId].DestPduNumber;
				for(cnt = 0u;cnt < destPduNum; cnt++)
				{
					txBufferId = PduR_ConfigData->PduRRoutingTableRef[srcPduId].PduRDestPduIdRef[cnt].\
							PduRDestTxBufferRef;
					/* Buffers need to be initialized when disabling routing path groups because
					 * TriggerTransmit may access these buffers all the time */
				
					if(((uint16)(boolean)TRUE == initialize) && ((uint16)0xffff != txBufferId) \
							&& (PDUR_TRIGGERTRANSMIT == PduR_ConfigData->PduRRoutingTableRef[srcPduId].\
									PduRDestPduIdRef[cnt].\
									PduRDestPduDataProvision))
					{
						/* By configuring the number of txbuffers you can choose */
						txBufferDepth = PduR_TxBuffer[txBufferId].PduRTxBufferDepth;
						if(1u == txBufferDepth)
											
						{
							if(NULL_PTR != PduR_ConfigData->PduRRoutingTableRef[srcPduId].\
									PduRDestPduIdRef[cnt].PduRDefaultValueRef)
							{
								/*Assign the data length that will be used by configuring*/
								PduR_TxBuffer[txBufferId].PduRTxBufferRef[0].SduLength = \
										(uint16)PduR_ConfigData->PduRRoutingTableRef[srcPduId].\
										PduRDestPduIdRef[cnt].PduRDefaultValueRef->DefaultValueLength;
								/**@req [SWS_PduR_00308] The function PduR_Init shall initialize all
								 * 						 configured default value to the PDU transmit
								 * 						 buffers
								 */
								PduR_Memcpy(
											PduR_TxBuffer[txBufferId].PduRTxBufferRef[0].TxBufferData,
											&PduR_Default_value[PduR_ConfigData->PduRRoutingTableRef\
																[srcPduId].PduRDestPduIdRef[cnt].\
																PduRDefaultValueRef->DefaultValueData],
											(uint16)PduR_ConfigData->PduRRoutingTableRef[srcPduId].\
										PduRDestPduIdRef[cnt].PduRDefaultValueRef->DefaultValueLength);
							}
						}
						else/*(PduRTxBufferDepth > 1)*/
						/**
						 * @req [SWS_PduR_00663] When a routing path associated with a FIFO
						 * 						 (PduRTxBufferDepth > 1) is stopped, the according FIFO
						 * 						 shall be flushed, and the PduR shall report
						 * 						 PDUR_E_PDU_INSTANCES_LOST to the DET if DET reporting
						 * 						 is enabled
						 */
						{
				
							if((boolean)TRUE == PduR_TxBuffer[txBufferId].PduRTxBufferRef[0].used)
							{
								#if(STD_ON == PDUR_DEV_ERROR_DETECT)
								PDUR_DET_ERROR_REPORT(PDUR_SID_DISABLEROUTING, \
										PDUR_E_PDU_INSTANCES_LOST);
								#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
							}
							PduR_TxBuffer[txBufferId].PduRTxBufferRef[0].used = (boolean)FALSE;
						}
					}
				}

			}
			/**
			 * @req [SWS_PduR_00646] The PDU Router shall immediately disable the routing path groups
			 */
			PathIsEnabled[srcPduId] = (boolean)FALSE;
		}
	}
	return;
}

#if(STD_ON == PDUR_COM_SUPPORT)
/**
 * @req [SWS_PduR_00629] The I-PDU shall not be buffered in the PDU Router module in case of PDU
 * 						transmission from a source upper layer module
 */
/**
 * @req [SWS_PduR_00406]
 */
/**
 * @sid 			0x89
 * @brief			Requests transmission of an I-PDU.
 * @param[in]		id: Identification of the I-PDU.
 * @param[in]		info: Length and pointer to the buffer of the I-PDU.
 * @param[out]		/
 * @param[in/out]	/
 * @return			Std_ReturnType
 * @retval			E_OK -request is accepted by the destination module; transmission is continued.
 * 					E_NOT_OK -request is not accepted by the destination module;transmission is aborted.
 */
FUNC(Std_ReturnType, PDUR_CODE)
PduR_ComTransmit(
	VAR(PduIdType, PDUR_VAR) id,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	/**
	 * @req [SWS_PduR_00119] If the PDU Router module has not been initialized (state PDUR_UNINIT),
	 * 						 all functions except PduR_Init and PduR_GetVersionInfo shall report
	 * 						 the error PDUR_E_INVALID_REQUEST via the DET when called, when
	 * 						 PduRDevErrorDetect is enabled.
	 */
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_COMTRANSMIT, PDUR_E_INVALID_REQUEST);
	}
	else if(NULL_PTR == info)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_COMTRANSMIT, PDUR_E_PARAM_POINTER);
	}
	/**
	 * @req [SWS_PduR_00221] If development error detection is enabled, a PDU identifier is not within
	 * 						 the specified range, and the PDU identifier is configured to be used by
	 * 						 the PDU Router module, the PDU Router module shall report the error
	 * 						 PDUR_E_PDU_ID_INVALID to the DET module, when PduRDevErrorDetect is
	 * 						 enabled.
	 */
	else if (id >= (uint16)PDUR_SRC_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_COMTRANSMIT, PDUR_E_PDU_ID_INVALID);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		ret = PduR_UpperModeTransmit(id,info);
	}
	return ret;
}

/**
 * @req [SWS_PduR_00769]
 */
/**
 * @sid 			0x8a
 * @brief			Requests cancellation of an ongoing transmission of an I-PDU in a lower layer
 * 					communication
 * 					interface or transport protocol module.
 * @param[in]		id: Identification of the I-PDU.
 * @param[out]		/
 * @param[in/out]	/
 * @return			Std_ReturnType
 * @retval			E_OK - Cancellation was executed successfully by the destination module.
 * 					E_NOT_OK - Cancellation was rejected by the destination module.
 */
#if(STD_ON == PDUR_COM_CANCEL_TRANSMIT)
FUNC(Std_ReturnType, PDUR_CODE)
PduR_ComCancelTransmit(
	VAR(PduIdType, PDUR_VAR) id
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_COMCANCELTRANSMIT, PDUR_E_INVALID_REQUEST);
	}
	else if(id >= (uint16)PDUR_SRC_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_COMCANCELTRANSMIT, PDUR_E_PDU_ID_INVALID);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		#if( STD_ON == PDUR_UPMODE_CANCEL_TRANSMIT)
		ret = PduR_UpperModeCancelTransmit(id);
		#endif/* STD_ON == PDUR_UPMODE_CANCEL_TRANSMIT */
	}
	return ret;
}
#endif/* STD_ON == PDUR_COM_CANCEL_TRANSMIT */

/**
 * @req [SWS_PduR_00482]
 */
/**
 * @sid 			0x8b
 * @brief			Request to change a specific transport protocol parameter (e.g. block size).
 * @param[in]		id: Identification of the I-PDU.
 * @param[in]		parameter: The parameter that shall change.
 * @param[in]		value: The new value of the parameter
 * @param[out]		/
 * @param[in/out]	/
 * @return			Std_ReturnType
 * @retval			E_OK - The parameter was changed successfully.
 * 					E_NOT_OK - The parameter change was rejected.
 */
#if(STD_ON == PDUR_COM_CHANGE_PARAMETER)
FUNC(Std_ReturnType, PDUR_CODE)
PduR_ComChangeParameter(
	VAR(PduIdType, PDUR_VAR) id,
	VAR(TPParameterType, PDUR_VAR) parameter,
	VAR(uint16, PDUR_VAR) value
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
    #if(STD_ON == PDUR_DEV_ERROR_DETECT)
    if(PDUR_ONLINE != PduR_Status)
    {
	    PDUR_DET_ERROR_REPORT(PDUR_SID_COMCHANGEPARAMETER, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= (uint16)PDUR_DEST_PDU_SUM)
    {
	    PDUR_DET_ERROR_REPORT(PDUR_SID_COMCHANGEPARAMETER, PDUR_E_PDU_ID_INVALID);
    }
    else
    #endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
    {
    	ret = PduR_UpperModeChangeParameter(id,parameter,value);
    }
	return ret;
}
#endif/* STD_ON == PDUR_COM_CHANGE_PARAMETER */

/**
 * @req [SWS_PduR_00726] If the routing path for the requested I-PDUs is disabled, then
 * 						 PduR_<Up>CancelReceive shall return (Std_ReturnType)E_NOT_OK directly without
 * 						 any further
 * 						 action
 */
/**
 * @req [SWS_PduR_00767]
 */
/**
 * @sid 			0x8c
 * @brief			Requests cancellation of an ongoing reception of an I-PDU in a lower layer transport
 * 					protocol module.
 * @param[in]		id: Identification of the I-PDU.
 * @param[out]		/
 * @param[in/out]	/
 * @return			Std_ReturnType
 * @retval			E_OK - Cancellation was executed successfully by the destination module
 * 					E_NOT_OK - Cancellation was rejected by the destination module.
 */
#if(STD_ON == PDUR_COM_CANCEL_RECEIVE)
FUNC(Std_ReturnType, PDUR_CODE)
PduR_ComCancelReceive(
	VAR(PduIdType, PDUR_VAR) id
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
    #if(STD_ON == PDUR_DEV_ERROR_DETECT)
    if(PDUR_ONLINE != PduR_Status)
    {
	    PDUR_DET_ERROR_REPORT(PDUR_SID_COMCANCELRECEIVE, PDUR_E_INVALID_REQUEST);
    }
    else if( id >= (uint16)PDUR_DEST_PDU_SUM)
    {
	    PDUR_DET_ERROR_REPORT(PDUR_SID_COMCANCELRECEIVE, PDUR_E_PDU_ID_INVALID);
    }
    else
    #endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
    {
    	ret = PduR_UpperModeCancelReceive(id);
    }
	return ret;
}
#endif/* STD_ON == PDUR_COM_CANCEL_RECEIVE */

#endif/* STD_ON == PDUR_COM_SUPPORT */
#if(STD_ON == PDUR_LDCOM_SUPPORT)
/**
 * @req [SWS_PduR_00710] If the routing path for the requested I-PDU is disabled, then
 * 						 PduR_<Up>CancelTransmit shall return (Std_ReturnType)E_NOT_OK directly without
 * 						 any further action
 */
/**
 * @req [SWS_PduR_00767]
 */
/**
 * @sid 			0x089
 * @brief			Requests transmission of an I-PDU.
 * @param[in]		id: Identification of the I-PDU.
 * @param[in]		info: Length and pointer to the buffer of the I-PDU.
 * @param[out]		/
 * @param[in/out]	/
 * @return			Std_ReturnType
 * @retval			E_OK - request is accepted by the destination module; transmission is continued
 * 					E_NOT_OK - request is not accepted by the destination module;transmission is aborted
 */
FUNC(Std_ReturnType, PDUR_CODE)
PduR_LdComTransmit(
	VAR(PduIdType, PDUR_VAR) id,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_LDCOMTRANSMIT, PDUR_E_INVALID_REQUEST);
	}
	else if (NULL_PTR == info)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_LDCOMTRANSMIT, PDUR_E_PARAM_POINTER);
	}
	else if (id >= PDUR_SRC_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_LDCOMTRANSMIT, PDUR_E_PDU_ID_INVALID);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		ret = PduR_UpperModeTransmit(id,info);
	}
	return ret;
}

/**
 * @req [SWS_PduR_00710] If the routing path for the requested I-PDU is disabled, then PduR_<Up>
 * 						 CancelTransmit shall return (Std_ReturnType)E_NOT_OK directly without any
 * 						 further action
 */
/**
 * @sid 			0x08a
 * @brief			Requests cancellation of an ongoing transmission of an I-PDU in a lower layer
 * 					communication interface or transport protocol module.
 * @param[in]		id: Identification of the I-PDU.
 * @param[out]		/
 * @param[in/out]	/
 * @return			Std_ReturnType
 * @retval			E_OK - Cancellation was executed successfully by the destination module.
 * 					E_NOT_OK - Cancellation was rejected by the destination module.
 */
#if(STD_ON == PDUR_LDCOM_CANCEL_TRANSMIT)
FUNC(Std_ReturnType, PDUR_CODE)
PduR_LdComCancelTransmit(
	VAR(PduIdType, PDUR_VAR) id
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_LDCOMCANCELTRANSMIT, PDUR_E_INVALID_REQUEST);
	}
	else if (id >= PDUR_SRC_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_LDCOMCANCELTRANSMIT, PDUR_E_PDU_ID_INVALID);
	}
	else
	#endif
	{
	#if( STD_ON == PDUR_UPMODE_CANCEL_TRANSMIT)
		ret = PduR_UpperModeCancelTransmit(id);
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	}
	return ret;
}
#endif/* STD_ON == PDUR_LDCOM_CANCEL_TRANSMIT */

/**
 * @sid 			0x08b
 * @brief			Request to change a specific transport protocol parameter (e.g. block size).
 * @param[in]		id: Identification of the I-PDU.
 * @param[in]		parameter: The parameter that shall change.
 * @param[in]		value: The new value of the parameter
 * @param[out]		/
 * @param[in/out]	/
 * @return			Std_ReturnType
 * @retval			E_OK - The parameter was changed successfully..
 * 					E_NOT_OK - The parameter change was rejected.
 */
#if(STD_ON == PDUR_LDCOM_CHANGE_PARAMETER)
FUNC(Std_ReturnType, PDUR_CODE)
PduR_LdComChangeParameter(
	VAR(PduIdType, PDUR_VAR) id,
	VAR(TPParameterType, PDUR_VAR) parameter,
	VAR(uint16, PDUR_VAR) value
)/* a received I-PDU */
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
    #if(STD_ON == PDUR_DEV_ERROR_DETECT)
    if(PDUR_ONLINE != PduR_Status)
    {
	    PDUR_DET_ERROR_REPORT(PDUR_SID_LDCOMCHANGEPARAMETER, PDUR_E_INVALID_REQUEST);
    }
    else if (id >= PDUR_DEST_PDU_SUM)
    {
	    PDUR_DET_ERROR_REPORT(PDUR_SID_LDCOMCHANGEPARAMETER, PDUR_E_PDU_ID_INVALID);
    }
    else
    #endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
    {
    	ret = PduR_UpperModeChangeParameter(id,parameter,value);
    }
	return ret;
}
#endif/* STD_ON == PDUR_LDCOM_CHANGE_PARAMETER */

/**
 * @req [SWS_PduR_00726] If the routing path for the requested I-PDUs is disabled, then PduR_<Up>
 * 						 CancelReceive shall return (Std_ReturnType)E_NOT_OK directly without any
 * 						 further action
 */
/**
 * @sid 			0x08c
 * @brief			Requests cancellation of an ongoing reception of an I-PDU in a lower layer transport
 * 					protocol module.
 * @param[in]		id: Identification of the I-PDU.
 * @param[out]		/
 * @param[in/out]	/
 * @return			Std_ReturnType
 * @retval			E_OK - Cancellation was executed successfully by the destination module
 * 					E_NOT_OK - Cancellation was rejected by the destination module.
 */
#if(STD_ON == PDUR_LDCOM_CANCEL_RECEIVE)
FUNC(Std_ReturnType, PDUR_CODE)
PduR_LdComCancelReceive(
	VAR(PduIdType, PDUR_VAR) id
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
    #if(STD_ON == PDUR_DEV_ERROR_DETECT)
    if(PDUR_ONLINE != PduR_Status)
    {
	    PDUR_DET_ERROR_REPORT(PDUR_SID_LDCOMCANCELRECEIVE, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_DEST_PDU_SUM)
    {
	    PDUR_DET_ERROR_REPORT(PDUR_SID_LDCOMCANCELRECEIVE, PDUR_E_PDU_ID_INVALID);
    }
    else
    #endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
    {
    	ret = PduR_UpperModeCancelReceive(id);
    }
	return ret;
}
#endif/* STD_ON == PDUR_LDCOM_CANCEL_RECEIVE */
#endif/* STD_ON == PDUR_LDCOM_SUPPORT */
#if(STD_ON == PDUR_DCM_SUPPORT)
/**
 * @req [SWS_PduR_00710] If the routing path for the requested I-PDU is disabled, then PduR_<Up>
 * 						 CancelTransmit shall return (Std_ReturnType)E_NOT_OK directly without any
 * 						 further action
 */
/**
 * @sid 			0x99
 * @brief			Requests transmission of an I-PDU.
 * @param[in]		id: Identification of the I-PDU.
 * @param[in]		info: Length and pointer to the buffer of the I-PDU.
 * @param[out]		/
 * @param[in/out]	/
 * @return			Std_ReturnType
 * @retval			E_OK - request is accepted by the destination module; transmission is continued.
 * 					E_NOT_OK - request is not accepted by the destination module;transmission is aborted
 */
FUNC(Std_ReturnType, PDUR_CODE)
PduR_DcmTransmit(
	VAR(PduIdType, PDUR_VAR) id,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_DCMTRANSMIT, PDUR_E_INVALID_REQUEST);
	}
	else if(NULL_PTR == info)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_DCMTRANSMIT, PDUR_E_PARAM_POINTER);
	}
	else if (id >= (PduIdType)PDUR_SRC_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_DCMTRANSMIT, PDUR_E_PDU_ID_INVALID);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		ret = PduR_UpperModeTransmit(id,info);
	}
	return ret;
}

/**
 * @req [SWS_PduR_00710] If the routing path for the requested I-PDU is disabled, then PduR_<Up>
 * 						 CancelTransmit shall return (Std_ReturnType)E_NOT_OK directly without any
 * 						 further action
 */
/**
 * @sid 			0x9a
 * @brief			Requests cancellation of an ongoing transmission of an I-PDU in a lower layer
 * 					communication interface or transport protocol module.
 * @param[in]		id: Identification of the I-PDU.
 * @param[out]		/
 * @param[in/out]	/
 * @return			Std_ReturnType
 * @retval			E_OK - Cancellation was executed successfully by the destination module.
 * 					E_NOT_OK - Cancellation was rejected by the destination module.
 */
#if(STD_ON == PDUR_DCM_CANCEL_TRANSMIT)
FUNC(Std_ReturnType, PDUR_CODE)
PduR_DcmCancelTransmit(
	VAR(PduIdType, PDUR_VAR) id
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_DCMCANCELTRANSMIT, PDUR_E_INVALID_REQUEST);
	}
	else if (id >= (PduIdType)PDUR_SRC_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_DCMCANCELTRANSMIT, PDUR_E_PDU_ID_INVALID);
	}
	else
	#endif
	{
	#if( STD_ON == PDUR_UPMODE_CANCEL_TRANSMIT)
		ret = PduR_UpperModeCancelTransmit(id);
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	}
	return ret;
}
#endif/* STD_ON == PDUR_DCM_CANCEL_TRANSMIT */

/**
 * @sid 			0x9b
 * @brief			Request to change a specific transport protocol parameter (e.g. block size).
 * @param[in]		id: Identification of the I-PDU.
 * @param[in]		parameter: The parameter that shall change.
 * @param[in]		value: The new value of the parameter
 * @param[out]		/
 * @param[in/out]	/
 * @return			Std_ReturnType
 * @retval			E_OK - The parameter was changed successfully.
 * 					E_NOT_OK - The parameter change was rejected.
 */
#if(STD_ON == PDUR_DCM_CHANGE_PARAMETER)
FUNC(Std_ReturnType, PDUR_CODE)
PduR_DcmChangeParameter(
	VAR(PduIdType, PDUR_VAR) id,
	VAR(TPParameterType, PDUR_VAR) parameter,
	VAR(uint16, PDUR_VAR) value
)/* a received I-PDU */
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
    #if(STD_ON == PDUR_DEV_ERROR_DETECT)
    if(PDUR_ONLINE != PduR_Status)
    {
	    PDUR_DET_ERROR_REPORT(PDUR_SID_DCMCHANGEPARAMETER, PDUR_E_INVALID_REQUEST);
    }
    else if (id >= (PduIdType)PDUR_DEST_PDU_SUM)
    {
	    PDUR_DET_ERROR_REPORT(PDUR_SID_DCMCHANGEPARAMETER, PDUR_E_PDU_ID_INVALID);
    }
    else
    #endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
    {
    	ret = PduR_UpperModeChangeParameter(id,parameter,value);
    }
	return ret;
}
#endif/* STD_ON == PDUR_DCM_CHANGE_PARAMETER */

/**
 * @req [SWS_PduR_00726] If the routing path for the requested I-PDUs is disabled, then PduR_<Up>
 * 						 CancelReceive shall return (Std_ReturnType)E_NOT_OK directly without any
 * 						 further action
 */
/**
 * @sid 			0x9c
 * @brief			Requests cancellation of an ongoing reception of an I-PDU in a lower layer transport
 * 					protocol module.
 * @param[in]		id: Identification of the I-PDU.
 * @param[out]		/
 * @param[in/out]	/
 * @return			Std_ReturnType
 * @retval			E_OK - Cancellation was executed successfully by the destination module
 * 					E_NOT_OK - Cancellation was rejected by the destination module.
 */
#if(STD_ON == PDUR_DCM_CANCEL_RECEIVE)
FUNC(Std_ReturnType, PDUR_CODE)
PduR_DcmCancelReceive(
	VAR(PduIdType, PDUR_VAR) id
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
    #if(STD_ON == PDUR_DEV_ERROR_DETECT)
    if(PDUR_ONLINE != PduR_Status)
    {
	    PDUR_DET_ERROR_REPORT(PDUR_SID_DCMCANCELRECEIVE, PDUR_E_INVALID_REQUEST);
    }
    else if (id >= (PduIdType)PDUR_DEST_PDU_SUM)
    {
	    PDUR_DET_ERROR_REPORT(PDUR_SID_DCMCANCELRECEIVE, PDUR_E_PDU_ID_INVALID);
    }
    else
    #endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
    {
    	ret = PduR_UpperModeCancelReceive(id);
    }
	return ret;
}
#endif/* STD_ON == PDUR_DCM_CANCEL_RECEIVE */
#endif/* STD_ON == PDUR_DCM_SUPPORT */
#if(STD_ON == PDUR_J1939DCM_SUPPORT)
/**
 * @req [SWS_PduR_00710] If the routing path for the requested I-PDU is disabled, then PduR_<Up>
 * 						 CancelTransmit shall return (Std_ReturnType)E_NOT_OK directly without any
 * 						 further action
 */
/**
 * @sid 			0xf9
 * @brief			Requests transmission of an I-PDU.
 * @param[in]		id: Identification of the I-PDU.
 * @param[in]		info: Length and pointer to the buffer of the I-PDU.
 * @param[out]		/
 * @param[in/out]	/
 * @return			Std_ReturnType
 * @retval			E_OK - request is accepted by the destination module; transmission is continued.
 * 					E_NOT_OK - request is not accepted by the destination module;transmission is aborted
 */
FUNC(Std_ReturnType, PDUR_CODE)
PduR_J1939DcmTransmit(
	VAR(PduIdType, PDUR_VAR) id,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_J1939DCMTRANSMIT, PDUR_E_INVALID_REQUEST);
	}
	else if(NULL_PTR == info)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_J1939DCMTRANSMIT, PDUR_E_PARAM_POINTER);
	}
	else if (id >= (PduIdType)PDUR_SRC_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_J1939DCMTRANSMIT, PDUR_E_PDU_ID_INVALID);

	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		ret = PduR_UpperModeTransmit(id,info);
	}
	return ret;
}

/**
 * @req [SWS_PduR_00710] If the routing path for the requested I-PDU is disabled, then PduR_<Up>
 * 						 CancelTransmit shall return (Std_ReturnType)E_NOT_OK directly without any
 * 						 further action
 */
/**
 * @sid 			0xfa
 * @brief			Requests cancellation of an ongoing transmission of an I-PDU in a lower layer
 * 					communication interface or transport protocol module.
 * @param[in]		id: Identification of the I-PDU.
 * @param[out]		/
 * @param[in/out]	/
 * @return			Std_ReturnType
 * @retval			E_OK - Cancellation was executed successfully by the destination module.
 * 					E_NOT_OK - Cancellation was rejected by the destination module.
 */
#if(STD_ON == PDUR_J1939DCM_CANCEL_TRANSMIT)
FUNC(Std_ReturnType, PDUR_CODE)
PduR_J1939DcmCancelTransmit(
	VAR(PduIdType, PDUR_VAR) id
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_J1939DCMCANCELTRANSMIT, PDUR_E_INVALID_REQUEST);
	}
	else if (id >= (PduIdType)PDUR_SRC_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_J1939DCMCANCELTRANSMIT, PDUR_E_PDU_ID_INVALID);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
	#if( STD_ON == PDUR_UPMODE_CANCEL_TRANSMIT)
		ret = PduR_UpperModeCancelTransmit(id);
	#endif/* STD_ON == PDUR_UPMODE_CANCEL_TRANSMIT */
	}
	return ret;
}
#endif/* STD_ON == PDUR_J1939DCM_CANCEL_TRANSMIT */

/**
 * @sid 			0xfb
 * @brief			Request to change a specific transport protocol parameter (e.g. block size).
 * @param[in]		id: Identification of the I-PDU.
 * @param[in]		parameter: The parameter that shall change.
 * @param[in]		value: The new value of the parameter
 * @param[out]		/
 * @param[in/out]	/
 * @return			Std_ReturnType
 * @retval			E_OK - The parameter was changed successfully.
 * 					E_NOT_OK - The parameter change was rejected.
 */
#if(STD_ON == PDUR_J1939DCM_CHANGE_PARAMETER)
FUNC(Std_ReturnType, PDUR_CODE)
PduR_J1939DcmChangeParameter(
	VAR(PduIdType, PDUR_VAR) id,
	VAR(TPParameterType, PDUR_VAR) parameter,
	VAR(uint16, PDUR_VAR) value
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
    #if(STD_ON == PDUR_DEV_ERROR_DETECT)
    if(PDUR_ONLINE != PduR_Status)
    {
	    PDUR_DET_ERROR_REPORT(PDUR_SID_J1939DCMCHANGEPARAMETER, PDUR_E_INVALID_REQUEST);
    }
    else if (id >= (PduIdType)PDUR_DEST_PDU_SUM)
    {
	    PDUR_DET_ERROR_REPORT(PDUR_SID_J1939DCMCHANGEPARAMETER, PDUR_E_PDU_ID_INVALID);
    }
    else
    #endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
    {
	#if( STD_ON == PDUR_UPMODE_CHANGE_PARAMETER)
		ret = PduR_UpperModeChangeParameter(id,parameter,value);
	#endif/* STD_ON == PDUR_UPMODE_CHANGE_PARAMETER */
    }
	return ret;
}
#endif/* STD_ON == PDUR_J1939DCM_CHANGE_PARAMETER */

/**
 * @req [SWS_PduR_00726] If the routing path for the requested I-PDUs is disabled, then PduR_<Up>
 * 						 CancelReceive shall return (Std_ReturnType)E_NOT_OK directly without any
 * 						 further action
 */
/**
 * @sid 			0xfc
 * @brief			Requests cancellation of an ongoing reception of an I-PDU in a lower layer transport
 * 					protocol module.
 * @param[in]		id: Identification of the I-PDU.
 * @param[out]		/
 * @param[in/out]	/
 * @return			Std_ReturnType
 * @retval			E_OK - Cancellation was executed successfully by the destination module
 * 					E_NOT_OK - Cancellation was rejected by the destination module.
 */
#if(STD_ON == PDUR_J1939DCM_CANCEL_RECEIVE)
FUNC(Std_ReturnType, PDUR_CODE)
PduR_J1939DcmCancelReceive(
	VAR(PduIdType, PDUR_VAR) id
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
    #if(STD_ON == PDUR_DEV_ERROR_DETECT)

    if(PDUR_ONLINE != PduR_Status)
    {
	    PDUR_DET_ERROR_REPORT(PDUR_SID_J1939DCMCANCELRECEIVE, PDUR_E_INVALID_REQUEST);
    }
    else if (id >= (PduIdType)PDUR_DEST_PDU_SUM)
    {
	    PDUR_DET_ERROR_REPORT(PDUR_SID_J1939DCMCANCELRECEIVE, PDUR_E_PDU_ID_INVALID);
    }
    else
    #endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
    {
    	ret = PduR_UpperModeCancelReceive(id);
    }
	return ret;
}
#endif/* STD_ON == PDUR_J1939DCM_CANCEL_RECEIVE */
#endif/* STD_ON == PDUR_J1939DCM_SUPPORT */
#if(STD_ON == PDUR_J1939RM_SUPPORT)
/**
 * @req [SWS_PduR_00710] If the routing path for the requested I-PDU is disabled, then PduR_<Up>
 * 						 CancelTransmit hall return (Std_ReturnType)E_NOT_OK directly without any
 * 						 further action
 */
/**
 * @sid 			0xe9
 * @brief			Requests transmission of an I-PDU.
 * @param[in]		id: Identification of the I-PDU.
 * @param[in]		info: Length and pointer to the buffer of the I-PDU.
 * @param[out]		/
 * @param[in/out]	/
 * @return			Std_ReturnType
 * @retval			E_OK - request is accepted by the destination module; transmission is continued.
 * 					E_NOT_OK - request is not accepted by the destination module;transmission is aborted
 */
FUNC(Std_ReturnType, PDUR_CODE)
PduR_J1939RmTransmit(
	VAR(PduIdType, PDUR_VAR) id,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_J1939RMTRANSMIT, PDUR_E_INVALID_REQUEST);
	}
	else if(NULL_PTR == info)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_J1939RMTRANSMIT, PDUR_E_PARAM_POINTER);
	}
	else if (id >= (PduIdType)PDUR_SRC_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_J1939RMTRANSMIT, PDUR_E_PDU_ID_INVALID);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		ret = PduR_UpperModeTransmit(id,info);
	}
	return ret;
}
/**
 * @req [SWS_PduR_00710] If the routing path for the requested I-PDU is disabled, then PduR_<Up>
 * 						 CancelTransmit shall return (Std_ReturnType)E_NOT_OK directly without any
 * 						 further action
 */
/**
 * @sid 			0xea
 * @brief			Requests cancellation of an ongoing transmission of an I-PDU in a lower layer
 * 					communication interface or transport protocol module.
 * @param[in]		id: Identification of the I-PDU.
 * @param[out]		/
 * @param[in/out]	/
 * @return			Std_ReturnType
 * @retval			E_OK - Cancellation was executed successfully by the destination module.
 * 					E_NOT_OK - Cancellation was rejected by the destination module.
 */
#if(STD_ON == PDUR_J1939RM_CANCEL_TRANSMIT)
FUNC(Std_ReturnType, PDUR_CODE)
PduR_J1939RmCancelTransmit(
	VAR(PduIdType, PDUR_VAR) id
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_J1939RMCANCELTRANSMIT, PDUR_E_INVALID_REQUEST);
	}
	else if (id >= (PduIdType)PDUR_SRC_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_J1939RMCANCELTRANSMIT, PDUR_E_PDU_ID_INVALID);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
	#if( STD_ON == PDUR_UPMODE_CANCEL_TRANSMIT)
		ret = PduR_UpperModeCancelTransmit(id);
	#endif/* STD_ON == PDUR_UPMODE_CANCEL_TRANSMIT */
	}
	return ret;
}
#endif/* STD_ON == PDUR_J1939RM_CANCEL_TRANSMIT */
#endif/* STD_ON == PDUR_J1939RM_SUPPORT */

#if(STD_ON == PDUR_CANIF_SUPPORT)
#if(STD_ON == PDUR_LOWER_SUPPORT)
/**
 * @req [SWS_PduR_00621] When the PduR_<Lo>RxIndication is called the PDU Router module shall call
 * 						 <Up>_RxIndication for each destination upper module
 */
/**
 * @req [SWS_PduR_00362]
 */
/**
 * @sid 			0x01
 * @brief			Indication of a received I-PDU from a lower layer communication interface module.
 * @param[in]		RxPduId: ID of the received I-PDU.
 * @param[in]		PduInfoPtr: Contains the length (SduLength) of the received I-PDU and a pointer
 * 					to a buffer (SduDataPtr) containing the I-PDU.
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void, PDUR_CODE)
PduR_CanIfRxIndication(
	VAR(PduIdType, PDUR_VAR) RxPduId,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
)
{
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_CANIFRXINDICATION, PDUR_E_INVALID_REQUEST);
	}
	else if((NULL_PTR == PduInfoPtr)||(NULL_PTR == PduInfoPtr->SduDataPtr))
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_CANIFRXINDICATION, PDUR_E_PARAM_POINTER);
	}
	else if(RxPduId >= (PduIdType)PDUR_SRC_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_CANIFRXINDICATION, PDUR_E_PDU_ID_INVALID);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		PduR_LowerModeRxIndication(RxPduId, PduInfoPtr);
	}
	return;
}
#endif/* STD_ON == PDUR_LOWER_SUPPORT */

/**
 * @req [SWS_PduR_00627] When the communication interface module calls PduR_<Lo>TxConfirmation
 * 						 the PDU Router shall call <Up>_TxConfirmation in the upper module
 */
/**
 * @req [SWS_PduR_00365]
 */
/**
 * @sid 			0x02
 * @brief			The lower layer communication interface module confirms the transmission of an
 * 					IPDU.
 * @param[in]		TxPduId: ID of the I-PDU that has been transmitted.
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
#if(STD_ON == PDUR_CANIF_TX_CONFIRMATION)
FUNC(void, PDUR_CODE)
PduR_CanIfTxConfirmation(
	VAR(PduIdType, PDUR_VAR) TxPduId
)
{
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_CANIFTXCONFIRMATION, PDUR_E_INVALID_REQUEST);
	}
	else if(TxPduId >= (PduIdType)PDUR_DEST_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_CANIFTXCONFIRMATION, PDUR_E_PDU_ID_INVALID);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		PduR_LowerModeTxConfirmation(TxPduId);
	}
	return;
}
#endif/* STD_ON == PDUR_CANIF_TX_CONFIRMATION */

/**
 * @req [SWS_PduR_00430] The PDU Router module shall forward a PduR_<Lo>TriggerTransmit request by
 * 						 the communication interface module to the upper module by calling <Up>_
 * 						 TriggerTransmit
 */
/**
 * @req [SWS_PduR_00369]
 */
/**
 * @sid 			0x03
 * @brief			Within this API, the upper layer module (called module) shall check whether the
 *              	available data fits into the buffer size reported by PduInfoPtr->SduLength.
 *              	If it fits, it shall copy its data into the buffer provided by PduInfoPtr->
 *              	SduDataPtr and update the length of the actual copied data in PduInfoPtr->SduLength
 *              	If not, it returns (Std_ReturnType)E_NOT_OK without changing PduInfoPtr.
 * @param[in]		TxPduId: ID of the I-PDU that has been transmitted.
 * @param[out]		/
 * @param[in/out]	PduInfoPtr: Contains a pointer to a buffer (SduDataPtr) to where the SDU
 *                  data shall be copied, and the available buffer size in SduLengh.
 *                  On return, the service will indicate the length of the copied SDU
 *                  data in SduLength.
 * @return			/
 * @retval			/
 */
#if(STD_ON == PDUR_CANIF_TRIGGER_TRANSMIT)
FUNC(Std_ReturnType, PDUR_CODE)
PduR_CanIfTriggerTransmit(
	VAR(PduIdType, PDUR_VAR) TxPduId,
	P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_CANIFTRIGGERTRANSMIT, PDUR_E_INVALID_REQUEST);
	}
	else if(TxPduId >= (PduIdType)PDUR_DEST_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_CANIFTRIGGERTRANSMIT, PDUR_E_PDU_ID_INVALID);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		ret = PduR_LowerModeTriggerTransmit(TxPduId, PduInfoPtr);
	}
	return ret;
}
#endif/* STD_ON == PDUR_CANIF_TRIGGER_TRANSMIT */
#endif/* STD_ON == PDUR_CANIF_SUPPORT */

#if(STD_ON == PDUR_SOAD_SUPPORT)
#if(STD_ON == PDUR_SOADIF_SUPPORT)
#if(STD_ON == PDUR_LOWER_SUPPORT)
/**
 * @sid 			0x61
 * @brief			Indication of a received I-PDU from a lower layer communication interface module.
 * @param[in]		RxPduId: ID of the received I-PDU.
 * @param[in]		PduInfoPtr: Contains the length (SduLength) of the received I-PDU and a pointer
 * 					to a buffer (SduDataPtr) containing the I-PDU.
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void, PDUR_CODE)
PduR_SoAdRxIndication(
	VAR(PduIdType, PDUR_VAR) RxPduId,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
)
{
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_SOADRXINDICATION, PDUR_E_INVALID_REQUEST);
	}
	else if((NULL_PTR == PduInfoPtr)||(NULL_PTR == PduInfoPtr->SduDataPtr))
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_SOADRXINDICATION, PDUR_E_PARAM_POINTER);
	}
	else if(RxPduId >= (PduIdType)PDUR_SRC_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_SOADRXINDICATION, PDUR_E_PDU_ID_INVALID);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		PduR_LowerModeRxIndication(RxPduId, PduInfoPtr);
	}
	return;
}
#endif/* STD_ON == PDUR_LOWER_SUPPORT */

/**
 * @req [SWS_PduR_00365]
 */
/**
 * @sid 			0x62
 * @brief			The lower layer communication interface module confirms the transmission of an
 * 					IPDU.
 * @param[in]		TxPduId: ID of the I-PDU that has been transmitted.
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
#if(STD_ON == PDUR_SOAD_TX_CONFIRMATION)
FUNC(void, PDUR_CODE)
PduR_SoAdTxConfirmation(
	VAR(PduIdType, PDUR_VAR) TxPduId
)
{
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_SOADTXCONFIRMATION, PDUR_E_INVALID_REQUEST);
	}
	else if(TxPduId >= (PduIdType)PDUR_DEST_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_SOADTXCONFIRMATION, PDUR_E_PDU_ID_INVALID);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		PduR_LowerModeTxConfirmation(TxPduId);
	}
	return;
}
#endif/* STD_ON == PDUR_SOAD_TX_CONFIRMATION */

/**
 * @sid 			0x63
 * @brief			Within this API, the upper layer module (called module) shall check whether the
 *              	available data fits into the buffer size reported by PduInfoPtr->SduLength.
 *              	If it fits, it shall copy its data into the buffer provided by PduInfoPtr->
 *              	SduDataPtr and update the length of the actual copied data in PduInfoPtr->SduLength
 *              	If not, it returns (Std_ReturnType)E_NOT_OK without changing PduInfoPtr.
 * @param[in]		TxPduId: ID of the I-PDU that has been transmitted.
 * @param[out]		/
 * @param[in/out]	PduInfoPtr: Contains a pointer to a buffer (SduDataPtr) to where the SDU
 *                  data shall be copied, and the available buffer size in SduLengh.
 *                  On return, the service will indicate the length of the copied SDU
 *                  data in SduLength.
 * @return			/
 * @retval			/
 */
#if(STD_ON == PDUR_SOAD_TRIGGER_TRANSMIT)
FUNC(Std_ReturnType, PDUR_CODE)
PduR_SoAdTriggerTransmit(
	VAR(PduIdType, PDUR_VAR) TxPduId,
	P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_SOADTRIGGERTRANSMIT, PDUR_E_INVALID_REQUEST);
	}
	else if(TxPduId >= (PduIdType)PDUR_DEST_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_SOADTRIGGERTRANSMIT, PDUR_E_PDU_ID_INVALID);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		ret = PduR_LowerModeTriggerTransmit(TxPduId, PduInfoPtr);
	}
	return ret;
}
#endif/* STD_ON == PDUR_SOAD_TRIGGER_TRANSMIT */
#endif/* STD_ON == PDUR_SOADIF_SUPPORT */
#endif

#if(STD_ON == PDUR_LINIF_SUPPORT)
/**
 * @req [SWS_PduR_00621] When the PduR_<Lo>RxIndication is called the PDU Router module shall call
 * 						 <Up>_RxIndication for each destination upper module
 */
/**
 * @sid 		0x51
 * @brief		Indication of a received I-PDU from a lower layer communication interface module.
 * @param[in]	RxPduId: ID of the received I-PDU.
 * @param[in]	PduInfoPtr: Contains the length (SduLength) of the received I-PDU and a pointer to
 * 				a buffer (SduDataPtr) containing the I-PDU.
 * @return		/
 * @retval		/
 */
FUNC(void, PDUR_CODE)
PduR_LinIfRxIndication(
	VAR(PduIdType, PDUR_VAR) RxPduId,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
)
{
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
	   PDUR_DET_ERROR_REPORT(PDUR_SID_LINIFRXINDICATION, PDUR_E_INVALID_REQUEST);
	}
	else if((NULL_PTR == PduInfoPtr)||(NULL_PTR == PduInfoPtr->SduDataPtr))
	{
	   PDUR_DET_ERROR_REPORT(PDUR_SID_LINIFRXINDICATION, PDUR_E_PARAM_POINTER);
	}
	else if(RxPduId >= (PduIdType)PDUR_SRC_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_LINIFRXINDICATION, PDUR_E_PDU_ID_INVALID);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		PduR_LowerModeRxIndication(RxPduId,PduInfoPtr);
	}
	return;
}

/**
 * @req [SWS_PduR_00627] When the communication interface module calls PduR_<Lo>TxConfirmation the
 * 						 PDU Router shall call <Up>_TxConfirmation in the upper module
 */
/**
 * @req [SWS_PduR_00621] When the PduR_<Lo>RxIndication is called the PDU Router module shall call
 * 						 <Up>_RxIndication for each destination upper module
 */
/**
 * @sid 			0x52
 * @brief			Indication of a received I-PDU from a lower layer communication interface module.
 * @param[in]		RxPduId: ID of the received I-PDU.
 * @param[in]		PduInfoPtr: Contains the length (SduLength) of the received I-PDU and a pointer
 * 					to a buffer (SduDataPtr) containing the I-PDU.
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
#if(STD_ON == PDUR_LINIF_TX_CONFIRMATION)
FUNC(void, PDUR_CODE)
PduR_LinIfTxConfirmation(
	VAR(PduIdType, PDUR_VAR) TxPduId
)
{
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_LINIFTXCONFIRMATION, PDUR_E_INVALID_REQUEST);
	}
	else if(TxPduId >= (PduIdType)PDUR_DEST_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_LINIFTXCONFIRMATION, PDUR_E_PDU_ID_INVALID);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		PduR_LowerModeTxConfirmation(TxPduId);
	}
	return;
}

#endif/* STD_ON == PDUR_LINIF_TX_CONFIRMATION */

/**
 * @req [SWS_PduR_00430] The PDU Router module shall forward a PduR_<Lo>TriggerTransmit request by
 * 						 the communication interface module to the upper module by calling <Up>_
 * 						 TriggerTransmit
 */
/**
 * @sid 			0x53
 * @brief			Within this API, the upper layer module (called module) shall check whether the
 *                  available data fits into the buffer size reported by PduInfoPtr->SduLength.
 *                  If it fits,it shall copy its data into the buffer provided by PduInfoPtr->SduDataPtr
 *                  and update the length of the actual copied data in PduInfoPtr->SduLength.
 *                  If not, it returns (Std_ReturnType)E_NOT_OK without changing PduInfoPtr.
 * @param[in]		TxPduId: ID of the SDU that is requested to be transmitted.
 * @param[out]		/
 * @param[in/out]	PduInfoPtr: Contains a pointer to a buffer (SduDataPtr) to where the SDU
 *                  data shall be copied, and the available buffer size in SduLengh.
 *                  On return, the service will indicate the length of the copied SDU
 *                  data in SduLength.
 * @return			/
 * @retval			/
 */
#if(STD_ON == PDUR_LINIF_TRIGGER_TRANSMIT)
FUNC(Std_ReturnType, PDUR_CODE)
PduR_LinIfTriggerTransmit(
	VAR(PduIdType, PDUR_VAR) TxPduId,
	P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_LINIFTRIGGERTRANSMIT, PDUR_E_INVALID_REQUEST);
	}
	else if(TxPduId >= (PduIdType)PDUR_DEST_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_LINIFTRIGGERTRANSMIT, PDUR_E_PDU_ID_INVALID);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		ret = PduR_LowerModeTriggerTransmit(TxPduId,PduInfoPtr);
	}
	return ret;
}
#endif/* STD_ON == PDUR_LINIF_TRIGGER_TRANSMIT */
#endif/* STD_ON == PDUR_LINIF_SUPPORT */

#if((STD_ON == PDUR_CANNM_SUPPORT) && (STD_ON == PDUR_COM_SUPPORT))

/**
 * @req [SWS_PduR_00621] When the PduR_<Lo>RxIndication is called the PDU Router module shall call
 * 						<Up>_RxIndication for each destination upper module
 */
/**
 * @sid 			0x11
 * @brief			Indication of a received I-PDU from a lower layer communication interface module.
 * @param[in]		RxPduId: ID of the received I-PDU.
 * @param[in]		PduInfoPtr: Contains the length (SduLength) of the received I-PDU and a pointer
 * 					to a buffer (SduDataPtr) containing the I-PDU.
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void, PDUR_CODE)
PduR_CanNmRxIndication(
	VAR(PduIdType, PDUR_VAR) RxPduId,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
)
{
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_CANNMRXINDICATION, PDUR_E_INVALID_REQUEST);
	}
	else if((NULL_PTR == PduInfoPtr)||(NULL_PTR == PduInfoPtr->SduDataPtr))
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_CANNMRXINDICATION, PDUR_E_PARAM_POINTER);
	}
	else if(RxPduId >= (PduIdType)PDUR_SRC_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_CANNMRXINDICATION, PDUR_E_PDU_ID_INVALID);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		PduR_LowerModeRxIndication(RxPduId,PduInfoPtr);
	}
	return;
}
/**
 * @req [SWS_PduR_00627] When the communication interface module calls PduR_<Lo>TxConfirmation
 * 						 the PDU Router shall call <Up>_TxConfirmation in the upper module
 */
/**
 * @sid 			0x12
 * @brief			The lower layer communication interface module confirms the transmission of an IPDU.
 * @param[in]		TxPduId: ID of the I-PDU that has been transmitted.
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
#if(STD_ON == PDUR_CANNM_TX_CONFIRMATION)
FUNC(void, PDUR_CODE)
PduR_CanNmTxConfirmation(
	VAR(PduIdType, PDUR_VAR) TxPduId
)
{
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_CANNMTXCONFIRMATION, PDUR_E_INVALID_REQUEST);
	}
	else if(TxPduId >= (PduIdType)PDUR_DEST_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_CANNMTXCONFIRMATION, PDUR_E_PDU_ID_INVALID);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		PduR_LowerModeTxConfirmation(TxPduId);
	}
	return;
}
#endif/* STD_ON == PDUR_CANNM_TX_CONFIRMATION */

/**
 * @req [SWS_PduR_00430] The PDU Router module shall forward a PduR_<Lo>TriggerTransmit
 * 						 request by the communication interface module to the upper module by
 * 						 calling <Up>_TriggerTransmit
 */
/**
 * @sid 			0x13
 * @brief			Within this API, the upper layer module (called module) shall check whether the
 *                  available data fits into the buffer size reported by PduInfoPtr->SduLength.
 *                  If fits, it shall copy its data into the buffer provided by PduInfoPtr->SduDataPtr
 *                  and update the length of the actual copied data in PduInfoPtr->SduLength.
 *                  If not, it returns (Std_ReturnType)E_NOT_OK without changing PduInfoPtr.
 * @param[in]		TxPduId: ID of the SDU that is requested to be transmitted.
 * @param[out]		PduInfoPtr: Contains a pointer to a buffer (SduDataPtr) to where the SDU
 *                  data shall be copied, and the available buffer size in SduLengh.
 *                  On return, the service will indicate the length of the copied SDU
 *                  data in SduLength.
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
#if(STD_ON == PDUR_CANNM_TRIGGER_TRANSMIT)
FUNC(Std_ReturnType, PDUR_CODE)
PduR_CanNmTriggerTransmit(
	VAR(PduIdType, PDUR_VAR) TxPduId,
	P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_CANNMTRIGGERTRANSMIT, PDUR_E_INVALID_REQUEST);
	}
	else if(TxPduId >= (PduIdType)PDUR_DEST_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_CANNMTRIGGERTRANSMIT, PDUR_E_PDU_ID_INVALID);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		ret = PduR_LowerModeTriggerTransmit(TxPduId,PduInfoPtr);
	}
	return ret;
}
#endif/* STD_ON == PDUR_CANNM_TRIGGER_TRANSMIT */
#endif/* (STD_ON == PDUR_CANNM_SUPPORT) && (STD_ON == PDUR_COM_SUPPORT) */

#if(STD_ON == PDUR_SECOC_SUPPORT)
/**
 * @req [SWS_PduR_00710] If the routing path for the requested I-PDU is disabled, then PduR_<Up>
 * 						 CancelTransmit shall return (Std_ReturnType)E_NOT_OK directly without any
 * 						 further action
 */
/**
 * @sid 			0xC9
 * @brief			Requests transmission of an I-PDU.
 * @param[in]		id: Identification of the I-PDU.
 * @param[in]		info: Length and pointer to the buffer of the I-PDU.
 * @param[out]
 * @param[in/out]
 * @return			Std_ReturnType
 * @retval			E_OK - request is accepted by the destination module; transmission is continued.
 * 					E_NOT_OK -request is not accepted by the destination module;transmission is aborted
 */
FUNC(Std_ReturnType, PDUR_CODE)
PduR_SecOCTransmit(
	VAR(PduIdType, PDUR_VAR) id,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_SECOCTRANSMIT, PDUR_E_INVALID_REQUEST);
	}
	else if(NULL_PTR == info)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_SECOCTRANSMIT, PDUR_E_PARAM_POINTER);
	}
	else if(id >= (PduIdType)PDUR_SRC_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_SECOCTRANSMIT, PDUR_E_PDU_ID_INVALID);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		ret = PduR_UpperModeTransmit(id,info);
	}
	return ret;
}

/**
 * @req [SWS_PduR_00710] If the routing path for the requested I-PDU is disabled, then PduR_<Up>
 * 						 CancelTransmit shall return (Std_ReturnType)E_NOT_OK directly without any
 * 						 further action
 */
/**
 * @sid 			0xCa
 * @brief			Requests cancellation of an ongoing transmission of an I-PDU in a lower layer
 * 					communication interface or transport protocol module.
 * @param[in]		id: Identification of the I-PDU.
 * @param[out]
 * @param[in/out]
 * @return			Std_ReturnType
 * @retval			E_OK - Cancellation was executed successfully by the destination module.
 * 					E_NOT_OK - Cancellation was rejected by the destination module.
 */
#if(STD_ON == PDUR_SECOC_CANCEL_TRANSMIT)
FUNC(Std_ReturnType, PDUR_CODE)
PduR_SecOCCancelTransmit(
	VAR(PduIdType, PDUR_VAR) id
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_SECOCCANCELTRANSMIT, PDUR_E_INVALID_REQUEST);
	}
	else if(id >= (PduIdType)PDUR_SRC_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_SECOCCANCELTRANSMIT, PDUR_E_PDU_ID_INVALID);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		ret = PduR_UpperModeCancelTransmit(id);
	}
	return ret;
}
#endif/* STD_ON == PDUR_SECOC_CANCEL_TRANSMIT */

/**
 * @req [SWS_PduR_00621] When the PduR_<Lo>RxIndication is called the PDU Router module shall call
 * 						 <Up>_RxIndication for each destination upper module
 */
/**
 * @sid 			0x71
 * @brief			Indication of a received I-PDU from a lower layer communication interface module.
 * @param[in]		RxPduId: ID of the received I-PDU.
 * @param[in]		PduInfoPtr: Contains the length (SduLength) of the received I-PDU and a pointer
 * 					to a buffer (SduDataPtr) containing the I-PDU.
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void, PDUR_CODE)
PduR_SecOCRxIndication(
	VAR(PduIdType, PDUR_VAR) RxPduId,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
)
{
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_SECOCRXINDICATION, PDUR_E_INVALID_REQUEST);
	}
	else if((NULL_PTR == PduInfoPtr)||(NULL_PTR == PduInfoPtr->SduDataPtr))
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_SECOCRXINDICATION, PDUR_E_PARAM_POINTER);
	}
	else if(RxPduId >= (PduIdType)PDUR_SRC_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_SECOCRXINDICATION, PDUR_E_PDU_ID_INVALID);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		PduR_LowerModeRxIndication(RxPduId,PduInfoPtr);
	}
	return;
}
/**
 * @req [SWS_PduR_00627] When the communication interface module calls PduR_<Lo>TxConfirmation the
 * 						 PDU Router shall call <Up>_TxConfirmation in the upper module
 */
/**
 * @sid 			0x72
 * @brief			The lower layer communication interface module confirms the transmission of an IPDU.
 * @param[in]		TxPduId: ID of the I-PDU that has been transmitted.
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
#if(STD_ON == PDUR_SECOC_TX_CONFIRMATION)
FUNC(void, PDUR_CODE)
PduR_SecOCTxConfirmation(
	VAR(PduIdType, PDUR_VAR) TxPduId
)
{
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_SECOCTXCONFIRMATION, PDUR_E_INVALID_REQUEST);
	}
	else if(TxPduId >= (PduIdType)PDUR_DEST_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_SECOCTXCONFIRMATION, PDUR_E_PDU_ID_INVALID);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		PduR_LowerModeTxConfirmation(TxPduId);
	}
	return;
}
#endif/* STD_ON == PDUR_SECOC_TX_CONFIRMATION */
#endif/* STD_ON == PDUR_SECOC_SUPPORT */

#if(STD_ON == PDUR_IPDUM_SUPPORT)
/**
 * @req [SWS_PduR_00710] If the routing path for the requested I-PDU is disabled, then PduR_<Up>
 * 						 CancelTransmit shall return (Std_ReturnType)E_NOT_OK directly without any
 * 						 further action
 */
/**
 * @sid 			0xa9
 * @brief			Requests transmission of an I-PDU.
 * @param[in]		id: Identification of the I-PDU.
 * @param[in]		info: Length and pointer to the buffer of the I-PDU.
 * @param[out]
 * @param[in/out]
 * @return			Std_ReturnType
 * @retval			E_OK - request is accepted by the destination module; transmission is continued.
 * 					E_NOT_OK - request is not accepted by the destination module;transmission is aborted
 */
FUNC(Std_ReturnType, PDUR_CODE)
PduR_IpduMTransmit(
	VAR(PduIdType, PDUR_VAR) id,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_IPDUMTRANSMIT, PDUR_E_INVALID_REQUEST);
	}
	else if (NULL_PTR == info)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_IPDUMTRANSMIT, PDUR_E_PARAM_POINTER);
	}
	else if (id >= (PduIdType)PDUR_SRC_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_IPDUMTRANSMIT, PDUR_E_PDU_ID_INVALID);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		ret = PduR_UpperModeTransmit(id,info);
	}
	return ret;
}

/**
 * @req [SWS_PduR_00430] The PDU Router module shall forward a PduR_<Lo>TriggerTransmit request by
 * 						 the communication interface module to the upper module by calling <Up>_
 * 						 TriggerTransmit
 */
/**
 * @req [SWS_PduR_00710] If the routing path for the requested I-PDU is disabled, then PduR_<Up>
 * 						 CancelTransmit shall return (Std_ReturnType)E_NOT_OK directly without any
 * 						 further action
 */
/**
 * @sid 			0x23
 * @brief			Within this API, the upper layer module (called module) shall check whether the
 *                  available data fits into the buffer size reported by PduInfoPtr->SduLength.
 *                  If fits, it shall copy its data into the buffer provided by PduInfoPtr->SduDataPtr
 *                  and update the length of the actual copied data in PduInfoPtr->SduLength.
 *                  If not, it returns (Std_ReturnType)E_NOT_OK without changing PduInfoPtr.
 * @param[in]		TxPduId: ID of the SDU that is requested to be transmitted.
 * @param[in]		info: Length and pointer to the buffer of the I-PDU.
 * @param[out]		/
 * @param[in/out]	PduInfoPtr: Contains a pointer to a buffer (SduDataPtr) to where the SDU
 *                  data shall be copied, and the available buffer size in SduLengh.
 *                  On return, the service will indicate the length of the copied SDU
 *                  data in SduLength.
 * @return			/
 * @retval			/
 */
#if((STD_ON == PDUR_IPDUM_TRIGGER_TRANSMIT) && (STD_ON == PDUR_COM_SUPPORT))
FUNC(Std_ReturnType, PDUR_CODE)
PduR_IpduMTriggerTransmit(
	VAR(PduIdType, PDUR_VAR) TxPduId,
	P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_IPDUMTRIGGERTRANSMIT, PDUR_E_INVALID_REQUEST);
	}
	else if (TxPduId >= (PduIdType)PDUR_DEST_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_IPDUMTRIGGERTRANSMIT, PDUR_E_PDU_ID_INVALID);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		ret = PduR_LowerModeTriggerTransmit(TxPduId, PduInfoPtr);
	}
	return ret;
}
#endif/* (STD_ON == PDUR_IPDUM_TRIGGER_TRANSMIT) && (STD_ON == PDUR_COM_SUPPORT) */

/**
 * @req [SWS_PduR_00621] When the PduR_<Lo>RxIndication is called the PDU Router module shall call
 * 						 <Up>_RxIndication for each destination upper module
 */
/**
 * @sid 			0x21
 * @brief			Indication of a received I-PDU from a lower layer communication interface module.
 * @param[in]		RxPduId: ID of the received I-PDU.
 * @param[in]		PduInfoPtr: Contains the length (SduLength) of the received I-PDU and a pointer
 * 					to a buffer (SduDataPtr) containing the I-PDU.
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
#if(STD_ON == PDUR_COM_SUPPORT)
FUNC(void, PDUR_CODE)
PduR_IpduMRxIndication(
	VAR(PduIdType, PDUR_VAR) RxPduId,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
)
{
    #if(STD_ON == PDUR_DEV_ERROR_DETECT)
    if(PDUR_ONLINE != PduR_Status)
    {
        PDUR_DET_ERROR_REPORT(PDUR_SID_IPDUMRXINDICATION, PDUR_E_INVALID_REQUEST);
    }
    else if ((NULL_PTR == PduInfoPtr)||(NULL_PTR == PduInfoPtr->SduDataPtr))
    {
        PDUR_DET_ERROR_REPORT(PDUR_SID_IPDUMRXINDICATION, PDUR_E_PARAM_POINTER);
    }
    else if (RxPduId >= (PduIdType)PDUR_SRC_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_IPDUMRXINDICATION, PDUR_E_PDU_ID_INVALID);
	}
	else
    #endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		PduR_LowerModeRxIndication(RxPduId, PduInfoPtr);
	}
	return;
}
#endif/* STD_ON == PDUR_COM_SUPPORT */

/**
 * @sid 			0x22
 * @brief			The lower layer communication interface module confirms the transmission of an IPDU.
 * @param[in]		TxPduId: ID of the I-PDU that has been transmitted.
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 * @req [SWS_PduR_00627] When the communication interface module calls PduR_<Lo>TxConfirmation the
 * 						 PDU Router shall call <Up>_TxConfirmation in the upper module
 */
#if((STD_ON == PDUR_IPDUM_TX_CONFIRMATION) && (STD_ON == PDUR_COM_SUPPORT))
FUNC(void, PDUR_CODE)
PduR_IpduMTxConfirmation(
	VAR(PduIdType, PDUR_VAR) TxPduId
)
{
	PduIdType srcUpPduId;
	PduIdType srcPduId;
	uint8 srcPduModuleIndex;
	uint8 srcPduMod;
    #if(STD_ON == PDUR_DEV_ERROR_DETECT)
    if(PDUR_ONLINE != PduR_Status)
    {
        PDUR_DET_ERROR_REPORT(PDUR_SID_IPDUMTXCONFIRMATION, PDUR_E_INVALID_REQUEST);
    }
    else if (TxPduId >= (PduIdType)PDUR_DEST_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_IPDUMTXCONFIRMATION, PDUR_E_PDU_ID_INVALID);
	}
	else
    #endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{

		srcPduId = PduR_ConfigData->PduRDestPduRef[TxPduId].PduRSrcPduRef;
		if((boolean)TRUE == PathIsEnabled[srcPduId])
		{
			srcPduMod = PduR_ConfigData->PduRSrcPduRef[srcPduId].SrcModuleType;
			if(PDUR_COM == srcPduMod)
			{
				if((boolean)TRUE == PduR_ConfigData->PduRSrcPduRef[srcPduId].PduRSrcPduUpTxConf)
				{
					srcUpPduId = PduR_ConfigData->PduRSrcPduRef[srcPduId].PduRSrcModulePduId;
					Com_TxConfirmation(srcUpPduId);
				}
			}
		}
	}
    return;
}
#endif/* (STD_ON == PDUR_IPDUM_TX_CONFIRMATION) && (STD_ON == PDUR_COM_SUPPORT) */
#endif/* STD_ON == PDUR_IPDUM_SUPPORT */

#if(STD_ON == PDUR_CANTP_SUPPORT)
/**
 * @sid 			0x06
 * @brief			This function is called at the start of receiving an N-SDU. The N-SDU might be
 *                  fragmented into multiple N-PDUs (FF with one or more following CFs) or might
 *                  consist of a single N-PDU (SF).
 * @param[in]		id: Identification of the I-PDU.
 * @param[in]		info: Pointer to a PduInfoType structure containin
 * @param[in]		TpSduLength: Total length of the N-SDU to be received.
 * @param[out]		bufferSizePtr: Available receive buffer in the receiving module
 * @param[in/out]	/
 * @return			BufReq_ReturnType
 * @retval			BUFREQ_OK
 * 					BUFREQ_E_NOT_OK
 * 					BUFREQ_E_OVFL
 * @req [SWS_PduR_00507]
 * @req [SWS_PduR_00794] The MetaData of I-PDUs provided by PduR_<SrcLoTp>StartOfReception shall be
 * 						 stored and provided with the I-PDU to <DstLoTp>_Transmit
 */
FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_CanTpStartOfReception(
	VAR(PduIdType, PDUR_VAR) id,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	VAR(PduLengthType, PDUR_VAR) TpSduLength,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
	BufReq_ReturnType bufQeqRet = BUFREQ_E_NOT_OK;
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_CANTPSTARTOFRECEPTION, PDUR_E_INVALID_REQUEST);
	}
	else if (id >= (PduIdType)PDUR_SRC_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_CANTPSTARTOFRECEPTION, PDUR_E_PDU_ID_INVALID);
	}
	else if (NULL_PTR == bufferSizePtr)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_CANTPSTARTOFRECEPTION, PDUR_E_PARAM_POINTER);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		bufQeqRet = PduR_LoTpStartOfReception(id,info,TpSduLength,bufferSizePtr);
	}
	return bufQeqRet;
}
/**
 * @req [SWS_PduR_00512]
 */
/**
 * @sid 			0x04
 * @brief			This function is called to provide the received data of an I-PDU segment (N-PDU)
 * 					to the upper layer. Each call to this function provides the next part of the
 * 					I-PDU data. The size of the remaining data is written to the position indicated
 * 					by bufferSizePtr.
 * @param[in]		id: Identification of the I-PDU.
 * @param[in]		info: Provides the source buffer (SduDataPtr) and the number of bytes to be
 * 					copied (SduLength). An SduLength of 0 can be used to query the current amount
 * 					of available buffer in the upper layer module. In this case, the SduDataPtr may
 * 					be a NULL_PTR.
 * @param[out]		bufferSizePtr: Available receive buffer in the receiving module
 * @param[in/out]	/
 * @return			BufReq_ReturnType
 * @retval			BUFREQ_OK
 * 					BUFREQ_E_NOT_OK
 * 					BUFREQ_E_OVFL
 */
FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_CanTpCopyRxData(
	VAR(PduIdType, PDUR_VAR) id,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
	BufReq_ReturnType bufQeqRet = BUFREQ_E_NOT_OK;
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_CANTPCOPYRXDATA, PDUR_E_INVALID_REQUEST);
	}
	else if (id >= (PduIdType)PDUR_SRC_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_CANTPCOPYRXDATA, PDUR_E_PDU_ID_INVALID);
	}
	else if ((NULL_PTR == info) || (NULL_PTR == bufferSizePtr))
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_CANTPCOPYRXDATA, PDUR_E_PARAM_POINTER);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		bufQeqRet = PduR_LoTpCopyRxData(id,info,bufferSizePtr);
	}
	return bufQeqRet;
}

/**
 * @req [SWS_PduR_00375]
 */
/**
 * @sid 			0x01
 * @brief			Called after an I-PDU has been received via the TP API, the result indicates
 * @param[in]		id: Identification of the received I-PDU.
 * @param[in]		result: Result of the reception.
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void, PDUR_CODE)
PduR_CanTpRxIndication(
	VAR(PduIdType, PDUR_VAR) id,
	VAR(Std_ReturnType, PDUR_VAR) result
)
{
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_CANTPRXINDICATION, PDUR_E_INVALID_REQUEST);
	}
	else if (id >= (PduIdType)PDUR_SRC_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_CANTPRXINDICATION, PDUR_E_PDU_ID_INVALID);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		PduR_LoTpRxIndication(id,result);
	}
	return;
}

/**
 * @req [SWS_PduR_00299] When a destination transport protocol module calls PduR_<LoTp>CopyTxData the
 * 						 PDU Router module shall call <Up>_CopyTxData in the source upper layer module.
 */
/**
 * @req [SWS_PduR_00518]
 */
/**
 * @sid 			0x07
 * @brief			This function is called to acquire the transmit data of an I-PDU segment (N-PDU).
 *                  Each call to this function provides the next part of the I-PDU data unless retry-
 *                  >TpDataState is TP_DATARETRY. In this case the function restarts to copy the
 *                  data beginning at the offset from the current position indicated by retry-
 *                  >TxTpDataCnt. The size of the remaining data is written to the position indicated
 *                  by availableDataPtr.
 * @param[in]		id: Identification of the received I-PDU.
 * @param[in]		info: Provides the destination buffer (SduDataPtr) and the number of bytes to be
 * 					copied (SduLength).
 * @param[in]		retry: This parameter is used to acknowledge transmitted data or to retransmit
 * 					data after transmission problems.
 * @param[out]		availableDataPtr: Indicates the remaining number of bytes that are available in the
 * 					upper layer module's Tx buffer.
 * @param[in/out]	/
 * @return			BufReq_ReturnType
 * @retval			BUFREQ_OK
 * 					BUFREQ_E_BUSY
 * 					BUFREQ_E_NOT_OK
 */
FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_CanTpCopyTxData(
	VAR(PduIdType, PDUR_VAR) id,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
)
{
	BufReq_ReturnType bufQeqRet = BUFREQ_E_NOT_OK;
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_CANTPCOPYTXDATA, PDUR_E_INVALID_REQUEST);
	}
	else if (id >= (PduIdType)PDUR_DEST_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_CANTPCOPYTXDATA, PDUR_E_PDU_ID_INVALID);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		bufQeqRet = PduR_LoTpCopyTxData(id,info,retry,availableDataPtr);
	}
	return bufQeqRet;
}

/**
 * @req [SWS_PduR_00301] In case of singlecast the PDU Router module shall forward the confirmation
 * 						 PduR_<LoTp>TxConfirmation from the lower layer transport protocol module to
 * 						 upper layer module using <Up>_TpTxConfirmation
 */
/**
 * @req [SWS_PduR_00381]
 */
/**
 * @sid 			0x08
 * @brief			This function is called after the I-PDU has been transmitted on its network, the
 *                  result indicates whether the transmission was successful or not.
 * @param[in]		id: Identification of the transmitted I-PDU.
 * @param[in]		result: Result of the transmission of the I-PDU.
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void, PDUR_CODE)
PduR_CanTpTxConfirmation(
	VAR(PduIdType, PDUR_VAR) id,
	VAR(Std_ReturnType, PDUR_VAR) result
)
{
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_CANTPTXCONFIRMATION, PDUR_E_INVALID_REQUEST);
	}
	else if (id >= (PduIdType)PDUR_DEST_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_CANTPTXCONFIRMATION, PDUR_E_PDU_ID_INVALID);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		PduR_LoTpTxConfirmation(id,result);
	}
	return;
}
#endif/* STD_ON == PDUR_CANTP_SUPPORT */

#if(STD_ON == PDUR_SOAD_SUPPORT)
#if(STD_ON == PDUR_SOADTP_SUPPORT)
/**
 * @sid 			0x66
 * @brief			This function is called at the start of receiving an N-SDU. The N-SDU might be
 *                  fragmented into multiple N-PDUs (FF with one or more following CFs) or might
 *                  consist of a single N-PDU (SF).
 * @param[in]		id: Identification of the I-PDU.
 * @param[in]		info: Pointer to a PduInfoType structure containin
 * @param[in]		TpSduLength: Total length of the N-SDU to be received.
 * @param[out]		bufferSizePtr: Available receive buffer in the receiving module
 * @param[in/out]	/
 * @return			BufReq_ReturnType
 * @retval			BUFREQ_OK
 * 					BUFREQ_E_NOT_OK
 * 					BUFREQ_E_OVFL
 * @req [SWS_PduR_00507]
 * @req [SWS_PduR_00794] The MetaData of I-PDUs provided by PduR_<SrcLoTp>StartOfReception shall be
 * 						 stored and provided with the I-PDU to <DstLoTp>_Transmit
 */
FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_SoAdTpStartOfReception(
	VAR(PduIdType, PDUR_VAR) id,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	VAR(PduLengthType, PDUR_VAR) TpSduLength,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
	BufReq_ReturnType bufQeqRet = BUFREQ_E_NOT_OK;
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_SOADTPSTARTOFRECEPTION, PDUR_E_INVALID_REQUEST);
	}
	else if (id >= (PduIdType)PDUR_SRC_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_SOADTPSTARTOFRECEPTION, PDUR_E_PDU_ID_INVALID);
	}
	else if (NULL_PTR == bufferSizePtr)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_SOADTPSTARTOFRECEPTION, PDUR_E_PARAM_POINTER);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		bufQeqRet = PduR_LoTpStartOfReception(id,info,TpSduLength,bufferSizePtr);
	}
	return bufQeqRet;
}

/**
 * @sid 			0x64
 * @brief			This function is called to provide the received data of an I-PDU segment (N-PDU)
 * 					to the upper layer. Each call to this function provides the next part of the
 * 					I-PDU data. The size of the remaining data is written to the position indicated
 * 					by bufferSizePtr.
 * @param[in]		id: Identification of the I-PDU.
 * @param[in]		info: Provides the source buffer (SduDataPtr) and the number of bytes to be
 * 					copied (SduLength). An SduLength of 0 can be used to query the current amount
 * 					of available buffer in the upper layer module. In this case, the SduDataPtr may
 * 					be a NULL_PTR.
 * @param[out]		bufferSizePtr: Available receive buffer in the receiving module
 * @param[in/out]	/
 * @return			BufReq_ReturnType
 * @retval			BUFREQ_OK
 * 					BUFREQ_E_NOT_OK
 * 					BUFREQ_E_OVFL
 */
FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_SoAdTpCopyRxData(
	VAR(PduIdType, PDUR_VAR) id,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
	BufReq_ReturnType bufQeqRet = BUFREQ_E_NOT_OK;
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_SOADTPCOPYRXDATA, PDUR_E_INVALID_REQUEST);
	}
	else if (id >= (PduIdType)PDUR_SRC_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_SOADTPCOPYRXDATA, PDUR_E_PDU_ID_INVALID);
	}
	else if ((NULL_PTR == info) || (NULL_PTR == bufferSizePtr))
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_SOADTPCOPYRXDATA, PDUR_E_PARAM_POINTER);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		bufQeqRet = PduR_LoTpCopyRxData(id,info,bufferSizePtr);
	}
	return bufQeqRet;
}

/**
 * @sid 			0x65
 * @brief			Called after an I-PDU has been received via the TP API, the result indicates
 * @param[in]		id: Identification of the received I-PDU.
 * @param[in]		result: Result of the reception.
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void, PDUR_CODE)
PduR_SoAdTpRxIndication(
	VAR(PduIdType, PDUR_VAR) id,
	VAR(Std_ReturnType, PDUR_VAR) result
)
{
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_SOADTPRXINDICATION, PDUR_E_INVALID_REQUEST);
	}
	else if (id >= (PduIdType)PDUR_SRC_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_SOADTPRXINDICATION, PDUR_E_PDU_ID_INVALID);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		PduR_LoTpRxIndication(id,result);
	}
	return;
}

/**
 * @sid 			0x67
 * @brief			This function is called to acquire the transmit data of an I-PDU segment (N-PDU).
 *                  Each call to this function provides the next part of the I-PDU data unless retry-
 *                  >TpDataState is TP_DATARETRY. In this case the function restarts to copy the
 *                  data beginning at the offset from the current position indicated by retry-
 *                  >TxTpDataCnt. The size of the remaining data is written to the position indicated
 *                  by availableDataPtr.
 * @param[in]		id: Identification of the received I-PDU.
 * @param[in]		info: Provides the destination buffer (SduDataPtr) and the number of bytes to be
 * 					copied (SduLength).
 * @param[in]		retry: This parameter is used to acknowledge transmitted data or to retransmit
 * 					data after transmission problems.
 * @param[out]		availableDataPtr: Indicates the remaining number of bytes that are available in the
 * 					upper layer module's Tx buffer.
 * @param[in/out]	/
 * @return			BufReq_ReturnType
 * @retval			BUFREQ_OK
 * 					BUFREQ_E_BUSY
 * 					BUFREQ_E_NOT_OK
 */
FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_SoAdTpCopyTxData(
	VAR(PduIdType, PDUR_VAR) id,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
)
{
	BufReq_ReturnType bufQeqRet = BUFREQ_E_NOT_OK;
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_SOADTPCOPYTXDATA, PDUR_E_INVALID_REQUEST);
	}
	else if (id >= (PduIdType)PDUR_DEST_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_SOADTPCOPYTXDATA, PDUR_E_PDU_ID_INVALID);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		bufQeqRet = PduR_LoTpCopyTxData(id,info,retry,availableDataPtr);
	}
	return bufQeqRet;
}

/**
 * @sid 			0x68
 * @brief			This function is called after the I-PDU has been transmitted on its network, the
 *                  result indicates whether the transmission was successful or not.
 * @param[in]		id: Identification of the transmitted I-PDU.
 * @param[in]		result: Result of the transmission of the I-PDU.
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void, PDUR_CODE)
PduR_SoAdTpTxConfirmation(
	VAR(PduIdType, PDUR_VAR) id,
	VAR(Std_ReturnType, PDUR_VAR) result
)
{
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_SOADTPTXCONFIRMATION, PDUR_E_INVALID_REQUEST);
	}
	else if (id >= (PduIdType)PDUR_DEST_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_SOADTPTXCONFIRMATION, PDUR_E_PDU_ID_INVALID);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		PduR_LoTpTxConfirmation(id,result);
	}
	return;
}
#endif/* STD_ON == PDUR_SOADTP_SUPPORT */
#endif


#if(STD_ON == PDUR_LINTP_SUPPORT)

/**
 * @req [SWS_PduR_00794] The MetaData of I-PDUs provided by PduR_<SrcLoTp>StartOfReception shall be
 * 						 stored and provided with the I-PDU to <DstLoTp>_Transmit
 */
/**
 * @sid 			0x56
 * @brief			This function is called at the start of receiving an N-SDU. The N-SDU might be
 *                  fragmented into multiple N-PDUs (FF with one or more following CFs) or might
 *                  consist of a single N-PDU (SF).
 * @param[in]		id: Identification of the I-PDU.
 * @param[in]		info: Pointer to a PduInfoType structure containin
 * @param[in]		TpSduLength: Total length of the N-SDU to be received.
 * @param[out]		bufferSizePtr: Available receive buffer in the receiving module
 * @param[in/out]	/
 * @return			BufReq_ReturnType
 * @retval			BUFREQ_OK
 * 					BUFREQ_E_NOT_OK
 * 					BUFREQ_E_OVFL
 */
FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_LinTpStartOfReception(
	VAR(PduIdType, PDUR_VAR) id,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	PduLengthType TpSduLength,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
	BufReq_ReturnType bufQeqRet = BUFREQ_E_NOT_OK;
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_LINTPSTARTOFRECEPTION, PDUR_E_INVALID_REQUEST);
	}
	else if (id >= (PduIdType)PDUR_SRC_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_LINTPSTARTOFRECEPTION, PDUR_E_PDU_ID_INVALID);
	}
	else if (NULL_PTR == bufferSizePtr)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_LINTPSTARTOFRECEPTION, PDUR_E_PARAM_POINTER);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		bufQeqRet = PduR_LoTpStartOfReception(id,info,TpSduLength,bufferSizePtr);
	}
	return bufQeqRet;
}

/**
 * @sid 			0x54
 * @brief			This function is called to provide the received data of an I-PDU segment (N-PDU)
 * 					to the upper layer. Each call to this function provides the next part of the I-PDU
 * 					data. The size of the remaining data is written to the position indicated by
 * 					bufferSizePtr.
 * @param[in]		id: Identification of the I-PDU.
 * @param[in]		info: Provides the source buffer (SduDataPtr) and the number of bytes to be
 * 					copied (SduLength). An SduLength of 0 can be used to query the current amount of
 * 					available buffer in the upper layer module. In this case, the SduDataPtr may be
 * 					a NULL_PTR.
 * @param[out]		bufferSizePtr: Available receive buffer in the receiving module
 * @param[in/out]	/
 * @return			BufReq_ReturnType
 * @retval			BUFREQ_OK
 * 					BUFREQ_E_NOT_OK
 * 					BUFREQ_E_OVFL
 */
FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_LinTpCopyRxData(
	VAR(PduIdType, PDUR_VAR) id,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
	BufReq_ReturnType bufQeqRet = BUFREQ_E_NOT_OK;
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_LINTPCOPYRXDATA, PDUR_E_INVALID_REQUEST);
	}
	else if (id >= (PduIdType)PDUR_SRC_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_LINTPCOPYRXDATA, PDUR_E_PDU_ID_INVALID);
	}
	else if ((NULL_PTR == info) || (NULL_PTR == bufferSizePtr))
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_LINTPCOPYRXDATA, PDUR_E_PARAM_POINTER);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		bufQeqRet = PduR_LoTpCopyRxData(id,info,bufferSizePtr);
	}
	return bufQeqRet;
}

/**
 * @sid 			0x55
 * @brief			Called after an I-PDU has been received via the TP API, the result indicates
 * @param[in]		id: Identification of the received I-PDU.
 * @param[in]		result: Result of the reception.
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void, PDUR_CODE)
PduR_LinTpRxIndication(
	VAR(PduIdType, PDUR_VAR) id,
	VAR(Std_ReturnType, PDUR_VAR) result
)
{
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_LINTPRXINDICATION, PDUR_E_INVALID_REQUEST);
	}
	else if (id >= (PduIdType)PDUR_SRC_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_LINTPRXINDICATION, PDUR_E_PDU_ID_INVALID);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		PduR_LoTpRxIndication(id,result);
	}
	return;
}
/**
 * @req [SWS_PduR_00299] When a destination transport protocol module calls PduR_<LoTp>CopyTxData the
 * 						 PDU Router module shall call <Up>_CopyTxData in the source upper layer module.
 */
/**
 * @sid 			0x57
 * @brief			This function is called to acquire the transmit data of an I-PDU segment (N-PDU).
 *                  Each call to this function provides the next part of the I-PDU data unless retry-
 *                  >TpDataState is TP_DATARETRY. In this case the function restarts to copy the
 *                  data beginning at the offset from the current position indicated by retry-
 *                  >TxTpDataCnt. The size of the remaining data is written to the position indicated
 *                  by availableDataPtr.
 * @param[in]		id: Identification of the received I-PDU.
 * @param[in]		info: Provides the destination buffer (SduDataPtr) and the number of bytes to be
 * 					copied (SduLength).
 * @param[in]		retry: This parameter is used to acknowledge transmitted data or to retransmit data
 * 					after transmission problems.
 * @param[out]		availableDataPtr: Indicates the remaining number of bytes that are available in the
 * 					upper layer module's Tx buffer.
 * @param[in/out]	/
 * @return			BufReq_ReturnType
 * @retval			BUFREQ_OK
 * 					BUFREQ_E_BUSY
 * 					BUFREQ_E_NOT_OK
 */
FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_LinTpCopyTxData(
	VAR(PduIdType, PDUR_VAR) id,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
)
{
	BufReq_ReturnType bufQeqRet = BUFREQ_E_NOT_OK;
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_LINTPCOPYTXDATA, PDUR_E_INVALID_REQUEST);
	}
	else if (id >= (PduIdType)PDUR_DEST_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_LINTPCOPYTXDATA, PDUR_E_PDU_ID_INVALID);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		bufQeqRet = PduR_LoTpCopyTxData(id,info,retry,availableDataPtr);
	}
	return bufQeqRet;
}

/**
 * @req [SWS_PduR_00301] In case of singlecast the PDU Router module shall forward the confirmation
 * 						 PduR_<LoTp>TxConfirmation from the lower layer transport protocol module to
 * 						 upper layer module using <Up>_TpTxConfirmation
 */
/**
 * @sid 			0x58
 * @brief			This function is called after the I-PDU has been transmitted on its network, the
 *                  result indicates whether the transmission was successful or not.
 * @param[in]		id: Identification of the transmitted I-PDU.
 * @param[in]		result: Result of the transmission of the I-PDU.
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void, PDUR_CODE)
PduR_LinTpTxConfirmation(
	VAR(PduIdType, PDUR_VAR) id,
	VAR(Std_ReturnType, PDUR_VAR) result
)
{
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_LINTPTXCONFIRMATION, PDUR_E_INVALID_REQUEST);
	}
	else if (id >= (PduIdType)PDUR_DEST_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_LINTPTXCONFIRMATION, PDUR_E_PDU_ID_INVALID);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		PduR_LoTpTxConfirmation(id,result);
	}
	return;
}
#endif/* STD_ON == PDUR_LINTP_SUPPORT */
#if(STD_ON == PDUR_J1939TP_SUPPORT)

/**
 * @req [SWS_PduR_00794] The MetaData of I-PDUs provided by PduR_<SrcLoTp>StartOfReception shall be
 * 						 stored and provided with the I-PDU to <DstLoTp>_Transmit
 */
/**
 * @sid 			0x16
 * @brief			This function is called at the start of receiving an N-SDU. The N-SDU might be
 *                  fragmented into multiple N-PDUs (FF with one or more following CFs) or might
 *                  consist of a single N-PDU (SF).
 * @param[in]		id: Identification of the I-PDU.
 * @param[in]		info: Pointer to a PduInfoType structure containin
 * @param[in]		TpSduLength: Total length of the N-SDU to be received.
 * @param[out]		bufferSizePtr: Available receive buffer in the receiving module
 * @param[in/out]	/
 * @return			BufReq_ReturnType
 * @retval			BUFREQ_OK
 * 					BUFREQ_E_NOT_OK
 * 					BUFREQ_E_OVFL
 */
FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_J1939TpStartOfReception(
	VAR(PduIdType, PDUR_VAR) id,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	PduLengthType TpSduLength,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
	BufReq_ReturnType bufQeqRet = BUFREQ_E_NOT_OK;
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
        PDUR_DET_ERROR_REPORT(PDUR_SID_J1939TPSTARTOFRECEPTION, PDUR_E_INVALID_REQUEST);
	}
	else if (id >= (PduIdType)PDUR_SRC_PDU_SUM)
	{
	    PDUR_DET_ERROR_REPORT(PDUR_SID_J1939TPSTARTOFRECEPTION, PDUR_E_PDU_ID_INVALID);
	}
	else if (NULL_PTR == bufferSizePtr)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_J1939TPSTARTOFRECEPTION, PDUR_E_PARAM_POINTER);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		bufQeqRet = PduR_LoTpStartOfReception(id,info,TpSduLength,bufferSizePtr);
	}
	return bufQeqRet;
}

/**
 * @sid 			0x14
 * @brief			This function is called to provide the received data of an I-PDU segment (N-PDU)
 * 					to the upper layer. Each call to this function provides the next part of the I-PDU
 * 					data. The size of the remaining data is written to the position indicated by
 * 					bufferSizePtr.
 * @param[in]		id: Identification of the I-PDU.
 * @param[in]		info: Provides the source buffer (SduDataPtr) and the number of bytes to be copied
 * 					(SduLength). An SduLength of 0 can be used to query the current amount of available
 * 					buffer in the upper layer module. In this case, the SduDataPtr may be a NULL_PTR.
 * @param[out]		bufferSizePtr: Available receive buffer in the receiving module
 * @param[in/out]	/
 * @return			BufReq_ReturnType
 * @retval			BUFREQ_OK
 * 					BUFREQ_E_NOT_OK
 * 					BUFREQ_E_OVFL
 */
FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_J1939TpCopyRxData(
	VAR(PduIdType, PDUR_VAR) id,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
	BufReq_ReturnType bufQeqRet = BUFREQ_E_NOT_OK;
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_J1939TPCOPYRXDATA, PDUR_E_INVALID_REQUEST);
	}
	else if (id >= (PduIdType)PDUR_SRC_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_J1939TPCOPYRXDATA, PDUR_E_PDU_ID_INVALID);
	}
	else if ((NULL_PTR == info) || (NULL_PTR == bufferSizePtr))
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_J1939TPCOPYRXDATA, PDUR_E_PARAM_POINTER);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		bufQeqRet = PduR_LoTpCopyRxData(id,info,bufferSizePtr);
	}
	return bufQeqRet;
}

/**
 * @sid 			0x15
 * @brief			Called after an I-PDU has been received via the TP API, the result indicates
 * @param[in]		id: Identification of the received I-PDU.
 * @param[in]		result: Result of the reception.
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void, PDUR_CODE)
PduR_J1939TpRxIndication(
	VAR(PduIdType, PDUR_VAR) id,
	VAR(Std_ReturnType, PDUR_VAR) result
)
{
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_J1939TPRXINDICATION, PDUR_E_INVALID_REQUEST);
	}
	else if (id >= (PduIdType)PDUR_SRC_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_J1939TPRXINDICATION, PDUR_E_PDU_ID_INVALID);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		PduR_LoTpRxIndication(id,result);
	}
	return;
}

/**
 * @req [SWS_PduR_00299] When a destination transport protocol module calls PduR_<LoTp>CopyTxData the
 * 						 PDU Router module shall call <Up>_CopyTxData in the source upper layer module.
 */
/**
 * @sid 			0x07
 * @brief			This function is called to acquire the transmit data of an I-PDU segment (N-PDU).
 *                  Each call to this function provides the next part of the I-PDU data unless retry-
 *                  >TpDataState is TP_DATARETRY. In this case the function restarts to copy the
 *                  data beginning at the offset from the current position indicated by retry-
 *                  >TxTpDataCnt. The size of the remaining data is written to the position indicated
 *                  by availableDataPtr.
 * @param[in]		id: Identification of the received I-PDU.
 * @param[in]		info: Provides the destination buffer (SduDataPtr) and the number of bytes to be
 * 					copied (SduLength).
 * @param[in]		retry: This parameter is used to acknowledge transmitted data or to retransmit
 * 					data after transmission problems.
 * @param[out]		availableDataPtr: Indicates the remaining number of bytes that are available in
 * 					the upper layer module's Tx buffer.
 * @param[in/out]	/
 * @return			BufReq_ReturnType
 * @retval			BUFREQ_OK
 * 					BUFREQ_E_BUSY
 * 					BUFREQ_E_NOT_OK
 */
FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_J1939TpCopyTxData(
	VAR(PduIdType, PDUR_VAR) id,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
)
{
	BufReq_ReturnType bufQeqRet = BUFREQ_E_NOT_OK;
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_J1939TPCOPYTXDATA, PDUR_E_INVALID_REQUEST);
	}
	else if (id >= (PduIdType)PDUR_DEST_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_J1939TPCOPYTXDATA, PDUR_E_PDU_ID_INVALID);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		bufQeqRet = PduR_LoTpCopyTxData(id,info,retry,availableDataPtr);
	}
	return bufQeqRet;
}

/**
 * @req [SWS_PduR_00301] In case of singlecast the PDU Router module shall forward the confirmation
 * 						 PduR_<LoTp>TxConfirmation from the lower layer transport protocol module to
 * 						 upper layer module using <Up>_TpTxConfirmation
 */
/**
 * @sid 			0x18
 * @brief			This function is called after the I-PDU has been transmitted on its network, the
 *                  result indicates whether the transmission was successful or not.
 * @param[in]		id: Identification of the transmitted I-PDU.
 * @param[in]		result: Result of the transmission of the I-PDU.
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void, PDUR_CODE)
PduR_J1939TpTxConfirmation(
	VAR(PduIdType, PDUR_VAR) id,
	VAR(Std_ReturnType, PDUR_VAR) result
)
{
	#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	if(PDUR_ONLINE != PduR_Status)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_J1939TPTXCONFIRMATION, PDUR_E_INVALID_REQUEST);
	}
	else if (id >= (PduIdType)PDUR_DEST_PDU_SUM)
	{
		PDUR_DET_ERROR_REPORT(PDUR_SID_J1939TPTXCONFIRMATION, PDUR_E_PDU_ID_INVALID);
	}
	else
	#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
	{
		PduR_LoTpTxConfirmation(id,result);
	}
	return;
}
#endif/* STD_ON == PDUR_J1939TP_SUPPORT */

/**
 * @brief			copy data from source to dest
 * @param[in]		An array that needs to be assigned
 * @param[in]		An array that needs to be copied
 * @param[in]		The length required to be copied
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
STATIC FUNC(void, PDUR_CODE)
PduR_Memcpy(
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) dest,
    P2CONST(uint8, AUTOMATIC, AUTOMATIC) source,
	VAR(uint16, PDUR_VAR) length
)
{
	while(length > 0u)
	{
		if(source != NULL_PTR)
		{
			*dest = *source;
			dest++;/* PRQA S 0498 EOF # violate MISRA_2004_Rule_17.4:There is no array, no indexes */
			source++;
		}
		else
		{
			break;
		}
		length--;
	}
	return;
}

#if((STD_ON == PDUR_CANIF_SUPPORT) || (STD_ON == PDUR_LINIF_SUPPORT))
/**
 * @req [SWS_PduR_00436] The PDU Router module shall support routing of I-PDUs between a source
 * 						 communication interface module and one or more destination communication
 * 						 interface modules
 */
/**
 * @brief			gateway Pdu
 * @param[in]		DestModule :Pdu module
 * @param[in]		RxPduId id
 * @param[in]		DestPduId :id
 * @param[in]		InfoPtr :Length and pointer to the buffer of the I-PDU.
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
STATIC FUNC(void, PDUR_CODE)
PduR_GateWayIfPdu(
	VAR(uint8, PDUR_VAR) DestModule,
	VAR(PduIdType, PDUR_VAR) RxPduId,
	VAR(PduIdType, PDUR_VAR) DestPduId,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) InfoPtr
)
{
	switch(DestModule)
	{
		#if(STD_ON == PDUR_CANIF_SUPPORT)
		case PDUR_CANIF:
			PduR_GatewayCanIfPduHandle(RxPduId,DestPduId,InfoPtr, DestModule);
			break;
		#endif/* STD_ON == PDUR_CANIF_SUPPORT */
		#if(STD_ON == PDUR_LINIF_SUPPORT)
		case PDUR_LINIF:
			PduR_GatewayLinIfPduHandle(RxPduId,DestPduId,InfoPtr, DestModule);
			break;
		#endif/* STD_ON == PDUR_LINIF_SUPPORT */
		default:
			break;
	}
}

/**
 * @brief			gateway CanIf Pdu
 * @param[in]		DestModule :Pdu module
 * @param[in]		RxPduId id
 * @param[in]		DestPduId :id
 * @param[in]		InfoPtr :Length and pointer to the buffer of the I-PDU.
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
#if(STD_ON == PDUR_CANIF_SUPPORT)
STATIC FUNC(void, PDUR_CODE)
PduR_GatewayCanIfPduHandle(
	VAR(PduIdType, PDUR_VAR) RxPduId,
	VAR(PduIdType, PDUR_VAR) PduId,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) InfoPtr,
	VAR(uint8, PDUR_VAR) DestModule
)
{
	PduR_DestPduDataProvisionType provisionType;
	PduInfoType pduInfo;
	PduIdType gateWayIfPduDirectStateId;
	uint16 bufId = 0u;
	uint8 destPduNum,cnt;
	uint8 index = 0u;
	destPduNum = PduR_ConfigData->PduRRoutingTableRef[RxPduId].DestPduNumber;
	for(cnt = 0u; cnt < destPduNum; cnt++)
	{
		if(PduR_ConfigData->PduRRoutingTableRef[RxPduId].PduRDestPduIdRef[cnt].DestPduId == PduId)
		{
			bufId = PduR_ConfigData->PduRRoutingTableRef[RxPduId].PduRDestPduIdRef[cnt].\
					PduRDestTxBufferRef;
			index = cnt;
			break;
		}
	}
	provisionType = PduR_ConfigData->PduRRoutingTableRef[RxPduId].PduRDestPduIdRef[index].\
			PduRDestPduDataProvision;
	gateWayIfPduDirectStateId = PduR_ConfigData->PduRRoutingTableRef[RxPduId].PduRDestPduIdRef[index].\
			PduRGatewayDirectTxStateIndex;
	/* Configure the buffer, trigger the sending mode, and wait for the underlying call to trigger the
	 * sending interface */
	/**
	 * @req [SWS_PduR_00306] The PduRDestPduDataProvision of the destination I-PDU  is configured to
	 * 						 PDUR_TRIGGERTRANSMIT. When <DstLo>_Transmit is called the <DstLo> module
	 * 						 does not copy the data and the PDU Router module shall buffer the I-PDU
	 * 						 and Specification of PDU Router wait for the PduR_<DstLo>TriggerTransmit
	 * 						 call from the <DstLo> module
	 */
	if(PDUR_TRIGGERTRANSMIT == provisionType)
	{
		/**/
		PduR_EnQueueBuffer(InfoPtr,bufId,DestModule);
		pduInfo.SduDataPtr = NULL_PTR;
		pduInfo.SduLength =(uint16) 0u;
		(void)CanIf_Transmit(PduId, &pduInfo);
	}
	/**
	 * @req [SWS_PduR_00303] The PduRDestPduDataProvision of the destination I-PDU is configured to
	 * 						 PDUR_DIRECT. When <DstLo>_Transmit is called the <DstLo> module copies
	 * 						 the data and the PDU Router does not buffer the transmitted I-PDU any
	 * 						 longer
	 */
	else
	{
		/**
		 * @req [SWS_PduR_00783] In case the I-PDU is gatewayed without buffering in the PDU Router,
		 * 						 the PDU Router shall forward the length without checking, just calling
		 * 						 the transmit function(s) of the destination modules
		 */
		/* No configuration buffer, send directly, do not return the value */
		if((uint16)0xffff == bufId)
		{
			/**
			 * @req [SWS_PduR_00437] The PDU Router module shall support routing of I-PDUs between
			 * 						 communication interface modules with immediate transmission
			 */
			(void)CanIf_Transmit(PduId, InfoPtr);
		}
		else
		{
			/* Just configure a buffer, follow the last thing that is the best, send the old data,
			 * and keep the new data */
			
			if(1u == PduR_TxBuffer[bufId].PduRTxBufferDepth)
			{
				if(PDUR_IDLE == PduR_DestPduState[gateWayIfPduDirectStateId])
				{
					/*Send the old data out of the buffer and store new data into the buffer*/
				
					if((boolean)TRUE == PduR_TxBuffer[bufId].PduRTxBufferRef[0].used)
					{

						pduInfo.SduDataPtr = PduR_TxBuffer[bufId].PduRTxBufferRef[0].TxBufferData;
						pduInfo.SduLength = PduR_TxBuffer[bufId].PduRTxBufferRef[0].SduLength;
				
						if((Std_ReturnType)E_OK == CanIf_Transmit(PduId, &pduInfo))
						{
							PduR_DestPduState[gateWayIfPduDirectStateId] = PDUR_BUSY;
						}
						/**
						 * @req [SWS_PduR_00784] When the I-PDU is transmitted from the PduR buffer to
						 * 						 the destination module the PduR shall pass the number
						 * 						 of bytes which was copied to the buffer as SduLength
						 */
						PduR_EnQueueBuffer(InfoPtr,bufId, DestModule);
					}
					/* Sending new data, even if it fails, doesn't store */
					else
					{
				
						if((Std_ReturnType)E_OK == CanIf_Transmit(PduId, InfoPtr))
						{
							PduR_DestPduState[gateWayIfPduDirectStateId] = PDUR_BUSY;
						}
					}
				}
				/* Directly provide data, gateways busy, store data to buffers */
				else
				{
					PduR_EnQueueBuffer(InfoPtr,bufId,DestModule);
					PduR_DestPduState[gateWayIfPduDirectStateId] = PDUR_IDLE;
				}
			}
			/*FIFO*/
			/**
			 * @req [SWS_PduR_00787] When PduR_<SrcLo>RxIndication is called and the FIFO queue is
			 * 						 not empty then the received I-PDU shall be copied as latest entry.
			 */
			else
			{
				if(PDUR_IDLE == PduR_DestPduState[gateWayIfPduDirectStateId])
				{
					/* Send the first data in the buffer and store the later data to the buffer */
				
					if((boolean)TRUE == PduR_TxBuffer[bufId].PduRTxBufferRef[0].used)
					{
						/**
						 * @req [SWS_PduR_00784] When the I-PDU is transmitted from the PduR buffer
						 * 						 to the destination module the PduR shall pass the
						 * 						 number of bytes which was copied to the buffer as
						 * 						 SduLength
						 */
						pduInfo.SduDataPtr = PduR_TxBuffer[bufId].PduRTxBufferRef[0].TxBufferData;
						pduInfo.SduLength = PduR_TxBuffer[bufId].PduRTxBufferRef[0].SduLength;
						/**
						 * @req [SWS_PduR_00667] When PduR_<DstLo>TxConfirmation is called and the FIFO
						 * 						 queue is not empty in case of direct data provision
						 * 						 <DstLo>_Transmit shall be called with the oldest I-PDU
						 * 						 of the FIFO. The transmitted I-PDU shall be removed
						 * 						 afterwards
						 */
				
						if((Std_ReturnType)E_OK == CanIf_Transmit(PduId, &pduInfo))
						{
							PduR_DestPduState[gateWayIfPduDirectStateId] = PDUR_BUSY;
						}
						else
						{
							#if(STD_ON == PDUR_DEV_ERROR_DETECT)
							PDUR_DET_ERROR_REPORT(PDUR_SID_CANIFRXINDICATION, \
									PDUR_E_PDU_INSTANCES_LOST);
							#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
						}
						/**
						 * @req [SWS_PduR_00793] PduR shall enqueue new data in the FIFO when
						 * 						 PduR_<SrcLo>RxIndication is called and the last
						 * 						 transmission of the same PDU has not yet been
						 * 						 confirmed via PduR_<DstLo>TxConfirmation
						 */
						PduR_ClearQueueBuffer(bufId);
						PduR_EnQueueBuffer(InfoPtr,bufId,DestModule);
					}
					/* Sending new data, even if it fails, doesn't store */
					/**
					 * @req [SWS_PduR_00665] When PduR_<SrcLo>RxIndication is called and the FIFO queue
					 * 						 is empty and no confirmation is outstanding for the same
					 * 						 PDU, <DstLo>_Transmit shall be called directly. The FIFO
					 * 						 stays empty.
					 */
					else
					{
				
						if((Std_ReturnType)E_OK == CanIf_Transmit(PduId, InfoPtr))
						{
							PduR_DestPduState[gateWayIfPduDirectStateId] = PDUR_BUSY;
						}
						else
						{
							#if(STD_ON == PDUR_DEV_ERROR_DETECT)
							PDUR_DET_ERROR_REPORT(PDUR_SID_CANIFRXINDICATION, \
									PDUR_E_PDU_INSTANCES_LOST);
							#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
						}
					}
				}
				/* Directly provide data, gateways busy, store data to buffers */
				else
				{
					PduR_EnQueueBuffer(InfoPtr,bufId,DestModule);
				}
			}
		}
	}
	return;
}
#endif/* STD_ON == PDUR_CANIF_SUPPORT */

/**
 * @brief			gateway LinIf Pdu
 * @param[in]		DestModule :Pdu module
 * @param[in]		RxPduId id
 * @param[in]		DestPduId :id
 * @param[in]		InfoPtr :Length and pointer to the buffer of the I-PDU.
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
#if(STD_ON == PDUR_LINIF_SUPPORT)
STATIC FUNC(void, PDUR_CODE)
PduR_GatewayLinIfPduHandle(
	VAR(PduIdType, PDUR_VAR) RxPduId,
	VAR(PduIdType, PDUR_VAR) PduId,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) InfoPtr,
	VAR(uint8, PDUR_VAR) DestModule
)
{
	PduR_DestPduDataProvisionType provisionType;
	PduInfoType pduInfo;
	PduIdType gateWayIfPduDirectStateId;
	uint16 bufId;
	uint8 destPduNum = 0u;
	uint8 cnt = 0u;
	uint8 index;
	destPduNum = PduR_ConfigData->PduRRoutingTableRef[RxPduId].DestPduNumber;
	for(cnt = 0u; cnt < destPduNum; cnt++)
	{
		if(PduR_ConfigData->PduRRoutingTableRef[RxPduId].PduRDestPduIdRef[cnt].DestPduId == PduId)
		{
			bufId = PduR_ConfigData->PduRRoutingTableRef[RxPduId].PduRDestPduIdRef[cnt].\
					PduRDestTxBufferRef;
			index = cnt;
		}
	}
	provisionType = PduR_ConfigData->PduRRoutingTableRef[RxPduId].PduRDestPduIdRef[index].\
			PduRDestPduDataProvision;
	gateWayIfPduDirectStateId = PduR_ConfigData->PduRRoutingTableRef[RxPduId].PduRDestPduIdRef[index].\
			PduRGatewayDirectTxStateIndex;

	/* Configure the buffer, trigger the sending mode, and wait for the underlying call to trigger the
	 * sending interface */
	/**
	 * @req [SWS_PduR_00306] The PduRDestPduDataProvision of the destination I-PDU is configured to
	 * 						 PDUR_TRIGGERTRANSMIT. When <DstLo>_Transmit is called the <DstLo> module
	 * 						 does not copy the data and the PDU Router module shall buffer the I-PDU
	 * 						 and Specification of PDU Router wait for the PduR_<DstLo>TriggerTransmit
	 * 						 call from the <DstLo> module
	 */
	if(PDUR_TRIGGERTRANSMIT == provisionType)
	{
		PduR_EnQueueBuffer(InfoPtr,bufId,DestModule);
		pduInfo.SduDataPtr = NULL_PTR;
		pduInfo.SduLength = 0u;
		(void)LinIf_Transmit(PduId, &pduInfo);
	}
	/**
	 * @req [SWS_PduR_00303] The PduRDestPduDataProvision of the destination I-PDU is configured to
	 * 						 PDUR_DIRECT. When <DstLo>_Transmit is called the <DstLo> module copies
	 * 						 the data and the PDU Router does not buffer the transmitted I-PDU any
	 * 						 longer
	 */
	else
	{
		/**
		 * @req [SWS_PduR_00783] In case the I-PDU is gatewayed without buffering in the PDU Router,
		 * 						 the PDU Router shall forward the length without checking, just calling
		 * 						 the transmit function(s) of the destination modules
		 */
		if(0xffffu == bufId)
		{
			/**
			 * @req [SWS_PduR_00437] The PDU Router module shall support routing of I-PDUs between
			 * 						 communication interface modules with immediate transmission
			 */
			(void)LinIf_Transmit(PduId, InfoPtr);
		}
		else
		{
			/* Just configure a buffer, follow the last thing that is the best, send the old data, and
			 * keep the new data */
			if(1u == PduR_TxBuffer[bufId].PduRTxBufferDepth)
			{
				if(PDUR_IDLE == PduR_DestPduState[gateWayIfPduDirectStateId])
				{
					/* Send the old data out of the buffer and store new data into the buffer */
					if((boolean)TRUE == PduR_TxBuffer[bufId].PduRTxBufferRef[0].used)
					{
						/**
						 * @req [SWS_PduR_00784] When the I-PDU is transmitted from the PduR buffer to
						 * 						 the destination module the PduR shall pass the number
						 * 						 of bytes which was copied to the buffer as SduLength
						 */
						pduInfo.SduDataPtr = PduR_TxBuffer[bufId].PduRTxBufferRef[0].TxBufferData;
						pduInfo.SduLength = PduR_TxBuffer[bufId].PduRTxBufferRef[0].SduLength;
						if((Std_ReturnType)E_OK == LinIf_Transmit(PduId, &pduInfo))
						{
							PduR_DestPduState[gateWayIfPduDirectStateId] = PDUR_BUSY;
						}
						PduR_EnQueueBuffer(InfoPtr,bufId,DestModule);
					}
					/* Sending new data, even if it fails, doesn't store */
					else
					{
						if((Std_ReturnType)E_OK == LinIf_Transmit(PduId, InfoPtr))
						{
							PduR_DestPduState[gateWayIfPduDirectStateId] = PDUR_BUSY;
						}
					}
				}
				/* Directly provide data, gateways busy, store data to buffers */
				else
				{
					PduR_EnQueueBuffer(InfoPtr,bufId,DestModule);
					PduR_DestPduState[gateWayIfPduDirectStateId] = PDUR_IDLE;
				}
			}
			/*FIFO*/
			/**
			 * @req [SWS_PduR_00787] When PduR_<SrcLo>RxIndication is called and the FIFO queue is not
			 * 						 empty then the received I-PDU shall be copied as latest entry.
			 */
			else
			{
				if(PDUR_IDLE == PduR_DestPduState[gateWayIfPduDirectStateId])
				{
					/* Send the first data in the buffer and store the later data to the buffer */
					if((boolean)TRUE == PduR_TxBuffer[bufId].PduRTxBufferRef[0].used)
					{
						/**
						 * @req [SWS_PduR_00784] When the I-PDU is transmitted from the PduR buffer
						 * 						 number of bytes which was copied to the buffer as
						 * 						 SduLength
						 */
						pduInfo.SduDataPtr = PduR_TxBuffer[bufId].PduRTxBufferRef[0].TxBufferData;
						pduInfo.SduLength = PduR_TxBuffer[bufId].PduRTxBufferRef[0].SduLength;
						/**
						 * @req [SWS_PduR_00667] When PduR_<DstLo>TxConfirmation is called and the
						 * 						 FIFO queue is not empty in case of direct data
						 * 						 provision <DstLo>_Transmit shall be called with the
						 * 						 oldest I-PDU of the FIFO. The transmitted I-PDU shall
						 * 						 be removed afterwards
						 */
						if((Std_ReturnType)E_OK == LinIf_Transmit(PduId, &pduInfo))
						{
							PduR_DestPduState[gateWayIfPduDirectStateId] = PDUR_BUSY;
						}
						else
						{
							#if(STD_ON == PDUR_DEV_ERROR_DETECT)
							PDUR_DET_ERROR_REPORT(PDUR_SID_LINIFRXINDICATION,\
									PDUR_E_PDU_INSTANCES_LOST);
							#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
						}
						PduR_ClearQueueBuffer(bufId);
						PduR_EnQueueBuffer(InfoPtr,bufId,DestModule);
					}
					/* Sending new data, even if it fails, doesn't store */
					/**
					 * @req [SWS_PduR_00665] When PduR_<SrcLo>RxIndication is called and the FIFO
					 * 						 queue is empty and no confirmation is outstanding for the
					 * 						 same PDU, <DstLo>_Transmit shall be called directly.
					 * 						 The FIFO stays empty.
					 */
					else
					{
						if((Std_ReturnType)E_OK == LinIf_Transmit(PduId, InfoPtr))
						{
							PduR_DestPduState[gateWayIfPduDirectStateId] = PDUR_BUSY;
						}
						else
						{
							#if(STD_ON == PDUR_DEV_ERROR_DETECT)
							PDUR_DET_ERROR_REPORT(PDUR_SID_LINIFRXINDICATION,\
									PDUR_E_PDU_INSTANCES_LOST);
							#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
						}
					}
				}
				/* Directly provide data, gateways busy, store data to buffers */
				else
				{
					PduR_EnQueueBuffer(InfoPtr,bufId,DestModule);
				}
			}
		}
	}
	return;
}
#endif/* STD_ON == PDUR_LINIF_SUPPORT */

/**
 * @brief			Update queue
 * @param[in]		bufId :buffer index
 * @param[in]		DestPduId :id
 * @param[in]		PduInfo :Length and pointer to the buffer of the I-PDU.
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
STATIC FUNC(void, PDUR_CODE)
PduR_EnQueueBuffer(
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)PduInfo,
	VAR(uint16, PDUR_VAR) bufId,
	VAR(uint8, PDUR_VAR) DestModule
)
{
	uint8 bufDepth;
	uint8 cnt;
	boolean usedBuf = (boolean)FALSE;
	uint32 pduMaxLength;
	/*The max buffer data length*/
	pduMaxLength = PduR_TxBuffer[bufId].PduRPduMaxLength;
	bufDepth = PduR_TxBuffer[bufId].PduRTxBufferDepth;
    /* Check buffer size whether enough to store data */
    /**
     * @req [SWS_PduR_00746] In case the I-PDU is buffered in the PDU Router module: The PDU Router
     * 						 module shall copy the data of of the I-PDU up to smallest of the following
     * 						 values
     */
    if(pduMaxLength > PduInfo->SduLength)
    {
    	pduMaxLength = PduInfo->SduLength;
    }
    /* When there is only one buffer, direct use */
    if(1u == bufDepth )
    {
    	PduR_TxBuffer[bufId].PduRTxBufferRef[0].used = (boolean)TRUE;
    	PduR_TxBuffer[bufId].PduRTxBufferRef[0].SduLength =(uint16) pduMaxLength;
    	/**
    	 * @req [SWS_PduR_00746] The PDU Router module shall copy the data of the I-PDU up to smallest
    	 */
    	PduR_Memcpy(
					PduR_TxBuffer[bufId].PduRTxBufferRef[0].TxBufferData,
					PduInfo->SduDataPtr,
					(uint16)pduMaxLength
					);
    }
    if(bufDepth > (uint16)1)
    {
    	/* One condition of entering judgment is the free time buffer */
    	
    	for (cnt =(uint8) 0; (cnt < bufDepth) && ((boolean)FALSE == usedBuf); cnt++)
		{
    		
			if((boolean)FALSE == PduR_TxBuffer[bufId].PduRTxBufferRef[cnt].used)
			{
				/**
				 * @req [SWS_PduR_00662] In case usage of a FIFO-Buffer (see PduRTxBufferDepth),
				 * 						 if the destination communication interface module is
				 * 						 requesting the I-PDU buffer using PduR_<DstLo>Trigger
				 * 						 Transmit and the FIFO is empty the return value E_NOT_OK
				 * 						 shall be used
				 */
				usedBuf = (boolean)TRUE;
				PduR_TxBuffer[bufId].PduRTxBufferRef[cnt].used = (boolean)TRUE;
				PduR_TxBuffer[bufId].PduRTxBufferRef[cnt].SduLength = (uint16)pduMaxLength;
				/**
				 * @req [SWS_PduR_00746] The PDU Router module shall copy the data of of the I-PDU
				 * 						 up to smallest
				 */
				PduR_Memcpy(
							PduR_TxBuffer[bufId].PduRTxBufferRef[cnt].TxBufferData,
							PduInfo->SduDataPtr,
							(uint16)pduMaxLength);
			}
		}
    	/* all buffer is used, the FIFO is flushed */
    	/**
    	 * @req [SWS_PduR_00819] When the I-PDU is copied (trigger transmit data provision) from the
    	 * 						 PduR buffer to the destination module the PduR shall check the lower
    	 * 						 layer's buffer size provided as SduLength. In case the buffer is too
    	 * 						 small for the stored PDU data, the PduR shall return E_NOT_OK and not
    	 * 						 process the TriggerTransmit call any further
    	 */
    	
    	if((boolean)FALSE == usedBuf)
    	{
    		/*Advanced first out principle fifo*/
    		/**
    		 * @req [SWS_PduR_00785] [SWS_PduR_00307] If PduRTxBufferDepth is configured to a value
    		 * 						 greater then 1 the Tx Pdu buffer shall have a first in C first
    		 * 						 out (FIFO) behavior
    		 */
    		/**
    		 * @req [SWS_PDUR_00809] In case of last-is best buffering,the PduRouter shall buffer
    		 * 						 the latest I-PDU in case of a trigger transmit data provision
    		 */
    		/**
    		 * @req [SWS_PduR_00746] The PDU Router module shall copy the data of of the I-PDU up
    		 * 						 to smallest
    		 */
    		PduR_Memcpy( 

						PduR_TxBuffer[bufId].PduRTxBufferRef[0].TxBufferData,
						PduInfo->SduDataPtr,
						(uint16)pduMaxLength);
		/*Reposition the release buffer*/
    		for(cnt = (uint8)1;cnt < bufDepth;cnt++)
    		{
    			PduR_TxBuffer[bufId].PduRTxBufferRef[cnt].used = (boolean)FALSE;
    		}
			#if(STD_ON == PDUR_DEV_ERROR_DETECT)
	        switch(DestModule)
	        {
				#if(STD_ON == PDUR_CANIF_SUPPORT)
				case PDUR_CANIF:
					PDUR_DET_ERROR_REPORT(PDUR_SID_CANIFRXINDICATION, PDUR_E_PDU_INSTANCES_LOST);
					break;
                #endif/* STD_ON == PDUR_CANIF_SUPPORT */
				#if(STD_ON == PDUR_LINIF_SUPPORT)
				case PDUR_LINIF:
					PDUR_DET_ERROR_REPORT(PDUR_SID_LINIFRXINDICATION, PDUR_E_PDU_INSTANCES_LOST);
					break;
				#endif/* STD_ON == PDUR_LINIF_SUPPORT */
				default:
					break;
	        }
            #endif/* STD_ON == PDUR_DEV_ERROR_DETECT */
    	}
    }
    return;
}


/**
 * @brief			Clear queue
 * @param[in]		bufId :buffer index
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
/* clear the buffer(the buffer data have transmit,Whether or not it succeeds) */
STATIC FUNC(void, PDUR_CODE)PduR_ClearQueueBuffer(
	VAR(uint16, PDUR_VAR) bufId
)
{
	uint8 bufDepth;
	uint8 num;
	bufDepth = PduR_TxBuffer[bufId].PduRTxBufferDepth;
	/**
	 * @req [SWS_PduR_00667] When PduR_<DstLo>TxConfirmation is called and the FIFO queue is not empty
	 * 						 in case of direct data provision <DstLo>_Transmit shall be called with
	 * 						 the oldest I-PDU of the FIFO. The transmitted I-PDU shall be removed
	 * 						 afterwards
	 */
	if(1u == bufDepth)
	{
		PduR_TxBuffer[bufId].PduRTxBufferRef[0].used = (boolean)FALSE;
	}
	if(bufDepth > (uint16)1)
	{
		/*Follow the fifo rule and send the oldest data to cache the new data at the end and change
		 * the last buffer state*/
		for(num = 0u;num < (bufDepth-(uint8)1);num++)
		{
			PduR_TxBuffer[bufId].PduRTxBufferRef[num] = \
					PduR_TxBuffer[bufId].PduRTxBufferRef[num+(uint8)1];
		}
		PduR_TxBuffer[bufId].PduRTxBufferRef[bufDepth-(uint8)1].used = (boolean)FALSE;
	}
	return;
}
#endif/* (STD_ON == PDUR_CANIF_SUPPORT) || (STD_ON == PDUR_LINIF_SUPPORT) */

/**
 * @brief			clear on the fly mode buffer
 * @param[in]		SrcPdu :Pdu id
 * @param[in]		CopyTpBufferNumber :copy length
 * @param[out]		/
 * @param[in/out]	/
 * @return			boolean
 * @retval			TRUE
 * 					FALSE
 */
#if(STD_ON == PDUR_TP_SUPPORT)
/* if the tp buffer which have been copyed all data by all dest Tp Pdus,need clear the tp buffer */
FUNC(boolean, PDUR_CODE)
STATIC PduR_ClearGateWayOnTheFlyTpBuffer(
	VAR(PduIdType, PDUR_VAR) SrcPdu,
	VAR(uint8, PDUR_VAR)  CopyTpBufferNumber
)
{
	boolean clearTpBuffer = (boolean)TRUE;
	uint8 destPduNum;
	uint8 cnt;
	uint16 tpRunTimeIndex;
	destPduNum = PduR_ConfigData->PduRRoutingTableRef[SrcPdu].DestPduNumber;
	/* After the on-the-fly mode is over, remove all the tp buffers for the gateway */
	
	for(cnt=(uint8)0;(cnt<destPduNum)&&((boolean)TRUE == clearTpBuffer);cnt++)
	{
		tpRunTimeIndex = PduR_ConfigData->PduRRoutingTableRef[SrcPdu].\
				PduRDestPduIdRef[cnt].GateWayTpRunTimeIndex;
		if(((boolean)FALSE == PduR_GateWayDestTpSate[tpRunTimeIndex].TpTxConfirmation) \
			&& (CopyTpBufferNumber > PduR_GateWayDestTpSate[tpRunTimeIndex].CopyCompleteTpBufferNumber))
		{
			clearTpBuffer = (boolean)FALSE;
		}
	}
	return clearTpBuffer;
}

/* find one valid tp buffer.if not find,return 0xffu */
/**
 * @req [SWS_PduR_00797] If a gatewayed TP PDU reception is indicated via PduR_<SrcLoTp>StartOfReception
 * 						 and the total SDU size reported by the parameter TpSduLength is not larger
 * 						 than the configured PduRPduMaxLength of the dedicated buffer referenced by
 * 						 PduRDestTxBufferRef, the PduR shall use the dedicated buffer.
 */
/**
 * @brief			FindValidTpBuffer
 * @param[in]		PduRSrcPduId :Pdu id
 * @param[in]		PduLength :buffer length
 * @param[out]		/
 * @param[in/out]	/
 * @return			uint8
 * @retval			buffer idnex
 */
STATIC FUNC(uint8, PDUR_CODE)
PduR_FindValidTpBuffer(
	VAR(uint16, PDUR_VAR) PduRSrcPduId,
	VAR(uint16, PDUR_VAR) PduLength
)
{

	uint8 findTpBuffer = (uint8)0xff;
	#if(PDUR_TP_BUFFER_SUM > 0u )
	uint8 tpBufferIndex;
	for(tpBufferIndex = 0u;tpBufferIndex < (uint8)PDUR_TP_BUFFER_SUM;tpBufferIndex++)
	{
		/*If the length of the incoming passes is greater than the length of the set, it causes the
		 *loss of data and should not be used*/
		/**
		 * @req [SWS_PduR_00791] When <UpTp>_StartOfReception returns BUFREQ_OK, but the available
		 * 						 buffer is too small to receive the whole message, the PduR shall
		 * 						 call <UpTp>_RxIndication with 0xffffu
		 */
		/**
		 * @req [SWS_PduR_00797] a gatewayed TP PDU reception is indicated via PduR_<SrcLoTp>
		 * 						 StartOfReception, and the total SDU size reported by the parameter
		 * 						 TpSduLength is not larger than the configured PduRPduMaxLength of
		 * 						 the dedicated buffer referenced by PduRDestTxBufferRef, the PduR
		 * 						 shall use the dedicated buffer.
		 */
		if(((boolean)FALSE == PduR_TpBuffer[tpBufferIndex].used) \
				&& (PduLength <= PduR_TpBuffer[tpBufferIndex].TpBufferLength))
		{
			if(0xffu == findTpBuffer)
			{
				findTpBuffer = tpBufferIndex;
			}
			else
			{
				/* enough large to include data,find biggest buffer So it's going to be a lot of
				 * different lengths TPBuffer */
				if(PduR_TpBuffer[findTpBuffer].TpBufferLength > \
						PduR_TpBuffer[tpBufferIndex].TpBufferLength)
				{
					findTpBuffer = tpBufferIndex;
				}
			}
		}
	}
	#endif/* PDUR_TP_BUFFER_SUM > 0 */
	/*else This is a valid tpbuffer under the gateway*/
	/* PRQA S 2995 EOF # violate MISRA_2004_Rule_13.7:ignore this warnning */
	if(((boolean)TRUE == PduR_ConfigData->PduRRoutingTableRef[PduRSrcPduId].GatewayOnTheFly)
		&& (0xffu == findTpBuffer))
	{
		#if(PDUR_TP_BUFFER_SUM > 0u)
		for(tpBufferIndex = 0u;(tpBufferIndex < (uint8)PDUR_TP_BUFFER_SUM) \
		&& (0xffu == findTpBuffer);tpBufferIndex++)
		{
			/**
			 * @req [SWS_PduR_00798] If a gatewayed TP PDU reception is indicated via PduR_<SrcLoTp>
			 * 						StartOfReception, and the total SDU size reported by the parameter
			 * 						TpSduLength is larger than the configured PduRPduMaxLength of the
			 * 						dedicated buffer, the PduR shall dynamically allocate a buffer from
			 * 						the PduRTpBufferTable.
			 */
			/* The threshold parameter is only related to the tp route, and when the direct tp routing
			 * is implemented, the pdurrouter should ensure that the allocated buffer size is at
			 * least greater than this threshold */
			if((PduR_ConfigData->PduRRoutingTableRef[PduRSrcPduId].PduRTpMaxThreshold < \
					PduR_TpBuffer[tpBufferIndex].TpBufferLength)
				&&((boolean)FALSE == PduR_TpBuffer[tpBufferIndex].used))
			{
				findTpBuffer = tpBufferIndex;
			}
		}
		#endif/* PDUR_TP_BUFFER_SUM > 0 */
	}
	return findTpBuffer;
}

/**
 * @brief			FindTpBuffer
 * @param[in]		PduRSrcPduId :Pdu id
 * @param[out]		/
 * @param[in/out]	/
 * @return			uint8
 * @retval			buffer idnex
 */
/* find the rx tp pdu active store tp buffer */
STATIC FUNC(uint8, PDUR_CODE)
PduR_FindTpBuffer(
	VAR(uint16, PDUR_VAR) PduRSrcPduId
)
{
	uint8 tpBufferId = (uint8)0xff;
	#if(PDUR_TP_BUFFER_SUM > 0u)
	uint8 num;
	for(num = 0u;num < (uint8)PDUR_TP_BUFFER_SUM;num++)
	{
		if(((boolean)TRUE == PduR_TpBuffer[num].used) && (PduRSrcPduId == \
				PduR_TpBuffer[num].PduHandleId))
		{
			/* The initial nexttpbufferid is 0xffu, which indicates that the tpbuffererers are not used
			 * for the gateway, and the tpbuffer will be used for the back value */
			if(0xffu == PduR_TpBuffer[num].NextTpBufferId)
			{
				tpBufferId = num;
			}
		}
	}
	#endif/* PDUR_TP_BUFFER_SUM > 0 */
	return tpBufferId;
}


/**
 * @brief			find one unused tp buffer.if no unused tp buffer,return 0xffu
 * @param[in]		/
 * @param[out]		/
 * @param[in/out]	/
 * @return			uint8
 * @retval			buffer idnex
 */
FUNC(uint8, PDUR_CODE)
STATIC PduR_NextValidTpBuffer(
	void
)
{

	uint8 vaildTpBuffer = (uint8)0xff;
	#if(PDUR_TP_BUFFER_SUM > 0u)
	uint8 tpBufferIndex;
	/* When the last buffer fills up, look for a buffer that can be used */
	for(tpBufferIndex = 0u;tpBufferIndex < (uint8)PDUR_TP_BUFFER_SUM;tpBufferIndex++)
	{
		if((boolean)FALSE == PduR_TpBuffer[tpBufferIndex].used)
		{
			vaildTpBuffer = tpBufferIndex;
		}
	}
	#endif/* PDUR_TP_BUFFER_SUM > 0 */
	return vaildTpBuffer;
}


/**
 * @brief			gateway SF pdu to Tp mode by LoTp_Transmit
 * @param[in]		PduRSrcPduId : Source Pdu Id
 * @param[in]		PduRDestPduId : Dest Pdu Id
 * @param[out]		/
 * @param[in/out]	/
 * @return			uint8
 * @retval			buffer idnex
 */
FUNC(Std_ReturnType, PDUR_CODE)
STATIC PduR_GateWaySFToTp(
	VAR(uint16, PDUR_VAR) PduRSrcPduId,
	VAR(uint16, PDUR_VAR) PduRDestPduId
)
{
	Std_ReturnType loTpTxRet = (Std_ReturnType)0;
	PduIdType gatewayTpIndex;
	uint16 txBufferId;
	PduInfoType pduRInfo;
	uint8 destPduNum;
	uint8 index;
	destPduNum = PduR_ConfigData->PduRRoutingTableRef[PduRSrcPduId].DestPduNumber;
	for(index = 0u;index < destPduNum; index++)
	{
		if(PduR_ConfigData->PduRRoutingTableRef[PduRSrcPduId].PduRDestPduIdRef[index].DestPduId == \
				PduRDestPduId)
		{
			txBufferId = PduR_ConfigData->PduRRoutingTableRef[PduRSrcPduId].\
					PduRDestPduIdRef[index].PduRDestTxBufferRef;
			gatewayTpIndex = PduR_ConfigData->PduRRoutingTableRef[PduRSrcPduId].\
					PduRDestPduIdRef[index].GateWayTpRunTimeIndex;
			/* Find the corresponding tp state according to the runtime id */
			
			if((boolean)FALSE == PduR_GateWayDestTpSate[gatewayTpIndex].TpTxConfirmation)
			{
				pduRInfo.SduLength = PduR_TxBuffer[txBufferId].PduRTxBufferRef[0].SduLength;
				#if(STD_ON == PDUR_META_DATA_SUPPORT)
				if(PduR_ConfigData->PduRSrcPduRef[PduRSrcPduId].MetaDataLength > 0u)
				{
					pduRInfo.SduDataPtr = PduR_TxBuffer[txBufferId].MetaData;
				}
				else
				{
					pduRInfo.SduDataPtr = NULL_PTR;
				}
				#else
				pduRInfo.SduDataPtr = NULL_PTR;
				#endif/* STD_ON == PDUR_META_DATA_SUPPORT */
				/* Send data using the tp single frame gateway */
				if(PduRLo_Transmit[PduR_ConfigData->PduRRoutingTableRef[PduRSrcPduId].\
								   PduRDestPduIdRef[index].DestModuleType] != NULL_PTR)
				{
					PduRLo_Transmit[PduR_ConfigData->PduRRoutingTableRef[PduRSrcPduId].\
									PduRDestPduIdRef[index].DestModuleType](PduRDestPduId,&pduRInfo);
				}
			}
		}
	}
	return loTpTxRet;
}

/**
 * @brief			copy the rx pdu data to the tp buffer
 * @param[in]		TpBufferId : buffer index
 * @param[in]		Info : Length and pointer to the buffer of the I-PDU.
 * @param[in]		BufferSizePtr : The size of the upper available space that needs to be confirmed
 * @param[out]		/
 * @param[in/out]	/
 * @return			BufReq_ReturnType
 * @retval			BUFREQ_OK
 * 					BUFREQ_E_NOT_OK
 * 					BUFREQ_E_BUSY
 * 					BUFREQ_E_OVFL
 */
FUNC(BufReq_ReturnType, PDUR_CODE)
STATIC PduR_CopyRxDataToTpBuffer(
	VAR(uint8, PDUR_VAR) TpBufferId,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) Info,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) BufferSizePtr
)
{
	BufReq_ReturnType bufQeqRet;
	/*You can use the rxbufferoffset as an offset*/
	uint16 rxBufferOffset;
	uint8 validTpBufferId;
	uint16 tpBufferStoreLength;
	/* The bufferoffset is a sign that the data is received in the tpbuffer, and a tpbuffer may actually
	 *be a great way to receive a lot of data */
 	rxBufferOffset = PduR_TpBuffer[TpBufferId].RxBufferOffset;
	if((rxBufferOffset + Info->SduLength) < PduR_TpBuffer[TpBufferId].TpBufferLength)
	{
		PduR_Memcpy(
					&PduR_TpBuffer[TpBufferId].TpBufferData[rxBufferOffset],
					Info->SduDataPtr,
					(uint16)Info->SduLength);
		PduR_TpBuffer[TpBufferId].RxBufferOffset += (uint16)Info->SduLength;
		/* The buffer size of the configuration minus the buffersizeused, shows the capacity of
		 *the remaining tpbuffer */
		*BufferSizePtr = (PduLengthType)PduR_TpBuffer[TpBufferId].TpBufferLength - (PduLengthType)PduR_TpBuffer[TpBufferId].\
				RxBufferOffset;
		bufQeqRet = BUFREQ_OK;
	}
	/* need another tp buffer to store the pdu(used for gateway-on-the-fly) */
	else if((rxBufferOffset + Info->SduLength) == PduR_TpBuffer[TpBufferId].TpBufferLength)
	{
		PduR_Memcpy(
					&PduR_TpBuffer[TpBufferId].TpBufferData[rxBufferOffset],
					Info->SduDataPtr,
					(uint16)Info->SduLength);
		PduR_TpBuffer[TpBufferId].RxBufferOffset = PduR_TpBuffer[TpBufferId].TpBufferLength;
		/* find unuse Tp buffer,Buffer the unbuffed data into the next buffer */
		validTpBufferId = PduR_NextValidTpBuffer();
		
		if(0xffu != validTpBufferId)
		{
			PduR_TpBuffer[TpBufferId].NextTpBufferId = validTpBufferId;
			PduR_TpBuffer[validTpBufferId].PduHandleId = PduR_TpBuffer[TpBufferId].PduHandleId;
			PduR_TpBuffer[validTpBufferId].RxBufferOffset = (uint16)0;
			PduR_TpBuffer[validTpBufferId].SduLength = PduR_TpBuffer[TpBufferId].SduLength;
			PduR_TpBuffer[validTpBufferId].used = (boolean)TRUE;
			*BufferSizePtr = PduR_TpBuffer[validTpBufferId].TpBufferLength;
		}
		else
		{
			*BufferSizePtr =(PduLengthType)0;
		}
		bufQeqRet = BUFREQ_OK;
	}
	/* need another tp buffer to store the pdu(used for gateway-on-the-fly) */
	else
	{
		/*find unuse tp buffer*/
		validTpBufferId = PduR_NextValidTpBuffer();
		/* PRQA S 2996 # violate MISRA_2004_Rule_13.7:The result of this logical operation can be
		 * (boolean)false */
		
		if(0xffu != validTpBufferId)
		{
			/* The tpbuffer configured is not enough to use the length of the original tpbuffer minus
			 *the receiving stop flag representation and the data length that can be cached, and the
			 *the remaining data is not cached in the tpbuffer */
			tpBufferStoreLength =(uint16) Info->SduLength - (PduR_TpBuffer[TpBufferId].\
					TpBufferLength - rxBufferOffset);
			PduR_Memcpy(
						&PduR_TpBuffer[TpBufferId].TpBufferData[rxBufferOffset],
						Info->SduDataPtr,
						(uint16)Info->SduLength - tpBufferStoreLength);
			PduR_TpBuffer[TpBufferId].RxBufferOffset = PduR_TpBuffer[TpBufferId].TpBufferLength;
			/* Using the nexttpbufferid to associate a tpbuffererand to find the subscript of the
			 *tpbuffer that you can use to connect to the previous one */
			PduR_TpBuffer[TpBufferId].NextTpBufferId = validTpBufferId;
			/*Because it's a new tpbufferer, so the offset is 0*/
			PduR_Memcpy(
						&PduR_TpBuffer[validTpBufferId].TpBufferData[0],
						&Info->SduDataPtr[Info->SduLength - tpBufferStoreLength],
						tpBufferStoreLength);
			PduR_TpBuffer[validTpBufferId].RxBufferOffset = tpBufferStoreLength;
			PduR_TpBuffer[validTpBufferId].PduHandleId = PduR_TpBuffer[TpBufferId].PduHandleId;
			PduR_TpBuffer[validTpBufferId].SduLength = PduR_TpBuffer[TpBufferId].SduLength;
			PduR_TpBuffer[validTpBufferId].used = (boolean)TRUE;
			/*The amount of buffer in the buffer is cached*/
			*BufferSizePtr = (PduLengthType)PduR_TpBuffer[validTpBufferId].TpBufferLength - tpBufferStoreLength;
			bufQeqRet = BUFREQ_OK;
		}
		else
		{
			bufQeqRet = BUFREQ_E_NOT_OK;
		}
	}
	return bufQeqRet;
}

/**
 * @brief			gateway SF pdu to up mode
 * @param[in]		PduRSrcPduId : Source Pdu Id
 * @param[in]		DestModule : Pdu module
 * @param[in]		PduRDestPduId : Dest Pdu Id
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void, PDUR_CODE)
STATIC PduR_RouteSFtoUp(
	VAR(uint8, PDUR_VAR) DestModule,
	VAR(uint16, PDUR_VAR) PduRSrcPduId,
	VAR(uint16, PDUR_VAR) PduRDestPduId
)
{
	BufReq_ReturnType upModuleRet;
	PduIdType upPduId;
	PduIdType gatewayTpIndex;
	uint16 txBufferId;
	PduLengthType bufferLength = (PduLengthType)0u;
	PduLengthType tpSduLength;
	PduInfoType pduRInfo;
	uint8 destPduNum;
	uint8 index;
	uint8 destModuleType;
	upPduId = PduR_ConfigData->PduRDestPduRef[PduRDestPduId].ActualPduId;
	destPduNum = PduR_ConfigData->PduRRoutingTableRef[PduRSrcPduId].DestPduNumber;
	for(index = 0u; index < destPduNum; index++)
	{
		if(PduRDestPduId == PduR_ConfigData->PduRRoutingTableRef[PduRSrcPduId].\
				PduRDestPduIdRef[index].DestPduId)
		{
			txBufferId = PduR_ConfigData->PduRRoutingTableRef[PduRSrcPduId].\
					PduRDestPduIdRef[index].PduRDestTxBufferRef;
			gatewayTpIndex = PduR_ConfigData->PduRRoutingTableRef[PduRSrcPduId].\
					PduRDestPduIdRef[index].GateWayTpRunTimeIndex;
			#if(STD_ON == PDUR_META_DATA_SUPPORT)
			if(PduR_ConfigData->PduRSrcPduRef[PduRSrcPduId].MetaDataLength > 0u)
			{
				pduRInfo.SduDataPtr = PduR_TxBuffer[txBufferId].MetaData;
				pduRInfo.SduLength = PduR_ConfigData->PduRSrcPduRef[PduRSrcPduId].MetaDataLength;
			}
			else
			{
				pduRInfo.SduDataPtr = NULL_PTR;
				pduRInfo.SduLength = 0u;
			}
			#else
			pduRInfo.SduDataPtr = NULL_PTR;
			pduRInfo.SduLength =(PduLengthType) 0u;
			#endif/* STD_ON == PDUR_META_DATA_SUPPORT */
			/* The upward layer module sends all the quantities that will be routed */
			tpSduLength = PduR_TxBuffer[txBufferId].PduRTxBufferRef[0].SduLength;
			destModuleType = PduR_ConfigData->PduRRoutingTableRef[PduRSrcPduId].\
					PduRDestPduIdRef[index].DestModuleType;
			if(PduRUp_TpStartOfReception[destModuleType] != NULL_PTR)
			{
				upModuleRet = (BufReq_ReturnType)PduRUp_TpStartOfReception[destModuleType]\
						(upPduId,&pduRInfo,tpSduLength,&bufferLength);
				if((BUFREQ_OK == upModuleRet) && (bufferLength >= tpSduLength))
				{
					pduRInfo.SduDataPtr = PduR_TxBuffer[txBufferId].PduRTxBufferRef[0].TxBufferData;
					pduRInfo.SduLength = tpSduLength;
					if(PduRUp_TpCopyRxData[destModuleType] != NULL_PTR)
					{
						upModuleRet = (BufReq_ReturnType)PduRUp_TpCopyRxData[destModuleType]\
								(upPduId,&pduRInfo,&bufferLength);
						/* When the received data is buffered in the buffer, a buffer completion
						 * sign is returned */
						if(BUFREQ_OK == upModuleRet)
						{
							if(PduRUp_TpRxIndication[destModuleType] != NULL_PTR)
							{
								PduRUp_TpRxIndication[destModuleType](upPduId,(Std_ReturnType)E_OK);
							}
							else
							{
								PduRUp_TpRxIndication[destModuleType](upPduId,(Std_ReturnType)E_NOT_OK);
							}
						}
					}
				}
				PduR_GateWayDestTpSate[gatewayTpIndex].TpTxConfirmation = (boolean)TRUE;
			}
		}
	}
	return ;
}

#endif/* STD_ON == PDUR_TP_SUPPORT */

#if(STD_ON == PDUR_TP_SUPPORT)

/**
 * @brief			Rx Tp Pdu gateway to only one Tp Module Pdu handle,when start of reception
 * @param[in]		SrcPduId : Source Pdu Id
 * @param[in]		info : Length and pointer to the buffer of the I-PDU.
 * @param[in]		DestPduId : Dest Pdu Id
 * @param[in]		bufferSizePtr :The size of the upper available space that needs to be confirmed
 * @param[out]		/
 * @param[in/out]	/
 * @return			BufReq_ReturnType
 * @retval			BUFREQ_OK
 * 					BUFREQ_E_NOT_OK
 * 					BUFREQ_E_BUSY
 * 					BUFREQ_E_OVFL
 */
STATIC FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_StartOfReceptionToOneTpHandle(
	VAR(PduIdType, PDUR_VAR) SrcPduId,
	VAR(PduIdType, PDUR_VAR) DestPduId,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	VAR(PduLengthType, PDUR_VAR) Length,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
	uint8 destPduNum, index;
	BufReq_ReturnType bufQeqRet = BUFREQ_E_NOT_OK;
	uint8 tpBufferIndex;
	uint16 pduRDestTxBuffeIndex;
	PduIdType tpRunTimeIndex;
	/**
	 * @req [SWS_PduR_00794] The MetaData of I-PDUs provided by PduR_<SrcLoTp>StartOfReception shall
	 * 						 be stored and provided with the I-PDU to <DstLoTp>_Transmit
	 */
	#if(STD_ON == PDUR_META_DATA_SUPPORT)
	uint8 metaDataLength;
	metaDataLength = PduR_ConfigData->PduRSrcPduRef[SrcPduId].MetaDataLength;
	#endif
	destPduNum = PduR_ConfigData->PduRRoutingTableRef[SrcPduId].DestPduNumber;
	for(index = 0u; index < destPduNum; index++)
	{
		if(PduR_ConfigData->PduRRoutingTableRef[SrcPduId].PduRDestPduIdRef[index].DestPduId == \
				DestPduId)
		{
			tpRunTimeIndex = PduR_ConfigData->PduRRoutingTableRef[SrcPduId].\
					PduRDestPduIdRef[index].GateWayTpRunTimeIndex;
			/* MF tp pdu gateway,need store in tp buffer */
			/* In case of the transport protocol module the PDU Router module is first notified with
			 * a start of reception notification when receiving  first frame (FF) or single frame */
			/* The first frame sends contains the packet length so that the packet is fully processed,
			 * the packet type is the request data or the response data, the sender's address so that
			 * the data comes from which ecucucor, the receiver address, so that the data is properly
			 * routed to the receiver and so on */
			
			if((boolean)FALSE == PduR_ConfigData->PduRRoutingTableRef[SrcPduId].TpPduIsSF)
			{
				/* find one valid tp buffer.if not find,return 0xffu Find the lower mark for the
				 * buffer you can use */
				tpBufferIndex = PduR_FindValidTpBuffer((uint16)SrcPduId,(uint16)Length);
				/* PRQA S 2996 # violate MISRA_2004_Rule_13.7:The result of this logical operation can
				 *  be (boolean)false */
				if((uint8)0xff != tpBufferIndex)
				{
					PduR_TpBuffer[tpBufferIndex].used = (boolean)TRUE;
					PduR_TpBuffer[tpBufferIndex].RxBufferOffset = (uint16)0;
					PduR_TpBuffer[tpBufferIndex].SduLength =(uint16) Length;
					PduR_TpBuffer[tpBufferIndex].PduHandleId = SrcPduId;
					/**
					 * @req [SWS_PduR_00794] The MetaData of I-PDUs provided by PduR_<SrcLoTp>StartOf
					 * 						 Reception shall be stored and provided with the I-PDU to
					 * 						 <DstLoTp>_Transmit
					 */
					#if(STD_ON == PDUR_META_DATA_SUPPORT)
					PduR_Memcpy(
								PduR_TpBuffer[tpBufferIndex].MetaData,
								info->SduDataPtr,
								metaDataLength);
					#endif/* STD_ON == PDUR_META_DATA_SUPPORT */
					PduR_GateWayDestTpSate[tpRunTimeIndex].ActiveTpBufferId = tpBufferIndex;
					PduR_GateWayDestTpSate[tpRunTimeIndex].TpTxConfirmation = (boolean)FALSE;
					PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset = (uint16)0;
					/* gateway-on-the-fly */
				
					if((boolean)TRUE == PduR_ConfigData->PduRRoutingTableRef[SrcPduId].GatewayOnTheFly)
					{
						/**
						 * @req [SWS_PduR_00708] Using gatewaying on-the-fly only one destination
						 * 						 transport protocol module is allowed
						 */
						/* The runtime id is the only idl that represents the tp packet sender and
						 * receiver, which contains the network address of the sender, the network
						 * address of the ecuc id receiver of the sender, and the ecuc id of the
						 * receiver */
						PduR_GateWayDestTpSate[tpRunTimeIndex].IsGateWayOnTheFly = (boolean)TRUE;
						PduR_GateWayDestTpSate[tpRunTimeIndex].CopyCompleteTpBufferNumber = (uint8)0;
						/**
						 * @req [SWS_PduR_00811] If a TP transmission is started via PduR_<SrcLo>
						 * 						 StartOfReception, the PDU Router module shall
						 * 						 directly call <DstLoTp>_Transmit if PduRTpThreshold
						 * 						 = 0.
						 */
						
						if(0u == PduR_ConfigData->PduRRoutingTableRef[SrcPduId].\
								PduRDestPduIdRef[index].PduRTpThreshold)
						{
							/* gateway MF pdu to Tp mode by LoTp_Transmit */
							
							if((Std_ReturnType)E_NOT_OK == PduR_GateWayMFToTp(SrcPduId, DestPduId))
							{
								PduR_ClearGateWayTpBufferAndState(SrcPduId);
								bufQeqRet = BUFREQ_E_NOT_OK;
							}
							else
							{
								/* The data length will be buffered into a specified buffer */
								bufQeqRet = BUFREQ_OK;
								*bufferSizePtr = PduR_TpBuffer[tpBufferIndex].TpBufferLength;
							}
							PduR_GateWayDestTpSate[tpRunTimeIndex].IsGateWayOnTheFly = (boolean)FALSE;
						}
						else
						{
							/* The data length will be buffered into a specified buffer */
							bufQeqRet = BUFREQ_OK;
							*bufferSizePtr = PduR_TpBuffer[tpBufferIndex].TpBufferLength;
						}
					}
					else
					{
						/* The data length will be buffered into a specified buffer */
						bufQeqRet = BUFREQ_OK;
						*bufferSizePtr = PduR_TpBuffer[tpBufferIndex].TpBufferLength;
					}
				}
				else
				{
					/* BUFREQ_E_OVFL No Buffer of the required length can be provided */
					/**
					 * @req [SWS_PduR_00799] no buffer could be allocated during a call of PduR_
					 * 						 <SrcLoTp>StartOfReception for the reception of a
					 * 						 gatewayed TP PDU, the PduR shall immediately stop
					 * 						 further processing of this I-PDU and return BUFREQ_E_OVFL
					 */
					bufQeqRet = BUFREQ_E_OVFL;
				}
			}
			/* SF tp pdu gateway,need store in dedicated buffer */
			/* The pdu of the first frame tp gateway needs to be stored in a dedicated buffer, which is
			 * to configure the tx buffer as a special buffer when configuring the tp gateway */
			else
			{
				pduRDestTxBuffeIndex = PduR_ConfigData->PduRRoutingTableRef[SrcPduId].\
						PduRDestPduIdRef[index].PduRDestTxBufferRef;
				PduR_TxBuffer[pduRDestTxBuffeIndex].PduRTxBufferRef[0].SduLength = (uint16)Length;
				#if(STD_ON == PDUR_META_DATA_SUPPORT)
				PduR_Memcpy(
							PduR_TxBuffer[pduRDestTxBuffeIndex].MetaData,
							info->SduDataPtr,
							metaDataLength);
				#endif/* STD_ON == PDUR_META_DATA_SUPPORT */
				PduR_GateWayDestTpSate[tpRunTimeIndex].TpTxConfirmation = (boolean)FALSE;
				PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset = (uint16)0;
				*bufferSizePtr = PduR_TxBuffer[pduRDestTxBuffeIndex].PduRPduMaxLength;
				bufQeqRet = BUFREQ_OK;
			}
		}
	}

	return bufQeqRet;
}

/**
 * @brief			gateway MF pdu to Tp mode by LoTp_Transmit
 * @param[in]		SrcPduId : Source Pdu Id
 * @param[in]		DestPduId : Dest Pdu Id
 * @param[out]		/
 * @param[in/out]	/
 * @return			boolean
 * @retval			TRUE
 * 					FALSE
 */
STATIC FUNC(boolean, PDUR_CODE)
PduR_GateWayMFToTp(
	VAR(uint16, PDUR_VAR) PduRSrcPduId,
	VAR(uint16, PDUR_VAR) PduRDestPduId
)
{
	/**
	 * @req [SWS_PduR_00634] When an upper layer module calls the PduR_<Up>Transmit the PDU Router
	 * 						 module shall call <LoTp>_Transmit for each destination transport protocol
	 * 						 module
	 */
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
	PduIdType tpRunTimeIndex;
	uint8 tpBufferIndex;
	PduInfoType pduRInfo;
	uint8 destPduNum;
	uint8 index;
	uint8 destModuleType;
	destPduNum = PduR_ConfigData->PduRRoutingTableRef[PduRSrcPduId].DestPduNumber;
	/**
	 * @req [SWS_PduR_00803] In case of gatewaying between TPs, when one destination fails (Transmit
	 * 						 returns (Std_ReturnType)E_NOT_OK or TpTxConfirmation is called
	 * 						  with an error), the other
	 * 						 destinations shall continue
	 */
	for(index = 0u; index < destPduNum; index++)
	{
		if(PduR_ConfigData->PduRRoutingTableRef[PduRSrcPduId].PduRDestPduIdRef[index].DestPduId == \
				PduRDestPduId)
		{
			tpRunTimeIndex = PduR_ConfigData->PduRRoutingTableRef[PduRSrcPduId].\
					PduRDestPduIdRef[index].GateWayTpRunTimeIndex;
			tpBufferIndex = PduR_GateWayDestTpSate[tpRunTimeIndex].ActiveTpBufferId;
			
			if((boolean)FALSE == PduR_GateWayDestTpSate[tpRunTimeIndex].TpTxConfirmation)
			{
				pduRInfo.SduLength = PduR_TpBuffer[tpBufferIndex].SduLength;
				/* Metadata is used to describe data properties and properties, and information about
				 * the type, length, time, time, and effectiveness of the metadata packet contain data
				 *  to help accept the correct parsing and use of data */
				#if(STD_ON == PDUR_META_DATA_SUPPORT)
				if(PduR_ConfigData->PduRSrcPduRef[PduRSrcPduId].MetaDataLength > 0u)
				{
					pduRInfo.SduDataPtr = PduR_TpBuffer[tpBufferIndex].MetaData;
				}
				else
				{
					pduRInfo.SduDataPtr = NULL_PTR;
				}
				#else
				pduRInfo.SduDataPtr = NULL_PTR;
				#endif/* STD_ON == PDUR_META_DATA_SUPPORT */
				destModuleType = PduR_ConfigData->PduRRoutingTableRef[PduRSrcPduId].\
						PduRDestPduIdRef[index].DestModuleType;
				/**
				 * @req [SWS_PDUR_00808] The PDU Router module shall start the TP transmission on the
				 * 						 destination bus by calling <DstLoTp>_Transmit if result value
				 * 						 is E_OK in the PduR_
				 * <SrcLoTp>RxIndication even if the TP threshold was not reached.
				 */
				if(PduRLo_Transmit[destModuleType] != NULL_PTR)
				{
					ret = PduRLo_Transmit[destModuleType](PduRDestPduId,&pduRInfo);
				}
			}
		}
	}
	return ret;
}

/**
 * @brief			gateway MF pdu to Tp mode by LoTp_Transmit
 * @param[in]		SrcPduId : Source Pdu Id
 * @param[in]		DestPduId : Dest Pdu Id
 * @param[in]		DestModule : Pdu Module
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
FUNC(void, PDUR_CODE)
STATIC PduR_RouteMFtoUp(
	VAR(uint8, PDUR_VAR) DestModule,
	VAR(uint16, PDUR_VAR) PduRSrcPduId,
	VAR(uint16, PDUR_VAR) PduRDestPduId
)
{
	BufReq_ReturnType ret;
	PduIdType destPduId;
	PduIdType tpRunTimeIndex;
	uint16 tpBufferId;
	PduLengthType bufferLength = (PduLengthType)0u;
	PduLengthType tpSduLength;
	PduInfoType pduRInfo;
	uint16 bufferStartIndex;
	uint8 destPduNum, index, destModuleType;
	destPduNum = PduR_ConfigData->PduRRoutingTableRef[PduRSrcPduId].DestPduNumber;
	for(index = 0u; index < destPduNum; index++)
	{
		if(PduR_ConfigData->PduRRoutingTableRef[PduRSrcPduId].PduRDestPduIdRef[index].DestPduId == \
				PduRDestPduId)
		{
			tpRunTimeIndex = PduR_ConfigData->PduRRoutingTableRef[PduRSrcPduId].\
					PduRDestPduIdRef[index].GateWayTpRunTimeIndex;
			destPduId = PduR_ConfigData->PduRRoutingTableRef[PduRSrcPduId].\
					PduRDestPduIdRef[index].DestPduId;
			tpBufferId = PduR_GateWayDestTpSate[tpRunTimeIndex].ActiveTpBufferId;
			#if(STD_ON == PDUR_META_DATA_SUPPORT)
			if(PduR_ConfigData->PduRSrcPduRef[PduRSrcPduId].MetaDataLength > 0)
			{
				pduRInfo.SduDataPtr = PduR_TpBuffer[tpBufferId].MetaData;
				pduRInfo.SduLength = PduR_ConfigData->PduRSrcPduRef[PduRSrcPduId].MetaDataLength;
			}
			else
			{
				pduRInfo.SduDataPtr = NULL_PTR;
				pduRInfo.SduLength = 0u;
			}
			#else
			pduRInfo.SduDataPtr = NULL_PTR;
			pduRInfo.SduLength = (PduLengthType)0;
			#endif/* STD_ON == PDUR_META_DATA_SUPPORT */
			tpSduLength = PduR_TpBuffer[tpBufferId].SduLength;
			destModuleType = PduR_ConfigData->PduRRoutingTableRef[PduRSrcPduId].\
					PduRDestPduIdRef[index].DestModuleType;
			if(PduRUp_TpStartOfReception[destModuleType] != NULL_PTR)
			{
				ret = (BufReq_ReturnType)PduRUp_TpStartOfReception[destModuleType]\
						(destPduId, &pduRInfo, tpSduLength, &bufferLength);
				bufferStartIndex = (uint16)0;
				if((BUFREQ_OK != ret) || (bufferLength == (PduLengthType) 0u))
				{
					PduR_GateWayDestTpSate[tpRunTimeIndex].TpTxConfirmation = (boolean)TRUE;
				}
				
				while((boolean)FALSE == PduR_GateWayDestTpSate[tpRunTimeIndex].TpTxConfirmation)
				{
					pduRInfo.SduDataPtr = &(PduR_TpBuffer[tpBufferId].TpBufferData[bufferStartIndex]);
					/* Store data with minimal data length */
					if(bufferLength > (tpSduLength - bufferStartIndex))
					{
						pduRInfo.SduLength = tpSduLength - bufferStartIndex;
					}
					else
					{
						pduRInfo.SduLength = bufferLength;
					}
					/* The data that will be routed to the routing data is copied into the buffer */
					if(PduRUp_TpCopyRxData[destModuleType] != NULL_PTR)
					{
						ret = (BufReq_ReturnType)PduRUp_TpCopyRxData[destModuleType]\
								(destPduId, &pduRInfo, &bufferLength);
					}
					if((BUFREQ_OK == ret) && (bufferLength != (PduLengthType)0u))
					{
						bufferStartIndex += (uint16)pduRInfo.SduLength;
						if(bufferStartIndex	 == tpSduLength)
						{
							if(PduRUp_TpRxIndication[destModuleType] != NULL_PTR)
							{
								PduRUp_TpRxIndication[destModuleType](destPduId,(Std_ReturnType)E_OK);
								PduR_GateWayDestTpSate[tpRunTimeIndex].TpTxConfirmation = (boolean)TRUE;
							}
						}
					}
					else
					{
						if(PduRUp_TpRxIndication[destModuleType] != NULL_PTR)
						{
							PduRUp_TpRxIndication[destModuleType](destPduId,(Std_ReturnType)E_NOT_OK);
							PduR_GateWayDestTpSate[tpRunTimeIndex].TpTxConfirmation = (boolean)TRUE;
						}
					}
				}
			}

		}
	}
}

/**
 * @req [SWS_PduR_00790] When an error is returned by <UpTp>_StartOfReception for a multicast TP
 * 						 gatewaying with configured local destination, the PduR shall stop the
 * 						 upper layer reception without further interaction with the upper layer
 */
/**
 * @brief			More Module Start Of Reception
 * @param[in]		SrcPduId : Source Pdu Id
 * @param[in]		DestPduNum : number of Pdu
 * @param[in]		info : Length and pointer to the buffer of the I-PDU.
 * @param[in]		Length
 * @param[in]		bufferSizePtr : The size of the upper available space that needs to be confirmed
 * @param[out]		/
 * @param[in/out]	/
 * @return			BufReq_ReturnType
 * @retval			BUFREQ_OK
 * 					BUFREQ_E_NOT_OK
 * 					BUFREQ_E_BUSY
 * 					BUFREQ_E_OVFL
 */
STATIC FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_StartOfReceptionToMoreModuleHandle(
	VAR(PduIdType, PDUR_VAR) SrcPduId,
	VAR(uint8, PDUR_VAR) DestPduNum,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	VAR(PduLengthType, PDUR_VAR) Length,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
	BufReq_ReturnType bufQeqRet;
	PduIdType tpRunTimeIndex;
	PduIdType pduRDestPduId;
	uint8 tpBufferIndex;
	uint16 pduRDestTxBuffeIndex;
	uint16 cnt;
	/* PRQA S 2983 EOF # violate MISRA_2004_Rule_21.1:ignore this warnning */
	boolean isCheckTxConfirm = (boolean)FALSE;

	/* MF tp pdu gateway,need store in tp buffer */
	
	if((boolean)FALSE == PduR_ConfigData->PduRRoutingTableRef[SrcPduId].TpPduIsSF)
	{
		/* find one valid tp buffer.if not find,return 0xffu, find the large buffer to stroe data */
		tpBufferIndex = PduR_FindValidTpBuffer((uint16)SrcPduId,(uint16) Length);
		/* find the valid tp buffer */
		/* PRQA S 2996 # violate MISRA_2004_Rule_13.7:The result of this logical operation can be
		 * (boolean)false */
		
		if(0xffu != tpBufferIndex)
		{
			/*set the tp buffer runtime state*/
			PduR_TpBuffer[tpBufferIndex].used = (boolean)TRUE;
			PduR_TpBuffer[tpBufferIndex].RxBufferOffset = (uint16)0;
			PduR_TpBuffer[tpBufferIndex].SduLength =(uint16) Length;
			PduR_TpBuffer[tpBufferIndex].PduHandleId = SrcPduId;
			#if(STD_ON == PDUR_META_DATA_SUPPORT)
			PduR_Memcpy(
						PduR_TpBuffer[tpBufferIndex].MetaData,
						info->SduDataPtr,
						PduR_ConfigData->PduRSrcPduRef[SrcPduId].MetaDataLength);
			#endif
			/* gateway-on-the-fly */
			
			if((boolean)TRUE == PduR_ConfigData->PduRRoutingTableRef[SrcPduId].GatewayOnTheFly)
			{
				for (cnt =(uint16) 0; cnt < (uint16)DestPduNum; cnt++)
				{
					pduRDestPduId = PduR_ConfigData->PduRRoutingTableRef[SrcPduId].\
							PduRDestPduIdRef[cnt].DestPduId;
				
					if((boolean)TRUE == PathIsEnabled[SrcPduId])
					{
						tpRunTimeIndex = PduR_ConfigData->PduRRoutingTableRef[SrcPduId].\
								PduRDestPduIdRef[cnt].GateWayTpRunTimeIndex;
						PduR_GateWayDestTpSate[tpRunTimeIndex].IsGateWayOnTheFly = (boolean)TRUE;
						PduR_GateWayDestTpSate[tpRunTimeIndex].ActiveTpBufferId = tpBufferIndex;
						PduR_GateWayDestTpSate[tpRunTimeIndex].CopyCompleteTpBufferNumber =(uint8) 0;
						PduR_GateWayDestTpSate[tpRunTimeIndex].TpTxConfirmation = (boolean)FALSE;
						PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset = (uint16)0;
						
						if(0u == PduR_ConfigData->PduRRoutingTableRef[SrcPduId].\
								PduRDestPduIdRef[cnt].PduRTpThreshold)
						{
							/* gateway MF pdu to Tp mode by LoTp_Transmit */
							
							if((Std_ReturnType)E_NOT_OK == PduR_GateWayMFToTp(SrcPduId, pduRDestPduId))
							{
								isCheckTxConfirm = (boolean)TRUE;
								PduR_GateWayDestTpSate[tpRunTimeIndex].ActiveTpBufferId = (uint8)0xff;
								PduR_GateWayDestTpSate[tpRunTimeIndex].TpTxConfirmation = (boolean)TRUE;
							}
							PduR_GateWayDestTpSate[tpRunTimeIndex].IsGateWayOnTheFly = (boolean)FALSE;
						}
					}
				}
				
				if((boolean)TRUE == isCheckTxConfirm)
				{
					/* At least one purpose module is not a confirmation state interface judgment */
				
					if((boolean)TRUE == PduR_AtLeastOneDestIsNotTxConfirm(SrcPduId))
					{
						bufQeqRet = (BufReq_ReturnType)BUFREQ_OK;
						*bufferSizePtr = PduR_TpBuffer[tpBufferIndex].TpBufferLength;
					}
					else
					{
						bufQeqRet = (BufReq_ReturnType)BUFREQ_E_NOT_OK;
						/* clear the tp buffer runtime state */
						PduR_ClearGateWayTpBufferAndState(SrcPduId);
					}
				}
				else
				{
					bufQeqRet = (BufReq_ReturnType)BUFREQ_OK;
					*bufferSizePtr = PduR_TpBuffer[tpBufferIndex].TpBufferLength;
				}
			}
			/* not gateway-on-the-fly */
			else
			{
				for (cnt = (uint16)0; cnt < (uint16)DestPduNum; cnt++)
				{
				
					if((boolean)TRUE == PathIsEnabled[SrcPduId])
					{
						tpRunTimeIndex = PduR_ConfigData->PduRRoutingTableRef[SrcPduId].\
								PduRDestPduIdRef[cnt].GateWayTpRunTimeIndex;
						PduR_GateWayDestTpSate[tpRunTimeIndex].ActiveTpBufferId = tpBufferIndex;
						PduR_GateWayDestTpSate[tpRunTimeIndex].TpTxConfirmation = (boolean)FALSE;
						PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset = (uint16)0;
					}
				}
				*bufferSizePtr = PduR_TpBuffer[tpBufferIndex].TpBufferLength;
				bufQeqRet = (BufReq_ReturnType)BUFREQ_OK;
			}
		}
		else
		{
			/**
			 * @req [SWS_PduR_00799] If no buffer could be allocated during a call of PduR_<SrcLoTp>
			 * 						 StartOfReception for the reception of a gatewayed TP PDU, the
			 * 						 PduR shall immediately stop further processing of this I-PDU and
			 * 						 return BUFREQ_E_OVFL
			 */
			bufQeqRet = (BufReq_ReturnType)BUFREQ_E_OVFL;
		}
	}
	/* SF tp pdu gateway,need store in dedicated buffer */
	else
	{
		for(cnt = (uint16)0; cnt < (uint16)DestPduNum;cnt++)
		{
			
			if((boolean)TRUE == PathIsEnabled[SrcPduId])
			{
				pduRDestTxBuffeIndex = PduR_ConfigData->PduRRoutingTableRef[SrcPduId].\
						PduRDestPduIdRef[cnt].PduRDestTxBufferRef;
				PduR_TxBuffer[pduRDestTxBuffeIndex].PduRTxBufferRef[0].SduLength =(uint16) Length;
				#if(STD_ON == PDUR_META_DATA_SUPPORT)
				PduR_Memcpy(
							PduR_TxBuffer[pduRDestTxBuffeIndex].MetaData,
							info->SduDataPtr,
							PduR_ConfigData->PduRSrcPduRef[SrcPduId].MetaDataLength);
				#endif/* STD_ON == PDUR_META_DATA_SUPPORT */
				tpRunTimeIndex = PduR_ConfigData->PduRRoutingTableRef[SrcPduId].\
						PduRDestPduIdRef[cnt].GateWayTpRunTimeIndex;
				PduR_GateWayDestTpSate[tpRunTimeIndex].TpTxConfirmation = (boolean)FALSE;
				PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset = (uint8)0;
			}
		}
		/* configuration guarantee the buffer length >= SF Pdu Length */
		*bufferSizePtr = Length;
		bufQeqRet = (BufReq_ReturnType)BUFREQ_OK;
	}
	return bufQeqRet;
}



/**
 * @req [SWS_PduR_00740] If the transport protocol module calls PduR_<LoTp>CopyTxData or PduR_<LoTp>
 * 						 CopyRxData with length zero (PduInfoType.SduLength = 0) the PDU Router module
 * 						 shall return the size of the current available buffer or the current
 * 						 available data respectively.
 */
/**
 * @brief			Rx Tp Pdu gateway to only one Tp Module Pdu handle,when copy Rx Data
 * @param[in]		SrcPduId : Source Pdu Id
 * @param[in]		DestPduId : Dest Pdu Id
 * @param[in]		info : Length and pointer to the buffer of the I-PDU.
 * @param[in]		bufferSizePtr : The size of the upper available space that needs to be confirmed
 * @param[out]		/
 * @param[in/out]	/
 * @return			BufReq_ReturnType
 * @retval			BUFREQ_OK
 * 					BUFREQ_E_NOT_OK
 * 					BUFREQ_E_BUSY
 * 					BUFREQ_E_OVFL
 */
STATIC FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_CopyRxDataToOneTpHandle(
	VAR(PduIdType, PDUR_VAR) SrcPduId,
	VAR(PduIdType, PDUR_VAR) DestPduId,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA)BufferSizePtr
)
/* Buffersizeptr should be the size of the buffer required to replicate the data */
{
	BufReq_ReturnType ret = BUFREQ_E_NOT_OK;
	uint16 destPduBufferIndex;
	uint8 tpBufferIndex;
	uint16 tpRunTimeIndex;
	uint16 threshold;
	uint8 destPduNum;
	uint8 index;
	destPduNum = PduR_ConfigData->PduRRoutingTableRef[SrcPduId].DestPduNumber;
	
	if((boolean)FALSE == PduR_ConfigData->PduRRoutingTableRef[SrcPduId].TpPduIsSF)
	{
		/*find the valid tp buffer to copy the data*/
		/*Because it's a continuous frame or the first frame, and then you're going to find the next
		 * buffer that you can use */
		tpBufferIndex = PduR_FindTpBuffer(SrcPduId);
		/* PRQA S 2996 # violate MISRA_2004_Rule_13.7:The result of this logical operation can be
		 * (boolean)false */
		
		if(0xffu != tpBufferIndex)
		{
			/*copy the rx pdu data to the tp buffer*/
			/**
			 * @req [SWS_PduR_00687] If routing on-the-fly is used and PduR_<SrcLoTp>CopyRxData is
			 * 						 called and the provided data cannot be stored in the buffer,
			 * 						 then BUFREQ_E_NOT_OK shall be returned and the execution of
			 * 						 the I- PDU gateway shall be stopped.
			 */
			ret = PduR_CopyRxDataToTpBuffer(tpBufferIndex, info, BufferSizePtr);
			
			if((BUFREQ_OK == ret) && ((boolean)TRUE == PduR_ConfigData->PduRRoutingTableRef\
					[SrcPduId].GatewayOnTheFly))
			{
				for(index = 0u; index < destPduNum; index++)
				{
					if(PduR_ConfigData->PduRRoutingTableRef[SrcPduId].PduRDestPduIdRef[index].\
							DestPduId == DestPduId)
					{

						/**
						 * @req [SWS_PduR_00317] The PDU Router module shall start the TP transmission
						 * 						 on the destination bus by calling <DstLoTp>_Transmit
						 * 						 as soon as the Tx threshold has been reached for the
						 * 						 specific destination.
						 */
						threshold = PduR_ConfigData->PduRRoutingTableRef[SrcPduId].\
								PduRDestPduIdRef[index].PduRTpThreshold;
						tpRunTimeIndex = PduR_ConfigData->PduRRoutingTableRef[SrcPduId].\
								PduRDestPduIdRef[index].GateWayTpRunTimeIndex;
						if(((boolean)TRUE == PduR_GateWayDestTpSate[tpRunTimeIndex].IsGateWayOnTheFly)\
								&& (PduR_TpBuffer[tpBufferIndex].RxBufferOffset >= threshold))
						{
							/* gateway MF pdu to Tp mode by LoTp_Transmit */
							
							if((Std_ReturnType)E_NOT_OK == PduR_GateWayMFToTp(SrcPduId, DestPduId))
							{
								ret = BUFREQ_E_NOT_OK;
							}
							PduR_GateWayDestTpSate[tpRunTimeIndex].IsGateWayOnTheFly = (boolean)FALSE;
						}
					}
				}
			}
		}

		else
		{
			ret = BUFREQ_E_NOT_OK;
		}
	}
	else
	{
		for(index = 0u; index < destPduNum; index++)
		{
			if(PduR_ConfigData->PduRRoutingTableRef[SrcPduId].PduRDestPduIdRef[index].DestPduId == \
					DestPduId)
			{
				destPduBufferIndex = PduR_ConfigData->PduRRoutingTableRef[SrcPduId].\
						PduRDestPduIdRef[index].PduRDestTxBufferRef;
				if(info->SduLength == PduR_TxBuffer[destPduBufferIndex].PduRTxBufferRef[0].SduLength)
				{
					PduR_Memcpy(
								PduR_TxBuffer[destPduBufferIndex].PduRTxBufferRef[0].TxBufferData,
								info->SduDataPtr,
								(uint16)info->SduLength);
					*BufferSizePtr = (PduLengthType)0;
					ret = BUFREQ_OK;
				}
				/**
				 * @req [SWS_PduR_00687] If routing on-the-fly is used and PduR_<SrcLoTp>CopyRxData is
				 * 						 called and the provided data cannot be stored in the buffer,
				 * 						 then BUFREQ_E_NOT_OK shall be returned and the execution of
				 * 						 the I- PDU gateway shall be stopped.
				 */
				else
				{
					/**
					 * @req [SWS_PduR_00792] When <UpTp>_CopyRxData returns an error, the PduR shall
					 * 						 call <UpTp>_RxIndication with result = E_NOT_OK.
					 */
					ret = BUFREQ_E_NOT_OK;
				}
			}
		}
	}
	return ret;
}

/**
 * @req [SWS_PduR_00161]
 */
/**
 * @brief			1:n Rx Tp Pdu GateWay(more than one Tp Module,zero or one Up Module),when copy
 * 					Rx Data
 * @param[in]		SrcPduId : Source Pdu Id
 * @param[in]		destPduNum : number of Dest Pdu
 * @param[in]		info : Length and pointer to the buffer of the I-PDU.
 * @param[in]		bufferSizePtr : The size of the upper available space that needs to be confirmed
 * @param[out]		/
 * @param[in/out]	/
 * @return			BufReq_ReturnType
 * @retval			BUFREQ_OK
 * 					BUFREQ_E_NOT_OK
 * 					BUFREQ_E_BUSY
 * 					BUFREQ_E_OVFL
 */
STATIC FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_CopyRxDataToMultitudeBswHandle(
	VAR(PduIdType, PDUR_VAR) SrcPduId,
	VAR(uint8, PDUR_VAR) destPduNum,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA)BufferSizePtr
)
{
	BufReq_ReturnType ret = BUFREQ_E_NOT_OK;
	PduIdType pduRDestPduId;
	uint16 tpRunTimeIndex;
	uint16 tpThreshold;
	uint16 pduRDestTxBuffeId;
	uint8 tpBufferId;
	uint16 cnt;
	/* the tp data is stored  in Dedicated buffer(SF) */
	
	if((boolean)TRUE == PduR_ConfigData->PduRRoutingTableRef[SrcPduId].TpPduIsSF)
	{
		for(cnt=(uint16)0;cnt<(uint16)destPduNum;cnt++)
		{
			tpRunTimeIndex = PduR_ConfigData->PduRRoutingTableRef[SrcPduId].PduRDestPduIdRef[cnt].\
					GateWayTpRunTimeIndex;
			
			if((boolean)FALSE == PduR_GateWayDestTpSate[tpRunTimeIndex].TpTxConfirmation)
			{
				
				if((boolean)TRUE == PathIsEnabled[SrcPduId])
				{
					pduRDestTxBuffeId = PduR_ConfigData->PduRRoutingTableRef[SrcPduId].\
							PduRDestPduIdRef[cnt].PduRDestTxBufferRef;
					if(info->SduLength == PduR_TxBuffer[pduRDestTxBuffeId].PduRTxBufferRef[0].SduLength)
					{
						PduR_Memcpy(PduR_TxBuffer[pduRDestTxBuffeId].PduRTxBufferRef[0].\
								TxBufferData,info->SduDataPtr,(uint16)info->SduLength);
						*BufferSizePtr = (PduLengthType)0;
						ret = BUFREQ_OK;
					}
					else
					{
						PduR_GateWayDestTpSate[tpRunTimeIndex].TpTxConfirmation = (boolean)TRUE;
					}
				}
				else
				{
					PduR_GateWayDestTpSate[tpRunTimeIndex].TpTxConfirmation = (boolean)TRUE;
				}
			}
		}
		
		if((boolean)FALSE == PduR_AtLeastOneDestIsNotTxConfirm(SrcPduId))
		{
			ret = BUFREQ_E_NOT_OK;
		}
	}
	/* the tp data is stored in Tp buffer(FF and CF) */
	else
	{
		for(cnt = (uint16)0;cnt<(uint16)destPduNum;cnt++)
		{
			
			if((boolean)FALSE == PathIsEnabled[SrcPduId])
			{
				tpRunTimeIndex = PduR_ConfigData->PduRRoutingTableRef[SrcPduId].\
						PduRDestPduIdRef[cnt].GateWayTpRunTimeIndex;
				PduR_GateWayDestTpSate[tpRunTimeIndex].TpTxConfirmation = (boolean)TRUE;
			}
		}
		/* dest pdu need use rx pdu data */
		
		if((boolean)TRUE == PduR_AtLeastOneDestIsNotTxConfirm(SrcPduId))
		{
			/* find valid buffer to copy data */
			tpBufferId = PduR_FindTpBuffer(SrcPduId);
			
			if(0xffu != tpBufferId)
			{

				ret = PduR_CopyRxDataToTpBuffer(tpBufferId, info, BufferSizePtr);
				
				if((BUFREQ_OK == ret) \
					&&((boolean)TRUE == PduR_ConfigData->PduRRoutingTableRef[SrcPduId].GatewayOnTheFly))
				{
					for(cnt=(uint16)0;cnt<(uint16)destPduNum;cnt++)
					{
						pduRDestPduId = PduR_ConfigData->PduRRoutingTableRef[SrcPduId].\
								PduRDestPduIdRef[cnt].DestPduId;
						tpRunTimeIndex = PduR_ConfigData->PduRRoutingTableRef[SrcPduId].\
								PduRDestPduIdRef[cnt].GateWayTpRunTimeIndex;
				
						if((boolean)FALSE == PduR_GateWayDestTpSate[tpRunTimeIndex].TpTxConfirmation)
						{
							tpThreshold = PduR_ConfigData->PduRRoutingTableRef[SrcPduId].\
									PduRDestPduIdRef[cnt].PduRTpThreshold;
							if(((boolean)TRUE == PduR_GateWayDestTpSate[tpRunTimeIndex].\
									IsGateWayOnTheFly) \
								&&(PduR_TpBuffer[tpBufferId].RxBufferOffset >= tpThreshold))
							{
								/* gateway MF pdu to Tp mode by LoTp_Transmit */
/* PRQA S 0715 EOF # violate MISRA_2004_Rule_1.1:The control structure can exceed 15 nested sets */
								if((Std_ReturnType)E_NOT_OK == PduR_GateWayMFToTp\
										(SrcPduId, pduRDestPduId))
								{
									PduR_GateWayDestTpSate[tpRunTimeIndex].TpTxConfirmation = \
											(boolean)TRUE;
								}
								PduR_GateWayDestTpSate[tpRunTimeIndex].IsGateWayOnTheFly = \
										(boolean)FALSE;
							}
						}
					}
					if((boolean)FALSE == PduR_AtLeastOneDestIsNotTxConfirm(SrcPduId))
					{
						ret = BUFREQ_E_NOT_OK;
					}
				}
			}
			/* unvalid tp buffer */
			else
			{
				ret = BUFREQ_E_NOT_OK;
			}
		}
		else
		{
			ret = BUFREQ_E_NOT_OK;
		}
	}
	return ret;
}

/**
 * @brief			Rx Tp Pdu gateway to only one Tp Module Pdu handle,when Rx Indication
 * @param[in]		SrcPduId : Source Pdu Id
 * @param[in]		destPduNum : number of Dest Pdu
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
STATIC FUNC(void, PDUR_CODE)
PduR_RxIndicationToTpHandle(
	VAR(PduIdType, PDUR_VAR) SrcPduId,
	VAR(PduIdType, PDUR_VAR) DestPduId
)
{
	uint8 destPduNum;
	uint8 pduIndex;
	uint16 TpRunTimeIndex = 0u;
	/* pdu data stored in tp buffer */
	if((boolean)FALSE == PduR_ConfigData->PduRRoutingTableRef[SrcPduId].TpPduIsSF)
	{
		/**
		 * @req [SWS_PduR_00797] If a gatewayed TP PDU reception is indicated via PduR_<SrcLoTp>Start
		 * 						 OfReception, and the total SDU size reported by the parameter
		 * 						 TpSduLength is not larger than the configured PduRPduMaxLength of the
		 * 						 dedicated buffer referenced by PduRDestTxBufferRef, the PduR shall
		 * 						 use the dedicated buffer
		 */
		if((boolean)TRUE == PduR_ConfigData->PduRRoutingTableRef[SrcPduId].GatewayOnTheFly)
		{
			destPduNum = PduR_ConfigData->PduRRoutingTableRef[SrcPduId].DestPduNumber;
			for(pduIndex = 0u;pduIndex < destPduNum; pduIndex++)
			{
				if(PduR_ConfigData->PduRRoutingTableRef[SrcPduId].PduRDestPduIdRef[pduIndex].\
						DestPduId == DestPduId)
				{
					TpRunTimeIndex = PduR_ConfigData->PduRRoutingTableRef[SrcPduId].\
							PduRDestPduIdRef[pduIndex].GateWayTpRunTimeIndex;
				}
			}
			if((boolean)TRUE == PduR_GateWayDestTpSate[TpRunTimeIndex].IsGateWayOnTheFly)
			{
				/* gateway MF pdu to Tp mode by LoTp_Transmit */
				/**
				 * @req [SWS_PduR_00551] The <DstLoTp>_Transmit shall be called on each destination
				 * 						 transport protocol module within the PduR_<SrcLoTp>
				 * 						 TpRxIndication, if result is (Std_ReturnType)E_OK
				 */
				if((Std_ReturnType)E_OK == PduR_GateWayMFToTp(SrcPduId, DestPduId))
				{
					PduR_GateWayDestTpSate[TpRunTimeIndex].IsGateWayOnTheFly = (boolean)FALSE;
				}
				else
				{
					/**
					 * @req [SWS_PduR_00689] If the result value is not (Std_ReturnType)E_OK in the
					 *  PduR_<SrcLoTp>
					 * 						 RxIndication, the PDU Router shall immediately stop
					 * 						 further processing of the I-PDU.
					 */
					PduR_ClearGateWayTpBufferAndState(SrcPduId);
				}
			}
		}
		/* Receive all pdu data,then gateway to other tp module */
		else
		{
			/* gateway MF pdu to Tp mode by LoTp_Transmit */
			/**
			 * @req [SWS_PduR_00551] The <DstLoTp>_Transmit shall be called on each destination
			 * 						 transport protocol module within the PduR_<SrcLoTp>TpRxIndication,
			 * 						 if result is (Std_ReturnType)E_OK
			 */
			if((Std_ReturnType)E_NOT_OK == PduR_GateWayMFToTp(SrcPduId, DestPduId))
			{
				PduR_ClearGateWayTpBufferAndState(SrcPduId);
			}
		}
	}
	/* pdu data stored in dedicated buffer(SF) */
	else
	{
		/* gateway SF pdu to Tp mode by LoTp_Transmit */
		if((Std_ReturnType)E_NOT_OK == PduR_GateWaySFToTp(SrcPduId, DestPduId))
		{
			PduR_ClearGateWayTpBufferAndState(SrcPduId);
		}
	}
	return;
}

/**
 * @brief			1:n Rx Tp Pdu GateWay(more than one Tp Module,zero or one Up Module),when Rx
 * 					Indication
 * @param[in]		SrcPduId : Source Pdu Id
 * @param[in]		destPduNum : number of Dest Pdu
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
*/
STATIC FUNC(void, PDUR_CODE)
PduR_RxIndicationToMultitudeBswHandle(
	VAR(PduIdType, PDUR_VAR) SrcPduId,
	VAR(uint8, PDUR_VAR) DestPduSum
)
{
	PduIdType destPduId;
	uint16 gatewayTpRunTimeId;
	boolean checkDestTxConfirmState = (boolean)FALSE;
	uint8 num;
	uint8 destModuleType;
	if((boolean)TRUE == PduR_AtLeastOneDestIsNotTxConfirm(SrcPduId))
	{
		/**
		 * @req [PduR_SWS_00803] In case of gatewaying between TPs, when one destination fails
		 * 						 (Transmit returns (Std_ReturnType)E_NOT_OK or TpTxConfirmation is
		 * 						 called with an error), the other destinations shall continue.
		 */
		for(num=(uint8)0;num<(uint8)DestPduSum;num++)
		{
			destPduId = PduR_ConfigData->PduRRoutingTableRef[SrcPduId].PduRDestPduIdRef[num].\
					DestPduId;
			if((boolean)FALSE == PathIsEnabled[SrcPduId])
			{
				gatewayTpRunTimeId = PduR_ConfigData->PduRRoutingTableRef[SrcPduId].\
						PduRDestPduIdRef[num].GateWayTpRunTimeIndex;
				PduR_GateWayDestTpSate[gatewayTpRunTimeId].TpTxConfirmation = (boolean)TRUE;
			}
			gatewayTpRunTimeId = PduR_ConfigData->PduRRoutingTableRef[SrcPduId].\
					PduRDestPduIdRef[num].GateWayTpRunTimeIndex;
			if((boolean)FALSE == PduR_GateWayDestTpSate[gatewayTpRunTimeId].TpTxConfirmation)
			{
				destModuleType = PduR_ConfigData->PduRRoutingTableRef[SrcPduId].\
						PduRDestPduIdRef[num].DestModuleType;
				switch(destModuleType)
				{
					#if(STD_ON == PDUR_COM_SUPPORT)
					case PDUR_COM:
					#endif/* STD_ON == PDUR_COM_SUPPORT */
					#if(STD_ON == PDUR_LDCOM_SUPPORT)
					case PDUR_LDCOM:
					#endif/* STD_ON == PDUR_LDCOM_SUPPORT */
					#if(STD_ON == PDUR_SECOC_SUPPORT)
					case PDUR_SECOC:
					#endif/* STD_ON == PDUR_SECOC_SUPPORT */
					#if(STD_ON == PDUR_DCM_SUPPORT)
					case PDUR_DCM:
					#endif/* STD_ON == PDUR_DCM_SUPPORT */
					#if(STD_ON == PDUR_J1939DCM_SUPPORT)
					case PDUR_J1939DCM:
					#endif/* STD_ON == PDUR_J1939DCM_SUPPORT */
					if((boolean)FALSE == PduR_ConfigData->PduRRoutingTableRef[SrcPduId].TpPduIsSF)
					{
						/* route the pdu to one up mode */
						PduR_RouteMFtoUp(destModuleType, SrcPduId, destPduId);
					}
					else
					{
						/* route the pdu to one up mode */
						PduR_RouteSFtoUp(destModuleType, SrcPduId, destPduId);
					}
					checkDestTxConfirmState = (boolean)TRUE;
					break;
					/* Gateway pdu */
					default:
						if((boolean)FALSE == PduR_ConfigData->PduRRoutingTableRef[SrcPduId].TpPduIsSF)
						{
							/**
							 * @req [SWS_PduR_00797] If a gatewayed TP PDU reception is indicated via
							 * 						 PduR_<SrcLoTp>StartOfReception, and the total SDU
							 * 						 size reported by the parameter TpSduLength is not
							 * 						 larger than the configured PduRPduMaxLength of the
							 * 						 dedicated buffer referenced by PduRDestTxBufferRef,
							 * 						 the PduR shall use the dedicated buffer
							 */
							if((boolean)TRUE == PduR_ConfigData->PduRRoutingTableRef[SrcPduId].\
									GatewayOnTheFly)
							{
								if((boolean)TRUE == PduR_GateWayDestTpSate[gatewayTpRunTimeId].\
										IsGateWayOnTheFly)
								{
									/* gateway MF pdu to Tp mode by LoTp_Transmit */
									if((Std_ReturnType)E_NOT_OK == PduR_GateWayMFToTp\
											(SrcPduId, destPduId))
									{
										PduR_GateWayDestTpSate[gatewayTpRunTimeId].TpTxConfirmation = \
												(boolean)FALSE;
										checkDestTxConfirmState = (boolean)TRUE;
									}
									PduR_GateWayDestTpSate[gatewayTpRunTimeId].IsGateWayOnTheFly = \
											(boolean)TRUE;
								}
							}
							/* Receive all pdu data,then gateway to other tp module */
							else
							{
								/* gateway MF pdu to Tp mode by LoTp_Transmit */
								if((Std_ReturnType)E_NOT_OK == PduR_GateWayMFToTp(SrcPduId, destPduId))
								{
									PduR_GateWayDestTpSate[gatewayTpRunTimeId].TpTxConfirmation = \
											(boolean)TRUE;
									checkDestTxConfirmState = (boolean)TRUE;
								}
							}
						}
						else
						{
							/* gateway SF pdu to Tp mode by LoTp_Transmit */
							if((Std_ReturnType)E_NOT_OK == PduR_GateWaySFToTp(SrcPduId, destPduId))
							{
								PduR_GateWayDestTpSate[gatewayTpRunTimeId].TpTxConfirmation = \
										(boolean)TRUE;
								checkDestTxConfirmState = (boolean)TRUE;
							}
						}
						break;
				}
			}
		}
		if((boolean)TRUE == checkDestTxConfirmState)
		{
			if((boolean)FALSE == PduR_AtLeastOneDestIsNotTxConfirm(SrcPduId))
			{
				PduR_ClearGateWayTpBufferAndState(SrcPduId);
			}
		}
	}
	else
	{
		PduR_ClearGateWayTpBufferAndState(SrcPduId);
	}
	return;
}

/**
 * @req [SWS_PduR_00818] For TP gateway scenario, the availableDataPtr of the PduR_<LoTp>CopyTxData
 * 						 indicates the remaining number of bytes that are available in the PduR's
 * 						 (gateway) TP buffer.
 */
/**
 * @brief			one Tp Pdu route to one Tp Pdu,the dest pdu copy tx data handle
 * @param[in]		SrcPduId : Source Pdu Id
 * @param[in]		ActualPduId : Dest Pdu Id
 * @param[in]		info : Length and pointer to the buffer of the I-PDU.
 * @param[in]		retry : The pointer structure of the retry operation
 * @param[in]		availableDataPtr : The size of the upper available space that needs to be confirmed
 * @param[out]		/
 * @param[in/out]	/
 * @return			BufReq_ReturnType
 * @retval			BUFREQ_OK
 * 					BUFREQ_E_NOT_OK
 * 					BUFREQ_E_BUSY
 * 					BUFREQ_E_OVFL
 */
STATIC FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_FromTpCopyTxDataHandle(
	VAR(PduIdType, PDUR_VAR) SrcPduId,
	VAR(PduIdType, PDUR_VAR) ActualPduId,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	P2CONST(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
)
/* The number of data available in the availabledataptr receive buffer */
{
	BufReq_ReturnType ret;
	uint16 tpRunTimeIndex;
	uint8 tpBufferId;
	uint16 destPduTxBuffeIndex;
	tpRunTimeIndex = PduR_ConfigData->PduRRoutingTableRef[SrcPduId].PduRDestPduIdRef[0].\
			GateWayTpRunTimeIndex;
	if((boolean)FALSE == PduR_GateWayDestTpSate[tpRunTimeIndex].TpTxConfirmation)
	{
		/* Gateway Multi-Frame I-PDU */
		if((boolean)FALSE == PduR_ConfigData->PduRRoutingTableRef[SrcPduId].TpPduIsSF)
		{
			tpBufferId = PduR_GateWayDestTpSate[tpRunTimeIndex].ActiveTpBufferId;
			/* gateway-on-the-fly mode */

			if((boolean)TRUE == PduR_ConfigData->PduRRoutingTableRef[SrcPduId].GatewayOnTheFly)
			{
				ret = PduR_HandleOneModuleOnFlyGateway(tpRunTimeIndex,info,tpBufferId,retry,\
						availableDataPtr);
			}
			/* not gateway-on-the-fly mode */
			else
			{
				ret = PduR_HandleOneModuleNotOnFlyGateway(tpRunTimeIndex,info,tpBufferId,retry,\
						availableDataPtr);
			}
		}
		/* Gateway Single-Frame I-PDU */
		/* If it's a single frame, a direct buffer, all the data is buffered to the buffer and there is
		 * no available data so availableDataPtr = 0; */
		else
		{
			destPduTxBuffeIndex = PduR_ConfigData->PduRRoutingTableRef[SrcPduId].PduRDestPduIdRef[0].\
					PduRDestTxBufferRef;
			if(info->SduLength == PduR_TxBuffer[destPduTxBuffeIndex].PduRTxBufferRef[0].SduLength)
			{
				PduR_Memcpy(info->SduDataPtr,PduR_TxBuffer[destPduTxBuffeIndex].PduRTxBufferRef[0].\
						TxBufferData,(uint16)info->SduLength);
				*availableDataPtr = (PduLengthType)0;
				ret = BUFREQ_OK;
			}
			else
			{
				/**
				 * @req [SWS_PduR_00815] For multi-frame transmission, if PduR_<DstLoTp>CopyTxData is
				 * 						 called with TpDataState TP_DATARETRY, the PDU Router shall
				 * 						 return BUFREQ_E_NOT_OK without copying any data
				 */
				ret = BUFREQ_E_NOT_OK;
			}
		}
	}
	else
	{
		ret = BUFREQ_E_NOT_OK;
	}
	return ret;
}

/**
 * @brief			one Tp Pdu route to one Tp Pdu,the dest pdu copy tx data handle
 * @param[in]		tpRunTimeIndex : gateway buffer index
 * @param[in]		tpBufferId : tp pdu buffer
 * @param[in]		info : Length and pointer to the buffer of the I-PDU.
 * @param[in]		retry : The pointer structure of the retry operation
 * @param[in]		availableDataPtr : The size of the upper available space that needs to be confirmed
 * @param[out]		/
 * @param[in/out]	/
 * @return			BufReq_ReturnType
 * @retval			BUFREQ_OK
 * 					BUFREQ_E_NOT_OK
 * 					BUFREQ_E_BUSY
 * 					BUFREQ_E_OVFL
 */
STATIC FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_HandleOneModuleOnFlyGateway(
	VAR(uint16, PDUR_VAR) tpRunTimeIndex,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	VAR(uint8, PDUR_VAR) tpBufferId,
	P2CONST(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
)
{
	BufReq_ReturnType ret;
	uint8 nextTpBufferId;
	uint16 tpBufferIfCopyLength;
	/**
	 * @req [SWS_PduR_00697] For Single-frame transmission, if PduR_<DstLoTp>CopyTxData is called with
	 * 						 TpDataState TP_CONFPENDING or TP_DATACONF or when the RetryInfoType
	 * 						 pointer is NULL, the PDU Router shall copy SduLength bytes of data. If
	 * 						 not enough data is avilalble, the Pdu Router shall return BUFREQ_E_BUSY
	 * 						 without copying any data.
	 */
	/**
	 * @req [SWS_PduR_00707] If PduR_<DstLoTp>CopyTxData is called with TpDataState TP_DATACONF or if
	 * 						 the RetryInfoType pointer is NULL, the PDU Router shall copy SduLength
	 * 						 bytes of data.
	 */
	if((NULL_PTR == retry) || (TP_DATACONF == retry->TpDataState) \
			|| (TP_CONFPENDING == retry->TpDataState))
	{
		nextTpBufferId = PduR_TpBuffer[tpBufferId].NextTpBufferId;
		/* the active tp buffer have stored full and other tp buffer have start store Rx Tp Pdu data */
		/* Copy the data in the tx buffer to the tp buffer */
		if(0xffu != nextTpBufferId)
		{
			/* updata available data length then indication Lo Tp module */
			if((PduLengthType)0 == info->SduLength)
			{
				/* The length of the data that is cached is the length of the receiving data minus the
				 * length of the sent data and the remaining effective buffer length */
				*availableDataPtr = ((PduLengthType)PduR_TpBuffer[tpBufferId].RxBufferOffset + \
						(PduLengthType)PduR_TpBuffer[nextTpBufferId].RxBufferOffset)  \
									- (PduLengthType)PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset;
				ret = BUFREQ_OK;
			}
			/* copy data and indication Lo Tp Module the available data length */
			else
			{
				/* the active buffer have not copy completely */
				/* If the data sent plus the number of data requested is more than the total amount of
				 * the received storage, it is not in this condition */
				if((PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset + info->SduLength) <= \
						PduR_TpBuffer[tpBufferId].RxBufferOffset)
				{
					/* Copy the data that is cached from the end of the message */
					PduR_Memcpy(info->SduDataPtr,
								&PduR_TpBuffer[tpBufferId].\
								TpBufferData[PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset],
								(uint16)info->SduLength);
					/* Mark the data length in the tp buffer and update the stop bit */
					PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset += (uint16)info->SduLength;
					/* Update the effective buffer data length and subtract the total length of the tx
					 * from the data length to the effective data length */
					*availableDataPtr = ((PduLengthType)PduR_TpBuffer[tpBufferId].RxBufferOffset + \
							(PduLengthType)PduR_TpBuffer[nextTpBufferId].RxBufferOffset)  \
										- (PduLengthType)PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset;
					ret = BUFREQ_OK;
				}
				/* The data sent plus the requested data exceeds the data received */
				else
				{
					/* the active buffer have not copy completely */
					/* How many buffer packets are required */
					tpBufferIfCopyLength = (PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset \
										   + (uint16)info->SduLength) - \
												   PduR_TpBuffer[tpBufferId].RxBufferOffset;
					/**
					 * @req [SWS_PduR_00697] don't have enough rx valid data for copy
					 */
					/* If the required packets are not sufficient in the next buffer, the buffer is
					 * returned */
					if(tpBufferIfCopyLength > PduR_TpBuffer[nextTpBufferId].RxBufferOffset)
					{
						ret = BUFREQ_E_BUSY;
					}
					/* have enough rx valid data for copy */
					/* If the amount of the buffer is sufficient to enter this code */
					else
					{
						/* The valid data in this buffer is copied into the tp buffer, which is the
						 * length of the copy(info->SduLength - TpBufferIfCopyLength) */
						PduR_Memcpy(
									info->SduDataPtr,
									&PduR_TpBuffer[tpBufferId].\
									TpBufferData[PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset],
									(uint16)(info->SduLength - tpBufferIfCopyLength));
						/* Remove the rest from another buffer */
						PduR_Memcpy(
									&info->SduDataPtr[info->SduLength - tpBufferIfCopyLength],
									&PduR_TpBuffer[nextTpBufferId].TpBufferData[0],
									tpBufferIfCopyLength);
						/* This is the data length sent by the current buffer */
						PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset = tpBufferIfCopyLength;
						PduR_GateWayDestTpSate[tpRunTimeIndex].ActiveTpBufferId = nextTpBufferId;
						*availableDataPtr = (PduLengthType)PduR_TpBuffer[nextTpBufferId].RxBufferOffset - \
								tpBufferIfCopyLength;
						ret = BUFREQ_OK;
						/* clear the tp buffer which have been copyed all data */
						PduR_TpBuffer[tpBufferId].NextTpBufferId = (uint8)0xff;
						PduR_TpBuffer[tpBufferId].PduHandleId = (PduIdType)0xffff;
						PduR_TpBuffer[tpBufferId].RxBufferOffset = (uint16)0;
						PduR_TpBuffer[tpBufferId].SduLength = (uint16)0;
						PduR_TpBuffer[tpBufferId].used = (boolean)FALSE;
					}
				}
			}
		}
		/* if tp buffer store not full */
		else
		{
			/* updata available data length then indication Lo Tp module */
			if((PduLengthType)0 == info->SduLength)
			{
				*availableDataPtr = (PduLengthType)PduR_TpBuffer[tpBufferId].RxBufferOffset - \
						(PduLengthType)PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset;
				ret = BUFREQ_OK;
			}
			/* copy data and indication Lo Tp Module the available data length */
			else
			{
				if((PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset + info->SduLength) <= \
						PduR_TpBuffer[tpBufferId].RxBufferOffset)
				{
					PduR_Memcpy(
								info->SduDataPtr,
								&PduR_TpBuffer[tpBufferId].\
								TpBufferData[PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset],
								(uint16)info->SduLength);
					PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset +=(uint16) info->SduLength;
					*availableDataPtr = (PduLengthType)PduR_TpBuffer[tpBufferId].RxBufferOffset - \
							(PduLengthType)PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset;
					ret = BUFREQ_OK;
				}
				else
				{
					/**
					 * @req [SWS_PDUR_00814] If not enough data is availalble or not all other
					 * 						 destination transport protocoll modules have called PduR
					 * 						 _<DstLoTp>CopyTxData for the previous frame, the Pdu Router
					 * 						 shall return BUFREQ_E_BUSY without copying any data.
					 */
					ret = BUFREQ_E_BUSY;
				}
			}
		}
	}
	else
	{
		ret = BUFREQ_E_NOT_OK;
	}
	return ret;
}

/**
 * @brief			OneModuleNotOnFlyGateway
 * @param[in]		tpRunTimeIndex : gateway buffer index
 * @param[in]		tpBufferId : tp pdu buffer
 * @param[in]		info : Length and pointer to the buffer of the I-PDU.
 * @param[in]		retry : The pointer structure of the retry operation
 * @param[in]		availableDataPtr : The size of the upper available space that needs to be confirmed
 * @param[out]		/
 * @param[in/out]	/
 * @return			BufReq_ReturnType
 * @retval			BUFREQ_OK
 * 					BUFREQ_E_NOT_OK
 * 					BUFREQ_E_BUSY
 * 					BUFREQ_E_OVFL
 */

STATIC FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_HandleOneModuleNotOnFlyGateway(
	VAR(uint16, PDUR_VAR) tpRunTimeIndex,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	VAR(uint8, PDUR_VAR) tpBufferId,
	P2CONST(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
)
{
	BufReq_ReturnType ret;
	/**
	 * @req [SWS_PduR_00705] For Single-frame transmission, if PduR_<DstLoTp>CopyTxData is called
	 * 						 with TpDataState TP_DATARETRY, the PDU Router shall set back the current
	 * 						 position by TxTpDataCnt bytes and copy SduLength bytes of data. If the
	 * 						 Pdu Router cannot set back the position as requested, it shall return
	 * 						 BUFREQ_E_NOT_OK without changing the current position or copying any data
	 * 						 If, after resetting the current position, not enough data is available
	 * 						 for copying, the Pdu Router shall return BUFREQ_E_BUSY without copying
	 * 						 any data.
	 */
	if((NULL_PTR != retry) && (TP_DATARETRY == retry->TpDataState))
	{
		if(PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset >= retry->TxTpDataCnt)
		{
			PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset -= (uint16)retry->TxTpDataCnt;
		}
		/* will not happen general,TP module guarantee */
		else
		{
			/* re-copy data from 0 */
			PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset = (uint16)0;
		}
	}
	/* updata available data length then indication Lo Tp module */
	if((PduLengthType)0 == info->SduLength)
	{
		*availableDataPtr = (PduLengthType)PduR_TpBuffer[tpBufferId].RxBufferOffset - \
				(PduLengthType)PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset;
		ret = BUFREQ_OK;
	}
	/* copy data and indication Lo Tp Module the available data length */
	else
	{
		if((PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset + info->SduLength) <= \
				PduR_TpBuffer[tpBufferId].RxBufferOffset)
		{
			PduR_Memcpy(
						info->SduDataPtr,
						&PduR_TpBuffer[tpBufferId].\
						TpBufferData[PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset],
						(uint16)info->SduLength);
			PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset += (uint16)info->SduLength;
			*availableDataPtr = (PduLengthType)PduR_TpBuffer[tpBufferId].RxBufferOffset - \
					(PduLengthType)PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset;
			ret = BUFREQ_OK;
		}
		/* will not happen general,TP module guarantee */
		else
		{
			ret = BUFREQ_E_NOT_OK;
		}
	}
	return ret;
}

/**
 * @brief			OneModuleNotOnFlyGateway
 * @param[in]		SrcPduId : Source Pdu Id
 * @param[in]		tpRunTimeIndex : gateway buffer index
 * @param[in]		tpBufferId : tp pdu buffer
 * @param[in]		info : Length and pointer to the buffer of the I-PDU.
 * @param[in]		retry : The pointer structure of the retry operation
 * @param[in]		availableDataPtr : The size of the upper available space that needs to be confirmed
 * @param[out]		/
 * @param[in/out]	/
 * @return			BufReq_ReturnType
 * @retval			BUFREQ_OK
 * 					BUFREQ_E_NOT_OK
 * 					BUFREQ_E_BUSY
 * 					BUFREQ_E_OVFL
 */
STATIC FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_HandleMultiModuleOnFlyGateway(
	VAR(PduIdType, PDUR_VAR) SrcPduId,
	VAR(uint16, PDUR_VAR) tpRunTimeIndex,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	VAR(uint8, PDUR_VAR) tpBufferId,
	P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
)
{
	BufReq_ReturnType ret;
	uint16 availbleCopyLength;
	uint8 nextTpBufferId;
	nextTpBufferId = PduR_TpBuffer[tpBufferId].NextTpBufferId;
	if(0xffu != nextTpBufferId)
	{
		if((PduLengthType)0 == info->SduLength)
		{
			*availableDataPtr = ((PduLengthType)PduR_TpBuffer[tpBufferId].RxBufferOffset + \
					(PduLengthType)PduR_TpBuffer[nextTpBufferId].RxBufferOffset)
								- (PduLengthType)PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset;
			ret = BUFREQ_OK;
		}
		else
		{
			if((PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset + info->SduLength) <= \
					PduR_TpBuffer[tpBufferId].RxBufferOffset)
			{
				PduR_Memcpy(
							info->SduDataPtr,
							&PduR_TpBuffer[tpBufferId].\
							TpBufferData[PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset],
							(uint16)info->SduLength);
				PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset += (uint16)info->SduLength;
				*availableDataPtr = ((PduLengthType)PduR_TpBuffer[tpBufferId].RxBufferOffset + \
						(PduLengthType)PduR_TpBuffer[nextTpBufferId].RxBufferOffset) \
									- (PduLengthType)PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset;
				ret = BUFREQ_OK;
			}
			else
			{
				availbleCopyLength = (PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset + \
						(uint16)info->SduLength) \
										- PduR_TpBuffer[tpBufferId].RxBufferOffset;
				if(availbleCopyLength > PduR_TpBuffer[nextTpBufferId].RxBufferOffset)
				{
					ret = BUFREQ_E_BUSY;
				}
				else
				{
					PduR_Memcpy(
								&info->SduDataPtr[0],
								&PduR_TpBuffer[tpBufferId].\
								TpBufferData[PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset],
								(uint16)(info->SduLength - availbleCopyLength));
					PduR_Memcpy(
								&info->SduDataPtr[info->SduLength - availbleCopyLength],
								&PduR_TpBuffer[nextTpBufferId].TpBufferData[0],
								availbleCopyLength);
					PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset = availbleCopyLength;
					PduR_GateWayDestTpSate[tpRunTimeIndex].ActiveTpBufferId = nextTpBufferId;
					PduR_GateWayDestTpSate[tpRunTimeIndex].CopyCompleteTpBufferNumber++;
					*availableDataPtr = (PduLengthType)PduR_TpBuffer[nextTpBufferId].RxBufferOffset - \
							availbleCopyLength;
					ret = BUFREQ_OK;

					if((boolean)TRUE == PduR_ClearGateWayOnTheFlyTpBuffer\
							(SrcPduId, PduR_GateWayDestTpSate[tpRunTimeIndex].\
									CopyCompleteTpBufferNumber))
					{
						PduR_TpBuffer[tpBufferId].NextTpBufferId = (uint8)0xff;
						PduR_TpBuffer[tpBufferId].PduHandleId = (uint8)0xffff;
						PduR_TpBuffer[tpBufferId].RxBufferOffset = (uint16)0;
						PduR_TpBuffer[tpBufferId].SduLength = (uint16)0;
						PduR_TpBuffer[tpBufferId].used = (boolean)FALSE;
					}
				}
			}
		}
	}
	else
	{
		if((PduLengthType)0 == info->SduLength)
		{
			*availableDataPtr = (PduLengthType)PduR_TpBuffer[tpBufferId].RxBufferOffset - \
					(PduLengthType)PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset;
			ret = BUFREQ_OK;
		}
		else
		{
			if((PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset + info->SduLength) <= \
					PduR_TpBuffer[tpBufferId].RxBufferOffset)
			{
				PduR_Memcpy(
							info->SduDataPtr,
							&PduR_TpBuffer[tpBufferId].\
							TpBufferData[PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset],
							(uint16)info->SduLength);
				PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset += (uint16)info->SduLength;
				*availableDataPtr = (PduLengthType)PduR_TpBuffer[tpBufferId].RxBufferOffset - \
						(PduLengthType)PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset;
				ret = BUFREQ_OK;
			}
			else
			{
				ret = BUFREQ_E_BUSY;
			}
		}
	}
	return ret;
}

/**
 * @brief			MultiModuleNotOnFlyGateway
 * @param[in]		tpRunTimeIndex : gateway buffer index
 * @param[in]		tpBufferId : tp pdu buffer
 * @param[in]		info : Length and pointer to the buffer of the I-PDU.
 * @param[in]		retry : The pointer structure of the retry operation
 * @param[in]		availableDataPtr : The size of the upper available space that needs to be confirmed
 * @param[out]		/
 * @param[in/out]	/
 * @return			BufReq_ReturnType
 * @retval			BUFREQ_OK
 * 					BUFREQ_E_NOT_OK
 * 					BUFREQ_E_BUSY
 * 					BUFREQ_E_OVFL
 */
STATIC FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_HandleMultiModuleNotOnFlyGateway(
	VAR(uint16, PDUR_VAR) tpRunTimeIndex,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	VAR(uint8, PDUR_VAR) tpBufferId,
	P2CONST(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
)
{
	BufReq_ReturnType ret;
	/**
	 * @req [SWS_PduR_00813] For multi-frame transmission, if PduR_<DstLoTp>CopyTxData is called with
	 * 						 TpDataState TP_CONFPENDING or TP_DATACONF or when the RetryInfoType
	 * 						 pointer is NULL, the PDU Router shall copy SduLength bytes of data. Only
	 * 						 the call from the last destination module shall increase the buffer
	 * 						 position
	 */
	if((NULL_PTR != retry) && (TP_DATARETRY == retry->TpDataState))
	{
		if(PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset >= retry->TxTpDataCnt)
		{
			PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset -=(uint16) retry->TxTpDataCnt;
		}
		else
		{
			PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset = (uint16)0;
		}
	}
	if((PduLengthType)0 == info->SduLength)
	{
		*availableDataPtr = (PduLengthType)PduR_TpBuffer[tpBufferId].RxBufferOffset - \
				(PduLengthType)PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset;
		ret = BUFREQ_OK;
	}
	else
	{
		if((PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset + info->SduLength) <= \
				PduR_TpBuffer[tpBufferId].RxBufferOffset)
		{
			PduR_Memcpy(
						info->SduDataPtr,
						&PduR_TpBuffer[tpBufferId].\
						TpBufferData[PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset],
						(uint16)info->SduLength);
			PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset +=(uint16) info->SduLength;
			*availableDataPtr = (PduLengthType)PduR_TpBuffer[tpBufferId].RxBufferOffset - \
					(PduLengthType)PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset;
			ret = BUFREQ_OK;
		}
		else
		{
			ret = BUFREQ_E_NOT_OK;
		}
	}
	return ret;
}


/**
 * @brief			one Tp Pdu route to more module Pdus,one dest Tp Pdu copy tx data handle
 * @param[in]		SrcPduId : Source Pdu Id
 * @param[in]		ActualPduId : Dest Pdu Id
 * @param[in]		info : Length and pointer to the buffer of the I-PDU.
 * @param[in]		retry : The pointer structure of the retry operation
 * @param[in]		availableDataPtr : The size of the upper available space that needs to be confirmed
 * @param[out]		/
 * @param[in/out]	/
 * @return			BufReq_ReturnType
 * @retval			BUFREQ_OK
 * 					BUFREQ_E_NOT_OK
 * 					BUFREQ_E_BUSY
 * 					BUFREQ_E_OVFL
 */
STATIC FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_FromTpCopyTxDataToMultitudeBswHandle(
	VAR(PduIdType, PDUR_VAR) SrcPduId,
	VAR(PduIdType, PDUR_VAR) ActualPduId,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
)
{
	BufReq_ReturnType ret = BUFREQ_E_NOT_OK;
	uint16 tpRunTimeIndex;
	uint8 tpBufferId;
	uint16 destPduBuffeIndex;
	uint8 destPduNum;
	uint8 index;
	destPduNum = PduR_ConfigData->PduRRoutingTableRef[SrcPduId].DestPduNumber;
	for(index = 0u; index < destPduNum; index++)
	{
		if(PduR_ConfigData->PduRRoutingTableRef[SrcPduId].PduRDestPduIdRef[index].DestPduId == \
				ActualPduId)
		{
			tpRunTimeIndex = PduR_ConfigData->PduRRoutingTableRef[SrcPduId].\
					PduRDestPduIdRef[index].GateWayTpRunTimeIndex;
			if(((boolean)TRUE == PathIsEnabled[SrcPduId]) && ((boolean)FALSE == \
					PduR_GateWayDestTpSate[tpRunTimeIndex].TpTxConfirmation))
			{
				if((boolean)FALSE == PduR_ConfigData->PduRRoutingTableRef[SrcPduId].TpPduIsSF)
				{
					tpBufferId = PduR_GateWayDestTpSate[tpRunTimeIndex].ActiveTpBufferId;
					if((boolean)TRUE == PduR_ConfigData->PduRRoutingTableRef[SrcPduId].GatewayOnTheFly)
					{
						ret = PduR_HandleMultiModuleOnFlyGateway\
						(SrcPduId,tpRunTimeIndex, info, tpBufferId, retry, availableDataPtr);
					}
					else
					{
						ret = PduR_HandleMultiModuleNotOnFlyGateway\
						(tpRunTimeIndex, info, tpBufferId, retry, availableDataPtr);
					}
				}
				else
				{
					destPduBuffeIndex = PduR_ConfigData->PduRRoutingTableRef[SrcPduId].\
							PduRDestPduIdRef[index].PduRDestTxBufferRef;
					if(info->SduLength == PduR_TxBuffer[destPduBuffeIndex].PduRTxBufferRef[0].SduLength)
					{
						PduR_Memcpy(info->SduDataPtr,PduR_TxBuffer[destPduBuffeIndex].\
								PduRTxBufferRef[0].TxBufferData,(uint16)info->SduLength);
						*availableDataPtr = (PduLengthType)0;
						ret = BUFREQ_OK;
					}
					else
					{
						ret = BUFREQ_E_NOT_OK;
					}
				}
			}
			else
			{
				ret = BUFREQ_E_NOT_OK;
			}
		}
	}
	return ret;
}

/**
 * @brief			one up module Tx tp pdu(SF) to more Tp Module Pdus,the Lo Tp copy tx data
 * @param[in]		SrcModuleType : Pdu Module
 * @param[in]		SrcPduId : Source Pdu Id
 * @param[in]		info : Length and pointer to the buffer of the I-PDU.
 * @param[in]		availableDataPtr : The size of the upper available space that needs to be confirmed
 * @param[out]		/
 * @param[in/out]	/
 * @return			BufReq_ReturnType
 * @retval			BUFREQ_OK
 * 					BUFREQ_E_NOT_OK
 * 					BUFREQ_E_BUSY
 * 					BUFREQ_E_OVFL
 */
STATIC FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_UpMulticastTpCopyData(
	VAR(uint8, PDUR_VAR) SrcModuleType,
	VAR(PduIdType, PDUR_VAR) SrcPduId,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
)
{
	BufReq_ReturnType ret;
	RetryInfoType pduRRetry;
	PduIdType upPduId;
	upPduId = PduR_ConfigData->PduRSrcPduRef[SrcPduId].PduRSourcePduHandleId;
	if((boolean)TRUE == PathIsEnabled[SrcPduId])
	{
		ret = BUFREQ_OK;
		/* first dest copy data */
		if(0u == PduR_UpTxTpMulRoute[PduR_ConfigData->PduRSrcPduRef[SrcPduId].TxTpMulticastIndex].\
				DestCopyDataTimer)
		{
			/**
			 * @req [SWS_PduR_00631] For each position in the transmission, the request of PduR_
			 * 						 <LoTP>CopyTxData of the first destination lower layer module
			 * 						 shall be forwarded with TpDataState set to TP_CONFPENDING
			 */

			if(PduRUp_TpCopyTxData[SrcModuleType] != NULL_PTR)
			{
				ret = (BufReq_ReturnType)PduRUp_TpCopyTxData[SrcModuleType]\
						(upPduId, info, &pduRRetry, availableDataPtr);
			}
			if(BUFREQ_OK == ret)
			{
				PduR_UpTxTpMulRoute[PduR_ConfigData->PduRSrcPduRef[SrcPduId].TxTpMulticastIndex].\
				DestCopyDataTimer += (uint8)1;
			}
			pduRRetry.TpDataState = TP_CONFPENDING;
		}
		/* next dest copy data */
		else
		{
			/**
			 * @req [SWS_PduR_00632] All following calls of PduR_<LoTp>CopyTxData requests shall be
			 * 						 forwarded with TP_DATARETRY to allow the same data to be copied
			 */
			pduRRetry.TpDataState = TP_DATARETRY;
			pduRRetry.TxTpDataCnt = info->SduLength;
			if(PduRUp_TpCopyTxData[SrcModuleType] != NULL_PTR)
			{
				ret = (BufReq_ReturnType)PduRUp_TpCopyTxData[SrcModuleType]\
						(upPduId, info, &pduRRetry, availableDataPtr);
			}
			if(BUFREQ_OK == ret)
			{
				PduR_UpTxTpMulRoute[PduR_ConfigData->PduRSrcPduRef[SrcPduId].TxTpMulticastIndex].\
				DestCopyDataTimer +=(uint8) 1;
			}
		}
	}
	else
	{
		ret = BUFREQ_E_NOT_OK;
	}
	return ret;
}

/**
 * @req [SWS_PduR_00637] When the PDU Router module receives the PduR_<DstLoTp>TxConfirmation, the PDU
 * 						 Router shall free the I-PDU buffer
 * 						 for this destination
 */
/**
 * @brief			handle txconfirmation
 * @param[in]		srcModuleType : Pdu Module
 * @param[in]		SrcPduId : Source Pdu Id
 * @param[in]		DestPduNum : number of pdu
 * @param[in]		Ret : result
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
STATIC FUNC(void, PDUR_CODE)
PduR_UpTpTxConfirmationHandle(
	VAR(uint8, PDUR_VAR) srcModuleType,
	VAR(PduIdType, PDUR_VAR) SrcPduId,
	VAR(uint8, PDUR_VAR) DestPduNum,
	VAR(Std_ReturnType, PDUR_VAR) Ret
)
{
	PduIdType actualUpPduId;
	actualUpPduId = PduR_ConfigData->PduRSrcPduRef[SrcPduId].PduRSrcModulePduId;
	/**
	 * @req [SWS_PduR_00765] In case of multi cast transmission, the PDU Router module shall call the
	 * 						 upper layer module using <Up>_TpTxConfirmation after receiving the last
	 * 						 PduR_<LoTp>TxConfirmation from the lower layer transport protocol modules.
	 * 						 The 'result' parameter shall be (Std_ReturnType)E_OK if at least one
	 * 						 PduR_<LoTp> TxConfirmation reported (Std_ReturnType)E_OK
	 */
	if(DestPduNum >(uint16) 1)
	{
		if(((Std_ReturnType)E_OK == Ret) && ((boolean)TRUE == PathIsEnabled[SrcPduId]))
		{
			PduR_UpTxConfirmation[PduR_ConfigData->PduRSrcPduRef[SrcPduId].UpTxconfirmStateIndex] = \
					(boolean)TRUE;
		}
		if(PduR_UpTxTpMulRoute[PduR_ConfigData->PduRSrcPduRef[SrcPduId].TxTpMulticastIndex].\
				ActiveDestNumber >(uint16) 0)
		{
			PduR_UpTxTpMulRoute[PduR_ConfigData->PduRSrcPduRef[SrcPduId].TxTpMulticastIndex].\
			ActiveDestNumber--;
			if(0u == PduR_UpTxTpMulRoute[PduR_ConfigData->PduRSrcPduRef[SrcPduId].TxTpMulticastIndex].\
					ActiveDestNumber)
			{
				if(PduRUp_TpTxConfirmation[srcModuleType] != NULL_PTR)
				{
					if((boolean)TRUE == PduR_UpTxConfirmation[PduR_ConfigData->PduRSrcPduRef[SrcPduId].\
															  UpTxconfirmStateIndex])
					{
						PduRUp_TpTxConfirmation[srcModuleType](actualUpPduId, (Std_ReturnType)E_OK);
					}
					else
					{
						PduRUp_TpTxConfirmation[srcModuleType](actualUpPduId, (Std_ReturnType)E_NOT_OK);
					}
				}
			}
		}
	}
	else
	{
		if(PduRUp_TpTxConfirmation[srcModuleType] != NULL_PTR)
		{
			if((boolean)TRUE == PathIsEnabled[SrcPduId])
			{
				PduRUp_TpTxConfirmation[srcModuleType](actualUpPduId, Ret);
			}
			else
			{
				PduRUp_TpTxConfirmation[srcModuleType](actualUpPduId, (Std_ReturnType)E_NOT_OK);
			}
		}
	}
}

/**
 * @brief			clear buffer and gateway state for gateway tp pdu
 * @param[in]		PduRSrcPduId : Source Pdu Id
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 */
STATIC FUNC(void, PDUR_CODE)
PduR_ClearGateWayTpBufferAndState(
	VAR(uint16, PDUR_VAR) PduRSrcPduId
)
{
	uint8 cnt;
	uint16 txBuffeIndex;
	uint16 tpRunTimeIndex;
	uint8 destPduNum;
	destPduNum = PduR_ConfigData->PduRRoutingTableRef[PduRSrcPduId].DestPduNumber;
	/* clear gateway tp dest pdu run time state */
	for (cnt = (uint8)0; cnt < (uint8)destPduNum; cnt++)
	{
		tpRunTimeIndex = PduR_ConfigData->PduRRoutingTableRef[PduRSrcPduId].PduRDestPduIdRef[cnt].\
				GateWayTpRunTimeIndex;
		PduR_GateWayDestTpSate[tpRunTimeIndex].ActiveTpBufferId = (uint8)0xff;
		PduR_GateWayDestTpSate[tpRunTimeIndex].TpTxConfirmation = (boolean)TRUE;
		PduR_GateWayDestTpSate[tpRunTimeIndex].TxBufferOffset = (uint16)0;
		PduR_GateWayDestTpSate[tpRunTimeIndex].CopyCompleteTpBufferNumber = (uint8)0;
		PduR_GateWayDestTpSate[tpRunTimeIndex].IsGateWayOnTheFly = (boolean)FALSE;
	}
	if((boolean)FALSE == PduR_ConfigData->PduRRoutingTableRef[PduRSrcPduId].RouteIsTp)
	{
		#if(PDUR_TP_BUFFER_SUM > 0)
		/* clear tp buffer */
		for(cnt = 0u;cnt < (uint8)PDUR_TP_BUFFER_SUM;cnt++)
		{
			/* Remove the corresponding pbuffer buffer for the corresponding pdu */
			if(((boolean)TRUE == PduR_TpBuffer[cnt].used) && (PduRSrcPduId == PduR_TpBuffer[cnt].\
					PduHandleId))
			{
				PduR_TpBuffer[cnt].NextTpBufferId = 0xffu;
				PduR_TpBuffer[cnt].PduHandleId = 0xffffu;
				PduR_TpBuffer[cnt].RxBufferOffset = 0u;
				PduR_TpBuffer[cnt].SduLength = 0u;
				PduR_TpBuffer[cnt].used = (boolean)FALSE;
			}
		}
		#endif/* PDUR_TP_BUFFER_SUM > 0 */
	}
	/* clear dedicated buffer */
	else
	{
		for(cnt = (uint8)0;cnt < (uint8)destPduNum;cnt++)
		{
			/* Remove the buffer that is specially set by the frame */
			txBuffeIndex = PduR_ConfigData->PduRRoutingTableRef[PduRSrcPduId].PduRDestPduIdRef[cnt].\
					PduRDestTxBufferRef;
			PduR_TpBuffer[txBuffeIndex].SduLength = (uint16)0;
			PduR_TpBuffer[txBuffeIndex].used = (boolean)FALSE;
		}
	}
	return;
}

/**
 * @brief			check wether has pdu is not confirmation
 * @param[in]		PduRSrcPduId : Source Pdu Id
 * @param[out]		/
 * @param[in/out]	/
 * @return			boolean
 * @retval			TRUE
 * 					FALSE
 */
STATIC FUNC(boolean, PDUR_CODE)
PduR_AtLeastOneDestIsNotTxConfirm(
	VAR(uint16, PDUR_VAR) PduRSrcPduId
)
{
	boolean ret = (boolean)FALSE;
	uint8 pduDestSum;
	PduIdType tpRunTimeIndex;
	uint16 num;
	pduDestSum = PduR_ConfigData->PduRRoutingTableRef[PduRSrcPduId].DestPduNumber;
	/* (Num < pduDestSum) && ((boolean)FALSE == retValue) When the retvalue value changes, jump out of
	 *  the loop */
	for (num = (uint8)0; (num < (uint8)pduDestSum) && ((boolean)FALSE == ret); num++)
	{
		tpRunTimeIndex = PduR_ConfigData->PduRRoutingTableRef[PduRSrcPduId].PduRDestPduIdRef[num].\
				GateWayTpRunTimeIndex;
		if(((uint16)0xffff != tpRunTimeIndex) && ((uint16)(boolean)FALSE == PduR_GateWayDestTpSate\
				[tpRunTimeIndex].TpTxConfirmation))
		{
			ret = (boolean)TRUE;
		}
	}
	return ret;
}

#endif/* STD_ON == PDUR_TP_SUPPORT */

#define PDUR_STOP_SEC_CODE
#include "PduR_MemMap.h"

#endif/* STD_OFF == PDUR_ZERO_COST_OPERATION */

#ifdef __cplusplus
}
#endif

/** @} */

