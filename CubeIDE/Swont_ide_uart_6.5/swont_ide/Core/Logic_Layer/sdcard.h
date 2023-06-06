/*
 * sdcard.h
 *
 *  Created on: May 24, 2023
 *      Author: niels
 */

#ifndef LOGIC_LAYER_SDCARD_H_
#define LOGIC_LAYER_SDCARD_H_

#include "drawshapes.h"
#include "fatfs.h"
#include "main.h"

FATFS FatFs;     // FatFS Handle
FIL fil, *pFil;  // File Handle
FRESULT fres;    // Error Handle

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
 * @fn Error DrawBitmapFromSDCard(uint16_t, uint16_t, bitmapKey)
 * @brief Draws bitmap selector at given location, starting from top-left.
 *
 * @param xp
 * @param yp
 * @param selector
 * @return Error
 */
extern Error DrawBitmapFromSDCard(uint16_t xp, uint16_t yp, bitmapKey selector);

#endif /* LOGIC_LAYER_SDCARD_H_ */
