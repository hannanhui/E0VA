/**
 * @file        BswM_Modules.h
 * @brief       AUTOSAR BSWM_MODULES - BswM_Modules driver header file.
 * @details     BswM_Modules driver header file, containing the Autosar API specification and
 *              other variables and functions that are exported by the BswM_Modules driver.
 * @version     1.2.0
 *
 * @addtogroup  BSWM_MODULES
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
#ifndef BSWM_MODULES_H
#define BSWM_MODULES_H

#if defined(__cplusplus)
extern "C" 
{
#endif /* defined(__cplusplus) */

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/

#include "BswM_Cfg.h"

#if ((STD_ON == BSWM_CANSM_ENABLED) || (BSWM_CANSM_ICOM_ENABLED))
#include <BswM_CanSM.h>
#endif /* ((STD_ON == BSWM_CANSM_ENABLED) || (BSWM_CANSM_ICOM_ENABLED)) */

#if (STD_ON == BSWM_COMM_ENABLED)
#include <BswM_ComM.h>
#endif /* (STD_ON == BSWM_COMM_ENABLED) */

#if (STD_ON == BSWM_DCM_ENABLED)
#include <BswM_Dcm.h>
#endif /* (STD_ON == BSWM_DCM_ENABLED) */

#if (STD_ON == BSWM_ECUM_ENABLED)
#include <BswM_EcuM.h>
#endif /* (STD_ON == BSWM_ECUM_ENABLED) */

#if (STD_ON == BSWM_ETHSM_ENABLED)
#include <BswM_EthSM.h>
#endif /* (STD_ON == BSWM_ETHSM_ENABLED) */

#if (STD_ON == BSWM_FRSM_ENABLED)
#include <BswM_FrSM.h>
#endif /* (STD_ON == BSWM_FRSM_ENABLED) */

#if (STD_ON == BSWM_GENERIC_REQUEST_ENABLED)
#include <BswM_Generic.h>
#endif /* (STD_ON == BSWM_GENERIC_REQUEST_ENABLED) */

#if (STD_ON == BSWM_J1939DCM_ENABLED)
#include <BswM_J1939Dcm.h>
#endif /* (STD_ON == BSWM_J1939DCM_ENABLED) */

#if (STD_ON == BSWM_J1939NM_ENABLED)
#include <BswM_J1939Nm.h>
#endif /* (STD_ON == BSWM_J1939NM_ENABLED) */

#if (STD_ON == BSWM_LINSM_ENABLED)
#include <BswM_LinSM.h>
#endif /* (STD_ON == BSWM_LINSM_ENABLED) */

#if (STD_ON == BSWM_LINTP_ENABLED)
#include <BswM_LinTp.h>
#endif /* (STD_ON == BSWM_LINTP_ENABLED) */

#if (STD_ON == BSWM_NM_ENABLED)
#include <BswM_Nm.h>
#endif /* (STD_ON == BSWM_NM_ENABLED) */

#if (STD_ON == BSWM_NVM_ENABLED)
#include <BswM_NvM.h>
#endif /* (STD_ON == BSWM_NVM_ENABLED) */

#if (STD_ON == BSWM_SCHM_ENABLED)
#include <BswM_SchM.h>
#endif /* (STD_ON == BSWM_RTE_ENABLED) */

#if (STD_ON == BSWM_SD_ENABLED)
#include <BswM_Sd.h>
#endif /* (STD_ON == BSWM_SD_ENABLED) */

#if (STD_ON == BSWM_WDGM_ENABLED)
#include <BswM_WdgM.h>
#endif /* (STD_ON == BSWM_WDGM_ENABLED) */

/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/

#define BSWM_MODULES_VENDOR_ID                    0U
#define BSWM_MODULES_AR_RELEASE_MAJOR_VERSION     4U
#define BSWM_MODULES_AR_RELEASE_MINOR_VERSION     2U
#define BSWM_MODULES_AR_RELEASE_REVISION_VERSION  2U
#define BSWM_MODULES_SW_MAJOR_VERSION             1U
#define BSWM_MODULES_SW_MINOR_VERSION             2U
#define BSWM_MODULES_SW_PATCH_VERSION             0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/

