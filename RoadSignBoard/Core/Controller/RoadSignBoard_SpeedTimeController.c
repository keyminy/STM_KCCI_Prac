/*
 * RoadSignBoard_SpeedTimeController.c
 *
 *  Created on: Jan 27, 2025
 *      Author: me
 */
#include "RoadSignBoard_SpeedTimeController.h"
uint16_t roadSignBoardSpeedTime;

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
