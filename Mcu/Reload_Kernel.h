/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Reload_Kernel.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2025-02-10
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
 *  |2025-02-10  |V1.0     |Yao Dongxin  |New create
 *****************************************************************************/

#ifndef RELOAD_KERNEL_H
#define RELOAD_KERNEL_H

/**
 * @brief Reload flash calibration value
 *
 * @return uint32_t
 *  0 -- success
 *  1 -- read flash trim value error
 *  2 -- unlock flash error
 */
/* PRQA S 0616 ++ #KQR000616 */
/* PRQA S 1753 2 #IN ASM FILE */
/* PRQA S 2071 1 #KQR002071 */
uint32_t __attribute__((section(".indata"))) __Reload_Kernel_Trim(void);

#endif