/* Check if current file and BswM_Cfg header file are of the same vendor */
#if(BSWM_MODULES_VENDOR_ID != BSWM_CFG_VENDOR_ID )
#error "BswM_Modules.h and BswM_Cfg.h have different vendor id"
#endif
/* Check if current file and BswM_Cfg header file are of the same Autosar version */
#if(\
		(BSWM_MODULES_AR_RELEASE_MAJOR_VERSION != BSWM_CFG_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_MODULES_AR_RELEASE_MINOR_VERSION != BSWM_CFG_AR_RELEASE_MINOR_VERSION) || \
		(BSWM_MODULES_AR_RELEASE_REVISION_VERSION != BSWM_CFG_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of BswM_Modules.h and BswM_Cfg.h are different "
#endif
/* Check if current file and BswM_Cfg header file are of the same software version */
#if(\
		(BSWM_MODULES_SW_MAJOR_VERSION != BSWM_CFG_SW_MAJOR_VERSION) || \
		(BSWM_MODULES_SW_MINOR_VERSION != BSWM_CFG_SW_MINOR_VERSION) || \
		(BSWM_MODULES_SW_PATCH_VERSION != BSWM_CFG_SW_PATCH_VERSION) \
	)
#error "Software Version Number of BswM_Modules.h and BswM_Cfg.h are different "
#endif

#if ((STD_ON == BSWM_CANSM_ENABLED) || (BSWM_CANSM_ICOM_ENABLED))
/* Check if current file and BswM_CanSM header file are of the same vendor */
#if(BSWM_MODULES_VENDOR_ID != BSWM_CANSM_VENDOR_ID )
#error "BswM_Modules.h and BswM_CanSM.h have different vendor id"
#endif
/* Check if current file and BswM_CanSM header file are of the same Autosar version */
#if(\
		(BSWM_MODULES_AR_RELEASE_MAJOR_VERSION != BSWM_CANSM_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_MODULES_AR_RELEASE_MINOR_VERSION != BSWM_CANSM_AR_RELEASE_MINOR_VERSION) || \
		(BSWM_MODULES_AR_RELEASE_REVISION_VERSION != BSWM_CANSM_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of BswM_Modules.h and BswM_CanSM.h are different "
#endif
/* Check if current file and BswM_CanSM header file are of the same software version */
#if(\
		(BSWM_MODULES_SW_MAJOR_VERSION != BSWM_CANSM_SW_MAJOR_VERSION) || \
		(BSWM_MODULES_SW_MINOR_VERSION != BSWM_CANSM_SW_MINOR_VERSION) || \
		(BSWM_MODULES_SW_PATCH_VERSION != BSWM_CANSM_SW_PATCH_VERSION) \
	)
#error "Software Version Number of BswM_Modules.h and BswM_CanSM.h are different "
#endif
#endif /* ((STD_ON == BSWM_CANSM_ENABLED) || (BSWM_CANSM_ICOM_ENABLED)) */

#if (STD_ON == BSWM_COMM_ENABLED)
/* Check if current file and BswM_ComM header file are of the same vendor */
#if(BSWM_MODULES_VENDOR_ID != BSWM_COMM_VENDOR_ID )
#error "BswM_Modules.h and BswM_ComM.h have different vendor id"
#endif
/* Check if current file and BswM_ComM header file are of the same Autosar version */
#if(\
		(BSWM_MODULES_AR_RELEASE_MAJOR_VERSION != BSWM_COMM_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_MODULES_AR_RELEASE_MINOR_VERSION != BSWM_COMM_AR_RELEASE_MINOR_VERSION) || \
		(BSWM_MODULES_AR_RELEASE_REVISION_VERSION != BSWM_COMM_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of BswM_Modules.h and BswM_ComM.h are different "
#endif
/* Check if current file and BswM_ComM header file are of the same software version */
#if(\
		(BSWM_MODULES_SW_MAJOR_VERSION != BSWM_COMM_SW_MAJOR_VERSION) || \
		(BSWM_MODULES_SW_MINOR_VERSION != BSWM_COMM_SW_MINOR_VERSION) || \
		(BSWM_MODULES_SW_PATCH_VERSION != BSWM_COMM_SW_PATCH_VERSION) \
	)
