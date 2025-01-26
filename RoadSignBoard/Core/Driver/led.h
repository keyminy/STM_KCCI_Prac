/*
 * led.h
 *
 *  Created on: 2025. 1. 27.
 *      Author: me
 */

#ifndef DRIVER_LED_H_
#define DRIVER_LED_H_
#include "main.h"


void LED_WriteData(uint8_t data);
void LED_AllOff(void);
void LED_LeftSign(void);
void LED_RightSign(void);
void LED_TwoWaySign(void);
void LED_AllBlink(void);
void LED_SetledState(uint8_t state);
uint8_t LED_GetledState(void);

#endif /* DRIVER_LED_H_ */
