/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      PwmIf.c                                                                  */
/*   Instance     :                                                                               */
/*   Author       :      Ed                                                                       */
/*   Modify date  :      2025-04-11 11:08:33 AM                                                   */
/*   Description  :                                                                               */
/*                                                                                                */
/*                                                                                                */
/*   Compiler    :       KungFu32 IDE  [Version: V1.0.20.3]                                       */
/*   Hardware    :       ChipOn microcontroller KF32A Family [KF32A136KQT]                        */
/*   Version     :       V1.0                                                                     */
/*                                                                                                */
/*                                                                                                */
/*   All rights reserved. Distribution or duplication without previous written agreement of the   */
/*   owner prohibited.                                                                            */
/*                                                                                                */
/**************************************************************************************************/


#include "Ecal_PWM.h"

static uint8_t CCPInitFlag = FALSE;
static uint8_t EPWMInitFlag = FALSE;

static uint16_t PWM_Period_Spread = VALVE_PWM_OUT_HZ;

//ZYG 20251208
void PWM_IF_PWM_PeriodSet(uint16_t Period)
{
	PWM_Period_Spread = Period;
}


void PWM_IF_PWM_CHANNEL_INDEX0_DutySet(uint16_t Duty)
{
	uint32_t Count = 0;
	uint32_t Period =PWM_OPTPUT_DUTY_MAX_COUNT;
	if (Duty < 0)
	{
		Duty = 0;
	}
	else if (Duty > 1000)
	{
		Duty = 1000;
	}

	Count  = Duty;
	Count *= Period;
	Count /= 1000;
	Pwm_SetPeriodAndDuty(E_PWM_CHANNEL_LIST_INDEX0, PWM_OPTPUT_FREQ_PERIOD, Count);
}
void PWM_IF_PWM_CHANNEL_INDEX1_DutySet(uint16_t Duty)
{
	uint32_t Count = 0;
	uint32_t Period =PWM_OPTPUT_DUTY_MAX_COUNT;
	if (Duty < 0)
	{
		Duty = 0;
	}
	else if (Duty > 1000)
	{
		Duty = 1000;
	}

	Count  = Duty;
	Count *= Period;
	Count /= 1000;
	Pwm_SetPeriodAndDuty(E_PWM_CHANNEL_LIST_INDEX1, PWM_OPTPUT_FREQ_PERIOD, Count);
}
void PWM_IF_PWM_CHANNEL_INDEX2_DutySet(uint16_t Duty)
{
	uint32_t Count = 0;
	uint32_t Period =PWM_OPTPUT_DUTY_MAX_COUNT;
	if (Duty < 0)
	{
		Duty = 0;
	}
	else if (Duty > 1000)
	{
		Duty = 1000;
	}

	Count  = Duty;
	Count *= Period;
	Count /= 1000;
	Pwm_SetPeriodAndDuty(E_PWM_CHANNEL_LIST_INDEX2, PWM_OPTPUT_FREQ_PERIOD, Count);
}
void PWM_IF_PWM_CHANNEL_INDEX3_DutySet(uint16_t Duty)
{
	uint32_t Count = 0;
	uint32_t Period =PWM_OPTPUT_DUTY_MAX_COUNT;
	if (Duty < 0)
	{
		Duty = 0;
	}
	else if (Duty > 1000)
	{
		Duty = 1000;
	}

	Count  = Duty;
	Count *= Period;
	Count /= 1000;
	Pwm_SetPeriodAndDuty(E_PWM_CHANNEL_LIST_INDEX3, PWM_OPTPUT_FREQ_PERIOD, Count);
}
void PWM_IF_PWM_CHANNEL_INDEX4_DutySet(uint16_t Duty)
{
	uint32_t Count = 0;
	uint32_t Period =PWM_OPTPUT_DUTY_MAX_COUNT;
	if (Duty < 0)
	{
		Duty = 0;
	}
	else if (Duty > 1000)
	{
		Duty = 1000;
	}

	Count  = Duty;
	Count *= Period;
	Count /= 1000;
	Pwm_SetPeriodAndDuty(E_PWM_CHANNEL_LIST_INDEX4, PWM_OPTPUT_FREQ_PERIOD, Count);}
