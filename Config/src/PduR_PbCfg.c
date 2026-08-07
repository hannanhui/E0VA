/**
* @file        PduR_PbCfg.c
* @brief       configuration file for PduR
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

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
#include "PduR.h"

/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION
 *====================================================================================================*/
#define PDUR_PBCFG_VENDOR_ID_C               		0U
#define PDUR_PBCFG_AR_RELEASE_MAJOR_VERSION_C		4U
#define PDUR_PBCFG_AR_RELEASE_MINOR_VERSION_C		2U
#define PDUR_PBCFG_AR_RELEASE_REVISION_VERSION_C	2U
#define PDUR_PBCFG_SW_MAJOR_VERSION_C      			1U
#define PDUR_PBCFG_SW_MINOR_VERSION_C      			2U
#define PDUR_PBCFG_SW_PATCH_VERSION_C      			0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and PduR_Types.h header file are of the same vendor */
#if(PDUR_PBCFG_VENDOR_ID_C != PDUR_VENDOR_ID )
#error "PduR_PbCfg.c and PduR.h have different vendor id"
#endif

#if(\
      (PDUR_PBCFG_AR_RELEASE_MAJOR_VERSION_C != PDUR_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_PBCFG_AR_RELEASE_MINOR_VERSION_C != PDUR_AR_RELEASE_MINOR_VERSION) || \
      (PDUR_PBCFG_AR_RELEASE_REVISION_VERSION_C != PDUR_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of PduR_PbCfg.c and PduR.h are different "
#endif

/* Check if current file and PduR.h header file are of the same software version */
#if(\
      (PDUR_PBCFG_SW_MAJOR_VERSION_C != PDUR_SW_MAJOR_VERSION) || \
      (PDUR_PBCFG_SW_MINOR_VERSION_C != PDUR_SW_MINOR_VERSION) ||\
	  (PDUR_PBCFG_SW_PATCH_VERSION_C != PDUR_SW_PATCH_VERSION)\
      )
#error "Software Version Number of PduR_PbCfg.c and PduR.h are different "
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

/*====================================================================================================*
 *                                           LOCAL CONSTANTS
 *====================================================================================================*/

/*====================================================================================================*
 *                                           LOCAL VARIABLES
 *====================================================================================================*/

/*====================================================================================================*
 *                                      LOCAL FUNCTION PROTOTYPES
 *====================================================================================================*/

/*====================================================================================================*
 *                                           LOCAL FUNCTIONS
 *====================================================================================================*/

/*====================================================================================================*
 *                                          GLOBAL FUNCTIONS
 *====================================================================================================*/

#define PDUR_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
CONST(PduRLowTransmitFunctionType, PDUR_CONST) PduRLo_Transmit[PDUR_MAX_BUSTYPE_NUMBER] =
{
#if(STD_ON == PDUR_COM_SUPPORT)
    NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_LDCOM_SUPPORT)
    NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_IPDUM_SUPPORT)
	IpduM_Transmit,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_SECOC_SUPPORT)
	SecOC_Transmit,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_DCM_SUPPORT)
    NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_J1939DCM_SUPPORT)
    NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_J1939RM_SUPPORT)
    NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_CANIF_SUPPORT)
    CanIf_Transmit,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_CANTP_SUPPORT)
	CanTp_Transmit,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_J1939TP_SUPPORT)
	J1939Tp_Transmit,
#else
    NULL_PTR,
#endif

#if(STD_ON == PDUR_CANNM_SUPPORT)
	CanNm_Transmit,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_LINIF_SUPPORT)
	LinIf_Transmit,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_LINTP_SUPPORT)
	LinTp_Transmit,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_FRIF_SUPPORT)
	FrIf_Transmit,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_SOADIF_SUPPORT)
	SoAd_IfTransmit,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_SOADTP_SUPPORT)
	SoAd_TpTransmit,
#else
    NULL_PTR,
#endif
};

CONST(PduRUpRxIndicationFunctionType, PDUR_CONST) PduRUp_RxIndication[PDUR_MAX_BUSTYPE_NUMBER] =
{
#if(STD_ON == PDUR_COM_SUPPORT)
    Com_RxIndication,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_LDCOM_SUPPORT)
    LdCom_RxIndication,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_IPDUM_SUPPORT)
	IpduM_RxIndication,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_SECOC_SUPPORT)
    Secoc_Rxindication,
