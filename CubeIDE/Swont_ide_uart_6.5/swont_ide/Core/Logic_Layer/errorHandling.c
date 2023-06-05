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
	printf("[%02d:%02d:%02d][%d]%s", (HAL_GetTick()/1000/60/60)%24, (HAL_GetTick()/1000/60)%60, (HAL_GetTick()/1000)%60, Error->Severity, Error->Msg);
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
	size_t SizeOfErrorList = sizeof(ErrorList)/sizeof(ErrorList[0]);
	for(size_t i = 0; i < SizeOfErrorList; i++){
		if(ErrorList[i].ErrorCode == ErrorCode){
			return (ErrorHandle*)&ErrorList[i];
		}
	}
	return (ErrorHandle*)&ErrorList[ERR_UNKNOWN_ERR];
}


