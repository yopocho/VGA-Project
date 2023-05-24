/*
 * Commands.c
 *
 *  Created on: 17 May 2023
 *      Author: r_middelman, yopocho
 */

#include "Commands.h"

/**
 * @fn void RecieveCommandLijn(command, input_vars)
 * @brief when line command is recieved adds the nesisary args and adds them to the buffer
 *
 * @param commandArray
 * @param inputStruct
 */
void RecieveCommandLijn(command commandArray, input_vars inputStruct) {
	uint8_t neededArg = 0;
	for (uint8_t i = 0; i < 7; i++) {
		neededArg = i + 1;
		if (i == 4) {
			ParseOnKomma(inputStruct, neededArg, 0, 1, commandArray);
		} else {
			ParseOnKomma(inputStruct, neededArg, 1, 0, commandArray);
		}
	}
}

void RecieveCommandClear(command commandArray, input_vars inputStruct)
{
	ParseOnKomma(inputStruct, 1, 0, 1, commandArray);
}
