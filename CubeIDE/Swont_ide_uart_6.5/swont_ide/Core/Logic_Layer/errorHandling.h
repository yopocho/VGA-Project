/*
 * errorHandling.h
 *
 *  Created on: 10 May 2023
 *      Author: niels
 */

#ifndef LOGIC_LAYER_ERRORHANDLING_H_
#define LOGIC_LAYER_ERRORHANDLING_H_

#include "main.h"

typedef enum
{
	ERR_INVALID_ARG,
	ERR_INVALID_CMD,
	ERR_ARG_OOB,
	ERR_MSG_LEN,
	ERR_NONE,
	ERR_GENERIC,
	ERR_UART_FAIL,
	ERR_UNKNOWN_ERR
} Error;

typedef enum
{
	NONE = 0x00U,
	LOW = 0x01U,
	MEDIUM = 0x02U,
	HIGH = 0x03U
} ErrorSeverity;

/**
 * @struct errorStruct
 * @brief Datatype for error messages
 *
 */
typedef struct ErrorDataType {
	Error ErrorCode;
	ErrorSeverity Severity;
	char* Msg;
} ErrorHandle;

static ErrorHandle ErrorList[] =
{
	{ERR_INVALID_ARG, 	LOW, 	"The supplied list of arguments is invalid\n\r"	},
	{ERR_INVALID_CMD, 	LOW, 	"Given command is wrong/unknown\n\r"			},
	{ERR_ARG_OOB, 		LOW, 	"Coordinates are out-of-bounds\n\r"				},
	{ERR_MSG_LEN, 		LOW, 	"Message length exceeded\n\r"					},
	{ERR_NONE, 			NONE, 	"No issue\n\r"									},
	{ERR_GENERIC, 		LOW, 	"Error\n\r"										},
	{ERR_UART_FAIL,		HIGH,	"UART Transmit failed\n\r"						}
};

Error TransmitError(Error ErrorCode);
ErrorHandle* GetError(Error ErrorCode);


#endif /* LOGIC_LAYER_ERRORHANDLING_H_ */
