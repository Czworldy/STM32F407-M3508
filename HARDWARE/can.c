#include "all.h"

CAN_HandleTypeDef   CAN1_Handler;   //CAN1���
CanTxMsgTypeDef     CAN1_TxMessage;      //������Ϣ
CanRxMsgTypeDef     CAN1_RxMessage;      //������Ϣ

CAN_HandleTypeDef   CAN2_Handler;   //CAN2���
CanTxMsgTypeDef     CAN2_TxMessage;      //������Ϣ
CanRxMsgTypeDef     CAN2_RxMessage;      //������Ϣ

////CAN��ʼ��
//tsjw:����ͬ����Ծʱ�䵥Ԫ.��Χ:CAN_SJW_1TQ~CAN_SJW_4TQ
//tbs2:ʱ���2��ʱ�䵥Ԫ.   ��Χ:CAN_BS2_1TQ~CAN_BS2_8TQ;
//tbs1:ʱ���1��ʱ�䵥Ԫ.   ��Χ:CAN_BS1_1TQ~CAN_BS1_16TQ
//brp :�����ʷ�Ƶ��.��Χ:1~1024; tq=(brp)*tpclk1
//������=Fpclk1/((tbs1+tbs2+1)*brp); ����tbs1��tbs2����ֻ�ù�ע��ʶ���ϱ�־����ţ�����CAN_BS2_1TQ�����Ǿ���Ϊtbs2=1�����㼴�ɡ�
//mode:CAN_MODE_NORMAL,��ͨģʽ;CAN_MODE_LOOPBACK,�ػ�ģʽ;
//Fpclk1��ʱ���ڳ�ʼ����ʱ������Ϊ42M,�������CAN1_Mode_Init(CAN_SJW_1tq,CAN_BS2_3tq,CAN_BS1_3tq,6,CAN_MODE_LOOPBACK);
//������Ϊ:42M/((3+3+1)*6)=1Mbps
//����ֵ:0,��ʼ��OK;
//    ����,��ʼ��ʧ��; 

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
	CAN1_Handler.pTxMsg = &CAN1_TxMessage;     //������Ϣ
	CAN1_Handler.pRxMsg = &CAN1_RxMessage;     //������Ϣ
	CAN1_Handler.Init.Prescaler = CAN1_Prescaler;    //��Ƶϵ��(Fdiv)Ϊbrp+1
	CAN1_Handler.Init.Mode = CAN_MODE_NORMAL;        //ģʽ���� 
	CAN1_Handler.Init.SJW = CAN_SJW_2TQ;         //����ͬ����Ծ���(Tsjw)Ϊtsjw+1��ʱ�䵥λ CAN_SJW_1TQ~CAN_SJW_4TQ
	CAN1_Handler.Init.BS1 = CAN_BS1_3TQ;         //tbs1��ΧCAN_BS1_1TQ~CAN_BS1_16TQ
	CAN1_Handler.Init.BS2 = CAN_BS2_3TQ;         //tbs2��ΧCAN_BS2_1TQ~CAN_BS2_8TQ
	CAN1_Handler.Init.TTCM = DISABLE;     //��ʱ�䴥��ͨ��ģʽ 
	CAN1_Handler.Init.ABOM = DISABLE;     //����Զ����߹���
	CAN1_Handler.Init.AWUM = DISABLE;     //˯��ģʽͨ���������(���CAN->MCR��SLEEPλ)
	CAN1_Handler.Init.NART = DISABLE;      //ʧ�ܷ��Զ��ش���ģʽ,���Զ��ش�
	CAN1_Handler.Init.RFLM = DISABLE;     //���Ĳ�����,�µĸ��Ǿɵ� 
	CAN1_Handler.Init.TXFP = ENABLE;      //ʹ�ܷ���FIFO���ȼ�,����˳���ɷ���˳����� DISABLE:ID����
	
	if(HAL_CAN_Init(&CAN1_Handler)!=HAL_OK) return 1;   //��ʼ��
