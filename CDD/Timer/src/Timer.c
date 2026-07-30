
/* Inclusion of Platform_Types.h and Compiler.h */
#include "Std_Types.h"
#include "Timer.h"

#define GPT_5msCnt       5uL
#define GPT_10msCnt      10uL
#define GPT_100msCnt     100uL
#define GPT_500msCnt     500uL
#define GPT_1000msCnt    1000uL

volatile uint8 Gpt_1msFlag;
volatile uint8 Gpt_5msFlag;
volatile uint8 Gpt_10msFlag;
volatile uint8 Gpt_500msFlag;
volatile uint32 msCounter = 0;
volatile uint32 Msc_Delay_count;

Std_ReturnType MyGetCounterValue(uint16 id, MyTickType* tick)
{
	*tick = msCounter;
	return E_OK;
}

Std_ReturnType MyGetElapsedCounterValue(uint16 id, MyTickType* tick, MyTickType* elapsed)
{
	*elapsed = msCounter - *tick;
	*tick = msCounter;
	return E_OK;
}


/* Gpt_1ms notification */
void Gpt_1ms(void)
{
	/* 1ms Interrupt*/
	static uint32 Gpt_5msTick =0 ;
	static uint32 Gpt_10msTick =0 ;
	static uint32 Gpt_500msTick =0 ;

	Msc_Delay_count ++;
	if(Msc_Delay_count > 6000)
	{
		Msc_Delay_count = 7000;
	}

	Gpt_1msFlag = TRUE;
	if(msCounter < 2147483647)
	{
		msCounter ++;
	}
	else
	{
		msCounter = 0;
	}
	/* 5ms Counter*/
	Gpt_5msTick++;
	if (Gpt_5msTick >= GPT_5msCnt)
	{
		Gpt_5msTick = 0;
		Gpt_5msFlag = TRUE;
	}
	/* 10ms Counter*/
	Gpt_10msTick++;
	if (Gpt_10msTick >= GPT_10msCnt)
	{
		Gpt_10msTick = 0;
		Gpt_10msFlag = TRUE;
	}

	Gpt_500msTick++;
	if (Gpt_500msTick >= GPT_500msCnt)
	{
		Gpt_500msTick = 0;
		Gpt_500msFlag = TRUE;
	}
}




