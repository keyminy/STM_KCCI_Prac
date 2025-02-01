/*
 * RoadSignBoard_SpeedTimeController.h
 *
 *  Created on: Jan 27, 2025
 *      Author: me
 */

#ifndef CONTROLLER_ROADSIGNBOARD_SPEEDTIMECONTROLLER_H_
#define CONTROLLER_ROADSIGNBOARD_SPEEDTIMECONTROLLER_H_
#include "main.h"

// speed
uint8_t RoadSignBoard_GetSpeedTime(void);
void RoadSignBoard_ChangeSpeedTime(void);
void RoadSignBoard_SetSpeedState(uint8_t state);

#endif /* CONTROLLER_ROADSIGNBOARD_SPEEDTIMECONTROLLER_H_ */