#else
    NULL_PTR,
#endif

#if(STD_ON == PDUR_DCM_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_J1939DCM_SUPPORT)
	J1939Dcm_RxIndication,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_J1939RM_SUPPORT)
	J1939Rm_RxIndication,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_CANIF_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_CANTP_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_J1939TP_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_CANNM_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_LINIF_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_LINTP_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_FRIF_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_SOADIF_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_SOADTP_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
};

CONST(PduRUpTxConfirmationFunctionType, PDUR_CONST) PduRUp_TxConfirmation[PDUR_MAX_BUSTYPE_NUMBER] =
{
#if(STD_ON == PDUR_COM_SUPPORT)
	Com_TxConfirmation,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_LDCOM_SUPPORT)
	LdCom_TxConfirmation,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_IPDUM_SUPPORT)
	IpduM_TxConfirmation,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_SECOC_SUPPORT)
	SecOC_TxConfirmation,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_DCM_SUPPORT)
	Dcm_TxConfirmation,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_J1939DCM_SUPPORT)
	J1939Dcm_TxConfirmation,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_J1939RM_SUPPORT)
	J1939Rm_TxConfirmation,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_CANIF_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_CANTP_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_J1939TP_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_CANNM_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_LINIF_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_LINTP_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_FRIF_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_SOADIF_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_SOADTP_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
};

CONST(PduRUpTriggerTransmitFunctionType, PDUR_CONST) PduRUp_TriggerTransmit[PDUR_MAX_BUSTYPE_NUMBER] =
{
#if(STD_ON == PDUR_COM_SUPPORT)
	Com_TriggerTransmit,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_LDCOM_SUPPORT)
	LdCom_TriggerTransmit,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_IPDUM_SUPPORT)
	IpduM_TriggerTransmit,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_SECOC_SUPPORT)
	SecOC_TriggerTransmit,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_DCM_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_J1939DCM_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_J1939RM_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_CANIF_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_CANTP_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_J1939TP_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_CANNM_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_LINIF_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_LINTP_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_FRIF_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_SOADIF_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_SOADTP_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
};

CONST(PduRUpTpRxIndicationFunctionType, PDUR_CONST) PduRUp_TpRxIndication[PDUR_MAX_BUSTYPE_NUMBER] =
{
#if(STD_ON == PDUR_COM_SUPPORT)
	Com_TpRxIndication,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_LDCOM_SUPPORT)
	LdCom_TpRxIndication,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_IPDUM_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_SECOC_SUPPORT)
	SecOC_TpRxIndication,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_DCM_SUPPORT)
	Dcm_TpRxIndication,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_J1939DCM_SUPPORT)
	J1939Dcm_TpRxIndication,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_J1939RM_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_CANIF_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_CANTP_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_J1939TP_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_CANNM_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_LINIF_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_LINTP_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_FRIF_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_SOADIF_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_SOADTP_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
};


CONST(PduRUpTpStartOfReceptionFunctionType, PDUR_CONST) PduRUp_TpStartOfReception[PDUR_MAX_BUSTYPE_NUMBER] =
{
#if(STD_ON == PDUR_COM_SUPPORT)
	Com_StartOfReception,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_LDCOM_SUPPORT)
	LdCom_StartOfReception,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_IPDUM_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_SECOC_SUPPORT)
	SecOC_StartOfReception,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_DCM_SUPPORT)
	Dcm_StartOfReception,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_J1939DCM_SUPPORT)
	J1939Dcm_StartOfReception,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_J1939RM_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_CANIF_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_CANTP_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_J1939TP_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_CANNM_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_LINIF_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_LINTP_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_FRIF_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_SOADIF_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_SOADTP_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
};

CONST(PduRUpTpCopyRxDataFunctionType, PDUR_CONST) PduRUp_TpCopyRxData[PDUR_MAX_BUSTYPE_NUMBER] =
{
#if(STD_ON == PDUR_COM_SUPPORT)
	Com_CopyRxData,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_LDCOM_SUPPORT)
	LdCom_CopyRxData,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_IPDUM_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_SECOC_SUPPORT)
	SecOC_CopyRxData,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_DCM_SUPPORT)
	Dcm_CopyRxData,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_J1939DCM_SUPPORT)
	J1939Dcm_CopyRxData,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_J1939RM_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_CANIF_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_CANTP_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_J1939TP_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_CANNM_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_LINIF_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_LINTP_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_FRIF_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_SOADIF_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_SOADTP_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
};

