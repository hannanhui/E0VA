/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      Uds_App.c                                                                */
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
#include<string.h>






typedef struct
{
    uint8_t CurSessionMode;  /*current session mode. default/program/extend mode*/
    uint8_t RequsetIdMode;   /*SUPPORT_PHYSICAL_ADDR/SUPPORT_FUNCTION_ADDR*/
    uint8_t SecurityLevel;   /*current security level*/
    uint16_t xUdsS3ServerTime;      /*uds s3 server time*/
    uint16_t xSecurityReqLockTime;  /*security request lock time*/
} tUdsInfo;
static void Uds_DigSession(struct UDSServiceInfo* i_pstUDSServiceInfo, tUdsAppMsgInfo *m_pstPDUMsg);
static void Uds_SecurityAccess(struct UDSServiceInfo* i_pstUDSServiceInfo, tUdsAppMsgInfo *m_pstPDUMsg);
static void Uds_ReadDataByIdentifier(struct UDSServiceInfo* i_pstUDSServiceInfo, tUdsAppMsgInfo *m_pstPDUMsg);
static void Uds_WriteDataByIdentifier(struct UDSServiceInfo* i_pstUDSServiceInfo, tUdsAppMsgInfo *m_pstPDUMsg);
static void Uds_ResetECU(struct UDSServiceInfo* i_pstUDSServiceInfo, tUdsAppMsgInfo *m_pstPDUMsg);
tUdsInfo gs_stUdsInfo =
{
    DEFALUT_SESSION,
    ERRO_REQUEST_ID,
    NONE_SECURITY,
    0u,
    0u,
};
/*dig serverice config table*/
//列举出所有支持的UDS服务项
const tUDSService gs_astUDSService[] =
{
    /*diagnose mode control*/
    {
        0x10u,
        DEFALUT_SESSION | PROGRAM_SESSION | EXTEND_SESSION,
        SUPPORT_PHYSICAL_ADDR | SUPPORT_FUNCTION_ADDR,
        SECURITY_LEVEL_1,
        Uds_DigSession
    },
	/*read data by identifier*/
    {
        0x22u,
        DEFALUT_SESSION | PROGRAM_SESSION | EXTEND_SESSION,
        SUPPORT_PHYSICAL_ADDR | SUPPORT_FUNCTION_ADDR,
        NONE_SECURITY,
        Uds_ReadDataByIdentifier
    },
    /*security access*/
    {
        0x27u,
        PROGRAM_SESSION | EXTEND_SESSION,
        SUPPORT_PHYSICAL_ADDR,
        SECURITY_LEVEL_1,
        Uds_SecurityAccess
    },

    /*write data by identifier*/
    {
        0x2Eu,
        PROGRAM_SESSION | EXTEND_SESSION,
        SUPPORT_PHYSICAL_ADDR,
        SECURITY_LEVEL_1,
        Uds_WriteDataByIdentifier
    },
    /*reset ECU*/
    {
        0x11u,
        PROGRAM_SESSION | EXTEND_SESSION,
        SUPPORT_PHYSICAL_ADDR | SUPPORT_FUNCTION_ADDR,
        SECURITY_LEVEL_1,
        Uds_ResetECU
    },

};


typedef struct
{
    uint8_t CalledPeriod;         /*called uds period*/
    /*security request count. If over this security request count, locked server some time.*/
    uint8_t SecurityRequestCnt;
    uint16_t xLockTime;         /*lock time*/
    uint16_t xS3Server;         /*s3 server time. */
} tUdsTimeInfo;

/* UDS time control information config table*/
const static tUdsTimeInfo gs_stUdsAppCfg =
{
    1u,
    3u,
    10000u,
    5000u
};
/*uds app time to count*/
#define UdsAppTimeToCount(xTime) ((xTime) / gs_stUdsAppCfg.CalledPeriod)


/*set currrent session mode. DEFAULT_SESSION/PROGRAM_SESSION/EXTEND_SESSION */
void SetCurrentSession(const uint8_t i_SerSessionMode)
{
    gs_stUdsInfo.CurSessionMode = i_SerSessionMode;
}
/*restart s3server time*/
void RestartS3Server(void)
{
    gs_stUdsInfo.xUdsS3ServerTime = UdsAppTimeToCount(gs_stUdsAppCfg.xS3Server);
}
void SubUdsS3ServerTime(uint16_t i_SubTime)
{
    gs_stUdsInfo.xUdsS3ServerTime -= i_SubTime;
}
static uint16_t GetUdsS3ServerTime(void)
{
    return (gs_stUdsInfo.xUdsS3ServerTime);
}

