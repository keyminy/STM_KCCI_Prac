#include "led.h"

LED_HandleTypeDef hLedRed = {GPIOC, GPIO_PIN_6};
LED_HandleTypeDef hLedGreen = {GPIOC, GPIO_PIN_8};

void LED_Toggle(LED_HandleTypeDef *hLed){
	HAL_GPIO_TogglePin(hLed->GPIO, hLed->GPIO_Pin);
}
