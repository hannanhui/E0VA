
#ifndef __LIN_SCHEDULE_H__
#define __LIN_SCHEDULE_H__
#define LIN_TX_TIMEOUT   T1_10MS
#define LIN_RX_TIMEOUT   T1_10MS

typedef enum
{
	MsgIndex00 = 0, /*0x00*/
	MsgIndex01,	    /*0x01*/
	NumberOfObjects, /*?????*/
}MsgIndex;

typedef enum
{
	LinTx = 0,
	LinTxOkWait,
	LinTxOk,
	LinTxTimeOut,
	LinRxOkWait,
	LinRxOk,
	LinRxTimeOut,
}LinTransEnum;

typedef struct
{
	LinTransEnum TransSts;
	uint8_t TxTimeOut;
	uint8_t RxTimeOut;
	uint8_t Index;
}LinTransStruct;

typedef union
{
    uint8_t data[8];
    struct
    {
        //Byte[0]
        uint8_t MasStep1;
				uint8_t MasStep2;
			uint8_t MasStep3;
			uint8_t MasStep4;
			uint8_t MasStep5;
			uint8_t MasStep6;
			uint8_t MasStep7;
			uint8_t MasStep8;
			
		
    }bits;
}MasTxSts;

typedef union
{
    uint8 data[8];
    struct
    {
        //Byte[0]
        uint8_t MasStep1;
				uint8_t MasStep2;
			uint8_t MasStep3;
			uint8_t MasStep4;
			uint8_t MasStep5;
			uint8_t MasStep6;
			uint8_t MasStep7;
			uint8_t MasStep8;
    }bits;
}MasRxSts;

extern MasTxSts MsgTx00;
extern MasRxSts MsgRx01;


extern void LinMasterInit(void);
extern void LinMasterTask(void);

#endif /* __LIN_SCHEDULE_H__ */














