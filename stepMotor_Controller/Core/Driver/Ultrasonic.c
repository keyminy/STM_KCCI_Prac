#include "Ultrasonic.h"

static volatile uint16_t UltraSonicCounter = 0;
static volatile uint8_t UltraSonicReadyFlag = 0;

void UltraSonic_SetReadyFlag(uint8_t flag)
{
	UltraSonicReadyFlag = flag;
}

void UltraSonic_Trigger(void)
{
	HAL_GPIO_WritePin(TRIGGER_GPIO_Port, TRIGGER_Pin, GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(TRIGGER_GPIO_Port, TRIGGER_Pin, GPIO_PIN_RESET);
}

uint8_t UltraSonic_IsReady(void)
{
	return UltraSonicReadyFlag;
}

uint8_t UltraSonic_GetDistance(void)
{
	uint16_t distance;
	UltraSonic_SetReadyFlag(CLEAR);
	distance = (int)(UltraSonicCounter * 0.017);
	return distance;
}

void UltraSonic_ISR_Process(void)
{
	if(HAL_GPIO_ReadPin(ECHO_GPIO_Port, ECHO_Pin))
	{
		__HAL_TIM_SET_COUNTER(&htim3,0);
	}
	else
	{
		UltraSonicCounter = __HAL_TIM_GET_COUNTER(&htim3);
		UltraSonic_SetReadyFlag(READY);
	}
}
