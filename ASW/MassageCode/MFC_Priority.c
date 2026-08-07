

#include "include.h"



static uint32_t MssgFunc_Priority = 0;
static uint8_t PriorityNum = 0;


static MssgFunc_pLevel_ops *pLoc_Priority;

void MssgFuncPrio_Init(MssgFunc_pLevel_ops *ops,uint8_t Number)
{
    pLoc_Priority = &ops[0];
    PriorityNum = Number;
}


void Creat_MssgFuncPrio(uint8_t id, uint8_t *RunFlag,uint8_t Level)
{
	if (id>=PriorityNum)
	{
		return;
	}
	pLoc_Priority[id].is_active = RunFlag;
	pLoc_Priority[id].pLevel = Level;
}


uint8_t Level_Active[5] = {0};
uint8_t Get_En_MssgFuncPrio(uint8_t ID)
{
    uint8_t i;
    uint8_t loc_Leve;
    loc_Leve = pLoc_Priority[ID].pLevel;

    for(i = 0; i<PriorityNum;i++)
    {
    	Level_Active[i] = *(pLoc_Priority[i].is_active);
        if(ID == i || (pLoc_Priority[i].is_active == ((void *)0)))
        {
            continue;
        }
        
        if(loc_Leve>pLoc_Priority[i].pLevel && (*(pLoc_Priority[i].is_active)))
        {
            return FALSE;
        }
    }
    return TRUE;
}




















