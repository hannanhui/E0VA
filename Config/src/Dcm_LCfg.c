/**
 * @file        Dcm_Lcfg.c
 * @brief       AUTOSAR 4.2.2 - 4.2.2 driver source file.
 * @details     Dcm driver source file, containing the C implementation of Autosar API specification
 *              and other variables and functions that are exported by the Dcm driver.
 * @version     1.2.0
 *
 * @addtogroup  Dcm
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
#include "Dcm_Internal.h"
#include "Dcm_UserCallOut.h"
/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION
 *====================================================================================================*/
#define DCM_LCFG_VENDOR_ID_C                                (0x00U)
#define DCM_LCFG_AR_RELEASE_MAJOR_VERSION_C                 (0x04U)
#define DCM_LCFG_AR_RELEASE_MINOR_VERSION_C                 (0x02U)
#define DCM_LCFG_AR_RELEASE_REVISION_VERSION_C              (0x02U)
#define DCM_LCFG_SW_MAJOR_VERSION_C                         (0x01U)
#define DCM_LCFG_SW_MINOR_VERSION_C                         (0x02U)
#define DCM_LCFG_SW_PATCH_VERSION_C                         (0x00U)
/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Dcm_Internal header file are of the same vendor */
#if(DCM_LCFG_VENDOR_ID_C != DCM_INTERNAL_VENDOR_ID )
#error "Dcm_Lcfg.c and Dcm_Internal.h have different vendor id"
#endif
/* Check if current file and Dcm_Internal header file are of the same Autosar version */
#if(\
		(DCM_LCFG_AR_RELEASE_MAJOR_VERSION_C != DCM_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_LCFG_AR_RELEASE_MINOR_VERSION_C != DCM_INTERNAL_AR_RELEASE_MINOR_VERSION) || \
		(DCM_LCFG_AR_RELEASE_REVISION_VERSION_C != DCM_INTERNAL_AR_RELEASE_REVISION_VERSION) \
)
#error "AutoSar Version Number of Dcm_Lcfg.c and Dcm_Internal.h are different"
#endif
/* Check if current file and Dcm_Internal header file are of the same software version */
#if(\
		(DCM_LCFG_SW_MAJOR_VERSION_C != DCM_INTERNAL_SW_MAJOR_VERSION) || \
		(DCM_LCFG_SW_MINOR_VERSION_C != DCM_INTERNAL_SW_MINOR_VERSION) || \
		(DCM_LCFG_SW_PATCH_VERSION_C != DCM_INTERNAL_SW_PATCH_VERSION) \
)
#error "Software Version Number of Dcm_Lcfg.c and Dcm_Internal.h are different"
#endif
/* Check if current file and Dcm_UserCallOut header file are of the same vendor */
#if(DCM_LCFG_VENDOR_ID_C != DCM_USERCALLOUT_VENDOR_ID )
#error "Dcm_Lcfg.c and Dcm_UserCallOut.h have different vendor id"
#endif
/* Check if current file and Dcm_UserCallOut header file are of the same Autosar version */
#if(\
		(DCM_LCFG_AR_RELEASE_MAJOR_VERSION_C != DCM_USERCALLOUT_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_LCFG_AR_RELEASE_MINOR_VERSION_C != DCM_USERCALLOUT_AR_RELEASE_MINOR_VERSION) || \
		(DCM_LCFG_AR_RELEASE_REVISION_VERSION_C != DCM_USERCALLOUT_AR_RELEASE_REVISION_VERSION) \
)
#error "AutoSar Version Number of Dcm_Lcfg.c and Dcm_UserCallOut.h are different"
#endif
/* Check if current file and Dcm_UserCallOut header file are of the same software version */
#if(\
		(DCM_LCFG_SW_MAJOR_VERSION_C != DCM_USERCALLOUT_SW_MAJOR_VERSION) || \
		(DCM_LCFG_SW_MINOR_VERSION_C != DCM_USERCALLOUT_SW_MINOR_VERSION) || \
		(DCM_LCFG_SW_PATCH_VERSION_C != DCM_USERCALLOUT_SW_PATCH_VERSION) \
)
#error "Software Version Number of Dcm_Lcfg.c and Dcm_UserCallOut.h are different"
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
#define DCM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dcm_MemMap.h"

CONST(Dcm_DsdSubServiceType, DCM_CONST)Dcm_DsdTable0Sid0x10SubService[3] = 
{
    {
        /* DcmDsdSubServiceUsed */
        TRUE,
        /* DcmDsdSubServiceId */
        0x1u,
        /* DcmDsdSubServiceSessionLevelRef */
        0x7u,
        /* DcmDsdSubServiceSecurityLevelRef */
        0u,
        /* DcmDsdSubServiceRxAddrType */
        DCM_FUNCTIONAL_PHYSICAL_TYPE,
        /* DcmDsdSubServiceP4ServerMax */
        50u,
        /* DcmDsdSubServiceConditionCheckFnc */
        NULL_PTR
    },
    {
        /* DcmDsdSubServiceUsed */
        TRUE,
        /* DcmDsdSubServiceId */
        0x2u,
        /* DcmDsdSubServiceSessionLevelRef */
        0x6u,
        /* DcmDsdSubServiceSecurityLevelRef */
        0u,
        /* DcmDsdSubServiceRxAddrType */
        DCM_PHYSICAL_TYPE,
        /* DcmDsdSubServiceP4ServerMax */
        50u,
        /* DcmDsdSubServiceConditionCheckFnc */
        &Dcm_UDS0x10Sub0x2ConditionCheck
    },
    {
        /* DcmDsdSubServiceUsed */
        TRUE,
        /* DcmDsdSubServiceId */
        0x3u,
        /* DcmDsdSubServiceSessionLevelRef */
        0x5u,
        /* DcmDsdSubServiceSecurityLevelRef */
        0u,
        /* DcmDsdSubServiceRxAddrType */
        DCM_FUNCTIONAL_PHYSICAL_TYPE,
        /* DcmDsdSubServiceP4ServerMax */
        50u,
        /* DcmDsdSubServiceConditionCheckFnc */
        NULL_PTR
    }
};

CONST(Dcm_DsdSubServiceType, DCM_CONST)Dcm_DsdTable0Sid0x11SubService[1] = 
{
    {
        /* DcmDsdSubServiceUsed */
        TRUE,
        /* DcmDsdSubServiceId */
        0x1u,
        /* DcmDsdSubServiceSessionLevelRef */
        0x7u,
        /* DcmDsdSubServiceSecurityLevelRef */
        0u,
        /* DcmDsdSubServiceRxAddrType */
        DCM_FUNCTIONAL_PHYSICAL_TYPE,
        /* DcmDsdSubServiceP4ServerMax */
        50u,
        /* DcmDsdSubServiceConditionCheckFnc */
        &Dcm_UDS0x11Sub0x1ConditionCheck
    }
};

