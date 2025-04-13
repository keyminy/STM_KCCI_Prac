/*
 * button.h
 *
 *  Created on: Apr 13, 2025
 *      Author: me
 */

#ifndef DRIVER_BUTTON_H_
#define DRIVER_BUTTON_H_
#include "main.h"

#define TRUE 1
#define FALSE 0
#define PUSHED		0
#define RELEASED	1


typedef struct{
	GPIO_TypeDef* GPIOx;
	uint16_t GPIO_Pin;
	uint8_t prevState;
} BUTTON_HandleTypeDef;

extern BUTTON_HandleTypeDef hButton_RunStop;
extern BUTTON_HandleTypeDef hButton_Dir;
extern BUTTON_HandleTypeDef hButton_Speed;

uint8_t Button_GetState(BUTTON_HandleTypeDef* hButton);

#endif /* DRIVER_BUTTON_H_ */
