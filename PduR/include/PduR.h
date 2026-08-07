/**
 * @file        PduR.h
 * @brief       Module header file of PduR, including version information,
 *              type definitions and all service interface declarations.
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

#ifndef  PDUR_H
#define  PDUR_H

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
/*@req [SWS_PduR_00216] The PDU Router module shall provide the functions used by the different modules
 * 						in separate header files.*/
/*@req [SWS_PduR_00801] Depending on configuration (see PduRBswModules), the PduR implementation shall
 * 						include the <module>.h and <module>_Cbk.h header files. <module>.h provides the
 * 						API of lower layer modules, while <module>_Cbk.h provides the callbacks of upper
 * 						layer modules.*/
#include "PduR_Types.h"

#include "PduR_Cfg.h"

#if(STD_ON == PDUR_CANIF_SUPPORT)
#include "CanIf.h"
#include "CanIf_Cbk.h"
#endif/* STD_ON == PDUR_CANIF_SUPPORT */

#if(STD_ON == PDUR_CANTP_SUPPORT)
#include "CanTp.h"
#include "CanTp_Cbk.h"
#endif/* STD_ON == PDUR_CANTP_SUPPORT */

#if(STD_ON == PDUR_J1939TP_SUPPORT)
#include "J1939Tp.h"
#include "J1939Tp_Cbk.h"
#endif/* STD_ON == PDUR_J1939TP_SUPPORT */

#if(STD_ON == PDUR_COM_SUPPORT)
#include "Com.h"
#include "Com_Cbk.h"
#endif/* STD_ON == PDUR_COM_SUPPORT */

#if(STD_ON == PDUR_DCM_SUPPORT)
#include "Dcm.h"
#include "Dcm_Cbk.h"
#endif/* STD_ON == PDUR_DCM_SUPPORT */

#if(STD_ON == PDUR_J1939DCM_SUPPORT)
#include "J1939Dcm.h"
#include "J1939Dcm_Cbk.h"
#endif/* STD_ON == PDUR_J1939DCM_SUPPORT */

#if(STD_ON == PDUR_IPDUM_SUPPORT)
#include "IpduM.h"
#include "IpduM_Cbk.h"
#endif/* STD_ON == PDUR_IPDUM_SUPPORT */

#if(STD_ON == PDUR_J1939RM_SUPPORT)
#include "J1939Rm.h"
#include "J1939Rm_Cbk.h"
#endif/* STD_ON == PDUR_J1939RM_SUPPORT */

#if(STD_ON == PDUR_LDCOM_SUPPORT)
#include "LdCom.h"
#include "LdCom_Cbk.h"
#endif/* STD_ON == PDUR_LDCOM_SUPPORT */

#if(STD_ON == PDUR_SECOC_SUPPORT)
#include "SecOC.h"
#include "SecOC_Cbk.h"
#endif/* STD_ON == PDUR_SECOC_SUPPORT */

#if(STD_ON == PDUR_DBG_SUPPORT)
#include "Dbg.h"
#include "Dbg_Cbk.h"
#endif/* STD_ON == PDUR_DBG_SUPPORT */

#if(STD_ON == PDUR_CANNM_SUPPORT)
#include "CanNm.h"
#include "CanNm_Cbk.h"
#endif/* STD_ON == PDUR_CANNM_SUPPORT */

#if(STD_ON == PDUR_LINIF_SUPPORT)
#include "LinIf.h"
#include "LinIf_Cbk.h"
#endif/* STD_ON == PDUR_LINIF_SUPPORT */

#if(STD_ON == PDUR_FRIF_SUPPORT)
#include "FrIf.h"
#include "FrIf_Cbk.h"
#endif/* STD_ON == PDUR_FRIF_SUPPORT */

#if(STD_ON == PDUR_FRNM_SUPPORT)
#include "FrNm.h"
#include "FrNm_Cbk.h"
#endif/* STD_ON == PDUR_FRNM_SUPPORT */

#if(STD_ON == PDUR_SOAD_SUPPORT)
#include "SoAd.h"
#endif/* STD_ON == PDUR_SOAD_SUPPORT */

