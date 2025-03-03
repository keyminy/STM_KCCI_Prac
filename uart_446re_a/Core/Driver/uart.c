/*
 * uart.c
 *
 *  Created on: 2025. 3. 3.
 *      Author: me
 */
#include "uart.h"

QUART_HandleTypeDef hQBuff = {
		0, // UART_HandleTypeDef *huart;
		0, //uint8_t readyFlag;
		0, // uint8_t tail;
		0, // uint8_t uartRxData;
		{0,} // uint8_t buffer[30];
};
//uint8_t uart2RxData;
//UART_HandleTypeDef *huart;


void UART_Init(QUART_HandleTypeDef *hQUart, UART_HandleTypeDef *hMyUart){
	hQUart->huart = hMyUart;
//	huart = hMyUart;
//	 HAL_UART_Receive_IT(hQUart->huart, &uart2RxData, 1); // important! resetting IT EN
	 HAL_UART_Receive_IT(hQUart->huart, &hQUart->uartRxData, 1); // important! resetting IT EN
}

void UART_ISR_Process(QUART_HandleTypeDef *hQUart){
	if(hQUart->uartRxData == 0xff){
		hQUart->buffer[hQUart->tail] = '\0';
		hQUart->tail = 0;
		hQUart->readyFlag = 1;
	}else{
		hQUart->buffer[hQUart->tail++] = hQUart->uartRxData;
	}
	 HAL_UART_Receive_IT(hQUart->huart, &hQUart->uartRxData, 1); // important! resetting IT EN
//	 HAL_UART_Receive_IT(huart, &uart2RxData, 1); // important! resetting IT EN
}

uint8_t UART_GetReadyQBuff(QUART_HandleTypeDef *hQUart){
	return hQUart->readyFlag;
}
uint8_t UART_SetReadyQBuff(QUART_HandleTypeDef *hQUart,uint8_t flag){
	hQUart->readyFlag = flag;
}

uint8_t *UART_GetBuff(QUART_HandleTypeDef *hQUart){
	// buffer의 주소를 접근할 수 있는 함수
	return hQUart->buffer;
}
