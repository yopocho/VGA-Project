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
Error DrawBitmapFromSDCard(uint8_t selector, uint8_t xp, uint8_t yp) {
	uint8_t color;

	if(fres != FR_OK){
		return ERR_SDCARD_UNAVAILABLE;
	}

	//Convert asked-for bitmap to the name of the .txt file its saved in on the SD card
	char filename[20] = "";
	itoa(selector, filename, 10);
	strcat(filename, ".txt");
	fres = f_open(&fil, filename, FA_READ);
	printf(filename);
	if (fres != FR_OK) {
		return ERR_SDCARD_OPEN;
	}

	unsigned char preambleBuf[32];
	uint8_t bufLen = 0;

	f_read(&fil, (void*)preambleBuf, 32, &bufLen);
	if(bufLen != 0) {
		printf("Read string from '%s' contents: %s\r\n", filename, preambleBuf);
	}
	else return ERR_SDCARD_GETS;

	uint8_t packetSize = 5; //0x.. pixeldata + comma
	uint8_t readBuf[packetSize];
	uint32_t pixelIndex = 0;
	uint8_t pixelColor = 0;
	bufLen = 0;

	while(1)
		{
			f_read(&fil, (void*)readBuf, packetSize, &bufLen);
			if(bufLen < packetSize) break;
			readBuf[strlen(readBuf)-1] = '\0';
//			printf(readBuf);
//			printf("\n\r");
			uint8_t pixelColor = (uint8_t)strtol(readBuf, NULL, 0);
			memset(readBuf ,0, sizeof(readBuf));
//			if(!(pixelIndex % VGA_DISPLAY_X)) ++pixelIndex; //TODO: 1 pixel per regel te weinig -_-, mss ArrayGenerator's schuld?
			VGA_RAM1[pixelIndex] = pixelColor;
			pixelColor = 0;
			++pixelIndex;
		}
//	printf(readBuf);
	printf("Array read!");

	//Be a tidy kiwi - don't forget to close your file!

	//		myprintf("I was able to open 'test.txt' for reading!\r\n");
	//
	//		//Read 30 bytes from "test.txt" on the SD card
	//		BYTE readBuf[30];
	//
	//		//We can either use f_read OR f_gets to get data out of files
	//		//f_gets is a wrapper on f_read that does some string formatting for us
	//		TCHAR* rres = f_gets((TCHAR*)readBuf, 30, &fil);
	//		if(rres != 0) {
	//		myprintf("Read string from 'test.txt' contents: %s\r\n", readBuf);
	//		} else {
	//		myprintf("f_gets error (%i)\r\n", fres);
	//		}
	//
	//		//Be a tidy kiwi - don't forget to close your file!
	//		f_close(&fil);

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
	f_close(&fil);
	return ERR_NONE;
}


