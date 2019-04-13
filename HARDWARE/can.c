#include "all.h"

CAN_HandleTypeDef   CAN1_Handler;   //CAN1句柄
CanTxMsgTypeDef     CAN1_TxMessage;      //发送消息
CanRxMsgTypeDef     CAN1_RxMessage;      //接收消息

CAN_HandleTypeDef   CAN2_Handler;   //CAN2句柄
CanTxMsgTypeDef     CAN2_TxMessage;      //发送消息
CanRxMsgTypeDef     CAN2_RxMessage;      //接收消息

////CAN初始化
//tsjw:重新同步跳跃时间单元.范围:CAN_SJW_1TQ~CAN_SJW_4TQ
//tbs2:时间段2的时间单元.   范围:CAN_BS2_1TQ~CAN_BS2_8TQ;
//tbs1:时间段1的时间单元.   范围:CAN_BS1_1TQ~CAN_BS1_16TQ
//brp :波特率分频器.范围:1~1024; tq=(brp)*tpclk1
//波特率=Fpclk1/((tbs1+tbs2+1)*brp); 其中tbs1和tbs2我们只用关注标识符上标志的序号，例如CAN_BS2_1TQ，我们就认为tbs2=1来计算即可。
//mode:CAN_MODE_NORMAL,普通模式;CAN_MODE_LOOPBACK,回环模式;
//Fpclk1的时钟在初始化的时候设置为42M,如果设置CAN1_Mode_Init(CAN_SJW_1tq,CAN_BS2_3tq,CAN_BS1_3tq,6,CAN_MODE_LOOPBACK);
//则波特率为:42M/((3+3+1)*6)=1Mbps
//返回值:0,初始化OK;
//    其他,初始化失败; 

