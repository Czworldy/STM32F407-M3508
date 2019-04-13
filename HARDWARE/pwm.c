#include "all.h"

#ifdef BSP_USING_PWM1
TIM_HandleTypeDef PWM1_Handler;
TIM_OC_InitTypeDef PWM1_OC_Handler;
#endif

#ifdef BSP_USING_PWM2
TIM_HandleTypeDef PWM2_Handler;
TIM_OC_InitTypeDef PWM2_OC_Handler;
#endif

#ifdef BSP_USING_PWM3
TIM_HandleTypeDef PWM3_Handler;
TIM_OC_InitTypeDef PWM3_OC_Handler;
#endif

#ifdef BSP_USING_PWM4
TIM_HandleTypeDef PWM4_Handler;
TIM_OC_InitTypeDef PWM4_OC_Handler;
#endif

void PWM_Init(void)
{
#ifdef BSP_USING_PWM1
	PWM1_Handler.Instance = PWM1_Instance;
	PWM1_Handler.Init.Prescaler = PWM1_Prescaler;       //定时器分频
	PWM1_Handler.Init.CounterMode = TIM_COUNTERMODE_UP;//向上计数模式
	PWM1_Handler.Init.Period = PWM1_Period;          //自动重装载值
	PWM1_Handler.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	HAL_TIM_PWM_Init(&PWM1_Handler);       //初始化PWM

	PWM1_OC_Handler.OCMode = TIM_OCMODE_PWM1; //模式选择PWM1
	PWM1_OC_Handler.Pulse = PWM1_Pulse;            //设置比较值,此值用来确定占空比
	PWM1_OC_Handler.OCPolarity = TIM_OCPOLARITY_HIGH; //输出比较极性为低 
	HAL_TIM_PWM_ConfigChannel(&PWM1_Handler,&PWM1_OC_Handler,PWM1_Channel);//配置TIM通道
	
	HAL_TIM_PWM_Start(&PWM1_Handler,PWM1_Channel);//开启PWM通道
#endif

#ifdef BSP_USING_PWM2
	PWM2_Handler.Instance = PWM2_Instance;
	PWM2_Handler.Init.Prescaler = PWM2_Prescaler;       //定时器分频
	PWM2_Handler.Init.CounterMode = TIM_COUNTERMODE_UP;//向上计数模式
	PWM2_Handler.Init.Period = PWM2_Period;          //自动重装载值
	PWM2_Handler.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	HAL_TIM_PWM_Init(&PWM2_Handler);       //初始化PWM
	
	PWM2_OC_Handler.OCMode = TIM_OCMODE_PWM1; //模式选择PWM1
	PWM2_OC_Handler.Pulse = PWM2_Pulse;            //设置比较值,此值用来确定占空比
	PWM2_OC_Handler.OCPolarity = TIM_OCPOLARITY_HIGH; //输出比较极性为低 
	HAL_TIM_PWM_ConfigChannel(&PWM2_Handler,&PWM2_OC_Handler,PWM2_Channel);//配置TIM通道
	
	HAL_TIM_PWM_Start(&PWM2_Handler,PWM2_Channel);//开启PWM通道
#endif

#ifdef BSP_USING_PWM3
	PWM3_Handler.Instance = PWM3_Instance;
	PWM3_Handler.Init.Prescaler = PWM3_Prescaler;       //定时器分频
	PWM3_Handler.Init.CounterMode = TIM_COUNTERMODE_UP;//向上计数模式
	PWM3_Handler.Init.Period = PWM3_Period;          //自动重装载值
	PWM3_Handler.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	HAL_TIM_PWM_Init(&PWM3_Handler);       //初始化PWM
	
	PWM3_OC_Handler.OCMode = TIM_OCMODE_PWM1; //模式选择PWM1
	PWM3_OC_Handler.Pulse = PWM3_Pulse;            //设置比较值,此值用来确定占空比
	PWM3_OC_Handler.OCPolarity = TIM_OCPOLARITY_HIGH; //输出比较极性为低 
	HAL_TIM_PWM_ConfigChannel(&PWM3_Handler,&PWM3_OC_Handler,PWM3_Channel);//配置TIM通道
	
	HAL_TIM_PWM_Start(&PWM3_Handler,PWM3_Channel);//开启PWM通道
#endif

#ifdef BSP_USING_PWM4
	PWM4_Handler.Instance = PWM4_Instance;
	PWM4_Handler.Init.Prescaler = PWM4_Prescaler;       //定时器分频
	PWM4_Handler.Init.CounterMode = TIM_COUNTERMODE_UP;//向上计数模式
	PWM4_Handler.Init.Period = PWM4_Period;          //自动重装载值
	PWM4_Handler.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	HAL_TIM_PWM_Init(&PWM4_Handler);       //初始化PWM
	
	PWM4_OC_Handler.OCMode = TIM_OCMODE_PWM1; //模式选择PWM1
	PWM4_OC_Handler.Pulse = PWM4_Pulse;            //设置比较值,此值用来确定占空比
	PWM4_OC_Handler.OCPolarity = TIM_OCPOLARITY_HIGH; //输出比较极性为低 
	HAL_TIM_PWM_ConfigChannel(&PWM4_Handler,&PWM4_OC_Handler,PWM4_Channel);//配置TIM通道
	
	HAL_TIM_PWM_Start(&PWM4_Handler,PWM4_Channel);//开启PWM通道
#endif
}

