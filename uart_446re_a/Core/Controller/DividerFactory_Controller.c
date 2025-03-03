#include "DividerFactory_Controller.h"

uint8_t controllerState;

void DividerFactory_SetState(uint8_t state){
	controllerState = state;
}
uint8_t DividerFactory_GetState(uint8_t state){
	return controllerState;
}

void DividerFactory_Init(void){
	DividerFactory_SetState(IDLE);
	UART_Init(&hQBuff,&huart2);
}

void DividerFactory_Controller(void){
	switch (controllerState) {
	case IDLE:
		IdleState();
		break;
	case RED_STATE:
		RedState();
		break;
	case GREEN_STATE:
		GreenState();
		break;
	}
}

void RedState(void){
	uint8_t redData;

	if(QisEmpty(&hQueA) == FALSE){
		// excute when not empty
		redData = DeQueue(&hQueA);
		for(int i=0; i < redData; i++){
			LED_Toggle(&hLedRed);
			HAL_Delay(200);
		}
	} else {
		DividerFactory_SetState(IDLE);
	}
}

void GreenState(void){
	uint8_t greenData;

	if(QisEmpty(&hQueB) == FALSE){
		// excute when not empty
		greenData = DeQueue(&hQueB);
		for(int i=0; i < greenData; i++){
			LED_Toggle(&hLedGreen);
			HAL_Delay(200);
		}
	}else {
		DividerFactory_SetState(IDLE);
	}
}
void IdleState(void){
	DividerFactory_DataDivider();
}
void DividerFactory_DataDivider(void){
	uint8_t* buff;
	if(UART_GetReadyQBuff(&hQBuff)){
		buff = UART_GetBuff(&hQBuff);
//		if(buff[0] == A장비){
		if(buff[0] == A_MACHINE){
			EnQueue(&hQueA,buff[1]);
			DividerFactory_SetState(RED_STATE);
		}
//		else if(buff[0] == B장비){
		else if(buff[0] == B_MACHINE){
			EnQueue(&hQueB,buff[1]);
			DividerFactory_SetState(GREEN_STATE);
		}
		UART_SetReadyQBuff(&hQBuff, 0);
	}
}