u8 CAN_Mode_Init(void)
{
	CAN_FilterConfTypeDef  CAN1_FilerConf, CAN2_FilerConf;
	uint8_t i = 0;
	uint8_t CAN1_FilterNumber = 0, CAN2_FilterNumber = 14;
	uint8_t CAN1_FIFO0_Size = 0, CAN1_FIFO1_Size = 0;
	uint8_t CAN2_FIFO0_Size = 0, CAN2_FIFO1_Size = 0;
	uint16_t CAN1_FIFO0_FilterId_FilterMaskId[14*4] = {0};
	uint16_t CAN1_FIFO1_FilterId_FilterMaskId[14*4] = {0};
	uint16_t CAN2_FIFO0_FilterId_FilterMaskId[14*4] = {0};
	uint16_t CAN2_FIFO1_FilterId_FilterMaskId[14*4] = {0};
	
	Hash_Table_Init();
	
#if USE_CAN1_R0 || USE_CAN1_R1
	CAN1_Handler.Instance = CAN1;
	CAN1_Handler.pTxMsg = &CAN1_TxMessage;     //发送消息
	CAN1_Handler.pRxMsg = &CAN1_RxMessage;     //接收消息
	CAN1_Handler.Init.Prescaler = CAN1_Prescaler;    //分频系数(Fdiv)为brp+1
	CAN1_Handler.Init.Mode = CAN_MODE_NORMAL;        //模式设置 
	CAN1_Handler.Init.SJW = CAN_SJW_2TQ;         //重新同步跳跃宽度(Tsjw)为tsjw+1个时间单位 CAN_SJW_1TQ~CAN_SJW_4TQ
	CAN1_Handler.Init.BS1 = CAN_BS1_3TQ;         //tbs1范围CAN_BS1_1TQ~CAN_BS1_16TQ
	CAN1_Handler.Init.BS2 = CAN_BS2_3TQ;         //tbs2范围CAN_BS2_1TQ~CAN_BS2_8TQ
	CAN1_Handler.Init.TTCM = DISABLE;     //非时间触发通信模式 
	CAN1_Handler.Init.ABOM = DISABLE;     //软件自动离线管理
	CAN1_Handler.Init.AWUM = DISABLE;     //睡眠模式通过软件唤醒(清除CAN->MCR的SLEEP位)
	CAN1_Handler.Init.NART = DISABLE;      //失能非自动重传输模式,即自动重传
	CAN1_Handler.Init.RFLM = DISABLE;     //报文不锁定,新的覆盖旧的 
	CAN1_Handler.Init.TXFP = ENABLE;      //使能发送FIFO优先级,报文顺序由发送顺序决定 DISABLE:ID决定
	
	if(HAL_CAN_Init(&CAN1_Handler)!=HAL_OK) return 1;   //初始化
#endif

#if USE_CAN2_R0 || USE_CAN2_R1
	CAN2_Handler.Instance = CAN2;
	CAN2_Handler.pTxMsg = &CAN2_TxMessage;     //发送消息
	CAN2_Handler.pRxMsg = &CAN2_RxMessage;     //接收消息
	CAN2_Handler.Init.Prescaler = CAN2_Prescaler;    //分频系数(Fdiv)为brp+1
	CAN2_Handler.Init.Mode = CAN_MODE_NORMAL;        //模式设置 
	CAN2_Handler.Init.SJW = CAN_SJW_2TQ;         //重新同步跳跃宽度(Tsjw)为tsjw+1个时间单位 CAN_SJW_1TQ~CAN_SJW_4TQ
	CAN2_Handler.Init.BS1 = CAN_BS1_3TQ;         //tbs1范围CAN_BS1_1TQ~CAN_BS1_16TQ
	CAN2_Handler.Init.BS2 = CAN_BS2_3TQ;         //tbs2范围CAN_BS2_1TQ~CAN_BS2_8TQ
	CAN2_Handler.Init.TTCM = DISABLE;     //非时间触发通信模式 
	CAN2_Handler.Init.ABOM = DISABLE;     //失能自动离线管理
	CAN2_Handler.Init.AWUM = DISABLE;     //睡眠模式通过软件唤醒(清除CAN->MCR的SLEEP位)
	CAN2_Handler.Init.NART = DISABLE;      //失能非自动重传输模式,即自动重传
	CAN2_Handler.Init.RFLM = DISABLE;     //报文不锁定,新的覆盖旧的 
	CAN2_Handler.Init.TXFP = ENABLE;      //使能发送FIFO优先级,报文顺序由发送顺序决定 DISABLE:ID决定
	
	if(HAL_CAN_Init(&CAN2_Handler)!=HAL_OK) return 2;   //初始化
#endif
	
	for(i = 0; i < Can_Data_Num; ++i)
	{
	#if CAN_MASTER == 1
		if(Can_Database[i].Data_type == READ_ONLY)
	#else
		if(Can_Database[i].Data_type == WRITE_ONLY)
	#endif
		{
			if(Can_Database[i].Channel == 1)
			{
				if(Can_Database[i].Fifo_num == CAN_FILTER_FIFO0)
				{
					CAN1_FIFO0_FilterId_FilterMaskId[CAN1_FIFO0_Size++] = (uint16_t)(Can_Database[i].Data_ID)<<5;
				}
				else
				{
					CAN1_FIFO1_FilterId_FilterMaskId[CAN1_FIFO1_Size++] = (uint16_t)(Can_Database[i].Data_ID)<<5;
				}
			}
			else if(Can_Database[i].Channel == 2)
			{
				if(Can_Database[i].Fifo_num == CAN_FILTER_FIFO0)
				{
					CAN2_FIFO0_FilterId_FilterMaskId[CAN2_FIFO0_Size++] = (uint16_t)(Can_Database[i].Data_ID)<<5;
				}
				else
				{
					CAN2_FIFO1_FilterId_FilterMaskId[CAN2_FIFO1_Size++] = (uint16_t)(Can_Database[i].Data_ID)<<5;
				}
			}
		}
	}
	
	for (i = 0; i < (3 - (CAN1_FIFO0_Size-1)%4); ++i)
	{
		CAN1_FIFO0_FilterId_FilterMaskId[CAN1_FIFO0_Size+i] = CAN1_FIFO0_FilterId_FilterMaskId[CAN1_FIFO0_Size-1];
	}
	for (i = 0; i < (3 - (CAN1_FIFO1_Size-1)%4); ++i)
	{
		CAN1_FIFO1_FilterId_FilterMaskId[CAN1_FIFO1_Size+i] = CAN1_FIFO1_FilterId_FilterMaskId[CAN1_FIFO1_Size-1];
	}
	for (i = 0; i < (3 - (CAN2_FIFO0_Size-1)%4); ++i)
	{
		CAN2_FIFO0_FilterId_FilterMaskId[CAN2_FIFO0_Size+i] = CAN2_FIFO0_FilterId_FilterMaskId[CAN2_FIFO0_Size-1];
	}
	for (i = 0; i < (3 - (CAN2_FIFO1_Size-1)%4); ++i)
	{
		CAN2_FIFO1_FilterId_FilterMaskId[CAN2_FIFO1_Size+i] = CAN2_FIFO1_FilterId_FilterMaskId[CAN2_FIFO1_Size-1];
	}
	
	if (CAN1_FIFO0_Size > 0)
	{
		for(i = 0;i <= ((CAN1_FIFO0_Size - 1) / 4); ++i)
		{
			CAN1_FilerConf.FilterIdHigh = CAN1_FIFO0_FilterId_FilterMaskId[4*i+0];     //32位ID
			CAN1_FilerConf.FilterIdLow = CAN1_FIFO0_FilterId_FilterMaskId[4*i+1];
			CAN1_FilerConf.FilterMaskIdHigh = CAN1_FIFO0_FilterId_FilterMaskId[4*i+2]; //32位MASK
			CAN1_FilerConf.FilterMaskIdLow = CAN1_FIFO0_FilterId_FilterMaskId[4*i+3];  
			CAN1_FilerConf.FilterFIFOAssignment = CAN_FILTER_FIFO0;//过滤器关联到FIFO0
			CAN1_FilerConf.FilterNumber = CAN1_FilterNumber++;          //过滤器
			CAN1_FilerConf.FilterMode = CAN_FILTERMODE_IDLIST;
			CAN1_FilerConf.FilterScale = CAN_FILTERSCALE_16BIT;
			CAN1_FilerConf.FilterActivation = ENABLE; //激活滤波器
			CAN1_FilerConf.BankNumber = 14;

			if(HAL_CAN_ConfigFilter(&CAN1_Handler,&CAN1_FilerConf)!=HAL_OK) return 3;//滤波器初始化
		}
	}
	
	if (CAN1_FIFO1_Size > 0)
	{
		for(i = 0;i <= ((CAN1_FIFO1_Size - 1) / 4); ++i)
		{
			CAN1_FilerConf.FilterIdHigh = CAN1_FIFO1_FilterId_FilterMaskId[4*i+0];     //32位ID
			CAN1_FilerConf.FilterIdLow = CAN1_FIFO1_FilterId_FilterMaskId[4*i+1];
			CAN1_FilerConf.FilterMaskIdHigh = CAN1_FIFO1_FilterId_FilterMaskId[4*i+2]; //32位MASK
			CAN1_FilerConf.FilterMaskIdLow = CAN1_FIFO1_FilterId_FilterMaskId[4*i+3];  
			CAN1_FilerConf.FilterFIFOAssignment = CAN_FILTER_FIFO1;//过滤器关联到FIFO1
			CAN1_FilerConf.FilterNumber = CAN1_FilterNumber++;          //过滤器
			CAN1_FilerConf.FilterMode = CAN_FILTERMODE_IDLIST;
			CAN1_FilerConf.FilterScale = CAN_FILTERSCALE_16BIT;
			CAN1_FilerConf.FilterActivation = ENABLE; //激活滤波器
			CAN1_FilerConf.BankNumber = 14;
			
			if(HAL_CAN_ConfigFilter(&CAN1_Handler,&CAN1_FilerConf)!=HAL_OK) return 4;//滤波器初始化
		}
	}
	
	if (CAN2_FIFO0_Size > 0)
	{
		for(i = 0;i <= ((CAN2_FIFO0_Size - 1) / 4); ++i)
		{
			CAN2_FilerConf.FilterIdHigh = CAN2_FIFO0_FilterId_FilterMaskId[4*i+0];     //32位ID
			CAN2_FilerConf.FilterIdLow = CAN2_FIFO0_FilterId_FilterMaskId[4*i+1];
			CAN2_FilerConf.FilterMaskIdHigh = CAN2_FIFO0_FilterId_FilterMaskId[4*i+2]; //32位MASK
			CAN2_FilerConf.FilterMaskIdLow = CAN2_FIFO0_FilterId_FilterMaskId[4*i+3];  
			CAN2_FilerConf.FilterFIFOAssignment = CAN_FILTER_FIFO0;//过滤器关联到FIFO0
			CAN2_FilerConf.FilterNumber = CAN2_FilterNumber++;          //过滤器
			CAN2_FilerConf.FilterMode = CAN_FILTERMODE_IDLIST;
			CAN2_FilerConf.FilterScale = CAN_FILTERSCALE_16BIT;
			CAN2_FilerConf.FilterActivation = ENABLE; //激活滤波器
			CAN2_FilerConf.BankNumber = 14;

			if(HAL_CAN_ConfigFilter(&CAN2_Handler,&CAN2_FilerConf)!=HAL_OK) return 5;//滤波器初始化
		}
	}
	
	if (CAN2_FIFO1_Size > 0)
	{
		for(i = 0;i <= ((CAN2_FIFO1_Size - 1) / 4); ++i)
		{
			CAN2_FilerConf.FilterIdHigh = CAN2_FIFO1_FilterId_FilterMaskId[4*i+0];     //32位ID
			CAN2_FilerConf.FilterIdLow = CAN2_FIFO1_FilterId_FilterMaskId[4*i+1];
			CAN2_FilerConf.FilterMaskIdHigh = CAN2_FIFO1_FilterId_FilterMaskId[4*i+2]; //32位MASK
			CAN2_FilerConf.FilterMaskIdLow = CAN2_FIFO1_FilterId_FilterMaskId[4*i+3];  
			CAN2_FilerConf.FilterFIFOAssignment = CAN_FILTER_FIFO1;//过滤器关联到FIFO1
			CAN2_FilerConf.FilterNumber = CAN2_FilterNumber++;          //过滤器
			CAN2_FilerConf.FilterMode = CAN_FILTERMODE_IDLIST;
			CAN2_FilerConf.FilterScale = CAN_FILTERSCALE_16BIT;
			CAN2_FilerConf.FilterActivation = ENABLE; //激活滤波器
			CAN2_FilerConf.BankNumber = 14;
			
			if(HAL_CAN_ConfigFilter(&CAN2_Handler,&CAN2_FilerConf)!=HAL_OK) return 6;//滤波器初始化
		}
	}
	return 0;
}

