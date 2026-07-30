/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      Uds_App.c                                                                */
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
#include "include.h"



#if UPGRADE_MODE == UPGRADE_MODE_FOR_UDS_LIN

typedef struct
{
    uint8_t CurSessionMode;  /*current session mode. default/program/extend mode*/
    uint8_t RequsetIdMode;   /*SUPPORT_PHYSICAL_ADDR/SUPPORT_FUNCTION_ADDR*/
    uint8_t SecurityLevel;   /*current security level*/
    uint16_t xUdsS3ServerTime;      /*uds s3 server time*/
    uint16_t xSecurityReqLockTime;  /*security request lock time*/
} tUdsInfo;

#define	Wait_EarseMemory_TimeTick_mS		4000
#define	Wait_CheckMemory_TimeTick_mS		2000
#define READBACK_PACKAGE_SIZE_BYTE		2048
#define SERVICE_LOCAL_RECV_SIZE		2048//256//512//1024


uint32_t app_Eraseaddr =0u;
uint32_t app_EraseLength =0u;
uint32_t Memory_CheckSum =0u;
uint8_t Memory_Crc8 =0u;

uint32_t Uds_Image_CheckSum;
uint8_t  Uds_Image_Crc8;

uint8_t Request_App_Erase_Flag = FALSE;
uint8_t Request_App_Erase_Result = FALSE;
uint8_t Request_App_CheckMemory_Flag = FALSE;
uint8_t Request_App_CheckMemory_Result = FALSE;

