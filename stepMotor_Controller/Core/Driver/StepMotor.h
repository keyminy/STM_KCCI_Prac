/*
 * StepMotor.h
 *
 *  Created on: Apr 13, 2025
 *      Author: me
 */

#ifndef DRIVER_STEPMOTOR_H_
#define DRIVER_STEPMOTOR_H_
#include "main.h"

void StepMotor_Stop(void);
void StepMotor_Run(void);
void StepMotor_Speed(uint8_t speed);
void StepMotor_Direction(uint8_t dir);
void StepMotor_CW();
void StepMotor_CCW();

#endif /* DRIVER_STEPMOTOR_H_ */
