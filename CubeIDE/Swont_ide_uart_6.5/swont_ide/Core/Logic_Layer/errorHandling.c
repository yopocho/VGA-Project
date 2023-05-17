/*
 * errorHandling.c
 *
 *  Created on: 10 May 2023
 *      Author: niels
 */

#include "errorhandling.h"

Error TransmitError(Error ErrorCode)
{
	ErrorHandle* Error = GetError(ErrorCode);
	printf("[%d]%s", Error->Severity, Error->Msg);
	return ERR_NONE;
}

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


