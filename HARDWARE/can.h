#ifndef __CAN_H
#define __CAN_H

#include "sys.h"

#define CAN_MASTER 1

#define CAN1_BAUDRATE 1000
#define CAN2_BAUDRATE 1000

#if CAN1_BAUDRATE == 1000 /* 1MBps */
	#define CAN1_Prescaler 6
#elif CAN1_BAUDRATE == 500 /* 500KBps */
  #define CAN1_Prescaler 12
#elif CAN1_BAUDRATE == 250 /* 250KBps */
  #define CAN1_Prescaler 24
#elif CAN1_BAUDRATE == 125 /* 125KBps */
  #define CAN1_Prescaler 48
#endif

#if CAN2_BAUDRATE == 1000 /* 1MBps */
	#define CAN2_Prescaler 6
#elif CAN2_BAUDRATE == 500 /* 500KBps */
  #define CAN2_Prescaler 12
#elif CAN2_BAUDRATE == 250 /* 250KBps */
  #define CAN2_Prescaler 24
#elif CAN2_BAUDRATE == 125 /* 125KBps */
  #define CAN2_Prescaler 48
#endif

//是否使能相应can总线，及其FIFO
#define USE_CAN1_R0	1
#define USE_CAN1_R1	1
#define USE_CAN2_R0	1
#define USE_CAN2_R1	1

#if USE_CAN1_R0 || USE_CAN1_R1
	#define CAN1_CLK_ENABLE() 					__HAL_RCC_CAN1_CLK_ENABLE()

	#define CAN1_RX_GPIO_CLK_ENABLE()		__HAL_RCC_GPIOB_CLK_ENABLE()
	#define CAN1_RX_PIN 								GPIO_PIN_8
	#define CAN1_RX_GPIO_PORT 					GPIOB
	
	#define CAN1_TX_GPIO_CLK_ENABLE() 	__HAL_RCC_GPIOB_CLK_ENABLE()
	#define CAN1_TX_PIN 								GPIO_PIN_9
	#define CAN1_TX_GPIO_PORT 					GPIOB
#endif

#if USE_CAN2_R0 || USE_CAN2_R1
	#define CAN2_CLK_ENABLE() 					__HAL_RCC_CAN2_CLK_ENABLE()

	#define CAN2_RX_GPIO_CLK_ENABLE()		__HAL_RCC_GPIOB_CLK_ENABLE()
	#define CAN2_RX_PIN 								GPIO_PIN_12
	#define CAN2_RX_GPIO_PORT 					GPIOB
	
	#define CAN2_TX_GPIO_CLK_ENABLE() 	__HAL_RCC_GPIOB_CLK_ENABLE()
	#define CAN2_TX_PIN 								GPIO_PIN_13
	#define CAN2_TX_GPIO_PORT 					GPIOB
#endif

extern CAN_HandleTypeDef   CAN1_Handler;   //CAN1句柄
extern CanTxMsgTypeDef     CAN1_TxMessage;      //发送消息
extern CanRxMsgTypeDef     CAN1_RxMessage;      //接收消息

extern CAN_HandleTypeDef   CAN2_Handler;   //CAN2句柄
extern CanTxMsgTypeDef     CAN2_TxMessage;      //发送消息
extern CanRxMsgTypeDef     CAN2_RxMessage;      //接收消息

u8 CAN_Mode_Init(void);//CAN初始化
void Can_SendData(CAN_HandleTypeDef* hcan);

#endif
