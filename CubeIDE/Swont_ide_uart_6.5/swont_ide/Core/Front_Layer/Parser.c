/*
 * Parser.c
 *
 *  Created on: 10 May 2023
 *      Author: r_middelman
 */

#include "Parser.h"

const char *possibleCommands[] = {"lijn",	"clearscherm", "rechthoek",
								  "wacht",	"tekst",	   "bitmap",
								  "cirkel", "figuur",	   "herhaal, help"};

const char *possibleColors[] = {
	"zwart",	  "blauw", "lichtblauw", "groen",	"lichtgroen",	 "cyaan",
	"lichtcyaan", "rood",  "lichtrood",	 "magenta", " lichtmagenta", "bruin",
	"geel",		  "grijs", "wit",		 "roze"};

const uint8_t colorCodes[] = {
	VGA_COL_BLACK,		VGA_COL_BLUE,	 VGA_COL_LIGHTBLUE,	   VGA_COL_GREEN,
	VGA_COL_LIGHTGREEN, VGA_COL_CYAN,	 VGA_COL_LIGHTCYAN,	   VGA_COL_RED,
	VGA_COL_LIGHTRED,	VGA_COL_MAGENTA, VGA_COL_LIGHTMAGENTA, VGA_COL_BROWN,
	VGA_COL_YELLOW,		VGA_COL_GRAY,	 VGA_COL_WHITE,		   VGA_COL_PINK};

/**
 * @fn Error ParseOnKomma(input_vars inputStruct, uint8_t neededArgument,
 * uint8_t convertToNumber, int convertColor, uint8_t getText, uint8_t getFont,
 * uint8_t getStyle, CmdStruct* CmdBuf)
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

	// Early error checks
	if (inputStruct.msglen == 0) {	// Only LF
		return ERR_INVALID_CMD;
	}
	if (strchr(inputStruct.line_rx_buffer, ',') ==
		NULL) {	 // No commas found, invalid
		return ERR_INVALID_CMD;
	}

	// Parse incoming message on comma
	char incommingMessage[inputStruct.msglen];
	memset(incommingMessage, 0, sizeof(incommingMessage));
	// loop through incomming characters
	for (int j = 0; j <= inputStruct.msglen; j++) {
		if (inputStruct.line_rx_buffer[j] == '-') return ERR_INVALID_ARG;
		// check for commas, 0 & spaces to delete them of seperate message
		if (inputStruct.line_rx_buffer[j] != 0 &&
			inputStruct.line_rx_buffer[j] != ',') {
			// if its for the text command don't delete the spaces
			if (getText) {
				incommingMessage[placeInBuf] = inputStruct.line_rx_buffer[j];
				placeInBuf++;
			} else if (inputStruct.line_rx_buffer[j] != ' ') {
				incommingMessage[placeInBuf] = inputStruct.line_rx_buffer[j];
				placeInBuf++;
			}
		}
		// if its the final letter check incomming message
		if (j == inputStruct.msglen) {
			incommingMessage[placeInBuf] = inputStruct.line_rx_buffer[j];
			placeInBuf++;
			if (commaCounter == neededArgument) {
				if (convertColor) {
					err = CheckWhatColor(incommingMessage, CmdBuf,
										 neededArgument);
					if (err != ERR_NONE) {
						return err;
					}
				}
				if (convertToNumber) {
					CmdBuf->argBuf[neededArgument] = atoi(incommingMessage);
					if (commaCounter != 6) {
						if (atoi(incommingMessage) <= 0) {
							return ERR_INVALID_ARG;
						}
					}
				}
				if (getText) strcpy(CmdBuf->textSentence, incommingMessage);
				if (getStyle) {
					if (strcmp(incommingMessage, "normaal") != 0 &&
						strcmp(incommingMessage, "vet") != 0 &&
						strcmp(incommingMessage, "cursief") != 0) {
						return ERR_INVALID_ARG;
					} else
						strcpy(CmdBuf->textStyle, incommingMessage);
				}
				if (getFont) {
					if (strcmp(incommingMessage, "consolas") != 0 &&
						strcmp(incommingMessage, "arial") != 0) {
						return ERR_INVALID_ARG;
					} else
						strcpy(CmdBuf->textFont, incommingMessage);
				}
			}
			break;
		}
		// actual comma parse (check for comma)
		if (inputStruct.line_rx_buffer[j] == ',') {
			incommingMessage[j] = 0;
			placeInBuf = 0;
			if (commaCounter == neededArgument) {
				// if comma counter is 0 then we need the command
				if (!commaCounter) {
					err =
						CheckWhatCommand(incommingMessage, CmdBuf, inputStruct);
					if (err != ERR_NONE) {
						return err;
					}
				}
				if (convertColor) {
					err = CheckWhatColor(incommingMessage, CmdBuf,
										 neededArgument);
					if (err != ERR_NONE) {
						return err;
					}
				}

				if (convertToNumber)
					CmdBuf->argBuf[neededArgument] = atoi(incommingMessage);
				if (getText) strcpy(CmdBuf->textSentence, incommingMessage);
				if (getStyle) {
					if (strcmp(incommingMessage, "normaal") != 0 &&
						strcmp(incommingMessage, "vet") != 0 &&
						strcmp(incommingMessage, "cursief") != 0) {
						return ERR_INVALID_ARG;
					} else
						strcpy(CmdBuf->textStyle, incommingMessage);
				}
				if (getFont) {
					if (strcmp(incommingMessage, "consolas") != 0 &&
						strcmp(incommingMessage, "arial") != 0) {
						return ERR_INVALID_ARG;
					} else
						strcpy(CmdBuf->textFont, incommingMessage);
				}
				break;
			}
			commaCounter++;
			// set the array to 0 again to fill with the argument
			memset(incommingMessage, 0, sizeof(incommingMessage));
		}
	}
	return ERR_NONE;
}

/**
 * @fn Error CheckWhatCommand(char[], CmdStruct*, input_vars)
 * @brief checks what command is being called,
 * compares the incomming string with a list of strings
 *
 * @param incommingCommand
 * @param CmdBuf
 * @param inputStruct
 * @return Error
 */