/*set security level*/
void SetSecurityLevel(uint8_t i_SerSecurityLevel)
{
    gs_stUdsInfo.SecurityLevel = i_SerSecurityLevel;
}

/*set negative erro code*/
void SetNegativeErroCode(const uint8_t i_UDSServiceNum,
                         const uint8_t i_ErroCode,
                         tUdsAppMsgInfo *m_pstPDUMsg)
{
	

    m_pstPDUMsg->aDataBuf[0u] = NEGTIVE_ID;
    m_pstPDUMsg->aDataBuf[1u] = i_UDSServiceNum;
    m_pstPDUMsg->aDataBuf[2u] = i_ErroCode;
    m_pstPDUMsg->xDataLen = 3u;
}

/*app memset*/
static void AppMemset(const uint8_t i_SetValue, const uint16_t i_Len, void *m_pvSource)
{
    
    memset(m_pvSource, i_SetValue, i_Len);
}


/*Is current received id can request?*/
uint8_t IsCurRxIdCanRequest(uint8_t i_SerRequestIdMode)
{
    uint8_t status = 0u;

    if((i_SerRequestIdMode & gs_stUdsInfo.RequsetIdMode) == gs_stUdsInfo.RequsetIdMode)
    {
        status = TRUE;
    }
    else
    {
        status = FALSE;
    }

    return status;
}
/*Is current security level can request?*/
uint8_t IsCurSecurityLevelRequet(uint8_t i_SerSecurityLevel)
{
    uint8_t status = 0u;

    if((i_SerSecurityLevel & gs_stUdsInfo.SecurityLevel) == gs_stUdsInfo.SecurityLevel)
    {
        status = TRUE;
    }
    else
    {
        status = FALSE;
    }

    return status;
}

/*Is current session can request?*/
uint8_t IsCurSeesionCanRequest(uint8_t i_SerSessionMode)
{
    uint8_t status = FALSE;

    if((i_SerSessionMode & gs_stUdsInfo.CurSessionMode) == gs_stUdsInfo.CurSessionMode)
    {
        status = TRUE;
    }
    else
    {
        status = FALSE;
    }

    return status;
}


/******************************UDS service main function define***************************************/
/*dig session*/
static void Uds_DigSession(struct UDSServiceInfo* i_pstUDSServiceInfo, tUdsAppMsgInfo *m_pstPDUMsg)
{
    uint8_t RequestSubfunction = 0u;


    RequestSubfunction = m_pstPDUMsg->aDataBuf[1u];

    /*set send postive message*/
    m_pstPDUMsg->aDataBuf[0u] = i_pstUDSServiceInfo->SerNum + 0x40u;
    m_pstPDUMsg->aDataBuf[1u] = RequestSubfunction;
    m_pstPDUMsg->xDataLen = 2u;

    /*sub function*/
    switch(RequestSubfunction)
    {
    case 0x01u :  /*default mode*/
        SetCurrentSession(DEFALUT_SESSION);
        SetSecurityLevel(NONE_SECURITY);
        break;

    case 0x02u :  /*program mode*/
        SetCurrentSession(PROGRAM_SESSION);
        /*restart s3server time*/
        RestartS3Server();
		if(IsCurSecurityLevelRequet(SECURITY_LEVEL_1))
		{
			if(NVM_Handle_RunAreaSet(NVM_Handle_Run_At_Boot)==TRUE)
    		{ 
    			System_ResetDelayTimeSet(T10_100MS);
    			System_SwResetFlagSet(TRUE);
				//SetNegativeErroCode(i_pstUDSServiceInfo->SerNum, RCRRP, m_pstPDUMsg);
			}
			
		}
        break;

    case 0x03u :  /*extend mode*/
        SetCurrentSession(EXTEND_SESSION);

        /*restart s3server time*/
        RestartS3Server();
        break;

    default :
        SetNegativeErroCode(i_pstUDSServiceInfo->SerNum, SFNS, m_pstPDUMsg);
        break;
    }
}
/*security access*/
static void Uds_SecurityAccess(struct UDSServiceInfo* i_pstUDSServiceInfo, tUdsAppMsgInfo *m_pstPDUMsg)
{
    uint8_t RequestSubfunction = 0u;
    static uint8_t s_aSeedBuf[AES_SEED_LEN] = {0u};
    BOOL ret = FALSE;


    /*get subfunction*/
    RequestSubfunction = m_pstPDUMsg->aDataBuf[1u];

    switch(RequestSubfunction)
    {
    case 0x01u :
        m_pstPDUMsg->aDataBuf[0u] = i_pstUDSServiceInfo->SerNum + 0x40u;

        /*get random and put in m_pstPDUMsg->aDataBuf[2u] ~ 17u byte*/
        ret = UDS_ALG_HAL_GetRandom(AES_SEED_LEN, s_aSeedBuf);
        
        if(TRUE == ret)
        {
            //memcpy(s_aSeedBuf, &m_pstPDUMsg->aDataBuf[2u],AES_SEED_LEN);
			for(uint8_t i=0;i<AES_SEED_LEN;i++)
			{
				 m_pstPDUMsg->aDataBuf[2u+i] = s_aSeedBuf[i];
			}
            m_pstPDUMsg->xDataLen = 2u + AES_SEED_LEN;
        }
        else
        {
            SetNegativeErroCode(i_pstUDSServiceInfo->SerNum, IK, m_pstPDUMsg);
        }
        
        break;

    case 0x02u :
        /*count random to key and check received key right?*/
        if(TRUE == UDS_ALG_HAL_Check_ReceiveKeyRight(&m_pstPDUMsg->aDataBuf[2u], s_aSeedBuf, AES_SEED_LEN))
        {
            m_pstPDUMsg->aDataBuf[0u] = i_pstUDSServiceInfo->SerNum + 0x40u;

            m_pstPDUMsg->xDataLen = 2u;

            AppMemset(0x1u, sizeof(s_aSeedBuf), s_aSeedBuf);

            SetSecurityLevel(SECURITY_LEVEL_1);
        }
        else
        {
            SetNegativeErroCode(i_pstUDSServiceInfo->SerNum, IK, m_pstPDUMsg);
        }

        break;

    default :

        break;
    }
}


