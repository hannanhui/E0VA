/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      CAN_Trcv.c                                                               */
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
#include "Type_Define.h"
#include "CAN_Trcv.h"
#include "ECAL_PORT.h"

/*================================================================================================
 * 函数名称：CAN_WorkModeControl
 * 输入参数：ModeType，CAN 收发器目标工作模式
 * 输出参数：无
 * 功能说明：控制 CAN 收发器的 STB_N 和 EN 引脚，切换工作模式
 * 作者    ：Devin
 * 日期    ：2023.04.27
 * 模式说明：
 *                   STB = H and EN = H --> NORMAL MODE;                                         *
 *                   STB = H and EN = L --> PWON/LISTENONLY MODE;                                *
 *                   STB = L and (EN = L or flag set) --> STANDBY MODE;                          *
 *                   STB = L and EN = H and flags cleared --> GO-TO-SLEEP COMMAND MODE;          *
 *                   Wake flag cleared and t > th(min)--> SLEEP MODE                             *
 *                                                                                               *
 *                   [1] Setting the UVNOM flag will clear the WAKE flag.                        *
 *                   [2] Setting the Wake flag will clear the UVNOM flag.                        *
 *                   [3] A LOW-to-HIGH transition on pin STB_N will clear the UVNOM flag         *
 *                   SO:Wake flag cleared = A LOW-to-HIGH transition on pin STB_N                *
 *                      Wake flag set = 唤醒标志置位                                              *
 ================================================================================================*/
void CAN_WorkModeControl(CanPhyMode_t ModeType)
{
    static CanPhyMode_t CurrentMode = CanPhyMod_Nor;
    uint32_t i;
    
    switch(ModeType)
    {
        case CanPhyMod_Nor: //正常模式
            SET_CAN_TRANSCEIVER0_STB;
            SET_CAN_TRANSCEIVER0_WORK_EN;
            CurrentMode = CanPhyMod_Nor;
            break;
        
        case CanPhyMod_LiO: //只监听模式
            SET_CAN_TRANSCEIVER0_STB;
            CLR_CAN_TRANSCEIVER0_WORK_EN;
            CurrentMode = CanPhyMod_LiO;
            break;
        
        case CanPhyMod_Stb: //待机模式
            if(CurrentMode == CanPhyMod_Stb)
            {
                //STB_N = L and EN = L
               CLR_CAN_TRANSCEIVER0_STB;
               CLR_CAN_TRANSCEIVER0_WORK_EN;
            }
            else if(CurrentMode == CanPhyMod_LiO)
            {
                //STB_N = L and (EN = L or Wake flag set)
                CLR_CAN_TRANSCEIVER0_STB;
                CLR_CAN_TRANSCEIVER0_WORK_EN;
                //======== Wake flag set ========//
            }
            else if(CurrentMode == CanPhyMod_GoTSp)
            {
                //STB_N = L and (EN = L or Wake flag set)
                CLR_CAN_TRANSCEIVER0_STB;
                CLR_CAN_TRANSCEIVER0_WORK_EN;
                //======== Wake flag set ========//
            }
            else if(CurrentMode == CanPhyMod_Sp)
            {
                //STB_N = L and Wake flag set
                CLR_CAN_TRANSCEIVER0_STB;
                //======== Wake flag set ========//
            }
            CurrentMode = CanPhyMod_Stb;
            break;
        
        case CanPhyMod_GoTSp: //进入休眠命令模式
            if(CurrentMode == CanPhyMod_Nor)
            {
                //STB_N = L and EN = H
                CLR_CAN_TRANSCEIVER0_STB;
                SET_CAN_TRANSCEIVER0_WORK_EN;
            }
            else if(CurrentMode == CanPhyMod_LiO)
            {
                //STB_N = L and EN = H and Wake flag cleared
                CLR_CAN_TRANSCEIVER0_STB;
                SET_CAN_TRANSCEIVER0_WORK_EN;
                //======== Wake flag cleared ========//
                //DIO_CLR_CAN0STB;
                //mdelay(500);
                //DIO_CLR_CAN0STB;
                //mdelay(1000);
            }
            else if(CurrentMode == CanPhyMod_Stb)
            {
                //STB_N = L and EN = H and Wake flag cleared
                CLR_CAN_TRANSCEIVER0_STB;
                SET_CAN_TRANSCEIVER0_WORK_EN;
                //======== Wake flag cleared ========//
                //DIO_CLR_CAN0STB;
                //mdelay(500);
                //DIO_SET_CAN0STB;
                //mdelay(1000);
            }
            CurrentMode = CanPhyMod_GoTSp;
            break;
        
        case CanPhyMod_Sp: //休眠模式
            //Only In "GO-TO-SLEEP MODE" --> Wake flag cleared and t > th(min) Can Go To "SLEEP MODE"
            //if(CurrentMode == CanPhyMod_GoTSp)
            {
                //======== Wake flag cleared ========//
                //DIO_CLR_CAN0STB;
                //mdelay(1000);
                //DIO_SET_CAN0STB;
                //mdelay(1000);
                //======== t > th(min) ========//

                //DIO_CLR_CAN0STB;
                //udelay(10000);
                //DIO_SET_CAN0STB;
                for(i=0;i<0xFFFFF;i++){;}
            }
            CurrentMode = CanPhyMod_Sp;
            break;
        
        default:
            break;
    }
}


void CANTrcv_Init(void)
{
	CAN_WorkModeControl(CanPhyMod_Nor);
}

