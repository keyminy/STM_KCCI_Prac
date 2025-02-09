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
enum {LIGHT_LEFT,LIGHT_RIGHT};

void setLightState(uint8_t state);
uint8_t getLightState(void);
void LightControllerInit(void);
void LightController(void);
void LightOnState(void);
void LightOffState(void);
void LED_WriteData(uint8_t data);
void ShiftController(void);
void LeftShiftState(void);
void RightShiftState(void);

#endif /* CONTROLLER_LIGHTCONTROLLER_H_ */
