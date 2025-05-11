/*
 * Queue.h
 *
 *  Created on: 2025. 3. 3.
 *      Author: me
 */

#ifndef SYSTEM_QUEUE_H_
#define SYSTEM_QUEUE_H_

#include "main.h"

#define QBuffLen 30
#define TRUE 1
#define FALSE 0

typedef struct {
	uint8_t qBuffer[QBuffLen];
	uint8_t head;
	uint8_t tail;
} QUEUE_HandleTypeDef;

extern QUEUE_HandleTypeDef hQue_ButtonRunStop;

void EnQueue(QUEUE_HandleTypeDef *hQue,uint8_t data);
uint8_t DeQueue(QUEUE_HandleTypeDef *hQue);
uint8_t QisEmpty(QUEUE_HandleTypeDef *hQue);
uint8_t QisFull(QUEUE_HandleTypeDef *hQue);

#endif /* SYSTEM_QUEUE_H_ */
