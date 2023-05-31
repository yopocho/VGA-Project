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

void RecieveCommandLijn(command commandArray, input_vars inputStruct);
void RecieveCommandClear(command commandArray, input_vars inputStruct);
void RecieveCommandRechthoek(command commandArray, input_vars inputStruct);
void RecieveCommandTekst(command commandArray, input_vars inputStruct);
void RecieveCommandBitmap(command commandArray, input_vars inputStruct);
void RecieveCommandWacht(command commandArray, input_vars inputStruct);
void RecieveCommandHerhaal(command commandArray, input_vars inputStruct);
void RecieveCommandFiguur(command commandArray, input_vars inputStruct);
void RecieveCommandCirkel(command commandArray, input_vars inputStruct);

#endif /* FRONT_LAYER_COMMANDS_H_ */
