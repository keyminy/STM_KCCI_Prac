/*
 * led.c
 *
 *  Created on: 2025. 1. 27.
 *      Author: me
 */
#include "led.h"

GPIO_TypeDef* LED_GPIO[8] = {
		GPIOB, 		GPIOB, 		GPIOB, 		GPIOB,
		GPIOC, 		GPIOC, 		GPIOC, 		GPIOC
};
uint16_t LED_GPIO_PIN[8] = {
		GPIO_PIN_12,		GPIO_PIN_13,		GPIO_PIN_14,		GPIO_PIN_15,
		GPIO_PIN_6,		GPIO_PIN_7,		GPIO_PIN_8,		GPIO_PIN_9
};

uint8_t ledState;

void LED_SetledState(uint8_t state){
	ledState = state;
}
uint8_t LED_GetledState(void){
	return ledState;
}

void LED_WriteData(uint8_t data){
	for(int i=0; i < 8; i++){
		HAL_GPIO_WritePin(LED_GPIO[i], LED_GPIO_PIN[i], data & (1<<i));
	}
}

void LED_AllOff(void){
	LED_WriteData(0x00);
}

void LED_LeftSign(void){
	uint8_t ledPattern[] = {0x00, 0x01,0x03,0x07,0x0f,0x0f,0x1f,0x3f
			,0x7f,0xff, 0x00, 0xff, 0x00, 0xff};
	uint8_t pattern = LED_GetledState();
	LED_WriteData(ledPattern[pattern]);
	pattern = (pattern+1) % (sizeof(ledPattern)/sizeof(uint8_t));
	LED_SetledState(pattern);
}

void LED_RightSign(void){
	uint8_t ledPattern[] = {0x00, 0x80,0xc0,0xe0,0xf0,0xf8,0xfc,0xfe
			,0xff,0x00, 0xff, 0x00, 0xff};
	uint8_t pattern = LED_GetledState();
	LED_WriteData(ledPattern[pattern]);
	pattern = (pattern+1) % (sizeof(ledPattern)/sizeof(uint8_t));
	LED_SetledState(pattern);
}
void LED_TwoWaySign(void){
	uint8_t ledPattern[] = {0x00, 0x18,0x3c,0x7e,0xff,0x00,0xff,0x00,0xff};
	uint8_t pattern = LED_GetledState();
	LED_WriteData(ledPattern[pattern]);
	pattern = (pattern+1) % (sizeof(ledPattern)/sizeof(uint8_t));
	LED_SetledState(pattern);
}
void LED_AllBlink(void){
	if(ledState == 0){
		ledState = 0xff;
	}else{
		ledState = 0;
	}
	LED_WriteData(ledState);
}