/*write data by identifier*/
static void Uds_WriteDataByIdentifier(struct UDSServiceInfo* i_pstUDSServiceInfo, tUdsAppMsgInfo *m_pstPDUMsg)
{

}
uint8_t ECUSoftwareNumberDef[9] ={0x48,0x36,0x01,0x01,0x04,0x00,0x00,0x00,0x00};
/*write data by identifier*/
static void Uds_ReadDataByIdentifier(struct UDSServiceInfo* i_pstUDSServiceInfo, tUdsAppMsgInfo *m_pstPDUMsg)
{
	uint16_t RequestSubfunction = 0u;
	uint8_t i=0u;
	uint16_t SwVersionDecimalism=0u;
	uint8_t SwYear=0;
	uint8_t SwMonth=0;
	uint8_t SwDay=0;
	uint8_t SwTimer=0;
	uint8_t Datebuff[11]={STR_SOFT_DATE};
	uint8_t HwVerbuff[6]={HW_DEF_VERSION};
//	CHECK_RESTRICTION(NULL != m_pstPDUMsg);
 //   CHECK_RESTRICTION(NULL != i_pstUDSServiceInfo);

    RequestSubfunction = (uint16_t)((m_pstPDUMsg->aDataBuf[1u]<<8) |(m_pstPDUMsg->aDataBuf[2u]));

	switch(RequestSubfunction)
    {
    	case DID_ECUSoftwareNumberIdentifier :
			m_pstPDUMsg->aDataBuf[0u] = i_pstUDSServiceInfo->SerNum + 0x40u;
			for(i=0;i<9;i++)
			{
				m_pstPDUMsg->aDataBuf[i+3] =ECUSoftwareNumberDef[i];
			}
			m_pstPDUMsg->xDataLen = 12u;
		break;
		
		case DID_ECUSoftwareVersionNumberDataIdentifier :
			m_pstPDUMsg->aDataBuf[0u] = i_pstUDSServiceInfo->SerNum + 0x40u;
			SwVersionDecimalism = (App_Major_Version[1]-0x30)*100000 +(App_Major_Version[2]-0x30)*10000 +(App_Major_Version[4]-0x30)*1000+(App_Major_Version[5]-0x30)*100+(App_Major_Version[7]-0x30)*10+(App_Major_Version[8]-0x30);
			SwYear =  (App_Major_Version[10]-0x30)*10 +(App_Major_Version[11]-0x30);
			SwMonth =  (App_Major_Version[12]-0x30)*10 +(App_Major_Version[13]-0x30);
			SwDay =  (App_Major_Version[14]-0x30)*10 +(App_Major_Version[15]-0x30);
			SwTimer =  (App_Major_Version[17]-0x30)*10 +(App_Major_Version[18]-0x30);
			m_pstPDUMsg->aDataBuf[3] =(SwVersionDecimalism>>8);
			m_pstPDUMsg->aDataBuf[4] =(SwVersionDecimalism&0xFF);
			m_pstPDUMsg->aDataBuf[5] =(SwYear&0xFF);
			m_pstPDUMsg->aDataBuf[6] =(SwMonth&0xFF);
			m_pstPDUMsg->aDataBuf[7] =(SwDay&0xFF);
			m_pstPDUMsg->aDataBuf[8] =(SwTimer&0xFF);
			m_pstPDUMsg->xDataLen = 9u;
	
		break;
		
		case DID_ECUHardwareVersionNumberDataIdentifier :
			m_pstPDUMsg->aDataBuf[0u] = i_pstUDSServiceInfo->SerNum + 0x40u;
			SwVersionDecimalism = (HwVerbuff[0]-0x30)*100 +(HwVerbuff[2]-0x30)*10 +(HwVerbuff[4]-0x30);
			SwYear =  (Datebuff[2]-0x30)*10 +(Datebuff[3]-0x30);
			SwMonth =  (Datebuff[5]-0x30)*10 +(Datebuff[6]-0x30);
			SwDay = (Datebuff[8]-0x30)*10 +(Datebuff[9]-0x30);
			SwTimer = 0x00;
			m_pstPDUMsg->aDataBuf[3] =(SwVersionDecimalism&0xFF);
			m_pstPDUMsg->aDataBuf[4] =(SwYear&0xFF);
			m_pstPDUMsg->aDataBuf[5] =(SwMonth&0xFF);
			m_pstPDUMsg->aDataBuf[6] =(SwDay&0xFF);
			m_pstPDUMsg->aDataBuf[7] =(SwTimer&0xFF);
			m_pstPDUMsg->xDataLen = 8u;
		break;
		
		case DID_BootSoftwareIdentification :
			m_pstPDUMsg->aDataBuf[0u] = i_pstUDSServiceInfo->SerNum + 0x40u;
			SwVersionDecimalism = (Boot_Major_Version[1]-0x30)*100000 +(Boot_Major_Version[2]-0x30)*10000 +(Boot_Major_Version[4]-0x30)*1000+(Boot_Major_Version[5]-0x30)*100+(Boot_Major_Version[7]-0x30)*10+(Boot_Major_Version[8]-0x30);
			SwYear =  (Boot_Major_Version[10]-0x30)*10 +(Boot_Major_Version[11]-0x30);
			SwMonth =  (Boot_Major_Version[12]-0x30)*10 +(Boot_Major_Version[13]-0x30);
			SwDay =  (Boot_Major_Version[14]-0x30)*10 +(Boot_Major_Version[15]-0x30);
			SwTimer =  (Boot_Major_Version[17]-0x30)*10 +(Boot_Major_Version[18]-0x30);
			m_pstPDUMsg->aDataBuf[3] =(SwVersionDecimalism>>8);
			m_pstPDUMsg->aDataBuf[4] =(SwVersionDecimalism&0xFF);
			m_pstPDUMsg->aDataBuf[5] =(SwYear&0xFF);
			m_pstPDUMsg->aDataBuf[6] =(SwMonth&0xFF);
			m_pstPDUMsg->aDataBuf[7] =(SwDay&0xFF);
			m_pstPDUMsg->aDataBuf[8] =(SwTimer&0xFF);
			m_pstPDUMsg->xDataLen = 9u;
		break;
		default:
			SetNegativeErroCode(i_pstUDSServiceInfo->SerNum, ROOR, m_pstPDUMsg);
			break;
	}

}