void PWM_IF_PWM_CHANNEL_INDEX5_DutySet(uint16_t Duty)
{
	uint32_t Count = 0;
	uint32_t Period =PWM_OPTPUT_DUTY_MAX_COUNT;
	if (Duty < 0)
	{
		Duty = 0;
	}
	else if (Duty > 1000)
	{
		Duty = 1000;
	}

	Count  = Duty;
	Count *= Period;
	Count /= 1000;
	Pwm_SetPeriodAndDuty(E_PWM_CHANNEL_LIST_INDEX5, PWM_OPTPUT_FREQ_PERIOD, Count);
}
void PWM_IF_PWM_CHANNEL_INDEX6_DutySet(uint16_t Duty)
{
	uint32_t Count = 0;
	uint32_t Period =PWM_OPTPUT_DUTY_MAX_COUNT;
	if (Duty < 0)
	{
		Duty = 0;
	}
	else if (Duty > 1000)
	{
		Duty = 1000;
	}

	Count  = Duty;
	Count *= Period;
	Count /= 1000;
	Pwm_SetPeriodAndDuty(E_PWM_CHANNEL_LIST_INDEX6, PWM_OPTPUT_FREQ_PERIOD, Count);
}
void PWM_IF_PWM_CHANNEL_INDEX7_DutySet(uint16_t Duty)
{
	uint32_t Count = 0;
	uint32_t Period =PWM_OPTPUT_DUTY_MAX_COUNT;
	if (Duty < 0)
	{
		Duty = 0;
	}
	else if (Duty > 1000)
	{
		Duty = 1000;
	}

	Count  = Duty;
	Count *= Period;
	Count /= 1000;
	Pwm_SetPeriodAndDuty(E_PWM_CHANNEL_LIST_INDEX7, PWM_OPTPUT_FREQ_PERIOD, Count);
}
void PWM_IF_PWM_CHANNEL_INDEX8_DutySet(uint16_t Duty)
{
	uint32_t Count = 0;
	uint32_t Period =PWM_OPTPUT_DUTY_MAX_COUNT;
	if (Duty < 0)
	{
		Duty = 0;
	}
	else if (Duty > 1000)
	{
		Duty = 1000;
	}

	Count  = Duty;
	Count *= Period;
	Count /= 1000;
	Pwm_SetPeriodAndDuty(E_PWM_CHANNEL_LIST_INDEX8, PWM_OPTPUT_FREQ_PERIOD, Count);
}
uint8_t ErrInEntry0=0;

