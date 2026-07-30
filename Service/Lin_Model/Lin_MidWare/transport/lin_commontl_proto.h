/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      lin_commontl_proto.h                                                     */
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
/*
 * Copyright (c) 2015-2016, Freescale Semiconductor, Inc.
 * Copyright 2016 NXP
 * All rights reserved.
 *
 * THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef LIN_COMMONTL_PROTO_H
#define LIN_COMMONTL_PROTO_H

#include "include.h"


typedef void (* commontl_callback_t)(void);
typedef void (* commontl_callback_Param_t)(uint8_t);


typedef enum {
    Commontl_proto_Callback_Diag_Tx_Data_assignment             = 0x00U,
	Commontl_proto_Callback_Diag_Tx_Complete, 
    Commontl_proto_Callback_Diag_Rx_Complete, 
    Commontl_proto_Callback_Proprietary_Tx_Data_assignment,
	Commontl_proto_Callback_Proprietary_Tx_Complete, 
    Commontl_proto_Callback_Proprietary_Rx_Complete,
    Commontl_proto_Callback_App_Tx_Data_assignment,
	Commontl_proto_Callback_App_Tx_Complete, 
    Commontl_proto_Callback_App_Rx_Complete,
    
} Lin_commontl_proto_callback_type_t;


typedef struct {

    commontl_callback_t Diag_Tx_Data_assignmentCallback;                   
	commontl_callback_t Diag_Tx_CompleteCallback; 
	commontl_callback_t Diag_Rx_CompleteCallback; 
	commontl_callback_t Proprietary_Tx_Data_assignmentCallback;                   
	commontl_callback_t Proprietary_Tx_CompleteCallback; 
	commontl_callback_t Proprietary_Rx_CompleteCallback; 
	commontl_callback_Param_t App_Tx_Data_assignmentCallback;                   
	commontl_callback_Param_t App_Tx_CompleteCallback; 
	commontl_callback_Param_t App_Rx_CompleteCallback; 

} S_commontl_callback_t;

extern commontl_callback_t lin_tl_InstallCallback(Lin_commontl_proto_callback_type_t opIndex,commontl_callback_t function);
commontl_callback_Param_t lin_tl_ApplyIdInstallCallback(Lin_commontl_proto_callback_type_t opIndex,commontl_callback_Param_t function);

extern void lin_tl_init(l_ifc_handle iii);

#endif
/* ****************************************************************************/
/* EOF */
/* ****************************************************************************/
