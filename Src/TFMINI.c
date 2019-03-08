#include "TFMINI.h"

UART_HandleTypeDef TFMINI_uart;
uint8_t frame[9];
const uint8_t HEADER = 0x59;

void TFMINI_Initialize(UART_HandleTypeDef *huart){
	TFMINI_uart = *huart;
	uint8_t command[8] = {0x42, 0x57, 0x02, 0x00, 0x00, 0x00, 0x01, 0x06};
	
	HAL_UART_Transmit(&TFMINI_uart, command, 8, 0xFF);
}

int TFMINI_GetDistance(void){
	int dist = 0;
	HAL_UART_Receive(&TFMINI_uart, frame, 9, HAL_MAX_DELAY);
	if (frame[0] == HEADER && frame[1] == HEADER)
		dist = frame[2] + frame[3] * 256;
	return dist;
}

int TFMINI_GetStrength(void){
	int stre = 0;
	HAL_UART_Receive(&TFMINI_uart, frame, 9, HAL_MAX_DELAY);
	if (frame[0] == HEADER && frame[1] == HEADER)
		stre = frame[4] + frame[5] * 256;
	return stre;
}