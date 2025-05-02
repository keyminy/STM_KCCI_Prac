/*
 * rfid.h
 *
 *  Created on: 2025. 5. 2.
 *      Author: me
 */

#ifndef CONTROLLER_RFID_H_
#define CONTROLLER_RFID_H_
#include "main.h"
#include "../Driver/mfrc522.h"

#define TRUE 	1
#define FALSE 	0
#define MAX_LEN 16

void RFID_Init(void);
uint8_t RFID_IsDetectCard(void);
void RFID_GetCardNumber(uint8_t* cardNumber);

#endif /* CONTROLLER_RFID_H_ */
