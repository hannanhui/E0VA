/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte.c>
 *  @brief      <>
 *  
 *  <MCU:TC397>
 *  
 *  @author     <>
 *  @date       <2022-08-12 15:11:21>
 */
/*============================================================================*/

/* Rte.c */
/*******************************************************************************
 **                        Revision Control History                           **
******************************************************************************/

/*******************************************************************************
 **                        Version Information                                **
******************************************************************************/

#define RTE_CORE

/*******************************************************************************
 **                        Include Section                                    **
******************************************************************************/
#if 0
#ifdef RTE_PREINCLUDE
#include RTE_PREINCLUDE
#endif
/* Box: RTE: OS Headers begin */
/*
#include "Rte_Const.h"
#include "Os.h"
*/
#if defined(RTE_REQUIRES_IOC)
#include "Ioc.h"
#endif /* defined(RTE_REQUIRES_IOC) */
/* Box: RTE: OS Headers end */
/* Box: RTE headers begin */
#include <Rte.h>
/*#include <Rte_Intl.h>*/
#include <Rte_Main.h>
#include "Rte_Type.h"
/*#include "Rte_Cfg.h"*/
#include "Rte_Cbk.h"
#if defined(RTE_REQUIRES_COM)
#include <Com.h>
#endif /* defined(RTE_REQUIRES_COM) */
#if defined(RTE_REQUIRES_NVM)
#include <NvM.h>
#endif /* defined(RTE_REQUIRES_NVM) */
/*#include "Rte_AR_HeadLampSWC.h"*/
/* Box: RTE headers end */
/* RTE_HEADER_END */

/* Header file reference for IoHwAb */
/*
#include "Rte_Data.h"
#include "Rte_IoHwAb_SignalAnalysis.h"
#include "Rte_IoHwAb.h"
*/

/*******************************************************************************
 **                        Global Variable Definitions                        **
******************************************************************************/

/*******************************************************************************
 **                        Global Function Definitions                        **
******************************************************************************/

/* ----- Function prototypes ----- */

/* EXTERN_FN_PROTOTYPES_START */


/* EXTERN_FN_PROTOTYPES_END */

/* RTE_FN_PROTOTYPES_START */

