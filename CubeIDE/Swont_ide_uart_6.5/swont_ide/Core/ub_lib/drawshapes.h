/*
 * DrawShapes.h
 *
 *  Created on: 17 mei 2023
 *      Author: Sjoerd
 */

#ifndef UB_LIB_DRAWSHAPES_H_
#define UB_LIB_DRAWSHAPES_H_

#include <main.h>
#include <errorHandling.h>

#define BITMAPSIZE 50

/**
 * @enum bitmapKey
 * @brief Datatype to define enumerated keys for the different available bitmaps
 *
 */
typedef enum //TODO: Add all these bitmaps to the SD-card, only test images are available
{
	LEFT,  /**< LEFT */
	RIGHT, /**< RIGHT */
	UP,    /**< UP */
	DOWN,  /**< DOWN */
	SMILEY,/**< SMILEY */
	ANGRY  /**< ANGRY */
} bitmapKey;

//Prototypes
//Error DrawRectangle(uint8_t xp, uint8_t yp, uint8_t Width, uint8_t Heigth, uint8_t color, uint8_t filled);
//Error DrawLine(uint8_t xp1, uint8_t yp1, uint8_t xp2, uint8_t yp2, uint8_t color, uint8_t thickness);
//Error ClearScreen(uint8_t color);

#endif /* UB_LIB_DRAWSHAPES_H_ */