/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/
/*@req [SWS_PduR_00217] The Module ID of the PDU Router module shall be 51 (decimal).*/
#define PDUR_VENDOR_ID               		0U
#define PDUR_MODULE_ID               		51U
#define PDUR_AR_RELEASE_MAJOR_VERSION		4U
#define PDUR_AR_RELEASE_MINOR_VERSION		2U
#define PDUR_AR_RELEASE_REVISION_VERSION	2U
#define PDUR_SW_MAJOR_VERSION      			1U
#define PDUR_SW_MINOR_VERSION      			2U
#define PDUR_SW_PATCH_VERSION      			0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and PduR_Types.h header file are of the same vendor */
#if(PDUR_VENDOR_ID != PDUR_TYPES_VENDOR_ID )
#error "PduR.h and PduR_Types.h have different vendor id"
#endif

#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION != PDUR_TYPES_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION != PDUR_TYPES_AR_RELEASE_MINOR_VERSION) || \
      (PDUR_AR_RELEASE_REVISION_VERSION != PDUR_TYPES_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of PduR.h and PduR_Types.h are different "
#endif

/* Check if current file and PduR_Types.h header file are of the same software version */
#if(\
      (PDUR_SW_MAJOR_VERSION != PDUR_TYPES_SW_MAJOR_VERSION) || \
      (PDUR_SW_MINOR_VERSION != PDUR_TYPES_SW_MINOR_VERSION) ||\
	  (PDUR_SW_PATCH_VERSION != PDUR_TYPES_SW_PATCH_VERSION)\
      )
#error "Software Version Number of PduR.h and PduR_Types.h are different "
#endif


#ifndef DISABLE_INTERMOD_VERSION_CHECK
#if(STD_ON == PDUR_CANTP_SUPPORT)
#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION != CANTP_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION != CANTP_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of PduR.h and CanTp.h are different "
#endif

#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION != CANTP_CBK_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION != CANTP_CBK_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of PduR.h and CanTp_Cbk.h are different "
#endif
#endif

#if(STD_ON == PDUR_CANIF_SUPPORT)
#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION != CANIF_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION != CANIF_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of PduR.h and CanIf.h are different "
#endif

#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION != CANIF_CBK_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION != CANIF_CBK_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of PduR.h and CanIf_Cbk.h are different "
#endif
#endif

#if(STD_ON == PDUR_J1939TP_SUPPORT)
#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION != J1939TP_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION != J1939TP_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of PduR.h and J1939Tp.h are different "
#endif

#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION != J1939TP_CBK_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION != J1939TP_CBK_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of PduR.h and J1939Tp_Cbk.h are different "
#endif
#endif

#if(STD_ON == PDUR_COM_SUPPORT)
#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION != COM_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION != COM_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of PduR.h and Com.h are different "
#endif

#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION != COM_CBK_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION != COM_CBK_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of PduR.h and Com_Cbk.h are different "
#endif
#endif

#if(STD_ON == PDUR_DCM_SUPPORT)
#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION != DCM_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION != DCM_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of PduR.h and Dcm.h are different "
#endif

#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION != DCM_CBK_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION != DCM_CBK_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of PduR.h and Dcm_Cbk.h are different "
#endif
#endif

#if(STD_ON == PDUR_J1939DCM_SUPPORT)
#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION != J1939DCM_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION != J1939DCM_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of PduR.h and J1939Dcm.h are different "
#endif

#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION != J1939DCM_CBK_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION != J1939DCM_CBK_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of PduR.h and J1939Dcm_Cbk.h are different "
#endif
#endif

#if(STD_ON == PDUR_IPDUM_SUPPORT)
#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION != IPDUM_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION != IPDUM_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of PduR.h and IpduM.h are different "
#endif

#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION != IPDUM_CBK_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION != IPDUM_CBK_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of PduR.h and IpduM_Cbk.h are different "
#endif
#endif

#if(STD_ON == PDUR_J1939RM_SUPPORT)
#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION != J1939RM_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION != J1939RM_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of PduR.h and J1939Rm.h are different "
#endif

#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION != J1939RM_CBK_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION != J1939RM_CBK_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of PduR.h and J1939Rm_Cbk.h are different "
#endif
#endif

#if(STD_ON == PDUR_LDCOM_SUPPORT)
#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION != LDCOM_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION != LDCOM_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of PduR.h and LdCom.h are different "
#endif

#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION != LDCOM_CBK_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION != LDCOM_CBK_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of PduR.h and LdCom_Cbk.h are different "
#endif
#endif