void PWM_IF_PWM_CHANNEL_INDEX9_DutySet(uint16_t Duty)
{
	uint32_t Count = 0;
	uint32_t Period =PWM_OPTPUT_DUTY_MAX_COUNT;
	if (Duty < 0)
	{
		Duty = 0;
	}
	else if (Duty > 1000)
	{
		Duty = 1000;
	}

	Count  = Duty;
	Count *= Period;
	Count /= 1000;
	Pwm_SetPeriodAndDuty(E_PWM_CHANNEL_LIST_INDEX9, PWM_OPTPUT_FREQ_PERIOD, Count);
}
void PWM_IF_PWM_CHANNEL_INDEX10_DutySet(uint16_t Duty)
{
	uint32_t Count = 0;
	uint32_t Period =PWM_OPTPUT_DUTY_MAX_COUNT;
	if (Duty < 0)
	{
		Duty = 0;
	}
	else if (Duty > 1000)
	{
		Duty = 1000;
	}

	Count  = Duty;
	Count *= Period;
	Count /= 1000;
	Pwm_SetPeriodAndDuty(E_PWM_CHANNEL_LIST_INDEX10, PWM_OPTPUT_FREQ_PERIOD, Count);
}
void PWM_IF_PWM_CHANNEL_INDEX11_DutySet(uint16_t Duty)
{
	uint32_t Count = 0;
	uint32_t Period =PWM_OPTPUT_DUTY_MAX_COUNT;
	if (Duty < 0)
	{
		Duty = 0;
	}
	else if (Duty > 1000)
	{
		Duty = 1000;
	}

	Count  = Duty;
	Count *= Period;
	Count /= 1000;
	Pwm_SetPeriodAndDuty(E_PWM_CHANNEL_LIST_INDEX11, PWM_OPTPUT_FREQ_PERIOD, Count);
}
void PWM_IF_PWM_CHANNEL_INDEX12_DutySet(uint16_t Duty)
{
	uint32_t Count = 0;
	uint32_t Period =PWM_OPTPUT_DUTY_MAX_COUNT;
	if (Duty < 0)
	{
		Duty = 0;
	}
	else if (Duty > 1000)
	{
		Duty = 1000;
	}

	Count  = Duty;
	Count *= Period;
	Count /= 1000;
	Pwm_SetPeriodAndDuty(E_PWM_CHANNEL_LIST_INDEX12, PWM_OPTPUT_FREQ_PERIOD, Count);
}
void PWM_IF_PWM_CHANNEL_INDEX13_DutySet(uint16_t Duty)
{
	uint32_t Count = 0;
	uint32_t Period =PWM_OPTPUT_DUTY_MAX_COUNT;
	if (Duty < 0)
	{
		Duty = 0;
	}
	else if (Duty > 1000)
	{
		Duty = 1000;
	}

	Count  = Duty;
	Count *= Period;
	Count /= 1000;
	Pwm_SetPeriodAndDuty(E_PWM_CHANNEL_LIST_INDEX13, PWM_OPTPUT_FREQ_PERIOD, Count);
}
void PWM_IF_PWM_CHANNEL_INDEX14_DutySet(uint16_t Duty)
{
	uint32_t Count = 0;
	uint32_t Period =PWM_OPTPUT_DUTY_MAX_COUNT;
	if (Duty < 0)
	{
		Duty = 0;
	}
	else if (Duty > 1000)
	{
		Duty = 1000;
	}

	Count  = Duty;
	Count *= Period;
	Count /= 1000;
	Pwm_SetPeriodAndDuty(E_PWM_CHANNEL_LIST_INDEX14, PWM_OPTPUT_FREQ_PERIOD, Count);
}
void PWM_IF_PWM_CHANNEL_INDEX15_DutySet(uint16_t Duty)
{
	uint32_t Count = 0;
	uint32_t Period =PWM_OPTPUT_DUTY_MAX_COUNT;
	if (Duty < 0)
	{
		Duty = 0;
	}
	else if (Duty > 1000)
	{
		Duty = 1000;
	}

	Count  = Duty;
	Count *= Period;
	Count /= 1000;
	Pwm_SetPeriodAndDuty(E_PWM_CHANNEL_LIST_INDEX15, PWM_OPTPUT_FREQ_PERIOD, Count);
}
void PWM_IF_PWM_CHANNEL_INDEX16_DutySet(uint16_t Duty)
{
	uint32_t Count = 0;
	uint32_t Period =PWM_OPTPUT_DUTY_MAX_COUNT;
	if (Duty < 0)
	{
		Duty = 0;
	}
	else if (Duty > 1000)
	{
		Duty = 1000;
	}

	Count  = Duty;
	Count *= Period;
	Count /= 1000;
	Pwm_SetPeriodAndDuty(E_PWM_CHANNEL_LIST_INDEX16, PWM_OPTPUT_FREQ_PERIOD, Count);
}
void PWM_IF_PWM_CHANNEL_INDEX17_DutySet(uint16_t Duty)
{
	uint32_t Count = 0;
	uint32_t Period =PWM_OPTPUT_DUTY_MAX_COUNT;
	if (Duty < 0)
	{
		Duty = 0;
	}
	else if (Duty > 1000)
	{
		Duty = 1000;
	}

	Count  = Duty;
	Count *= Period;
	Count /= 1000;
	Pwm_SetPeriodAndDuty(E_PWM_CHANNEL_LIST_INDEX17, PWM_OPTPUT_FREQ_PERIOD, Count);
}
void PWM_IF_PWM_CHANNEL_INDEX18_DutySet(uint16_t Duty)
{
	uint32_t Count = 0;
	uint32_t Period =PWM_OPTPUT_DUTY_MAX_COUNT;
	if (Duty < 0)
	{
		Duty = 0;
	}
	else if (Duty > 1000)
	{
		Duty = 1000;
	}

	Count  = Duty;
	Count *= Period;
	Count /= 1000;
	Pwm_SetPeriodAndDuty(E_PWM_CHANNEL_LIST_INDEX18, PWM_OPTPUT_FREQ_PERIOD, Count);
}
void PWM_IF_PWM_CHANNEL_INDEX19_DutySet(uint16_t Duty)
{
	uint32_t Count = 0;
	uint32_t Period =PWM_OPTPUT_DUTY_MAX_COUNT;
	if (Duty < 0)
	{
		Duty = 0;
	}
	else if (Duty > 1000)
	{
		Duty = 1000;
	}

	Count  = Duty;
	Count *= Period;
	Count /= 1000;
	Pwm_SetPeriodAndDuty(E_PWM_CHANNEL_LIST_INDEX19, PWM_OPTPUT_FREQ_PERIOD, Count);
}
void PWM_IF_PWM_CHANNEL_INDEX20_DutySet(uint16_t Duty)
{
	uint32_t Count = 0;
	uint32_t Period =PWM_OPTPUT_DUTY_MAX_COUNT;
	if (Duty < 0)
	{
		Duty = 0;
	}
	else if (Duty > 1000)
	{
		Duty = 1000;
	}

	Count  = Duty;
	Count *= Period;
	Count /= 1000;
	Pwm_SetPeriodAndDuty(E_PWM_CHANNEL_LIST_INDEX20, PWM_OPTPUT_FREQ_PERIOD, Count);
}


