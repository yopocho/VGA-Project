/*
 * Parser.c
 *
 *  Created on: 10 May 2023
 *      Author: r_middelman
 */

#include "Parser.h"

char debugMessage[] = "Debug is working";


void Parse_On_Komma(input_vars inputStruct){

}

void OutputDebug(char debugMessage, UART_HandleTypeDef *uartHandle){
	HAL_UART_Transmit(uartHandle, debugMessage, sizeof(debugMessage), 10);
}


