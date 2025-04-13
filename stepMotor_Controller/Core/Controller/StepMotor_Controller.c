#include "StepMotor_Controller.h"

uint8_t stepMotorRunStopState;
uint8_t stepMotorSpeedState;
uint8_t stepMotorDirState;

void StepMotor_Controller(void){
	switch (stepMotorRunStopState) {
		case STEPMOTOR_STOP:
			StepMotor_Control_Stop();
			break;
		case STEPMOTOR_RUN:
			StepMotor_Control_Run();
			break;
	}
}

void StepMotor_Control_Run(void){
	StepMotor_Run(); // Driver

	StepMotor_Control_Speed();
	StepMotor_Control_Direction();
	//hButton_RunStop : BTN1
	if(Button_GetState(&hButton_RunStop)){

	}
}



void StepMotor_Control_Stop(void){
	StepMotor_Stop(); // Driver

	// hButton_RunStop : BTN1
	if(Button_GetState(&hButton_RunStop)){

	}
}



void StepMotor_Control_Speed(){
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



void StepMotor_Control_Direction(){
	switch (stepMotorDirState) {
		case CW:
			StepMotor_Direction(CW); // Driver
			// hButton_Dir : BTN2
			if(Button_GetState(hButton_Dir)){

			}
			break;
		case CCW:
			StepMotor_Direction(CCW); // Driver
			// hButton_Dir : BTN2
			if(Button_GetState(hButton_Dir)){

			}
			break;
	}
}