/*reset ECU*/
static void Uds_ResetECU(struct UDSServiceInfo* i_pstUDSServiceInfo, tUdsAppMsgInfo *m_pstPDUMsg)
{
    uint8_t RequestSubfunction = 0u;



    RequestSubfunction = m_pstPDUMsg->aDataBuf[1u];
    
    if(NVM_Handle_RunAreaSet(NVM_Handle_Run_At_App)==TRUE)
    {        
        /*set send postive message*/
        m_pstPDUMsg->aDataBuf[0u] = i_pstUDSServiceInfo->SerNum + 0x40u;
        m_pstPDUMsg->aDataBuf[1u] = RequestSubfunction;
        m_pstPDUMsg->xDataLen = 2u;
    }
    else
    {
        SetNegativeErroCode(i_pstUDSServiceInfo->SerNum, SNS, m_pstPDUMsg);
    }

    /*sub function*/
//    switch(RequestSubfunction)
}

/**********************UDS service correlation other function realizing************************/
/* get uds service config information */
tUDSService* GetUDSServiceInfo(uint8_t *m_pSupServItem)
{

    
    *m_pSupServItem = sizeof(gs_astUDSService) / sizeof(gs_astUDSService[0u]);

    return (tUDSService*) &gs_astUDSService[0u];
}

