/*
 * Parser.h
 *
 *  Created on: 10 May 2023
 *      Author: r_middelman
 */

#ifndef FRONT_LAYER_PARSER_H_
#define FRONT_LAYER_PARSER_H_

#include "Commands.h"
#include "main.h"
#include "usart.h"

// #define FRONT_LAYER_DEBUG
#define AMOUNT_OF_COMMANDS 9
#define AMOUNT_OF_COLORS 16

char debugMessageParse[] = "Found comma in message\n";
char debugMessageCommand[] = "Matched command with number\n";
char debugMessageColor[] = "found color\n";

char *possibleCommands[] = {"lijn",	  "clearscherm", "rechthoek",
							"wacht",  "tekst",		 "bitmap",
							"cirkel", "figuur",		 "herhaal"};

char *possibleColors[] = {"zwart",		"blauw",   "lichtblauw",	"groen",
						  "lichtgroen", "cyaan",   "lichtcyaan",	"rood",
						  "lichtrood",	"magenta", " lichtmagenta", "bruin",
						  "geel",		"grijs",   "wit",			"roze"};

uint8_t colorCodes[] = {
	VGA_COL_BLACK,		VGA_COL_BLUE,	 VGA_COL_LIGHTBLUE,	   VGA_COL_GREEN,
	VGA_COL_LIGHTGREEN, VGA_COL_CYAN,	 VGA_COL_LIGHTCYAN,	   VGA_COL_RED,
	VGA_COL_LIGHTRED,	VGA_COL_MAGENTA, VGA_COL_LIGHTMAGENTA, VGA_COL_BROWN,
	VGA_COL_YELLOW,		VGA_COL_GRAY,	 VGA_COL_WHITE,		   VGA_COL_PINK};

Error ParseOnKomma(input_vars inputStruct, uint8_t neededArgument,
				  uint8_t convertToNumber, int convertColor,
				  command commandArray);
Error CheckWhatCommand(char incommingCommand[], command commandArray,
					  input_vars inputStruct);
Error CheckWhatColor(char incommingColor[], command commandArray,
					uint8_t argPlace);
Error DoOnCommand(command commandArray, input_vars inputStruct);
Error OutputDebug(char message[], size_t messageLength,
				 UART_HandleTypeDef *uartHandle);

#endif /* FRONT_LAYER_PARSER_H_ */
