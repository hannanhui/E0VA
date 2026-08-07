/*
 * @Author: yinggangzhang yinggangzhang@tangtring.com
 * @Date: 2025-10-27 16:29:06
 * @LastEditors: yinggangzhang yinggangzhang@tangtring.com
 * @LastEditTime: 2025-10-27 16:34:08
 * @FilePath: \Source\APP\MFC\MFC_Lumbar_Ctrl.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#ifndef MFC_LUMBAR_CTRL_H_
#define MFC_LUMBAR_CTRL_H_

#define LUMB_INFLATE_TIMER_MAX  1500U //10ms
#define LUMB_DEFLATE_TIMER_MAX  6000U //10ms

#define LUMB_PROTECT_PRESSURE   45000U



#define LUMB_BAG_NUM  2U

typedef enum
{
    LumbFunc_IDLE,
	LumbFunc_UP,
    LumbFunc_DOWN,
    LumbFunc_FWD,
    LumbFunc_RWD,	
    LumbFunc_MAX,
}Lumbar_Func_Type;


typedef enum
{
    LumbState_IDLE,
	LumbState_RUN,
	LumbState_END,
	LumbState_FAULT,
}Lumbar_RunState_Type;



typedef enum
{
    LumbBag_IDLE,
	LumbBag_Inflate,
    LumbBag_Deflate,				
}Lumbar_BagRun_Type;

typedef enum
{
    Lumb_UP = 0,
	Lumb_DOWN,	
    Lumb_OTHER,		
}Lumbar_BagNum_Type;

typedef struct 
{
    Lumbar_BagRun_Type BagState;
    uint32_t Presure;
    uint16_t  ticks; //step time
}Lumbar_Bag_Info_Type;

typedef struct 
{
    Lumbar_Bag_Info_Type Bag_Info[LUMB_BAG_NUM];
    Lumbar_Func_Type Lumbar_Func;
    Lumbar_RunState_Type Lumbar_State;
    uint16_t Bag_Timer;
    uint8_t  PumpState :1; 
    uint8_t RunFlag ;
}Lumbar_Info_Type;

extern void Lumbar_Task(void);
extern void Lumbar_Init(void);
extern uint8_t* Get_Lumbar_pRunState(void);
extern Lumbar_BagRun_Type Get_LumbarBagState(Lumbar_BagNum_Type Index);
extern void Set_Lumbar_Pressure(Lumbar_BagNum_Type Index,uint32_t u32Value);
extern void Set_Lumbar_Function(uint8 u8Value);
#endif




