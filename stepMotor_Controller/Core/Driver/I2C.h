/*
 * I2C.h
 *
 *  Created on: May 2, 2025
 *      Author: me
 */

#ifndef DRIVER_I2C_H_
#define DRIVER_I2C_H_
#include "main.h"

typedef struct{
	I2C_HandleTypeDef* hi2c;
	uint16_t DevAddress;
} I2C_Control_HandleTypeDef;

extern I2C_Control_HandleTypeDef hI2C_LCD;

void I2C_TxByte(I2C_Control_HandleTypeDef *hi2c,uint8_t data);
// param : LCD DEVICE ADDRESS Write, lcdData
void I2C_RxByteI2C_TxByte(I2C_Control_HandleTypeDef *hi2c);
void I2C_TxStream(I2C_Control_HandleTypeDef *hi2c,uint8_t *pData,uint16_t Size);
void I2C_RxStream(I2C_Control_HandleTypeDef *hi2c,uint8_t *pData,uint16_t Size);

#endif /* DRIVER_I2C_H_ */
