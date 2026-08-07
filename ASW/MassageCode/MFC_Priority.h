

#ifndef __MFC_PRIORITY_H
#define __MFC_PRIORITY_H


typedef struct
{
    uint8_t pLevel;//
    uint8_t *is_active;//
}MssgFunc_pLevel_ops;


extern void MssgFuncPrio_Init(MssgFunc_pLevel_ops *ops,uint8_t Number);
extern void Creat_MssgFuncPrio(uint8_t id, uint8_t *RunFlag,uint8_t Level);
extern uint8_t Get_En_MssgFuncPrio(uint8_t ID);













#endif














