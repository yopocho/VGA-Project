/*
 * DrawShapes.c
 *
 *
 *  Created on: 26 apr. 2023
 *      Author: Sjoerd
 */
#include <main.h>

/**
 * @fn int DrawRectangle(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t)
 * @brief Draws a rectangle with the specified color within the x & y coordinates
 *
 * @param xp
 * @param yp
 * @param Width
 * @param Heigth
 * @param color
 * @param filled
 * @return
 */
int DrawRectangle(uint8_t xp, uint8_t yp, uint8_t Width, uint8_t Heigth,
		uint8_t color, uint8_t filled) {
	if (filled == 0)
	{
		for (uint8_t y = yp; y < yp + Heigth; y++)
		{
			for (uint8_t x = xp; x < xp + Width; x++)
			{
				UB_VGA_SetPixel(x, y, color);
			}
		}
	}
	//rectangle not filled only lines
	if(filled == 1)
	{
		//top line
		for (uint8_t x = xp; x < xp + Width; x++)
		{
			UB_VGA_SetPixel(x, yp, color);
		}
		//bottom line
		for (uint8_t x = xp; x < xp + Width; x++)
		{
			UB_VGA_SetPixel(x, yp+Heigth, color);
		}

		//Left vertical line
		for (uint8_t y = yp; y < yp+Heigth; y++)
		{
			UB_VGA_SetPixel(xp, y, color);

		}
		//Right vertical line
		for (uint8_t y = yp; y < yp+Heigth; y++)
		{
			UB_VGA_SetPixel(xp+Width, y, color);
		}
	}
}
