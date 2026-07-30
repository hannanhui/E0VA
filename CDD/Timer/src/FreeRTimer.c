
/******************************* references ************************************/
#include "FreeRTimer.h"
#include "Timer.h"

/****************************** implementations ********************************/
uint32 Frt_ReadOutMS(void)
{
	uint32  OSCurMs;

	(void)MyGetCounterValue(0, &OSCurMs);
	            /*tick to ms*/
	OSCurMs = TICKS2MS_SystemTimer(OSCurMs);

	return(OSCurMs);
}

uint32 Frt_CalculateElapsedMS(uint32 OldCurMs)
{
	uint32  ElapsedMs;

	OldCurMs = MS2TICKS_SystemTimer(OldCurMs);
    (void)MyGetElapsedCounterValue(0, &OldCurMs, &ElapsedMs);
    ElapsedMs = TICKS2MS_SystemTimer(ElapsedMs);

    return(ElapsedMs);
}

