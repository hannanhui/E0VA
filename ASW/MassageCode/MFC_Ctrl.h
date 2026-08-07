


#ifndef __MFC_CTRL_H_
#define __MFC_CTRL_H_

#include "MFC_Lumbar_Ctrl.h"

#include "MFC_Priority.h"
#include "Massage_MFC_Map.h"
#include "Massage_MFC_Ctrl.h"





typedef enum
{
    FUNC_MASSAGE = 0,
	FUNC_LUMBAR,		
    FUNC_NUM_MAX,
}MFC_Function_Type;


extern BOOL Get_MFC_PumpState(void);
extern void MFC_Ctrl_Init(void);
extern void MFC_Ctrl_Task(void);







#endif





