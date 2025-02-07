/*
 * buzzer.c
 *
 *  Created on: Feb 6, 2025
 *      Author: me
 */
#include "buzzer.h"


TIM_HandleTypeDef *hBuzzTim;
uint32_t buzzChannel;

void BUZZER_Init(TIM_HandleTypeDef* htim,uint32_t channel){
	hBuzzTim = htim;
	buzzChannel = channel;
}

void BUZZER_ModeButtonSound(void){
	BUZZER_StartFreq(); 		// make sound
	BUZZER_GenFreq(1000);	// make freq (1kHz)
	HAL_Delay(100);				// delay
	BUZZER_GenFreq(2000);	// 2kHz
	HAL_Delay(100);
	BUZZER_GenFreq(3000);	// 3kHz
	HAL_Delay(100);
	Buzzer_StopFreq();	// no sound
}

void BUZZER_SpeedButtonSound(void){
	BUZZER_StartFreq(); 		// make sound
	BUZZER_GenFreq(3000);	// make freq
	HAL_Delay(100);				// delay
	BUZZER_GenFreq(4000);
	HAL_Delay(100);
	BUZZER_GenFreq(5000);
	HAL_Delay(100);
	Buzzer_StopFreq();	// no sound
}

void BUZZER_StartFreq(void){
	// PWM Start
	HAL_TIM_PWM_Start(hBuzzTim, buzzChannel);
}

void Buzzer_StopFreq(void){
	// PWM Stop
	HAL_TIM_PWM_Stop(hBuzzTim, buzzChannel);
}

void BUZZER_GenFreq(uint16_t freq){
	uint16_t arr = (100000/freq) -1; //ARR = (100000(100kHz)/freq)-1
	uint16_t ccr = arr/2; // CCR = ARR/2; -> duty 50%
	__HAL_TIM_SET_AUTORELOAD(hBuzzTim,arr); // ARR 레지스터에 적용이 됩니다.
	__HAL_TIM_SET_COMPARE(hBuzzTim, buzzChannel,ccr);
}
