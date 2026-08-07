

#ifndef _FUNCTION_KEY_H_
#define _FUNCTION_KEY_H_

/* 气袋工作模式 */
typedef enum {
  LumbarKey_IDLE = 0,                   /* Default value */
  LumbarKey_UP,
  LumbarKey_DOWN,
  LumbarKey_FWD,
  LumbarKey_RWD,
  LumbarKey_MID,
  LumbarKey_MAX,
} Lumbar_Key_Type;


/**
* @details	   AD deal info. 
*/
typedef struct
{
	uint16_t Adc_MIN;
	uint16_t Adc_MAX;
	uint16_t Key_Id;
}Adc_Key_Info_type;




extern Lumbar_Key_Type Get_Lumbar_Key_Value(void);

extern void Function_Key_Timer10ms(void);
extern void Function_Key_Init(void);










#endif



