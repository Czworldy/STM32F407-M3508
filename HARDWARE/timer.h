#ifndef _TIMER_H
#define _TIMER_H
#include "all.h"
extern TIM_HandleTypeDef TIM2_Handler;      //¶¨Ê±Æ÷¾ä±ú 
extern  int64_t time;
void TIM2_Init(u16 arr,u16 psc);

#endif

