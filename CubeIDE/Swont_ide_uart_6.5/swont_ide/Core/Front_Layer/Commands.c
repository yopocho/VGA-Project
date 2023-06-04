/*
 * Commands.c
 *
 *  Created on: 17 May 2023
 *      Author: r_middelman, yopocho
 */

#include "Commands.h"
#include "errorHandling.h"
//#include "Parser.h"

CmdStruct CmdBuf[CMD_BUFF_SIZE];
CmdStruct *pCmdBuf = &CmdBuf[0];
uint32_t CmdBufLen = 0;

/**
 * @fn Error CircBufPush(CmdStruct*)
 * @brief Pushes given CmdStruct to circular buffer, incrementing pCmdBuf with each addition.
 * When pCmdBuf has reached the end of CmdBuf, loop back to the beginning to be circular.
 *
 * @param CmdBuf
 * @return Error
 */
Error CircBufPush(CmdStruct *CmdBuf) {
	pCmdBuf->commandNummer = CmdBuf->commandNummer;
	memcpy(pCmdBuf->argBuf, CmdBuf->argBuf, sizeof(CmdBuf->argBuf[0]) * MAX_CMD_ARGS);
	memcpy(pCmdBuf->textSentence, CmdBuf->textSentence, sizeof(CmdBuf->textSentence[0]) * MAX_CMD_CHARS);

	//Check if the buffer pointer has reached the end and if so, loop back to start
	if(pCmdBuf == &CmdBuf[CMD_BUFF_SIZE - 1]) {
		pCmdBuf = &CmdBuf[0];
		return ERR_NONE;
	}
	if(CmdBufLen != CMD_BUFF_SIZE - 1) {
		++CmdBufLen;
	}
	++pCmdBuf;
	return ERR_NONE;
}

/**
 * @fn CmdStruct CircBufPop(void)
 * @brief Pops head of CmdBuf
 *
 * @return CmdStruct
 */
CmdStruct CircBufPop(void) {
	--pCmdBuf;
	--CmdBufLen;
	return *pCmdBuf;
}



/**
 * @fn void RecieveCommandLijn(command, input_vars)
 * @brief when line command is recieved adds the necessary args and adds them to
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
			ParseOnKomma(inputStruct, neededArg, 0, 1, 0, 0, 0, *CmdBuf);
		} else {
			ParseOnKomma(inputStruct, neededArg, 1, 0, 0,0,0,  *CmdBuf);
		}
	}
	return ERR_NONE;
}

/**
 * @fn void RecieveCommandClear(command, input_vars)
 * @brief
 *
 * @param commandArray
 * @param inputStruct
 */
Error RecieveCommandClear(CmdStruct *CmdBuf, input_vars inputStruct) {
	ParseOnKomma(inputStruct, 1, 0, 1, 0, 0, 0,  *CmdBuf);
	return ERR_NONE;
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
			ParseOnKomma(inputStruct, neededArg, 0, 1, 0, 0, 0, *CmdBuf);
		} else {
			ParseOnKomma(inputStruct, neededArg, 1, 0, 0, 0, 0, *CmdBuf);
		}
	}
	return ERR_NONE;
}

//TODO: Integrate command tekst into parser
Error RecieveCommandTekst(CmdStruct *CmdBuf, input_vars inputStruct) {
	return ERR_NONE;
}

Error RecieveCommandBitmap(CmdStruct *CmdBuf, input_vars inputStruct) {
	uint8_t neededArg = 0;
	for (uint8_t i = 0; i < 3; i++) {
		neededArg = i + 1;
		ParseOnKomma(inputStruct, neededArg, 1, 0, 0, 0, 0, *CmdBuf);
	}
	return ERR_NONE;
}

/**
 * @fn Error RecieveCommandWacht(CmdStruct*, input_vars)
 * @brief
 *
 * @param CmdBuf
 * @param inputStruct
 * @return
 */
