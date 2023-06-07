/*
 * DrawShapes.c
 *
 *
 *  Created on: 26 apr. 2023
 *      Author: Sjoerd
 */

#include "drawshapes.h"

#include <math.h>

#include "Commands.h"

/**
 * @fn Error DrawLine(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t)
 * @brief Draws a line in between the specified points with color and thickness
 *
 * @param xp
 * @param yp
 * @param xp2
 * @param yp2
 * @param color
 * @param thickness
 * @return Error
 */
Error DrawLine(uint16_t xp1, uint16_t yp1, uint16_t xp2, uint16_t yp2,
               uint8_t color, uint8_t thickness) {
  // Error checks
  if (xp1 > VGA_DISPLAY_X) return ERR_ARG_OOB;
  if (yp1 > VGA_DISPLAY_Y) return ERR_ARG_OOB;
  if (xp2 > VGA_DISPLAY_X) return ERR_ARG_OOB;
  if (yp2 > VGA_DISPLAY_Y) return ERR_ARG_OOB;

  int dx = xp2 - xp1;
  int dy = yp2 - yp1;

  // calculate steps required for generating pixels
  int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

  // calculate increment in x & y for each steps
  float Xinc = dx / (float)steps;
  float Yinc = dy / (float)steps;

  // Put pixel for each step
  for (int j = 0 - abs(thickness / 2); j <= abs(thickness / 2); j++) {
    float X = xp1 + 0.5;
    float Y = yp1 + j + 0.5;
    for (int i = 0; i <= steps; i++) {
      UB_VGA_SetPixel(X, Y, color);
      X += Xinc;  // increment in x at each step
      Y += Yinc;
    }
  }
  return ERR_NONE;
}

/**
 * @fn Error DrawRectangle(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t)
 * @brief Draws a rectangle with the specified color within the x & y
 * coordinates
 *
 * @param xp
 * @param yp
 * @param Width
 * @param Heigth
 * @param color
 * @param lined
 * @return Error
 */
Error DrawRectangle(uint16_t xp, uint16_t yp, uint16_t Width, uint16_t Heigth,
                    uint8_t color, uint8_t lined) {
  // Error checks
  if (xp > VGA_DISPLAY_X) return ERR_ARG_OOB;
  if (yp > VGA_DISPLAY_Y) return ERR_ARG_OOB;
  if (lined < 0 || lined > 1) return ERR_ARG_OOB;
  if (xp + Width > VGA_DISPLAY_X) return ERR_ARG_OOB;
  if (yp + Heigth > VGA_DISPLAY_Y) return ERR_ARG_OOB;

  if (lined == 0) {
    for (uint8_t y = yp; y < yp + Heigth; y++) {
      for (uint8_t x = xp; x < xp + Width; x++) {
        UB_VGA_SetPixel(x, y, color);
      }
    }
  }
  // rectangle not filled, only lines
  if (lined == 1) {
    // top line
    DrawLine(xp, yp, xp + Width, yp, color, 1);
    // bottom line
    DrawLine(xp, yp + Heigth, xp + Width, yp + Heigth, color, 1);
    // Left vertical line
    DrawLine(xp, yp, xp, yp + Heigth, color, 1);
    // Right vertical line
    DrawLine(xp + Width, yp, xp + Width, yp + Heigth, color, 1);
  }
  return ERR_NONE;
}

/**
 * @fn Error ClearScreen(uint8_t)
 * @brief Clears the screen in the specified color
 *
 * @param color
 * @return Error
 */
Error ClearScreen(uint8_t color) {
  UB_VGA_FillScreen(color);
  return ERR_NONE;
}

/**
 * @fn Error DrawCircle(uint16_t, uint16_t, uint16_t, uint8_t)
 * @brief Draws a circle with center xp,yp, of radius radius and of color color
 *
 * @param xp
 * @param yp
 * @param radius
 * @param color
 * @return Error
 */
Error DrawCircle(uint16_t xp, uint16_t yp, uint16_t radius, uint8_t color) {
  if (xp > VGA_DISPLAY_X || yp > VGA_DISPLAY_Y) {
    return ERR_ARG_OOB;
  }

  double angle, x1, y1;
  for (angle = 0; angle < 360; angle += 0.1) {
    x1 = radius * cos(angle * M_PI / 180);
    y1 = radius * sin(angle * M_PI / 180);
    UB_VGA_SetPixel(xp + x1, yp + y1, color);
  }
  return ERR_NONE;
}

/**
 * @fn Error DrawFigure(uint16_t, uint16_t, uint16_t, uint16_t, uint16_t,
 * uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint8_t)
 * @brief Draws a figure with lines to and from p1-p5 in the given color.
 *
 * @param xp1
 * @param yp1
 * @param xp2
 * @param yp2
 * @param xp3
 * @param yp3
 * @param xp4
 * @param yp4
 * @param xp5
 * @param yp5
 * @param color
 * @return Error
 */
Error DrawFigure(uint16_t xp1, uint16_t yp1, uint16_t xp2, uint16_t yp2,
                 uint16_t xp3, uint16_t yp3, uint16_t xp4, uint16_t yp4,
                 uint16_t xp5, uint16_t yp5, uint8_t color) {
  uint16_t coords[10] = {xp1, yp1, xp2, yp2, xp3, yp3, xp4, yp4, xp5, yp5};

  // Loop over all the start and end coordinates, drawing a line between them
  for (uint8_t i = 0; i < 10; i += 2) {
    Error err = DrawLine(coords[i], coords[i + 1], coords[i + 2], coords[i + 3],
                         color, FIGURE_THICKNESS);
    if (err != ERR_NONE) {
      return err;
    }
  }

  return ERR_NONE;
}

/**
 * @fn Error Wait(uint32_t delayMs)
 * @brief Delays drawing for delayMs amont of milliseconds.
 *
 * @param delayMs
 * @return Error
 */
Error Wait(uint32_t delayMs) {
  printf("Waiting for %lu ms\r\n", delayMs);
  HAL_Delay(delayMs);
  printf("Done waiting\r\n");
  return ERR_NONE;
}

/**
 * @fn Error RepeatCommands(uint8_t, uint8_t)
 * @brief Repeats the last amount repeatDepth commands for repeatCount amount of
 * times. Reads from the circular buffer where the commands have been pushed to.
 *
 * @param repeatDepth
 * @param repeatCount
 * @return Error
 */
Error RepeatCommands(uint8_t repeatDepth, uint8_t repeatCount) {
  if (pCircBuf->CmdBufLen < repeatDepth) {
    return ERR_ARG_OOB;
  }

  if ((pCircBuf->pHead - repeatDepth) < &pCircBuf->CmdBuf[0]) {
    uint8_t index = repeatDepth - (pCircBuf->pHead - &pCircBuf->CmdBuf[0]);
    pCircBuf->pRepeat = &pCircBuf->CmdBuf[CMD_BUFF_SIZE - 1] - index - 1;
  } else {
    pCircBuf->pRepeat = pCircBuf->pHead - repeatDepth;
  }

  for (uint8_t i = 0; i < repeatDepth; i++) {
    CmdStruct* poppedCmd = CircBufPop();
    for (uint8_t j = 0; j < repeatCount; j++) {
      Error err = callCommand(poppedCmd);
#ifdef DEBUG
      printf("Repeating cmd %d \r\n", poppedCmd->commandNummer);
#endif
      if (err != ERR_NONE) {
        return err;
      }
    }
  }
  return ERR_NONE;
}
