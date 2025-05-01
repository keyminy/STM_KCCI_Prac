#include "FND.h"

uint16_t fndData = 0;

void FND_SetData(uint16_t data){
	fndData = data;
}

uint16_t FND_GetData(void){
	return fndData;
}

// ISR에서 실행되는 함수
void FND_ISR_Process(void){
	FND_DisplayData();
}

void FND_WriteData(uint8_t* data)
{
	SPI_WriteStream(&hSpiFnd,data,2);
//	HAL_GPIO_WritePin(SPI2_SS_GPIO_Port, SPI2_SS_Pin, GPIO_PIN_RESET);
//	HAL_SPI_Transmit(&hspi2, data, 2, 1000); // 2byte, timeout 1s
//	HAL_GPIO_WritePin(SPI2_SS_GPIO_Port, SPI2_SS_Pin, GPIO_PIN_SET);
}


void FND_DisplayData(void){
	uint8_t fndFont[] = {
			0xC0, // 0
			0xF9, // 1
			0xA4, // 2
			0xB0, // 3
			0x99, // 4
			0x92, // 5
			0x82, // 6
			0xF8, // 7
			0x80, // 8
			0x90,  // 9
			0x7F // DP
	};
	uint8_t fndValue[2];
	static uint8_t fndState = 0;
	fndState = (fndState+1) % 4;// INT걸릴때마다 fndState증가

	switch (fndState)
	{
		case 0:
			fndValue[0] = 0x10;// 1000자리
			fndValue[1] = fndFont[fndData/1000%10];
			FND_WriteData(fndValue);
			break;
		case 1:
			fndValue[0] = 0x20;// 100자리
			fndValue[1] = fndFont[fndData/100%10];
			FND_WriteData(fndValue);
			break;
		case 2:
			fndValue[0] = 0x40;// 10자리
			fndValue[1] = fndFont[fndData/10%10];
			FND_WriteData(fndValue);
			break;
		case 3:
			fndValue[0] = 0x80;// 1자리
			fndValue[1] = fndFont[fndData%10];
			FND_WriteData(fndValue);
			break;
	}
}