#error "Software Version Number of BswM_Modules.h and BswM_ComM.h are different "
#endif
#endif /* (STD_ON == BSWM_COMM_ENABLED) */

#if (STD_ON == BSWM_DCM_ENABLED)
/* Check if current file and BswM_Dcm header file are of the same vendor */
#if(BSWM_MODULES_VENDOR_ID != BSWM_DCM_VENDOR_ID )
#error "BswM_Modules.h and BswM_Dcm.h have different vendor id"
#endif
/* Check if current file and BswM_Dcm header file are of the same Autosar version */
#if(\
		(BSWM_MODULES_AR_RELEASE_MAJOR_VERSION != BSWM_DCM_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_MODULES_AR_RELEASE_MINOR_VERSION != BSWM_DCM_AR_RELEASE_MINOR_VERSION) || \
		(BSWM_MODULES_AR_RELEASE_REVISION_VERSION != BSWM_DCM_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of BswM_Modules.h and BswM_Dcm.h are different "
#endif
/* Check if current file and BswM_Dcm header file are of the same software version */
#if(\
		(BSWM_MODULES_SW_MAJOR_VERSION != BSWM_DCM_SW_MAJOR_VERSION) || \
		(BSWM_MODULES_SW_MINOR_VERSION != BSWM_DCM_SW_MINOR_VERSION) || \
		(BSWM_MODULES_SW_PATCH_VERSION != BSWM_DCM_SW_PATCH_VERSION) \
	)
#error "Software Version Number of BswM_Modules.h and BswM_Dcm.h are different "
#endif
#endif /* (STD_ON == BSWM_DCM_ENABLED) */

#if (STD_ON == BSWM_ECUM_ENABLED)
/* Check if current file and BswM_EcuM header file are of the same vendor */
#if(BSWM_MODULES_VENDOR_ID != BSWM_ECUM_VENDOR_ID )
#error "BswM_Modules.h and BswM_EcuM.h have different vendor id"
#endif
/* Check if current file and BswM_EcuM header file are of the same Autosar version */
#if(\
		(BSWM_MODULES_AR_RELEASE_MAJOR_VERSION != BSWM_ECUM_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_MODULES_AR_RELEASE_MINOR_VERSION != BSWM_ECUM_AR_RELEASE_MINOR_VERSION) || \
		(BSWM_MODULES_AR_RELEASE_REVISION_VERSION != BSWM_ECUM_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of BswM_Modules.h and BswM_EcuM.h are different "
#endif
/* Check if current file and BswM_EcuM header file are of the same software version */
#if(\
		(BSWM_MODULES_SW_MAJOR_VERSION != BSWM_ECUM_SW_MAJOR_VERSION) || \
		(BSWM_MODULES_SW_MINOR_VERSION != BSWM_ECUM_SW_MINOR_VERSION) || \
		(BSWM_MODULES_SW_PATCH_VERSION != BSWM_ECUM_SW_PATCH_VERSION) \
	)
#error "Software Version Number of BswM_Modules.h and BswM_EcuM.h are different "
#endif
#endif /* (STD_ON == BSWM_ECUM_ENABLED) */

#if (STD_ON == BSWM_ETHSM_ENABLED)
/* Check if current file and BswM_EthSM header file are of the same vendor */
#if(BSWM_MODULES_VENDOR_ID != BSWM_ETHSM_VENDOR_ID )
#error "BswM_Modules.h and BswM_EthSM.h have different vendor id"
#endif
/* Check if current file and BswM_EthSM header file are of the same Autosar version */
#if(\
		(BSWM_MODULES_AR_RELEASE_MAJOR_VERSION != BSWM_ETHSM_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_MODULES_AR_RELEASE_MINOR_VERSION != BSWM_ETHSM_AR_RELEASE_MINOR_VERSION) || \
		(BSWM_MODULES_AR_RELEASE_REVISION_VERSION != BSWM_ETHSM_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of BswM_Modules.h and BswM_EthSM.h are different "
#endif
/* Check if current file and BswM_EthSM header file are of the same software version */
#if(\
		(BSWM_MODULES_SW_MAJOR_VERSION != BSWM_ETHSM_SW_MAJOR_VERSION) || \
		(BSWM_MODULES_SW_MINOR_VERSION != BSWM_ETHSM_SW_MINOR_VERSION) || \
		(BSWM_MODULES_SW_PATCH_VERSION != BSWM_ETHSM_SW_PATCH_VERSION) \
	)
