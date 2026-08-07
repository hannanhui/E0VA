
/******************************* references ************************************/
#include "FreeRTimer.h"
//#include "Os_counter_api.h"
#include "Std_Types.h"
#include "Platform_Types.h"

/****************************** implementations ********************************/

TickType msCounter = 0;
/*the function defined in an other file*/

void Run_msCounter(void)
{
    msCounter++;
}

Std_ReturnType GetCounterValue(uint16 id, TickType* tick)
{
	*tick = msCounter;
	return E_OK;
}

Std_ReturnType GetElapsedCounterValue(uint16 id, TickType* tick, TickType* elapsed)
{
	*elapsed = msCounter - *tick;
	*tick = msCounter;
	return E_OK;
}


uint32 Frt_ReadOutMS(void)
{
    uint32  OSCurMs;

	(void)GetCounterValue(0, &OSCurMs);
	/*tick to ms*/
	OSCurMs = TICKS2MS_SystemTimer(OSCurMs);

    return(OSCurMs);
}

uint32 Frt_CalculateElapsedMS(uint32 OldCurMs)
{
    uint32  ElapsedMs;

    /*ms to tick*/
	OldCurMs = MS2TICKS_SystemTimer(OldCurMs);
    (void)GetElapsedCounterValue(0, &OldCurMs, &ElapsedMs);
    ElapsedMs = TICKS2MS_SystemTimer(ElapsedMs);

    return(ElapsedMs);
}