#if(STD_ON == PDUR_SECOC_SUPPORT)
#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION != SECOC_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION != SECOC_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of PduR.h and SecOC.h are different "
#endif

#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION != SECOC_CBK_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION != SECOC_CBK_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of PduR.h and SecOC_Cbk.h are different "
#endif
#endif

#if(STD_ON == PDUR_DBG_SUPPORT)
#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION != DBG_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION != DBG_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of PduR.h and Dbg.h are different "
#endif

#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION != DBG_CBK_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION != DBG_CBK_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of PduR.h and Dbg_Cbk.h are different "
#endif
#endif

#if(STD_ON == PDUR_CANNM_SUPPORT)
#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION != CANNM_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION != CANNM_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of PduR.h and CanNm.h are different "
#endif

#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION != CANNM_CBK_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION != CANNM_CBK_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of PduR.h and CanNm_Cbk.h are different "
#endif

#endif

#if(STD_ON == PDUR_LINIF_SUPPORT)
#if(\
     (PDUR_AR_RELEASE_MAJOR_VERSION != LINIF_AR_RELEASE_MAJOR_VERSION) || \
     (PDUR_AR_RELEASE_MINOR_VERSION != LINIF_AR_RELEASE_MINOR_VERSION) \
     )
#error "AutoSar Version Number of PduR.h and LinIf.h are different "
#endif


#if(\
     (PDUR_AR_RELEASE_MAJOR_VERSION != LINIF_CBK_AR_RELEASE_MAJOR_VERSION) || \
     (PDUR_AR_RELEASE_MINOR_VERSION != LINIF_CBK_AR_RELEASE_MINOR_VERSION) \
     )
#error "AutoSar Version Number of PduR.h and LinIf_Cbk.h are different "
#endif

#endif

#if(STD_ON == PDUR_FRIF_SUPPORT)
#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION != FRIF_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION != FRIF_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of PduR.h and FrIf.h are different "
#endif


#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION != FRIF_CBK_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION != FRIF_CBK_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of PduR.h and FrIf_Cbk.h are different "
#endif

#endif

#if(STD_ON == PDUR_FRNM_SUPPORT)
#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION != FRNM_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION != FRNM_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of PduR.h and FrNm.h are different "
#endif

#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION != FRNM__CBK_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION != FRNM__CBK_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of PduR.h and FrNm_Cbk.h are different "
#endif
#endif