#error "Software Version Number of BswM_Modules.h and BswM_EthSM.h are different "
#endif
#endif /* (STD_ON == BSWM_ETHSM_ENABLED) */

#if (STD_ON == BSWM_FRSM_ENABLED)
/* Check if current file and BswM_FrSM header file are of the same vendor */
#if(BSWM_MODULES_VENDOR_ID != BSWM_FRSM_VENDOR_ID )
#error "BswM_Modules.h and BswM_FrSM.h have different vendor id"
#endif
/* Check if current file and BswM_FrSM header file are of the same Autosar version */
#if(\
		(BSWM_MODULES_AR_RELEASE_MAJOR_VERSION != BSWM_FRSM_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_MODULES_AR_RELEASE_MINOR_VERSION != BSWM_FRSM_AR_RELEASE_MINOR_VERSION) || \
		(BSWM_MODULES_AR_RELEASE_REVISION_VERSION != BSWM_FRSM_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of BswM_Modules.h and BswM_FrSM.h are different "
#endif
/* Check if current file and BswM_FrSM header file are of the same software version */
#if(\
		(BSWM_MODULES_SW_MAJOR_VERSION != BSWM_FRSM_SW_MAJOR_VERSION) || \
		(BSWM_MODULES_SW_MINOR_VERSION != BSWM_FRSM_SW_MINOR_VERSION) || \
		(BSWM_MODULES_SW_PATCH_VERSION != BSWM_FRSM_SW_PATCH_VERSION) \
	)
#error "Software Version Number of BswM_Modules.h and BswM_FrSM.h are different "
#endif
#endif /* (STD_ON == BSWM_FRSM_ENABLED) */

#if (STD_ON == BSWM_GENERIC_REQUEST_ENABLED)
/* Check if current file and BswM_Generic header file are of the same vendor */
#if(BSWM_MODULES_VENDOR_ID != BSWM_GENERIC_VENDOR_ID )
#error "BswM_Modules.h and BswM_Generic.h have different vendor id"
#endif
/* Check if current file and BswM_Generic header file are of the same Autosar version */
#if(\
		(BSWM_MODULES_AR_RELEASE_MAJOR_VERSION != BSWM_GENERIC_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_MODULES_AR_RELEASE_MINOR_VERSION != BSWM_GENERIC_AR_RELEASE_MINOR_VERSION) || \
		(BSWM_MODULES_AR_RELEASE_REVISION_VERSION != BSWM_GENERIC_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of BswM_Modules.h and BswM_Generic.h are different "
#endif
/* Check if current file and BswM_Generic header file are of the same software version */
#if(\
		(BSWM_MODULES_SW_MAJOR_VERSION != BSWM_GENERIC_SW_MAJOR_VERSION) || \
		(BSWM_MODULES_SW_MINOR_VERSION != BSWM_GENERIC_SW_MINOR_VERSION) || \
		(BSWM_MODULES_SW_PATCH_VERSION != BSWM_GENERIC_SW_PATCH_VERSION) \
	)
#error "Software Version Number of BswM_Modules.h and BswM_Generic.h are different "
#endif
#endif /* (STD_ON == BSWM_GENERIC_REQUEST_ENABLED) */

