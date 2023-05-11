/*
 * Parser.h
 *
 *  Created on: 10 May 2023
 *      Author: r_middelman
 */

#ifndef FRONT_LAYER_PARSER_H_
#define FRONT_LAYER_PARSER_H_

#include "usart.h"

#define FRONT_LAYER_DEBUG

void ParseOnKomma(input_vars inputStruct);
void OutputDebug(char message[], size_t messageLength, UART_HandleTypeDef *uartHandle);

#endif /* FRONT_LAYER_PARSER_H_ */
