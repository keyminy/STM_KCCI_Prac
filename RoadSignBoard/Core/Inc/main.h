/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
extern TIM_HandleTypeDef htim2;;
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define BUTTON2_Pin GPIO_PIN_0
#define BUTTON2_GPIO_Port GPIOC
#define FND_A_Pin GPIO_PIN_0
#define FND_A_GPIO_Port GPIOA
#define FND_B_Pin GPIO_PIN_1
#define FND_B_GPIO_Port GPIOA
#define FND_E_Pin GPIO_PIN_4
#define FND_E_GPIO_Port GPIOA
#define FND_F_Pin GPIO_PIN_5
#define FND_F_GPIO_Port GPIOA
#define FND_G_Pin GPIO_PIN_6
#define FND_G_GPIO_Port GPIOA
#define FND_DP_Pin GPIO_PIN_7
#define FND_DP_GPIO_Port GPIOA
#define FND_DIGIT_0_Pin GPIO_PIN_0
#define FND_DIGIT_0_GPIO_Port GPIOB
#define FND_DIGIT_1_Pin GPIO_PIN_1
#define FND_DIGIT_1_GPIO_Port GPIOB
#define FND_DIGIT_2_Pin GPIO_PIN_2
#define FND_DIGIT_2_GPIO_Port GPIOB
#define LED1_Pin GPIO_PIN_12
#define LED1_GPIO_Port GPIOB
#define LED2_Pin GPIO_PIN_13
#define LED2_GPIO_Port GPIOB
#define LED3_Pin GPIO_PIN_14
#define LED3_GPIO_Port GPIOB
#define LED4_Pin GPIO_PIN_15
#define LED4_GPIO_Port GPIOB
#define LED5_Pin GPIO_PIN_6
#define LED5_GPIO_Port GPIOC
#define LED6_Pin GPIO_PIN_7
#define LED6_GPIO_Port GPIOC
#define LED7_Pin GPIO_PIN_8
#define LED7_GPIO_Port GPIOC
#define LED8_Pin GPIO_PIN_9
#define LED8_GPIO_Port GPIOC
#define FND_C_Pin GPIO_PIN_11
#define FND_C_GPIO_Port GPIOA
#define FND_D_Pin GPIO_PIN_12
#define FND_D_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
#define FND_DIGIT_3_Pin GPIO_PIN_4
#define FND_DIGIT_3_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
