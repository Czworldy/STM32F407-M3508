#include "all.h"

#ifdef BSP_USING_USART1
UART_HandleTypeDef USART1_Handler; //UART句柄
u8 USART1_RxBuffer[RXBUFFERSIZE];//HAL库USART接收Buffer
#endif

#ifdef BSP_USING_USART2
UART_HandleTypeDef USART2_Handler; //UART句柄
u8 USART2_RxBuffer[RXBUFFERSIZE];//HAL库USART接收Buffer
#endif

#ifdef BSP_USING_USART3
UART_HandleTypeDef USART3_Handler; //UART句柄
u8 USART3_RxBuffer[RXBUFFERSIZE];//HAL库USART接收Buffer
#endif

#ifdef BSP_USING_UART4
UART_HandleTypeDef UART4_Handler; //UART句柄
u8 UART4_RxBuffer[RXBUFFERSIZE];//HAL库USART接收Buffer
#endif

#ifdef BSP_USING_UART5
UART_HandleTypeDef UART5_Handler; //UART句柄
u8 UART5_RxBuffer[RXBUFFERSIZE];//HAL库USART接收Buffer
#endif

#ifdef BSP_USING_USART6
UART_HandleTypeDef USART6_Handler; //UART句柄
u8 USART6_RxBuffer[RXBUFFERSIZE];//HAL库USART接收Buffer
#endif

