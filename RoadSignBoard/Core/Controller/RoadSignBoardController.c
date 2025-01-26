/*
 * RoadSignBoardController.c
 *
 *  Created on: 2025. 1. 26.
 *      Author: me
 */

#include "RoadSignBoardController.h"

uint8_t roadSignBoardState;

void RoadSignBoard_Init(void){
	RoadSignBoard_SetState(IDLE);
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

	if(Button_GetState()){
		RoadSignBoard_SetState(LEFT_SIGN);
	}
}

void RoadSignBoard_Left_State(void){
	static uint32_t prevTime = 0;

	if(HAL_GetTick() - prevTime > 200){
		prevTime = HAL_GetTick();
		LED_LeftSign();
	}
	if(Button_GetState()){
		RoadSignBoard_SetState(RIGHT_SIGN);
	}
}


void RoadSignBoard_Right_State(void){
	static uint32_t prevTime = 0;
	if(HAL_GetTick() - prevTime > 200){
		prevTime = HAL_GetTick();
		LED_RightSign();
	}
	if(Button_GetState()){
		RoadSignBoard_SetState(TWOWAY_SIGN);
	}
}

void RoadSignBoard_TwoWay_State(void){
	static uint32_t prevTime = 0;
	if(HAL_GetTick() - prevTime > 200){
		prevTime = HAL_GetTick();
		LED_TwoWaySign();
	}
	if(Button_GetState()){
		RoadSignBoard_SetState(BLINK);
	}
}

void RoadSignBoard_Blink_State(void){
	static uint32_t prevTime = 0;

	if(HAL_GetTick() - prevTime > 300){
		prevTime = HAL_GetTick();
		LED_AllBlink();
	}
	if(Button_GetState()){
		RoadSignBoard_SetState(IDLE);
	}
}
