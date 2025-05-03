#include "StepMotor_Controller.h"
#include <string.h>
#include <stdio.h>

eRunStop stepMotorRunStopState;
uint8_t stepMotorSpeedState;
uint8_t stepMotorDirState;

void StepMotor_Control_ISR_Process(void){
	switch(stepMotorDirState){
	case CW:
		StepMotor_CW();
		break;
	case CCW:
		StepMotor_CCW();
		break;
	}
}


void StepMotor_Controller_Init(void){
	stepMotorRunStopState = STEPMOTOR_STOP;
	stepMotorSpeedState = SPEED_1;
	stepMotorDirState = CW;

	char buff[30];
	sprintf(buff, "STEP MOTOR STOP");
    move_cursor(0,0);
    lcd_string(buff);
    move_cursor(1,0);
	sprintf(buff, "SPEED 1");
    lcd_string(buff);
    move_cursor(1,10);
	sprintf(buff, "CW");
    lcd_string(buff);
}

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

	if(!QisEmpty(&hQue_ButtonRunStop)){
		DeQueue(&hQue_ButtonRunStop);
//	if(Button_GetState(&hButton_RunStop)){
		stepMotorRunStopState = STEPMOTOR_STOP;
		char buff[30];
		sprintf(buff, "STEP MOTOR STOP ");
	    move_cursor(0,0);
	    lcd_string(buff);
	}
}


void StepMotor_Control_Stop(void){
	StepMotor_Stop(); // Driver

	if(!QisEmpty(&hQue_ButtonRunStop))
	{
		//empty가 아닐때 실행
		DeQueue(&hQue_ButtonRunStop);
		stepMotorRunStopState = STEPMOTOR_RUN;
		char buff[30];
		sprintf(buff, "STEP MOTOR RUN ");
	    move_cursor(0,0);
	    lcd_string(buff);
	}
	// hButton_RunStop : BTN1
//	if(Button_GetState(&hButton_RunStop)){
//		stepMotorRunStopState = STEPMOTOR_RUN;
//		char buff[30];
//		sprintf(buff, "STEP MOTOR STOP");
//	    move_cursor(0,0);
//	    lcd_string(buff);
//	}
}



void StepMotor_Control_Speed(){
	switch(stepMotorSpeedState){
	case SPEED_1:
		StepMotor_Speed(SPEED_1);
		// hButton_Speed : BTN3
		if(!QisEmpty(&hQue_ButtonSpeed)){
			DeQueue(&hQue_ButtonSpeed);
//		if(Button_GetState(&hButton_Speed)){
//			__HAL_TIM_SET_COUNTER(&htim2,0);
			stepMotorSpeedState = SPEED_2;
			char buff[30];
			sprintf(buff, "SPEED 2");
		    move_cursor(1,0);
		    lcd_string(buff);
		}
		break;
	case SPEED_2:
		StepMotor_Speed(SPEED_2);
		// hButton_Speed : BTN3
		if(!QisEmpty(&hQue_ButtonSpeed)){
			DeQueue(&hQue_ButtonSpeed);
//		if(Button_GetState(&hButton_Speed)){
//			__HAL_TIM_SET_COUNTER(&htim2,0);
			stepMotorSpeedState = SPEED_3;
			char buff[30];
			sprintf(buff, "SPEED 3");
		    move_cursor(1,0);
		    lcd_string(buff);
		}
		break;
	case SPEED_3:
		StepMotor_Speed(SPEED_3);
		// hButton_Speed : BTN3
		if(!QisEmpty(&hQue_ButtonSpeed)){
			DeQueue(&hQue_ButtonSpeed);
//		if(Button_GetState(&hButton_Speed)){
//			__HAL_TIM_SET_COUNTER(&htim2,0);
			stepMotorSpeedState = SPEED_1;
			char buff[30];
			sprintf(buff, "SPEED 1");
		    move_cursor(1,0);
		    lcd_string(buff);
		}
		break;
	}
}



void StepMotor_Control_Direction(){
	switch (stepMotorDirState) {
		case CW:
			//ISR에서 하는중
			//StepMotor_Direction(CW); // Driver
			// hButton_Dir : BTN2
			if(!QisEmpty(&hQue_ButtonDir)){
				DeQueue(&hQue_ButtonDir);
//			if(Button_GetState(&hButton_Dir)){
				stepMotorDirState = CCW;
				char buff[30];
				sprintf(buff, "CCW");
			    move_cursor(1,10);
			    lcd_string(buff);
			}
			break;
		case CCW:
			//ISR에서 하는중
			//StepMotor_Direction(CCW); // Driver
			// hButton_Dir : BTN2
			if(!QisEmpty(&hQue_ButtonDir)){
				DeQueue(&hQue_ButtonDir);
//			if(Button_GetState(&hButton_Dir)){
				stepMotorDirState = CW;
				char buff[30];
				sprintf(buff, "CW");
			    move_cursor(1,10);
			    lcd_string(buff);
			}
			break;
	}
}
