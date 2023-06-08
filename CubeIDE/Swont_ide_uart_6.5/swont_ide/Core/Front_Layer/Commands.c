/*
 * Commands.c
 *
 *  Created on: 17 May 2023
 *      Author: r_middelman, yopocho
 */

#include "Commands.h"

#include "Parser.h"
#include "drawshapes.h"
#include "drawtext.h"
#include "errorHandling.h"
#include "sdcard.h"

CircularBuffer circBuf;
CircularBuffer *pCircBuf;
Error err;

const char *helpMessage =
	" - lijn, x, y, x', y', kleur, dikte\r\n - rechthoek, x_lup, y_lup, breedte, "
	"hoogte, kleur, gevuld (1,0) [als 1: rand (1px) met kleur]\r\n - tekst, x, y, "
	"kleur, tekst, fontnaam (arial, consolas), fontgrootte (1,2), fontstijl "
	"(normaal, vet, cursief)\r\n - bitmap, nr, x-lup, y-lup  [tenminste: pijl (in 4 "
	"richtingen), smiley (boos, blij)]\r\n - clearscherm, kleur\r\n - wacht, msecs\r\n - herhaal, "
	"aantal (laatst uitgevoerde commandos), hoevaak (herhalen) \r\n - cirkel, x, "
	"y, radius, kleur\r\n - figuur, x1,y1, x2,y2, x3,y3, x4,y4, x5,y5, kleur\r\n Ask the "
	"authors for the user manual if you want to use the application\r\n"
		"X max = 320, Y max = 240 \r\n";

// Error DrawBitmapFromSDCard(uint16_t xp, uint16_t yp, bitmapKey selector);

/**
 * @fn void CircBufInit(void)
 * @brief Initializes the circular buffer for the "Herhaal"-command
 *
 */
void CircBufInit(void) {
	pCircBuf = &circBuf;
	memset(pCircBuf->CmdBuf, 0, sizeof(pCircBuf->CmdBuf[0]));
	pCircBuf->pHead = &pCircBuf->CmdBuf[0];
	pCircBuf->pRepeat = &pCircBuf->CmdBuf[0];
	pCircBuf->CmdBufLen = 0;
}

/**
 * @fn Error CircBufPush(CmdStruct*)
 * @brief Pushes given CmdStruct to circular buffer, incrementing pCmdBuf with
 * each addition. When pCmdBuf has reached the end of CmdBuf, loop back to the
 * beginning to be circular.
 *
 * @param CmdBuf
 * @return Error
 */
Error CircBufPush(CmdStruct *CmdBuf) {
#ifdef DEBUG
	printf("%lu\r\n", (uint32_t)pCircBuf->pHead);
#endif
	pCircBuf->pHead->commandNummer = CmdBuf->commandNummer;
	memcpy(pCircBuf->pHead->argBuf, CmdBuf->argBuf,
		   sizeof(CmdBuf->argBuf[0]) * MAX_CMD_ARGS);
	strcpy(pCircBuf->pHead->textSentence, CmdBuf->textSentence);
	strcpy(pCircBuf->pHead->textFont, CmdBuf->textFont);
	strcpy(pCircBuf->pHead->textStyle, CmdBuf->textStyle);
#ifdef DEBUG
	printf("Pushed %d\n\r", CmdBuf->commandNummer);
	printf("Pushed %d\n\r", pCircBuf->pHead->commandNummer);
#endif
	// Check if the buffer pointer has reached the end and if so, loop back to
	// start
	if (pCircBuf->pHead == &pCircBuf->CmdBuf[CMD_BUFF_SIZE - 1]) {
		pCircBuf->pHead = &pCircBuf->CmdBuf[0];
#ifdef DEBUG
		printf("At buffers end w/ pushing, looping back around!\r\n");
#endif
		return ERR_NONE;
	}
	if (pCircBuf->CmdBufLen != CMD_BUFF_SIZE - 1) {
		++pCircBuf->CmdBufLen;
	}
	++pCircBuf->pHead;
	return ERR_NONE;
}

/**
 * @fn CmdStruct CircBufPop(void)
 * @brief Pops head of CmdBuf
 *
 * @return CmdStruct
 */
CmdStruct *CircBufPop(void) {
	if (pCircBuf->pRepeat == &pCircBuf->CmdBuf[CMD_BUFF_SIZE - 1]) {
		pCircBuf->pRepeat = &pCircBuf->CmdBuf[0];
#ifdef DEBUG
		printf("At buffers end w/ pushing, looping back around!\r\n");
#endif
	}

	return pCircBuf->pRepeat++;
}

