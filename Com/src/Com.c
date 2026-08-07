/**
 * @file       	Com.c
 * @brief       Source file of Com module, implementing all services of Com.
 * @version     1.2.0
 * @addtogroup  Com
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

/* PRQA S 0292, 0288, 1503, 1505, 0857, 0791, 0828, 0647,2984,2991,2992,2995,2880,2877,0491,0316 EOF #
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

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
/* @req [SWS_Com_00220] */
#include "Com.h"
#include "PduR_Com.h"
#include "Com_Cbk.h"
#include "Com_Internal.h"
#if(STD_ON == COM_DEV_ERROR_DETECT)
#include "Det.h"
#endif
#ifdef AH_TEST_COM
#include "TestCode.h"
#endif


/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION
 *====================================================================================================*/
#define COM_VENDOR_ID_C 					0U
#define COM_AR_RELEASE_MAJOR_VERSION_C  	4U
#define COM_AR_RELEASE_MINOR_VERSION_C  	2U
#define COM_AR_RELEASE_REVISION_VERSION_C	2U
#define COM_SW_MAJOR_VERSION_C				1U
#define COM_SW_MINOR_VERSION_C				2U
#define COM_SW_PATCH_VERSION_C				0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Com.h header file are of the same vendor */
#if(COM_VENDOR_ID_C != COM_VENDOR_ID )
#error "Com.c and Com.h have different vendor id"
#endif

#if(\
      (COM_AR_RELEASE_MAJOR_VERSION_C != COM_AR_RELEASE_MAJOR_VERSION) || \
      (COM_AR_RELEASE_MINOR_VERSION_C != COM_AR_RELEASE_MINOR_VERSION) || \
      (COM_AR_RELEASE_REVISION_VERSION_C != COM_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of Com.c and Com.h are different "
#endif

/* Check if current file and Com.h header file are of the same software version */
#if(\
      (COM_SW_MAJOR_VERSION_C != COM_SW_MAJOR_VERSION) || \
      (COM_SW_MINOR_VERSION_C != COM_SW_MINOR_VERSION) ||\
	  (COM_SW_PATCH_VERSION_C != COM_SW_PATCH_VERSION)\
      )
#error "Software Version Number of Com.c and Com.h are different "
#endif

/* Check if current file and Com_Cbk.h header file are of the same vendor */
#if(COM_VENDOR_ID_C != COM_VENDOR_ID )
#error "Com.c and Com_Cbk.h have different vendor id"
#endif

#if(\
      (COM_AR_RELEASE_MAJOR_VERSION_C != COM_CBK_AR_RELEASE_MAJOR_VERSION) || \
      (COM_AR_RELEASE_MINOR_VERSION_C != COM_CBK_AR_RELEASE_MINOR_VERSION) || \
      (COM_AR_RELEASE_REVISION_VERSION_C != COM_CBK_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of Com.c and Com_Cbk.h are different "
#endif

/* Check if current file and Com_Cbk.h header file are of the same software version */
#if(\
      (COM_SW_MAJOR_VERSION_C != COM_CBK_SW_MAJOR_VERSION) || \
      (COM_SW_MINOR_VERSION_C != COM_CBK_SW_MINOR_VERSION) ||\
	  (COM_SW_PATCH_VERSION_C != COM_CBK_SW_PATCH_VERSION)\
      )
#error "Software Version Number of Com.c and Com_Cbk.h are different "
#endif

/* Check if current file and Com_Internal.h header file are of the same vendor */
#if(COM_VENDOR_ID_C != COM_VENDOR_ID )
#error "Com.c and Com_Internal.h have different vendor id"
#endif

