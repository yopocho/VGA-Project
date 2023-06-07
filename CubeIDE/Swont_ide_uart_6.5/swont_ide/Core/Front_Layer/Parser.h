/*
 * Parser.h
 *
 *  Created on: 10 May 2023
 *      Author: r_middelman
 */

#ifndef FRONT_LAYER_PARSER_H_
#define FRONT_LAYER_PARSER_H_

#include "Commands.h"
#include "errorHandling.h"
#include "main.h"
#include "usart.h"

#define AMOUNT_OF_COMMANDS 9
#define AMOUNT_OF_COLORS 16

extern const char *possibleCommands[];

extern const char *possibleColors[];

extern const uint8_t colorCodes[];

extern Error ParseOnKomma(input_vars inputStruct, uint8_t neededArgument,
		   uint8_t convertToNumber, int convertColor, uint8_t getText,
		   uint8_t getFont, uint8_t getStyle, CmdStruct *CmdBuf);
extern Error CheckWhatCommand(char incommingCommand[], CmdStruct *CmdBuf,
			   input_vars inputStruct);
extern Error CheckWhatColor(char incommingColor[], CmdStruct *CmdBuf,
			 uint8_t argPlace);
extern Error DoOnCommand(CmdStruct *CmdBuf, input_vars inputStruct);

#endif /* FRONT_LAYER_PARSER_H_ */