CONST(Dcm_DsdSubServiceType, DCM_CONST)Dcm_DsdTable0Sid0x27SubService[2] = 
{
    {
        /* DcmDsdSubServiceUsed */
        TRUE,
        /* DcmDsdSubServiceId */
        0x11u,
        /* DcmDsdSubServiceSessionLevelRef */
        0x2u,
        /* DcmDsdSubServiceSecurityLevelRef */
        0u,
        /* DcmDsdSubServiceRxAddrType */
        DCM_PHYSICAL_TYPE,
        /* DcmDsdSubServiceP4ServerMax */
        50u,
        /* DcmDsdSubServiceConditionCheckFnc */
        NULL_PTR
    },
    {
        /* DcmDsdSubServiceUsed */
        TRUE,
        /* DcmDsdSubServiceId */
        0x12u,
        /* DcmDsdSubServiceSessionLevelRef */
        0x2u,
        /* DcmDsdSubServiceSecurityLevelRef */
        0u,
        /* DcmDsdSubServiceRxAddrType */
        DCM_PHYSICAL_TYPE,
        /* DcmDsdSubServiceP4ServerMax */
        50u,
        /* DcmDsdSubServiceConditionCheckFnc */
        NULL_PTR
    }
};

CONST(Dcm_DsdSubServiceType, DCM_CONST)Dcm_DsdTable0Sid0x31SubService[1] = 
{
    {
        /* DcmDsdSubServiceUsed */
        TRUE,
        /* DcmDsdSubServiceId */
        0x1u,
        /* DcmDsdSubServiceSessionLevelRef */
        0x7u,
        /* DcmDsdSubServiceSecurityLevelRef */
        0u,
        /* DcmDsdSubServiceRxAddrType */
        DCM_PHYSICAL_TYPE,
        /* DcmDsdSubServiceP4ServerMax */
        5000u,
        /* DcmDsdSubServiceConditionCheckFnc */
        &Dcm_UDS0x31Sub0x1ConditionCheck
    }
};

CONST(Dcm_DsdSubServiceType, DCM_CONST)Dcm_DsdTable0Sid0x3ESubService[1] = 
{
    {
        /* DcmDsdSubServiceUsed */
        TRUE,
        /* DcmDsdSubServiceId */
        0x0u,
        /* DcmDsdSubServiceSessionLevelRef */
        0x7u,
        /* DcmDsdSubServiceSecurityLevelRef */
        0u,
        /* DcmDsdSubServiceRxAddrType */
        DCM_FUNCTIONAL_PHYSICAL_TYPE,
        /* DcmDsdSubServiceP4ServerMax */
        50u,
        /* DcmDsdSubServiceConditionCheckFnc */
        NULL_PTR
    }
};

CONST(Dcm_DsdSubServiceType, DCM_CONST)Dcm_DsdTable0Sid0x28SubService[2] = 
{
    {
        /* DcmDsdSubServiceUsed */
        TRUE,
        /* DcmDsdSubServiceId */
        0x0u,
        /* DcmDsdSubServiceSessionLevelRef */
        0x7u,
        /* DcmDsdSubServiceSecurityLevelRef */
        0u,
        /* DcmDsdSubServiceRxAddrType */
        DCM_FUNCTIONAL_PHYSICAL_TYPE,
        /* DcmDsdSubServiceP4ServerMax */
        0u,
        /* DcmDsdSubServiceConditionCheckFnc */
        NULL_PTR
    },
    {
        /* DcmDsdSubServiceUsed */
        TRUE,
        /* DcmDsdSubServiceId */
        0x3u,
        /* DcmDsdSubServiceSessionLevelRef */
        0x7u,
        /* DcmDsdSubServiceSecurityLevelRef */
        0u,
        /* DcmDsdSubServiceRxAddrType */
        DCM_FUNCTIONAL_PHYSICAL_TYPE,
        /* DcmDsdSubServiceP4ServerMax */
        0u,
        /* DcmDsdSubServiceConditionCheckFnc */
        NULL_PTR
    }
};

CONST(Dcm_DsdSubServiceType, DCM_CONST)Dcm_DsdTable0Sid0x85SubService[2] = 
{
    {
        /* DcmDsdSubServiceUsed */
        TRUE,
        /* DcmDsdSubServiceId */
        0x1u,
        /* DcmDsdSubServiceSessionLevelRef */
        0x7u,
        /* DcmDsdSubServiceSecurityLevelRef */
        0u,
        /* DcmDsdSubServiceRxAddrType */
        DCM_FUNCTIONAL_PHYSICAL_TYPE,
        /* DcmDsdSubServiceP4ServerMax */
        0u,
        /* DcmDsdSubServiceConditionCheckFnc */
        NULL_PTR
    },
    {
        /* DcmDsdSubServiceUsed */
        TRUE,
        /* DcmDsdSubServiceId */
        0x2u,
        /* DcmDsdSubServiceSessionLevelRef */
        0x7u,
        /* DcmDsdSubServiceSecurityLevelRef */
        0u,
        /* DcmDsdSubServiceRxAddrType */
        DCM_FUNCTIONAL_PHYSICAL_TYPE,
        /* DcmDsdSubServiceP4ServerMax */
        0u,
        /* DcmDsdSubServiceConditionCheckFnc */
        NULL_PTR
    }
};

