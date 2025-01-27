/*
 * button.h
 *
 *  Created on: 2025. 1. 27.
 *      Author: me
 */

#ifndef DRIVER_BUTTON_H_
#define DRIVER_BUTTON_H_
#include "main.h"

#define BUTTON2_GPIO GPIOC
#define BUTTON2_GPIO_PIN GPIO_PIN_0

#define PUSHED		0
#define RELEASED	1

uint8_t Button_GetState();
uint8_t Button1_GetState();
uint8_t Button2_GetState();

#endif /* DRIVER_BUTTON_H_ */
