/*
 * buzzer.c
 *
 *  Created on: Feb 6, 2025
 *      Author: me
 */

void BUZZER_ModeButtonSound(void){
	BUZZER_StartFreq(); 		// make sound
	BUZZER_GenFreq(freqValue);	// make freq
	HAL_Delay(100);				// delay
	BUZZER_GenFreq(freqValue);
	HAL_Delay(100);
	BUZZER_GenFreq(freqValue);
	HAL_Delay(100);
	Buzzer_StopFreq();	// no sound
}

void BUZZER_SpeedButtonSound(void){
	BUZZER_StartFreq(); 		// make sound
	BUZZER_GenFreq(freqValue);	// make freq
	HAL_Delay(100);				// delay
	BUZZER_GenFreq(freqValue);
	HAL_Delay(100);
	BUZZER_GenFreq(freqValue);
	HAL_Delay(100);
	Buzzer_StopFreq();	// no sound
}

void BUZZER_StartFreq(void){
	// PWM Start
}

void Buzzer_StopFreq(void){
	// PWM Stop
}

void BUZZER_GenFreq(uint16_t freq){

}
