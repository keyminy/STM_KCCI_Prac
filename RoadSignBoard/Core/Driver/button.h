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

typedef struct{
	GPIO_TypeDef* GPIOx;
	uint16_t GPIO_Pin;
	uint8_t prevState;
} BUTTON_HandleTypeDef;
// 버튼 핸들러 타입이다
// prefix h : button handler
extern BUTTON_HandleTypeDef hButton_Mode;
extern BUTTON_HandleTypeDef hButton_SpeedTime;

uint8_t Button_GetState(BUTTON_HandleTypeDef* hButton);
uint8_t Button1_GetState();
uint8_t Button2_GetState();

#endif /* DRIVER_BUTTON_H_ */
