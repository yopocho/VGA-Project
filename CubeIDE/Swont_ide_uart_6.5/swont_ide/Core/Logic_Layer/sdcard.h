/*
 * sdcard.h
 *
 *  Created on: May 24, 2023
 *      Author: niels
 */

#include "main.h"
#include "fatfs.h"

#ifndef LOGIC_LAYER_SDCARD_H_
#define LOGIC_LAYER_SDCARD_H_


FATFS FatFs; //FatFS Handle
FIL fil; //File Handle
FRESULT fres; //Error Handle

/**
 * @fn Error SDCardInit()
 * @brief Initializes the SD card
 *
 * @return Error
 */
extern Error SDCardInit();


/**
 * @fn Error SDCardDeinit()
 * @brief deinitializes the SD card
 *
 * @return Error
 */
extern Error SDCardDeinit();


/**
 * @fn Error SDCardReadFile()
 * @brief Reads file from the SD card
 *
 * @return Error
 */
extern Error SDCardReadFile();

#endif /* LOGIC_LAYER_SDCARD_H_ */