/**
 * @fn Error RecieveCommandLijn(CmdStruct*, input_vars)
 * @brief when line command is recieved adds the necessary args and adds them to
 * the buffer
 *
 * @param CmdBuf
 * @param inputStruct
 * @return Error
 */
Error RecieveCommandLijn(CmdStruct *CmdBuf, input_vars inputStruct) {
	uint8_t neededArg = 0;
	for (uint8_t i = 0; i < 7; i++) {
		neededArg = i + 1;
		if (i == 4) {
			err = ParseOnKomma(inputStruct, neededArg, 0, 1, 0, 0, 0, CmdBuf);
			if (err != ERR_NONE) {
				return err;
			}
		} else {
			err = ParseOnKomma(inputStruct, neededArg, 1, 0, 0, 0, 0, CmdBuf);
			if (err != ERR_NONE) {
				return err;
			}
		}
	}
	return ERR_NONE;
}

/**
 * @fn Error RecieveCommandClear(CmdStruct*, input_vars)
 * @brief
 *
 * @param CmdBuf
 * @param inputStruct
 * @return Error
 */
Error RecieveCommandClear(CmdStruct *CmdBuf, input_vars inputStruct) {
	err = ParseOnKomma(inputStruct, 1, 0, 1, 0, 0, 0, CmdBuf);
	if (err != ERR_NONE) {
		return err;
	}
	return ERR_NONE;
}

/**
 * @fn Error RecieveCommandRechthoek(CmdStruct*, input_vars)
 * @brief
 *
 * @param CmdBuf
 * @param inputStruct
 * @return Error
 */
Error RecieveCommandRechthoek(CmdStruct *CmdBuf, input_vars inputStruct) {
	uint8_t neededArg = 0;
	for (uint8_t i = 0; i < 7; i++) {
		neededArg = i + 1;
		if (i == 4) {
			err = ParseOnKomma(inputStruct, neededArg, 0, 1, 0, 0, 0, CmdBuf);
			if (err != ERR_NONE) {
				return err;
			}
		} else {
			err = ParseOnKomma(inputStruct, neededArg, 1, 0, 0, 0, 0, CmdBuf);
			if (err != ERR_NONE) {
				return err;
			}
		}
	}
	return ERR_NONE;
}

/**
 * @fn Error RecieveCommandTekst(CmdStruct*, input_vars)
 * @brief
 *
 * @param CmdBuf
 * @param inputStruct
 * @return Error
 */
Error RecieveCommandTekst(CmdStruct *CmdBuf, input_vars inputStruct) {
	uint8_t neededArg = 0;
	for (uint8_t i = 0; i < 7; i++) {
		neededArg = i + 1;
		if (i == 2) {
			err = ParseOnKomma(inputStruct, neededArg, 0, 1, 0, 0, 0, CmdBuf);
			if (err != ERR_NONE) {
				return err;
			}
		} else if (i == 3) {
			ParseOnKomma(inputStruct, neededArg, 0, 0, 1, 0, 0, CmdBuf);
		} else if (i == 4) {
			err = ParseOnKomma(inputStruct, neededArg, 0, 0, 0, 1, 0, CmdBuf);
			if (err != ERR_NONE) {
				return err;
			}
		} else if (i == 6) {
			err = ParseOnKomma(inputStruct, neededArg, 0, 0, 0, 0, 1, CmdBuf);
			if (err != ERR_NONE) {
				return err;
			}
		} else {
			err = ParseOnKomma(inputStruct, neededArg, 1, 0, 0, 0, 0, CmdBuf);
			if (err != ERR_NONE) {
				return err;
			}
		}
	}
	return ERR_NONE;
}

/**
 * @fn Error RecieveCommandBitmap(CmdStruct*, input_vars)
 * @brief
 *
 * @param CmdBuf
 * @param inputStruct
 * @return Error
 */
Error RecieveCommandBitmap(CmdStruct *CmdBuf, input_vars inputStruct) {
	uint8_t neededArg = 0;
	for (uint8_t i = 0; i < 3; i++) {
		neededArg = i + 1;
		err = ParseOnKomma(inputStruct, neededArg, 1, 0, 0, 0, 0, CmdBuf);
		if (err != ERR_NONE) {
			return err;
		}
	}
	return ERR_NONE;
}

/**
 * @fn Error RecieveCommandWacht(CmdStruct*, input_vars)
 * @brief
 *
 * @param CmdBuf
 * @param inputStruct
 * @return Error
 */
Error RecieveCommandWacht(CmdStruct *CmdBuf, input_vars inputStruct) {
	err = ParseOnKomma(inputStruct, 1, 1, 0, 0, 0, 0, CmdBuf);
	if (err != ERR_NONE) {
		return err;
	}
	return ERR_NONE;
}

