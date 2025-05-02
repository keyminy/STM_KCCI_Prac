#include "rfid.h"
#include <stdio.h>


void RFID_Init(void)
{
	  uint8_t byte;

	  mfrc522_init(&hspi2);
	  byte = mfrc522_read(VersionReg);

	  printf("ver : %0x\n",byte); // read Version Info byte
	  if(byte == 0x92){
		  printf("MIFARE RC522v1\n");
		  printf("Detected!\n");
	  }else{
		  printf("No reader found\n");
	  }
}

// Card is tagged?
uint8_t RFID_IsDetectCard(void){
	uint8_t byte;
	uint8_t str[MAX_LEN];

	byte = mfrc522_request(PICC_REQALL, str);
	if(byte == CARD_FOUND){
		return TRUE;
	}
	return FALSE;
}

void RFID_GetCardNumber(uint8_t* cardNumber){
	mfrc522_get_card_serial(cardNumber);
}
