/*
 * errorHandling.h
 *
 *  Created on: 10 May 2023
 *      Author: niels
 */

#ifndef LOGIC_LAYER_ERRORHANDLING_H_
#define LOGIC_LAYER_ERRORHANDLING_H_

#include "main.h"

/**
 * @enum Error
 * @brief Error codes datatype
 *
 */
typedef enum
{
	ERR_INVALID_ARG,   /**< ERR_INVALID_ARG */
	ERR_INVALID_CMD,   /**< ERR_INVALID_CMD */
	ERR_ARG_OOB,       /**< ERR_ARG_OOB */
	ERR_MSG_LEN,       /**< ERR_MSG_LEN */
	ERR_NONE,          /**< ERR_NONE */
	ERR_GENERIC,       /**< ERR_GENERIC */
	ERR_UART_FAIL,     /**< ERR_UART_FAIL */
	ERR_UNKNOWN_ERR,   /**< ERR_UNKNOWN_ERR */
	ERR_SDCARD_MOUNT,  /**< ERR_SDCARD_MOUNT */
	ERR_SDCARD_GETFREE,/**< ERR_SDCARD_GETFREE */
	ERR_SDCARD_GETS,   /**< ERR_SDCARD_GETS */
	ERR_SDCARD_WRITE,  /**< ERR_SDCARD_WRITE */
	ERR_SDCARD_OPEN    /**< ERR_SDCARD_OPEN */
} Error;

/**
 * @enum ErrorSeverity
 * @brief Enum which contains the different error severity levels
 *
 */
typedef enum
{
	NONE = 0x00U,  /**< NONE */
	LOW = 0x01U,   /**< LOW */
	MEDIUM = 0x02U,/**< MEDIUM */
	HIGH = 0x03U   /**< HIGH */
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
	{ERR_INVALID_ARG, 		LOW, 	"The supplied list of arguments is invalid\n\r"	},
	{ERR_INVALID_CMD, 		LOW, 	"Given command is wrong/unknown\n\r"			},
	{ERR_ARG_OOB, 			LOW, 	"Coordinates are out-of-bounds\n\r"				},
	{ERR_MSG_LEN, 			LOW, 	"Message length exceeded\n\r"					},
	{ERR_NONE, 				NONE, 	"No issue\n\r"									},
	{ERR_GENERIC, 			LOW, 	"Error\n\r"										},
	{ERR_UART_FAIL,			HIGH,	"UART Transmit failed\n\r"						},
	{ERR_SDCARD_MOUNT,		LOW,	"Could not mount SD-card\n\r"					},
	{ERR_SDCARD_GETFREE,	LOW,	"Could not retreive free space on SD-card"		},
	{ERR_SDCARD_GETS,		LOW,	"Could not read data from SD-card"				},
	{ERR_SDCARD_WRITE,		LOW,	"Could not write to SD-card"					},
	{ERR_SDCARD_OPEN,		LOW,	"Could not open SD-card"						}
};

Error TransmitError(Error ErrorCode);
ErrorHandle* GetError(Error ErrorCode);


#endif /* LOGIC_LAYER_ERRORHANDLING_H_ */