CONST(Dcm_DsdServiceType, DCM_CONST)Dcm_DsdServiceTable0Services[12] = 
{
    {
        /* DcmDsdServiceUsed */
        TRUE,
        /* DcmDsdSidTabSubfuncAvail */
        TRUE,
        /* DcmDsdSidTabServiceId */
        0x10u,
        /* DcmDsdSubServiceNum */
        3u,
        /* DcmDsdSidTabSessionLevelRef */
        0x7u,
        /* DcmDsdSidTabSecurityLevelRef */
        0u,
        /* DcmDsdServiceRxAddrType */
        DCM_FUNCTIONAL_PHYSICAL_TYPE,
        /* DcmDsdServiceP4ServerMax */
        0u,
        /* DcmDsdSidTabFnc */
        &Dcm_UDS0x10,
        /* DcmDsdServiceConditionCheckFnc */
        NULL_PTR,
        /* DcmDsdSubService */
        &Dcm_DsdTable0Sid0x10SubService[0]
    },
    {
        /* DcmDsdServiceUsed */
        TRUE,
        /* DcmDsdSidTabSubfuncAvail */
        TRUE,
        /* DcmDsdSidTabServiceId */
        0x11u,
        /* DcmDsdSubServiceNum */
        1u,
        /* DcmDsdSidTabSessionLevelRef */
        0x7u,
        /* DcmDsdSidTabSecurityLevelRef */
        0u,
        /* DcmDsdServiceRxAddrType */
        DCM_FUNCTIONAL_PHYSICAL_TYPE,
        /* DcmDsdServiceP4ServerMax */
        0u,
        /* DcmDsdSidTabFnc */
        &Dcm_UDS0x11,
        /* DcmDsdServiceConditionCheckFnc */
        NULL_PTR,
        /* DcmDsdSubService */
        &Dcm_DsdTable0Sid0x11SubService[0]
    },
    {
        /* DcmDsdServiceUsed */
        TRUE,
        /* DcmDsdSidTabSubfuncAvail */
        FALSE,
        /* DcmDsdSidTabServiceId */
        0x22u,
        /* DcmDsdSubServiceNum */
        0u,
        /* DcmDsdSidTabSessionLevelRef */
        0x7u,
        /* DcmDsdSidTabSecurityLevelRef */
        0u,
        /* DcmDsdServiceRxAddrType */
        DCM_FUNCTIONAL_PHYSICAL_TYPE,
        /* DcmDsdServiceP4ServerMax */
        200u,
        /* DcmDsdSidTabFnc */
        &Dcm_UDS0x22,
        /* DcmDsdServiceConditionCheckFnc */
        &Dcm_UDS0x22ConditionCheck,
        /* DcmDsdSubService */
        NULL_PTR
    },
    {
        /* DcmDsdServiceUsed */
        TRUE,
        /* DcmDsdSidTabSubfuncAvail */
        TRUE,
        /* DcmDsdSidTabServiceId */
        0x27u,
        /* DcmDsdSubServiceNum */
        2u,
        /* DcmDsdSidTabSessionLevelRef */
        0x7u,
        /* DcmDsdSidTabSecurityLevelRef */
        0u,
        /* DcmDsdServiceRxAddrType */
        DCM_PHYSICAL_TYPE,
        /* DcmDsdServiceP4ServerMax */
        0u,
        /* DcmDsdSidTabFnc */
        &Dcm_UDS0x27,
        /* DcmDsdServiceConditionCheckFnc */
        NULL_PTR,
        /* DcmDsdSubService */
        &Dcm_DsdTable0Sid0x27SubService[0]
    },
    {
        /* DcmDsdServiceUsed */
        TRUE,
        /* DcmDsdSidTabSubfuncAvail */
        FALSE,
        /* DcmDsdSidTabServiceId */
        0x2Eu,
        /* DcmDsdSubServiceNum */
        0u,
        /* DcmDsdSidTabSessionLevelRef */
        0x2u,
        /* DcmDsdSidTabSecurityLevelRef */
        0x1u,
        /* DcmDsdServiceRxAddrType */
        DCM_PHYSICAL_TYPE,
        /* DcmDsdServiceP4ServerMax */
        5000u,
        /* DcmDsdSidTabFnc */
        &Dcm_UDS0x2E,
        /* DcmDsdServiceConditionCheckFnc */
        NULL_PTR,
        /* DcmDsdSubService */
        NULL_PTR
    },
    {
        /* DcmDsdServiceUsed */
        TRUE,
        /* DcmDsdSidTabSubfuncAvail */
        TRUE,
        /* DcmDsdSidTabServiceId */
        0x31u,
        /* DcmDsdSubServiceNum */
        1u,
        /* DcmDsdSidTabSessionLevelRef */
        0x7u,
        /* DcmDsdSidTabSecurityLevelRef */
        0u,
        /* DcmDsdServiceRxAddrType */
        DCM_PHYSICAL_TYPE,
        /* DcmDsdServiceP4ServerMax */
        0u,
        /* DcmDsdSidTabFnc */
        &Dcm_UDS0x31,
        /* DcmDsdServiceConditionCheckFnc */
        NULL_PTR,
        /* DcmDsdSubService */
        &Dcm_DsdTable0Sid0x31SubService[0]
    },
    {
        /* DcmDsdServiceUsed */
        TRUE,
        /* DcmDsdSidTabSubfuncAvail */
        TRUE,
        /* DcmDsdSidTabServiceId */
        0x3Eu,
        /* DcmDsdSubServiceNum */
        1u,
        /* DcmDsdSidTabSessionLevelRef */
        0x7u,
        /* DcmDsdSidTabSecurityLevelRef */
        0u,
        /* DcmDsdServiceRxAddrType */
        DCM_FUNCTIONAL_PHYSICAL_TYPE,
        /* DcmDsdServiceP4ServerMax */
        0u,
        /* DcmDsdSidTabFnc */
        &Dcm_UDS0x3E,
        /* DcmDsdServiceConditionCheckFnc */
        NULL_PTR,
        /* DcmDsdSubService */
        &Dcm_DsdTable0Sid0x3ESubService[0]
    },
    {
        /* DcmDsdServiceUsed */
        TRUE,
        /* DcmDsdSidTabSubfuncAvail */
        FALSE,
        /* DcmDsdSidTabServiceId */
        0x34u,
        /* DcmDsdSubServiceNum */
        0u,
        /* DcmDsdSidTabSessionLevelRef */
        0x2u,
        /* DcmDsdSidTabSecurityLevelRef */
        0x1u,
        /* DcmDsdServiceRxAddrType */
        DCM_PHYSICAL_TYPE,
        /* DcmDsdServiceP4ServerMax */
        0u,
        /* DcmDsdSidTabFnc */
        &Dcm_UDS0x34,
        /* DcmDsdServiceConditionCheckFnc */
        NULL_PTR,
        /* DcmDsdSubService */
        NULL_PTR
    },
    {
        /* DcmDsdServiceUsed */
        TRUE,
        /* DcmDsdSidTabSubfuncAvail */
        FALSE,
        /* DcmDsdSidTabServiceId */
        0x36u,
        /* DcmDsdSubServiceNum */
        0u,
        /* DcmDsdSidTabSessionLevelRef */
        0x2u,
        /* DcmDsdSidTabSecurityLevelRef */
        0x1u,
        /* DcmDsdServiceRxAddrType */
        DCM_PHYSICAL_TYPE,
        /* DcmDsdServiceP4ServerMax */
        0u,
        /* DcmDsdSidTabFnc */
        &Dcm_UDS0x36,
        /* DcmDsdServiceConditionCheckFnc */
        NULL_PTR,
        /* DcmDsdSubService */
        NULL_PTR
    },
    {
        /* DcmDsdServiceUsed */
        TRUE,
        /* DcmDsdSidTabSubfuncAvail */
        FALSE,
        /* DcmDsdSidTabServiceId */
        0x37u,
        /* DcmDsdSubServiceNum */
        0u,
        /* DcmDsdSidTabSessionLevelRef */
        0x2u,
        /* DcmDsdSidTabSecurityLevelRef */
        0x1u,
        /* DcmDsdServiceRxAddrType */
        DCM_PHYSICAL_TYPE,
        /* DcmDsdServiceP4ServerMax */
        0u,
        /* DcmDsdSidTabFnc */
        &Dcm_UDS0x37,
        /* DcmDsdServiceConditionCheckFnc */
        NULL_PTR,
        /* DcmDsdSubService */
        NULL_PTR
    },
    {
        /* DcmDsdServiceUsed */
        TRUE,
        /* DcmDsdSidTabSubfuncAvail */
        TRUE,
        /* DcmDsdSidTabServiceId */
        0x28u,
        /* DcmDsdSubServiceNum */
        2u,
        /* DcmDsdSidTabSessionLevelRef */
        0x7u,
        /* DcmDsdSidTabSecurityLevelRef */
        0u,
        /* DcmDsdServiceRxAddrType */
        DCM_FUNCTIONAL_PHYSICAL_TYPE,
        /* DcmDsdServiceP4ServerMax */
        0u,
        /* DcmDsdSidTabFnc */
        &Dcm_UDS0x28,
        /* DcmDsdServiceConditionCheckFnc */
        NULL_PTR,
        /* DcmDsdSubService */
        &Dcm_DsdTable0Sid0x28SubService[0]
    },
    {
        /* DcmDsdServiceUsed */
        TRUE,
        /* DcmDsdSidTabSubfuncAvail */
        TRUE,
        /* DcmDsdSidTabServiceId */
        0x85u,
        /* DcmDsdSubServiceNum */
        2u,
        /* DcmDsdSidTabSessionLevelRef */
        0x7u,
        /* DcmDsdSidTabSecurityLevelRef */
        0u,
        /* DcmDsdServiceRxAddrType */
        DCM_FUNCTIONAL_PHYSICAL_TYPE,
        /* DcmDsdServiceP4ServerMax */
        0u,
        /* DcmDsdSidTabFnc */
        &Dcm_UDS0x85,
        /* DcmDsdServiceConditionCheckFnc */
        NULL_PTR,
        /* DcmDsdSubService */
        &Dcm_DsdTable0Sid0x85SubService[0]
    }
};

