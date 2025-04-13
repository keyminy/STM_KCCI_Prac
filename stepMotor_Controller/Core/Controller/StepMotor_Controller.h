/*
 * StepMotor_Controller.h
 *
 *  Created on: Apr 13, 2025
 *      Author: me
 */

#ifndef CONTROLLER_STEPMOTOR_CONTROLLER_H_
#define CONTROLLER_STEPMOTOR_CONTROLLER_H_
#include "main.h"
#include "../Driver/Button.h"
#include "../Driver/StepMotor.h"

typedef enum {
	STEPMOTOR_STOP,
	STEPMOTOR_RUN
} eRunStop;

enum {
	SPEED_1,
	SPEED_2,
	SPEED_3
};

enum {
	CW,
	CCW
};


void StepMotor_Control_ISR_Process(void);
void StepMotor_Controller_Init(void);
void StepMotor_Controller(void);
void StepMotor_Control_Run(void);
void StepMotor_Control_Stop(void);
void StepMotor_Control_Speed();
void StepMotor_Control_Direction();

#endif /* CONTROLLER_STEPMOTOR_CONTROLLER_H_ */
