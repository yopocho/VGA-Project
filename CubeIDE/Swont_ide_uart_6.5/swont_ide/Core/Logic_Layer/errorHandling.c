/*
 * errorHandling.c
 *
 *  Created on: 10 May 2023
 *      Author: niels
 */

#include "errorHandling.h"


/**
 * @fn errorHandle transmitError(errorHandle, UART_HandleTypeDef*)
 * @brief
 *
 * @param errorMessage
 * @param huart
 * @return
 */
errorHandle TransmitError(errorHandle* errorMessage, UART_HandleTypeDef *huart)
{
	char* sevChar;
	itoa(errorMessage->severity, sevChar, 10);
	char* sevMSG = "Severity[";
	char* tempTotalMSG = strcat(sevMSG, errorMessage->msg);
	char* totalMSG = strcat(tempTotalMSG, "]");
	if(HAL_UART_Transmit(&huart, &totalMSG, strlen(totalMSG), 0xFFFF) != HAL_OK)
		{
			TransmitError(ERR_TX_FAIL, &huart);
		}
	return ERR_TX_;
}
