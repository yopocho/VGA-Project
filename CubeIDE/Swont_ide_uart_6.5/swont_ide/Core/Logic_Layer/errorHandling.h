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
	MSG_ERR_INVALID_ARG = "The supplied list of arguments is invalid\n\r",//Argument(type) invalid
	MSG_ERR_INVALID_CMD = "Given command is wrong/unknown\n\r",//Unknown command
	MSG_ERR_ARG_OOB = "Coordinates are out-of-bounds\n\r",//Arg out-of-bounds
	MSG_ERR_MSG_LEN = "Message length exceeded\n\r",//UART Message length
	MSG_ERR_NONE = "No issue\n\r",
	MSG_ERR_GENERIC = "Error\n\r",
	MSG_ERR_UART_FAIL = "UART Transmit failed\n\r"
} ErrorMessage;

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
typedef struct errorDatatype {
	ErrorMessage msg;
	ErrorSeverity severity;
} ErrorHandle;

ErrorHandle ERR_INVALID_ARG, ERR_INVALID_CMD, ERR_ARG_OOB, ERR_MSG_LEN, ERR_NONE, ERR_GENERIC, ERR_UART_FAIL;

//ErrorHandle ERR_INVALID_ARG =
//{
//		.msg = MSG_ERR_INVALID_ARG,
//		.severity = LOW
//};
//
//ErrorHandle ERR_INVALID_CMD =
//{
//		.msg = MSG_ERR_INVALID_CMD,
//		.severity = LOW
//};
//
//ErrorHandle ERR_ARG_OOB =
//{
//		.msg = ERR_ARG_OOB,
//		.severity = LOW
//};
//
//ErrorHandle ERR_MSG_LEN =
//{
//		.msg = MSG_ERR_MSG_LEN,
//		.severity = MEDIUM
//};
//
//ErrorHandle ERR_NONE =
//{
//		.msg = MSG_ERR_NONE,
//		.severity = NONE
//};
//
//ErrorHandle ERR_GENERIC =
//{
//		.msg = MSG_ERR_GENERIC,
//		.severity = HIGH
//};
//
//ErrorHandle ERR_TX_FAIL =
//{
//		.msg = MSG_TX_FAIL,
//		.severity = HIGH
//};

ErrorHandle TransmitError(errorHandle *errorMessage, UART_HandleTypeDef *huart);
ErrorHandle InitErrors();


#endif /* LOGIC_LAYER_ERRORHANDLING_H_ */
