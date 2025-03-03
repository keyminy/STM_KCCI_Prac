/*
 * DividerFactory_Controller.h
 *
 *  Created on: Mar 3, 2025
 *      Author: me
 */

#ifndef CONTROLLER_DIVIDERFACTORY_CONTROLLER_H_
#define CONTROLLER_DIVIDERFACTORY_CONTROLLER_H_
#include "main.h"
#include "../Driver/led.h"
#include "../Driver/uart.h"
#include "../System/Queue.h"

#define A_MACHINE 0x01
#define B_MACHINE 0x02

enum {IDLE,RED_STATE,GREEN_STATE};
void DividerFactory_SetState(uint8_t state);
uint8_t DividerFactory_GetState(uint8_t state);
void DividerFactory_Init(void);
void IdleState(void);
void DividerFactory_Controller(void);
void RedState(void);
void GreenState(void);

#endif /* CONTROLLER_DIVIDERFACTORY_CONTROLLER_H_ */
