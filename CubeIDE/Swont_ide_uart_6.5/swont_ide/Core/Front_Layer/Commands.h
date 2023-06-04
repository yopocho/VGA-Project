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
#define CMD_BUFF_SIZE 3
#define MAX_CMD_ARGS 12
#define MAX_CMD_CHARS 128

typedef enum {
	LIJN,
	CLEARSCHERM,
	RECHTHOEK,
	WACHT,
	TEKST,
	BITMAP,
	CIRKEL,
	FIGUUR,
	HERHAAL
} Command;

typedef struct CmdStruct {
	int commandNummer;
	uint16_t argBuf[MAX_CMD_ARGS];
	char textSentence[MAX_CMD_CHARS];
	char textFont[30];
	char textStyle[30];
} CmdStruct;

typedef struct CircularBuffer{
	CmdStruct CmdBuf[CMD_BUFF_SIZE];
	CmdStruct *pHead;
	CmdStruct *pRepeat;
	uint32_t CmdBufLen;
} CircularBuffer;

extern CircularBuffer circBuf;
extern CircularBuffer *pCircBuf;

Error RecieveCommandLijn(CmdStruct *CmdBuf, input_vars inputStruct);
Error RecieveCommandClear(CmdStruct *CmdBuf, input_vars inputStruct);
Error RecieveCommandRechthoek(CmdStruct *CmdBuf, input_vars inputStruct);
Error RecieveCommandTekst(CmdStruct *CmdBuf, input_vars inputStruct);
Error RecieveCommandBitmap(CmdStruct *CmdBuf, input_vars inputStruct);
Error RecieveCommandWacht(CmdStruct *CmdBuf, input_vars inputStruct);
Error RecieveCommandHerhaal(CmdStruct *CmdBuf, input_vars inputStruct);
Error RecieveCommandFiguur(CmdStruct *CmdBuf, input_vars inputStruct);
Error RecieveCommandCirkel(CmdStruct *CmdBuf, input_vars inputStruct);
Error CircBufPush(CmdStruct *CmdBuf);
CmdStruct* CircBufPop(void);

#endif /* FRONT_LAYER_COMMANDS_H_ */