CONST(Dcm_DsdServiceTableType, DCM_CONST)Dcm_DsdServiceTable[1] = 
{
    {
        /* DcmDsdSidTabId */
        0u,
        /* DcmServiceNum */
        12u,
        /* DcmDsdService */
        &Dcm_DsdServiceTable0Services[0]
    }
};

CONST(Dcm_DsdType, DCM_CONST)Dcm_Dsd = 
{
    /* DcmDsdUDS0x28SesRef */
    0x7u,
    /* DcmDsdUDS0x85SesRef */
    0x7u,
    /* DcmDsdServiceTable */
    &Dcm_DsdServiceTable[0]
};

#define DCM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONFIG_DATA_8
#include "Dcm_MemMap.h"

VAR(uint8, DCM_VAR)Dcm_InternalBuffer[8448] = {0};

#define DCM_STOP_SEC_CONFIG_DATA_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dcm_MemMap.h"

CONST(Dcm_DslBufferType, DCM_CONST)Dcm_DslBuffer[2] = 
{
    {
        /* DcmDslBufferSize */
        4224u,
        /* DcmDslBufferRef */
        &Dcm_InternalBuffer[0]
    },
    {
        /* DcmDslBufferSize */
        4224u,
        /* DcmDslBufferRef */
        &Dcm_InternalBuffer[4224]
    }
};

CONST(Dcm_DslProtocolRxType, DCM_CONST)Dcm_DslProtocolRx[2] = 
{
    {
        /* DcmDslRxParentConIdx */
        0u,
        /* DcmDslRxParentProIdx */
        0u,
        /* DcmDslProtocolRxPduRef */
        DcmConf_DcmDslProtocolRx_LinPdu_LinTpToDcm_MasterReq_Rx,
        /* DcmDslProtocolRxPduId */
        DcmConf_DcmDslProtocolRx_LinPdu_LinTpToDcm_MasterReq_Rx,
        /* DcmDslProtocolRxAddrType */
        DCM_PHYSICAL_TYPE
    },
    {
        /* DcmDslRxParentConIdx */
        0u,
        /* DcmDslRxParentProIdx */
        0u,
        /* DcmDslProtocolRxPduRef */
        DcmConf_DcmDslProtocolRx_LinTp_To_PudR_Function_Rx,
        /* DcmDslProtocolRxPduId */
        DcmConf_DcmDslProtocolRx_LinTp_To_PudR_Function_Rx,
        /* DcmDslProtocolRxAddrType */
        DCM_FUNCTIONAL_TYPE
    }
};

CONST(Dcm_DslProtocolTxType, DCM_CONST)Dcm_DslProtocolTx[1] = 
{
    {
        /* DcmDslTxParentConIdx */
        0u,
        /* DcmDslTxParentProIdx */
        0u,
        /* DcmDslProtocolTxPduRef */
        DcmConf_DcmDslProtocolTx_LinPdu_DcmToLinTp_SlaveResp_Tx,
        /* DcmDslTxConfirmationPduId */
        DcmConf_DcmDslProtocolTx_LinPdu_DcmToLinTp_SlaveResp_Tx
    }
};

CONST(Dcm_DslMainConnectionType, DCM_CONST)Dcm_DslMainConnection[1] = 
{
    {
        /* DcmDslParentProIdx */
        0u,
        /* DcmDslProtocolComMChannelRef */
        0u,
        /* DcmDslProtocolTx */
        &Dcm_DslProtocolTx[0],
    }
};

CONST(Dcm_DslProtocolRowType, DCM_CONST)Dcm_DslProtocolRow[1] = 
{
    {
        /* DcmDslProtocolRowUsed */
        TRUE,
        /* DcmSendRespPendOnTransToBoot */
        FALSE,
        /* DcmDslProtocolPriority */
        0u,
        /* DcmTimStrP2ServerAdjust */
        0u,
        /* DcmTimStrP2StarServerAdjust */
        0u,
        /* DcmDslProtocolPreemptTimeout */
        50u,
        /* DcmDslProtocolID */
        DCM_UDS_ON_CAN,
        /* DcmDslProtocolRxBufferRef */
        &Dcm_DslBuffer[1],
        /* DcmDslProtocolSIDTable */
        &Dcm_DsdServiceTable[0],
        /* DcmDslProtocolTxBufferRef */
        &Dcm_DslBuffer[0]
    }
};

CONST(Dcm_DslType, DCM_CONST)Dcm_Dsl = 
{
    /* DcmDslBuffer */
    &Dcm_DslBuffer[0],
    /* DcmDslProtocolRow */
    &Dcm_DslProtocolRow[0]
};

CONST(Dcm_DspComControlAllChannelType, DCM_CONST)Dcm_DspComControlAllChannel[1] = 
{
    {
        /* DcmDspComControlAllChannelUsed */
        TRUE,
        /* DcmDspAllComMChannelRef */
        0u
    }
};

CONST(Dcm_DspComControlType, DCM_CONST)Dcm_DspComControl = 
{
    /* DcmDspComControlAllChannel */
    &Dcm_DspComControlAllChannel[0]
};

CONST(Dcm_DspCommonAuthorizationType, DCM_CONST)Dcm_DspCommonAuthorization[1] = 
{
    {
        /* DcmDspCommonAuthorizationSessionRef */
        0x2u,
        /* DcmDspCommonAuthorizationSecurityLevelRef */
        0x1u
    }
};

CONST(Dcm_DspControlDTCSettingType, DCM_CONST)Dcm_DspControlDTCSetting = 
{
    /* DcmSupportDTCSettingControlOptionRecord */
    FALSE
};

#define DCM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONFIG_DATA_8
#include "Dcm_MemMap.h"

VAR(uint8, DCM_VAR)Dcm_DspDataInternalBuffer_DcmDspData_0xF180[32] = {0};

VAR(uint8, DCM_VAR)Dcm_DspDataInternalBuffer_DcmDspData_0xF187[16] = {0};

VAR(uint8, DCM_VAR)Dcm_DspDataInternalBuffer_DcmDspData_0xF089[24] = {0};

VAR(uint8, DCM_VAR)Dcm_DspDataInternalBuffer_DcmDspData_0xF18A[10] = {0};

VAR(uint8, DCM_VAR)Dcm_DspDataInternalBuffer_DcmDspData_0xF186[1] = {0};

VAR(uint8, DCM_VAR)Dcm_DspDataInternalBuffer_DcmDspData_0xF184[19] = {0};

VAR(uint8, DCM_VAR)Dcm_DspDataInternalBuffer_DcmDspData_0xF0F1[4] = {0};

VAR(uint8, DCM_VAR)Dcm_DspDataInternalBuffer_DcmDspData_0xF0F3[4] = {0};