#if(STD_ON == PDUR_SOAD_SUPPORT)
#if(\
      (PDUR_AR_RELEASE_MAJOR_VERSION != SOAD_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_AR_RELEASE_MINOR_VERSION != SOAD_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of PduR.h and SoAd.h are different "
#endif

#endif

#endif

/*====================================================================================================*
 *                                             CONSTANTS
 *====================================================================================================*/

/*====================================================================================================*
 *                                         DEFINES AND MACROS
 *====================================================================================================*/
#if(STD_OFF == PDUR_ZERO_COST_OPERATION)

/*@req [SWS_PduR_00292] General PDU Router module definitions shall be defined in PduR.h.*/
#if(STD_ON == PDUR_DEV_ERROR_DETECT)
#define PDUR_INSTANCE_ID			0u
/* General function id */
#define PDUR_SID_INIT                       	 ((uint8)0xf0u)
#define PDUR_SID_GETVERSIONINFO               	 ((uint8)0xf1u)
#define PDUR_SID_GETCONFIGURATIONID              ((uint8)0xf2u)
#define PDUR_SID_ENABLEROUTING                   ((uint8)0xf3u)
#define PDUR_SID_DISABLEROUTING                  ((uint8)0xf4u)
/* CanIf function id */
#define PDUR_SID_CANIFRXINDICATION               ((uint8)0x01u)
#define PDUR_SID_CANIFTXCONFIRMATION             ((uint8)0x02u)
#define PDUR_SID_CANIFTRIGGERTRANSMIT            ((uint8)0x03u)
/* LinIf function id */
#define PDUR_SID_LINIFRXINDICATION               ((uint8)0x51u)
#define PDUR_SID_LINIFTXCONFIRMATION             ((uint8)0x52u)
#define PDUR_SID_LINIFTRIGGERTRANSMIT            ((uint8)0x53u)
/* CanNm function id */
#define PDUR_SID_CANNMRXINDICATION               ((uint8)0x11u)
#define PDUR_SID_CANNMTXCONFIRMATION             ((uint8)0x12u)
#define PDUR_SID_CANNMTRIGGERTRANSMIT            ((uint8)0x13u)
/*CanTP function id */
#define PDUR_SID_CANTPCOPYRXDATA                 ((uint8)0x04u)
#define PDUR_SID_CANTPRXINDICATION               ((uint8)0x05u)
#define PDUR_SID_CANTPSTARTOFRECEPTION           ((uint8)0x06u)
#define PDUR_SID_CANTPCOPYTXDATA                 ((uint8)0x07u)
#define PDUR_SID_CANTPTXCONFIRMATION             ((uint8)0x08u)
/*LinTP function id */
#define PDUR_SID_LINTPCOPYRXDATA                 ((uint8)0x54u)
#define PDUR_SID_LINTPRXINDICATION               ((uint8)0x55u)
#define PDUR_SID_LINTPSTARTOFRECEPTION           ((uint8)0x56u)
#define PDUR_SID_LINTPCOPYTXDATA                 ((uint8)0x57u)
#define PDUR_SID_LINTPTXCONFIRMATION             ((uint8)0x58u)
/*J1939CanTP function id */
#define PDUR_SID_J1939TPCOPYRXDATA               ((uint8)0x14u)
#define PDUR_SID_J1939TPRXINDICATION             ((uint8)0x15u)
#define PDUR_SID_J1939TPSTARTOFRECEPTION         ((uint8)0x16u)
#define PDUR_SID_J1939TPCOPYTXDATA               ((uint8)0x17u)
#define PDUR_SID_J1939TPTXCONFIRMATION           ((uint8)0x18u)
/* Com function id */
#define PDUR_SID_COMTRANSMIT            		 ((uint8)0x89u)
#define PDUR_SID_COMCANCELTRANSMIT               ((uint8)0x8au)
#define PDUR_SID_COMCHANGEPARAMETER              ((uint8)0x8bu)
#define PDUR_SID_COMCANCELRECEIVE                ((uint8)0x8cu)

/* LdCom function id */
#define PDUR_SID_LDCOMTRANSMIT            		 ((uint8)0x89u)
#define PDUR_SID_LDCOMCANCELTRANSMIT             ((uint8)0x8au)
#define PDUR_SID_LDCOMCHANGEPARAMETER            ((uint8)0x8bu)
#define PDUR_SID_LDCOMCANCELRECEIVE              ((uint8)0x8cu)

/* SecOC function id */
#define PDUR_SID_SECOCTRANSMIT            	     ((uint8)0xc9u)
#define PDUR_SID_SECOCCANCELTRANSMIT             ((uint8)0xcau)
#define PDUR_SID_SECOCRXINDICATION               ((uint8)0x71u)
#define PDUR_SID_SECOCTXCONFIRMATION             ((uint8)0x72u)

/* IpduM function id */
#define PDUR_SID_IPDUMTRANSMIT            	     ((uint8)0xa9u)
#define PDUR_SID_IPDUMTRIGGERTRANSMIT            ((uint8)0x23u)
#define PDUR_SID_IPDUMRXINDICATION               ((uint8)0x21u)
#define PDUR_SID_IPDUMTXCONFIRMATION             ((uint8)0x22u)

/* J1939Rm function id */
#define PDUR_SID_J1939RMTRANSMIT            	 ((uint8)0xe9u)
#define PDUR_SID_J1939RMCANCELTRANSMIT           ((uint8)0xeau)
/* Dcm function id */
#define PDUR_SID_DCMTRANSMIT            		 ((uint8)0x99u)
#define PDUR_SID_DCMCANCELTRANSMIT               ((uint8)0x9au)
#define PDUR_SID_DCMCHANGEPARAMETER              ((uint8)0x9bu)
#define PDUR_SID_DCMCANCELRECEIVE                ((uint8)0x9cu)
/* J1939Dcm function id */
#define PDUR_SID_J1939DCMTRANSMIT            	 ((uint8)0xf9u)
#define PDUR_SID_J1939DCMCANCELTRANSMIT          ((uint8)0xfau)
#define PDUR_SID_J1939DCMCHANGEPARAMETER         ((uint8)0xfbu)
#define PDUR_SID_J1939DCMCANCELRECEIVE           ((uint8)0xfcu)

/* SoAd function id */
#define PDUR_SID_SOADRXINDICATION               ((uint8)0x61u)
#define PDUR_SID_SOADTXCONFIRMATION             ((uint8)0x62u)
#define PDUR_SID_SOADTRIGGERTRANSMIT            ((uint8)0x63u)

/*SoAdTP function id */
#define PDUR_SID_SOADTPCOPYRXDATA                 ((uint8)0x64u)
#define PDUR_SID_SOADTPRXINDICATION               ((uint8)0x65u)
#define PDUR_SID_SOADTPSTARTOFRECEPTION           ((uint8)0x66u)
#define PDUR_SID_SOADTPCOPYTXDATA                 ((uint8)0x67u)
#define PDUR_SID_SOADTPTXCONFIRMATION             ((uint8)0x68u)

/*@req [SWS_PDUR_00816] [SWS_PduR_00100]*/
#define PDUR_E_PARAM_POINTER	             ((uint8)0x09u)
#define PDUR_E_PDU_INSTANCES_LOST            ((uint8)0x0au)
#define PDUR_E_INIT_FAILED					 ((uint8)0x00u)
#define PDUR_E_INVALID_REQUEST               ((uint8)0x01u)
#define PDUR_E_PDU_ID_INVALID                ((uint8)0x02u)
#define PDUR_E_TP_TX_REQ_REJECTED            ((uint8)0x03u)
#define PDUR_E_ROUTING_PATH_GROUP_ID_INVALID ((uint8)0x08u)

#define PDUR_DET_ERROR_REPORT(ApiId,ErrorId)     (\
                         (void)Det_ReportError(\
                                PDUR_MODULE_ID,\
                                PDUR_INSTANCE_ID,\
                                            (ApiId),\
                                            (ErrorId)))
