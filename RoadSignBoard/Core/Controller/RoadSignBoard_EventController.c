/*
 * RoadSignBoard_EventController.c
 *
 *  Created on: Jan 27, 2025
 *      Author: me
 */
#include "RoadSignBoard_EventController.h"

void RoadSignBoardEventHandler(uint8_t state){
	if(Button1_GetState()){
		RoadSignBoard_SetState(state);
		LED_SetledState(0);
	}
	if(Button2_GetState()){
		RoadSignBoard_ChangeSpeedTime();
	}
}
