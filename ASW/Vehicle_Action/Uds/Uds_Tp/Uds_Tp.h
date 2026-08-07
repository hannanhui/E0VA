/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      Uds_Tp.h                                                                 */
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
#ifndef INCLUDE_UDS_TP_H_
#define INCLUDE_UDS_TP_H_

#define LIN_DIAG_MASTER_REQUEST_ID   0X3C
#define LIN_DIAG_SLAVER_RESPOND_ID   0X3D

#define	LIN_NAD_SLEEP				 0x00	// Sleep Instruction


#define LIN_DEF_NAD             0x8C        /*default NAD*/

#define LIN_FUNC_ID    		0x7e		/*FUNCTION ID*/
#define MAX_DATA_LEN (150u)


typedef uint16_t tNetTime;
typedef uint32_t tUdsId;
typedef uint32_t tUdsLen;
typedef uint16_t tBlockSize;

typedef uint16_t tLinTpDataLen;
typedef uint8_t (*tNetTxMsg)(const tUdsId, const uint16_t, const uint8_t *, const uint32_t);
typedef uint8_t (*tNetRx)(tUdsId *, tUdsLen *, uint8_t *);



/*********************************************************
**	SF	-- 	signle frame
**	FF	--	first frame
**	CF	--	consective frame
*********************************************************/

typedef enum
{
	IDLE,      /*idle*/
	RX_SF,   /*wait signle frame*/
	RX_FF,   /*wait first frame*/
	RX_CF,   /*wait consective frame*/

	TX_SF,     /*tx signle frame*/
	TX_FF,     /*tx first frame*/
	TX_CF,     /*tx consective frame*/

	WAITTING_TX, /*watting tx message*/

	WAIT_CONFIRM /*wait confrim*/
}tLinTpWorkStatus;

typedef enum
{
	SF=0,        /*signle frame value*/
	FF=1,        /*first frame value*/
	CF=2,        /*consective frame value*/
}tNetWorkFrameType;

typedef struct
{
	uint8_t ucCalledPeriod;      /*called CAN tp main function period*/
	tUdsId master_request_id;    /*master request id*/
    tUdsId slaver_respond_id;    /*slaver respond id*/
    tUdsId lin_nad;              /*lin_nad*/
	tBlockSize xBlockSize;       /*BS*/
	tNetTime xSTmin;             /*STmin*/
	tNetTime xNAs;               /*N_As*/
	tNetTime xNAr;               /*N_Ar*/
	tNetTime xNBs;               /*N_Bs*/
	tNetTime xNBr;               /*N_Br*/
	tNetTime xNCs;               /*N_Cs*/
	tNetTime xNCr;               /*N_Cr*/
	uint32_t txBlockingMaxTimeMs;/*TX message blocking max time (MS)*/
	tNetTxMsg pfNetTxMsg;        /*net tx message with non blocking*/
	tNetRx pfNetRx;              /*net rx*/
}tUdsLINNetLayerCfg;

typedef struct
{
	tUdsId xLinTpId;                        /*lin tp message id*/
	tLinTpDataLen xPduDataLen;              /*pdu data len(Rx/Tx data len)*/
	tLinTpDataLen xFFDataLen;               /*Rx/Tx FF data len*/
	tLinTpDataLen xFFDataIndex;               /*Rx/Tx FF data Rx/Tx Index*/
	uint8_t aDataBuf[MAX_DATA_LEN];         /*Rx/Tx data buf*/
}tLinTpDataInfo;

typedef struct
{
	uint8_t ucSN;          /*SN*/
	uint8_t ucBlockSize;   /*Block size*/
	tNetTime xSTmin;             /*STmin*/
	tNetTime xMaxWatiTimeout;    /*timeout time*/
	tLinTpDataInfo stLinTpDataInfo;
}tLinTpInfo;
extern const tUdsLINNetLayerCfg g_stLINUdsNetLayerCfgInfo;

extern void LINTP_DEVICE_NAD_Set(uint8_t opNad);
extern BOOL IsRxMsgReally(void);
extern void ClearRxMsgReadlly(void);
extern void SetRxMsgReadlly(void);
extern BOOL IsTxMsgReally(void);
extern void ClearTxMsgReadlly(void);
extern void SetTxMsgReadlly(void);
extern uint8_t LINTP_TxMsg(const tUdsId i_xTxId, const uint16_t i_DataLen, const uint8_t* i_pDataBuf, const uint32_t txBlockingMaxtime);
extern uint8_t LINTP_RxMsg(tUdsId * o_pxRxId, tUdsLen * o_pRxDataLen, uint8_t *o_pRxBuf);

extern void UDS_Tp_Init(void);

#endif /* INCLUDE_UDS_TP_H_ */
