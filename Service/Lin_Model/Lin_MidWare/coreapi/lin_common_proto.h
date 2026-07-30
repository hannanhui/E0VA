/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      lin_common_proto.h                                                       */
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


#ifndef LIN_COMMON_PROTO_H
#define LIN_COMMON_PROTO_H

#include "include.h"

/* *****************************************************************************
 * Definitions
 ******************************************************************************/
#define MAKE_UNCONDITIONAL_FRAME   0U     /*!< Make unconditional frame */
#define UPDATE_UNCONDITIONAL_FRAME 1U     /*!< Update unconditional frame */

/* *****************************************************************************
 * API
 ******************************************************************************/


/*
 * @brief This function packs signals associated with unconditional frame
 *  into buffer.
 *
 * @param[in] iii Interface name
 * @param[in] id ID to process
 * @param[in] type Make or update
 * @return void
 */
void lin_process_uncd_frame(l_ifc_handle iii,
                            uint8_t id,
                            uint8_t type);

/*
 * @brief This function returns the index of a frame in frame list
 * or 0xFF if not found.
 *
 * @param[in] iii Interface name
 * @param[in] id ID to process
 * @return uint8_t
 */
uint8_t lin_get_frame_index(l_ifc_handle iii,
                         uint8_t id);
uint8_t lin_get_Tbl_index(l_ifc_handle iii);

#endif /* LIN_COMMON_PROTO_H */

/* ****************************************************************************/
/* EOF */
/* ****************************************************************************/
