#ifndef _PWM_H
#define _PWM_H

#include "stm32f4xx.h"

#define BSP_USING_PWM1
#define BSP_USING_PWM2
#define BSP_USING_PWM3
#define BSP_USING_PWM4

#ifdef BSP_USING_PWM1
#define PWM1_Instance							TIM9
#define PWM1_Prescaler						167
#define PWM1_Period								999
#define PWM1_Pulse								200
#define PWM1_Channel							TIM_CHANNEL_2
#define PWM1_TIM_CLK_ENABLE()			__HAL_RCC_TIM9_CLK_ENABLE()
#define PWM1_GPIO_CLK_ENABLE()		__HAL_RCC_GPIOE_CLK_ENABLE()
#define PWM1_PIN 									GPIO_PIN_6
#define PWM1_GPIO_AF 							GPIO_AF3_TIM9
#define PWM1_GPIO_PORT 						GPIOE
extern TIM_HandleTypeDef PWM1_Handler;
extern TIM_OC_InitTypeDef PWM1_OC_Handler;
#endif

#ifdef BSP_USING_PWM2
#define PWM2_Instance							TIM9
#define PWM2_Prescaler						167
#define PWM2_Period								999
#define PWM2_Pulse								200
#define PWM2_Channel							TIM_CHANNEL_1
#define PWM2_TIM_CLK_ENABLE()			__HAL_RCC_TIM9_CLK_ENABLE()
#define PWM2_GPIO_CLK_ENABLE()		__HAL_RCC_GPIOE_CLK_ENABLE()
#define PWM2_PIN 									GPIO_PIN_5
#define PWM2_GPIO_AF 							GPIO_AF3_TIM9
#define PWM2_GPIO_PORT 						GPIOE
extern TIM_HandleTypeDef PWM2_Handler;
extern TIM_OC_InitTypeDef PWM2_OC_Handler;
#endif

#ifdef BSP_USING_PWM3
#define PWM3_Instance							TIM3
#define PWM3_Prescaler						83
#define PWM3_Period								999
#define PWM3_Pulse								200
#define PWM3_Channel							TIM_CHANNEL_2
#define PWM3_TIM_CLK_ENABLE()			__HAL_RCC_TIM3_CLK_ENABLE()
#define PWM3_GPIO_CLK_ENABLE()		__HAL_RCC_GPIOB_CLK_ENABLE()
#define PWM3_PIN 									GPIO_PIN_5
#define PWM3_GPIO_AF 							GPIO_AF2_TIM3
#define PWM3_GPIO_PORT 						GPIOB
extern TIM_HandleTypeDef PWM2_Handler;
extern TIM_HandleTypeDef PWM3_Handler;
extern TIM_OC_InitTypeDef PWM3_OC_Handler;
#endif

#ifdef BSP_USING_PWM4
#define PWM4_Instance							TIM3
#define PWM4_Prescaler						83
#define PWM4_Period								999
#define PWM4_Pulse								200
#define PWM4_Channel							TIM_CHANNEL_1
#define PWM4_TIM_CLK_ENABLE()			__HAL_RCC_TIM3_CLK_ENABLE()
#define PWM4_GPIO_CLK_ENABLE()		__HAL_RCC_GPIOB_CLK_ENABLE()
#define PWM4_PIN 									GPIO_PIN_4
#define PWM4_GPIO_AF 							GPIO_AF2_TIM3
#define PWM4_GPIO_PORT 						GPIOB
extern TIM_HandleTypeDef PWM4_Handler;
extern TIM_OC_InitTypeDef PWM4_OC_Handler;
#endif

void PWM_Init(void);

#endif