/**
 * @fn Error RecieveCommandHerhaal(CmdStruct*, input_vars)
 * @brief
 *
 * @param CmdBuf
 * @param inputStruct
 * @return Error
 */
Error RecieveCommandHerhaal(CmdStruct *CmdBuf, input_vars inputStruct) {
	uint8_t neededArg = 0;
	for (uint8_t i = 0; i < 2; i++) {
		neededArg = i + 1;
		err = ParseOnKomma(inputStruct, neededArg, 1, 0, 0, 0, 0, CmdBuf);
		if (err != ERR_NONE) {
			return err;
		}
	}
	return ERR_NONE;
}

/**
 * @fn Error RecieveCommandFiguur(CmdStruct*, input_vars)
 * @brief
 *
 * @param CmdBuf
 * @param inputStruct
 * @return Error
 */
Error RecieveCommandFiguur(CmdStruct *CmdBuf, input_vars inputStruct) {
	uint8_t neededArg = 0;
	for (uint8_t i = 0; i < 12; i++) {
		neededArg = i + 1;
		if (i == 10) {
			err = ParseOnKomma(inputStruct, neededArg, 0, 1, 0, 0, 0, CmdBuf);
			if (err != ERR_NONE) {
				return err;
			}
		} else {
			err = ParseOnKomma(inputStruct, neededArg, 1, 0, 0, 0, 0, CmdBuf);
			if (err != ERR_NONE) {
				return err;
			}
		}
	}
	return ERR_NONE;
}

/**
 * @fn Error RecieveCommandCirkel(CmdStruct*, input_vars)
 * @brief
 *
 * @param CmdBuf
 * @param inputStruct
 * @return Error
 */
Error RecieveCommandCirkel(CmdStruct *CmdBuf, input_vars inputStruct) {
	uint8_t neededArg = 0;
	for (uint8_t i = 0; i < 5; i++) {
		neededArg = i + 1;
		if (i == 3) {
			err = ParseOnKomma(inputStruct, neededArg, 0, 1, 0, 0, 0, CmdBuf);
			if (err != ERR_NONE) {
				return err;
			}
		} else {
			err = ParseOnKomma(inputStruct, neededArg, 1, 0, 0, 0, 0, CmdBuf);
			if (err != ERR_NONE) {
				return err;
			}
		}
	}
	return ERR_NONE;
}

/**
 * @fn Error RecieveCommandHelp(CmdStruct*, input_vars)
 * @brief help function
 *
 * @param CmdBuf
 * @param inputStruct
 * @return returns no error
 */
Error RecieveCommandHelp(CmdStruct *CmdBuf, input_vars inputStruct) {
	return ERR_NONE;
}

/**
 * @fn Error callCommand(CmdStruct*)
 * @brief
 *
 * @param arg_struct
 * @return Error
 */
Error callCommand(CmdStruct *arg_struct) {
	Error err;
	switch (arg_struct->commandNummer) {
		case LIJN:
			err = DrawLine(arg_struct->argBuf[1], arg_struct->argBuf[2],
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
			err = DrawBitmapFromSDCard(arg_struct->argBuf[2],
									   arg_struct->argBuf[3],
									   arg_struct->argBuf[1]);
			break;
		case CIRKEL:
			err = DrawCircle(arg_struct->argBuf[1], arg_struct->argBuf[2],
							 arg_struct->argBuf[3], arg_struct->argBuf[4]);
			break;
		case FIGUUR:
			err = DrawFigure(arg_struct->argBuf[1], arg_struct->argBuf[2],
							 arg_struct->argBuf[3], arg_struct->argBuf[4],
							 arg_struct->argBuf[5], arg_struct->argBuf[6],
							 arg_struct->argBuf[7], arg_struct->argBuf[8],
							 arg_struct->argBuf[9], arg_struct->argBuf[10],
							 arg_struct->argBuf[11]);
			break;
		case TEKST:
			err = DrawText(arg_struct->argBuf[1], arg_struct->argBuf[2],
						   arg_struct->argBuf[3], arg_struct->textSentence,
						   arg_struct->textFont, arg_struct->argBuf[6],
						   arg_struct->textStyle);
			break;
		case HERHAAL:
			err = RepeatCommands(arg_struct->argBuf[1], arg_struct->argBuf[2]);
			break;
		case HELP:
			printf("%s", helpMessage);
			err = ERR_NONE;
			break;

		default:
			return ERR_UNKNOWN_ERR;
	}
	if (err != ERR_NONE) {
		return err;
	}
	return ERR_NONE;
}