#else
#define LDCOM_DET_REPORT(ApiId,ErrorId)


#endif/* STD_ON == PDUR_DEV_ERROR_DETECT */

/*====================================================================================================*
 *                                               ENUMS
 *====================================================================================================*/
/**
 * @brief define the PduR State Struct
*/
typedef enum
{
    PDUR_BUSY = 0u,
    PDUR_IDLE
} PduR_DestStateType;

/**
 * @brief choose which selection way to use
 */
typedef enum
{
	UNIVERSAL = 0u,
	LOCAL
}PduR_ModeChoiceType;

/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS
 *====================================================================================================*/
/**
 * @brief runtime gateway state
 */
typedef struct
{
	/** <@brief gateway-on-the-fly mode,decide the pdu need call transmit API or not*/
	boolean IsGateWayOnTheFly;
	/** <@brief real TpBuffer Id*/
	uint8 ActiveTpBufferId;
	/** <@brief gateway-on-the-fly mode(1:n),used to decide the tp buffer(all dest have copyed) need
	 * to be cleared*/
	uint8 CopyCompleteTpBufferNumber;
	/** <@brief gateway tp(MF),record where to copy data*/
	uint16 TxBufferOffset;
	/** <@brief E_OK or E_NOT_OK*/
	boolean TpTxConfirmation;
}PduR_GateWayDestTpRunTimeType;

/**
 * @brief mask gateway Tp Pdu
 */
typedef struct
{
	/** <@brief dest copy data time*/
	uint8 DestCopyDataTimer;
	/** <@brief real dest num*/
	uint8 ActiveDestNumber;
}PduR_UpTxTpMulPduRunTimeType;

/*====================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS
 *====================================================================================================*/
extern CONST(PduR_PBConfigType, PDUR_CONST_PBCFG) PduR_Config;

#if(PDUR_TP_BUFFER_SUM > 0)
extern PduR_TpBufferTableType PduR_TpBuffer[PDUR_TP_BUFFER_SUM];
#else
extern P2VAR(PduR_TpBufferTableType, AUTOMATIC, PDUR_APPL_DATA) PduR_TpBuffer;
#endif/* PDUR_TP_BUFFER_SUM > 0 */

#if(PDUR_TX_BUFFER_SUM > 0)
extern PduR_TxBufferTableType PduR_TxBuffer[PDUR_TX_BUFFER_SUM];
#else
extern P2VAR(PduR_TxBufferTableType, AUTOMATIC, PDUR_APPL_DATA) PduR_TxBuffer;
#endif/* PDUR_TX_BUFFER_SUM > 0 */

