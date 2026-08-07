

#include "include.h"
#include "multi_button.h"

static Button Lumbar_Btn[LumbarKey_MAX];
Lumbar_Key_Type LumbarKeyValue = LumbarKey_IDLE;
static Lumbar_Key_Type AD_Key_Value = LumbarKey_IDLE;

const  Adc_Key_Info_type Adc_Key_Table[LumbarKey_MAX -1] =
{
	{700U,1300U,LumbarKey_UP},
	{1500U,2100U,LumbarKey_DOWN},
	{2300U,3000U,LumbarKey_RWD},
	{0U,500U,LumbarKey_FWD},
	{3100U,3900U,LumbarKey_MID},
};


/**
* @brief	   读取按键AD
* @details	   This is the detail description. 
* @par 修改日志
*	   ZYG于2025/09/16创建
*/
static void Lumbar_Key_AD_Deal(void)
{
		uint8_t i = 0;
		uint16_t Key_adc;
		AD_Key_Value = LumbarKey_IDLE;
	Key_adc = DigitalIf_Adc_DataGet(Digital_Adc_Index6);
	
	for(i=0;i<(LumbarKey_MAX -1);i++)
		{
		if(Key_adc>=Adc_Key_Table[i].Adc_MIN && Key_adc<Adc_Key_Table[i].Adc_MAX)
			{
			AD_Key_Value = Adc_Key_Table[i].Key_Id;
			break;
			}
		
		}
}


/**
* @brief	   读取按键触发
* @details	   This is the detail description. 
* @retval	   按键键值
* @par 修改日志
*	   ZYG于2025/09/16创建
*/
uint8_t Read_Key_Value(uint8_t button_id)
{
	 
	switch (button_id) {
        case LumbarKey_IDLE:
            return (AD_Key_Value == LumbarKey_IDLE)?TRUE:FALSE;
        case LumbarKey_UP:
            return (AD_Key_Value == LumbarKey_UP)?TRUE:FALSE;
		case LumbarKey_DOWN:
            return (AD_Key_Value == LumbarKey_DOWN)?TRUE:FALSE;
		case LumbarKey_RWD:
            return (AD_Key_Value == LumbarKey_RWD)?TRUE:FALSE;
		case LumbarKey_FWD:
            return (AD_Key_Value == LumbarKey_FWD)?TRUE:FALSE;
		case LumbarKey_MID:
            return (AD_Key_Value == LumbarKey_MID)?TRUE:FALSE;	
        default:
            return 0;
		}
}


/**
* @brief	   按键空闲状态
* @details	   This is the detail description. 
* @retval	   按键键值
* @par 修改日志
*	   ZYG于2025/09/16创建
*/
Lumbar_Key_Type Get_Lumbar_Key_Value(void)
{
return LumbarKeyValue;
}



/**
* @brief	   按键空闲状态
* @details	   callback function
* @par 修改日志
*	   ZYG于2025/09/16创建
*/
void Lumbar_key_IDLE(void)
{
	//(void)btn;	// suppress unused parameter warning
	LumbarKeyValue = LumbarKey_IDLE;
}

/**
* @brief	   UP按键
* @details	   callback function
* @par 修改日志
*	   ZYG于2025/09/16创建
*/
void Lumbar_key_UP(void)
{
	//(void)btn;	// suppress unused parameter warning
	LumbarKeyValue = LumbarKey_UP;
}


/**
* @brief	   DOWN按键
* @details	   callback function
* @par 修改日志
*	   ZYG于2025/09/16创建
*/
void Lumbar_key_DOWN(void)
{
	//(void)btn;	// suppress unused parameter warning
	LumbarKeyValue = LumbarKey_DOWN;
}

/**
* @brief	   RWD按键
* @details	  callback function
* @par 修改日志
*	   ZYG于2025/09/16创建
*/
void Lumbar_key_RWD(void)
{
	//(void)btn;	// suppress unused parameter warning
	LumbarKeyValue = LumbarKey_RWD;
}

/**
* @brief	   FWD按键
* @details	   callback function
* @par 修改日志
*	   ZYG于2025/09/16创建
*/
void Lumbar_key_FWD(void)
{
	//(void)btn;	// suppress unused parameter warning
	LumbarKeyValue = LumbarKey_FWD;
}


/**
* @brief	   MID按键
* @details	   This is the detail description. 
* @par 修改日志
*	   ZYG于2025/09/16创建
*/

void Lumbar_key_MID(void)
{
	//(void)btn;	// suppress unused parameter warning
	LumbarKeyValue = LumbarKey_MID;
}






/**
* @brief	   按键初始化
* @details	   This is the detail description. 
* @par 修改日志
*	   ZYG于2025/09/16创建
*/
void Function_Key_Init(void)
{
	button_init(&Lumbar_Btn[LumbarKey_IDLE], Read_Key_Value, TRUE, LumbarKey_IDLE);
	button_init(&Lumbar_Btn[LumbarKey_UP], Read_Key_Value, TRUE, LumbarKey_UP);
	button_init(&Lumbar_Btn[LumbarKey_DOWN], Read_Key_Value, TRUE, LumbarKey_DOWN);
	button_init(&Lumbar_Btn[LumbarKey_RWD], Read_Key_Value, TRUE, LumbarKey_RWD);
	button_init(&Lumbar_Btn[LumbarKey_FWD], Read_Key_Value, TRUE, LumbarKey_FWD);
	button_init(&Lumbar_Btn[LumbarKey_MID], Read_Key_Value, TRUE, LumbarKey_MID);

//	button_attach(&Lumbar_Btn[LumbarKey_IDLE], BTN_PRESS_DOWN, Lumbar_key_IDLE);
//	button_attach(&Lumbar_Btn[LumbarKey_UP], BTN_PRESS_DOWN, Lumbar_key_UP);
//	button_attach(&Lumbar_Btn[LumbarKey_DOWN], BTN_PRESS_DOWN, Lumbar_key_DOWN);
//	button_attach(&Lumbar_Btn[LumbarKey_RWD], BTN_PRESS_DOWN, Lumbar_key_RWD);
//	button_attach(&Lumbar_Btn[LumbarKey_FWD], BTN_PRESS_DOWN, Lumbar_key_FWD);
//	button_attach(&Lumbar_Btn[LumbarKey_MID], BTN_PRESS_DOWN, Lumbar_key_MID);

	button_start(&Lumbar_Btn[LumbarKey_IDLE]);
    button_start(&Lumbar_Btn[LumbarKey_UP]);
	button_start(&Lumbar_Btn[LumbarKey_DOWN]);
	button_start(&Lumbar_Btn[LumbarKey_RWD]);
	button_start(&Lumbar_Btn[LumbarKey_FWD]);
	button_start(&Lumbar_Btn[LumbarKey_MID]);
}




/**
* @brief	   按键10ms
* @details	   This is the detail description. 
* @par 修改日志
*	   ZYG于2025/09/16创建
*/
void Function_Key_Timer10ms(void)
{
	Lumbar_Key_AD_Deal();
	button_ticks();
}



