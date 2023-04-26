/*
 * Draw_Line.c
 *
 *  Created on: 26 apr. 2023
 *      Author: Sjoerd
 */
#include <main.h>
/**
 * @brief
 *
 * @param xp1
 * @param xp2
 * @param yp1
 * @param yp2
 * @param color
 * @return
 */
int Draw_Line(uint8_t xp1, uint8_t yp1, uint8_t xp2, uint8_t yp2, uint8_t color)
{
	 for(uint8_t y = yp1; y < yp2; y++)
	 {
		 for(uint8_t x = xp1; x < xp2; x++)
		 {
			 UB_VGA_SetPixel(x, y, color);

		 }

	 }
}
//  Draw_Line(10,80,10,20, VGA_COL_BLUE);