#if(\
      (COM_AR_RELEASE_MAJOR_VERSION_C != COM_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
      (COM_AR_RELEASE_MINOR_VERSION_C != COM_INTERNAL_AR_RELEASE_MINOR_VERSION) || \
      (COM_AR_RELEASE_REVISION_VERSION_C != COM_INTERNAL_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of Com.c and Com_Internal.h are different "
#endif

/* Check if current file and Com_Internal.h header file are of the same software version */
#if(\
      (COM_SW_MAJOR_VERSION_C != COM_INTERNAL_SW_MAJOR_VERSION) || \
      (COM_SW_MINOR_VERSION_C != COM_INTERNAL_SW_MINOR_VERSION) ||\
	  (COM_SW_PATCH_VERSION_C != COM_INTERNAL_SW_PATCH_VERSION)\
      )
#error "Software Version Number of Com.c and Com_Internal.h are different "
#endif

#ifndef DISABLE_INTERMOD_VERSION_CHECK

#if(\
      (COM_AR_RELEASE_MAJOR_VERSION_C != PDUR_COM_AR_RELEASE_MAJOR_VERSION) || \
      (COM_AR_RELEASE_MINOR_VERSION_C != PDUR_COM_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of Com.c and PduR_Com.h are different "
#endif

#if(STD_ON == COM_DEV_ERROR_DETECT)
#if(\
      (COM_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
      (COM_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of Com.c and Det.h are different "
#endif
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

#define COM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Com_MemMap.h"
STATIC VAR(Com_StatusType, COM_VAR) Com_Status = COM_UNINIT;

P2CONST(Com_ConfigType, COM_CONST, AUTOMATIC) Com_ConfigPtr = NULL_PTR;
#define COM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Com_MemMap.h"

#if(COM_NUMBER_OF_IPDUGROUP > 0u)
#define COM_START_SEC_VAR_NO_INIT_BOOLEAN
#include "Com_MemMap.h"
VAR(boolean, COM_VAR) Com_IPduGroupIsActive[COM_NUMBER_OF_IPDUGROUP];
VAR(boolean, COM_VAR) Com_IPduGroupDMIsActive[COM_NUMBER_OF_IPDUGROUP];
#define COM_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "Com_MemMap.h"
#endif

#if(COM_NUMBER_OF_TXSIGNALGROUP > 0u)
#define COM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Com_MemMap.h"
VAR(Com_TxSignalGroupRunTimeStateType, COM_VAR) Com_TxSignalGroupState[COM_NUMBER_OF_TXSIGNALGROUP];
#define COM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Com_MemMap.h"
#endif

#if(COM_NUMBER_OF_TIMEOUT_SIGNAL > 0u)
#define COM_START_SEC_VAR_NO_INIT_16
#include "Com_MemMap.h"
VAR(uint16, COM_VAR) Com_TimeOut[COM_NUMBER_OF_TIMEOUT_SIGNAL];
#define COM_STOP_SEC_VAR_NO_INIT_16
#include "Com_MemMap.h"
#endif

#if(COM_NUMBER_OF_UPDATEBIT_GWSOURCESIGNAL > 0u)
#define COM_START_SEC_VAR_NO_INIT_BOOLEAN
#include "Com_MemMap.h"
VAR(boolean, COM_VAR) Com_GWSourceSignalUpdate[COM_NUMBER_OF_UPDATEBIT_GWSOURCESIGNAL];
#define COM_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "Com_MemMap.h"
#endif

#if(COM_NUMBER_OF_ONEEVERYNFILTERSIGNAL > 0u)
#define COM_START_SEC_VAR_NO_INIT_32
#include "Com_MemMap.h"
VAR(uint32, COM_VAR) Com_OneEveryNcnt[COM_NUMBER_OF_ONEEVERYNFILTERSIGNAL];
#define COM_STOP_SEC_VAR_NO_INIT_32
#include "Com_MemMap.h"
#endif

#if(COM_NUMBER_OF_MASKNEWDIFFERMASKOLD_SIGNAL > 0u)
#define COM_START_SEC_VAR_NO_INIT_BOOLEAN
#include "Com_MemMap.h"
VAR(boolean, COM_VAR) Com_MaskNewDifferMaskOldTimeOut[COM_NUMBER_OF_MASKNEWDIFFERMASKOLD_SIGNAL];
#define COM_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "Com_MemMap.h"
#endif

#if(COM_NUMBER_OF_RXIPDU > 0)
/*RxPdu*/
#define COM_START_SEC_VAR_NO_INIT_BOOLEAN
#include "Com_MemMap.h"
VAR(boolean, COM_VAR) Com_RxIPduIsActive[COM_NUMBER_OF_RXIPDU];
VAR(boolean, COM_VAR) Com_RxIPduIsReceiving[COM_NUMBER_OF_RXIPDU];
VAR(boolean, COM_VAR) Com_RxIPduDMEnable[COM_NUMBER_OF_RXIPDU];
VAR(boolean, COM_VAR) Com_RxIPduNeedGw[COM_NUMBER_OF_RXIPDU];
VAR(boolean, COM_VAR) Com_RxIPduRxIndication[COM_NUMBER_OF_RXIPDU];
#define COM_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "Com_MemMap.h"

#define COM_START_SEC_VAR_NO_INIT_16
#include "Com_MemMap.h"
VAR(uint16, COM_VAR) Com_RxIPduOffset[COM_NUMBER_OF_RXIPDU];
#define COM_STOP_SEC_VAR_NO_INIT_16
#include "Com_MemMap.h"
#endif

#if(COM_NUMBER_OF_TXIPDU > 0)
/*TxPdu*/
#define COM_START_SEC_VAR_NO_INIT_BOOLEAN
#include "Com_MemMap.h"
VAR(boolean, COM_VAR) Com_TxIPduIsActive[COM_NUMBER_OF_TXIPDU];
VAR(boolean, COM_VAR) Com_TxIPduIsTransmiting[COM_NUMBER_OF_TXIPDU];
VAR(boolean, COM_VAR) Com_TxIPduTMS[COM_NUMBER_OF_TXIPDU];
VAR(boolean, COM_VAR) Com_TxIPduNeedDelay[COM_NUMBER_OF_TXIPDU];
VAR(boolean, COM_VAR) Com_TxIPduTxConfirmation[COM_NUMBER_OF_TXIPDU];
#define COM_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "Com_MemMap.h"

#define COM_START_SEC_VAR_NO_INIT_16
#include "Com_MemMap.h"
VAR(uint16, COM_VAR) Com_TxIPduMDT[COM_NUMBER_OF_TXIPDU];
VAR(uint16, COM_VAR) Com_TxIPduDMTime[COM_NUMBER_OF_TXIPDU];
VAR(uint16, COM_VAR) Com_TxIPduRepeatNum[COM_NUMBER_OF_TXIPDU];
VAR(uint16, COM_VAR) Com_TxIPduRepetitionPeriod[COM_NUMBER_OF_TXIPDU];
VAR(uint16, COM_VAR) Com_TxIPduPeriodCnt[COM_NUMBER_OF_TXIPDU];
VAR(uint16, COM_VAR) Com_TxIPduOffset[COM_NUMBER_OF_TXIPDU];
#define COM_STOP_SEC_VAR_NO_INIT_16
#include "Com_MemMap.h"

#define COM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Com_MemMap.h"
VAR(Com_TxModeModeType, COM_VAR) Com_TxIPduMode[COM_NUMBER_OF_TXIPDU];
#define COM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Com_MemMap.h"
#endif

/*====================================================================================================*
 *                                      LOCAL FUNCTION PROTOTYPES
 *====================================================================================================*/

/*====================================================================================================*
 *                                           LOCAL FUNCTIONS
 *====================================================================================================*/

/*====================================================================================================*
 *                                          GLOBAL FUNCTIONS
 *====================================================================================================*/

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/**
 * @sid 			0x01
 * @brief			This service initializes internal and external interfaces and variables of the COM
 * 					module layer for the further processing.After calling this function the inter-ECU
 * 					communication is still disabled.
 * @param[in]		Config: Pointer to the COM configuration data.
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 * @req [SWS_Com_00128]
 */
FUNC(void , COM_CODE)
Com_Init(P2CONST(Com_ConfigType, AUTOMATIC, COM_CONST_PBCFG) config)
{
	uint16 cnt;
	/**
	 * @req [SWS_Com_00442] When a development error is detected, the function Det_ReportError of the
	 *						development error tracer shall be called
	 */
#if(STD_ON == COM_DEV_ERROR_DETECT )
    if(NULL_PTR == config)
    {
        COM_DET_ERROR_REPORT(COM_SID_INIT, COM_E_PARAM_POINTER);
    }
    else if(Com_Status != COM_UNINIT)
    {
        COM_DET_ERROR_REPORT(COM_SID_INIT, COM_E_INIT_FAILED);
    }
    else
#endif/*(STD_ON == COM_DEV_ERROR_DETECT )*/
    {
    	Com_ConfigPtr = config;
    	Com_InitRxPduBuffer();
    	Com_InitTxPduBuffer();
#if(COM_NUMBER_OF_RXIPDU > 0)
		/**
		 * @req [SWS_Com_00217] Initializes the value of the rxipdu and txipdu runtime buffer
		 * @req [SWS_Com_00015]
		 */
		for(cnt = 0u; cnt < (uint16)COM_LENGTH_OF_RXIPDUBUFFER; cnt++)
		{
			Com_RxIPduRuntimeValue[cnt] = Com_RxIPduOriginalValue[cnt];
		}
#endif
#if(COM_NUMBER_OF_TXIPDU > 0)
		for(cnt = 0u; cnt < (uint16)COM_LENGTH_OF_TXIPDUBUFFER; cnt++)
		{
			Com_TxIPduRuntimeValue[cnt] = Com_TxIPduOriginalValue[cnt];
		}
#endif
		Com_InitSignalRunTimeBuffer();
		Com_InitGroupSignalRunTimeBuffer();
/* Example Initialize the tmc value of the sent signal,provided that the filter condition of the sent
 * signal is not NULL_PTR */
#if(COM_TMCTXSIGNAL_NUMBER > 0u)
		for(cnt = 0u; cnt < COM_TMCTXSIGNAL_NUMBER; cnt++)
		{
#if(COM_TMCTXGROUPSIGNAL_NUMBER > 0u)
			if(cnt < COM_TMCTXGROUPSIGNAL_NUMBER)
			{
				TxGroupSignalTMCBuffer[cnt] = Com_TxSignalOriginalTMC[cnt];
			}
#endif
			TxSignalTMCRunTime[cnt] = Com_TxSignalOriginalTMC[cnt];
		}
#endif
/**
 * @req [SWS_Com_00328]
 * @req [SWS_Com_00444] The pdu group is disabled by default, and the dm group is disabled
 */
#if(COM_NUMBER_OF_IPDUGROUP > 0u)
		for(cnt = 0u; cnt < (uint16)COM_NUMBER_OF_IPDUGROUP; cnt++)
		{
			Com_IPduGroupIsActive[cnt] =(boolean) FALSE;
			Com_IPduGroupDMIsActive[cnt] =(boolean) FALSE;
		}
#endif
/* set the dm timeout counter for all incoming signals to 0 */
#if(COM_NUMBER_OF_TIMEOUT_SIGNAL > 0u)
		for(cnt = 0u;cnt < ((uint16)COM_NUMBER_OF_TIMEOUT_SIGNAL); cnt++)
		{
			Com_TimeOut[cnt] = 0u;
		}
#endif
		Com_Status = COM_INIT;
    }
    return ;
}

/**
 * @sid 			0x02
 * @brief			This service stops the inter-ECU communication. All startedI-PDU groups are stopped
 * 					and have to be started again, if needed, after Com_Init is called. By a call to
 * 					Com_DeInit the AUTOSAR COM module is put into an not initialized state.
 * @param[in]		/
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 * @req [SWS_Com_00129]
 */
FUNC(void , COM_CODE)
Com_DeInit(void)
{
	uint16 cnt;
#if(STD_ON == COM_DEV_ERROR_DETECT )
    if(COM_INIT != Com_Status)
    {
    	COM_DET_ERROR_REPORT(COM_SID_DEINIT, COM_E_UNINIT);
    }
    else
#endif/* (STD_ON == COM_DEV_ERROR_DETECT ) */
    {
    	/* disable all pdu groups */
#if(COM_NUMBER_OF_IPDUGROUP > 0u)
    	for(cnt = 0u;cnt < (uint16)COM_NUMBER_OF_IPDUGROUP; cnt++)
    	{
    		Com_IPduGroupIsActive[cnt] =(boolean) FALSE;
    	}
#endif
#if(COM_NUMBER_OF_RXIPDU > 0)
    	/* set all rxipdu to false */
    	for(cnt = 0u;cnt < (uint16)COM_NUMBER_OF_RXIPDU; cnt++)
    	{
    		Com_RxIPduIsActive[cnt] = (boolean)FALSE;
    	}
#endif
#if(COM_NUMBER_OF_TXIPDU > 0)
    	/* set all txipdu to false */
    	for(cnt = 0u; cnt < (uint16)COM_NUMBER_OF_TXIPDU; cnt++)
    	{
    		Com_TxIPduIsActive[cnt] = (boolean)FALSE;
    	}
#endif
    	/* set status of com to uninit */
    	Com_Status = COM_UNINIT;
    }
}

/**
 * @sid 			0x03
 * @brief			This service starts I-PDU groups.
 * @param[in]		ipduGroupVector: I-PDU group vector containing the activation
 *                  state (stopped = 0/started = 1) for all I-PDU groups.
 *                  initialize: flag to request initialization of the I-PDUs which are newly started
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 * @req [SWS_Com_00792]
 */
#if(COM_NUMBER_OF_IPDUGROUP)
FUNC(void , COM_CODE)
Com_IpduGroupControl(Com_IpduGroupVector const ipduGroupVector,boolean initialize)
{
	Com_IpduGroupIdType cnt;
	uint8 value;
	uint16 loop;
#if(STD_ON == COM_DEV_ERROR_DETECT)
    if(COM_INIT != Com_Status)
    {
        COM_DET_ERROR_REPORT(COM_SID_IPDUGROUPCONTROL, COM_E_UNINIT);
    }
    else
#endif
    {
    	/* PRQA S 2985 EOF #violate MISAR2004_21.1:ingore this warnning */
#if(COM_NUMBER_OF_IPDUGROUP > 0u)
        /* base ipduGroupVector,set the all i-pdu group to enable or disable */
        for(cnt = 0u; cnt < (uint16)COM_NUMBER_OF_IPDUGROUP; cnt++)
        {
            value = ((ipduGroupVector[cnt >> 3u]) >> (cnt & 0x07u));
            value = value & 0x01u;
            Com_IPduGroupIsActive[cnt] = (0x01u == value)? (boolean)TRUE : (boolean)FALSE;
        }
#endif
#if(COM_NUMBER_OF_RXIPDU > 0)
        /**
         * @req [SWS_Com_00771]
         * @req [SWS_Com_00114] base initialize,select if or not init the rx pdu when state change from
         * 						disable to enable
         */
        /**/
        for(loop = 0u; loop < (uint16)COM_NUMBER_OF_RXIPDU; loop++)
        {
            Com_RxIpduControl(loop, initialize);
        }
#endif
#if(COM_NUMBER_OF_TXIPDU > 0)
        for(loop = 0u; loop < (uint16)COM_NUMBER_OF_TXIPDU; loop++)
        {
            Com_TxIpduControl(loop, initialize);
        }
#endif
    }
    return;
}
#endif

/**
 * @sid 			0x06
 * @brief			This service enables or disables I-PDU group Deadline Monitoring.
 * @param[in]		ipduGroupVector: I-PDU group vector containing the activation
 *                  state (stopped = 0/started = 1) for all I-PDU groups.
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 * @req [SWS_Com_00752]
 * @req [SWS_Com_00616]
 * @req [SWS_Com_00617]
 */
#if(COM_NUMBER_OF_IPDUGROUP > 0u)
FUNC(void , COM_CODE)
Com_ReceptionDMControl(Com_IpduGroupVector const ipduGroupVector)
{
	Com_IpduGroupIdType cnt;
	uint8 ret;
	uint16 loop;
	Com_IpduGroupIdType IpduGroupRefNum;
	Com_IpduGroupIdType IpduGroupRefIndex;
	boolean IpduGroupDMEnable = (boolean)FALSE;
	Com_IpduGroupIdType IpduGroupId;
#if(STD_ON == COM_DEV_ERROR_DETECT )
    if(COM_INIT != Com_Status)
    {
    	COM_DET_ERROR_REPORT(COM_SID_RECEPTIONDMCONTROL, COM_E_UNINIT);
    }
    else
#endif/* (STD_ON == COM_DEV_ERROR_DETECT ) */
    {
    	for(cnt = 0U; cnt < (uint16)COM_NUMBER_OF_IPDUGROUP; cnt++)
    	{
    		ret = (ipduGroupVector[cnt >> 3u]) >> (cnt & 0x07u);
    		ret = ret & 0x01u;
    		Com_IPduGroupDMIsActive[cnt] = (0x01u == ret) ? (boolean)TRUE : (boolean)FALSE;
    	}
    	/**
    	 * @req [SWS_Com_00534] If Com_ReceptionDMControl is invoked on an I-PDU group containing only
    	 * 						also Tx-I-PDUs, shall silently ignore the Tx-I-PDUs
    	 */
		for(loop = 0U; loop < (uint16)COM_NUMBER_OF_RXIPDU; loop++)
		{
			IpduGroupRefNum = COM_CFG_RXPDU(loop).ComIPduGroupsRefNumber;
			if(IpduGroupRefNum > 0U)
			{
				for(IpduGroupRefIndex = 0U; (IpduGroupRefIndex < IpduGroupRefNum) \
					&& (IpduGroupDMEnable == (boolean)FALSE);IpduGroupRefIndex++)
				{
					IpduGroupId = Com_ConfigPtr->ComRxIPdu[loop].ComIPduGroupsRef[IpduGroupRefIndex];
					if((boolean)TRUE == Com_IPduGroupDMIsActive[IpduGroupId])
					{
						IpduGroupDMEnable =(boolean) TRUE;
					}
				}
#if(COM_NUMBER_OF_RXIPDU > 0)
				if((boolean)TRUE == IpduGroupDMEnable)
				{

					/**
					 * @req [SWS_Com_00224] If the reception deadline monitoring state of an I-PDU is
					 * 						changed to enabled, set the reception deadline monitoring
					 * @req [SWS_Com_00486]
					 */
					if((boolean)FALSE == Com_RxIPduDMEnable[loop])
					{
						Com_RxIPduDMEnable[loop] =(boolean) TRUE;
#if(COM_NUMBER_OF_TIMEOUT_SIGNAL > 0u)
						Com_ResetRxPduDeadlineMonitorTime(loop);
#endif/* COM_NUMBER_OF_RXSIGNAL+COM_NUMBER_OF_RXSIGNALGROUP > 0U */
					}
				}
				else
				{
					/* @req [SWS_Com_00225] */
					if((boolean)TRUE == Com_RxIPduDMEnable[loop])
					{
						Com_RxIPduDMEnable[loop] =(boolean) FALSE;
#if(COM_NUMBER_OF_TIMEOUT_SIGNAL > 0)
						Com_ClearRxPduDeadlineMonitorTime(loop);
#endif/* COM_NUMBER_OF_RXSIGNAL+COM_NUMBER_OF_RXSIGNALGROUP > 0U */
					}
				}
#endif
			}
    	}
    }
    return ;
}
#endif

/**
 * @sid 			0x07
 * @brief			Returns the status of the AUTOSAR COM module.
 * @param[in]		/
 * @param[out]		/
 * @param[in/out]	/
 * @return			uint8(E_OK,COM_SERVICE_NOT_AVAILABLE,COM_BUSY)
 * @retval			Com_StatusType(COM_UNINIT and COM_INIT)
 *                  COM_UNINIT: the AUTOSAR COM module is not initialized and not usable
 *                  COM_INIT: the AUTOSAR COM module is initialized and usable
 * @req [SWS_Com_00194]
 */
FUNC(Com_StatusType , COM_CODE)
Com_GetStatus(void)
{
	return Com_Status;
}

/**
 * @sid 			0x09
 * @brief			Returns the status of the AUTOSAR COM module.
 * @param[in]		/
 * @param[out]		/
 * @param[in/out]	/
 * @return			uint8(E_OK,COM_SERVICE_NOT_AVAILABLE,COM_BUSY)
 * @retval			Com_StatusType(COM_UNINIT and COM_INIT)
 *                  COM_UNINIT: the AUTOSAR COM module is not initialized and not usable
 *                  COM_INIT: the AUTOSAR COM module is initialized and usable
 * @req [SWS_Com_00426]
 */
FUNC(void , COM_CODE)
Com_GetVersionInfo(Std_VersionInfoType* versioninfo)
{
#if(STD_ON == COM_DEV_ERROR_DETECT )
    if(versioninfo == NULL_PTR)
    {
    	COM_DET_ERROR_REPORT(COM_SID_GETVERSIONINFO, COM_E_PARAM_POINTER);
    }
    else
#endif/* (STD_ON == COM_DEV_ERROR_DETECT ) */
    {
    	versioninfo->moduleID = COM_MODULE_ID;
    	versioninfo->sw_major_version = COM_SW_MAJOR_VERSION;
    	versioninfo->sw_minor_version = COM_SW_MINOR_VERSION;
    	versioninfo->sw_patch_version = COM_SW_PATCH_VERSION;
    	versioninfo->vendorID = COM_VENDOR_ID;
    }
    return;
}


/**
 * @sid 			0x1c
 * @brief			This service sets all bits of the given Com_IpduGroupVector to 0.
 * @param[in]		/
 * @param[out]		ipduGroupVector: I-PDU group vector to be cleared
 * @param[in/out]	/
 * @return			/
 * @retval			/
 * @req [SWS_Com_00749]
 */
FUNC(void , COM_CODE)
Com_ClearIpduGroupVector(Com_IpduGroupVector ipduGroupVector)
{
    uint8 VectorLength;
    uint8 cnt;
#if(STD_ON == COM_DEV_ERROR_DETECT )
    if(COM_INIT != Com_Status)
    {
    	COM_DET_ERROR_REPORT(COM_SID_CLEARIPDUGROUPVECTOR, COM_E_UNINIT);
    }
    else
#endif/*STD_ON == COM_DEV_ERROR_DETECT*/
    {
        VectorLength = (uint8)((((uint8)COM_NUMBER_OF_IPDUGROUP - 1u) >> 3)+ 1u);
        for(cnt = 0u; cnt < VectorLength; cnt++)
        {
            ipduGroupVector[cnt] = 0x00u;
        }
    }
    return ;
}


/**
 * @sid 			0x1d
 * @brief			This service sets the value of a bit in an I-PDU group vector.
 * @param[in]		ipduGroupId: ipduGroup used to identify
 *                  bitval: New value of the corresponding bit
 * @param[out]		/
 * @param[in/out]	ipduGroupVector: I-PDU group vector to be modified
 * @return			/
 * @retval			/
 * @req [SWS_Com_00750]
 * @req [SWS_Com_00623]
 */
#if(COM_NUMBER_OF_IPDUGROUP)
FUNC(void , COM_CODE)
Com_SetIpduGroup(Com_IpduGroupVector ipduGroupVector,Com_IpduGroupIdType ipduGroupId,boolean bitval)
{
	uint8 value = (uint8)0x01;
#if(STD_ON == COM_DEV_ERROR_DETECT )
    if(COM_INIT != Com_Status)
    {
    	COM_DET_ERROR_REPORT(COM_SID_SETIPDUGROUP, COM_E_UNINIT);
    }
    else if(ipduGroupId >= (Com_IpduGroupIdType)COM_NUMBER_OF_IPDUGROUP)
    {
    	COM_DET_ERROR_REPORT(COM_SID_SETIPDUGROUP, COM_E_PARAM);
    }
    else
#endif/* STD_ON == COM_DEV_ERROR_DETECT */
    {
    	value = value << (ipduGroupId & 0x07u);
    	if((boolean)TRUE == bitval)
    	{
    		ipduGroupVector[ipduGroupId >> 3u] |= value;
    	}
    	else
    	{
    		ipduGroupVector[(ipduGroupId >> 3u)] &= (uint8)(~value);
    	}
    }
    return ;
}
#endif

/**
 * @sid 			0x0a
 * @brief			The service Com_SendSignal updates the signal(include group signal) object
 *                  identified by SignalId with the signal referenced by the SignalDataPtr parameter.
 * @param[in]		SignalId: Id of signal to be sent.
 * @param[in]		SignalDataPtr: Reference to the signal data to be transmitted.
 * @param[out]		/
 * @param[in/out]	/
 * @return			uint8(E_OK,COM_SERVICE_NOT_AVAILABLE,COM_BUSY)
 * @retval			E_OK: service has been accepted
 *                  COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was stopped
 *                  (or service failed due to development error)
 *                  COM_BUSY: in case the TP-Buffer is locked for large data types handling
 * @req [SWS_Com_00197]
 * @req [SWS_Com_00625]
 * @req [SWS_Com_00624]
 */
FUNC(uint8 , COM_CODE)
Com_SendSignal(Com_SignalIdType SignalId,P2CONST(void, AUTOMATIC, COM_APPL_CONST) SignalDataPtr)
{
	uint8 ret = (uint8)E_OK;
#if(COM_NUMBER_OF_TXIPDU > 0)
	Com_SignalType signalType;
	PduIdType refPduId;
#endif
#if(COM_NUMBER_OF_TXSIGNALGROUP > 0u)
    Com_SignalIdType groupSignalId;
#endif/* COM_NUMBER_OF_TXSIGNALGROUP > 0 */

#if(STD_ON == COM_DEV_ERROR_DETECT )
    if(COM_INIT != Com_Status)
    {
    	COM_DET_ERROR_REPORT(COM_SID_SENDSIGNAL, COM_E_UNINIT);
    }
    else if(SignalId >= (Com_SignalIdType)(COM_NUMBER_OF_TXSIGNAL + COM_NUMBER_OF_TXGROUPSIGNAL))
    {
    	COM_DET_ERROR_REPORT(COM_SID_SENDSIGNAL, COM_E_PARAM);
    }
    else if(NULL_PTR == SignalDataPtr)
    {
    	COM_DET_ERROR_REPORT(COM_SID_SENDSIGNAL, COM_E_PARAM_POINTER);
    }
    else
#endif/*STD_ON == COM_DEV_ERROR_DETECT*/
    {
#if(COM_NUMBER_OF_TXIPDU > 0)
    	if(SignalId < (Com_SignalIdType)COM_NUMBER_OF_TXSIGNAL)
    	{
    		signalType = COM_CFG_GET_TXSIGNAL_TYPE(SignalId);
    		if((signalType != COM_UINT8_DYN) \
    				&& ((boolean)TRUE != COM_CFG_TXSIGNAL(SignalId).ComInitialValueOnly))
    		{
    			refPduId = COM_CFG_TXSIGNAL(SignalId).ComIpduRefIndex;
    			if((COM_CFG_GET_TXPDU_TYPE(refPduId) == COM_TP) \
    					&& (Com_TxIPduIsTransmiting[refPduId] == (boolean)TRUE))
    			{
    				ret = COM_BUSY;
    			}
    			else
    			{
					ret = Com_HandlePassSignal(SignalId,refPduId,SignalDataPtr);
    			}
    		}
    		else
    		{
    			ret = COM_SERVICE_NOT_AVAILABLE;
    		}
    	}
    	/* if a signal group */
#if(COM_NUMBER_OF_TXSIGNALGROUP > 0u)
        else
        {
            groupSignalId = SignalId - COM_NUMBER_OF_TXSIGNAL;
            ret = Com_HandleTxGroupSignal(groupSignalId, SignalDataPtr);
        }
#endif/* COM_NUMBER_OF_TXSIGNALGROUP > 0u */
#endif
    }
    return ret;
}


/**
 * @sid 			0x21
 * @brief			The service Com_SendDynSignal updates the signal object identified by SignalId with
 * 					the signal referenced by the SignalDataPtr parameter.
 * @param[in]		SignalId: Id of signal to be sent.
 *                  SignalDataPtr: Reference to the signal data to be transmitted.
 *                  Length: Length of the dynamic length signal
 * @param[out]		/
 * @param[in/out]	/
 * @return			uint8(E_OK,E_NOT_OK,COM_SERVICE_NOT_AVAILABLE,COM_BUSY)
 * @retval			E_OK: service has been accepted
 *                  E_NOT_OK: Length is greater than the configured ComSignalLength of this sent signal
 *                  COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was stopped
 *                  COM_BUSY: in case the TP-Buffer is locked
 * @req [SWS_Com_00627]
 * @req [SWS_Com_00628]
 * @req [SWS_Com_00629]
 * @req [SWS_Com_00630]
 */
FUNC(uint8 , COM_CODE)
Com_SendDynSignal(
	Com_SignalIdType SignalId,
	P2CONST(void, AUTOMATIC, COM_APPL_CONST) SignalDataPtr,uint16 Length
)
{
	uint8 ret = (uint8)E_OK;
#if(COM_NUMBER_OF_TXIPDU > 0)
	Com_SignalType signaltype;
	PduIdType refPduId;
#if(COM_NUMBER_OF_TXSIGNALGROUP > 0u)
    Com_SignalIdType groupSignalId;
#endif/* COM_NUMBER_OF_TXSIGNALGROUP > 0u */
#endif
#if(STD_ON == COM_DEV_ERROR_DETECT )
    if(COM_INIT != Com_Status)
    {
    	COM_DET_ERROR_REPORT(COM_SID_SENDDYNSIGNAL, COM_E_UNINIT);
    }
    else if(SignalId >= (Com_SignalIdType)(COM_NUMBER_OF_TXSIGNAL + COM_NUMBER_OF_TXGROUPSIGNAL))
    {
    	COM_DET_ERROR_REPORT(COM_SID_SENDDYNSIGNAL, COM_E_PARAM);
    }
    else if(NULL_PTR == SignalDataPtr)
    {
    	COM_DET_ERROR_REPORT(COM_SID_SENDDYNSIGNAL, COM_E_PARAM_POINTER);
    }
    else
#endif/* STD_ON == COM_DEV_ERROR_DETECT */
    {
#if(COM_NUMBER_OF_TXIPDU > 0)
    	if(SignalId <(Com_SignalIdType) COM_NUMBER_OF_TXSIGNAL)
    	{
    		signaltype = COM_CFG_GET_TXSIGNAL_TYPE(SignalId);
    		/**
    		 * @req [SWS_Com_00753] return invalid if the signal type is not dynamic
    		 */
    		if((signaltype == COM_UINT8_DYN) \
    				&& ((boolean)FALSE == COM_CFG_TXSIGNAL(SignalId).ComInitialValueOnly))
    		{
    			refPduId = COM_CFG_TXSIGNAL(SignalId).ComIpduRefIndex;
    			if((COM_CFG_GET_TXPDU_TYPE(refPduId) == COM_TP) \
    					&& ((Com_TxIPduIsTransmiting[refPduId]) == (boolean)TRUE))
    			{
    				ret = COM_BUSY;

    			}
    			else
    			{
    				if(Length > COM_CFG_TXSIGNAL(SignalId).ComSignalLength)
    				{
#if(STD_ON == COM_DEV_ERROR_DETECT)
                        COM_DET_ERROR_REPORT(COM_SID_SENDDYNSIGNAL, COM_E_PARAM);
#endif/*STD_ON == COM_DEV_ERROR_DETECT */
    					ret =(uint8) E_NOT_OK;
    				}
    				else
    				{
    					ret = Com_HandlePassDynSignal(SignalId,refPduId,SignalDataPtr,Length);
    				}
    			}
    		}
    		else
    		{
    			ret = COM_SERVICE_NOT_AVAILABLE;
    		}
    	}
        /* the signal is Tx Group Signal */
#if(COM_NUMBER_OF_TXSIGNALGROUP > 0u)
        else
        {
            groupSignalId = SignalId - COM_NUMBER_OF_TXSIGNAL;
            ret = Com_HandleTxDynGroupSignal(groupSignalId, SignalDataPtr, Length);
        }
#endif/*COM_NUMBER_OF_TXSIGNALGROUP > 0u */
#endif
    }
    return ret;
}


/**
 * @sid 			0x0b
 * @brief			copies the data of the signal identified by SignalId to the location specified by
 * 					SignalDataPtr
 * @param[in]		SignalId: Id of signal to be received.
 * @param[out]		SignalDataPtr: Reference to the location where the received signal data shall be
 * 					stored
 * @param[in/out]	/
 * @return			uint8(E_OK,COM_SERVICE_NOT_AVAILABLE,COM_BUSY)
 * @retval			E_OK: service has been accepted
 *                  E_NOT_OK: Length is greater than the configured ComSignalLength of this sent signal
 *                  COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was stopped
 *                  COM_BUSY: in case the TP-Buffer is locked for large data types handling
 * @req [SWS_Com_00198]
 * @req [SWS_Com_00631]
 */
FUNC(uint8 , COM_CODE)
Com_ReceiveSignal(Com_SignalIdType SignalId,P2VAR(void, AUTOMATIC, COM_APPL_CONST) SignalDataPtr)
{
#if(COM_NUMBER_OF_RXIPDU > 0)
    PduIdType refPduIdx;
    uint16 initValueId;
    Com_SignalType signalType;
#if(COM_NUMBER_OF_8BITSIGNAL > 0u)
    uint16 signalLength;
    uint16 index;
#endif
    uint16 groupSignalId;
#endif
    uint8 ret = (Std_ReturnType)E_NOT_OK;
#if(STD_ON == COM_DEV_ERROR_DETECT )
    if(COM_INIT != Com_Status)
    {
    	COM_DET_ERROR_REPORT(COM_SID_RECEIVESIGNAL, COM_E_UNINIT);
    }
    else if(SignalId >= (Com_SignalIdType)(COM_NUMBER_OF_RXSIGNAL + COM_NUMBER_OF_RXGROUPSIGNAL))
    {
    	COM_DET_ERROR_REPORT(COM_SID_RECEIVESIGNAL, COM_E_PARAM);
    }
    else if(NULL_PTR == SignalDataPtr)
    {
    	COM_DET_ERROR_REPORT(COM_SID_RECEIVESIGNAL, COM_E_PARAM_POINTER);
    }
    else
#endif/* STD_ON == COM_DEV_ERROR_DETECT */
    {
#if(COM_NUMBER_OF_RXIPDU > 0)
    	if(SignalId <(Com_SignalIdType) COM_NUMBER_OF_RXSIGNAL)
		{
    		refPduIdx = COM_CFG_RXSIGNAL(SignalId).ComIpduRefIndex;
    		initValueId = COM_CFG_RXSIGNAL(SignalId).ComSignalInitValueId;
		}
    	else
    	{
    		groupSignalId = SignalId - (uint16)COM_NUMBER_OF_RXSIGNAL;
    		refPduIdx = COM_CFG_RXSIGNALGROUP(COM_CFG_RXGROUPSIGNAL(groupSignalId).\
    				ComSignalGroupRef).ComIpduRefIndex;
    		initValueId = COM_CFG_RXGROUPSIGNAL(groupSignalId).ComSignalInitValueId;
    	}
    	if(!COM_CHECKRXPDUISENABLE(refPduIdx))
    	{
    		ret = COM_SERVICE_NOT_AVAILABLE;
    	}
    	else
    	{
    		if((boolean)FALSE == Com_RxIPduIsReceiving[refPduIdx])
    		{
    			ret = (Std_ReturnType)E_OK;
    			if(SignalId <(Com_SignalIdType) COM_NUMBER_OF_RXSIGNAL)
    			{
        			signalType = COM_CFG_RXSIGNAL(SignalId).ComSignalType;
        			switch(signalType)
        			{
        				case COM_BOOLEAN:
 #if(COM_NUMBER_OF_BOOLSIGNAL > 0u)
        					*((boolean *)SignalDataPtr) = Com_BoolSignalRuntimeValue[initValueId];
 #endif
        					break;
        				case COM_UINT8:
        				case COM_SINT8:
#if(COM_NUMBER_OF_8BITSIGNAL > 0u)
        					*((uint8 *)SignalDataPtr) = Com_8BitSignalRuntimeValue[initValueId];
#endif
        					break;
        				case COM_UINT8_N:
#if(COM_NUMBER_OF_8BITSIGNAL > 0u)
        					signalLength = COM_CFG_RXSIGNAL(SignalId).ComSignalLength;
				/* PRQA S 0492 EOF # violate MISRA_2004_Rule_17.4:ingore this warnning */
        					for(index = 0u; index < signalLength; index++)
        					{
        						((uint8 *)SignalDataPtr)[index] = \
        								Com_8BitSignalRuntimeValue[initValueId + index];
        					}
#endif
        					break;
        				case COM_UINT16:
        				case COM_SINT16:
 #if(COM_NUMBER_OF_16BITSIGNAL > 0u)
        					*((uint16 *)SignalDataPtr) = Com_16BitSignalRuntimeValue[initValueId];
#endif
        					break;
        				case COM_UINT32:
        				case COM_SINT32:
        				case COM_FLOAT32:
#if(COM_NUMBER_OF_32BITSIGNAL > 0u)
        					*((uint32 *)SignalDataPtr) = Com_32BitSignalRuntimeValue[initValueId];
#endif
    						break;
        				case COM_UINT64:
        				case COM_SINT64:
        				case COM_FLOAT64:
#if(COM_NUMBER_OF_64BITSIGNAL > 0u)
        					*((uint64 *)SignalDataPtr) = Com_64BitSignalRuntimeValue[initValueId];
#endif
    						break;
        				default:break;
        			}
    			}
    			else
    			{
        			signalType = COM_CFG_RXGROUPSIGNAL(groupSignalId).ComSignalType;
        			switch(signalType)
    				{
        				case COM_BOOLEAN:
#if(COM_NUMBER_OF_RXGROUPBOOLSIGNAL > 0u)
        					*((boolean*)SignalDataPtr) = Com_RxGroupBoolSignalShadowBuff[initValueId];
#endif
						break;
        				case COM_UINT8:
        				case COM_SINT8:
#if(COM_NUMBER_OF_RXGROUP8BITSIGNAL > 0u)
        					*((uint8 *)SignalDataPtr) = Com_RxGroup8BitSignalShadowBuff[initValueId];
#endif
        					break;
        				case COM_UINT8_N:
#if(COM_NUMBER_OF_RXGROUP8BITSIGNAL > 0u)
        					signalLength = COM_CFG_RXGROUPSIGNAL(groupSignalId).ComSignalLength;
        					for(index= 0u; index < signalLength ; index++)
        					{
        						((uint8 *)SignalDataPtr)[index] = \
        								Com_RxGroup8BitSignalShadowBuff[initValueId + index];
        					}
#endif
        					break;
        				case COM_UINT16:
        				case COM_SINT16:
#if(COM_NUMBER_OF_RXGROUP16BITSIGNAL > 0u)
        					*((uint16 *)SignalDataPtr) = Com_RxGroup16BitSignalShadowBuff[initValueId];
#endif
        					break;
        				case COM_UINT32:
        				case COM_SINT32:
        				case COM_FLOAT32:
#if(COM_NUMBER_OF_RXGROUP32BITSIGNAL > 0u)
        					*((uint32 *)SignalDataPtr) = Com_RxGroup32BitSignalShadowBuff[initValueId];
#endif
    						break;
        				case COM_UINT64:
        				case COM_SINT64:
        				case COM_FLOAT64:
#if(COM_NUMBER_OF_RXGROUP64BITSIGNAL > 0u)
        					*((uint64 *)SignalDataPtr) = Com_RxGroup64BitSignalShadowBuff[initValueId];
#endif
    						break;
        				default:break;
    				}
    			}
    		}
    		else

    		{
    			ret = COM_BUSY;
    		}
    	}
#endif
    }
    return ret;
}


/**
 * @sid 			0x22
 * @brief			Com_ReceiveDynSignal copies the data of the signal identified by SignalId to the
 *                  location specified by SignalDataPtr and stores the length of the dynamical length
 *                  signal at the position given by the Length parameter.
 * @param[in]		SignalId: Id of signal to be received.
 * @param[out]		SignalDataPtr: Reference to the location where the received signal data shall be
 * 					stored
 * @param[in/out]	Length
 * @return			uint8(E_OK,E_NOT_OK,COM_SERVICE_NOT_AVAILABLE,COM_BUSY)
 * @retval			E_OK: service has been accepted
 *                  E_NOT_OK: in case the Length is smaller than the received length of the dynamic
 *                  length signal
 *                  COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was stopped
 *                  COM_BUSY: in case the TP-Buffer is locked
 * @req [SWS_Com_00690]
 * @req [SWS_Com_00711]
 * @req [SWS_Com_00724]
 */
FUNC(uint8 , COM_CODE)
Com_ReceiveDynSignal(
	Com_SignalIdType SignalId,
	P2VAR(void, AUTOMATIC, COM_APPL_CONST) SignalDataPtr,
	P2CONST(uint16, AUTOMATIC, COM_APPL_CONST) Length
)
{
    Com_SignalType signalType;
    uint8 ret = (Std_ReturnType)E_NOT_OK;
#if(COM_NUMBER_OF_RXIPDU > 0)
    PduIdType refPduIdx;
    uint16 signalLength;
#if(COM_NUMBER_OF_8BITSIGNAL > 0u)
    uint16 initValueId;
    uint8 index;
#endif
#endif
#if(STD_ON == COM_DEV_ERROR_DETECT )
    if(COM_INIT != Com_Status)
    {
    	COM_DET_ERROR_REPORT(COM_SID_RECEIVEDYNSIGNAL, COM_E_UNINIT);
    }
    else if(SignalId >= (Com_SignalIdType)(COM_NUMBER_OF_RXSIGNAL + COM_NUMBER_OF_RXGROUPSIGNAL))
    {
    	COM_DET_ERROR_REPORT(COM_SID_RECEIVEDYNSIGNAL, COM_E_PARAM);
    }
    else if(NULL_PTR == SignalDataPtr)
    {
    	COM_DET_ERROR_REPORT(COM_SID_RECEIVEDYNSIGNAL, COM_E_PARAM_POINTER);
    }
    else
#endif/* STD_ON == COM_DEV_ERROR_DETECT */
    {
    	if(SignalId < (Com_SignalIdType)COM_NUMBER_OF_RXSIGNAL)
		{
#if(COM_NUMBER_OF_RXIPDU > 0)
    		refPduIdx = COM_CFG_RXSIGNAL(SignalId).ComIpduRefIndex;
#endif
    		signalType = COM_CFG_RXSIGNAL(SignalId).ComSignalType;
		}
    	else
    	{
#if(COM_NUMBER_OF_RXIPDU > 0)
    		refPduIdx = COM_CFG_RXSIGNALGROUP(\
    				COM_CFG_RXGROUPSIGNAL(SignalId - (uint16)COM_NUMBER_OF_RXSIGNAL).\
    				ComSignalGroupRef).ComIpduRefIndex;
#endif
    		signalType = COM_CFG_RXGROUPSIGNAL(SignalId - (uint16)COM_NUMBER_OF_RXSIGNAL).ComSignalType;
    	}
    	if(signalType != COM_UINT8_DYN)
    	{
    		ret = COM_SERVICE_NOT_AVAILABLE;
    	}
    	else
    	{
    		/* PRQA S 0715 EOF # violate MISRA_2004_Rule_1.1:ignore warnning */
#if(COM_NUMBER_OF_RXIPDU > 0)
    		if(!COM_CHECKRXPDUISENABLE(refPduIdx))
    		{
    			ret = COM_SERVICE_NOT_AVAILABLE;
    		}
    		else
    		{
        		if((boolean)FALSE == Com_RxIPduIsReceiving[refPduIdx])
        		{
        			ret = (Std_ReturnType)E_OK;
        			if(SignalId <(Com_SignalIdType) COM_NUMBER_OF_RXSIGNAL)
        			{
        				signalLength = COM_CFG_RXSIGNAL(SignalId).ComSignalLength;
    					if(signalLength > *Length)
    					{
    						ret =(uint8) E_NOT_OK;
    					}
    					else
    					{
#if(COM_NUMBER_OF_8BITSIGNAL > 0u)
    						initValueId = Com_ConfigPtr->ComRxSignal[SignalId].ComSignalInitValueId;
    						for(index = 0u; index < signalLength ;index++)
    						{
    							((uint8 *)SignalDataPtr)[index] = \
    									Com_8BitSignalRuntimeValue[initValueId + index];

    						}
#endif
    					}
        			}
        			else
        			{
        				signalLength = COM_CFG_RXGROUPSIGNAL(SignalId - (uint16)COM_NUMBER_OF_RXSIGNAL).ComSignalLength;
        				if(signalLength > *Length)
        				{
        					ret = (uint8)E_NOT_OK;
        				}
        				else
        				{
#if(COM_NUMBER_OF_RXGROUP8BITSIGNAL > 0u)
        					initValueId = COM_CFG_RXGROUPSIGNAL(SignalId - (uint16)COM_NUMBER_OF_RXSIGNAL).\
    								ComSignalInitValueId;
    						for(index = (uint8)0; index < signalLength ;index++)
    						{

    							((uint8 *)SignalDataPtr)[index] = \
    									Com_RxGroup8BitSignalShadowBuff[initValueId + index];

    						}
#endif
        				}
        			}
        		}
        		else
        		{
        			ret = COM_BUSY;
        		}
    		}
#endif
    	}
    }
    return ret;
}

/**
 * @sid 			0x0d
 * @brief			The service Com_SendSignalGroup copies the content of the associated shadow buffer
 * 					to the associated I-PDU.
 * @param[in]		SignalGroupId: Id of signal group to be sent.
 * @param[out]		/
 * @param[in/out]	/
 * @return			uint8(E_OK,COM_SERVICE_NOT_AVAILABLE,COM_BUSY)
 * @retval			E_OK: service has been accepted
 *                  COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was stopped
 *                  COM_BUSY: in case the TP-Buffer is locked
 * @req [SWS_Com_00200]
 * @req [SWS_Com_00635]
 * @req [SWS_Com_00637]
 */
#if(COM_NUMBER_OF_TXSIGNALGROUP > 0u)
FUNC(uint8 , COM_CODE)
Com_SendSignalGroup(Com_SignalGroupIdType SignalGroupId)
{
    uint8 ret = COM_SERVICE_NOT_AVAILABLE;
    PduIdType refPduId;
#if(STD_ON == COM_DEV_ERROR_DETECT)
    if(COM_INIT != Com_Status)
    {
        COM_DET_ERROR_REPORT(COM_SID_SENDSIGNALGROUP, COM_E_UNINIT);
    }
    else if(SignalGroupId >= COM_NUMBER_OF_TXSIGNALGROUP)
    {
        COM_DET_ERROR_REPORT(COM_SID_SENDSIGNALGROUP, COM_E_PARAM);
    }
    else
#endif/*STD_ON == COM_DEV_ERROR_DETECT*/
    {
    	if(COM_CFG_TXSIGNALGROUP(SignalGroupId).ComInitialValueOnly != (boolean)TRUE)
    	{
    		refPduId = COM_CFG_TXSIGNALGROUP(SignalGroupId).ComIpduRefIndex;
    		if(COM_CFG_GET_TXPDU_TYPE(refPduId) == COM_TP \
    				&& Com_TxIPduIsTransmiting[refPduId] == (boolean)TRUE)
    		{
    			ret = COM_BUSY;
    		}
    		else
    		{
    			ret = Com_HandlePassSignalGroup(SignalGroupId,refPduId);
    		}
    	}
    	else
    	{
    		ret = COM_SERVICE_NOT_AVAILABLE;
    	}
    }
    return ret;
}
#endif/* COM_NUMBER_OF_TXSIGNALGROUP > 0 */


/**
 * @sid 			0x0e
 * @brief			The service Com_ReceiveSignalGroup copies the received signal group from the I-PDU
 * 					to the shadow buffer.
 * @param[in]		SignalGroupId: Id of signal group to be received.
 * @param[out]		/
 * @param[in/out]	/
 * @return			uint8(E_OK,COM_SERVICE_NOT_AVAILABLE,COM_BUSY)
 * @retval			E_OK: service has been accepted
 *                  COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was stopped
 *                  COM_BUSY: in case the TP-Buffer is locked
 * @req [SWS_Com_00201]
 * @req [SWS_Com_00638]
 * @req [SWS_Com_00639]
 */
FUNC(uint8 , COM_CODE)
Com_ReceiveSignalGroup(Com_SignalGroupIdType SignalGroupId)
{
#if(COM_NUMBER_OF_RXIPDU > 0)
	PduIdType refPduId;
#endif
    uint8 ret = (Std_ReturnType)E_NOT_OK;
    Com_SignalIdType signalNumber;
    Com_SignalIdType cnt;
    Com_SignalIdType groupSignalId;
#if((COM_NUMBER_OF_RXGROUPBOOLSIGNAL > 0u) || \
		(COM_NUMBER_OF_RXGROUP8BITSIGNAL > 0u) || \
		(COM_NUMBER_OF_RXGROUP16BITSIGNAL > 0u) || \
		(COM_NUMBER_OF_RXGROUP32BITSIGNAL > 0u) || \
		(COM_NUMBER_OF_RXGROUP64BITSIGNAL > 0u))
    uint16 initValueId;
#endif
    uint16 signalLength;
    uint8 index;
    Com_SignalType signalType;
#if(STD_ON == COM_DEV_ERROR_DETECT )
    if(COM_INIT != Com_Status)
    {
    	COM_DET_ERROR_REPORT(COM_SID_RECEIVESIGNALGROUP, COM_E_UNINIT);
    }
    else if(SignalGroupId >= (Com_SignalGroupIdType)COM_NUMBER_OF_RXSIGNALGROUP)
    {
    	COM_DET_ERROR_REPORT(COM_SID_RECEIVESIGNALGROUP, COM_E_PARAM);
    }
    else
#endif/* STD_ON == COM_DEV_ERROR_DETECT */
    {
#if(COM_NUMBER_OF_RXIPDU > 0)
    	refPduId = COM_CFG_RXSIGNALGROUP(SignalGroupId).ComIpduRefIndex;
#endif
#if(COM_NUMBER_OF_RXIPDU > 0)
    	if((boolean)TRUE == Com_RxIPduIsReceiving[refPduId])
    	{
    		ret = COM_BUSY;
    	}
    	else
#endif
    	{
    		signalNumber = COM_CFG_RXSIGNALGROUP(SignalGroupId).ComGroupSignalNumber;
    		for(cnt = 0u; cnt < signalNumber; cnt++)
    		{
    			groupSignalId = COM_CFG_RXSIGNALGROUP(SignalGroupId).ComRxGroupSignalId[cnt];
#if((COM_NUMBER_OF_RXGROUPBOOLSIGNAL > 0u) || \
		(COM_NUMBER_OF_RXGROUP8BITSIGNAL > 0u) || \
		(COM_NUMBER_OF_RXGROUP16BITSIGNAL > 0u) || \
		(COM_NUMBER_OF_RXGROUP32BITSIGNAL > 0u) || \
		(COM_NUMBER_OF_RXGROUP64BITSIGNAL > 0u))
    			initValueId = COM_CFG_RXGROUPSIGNAL(groupSignalId).ComSignalInitValueId;
#endif
    			/**
    			 * @req [SWS_Com_00051] copy the data from the I-PDU buffer to the shadow buffer
    			 */
    			signalType = COM_CFG_RXGROUPSIGNAL(groupSignalId).ComSignalType;
    			if(signalType == COM_BOOLEAN)
    			{
#if(COM_NUMBER_OF_RXGROUPBOOLSIGNAL > 0u)
    				Com_RxGroupBoolSignalShadowBuff[initValueId] = \
    						Com_BoolSignalRuntimeValue[initValueId];
#endif
    			}
    			else if((signalType == COM_UINT8) || (signalType == COM_SINT8))
				{
#if(COM_NUMBER_OF_RXGROUP8BITSIGNAL > 0u)
    				Com_RxGroup8BitSignalShadowBuff[initValueId] = \
    						Com_8BitSignalRuntimeValue[initValueId];
#endif
				}
    			else if((signalType == COM_UINT16) || (signalType == COM_SINT16))
				{
#if(COM_NUMBER_OF_RXGROUP16BITSIGNAL > 0u)
    				Com_RxGroup16BitSignalShadowBuff[initValueId] = \
    						Com_16BitSignalRuntimeValue[initValueId];
#endif
				}
    			else if((signalType == COM_UINT32) || (signalType == COM_SINT32) || \
    					(signalType == COM_FLOAT32))
				{
#if(COM_NUMBER_OF_RXGROUP32BITSIGNAL > 0u)
    				Com_RxGroup32BitSignalShadowBuff[initValueId] = \
    						Com_32BitSignalRuntimeValue[initValueId];
#endif
				}
    			else if((signalType == COM_UINT64) || (signalType == COM_SINT64) || \
    					(signalType == COM_FLOAT64))
				{
#if(COM_NUMBER_OF_RXGROUP64BITSIGNAL > 0u)
    				Com_RxGroup64BitSignalShadowBuff[initValueId] = \
    						Com_64BitSignalRuntimeValue[initValueId];
#endif
				}
    			else if(signalType == COM_UINT8_N)
    			{
    				signalLength = COM_CFG_RXGROUPSIGNAL(groupSignalId).ComSignalLength;
    				for(index = 0u; index < signalLength; index++)
    				{
#if(COM_NUMBER_OF_RXGROUP8BITSIGNAL > 0u)
    					Com_RxGroup8BitSignalShadowBuff[initValueId + index] = \
    							Com_8BitSignalRuntimeValue[initValueId + index];
#endif
    				}
    			}
    			else if(signalType == COM_UINT8_DYN)
				{
#if(COM_NUMBER_OF_RXIPDU > 0)
    				signalLength = Com_RxIPduLength[refPduId].RxIpduLength -\
    						COM_CFG_RXPDU(refPduId).IPduNoDynSignalLength;
					for(index = 0u; index < signalLength; index++)
					{
#if(COM_NUMBER_OF_RXGROUP8BITSIGNAL > 0u)
						Com_RxGroup8BitSignalShadowBuff[initValueId + index] = \
								Com_8BitSignalRuntimeValue[initValueId + index];
#endif
					}
#endif
				}
    			else
    			{
    				/* do nothing */
    			}
    		}
#if(COM_NUMBER_OF_RXIPDU > 0)
    		if(!COM_CHECKRXPDUISENABLE(refPduId))
    		{
    			ret = COM_SERVICE_NOT_AVAILABLE;
    		}
    		else
#endif
    		{
    			ret = (uint8)E_OK;
    		}
    	}
    }
    return ret;
}


/**
 * @sid 			0x10
 * @brief			The service Com_InvalidateSignal invalidates the signal with the given SignalId
 *                  by setting its value to its configured ComSignalDataInvalidValue.
 * @param[in]		SignalId: Id of signal to be invalidated.
 * @param[out]		/
 * @param[in/out]	/
 * @return			uint8(E_OK,COM_SERVICE_NOT_AVAILABLE,COM_BUSY)
 * @retval			E_OK: service has been accepted
 *                  COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was stopped
 *                  COM_BUSY: in case the TP-Buffer is locked
 * @req [SWS_Com_00203]
 * @req [SWS_Com_00642]
 */
FUNC(uint8 , COM_CODE)
Com_InvalidateSignal(Com_SignalIdType SignalId)
{
	uint8 ret = (uint8)E_OK;
#if(COM_NUMBER_OF_TXIPDU > 0)
	Com_SignalType signalType;
    uint16 invalidValueId = 0xffffu;

#if(COM_NUMBER_OF_NVALID_8BITSIGNAL > 0u)
    uint16 signalLength;
#endif
    PduIdType refPduId;
#if(STD_ON == COM_DEV_ERROR_DETECT )
    if(COM_INIT != Com_Status)
    {
    	COM_DET_ERROR_REPORT(COM_SID_INVALIDATESIGNAL, COM_E_UNINIT);
    }
    else if(SignalId >= (Com_SignalIdType)COM_NUMBER_OF_TXSIGNAL)
    {
    	COM_DET_ERROR_REPORT(COM_SID_INVALIDATESIGNAL, COM_E_PARAM);
    }
    else
#endif/*STD_ON == COM_DEV_ERROR_DETECT */
    {
    	refPduId = COM_CFG_TXSIGNAL(SignalId).ComIpduRefIndex;
    	if((COM_TP == COM_CFG_GET_TXPDU_TYPE(refPduId)) \
    			&& ((boolean)TRUE == Com_TxIPduIsTransmiting[refPduId]))
    	{
    		ret = COM_BUSY;
    	}
    	else
    	{
			signalType = COM_CFG_GET_TXSIGNAL_TYPE(SignalId);
#if((COM_NUMBER_OF_NVALID_BOOLSIGNAL > 0u) || \
		(COM_NUMBER_OF_NVALID_8BITSIGNAL > 0u) || \
		(COM_NUMBER_OF_NVALID_16BITSIGNAL > 0u) || \
		(COM_NUMBER_OF_NVALID_32BITSIGNAL > 0u) || \
		(COM_NUMBER_OF_NVALID_64BITSIGNAL > 0u))
			invalidValueId = Com_ConfigPtr->ComTxSignal[SignalId].ComSignalDataInvalidValueId;
#endif
			/**
			 * @req [SWS_Com_00099] perform internally a Com_SendSignal with the configured
			 * 						ComSignalDataInvalidValue
			 * @req [SWS_Com_00286]
			 */
			if(invalidValueId != 0xffffu)
			{
				if(signalType == COM_BOOLEAN)
				{
	#if(COM_NUMBER_OF_NVALID_BOOLSIGNAL > 0u)
					ret = Com_SendSignal(SignalId, &Com_BoolSignalInvalidValue[invalidValueId]);
	#endif
				}
				else if((signalType == COM_UINT8) || (signalType == COM_SINT8) \
						|| (signalType == COM_UINT8_N))
				{
	#if(COM_NUMBER_OF_NVALID_8BITSIGNAL > 0u)
					ret = Com_SendSignal(SignalId, &Com_8BitSignalInvalidValue[invalidValueId]);
	#endif
				}
				else if((signalType == COM_UINT16) || (signalType == COM_SINT16))
				{
	#if(COM_NUMBER_OF_NVALID_16BITSIGNAL > 0u)
					ret = Com_SendSignal(SignalId, &Com_16BitSignalInvalidValue[invalidValueId]);
	#endif
				}
				else if((signalType == COM_UINT32) || (signalType == COM_SINT32) \
						|| (signalType == COM_FLOAT32))
				{
	#if(COM_NUMBER_OF_NVALID_32BITSIGNAL > 0u)
					ret = Com_SendSignal(SignalId, &Com_32BitSignalInvalidValue[invalidValueId]);
	#endif
				}
				else if((signalType == COM_UINT64) || (signalType == COM_SINT64) \
						|| (signalType == COM_FLOAT64))
				{
	#if(COM_NUMBER_OF_NVALID_64BITSIGNAL > 0u)
					ret = Com_SendSignal(SignalId, &Com_64BitSignalInvalidValue[invalidValueId]);
	#endif
				}
				else if(signalType == COM_UINT8_DYN)
				{
	#if(COM_NUMBER_OF_NVALID_8BITSIGNAL > 0u)
					signalLength = COM_CFG_TXSIGNAL(SignalId).ComSignalDataInvalidValueLength;
					ret = Com_SendDynSignal(SignalId, \
							&Com_8BitSignalInvalidValue[invalidValueId], signalLength);
	#endif
					/* PRQA S 2996 EOF #violate MISAR2004_13.7:ingore this warnning */
					if((uint8)E_NOT_OK == ret)
					{
						ret = COM_SERVICE_NOT_AVAILABLE;
					}
				}
				else
				{
					/* do nothing */
				}
			}
			else
			{
				ret = COM_SERVICE_NOT_AVAILABLE;
			}
    	}
    }
#endif
    return ret;
}


/**
 * @sid 			0x1b
 * @brief			The service Com_InvalidateSignalGroup invalidates all group signals of the signal
 *                  group with the given SignalGroupId by setting their values to their configured
 *                  ComSignalDataInvalidValues.
 * @param[in]		SignalGroupId: Id of signal group to be invalidated.
 * @param[out]		/
 * @param[in/out]	/
 * @return			uint8(E_OK,COM_SERVICE_NOT_AVAILABLE,COM_BUSY)
 * @retval			E_OK: service has been accepted
 *                  COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was stopped
 *                  COM_BUSY: in case the TP-Buffer is locked
 * @req [SWS_Com_00557]
 */
#if(COM_NUMBER_OF_TXGROUPSIGNAL > 0u)
FUNC(uint8 , COM_CODE)
Com_InvalidateSignalGroup(Com_SignalGroupIdType SignalGroupId)
{
   	uint8 ret = E_OK;
    PduIdType refPduId;
    Com_SignalIdType signalNumber;
    Com_SignalIdType SignalId;
    Com_SignalIdType cnt;
    Com_SignalType signaltype;
#if((COM_NUMBER_OF_NVALID_BOOLSIGNAL > 0u) || \
		(COM_NUMBER_OF_NVALID_8BITSIGNAL > 0u) || \
		(COM_NUMBER_OF_NVALID_16BITSIGNAL > 0u) || \
		(COM_NUMBER_OF_NVALID_32BITSIGNAL > 0u) || \
		(COM_NUMBER_OF_NVALID_64BITSIGNAL > 0u))
    uint16 signallength;
    uint16 invalidIdx;
#endif
#if(STD_ON == COM_DEV_ERROR_DETECT )
    if(COM_INIT != Com_Status)
    {
    	COM_DET_ERROR_REPORT(COM_SID_INVALIDATESIGNALGROUP, COM_E_UNINIT);
    }
    else if(SignalGroupId >= COM_NUMBER_OF_TXSIGNALGROUP)
    {
    	COM_DET_ERROR_REPORT(COM_SID_INVALIDATESIGNALGROUP, COM_E_PARAM);
    }
    else
#endif/* STD_ON == COM_DEV_ERROR_DETECT */
    {
    	if(TRUE == COM_CFG_TXSIGNALGROUP(SignalGroupId).ComInitialValueOnly)
    	{
    		ret = COM_SERVICE_NOT_AVAILABLE;
    	}
    	else
    	{
    		refPduId = COM_CFG_TXSIGNALGROUP(SignalGroupId).ComIpduRefIndex;
    		if((COM_TP == COM_CFG_GET_TXPDU_TYPE(refPduId)) \
    				&& (TRUE == Com_TxIPduIsTransmiting[refPduId]))
    		{
    			ret = COM_BUSY;
    		}
    		else
    		{
    			signalNumber = COM_CFG_TXSIGNALGROUP(SignalGroupId).ComGroupSignalNumber;
    			for(cnt = 0;cnt < signalNumber; cnt ++)
    			{
    				SignalId = COM_CFG_TXSIGNALGROUP(SignalGroupId).ComTxGroupSignalId[cnt];
    				signaltype = COM_CFG_TXGROUPSIGNAL(SignalId).ComSignalType;
#if((COM_NUMBER_OF_NVALID_BOOLSIGNAL > 0u) || \
		(COM_NUMBER_OF_NVALID_8BITSIGNAL > 0u) || \
		(COM_NUMBER_OF_NVALID_16BITSIGNAL > 0u) || \
		(COM_NUMBER_OF_NVALID_32BITSIGNAL > 0u) || \
		(COM_NUMBER_OF_NVALID_64BITSIGNAL > 0u))
    				invalidIdx = COM_CFG_TXGROUPSIGNAL(SignalId).ComSignalDataInvalidValueId;
#endif
    				/*check the type of the signal*/
    				switch(signaltype)
    				{
    				case COM_BOOLEAN:
#if(COM_NUMBER_OF_NVALID_BOOLSIGNAL > 0u)
    					ret = Com_HandleTxGroupSignal(SignalId, &Com_BoolSignalInvalidValue[invalidIdx]);
#endif
    					break;
    				case COM_UINT8:
    				case COM_SINT8:
    				case COM_UINT8_N:
#if(COM_NUMBER_OF_NVALID_8BITSIGNAL > 0u)
    					ret = Com_HandleTxGroupSignal(SignalId, &Com_8BitSignalInvalidValue[invalidIdx]);
#endif
    					break;
    				case COM_UINT8_DYN:
#if(COM_NUMBER_OF_NVALID_8BITSIGNAL > 0u)
    					signallength = COM_CFG_TXGROUPSIGNAL(SignalId).ComSignalDataInvalidValueLength;
						ret = Com_HandleTxDynGroupSignal(SignalId, \
								&Com_8BitSignalInvalidValue[invalidIdx], signallength);
						/* if E_NOT_OK is returned, ret is invalid */
						if(E_NOT_OK == ret)
						{
							ret = COM_SERVICE_NOT_AVAILABLE;
						}
#endif
    					break;
    				case COM_UINT16:
    				case COM_SINT16:
#if(COM_NUMBER_OF_NVALID_16BITSIGNAL > 0u)
    					ret = Com_HandleTxGroupSignal(SignalId, &Com_16BitSignalInvalidValue[invalidIdx]);
#endif
    					break;
    				case COM_UINT32:
    				case COM_SINT32:
    				case COM_FLOAT32:
#if(COM_NUMBER_OF_NVALID_32BITSIGNAL > 0u)
    					ret = Com_HandleTxGroupSignal(SignalId, &Com_32BitSignalInvalidValue[invalidIdx]);
#endif
    					break;
    				case COM_UINT64:
    				case COM_SINT64:
    				case COM_FLOAT64:
#if(COM_NUMBER_OF_NVALID_64BITSIGNAL > 0u)
    					ret = Com_HandleTxGroupSignal(SignalId, &Com_64BitSignalInvalidValue[invalidIdx]);
#endif
					break;
    				default:
    					break;
    				}
    			}
    		}
    	}
    }
	return ret;
}
#endif


