
#include "include.h"

#include "LinIf.h"
//#include "Lin.h"

extern Std_ReturnType Lin_SendFrame(uint8 Channel, const Lin_PduType *PduInfoPtr);
extern Lin_StatusType Lin_GetStatus(uint8 Channel, uint8 **Lin_SduPtr);
LinTransStruct LinMaster;
MasTxSts MsgTx00;
MasRxSts MsgRx01;

const Lin_PduType LinMasterFrameTbl[NumberOfObjects] =
{
    {0x80U, LIN_ENHANCED_CS, LIN_FRAMERESPONSE_TX, 8U, &MsgTx00.data[0]},
    {0xC1U, LIN_ENHANCED_CS, LIN_FRAMERESPONSE_RX, 8U, &MsgRx01.data[0]},
};

void LinMasterInit(void)
{
	LinMaster.TransSts = LinTx;
	LinMaster.TxTimeOut = 0;
    LinMaster.RxTimeOut = 0;
	for(uint8_t i=0;i<8;i++)
	{
		MsgTx00.data[i] = i;
	}
}

void LinMasterTask(void)
{
	uint8 Cnt = 0;
	static uint8 LinSduPtrTemp[8] = {0};
	static uint8* LinSduPtr = LinSduPtrTemp;
	Lin_StatusType RetVal = LIN_NOT_OK;

	switch(LinMaster.TransSts)
	{
		case LinTx:
			LinMaster.TxTimeOut = 0;
			LinMaster.RxTimeOut = 0;
			RetVal = Lin_SendFrame(0, &LinMasterFrameTbl[LinMaster.Index]);

			if(LinMasterFrameTbl[LinMaster.Index].Drc == LIN_FRAMERESPONSE_TX)
			{
				LinMaster.TransSts = LinTxOkWait;
			}

			if(LinMasterFrameTbl[LinMaster.Index].Drc == LIN_FRAMERESPONSE_RX)
			{
				LinMaster.TransSts = LinRxOkWait;
			}
			break;
		
		case LinTxOkWait:
			RetVal = Lin_GetStatus(0, &LinSduPtr);

			if(RetVal == LIN_TX_OK)
			{
				LinMaster.TransSts = LinTxOk;
			}
			else 
			{
				LinMaster.TxTimeOut++;
			}

			if(LinMaster.TxTimeOut >= LIN_TX_TIMEOUT)
			{
				LinMaster.TransSts = LinTxTimeOut;
			}
			break;
			
		case LinRxOkWait:
			RetVal = Lin_GetStatus(0, &LinSduPtr);

			if(RetVal == LIN_RX_OK)
			{
				for(Cnt = 0; Cnt < LinMasterFrameTbl[LinMaster.Index].Dl; Cnt++)
	            {
	            	LinMasterFrameTbl[LinMaster.Index].SduPtr[Cnt] = *LinSduPtr;
	            	LinSduPtr++;
	            }
				LinMaster.TransSts = LinRxOk;
			}
			else
			{
				LinMaster.RxTimeOut++;
			}

			if(LinMaster.RxTimeOut >= LIN_RX_TIMEOUT)
			{
				LinMaster.TransSts = LinRxTimeOut;
			}
			break;
			
		case LinTxOk:
		case LinRxOk:
		case LinTxTimeOut:
		case LinRxTimeOut:
			LinMaster.TransSts = LinTx;
			LinMaster.Index++;
			if(LinMaster.Index >= NumberOfObjects)
			{
				LinMaster.Index = 0;
			}
			break;
		
		default:
			LinMaster.TransSts = LinTx;
			break;
	}
}

