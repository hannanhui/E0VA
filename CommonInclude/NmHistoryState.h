#ifndef NM_HISTORY_STATE
#define NM_HISTORY_STATE
#include "ComStack_Types.h"

#if defined(ASENSING_GEELY_FX11_CUSTOM)
/******************************************************************************
**                      Global Symbols                                       **
******************************************************************************/

/* nm state history value define */
/* Off */
#define NHS_STATE_OFF                               ((uint8)0x01u)
/* BusSleepMode */
#define NHS_STATE_BUSSLEEPMODE                      ((uint8)0x02u)
/* repeat message state */
#define NHS_STATE_REPEATMESSAGESTATE                ((uint8)0x04u)
/* normal operation state */
#define NHS_STATE_NORMALOPERATIONTATE               ((uint8)0x05u)
/* ready sleep state */
#define NHS_STATE_READYSLEEPSTATE                   ((uint8)0x06u)
/* prepare bus sleep mode */
#define NHS_STATE_PREPAREBUSSLEEPMODE               ((uint8)0x07u)
/* CANSM Bus off recovery Level 1 */
#define NHS_STATE_BUSOFF_REC_LEVEL1                 ((uint8)0x08u)
/* CANSM Bus off recovery Level 2 */
#define NHS_STATE_BUSOFF_REC_LEVEL2                 ((uint8)0x09u)

#define NHS_BUFFER_SIZE                             (10u)


extern void NmHistoryState_Init(void);
extern void NmHistoryState_DeInit(void);
#if defined(NM_CUSTOM_TIMERSTAMP)
extern void NmHistoryState_MainFunction(void);
#endif /* defind(NM_CUSTOM_TIMERSTAMP) */
extern void NmNmHistoryState_NodifyBusOff(boolean busOffState);
extern void NmHistoryState_NodifyState(uint8 state);
#endif /* defined(ASENSING_GEELY_FX11_CUSTOM) */
extern Std_ReturnType NmHistoryState_BaseDidReadLen(uint16 * lenPtr);
extern Std_ReturnType NmHistoryState_BaseDidReadBuf(uint8 * bufPtr);


#endif/* NM_HISTORY_STATE */
