/*
 * sdcard.h
 *
 *  Created on: May 24, 2023
 *      Author: niels
 */

#ifndef LOGIC_LAYER_SDCARD_H_
#define LOGIC_LAYER_SDCARD_H_

#include "main.h"
#include "fatfs.h"


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
extern Error SDCardReadFile(uint8_t* pFramebuffer, uint8_t bitmapIndex);

extern Error DrawBitmapFromSDCard(uint16_t xp, uint16_t yp, uint8_t selector);

#endif /* LOGIC_LAYER_SDCARD_H_ */
