/*
 * rfidDatabase.h
 *
 *  Created on: 2025. 5. 2.
 *      Author: me
 */

#ifndef CONTROLLER_RFIDDATABASE_H_
#define CONTROLLER_RFIDDATABASE_H_
#include "main.h"

#define VALID 	1
#define INVALID	0

uint8_t Rfid_DB_CheckNumber(uint8_t* cardNumber);

#endif /* CONTROLLER_RFIDDATABASE_H_ */
