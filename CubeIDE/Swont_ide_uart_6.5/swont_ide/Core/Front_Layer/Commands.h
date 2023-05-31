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

Error RecieveCommandLijn(command commandArray, input_vars inputStruct);
Error RecieveCommandClear(command commandArray, input_vars inputStruct);
Error RecieveCommandRechthoek(command commandArray, input_vars inputStruct);
Error RecieveCommandTekst(command commandArray, input_vars inputStruct);
Error RecieveCommandBitmap(command commandArray, input_vars inputStruct);
Error RecieveCommandWacht(command commandArray, input_vars inputStruct);
Error RecieveCommandHerhaal(command commandArray, input_vars inputStruct);
Error RecieveCommandFiguur(command commandArray, input_vars inputStruct);
Error RecieveCommandCirkel(command commandArray, input_vars inputStruct);

#endif /* FRONT_LAYER_COMMANDS_H_ */
