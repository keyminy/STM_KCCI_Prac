/*
 * StepMotor_Controller.h
 *
 *  Created on: Apr 13, 2025
 *      Author: me
 */

#ifndef CONTROLLER_STEPMOTOR_CONTROLLER_H_
#define CONTROLLER_STEPMOTOR_CONTROLLER_H_
#include "main.h"

#define STEP_A1_GPIO GPIOC
#define STEP_A1_GPIO_PIN GPIO_PIN_0
#define STEP_B1_GPIO GPIOC
#define STEP_B1_GPIO_PIN GPIO_PIN_1
#define STEP_A2_GPIO GPIOC
#define STEP_A2_GPIO_PIN GPIO_PIN_2
#define STEP_B2_GPIO GPIOC
#define STEP_B2_GPIO_PIN GPIO_PIN_3


void StepMotor_Controller(void);
void StepMotor_Control_Run(void);
void StepMotor_Control_Stop(void);
void StepMotor_Control_Speed();
void StepMotor_Control_Direction();

#endif /* CONTROLLER_STEPMOTOR_CONTROLLER_H_ */