#endif

#if USE_CAN2_R0 || USE_CAN2_R1
	CAN2_Handler.Instance = CAN2;
	CAN2_Handler.pTxMsg = &CAN2_TxMessage;     //������Ϣ
	CAN2_Handler.pRxMsg = &CAN2_RxMessage;     //������Ϣ
	CAN2_Handler.Init.Prescaler = CAN2_Prescaler;    //��Ƶϵ��(Fdiv)Ϊbrp+1
	CAN2_Handler.Init.Mode = CAN_MODE_NORMAL;        //ģʽ���� 
	CAN2_Handler.Init.SJW = CAN_SJW_2TQ;         //����ͬ����Ծ���(Tsjw)Ϊtsjw+1��ʱ�䵥λ CAN_SJW_1TQ~CAN_SJW_4TQ
	CAN2_Handler.Init.BS1 = CAN_BS1_3TQ;         //tbs1��ΧCAN_BS1_1TQ~CAN_BS1_16TQ
	CAN2_Handler.Init.BS2 = CAN_BS2_3TQ;         //tbs2��ΧCAN_BS2_1TQ~CAN_BS2_8TQ
	CAN2_Handler.Init.TTCM = DISABLE;     //��ʱ�䴥��ͨ��ģʽ 
	CAN2_Handler.Init.ABOM = DISABLE;     //ʧ���Զ����߹���
	CAN2_Handler.Init.AWUM = DISABLE;     //˯��ģʽͨ���������(���CAN->MCR��SLEEPλ)
	CAN2_Handler.Init.NART = DISABLE;      //ʧ�ܷ��Զ��ش���ģʽ,���Զ��ش�
	CAN2_Handler.Init.RFLM = DISABLE;     //���Ĳ�����,�µĸ��Ǿɵ� 
	CAN2_Handler.Init.TXFP = ENABLE;      //ʹ�ܷ���FIFO���ȼ�,����˳���ɷ���˳����� DISABLE:ID����
	
	if(HAL_CAN_Init(&CAN2_Handler)!=HAL_OK) return 2;   //��ʼ��
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
			CAN1_FilerConf.FilterIdHigh = CAN1_FIFO0_FilterId_FilterMaskId[4*i+0];     //32λID
			CAN1_FilerConf.FilterIdLow = CAN1_FIFO0_FilterId_FilterMaskId[4*i+1];
			CAN1_FilerConf.FilterMaskIdHigh = CAN1_FIFO0_FilterId_FilterMaskId[4*i+2]; //32λMASK
			CAN1_FilerConf.FilterMaskIdLow = CAN1_FIFO0_FilterId_FilterMaskId[4*i+3];  
			CAN1_FilerConf.FilterFIFOAssignment = CAN_FILTER_FIFO0;//������������FIFO0
			CAN1_FilerConf.FilterNumber = CAN1_FilterNumber++;          //������
			CAN1_FilerConf.FilterMode = CAN_FILTERMODE_IDLIST;
			CAN1_FilerConf.FilterScale = CAN_FILTERSCALE_16BIT;
			CAN1_FilerConf.FilterActivation = ENABLE; //�����˲���
			CAN1_FilerConf.BankNumber = 14;

			if(HAL_CAN_ConfigFilter(&CAN1_Handler,&CAN1_FilerConf)!=HAL_OK) return 3;//�˲�����ʼ��
		}
	}
	
	if (CAN1_FIFO1_Size > 0)
	{
		for(i = 0;i <= ((CAN1_FIFO1_Size - 1) / 4); ++i)
		{
			CAN1_FilerConf.FilterIdHigh = CAN1_FIFO1_FilterId_FilterMaskId[4*i+0];     //32λID
			CAN1_FilerConf.FilterIdLow = CAN1_FIFO1_FilterId_FilterMaskId[4*i+1];
			CAN1_FilerConf.FilterMaskIdHigh = CAN1_FIFO1_FilterId_FilterMaskId[4*i+2]; //32λMASK
			CAN1_FilerConf.FilterMaskIdLow = CAN1_FIFO1_FilterId_FilterMaskId[4*i+3];  
			CAN1_FilerConf.FilterFIFOAssignment = CAN_FILTER_FIFO1;//������������FIFO1
			CAN1_FilerConf.FilterNumber = CAN1_FilterNumber++;          //������
			CAN1_FilerConf.FilterMode = CAN_FILTERMODE_IDLIST;
			CAN1_FilerConf.FilterScale = CAN_FILTERSCALE_16BIT;
			CAN1_FilerConf.FilterActivation = ENABLE; //�����˲���
			CAN1_FilerConf.BankNumber = 14;
			
			if(HAL_CAN_ConfigFilter(&CAN1_Handler,&CAN1_FilerConf)!=HAL_OK) return 4;//�˲�����ʼ��
		}
	}
	
	if (CAN2_FIFO0_Size > 0)
	{
		for(i = 0;i <= ((CAN2_FIFO0_Size - 1) / 4); ++i)
		{
			CAN2_FilerConf.FilterIdHigh = CAN2_FIFO0_FilterId_FilterMaskId[4*i+0];     //32λID
			CAN2_FilerConf.FilterIdLow = CAN2_FIFO0_FilterId_FilterMaskId[4*i+1];
			CAN2_FilerConf.FilterMaskIdHigh = CAN2_FIFO0_FilterId_FilterMaskId[4*i+2]; //32λMASK
			CAN2_FilerConf.FilterMaskIdLow = CAN2_FIFO0_FilterId_FilterMaskId[4*i+3];  
			CAN2_FilerConf.FilterFIFOAssignment = CAN_FILTER_FIFO0;//������������FIFO0
			CAN2_FilerConf.FilterNumber = CAN2_FilterNumber++;          //������
			CAN2_FilerConf.FilterMode = CAN_FILTERMODE_IDLIST;
			CAN2_FilerConf.FilterScale = CAN_FILTERSCALE_16BIT;
			CAN2_FilerConf.FilterActivation = ENABLE; //�����˲���
			CAN2_FilerConf.BankNumber = 14;

			if(HAL_CAN_ConfigFilter(&CAN2_Handler,&CAN2_FilerConf)!=HAL_OK) return 5;//�˲�����ʼ��
		}
	}
	
	if (CAN2_FIFO1_Size > 0)
	{
		for(i = 0;i <= ((CAN2_FIFO1_Size - 1) / 4); ++i)
		{
			CAN2_FilerConf.FilterIdHigh = CAN2_FIFO1_FilterId_FilterMaskId[4*i+0];     //32λID
			CAN2_FilerConf.FilterIdLow = CAN2_FIFO1_FilterId_FilterMaskId[4*i+1];
			CAN2_FilerConf.FilterMaskIdHigh = CAN2_FIFO1_FilterId_FilterMaskId[4*i+2]; //32λMASK
			CAN2_FilerConf.FilterMaskIdLow = CAN2_FIFO1_FilterId_FilterMaskId[4*i+3];  
			CAN2_FilerConf.FilterFIFOAssignment = CAN_FILTER_FIFO1;//������������FIFO1
			CAN2_FilerConf.FilterNumber = CAN2_FilterNumber++;          //������
			CAN2_FilerConf.FilterMode = CAN_FILTERMODE_IDLIST;
			CAN2_FilerConf.FilterScale = CAN_FILTERSCALE_16BIT;
			CAN2_FilerConf.FilterActivation = ENABLE; //�����˲���
			CAN2_FilerConf.BankNumber = 14;
			
			if(HAL_CAN_ConfigFilter(&CAN2_Handler,&CAN2_FilerConf)!=HAL_OK) return 6;//�˲�����ʼ��
		}
	}
	return 0;
}

