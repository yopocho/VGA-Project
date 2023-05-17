/*
 * DrawShapes.c
 *
 *
 *  Created on: 26 apr. 2023
 *      Author: Sjoerd
 */
#include <main.h>
#include <math.h>
#include <Bitmaps.h>
#include <DrawShapes.h>


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
int DrawRectangle(uint8_t xp, uint8_t yp, uint8_t Width, uint8_t Heigth, uint8_t color, uint8_t filled)
{
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
	//rectangle not filled, only lines
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

/**
 * @fn int DrawLine(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t)
 * @brief Draws a line in between the specified points with color and thickness
 *
 * @param xp
 * @param yp
 * @param xp2
 * @param yp2
 * @param color
 * @param thickness
 * @return
 */
int DrawLine(uint8_t xp1, uint8_t yp1, uint8_t xp2, uint8_t yp2, uint8_t color, uint8_t thickness)
{
	int dx = xp2 - xp1;
    int dy = yp2 - yp1;

    // calculate steps required for generating pixels
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    // calculate increment in x & y for each steps
    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;

    // Put pixel for each step
    for(int j=0-abs(thickness/2); j <= abs(thickness/2); j++)
    {
    	float X = xp1 + 0.5;
    	float Y = yp1 + j + 0.5;
    	for (int i = 0; i <= steps; i++)
    	{
    		 UB_VGA_SetPixel(X,Y,color);
    		 X += Xinc; // increment in x at each step
    		 Y += Yinc;
    	}
    }
}

/**
 * @fn int ClearScreen(uint8_t)
 * @brief Clears the screen in the specified color
 *
 * @param color
 * @return
 */
int ClearScreen(uint8_t color)
{
	UB_VGA_FillScreen(color);
}

/**
 * @fn int DrawBitmap(uint8_t, uint8_t, uint8_t)
 * @brief Draws a bitmap on given location
 *
 * @param xp
 * @param yp
 * @param selection
 * @return
 */
int DrawBitmap(uint8_t selector,uint8_t xp, uint8_t yp)
{
	uint8_t color;

	if(selector == LEFT)//Left
	{
		for (uint8_t y = 0; y < BITMAPSIZE; y++)
		{
			for (uint8_t x = 0; x < BITMAPSIZE; x++)
			{
				if (arrowLeft[y][x] != 0b10010000)
				{
					color = arrowLeft[y][x];
					UB_VGA_SetPixel(xp+x, yp+y, color);
				}
			}
		}
	}

	if(selector == RIGHT)//Right
	{
		for (uint8_t y = 0; y < BITMAPSIZE; y++)
		{
			for (uint8_t x = 0; x < BITMAPSIZE; x++)
			{
				if (arrowLeft[y][x] != 0b10010000)
				{
					color = arrowLeft[y][x];
					UB_VGA_SetPixel(xp+BITMAPSIZE-x, yp+BITMAPSIZE-y, color);
				}
			}
		}
	}

	if(selector == UP) //Up
	{
		for (uint8_t y = 0; y < BITMAPSIZE; y++)
		{
			for (uint8_t x = 0; x < BITMAPSIZE; x++)
			{
				if (arrowLeft[x][y] != 0b10010000)
				{
					color = arrowLeft[x][y];
					UB_VGA_SetPixel(xp+x, yp+y, color);
				}
			}
		}
	}

	if(selector == DOWN)//Down
	{
		for (uint8_t y = 0; y < BITMAPSIZE; y++)
		{
			for (uint8_t x = 0; x < BITMAPSIZE; x++)
			{
				if (arrowLeft[x][y] != 0b10010000)
				{
					color = arrowLeft[x][y];
					UB_VGA_SetPixel(xp+BITMAPSIZE-x, yp+BITMAPSIZE-y, color);
				}
			}
		}
	}

	if(selector == SMILEY)//smileyFace
	{
		for (uint8_t y = 0; y < BITMAPSIZE; y++)
		{
			for (uint8_t x = 0; x < BITMAPSIZE; x++)
			{
				if (smiley[y][x] != 0b10010000)
				{
					color = smiley[y][x];
					UB_VGA_SetPixel(xp+x, yp+y, color);

				}
			}
		}
	}
	if(selector == ANGRY)//Anrgy Face
		{
			for (uint8_t y = 0; y < BITMAPSIZE; y++)
			{
				for (uint8_t x = 0; x < BITMAPSIZE; x++)
				{
					if (angry[y][x] != 0b10010000)
					{
						color = angry[y][x];
						UB_VGA_SetPixel(xp+x, yp+y, color);

					}
				}
			}
		}
}







