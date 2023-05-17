/*
 * Commands.h
 *
 *  Created on: 17 May 2023
 *      Author: r_middelman
 */

#ifndef FRONT_LAYER_COMMANDS_H_
#define FRONT_LAYER_COMMANDS_H_


//size of the circulair buffer (which is also the max amount for the herhaal command)
#define SIZE_OF_CIRC_BUFFER 1024

/// @struct
/// @brief
/// struct that contains all the info of the given commands
typedef struct {
	//these are the same for almost all of the commands (maybe not wait and clear screen)
	uint8_t commandCode;

	//this is where it gets a little more complicated


}command;


#endif /* FRONT_LAYER_COMMANDS_H_ */