static void Uds_DigSession(struct UDSServiceInfo* i_pstUDSServiceInfo, tUdsAppMsgInfo *m_pstPDUMsg);
static void Uds_CommunicationControl(struct UDSServiceInfo* i_pstUDSServiceInfo, tUdsAppMsgInfo *m_pstPDUMsg);
static void Uds_ControlDTCSetting(struct UDSServiceInfo* i_pstUDSServiceInfo, tUdsAppMsgInfo *m_pstPDUMsg);
static void Uds_SecurityAccess(struct UDSServiceInfo* i_pstUDSServiceInfo, tUdsAppMsgInfo *m_pstPDUMsg);
static void Uds_WriteDataByIdentifier(struct UDSServiceInfo* i_pstUDSServiceInfo, tUdsAppMsgInfo *m_pstPDUMsg);
static void Uds_ReadDataByIdentifier(struct UDSServiceInfo* i_pstUDSServiceInfo, tUdsAppMsgInfo *m_pstPDUMsg);
static void Uds_RequestDownload(struct UDSServiceInfo* i_pstUDSServiceInfo, tUdsAppMsgInfo *m_pstPDUMsg);
static void Uds_TransferData(struct UDSServiceInfo* i_pstUDSServiceInfo, tUdsAppMsgInfo *m_pstPDUMsg);
static void Uds_RequestTransferExit(struct UDSServiceInfo* i_pstUDSServiceInfo, tUdsAppMsgInfo *m_pstPDUMsg);
static void Uds_RoutineControl(struct UDSServiceInfo* i_pstUDSServiceInfo, tUdsAppMsgInfo *m_pstPDUMsg);
static void Uds_ResetECU(struct UDSServiceInfo* i_pstUDSServiceInfo, tUdsAppMsgInfo *m_pstPDUMsg);
tUdsInfo gs_stUdsInfo =
{
    PROGRAM_SESSION,
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

    /*communication control*/
    {
        0x28u,
        DEFALUT_SESSION | PROGRAM_SESSION | EXTEND_SESSION,
        SUPPORT_PHYSICAL_ADDR | SUPPORT_FUNCTION_ADDR,
        NONE_SECURITY,
        Uds_CommunicationControl
    },

    /*control DTC setting*/
    {
        0x85u,
        DEFALUT_SESSION | PROGRAM_SESSION | EXTEND_SESSION,
        SUPPORT_PHYSICAL_ADDR | SUPPORT_FUNCTION_ADDR,
        NONE_SECURITY,
        Uds_ControlDTCSetting
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

    /*request download data */
    {
        0x34u,
        PROGRAM_SESSION,
        SUPPORT_PHYSICAL_ADDR,
        SECURITY_LEVEL_1,
        Uds_RequestDownload
    },

    /*transter data*/
    {
        0x36u,
        PROGRAM_SESSION,
        SUPPORT_PHYSICAL_ADDR,
        SECURITY_LEVEL_1,
        Uds_TransferData
    },

    /*request exit transfer data*/
    {
        0x37u,
        PROGRAM_SESSION,
        SUPPORT_PHYSICAL_ADDR,
        SECURITY_LEVEL_1,
        Uds_RequestTransferExit
    },

    /*routine control*/
    {
        0x31u,
        PROGRAM_SESSION,
        SUPPORT_PHYSICAL_ADDR,
        SECURITY_LEVEL_1,
        Uds_RoutineControl
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
/* calculate block number */
static uint8_t gs_CalBlockNum = 0u;
/* calculate block number */
static uint8_t gs_ImageTransferStatus = 0u;

/* received block number */
static uint8_t gs_RxBlockNum = 0u;
/*download data info*/
static tDowloadDataInfo gs_stDowloadDataInfo = {0u, 0u};
/*erase memory routine cotnrol ID*/
const static uint8_t gs_aEraseMemoryRoutineControlId[] = {0x31u, 0x01u, 0xDFu, 0xFFu};
/*stop routine cotnrol ID*/
const static uint8_t gs_aStopRoutineControlId[] = {0x31u, 0x02u};

/*check sum routine control ID*/
const static uint8_t gs_aCheckSumRoutineControlId[] = {0x31u, 0x01u, 0xDFu, 0xFEu};

const static uint8_t gs_aEraseMemoryRoutineResultId[] = {0x31u, 0x03u, 0xDFu, 0xFFu};
/*check sum routine control ID*/
const static uint8_t gs_aCheckSumRoutineResultId[] = {0x31u, 0x03u, 0xDFu, 0xFEu};

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
void Uds_SetApp_Erase_Flag(void)
{
    Request_App_Erase_Flag = TRUE;
}
void Uds_SetApp_CheckMemory_Flag(void)
{
    Request_App_CheckMemory_Flag = TRUE;
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
	CHECK_RESTRICTION(NULL != m_pstPDUMsg);

    m_pstPDUMsg->aDataBuf[0u] = NEGTIVE_ID;
    m_pstPDUMsg->aDataBuf[1u] = i_UDSServiceNum;
    m_pstPDUMsg->aDataBuf[2u] = i_ErroCode;
    m_pstPDUMsg->xDataLen = 3u;
}

/*app memset*/
static void AppMemset(const uint8_t i_SetValue, const uint16_t i_Len, void *m_pvSource)
{
	CHECK_RESTRICTION(NULL != m_pvSource);
    
    memset(m_pvSource, i_SetValue, i_Len);
}
/*Is download data address valid?*/
static uint8_t IsDownloadDataAddrValid(const uint32_t i_DataAddr)
{
    if((i_DataAddr>=ApplicationAddress)&&(i_DataAddr<=(ApplicationAddress+APP_SIZE)))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/*Is dowload data len valid?*/
static uint8_t IsDownloadDataLenValid(const uint32_t i_DataLen)
{
   if(i_DataLen<=(APP_SIZE))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
/*check routine control right?*/
static uint8_t IsCheckRoutineControlRight(const tCheckRoutineCtlInfo i_eCheckRoutineCtlId,
                                        const tUdsAppMsgInfo *m_pstPDUMsg)
{
    uint8_t Index = 0u;
    uint8_t FindCnt = 0u;
    uint8_t *pDestRoutineCltId = NULL;

    CHECK_RESTRICTION(NULL != m_pstPDUMsg);

    switch(i_eCheckRoutineCtlId)
    {
    case ERASE_MEMORY_ROUTINE_CONTROL :
        pDestRoutineCltId = (uint8_t *)&gs_aEraseMemoryRoutineControlId[0u];

        FindCnt = sizeof(gs_aEraseMemoryRoutineControlId);

        break;
	case STOP_ROUTINE_CONTROL:
		pDestRoutineCltId = (uint8_t *)&gs_aStopRoutineControlId[0u];
        FindCnt = sizeof(gs_aStopRoutineControlId);
		break;
    case CHECK_SUM_ROUTINE_CONTROL :
        pDestRoutineCltId = (uint8_t *)&gs_aCheckSumRoutineControlId[0u];
        FindCnt = sizeof(gs_aCheckSumRoutineControlId);
        break;
		

	case ERASE_MEMORY_ROUTINE_RESULTS:
		pDestRoutineCltId = (uint8_t *)&gs_aEraseMemoryRoutineResultId[0u];
        FindCnt = sizeof(gs_aEraseMemoryRoutineResultId);
		break;
	case CHECK_SUM_ROUTINE_RESULTS:
		pDestRoutineCltId = (uint8_t *)&gs_aCheckSumRoutineResultId[0u];
        FindCnt = sizeof(gs_aCheckSumRoutineResultId);
		break;

		
    default :

        return FALSE;

        /*This is not have break*/
    }

    if((NULL == pDestRoutineCltId) || (m_pstPDUMsg->xDataLen < FindCnt))
    {
        return FALSE;
    }

    while(Index < FindCnt)
    {
        if(m_pstPDUMsg->aDataBuf[Index] != pDestRoutineCltId[Index])
        {
            return FALSE;
        }

        Index++;
    }

    return TRUE;
}

/*Is erase memory routine control */
static uint8_t IsEraseMemoryRoutineControl(const tUdsAppMsgInfo *m_pstPDUMsg)
{
	CHECK_RESTRICTION(NULL != m_pstPDUMsg);
    
    return IsCheckRoutineControlRight(ERASE_MEMORY_ROUTINE_CONTROL, m_pstPDUMsg);
}

/*Is check sum routine control?*/
static uint8_t IsCheckSumRoutineControl(const tUdsAppMsgInfo *m_pstPDUMsg)
{
	CHECK_RESTRICTION(NULL != m_pstPDUMsg);
    
    return IsCheckRoutineControlRight(CHECK_SUM_ROUTINE_CONTROL, m_pstPDUMsg);
}

/*Is erase memory routine control*/
static uint8_t IsEraseMemoryRoutineResult(const tUdsAppMsgInfo *m_pstPDUMsg)
{
	CHECK_RESTRICTION(NULL != m_pstPDUMsg);
    
    return IsCheckRoutineControlRight(ERASE_MEMORY_ROUTINE_RESULTS, m_pstPDUMsg);
}


/*Is check sum routine Result*/
static uint8_t IsCheckSumRoutineResult(const tUdsAppMsgInfo *m_pstPDUMsg)
{
	CHECK_RESTRICTION(NULL != m_pstPDUMsg);
	
	return IsCheckRoutineControlRight(CHECK_SUM_ROUTINE_RESULTS, m_pstPDUMsg);
}


/*Is stop routine control*/
static uint8_t IsStopRoutineControl(const tUdsAppMsgInfo *m_pstPDUMsg)
{
	CHECK_RESTRICTION(NULL != m_pstPDUMsg);
    
    return IsCheckRoutineControlRight(STOP_ROUTINE_CONTROL, m_pstPDUMsg);
}

/*Is current received id can request */
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

    CHECK_RESTRICTION(NULL != m_pstPDUMsg);
    CHECK_RESTRICTION(NULL != i_pstUDSServiceInfo);

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

/*communication control*/
static void Uds_CommunicationControl(struct UDSServiceInfo* i_pstUDSServiceInfo, tUdsAppMsgInfo *m_pstPDUMsg)
{
    uint8_t RequestSubfunction = 0u;

    CHECK_RESTRICTION(NULL != m_pstPDUMsg);
    CHECK_RESTRICTION(NULL != i_pstUDSServiceInfo);

    RequestSubfunction = m_pstPDUMsg->aDataBuf[1u];

    switch(RequestSubfunction)
    {
    case 0x0u :
    case 0x03u :
        m_pstPDUMsg->aDataBuf[0u] = i_pstUDSServiceInfo->SerNum + 0x40u;
        m_pstPDUMsg->aDataBuf[1u] = RequestSubfunction;
        m_pstPDUMsg->xDataLen = 2u;

        break;

    case 0x80u :
    case 0x83u :
        /*don't transmit uds message.*/
        m_pstPDUMsg->aDataBuf[0u] = 0u;
        m_pstPDUMsg->xDataLen = 0u;

        break;

    default :
        SetNegativeErroCode(i_pstUDSServiceInfo->SerNum, SFNS, m_pstPDUMsg);

        break;
    }
}

/*control DTC setting*/
static void Uds_ControlDTCSetting(struct UDSServiceInfo* i_pstUDSServiceInfo, tUdsAppMsgInfo *m_pstPDUMsg)
{
    uint8_t RequestSubfunction = 0u;

    CHECK_RESTRICTION(NULL != m_pstPDUMsg);
    CHECK_RESTRICTION(NULL != i_pstUDSServiceInfo);

    RequestSubfunction = m_pstPDUMsg->aDataBuf[1u];

    switch(RequestSubfunction)
    {
    case 0x01u :
    case 0x02u :
        m_pstPDUMsg->aDataBuf[0u] = i_pstUDSServiceInfo->SerNum + 0x40u;
        m_pstPDUMsg->aDataBuf[1u] = RequestSubfunction;
        m_pstPDUMsg->xDataLen = 2u;
        break;

    case 0x81u :
    case 0x82u :
        m_pstPDUMsg->xDataLen = 0u;
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

    CHECK_RESTRICTION(NULL != m_pstPDUMsg);
    CHECK_RESTRICTION(NULL != i_pstUDSServiceInfo);

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
/*request download*/
static void Uds_RequestDownload(struct UDSServiceInfo* i_pstUDSServiceInfo, tUdsAppMsgInfo *m_pstPDUMsg)
{
    uint8_t Index = 0u;
    uint8_t Ret = TRUE;
	uint8_t addr_ByteSize =0u;
	uint8_t Length_ByteSize =0u;
	uint32_t Recvdatalength=0u;
	CHECK_RESTRICTION(NULL != m_pstPDUMsg);
    CHECK_RESTRICTION(NULL != i_pstUDSServiceInfo);
	addr_ByteSize =((m_pstPDUMsg->aDataBuf[2]>>0 )&0x0F);
	Length_ByteSize =((m_pstPDUMsg->aDataBuf[2]>>4 )&0x0F);
    if(m_pstPDUMsg->xDataLen < (addr_ByteSize + Length_ByteSize + 1u + 2u))
    {
        Ret = FALSE;

        SetNegativeErroCode(i_pstUDSServiceInfo->SerNum, IMLOIF, m_pstPDUMsg);
    }

    if(TRUE == Ret)
    {
        /*get data addr */
        gs_stDowloadDataInfo.StartAddr = 0u;
        for(Index = 0u; Index < addr_ByteSize; Index++)
        {
            gs_stDowloadDataInfo.StartAddr <<= 8u;
            /* 3u = N_PCI(1) + SID34(1) + dataFormatldentifier(1) */
            gs_stDowloadDataInfo.StartAddr |= m_pstPDUMsg->aDataBuf[Index + 3u];
        }

        /*get data len*/
        gs_stDowloadDataInfo.DataLen = 0u;
        for(Index = 0u; Index < Length_ByteSize; Index++)
        {
            gs_stDowloadDataInfo.DataLen <<= 8u;
            gs_stDowloadDataInfo.DataLen |= m_pstPDUMsg->aDataBuf[Index + 3u+addr_ByteSize];
        }
		gs_stDowloadDataInfo.DataWrite_Size = 0u;
    }

    /*Is download data  addr  and len valid?*/
    if(((TRUE != IsDownloadDataAddrValid(gs_stDowloadDataInfo.StartAddr)) ||
            (TRUE != IsDownloadDataLenValid(gs_stDowloadDataInfo.DataLen))) && (TRUE == Ret))
    {
        SetNegativeErroCode(i_pstUDSServiceInfo->SerNum, ROOR, m_pstPDUMsg);

        Ret = FALSE;
    }
	// 检查内存是否按页对齐
	if (gs_stDowloadDataInfo.StartAddr % FLASH_ONE_SECTOR_SIZE)
	{
		SetNegativeErroCode(i_pstUDSServiceInfo->SerNum, IMLOIF, m_pstPDUMsg);

        Ret = FALSE;
	}
	
    if(TRUE == Ret)
    {
        /*set wait transfer data step(0x34 service)*/
        //Flash_SetNextDownloadStep(FL_TRANSFER_STEP);

        /*save received program addr and data len*/
        //Flash_SaveDownloadDataInfo(gs_stDowloadDataInfo.StartAddr, gs_stDowloadDataInfo.DataLen);
        
        Recvdatalength = SERVICE_LOCAL_RECV_SIZE + 2;// Identifier Id and sn 
        /*fill postive message*/
        m_pstPDUMsg->aDataBuf[0u] = i_pstUDSServiceInfo->SerNum + 0x40u;
        m_pstPDUMsg->aDataBuf[1u] = 0x20;
        m_pstPDUMsg->aDataBuf[2u] = (Recvdatalength >> 8) & 0xFF;
        m_pstPDUMsg->aDataBuf[3u] = (Recvdatalength >> 0) & 0xFF;
        m_pstPDUMsg->xDataLen = 4u;
		gs_ImageTransferStatus = TRUE;
        /*set wait received block number*/
        //gs_RxBlockNum++;
        gs_CalBlockNum = 1u;
		Uds_Image_Crc8 =0;
		Uds_Image_CheckSum = 0u;
    }
    
}
/*transfer data*/
static void Uds_TransferData(struct UDSServiceInfo* i_pstUDSServiceInfo, tUdsAppMsgInfo *m_pstPDUMsg)
{
	CHECK_RESTRICTION(NULL != m_pstPDUMsg);
    CHECK_RESTRICTION(NULL != i_pstUDSServiceInfo);
	uint8_t	Uds_App_ReadBackBuf[SERVICE_LOCAL_RECV_SIZE];	
	uint16_t Index;
	gs_RxBlockNum = m_pstPDUMsg->aDataBuf[1];
	if(gs_ImageTransferStatus)
	{
		if(gs_RxBlockNum != gs_CalBlockNum)
		{
			SetNegativeErroCode(i_pstUDSServiceInfo->SerNum, BNE, m_pstPDUMsg);
		}
		else
		{
			if(gs_stDowloadDataInfo.StartAddr>=ApplicationAddress)
			{
				if(m_pstPDUMsg->xDataLen > SERVICE_LOCAL_RECV_SIZE + 2)
				{
					SetNegativeErroCode(i_pstUDSServiceInfo->SerNum, IMLOIF, m_pstPDUMsg);
				}
				else
				{
					
				    if(NVM_Handle_DataWriteOperate(NVM_Handle_CodeFlashData,NVM_Handle_CodeFlash_NErase_8BytesWrite,gs_stDowloadDataInfo.StartAddr+gs_stDowloadDataInfo.DataWrite_Size,&(m_pstPDUMsg->aDataBuf[2]), m_pstPDUMsg->xDataLen-2)==TRUE)
				    {
				    	INT_All_Enable(DISABLE);
				    	if(NVM_Handle_DataReadOperate(NVM_Handle_CodeFlashData,gs_stDowloadDataInfo.StartAddr+gs_stDowloadDataInfo.DataWrite_Size,Uds_App_ReadBackBuf, m_pstPDUMsg->xDataLen-2)==TRUE)      
						{
							for(Index=0; Index<SERVICE_LOCAL_RECV_SIZE; Index++)
							{
								Uds_Image_CheckSum +=( (Uds_App_ReadBackBuf[Index]) & 0xFF);
							}
						}
			            Uds_Image_Crc8 = CommCrcCal_crc8((uint8_t*)Uds_App_ReadBackBuf, SERVICE_LOCAL_RECV_SIZE, Uds_Image_Crc8);
						INT_All_Enable(ENABLE);
				    	gs_stDowloadDataInfo.DataWrite_Size += (m_pstPDUMsg->xDataLen-2);
						gs_CalBlockNum++;
				        //gs_RxBlockNum = m_pstPDUMsg->aDataBuf[1];
				        m_pstPDUMsg->aDataBuf[0u] = i_pstUDSServiceInfo->SerNum + 0x40u;
				        m_pstPDUMsg->aDataBuf[1u] = gs_RxBlockNum;
				        m_pstPDUMsg->xDataLen = 2u;
				    }
				     else
				    {
				        SetNegativeErroCode(i_pstUDSServiceInfo->SerNum, CNC, m_pstPDUMsg);
				    }
				}
			}
			else
			{
				SetNegativeErroCode(i_pstUDSServiceInfo->SerNum, NEGTIVEPE, m_pstPDUMsg);
			}
		}
	}
    else
   	{
		SetNegativeErroCode(i_pstUDSServiceInfo->SerNum, CNC, m_pstPDUMsg);
	}
}
/*request transfer exit*/
static void Uds_RequestTransferExit(struct UDSServiceInfo* i_pstUDSServiceInfo, tUdsAppMsgInfo *m_pstPDUMsg)
{
	CHECK_RESTRICTION(NULL != m_pstPDUMsg);
    CHECK_RESTRICTION(NULL != i_pstUDSServiceInfo);
    m_pstPDUMsg->aDataBuf[0u] = i_pstUDSServiceInfo->SerNum + 0x40u;
	gs_ImageTransferStatus =FALSE;
    m_pstPDUMsg->xDataLen = 1u;
}

/*write data by identifier*/
static void Uds_WriteDataByIdentifier(struct UDSServiceInfo* i_pstUDSServiceInfo, tUdsAppMsgInfo *m_pstPDUMsg)
{

}



uint8_t Uds_FlashChecksumInspect(uint32_t addr ,uint32_t len ,uint32_t value)
{
	uint8_t ReadBackBuff[4];
	uint8_t RetVal = FALSE;
	uint32_t ReadBackChecksum =0u;
	if(NVM_Handle_DataReadOperate(NVM_Handle_CodeFlashChecksum,addr,ReadBackBuff,len))
	{
		ReadBackChecksum = ((uint32_t)(ReadBackBuff[3])<<24)|((uint32_t)(ReadBackBuff[2])<<16)|((uint32_t)(ReadBackBuff[1])<<8)|((uint32_t)(ReadBackBuff[0])<<0);
		if(ReadBackChecksum == value)
		{
			RetVal = TRUE;
		}
	}
	return RetVal;
}

/*routine control*/
static void Uds_RoutineControl(struct UDSServiceInfo* i_pstUDSServiceInfo, tUdsAppMsgInfo *m_pstPDUMsg)
{
	uint8_t addr_ByteSize =0u;
	uint8_t Length_ByteSize =0u;
	
	uint8_t i=0u;
	CHECK_RESTRICTION(NULL != m_pstPDUMsg);
    CHECK_RESTRICTION(NULL != i_pstUDSServiceInfo);

    RestartS3Server();

    /*Is erase memory routine control?*/
    if(TRUE == IsEraseMemoryRoutineControl(m_pstPDUMsg))
    {
        /*request client timeout time*/
        
    	addr_ByteSize =((m_pstPDUMsg->aDataBuf[4]>>0 )&0x0F);
	    Length_ByteSize =((m_pstPDUMsg->aDataBuf[4]>>4 )&0x0F);
		for(i=0;i<addr_ByteSize;i++)
		{
			app_Eraseaddr |= m_pstPDUMsg->aDataBuf[5+i]<<(8*(addr_ByteSize-1-i));
		}
		for(i=0;i<Length_ByteSize;i++)
		{
			app_EraseLength |= m_pstPDUMsg->aDataBuf[5+i+addr_ByteSize]<<(8*(Length_ByteSize-1-i));
		}
		if ((ApplicationAddress<= app_Eraseaddr)  &&
					(app_Eraseaddr <= (ApplicationAddress+APP_SIZE-FLASH_ONE_SECTOR_SIZE)) &&
					((app_Eraseaddr + app_EraseLength) <= (ApplicationAddress+APP_SIZE)))
		{
			m_pstPDUMsg->aDataBuf[0] = i_pstUDSServiceInfo->SerNum + 0x40u; 
            m_pstPDUMsg->aDataBuf[4] = ((Wait_EarseMemory_TimeTick_mS>>8)&0xFF);
			m_pstPDUMsg->aDataBuf[5] = ((Wait_EarseMemory_TimeTick_mS)&0xFF);
            m_pstPDUMsg->xDataLen = 6;
		}
		else
		{
			SetNegativeErroCode(i_pstUDSServiceInfo->SerNum, IMLOIF, m_pstPDUMsg);
		}
		
        
    }
    /*Is check sum routine control?*/
    else if(TRUE == IsCheckSumRoutineControl(m_pstPDUMsg))
    {
        
        if(m_pstPDUMsg->xDataLen != 9)
       	{
			SetNegativeErroCode(i_pstUDSServiceInfo->SerNum, IMLOIF, m_pstPDUMsg);
		}
		else
		{
			Memory_CheckSum = ((uint32_t)(m_pstPDUMsg->aDataBuf[4])<<24)|((uint32_t)(m_pstPDUMsg->aDataBuf[5])<<16)|((uint32_t)(m_pstPDUMsg->aDataBuf[6])<<8)|((uint32_t)(m_pstPDUMsg->aDataBuf[7])<<0);
			Memory_Crc8 = m_pstPDUMsg->aDataBuf[8];
			m_pstPDUMsg->aDataBuf[0] = i_pstUDSServiceInfo->SerNum + 0x40u; 
            m_pstPDUMsg->aDataBuf[4] = ((Wait_CheckMemory_TimeTick_mS>>8)&0xFF);
			m_pstPDUMsg->aDataBuf[5] = ((Wait_CheckMemory_TimeTick_mS)&0xFF);
            m_pstPDUMsg->xDataLen = 6;
		}
        
        
        
        /*request client timeout time*/
        //SetNegativeErroCode(i_pstUDSServiceInfo->SerNum, RCRRP, m_pstPDUMsg);

        //m_pstPDUMsg->pfUDSTxMsgServiceCallBack = &DoCheckSum;
    }
	else if(TRUE == IsStopRoutineControl(m_pstPDUMsg))
	{
		Request_App_Erase_Flag = FALSE;
		Request_App_CheckMemory_Result = FALSE;
		Request_App_Erase_Result	 = FALSE;
		Request_App_CheckMemory_Flag = FALSE;
	}
	else if(TRUE == IsEraseMemoryRoutineResult(m_pstPDUMsg))
	{
		Request_App_Erase_Flag = FALSE;
		if(Request_App_Erase_Result)
		{
			m_pstPDUMsg->aDataBuf[0] = i_pstUDSServiceInfo->SerNum + 0x40u;
			m_pstPDUMsg->xDataLen = 4;
		}
		else
        {
            SetNegativeErroCode(i_pstUDSServiceInfo->SerNum, CNC, m_pstPDUMsg);
        }
	}
	else if(TRUE == IsCheckSumRoutineResult(m_pstPDUMsg))
	{
		Request_App_CheckMemory_Flag = FALSE;
		if(Request_App_CheckMemory_Result)
		{
			m_pstPDUMsg->aDataBuf[0] = i_pstUDSServiceInfo->SerNum + 0x40u;
			m_pstPDUMsg->xDataLen = 4;
		}
		else
        {
            SetNegativeErroCode(i_pstUDSServiceInfo->SerNum, NEGTIVEPE, m_pstPDUMsg);
        }
	}
    else
    {
        /*don't have this routine control ID*/
        SetNegativeErroCode(i_pstUDSServiceInfo->SerNum, SFNS, m_pstPDUMsg);
    }

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
	CHECK_RESTRICTION(NULL != m_pstPDUMsg);
    CHECK_RESTRICTION(NULL != i_pstUDSServiceInfo);

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

    CHECK_RESTRICTION(NULL != m_pstPDUMsg);
    CHECK_RESTRICTION(NULL != i_pstUDSServiceInfo);

    RequestSubfunction = m_pstPDUMsg->aDataBuf[1u];
    
 
    /*set send postive message*/
    m_pstPDUMsg->aDataBuf[0u] = i_pstUDSServiceInfo->SerNum + 0x40u;
    m_pstPDUMsg->aDataBuf[1u] = RequestSubfunction;
    m_pstPDUMsg->xDataLen = 2u;
   

    /*sub function*/
//    switch(RequestSubfunction)
}

/**********************UDS service correlation other function realizing************************/
/* get uds service config information */
tUDSService* GetUDSServiceInfo(uint8_t *m_pSupServItem)
{
	CHECK_RESTRICTION(NULL != m_pSupServItem);
    
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

void UDS_AppEraseAndCheckFunAdjust(void)
{
	#if 0
	uint32_t Package;
	uint32_t PackageNum;
	uint16_t Index;
	uint8_t	Uds_App_ReadBackBuf[SERVICE_LOCAL_RECV_SIZE];				// 接收数据缓存	
	#endif
	if(Request_App_Erase_Flag)
	{
		INT_All_Enable(DISABLE);//关闭所有中断
		//默认执行单次全擦，每次写入擦除暂未实现
		if((NVM_Handle_DataEraseOperate(NVM_Handle_CodeFlashData,app_Eraseaddr)==TRUE)&&(NVM_Handle_RunAreaSet(NVM_Handle_Run_At_Boot)==TRUE))
		{
			Request_App_Erase_Result = TRUE;
		}
		else
		{
			Request_App_Erase_Result = FALSE;
		}
		INT_All_Enable(ENABLE);//开启所有中断
		Request_App_Erase_Flag =  FALSE;
	}
	#if 0
	Uds_Image_CheckSum = 0u;
	Uds_Image_Crc8 = 0u;
	#endif
	if(Request_App_CheckMemory_Flag)
	{


		#if 0
		INT_All_Enable(DISABLE);
		PackageNum = gs_stDowloadDataInfo.DataLen/SERVICE_LOCAL_RECV_SIZE;
		
        for(Package=0; Package<PackageNum; Package++)
        {
			WatchDogIf_Free();
			if(NVM_Handle_DataReadOperate(NVM_Handle_CodeFlashData,(gs_stDowloadDataInfo.StartAddr + (Package * SERVICE_LOCAL_RECV_SIZE)),Uds_App_ReadBackBuf, READBACK_PACKAGE_SIZE_BYTE)==TRUE)      
			{
				for(Index=0; Index<SERVICE_LOCAL_RECV_SIZE; Index++)
				{
					Uds_Image_CheckSum +=( (Uds_App_ReadBackBuf[Index]) & 0xFF);
				}
			}
            Uds_Image_Crc8 = CommCrcCal_crc8((uint8_t*)Uds_App_ReadBackBuf, SERVICE_LOCAL_RECV_SIZE, Uds_Image_Crc8);
        }
		INT_All_Enable(ENABLE);
		#endif
		if((Memory_Crc8 == Uds_Image_Crc8)&&(Uds_Image_CheckSum == Memory_CheckSum))
		{
			if(NVM_Handle_RunAreaSet(NVM_Handle_Run_At_App)==TRUE)
			{
				Request_App_CheckMemory_Result = TRUE;
			}
			else
			{
				Request_App_CheckMemory_Result = FALSE;
			}
		}
        else
        {
            Request_App_CheckMemory_Result = FALSE;
        }
		Request_App_CheckMemory_Flag = FALSE;
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
    tUdsAppMsgInfo stUdsAppMsg = {0u, 0u, 0u, 0u, {0u}, NULL};
    UDS_AppEraseAndCheckFunAdjust();
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
#endif