//CAN底层驱动，引脚配置，时钟配置，中断配置
//此函数会被HAL_CAN_Init()调用
//hcan:CAN句柄
void HAL_CAN_MspInit(CAN_HandleTypeDef* hcan)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	if (hcan == (&CAN1_Handler))
	{
	#if USE_CAN1_R0 || USE_CAN1_R1
		CAN1_CLK_ENABLE();
		
		CAN1_RX_GPIO_CLK_ENABLE();
		GPIO_InitStructure.Pin = CAN1_RX_PIN;
		GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;          //推挽复用
		GPIO_InitStructure.Pull = GPIO_PULLUP;              //上拉
		GPIO_InitStructure.Speed = GPIO_SPEED_FAST;         //快速
		GPIO_InitStructure.Alternate = GPIO_AF9_CAN1;       //复用为CAN1
		HAL_GPIO_Init(CAN1_RX_GPIO_PORT, &GPIO_InitStructure);         //初始化
		
		CAN1_TX_GPIO_CLK_ENABLE();
		GPIO_InitStructure.Pin = CAN1_TX_PIN;
		HAL_GPIO_Init(CAN1_TX_GPIO_PORT, &GPIO_InitStructure);         //初始化
		
		__HAL_CAN_ENABLE_IT(&CAN1_Handler, CAN_IT_FMP0);//FIFO0消息挂起中断允许.
		HAL_NVIC_SetPriority(CAN1_RX0_IRQn,2,0);    //抢占优先级1，子优先级0
		HAL_NVIC_EnableIRQ(CAN1_RX0_IRQn);          //使能中断
		__HAL_CAN_ENABLE_IT(&CAN1_Handler, CAN_IT_FMP1);//FIFO1消息挂起中断允许.
		HAL_NVIC_SetPriority(CAN1_RX1_IRQn,2,1);    //抢占优先级1，子优先级1
		HAL_NVIC_EnableIRQ(CAN1_RX1_IRQn);          //使能中断
	#endif
	}
	else if (hcan == (&CAN2_Handler))
	{
	#if USE_CAN2_R0 || USE_CAN2_R1
		CAN2_CLK_ENABLE();
		
		CAN2_RX_GPIO_CLK_ENABLE();
		GPIO_InitStructure.Pin = CAN2_RX_PIN;
		GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;          //推挽复用
		GPIO_InitStructure.Pull = GPIO_PULLUP;              //上拉
		GPIO_InitStructure.Speed = GPIO_SPEED_FAST;         //快速
		GPIO_InitStructure.Alternate = GPIO_AF9_CAN2;       //复用为CAN2
		HAL_GPIO_Init(CAN2_RX_GPIO_PORT, &GPIO_InitStructure);         //初始化
		
		CAN2_TX_GPIO_CLK_ENABLE();
		GPIO_InitStructure.Pin = CAN2_TX_PIN;
		HAL_GPIO_Init(CAN2_TX_GPIO_PORT, &GPIO_InitStructure);         //初始化
		
		__HAL_CAN_ENABLE_IT(&CAN2_Handler, CAN_IT_FMP0);//FIFO0消息挂起中断允许.
		HAL_NVIC_SetPriority(CAN2_RX0_IRQn,2,2);    //抢占优先级1，子优先级2
		HAL_NVIC_EnableIRQ(CAN2_RX0_IRQn);          //使能中断
		__HAL_CAN_ENABLE_IT(&CAN2_Handler, CAN_IT_FMP1);//FIFO1消息挂起中断允许.
		HAL_NVIC_SetPriority(CAN2_RX1_IRQn,2,3);    //抢占优先级1，子优先级3
		HAL_NVIC_EnableIRQ(CAN2_RX1_IRQn);          //使能中断
	#endif
	}
}

