#include "stepMotor.h"

#define STEP_A1_GPIO GPIOC
#define STEP_B1_GPIO GPIOC
#define STEP_A2_GPIO GPIOC
#define STEP_B2_GPIO GPIOC

void STEPMOTOR_Run(void){
	// 타이머 인터럽트 시작
}

void STEPMOTOR_Stop(void){
	// 타이머 인터럽트 스탑
}

void STEPMOTOR_Speed(uint16_t value){
	// 타이머 인터럽트 발생되는 주기 변경하여, 스텝모터 스피드 설정하는 함수
}


void STEPMOTOR_CW(){
	static uint8_t stepMotor_phase = 0;
	//there are 4steps...
	stepMotor_phase = (stepMotor_phase+1) % 4;
	switch(stepMotor_phase){
		case 0:
		  HAL_GPIO_WritePin(STEP_A1_GPIO, STEP_IN1_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(STEP_B1_GPIO, STEP_IN2_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(STEP_A2_GPIO, STEP_IN3_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(STEP_B2_GPIO, STEP_IN4_Pin, GPIO_PIN_SET);
		  HAL_Delay(1);
		break;
		case 1:
		  HAL_GPIO_WritePin(STEP_A1_GPIO, STEP_IN1_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(STEP_B1_GPIO, STEP_IN2_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(STEP_A2_GPIO, STEP_IN3_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(STEP_B2_GPIO, STEP_IN4_Pin, GPIO_PIN_SET);
		  HAL_Delay(1);
		break;
		case 2:
		  HAL_GPIO_WritePin(STEP_A1_GPIO, STEP_IN1_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(STEP_B1_GPIO, STEP_IN2_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(STEP_A2_GPIO, STEP_IN3_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(STEP_B2_GPIO, STEP_IN4_Pin, GPIO_PIN_RESET);
		  HAL_Delay(1);
		break;
		case 3:
		  HAL_GPIO_WritePin(STEP_A1_GPIO, STEP_IN1_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(STEP_B1_GPIO, STEP_IN2_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(STEP_A2_GPIO, STEP_IN3_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(STEP_B2_GPIO, STEP_IN4_Pin, GPIO_PIN_RESET);
		  HAL_Delay(1);
		break;
	}
}

void STEPMOTOR_CCW(){
	static uint8_t stepMotor_phase = 0;
	//there are 4steps...
	stepMotor_phase = (stepMotor_phase+1) % 4;
	switch(stepMotor_phase){
	case 0:
	  HAL_GPIO_WritePin(STEP_A1_GPIO, STEP_IN1_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(STEP_B1_GPIO, STEP_IN2_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(STEP_A2_GPIO, STEP_IN3_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(STEP_B2_GPIO, STEP_IN4_Pin, GPIO_PIN_RESET);
	  HAL_Delay(1);
		break;
	case 1:
	  HAL_GPIO_WritePin(STEP_A1_GPIO, STEP_IN1_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(STEP_B1_GPIO, STEP_IN2_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(STEP_A2_GPIO, STEP_IN3_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(STEP_B2_GPIO, STEP_IN4_Pin, GPIO_PIN_RESET);
	  HAL_Delay(1);
		break;
	case 2:
	  HAL_GPIO_WritePin(STEP_A1_GPIO, STEP_IN1_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(STEP_B1_GPIO, STEP_IN2_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(STEP_A2_GPIO, STEP_IN3_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(STEP_B2_GPIO, STEP_IN4_Pin, GPIO_PIN_SET);
	  HAL_Delay(1);
		break;
	case 3:
	  HAL_GPIO_WritePin(STEP_A1_GPIO, STEP_IN1_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(STEP_B1_GPIO, STEP_IN2_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(STEP_A2_GPIO, STEP_IN3_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(STEP_B2_GPIO, STEP_IN4_Pin, GPIO_PIN_SET);
	  HAL_Delay(1);
		break;
	}
}
