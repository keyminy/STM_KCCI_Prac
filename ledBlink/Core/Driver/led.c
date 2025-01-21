/*
 * led.c
 *
 *  Created on: Jan 11, 2025
 *      Author: me
 */
#include "led.h"

void LED_WriteData(uint8_t data){
	GPIO_TypeDef* LED_GPIO[8] = {
		GPIOB, 		GPIOB, 		GPIOB, 		GPIOB,
		GPIOC, 		GPIOC, 		GPIOC, 		GPIOC
	};
	uint16_t LED_GPIO_PIN[8] = {
		GPIO_PIN_12,		GPIO_PIN_13,		GPIO_PIN_14,		GPIO_PIN_15,
		GPIO_PIN_6,		GPIO_PIN_7,		GPIO_PIN_8,		GPIO_PIN_9
	};
	for(int i=0; i < 8; i++){
		HAL_GPIO_WritePin(LED_GPIO[i], LED_GPIO_PIN[i], data & (1<<i));
	}
}

void LED_On(void){
	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
}

void LED_Off(void){
	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
}
