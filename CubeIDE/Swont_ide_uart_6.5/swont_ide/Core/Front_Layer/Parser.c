/*
 * Parser.c
 *
 *  Created on: 10 May 2023
 *      Author: r_middelman
 */

#include "Parser.h"

/**
 * @fn void ParseOnKomma(input_vars, uint8_t, uint8_t, int, command)
 * @brief parser on comma function. works by looping
 * through the input and then executing calling the command that is futher
 * needed
 *
 * @param inputStruct
 * @param neededArgument
 * @param convertToNumber
 * @param convertColor
 * @param commandArray
 */
Error ParseOnKomma(input_vars inputStruct, uint8_t neededArgument,
				  uint8_t convertToNumber, int convertColor,
				  command commandArray) {
	uint8_t commaCounter = 0;
	uint8_t placeInBuf = 0;
	char incommingMessage[inputStruct.msglen];
	for (int j = 0; j <= inputStruct.msglen; j++) {
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
		if (j == inputStruct.msglen) {
			incommingMessage[placeInBuf] = inputStruct.line_rx_buffer[j];
			placeInBuf++;
			if (commaCounter == neededArgument) {
				if (convertColor)
					CheckWhatColor(incommingMessage, commandArray,
								   neededArgument);
				if (convertToNumber)
					commandArray[neededArgument] = atoi(incommingMessage);
			}
			break;
		}
		if (inputStruct.line_rx_buffer[j] != 0 &&
			inputStruct.line_rx_buffer[j] != ',') {
			incommingMessage[placeInBuf] = inputStruct.line_rx_buffer[j];
			placeInBuf++;
		}
	}
}

/**
 * @fn void CheckWhatCommand(char[], command, input_vars)
 * @brief checks what command is being called,
 * compares the incomming string with a list of strings
 *
 * @param incommingCommand
 * @param commandArray
 * @param inputStruct
 */
Error CheckWhatCommand(char incommingCommand[], CmdStruct CmdBuf,
					  input_vars inputStruct) {
	for (uint8_t i = 0; i < AMOUNT_OF_COMMANDS; i++) {
		if (strcmp(incommingCommand, possibleCommands[i]) == 0) {
			CmdBuf.commandNummer = i;
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
 * @brief checks what color is being called and asignes a numerical value in an
 * array
 *
 * @param incommingColor
 * @param commandArray
 * @param argPlace
 */
Error CheckWhatColor(char incommingColor[], CmdStruct CmdBuf, uint8_t argPlace) {
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
/**
 * @fn void DoOnCommand(command, input_vars)
 * @brief checks which command is given and takes futher actions to add the rest
 * of the args
 *
 * @param commandArray
 * @param inputStruct
 */
Error DoOnCommand(CmdStruct CmdBuf, input_vars inputStruct) {
	switch (commandArray[0]) {
		case 0:
			// lijn
			RecieveCommandLijn(commandArray, inputStruct);
			break;
		case 1:
			// clearscherm
			RecieveCommandClear(commandArray, inputStruct);
			break;
		case 2:
			// rechthoek
			RecieveCommandRechthoek(commandArray, inputStruct);
			break;
		case 3:
			// wacht
			RecieveCommandWacht(commandArray, inputStruct);
			break;
		case 4:
			// tekst
			RecieveCommandTekst(commandArray, inputStruct);
			break;
		case 5:
			// bitmap
			RecieveCommandBitmap(commandArray, inputStruct);
			break;
		case 6:
			// cirkel
			RecieveCommandCirkel(commandArray, inputStruct);
			break;
		case 7:
			// figuur
			RecieveCommandFiguur(commandArray, inputStruct);
			break;
		case 8:
			// herhaal
			RecieveCommandHerhaal(commandArray, inputStruct);
			break;
	}
}

/**
 * @fn void OutputDebug(char[], size_t, UART_HandleTypeDef*)
 * @brief simple debugging func
 *
 * @param message
 * @param messageLength
 * @param uartHandle
 */
Error OutputDebug(char message[], size_t messageLength,
				 UART_HandleTypeDef *uartHandle) {
	HAL_UART_Transmit(uartHandle, message, messageLength, 10);
}
