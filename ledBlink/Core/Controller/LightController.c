/*
 * LightController.c
 *
 *  Created on: Jan 11, 2025
 *      Author: me
 */
#include "LightController.h"

uint8_t lightState;

void setLightState(uint8_t state){
	lightState = state;
}
uint8_t getLightState(void){
	return lightState;
}

// 처음 Start는 전등 OFF상태로
void LightControllerInit(void){
	setLightState(LIGHT_OFF); // 초기화
}

void LightController(void){
	switch (getLightState()) {
		case LIGHT_ON:
			LightOnState();
			break;
		case LIGHT_OFF:
			LightOffState();

			break;
	}
}

void LightOnState(void){
	LED_On();
	if(Button_GetState()){
		setLightState(LIGHT_OFF);
	}
}

void LightOffState(void){
	LED_Off();
	if(Button_GetState()){
		setLightState(LIGHT_ON);
	}
}
