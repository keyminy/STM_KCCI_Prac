/*
 * uart.h
 *
 *  Created on: 2025. 3. 3.
 *      Author: me
 */

#ifndef DRIVER_UART_H_
#define DRIVER_UART_H_
#include "main.h"

typedef struct {
	UART_HandleTypeDef *huart;
	uint8_t readyFlag;
	uint8_t tail;
	uint8_t uartRxData;
	uint8_t buffer[30];
} QUART_HandleTypeDef;

// 외부에서도 사용할 수 있게 extern
extern QUART_HandleTypeDef hQBuff;

void UART_Init(QUART_HandleTypeDef *hQUart, UART_HandleTypeDef *hMyUart);
void UART_ISR_Process(QUART_HandleTypeDef *hQUart);
uint8_t *UART_GetBuff(QUART_HandleTypeDef *hQUart);
uint8_t UART_GetReadyQBuff(QUART_HandleTypeDef *hQUart);
uint8_t UART_SetReadyQBuff(QUART_HandleTypeDef *hQUart,uint8_t flag);


#endif /* DRIVER_UART_H_ */
