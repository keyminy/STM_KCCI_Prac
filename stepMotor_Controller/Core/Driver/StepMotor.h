#ifndef DRIVER_STEPMOTOR_H_
#define DRIVER_STEPMOTOR_H_
#include "main.h"

// 1ms가 100임(왜냐하면 100k를 100번셈)
#define MOTOR_SPEED_1 800 // 8ms
#define MOTOR_SPEED_2 400 // 4ms
#define MOTOR_SPEED_3 200 // 2ms

enum {
	SPEED1,
	SPEED2,
	SPEED3
};

enum {
	MOTOR_CW,
	MOTOR_CCW
};

#define STEP_A1_GPIO GPIOC
#define STEP_A1_GPIO_PIN GPIO_PIN_0
#define STEP_B1_GPIO GPIOC
#define STEP_B1_GPIO_PIN GPIO_PIN_1
#define STEP_A2_GPIO GPIOC
#define STEP_A2_GPIO_PIN GPIO_PIN_2
#define STEP_B2_GPIO GPIOC
#define STEP_B2_GPIO_PIN GPIO_PIN_3

void StepMotor_Stop(void);
void StepMotor_Run(void);
void StepMotor_Speed(uint8_t speed);
void StepMotor_Direction(uint8_t dir);
void StepMotor_CW();
void StepMotor_CCW();

#endif /* DRIVER_STEPMOTOR_H_ */
