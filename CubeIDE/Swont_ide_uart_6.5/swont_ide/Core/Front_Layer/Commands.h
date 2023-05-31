/*
 * Commands.h
 *
 *  Created on: 17 May 2023
 *      Author: r_middelman, yopocho
 */

#ifndef FRONT_LAYER_COMMANDS_H_
#define FRONT_LAYER_COMMANDS_H_

#include "main.h"

// size of the circulair buffer (which is also the max amount for the herhaal
// command)
#define CMD_BUFF_SIZE 128
#define MAX_CMD_ARGS 12

typedef struct CmdStruct {
	int commandNummer;
	uint16_t argBuf[12];
	char textSentence[1024];
} CmdStruct;

typedef uint16_t command[12];

void RecieveCommandLijn(CmdStruct CmdBuf, input_vars inputStruct);
void RecieveCommandClear(CmdStruct CmdBuf, input_vars inputStruct);
void RecieveCommandRechthoek(CmdStruct CmdBuf, input_vars inputStruct);
void RecieveCommandTekst(CmdStruct CmdBuf, input_vars inputStruct);
void RecieveCommandBitmap(CmdStruct CmdBuf, input_vars inputStruct);
void RecieveCommandWacht(CmdStruct CmdBuf, input_vars inputStruct);
void RecieveCommandHerhaal(CmdStruct CmdBuf, input_vars inputStruct);
void RecieveCommandFiguur(CmdStruct CmdBuf, input_vars inputStruct);
void RecieveCommandCirkel(CmdStruct CmdBuf, input_vars inputStruct);

#endif /* FRONT_LAYER_COMMANDS_H_ */