/*uds time control*/
void UDS_SystemTickCtl(void)
{
    if(GetUdsS3ServerTime())
    {
        SubUdsS3ServerTime(1u);
    }
}

/*uds main function. ISO14229*/
void UDS_MainFun(void)
{
    tUDSService *pstUDSService = NULL;
    uint8_t SupSerItem = 0u;
    uint8_t UDSSerNum = 0u;
    uint8_t UDSSerIndex = 0u;
    uint8_t isFindService = FALSE;
    tUdsAppMsgInfo stUdsAppMsg = {0u, 0u, {0u}, NULL};
    
    UDS_ALG_HAL_AddSWTimerTickCnt();//随机时间用于产生随机种子
    //检查消息接收是否完成
    if(IsRxMsgReally()==FALSE)
    {
        return;
    }
    
    if(LINTP_RxMsg(&stUdsAppMsg.xUdsId,&stUdsAppMsg.xDataLen,stUdsAppMsg.aDataBuf)==FALSE)
    {
        return;
    }
    
    /*get UDS service Information, start PTR and service item 获得所有服务列表*/
    pstUDSService = GetUDSServiceInfo(&SupSerItem);
    
    /*get UDS service ID 获得SID号*/
    UDSSerNum = stUdsAppMsg.aDataBuf[0u];
    
    while((UDSSerIndex < SupSerItem) && (NULL != pstUDSService))
    {
        if(UDSSerNum == pstUDSService[UDSSerIndex].SerNum)
        {
            isFindService = TRUE;

            if(TRUE != IsCurRxIdCanRequest(pstUDSService[UDSSerIndex].SupReqMode))
            {
                /*received ID cann't request this service.*/
                SetNegativeErroCode(stUdsAppMsg.aDataBuf[0u], SNS, &stUdsAppMsg);

                break;
            }

            if(TRUE != IsCurSeesionCanRequest(pstUDSService[UDSSerIndex].SessionMode))
            {
                /*currnet session mode cann't request ths service.*/
                SetNegativeErroCode(stUdsAppMsg.aDataBuf[0u], SNS, &stUdsAppMsg);

                break;
            }

            if(TRUE != IsCurSecurityLevelRequet(pstUDSService[UDSSerIndex].ReqLevel))
            {
                /*current security level cann't request this service.*/
                SetNegativeErroCode(stUdsAppMsg.aDataBuf[0u], SNS, &stUdsAppMsg);

                break;
            }

            stUdsAppMsg.pfUDSTxMsgServiceCallBack = NULL;

            /*find service, and do it.*/
            if(NULL != pstUDSService[UDSSerIndex].pfSerNameFun)
            {
                pstUDSService[UDSSerIndex].pfSerNameFun((tUDSService *)&pstUDSService[UDSSerIndex], &stUdsAppMsg);
                ClearRxMsgReadlly();
//                ReallyTxBuffFlag = TRUE;
            }
            else
            {
                /*current security level cann't request this service.*/
                SetNegativeErroCode(stUdsAppMsg.aDataBuf[0u], SNS, &stUdsAppMsg);
            }

            break;
        }

        UDSSerIndex++;
    }
    RestartS3Server();
    if(TRUE != isFindService)
    {
        /*response not support service.*/
        SetNegativeErroCode(stUdsAppMsg.aDataBuf[0u], SNS, &stUdsAppMsg);
    }
    else
    {
        //将准备发送的数据放入待应答缓存gs_stLinTPTxRxDataInfo
        if(IsRxMsgReally()==FALSE)
        {
        	LINTP_TxMsg(LIN_DIAG_SLAVER_RESPOND_ID,stUdsAppMsg.xDataLen, stUdsAppMsg.aDataBuf,g_stLINUdsNetLayerCfgInfo.txBlockingMaxTimeMs);
        }
        isFindService = FALSE;
    }
    
    ClearRxMsgReadlly();
}

