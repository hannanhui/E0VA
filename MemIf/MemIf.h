/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : MemIf.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2025-08-29
 *  @Version         : V1.0.0_SF
 *  @Description     : This document describes the C language document template.
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 ******************************************************************************
 *                        REVISION HISTORY
 ******************************************************************************
 *  |Date        |Version  |Author       |Description
 ******************************************************************************
 *  |2025-08-29  |V1.0     |Wang Ning    |New creat
 *****************************************************************************/

/******************************************************************************
 *                      Include Files                                          *
 ******************************************************************************/
#ifndef MEMIF_H
#define MEMIF_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                       Files Version Checks                                 *
 ******************************************************************************/
/*
    Internal micro-dependent versioning. Check of AUTOSAR & Vendor specification
   version.
*/
/**
 * @{
 * @file           Can.h
 */
/* PRQA S 1534 ++ #KQR001534 */
#define MEMIF_SW_MAJOR_VERSION 1
#define MEMIF_SW_MINOR_VERSION 0
#define MEMIF_SW_PATCH_VERSION 0
/* AUTOSAR module identification */

/******************************************************************************
 *                      Macro                                                  *
 ******************************************************************************/
/* Service ids */
#define MEMIF_SETMODE_ID             0x01u
#define MEMIF_READ_ID                0x02u
#define MEMIF_WRITE_ID               0x03u
#define MEMIF_CANCEL_ID              0x04u
#define MEMIF_GETSTATUS_ID           0x05u
#define MEMIF_GETJOBRESULT_ID        0x06u
#define MEMIF_INVALIDATEBLOCK_ID     0x07u
#define MEMIF_GETVERSIONINFO_ID      0x08u
#define MEMIF_ERASEIMMEDIATEBLOCK_ID 0x09u

/*PRQA S 3332 ++ #KQR003332 */
/* @req MemIf057 */
#if (MEMIF_VERSION_INFO_API == STD_ON)
/* @req MemIf045 */
/* !req MemIf063 */
#define MemIf_GetVersionInfo(_vi) STD_GET_VERSION_INFO(_vi, MEMIF)
#endif /* MEMIF_VERSION_INFO_API */

#define MemIf_SetMode(_mode) Fee_SetMode(_mode)
#define MemIf_Read(_deviceIndex, _blockNumber, _blockOffset, _dataBufferPtr, _length)                                  \
    Fee_Read(_blockNumber, _blockOffset, _dataBufferPtr, _length)
#define MemIf_Write(_deviceIndex, _blockNumber, _dataBufferPtr) Fee_Write(_blockNumber, _dataBufferPtr)
#define MemIf_Cancel(_deviceIndex)                              Fee_Cancel()
#define MemIf_GetStatus(_deviceIndex)                           Fee_GetStatus()
#define MemIf_GetJobResult(_deviceIndex)                        Fee_GetJobResult()
#define MemIf_InvalidateBlock(_deviceIndex, _blockNumber)       Fee_InvalidateBlock(_blockNumber)
#define MemIf_EraseImmediateBlock(_deviceIndex, _blockNumber)   Fee_EraseImmediateBlock(_blockNumber)

#ifdef __cplusplus
}
#endif

#endif
