#include "Button.h"

BUTTON_HandleTypeDef hButton_RunStop 	= {B1_GPIO_Port,B1_Pin,RELEASED};
BUTTON_HandleTypeDef hButton_Dir 		= {BTN2_GPIO_Port,BTN2_Pin,RELEASED};
BUTTON_HandleTypeDef hButton_Speed 		= {BTN3_GPIO_Port,BTN3_Pin,RELEASED};

//void Button_GetState(&hButton_RunStop){
uint8_t Button_GetState(BUTTON_HandleTypeDef* hButton){

	//	static uint8_t prevState = RELEASED;

	// pull up 저항, 버튼 누르면 0V로 떨어짐
	uint8_t curState = HAL_GPIO_ReadPin(hButton->GPIOx,hButton->GPIO_Pin);

	if((curState == PUSHED) && (hButton->prevState != PUSHED)){
		// 처음 누른상태임, 전 상태는 안눌려있었던거고 새롭게 눌려진 것.
		HAL_Delay(10);
		hButton->prevState = PUSHED; // 눌렸다.
		return FALSE; // 눌렸다 뗏을 때 동작하고 싶음.
	}else if((curState != PUSHED) && (hButton->prevState == PUSHED)){
		// 현재상태 : 눌렸다가 뗀 상태!!, 그러면 prevState는 PUSHED상태
		HAL_Delay(10);
		hButton->prevState = RELEASED;
		return TRUE;
	}
	return FALSE; // default FALSE return
}
