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
	DWORD free_clusters, free_sectors, total_sectors;

	FATFS* getFreeFs;

	fres = f_getfree("", &free_clusters, &getFreeFs);
	if (fres != FR_OK) {
		return ERR_SDCARD_GETFREE;
	}

	//Formula comes from ChaN's documentation
	total_sectors = (getFreeFs->n_fatent - 2) * getFreeFs->csize;
	free_sectors = free_clusters * getFreeFs->csize;

	myprintf("SD card stats:\r\n%10lu KiB total drive space.\r\n%10lu KiB available.\r\n", total_sectors / 2, free_sectors / 2);
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
}

/**
 * @fn Error SDCardReadFile()
 * @brief
 *
 * @return
 */
Error SDCardReadFile()
{
	//	//Now let's try to open file "test.txt"
	//	fres = f_open(&fil, "test.txt", FA_READ);
	//	if (fres != FR_OK) {
	//	myprintf("f_open error (%i)\r\n");
	//	while(1);
	//	}
	//	myprintf("I was able to open 'test.txt' for reading!\r\n");
	//
	//	//Read 30 bytes from "test.txt" on the SD card
	//	BYTE readBuf[30];
	//
	//	//We can either use f_read OR f_gets to get data out of files
	//	//f_gets is a wrapper on f_read that does some string formatting for us
	//	TCHAR* rres = f_gets((TCHAR*)readBuf, 30, &fil);
	//	if(rres != 0) {
	//	myprintf("Read string from 'test.txt' contents: %s\r\n", readBuf);
	//	} else {
	//	myprintf("f_gets error (%i)\r\n", fres);
	//	}
	//
	//	//Be a tidy kiwi - don't forget to close your file!
	//	f_close(&fil);
}


