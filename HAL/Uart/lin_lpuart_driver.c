/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      lin_lpuart_driver.c                                                      */
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
/*
 * Copyright (c) 2015 - 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2018 NXP
 * All rights reserved.
 *
 * THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

/*!
 * @file lin_lpuart_driver.c
 *
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Required Rule 1.3, Taking address of near auto variable.
 * The code is not dynamically linked. An absolute stack address is obtained
 * when taking the address of the near auto variable. A source of error in
 * writing dynamic code is that the stack segment may be different from the data
 * segment.
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 8.7, External could be made static.
 * Function is defined for usage by application code.
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 8.9, Could define variables 'g_linLpuartIsrs',
 * 'g_linLpuartErrIsrs' at block scope.
 * These variables are used all over lin_lpuart driver so they must remain global.
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 11.4, Conversion between a pointer and
 * integer type.
 * The cast is required to initialize a pointer with an unsigned int define,
 * representing an address.
 *
 * @section [global]
 * Violates MISRA 2012 Required Rule 11.6, Cast from pointer to unsigned int.
 * The cast is required to initialize a pointer with an unsigned int define,
 * representing an address.
 */

/* *****************************************************************************
 * Includes
 ******************************************************************************/
#include "lin_lpuart_driver.h"
#include <string.h>
#include "LinIf_Cbk.h"
/* *****************************************************************************
 * Variables
 ******************************************************************************/

uint8_t RxReadBackFrameData[9] ={0};
uint8_t LinBackupSendFrameData[8] ={0};

static uint8_t BreakCharDetectLength = 11;

volatile uint32_t g_Break_section_width = 0UL;										

/* Table to save LPUART state structure pointers */
lin_state_t * g_linStatePtr[LPUART_INSTANCE_COUNT] = {NULL};

/* Table to save LIN user config structure pointers */
lin_user_config_t * g_linUserconfigPtr[LPUART_INSTANCE_COUNT] = {NULL};


/*configure uart Fifo parameter */
static UART_FIFOConfig_t  g_uartFifoCfg = 
{
    .fifoEnable = ENABLE,
    .txFifoReset = DISABLE,
    .rxFifoReset = ENABLE,
    .fifoTet     = UART_TX_FIFO_EMPTY,
    .fifoRt      = UART_RX_FIFO_CHAR_1
};



/* *****************************************************************************
 * Static variables
 ******************************************************************************/

//static uint8_t s_wakeupSignal[LPUART_INSTANCE_COUNT] = {0U};


/* *****************************************************************************
 * Static function prototypes
 ******************************************************************************/


static void LIN_LPUART_DRV_ProcessBreakDetect(uint32_t instance);


static void LIN_LPUART_DRV_ProcessFrame(uint32_t instance,
                                        uint8_t tmpByte);

static void LIN_LPUART_DRV_ProcessFrameHeader(uint32_t instance,
                                              uint8_t tmpByte);

static void LIN_LPUART_DRV_ProcessReceiveFrameData(uint32_t instance,
                                                   uint8_t tmpByte);

static void LIN_LPUART_DRV_ProcessSendFrameData(uint32_t instance);



static uint8_t LIN_LPUART_DRV_MakeChecksumByte(uint32_t instance,
                                               const uint8_t * buffer,
                                               uint8_t sizeBuffer,
                                               uint8_t PID);
static void LPUART_SetBreakCharDetectLength(lpuart_break_char_length_t length);

static void LIN_LPUART_DRV_ProcessReadBackFrameData(uint32_t instance,
                                                uint8_t tmpByte);
/*******************************************************************************
*
*������          ��System_Usart_Calculate_Brgr_Val
*��������      ������USART�Ĳ���������
*��������      ��BaudRate - Ҫ���õĲ�����
*��������      ��PeripheraClockFreq - ����ʱ��Ƶ��
*��������ֵ  ��Brgm  - ��������������
*��������ֵ  ��Brgf1 - ������С�����Ӳ���
*��������ֵ  ��Brgf2 - ������С����ĸ����
*˵��	     ����
*
*******************************************************************************/
void LPUART_Calculate_Brgr_Val(uint32_t BaudRate, uint32_t PeripheraClockFreq, uint16_t* Brgm, uint8_t* Brgf1, uint8_t* Brgf2)
{
    // ������ = Fck/(16*BRGM*(1+BRGF1/BRGF2))
	// (16*BRGM*(1+BRGF1/BRGF2)) = Fck/BaudRate
	// BRGM*(1+BRGF1/BRGF2) = Fck/BaudRate/16
	// BRGM Ϊ�������������֣�BRGF1 ��BRGF2 ��ɲ����ʷ�������
	FP32   Temp;
	FP32   Err_Dec;			// ��ǰ��ĸֵ�������С�����
	FP32   Err_Dec_Min;		// �����С��������Сֵ
	uint8_t  Downstairs;		// С��������Сֵ�Ծ͵ķ�ĸֵ
	uint8_t  i;

	uint32_t TempBrgm  = 0;	// USART��������������"BRGM"��ȡֵΪ0~65535
	uint8_t  TempBrgf1 = 0; 	// USART������С�����Ӳ���"BRGF1"��ȡֵΪ0~0xF
	uint8_t  TempBrgf2 = 0;	// USART������С����ĸ����"BRGF2"��ȡֵΪ0~0xF

	Temp  = PeripheraClockFreq;
	Temp /= BaudRate;
	Temp /= 16;

	TempBrgm = 1;
	if(Temp/TempBrgm < 1)
	{
		CHECK_RESTRICTION(0);
	}

	while(1)
	{
		if(Temp/TempBrgm < 2)
		{
			if (Temp/(TempBrgm+1) < 1)
			{
				break;
			}
		}
		TempBrgm++;
	}

	if(TempBrgm > 65535)
	{
		CHECK_RESTRICTION(0);
	}

	Temp /= TempBrgm;
	Temp -= 1;			// С������

	if ((Temp < 0) || (Temp > 1))
	{
		CHECK_RESTRICTION(0);
	}

	if(Temp)
	{
		if (Temp >= 0.001)	// 1/15 > 1/1000
		{
			// ����С�������Сֵʱ�ķ�ĸֵ
			for(i=2; i<16; i++)
			{
				if (i==2)
				{
					Err_Dec_Min  = Temp*i;
					Err_Dec_Min -= (uint32_t)Err_Dec_Min;

					if (Err_Dec_Min > 0.5)
					{
						Err_Dec_Min  = 1 - Err_Dec_Min;
					}

					Downstairs  = i;
				}
				else
				{
					Err_Dec = Temp*i;
					Err_Dec -= (uint32_t)Err_Dec;
					if (Err_Dec > 0.5)
					{
						Err_Dec  = 1 - Err_Dec;
					}

					if (Err_Dec_Min > Err_Dec)
					{
						Err_Dec_Min = Err_Dec;
						Downstairs = i;
					}
				}
			}
		}
		else
		{
			Downstairs = 0;
		}

		// ���ݷ�ĸֵ���÷���ֵ
		if (Downstairs)
		{
			TempBrgf1 = Temp*Downstairs + (0.5/Downstairs);
		}

		// ���÷�ĸ��ֵ
		if (TempBrgf1)
		{
			TempBrgf2 = Downstairs;
		}
		else
		{
			TempBrgf2 = 1;
		}
	}

	if ((TempBrgf1 > 15) || (TempBrgf2 > 15))
	{
		CHECK_RESTRICTION(0);
	}

	*Brgm  = TempBrgm;
	*Brgf1 = TempBrgf1;
	*Brgf2 = TempBrgf2;
}

