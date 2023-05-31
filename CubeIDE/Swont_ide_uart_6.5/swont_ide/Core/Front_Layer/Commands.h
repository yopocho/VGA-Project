/*
 * Commands.h
 *
 *  Created on: 17 May 2023
 *      Author: r_middelman, yopocho
 */

#ifndef FRONT_LAYER_COMMANDS_H_
#define FRONT_LAYER_COMMANDS_H_

#include "main.h"
#include "errorHandling.h"

// size of the circulair buffer (which is also the max amount for the herhaalcommand)
#define CMDBUF_MAX_SIZE 64
#define MAX_CMD_ARGS 12

/**
 * @struct CmdStruct
 * @brief Datatype which holds each command and its arguments
 *
 */
typedef struct CmdStruct {
	int commandNummer;
	uint16_t argBuf[12];
	char textSentence[256];
} CmdStruct;

Error AddToBuffer(CmdStruct *command);

typedef uint16_t command[12];

Error RecieveCommandLijn(CmdStruct CmdBuf, input_vars inputStruct);
Error RecieveCommandClear(CmdStruct CmdBuf, input_vars inputStruct);
Error RecieveCommandRechthoek(CmdStruct CmdBuf, input_vars inputStruct);
Error RecieveCommandTekst(CmdStruct CmdBuf, input_vars inputStruct);
Error RecieveCommandBitmap(CmdStruct CmdBuf, input_vars inputStruct);
Error RecieveCommandWacht(CmdStruct CmdBuf, input_vars inputStruct);
Error RecieveCommandHerhaal(CmdStruct CmdBuf, input_vars inputStruct);
Error RecieveCommandFiguur(CmdStruct CmdBuf, input_vars inputStruct);
Error RecieveCommandCirkel(CmdStruct CmdBuf, input_vars inputStruct);
Error AddToBuffer(CmdStruct *command);

#endif /* FRONT_LAYER_COMMANDS_H_ */
