/*
 * buzzer.h
 *
 *  Created on: Feb 6, 2025
 *      Author: me
 */

#ifndef DRIVER_BUZZER_H_
#define DRIVER_BUZZER_H_
#include "main.h"

void BUZZER_ModeButtonSound(void);
void BUZZER_SpeedButtonSound(void);
void BUZZER_Init(TIM_HandleTypeDef* htim,uint32_t channel);
void BUZZER_StartFreq(void);
void Buzzer_StopFreq(void);
void BUZZER_GenFreq(uint16_t freq);

#endif /* DRIVER_BUZZER_H_ */
