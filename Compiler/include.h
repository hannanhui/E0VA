/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      include.h                                                                */
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

#ifndef INCLUDE_H__
#define INCLUDE_H__



#include "stdio.h"

#include <string.h>
#include "Common.h"
#include "Type_Define.h"
#include "Rte_Type.h"





#include "model_Cfg_feature.h"
#include "model_feature.h"




#if ((CAR_PUB_NET_COM_MEOD == NET_COM_CAN)||(CAR_PUB_NET_COM_MEOD == NET_COM_LIN_CAN))

#include "Can.h"

#include "PduR.h"
#include "ComM.h"
#include "Com.h"

#include "BSW.h"

//#include "TJA1043.h"

#include "Dcm.h"
#include "BswM.h"
#include "Fls.h"
//#include "RTE_Dcm.h"
#include "SchM_Can.h"
#if defined(ASENSING_GEELY_FX11_CUSTOM)
  #include "NmHistoryState.h"
#endif /* defined(ASENSING_GEELY_FX11_CUSTOM) */

//#include "ComM_EcuMBswM.h"
#endif

#if (CAR_PUB_NET_COM_MEOD == NET_COM_LIN)
#include "BSW.h"
#endif


#include "Rte_Com.h"




#include "Service.h"

#include "APP.h"

#include "global_var.h"




#endif /* __INCLUDE_H__ */
