/*
 * Commands.h
 *
 *  Created on: 17 May 2023
 *      Author: r_middelman, yopocho
 */

#ifndef FRONT_LAYER_COMMANDS_H_
#define FRONT_LAYER_COMMANDS_H_

#include "errorHandling.h"

// size of the circulair buffer (which is also the max amount for the herhaal
// command)
#define CMD_BUFF_SIZE 64
#define MAX_CMD_ARGS 12
#define MAX_CMD_CHARS 128

/**
 * @enum Command
 * @brief enum for all the commands
 *
 */
typedef enum {
	LIJN,		 /**< LIJN */
	CLEARSCHERM, /**< CLEARSCHERM */
	RECHTHOEK,	 /**< RECHTHOEK */
	WACHT,		 /**< WACHT */
	TEKST,		 /**< TEKST */
	BITMAP,		 /**< BITMAP */
	CIRKEL,		 /**< CIRKEL */
	FIGUUR,		 /**< FIGUUR */
	HERHAAL		 /**< HERHAAL */
} Command;

/**
 * @struct CmdStruct
 * @brief keeps all the arguments for the things
 *
 */
typedef struct CmdStruct {
	int commandNummer;
	uint16_t argBuf[MAX_CMD_ARGS];
	char textSentence[MAX_CMD_CHARS];
	char textFont[30];
	char textStyle[30];
} CmdStruct;

/**
 * @struct CircularBuffer
 * @brief circ buffer struct
 *
 */
typedef struct CircularBuffer {
	CmdStruct CmdBuf[CMD_BUFF_SIZE];
	CmdStruct *pHead;
	CmdStruct *pRepeat;
	uint32_t CmdBufLen;
} CircularBuffer;

extern CircularBuffer circBuf;
extern CircularBuffer *pCircBuf;

extern Error RecieveCommandLijn(CmdStruct *CmdBuf, input_vars inputStruct);
extern Error RecieveCommandClear(CmdStruct *CmdBuf, input_vars inputStruct);
extern Error RecieveCommandRechthoek(CmdStruct *CmdBuf, input_vars inputStruct);
extern Error RecieveCommandTekst(CmdStruct *CmdBuf, input_vars inputStruct);
extern Error RecieveCommandBitmap(CmdStruct *CmdBuf, input_vars inputStruct);
extern Error RecieveCommandWacht(CmdStruct *CmdBuf, input_vars inputStruct);
extern Error RecieveCommandHerhaal(CmdStruct *CmdBuf, input_vars inputStruct);
extern Error RecieveCommandFiguur(CmdStruct *CmdBuf, input_vars inputStruct);
extern Error RecieveCommandCirkel(CmdStruct *CmdBuf, input_vars inputStruct);
extern Error callCommand(CmdStruct *arg_struct);
void CircBufInit(void);
Error CircBufPush(CmdStruct *CmdBuf);
CmdStruct *CircBufPop(void);

#endif /* FRONT_LAYER_COMMANDS_H_ */