void UART_Config(void)
{
#ifdef BSP_USING_USART1
	USART1_Handler.Instance = USART1;
	USART1_Handler.Init.BaudRate = USART1_BAUDRATE;				    //波特率
	USART1_Handler.Init.WordLength = UART_WORDLENGTH_8B;   //字长为8位数据格式
	USART1_Handler.Init.StopBits = UART_STOPBITS_1;	    //一个停止位
	USART1_Handler.Init.Parity = UART_PARITY_NONE;		    //无奇偶校验位
	USART1_Handler.Init.HwFlowCtl = UART_HWCONTROL_NONE;   //无硬件流控
	USART1_Handler.Init.Mode = UART_MODE_TX_RX;		    //收发模式
	HAL_UART_Init(&USART1_Handler);					    //HAL_UART_Init()会使能UART
	
//	HAL_UART_Receive_IT(&USART1_Handler, (u8*)USART1_RxBuffer, RXBUFFERSIZE);//该函数会开启接收中断：标志位UART_IT_RXNE，并且设置接收缓冲以及接收缓冲接收最大数据量
#endif

#ifdef BSP_USING_USART2
	USART2_Handler.Instance = USART2;
	USART2_Handler.Init.BaudRate = USART2_BAUDRATE;				    //波特率
	USART2_Handler.Init.WordLength = UART_WORDLENGTH_8B;   //字长为8位数据格式
	USART2_Handler.Init.StopBits = UART_STOPBITS_1;	    //一个停止位
	USART2_Handler.Init.Parity = UART_PARITY_NONE;		    //无奇偶校验位
	USART2_Handler.Init.HwFlowCtl = UART_HWCONTROL_NONE;   //无硬件流控
	USART2_Handler.Init.Mode = UART_MODE_TX_RX;		    //收发模式
	HAL_UART_Init(&USART2_Handler);					    //HAL_UART_Init()会使能UART
	
//	HAL_UART_Receive_IT(&USART2_Handler, (u8*)USART2_RxBuffer, RXBUFFERSIZE);//该函数会开启接收中断：标志位UART_IT_RXNE，并且设置接收缓冲以及接收缓冲接收最大数据量
#endif

#ifdef BSP_USING_USART3
	USART3_Handler.Instance = USART3;
	USART3_Handler.Init.BaudRate = USART3_BAUDRATE;				    //波特率
	USART3_Handler.Init.WordLength = UART_WORDLENGTH_8B;   //字长为8位数据格式
	USART3_Handler.Init.StopBits = UART_STOPBITS_1;	    //一个停止位
	USART3_Handler.Init.Parity = UART_PARITY_NONE;		    //无奇偶校验位
	USART3_Handler.Init.HwFlowCtl = UART_HWCONTROL_NONE;   //无硬件流控
	USART3_Handler.Init.Mode = UART_MODE_TX_RX;		    //收发模式
	HAL_UART_Init(&USART3_Handler);					    //HAL_UART_Init()会使能UART
	
//	HAL_UART_Receive_IT(&USART3_Handler, (u8*)USART3_RxBuffer, RXBUFFERSIZE);//该函数会开启接收中断：标志位UART_IT_RXNE，并且设置接收缓冲以及接收缓冲接收最大数据量
#endif

#ifdef BSP_USING_UART4
	UART4_Handler.Instance = UART4;
	UART4_Handler.Init.BaudRate = UART4_BAUDRATE;				    //波特率
	UART4_Handler.Init.WordLength = UART_WORDLENGTH_8B;   //字长为8位数据格式
	UART4_Handler.Init.StopBits = UART_STOPBITS_1;	    //一个停止位
	UART4_Handler.Init.Parity = UART_PARITY_NONE;		    //无奇偶校验位
	UART4_Handler.Init.HwFlowCtl = UART_HWCONTROL_NONE;   //无硬件流控
	UART4_Handler.Init.Mode = UART_MODE_TX_RX;		    //收发模式
	HAL_UART_Init(&UART4_Handler);					    //HAL_UART_Init()会使能UART
	
//	HAL_UART_Receive_IT(&UART4_Handler, (u8*)UART4_RxBuffer, RXBUFFERSIZE);//该函数会开启接收中断：标志位UART_IT_RXNE，并且设置接收缓冲以及接收缓冲接收最大数据量
#endif

#ifdef BSP_USING_UART5
	UART5_Handler.Instance = UART5;
	UART5_Handler.Init.BaudRate = UART5_BAUDRATE;				    //波特率
	UART5_Handler.Init.WordLength = UART_WORDLENGTH_8B;   //字长为8位数据格式
	UART5_Handler.Init.StopBits = UART_STOPBITS_1;	    //一个停止位
	UART5_Handler.Init.Parity = UART_PARITY_NONE;		    //无奇偶校验位
	UART5_Handler.Init.HwFlowCtl = UART_HWCONTROL_NONE;   //无硬件流控
	UART5_Handler.Init.Mode = UART_MODE_TX_RX;		    //收发模式
	HAL_UART_Init(&UART5_Handler);					    //HAL_UART_Init()会使能UART
	
//	HAL_UART_Receive_IT(&UART5_Handler, (u8*)UART5_RxBuffer, RXBUFFERSIZE);//该函数会开启接收中断：标志位UART_IT_RXNE，并且设置接收缓冲以及接收缓冲接收最大数据量
#endif

#ifdef BSP_USING_USART6
	USART6_Handler.Instance = USART6;
	USART6_Handler.Init.BaudRate = USART6_BAUDRATE;				    //波特率
	USART6_Handler.Init.WordLength = UART_WORDLENGTH_8B;   //字长为8位数据格式
	USART6_Handler.Init.StopBits = UART_STOPBITS_1;	    //一个停止位
	USART6_Handler.Init.Parity = UART_PARITY_NONE;		    //无奇偶校验位
	USART6_Handler.Init.HwFlowCtl = UART_HWCONTROL_NONE;   //无硬件流控
	USART6_Handler.Init.Mode = UART_MODE_TX_RX;		    //收发模式
	HAL_UART_Init(&USART6_Handler);					    //HAL_UART_Init()会使能UART
	
//	HAL_UART_Receive_IT(&USART6_Handler, (u8*)USART6_RxBuffer, RXBUFFERSIZE);//该函数会开启接收中断：标志位UART_IT_RXNE，并且设置接收缓冲以及接收缓冲接收最大数据量
#endif
}

