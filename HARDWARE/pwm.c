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
	PWM1_Handler.Init.Prescaler = PWM1_Prescaler;       //��ʱ����Ƶ
	PWM1_Handler.Init.CounterMode = TIM_COUNTERMODE_UP;//���ϼ���ģʽ
	PWM1_Handler.Init.Period = PWM1_Period;          //�Զ���װ��ֵ
	PWM1_Handler.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	HAL_TIM_PWM_Init(&PWM1_Handler);       //��ʼ��PWM

	PWM1_OC_Handler.OCMode = TIM_OCMODE_PWM1; //ģʽѡ��PWM1
	PWM1_OC_Handler.Pulse = PWM1_Pulse;            //���ñȽ�ֵ,��ֵ����ȷ��ռ�ձ�
	PWM1_OC_Handler.OCPolarity = TIM_OCPOLARITY_HIGH; //����Ƚϼ���Ϊ�� 
	HAL_TIM_PWM_ConfigChannel(&PWM1_Handler,&PWM1_OC_Handler,PWM1_Channel);//����TIMͨ��
	
	HAL_TIM_PWM_Start(&PWM1_Handler,PWM1_Channel);//����PWMͨ��
#endif

#ifdef BSP_USING_PWM2
	PWM2_Handler.Instance = PWM2_Instance;
	PWM2_Handler.Init.Prescaler = PWM2_Prescaler;       //��ʱ����Ƶ
	PWM2_Handler.Init.CounterMode = TIM_COUNTERMODE_UP;//���ϼ���ģʽ
	PWM2_Handler.Init.Period = PWM2_Period;          //�Զ���װ��ֵ
	PWM2_Handler.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	HAL_TIM_PWM_Init(&PWM2_Handler);       //��ʼ��PWM
	
	PWM2_OC_Handler.OCMode = TIM_OCMODE_PWM1; //ģʽѡ��PWM1
	PWM2_OC_Handler.Pulse = PWM2_Pulse;            //���ñȽ�ֵ,��ֵ����ȷ��ռ�ձ�
	PWM2_OC_Handler.OCPolarity = TIM_OCPOLARITY_HIGH; //����Ƚϼ���Ϊ�� 
	HAL_TIM_PWM_ConfigChannel(&PWM2_Handler,&PWM2_OC_Handler,PWM2_Channel);//����TIMͨ��
	
	HAL_TIM_PWM_Start(&PWM2_Handler,PWM2_Channel);//����PWMͨ��
#endif

#ifdef BSP_USING_PWM3
	PWM3_Handler.Instance = PWM3_Instance;
	PWM3_Handler.Init.Prescaler = PWM3_Prescaler;       //��ʱ����Ƶ
	PWM3_Handler.Init.CounterMode = TIM_COUNTERMODE_UP;//���ϼ���ģʽ
	PWM3_Handler.Init.Period = PWM3_Period;          //�Զ���װ��ֵ
	PWM3_Handler.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	HAL_TIM_PWM_Init(&PWM3_Handler);       //��ʼ��PWM
	
	PWM3_OC_Handler.OCMode = TIM_OCMODE_PWM1; //ģʽѡ��PWM1
	PWM3_OC_Handler.Pulse = PWM3_Pulse;            //���ñȽ�ֵ,��ֵ����ȷ��ռ�ձ�
	PWM3_OC_Handler.OCPolarity = TIM_OCPOLARITY_HIGH; //����Ƚϼ���Ϊ�� 
	HAL_TIM_PWM_ConfigChannel(&PWM3_Handler,&PWM3_OC_Handler,PWM3_Channel);//����TIMͨ��
	
	HAL_TIM_PWM_Start(&PWM3_Handler,PWM3_Channel);//����PWMͨ��
#endif

#ifdef BSP_USING_PWM4
	PWM4_Handler.Instance = PWM4_Instance;
	PWM4_Handler.Init.Prescaler = PWM4_Prescaler;       //��ʱ����Ƶ
	PWM4_Handler.Init.CounterMode = TIM_COUNTERMODE_UP;//���ϼ���ģʽ
	PWM4_Handler.Init.Period = PWM4_Period;          //�Զ���װ��ֵ
	PWM4_Handler.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	HAL_TIM_PWM_Init(&PWM4_Handler);       //��ʼ��PWM
	
	PWM4_OC_Handler.OCMode = TIM_OCMODE_PWM1; //ģʽѡ��PWM1
	PWM4_OC_Handler.Pulse = PWM4_Pulse;            //���ñȽ�ֵ,��ֵ����ȷ��ռ�ձ�
	PWM4_OC_Handler.OCPolarity = TIM_OCPOLARITY_HIGH; //����Ƚϼ���Ϊ�� 
	HAL_TIM_PWM_ConfigChannel(&PWM4_Handler,&PWM4_OC_Handler,PWM4_Channel);//����TIMͨ��
	
	HAL_TIM_PWM_Start(&PWM4_Handler,PWM4_Channel);//����PWMͨ��
#endif
}

//��ʱ���ײ�������ʱ��ʹ�ܣ���������
//�˺����ᱻHAL_TIM_PWM_Init()����
//htim:��ʱ�����
void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	if (htim == &PWM1_Handler)
	{
		PWM1_TIM_CLK_ENABLE();
		PWM1_GPIO_CLK_ENABLE();
		
		GPIO_InitStructure.Pin = PWM1_PIN;
		GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;  	//�����������
		GPIO_InitStructure.Pull = GPIO_PULLUP;          //����
		GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;     //����
		GPIO_InitStructure.Alternate= PWM1_GPIO_AF;	//����
		HAL_GPIO_Init(PWM1_GPIO_PORT, &GPIO_InitStructure);
	}
	else if (htim == &PWM2_Handler)
	{
		PWM2_TIM_CLK_ENABLE();
		PWM2_GPIO_CLK_ENABLE();
		
		GPIO_InitStructure.Pin = PWM2_PIN;
		GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;  	//�����������
		GPIO_InitStructure.Pull = GPIO_PULLUP;          //����
		GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;     //����
		GPIO_InitStructure.Alternate= PWM2_GPIO_AF;	//����
		HAL_GPIO_Init(PWM2_GPIO_PORT, &GPIO_InitStructure);
	}
	else if (htim == &PWM3_Handler)
	{
		PWM3_TIM_CLK_ENABLE();
		PWM3_GPIO_CLK_ENABLE();
		
		GPIO_InitStructure.Pin = PWM3_PIN;
		GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;  	//�����������
		GPIO_InitStructure.Pull = GPIO_PULLUP;          //����
		GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;     //����
		GPIO_InitStructure.Alternate= PWM3_GPIO_AF;	//����
		HAL_GPIO_Init(PWM3_GPIO_PORT, &GPIO_InitStructure);
	}
	else if (htim == &PWM4_Handler)
	{
		PWM4_TIM_CLK_ENABLE();
		PWM4_GPIO_CLK_ENABLE();
		
		GPIO_InitStructure.Pin = PWM4_PIN;
		GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;  	//�����������
		GPIO_InitStructure.Pull = GPIO_PULLUP;          //����
		GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;     //����
		GPIO_InitStructure.Alternate= PWM4_GPIO_AF;	//����
		HAL_GPIO_Init(PWM4_GPIO_PORT, &GPIO_InitStructure);
	}
}