CONST(PduRUpTpCopyTxDataFunctionType, PDUR_CONST) PduRUp_TpCopyTxData[PDUR_MAX_BUSTYPE_NUMBER] =
{
#if(STD_ON == PDUR_COM_SUPPORT)
	Com_CopyTxData,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_LDCOM_SUPPORT)
	LdCom_CopyTxData,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_IPDUM_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_SECOC_SUPPORT)
	SecOC_CopyTxData,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_DCM_SUPPORT)
	Dcm_CopyTxData,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_J1939DCM_SUPPORT)
	J1939Dcm_CopyTxData,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_J1939RM_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_CANIF_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_CANTP_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_J1939TP_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_CANNM_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_LINIF_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_LINTP_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_FRIF_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_SOADIF_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_SOADTP_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
};

CONST(PduRUpTpTxConfirmationFunctionType, PDUR_CONST) PduRUp_TpTxConfirmation[PDUR_MAX_BUSTYPE_NUMBER] =
{
#if(STD_ON == PDUR_COM_SUPPORT)
	Com_TpTxConfirmation,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_LDCOM_SUPPORT)
	LdCom_TpTxConfirmation,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_IPDUM_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_SECOC_SUPPORT)
	SecOC_TpTxConfirmation,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_DCM_SUPPORT)
	Dcm_TpTxConfirmation,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_J1939DCM_SUPPORT)
	J1939Dcm_TpTxConfirmation,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_J1939RM_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_CANIF_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_CANTP_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_J1939TP_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_CANNM_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_LINIF_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_LINTP_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_FRIF_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_SOADIF_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_SOADTP_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
};

CONST(PduRCancelTransmitFunctionType, PDUR_CONST) PduRUp_CancelTransmit[PDUR_MAX_BUSTYPE_NUMBER] =
{
#if(STD_ON == PDUR_COM_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_LDCOM_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_IPDUM_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_SECOC_SUPPORT)
	SecOC_CancelTransmit,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_DCM_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_J1939DCM_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_J1939RM_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_CANIF_SUPPORT)
#if(STD_ON == CANIF_PUBLIC_CANCEL_TRANSMIT_SUPPORT)
	CanIf_CancelTransmit,
#else
	NULL_PTR,
#endif
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_CANTP_SUPPORT)
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_J1939TP_SUPPORT)
	J1939Tp_CancelTransmit,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_CANNM_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_LINIF_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_LINTP_SUPPORT)
	//LinTp_CancelTransmit,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_FRIF_SUPPORT)
	FrIf_CancelTransmit,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_SOADIF_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_SOADTP_SUPPORT)
	SoAd_TpCancelTransmit,
#else
    NULL_PTR,
#endif
};

CONST(PduRCancelReceiveFunctionType, PDUR_CONST) PduRUp_CancelReceive[PDUR_MAX_BUSTYPE_NUMBER] =
{
#if(STD_ON == PDUR_COM_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_LDCOM_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_IPDUM_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_SECOC_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_DCM_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_J1939DCM_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_J1939RM_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_CANIF_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_CANTP_SUPPORT)
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_J1939TP_SUPPORT)
	J1939Tp_CancelReceive,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_CANNM_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_LINIF_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_LINTP_SUPPORT)
//	LinTp_CancelReceive,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_FRIF_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_SOADIF_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_SOADTP_SUPPORT)
	SoAd_TpCancelReceive,
#else
    NULL_PTR,
#endif
};

CONST(PduRChangeParameterFunctionType, PDUR_CONST) PduRUp_ChangeParameter[PDUR_MAX_BUSTYPE_NUMBER] =
{
#if(STD_ON == PDUR_COM_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_LDCOM_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_IPDUM_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_SECOC_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_DCM_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_J1939DCM_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_J1939RM_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_CANIF_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_CANTP_SUPPORT)
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_J1939TP_SUPPORT)
	J1939Tp_ChangeParameter,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_CANNM_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_LINIF_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_LINTP_SUPPORT)
	//LinTp_ChangeParameter,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_FRIF_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_SOADIF_SUPPORT)
	NULL_PTR,
#else
    NULL_PTR,
#endif
#if(STD_ON == PDUR_SOADTP_SUPPORT)
	SoAd_TpChangeParameter,
#else
    NULL_PTR,
#endif
};
#define PDUR_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */

