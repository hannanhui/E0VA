/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      Uds_Tp.c                                                                 */
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



#define FILL_VALUE  (0xFF)    /*Default Fill value*/

#define DATA_LEN (8u)         /*LIN sends the total length of a frame*/
#define SF_DATA_MAX_LEN (6u)  /*max signle frame data len*/
#define FF_DATA_MIN_LEN (5u)  /*min fiirst frame data len*/
#define CF_DATA_MAX_LEN (6u)  /*连续帧一帧包含有的数据长度*/

extern uint8_t PowerApp_DiagSleepNoResponseEnGet(void);

BOOL RxMsgFlag = FALSE;//表示信息是否完整接收到一条消息
BOOL TxMsgFlag = FALSE;//表示信息是否准备好完整的发送消息

uint8_t gs_Lin_Tp_Nad = LIN_DEF_NAD;
volatile tLinTpInfo gs_stLinTPTxRxDataInfo; /*Data transmission layer data storage with cache, sending and receiving time-sharing multiplexing*/
volatile tLinTpWorkStatus gs_eLinTpWorkStatus = IDLE;/*检测当前lin_tp层的工作状态*/
/*uds netwrok layer cfg info */
const tUdsLINNetLayerCfg g_stLINUdsNetLayerCfgInfo = 
{
	1u,       /*called lin tp period*/
	LIN_DIAG_MASTER_REQUEST_ID,   
	LIN_DIAG_SLAVER_RESPOND_ID,   
	LIN_DEF_NAD,  
	0u,       /*BS = block size*/
	0u,      /*STmin*/
	25u,      /*N_As*/
	25u,      /*N_Ar*/
	75u,     /*N_Bs*/
	0u,       /*N_Br*/
	100u,       /*N_Cs < 0.9 N_Cr*/
	150u,     /*N_Cr*/
	0u,       /*max blocking time 0ms, > 0u mean waitting send successful. equal 0 is not waitting.*/
	LINTP_TxMsg, /*lin tp tx*/
	LINTP_RxMsg, /*lin tp rx*/
};

/*set cur LIN TP status*/
#define SetCurLINTPSatus(status) \
do{\
	gs_eLinTpWorkStatus = status;\
}while(0u)

void LINTP_DEVICE_NAD_Set(uint8_t opNad)
{
	gs_Lin_Tp_Nad = opNad;
}
uint8_t LINTP_DEVICE_NAD_Get(void)
{
	return gs_Lin_Tp_Nad;
}
/*lin tp tx message: there not use LIN driver TxFIFO, directly invoked LIN send function*/
uint8_t LINTP_TxMsg(const tUdsId i_xTxId,
							  const uint16_t i_DataLen, 
							  const uint8_t* i_pDataBuf, 
							  const uint32_t txBlockingMaxtime)
{    
	uint8_t Calquotient,remainder =0;
	uint8_t i,j=0u;
    if(i_DataLen<=(SF_DATA_MAX_LEN))//单帧发送
    {
         gs_stLinTPTxRxDataInfo.stLinTpDataInfo.xLinTpId = i_xTxId;
         gs_stLinTPTxRxDataInfo.stLinTpDataInfo.xPduDataLen = i_DataLen;
		 gs_stLinTPTxRxDataInfo.stLinTpDataInfo.xFFDataIndex =0;
         for(int i=0;i<i_DataLen;i++)
         {
             gs_stLinTPTxRxDataInfo.stLinTpDataInfo.aDataBuf[i] = i_pDataBuf[i];
         }
          
    }
    else
    {
    	gs_stLinTPTxRxDataInfo.stLinTpDataInfo.xLinTpId = i_xTxId;
        gs_stLinTPTxRxDataInfo.stLinTpDataInfo.xPduDataLen = i_DataLen;
		gs_stLinTPTxRxDataInfo.stLinTpDataInfo.xFFDataIndex =0;
		gs_stLinTPTxRxDataInfo.stLinTpDataInfo.aDataBuf[0] = LINTP_DEVICE_NAD_Get();
		gs_stLinTPTxRxDataInfo.stLinTpDataInfo.aDataBuf[1] = ((FF<<4)|((i_DataLen&0xF00)>>8));
		gs_stLinTPTxRxDataInfo.stLinTpDataInfo.aDataBuf[2] = (i_DataLen&0xFF);
		gs_stLinTPTxRxDataInfo.stLinTpDataInfo.xPduDataLen +=3;
		for( i=0;i<FF_DATA_MIN_LEN;i++)
     	{
         	gs_stLinTPTxRxDataInfo.stLinTpDataInfo.aDataBuf[i+3] = i_pDataBuf[i];
     	}
		Calquotient =((i_DataLen-FF_DATA_MIN_LEN)/6); 
		for( i=0;i<Calquotient;i++)
     	{
         	gs_stLinTPTxRxDataInfo.stLinTpDataInfo.aDataBuf[(8+(i*8))] = LINTP_DEVICE_NAD_Get();

			gs_stLinTPTxRxDataInfo.stLinTpDataInfo.aDataBuf[(9+(i*8))] =((CF<<4)|(((i+1)&0x0F)));

			
			for( j=0;j<6;j++)
			{
				gs_stLinTPTxRxDataInfo.stLinTpDataInfo.aDataBuf[(10+(i*8)+j)] = i_pDataBuf[(FF_DATA_MIN_LEN+i*6+j)];
			}
     	}
		gs_stLinTPTxRxDataInfo.stLinTpDataInfo.xPduDataLen +=(Calquotient*2);
		remainder = ((i_DataLen-FF_DATA_MIN_LEN)%6); 
		if(remainder>0)
		{
			gs_stLinTPTxRxDataInfo.stLinTpDataInfo.aDataBuf[(8+(Calquotient*8))] = LINTP_DEVICE_NAD_Get();
			gs_stLinTPTxRxDataInfo.stLinTpDataInfo.aDataBuf[(9+(Calquotient*8))] =((CF<<4)|(((Calquotient+1)&0x0F)));
			for( j=0;j<remainder;j++)
			{
				gs_stLinTPTxRxDataInfo.stLinTpDataInfo.aDataBuf[(10+(Calquotient*8)+j)] = i_pDataBuf[(FF_DATA_MIN_LEN+Calquotient*6+j)];
			}
			gs_stLinTPTxRxDataInfo.stLinTpDataInfo.xPduDataLen +=2;
		}
    }
	SetTxMsgReadlly();
    return TRUE;
}

/*lin tp rx message: read rx msg from LIN driver RxFIFO*/
uint8_t LINTP_RxMsg(tUdsId * o_pxRxId,
					  	 tUdsLen * o_pRxDataLen,
						 uint8_t *o_pRxBuf)
{
    *o_pxRxId = gs_stLinTPTxRxDataInfo.stLinTpDataInfo.xLinTpId;
    *o_pRxDataLen = gs_stLinTPTxRxDataInfo.stLinTpDataInfo.xPduDataLen;
    for(int i = 0;i<gs_stLinTPTxRxDataInfo.stLinTpDataInfo.xPduDataLen;i++)
    {
        o_pRxBuf[i] = gs_stLinTPTxRxDataInfo.stLinTpDataInfo.aDataBuf[i];
    }
	
    return TRUE;
}
//检查接收消息是否就绪
BOOL IsRxMsgReally(void)
{
    return RxMsgFlag;
}
void ClearRxMsgReadlly(void)
{
    RxMsgFlag = FALSE;
}
void SetRxMsgReadlly(void)
{
    RxMsgFlag = TRUE;
}
//检查发送消息是否就绪
BOOL IsTxMsgReally(void)
{
    return TxMsgFlag;
}
void ClearTxMsgReadlly(void)
{
    TxMsgFlag = FALSE;
}
void SetTxMsgReadlly(void)
{
    TxMsgFlag = TRUE;
}

/*write data in LIN TP*/
BOOL LINTP_DriverWriteDataInLINTP(const uint32_t i_RxID, const uint32_t i_dataLen,  volatile uint8_t *i_pDataBuf)
{
    static uint16_t tp_len_need_rece = 0;
    static uint16_t tp_rx_index = 0;

    if(i_dataLen!=DATA_LEN)//检测长度是否正确
    {
        return FALSE;
    }
    if(LIN_DIAG_MASTER_REQUEST_ID!=i_RxID)//判断是否为主机请求地址
    {
        return FALSE;
    }
    if(!((LINTP_DEVICE_NAD_Get()==i_pDataBuf[0])||(LIN_FUNC_ID==i_pDataBuf[0])))//检测ID号是否匹配
    {
        return FALSE;
    }
    
    uint8_t i_eFrameType = (i_pDataBuf[1]>>4);//获得帧类型
    if(!(SF == i_eFrameType ||FF == i_eFrameType  ||CF == i_eFrameType))//判断类型是否合法
    {
        return FALSE;
    }
    
    volatile uint16_t data_len = i_pDataBuf[1]&0x0f;
    
    if(SF == i_eFrameType)
    {
        gs_stLinTPTxRxDataInfo.stLinTpDataInfo.xLinTpId = i_RxID;
        gs_stLinTPTxRxDataInfo.stLinTpDataInfo.xPduDataLen = data_len;
        for(int i = 0;i<data_len;i++)//先将缓存内容填满填充值
        {
            gs_stLinTPTxRxDataInfo.stLinTpDataInfo.aDataBuf[i] = FILL_VALUE;
        }
        for(int i = 0;i<data_len;i++)//把单帧数据保存方便后续处理
        {
            gs_stLinTPTxRxDataInfo.stLinTpDataInfo.aDataBuf[i] = i_pDataBuf[i+2];
        }

        SetRxMsgReadlly();//消息接收完成状态更新，可以通知应用层处理消息了
        SetCurLINTPSatus(RX_SF);//状态更新为接收单帧状态
    }
    else if(FF == i_eFrameType)
    {
        gs_stLinTPTxRxDataInfo.stLinTpDataInfo.xLinTpId = i_RxID;
        tp_len_need_rece = (data_len<<8)+i_pDataBuf[2];
        gs_stLinTPTxRxDataInfo.stLinTpDataInfo.xPduDataLen = tp_len_need_rece;
        for(int i = 0;i<tp_len_need_rece;i++)//先将缓存内容填满填充值
        {
            gs_stLinTPTxRxDataInfo.stLinTpDataInfo.aDataBuf[i] = FILL_VALUE;
        }
        for(int i = 0;i<FF_DATA_MIN_LEN;i++)//保存首帧数据
        {
            gs_stLinTPTxRxDataInfo.stLinTpDataInfo.aDataBuf[i] = i_pDataBuf[i+3];
        }
        tp_rx_index = FF_DATA_MIN_LEN;//下个连续帧起始编号
        tp_len_need_rece = tp_len_need_rece - (FF_DATA_MIN_LEN);//剩余需要接收的数据长度
        SetCurLINTPSatus(RX_FF);//状态更新

    }
    else if(CF == i_eFrameType)
    {
        int current_sn = i_pDataBuf[1]&0x0f;
        if(current_sn>=4)
        {
        }
        SetCurLINTPSatus(RX_CF);//状态更新
        data_len = 6;
        if(tp_len_need_rece>6)
        {
            tp_len_need_rece = tp_len_need_rece-6;            
        }
        else
        {
            SetRxMsgReadlly();//消息接收完成状态更新，可以通知应用层处理消息了
            SetCurLINTPSatus(IDLE);//状态更新
        }
        for(int i = 0;i<data_len;i++)//保存数据
        {
            gs_stLinTPTxRxDataInfo.stLinTpDataInfo.aDataBuf[tp_rx_index] = i_pDataBuf[i+2];
            tp_rx_index++;
        }
        
    }
    return TRUE;
}



/*Driver write data in TP for read message from BUS*/
BOOL TP_DriverWriteDataInTP(const uint32_t i_RxID, const uint32_t i_RxDataLen,  volatile uint8_t *i_pRxDataBuf)
{
	BOOL result = FALSE;


	
	result = LINTP_DriverWriteDataInLINTP(i_RxID, i_RxDataLen, i_pRxDataBuf);

	return result;
}













static void Diag_Tx_Data_assignment(void)
{
	uint8_t Tmp_DataLen =0u;
	for(uint8_t i = 0;i<8;i++)
	{
		g_lin_Diag_Tx_data_buffer[i] = 0xFF;
	}
	
	if(TRUE == IsTxMsgReally())
	{
		if(LIN_DIAG_SLAVER_RESPOND_ID == gs_stLinTPTxRxDataInfo.stLinTpDataInfo.xLinTpId)
		{
			if(gs_stLinTPTxRxDataInfo.stLinTpDataInfo.xPduDataLen <=  SF_DATA_MAX_LEN)
			{
				g_lin_Diag_Tx_data_buffer[0] = LINTP_DEVICE_NAD_Get();//NAD
			    g_lin_Diag_Tx_data_buffer[1] = gs_stLinTPTxRxDataInfo.stLinTpDataInfo.xPduDataLen;
				for(uint8_t i = 0;i<gs_stLinTPTxRxDataInfo.stLinTpDataInfo.xPduDataLen;i++)
				{
					g_lin_Diag_Tx_data_buffer[2+i] = gs_stLinTPTxRxDataInfo.stLinTpDataInfo.aDataBuf[i];
				}
				ClearTxMsgReadlly();
			}
			else
			{
				if(gs_stLinTPTxRxDataInfo.stLinTpDataInfo.xFFDataIndex+8 < gs_stLinTPTxRxDataInfo.stLinTpDataInfo.xPduDataLen)
				{
					for(uint8_t i = 0;i<8;i++)
					{
						g_lin_Diag_Tx_data_buffer[i] = gs_stLinTPTxRxDataInfo.stLinTpDataInfo.aDataBuf[gs_stLinTPTxRxDataInfo.stLinTpDataInfo.xFFDataIndex];
						gs_stLinTPTxRxDataInfo.stLinTpDataInfo.xFFDataIndex+=1;
					}
				}
				else
				{
					Tmp_DataLen = gs_stLinTPTxRxDataInfo.stLinTpDataInfo.xPduDataLen - gs_stLinTPTxRxDataInfo.stLinTpDataInfo.xFFDataIndex;
					for(uint8_t i = 0;i<Tmp_DataLen;i++)
					{
						g_lin_Diag_Tx_data_buffer[i] = gs_stLinTPTxRxDataInfo.stLinTpDataInfo.aDataBuf[gs_stLinTPTxRxDataInfo.stLinTpDataInfo.xFFDataIndex];
						gs_stLinTPTxRxDataInfo.stLinTpDataInfo.xFFDataIndex+=1;
					}
					ClearTxMsgReadlly();
				}
			}
			g_lin_Diag_Tx_data_Len =8u;
		}
		else
		{
			ClearTxMsgReadlly();
			g_lin_Diag_Tx_data_Len =0u;
		}
	}
	else
	{
		g_lin_Diag_Tx_data_Len =0u;
	}
	
}
static void Diag_Tx_Complete(void)
{
	if(LIN_DIAG_SLAVER_RESPOND_ID == gs_stLinTPTxRxDataInfo.stLinTpDataInfo.xLinTpId)
	{
		if(gs_stLinTPTxRxDataInfo.stLinTpDataInfo.xPduDataLen <=  SF_DATA_MAX_LEN)
		{
			if(g_lin_Diag_Tx_data_buffer[2]==0x51)//判断是否为复位应答信号，如果是需要在发送应答后置起复位标志进行复位
			{
				System_ResetDelayTimeSet(T10_100MS);
				System_SwResetFlagSet(TRUE);
			}
		}
	}
	g_lin_Diag_Tx_data_Len =0u;
}
static void Diag_Rx_Complete(void)
{
	if(g_lin_Diag_Rx_data_buffer[0] == LIN_NAD_SLEEP)
	{
		if(0u == PowerApp_DiagSleepNoResponseEnGet())
		{
			System_Sleep_Event_Set(LIN_BUS_EVENT);
		}
	}
	else
	{

		TP_DriverWriteDataInTP(LIN_DIAG_MASTER_REQUEST_ID, sizeof(g_lin_Diag_Rx_data_buffer), g_lin_Diag_Rx_data_buffer);

	}
}



void UDS_Tp_Init(void)
{
	l_ifc_tl_InstallCallback_Diag_Tx_Data_assignment_LI0(Diag_Tx_Data_assignment);
	l_ifc_tl_InstallCallback_Diag_Tx_Complete_LI0(Diag_Tx_Complete);
	l_ifc_tl_InstallCallback_Diag_Rx_Complete_LI0(Diag_Rx_Complete);
}




