#include "all.h"

#ifdef BSP_USING_USART1
UART_HandleTypeDef USART1_Handler; //UART���
u8 USART1_RxBuffer[RXBUFFERSIZE];//HAL��USART����Buffer
#endif

#ifdef BSP_USING_USART2
UART_HandleTypeDef USART2_Handler; //UART���
u8 USART2_RxBuffer[RXBUFFERSIZE];//HAL��USART����Buffer
#endif

#ifdef BSP_USING_USART3
UART_HandleTypeDef USART3_Handler; //UART���
u8 USART3_RxBuffer[RXBUFFERSIZE];//HAL��USART����Buffer
#endif

#ifdef BSP_USING_UART4
UART_HandleTypeDef UART4_Handler; //UART���
u8 UART4_RxBuffer[RXBUFFERSIZE];//HAL��USART����Buffer
#endif

#ifdef BSP_USING_UART5
UART_HandleTypeDef UART5_Handler; //UART���
u8 UART5_RxBuffer[RXBUFFERSIZE];//HAL��USART����Buffer
#endif

#ifdef BSP_USING_USART6
UART_HandleTypeDef USART6_Handler; //UART���
u8 USART6_RxBuffer[RXBUFFERSIZE];//HAL��USART����Buffer
#endif

void UART_Config(void)
{
#ifdef BSP_USING_USART1
	USART1_Handler.Instance = USART1;
	USART1_Handler.Init.BaudRate = USART1_BAUDRATE;				    //������
	USART1_Handler.Init.WordLength = UART_WORDLENGTH_8B;   //�ֳ�Ϊ8λ���ݸ�ʽ
	USART1_Handler.Init.StopBits = UART_STOPBITS_1;	    //һ��ֹͣλ
	USART1_Handler.Init.Parity = UART_PARITY_NONE;		    //����żУ��λ
	USART1_Handler.Init.HwFlowCtl = UART_HWCONTROL_NONE;   //��Ӳ������
	USART1_Handler.Init.Mode = UART_MODE_TX_RX;		    //�շ�ģʽ
	HAL_UART_Init(&USART1_Handler);					    //HAL_UART_Init()��ʹ��UART
	
//	HAL_UART_Receive_IT(&USART1_Handler, (u8*)USART1_RxBuffer, RXBUFFERSIZE);//�ú����Ὺ�������жϣ���־λUART_IT_RXNE���������ý��ջ����Լ����ջ���������������
#endif

#ifdef BSP_USING_USART2
	USART2_Handler.Instance = USART2;
	USART2_Handler.Init.BaudRate = USART2_BAUDRATE;				    //������
	USART2_Handler.Init.WordLength = UART_WORDLENGTH_8B;   //�ֳ�Ϊ8λ���ݸ�ʽ
	USART2_Handler.Init.StopBits = UART_STOPBITS_1;	    //һ��ֹͣλ
	USART2_Handler.Init.Parity = UART_PARITY_NONE;		    //����żУ��λ
	USART2_Handler.Init.HwFlowCtl = UART_HWCONTROL_NONE;   //��Ӳ������
	USART2_Handler.Init.Mode = UART_MODE_TX_RX;		    //�շ�ģʽ
	HAL_UART_Init(&USART2_Handler);					    //HAL_UART_Init()��ʹ��UART
	
//	HAL_UART_Receive_IT(&USART2_Handler, (u8*)USART2_RxBuffer, RXBUFFERSIZE);//�ú����Ὺ�������жϣ���־λUART_IT_RXNE���������ý��ջ����Լ����ջ���������������
#endif

#ifdef BSP_USING_USART3
	USART3_Handler.Instance = USART3;
	USART3_Handler.Init.BaudRate = USART3_BAUDRATE;				    //������
	USART3_Handler.Init.WordLength = UART_WORDLENGTH_8B;   //�ֳ�Ϊ8λ���ݸ�ʽ
	USART3_Handler.Init.StopBits = UART_STOPBITS_1;	    //һ��ֹͣλ
	USART3_Handler.Init.Parity = UART_PARITY_NONE;		    //����żУ��λ
	USART3_Handler.Init.HwFlowCtl = UART_HWCONTROL_NONE;   //��Ӳ������
	USART3_Handler.Init.Mode = UART_MODE_TX_RX;		    //�շ�ģʽ
	HAL_UART_Init(&USART3_Handler);					    //HAL_UART_Init()��ʹ��UART
	
//	HAL_UART_Receive_IT(&USART3_Handler, (u8*)USART3_RxBuffer, RXBUFFERSIZE);//�ú����Ὺ�������жϣ���־λUART_IT_RXNE���������ý��ջ����Լ����ջ���������������
#endif

#ifdef BSP_USING_UART4
	UART4_Handler.Instance = UART4;
	UART4_Handler.Init.BaudRate = UART4_BAUDRATE;				    //������
	UART4_Handler.Init.WordLength = UART_WORDLENGTH_8B;   //�ֳ�Ϊ8λ���ݸ�ʽ
	UART4_Handler.Init.StopBits = UART_STOPBITS_1;	    //һ��ֹͣλ
	UART4_Handler.Init.Parity = UART_PARITY_NONE;		    //����żУ��λ
	UART4_Handler.Init.HwFlowCtl = UART_HWCONTROL_NONE;   //��Ӳ������
	UART4_Handler.Init.Mode = UART_MODE_TX_RX;		    //�շ�ģʽ
	HAL_UART_Init(&UART4_Handler);					    //HAL_UART_Init()��ʹ��UART
	
//	HAL_UART_Receive_IT(&UART4_Handler, (u8*)UART4_RxBuffer, RXBUFFERSIZE);//�ú����Ὺ�������жϣ���־λUART_IT_RXNE���������ý��ջ����Լ����ջ���������������
#endif

#ifdef BSP_USING_UART5
	UART5_Handler.Instance = UART5;
	UART5_Handler.Init.BaudRate = UART5_BAUDRATE;				    //������
	UART5_Handler.Init.WordLength = UART_WORDLENGTH_8B;   //�ֳ�Ϊ8λ���ݸ�ʽ
	UART5_Handler.Init.StopBits = UART_STOPBITS_1;	    //һ��ֹͣλ
	UART5_Handler.Init.Parity = UART_PARITY_NONE;		    //����żУ��λ
	UART5_Handler.Init.HwFlowCtl = UART_HWCONTROL_NONE;   //��Ӳ������
	UART5_Handler.Init.Mode = UART_MODE_TX_RX;		    //�շ�ģʽ
	HAL_UART_Init(&UART5_Handler);					    //HAL_UART_Init()��ʹ��UART
	
//	HAL_UART_Receive_IT(&UART5_Handler, (u8*)UART5_RxBuffer, RXBUFFERSIZE);//�ú����Ὺ�������жϣ���־λUART_IT_RXNE���������ý��ջ����Լ����ջ���������������
#endif

#ifdef BSP_USING_USART6
	USART6_Handler.Instance = USART6;
	USART6_Handler.Init.BaudRate = USART6_BAUDRATE;				    //������
	USART6_Handler.Init.WordLength = UART_WORDLENGTH_8B;   //�ֳ�Ϊ8λ���ݸ�ʽ
	USART6_Handler.Init.StopBits = UART_STOPBITS_1;	    //һ��ֹͣλ
	USART6_Handler.Init.Parity = UART_PARITY_NONE;		    //����żУ��λ
	USART6_Handler.Init.HwFlowCtl = UART_HWCONTROL_NONE;   //��Ӳ������
	USART6_Handler.Init.Mode = UART_MODE_TX_RX;		    //�շ�ģʽ
	HAL_UART_Init(&USART6_Handler);					    //HAL_UART_Init()��ʹ��UART
	
//	HAL_UART_Receive_IT(&USART6_Handler, (u8*)USART6_RxBuffer, RXBUFFERSIZE);//�ú����Ὺ�������жϣ���־λUART_IT_RXNE���������ý��ջ����Լ����ջ���������������
#endif
}