#if(PDUR_DEFAULT_VALUE_LENGTH > 0)
extern const uint8 PduR_Default_value[PDUR_DEFAULT_VALUE_LENGTH];
#else
extern CONSTP2CONST(uint8, AUTOMATIC, PDUR_APPL_DATA) PduR_Default_value;
#endif/* PDUR_DEFAULT_VALUE_LENGTH > 0 */

#if(PDUR_BSW_MODULE_SUM > 0)
extern const PduRBswModuleType PduR_BswModuleConfigData[PDUR_BSW_MODULE_SUM];
#else
extern CONSTP2CONST(PduRBswModuleType, AUTOMATIC, PDUR_APPL_DATA) PduR_BswModuleConfigData;
#endif/* PDUR_BSW_MODULE_SUM > 0 */

extern CONST(PduRLowTransmitFunctionType, PDUR_CONST)
PduRLo_Transmit[PDUR_MAX_BUSTYPE_NUMBER];

extern CONST(PduRUpRxIndicationFunctionType, PDUR_CONST)
PduRUp_RxIndication[PDUR_MAX_BUSTYPE_NUMBER];

extern CONST(PduRUpTxConfirmationFunctionType, PDUR_CONST)
PduRUp_TxConfirmation[PDUR_MAX_BUSTYPE_NUMBER];

extern CONST(PduRUpTriggerTransmitFunctionType, PDUR_CONST)
PduRUp_TriggerTransmit[PDUR_MAX_BUSTYPE_NUMBER];

extern CONST(PduRUpTpRxIndicationFunctionType, PDUR_CONST)
PduRUp_TpRxIndication[PDUR_MAX_BUSTYPE_NUMBER];

extern CONST(PduRUpTpStartOfReceptionFunctionType, PDUR_CONST)
PduRUp_TpStartOfReception[PDUR_MAX_BUSTYPE_NUMBER];

extern CONST(PduRUpTpCopyRxDataFunctionType, PDUR_CONST)
PduRUp_TpCopyRxData[PDUR_MAX_BUSTYPE_NUMBER];

extern CONST(PduRUpTpCopyTxDataFunctionType, PDUR_CONST)
PduRUp_TpCopyTxData[PDUR_MAX_BUSTYPE_NUMBER];

extern CONST(PduRUpTpTxConfirmationFunctionType, PDUR_CONST)
PduRUp_TpTxConfirmation[PDUR_MAX_BUSTYPE_NUMBER];

extern CONST(PduRCancelTransmitFunctionType, PDUR_CONST)
PduRUp_CancelTransmit[PDUR_MAX_BUSTYPE_NUMBER];

extern CONST(PduRCancelReceiveFunctionType, PDUR_CONST)
PduRUp_CancelReceive[PDUR_MAX_BUSTYPE_NUMBER];

extern CONST(PduRChangeParameterFunctionType, PDUR_CONST)
PduRUp_ChangeParameter[PDUR_MAX_BUSTYPE_NUMBER];

/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES
 *====================================================================================================*/
#define PDUR_START_SEC_CODE
#include "PduR_MemMap.h"
extern FUNC(void, PDUR_CODE)
PduR_GetVersionInfo(
	P2VAR(Std_VersionInfoType, AUTOMATIC,PDUR_APPL_DATA) versionInfo
);

extern FUNC(void, PDUR_CODE)
PduR_Init(
	P2CONST(PduR_PBConfigType, AUTOMATIC, PDUR_APPL_DATA) ConfigPtr
);

extern FUNC(PduR_PBConfigIdType, PDUR_CODE)
PduR_GetConfigurationId(
	void
);

extern FUNC(void, PDUR_CODE)
PduR_EnableRouting(
	VAR(PduR_RoutingPathGroupIdType, PDUR_VAR) id
);

extern FUNC(void, PDUR_CODE)
PduR_DisableRouting(
	VAR(PduR_RoutingPathGroupIdType, PDUR_VAR) id,
	VAR(boolean, PDUR_VAR) initialize
);

#define PDUR_STOP_SEC_CODE
#include "PduR_MemMap.h"
#endif/* STD_OFF == PDUR_ZERO_COST_OPERATION */

#ifdef __cplusplus
}
#endif

#endif  /* end of PDUR_H */
/** @} */