void PWM_IF_PWM_CHANNEL_INDEX21_DutySet(uint16_t Duty)
{
	uint32_t Count = 0;
	uint32_t Period =PWM_OPTPUT_DUTY_MAX_COUNT;
	if (Duty < 0)
	{
		Duty = 0;
	}
	else if (Duty > 1000)
	{
		Duty = 1000;
	}

	Count  = Duty;
	Count *= Period;
	Count /= 1000;
	Pwm_SetPeriodAndDuty(E_PWM_CHANNEL_LIST_INDEX21, PWM_OPTPUT_FREQ_PERIOD, Count);
}

void PWM_IF_PWM_CHANNEL_INDEX22_DutySet(uint16_t Duty)
{
	uint32_t Count = 0;
	uint32_t Period =PWM_OPTPUT_DUTY_MAX_COUNT;
	if (Duty < 0)
	{
		Duty = 0;
	}
	else if (Duty > 1000)
	{
		Duty = 1000;
	}

	Count  = Duty;
	Count *= Period;
	Count /= 1000;
	Pwm_SetPeriodAndDuty(E_PWM_CHANNEL_LIST_INDEX22, PWM_OPTPUT_FREQ_PERIOD, Count);
}
void PWM_IF_PWM_CHANNEL_INDEX23_DutySet(uint16_t Duty)
{
	uint32_t Count = 0;
	uint32_t Period =PWM_OPTPUT_DUTY_MAX_COUNT;
	if (Duty < 0)
	{
		Duty = 0;
	}
	else if (Duty > 1000)
	{
		Duty = 1000;
	}

	Count  = Duty;
	Count *= Period;
	Count /= 1000;
	Pwm_SetPeriodAndDuty(E_PWM_CHANNEL_LIST_INDEX23, PWM_OPTPUT_FREQ_PERIOD, Count);
	
}
void PWM_IF_PWM_CHANNEL_INDEX24_DutySet(uint16_t Duty)
{
	uint32_t Count = 0;
	uint32_t Period =PWM_OPTPUT_DUTY_MAX_COUNT;
	if (Duty < 0)
	{
		Duty = 0;
	}
	else if (Duty > 1000)
	{
		Duty = 1000;
	}

	Count  = Duty;
	Count *= Period;
	Count /= 1000;
	Pwm_SetPeriodAndDuty(E_PWM_CHANNEL_LIST_INDEX24, PWM_OPTPUT_FREQ_PERIOD, Count);
}
void PWM_IF_PWM_CHANNEL_INDEX25_DutySet(uint16_t Duty)
{
	uint32_t Count = 0;
	uint32_t Period =PWM_OPTPUT_DUTY_MAX_COUNT;
	if (Duty < 0)
	{
		Duty = 0;
	}
	else if (Duty > 1000)
	{
		Duty = 1000;
	}

	Count  = Duty;
	Count *= Period;
	Count /= 1000;
	Pwm_SetPeriodAndDuty(E_PWM_CHANNEL_LIST_INDEX25, PWM_OPTPUT_FREQ_PERIOD, Count);
}
void PWM_IF_PWM_CHANNEL_INDEX26_DutySet(uint16_t Duty)
{
	uint32_t Count = 0;
	uint32_t Period =PWM_OPTPUT_DUTY_MAX_COUNT;
	if (Duty < 0)
	{
		Duty = 0;
	}
	else if (Duty > 1000)
	{
		Duty = 1000;
	}

	Count  = Duty;
	Count *= Period;
	Count /= 1000;
	Pwm_SetPeriodAndDuty(E_PWM_CHANNEL_LIST_INDEX26, PWM_OPTPUT_FREQ_PERIOD, Count);
}
void PWM_IF_PWM_CHANNEL_INDEX27_DutySet(uint16_t Duty)
{
	uint32_t Count = 0;
	uint32_t Period =PWM_OPTPUT_DUTY_MAX_COUNT;
	if (Duty < 0)
	{
		Duty = 0;
	}
	else if (Duty > 1000)
	{
		Duty = 1000;
	}

	Count  = Duty;
	Count *= Period;
	Count /= 1000;
	Pwm_SetPeriodAndDuty(E_PWM_CHANNEL_LIST_INDEX27, PWM_OPTPUT_FREQ_PERIOD, Count);
}
void PWM_IF_PWM_CHANNEL_INDEX28_DutySet(uint16_t Duty)
{
	uint32_t Count = 0;
	uint32_t Period =PWM_OPTPUT_DUTY_MAX_COUNT;
	if (Duty < 0)
	{
		Duty = 0;
	}
	else if (Duty > 1000)
	{
		Duty = 1000;
	}

	Count  = Duty;
	Count *= Period;
	Count /= 1000;
	Pwm_SetPeriodAndDuty(E_PWM_CHANNEL_LIST_INDEX28, PWM_OPTPUT_FREQ_PERIOD, Count);
}
void PWM_IF_PWM_CHANNEL_INDEX29_DutySet(uint16_t Duty)
{
	uint32_t Count = 0;
	uint32_t Period =PWM_OPTPUT_DUTY_MAX_COUNT;
	if (Duty < 0)
	{
		Duty = 0;
	}
	else if (Duty > 1000)
	{
		Duty = 1000;
	}

	Count  = Duty;
	Count *= Period;
	Count /= 1000;
	Pwm_SetPeriodAndDuty(E_PWM_CHANNEL_LIST_INDEX29, PWM_OPTPUT_FREQ_PERIOD, Count);
}
void PWM_IF_PWM_CHANNEL_INDEX30_DutySet(uint16_t Duty)
{
	uint32_t Count = 0;
	uint32_t Period =PWM_OPTPUT_DUTY_MAX_COUNT;
	if (Duty < 0)
	{
		Duty = 0;
	}
	else if (Duty > 1000)
	{
		Duty = 1000;
	}

	Count  = Duty;
	Count *= Period;
	Count /= 1000;
	Pwm_SetPeriodAndDuty(E_PWM_CHANNEL_LIST_INDEX30, PWM_OPTPUT_FREQ_PERIOD, Count);
}


