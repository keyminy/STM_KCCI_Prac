/*
 * SPI.h
 *
 *  Created on: 2025. 5. 1.
 *      Author: me
 */

#ifndef DRIVER_SPI_H_
#define DRIVER_SPI_H_
#include "main.h"

typedef struct{
	SPI_HandleTypeDef* hspi;
	GPIO_TypeDef* GPIO;
	uint16_t GPIO_Pin;
} SPI_CONTROL_HandleTypedef;

extern SPI_CONTROL_HandleTypedef hSpiFnd;
extern SPI_CONTROL_HandleTypedef hSpiRfid;

void SPI_Init(SPI_CONTROL_HandleTypedef* hSpi,SPI_HandleTypeDef* hspi);
void SPI_WriteStream(SPI_CONTROL_HandleTypedef* hSpi,uint8_t* data,uint16_t Size);
void SPI_WriteByte(SPI_CONTROL_HandleTypedef* hSpi,uint8_t data);
void SPI_ReadStream(SPI_CONTROL_HandleTypedef* hSpi,uint8_t* data,uint16_t Size);
uint8_t SPI_ReadByte(SPI_CONTROL_HandleTypedef* hSpi);
void SPI_TranceiveStream(SPI_CONTROL_HandleTypedef* hSpi,uint8_t* txData,uint8_t* rxData,uint16_t Size);
uint8_t SPI_TranceiveByte(SPI_CONTROL_HandleTypedef* hSpi,uint8_t txData);

#endif /* DRIVER_SPI_H_ */
