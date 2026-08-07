#include "ComStack_Types.h"
#include "NmHistoryState.h"
#include "NvM_Cfg.h"


/* this file shall be compile only used 009-19 project  */
#if defined(ASENSING_GEELY_FX11_CUSTOM)

#define READ_NM_HISTORY_STATE 0
#define READ_NM_CURRENT_STATE 1

/******************************************************************************
**                      Private Variable Definitions                         **
******************************************************************************/
static uint32 writePoint;
static uint32 localBufStoreCnt = 0u;
static boolean localBusOffState = FALSE;
#if defined(NM_CUSTOM_TIMERSTAMP)
static uint32 nHs_gTimer = 0ul;

#define TIMER_ASSEMBER(buf)    \
        ((uint32)buf[0]) << 24u| \
        ((uint32)buf[1]) << 16u| \
        ((uint32)buf[2]) << 8u| \
        ((uint32)buf[3]);

#define  TIMER_REASSEMBER(buf, timervlu)    \
    do { \
        buf[0] = (uint8)((timervlu>>24u) & 0xFF); \
        buf[1] = (uint8)((timervlu>>16u) & 0xFF); \
        buf[2] = (uint8)((timervlu>>8u) & 0xFF); \
        buf[3] = (uint8)((timervlu) & 0xFF); \
    } while (0)
#endif /* defind(NM_CUSTOM_TIMERSTAMP) */

typedef struct
{
    uint8  nmState;
#if defined(NM_CUSTOM_TIMERSTAMP)
    uint32 tmStampU32;
#endif /* defind(NM_CUSTOM_TIMERSTAMP) */
} Nhs_BufferType;

#if defined(NM_CUSTOM_TIMERSTAMP)

void NmHistoryState_CopyNmStateToNvm(void);

typedef struct
{
    /* data */
    Std_ReturnType (*readTimerStampFuncPtr)(uint8 *);
    Std_ReturnType (*writeTimerStampFuncPtr)(uint8 *);
} Nhs_ConfigType;

static const Nhs_ConfigType Nhs_Config =
{
	NULL_PTR,
	NULL_PTR
};
#endif/* defind(NM_CUSTOM_TIMERSTAMP) */


static Nhs_BufferType Nhs_Buffer[NHS_BUFFER_SIZE];


void NmHistoryState_Init(void)
{
#if defined(NM_CUSTOM_TIMERSTAMP)
    /* step 1:
    read global timer stamp form trcv TJA1169 */
    uint8 localTmSt[4];

    if (NULL_PTR != Nhs_Config.readTimerStampFuncPtr)
    {
        Std_ReturnType ret = Nhs_Config.readTimerStampFuncPtr(localTmSt);

        if (E_OK == ret)
        {
            nHs_gTimer = TIMER_ASSEMBER(localTmSt);
        }
    }
    else
    {
        nHs_gTimer = 0;
    }
#endif /* defind(NM_CUSTOM_TIMERSTAMP) */

    uint32 index = 0u;

    for(index = 0u; index < NHS_BUFFER_SIZE; index++)
    {
        Nhs_Buffer[index].nmState = NHS_STATE_OFF;
#if defined(NM_CUSTOM_TIMERSTAMP)
        Nhs_Buffer[index].tmStampU32 = nHs_gTimer;
#endif /* defind(NM_CUSTOM_TIMERSTAMP) */
    }

/*9-12-change*/
    uint8 Counter_NM = 0;
    uint8 i = 49;
    do
    {
        Nhs_Buffer[Counter_NM].nmState = NvMBlockRamBuffer7[i - 4];
        (Nhs_Buffer[Counter_NM].tmStampU32) = (((uint32)NvMBlockRamBuffer7[i]) ^ ((uint32)NvMBlockRamBuffer7[i-1] << 8)
                                             ^ ((uint32)NvMBlockRamBuffer7[i-2] << 16) ^ (uint32)NvMBlockRamBuffer7[i-3] << 24);
        i -= 5;
        Counter_NM++;
    }while(Counter_NM < NHS_BUFFER_SIZE);


/*9-12-change*/
    writePoint = 0u;
    localBufStoreCnt = 0u;
    localBusOffState = FALSE;
}

void NmHistoryState_DeInit(void)
{
#if defined(NM_CUSTOM_TIMERSTAMP)
    uint8 localTmSt[4];
    TIMER_REASSEMBER(localTmSt, nHs_gTimer);

    if(NULL_PTR != Nhs_Config.writeTimerStampFuncPtr)
    {
        (void)Nhs_Config.writeTimerStampFuncPtr(localTmSt);
    }
#endif/* defind(NM_CUSTOM_TIMERSTAMP) */
}

#if defined(NM_CUSTOM_TIMERSTAMP)
/* cycle 100ms */
void NmHistoryState_MainFunction(void)
{
    nHs_gTimer++;
}
#endif /* defind(NM_CUSTOM_TIMERSTAMP) */

void NmNmHistoryState_NodifyBusOff(boolean busOffState)
{
    localBusOffState = busOffState;
}

