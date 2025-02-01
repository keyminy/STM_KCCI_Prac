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
		FND_ShowMode(state);
		LED_SetledState(0);
	}
	if(Button_GetState(&hButton_SpeedTime)){
		RoadSignBoard_ChangeSpeedTime();
//		FND_ShowSpeed(???);
		FND_ShowSpeed(RoadSignBoard_GetSpeedState());
		//RoadSignBoard_GetSpeedState() : 0,1,2,3,4,5...
	}
}

void RoadSignBoard_SetState(uint8_t state){
	roadSignBoardState = state;
}

uint8_t RoadSignBoard_GetState(void){
	return roadSignBoardState;
}
