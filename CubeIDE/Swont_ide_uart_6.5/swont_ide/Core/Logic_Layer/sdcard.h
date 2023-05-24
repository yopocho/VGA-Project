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

extern Error SDCardInit();

extern Error SDCardDeinit();

#endif /* LOGIC_LAYER_SDCARD_H_ */
