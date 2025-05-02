#include "SPI.h"

SPI_CONTROL_HandleTypedef hSpiFnd = {&hspi2,SPI2_SS_GPIO_Port,SPI2_SS_Pin};
SPI_CONTROL_HandleTypedef hSpiRfid = {&hspi2,SPI_RFID_SS_GPIO_Port,SPI_RFID_SS_Pin};

void SPI_Init(SPI_CONTROL_HandleTypedef* hSpi,SPI_HandleTypeDef* hspi){
	hSpi->hspi = hspi;
}

void SPI_WriteStream(SPI_CONTROL_HandleTypedef* hSpi,uint8_t* data,uint16_t Size) {
	HAL_GPIO_WritePin(hSpi->GPIO, hSpi->GPIO_Pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(hSpi->hspi, data, Size, 1000); // 2byte, timeout 1s
	HAL_GPIO_WritePin(hSpi->GPIO, hSpi->GPIO_Pin, GPIO_PIN_SET);
}
// send only one data byte
void SPI_WriteByte(SPI_CONTROL_HandleTypedef* hSpi,uint8_t data) {
	HAL_GPIO_WritePin(hSpi->GPIO, hSpi->GPIO_Pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(hSpi->hspi, &data, 1, 1000); // 1byte, timeout 1s
	HAL_GPIO_WritePin(hSpi->GPIO, hSpi->GPIO_Pin, GPIO_PIN_SET);
}

void SPI_ReadStream(SPI_CONTROL_HandleTypedef* hSpi,uint8_t* data,uint16_t Size) {
	HAL_GPIO_WritePin(hSpi->GPIO, hSpi->GPIO_Pin, GPIO_PIN_RESET);
	HAL_SPI_Receive(hSpi->hspi, data, Size, 1000); // read data in the variable "data"
	HAL_GPIO_WritePin(hSpi->GPIO, hSpi->GPIO_Pin, GPIO_PIN_SET);
}
uint8_t SPI_ReadByte(SPI_CONTROL_HandleTypedef* hSpi) {
	uint8_t rxData;
	HAL_GPIO_WritePin(hSpi->GPIO, hSpi->GPIO_Pin, GPIO_PIN_RESET);
	HAL_SPI_Receive(hSpi->hspi, &rxData, 1, 1000); // read 1byte data in the variable "rxData"
	HAL_GPIO_WritePin(hSpi->GPIO, hSpi->GPIO_Pin, GPIO_PIN_SET);

	return rxData;
}

void SPI_TranceiveStream(SPI_CONTROL_HandleTypedef* hSpi,uint8_t* txData,uint8_t* rxData,uint16_t Size)
{
	HAL_GPIO_WritePin(hSpi->GPIO, hSpi->GPIO_Pin, GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(hSpi->hspi, txData, rxData, Size, 1000);
	HAL_GPIO_WritePin(hSpi->GPIO, hSpi->GPIO_Pin, GPIO_PIN_SET);
}

uint8_t SPI_TranceiveByte(SPI_CONTROL_HandleTypedef* hSpi,uint8_t txData)
{
	uint8_t rxData;
	HAL_GPIO_WritePin(hSpi->GPIO, hSpi->GPIO_Pin, GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(hSpi->hspi, &txData, &rxData, 1, 1000);
	HAL_GPIO_WritePin(hSpi->GPIO, hSpi->GPIO_Pin, GPIO_PIN_SET);
	return rxData;
}

