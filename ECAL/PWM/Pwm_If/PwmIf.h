/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      PwmIf.h                                                                  */
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
#ifndef PWM_IF_H_
#define PWM_IF_H_


extern void PWM_IF_DeInit(void);

extern void PWM_IF_Init(void);

/*******************************************************************************
*Name        : PWM_IF_PWM_DutySet
*Function    : Pwm Duty Ctrl
*argument    : opIndex - E_PWM_CHANNEL_LIST Index(Max 24 channel) 
*					E_PWM_CHANNEL_LIST_INDEX0   ===>
					E_PWM_CHANNEL_LIST_INDEX1,  ===>	
					E_PWM_CHANNEL_LIST_INDEX2,  ===>
					E_PWM_CHANNEL_LIST_INDEX3,  ===>
					E_PWM_CHANNEL_LIST_INDEX4,  ===>
					E_PWM_CHANNEL_LIST_INDEX5,  ===>
					E_PWM_CHANNEL_LIST_INDEX6,  ===>
					E_PWM_CHANNEL_LIST_INDEX7,  ===>
					E_PWM_CHANNEL_LIST_INDEX8,  ===>
					E_PWM_CHANNEL_LIST_INDEX9,  ===>
					E_PWM_CHANNEL_LIST_INDEX10, ===>
					E_PWM_CHANNEL_LIST_INDEX11, ===>
					E_PWM_CHANNEL_LIST_INDEX12, ===>
					E_PWM_CHANNEL_LIST_INDEX13, ===>
					E_PWM_CHANNEL_LIST_INDEX14, ===>
					E_PWM_CHANNEL_LIST_INDEX15, ===>
					E_PWM_CHANNEL_LIST_INDEX16, ===>
					E_PWM_CHANNEL_LIST_INDEX17, ===>
					E_PWM_CHANNEL_LIST_INDEX18, ===>
					E_PWM_CHANNEL_LIST_INDEX19, ===>
					E_PWM_CHANNEL_LIST_INDEX20, ===>
					E_PWM_CHANNEL_LIST_INDEX21, ===>
					E_PWM_CHANNEL_LIST_INDEX22, ===>
					E_PWM_CHANNEL_LIST_INDEX23,	===>
					E_PWM_CHANNEL_LIST_INDEX24, ===>
					E_PWM_CHANNEL_LIST_INDEX25, ===>
					E_PWM_CHANNEL_LIST_INDEX26, ===>
					E_PWM_CHANNEL_LIST_INDEX27, ===>
					E_PWM_CHANNEL_LIST_INDEX28, ===>
					E_PWM_CHANNEL_LIST_INDEX29, ===>
					E_PWM_CHANNEL_LIST_INDEX30, ===>
					E_PWM_CHANNEL_LIST_INDEX31, ===>
*			   Duty - Pwm Set Duty
*			   			FALSE - index corresponding to the valve Off
*			   			TRUE  - index corresponding to the valve On
*Retval      : NONE
*explain     : If Valve Driving by pwm alone:
					Valve use Pwm driving
				  	Valve Power supply use Batt+ driving
				  	opIndex corresponding to the hardware PWM channel
			   If Valve Driving by Pwm union i/o:
			   		Valve use I/O driving
				  	Valve Power supply use PWM driving
			   		opIndex corresponding to the hardware I/O
			   If Valve Driving by i/o alone:
			   		Valve use I/O driving
				  	Valve Power supply use Batt+ driving
				  	opIndex corresponding to the hardware I/O
*******************************************************************************/

extern void PWM_IF_PWM_DutySet(E_PWM_CHANNEL_LIST ChannelIndex ,uint16_t Duty);
extern void PWM_IF_PWM_PeriodSet(uint16_t Period);



#endif /* PORT_IF_H_ */