//CAN中断服务函数
void CAN1_RX0_IRQHandler(void)
{
	u8 i;
	
	HAL_CAN_Receive(&CAN1_Handler, CAN_FIFO0, 0);
	if(HASH_TABLE[CAN1_RxMessage.StdId] < Can_Data_Num)
	{
		if(Can_Database[HASH_TABLE[CAN1_RxMessage.StdId]].Data_length == CAN1_RxMessage.DLC)
		#if CAN_MASTER == 1
			if(Can_Database[HASH_TABLE[CAN1_RxMessage.StdId]].Data_type == READ_ONLY)
		#else
			if(Can_Database[HASH_TABLE[CAN1_RxMessage.StdId]].Data_type == WRITE_ONLY)
		#endif
				if(Can_Database[HASH_TABLE[CAN1_RxMessage.StdId]].Channel == 1)
					if(Can_Database[HASH_TABLE[CAN1_RxMessage.StdId]].Fifo_num == CAN_FILTER_FIFO0)
					{
						for(i = 0; i < CAN1_RxMessage.DLC; ++i)
							(*(Can_Database[HASH_TABLE[CAN1_RxMessage.StdId]].Data_ptr+i)) = CAN1_RxMessage.Data[i];
						Can_Database[HASH_TABLE[CAN1_RxMessage.StdId]].MenuFunc();
					}
	}
}