//UART�ײ��ʼ����ʱ��ʹ�ܣ��������ã��ж�����
//�˺����ᱻHAL_UART_Init()����
//huart:���ھ��
void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
    //GPIO�˿�����
	GPIO_InitTypeDef GPIO_InitStructure;
	
	if (huart->Instance == USART1)
	{
		#if BSP_USING_USART1
			USART1_CLK_ENABLE();
			
			USART1_TX_GPIO_CLK_ENABLE();
			GPIO_InitStructure.Pin = USART1_TX_PIN;
			GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;		//�����������
			GPIO_InitStructure.Pull = GPIO_PULLUP;			//����
			GPIO_InitStructure.Speed = GPIO_SPEED_FAST;		//����
			GPIO_InitStructure.Alternate = GPIO_AF7_USART1;	//����ΪUSART1
			HAL_GPIO_Init(USART1_TX_GPIO_PORT, &GPIO_InitStructure);	   	//��ʼ��
			
			USART1_RX_GPIO_CLK_ENABLE();
			GPIO_InitStructure.Pin = USART1_RX_PIN;
			HAL_GPIO_Init(USART1_RX_GPIO_PORT, &GPIO_InitStructure);	   	//��ʼ��
			
			__HAL_UART_DISABLE_IT(huart,UART_IT_TC);
			__HAL_UART_ENABLE_IT(huart,UART_IT_RXNE);		//���������ж�
			__HAL_UART_CLEAR_FLAG(huart,UART_FLAG_TC);
			HAL_NVIC_EnableIRQ(USART1_IRQn);				//ʹ��USART�ж�ͨ��
			HAL_NVIC_SetPriority(USART1_IRQn, 2, 2);			//��ռ���ȼ�2�������ȼ�2
		#endif
	}
	else if (huart->Instance == USART2)
	{
		#ifdef BSP_USING_USART2
			USART2_CLK_ENABLE();
			
			USART2_TX_GPIO_CLK_ENABLE();
			GPIO_InitStructure.Pin = USART2_TX_PIN;
			GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;		//�����������
			GPIO_InitStructure.Pull = GPIO_PULLUP;			//����
			GPIO_InitStructure.Speed = GPIO_SPEED_FAST;		//����
			GPIO_InitStructure.Alternate = GPIO_AF7_USART2;	//����ΪUSART
			HAL_GPIO_Init(USART2_TX_GPIO_PORT, &GPIO_InitStructure);	   	//��ʼ��
			
			USART2_RX_GPIO_CLK_ENABLE();
			GPIO_InitStructure.Pin = USART2_RX_PIN;
			HAL_GPIO_Init(USART2_RX_GPIO_PORT, &GPIO_InitStructure);	   	//��ʼ��
			
			__HAL_UART_DISABLE_IT(huart,UART_IT_TC);
			__HAL_UART_ENABLE_IT(huart,UART_IT_RXNE);		//���������ж�
			__HAL_UART_CLEAR_FLAG(huart,UART_FLAG_TC);
			HAL_NVIC_EnableIRQ(USART2_IRQn);				//ʹ��USART�ж�ͨ��
			HAL_NVIC_SetPriority(USART2_IRQn, 2, 2);			//��ռ���ȼ�2�������ȼ�2
		#endif
	}
	else if (huart->Instance == USART3)
	{
		#ifdef BSP_USING_USART3
			USART3_CLK_ENABLE();
			
			USART3_TX_GPIO_CLK_ENABLE();
			GPIO_InitStructure.Pin = USART3_TX_PIN;
			GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;		//�����������
			GPIO_InitStructure.Pull = GPIO_PULLUP;			//����
			GPIO_InitStructure.Speed = GPIO_SPEED_FAST;		//����
			GPIO_InitStructure.Alternate = GPIO_AF7_USART3;	//����ΪUSART
			HAL_GPIO_Init(USART3_TX_GPIO_PORT, &GPIO_InitStructure);	   	//��ʼ��
			
			USART3_RX_GPIO_CLK_ENABLE();
			GPIO_InitStructure.Pin = USART3_RX_PIN;
			HAL_GPIO_Init(USART3_RX_GPIO_PORT, &GPIO_InitStructure);	   	//��ʼ��
			
			__HAL_UART_DISABLE_IT(huart,UART_IT_TC);
			__HAL_UART_ENABLE_IT(huart,UART_IT_RXNE);		//���������ж�
			__HAL_UART_CLEAR_FLAG(huart,UART_FLAG_TC);
			HAL_NVIC_EnableIRQ(USART3_IRQn);				//ʹ��USART�ж�ͨ��
			HAL_NVIC_SetPriority(USART3_IRQn, 2, 2);			//��ռ���ȼ�2�������ȼ�2
		#endif
	}
	else if (huart->Instance == UART4)
	{
		#ifdef BSP_USING_UART4
			UART4_CLK_ENABLE();
			
			UART4_TX_GPIO_CLK_ENABLE();
			GPIO_InitStructure.Pin = UART4_TX_PIN;
			GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;		//�����������
			GPIO_InitStructure.Pull = GPIO_PULLUP;			//����
			GPIO_InitStructure.Speed = GPIO_SPEED_FAST;		//����
			GPIO_InitStructure.Alternate = GPIO_AF8_UART4;	//����ΪUSART
			HAL_GPIO_Init(UART4_TX_GPIO_PORT, &GPIO_InitStructure);	   	//��ʼ��
			
			UART4_RX_GPIO_CLK_ENABLE();
			GPIO_InitStructure.Pin = UART4_RX_PIN;
			HAL_GPIO_Init(UART4_RX_GPIO_PORT, &GPIO_InitStructure);	   	//��ʼ��
			
			__HAL_UART_DISABLE_IT(huart,UART_IT_TC);
			__HAL_UART_ENABLE_IT(huart,UART_IT_RXNE);		//���������ж�
			__HAL_UART_CLEAR_FLAG(huart,UART_FLAG_TC);
			HAL_NVIC_EnableIRQ(UART4_IRQn);				//ʹ��USART�ж�ͨ��
			HAL_NVIC_SetPriority(UART4_IRQn, 2, 2);			//��ռ���ȼ�2�������ȼ�2
		#endif
	}
	else if (huart->Instance == UART5)
	{
		#ifdef BSP_USING_UART5
			UART5_CLK_ENABLE();
			
			UART5_TX_GPIO_CLK_ENABLE();
			GPIO_InitStructure.Pin = UART5_TX_PIN;
			GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;		//�����������
			GPIO_InitStructure.Pull = GPIO_PULLUP;			//����
			GPIO_InitStructure.Speed = GPIO_SPEED_FAST;		//����
			GPIO_InitStructure.Alternate = GPIO_AF8_UART5;	//����ΪUSART
			HAL_GPIO_Init(UART5_TX_GPIO_PORT, &GPIO_InitStructure);	   	//��ʼ��
			
			UART5_RX_GPIO_CLK_ENABLE();
			GPIO_InitStructure.Pin = UART5_RX_PIN;
			HAL_GPIO_Init(UART5_RX_GPIO_PORT, &GPIO_InitStructure);	   	//��ʼ��
			
			__HAL_UART_DISABLE_IT(huart,UART_IT_TC);
			__HAL_UART_ENABLE_IT(huart,UART_IT_RXNE);		//���������ж�
			__HAL_UART_CLEAR_FLAG(huart,UART_FLAG_TC);
			HAL_NVIC_EnableIRQ(UART5_IRQn);				//ʹ��USART�ж�ͨ��
			HAL_NVIC_SetPriority(UART5_IRQn, 2, 2);			//��ռ���ȼ�2�������ȼ�2
		#endif
	}
	else if (huart->Instance == USART6)
	{
		#ifdef BSP_USING_USART6
			USART6_CLK_ENABLE();
			
			USART6_TX_GPIO_CLK_ENABLE();
			GPIO_InitStructure.Pin = USART6_TX_PIN;
			GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;		//�����������
			GPIO_InitStructure.Pull = GPIO_PULLUP;			//����
			GPIO_InitStructure.Speed = GPIO_SPEED_FAST;		//����
			GPIO_InitStructure.Alternate = GPIO_AF8_USART6;	//����ΪUSART
			HAL_GPIO_Init(USART6_TX_GPIO_PORT, &GPIO_InitStructure);	   	//��ʼ��
			
			USART6_RX_GPIO_CLK_ENABLE();
			GPIO_InitStructure.Pin = USART6_RX_PIN;
			HAL_GPIO_Init(USART6_RX_GPIO_PORT, &GPIO_InitStructure);	   	//��ʼ��
			
			__HAL_UART_DISABLE_IT(huart,UART_IT_TC);
			__HAL_UART_ENABLE_IT(huart,UART_IT_RXNE);		//���������ж�
			__HAL_UART_CLEAR_FLAG(huart,UART_FLAG_TC);
			HAL_NVIC_EnableIRQ(USART6_IRQn);				//ʹ��USART�ж�ͨ��
			HAL_NVIC_SetPriority(USART6_IRQn, 2, 2);			//��ռ���ȼ�2�������ȼ�2
		#endif
	}
}

