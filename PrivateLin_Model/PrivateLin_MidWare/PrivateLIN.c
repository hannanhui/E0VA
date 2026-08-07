
#include "include.h"

static uint16_t LIN_Period_1mS_Cnt = 0;

/*******************************************************************************
*函数名 		: LIN_App_Init
*函数功能  	: LIN 初始化
*函数参数	: 无
*函数返回值	: 无
*说明		: 无
*******************************************************************************/
void Private_LIN_Init(void)
{
	LIN_Period_1mS_Cnt = 0;

	Private_Lin_Phy_Init();
	LIN_Msg_Tbl_Init();
	//LIN_Schedule_Init();
	//LIN_Schedule_Set_Type(LIN_SCHEDULE_TYPE_NORMAL);
}


/*******************************************************************************
*函数名		: LIN_Period_1mS
*函数功能  	: LIN诊断周期函数
*函数参数  	: 无
*函数返回值	: 无
*说明		: 无
*******************************************************************************/
void LIN_Period_1mS(void)
{	
	if(LIN_Period_1mS_Cnt<LIN_SCHEDULE_PREIODIC)
	{
		if (++LIN_Period_1mS_Cnt <  LIN_SCHEDULE_PREIODIC)
		{
			return;
		}
	}
	if(BAT_VOL_STA_NORMAL == FaultDiag_BattVol_StatusGet())
	{
		//LIN_Schedule_Period_10mS();
	}
	LIN_Period_1mS_Cnt =0;


	
}
void LIN_Period_10mS(void)
{	

	if(BAT_VOL_STA_NORMAL == FaultDiag_BattVol_StatusGet())
	{
		//LIN_Schedule_Period_10mS();
	}


	
}



