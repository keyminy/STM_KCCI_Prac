/*
 * RoadSignBoardController.c
 *
 *  Created on: 2025. 1. 26.
 *      Author: me
 */

#include "RoadSignBoardController.h"


void RoadSignBoard_Init(void){
	RoadSignBoard_SetState(IDLE);
	RoadSignBoard_SetSpeedTime(100);// 초기값 설정 : 100ms
	RoadSignBoard_SetSpeedState(0);
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
	RoadSignBoard_EventHandler(LEFT_SIGN);
}

void RoadSignBoard_Left_State(void){
	RoadSignBoard_ExcuteHandler(LED_LeftSign);
	RoadSignBoard_EventHandler(RIGHT_SIGN);
}


void RoadSignBoard_Right_State(void){
	RoadSignBoard_ExcuteHandler(LED_RightSign);
	RoadSignBoard_EventHandler(TWOWAY_SIGN);
}

void RoadSignBoard_TwoWay_State(void){
	RoadSignBoard_ExcuteHandler(LED_TwoWaySign);
	RoadSignBoard_EventHandler(BLINK);
}

void RoadSignBoard_Blink_State(void){
	RoadSignBoard_ExcuteHandler(LED_AllBlink);
	RoadSignBoard_EventHandler(IDLE);
}

void RoadSignBoard_ExcuteHandler(void (*pfLED_DirectionSign)(void)){
	static uint32_t prevTime = 0;

	if(HAL_GetTick() - prevTime > RoadSignBoard_GetSpeedTime()){
		prevTime = HAL_GetTick();
		pfLED_DirectionSign(); //LED_LeftSign(); // Excute Function
	}
}