Error CheckWhatCommand(char incommingCommand[], CmdStruct *CmdBuf,
					   input_vars inputStruct) {
	for (uint8_t i = 0; i < AMOUNT_OF_COMMANDS; i++) {
		if (strcmp(incommingCommand, possibleCommands[i]) == 0) {
			CmdBuf->commandNummer = i;
			Error err = DoOnCommand(CmdBuf, inputStruct);
			if (err != ERR_NONE) {
				return err;
			}

			return ERR_NONE;
		}
	}
	return ERR_INVALID_CMD;
}
/**
 * @fn Error CheckWhatColor(char[], CmdStruct*, uint8_t)
 * @brief checks what color is being called and asignes a numerical value in an
 * array
 *
 * @param incommingColor
 * @param CmdBuf
 * @param argPlace
 * @return Error
 */
Error CheckWhatColor(char incommingColor[], CmdStruct *CmdBuf,
					 uint8_t argPlace) {
	for (uint8_t i = 0; i < AMOUNT_OF_COLORS; i++) {
		if (strcmp(incommingColor, possibleColors[i]) == 0) {
			CmdBuf->argBuf[argPlace] = colorCodes[i];
			return ERR_NONE;
		}
	}
	return ERR_UNKNOWN_COL;
}
/**
 * @fn Error DoOnCommand(CmdStruct*, input_vars)
 * @brief checks which command is given and takes futher actions to add the rest
 * of the args
 *
 * @param CmdBuf
 * @param inputStruct
 * @return Error
 */
Error DoOnCommand(CmdStruct *CmdBuf, input_vars inputStruct) {
	Error err;
	switch (CmdBuf->commandNummer) {
		case 0:
			// lijn
			err = RecieveCommandLijn(CmdBuf, inputStruct);
			break;
		case 1:
			// clearscherm
			err = RecieveCommandClear(CmdBuf, inputStruct);
			break;
		case 2:
			// rechthoek
			err = RecieveCommandRechthoek(CmdBuf, inputStruct);
			break;
		case 3:
			// wacht
			err = RecieveCommandWacht(CmdBuf, inputStruct);
			break;
		case 4:
			// tekst
			err = RecieveCommandTekst(CmdBuf, inputStruct);
			break;
		case 5:
			// bitmap
			err = RecieveCommandBitmap(CmdBuf, inputStruct);
			break;
		case 6:
			// cirkel
			err = RecieveCommandCirkel(CmdBuf, inputStruct);
			break;
		case 7:
			// figuur
			err = RecieveCommandFiguur(CmdBuf, inputStruct);
			break;
		case 8:
			// herhaal
			err = RecieveCommandHerhaal(CmdBuf, inputStruct);
			break;
		default:
			return ERR_INVALID_CMD;
			break;
	}
	return err;
}
