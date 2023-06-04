/*
 * Parser.c
 *
 *  Created on: 10 May 2023
 *      Author: r_middelman
 */

#include "Parser.h"

/**
 * @fn Error ParseOnKomma(input_vars inputStruct, uint8_t neededArgument, uint8_t convertToNumber,
 * int convertColor, uint8_t getText, uint8_t getFont, uint8_t getStyle, CmdStruct* CmdBuf)
 * @brief parser on comma function. works by looping
 * through the input and then executing calling the command that is futher
 * needed
 *
 * @param inputStruct
 * @param neededArgument
 * @param convertToNumber
 * @param convertColor
 * @param getText
 * @param getFont
 * @param getStyle
 * @param CmdBuf
 * @return Error
 */
Error ParseOnKomma(input_vars inputStruct, uint8_t neededArgument,
				   uint8_t convertToNumber, int convertColor, uint8_t getText,
				   uint8_t getFont, uint8_t getStyle, CmdStruct *CmdBuf) {
	uint8_t commaCounter = 0;
	uint8_t placeInBuf = 0;
	Error err;

	//Early error checks
	if(inputStruct.msglen == 0) { //Only LF
		return ERR_INVALID_CMD;
	}
	if(strchr(inputStruct.line_rx_buffer, ',') == NULL) { //No commas found, invalid
		return ERR_INVALID_CMD;
	}

	//Parse incoming message on comma
	char incommingMessage[inputStruct.msglen];
	for (int j = 0; j <= inputStruct.msglen; j++) {
		if (inputStruct.line_rx_buffer[j] == ',') {
			incommingMessage[j] = 0;
			placeInBuf = 0;
#ifdef FRONT_LAYER_DEBUG
			OutputDebug(debugMessageParse, sizeof(debugMessageParse), &huart2);
#endif
			if (commaCounter == neededArgument) {
				if (!commaCounter) {
					err = CheckWhatCommand(incommingMessage, CmdBuf, inputStruct);
					if (err != ERR_NONE) {
						return err;
					}
				}
				if (convertColor) {
					err = CheckWhatColor(incommingMessage, CmdBuf, neededArgument);
					if(err != ERR_NONE) {
						return err;
					}
				}

				if (convertToNumber)
					CmdBuf->argBuf[neededArgument] = atoi(incommingMessage);
				if (getText)
					strcpy(CmdBuf->textSentence, incommingMessage);
				if (getStyle)
					strcpy(CmdBuf->textStyle, incommingMessage);
				if (getFont)
					strcpy(CmdBuf->textFont , incommingMessage);
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
					CheckWhatColor(incommingMessage, CmdBuf, neededArgument);
				if (convertToNumber)
					CmdBuf->argBuf[neededArgument] = atoi(incommingMessage);
				if (getText) strcpy(CmdBuf->textSentence, incommingMessage);
								if (getStyle) strcpy(CmdBuf->textStyle, incommingMessage);
								if (getFont) strcpy(CmdBuf->textFont , incommingMessage);
			}
			break;
		}
		if (inputStruct.line_rx_buffer[j] != 0 &&
			inputStruct.line_rx_buffer[j] != ',') {
			incommingMessage[placeInBuf] = inputStruct.line_rx_buffer[j];
			placeInBuf++;
		}
	}
	return ERR_NONE;
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
Error CheckWhatCommand(char incommingCommand[], CmdStruct *CmdBuf,
					   input_vars inputStruct) {
	for (uint8_t i = 0; i < AMOUNT_OF_COMMANDS; i++) {
		if (strcmp(incommingCommand, possibleCommands[i]) == 0) {
			CmdBuf->commandNummer = i;
#ifdef FRONT_LAYER_DEBUG
			OutputDebug(debugMessageCommand, sizeof(debugMessageCommand),
						&huart2);
#endif
			Error err = DoOnCommand(CmdBuf, inputStruct);
			if(err != ERR_NONE) {
				return err;
			}
			return ERR_NONE;
		}
	}
	return ERR_INVALID_CMD;
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
Error CheckWhatColor(char incommingColor[], CmdStruct *CmdBuf,
					 uint8_t argPlace) {
	for (uint8_t i = 0; i < AMOUNT_OF_COLORS; i++) {
		if (strcmp(incommingColor, possibleColors[i]) == 0) {
			CmdBuf->argBuf[argPlace] = colorCodes[i];
#ifdef FRONT_LAYER_DEBUG
			OutputDebug(debugMessageColor, sizeof(debugMessageColor), &huart2);
#endif
			return ERR_NONE;
		}
	}
	return ERR_UNKNOWN_COL;
}
/**
 * @fn void DoOnCommand(command, input_vars)
 * @brief checks which command is given and takes futher actions to add the rest
 * of the args
 *
 * @param commandArray
 * @param inputStruct
 */
Error DoOnCommand(CmdStruct *CmdBuf, input_vars inputStruct) {
	Error err;
	switch (CmdBuf->commandNummer) {
		case 0:
			// lijn
			err = RecieveCommandLijn(&CmdBuf, inputStruct);
			break;
		case 1:
			// clearscherm
			err = RecieveCommandClear(&CmdBuf, inputStruct);
			break;
		case 2:
			// rechthoek
			err = RecieveCommandRechthoek(&CmdBuf, inputStruct);
			break;
		case 3:
			// wacht
			err = RecieveCommandWacht(&CmdBuf, inputStruct);
			break;
		case 4:
			// tekst
			err = RecieveCommandTekst(&CmdBuf, inputStruct);
			break;
		case 5:
			// bitmap
			err = RecieveCommandBitmap(&CmdBuf, inputStruct);
			break;
		case 6:
			// cirkel
			err = RecieveCommandCirkel(&CmdBuf, inputStruct);
			break;
		case 7:
			// figuur
			err = RecieveCommandFiguur(&CmdBuf, inputStruct);
			break;
		case 8:
			// herhaal
			err = RecieveCommandHerhaal(&CmdBuf, inputStruct);
			break;
	}
	return err;
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
	if(HAL_UART_Transmit(uartHandle, message, messageLength, 10) != HAL_OK) {
		return ERR_UART_FAIL;
	}
	return ERR_NONE;
}