int fputc(int ch, FILE *f)
{ 	
	while((USART6->SR&0X40)==0);//ѭ������,ֱ���������   
	USART6->DR = (u8) ch;      
	return ch;
}

void UART_SendByte(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
	HAL_UART_Transmit(huart,pData,Size,Timeout);	//���ͽ��յ�������
	while(__HAL_UART_GET_FLAG(huart,UART_FLAG_TC)!=SET);		//�ȴ����ͽ���
}

void UART_GetByte(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
	while(__HAL_UART_GET_FLAG(huart,UART_FLAG_RXNE)!=SET);
	HAL_UART_Receive(huart,pData,Size,Timeout);
}

void UART_puts(UART_HandleTypeDef *huart, uint8_t *pData)
{
	while (*pData)
	{
		UART_SendByte(huart, pData++, 1, 1000);
	}
}

void UART_printf(UART_HandleTypeDef *huart, char *fmt, ...)
{
	va_list ap;
	char str[128];

	va_start(ap,fmt);
	vsprintf(str,fmt,ap);
	va_end(ap);
	UART_puts(huart, (u8*)str);
}

#ifdef BSP_USING_USART1
//����1�жϷ������
void USART1_IRQHandler(void)                	
{	
	u8 Res;
	
	if((__HAL_UART_GET_FLAG(&USART1_Handler,UART_FLAG_RXNE)!=RESET))
	{
    HAL_UART_Receive(&USART1_Handler,&Res,1,1000);
		UART_SendByte(&USART1_Handler,&Res,1,1000);
	}
} 
#endif

