/*
 * errorHandling.c
 *
 *  Created on: 10 May 2023
 *      Author: niels
 */

#include "errorhandling.h"

/**
 * @fn Error TransmitError(Error)
 * @brief Transmits relevant errors and their severity via UART
 *
 * @param ErrorCode
 * @return Error
 */
Error TransmitError(Error ErrorCode)
{
	ErrorHandle* Error = GetError(ErrorCode);
	printf("[%d]%s", Error->Severity, Error->Msg);
	return ERR_NONE;
}

/**
 * @fn ErrorHandle GetError*(Error)
 * @brief Loops through ErrorList to find the ErrorHandle struct with the requested error name
 *
 * @param ErrorCode
 * @return ErrorHandle
 */
ErrorHandle* GetError(Error ErrorCode)
{
	uint8_t SizeOfErrorList = sizeof(ErrorList)/sizeof(ErrorList[0]);
	for(uint8_t i = 0; i < SizeOfErrorList; i++)
	{
		if(ErrorList[i].ErrorCode == ErrorCode)
		{
			return &ErrorList[i];
		}
	}
	return ERR_UNKNOWN_ERR;
}


