/*
 * button.c
 *
 *  Created on: 2025. 1. 27.
 *      Author: me
 */
#include "button.h"

uint8_t Button_GetState(){
	// 전 상태를 알고 있어야함, 함수 호출이 끝나도 값을 유지해야하므로 static
	static uint8_t prevState = RELEASED; // 전상태 : 눌리지 않음
	uint8_t curState;
	curState = HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin);

	if(curState == PUSHED && prevState != PUSHED){
		HAL_Delay(10);
		prevState = PUSHED;
		return 0;
	}else if(curState != PUSHED && prevState == PUSHED){
		HAL_Delay(10);
		prevState = RELEASED;
		return 1;
	}
	return 0;
}
uint8_t Button1_GetState(){
	// 전 상태를 알고 있어야함, 함수 호출이 끝나도 값을 유지해야하므로 static
	static uint8_t prevState = RELEASED; // 전상태 : 눌리지 않음
	uint8_t curState;
	curState = HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin);

	if(curState == PUSHED && prevState != PUSHED){
		HAL_Delay(10);
		prevState = PUSHED;
		return 0;
	}else if(curState != PUSHED && prevState == PUSHED){
		HAL_Delay(10);
		prevState = RELEASED;
		return 1;
	}
	return 0;
}
uint8_t Button2_GetState(){
	// 전 상태를 알고 있어야함, 함수 호출이 끝나도 값을 유지해야하므로 static
	static uint8_t prevState = RELEASED; // 전상태 : 눌리지 않음
	uint8_t curState;
	curState = HAL_GPIO_ReadPin(BUTTON2_GPIO, BUTTON2_GPIO_PIN);

	if(curState == PUSHED && prevState != PUSHED){
		HAL_Delay(10);
		prevState = PUSHED;
		return 0;
	}else if(curState != PUSHED && prevState == PUSHED){
		HAL_Delay(10);
		prevState = RELEASED;
		return 1;
	}
	return 0;
}