/* *****************************************************************************
 * Code
 ******************************************************************************/
/*FUNCTION**********************************************************************
 *
 * Function Name : LIN_LPUART_DRV_Init
 * Description   : This function initializes a LPUART instance for operation.
 * This function will initialize the run-time state structure to keep track of
 * the on-going transfers, initialize the module to user defined settings and
 * default settings, set break field length to be 13 bit times minimum, enable
 * the break detect interrupt, Rx complete interrupt, frame error detect interrupt,
 * and enable the LPUART module transmitter and receiver.
 *
 * Implements    : LIN_LPUART_DRV_Init_Activity
 *END**************************************************************************/
status_t LIN_LPUART_DRV_Init(uint32_t instance,
                             lin_user_config_t * linUserConfig,
                             lin_state_t * linCurrentState)
{


    status_t retVal = STATUS_UNSUPPORTED;
	int8_t UartInitFlag = SCI_SUCCESS;
	/* Get base address of the LPUART instance. */
	uint16_t Brgm  = 0;	// USART��������������z��ȡֵΪ0~65535
	uint8_t  Brgf1 = 0; 	// USART������С�����Ӳ���x��ȡֵΪ0~0xF
	uint8_t  Brgf2 = 0;	// USART������С����ĸ����y��ȡֵΪ0~0xF

	//CLK_Module_t clk[] = {CLK_UART0,CLK_UART1,CLK_UART2,CLK_UART3};
    //IRQn_Type uartIRQ[] = {UART0_IRQn, UART1_IRQn, UART2_IRQn, UART3_IRQn};
    CLK_Module_t uartClkId = CLK_LIN_ID;
    uint32_t clkFreq = 0U;
    
    UART_LinConfig_t linConfig;
    
    /* Save runtime structure pointer. */
    g_linStatePtr[instance] = linCurrentState;

    /* Save LIN user config structure pointer. */
    g_linUserconfigPtr[instance] = linUserConfig;
	
	clkFreq = CLK_GetModuleClkFreq(uartClkId, 8000000);
    
    /* Clear linSourceClockFreq value */
    linCurrentState->linSourceClockFreq = clkFreq;
	
	LPUART_DRV_BREAK_Init();
    linConfig.baudRate = linUserConfig->baudRate;
    linConfig.oscFreq = 8000000;
    linConfig.mode = linUserConfig->nodeFunction;
    linConfig.autoSyncEn = linUserConfig->autobaudEnable;
    /* Boot only needs diagnostic MRF/SRF; filter out vehicle application IDs in HW. */
    linConfig.idFilterEn = ENABLE;
        
    SYSCTRL_ResetModule(SYSCTRL_LIN_ID);
    SYSCTRL_EnableModule(SYSCTRL_LIN_ID);
    
    while(ERR == UART_WaitBusyClear(LIN_ID, 7000))
    {
        UART_ReceiveByte(LIN_ID);
    }
    
    UART_LinConfig(LIN_ID, &linConfig);
    UART_FIFOConfig(LIN_ID, &g_uartFifoCfg);
    (void)UART_LinEnableIdFilter(LIN_ID, 0U, 0x3CU);
    (void)UART_LinEnableIdFilter(LIN_ID, 1U, 0x3DU);
    UART_LinDisableVagueIdFilter(LIN_ID);
  
    UART_IntMask(LIN_ID, UART_INT_RBFI ,UNMASK);
    UART_IntMask(LIN_ID, UART_INT_LSI, UNMASK);
        
    /* enable IRQ*/
    INT_EnableIRQ(LIN_IRQ_NUM);
    INT_SetPriority(LIN_IRQ_NUM,0x00);

	//UART0_Handler();
	LPUART_SetIntMode(LPUART_LIN_BREAK_DETECT, false);
	
	LIN_LPUART_DRV_GotoIdleState(instance);
    /* Change node's current state to IDLE */
    linCurrentState->currentNodeState = LIN_NODE_STATE_IDLE;

    /* Clear flags in current LIN state structure */
    linCurrentState->isTxBusy = false;
    linCurrentState->isRxBusy = false;
    linCurrentState->isBusBusy = false;
    linCurrentState->isRxBlocking = false;
    linCurrentState->isTxBlocking = false;
    linCurrentState->timeoutCounterFlag = false;
    linCurrentState->timeoutCounter = 0U;
	retVal = STATUS_SUCCESS;

    

    

     

    return retVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LIN_LPUART_DRV_Deinit
 * Description   : This function shuts down the LPUART by disabling interrupts and
 *                 transmitter/receiver.
 *
 * Implements    : LIN_LPUART_DRV_Deinit_Activity
 *END**************************************************************************/
void LIN_LPUART_DRV_Deinit(uint32_t instance)
{
    /* Get the current LIN state of this LPUART instance. */
    lin_state_t * linCurrentState = g_linStatePtr[instance];
	/* Check if current instance is already de-initialized or is gated.*/
   // DEV_ASSERT(linCurrentState != NULL);

	INT_DisableIRQ(LIN_IRQ_NUM);
	 /* Disable RX  interrupt */
	(void)LPUART_ClearStatusFlag(LPUART_LIN_RX_DETECT);
    LPUART_SetIntMode( LPUART_LIN_RX_DETECT, false);

    /* Disable TX interrupt */
	(void)LPUART_ClearStatusFlag(LPUART_LIN_TX_DETECT);
    LPUART_SetIntMode(LPUART_LIN_TX_DETECT, false);

    /* Disable frame error interrupt */
	(void)LPUART_ClearStatusFlag(LPUART_LIN_ERR_DETECT);
    LPUART_SetIntMode(LPUART_LIN_ERR_DETECT, false);

    /* Disable LIN break detect interrupt */ 
	(void)LPUART_ClearStatusFlag(LPUART_LIN_BREAK_DETECT);
	LPUART_SetIntMode(LPUART_LIN_BREAK_DETECT, false);
	
    /* Change node's current state to UNINIT */
    linCurrentState->currentNodeState = LIN_NODE_STATE_UNINIT;

    /* Clear our saved pointer to the LIN state structure */
    g_linStatePtr[instance] = NULL;
//	LPUART_DeInit();

}



/*FUNCTION**********************************************************************
 *
 * Function Name : LIN_LPUART_DRV_InstallCallback
 * Description   : This function installs the callback function that is used for LIN_LPUART_DRV_IRQHandler.
 * Pass in Null pointer as callback will uninstall.
 *
 * Implements    : LIN_LPUART_DRV_InstallCallback_Activity
 *END**************************************************************************/
lin_callback_t LIN_LPUART_DRV_InstallCallback(uint32_t instance,
                                              lin_callback_t function)
{

    /* Get the current LIN state of this LPUART instance. */
    lin_state_t * linCurrentState = g_linStatePtr[instance];

    /* Get the current callback function. */
    lin_callback_t currentCallback = linCurrentState->Callback;

    /* Install new callback function. */
    linCurrentState->Callback = function;

    return currentCallback;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LIN_LPUART_DRV_MakeChecksumByte
 * Description   : This function calculate checksum for a frame. This function
 * will return classic or enhanced checksum base on data in
 * g_linUserconfigPtr[instance] and input parameter.
 *
 * Implements    : LIN_LPUART_DRV_SendFrameDataBlocking_Activity
 *END**************************************************************************/
static uint8_t LIN_LPUART_DRV_MakeChecksumByte(uint32_t instance,
                                               const uint8_t * buffer,
                                               uint8_t sizeBuffer,
                                               uint8_t PID)
{
    /* Get list of PIDs use classic checksum. */
    const uint8_t *classicPID = g_linUserconfigPtr[instance]->classicPID;
    const uint8_t numOfClassicPID = g_linUserconfigPtr[instance]->numOfClassicPID;
    uint8_t checkSum = PID;
    uint8_t retVal = 0U;

    if(numOfClassicPID == 255U)
    {
        /*all frame use enhanced checksum */
        checkSum = 0U;
    }
    else
    {
        if(classicPID != NULL)
        {
            for (retVal = 0U; retVal < numOfClassicPID; retVal++)
            {
                if(checkSum == classicPID[retVal])
                {
                    checkSum = 0U;
                    break;
                }
            }
        }
    }
    retVal = LIN_DRV_MakeChecksumByte(buffer, sizeBuffer, checkSum);
    return retVal;
}
UART_LinResponse_t txInfo;

/*FUNCTION**********************************************************************
 *
 * Function Name : LIN_LPUART_DRV_SendFrameData
 * Description   : This function sends data out through the LPUART module using
 * non-blocking method. This function will calculate the checksum byte and send
 * it with the frame data. The function will return immediately after calling
 * this function. If txSize is equal to 0 or greater than 8  or node's current
 * state is in SLEEP mode then the function will return STATUS_ERROR. If
 * isBusBusy is currently true then the function will return STATUS_BUSY.
 *
 * Implements    : LIN_LPUART_DRV_SendFrameData_Activity
 *END**************************************************************************/
status_t LIN_LPUART_DRV_SendFrameData(uint32_t instance,
                                      const uint8_t * txBuff,
                                      uint8_t txSize)
{
    /* Assert parameters. */
    CHECK_RESTRICTION(txBuff != NULL);
    CHECK_RESTRICTION(instance < LPUART_INSTANCE_COUNT);

    status_t retVal = STATUS_SUCCESS;



    /* Get the current LIN state of this LPUART instance. */
    lin_state_t * linCurrentState = g_linStatePtr[instance];

    /* Check whether current mode is sleep mode */
    bool checkSleepMode = (LIN_NODE_STATE_SLEEP_MODE == linCurrentState->currentNodeState);
	ResultStatus_t status; 

    /* Check if txSize > 8 or equal to 0 or node's current state
     * is in SLEEP mode then return STATUS_ERROR */
    if ((8U < txSize) || (0U == txSize) || checkSleepMode)
    {
        retVal = STATUS_ERROR;
    }
    else
    {
        /* Check if the LIN Bus is busy */
        if (linCurrentState->isBusBusy)
        {
            retVal = STATUS_BUSY;
        }
        else
        {
            /* Make the checksum byte. */
            linCurrentState->checkSum = LIN_LPUART_DRV_MakeChecksumByte(instance, txBuff, txSize, linCurrentState->currentPid);

            /* Update the LIN state structure. */
            linCurrentState->txBuff = txBuff;
            /* Add a place for checksum byte */
            linCurrentState->txSize = (uint8_t)(txSize + 1U);
            linCurrentState->cntByte = 0U;
            linCurrentState->cntReadbackByte = 0U;
            linCurrentState->currentNodeState = LIN_NODE_STATE_SEND_DATA;
            linCurrentState->currentEventId = LIN_NO_EVENT;
            linCurrentState->isBusBusy = true;
            linCurrentState->isTxBusy = true;
			//(void)LPUART_ClearStatusFlag(LPUART_LIN_RX_DETECT);
		    //LPUART_SetIntMode( LPUART_LIN_RX_DETECT, false);
            /* Set Break char detect length as 10 bits minimum */
            LPUART_SetBreakCharDetectLength(LPUART_BREAK_CHAR_11_BIT_MINIMUM);
			for(uint8_t i=0;i<9;i++)
			{
				RxReadBackFrameData[i] =0u;
			}
			for(uint8_t i=0;i<txSize;i++)
			{
				LinBackupSendFrameData[i] =txBuff[i];
			}
            /* Start sending data */
			
			txInfo.checkType = UART_LIN_CHECKSUM_CLASSIC;		// D��?��o��?????aCLASSIC
			txInfo.len = txSize; 

			memcpy(txInfo.data, LinBackupSendFrameData,txSize); // ��?Send_Data_Buff.Data?��????��?txInfo.data
			//LPUART_Putchar(*linCurrentState->txBuff);

			/* stop all transmission */
            UART_LinStopTransmission(LIN_ID);
            /* Send response */
            status = UART_LinSendResponse(LIN_ID, &txInfo);     // ��?��|��?�̡�uart_drv?y?�����騺y?Y ��?����?��txInfo.data      
            if(status == ERR)
            {
                linCurrentState->isBusBusy = false;
                linCurrentState->isTxBusy = false;
							 
            }
						else
						{
							
						}
        }
    }

    return retVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LIN_LPUART_DRV_GetTransmitStatus
 * Description   : This function returns whether the previous LPUART transmit has
 * finished. When performing non-blocking transmit, the user can call this
 * function to ascertain the state of the current transmission:
 * in progress (or busy that is STATUS_BUSY) or timeout (if timeout has occurred that is
 * STATUS_TIMEOUT) or complete (success that is STATUS_SUCCESS).
 * In addition, if the transmission is still in progress, the user can obtain the number
 * of bytes that still needed to transmit.
 *
 * Implements    : LIN_LPUART_DRV_GetTransmitStatus_Activity
 *END**************************************************************************/
status_t LIN_LPUART_DRV_GetTransmitStatus(uint32_t instance,
                                          uint8_t * bytesRemaining)
{
    /* Assert parameters. */
    CHECK_RESTRICTION(instance < LPUART_INSTANCE_COUNT);

    status_t retVal = STATUS_SUCCESS;

    /* Get the current LIN state of this LPUART instance. */
    const lin_state_t * linCurrentState = g_linStatePtr[instance];

    /* Get the number of bytes that is still needed to transmit */
    *bytesRemaining = (uint8_t)(linCurrentState->txSize - linCurrentState->cntByte);

    /* Return status of the on-going transmission */
    if ((linCurrentState->currentEventId == LIN_NO_EVENT) && (*bytesRemaining != 0U))
    {
        if (linCurrentState->timeoutCounterFlag == false)
        {
            retVal = STATUS_BUSY;
        }
        else
        {
            retVal = STATUS_TIMEOUT;
        }
    }

    return retVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LIN_LPUART_DRV_RecvFrmData
 * Description   : This function receives data from LPUART module using
 * non-blocking method. This function returns immediately after initiating the
 * receive function. The application has to get the receive status to see when
 * the receive is complete. In other words, after calling non-blocking get
 * function, the application must get the receive status to check if receive
 * is completed or not. The interrupt handler LIN_LPUART_DRV_IRQHandler will check
 * the checksum byte. If the checksum is correct, it will receive the frame data.
 * If the checksum is incorrect, this function will return STATUS_TIMEOUT and data in
 * rxBuff might be wrong. This function also check if rxSize is in range from 1 to 8.
 * If not, it will return STATUS_ERROR. This function also returns STATUS_ERROR if
 * node's current state is in SLEEP mode. This function checks if the
 * isBusBusy is false, if not it will return STATUS_BUSY.
 *
 * Implements    : LIN_LPUART_DRV_RecvFrmData_Activity
 *END**************************************************************************/
status_t LIN_LPUART_DRV_RecvFrmData(uint32_t instance,
                                    uint8_t * rxBuff,
                                    uint8_t rxSize)
{
    /* Assert parameters. */
    CHECK_RESTRICTION(rxBuff != NULL);
    CHECK_RESTRICTION(instance < LPUART_INSTANCE_COUNT);

    status_t retVal = STATUS_SUCCESS;



    /* Get the current LIN state of this LPUART instance. */
    lin_state_t * linCurrentState = g_linStatePtr[instance];

    /* Check whether current mode is sleep mode */
    bool checkSleepMode = (LIN_NODE_STATE_SLEEP_MODE == linCurrentState->currentNodeState);

    /* Check if rxSize > 8 or equal to 0 or node's current state
     * is in SLEEP mode then return STATUS_ERROR */
    if ((8U < rxSize) || (0U == rxSize) || checkSleepMode)
    {
        retVal = STATUS_ERROR;
    }
    else
    {
        /* Check if the LIN Bus is busy */
        if (linCurrentState->isBusBusy)
        {
            retVal = STATUS_BUSY;
        }
        else
        {
            /* Update the LIN state structure. */
            linCurrentState->rxBuff = rxBuff;
            /* Add a place for checksum byte */
            linCurrentState->rxSize = (uint8_t)(rxSize + 1U);
            linCurrentState->cntByte = 0U;
			linCurrentState->cntReadbackByte = 0U;
            /* Start receiving data */
            linCurrentState->currentNodeState = LIN_NODE_STATE_RECV_DATA;
            linCurrentState->currentEventId = LIN_NO_EVENT;
            linCurrentState->isBusBusy = true;
            linCurrentState->isRxBusy = true;
            linCurrentState->isRxBlocking = false;

            LPUART_SetBreakCharDetectLength(LPUART_BREAK_CHAR_11_BIT_MINIMUM);
        }
    }

    return retVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LPUART_DRV_AbortTransferData
 * Description   : Aborts an on-going non-blocking transmission/reception.
 * While performing a non-blocking transferring data, users can call this
 * function to terminate immediately the transferring.
 *
 * Implements    : LIN_LPUART_DRV_AbortTransferData_Activity
 *END**************************************************************************/
status_t LIN_LPUART_DRV_AbortTransferData(uint32_t instance)
{
    /* Assert parameters. */
    CHECK_RESTRICTION(instance < LPUART_INSTANCE_COUNT);

    status_t retVal = STATUS_SUCCESS;

    /* Get the current LIN state of this LPUART instance. */
    lin_state_t * linCurrentState = g_linStatePtr[instance];

    /* Change node's current state to IDLE */
    (void)LIN_LPUART_DRV_GotoIdleState(instance);

    /* Clear LIN Tx and Rx Busy flag */
    linCurrentState->isTxBusy = false;
    linCurrentState->isRxBusy = false;

    return retVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LIN_LPUART_DRV_GetReceiveStatus
 * Description   : This function returns whether the previous LPUART reception is
 * complete. When performing a non-blocking receive, the user can call this
 * function to ascertain the state of the current receive progress: in progress
 * or complete. In addition, if the reception is still in progress, the user can
 * obtain the number of words that is still needed to receive.
 *
 * Implements    : LIN_LPUART_DRV_GetReceiveStatus_Activity
 *END**************************************************************************/
status_t LIN_LPUART_DRV_GetReceiveStatus(uint32_t instance,
                                         uint8_t * bytesRemaining)
{
    /* Assert parameters. */
    CHECK_RESTRICTION(instance < LPUART_INSTANCE_COUNT);

    status_t retVal = STATUS_SUCCESS;

    /* Get the current LIN state of this LPUART instance. */
    const lin_state_t * linCurrentState = g_linStatePtr[instance];

    /* Get the number of bytes that is still needed to receive */
    *bytesRemaining = (uint8_t)(linCurrentState->rxSize - linCurrentState->cntByte);

    /* Return status of the on-going reception */
    if ((linCurrentState->currentEventId == LIN_NO_EVENT) && (*bytesRemaining != 0U))
    {
        if (linCurrentState->timeoutCounterFlag == false)
        {
            retVal = STATUS_BUSY;
        }
        else
        {
            retVal = STATUS_TIMEOUT;
        }
    }

    return retVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LIN_LPUART_DRV_GoToSleepMode
 * Description   : This function puts current LIN node to sleep mode.
 * This function changes current node state to LIN_NODE_STATE_SLEEP_MODE.
 *
 * Implements    : LIN_LPUART_DRV_GoToSleepMode_Activity
 *END**************************************************************************/
status_t LIN_LPUART_DRV_GoToSleepMode(uint32_t instance)
{
    /* Assert parameters. */
    CHECK_RESTRICTION(instance < LPUART_INSTANCE_COUNT);

    /* Get base address of the LPUART instance. */

    /* Get the current LIN state of this LPUART instance. */
    lin_state_t * linCurrentState = g_linStatePtr[instance];
		#if (0u == DEBUG_APPLICATION_ENABLE)
    /* Update node's current state to SLEEP_MODE. */
    linCurrentState->currentNodeState = LIN_NODE_STATE_SLEEP_MODE;
		#endif
    ///* Clear LPUART_RX Pin Active Edge Interrupt Flag. */
    //(void)LPUART_ClearStatusFlag(base, LPUART_RX_ACTIVE_EDGE_DETECT);

    /* Set Receive data not inverted */

    /* Disable RX  interrupt */
	//(void)LPUART_ClearStatusFlag(LPUART_LIN_RX_DETECT);
    //LPUART_SetIntMode( LPUART_LIN_RX_DETECT, false);

    /* Disable TX interrupt */
	//(void)LPUART_ClearStatusFlag(LPUART_LIN_TX_DETECT);
    //LPUART_SetIntMode(LPUART_LIN_TX_DETECT, false);

    /* Enable frame error interrupt */
	//(void)LPUART_ClearStatusFlag(LPUART_LIN_ERR_DETECT);
   // LPUART_SetIntMode(LPUART_LIN_ERR_DETECT, false);

    /* Enable LIN break detect interrupt */
	//(void)LPUART_ClearStatusFlag(LPUART_LIN_BREAK_DETECT);
   // LPUART_SetIntMode(LPUART_LIN_BREAK_DETECT, false);

    return STATUS_SUCCESS;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LIN_LPUART_DRV_SendWakeupSignal
 * Description   : This function sends a wakeup signal through the LPUART interface.
 *
 * Implements    : LIN_LPUART_DRV_SendWakeupSignal_Activity
 *END**************************************************************************/
status_t LIN_LPUART_DRV_SendWakeupSignal(uint32_t instance)
{
    /* CHECK_RESTRICTION parameters. */
    CHECK_RESTRICTION(instance < LPUART_INSTANCE_COUNT);

    /* Get the current LIN state of this LPUART instance. */
    const lin_state_t * linCurrentState = g_linStatePtr[instance];
    status_t retVal = STATUS_SUCCESS;

    /* Check if bus is not busy */
    if (linCurrentState->isBusBusy == false)
    {
        /* Send a wakeup signal */
        //LPUART_Putchar( s_wakeupSignal[instance]);
    }
    else
    {
        retVal = STATUS_BUSY;
    }

    return retVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LIN_LPUART_DRV_GetCurrentNodeState
 * Description   : This function gets the current LIN node state.
 *
 * Implements    : LIN_LPUART_DRV_GetCurrentNodeState_Activity
 *END**************************************************************************/
lin_node_state_t LIN_LPUART_DRV_GetCurrentNodeState(uint32_t instance)
{
    /* Assert parameters. */
    CHECK_RESTRICTION(instance < LPUART_INSTANCE_COUNT);

    lin_node_state_t retVal = LIN_NODE_STATE_UNINIT;
    /* Get the current LIN state of this LPUART instance. */
    const lin_state_t * linCurrentState = g_linStatePtr[instance];

    if (linCurrentState != NULL)
    {
        retVal = linCurrentState->currentNodeState;
    }

    /* Return LIN node's current state */
    return retVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LIN_LPUART_DRV_TimeoutService
 * Description   : This is callback function for Timer Interrupt Handler.
 * Users shall initialize a timer (for example FTM) in Output compare mode
 * with period of about 500 micro seconds. In timer IRQ handler, call this function.
 *
 * Implements    : LIN_LPUART_DRV_TimeoutService_Activity
 *END**************************************************************************/
void LIN_LPUART_DRV_TimeoutService(uint32_t instance)
{
    /* Assert parameters. */
    CHECK_RESTRICTION(instance < LPUART_INSTANCE_COUNT);

    /* Get the current LIN state of this LPUART instance. */
    lin_state_t * linCurrentState = g_linStatePtr[instance];

    /* Get LIN node's current state */
    lin_node_state_t state = linCurrentState->currentNodeState;

    switch (state)
    {
    	
        /* If the node is SENDING DATA */
        case LIN_NODE_STATE_SEND_DATA:
            /* Check if timeout Counter is 0 */
            if (linCurrentState->timeoutCounter == 0U)
            {
                /* Set timeout Counter flag */
                linCurrentState->timeoutCounterFlag = true;

                if (linCurrentState->isTxBlocking == false)
                {
                	/* Set current event id to LIN_TX_TIMEOUT */
					linCurrentState->currentEventId = LIN_TX_TIMEOUT;
                    /* Callback to handle timeout Counter flag */
                    if (linCurrentState->Callback != NULL)
                    {
                        linCurrentState->Callback(instance, linCurrentState);
                    }

                    /* Clear Tx busy flag */
                    linCurrentState->isTxBusy = false;

                    /* Change the node's current state to IDLE */
                    (void)LIN_LPUART_DRV_GotoIdleState(instance);
                }
            }
            else /* If timeout Counter is not 0, then decrease timeout Counter by one */
            {
                linCurrentState->timeoutCounter--;
            }

            break;
        /* If the node is RECEIVING DATA */
        case LIN_NODE_STATE_RECV_DATA:
            /* Check if timeout Counter is 0 */
            if (linCurrentState->timeoutCounter == 0U)
            {
                /* Set timeout Counter flag */
                linCurrentState->timeoutCounterFlag = true;

                /* Check if the reception is non-blocking */
                if (linCurrentState->isRxBlocking == false)
                {
                	/* Set current event id to LIN_RX_TIMEOUT */
					linCurrentState->currentEventId = LIN_RX_TIMEOUT;
                    /* Callback to handle timeout Counter flag */
                    if (linCurrentState->Callback != NULL)
                    {
                        linCurrentState->Callback(instance, linCurrentState);
                    }

                    /* Clear Rx busy flag */
                    linCurrentState->isRxBusy = false;

                    /* Change the node's current state to IDLE */
                    (void)LIN_LPUART_DRV_GotoIdleState(instance);
                }
            }
            /* If timeout Counter is not 0, then decrease timeout Counter by one */
            else
            {
                linCurrentState->timeoutCounter--;
            }

            break;
        default:
            /* The node state is not SENDING nor RECEIVING data */
            break;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LIN_LPUART_DRV_SetTimeoutCounter
 * Description   : This function sets value for timeout counter that is used in
 * LIN_LPUART_DRV_TimeoutService
 *
 * Implements    : LIN_LPUART_DRV_SetTimeoutCounter_Activity
 *END**************************************************************************/
void LIN_LPUART_DRV_SetTimeoutCounter(uint32_t instance,
                                      uint32_t timeoutValue)
{
    /* Assert parameters. */
    CHECK_RESTRICTION(instance < LPUART_INSTANCE_COUNT);

    /* Get the current LIN state of this LPUART instance. */
    lin_state_t * linCurrentState = g_linStatePtr[instance];

    /* Clear Timeout Counter Flag */
    linCurrentState->timeoutCounterFlag = false;

    /* Set new value for Timeout Counter */
    linCurrentState->timeoutCounter = timeoutValue;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LIN_LPUART_DRV_EnableIRQ
 * Description   : This function enables LPUART hardware interrupts.
 *
 * Implements    : LIN_LPUART_DRV_EnableIRQ_Activity
 *END**************************************************************************/
status_t LIN_LPUART_DRV_EnableIRQ(uint32_t instance)
{

    status_t retVal = STATUS_SUCCESS;
    /* Get the current LIN state of this LPUART instance. */
    const lin_state_t * linCurrentState = g_linStatePtr[instance];

    if (linCurrentState->currentNodeState == LIN_NODE_STATE_SLEEP_MODE)
    {
        /* Enable RX Input Active Edge interrupt */
        //LPUART_SetIntMode(LPUART_INT_RX_ACTIVE_EDGE, true);
    }
    else
    {
        /* Enable RX complete interrupt */
        //LPUART_SetIntMode( LPUART_LIN_RX_DETECT, true);

        /* Enable frame error interrupt */
        //LPUART_SetIntMode(LPUART_LIN_TX_DETECT, true);

        /* Enable LIN break detect interrupt */
        //LPUART_SetIntMode(LPUART_LIN_BREAK_DETECT, true);
    }



    return retVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LIN_LPUART_DRV_DisableIRQ
 * Description   : This function disables LPUART hardware interrupts.
 *
 * Implements    : LIN_LPUART_DRV_DisableIRQ_Activity
 *END**************************************************************************/
status_t LIN_LPUART_DRV_DisableIRQ(uint32_t instance)
{

    status_t retVal = STATUS_SUCCESS;

    /* Get the current LIN state of this LPUART instance. */
    const lin_state_t * linCurrentState = g_linStatePtr[instance];

    if (linCurrentState->currentNodeState == LIN_NODE_STATE_SLEEP_MODE)
    {
        /* Disable RX Input Active Edge interrupt */
        //LPUART_SetIntMode( LPUART_INT_RX_ACTIVE_EDGE, false);
    }
    else
    {
        /* Enable RX complete interrupt */
        LPUART_SetIntMode( LPUART_LIN_RX_DETECT, false);

        /* Enable frame error interrupt */
        LPUART_SetIntMode(LPUART_LIN_TX_DETECT, false);

        /* Enable LIN break detect interrupt */
        LPUART_SetIntMode(LPUART_LIN_BREAK_DETECT, false);
    }



    return retVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LIN_LPUART_DRV_GotoIdleState
 * Description   : This function puts current node to Idle state.
 *
 * Implements    : LIN_LPUART_DRV_GotoIdleState_Activity
 *END**************************************************************************/
status_t LIN_LPUART_DRV_GotoIdleState(uint32_t instance)
{

    /* Get the current LIN state of this LPUART instance. */
    lin_state_t * linCurrentState = g_linStatePtr[instance];
	LPUART_Break_Timer_Detc_Stop();
    linCurrentState->currentEventId = LIN_NO_EVENT;

    /* Set Break char detect length as 13 bits minimum */
	LPUART_SetBreakCharDetectLength(LPUART_BREAK_CHAR_11_BIT_MINIMUM);


    /* Set Receive data not inverted */

	
    /* Disable RX  interrupt */
	//(void)LPUART_ClearStatusFlag(LPUART_LIN_RX_DETECT);
    //LPUART_SetIntMode( LPUART_LIN_RX_DETECT, false);

    /* Disable TX interrupt */
	//(void)LPUART_ClearStatusFlag(LPUART_LIN_TX_DETECT);
    //LPUART_SetIntMode(LPUART_LIN_TX_DETECT, false);

    /* Enable frame error interrupt */
	//(void)LPUART_ClearStatusFlag(LPUART_LIN_ERR_DETECT);
   // LPUART_SetIntMode(LPUART_LIN_ERR_DETECT, false);

    /* Enable LIN break detect interrupt */
	(void)LPUART_ClearStatusFlag(LPUART_LIN_BREAK_DETECT);

    /* Discard leftover RX bytes so ignored application frames cannot overflow FIFO. */
    UART_EmptyRxFifo(LIN_ID);

    /* Change node's current state to IDLE */
    linCurrentState->currentNodeState = LIN_NODE_STATE_IDLE;

    /* Clear Bus busy Flag */
    linCurrentState->isBusBusy = false;
	linCurrentState->cntByte=0;                            /*!< To count number of bytes already transmitted or received. */
	linCurrentState->cntReadbackByte = 0U;
    linCurrentState->txSize=0;                    /*!< The remaining number of bytes to be transmitted. */
    linCurrentState->rxSize=0;                    /*!< The remaining number of bytes to be received. */
	LPUART_Break_Timer_Detc_Start();
	LPUART_SetIntMode(LPUART_LIN_TX_DETECT, false);
    return STATUS_SUCCESS;
}
static void LPUART_SetBreakCharDetectLength(lpuart_break_char_length_t length)
{
	if(LPUART_BREAK_CHAR_10_BIT_MINIMUM == length)
	{
		BreakCharDetectLength = 10;
	}
	else if(LPUART_BREAK_CHAR_11_BIT_MINIMUM == length)
	{
		BreakCharDetectLength = 11;
	}
	else if(LPUART_BREAK_CHAR_13_BIT_MINIMUM == length)
	{
		BreakCharDetectLength = 13;
	}
    
}


void LIN_LPUART_DRV_BREAK_IRQHandler(uint32_t instance)
{
	/* Get the current LIN state of this LPUART instance. */
	    lin_state_t * linCurrentState = g_linStatePtr[instance];
	    if(LIN_NODE_STATE_SLEEP_MODE != linCurrentState->currentNodeState)
		{
			LPUART_ClearStatusFlag(LPUART_LIN_BREAK_DETECT);
			LIN_LPUART_DRV_ProcessBreakDetect(instance);
			LPUART_ClearStatusFlag(LPUART_LIN_ERR_DETECT);
		}

}
/*FUNCTION**********************************************************************
 *
 * Function Name : LIN_LPUART_DRV_TX_IRQHandler
 * Description   : Interrupt handler for LPUART.
 * This handler uses the buffers stored in the lin_state_t struct to transfer
 * data. This is not a public API as it is called by IRQ whenever an interrupt
 * occurs.
 *
 * Implements    : LIN_LPUART_DRV_IRQHandler_Activity
 *END**************************************************************************/
void LIN_LPUART_DRV_TX_IRQHandler(uint32_t instance)
{
	 /* Get the current LIN state of this LPUART instance. */
    lin_state_t * linCurrentState = g_linStatePtr[instance];
	//if(LPUART_GetStatusFlag(LPUART_LIN_RX_DETECT))
	{
		(void)LPUART_ClearStatusFlag(LPUART_LIN_TX_DETECT);
		if(LIN_NODE_STATE_SEND_DATA == linCurrentState->currentNodeState)
		{
			LIN_LPUART_DRV_ProcessSendFrameData(instance);
		}
	}
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LIN_LPUART_DRV_IRQHandler
 * Description   : Interrupt handler for LPUART.
 * This handler uses the buffers stored in the lin_state_t struct to transfer
 * data. This is not a public API as it is called by IRQ whenever an interrupt
 * occurs.
 *
 * Implements    : LIN_LPUART_DRV_IRQHandler_Activity
 *END**************************************************************************/
void LIN_LPUART_DRV_RX_IRQHandler(uint32_t instance)
{

    volatile uint8_t tmpByte = 0U;
	volatile uint8_t err_type;
	volatile uint8_t ErrFlag =0u;

    /* Get the current LIN state of this LPUART instance. */
    lin_state_t * linCurrentState = g_linStatePtr[instance];
	  /* Get data from Data Register & Clear LPUART_RX_DATA_REG_FULL flag */
		
	//err_type = LPUART_Error_Status_Det();
 	 LPUART_Getchar((volatile uint8_t *)&tmpByte);

	/* Process data in Data Register while receive, send data */
	LIN_LPUART_DRV_ProcessFrame(instance, tmpByte);

		

    
} /* End void LIN_LPUART_DRV_IRQHandler(uint32_t instance) */

/*FUNCTION**********************************************************************
 *
 * Function Name : LIN_LPUART_DRV_ProcessBreakDetect
 * Description   : This function process break detect for LIN communication.
 *
 * Implements    : LIN_LPUART_DRV_ProcessBreakDetect_Activity
 *END**************************************************************************/
static void LIN_LPUART_DRV_ProcessBreakDetect(uint32_t instance)
{
    /* Get the current LIN user configure structure of this LPUART instance. */
    //const lin_user_config_t * linUserConfig = g_linUserconfigPtr[instance];

    /* Get the current LIN state of this LPUART instance. */
    lin_state_t * linCurrentState = g_linStatePtr[instance];

    /* Clear LIN Break Detect Interrupt Flag */
    (void)LPUART_ClearStatusFlag(LPUART_LIN_BREAK_DETECT);
    if(linCurrentState->currentNodeState != LIN_NODE_STATE_SLEEP_MODE)
    {
		/* Set Break char detect length as 10 bits minimum */
		LPUART_SetBreakCharDetectLength( LPUART_BREAK_CHAR_11_BIT_MINIMUM);
		/* Disable LIN Break Detect Interrupt */
		//LPUART_SetIntMode(LPUART_LIN_BREAK_DETECT, false);

        /* Drop stale bytes from ignored frames before expecting SYNC 0x55. */
        UART_EmptyRxFifo(LIN_ID);

		/* Set flag LIN bus busy */
		linCurrentState->isBusBusy = true;
		/* Change the node's current state to RECEIVED BREAK FIELD */
		linCurrentState->currentEventId = LIN_RECV_BREAK_FIELD_OK;
		/* Callback function */
		if (linCurrentState->Callback != NULL)
		{
			linCurrentState->Callback(instance, linCurrentState);
		}
		/* Change the node's current state to RECEIVING SYNC FIELD */
		linCurrentState->currentNodeState = LIN_NODE_STATE_RECV_SYNC;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LIN_LPUART_DRV_ProcessFrame
 * Description   : Part of Interrupt handler for receiving and sending data.
 * Receive Header, Data and Send Data.
 *
 * Implements    : LIN_LPUART_DRV_ProcessFrame_Activity
 *END**************************************************************************/
static void LIN_LPUART_DRV_ProcessFrame(uint32_t instance,
                                        uint8_t tmpByte)
{
    /* Get the current LIN state of this LPUART instance. */
    const lin_state_t * linCurrentState = g_linStatePtr[instance];

    /* Check node's current state */
    switch (linCurrentState->currentNodeState)
    {
        /* if current state is RECEIVE SYNC FIELD */
        case LIN_NODE_STATE_RECV_SYNC:
			LIN_LPUART_DRV_ProcessFrameHeader(instance, tmpByte);
			break;
        /* if current state is MASTER SENDING PID */
        case LIN_NODE_STATE_SEND_PID:
			break;
        /* if current state is RECEIVE PID */
        case LIN_NODE_STATE_RECV_PID:
            LIN_LPUART_DRV_ProcessFrameHeader(instance, tmpByte);
            break;
        /* if current state is RECEIVE DATA */
        case LIN_NODE_STATE_RECV_DATA:
            LIN_LPUART_DRV_ProcessReceiveFrameData(instance, tmpByte);
            break;
        /* if current state is SENDING DATA */
        case LIN_NODE_STATE_SEND_DATA:
            LIN_LPUART_DRV_ProcessReadBackFrameData(instance, tmpByte);
            break;

        default:
            /* Other node state */
            break;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LIN_LPUART_DRV_ProcessFrameHeader
 * Description   : Part of Interrupt handler for receiving and sending data.
 * Receive Sync byte, PID and Send PID.
 *
 * Implements    : LIN_LPUART_DRV_ProcessFrameHeader_Activity
 *END**************************************************************************/
static void LIN_LPUART_DRV_ProcessFrameHeader(uint32_t instance,
                                              uint8_t tmpByte)
{
    /* Get base address of the LPUART instance. */

    /* Get the current LIN user config structure of this LPUART instance. */
    //const lin_user_config_t * linUserConfig = g_linUserconfigPtr[instance];

    /* Get the current LIN state of this LPUART instance. */
    lin_state_t * linCurrentState = g_linStatePtr[instance];

    /* Check node's current state */
    switch (linCurrentState->currentNodeState)
    {
        /* If current state is RECEIVE SYNC FIELD */
        case LIN_NODE_STATE_RECV_SYNC:
            if (tmpByte == 0x55U)
            {
                /* Set current event ID to Sync byte is correct */
                linCurrentState->currentEventId = LIN_SYNC_OK;
                /* Change node's current state to RECEIVE PID */
                linCurrentState->currentNodeState = LIN_NODE_STATE_RECV_PID;
				LPUART_Break_Timer_Detc_Stop();//Off the timer and in the triggered state
				//(void)LPUART_ClearStatusFlag(LPUART_LIN_BREAK_DETECT);
            }
            else
            {
                /* Set current event ID to Sync byte is incorrect */
                linCurrentState->currentEventId = LIN_SYNC_ERROR;
                /* Callback function to handle event RECEIVED SYNC FIELD ERROR */
                if (linCurrentState->Callback != NULL)
                {
                    linCurrentState->Callback(instance, linCurrentState);
                }

                /* Change node's current state to IDLE */
                //(void)LIN_LPUART_DRV_GotoIdleState(instance);
                LPUART_Break_Timer_Detc_Stop();
				//(void)LPUART_ClearStatusFlag(LPUART_LIN_BREAK_DETECT);
				LPUART_Break_Timer_Detc_Start();
            }

            break;
        /* If current state is MASTER SENDING PID */
        case LIN_NODE_STATE_SEND_PID:
			#if 0
            /* Check if master node sent SYNC byte correctly before send PID */
            if (tmpByte == 0x55U)
            {
                /* Change node's current state to RECEIVING PID */
                linCurrentState->currentNodeState = LIN_NODE_STATE_RECV_PID;
                /* Send the current PID byte */
                LPUART_Putchar(linCurrentState->currentPid);
            }
            /* In case of errors during header transmission, it is up to the implementer
             * how to handle these errors (stop/continue transmission) and to decide if the
             * corresponding response is valid or not.
             * By default, LIN Driver set isBusBusy to false, and change node's state to IDLE.
             */
            else
            {
                /* Set current event ID to Sync byte is incorrect */
                linCurrentState->currentEventId = LIN_SYNC_ERROR;
                /* Clear Bus bus flag */
                linCurrentState->isBusBusy = false;
                /* Change node's current state to IDLE */
                linCurrentState->currentNodeState = LIN_NODE_STATE_IDLE;

                /* Callback function to handle event SENT SYNC BYTE ERROR */
                if (linCurrentState->Callback != NULL)
                {
                    linCurrentState->Callback(instance, linCurrentState);
                }
            }
			#endif
            break;
        /* If current state is RECEIVE PID */
        case LIN_NODE_STATE_RECV_PID:
			#if 0
            /* If the node is MASTER */
            if (linUserConfig->nodeFunction == (bool)MASTER)
            {
                /* Check if master node sent PID correctly */
                if (tmpByte == linCurrentState->currentPid)
                {
                    /* Set current event ID to PID correct */
                    linCurrentState->currentEventId = LIN_PID_OK;

                    /* Check receiving data is blocking */
                    if (linCurrentState->isRxBlocking == true)
                    {
                        /* Starting receive data blocking */
                        linCurrentState->currentNodeState = LIN_NODE_STATE_RECV_DATA;
                        linCurrentState->isBusBusy = true;
                        linCurrentState->isRxBusy = true;

                        /* Set Break char detect length as 10 bits minimum */
						LPUART_SetBreakCharDetectLength(LPUART_BREAK_CHAR_11_BIT_MINIMUM);
                    }
                    else
                    {
                        /* Clear Bus bus flag */
                        linCurrentState->isBusBusy = false;

                        /* Callback function to handle correct PID */
                        if (linCurrentState->Callback != NULL)
                        {
                            linCurrentState->Callback(instance, linCurrentState);
                        }
                    }
                }
                /* In case of errors during header transmission, it is up to the implementer
                 * how to handle these errors (stop/continue transmission) and to decide if the
                 * corresponding response is valid or not.
                 * By default, LIN Driver set isBusBusy to false, and change node's state to IDLE.
                 */
                else
                {
                    /* Set current event ID to PID incorrect */
                    linCurrentState->currentEventId = LIN_PID_ERROR;
                    /* Clear bus busy flag */
                    linCurrentState->isBusBusy = false;
                    /* Change node's current state to IDLE */
                    linCurrentState->currentNodeState = LIN_NODE_STATE_IDLE;
                    /* Callback function to handle event MASTER SENT PID ERROR */
                    if (linCurrentState->Callback != NULL)
                    {
                        linCurrentState->Callback(instance, linCurrentState);
                    }
                }
            }
            /* If the node is SLAVE */
            else
			#endif
            {
                /* Check the received PID */
                linCurrentState->currentId = LIN_DRV_ProcessParity(tmpByte, CHECK_PARITY);
                linCurrentState->currentPid = tmpByte;
                if (linCurrentState->currentId != 0xFFU)
                {
                    /* Set current event ID to PID correct */
                    linCurrentState->currentEventId = LIN_PID_OK;
                    /* Clear Bus bus flag */
                    linCurrentState->isBusBusy = false;

                    /* Callback function to handle event PID correct */
                    if (linCurrentState->Callback != NULL)
                    {
                        linCurrentState->Callback(instance, linCurrentState);
                    }

                }
                else
                {
                    /* Set current event ID to PID ERROR */
                    linCurrentState->currentEventId = LIN_PID_ERROR;

                    /* Callback function to handle event PID incorrect */
                    if (linCurrentState->Callback != NULL)
                    {
                        linCurrentState->Callback(instance, linCurrentState);
                    }

                    /* Change node's current state to IDLE */
                    (void)LIN_LPUART_DRV_GotoIdleState(instance);
                }
            }

            break;
        default:
            /* Other node state */
            break;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LIN_LPUART_DRV_ProcessReceiveFrameData
 * Description   : Part of Interrupt handler for receiving.
 *
 * Implements    : LIN_LPUART_DRV_ProcessReceiveFrameData_Activity
 *END**************************************************************************/
static void LIN_LPUART_DRV_ProcessReceiveFrameData(uint32_t instance,
                                                   uint8_t tmpByte)
{
    /* Get the current LIN state of this LPUART instance. */
    lin_state_t * linCurrentState = g_linStatePtr[instance];

    if (linCurrentState->rxSize > (linCurrentState->cntByte + 1U))
    {
        *(linCurrentState->rxBuff) = tmpByte;
        linCurrentState->rxBuff++;
    }
    else
    {
        if ((linCurrentState->rxSize - linCurrentState->cntByte) == 1U)
        {
            linCurrentState->checkSum = tmpByte;
        }
    }

    linCurrentState->cntByte++;
    if (linCurrentState->cntByte == linCurrentState->rxSize)
    {
        /* Restore rxBuffer pointer */
        linCurrentState->rxBuff -= linCurrentState->rxSize - 1U;
        if (LIN_LPUART_DRV_MakeChecksumByte(instance, linCurrentState->rxBuff, linCurrentState->rxSize - 1U, linCurrentState->currentPid) == linCurrentState->checkSum)
        {
            linCurrentState->currentEventId = LIN_RX_COMPLETED;
            linCurrentState->currentNodeState = LIN_NODE_STATE_RECV_DATA_COMPLETED;

            /* callback function to handle RX COMPLETED */
            if (linCurrentState->Callback != NULL)
            {
                linCurrentState->Callback(instance, linCurrentState);
            }
					

            /* Clear Bus busy flag */
            linCurrentState->isBusBusy = false;

            /* Clear Rx busy flag */
            linCurrentState->isRxBusy = false;

            /* In case of receiving a go to sleep request, after callback, node is in SLEEP MODE */
            /* In this case, node is in SLEEP MODE state */
            if (linCurrentState->currentNodeState != LIN_NODE_STATE_SLEEP_MODE)
            {
                (void)LIN_LPUART_DRV_GotoIdleState(instance);
            }

        }
        else
        {
            linCurrentState->currentEventId = LIN_CHECKSUM_ERROR;
            /* callback function to handle checksum error */
            if (linCurrentState->Callback != NULL)
            {
                linCurrentState->Callback(instance, linCurrentState);
            }

            /* Clear Rx busy flag */
            linCurrentState->isRxBusy = false;

            /* Change node's current state to IDLE */
            (void)LIN_LPUART_DRV_GotoIdleState(instance);
        }
    }
}
static void LIN_LPUART_DRV_ProcessSendFrameData(uint32_t instance)
{

    /* Get the current LIN state of this LPUART instance. */
    lin_state_t * linCurrentState = g_linStatePtr[instance];

	if (linCurrentState->cntByte < linCurrentState->txSize)
	{
		/* Send checksum byte */
		if ((linCurrentState->txSize - linCurrentState->cntByte) == 1U)
		{
			LPUART_Putchar(linCurrentState->checkSum);
		}
		/* Send data bytes */
		else
		{
			LPUART_Putchar(*linCurrentState->txBuff);
		}

		linCurrentState->txBuff++;
		linCurrentState->cntByte++;
	}
	else
	{
		linCurrentState->currentEventId = LIN_TX_COMPLETED;
		linCurrentState->currentNodeState = LIN_NODE_STATE_SEND_DATA_COMPLETED;

		//LPUART_SetIntMode(LPUART_LIN_TX_DETECT, false);
		/* callback function to handle event TX COMPLETED */
		if (linCurrentState->Callback != NULL)
		{
			linCurrentState->Callback(instance, linCurrentState);
		}


		/* Clear Tx busy flag */
		linCurrentState->isTxBusy = false;

		/* Change node's current state to IDLE */
		(void)LIN_LPUART_DRV_GotoIdleState(instance);

	}

}

/*FUNCTION**********************************************************************
 *
 * Function Name : LIN_LPUART_DRV_ProcessSendFrameData
 * Description   : Part of Interrupt handler for sending data.
 *
 * Implements    : LIN_LPUART_DRV_ProcessSendFrameData_Activity
 *END**************************************************************************/
static void LIN_LPUART_DRV_ProcessReadBackFrameData(uint32_t instance,
                                                uint8_t tmpByte)
{
    bool sendFlag = true;
    uint8_t tmpSize;
    bool tmpCheckSumAndSize=0;
    bool tmpBuffAndSize=0;

	
    /* Get the current LIN state of this LPUART instance. */
    lin_state_t * linCurrentState = g_linStatePtr[instance];
	if (linCurrentState->cntByte < linCurrentState->txSize)
    {
		RxReadBackFrameData[linCurrentState->cntReadbackByte] =  tmpByte;
	 }

    tmpSize = (uint8_t)((linCurrentState->txSize - 2) - linCurrentState->cntReadbackByte);
    tmpBuffAndSize = ((LinBackupSendFrameData[linCurrentState->cntReadbackByte] != tmpByte) && (tmpSize != 0U));
    if (tmpBuffAndSize )

    {
        linCurrentState->currentEventId = LIN_READBACK_ERROR;
		    linCurrentState->cntReadbackByte =0;
        /* callback function to handle Readback error */
        if (linCurrentState->Callback != NULL)
        {
            linCurrentState->Callback(instance, linCurrentState);
        }

        /* Check if the transmission is non-blocking */
        if (linCurrentState->isTxBlocking == false)
        {
            /* Clear Tx busy flag */
            linCurrentState->isTxBusy = false;

            /* Change node's current state to IDLE */
            (void)LIN_LPUART_DRV_GotoIdleState(instance);
        }

        sendFlag = false;
    }
    else
    {

    	if(tmpSize == 0)
    	{
					linCurrentState->currentEventId = LIN_TX_COMPLETED;
					linCurrentState->currentNodeState = LIN_NODE_STATE_SEND_DATA_COMPLETED;

					//LPUART_SetIntMode(LPUART_LIN_TX_DETECT, false);
					/* callback function to handle event TX COMPLETED */
					if (linCurrentState->Callback != NULL)
					{
						linCurrentState->Callback(instance, linCurrentState);
					}


					/* Clear Tx busy flag */
					linCurrentState->isTxBusy = false;

					/* Change node's current state to IDLE */
				//	(void)LIN_LPUART_DRV_GotoIdleState(instance);
			}
			else
			{
				linCurrentState->cntReadbackByte++;
			}
			
    }

}

/* *****************************************************************************
 * EOF
 ******************************************************************************/
