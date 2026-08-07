#include "include.h"


MssgFunc_pLevel_ops Mssg_Sys_ops[FUNC_NUM_MAX] = {0};
static uint8_t MFC_Run = 0;
extern BOOL Get_Out_Lumbar_PumpState(void);

void MFC_Ctrl_Init(void)
{
	
}


BOOL Get_MFC_PumpState(void)
{
	if (Get_Out_Massage_PumpState()||Get_Out_Lumbar_PumpState())
	{
		return TRUE;
	}
	return FALSE;
}





void MFC_Ctrl_Task(void)
{

}




















