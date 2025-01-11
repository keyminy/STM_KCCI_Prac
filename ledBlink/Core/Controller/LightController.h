/*
 * LightController.h
 *
 *  Created on: Jan 11, 2025
 *      Author: me
 */

#ifndef CONTROLLER_LIGHTCONTROLLER_H_
#define CONTROLLER_LIGHTCONTROLLER_H_

#include "main.h"
#include "../Driver/led.h"
#include "../Driver/button.h"

enum {LIGHT_ON,LIGHT_OFF};
void setLightState(uint8_t state);
uint8_t getLightState(void);
void LightControllerInit(void);
void LightController(void);
void LightOnState(void);
void LightOffState(void);

#endif /* CONTROLLER_LIGHTCONTROLLER_H_ */