/**
 * @sid 			0x17
 * @brief			By a call to Com_TriggerIPDUSend the I-PDU with the given ID is triggered for
 * 					transmission.
 * @param[in]		PduId: The I-PDU-ID of the I-PDU that shall be triggered for sending
 * @param[out]		/
 * @param[in/out]	/
 * @return			uint8(E_OK,COM_SERVICE_NOT_AVAILABLE,COM_BUSY)
 * @retval			Std_ReturnType
 *                  E_OK: I-PDU was triggered for transmission
 *                  E_NOT_OK: I-PDU is stopped, the transmission could not be triggered
 * @req [SWS_Com_00348]
 * @req [SWS_Com_00861]
 * @req [SWS_Com_00492]
 */
FUNC(Std_ReturnType , COM_CODE)
Com_TriggerIPDUSend(PduIdType PduId)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
#if(COM_NUMBER_OF_TXIPDU > 0)
	PduIdType pduId;
	PduInfoType pduinfo;
	uint16 buffIndex;
	uint16 pdulength;
	uint16 metadatalength;
	boolean retValue = (boolean)TRUE;
	uint8 pducounter = (uint8)0xff;
	PduIdType pdurLayerId;
#endif
#if(STD_ON == COM_DEV_ERROR_DETECT )
    if(COM_INIT != Com_Status)
    {
    	COM_DET_ERROR_REPORT(COM_SID_TRIGGERIPDUSEND, COM_E_UNINIT);
    }
    else if((PduId >= (PduIdType)(COM_NUMBER_OF_RXIPDU + COM_NUMBER_OF_TXIPDU)) || \
    (PduId < (PduIdType)COM_NUMBER_OF_RXIPDU))
    {
    	COM_DET_ERROR_REPORT(COM_SID_TRIGGERIPDUSEND, COM_E_PARAM);
    }
    else