VAR(uint8, DCM_VAR)Dcm_DspDataInternalBuffer_DcmDspData_0xF160[1] = {0};

#define DCM_STOP_SEC_CONFIG_DATA_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dcm_MemMap.h"

CONST(Dcm_DspDataType, DCM_CONST)Dcm_DspData[9] = 
{
    {
        /* DcmDspDataConditionCheckReadFncUsed */
        TRUE,
        /* DcmDspDataSize */
        256u,
        /* DcmDspDataEndianness */
        DCM_OPAQUE,
        /* DcmDspDataType */
        DCM_UINT8_N,
        /* DcmDspDataUsePort */
        DCM_USE_DATA_SYNCH_FNC,
        /* DcmDspDataConditionCheckReadFnc */
        &DcmDspDataConditionCheckRead_0xF180,
        /* DcmDspDataReadFnc */
        &DcmDspDataRead_0xF180,
        /* DcmDspDataWriteFnc */
        NULL_PTR,
        /* DcmDspDataInternalBuffer */
        &Dcm_DspDataInternalBuffer_DcmDspData_0xF180[0]
    },
    {
        /* DcmDspDataConditionCheckReadFncUsed */
        TRUE,
        /* DcmDspDataSize */
        128u,
        /* DcmDspDataEndianness */
        DCM_OPAQUE,
        /* DcmDspDataType */
        DCM_UINT8_N,
        /* DcmDspDataUsePort */
        DCM_USE_DATA_SYNCH_FNC,
        /* DcmDspDataConditionCheckReadFnc */
        &DcmDspDataConditionCheckRead_0xF187,
        /* DcmDspDataReadFnc */
        &DcmDspDataRead_0xF187,
        /* DcmDspDataWriteFnc */
        NULL_PTR,
        /* DcmDspDataInternalBuffer */
        &Dcm_DspDataInternalBuffer_DcmDspData_0xF187[0]
    },
    {
        /* DcmDspDataConditionCheckReadFncUsed */
        TRUE,
        /* DcmDspDataSize */
        192u,
        /* DcmDspDataEndianness */
        DCM_OPAQUE,
        /* DcmDspDataType */
        DCM_UINT8_N,
        /* DcmDspDataUsePort */
        DCM_USE_DATA_SYNCH_FNC,
        /* DcmDspDataConditionCheckReadFnc */
        &DcmDspDataConditionCheckRead_0xF089,
        /* DcmDspDataReadFnc */
        &DcmDspDataRead_0xF089,
        /* DcmDspDataWriteFnc */
        NULL_PTR,
        /* DcmDspDataInternalBuffer */
        &Dcm_DspDataInternalBuffer_DcmDspData_0xF089[0]
    },
    {
        /* DcmDspDataConditionCheckReadFncUsed */
        TRUE,
        /* DcmDspDataSize */
        80u,
        /* DcmDspDataEndianness */
        DCM_OPAQUE,
        /* DcmDspDataType */
        DCM_UINT8_N,
        /* DcmDspDataUsePort */
        DCM_USE_DATA_SYNCH_FNC,
        /* DcmDspDataConditionCheckReadFnc */
        &DcmDspDataConditionCheckRead_0xF18A,
        /* DcmDspDataReadFnc */
        &DcmDspDataRead_0xF18A,
        /* DcmDspDataWriteFnc */
        NULL_PTR,
        /* DcmDspDataInternalBuffer */
        &Dcm_DspDataInternalBuffer_DcmDspData_0xF18A[0]
    },
    {
        /* DcmDspDataConditionCheckReadFncUsed */
        TRUE,
        /* DcmDspDataSize */
        8u,
        /* DcmDspDataEndianness */
        DCM_OPAQUE,
        /* DcmDspDataType */
        DCM_UINT8_N,
        /* DcmDspDataUsePort */
        DCM_USE_DATA_SYNCH_FNC,
        /* DcmDspDataConditionCheckReadFnc */
        &DcmDspDataConditionCheckRead_0xF186,
        /* DcmDspDataReadFnc */
        &DcmDspDataRead_0xF186,
        /* DcmDspDataWriteFnc */
        NULL_PTR,
        /* DcmDspDataInternalBuffer */
        &Dcm_DspDataInternalBuffer_DcmDspData_0xF186[0]
    },
    {
        /* DcmDspDataConditionCheckReadFncUsed */
        TRUE,
        /* DcmDspDataSize */
        152u,
        /* DcmDspDataEndianness */
        DCM_OPAQUE,
        /* DcmDspDataType */
        DCM_UINT8_N,
        /* DcmDspDataUsePort */
        DCM_USE_DATA_SYNCH_FNC,
        /* DcmDspDataConditionCheckReadFnc */
        &DcmDspDataConditionCheckRead_0xF184,
        /* DcmDspDataReadFnc */
        &DcmDspDataRead_0xF184,
        /* DcmDspDataWriteFnc */
        &DcmDspDataWrite_0xF184,
        /* DcmDspDataInternalBuffer */
        &Dcm_DspDataInternalBuffer_DcmDspData_0xF184[0]
    },
    {
        /* DcmDspDataConditionCheckReadFncUsed */
        TRUE,
        /* DcmDspDataSize */
        32u,
        /* DcmDspDataEndianness */
        DCM_OPAQUE,
        /* DcmDspDataType */
        DCM_UINT8_N,
        /* DcmDspDataUsePort */
        DCM_USE_DATA_SYNCH_FNC,
        /* DcmDspDataConditionCheckReadFnc */
        &DcmDspDataConditionCheckRead_0xF0F1,
        /* DcmDspDataReadFnc */
        &DcmDspDataRead_0xF0F1,
        /* DcmDspDataWriteFnc */
        NULL_PTR,
        /* DcmDspDataInternalBuffer */
        &Dcm_DspDataInternalBuffer_DcmDspData_0xF0F1[0]
    },
    {
        /* DcmDspDataConditionCheckReadFncUsed */
        TRUE,
        /* DcmDspDataSize */
        32u,
        /* DcmDspDataEndianness */
        DCM_OPAQUE,
        /* DcmDspDataType */
        DCM_UINT8_N,
        /* DcmDspDataUsePort */
        DCM_USE_DATA_SYNCH_FNC,
        /* DcmDspDataConditionCheckReadFnc */
        &DcmDspDataConditionCheckRead_0xF0F3,
        /* DcmDspDataReadFnc */
        &DcmDspDataRead_0xF0F3,
        /* DcmDspDataWriteFnc */
        NULL_PTR,
        /* DcmDspDataInternalBuffer */
        &Dcm_DspDataInternalBuffer_DcmDspData_0xF0F3[0]
    },
    {
        /* DcmDspDataConditionCheckReadFncUsed */
        TRUE,
        /* DcmDspDataSize */
        8u,
        /* DcmDspDataEndianness */
        DCM_OPAQUE,
        /* DcmDspDataType */
        DCM_UINT8_N,
        /* DcmDspDataUsePort */
        DCM_USE_DATA_SYNCH_FNC,
        /* DcmDspDataConditionCheckReadFnc */
        &DcmDspDataConditionCheckRead_0xF160,
        /* DcmDspDataReadFnc */
        &DcmDspDataRead_0xF160,
        /* DcmDspDataWriteFnc */
        NULL_PTR,
        /* DcmDspDataInternalBuffer */
        &Dcm_DspDataInternalBuffer_DcmDspData_0xF160[0]
    }
};

