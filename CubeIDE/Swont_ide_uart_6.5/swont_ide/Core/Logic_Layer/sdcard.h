/*
 * sdcard.h
 *
 *  Created on: May 24, 2023
 *      Author: niels
 */

#ifndef LOGIC_LAYER_SDCARD_H_
#define LOGIC_LAYER_SDCARD_H_

FATFS FatFs; 	//Fatfs handle
FIL fil; 		//File handle
FRESULT fres; //Result after operations

extern void SDCardInit();

extern void SDCardDeinit();

#endif /* LOGIC_LAYER_SDCARD_H_ */
