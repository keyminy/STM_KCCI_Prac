/*
 * led.h
 *
 *  Created on: 2025. 3. 3.
 *      Author: me
 */

#ifndef DRIVER_LED_H_
#define DRIVER_LED_H_
#include "main.h"

typedef struct{
	GPIO_TypeDef* GPIO;
	uint16_t GPIO_Pin;
} LED_HandleTypeDef;

extern LED_HandleTypeDef hLedRed;
extern LED_HandleTypeDef hLedGreen;

void LED_Toggle(LED_HandleTypeDef *hLed);

#endif /* DRIVER_LED_H_ */
