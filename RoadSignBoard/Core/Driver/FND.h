/*
 * FND.h
 *
 *  Created on: 2025. 2. 1.
 *      Author: me
 */

#ifndef DRIVER_FND_H_
#define DRIVER_FND_H_
#include "main.h"

// PA6,PA7,PC4,PC5,PB0,PB1,PB2,PB10
#define FND_GPIO_DATA GPIOA


// digit : PA8,PA9,PA10,PA11
#define FND_GPIO_DIGIT 	  GPIOB

#define FND_PIN_DIGIT_0   GPIO_PIN_0
#define FND_PIN_DIGIT_1   GPIO_PIN_1
#define FND_PIN_DIGIT_2   GPIO_PIN_2
#define FND_PIN_DIGIT_3   GPIO_PIN_4

enum {
	DIGIT_0,
	DIGIT_1,
	DIGIT_2,
	DIGIT_3
};

void FND_ShowMode(uint8_t mode);
void FND_ShowSpeed(uint8_t speed);
void FND_ISR_Process(void);
void FND_WriteData(void);

#endif /* DRIVER_FND_H_ */
