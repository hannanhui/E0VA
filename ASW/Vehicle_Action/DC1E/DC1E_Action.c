/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      DC1E_Action.c                                                            */
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

#include "include.h"

#define ECU_INST_POS_DEF  ECU_INST_POS_FL


/*PartNum1 
O9 FL: 6608371815; O9 FR: 6608371816*/


uint8_t Boot_Major_Version[VERSION_INFO_MAX_SIZE];	// Boot?锟铰★拷?锟斤拷?D??锟斤拷
uint8_t App_Major_Version[VERSION_INFO_MAX_SIZE];	// App?锟铰★拷?锟斤拷?D??锟斤拷

uint8_t Boot_Minor_Version[VERSION_INFO_MAX_SIZE];	// Boot锟教★拷2??a锟斤拷?锟斤拷?D??锟斤拷
uint8_t App_Minor_Version[VERSION_INFO_MAX_SIZE];	// App锟教★拷2??aD??锟斤拷

lin_protocol_ResponeErr_Type* LinBusErrStatus;
static uint16_t LinAppRxTimer = T10_5000MS;
static uint8_t LinAppRxTimeOutFlag = FALSE;


static void LinApp_Tx_Data_assignment(uint8_t OpNodeid)
{


}

static void LinApp_Tx_Complete(uint8_t OpNodeid)
{

}

static void LinApp_Rx_Complete(uint8_t OpNodeid)
{

}

static void LinTimeOutDeal(void)
{
	if (LinAppRxTimer)
	{
		LinAppRxTimer--;
	}
	else
	{
		LinAppRxTimeOutFlag = TRUE;
	}
}

uint8_t MVP17_BusGetLinTimeOutFlag(void)
{
	return LinAppRxTimeOutFlag;
}

void LinApp_Callback_Init(void)
{
	l_ifc_tl_InstallCallback_App_Tx_Data_assignment_LI0(LinApp_Tx_Data_assignment);
	l_ifc_tl_InstallCallback_App_Tx_Complete_LI0(LinApp_Tx_Complete);
	l_ifc_tl_InstallCallback_App_Rx_Complete_LI0(LinApp_Rx_Complete);
}

void DC1E_Action_Bus_ID_RecvSendEnJduge(void)
{

	l_lld_Id_Stbl_use_index_Set_LI0(LI0_Schedule_Index0, TRUE);
	l_lld_Id_Respone_Set_LI0(LI0_Schedule_Index0, LI0_TBL0_MVP17_Ctrl, TRUE);
	l_lld_Id_Respone_Set_LI0(LI0_Schedule_Index0, LI0_TBL0_MVP17_Pressure_0_3, TRUE);
	l_lld_Id_Respone_Set_LI0(LI0_Schedule_Index0, LI0_TBL0_MVP17_Pressure_4_7, TRUE);
	l_lld_Id_Respone_Set_LI0(LI0_Schedule_Index0, LI0_TBL0_MVP17_Pressure_8_10, TRUE);
	l_lld_Id_Respone_Set_LI0(LI0_Schedule_Index0, LI0_TBL0_Sensor_Temperature_0_7, TRUE);
	l_lld_Id_Respone_Set_LI0(LI0_Schedule_Index0, LI0_TBL0_Senor_Temperature_other, TRUE);
	l_lld_Id_Respone_Set_LI0(LI0_Schedule_Index0, LI0_TBL0_Memory_Pressure, TRUE);
	l_lld_Id_Respone_Set_LI0(LI0_Schedule_Index0, LI0_TBL0_MVP17_State, TRUE);
	l_lld_Id_Respone_Set_LI0(LI0_Schedule_Index0, LI0_TBL0_MVP17_RUN, TRUE);
	#if (UPGRADE_MODE == UPGRADE_MODE_FOR_UDS_LIN)
	l_lld_Id_Respone_Set_LI0(LI0_Schedule_Index0,LI0_TBL0_DiagMasterReq,TRUE);
	l_lld_Id_Respone_Set_LI0(LI0_Schedule_Index0,LI0_TBL0_DiagSlaveResp,TRUE);
	l_lld_Id_Respone_Set_LI0(LI0_Schedule_Index0,LI0_TBL0_PrietaryMasterReq,FALSE);
	l_lld_Id_Respone_Set_LI0(LI0_Schedule_Index0,LI0_TBL0_PrietarySlaveResp,FALSE);
	g_lin_Diag_Tx_data_Len =0u;
	LINTP_DEVICE_NAD_Set(ASM_POS_FL_NAD);
	#else
	l_lld_Id_Respone_Set_LI0(LI0_Schedule_Index0,LI0_TBL0_DiagMasterReq,FALSE);
	l_lld_Id_Respone_Set_LI0(LI0_Schedule_Index0,LI0_TBL0_DiagSlaveResp,FALSE);
	l_lld_Id_Respone_Set_LI0(LI0_Schedule_Index0,LI0_TBL0_PrietaryMasterReq,TRUE);
	l_lld_Id_Respone_Set_LI0(LI0_Schedule_Index0,LI0_TBL0_PrietarySlaveResp,TRUE);
	g_lin_Diag_Tx_data_Len =0u;
	#endif


}

