/**
 * @file        SchM_Dcm.h
 * @brief       AUTOSAR 4.2.2 - 4.2.2 driver header file.
 * @details    	SchM driver header file, containing the Autosar API specification and
 *              other variables and functions that are exported by the SchM driver.
 * @version     1.2.0
 *
 * @addtogroup  SchM
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

#ifndef SCHM_DCM_H
#define SCHM_DCM_H

#ifdef __cplusplus
extern "C"{
#endif

/* PRQA S 0342, 0881 EOF #
 *
 * 1.0342 -- Violates MISRA 2004 Required Rule 19.13, Using the glue operator '##'.
 *
 * 2.0881 -- Violates MISRA 2004 Required Rule 19.12, Using multiple ## operators in the same macro
 * definition.
 *
 * @page misra_violations MISRA-C:2004 violations
 */

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/

/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/
#define SCHM_DCM_VENDOR_ID	                            	(0x00U)
#define SCHM_DCM_AR_RELEASE_MAJOR_VERSION	           	 	(0x04U)
#define SCHM_DCM_AR_RELEASE_MINOR_VERSION	            	(0x02U)
#define SCHM_DCM_AR_RELEASE_REVISION_VERSION	        	(0x02U)
#define SCHM_DCM_SW_MAJOR_VERSION	                    	(0x01U)
#define SCHM_DCM_SW_MINOR_VERSION	                    	(0x02U)
#define SCHM_DCM_SW_PATCH_VERSION	                    	(0x00U)
/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/

/*====================================================================================================*
 *                                             CONSTANTS
 *====================================================================================================*/

/*====================================================================================================*
 *                                         DEFINES AND MACROS
 *====================================================================================================*/
#define SchM_Switch_DcmDiagnosticSessionControl(Mode)			SchM_Switch_##bsnp##_DcmDiagnosticSessionControl(Mode)
#define SchM_Switch_bsnp_DcmDiagnosticSessionControl(Mode)		do{}while(0)

#define SchM_Switch_DcmEcuReset(Mode)							SchM_Switch_##bsnp##_DcmEcuReset(Mode)
#define SchM_Switch_bsnp_DcmEcuReset(Mode)						do{}while(0)

#define SchM_Switch_DcmRapidPowerShutDown(Mode)					SchM_Switch_##bsnp##_DcmRapidPowerShutDown(Mode)
#define SchM_Switch_bsnp_DcmRapidPowerShutDown(Mode)			do{}while(0)

#define SchM_Switch_DcmControlDTCSetting(Mode)					SchM_Switch_##bsnp##_DcmControlDTCSetting(Mode)
#define SchM_Switch_bsnp_DcmControlDTCSetting(Mode)				do{}while(0)
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

#ifdef __cplusplus
}
#endif

#endif /* SCHM_DCM_H */
/** @} */
