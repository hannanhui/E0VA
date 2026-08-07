#include "Platform_Types.h"
#include "FreeRTimer.h"
#include "SmartAdj.h"
#include "Pneumatic.h"

#define GPT_5msCnt       5uL
#define GPT_10msCnt      10uL
#define GPT_20msCnt      20uL
#define GPT_50msCnt      50uL
#define GPT_100msCnt     100uL
#define GPT_1000msCnt    1000uL

volatile boolean Gpt_1msFlag;
volatile boolean Gpt_5msFlag;
volatile boolean Gpt_10msFlag;
volatile boolean Gpt_20msFlag;
volatile boolean Gpt_50msFlag;
volatile boolean Gpt_100msFlag;
volatile boolean Gpt_1000msFlag;

/* Gpt_1ms notification CONTINUOUS MODE */
void GptNotification_1ms(void)
{
    /* 1ms Interrupt*/
    static uint32 Gpt_5msTick = 1;
    static uint32 Gpt_10msTick = 3;
    static uint32 Gpt_20msTick = 5 ;
    static uint32 Gpt_50msTick = 7;
    static uint32 Gpt_100msTick = 9;
    static uint32 Gpt_1000msTick = 11;
    
    Run_msCounter();
    
    /* 1ms Counter*/
    Gpt_1msFlag = 1;
    
    /* 5ms Counter*/
    Gpt_5msTick++;
    if(Gpt_5msTick >= GPT_5msCnt)
    {
        Gpt_5msTick = 0;
        Gpt_5msFlag = 1;
    }
    
    /* 10ms Counter*/
    Gpt_10msTick++;
    if(Gpt_10msTick >= GPT_10msCnt)
    {
        Gpt_10msTick = 0;
        Gpt_10msFlag = 1;
		MassageTimeCnt();
    }
    
    /* 20ms Counter*/
    Gpt_20msTick++;
    if(Gpt_20msTick >= GPT_20msCnt)
    {
        Gpt_20msTick = 0;
        Gpt_20msFlag = 1;
    }
    
    /* 50ms Counter*/
    Gpt_50msTick++;
    if(Gpt_50msTick >= GPT_50msCnt)
    {
        Gpt_50msTick = 0;
        Gpt_50msFlag = 1;
    }
    
    /* 100ms Counter*/
    Gpt_100msTick++;
    if(Gpt_100msTick >= GPT_100msCnt)
    {
        Gpt_100msTick = 0;
        Gpt_100msFlag = 1;
        
        if(ActionTimeOut)
            ActionTimeOut--;
        //if(BACK_SIDE_L_FastTime)
        //    BACK_SIDE_L_FastTime--;
        //if(BACK_SIDE_R_FastTime)
        //    BACK_SIDE_R_FastTime--;
    }
    
    /* 1000ms Counter*/
    Gpt_1000msTick++;
    if(Gpt_1000msTick >= GPT_1000msCnt)
    {
        Gpt_1000msTick = 0;
        Gpt_1000msFlag = 1;
    }
}


