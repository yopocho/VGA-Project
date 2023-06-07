/*
 * sdcard.h
 *
 *  Created on: May 24, 2023
 *      Author: niels
 */

#ifndef LOGIC_LAYER_SDCARD_H_
#define LOGIC_LAYER_SDCARD_H_

// #include "drawshapes.h"
#include "fatfs.h"
#include "main.h"

extern FATFS FatFs;     // FatFS Handle
extern FIL fil, *pFil;  // File Handle
extern FRESULT fres;    // Error Handle

/**
 * @enum bitmapKey
 * @brief Datatype to define enumerated keys for the different available bitmaps
 *
 */
typedef enum  // TODO: Add all these bitmaps to the SD-card, only test images
              // are available
{ LEFT,       /**< LEFT */
  RIGHT,      /**< RIGHT */
  UP,         /**< UP */
  DOWN,       /**< DOWN */
  SMILEY,     /**< SMILEY */
  ANGRY       /**< ANGRY */
} bitmapKey;

Error SDCardInit();
Error SDCardDeinit();
extern Error DrawBitmapFromSDCard(uint16_t xp, uint16_t yp, bitmapKey selector);
extern Error ClearScreen(uint8_t color);
extern Error DrawRectangle(uint8_t xp, uint8_t yp, uint8_t Width,
                           uint8_t Heigth, uint8_t color, uint8_t filled);
Error DrawLine(uint8_t xp1, uint8_t yp1, uint8_t xp2, uint8_t yp2,
               uint8_t color, uint8_t thickness);
extern Error RepeatCommands(uint8_t repeatDepth, uint8_t repeatCount);
extern Error Wait(uint32_t delayMs);
extern Error DrawFigure(uint16_t xp1, uint16_t yp1, uint16_t xp2, uint16_t yp2,
                        uint16_t xp3, uint16_t yp3, uint16_t xp4, uint16_t yp4,
                        uint16_t xp5, uint16_t yp5, uint8_t color);
extern Error DrawCircle(uint16_t xp, uint16_t yp, uint16_t radius,
                        uint8_t color);

#endif /* LOGIC_LAYER_SDCARD_H_ */
