/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      lin_common.c                                                             */
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
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
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

/*!
 * @file lin_common.c
 */

/* *****************************************************************************
 * Includes
 ******************************************************************************/
#include "lin_driver.h"
#include "LinIf_Cbk.h"
/* ****************************************************************************
 * Definitions
 ******************************************************************************/

/* *****************************************************************************
 * Code
 ******************************************************************************/
/*FUNCTION**********************************************************************
 *
 * Function Name : BIT
 * Description   : Return bit B in byte A
 * This is not a public API as it is called by other API functions.
 *
 *END**************************************************************************/
static inline uint8_t BIT(uint8_t A,
                          uint8_t B)
{
    return (uint8_t)((A >> B) & 0x01U);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LIN_DRV_ProcessParity
 * Description   : Makes or checks parity bits. If action is checking parity, the function
 * returns ID value if parity bits are correct or 0xFF if parity bits are incorrect. If action
 * is making parity bits, then from input value of ID, the function returns PID.
 * This is not a public API as it is called by other API functions.
 *
 * Implements    : LIN_DRV_ProcessParity_Activity
 *END**************************************************************************/
uint8_t LIN_DRV_ProcessParity(uint8_t PID,
                              uint8_t typeAction)
{
    uint8_t parity;
    uint8_t retVal;

    parity = (uint8_t)(((0xFFU & (BIT(PID, 0U) ^ BIT(PID, 1U) ^ BIT(PID, 2U) ^ BIT(PID, 4U))) << 6U) |
                       ((0xFFU ^ (BIT(PID, 1U) ^ BIT(PID, 3U) ^ BIT(PID, 4U) ^ BIT(PID, 5U))) << 7U));

    /* Check if action is checking parity bits */
    if (CHECK_PARITY == typeAction)
    {
        /* If parity bits are incorrect */
        if ((PID & 0xC0U) != parity)
        {
            /* Return 0xFF if parity bits are incorrect */
            retVal = 0xFFU;
        }
        /* If parity bits are correct */
        else
        {
            /* Return ID if parity bits are correct */
            retVal = (uint8_t)(PID & 0x3FU);
        }
    }
    /* If action is making parity bits */
    else
    {
        /* Return PID in case of making parity bits */
        retVal = (uint8_t)(PID | parity);
    }

    return retVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LIN_DRV_MakeChecksumByte
 * Description   : Makes the checksum byte for a frame. For PID of identifiers,
 * if PID is 0x3C (ID 0x3C) or 0x7D (ID 0x3D) or 0xFE (ID 0x3E) or 0xBF (ID 0x3F)
 * apply classic checksum and apply enhanced checksum for other PID.
 * In case user want to calculate classic checksum please set PID to zero.
 *
 * Implements    : LIN_DRV_MakeChecksumByte_Activity
 *END**************************************************************************/
uint8_t LIN_DRV_MakeChecksumByte(const uint8_t * buffer,
                                 uint8_t sizeBuffer,
                                 uint8_t PID)
{
    uint8_t length;
    uint16_t checksum = 0U;

    /* For PID is 0x3C (ID 0x3C) or 0x7D (ID 0x3D) or 0xFE (ID 0x3E) or 0xBF (ID 0x3F)
     * apply classic checksum and apply enhanced checksum for other PID */
    if ((0x3CU != PID) && (0x7DU != PID) )//&& (0xFEU != PID) && (0xBFU != PID)
    {
        /* For PID other than 0x3C, 0x7D, 0xFE and 0xBF: Add PID in checksum calculation */
        checksum = PID;
    }
    else
    {
        /* For 0x3C, 0x7D, 0xFE and 0xBF: Do not add PID in checksum calculation */
        checksum = 0U;
    }

    for (length = sizeBuffer; 0U < length; length--)
    {
        checksum += *buffer;
        buffer++;
        /* Deal with the carry */
        if (checksum > 0xFFU)
        {
            checksum -= 0xFFU;
        }
    }

    /* Return reversed checksum */
    return (uint8_t)(~checksum);
}

extern uint8 APP_Jump;
volatile uint8 Dcm_Send_1002 = 0;
void LIN_DRV_NotifyLinIf(uint32_t instance,void*linState)
{
	lin_state_t *state =(lin_state_t*)linState;
	NetworkHandleType channel=(NetworkHandleType)instance;
	Lin_PduType LinPdu;
	lin_event_id_t eventId;
	const uint8_t *data;
	uint8_t pid;
	
	if(state == NULL)
	{
		return;
	}
  eventId = state->currentEventId;
	
	if((eventId == LIN_TX_COMPLETED)||(eventId == LIN_TX_TIMEOUT)||(eventId == LIN_TX_BIT_ERR))
	{
		data = state->txBuff;
	}
	else
	{
		data = state->rxBuff;
	}
	

	pid = state->currentPid;
	
    switch (eventId)
    {
        case LIN_PID_OK:
            LinPdu.Pid = pid;
            LinPdu.Cs = LIN_CLASSIC_CS;
            LinPdu.Dl = 8;
            LinPdu.SduPtr = (uint8_t *)data;
            if(APP_Jump == 0x01)
            {
            Dcm_Send_1002 = 1;
            }
										 
            if(E_OK == LinIf_HeaderIndication(0,&LinPdu))
            {
                if(LIN_FRAMERESPONSE_TX == LinPdu.Drc)
                {

									  LIN_DRV_SetTimeoutCounter(0,1000U);
                    LIN_DRV_SendFrameData(instance,LinPdu.SduPtr,LinPdu.Dl);
                }
                else if(LIN_FRAMERESPONSE_RX == LinPdu.Drc)
                {
									  LIN_DRV_SetTimeoutCounter(0,1000U);
                    LIN_DRV_ReceiveFrameData(instance,LinPdu.SduPtr,LinPdu.Dl);
                }
            }
            if(LIN_NODE_STATE_RECV_PID == state->currentNodeState)
            {
                //LIN_DRV_AbortTransferData(0);
            }
            break;
        case LIN_TX_COMPLETED:
            LinIf_TxConfirmation(0);
            break;
        case LIN_RX_COMPLETED:
            (void)LinIf_RxIndication(0,(uint8_t*)data);
            break;
        case LIN_SYNC_ERROR:
					LinIf_LinErrorIndication(0,LIN_ERR_HEADER);
        case LIN_FRAME_ERROR:
					LinIf_LinErrorIndication(0,LIN_ERR_RESP_STOPBIT);
             break;
        case LIN_CHECKSUM_ERROR:
					LinIf_LinErrorIndication(0,LIN_ERR_RESP_CHKSUM);
             break;
        case LIN_TX_BIT_ERR:
          	LinIf_LinErrorIndication(0,LIN_ERR_RESP_DATABIT);
             break;
        case LIN_TX_TIMEOUT:
				case LIN_RX_TIMEOUT:
         LinIf_LinErrorIndication(0,LIN_ERR_NO_RESP);
            break;
        default:
            /*nothing to do*/
            break;
    }
}

/* *****************************************************************************
 * EOF
 ******************************************************************************/
