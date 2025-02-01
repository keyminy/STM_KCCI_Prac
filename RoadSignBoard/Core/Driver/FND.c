/*
 * FND.c
 *
 *  Created on: 2025. 2. 1.
 *      Author: me
 */
#include "fnd.h"

uint8_t modeData;
uint8_t speedData;


void FND_ShowMode(uint8_t mode){
	modeData = mode;
}

void FND_ShowSpeed(uint8_t speed){
	speedData = speed;
}

void FND_ISR_Process(void){
	FND_WriteData();
}

void FND_WriteData(void){
	static uint8_t fndState = 0;
	fndState = (fndState+1) % 4;

	uint16_t FND_FONT[] = {
	        0x40, // 0
	        0xF9|(FND_D_Pin), // 1
	        0xA4|(FND_C_Pin), // 2
	        0xB0, // 3
	        0x99|(FND_D_Pin), // 4
	        0x92, // 5
	        0x82, // 6
	        0xF8, // 7
	        0x80, // 8
	        0x90,  // 9
			0x7F // DP
	};

//	FND_SelectDigit(DIGIT_ALL,OFF);
	  HAL_GPIO_WritePin(FND_GPIO_DATA, FND_A_Pin | FND_B_Pin | FND_C_Pin | FND_D_Pin
              | FND_E_Pin | FND_F_Pin | FND_G_Pin | FND_DP_Pin, GPIO_PIN_RESET); // OFF All data

	// OFF All digit
	HAL_GPIO_WritePin(FND_GPIO_DIGIT, FND_PIN_DIGIT_0, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(FND_GPIO_DIGIT, FND_PIN_DIGIT_1, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(FND_GPIO_DIGIT, FND_PIN_DIGIT_2, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(FND_GPIO_DIGIT, FND_PIN_DIGIT_3, GPIO_PIN_RESET);

	// ISR마다 fnd출력
	switch(fndState){
	case DIGIT_0:
//		FND_SendData(fndDigitData_0);
//		FND_SelectDigit(DIGIT_0,ON);
		HAL_GPIO_WritePin(FND_GPIO_DATA, FND_FONT[modeData%10], GPIO_PIN_SET);
		HAL_GPIO_WritePin(FND_GPIO_DIGIT, FND_PIN_DIGIT_0, GPIO_PIN_SET);
		break;
	case DIGIT_1:
//		FND_SendData(fndDigitData_1);
//		FND_SelectDigit(DIGIT_1,ON);
		HAL_GPIO_WritePin(FND_GPIO_DATA, FND_FONT[modeData/10%10], GPIO_PIN_SET);
		HAL_GPIO_WritePin(FND_GPIO_DIGIT, FND_PIN_DIGIT_1, GPIO_PIN_SET);
		break;
	case DIGIT_2:
//		FND_SendData(fndDigitData_2);
//		FND_SelectDigit(DIGIT_2,ON);
		HAL_GPIO_WritePin(FND_GPIO_DATA, FND_FONT[speedData%10], GPIO_PIN_SET);
		HAL_GPIO_WritePin(FND_GPIO_DIGIT, FND_PIN_DIGIT_2, GPIO_PIN_SET);
		break;
	case DIGIT_3:
//		FND_SendData(fndDigitData_3);
//		FND_SelectDigit(DIGIT_3,ON);
		HAL_GPIO_WritePin(FND_GPIO_DATA, FND_FONT[speedData/10%10], GPIO_PIN_SET);
		HAL_GPIO_WritePin(FND_GPIO_DIGIT, FND_PIN_DIGIT_3, GPIO_PIN_SET);
		break;
	}
}
//
//void FND_SendData(uint8_t fndData){
//	// PA6,PA7,PC4,PC5,PB0,PB1,PB2,PB10
//	GPIO_TypeDef* FND_GPIO_DATA[8] = {
//			GPIOA, 		GPIOA, 		GPIOC, 		GPIOC,
//			GPIOB, 		GPIOB, 		GPIOB, 		GPIOB
//	};
//	uint16_t FND_GPIO_DATA_PIN[8] = {
//			GPIO_PIN_6,		GPIO_PIN_7,		GPIO_PIN_4,		GPIO_PIN_5,
//			GPIO_PIN_0,		GPIO_PIN_1,		GPIO_PIN_2,		GPIO_PIN_10
//	};
//	uint8_t FND_FONT[] = {
//	        0xC0, // 0
//	        0xF9, // 1
//	        0xA4, // 2
//	        0xB0, // 3
//	        0x99, // 4
//	        0x92, // 5
//	        0x82, // 6
//	        0xF8, // 7
//	        0x80, // 8
//	        0x90,  // 9
//			0x7F // DP
//	};
//	for(int i=0; i < 8; i++){
//		HAL_GPIO_WritePin(FND_GPIO_DATA[i], FND_FONT[fndData], GPIO_PIN_SET);
//	}
//}
//
//void FND_SelectDigit(GPIO_TypeDef* FND_Select_GPIO,uint16_t FND_Select_GPIO_PIN){
//	// PA8,PA9,PA10,PA11
//	for(int i=0; i < 8; i++){
//		HAL_GPIO_WritePin(FND_Select_GPIO[i], FND_Select_GPIO_PIN[i], fndData & (1<<i));
//	}
//}