#endif/* STD_ON == COM_DEV_ERROR_DETECT */
    {
#if(COM_NUMBER_OF_TXIPDU > 0)
    	pduId = PduId - (PduIdType)COM_NUMBER_OF_RXIPDU;
    	if(!COM_CHECKTXPDUISENABLE(pduId))
    	{
    		Com_ErrorNotification(pduId);
    		ret = (Std_ReturnType)E_NOT_OK;
    	}
    	else
    	{
			buffIndex = COM_CFG_TXPDU(pduId).ComTxIPduBufIndex;
			pdulength = COM_CFG_TXPDU(pduId).ComIPduInitLength;
    		if(COM_CFG_TXPDU(pduId).ComIPduCallout != NULL_PTR)
    		{
    			pduinfo.SduDataPtr = &Com_TxIPduRuntimeValue[buffIndex];
    			pduinfo.SduLength = pdulength + (PduLengthType)COM_CFG_TXPDU(pduId).MetaDataLength;
    			retValue = COM_CFG_TXPDU(pduId).ComIPduCallout(pduId, &pduinfo);
    		}
    		if((boolean)TRUE == retValue)
    		{
    			/* if the send is through the mdt delay function or the current pdu is being sent */
    			if((Com_TxIPduMDT[pduId] > 0u) \
    					|| ((boolean)TRUE == Com_TxIPduIsTransmiting[pduId]))
    			{
    				Com_TxIPduNeedDelay[pduId] = (boolean)TRUE;
    				ret = (Std_ReturnType)E_OK;
    			}
    			else
    			{
    				metadatalength = COM_CFG_TXPDU(pduId).MetaDataLength;
    				if(COM_NORMAL == COM_CFG_GET_TXPDU_TYPE(pduId))
    				{
    					pduinfo.SduDataPtr = &Com_TxIPduRuntimeValue[buffIndex];
    					pduinfo.SduLength = (PduLengthType)pdulength + (PduLengthType)metadatalength;
    				}
    				else
    				{
    					if(metadatalength != 0u)
    					{
    						pduinfo.SduDataPtr = \
								&Com_TxIPduRuntimeValue[(buffIndex + pdulength) - metadatalength];
    					}
    					else
    					{
    						pduinfo.SduDataPtr = NULL_PTR;
    					}
    					pduinfo.SduLength = pdulength;
    				}
    				if(COM_CFG_TXPDU(pduId).ComIPduCounter != NULL_PTR)
    				{
    					Com_CalCounterValue(pduId);
    					pducounter = Com_TxIPduData[pduId].TxIpduCounter;
    					Com_GetNextCounterValue((boolean)TRUE, pduId);
    				}
    				pdurLayerId = COM_CFG_TXPDU(pduId).PduRLayerId;
    				ret = PduR_ComTransmit(pdurLayerId, &pduinfo);
    				Com_HandleTransmitResult(pduId,ret,pducounter);
    			}
    		}
    	}
#endif
    }
    return ret;
}


