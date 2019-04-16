#include "all.h"

TIM_HandleTypeDef TIM2_Handler;      //��ʱ����� 

int64_t time = 0;
//ͨ�ö�ʱ��2�жϳ�ʼ��
//arr���Զ���װֵ��
//psc��ʱ��Ԥ��Ƶ��
//��ʱ�����ʱ����㷽��:Tout=((arr+1)*(psc+1))/Ft us.
//Ft=��ʱ������Ƶ��,��λ:Mhz
//����ʹ�õ��Ƕ�ʱ��2!(��ʱ��2����APB1�ϣ�ʱ��ΪHCLK/2)
void TIM2_Init(u16 arr,u16 psc)
{  
	TIM2_Handler.Instance = TIM2;                          //ͨ�ö�ʱ��2
	TIM2_Handler.Init.Prescaler = psc;                     //��Ƶϵ��
	TIM2_Handler.Init.CounterMode = TIM_COUNTERMODE_UP;    //���ϼ�����
	TIM2_Handler.Init.Period = arr;                        //�Զ�װ��ֵ
	TIM2_Handler.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;//ʱ�ӷ�Ƶ����
	HAL_TIM_Base_Init(&TIM2_Handler);
	
	HAL_TIM_Base_Start_IT(&TIM2_Handler); //ʹ�ܶ�ʱ��2�Ͷ�ʱ��2�����жϣ�TIM_IT_UPDATE   
}

//��ʱ���ײ�����������ʱ�ӣ������ж����ȼ�
//�˺����ᱻHAL_TIM_Base_Init()��������
void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim)
{
  if(htim->Instance == TIM2)
	{
		__HAL_RCC_TIM2_CLK_ENABLE();            //ʹ��TIM2ʱ��
		HAL_NVIC_SetPriority(TIM2_IRQn,3,3);    //�����ж����ȼ�����ռ���ȼ�1�������ȼ�1
		HAL_NVIC_EnableIRQ(TIM2_IRQn);          //����TIM2�ж�   
		__HAL_TIM_DISABLE(&TIM2_Handler);
		time = 0;
		TIM2_Handler.Instance->CNT = 0; //��ʱ������
	}
}


//��ʱ��2�жϷ�����
void TIM2_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&TIM2_Handler);
}

//�ص���������ʱ���жϷ���������
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim == (&TIM2_Handler))
	{
		++time;
	}
}