//CAN�ײ��������������ã�ʱ�����ã��ж�����
//�˺����ᱻHAL_CAN_Init()����
//hcan:CAN���
void HAL_CAN_MspInit(CAN_HandleTypeDef* hcan)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	if (hcan == (&CAN1_Handler))
	{
	#if USE_CAN1_R0 || USE_CAN1_R1
		CAN1_CLK_ENABLE();
		
		CAN1_RX_GPIO_CLK_ENABLE();
		GPIO_InitStructure.Pin = CAN1_RX_PIN;
		GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;          //���츴��
		GPIO_InitStructure.Pull = GPIO_PULLUP;              //����
		GPIO_InitStructure.Speed = GPIO_SPEED_FAST;         //����
		GPIO_InitStructure.Alternate = GPIO_AF9_CAN1;       //����ΪCAN1
		HAL_GPIO_Init(CAN1_RX_GPIO_PORT, &GPIO_InitStructure);         //��ʼ��
		
		CAN1_TX_GPIO_CLK_ENABLE();
		GPIO_InitStructure.Pin = CAN1_TX_PIN;
		HAL_GPIO_Init(CAN1_TX_GPIO_PORT, &GPIO_InitStructure);         //��ʼ��
		
		__HAL_CAN_ENABLE_IT(&CAN1_Handler, CAN_IT_FMP0);//FIFO0��Ϣ�����ж�����.
		HAL_NVIC_SetPriority(CAN1_RX0_IRQn,2,0);    //��ռ���ȼ�1�������ȼ�0
		HAL_NVIC_EnableIRQ(CAN1_RX0_IRQn);          //ʹ���ж�
		__HAL_CAN_ENABLE_IT(&CAN1_Handler, CAN_IT_FMP1);//FIFO1��Ϣ�����ж�����.
		HAL_NVIC_SetPriority(CAN1_RX1_IRQn,2,1);    //��ռ���ȼ�1�������ȼ�1
		HAL_NVIC_EnableIRQ(CAN1_RX1_IRQn);          //ʹ���ж�
	#endif
	}
	else if (hcan == (&CAN2_Handler))
	{
	#if USE_CAN2_R0 || USE_CAN2_R1
		CAN2_CLK_ENABLE();
		
		CAN2_RX_GPIO_CLK_ENABLE();
		GPIO_InitStructure.Pin = CAN2_RX_PIN;
		GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;          //���츴��
		GPIO_InitStructure.Pull = GPIO_PULLUP;              //����
		GPIO_InitStructure.Speed = GPIO_SPEED_FAST;         //����
		GPIO_InitStructure.Alternate = GPIO_AF9_CAN2;       //����ΪCAN2
		HAL_GPIO_Init(CAN2_RX_GPIO_PORT, &GPIO_InitStructure);         //��ʼ��
		
		CAN2_TX_GPIO_CLK_ENABLE();
		GPIO_InitStructure.Pin = CAN2_TX_PIN;
		HAL_GPIO_Init(CAN2_TX_GPIO_PORT, &GPIO_InitStructure);         //��ʼ��
		
		__HAL_CAN_ENABLE_IT(&CAN2_Handler, CAN_IT_FMP0);//FIFO0��Ϣ�����ж�����.
		HAL_NVIC_SetPriority(CAN2_RX0_IRQn,2,2);    //��ռ���ȼ�1�������ȼ�2
		HAL_NVIC_EnableIRQ(CAN2_RX0_IRQn);          //ʹ���ж�
		__HAL_CAN_ENABLE_IT(&CAN2_Handler, CAN_IT_FMP1);//FIFO1��Ϣ�����ж�����.
		HAL_NVIC_SetPriority(CAN2_RX1_IRQn,2,3);    //��ռ���ȼ�1�������ȼ�3
		HAL_NVIC_EnableIRQ(CAN2_RX1_IRQn);          //ʹ���ж�
	#endif
	}
}

//CAN�жϷ�����
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
