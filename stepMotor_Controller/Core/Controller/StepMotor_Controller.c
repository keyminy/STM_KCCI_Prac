#include "StepMotor_Controller.h"

#define STEP_A1_GPIO GPIOC
#define STEP_A1_GPIO_PIN GPIO_PIN_0
#define STEP_B1_GPIO GPIOC
#define STEP_B1_GPIO_PIN GPIO_PIN_1
#define STEP_A2_GPIO GPIOC
#define STEP_A2_GPIO_PIN GPIO_PIN_2
#define STEP_B2_GPIO GPIOC
#define STEP_B2_GPIO_PIN GPIO_PIN_3

void STEPMOTOR_Run(void){
	// 타이머 인터럽트 시작
	HAL_TIM_Base_Start_IT(&htim2);
	StepMotor_SpeedControl();
	StepMotor_DirectionControl();
	//hButton_RunStop : BTN1
	if(Button_GetState(&hButton_RunStop)){

	}
}

void STEPMOTOR_Stop(void){
	// 타이머 인터럽트 스탑
	HAL_TIM_Base_Stop_IT(&htim2);
	// hButton_RunStop : BTN1
	if(Button_GetState(&hButton_RunStop)){

	}
}

void StepMotor_SpeedControl(){
	switch(stepMotorSpeedState){
	case SPEED_1:
		StepMotor_Speed(SPEED_1);
		// hButton_Speed : BTN3
		if(Button_GetState(hButton_Speed)){

		}
		break;
	case SPEED_2:
		StepMotor_Speed(SPEED_2);
		// hButton_Speed : BTN3
		if(Button_GetState(hButton_Speed)){

		}
		break;
	case SPEED_3:
		StepMotor_Speed(SPEED_3);
		// hButton_Speed : BTN3
		if(Button_GetState(hButton_Speed)){

		}
		break;
	}
}

void StepMotor_Speed(uint8_t speed){
	// 타이머 인터럽트 발생되는 주기 변경하여, 스텝모터 스피드 설정하는 함수
	switch (speed) {
		case SPEED_1:
			break;
		case SPEED_2:
			break;
		case SPEED_3:
			break;
	}

}

void StepMotor_DirectionControl(){
	switch (stepMotorDirState) {
		case CW:
			StepMotor_Direction(CW);
			// hButton_Dir : BTN2
			if(Button_GetState(hButton_Dir)){

			}
			break;
		case CCW:
			StepMotor_Direction(CCW);
			// hButton_Dir : BTN2
			if(Button_GetState(hButton_Dir)){

			}
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