void PWM_IF_PWM_CHANNEL_INDEX31_DutySet(uint16_t Duty)
{
	uint32_t Count = 0;
	uint32_t Period =PWM_OPTPUT_DUTY_MAX_COUNT;
	if (Duty < 0)
	{
		Duty = 0;
	}
	else if (Duty > 1000)
	{
		Duty = 1000;
	}

	Count  = Duty;
	Count *= Period;
	Count /= 1000;
	Pwm_SetPeriodAndDuty(E_PWM_CHANNEL_LIST_INDEX31, PWM_OPTPUT_FREQ_PERIOD, Count);
}

void PWM_IF_PWM_DutySet(E_PWM_CHANNEL_LIST ChannelIndex ,uint16_t Duty)
{

		switch(ChannelIndex)
		{
			case E_PWM_CHANNEL_LIST_INDEX0:
					 PWM_IF_PWM_CHANNEL_INDEX0_DutySet(Duty);
				break;
			case E_PWM_CHANNEL_LIST_INDEX1:
					 PWM_IF_PWM_CHANNEL_INDEX1_DutySet(Duty);
				break;
			case E_PWM_CHANNEL_LIST_INDEX2:
					 PWM_IF_PWM_CHANNEL_INDEX2_DutySet(Duty);
				break;
			case E_PWM_CHANNEL_LIST_INDEX3:
					 PWM_IF_PWM_CHANNEL_INDEX3_DutySet(Duty);
				break;
			case E_PWM_CHANNEL_LIST_INDEX4:
					 PWM_IF_PWM_CHANNEL_INDEX4_DutySet(Duty);
				break;
			case E_PWM_CHANNEL_LIST_INDEX5:
					 PWM_IF_PWM_CHANNEL_INDEX5_DutySet(Duty);
				break;
			case E_PWM_CHANNEL_LIST_INDEX6:
					 PWM_IF_PWM_CHANNEL_INDEX6_DutySet(Duty);
				break;
			case E_PWM_CHANNEL_LIST_INDEX7:
					 PWM_IF_PWM_CHANNEL_INDEX7_DutySet(Duty);
				break;
			case E_PWM_CHANNEL_LIST_INDEX8:
					 PWM_IF_PWM_CHANNEL_INDEX8_DutySet(Duty);
				break;
			case E_PWM_CHANNEL_LIST_INDEX9:
					 PWM_IF_PWM_CHANNEL_INDEX9_DutySet(Duty);
				break;
			case E_PWM_CHANNEL_LIST_INDEX10:
					 PWM_IF_PWM_CHANNEL_INDEX10_DutySet(Duty);
				break;
			case E_PWM_CHANNEL_LIST_INDEX11:
					 PWM_IF_PWM_CHANNEL_INDEX11_DutySet(Duty);
				break;
			case E_PWM_CHANNEL_LIST_INDEX12:
					 PWM_IF_PWM_CHANNEL_INDEX12_DutySet(Duty);
				break;
			case E_PWM_CHANNEL_LIST_INDEX13:
					 PWM_IF_PWM_CHANNEL_INDEX13_DutySet(Duty);
				break;
			case E_PWM_CHANNEL_LIST_INDEX14:
					 PWM_IF_PWM_CHANNEL_INDEX14_DutySet(Duty);
				break;
			case E_PWM_CHANNEL_LIST_INDEX15:
					 PWM_IF_PWM_CHANNEL_INDEX15_DutySet(Duty);
				break;
			case E_PWM_CHANNEL_LIST_INDEX16:
					 PWM_IF_PWM_CHANNEL_INDEX16_DutySet(Duty);
				break;
			case E_PWM_CHANNEL_LIST_INDEX17:
					 PWM_IF_PWM_CHANNEL_INDEX17_DutySet(Duty);
				break;
			case E_PWM_CHANNEL_LIST_INDEX18:
					 PWM_IF_PWM_CHANNEL_INDEX18_DutySet(Duty);
				break;
			case E_PWM_CHANNEL_LIST_INDEX19:
					 PWM_IF_PWM_CHANNEL_INDEX19_DutySet(Duty);
				break;
			case E_PWM_CHANNEL_LIST_INDEX20:
					 PWM_IF_PWM_CHANNEL_INDEX20_DutySet(Duty);
				break;
			case E_PWM_CHANNEL_LIST_INDEX21:
					 PWM_IF_PWM_CHANNEL_INDEX21_DutySet(Duty);
				break;
			case E_PWM_CHANNEL_LIST_INDEX22:
					 PWM_IF_PWM_CHANNEL_INDEX22_DutySet(Duty);
				break;
			case E_PWM_CHANNEL_LIST_INDEX23:
					 PWM_IF_PWM_CHANNEL_INDEX23_DutySet(Duty);
				break;
			case E_PWM_CHANNEL_LIST_INDEX24:
					 PWM_IF_PWM_CHANNEL_INDEX24_DutySet(Duty);
				break;
			case E_PWM_CHANNEL_LIST_INDEX25:
					 PWM_IF_PWM_CHANNEL_INDEX25_DutySet(Duty);
				break;
			case E_PWM_CHANNEL_LIST_INDEX26:
					 PWM_IF_PWM_CHANNEL_INDEX26_DutySet(Duty);
				break;
			case E_PWM_CHANNEL_LIST_INDEX27:
					 PWM_IF_PWM_CHANNEL_INDEX27_DutySet(Duty);
				break;
			case E_PWM_CHANNEL_LIST_INDEX28:
					 PWM_IF_PWM_CHANNEL_INDEX28_DutySet(Duty);
				break;
			case E_PWM_CHANNEL_LIST_INDEX29:
					 PWM_IF_PWM_CHANNEL_INDEX29_DutySet(Duty);
				break;
			case E_PWM_CHANNEL_LIST_INDEX30:
					 PWM_IF_PWM_CHANNEL_INDEX30_DutySet(Duty);
				break;
			case E_PWM_CHANNEL_LIST_INDEX31:
					 PWM_IF_PWM_CHANNEL_INDEX31_DutySet(Duty);
				break;
			default:
				break;
		}
		
}





void PWM_IF_DeInit(void)
{
	Pwm_DeInit();
	EPWMInitFlag = FALSE;
	CCPInitFlag = FALSE;
}

void PWM_IF_Init(void)
{
	
	Pwm_Init(NULL_PTR);
	EPWMInitFlag = TRUE;
	CCPInitFlag = TRUE;
}