//定时器底层驱动，时钟使能，引脚配置
//此函数会被HAL_TIM_PWM_Init()调用
//htim:定时器句柄
void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	if (htim == &PWM1_Handler)
	{
		PWM1_TIM_CLK_ENABLE();
		PWM1_GPIO_CLK_ENABLE();
		
		GPIO_InitStructure.Pin = PWM1_PIN;
		GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;  	//复用推挽输出
		GPIO_InitStructure.Pull = GPIO_PULLUP;          //上拉
		GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;     //高速
		GPIO_InitStructure.Alternate= PWM1_GPIO_AF;	//复用
		HAL_GPIO_Init(PWM1_GPIO_PORT, &GPIO_InitStructure);
	}
	else if (htim == &PWM2_Handler)
	{
		PWM2_TIM_CLK_ENABLE();
		PWM2_GPIO_CLK_ENABLE();
		
		GPIO_InitStructure.Pin = PWM2_PIN;
		GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;  	//复用推挽输出
		GPIO_InitStructure.Pull = GPIO_PULLUP;          //上拉
		GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;     //高速
		GPIO_InitStructure.Alternate= PWM2_GPIO_AF;	//复用
		HAL_GPIO_Init(PWM2_GPIO_PORT, &GPIO_InitStructure);
	}
	else if (htim == &PWM3_Handler)
	{
		PWM3_TIM_CLK_ENABLE();
		PWM3_GPIO_CLK_ENABLE();
		
		GPIO_InitStructure.Pin = PWM3_PIN;
		GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;  	//复用推挽输出
		GPIO_InitStructure.Pull = GPIO_PULLUP;          //上拉
		GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;     //高速
		GPIO_InitStructure.Alternate= PWM3_GPIO_AF;	//复用
		HAL_GPIO_Init(PWM3_GPIO_PORT, &GPIO_InitStructure);
	}
	else if (htim == &PWM4_Handler)
	{
		PWM4_TIM_CLK_ENABLE();
		PWM4_GPIO_CLK_ENABLE();
		
		GPIO_InitStructure.Pin = PWM4_PIN;
		GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;  	//复用推挽输出
		GPIO_InitStructure.Pull = GPIO_PULLUP;          //上拉
		GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;     //高速
		GPIO_InitStructure.Alternate= PWM4_GPIO_AF;	//复用
		HAL_GPIO_Init(PWM4_GPIO_PORT, &GPIO_InitStructure);
	}
}
