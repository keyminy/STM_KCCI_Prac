/*
 * RoadSignBoard_SpeedTimeController.c
 *
 *  Created on: Jan 27, 2025
 *      Author: me
 */
#include "RoadSignBoard_SpeedTimeController.h"

uint16_t roadSignBoardSpeedTime;
uint8_t speedState; // global variable for fnd display

void RoadSignBoard_SetSpeedState(uint8_t state){
	speedState = state;
}
uint8_t RoadSignBoard_GetSpeedState(void){
	return speedState;
}

void RoadSignBoard_SetSpeedTime(uint8_t state){
	roadSignBoardSpeedTime = state;
}

uint8_t RoadSignBoard_GetSpeedTime(void){
	return roadSignBoardSpeedTime;
}


void RoadSignBoard_ChangeSpeedTime(void){
	// 0.1s, 0.2s, 0.3s, 0.4s, 0.5s
//	RoadSignBoard_SetSpeedTime(RoadSignBoard_GetSpeedTime()+10);

	// use array
	uint16_t speedTime[] = {100,200,300,400,500};
	uint8_t state = RoadSignBoard_GetSpeedState();

	state = (state + 1) % (sizeof(speedTime)/sizeof(uint16_t));
	RoadSignBoard_SetSpeedState(state); // set speedState

	roadSignBoardSpeedTime = speedTime[state];
}
