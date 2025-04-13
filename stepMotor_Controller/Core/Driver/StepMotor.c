#include "StepMotor.h"

void StepMotor_Stop(void){
	// 타이머 인터럽트 스탑
	HAL_TIM_Base_Stop_IT(&htim2);
}
void StepMotor_Run(void){
	// 타이머 인터럽트 시작
	HAL_TIM_Base_Start_IT(&htim2);
}

void StepMotor_Speed(uint8_t speed){
	// 타이머 인터럽트 발생되는 주기 변경하여, 스텝모터 스피드 설정하는 함수
	switch (speed) {
		case SPEED_1:
			__HAL_TIM_SET_AUTORELOAD(&htim2,MOTOR_SPEED_1);
			break;
		case SPEED_2:
			__HAL_TIM_SET_AUTORELOAD(&htim2,MOTOR_SPEED_2);
			break;
		case SPEED_3:
			__HAL_TIM_SET_AUTORELOAD(&htim2,MOTOR_SPEED_3);
			break;
	}
}


void StepMotor_Direction(uint8_t dir){
	switch (dir) {
		case CW:
			StepMotor_CW();
			break;
		case CCW:
			StepMotor_CCW();
			break;
	}
}

void StepMotor_CW(){
	static uint8_t stepMotor_phase = 0;
	//there are 4steps...
	stepMotor_phase = (stepMotor_phase+1) % 4;
	switch(stepMotor_phase){
		case 0:
		  HAL_GPIO_WritePin(STEP_A1_GPIO, STEP_A1_GPIO_PIN, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(STEP_B1_GPIO, STEP_B1_GPIO_PIN, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(STEP_A2_GPIO, STEP_A2_GPIO_PIN, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(STEP_B2_GPIO, STEP_B2_GPIO_PIN, GPIO_PIN_SET);
		  HAL_Delay(1);
		break;
		case 1:
		  HAL_GPIO_WritePin(STEP_A1_GPIO, STEP_A1_GPIO_PIN, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(STEP_B1_GPIO, STEP_B1_GPIO_PIN, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(STEP_A2_GPIO, STEP_A2_GPIO_PIN, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(STEP_B2_GPIO, STEP_B2_GPIO_PIN, GPIO_PIN_SET);
		  HAL_Delay(1);
		break;
		case 2:
		  HAL_GPIO_WritePin(STEP_A1_GPIO, STEP_A1_GPIO_PIN, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(STEP_B1_GPIO, STEP_B1_GPIO_PIN, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(STEP_A2_GPIO, STEP_A2_GPIO_PIN, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(STEP_B2_GPIO, STEP_B2_GPIO_PIN, GPIO_PIN_RESET);
		  HAL_Delay(1);
		break;
		case 3:
		  HAL_GPIO_WritePin(STEP_A1_GPIO, STEP_A1_GPIO_PIN, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(STEP_B1_GPIO, STEP_B1_GPIO_PIN, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(STEP_A2_GPIO, STEP_A2_GPIO_PIN, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(STEP_B2_GPIO, STEP_B2_GPIO_PIN, GPIO_PIN_RESET);
		  HAL_Delay(1);
		break;
	}
}

void StepMotor_CCW(){
	static uint8_t stepMotor_phase = 0;
	//there are 4steps...
	stepMotor_phase = (stepMotor_phase+1) % 4;
	switch(stepMotor_phase){
	case 0:
	  HAL_GPIO_WritePin(STEP_A1_GPIO, STEP_A1_GPIO_PIN, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(STEP_B1_GPIO, STEP_B1_GPIO_PIN, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(STEP_A2_GPIO, STEP_A2_GPIO_PIN, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(STEP_B2_GPIO, STEP_B2_GPIO_PIN, GPIO_PIN_RESET);
	  HAL_Delay(1);
		break;
	case 1:
	  HAL_GPIO_WritePin(STEP_A1_GPIO, STEP_A1_GPIO_PIN, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(STEP_B1_GPIO, STEP_B1_GPIO_PIN, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(STEP_A2_GPIO, STEP_A2_GPIO_PIN, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(STEP_B2_GPIO, STEP_B2_GPIO_PIN, GPIO_PIN_RESET);
	  HAL_Delay(1);
		break;
	case 2:
	  HAL_GPIO_WritePin(STEP_A1_GPIO, STEP_A1_GPIO_PIN, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(STEP_B1_GPIO, STEP_B1_GPIO_PIN, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(STEP_A2_GPIO, STEP_A2_GPIO_PIN, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(STEP_B2_GPIO, STEP_B2_GPIO_PIN, GPIO_PIN_SET);
	  HAL_Delay(1);
		break;
	case 3:
	  HAL_GPIO_WritePin(STEP_A1_GPIO, STEP_A1_GPIO_PIN, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(STEP_B1_GPIO, STEP_B1_GPIO_PIN, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(STEP_A2_GPIO, STEP_A2_GPIO_PIN, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(STEP_B2_GPIO, STEP_B2_GPIO_PIN, GPIO_PIN_SET);
	  HAL_Delay(1);
		break;
	}
}
