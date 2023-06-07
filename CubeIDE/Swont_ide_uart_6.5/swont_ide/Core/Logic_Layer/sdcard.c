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
Error SDCardInit() {
  // Open the file system
  fres = f_mount(&FatFs, "", 1);  // 1=mount now
  if (fres != FR_OK) {
    return ERR_SDCARD_MOUNT;
  }

  // Let's get some statistics from the SD card
  DWORD free_clusters, free_sectors, total_sectors, used_sectors;

  FATFS* getFreeFs;

  fres = f_getfree("", &free_clusters, &getFreeFs);
  if (fres != FR_OK) {
    return ERR_SDCARD_GETFREE;
  }

  // Formula comes from ChaN's documentation
  total_sectors = (getFreeFs->n_fatent - 2) * getFreeFs->csize;
  free_sectors = free_clusters * getFreeFs->csize;
  used_sectors = total_sectors - free_sectors;
  printf(
      "SD card stats:\r\n%10lu KiB total drive space.\r\n%10lu KiB "
      "available.\r\n%10lu KiB used.\r\n",
      total_sectors / 2, free_sectors / 2, used_sectors / 2);
  return ERR_NONE;
}

/**
 * @fn Error SDCardInit()
 * @brief Deinitializes the SD card
 *
 * @return Error
 */
Error SDCardDeinit() {
  // We're done, so de-mount the drive
  f_mount(NULL, "", 0);
  return ERR_NONE;
}

/**
 * @fn Error DrawBitmapFromSDCard(uint16_t, uint16_t, bitmapKey)
 * @brief Draws a bitmap at given location, starting from top-left.
 *
 * @param xp
 * @param yp
 * @param selector
 * @return Error
 */
Error DrawBitmapFromSDCard(uint16_t xp, uint16_t yp, bitmapKey selector) {
  if (xp > VGA_DISPLAY_X || yp > VGA_DISPLAY_Y) {
    return ERR_ARG_OOB;
  }

  if (fres != FR_OK) {
    return ERR_SDCARD_UNAVAILABLE;
  }

  // Convert asked-for bitmap to the name of the .txt file its saved in on the
  // SD card
  char filename[20] = "";
  itoa(selector, filename, 10);
  strcat(filename, ".txt");
  fres = f_open(&fil, filename, FA_READ);
  if (fres != FR_OK) {
    return ERR_SDCARD_OPEN;
  }

  // Setup preambleBuf to read preamble of bitmap into
  char preambleBuf[9];
  uint8_t bufLen = 0;

  // Read preamble of bitmap file
  fres = f_read(&fil, (void*)preambleBuf, 9, (UINT*)&bufLen);
  if (bufLen != 0 && fres == FR_OK) {
    printf("Read string from '%s' contents: %s\n\r", filename, preambleBuf);
  } else if (preambleBuf[3] != 'x')
    return ERR_BITMAP_FORMAT;
  else
    return ERR_SDCARD_READ;

  // Parse preambleBuf
  uint16_t width = atoi(preambleBuf);
  uint16_t height = atoi(preambleBuf + 4);

  // Setup readBuf to read data for each pixel
  uint8_t packetSize = 5;  // chars (0x..,) pixeldata + comma
  uint8_t readBuf[packetSize];

  // Check if bitmap will be written off-screen
  uint16_t limitY =
      (yp + height) < VGA_DISPLAY_Y ? (yp + height) : VGA_DISPLAY_Y;
  uint16_t limitX = (xp + width) < VGA_DISPLAY_X ? (xp + width) : VGA_DISPLAY_X;

  uint16_t pixelOverflow = 0;

  pFil = &fil;

  // Loop over every coordinte of where the bitmap has to be drawn, read the
  // pixel's colour and write to framebuffer
  for (uint16_t y = yp; y < limitY; y++) {
    for (uint16_t x = xp; x < limitX; x++) {
      fres = f_read(&fil, (void*)readBuf, packetSize, (UINT*)&bufLen);
      if (fres != FR_OK) {
        return ERR_SDCARD_READ;
      }
      readBuf[strlen((const char*)readBuf) - 1] = '\0';
      uint8_t pixelColor = (uint8_t)strtol((const char*)readBuf, NULL, 0);
      memset(readBuf, 0, sizeof(readBuf));
      VGA_RAM1[(y * (VGA_DISPLAY_X + 1)) + x] = pixelColor;
      ++pixelOverflow;
    }
    // If x is off-screen, offset read/write pointer with remaining pixels on
    // line
    if (((xp + width) > (VGA_DISPLAY_X)) &&
        ((pixelOverflow + width) > (VGA_DISPLAY_X))) {
      fres = f_lseek(
          pFil, f_tell(pFil) + (packetSize * (xp + width - VGA_DISPLAY_X)));
      if (fres != FR_OK) {
        return ERR_SDCARD_LSEEK;
      }
    }
    pixelOverflow = 0;
  }

  fres = f_close(&fil);
  if (fres != FR_OK) {
    return ERR_SDCARD_CLOSE;
  }
  return ERR_NONE;
}
