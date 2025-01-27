/*
 * RoadSignBoardController.h
 *
 *  Created on: 2025. 1. 27.
 *      Author: me
 */

#ifndef CONTROLLER_ROADSIGNBOARDCONTROLLER_H_
#define CONTROLLER_ROADSIGNBOARDCONTROLLER_H_

#include "main.h"
#include "../Driver/led.h"
#include "../Driver/button.h"


enum {
	IDLE,
	LEFT_SIGN,
	RIGHT_SIGN,
	TWOWAY_SIGN,
	BLINK
};
void RoadSignBoard_Init(void);
void RoadSignBoard_SetState(uint8_t state);
uint8_t RoadSignBoard_GetState(void);
void RoadSignBoardController(void);
void RoadSignBoard_Idle_State(void);
void RoadSignBoard_Left_State(void);
void RoadSignBoard_Right_State(void);
void RoadSignBoard_TwoWay_State(void);
void RoadSignBoard_Blink_State(void);

// speed
void RoadSignBoard_SetSpeedTime(uint16_t speedTime);
uint16_t RoadSignBoard_GetSpeedTime(void);
void RoadSignBoard_ChangeSpeedTime(void);


#endif /* CONTROLLER_ROADSIGNBOARDCONTROLLER_H_ */