void DC1E_Action_Init(void)
{
	DC1E_Action_Bus_ID_RecvSendEnJduge();
}

void DC1E_Lintl_UseFuncListCallbackInstall(void)
{
	LinApp_Callback_Init();
	UDS_Tp_Init();
	ProprietaryLin_Tp_Init();
	#if UPGRADE_MODE == UPGRADE_MODE_FOR_PROPRIETARY_LIN
	ProprietaryLin_App_Init();
	#endif
	LinBusErrStatus =l_lld_Id_lin_ResponeErr_Status_Get_LI0();
}

void DC1E_Action_ID_21_Deal(void)
{

}

void DC1E_Action_ID_22_Deal(void)
{

}

void DC1E_Action_ID_23_Deal(void)
{
	
}

void DC1E_Action_ID_24_Deal(void)
{

}

void DC1E_Action_ID_25_Deal(void)
{

}

void DC1E_Action_ID_12_Deal(void)
{

}

/* ======================== LinIf → LinApp 桥接函数 ======================== */

/**
 * @brief  RX 桥接：LinIf 收到应用帧数据后调用此函数，
 *         将数据拷贝到应用缓冲区，然后回调 LinApp_Rx_Complete
 */
void LinApp_Rx_Bridge(PduIdType RxPduId, const PduInfoType* PduInfoPtr)
{
    uint8_t pid;
    uint8_t i;

    /* 根据 PduId 映射到 PID */
    if (RxPduId == PduRConf_PduRSrcPdu_LinPdu_LinIfToPduR_ZCU_SMM_1_Rx)
    {
        pid = 0x4CU;  /* ZCU_SMM_1 PID */
    }
    else if (RxPduId == PduRConf_PduRSrcPdu_LinPdu_LinIfToPduR_ZCU_SMM_2_Rx)
    {
        pid = 0x8EU;  /* ZCU_SMM_2 PID */
    }
    else
    {
        return;  /* 非应用帧，不处理 */
    }

    /* 保存接收数据到应用缓冲区 */
    for (i = 0; i < 8; i++)
    {
	    //这个地方根据报文在数据中的位置g_lin_Proprietary_Rx_data_buffer[i+实际偏移]
        g_lin_Proprietary_Rx_data_buffer[i] = PduInfoPtr->SduDataPtr[i];
    }

    /* 通知应用层 */
    LinApp_Rx_Complete(pid);
}

/**
 * @brief  TX TriggerTransmit 桥接：LinIf 需要发送数据时调用此函数，
 *         先回调 LinApp_Tx_Data_assignment 让应用准备数据，
 *         然后将应用缓冲区数据提供给 LinIf
 */
Std_ReturnType LinApp_TxTrigger_Bridge(PduIdType TxPduId, PduInfoType* PduInfoPtr)
{
    uint8_t pid;
    uint8_t i;

    /* 根据 PduId 映射到 PID */
    if (TxPduId == PduRConf_PduRDestPdu_LinPdu_PduRToLinIf_DSMM_1_Tx)
    {
        pid = 0xCAU;  /* DSMM_1 PID */
    }
    else
    {
        return E_NOT_OK;
    }

    /* 通知应用层准备发送数据 */
    LinApp_Tx_Data_assignment(pid);

    /* 将应用缓冲区数据拷贝到 LinIf 的发送缓冲区 */
    for (i = 0; i < PduInfoPtr->SduLength; i++)
    {
	    //这个地方根据报文在数据中的位置g_lin_Proprietary_Tx_data_buffer[i+实际偏移]
        PduInfoPtr->SduDataPtr[i] = g_lin_Proprietary_Tx_data_buffer[i];
    }

    return E_OK;
}

/**
 * @brief  TX Confirmation 桥接：LinIf 发送完成时调用此函数，
 *         回调 LinApp_Tx_Complete 通知应用层
 */
void LinApp_TxConfirm_Bridge(PduIdType TxPduId)
{
    uint8_t pid;

    if (TxPduId == PduRConf_PduRDestPdu_LinPdu_PduRToLinIf_DSMM_1_Tx)
    {
        pid = 0xCAU;  /* DSMM_1 PID */
    }
    else
    {
        return;
    }

    LinApp_Tx_Complete(pid);
}

/*******************************************************************************
* Function name: MX11_Action_Periodic_Prcoess_10mS
* Function function: MX11 cycle processing
* Function parameter: none
* Function return: none
* Note: None

*******************************************************************************/
void DC1E_Action_Periodic_Prcoess_10mS(void)
{
	LinTimeOutDeal();

}

/*******************************************************************************
* Function name: MX11_Action_Periodic_10mS
* Function Function: MX11 bus data cycle processing function
* Function parameter: none
* Function return: none
* Note: None

*******************************************************************************/
void DC1E_Action_Periodic_10mS(void)
{
	DC1E_Action_Periodic_Prcoess_10mS();
	DC1E_Action_Bus_ID_RecvSendEnJduge();
}


