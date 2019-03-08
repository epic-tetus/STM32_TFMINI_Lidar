#ifndef __TFMINI__H__
#define __TFMINI__H__

#include "stm32f1xx_hal.h"

void TFMINI_Initialize(UART_HandleTypeDef *huart);
int TFMINI_GetDistance(void);
int TFMINI_GetStrength(void);

#endif