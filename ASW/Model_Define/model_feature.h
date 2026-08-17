/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      model_feature.h                                                          */
/*   Instance     :                                                                               */
/*   Author       :      Ed                                                                       */
/*   Modify date  :      2025-12-22 14:00:05 PM                                                   */
/*   Description  :                                                                               */
/*                                                                                                */
/*                                                                                                */
/*   Compiler    :       KungFu32 IDE  [Version: V1.0.20.3]                                       */
/*   Hardware    :       ChipOn microcontroller KF32A Family [KF32A156MQV]                        */
/*   Version     :       V1.0                                                                     */
/*                                                                                                */
/*                                                                                                */
/*   All rights reserved. Distribution or duplication without previous written agreement of the   */
/*   owner prohibited.                                                                            */
/*                                                                                                */
/**************************************************************************************************/
#ifndef MODEL_FEATURE_H_
#define MODEL_FEATURE_H_





/* ********************************************************************
                 Project definition area
***********************************************************************/
/*Project definition*/

#define PRO_MGP13           1  
#define PRO_SGE03           2

#define MODEL           PRO_MGP13

#if MODEL == PRO_MGP13
































#include "model_MGP13.h"

#else
#error "!!! Model error !!!"
#endif

/* ********************************************************************
                 Default definition area for all definitions
***********************************************************************/








/* *******************************************************************/

#endif  //_MODEL_FEATURE_H_
