/*
 * Gpt_Callout.h
 *
 *  Created on: 2017骞�11鏈�6鏃�
 *      Author: wu
 */

#ifndef TIMER_TIMER_H_
#define TIMER_TIMER_H_

/*=======[E X T E R N A L   V A R I A B L E   D E C L A R A T I O N S]========*/

extern volatile uint8 Gpt_1msFlag;

extern volatile uint8 Gpt_5msFlag;

extern volatile uint8 Gpt_10msFlag;

extern volatile uint8 Gpt_100msFlag;

extern volatile uint8 Gpt_500msFlag;

extern volatile uint8 Gpt_1000msFlag;

typedef uint32 MyTickType;

extern Std_ReturnType MyGetCounterValue(uint16 id, MyTickType* tick);

extern Std_ReturnType MyGetElapsedCounterValue(uint16 id, MyTickType* tick, MyTickType* elapsed);

extern void Gpt_1ms(void);

#endif /* TIMER_TIMER_H_ */
