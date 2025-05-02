#include "I2C.h"

I2C_Control_HandleTypeDef hI2C_LCD = {&hi2c1,(0x27<<1)};

// param : LCD DEVICE ADDRESS Write, lcdData
// send only 1byte
//void I2C_TxByte(uint16_t LCD_DEV_ADDR_W,uint8_t lcdData)
void I2C_TxByte(I2C_Control_HandleTypeDef *hi2c,uint8_t data)
{
	HAL_I2C_Master_Transmit(hi2c->hi2c, hi2c->DevAddress, &data, 1, 1000);
}

// param : LCD DEVICE ADDRESS Write, lcdData
void I2C_RxByteI2C_TxByte(I2C_Control_HandleTypeDef *hi2c)
{
	uint8_t rxData;
	HAL_I2C_Master_Receive(hi2c->hi2c, hi2c->DevAddress, &rxData, 1, 1000);
	return rxData;
}

void I2C_TxStream(I2C_Control_HandleTypeDef *hi2c,uint8_t *pData,uint16_t Size)
{
	HAL_I2C_Master_Transmit(hi2c->hi2c, hi2c->DevAddress, pData, Size, 1000);

}

void I2C_RxStream(I2C_Control_HandleTypeDef *hi2c,uint8_t *pData,uint16_t Size)
{
	HAL_I2C_Master_Receive(hi2c->hi2c, hi2c->DevAddress, pData, Size, 1000);
}
