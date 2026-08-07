/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      lin_commontl_api.h                                                       */
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
#ifndef LIN_COMMONTL_API_H
#define LIN_COMMONTL_API_H

/*!
 * @addtogroup commontl_api_group
 * @{
 */

#include "Apply_lin.h"
#include "lin_common_api.h"


extern void ld_init(l_ifc_handle iii);
extern commontl_callback_t ld_InstallCallback(Lin_commontl_proto_callback_type_t opIndex,commontl_callback_t function);
extern commontl_callback_Param_t ld_ApplyIdInstallCallback(Lin_commontl_proto_callback_type_t opIndex,commontl_callback_Param_t function);

#endif /* LIN_COMMONTL_API_H */
/*! @} */

/*! @} */

/* ****************************************************************************/
/* EOF */
/* ****************************************************************************/
