/*
 * sdcard.c
 *
 *  Created on: May 24, 2023
 *      Author: niels
 */

#include "sdcard.h"


/**
 * @fn Error SDCardInit()
 * @brief Initializes the SD card
 *
 * @return Error
 */
Error SDCardInit()
{
	//Open the file system
	fres = f_mount(&FatFs, "", 1); //1=mount now
	if (fres != FR_OK) {
		return ERR_SDCARD_MOUNT;
	}

	//Let's get some statistics from the SD card
	DWORD free_clusters, free_sectors, total_sectors, used_sectors;

	FATFS* getFreeFs;

	fres = f_getfree("", &free_clusters, &getFreeFs);
	if (fres != FR_OK) {
		return ERR_SDCARD_GETFREE;
	}

	//Formula comes from ChaN's documentation
	total_sectors = (getFreeFs->n_fatent - 2) * getFreeFs->csize;
	free_sectors = free_clusters * getFreeFs->csize;
	used_sectors = total_sectors - free_sectors;
	printf("SD card stats:\r\n%10lu KiB total drive space.\r\n%10lu KiB available.\r\n%10ul KiB used.\r\n", total_sectors / 2, free_sectors / 2, used_sectors / 2);
	return ERR_NONE;
}


/**
 * @fn Error SDCardInit()
 * @brief Deinitializes the SD card
 *
 * @return Error
 */
Error SDCardDeinit()
{
	//We're done, so de-mount the drive
	f_mount(NULL, "", 0);
	return ERR_NONE;
}

///**
// * @fn Error SDCardReadFile()
// * @brief
// *
// * @return
// */
//Error SDCardReadFile(uint8_t* pFramebuffer, uint8_t bitmapIndex)
//{
//	return ERR_NONE;
//}

/**
 * @fn Error DrawBitmapFromSDCard(uint8_t, uint8_t, uint8_t)
 * @brief Draws a bitmap at given location, starting from top-left.
 *
 * @param selector
 * @param xp
 * @param yp
 * @return Error
 */
Error DrawBitmapFromSDCard(uint16_t xp, uint16_t yp, uint8_t selector) {

	if(xp > VGA_DISPLAY_X || yp > VGA_DISPLAY_Y) {
		return ERR_ARG_OOB;
	}

	if(fres != FR_OK){
		return ERR_SDCARD_UNAVAILABLE;
	}

	//Convert asked-for bitmap to the name of the .txt file its saved in on the SD card
	char filename[20] = "";
	itoa(selector, filename, 10);
	strcat(filename, ".txt");
	fres = f_open(&fil, filename, FA_READ);
	if (fres != FR_OK) {
		return ERR_SDCARD_OPEN;
	}

	unsigned char preambleBuf[9];
	uint8_t bufLen = 0;

	f_read(&fil, (void*)preambleBuf, 9, &bufLen);
	if(bufLen != 0) {
		printf("Read string from '%s' contents: %s\n\r", filename, preambleBuf);
	}
	else if(preambleBuf[3] != 'x') return ERR_BITMAP_FORMAT;
	else return ERR_SDCARD_GETS;

	uint16_t width = atoi(preambleBuf);
	uint16_t height = atoi(preambleBuf+4);
	printf("%d, %d\n\r", width, height);
	uint8_t packetSize = 5; //chars (0x..,) pixeldata + comma
	uint8_t readBuf[packetSize];

	// Check if bitmap will be written off-screen
	uint16_t limitY = (yp+height)<VGA_DISPLAY_Y?(yp+height):VGA_DISPLAY_Y;
	uint16_t limitX = (xp+width)<VGA_DISPLAY_X?(xp+width):VGA_DISPLAY_X;

	uint8_t pixelColor = 0;

	uint16_t counter = 0;

	for(uint16_t y = yp; y < limitY; y++)
	{
		for(uint16_t x = xp; x < limitX; x++)
		{
			f_read(&fil, (void*)readBuf, packetSize, &bufLen);
//			printf(readBuf);
			readBuf[strlen(readBuf)-1] = '\0';
			uint8_t pixelColor = (uint8_t)strtol(readBuf, NULL, 0);
			memset(readBuf ,0, sizeof(readBuf));
//			UB_VGA_SetPixel(x, y, pixelColor);
			VGA_RAM1[(y * (VGA_DISPLAY_X + 1)) + x] = pixelColor;
			++counter;
		}
		if(((xp + width) > (VGA_DISPLAY_X + 1)) && ((counter + width) > (VGA_DISPLAY_X + 1))) {
			uint32_t xOffset = (packetSize * (xp + width - VGA_DISPLAY_X));
			uint32_t error = f_lseek(fil.fptr, f_tell(fil.fptr) + xOffset);
			printf(error);
		}
		counter = 0;
		if(fil.fptr > 327689) printf("ohkut");
//		fil.fptr = 9;
	}

	f_close(&fil);
	return ERR_NONE;
}

//	switch(selector)
//	{
//		case LEFT:
//			for (uint8_t y = 0; y < BITMAPSIZE; y++) {
//						for (uint8_t x = 0; x < BITMAPSIZE; x++) {
//							if (arrowLeft[y][x] != 0b10010000) {
//								color = arrowLeft[y][x];
//								UB_VGA_SetPixel(xp + x, yp + y, color);
//							}
//						}
//					}
//			break;
//		case RIGHT:
//			for (uint8_t y = 0; y < BITMAPSIZE; y++) {
//				for (uint8_t x = 0; x < BITMAPSIZE; x++) {
//					if (arrowLeft[y][x] != 0b10010000) {
//						color = arrowLeft[y][x];
//						UB_VGA_SetPixel(xp + BITMAPSIZE - x, yp + BITMAPSIZE - y,
//								color);
//					}
//				}
//			}
//			break;
//		case UP:
//			for (uint8_t y = 0; y < BITMAPSIZE; y++) {
//				for (uint8_t x = 0; x < BITMAPSIZE; x++) {
//					if (arrowLeft[x][y] != 0b10010000) {
//						color = arrowLeft[x][y];
//						UB_VGA_SetPixel(xp + x, yp + y, color);
//					}
//				}
//			}
//			break;
//		case DOWN:
//			for (uint8_t y = 0; y < BITMAPSIZE; y++) {
//				for (uint8_t x = 0; x < BITMAPSIZE; x++) {
//					if (arrowLeft[x][y] != 0b10010000) {
//						color = arrowLeft[x][y];
//						UB_VGA_SetPixel(xp + BITMAPSIZE - x, yp + BITMAPSIZE - y,
//								color);
//					}
//				}
//			}
//			break;
//		case SMILEY:
//			for (uint8_t y = 0; y < BITMAPSIZE; y++) {
//				for (uint8_t x = 0; x < BITMAPSIZE; x++) {
//					if (smiley[y][x] != 0b10010000) {
//						color = smiley[y][x];
//						UB_VGA_SetPixel(xp + x, yp + y, color);
//
//					}
//				}
//			}
//			break;
//		case ANGRY:
//			for (uint8_t y = 0; y < BITMAPSIZE; y++) {
//				for (uint8_t x = 0; x < BITMAPSIZE; x++) {
//					if (angry[y][x] != 0b10010000) {
//						color = angry[y][x];
//						UB_VGA_SetPixel(xp + x, yp + y, color);
//					}
//				}
//			}
//			break;
//		default:
//			return ERR_INVALID_ARG;
//			break;
//	}


