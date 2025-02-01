/*
 * RoadSignBoard_EventController.h
 *
 *  Created on: Jan 27, 2025
 *      Author: me
 */

#ifndef CONTROLLER_ROADSIGNBOARD_EVENTCONTROLLER_H_
#define CONTROLLER_ROADSIGNBOARD_EVENTCONTROLLER_H_

#include "main.h"
#include "RoadSignBoard_SpeedTimeController.h"
#include "../Driver/button.h"
#include "../Driver/led.h"
#include "../Driver/FND.h"

void RoadSignBoard_EventHandler(uint8_t state);
void RoadSignBoard_SetState(uint8_t state);
uint8_t RoadSignBoard_GetState(void);


#endif /* CONTROLLER_ROADSIGNBOARD_EVENTCONTROLLER_H_ */