/* Global functions */
/* Instance: /HeadLamp_FlatView/SwComponentTypes/HeadLamp_FlatView/CPT_AR_HeadLampSWC (CPT_AR_HeadLampSWC), Type: AR_HeadLampSWC */
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h" /*lint !e537 permit multiple inclusion */
FUNC(Std_ReturnType, RTE_CODE) Rte_ImplWrite_CPT_AR_HeadLampSWC_CMDHighBeam_CMDHighBeam(VAR(UInt8, AUTOMATIC) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_ImplWrite_CPT_AR_HeadLampSWC_CMDLowBeam_CMDLowBeam(VAR(UInt8, AUTOMATIC) data);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h" /*lint !e537 permit multiple inclusion */

/* RTE_FN_PROTOTYPES_END */

/* ----- External variables ----- */

/* RTE_IMPORTS_START */

/* RTE_IMPORTS_END */

/* ----- Global variables ----- */

/* RTE_GLOBALS_START */


#define RTE_START_SEC_VAR_CLEARED_8
#include "Rte_MemMap.h" /*lint !e537 permit multiple inclusion */
VAR(Rte_ImplicitBufsType, RTE_DATA) Rte_ImplicitBufs;
VAR(UInt8, RTE_DATA) Rte_Ms_000000;
VAR(UInt8, RTE_DATA) Rte_Ms_000001;
#define RTE_STOP_SEC_VAR_CLEARED_8
#include "Rte_MemMap.h" /*lint !e537 permit multiple inclusion */

#define RTE_START_SEC_VAR_CLEARED_BOOLEAN
#include "Rte_MemMap.h" /*lint !e537 permit multiple inclusion */
VAR(Boolean, RTE_DATA) Rte_Rx_000000 = 0;
VAR(Boolean, RTE_DATA) Rte_Rx_000001 = 0;
VAR(Boolean, RTE_DATA) Rte_Rx_000002 = 0;
#define RTE_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Rte_MemMap.h" /*lint !e537 permit multiple inclusion */

#define RTE_START_SEC_CONST_UNSPECIFIED
#include "Rte_MemMap.h" /*lint !e537 permit multiple inclusion */
#if ( defined(RTE_WOWP_EVENTS) && ( RTE_WOWP_EVENTS > 0 ) )
CONST(Rte_TaskInfo, RTE_CONST) Rte_Tasks[1] = {
   { RTE_REF_FROM_TASK(OsTask_10ms), RTE_NUM_TIMEOUT_ALARMS, 0 }
};
#endif /* ( defined(RTE_WOWP_EVENTS) && ( RTE_WOWP_EVENTS > 0 ) ) */
#define RTE_STOP_SEC_CONST_UNSPECIFIED
#include "Rte_MemMap.h" /*lint !e537 permit multiple inclusion */
/* RTE_GLOBALS_END */


/* ----- Data structures ----- */

/* RTE_CDS_START */

/* Instance: /HeadLamp_FlatView/SwComponentTypes/HeadLamp_FlatView/CPT_AR_HeadLampSWC (CPT_AR_HeadLampSWC), Type: AR_HeadLampSWC */
#define RTE_START_SEC_CONST_UNSPECIFIED
#include "Rte_MemMap.h" /*lint !e537 permit multiple inclusion */
CONST(struct Rte_CDS_AR_HeadLampSWC, RTE_CONST) Rte_Instance_CPT_AR_HeadLampSWC = {
   /* Data handles */
   &Rte_ImplicitBufs.isa_2.Rte_OsTask_10ms.sbuf3,    /* Runnable_Step_CMDHighBeam_CMDHighBeam */
   &Rte_ImplicitBufs.isa_2.Rte_OsTask_10ms.sbuf4,    /* Runnable_Step_CMDLowBeam_CMDLowBeam */
   &Rte_ImplicitBufs.isa_2.Rte_OsTask_10ms.rbuf0,    /* Runnable_Step_HMIHighBeam_HMIHighBeam */
   &Rte_ImplicitBufs.isa_2.Rte_OsTask_10ms.rbuf1,    /* Runnable_Step_HMILowBeam_HMILowBeam */
   &Rte_ImplicitBufs.isa_2.Rte_OsTask_10ms.rbuf2,    /* Runnable_Step_HMIPositionLamp_HMIPositionLamp */
   /* Port Data Structure Arrays */
   {
      {
         0U                                          /* Rte_Dummy */
      }                                              /* CMDHighBeam = CMDHighBeam[0] */
   },                                                /* CMDHighBeam */
   {
      {
         0U                                          /* Rte_Dummy */
      }                                              /* CMDLowBeam = CMDLowBeam[0] */
   },                                                /* CMDLowBeam */
   {
      {
         0U                                          /* Rte_Dummy */
      }                                              /* HMIHighBeam = HMIHighBeam[0] */
   },                                                /* HMIHighBeam */
   {
      {
         0U                                          /* Rte_Dummy */
      }                                              /* HMILowBeam = HMILowBeam[0] */
   },                                                /* HMILowBeam */
   {
      {
         0U                                          /* Rte_Dummy */
      }                                              /* HMIPositionLamp = HMIPositionLamp[0] */
   }                                                 /* HMIPositionLamp */
};
CONST(Rte_SelfType_AR_HeadLampSWC, RTE_CONST) Rte_Self_CPT_AR_HeadLampSWC = &Rte_Instance_CPT_AR_HeadLampSWC;
#define RTE_STOP_SEC_CONST_UNSPECIFIED
#include "Rte_MemMap.h" /*lint !e537 permit multiple inclusion */

/* RTE_CDS_END */

/* ----- Function implementations ----- */

/* RTE_FUNCTIONS_START */

/* Instance: /HeadLamp_FlatView/SwComponentTypes/HeadLamp_FlatView/CPT_AR_HeadLampSWC (CPT_AR_HeadLampSWC), Type: AR_HeadLampSWC */
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h" /*lint !e537 permit multiple inclusion */
/* Direct API 'Rte_IRead_Runnable_Step_HMIHighBeam_HMIHighBeam' for 'CPT_AR_HeadLampSWC' optimized to implicit read. */
/* Function body elided - API implemented as macro. */
/* Function definition Rte_IRead_CPT_AR_HeadLampSWC_Runnable_Step_HMIHighBeam_HMIHighBeam omitted -- not used */

/* Direct API 'Rte_IRead_Runnable_Step_HMILowBeam_HMILowBeam' for 'CPT_AR_HeadLampSWC' optimized to implicit read. */
/* Function body elided - API implemented as macro. */
/* Function definition Rte_IRead_CPT_AR_HeadLampSWC_Runnable_Step_HMILowBeam_HMILowBeam omitted -- not used */

/* Direct API 'Rte_IRead_Runnable_Step_HMIPositionLamp_HMIPositionLamp' for 'CPT_AR_HeadLampSWC' optimized to implicit read. */
/* Function body elided - API implemented as macro. */
/* Function definition Rte_IRead_CPT_AR_HeadLampSWC_Runnable_Step_HMIPositionLamp_HMIPositionLamp omitted -- not used */

/* Direct API 'Rte_IWriteRef_Runnable_Step_CMDHighBeam_CMDHighBeam' for 'CPT_AR_HeadLampSWC' optimized to implicit write. */
/* Function body elided - API implemented as macro. */
/* Function definition Rte_IWriteRef_CPT_AR_HeadLampSWC_Runnable_Step_CMDHighBeam_CMDHighBeam omitted -- not used */

/* Direct API 'Rte_IWriteRef_Runnable_Step_CMDLowBeam_CMDLowBeam' for 'CPT_AR_HeadLampSWC' optimized to implicit write. */
/* Function body elided - API implemented as macro. */
/* Function definition Rte_IWriteRef_CPT_AR_HeadLampSWC_Runnable_Step_CMDLowBeam_CMDLowBeam omitted -- not used */

/* Direct API 'Rte_IWrite_Runnable_Step_CMDHighBeam_CMDHighBeam' for 'CPT_AR_HeadLampSWC' optimized to implicit write. */
/* Function body elided - API implemented as macro. */
/* Function definition Rte_IWrite_CPT_AR_HeadLampSWC_Runnable_Step_CMDHighBeam_CMDHighBeam omitted -- not used */

/* Direct API 'Rte_IWrite_Runnable_Step_CMDLowBeam_CMDLowBeam' for 'CPT_AR_HeadLampSWC' optimized to implicit write. */
/* Function body elided - API implemented as macro. */
/* Function definition Rte_IWrite_CPT_AR_HeadLampSWC_Runnable_Step_CMDLowBeam_CMDLowBeam omitted -- not used */

FUNC(Std_ReturnType, RTE_CODE)
Rte_ImplWrite_CPT_AR_HeadLampSWC_CMDHighBeam_CMDHighBeam(VAR(UInt8, AUTOMATIC) data) /* 1 */
{
   VAR(Std_ReturnType, AUTOMATIC) rtn = RTE_E_OK;

   Rte_Ms_000000 = data;
   /* SpecReq: Send signal begin */
   /* The signal is CmdHighBeam */
   if ( ((VAR(StatusType, AUTOMATIC))E_OK) != Com_SendSignal(((VAR(Com_SignalIdType, AUTOMATIC))0), &data) )
   {
      rtn = ((VAR(Std_ReturnType, AUTOMATIC))RTE_E_COM_STOPPED);
   }
   /* SpecReq: Send signal end */
   /* Send complete */
   return rtn;
}

FUNC(Std_ReturnType, RTE_CODE)
Rte_ImplWrite_CPT_AR_HeadLampSWC_CMDLowBeam_CMDLowBeam(VAR(UInt8, AUTOMATIC) data) /* 1 */
{
   VAR(Std_ReturnType, AUTOMATIC) rtn = RTE_E_OK;
 //  sint8 converted_ComSignal_CmdLowBeam;

   Rte_Ms_000001 = data;
   /* SpecReq: Send signal begin */
   /* The signal is CmdLowBeam */
   /* Incoming type is in the range 0...255, requiring UInt8. */
   /* intermediate value of addition is in the range -8...255, requiring sint16. */
//   converted_ComSignal_CmdLowBeam = ( ((VAR(sint16, AUTOMATIC))-8) + ((VAR(sint16, AUTOMATIC))data) );
//   if ( ((VAR(StatusType, AUTOMATIC))E_OK) != Com_SendSignal(((VAR(Com_SignalIdType, AUTOMATIC))1), &converted_ComSignal_CmdLowBeam) )
   if ( ((VAR(StatusType, AUTOMATIC))E_OK) != Com_SendSignal(((VAR(Com_SignalIdType, AUTOMATIC))1), &data) )
   {
      rtn = ((VAR(Std_ReturnType, AUTOMATIC))RTE_E_COM_STOPPED);
   }
   /* SpecReq: Send signal end */
   /* Send complete */
   return rtn;
}

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h" /*lint !e537 permit multiple inclusion */
/* ----- API functions ----- */

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h" /*lint !e537 permit multiple inclusion */
FUNC(void, RTE_CODE)
Rte_COMCbk_ComSignal_HighBeam(void)
{
   StatusType comstatus;
   Boolean data;
   boolean read_ok = TRUE;

   /* Box: test begin */
#if !defined(RTE_OMIT_UNINIT_CHECK)
   if ( TRUE != Rte_Initialized )
   {
      return;
   }
#endif /* !defined(RTE_OMIT_UNINIT_CHECK) */
   /* Box: test end */
   /* Box: initialize begin */
   /* Box: initialize end */
   /* Box: receive begin */
   /* SpecReq: Receive signal begin */
   comstatus = Com_ReceiveSignal(((VAR(Com_SignalIdType, AUTOMATIC))0), &data);
   if ( ((VAR(StatusType, AUTOMATIC))E_OK) != comstatus )
   {
      read_ok = ((VAR(boolean, AUTOMATIC))FALSE);
   }
   /* SpecReq: Receive signal end */
   /* Box: receive end */
   /* Box: process begin */
   if ( TRUE == read_ok )
   {
      /* SpecReq: Buffer write begin */
      /* Optimizer: Removed resource lock */
      Rte_Rx_000000 = data;
      /* SpecReq: Buffer write end */
   }
   /* Box: process end */
}

FUNC(void, RTE_CODE)
Rte_COMCbk_ComSignal_PositionLamp(void)
{
   StatusType comstatus;
   Boolean data;
   boolean read_ok = TRUE;

   /* Box: test begin */
#if !defined(RTE_OMIT_UNINIT_CHECK)
   if ( TRUE != Rte_Initialized )
   {
      return;
   }
#endif /* !defined(RTE_OMIT_UNINIT_CHECK) */
   /* Box: test end */
   /* Box: initialize begin */
   /* Box: initialize end */
   /* Box: receive begin */
   /* SpecReq: Receive signal begin */
   comstatus = Com_ReceiveSignal(((VAR(Com_SignalIdType, AUTOMATIC))1), &data);
   if ( ((VAR(StatusType, AUTOMATIC))E_OK) != comstatus )
   {
      read_ok = ((VAR(boolean, AUTOMATIC))FALSE);
   }
   /* SpecReq: Receive signal end */
   /* Box: receive end */
   /* Box: process begin */
   if ( TRUE == read_ok )
   {
      /* SpecReq: Buffer write begin */
      /* Optimizer: Removed resource lock */
      Rte_Rx_000001 = data;
      /* SpecReq: Buffer write end */
   }
   /* Box: process end */
}

FUNC(void, RTE_CODE)
Rte_COMCbk_ComSignal_lowBeam(void)
{
   StatusType comstatus;
   Boolean data;
   boolean read_ok = TRUE;

   /* Box: test begin */
#if !defined(RTE_OMIT_UNINIT_CHECK)
   if ( TRUE != Rte_Initialized )
   {
      return;
   }
#endif /* !defined(RTE_OMIT_UNINIT_CHECK) */
   /* Box: test end */
   /* Box: initialize begin */
   /* Box: initialize end */
   /* Box: receive begin */
   /* SpecReq: Receive signal begin */
   comstatus = Com_ReceiveSignal(((VAR(Com_SignalIdType, AUTOMATIC))2), &data);
   if ( ((VAR(StatusType, AUTOMATIC))E_OK) != comstatus )
   {
      read_ok = ((VAR(boolean, AUTOMATIC))FALSE);
   }
   /* SpecReq: Receive signal end */
   /* Box: receive end */
   /* Box: process begin */
   if ( TRUE == read_ok )
   {
      /* SpecReq: Buffer write begin */
      /* Optimizer: Removed resource lock */
      Rte_Rx_000002 = data;
      /* SpecReq: Buffer write end */
   }
   /* Box: process end */
}

/*******************************************************************************************************************/
/*                Application instance function implementation of IoHwAb                                           */
/*******************************************************************************************************************/

void Rte_IoHwAb_AppInstance_Init(void)
{
    Rte_IoHwAb_SignalAnalysis_Swc_Init();
}

void Rte_IoHwAb_AppInstance_MainFunction(void)
{
    Rte_IoHwAb_SignalAnalysis_Swc_Step();
    Rte_Rte_IoHwAb_Mainfunction();
}



#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h" /*lint !e537 permit multiple inclusion */
/* RTE_FUNCTIONS_END */
#endif
