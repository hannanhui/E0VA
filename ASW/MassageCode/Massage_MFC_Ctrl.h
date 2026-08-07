/*
 * @Author: yinggangzhang yinggangzhang@tangtring.com
 * @Date: 2025-09-17 10:19:21
 * @LastEditors: yinggangzhang yinggangzhang@tangtring.com
 * @LastEditTime: 2025-09-22 14:43:52
 * @FilePath: \MeaaageCode\Massage_Ctrl.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


#ifndef __MASSAGE_CTRL_H_
#define __MASSAGE_CTRL_H_


#include <stdbool.h>
#include "Std_Types.h"





typedef enum
{
	MSSG_CTL_IDLE=0,
    MSSG_RUN,		
    MSSG_STOP,		
    MSSG_FAULT,				
}Massage_State_Type;



typedef struct 
{
    uint32_t Mapping;
    uint8_t Massage_ID;
    Massage_Mode_Type Mode;
    uint8_t Grade;
    uint8_t  Enable :1; 
    Massage_State_Type MssgState;
    uint8_t RunState;

    uint8_t repeat;
    uint16_t ticks;
    uint8_t Curr_Step;
    uint8_t RollStartStep;

    uint8_t  PumpState :1; 
}Massage_Info_Type;

extern void Massage_Init(void);
extern void Set_Massage_Mode(uint8_t mode);
extern void Set_Massage_Grade(uint8_t grade);
extern void Set_Massage_Enable(uint8_t OnOff);
extern BOOL Get_Out_Valve_Map_Bit(BAG_INDEX_TYPE Index);
extern uint8_t* Get_Out_Massage_pRunState(void);

extern BOOL Get_Out_Massage_PumpState(void);
extern void Massage_Task_10ms(void);

#endif