/**
 * @sid 			0x28
 * @brief			By a call to Com_TriggerIPDUSendWithMetaData the AUTOSAR COM module updates its
 * 					internal metadata for the I-PDU with the given ID by copying the metadata from
 * 					the given position and with respect to the globally configured metadata length
 * 					of the I-PDU. Then the I-PDU is triggered for transmission.
 * @param[in]		PduId: The I-PDU-ID of the I-PDU that shall be triggered for sending
 * @param[in]		MetaData: A pointer to the metadata for the triggered send-request
 * @param[out]		/
 * @param[in/out]	/
 * @return			uint8(E_OK,COM_SERVICE_NOT_AVAILABLE,COM_BUSY)
 * @retval			Std_ReturnType
 *                  E_OK: I-PDU was triggered for transmission
 *                  E_NOT_OK: I-PDU is stopped, the transmission could not be triggered
 * @req [SWS_Com_00858]
 * @req [SWS_Com_00862]
 */
#if(STD_ON == COM_METADATA_SUPPORT)
FUNC(Std_ReturnType , COM_CODE)
Com_TriggerIPDUSendWithMetaData(PduIdType PduId,P2VAR(uint8, AUTOMATIC, COM_APPL_CONST) MetaData)
{
    Std_ReturnType returnValue = E_NOT_OK;
    PduIdType pduId;
    uint16 refPduIdx;
    uint16 pduLength;
    uint8 metadataLength;
    boolean ret = TRUE;
    PduInfoType pduinfo;
    uint8 counterValue = 0xff;
    PduIdType lowPduId;
    uint8 cnt;
#if(STD_ON == COM_DEV_ERROR_DETECT )
    if(COM_INIT != Com_Status)
    {
        COM_DET_ERROR_REPORT(COM_SID_TRIGGERIPDUSENDWITHMETADATA, COM_E_UNINIT);
    }
    else if((PduId >= (COM_NUMBER_OF_RXIPDU + COM_NUMBER_OF_TXIPDU)) || (PduId < COM_NUMBER_OF_RXIPDU))
    {
        COM_DET_ERROR_REPORT(COM_SID_TRIGGERIPDUSENDWITHMETADATA, COM_E_PARAM);
    }
    else
#endif/* STD_ON == COM_DEV_ERROR_DETECT */
    {
    	pduId = PduId - COM_NUMBER_OF_RXIPDU;
    	if(!COM_CHECKTXPDUISENABLE(pduId))
    	{
    		Com_ErrorNotification(pduId);
    		returnValue = E_NOT_OK;
    	}
    	else
    	{
    		refPduIdx = COM_CFG_TXPDU(pduId).ComTxIPduBufIndex;
    		pduLength = COM_CFG_TXPDU(pduId).ComIPduInitLength;
    		metadataLength = COM_CFG_TXPDU(pduId).MetaDataLength;
    		for(cnt = 0; cnt < metadataLength; cnt++)
    		{
    			Com_TxIPduRuntimeValue[refPduIdx + pduLength + cnt] = MetaData[cnt];
    		}
    		if(COM_CFG_TXPDU(pduId).ComIPduCallout != NULL_PTR)
			{
				pduinfo.SduDataPtr = &Com_TxIPduRuntimeValue[refPduIdx];
				pduinfo.SduLength = pduLength + (uint16)COM_CFG_TXPDU(pduId).MetaDataLength;
				ret = COM_CFG_TXPDU(pduId).ComIPduCallout(pduId, &pduinfo);
			}
    		if(TRUE == ret)
    		{
    			/* if the delay for sending pdu is set or the pdu is being sent,
    			 * you need to enable the delay for pdu */
    			if((Com_TxIPduMDT[pduId] > 0u) \
    					|| (TRUE == Com_TxIPduIsTransmiting[pduId]))
    			{
    				Com_TxIPduNeedDelay[pduId] = TRUE;
    				returnValue = E_OK;
    			}
    			else
    			{
    				if(COM_NORMAL == COM_CFG_TXPDU(pduId).ComIPduType)
    				{
    					pduinfo.SduDataPtr = &Com_TxIPduRuntimeValue[refPduIdx];
    					pduinfo.SduLength = pduLength + metadataLength;
    				}
    				else
    				{
    					if(metadataLength != 0u)
    					{
    						pduinfo.SduDataPtr = &Com_TxIPduRuntimeValue[refPduIdx + pduLength];
    					}
    					else
    					{
    						pduinfo.SduDataPtr = NULL_PTR;
    					}
    					pduinfo.SduLength = pduLength;
    				}
    				/* if the sent pdu has counter parameter, calculate its effectiveness */
    				if(COM_CFG_TXPDU(pduId).ComIPduCounter != NULL_PTR)
    				{
    					Com_CalCounterValue(pduId);
    					counterValue = Com_TxIPduData[pduId].TxIpduCounter;
    					Com_GetNextCounterValue(TRUE, pduId);
    				}
    				/* invoking the pdur_transmit */
    				lowPduId = COM_CFG_TXPDU(pduId).PduRLayerId;
    				returnValue = PduR_ComTransmit(lowPduId, &pduinfo);
    				Com_HandleTransmitResult(pduId,returnValue,counterValue);
    			}
    		}
    	}
    }
	return returnValue;
}
#endif/*STD_ON == COM_METADATA_SUPPORT*/