#ifdef BSP_USING_USART2
//����2�жϷ������
void USART2_IRQHandler(void)                	
{	
	u8 Res;
	
	if((__HAL_UART_GET_FLAG(&USART2_Handler,UART_FLAG_RXNE)!=RESET))
	{
    HAL_UART_Receive(&USART2_Handler,&Res,1,1000);
		UART_SendByte(&USART2_Handler,&Res,1,1000);
	}
} 
#endif

#ifdef BSP_USING_USART3
//����3�жϷ������
void USART3_IRQHandler(void)                	
{	
	u8 Res;
	
	if((__HAL_UART_GET_FLAG(&USART3_Handler,UART_FLAG_RXNE)!=RESET))
	{
    HAL_UART_Receive(&USART3_Handler,&Res,1,1000);
		UART_SendByte(&USART3_Handler,&Res,1,1000);
	}
} 
#endif

#ifdef BSP_USING_UART4
//����4�жϷ������
void UART4_IRQHandler(void)                	
{	
	u8 Res;
	
	if((__HAL_UART_GET_FLAG(&UART4_Handler,UART_FLAG_RXNE)!=RESET))
	{
    HAL_UART_Receive(&UART4_Handler,&Res,1,1000);
		UART_SendByte(&UART4_Handler,&Res,1,1000);
	}
} 
#endif

#ifdef BSP_USING_UART5
//����5�жϷ������
void UART5_IRQHandler(void)                	
{	
	u8 Res;
	
	if((__HAL_UART_GET_FLAG(&UART5_Handler,UART_FLAG_RXNE)!=RESET))
	{
    HAL_UART_Receive(&UART5_Handler,&Res,1,1000);
		UART_SendByte(&UART5_Handler,&Res,1,1000);
	}
} 
#endif

#ifdef BSP_USING_USART6
//����6�жϷ������
void USART6_IRQHandler(void)                	
{	
	u8 Res;
	
	if((__HAL_UART_GET_FLAG(&USART6_Handler,UART_FLAG_RXNE)!=RESET))
	{
    HAL_UART_Receive(&USART6_Handler,&Res,1,1000);
		UART_SendByte(&USART6_Handler,&Res,1,1000);
	}
} 
#endif

