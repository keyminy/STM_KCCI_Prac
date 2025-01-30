/*
 * RoadSignBoard_EventController.c
 *
 *  Created on: Jan 27, 2025
 *      Author: me
 */
#include "RoadSignBoard_EventController.h"

uint8_t roadSignBoardState;

void RoadSignBoard_EventHandler(uint8_t state){
	if(Button_GetState(&hButton_Mode)){
		RoadSignBoard_SetState(state);
		LED_SetledState(0);
	}
	if(Button_GetState(&hButton_SpeedTime)){
		RoadSignBoard_ChangeSpeedTime();
	}
}

void RoadSignBoard_SetState(uint8_t state){
	roadSignBoardState = state;
}

uint8_t RoadSignBoard_GetState(void){
	return roadSignBoardState;
}
