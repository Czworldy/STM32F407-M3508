#include "all.h"

void IO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	__HAL_RCC_GPIOI_CLK_ENABLE();
	
	GPIO_InitStructure.Pin = GPIO_PIN_6 | GPIO_PIN_7;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Pull = GPIO_NOPULL;
	GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOI, &GPIO_InitStructure);
	
	__HAL_RCC_GPIOE_CLK_ENABLE();
	
	GPIO_InitStructure.Pin = GPIO_PIN_2 | GPIO_PIN_4;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Pull = GPIO_NOPULL;
	GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOE, &GPIO_InitStructure);
	
//	__HAL_RCC_GPIOF_CLK_ENABLE();
//	
//	GPIO_InitStructure.Pin = GPIO_PIN_9 | GPIO_PIN_10;
//	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
//	GPIO_InitStructure.Pull = GPIO_NOPULL;
//	GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
//	HAL_GPIO_Init(GPIOF, &GPIO_InitStructure);
}
void EXTI_Config(void)
{
	GPIO_InitTypeDef GPIO_Initure;
	
    __HAL_RCC_GPIOB_CLK_ENABLE();
	
    GPIO_Initure.Pin = GPIO_PIN_11;
    GPIO_Initure.Mode = GPIO_MODE_IT_FALLING;
    GPIO_Initure.Pull = GPIO_PULLUP;
	GPIO_Initure.Speed = GPIO_SPEED_HIGH;
    HAL_GPIO_Init(GPIOB, &GPIO_Initure);
    
    HAL_NVIC_SetPriority(EXTI15_10_IRQn,2,0);       //抢占优先级为2，子优先级为0
    HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);             //使能中断线
	
}
void EXTI15_10_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    switch (GPIO_Pin)
    {
        case GPIO_PIN_11:
		{
            set_spd[1] = set_loc[1] = 0;
		}
        default:
            break;
    }
}