#if (STD_ON == BSWM_J1939DCM_ENABLED)
/* Check if current file and BswM_J1939Dcm header file are of the same vendor */
#if(BSWM_MODULES_VENDOR_ID != BSWM_J1939DCM_VENDOR_ID )
#error "BswM_Modules.h and BswM_J1939Dcm.h have different vendor id"
#endif
/* Check if current file and BswM_J1939Dcm header file are of the same Autosar version */
#if(\
		(BSWM_MODULES_AR_RELEASE_MAJOR_VERSION != BSWM_J1939DCM_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_MODULES_AR_RELEASE_MINOR_VERSION != BSWM_J1939DCM_AR_RELEASE_MINOR_VERSION) || \
		(BSWM_MODULES_AR_RELEASE_REVISION_VERSION != BSWM_J1939DCM_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of BswM_Modules.h and BswM_J1939Dcm.h are different "
#endif
/* Check if current file and BswM_J1939Dcm header file are of the same software version */
#if(\
		(BSWM_MODULES_SW_MAJOR_VERSION != BSWM_J1939DCM_SW_MAJOR_VERSION) || \
		(BSWM_MODULES_SW_MINOR_VERSION != BSWM_J1939DCM_SW_MINOR_VERSION) || \
		(BSWM_MODULES_SW_PATCH_VERSION != BSWM_J1939DCM_SW_PATCH_VERSION) \
	)
#error "Software Version Number of BswM_Modules.h and BswM_J1939Dcm.h are different "
#endif
#endif /* (STD_ON == BSWM_J1939DCM_ENABLED) */

#if (STD_ON == BSWM_J1939NM_ENABLED)
/* Check if current file and BswM_J1939Nm header file are of the same vendor */
#if(BSWM_MODULES_VENDOR_ID != BSWM_J1939NM_VENDOR_ID )
#error "BswM_Modules.h and BswM_J1939Nm.h have different vendor id"
#endif
/* Check if current file and BswM_J1939Nm header file are of the same Autosar version */
#if(\
		(BSWM_MODULES_AR_RELEASE_MAJOR_VERSION != BSWM_J1939NM_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_MODULES_AR_RELEASE_MINOR_VERSION != BSWM_J1939NM_AR_RELEASE_MINOR_VERSION) || \
		(BSWM_MODULES_AR_RELEASE_REVISION_VERSION != BSWM_J1939NM_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of BswM_Modules.h and BswM_J1939Nm.h are different "
#endif
/* Check if current file and BswM_J1939Nm header file are of the same software version */
#if(\
		(BSWM_MODULES_SW_MAJOR_VERSION != BSWM_J1939NM_SW_MAJOR_VERSION) || \
		(BSWM_MODULES_SW_MINOR_VERSION != BSWM_J1939NM_SW_MINOR_VERSION) || \
		(BSWM_MODULES_SW_PATCH_VERSION != BSWM_J1939NM_SW_PATCH_VERSION) \
	)
#error "Software Version Number of BswM_Modules.h and BswM_J1939Nm.h are different "
#endif
#endif /* (STD_ON == BSWM_J1939NM_ENABLED) */

#if (STD_ON == BSWM_LINSM_ENABLED)
/* Check if current file and BswM_LinSM header file are of the same vendor */
#if(BSWM_MODULES_VENDOR_ID != BSWM_LINSM_VENDOR_ID )
#error "BswM_Modules.h and BswM_LinSM.h have different vendor id"
#endif
/* Check if current file and BswM_LinSM header file are of the same Autosar version */
#if(\
		(BSWM_MODULES_AR_RELEASE_MAJOR_VERSION != BSWM_LINSM_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_MODULES_AR_RELEASE_MINOR_VERSION != BSWM_LINSM_AR_RELEASE_MINOR_VERSION) || \
		(BSWM_MODULES_AR_RELEASE_REVISION_VERSION != BSWM_LINSM_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of BswM_Modules.h and BswM_LinSM.h are different "
#endif
/* Check if current file and BswM_LinSM header file are of the same software version */
#if(\
		(BSWM_MODULES_SW_MAJOR_VERSION != BSWM_LINSM_SW_MAJOR_VERSION) || \
		(BSWM_MODULES_SW_MINOR_VERSION != BSWM_LINSM_SW_MINOR_VERSION) || \
		(BSWM_MODULES_SW_PATCH_VERSION != BSWM_LINSM_SW_PATCH_VERSION) \
	)