void CAN1_RX1_IRQHandler(void)
{
	u8 i;
	
	HAL_CAN_Receive(&CAN1_Handler, CAN_FIFO1, 0);
	if(HASH_TABLE[CAN1_RxMessage.StdId] < Can_Data_Num)
	{
		if(Can_Database[HASH_TABLE[CAN1_RxMessage.StdId]].Data_length == CAN1_RxMessage.DLC)
		#if CAN_MASTER == 1
			if(Can_Database[HASH_TABLE[CAN1_RxMessage.StdId]].Data_type == READ_ONLY)
		#else
			if(Can_Database[HASH_TABLE[CAN1_RxMessage.StdId]].Data_type == WRITE_ONLY)
		#endif
				if(Can_Database[HASH_TABLE[CAN1_RxMessage.StdId]].Channel == 1)
					if(Can_Database[HASH_TABLE[CAN1_RxMessage.StdId]].Fifo_num == CAN_FILTER_FIFO1)
					{
						for(i = 0; i < CAN1_RxMessage.DLC; ++i)
							(*(Can_Database[HASH_TABLE[CAN1_RxMessage.StdId]].Data_ptr+i)) = CAN1_RxMessage.Data[i];
						Can_Database[HASH_TABLE[CAN1_RxMessage.StdId]].MenuFunc();
					}	
	}
}

