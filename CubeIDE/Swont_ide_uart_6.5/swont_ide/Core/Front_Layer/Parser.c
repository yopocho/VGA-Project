/*
 * Parser.c
 *
 *  Created on: 10 May 2023
 *      Author: r_middelman
 */

#include "Parser.h"

/// @fn void ParseOnKomma(input_vars)
/// @brief loops through the incomming message and checks for ascii number 44
/// (,) at the same time fill an array to check later what type of message it
/// is.
///
/// @param inputStruct
void ParseOnKomma(input_vars inputStruct, uint8_t neededArgument,
				  uint8_t convertToNumber, int convertColor,
				  command commandArray) {
	uint8_t commaCounter = 0;
	uint8_t placeInBuf = 0;
	char incommingMessage[inputStruct.msglen];
	for (int j = 0; j < inputStruct.msglen; j++) {
		if (inputStruct.line_rx_buffer[j] == ',') {
			incommingMessage[j] = 0;
			placeInBuf = 0;
#ifdef FRONT_LAYER_DEBUG
			OutputDebug(debugMessageParse, sizeof(debugMessageParse), &huart2);
#endif
			if (commaCounter == neededArgument) {
				if (!commaCounter)
					CheckWhatCommand(incommingMessage, commandArray,
									 inputStruct);
				if (convertColor)
					CheckWhatColor(incommingMessage, commandArray,
								   neededArgument);
				if (convertToNumber)
					commandArray[neededArgument] = atoi(incommingMessage);
				break;
			}
			commaCounter++;
			// set the array to 0 again to fill with the argument
			memset(incommingMessage, 0, sizeof(incommingMessage));
		}
		if (inputStruct.line_rx_buffer[j] != 0 &&
			inputStruct.line_rx_buffer[j] != ',') {
			incommingMessage[placeInBuf] = inputStruct.line_rx_buffer[j];
			placeInBuf++;
		}
	}
}

/**
 * @fn void CheckWhatCommand(char[], command)
 * @brief
 *
 * @param commandNames
 * @param commandArray
 */
void CheckWhatCommand(char incommingCommand[], command commandArray,
					  input_vars inputStruct) {
	for (uint8_t i = 0; i < AMOUNT_OF_COMMANDS; i++) {
		if (strcmp(incommingCommand, possibleCommands[i]) == 0) {
			commandArray[0] = i;
#ifdef FRONT_LAYER_DEBUG
			OutputDebug(debugMessageCommand, sizeof(debugMessageCommand),
						&huart2);
#endif
			DoOnCommand(commandArray, inputStruct);
		}
	}
}
/**
 * @fn void CheckWhatColor(char[], command, uint8_t)
 * @brief
 *
 * @param colorNames
 * @param commandArray
 * @param argPlace
 */
void CheckWhatColor(char incommingColor[], command commandArray,
					uint8_t argPlace) {
	for (uint8_t i = 0; i < AMOUNT_OF_COLORS; i++) {
		if (strcmp(incommingColor, possibleColors[i]) == 0) {
			commandArray[argPlace] = colorCodes[i];
#ifdef FRONT_LAYER_DEBUG
			OutputDebug(debugMessageColor, sizeof(debugMessageColor), &huart2);
#endif
			break;
		}
	}
}

void DoOnCommand(command commandArray, input_vars inputStruct) {
	switch (commandArray[0]) {
		case 0:
			// lijn
			RecieveCommandLijn(commandArray, inputStruct);
			break;
		case 1:
			break;
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
