/*
 * Parser.c
 *
 *  Created on: 10 May 2023
 *      Author: r_middelman
 */

#include "Parser.h"

char debugMessageParse[] = "Found comma in message\n";

/// @fn void ParseOnKomma(input_vars)
/// @brief
///
/// @param inputStruct
void ParseOnKomma(input_vars inputStruct) {
  // walk through all letters of the messsage
  for (int i = 0; i < inputStruct.msglen; i++) {
    // check if there is a comma
    if (inputStruct.line_rx_buffer[i] == 44) {
      #ifdef FRONT_LAYER_DEBUG
        OutputDebug(debugMessage, sizeof(debugMessage), &huart2);
      #endif
    }
  }
}

/// @fn void OutputDebug(char[], size_t, UART_HandleTypeDef*)
/// @brief
///
/// @param message
/// @param messageLength
/// @param uartHandle
void OutputDebug(char message[], size_t messageLength,
                 UART_HandleTypeDef *uartHandle) {
  HAL_UART_Transmit(uartHandle, message, messageLength, 10);
}
