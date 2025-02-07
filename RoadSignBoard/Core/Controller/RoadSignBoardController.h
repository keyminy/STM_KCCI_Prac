/*
 * RoadSignBoardController.h
 *
 *  Created on: 2025. 1. 27.
 *      Author: me
 */

#ifndef CONTROLLER_ROADSIGNBOARDCONTROLLER_H_
#define CONTROLLER_ROADSIGNBOARDCONTROLLER_H_

#include "main.h"
#include "RoadSignBoard_EventController.h"
#include "RoadSignBoard_SpeedTimeController.h"
#include "../Driver/led.h"
#include "../Driver/button.h"
#include "../Driver/FND.h"
#include "../Driver/buzzer.h"


enum {
	IDLE,
	LEFT_SIGN,
	RIGHT_SIGN,
	TWOWAY_SIGN,
	BLINK
};
void RoadSignBoard_Init(void);
void RoadSignBoardController(void);
void RoadSignBoard_Idle_State(void);
void RoadSignBoard_Left_State(void);
void RoadSignBoard_Right_State(void);
void RoadSignBoard_TwoWay_State(void);
void RoadSignBoard_Blink_State(void);


//fp
void RoadSignBoard_ExcuteHandler(void (*pfLED_DirectionSign)(void));

#endif /* CONTROLLER_ROADSIGNBOARDCONTROLLER_H_ */