#define DCM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dcm_MemMap.h"

CONST(Dcm_DspDidReadType, DCM_CONST)Dcm_DspDidRead[9] = 
{
    {
        /* DcmDspDidReadSessionRef */
        0x7u,
        /* DcmDspDidReadSecurityLevelRef */
        0u
    },
    {
        /* DcmDspDidReadSessionRef */
        0x7u,
        /* DcmDspDidReadSecurityLevelRef */
        0u
    },
    {
        /* DcmDspDidReadSessionRef */
        0x7u,
        /* DcmDspDidReadSecurityLevelRef */
        0u
    },
    {
        /* DcmDspDidReadSessionRef */
        0x7u,
        /* DcmDspDidReadSecurityLevelRef */
        0u
    },
    {
        /* DcmDspDidReadSessionRef */
        0x7u,
        /* DcmDspDidReadSecurityLevelRef */
        0u
    },
    {
        /* DcmDspDidReadSessionRef */
        0x7u,
        /* DcmDspDidReadSecurityLevelRef */
        0u
    },
    {
        /* DcmDspDidReadSessionRef */
        0x7u,
        /* DcmDspDidReadSecurityLevelRef */
        0u
    },
    {
        /* DcmDspDidReadSessionRef */
        0x7u,
        /* DcmDspDidReadSecurityLevelRef */
        0u
    },
    {
        /* DcmDspDidReadSessionRef */
        0x7u,
        /* DcmDspDidReadSecurityLevelRef */
        0u
    }
};

CONST(Dcm_DspDidWriteType, DCM_CONST)Dcm_DspDidWrite[1] = 
{
    {
        /* DcmDspDidWriteSessionRef */
        0x2u,
        /* DcmDspDidWriteSecurityLevelRef */
        0x1u
    }
};

CONST(Dcm_DspDidInfoType, DCM_CONST)Dcm_DspDidInfo[9] = 
{
    {
        /* DcmDspDidRead */
        &Dcm_DspDidRead[0],
        /* DcmDspDidWrite */
        NULL_PTR
    },
    {
        /* DcmDspDidRead */
        &Dcm_DspDidRead[1],
        /* DcmDspDidWrite */
        NULL_PTR
    },
    {
        /* DcmDspDidRead */
        &Dcm_DspDidRead[2],
        /* DcmDspDidWrite */
        NULL_PTR
    },
    {
        /* DcmDspDidRead */
        &Dcm_DspDidRead[3],
        /* DcmDspDidWrite */
        NULL_PTR
    },
    {
        /* DcmDspDidRead */
        &Dcm_DspDidRead[4],
        /* DcmDspDidWrite */
        NULL_PTR
    },
    {
        /* DcmDspDidRead */
        &Dcm_DspDidRead[5],
        /* DcmDspDidWrite */
        &Dcm_DspDidWrite[0]
    },
    {
        /* DcmDspDidRead */
        &Dcm_DspDidRead[6],
        /* DcmDspDidWrite */
        NULL_PTR
    },
    {
        /* DcmDspDidRead */
        &Dcm_DspDidRead[7],
        /* DcmDspDidWrite */
        NULL_PTR
    },
    {
        /* DcmDspDidRead */
        &Dcm_DspDidRead[8],
        /* DcmDspDidWrite */
        NULL_PTR
    }
};

#define DCM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dcm_MemMap.h"

CONST(Dcm_DspDidSignalType, DCM_CONST)Dcm_DspDidSignal[9] = 
{
    {
        /* DcmDspDidDataPos */
        0u,
        /* DcmDspDidDataRef */
        &Dcm_DspData[0]
    },
    {
        /* DcmDspDidDataPos */
        0u,
        /* DcmDspDidDataRef */
        &Dcm_DspData[1]
    },
    {
        /* DcmDspDidDataPos */
        0u,
        /* DcmDspDidDataRef */
        &Dcm_DspData[2]
    },
    {
        /* DcmDspDidDataPos */
        0u,
        /* DcmDspDidDataRef */
        &Dcm_DspData[3]
    },
    {
        /* DcmDspDidDataPos */
        0u,
        /* DcmDspDidDataRef */
        &Dcm_DspData[4]
    },
    {
        /* DcmDspDidDataPos */
        0u,
        /* DcmDspDidDataRef */
        &Dcm_DspData[5]
    },
    {
        /* DcmDspDidDataPos */
        0u,
        /* DcmDspDidDataRef */
        &Dcm_DspData[6]
    },
    {
        /* DcmDspDidDataPos */
        0u,
        /* DcmDspDidDataRef */
        &Dcm_DspData[7]
    },
    {
        /* DcmDspDidDataPos */
        0u,
        /* DcmDspDidDataRef */
        &Dcm_DspData[8]
    }
};

CONST(Dcm_DspDidType, DCM_CONST)Dcm_DspDid[9] = 
{
    {
        /* DcmDspDidUsed */
        TRUE,
        /* DcmDspDidSignalNum */
        1u,
        /* DcmDspDidIdentifier */
        0xF180u,
        /* DcmDspDidInfoRef */
        &Dcm_DspDidInfo[0],
        /* DcmDspDidSignal */
        &Dcm_DspDidSignal[0]
    },
    {
        /* DcmDspDidUsed */
        TRUE,
        /* DcmDspDidSignalNum */
        1u,
        /* DcmDspDidIdentifier */
        0xF187u,
        /* DcmDspDidInfoRef */
        &Dcm_DspDidInfo[1],
        /* DcmDspDidSignal */
        &Dcm_DspDidSignal[1]
    },
    {
        /* DcmDspDidUsed */
        TRUE,
        /* DcmDspDidSignalNum */
        1u,
        /* DcmDspDidIdentifier */
        0xF089u,
        /* DcmDspDidInfoRef */
        &Dcm_DspDidInfo[2],
        /* DcmDspDidSignal */
        &Dcm_DspDidSignal[2]
    },
    {
        /* DcmDspDidUsed */
        TRUE,
        /* DcmDspDidSignalNum */
        1u,
        /* DcmDspDidIdentifier */
        0xF18Au,
        /* DcmDspDidInfoRef */
        &Dcm_DspDidInfo[3],
        /* DcmDspDidSignal */
        &Dcm_DspDidSignal[3]
    },
    {
        /* DcmDspDidUsed */
        TRUE,
        /* DcmDspDidSignalNum */
        1u,
        /* DcmDspDidIdentifier */
        0xF186u,
        /* DcmDspDidInfoRef */
        &Dcm_DspDidInfo[4],
        /* DcmDspDidSignal */
        &Dcm_DspDidSignal[4]
    },
    {
        /* DcmDspDidUsed */
        TRUE,
        /* DcmDspDidSignalNum */
        1u,
        /* DcmDspDidIdentifier */
        0xF184u,
        /* DcmDspDidInfoRef */
        &Dcm_DspDidInfo[5],
        /* DcmDspDidSignal */
        &Dcm_DspDidSignal[5]
    },
    {
        /* DcmDspDidUsed */
        TRUE,
        /* DcmDspDidSignalNum */
        1u,
        /* DcmDspDidIdentifier */
        0xF0F1u,
        /* DcmDspDidInfoRef */
        &Dcm_DspDidInfo[6],
        /* DcmDspDidSignal */
        &Dcm_DspDidSignal[6]
    },
    {
        /* DcmDspDidUsed */
        TRUE,
        /* DcmDspDidSignalNum */
        1u,
        /* DcmDspDidIdentifier */
        0xF0F3u,
        /* DcmDspDidInfoRef */
        &Dcm_DspDidInfo[7],
        /* DcmDspDidSignal */
        &Dcm_DspDidSignal[7]
    },
    {
        /* DcmDspDidUsed */
        TRUE,
        /* DcmDspDidSignalNum */
        1u,
        /* DcmDspDidIdentifier */
        0xF160u,
        /* DcmDspDidInfoRef */
        &Dcm_DspDidInfo[8],
        /* DcmDspDidSignal */
        &Dcm_DspDidSignal[8]
    }
};

