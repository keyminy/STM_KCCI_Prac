/*
 * Ultrasonic.h
 *
 *  Created on: May 3, 2025
 *      Author: me
 */

#ifndef DRIVER_ULTRASONIC_H_
#define DRIVER_ULTRASONIC_H_
#include "main.h"

#define CLEAR 0
#define READY 1

void UltraSonic_SetReadyFlag(uint8_t flag);
void UltraSonic_Trigger(void);
uint8_t UltraSonic_IsReady(void);
uint8_t UltraSonic_GetDistance(void);
void UltraSonic_ISR_Process(void);

#endif /* DRIVER_ULTRASONIC_H_ */
