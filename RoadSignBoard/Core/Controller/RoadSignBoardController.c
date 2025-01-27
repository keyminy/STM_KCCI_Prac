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

void RoadSignBoard_Idle_State(void){
	LED_AllOff();

	if(Button1_GetState()){
		RoadSignBoard_SetState(LEFT_SIGN);
		LED_SetledState(0);
	}

	if(Button2_GetState()){
		RoadSignBoard_ChangeSpeedTime();
	}
}

void RoadSignBoard_Left_State(void){
	static uint32_t prevTime = 0;

	if(HAL_GetTick() - prevTime > RoadSignBoard_GetSpeedTime()){
		prevTime = HAL_GetTick();
		LED_LeftSign();
	}
	if(Button1_GetState()){
		RoadSignBoard_SetState(RIGHT_SIGN);
		LED_SetledState(0);
	}
	if(Button2_GetState()){
		RoadSignBoard_ChangeSpeedTime();
	}
}


void RoadSignBoard_Right_State(void){
	static uint32_t prevTime = 0;
	if(HAL_GetTick() - prevTime > RoadSignBoard_GetSpeedTime()){
		prevTime = HAL_GetTick();
		LED_RightSign();
	}
	if(Button1_GetState()){
		RoadSignBoard_SetState(TWOWAY_SIGN);
		LED_SetledState(0);
	}
	if(Button2_GetState()){
		RoadSignBoard_ChangeSpeedTime();
	}
}

void RoadSignBoard_TwoWay_State(void){
	static uint32_t prevTime = 0;
	if(HAL_GetTick() - prevTime > RoadSignBoard_GetSpeedTime()){
		prevTime = HAL_GetTick();
		LED_TwoWaySign();
	}
	if(Button1_GetState()){
		RoadSignBoard_SetState(BLINK);
		LED_SetledState(0);
	}
	if(Button2_GetState()){
		RoadSignBoard_ChangeSpeedTime();
	}
}

void RoadSignBoard_Blink_State(void){
	static uint32_t prevTime = 0;

	if(HAL_GetTick() - prevTime > RoadSignBoard_GetSpeedTime()){
//	if(HAL_GetTick() - prevTime > 300){
		prevTime = HAL_GetTick();
		LED_AllBlink();
	}
	if(Button1_GetState()){
		RoadSignBoard_SetState(IDLE);
		LED_SetledState(0);
	}
	if(Button2_GetState()){
		RoadSignBoard_ChangeSpeedTime();
	}
}
