#include "all.h"

TIM_HandleTypeDef TIM2_Handler;      //定时器句柄 

int64_t time = 0;
//通用定时器2中断初始化
//arr：自动重装值。
//psc：时钟预分频数
//定时器溢出时间计算方法:Tout=((arr+1)*(psc+1))/Ft us.
//Ft=定时器工作频率,单位:Mhz
//这里使用的是定时器2!(定时器2挂在APB1上，时钟为HCLK/2)
void TIM2_Init(u16 arr,u16 psc)
{  
	TIM2_Handler.Instance = TIM2;                          //通用定时器2
	TIM2_Handler.Init.Prescaler = psc;                     //分频系数
	TIM2_Handler.Init.CounterMode = TIM_COUNTERMODE_UP;    //向上计数器
	TIM2_Handler.Init.Period = arr;                        //自动装载值
	TIM2_Handler.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;//时钟分频因子
	HAL_TIM_Base_Init(&TIM2_Handler);
	
	HAL_TIM_Base_Start_IT(&TIM2_Handler); //使能定时器2和定时器2更新中断：TIM_IT_UPDATE   
}

//定时器底册驱动，开启时钟，设置中断优先级
//此函数会被HAL_TIM_Base_Init()函数调用
void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim)
{
  if(htim->Instance == TIM2)
	{
		__HAL_RCC_TIM2_CLK_ENABLE();            //使能TIM2时钟
		HAL_NVIC_SetPriority(TIM2_IRQn,3,3);    //设置中断优先级，抢占优先级1，子优先级1
		HAL_NVIC_EnableIRQ(TIM2_IRQn);          //开启TIM2中断   
		__HAL_TIM_DISABLE(&TIM2_Handler);
		time = 0;
		TIM2_Handler.Instance->CNT = 0; //定时器归零
	}
}


//定时器2中断服务函数
void TIM2_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&TIM2_Handler);
}

//回调函数，定时器中断服务函数调用
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim == (&TIM2_Handler))
	{
		++time;
	}
}
