/*
 * FND.h
 *
 *  Created on: 2025. 4. 30.
 *      Author: me
 */

#ifndef DRIVER_FND_H_
#define DRIVER_FND_H_
#include "main.h"

void FND_SetData(uint16_t data);
uint16_t FND_GetData(void);
void FND_ISR_Process(void);
void FND_DisplayData(void);


#endif /* DRIVER_FND_H_ */