//UART底层初始化，时钟使能，引脚配置，中断配置
//此函数会被HAL_UART_Init()调用
//huart:串口句柄
void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
    //GPIO端口设置
	GPIO_InitTypeDef GPIO_InitStructure;
	
	if (huart->Instance == USART1)
	{
		#if BSP_USING_USART1
			USART1_CLK_ENABLE();
			
			USART1_TX_GPIO_CLK_ENABLE();
			GPIO_InitStructure.Pin = USART1_TX_PIN;
			GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;		//复用推挽输出
			GPIO_InitStructure.Pull = GPIO_PULLUP;			//上拉
			GPIO_InitStructure.Speed = GPIO_SPEED_FAST;		//高速
			GPIO_InitStructure.Alternate = GPIO_AF7_USART1;	//复用为USART1
			HAL_GPIO_Init(USART1_TX_GPIO_PORT, &GPIO_InitStructure);	   	//初始化
			
			USART1_RX_GPIO_CLK_ENABLE();
			GPIO_InitStructure.Pin = USART1_RX_PIN;
			HAL_GPIO_Init(USART1_RX_GPIO_PORT, &GPIO_InitStructure);	   	//初始化
			
			__HAL_UART_DISABLE_IT(huart,UART_IT_TC);
			__HAL_UART_ENABLE_IT(huart,UART_IT_RXNE);		//开启接收中断
			__HAL_UART_CLEAR_FLAG(huart,UART_FLAG_TC);
			HAL_NVIC_EnableIRQ(USART1_IRQn);				//使能USART中断通道
			HAL_NVIC_SetPriority(USART1_IRQn, 2, 2);			//抢占优先级2，子优先级2
		#endif
	}
	else if (huart->Instance == USART2)
	{
		#ifdef BSP_USING_USART2
			USART2_CLK_ENABLE();
			
			USART2_TX_GPIO_CLK_ENABLE();
			GPIO_InitStructure.Pin = USART2_TX_PIN;
			GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;		//复用推挽输出
			GPIO_InitStructure.Pull = GPIO_PULLUP;			//上拉
			GPIO_InitStructure.Speed = GPIO_SPEED_FAST;		//高速
			GPIO_InitStructure.Alternate = GPIO_AF7_USART2;	//复用为USART
			HAL_GPIO_Init(USART2_TX_GPIO_PORT, &GPIO_InitStructure);	   	//初始化
			
			USART2_RX_GPIO_CLK_ENABLE();
			GPIO_InitStructure.Pin = USART2_RX_PIN;
			HAL_GPIO_Init(USART2_RX_GPIO_PORT, &GPIO_InitStructure);	   	//初始化
			
			__HAL_UART_DISABLE_IT(huart,UART_IT_TC);
			__HAL_UART_ENABLE_IT(huart,UART_IT_RXNE);		//开启接收中断
			__HAL_UART_CLEAR_FLAG(huart,UART_FLAG_TC);
			HAL_NVIC_EnableIRQ(USART2_IRQn);				//使能USART中断通道
			HAL_NVIC_SetPriority(USART2_IRQn, 2, 2);			//抢占优先级2，子优先级2
		#endif
	}
	else if (huart->Instance == USART3)
	{
		#ifdef BSP_USING_USART3
			USART3_CLK_ENABLE();
			
			USART3_TX_GPIO_CLK_ENABLE();
			GPIO_InitStructure.Pin = USART3_TX_PIN;
			GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;		//复用推挽输出
			GPIO_InitStructure.Pull = GPIO_PULLUP;			//上拉
			GPIO_InitStructure.Speed = GPIO_SPEED_FAST;		//高速
			GPIO_InitStructure.Alternate = GPIO_AF7_USART3;	//复用为USART
			HAL_GPIO_Init(USART3_TX_GPIO_PORT, &GPIO_InitStructure);	   	//初始化
			
			USART3_RX_GPIO_CLK_ENABLE();
			GPIO_InitStructure.Pin = USART3_RX_PIN;
			HAL_GPIO_Init(USART3_RX_GPIO_PORT, &GPIO_InitStructure);	   	//初始化
			
			__HAL_UART_DISABLE_IT(huart,UART_IT_TC);
			__HAL_UART_ENABLE_IT(huart,UART_IT_RXNE);		//开启接收中断
			__HAL_UART_CLEAR_FLAG(huart,UART_FLAG_TC);
			HAL_NVIC_EnableIRQ(USART3_IRQn);				//使能USART中断通道
			HAL_NVIC_SetPriority(USART3_IRQn, 2, 2);			//抢占优先级2，子优先级2
		#endif
	}
	else if (huart->Instance == UART4)
	{
		#ifdef BSP_USING_UART4
			UART4_CLK_ENABLE();
			
			UART4_TX_GPIO_CLK_ENABLE();
			GPIO_InitStructure.Pin = UART4_TX_PIN;
			GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;		//复用推挽输出
			GPIO_InitStructure.Pull = GPIO_PULLUP;			//上拉
			GPIO_InitStructure.Speed = GPIO_SPEED_FAST;		//高速
			GPIO_InitStructure.Alternate = GPIO_AF8_UART4;	//复用为USART
			HAL_GPIO_Init(UART4_TX_GPIO_PORT, &GPIO_InitStructure);	   	//初始化
			
			UART4_RX_GPIO_CLK_ENABLE();
			GPIO_InitStructure.Pin = UART4_RX_PIN;
			HAL_GPIO_Init(UART4_RX_GPIO_PORT, &GPIO_InitStructure);	   	//初始化
			
			__HAL_UART_DISABLE_IT(huart,UART_IT_TC);
			__HAL_UART_ENABLE_IT(huart,UART_IT_RXNE);		//开启接收中断
			__HAL_UART_CLEAR_FLAG(huart,UART_FLAG_TC);
			HAL_NVIC_EnableIRQ(UART4_IRQn);				//使能USART中断通道
			HAL_NVIC_SetPriority(UART4_IRQn, 2, 2);			//抢占优先级2，子优先级2
		#endif
	}
	else if (huart->Instance == UART5)
	{
		#ifdef BSP_USING_UART5
			UART5_CLK_ENABLE();
			
			UART5_TX_GPIO_CLK_ENABLE();
			GPIO_InitStructure.Pin = UART5_TX_PIN;
			GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;		//复用推挽输出
			GPIO_InitStructure.Pull = GPIO_PULLUP;			//上拉
			GPIO_InitStructure.Speed = GPIO_SPEED_FAST;		//高速
			GPIO_InitStructure.Alternate = GPIO_AF8_UART5;	//复用为USART
			HAL_GPIO_Init(UART5_TX_GPIO_PORT, &GPIO_InitStructure);	   	//初始化
			
			UART5_RX_GPIO_CLK_ENABLE();
			GPIO_InitStructure.Pin = UART5_RX_PIN;
			HAL_GPIO_Init(UART5_RX_GPIO_PORT, &GPIO_InitStructure);	   	//初始化
			
			__HAL_UART_DISABLE_IT(huart,UART_IT_TC);
			__HAL_UART_ENABLE_IT(huart,UART_IT_RXNE);		//开启接收中断
			__HAL_UART_CLEAR_FLAG(huart,UART_FLAG_TC);
			HAL_NVIC_EnableIRQ(UART5_IRQn);				//使能USART中断通道
			HAL_NVIC_SetPriority(UART5_IRQn, 2, 2);			//抢占优先级2，子优先级2
		#endif
	}
	else if (huart->Instance == USART6)
	{
		#ifdef BSP_USING_USART6
			USART6_CLK_ENABLE();
			
			USART6_TX_GPIO_CLK_ENABLE();
			GPIO_InitStructure.Pin = USART6_TX_PIN;
			GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;		//复用推挽输出
			GPIO_InitStructure.Pull = GPIO_PULLUP;			//上拉
			GPIO_InitStructure.Speed = GPIO_SPEED_FAST;		//高速
			GPIO_InitStructure.Alternate = GPIO_AF8_USART6;	//复用为USART
			HAL_GPIO_Init(USART6_TX_GPIO_PORT, &GPIO_InitStructure);	   	//初始化
			
			USART6_RX_GPIO_CLK_ENABLE();
			GPIO_InitStructure.Pin = USART6_RX_PIN;
			HAL_GPIO_Init(USART6_RX_GPIO_PORT, &GPIO_InitStructure);	   	//初始化
			
			__HAL_UART_DISABLE_IT(huart,UART_IT_TC);
			__HAL_UART_ENABLE_IT(huart,UART_IT_RXNE);		//开启接收中断
			__HAL_UART_CLEAR_FLAG(huart,UART_FLAG_TC);
			HAL_NVIC_EnableIRQ(USART6_IRQn);				//使能USART中断通道
			HAL_NVIC_SetPriority(USART6_IRQn, 2, 2);			//抢占优先级2，子优先级2
		#endif
	}
}

int fputc(int ch, FILE *f)
{ 	
	while((USART6->SR&0X40)==0);//循环发送,直到发送完毕   
	USART6->DR = (u8) ch;      
	return ch;
}

void UART_SendByte(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
	HAL_UART_Transmit(huart,pData,Size,Timeout);	//发送接收到的数据
	while(__HAL_UART_GET_FLAG(huart,UART_FLAG_TC)!=SET);		//等待发送结束
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
//串口1中断服务程序
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
//串口2中断服务程序
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
//串口3中断服务程序
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
//串口4中断服务程序
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
//串口5中断服务程序
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
//串口6中断服务程序
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

