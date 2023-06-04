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
 * @brief Enum for all API error codes
 *
 */
typedef const enum
{
	ERR_INVALID_ARG,       /**< ERR_INVALID_ARG */
	ERR_INVALID_CMD,       /**< ERR_INVALID_CMD */
	ERR_ARG_OOB,           /**< ERR_ARG_OOB */
	ERR_MSG_LEN,           /**< ERR_MSG_LEN */
	ERR_NONE,              /**< ERR_NONE */
	ERR_GENERIC,           /**< ERR_GENERIC */
	ERR_UART_FAIL,         /**< ERR_UART_FAIL */
	ERR_UNKNOWN_ERR,       /**< ERR_UNKNOWN_ERR */
	ERR_SDCARD_MOUNT,      /**< ERR_SDCARD_MOUNT */
	ERR_SDCARD_GETFREE,    /**< ERR_SDCARD_GETFREE */
	ERR_SDCARD_READ,       /**< ERR_SDCARD_READ */
	ERR_SDCARD_WRITE,      /**< ERR_SDCARD_WRITE */
	ERR_SDCARD_OPEN,       /**< ERR_SDCARD_OPEN */
	ERR_SDCARD_UNAVAILABLE,/**< ERR_SDCARD_UNAVAILABLE */
	ERR_BITMAP_FORMAT,     /**< ERR_BITMAP_FORMAT */
	ERR_SDCARD_CLOSE,      /**< ERR_SDCARD_CLOSE */
	ERR_SDCARD_LSEEK,       /**< ERR_SDCARD_LSEEK */
	ERR_INVALID_COL,
	ERR_TEXT_OOB,
	ERR_INVALID_CHAR
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

static const ErrorHandle ErrorList[] =
{
	{ERR_INVALID_ARG, 			LOW, 	"The supplied list of arguments is invalid\r\n"	},
	{ERR_INVALID_CMD, 			LOW, 	"Given command is wrong/unknown\r\n"			},
	{ERR_ARG_OOB, 				LOW, 	"Coordinates are out-of-bounds\r\n"				},
	{ERR_MSG_LEN, 				LOW, 	"Message length exceeded\r\n"					},
	{ERR_NONE, 					NONE, 	"No issue\r\n"									},
	{ERR_GENERIC, 				LOW, 	"Error\r\n"										},
	{ERR_UART_FAIL,				HIGH,	"UART Transmit failed\r\n"						},
	{ERR_UNKNOWN_ERR,			MEDIUM,	"Couldn't return error\r\n"						},
	{ERR_SDCARD_MOUNT,			LOW,	"Could not mount SD-card\r\n"					},
	{ERR_SDCARD_GETFREE,		LOW,	"Could not retrieve free space on SD-card\r\n"	},
	{ERR_SDCARD_READ,			LOW,	"Could not read data from SD-card\r\n"			},
	{ERR_SDCARD_WRITE,			LOW,	"Could not write to SD-card\r\n"				},
	{ERR_SDCARD_OPEN,			LOW,	"Could not open SD-card\r\n"					},
	{ERR_SDCARD_UNAVAILABLE, 	LOW,	"SDCard unavailable\r\n"						},
	{ERR_BITMAP_FORMAT,			LOW,	"Supplied bitmap has an incorrect format\r\n"	},
	{ERR_SDCARD_CLOSE,			LOW,	"Unable to close SD-card\r\n"					},
	{ERR_SDCARD_LSEEK,			LOW,	"FatFS f_lseek misbehaved\r\n"					},
	{ERR_INVALID_COL,			LOW,	"Given color in wrong or unkown\r\n"			},
	{ERR_TEXT_OOB,				LOW,	"Text will not fit inside screen\r\n"			},
	{ERR_INVALID_CHAR,			MEDIUM,	"Character is invalid or unkown in text\r\n"	}
};

Error TransmitError(Error ErrorCode);
ErrorHandle* GetError(Error ErrorCode);


#endif /* LOGIC_LAYER_ERRORHANDLING_H_ */
