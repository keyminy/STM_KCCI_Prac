/*
 * RoadSignBoardController.c
 *
 *  Created on: 2025. 1. 26.
 *      Author: me
 */

#include "RoadSignBoardController.h"

uint8_t roadSignBoardState;
uint16_t roadSignBoardSpeedTime;

void RoadSignBoard_Init(void){
	RoadSignBoard_SetState(IDLE);
	RoadSignBoard_SetSpeedTime(100);// 초기값 설정 : 100ms
}

void RoadSignBoard_SetSpeedTime(uint16_t speedTime){
	roadSignBoardSpeedTime = speedTime;
}

uint16_t RoadSignBoard_GetSpeedTime(void){
	return roadSignBoardSpeedTime;
}

void RoadSignBoard_ChangeSpeedTime(void){
	// 0.1s, 0.2s, 0.3s, 0.4s, 0.5s
//	RoadSignBoard_SetSpeedTime(RoadSignBoard_GetSpeedTime()+10);

	static uint8_t speedState = 0;
	// use array
	uint16_t speedTime[] = {100,200,300,400,500};
	speedState = (speedState + 1) % (sizeof(speedTime)/sizeof(uint16_t));
	roadSignBoardSpeedTime = speedTime[speedState];
}

void RoadSignBoard_SetState(uint8_t state){
	roadSignBoardState = state;
}

uint8_t RoadSignBoard_GetState(void){
	return roadSignBoardState;
}

void RoadSignBoardController(void){
	switch(RoadSignBoard_GetState()){
	case IDLE:
		RoadSignBoard_Idle_State();
		break;
	case LEFT_SIGN:
		RoadSignBoard_Left_State();
		break;
	case RIGHT_SIGN:
		RoadSignBoard_Right_State();
		break;
	case TWOWAY_SIGN:
		RoadSignBoard_TwoWay_State();
		break;
	case BLINK:
		RoadSignBoard_Blink_State();
		break;
	}
}

void RoadSignBoard_ExcuteHandler(void (*pfLED_DirectionSign)(void)){
	static uint32_t prevTime = 0;

	if(HAL_GetTick() - prevTime > RoadSignBoard_GetSpeedTime()){
		prevTime = HAL_GetTick();
		pfLED_DirectionSign(); //LED_LeftSign(); // Excute Function
	}
}

void RoadSignBoard_Idle_State(void){
	LED_AllOff();
	RoadSignBoardEventHandler(LEFT_SIGN);
}

void RoadSignBoard_Left_State(void){
	RoadSignBoard_ExcuteHandler(LED_LeftSign);

//	static uint32_t prevTime = 0;
//
//	if(HAL_GetTick() - prevTime > RoadSignBoard_GetSpeedTime()){
//		prevTime = HAL_GetTick();
//		LED_LeftSign();
//	}
	RoadSignBoardEventHandler(RIGHT_SIGN);
}


void RoadSignBoard_Right_State(void){
	RoadSignBoard_ExcuteHandler(LED_RightSign);
//	static uint32_t prevTime = 0;
//	if(HAL_GetTick() - prevTime > RoadSignBoard_GetSpeedTime()){
//		prevTime = HAL_GetTick();
//		LED_RightSign();
//	}
	RoadSignBoardEventHandler(TWOWAY_SIGN);
}

void RoadSignBoard_TwoWay_State(void){
	RoadSignBoard_ExcuteHandler(LED_TwoWaySign);
//	static uint32_t prevTime = 0;
//	if(HAL_GetTick() - prevTime > RoadSignBoard_GetSpeedTime()){
//		prevTime = HAL_GetTick();
//		LED_TwoWaySign();
//	}
	RoadSignBoardEventHandler(BLINK);
}

void RoadSignBoard_Blink_State(void){
	RoadSignBoard_ExcuteHandler(LED_AllBlink);
//	static uint32_t prevTime = 0;
//
//	if(HAL_GetTick() - prevTime > RoadSignBoard_GetSpeedTime()){
////	if(HAL_GetTick() - prevTime > 300){
//		prevTime = HAL_GetTick();
//		LED_AllBlink();
//	}
	RoadSignBoardEventHandler(IDLE);
}
