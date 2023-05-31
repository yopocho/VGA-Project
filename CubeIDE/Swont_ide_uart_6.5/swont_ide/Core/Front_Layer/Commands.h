/*
 * Commands.h
 *
 *  Created on: 17 May 2023
 *      Author: r_middelman, yopocho
 */

#ifndef FRONT_LAYER_COMMANDS_H_
#define FRONT_LAYER_COMMANDS_H_

#include "errorHandling.h"
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

Error RecieveCommandLijn(CmdStruct *CmdBuf, input_vars inputStruct);
Error RecieveCommandClear(CmdStruct *CmdBuf, input_vars inputStruct);
Error RecieveCommandRechthoek(CmdStruct *CmdBuf, input_vars inputStruct);
Error RecieveCommandTekst(CmdStruct *CmdBuf, input_vars inputStruct);
Error RecieveCommandBitmap(CmdStruct *CmdBuf, input_vars inputStruct);
Error RecieveCommandWacht(CmdStruct *CmdBuf, input_vars inputStruct);
Error RecieveCommandHerhaal(CmdStruct *CmdBuf, input_vars inputStruct);
Error RecieveCommandFiguur(CmdStruct *CmdBuf, input_vars inputStruct);
Error RecieveCommandCirkel(CmdStruct *CmdBuf, input_vars inputStruct);

#endif /* FRONT_LAYER_COMMANDS_H_ */