void NmHistoryState_NodifyState(uint8 state)
{
    boolean allowReocde = FALSE;

    if(TRUE != localBusOffState)
    {
        if ((NHS_STATE_BUSOFF_REC_LEVEL1 != state)
                && (NHS_STATE_BUSOFF_REC_LEVEL2 != state))
        {
            allowReocde = TRUE;
        }
    }
    else
    {
        if ((NHS_STATE_BUSOFF_REC_LEVEL1 == state)
                || (NHS_STATE_BUSOFF_REC_LEVEL2 == state))
        {
            allowReocde = TRUE;
        }
    }

    if ((writePoint > 0) && (Nhs_Buffer[writePoint-1].nmState == state))
	{
    	allowReocde = FALSE;
	}
    else if ((0 == writePoint) && (Nhs_Buffer[NHS_BUFFER_SIZE-1].nmState == state))
    {
    	allowReocde = FALSE;
    }

    if(TRUE == allowReocde)
    {
        Nhs_Buffer[writePoint].nmState = state;
#if defined(NM_CUSTOM_TIMERSTAMP)
        Nhs_Buffer[writePoint].tmStampU32 = nHs_gTimer;
#endif /* defind(NM_CUSTOM_TIMERSTAMP) */

        writePoint++;
        if(writePoint >= NHS_BUFFER_SIZE)
        {
            writePoint = 0u;
        }

        localBufStoreCnt++;
        if(localBufStoreCnt > NHS_BUFFER_SIZE)
        {
            localBufStoreCnt = NHS_BUFFER_SIZE;
        }
    }
}

Std_ReturnType NmHistoryState_BaseDidReadLen(uint16 * lenPtr)
{
    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != lenPtr)
    {
        *lenPtr = (uint16)(sizeof(Nhs_BufferType) * localBufStoreCnt);
        ret = E_OK;
    }

    return ret;
}



Std_ReturnType NmHistoryState_BaseDidReadBuf(uint8 * bufPtr)
{
    Std_ReturnType ret = E_NOT_OK;
#if 0   //9-12-change
    static uint8 NmHistoryRead_Flag = READ_NM_HISTORY_STATE;
    uint8 i;

    if (READ_NM_HISTORY_STATE == NmHistoryRead_Flag)
    {
        for(i = 0; i < 50; i++)
        {
            bufPtr[i] = NvMBlockRamBuffer7[i];
        }
        NmHistoryRead_Flag = READ_NM_CURRENT_STATE;
        ret = E_OK;
    }
    else
    {
#endif
        if (NULL_PTR != bufPtr)
        {
            // uint32 totCnt = localBufStoreCnt;
            uint32 totCnt = NHS_BUFFER_SIZE; /* read all buffer */
            uint32 index = writePoint;

            ret = E_OK;

            if (totCnt > 0u)
            {
                while (totCnt--)
                {
                    if (0u == index)
                    {
                        index = NHS_BUFFER_SIZE - 1u;
                    }
                    else
                    {
                        index--;
                    }

                    *bufPtr++ = Nhs_Buffer[index].nmState;
#if defined(NM_CUSTOM_TIMERSTAMP)
                    *bufPtr++ = (uint8)(Nhs_Buffer[index].tmStampU32 >> 24u);
                    *bufPtr++ = (uint8)(Nhs_Buffer[index].tmStampU32 >> 16u);
                    *bufPtr++ = (uint8)(Nhs_Buffer[index].tmStampU32 >> 8u);
                    *bufPtr++ = (uint8)(Nhs_Buffer[index].tmStampU32);
#endif /* defind(NM_CUSTOM_TIMERSTAMP) */
                }
            }
        }

    // }//9-12-change
    

    return ret;
}

void NmHistoryState_CopyNmStateToNvm(void)
{
    uint32 totCnt = NHS_BUFFER_SIZE; /* read all buffer */
    uint32 index = writePoint;
    uint8 i = 0;

    if (totCnt > 0u)
    {
        while (totCnt--)
        {
            if (0u == index)
            {
                index = NHS_BUFFER_SIZE - 1u;
            }
            else
            {
                index--;
            }
            NvMBlockRamBuffer7[i] = Nhs_Buffer[index].nmState;
#if defined(NM_CUSTOM_TIMERSTAMP)
            NvMBlockRamBuffer7[i+1] = (uint8)(Nhs_Buffer[index].tmStampU32 >> 24u);
            NvMBlockRamBuffer7[i+2] = (uint8)(Nhs_Buffer[index].tmStampU32 >> 16u);
            NvMBlockRamBuffer7[i+3] = (uint8)(Nhs_Buffer[index].tmStampU32 >> 8u);
            NvMBlockRamBuffer7[i+4] = (uint8)(Nhs_Buffer[index].tmStampU32);
#endif /* defind(NM_CUSTOM_TIMERSTAMP) */
            i += 5;
        

        }
    }
    
    
}

#endif/* defined(ASENSING_GEELY_FX11_CUSTOM) */