void CAN2_RX0_IRQHandler(void)
{
	u8 i;
	
	HAL_CAN_Receive(&CAN2_Handler, CAN_FIFO0, 0);
	if(HASH_TABLE[CAN2_RxMessage.StdId] < Can_Data_Num)
	{
		if(Can_Database[HASH_TABLE[CAN2_RxMessage.StdId]].Data_length == CAN2_RxMessage.DLC)
		#if CAN_MASTER == 1
			if(Can_Database[HASH_TABLE[CAN2_RxMessage.StdId]].Data_type == READ_ONLY)
		#else
			if(Can_Database[HASH_TABLE[CAN2_RxMessage.StdId]].Data_type == WRITE_ONLY)
		#endif
				if(Can_Database[HASH_TABLE[CAN2_RxMessage.StdId]].Channel == 2)
					if(Can_Database[HASH_TABLE[CAN2_RxMessage.StdId]].Fifo_num == CAN_FILTER_FIFO0)
					{
						for(i = 0; i < CAN2_RxMessage.DLC; ++i)
							(*(Can_Database[HASH_TABLE[CAN2_RxMessage.StdId]].Data_ptr+i)) = CAN2_RxMessage.Data[i];
						Can_Database[HASH_TABLE[CAN2_RxMessage.StdId]].MenuFunc();
					}
	}
}

void CAN2_RX1_IRQHandler(void)
{
  u8 i;
	
	HAL_CAN_Receive(&CAN2_Handler, CAN_FIFO1, 0);
	if(HASH_TABLE[CAN2_RxMessage.StdId] < Can_Data_Num)
	{
		if(Can_Database[HASH_TABLE[CAN2_RxMessage.StdId]].Data_length == CAN2_RxMessage.DLC)
		#if CAN_MASTER == 1
			if(Can_Database[HASH_TABLE[CAN2_RxMessage.StdId]].Data_type == READ_ONLY)
		#else
			if(Can_Database[HASH_TABLE[CAN2_RxMessage.StdId]].Data_type == WRITE_ONLY)
		#endif
				if(Can_Database[HASH_TABLE[CAN2_RxMessage.StdId]].Channel == 2)
					if(Can_Database[HASH_TABLE[CAN2_RxMessage.StdId]].Fifo_num == CAN_FILTER_FIFO1)
					{
						for(i = 0; i < CAN2_RxMessage.DLC; ++i)
							(*(Can_Database[HASH_TABLE[CAN2_RxMessage.StdId]].Data_ptr+i)) = CAN2_RxMessage.Data[i];
						Can_Database[HASH_TABLE[CAN2_RxMessage.StdId]].MenuFunc();
					}
	}
}

void Can_SendData(CAN_HandleTypeDef* hcan)
{
	if(HAL_CAN_Transmit(hcan,30)!=HAL_OK)
	{
		
	}
}