/**
 * @sid 			0x27
 * @brief			The service Com_SwitchIpduTxMode sets the transmission mode of the I-PDU referenced
 * 					by PduId to Mode.In case the transmission mode changes, the new mode shall
 * 					immediately be effective.In case the requested transmission mode was already active
 * 					for this I-PDU, the call will have no effect.
 * @param[in]		PduId: The I-PDU-ID of the I-PDU that shall be triggered for sending
 * @param[in]		Mode: the transmission mode that shall be set.
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 * @req [SWS_Com_00605]
 * @req [SWS_Com_00784]
 */
FUNC(void , COM_CODE)
Com_SwitchIpduTxMode(PduIdType PduId,boolean Mode)
{
#if(COM_NUMBER_OF_TXIPDU > 0)
	PduIdType txPduId;
#if(STD_ON == COM_DEV_ERROR_DETECT )
    if(COM_INIT != Com_Status)
    {
    	COM_DET_ERROR_REPORT(COM_SID_SWITCHIPDUTXMODE, COM_E_UNINIT);
    }
    else if((PduId >= (PduIdType)(COM_NUMBER_OF_RXIPDU + COM_NUMBER_OF_TXIPDU)) || \
    (PduId < (PduIdType)COM_NUMBER_OF_RXIPDU))
    {
    	COM_DET_ERROR_REPORT(COM_SID_SWITCHIPDUTXMODE, COM_E_PARAM);
    }
    else
#endif/*STD_ON == COM_METADATA_SUPPORT*/
    {
    	txPduId = PduId - (uint16)COM_NUMBER_OF_RXIPDU;
    	if(Mode == (boolean)TRUE)
    	{
    		Com_TxIPduTMS[txPduId] = (boolean)TRUE;
    		Com_TxIPduMode[txPduId] = COM_CFG_TXPDU(txPduId).ComTxModeTrue->ComTxModeMode;
    		Com_TxIPduPeriodCnt[txPduId] = COM_CFG_TXPDU(txPduId).ComTxModeTrue->ComTxModeTimeOffset;
    		Com_TxIPduRepeatNum[txPduId] = 0u;
    		Com_TxIPduRepetitionPeriod[txPduId] = 0u;
    	}
    	else
    	{
    		Com_TxIPduTMS[txPduId] = (boolean)FALSE;
    		Com_TxIPduMode[txPduId] = COM_CFG_TXPDU(txPduId).ComTxModeFalse->ComTxModeMode;
    		Com_TxIPduPeriodCnt[txPduId] = COM_CFG_TXPDU(txPduId).ComTxModeFalse->ComTxModeTimeOffset;
    		Com_TxIPduRepeatNum[txPduId] = 0u;
    		Com_TxIPduRepetitionPeriod[txPduId] = 0u;
    	}
    }
#endif
	return;
}


/**
 * @sid 			0x41
 * @brief			Within this API, the upper layer module (called module) shall check whether the
 *                  available data fits into the buffer size reported by PduInfoPtr->SduLength. If it
 *                  fits, it shall copy its data into the buffer provided by PduInfoPtr->SduDataPtr and
 *                  update the length of the actual copied data in PduInfoPtr->SduLength.If not, it
 *                  returns E_NOT_OK without changing PduInfoPtr.
 * @param[in]		TxPduId: ID of the SDU that is requested to be transmitted.
 * @param[out]		/
 * @param[in/out]	PduInfoPtr: Contains a pointer to a buffer (SduDataPtr) to where the SDU data shall
 * 					be copied, and the available buffer size in SduLengh.On return, the service will
 * 					indicate the length of the copied SDU data in SduLength.
 * @return			Std_ReturnType
 * @retval			E_OK: SDU has been copied and SduLength indicates the number of copied bytes.
 *                  E_NOT_OK: No SDU data has been copied.
 * @req [SWS_Com_00001]
 * @req [SWS_Com_00647]
 * @req [SWS_Com_00869]
 */
FUNC(Std_ReturnType , COM_CODE)
Com_TriggerTransmit(PduIdType TxPduId,P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
	Std_ReturnType ret =(Std_ReturnType) E_NOT_OK;
#if(COM_NUMBER_OF_TXIPDU > 0)
	PduIdType pduId;
	uint16 pduLength;
	uint16 pduBufferIdx;
	PduInfoType pduInfo;
	uint8 cnt;
#if(STD_ON == COM_DEV_ERROR_DETECT)
    if(COM_INIT != Com_Status)
    {
        COM_DET_ERROR_REPORT(COM_SID_TRIGGERTRANSMIT, COM_E_UNINIT);
    }
    else if((TxPduId >= (PduIdType)(COM_NUMBER_OF_RXIPDU + COM_NUMBER_OF_TXIPDU)) || \
    (TxPduId < (PduIdType)COM_NUMBER_OF_RXIPDU))
    {
        COM_DET_ERROR_REPORT(COM_SID_TRIGGERTRANSMIT, COM_E_PARAM);
    }
    else if((NULL_PTR == PduInfoPtr) || (NULL_PTR == PduInfoPtr->SduDataPtr))
    {
        COM_DET_ERROR_REPORT(COM_SID_TRIGGERTRANSMIT, COM_E_PARAM_POINTER);
    }
    else
#endif/*STD_ON == COM_DEV_ERROR_DETECT*/
    {
		pduId = TxPduId - (PduIdType)COM_NUMBER_OF_RXIPDU;
		pduBufferIdx = COM_CFG_TXPDU(pduId).ComTxIPduBufIndex;
		pduLength = COM_CFG_TXPDU(pduId).MetaDataLength + COM_CFG_TXPDU(pduId).ComIPduInitLength;
		/**
		 * @req [SWS_Com_00800] check whether the pdu is activated
		 */
		if(!COM_CHECKTXPDUISENABLE(pduId))
		{
			Com_ErrorNotification(pduId);
		}
		else
		{
			/* if the length of the incoming data is greater than the calculated pdu length,
			 * the part that is longer is discarded */
			if(PduInfoPtr->SduLength >= pduLength)
			{
				PduInfoPtr->SduLength = pduLength;
				for(cnt = 0u;cnt < pduLength;cnt++)
				{
					PduInfoPtr->SduDataPtr[cnt] = Com_TxIPduRuntimeValue[pduBufferIdx + cnt];
				}
				if(COM_CFG_TXPDU(pduId).ComIPduTriggerTransmitCallout != NULL_PTR)
				{
					pduInfo.SduDataPtr = &Com_TxIPduRuntimeValue[pduBufferIdx];
					pduInfo.SduLength = pduLength;
					(void)COM_CFG_TXPDU(pduId).ComIPduTriggerTransmitCallout(pduId, &pduInfo);
				}
				/**
				 * @req [SWS_Com_00578] If ComTxIPduClearUpdateBit of an I-PDU is configured to
				 * 						TriggerTransmit, clear all update-bits of all contained signals
				 * 						and signal groups after the contents of this I-PDU was
				 * 						successfully requested by Com_TriggerTransmit
				 */
				if(COM_TRIGGERTRANSMIT == COM_CFG_TXPDU(pduId).ComTxIPduClearUpdateBit)
				{
					Com_ClearUpdates(pduId);
				}
				Com_TxIPduIsTransmiting[pduId] =(boolean) TRUE;
				ret =(Std_ReturnType) E_OK;
			}
		}
    }
#endif
    return ret;
}

/**
 * @sid 			0x18
 * @brief			This function performs the processing of the AUTOSAR COM module's receive processing
 * 					that are not directly handled within the COM's functions invoked by the PDU-R, for
 * 					example Com_RxIndication.
 * @param[in]		/
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 * @req [SWS_Com_00664]
 * @req [SWS_Com_00399]
 */
FUNC(void , COM_CODE)
Com_MainFunctionRx(void)
{
#if(COM_NUMBER_OF_RXIPDU > 0)
    PduIdType pduId;
#endif
#if(STD_ON == COM_DEV_ERROR_DETECT)
    if(COM_INIT != Com_Status)
    {
    	COM_DET_ERROR_REPORT(COM_SID_MAINFUNCTIONRX, COM_E_UNINIT);
    }
    else
#endif/*STD_ON == COM_DEV_ERROR_DETECT*/
    {
#if(COM_NUMBER_OF_RXIPDU > 0)
    	for(pduId =0u;pduId < (uint16)COM_NUMBER_OF_RXIPDU;pduId++)
    	{
    		/**
    		 * @req [SWS_Com_00684]
    		 * @req [SWS_Com_00713] If an I-PDU is stopped shall disable its reception processing.
    		 */
    		if(COM_CHECKRXPDUISENABLE(pduId))
    		{
				if((boolean)TRUE == Com_RxIPduRxIndication[pduId])
				{
					Com_HandlePdu(pduId);
					Com_RxIPduRxIndication[pduId] = (boolean)FALSE;
					/**
					 * @req [SWS_Com_00370] The Signal Gateway shall scale down to no size if no signal
					 * 						routing functionality is needed
					 */
					if((boolean)TRUE == COM_CFG_RXPDU(pduId).IPduGW)
					{
						Com_RxIPduNeedGw[pduId] = (boolean)TRUE;
					}
					else
					{
						Com_RxIPduNeedGw[pduId] = (boolean)FALSE;
					}
				}
				/**
				 * @req [SWS_Com_00291] perform an I-PDU based reception deadline monitoring for signals
				 * 						without an update-bit
				 */
				if((boolean)TRUE == Com_RxIPduDMEnable[pduId])
				{
#if((COM_NUMBER_OF_RXSIGNAL > 0u) && (COM_NUMBER_OF_TIMEOUT_SIGNAL > 0u))
					Com_HandleReceiveDm(pduId);
#endif
/* if the number of the pdu group greater than 0 */
#if((COM_NUMBER_OF_RXSIGNALGROUP > 0u) && (COM_NUMBER_OF_TIMEOUT_SIGNAL > 0u))
					Com_RxGroupSignalMainFunction(pduId);
#endif/* COM_NUMBER_OF_RXSIGNALGROUP > 0 */
				}
    		}
    	}
#endif
    }
	return ;
}

/**
 * @sid 			0x19
 * @brief			This function performs the processing of the AUTOSAR COM module's transmission
 * 					activities that are not directly handled within the COM's function invoked by the
 * 					RTE, for example Com_SendSignal.
 * @param[in]		/
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 * @req [SWS_Com_00665]
 * @req [SWS_Com_00400]
 */