#error "Software Version Number of BswM_Modules.h and BswM_LinSM.h are different "
#endif
#endif /* (STD_ON == BSWM_LINSM_ENABLED) */

#if (STD_ON == BSWM_LINTP_ENABLED)
/* Check if current file and BswM_LinTp header file are of the same vendor */
#if(BSWM_MODULES_VENDOR_ID != BSWM_LINTP_VENDOR_ID )
#error "BswM_Modules.h and BswM_LinTp.h have different vendor id"
#endif
/* Check if current file and BswM_LinTp header file are of the same Autosar version */
#if(\
		(BSWM_MODULES_AR_RELEASE_MAJOR_VERSION != BSWM_LINTP_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_MODULES_AR_RELEASE_MINOR_VERSION != BSWM_LINTP_AR_RELEASE_MINOR_VERSION) || \
		(BSWM_MODULES_AR_RELEASE_REVISION_VERSION != BSWM_LINTP_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of BswM_Modules.h and BswM_LinTp.h are different "
#endif
/* Check if current file and BswM_LinTp header file are of the same software version */
#if(\
		(BSWM_MODULES_SW_MAJOR_VERSION != BSWM_LINTP_SW_MAJOR_VERSION) || \
		(BSWM_MODULES_SW_MINOR_VERSION != BSWM_LINTP_SW_MINOR_VERSION) || \
		(BSWM_MODULES_SW_PATCH_VERSION != BSWM_LINTP_SW_PATCH_VERSION) \
	)
#error "Software Version Number of BswM_Modules.h and BswM_LinTp.h are different "
#endif
#endif /* (STD_ON == BSWM_LINTP_ENABLED) */

#if (STD_ON == BSWM_NM_ENABLED)
/* Check if current file and BswM_Nm header file are of the same vendor */
#if(BSWM_MODULES_VENDOR_ID != BSWM_NM_VENDOR_ID )
#error "BswM_Modules.h and BswM_Nm.h have different vendor id"
#endif
/* Check if current file and BswM_Nm header file are of the same Autosar version */
#if(\
		(BSWM_MODULES_AR_RELEASE_MAJOR_VERSION != BSWM_NM_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_MODULES_AR_RELEASE_MINOR_VERSION != BSWM_NM_AR_RELEASE_MINOR_VERSION) || \
		(BSWM_MODULES_AR_RELEASE_REVISION_VERSION != BSWM_NM_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of BswM_Modules.h and BswM_Nm.h are different "
#endif
/* Check if current file and BswM_Nm header file are of the same software version */
#if(\
		(BSWM_MODULES_SW_MAJOR_VERSION != BSWM_NM_SW_MAJOR_VERSION) || \
		(BSWM_MODULES_SW_MINOR_VERSION != BSWM_NM_SW_MINOR_VERSION) || \
		(BSWM_MODULES_SW_PATCH_VERSION != BSWM_NM_SW_PATCH_VERSION) \
	)
#error "Software Version Number of BswM_Modules.h and BswM_Nm.h are different "
#endif
#endif /* (STD_ON == BSWM_NM_ENABLED) */

#if (STD_ON == BSWM_SCHM_ENABLED)
/* Check if current file and BswM_SchM header file are of the same vendor */
#if(BSWM_MODULES_VENDOR_ID != BSWM_SCHM_VENDOR_ID )
#error "BswM_Modules.h and BswM_SchM.h have different vendor id"
#endif
/* Check if current file and BswM_SchM header file are of the same Autosar version */
#if(\
		(BSWM_MODULES_AR_RELEASE_MAJOR_VERSION != BSWM_SCHM_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_MODULES_AR_RELEASE_MINOR_VERSION != BSWM_SCHM_AR_RELEASE_MINOR_VERSION) || \
		(BSWM_MODULES_AR_RELEASE_REVISION_VERSION != BSWM_SCHM_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of BswM_Modules.h and BswM_SchM.h are different "
#endif
/* Check if current file and BswM_SchM header file are of the same software version */
#if(\
		(BSWM_MODULES_SW_MAJOR_VERSION != BSWM_SCHM_SW_MAJOR_VERSION) || \
		(BSWM_MODULES_SW_MINOR_VERSION != BSWM_SCHM_SW_MINOR_VERSION) || \
		(BSWM_MODULES_SW_PATCH_VERSION != BSWM_SCHM_SW_PATCH_VERSION) \
	)
