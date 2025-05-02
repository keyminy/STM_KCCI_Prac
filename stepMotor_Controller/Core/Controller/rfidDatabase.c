#include "rfidDatabase.h"

uint8_t validCard[2][5] = {
		  {0x0c,0xc8,0x4c,0x30, 0xb8},
		  {0,}
  };

uint8_t Rfid_DB_CheckNumber(uint8_t* cardNumber) {
	for (int i = 0; i < 2; i++) {
		// compare 5digits
		if (!strncmp(validCard[i], cardNumber, 5)) {
//			printf("Valid Card! : %d(row)\n", i);
			return VALID;
		}
	}
	return INVALID;
}
