/*
 * LightController.c
 *
 *  Created on: Jan 11, 2025
 *      Author: me
 */
#include "LightController.h"

uint8_t lightState;
uint8_t ledData = 1;

void setLightState(uint8_t state){
	lightState = state;
}
uint8_t getLightState(void){
	return lightState;
}

// 처음 Start는 전등 OFF상태로
void LightControllerInit(void){
	setLightState(LIGHT_LEFT); // 초기화
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

void ShiftController(void){
	switch (lightState) {
		case LIGHT_LEFT:
			LeftShiftState();
			break;
		case LIGHT_RIGHT:
			RightShiftState();
			break;
	}
}
void LeftShiftState(void){
	ledData = ledData >> 7 | ledData << 1;
	LED_WriteData(ledData);
	HAL_Delay(100);

	if(Button_GetState()){
		setLightState(LIGHT_RIGHT);
	}

	//(M2)
//	for(int i=0; i < 8; i++){
//		LED_WriteData(1<<i);
//		if(Button_GetState()){
//			setLightState(LIGHT_RIGHT);
//		}
//		HAL_Delay(100);
//	}
//	LED_WriteData(0x00);
}
void RightShiftState(void){
	ledData = ledData >> 1 | ledData << 7;
	LED_WriteData(ledData);
	HAL_Delay(100);

	if(Button_GetState()){
		setLightState(LIGHT_LEFT);
	}

	// (M2)
//	for(int i=7; i >= 0; i--){
//		LED_WriteData(1<<i);
//		if(Button_GetState()){
//			setLightState(LIGHT_LEFT);
//		}
//		HAL_Delay(100);
//	}
//	LED_WriteData(0x00);
}

void LightOnState(void){
//	LED_On();
	LED_WriteData(0xff);
	if(Button_GetState()){
		setLightState(LIGHT_OFF);
	}
}

void LightOffState(void){
//	LED_Off();
	LED_WriteData(0x00);
	if(Button_GetState()){
		setLightState(LIGHT_ON);
	}
}
