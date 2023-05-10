/*
 * DrawShapes.c
 *
 *
 *  Created on: 26 apr. 2023
 *      Author: Sjoerd
 */
#include <main.h>

/**
 * @fn int DrawRectangle(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t)
 * @brief Draws a rectangle with the specified color within the x & y coordinates
 *
 * @param xp1
 * @param yp1
 * @param xp2
 * @param yp2
 * @param color
 * @return
 */
int DrawRectangle(uint8_t xp1, uint8_t yp1, uint8_t xp2, uint8_t yp2, uint8_t color)
{
	 for(uint8_t y = yp1; y < yp2; y++)
	 {
		 for(uint8_t x = xp1; x < xp2; x++)
		 {
			 UB_VGA_SetPixel(x, y, color);

		 }

	 }
}
