/*
 * Queue.c
 *
 *  Created on: 2025. 3. 3.
 *      Author: me
 */
#include "Queue.h"

QUEUE_HandleTypeDef hQueA = {{0,},0,0};
QUEUE_HandleTypeDef hQueB = {{0,},0,0};

void EnQueue(QUEUE_HandleTypeDef *hQue,uint8_t data)
{
	if(QisFull(hQue)){
		return;
	}else{
		hQue->tail = (hQue->tail+1) % QBuffLen; // tail = 29이면 tail = 0
		hQue->qBuffer[hQue->tail] = data;
	}
}
uint8_t DeQueue(QUEUE_HandleTypeDef *hQue){
	if(QisEmpty(hQue)){
		return -1;
	}else{
		hQue->head = (hQue->head+1) % QBuffLen; // head = 29이면 haed = 0
		return hQue->qBuffer[hQue->head];
	}
}

uint8_t QisEmpty(QUEUE_HandleTypeDef *hQue){
	if(hQue->tail == hQue->head){
		return TRUE;
	} else{
		return FALSE;
	}
}

uint8_t QisFull(QUEUE_HandleTypeDef *hQue){
	if(((hQue->tail+1) % QBuffLen) == hQue->head){
		return TRUE;
	}else{
		return FALSE;
	}
}