FUNC(void , COM_CODE)
Com_MainFunctionTx(void)
{
#if(COM_NUMBER_OF_TXIPDU > 0)
	boolean needDelay =(boolean) FALSE;
	boolean allowSend = (boolean)FALSE;
    PduIdType pduId;
	Com_TxModeModeType mode;
#if(STD_ON == COM_DEV_ERROR_DETECT)
    if(COM_INIT != Com_Status)
    {
        COM_DET_ERROR_REPORT(COM_SID_MAINFUNCTIONTX, COM_E_UNINIT);
    }
    else
#endif/*STD_ON == COM_DEV_ERROR_DETECT*/
    {
    	for(pduId = 0u; pduId < (PduIdType)COM_NUMBER_OF_TXIPDU; pduId++)
    	{
    		/**
    		 * @req [SWS_Com_00777] If an I-PDU is stopped as result of a call to Com_IpduGroupControl,
    		 * 						COM module shall cancel any outstanding transmission requests for
    		 * 						this I-PDU. This includes cancelling any potential retries with
    		 * 						respect to ComRetryFailedTransmitRequests*/
    		if(COM_CHECKTXPDUISENABLE(pduId))
    		{

    			Com_CheckPduIsDelay(pduId,&needDelay);
    			/**
    			 * @req [SWS_Com_00135] The AUTOSAR COM module shall not initiate transmissions for
    			 * 						I-PDUs that have the ComTxModeMode (ECUC_Com_00137) NONE
    			 */
    			mode = Com_TxIPduMode[pduId];
    			if(mode == COM_DIRECT)
    			{
    				allowSend = Com_TxDirect(pduId, needDelay);
    			}
    			else if(mode == COM_PERIODIC)
    			{
    				allowSend = Com_TxPeriodic(pduId, needDelay);
    			}
    			else if(mode == COM_MIXED)
    			{
    				allowSend = Com_TxMix(pduId, needDelay);
    			}
    			else
    			{
    				/* do nothing */
    			}
    			if(Com_TxIPduTxConfirmation[pduId] == (boolean)TRUE)
    			{
    				Com_Confirmation(pduId);
    				Com_TxIPduTxConfirmation[pduId] = (boolean)FALSE;
    			}
    			if((boolean)TRUE == allowSend)
    			{
    				if((COM_TP == COM_CFG_TXPDU(pduId).ComIPduType) && \
    						((boolean)TRUE == Com_TxIPduIsTransmiting[pduId]))
    				{
    					allowSend =(boolean) FALSE;
    					/**
    					 * @req [SWS_Com_00863] report the runtime error COM_E_SKIPPED_- TRANSMISSION.
    					 */
#if(STD_ON == COM_DEV_ERROR_DETECT)
    					COM_DET_ERROR_REPORT(COM_SID_MAINFUNCTIONTX,COM_E_SKIPPED_TRANSMISSION);
#endif
    				}
    			}
    			if((boolean)TRUE == allowSend)
				{
    				/**
    				 * @req [SWS_Com_00478] The AUTOSAR COM module shall send out an I-PDU at most once
    				 * 						within one call of Com_MainFunctionTx
    				 */
    				Com_SendPdu(pduId);
				}
    		}
    	}
    }
#endif
    return;
}

/**
 * @sid 			0x1a
 * @brief			Calls the signal gateway part of the AUTOSAR COM module to forward received signals
 * 					to be routed.
 * @param[in]		/
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 * @req [SWS_Com_00357]
 * @req [SWS_Com_00361]
 * @req [SWS_Com_00701]
 * @req [SWS_Com_00359]
 * @req [SWS_Com_00666]
 * @req [SWS_Com_00669]
 */
FUNC(void , COM_CODE)
Com_MainFunctionRouteSignals(void)
{
#if(COM_NUMBER_OF_RXIPDU > 0)
	PduIdType PduId;
#endif
#if (0u < COM_NUMBER_OF_GWMAPPING)
	Com_GWSignalType GwSourceSignalType;
	Com_SignalIdType GwSourceSignalId;
	Com_SignalGroupIdType SignalGroupId;
	uint16 cnt;
#endif/* 0u < COM_NUMBER_OF_GWMAPPING */
#if(STD_ON == COM_DEV_ERROR_DETECT)
	if(COM_INIT != Com_Status)
	{
		COM_DET_ERROR_REPORT(COM_SID_MAINFUNCTIONROUTESIGNALS, COM_E_UNINIT);
	}
	else
#endif/* STD_ON == COM_DEV_ERROR_DETECT */
	{
#if(COM_NUMBER_OF_RXIPDU > 0)
		/* Traverse all the pdu groups and find the pdu of the source signal */
		for(PduId =(PduIdType) 0; PduId < (PduIdType)COM_NUMBER_OF_RXIPDU; PduId ++)
		{
			if((boolean)TRUE == Com_RxIPduNeedGw[PduId])
			{
#if (0u < COM_NUMBER_OF_GWMAPPING)
				for(cnt = 0u; cnt < (uint16)COM_NUMBER_OF_GWMAPPING; cnt ++)
				{
					GwSourceSignalType = Com_ConfigPtr->ComGwMapping[cnt].ComGwSourceSignalType;
					GwSourceSignalId = Com_ConfigPtr->ComGwMapping[cnt].ComGwSourceSignalId;
					switch(GwSourceSignalType)
					{
							/**
							 * @req [SWS_Com_00833] shall support individual group signals of a source
							 * 						signal group to a individual target signals
							 */
						case COM_SIGNAL:
							if(PduId == Com_ConfigPtr->ComRxSignal[GwSourceSignalId].ComIpduRefIndex)
							{
								Com_GwSignal(cnt, GwSourceSignalType, GwSourceSignalId);
							}
							break;
							/**
							 * @req [SWS_Com_00383]
							 * @req [SWS_Com_00735] route signal groups in a consistent manner. transfer
													a signal group as one consistent set of data during
													a routing operation
							 */
						case COM_SIGNAL_GROUP:
							if(PduId == COM_CFG_RXSIGNALGROUP(GwSourceSignalId).ComIpduRefIndex)
							{
								Com_GwSignal(cnt, GwSourceSignalType, GwSourceSignalId);
							}
							break;
						case COM_GROUP_SIGNAL:
							SignalGroupId = COM_CFG_RXGROUPSIGNAL(GwSourceSignalId).ComSignalGroupRef;
							if(PduId == COM_CFG_RXSIGNALGROUP(SignalGroupId).ComIpduRefIndex)
							{
								Com_GwSignal(cnt, GwSourceSignalType, GwSourceSignalId);
							}
							break;
						default:
							break;
					}
				}
#endif/* 0u < COM_NUMBER_OF_GWMAPPING */
				Com_RxIPduNeedGw[PduId] = (boolean)FALSE;
			}
		}
#endif
	}
	return;
}

/**
 * @sid 			0x42
 * @brief			Indication of a received I-PDU from a lower layer communication interface module.
 * @param[in]		RxPduId: ID of the received I-PDU.
 *                  PduInfoPtr: Contains the length (SduLength) of the received I-PDU and a pointer to
 *                  a buffer (SduDataPtr) containing the I-PDU.
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 * @req [SWS_Com_00123]
 */
FUNC(void ,COM_CODE)
Com_RxIndication(PduIdType RxPduId,P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
#if(COM_NUMBER_OF_RXIPDU > 0)
	boolean ret = (boolean)TRUE;
    boolean allowReceive = (boolean)FALSE;
#endif
#if(STD_ON == COM_DEV_ERROR_DETECT)
    if(COM_INIT != Com_Status)
    {
        COM_DET_ERROR_REPORT(COM_SID_RXINDICATION, COM_E_UNINIT);
    }
    else if(RxPduId >= (PduIdType)COM_NUMBER_OF_RXIPDU)
    {
        COM_DET_ERROR_REPORT(COM_SID_RXINDICATION, COM_E_PARAM);
    }
    else if((NULL_PTR == PduInfoPtr) || (NULL_PTR == PduInfoPtr->SduDataPtr))
    {
        COM_DET_ERROR_REPORT(COM_SID_RXINDICATION, COM_E_PARAM_POINTER);
    }
    else
#endif/* STD_ON == COM_DEV_ERROR_DETECT */
    {
#if(COM_NUMBER_OF_RXIPDU > 0)

    	/**
    	 * @req [SWS_Com_00794]
    	 * @req [SWS_Com_00575]
    	 * @req [SWS_Com_00684] when pdu is activated, the data length is greater than the minimum and
    	 * 						is less than the maximum, and the length of the pdu is valid
    	 */
    	if(COM_CHECKRXPDUISENABLE(RxPduId))
    	{
        	/**
    		 * @req [SWS_Com_00574] check the received data length
    		 */
        	if(PduInfoPtr->SduLength <= COM_CFG_RXPDU(RxPduId).ComIPduInitLength)
        	{
        		if(NULL_PTR != COM_CFG_RXPDU(RxPduId).ComIPduCallout)
        		{
        			ret = COM_CFG_RXPDU(RxPduId).ComIPduCallout(RxPduId, PduInfoPtr);
        		}
        		if(ret == (boolean)TRUE)
        		{
            		/**
            		 * @req [SWS_Com_00715]
            		 * @req [SWS_Com_00738] When a (large) I-PDU with a configured reception deadline
            		 * 						monitoring is received successfully, reset the reception
            		 * 						deadline monitoring timer
            		 */
            		if((boolean)TRUE == Com_RxIPduDMEnable[RxPduId])
            		{
#if(COM_NUMBER_OF_TIMEOUT_SIGNAL > 0)
            			Com_ResetDMTime(RxPduId, PduInfoPtr);
#endif
            		}
            		Com_HandleRxPduCounter(RxPduId,&allowReceive,PduInfoPtr);
        		}
        		Com_HandleReceivePdu(allowReceive, RxPduId);
        	}
    	}
#endif
    }
	return;
}

/**
 * @sid 			0x01
 * @brief			This service Initializes internal and external interfaces of the CAN Interface for
 * 					the further processing.
 * @param[in]		id: Identification of the received I-PDU.
 *                  result: Result of the reception.
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 * @req [SWS_Com_00650]
 */
FUNC(void,COM_CODE)
Com_TpRxIndication(PduIdType id,Std_ReturnType result)
{
#if(COM_NUMBER_OF_RXIPDU > 0)
	boolean ret = (boolean)TRUE;
	PduInfoType pduinfo;
	PduIdType bufferIndex;
	uint16 cnt;
	boolean counterIsValid;
	uint8 receiveCounter;
	uint16 pdulength;
#endif
#if(STD_ON == COM_DEV_ERROR_DETECT)
    if(COM_INIT != Com_Status)
    {
        COM_DET_ERROR_REPORT(COM_SID_TPRXINDICATION, COM_E_UNINIT);
    }
    else if(id >= (PduIdType)COM_NUMBER_OF_RXIPDU)
    {
        COM_DET_ERROR_REPORT(COM_SID_TPRXINDICATION, COM_E_PARAM);
    }
    else
#endif/* STD_ON == COM_DEV_ERROR_DETECT */
    {
#if(COM_NUMBER_OF_RXIPDU > 0)
    	/**
    	 * @req [SWS_Com_00713] If an I-PDU is stopped shall disable its reception processing.
    	 */
    	if(COM_CHECKRXPDUISENABLE(id))
    	{
    		Com_RxIPduIsReceiving[id] =(boolean) FALSE;
    		bufferIndex = COM_CFG_RXPDU(id).ComRxIPduBufIndex;
    		if((Std_ReturnType)E_OK == result)
    		{
    			pduinfo.SduDataPtr = &Com_RxIPduRuntimeValue[bufferIndex];
    			pduinfo.SduLength = (PduLengthType)Com_RxIPduLength[id].RxIpduLength + \
    					(PduLengthType)COM_CFG_RXPDU(id).MetaDataLength;
    			/**
    			 * @req [SWS_Com_00715] When a I-PDU with a configured reception deadline monitoring,
    			 * 						reset the reception deadline monitoring timer
    			 */
    			if((boolean)TRUE == Com_RxIPduDMEnable[id])
    			{
#if(COM_NUMBER_OF_TIMEOUT_SIGNAL > 0)
    				Com_ResetDMTime(id, &pduinfo);
#endif
    			}
    			if(NULL_PTR == COM_CFG_RXPDU(id).ComIPduCounter)
    			{
    				counterIsValid = (boolean)TRUE;
    			}
    			else
    			{
    				receiveCounter = (boolean)Com_UnPackCounter(id);
    				counterIsValid = (boolean)Com_CalCounterIsValid(id, receiveCounter);
    			}
    			if((boolean)TRUE == counterIsValid)
    			{
    				if(NULL_PTR != COM_CFG_RXPDU(id).ComIPduCallout)
					{
						ret = COM_CFG_RXPDU(id).ComIPduCallout(id, &pduinfo);
					}
    				if(ret == (boolean)TRUE)
    				{
        				if(COM_IMMEDIATE == COM_CFG_RXPDU(id).ComIPduSignalProcessing)
        				{
        					Com_RxIPduRxIndication[id] = (boolean)FALSE;
        					Com_HandlePdu(id);
        				}
        				else
        				{
        					Com_RxIPduRxIndication[id] = (boolean)TRUE;
        				}
    				}
    			}
    		}
    		/**
    		 * @req [SWS_Com_00838] TP PDU false receipt, treat all signals of the received large I-PDU
    		 * 						exactly like invalidated signals.
    		 */
    		else
    		{
    			pdulength = (uint16)COM_CFG_RXPDU(id).ComIPduInitLength;
    			for(cnt = 0u; cnt < pdulength; cnt ++)
    			{
    				Com_RxIPduRuntimeValue[bufferIndex + cnt] = Com_RxIPduOriginalValue[bufferIndex + cnt];
    			}
    			Com_HandleInvalidPdu(id);
    		}
    	}
#endif
    }
    return;
}


/**
 * @sid 			0x40
 * @brief			The lower layer communication interface module confirms the transmission of an IPDU
 * @param[in]		TxPduId: ID of the I-PDU that has been transmitted.
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 * @req [SWS_Com_00124]
 */
FUNC(void, COM_CODE)
Com_TxConfirmation(PduIdType TxPduId)
{
#if(COM_NUMBER_OF_TXIPDU > 0)
	Com_IPduSignalProcessingType signalProcessing;
	PduIdType PduId;
#if(STD_ON == COM_DEV_ERROR_DETECT)
    if(COM_INIT != Com_Status)
    {
        COM_DET_ERROR_REPORT(COM_SID_TXCONFIRMATION, COM_E_UNINIT);
    }
    else if((TxPduId >= (PduIdType)(COM_NUMBER_OF_RXIPDU + COM_NUMBER_OF_TXIPDU)) || \
    (TxPduId < (PduIdType)COM_NUMBER_OF_RXIPDU))
    {
        COM_DET_ERROR_REPORT(COM_SID_TXCONFIRMATION, COM_E_PARAM);
    }
    else
#endif/* STD_ON == COM_DEV_ERROR_DETECT */
    {
    	PduId = TxPduId - (PduIdType)COM_NUMBER_OF_RXIPDU;
    	if(COM_CHECKTXPDUISENABLE(PduId))
    	{
    		if(Com_TxIPduRepeatNum[PduId] > 0u)
    		{
    			Com_TxIPduRepeatNum[PduId]--;
    			if(0u == Com_TxIPduRepeatNum[PduId])
    			{
    				/* @req [SWS_Com_00305] */
    				Com_TxIPduDMTime[PduId] = 0u;
    				Com_TxIPduRepetitionPeriod[PduId] = 0u;
    				signalProcessing = COM_CFG_TXPDU(PduId).ComIPduSignalProcessing;
    				if(signalProcessing == COM_IMMEDIATE)
    				{
						Com_Confirmation(PduId);
						Com_TxIPduTxConfirmation[PduId] =(boolean) FALSE;
    				}
    				else
    				{
    					Com_TxIPduTxConfirmation[PduId] =(boolean) TRUE;
    				}
    			}
    		}
    		/**
    		 * @req [SWS_Com_00577] If the update bit is set, the update bit is to be cleared
    		 */
    		if(COM_CONFIRMATION == COM_CFG_TXPDU(PduId).ComTxIPduClearUpdateBit)
    		{
    			Com_ClearUpdates(PduId);
    		}
    		/**
    		 * @req [SWS_Com_00697] reset the transmission deadline monitoring timer for this I-PDU
    		 * 						which transmission mode is NONE
    		 */
    		if((COM_NONE == COM_CFG_TXPDU(PduId).ComTxModeTrue->ComTxModeMode) \
    				&& (NULL_PTR == COM_CFG_TXPDU(PduId).ComTxModeFalse))
    		{
    			Com_TxIPduDMTime[PduId] = COM_CFG_TXPDU(PduId).ComTxIpduDM;
    		}
    		Com_TxIPduIsTransmiting[PduId] =(boolean) FALSE;
    	}
    }
#endif
    return;
}