Error RecieveCommandWacht(CmdStruct *CmdBuf, input_vars inputStruct) {
	ParseOnKomma(inputStruct, 1, 1, 0, 0, 0, 0,  *CmdBuf);
	return ERR_NONE;
}

//TODO: Integrate command Herhaal into parser
/**
 * @fn void RecieveCommandHerhaal(command, input_vars)
 * @brief
 *
 * @param commandArray
 * @param inputStruct
 */
Error RecieveCommandHerhaal(CmdStruct *CmdBuf, input_vars inputStruct) {
	uint8_t neededArg = 0;
	for (uint8_t i = 0; i < 3; i++) {
		neededArg = i + 1;
		ParseOnKomma(inputStruct, neededArg, 1, 0, 0, 0, 0, 0, CmdBuf);
	}
	return ERR_NONE;
}

Error RecieveCommandFiguur(CmdStruct *CmdBuf, input_vars inputStruct) {
	uint8_t neededArg = 0;
	for (uint8_t i = 0; i < 12; i++) {
		neededArg = i + 1;
		if(i == 10) {
			ParseOnKomma(inputStruct, neededArg, 0, 1, 0, 0, 0, *CmdBuf);
		}
		else {
			ParseOnKomma(inputStruct, neededArg, 1, 0, 0, 0, 0, *CmdBuf);
		}
	}
	return ERR_NONE;
}

Error RecieveCommandCirkel(CmdStruct *CmdBuf, input_vars inputStruct) {
	uint8_t neededArg = 0;
	for (uint8_t i = 0; i < 5; i++) {
		neededArg = i + 1;
		if(i == 3) {
			ParseOnKomma(inputStruct, neededArg, 0, 1, 0, 0, 0, *CmdBuf);
		}
		else {
			ParseOnKomma(inputStruct, neededArg, 1, 0, 0, 0, 0, *CmdBuf);
		}
	}
	return ERR_NONE;
}

Error callCommand(CmdStruct *arg_struct){
	Error err;
	switch (arg_struct->commandNummer) {
		case LIJN:
			err = DrawLine(	arg_struct->argBuf[1], arg_struct->argBuf[2],
						arg_struct->argBuf[3], arg_struct->argBuf[4],
						arg_struct->argBuf[5], arg_struct->argBuf[6]);
			break;
		case CLEARSCHERM:
			err = ClearScreen(arg_struct->argBuf[1]);
			break;
		case RECHTHOEK:
			err = DrawRectangle(arg_struct->argBuf[1], arg_struct->argBuf[2],
			arg_struct->argBuf[3], arg_struct->argBuf[4],
			arg_struct->argBuf[5], arg_struct->argBuf[6]);
			break;
		case WACHT:
			err = Wait(arg_struct->argBuf[1]);
			break;
		case BITMAP:
			err = DrawBitmapFromSDCard(arg_struct->argBuf[2], arg_struct->argBuf[3], arg_struct->argBuf[1]);
			break;
		case CIRKEL:
			err = DrawCircle(arg_struct->argBuf[1], arg_struct->argBuf[2], arg_struct->argBuf[3], arg_struct->argBuf[4]);
			break;
		case FIGUUR:
			err = DrawFigure(	arg_struct->argBuf[1], arg_struct->argBuf[2],
						arg_struct->argBuf[3], arg_struct->argBuf[4],
						arg_struct->argBuf[5], arg_struct->argBuf[6],
						arg_struct->argBuf[7], arg_struct->argBuf[8],
						arg_struct->argBuf[9], arg_struct->argBuf[10],
						arg_struct->argBuf[11]);
			break;
		case HERHAAL:
			err = RepeatCommands(2, 1);
//			err = RepeatCommands(arg_struct->argBuf[1], arg_struct->argBuf[2]);
			break;
		default:
			return ERR_UNKNOWN_ERR;
	}
	if(err != ERR_NONE) {
		return err;
	}
	return ERR_NONE;
}