#define DCM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dcm_MemMap.h"

CONST(Dcm_DspReadMemoryRangeInfoType, DCM_CONST)Dcm_DspReadMemoryRangeInfo[2] = 
{
    {
        /* DcmDspReadMemoryRangeSecurityLevelRef */
        0x1u,
        /* DcmDspReadMemoryRangeLow */
        0x10000u,
        /* DcmDspReadMemoryRangeHigh */
        0x7D000u
    },
    {
        /* DcmDspReadMemoryRangeSecurityLevelRef */
        0x1u,
        /* DcmDspReadMemoryRangeLow */
        0x20007B00u,
        /* DcmDspReadMemoryRangeHigh */
        0x20007F00u
    }
};

CONST(Dcm_DspWriteMemoryRangeInfoType, DCM_CONST)Dcm_DspWriteMemoryRangeInfo[2] = 
{
    {
        /* DcmDspWriteMemoryRangeSecurityLevelRef */
        0x1u,
        /* DcmDspWriteMemoryRangeLow */
        0x10000u,
        /* DcmDspWriteMemoryRangeHigh */
        0x7D000u
    },
    {
        /* DcmDspWriteMemoryRangeSecurityLevelRef */
        0x1u,
        /* DcmDspWriteMemoryRangeLow */
        0x20007B00u,
        /* DcmDspWriteMemoryRangeHigh */
        0x20007F00u
    }
};

CONST(Dcm_DspMemoryIdInfoType, DCM_CONST)Dcm_DspMemoryIdInfo[2] =
{
    {
        /* DcmDspMemoryIdValue */
        00u,
        /* DcmDspReadMemoryRangeInfoNum */
        1u,
        /* DcmDspWriteMemoryRangeInfoNum */
        1u,
        /* DcmDspReadMemoryRangeInfo */
        &Dcm_DspReadMemoryRangeInfo[0],
        /* DcmDspWriteMemoryRangeInfo */
        &Dcm_DspWriteMemoryRangeInfo[0]
    },
    {
        /* DcmDspMemoryIdValue */
        32u,
        /* DcmDspReadMemoryRangeInfoNum */
        1u,
        /* DcmDspWriteMemoryRangeInfoNum */
        1u,
        /* DcmDspReadMemoryRangeInfo */
        &Dcm_DspReadMemoryRangeInfo[1],
        /* DcmDspWriteMemoryRangeInfo */
        &Dcm_DspWriteMemoryRangeInfo[1]
    }
};

CONST(Dcm_DspMemoryType, DCM_CONST)Dcm_DspMemory = 
{
    /* DcmDspMemoryIdInfo */
    &Dcm_DspMemoryIdInfo[0]
};

#define DCM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dcm_MemMap.h"

CONST(Dcm_DspRoutineSignalType, DCM_CONST)Dcm_DspRoutineInSignal[2] = 
{
    {
        /* DcmDspRoutineSignalLength */
        72u,
        /* DcmDspRoutineSignalPos */
        0u,
        /* DcmDspRoutineSignalEndianness */
        DCM_OPAQUE,
        /* DcmDspRoutineSignalType */
        DCM_UINT8_DYN
    },
    {
        /* DcmDspRoutineSignalLength */
        3072u,
        /* DcmDspRoutineSignalPos */
        0u,
        /* DcmDspRoutineSignalEndianness */
        DCM_OPAQUE,
        /* DcmDspRoutineSignalType */
        DCM_UINT8_DYN
    }
};

CONST(Dcm_DspRoutineSignalType, DCM_CONST)Dcm_DspRoutineOutSignal[5] = 
{
    {
        /* DcmDspRoutineSignalLength */
        16u,
        /* DcmDspRoutineSignalPos */
        0u,
        /* DcmDspRoutineSignalEndianness */
        DCM_OPAQUE,
        /* DcmDspRoutineSignalType */
        DCM_UINT8_DYN
    },
    {
        /* DcmDspRoutineSignalLength */
        8u,
        /* DcmDspRoutineSignalPos */
        0u,
        /* DcmDspRoutineSignalEndianness */
        DCM_OPAQUE,
        /* DcmDspRoutineSignalType */
        DCM_UINT8_DYN
    },
    {
        /* DcmDspRoutineSignalLength */
        8u,
        /* DcmDspRoutineSignalPos */
        0u,
        /* DcmDspRoutineSignalEndianness */
        DCM_OPAQUE,
        /* DcmDspRoutineSignalType */
        DCM_UINT8_DYN
    },
    {
        /* DcmDspRoutineSignalLength */
        8u,
        /* DcmDspRoutineSignalPos */
        0u,
        /* DcmDspRoutineSignalEndianness */
        DCM_OPAQUE,
        /* DcmDspRoutineSignalType */
        DCM_UINT8_DYN
    },
    {
        /* DcmDspRoutineSignalLength */
        8u,
        /* DcmDspRoutineSignalPos */
        0u,
        /* DcmDspRoutineSignalEndianness */
        DCM_OPAQUE,
        /* DcmDspRoutineSignalType */
        DCM_UINT8_DYN
    }
};

