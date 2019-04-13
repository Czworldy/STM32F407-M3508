#ifndef _USART_H
#define _USART_H

#include "sys.h"

//#define BSP_USING_USART1
#define BSP_USING_USART2
#define BSP_USING_USART3
#define BSP_USING_UART4
//#define BSP_USING_UART5
#define BSP_USING_USART6

#define RXBUFFERSIZE 1 //缓存大小

#ifdef BSP_USING_USART1
	#define USART1_BAUDRATE 							115200
	#define USART1_CLK_ENABLE() 					__HAL_RCC_USART1_CLK_ENABLE()

	#define USART1_RX_GPIO_CLK_ENABLE() 	__HAL_RCC_GPIOA_CLK_ENABLE()
	#define USART1_RX_PIN 								GPIO_PIN_10
	#define USART1_RX_GPIO_PORT 					GPIOA
	
	#define USART1_TX_GPIO_CLK_ENABLE() 	__HAL_RCC_GPIOA_CLK_ENABLE()
	#define USART1_TX_PIN 								GPIO_PIN_9
	#define USART1_TX_GPIO_PORT 					GPIOA

	extern UART_HandleTypeDef USART1_Handler; //UART句柄
	extern u8 USART1_RxBuffer[];//HAL库USART接收Buffer
#endif

#ifdef BSP_USING_USART2
	#define USART2_BAUDRATE	 							115200
	#define USART2_CLK_ENABLE() 					__HAL_RCC_USART2_CLK_ENABLE()

	#define USART2_RX_GPIO_CLK_ENABLE()		__HAL_RCC_GPIOA_CLK_ENABLE()
	#define USART2_RX_PIN 								GPIO_PIN_3
	#define USART2_RX_GPIO_PORT 					GPIOA
	
	#define USART2_TX_GPIO_CLK_ENABLE() 	__HAL_RCC_GPIOA_CLK_ENABLE()
	#define USART2_TX_PIN 								GPIO_PIN_2
	#define USART2_TX_GPIO_PORT 					GPIOA
	
	extern UART_HandleTypeDef USART2_Handler; //UART句柄
	extern u8 USART2_RxBuffer[];//HAL库USART接收Buffer
#endif

#ifdef BSP_USING_USART3
	#define USART3_BAUDRATE 							115200
	#define USART3_CLK_ENABLE() 					__HAL_RCC_USART3_CLK_ENABLE()

	#define USART3_RX_GPIO_CLK_ENABLE() 	__HAL_RCC_GPIOB_CLK_ENABLE()
	#define USART3_RX_PIN 								GPIO_PIN_11
	#define USART3_RX_GPIO_PORT 					GPIOB
	
	#define USART3_TX_GPIO_CLK_ENABLE() 	__HAL_RCC_GPIOB_CLK_ENABLE()
	#define USART3_TX_PIN 								GPIO_PIN_10
	#define USART3_TX_GPIO_PORT 					GPIOB
	
	extern UART_HandleTypeDef USART3_Handler; //UART句柄
	extern u8 USART3_RxBuffer[];//HAL库USART接收Buffer
#endif

#ifdef BSP_USING_UART4
	#define UART4_BAUDRATE 							115200
	#define UART4_CLK_ENABLE() 					__HAL_RCC_UART4_CLK_ENABLE()

	#define UART4_RX_GPIO_CLK_ENABLE()	__HAL_RCC_GPIOA_CLK_ENABLE()
	#define UART4_RX_PIN 								GPIO_PIN_1
	#define UART4_RX_GPIO_PORT 					GPIOA
	
	#define UART4_TX_GPIO_CLK_ENABLE() 	__HAL_RCC_GPIOA_CLK_ENABLE()
	#define UART4_TX_PIN 								GPIO_PIN_0
	#define UART4_TX_GPIO_PORT 					GPIOA
	
	extern UART_HandleTypeDef UART4_Handler; //UART句柄
	extern u8 UART4_RxBuffer[];//HAL库USART接收Buffer
#endif

#ifdef BSP_USING_UART5
	#define UART5_BAUDRATE 							115200
	#define UART5_CLK_ENABLE() 					__HAL_RCC_UART5_CLK_ENABLE()

	#define UART5_RX_GPIO_CLK_ENABLE() 	__HAL_RCC_GPIOD_CLK_ENABLE()
	#define UART5_RX_PIN 								GPIO_PIN_2
	#define UART5_RX_GPIO_PORT 					GPIOD
	
	#define UART5_TX_GPIO_CLK_ENABLE() 	__HAL_RCC_GPIOC_CLK_ENABLE()
	#define UART5_TX_PIN 								GPIO_PIN_12
	#define UART5_TX_GPIO_PORT 					GPIOC
	
	extern UART_HandleTypeDef UART5_Handler; //UART句柄
	extern u8 UART5_RxBuffer[];//HAL库USART接收Buffer
#endif

#ifdef BSP_USING_USART6
	#define USART6_BAUDRATE 							115200
	#define USART6_CLK_ENABLE() 					__HAL_RCC_USART6_CLK_ENABLE()

	#define USART6_RX_GPIO_CLK_ENABLE()	 	__HAL_RCC_GPIOC_CLK_ENABLE()
	#define USART6_RX_PIN 								GPIO_PIN_7
	#define USART6_RX_GPIO_PORT 					GPIOC
	
	#define USART6_TX_GPIO_CLK_ENABLE() 	__HAL_RCC_GPIOC_CLK_ENABLE()
	#define USART6_TX_PIN 								GPIO_PIN_6
	#define USART6_TX_GPIO_PORT 					GPIOC
	
	extern UART_HandleTypeDef USART6_Handler; //UART句柄
	extern u8 USART6_RxBuffer[];//HAL库USART接收Buffer
#endif

void UART_Config(void);
void UART_SendByte(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout);
void UART_GetByte(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout);
void UART_puts(UART_HandleTypeDef *huart, uint8_t *pData);
void UART_printf(UART_HandleTypeDef *huart, char *fmt, ...);


#endif
