/*
 * Parser.c
 *
 *  Created on: 10 May 2023
 *      Author: r_middelman
 */

#include "Parser.h"

char debugMessageParse[] = "Found comma in message\n";
char debugMessageCommand[] = "Matched command with number";

char possibleCommands[AMOUNT_OF_COMMANDS][12] = {
	"clearscherm", "lijn",	 "rechthoek", "wacht",	"tekst",
	"bitmap",	   "cirkel", "figuur",	  "herhaal"};


char possibleColors[AMOUNT_OF_COLORS][12] = {

};

/// @fn void ParseOnKomma(input_vars)
/// @brief
/// loops through the incomming message and checks for ascii number 44 (,)
/// at the same time fill an array to check later what type of message it is.
///
/// @param inputStruct
void ParseOnKomma(input_vars inputStruct) {
	char incommingMessage[inputStruct.msglen];
	// walk through all letters of the messsage
	for (int i = 0; i < inputStruct.msglen; i++) {
		// check if there is a comma
		if (inputStruct.line_rx_buffer[i] == 44) {
#ifdef FRONT_LAYER_DEBUG
			OutputDebug(debugMessageParse, sizeof(debugMessageParse), &huart2);
#endif
			break;
		}
		incommingMessage[i] = inputStruct.line_rx_buffer[i];
	}
}

/// @fn void CheckWhatCommandArray(char[], input_vars)
/// @brief
///
/// @param command
/// @param inputStruct
void CheckWhatCommandArray(char commandArray[], command commandStruct) {
	for (uint8_t i = 0; i < AMOUNT_OF_COMMANDS; i++) {
		if (strcmp(commandArray, possibleCommands[i]) == 0) {
			commandStruct.commandCode = i;
#ifdef FRONT_LAYER_DEBUG
			OutputDebug(debugMessageCommand, sizeof(debugMessageCommand), &huart2);
#endif
		}
	}
}

/// @fn void OutputDebug(char[], size_t, UART_HandleTypeDef*)
/// @brief most simple debug function
///
/// @param message
/// @param messageLength
/// @param uartHandle
void OutputDebug(char message[], size_t messageLength,
				 UART_HandleTypeDef *uartHandle) {
	HAL_UART_Transmit(uartHandle, message, messageLength, 10);
}
