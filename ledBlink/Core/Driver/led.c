/*
 * led.c
 *
 *  Created on: Jan 11, 2025
 *      Author: me
 */
#include "led.h"

void LED_On(void){
	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
}

void LED_Off(void){
	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
}