/**
 * @sid 			0x48
 * @brief			This function is called after the I-PDU has been transmitted on its network, the
 *                  result indicates whether the transmission was successful or not.
 * @param[in]		id: Identification of the transmitted I-PDU.
 * @param[in]       result: Result of the transmission of the I-PDU.
 * @param[out]		/
 * @param[in/out]	/
 * @return			/
 * @retval			/
 * @req [SWS_Com_00725]
 */
FUNC(void, COM_CODE)
Com_TpTxConfirmation(PduIdType id,Std_ReturnType result)
{
#if(COM_NUMBER_OF_TXIPDU > 0)
	Com_IPduSignalProcessingType SignalProcessing;
	PduIdType PduId;
	boolean NeedkNotif = (boolean)FALSE;
#if(STD_ON == COM_DEV_ERROR_DETECT)
	if(COM_INIT != Com_Status)
	{
		COM_DET_ERROR_REPORT(COM_SID_TPTXCONFIRMATION, COM_E_UNINIT);
	}
	else if((id >= (PduIdType)(COM_NUMBER_OF_RXIPDU + COM_NUMBER_OF_TXIPDU)) || \
	(id < (PduIdType)COM_NUMBER_OF_RXIPDU))
	{
		COM_DET_ERROR_REPORT(COM_SID_TPTXCONFIRMATION, COM_E_PARAM);
	}
	else
#endif/* STD_ON == COM_DEV_ERROR_DETECT */
	{
		PduId = id - (PduIdType)COM_NUMBER_OF_RXIPDU;
		if(COM_CHECKTXPDUISENABLE(PduId))
		{
			Com_TxIPduIsTransmiting[PduId] = (boolean)FALSE;
            Com_TxIPduOffset[PduId] = 0u;
            if((Std_ReturnType)E_OK == result)
            {
            	if(Com_TxIPduRepeatNum[PduId] > 0u)
            	{
            		Com_TxIPduRepeatNum[PduId]--;
            		if(0u == Com_TxIPduRepeatNum[PduId])
            		{
            			NeedkNotif = (boolean)TRUE;
            			Com_TxIPduDMTime[PduId] = 0u;
            			Com_TxIPduRepetitionPeriod[PduId] = 0u;
            		}
            	}
            	/*You don't need to send it again*/
            	else
            	{
            		NeedkNotif = (boolean)TRUE;
            		Com_TxIPduDMTime[PduId] = 0u;
            	}
            	if((boolean)TRUE == NeedkNotif)
            	{
            		SignalProcessing = COM_CFG_TXPDU(PduId).ComIPduSignalProcessing;
            		if(COM_IMMEDIATE == SignalProcessing)
            		{
            			Com_Confirmation(PduId);
            			Com_TxIPduTxConfirmation[PduId] = (boolean)FALSE;
            		}
            		else
            		{
            			Com_TxIPduTxConfirmation[PduId] = (boolean)TRUE;
            		}
            	}
            	if(COM_CONFIRMATION == COM_CFG_TXPDU(PduId).ComTxIPduClearUpdateBit)
            	{
            		Com_ClearUpdates(PduId);
            	}
            }
		}
	}
#endif
	return;
}

/**
 * @sid 			0x46
 * @brief			This function is called at the start of receiving an N-SDU. The N-SDU might be
 *                  fragmented into multiple N-PDUs (FF with one or more following CFs) or might consist
 *                  of a single N-PDU (SF).
 * @param[in]		id: Identification of the transmitted I-PDU.
 * @param[in]       info: Pointer to a PduInfoType structure containing the payload data and payload
 * 					length of the first frame or single frame of a transport protocol I-PDU reception.
 *                  Depending on the global parameter MetaDataLength, additional bytes containing
 *                  MetaData (e.g. the CAN ID) are appended after the payload data, increasing the
 *                  length accordingly. If neither first/single frame data nor MetaData are available,
 *                  this parameter is set to NULL_PTR.
 * @param[in]       TpSduLength: Total length of the N-SDU to be received.
 * @param[out]		bufferSizePtr: Available receive buffer in the receiving module. This parameter will
 *                  be used to compute the Block Size (BS) in the transport protocol module.
 * @param[in/out]	/
 * @return			BufReq_ReturnType(BUFREQ_OK,BUFREQ_E_NOT_OK,BUFREQ_E_OVFL)
 * @retval			BUFREQ_OK: Connection has been accepted.
 * 					BUFREQ_E_NOT_OK: Connection has been rejected; reception is aborted. bufferSizePtr
 * 					remains unchanged.
 *                  BUFREQ_E_OVFL: No buffer of the required length can be provided; reception is
 *                  aborted.bufferSizePtr remains unchanged.
 * @req [SWS_Com_00691]
 * @req [SWS_Com_00654]
 * @req [SWS_Com_00655]
 * @req [SWS_Com_00656]
 * @req [SWS_Com_00721]
 */
FUNC(BufReq_ReturnType, COM_CODE)
Com_StartOfReception
(
	PduIdType id,
	P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) info,
	PduLengthType TpSduLength,
	P2VAR(PduLengthType, AUTOMATIC, COM_APPL_DATA) bufferSizePtr
)
{
    BufReq_ReturnType bufReq = BUFREQ_E_NOT_OK;
#if(COM_NUMBER_OF_RXIPDU > 0)
    PduLengthType cnt;
    PduLengthType metadataLength;
#endif
#if(STD_ON == COM_DEV_ERROR_DETECT)
    if(COM_INIT != Com_Status)
    {
        COM_DET_ERROR_REPORT(COM_SID_STARTOFRECEPTION, COM_E_UNINIT);
    }
    else if(id >= (PduIdType)COM_NUMBER_OF_RXIPDU)
    {
        COM_DET_ERROR_REPORT(COM_SID_STARTOFRECEPTION, COM_E_PARAM);
    }
    else if(NULL_PTR == bufferSizePtr)
    {
        COM_DET_ERROR_REPORT(COM_SID_STARTOFRECEPTION, COM_E_PARAM_POINTER);
    }
    else
#endif
    {
#if(COM_NUMBER_OF_RXIPDU > 0)
    	/**
		 * @req [SWS_Com_00713] If an I-PDU is stopped shall disable its reception processing.
		 */
        if(COM_CHECKRXPDUISENABLE(id))
        {
            if(TpSduLength > COM_CFG_RXPDU(id).ComIPduInitLength)
            {
                bufReq = BUFREQ_E_OVFL;
            }
            else
            {
                if((boolean)FALSE == Com_RxIPduIsReceiving[id])
                {
                    metadataLength = (uint16)COM_CFG_RXPDU(id).MetaDataLength;
                    Com_RxIPduLength[id].RxIpduLength = (uint16)TpSduLength;
                    Com_RxIPduIsReceiving[id] = (boolean)TRUE;
                    Com_RxIPduOffset[id] = 0u;
                    *bufferSizePtr = TpSduLength;
                    if(0u < metadataLength)
                    {
                        for(cnt = 0u; cnt < metadataLength; cnt++)
                        {
                            Com_RxIPduRuntimeValue[COM_CFG_RXPDU(id).ComRxIPduBufIndex + \
								  TpSduLength + cnt] = \
										  info->SduDataPtr[(info->SduLength - metadataLength) + cnt];
                        }
                    }
                    bufReq = (BufReq_ReturnType)BUFREQ_OK;
                }
            }
        }
#endif
    }
    return bufReq;

}

/**
 * @sid 			0x44
 * @brief			This function is called to provide the received data of an I-PDU segment (N-PDU) to
 * 					the upper layer.Each call to this function provides the next part of the I-PDU data.
 *                  The size of the remaining data is written to the position indicated by bufferSizePtr
 * @param[in]		id: Identification of the transmitted I-PDU.
 * @param[in]       info: Provides the source buffer (SduDataPtr) and the number of bytes to be copied.
 *                  An SduLength of 0 can be used to query the current amount of available buffer in the
 *                  upper layer module. In this case, the SduDataPtr may be a NULL_PTR.
 * @param[out]		bufferSizePtr: Available receive buffer after data has been copied.
 * @param[in/out]	/
 * @return			BufReq_ReturnType
 * @retval			BUFREQ_OK: Data copied successfully
 *                  BUFREQ_E_NOT_OK: Data was not copied because an error occurred.
 * @req [SWS_Com_00692]
 * @req [SWS_Com_00782]
 */
FUNC(BufReq_ReturnType , COM_CODE)
Com_CopyRxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) info,
    P2VAR(PduLengthType, AUTOMATIC, COM_APPL_DATA) bufferSizePtr
)
{
    BufReq_ReturnType bufReq = BUFREQ_E_NOT_OK;
#if(COM_NUMBER_OF_RXIPDU > 0)
    PduLengthType cnt;
#endif
#if(STD_ON == COM_DEV_ERROR_DETECT)
    if(COM_INIT != Com_Status)
    {
        COM_DET_ERROR_REPORT(COM_SID_COPYRXDATA, COM_E_UNINIT);
    }
    else if(id >= (PduIdType)COM_NUMBER_OF_RXIPDU)
    {
        COM_DET_ERROR_REPORT(COM_SID_COPYRXDATA, COM_E_PARAM);
    }
    else if((NULL_PTR == info) || (NULL_PTR == bufferSizePtr))
    {
        COM_DET_ERROR_REPORT(COM_SID_COPYRXDATA, COM_E_PARAM_POINTER);
    }
    else
#endif/* STD_ON == COM_DEV_ERROR_DETECT */
    {
#if(COM_NUMBER_OF_RXIPDU > 0)
    	/**
		 * @req [SWS_Com_00713] If an I-PDU is stopped shall disable its reception processing.
		 */
        if(COM_CHECKRXPDUISENABLE(id))
        {
            if(((boolean)TRUE == Com_RxIPduIsReceiving[id]) &&
               ((Com_RxIPduOffset[id] + info->SduLength) <= Com_RxIPduLength[id].RxIpduLength))
            {
                /*copy the RX data to RX PDU buffer*/
                for(cnt = 0u; cnt < info->SduLength; cnt++)
                {
                    Com_RxIPduRuntimeValue[COM_CFG_RXPDU(id).ComRxIPduBufIndex + \
										  Com_RxIPduOffset[id] + (uint16)cnt] = info->SduDataPtr[cnt];
                }
                Com_RxIPduOffset[id] += (uint16)info->SduLength;
                *bufferSizePtr = (PduLengthType)Com_RxIPduLength[id].RxIpduLength - \
                		(PduLengthType)Com_RxIPduOffset[id];
                bufReq = (BufReq_ReturnType)BUFREQ_OK;
            }
        }
#endif
    }
    return bufReq;
}

/**
 * @sid 			0x43
 * @brief			This function is called to acquire the transmit data of an I-PDU segment Each call
 * 					to this function provides the next part of the I-PDU data unless retry->TpDataState
 *                  is TP_DATARETRY. In this case the function restarts to copy the data beginning at
 *                  the offset from the current position indicated by retry->TxTpDataCnt. The size of
 *                  the remaining data is written to the position indicated by availableDataPtr.
 * @param[in]       id: Identification of the transmitted I-PDU.
 * @param[in]       retry: This parameter is used to acknowledge transmitted data or to retransmit data
 * 					after transmission problems.
 * @param[out]		availableDataPtr: Indicates the remaining number of bytes that are available in the
 * 					upper layer module's Tx buffer.availableDataPtr can be used by TP modules that
 * 					support dynamic payload lengths (e.g. FrIsoTp) to determine the size of the
 * 					following CFs.
 * @param[in/out]	/
 * @return			BufReq_ReturnType
 * @retval			BUFREQ_OK: Data copied successfully
 * 					BUFREQ_E_BUSY: Request could not be fulfilled, because the required amount of Tx
 * 					data is not available.
 *                  BUFREQ_E_NOT_OK: Data was not copied because an error occurred.
 * @req [SWS_Com_00693]
 * @req [SWS_Com_00783]
 */
/* PRQA S 3673 EOF #violate MISAR2004_16.7:ingore this warnning */
FUNC(BufReq_ReturnType , COM_CODE)
Com_CopyTxData
(
	PduIdType id,
	P2CONST(PduInfoType, AUTOMATIC, DCM_CONST)info,
	P2VAR(RetryInfoType,AUTOMATIC,DCM_VAR)retry,
	P2VAR(PduLengthType,AUTOMATIC,DCM_VAR) availableDataPtr
)
{
    BufReq_ReturnType bufReq = BUFREQ_E_NOT_OK;
#if(COM_NUMBER_OF_TXIPDU > 0)
    PduIdType txIpduId;
    PduLengthType cnt;
#if(STD_ON == COM_DEV_ERROR_DETECT)
    if(COM_INIT != Com_Status)
    {
        COM_DET_ERROR_REPORT(COM_SID_COPYTXDATA, COM_E_UNINIT);
    }
    else if((id >= (PduIdType)(COM_NUMBER_OF_RXIPDU + COM_NUMBER_OF_TXIPDU)) || \
    (id < (PduIdType)COM_NUMBER_OF_RXIPDU))
    {
        COM_DET_ERROR_REPORT(COM_SID_COPYTXDATA, COM_E_PARAM);
    }
    else if((NULL_PTR == info) || (NULL_PTR == availableDataPtr))
    {
        COM_DET_ERROR_REPORT(COM_SID_COPYTXDATA, COM_E_PARAM_POINTER);
    }
    else
#endif/* STD_ON == COM_DEV_ERROR_DETECT */
    {
        txIpduId = id -(PduIdType) COM_NUMBER_OF_RXIPDU;
        if((COM_CHECKTXPDUISENABLE(txIpduId)) \
        		&& ((boolean)TRUE == Com_TxIPduIsTransmiting[txIpduId]))
        {
            if((NULL_PTR != retry) && (TP_DATARETRY == retry->TpDataState))
            {
                if(Com_TxIPduOffset[txIpduId] >= retry->TxTpDataCnt)
                {
                    Com_TxIPduOffset[txIpduId] = \
                    		Com_TxIPduOffset[txIpduId] - (uint16)retry->TxTpDataCnt;
                }
                else
                {
                    Com_TxIPduOffset[txIpduId] = 0u;
                }
            }
            if((Com_TxIPduOffset[txIpduId] + info->SduLength) > COM_CFG_TXPDU(txIpduId).ComIPduInitLength)
            {
                bufReq = (BufReq_ReturnType)BUFREQ_E_NOT_OK;
            }
            else
            {
                for(cnt = 0u; cnt < info->SduLength; cnt++)
                {
                    info->SduDataPtr[cnt] = Com_TxIPduRuntimeValue[COM_CFG_TXPDU(txIpduId).\
						  ComTxIPduBufIndex + Com_TxIPduOffset[txIpduId] + (uint16)cnt];
                }
                Com_TxIPduOffset[txIpduId] += (uint16)info->SduLength;
                *availableDataPtr = (PduLengthType)COM_CFG_TXPDU(txIpduId).ComIPduInitLength - \
                		(PduLengthType)Com_TxIPduOffset[txIpduId];
                bufReq = (BufReq_ReturnType)BUFREQ_OK;
            }
        }
    }
#endif
    return bufReq;
}

#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

