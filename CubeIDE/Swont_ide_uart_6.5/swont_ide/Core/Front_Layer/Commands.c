/*
 * Commands.c
 *
 *  Created on: 17 May 2023
 *      Author: r_middelman, yopocho
 */

#include "Commands.h"

CmdStruct circCmdBuf[CMDBUF_MAX_SIZE];
CmdStruct *pCircCmdBuf = &circCmdBuf[0];
uint32_t circCmdBufLen;

/**
 * @fn void RecieveCommandLijn(command, input_vars)
 * @brief when line command is recieved adds the nesisary args and adds them to
 * the buffer
 *
 * @param commandArray
 * @param inputStruct
 */
Error RecieveCommandLijn(CmdStruct *CmdBuf, input_vars inputStruct) {
	uint8_t neededArg = 0;
	for (uint8_t i = 0; i < 7; i++) {
		neededArg = i + 1;
		if (i == 4) {
			ParseOnKomma(inputStruct, neededArg, 0, 1, *CmdBuf);
		} else {
			ParseOnKomma(inputStruct, neededArg, 1, 0, *CmdBuf);
		}
	}
//	AddToBuffer(&CmdBuf);
}

/**
 * @fn void RecieveCommandClear(command, input_vars)
 * @brief
 *
 * @param commandArray
 * @param inputStruct
 */
Error RecieveCommandClear(CmdStruct *CmdBuf, input_vars inputStruct) {
	ParseOnKomma(inputStruct, 1, 0, 1, *CmdBuf);
}

/**
 * @fn void RecieveCommandRechthoek(command, input_vars)
 * @brief
 *
 * @param commandArray
 * @param inputStruct
 */
Error RecieveCommandRechthoek(CmdStruct *CmdBuf, input_vars inputStruct) {
	uint8_t neededArg = 0;
	for (uint8_t i = 0; i < 7; i++) {
		neededArg = i + 1;
		if (i == 4) {
			ParseOnKomma(inputStruct, neededArg, 0, 1, *CmdBuf);
		} else {
			ParseOnKomma(inputStruct, neededArg, 1, 0, *CmdBuf);
		}
	}
}

Error RecieveCommandTekst(CmdStruct *CmdBuf, input_vars inputStruct) {

}

Error RecieveCommandBitmap(CmdStruct *CmdBuf, input_vars inputStruct) {
	uint8_t neededArg = 0;
	for (uint8_t i = 0; i < 3; i++) {
		neededArg = i + 1;
		ParseOnKomma(inputStruct, neededArg, 1, 0, CmdBuf);
	}
}

/**
 * @fn void RecieveCommandWacht(command, input_vars)
 * @brief
 *
 * @param commandArray
 * @param inputStruct
 */
Error RecieveCommandWacht(CmdStruct *CmdBuf, input_vars inputStruct) {
	ParseOnKomma(inputStruct, 1, 1, 0, CmdBuf);
}

/**
 * @fn void RecieveCommandHerhaal(command, input_vars)
 * @brief
 *
 * @param commandArray
 * @param inputStruct
 */
Error RecieveCommandHerhaal(CmdStruct *CmdBuf, input_vars inputStruct) {
	uint8_t neededArg = 0;
	for (uint8_t i = 0; i < 2; i++) {
		neededArg = i + 1;
		ParseOnKomma(inputStruct, neededArg, 1, 0, CmdBuf);
	}
}

Error RecieveCommandFiguur(CmdStruct *CmdBuf, input_vars inputStruct) {}

Error RecieveCommandCirkel(CmdStruct *CmdBuf, input_vars inputStruct) {}