CONST(Dcm_DspStartRoutineType, DCM_CONST)Dcm_DspStartRoutine[5] = 
{
    {
        /* DcmDspStartRoutineInSignalNum */
        0u,
        /* DcmDspStartRoutineOutSignalNum */
        1u,
        /* DcmDspStartRoutineFnc */
        &DcmDspStartRoutine_0x0203,
        /* DcmDspStartRoutineCommonAuthorizationRef */
        NULL_PTR,
        /* DcmDspStartRoutineInSignal */
        NULL_PTR,
        /* DcmDspStartRoutineOutSignal */
        &Dcm_DspRoutineOutSignal[0],
    },
    {
        /* DcmDspStartRoutineInSignalNum */
        1u,
        /* DcmDspStartRoutineOutSignalNum */
        1u,
        /* DcmDspStartRoutineFnc */
        &DcmDspStartRoutine_0xFF00_EraseMemory,
        /* DcmDspStartRoutineCommonAuthorizationRef */
        &Dcm_DspCommonAuthorization[0],
        /* DcmDspStartRoutineInSignal */
        &Dcm_DspRoutineInSignal[0],
        /* DcmDspStartRoutineOutSignal */
        &Dcm_DspRoutineOutSignal[1],
    },
    {
        /* DcmDspStartRoutineInSignalNum */
        0u,
        /* DcmDspStartRoutineOutSignalNum */
        1u,
        /* DcmDspStartRoutineFnc */
        &DcmDspStartRoutine_0xFF01_checkProgrammingDependencies,
        /* DcmDspStartRoutineCommonAuthorizationRef */
        &Dcm_DspCommonAuthorization[0],
        /* DcmDspStartRoutineInSignal */
        NULL_PTR,
        /* DcmDspStartRoutineOutSignal */
        &Dcm_DspRoutineOutSignal[2],
    },
    {
        /* DcmDspStartRoutineInSignalNum */
        0u,
        /* DcmDspStartRoutineOutSignalNum */
        1u,
        /* DcmDspStartRoutineFnc */
        &DcmDspStartRoutine_0xDD01_StayInBoot,
        /* DcmDspStartRoutineCommonAuthorizationRef */
        NULL_PTR,
        /* DcmDspStartRoutineInSignal */
        NULL_PTR,
        /* DcmDspStartRoutineOutSignal */
        &Dcm_DspRoutineOutSignal[3],
    },
    {
        /* DcmDspStartRoutineInSignalNum */
        1u,
        /* DcmDspStartRoutineOutSignalNum */
        1u,
        /* DcmDspStartRoutineFnc */
        &DcmDspStartRoutine_0xDD02_SecuritySignatureVerification,
        /* DcmDspStartRoutineCommonAuthorizationRef */
        &Dcm_DspCommonAuthorization[0],
        /* DcmDspStartRoutineInSignal */
        &Dcm_DspRoutineInSignal[1],
        /* DcmDspStartRoutineOutSignal */
        &Dcm_DspRoutineOutSignal[4],
    }
};

CONST(Dcm_DspRoutineType, DCM_CONST)Dcm_DspRoutine[5] = 
{
    {
        /* DcmDspRoutineUsed */
        TRUE,
        /* DcmDspRoutineUsePort */
        FALSE,
        /* DcmDspRoutineIdentifier */
        0x203u,
        /* DcmDspCommonAuthorizationRef */
        NULL_PTR,
        /* DcmDspStartRoutine */
        &Dcm_DspStartRoutine[0],
    },
    {
        /* DcmDspRoutineUsed */
        TRUE,
        /* DcmDspRoutineUsePort */
        FALSE,
        /* DcmDspRoutineIdentifier */
        0xFF00u,
        /* DcmDspCommonAuthorizationRef */
        &Dcm_DspCommonAuthorization[0],
        /* DcmDspStartRoutine */
        &Dcm_DspStartRoutine[1],
    },
    {
        /* DcmDspRoutineUsed */
        TRUE,
        /* DcmDspRoutineUsePort */
        FALSE,
        /* DcmDspRoutineIdentifier */
        0xFF01u,
        /* DcmDspCommonAuthorizationRef */
        &Dcm_DspCommonAuthorization[0],
        /* DcmDspStartRoutine */
        &Dcm_DspStartRoutine[2],
    },
    {
        /* DcmDspRoutineUsed */
        TRUE,
        /* DcmDspRoutineUsePort */
        FALSE,
        /* DcmDspRoutineIdentifier */
        0xDD01u,
        /* DcmDspCommonAuthorizationRef */
        NULL_PTR,
        /* DcmDspStartRoutine */
        &Dcm_DspStartRoutine[3],
    },
    {
        /* DcmDspRoutineUsed */
        TRUE,
        /* DcmDspRoutineUsePort */
        FALSE,
        /* DcmDspRoutineIdentifier */
        0xDD02u,
        /* DcmDspCommonAuthorizationRef */
        &Dcm_DspCommonAuthorization[0],
        /* DcmDspStartRoutine */
        &Dcm_DspStartRoutine[4],
    }
};

#define DCM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dcm_MemMap.h"

CONST(Dcm_DspSecurityRowType, DCM_CONST)Dcm_DspSecurityRow[1] = 
{
    {
        /* DcmDspSecurityLevel */
        9u,
        /* DcmDspSecurityNumAttDelay */
        2u,
        /* DcmDspSecurityADRSize */
        0u,
        /* DcmDspSecurityDelayTime */
        10000u,
        /* DcmDspSecurityDelayTimeOnBoot */
        0u,
        /* DcmDspSecurityKeySize */
        16u,
        /* DcmDspSecuritySeedSize */
        16u,
        /* DcmDspSecurityUsePort */
        DCM_USE_DATA_ASYNCH_FNC,
        /* DcmDspSecurityCompareKeyFnc */
        DcmDspSecurityCompareKey_Level_FBL,
        /* DcmDspSecurityGetSeedFnc */
        DcmDspSecurityGetSeed_Level_FBL
    }
};

#define DCM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dcm_MemMap.h"

CONST(Dcm_DspSessionRowType, DCM_CONST)Dcm_DspSessionRow[3] = 
{
    {
        /* DcmDspSessionLevel */
        1u,
        /* DcmDspSessionP2ServerMax */
        50u,
        /* DcmDspSessionP2PendingThreshold */
        30u,
        /* DcmDspSessionForBoot */
        DCM_NO_BOOT,
        /* DcmDspSessionP2StarServerMax */
        2000u,
    },
    {
        /* DcmDspSessionLevel */
        2u,
        /* DcmDspSessionP2ServerMax */
        50u,
        /* DcmDspSessionP2PendingThreshold */
        30u,
        /* DcmDspSessionForBoot */
        DCM_NO_BOOT,
        /* DcmDspSessionP2StarServerMax */
        2000u,
    },
    {
        /* DcmDspSessionLevel */
        3u,
        /* DcmDspSessionP2ServerMax */
        50u,
        /* DcmDspSessionP2PendingThreshold */
        30u,
        /* DcmDspSessionForBoot */
        DCM_NO_BOOT,
        /* DcmDspSessionP2StarServerMax */
        2000u,
    }
};

#define DCM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dcm_MemMap.h"

CONST(Dcm_DspType, DCM_CONST)Dcm_Dsp = 
{
    /* DcmDspComControl */
    &Dcm_DspComControl,
    /* DcmDspCommonAuthorization */
    &Dcm_DspCommonAuthorization[0],
    /* DcmDspControlDTCSetting */
    &Dcm_DspControlDTCSetting,
    /* DcmDspData */
    &Dcm_DspData[0],
    /* DcmDspDid */
    &Dcm_DspDid[0],
    /* DcmDspDidInfo */
    &Dcm_DspDidInfo[0],
    /* DcmDspMemory */
    &Dcm_DspMemory,
    /* DcmDspRoutine */
    &Dcm_DspRoutine[0],
    /* DcmDspSecurityRow */
    &Dcm_DspSecurityRow[0],
    /* DcmDspSessionRow */
    &Dcm_DspSessionRow[0],
};

CONST(Dcm_ConfigType, DCM_CONST)Dcm_Config = 
{
    /* DcmDsd */
    &Dcm_Dsd,
    /* DcmDsl */
    &Dcm_Dsl,
    /* DcmDsp */
    &Dcm_Dsp,
    /* DcmDslMainConnection */
    &Dcm_DslMainConnection[0],
    /* DcmDslProtocolRx */
    &Dcm_DslProtocolRx[0],
    /* DcmDslProtocolTx */
    &Dcm_DslProtocolTx[0]
};

#define DCM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dcm_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