#error "Software Version Number of BswM_Modules.h and BswM_SchM.h are different "
#endif
#endif /* (STD_ON == BSWM_SCHM_ENABLED) */

#if (STD_ON == BSWM_SD_ENABLED)
/* Check if current file and BswM_Sd header file are of the same vendor */
#if(BSWM_MODULES_VENDOR_ID != BSWM_SD_VENDOR_ID )
#error "BswM_Modules.h and BswM_Sd.h have different vendor id"
#endif
/* Check if current file and BswM_Sd header file are of the same Autosar version */
#if(\
		(BSWM_MODULES_AR_RELEASE_MAJOR_VERSION != BSWM_SD_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_MODULES_AR_RELEASE_MINOR_VERSION != BSWM_SD_AR_RELEASE_MINOR_VERSION) || \
		(BSWM_MODULES_AR_RELEASE_REVISION_VERSION != BSWM_SD_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of BswM_Modules.h and BswM_Sd.h are different "
#endif
/* Check if current file and BswM_Sd header file are of the same software version */
#if(\
		(BSWM_MODULES_SW_MAJOR_VERSION != BSWM_SD_SW_MAJOR_VERSION) || \
		(BSWM_MODULES_SW_MINOR_VERSION != BSWM_SD_SW_MINOR_VERSION) || \
		(BSWM_MODULES_SW_PATCH_VERSION != BSWM_SD_SW_PATCH_VERSION) \
	)
#error "Software Version Number of BswM_Modules.h and BswM_Sd.h are different "
#endif
#endif /* (STD_ON == BSWM_SD_ENABLED) */

#if (STD_ON == BSWM_WDGM_ENABLED)
/* Check if current file and BswM_WdgM header file are of the same vendor */
#if(BSWM_MODULES_VENDOR_ID != BSWM_WDGM_VENDOR_ID )
#error "BswM_Modules.h and BswM_WdgM.h have different vendor id"
#endif
/* Check if current file and BswM_WdgM header file are of the same Autosar version */
#if(\
		(BSWM_MODULES_AR_RELEASE_MAJOR_VERSION != BSWM_WDGM_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_MODULES_AR_RELEASE_MINOR_VERSION != BSWM_WDGM_AR_RELEASE_MINOR_VERSION) || \
		(BSWM_MODULES_AR_RELEASE_REVISION_VERSION != BSWM_WDGM_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of BswM_Modules.h and BswM_WdgM.h are different "
#endif
/* Check if current file and BswM_WdgM header file are of the same software version */
#if(\
		(BSWM_MODULES_SW_MAJOR_VERSION != BSWM_WDGM_SW_MAJOR_VERSION) || \
		(BSWM_MODULES_SW_MINOR_VERSION != BSWM_WDGM_SW_MINOR_VERSION) || \
		(BSWM_MODULES_SW_PATCH_VERSION != BSWM_WDGM_SW_PATCH_VERSION) \
	)
#error "Software Version Number of BswM_Modules.h and BswM_WdgM.h are different "
#endif
#endif /* (STD_ON == BSWM_WDGM_ENABLED) */

/*====================================================================================================*
 *                                             CONSTANTS
 *====================================================================================================*/

/*====================================================================================================*
 *                                         DEFINES AND MACROS
 *====================================================================================================*/

/*====================================================================================================*
 *                                               ENUMS
 *====================================================================================================*/

/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS
 *====================================================================================================*/

/*====================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS
 *====================================================================================================*/

/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES
 *====================================================================================================*/

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */
/** @} */

#endif /* !defined BSWM_MODULES_H */
